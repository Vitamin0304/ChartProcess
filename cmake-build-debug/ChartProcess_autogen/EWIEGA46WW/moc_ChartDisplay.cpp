/****************************************************************************
** Meta object code from reading C++ file 'ChartDisplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ChartDisplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChartDisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChartDisplay_t {
    QByteArrayData data[31];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChartDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChartDisplay_t qt_meta_stringdata_ChartDisplay = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ChartDisplay"
QT_MOC_LITERAL(1, 13, 12), // "changeXRange"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "QCPRange"
QT_MOC_LITERAL(4, 36, 8), // "newRange"
QT_MOC_LITERAL(5, 45, 8), // "oldRange"
QT_MOC_LITERAL(6, 54, 13), // "addDataSignal"
QT_MOC_LITERAL(7, 68, 8), // "uint32_t"
QT_MOC_LITERAL(8, 77, 10), // "graphIndex"
QT_MOC_LITERAL(9, 88, 1), // "x"
QT_MOC_LITERAL(10, 90, 1), // "y"
QT_MOC_LITERAL(11, 92, 19), // "addDataVectorSignal"
QT_MOC_LITERAL(12, 112, 15), // "QVector<double>"
QT_MOC_LITERAL(13, 128, 4), // "keys"
QT_MOC_LITERAL(14, 133, 6), // "values"
QT_MOC_LITERAL(15, 140, 13), // "alreadySorted"
QT_MOC_LITERAL(16, 154, 12), // "replotSignal"
QT_MOC_LITERAL(17, 167, 20), // "maximizeXRangeSignal"
QT_MOC_LITERAL(18, 188, 11), // "clearSignal"
QT_MOC_LITERAL(19, 200, 18), // "on_x_range_changed"
QT_MOC_LITERAL(20, 219, 15), // "on_slider_moved"
QT_MOC_LITERAL(21, 235, 8), // "position"
QT_MOC_LITERAL(22, 244, 13), // "on_mouse_move"
QT_MOC_LITERAL(23, 258, 12), // "QMouseEvent*"
QT_MOC_LITERAL(24, 271, 1), // "e"
QT_MOC_LITERAL(25, 273, 16), // "on_clear_clicked"
QT_MOC_LITERAL(26, 290, 6), // "replot"
QT_MOC_LITERAL(27, 297, 7), // "addData"
QT_MOC_LITERAL(28, 305, 13), // "addDataVector"
QT_MOC_LITERAL(29, 319, 13), // "followCurrent"
QT_MOC_LITERAL(30, 333, 10) // "viewGlobal"

    },
    "ChartDisplay\0changeXRange\0\0QCPRange\0"
    "newRange\0oldRange\0addDataSignal\0"
    "uint32_t\0graphIndex\0x\0y\0addDataVectorSignal\0"
    "QVector<double>\0keys\0values\0alreadySorted\0"
    "replotSignal\0maximizeXRangeSignal\0"
    "clearSignal\0on_x_range_changed\0"
    "on_slider_moved\0position\0on_mouse_move\0"
    "QMouseEvent*\0e\0on_clear_clicked\0replot\0"
    "addData\0addDataVector\0followCurrent\0"
    "viewGlobal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChartDisplay[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       6,    3,   94,    2, 0x06 /* Public */,
      11,    4,  101,    2, 0x06 /* Public */,
      16,    0,  110,    2, 0x06 /* Public */,
      17,    0,  111,    2, 0x06 /* Public */,
      18,    0,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    2,  113,    2, 0x0a /* Public */,
      20,    1,  118,    2, 0x0a /* Public */,
      22,    1,  121,    2, 0x0a /* Public */,
      25,    0,  124,    2, 0x0a /* Public */,
      26,    0,  125,    2, 0x0a /* Public */,
      27,    3,  126,    2, 0x0a /* Public */,
      28,    4,  133,    2, 0x0a /* Public */,
      29,    0,  142,    2, 0x0a /* Public */,
      30,    0,  143,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Double, QMetaType::Double,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 12, 0x80000000 | 12, QMetaType::Bool,    8,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Double, QMetaType::Double,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 12, 0x80000000 | 12, QMetaType::Bool,    8,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChartDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChartDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeXRange((*reinterpret_cast< const QCPRange(*)>(_a[1])),(*reinterpret_cast< const QCPRange(*)>(_a[2]))); break;
        case 1: _t->addDataSignal((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->addDataVectorSignal((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< const QVector<double>(*)>(_a[2])),(*reinterpret_cast< const QVector<double>(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 3: _t->replotSignal(); break;
        case 4: _t->maximizeXRangeSignal(); break;
        case 5: _t->clearSignal(); break;
        case 6: _t->on_x_range_changed((*reinterpret_cast< const QCPRange(*)>(_a[1])),(*reinterpret_cast< const QCPRange(*)>(_a[2]))); break;
        case 7: _t->on_slider_moved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_mouse_move((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: _t->on_clear_clicked(); break;
        case 10: _t->replot(); break;
        case 11: _t->addData((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 12: _t->addDataVector((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< const QVector<double>(*)>(_a[2])),(*reinterpret_cast< const QVector<double>(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 13: _t->followCurrent(); break;
        case 14: _t->viewGlobal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChartDisplay::*)(const QCPRange & , const QCPRange & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartDisplay::changeXRange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChartDisplay::*)(uint32_t , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartDisplay::addDataSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ChartDisplay::*)(uint32_t , const QVector<double> & , const QVector<double> & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartDisplay::addDataVectorSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ChartDisplay::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartDisplay::replotSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ChartDisplay::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartDisplay::maximizeXRangeSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ChartDisplay::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartDisplay::clearSignal)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChartDisplay::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ChartDisplay.data,
    qt_meta_data_ChartDisplay,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChartDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChartDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChartDisplay.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ChartDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ChartDisplay::changeXRange(const QCPRange & _t1, const QCPRange & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChartDisplay::addDataSignal(uint32_t _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChartDisplay::addDataVectorSignal(uint32_t _t1, const QVector<double> & _t2, const QVector<double> & _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChartDisplay::replotSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ChartDisplay::maximizeXRangeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ChartDisplay::clearSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
