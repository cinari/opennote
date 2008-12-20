#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "NotebookExplorer.h"
#include "DavinciTextEdit.h"
#include <QMainWindow>
#include <QMap>
#include <QListWidget>
#include <QTreeWidget>
#include <QPointer>
#include <QTreeView>
#include <QDirModel>

QT_FORWARD_DECLARE_CLASS(QAction)
QT_FORWARD_DECLARE_CLASS(QComboBox)
QT_FORWARD_DECLARE_CLASS(QFontComboBox)
QT_FORWARD_DECLARE_CLASS(QTextEdit)
QT_FORWARD_DECLARE_CLASS(QTextCharFormat)
QT_FORWARD_DECLARE_CLASS(QMenu)
QT_FORWARD_DECLARE_CLASS(DavinciTextEdit)
QT_FORWARD_DECLARE_CLASS(NotebookList)

const QString ApplicationName="OpenNote 2008 (beta)";

class TextEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    TextEditorWindow(QWidget *parent = 0);
    bool load(const QString &f);
    NotebookList *notebookList;
    DavinciTextEdit *textEdit;

public slots:
	bool fileSave();

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    void setupFileActions();
    void setupEditActions();
    void setupTextActions();
    void setupNotebook();
    bool maybeSave();
    void setCurrentFileName(const QString &fileName);

private slots:
    void fileNew();
    void fileOpen();
    bool fileSaveAs();
    void filePrint();
    void filePrintPreview();
    void filePrintPdf();

    void textBold();
    void textUnderline();
    void textItalic();
    void textFamily(const QString &f);
    void textSize(const QString &p);
    void textStyle(QAction *a);
    void textColor();
    void textAlign(QAction *a);
    void experiment();

    void currentCharFormatChanged(const QTextCharFormat &format);
    void cursorPositionChanged();

    void clipboardDataChanged();
    void printPreview(QPrinter *);

private:
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    //virtual bool canInsertFromMimeData( const QMimeData *source ) const;
    void fontChanged(const QFont &f);
    void colorChanged(const QColor &c);
    void alignmentChanged(Qt::Alignment a);

    QAction
		*actionNew,
        *actionSave,
		*actionExportPdf,
		*actionPublish,
        *actionTextBold,
        *actionTextUnderline,
        *actionTextItalic,
        *actionTextColor,
        *actionAlignLeft,
        *actionAlignCenter,
        *actionAlignRight,
        *actionAlignJustify,
        *actionUndo,
        *actionRedo,
        *actionCut,
        *actionCopy,
        *actionPaste,
        *actionExperiment,
        *actionEdit,
        *actionListBullets,
        *actionListNumering,
        *actionHyperlink,
        *actionEtc;


    QComboBox *comboStyle;
    QFontComboBox *comboFont;
    QComboBox *comboSize;

    QToolBar *tb;
    QString fileName;
    QWidget *mainPanel;
    QWidget *rightPanel;
};

#endif
