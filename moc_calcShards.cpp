/****************************************************************************
** Meta object code from reading C++ file 'calcShards.h'
**
** Created: Sun Nov 24 17:25:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calcShards.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calcShards.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CCalcShards[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      40,   36,   12,   12, 0x08,
      68,   12,   12,   12, 0x08,
      89,   36,   12,   12, 0x08,
     116,   12,   12,   12, 0x08,
     132,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CCalcShards[] = {
    "CCalcShards\0\0handle_create_shards()\0"
    "y,x\0handle_color_shard(int,int)\0"
    "handle_clear_color()\0handle_draw_shard(int,int)\0"
    "handle_export()\0handle_save_image()\0"
};

void CCalcShards::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CCalcShards *_t = static_cast<CCalcShards *>(_o);
        switch (_id) {
        case 0: _t->handle_create_shards(); break;
        case 1: _t->handle_color_shard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->handle_clear_color(); break;
        case 3: _t->handle_draw_shard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->handle_export(); break;
        case 5: _t->handle_save_image(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CCalcShards::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CCalcShards::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CCalcShards,
      qt_meta_data_CCalcShards, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CCalcShards::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CCalcShards::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CCalcShards::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CCalcShards))
        return static_cast<void*>(const_cast< CCalcShards*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CCalcShards::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
