#ifndef DAVINCITEXTEDIT_H_
#define DAVINCITEXTEDIT_H_
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
class QTextEdit;

class DavinciTextEdit : public QTextEdit {
	Q_OBJECT
public:
	DavinciTextEdit();
	virtual ~DavinciTextEdit();
	virtual void mouseReleaseEvent (QMouseEvent * e);
	virtual bool canInsertFromMimeData(const QMimeData *source);
	void insertHyperLink(QString name, QString& url);
	void insertTextBox();
};

#endif /* DAVINCITEXTEDIT_H_ */
