/****************************************************************************
** Meta object code from reading C++ file 'superViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/superViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'superViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_superViewer_t {
    QByteArrayData data[11];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_superViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_superViewer_t qt_meta_stringdata_superViewer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "superViewer"
QT_MOC_LITERAL(1, 12, 12), // "errorChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "value"
QT_MOC_LITERAL(4, 32, 18), // "superButtonPressed"
QT_MOC_LITERAL(5, 51, 17), // "RGBsliderReleased"
QT_MOC_LITERAL(6, 69, 18), // "delta_ValueChanged"
QT_MOC_LITERAL(7, 88, 20), // "npoints_ValueChanged"
QT_MOC_LITERAL(8, 109, 19), // "pcsize_ValueChanged"
QT_MOC_LITERAL(9, 129, 17), // "saveButtonPressed"
QT_MOC_LITERAL(10, 147, 18) // "resetButtonPressed"

    },
    "superViewer\0errorChanged\0\0value\0"
    "superButtonPressed\0RGBsliderReleased\0"
    "delta_ValueChanged\0npoints_ValueChanged\0"
    "pcsize_ValueChanged\0saveButtonPressed\0"
    "resetButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_superViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    1,   59,    2, 0x0a /* Public */,
       7,    1,   62,    2, 0x0a /* Public */,
       8,    1,   65,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void superViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        superViewer *_t = static_cast<superViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->errorChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->superButtonPressed(); break;
        case 2: _t->RGBsliderReleased(); break;
        case 3: _t->delta_ValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->npoints_ValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->pcsize_ValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->saveButtonPressed(); break;
        case 7: _t->resetButtonPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (superViewer::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&superViewer::errorChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject superViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_superViewer.data,
      qt_meta_data_superViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *superViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *superViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_superViewer.stringdata0))
        return static_cast<void*>(const_cast< superViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int superViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void superViewer::errorChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
