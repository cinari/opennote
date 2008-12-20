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
