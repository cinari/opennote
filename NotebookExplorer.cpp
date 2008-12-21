#include "NotebookExplorer.h"
#include "SubversionController.h"
#include "SwissKnife.h"

#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QFontComboBox>
#include <QItemDelegate>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QMenu>
#include <QMenuBar>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextCodec>
#include <QTextEdit>
#include <QListWidget>
#include <QToolBar>
#include <QTextCursor>
#include <QTextList>
#include <QtDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QPrintPreviewDialog>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QList>
#include <QDirModel>
#include <QTreeView>
#include <QProcess>
#include <iostream>
#include <string>
#include <QString>
#include <QVariant>
#include <QInputDialog>
#include <QTreeWidget>
#include <QHeaderView>
#include <QTreeWidgetItem>
#include <QFileInfoList>
#include <QTimer>
#include <QtGlobal>
#include <QErrorMessage>
#include <QStatusBar>
using namespace std;

const QString rsrcPath = ":/images/win";

NoteElement::NoteElement(QString _noteName)
{
	name = _noteName;
	fileName = _noteName+extensionName;
}

void NotebookList::notebookSelectionChanged()
{
	SwissKnife::printString("changed!!");
	//notebookSelected();
}

void NotebookList::keyPressEvent(QKeyEvent * event)
{
	SwissKnife::printString("pressed");
}

void NotebookList::notebookSelected(QModelIndex idx)
{
	QTreeWidgetItem *item = itemFromIndex(idx);
	QString fullFilePath="";

	if(lastSelectedItem)
		lastSelectedItem->setBackground(0,QBrush(QColor(Qt::white)));
	item->setBackground(0,QBrush(QColor(Qt::yellow)));
	lastSelectedItem = item;

	if(item->whatsThis(0) == "folder"){
		if(item->isExpanded())
			item->setExpanded(false);
		else
			item->setExpanded(true);
		return;
	}

	if (textEditorWindow->textEdit->document()->isModified())
		textEditorWindow->fileSave();


	while (idx != QModelIndex())
	{
		QString itemName = this->model()->data(idx).toString();
		if (fullFilePath == "") fullFilePath = itemName;
		else fullFilePath = itemName + "/" + fullFilePath;
		idx = idx.parent();
	}

	fullFilePath = baseDirectory + fullFilePath + extensionName;
	cout << "full path : "<<fullFilePath.toAscii().data()<<endl;

	QString lastModifiedDate = svnController->getDateInfo(fullFilePath);
	textEditorWindow->statusBar()->showMessage(lastModifiedDate,0);
	textEditorWindow->load(fullFilePath);
}

void NotebookList::addNewFolder()
{
	bool ok;
    QString newFolderName = QInputDialog::getText(this, tr("Add new folder"),
                                         tr("folder title:"), QLineEdit::Normal,
                                         "", &ok);
    if(newFolderName.length() == 0) return;
    insertFolder(currentItem(),new NoteElement(newFolderName));
}

// add new note
void NotebookList::addNewNote()
{
	bool ok;
    QString newNotebookName = QInputDialog::getText(this, tr("Add new note"),
                                         tr("Note title:"), QLineEdit::Normal,
                                         "", &ok);


    if(newNotebookName.length() == 0) return;
    SwissKnife::printString("add New Note: "+newNotebookName);
    insertPage(currentItem(),new NoteElement(newNotebookName));
}

void NotebookList::renameNote()
{
	bool ok;
	QString relativeDirectory = "";
	QString extName;
	QString newName = QInputDialog::getText(this, tr("rename"),
	                                         tr("Rename to"), QLineEdit::Normal,
	                                         "", &ok);

	if(newName.length() == 0) return;
	QTreeWidgetItem* selectedItem = currentItem();

	if(selectedItem->parent())
		relativeDirectory = selectedItem->parent()->text(0) + "/";

	if(selectedItem->whatsThis(0) == "folder")
		extName="";
	else extName=".w";

	QString srcFileName = relativeDirectory+selectedItem->text(0) + extName;
	QString dstFileName = relativeDirectory+newName + extName;
	SwissKnife::printString("from: "+ srcFileName);
	SwissKnife::printString("to: " + dstFileName);

	svnController->doMove(srcFileName,dstFileName);
	selectedItem->setText(0,newName);
}

void NotebookList::setupSubMenu()
{
    QStringList nameFilter;

    QAction *addNewNoteAction = new QAction(tr("New Note"),this);
    this->addAction(addNewNoteAction);

    QAction *addNewFolderAction = new QAction(tr("New Folder"),this);
    this->addAction(addNewFolderAction);

    QAction *addRenameAction = new QAction(tr("Rename"),this);
    this->addAction(addRenameAction);

    QAction *addRefreshAction = new QAction(tr("Refresh"),this);
    this->addAction(addRefreshAction);

    setContextMenuPolicy(Qt::ActionsContextMenu);

    setItemDelegate(new QItemDelegate);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    //notebookList->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);

    connect(addNewNoteAction,SIGNAL(triggered()), SLOT(addNewNote()));
    connect(addNewFolderAction,SIGNAL(triggered()), SLOT(addNewFolder()));
    connect(addRenameAction,SIGNAL(triggered()), SLOT(renameNote()));
    connect(addRefreshAction,SIGNAL(triggered()), SLOT(refreshNotebook()));
    //connect(notebookList    ,SIGNAL(clicked(QModelIndex)),this,SLOT(notebookSelected(QModelIndex)));

    connect(this    ,SIGNAL(currentItemChanged(QModelIndex)),this,SLOT(notebookSelected(QModelIndex)));
    connect(this    ,SIGNAL(clicked(QModelIndex)),this,SLOT(notebookSelected(QModelIndex)));
}

NotebookList::NotebookList(TextEditorWindow *textEditWindow, QString notebookBaseDirectory) {

	baseDirectory = notebookBaseDirectory;
	this->textEditorWindow = textEditWindow;
	this->setAutoFillBackground(false);
	svnController = new SubversionController(baseDirectory);

	QString headerTitle="Notes";
	header()->setResizeMode(QHeaderView::Stretch);
	this->setHeaderHidden(true);
	setFont(QFont("Verdana", 11));

	lastSelectedItem = 0;
	setupSubMenu();

    folderIcon = QIcon(rsrcPath + "/Favourites.png");
    bookmarkIcon = QIcon(rsrcPath + "/New Doc.png");

	item=0;

	// 타이머로 아래 update 함수를 매번 실행하게끔 설정
	/*
	QTimer* timer = new QTimer(this);
	QObject::connect(timer,SIGNAL(timeout()),this,SLOT(refreshNotebook()));
	timer->start(30000);
	*/
	updateNotebook(baseDirectory, 0);
}

void NotebookList::insertFolder(QTreeWidgetItem* selectedItem, NoteElement* folder)
{
	QString workingDir = baseDirectory;
	insertNode(0, folder->name, "folder");

	QDir dir(baseDirectory);
	/*
	if (dir.exists())
	{
		QErrorMessage* errMsgDialog = new QErrorMessage(this);
		errMsgDialog->showMessage(tr("Already exists!"));
		return;
	}
	*/
	if (dir.mkdir(folder->name))
	{
		cout << "directory creation success"<<endl;
		svnController->doAdd(baseDirectory+"/"+folder->name);
	}
	else
	{
		cout << "directory creatation failed"<<endl;
	}
}

QTreeWidgetItem *NotebookList::insertNode(QTreeWidgetItem *parent, QString name, QString type)
{
	QTreeWidgetItem *newItem;

	if(parent)
		newItem = new QTreeWidgetItem(parent);
	else
		newItem = new QTreeWidgetItem(this);

	newItem->setText(0, name);
	newItem->setWhatsThis(0,type);
	newItem->setForeground(0, QBrush(QColor(Qt::black)));

	if(type == "folder")
	{
		newItem->setIcon(0,folderIcon);
		newItem->setExpanded(true);
	}
	else if(type == "notebook")
		newItem->setIcon(0,bookmarkIcon);

	return newItem;
}

void NotebookList::insertPage(QTreeWidgetItem* selectedItem, NoteElement* note)
{
	QString workingDir = baseDirectory;
	QTreeWidgetItem* parentItem = 0;

	if(selectedItem)
	{
		if(selectedItem->whatsThis(0) == "folder")
		{
			parentItem = selectedItem;
			workingDir = workingDir + selectedItem->text(0) + "/";
		}
		else if(selectedItem->whatsThis(0) == "notebook" && selectedItem->parent())
		{
			workingDir += selectedItem->parent()->text(0) + "/";
			parentItem = selectedItem->parent();
		}
	}

	insertNode(parentItem, note->name, "notebook");

	// 템플릿에서 복사해오기
	QString templatePath = QDir::currentPath() + "/template.w";
	QString newNotePath = workingDir + note->fileName;

	SwissKnife::printString("new note path: " + newNotePath);

	QByteArray templateData = SwissKnife::fileRead(templatePath);
	QString templateText = QString::fromLocal8Bit(templateData); // locally encoded string to Unicode

	templateText.replace("[::title::]",note->name);
	SwissKnife::fileSave(newNotePath, templateText);

	QFile fNewFile(newNotePath);
	QFile fTemplate(QDir::currentPath() + "/template.w");

	// TODO: subversion 에 바로 파일 등록하지 말고
	// OLD: svnController->doAdd(workingDir + note->fileName) 을 바로하지 말고 트랜잭션 로그에 남긴다!

	cout << "workingDir ==" << workingDir.toAscii().data()<<endl;
}

void NotebookList::refreshNotebook()
{
	QByteArray result = svnController->doUpdate();
	QStringList fileList;

	char fileName[64]; int fileP=0;
	enum STATES {NOTHING, START, SKIP, PROCESSING};
	STATES state = NOTHING;

	for(int i=0;i<result.length();i++)
	{
		switch(state)
		{
		case NOTHING:
			if(i > 1 && result.at(i-1) == '\n' && result.at(i) == 'A') state=START;
			if(i==0 && result.at(i) == 'A') state=START;
			break;

		case START:
			if(result.at(i) == ' ') state=SKIP;
			else state=NOTHING;
			break;

		case SKIP:
			if(result.at(i) == ' ') state=SKIP;
			else
			{
				state=PROCESSING;
				fileP=0;
				fileName[fileP++]=result.at(i);
			}
			break;

		case PROCESSING:
			if(result.at(i) != '\n') fileName[fileP++]=result.at(i);
			else
			{
				fileName[fileP]=0;
				QString t(fileName);
				fileList << t;
				state=NOTHING;
			}
			break;
		}
	}

	QTreeWidgetItem *t;
	for(int i=0;i<fileList.size();i++)
	{
		t = createChildItem(fileList.at(i));
		t->setText(0, fileList.at(i));
		t->setText(0, "dont know");
		t->setForeground(0, QBrush(QColor(Qt::blue)));
		t->setIcon(0,bookmarkIcon); // newIcon 으로 대체하기
	}
}

void NotebookList::updateNotebook(QString baseDir, int depth)
{
	QDir *dir = new QDir(baseDir);

	svnController->doUpdate();
	cout << "updateNobteook: "<<baseDir.toAscii().data() << endl;

	if(!dir->exists()) return;
	QFileInfoList dirInfoList = dir->entryInfoList();
	for(int i=0; i < dirInfoList.count();i++)
	{
		QFileInfo fInfo = dirInfoList.at(i);
		QString fileName = fInfo.fileName();
		QTreeWidgetItem *t;

		if(fInfo.isFile() && fileName.endsWith(".w")==false) continue;
		if(fileName.startsWith(".")) continue;
		QString baseName = fInfo.baseName();

		t = createChildItem(baseName);
		t->setText(0, baseName);
		t->setForeground(0, QBrush(QColor(Qt::blue)));

		if(fInfo.isDir())
		{
			t->setIcon(0,folderIcon);
			t->setWhatsThis(0,"folder");
			setItemExpanded(item,true);
			if(depth == 0)
			{
				item = t;
				updateNotebook(baseDir+"/"+fileName, 1);
				item = item->parent();
			}
		}
		else if(fInfo.isFile())
		{
			t->setWhatsThis(0,"notebook");
			t->setIcon(0,bookmarkIcon);
		}
	}
}

QTreeWidgetItem* NotebookList::createChildItem(const QString title)
{
	QTreeWidgetItem *childItem;
    if (item) {
        childItem = new QTreeWidgetItem(item);
    } else {
        childItem = new QTreeWidgetItem(this);
    }
    childItem->setData(0, Qt::UserRole, title);
    return childItem;
}

NotebookList::~NotebookList() {

}
