/****************************************************************************
** Meta object code from reading C++ file 'ICPViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/ICPViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ICPViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ICPViewer_t {
    QByteArrayData data[10];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ICPViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ICPViewer_t qt_meta_stringdata_ICPViewer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ICPViewer"
QT_MOC_LITERAL(1, 10, 12), // "errorChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "value"
QT_MOC_LITERAL(4, 30, 19), // "randomButtonPressed"
QT_MOC_LITERAL(5, 50, 21), // "distance_ValueChanged"
QT_MOC_LITERAL(6, 72, 20), // "npoints_ValueChanged"
QT_MOC_LITERAL(7, 93, 19), // "pcsize_ValueChanged"
QT_MOC_LITERAL(8, 113, 17), // "saveButtonPressed"
QT_MOC_LITERAL(9, 131, 17) // "RGBsliderReleased"

    },
    "ICPViewer\0errorChanged\0\0value\0"
    "randomButtonPressed\0distance_ValueChanged\0"
    "npoints_ValueChanged\0pcsize_ValueChanged\0"
    "saveButtonPressed\0RGBsliderReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ICPViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       6,    1,   56,    2, 0x0a /* Public */,
       7,    1,   59,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ICPViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ICPViewer *_t = static_cast<ICPViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->errorChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->randomButtonPressed(); break;
        case 2: _t->distance_ValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->npoints_ValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->pcsize_ValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->saveButtonPressed(); break;
        case 6: _t->RGBsliderReleased(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ICPViewer::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ICPViewer::errorChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ICPViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ICPViewer.data,
      qt_meta_data_ICPViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ICPViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ICPViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ICPViewer.stringdata0))
        return static_cast<void*>(const_cast< ICPViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int ICPViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ICPViewer::errorChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
