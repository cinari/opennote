#include "DavinciTextEdit.h"
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

using namespace std;
DavinciTextEdit::DavinciTextEdit() : QTextEdit() {

}

DavinciTextEdit::~DavinciTextEdit() {

}

void DavinciTextEdit::mouseReleaseEvent (QMouseEvent * e)
{
	QPoint pt = e->pos();
	QTextEdit::mouseReleaseEvent(e);

	QString anchor = this->anchorAt(pt);
	cout << "anchor:" << anchor.toAscii().data() <<endl;
}

bool DavinciTextEdit::canInsertFromMimeData( const QMimeData *source )
{
	QString str = source->imageData().toString();
	cout << "image dragged: "<<str.toAscii().data() << endl;
    if (source->hasImage())
        return true;
    else
        return QTextEdit::canInsertFromMimeData(source);
}

void DavinciTextEdit::insertHyperLink(QString name, QString& url)
{
	insertHtml("<a href=\"" + url + "\">" + name + "</a><p> </p>");
}

void DavinciTextEdit::insertTextBox()
{
	QString t = "<table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" width=\"85%\" cellspacing=\"0\" cellpadding=\"1\" bgcolor=\"#999999\">"  \
			    "<tr><td>" \
			    "<table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" align=\"center\" width=\"100%\" cellspacing=\"0\" cellpadding=\"2\" bgcolor=\"#FDD017\">" \
			    "<tr><td>" \
			    "<table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" width=\"100%\" cellspacing=\"2\" cellpadding=\"2\">" \
			    "<tr>" \
			    "<td colspan=\"7\" style=\" vertical-align:top;\">" \
			    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial'; font-size:12pt; color:#000000;\">&nbsp;</p>" \
			    "</td></tr></table></td></tr></table></td></tr></table>";

	insertHtml(t);
}
