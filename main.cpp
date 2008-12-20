#include "TextEditorWindow.h"
#include <QApplication>
#include <QtGui>
#include <QAbstractItemModel>
#include <QFont>
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
#include <QtGlobal>
int main( int argc, char ** argv )
{
    Q_INIT_RESOURCE(OpenNote);

    QApplication a( argc, argv );
    TextEditorWindow mw;
    qWarning("qWarning() executed");

    //mw.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    mw.setWindowTitle(ApplicationName);
    mw.statusBar()->showMessage("Editing");
    mw.resize( 800, 600 );
    mw.show();
    return a.exec();
}

