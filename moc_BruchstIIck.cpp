/****************************************************************************
** Meta object code from reading C++ file 'BruchstIIck.h'
**
** Created: Sun Nov 24 17:25:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "BruchstIIck.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BruchstIIck.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BruchstIIck[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      20,   12,   12,   12, 0x08,
      27,   12,   12,   12, 0x08,
      48,   12,   12,   12, 0x08,
      70,   12,   12,   12, 0x08,
      96,   12,   12,   12, 0x08,
     123,   12,   12,   12, 0x08,
     145,   12,   12,   12, 0x08,
     168,   12,   12,   12, 0x08,
     191,   12,   12,   12, 0x08,
     215,   12,   12,   12, 0x08,
     234,   12,   12,   12, 0x08,
     253,   12,   12,   12, 0x08,
     276,   12,   12,   12, 0x08,
     309,   12,   12,   12, 0x08,
     336,   12,   12,   12, 0x08,
     359,   12,   12,   12, 0x08,
     380,   12,   12,   12, 0x08,
     402,  400,   12,   12, 0x08,
     434,   12,   12,   12, 0x08,
     459,   12,   12,   12, 0x08,
     480,   12,   12,   12, 0x08,
     502,   12,   12,   12, 0x08,
     524,   12,   12,   12, 0x08,
     545,   12,   12,   12, 0x08,
     568,   12,   12,   12, 0x08,
     589,   12,   12,   12, 0x08,
     615,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BruchstIIck[] = {
    "BruchstIIck\0\0load()\0save()\0"
    "handle_mean_filter()\0handle_median_filer()\0"
    "handle_laplacian_filter()\0"
    "handle_laplacianW_filter()\0"
    "handle_sobel_filter()\0handle_scharr_filter()\0"
    "handle_kirsch_filter()\0handle_roberts_filter()\0"
    "handle_light_add()\0handle_light_sub()\0"
    "handle_invert_filter()\0"
    "handle_global_threshold_filter()\0"
    "handle_set_border_filter()\0"
    "handle_custom_filter()\0handle_undo_button()\0"
    "handle_calcShards()\0i\0"
    "handle_edge_detecter_combo(int)\0"
    "handle_global_contrast()\0handle_gamma_patch()\0"
    "handle_load_program()\0handle_save_program()\0"
    "handle_run_program()\0handle_clear_program()\0"
    "handle_pop_program()\0handle_threshold_slider()\0"
    "handle_message_about()\0"
};

void BruchstIIck::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BruchstIIck *_t = static_cast<BruchstIIck *>(_o);
        switch (_id) {
        case 0: _t->load(); break;
        case 1: _t->save(); break;
        case 2: _t->handle_mean_filter(); break;
        case 3: _t->handle_median_filer(); break;
        case 4: _t->handle_laplacian_filter(); break;
        case 5: _t->handle_laplacianW_filter(); break;
        case 6: _t->handle_sobel_filter(); break;
        case 7: _t->handle_scharr_filter(); break;
        case 8: _t->handle_kirsch_filter(); break;
        case 9: _t->handle_roberts_filter(); break;
        case 10: _t->handle_light_add(); break;
        case 11: _t->handle_light_sub(); break;
        case 12: _t->handle_invert_filter(); break;
        case 13: _t->handle_global_threshold_filter(); break;
        case 14: _t->handle_set_border_filter(); break;
        case 15: _t->handle_custom_filter(); break;
        case 16: _t->handle_undo_button(); break;
        case 17: _t->handle_calcShards(); break;
        case 18: _t->handle_edge_detecter_combo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->handle_global_contrast(); break;
        case 20: _t->handle_gamma_patch(); break;
        case 21: _t->handle_load_program(); break;
        case 22: _t->handle_save_program(); break;
        case 23: _t->handle_run_program(); break;
        case 24: _t->handle_clear_program(); break;
        case 25: _t->handle_pop_program(); break;
        case 26: _t->handle_threshold_slider(); break;
        case 27: _t->handle_message_about(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BruchstIIck::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BruchstIIck::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BruchstIIck,
      qt_meta_data_BruchstIIck, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BruchstIIck::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BruchstIIck::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BruchstIIck::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BruchstIIck))
        return static_cast<void*>(const_cast< BruchstIIck*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BruchstIIck::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
