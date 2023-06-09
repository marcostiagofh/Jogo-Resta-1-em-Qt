/****************************************************************************
** Meta object code from reading C++ file 'Peca.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../resta1/Peca.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Peca.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Peca_t {
    QByteArrayData data[8];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Peca_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Peca_t qt_meta_stringdata_Peca = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Peca"
QT_MOC_LITERAL(1, 5, 12), // "stateChanged"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "Peca::State"
QT_MOC_LITERAL(4, 31, 5), // "state"
QT_MOC_LITERAL(5, 37, 8), // "setState"
QT_MOC_LITERAL(6, 46, 8), // "getState"
QT_MOC_LITERAL(7, 55, 10) // "updateIcon"

    },
    "Peca\0stateChanged\0\0Peca::State\0state\0"
    "setState\0getState\0updateIcon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Peca[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   37,    2, 0x0a /* Public */,
       6,    0,   40,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    0x80000000 | 3,
    QMetaType::Void,

       0        // eod
};

void Peca::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Peca *_t = static_cast<Peca *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< Peca::State(*)>(_a[1]))); break;
        case 1: _t->setState((*reinterpret_cast< Peca::State(*)>(_a[1]))); break;
        case 2: { Peca::State _r = _t->getState();
            if (_a[0]) *reinterpret_cast< Peca::State*>(_a[0]) = _r; }  break;
        case 3: _t->updateIcon(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Peca::*_t)(Peca::State );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Peca::stateChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Peca::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_Peca.data,
      qt_meta_data_Peca,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Peca::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Peca::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Peca.stringdata0))
        return static_cast<void*>(const_cast< Peca*>(this));
    return QPushButton::qt_metacast(_clname);
}

int Peca::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Peca::stateChanged(Peca::State _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
