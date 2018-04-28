/****************************************************************************
** Meta object code from reading C++ file 'myudp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../myudp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myudp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyUDP_t {
    QByteArrayData data[8];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyUDP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyUDP_t qt_meta_stringdata_MyUDP = {
    {
QT_MOC_LITERAL(0, 0, 5), // "MyUDP"
QT_MOC_LITERAL(1, 6, 9), // "readReady"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 21), // "readReady_SyncService"
QT_MOC_LITERAL(4, 39, 11), // "sendUdpData"
QT_MOC_LITERAL(5, 51, 18), // "QList<cv::Point3f>"
QT_MOC_LITERAL(6, 70, 14), // "robotLocations"
QT_MOC_LITERAL(7, 85, 9) // "timeStamp"

    },
    "MyUDP\0readReady\0\0readReady_SyncService\0"
    "sendUdpData\0QList<cv::Point3f>\0"
    "robotLocations\0timeStamp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyUDP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    2,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QTime,    6,    7,

       0        // eod
};

void MyUDP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyUDP *_t = static_cast<MyUDP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readReady(); break;
        case 1: _t->readReady_SyncService(); break;
        case 2: _t->sendUdpData((*reinterpret_cast< QList<cv::Point3f>(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MyUDP::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyUDP.data,
      qt_meta_data_MyUDP,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyUDP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyUDP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyUDP.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyUDP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
