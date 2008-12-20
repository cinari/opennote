/****************************************************************************
** Meta object code from reading C++ file 'textedit.h'
**
** Created: Sun Nov 2 20:35:10 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../textedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TextEditorWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      23,   17,   18,   17, 0x0a,
      34,   17,   17,   17, 0x08,
      44,   17,   17,   17, 0x08,
      55,   17,   18,   17, 0x08,
      68,   17,   17,   17, 0x08,
      80,   17,   17,   17, 0x08,
      99,   17,   17,   17, 0x08,
     114,   17,   17,   17, 0x08,
     125,   17,   17,   17, 0x08,
     141,   17,   17,   17, 0x08,
     156,  154,   17,   17, 0x08,
     178,  176,   17,   17, 0x08,
     207,  196,   17,   17, 0x08,
     222,   17,   17,   17, 0x08,
     236,  234,   17,   17, 0x08,
     256,   17,   17,   17, 0x08,
     276,  269,   17,   17, 0x08,
     318,   17,   17,   17, 0x08,
     342,   17,   17,   17, 0x08,
     365,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TextEditorWindow[] = {
    "TextEditorWindow\0\0bool\0fileSave()\0"
    "fileNew()\0fileOpen()\0fileSaveAs()\0"
    "filePrint()\0filePrintPreview()\0"
    "filePrintPdf()\0textBold()\0textUnderline()\0"
    "textItalic()\0f\0textFamily(QString)\0p\0"
    "textSize(QString)\0styleIndex\0"
    "textStyle(int)\0textColor()\0a\0"
    "textAlign(QAction*)\0experiment()\0"
    "format\0currentCharFormatChanged(QTextCharFormat)\0"
    "cursorPositionChanged()\0clipboardDataChanged()\0"
    "printPreview(QPrinter*)\0"
};

const QMetaObject TextEditorWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TextEditorWindow,
      qt_meta_data_TextEditorWindow, 0 }
};

const QMetaObject *TextEditorWindow::metaObject() const
{
    return &staticMetaObject;
}

void *TextEditorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TextEditorWindow))
        return static_cast<void*>(const_cast< TextEditorWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TextEditorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = fileSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: fileNew(); break;
        case 2: fileOpen(); break;
        case 3: { bool _r = fileSaveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: filePrint(); break;
        case 5: filePrintPreview(); break;
        case 6: filePrintPdf(); break;
        case 7: textBold(); break;
        case 8: textUnderline(); break;
        case 9: textItalic(); break;
        case 10: textFamily((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: textSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: textStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: textColor(); break;
        case 14: textAlign((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 15: experiment(); break;
        case 16: currentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 17: cursorPositionChanged(); break;
        case 18: clipboardDataChanged(); break;
        case 19: printPreview((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
