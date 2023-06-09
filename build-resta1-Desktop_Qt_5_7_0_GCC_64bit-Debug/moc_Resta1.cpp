/****************************************************************************
** Meta object code from reading C++ file 'Resta1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../resta1/Resta1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Resta1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Resta1_t {
    QByteArrayData data[10];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Resta1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Resta1_t qt_meta_stringdata_Resta1 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Resta1"
QT_MOC_LITERAL(1, 7, 8), // "gameOver"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "play"
QT_MOC_LITERAL(4, 22, 15), // "iniciarNovoJogo"
QT_MOC_LITERAL(5, 38, 12), // "mostrarSobre"
QT_MOC_LITERAL(6, 51, 14), // "mostrarFimJogo"
QT_MOC_LITERAL(7, 66, 10), // "trocarModo"
QT_MOC_LITERAL(8, 77, 8), // "QAction*"
QT_MOC_LITERAL(9, 86, 4) // "modo"

    },
    "Resta1\0gameOver\0\0play\0iniciarNovoJogo\0"
    "mostrarSobre\0mostrarFimJogo\0trocarModo\0"
    "QAction*\0modo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Resta1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void Resta1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Resta1 *_t = static_cast<Resta1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameOver(); break;
        case 1: _t->play(); break;
        case 2: _t->iniciarNovoJogo(); break;
        case 3: _t->mostrarSobre(); break;
        case 4: _t->mostrarFimJogo(); break;
        case 5: _t->trocarModo((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Resta1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Resta1::gameOver)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Resta1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Resta1.data,
      qt_meta_data_Resta1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Resta1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Resta1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Resta1.stringdata0))
        return static_cast<void*>(const_cast< Resta1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Resta1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Resta1::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
