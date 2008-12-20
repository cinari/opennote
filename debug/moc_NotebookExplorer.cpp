/****************************************************************************
** Meta object code from reading C++ file 'NotebookExplorer.h'
**
** Created: Fri Dec 19 22:59:14 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NotebookExplorer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NotebookExplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NotebookList[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      32,   13,   13,   13, 0x0a,
      45,   13,   13,   13, 0x0a,
      60,   13,   13,   13, 0x0a,
      77,   73,   13,   13, 0x0a,
     107,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NotebookList[] = {
    "NotebookList\0\0refreshNotebook()\0"
    "addNewNote()\0addNewFolder()\0renameNote()\0"
    "idx\0notebookSelected(QModelIndex)\0"
    "notebookSelectionChanged()\0"
};

const QMetaObject NotebookList::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_NotebookList,
      qt_meta_data_NotebookList, 0 }
};

const QMetaObject *NotebookList::metaObject() const
{
    return &staticMetaObject;
}

void *NotebookList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NotebookList))
        return static_cast<void*>(const_cast< NotebookList*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int NotebookList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: refreshNotebook(); break;
        case 1: addNewNote(); break;
        case 2: addNewFolder(); break;
        case 3: renameNote(); break;
        case 4: notebookSelected((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: notebookSelectionChanged(); break;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
