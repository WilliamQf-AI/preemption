/****************************************************************************
** Meta object code from reading C++ file 'GameManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GameManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameManager_t {
    QByteArrayData data[14];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameManager_t qt_meta_stringdata_GameManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GameManager"
QT_MOC_LITERAL(1, 12, 30), // "qmlSlot_gameCanvas_onCompleted"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 6), // "sender"
QT_MOC_LITERAL(4, 51, 30), // "qmlSlot_gameCanvas_onDestroyed"
QT_MOC_LITERAL(5, 82, 24), // "qmlSlot_inputBox_discard"
QT_MOC_LITERAL(6, 107, 23), // "qmlSlot_inputBox_accept"
QT_MOC_LITERAL(7, 131, 20), // "qmlSlot_cell_onClick"
QT_MOC_LITERAL(8, 152, 1), // "x"
QT_MOC_LITERAL(9, 154, 1), // "y"
QT_MOC_LITERAL(10, 156, 21), // "qmlSlot_arrow_onClick"
QT_MOC_LITERAL(11, 178, 3), // "dir"
QT_MOC_LITERAL(12, 182, 22), // "qmlSlot_btnRun_onClick"
QT_MOC_LITERAL(13, 205, 29) // "qmlSlot_cell_onPositionChange"

    },
    "GameManager\0qmlSlot_gameCanvas_onCompleted\0"
    "\0sender\0qmlSlot_gameCanvas_onDestroyed\0"
    "qmlSlot_inputBox_discard\0"
    "qmlSlot_inputBox_accept\0qmlSlot_cell_onClick\0"
    "x\0y\0qmlSlot_arrow_onClick\0dir\0"
    "qmlSlot_btnRun_onClick\0"
    "qmlSlot_cell_onPositionChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    2,   60,    2, 0x0a /* Public */,
      10,    3,   65,    2, 0x0a /* Public */,
      12,    0,   72,    2, 0x0a /* Public */,
      13,    1,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    3,

       0        // eod
};

void GameManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameManager *_t = static_cast<GameManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->qmlSlot_gameCanvas_onCompleted((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->qmlSlot_gameCanvas_onDestroyed(); break;
        case 2: _t->qmlSlot_inputBox_discard(); break;
        case 3: _t->qmlSlot_inputBox_accept(); break;
        case 4: _t->qmlSlot_cell_onClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->qmlSlot_arrow_onClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->qmlSlot_btnRun_onClick(); break;
        case 7: _t->qmlSlot_cell_onPositionChange((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameManager.data,
      qt_meta_data_GameManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GameManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
