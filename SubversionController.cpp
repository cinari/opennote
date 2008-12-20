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
#include <QStatusBar>
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
#include <iostream>
#include <string>
#include <QString>
#include <QVariant>
#include <QTreeWidgetItem>
#include <QProcess>
#include <QInputDialog>
#include <QVariant>
#include <QTreeWidget>
#include <QProcess>
#include <QtXml>
#include <QXmlDefaultHandler>

using namespace std;

class XInfoHandler : public QXmlDefaultHandler
{
public:
	XInfoHandler(SubversionController *svnctl);
	bool endElement(const QString &namespaceURI, const QString &localName,const QString &qName);
	bool characters(const QString &str);

private:
	QString currentText;
	SubversionController *svnctl;
};

XInfoHandler::XInfoHandler(SubversionController *svnctl)
{
	this->svnctl = svnctl;
	currentText="";
}

bool XInfoHandler::endElement(const QString &namespaceURI, const QString &localName,const QString &qName)
{
	if(qName == "date")
	{
		svnctl->shm = currentText;
		//qprint2(currentText);
	}
	currentText.clear();
	return true;
};

bool XInfoHandler::characters(const QString &str)
 {
     currentText += str;
     return true;
 }

SubversionController::SubversionController(QString workingDir) {
	workingDirectory = workingDir;

	svnProcess = new QProcess();
	svnProcess->setWorkingDirectory(workingDirectory);

	cout << svnProcess->workingDirectory().toAscii().data()<<endl;
	svnProcess->start("svn",QStringList() << "co" << repository_url << ".");
	//svnProcess->waitForFinished(30000);
}

SubversionController::~SubversionController() {
	//del process;
}

void SubversionController::doAdd(QString fileName)
{
	svnProcess->setWorkingDirectory(workingDirectory);
	cout << "workingDirectory" << workingDirectory.toAscii().data()<<endl;
	cout << "svn add "<<fileName.toAscii().data()<<endl;
	svnProcess->start("svn", QStringList() << "add" << fileName);
	//svnProcess->waitForFinished(30000);

	doCommit(fileName);
}

void SubversionController::doCommit(QString fileName)
{
	svnProcess->setWorkingDirectory(workingDirectory);
	svnProcess->start("svn", QStringList() << "ci" << fileName << "-m" << "\"\"");
	svnProcess->waitForFinished(30000);

	// for test
	QByteArray result = svnProcess->readAll();

	for(int i=0;i<result.size();i++)
		cout << result.at(i);
	cout << "-------------"<<endl;

}

QByteArray SubversionController::doUpdate()
{
	cout << "update Notebook (svn up)" << endl;
	// 1. launch "SVN update"
	QProcess process;
	process.setWorkingDirectory(workingDirectory);
	process.start("svn",QStringList() << "update");
	//connect(process,finished(exitCode,exitStatus),???,updateFinished(exitCode,exitStatus,process.readAll()));
	//process.waitForFinished(30000);
	return process.readAll();
}

void SubversionController::doMove(QString srcFileName, QString dstFileName)
{
	cout << "rename Notebook (svn move!)" << endl;

	QProcess process;
	process.setWorkingDirectory(workingDirectory);
	process.start("svn",QStringList() << "move" << srcFileName << dstFileName);
	doCommit(dstFileName);
	process.waitForFinished(5000);
}

QString SubversionController::getDateInfo(QString fileName)
{
	QProcess process;

	process.setWorkingDirectory(workingDirectory);
	process.start("svn",QStringList() << "info" << fileName << "--xml");
	process.waitForFinished(30000);
	QByteArray result = process.read(3000);
//	QString sResult(result);

	XInfoHandler hnd(this);
	QXmlSimpleReader reader;
	reader.setContentHandler(&hnd);

	QXmlInputSource xmlInputSource;
	xmlInputSource.setData(result);

	reader.parse(xmlInputSource);

	QString test="A          abc.cpp\nA         ddd.cpp";
	QStringList list1 = test.split(QRegExp("[ \n]"),QString::SkipEmptyParts);
	for(int i=0;i<list1.size();i++)
	{
		SwissKnife::printString("hahah = "+list1.at(i)+"\n");
	}

	return shm;
}

