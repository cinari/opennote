#ifndef NOTEBOOKEXPLORER_H_
#define NOTEBOOKEXPLORER_H_

#include "TextEditorWindow.h"
#include "SubversionController.h"
#include <QTextCodec>
#include <QTextEdit>
#include <QApplication>
#include <QTreeWidget>
#include <QString>

class QTreeWidget;

QT_FORWARD_DECLARE_CLASS(TextEditorWindow)

const QString extensionName=".w";

class NoteElement
{
public:
	NoteElement(QString _noteName);
	QString name;
	QString fileName;
};

class NotebookList : public QTreeWidget {

	Q_OBJECT
public:
	NotebookList(TextEditorWindow *textEditWindow, QString notebookBaseDirectory);
	virtual ~NotebookList();
	QTreeWidgetItem* createChildItem(const QString title);
	void updateNotebook(QString baseDir, int depth);
	void insertPage(QTreeWidgetItem* currentItem, NoteElement* note);
	void insertFolder(QTreeWidgetItem* currentItem, NoteElement* folder);
	void setupSubMenu();
	typedef enum {NOTE_PAGE, NOTE_FOLDER} NoteType;
    TextEditorWindow *textEditorWindow;
    SubversionController* svnController;

private:
	bool isNewNote(QString filename);
	void keyPressEvent(QKeyEvent * event);
	QTreeWidgetItem *insertNode(QTreeWidgetItem *parent, QString name, QString type);

    QIcon folderIcon;
    QIcon bookmarkIcon;

	QTreeWidgetItem *item;
	QTreeWidgetItem *t; // test

	QString baseDirectory;
	QTreeWidgetItem* lastSelectedItem;

public slots:

	void refreshNotebook();
	void addNewNote();
	void addNewFolder();
	void renameNote();
	void notebookSelected(QModelIndex idx);
	void notebookSelectionChanged();
};

#endif /* NOTEBOOKEXPLORER_H_ */


