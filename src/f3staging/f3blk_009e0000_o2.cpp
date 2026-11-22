#include <math.h>
#include <new>
#include <math.h>
#include <math.h>
#include <intrin.h>
#include <math.h>
// src/f3staging/f3blk_009e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009ee170 (community match, verified in this file)
extern const char DAT_00e80844[];
extern const char DAT_00e7d1b4[];
extern const char DAT_00e36400[];
class ObjectVisitor {
public:
    virtual void Unk00();
    virtual void Begin(const char* name, int flags, void* object);
    virtual void Array(const char* name, int flags, void* array, int usedBytes, int allocatedBytes);
    virtual void Object(const char* name, int flags, void* object);
    virtual void Unk10();
    virtual void Unk14();
    virtual void End();
};
class ArrayObject {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    void** children;
    int count;
    unsigned int capacity;
    void FUN_009ee170(ObjectVisitor* visitor);
};
void ArrayObject::FUN_009ee170(ObjectVisitor* visitor) {
    visitor->Begin(DAT_00e80844, 1, this);
    if (!(capacity & 0x80000000))
        visitor->Array(DAT_00e7d1b4, 1, children, count * 4, (capacity & 0x3fffffff) * 4);
    for (int i = 0; i < count; ++i)
        visitor->Object(DAT_00e36400, 1, children[i]);
    visitor->End();
}

// @f3 0x009f26a0 (community match, verified in this file)
extern int DAT_011697fc;
namespace f3m_009f26a0 {
void __cdecl FUN_00901e90(void* arr, int newCapacity, int elemSize);

struct Item26a0 {
    int value;
};
struct Handle26a0 {
    Item26a0* ptr;
};
struct Listener26a0 {
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0c();
    virtual void Unk10();
    virtual void Notify(Handle26a0 item, int kind, int value);
};
struct ItemArray26a0 {
    Handle26a0* data;
    int count;
    unsigned int capacity;
};
struct Entry26a0 {
    int unk00;
    ItemArray26a0 values;
};
struct Obj26a0 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
    Listener26a0* listener;
    int unk1c; int unk20; int unk24; int unk28; int unk2c;
    Entry26a0** table;
    void FUN_009f26a0(int index);
};
// pdb: hkpShapeDisplayViewer::removeAllGeometries | hkpShapeDisplayViewer.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: worldIndex
void Obj26a0::FUN_009f26a0(int index)
{
    Entry26a0* entry = table[index];
    for (int i = 0; i < entry->values.count; i++)
    {
        listener->Notify(entry->values.data[i], DAT_011697fc, entry->values.data[i].ptr->value);
    }
    ItemArray26a0* arr = &entry->values;
    int cap = arr->capacity & 0x3fffffff;
    if (cap < 0)
        FUN_00901e90(arr, (cap * 2) > 0 ? cap * 2 : 0, 4);
    arr->count = 0;
}
}   // namespace f3m_009f26a0

// @f3 0x009f97a0 (community match, verified in this file)
namespace f3m_009f97a0 {
namespace f3m_009f97a0 {
struct Vector { float f00, f04, f08, f0c, f10, f14; };
struct Scale { float f00, f04, f08; };
struct Dest { float f00, f04, f08, f0c, f10, f14, f18, f1c; };
struct Matrix
{
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
};
struct Cursor { Matrix* matrix; };
}
using namespace f3m_009f97a0;
// pdb: hk1dAngularVelocityMotorCommitJacobian | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
// pdb params: info, in, jac, out
void FUN_009f97a0(Vector* v, Scale* s, Dest* dest, Cursor* cursor)
{
    dest->f1c = s->f08 * v->f00;

    Matrix* m = cursor->matrix;
    m->m00 = (float)((double)m->m00 + 1.1920928955078125e-07);
    *((unsigned char*)&m->m00) = 14;

    m = m + 1;
    cursor->matrix = m;

    (m - 1)->m20 = v->f08 * s->f04;
    (m - 1)->m21 = v->f0c * s->f04;
    (m - 1)->m22 = v->f04;
    (m - 1)->m23 = v->f10;
    (m - 1)->m30 = v->f14;
}
}   // namespace f3m_009f97a0

// @f3 0x009fa730 (community match, verified in this file)
namespace f3m_009fa730 {
namespace f3m_009fa730 {
struct Src_9fa730 {
    unsigned char m00;
    unsigned char m01;
    unsigned char m02;
    unsigned char m03;
    unsigned char m04;
    unsigned char m05;
    unsigned char m06;
    unsigned char m07;
    float m08;
};
struct Rec_9fa730 {
    unsigned char type;
    unsigned char pad01;
    unsigned char pad02;
    unsigned char pad03;
    unsigned char flag;
    unsigned char pad05;
    unsigned char pad06;
    unsigned char pad07;
    int unk08;
    int unk0C;
};
struct Ctx_9fa730 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48;
    int unk4C;
};
struct Tmp_9fa730 {
    int key;
    int ctx;
    float f;
    int val;
};
void __cdecl FUN_00a4e670(Tmp_9fa730* t, Ctx_9fa730* obj, Rec_9fa730** cur);
}
using namespace f3m_009fa730;

// pdb: buildJacobianFromAngFrictionAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) void FUN_009fa730(Src_9fa730* src, Rec_9fa730** cur, Ctx_9fa730* obj, int a1)
{
    if (src->m02 != 0 && src->m08 != 0.0f)
    {
        Tmp_9fa730 t;
        t.key = (src->m03 << 4) + a1;
        t.f = src->m08;
        t.val = src->m04;
        t.ctx = obj->unk4C;
        FUN_00a4e670(&t, obj, cur);
        return;
    }
    Rec_9fa730* p = *cur;
    float v = *(float*)p;
    double r = v + 1.1920928955078125e-07;
    p->flag = src->m04;
    *(float*)p = (float)r;
    p->type = 3;
    *cur = p + 1;
}
Src_9fa730* volatile g_src_9fa730; Rec_9fa730** volatile g_cur_9fa730; Ctx_9fa730* volatile g_obj_9fa730; volatile int g_a_9fa730;
void caller_of_FUN_009fa730() { FUN_009fa730(g_src_9fa730, g_cur_9fa730, g_obj_9fa730, g_a_9fa730); }
}   // namespace f3m_009fa730

// @f3 0x009ee430 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009ee430 {
namespace f3m_009ee430 {
struct Allocator { void FUN_008f6d90(void* p, int bytes, int cls); };
}
extern "C" __declspec(dllimport) f3m_009ee430::Allocator* __stdcall TlsGetValue(unsigned int);
class hkBaseObject_9ee430
{
public:
    virtual ~hkBaseObject_9ee430() throw() {}
};
class hkReferencedObject_9ee430 : public hkBaseObject_9ee430
{
public:
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    int unk08;
    int unk0c;
    int unk10;
    virtual ~hkReferencedObject_9ee430() throw() {}
    void removeReference()
    {
        if (m_memSizeAndFlags != 0)
        {
            --m_referenceCount;
            if (m_referenceCount == 0)
                delete this;
        }
    }
};
class Iface_9ee430
{
public:
    virtual ~Iface_9ee430() throw() {}
    int unk18[11];
};
template <class T> struct hkArray_9ee430
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~hkArray_9ee430()
    {
        if (!(m_capacityAndFlags & 0x80000000))
        {
            int cap = m_capacityAndFlags & 0x3fffffff;
            f3m_009ee430::Allocator* a = TlsGetValue(DAT_010f3170);
            a->FUN_008f6d90(m_data, cap * sizeof(T), 0x17);
        }
    }
};
class FUN_009ee430 : public hkReferencedObject_9ee430, public Iface_9ee430
{
public:
    hkArray_9ee430<hkReferencedObject_9ee430*> m_children;
    virtual ~FUN_009ee430() throw();
};
// pdb: hkpConvexListShape::~hkpConvexListShape | hkpConvexListShape.obj | fnv360_0822_retail, call_seq, high
FUN_009ee430::~FUN_009ee430() throw()
{
    for (int i = 0; i < m_children.m_size; i++)
        m_children.m_data[i]->removeReference();
}
}   // namespace f3m_009ee430

// @f3 0x009fc3a0 (community match, verified in this file)
extern const double FUN_00e20408;
namespace f3m_009fc3a0 {
namespace f3m_009fc3a0 {
struct WriterContext_9fc3a0 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
};
struct WriterRecord_9fc3a0 {
    unsigned char type;
    unsigned char flag;
    unsigned short pad02;
    unsigned short low;
    unsigned short high;
    unsigned int value;
    unsigned int whole;
};
}
using namespace f3m_009fc3a0;
struct WriterArgs_9fc3a0 {
    unsigned int value_bits;
    unsigned char flag;
};
// pdb: hkInitHeader | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkSetInvMassBuildJacobian)
static void __declspec(noinline) FUN_009fc3a0(WriterContext_9fc3a0* apWriter, float** cursor, WriterArgs_9fc3a0 args)
{
    float* record = *cursor;
    float old = *record;
    int high = apWriter->unk54;
    old += FUN_00e20408;
    int low = apWriter->unk50;
    int whole = apWriter->unk48;
    *record = old;
    WriterRecord_9fc3a0* out = (WriterRecord_9fc3a0*)record;
    out->high = (unsigned short)high;
    unsigned int value = *(volatile unsigned int*)&args.value_bits;
    out->whole = (unsigned int)whole;
    unsigned char flag = args.flag;
    out->low = (unsigned short)low;
    out->value = value;
    out->type = 1;
    out->flag = flag;
    *cursor = (float*)(out + 1);
}
WriterContext_9fc3a0* volatile g_ctx_9fc3a0; float** volatile g_cur_9fc3a0; WriterArgs_9fc3a0 g_args_9fc3a0;
void caller_of_FUN_009fc3a0() { FUN_009fc3a0(g_ctx_9fc3a0, g_cur_9fc3a0, g_args_9fc3a0); }
}   // namespace f3m_009fc3a0

// @f3 0x009f13b0 (community match, verified in this file)
extern int DAT_00e80b80;
extern int DAT_00e80b60;
extern int DAT_00e80b50;
extern int DAT_00e80b38;
extern int DAT_00e80b28;
extern int DAT_00e80a58;
extern int DAT_00dcd094;
namespace f3m_009f13b0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);


class hkThreadMemory {
public:
    void Deallocate(void* p, int nbytes, int cls);
};

class ViewerBase {
public:
    ~ViewerBase();
};

class hkIfaceA {
public:
    int m_vptr;
    ~hkIfaceA() { m_vptr = (int)&DAT_00dcd094; }
};

class hkIfaceB {
public:
    int m_vptr;
    ~hkIfaceB() { m_vptr = (int)&DAT_00e80a58; }
};

class FUN_009f13b0 {
public:
    int m_vptr00;
    int unk04;
    int m_vptr08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_vptr20;
    int unk24;
    hkIfaceA m_ifaceA;
    hkIfaceB m_ifaceB;
    void* m_pData;
    int m_iCount;
    unsigned int m_uCapBits;
    void Destroy();
    void RemoveWorldData(int idx);
};

// pdb: hkpSweptTransformDisplayViewer::~hkpSweptTransformDisplayViewer | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, call_seq, medium
void FUN_009f13b0::Destroy()
{
    m_vptr00 = (int)&DAT_00e80b80;
    m_vptr08 = (int)&DAT_00e80b60;
    m_vptr20 = (int)&DAT_00e80b50;
    m_ifaceA.m_vptr = (int)&DAT_00e80b38;
    m_ifaceB.m_vptr = (int)&DAT_00e80b28;
    for (int i = m_iCount - 1; i >= 0; --i)
        RemoveWorldData(i);
    if ((m_uCapBits & 0x80000000u) == 0)
    {
        int n = m_uCapBits & 0x3fffffff;
        hkThreadMemory* a = (hkThreadMemory*)TlsGetValue(DAT_010f3170);
        a->Deallocate(m_pData, n * 4, 0x17);
    }
    m_ifaceB.~hkIfaceB();
    m_ifaceA.~hkIfaceA();
    ((ViewerBase*)this)->~ViewerBase();
}
}   // namespace f3m_009f13b0

// @f3 0x009fcb10 (community match, verified in this file)
extern const double DAT_00e20408;
namespace f3m_009fcb10 {
struct Source1149 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int value48,unk4C,context50,context54; };
struct Record1149 {
 union { float accumulator; struct { unsigned char opcode,option; unsigned short unk02; }; };
 unsigned short context50,context54;
 unsigned int input;
 int value;
};
// pdb: hkBeginConstraints | hkpBuildJacobianFromAtoms.obj | tesv_win, call_seq, medium
void __cdecl FUN_009fcb10(const Source1149* source,Record1149** dest,volatile unsigned int input,volatile unsigned char option) {
 Record1149* record=*dest;
 double next=record->accumulator+DAT_00e20408;
 int last=source->context54;
 int first=source->context50;
 int value=source->value48;
 record->accumulator=(float)next;
 record->context54=(unsigned short)last;
 unsigned int bits=input;
 record->value=value;
 unsigned char flag=option;
 record->context50=(unsigned short)first;
 record->input=bits;
 record->opcode=1;
 record->option=flag;
 *dest=const_cast<Record1149*>(record+1);
}
}   // namespace f3m_009fcb10

// @f3 0x009e5e90 (community match, verified in this file)
extern float DAT_01062ec8;
extern float DAT_00de20b0;
namespace f3m_009e5e90 {
// FUN_009e5e90: ctor of a polymorphic class with a non-polymorphic base at +4.
// Stack args: const float* a, const float* b, float c, float d. Returns this.


float __stdcall Call009e5290();
void __stdcall Call009e5500(float v);
void __stdcall Call009e52e0();

struct FUN_009e5e90_base {
    FUN_009e5e90_base(float d)
    {
        unk0c = d;
        unk02 = 1;
        unk04 = 0;
        unk08 = 3;
    }
    unsigned short unk00;
    unsigned short unk02;
    unsigned int unk04;
    int unk08;
    float unk0c;
};

class FUN_009e5e90 : public FUN_009e5e90_base {
public:
    virtual void Unk00();
    FUN_009e5e90(const float* a, const float* b, float c, float d);
    unsigned int unk14;
    float unk18;
    unsigned int unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
};

// pdb: hkpCylinderShape::hkpCylinderShape | hkpCylinderShape.obj | fnv360_0822_retail, objrun, high
// pdb params: vertexA, vertexB, cylinderRadius, paddingRadius
FUN_009e5e90::FUN_009e5e90(const float* a, const float* b, float c, float d)
    : FUN_009e5e90_base(d)
{
    if (DAT_01062ec8 < 0.0f)
        DAT_01062ec8 = 1.0f - Call009e5290();
    unk20 = a[0];
    unk24 = a[1];
    unk28 = a[2];
    unk2c = a[3];
    unk30 = b[0];
    unk34 = b[1];
    unk38 = b[2];
    unk3c = b[3];
    Call009e5500(c);
    Call009e52e0();
    unk18 = DAT_00de20b0;
}
}   // namespace f3m_009e5e90

// @f3 0x009e1d40 (community match, verified in this file)
#include <intrin.h>
extern char DAT_00e8057c[];
extern char DAT_00e36414[];
extern char DAT_00e35eec[];
extern char DAT_00e8053c[];
extern char DAT_00dcc494[];
namespace f3m_009e1d40 {


struct FUN_009e1d40_Ref {
    virtual void vf00(int value);
    short unk04;
    short unk06;
};

struct FUN_009e1d40_Obj {
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_009e1d40_Ref* unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    void* unk30;
    FUN_009e1d40_Ref* unk34;

    void FUN_009e1d40();
};

// pdb: hkpMoppBvTreeShape::~hkpMoppBvTreeShape | hkpMoppBvTreeShape.obj | fnv360_0822_retail, call_seq, high
void FUN_009e1d40_Obj::FUN_009e1d40() {
    this->unk00 = DAT_00e8057c;
    _ReadWriteBarrier();
    FUN_009e1d40_Ref* first = this->unk34;
    this->unk30 = DAT_00e36414;
    if (first->unk04 != 0) {
        if (--first->unk06 == 0)
            first->vf00(1);
    }

    this->unk30 = DAT_00e35eec;
    _ReadWriteBarrier();
    FUN_009e1d40_Ref* second = this->unk10;
    this->unk00 = DAT_00e8053c;
    if (second->unk04 != 0) {
        if (--second->unk06 == 0)
            second->vf00(1);
    }

    this->unk00 = DAT_00dcc494;
}
}   // namespace f3m_009e1d40

// @f3 0x009ec660 (community match, verified in this file)
#include <intrin.h>
extern unsigned int DAT_010f3170;
extern unsigned int DAT_0116913c;
extern const char DAT_00e807bc[];
extern const char DAT_00e807b4[];
extern const char DAT_00e807a8[];
extern const char DAT_00e0811c[];
namespace f3m_009ec660 {



struct hkMonitorStream {
    int unk00;
    char* m_cur;
    int unk08;
    char* m_end;
};

struct Allocator_9ec660 {
    void FUN_008f6d90(void* p, int bytes, int cls) throw();
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct InplaceArray_9ec660 {
    int unk00;
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    __int64 m_storage[128];

    void FUN_00a60840() throw();

    ~InplaceArray_9ec660() throw() {
        if (!(m_capacityAndFlags & 0x80000000)) {
            int cap = m_capacityAndFlags & 0x3fffffff;
            Allocator_9ec660* a = (Allocator_9ec660*)TlsGetValue(DAT_010f3170);
            a->FUN_008f6d90(m_data, cap * 8, 0x17);
        }
    }
};

struct ConvexConfig {
    unsigned char m_b00;
    unsigned char m_pad01;
    unsigned char m_b02;
    unsigned char m_pad03;
    float m_f04;
    float m_f08;
    float m_f0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
};

void __cdecl FUN_009eb790(const void* a1, void* a2, const void* a3, int a4) throw();
void __cdecl FUN_00a5d870(void* a1, const void* a2) throw();
int __cdecl FUN_00a5d940(void* a1, void* a2, void* a3, const void* a4, const void* a5) throw();

// pdb: hkGeometryUtility::createConvexGeometry | hkGeometryUtility.obj | fnv360_0822_retail, call_seq, medium
// pdb params: stridedVertsIn, geometryOut, planeEquationsOut
void __cdecl FUN_009ec660(const void* a1, const void* a2, const void* a3, int a4)
{
    volatile unsigned int ticks;
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0116913c);
    char* cur = stream->m_cur;
    if (cur < stream->m_end) {
        *(const char**)cur = DAT_00e807bc;
        *(const char**)(cur + 12) = DAT_00e807b4;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = ticks;
        stream->m_cur = cur + 16;
    }

    InplaceArray_9ec660 array;
    array.FUN_00a60840();
    FUN_009eb790(a1, &array, a2, a4);
    FUN_00a5d870(&array, a2);

    stream = (hkMonitorStream*)TlsGetValue(DAT_0116913c);
    char* cur2 = stream->m_cur;
    if (cur2 < stream->m_end) {
        *(const char**)cur2 = DAT_00e807a8;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        *(unsigned int*)(cur2 + 4) = ticks;
        stream->m_cur = cur2 + 12;
    }

    char outByte;
    ConvexConfig cfg;
    cfg.m_f04 = 2.0e-5f;
    cfg.m_f08 = 4.0e-6f;
    cfg.m_b02 = (a4 == 2);
    cfg.m_f0c = 1.0e-6f;
    cfg.m_f10 = 1.0e-5f;
    cfg.m_f14 = 0.05f;
    cfg.m_f18 = 1.0e-6f;
    cfg.m_f1c = 1.0e-6f;
    cfg.m_b00 = 1;
    cfg.m_f20 = 1.0e-8f;
    cfg.m_f24 = 1.0e-6f;
    cfg.m_f28 = 1.0e-4f;
    cfg.m_f2c = 1.0e-5f;
    cfg.m_f30 = 2.0e-5f;

    FUN_00a5d940(&outByte, &cfg, &array, a2, a3);

    stream = (hkMonitorStream*)TlsGetValue(DAT_0116913c);
    char* cur3 = stream->m_cur;
    if (cur3 < stream->m_end) {
        *(const char**)cur3 = DAT_00e0811c;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        *(unsigned int*)(cur3 + 4) = ticks;
        stream->m_cur = cur3 + 12;
    }
}
}   // namespace f3m_009ec660

// @f3 0x009ed780 (community match, verified in this file)
namespace f3m_009ed780 {
namespace n9ed780 {
struct Vec4 { float x, y, z, w; };
struct Shape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void GetCenter(Vec4* out);
};
struct Obj {
    char pad[0x18];
    Shape* shape;
    char pad1c[4];
    Vec4 col0;
    Vec4 col1;
    Vec4 col2;
    Vec4 trans;
    void FUN_009ed780(Vec4* out);
};
// pdb: hkpConvexTransformShape::getSupportingVertexImpl | hkpConvexTransformShape.obj | tesv_win, objrun_open, low
void Obj::FUN_009ed780(Vec4* out)
{
    shape->GetCenter(out);
    float x = out->x;
    float y = out->y;
    float z = out->z;
    out->x = col0.x * x + col1.x * y + col2.x * z + trans.x;
    out->y = col0.y * x + col1.y * y + col2.y * z + trans.y;
    out->z = col0.z * x + col1.z * y + col2.z * z + trans.z;
    out->w = 0.0f;
}
}
}   // namespace f3m_009ed780

// @f3 0x009e0590 (community match, verified in this file)
namespace f3m_009e0590 {
namespace n9e0590 {
struct hkArray;
void __cdecl FUN_00901f10(hkArray* a, int elemSize);
struct hkArray {
    int* m_data;
    int m_size;
    int m_capacityAndFlags;
    void pushBack(int v)
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, 4);
        m_data[m_size] = v;
        m_size++;
    }
};
struct Writer {
    char pad[0x1c];
    hkArray ops;
    hkArray args;
};
struct Obj {
    int unk00;
    Writer* w;
    void FUN_009e0590(int a, int b);
};
// pdb: hkpConstraintConstructionKit::addConstraintModifierCallback | hkpConstraintConstructionKit.obj | tesv_win, objrun_open, low
void Obj::FUN_009e0590(int a, int b)
{
    w->ops.pushBack(0x18);
    w->args.pushBack(a);
    w->ops.pushBack(b);
}
}
}   // namespace f3m_009e0590

// @f3 0x009ee7e0 (community match, verified in this file)
namespace f3m_009ee7e0 {
struct Ref9ee7e0 { int vtbl; unsigned short unk04; unsigned short refs; };
class Base9ee7e0 {
public:
    virtual ~Base9ee7e0();
    unsigned short unk04;
    unsigned short refs;
    Base9ee7e0() { refs = 1; }
};
class FUN_009ee7e0 : public Base9ee7e0 {
public:
    virtual ~FUN_009ee7e0();
    Ref9ee7e0* ref;
    bool flag;
    FUN_009ee7e0(Ref9ee7e0* r, bool f);
};
// pdb: hkOArchive::hkOArchive | hkOArchive.obj | fnv360_0822_retail, call_gap, high
// pdb params: sw, bs
FUN_009ee7e0::FUN_009ee7e0(Ref9ee7e0* r, bool f)
{
    ref = r;
    flag = f;
    if (r->unk04)
        ++r->refs;
}
}   // namespace f3m_009ee7e0

// @f3 0x009f3350 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009f3350 {
namespace n9f3350 {
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned int) throw();
}
struct Data9f3350 { char pad00[0x6c]; void** items; int count; };
class FUN_00a64860 { public: virtual ~FUN_00a64860(); int unk04; };
class Base08 { public: virtual void b08(); char pad[0x14]; };
class Base20 { public: virtual void b20(); Data9f3350* data; };
class Base28 { public: virtual void b28(); __forceinline ~Base28() {} };
class Base2c { public: virtual void b2c(); __forceinline ~Base2c() {} };
struct Array9f3350 {
    void** ptr;
    int unk04;
    unsigned int flags;
    __forceinline ~Array9f3350() {
        if (!(flags & 0x80000000)) {
            unsigned int n = flags & 0x3fffffff;
            n9f3350::Alloc* a = n9f3350::FUN_00d9b080(DAT_010f3170);
            a->FUN_008f6d90(ptr, n * 4, 0x17);
        }
    }
};
class FUN_009f3350 : public FUN_00a64860, public Base08, public Base20, public Base28, public Base2c {
public:
    Array9f3350 arr;
    void FUN_009f30e0(void* item) throw();
    virtual ~FUN_009f3350();
};
// pdb: hkpPhantomDisplayViewer::~hkpPhantomDisplayViewer | hkpPhantomDisplayViewer.obj | fnv360_0822_retail, call_seq, medium
FUN_009f3350::~FUN_009f3350()
{
    if (data) {
        for (int i = 0; i < data->count; ++i)
            FUN_009f30e0(data->items[i]);
    }
}
}   // namespace f3m_009f3350

// @f3 0x009ef290 (community match, verified in this file)
namespace f3m_009ef290 {
struct Owner {
    int unk00;
    unsigned short unk04;
    Owner* FUN_009ef290(int flags);
    void FUN_009ef0e0();
};
// pdb: hkServerProcessHandler::`scalar deleting destructor' | hkServerProcessHandler.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: hkRemoteObjectProcess::`vector deleting destructor')
Owner* Owner::FUN_009ef290(int flags) {
    FUN_009ef0e0();
    if (flags & 1) {
        f3m_009ee430::f3m_009ee430::Allocator* allocator = f3m_009ee430::TlsGetValue(DAT_010f3170);
        allocator->FUN_008f6d90(this, unk04, 0x35);
    }
    return this;
}
}   // namespace f3m_009ef290

// @f3 0x009ee850 (community match, verified in this file)
namespace f3m_009ee850 {
struct Ref9ee850 { virtual void Delete(int flags) throw(); short active; short refs; };
struct Ptr9ee850 {
    Ref9ee850* p;
    ~Ptr9ee850() throw() {
        Ref9ee850* r = p;
        if (r->active) {
            --r->refs;
            if (!r->refs) r->Delete(1);
        }
    }
};
class Base9ee850 {
public:
    virtual ~Base9ee850() {}
    unsigned short unk04;
    unsigned short refs;
};
class FUN_009ee850 : public Base9ee850 {
public:
    virtual ~FUN_009ee850();
    Ptr9ee850 ref;
    bool flag;
};
// pdb: hkOArchive::~hkOArchive | hkOArchive.obj | fnv360_0822_retail, call_dedup, high
FUN_009ee850::~FUN_009ee850()
{
}
}   // namespace f3m_009ee850

// @f3 0x009f16d0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009f16d0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Object009f16d0 {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
    Object009f16d0* FUN_008f6d30(unsigned int a, unsigned int b);
    void* FUN_009f1540(void* value);
};
// pdb: hkpSimulationIslandViewer::create | hkpSimulationIslandViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: contexts
void* FUN_009f16d0(void* value) {
    Object009f16d0* object = (Object009f16d0*)TlsGetValue(DAT_010f3170);
    object = object->FUN_008f6d30(0x48, 0x35);
    object->unk04 = 0x48;
    void* result = object->FUN_009f1540(value);
    if (result)
        return (char*)result + 8;
    return 0;
}
}   // namespace f3m_009f16d0

// @f3 0x009e0d90 (community match, verified in this file)
namespace f3m_009e0d90 {
namespace task0777 {
struct S_00c89a30_Obj;
struct S_00c89a30_Owner;
struct S_00c89a30_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual int v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53(S_00c89a30_Obj* o, int f);
    int unk04;
    S_00c89a30_Owner* unk08;
    void FUN_008d8a30(S_00c89a30_Owner* owner);
    bool FUN_009e0d90(S_00c89a30_Obj* other);
};
// @fnv 0x00c89a30
// pdb: bhkConstraintChain::KillCinfo | bhkConstraintChain.obj | fnv360_0822_debug, objrun, low
// pdb params: abCreated
bool S_00c89a30_Obj::FUN_009e0d90(S_00c89a30_Obj* other)
{
    S_00c89a30_Owner* owner = this ? unk08 : 0;
    bool r = false;
    if (owner)
    {
        if (other)
        {
            int a = v38();
            int b = other->v38();
            if (a != b)
            {
                v40();
                v53(other, 1);
                other->FUN_008d8a30(owner);
                r = true;
            }
        }
        else
        {
            v40();
        }
    }
    return r;
}

}
}   // namespace f3m_009e0d90

// @f3 0x009ecee0 (community match, verified in this file)
namespace f3m_009ecee0 {
struct Tgt_009ecee0 {
    virtual void t00();
    virtual void t01();
    virtual void t02();
    virtual void t03();
    virtual void t04();
    virtual void t05();
    virtual void t06();
    virtual void t07();
    virtual void t08();
    virtual int v();
};
struct O_009ecee0 { char pad[0x18]; Tgt_009ecee0* p; int FUN_009ecee0(); };
// pdb: hkpConvexTransformShape::getNumCollisionSpheresImpl | hkpConvexTransformShape.obj | fnv360_0822_retail, objrun_open, low
int O_009ecee0::FUN_009ecee0() { return p->v(); }
}   // namespace f3m_009ecee0

// @f3 0x009e5ac0 (community match, verified in this file)
namespace f3m_009e5ac0 {
namespace n9e5ac0 {
struct Vec4 { float x, y, z, w; };
}
struct Obj9e5ac0 {
    char pad[0x30];
    float x, y, z, w;
    void hkpCylinderShape_getFirstVertex(n9e5ac0::Vec4* out) const;
};
// pdb: hkpCylinderShape::getFirstVertex | hkpCylinderShape.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void Obj9e5ac0::hkpCylinderShape_getFirstVertex(n9e5ac0::Vec4* out) const
{
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
}
}   // namespace f3m_009e5ac0

// @f3 0x009f30b0 (community match, verified in this file)
namespace f3m_009f30b0 {
struct Target_009f30b0 {
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    void FUN_009f2f50();
    Target_009f30b0* FUN_009f30b0(int flags);
};
// pdb: hkpShapeDisplayViewer::`scalar deleting destructor' | hkpShapeDisplayViewer.obj | fnv360_0822_retail, vtable, medium
Target_009f30b0* Target_009f30b0::FUN_009f30b0(int flags)
{
    FUN_009f2f50();
    if (flags & 1) {
        f3m_009ee430::f3m_009ee430::Allocator* a = (f3m_009ee430::f3m_009ee430::Allocator*)f3m_009f13b0::TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(this, unk04, 0x35);
    }
    return this;
}
}   // namespace f3m_009f30b0

// @f3 0x009e4a80 (community match, verified in this file)
extern char DAT_00e8066c[];
extern char DAT_00e80648[];
extern char DAT_00e35eec[];
namespace f3m_009e4a80 {

void __cdecl FUN_00cb1260(void* dst, const void* src, int size);

class ThreadMemory
{
public:
    virtual void* Alloc(int align, int size, int cls);
};

struct Subpart
{
    unsigned char unk00;
    unsigned char materialIndexType;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};

class ShapeCollection
{
public:
    void* m_vptr00;
    short unk04;
    short unk06;
    int unk08;
    int m_type;
    void* m_vptr10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    Subpart* m_data1;
    int m_count1;
    Subpart* m_data2;
    int m_count2;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Subpart m_inline;

    ShapeCollection* FUN_009e4a80(int flag);
};

// pdb: hkbStateMachine::hkbStateMachine | hkbStateMachine.obj | tesv_win, call_seq, medium
ShapeCollection* ShapeCollection::FUN_009e4a80(int flag)
{
    unk06 = 1;
    *(void* volatile*)&m_vptr10 = DAT_00e35eec;
    m_type = 8;
    m_vptr00 = DAT_00e8066c;
    m_vptr10 = DAT_00e80648;

    if (flag != 0)
    {
        for (int i = 0; i < m_count1; ++i)
        {
            if (m_data1[i].materialIndexType == 0)
                m_data1[i].materialIndexType = 1;
        }
        for (int i = 0; i < m_count2; ++i)
        {
            if (m_data2[i].materialIndexType == 0)
                m_data2[i].materialIndexType = 1;
        }
        int n1 = m_count1;
        if (n1 == 1)
        {
            FUN_00cb1260(&m_inline, m_data1, sizeof(Subpart));
            m_data1 = &m_inline;
        }
        else if (n1 > 1)
        {
            ThreadMemory* mem = (ThreadMemory*)f3m_009f13b0::TlsGetValue(DAT_010f3170);
            Subpart* p = (Subpart*)mem->Alloc(sizeof(Subpart), n1 * sizeof(Subpart), 0x25);
            FUN_00cb1260(p, m_data1, m_count1 * sizeof(Subpart));
            m_data1 = p;
        }
        int n2 = m_count2;
        if (n2 > 0)
        {
            ThreadMemory* mem = (ThreadMemory*)f3m_009f13b0::TlsGetValue(DAT_010f3170);
            Subpart* p = (Subpart*)mem->Alloc(sizeof(Subpart), n2 * sizeof(Subpart), 0x25);
            FUN_00cb1260(p, m_data2, m_count2 * sizeof(Subpart));
            m_data2 = p;
        }
    }
    m_type = 0xf;
    return this;
}
}   // namespace f3m_009e4a80

// @f3 0x009e33b0 (community match, verified in this file)
namespace f3m_009e33b0 {
namespace f3m_009e33b0 {
struct Stats {
    virtual void F0();
    virtual void Begin(const char* name, int kind, const void* obj);
    virtual void Chunk(const char* name, int kind, const void* p, int used, int alloc);
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void End();
};
struct Item { char unk[0x40]; };
struct Obj {
    void FUN_009e33b0(Stats* s);
    int unk00[20];
    Item* a;
    int aCount;
    Item* b;
    int bCount;
    int unk60[4];
    char inl[0x40];
};
void Obj::FUN_009e33b0(Stats* s) {
    s->Begin("MeshShape", 1, this);
    if ((void*)a != (void*)inl) {
        int size = aCount << 6;
        s->Chunk("TriangleSubParts", 1, a, size, size);
    }
    int size2 = bCount << 6;
    s->Chunk("ShapeSubParts", 1, b, size2, size2);
    s->End();
}
}
}   // namespace f3m_009e33b0

// @f3 0x009e1ae0 (community match, verified in this file)
namespace f3m_009e1ae0 {
class FUN_009e1ae0_Class
{
public:
    void FUN_009e1ae0(void* arg);
};

void FUN_009a1770(void* arg1, int arg2, void* arg3);

void FUN_009e1ae0_Class::FUN_009e1ae0(void* arg)
{
    FUN_009a1770((void*)((char*)this + 0x10), 50, arg);
}
}   // namespace f3m_009e1ae0

// @f3 0x009f3150 (community match, verified in this file)
namespace f3m_009f3150 {
namespace Task0855 {
struct World {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 int unk64;
 int unk68;
 int unk6c;
 int unk70;
 int unk74;
 int unk78;
 int unk7c;
 int unk80;
 int unk84;
 int unk88;
 int unk8c;
 int unk90;
 int unk94;
 int unk98;
 int unk9c;
 int unka0;
 int unka4;
 int unka8;
 int unkac;
 int unkb0;
 int unkb4;
 int unkb8;
 int unkbc;
 int unkc0;
 int unkc4;
 int unkc8;
 int unkcc;
 int unkd0;
 int unkd4;
 int unkd8;
 int unkdc;
 int unke0;
 void** items; int count;
 void hkpWorld_addPhantomListener(void*);
 void FUN_00903be0(void*);
};
struct Listener {virtual void v0(); virtual void callback(void*);};
struct Viewer {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 Listener listener;
 int secondary;
 void FUN_009f3150(World*);
};
// pdb: hkpPhantomDisplayViewer::addWorld | hkpPhantomDisplayViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: world
void Viewer::FUN_009f3150(World* world) {
 void* p1=this ? &listener:0;
 world->hkpWorld_addPhantomListener(p1);
 void* p2=this ? &secondary:0;
 world->FUN_00903be0(p2);
 int i=0;
 if(world->count>0) {
  Listener* base=&listener;
  do {void* item=world->items[i]; base->callback(item); ++i;}while(i<world->count);
 }
}
}
}   // namespace f3m_009f3150

// @f3 0x009e0c50 (community match, verified in this file)
extern int DAT_011697c0;
namespace f3m_009e0c50 {
namespace Task0864 {
struct FUN_008fbad0 {
 virtual void slot00();
 int unk04;
 ~FUN_008fbad0();
};
struct FUN_009e0c50: FUN_008fbad0 {
 virtual ~FUN_009e0c50();
 void FUN_008f7ef0();
};
// pdb: bhkConstraintChain::~bhkConstraintChain | bhkConstraintChain.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkArray<class hkVector4,struct hkContainerHeapAllocator>::~hkArray<class hkVector4,struct hkContainerHeapAllocator>)
FUN_009e0c50::~FUN_009e0c50(){FUN_008f7ef0(); --DAT_011697c0;}
}
}   // namespace f3m_009e0c50

// @f3 0x009e28c0 (community match, verified in this file)
extern int DAT_011697cc;
namespace f3m_009e28c0 {
class FUN_00c86720_base
{
public:
    virtual void unk00();
    ~FUN_00c86720_base();
    int unk04;
};
class FUN_009e28c0 : public FUN_00c86720_base
{
public:
    virtual ~FUN_009e28c0();
    void FUN_008f7ef0();
};
// pdb: bhkHeightFieldShape::~bhkHeightFieldShape | bhkHeightFieldShape.obj | fnv360_0822_retail, caller_sim, medium
FUN_009e28c0::~FUN_009e28c0()
{
    FUN_008f7ef0();
    --DAT_011697cc;
}
}   // namespace f3m_009e28c0

// @f3 0x009e6e10 (community match, verified in this file)
namespace f3m_009e6e10 {
namespace n9e6e10 {
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    void operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
};
struct Base {
    virtual ~Base();
    Base(int type);
    char pad[0x60 - 4];
};
}
struct FUN_009e6e10 : n9e6e10::Base {
    n9e6e10::Vec4 m_a;
    n9e6e10::Vec4 m_b;
    float m_c;
    int m_d;
    int m_e;
    FUN_009e6e10(const n9e6e10::Vec4& a, const n9e6e10::Vec4& b, float c, int d, int e);
    ~FUN_009e6e10();
};
// pdb: hkDisplayCylinder::hkDisplayCylinder | hkDisplayCylinder.obj | fnv360_0822_retail, uvref, medium
// pdb params: top, bottom, radius, numSides, numHeightSegments
FUN_009e6e10::FUN_009e6e10(const n9e6e10::Vec4& a, const n9e6e10::Vec4& b, float c, int d, int e)
    : n9e6e10::Base(9), m_d(d), m_e(e)
{
    m_a = a;
    m_b = b;
    m_c = c;
}
}   // namespace f3m_009e6e10

// @f3 0x009e2930 (community match, verified in this file)
struct StrArr
{
    unsigned field0, field4;
    unsigned short m8;
    unsigned short mA;
    unsigned short fieldC;
    unsigned short mE;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char*&);
};
void __stdcall FUN_008f7a20(StrArr*);
char* FUN_00847b50(const char*);
struct GlobalObjectO2_00a7b610
{
    const char* f0;
};
extern GlobalObjectO2_00a7b610 DAT_011697d0;
// @fnv 0x00bc28f0
// pdb: bhkHeightFieldShape::GetViewerStrings | bhkHeightFieldShape.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apStrings
void __stdcall FUN_009e2930(StrArr* pStrArr)
{
    FUN_008f7a20(pStrArr);
    char* pStr = FUN_00847b50(DAT_011697d0.f0);
    unsigned int uiIndex = pStrArr->mA;
    unsigned int cnt = pStrArr->m8;
    if (uiIndex >= cnt)
    {
        pStrArr->FUN_00555790(pStrArr->mE + uiIndex);
    }
    pStrArr->FUN_005b3880(uiIndex, pStr);
}

// @f3 0x009e1b90 (community match, verified in this file)
namespace f3m_009e1b90 {
namespace n9e1b90 {
struct Writer {
    virtual void v0();
    virtual void BeginObject(const char* name, int n, const void* obj);
    virtual void v8();
    virtual void WriteRef(const char* name, int n, const void* obj);
    virtual void v10();
    virtual void v14();
    virtual void EndObject();
};
}
struct FUN_009e1b90_c {
    char pad[0x10];
    void* mopp;
    char pad14[0x34 - 0x14];
    void* mesh;
    void FUN_009e1b90(n9e1b90::Writer* w);
};
void FUN_009e1b90_c::FUN_009e1b90(n9e1b90::Writer* w)
{
    w->BeginObject("MoppShape", 1, this);
    w->WriteRef("Mesh", 1, mesh);
    w->WriteRef("Mopp", 1, mopp);
    w->EndObject();
}
}   // namespace f3m_009e1b90

// @f3 0x009e1e90 (community match, verified in this file)
namespace f3m_009e1e90 {
struct FUN_009e1e90_Ref {
    int unk00;
    short unk04;
    short unk06;
};

struct FUN_009e1e90_Obj {
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    void* unk30;
    FUN_009e1e90_Ref* unk34;

    FUN_009e1e90_Obj* FUN_009e1e90(FUN_009e1e90_Ref* ref, int value);
};

void __stdcall FUN_009e1e30(int kind, int value);

// pdb: hkpMoppBvTreeShape::hkpMoppBvTreeShape | hkpMoppBvTreeShape.obj | fnv360_0721_beta, objrun, high
// pdb params: collection, code
FUN_009e1e90_Obj* FUN_009e1e90_Obj::FUN_009e1e90(FUN_009e1e90_Ref* ref, int value)
{
    FUN_009e1e30(11, value);
    unk00 = DAT_00e8057c;
    unk30 = DAT_00e36414;
    unk34 = ref;
    if (ref->unk04 != 0)
        ++ref->unk06;
    return this;
}
}   // namespace f3m_009e1e90

// @f3 0x009e3520 (community match, verified in this file)
namespace f3m_009e3520 {
struct Outer_9e3520 { int* FUN_009e34d0(int k); };
struct Inner_9e3520 { int FUN_009e3520(int k); };
// pdb: hkpExtendedMeshShape::ShapesSubpart::ShapesSubpart | hkpExtendedMeshShape.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkpExtendedMeshShape::getCollisionFilterInfo)
int Inner_9e3520::FUN_009e3520(int k) { int* p = ((Outer_9e3520*)((char*)this - 0x10))->FUN_009e34d0(k); if (p) return *p; return 0; }
}   // namespace f3m_009e3520

// @f3 0x009e1aa0 (community match, verified in this file)
namespace f3m_009e1aa0 {
class FUN_009e1aa0_Obj {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;

    void __thiscall FUN_009e1aa0(const float* first, const float* second);
};

void __thiscall FUN_009e1aa0_Obj::FUN_009e1aa0(const float* first, const float* second)
{
    unk20 = first[0];
    unk24 = first[1];
    unk28 = first[2];
    unk2C = first[3];
    unk30 = second[0];
    unk34 = second[1];
    unk38 = second[2];
    unk3C = second[3];
}
}   // namespace f3m_009e1aa0

// @f3 0x009e28a0 (community match, verified in this file)
namespace f3m_009e28a0 {
struct V4_9e28a0 { float x, y, z, w; void FUN_009e28a0(const V4_9e28a0* s); };
// pdb: hkpMoppCompilerInput::setAbsoluteFitToleranceOfAxisAlignedTriangles | hkpMoppCompilerInput.obj | tesv_win, objrun_open, low
void V4_9e28a0::FUN_009e28a0(const V4_9e28a0* s) { x = s->x; y = s->y; z = s->z; w = s->w; }
}   // namespace f3m_009e28a0

// @f3 0x009e1b50 (community match, verified in this file)
namespace f3m_009e1b50 {
namespace n9e1b50 {
struct RefObj {
    unsigned short memSize;
    short refCount;
    RefObj() : refCount(1) {}
    virtual ~RefObj();
};
struct Shape : RefObj {
    int userData;
    Shape() : userData(0) {}
};
struct Vec4 {
    float x, y, z, w;
    void setZero4() { w = 0.0f; z = 0.0f; y = 0.0f; x = 0.0f; }
};
}
struct FUN_009e1b50 : n9e1b50::Shape {
    int pad0c;
    short type;
    char pad12[0x20 - 0x12];
    n9e1b50::Vec4 a;
    n9e1b50::Vec4 b;
    short m40;
    FUN_009e1b50();
    virtual ~FUN_009e1b50();
};
// pdb: hkpBallAndSocketConstraintData::hkpBallAndSocketConstraintData | hkpBallAndSocketConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_009e1b50::FUN_009e1b50()
{
    type = 3;
    m40 = 5;
    a.setZero4();
    b.setZero4();
}
}   // namespace f3m_009e1b50

// @f3 0x009e41f0 (community match, verified in this file)
namespace f3m_009e41f0 {
namespace task1059 {
void __cdecl FUN_009a7a80(void*,void*,void*,float,int);
struct Vec{float x,y,z,w;};
struct Object{Vec unk00,unk10,unk20,field30,field40;void FUN_009e41f0(void*,float,int);};
// pdb: hkpExtendedMeshShape::operator delete | hkpExtendedMeshShape.obj | fnv360_0822_debug, objrun_open, low
// pdb params: p
void Object::FUN_009e41f0(void* p,float v,int n){FUN_009a7a80(p,&field30,&field40,v,n);}
}
}   // namespace f3m_009e41f0

// @f3 0x009e4640 (community match, verified in this file)
namespace f3m_009e4640 {
extern unsigned long DAT_010f3170;
struct Svc_9e4640 { virtual void t0(); virtual void v1(int a); };
extern "C" __declspec(dllimport) Svc_9e4640* __stdcall TlsGetValue(unsigned long);
struct O_9e4640 { char pad[0x58]; int a58; void FUN_009e4640(); };
void O_9e4640::FUN_009e4640() { int v = a58; Svc_9e4640* s = TlsGetValue(DAT_010f3170); s->v1(v); }
}

// @f3 0x009f3b20 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009f3b20 {
namespace task9f3b20 {
struct Item { int unk00; short unk04; short unk06; Item* FUN_009f3a40(void*); };
struct Allocator { Item* FUN_008f6d30(int,int); };
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
// pdb: hkpMousePickingViewer::create | hkpMousePickingViewer.obj | fnv360_0822_debug, objrun, medium
// pdb params: contexts
void* __cdecl FUN_009f3b20(void* arg) {
 Allocator* allocator=(Allocator*)TlsGetValue(DAT_010f3170);
 Item* item=allocator->FUN_008f6d30(0x34,0x35);
 item->unk04=0x34;
 Item* result=item->FUN_009f3a40(arg);
 return result ? (char*)result+8 : 0;
}
}
}   // namespace f3m_009f3b20

// @f3 0x009e3370 (community match, verified in this file)
namespace f3m_009e3370 {
struct V4_009e3370 { float x, y, z, w; };
struct O_009e3370 { char pad[0x20]; V4_009e3370 v; void FUN_009e3370(const V4_009e3370* s); };
void O_009e3370::FUN_009e3370(const V4_009e3370* s) { v.x = s->x; v.y = s->y; v.z = s->z; v.w = s->w; }
}   // namespace f3m_009e3370

// @f3 0x009e8000 (community match, verified in this file)
namespace f3m_009e8000 {
struct V4_009e8000 { float x, y, z, w; };
struct O_009e8000 { char pad[0x30]; V4_009e8000 v; void FUN_009e8000(V4_009e8000* out); };
// pdb: hkpConvexVerticesShape::getAabbImpl | hkpConvexVerticesShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: localToWorld, tolerance, out
void O_009e8000::FUN_009e8000(V4_009e8000* out) { out->x = v.x; out->y = v.y; out->z = v.z; out->w = v.w; }
}   // namespace f3m_009e8000

// @f3 0x009e10c0 (community match, verified in this file)
namespace f3m_009e10c0 {
namespace f3m_009e10c0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct P { char pad[4]; unsigned short w; }; struct T { void FUN_008f6d90(P* p, unsigned int a, unsigned int b); }; }
// pdb: bhkConstraintChain::LoadBinary | bhkConstraintChain.obj | fnv360_0822_debug, objrun, low, conflict (skyrim: hkArrayBase<short>::_insertAt)
// pdb params: arStream
void __cdecl FUN_009e10c0(f3m_009e10c0::P* p) { f3m_009e10c0::T* t = (f3m_009e10c0::T*)f3m_009e10c0::DAT_00d9b080(f3m_009e10c0::DAT_010f3170); t->FUN_008f6d90(p, p->w, 0x2c); }
}   // namespace f3m_009e10c0

// @f3 0x009e2980 (community match, verified in this file)
extern char DAT_00e805cc;
namespace f3m_009e2980 {
struct Tgt_009e2980 {
    virtual void t0(); virtual void v1(const char* s, int a, void* b); virtual void t2(); virtual void t3(); virtual void t4(); virtual void t5();
    virtual int v6();
};
struct O_009e2980 { int FUN_009e2980(Tgt_009e2980* t); };
int O_009e2980::FUN_009e2980(Tgt_009e2980* t) {
    t->v1(&DAT_00e805cc, 1, this);
    return t->v6();
}
}   // namespace f3m_009e2980

// @f3 0x009e5260 (community match, verified in this file)
extern char DAT_00e806a0;
namespace f3m_009e5260 {
struct Tgt_009e5260 {
    virtual void t0(); virtual void v1(const char* s, int a, void* b); virtual void t2(); virtual void t3(); virtual void t4(); virtual void t5();
    virtual int v6();
};
struct O_009e5260 { int FUN_009e5260(Tgt_009e5260* t); };
// pdb: hkpCylinderShape::calcContentStatistics | hkpCylinderShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: collector, cls
int O_009e5260::FUN_009e5260(Tgt_009e5260* t) {
    t->v1(&DAT_00e806a0, 1, this);
    return t->v6();
}
}   // namespace f3m_009e5260

// @f3 0x009edb90 (community match, verified in this file)
namespace f3m_009edb90 {
namespace task1114 {
struct Target {
virtual void v00();
virtual void v04();
virtual void v08();
virtual void v0c();
virtual void v10();
virtual void v14();
virtual void v18();
virtual void v1c();
virtual void v20();
virtual void v24();
virtual void v28();
virtual void Run(void*);};
struct Holder {Target* target;};
struct Object {
int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
int unk40;
Holder* holder;void FUN_009edb90(void*);};
// pdb: hkpConvexListShape::getFirstVertex | hkpConvexListShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: v
void Object::FUN_009edb90(void* a){holder->target->Run(a);}
}
}   // namespace f3m_009edb90

// @f3 0x009e4c20 (community match, verified in this file)
namespace n9e4c20 {
extern unsigned long DAT_010f3170;
struct Alloc { virtual void* AlignedAlloc(int align, int size, int tag); };
extern Alloc* (__stdcall* const FUN_00d9b080)(unsigned long);
void __cdecl FUN_009234e0(void* dst, const void* src, int bytes);
struct Elem { int v[16]; };
}
struct C9e4c20 {
    char p00[0x58];
    n9e4c20::Elem* data;
    int count;
    void FUN_009e4640();
    n9e4c20::Elem* hkpExtendedMeshShape_expandOneShapesSubparts();
};
// pdb: hkpExtendedMeshShape::expandOneShapesSubparts | hkpExtendedMeshShape.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_seq) + skyrim(call_gap), high
n9e4c20::Elem* C9e4c20::hkpExtendedMeshShape_expandOneShapesSubparts()
{
    using namespace n9e4c20;
    int n = count + 1;
    Elem* p = (Elem*)n9e4c20::FUN_00d9b080(n9e4c20::DAT_010f3170)->AlignedAlloc(0x40, n * sizeof(Elem), 0x25);
    FUN_009234e0(p, data, count * sizeof(Elem));
    FUN_009e4640();
    data = p;
    count++;
    return &data[count - 1];
}

// @f3 0x009f3280 (community match, verified in this file)
namespace f3m_009f3280 {
extern void __cdecl FUN_00901f10(void* arr, int elemSize);

struct FUN_009f3280_Array {
    int* data;
    int count;
    unsigned int capacity;
};

struct FUN_009f3280_Obj {
    int unk00;
    int unk04;
    FUN_009f3280_Array array;

    void FUN_009f3280(int value);
};

void FUN_009f3280_Obj::FUN_009f3280(int value)
{
    FUN_009f3280_Array* a = &array;

    if (a->count == (int)(a->capacity & 0x3fffffffu))
        FUN_00901f10(a, 4);

    a->data[a->count] = value;
    ++a->count;
}
}   // namespace f3m_009f3280

// @f3 0x009e22b0 (community match, verified in this file)
namespace f3m_009e22b0 {
namespace f3m_009e22b0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009e22b0 { char pad[4]; unsigned short w; void FUN_009e1d40(); O009e22b0* FUN_009e22b0(unsigned int flags); };
// pdb: hkpMoppBvTreeShape::`scalar deleting destructor' | hkpMoppBvTreeShape.obj | fnv360_0822_retail, vtable_prefix, high
O009e22b0* O009e22b0::FUN_009e22b0(unsigned int flags) { FUN_009e1d40(); if (flags & 1) { f3m_009e22b0::T* t = (f3m_009e22b0::T*)f3m_009e22b0::DAT_00d9b080(f3m_009e22b0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_009e22b0

// @f3 0x009e8ab0 (community match, verified in this file)
namespace f3m_009e8ab0 {
namespace f3m_009e8ab0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009e8ab0 { char pad[4]; unsigned short w; void FUN_009e8a10(); O009e8ab0* FUN_009e8ab0(unsigned int flags); };
O009e8ab0* O009e8ab0::FUN_009e8ab0(unsigned int flags) { FUN_009e8a10(); if (flags & 1) { f3m_009e8ab0::T* t = (f3m_009e8ab0::T*)f3m_009e8ab0::DAT_00d9b080(f3m_009e8ab0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_009e8ab0

// @f3 0x009ee4d0 (community match, verified in this file)
namespace f3m_009ee4d0 {
namespace f3m_009ee4d0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009ee4d0 { char pad[4]; unsigned short w; void FUN_009ee430(); O009ee4d0* FUN_009ee4d0(unsigned int flags); };
// pdb: hkpConvexListShape::`scalar deleting destructor' | hkpConvexListShape.obj | fnv360_0822_retail, vtable_prefix, high
O009ee4d0* O009ee4d0::FUN_009ee4d0(unsigned int flags) { FUN_009ee430(); if (flags & 1) { f3m_009ee4d0::T* t = (f3m_009ee4d0::T*)f3m_009ee4d0::DAT_00d9b080(f3m_009ee4d0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_009ee4d0

// @f3 0x009eeb80 (community match, verified in this file)
namespace f3m_009eeb80 {
namespace f3m_009eeb80 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009eeb80 { char pad[4]; unsigned short w; void FUN_009ee850(); O009eeb80* FUN_009eeb80(unsigned int flags); };
// pdb: hkOArchive::`scalar deleting destructor' | hkOArchive.obj | fnv360_0822_retail, vtable, high
O009eeb80* O009eeb80::FUN_009eeb80(unsigned int flags) { FUN_009ee850(); if (flags & 1) { f3m_009eeb80::T* t = (f3m_009eeb80::T*)f3m_009eeb80::DAT_00d9b080(f3m_009eeb80::DAT_010f3170); t->FUN_008f6d90(this, w, 0x1a); } return this; }
}   // namespace f3m_009eeb80

// @f3 0x009ef970 (community match, verified in this file)
namespace f3m_009ef970 {
namespace f3m_009ef970 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009ef970 { char pad[4]; unsigned short w; void FUN_009ef860(); O009ef970* FUN_009ef970(unsigned int flags); };
// pdb: hkpWorldMemoryViewer::`scalar deleting destructor' | hkpWorldMemoryViewer.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: `anonymous namespace'::NavmeshMovementPostPhysicsListener::NavmeshMovementPostPhysicsListener)
O009ef970* O009ef970::FUN_009ef970(unsigned int flags) { FUN_009ef860(); if (flags & 1) { f3m_009ef970::T* t = (f3m_009ef970::T*)f3m_009ef970::DAT_00d9b080(f3m_009ef970::DAT_010f3170); t->FUN_008f6d90(this, w, 0x35); } return this; }
}   // namespace f3m_009ef970

// @f3 0x009f0660 (community match, verified in this file)
namespace f3m_009f0660 {
namespace f3m_009f0660 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009f0660 { char pad[4]; unsigned short w; void FUN_009efc60(); O009f0660* FUN_009f0660(unsigned int flags); };
// pdb: hkpVehicleViewer::`scalar deleting destructor' | hkpVehicleViewer.obj | fnv360_0822_retail, vtable, medium
O009f0660* O009f0660::FUN_009f0660(unsigned int flags) { FUN_009efc60(); if (flags & 1) { f3m_009f0660::T* t = (f3m_009f0660::T*)f3m_009f0660::DAT_00d9b080(f3m_009f0660::DAT_010f3170); t->FUN_008f6d90(this, w, 0x35); } return this; }
}   // namespace f3m_009f0660

// @f3 0x009f14b0 (community match, verified in this file)
namespace f3m_009f14b0 {
namespace f3m_009f14b0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009f14b0 { char pad[4]; unsigned short w; void FUN_009f13b0(); O009f14b0* FUN_009f14b0(unsigned int flags); };
// pdb: hkpSweptTransformDisplayViewer::`scalar deleting destructor' | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, vtable, medium
O009f14b0* O009f14b0::FUN_009f14b0(unsigned int flags) { FUN_009f13b0(); if (flags & 1) { f3m_009f14b0::T* t = (f3m_009f14b0::T*)f3m_009f14b0::DAT_00d9b080(f3m_009f14b0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x35); } return this; }
}   // namespace f3m_009f14b0

// @f3 0x009f3a10 (community match, verified in this file)
namespace f3m_009f3a10 {
namespace f3m_009f3a10 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009f3a10 { char pad[4]; unsigned short w; void FUN_009f3350(); O009f3a10* FUN_009f3a10(unsigned int flags); };
// pdb: hkpPhantomDisplayViewer::`scalar deleting destructor' | hkpPhantomDisplayViewer.obj | fnv360_0822_retail, vtable, medium
O009f3a10* O009f3a10::FUN_009f3a10(unsigned int flags) { FUN_009f3350(); if (flags & 1) { f3m_009f3a10::T* t = (f3m_009f3a10::T*)f3m_009f3a10::DAT_00d9b080(f3m_009f3a10::DAT_010f3170); t->FUN_008f6d90(this, w, 0x35); } return this; }
}   // namespace f3m_009f3a10

// @f3 0x009f3dd0 (community match, verified in this file)
namespace f3m_009f3dd0 {
namespace f3m_009f3dd0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009f3dd0 { char pad[4]; unsigned short w; void FUN_009f3ba0(); O009f3dd0* FUN_009f3dd0(unsigned int flags); };
O009f3dd0* O009f3dd0::FUN_009f3dd0(unsigned int flags) { FUN_009f3ba0(); if (flags & 1) { f3m_009f3dd0::T* t = (f3m_009f3dd0::T*)f3m_009f3dd0::DAT_00d9b080(f3m_009f3dd0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x35); } return this; }
}   // namespace f3m_009f3dd0

// @f3 0x009e5a70 (community match, verified in this file)
namespace f3m_009e5a70 {
namespace n9e5a70 {
struct Vec4 {
    float x, y, z, w;
    void setAdd(const Vec4& p, const Vec4& q) { x = p.x + q.x; y = p.y + q.y; z = p.z + q.z; w = p.w + q.w; }
};
}
struct C9e5a70 {
    char pad[0x20];
    n9e5a70::Vec4 a;
    n9e5a70::Vec4 b;
    void hkpCylinderShape_getCentreImpl(n9e5a70::Vec4* out);
};
// pdb: hkpCylinderShape::getCentreImpl | hkpCylinderShape.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void C9e5a70::hkpCylinderShape_getCentreImpl(n9e5a70::Vec4* out)
{
    out->setAdd(a, b);
    out->x *= 0.5;
    out->y *= 0.5;
    out->z *= 0.5;
    out->w *= 0.5;
}
}   // namespace f3m_009e5a70

// @f3 0x009ef440 (community match, verified in this file)
namespace f3m_009ef440 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
struct Pool_9ef440 { void* FUN_008f6d30(int size, int kind); };
struct Hdr_9ef440 { int unk00; unsigned short unk04; };
struct First_9ef440 { int unk00; unsigned short unk04; unsigned short unk06; };
struct Second_9ef440 { int unk00; };
struct Obj_9ef440 : First_9ef440, Second_9ef440 {
    Obj_9ef440(int a, int b) throw();
    static void* operator new(unsigned int size) {
        Pool_9ef440* pool = (Pool_9ef440*)DAT_00d9b080(DAT_010f3170);
        Hdr_9ef440* p = (Hdr_9ef440*)pool->FUN_008f6d30(0x2c, 0x35);
        p->unk04 = 0x2c;
        return p;
    }
    static void operator delete(void* p);
};
// pdb: hkpWorldSnapshotViewer::createPC | hkpWorldSnapshotViewer.obj | fnv360_0822_debug, objrun, medium
// pdb params: contexts
Second_9ef440* __cdecl FUN_009ef440(int a) {
    return new Obj_9ef440(a, 1);
}
}   // namespace f3m_009ef440

// @f3 0x009e45a0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009e45a0 {

class FUN_009e45a0_Ref {
public:
    virtual void vf00(int value);
    short unk04;
    short unk06;
};

struct FUN_009e45a0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_009e45a0_Ref** unk10;
    int unk14;

    void FUN_009e45a0();
};

namespace f3m_009ee430_inner {
struct Allocator {
    void FUN_008f6d90(void* p, int bytes, int cls);
};
}

extern "C" __declspec(dllimport) f3m_009ee430_inner::Allocator* __stdcall TlsGetValue(unsigned int);

void FUN_009e45a0_Class::FUN_009e45a0() {
    FUN_009e45a0_Class* self = this;
    int i = 0;

    while (i < self->unk14) {
        FUN_009e45a0_Ref* ref = self->unk10[i];
        if (ref->unk04 != 0) {
            ref->unk06--;
            if (ref->unk06 == 0) {
                ref->vf00(1);
            }
        }
        i++;
    }

    int count = self->unk14;
    void** arr = reinterpret_cast<void**>(self->unk10);

    f3m_009ee430_inner::Allocator* alloc = TlsGetValue(DAT_010f3170);
    alloc->FUN_008f6d90(arr, count * 4, 0x27);
}
}   // namespace f3m_009e45a0

// @f3 0x009e2360 (community match, verified in this file)
namespace f3m_009e2360 {
namespace f3m_009e2360 {

struct Element8 {
    int unk00;
    int unk04;
};

struct Array8 {
    Element8* data;
    int count;
    unsigned int capacity;

    void FUN_009e2360(int index, const Element8* src, int num);
};

void Array8::FUN_009e2360(int index, const Element8* src, int num)
{
    int newCount = count + num;
    int n = count - index;
    int cap = capacity & 0x3fffffff;
    if (cap < newCount)
    {
        int newCap = cap * 2;
        if (newCount >= newCap)
            newCap = newCount;
        f3m_009f26a0::FUN_00901e90(this, newCap, 8);
    }
    {
        Element8* s = &data[index];
        Element8* d = &data[index + num];
        for (int i = n - 1; i >= 0; --i)
            d[i] = s[i];
    }
    {
        Element8* q = data + index;
        for (int i = num - 1; i >= 0; --i)
            q[i] = src[i];
    }
    count = newCount;
}
}
}   // namespace f3m_009e2360

// @f3 0x009f2ef0 (community match, verified in this file)
namespace f3m_009f2ef0 {
namespace f3m_009f2ef0 {

struct ArgOwner {
    void Attach(void* p);
    void Detach(void* p);
};

struct ItemArray9f2ef0 {
    void* data;
    int count;
    unsigned int capacity;
};

struct Entry9f2ef0 {
    ArgOwner* owner;
    ItemArray9f2ef0 values;
    void FUN_009f5b00(int flag);
};

struct OwnerObject {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    Entry9f2ef0** table;
    int count;
    void FUN_009f2ef0(int index);
};

}

using namespace f3m_009f2ef0;

// pdb: hkpShapeDisplayViewer::removeWorld | hkpShapeDisplayViewer.obj | fnv360_0822_retail, caller, medium
// pdb params: i
void OwnerObject::FUN_009f2ef0(int index)
{
    table[index]->owner->Attach(this ? (void*)((char*)this + 0x28) : 0);
    table[index]->owner->Detach((void*)((char*)this + 0x2c));
    ((f3m_009f26a0::Obj26a0*)this)->FUN_009f26a0(index);
    Entry9f2ef0* entry = table[index];
    if (entry)
        entry->FUN_009f5b00(1);
    table[index] = table[--count];
}
}   // namespace f3m_009f2ef0

// @f3 0x009ec800 (community match, verified in this file)
namespace f3m_009ec800 {
namespace f3m_009ec800 {

struct Elem8_9ec800 { int x; int y; };

struct Array8_9ec800 {
    Elem8_9ec800* m_data;
    int m_size;
    unsigned int m_capacityAndFlags;
};

struct Local_9ec800 {
    int m_unk00;
    Array8_9ec800 m_array;
    Elem8_9ec800 m_inline[128];
    void FUN_00a60840();
};

void __cdecl FUN_009eb790(void* src, Local_9ec800* self, void* a1, void* a2);
void __cdecl FUN_00a5d870(Local_9ec800* self, void* a1);

// pdb: hkGeometryUtility::createConvexGeometry | hkGeometryUtility.obj | fnv360_0822_retail, call_gap, low
// pdb params: stridedVertsIn, geometryOut
void FUN_009ec800(void* src, void* a1, void* a2)
{
    Local_9ec800 local;
    local.FUN_00a60840();
    FUN_009eb790(src, &local, a1, a2);
    FUN_00a5d870(&local, a1);

    Array8_9ec800* arr = &local.m_array;
    if (!(arr->m_capacityAndFlags & 0x80000000)) {
        int cap = arr->m_capacityAndFlags & 0x3fffffff;
        f3m_009ee430::f3m_009ee430::Allocator* alloc = f3m_009ee430::TlsGetValue(DAT_010f3170);
        alloc->FUN_008f6d90(arr->m_data, cap * sizeof(Elem8_9ec800), 0x17);
    }
}
}
}   // namespace f3m_009ec800

// @f3 0x009e2850 (community match, verified in this file)
extern float DAT_010231a8;
extern float DAT_0101e2bc;
extern float DAT_010181bc;
namespace f3m_009e2850 {

class Init_9e2850 {
public:
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    volatile bool unk1c;
    volatile bool unk1d;
    volatile bool unk1e;
    volatile bool unk1f;
    volatile bool unk20;
    Init_9e2850* FUN_009e2850();
};

// pdb: hkpMoppCompilerInput::hkpMoppCompilerInput | hkpMoppCompilerInput.obj | tesv_win, objrun_open, low
Init_9e2850* Init_9e2850::FUN_009e2850()
{
    unk18 = 0.3f;
    unk10 = DAT_010231a8;
    unk14 = DAT_0101e2bc;
    unk00 = 0.05f;
    unk04 = 0.05f;
    unk08 = 0.05f;
    unk0c = 0.0f;
    unk1c = true;
    unk1d = true;
    unk1f = true;
    unk20 = false;
    unk1e = false;
    return this;
}
}   // namespace f3m_009e2850

// @f3 0x009e1260 (community match, verified in this file)
namespace f3m_009e1260 {
namespace f3m_009e1260 {

class Ref_9e1260 {
public:
    virtual ~Ref_9e1260();
    unsigned short m_memSizeAndFlags;   // +4
    short m_referenceCount;             // +6
};

struct Allocator_9e1260 {
    void* FUN_008f6d30(int bytes, int cls);
};

struct Src_9e1260 {
    int unk00;
    Ref_9e1260* m_ref;      // +4
    int unk08;
    int unk0c;
    int unk10;
    void** m_data;          // +0x14
    int m_count;            // +0x18
};

class Holder_9e1260 {
public:
    virtual ~Holder_9e1260();
    unsigned short m_memSizeAndFlags;   // +4
    short m_referenceCount;             // +6
    int unk08;
    Ref_9e1260* m_ref;                  // +0x0c
    int unk10;
    void* unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;

    Holder_9e1260(Ref_9e1260* r);
    void FUN_00a50b70(void* item);

    void removeReference()
    {
        if (m_memSizeAndFlags != 0)
        {
            --m_referenceCount;
            if (m_referenceCount == 0)
                delete this;
        }
    }

    static void* operator new(unsigned int size)
    {
        Allocator_9e1260* a = (Allocator_9e1260*)f3m_009ee430::TlsGetValue(DAT_010f3170);
        Ref_9e1260* p = (Ref_9e1260*)a->FUN_008f6d30(size, 0x2c);
        p->m_memSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
};

class Target_9e1260 {
public:
    virtual void vf00(void* p);
    virtual void vf01(void* p);
    virtual void vf02(void* p);
    virtual void vf03(void* p);
    virtual void vf04(void* p);
    virtual void vf05(void* p);
    virtual void vf06(void* p);
    virtual void vf07(void* p);
    virtual void vf08(void* p);
    virtual void vf09(void* p);
    virtual void vf10(void* p);
    virtual void vf11(void* p);
    virtual void vf12(void* p);
    virtual void vf13(void* p);
    virtual void vf14(void* p);
    virtual void vf15(void* p);
    virtual void vf16(void* p);
    virtual void vf17(void* p);
    virtual void vf18(void* p);
    virtual void vf19(void* p);
    virtual void vf20(void* p);
    virtual void vf21(void* p);
    virtual void vf22(void* p);
    virtual void vf23(void* p);
    virtual void vf24(void* p);
    virtual void vf25(void* p);
    virtual void vf26(void* p);
    virtual void vf27(void* p);
    virtual void vf28(void* p);
    virtual void vf29(void* p);
    virtual void vf30(void* p);
    virtual void vf31(void* p);
    virtual void vf32(void* p);
    virtual void vf33(void* p);
    virtual void vf34(void* p);
    virtual void vf35(void* p);
    virtual void vf36(void* p);
    virtual void vf37(void* p);
    virtual void vf38(void* p);
    virtual void vf39(void* p);
    virtual void vf40(void* p);
    virtual void vf41(void* p);
    virtual void vf42(void* p);
    virtual void vf43(void* p);
    virtual void vf44(void* p);
    virtual void vf45(void* p);
    virtual void vf46(void* p);
    virtual void vf47(void* p);
    void FUN_009e1260(void* arg);
};

// pdb: bhkConstraintChain::Init | bhkConstraintChain.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arInfo
void Target_9e1260::FUN_009e1260(void* arg)
{
    Src_9e1260* p = arg ? (Src_9e1260*)((char*)arg - 4) : 0;
    Ref_9e1260* ref = p->m_ref;
    Holder_9e1260* h = new Holder_9e1260(ref);
    for (int i = 0; i < p->m_count; i++)
        h->FUN_00a50b70(p->m_data[i]);
    vf35(h);
    h->removeReference();
    vf47(arg);
}

}
}   // namespace f3m_009e1260

// @f3 0x009f5590 (community match, verified in this file)
namespace f3m_009f5590 {
// FUN_009f5590: thiscall, one stack param (ctx). Collects nodes, filters/logs, pushes ctx+0x13 into elem list, notifies sink, frees temp array.

struct PtrArr {
    void** data;
    int count;
    unsigned int cap;   // bit31 set = no owned buffer
};

struct Elem {
    virtual ~Elem() {}
    PtrArr list;        // +4 data, +8 count, +0xc cap
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50;          // type code, 6 = candidate
};

struct Frame {
    PtrArr arr;
    Elem* volatile elem;
};

struct Sink {
    virtual void S0();
    virtual void S1(void* a, void* b, void* c, void* d, int e);
    virtual void S2();
    virtual void S3(void* a, void* b, void* c);
};

struct Logger {
    virtual void L0();
    virtual void L1();
    virtual void L2();
    virtual void Log(int a, int b, void* buf, const char* file, int line);
};

struct Tmp20 { int unk00; Tmp20(); };
struct Tmp38 { int unk00; int unk04; int unk08; void Assign(Tmp20* src); void Collect(void* node, PtrArr* out); };
struct Tmp2c { int unk00; int unk04; int unk08; void Format(void* buf, int n); void Add(const char* s); void Dtor(); };
struct Pool28 { int FUN_009f5410(int v); };
struct Alloc { void FUN_008f6d90(void* p, int size, int tag); };
extern "C" void* __cdecl FUN_00901f10(PtrArr* arr, int n);

extern Logger* DAT_010f3364;
extern void* DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(void*);
extern void* DAT_01169828;
extern void* DAT_01169830;
extern void* DAT_0116982c;

struct FUN_009f5590_cls {
    int unk00;
    void FUN_009f5590(char* ctx);
};

// pdb: hkpConvexRadiusViewer::entityAddedCallback | hkpConvexRadiusViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: entity
void FUN_009f5590_cls::FUN_009f5590(char* ctx)
{
    if (*(int*)(ctx + 0x10) == 0)
        return;
    int idx = ((Pool28*)((char*)this - 0x28))->FUN_009f5410(*(int*)(ctx + 8));
    if (idx < 0)
        return;
    Frame fr;
    PtrArr& arr = fr.arr;
    fr.elem = ((Elem**)*(char**)((char*)this + 8))[idx];
    arr.data = 0;
    arr.count = 0;
    arr.cap = 0x80000000u;
    Tmp20 a20;
    Tmp38 c38;
    c38.Assign(&a20);
    c38.Collect(*(void**)(ctx + 0x10), &arr);
    for (int i = arr.count - 1; i >= 0; --i) {
        Elem* e = (Elem*)arr.data[i];
        if (e->unk50 == 6 && e->list.count == 0) {
            struct { unsigned int unkpad; unsigned int buf[128]; } bb;
            Tmp2c o2c;
            o2c.Format(bb.buf, 0x200);
            o2c.Add("Unable to build display geometry from hkpShape geometry data");
            DAT_010f3364->Log(0, -1, bb.buf, ".\\VisualDebugger\\Viewer\\Collide\\hkpConvexRadiusViewer.cpp", 0xa6);
            o2c.Dtor();
            arr.count = arr.count - 1;
            arr.data[i] = arr.data[arr.count];
        }
    }
    if (arr.count > 0) {
        PtrArr* lst = &fr.elem->list;
        void* node = ctx + 0x13;
        if (lst->count == (int)(lst->cap & 0x3fffffff)) {
            FUN_00901f10(lst, 4);
        }
        lst->data[lst->count] = node;
        lst->count++;
        (*(Sink**)((char*)this - 0x10))->S1(&arr, ctx + 0xe0, ctx + 0x13, DAT_01169828, 0);
        if (*(unsigned char*)(ctx + 0xd8) == 7)
            (*(Sink**)((char*)this - 0x10))->S3(DAT_01169830, ctx + 0x13, DAT_01169828);
        else
            (*(Sink**)((char*)this - 0x10))->S3(DAT_0116982c, ctx + 0x13, DAT_01169828);
    }
    for (int j = 0; j < arr.count; ++j) {
        Elem* p = (Elem*)arr.data[j];
        if (p != 0)
            delete p;
    }
    if ((arr.cap & 0x80000000u) == 0) {
        unsigned int n = arr.cap & 0x3fffffffu;
        Alloc* al = (Alloc*)DAT_00d9b080(DAT_010f3170);
        al->FUN_008f6d90(arr.data, n * 4, 0x17);
    }
}
}   // namespace f3m_009f5590

// @f3 0x009ef770 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009ef770 {
namespace n9ef770 {
struct Alloc { void FUN_008f6d90(void* p, int size, int tag); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned int);
void FUN_009ef4c0_body();
struct FUN_009ef770 {
    unsigned short memSize;
    short refCount;
    virtual ~FUN_009ef770();
    // pdb: hkpWorldSnapshotViewer::`scalar deleting destructor' | hkpWorldSnapshotViewer.obj | fnv360_0822_debug, vtable, medium
    static void operator delete(void* p)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        al->FUN_008f6d90(p, ((FUN_009ef770*)p)->memSize, 0x35);
    }
};
__declspec(noinline) FUN_009ef770::~FUN_009ef770() { FUN_009ef4c0_body(); }
}
}   // namespace f3m_009ef770

// @f3 0x009e16b0 (community match, verified in this file)
namespace f3m_009e16b0 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
extern "C" __declspec(dllimport) Heap* __stdcall TlsGetValue(unsigned long) throw();
extern unsigned long DAT_010f3170;
struct Elem { int v[8]; };
struct InlineArray {
    Elem* data;
    int size;
    unsigned int cap;
    __forceinline void Release() {
        if ((cap & 0x80000000u) == 0) {
            unsigned int n = cap & 0x3fffffff;
            Heap* h = TlsGetValue(DAT_010f3170);
            h->FUN_008f6d90(data, n << 5, 0x17);
        }
    }
};
struct Base {
    int unk4, unk8, unkC, unk10, unk14;
    virtual ~Base() {}
};
struct Holder : Base {
    InlineArray arr;
    virtual ~Holder();
};
// pdb: hkpBallSocketChainData::~hkpBallSocketChainData | hkpBallSocketChainData.obj | fnv360_0822_retail, call_seq, high
Holder::~Holder() {
    arr.Release();
}
}

// @f3 0x009eeb30 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Build344{
extern unsigned long DAT_010f3170;extern int DAT_00e808d0;
struct Object344{void*vtable;unsigned short memory,refs;unsigned int unk08,unk0c,unk10;Object344* FUN_00943bb0(void*,int);};
struct Heap344{void* FUN_008f6d30(unsigned int,int);};
struct Owner344{void*vtable;unsigned short memory,refs;Object344*object;unsigned char flag;Owner344(void*,unsigned char);};
// pdb: hkOArchive::operator delete | hkOArchive.obj | fnv360_0822_debug, objrun, low, conflict (skyrim: hkOArchive::hkOArchive)
// pdb params: p
Owner344::Owner344(void*input,unsigned char option){refs=1;vtable=&DAT_00e808d0;flag=option;Heap344*heap=(Heap344*)TlsGetValue(DAT_010f3170);Object344*created=(Object344*)heap->FUN_008f6d30(sizeof(Object344),26);created->memory=sizeof(Object344);object=created->FUN_00943bb0(input,1);}
}

// @f3 0x009f4000 (community match, verified in this file)
namespace f3m_009f4000 {
namespace task1294 {
template <class T> struct S_00d69fc0_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
                m_data[index] = m_data[m_iElementCount];
    }
};

struct S_00d69fc0_Item;

struct S_00d69fc0
{
    int unk00;
    int unk04;
    S_00d69fc0_Array<S_00d69fc0_Item*> m_items;
    void FUN_009f4000(S_00d69fc0_Item* item);
};

// Finds item in m_items and, if present, removes it by index.
// @fnv 0x00d69fc0
// pdb: hkArrayBase<hkDisplayBox>::operator[] | hkpRigidBodyInertiaViewer.obj | fnv360_0822_debug, objrun_open, low
// pdb params: i
void S_00d69fc0::FUN_009f4000(S_00d69fc0_Item* item)
{
    int index = m_items.indexOf(item);
    if (index >= 0)
        m_items.removeAt(index);
}


}
}   // namespace f3m_009f4000

// @f3 0x009e78c0 (community match, verified in this file)
namespace f3m_009e78c0 {
struct Ref_9e78c0 { virtual void Del(int f); unsigned short w4; short w6; };
struct O_9e78c0 {
    char pad[0x5c]; Ref_9e78c0* p;
    void FUN_009e78c0(Ref_9e78c0* r);
};
// pdb: hkArrayBase<hkpConvexVerticesShape::FourVectors>::_clearAndDeallocate | hkpConvexVerticesShape.obj | fnv360_0822_debug, objrun_open, low
// pdb params: alloc
void O_9e78c0::FUN_009e78c0(Ref_9e78c0* r) {
    if (r && r->w4) r->w6++;
    Ref_9e78c0* old = p;
    if (old && old->w4) {
        --old->w6;
        if ((unsigned short)old->w6 == 0) old->Del(1);
    }
    p = r;
}
}   // namespace f3m_009e78c0

// @f3 0x009ee7a0 (community match, verified in this file)
namespace f3m_009ee7a0 {
struct RefB9ee7a0 { virtual ~RefB9ee7a0(); unsigned short size; short refs; };
struct OwnerB9ee7a0 {
 int unk00; int unk04; RefB9ee7a0* value;
 void FUN_009ee7a0(RefB9ee7a0* next);
};
// pdb: hkOArchive::setStreamWriter | hkOArchive.obj | fnv360_0822_retail, objrun, medium
// pdb params: newWriter
void OwnerB9ee7a0::FUN_009ee7a0(RefB9ee7a0* next) {
 if(next->size) ++next->refs;
 RefB9ee7a0* old=value;
 if(old->size && --old->refs == 0) delete old;
 value=next;
}

}   // namespace f3m_009ee7a0

// @f3 0x009eda70 (community match, verified in this file)
extern int FUN_00e36414;
namespace f3m_009eda70 {
namespace f3m_009eda70 {
struct Mem_da70 {
    void FUN_008f6d90(void* p, int bytes, int tag);
};
__declspec(dllimport) Mem_da70* __stdcall FUN_00d9b080(int);
class Ref_da70 {
public:
    virtual void DeleteThis(int flag);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                DeleteThis(1);
        }
    }
};
struct Cls_da70 {
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    char pad08[0xc];
    void* vtable2;
    Ref_da70* ref;
    Cls_da70* FUN_009eda70(unsigned int flags);
};
}
using namespace f3m_009eda70;

// pdb: hkpConvexTransformShape::`scalar deleting destructor' | hkpConvexTransformShape.obj | fnv360_0721_beta, objrun_open, low, conflict (skyrim: hkpTransformShape::`vector deleting destructor')
Cls_da70* Cls_da70::FUN_009eda70(unsigned int flags)
{
    vtable2 = &FUN_00e36414;
    ref->removeReference();
    vtable2 = &DAT_00e35eec;
    vtable = &DAT_00dcc494;
    if (flags & 1) {
        Mem_da70* mem = FUN_00d9b080(DAT_010f3170);
        mem->FUN_008f6d90(this, memSizeAndFlags, 0x27);
    }
    return this;
}
}   // namespace f3m_009eda70

// @f3 0x009e4610 (community match, verified in this file)
namespace workerA9e46 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall*DAT_00d9b080)(unsigned long);
struct Owner {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 void* data; int count; void FUN_009e4610();
};
void Owner::FUN_009e4610() {
 if(count>1) {
  void* p=data;
  void* allocator=DAT_00d9b080(DAT_010f3170);
  void** table=*(void***)allocator;
  typedef void (__thiscall* Release)(void*,void*);
  ((Release)table[1])(allocator,p);
 }
}
}

// @f3 0x009ef7a0 (community match, verified in this file)
extern void* DAT_00e80a44[];
extern void* DAT_00e80a24[];
extern void* DAT_00e80a14[];
namespace f3m_009ef7a0 {
namespace task1331 {
struct Subobject { void FUN_00a64b10(unsigned int); };
struct Object {
 void** table0; unsigned unk04;
 void** table8; unsigned unk0c,unk10,unk14,unk18,unk1c;
 void** table20; unsigned unk24;
 Subobject member28;
 void FUN_00a648d0(int);
 Object* FUN_009ef7a0(int);
};
// pdb: hkpWorldMemoryViewer::hkpWorldMemoryViewer | hkpWorldMemoryViewer.obj | fnv360_0822_retail, uconst, low
// pdb params: vtlbReg, contexts
Object* Object::FUN_009ef7a0(int value) {
 FUN_00a648d0(value);
 table0=DAT_00e80a44;
 table8=DAT_00e80a24;
 table20=DAT_00e80a14;
 member28.FUN_00a64b10(0x7a120);
 return this;
}
}
}   // namespace f3m_009ef7a0

// @f3 0x009e8a10 (community match, verified in this file)
extern int FUN_00e8074c;
namespace f3m_009e8a10 {
namespace f3m_009e8a10 {
struct Mem_8a10 {
    void FUN_008f6d90(void* p, int bytes, int tag);
};
__declspec(dllimport) Mem_8a10* __stdcall FUN_00d9b080(int);
class Ref_8a10 {
public:
    virtual void DeleteThis(int flag);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                DeleteThis(1);
        }
    }
};
template <int N> struct Elem_8a10 {
    char bytes[N];
};
template <class T> struct Array_8a10 {
    T* data;
    int size;
    int capacityAndFlags;
    void Free()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int cap = capacityAndFlags & 0x3fffffff;
            Mem_8a10* mem = FUN_00d9b080(DAT_010f3170);
            mem->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
struct Cls_8a10 {
    void* vtable;
    char pad04[0x3c];
    Array_8a10<Elem_8a10<0x30> > arr40;
    int unk4C;
    Array_8a10<Elem_8a10<0x10> > arr50;
    Ref_8a10* ref5C;
    void FUN_009e8a10();
};
}
using namespace f3m_009e8a10;

// pdb: hkpConvexVerticesShape::~hkpConvexVerticesShape | hkpConvexVerticesShape.obj | fnv360_0822_retail, call_seq, high
void Cls_8a10::FUN_009e8a10()
{
    vtable = &FUN_00e8074c;
    if (ref5C)
        ref5C->removeReference();
    arr50.Free();
    arr40.Free();
    vtable = &DAT_00dcc494;
}
}   // namespace f3m_009e8a10

// @f3 0x009e22e0 (community match, verified in this file)
namespace f3m_009e22e0 {
namespace f3m_009e22e0 {
class Ref_22e0 {
public:
    virtual void DeleteThis(int flag);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                DeleteThis(1);
        }
    }
};
class FUN_009e1d40 {
public:
    virtual ~FUN_009e1d40();
    int pad04[0xf];
};
class FUN_009e22e0 : public FUN_009e1d40 {
public:
    Ref_22e0* ref;
    virtual ~FUN_009e22e0();
};
}
using namespace f3m_009e22e0;

// pdb: hkScaledMoppBvTreeShape::~hkScaledMoppBvTreeShape | hkScaledMoppBvTreeShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_009e22e0::~FUN_009e22e0()
{
    if (ref)
        ref->removeReference();
}
}   // namespace f3m_009e22e0

// @f3 0x009ef0e0 (community match, verified in this file)
namespace f3m_009ef0e0 {
namespace f3m_009ef0e0 {
struct Mem_f0e0 {
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
__declspec(dllimport) Mem_f0e0* __stdcall FUN_00d9b080(int) throw();
class Obj_f0e0 {
public:
    virtual void DeleteThis(int flag) throw();
};
template <class T> struct Array_f0e0 {
    T* data;
    int size;
    int capacityAndFlags;
    ~Array_f0e0() throw()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int cap = capacityAndFlags & 0x3fffffff;
            Mem_f0e0* mem = FUN_00d9b080(DAT_010f3170);
            mem->FUN_008f6d90(data, cap * 4, 0x17);
        }
    }
};
struct FUN_00922cf0 {
    int unk00[3];
    ~FUN_00922cf0() throw();
};
class BaseObj_f0e0 {
public:
    virtual ~BaseObj_f0e0() throw() {}
};
class Ref_f0e0 : public BaseObj_f0e0 {
public:
    unsigned short memSizeAndFlags;
    short referenceCount;
    virtual ~Ref_f0e0() throw() {}
};
class B8_f0e0 {
public:
    virtual ~B8_f0e0() throw() {}
};
class BC_f0e0 {
public:
    virtual ~BC_f0e0() throw() {}
};
class FUN_009ef0e0 : public Ref_f0e0, public B8_f0e0, public BC_f0e0 {
public:
    int unk10;
    Obj_f0e0* obj14;
    Obj_f0e0* obj18;
    Obj_f0e0* obj1C;
    int unk20;
    Ref_f0e0 member24;
    FUN_00922cf0 member2C;
    Array_f0e0<Obj_f0e0*> children;
    Array_f0e0<int> ints;
    virtual ~FUN_009ef0e0() throw();
};
}
using namespace f3m_009ef0e0;

// pdb: hkServerProcessHandler::~hkServerProcessHandler | hkServerProcessHandler.obj | fnv360_0822_retail, call_seq, medium
FUN_009ef0e0::~FUN_009ef0e0() throw()
{
    for (int i = 0; i < children.size; i++) {
        Obj_f0e0* child = children.data[i];
        if (child)
            child->DeleteThis(1);
    }
    if (obj14)
        obj14->DeleteThis(1);
    if (obj18)
        obj18->DeleteThis(1);
    if (obj1C)
        obj1C->DeleteThis(1);
}
}   // namespace f3m_009ef0e0

// @f3 0x009eceb0 (community match, verified in this file)
namespace f3m_009eceb0 {
struct V4_9eceb0 { float x, y, z, w; void Set(const V4_9eceb0& o) { x = o.x; y = o.y; z = o.z; w = o.w; } };
struct O_9eceb0 { V4_9eceb0 v; O_9eceb0* FUN_009eceb0(const V4_9eceb0* p, float f); };
O_9eceb0* O_9eceb0::FUN_009eceb0(const V4_9eceb0* p, float f) { v.Set(*p); float* pw = &v.w; *pw = f; return this; }
}   // namespace f3m_009eceb0

// @f3 0x009f05b0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009f05b0 {

namespace f3m_9f05b0 {
struct Allocator {
    void* FUN_008f6d30(int size, int cls);
};
struct Node {
    void* m_vptr;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    void* FUN_009efc00(void* arg);
};
}
extern "C" __declspec(dllimport) f3m_9f05b0::Allocator* __stdcall TlsGetValue(unsigned int);

// pdb: hkpVehicleViewer::create | hkpVehicleViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: contexts
void* FUN_009f05b0(void* arg)
{
    f3m_9f05b0::Allocator* mem = TlsGetValue(DAT_010f3170);
    f3m_9f05b0::Node* n = (f3m_9f05b0::Node*)mem->FUN_008f6d30(0x3c, 0x35);
    n->m_memSizeAndFlags = 0x3c;
    void* r = n->FUN_009efc00(arg);
    return r ? (char*)r + 8 : 0;
}
}   // namespace f3m_009f05b0

// @f3 0x009f32b0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
extern const void* DAT_00e80d90[];
namespace f3m_009f32b0 {
namespace user_shape_identifier_header {
extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
struct Heap {void* FUN_008f6d30(unsigned int,int);};
struct Header {const void** vtable;unsigned short sizeAndFlags;short refCount;__forceinline void Init(){sizeAndFlags=20;refCount=1;vtable=DAT_00e80d90;}};struct Array {void* data;int count;unsigned int capacity;__forceinline void Init(){data=0;count=0;capacity=0x80000000u;}};struct Identifier {Header header;Array array;};
// pdb: hkpUserShapePhantomTypeIdentifiercreate | hkpPhantomDisplayViewer.obj | fnv360_0822_retail, uvref, medium
Identifier* __cdecl FUN_009f32b0(){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);Identifier* result=(Identifier*)heap->FUN_008f6d30(sizeof(Identifier),21);result->header.Init();result->array.Init();return result;}
}
}   // namespace f3m_009f32b0

// @f3 0x009e0e20 (community match, verified in this file)
extern char DAT_00dcc494[];
namespace f3m_009e0e20 {

struct Elem;

class Sub {
public:
    bool FUN_008d6140(int arg);
};

class Entry {
public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    Sub* unk310;
};

class Host {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual Entry* v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53(Sub* sub, int mode);
    unsigned int unk04;
    int unk08;

    bool FUN_009e0e20();
};

// pdb: bhkConstraintChain::SaveBinary | bhkConstraintChain.obj | fnv360_0822_debug, objrun, low
// pdb params: arStream
bool Host::FUN_009e0e20()
{
    bool result = false;
    Entry* entry = v38();
    Sub* sub = entry ? entry->unk310 : 0;
    _ReadWriteBarrier();
    if (sub) {
        result = sub->FUN_008d6140(unk08);
        v53(sub, 0);
    }
    return result;
}
}   // namespace f3m_009e0e20

// @f3 0x009e2ec0 (community match, verified in this file)
extern int DAT_00e805dc;
namespace f3m_009e2ec0 {

class FUN_009e2ec0
{
public:
    int m_vptr;
    short unk04;
    short unk06;
    int unk08;
    int unk0c;
    float v0[4];
    float v1[4];
    float v2[4];

    FUN_009e2ec0(const float* a, const float* b, const float* c);
};

// pdb: hkpPlaneShape::hkpPlaneShape | hkpPlaneShape.obj | fnv360_0822_retail, objrun, high
// pdb params: direction, center, halfExtents
FUN_009e2ec0::FUN_009e2ec0(const float* a, const float* b, const float* c)
{
    unk06 = 1;
    unk08 = 0;
    unk0c = 0x1b;
    m_vptr = (int)&DAT_00e805dc;

    v0[0] = a[0];
    v0[1] = a[1];
    v0[2] = a[2];
    v0[3] = a[3];

    float d = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    v0[3] = -d;

    v1[0] = b[0];
    v1[1] = b[1];
    v1[2] = b[2];
    v1[3] = b[3];

    v2[0] = c[0];
    v2[1] = c[1];
    v2[2] = c[2];
    v2[3] = c[3];
}
}   // namespace f3m_009e2ec0

// @f3 0x009e1e30 (community match, verified in this file)
namespace f3m_009e1e30 {
// pdb: hkMoppBvTreeShapeBase::hkMoppBvTreeShapeBase | hkpMoppBvTreeShape.obj | fnv360_0721_beta, objrun, high
// pdb params: type, code
namespace Construct417{extern int DAT_00e8053c;struct Source{void*vtable;unsigned short memory,refs;unsigned int unk08,unk0c;float x,y,z,w;unsigned int first,second;void AddRef(){if(memory)++refs;}};struct Owner{void*vtable;unsigned short memory,refs;unsigned int flags;void*context;Source*source;unsigned int first,second,unk1c;float x,y,z,w;Owner(void*,Source*);};Owner::Owner(void*a,Source*b):context(a){refs=1;flags=0;vtable=&DAT_00e8053c;source=b;b->AddRef();x=b->x;y=b->y;z=b->z;w=b->w;first=b->first;second=b->second;}}
}   // namespace f3m_009e1e30

// @f3 0x009ecef0 (community match, verified in this file)
namespace f3m_009ecef0 {
namespace convex_transform_serializer {
struct Serializer {virtual void v00();virtual void Begin(const char*,int,void*);virtual void v08();virtual void Child(const char*,int,void*);virtual void v10();virtual void v14();virtual void Finish();};
struct Owner {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14;void* child;void FUN_009ecef0(Serializer*);};
// pdb: hkpConvexTransformShape::calcContentStatistics | hkpConvexTransformShape.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: collector, cls
void Owner::FUN_009ecef0(Serializer* serializer){serializer->Begin("CvxTransform",1,this);serializer->Child("Child",1,child);serializer->Finish();}
}
}   // namespace f3m_009ecef0

// @f3 0x009ecf50 (community match, verified in this file)
extern char DAT_00e807e4[];
extern char DAT_00e36414[];
namespace f3m_009ecf50 {

struct Float16 {
    float v[16];
    Float16* FUN_008fda60(const float* src);
};

struct Foo9ecf50 {
    void* vptr;
    short unk04;
    short unk06;
    int unk08;
    int unk0c;
    float unk10;
    const char* unk14;
    void* unk18;
    int unk1c;
    Float16 unk20;

    Foo9ecf50* FUN_009ecf50(void* a2, int a3);
};

// pdb: hkpConvexTransformShape::hkpConvexTransformShape | hkpConvexTransformShape.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: childShape, transform, ref
Foo9ecf50* Foo9ecf50::FUN_009ecf50(void* a2, int a3)
{
    volatile float tmp = *(float*)((char*)a2 + 0x10);
    this->unk10 = tmp;
    this->unk06 = 1;
    this->unk08 = 0;
    this->unk0c = 13;
    this->vptr = DAT_00e807e4;
    this->unk14 = DAT_00e36414;
    this->unk18 = a2;
    if (*(short*)((char*)a2 + 4) != 0)
        ++*(short*)((char*)a2 + 6);
    this->unk20.FUN_008fda60((const float*)a3);
    return this;
}
}   // namespace f3m_009ecf50

// @f3 0x009e2250 (community match, verified in this file)
namespace f3m_009e2250 {
namespace f3m_009e2250 {
class FUN_009e2250_Obj {
public:
    int vptr;
    unsigned short unk04;
    short unk06;
    int unk08;
    int unk0c;
    f3m_009e1d40::FUN_009e1d40_Ref* unk10;

    FUN_009e2250_Obj* FUN_009e2250(unsigned char flag);
};

// pdb: hkMoppBvTreeShapeBase::`scalar deleting destructor' | hkpMoppBvTreeShape.obj | fnv360_0822_retail, vtable_prefix, high
FUN_009e2250_Obj* FUN_009e2250_Obj::FUN_009e2250(unsigned char flag)
{
    this->vptr = (int)&DAT_00e8053c;

    f3m_009e1d40::FUN_009e1d40_Ref* ref = this->unk10;
    if (ref->unk04 != 0) {
        if (--ref->unk06 == 0)
            ref->vf00(1);
    }

    this->vptr = (int)&DAT_00dcc494;

    if ((flag & 1) != 0) {
        f3m_009ee430::f3m_009ee430::Allocator* allocator =
            f3m_009ee430::TlsGetValue(DAT_010f3170);
        allocator->FUN_008f6d90(this, this->unk04, 0x27);
    }

    return this;
}
}
}   // namespace f3m_009e2250

// @f3 0x009f1130 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009f1130 {
namespace swept_viewer_factory {
extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
struct Heap {void* FUN_008f6d30(unsigned int,int);};
struct Viewer {void* vtable;unsigned short size,refs;unsigned int unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28,unk2C,unk30,unk34,unk38;Viewer* FUN_009f0ca0(void*);};
// pdb: hkpSweptTransformDisplayViewer::create | hkpSweptTransformDisplayViewer.obj | fnv360_0822_debug, objrun, medium
// pdb params: contexts
void* __cdecl FUN_009f1130(void* context){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);Viewer* viewer=(Viewer*)heap->FUN_008f6d30(sizeof(Viewer),53);viewer->size=sizeof(Viewer);Viewer* result=viewer->FUN_009f0ca0(context);return result?(void*)&result->unk08:0;}
}
}   // namespace f3m_009f1130

// @f3 0x009f2810 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009f2810 {
namespace viewer_factory_1928 {
extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
struct Heap {void* FUN_008f6d30(unsigned int,int);};
struct Viewer {void* vtable;unsigned short size,refs;unsigned int unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28,unk2C,unk30,unk34,unk38;unsigned int unk3C;unsigned int unk40;unsigned int unk44;unsigned int unk48;unsigned int unk4C;unsigned int unk50;unsigned int unk54;unsigned int unk58;unsigned int unk5C;unsigned int unk60;unsigned int unk64;unsigned int unk68;Viewer* FUN_009f2720(void*);};
// pdb: hkpShapeDisplayViewer::create | hkpShapeDisplayViewer.obj | fnv360_0822_debug, objrun, medium
// pdb params: contexts
void* __cdecl FUN_009f2810(void* context){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);Viewer* viewer=(Viewer*)heap->FUN_008f6d30(sizeof(Viewer),53);viewer->size=sizeof(Viewer);Viewer* result=viewer->FUN_009f2720(context);return result?(void*)&result->unk08:0;}
}
}   // namespace f3m_009f2810

// @f3 0x009f35e0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009f35e0 {
namespace viewer_factory_1929 {
extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
struct Heap {void* FUN_008f6d30(unsigned int,int);};
struct Viewer {void* vtable;unsigned short size,refs;unsigned int unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28,unk2C,unk30,unk34,unk38;Viewer* FUN_009f32f0(void*);};
// pdb: hkpPhantomDisplayViewer::create | hkpPhantomDisplayViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: contexts
void* __cdecl FUN_009f35e0(void* context){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);Viewer* viewer=(Viewer*)heap->FUN_008f6d30(sizeof(Viewer),53);viewer->size=sizeof(Viewer);Viewer* result=viewer->FUN_009f32f0(context);return result?(void*)&result->unk08:0;}
}
}   // namespace f3m_009f35e0

// @f3 0x009ef400 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009ef400 {
namespace snapshot_viewer_factory {
extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
struct Heap {void* FUN_008f6d30(unsigned int,int);};
struct Viewer {void* vtable;unsigned short size,refs;unsigned int unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28;Viewer* FUN_009ef3d0(void*,unsigned char);};
// pdb: hkpWorldSnapshotViewer::createNative | hkpWorldSnapshotViewer.obj | fnv360_0822_debug, objrun, medium
// pdb params: contexts
void* __cdecl FUN_009ef400(void* context){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);Viewer* viewer=(Viewer*)heap->FUN_008f6d30(sizeof(Viewer),53);viewer->size=sizeof(Viewer);Viewer* result=viewer->FUN_009ef3d0(context,0);return result?(void*)&result->unk08:0;}
}
}   // namespace f3m_009ef400

// @f3 0x009ef200 (community match, verified in this file)
namespace f3m_009ef200 {
    extern unsigned long DAT_010f3170;
    extern void* (__stdcall* DAT_00d9b080)(unsigned long);

    struct Allocator {
        void FUN_008f6d90(void* p, unsigned int bytes, unsigned int cls);
    };
}

extern void FUN_00dcc494();

struct O009ef200_Sub {
    void FUN_00922cf0();
};

struct O009ef200 {
    int vptr;
    unsigned short unk04;
    unsigned short unk06;

    O009ef200* FUN_009ef200(unsigned char flags);
};

// pdb: hkCommandRouter::`scalar deleting destructor' | hkServerProcessHandler.obj | fnv360_0822_retail, vtable, medium
O009ef200* O009ef200::FUN_009ef200(unsigned char flags) {
    ((O009ef200_Sub*)((char*)this + 8))->FUN_00922cf0();

    vptr = (int)&FUN_00dcc494;

    if (flags & 1) {
        f3m_009ef200::Allocator* allocator =
            (f3m_009ef200::Allocator*)f3m_009ef200::DAT_00d9b080(
                f3m_009ef200::DAT_010f3170);
        allocator->FUN_008f6d90(this, unk04, 0x35);
    }

    return this;
}

// @f3 0x009e2df0 (community match, verified in this file)
#include <intrin.h>
extern int FUN_00e805dc;
namespace f3m_009e2df0 {
namespace f3m_009e2df0 {
struct Vec4_2df0 {
    float x, y, z, w;
};
struct Aabb_2df0 {
    Vec4_2df0 min;
    Vec4_2df0 max;
};
class Shape_2df0 {
public:
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    int userData;
    int type;
    Shape_2df0(int t) : referenceCount(1), userData(0), type(t) {}
};
class FUN_009e2df0 : public Shape_2df0 {
public:
    Vec4_2df0 unk10;
    Vec4_2df0 center;
    Vec4_2df0 halfExtents;
    FUN_009e2df0(const Vec4_2df0& v, const Aabb_2df0& aabb);
};
}
using namespace f3m_009e2df0;

// pdb: hkpPlaneShape::hkpPlaneShape | hkpPlaneShape.obj | fnv360_0822_retail, objrun, high
// pdb params: plane, aabb
FUN_009e2df0::FUN_009e2df0(const Vec4_2df0& v, const Aabb_2df0& aabb) : Shape_2df0(0x1b)
{
    vtable = &FUN_00e805dc;
    _ReadWriteBarrier();
    unk10.x = v.x;
    unk10.y = v.y;
    unk10.z = v.z;
    unk10.w = v.w;
    halfExtents.x = aabb.max.x - aabb.min.x;
    halfExtents.y = aabb.max.y - aabb.min.y;
    halfExtents.z = aabb.max.z - aabb.min.z;
    halfExtents.w = aabb.max.w - aabb.min.w;
    halfExtents.x *= 0.5;
    halfExtents.y *= 0.5;
    halfExtents.z *= 0.5;
    halfExtents.w *= 0.5;
    center.x = aabb.max.x * 0.5 + aabb.min.x * 0.5;
    center.y = aabb.max.y * 0.5 + aabb.min.y * 0.5;
    center.z = aabb.max.z * 0.5 + aabb.min.z * 0.5;
    center.w = aabb.max.w * 0.5 + aabb.min.w * 0.5;
}
}   // namespace f3m_009e2df0

// @f3 0x009efc60 (community match, verified in this file)
extern int DAT_00e80ac4, DAT_00e80aa4, DAT_00e80a94, DAT_00e80a84, DAT_00e80a74, DAT_00e80a58, DAT_00e7bf00;
extern unsigned int DAT_010f3170;
namespace f3m_009efc60 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct Allocator9ef { void FUN_008f6d90(void* p, int bytes, int cls); };

struct Container9ef {
    int pad00[27];
    void** data;
    int size;
};

struct Notify9ef {
    int* table;
    Container9ef* owner;
    void FUN_009ef9c0(void* item);
};

struct Base9ef { void FUN_00a64860(); };

struct IfaceA9ef { int vptr; ~IfaceA9ef() { vptr = (int)&DAT_00e7bf00; } };
struct IfaceB9ef { int vptr; ~IfaceB9ef() { vptr = (int)&DAT_00e80a58; } };

struct Owner9ef {
    int vptr00;
    int unk04;
    int vptr08;
    int unk0c, unk10, unk14, unk18, unk1c;
    Notify9ef notify;
    IfaceA9ef ifaceA;
    IfaceB9ef ifaceB;
    void* data30;
    int unk34;
    unsigned int cap38;
    void FUN_009efc60();
};

// pdb: hkpVehicleViewer::~hkpVehicleViewer | hkpVehicleViewer.obj | fnv360_0822_retail, call_seq, medium
void Owner9ef::FUN_009efc60() {
    vptr00 = (int)&DAT_00e80ac4;
    vptr08 = (int)&DAT_00e80aa4;
    notify.table = (int*)&DAT_00e80a94;
    ifaceA.vptr = (int)&DAT_00e80a84;
    ifaceB.vptr = (int)&DAT_00e80a74;
    if (notify.owner) {
        for (int i = 0; i < notify.owner->size; ++i)
            notify.FUN_009ef9c0(notify.owner->data[i]);
    }
    if (!(cap38 & 0x80000000u)) {
        int n = cap38 & 0x3fffffff;
        Allocator9ef* a = (Allocator9ef*)TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(data30, n * 4, 0x17);
    }
    ifaceB.~IfaceB9ef();
    ifaceA.~IfaceA9ef();
    ((Base9ef*)this)->FUN_00a64860();
}
}   // namespace f3m_009efc60

// @f3 0x009f15d0 (community match, verified in this file)
extern int DAT_00e80c84;
extern int DAT_00e80c64;
extern int DAT_00e80c54;
extern int DAT_00e80c44;
extern int DAT_00e80a58;
namespace f3m_009f15d0 {
extern "C" void _ReadWriteBarrier(void);


namespace f3m_009f15d0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct Allocator {
    void FUN_008f6d90(void* p, int bytes, int cls);
};

struct HKWorldList {
    void IsEntityAdded(void* entity);
};

struct Listener;

struct ListHolder {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68;
    HKWorldList** m_lists;
    int m_count;
};

struct Listener {
    virtual ~Listener();
    int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
};

struct ParentBase_t {
    int m_vptr00;
    int unk04;
    int m_vptr08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_vptr20;
    ListHolder* m_pHolder;
    void Init();
};

class FUN_009f15d0 : public ParentBase_t {
public:
    int m_listenerVptr;
    int unk2c;
    Listener* m_dataA;
    int m_sizeA;
    unsigned int m_capA;
    Listener* m_dataB;
    int m_sizeB;
    unsigned int m_capB;
    void Destroy();
};

// pdb: hkpSimulationIslandViewer::~hkpSimulationIslandViewer | hkpSimulationIslandViewer.obj | fnv360_0822_retail, call_seq, medium
void FUN_009f15d0::Destroy()
{
    m_vptr00 = (int)&DAT_00e80c84;
    m_vptr08 = (int)&DAT_00e80c64;
    m_vptr20 = (int)&DAT_00e80c54;
    m_listenerVptr = (int)&DAT_00e80c44;

    if (m_pHolder != 0)
    {
        for (int i = 0; i < m_pHolder->m_count; i++)
        {
            HKWorldList* w = m_pHolder->m_lists[i];
            _ReadWriteBarrier();
            w->IsEntityAdded(&m_listenerVptr);
        }
    }

    int nB = m_sizeB;
    for (int i = 0; i < nB; i++)
    {
        Listener* e = &m_dataB[i];
        e->~Listener();
    }
    if ((m_capB & 0x80000000u) == 0)
    {
        int n = m_capB & 0x3fffffff;
        Allocator* a = (Allocator*)TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(m_dataB, n * sizeof(Listener), 0x17);
    }

    int nA = m_sizeA;
    for (int i = 0; i < nA; i++)
    {
        Listener* e = &m_dataA[i];
        e->~Listener();
    }
    if ((m_capA & 0x80000000u) == 0)
    {
        int n = m_capA & 0x3fffffff;
        Allocator* a = (Allocator*)TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(m_dataA, n * sizeof(Listener), 0x17);
    }

    m_listenerVptr = (int)&DAT_00e80a58;
    Init();
}

}
}   // namespace f3m_009f15d0

// @f3 0x009e1680 (community match, verified in this file)
namespace f3m_009e1680 {
namespace task1713 {
struct Finish {int flag;};
struct Base {virtual void v0();unsigned short size,refs;unsigned int userData;Base(Finish):refs(1){}};
struct Handle {unsigned int a,b;void* value;void hkpBridgeConstraintAtom_init(void*);Handle(Finish){hkpBridgeConstraintAtom_init(value);}};
struct FUN_009e1680:Base {Handle handle;FUN_009e1680(Finish);};
// pdb: hkpBallSocketChainData::hkpBallSocketChainData | hkpBallSocketChainData.obj | fnv360_0822_retail, caller_sim, high
// pdb params: f
FUN_009e1680::FUN_009e1680(Finish flag):Base(flag),handle(flag){handle.hkpBridgeConstraintAtom_init(this);}
}
}   // namespace f3m_009e1680

// @f3 0x009e4bb0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009e4bb0 {

extern "C" void* (__stdcall* const DAT_00fdf044)(unsigned long);
namespace a270_9e4bb0 {
struct Allocator {
    virtual void* Alloc(int align, int bytes, int cls);
};
void __cdecl FUN_009234e0(void* dst, const void* src, int bytes);
struct Stack {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    char* unk50;
    int unk54;
    int unk58, unk5C, unk60, unk64, unk68, unk6C;
    char unk70[64];
    void FUN_009e4610();
    char* FUN_009e4bb0();
};
// pdb: hkpExtendedMeshShape::expandOneTriangleSubparts | hkpExtendedMeshShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
char* Stack::FUN_009e4bb0() {
    if (unk54 == 0) {
        unk50 = unk70;
        unk54 = 1;
        return unk70;
    }
    int next = unk54 + 1;
    Allocator* a = (Allocator*)DAT_00fdf044(DAT_010f3170);
    char* mem = (char*)a->Alloc(0x40, next << 6, 0x25);
    FUN_009234e0(mem, unk50, unk54 << 6);
    FUN_009e4610();
    unk54 += 1;
    unk50 = mem;
    int count = *(int volatile*)&unk54;
    return mem + (count * 0x40 - 0x40);
}
}
}   // namespace f3m_009e4bb0

// @f3 0x009f2720 (community match, verified in this file)
extern int DAT_00dcd094,DAT_00e80a58,DAT_00e80d3c,DAT_00e80d1c,DAT_00e80d0c,DAT_00e80cf4,DAT_00e80ce4;
extern const char DAT_00e80cc4[];
namespace f3m_009f2720 {
struct Item494 {virtual void slot00();virtual void* Description();};
struct List494 {Item494** data;int count; __forceinline Item494*& operator[](int i) {return data[i];} };
struct Array494 {unsigned int data,count,capacity;void FUN_00922cb0(); void Init(){data=0;count=0;capacity=0x80000000u;}};
int __cdecl hkString_strCmp(const char*,void*);
struct Owner494 {
    void* table00;unsigned int unk04;void* table08;unsigned int unk0c,unk10,unk14,unk18,unk1c;
    void* table20;unsigned int unk24;void* table28;void* table2c;
    Array494 first,second,third,fourth;
    bool flag60,flag61,flag62,flag63,flag64,flag65;unsigned char unk66,unk67;float value68;
    void FUN_00a648d0(List494*);
    Owner494* FUN_009f2720(List494*);
};
// pdb: hkpShapeDisplayViewer::hkpShapeDisplayViewer | hkpShapeDisplayViewer.obj | fnv360_0822_retail, ustr, medium
// pdb params: contexts
Owner494* Owner494::FUN_009f2720(List494* list) {
    FUN_00a648d0(list);
    *reinterpret_cast<void* volatile*>(&table28)=&DAT_00dcd094;
    *reinterpret_cast<void* volatile*>(&table2c)=&DAT_00e80a58;
    table00=&DAT_00e80d3c;table08=&DAT_00e80d1c;table20=&DAT_00e80d0c;
    *reinterpret_cast<void* volatile*>(&table28)=&DAT_00e80cf4;
    *reinterpret_cast<void* volatile*>(&table2c)=&DAT_00e80ce4;
    first.Init();
    second.FUN_00922cb0();third.FUN_00922cb0();fourth.FUN_00922cb0();
    flag60=true;flag61=false;flag62=false;flag63=true;flag64=true;flag65=true;*reinterpret_cast<volatile float*>(&value68)=-1.0f;
    int count=list->count;
    int i;
    for(i=0;i<count;++i) {
        if(hkString_strCmp(DAT_00e80cc4,list->data[i]->Description())==0) goto found;
    }
    return this;
found:
    Item494*& r=(*list)[i];
    flag60=*reinterpret_cast<bool*>(((r!=0)?reinterpret_cast<char*>(r)-8:static_cast<char*>(0))+0x58);
    return this;
}

}   // namespace f3m_009f2720

// @f3 0x009f1350 (community match, verified in this file)
namespace f3m_009f1350 {
struct ArgOwner1350 {
    void FUN_00902a60(void* p);
    void FUN_00902ba0(void* p);
};

struct Entry1350 {
    ArgOwner1350* owner;
    void FUN_009f5b00(int flag);
};

struct Obj1350 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    Entry1350** table;
    int count;
    void FUN_009f0c30(int index);
    void FUN_009f1350(int index);
};

// pdb: hkpSweptTransformDisplayViewer::removeWorld | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, call_gap, medium
// pdb params: i
void Obj1350::FUN_009f1350(int index)
{
    table[index]->owner->FUN_00902a60(this ? (void*)((char*)this + 0x28) : 0);
    table[index]->owner->FUN_00902ba0((void*)((char*)this + 0x2c));
    FUN_009f0c30(index);
    Entry1350* entry = table[index];
    if (entry)
        entry->FUN_009f5b00(1);
    table[index] = table[--count];
}
}   // namespace f3m_009f1350

// @f3 0x009e4990 (community match, verified in this file)
namespace f3m_009e4990 {
namespace destroy990 {
struct Ref;struct RefTable {void (__thiscall *destroy)(Ref*,int) throw();};struct Ref {RefTable* table;unsigned short size;short count;};
struct Entry {int unk00;int unk04;int unk08;int unk0c;Ref** data;int count;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
};
struct Alloc {void FUN_008f6d90(void*,int,int) throw();};extern unsigned DAT_010f3170;extern Alloc* (__stdcall *DAT_00d9b080)(unsigned) throw();extern void* DAT_00e8066c[];extern void* DAT_00e80648[];extern void* DAT_00e35eec[];extern void* DAT_00dcc494[];
struct Base0 {void** table;unsigned short flags;unsigned short unk06;int unk08;int unk0c; ~Base0() throw() {table=DAT_00dcc494;}};
struct Base10 {void** table10; ~Base10() throw() {table10=DAT_00e35eec;}};
struct FUN_009e4990 : Base0, Base10 {
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
int unk40;
int unk44;
int unk48;
int unk4c;
int unk50;
int unk54;
Entry* entries;int count;short* values;int unk64;unsigned capacity;void FUN_009e4610() throw();void FUN_009e4640() throw();~FUN_009e4990() throw();};
// pdb: hkpExtendedMeshShape::~hkpExtendedMeshShape | hkpExtendedMeshShape.obj | fnv360_0822_retail, call_seq, high
FUN_009e4990::~FUN_009e4990(){table=DAT_00e8066c;table10=DAT_00e80648;for(int i=0;i<count;++i){Entry* e=&entries[i];for(int j=0;j<e->count;++j){Ref* r=e->data[j];if(r->size){--r->count;if(!r->count)r->table->destroy(r,1);}}if((flags&0x7fffu)>0){int n=e->count;Ref** data=e->data;Alloc* allocator=DAT_00d9b080(DAT_010f3170);allocator->FUN_008f6d90(data,n*4,0x27);}}FUN_009e4610();FUN_009e4640();if(!(capacity&0x80000000u)){int n=capacity&0x3fffffff;Alloc* allocator=DAT_00d9b080(DAT_010f3170);allocator->FUN_008f6d90(values,n*2,0x17);}}
}
}   // namespace f3m_009e4990

// @f3 0x009efaf0 (community match, verified in this file)
namespace f3m_009efaf0 {
namespace f3m_009efaf0 {

class Target_009efaf0 {
public:
    virtual void DeleteThis(int flag);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if (referenceCount == 0)
                DeleteThis(1);
        }
    }
};

template <class T> struct Array_009efaf0
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        m_data[index] = m_data[m_iElementCount];
    }
};

struct Owner_009efaf0 {
    int unk00;
    int unk04;
    Array_009efaf0<Target_009efaf0*> m_items;

    void __thiscall FUN_009efaf0(Target_009efaf0* target);
};

// pdb: hkpVehicleViewer::actionRemovedCallback | hkpVehicleViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: action
void __thiscall Owner_009efaf0::FUN_009efaf0(Target_009efaf0* target)
{
    int index = m_items.indexOf(target);
    if (index != -1) {
        m_items.removeAt(index);
        target->removeReference();
    }
}

}
}   // namespace f3m_009efaf0

// @f3 0x009e2430 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009e2430 {
// hkArray-style cleanup: free two 8-byte-element arrays when their
// capacityAndFlags does not carry the "do not deallocate" bit.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct Alloc {
    void FUN_008f6d90(void* p, int bytes, int tag);
};

struct Elem8 { int a; int b; };

class C009e2430 {
public:
    int m_unk00;
    Elem8* m_data04;
    int m_size08;
    int m_cap0c;
    Elem8* m_data10;
    int m_size14;
    int m_cap18;

    void FUN_009e2430();
};

// pdb: hkpMoppCompilerChunkInfo::~hkpMoppCompilerChunkInfo | hkpMoppUtility.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void C009e2430::FUN_009e2430()
{
    if (!(m_cap18 & 0x80000000)) {
        int n = m_cap18 & 0x3fffffff;
        Alloc* a = (Alloc*)TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(m_data10, n * 8, 0x17);
    }
    if (!(m_cap0c & 0x80000000)) {
        int n = m_cap0c & 0x3fffffff;
        Alloc* a = (Alloc*)TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(m_data04, n * 8, 0x17);
    }
}
}   // namespace f3m_009e2430

// @f3 0x009f57e0 (community match, verified in this file)
#include <new>

namespace Merge530
{
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct Listener
{
    virtual void Slot0();
    virtual void Add(void*);
};
template <class T> struct Array
{
    T* data;
    int count, capacity;
};
struct Object
{
    char pad[0x48];
    Array<void*> children;
};
struct Input;
struct Record
{
    Input* source;
    Array<void*> values;

};
struct Heap
{
    char pad[0x48];
    Record* head;
    int count;
    Record* FUN_008f6800(int, int);
    __forceinline Record* Allocate()
    {
        Record* value = head;
        if (value)
        {
            --count;
            head = reinterpret_cast<Record*>(value->source);
            return value;
        }
        return FUN_008f6800(2, 53);
    }
};
struct Input
{
    char pad[0x20];
    Object* root;
    unsigned int pad24;
    Array<Object*> first;
    Array<Object*> second;
    void FUN_00903ae0(Listener*);
    void FUN_00903be0(void**);
};
void __cdecl FUN_00901f10(Array<Record*>*, int);
static __forceinline void Append(Array<Record*>* array, Record* record)
{
    if (array->count == (array->capacity & 0x3fffffff))
        FUN_00901f10(array, 4);
    array->data[array->count++] = record;
}
struct Owner
{
    char pad[0x28];
    Listener listener;
    void* other;
    Array<Record*> records;
    void FUN_009f57e0(Input*);
};
// pdb: hkpConvexRadiusViewer::addWorld | hkpConvexRadiusViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: world
void Owner::FUN_009f57e0(Input* input)
{
    input->FUN_00903ae0(this ? &listener : 0);
    input->FUN_00903be0(this ? &other : 0);
    Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
    Record* storage = heap->Allocate();
    Record* record = 0;
    if (storage)
    {
        storage->values.data = 0;
        storage->values.count = 0;
        storage->values.capacity = 0x80000000;
        record = storage;
    }
    record->source = input;
    Append(&records, record);
    for (int i = 0; i < input->first.count; ++i)
    {
        const Array<void*>& children = input->first.data[i]->children;
        for (int j = 0; j < children.count; ++j)
            listener.Add(children.data[j]);
    }
    for (int i = 0; i < input->second.count; ++i)
    {
        const Array<void*>& children = input->second.data[i]->children;
        for (int j = 0; j < children.count; ++j)
            listener.Add(children.data[j]);
    }
    Object* root = input->root;
    if (root)
    {
        for (int i = 0; i < root->children.count; ++i)
            listener.Add(root->children.data[i]);
    }
}
}

// @f3 0x009edf50 (community match, verified in this file)
namespace f3m_009edf50 {
struct Item_9edf50 {
    int unk00;
    unsigned short w4;
    unsigned short w6;
    int unk08;
    int unk0C;
    float f10;
    void AddReference(short step) { if (w4 != 0) w6 += step; }
};

struct Arr_9edf50 {
    Item_9edf50** data;
    int count;
    unsigned int cap;
};

void FUN_00901e90(Arr_9edf50* a, int cap, int elem);

class Owner9edf50 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    Arr_9edf50 arr;
    void hkpConvexListShape_setShapesAndRadius(Item_9edf50** items, int n);
};

// pdb: hkpConvexListShape::setShapesAndRadius | hkpConvexListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(objrun_prop), high
void Owner9edf50::hkpConvexListShape_setShapesAndRadius(Item_9edf50** items, int n)
{
    Arr_9edf50* a = &arr;
    int cap = a->cap & 0x3fffffff;
    if (cap < n) {
        int newcap = cap * 2;
        if (n >= newcap) newcap = n;
        FUN_00901e90(a, newcap, 4);
    }
    a->count = n;
    unk10 = items[0]->f10;
    int i = 0;
    short step = (short)(i + 1);
    for (; i < n; i += step) {
        Item_9edf50** const destination = a->data;
        destination[i] = items[i];
        items[i]->AddReference(step);
    }
}

}   // namespace f3m_009edf50

// @f3 0x009e15b0 (community match, verified in this file)
namespace f3m_009e15b0 {
namespace F3Pair2296 {
struct Vector { float x,y,z,w; };
struct Pair { Vector first, second; };
struct Array {
    Pair* data;
    int count;
    unsigned capacity;
};
extern void __cdecl FUN_00901f10(Array*, int);
struct Owner {
    unsigned unk00,unk04,unk08,unk0c,unk10,unk14;
    Array pairs;
    Pair* hkpBallSocketChainData_addConstraintInfoInBodySpace(const Vector*, const Vector*);
};
// pdb: hkpBallSocketChainData::addConstraintInfoInBodySpace | hkpBallSocketChainData.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
Pair* Owner::hkpBallSocketChainData_addConstraintInfoInBodySpace(const Vector* first, const Vector* second)
{
    Array* a=&pairs;
    int capacity=a->capacity&0x3fffffff;
    if (a->count==capacity) FUN_00901f10(a,sizeof(Pair));
    Pair* result=&a->data[a->count++];
    result->first.x=first->x; result->first.y=first->y;
    result->first.z=first->z; result->first.w=first->w;
    result->second.x=second->x; result->second.y=second->y;
    result->second.z=second->z; result->second.w=second->w;
    return result;
}
}
}   // namespace f3m_009e15b0

// @f3 0x009eb790 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long index);
namespace n9eb790 {
extern unsigned long DAT_010f3170;
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
void __cdecl FUN_00901e90(void* arr, int cap, int elemSize) throw();
struct Vec4 { float x; float y; float z; float w; };
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    Array() : data(0), size(0), capAndFlags(0x80000000) {}
    T& expandOne() throw() {
        int s = size;
        int n = s + 1;
        int cap = capAndFlags & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
        size = n;
        return data[s];
    }
    ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = (Alloc*)::FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
struct Strided { float* data; int count; int stride; };
void __cdecl FUN_00a5fae0(const void* points, int count, int a, int b, int c) throw();
}
// pdb: hkgpConvexHull::build | hkgpConvexHull.obj | fnv360_0822_retail, callee_sim, low
// pdb params: points, config
void __cdecl FUN_009eb790(n9eb790::Strided* in, int a, int b, int c)
{
    using namespace n9eb790;
    if (in->stride == 16 && ((unsigned int)in->data & 0xf) == 0) {
        FUN_00a5fae0(in->data, in->count, a, b, c);
        return;
    }
    Array<Vec4> arr;
    int stride = in->stride / 4;
    for (int i = 0; i < in->count; i++) {
        Vec4& v = arr.expandOne();
        v.x = in->data[i * stride];
        v.y = in->data[i * stride + 1];
        v.z = in->data[i * stride + 2];
    }
    FUN_00a5fae0(arr.data, in->count, a, b, c);
}

// @f3 0x009e1c10 (community match, verified in this file)
namespace f3m_009e1c10 {
namespace f3m_009e1c10 {
struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct Aabb
{
    Vec4 min;
    Vec4 max;
};

struct BroadphaseQuery
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;

    void FUN_00a52f70(int world, Aabb* box, int filter);
};

struct Region
{
    int unk00; int unk04; int unk08; int unk0C;
    int world;
    int unk14; int unk18; int unk1C;
    Vec4 origin;

    void FUN_009e1c10(const Aabb* in, int filter);
};

// pdb: hkMoppBvTreeShapeBase::queryAabb | hkpMoppBvTreeShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: aabb, hits
void Region::FUN_009e1c10(const Aabb* in, int filter)
{
    float r = 16777216.0 / origin.w;
    Vec4 upper;
    upper.x = origin.x + r;
    upper.y = origin.y + r;
    upper.z = origin.z + r;
    upper.w = r + origin.w;
    Aabb box;
    box.min.x = origin.x > in->min.x ? origin.x : in->min.x;
    box.min.y = origin.y > in->min.y ? origin.y : in->min.y;
    box.min.z = origin.z > in->min.z ? origin.z : in->min.z;
    box.min.w = origin.w > in->min.w ? origin.w : in->min.w;
    box.max.x = upper.x < in->max.x ? upper.x : in->max.x;
    box.max.y = upper.y < in->max.y ? upper.y : in->max.y;
    box.max.z = upper.z < in->max.z ? upper.z : in->max.z;
    box.max.w = upper.w < in->max.w ? upper.w : in->max.w;
    BroadphaseQuery query;
    query.FUN_00a52f70(world, &box, filter);
}
}
}   // namespace f3m_009e1c10

// @f3 0x009e0240 (community match, verified in this file)
namespace f3m_009e0240 {
// 0x009e0240 -- appends to three hkArray-style containers.
struct __declspec(align(16)) Vec4 { float x; float y; float z; float w; };

void __cdecl FUN_00901f10(void* arr, int elemSize);

struct IntArr
{
    int* data;
    int size;
    unsigned int capFlags;
    inline void Add(int v)
    {
        if (size == (int)(capFlags & 0x3fffffff))
            FUN_00901f10(this, 4);
        data[size] = v;
        size = size + 1;
    }
};

struct VecArr
{
    Vec4* data;
    int size;
    unsigned int capFlags;
    inline Vec4* Add()
    {
        if (size == (int)(capFlags & 0x3fffffff))
            FUN_00901f10(this, 16);
        Vec4* p = &data[size];
        size = size + 1;
        return p;
    }
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    VecArr vecs;
    IntArr ints;
    int unk28;
    int unk2c;
    int unk30;
    IntArr ptrs;
};

struct Arg2
{
    int unk00;
    unsigned short count;
    unsigned short refs;
};

struct Self
{
    int unk00;
    Holder* holder;
    int FUN_009e0240(unsigned char a1, Arg2* a2);
};

// pdb: hkpConstraintConstructionKit::setLinearMotor | hkpConstraintConstructionKit.obj | tesv_win, objopen_prop, low
int Self::FUN_009e0240(unsigned char a1, Arg2* a2)
{
    Vec4 v;
    int idx;

    holder->ints.Add(0xf);
    int flag = a1;
    holder->ints.Add(flag);
    v.x = (float)holder->ptrs.size;
    idx = holder->vecs.size;
    if (a2->count)
        a2->refs = a2->refs + 1;
    Vec4* p = holder->vecs.Add();
    p->x = v.x;
    p->y = 0.0f;
    p->z = 0.0f;
    p->w = 0.0f;
    holder->ptrs.Add((int)a2);
    Holder* h = holder;
    h->unk04 = h->unk04 + 0x50;
    h->unk08 = h->unk08 + 1;
    h->unk0c = h->unk0c + 3;
    return idx;
}
}   // namespace f3m_009e0240

// @f3 0x009edfc0 (community match, verified in this file)
namespace f3m_009edfc0 {
struct hkTransform { float m_rows[4][4]; };

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
};

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;

    __forceinline void includeAabb(const hkAabb& aabb)
    {
        m_min.x = m_min.x < aabb.m_min.x ? m_min.x : aabb.m_min.x;
        m_min.y = m_min.y < aabb.m_min.y ? m_min.y : aabb.m_min.y;
        m_min.z = m_min.z < aabb.m_min.z ? m_min.z : aabb.m_min.z;
        m_min.w = m_min.w < aabb.m_min.w ? m_min.w : aabb.m_min.w;
        m_max.x = m_max.x > aabb.m_max.x ? m_max.x : aabb.m_max.x;
        m_max.y = m_max.y > aabb.m_max.y ? m_max.y : aabb.m_max.y;
        m_max.z = m_max.z > aabb.m_max.z ? m_max.z : aabb.m_max.z;
        m_max.w = m_max.w > aabb.m_max.w ? m_max.w : aabb.m_max.w;
    }
};

class hkpShape
{
public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void calcAabb(const hkTransform& localToWorld, float tolerance, hkAabb& aabbOut) const;
};

struct hkChildShapes
{
    hkpShape** m_data;
    int m_size;
    int m_capacity;
};

struct hkpConvexListShape
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    float m_radius;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    hkVector4 m_halfExtents;
    hkVector4 m_center;
    bool m_useCachedAabb;
    hkChildShapes m_children;

    void FUN_009edfc0(const hkTransform& localToWorld, float tolerance, hkAabb& aabbOut) const;
};

void FUN_009a7a80(const hkTransform& localToWorld, const hkVector4& halfExtents, const hkVector4& center,
                  float radius, hkAabb& aabbOut);

void hkpConvexListShape::FUN_009edfc0(const hkTransform& localToWorld, float tolerance, hkAabb& aabbOut) const
{
    if (m_useCachedAabb)
    {
        FUN_009a7a80(localToWorld, m_halfExtents, m_center, m_radius + tolerance, aabbOut);
        return;
    }

    m_children.m_data[0]->calcAabb(localToWorld, tolerance, aabbOut);

    hkAabb aabb;
    for (int i = 1; i < m_children.m_size; i++)
    {
        m_children.m_data[i]->calcAabb(localToWorld, tolerance, aabb);
        aabbOut.includeAabb(aabb);
    }
}
}   // namespace f3m_009edfc0

// @f3 0x009f2150 (community match, verified in this file)
namespace f3m_009f2150 {
namespace display_geometry_copy {
struct __declspec(align(16)) Vector4 {
 float x,y,z,w;__forceinline Vector4() {}
 __forceinline Vector4(const Vector4& v):x(v.x),y(v.y),z(v.z),w(v.w){}
 __forceinline Vector4& operator=(const Vector4& v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
};
struct __declspec(align(16)) Matrix3 {
 Vector4 column0,column1,column2;__forceinline Matrix3(){}
 __forceinline Matrix3(const Matrix3& v):column0(v.column0),column1(v.column1),column2(v.column2){}
 __forceinline Matrix3& operator=(const Matrix3& v){column0=v.column0;column1=v.column1;column2=v.column2;return *this;}
};
struct __declspec(align(16)) Transform {
 Matrix3 rotation;Vector4 translation;__forceinline Transform(){}
 __forceinline Transform(const Transform& v):rotation(v.rotation),translation(v.translation){}
 __forceinline Transform& operator=(const Transform& v){rotation=v.rotation;translation=v.translation;return *this;}
};
struct hkBaseObject { virtual ~hkBaseObject() throw(); };
struct hkReferencedObject : hkBaseObject { unsigned short memorySizeAndFlags,referenceCount;__forceinline hkReferencedObject() throw():referenceCount(1){} };
struct Geometry;
struct hkDisplayGeometry : hkReferencedObject {
 unsigned int type;Transform transform;Geometry* geometry;
 hkDisplayGeometry(const hkDisplayGeometry&) throw();
};
hkDisplayGeometry::hkDisplayGeometry(const hkDisplayGeometry& source) throw() {
 type=source.type;
 Transform snapshot(source.transform);transform=snapshot;
 geometry=source.geometry;
}
}
}   // namespace f3m_009f2150

// @f3 0x009f3bd0 (community match, verified in this file)
extern float DAT_00dc0a84,DAT_00db8b4c,DAT_00dbe1e0;
namespace f3m_009f3bd0 {
namespace Native1696 {
typedef void* (__stdcall *TlsFn)(unsigned long);extern TlsFn DAT_00d9b080;extern unsigned long DAT_010f3170;
struct __declspec(align(16)) Vector {float x,y,z,w;void FUN_008d2970(const void*,const Vector&);};
struct FUN_0092e3c0;struct World {void FUN_00907120(FUN_0092e3c0*);};
struct Entity {unsigned unk00,unk04;World* world;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
unsigned unk34;
unsigned unk38;
unsigned unk3c;
unsigned unk40;
unsigned unk44;
unsigned unk48;
unsigned unk4c;
unsigned unk50;
unsigned unk54;
unsigned unk58;
unsigned unk5c;
unsigned unk60;
unsigned unk64;
unsigned unk68;
unsigned unk6c;
unsigned unk70;
unsigned unk74;
unsigned unk78;
unsigned unk7c;
unsigned unk80;
unsigned unk84;
unsigned unk88;
unsigned unk8c;
unsigned unk90;
unsigned unk94;
unsigned unk98;
unsigned unk9c;
unsigned unka0;
unsigned unka4;
unsigned unka8;
unsigned unkac;
unsigned unkb0;
unsigned unkb4;
unsigned unkb8;
unsigned unkbc;
unsigned unkc0;
unsigned unkc4;
unsigned unkc8;
unsigned unkcc;
unsigned unkd0;
unsigned unkd4;
unsigned char motion;char unkd9,unkda,unkdb;unsigned unkdc;Vector transform;World* GetWorld(){return world;}
};
struct Pool {void* FUN_008f6d30(int,int);};
struct FUN_0092e3c0 {
unsigned unk00;unsigned short size;unsigned short unk06;
unsigned unk08;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
unsigned unk34;
unsigned unk38;
unsigned unk3c;
unsigned unk40;
unsigned unk44;
unsigned unk48;
unsigned unk4c;
unsigned unk50;
unsigned unk54;
unsigned unk58;
unsigned unk5c;
FUN_0092e3c0(const Vector&,const Vector&,float,float,float,Entity*,int) throw();
static __forceinline void* operator new(unsigned n){Pool* p=(Pool*)DAT_00d9b080(DAT_010f3170);FUN_0092e3c0* v=(FUN_0092e3c0*)p->FUN_008f6d30(n,0x29);v->size=(unsigned short)n;return v;}
void FUN_0092dea0(float);
};
struct Node {unsigned unk00,unk04,unk08,unk0c;signed char ownerOffset;char unk11,unk12,unk13;unsigned unk14;unsigned char type;};
struct Bool {bool value;Bool(bool b):value(b){}};
struct Holder {
unsigned unk00;
unsigned unk04;
unsigned unk08;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
World* world;FUN_0092e3c0* spring;float maxForce;
Bool FUN_009f3bd0(unsigned __int64 tagged,const Vector& pos);
};
// pdb: hkpMousePickingViewer::pickObject | hkpMousePickingViewer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: id, worldPosition
Bool Holder::FUN_009f3bd0(unsigned __int64 tagged,const Vector& pos){
unsigned __int64 tag=tagged&3;
if(tag==3)tagged&=~3ui64;else if(tag!=0)return false;
Node* n=(Node*)(unsigned)tagged;
if(n->type==1){Entity* e=(Entity*)((char*)n+n->ownerOffset);if(e){world=e->GetWorld();if(e->motion!=7&&e->GetWorld()==world){
Vector local;local.FUN_008d2970(&e->transform,pos);
spring=new FUN_0092e3c0(local,pos,0.5f,0.3f,0.95f,e,0);
spring->FUN_0092dea0(maxForce);world->FUN_00907120(spring);
}}}return true;
}
}

}   // namespace f3m_009f3bd0

// @f3 0x009e3630 (community match, verified in this file)
struct SimdVec4
{
    FNV_ALIGN(16) float x;
    float y;
    float z;
    float w;

    __forceinline void setAll(float a)
    {
        x = a;
        y = a;
        z = a;
        w = a;
    }

    __forceinline void setNeg4(const SimdVec4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }

    __forceinline void setMin4(const SimdVec4& a, const SimdVec4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }

    __forceinline void setMax4(const SimdVec4& a, const SimdVec4& b)
    {
        x = a.x > b.x ? a.x : b.x;
        y = a.y > b.y ? a.y : b.y;
        z = a.z > b.z ? a.z : b.z;
        w = a.w > b.w ? a.w : b.w;
    }
};

struct SimdQuat
{
    SimdVec4 m_vec;
};

struct FNV_ALIGN(16) SimdRotation
{
    SimdVec4 m_col0;
    SimdVec4 m_col1;
    SimdVec4 m_col2;

    void hkRotation_set(const SimdQuat& q);
};

struct SimdTransform
{
    SimdRotation m_rotation;
    SimdVec4 m_translation;

    __forceinline SimdTransform(const SimdQuat& q, const SimdVec4& t)
        : m_translation(t)
    {
        m_rotation.hkRotation_set(q);
    }
};

struct SimdAabb
{
    SimdVec4 m_min;
    SimdVec4 m_max;

    SimdAabb() {}
};

class ChildShapeBase
{
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void getAabbImpl(const SimdTransform& localToWorld, float tolerance, SimdAabb& out) const = 0;

    __forceinline void getAabb(const SimdTransform& localToWorld, float tolerance, SimdAabb& out) const
    {
        getAabbImpl(localToWorld, tolerance, out);
    }
};

template <class T>
class ShapeRefPtr
{
public:
    T* m_pntr;
    inline T* operator->() const { return m_pntr; }
};

template <class T>
class ShapeArray
{
public:
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    inline int getSize() const { return m_size; }
    inline const T& operator[](int i) const { return m_data[i]; }
};

struct ShapesSubpartEntry
{
    int unk00;
    const void* unk04;
    int unk08;
    const void* unk0C;
    ShapeArray< ShapeRefPtr<ChildShapeBase> > m_childShapes;
    SimdQuat m_rotation;
    SimdVec4 m_translation;

    inline const SimdVec4& getTranslation() const { return m_translation; }
    inline const SimdQuat& getRotation() const { return m_rotation; }
};

// pdb: hkpExtendedMeshShape::calcAabbExtents | hkpExtendedMeshShape.obj | tesv_win, objopen_prop, low
static __declspec(noinline) void FUN_009e3630(const ShapesSubpartEntry& part, SimdAabb& out)
{
    out.m_min.setAll(3.40282e+38f);
    out.m_max.setNeg4(out.m_min);

    SimdTransform transform(part.getRotation(), part.getTranslation());

    for (int i = 0; i < part.m_childShapes.getSize(); i++)
    {
        SimdAabb childAabb;
        part.m_childShapes[i]->getAabb(transform, 0.0f, childAabb);
        out.m_min.setMin4(out.m_min, childAabb.m_min);
        out.m_max.setMax4(out.m_max, childAabb.m_max);
    }
}

extern volatile ShapesSubpartEntry* g_partPtr;
extern volatile SimdAabb* g_outPtr;

void caller_9e3630()
{
    FUN_009e3630(*const_cast<const ShapesSubpartEntry*>(g_partPtr), *const_cast<SimdAabb*>(g_outPtr));
}

// @f3 0x009e7960 (community match, verified in this file)
namespace f3m_009e7960 {
namespace Unpack603
{
struct Vector { float x, y, z, w; };
struct Planar { float x[4], y[4], z[4]; };
struct Owner
{
    char pad[0x10];
    float weight;
    char gap[0x2c];
    const Planar* blocks;
    int unused[2];
    int count;
    Vector* hkpConvexVerticesShape_getCollisionSpheresImpl(Vector*);
};
// pdb: hkpConvexVerticesShape::getCollisionSpheresImpl | hkpConvexVerticesShape.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
Vector* Owner::hkpConvexVerticesShape_getCollisionSpheresImpl(Vector* output)
{
    __declspec(align(16)) Vector temp;
    const Planar* block = blocks;
    Vector* out = output;
    int remaining = count - 1;
    if (remaining >= 3)
    {
        unsigned groups = static_cast<unsigned>(remaining + 1) >> 2;
        remaining -= groups * 4;
        do
        {
{ temp.x = block->x[0]; temp.y = block->y[0]; temp.z = block->z[0]; temp.w = weight;
        Vector* current = out++; current->x = temp.x; current->y = temp.y; current->z = temp.z; current->w = temp.w; }
{ temp.x = block->x[1]; temp.y = block->y[1]; temp.z = block->z[1]; temp.w = weight;
        Vector* current = out++; current->x = temp.x; current->y = temp.y; current->z = temp.z; current->w = temp.w; }
{ temp.x = block->x[2]; temp.y = block->y[2]; temp.z = block->z[2]; temp.w = weight;
        Vector* current = out++; current->x = temp.x; current->y = temp.y; current->z = temp.z; current->w = temp.w; }
{ temp.x = block->x[3]; temp.y = block->y[3]; temp.z = block->z[3]; temp.w = weight;
        Vector* current = out++; current->x = temp.x; current->y = temp.y; current->z = temp.z; current->w = temp.w;            ++block; }
        } while (--groups);
    }
    if (remaining >= 0) { temp.x = block->x[0]; temp.y = block->y[0]; temp.z = block->z[0]; temp.w = weight;
        Vector* current = out++; current->x = temp.x; current->y = temp.y; current->z = temp.z; current->w = temp.w; }
    if (remaining >= 1) { temp.x = block->x[1]; temp.y = block->y[1]; temp.z = block->z[1]; temp.w = weight;
        Vector* current = out++; current->x = temp.x; current->y = temp.y; current->z = temp.z; current->w = temp.w; }
    if (remaining >= 2) { temp.x = block->x[2]; temp.y = block->y[2]; temp.z = block->z[2]; temp.w = weight;
        out->x = temp.x; out->y = temp.y; out->z = temp.z; out->w = temp.w; }    return output;
}
}


}   // namespace f3m_009e7960

// @f3 0x009e0360 (community match, verified in this file)
namespace f3m_009e0360 {
namespace Vector613
{
void __cdecl FUN_00901f10(void*, unsigned);
struct ScalarArray
{
    unsigned* data;
    int size;
    unsigned capacity;
    __forceinline void Add(unsigned value)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, 4);
        data[size] = value;
        ++size;
    }
};
struct __declspec(align(16)) Vector { float x, y, z, w; };
struct VectorArray
{
    Vector* data;
    int size;
    unsigned capacity;
    __forceinline Vector* Append()
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, 16);
        Vector* entry = data + size;
        ++size;
        return entry;
    }
};
struct Storage
{
    int unused, bytes, count, headers;
    VectorArray points;
    ScalarArray commands;
};
struct Owner
{
    int unused;
    Storage* storage;
    int FUN_009e0360(unsigned char, float);
};
// pdb: hkpConstraintConstructionKit::setAngularFriction | hkpConstraintConstructionKit.obj | tesv_win, objrun_open, low
int Owner::FUN_009e0360(unsigned char tag, float value)
{
    storage->commands.Add(20);
    unsigned command = tag;
    storage->commands.Add(command);
    Storage* current = storage;
    int index = current->points.size;
    Vector* entry = current->points.Append();
    __declspec(align(16)) float scalar = value;
    entry->x = scalar;
    entry->y = 0.0f;
    entry->z = 0.0f;
    entry->w = 0.0f;
    current = storage;
    current->bytes += 48;
    ++current->count;
    current->headers += 2;
    return index;
}
}


}   // namespace f3m_009e0360

// @f3 0x009e2c60 (community match, verified in this file)
namespace f3m_009e2c60 {
namespace f3m_009e2c60 {
struct Plane9e { float x, y, z, w; };
struct PlaneArray9e { Plane9e* data; int count; };
struct Transform9e {
    int unk00, unk04, unk08, unk0c;
    Plane9e p;
    void FUN_009e2c60(PlaneArray9e* src, Plane9e* out);
};

void Transform9e::FUN_009e2c60(PlaneArray9e* src, Plane9e* out)
{
    Plane9e* o = out;
    Plane9e* in = src->data;
    int n = src->count;
    for (int i = n - 1; i >= 0; --i) {
        o->x = p.x;
        o->y = p.y;
        o->z = p.z;
        o->w = p.w;
        float d = in->x * p.x + in->y * p.y + in->z * p.z + p.w;
        o->w = d - in->w;
        ++in;
        ++o;
    }
}
}
}   // namespace f3m_009e2c60

// @f3 0x009f5c10 (community match, verified in this file)
#include <intrin.h>
extern unsigned DAT_0116913c;extern void* DAT_01169834;
extern const char DAT_00e811a0[],DAT_00e32798[];
namespace f3m_009f5c10 {
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long);
namespace ConstraintDrawDetail {
struct TraceEntry
{
    const char* name;
    unsigned tick;
    unsigned value;
};
struct TraceBuffer
{
    char* begin;
    char* current;
    char* end;
    char* limit;
};
struct Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual unsigned getType();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Shape* child;
    Shape* FUN_0095b0f0();
};
struct Collidable
{
    int unk00;
    int unk04;
    int unk08;
    Shape* shape;
    int unk10;
    void* first;
    void* second;
};
struct LocalCollidable : Collidable
{
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    void FUN_00979fb0(void*, void*, Shape*, bool);
    void FUN_0097a090();
};
struct Transform
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
};
struct __declspec(align(16)) Renderer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    void FUN_00a6a700();
    void FUN_00de47d0(float);
    void FUN_00a6f260(Collidable*, void*, void*);
    void FUN_00a6f090(Collidable*, void*, void*);
    void FUN_00a6e650(Collidable*, void*, void*);
    void FUN_00a6e460(Collidable*, void*, void*);
    void FUN_00a6ddd0(Collidable*, void*, void*);
    void FUN_00a6dbd0(Collidable*, void*, void*);
    void FUN_00a6d890(Collidable*, void*, void*);
    void FUN_00a6d020(Collidable*, void*, void*);
    void FUN_00a6cc50(Collidable*, void*, void*);
};
struct __declspec(align(16)) Extended : Renderer
{
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    void FUN_009f62f0();
    void FUN_00a6ec10(Collidable*, void*, void*);
    void FUN_00a6c820(Collidable*, void*, void*);
};
struct Tail
{
    void FUN_00a28830();
};
struct ComplexCleanup
{
    void FUN_009f6310();
};
struct __declspec(align(16)) Complex : Renderer
{
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    void FUN_009f62b0();
    void FUN_00a6d290(Collidable*, void*, void*);
    void FUN_00a6c270(Collidable*, void*, void*);
    void FUN_009f6310();
};
struct Viewer {void FUN_009f5c10(Collidable*,void*);};
}
// pdb: hkpConstraintViewer::draw | hkpConstraintViewer.obj | fnv360_0822_retail, ustr, medium
// pdb params: constraint, masterEntity, displayHandler
void ConstraintDrawDetail::Viewer::FUN_009f5c10(Collidable* object, void* context)
{
    using namespace ConstraintDrawDetail;
    Viewer* owner = this;
    volatile unsigned ticks;
    Extended renderer;
    Complex complexRenderer;
    LocalCollidable child;
    {
    TraceBuffer* trace = (TraceBuffer*)FUN_00d9b080(DAT_0116913c);
    char* entry = trace->current;
    if (entry < trace->limit)
    {
        *(const char**)entry = DAT_00e811a0;
        _ReadWriteBarrier();
        ticks = (unsigned)__rdtsc();
        *(unsigned*)(entry+4) = ticks;
        entry += 12;
        trace->current = entry;
    }
    }
    unsigned uiShapeType = object->shape->getType();
    switch (uiShapeType)
    {
    case 0: {
        renderer.FUN_00a6a700();
        renderer.FUN_00a6f260(object, context, DAT_01169834);
        break;
    }
    case 1: {
        renderer.FUN_00a6a700();
        renderer.FUN_00a6f090(object, context, DAT_01169834);
        break;
    }
    case 2: {
        renderer.FUN_009f62f0();
        renderer.FUN_00a6ec10(object, context, DAT_01169834);
        ((Tail*)&renderer.unk0d0)->FUN_00a28830();
        break;
    }
    case 6: {
        renderer.FUN_00a6a700();
        renderer.FUN_00a6e650(object, context, DAT_01169834);
        break;
    }
    case 8: {
        renderer.FUN_00a6a700();
        renderer.FUN_00a6e460(object, context, DAT_01169834);
        break;
    }
    case 9: {
        renderer.FUN_00a6a700();
        renderer.FUN_00a6ddd0(object, context, DAT_01169834);
        break;
    }
    case 3: {
        renderer.FUN_00a6a700();
        renderer.FUN_00a6dbd0(object, context, DAT_01169834);
        break;
    }
    case 14: {
        renderer.FUN_00a6a700();
        renderer.FUN_00a6d890(object, context, DAT_01169834);
        break;
    }
    case 7: {
        complexRenderer.FUN_009f62b0();
        complexRenderer.FUN_00a6d290(object, context, DAT_01169834);
        complexRenderer.FUN_009f6310();
        break;
    }
    case 12: {
        child.FUN_00979fb0(object->first, object->second, object->shape->child, true);
        owner->FUN_009f5c10(&child, context);
        child.FUN_0097a090();
        break;
    }
    case 13: {
        Shape* pParentShape = object->shape;
        void* second = object->second;
        void* first = object->first;
        child.FUN_00979fb0(first, second, pParentShape->FUN_0095b0f0(), true);
        owner->FUN_009f5c10(&child, context);
        child.FUN_0097a090();
        break;
    }
    case 15: {
        renderer.FUN_00a6a700();
        renderer.FUN_00a6d020(object, context, DAT_01169834);
        break;
    }
    case 100:
    case 101:
    case 102: {
        renderer.FUN_00a6a700();
        renderer.FUN_00a6cc50(object, context, DAT_01169834);
        break;
    }
    case 18: {
        renderer.FUN_009f62f0();
        renderer.FUN_00a6c820(object, context, DAT_01169834);
        ((Tail*)&renderer.unk0d0)->FUN_00a28830();
        break;
    }
    case 19: {
        complexRenderer.FUN_009f62b0();
        complexRenderer.FUN_00a6c270(object, context, DAT_01169834);
        ((ComplexCleanup*)&complexRenderer)->FUN_009f6310();
        break;
    }
    }
    TraceBuffer* trace = (TraceBuffer*)FUN_00d9b080(DAT_0116913c);
    if (trace->current < trace->limit)
    {
        char* entry = trace->current;
        *(const char**)entry = DAT_00e32798;
        _ReadWriteBarrier();
        volatile unsigned tick = (unsigned)__rdtsc();
        *(unsigned*)(entry+4) = tick;
        entry += 12;
        trace->current = entry;
    }
}

}   // namespace f3m_009f5c10

// @f3 0x009e8750 (community match, verified in this file)
namespace n9e8750 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
extern const void* DAT_00e8074c;
struct Alloc {
    void FUN_008f6d90(void* p, int size, int tag) throw();
    void* FUN_008f6d30(int size, int tag) throw();
};
struct Vector4 {
    float x, y, z, w;
    Vector4& operator=(const Vector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
template <class T> __forceinline void copy(T* dst, const T* src, int n) { for (int i = 0; i < n; i++) dst[i] = src[i]; }
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    void Init() { data = 0; size = 0; capAndFlags = 0x80000000; }
    __forceinline void assign(const Array& o) throw() {
        if ((capAndFlags & 0x3fffffff) < o.size) { int cap = capAndFlags & 0x3fffffff;
            if ((capAndFlags & 0x80000000) == 0) {
                Alloc* al = (Alloc*)TlsGetValue(DAT_010f3170);
                al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
            }
            Alloc* al = (Alloc*)TlsGetValue(DAT_010f3170);
            data = (T*)al->FUN_008f6d30(o.size * sizeof(T), 0x17);
            capAndFlags = (capAndFlags & 0x40000000) | o.size;
        }
        size = o.size;
        copy(data, o.data, size);
    }
};
struct Triple { int a, b, c; };
struct Shape {
    const void* vtable;
    unsigned short memSize;
    short refCount;
    int userData;
    int type;
    float radius;
    char unk14[0x40 - 0x14];
    Array<void*> unk40;
    int unk4C;
    Array<Vector4> vertices;
    int unk5C;
    Shape* FUN_009e8750(const Triple* t, const Array<Vector4>& v, float r);
    void FUN_009e80c0(int a, int c, int b);
};
// pdb: hkpConvexVerticesShape::hkpConvexVerticesShape | hkpConvexVerticesShape.obj | fnv360_0822_retail, objrun, high
// pdb params: rotatedVertices, numVertices, planes, numPlanes, aabb, radius
Shape* Shape::FUN_009e8750(const Triple* t, const Array<Vector4>& v, float r)
{
    radius = r;
    refCount = 1;
    userData = 0;
    type = 7;
    vtable = &DAT_00e8074c;
    unk40.Init();
    vertices.Init();
    unk5C = 0;
    vertices.assign(v);
    FUN_009e80c0(t->a, t->c, t->b);
    return this;
}
}

// @f3 0x009e3b50 (community match, verified in this file)
namespace f3m_009e3b50 {
namespace w9e3b50 {
void __cdecl FUN_00901e90(void* arr, int cap, int elemSize) throw();
struct hkBool {
    char m_bool;
    hkBool(bool b) { m_bool = (char)b; }
};
unsigned short __cdecl FUN_00a560b0(unsigned int key, int a, bool b);
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    T& operator[](int i) { return data[i]; }
    int getCapacity() const { return capAndFlags & 0x3fffffff; }
    void reserve(int n)
    {
        if (getCapacity() < n)
            FUN_00901e90(this, n, sizeof(T));
    }
    void setSize(int n)
    {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = cap + cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
        size = n;
    }
};
struct Elem { int pad00[4]; int count10; int pad14[10]; int offset3c; };
struct Obj {
    char pad00[0x14];
    bool done14;
    char pad15[3];
    int shift18;
    char pad1c[0x50 - 0x1c];
    Elem* elems;
    int count54;
    int pad58[2];
    Array<unsigned short> keys60;
    volatile char mode6c;
    void FUN_009e3b50(int a, int mode);
};
// pdb: hkpExtendedMeshShape::calcSizeForSpu | hkpExtendedMeshShape.obj | tesv_win, objopen_prop, low
void Obj::FUN_009e3b50(int a, int mode)
{
    int total = 0;
    for (int i = 0; i < count54; i++) {
        elems[i].offset3c = total;
        total += elems[i].count10;
    }
    keys60.reserve(total);
    keys60.setSize(total);
    int k = 0;
    for (int i = 0; i < count54; i++)
        for (int j = 0; j < elems[i].count10; j++)
        {
            unsigned int key = (i << (32 - shift18)) | j;
            keys60[k] = FUN_00a560b0(key, a, mode != 5);
            k++;
        }
    done14 = true;
    mode6c = (char)mode;
}
}
}   // namespace f3m_009e3b50

// @f3 0x009f59a0 (community match, verified in this file)
namespace f3m_009f59a0 {
namespace f3m_009f59a0 {
struct CollisionAgent {
    void FUN_00902a60(void* listener);
    void FUN_00902ba0(void* listener);
};

struct Record {
    CollisionAgent* agent;
    void FUN_009f5b00(int releaseStorage);
};

struct Viewer {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    void* firstListenerTable;
    void* secondListenerTable;
    Record** records;
    int recordCount;

    void FUN_009f54c0(int index);
    void FUN_009f59a0(int index);
};

// pdb: hkpConvexRadiusViewer::removeWorld | hkpConvexRadiusViewer.obj | fnv360_0822_retail, call_gap, medium
// pdb params: i
void Viewer::FUN_009f59a0(int index)
{
    records[index]->agent->FUN_00902a60(this ? &firstListenerTable : 0);
    records[index]->agent->FUN_00902ba0(&secondListenerTable);
    FUN_009f54c0(index);

    Record* record = records[index];
    if (record)
        record->FUN_009f5b00(1);
    records[index] = records[--recordCount];
}
}
}   // namespace f3m_009f59a0

// @f3 0x009f54c0 (community match, verified in this file)
extern void* DAT_01169828;
namespace f3m_009f54c0 {
namespace f3m_009f54c0 {

struct ShapeHandle {
    void* shape;
};

struct Listener {
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0c();
    virtual void Unk10();
    virtual void Remove(ShapeHandle handle, void* category, int value);
};

struct ShapeArray {
    ShapeHandle* data;
    int count;
    unsigned int capacity;
};

struct Record {
    void* collisionAgent;
    ShapeArray shapes;
};

struct Viewer {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Listener* listener;
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
    Record** records;
    void FUN_009f54c0(int index);
};

void __cdecl FUN_00901e90(ShapeArray* array, int capacity, int elementSize);

// pdb: hkpConvexRadiusViewer::removeAllGeometries | hkpConvexRadiusViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: worldIndex
void Viewer::FUN_009f54c0(int index)
{
    Record* record = records[index];
    for (int i = 0; i < record->shapes.count; ++i)
        listener->Remove(record->shapes.data[i], DAT_01169828, 0);

    ShapeArray* shapes = &record->shapes;
    int capacity = shapes->capacity & 0x3fffffff;
    if (capacity < 0)
        FUN_00901e90(shapes, capacity * 2 > 0 ? capacity * 2 : 0, sizeof(ShapeHandle));
    shapes->count = 0;
}
}

}   // namespace f3m_009f54c0

// @f3 0x009f40a0 (community match, verified in this file)
namespace f3m_009f40a0 {
namespace f3m_009f40a0 {
struct Item;

struct Items {
    Item** data;
    int count;
    unsigned int capacity;
};

void __cdecl FUN_00901f10(Items* items, int elementSize);

struct Owner {
    unsigned int unk00, unk04;
    Items items;
    void FUN_009f40a0(Item* item);
};

void Owner::FUN_009f40a0(Item* item)
{
    Items* array = &items;
    if (array->count == static_cast<int>(array->capacity & 0x3fffffffu))
        FUN_00901f10(array, sizeof(Item*));
    array->data[array->count] = item;
    ++array->count;
}
}
}   // namespace f3m_009f40a0

// @f3 0x009e37e0 (community match, verified in this file)
namespace f3m_009e37e0 {
extern const float DAT_00de6e60, DAT_00de731c;
struct Transform;
struct __declspec(align(16)) Vec4 {
    float x,y,z,w;
    Vec4() {}
    Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
    void SetAll(float value) { x=value; y=value; z=value; w=value; }
    Vec4& operator=(const Vec4& o){x=o.x;y=o.y;z=o.z;w=o.w;return *this;}
    void SetSub(const Vec4& a,const Vec4& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
    void SetAdd(const Vec4& a,const Vec4& b){x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w;}
    Vec4 operator-(const Vec4& o)const{return Vec4(x-o.x,y-o.y,z-o.z,w-o.w);}
    Vec4 operator+(const Vec4& o)const{return Vec4(x+o.x,y+o.y,z+o.z,w+o.w);}
    Vec4& operator*=(double value){x=(float)(x*value);y=(float)(y*value);z=(float)(z*value);w=(float)(w*value);return *this;}
    void Subtract(float value){x-=value;y-=value;z-=value;w-=value;}
    void Add(float value){x+=value;y+=value;z+=value;w+=value;}
    void Min(const Vec4& o){if(!(x<o.x))x=o.x;if(!(y<o.y))y=o.y;if(!(z<o.z))z=o.z;if(!(w<o.w))w=o.w;}
    void Max(const Vec4& o){if(!(x>o.x))x=o.x;if(!(y>o.y))y=o.y;if(!(z>o.z))z=o.z;if(!(w>o.w))w=o.w;}
    void hkVector4_setTransformedPos(const Transform* transform,const Vec4* vector);
};
struct Aabb { Vec4 minimum,maximum; void Reset(){minimum.SetAll(DAT_00de6e60);maximum.SetAll(DAT_00de731c);} void Merge(const Aabb& o){minimum.Min(o.minimum);maximum.Max(o.maximum);} };
struct Transform { Vec4 rotation[3],position; void hkRotation_set(const Vec4* quaternion); };
extern const Transform DAT_010f3370;
struct Shape {
    virtual void v00();virtual void v04();virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();
    virtual void GetAabb(const Transform* transform,float tolerance,Aabb* output);
};
struct TrianglePart {
    unsigned int unk00,unk04,unk08,unk0C;
    int count;
    const char* vertices;
    int vertexStride;
    unsigned int unk1C,unk20,unk24,unk28,unk2C;
    const char* indices;
    int indexStride;
    unsigned char format,unk39;
    unsigned short unk3A;
    unsigned int unk3C;
};
struct CompoundPart {
    unsigned int unk00,unk04,unk08,unk0C;
    Shape** shapes;
    int count;
    unsigned int unk18,unk1C;
    Vec4 rotation,translation;
};
static __declspec(noinline) void FUN_009e3220(Aabb* output,const float* vertex,const Vec4* scale,const Transform* transform) {
    Vec4 scaled(vertex[0]*scale->x,vertex[1]*scale->y,vertex[2]*scale->z,0.0f);
    Vec4 point;
    point.hkVector4_setTransformedPos(transform,&scaled);
    output->minimum.Min(point);
    output->maximum.Max(point);
}
static __declspec(noinline) void FUN_009e3540(Aabb* output,const TrianglePart* part,const Vec4* scale) {
    output->Reset();
    for(int i=0;i<part->count;++i){
        const char* indices=part->indices+i*part->indexStride;
        unsigned int a,b,c;
        if(part->format==1){const unsigned short* p=(const unsigned short*)indices;a=p[0];b=p[1];c=p[2];}
        else {const unsigned int* p=(const unsigned int*)indices;a=p[0];b=p[1];c=p[2];}
        const float* first=(const float*)(part->vertices+a*part->vertexStride);
        const float* second=(const float*)(part->vertices+b*part->vertexStride);
        const float* third=(const float*)(part->vertices+c*part->vertexStride);
        FUN_009e3220(output,first,scale,&DAT_010f3370);
        FUN_009e3220(output,second,scale,&DAT_010f3370);
        FUN_009e3220(output,third,scale,&DAT_010f3370);
    }
}
static __declspec(noinline) void FUN_009e3630(Aabb* output,const CompoundPart* part) {
    output->Reset();
    Transform transform;
    transform.position=part->translation;
    transform.hkRotation_set(&part->rotation);
    for(int i=0;i<part->count;++i){
        Aabb bounds;
        part->shapes[i]->GetAabb(&transform,0.0f,&bounds);
        output->Merge(bounds);
    }
}
struct Owner {
    unsigned int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C;
    Vec4 scale,halfExtents,center;
    TrianglePart* triangles;
    int triangleCount;
    CompoundPart* compounds;
    int compoundCount;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    float radius;
    void FUN_009e37e0();
};
// pdb: hkpExtendedMeshShape::recalcAabbExtents | hkpExtendedMeshShape.obj | tesv_win, objopen_prop, low
void Owner::FUN_009e37e0(){
    Vec4 minimum,maximum;
    minimum.SetAll(DAT_00de6e60);
    maximum.SetAll(DAT_00de731c);
    float cachedRadius=radius;
    for(int i=0;i<triangleCount;++i){
        Aabb bounds;
        FUN_009e3540(&bounds,&triangles[i],&scale);
        bounds.minimum.Subtract(cachedRadius);
        bounds.maximum.Add(cachedRadius);
        minimum.Min(bounds.minimum);
        maximum.Max(bounds.maximum);
    }
    for(int i=0;i<compoundCount;++i){
        Aabb bounds;
        FUN_009e3630(&bounds,&compounds[i]);
        minimum.Min(bounds.minimum);
        maximum.Max(bounds.maximum);
    }
    halfExtents.SetSub(maximum,minimum);
    halfExtents*=0.5;
    center.SetAdd(maximum,minimum);
    center*=0.5;
}
}

// @f3 0x009f6380 (community match, verified in this file)
namespace f3m_009f6380 {
struct Obj6380 {
    int unk00;
    unsigned short unk04;
    short unk06;
    void FUN_009f6040();
    Obj6380* FUN_009f6380(int flags);
};
// pdb: hkpConstraintViewer::`scalar deleting destructor' | hkpConstraintViewer.obj | fnv360_0822_retail, vtable, medium
Obj6380* Obj6380::FUN_009f6380(int flags)
{
    FUN_009f6040();
    if (flags & 1) {
        f3m_009ee430::f3m_009ee430::Allocator* allocator = f3m_009ee430::TlsGetValue(DAT_010f3170);
        allocator->FUN_008f6d90(this, unk04, 0x11);
    }
    return this;
}
}   // namespace f3m_009f6380

// @f3 0x009f7ba0 (community match, verified in this file)
namespace f3m_009f7ba0 {
namespace f3m_009f7ba0 {
extern int DAT_01268b54;   // vtable at 0x00e7ce98
struct FinishLoaded {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}

void __cdecl FUN_009f7ba0(f3m_009f7ba0::FinishLoaded* p)
{
    if (p) {
        p->referenceCount = 1;
        p->vtable = &f3m_009f7ba0::DAT_01268b54;
    }
}
}   // namespace f3m_009f7ba0

// @f3 0x009f7b60 (community match, verified in this file)
namespace f3m_009f7b60 {
namespace f3m_009f7b60 {
struct V009f7b60Flag { int m_finishing; };
struct __declspec(align(16)) V009f7b60Vec { float x, y, z, w; };
struct FUN_0090b6c0 {
    void* vtable;
    int unk04[3];
    V009f7b60Vec unk10[31];
    FUN_0090b6c0(V009f7b60Flag flag) throw();
};
// pdb: getVtablehkpEntity | hkpDynamicsReflections.obj | tesv_win, objrun_prop, low
void* FUN_009f7b60()
{
    V009f7b60Flag flag;
    flag.m_finishing = 0;
    FUN_0090b6c0 object(flag);
    return object.vtable;
}
}
}   // namespace f3m_009f7b60

// @f3 0x009f4b30 (community match, verified in this file)
namespace f3m_009f4b30 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D009f4b30Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D009f4b30 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_009f4130();
    D009f4b30* FUN_009f4b30(unsigned int flags);
};
// pdb: hkpRigidBodyInertiaViewer::`scalar deleting destructor' | hkpRigidBodyInertiaViewer.obj | fnv360_0822_retail, vtable, medium
D009f4b30* D009f4b30::FUN_009f4b30(unsigned int flags)
{
    FUN_009f4130();
    if (flags & 1) {
        D009f4b30Heap* heap = (D009f4b30Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x35);
    }
    return this;
}
}

// @f3 0x009f52b0 (community match, verified in this file)
namespace f3m_009f52b0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D009f52b0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D009f52b0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a68740();
    D009f52b0* FUN_009f52b0(unsigned int flags);
};
// pdb: hkpInactiveContactPointViewer::`scalar deleting destructor' | hkpInactiveContactPointViewer.obj | fnv360_0822_retail, vtable, medium
D009f52b0* D009f52b0::FUN_009f52b0(unsigned int flags)
{
    FUN_00a68740();
    if (flags & 1) {
        D009f52b0Heap* heap = (D009f52b0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x35);
    }
    return this;
}
}

// @f3 0x009f5b80 (community match, verified in this file)
namespace f3m_009f5b80 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D009f5b80Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D009f5b80 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_009f5a00();
    D009f5b80* FUN_009f5b80(unsigned int flags);
};
// pdb: hkpConvexRadiusViewer::`scalar deleting destructor' | hkpConvexRadiusViewer.obj | fnv360_0822_retail, vtable, medium
D009f5b80* D009f5b80::FUN_009f5b80(unsigned int flags)
{
    FUN_009f5a00();
    if (flags & 1) {
        D009f5b80Heap* heap = (D009f5b80Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x35);
    }
    return this;
}
}

// @f3 0x009f6ad0 (community match, verified in this file)
namespace f3m_009f6ad0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D009f6ad0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D009f6ad0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_009f6980();
    D009f6ad0* FUN_009f6ad0(unsigned int flags);
};
// pdb: hkpRigidBodyCentreOfMassViewer::`scalar deleting destructor' | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_retail, vtable, medium
D009f6ad0* D009f6ad0::FUN_009f6ad0(unsigned int flags)
{
    FUN_009f6980();
    if (flags & 1) {
        D009f6ad0Heap* heap = (D009f6ad0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x35);
    }
    return this;
}
}

// @f3 0x009f74f0 (community match, verified in this file)
namespace f3m_009f74f0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D009f74f0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D009f74f0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_009f6be0();
    D009f74f0* FUN_009f74f0(unsigned int flags);
};
// pdb: hkpMidphaseViewer::`scalar deleting destructor' | hkpMidphaseViewer.obj | fnv360_0822_retail, vtable, medium
D009f74f0* D009f74f0::FUN_009f74f0(unsigned int flags)
{
    FUN_009f6be0();
    if (flags & 1) {
        D009f74f0Heap* heap = (D009f74f0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x11);
    }
    return this;
}
}

// @f3 0x009f7ae0 (community match, verified in this file)
namespace f3m_009f7ae0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D009f7ae0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D009f7ae0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_009f7600();
    D009f7ae0* FUN_009f7ae0(unsigned int flags);
};
// pdb: hkpBroadphaseViewer::`scalar deleting destructor' | hkpBroadphaseViewer.obj | fnv360_0822_retail, vtable, medium
D009f7ae0* D009f7ae0::FUN_009f7ae0(unsigned int flags)
{
    FUN_009f7600();
    if (flags & 1) {
        D009f7ae0Heap* heap = (D009f7ae0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x11);
    }
    return this;
}
}

// @f3 0x009f4210 (community match, verified in this file)
namespace f3m_009f4210 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct F009f4210Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct F009f4210Base0 { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct F009f4210Base8 { int unk[16]; };
struct FUN_009f40d0 : F009f4210Base0, F009f4210Base8 {
    FUN_009f40d0(void* arg) throw();
    static void* operator new(unsigned int n)
    {
        F009f4210Heap* heap = (F009f4210Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x35);
        ((F009f4210Base0*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
// pdb: hkpRigidBodyInertiaViewer::create | hkpRigidBodyInertiaViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: contexts
F009f4210Base8* FUN_009f4210(void* arg)
{
    return new FUN_009f40d0(arg);
}
}

// @f3 0x009f5010 (community match, verified in this file)
namespace f3m_009f5010 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct F009f5010Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct F009f5010Base0 { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct F009f5010Base8 { int unk[9]; };
struct FUN_009f4bd0 : F009f5010Base0, F009f5010Base8 {
    FUN_009f4bd0(void* arg) throw();
    static void* operator new(unsigned int n)
    {
        F009f5010Heap* heap = (F009f5010Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x35);
        ((F009f5010Base0*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
// pdb: hkpToiContactPointViewer::create | hkpToiContactPointViewer.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: contexts
F009f5010Base8* FUN_009f5010(void* arg)
{
    return new FUN_009f4bd0(arg);
}
}

// @f3 0x009f5160 (community match, verified in this file)
namespace f3m_009f5160 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct F009f5160Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct F009f5160Base0 { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct F009f5160Base8 { int unk[10]; };
struct FUN_009f5110 : F009f5160Base0, F009f5160Base8 {
    FUN_009f5110(void* arg) throw();
    static void* operator new(unsigned int n)
    {
        F009f5160Heap* heap = (F009f5160Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x35);
        ((F009f5160Base0*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
// pdb: hkpInactiveContactPointViewer::create | hkpInactiveContactPointViewer.obj | fnv360_0822_debug, objrun, medium
// pdb params: contexts
F009f5160Base8* FUN_009f5160(void* arg)
{
    return new FUN_009f5110(arg);
}
}

// @f3 0x009f5220 (community match, verified in this file)
namespace f3m_009f5220 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct F009f5220Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct F009f5220Base0 { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct F009f5220Base8 { int unk[10]; };
struct FUN_009f51d0 : F009f5220Base0, F009f5220Base8 {
    FUN_009f51d0(void* arg) throw();
    static void* operator new(unsigned int n)
    {
        F009f5220Heap* heap = (F009f5220Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x35);
        ((F009f5220Base0*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
// pdb: hkpActiveContactPointViewer::create | hkpActiveContactPointViewer.obj | fnv360_0822_debug, objrun, medium
// pdb params: contexts
F009f5220Base8* FUN_009f5220(void* arg)
{
    return new FUN_009f51d0(arg);
}
}

// @f3 0x009f5780 (community match, verified in this file)
namespace f3m_009f5780 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct F009f5780Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct F009f5780Base0 { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct F009f5780Base8 { int unk[13]; };
struct FUN_009f5530 : F009f5780Base0, F009f5780Base8 {
    FUN_009f5530(void* arg) throw();
    static void* operator new(unsigned int n)
    {
        F009f5780Heap* heap = (F009f5780Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x35);
        ((F009f5780Base0*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
// pdb: hkpConvexRadiusViewer::create | hkpConvexRadiusViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: contexts
F009f5780Base8* FUN_009f5780(void* arg)
{
    return new FUN_009f5530(arg);
}
}

// @f3 0x009f6250 (community match, verified in this file)
namespace f3m_009f6250 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct F009f6250Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct F009f6250Base0 { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct F009f6250Base8 { int unk[12]; };
struct FUN_009f5fc0 : F009f6250Base0, F009f6250Base8 {
    FUN_009f5fc0(void* arg) throw();
    static void* operator new(unsigned int n)
    {
        F009f6250Heap* heap = (F009f6250Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x11);
        ((F009f6250Base0*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
// pdb: hkpConstraintViewer::create | hkpConstraintViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: contexts
F009f6250Base8* FUN_009f6250(void* arg)
{
    return new FUN_009f5fc0(arg);
}
}

// @f3 0x009f6a20 (community match, verified in this file)
namespace f3m_009f6a20 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct F009f6a20Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct F009f6a20Base0 { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct F009f6a20Base8 { int unk[13]; };
struct FUN_009f6920 : F009f6a20Base0, F009f6a20Base8 {
    FUN_009f6920(void* arg) throw();
    static void* operator new(unsigned int n)
    {
        F009f6a20Heap* heap = (F009f6a20Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x35);
        ((F009f6a20Base0*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
// pdb: hkpRigidBodyCentreOfMassViewer::create | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_debug, objrun, medium
// pdb params: contexts
F009f6a20Base8* FUN_009f6a20(void* arg)
{
    return new FUN_009f6920(arg);
}
}

// @f3 0x009f6c90 (community match, verified in this file)
namespace f3m_009f6c90 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct F009f6c90Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct F009f6c90Base0 { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct F009f6c90Base8 { int unk[12]; };
struct FUN_009f6b60 : F009f6c90Base0, F009f6c90Base8 {
    FUN_009f6b60(void* arg) throw();
    static void* operator new(unsigned int n)
    {
        F009f6c90Heap* heap = (F009f6c90Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x11);
        ((F009f6c90Base0*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
// pdb: hkpMidphaseViewer::create | hkpMidphaseViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: contexts
F009f6c90Base8* FUN_009f6c90(void* arg)
{
    return new FUN_009f6b60(arg);
}
}

// @f3 0x009f76b0 (community match, verified in this file)
namespace f3m_009f76b0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct F009f76b0Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct F009f76b0Base0 { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct F009f76b0Base8 { int unk[12]; };
struct FUN_009f7580 : F009f76b0Base0, F009f76b0Base8 {
    FUN_009f7580(void* arg) throw();
    static void* operator new(unsigned int n)
    {
        F009f76b0Heap* heap = (F009f76b0Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x11);
        ((F009f76b0Base0*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
// pdb: hkpBroadphaseViewer::create | hkpBroadphaseViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: contexts
F009f76b0Base8* FUN_009f76b0(void* arg)
{
    return new FUN_009f7580(arg);
}
}

// @f3 0x009f7b40 (community match, verified in this file)
namespace f3m_009f7b40 {
struct S9f7b40 {
    int pad[4];
    int __thiscall FUN_0090b6c0(int value);
};

// pdb: finishLoadedObjecthkpEntity | hkpDynamicsReflections.obj | tesv_win, objrun_prop, low
int __cdecl FUN_009f7b40(S9f7b40* param_1)
{
    int result = 1;
    if (param_1)
        result = param_1->FUN_0090b6c0(1);
    return result;
}
}   // namespace f3m_009f7b40

// @f3 0x009f68f0 (community match, verified in this file)
namespace f3m_009f68f0 {
struct Arr9f68f0 {
    int* data;
    int size;
    int cap;
};

struct S9f68f0 {
    int unk00;
    int unk04;
    Arr9f68f0 arr;
    int unk14;
    void __thiscall FUN_009f68f0(int value);
};

void __cdecl FUN_00901f10(Arr9f68f0* arr, int elemSize);

void __thiscall S9f68f0::FUN_009f68f0(int value)
{
    Arr9f68f0* a = &arr;
    if (a->size == (a->cap & 0x3fffffff))
        FUN_00901f10(a, 4);
    a->data[a->size] = value;
    a->size++;
}
}   // namespace f3m_009f68f0

// @f3 0x009f65b0 (community match, verified in this file)
namespace f3m_009f65b0 {
namespace Worker2482 {
template <class T> struct S_00d69fc0_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
                m_data[index] = m_data[m_iElementCount];
    }
};

struct S_00d69fc0_Item;

struct S_00d69fc0
{
    int unk00;
    int unk04;
    S_00d69fc0_Array<S_00d69fc0_Item*> m_items;
    void FUN_009f65b0(S_00d69fc0_Item* item);
};

// Finds item in m_items and, if present, removes it by index.
// @fnv 0x00d69fc0
void S_00d69fc0::FUN_009f65b0(S_00d69fc0_Item* item)
{
    int index = m_items.indexOf(item);
    if (index >= 0)
        m_items.removeAt(index);
}


}
}   // namespace f3m_009f65b0

// @f3 0x009f7600 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009f7600 {
struct FUN_009f7600_Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    struct FUN_009f7600_Item** unk6c;
    int unk70;
};

struct FUN_009f7600_Element {
    virtual void vf00(int value);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};

struct FUN_009f7600_Allocator {
    void FUN_008f6d90(void* p, int bytes, int cls);
};

struct FUN_009f7600_Item {
    void FUN_00902ba0(void* p);
};

extern void* (__stdcall* DAT_00d9b080)(unsigned long);

extern void FUN_00e81384();
extern void FUN_00e81364();
extern void FUN_00e81354();
extern void FUN_00e81344();
extern void FUN_00e80a58();
extern void FUN_00e86eb8();
extern void FUN_00e86e98();
extern void FUN_00e86e88();
extern void FUN_00e86e78();
extern void FUN_00e808e0();
extern void FUN_00dcc494();

class FUN_009f7600_Class {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    FUN_009f7600_Owner* unk24;
    int unk28;
    FUN_009f7600_Element* unk2c;
    int unk30;
    int unk34;

    void FUN_00a64860();
    void FUN_009f7600();
};

// pdb: hkpBroadphaseViewer::~hkpBroadphaseViewer | hkpBroadphaseViewer.obj | fnv360_0822_retail, call_seq, medium
void FUN_009f7600_Class::FUN_009f7600()
{
    unk00 = (int)&FUN_00e81384;
    unk08 = (int)&FUN_00e81364;
    unk20 = (int)&FUN_00e81354;
    unk28 = (int)&FUN_00e81344;

    if (unk24 != 0) {
        for (int i = 0; i < unk24->unk70; ++i) {
            FUN_009f7600_Item* item = unk24->unk6c[i];
            item->FUN_00902ba0(&unk28);
        }
    }

    int count = unk30;
    if (count > 0) {
        int offset = 0;
        do {
            FUN_009f7600_Element* element =
                (FUN_009f7600_Element*)((char*)unk2c + offset);
            element->vf00(0);
            offset += 0x80;
        } while (--count);
    }

    int capacity = unk34;
    if (!(capacity & 0x80000000)) {
        int slots = unk34 & 0x3fffffff;
        void* allocator = DAT_00d9b080(DAT_010f3170);
        ((FUN_009f7600_Allocator*)allocator)->FUN_008f6d90(
            unk2c, slots * 0x80, 0x17);
    }

    unk28 = (int)&FUN_00e80a58;
    FUN_00a64860();
}
}   // namespace f3m_009f7600

// @f3 0x009fcad0 (community match, verified in this file)
namespace f39fcad0 {
struct WriterContext {
int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
int unk40;
int unk44;
int unk48;
int unk4c;
int unk50;
int unk54;
};
struct WriterArgs { void* data; unsigned int index; };
union Arg { unsigned int i; unsigned short s; unsigned char b; void* p; };
struct Record { unsigned char type,flag; unsigned short unused,low,high; Arg data,whole; };
extern double DAT_00e20408;
// pdb: _hkBeginConstraints | hkpBuildJacobianFromAtoms.obj | tesv_win, objrun, medium
static __declspec(noinline) void FUN_009fcad0(WriterContext* source,Record** cursor,WriterArgs args) {
    Record* record=*cursor;
    float value=*(float*)record;
    unsigned int high=source->unk54;
    value+=DAT_00e20408;
    unsigned int low=source->unk50;
    unsigned int whole=source->unk48;
    *(float*)record=value;
    record->low=(unsigned short)low;
    record->high=(unsigned short)high;
    record->data.p=args.data;
    record->type=1;
    record->whole.i=whole;
    record->flag=(unsigned char)args.index;
    *cursor=record+1;
}
void RecordWrite_use(WriterContext* source,Record** cursor,WriterArgs args) { FUN_009fcad0(source,cursor,args); }
}

// @f3 0x009f5b00 (community match, verified in this file)
namespace f3m_009f5b00 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
extern unsigned long DAT_010f3170;
struct FreeElem { FreeElem* m_pNext; };
struct FreeList
{
    FreeElem* m_pHead;
    int m_iNumElem;
    void put(void* p)
    {
        FreeElem* elem = static_cast<FreeElem*>(p);
        FreeElem* head = m_pHead;
        m_iNumElem++;
        elem->m_pNext = head;
        m_pHead = elem;
    }
};
struct ThreadMemory
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    int m_iMaxNumElemsOnFreeList;
    FreeList m_akFreeList[8];
    void FUN_008f6890(int row, void* p, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    void deallocate(void* p, int row, int cls)
    {
        if (m_akFreeList[row].m_iNumElem >= m_iMaxNumElemsOnFreeList)
            FUN_008f6890(row, p, cls);
        else
            m_akFreeList[row].put(p);
    }
};
inline ThreadMemory& GetThreadMemory() { return *(ThreadMemory*)TlsGetValue(DAT_010f3170); }
template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~hkArray()
    {
        if (m_capacityAndFlags >= 0)
            GetThreadMemory().FUN_008f6d90(m_data, (m_capacityAndFlags & 0x3fffffff) * sizeof(T), 0x17);
    }
    void release()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = m_capacityAndFlags & 0x3fffffff;
            ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, capacity * sizeof(T), 0x17);
        }
    }
};
}
struct f3m_009f5b00_Obj
{
    int unk00;
    f3m_009f5b00::hkArray<void*> m_kArray;
    f3m_009f5b00_Obj* FUN_009f5b00(unsigned int flags);
};
f3m_009f5b00_Obj* f3m_009f5b00_Obj::FUN_009f5b00(unsigned int flags)
{
    m_kArray.release();
    if ((flags & 1) && this)
        f3m_009f5b00::GetThreadMemory().deallocate(this, 2, 0x35);
    return this;
}

// @f3 0x009f6980 (community match, verified in this file)
namespace f3m_009f6980 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
extern unsigned long DAT_010f3170;
struct ThreadMemory
{
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
};
template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~hkArray()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = m_capacityAndFlags & 0x3fffffff;
            ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, capacity * sizeof(T), 0x17);
        }
    }
};
struct Children
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68;
    void** m_ppItems;
    int m_iNumItems;
};
struct PrimaryBase
{
    virtual ~PrimaryBase();
    int unk04;
};
struct InterfaceB
{
    virtual void b00();
    int unk04; int unk08; int unk0c; int unk10; int unk14;
};
struct InterfaceC
{
    virtual void c00();
    Children* m_pChildren;
};
struct ParentD
{
    virtual ~ParentD() {}
};
struct InterfaceD : ParentD
{
    virtual ~InterfaceD() {}
};
struct ParentE
{
    virtual ~ParentE() {}
};
struct InterfaceE : ParentE
{
    virtual ~InterfaceE() {}
};
}

class FUN_009f6980 : public f3m_009f6980::PrimaryBase,
                     public f3m_009f6980::InterfaceB,
                     public f3m_009f6980::InterfaceC,
                     public f3m_009f6980::InterfaceD,
                     public f3m_009f6980::InterfaceE
{
  public:
    virtual ~FUN_009f6980();
    void FUN_009f63b0(void* item) throw();
    f3m_009f6980::hkArray<void*> m_kArray;
};

// pdb: hkpRigidBodyCentreOfMassViewer::~hkpRigidBodyCentreOfMassViewer | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_retail, call_seq, medium
FUN_009f6980::~FUN_009f6980()
{
    if (m_pChildren)
    {
        for (int i = 0; i < m_pChildren->m_iNumItems; i++)
            FUN_009f63b0(m_pChildren->m_ppItems[i]);
    }
}

// @f3 0x009f5a00 (community match, verified in this file)
namespace f3m_009f5a00 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
extern unsigned long DAT_010f3170;
struct ThreadMemory
{
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
};
template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~hkArray()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = m_capacityAndFlags & 0x3fffffff;
            ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, capacity * sizeof(T), 0x17);
        }
    }
};
struct Children
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68;
    void** m_ppItems;
    int m_iNumItems;
};
struct PrimaryBase
{
    virtual ~PrimaryBase();
    int unk04;
};
struct InterfaceB
{
    virtual void b00();
    int unk04; int unk08; int unk0c; int unk10; int unk14;
};
struct InterfaceC
{
    virtual void c00();
    Children* m_pChildren;
};
struct ParentD
{
    virtual ~ParentD() {}
};
struct InterfaceD : ParentD
{
    virtual ~InterfaceD() {}
};
struct ParentE
{
    virtual ~ParentE() {}
};
struct InterfaceE : ParentE
{
    virtual ~InterfaceE() {}
};
}

class FUN_009f5a00 : public f3m_009f5a00::PrimaryBase,
                     public f3m_009f5a00::InterfaceB,
                     public f3m_009f5a00::InterfaceC,
                     public f3m_009f5a00::InterfaceD,
                     public f3m_009f5a00::InterfaceE
{
  public:
    virtual ~FUN_009f5a00();
    void FUN_009f59a0(int index) throw();
    f3m_009f5a00::hkArray<void*> m_kArray;
};

// pdb: hkpConvexRadiusViewer::~hkpConvexRadiusViewer | hkpConvexRadiusViewer.obj | fnv360_0822_retail, call_seq, medium
FUN_009f5a00::~FUN_009f5a00()
{
    for (int i = m_kArray.m_size - 1; i >= 0; i--)
        FUN_009f59a0(i);
}

// @f3 0x009f6be0 (community match, verified in this file)
namespace f3m_009f6be0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();
extern unsigned long DAT_010f3170;
struct ThreadMemory
{
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
};
template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline ~hkArray() throw()
    {
        int n = m_size;
        for (int i = 0; i < n; i++)
        {
            T* p = m_data + i;
            p->Destroy(0);
        }
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = m_capacityAndFlags & 0x3fffffff;
            ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(m_data, capacity * sizeof(T), 0x17);
        }
    }
};
struct InterfaceE;
struct Child
{
    void FUN_00902ba0(InterfaceE* listener) throw();
};
struct Elem
{
    virtual void Destroy(int flags) throw();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};
struct Children
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68;
    Child** m_ppItems;
    int m_iNumItems;
};
struct PrimaryBase
{
    virtual ~PrimaryBase();
    int unk04;
};
struct InterfaceB
{
    virtual void b00();
    int unk04; int unk08; int unk0c; int unk10; int unk14;
};
struct InterfaceC
{
    virtual void c00();
    Children* m_pChildren;
};
struct ParentE
{
    virtual ~ParentE() {}
};
struct InterfaceE : ParentE
{
    virtual ~InterfaceE() {}
};
}

class FUN_009f6be0 : public f3m_009f6be0::PrimaryBase,
                     public f3m_009f6be0::InterfaceB,
                     public f3m_009f6be0::InterfaceC,
                     public f3m_009f6be0::InterfaceE
{
  public:
    virtual ~FUN_009f6be0();
    f3m_009f6be0::hkArray<f3m_009f6be0::Elem> m_kArray;
};

// pdb: hkpMidphaseViewer::~hkpMidphaseViewer | hkpMidphaseViewer.obj | fnv360_0822_retail, call_seq, medium
FUN_009f6be0::~FUN_009f6be0()
{
    if (m_pChildren)
    {
        for (int i = 0; i < m_pChildren->m_iNumItems; i++)
            m_pChildren->m_ppItems[i]->FUN_00902ba0(this);
    }
}

// @f3 0x009f50e0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009f50e0 {
namespace f3m_009f50e0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

class hkThreadMemory50e0 {
public:
    void FUN_008f6d90(void* a_pMemory, int a_iBytes, int a_iClass);
};

class hkBaseObject50e0 {
public:
    virtual ~hkBaseObject50e0() {}
};

class hkReferencedObject50e0 : public hkBaseObject50e0 {
public:
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;

    static void operator delete(void* a_pMemory) {
        hkThreadMemory50e0* pMemory = (hkThreadMemory50e0*)TlsGetValue(DAT_010f3170);
        pMemory->FUN_008f6d90(a_pMemory, ((hkReferencedObject50e0*)a_pMemory)->m_memSizeAndFlags, 0x35);
    }
};

class FUN_009f50e0 : public hkReferencedObject50e0 {
public:
    FUN_009f50e0();
    virtual ~FUN_009f50e0();
};

FUN_009f50e0::FUN_009f50e0() {}
}
}   // namespace f3m_009f50e0

// @f3 0x009e4720 (community match, verified in this file)
extern unsigned int DAT_010f3170;
extern char DAT_00e8066c[];
extern char DAT_00e80648[];
namespace f3m_009e4720 {

namespace f3m_009e4720 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

class ThreadMemory
{
public:
    virtual void* Alloc(int align, int size, int cls);
    void FUN_008f6d90(void* p, int bytes, int cls);
    void* FUN_008f6d30(int bytes, int cls);
};

struct Vector4
{
    float x, y, z, w;
    void setZero() { x = y = z = w = 0.0f; }
};

struct Subpart
{
    unsigned char m_type;
    unsigned char m_materialIndexType;
    unsigned short unk02;
    int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vector4 m_offset;
    int unk30;
    int unk34;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char unk3a;
    unsigned char unk3b;
    int unk3c;

    void init()
    {
        m_type = 0;
        m_materialIndexType = 1;
        unk08 = 0;
        unk02 = 0;
        unk0a = 1;
        unk0c = 0;
        unk04 = 0;
        unk39 = 0;
        m_offset.setZero();
    }
};

struct SubpartInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    int unk1c;
    int unk20;
    unsigned short unk24;
    unsigned short unk26;
    int unk28;
    unsigned short unk2c;
    unsigned short unk2e;
    unsigned short unk30;
    unsigned short unk32;
    int unk34;
};

template <typename T>
inline void hkDeallocateChunk(T* const& p, int n, int cls)
{
    ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
    mem->FUN_008f6d90(p, n * sizeof(T), cls);
}

template <typename T>
inline T* hkAllocateChunk(const int& n, int cls)
{
    ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
    return (T*)mem->FUN_008f6d30(n * sizeof(T), cls);
}

struct ShortArray
{
    unsigned short* m_data;
    int m_size;
    int m_capacityAndFlags;

    void init() { m_data = 0; m_size = 0; m_capacityAndFlags = 0x80000000; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }

    static void copy(unsigned short* dst, const unsigned short* src, int n)
    {
        for (int i = 0; i < n; i++)
            dst[i] = src[i];
    }

    __forceinline ShortArray& operator=(const ShortArray& a)
    {
        if (getCapacity() < a.m_size)
        {
            if ((m_capacityAndFlags & 0x80000000) == 0)
            {
                hkDeallocateChunk<unsigned short>(m_data, getCapacity(), 0x17);
            }
            m_data = hkAllocateChunk<unsigned short>(a.m_size, 0x17);
            m_capacityAndFlags = a.m_size | (m_capacityAndFlags & 0x40000000);
        }
        m_size = a.m_size;
        copy(m_data, a.m_data, m_size);
        return *this;
    }
};

struct Cinfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    int unk30;
    SubpartInfo* m_subparts;
    int m_numSubparts;
    int unk3c;
    ShortArray m_shorts;
    unsigned char unk4c;
    unsigned char unk4d;
    unsigned char unk4e;
    unsigned char unk4f;
    float unk50;
};

class Shape
{
public:
    void* m_vptr00;
    short unk04;
    short unk06;
    int unk08;
    int m_type;
    void* m_vptr10;
    int unk14;
    int unk18;
    int unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    Subpart* m_subparts;
    int m_numSubparts;
    int unk58;
    int unk5c;
    ShortArray m_shorts;
    unsigned char unk6c;
    Subpart m_inline;
    float unkb0;

    void FUN_0099f010(int type);
    void FUN_009e37e0();
    Shape* FUN_009e4720(const Cinfo* cinfo);
};

// pdb: hkpExtendedMeshShape::hkpExtendedMeshShape | hkpExtendedMeshShape.obj | fnv360_0822_retail, objrun, high
// pdb params: meshShape
Shape* Shape::FUN_009e4720(const Cinfo* cinfo)
{
    FUN_0099f010(0xf);
    m_vptr00 = DAT_00e8066c;
    m_vptr10 = DAT_00e80648;
    m_shorts.init();
    m_inline.init();
    unk20 = cinfo->unk20;
    unk24 = cinfo->unk24;
    unk28 = cinfo->unk28;
    unk2c = cinfo->unk2c;
    unkb0 = cinfo->unk50;
    unk18 = cinfo->unk30;
    unk6c = cinfo->unk4c;

    m_shorts = cinfo->m_shorts;

    int count = cinfo->m_numSubparts;
    if (count == 1)
    {
        m_subparts = &m_inline;
        m_numSubparts = count;
    }
    else
    {
        ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
        m_subparts = (Subpart*)mem->Alloc(0x40, count << 6, 0x25);
        m_numSubparts = cinfo->m_numSubparts;
    }
    unk58 = 0;
    unk5c = 0;

    for (unsigned int i = 0; (int)i < cinfo->m_numSubparts; i++)
    {
        m_subparts[i].unk10 = cinfo->m_subparts[i].unk1c;
        m_subparts[i].unk04 = cinfo->m_subparts[i].unk20;
        m_subparts[i].unk08 = cinfo->m_subparts[i].unk24;
        m_subparts[i].m_materialIndexType = cinfo->m_subparts[i].unk11;
        m_subparts[i].unk0c = cinfo->m_subparts[i].unk28;
        m_subparts[i].unk02 = cinfo->m_subparts[i].unk2c;
        m_subparts[i].unk0a = cinfo->m_subparts[i].unk30;
        m_subparts[i].unk14 = cinfo->m_subparts[i].unk00;
        m_subparts[i].unk18 = cinfo->m_subparts[i].unk04;
        m_subparts[i].unk1c = cinfo->m_subparts[i].unk08;
        m_subparts[i].unk30 = cinfo->m_subparts[i].unk0c;
        m_subparts[i].unk38 = cinfo->m_subparts[i].unk10;
        m_subparts[i].unk34 = cinfo->m_subparts[i].unk14;
        m_subparts[i].unk3c = cinfo->m_subparts[i].unk34;
        m_subparts[i].m_offset.setZero();
        m_subparts[i].unk39 = cinfo->m_subparts[i].unk18;
    }
    FUN_009e37e0();
    return this;
}

}
}   // namespace f3m_009e4720

// @f3 0x009e4660 (community match, verified in this file)
extern char DAT_00e8066c[];
extern char DAT_00e80648[];
namespace f3m_009e4660 {


struct FUN_009e4660 {
    void* unk00;
    int unk04, unk08, unk0c;
    void* unk10;
    void FUN_0099f010(int);
    int unk14;
    void* unk18;
    int unk1c;
    float unk20, unk24, unk28, unk2c;
    float unk30, unk34, unk38, unk3c;
    float unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68;
    char unk6c, unk6d, unk6e, unk6f;
    char unk70, unk71;
    short unk72;
    int unk74;
    short unk78, unk7a;
    int unk7c, unk80, unk84, unk88, unk8c;
    float unk90, unk94, unk98, unk9c;
    int unka0, unka4;
    char unka8, unka9, unkaa, unkab;
    int unkac;
    float unkb0;

    FUN_009e4660(float value, void* p);
};

// pdb: hkpExtendedMeshShape::hkpExtendedMeshShape | hkpExtendedMeshShape.obj | fnv360_0822_retail, callee_sim, low
// pdb params: radius, numBitsForSubpartIndex
FUN_009e4660::FUN_009e4660(float value, void* p) {
    FUN_0099f010(15);
    volatile FUN_009e4660* t = this;
    float z = 0.0f;
    t->unk00 = (void*)DAT_00e8066c;
    t->unk10 = (void*)DAT_00e80648;
    t->unk68 = 0x80000000;
    t->unk60 = 0;
    t->unk64 = 0;
    t->unk70 = 0;
    t->unk78 = 0;
    t->unk72 = 0;
    t->unk7c = 0;
    t->unk74 = 0;
    t->unka9 = 0;
    t->unk71 = 1;
    t->unk7a = 1;
    t->unk9c = z;
    t->unk98 = z;
    void* q = *(void* volatile*)&p;
    t->unk94 = z;
    t->unk90 = z;
    t->unk20 = 1.0f;
    t->unk24 = 1.0f;
    t->unk28 = 1.0f;
    t->unk2c = 1.0f;
    t->unk50 = 0;
    t->unkb0 = value;
    t->unk54 = 0;
    _ReadWriteBarrier();
    t->unk58 = 0;
    t->unk5c = 0;
    t->unk18 = q;
    t->unk6c = 6;
    float mn = -3.40282e38f;
    t->unk30 = mn; t->unk34 = mn; t->unk38 = mn; t->unk3c = mn;
    t->unk4c = z;
    t->unk48 = z;
    t->unk44 = z;
    t->unk40 = z;
}
}   // namespace f3m_009e4660

// @f3 0x009e8ab0 (community match, verified in this file)
namespace f3m_009e8ab0 {
struct Alloc_9e8ab0 { void FUN_008f6d90(void* p, int bytes, int cls); };
struct hkReferencedObject_9e8ab0
{
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    virtual ~hkReferencedObject_9e8ab0();
    static void operator delete(void* p)
    {
        hkReferencedObject_9e8ab0* b = static_cast<hkReferencedObject_9e8ab0*>(p);
        Alloc_9e8ab0* a = (Alloc_9e8ab0*)f3m_009f13b0::TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(p, b->m_memSizeAndFlags, 0x27);
    }
};
struct FUN_009e8ab0 : hkReferencedObject_9e8ab0
{
    virtual ~FUN_009e8ab0();
};
__declspec(noinline) FUN_009e8ab0::~FUN_009e8ab0() {}
}   // namespace f3m_009e8ab0

// @f3 0x009f4130 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_009f4130 {
namespace cleanup9f4130 {
struct ThreadMemory { void FUN_008f6d90(void* p, unsigned bytes, int tag) throw(); };
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
struct Entity;
struct World {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    Entity** items;
    int count;
};
struct Geometry {
    virtual ~Geometry() throw();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};
template<class T> struct Array {
    T* data;
    int count;
    unsigned capacityAndFlags;
    __forceinline ~Array() {
        int remaining = count;
        if (remaining > 0) {
            int offset = 0;
            do {
                T* element = reinterpret_cast<T*>(reinterpret_cast<char*>(data) + offset);
                element->~T();
                offset += sizeof(T);
            } while (--remaining);
        }
        if (!(capacityAndFlags & 0x80000000)) {
            unsigned capacity = capacityAndFlags & 0x3fffffff;
            ThreadMemory* memory = static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170));
            memory->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
};

}
class D671F0BaseA { public: virtual ~D671F0BaseA() throw(); unsigned short memSizeAndFlags; unsigned short referenceCount; };
class D671F0BaseB { public: virtual void Slot00(); int unk04; int unk08; int unk0c; int unk10; int unk14; };
class D671F0BaseC { public: virtual void Slot00(); cleanup9f4130::World* world; };
class D671F0ListenerA { public: virtual ~D671F0ListenerA() throw() {} };
class D671F0ListenerB { public: virtual ~D671F0ListenerB() throw() {} };
class FUN_00d671f0 : public D671F0BaseA, public D671F0BaseB, public D671F0BaseC, public D671F0ListenerA, public D671F0ListenerB {
public:
    cleanup9f4130::Array<cleanup9f4130::Entity*> objects;
    cleanup9f4130::Array<cleanup9f4130::Geometry> geometry;
    void FUN_009f3e00(cleanup9f4130::Entity* entity) throw();
    virtual ~FUN_00d671f0() throw();
};
// pdb: hkpRigidBodyInertiaViewer::~hkpRigidBodyInertiaViewer | hkpRigidBodyInertiaViewer.obj | fnv360_0822_retail, call_seq, medium
FUN_00d671f0::~FUN_00d671f0() throw()
{
    if (world) {
        int count = world->count;
        for (int index = 0; index < count; ++index)
            FUN_009f3e00(world->items[index]);
    }
}
}   // namespace f3m_009f4130

// @f3 0x009f82f0 (community match, verified in this file)
namespace f3m_009f82f0 {
struct Vec4 {
    float x, y, z, w;
};

struct Transform {
    Vec4 c0, c1, c2, c3;
    __forceinline void transformPos(const Vec4& in, Vec4& out) const {
        float ix = in.x;
        float iy = in.y;
        float iz = in.z;
        out.x = c1.x * iy + c0.x * ix + c2.x * iz + c3.x;
        out.y = c1.y * iy + c0.y * ix + c2.y * iz + c3.y;
        out.z = c1.z * iy + c0.z * ix + c2.z * iz + c3.z;
        out.w = 0.0f;
    }
};

struct Pair {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    Transform* t0;
    Transform* t1;
};

struct Constraint {
    Vec4 unk00;
    Vec4 pivotA;
    Vec4 pivotB;
};

// pdb: setLocalTranslationsFromAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0721_beta, objopen_prop, low
static __declspec(noinline) void FUN_009f82f0(const Constraint* c, Transform* outA, Transform* outB, const Pair* p) {
    p->t0->transformPos(c->pivotA, outA->c3);
    p->t1->transformPos(c->pivotB, outB->c3);
}

void caller(const Constraint* c, Transform* outA, Transform* outB, const Pair* p) {
    FUN_009f82f0(c, outA, outB, p);
}
}   // namespace f3m_009f82f0

// @f3 0x009ed4f0 (community match, verified in this file)
namespace f3m_009ed4f0 {
namespace Support9ED4F0 {
struct Transform;
struct __declspec(align(16)) Vector4 {
    float x,y,z,w;
    __forceinline void Set(const Vector4& other) {
        x=other.x;y=other.y;z=other.z;w=other.w;
    }
    __forceinline void SetRotatedInverseDir(const Transform& transform,const Vector4& direction);
    __forceinline void SetTransformedPos(const Transform& transform,const Vector4& position);
};
struct Transform {
    Vector4 first,second,third,translation;
};
__forceinline void Vector4::SetRotatedInverseDir(const Transform& transform,const Vector4& direction) {
    const float dx=direction.x;
    const float dy=direction.y;
    const float dz=direction.z;
    x=transform.first.x*dx+transform.first.y*dy+transform.first.z*dz;
    y=transform.second.x*dx+transform.second.y*dy+transform.second.z*dz;
    z=transform.third.x*dx+transform.third.y*dy+transform.third.z*dz;
    w=0.0f;
}
__forceinline void Vector4::SetTransformedPos(const Transform& transform,const Vector4& position) {
    const float px=position.x;
    const float py=position.y;
    const float pz=position.z;
    x=transform.first.x*px+transform.second.x*py+transform.third.x*pz+transform.translation.x;
    y=transform.first.y*px+transform.second.y*py+transform.third.y*pz+transform.translation.y;
    z=transform.first.z*px+transform.second.z*py+transform.third.z*pz+transform.translation.z;
    w=position.w;
}
struct ConvexShape {
    virtual void Slot00() const=0;
    virtual void Slot04() const=0;
    virtual void Slot08() const=0;
    virtual void Slot0C() const=0;
    virtual void Slot10() const=0;
    virtual void Slot14() const=0;
    virtual void Slot18() const=0;
    virtual void Slot1C() const=0;
    virtual void Slot20() const=0;
    virtual void Slot24() const=0;
    virtual void Slot28() const=0;
    virtual void Slot2C() const=0;
    virtual void GetSupportingVertex(const Vector4& direction,Vector4& vertex) const=0;
};
struct TransformedShape : ConvexShape {
    int unk04,unk08,unk0c,unk10,unk14;
    const ConvexShape* child;
    int unk1c;
    Transform transform;
    void FUN_009ed4f0(const Vector4& direction,Vector4& vertex) const;
};
void TransformedShape::FUN_009ed4f0(const Vector4& direction,Vector4& vertex) const {
    Vector4 localDirection;
    const ConvexShape* shape=child;
    localDirection.SetRotatedInverseDir(transform,direction);
    Vector4 localVertex;
    shape->GetSupportingVertex(localDirection,localVertex);
    Vector4 worldVertex;
    worldVertex.SetTransformedPos(transform,localVertex);
    vertex.Set(worldVertex);
}
}
}   // namespace f3m_009ed4f0

// @f3 0x009e4c80 (community match, verified in this file)
extern float g_009e3540_init;
extern int g_009e3540_tbl;
namespace f3m_009e4c80 {
struct __declspec(align(16)) unkBox {
    float v[8];
};

struct unkHolder {
    int unk00, unk04, unk08, unk0c;
};

struct unkHelper {
    int unk00, unk04, unk08, unk0c;
    int count;
    int base;
    int scale;
    int unk1c;
    int unk20, unk24, unk28, unk2c;
    unsigned char* data;
    int stride;
    unsigned char shortIdx;
    void FUN_009d5e10(int a);
};

void FUN_009e3220(unkHolder* o, int idx, int* tbl);

static __declspec(noinline) void FUN_009e3540(unkBox& box, unkHelper* h, unkHolder* o)
{
    box.v[0] = g_009e3540_init;
    box.v[1] = g_009e3540_init;
    box.v[2] = g_009e3540_init;
    box.v[3] = g_009e3540_init;
    box.v[4] = -box.v[0];
    box.v[5] = -box.v[1];
    box.v[6] = -box.v[2];
    box.v[7] = -box.v[3];
    for (int i = 0; i < h->count; i++) {
        unsigned char* p = h->data + h->stride * i;
        int a, b, c;
        if (h->shortIdx == 1) {
            a = ((unsigned short*)p)[0] * h->scale + h->base;
            b = ((unsigned short*)p)[1] * h->scale + h->base;
            c = ((unsigned short*)p)[2] * h->scale + h->base;
        } else {
            a = ((int*)p)[0] * h->scale + h->base;
            b = ((int*)p)[1] * h->scale + h->base;
            c = ((int*)p)[2] * h->scale + h->base;
        }
        FUN_009e3220(o, a, &g_009e3540_tbl);
        FUN_009e3220(o, b, &g_009e3540_tbl);
        FUN_009e3220(o, c, &g_009e3540_tbl);
    }
}

struct FUN_009e4c80_cls {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    unkHolder unk20;
    float ext[4];
    float ctr[4];
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unkA0, unkA4, unkA8, unkAc;
    float unkB0;
    unkHelper* FUN_009e4bb0();
    void FUN_009e4c80(int a);
};

void FUN_009e4c80_cls::FUN_009e4c80(int a)
{
    unkHelper* h = FUN_009e4bb0();
    h->FUN_009d5e10(a);
    float lo[4];
    float hi[4];
    lo[0] = ctr[0] - ext[0];
    lo[1] = ctr[1] - ext[1];
    lo[2] = ctr[2] - ext[2];
    lo[3] = ctr[3] - ext[3];
    hi[0] = ctr[0] + ext[0];
    hi[1] = ctr[1] + ext[1];
    hi[2] = ctr[2] + ext[2];
    hi[3] = ctr[3] + ext[3];
    unkBox box;
    FUN_009e3540(box, h, &unk20);
    float m = unkB0;
    for (int i = 0; i < 4; i++) {
        box.v[i] = box.v[i] - m;
    }
    for (int i = 0; i < 4; i++) {
        box.v[i + 4] = box.v[i + 4] + m;
    }
    for (int i = 0; i < 4; i++) {
        if (!(lo[i] < box.v[i])) lo[i] = box.v[i];
    }
    for (int i = 0; i < 4; i++) {
        if (!(hi[i] > box.v[i + 4])) hi[i] = box.v[i + 4];
    }
    for (int i = 0; i < 4; i++) {
        ext[i] = hi[i] - lo[i];
    }
    for (int i = 0; i < 4; i++) {
        ext[i] = ext[i] * 0.5;
    }
    for (int i = 0; i < 4; i++) {
        ctr[i] = hi[i] + lo[i];
    }
    for (int i = 0; i < 4; i++) {
        ctr[i] = ctr[i] * 0.5;
    }
}
}   // namespace f3m_009e4c80

// @f3 0x009eab50 (community match, verified in this file)
#include <math.h>
namespace f3m_009eab50 {

struct __declspec(align(16)) Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct __declspec(align(16)) hkVector4 {
    float x, y, z, w;
    hkVector4() {}
    hkVector4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void operator=(const hkVector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    hkVector4 operator-(const hkVector4& o) const { return hkVector4(x - o.x, y - o.y, z - o.z, w - o.w); }
    hkVector4 operator+(const hkVector4& o) const { return hkVector4(x + o.x, y + o.y, z + o.z, w + o.w); }
    hkVector4 operator*(float s) const { return hkVector4(x * s, y * s, z * s, w * s); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 xyz() const { return Vec3(x, y, z); }
    float Length3() const { return sqrtf(x * x + y * y + z * z); }
};

struct __declspec(align(16)) Sphere {
    float x, y, z, radius;
    Sphere& operator=(const Sphere& o) { x = o.x; y = o.y; z = o.z; radius = o.radius; return *this; }
    void SetCenter(const Vec3& c) { x = c.x; y = c.y; z = c.z; }
    void Set(const hkVector4& v) { x = v.x; y = v.y; z = v.z; radius = v.w; }
};

inline Vec3 operator-(const hkVector4& a, const Sphere& b) { return Vec3(a.x - b.x, a.y - b.y, a.z - b.z); }

static __declspec(noinline) Sphere FUN_009ea460(const hkVector4& b, const hkVector4& a, float r)
{
    Sphere s;
    hkVector4 half = (a - b) * 0.5f;
    hkVector4 center = b + half;
    s.Set(center);
    s.radius = half.Length3() + r;
    return s;
}

static __declspec(noinline) Sphere FUN_009ea550(const hkVector4& c, const hkVector4& b, const hkVector4& a, float r)
{
    Sphere s;
    Vec3 e2 = b - c.xyz();
    Vec3 e1 = a - c.xyz();
    float d11 = e1.x * e1.x + e1.y * e1.y + e1.z * e1.z;
    float d22 = e2.x * e2.x + e2.y * e2.y + e2.z * e2.z;
    float d12 = e1.x * e2.x + e1.y * e2.y + e1.z * e2.z;
    float inv = 0.5f / (d11 * d22 - d12 * d12);
    float k1 = (d11 - d12) * d22 * inv;
    float k2 = (d22 - d12) * d11 * inv;
    hkVector4 off(e1.x * k1 + e2.x * k2, e1.y * k1 + e2.y * k2, e1.z * k1 + e2.z * k2, 0.0f);
    hkVector4 center = c;
    center = center + off;
    s.Set(center);
    s.radius = off.Length3() + r;
    return s;
}

static __declspec(noinline) Sphere FUN_009ea810(const hkVector4& d, const hkVector4& c, const hkVector4& b, const hkVector4& a, float r)
{
    Sphere s;
    Vec3 e3 = c - d.xyz();
    Vec3 e2 = b - d.xyz();
    Vec3 e1 = a - d.xyz();
    float det = e1.x * (e2.y * e3.z - e2.z * e3.y) - e1.y * (e2.x * e3.z - e2.z * e3.x) + e1.z * (e2.x * e3.y - e2.y * e3.x);
    float inv = 0.5f / det;
    float l1 = e1.x * e1.x + e1.y * e1.y + e1.z * e1.z;
    float l2 = e2.x * e2.x + e2.y * e2.y + e2.z * e2.z;
    float l3 = e3.x * e3.x + e3.y * e3.y + e3.z * e3.z;
    hkVector4 off(l1 * inv * e3.x + l2 * inv * e1.x, l2 * inv * e2.y + l3 * inv * e1.y, l3 * inv * e3.z + l1 * inv * e2.z, 0.0f);
    hkVector4 center = d;
    center = center + off;
    s.Set(center);
    s.radius = off.Length3() + r;
    return s;
}
// pdb: miniSphereRecurseCall | hkGeometryUtility.obj | tesv_win, call_seq, medium
Sphere FUN_009eab50(hkVector4* pts, int n, unsigned int level, float t)
{
    Sphere s;
    switch (level) {
    case 0:
        s.SetCenter(Vec3(0.0f, 0.0f, 0.0f));
        s.radius = -1.0f;
        break;
    case 1:
        s.SetCenter(pts[-1].xyz());
        s.radius = t;
        break;
    case 2:
        s = FUN_009ea460(pts[-1], pts[-2], t);
        break;
    case 3:
        s = FUN_009ea550(pts[-1], pts[-2], pts[-3], t);
        break;
    default:
        s = FUN_009ea810(pts[-1], pts[-2], pts[-3], pts[-4], t);
        return s;
    }
    for (int i = 0; i < n; i++) {
        if ((pts[i] - s).Length() > s.radius) {
            for (int j = i; j > 0; j--) {
                hkVector4 tmp = pts[j];
                pts[j] = pts[j - 1];
                pts[j - 1] = tmp;
            }
            s = FUN_009eab50(pts + 1, i, level + 1, t);
        }
    }
    return s;
}
}   // namespace f3m_009eab50

// @f3 0x009f33f0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace S9f33f0_ns {

extern const char DAT_00e80bd4[];
extern const char DAT_00e80e04[];

struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
__declspec(dllimport) Alloc* __stdcall FUN_00d9b080(unsigned int) throw();

struct Item {
    virtual void Dtor(int flag) throw();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    int unk50;
};

struct IntArr {
    unsigned int unk00;
    unsigned int unk04;
    int* data;
    int count;
    int IndexOf(int t) {
        for (int i = 0; i < count; ++i)
            if (data[i] == t) return i;
        return -1;
    }
};
extern IntArr* DAT_01169808;

struct Arg {
    virtual void V0() throw();
    virtual void V4() throw();
    virtual void V8() throw();
    virtual void Vc() throw();
    virtual void V10() throw();
    virtual int GetType() throw();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

template <class T> struct S9f33f0_Array {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    S9f33f0_Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    void Release() {
        if (!(m_capacityAndFlags & 0x80000000)) {
            int cap = m_capacityAndFlags & 0x3fffffff;
            Alloc* a = FUN_00d9b080(DAT_010f3170);
            a->FUN_008f6d90(m_data, cap * sizeof(T), 0x17);
        }
    }
};

struct PtrArr {
    Item** data;
    int count;
    unsigned int cap;
};

struct ObjA { unsigned int unk00; unsigned int unk04; void FUN_00a655a0() throw(); };
struct ObjB {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0c; unsigned int unk10;
    void FUN_00a655b0(ObjA* a) throw();
    void FUN_00a66d50(unsigned int v, S9f33f0_Array<Item*>* out) throw();
};
struct StrB {
    unsigned int unk00; unsigned int unk04; unsigned int unk08;
    void FUN_00923070(unsigned int* buf, int n) throw();
    void FUN_00943710(const char* s) throw();
    void FUN_00943a60() throw();
};
struct Logger {
    virtual void V0() throw();
    virtual void V4() throw();
    virtual void V8() throw();
    virtual void Log(int a, int b, unsigned int* c, const char* d, int e) throw();
};
extern Logger* DAT_010f3364;

struct Sink {
    virtual void V0() throw();
    virtual void Call4(S9f33f0_Array<Item*>* out, unsigned int a, void* p, unsigned int b, unsigned int c) throw();
    virtual void V8() throw();
    virtual void CallC(unsigned int a, void* p, unsigned int b) throw();
};
extern unsigned int DAT_0116980c;
extern unsigned int DAT_01169810;

void FUN_00901f10(PtrArr* a, int n) throw();

struct Owner {
    unsigned int unk04;
    unsigned int unk08;
    PtrArr arr;
    void FUN_009f33f0(Arg* o);
};

// pdb: hkpPhantomDisplayViewer::phantomAddedCallback | hkpPhantomDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: phantom
void Owner::FUN_009f33f0(Arg* o) {
    unsigned int v = o->unk10;
    unsigned int* pv = &o->unk10;
    int t = o->GetType();
    S9f33f0_Array<Item*> local;
    bool ok = true;
    if (t != 1 && t != 2) {
        int idx = DAT_01169808->IndexOf(t);
        ok = (idx != -1);
    }
    if (ok && v != 0) {
        ObjA a; a.FUN_00a655a0();
        ObjB b; b.FUN_00a655b0(&a);
        b.FUN_00a66d50(v, &local);
        for (int i = local.m_size - 1; i >= 0; --i) {
            Item* it = local.m_data[i];
            if (it->unk50 == 6 && it->unk08 == 0) {
                unsigned int buf[128];
                StrB s; s.FUN_00923070(buf, 0x200);
                s.FUN_00943710(DAT_00e80bd4);
                DAT_010f3364->Log(0, -1, buf, DAT_00e80e04, 0x92);
                s.FUN_00943a60();
                local.m_data[i] = local.m_data[--local.m_size];
            }
        }
        PtrArr* p = &arr;
        if (p->count == (int)(arr.cap & 0x3fffffff))
            FUN_00901f10(p, 4);
        p->data[p->count] = (Item*)o;
        p->count++;
        Sink* sk = *(Sink**)((char*)this - 0x10);
        sk->Call4(&local, pv[2], pv, DAT_0116980c, v);
        sk = *(Sink**)((char*)this - 0x10);
        sk->CallC(DAT_01169810, pv, DAT_0116980c);
        for (int j = 0; j < local.m_size; ++j) {
            Item* it = local.m_data[j];
            if (it)
                it->Dtor(1);
        }
    }
    local.Release();
}

}

// @f3 0x009f7bd0 (community match, verified in this file)
#include <math.h>
extern int DAT_01268798;
namespace f3m_009f7bd0 {

namespace S009f7bd0 {

struct __declspec(align(16)) S009f7bd0_Vec4 {
    float x, y, z, w;
    void operator=(const S009f7bd0_Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    void setSub4(const S009f7bd0_Vec4& a, const S009f7bd0_Vec4& b)
    {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
    float lengthSquared3() const { return x * x + y * y + z * z; }
    float length3() const { return (float)sqrt(lengthSquared3()); }
    void mul4(float s) { float t = s; x *= t; y *= t; z *= t; w *= t; }
};

struct S009f7bd0_Body {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    S009f7bd0_Vec4 m_pos;
};

struct S009f7bd0_Param {
    int unk00;
    float m_radius;
};

struct S009f7bd0_Pair {
    S009f7bd0_Vec4 m_posA;
    S009f7bd0_Vec4 m_posB;
    S009f7bd0_Vec4 m_normal;
};

}

using namespace S009f7bd0;

extern "C" void __cdecl FUN_00a4f230(S009f7bd0_Pair* pair, int a, void* b, float dist);

static __declspec(noinline) void FUN_009f7bd0(S009f7bd0_Body* self, S009f7bd0_Body* other,
                                              S009f7bd0_Param* param, int a, void* b)
{
    S009f7bd0_Pair pair;
    pair.m_posA = self->m_pos;
    pair.m_posB = other->m_pos;
    S009f7bd0_Vec4 dir;
    dir.setSub4(pair.m_posA, pair.m_posB);
    float len = dir.length3();
    dir.mul4(1.0f / len);
    float dist = len;
    if (len > 0.0f) {
        pair.m_normal = dir;
    } else {
        pair.m_normal = *(const S009f7bd0_Vec4*)&DAT_01268798;
        dist = 0.0f;
    }
    FUN_00a4f230(&pair, a, b, param->m_radius - dist);
}

volatile int g_009f7bd0_in;
void S009f7bd0_caller()
{
    FUN_009f7bd0((S009f7bd0_Body*)g_009f7bd0_in, (S009f7bd0_Body*)g_009f7bd0_in,
                 (S009f7bd0_Param*)g_009f7bd0_in, g_009f7bd0_in, (void*)g_009f7bd0_in);
}
}   // namespace f3m_009f7bd0

// @f3 0x009ee3d0 (community match, verified in this file)
namespace Init9ee3d0 {
extern char DAT_00e35eec,DAT_00e8088c,DAT_00e80864;
struct Object {void* volatile vtable;volatile unsigned short unk04,refs;volatile int zero,type;volatile float scalar;void* volatile table;volatile float factor;int unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40;volatile int data,count;volatile unsigned capacity;void hkpConvexListShape_setShapesAndRadius(void*,void*);void hkpConvexListShape_setUseCachedAabb(int);Object* FUN_009ee3d0(void*,void*);};
// pdb: hkpConvexListShape::hkpConvexListShape | hkpConvexListShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: shapeArray, numShapes
Object* Object::FUN_009ee3d0(void* a,void* b){scalar=0;zero=0;refs=1;type=0x15;table=&DAT_00e35eec;vtable=&DAT_00e8088c;table=&DAT_00e80864;data=0;count=0;capacity=0x80000000u;factor=1;hkpConvexListShape_setShapesAndRadius(a,b);hkpConvexListShape_setUseCachedAabb(1);return this;}
}

// @f3 0x009f2f50 (community match, verified in this file)
namespace Destroy338 {
extern void* const DAT_00e80d3c[],*const DAT_00e80d1c[],*const DAT_00e80d0c[],*const DAT_00e80cf4[],*const DAT_00e80ce4[],*const DAT_00e80a58[],*const DAT_00dcd094[];extern unsigned DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned);struct Heap{void FUN_008f6d90(void*,unsigned,int) throw();};struct Array{void* data;int size;unsigned capacity;void FUN_00922cf0() throw();};
struct Base0{virtual ~Base0() throw();int unk04;};struct Base8{virtual void v8();int unk0c,unk10,unk14,unk18,unk1c;};struct Base20{virtual void v20();int unk24;};struct Base28{virtual ~Base28() throw(){}};struct Base2c{virtual ~Base2c() throw(){}};struct FUN_009f2f50:Base0,Base8,Base20,Base28,Base2c {virtual void v8();virtual void v20();void* data;int count;unsigned flags;Array a,b,c;void FUN_009f2ef0(int) throw();void FUN_00a64860();virtual ~FUN_009f2f50() throw();};
// pdb: hkpShapeDisplayViewer::~hkpShapeDisplayViewer | hkpShapeDisplayViewer.obj | fnv360_0822_retail, call_seq, medium
FUN_009f2f50::~FUN_009f2f50() throw(){for(int i=count-1;i>=0;--i)FUN_009f2ef0(i);c.FUN_00922cf0();b.FUN_00922cf0();a.FUN_00922cf0();if(!(flags&0x80000000)){unsigned capacity=flags&0x3fffffff;Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(data,capacity*4,23);}}
}

// @f3 0x009f86b0 (community match, verified in this file)
extern unsigned char DAT_00e817d8[];
namespace f3m_009f86b0 {

namespace f3m_009f86b0 {

struct Vec4 {
    float x, y, z, w;
};

struct __declspec(align(16)) Planes {
    Vec4 a;
    Vec4 b;
    Vec4 c;
};

struct Info {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char start;
    unsigned char count;
};

void __cdecl FUN_00a4e410(Planes* planes, int arg1, int arg3);

inline void Copy(Vec4& d, const Vec4& s) { d.x = s.x; d.y = s.y; d.z = s.z; d.w = s.w; }
inline const Vec4& At(const char* base, unsigned int off) { return *(const Vec4*)(base + off); }

// pdb: buildJacobianFromAngAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0721_beta, objrun_prop, low
static __declspec(noinline) void FUN_009f86b0(const Info* info, int arg1, const char* base, const char* p10, int arg3)
{
    for (int i = info->start; i < info->start + info->count; ++i) {
        Planes planes;
        Copy(planes.b, At(base, DAT_00e817d8[i]));
        Copy(planes.a, At(base, DAT_00e817d8[i + 1]));
        Copy(planes.c, At(p10, DAT_00e817d8[i + 2]));
        FUN_00a4e410(&planes, arg1, arg3);
    }
}

const Info* volatile g_info;
volatile int g_arg1;
const char* volatile g_base;
const char* volatile g_p10;
volatile int g_arg3;

void Caller_009f86b0()
{
    FUN_009f86b0(g_info, g_arg1, g_base, g_p10, g_arg3);
}

}
}   // namespace f3m_009f86b0

// @f3 0x009e8910 (community match, verified in this file)
extern char DAT_0126905c;
namespace f3m_009e8910 {
namespace ns_009e8910 {

struct Vec4 {
    float x, y, z, w;
    void SetSub(const Vec4& a, const Vec4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    void SetAdd(const Vec4& a, const Vec4& b)
    {
        const float* pa = &a.x;
        const float* pb = &b.x;
        x = pa[0] + pb[0];
        y = pa[1] + pb[1];
        z = pa[2] + pb[2];
        w = pa[3] + pb[3];
    }
    void Multiply(float v)
    {
        x = x * (double)v;
        y = y * (double)v;
        z = z * (double)v;
        w = w * (double)v;
    }
};

struct Bounds380 {
    Vec4 minimum;
    Vec4 maximum;
};

struct TransposedPoints380;
struct Vector380;

struct Vertices380 {
    TransposedPoints380* data;
    int size;
    int capacity;
    Vertices380(TransposedPoints380* p, int count)
        : data(p), size(((count + 3) & ~3) / 4), capacity(size | 0x80000000) {}
};

struct Planes380 {
    Vector380* data;
    int size;
    int capacity;
    Planes380(Vector380* p, int n) : data(p), size(n), capacity(n | 0x80000000) {}
};

struct ConvexBase380 {
    void* vtable;
    unsigned short memSizeAndFlags;
    short references;
    int userData;
    int type;
    float radius;
    int pad14, pad18, pad1c;

    ConvexBase380(float r)
    {
        references = 1;
        radius = r;
        userData = 0;
        type = 7;
    }
};

struct FUN_009e8910 : ConvexBase380 {
    Vec4 halfExtents;
    Vec4 center;
    Vertices380 vertices;
    int vertexCount;
    Planes380 planes;
    void* connectivity;

    FUN_009e8910(TransposedPoints380* vertexData, int count, Vector380* planeData, int planeCount,
                 const Bounds380& bounds, float r);
};

FUN_009e8910::FUN_009e8910(TransposedPoints380* vertexData, int count, Vector380* planeData, int planeCount,
                           const Bounds380& bounds, float r)
    : ConvexBase380(r),
      vertices((vtable = &::DAT_0126905c, vertexData), count),
      vertexCount(count),
      planes(planeData, planeCount),
      connectivity(0)
{
    halfExtents.SetSub(bounds.maximum, bounds.minimum);
    halfExtents.Multiply(0.5f);
    center.SetAdd(bounds.minimum, bounds.maximum);
    center.Multiply(0.5f);
}

}
}   // namespace f3m_009e8910

// @f3 0x009e09b0 (community match, verified in this file)
extern void* DAT_00e803e0[];
extern const float DAT_00e010dc;
namespace f3m_009e09b0 {
namespace c3_009e09b0 {


struct Vector4
{
    float x, y, z, w;

    float& operator()(int i)
    {
        return (&x)[i];
    }

    void setZero4()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
};

struct Matrix3
{
    Vector4 m_col0;
    Vector4 m_col1;
    Vector4 m_col2;

    void setZero()
    {
        m_col0.setZero4();
        m_col1.setZero4();
        m_col2.setZero4();
    }

    float& operator()(int row, int col)
    {
        return (&m_col0)[col](row);
    }

    void setIdentity()
    {
        setZero();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};

struct ConstraintBase
{
    void** m_vptr;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;

    ConstraintBase()
    {
        m_vptr = DAT_00e803e0;
        m_08 = 0;
        m_06 = 1;
    }
};

struct Atom
{
    unsigned short m_type;
    Atom(unsigned short type) : m_type(type) {}
};

struct RotationsAtom : Atom
{
    unsigned short m_pad02;
    int m_04;
    int m_08;
    int m_0C;
    Matrix3 m_rotationA;
    Matrix3 m_rotationB;
    RotationsAtom() : Atom(4) {}
};

struct TwistLimitAtom : Atom
{
    unsigned char m_isEnabled;
    unsigned char m_twistAxis;
    float m_minAngle;
    float m_maxAngle;
    float m_angularLimitsTauFactor;
    TwistLimitAtom() : Atom(0xe) { m_isEnabled = 1; }
};

struct FrictionAtom : Atom
{
    unsigned char m_isEnabled;
    FrictionAtom() : Atom(0xc) {}
};


struct FUN_009e09b0 : ConstraintBase
{
    int m_0C;
    RotationsAtom m_rotations;
    TwistLimitAtom m_twist;
    FrictionAtom m_friction;

    FUN_009e09b0();
};

// pdb: hkpHingeLimitsData::hkpHingeLimitsData | hkpHingeLimitsData.obj | tesv_win, callee_sim, low
FUN_009e09b0::FUN_009e09b0()
{
    m_rotations.m_rotationA.setIdentity();
    m_rotations.m_rotationB.setIdentity();
    m_friction.m_isEnabled = 0;
    m_twist.m_minAngle = DAT_00e010dc;
    m_twist.m_twistAxis = 0;
    m_twist.m_maxAngle = 3.14159265f;
    m_twist.m_angularLimitsTauFactor = 1.0f;
}

}
}   // namespace f3m_009e09b0

// @f3 0x009e0500 (community match, verified in this file)
namespace f3m_009e0500 {
namespace Small546 {
void __cdecl FUN_00901f10(void*,int);
struct __declspec(align(16)) Vector {float x,y,z,w;Vector(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}void operator=(const Vector& p){x=p.x;y=p.y;z=p.z;w=p.w;}};
struct IntArray {int* data;int size,capacity;void Add(const int& x){if(size==(capacity&0x3fffffff))FUN_00901f10(this,4);data[size]=x;++size;}};
struct VecArray {Vector* data;int size,capacity;void Add(const Vector& x){if(size==(capacity&0x3fffffff))FUN_00901f10(this,16);data[size++]=x;}};
struct Writer {unsigned unk00,unk04,unk08,unk0c;VecArray vectors;IntArray ops;};
struct Owner {unsigned unk00;Writer* writer;int count;int FUN_009e0500(float);};
// pdb: hkpConstraintConstructionKit::constrainAllLinearDof | hkpConstraintConstructionKit.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
int Owner::FUN_009e0500(float value){++count;writer->ops.Add(0x16);int result=writer->vectors.size;writer->vectors.Add(Vector(value,0.0f,0.0f,0.0f));return result;}
}
}   // namespace f3m_009e0500

// @f3 0x009e86c0 (community match, verified in this file)
extern const char DAT_00e8073c[],DAT_00e80734[];
namespace f3m_009e86c0 {
namespace match644 {
struct Array {void* data;int count;unsigned capacity;};
struct Shape {
 unsigned u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24,u28,u2c,u30,u34,u38,u3c;
 Array first;unsigned u4c;Array second;
 void FUN_009e86c0(ObjectVisitor*);
};
// pdb: hkpConvexVerticesShape::hkpConvexVerticesShape | hkpConvexVerticesShape.obj | fnv360_0822_retail, objrun, high
// pdb params: radius
void Shape::FUN_009e86c0(ObjectVisitor* visitor){
 visitor->Begin(DAT_00e8073c,1,this);
 if(!(first.capacity&0x80000000u))visitor->Array(DAT_00e80734,1,first.data,first.count*48,(first.capacity&0x3fffffffu)*48);
 if(!(second.capacity&0x80000000u))visitor->Array(DAT_00e80734,1,second.data,second.count*16,(second.capacity&0x3fffffffu)*16);
 visitor->End();
}
}
}   // namespace f3m_009e86c0

// @f3 0x009efa60 (community match, verified in this file)
namespace f3m_009efa60 {
namespace match645 {
struct Batch {
 virtual void DeleteThis(int);
 unsigned short memorySize;short references;
 unsigned u08,u0c,u10,u14,u18,u1c;
 void** items;int count;
 void Release(){if(memorySize && --references==0)DeleteThis(1);}
};
struct Listener {virtual void slot0();virtual void Add(void*);};
struct World {void FUN_00903a60(Listener*);void FUN_00903be0(void**);Batch* FUN_009035e0();};
struct Primary {virtual void slot0();unsigned u04,u08,u0c,u10,u14,u18,u1c;};
struct Secondary {virtual void slot0();unsigned u24;Listener listener;void* other;void FUN_009efa60(World*);};
struct Owner:Primary,Secondary {};
// pdb: hkpVehicleViewer::worldAddedCallback | hkpVehicleViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: w
void Secondary::FUN_009efa60(World* world){
 Owner* owner=reinterpret_cast<Owner*>(reinterpret_cast<char*>(this)-sizeof(Primary));
 world->FUN_00903a60(owner?&listener:0);
 world->FUN_00903be0(owner?&other:0);
 Batch* batch=world->FUN_009035e0();
 for(int i=0;i<batch->count;++i)listener.Add(batch->items[i]);
 batch->Release();
}
}

}   // namespace f3m_009efa60

// @f3 0x009ed820 (community match, verified in this file)
namespace f3m_009ed820 {
namespace f3m_9ed820 {
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};

class Inner18 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void GetPos(Vec4* out);
};

struct Owner9ed820 {
    int m_00, m_04, m_08, m_0c, m_10, m_14;
    Inner18* m_18;
    int m_1c;
    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;
    Vec4 m_pos;

    void FUN_009ed820(Vec4* out);
};

// pdb: hkpConvexTransformShape::getSupportingVertexImpl | hkpConvexTransformShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: direction, supportingVertexOut
void Owner9ed820::FUN_009ed820(Vec4* out)
{
    Vec4 p;
    m_18->GetPos(&p);
    out->x = m_col0.x * p.x + m_col1.x * p.y + m_col2.x * p.z + m_pos.x;
    out->y = m_col0.y * p.x + m_col1.y * p.y + m_col2.y * p.z + m_pos.y;
    out->z = m_col0.z * p.x + m_col1.z * p.y + m_col2.z * p.z + m_pos.z;
    out->w = 0.0f;
}
}

}   // namespace f3m_009ed820

// @f3 0x009e2090 (community match, verified in this file)
namespace f3m_009e2090 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
struct ThreadMemoryView { void FUN_008f6d90(void*,int,int); };
struct __declspec(align(16)) BoundsView { float lo[4];float hi[4]; };
struct __declspec(align(16)) Vec4 { float v[4]; };
struct QuantizationDescriptor {
    int unk00;int unk04;int unk08;int unk0c;
    float x,y,z,w;
    void* data;int count;int capacity;
};
struct IndexArray { void* data;int size;int capacity; };
struct __declspec(align(16)) QueryResult {
    IndexArray* output;
    int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;
    void FUN_00a52f70(QuantizationDescriptor*,BoundsView*,IndexArray*);
};
struct DescriptorBuffer {
    int buffer[16];
    QuantizationDescriptor& get(){return *(QuantizationDescriptor*)(((unsigned int)buffer+15)&~15u);}
};
inline QuantizationDescriptor& alignDesc(int* b){return *(QuantizationDescriptor*)(((unsigned int)b+15)&~15u);}
struct QuantizedBoundsQuery {
    int unk00;int unk04;int unk08;int unk0c;int unk10;
    void* data;int count;int unk1c;
    float x,y,z,w;
    int FUN_009e2090(BoundsView*,void*,int);
};
// pdb: hkMoppBvTreeShapeBase::queryAabbImpl | hkpMoppBvTreeShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: aabb, hits, maxNumKeys
int QuantizedBoundsQuery::FUN_009e2090(BoundsView* bounds,void* data,int capacity)
{
    int buffer[16];
    alignDesc(buffer).x=x;
    int c=count;
    alignDesc(buffer).y=y;
    void* d=this->data;
    alignDesc(buffer).z=z;alignDesc(buffer).w=w;
    alignDesc(buffer).data=d;
    float scale=16777216.0/w;
    QuantizationDescriptor& descriptor=alignDesc(buffer);
    descriptor.count=c;descriptor.capacity=c;
    Vec4 limit;
    limit.v[0]=x+scale;limit.v[1]=y+scale;limit.v[2]=z+scale;limit.v[3]=w+scale;
    BoundsView clipped;
    clipped.lo[0]=x>bounds->lo[0] ? x:bounds->lo[0];
    clipped.lo[1]=y>bounds->lo[1] ? y:bounds->lo[1];
    clipped.lo[2]=z>bounds->lo[2] ? z:bounds->lo[2];
    clipped.lo[3]=w>bounds->lo[3] ? w:bounds->lo[3];
    clipped.hi[0]=limit.v[0]<bounds->hi[0] ? limit.v[0]:bounds->hi[0];
    clipped.hi[1]=limit.v[1]<bounds->hi[1] ? limit.v[1]:bounds->hi[1];
    clipped.hi[2]=limit.v[2]<bounds->hi[2] ? limit.v[2]:bounds->hi[2];
    clipped.hi[3]=limit.v[3]<bounds->hi[3] ? limit.v[3]:bounds->hi[3];
    int size;
    {
    IndexArray output={data,0,capacity|0x80000000};
    QueryResult result;
    result.FUN_00a52f70(&descriptor,&clipped,&output);
    size=result.output->size;
    if(!(output.capacity&0x80000000)) {
        int n=output.capacity&0x3fffffff;
        ThreadMemoryView* mem=(ThreadMemoryView*)TlsGetValue(DAT_010f3170);
        mem->FUN_008f6d90(output.data,n*4,0x17);
    }
    }
    return size;
}
}   // namespace f3m_009e2090

// @f3 0x009fbbc0 (community match, verified in this file)
#include <math.h>
namespace f3m_009fbbc0 {
struct hkSimdReal {
    float m_real;
    hkSimdReal(float r) : m_real(r) {}
    operator float() const { return m_real; }
};
inline hkSimdReal sqrtInverse(const hkSimdReal& r) { float res; if (r != 0.0f) res = 1.0f / sqrt((float)r); else res = 0.0f; return res; }
struct __declspec(align(16)) hkVector4 {
    float x, y, z, w;
    hkVector4() {}
    hkVector4(const hkVector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    void operator=(const hkVector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    void setMul4(float s, const hkVector4& a) { x = s * a.x; y = s * a.y; z = s * a.z; w = s * a.w; }
    void setMul4(const hkVector4& a, const hkVector4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    void mul4(const hkVector4& a) { x = a.x * x; y = a.y * y; z = a.z * z; w = a.w * w; }
    void add4(const hkVector4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    void mul4(const hkSimdReal& s) { x *= s; y *= s; z *= s; w *= s; }
    void setNeg4(const hkVector4& a) { x = -a.x; y = -a.y; z = -a.z; w = -a.w; }
    void setCross(const hkVector4& a, const hkVector4& b) { x = a.y * b.z - a.z * b.y; y = a.z * b.x - a.x * b.z; z = a.x * b.y - a.y * b.x; }
    void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void setCross0(const hkVector4& a, const hkVector4& b) { const float nx = a.y * b.z - a.z * b.y; const float ny = a.z * b.x - a.x * b.z; const float nz = a.x * b.y - a.y * b.x; set(nx, ny, nz, 0.0f); }
    void setRotatedDir(const struct hkRotation& r, const hkVector4& b);
    float lengthSquared3() const { return x * x + y * y + z * z; }
    __forceinline float lengthInverse3() const { float l2 = x * x + y * y + z * z; return sqrtInverse(l2); }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
};
struct hkRotation { hkVector4 col0, col1, col2; };
__forceinline void hkVector4::setRotatedDir(const hkRotation& r, const hkVector4& b)
{
    const float* m = &r.col0.x; const float* v = &b.x;
    x = m[0] * v[0] + m[4] * v[1] + m[8] * v[2];
    y = m[1] * v[0] + m[5] * v[1] + m[9] * v[2];
    z = m[2] * v[0] + m[6] * v[1] + m[10] * v[2];
    w = 0.0f;
}
struct hkTransform { hkVector4 col0, col1, col2, translation; };
struct PulleyData {
    hkVector4 pivotA;
    hkVector4 pivotB;
    float ropeLength;
    float leverage;
    PulleyData(const PulleyData& o) : pivotA(o.pivotA), pivotB(o.pivotB), ropeLength(o.ropeLength), leverage(o.leverage) {}
};
struct PulleyAtom {
    unsigned short type;
    unsigned short unk02;
    int unk04, unk08, unk0c;
    PulleyData data;
};
struct Body {
    unsigned char unk00, fixed01; unsigned short unk02;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    hkVector4 invInertia, position; hkRotation rot;
};
struct QueryIn {
    int unk00, unk04; float rhsFactor08; int unk0c, unk10, unk14, unk18, unk1c;
    float virtMassFactor20; int unk24, unk28, unk2c; Body* bodyA; Body* bodyB;
};
struct Jacobian { hkVector4 linearA, linearB, angularA, angularB; };
extern hkVector4 DAT_010f3370;

struct PulleyInfo { hkVector4 positionA, positionB, pivotA, pivotB; float ropeLength, leverage; };
struct Work { hkVector4 unk00, unk10, unk20, dirA, dirB, unk50, unk60; float unk70, unk74, rhsFactor, massFactor; };
// pdb: buildJacobianFromPulleyAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) void FUN_009fbbc0(const PulleyAtom& atom, const hkTransform& baseA, const hkTransform& baseB, const QueryIn& in, Jacobian** cursor)
{
    int e0 = in.unk00;
    int e1 = in.unk04;
    int e2 = in.unk0c;
    int e3 = in.unk10;
    int e4 = in.unk14;
    int e5 = in.unk18;
    int e6 = in.unk1c;
    PulleyInfo info;
    Work wk;
    info.positionA = baseA.translation;
    info.positionB = baseB.translation;
    info.pivotA = atom.data.pivotA;
    info.pivotB = atom.data.pivotB;
    info.ropeLength = atom.data.ropeLength;
    info.leverage = atom.data.leverage;
    Body* bodyA = in.bodyA;
    Body* bodyB = in.bodyB;
    Jacobian* out = *cursor;
    wk.dirA.setSub4(info.pivotA, info.positionA);
    wk.dirB.setSub4(info.positionB, info.pivotB);
    float len = wk.dirA.lengthSquared3();
    if (len > 1.1920928955078125e-7f) {
        wk.dirA.normalize3();
    } else {
        wk.dirA = DAT_010f3370;
    }
    len = wk.dirB.lengthSquared3();
    if (len > 1.1920928955078125e-7f) {
        wk.dirB.normalize3();
    } else {
        wk.dirB.setNeg4(DAT_010f3370);
    }
    wk.rhsFactor = in.rhsFactor08;
    wk.massFactor = in.virtMassFactor20;
    hkVector4 sB; sB.setMul4(info.leverage, wk.dirB);
    out->linearA = wk.dirA;
    out->linearB = sB;
    hkVector4 armA; armA.setSub4(info.positionA, bodyA->position);
    hkVector4 armB; armB.setSub4(info.positionB, bodyB->position);
    hkVector4 c;
    c.setCross(armA, wk.dirA);
    if (bodyA->fixed01) {
        out->angularA.x = c.x; out->angularA.y = c.y; out->angularA.z = c.z; out->angularA.w = 0.0f;
    } else {
        out->angularA.setRotatedDir(bodyA->rot, c);
    }
    hkVector4 cB; cB.setCross(sB, armB);
    if (bodyB->fixed01) {
        out->angularB.x = cB.x; out->angularB.y = cB.y; out->angularB.z = cB.z; out->angularB.w = 0.0f;
    } else {
        out->angularB.setRotatedDir(bodyB->rot, cB);
    }
    hkVector4 qA; qA.setMul4(out->angularA, out->angularA);
    hkVector4 qB; qB.setMul4(out->angularB, out->angularB);
    qA.mul4(bodyA->invInertia);
    qB.mul4(bodyB->invInertia);
    qA.add4(qB);
    float lev2 = info.leverage * info.leverage;
    float mass = (float)(lev2 * bodyB->invInertia.w + bodyA->invInertia.w + 1.1920928955078125e-7);
    float ang = qA.x + qA.y + qA.z;
    float sum = mass + ang;
    out->angularA.w = wk.massFactor / sum;
    hkVector4 a2; a2.setSub4(info.pivotA, info.positionA);
    hkVector4 b2; b2.setSub4(info.positionB, info.pivotB);
    float total = sqrt(a2.lengthSquared3()) + sqrt(b2.lengthSquared3()) * info.leverage;
    const float& rt = total;
    *cursor = out + 1;
    float dev = rt - info.ropeLength;
    out->linearA.w = dev * wk.rhsFactor;
    out->linearA.x = (float)(out->linearA.x + 1.1920928955078125e-7);
    *(unsigned char*)&out->linearA.x = 10;
}

const hkTransform* volatile zA;
const hkTransform* volatile zB;
const PulleyAtom* volatile zAtom;
const QueryIn* volatile zIn;
Jacobian** volatile zCursor;
void zCaller_009fbbc0() { FUN_009fbbc0(*zAtom, *zA, *zB, *zIn, zCursor); }
}

// @f3 0x009e4220 (community match, verified in this file)
#include <math.h>
namespace Init9E4220 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
namespace f3m_009e4220 {
struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline int compare(const hkVector4& b) const {return (x<=b.x?8:0)|(y<=b.y?4:0)|(z<=b.z?2:0)|(w<=b.w?1:0);}
    __forceinline void setAll(float v) {x=v;y=v;z=v;w=v;}
};
struct hkThreadMemory
{
    void* FUN_008f6d30(int size, int memClass);
    static hkThreadMemory& getInstance() { return *(hkThreadMemory*)DAT_00d9b080(DAT_010f3170); }
};
struct hkReferencedObject
{
    void* vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    void addReference() { if (m_memSizeAndFlags != 0) m_referenceCount++; }
};
}
struct BoolValue {
    unsigned char value;
    __forceinline BoolValue& operator=(bool flag) {value=flag;return *this;}
};
extern const float FUN_00db7df0;
extern f3m_009e4220::hkVector4 DAT_01092a50;
struct FUN_009e4220
{
    unsigned char m_00;
    unsigned char m_01;
    short m_02;
    int m_04;
    short m_08;
    short m_0a;
    int m_0c;
    f3m_009e4220::hkReferencedObject** m_children;
    int m_numChildren;
    bool m_18;
    BoolValue m_19;
    unsigned short unk1a;
    int unk1c;
    f3m_009e4220::hkVector4 m_20;
    f3m_009e4220::hkVector4 m_30;
    FUN_009e4220(f3m_009e4220::hkReferencedObject** children, int numChildren, const f3m_009e4220::hkVector4& v);
};
FUN_009e4220::FUN_009e4220(f3m_009e4220::hkReferencedObject** children, int numChildren, const f3m_009e4220::hkVector4& v)
{
    using namespace f3m_009e4220;
    m_00 = 1;
    m_01 = 1;
    m_08 = 0;
    m_02 = 0;
    m_0a = 1;
    m_0c = 0;
    m_04 = 0;
    m_30 = v;
    hkThreadMemory& mem = hkThreadMemory::getInstance();
    int numBytes = numChildren << 2;
    hkReferencedObject** dst = (hkReferencedObject**)mem.FUN_008f6d30(numBytes, 0x27);
    int numWords = (unsigned)numBytes >> 2;
    hkReferencedObject** src = children;
    m_children = dst;
    m_numChildren = numChildren;
    for (int i = 0; i < numWords; i++)
        *dst++ = *src++;
    for (int i = 0; i < numChildren; i++)
        m_children[i]->addReference();
    m_20.x = 0.0f;
    m_20.y = 0.0f;
    m_20.z = 0.0f;
    m_20.w = 1.0f;
    m_19 = false;
    hkVector4 delta; const float epsilon=0.001f;
    delta.x = v.x - DAT_01092a50.x;
    delta.y = v.y - DAT_01092a50.y;
    delta.z = v.z - DAT_01092a50.z;
    delta.w = v.w - DAT_01092a50.w;
    delta.x = fabsf(delta.x);
    delta.y = fabsf(delta.y);
    delta.z = fabsf(delta.z);
    delta.w = fabsf(delta.w);
    hkVector4 threshold; threshold.setAll(epsilon);
    int mask=delta.compare(threshold);
    m_18 = (mask & 0xe) != 0xe;
}
}

// @f3 0x009e93b0 (community match, verified in this file)
extern const float DAT_00e80798;
extern const float DAT_00e80794;
namespace f3m_009e93b0 {

namespace f3m_009e93b0 {

struct __declspec(align(16)) S009e93b0_Vec4 {
    float x, y, z, w;
};

struct S009e93b0_Point {
    float x, y, z;
};

struct S009e93b0_Mat {
    S009e93b0_Vec4 r0, r1, r2;
};

static inline float S009e93b0_dot3(const S009e93b0_Vec4& r, const S009e93b0_Vec4& p)
{
    return r.x * p.x + r.y * p.y + r.z * p.z;
}

static inline float S009e93b0_dotY(const S009e93b0_Vec4& r, const S009e93b0_Vec4& p)
{
    double y = r.y * p.y;
    double x = r.x * p.x;
    double z = r.z * p.z;
    return y + x + z;
}

static __declspec(noinline) void FUN_009e93b0(const char* verts, const S009e93b0_Mat* m, int numVerts, int stride, S009e93b0_Vec4* __restrict halfExt, S009e93b0_Vec4* center)
{
    S009e93b0_Vec4 minV;
    S009e93b0_Vec4 maxV;
    minV.x = DAT_00e80798;
    minV.y = DAT_00e80798;
    minV.z = DAT_00e80798;
    maxV.x = DAT_00e80794;
    maxV.y = DAT_00e80794;
    maxV.z = DAT_00e80794;
    for (int i = 0; i < numVerts / 3; i++) {
        for (int j = 0; j < 3; j++) {
            S009e93b0_Vec4 p;
            p.x = ((const float*)verts)[0];
            p.y = ((const float*)verts)[1];
            p.z = ((const float*)verts)[2];
            verts += stride;
            float d = S009e93b0_dot3(m->r0, p);
            if (d < minV.x) minV.x = d;
            if (d > maxV.x) maxV.x = d;
            d = S009e93b0_dotY(m->r1, p);
            if (d < minV.y) minV.y = d;
            if (d > maxV.y) maxV.y = d;
            double yy = m->r2.y * p.y;
            d = yy + m->r2.x * p.x + m->r2.z * p.z;
            if (d < minV.z) minV.z = d;
            if (d > maxV.z) maxV.z = d;
        }
    }
    S009e93b0_Vec4 c;
    c.x = maxV.x + minV.x;
    c.y = maxV.y + minV.y;
    c.z = maxV.z + minV.z;
    c.x *= 0.5;
    c.y *= 0.5;
    c.z *= 0.5;
    halfExt->x = (float)(maxV.x - minV.x) * 0.5;
    halfExt->y = (float)(maxV.y - minV.y) * 0.5;
    halfExt->z = (float)(maxV.z - minV.z) * 0.5;
    halfExt->w = DAT_00e80794;
    center->x = m->r0.x * c.x;
    center->y = m->r0.y * c.x;
    center->z = m->r0.z * c.x;
    center->w = m->r0.w * c.x;
    center->x += m->r1.x * c.y;
    center->y += m->r1.y * c.y;
    center->z += m->r1.z * c.y;
    center->w += m->r1.w * c.y;
    center->x += m->r2.x * c.z;
    center->y += m->r2.y * c.z;
    center->z += m->r2.z * c.z;
    center->w += m->r2.w * c.z;
}

volatile int g009e93b0_n;
volatile int g009e93b0_s;
const char* volatile g009e93b0_v;
S009e93b0_Mat* volatile g009e93b0_m;
S009e93b0_Vec4* volatile g009e93b0_c;
S009e93b0_Vec4* volatile g009e93b0_h;

void S009e93b0_caller()
{
    FUN_009e93b0(g009e93b0_v, g009e93b0_m, g009e93b0_n, g009e93b0_s, g009e93b0_h, g009e93b0_c);
}

}
}   // namespace f3m_009e93b0

// @f3 0x009f0970 (community match, verified in this file)
extern int DAT_011697ec;
namespace f3m_009f0970 {

struct S009f0d00_Vector4 {
    float x, y, z, w;
    __forceinline void setRotatedDir(const struct S009f0d00_Rotation& a, const S009f0d00_Vector4& b);
    __forceinline void setSub4(const S009f0d00_Vector4& a, const S009f0d00_Vector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
};

struct S009f0d00_Rotation {
    S009f0d00_Vector4 c0, c1, c2;
    __forceinline float operator()(int r, int c) const { return (&(&c0)[c].x)[r]; }
    void hkRotation_set(const S009f0d00_Vector4* q);
};

__forceinline void S009f0d00_Vector4::setRotatedDir(const S009f0d00_Rotation& a, const S009f0d00_Vector4& b)
{
    const float v0 = b.x;
    const float v1 = b.y;
    const float v2 = b.z;
    x = a(0, 0) * v0 + a(0, 1) * v1 + a(0, 2) * v2;
    y = a(1, 0) * v0 + a(1, 1) * v1 + a(1, 2) * v2;
    z = a(2, 0) * v0 + a(2, 1) * v1 + a(2, 2) * v2;
    w = 0.0;
}

struct __declspec(align(16)) S009f0d00_Transform {
    S009f0d00_Rotation rot;
    S009f0d00_Vector4 trans;
};

struct S009f0d00_SweptTransform {
    S009f0d00_Vector4 m_centerOfMass0;
    S009f0d00_Vector4 m_centerOfMass1;
    S009f0d00_Vector4 m_rotation0;
    S009f0d00_Vector4 m_rotation1;
    S009f0d00_Vector4 m_centerOfMassLocal;
};

__forceinline void S009f0d00_calcTransAtT0(const S009f0d00_SweptTransform& sweptTrans, S009f0d00_Transform& transformOut)
{
    const S009f0d00_Vector4& q0 = sweptTrans.m_rotation0;
    transformOut.rot.hkRotation_set(&q0);
    S009f0d00_Vector4 centerShift;
    centerShift.setRotatedDir(transformOut.rot, sweptTrans.m_centerOfMassLocal);
    transformOut.trans.setSub4(sweptTrans.m_centerOfMass0, centerShift);
}

__forceinline void S009f0d00_calcTransAtT1(const S009f0d00_SweptTransform& sweptTrans, S009f0d00_Transform& transformOut)
{
    const S009f0d00_Vector4& q1 = sweptTrans.m_rotation1;
    transformOut.rot.hkRotation_set(&q1);
    S009f0d00_Vector4 centerShift;
    centerShift.setRotatedDir(transformOut.rot, sweptTrans.m_centerOfMassLocal);
    transformOut.trans.setSub4(sweptTrans.m_centerOfMass1, centerShift);
}

class S009f0d00_DisplayHandler {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void updateGeometry(const S009f0d00_Transform& t, unsigned long id, int tag);
};

class XfOwnerN {
public:
    void FUN_009f0970(char* entity);
};


// pdb: hkpSweptTransformDisplayViewer::inactiveEntityMovedCallback | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: entity
void XfOwnerN::FUN_009f0970(char* entity) {
    const S009f0d00_SweptTransform& swept = *(const S009f0d00_SweptTransform*)(entity + 0x120);

    S009f0d00_Transform t0;
    S009f0d00_calcTransAtT0(swept, t0);
    (*(S009f0d00_DisplayHandler**)((char*)this - 0x14))->updateGeometry(t0, (unsigned long)(entity + 0x10) + 1, DAT_011697ec);

    S009f0d00_calcTransAtT1(swept, t0);
    (*(S009f0d00_DisplayHandler**)((char*)this - 0x14))->updateGeometry(t0, (unsigned long)(entity + 0x10) + 2, DAT_011697ec);
}
}   // namespace f3m_009f0970

// @f3 0x009fa300 (community match, verified in this file)
#include <math.h>

float Atan2(float y, float x);
namespace f3m_009fa300 {
extern const float DAT_00de6e70;
extern const float DAT_00e817f0[];
extern const float DAT_00e817f8[];

struct SimdReal { float v; SimdReal(float f) : v(f) {} operator float() const { return v; } };

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline void setCross(const Vec4& a, const Vec4& b)
    {
        float nx = a.y * b.z - a.z * b.y;
        float ny = a.z * b.x - a.x * b.z;
        float nz = a.x * b.y - a.y * b.x;
        x = nx; y = ny; z = nz; w = 0.0f;
    }
    __forceinline SimdReal dot3(const Vec4& a) const { return x * a.x + y * a.y + z * a.z; }
    __forceinline void mul4(const float& s) { x *= s; y *= s; z *= s; w *= s; }
    __forceinline void setMul4(float s, const Vec4& a) { x = s * a.x; y = s * a.y; z = s * a.z; w = s * a.w; }
    __forceinline void setMul4b(const Vec4& a, float s) { x = a.x * s; y = a.y * s; z = a.z * s; w = a.w * s; }
    __forceinline void setMul4c(float s, const Vec4& a) { for (int i = 0; i < 4; i++) (&x)[i] = (&a.x)[i] * s; }

};

static __forceinline void CrossF(Vec4& c, const Vec4& a, const Vec4& b)
{
    float nx = a.y * b.z - a.z * b.y;
    float ny = a.z * b.x - a.x * b.z;
    float nz = a.x * b.y - a.y * b.x;
    c.x = nx; c.y = ny; c.z = nz; c.w = 0.0f;
}
struct Rec {
    unsigned char unk00, unk01, unk02, iB, iC, num, unk06, unk07;
    float f08, f0c, f10;
};
struct Out { Vec4 q; float f10, f14, f18, f1c; };
struct AObj {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    float f40;
};

static __forceinline float SqrtF(float r) { return sqrtf(r); }
static __forceinline int Impl(const Rec* rec, Out* out, AObj* a, const Vec4& u, const Vec4& v)
{
    Vec4 c;
    c.setCross(v, u);
    float len2 = c.dot3(c);
    if (DAT_00de6e70 > len2)
        return 1;
    float dot = v.x * u.x + u.y * v.y + v.z * u.z;

    unsigned int num = rec->num;
    float len = (float)sqrt((double)len2);
    float angle = Atan2(len, dot) * DAT_00e817f8[num] + DAT_00e817f0[num];
    float t = DAT_00e817f8[1 - rec->num];
    out->f1c = a->f40 * rec->f10;
    c.mul4(1.0f / len);
    out->q.x = c.x * t;
    out->q.y = c.y * t;
    out->q.z = c.z * t;
    out->q.w = c.w * t;
    out->f18 = angle;
    out->f10 = rec->f08;
    out->f14 = rec->f0c;
    return 0;
}
// pdb: buildJacobianFromConeLimitAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) int FUN_009fa300(AObj* a, const Vec4* B, const Vec4* C, const Rec* rec, Out* out)
{
    const Vec4& v = B[rec->iB];
    return Impl(rec, out, a, C[rec->iC], v);
}
extern AObj* volatile g_a;
extern const Vec4* volatile g_b;
extern const Vec4* volatile g_c;
extern const Rec* volatile g_rec;
extern Out* volatile g_out;
extern int g_res;
void Caller009fa300()
{
    Out* o = g_out;
    const Rec* r = g_rec;
    g_res = FUN_009fa300(g_a, g_b, g_c, r, o);
    g_res += FUN_009fa300(g_a, g_b, g_c, r, o);
}
}

// @f3 0x009eef30 (community match, verified in this file)
namespace z9eef30 {

struct b17_Heap {
    void* Alloc(unsigned int size, int align);
    void Free(void* p, unsigned int size, int align);
};
extern unsigned long DAT_010f3170;
__declspec(dllimport) b17_Heap* __stdcall FUN_00d9b080(unsigned long index) throw();
extern char FUN_00e80900;
extern char FUN_00e808e0;
extern char DAT_00e80970;
extern char DAT_00e80950;
extern char DAT_00e80930;
extern char DAT_00e80920;

struct b17_Arr {
    void* data;
    int count;
};

struct b17_Node {
    void* Init(int v);
    unsigned int unk00;
    unsigned short unk04;
};

struct b17_NodeB {
    void* Init(int v);
    unsigned int unk00;
    unsigned short unk04;
};

struct b17_Node2 {
    void* Find(void* p);
    unsigned int unk00;
    unsigned short unk04;
};

struct Z {
    Z();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct RefBase {
    void* vptr;
    unsigned short memSize;
    unsigned short refCount;
    __forceinline RefBase() { refCount = 1; }
};

struct YBase : RefBase {
    __forceinline YBase() { vptr = &DAT_00e80920; }
};

struct Y : YBase {
    Z z;
    void Attach(void* p);
};

struct BaseB {
    void* vptr8;
    __forceinline BaseB() { vptr8 = &FUN_00e80900; }
};

struct BaseC {
    void* vptrC;
    unsigned char flag;
    __forceinline BaseC() { vptrC = &FUN_00e808e0; flag = 0; }
};

struct Arr {
    void* data;
    int size;
    unsigned int capacityAndFlags;
    __forceinline Arr() : data(0), size(0), capacityAndFlags(0x80000000u) {}
};

struct Bases : RefBase, BaseB, BaseC {
    __forceinline Bases()
    {
        vptr = &DAT_00e80970;
        vptr8 = &DAT_00e80950;
        vptrC = &DAT_00e80930;
    }
};

struct FUN_009eef30 : Bases {
    int unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    Y y;
    Arr arr0;
    Arr arr;
    FUN_009eef30(const b17_Arr* src, int a2, int a3);
};

// pdb: hkServerProcessHandler::hkServerProcessHandler | hkServerProcessHandler.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: contexts, inStream, outStream
FUN_009eef30::FUN_009eef30(const b17_Arr* src, int a2, int a3)
{
    y.Attach(static_cast<BaseC*>(this));

    unsigned int flags = arr.capacityAndFlags;
    if ((int)(flags & 0x3fffffffu) < src->count) {
        if (!(flags & 0x80000000u)) {
            b17_Heap* h = FUN_00d9b080(DAT_010f3170);
            h->Free(arr.data, (flags & 0x3fffffffu) * 4, 0x17);
        }
        b17_Heap* h = FUN_00d9b080(DAT_010f3170);
        arr.data = h->Alloc(src->count * 4, 0x17);
        arr.capacityAndFlags = (arr.capacityAndFlags & 0x40000000u) | (unsigned int)src->count;
    }

    int n = src->count;
    arr.size = n;
    unsigned int* dst = (unsigned int*)arr.data;
    const unsigned int* s = (const unsigned int*)src->data;
    for (int i = 0; i < n; ++i) {
        dst[i] = s[i];
    }

    unsigned int sz = 0x10;
    void* t;
    if (a2 != 0) {
        b17_Heap* h = FUN_00d9b080(DAT_010f3170);
        b17_Node* nd = (b17_Node*)h->Alloc(sz, 0xd);
        nd->unk04 = (unsigned short)sz;
        t = nd->Init(a2);
    } else {
        t = 0;
    }
    unk14 = (int)t;

    if (a3 != 0) {
        b17_Heap* h = FUN_00d9b080(DAT_010f3170);
        b17_NodeB* nd = (b17_NodeB*)h->Alloc(sz, 0xd);
        nd->unk04 = (unsigned short)sz;
        t = nd->Init(a3);
    } else {
        t = 0;
    }
    unk18 = t;

    b17_Heap* h = FUN_00d9b080(DAT_010f3170);
    b17_Node2* n2 = (b17_Node2*)h->Alloc(0x14, 0x35);
    n2->unk04 = 0x14;
    void* r = n2->Find(unk18);
    unk1c = r != 0 ? (char*)r + 8 : 0;
    unk20 = (void*)static_cast<BaseB*>(this);
}

}

// @f3 0x009e91d0 (community match, verified in this file)
namespace f3m_009e91d0 {
namespace Matrix9E91D0 {
struct Result {
    unsigned char value;
    Result() {}
    __forceinline operator bool() const { return value!=0; }
};
struct __declspec(align(16)) Vector4 {
    float x,y,z,w;
    __forceinline void Set(float a,float b,float c,float d) {
        x=a;y=b;z=c;w=d;
    }
    __forceinline void Set(const Vector4& source) {
        x=source.x;y=source.y;z=source.z;w=source.w;
    }
    __forceinline void SetCross(const Vector4& a,const Vector4& b) {
        const float nx=a.y*b.z-a.z*b.y;
        const float ny=a.z*b.x-a.x*b.z;
        const float nz=a.x*b.y-a.y*b.x;
        Set(nx,ny,nz,0.0f);
    }
    __forceinline float Dot3(const Vector4& other) const {
        return x*other.x+y*other.y+z*other.z;
    }
    __forceinline void SetNeg4(const Vector4& other) {x=-other.x;y=-other.y;z=-other.z;w=-other.w;}
};
Result __cdecl FUN_009e8c20(Vector4* matrix,int flags);
Result __cdecl FUN_009e91d0(Vector4* matrix,Vector4* first,Vector4* second,Vector4* third) {
    Result result=FUN_009e8c20(matrix,30);
    if(!result) {
        first->Set(1.0f,0.0f,0.0f,0.0f);
        second->Set(0.0f,1.0f,0.0f,0.0f);
        third->Set(0.0f,0.0f,1.0f,0.0f);
    } else {
        first->Set(matrix[0]);
        second->Set(matrix[1]);
        third->Set(matrix[2]);
        Vector4 cross;
        cross.SetCross(*first,*second);
        float determinant=third->Dot3(cross);
        if(determinant<0.0f)
            third->SetNeg4(*third);
    }
    return result;
}
}



}   // namespace f3m_009e91d0

// @f3 0x009e43d0 (community match, verified in this file)
namespace f3m_009e43d0 {


extern unsigned long DAT_010f3170;
extern float DAT_01092a50;
extern float DAT_01092a54;
extern float DAT_01092a58;
extern float DAT_01092a5c;
extern float DAT_00db7df0;
extern int DAT_010f3370;

namespace f3m_009e43d0 {
namespace S009e43d0_ns {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
}
using S009e43d0_ns::FUN_00d9b080;

struct ThreadMem {
    void* FUN_008f6d30(int numBytes, int category);
};

struct Item {
    int unk00;
    unsigned short m_active;
    unsigned short m_refs;
};

struct Result {
    unsigned char m_value;
    Result() {}
};

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};

struct Source;

struct Sub {
    unsigned char pad[0x10];
    void FUN_00924360(const Source* source);
};

struct Source {
    unsigned char pad[0x30];
    Vec4 m_v;
    Result FUN_0096c5a0(const int& ref, float tolerance) const;
};

__forceinline float Abs(float r)
{
    return static_cast<float>(fabs(r));
}

struct Obj {
    unsigned char f0;
    unsigned char f1;
    unsigned short f2;
    int f4;
    unsigned short f8;
    unsigned short fa;
    int fc;
    Item** m_items;
    int m_count;
    bool m_notIdentity;
    bool m_ok;
    unsigned char pad1a[6];
    Sub m_sub;
    Vec4 m_v;

    Obj* FUN_009e43d0(Item** items, int count, const Source* source);
};

Obj* Obj::FUN_009e43d0(Item** items, int count, const Source* source)
{
    f0 = 1;
    f1 = 1;
    f8 = 0;
    f2 = 0;
    fa = 1;
    fc = 0;
    f4 = 0;
    m_sub.FUN_00924360(source);
    m_v = source->m_v;

    ThreadMem* mem = static_cast<ThreadMem*>(FUN_00d9b080(DAT_010f3170));
    int bytes = count * static_cast<int>(sizeof(Item*));
    Item** data = static_cast<Item**>(mem->FUN_008f6d30(bytes, 0x27));
    m_items = data;
    m_count = count;
    Item* const* s = items;
    int n = static_cast<unsigned>(bytes) >> 2;
    if (n > 0) { do { *data++ = *s++; } while (--n); }
    for (int i = 0; i < count; i++) {
        Item* item = m_items[i];
        if (item->m_active != 0)
            item->m_refs++;
    }

    Vec4 d;
    d.x = m_v.x - DAT_01092a50;
    d.y = m_v.y - DAT_01092a54;
    d.z = m_v.z - DAT_01092a58;
    d.w = m_v.w - DAT_01092a5c;
    d.x = Abs(d.x);
    d.y = Abs(d.y);
    d.z = Abs(d.z);
    d.w = Abs(d.w);
    int mask = ((d.x <= 0.001f) ? 8 : 0) | ((d.y <= 0.001f) ? 4 : 0) | ((d.z <= 0.001f) ? 2 : 0) | ((d.w <= 0.001f) ? 1 : 0);
    m_notIdentity = (mask & 0xe) != 0xe;
    m_ok = source->FUN_0096c5a0(DAT_010f3370, 0.001f).m_value == 0;
    return this;
}
}
}   // namespace f3m_009e43d0

// @f3 0x009e0630 (community match, verified in this file)
#include <math.h>
namespace f3m_009e0630 {
namespace basis9e0630 {
struct Vector4 {
    float x,y,z,w;
    __forceinline void Set(const Vector4& r) {x=r.x;y=r.y;z=r.z;w=r.w;}
    __forceinline Vector4& Mul(const float& scale) {x=scale*x;y*=scale;z*=scale;w*=scale;return *this;}

    __forceinline void Normalize3() {
        float scale=x*x+y*y+z*z;
        if(scale!=0.0f) {
            scale=static_cast<float>(sqrt(scale));
            scale=1.0f/scale;
        }else scale=0.0f;
        Mul(scale);
    }
    __forceinline void Cross(const Vector4& a,const Vector4& b) {
        float cy=a.z*b.x-a.x*b.z;
        float cz=a.x*b.y-a.y*b.x;
        float cx=a.y*b.z-a.z*b.y;
        x=cx;y=cy;z=cz;w=0.0f;
    }
};
struct BasisPair {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    Vector4 firstA,firstB,firstC,secondA,secondB,secondC;
    void FUN_009e0630(const Vector4& a,const Vector4& b,const Vector4& c,const Vector4& d);
};
void BasisPair::FUN_009e0630(const Vector4& a,const Vector4& b,const Vector4& c,const Vector4& d) {
    Vector4* pa=&firstA;
    firstA.Set(a);firstA.Normalize3();
    firstB.Set(c);firstB.Normalize3();
    firstC.Cross(a,c);
    this->secondA.Set(b);this->secondA.Normalize3();
    secondB.Set(d);secondB.Normalize3();
    secondC.Cross(b,d);
}
}
}   // namespace f3m_009e0630

// @f3 0x009ed320 (community match, verified in this file)
namespace f3m_009ed320 {

extern unsigned long DAT_0116913c;
extern const char DAT_00e80834[];
extern const char DAT_00e32798[];
namespace f3m_009ed320 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct Command { const char* name; unsigned int ticks; unsigned int unk08; 
    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int time; __asm { rdtsc
        mov time, eax } ticks = time; }
};
struct Stream { unsigned int unk00; Command* cursor; unsigned int unk08; Command* limit; };

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};

struct Transform {
    Vec4 c0, c1, c2, t;
    void hkTransform_setMul(const Transform* a, const Transform* b);
};

struct RayInput {
    Vec4 from;
    Vec4 to;
    unsigned int unk20, unk24, unk28, unk2c;
};

struct CdBody {
    void* shape;
    unsigned int key;
    const Transform* motion;
    const CdBody* parent;
    CdBody() {}
    CdBody(const CdBody* p, const Transform* m) { motion = m; parent = p; }
};

struct Shape {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void CastRay(const RayInput& input, const CdBody& body, void* collector);
};

struct TransformShape {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Shape* child;
    unsigned int unk1c;
    Transform xf;
    void hkpConvexTransformShape_castRayWithCollectorImpl(const RayInput& input, const CdBody& parent, void* collector);
};

__forceinline void InvPos(Vec4& out, const Transform& a, const Vec4& b)
{
    float dx = b.x - a.t.x;
    float dy = b.y - a.t.y;
    float dz = b.z - a.t.z;
    out.x = a.c0.x * dx + a.c0.y * dy + a.c0.z * dz;
    out.y = a.c1.x * dx + a.c1.y * dy + a.c1.z * dz;
    out.z = a.c2.x * dx + a.c2.y * dy + a.c2.z * dz;
    out.w = 0.0f;
}

__forceinline void InvPos2(Vec4& out, const Transform& a, const Vec4& b)
{
    float dz = 0.0f, dy = 0.0f, dx = 0.0f;
    dx = b.x - a.t.x;
    dy = b.y - a.t.y;
    dz = b.z - a.t.z;
    out.x = a.c0.x * dx + a.c0.y * dy + a.c0.z * dz;
    out.y = a.c1.x * dx + a.c1.y * dy + a.c1.z * dz;
    out.z = a.c2.x * dx + a.c2.y * dy + a.c2.z * dz;
    out.w = 0.0f;
}

// pdb: hkpConvexTransformShape::castRayWithCollectorImpl | hkpConvexTransformShape.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void TransformShape::hkpConvexTransformShape_castRayWithCollectorImpl(const RayInput& input, const CdBody& parent, void* collector)
{
    Stream* s = (Stream*)TlsGetValue(DAT_0116913c);
    Command* c = s->cursor;
    if (c < s->limit) {
        c->name = DAT_00e80834;
        c->setTime();
        s->cursor = c + 1;
    }
    RayInput sub = input;
    InvPos(sub.from, xf, input.from);
    InvPos2(sub.to, xf, input.to);
    Transform world;
    world.hkTransform_setMul(parent.motion, &xf);
    CdBody body(&parent, &world);
    body.shape = child;
    body.key = 0;
    child->CastRay(sub, body, collector);
    Stream* s2 = (Stream*)TlsGetValue(DAT_0116913c);
    Command* c2 = s2->cursor;
    if (c2 < s2->limit) {
        c2->name = DAT_00e32798;
        c2->setTime();
        s2->cursor = c2 + 1;
    }
}

}
}   // namespace f3m_009ed320

// @f3 0x009edc20 (community match, verified in this file)
extern float FUN_00de6e60;
extern float FUN_00de731c;
extern double FUN_00db7de8;
extern int DAT_010f3370;
namespace f3m_009edc20 {
struct __declspec(align(16)) Aabb9edc20 { float mn[4]; float mx[4]; };

static __forceinline void Add4(float* o, const float* p, const float* q) { o[0] = p[0] + q[0]; o[1] = p[1] + q[1]; o[2] = p[2] + q[2]; o[3] = p[3] + q[3]; }
static __forceinline void Sub4(float* o, const float* p, const float* q) { o[0] = p[0] - q[0]; o[1] = p[1] - q[1]; o[2] = p[2] - q[2]; o[3] = p[3] - q[3]; }
static __forceinline void Mul4(float* o, double s) { o[0] *= s; o[1] *= s; o[2] *= s; o[3] *= s; }
static __forceinline void Mul4f(float* o, float s) { o[0] *= s; o[1] *= s; o[2] *= s; o[3] *= s; }
static __forceinline void Mul4r(float* o, const double& s) { o[0] = (float)(o[0] * s); o[1] = (float)(o[1] * s); o[2] = (float)(o[2] * s); o[3] = (float)(o[3] * s); }

class FUN_009edc20_Child {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c(const void* a, float t, float* bounds);
};

class FUN_009edc20_Owner {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float halfExtent[4];
    float center[4];
    bool flag40;
    FUN_009edc20_Child** children44;
    int count48;
    void hkpConvexListShape_setUseCachedAabb(bool flag);
};

// pdb: hkpConvexListShape::setUseCachedAabb | hkpConvexListShape.obj | fnv360_0822_retail, objrun + bridge(call_seq|objrun) + skyrim(objrun_prop), high
void FUN_009edc20_Owner::hkpConvexListShape_setUseCachedAabb(bool flag) {
    flag40 = flag;
    if (!flag) {
        return;
    }
    Aabb9edc20 bb;
    bb.mn[0] = FUN_00de6e60; bb.mn[1] = FUN_00de6e60; bb.mn[2] = FUN_00de6e60; bb.mn[3] = FUN_00de6e60;
    bb.mx[0] = FUN_00de731c; bb.mx[1] = FUN_00de731c; bb.mx[2] = FUN_00de731c; bb.mx[3] = FUN_00de731c;
    __declspec(align(16)) float tmp[8];
    for (int i = 0; i < count48; i++) {
        FUN_009edc20_Child* c = children44[i];
        c->unk1c((const void*)&DAT_010f3370, 0.0f, tmp);
        if (!(bb.mn[0] < tmp[0])) bb.mn[0] = tmp[0];
        if (!(bb.mn[1] < tmp[1])) bb.mn[1] = tmp[1];
        if (!(bb.mn[2] < tmp[2])) bb.mn[2] = tmp[2];
        if (!(bb.mn[3] < tmp[3])) bb.mn[3] = tmp[3];
        if (!(bb.mx[0] > tmp[4])) bb.mx[0] = tmp[4];
        if (!(bb.mx[1] > tmp[5])) bb.mx[1] = tmp[5];
        if (!(bb.mx[2] > tmp[6])) bb.mx[2] = tmp[6];
        if (!(bb.mx[3] > tmp[7])) bb.mx[3] = tmp[7];
    }
    Add4(center, bb.mx, bb.mn);
    Mul4(center, 0.5);
    Sub4(halfExtent, bb.mx, bb.mn);
    Mul4(halfExtent, 0.5);
}
}   // namespace f3m_009edc20

// @f3 0x009e5520 (community match, verified in this file)
#include <math.h>
extern float DAT_01062ec0,DAT_01062ec4,DAT_01062ec8;extern double DAT_00dd8ac8;extern const float DAT_00e7c75c;
namespace f3m_009e5520 {
namespace Cylinder3083 {
struct __declspec(align(16)) hkVector4 {float x,y,z;union {float w;unsigned id;};
 __forceinline float dot(float bx,float by,float bz)const{return (y*by+x*bx)+z*bz;}
 void setMul(float v,const hkVector4& a){x=a.x*v;y=a.y*v;z=a.z*v;w=a.w*v;}
 void setAdd(const hkVector4& a,const hkVector4& b){x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w;}
 void mul(float v){x*=v;y*=v;z*=v;w*=v;}
};
typedef hkVector4 CylinderSupportStore;
struct hkpCylinderShape {int unk00,unk04,unk08,unk0c;float unk10,m_fCylinderRadius;int unk18,unk1c;hkVector4 m_kVertices[2],m_kPerpendicular1,m_kPerpendicular2;
 enum {VERTEX_ID_ENCODING_VALUE_MASK=15,VERTEX_ID_ENCODING_IS_BASE_A_SHIFT=7,VERTEX_ID_ENCODING_SIN_SIGN_SHIFT=6,VERTEX_ID_ENCODING_COS_SIGN_SHIFT=5,VERTEX_ID_ENCODING_IS_SIN_LESSER_SHIFT=4};};
struct CylinderSupportShape:hkpCylinderShape {void hkpCylinderShape_getSupportingVertexImpl(const hkVector4&,CylinderSupportStore&)const;};
// pdb: hkpCylinderShape::getSupportingVertexImpl | hkpCylinderShape.obj | fnv360_0822_retail, objrun + bridge(udata|vtable) + skyrim(udata), high
void CylinderSupportShape::hkpCylinderShape_getSupportingVertexImpl(const hkVector4& direction, CylinderSupportStore& output) const
{
    int vertexId;
    {
    const float eps = 1.19209290e-7f;
    const hkVector4& dir=direction;
    hkVector4 axis; axis.x=m_kVertices[1].x-m_kVertices[0].x;axis.y=m_kVertices[1].y-m_kVertices[0].y;axis.z=m_kVertices[1].z-m_kVertices[0].z;
    float u = dir.dot(m_kPerpendicular1.x,m_kPerpendicular1.y,m_kPerpendicular1.z);
    float v = dir.dot(m_kPerpendicular2.x,m_kPerpendicular2.y,m_kPerpendicular2.z);
    float len2 = u * u + v * v;

    if (DAT_00e7c75c <= len2)
    {
        float invLen = 1.0f / sqrtf(len2);
        v *= invLen;
        u *= invLen;
    }
    else
    {
        v = 0.0f;
        u = 1.0f;
    }

    int vSign = (v >= 0.0f);
    int uSign = (u >= 0.0f);
    float absV = fabsf(v);
    float absU = fabsf(u);
    int sinLesser;
    float minAbs;
    if (absV <= absU)
    {
        sinLesser = 1;
        minAbs = absV;
    }
    else
    {
        sinLesser = 0;
        minAbs = absU;
    }

    float da = (dir.y*axis.y + dir.x*axis.x) + dir.z*axis.z;
    int isBaseA = (da <= 0.0f);
    float factor = DAT_01062ec0;
    float bias = DAT_01062ec8;
    int angleIndex = fnv_FloatToInt((float)((factor * minAbs - bias) + DAT_00dd8ac8));
    vertexId = (sinLesser + 2 * (uSign + 2 * (vSign + 2 * isBaseA))) << 4;
    vertexId += angleIndex;

    }
    float u,v;
    int idx = (unsigned short)vertexId & hkpCylinderShape::VERTEX_ID_ENCODING_VALUE_MASK;
    unsigned short id16 = (unsigned short)vertexId;
    float half = (float)(idx + 0.5);
    int baseBit = (id16 >> hkpCylinderShape::VERTEX_ID_ENCODING_IS_BASE_A_SHIFT) & 1;
    int sinSign = (id16 >> hkpCylinderShape::VERTEX_ID_ENCODING_SIN_SIGN_SHIFT) & 1;
    int cosSign = (id16 >> hkpCylinderShape::VERTEX_ID_ENCODING_COS_SIGN_SHIFT) & 1;
    float s = half * DAT_01062ec4;
    float c = sqrtf(1.0f - s * s);

    if (vertexId & (1 << hkpCylinderShape::VERTEX_ID_ENCODING_IS_SIN_LESSER_SHIFT))
    {
        v = s;
        u = c;
    }
    else
    {
        u = s;
        v = c;
    }
    if (sinSign == 0)
        v = -v;
    if (cosSign == 0)
        u = -u;

    hkVector4 a,b,radial;
 a.setMul(u,m_kPerpendicular1); b.setMul(v,m_kPerpendicular2); radial.setAdd(b,a); radial.mul(m_fCylinderRadius);
 output.setAdd(m_kVertices[1-baseBit],radial); output.id=(unsigned)vertexId|0x3f000000u;
}

}
}   // namespace f3m_009e5520

// @f3 0x009eead0 (community match, verified in this file)
extern char DAT_00e808d0[];
extern unsigned int DAT_010f3170;
namespace f3m_009eead0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

class hkBool
{
public:
    hkBool(bool b) { m_bool = (char)b; }
    char m_bool;
};

struct Obj_9eead0
{
    char pad[4];
    unsigned short w4;
    char pad2[2];

    void* FUN_009a8fd0(int a, int b, hkBool t);
};

struct Heap_9eead0
{
    Obj_9eead0* FUN_008f6d30(int size, int kind);
};

class C_9eead0
{
public:
    void* m_00;
    unsigned short m_04;
    unsigned short m_06;
    void* m_08;
    hkBool m_0c;

    C_9eead0* FUN_009eead0(int a, int b, hkBool c);
};

// pdb: hkOArchive::hkOArchive | hkOArchive.obj | fnv360_0822_debug, objrun, high
// pdb params: arr, bs
C_9eead0* C_9eead0::FUN_009eead0(int a, int b, hkBool c)
{
    m_06 = 1;
    m_00 = DAT_00e808d0;
    m_0c = c;
    Heap_9eead0* heap = (Heap_9eead0*)TlsGetValue(DAT_010f3170);
    Obj_9eead0* o = heap->FUN_008f6d30(0x1c, 0x1a);
    o->w4 = 0x1c;
    m_08 = o->FUN_009a8fd0(a, b, false);
    return this;
}
}   // namespace f3m_009eead0

// @f3 0x009f5050 (community match, verified in this file)
extern int DAT_0116981c;
extern const double fnv_limit_9f5050;
namespace f3m_009f5050 {
struct Vec_9f5050 {
    float x;
    float y;
    float z;
};

struct Sub_9f5050 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Vec_9f5050 vec;
};

struct Obj_9f5050 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

int g_out_9f5050;
extern int fnv_probe_call_9f5050();

static __declspec(noinline) void fnv_callee_9f5050(int a, Vec_9f5050* v, Sub_9f5050* s, int b, int c)
{
    float m = v->x * v->x + v->y * v->y + v->z * v->z;
    s->vec.x = m;
    s->vec.y = m;
    int t = fnv_probe_call_9f5050();
    g_out_9f5050 = t + a + b + c;
}

struct C_9f5050 {
    void hkpToiContactPointViewer_contactPointCallback(Obj_9f5050* a);
};

// pdb: hkpToiContactPointViewer::contactPointCallback | hkpToiContactPointViewer.obj | fnv360_0822_retail, udata + bridge(udata|vtable), high
void C_9f5050::hkpToiContactPointViewer_contactPointCallback(Obj_9f5050* a)
{
    char* m = (char*)a->unk0c;
    if (*(float*)(m + 0x3030) != fnv_limit_9f5050) {
        Sub_9f5050* s = (Sub_9f5050*)(m + 0x3010);
        fnv_callee_9f5050(*(int*)((char*)this - 0x10), &s->vec, s, -65536, DAT_0116981c);
    }
}
}   // namespace f3m_009f5050

// @f3 0x009e4ef0 (community match, verified in this file)
extern double DAT_00db7de8;
extern double DAT_00db7de8;
extern float DAT_00de6e60;
extern float DAT_00de731c;
namespace f3m_009e4ef0 {

struct S9e4ef0_Vec4
{
    float x, y, z, w;
    void Scale(double s)
    {
        x = x * s;
        y = y * s;
        z = z * s;
        w = w * s;
    }
};

struct __declspec(align(16)) S9e4ef0_Transform
{
    S9e4ef0_Vec4 col0;
    S9e4ef0_Vec4 col1;
    S9e4ef0_Vec4 col2;
    S9e4ef0_Vec4 translation;
    void hkRotation_set(const S9e4ef0_Vec4* rotation);
};

struct __declspec(align(16)) S9e4ef0_Aabb
{
    float min[4];
    float max[4];
};

struct S9e4ef0_Shape
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void GetAabb(const S9e4ef0_Transform* xf, float tolerance, S9e4ef0_Aabb* out);
    short unk04;
    short unk06;
};

struct S9e4ef0_List
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S9e4ef0_Shape** m_data;
    int m_size;
    int unk18;
    int unk1c;
    S9e4ef0_Vec4 m_rotation;
    S9e4ef0_Vec4 m_translation;
    void FUN_009d5e80(S9e4ef0_List* src);
};

struct S9e4ef0_Heap
{
    void* FUN_008f6d30(unsigned int size, unsigned int id);
};

extern S9e4ef0_Heap* (__stdcall* DAT_00d9b080)(unsigned int owner);

static __declspec(noinline) void FUN_009e3630(S9e4ef0_Aabb* out, S9e4ef0_List* list)
{
    out->min[0] = out->min[1] = out->min[2] = out->min[3] = DAT_00de6e60;
    out->max[0] = DAT_00de731c;
    out->max[1] = -out->min[1];
    out->max[2] = -out->min[2];
    out->max[3] = -out->min[3];
    S9e4ef0_Transform xf;
    xf.translation = list->m_translation;
    xf.hkRotation_set(&list->m_rotation);
    for (int i = 0; i < list->m_size; i++)
    {
        S9e4ef0_Aabb box;
        list->m_data[i]->GetAabb(&xf, 0.0f, &box);
        for (int j = 0; j < 4; j++)
        {
            out->min[j] = box.min[j] < out->min[j] ? box.min[j] : out->min[j];
            out->max[j] = box.max[j] > out->max[j] ? box.max[j] : out->max[j];
        }
    }
}

struct S9e4ef0_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    float m_halfExtent[4];
    float m_center[4];
    S9e4ef0_List* hkpExtendedMeshShape_expandOneShapesSubparts();
    void FUN_009e4ef0(S9e4ef0_List* src);
};

void S9e4ef0_Owner::FUN_009e4ef0(S9e4ef0_List* src)
{
    S9e4ef0_Aabb box;
    S9e4ef0_Aabb bound;
    S9e4ef0_List* t = hkpExtendedMeshShape_expandOneShapesSubparts();
    t->FUN_009d5e80(src);
    int count = t->m_size;
    S9e4ef0_Heap* heap = DAT_00d9b080(DAT_010f3170);
    t->m_data = (S9e4ef0_Shape**)heap->FUN_008f6d30(count * 4, 0x27);
    int n = (unsigned int)(src->m_size * 4) / 4;
    S9e4ef0_Shape** d = t->m_data;
    S9e4ef0_Shape** s = src->m_data;
    if (n > 0)
    {
        do
        {
            *d++ = *s++;
        } while (--n);
    }
    for (int i = 0; i < t->m_size; i++)
    {
        S9e4ef0_Shape* e = t->m_data[i];
        if (e->unk04 != 0)
            e->unk06++;
    }
    float c0 = m_center[0];
    box.min[0] = c0 - m_halfExtent[0];
    box.min[1] = m_center[1] - m_halfExtent[1];
    box.min[2] = m_center[2] - m_halfExtent[2];
    box.min[3] = m_center[3] - m_halfExtent[3];
    box.max[0] = m_halfExtent[0] + m_center[0];
    box.max[1] = m_halfExtent[1] + m_center[1];
    box.max[2] = m_halfExtent[2] + m_center[2];
    box.max[3] = m_halfExtent[3] + m_center[3];
    FUN_009e3630(&bound, t);
    for (int j = 0; j < 4; j++)
        if (!(box.min[j] < bound.min[j]))
            box.min[j] = bound.min[j];
    for (int j = 0; j < 4; j++)
        if (!(box.max[j] > bound.max[j]))
            box.max[j] = bound.max[j];
    for (int j = 0; j < 4; j++)
        m_halfExtent[j] = box.max[j] - box.min[j];
    for (int j = 0; j < 4; j++)
        m_halfExtent[j] *= 0.5;
    for (int j = 0; j < 4; j++)
        m_center[j] = box.min[j] + box.max[j];
    for (int j = 0; j < 4; j++)
        m_center[j] *= 0.5;
}
}   // namespace f3m_009e4ef0

// @f3 0x009e7b60 (community match, verified in this file)
namespace f3m_009e7b60 {
namespace S9e7b60 {

typedef float hkReal;

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    __forceinline hkReal& operator()(int i) { return m_quad[i]; }
    __forceinline hkReal getComponent(int i) const { return m_quad[i]; }
    __forceinline const hkReal& operator()(int i) const { return m_quad[i]; }
    __forceinline void setAll(hkReal r)
    {
        m_quad[0] = r;
        m_quad[1] = r;
        m_quad[2] = r;
        m_quad[3] = r;
    }
    __forceinline void setMul4(hkReal r, const hkVector4& v)
    {
        m_quad[0] = r * v.m_quad[0];
        m_quad[1] = r * v.m_quad[1];
        m_quad[2] = r * v.getComponent(2); // Fake match: lane 2 read through the by-value getter sets the x87 operand order of the y product's third lane
        m_quad[3] = r * v.m_quad[3];
    }
    __forceinline void add4(const hkVector4& v)
    {
        m_quad[0] += v.m_quad[0];
        m_quad[1] += v.m_quad[1];
        m_quad[2] += v.m_quad[2];
        m_quad[3] += v.m_quad[3];
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_quad[0] = a.m_quad[0] + b.m_quad[0];
        m_quad[1] = a.m_quad[1] + b.m_quad[1];
        m_quad[2] = a.m_quad[2] + b.m_quad[2];
        m_quad[3] = a.m_quad[3] + b.m_quad[3];
    }
    __forceinline void addMul4(hkReal r, const hkVector4& v)
    {
        hkVector4 t;
        t.setMul4(r, v);
        setAdd4(t, *this);
    }
    __forceinline int compareLessThan4Mask(const hkVector4& v) const
    {
        return ((m_quad[0] < v.m_quad[0]) ? 8 : 0) | ((m_quad[1] < v.m_quad[1]) ? 4 : 0) |
               ((m_quad[2] < v.m_quad[2]) ? 2 : 0) | ((m_quad[3] < v.m_quad[3]) ? 1 : 0);
    }
    __forceinline void setInt24W(int value)
    {
        reinterpret_cast<int*>(m_quad)[3] = value | 0x3f000000;
    }
};

struct hkFourTransposedPoints
{
    hkVector4 m_x;
    hkVector4 m_y;
    hkVector4 m_z;
};

template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline int getSize() const { return m_size; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
};

class hkpConvexVerticesShape
{
public:
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    hkReal m_radius;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_aabbHalfExtents;
    hkVector4 m_aabbCenter;
    hkArray<hkFourTransposedPoints> m_rotatedVertices;
    int m_numVertices;

    void hkpConvexVerticesShape_getSupportingVertexImpl(const hkVector4& direction, hkVector4& supportingVertexOut) const;
};

// pdb: hkpConvexVerticesShape::getSupportingVertexImpl | hkpConvexVerticesShape.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void hkpConvexVerticesShape::hkpConvexVerticesShape_getSupportingVertexImpl(const hkVector4& direction, hkVector4& supportingVertexOut) const
{
    const hkReal minReal = -3.40282e38f;
    hkVector4 bestDot;
    bestDot.setAll(minReal);
    int vertexId = 0;
    {
        const hkArray<hkFourTransposedPoints>& rotated = m_rotatedVertices;
        const hkFourTransposedPoints* fv = &rotated[0];
        int numVertices = rotated.getSize() * 4;
        for (int i = 0; i < numVertices; i += 4)
        {
            hkReal dirX = direction(0);
            hkReal dirY = direction(1);
            hkReal dirZ = direction(2);
            hkVector4 dotX;
            dotX.setMul4(dirX, fv->m_x);
            hkVector4 dotY;
            dotY.setMul4(dirY, fv->m_y);
            hkVector4 dot;
            dot.setAdd4(dotY, dotX);
            dot.addMul4(dirZ, fv->m_z);
            int mask = bestDot.compareLessThan4Mask(dot);
            if (mask)
            {
                hkReal best;
                switch (mask)
                {
                case 0:
                case 8:
                    { best = dot(0); vertexId = i; }
                    break;
                case 4:
                    { best = dot(1); vertexId = i + 1; }
                    break;
                case 2:
                    { best = dot(2); vertexId = i + 2; }
                    break;
                case 1:
                    { best = dot(3); vertexId = i + 3; }
                    break;
                default:
                    if (dot(0) > dot(1))
                    {
                case 11:
                        if (dot(0) > dot(2)) {
                            if (dot(0) > dot(3)) { best = dot(0); vertexId = i; } else { best = dot(3); vertexId = i + 3; }
                        } else {
                            if (dot(2) > dot(3)) { best = dot(2); vertexId = i + 2; } else { best = dot(3); vertexId = i + 3; }
                        }
                    }
                    else
                    {
                case 7:
                        if (dot(1) > dot(2)) {
                            if (dot(1) > dot(3)) { best = dot(1); vertexId = i + 1; } else { best = dot(3); vertexId = i + 3; }
                        } else {
                            if (dot(2) > dot(3)) { best = dot(2); vertexId = i + 2; } else { best = dot(3); vertexId = i + 3; }
                        }
                    }
                    break;
                }
                bestDot.setAll(best);
            }
            fv++;
        }
    }
    const hkFourTransposedPoints& v = m_rotatedVertices[(unsigned)vertexId >> 2];
    int k = vertexId & 3;
    supportingVertexOut(0) = v.m_x(k);
    supportingVertexOut(1) = v.m_y(k);
    supportingVertexOut(2) = v.m_z(k);
    supportingVertexOut.setInt24W(vertexId);
}

}
}   // namespace f3m_009e7b60

// @f3 0x009ecff0 (community match, verified in this file)
namespace f3m_009ecff0 {
// hkpConvexTransformShape::getMaximumProjection(const hkVector4& direction) const: rotate the direction into the
// child's space, take the child's maximum projection, scale the local direction by it, transform that support
// point back and project it on the direction.
namespace f3m_009ecff0
{
    typedef float hkReal;
    typedef hkReal hkSimdReal;
    typedef hkReal hkSimdRealParameter;
    class hkTransform;
    class hkRotation;

    class hkVector4
    {
    public:
        __forceinline hkReal& operator()(int i) { return (&x)[i]; }
        __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
        __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a)
        {
            hkReal r = hkReal(rs);
            x = r * a.x;
            y = r * a.y;
            z = r * a.z;
            w = r * a.w;
        }
        __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& v);
        __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& v);
        __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }

        __declspec(align(16)) hkReal x;
        hkReal y;
        hkReal z;
        hkReal w;
    };

    class hkMatrix3
    {
    public:
        inline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
        inline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
        hkVector4 m_col0;
        hkVector4 m_col1;
        hkVector4 m_col2;
    };
    class hkRotation : public hkMatrix3
    {
    };
    class hkTransform
    {
    public:
        inline const hkRotation& getRotation() const { return m_rotation; }
        inline const hkReal& operator()(int r, int c) const { return m_rotation(r, c); }
        hkRotation m_rotation;
        hkVector4 m_translation;
    };

    inline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& v)
    {
        hkReal v0 = v(0);
        hkReal v1 = v(1);
        hkReal v2 = v(2);
        hkVector4& t = *this;
        t(0) = r(0, 0) * v0 + r(1, 0) * v1 + r(2, 0) * v2;
        t(1) = r(0, 1) * v0 + r(1, 1) * v1 + r(2, 1) * v2;
        t(2) = r(0, 2) * v0 + r(1, 2) * v1 + r(2, 2) * v2;
        t(3) = 0;
    }
    inline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
    {
        hkReal v0 = v(0);
        hkReal v1 = v(1);
        hkReal v2 = v(2);
        hkVector4& d = *this;
        d(0) = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2 + t(0, 3);
        d(1) = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2 + t(1, 3);
        d(2) = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2 + t(2, 3);
        d(3) = 0;
    }

    class hkpConvexShape
    {
    public:
        virtual ~hkpConvexShape();
        virtual int calcSizeForSpu(const void* input, int spuBufferSizeLeft) const;
        virtual void getAabb(const hkTransform& localToWorld, hkReal tolerance, void* out) const;
        virtual hkReal getMaximumProjection(const hkVector4& direction) const;
    };
    class hkpSingleShapeContainer
    {
    public:
        virtual ~hkpSingleShapeContainer();
        inline const hkpConvexShape* getChild() const { return m_childShape; }
        const hkpConvexShape* m_childShape;
    };
    class hkpShapeBase
    {
    public:
        virtual ~hkpShapeBase();
        unsigned short m_memSizeAndFlags;
        short m_referenceCount;
        unsigned int m_userData;
        unsigned int m_type;
        hkReal m_radius;
    };
    class hkpConvexTransformShape : public hkpShapeBase
    {
    public:
        inline const hkpConvexShape* getChildShape() const { return m_childShape.getChild(); }
        inline const hkTransform& getTransform() const { return m_transform; }
        hkReal FUN_009ecff0(const hkVector4& direction) const;

        hkpSingleShapeContainer m_childShape;
        int m_childShapeSize;
        hkTransform m_transform;
    };

    // pdb: hkpConvexTransformShape::getMaximumProjection | hkpConvexTransformShape.obj | fnv360_0822_retail, objopen_prop, low
    // pdb params: direction
    hkReal hkpConvexTransformShape::FUN_009ecff0(const hkVector4& direction) const
    {
        hkVector4 localDir;
        localDir._setRotatedInverseDir(getTransform().getRotation(), direction);
        const hkpConvexShape* childShape = getChildShape();
        hkReal localProjection = childShape->getMaximumProjection(localDir);
        hkVector4 localSupport;
        localSupport.setMul4(localProjection, localDir);
        hkVector4 worldSupport;
        worldSupport._setTransformedPos(getTransform(), localSupport);
        return worldSupport.dot3(direction);
    }
}
}   // namespace f3m_009ecff0

// @f3 0x009e9c60 (community match, verified in this file)
#include <math.h>
namespace f3m_009e9c60 {

namespace Step9c60 {
inline float Root(float value) { return sqrtf(value); }
inline float InverseRoot(float value) { return 1.0f / Root(value); }

struct Vector {
    float x, y, z, w;
    __forceinline const float& At(int i) const { return (&x)[i]; }
    __forceinline void operator=(const Vector& other) {
        x = other.x; y = other.y; z = other.z; w = other.w;
    }
    __forceinline void Integrate(float factor, const Vector& delta) {
        x += factor * delta.At(0); y += factor * delta.At(1);
        z += factor * delta.At(2); w += factor * delta.w;
    }
    __forceinline void Scale(float factor) {
        // Fake match: retain the scalar-copy local to preserve operand ranking.
        float scalar = factor;
        x *= scalar; y *= scalar; z *= scalar; w *= scalar;
    }
    __forceinline float InverseLength() const {
        float square = x*x + y*y + z*z;
        return square ? InverseRoot(square) : 0.0f;
    }
    __forceinline void Normalize() { Scale(InverseLength()); }
    __forceinline float Dot(const Vector& other) const {
        return x*other.x + y*other.y + z*other.z;
    }
    __forceinline void Reject(float factor, const Vector& axis) {
        x -= factor*axis.x; y -= factor*axis.y;
        z -= factor*axis.z; w -= factor*axis.w;
    }
    __forceinline void Set(float a, float b, float c, float d) {
        x = a; y = b; z = c; w = d;
    }
    __forceinline void Cross(const Vector& a, const Vector& b) {
        const float crossX = a.At(1)*b.At(2) - a.At(2)*b.At(1);
        const float crossY = a.At(2)*b.At(0) - a.At(0)*b.At(2);
        const float crossZ = a.At(0)*b.At(1) - a.At(1)*b.At(0);
        Set(crossX, crossY, crossZ, 0.0f);
    }
};
}

// Fake match: static/noinline and the emission caller below recover the private register ABI.
// pdb: takeStepAxes | hkGeometryUtility.obj | tesv_win, objrun_prop, low
static __declspec(noinline) void FUN_009e9c60(const Step9c60::Vector* source, Step9c60::Vector* delta, float step, Step9c60::Vector* output)
{
    for (int index = 0; index < 2; ++index) {
        output[index] = source[index];
        output[index].Integrate(step, delta[index]);
    }
    output[0].Normalize();
    float projection = output[1].Dot(output[0]);
    output[1].Reject(projection, output[0]);
    output[1].Normalize();
    // Fake match: named input references preserve cross-product operand ranking.
    const Step9c60::Vector& first = output[0];
    const Step9c60::Vector& second = output[1];
    output[2].Cross(first, second);
    output[2].Normalize();
}

// Fake match: volatile inputs keep the private-ABI emission caller from specializing the function.
const Step9c60::Vector* volatile g_source9c60;
Step9c60::Vector* volatile g_delta9c60;
Step9c60::Vector* volatile g_output9c60;
volatile float g_step9c60;
void caller_of_9c60() { FUN_009e9c60(g_source9c60, g_delta9c60, g_step9c60, g_output9c60); }
}   // namespace f3m_009e9c60

// @f3 0x009e34d0 (community match, verified in this file)
namespace f3m_009e34d0 {
struct FUN_009e34d0_Mesh {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int bits;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    unsigned int triangles;
    int count;
    unsigned int shapes;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int* single;

    int* FUN_009e34d0(int k);
};

// pdb: hkpExtendedMeshShape::getMeshMaterial | hkpExtendedMeshShape.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: key
int* FUN_009e34d0_Mesh::FUN_009e34d0(int k)
{
    unsigned int index = ((unsigned int)k & 0x7fffffffu) >> (32 - bits);
    if (((unsigned int)k & 0x80000000u) == 0) {
        if (count == 1) return single;
        index <<= 6;
        index += triangles;
        return *(int* volatile*)(index + 12);
    } else {
        index <<= 6;
        index += shapes;
        return *(int* volatile*)(index + 12);
    }
}
}   // namespace f3m_009e34d0

// @f3 0x009f9800 (community match, verified in this file)
extern int DAT_01268798;
extern const double DAT_01012060;
namespace f3m_009f9800 {
// Ball-and-socket Jacobian builder: three linear rows (one per world axis) with a
// stabilised right-hand side. Stand-in types; fields are named by offset.
struct Matrix;
struct __declspec(align(16)) V4 {
 float x,y,z,w;__forceinline void exterior(const V4& a,const V4& b) {
 float p=a.y*b.z-a.z*b.y, q=a.z*b.x-a.x*b.z, t=a.x*b.y-a.y*b.x;
 x=p;y=q;z=t;w=0.0f;
}
__forceinline void operator=(const V4& v) {x=v.x;y=v.y;z=v.z;w=v.w;}
__forceinline void turn(const Matrix* m,const V4& v);

 __forceinline void product(const V4& l,const V4& r) {x=l.x*r.x;y=l.y*r.y;z=l.z*r.z;w=l.w*r.w;}
 // the same product with the first factor of x read into a named value first
 __forceinline void productNamedX(const V4& l,const V4& r) {float lx=l.x;x=lx*r.x;y=l.y*r.y;z=l.z*r.z;w=l.w*r.w;}

 void FUN_00477880(const Matrix* matrix,const V4* vector);
};
struct Matrix {
 V4 c0,c1,c2;
 __forceinline const float& element(int r,int c)const {return (&(&c0)[c].x)[r];}
};
__forceinline void V4::turn(const Matrix* m,const V4& v) {
 float a=v.x,b=v.y,c=v.z;
 x=m->element(0,0)*a+m->element(0,1)*b+m->element(0,2)*c;
 y=m->element(1,0)*a+m->element(1,1)*b+m->element(1,2)*c;
 z=m->element(2,0)*a+m->element(2,1)*b+m->element(2,2)*c;
 w=0.0f;
}
struct Body {
 unsigned char unk00,unk01,unk02,unk03;
 int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 V4 unk20,unk30,unk40; Matrix unk50;
};
struct Input {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
 float unk1c,unk20;
 int unk24,unk28,unk2c;
 Body* unk30; Body* unk34;
};
struct Motion { V4 unk00,unk10,unk20,unk30; };
struct Row { V4 axis,a,b; };
static inline void sub(V4& r,const V4& a,const V4& b) { r.x=a.x-b.x; r.y=a.y-b.y; r.z=a.z-b.z; r.w=a.w-b.w; }

// pdb: buildJacobianFromBallSocketAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
void FUN_009f9800(Input* input,Motion* ma,Motion* mbarg,Row** output) {
 int firstAxis=0;
 int axisCount=3;
 int schemaType=5;
 float cnt=1.0f/input->unk1c;
 Motion* ptr;
 ptr = *(Motion* volatile*)&mbarg;
 Body* y;
 y = input->unk30;
 Body* b;
 Row* n;
 n = *output;
 b = input->unk34;
 V4 dv; sub(dv,ptr->unk30,ma->unk30);
 {
 V4 ra; sub(ra,ma->unk30,y->unk40);
 V4 rb; sub(rb,ptr->unk30,b->unk40);
 V4 wa,wb;
 wa.FUN_00477880(&y->unk50,&y->unk20);
 wb.FUN_00477880(&b->unk50,&b->unk20);
 V4 ca; ca.exterior(ra,wa);
 V4 cb; cb.exterior(rb,wb);
 dv.x+=cnt * cb.x; dv.y+=cb.y*cnt; dv.z+=cnt * cb.z; dv.w+=DAT_01012060*cnt;
 dv.x-=ca.x*cnt; dv.y-=cnt * ca.y; dv.z-=ca.z*cnt; dv.w-=DAT_01012060*cnt;
 }
 const V4* normal=(const V4*)&DAT_01268798;
 for(int i=firstAxis;i < axisCount;i++,normal++) {
  Body* other=b;
  const V4& q=*normal;
  int kk=i;
  float x=input->unk20,dt=input->unk1c;
  n->axis.x=q.x;n->axis.y=q.y;n->axis.z=q.z;n->axis.w=q.w;
  {
  // arm of the second body: its centre is read into a named value per component
  V4 r1,r2; sub(r1,ma->unk30,y->unk40); { float centre=other->unk40.x; r2.x=ptr->unk30.x-centre; } { float centre=other->unk40.y; r2.y=ptr->unk30.y-centre; } { float centre=other->unk40.z; r2.z=ptr->unk30.z-centre; }
  V4 c1; c1.exterior(r1,q);
  if(y->unk01) { n->a=c1; }
  else { n->a.turn(&y->unk50,c1); }

  V4 c2; c2.exterior(q,r2);
  if(b->unk01) { n->b=c2; }
  else { n->b.turn(&b->unk50,c2); }

  }
  V4 sa,sb;
  sa.product(n->a,n->a);
  sb.productNamedX(n->b,n->b);
  // inverse inertia weighting: each factor is read into a named value, then multiplied in
  { float inv=y->unk30.x; sa.x*=inv; }
  { float inv=y->unk30.y; sa.y*=inv; }
  { float inv=y->unk30.z; sa.z*=inv; }
  { float inv=other->unk30.x; sb.x*=inv; }
  { float inv=b->unk30.y; sb.y*=inv; }
  { float inv=b->unk30.z; sb.z*=inv; }
  sa.x=sb.x+sa.x;sa.y=sa.y + sb.y;sa.z=sb.z+sa.z;sa.w=b->unk30.w+y->unk30.w;
  float kIter;
  kIter = sa.y + sa.x + sa.z + sa.w;
  kIter+=1.1920928955078125e-7;
  n->b.w=kIter;n->a.w=x/kIter;
  V4 diff; sub(diff,ptr->unk30,ma->unk30);
  float val;
  val = diff.x * q.x+diff.y * q.y+q.z*diff.z;
  n->axis.w=val*dt;
  n->axis.w=(&dv.x)[kk]*input->unk1c;
  n->axis.x+=1.1920928955078125e-7;
  *(unsigned char*)&n->axis.x=(unsigned char)schemaType;
  ++n;
 }
 *output=n;
}
}   // namespace f3m_009f9800

// @f3 0x009f8810 (community match, verified in this file)
namespace f3m_009f8810 {
// Ball-and-socket Jacobian builder taking the two pivots directly: three linear rows
// (one per world axis) with a stabilised right-hand side. Stand-in types.
struct MatrixF;
struct __declspec(align(16)) VecF {
 union {struct{float x,y,z,w;};float values[4];};
 void sub4(const VecF& a,const VecF& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
 void sub3(const VecF& a,const VecF& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;}
 __forceinline void cross(const VecF& a,const VecF& b){float cx=a.y*b.z-a.z*b.y,cy=a.z*b.x-a.x*b.z,cz=a.x*b.y-a.y*b.x;x=cx;y=cy;z=cz;w=0.0f;}
 void addMul(const VecF& a,float f){x+=a.x*f;y+=a.y*f;z+=a.z*f;w+=0.0f*f;}
 void subMul(const VecF& a,float f){x-=a.x*f;y-=a.y*f;z-=a.z*f;w-=0.0f*f;}
 void mul4(const VecF& a,const VecF& b){x=a.x*b.x;y=a.y*b.y;z=a.z*b.z;w=a.w*b.w;}
 // the same product with the first factor of x read into a named value first
 void mul4NamedX(const VecF& a,const VecF& b){float ax=a.x;x=ax*b.x;y=a.y*b.y;z=a.z*b.z;w=a.w*b.w;}
 void add3(const VecF& a){x+=a.x;y+=a.y;z+=a.z;}
 void store(VecF& a)const{a.x=x;a.y=y;a.z=z;a.w=w;}
 float dot3(const VecF& a)const{return x*a.x+y*a.y+z*a.z;}
 void FUN_00477880(const void*,const VecF&);
 __forceinline void rotate(const MatrixF&,const VecF&);
};
struct MatrixF{VecF c0,c1,c2;
 __forceinline void transform(VecF& out,const VecF& v)const{
 float vx=v.x,vy=v.y,vz=v.z;
 out.x=c0.x*vx+c1.x*vy+c2.x*vz;
 out.y=c0.y*vx+c1.y*vy+c2.y*vz;
 out.z=c0.z*vx+c1.z*vy+c2.z*vz;
 }
};
__forceinline void VecF::rotate(const MatrixF& m,const VecF& v){
 float vx=v.x,vy=v.y,vz=v.z;
 x=m.c0.x*vx+m.c1.x*vy+m.c2.x*vz;
 y=m.c0.y*vx+m.c1.y*vy+m.c2.y*vz;
 z=m.c0.z*vx+m.c1.z*vy+m.c2.z*vz;
 w=0.0f;
}
struct BodyF{
 unsigned char unk00,local,unk02,unk03;
 unsigned int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 VecF velocity,inertia,center;MatrixF basis;
};
struct InfoF{
 unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
 float timestep,scale;
 unsigned int unk24,unk28,unk2c;
 BodyF* first;BodyF* second;
};
struct RowF{VecF linear,angularA,angularB;};
extern VecF DAT_010f3370[3];
// pdb: _hkBallSocketConstraintBuildJacobian | hkpBuildJacobianFromAtoms.obj | fnv360_0721_beta, objrun + skyrim(objrun), high
void __cdecl _hkBallSocketConstraintBuildJacobian(const VecF& pointA,const VecF& pointB,const InfoF& info,RowF*& output){
 float inv=1.0f/info.timestep;
 BodyF* a=info.first;BodyF* b=info.second;
 VecF correction;correction.sub4(pointB,pointA);
 RowF* row=output;
 {
 VecF leverA;leverA.sub3(pointA,a->center);
 VecF leverB;leverB.sub3(pointB,b->center);
 VecF omegaA;omegaA.FUN_00477880(&a->basis,a->velocity);
 VecF omegaB;omegaB.FUN_00477880(&b->basis,b->velocity);
 VecF crossA;crossA.cross(leverA,omegaA);
 VecF crossB;crossB.cross(leverB,omegaB);
 correction.addMul(crossB,inv);correction.subMul(crossA,inv);
 }
 const VecF* axes=DAT_010f3370;
 for(int i=0;i<3;++i,++axes){
  BodyF* other=b;
  float rhs=info.scale;float time=info.timestep;
  const VecF& axis=*axes;axis.store(row->linear);
  VecF rA;rA.sub3(pointA,a->center);
  VecF rB;rB.sub3(pointB,b->center);
  VecF jA;jA.cross(rA,axis);
   if(a->local){jA.store(row->angularA);}
   else row->angularA.rotate(a->basis,jA);
  VecF jB;jB.cross(axis,rB);
   if(b->local){jB.store(row->angularB);}
   else row->angularB.rotate(b->basis,jB);
  VecF sqA;sqA.mul4(row->angularA,row->angularA);
  VecF sqB;sqB.mul4NamedX(row->angularB,row->angularB);
  // inverse inertia weighting; four factors are read into a named value first
  sqA.x=a->inertia.x*sqA.x;
  sqA.y=a->inertia.y*sqA.y;
  { float factor=a->inertia.z; sqA.z*=factor; }
  { float factor=b->inertia.x; sqB.x*=factor; }
  { float factor=b->inertia.y; sqB.y*=factor; }
  { float factor=other->inertia.z; sqB.z*=factor; }
  sqA.add3(sqB);
  sqA.w=b->inertia.w+a->inertia.w;
  float mass=sqA.x+sqA.y+sqA.z+sqA.w;
  mass=(float)(mass+1.1920928955078125e-7);
  row->angularB.w=mass;
  row->angularA.w=rhs/mass;
  VecF difference;{ float coord=pointB.x; difference.x=coord-pointA.x; } { float coord=pointB.y; difference.y=coord-pointA.y; } difference.z=pointB.z-pointA.z;
  float distance=axis.x*difference.x+difference.y*axis.y+axis.z*difference.z;
  row->linear.w=distance*time;
  row->linear.w=correction.values[i]*info.timestep;
  row->linear.x=(float)(row->linear.x+1.1920928955078125e-7);
  *(unsigned char*)&row->linear.x=5;
  ++row;
 }
 output=row;
}

}   // namespace f3m_009f8810

// @f3 0x009f80d0 (community match, verified in this file)
namespace f3m_009f80d0 {
// World transforms of the two constraint frames: out = bodyTransform * localTransform for body A
// and body B (hkTransform::setMul inlined twice, x87 build of Havok). Stand-in types.
// A static function: the compiler gives it a private calling convention (first output in ecx,
// the rest on the stack, caller pops), so one ordinary caller is defined below to have it emitted.
namespace f3m_009f80d0 {

struct hkRotation;

struct __declspec(align(16)) hkVector4 {
    float x, y, z, w;
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
    __forceinline void add4(const hkVector4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
};

struct hkRotation {
    hkVector4 c0, c1, c2;
    __forceinline hkRotation() {}
    __forceinline hkRotation(const hkRotation& r) : c0(r.c0), c1(r.c1), c2(r.c2) {}
    __forceinline float operator()(int r, int c) const { return (&(&c0)[c].x)[r]; }
};

__forceinline void hkVector4::_setRotatedDir(const hkRotation& a, const hkVector4& b)
{
    const float v0 = b.x;
    const float v1 = b.y;
    const float v2 = b.z;
    x = a(0, 0) * v0 + a(0, 1) * v1 + a(0, 2) * v2;
    y = a(1, 0) * v0 + a(1, 1) * v1 + a(1, 2) * v2;
    z = a(2, 0) * v0 + a(2, 1) * v1 + a(2, 2) * v2;
    w = 0.0f;
}

// hkVector4Util::rotatePoints: rotates through a local copy of the matrix, last vector first.
static __forceinline void rotatePoints(const hkRotation& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkRotation unaligned_t = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setRotatedDir(unaligned_t, vectorsIn[i]);
    } while (--i >= 0);
}

struct hkTransform {
    hkRotation m_rotation;
    hkVector4 m_translation;
    __forceinline void setMul(const hkTransform& aTb, const hkTransform& bTc)
    {
        rotatePoints(aTb.m_rotation, &bTc.m_rotation.c0, 4, &m_rotation.c0);
        m_translation.add4(aTb.m_translation);
    }
};

struct Atom {
    unsigned int unk00, unk04, unk08, unk0c;
    hkTransform m_transformA;
    hkTransform m_transformB;
};

struct Bodies {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34;
    const hkTransform* m_transformA;
    const hkTransform* m_transformB;
};

// pdb: setLocalTransformsFromAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0721_beta, objopen_prop, low
static __declspec(noinline) void FUN_009f80d0(hkTransform* outA, const Atom* atom, const Bodies* bodies, hkTransform* outB)
{
    outA->setMul(*bodies->m_transformA, atom->m_transformA);
    outB->setMul(*bodies->m_transformB, atom->m_transformB);
}

hkTransform* volatile g_outA;
const Atom* volatile g_atom;
const Bodies* volatile g_bodies;
hkTransform* volatile g_outB;

void Caller_009f80d0()
{
    FUN_009f80d0(g_outA, g_atom, g_bodies, g_outB);
}

}
}   // namespace f3m_009f80d0

// @f3 0x009f9370 (community match, verified in this file)
namespace f3m_009f9370 {
typedef float hkReal;

struct hkRotation;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    __forceinline hkVector4() {}
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline void setNeg4(const hkVector4& v) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    __forceinline void mul4(const hkVector4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    __forceinline hkReal horizontalAdd3() const { return x + y + z; }
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& b);
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
};
__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    const hkVector4& c0 = r.getColumn(0);
    const hkVector4& c1 = r.getColumn(1);
    const hkVector4& c2 = r.getColumn(2);
    this->x = c0(0) * v0 + c1(0) * v1 + c2(0) * v2;
    this->y = c0(1) * v0 + c1(1) * v1 + c2(1) * v2;
    this->z = c0(2) * v0 + c1(2) * v1 + c2(2) * v2;
    this->w = 0;
}

struct hkpVelocityAccumulator
{
    unsigned char m_type;
    unsigned char m_matrixIsIdentity;
    unsigned int m_deactivationClass;
    hkReal m_gravityFactor;
    hkVector4 m_linearVel;
    hkVector4 m_angularVel;
    hkVector4 m_invMasses;
    hkVector4 m_scratch0;
    hkRotation m_coreFromWorldMatrix;
    __forceinline const hkRotation& getCoreFromWorldMatrix() const { return m_coreFromWorldMatrix; }
};

struct hkpConstraintQueryIn
{
    hkReal m_subStepDeltaTime;
    hkReal m_microStepDeltaTime;
    hkReal m_subStepInvDeltaTime;
    hkReal m_frameDeltaTime;
    hkReal m_frameInvDeltaTime;
    hkReal m_invNumSteps;
    hkReal m_invNumStepsTimesMicroSteps;
    hkReal m_maxConstraintViolationSqrd;
    hkReal m_rhsFactor;
    hkReal m_virtMassFactor;
    hkReal m_frictionRhsFactor;
    hkReal m_unk2c;
    const hkpVelocityAccumulator* m_bodyA;
    const hkpVelocityAccumulator* m_bodyB;
};

struct hkp2AngJacobian
{
    hkVector4 m_angular[2];
    __forceinline hkReal getAngularDiag(const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB) const
    {
        // the named reference for the first row (instead of m_angular[0] twice) sets the order of the fourth
        // inverse-mass multiply (local first) and of the first two adds; it emits no code of its own.
        const hkVector4& a0 = m_angular[0];
        hkVector4 ang0; ang0.setMul4(a0, a0);
        hkVector4 ang1; ang1.setMul4(m_angular[1], m_angular[1]);
        ang0.mul4(mA.m_invMasses);
        ang1.mul4(mB.m_invMasses);
        // ang0 += ang1, written per component: the indexed form for x and y and the member form for z and w is
        // what reproduces the original operand order of the three adds (ang1 first for x and y, ang0 first for z);
        // add4() or a single spelling for all four components gives another order. A guess at the source.
        ang0(0) += ang1(0); ang0(1) += ang1(1); ang0.z += ang1.z; ang0.w += ang1.w;
        return ang0.horizontalAdd3();
    }
};

struct hkp1dBilateralConstraintStatus
{
    hkReal m_virtualMass;
};

static __forceinline void rotateToCore(const hkpVelocityAccumulator* m, const hkVector4& dir, hkVector4& out)
{
    if (m->m_matrixIsIdentity)
    {
        out = dir;
    }
    else
    {
        out._setRotatedDir(m->getCoreFromWorldMatrix(), dir);
    }
}

static __forceinline void rotateNegToCore(const hkpVelocityAccumulator* m, const hkVector4& dir, hkVector4& out)
{
    if (m->m_matrixIsIdentity)
    {
        out.setNeg4(dir);
    }
    else
    {
        hkVector4 d; d.setNeg4(dir);
        out._setRotatedDir(m->getCoreFromWorldMatrix(), d);
    }
}

// pdb: _hk1dAngularVelocityMotorBeginJacobian | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) void FUN_009f9370(const hkVector4& directionOfConstraint, const hkpConstraintQueryIn& in, hkp2AngJacobian* jac, hkp1dBilateralConstraintStatus& statusOut)
{
    const hkVector4& dir = directionOfConstraint;
    const hkpVelocityAccumulator* mB = in.m_bodyB;
    const hkpVelocityAccumulator* mA = in.m_bodyA;
    hkp2AngJacobian& j = *jac;
    rotateToCore(mA, dir, j.m_angular[0]);
    rotateNegToCore(mB, dir, j.m_angular[1]);
    hkReal dJ = j.getAngularDiag(*mA, *mB);
    dJ = dJ + 1.1920928955078125e-7;
    hkReal virtualMass = 1.0f / dJ;
    j.m_angular[0].w = virtualMass;
    statusOut.m_virtualMass = virtualMass;
}

const hkVector4* volatile g_dir;
const hkpConstraintQueryIn* volatile g_in;
hkp2AngJacobian* volatile g_jac;
hkp1dBilateralConstraintStatus* volatile g_status;

void Caller_009f9370()
{
    FUN_009f9370(*g_dir, *g_in, g_jac, *g_status);
}
}   // namespace f3m_009f9370

// @f3 0x009efd00 (community match, verified in this file)
namespace f3m_009efd00 {
// Havok 5.5 hkpVehicleViewer::postSimulationCallback (FPU build). FNV twin
// hkpVehicleViewer::FUN_00d63680 (hkpvehicleviewer_ehsc_noehsc_variant_rtm_variant.cpp).
// FO3's displayLine takes (start, end, color, tag): no collidable id.


__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

namespace N9efd00 {

extern unsigned long DAT_0116913c;
extern unsigned long DAT_010f3170;
extern int DAT_011697e8;

typedef float hkReal;
typedef signed char hkInt8;


struct ProfRec {
    const char* m_pName;
    unsigned int m_iTick;
    int unk08;
    __forceinline void stamp()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_iTick = ticks;
    }
};
struct ProfBuf { int unk00; char* m_pCur; int unk08; char* m_pRecordEnd; };

static __forceinline void clockOne(const char* name)
{
    ProfBuf& stream = *(ProfBuf*)FUN_00d9b080(DAT_0116913c);
    if (stream.m_pCur < stream.m_pRecordEnd) {
        ProfRec* command = (ProfRec*)stream.m_pCur;
        command->m_pName = name;
        command->stamp();
        stream.m_pCur = (char*)(command + 1);
    }
}

struct hkThreadMemory {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* p);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_current;
    int unk24;
    char* m_base;
    char* m_end;

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)FUN_00d9b080(DAT_010f3170);
    }
    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = (nbytes + 16) & ~15;
        char* current = m_current;
        void* ret;
        if (current + nbytes <= m_end)
        {
            m_current = current + nbytes;
            ret = current;
        }
        else
        {
            ret = onStackOverflow(nbytes);
        }
        return ret;
    }
    __forceinline void deallocateStack(void* p)
    {
        m_current = (char*)p;
        if (p == m_base)
            onStackUnderflow(p);
    }
};

template <class T>
__forceinline T* hkAllocateStack(int n)
{
    return (T*)hkThreadMemory::getInstance().allocateStack(n * sizeof(T));
}
template <class T>
__forceinline void hkDeallocateStack(T* p)
{
    hkThreadMemory::getInstance().deallocateStack(p);
}

struct hkQuaternion;

struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    // The named first lane emits no code of its own; it is a guess at the source: it sets the x87 operand order of
    // the spoke normalize (+0x346..+0x368, x and y factor first, z lane first) without moving any other site.
    __forceinline void operator=(const hkVector4& v) { hkReal vx = v.x; x = vx; y = v.y; z = v.z; w = v.w; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void add4(const hkVector4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline void mul4(hkReal s) { x *= s; y *= s; z *= s; w *= s; }
    __forceinline void setMul4(hkReal r, const hkVector4& a) { x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
    __forceinline void addMul4(const hkReal& r, const hkVector4& a) { hkReal f = r; x += f * a.x; y += f * a.y; z += f * a.z; w += f * a.w; }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r) { x = a.x + r * b.x; y = a.y + r * b.y; z = a.z + r * b.z; w = a.w + r * b.w; }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1.y * v2.z - v1.z * v2.y;
        const hkReal ny = v1.z * v2.x - v1.x * v2.z;
        const hkReal nz = v1.x * v2.y - v1.y * v2.x;
        set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return x * a.x + y * a.y + z * a.z; }
    __forceinline hkReal lengthSquared3() const { return dot3(*this); }
    __forceinline void normalize3();
    __forceinline hkReal lengthInverse3() const;
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

namespace hkMath
{
    __forceinline hkReal sqrt(hkReal r) { return hkReal(::sqrt(r)); }
    __forceinline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

// Havok FPU form: the inverse length is a conditional expression through hkMath::sqrtInverse. Written as an
// if/else into a named local instead, the y lane of the normalize multiply comes out lane first (+0x350).
__forceinline hkReal hkVector4::lengthInverse3() const
{
    hkReal l2 = lengthSquared3();
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}
__forceinline void hkVector4::normalize3() { mul4(lengthInverse3()); }



struct hkQuaternion
{
    hkVector4 m_vec;
    hkQuaternion(const hkVector4& axis, hkReal angle);
    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec(3); }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.getReal();
    hkReal q2minus1 = qreal * qreal - 0.5;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    setAdd4(ret, ret);
}

template <class T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline int getSize() const { return m_size; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
};

struct hkColor
{
    enum ExtendedColors
    {
        RED = 0xFFFF0000,
        YELLOWGREEN = 0xFF9ACD32,
        ROSYBROWN = 0xFFBC8F8F,
        WHITESMOKE = 0xFFF5F5F5
    };
};

struct hkDebugDisplayHandler
{
    virtual ~hkDebugDisplayHandler();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int displayLine(const hkVector4& start, const hkVector4& end, int color, int tag);
};

struct hkpRigidBody;
struct hkpWorld;

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
    __forceinline const hkVector4& getPosition() const { return m_position; }
};

struct hkReferencedObject
{
    virtual ~hkReferencedObject();
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpVehicleData : hkReferencedObject
{
    struct WheelComponentParams
    {
        hkReal m_radius;
        hkReal m_mass;
        hkReal m_width;
        hkReal m_friction;
        hkReal m_viscosityFriction;
        hkReal m_maxFriction;
        hkReal m_slipAngle;
        hkReal m_forceFeedbackMultiplier;
        hkReal m_maxContactBodyAcceleration;
        hkInt8 m_axle;
    };
    int unk08;
    int unk0c;
    hkVector4 m_gravity;
    hkInt8 m_numWheels;
    hkVector4 m_chassisOrientation0;
    hkVector4 m_chassisOrientation1;
    hkVector4 m_chassisOrientation2;
    hkReal m_torqueRollFactor;
    hkReal m_torquePitchFactor;
    hkReal m_torqueYawFactor;
    hkReal m_extraTorqueFactor;
    hkReal m_maxVelocityForPositionalFriction;
    hkReal m_chassisUnitInertiaYaw;
    hkReal m_chassisUnitInertiaRoll;
    hkReal m_chassisUnitInertiaPitch;
    hkReal m_frictionEqualizer;
    hkReal m_normalClippingAngle;
    hkReal m_maxFrictionSolverMassRatio;
    hkArray<WheelComponentParams> m_wheelParams;
    hkArray<hkInt8> m_numWheelsPerAxle;
};

struct hkpVehicleInstance : hkReferencedObject
{
    struct WheelInfo
    {
        hkContactPoint m_contactPoint;
        hkReal m_contactFriction;
        hkpRigidBody* m_contactBody;
        unsigned int m_contactShapeKey;
        hkVector4 m_hardPointWs;
        hkVector4 m_rayEndPointWs;
        hkReal m_currentSuspensionLength;
        hkVector4 m_suspensionDirectionWs;
        hkVector4 m_spinAxisCs;
        hkVector4 m_spinAxisWs;
        hkVector4 m_steeringOrientationCs;
        hkReal m_spinVelocity;
        hkReal m_spinAngle;
        hkReal m_skidEnergyDensity;
        hkReal m_sideForce;
        hkReal m_forwardSlipVelocity;
        hkReal m_sideSlipVelocity;
    };
    void* m_world;
    void* m_island;
    unsigned long m_userData;
    const char* m_name;
    void* m_entity;
    hkpVehicleData* m_data;
    void* m_driverInput;
    void* m_steering;
    void* m_engine;
    void* m_transmission;
    void* m_brake;
    void* m_suspension;
    void* m_aerodynamics;
    void* m_wheelCollide;
    void* m_tyreMarks;
    void* m_velocityDamper;
    hkArray<WheelInfo> m_wheelsInfo;
};

struct hkProcess
{
    virtual ~hkProcess();
    hkDebugDisplayHandler* m_displayHandler;
    void* m_processHandler;
};

struct hkpPhysicsContextWorldListener
{
    virtual ~hkpPhysicsContextWorldListener();
};

struct hkpActionListener
{
    virtual void actionAddedCallback(void* action);
};

struct hkpWorldPostSimulationListener
{
    virtual ~hkpWorldPostSimulationListener();
    virtual void FUN_009efd00(hkpWorld* world) = 0;
};

struct hkpWorldViewerBase : hkReferencedObject, hkProcess, hkpPhysicsContextWorldListener
{
    void* m_context;
};

} // namespace N9efd00

using namespace N9efd00;

class hkpVehicleViewer : public hkpWorldViewerBase, public hkpActionListener, public hkpWorldPostSimulationListener
{
public:
    virtual void FUN_009efd00(hkpWorld* world);
    hkArray<hkpVehicleInstance*> m_vehicles;
};

// pdb: hkpVehicleViewer::postSimulationCallback | hkpVehicleViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void hkpVehicleViewer::FUN_009efd00(hkpWorld* world)
{
    clockOne("TthkpVehicleViewer::step");

    const int numVehicles = m_vehicles.getSize();
    const int numWheelSegments = 12;

    for (int i = 0; i < numVehicles; i++)
    {
        const hkpVehicleInstance* vehicle = m_vehicles[i];
        const int numWheels = vehicle->m_wheelsInfo.getSize();
        hkVector4* centerPoint = hkAllocateStack<hkVector4>(numWheels);

        for (int w = 0; w < numWheels; w++)
        {
            const hkpVehicleData::WheelComponentParams& wheelParam = vehicle->m_data->m_wheelParams[w];
            const hkpVehicleInstance::WheelInfo& wheel = vehicle->m_wheelsInfo[w];
            const hkVector4& contactPoint = wheel.m_contactPoint.getPosition();
            const hkVector4& hardPoint = wheel.m_hardPointWs;

            // A named colour for the suspension line (no code of its own): with it the function's local count gives
            // the original x87 operand order at +0x130 and +0x346 (the earlier drafts had a dead int here instead).
            const int suspensionColor = (wheel.m_contactBody) ? hkColor::RED : hkColor::ROSYBROWN;
            m_displayHandler->displayLine(contactPoint, hardPoint, suspensionColor, DAT_011697e8);

            centerPoint[w].setAddMul4(contactPoint, wheel.m_suspensionDirectionWs, -wheelParam.m_radius);

            {
                hkVector4 spoke;
                spoke = wheel.m_suspensionDirectionWs;
                hkQuaternion spokeRotation(wheel.m_spinAxisWs, -wheel.m_spinAngle);
                spoke.setRotatedDir(spokeRotation, spoke);
                spoke.normalize3();
                spoke.mul4(wheelParam.m_radius);
                hkVector4 start;
                start.setAdd4(centerPoint[w], spoke);
                hkVector4 end;
                end.setSub4(centerPoint[w], spoke);
                m_displayHandler->displayLine(start, end,
                    (wheel.m_contactBody) ? hkColor::WHITESMOKE : hkColor::ROSYBROWN, DAT_011697e8);
            }

            hkVector4 spokes[numWheelSegments];
            spokes[0].setMul4(wheelParam.m_radius, wheel.m_suspensionDirectionWs);
            hkQuaternion spokeRotation(wheel.m_spinAxisWs, 0.5235988f);
            for (int s = 1; s < numWheelSegments + 2; s++)
            {
                if (s < numWheelSegments)
                {
                    spokes[s].setRotatedDir(spokeRotation, spokes[s - 1]);
                }
                if (s <= numWheelSegments)
                {
                    // the reference to the centre is declared before the one to the spoke: that order gives the
                    // original operand order of the add4 lanes (+0x5f1..+0x60f)
                    const hkVector4& cc = centerPoint[w];
                    hkVector4& sp = spokes[s - 1];
                    sp.add4(cc);
                }
                if (s >= 2)
                {
                    m_displayHandler->displayLine(spokes[(s - 2) % numWheelSegments],
                        spokes[(s - 1) % numWheelSegments],
                        (wheel.m_contactBody) ? hkColor::WHITESMOKE : hkColor::ROSYBROWN, DAT_011697e8);
                }
            }
        }

        const int numAxles = vehicle->m_data->m_numWheelsPerAxle.getSize();
        for (int axle = 0; axle < numAxles; axle++)
        {
            hkVector4 a;
            hkVector4 b;
            bool firstTimeThrough = true;
            const int totalWheelsOnThisAxle = vehicle->m_data->m_numWheelsPerAxle[axle];
            int wheelsFoundOnThisAxle = 0;
            for (int w = 0; w < numWheels; w++)
            {
                const hkpVehicleData::WheelComponentParams& wheelParam = vehicle->m_data->m_wheelParams[w];
                if (wheelParam.m_axle != axle) continue;
                wheelsFoundOnThisAxle++;
                a = b;
                b = centerPoint[w];
                if (firstTimeThrough)
                {
                    firstTimeThrough = false;
                }
                else
                {
                    m_displayHandler->displayLine(a, b, hkColor::YELLOWGREEN, DAT_011697e8);
                }
                if (wheelsFoundOnThisAxle == totalWheelsOnThisAxle) break;
            }
        }

        hkDeallocateStack(centerPoint);
    }

    clockOne("Et");
}

}   // namespace f3m_009efd00

// @f3 0x009fb4b0 (community match, verified in this file)
namespace f3m_009fb4b0 {
// Havok pulley constraint: builds the 2-linear/2-angular jacobian row (schema byte 10) from the pulley info.
// Matches under /MT /O2 /GS /EHsc /Gy (the pack lists /Od, but the target is optimised code with an aligned frame).


extern float DAT_010f3370[4];

namespace f3m_009fb4b0 {
__forceinline float root(float value) { return sqrtf(value); }

__forceinline float S9fb4b0_sqrtInverse(float);
struct __declspec(align(16)) S9fb4b0_Vec4 {
    float x, y, z, w;
    S9fb4b0_Vec4() {}
    S9fb4b0_Vec4(const S9fb4b0_Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    S9fb4b0_Vec4& operator=(const S9fb4b0_Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void setSub4(const S9fb4b0_Vec4& a, const S9fb4b0_Vec4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline void setNeg4(const S9fb4b0_Vec4& a) { x = -a.x; y = -a.y; z = -a.z; w = -a.w; }
    __forceinline void setCross(const S9fb4b0_Vec4& v1, const S9fb4b0_Vec4& v2) {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        x = nx; y = ny; z = nz; w = 0.0f;
    }
    __forceinline void rotC(const S9fb4b0_Vec4* m, const S9fb4b0_Vec4& c) {
        x = m[0].x * c.x + m[1].x * c.y + m[2].x * c.z;
        y = m[0].y * c.x + m[1].y * c.y + m[2].y * c.z;
        z = m[0].z * c.x + m[1].z * c.y + m[2].z * c.z;
        w = 0.0f;
    }
    __forceinline float lengthSquared3() const { return x * x + y * y + z * z; }
    __forceinline void setMul4(const S9fb4b0_Vec4& a, const S9fb4b0_Vec4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    __forceinline void mul4(float r) { x *= r; y *= r; z *= r; w *= r; }
    __forceinline void mul4V(const S9fb4b0_Vec4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    __forceinline float length3() const { return root(lengthSquared3()); }
};

__forceinline float S9fb4b0_sqrtInverse(float r)
{
    float result;
    if (r != 0.0f)
        result = 1.0f / root(r);
    else
        result = 0.0f;
    return result;
}

struct S9fb4b0_Body {
    unsigned char m_type;
    unsigned char m_matrixIsIdentity;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int unk08;
    int unk0c;
    S9fb4b0_Vec4 m_linearVel;
    S9fb4b0_Vec4 m_angularVel;
    S9fb4b0_Vec4 m_invMasses;
    S9fb4b0_Vec4 m_centerOfMass;
    S9fb4b0_Vec4 m_rot[3];
};

struct S9fb4b0_In {
    int unk00;
    int unk04;
    float m_tau;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float m_damping;
    int unk24;
    int unk28;
    int unk2c;
    S9fb4b0_Body* m_bodyA;
    S9fb4b0_Body* m_bodyB;
};

struct S9fb4b0_Jac {
    S9fb4b0_Vec4 m_linear0;
    S9fb4b0_Vec4 m_linear1;
    S9fb4b0_Vec4 m_angular0;
    S9fb4b0_Vec4 m_angular1;
};

struct S9fb4b0_Out {
    S9fb4b0_Jac* m_jac;
};

struct S9fb4b0_Info {
    S9fb4b0_Vec4 m_posA;
    S9fb4b0_Vec4 m_posB;
    S9fb4b0_Vec4 m_pivotA;
    S9fb4b0_Vec4 m_pivotB;
    float m_ropeLength;
    float m_leverage;
};

struct S9fb4b0_Work {
    S9fb4b0_Body* m_bodyA;
    S9fb4b0_Body* m_bodyB;
    S9fb4b0_Vec4 m_posA;
    S9fb4b0_Vec4 m_posB;
    S9fb4b0_Vec4 m_dirA;
    S9fb4b0_Vec4 m_dirB;
    S9fb4b0_Vec4 m_pivotA;
    S9fb4b0_Vec4 m_pivotB;
    float m_ropeLength;
    float m_leverage;
    float m_tau;
    float m_damping;
};

static __forceinline void buildRows(const S9fb4b0_Work& w, S9fb4b0_Jac* jac)
{
    S9fb4b0_Body* bodyA = w.m_bodyA;
    S9fb4b0_Body* bodyB = w.m_bodyB;
    const float leverage = w.m_leverage;
    S9fb4b0_Vec4 t;
    t.x = leverage * w.m_dirB.x;
    t.y = leverage * w.m_dirB.y;
    t.z = leverage * w.m_dirB.z;
    t.w = leverage * w.m_dirB.w;
    jac->m_linear0 = w.m_dirA;
    jac->m_linear1 = t;

    S9fb4b0_Vec4 rA;
    S9fb4b0_Vec4 rB;
    rA.x = w.m_posA.x - bodyA->m_centerOfMass.x;
    rA.y = w.m_posA.y - bodyA->m_centerOfMass.y;
    rA.z = w.m_posA.z - bodyA->m_centerOfMass.z;
    rB.x = w.m_posB.x - bodyB->m_centerOfMass.x;
    rB.y = w.m_posB.y - bodyB->m_centerOfMass.y;
    rB.z = w.m_posB.z - bodyB->m_centerOfMass.z;
    {
        S9fb4b0_Vec4 c;
        c.setCross(rA, w.m_dirA);
        if (bodyA->m_matrixIsIdentity) {
            jac->m_angular0 = c;
        } else {
            jac->m_angular0.rotC(bodyA->m_rot, c);
        }
    }
    {
        S9fb4b0_Vec4 c;
        c.setCross(t, rB);
        if (bodyB->m_matrixIsIdentity) {
            jac->m_angular1 = c;
        } else {
            jac->m_angular1.rotC(bodyB->m_rot, c);
        }
    }

    {
        S9fb4b0_Vec4 a;
        a.setMul4(jac->m_angular0, jac->m_angular0);
        S9fb4b0_Vec4 b;
        b.setMul4(jac->m_angular1, jac->m_angular1);
        a.mul4V(bodyA->m_invMasses);
        b.mul4V(bodyB->m_invMasses);
        // a += b spelled per component: the named x term and operator() for y and z reproduce the original
        // operand order of the three adds (b loaded first); other spellings flip one of them. A guess at the source.
        { float ax = a.x; a.x = ax + b.x; }
        a(1) += b(1);
        a(2) += b(2);
        a.w += b.w;
        float lev2 = w.m_leverage * w.m_leverage;
        float invMass = lev2 * bodyB->m_invMasses.w + bodyA->m_invMasses.w + 1.1920928955078125e-07;
        float sum = a.y + a.x + a.z;
        float denom = invMass + sum;
        jac->m_angular0.w = w.m_damping / denom;
    }

    {
        S9fb4b0_Vec4 d1;
        d1.x = w.m_pivotA.x - w.m_posA.x;
        d1.y = w.m_pivotA.y - w.m_posA.y;
        d1.z = w.m_pivotA.z - w.m_posA.z;
        S9fb4b0_Vec4 d2;
        d2.x = w.m_posB.x - w.m_pivotB.x;
        d2.y = w.m_posB.y - w.m_pivotB.y;
        d2.z = w.m_posB.z - w.m_pivotB.z;
        float len = d1.length3() + d2.length3() * w.m_leverage;
        float err = len - w.m_ropeLength;
        jac->m_linear0.w = err * w.m_tau;
    }
}

// A static function: the compiler gives it a private convention with the info pointer in esi (compiler_tips.md,
// "Inputs in registers"). __restrict on the output lets the cursor store be scheduled into the final float code
// as in the original; without it only that store moves (a guess at the source).
// pdb: hkPulleyConstraintBuildJacobian | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) void FUN_009fb4b0(const S9fb4b0_Info* info, const S9fb4b0_In* in, S9fb4b0_Out* __restrict out)
{
    S9fb4b0_Body* bodyA = in->m_bodyA;
    S9fb4b0_Body* bodyB = in->m_bodyB;
    S9fb4b0_Jac* jac = out->m_jac;
    const S9fb4b0_Vec4& identity = *(const S9fb4b0_Vec4*)DAT_010f3370;
    const float eps = 1.192092896e-07f;
    S9fb4b0_Work w;
    w.m_dirA.setSub4(info->m_pivotA, info->m_posA);
    w.m_dirB.setSub4(info->m_posB, info->m_pivotB);

    {
        float len2 = w.m_dirA.lengthSquared3();
        bool ok = len2 > eps;
        if (ok) {
            float invLen = S9fb4b0_sqrtInverse(w.m_dirA.lengthSquared3());
            w.m_dirA.mul4(invLen);
        } else {
            w.m_dirA.x = identity.x;
            w.m_dirA.y = identity.y;
            w.m_dirA.z = identity.z;
            w.m_dirA.w = identity.w;
        }
    }
    {
        float len2 = w.m_dirB.lengthSquared3();
        bool ok = len2 > eps;
        if (ok) {
            float invLen = S9fb4b0_sqrtInverse(w.m_dirB.lengthSquared3());
            w.m_dirB.mul4(invLen);
        } else {
            w.m_dirB.setNeg4(identity);
        }
    }

    w.m_bodyA = bodyA;
    w.m_bodyB = bodyB;
    w.m_posA = info->m_posA;
    w.m_posB = info->m_posB;
    w.m_pivotA = info->m_pivotA;
    w.m_pivotB = info->m_pivotB;
    w.m_ropeLength = info->m_ropeLength;
    w.m_leverage = info->m_leverage;
    w.m_tau = in->m_tau;
    w.m_damping = in->m_damping;

    buildRows(w, jac);
    out->m_jac = jac + 1;
    jac->m_linear0.x = (float)(jac->m_linear0.x + 1.1920928955078125e-07);
    *(unsigned char*)&jac->m_linear0 = 10;
}

// Caller that makes the compiler emit the static function; volatile inputs keep it from specialising the call.
const S9fb4b0_Info* volatile g_info;
const S9fb4b0_In* volatile g_in;
S9fb4b0_Out* volatile g_out;

void Caller_009fb4b0()
{
    FUN_009fb4b0(g_info, g_in, g_out);
}

}

}   // namespace f3m_009fb4b0

// @f3 0x009e8450 (community match, verified in this file)
extern unsigned long g_hkMonitorStreamTlsIndex;
namespace f3m_009e8450 {
// hkpConvexVerticesShape::castRay (x87 build of Havok): clip the ray against the plane equations.
// The code is optimised: it matches under /MT /O2 /GS /EHsc /Gy, not under the listed /Od flags.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct hkMonitorStream
{
    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;
};
struct hkTimerCommand
{
    const char* m_commandAndMonitor;
    unsigned int m_time;
    void* m_unk08;
};
// HK_TIMER_BEGIN / HK_TIMER_END: Havok reads the clock with these two assembly lines.
inline void hkTimerCommandMark(const char* name)
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(g_hkMonitorStreamTlsIndex);
    hkTimerCommand* cmd = (hkTimerCommand*)stream->m_end;
    if ((char*)cmd < stream->m_capacityMinus16)
    {
        cmd->m_commandAndMonitor = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        cmd->m_time = ticks;
        stream->m_end = (char*)(cmd + 1);
    }
}
struct hkBool
{
    char m_bool;
    hkBool(bool b)
    {
        m_bool = (char)b;
    }
};
struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;
    void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    float dot4xyz1(const hkVector4& a) const
    {
        return x * a.x + y * a.y + z * a.z + w;
    }
};
struct hkpShapeRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
};
struct hkpShapeRayCastOutput
{
    hkVector4 m_normal;
    float m_hitFraction;
    int unk14;
    int unk18;
    int unk1C;
    int m_shapeKeys[8];
    int m_shapeKeyIndex;
};
template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};
class hkpConvexPlanesShape
{
  public:
    int unk00[20];
    hkArray<hkVector4> m_planeEquations;
    hkBool FUN_009e8450(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
};
// pdb: hkpConvexVerticesShape::castRayImpl | hkpConvexVerticesShape.obj | fnv360_0822_retail, ustr, medium
// pdb params: input, results
hkBool hkpConvexPlanesShape::FUN_009e8450(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const
{
    hkTimerCommandMark("TtrcConvexVert");
    float minT = -1.0f;
    float maxT = results.m_hitFraction;
    hkVector4 bestNormal;
    bestNormal.x = bestNormal.y = bestNormal.z = bestNormal.w = 0.0f;
    for (int i = m_planeEquations.m_size - 1; i >= 0; i--)
    {
        const hkVector4& plane = m_planeEquations.m_data[i];
        const hkVector4& from = input.m_from;
        float dFrom = plane.dot4xyz1(from);
        // Fake match: the second distance reads the plane through its own named pointer and is written out lane by
        // lane; with plane.dot4xyz1(input.m_to) the z term loads the plane lane first (fld [ecx+8]; fmul [edi+0x18]).
        const hkVector4* plane2 = &plane;
        float dTo = plane2->x * input.m_to.x + plane2->y * input.m_to.y + plane2->z * input.m_to.z + plane2->w;
        if (dFrom >= 0.0f)
        {
            if (dTo >= 0.0f)
            {
                hkTimerCommandMark("Et");
                return false;
            }
            float t = dFrom / (dFrom - dTo);
            if (t >= minT)
            {
                minT = t;
                bestNormal = plane;
            }
        }
        else
        {
            if (!(dTo >= 0.0f))
                continue;
            float t;
            t = dFrom / (dFrom - dTo);
            maxT = (t > maxT) ? maxT : t;
        }
        if (maxT < minT)
        {
            hkTimerCommandMark("Et");
            return false;
        }
    }
    if (minT < 0.0f)
    {
        hkTimerCommandMark("Et");
        return false;
    }
    results.m_normal = bestNormal;
    results.m_hitFraction = minT;
    results.m_shapeKeys[results.m_shapeKeyIndex] = -1;
    hkTimerCommandMark("Et");
    return true;
}
}   // namespace f3m_009e8450

// @f3 0x009f90f0 (community match, verified in this file)
namespace f3m_009f90f0 {
// 1-d angular Jacobian builder (Havok constraint solver setup): two angular rows rotated into each body's core
// frame, the inverse virtual mass in ang0.w, the right-hand side row, schema type 12. Built under
// /MT /O2 /GS /EHsc /Gy (the pack lists /Od, which cannot give this aligned frame). Stand-in types.
namespace f3m_009f90f0 {

struct Mat;
struct __declspec(align(16)) S009f90f0_Vec4 {
    __forceinline void rotate(const Mat&, const S009f90f0_Vec4&);
    // negate and setMul4L are written as lane loops: with explicit lanes the x87 operand order of the B rotation
    // and of the inertia sum changes (a guess at the source; setMul4 with explicit lanes is used for the second row).
    __forceinline void negate(const S009f90f0_Vec4& a) { for(int i=0;i<4;++i) v[i]=-a.v[i]; }
    inline float& operator()(int i) { return v[i]; }
    inline const float& operator()(int i) const { return v[i]; }
    float v[4];
    void setMul4L(const S009f90f0_Vec4& a, const S009f90f0_Vec4& b) { for(int i=0;i<4;++i) v[i]=a.v[i]*b.v[i]; }
    void setMul4(const S009f90f0_Vec4& a, const S009f90f0_Vec4& b) { v[0] = a.v[0] * b.v[0]; v[1] = a.v[1] * b.v[1]; v[2] = a.v[2] * b.v[2]; v[3] = a.v[3] * b.v[3]; }
    void mul4(const S009f90f0_Vec4& a) { v[0] *= a.v[0]; v[1] *= a.v[1]; v[2] *= a.v[2]; v[3] *= a.v[3]; }
    void add4(const S009f90f0_Vec4& a) { v[0] = v[0] + a.v[0]; v[1] = v[1] + a.v[1]; v[2] = v[2] + a.v[2]; v[3] = v[3] + a.v[3]; }
};

struct Mat {
    S009f90f0_Vec4 columns[3];
    inline const float& operator()(int row,int col) const { return columns[col].v[row]; }
};

struct S009f90f0_Body {
    unsigned char unk00;
    unsigned char fixed;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int unk08;
    int unk0c;
    S009f90f0_Vec4 unk10;
    S009f90f0_Vec4 unk20;
    S009f90f0_Vec4 invInertia;
    S009f90f0_Vec4 unk40;
    Mat rotation;
};

struct S009f90f0_Bodies {
    int unk00;
    int unk04;
    float f08;
    int unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    S009f90f0_Body* bodyA;
    S009f90f0_Body* bodyB;
};

struct S009f90f0_In {
    S009f90f0_Vec4 axis;
    S009f90f0_Vec4 v1;
};

struct S009f90f0_Out {
    S009f90f0_Vec4 ang0;
    S009f90f0_Vec4 ang1;
    S009f90f0_Vec4 v2;
};

}
using namespace f3m_009f90f0;

__forceinline void S009f90f0_Vec4::rotate(const Mat& b, const S009f90f0_Vec4& v)
{
    float x=v.v[0], y=v.v[1], z=v.v[2];
    this->v[0]=b(0,0)*x+b(0,1)*y+b(0,2)*z;
    this->v[1]=b(1,0)*x+b(1,1)*y+b(1,2)*z;
    this->v[2]=b(2,0)*x+b(2,1)*y+b(2,2)*z;
    this->v[3]=0;
}

__forceinline float Build(const S009f90f0_In* in, const S009f90f0_Bodies* b, S009f90f0_Out* s)
{
    const S009f90f0_Body* A = b->bodyA;
    const S009f90f0_Body* B = b->bodyB;
    if (A->fixed) {
        s->ang0.v[0] = in->axis.v[0];
        s->ang0.v[1] = in->axis.v[1];
        s->ang0.v[2] = in->axis.v[2];
        s->ang0.v[3] = in->axis.v[3];
    } else {
        s->ang0.rotate(A->rotation,in->axis);
    }
    if (B->fixed) {
        s->ang1.v[0] = -in->axis.v[0];
        s->ang1.v[1] = -in->axis.v[1];
        s->ang1.v[2] = -in->axis.v[2];
        s->ang1.v[3] = -in->axis.v[3];
    } else {
        S009f90f0_Vec4 n;
        n.negate(in->axis);
        s->ang1.rotate(B->rotation,n);
        (void)n.v[0];   // a guess at the source: an unused read; sets the x87 operand order of the B rotation's x lane
    }
    S009f90f0_Vec4 t0;
    t0.setMul4L(s->ang0, s->ang0);
    S009f90f0_Vec4 t1;
    t1.setMul4(s->ang1, s->ang1);
    t0.mul4(A->invInertia);
    t1.mul4(B->invInertia);
    t0.add4(t1);
    (void)t1.v[2];  // a guess at the source: an unused read; sets the operand order of the z lane of t0 += t1
    float sum = (t0.v[1] + t0.v[0]) + t0.v[2];
    float denom = (float)(sum + 1.1920928955078125e-07);
    return denom;
}
// pdb: hk1dAngularLimitBuildJacobian | hkpBuildJacobianFromAtoms.obj | fnv360_0721_beta, objrun, medium
// pdb params: info, in, out
void FUN_009f90f0(const S009f90f0_In* in, const S009f90f0_Bodies* b, S009f90f0_Out** pp)
{
    float wgt = in->v1.v[3];
    S009f90f0_Out* s = *pp;
    float denom = Build(in,b,s);
    s->ang0.v[3] = wgt / denom;
    float k = -b->f08;
    float ax = in->v1.v[0];
    float ay = in->v1.v[1];
    float az = in->v1.v[2];
    s->ang1.v[3] = az * k;
    s = *pp;
    *pp = s + 1;
    s->v2.v[0] = ax * k * wgt;
    s->v2.v[1] = k * ay * wgt;
    s->v2.v[2] = wgt;
    s->ang0.v[0] = (float)(1.1920928955078125e-07 + s->ang0.v[0]);
    *(unsigned char*)s = 12;
}

}   // namespace f3m_009f90f0

// @f3 0x009e6e80 (community match, verified in this file)
namespace f3m_009e6e80 {
// Havok 5.5 hkDisplayCylinder::buildGeometry (FPU vector build), stand-in types: +0x08 m_geometry, +0x60 m_top,
// +0x70 m_bottom, +0x80 m_radius, +0x84 m_numSides, +0x88 m_numHeightSegments. Built under /MT /O2 /GS /EHsc /Gy
// (the pack lists /Od, which cannot give the aligned frame).


inline float root9(float f){return (float)sqrt(f);}
inline float reciprocalRoot9(float f){return 1.0f/root9(f);}
struct Q9;
struct __declspec(align(16)) V9 {
 __forceinline void accumulate(float s,const V9& a){x+=s*a.x;y+=s*a.y;z+=s*a.z;w+=s*a.w;}
 __forceinline void rotate(const Q9&,const V9&);
 float x,y,z,w;
 void sub(const V9& a,const V9& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
 __forceinline void mul(float f){float s=f;x*=s;y*=s;z*=s;w*=s;}
 __forceinline void setMul(const V9& a,float f){float s=f;x=s*a.x;y=s*a.y;z=s*a.z;w=s*a.w;}
 void store(V9& a)const{a.x=x;a.y=y;a.z=z;a.w=w;}
 void add(const V9& a){x+=a.x;y+=a.y;z+=a.z;w+=a.w;}
 void setAdd(const V9& a,const V9& b){x=b.x+a.x;y=a.y+b.y;z=b.z+a.z;w=a.w+b.w;}
 void cross(const V9& a,const V9& b){float u=a.y*b.z-a.z*b.y;float v=a.z*b.x-a.x*b.z;float t=a.x*b.y-a.y*b.x;w=0.0f;x=u;y=v;z=t;}
 __forceinline void hset(float a,float b,float c,float d){x=a;y=b;z=c;w=d;}
 __forceinline float dot(const V9& b)const{return x*b.x+(y*b.y)+z*b.z;}
 __forceinline float inverseLength()const{float v=x*x+y*y+z*z;return v?reciprocalRoot9(v):0;}
 __forceinline void normalize(){mul(inverseLength());}
 __forceinline float& operator()(int i){return (&x)[i];}
 __forceinline const float& operator()(int i)const{return (&x)[i];}
};
struct __declspec(align(16)) Q9 {
 float x,y,z,w;
 __forceinline const V9& getImag()const{return *(const V9*)this;}
 void FUN_009240d0(const V9&,float);
 void FUN_008d3290(const Q9&,const Q9&);
};
__forceinline void V9::rotate(const Q9& q,const V9& v){
 float scalar=q.w;
 float factor=(float)(scalar*scalar-0.5);
 V9 t;t.setMul(v,factor);
 // a guess at the source: the vector part copied through a reference, and its z lane read through the quaternion,
 // set the x87 operand order of the dot product and of the first addMul4 (+0x4f8..+0x538)
 const V9& qi=q.getImag();V9 imag=qi;
 const float qz=q.z;float product=imag.x*v.x+(imag.y*v.y)+(qz*v.z);
 t.accumulate(product,imag);
 V9 perpendicular;perpendicular.cross(imag,v);
 t.accumulate(scalar,perpendicular);
 setAdd(t,t);
}
struct Tri9{int a,b,c;void store(Tri9& x)const{x.a=a;x.b=b;x.c=c;}};
void __cdecl FUN_00901e90(void*,int,int);
template<class T>struct Array9{
 T* data;int size,capacity;
 Array9():data(0),size(0),capacity(0x80000000){}
 T& expand(){int n=size;int needed=n+1;int cap=capacity&0x3fffffff;if(cap<needed){int grow=cap*2;if(needed>=grow)grow=needed;FUN_00901e90(this,grow,sizeof(T));}size=n+1;return data[n];}
};
struct Mesh9{Array9<V9> vertices;Array9<Tri9> triangles;};
extern const double DAT_00dc0760;
extern unsigned long DAT_010f3170;
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();
struct Thread9{
unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
unsigned int unk1c;
unsigned int unk20;
unsigned int unk24;
unsigned int unk28;
unsigned int unk2c;
unsigned int unk30;
unsigned int unk34;
unsigned int unk38;
unsigned int unk3c;
unsigned int unk40;
unsigned int unk44;
unsigned int unk48;
unsigned int unk4c;
void* freeList;int freeCount;
 void* FUN_008f6800(int,int);
 __forceinline void* take(){void* p=freeList;if(p){--freeCount;freeList=*(void**)p;return p;}return FUN_008f6800(3,0x27);}
};
extern V9 DAT_00e375b0,DAT_00e375c0,DAT_00e375d0;
struct Owner9{
 int unk00,unk04;Mesh9* mesh;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
unsigned int unk1c;
unsigned int unk20;
unsigned int unk24;
unsigned int unk28;
unsigned int unk2c;
unsigned int unk30;
unsigned int unk34;
unsigned int unk38;
unsigned int unk3c;
unsigned int unk40;
unsigned int unk44;
unsigned int unk48;
unsigned int unk4c;
unsigned int unk50;
unsigned int unk54;
unsigned int unk58;
unsigned int unk5c;
V9 end,start;float radius;int rings,steps;
 void FUN_009e6e80();
};
// pdb: hkDisplayCylinder::buildGeometry | hkDisplayCylinder.obj | fnv360_0822_retail, vtable, medium
void Owner9::FUN_009e6e80(){
 const int& axial=steps;const int& radialCount=rings;
 const V9& bottom=start;   // a guess at the source: m_bottom through one reference sets the lane order of both adds
 Q9 stepRotation;
 V9 direction;
 Q9 rotation;
 {
 V9 delta;delta.sub(end,start);float inv=1.0f/(float)axial;delta.mul(inv);
 direction=delta;direction.normalize();
 V9 radial;
 {
 V9 basis;
 if(fabs(direction.x)>0.5f)basis=DAT_00e375c0;
 else if(fabs(direction(1))>0.5f)basis=DAT_00e375d0;
 else if(fabs(direction(2))>0.5f)basis=DAT_00e375b0;
 radial.cross(direction,basis);
 radial.normalize();
 radial.mul(radius);
 }
 stepRotation.FUN_009240d0(direction,(float)(DAT_00dc0760/(float)radialCount));
 rotation.FUN_009240d0(direction,0.0f);
 Thread9* thread=(Thread9*)FUN_00d9b080(DAT_010f3170);
 void* allocation=thread->take();
 Mesh9* result=0;if(allocation)result=new(allocation)Mesh9;
 mesh=result;
 start.store(mesh->vertices.expand());
  // a guess at the source: the parenthesised count sets the lane order of the top and ring point adds
 {V9 endpoint;endpoint.setMul(delta,((float)axial));{V9& e=endpoint;e.add(bottom);}endpoint.store(mesh->vertices.expand());}
 for(int i=0;i<radialCount;++i){
  V9 offset;offset.rotate(rotation,radial);
  V9 point;point.setAdd(bottom,offset);
  for(int j=0;j<axial;++j){point.store(mesh->vertices.expand());point.add(delta);}
  point.store(mesh->vertices.expand());
  Q9 previous=rotation;rotation.FUN_008d3290(previous,stepRotation);
 }
 }
 int stride=axial+1;
 int limit=(axial+1)*radialCount+2;
 struct __declspec(align(16)) Quad9 {int a,b,c,d;};
 Quad9 quad={2,stride+2,3,stride+3};
 for(int i=0;i<radialCount;++i){
  for(int j=0;j<axial;++j){Tri9 first={quad.a,quad.b,quad.c};first.store(mesh->triangles.expand());Tri9 second={quad.c,quad.b,quad.d};second.store(mesh->triangles.expand());++quad.a;++quad.b;++quad.c;++quad.d;}
  ++quad.a;++quad.b;++quad.c;++quad.d;
  if(quad.d>=limit){quad.b+=2-limit;quad.d+=2-limit;}
 }
 for(int side=0;side<2;++side){
  int current=(side?axial:0)+2;
  for(int i=0;i<radialCount;++i){int next=current+stride;if(next>=limit)next+=2-limit;
   if(side){Tri9 tri={side,current,next};tri.store(mesh->triangles.expand());}
   else {Tri9 tri={0,next,current};tri.store(mesh->triangles.expand());}
   current=next;
  }
 }
}

}   // namespace f3m_009e6e80

// @f3 0x009fc870 (community match, verified in this file)
// 0x009fc870: buildJacobianFromMovingSurfaceModifier(const hkpMovingSurfaceModifierConstraintAtom& atom,
// hkpConstraintQueryIn& in, const hkTransform& baseA, const hkTransform& baseB, hkpConstraintQueryOut& out) of Havok
// 5.5.0 (hkpConstraintSolver, hkpBuildJacobianFromAtoms.cpp; compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-), a
// file-local (static) function.
// The moving-surface modifier: rewrites the header schema of its child contact atom, copies the moving body's velocity
// accumulator and adds the surface velocity (the atom's velocity without its part along the contact normal, negated
// for body B) to it, writes an add-velocity schema before and after the child contact's jacobians.
// The function takes 'atom' in eax and 'in' and 'out' on the stack (the two unused transforms are not passed):
// Visual C++ 2005 gives a static function whose address is never taken a register convention of its own when it sees
// every call to it in the same file, without whole-program optimization.
// THE CALLER IN THIS FILE IS A STAND-IN, not a function of the game: it exists only so that the compiler emits the
// static target (a static function with no call in its file is not emitted at all). The real caller is the atom loop
// hkSolverBuildJacobianFromAtomsNotContact (0x009fccc0), where the SDK's builds expand this function inline; in the
// SDK's release object and in the game nothing calls this out-of-line copy. The target's bytes were measured to be
// the same with every caller form tried (called once or twice, expanded in a small atom loop, inline or not).
// This file is built from the Havok 5.5.0 SDK's own headers: the preprocessed source cut down to the declarations the
// code needs (those declarations are the SDK's text with its names; the SDK's memory-allocator boilerplate is left
// out). The solver library's schema classes that no SDK header ships (hkpJacobianSchema, hkpJacobianHeaderSchema) are
// rebuilt from the library's debug records. The body follows the SDK's unoptimized expansion statement by statement.
// hkAddVelocityBuildJacobian is DEFINED in this file with a stand-in body (see the note at it): with only a
// declaration the compiler must assume the vector passed to it escapes, and it then loads the fourth lane of the
// contact normal two instructions early. Only FUN_009fc870 carries the packet's name.
namespace f3m_009fc870 {

typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}
template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
class hkHalf
{
    public:
	    inline hkHalf(){   }
	    inline hkHalf(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
	    }
	    inline hkHalf& operator=(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
		    return *this;
	    }
	    inline operator float() const
	    {
		    union
		    {
			    int i;
			    float f;
		    } u;
		    u.i = (m_value <<16);
		    return u.f;
	    }
    private:
	    hkInt16 m_value;
};
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::subMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x -= r * a.x;
	y -= r * a.y;
	z -= r * a.z;
	w -= r * a.w;
}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w =  v.w;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkVector4& getPosition() const;
		inline hkVector4& getPosition();
		inline void setPosition(const hkVector4& position);
		inline const hkVector4& getNormal() const;
		inline const hkVector4& getSeparatingNormal() const;
		inline hkSimdReal getDistanceSimdReal() const;
		inline void setDistance( hkReal d );
		inline void set( const hkVector4& position, const hkVector4& normal, float dist );
		inline void setFlipped( const hkContactPoint& point );
		inline void flip();
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline const hkVector4& hkContactPoint::getNormal() const
{
	return m_separatingNormal;
}
class hkpSolverResults
{
	public:
		inline hkReal getImpulseApplied() const;
		inline hkpSolverResults();
		inline void init();
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};
class hkpConstraintQueryIn;
class hkpConstraintQueryOut;
struct hkpSimpleContactConstraintAtom;
class hkpSimpleContactConstraintDataInfo
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum {	HK_FLAG_OK = 0x00, HK_FLAG_POINT_REMOVED = 0x01, HK_FLAG_AREA_CHANGED = 0x04 };
		void init()
		{
			m_flags = HK_FLAG_OK;
			m_index = 3;
			for(int i = 0; i < 7; ++i)
			{
				m_data[i] = 0;
			}
		}
		hkpSimpleContactConstraintDataInfo()
		{
			init();
		}
		__declspec(align(16)) hkUint16 m_flags;
		hkUint16 m_index;
		hkUint32 m_data[7];
		hkpSimpleContactConstraintDataInfo(hkFinishLoadedObjectFlag f) {}
};
extern "C"
{
void __cdecl hkSimpleContactConstraintDataBuildJacobian( hkpSimpleContactConstraintAtom* atom, const hkpConstraintQueryIn& in, hkBool writeHeaderSchema, hkpConstraintQueryOut& out );
}
struct hkpSolverInfo
{
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	inline void setTauAndDamping( float tau, float damping )
	{
		m_tau = tau;
		m_frictionTau = 0.5f * tau;
		m_damping = damping;
		m_dampDivTau = damping / tau;
		m_dampDivFrictionTau = damping / m_frictionTau;
		m_tauDivDamp = tau/damping;
		m_frictionTauDivDamp = m_frictionTau/damping;
		m_integrateVelocityFactor.setAll3( m_tauDivDamp );
		m_invIntegrateVelocityFactor.setAll3( m_dampDivTau );
	}
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	inline void incrementDeactivationFlags()
	{
		m_deactivationIntegrateCounter++;
		if (((m_deactivationIntegrateCounter+4) & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x01;
		}
		if ((m_deactivationIntegrateCounter & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x02;
		}
		if ((m_deactivationIntegrateCounter & 15) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[1] = 1 - m_deactivationNumInactiveFramesSelectFlag[1];
			m_deactivationIntegrateCounter = 0;
		}
	}
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};
struct hkpConstraintInfo
{
	int m_maxSizeOfSchema;
	int m_sizeOfSchemas;
	int m_numSolverResults;
	int m_numSolverElemTemps;
	inline void clear( ) { m_maxSizeOfSchema = 0; m_sizeOfSchemas = 0; m_numSolverResults = 0; m_numSolverElemTemps = 0; }
	inline void addHeader( ) { m_sizeOfSchemas += 16; }
	inline void add( int schemaSize, int numSolverResults, int numSolverTempElems ) { m_sizeOfSchemas += schemaSize; m_numSolverResults += numSolverResults; m_numSolverElemTemps += numSolverTempElems; }
	inline void add( const hkpConstraintInfo& other);
	inline void sub( const hkpConstraintInfo& other);
	inline void merge( const hkpConstraintInfo& other);
};
class hkpContactPointPropertiesStream;
struct hkpConstraintAtom
{
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		enum AtomType
		{
			TYPE_INVALID = 0,
			TYPE_BRIDGE,
			TYPE_SET_LOCAL_TRANSFORMS,
			TYPE_SET_LOCAL_TRANSLATIONS,
			TYPE_SET_LOCAL_ROTATIONS,
			TYPE_BALL_SOCKET,
			TYPE_STIFF_SPRING,
			TYPE_LIN,
			TYPE_LIN_SOFT,
			TYPE_LIN_LIMIT,
			TYPE_LIN_FRICTION,
			TYPE_LIN_MOTOR,
			TYPE_2D_ANG,
			TYPE_ANG,
			TYPE_ANG_LIMIT,
			TYPE_TWIST_LIMIT,
			TYPE_CONE_LIMIT,
			TYPE_ANG_FRICTION,
			TYPE_ANG_MOTOR,
			TYPE_RAGDOLL_MOTOR,
			TYPE_PULLEY,
			TYPE_OVERWRITE_PIVOT,
			TYPE_CONTACT,
			TYPE_MODIFIER_SOFT_CONTACT,
			TYPE_MODIFIER_MASS_CHANGER,
			TYPE_MODIFIER_VISCOUS_SURFACE,
			TYPE_MODIFIER_MOVING_SURFACE,
			TYPE_MODIFIER_IGNORE_CONSTRAINT,
			TYPE_MAX
		};
		enum CallbackRequest
		{
			CALLBACK_REQUEST_NONE = 0,
			CALLBACK_REQUEST_NEW_CONTACT_POINT = 1,
			CALLBACK_REQUEST_SETUP_PPU_ONLY = 2,
			CALLBACK_REQUEST_SETUP_CALLBACK = 4
		};
	public:
		__forceinline enum AtomType getType() const { return m_type; }
		__forceinline int isModifierType() const { return m_type >= TYPE_MODIFIER_SOFT_CONTACT; }
	protected:
		hkpConstraintAtom(enum AtomType type) : m_type(type) {}
	private:
		hkpConstraintAtom();
	public:
		hkEnum<AtomType,hkUint16> m_type;
		hkpConstraintAtom(hkFinishLoadedObjectFlag f) {}
};
struct hkpSimpleContactConstraintAtom : public hkpConstraintAtom
{
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		hkpSimpleContactConstraintAtom() : hkpConstraintAtom(TYPE_CONTACT) {}
		__forceinline hkContactPoint* getContactPoints() const { return const_cast<hkContactPoint*>( reinterpret_cast<const hkContactPoint*>( this+1 ) ); }
		__forceinline int getContactPointPropertiesStriding() const;
		__forceinline hkpContactPointPropertiesStream* getContactPointPropertiesStream() const { return const_cast<hkpContactPointPropertiesStream*>( reinterpret_cast<const hkpContactPointPropertiesStream*>( hkAddByteOffsetConst( getContactPoints(), sizeof(hkContactPoint) * m_numReservedContactPoints ) ) ); }
		__forceinline hkpContactPointPropertiesStream* getContactPointPropertiesStream(int i) const;
	public:
		__forceinline hkpConstraintAtom* next() const { ; return 0; }
		__forceinline int numSolverResults() const    { return m_numContactPoints+3; }
		__forceinline void addToConstraintInfo(hkpConstraintInfo& infoOut) const
		{
			int size = m_numContactPoints;
			infoOut.m_sizeOfSchemas    += 16
										+ (size >> 1) * 112
				                        + (size & 1) * 48
										+ 112;
			infoOut.m_maxSizeOfSchema = infoOut.m_sizeOfSchemas + (144 - 112);
			infoOut.m_numSolverResults   += size + 2;
			infoOut.m_numSolverElemTemps += size + (2 + 1);
			if ( size >= 2 )
			{
				infoOut.m_sizeOfSchemas   += 144 - 112;
				infoOut.m_numSolverResults   += 1;
				infoOut.m_numSolverElemTemps += 1 + 0;
			}
		}
	public:
		hkUint16 m_sizeOfAllAtoms;
		hkUint16 m_numContactPoints;
		hkUint16 m_numReservedContactPoints;
		hkUint8 m_numUserDatasForBodyA;
		hkUint8 m_numUserDatasForBodyB;
		hkUint8 m_contactPointPropertiesStriding;
		hkUint16 m_maxNumContactPoints;
		__declspec(align(16)) class hkpSimpleContactConstraintDataInfo m_info;
	public:
		hkpSimpleContactConstraintAtom(hkFinishLoadedObjectFlag f);
};
class hkContactPointMaterial
{
	public:
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		inline hkBool32 isPotential();
		inline void setMaxImpulsePerStep( hkUFloat8 impulse );
		inline hkReal getMaxImpulsePerStep();
	protected:
		hkUlong m_userData;
		hkUFloat8 m_friction;
		hkUint8 m_restitution;
	public:
		hkUFloat8 m_maxImpulse;
	public:
		void reset()
		{
			m_friction.m_value = 0;
			m_maxImpulse.m_value = 0;
			m_restitution = 0;
			m_flags = CONTACT_IS_NEW_AND_POTENTIAL;
		}
		enum  FlagEnum
		{
			CONTACT_IS_NEW_AND_POTENTIAL  = 1,
			CONTACT_USES_SOLVER_PATH2 = 2,
			CONTACT_BREAKOFF_OBJECT_ID = 4,
		};
		hkUint8 m_flags;
		friend class hkpSaveContactPointsEndianUtil;
};
class hkpContactPointProperties : public hkpSolverResults, public hkContactPointMaterial
{
	public:
		inline hkBool wasUsed()
		{
			return !isPotential() && ( m_impulseApplied > 0.f );
		}
	public:
		hkReal m_internalDataA;
		typedef hkUint32 UserData;
		static inline int getNumExtendedUserDatas(const hkpSimpleContactConstraintAtom* atom, int bodyIdx);
		inline hkpContactPointProperties::UserData& getExtendedUserData(const hkpSimpleContactConstraintAtom* atom, int bodyIdx, int i);
};
class hkpContactPointPropertiesStream
{
public:
	__forceinline hkpContactPointProperties* asProperties() { return reinterpret_cast<hkpContactPointProperties*>(this); }
	__forceinline const hkpContactPointProperties* asProperties() const { return reinterpret_cast<const hkpContactPointProperties*>(this); }
};
__forceinline int hkpSimpleContactConstraintAtom::getContactPointPropertiesStriding() const { return m_contactPointPropertiesStriding; }
struct hkpModifierConstraintAtom : public hkpConstraintAtom
{
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		int addModifierDataToConstraintInfo( hkpConstraintInfo& cinfo ) const;
		static int __cdecl addAllModifierDataToConstraintInfo( hkpModifierConstraintAtom* firstModifier, hkpConstraintInfo& cinfo );
	protected:
		hkpModifierConstraintAtom(enum AtomType type, int size) : hkpConstraintAtom(type), m_modifierAtomSize( hkUint16(size)) {}
	public:
		__declspec(align(16)) hkUint16 m_modifierAtomSize;
		hkUint16                      m_childSize;
		hkpConstraintAtom* m_child;
		hkUint32 m_pad[2];
		hkpModifierConstraintAtom(hkFinishLoadedObjectFlag f) : hkpConstraintAtom(f) {}
};
struct hkpMovingSurfaceModifierConstraintAtom : public hkpModifierConstraintAtom
{
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		hkpMovingSurfaceModifierConstraintAtom() : hkpModifierConstraintAtom(TYPE_MODIFIER_MOVING_SURFACE, sizeof(hkpMovingSurfaceModifierConstraintAtom)) { }
		__forceinline int numSolverResults() const { return 0; }
		int getConstraintInfo( hkpConstraintInfo& info ) const
		{
			info.m_sizeOfSchemas   += 2 * 32 + 16;
			return hkpConstraintAtom::CALLBACK_REQUEST_NONE;
		}
		void collisionResponseBeginCallback( const hkContactPoint& cp, struct hkpSimpleConstraintInfoInitInput& inA, struct hkpBodyVelocity& velA, hkpSimpleConstraintInfoInitInput& inB, hkpBodyVelocity& velB);
		void collisionResponseEndCallback(   const hkContactPoint& cp, hkReal impulseApplied, struct hkpSimpleConstraintInfoInitInput& inA, struct hkpBodyVelocity& velA, hkpSimpleConstraintInfoInitInput& inB, hkpBodyVelocity& velB);
		hkVector4& getVelocity() { return m_velocity; }
		const hkVector4& getVelocity() const { return m_velocity; }
	public:
 		hkVector4 m_velocity;
		hkpMovingSurfaceModifierConstraintAtom(hkFinishLoadedObjectFlag f) : hkpModifierConstraintAtom(f) {}
};
class hkStepInfo
{
	public:
		hkStepInfo(){}
		void set( hkTime startTime, hkTime endTime)
		{
			m_startTime = startTime;
			m_endTime   = endTime;
			m_deltaTime = endTime - startTime;
			m_invDeltaTime = m_deltaTime == 0.0f ? 0.0f : 1.0f / m_deltaTime;
		}
		hkStepInfo( hkTime startTime, hkTime endTime)
		{
			set( startTime, endTime );
		}
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
class hkpVelocityAccumulator;
class hkpConstraintQueryStepInfo
{
	public:
		__declspec(align(16)) hkPadSpu<float> m_substepDeltaTime;
		hkPadSpu<float>		m_microStepDeltaTime;
		hkPadSpu<float>		m_substepInvDeltaTime;
		hkPadSpu<float>		m_frameDeltaTime;
		hkPadSpu<float>		m_frameInvDeltaTime;
		hkPadSpu<float>		m_invNumSteps;
		hkPadSpu<float>		m_invNumStepsTimesMicroSteps;
		hkPadSpu<float>		m_rhsFactor;
		hkPadSpu<float>		m_virtMassFactor;
		hkPadSpu<float> m_frictionRhsFactor;
};
class hkpConstraintQueryIn: public hkpConstraintQueryStepInfo
{
	public:
		hkpConstraintQueryIn() { }
		__declspec(align(16)) hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
		hkPadSpu<const hkpVelocityAccumulator*>	m_bodyB;
		hkPadSpu<const hkTransform*>	m_transformA;
		hkPadSpu<const hkTransform*>	m_transformB;
		hkPadSpu<hkReal> m_tau;
		hkPadSpu<hkReal> m_damping;
		hkPadSpu<class hkpConstraintInstance*>	m_constraintInstance;
		hkPadSpu<void*>	m_constraintRuntime;
		hkPadSpu<hkUint32> m_accumulatorAIndex;
		hkPadSpu<hkUint32> m_accumulatorBIndex;
		hkPadSpu<void*> m_constraintRuntimeInMainMemory;
		inline void set( const hkpSolverInfo& si, const hkStepInfo& stepInfo )
		{
			m_substepDeltaTime    = si.m_deltaTime;
			m_microStepDeltaTime  = si.m_deltaTime * si.m_invNumMicroSteps;
			m_substepInvDeltaTime = si.m_invDeltaTime;
			m_invNumSteps		  = si.m_invNumSteps;
			m_invNumStepsTimesMicroSteps	  = si.m_invNumSteps * si.m_invNumMicroSteps;
			m_tau			      = si.m_tau;
			m_damping		      = si.m_damping;
			m_rhsFactor			  = si.m_tauDivDamp * si.m_invDeltaTime;
			m_virtMassFactor      = si.m_damping;
			m_frictionRhsFactor   = si.m_frictionTauDivDamp * si.m_invDeltaTime;
			m_frameDeltaTime      = stepInfo.m_deltaTime;
			m_frameInvDeltaTime   = stepInfo.m_invDeltaTime;
		}
};
class hkpJacobianSchema;
class  hkpConstraintQueryOut
{
	public:
		hkPadSpu<hkpJacobianSchema*> m_jacobianSchemas;
};
class hkpVelocityAccumulator
{
	public:
	    enum hkpAccumulatorType
	    {
		    HK_RIGID_BODY,
		HK_KEYFRAMED_RIGID_BODY,
		HK_NO_GRAVITY_RIGID_BODY,
		HK_END
	};
	hkEnum<hkpAccumulatorType,hkUint8> m_type;
	hkBool m_matrixIsIdentity;
	hkUint32 m_deactivationClass;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel;
	hkVector4 m_invMasses;
	hkVector4& getCenterOfMassInWorld() { return m_scratch0; }
	const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
	hkRotation& getCoreFromWorldMatrix() { return reinterpret_cast<hkRotation&>(m_scratch1); }
	const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
	hkVector4& getSumLinearVel() { return m_scratch0; }
	hkVector4& getSumAngularVel() { return m_scratch1; }
	const hkVector4& getSumLinearVel() const { return m_scratch0; }
	const hkVector4& getSumAngularVel() const { return m_scratch1; }
public:
	hkVector4 m_scratch0;
	hkVector4 m_scratch1;
	hkVector4 m_scratch2;
	hkVector4 m_scratch3;
public:
	__forceinline void setFixed()
	{
		m_type = hkpVelocityAccumulator::HK_KEYFRAMED_RIGID_BODY;
		m_matrixIsIdentity = true;
		this->m_invMasses.setZero4();
		this->m_linearVel.setZero4();
		this->m_angularVel.setZero4();
		this->getCenterOfMassInWorld().setZero4();
		this->getCoreFromWorldMatrix().setZero();
	}
};
class hkpJacobianSchema
{
	public:
		enum SchemaType
		{
			SCHEMA_TYPE_END = 0,
			SCHEMA_TYPE_HEADER,
			SCHEMA_TYPE_GOTO,
			SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER,
			SCHEMA_TYPE_SIMPLE_BEGIN,
			SCHEMA_TYPE_1D_BILATERAL,
			SCHEMA_TYPE_1D_BILATERAL_USER_TAU,
			SCHEMA_TYPE_1D_LINEAR_LIMITS,
			SCHEMA_TYPE_1D_FRICTION,
			SCHEMA_TYPE_1D_LINEAR_MOTOR,
			SCHEMA_TYPE_1D_PULLEY,
			SCHEMA_TYPE_1D_ANGULAR,
			SCHEMA_TYPE_1D_ANGULAR_LIMITS,
			SCHEMA_TYPE_1D_ANGULAR_FRICTION,
			SCHEMA_TYPE_1D_ANGULAR_MOTOR,
			SCHEMA_TYPE_SINGLE_CONTACT,
			SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_SINGLE_LIMIT_CONTACT,
			SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_PAIR_CONTACT,
			SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_2D_FRICTION,
			SCHEMA_TYPE_3D_FRICTION,
			SCHEMA_TYPE_SET_MASS,
			SCHEMA_TYPE_ADD_VELOCITY,
			SCHEMA_TYPE_SIMPLE_END,
			SCHEMA_TYPE_STIFF_SPRING_CHAIN,
			SCHEMA_TYPE_BALL_SOCKET_CHAIN,
			SCHEMA_TYPE_POWERED_CHAIN,
			SCHEMA_TYPE_MAX
		};
		static __forceinline void __cdecl setType( hkpJacobianSchema* schema, hkEnum<SchemaType, hkInt8> type )
		{
			*reinterpret_cast<hkReal*>( schema ) += 1.192092896e-07f;
			*reinterpret_cast<hkEnum<SchemaType, hkInt8>*>( schema ) = type;
		}
};
class hkpJacobianHeaderSchema
{
	public:
		__forceinline void initHeader( hkpConstraintInstance* instance, const int bodyAIndex, const int bodyBIndex, hkpSolverResults* sr, const int solverResultStriding )
		{
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>( this ), hkpJacobianSchema::SCHEMA_TYPE_HEADER );
			m_bodyAIndex = hkUint16( bodyAIndex );
			m_bodyBIndex = hkUint16( bodyBIndex );
			m_solverResultInMainMemory = sr;
			m_constraintInstance = instance;
			;
			;
			m_solverResultStriding = hkUint8( solverResultStriding );
		}
	private:
		hkUint8 m_padding0;
	public:
		hkUint8 m_solverResultStriding;
	private:
		hkUint16 m_padding1;
	public:
		hkUint16 m_bodyAIndex;
		hkUint16 m_bodyBIndex;
		hkpSolverResults* m_solverResultInMainMemory;
		hkpConstraintInstance* m_constraintInstance;
};
// A STAND-IN body, not the game's function at 0x00a4e3c0: the original file defines hkAddVelocityBuildJacobian
// itself, so the compiler can see that the vector passed to it does not escape. That changes how it orders
// the copy of the contact normal in FUN_009fc870 below. The call stays a real call.
__declspec(noinline) void __cdecl hkAddVelocityBuildJacobian( const hkVector4& velocity, int bodyIndex, hkpConstraintQueryOut& out )
{
	hkVector4* schema = reinterpret_cast<hkVector4*>( out.m_jacobianSchemas.val() );
	*schema = velocity;
	out.m_jacobianSchemas = hkAddByteOffset( out.m_jacobianSchemas.val(), hkUlong( 32 + bodyIndex ) );
}
static __forceinline void __cdecl hkInitHeader( const hkpConstraintQueryIn& in, hkpSolverResults* results, int resultStriding, hkpConstraintQueryOut& out )
{
	hkpJacobianHeaderSchema* header = reinterpret_cast<hkpJacobianHeaderSchema*>( out.m_jacobianSchemas.val() );
	header->initHeader( in.m_constraintInstance, in.m_accumulatorAIndex, in.m_accumulatorBIndex, results, resultStriding );
	out.m_jacobianSchemas = reinterpret_cast<hkpJacobianSchema*>( header + 1 );
}
static __forceinline void __cdecl FUN_009fc870( const hkpMovingSurfaceModifierConstraintAtom& atom, hkpConstraintQueryIn& in, const hkTransform& baseA, const hkTransform& baseB, hkpConstraintQueryOut& out )
{
	hkVector4 velocity = atom.getVelocity();
	hkpConstraintQueryIn modifiedIn = in;
	const hkpConstraintAtom* child = atom.m_child;
	hkpSimpleContactConstraintAtom* contactAtom = const_cast<hkpSimpleContactConstraintAtom*>( static_cast<const hkpSimpleContactConstraintAtom*>( child ) );
	out.m_jacobianSchemas = hkAddByteOffset( out.m_jacobianSchemas.val(), hkUlong( -16 ) );
	hkpContactPointPropertiesStream* cpProps = contactAtom->getContactPointPropertiesStream();
	const int striding = contactAtom->getContactPointPropertiesStriding();
	hkpContactPointPropertiesStream* cpPropsInMainMemory = cpProps;
	hkInitHeader( in, cpPropsInMainMemory->asProperties(), striding, out );
	hkBool accumIndex = in.m_accumulatorAIndex == 0;
	hkpVelocityAccumulator accum;
	if ( !accumIndex )
	{
		accum = *in.m_bodyA;
		in.m_bodyA = &accum;
	}
	else
	{
		accum = *in.m_bodyB;
		in.m_bodyB = &accum;
		velocity.setNeg3( velocity );
	}
	hkVector4 normal = contactAtom->getContactPoints()[0].getNormal();
	const hkSimdReal dot = normal.dot3( velocity );
	hkVector4 deltaVel;
	deltaVel = velocity;
	deltaVel.subMul4( dot, normal );
	deltaVel.setNeg4( deltaVel );
	hkAddVelocityBuildJacobian( deltaVel, accumIndex, out );
	accum.m_linearVel.add4( deltaVel );
	hkBool doNotWriteHeaderSchema = false;
	hkpSimpleContactConstraintAtom* contact = const_cast<hkpSimpleContactConstraintAtom*>( static_cast<const hkpSimpleContactConstraintAtom*>( child ) );
	hkSimpleContactConstraintDataBuildJacobian( contact, modifiedIn, doNotWriteHeaderSchema, out );
	deltaVel.setNeg4( deltaVel );
	hkAddVelocityBuildJacobian( deltaVel, accumIndex, out );
}
// A STAND-IN caller, not a function of the game: it only makes the compiler emit the static FUN_009fc870 above (see the head).
void __cdecl standInCallerOfMovingSurfaceModifier( const hkpConstraintAtom* atoms, const hkpConstraintQueryIn& tmpIn, hkpConstraintQueryOut& out )
{
	hkpConstraintQueryIn in = tmpIn;
	hkTransform baseA;
	hkTransform baseB;
	FUN_009fc870( *static_cast<const hkpMovingSurfaceModifierConstraintAtom*>( atoms ), in, baseA, baseB, out );
}

}  // namespace f3m_009fc870

// @f3 0x009e0120 (community match, verified in this file)
namespace f3m_009e0120 {
namespace Writer834 {
void FUN_00901f10(void*,int);
struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void set(float a, float b, float c, float d) {x=a; y=b; z=c; w=d;}
};

struct hkReferencedObject
{
    int unk00; unsigned short size; mutable short refs;
};

template <class T>
struct S009e0120_Array
{
    T* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
    void AddBack(const T& v) { if (m_iElementCount == (m_capFlags & 0x3fffffff)) FUN_00901f10(this,sizeof(T)); m_data[m_iElementCount++] = v; }
};

struct S009e0120_Writer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    S009e0120_Array<hkVector4> m_kShapeVectorData;
    S009e0120_Array<int> m_commands;
    int unk28, unk2c, unk30;
    S009e0120_Array<const hkReferencedObject*> m_kTrackedObjects;
};

struct S009e0120_Class
{
    int unk00;
    S009e0120_Writer* m_pStreamWriter;
    int FUN_009e0120(bool flag, const hkReferencedObject* object);
};

// pdb: hkpConstraintConstructionKit::setAngularMotor | hkpConstraintConstructionKit.obj | tesv_win, objopen_prop, low
int S009e0120_Class::FUN_009e0120(bool flag, const hkReferencedObject* object)
{
    m_pStreamWriter->m_commands.AddBack(0xe);
    m_pStreamWriter->m_commands.AddBack(flag);

    int index = m_pStreamWriter->m_kShapeVectorData.m_iElementCount;
    hkVector4 v;
    v.set((float)m_pStreamWriter->m_kTrackedObjects.m_iElementCount, 0.0f, 0.0f, 0.0f);
    if (object->size) ++object->refs;
    S009e0120_Array<hkVector4>& vectors = m_pStreamWriter->m_kShapeVectorData;
    if (vectors.m_iElementCount == (vectors.m_capFlags & 0x3fffffff)) FUN_00901f10(&vectors, sizeof(hkVector4));
    vectors.m_data[vectors.m_iElementCount++].set(v.x, 0.0f, 0.0f, 0.0f);
    m_pStreamWriter->m_kTrackedObjects.AddBack(object);

    S009e0120_Writer* writer = m_pStreamWriter;
    writer->unk04 += 0x40;
    writer->unk08 += 1;
    writer->unk0c += 3;
    return index;
}
}
}   // namespace f3m_009e0120

// @f3 0x009e5ae0 (community match, verified in this file)
namespace f3m_009e5ae0 {
// 0x009e5ae0: fills in the spheres a cylinder collides with against height fields
// (hkpCylinderShape::getCollisionSpheres in Havok terms): eight around the rim of each end, and one on the axis at
// each end. A cylinder taller than it is wide gets its rim spheres pulled towards the axis and its two axis spheres
// pushed inwards and enlarged instead.

namespace f3m_009e5ae0 {

typedef float hkReal;
typedef hkReal hkSimdRealParameter;      // a scalar argument of the vector functions

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void mul4(hkSimdRealParameter rs)
    {
        hkReal s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter rs)
    {
        x = a.x + rs * b.x;
        y = a.y + rs * b.y;
        z = a.z + rs * b.z;
        w = a.w + rs * b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    __forceinline hkReal lengthSquared3() const { return dot3(*this); }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

// centre in x, y, z and radius in w
class hkSphere
{
public:
    __forceinline hkVector4& getPositionAndRadius() { return m_pos; }
    __forceinline void setRadius(hkReal newRadius) { m_pos(3) = newRadius; }

    hkVector4 m_pos;
};

class hkpCylinderShape
{
public:
    const hkSphere* hkpCylinderShape_getCollisionSpheresImpl(hkSphere* sphereBuffer) const;

    __forceinline hkReal getRadius() const { return m_radius; }
    __forceinline hkReal getCylinderRadius() const { return m_cylRadius; }
    __forceinline const hkVector4& getVertex(int i) const { return (&m_vertexA)[i]; }

    void* m_vtable;
    int unk04;
    unsigned int m_userData;
    int m_type;
    hkReal m_radius;
    hkReal m_cylRadius;
    hkReal m_cylBaseRadiusFactorForHeightFieldCollisions;
    int unk1c;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_perpendicular1;
    hkVector4 m_perpendicular2;
};

// pdb: hkpCylinderShape::getCollisionSpheresImpl | hkpCylinderShape.obj | fnv360_0822_retail, objrun + bridge(uconst|vtable) + skyrim(objrun), high
const hkSphere* hkpCylinderShape::hkpCylinderShape_getCollisionSpheresImpl(hkSphere* sphereBuffer) const
{
    hkReal radius = getCylinderRadius();
    hkReal cylRadius = radius;
    hkReal heightShift = 0.0f;
    {
        hkVector4 symmetryAxis;
        symmetryAxis.setSub4(m_vertexB, m_vertexA);
        hkReal heightSqr = symmetryAxis.lengthSquared3();

        // taller than wide: the rim spheres go towards the axis, the axis spheres inwards
        if (heightSqr >= radius * 4.0f * radius)
        {
            heightShift = radius;
            cylRadius = radius * m_cylBaseRadiusFactorForHeightFieldCollisions;
        }
    }

    // the eight directions around the rim
    hkVector4 diag1;
    diag1.setAdd4(m_perpendicular1, m_perpendicular2);
    diag1.mul4(cylRadius * 0.70710678f);
    hkVector4 diag2;
    diag2.setSub4(m_perpendicular1, m_perpendicular2);
    diag2.mul4(cylRadius * 0.70710678f);
    hkVector4 perp1;
    perp1.setMul4(cylRadius, m_perpendicular1);
    hkVector4 perp2;
    perp2.setMul4(cylRadius, m_perpendicular2);

    // the fourth component of a sphere is its radius: keep the directions out of it
    diag1(3) = 0;
    diag2(3) = 0;
    perp1(3) = 0;
    perp2(3) = 0;

    hkReal sphereRadius = getRadius();

    for (int i = 0; i < 2; i++)
    {
        hkVector4 center = getVertex(i);
        center(3) = sphereRadius;

        const int base = i * 8;
        sphereBuffer[base + 0].getPositionAndRadius().setAdd4(center, perp1);
        sphereBuffer[base + 1].getPositionAndRadius().setAdd4(center, diag1);
        sphereBuffer[base + 2].getPositionAndRadius().setAdd4(center, perp2);
        sphereBuffer[base + 3].getPositionAndRadius().setSub4(center, diag2);
        sphereBuffer[base + 4].getPositionAndRadius().setSub4(center, perp1);
        sphereBuffer[base + 5].getPositionAndRadius().setSub4(center, diag1);
        sphereBuffer[base + 6].getPositionAndRadius().setSub4(center, perp2);
        sphereBuffer[base + 7].getPositionAndRadius().setAdd4(center, diag2);
    }

    // the two spheres on the axis
    {
        hkVector4 unitAxis;
        unitAxis.setCross(m_perpendicular1, m_perpendicular2);
        sphereBuffer[16].getPositionAndRadius().setAddMul4(getVertex(0), unitAxis, heightShift);
        sphereBuffer[17].getPositionAndRadius().setAddMul4(getVertex(1), unitAxis, -heightShift);

        hkReal axisRadius = heightShift + sphereRadius;
        sphereBuffer[16].setRadius(axisRadius);
        sphereBuffer[17].setRadius(axisRadius);
    }

    return sphereBuffer;
}

}
}   // namespace f3m_009e5ae0

// @f3 0x009f4cb0 (community match, verified in this file)
// 0x009f4cb0: hkToiContactPointViewer_displayArrow(hkDebugDisplayHandler* handler, const hkVector4& from,
// const hkVector4& dir, int color, int tag) of Havok 5.5.0 (hkpUtilities, hkpToiContactPointViewer.cpp; compiled
// with /MT /Ox /Ob1 /Oi /Ot /GF /GS-), a file-local (static) function.
// Draws an arrow for a time-of-impact contact: the shaft from 'from' to from + dir, and two head lines from the tip
// to a point 85% along the shaft, offset either way by a perpendicular of dir scaled to 15% of its length; inside
// Havok's timer "ToiDisplayArrow" and only for a dir longer than the float epsilon.
// The function takes 'from' in ecx and 'dir' in eax (handler, color and tag on the stack): Visual C++ 2005 gives a
// static function whose address is never taken a register convention of its own when it sees every call to it in
// the same file, without whole-program optimization. Its one caller from the same source file,
// hkpToiContactPointViewer::contactProcessCallback (0x009f5050), is therefore defined here as well; without it the
// function is not emitted at all, and with external linkage it takes all five arguments from the stack (835 bytes
// instead of 853).
// This file is built from the Havok 5.5.0 SDK's own headers: the functions were compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the code needs (whole declarations by
// work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library object); those
// declarations are the SDK's text with its names. The SDK's int 3 traps in the unused placement operators were
// removed; the timer read is the kit's accepted two-instruction block, which is exactly the SDK's own
// hkMonitorStream::TimerCommand::setTime. The bodies follow the SDK's unoptimized (hybrid) library object statement
// by statement and reproduce the release object. Only the function carries the packet's name.
namespace f3m_009f4cb0 {

typedef float  hkReal;
typedef float  hkFloat32;
typedef double hkDouble64;
typedef signed char		hkChar;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __int64 hkUint64;
typedef __int64 hkInt64;
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
		}
	private:
		char m_bool;
};
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		hkInt32 f = *(int*)&fv;
		hkInt32* minf = (hkInt32*)&hkUFloat8_intToReal[0];
		hkInt32* maxf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
		for (int i = 6; i>=0; i--)
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				__forceinline void setData(T p)
				{
					hkUlong v = hkUlong(p);
					TlsSetValue( m_slotID, (void*)v );
				}
				unsigned long m_slotID;
		};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
};
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		T m_storage[N];
	public:
		hkInplaceArray(hkFinishLoadedObjectFlag f) : hkArray<T>(f) { }
};
namespace hkSmallArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T>
class hkSmallArray
{
		friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkSmallArrayUtil::_reserveMore(void* array, int sizeElem);
	public:
		__forceinline void reserve(int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		void clearAndDeallocate();
	public:
		enum
		{
			CAPACITY_MASK			= hkUint16(0x3fff),
			FLAG_MASK				= hkUint16(0xC000),
			DONT_DEALLOCATE_FLAG	= hkUint16(0x8000),
			LOCKED_FLAG				= hkUint16(0x4000),
			FORCE_SIGNED			= -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
extern "C" {
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		inline hkQuaternion() { }
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
template < typename K , typename V > class hkPointerMap;
class hkStreamWriter;
class hkMonitorStream
{
	public:
		static hkMonitorStream& getInstance()
		{
			extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
			return *hkMonitorStream__m_instance.getData();
		}
		void __cdecl reset();
		void __cdecl resize( int newSize );
	public:
		__forceinline char* __cdecl getStart() { return m_start.val(); }
		__forceinline char* __cdecl getEnd() { return m_end.val(); }
		__forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); }
		__forceinline char* __cdecl getCapacity() { return m_capacity.val(); }
		__forceinline hkBool __cdecl memoryAvailable( )
		{
			return getEnd() < getCapacityMinus16();
		}
		__forceinline int __cdecl getCurrentMonitorDataSize()
		{
			return (int)(m_end.val() - m_start.val());
		}
		__forceinline void* __cdecl expandby( int size ) { char* h = m_end.val(); char* newEnd = h + size; m_end = newEnd; return h; }
		__forceinline void __cdecl setEnd(char* ptr) {  m_end = ptr; }
		__forceinline hkBool __cdecl isBufferAllocatedOnTheHeap() { return m_isBufferAllocatedOnTheHeap; }
		void __cdecl setStaticBuffer( char* buffer, int bufferSize );
	public:
		static void __cdecl init();
		void __cdecl quit();
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
	public:
		struct Command
		{
			const char* m_commandAndMonitor;
		};
		struct AddValueCommand : public hkMonitorStream::Command
		{
			float m_value;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			hkUint32	m_time0;
			hkUint32	m_time1;
			__forceinline void setTime();
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			const char* m_nameOfFirstSplit;
		};
};
void hkMonitorStream::TimerCommand::setTime()
{
		hkUint32 ticks;
		__asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
		m_time0 = ticks;
}
class hkAabb;
struct hkAabbUint32;
namespace hkVector4Util
{
__forceinline void __cdecl calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut);
}
inline void __cdecl hkVector4Util::calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
	int min = 0;
	int ok1 = 1;
	int ok2 = 2;
	hkReal a0 = hkMath::fabs(vectorIn(0));
	hkReal a1 = hkMath::fabs(vectorIn(1));
	hkReal a2 = hkMath::fabs(vectorIn(2));
	if( a1 < a0 )
	{
		ok1 = 0;
		min = 1;
		a0 = a1;
	}
	if(a2 < a0)
	{
		ok2 = min;
		min = 2;
	}
	biVectorOut.setZero4();
	biVectorOut(ok1) =  vectorIn(ok2);
	biVectorOut(ok2) = -vectorIn(ok1);
}
class hkDisplayGeometry;
class hkDebugDisplayHandler
{
	public:
		enum Command
		{
			HK_STEP = 0x00,
			HK_ADD_GEOMETRY,
			HK_UPDATE_GEOMETRY,
		};
		virtual ~hkDebugDisplayHandler() {}
		virtual hkResult addGeometry(const hkArray<hkDisplayGeometry*>& geometries, const hkTransform& transform, hkUlong id, int tag, hkUlong shapeIdHint) = 0;
		virtual hkResult addGeometryInstance(hkUlong origianalGeomId, const hkTransform& transform, hkUlong id, int tag, hkUlong shapeIdHint) = 0;
		virtual hkResult setGeometryColor(int color, hkUlong id, int tag) = 0;
		virtual hkResult updateGeometry(const hkTransform& transform, hkUlong id, int tag) = 0;
		virtual hkResult removeGeometry(hkUlong id, int tag, hkUlong shapeIdHint) = 0;
		virtual hkResult updateCamera(const hkVector4& from, const hkVector4& to, const hkVector4& up, hkReal nearPlane, hkReal farPlane, hkReal fov, const char* name) = 0;
		virtual hkResult displayPoint(const hkVector4& position, int colour, int tag) = 0;
		virtual hkResult displayLine(const hkVector4& start, const hkVector4& end, int color, int tag) = 0;
		virtual hkResult sendMemStatsDump(const char* data, int length) = 0;
		virtual hkResult holdImmediate() = 0;
		virtual void lockForUpdate() { }
		virtual void unlockForUpdate() { }
};
class hkColor
{
	public:
		static int __cdecl rgbFromChars(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 0xff);
		static int __cdecl rgbFromFloats(const hkReal red, const hkReal green, const hkReal blue, const hkReal alpha = 1.0f);
		enum ExtendedColours
		{
			MAROON = 0xFF800000,
			DARKRED = 0xFF8B0000,
			RED = 0xFFFF0000,
		};
};
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkVector4& getPosition() const;
		inline hkVector4& getPosition();
		inline void setPosition(const hkVector4& position);
		inline const hkVector4& getNormal() const;
		inline const hkVector4& getSeparatingNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setSeparatingNormal( const hkVector4& normal, hkReal dist );
		inline void setSeparatingNormal( const hkVector4& separatingNormal );
};
struct hkpProcessCdPoint
{
	hkContactPoint m_contact;
    hkPadSpu<hkUint32>	m_contactPointId;
};
class hkContactPointMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline void setUserData( hkUlong data );
		inline hkBool32 isPotential();
		inline void setMaxImpulsePerStep( hkUFloat8 impulse );
		inline hkReal getMaxImpulsePerStep();
	protected:
		hkUlong m_userData;
		hkUFloat8 m_friction;
		hkUint8 m_restitution;
	public:
		hkUFloat8 m_maxImpulse;
	public:
		void reset()
		{
			m_friction.m_value = 0;
			m_maxImpulse.m_value = 0;
			m_restitution = 0;
			m_flags = CONTACT_IS_NEW_AND_POTENTIAL;
		}
		enum  FlagEnum
		{
			CONTACT_IS_NEW_AND_POTENTIAL  = 1,
			CONTACT_USES_SOLVER_PATH2 = 2,
			CONTACT_BREAKOFF_OBJECT_ID = 4,
		};
		hkUint8 m_flags;
		friend class hkpSaveContactPointsEndianUtil;
};
class hkpConvexShape;
class hkpTriangleShape;
class hkpGskCache
{
	public:
		hkUint16  m_vertices[4];
		hkUint8	  m_dimA;
		hkUint8	  m_dimB;
		hkUint8	  m_maxDimB : 4;
		typedef hkUint8 GskFlags;
		enum GskFlagValues
		{
			GSK_FLAGS_SHAPE_A_IS_CYLINDER           = 0x01,
			GSK_FLAGS_CONVEX_LIST_IN_GSK_MODE  = 0x20,
			GSK_FLAGS_PROCESS_FUNCTION_CALLED  = 0x40,
			ONE_BIT_STILL_UNUSED     = 0x80
		};
		hkUint8 m_gskFlags;
	public:
		void init( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& btoa );
		void initTriangle( const hkpConvexShape* shapeA, const hkpTriangleShape* shapeB, const hkTransform& btoa );
		inline void flip();
};
__declspec(align(16)) class hkGskCache16 : public hkpGskCache
{
	public:
		void set(const hkGskCache16& other)
		{
				*this = other;
		}
};
class hkpSolverResults
{
	public:
		inline hkReal getImpulseApplied() const;
		inline hkpSolverResults();
		inline void init();
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};
struct hkpSimpleContactConstraintAtom;
class hkpContactPointProperties : public hkpSolverResults, public hkContactPointMaterial
{
	public:
		inline hkBool wasUsed()
		{
			return !isPotential() && ( m_impulseApplied > 0.f );
		}
	public:
		hkReal m_internalDataA;
		typedef hkUint32 UserData;
		static inline int getNumExtendedUserDatas(const hkpSimpleContactConstraintAtom* atom, int bodyIdx);
		inline hkpContactPointProperties::UserData& getExtendedUserData(const hkpSimpleContactConstraintAtom* atom, int bodyIdx, int i);
};
__declspec(align(16)) class hkContactPointPropertiesWithExtendedUserData16 : public hkpContactPointProperties
{
	public:
};
class hkpContactPointPropertiesStream
{
public:
	__forceinline hkpContactPointProperties* asProperties() { return reinterpret_cast<hkpContactPointProperties*>(this); }
	__forceinline const hkpContactPointProperties* asProperties() const { return reinterpret_cast<const hkpContactPointProperties*>(this); }
};
class hkpSimpleContactConstraintDataInfo
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum {	HK_FLAG_OK = 0x00, HK_FLAG_POINT_REMOVED = 0x01, HK_FLAG_AREA_CHANGED = 0x04 };
		void init()
		{
			m_flags = HK_FLAG_OK;
		}
		hkpSimpleContactConstraintDataInfo()
		{
			init();
		}
		__declspec(align(16)) hkUint16 m_flags;
		hkUint16 m_index;
		hkUint32 m_data[7];
		hkpSimpleContactConstraintDataInfo(hkFinishLoadedObjectFlag f) {}
};
struct hkpConstraintInfo
{
	int m_maxSizeOfSchema;
	int m_sizeOfSchemas;
	int m_numSolverResults;
	int m_numSolverElemTemps;
	inline void clear( ) { m_maxSizeOfSchema = 0; m_sizeOfSchemas = 0; m_numSolverResults = 0; m_numSolverElemTemps = 0; }
	inline void addHeader( ) { m_sizeOfSchemas += 16; }
	inline void add( const hkpConstraintInfo& other);
	inline void sub( const hkpConstraintInfo& other);
	inline void merge( const hkpConstraintInfo& other);
};
class hkpConstraintQueryIn;
class hkpConstraintQueryOut;
class hkpConstraintInstance;
typedef void hkpConstraintRuntime;
class hkpConstraintData : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpConstraintData(hkFinishLoadedObjectFlag f) {}
        enum ConstraintType
        {
            CONSTRAINT_TYPE_BALLANDSOCKET = 0,
            CONSTRAINT_TYPE_HINGE = 1,
        };
		inline hkpConstraintData();
		inline virtual ~hkpConstraintData();
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		virtual hkBool isValid() const = 0;
		virtual int getType() const = 0;
		struct RuntimeInfo
		{
			int m_sizeOfExternalRuntime;
			int m_numSolverResults;
		};
		virtual void getRuntimeInfo( hkBool wantRuntime, RuntimeInfo& infoOut ) const = 0;
		virtual hkpSolverResults* getSolverResults( hkpConstraintRuntime* runtime );
		virtual void addInstance( hkpConstraintInstance* constraint, hkpConstraintRuntime* runtime, int sizeOfRuntime ) const;
		virtual hkBool isBuildJacobianCallbackRequired() const { return false; }
		virtual void buildJacobianCallback( const hkpConstraintQueryIn &in ) { ; }
		struct ConstraintInfo : public hkpConstraintInfo
		{
			struct hkpConstraintAtom* m_atoms;
			hkUint32		  m_sizeOfAllAtoms;
		};
		virtual void getConstraintInfo( ConstraintInfo& infoOut ) const = 0;
		static void __cdecl getConstraintInfoUtil( const hkpConstraintAtom* atoms, int sizeOfAllAtoms, ConstraintInfo& infoOut );
	public:
		hkUlong m_userData;
};
struct hkpConstraintAtom
{
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		enum AtomType
		{
			TYPE_INVALID = 0,
			TYPE_BRIDGE,
			TYPE_CONTACT,
			TYPE_MODIFIER_SOFT_CONTACT,
			TYPE_MODIFIER_MASS_CHANGER,
			TYPE_MODIFIER_VISCOUS_SURFACE,
			TYPE_MODIFIER_MOVING_SURFACE,
			CALLBACK_REQUEST_NONE = 0,
			CALLBACK_REQUEST_NEW_CONTACT_POINT = 1,
			CALLBACK_REQUEST_SETUP_PPU_ONLY = 2,
			CALLBACK_REQUEST_SETUP_CALLBACK = 4
		};
	public:
		__forceinline enum AtomType getType() const { return m_type; }
		__forceinline int isModifierType() const { return m_type >= TYPE_MODIFIER_SOFT_CONTACT; }
	protected:
		hkpConstraintAtom(enum AtomType type) : m_type(type) {}
	private:
		hkpConstraintAtom();
	public:
		hkEnum<AtomType,hkUint16> m_type;
		hkpConstraintAtom(hkFinishLoadedObjectFlag f) {}
};
struct hkpSimpleContactConstraintAtom : public hkpConstraintAtom
{
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		__forceinline hkpConstraintAtom* next() const { ; return 0; }
		__forceinline int numSolverResults() const    { return m_numContactPoints+3; }
		__forceinline void addToConstraintInfo(hkpConstraintInfo& infoOut) const
		{
			int size = m_numContactPoints;
			infoOut.m_numSolverResults   += size + 2;
			infoOut.m_numSolverElemTemps += size + (2 + 1);
			if ( size >= 2 )
			{
				infoOut.m_sizeOfSchemas   += 144 - 112;
				infoOut.m_numSolverResults   += 1;
				infoOut.m_numSolverElemTemps += 1 + 0;
			}
		}
	public:
		hkUint16 m_sizeOfAllAtoms;
		hkUint16 m_numContactPoints;
		hkUint16 m_numReservedContactPoints;
		hkUint8 m_numUserDatasForBodyA;
		hkUint8 m_numUserDatasForBodyB;
};
enum {HK_MAX_CONTACT_POINT = 256 };
class hkpConstraintOwner;
struct hkpProcessCollisionData
{
	public:
		inline int getNumContactPoints() const;
		inline hkpProcessCdPoint& getContactPoint( int i );
		inline hkpProcessCdPoint* getFirstContactPoint();
		inline hkpProcessCdPoint* getEnd();
		inline hkBool isEmpty() const;
		inline hkBool hasToi() const;
		inline hkContactPoint& getToiContactPoint();
		inline hkTime getToi() const;
		inline hkpContactPointProperties& getToiProperties();
	public:
		hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
		hkPadSpu<hkpConstraintOwner*> m_constraintOwner;
		hkpProcessCdPoint   m_contactPoints[HK_MAX_CONTACT_POINT];
		struct ToiInfo
		{
			public:
				inline ToiInfo();
				inline void flip();
			public:
		};
		struct ToiInfo m_toi;
		inline hkpProcessCollisionData( hkpConstraintOwner* owner );
};
inline hkpProcessCdPoint* hkpProcessCollisionData::getEnd()
{
	return m_firstFreeContactPoint;
}
class hkProcessContext;
enum hkpShapeType
{
	HK_SHAPE_INVALID = 0,
	HK_SHAPE_CONVEX,
	HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX,
	HK_SHAPE_SPHERE,
	HK_SHAPE_USER2,
	HK_SHAPE_MAX_ID,
	HK_SHAPE_ALL = -1
};
class hkpCdVertex;
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpShape( hkpShapeType type );
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			static void __cdecl resetShapeFunctions();
			typedef void (__cdecl *GetSupportingVertexFunc)        (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int  (__cdecl *GetNumCollisionSpheresFunc)		(const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc)					(const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				hkPadSpu<GetSupportingVertexFunc>			m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc>				m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc>						m_getCentreFunc;
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				GetAabbFunc							m_getAabbFunc;
				CastRayFunc							m_castRay;
				GetChildShapeFunc					m_getChildShapeFunc;
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
	public:
	public:
		hkUlong m_userData;
	public:
		hkEnum<hkpShapeType, hkUint32> m_type;
	public:
		hkpShape( class hkFinishLoadedObjectFlag flag ) { m_type = HK_SHAPE_INVALID; }
};
class hkMotionState;
class hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpCdBody(  ){}
		friend class hkpCollidable;
		const hkpCdBody*		 m_parent;
};
class hkpBroadPhaseHandle
{
	public:
};
enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_INVALID,
	HK_COLLIDABLE_QUALITY_FIXED,
	HK_COLLIDABLE_QUALITY_USER,
	HK_COLLIDABLE_QUALITY_CHARACTER,
	HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,
	HK_COLLIDABLE_QUALITY_MAX
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpTypedBroadPhaseHandle( int type );
		hkUint32 m_collisionFilterInfo;
};
class hkpCollidable : public hkpCdBody
{
	public:
		__forceinline void setQualityType(hkpCollidableQualityType type);
		__forceinline hkReal getAllowedPenetrationDepth() const;
		__forceinline void setAllowedPenetrationDepth( hkReal val );
	public:
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		__forceinline int getType() const;
		hkpCollidable( class hkFinishLoadedObjectFlag flag );
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				BoundingVolumeData();
				__forceinline const hkAabbUint32& getAabbUint32() const { return reinterpret_cast<const hkAabbUint32&>(m_min); }
				__forceinline       hkAabbUint32& getAabbUint32()		  { return reinterpret_cast<      hkAabbUint32&>(m_min); }
				__forceinline void invalidate() { m_min[0] = 1; m_max[0] = 0; }
				__forceinline bool isValid() const { return m_min[0] <= m_max[0]; }
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpLinkedCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpLinkedCollidable();
		inline hkpLinkedCollidable( class hkFinishLoadedObjectFlag flag ) : hkpCollidable(flag) {}
	public:
		struct CollisionEntry
		{
			hkpAgentNnEntry* m_agentEntry;
			hkpLinkedCollidable*	m_partner;
		};
		hkArray<struct CollisionEntry> m_collisionEntries;
};
class hkMultiThreadCheck
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		__forceinline hkMultiThreadCheck();
		__forceinline void init();
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		__forceinline void markForRead( ReadMode mode = RECURSIVE )
		{
			;
		}
		__forceinline void markForWrite( )
		{
			;
		}
		__forceinline bool isMarkedForWrite( )
		{
			return true;
		}
		__forceinline bool isMarkedForReadRecursive()
		{
			return true;
		}
		__forceinline void unmarkForRead( )
		{
			;
		}
		__forceinline void unmarkForWrite()
		{
			;
		}
		bool isMarkedForWriteImpl( );
		void unmarkForReadImpl( );
		void unmarkForWriteImpl();
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};
struct hkpPropertyValue
{
	inline int getInt() const;
	inline void* getPtr() const;
};
class hkpProperty
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		inline hkpProperty();
		inline hkpProperty( hkUint32 key, hkInt32 value );
		inline hkpProperty( hkUint32 key, hkpPropertyValue value );
	public:
		hkUint32 m_key;
		hkUint32 m_alignmentPadding;
		struct hkpPropertyValue m_value;
	public:
		hkpProperty( class hkFinishLoadedObjectFlag flag ) { }
	public:
		static void __cdecl mapStringToKey( const char* string, hkUint32& keyOut );
};
class hkpWorld;
namespace hkWorldOperation
{
enum Result
	{
		POSTPONED,
		DONE
	};
}
class hkpWorldObject : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		void addProperty( hkUint32 key, hkpPropertyValue value );
		hkpPropertyValue removeProperty( hkUint32 key );
		void editProperty( hkUint32 key, hkpPropertyValue value );
		inline hkpPropertyValue getProperty( hkUint32 key ) const;
		inline hkBool hasProperty( hkUint32 key ) const;
		void lockProperty( hkUint32 key );
		void unlockProperty( hkUint32 key );
		void checkReadWrite();
		void checkReadOnly() const;
		void addReference();
		void removeReference();
		void addReferenceAsCriticalOperation();
		void removeReferenceAsCriticalOperation();
	public:
		enum BroadPhaseType
		{
			BROAD_PHASE_INVALID,
			BROAD_PHASE_ENTITY,
			BROAD_PHASE_PHANTOM,
			BROAD_PHASE_BORDER,
			BROAD_PHASE_MAX_ID
		};
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationUtil;
		inline void setWorld( hkpWorld* world );
		virtual class hkMotionState* getMotionState() = 0;
		class hkpLinkedCollidable m_collidable;
	protected:
		class hkMultiThreadCheck m_multiThreadCheck;
		const char* m_name;
		hkArray<class hkpProperty> m_properties;
	public:
		hkpWorldObject( class hkFinishLoadedObjectFlag flag );
};
class hkpMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpMaterial();
		inline hkReal getFriction() const;
		inline hkReal getRestitution() const;
		inline void setFriction( hkReal newFriction );
		inline void setRestitution( hkReal newRestitution );
		static inline hkReal __cdecl getCombinedFriction( hkReal frictionA, hkReal frictionB);
		static inline hkReal __cdecl getCombinedRestitution( hkReal restitutionA, hkReal restitutionB);
		enum ResponseType
		{
			RESPONSE_INVALID,
			RESPONSE_SIMPLE_CONTACT,
			RESPONSE_REPORTING,
			RESPONSE_NONE,
			RESPONSE_MAX_ID
		};
		inline void setResponseType( enum hkpMaterial::ResponseType t );
		inline enum hkpMaterial::ResponseType getResponseType() const;
	private:
		hkEnum<ResponseType,hkInt8> m_responseType;
		hkReal m_friction;
		hkReal m_restitution;
	public:
		hkpMaterial( class hkFinishLoadedObjectFlag flag ) { }
};
class hkpEntity;
class hkpRigidBody;
class hkpSimulationIsland;
class hkpConstraintInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum ConstraintPriority
		{
			PRIORITY_INVALID,
			PRIORITY_PSI,
			PRIORITY_TOI,
			PRIORITY_TOI_HIGHER,
			PRIORITY_TOI_FORCED,
		};
		enum InstanceType
		{
			TYPE_NORMAL,
			TYPE_CHAIN
		};
		enum AddReferences
		{
			DO_NOT_ADD_REFERENCES,
			DO_ADD_REFERENCES
		};
		enum CloningMode
		{
			CLONE_INSTANCES_ONLY,
			CLONE_DATAS_WITH_MOTORS
		};
		hkpConstraintInstance(hkpEntity* entityA, hkpEntity* entityB, hkpConstraintData* data, ConstraintPriority priority = PRIORITY_PSI);
		~hkpConstraintInstance();
		hkpConstraintInstance* clone(hkpEntity* newEntityA, hkpEntity* newEntityB, CloningMode mode = CLONE_INSTANCES_ONLY) const;
	protected:
		inline hkpConstraintRuntime* getRuntime() const;
		inline void setWantRuntime( hkBool b );
		inline hkBool getWantRuntime() const ;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		inline ConstraintPriority getPriority() const;
		void setPriority( ConstraintPriority priority );
		inline const char* getName() const;
		inline void setName( const char* name );
	public:
	protected:
		hkBool				m_wantRuntime;
		const char* m_name;
	public:
		hkUlong m_userData;
		struct hkConstraintInternal* m_internal;
	public:
		hkpConstraintInstance(hkFinishLoadedObjectFlag f) { }
	private:
		friend class hkpWorldConstraintUtil;
		friend class hkpSimpleConstraintContactMgr;
		friend class hkpSaveContactPointsUtil;
		hkpConstraintInstance(){}
};
inline hkUlong hkpConstraintInstance::getUserData() const
{
	return m_userData;
}
class hkMotionState
{
		class hkSweptTransform m_sweptTransform;
	public:
		hkVector4 m_deltaAngle;
		hkReal m_objectRadius;
		hkReal	m_linearDamping;
		hkReal	m_angularDamping;
		hkUFloat8 m_maxLinearVelocity;
		hkUFloat8 m_maxAngularVelocity;
		hkUint8	m_deactivationClass;
};
class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_SPHERE_INERTIA,
		MOTION_STABILIZED_SPHERE_INERTIA,
		MOTION_BOX_INERTIA,
		MOTION_STABILIZED_BOX_INERTIA,
		MOTION_KEYFRAMED,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};
public:
	inline MotionType getType() const { return m_type; }
public:
	enum { NUM_INACTIVE_FRAMES_TO_DEACTIVATE = 5 };
public:
	hkEnum<MotionType, hkUint8>	m_type;
	hkUint8		m_deactivationIntegrateCounter;
	hkUint16	m_deactivationNumInactiveFrames[2];
	class hkMotionState m_motionState;
	hkVector4 m_inertiaAndMassInv;
	hkVector4		m_linearVelocity;
	hkVector4		m_angularVelocity;
	hkVector4 m_deactivationRefPosition[ 2 ];
	hkUint32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
public:
	hkpMotion( class hkFinishLoadedObjectFlag flag ) { }
};
class hkpKeyframedRigidMotion : public hkpMotion
{
	public:
		virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		virtual void applyLinearImpulse(const hkVector4& imp);
		virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
		virtual void applyAngularImpulse(const hkVector4& imp);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
		virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
	protected:
		hkpKeyframedRigidMotion(): hkpMotion(hkFinishLoadedObjectFlag()){ m_savedMotion = 0; }
	public:
	public:
		virtual void setStepPosition( hkReal position, hkReal timestep );
		virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
	public:
		hkpKeyframedRigidMotion( class hkFinishLoadedObjectFlag flag ) : hkpMotion( flag ) {}
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpMaxSizeMotion() : hkpKeyframedRigidMotion( ) {}
		hkpMaxSizeMotion( class hkFinishLoadedObjectFlag flag ) : hkpKeyframedRigidMotion( flag ) {}
	private:
		void operator=(const hkpMaxSizeMotion& other);
		hkpMaxSizeMotion( const hkpMaxSizeMotion& other );
};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpAction;
class hkpDynamicsContactMgr;
class hkSpuCollisionCallbackUtil;
class hkpEntity : public hkpWorldObject
{
	public:
		enum SpuCollisionCallbackEventFilter
		{
			SPU_SEND_NONE					= 0x00,
			SPU_SEND_CONTACT_POINT_ADDED	= 0x01,
			SPU_SEND_CONTACT_POINT_PROCESS	= 0x02,
			SPU_SEND_CONTACT_POINT_REMOVED	= 0x04,
			SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
		};
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpEntity();
		void addEntityListener( hkpEntityListener* el);
		void removeEntityListener( hkpEntityListener* el);
		void addEntityActivationListener( hkpEntityActivationListener* el);
		void removeEntityActivationListener( hkpEntityActivationListener* el);
	protected:	hkArray<hkpConstraintInstance*>				m_constraintsSlave;
	protected:
		hkArray<hkUint8> m_constraintRuntime;
		hkpSimulationIsland* m_simulationIsland;
	public:
		hkInt8  m_autoRemoveLevel;
		hkUint8 m_numUserDatasInContactPointProperties;
		hkUint32 m_uid;
	public:
		struct SpuCollisionCallback
		{
		public:
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			SpuCollisionCallback():
				m_util(0),
				m_capacity(0),
				m_eventFilter(SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS),
				m_userFilter(0x01)
			{
			}
			hkSpuCollisionCallbackUtil* m_util;
			hkUint16 m_capacity;
			hkUint8 m_eventFilter;
			hkUint8	m_userFilter;
		};
		struct ExtendedListeners
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
			hkSmallArray<hkpEntityListener*>				m_entityListeners;
		};
	public:
		struct SpuCollisionCallback m_spuCollisionCallback;
	protected:	mutable ExtendedListeners* m_extendedListeners;
	public:		class hkpMaxSizeMotion m_motion;
	protected:
		friend class hkpEntityCallbackUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpWorld;
		friend class hkpSimulationIsland;
		friend class hkpWorldOperationUtil;
		hkSmallArray<hkpCollisionListener*>			m_collisionListeners;
		hkSmallArray<hkpAction*>						m_actions;
};
class hkpPhysicsContextWorldListener
{
    public:
        virtual ~hkpPhysicsContextWorldListener() { }
        virtual void worldAddedCallback( hkpWorld* newWorld ) = 0;
        virtual void worldRemovedCallback( hkpWorld* newWorld ) = 0;
};
class hkpPhysicsContext;
class hkOArchive: public hkReferencedObject
{
	public:
		hkOArchive(hkStreamWriter* sb, hkBool byteswap=0);
		hkOArchive(const char* filename, hkBool byteswap=0);
		hkOArchive(void* mem, int memSize, hkBool byteswap=0);
		hkOArchive(hkArray<char>& arr, hkBool byteswap=0);
		~hkOArchive();
		void writeArrayGeneric(const void* buf, int sizeelem, int nelem);
		int writeRaw(const void* buf, int nbytes);
		void setByteSwap(hkBool on);
		hkBool getByteSwap() const;
		hkBool isOk() const;
		hkStreamWriter* getStreamWriter();
		void setStreamWriter(hkStreamWriter* writer);
	protected:
		hkStreamWriter*		m_writer;
		hkBool m_byteSwap;
};
struct hkGeometry
{
	struct Triangle
	{
		int m_a;
		int m_b;
		int m_c;
		void set( int a, int b, int c )
		{
			m_a = a;
			m_b = b;
			m_c = c;
		}
	};
	hkArray<hkVector4> m_vertices;
	hkArray<Triangle> m_triangles;
};
class hkDisplaySerializeOStream : public hkOArchive
{
};
class hkDisplaySerializeIStream;
class hkProcessHandler;
class hkProcess
{
	public:
		hkProcess( hkBool selectable )
			: m_selectable(selectable) {}
		virtual ~hkProcess() {}
		virtual int getProcessTag() = 0;
		hkBool m_selectable;
		hkDisplaySerializeIStream* m_inStream;
		hkDisplaySerializeOStream* m_outStream;
		hkDebugDisplayHandler* m_displayHandler;
		hkProcessHandler* m_processHandler;
		virtual void getConsumableCommands( hkUint8*& commands, int& numCommands ) { commands = 0; numCommands = 0; }
		virtual void consumeCommand( hkUint8 command ) { }
		virtual bool isOk() { return m_outStream && m_outStream->isOk(); }
		virtual void init() { }
		virtual void step( hkReal frameTimeInMs  ) { }
};
class hkpWorldViewerBase :   public hkReferencedObject,
							public hkProcess,
							protected hkpPhysicsContextWorldListener
{
	public:
		hkpWorldViewerBase( const hkArray<hkProcessContext*>& contexts );
		virtual ~hkpWorldViewerBase();
		virtual void getConsumableCommands( hkUint8*& commands, int& numCommands ) { commands = 0; numCommands = 0; }
		virtual void consumeCommand( hkUint8 command ) { }
		virtual void step( hkReal frameTimeInMs ) {  }
		virtual void worldRemovedCallback( hkpWorld* world ) { }
		virtual void worldAddedCallback( hkpWorld* world ) { }
	protected:
		hkpPhysicsContext* m_context;
};
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
class hkpContactMgr: public hkReferencedObject
{
	public:
		enum Type
		{
			TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
			TYPE_REPORT_CONTACT_MGR,
			TYPE_CONVEX_LIST_CONTACT_MGR,
			TYPE_NULL_CONTACT_MGR,
			TYPE_USER_CONTACT_MGR,
			TYPE_MAX
		};
		enum ToiAccept
		{
			TOI_ACCEPT = 0,
			TOI_REJECT = 1
		};
		hkpContactMgr( Type type ): m_type(type){}
		__forceinline hkResult reserveContactPoints( int numPoints );
		__forceinline void removeContactPoint( hkContactPointId cpId, hkpConstraintOwner& constraintOwner );
		__forceinline void removeToi( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties );
	public:
		virtual hkResult reserveContactPointsImpl( int numPoints ) = 0;
		virtual void removeContactPointImpl( hkContactPointId cpId, hkpConstraintOwner& constraintOwner ) = 0;
		virtual void removeToiImpl( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties ) = 0;
		virtual void cleanup(){}
	public:
		Type m_type;
};
class hkpDynamicsContactMgr: public hkpContactMgr
{
	public:
		hkpDynamicsContactMgr( Type type ): hkpContactMgr( type ) {}
		virtual hkpContactPointProperties* getContactPointProperties( hkContactPointId id ){ return 0;}
		virtual hkContactPoint* getContactPoint( hkContactPointId id ){ return 0;}
		virtual void getAllContactPointIds( hkArray<hkContactPointId>& contactPointIds ) const {}
		virtual Type getType() const = 0;
		virtual class hkpConstraintInstance* getConstraintInstance() { return 0; }
		virtual void confirmToi( struct hkpToiEvent& event, hkReal rotateNormal, class hkArray<class hkpEntity*>& outToBeActivated ){}
	protected:
		class hkpWorld*					m_world;
};
struct hkpCollisionInput;
class hkStatisticsCollector
{
	public:
		virtual ~hkStatisticsCollector() { m_clientData = 0; }
        enum { MAX_STATISTICS_CLASS_BIT = 5 };
		enum StatisticClass
		{
			MEMORY_ALL = 0xf,
			MEMORY_SHARED = 1,
			MEMORY_INSTANCE = 2,
			MEMORY_ENGINE = 4,
			MEMORY_RUNTIME = 8,
			MEMORY_APPLICATION = 16,
			MEMORY_LAST = 32
		};
		virtual void beginObject( const char* name, StatisticClass statisticClass, const hkReferencedObject* object ) = 0;
		virtual void addChunk( const char* name, StatisticClass statisticClass, const void* chunkAddress, int usedSize, int allocatedSize = 0) = 0;
		void addAllocated( const char* name, StatisticClass statisticClass, const void* chunkAddress );
		virtual void addChildObject( const char* name, StatisticClass statisticClass, const hkReferencedObject* object ) = 0;
		template<typename T>
		__forceinline void addSmallArray( const char* name, StatisticClass statisticClass, const hkSmallArray<T>& array )
		{
			if ( !(array.m_capacityAndFlags & array.DONT_DEALLOCATE_FLAG) )
			{
				addChunk( name, statisticClass, array.begin(), array.getSize() * int(sizeof(T)), array.getCapacity() * int(sizeof(T)) );
			}
		}
		template<typename T>
		__forceinline void addObjectArray( const char* name, StatisticClass statisticClass, const hkObjectArray<T>& array )
		{
			if ( !(array.m_array.m_capacityAndFlags & array.m_array.DONT_DEALLOCATE_FLAG) )
			{
				addChunk( name, statisticClass, array.begin(), array.getSize() * int(sizeof(T)), array.getCapacity() * int(sizeof(T)) );
			}
		}
		template<typename KEY, typename VALUE>
		__forceinline void addPointerMap( const char* name, StatisticClass statisticClass, const hkPointerMap<KEY,VALUE>& map )
		{
			addChunk( name, statisticClass, map.getMemStart(), map.getSize() * int(sizeof(KEY)), map.getMemSize() );
		}
		virtual void endObject( ) = 0;
	public:
		const void* m_clientData;
};
class hkpContactMgrFactory: public hkReferencedObject
{
	public:
		virtual hkpContactMgr*	createContactMgr( const hkpCollidable& a, const hkpCollidable& b, const hkpCollisionInput& input ) = 0;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const
        {
            collector->beginObject("hkpContactMgrFactory", collector->MEMORY_INSTANCE, this);
            collector->endObject();
        }
};
class hkpDynamicsCpIdMgr
{
	public:
		enum { HK_MAX_IDS_PER_OBJECT = 8 };
		enum { FREE_VALUE = 0xff };
		typedef hkUchar hkpValueType;
	public:
		inline  hkpDynamicsCpIdMgr();
		inline ~hkpDynamicsCpIdMgr() {}
		inline int newId( int value );
		inline int indexOf( int value ) const;
		inline void freeId( int id );
		inline void decrementValuesGreater( int relIndex );
		inline void getAllUsedIds( hkArray<hkContactPointId>& ids ) const;
		inline hkpValueType getValueAt(int id);
	public:
		hkInplaceArray<hkpValueType,HK_MAX_IDS_PER_OBJECT>	m_values;
};
class hkpSimpleContactConstraintData: public hkpConstraintData
{
	public:
		hkpSimpleContactConstraintData(hkpConstraintInstance* constraint, hkpRigidBody* bodyA, hkpRigidBody* bodyB);
		inline ~hkpSimpleContactConstraintData();
		inline int getNumContactPoints();
		inline const hkContactPointId getContactPointIdAt( int index );
		inline hkContactPoint& getContactPoint( int  id );
		inline hkpContactPointProperties* getContactPointProperties( int  id );
		hkContactPointId allocateContactPoint( hkpConstraintOwner& constraintOwner, hkContactPoint** cpOut, hkpContactPointProperties** cpPropsOut);
		int freeContactPoint( hkpConstraintOwner& constraintOwner, hkContactPointId id );
		virtual hkBool isValid() const;
		virtual void getConstraintInfo( hkpConstraintData::ConstraintInfo& infoOut ) const;
		virtual void getRuntimeInfo( hkBool wantRuntime, hkpConstraintData::RuntimeInfo& infoOut ) const;
		virtual hkpSolverResults* getSolverResults( hkpConstraintRuntime* runtime );
		virtual int getType() const;
		inline hkpSimpleContactConstraintData( hkFinishLoadedObjectFlag f ) { }
	public:
		hkpDynamicsCpIdMgr		m_idMgrA;
		void*					m_clientData;
		hkpConstraintInstance*	m_constraint;
		hkpSimpleContactConstraintAtom*	m_atom;
		int								m_atomSize;
};
class hkpSimpleConstraintContactMgr: public hkpDynamicsContactMgr
{
	public:
		hkUint16					m_skipNextNprocessCallbacks;
		hkpSimpleContactConstraintData	m_contactConstraintData;
		hkpConstraintInstance			m_constraint;
		hkUint32					m_pad[4];
};
enum hkpContactPointAccept
{
	HK_CONTACT_POINT_ACCEPT = 0,
	HK_CONTACT_POINT_REJECT = 1
};
struct hkpToiPointAddedEvent;
struct hkpManifoldPointAddedEvent;
struct hkpContactPointAddedEvent
{
	const hkpCdBody* m_bodyA;
	const hkpCdBody* m_bodyB;
	enum Type { TYPE_TOI, TYPE_MANIFOLD };
	const hkEnum<Type, hkInt32> m_type;
	hkpEntity* m_callbackFiredFrom;
	const hkContactPoint* m_contactPoint;
	inline hkpToiPointAddedEvent& asToiEvent();
	inline hkpManifoldPointAddedEvent& asManifoldEvent();
	hkpDynamicsContactMgr* m_internalContactMgr;
	const struct hkpProcessCollisionInput* m_collisionInput;
	struct hkpProcessCollisionOutput* m_collisionOutput;
	inline hkpContactPointAddedEvent(	hkpDynamicsContactMgr* contactMgr,
										const hkpProcessCollisionInput* m_collisionInput,
										hkpProcessCollisionOutput* m_collisionOutput,
										const hkpCdBody* a,    const hkpCdBody* b,
										hkContactPoint* cp,   const hkpGskCache* gskCache, hkpContactPointProperties* cpp,
										hkReal projectedVelocity, Type pointType );
};
struct hkpContactPointConfirmedEvent;
struct hkpContactPointRemovedEvent;
struct hkpContactProcessEvent
{
	const hkpContactProcessEvent& operator=(const hkpContactProcessEvent&);
	inline int getEntityIndex( const hkpEntity* entity ) const;
	inline const hkpSimpleContactConstraintAtom* getAtom() const;
	inline int getNumExtendedUserDatas(const hkpEntity* entity) const;
	inline void getExtendedUserDatas(int contactPointIndex, const hkpEntity* entity, hkpContactPointProperties::UserData* datasOut, int numDatas) const;
	inline void setExtendedUserDatas(int contactPointIndex, const hkpEntity* entity, hkpContactPointProperties::UserData* datasIn, int numDatas) const;
	inline void getToiExtendedUserDatas(const hkpEntity* entity, hkpContactPointProperties::UserData* datasOut, int numDatas) const;
	inline void setToiExtendedUserDatas(const hkpEntity* entity, hkpContactPointProperties::UserData* datasIn, int numDatas) const;
	const hkpCollidable* m_collidableA;
	const hkpCollidable* m_collidableB;
	hkpEntity* m_callbackFiredFrom;
	hkpProcessCollisionData* m_collisionData;
	hkpContactPointProperties* m_contactPointProperties[ HK_MAX_CONTACT_POINT ];
	hkpDynamicsContactMgr* m_internalContactMgr;
	inline hkpContactProcessEvent( 	hkpDynamicsContactMgr* contactMgr,	const hkpCollidable* a,	const hkpCollidable* b,	hkpProcessCollisionData* cr);
};
class hkpCollisionListener
{
	public:
		virtual void contactPointAddedCallback(	hkpContactPointAddedEvent& event) = 0;
		virtual void contactPointConfirmedCallback( hkpContactPointConfirmedEvent& event) = 0;
		virtual void contactPointRemovedCallback( hkpContactPointRemovedEvent& event ) = 0;
		virtual void contactProcessCallback( hkpContactProcessEvent& event ) {}
		virtual ~hkpCollisionListener() {}
};
class hkpToiContactPointViewer
	: public hkpWorldViewerBase
	, public hkpCollisionListener
{
	public:
		virtual void init();
		static const char* getName() { return "Contact Points (TOI)"; }
		static hkProcess* __cdecl create(const hkArray<hkProcessContext*>& contexts);
		static void __cdecl registerViewer();
		int getProcessTag(void);
		virtual void contactPointAddedCallback(hkpContactPointAddedEvent& event){}
		virtual void contactPointConfirmedCallback(hkpContactPointConfirmedEvent& event){}
		virtual void contactPointRemovedCallback(hkpContactPointRemovedEvent& event){}
		virtual void contactProcessCallback(hkpContactProcessEvent& event);
	protected:
		hkpToiContactPointViewer(const hkArray<hkProcessContext*>& contexts);
		virtual ~hkpToiContactPointViewer();
		virtual void worldAddedCallback  ( hkpWorld* world );
		virtual void worldRemovedCallback( hkpWorld* world );
		static int s_tag;
};
// pdb: hkToiContactPointViewer_displayArrow | hkpToiContactPointViewer.obj | fnv360_0822_retail, ustr, medium
static void FUN_009f4cb0( hkDebugDisplayHandler* handler, const hkVector4& from, const hkVector4& dir, int color, int tag )
{
	if ( dir.lengthSquared3() > 1.192092896e-07F )
	{
		{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "T" "t" "ToiDisplayArrow"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
		hkVector4 to; to.setAdd4( from, dir );
		hkVector4 ort; hkVector4Util::calculatePerpendicularVector( dir, ort );
		ort.normalize3();
		hkVector4 ort2; ort2.setCross( dir, ort );
		ort.mul4( dir.length3() );
		const hkReal c = 0.85f;
		hkVector4 p; p.setInterpolate4( from, to, c );
		hkVector4 p0; p0.setAddMul4( p, ort, 1.0f - c );
		hkVector4 p1; p1.setAddMul4( p, ort, -(1.0f - c) );
		handler->displayLine( from, to, color, tag );
		handler->displayLine( to, p0, color, tag );
		handler->displayLine( to, p1, color, tag );
		{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	}
}
void hkpToiContactPointViewer::contactProcessCallback( hkpContactProcessEvent& event )
{
	if ( event.m_collisionData->hasToi() )
	{
		hkContactPoint& contact = event.m_collisionData->getToiContactPoint();
		FUN_009f4cb0( m_displayHandler, contact.getPosition(), contact.getNormal(), hkColor::RED, s_tag );
	}
}

}  // namespace f3m_009f4cb0

// @f3 0x009f9d90 (community match, verified in this file)
namespace f3m_009f9d90 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct Shape { Vec4 vertices[4]; };
struct Info { unsigned char unk00, unk01, index, unk03; float u, v; };
struct Query {
    Vec4 a, b, c;
    float u, v;
};
struct Out;
struct Ctx;
void __cdecl FUN_00a4f7f0(const Query* query, Ctx* ctx, Out* out);
// pdb: buildJacobianFromLinSoftAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) void FUN_009f9d90(const Info* info, Ctx* ctx, Out* out, Shape* shape, Shape* other)
{
    Query q;
    q.a = other->vertices[3];
    q.b = shape->vertices[3];
    q.c = shape->vertices[info->index];
    q.u = info->u;
    q.v = info->v;
    FUN_00a4f7f0(&q, ctx, out);
}
extern Shape* volatile g_shape;
extern Shape* volatile g_other;
extern Info* volatile g_info;
extern Ctx* volatile g_ctx;
extern Out* volatile g_out;
void caller_of_FUN_009f9d90() { FUN_009f9d90(g_info, g_ctx, g_out, g_shape, g_other); }
}

// @f3 0x009f8d90 (community match, verified in this file)
namespace f3m_009f8d90 {

typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned int hkUint32;

const hkReal HK_REAL_EPSILON = 1.192092896e-07f;

extern hkReal hkTransformIdentity[];

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }
private:
    TYPE m_storage;
};

class hkMatrix3;
class hkRotation;

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0) { x = a; y = b; z = c; w = d; }
    __forceinline void add4(const hkVector4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1) { x = v0.x + v1.x; y = v0.y + v1.y; z = v0.z + v1.z; w = v0.w + v1.w; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1) { x = v0.x - v1.x; y = v0.y - v1.y; z = v0.z - v1.z; w = v0.w - v1.w; }
    __forceinline void mul4(const hkVector4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkReal horizontalAdd4() const { return x + y + z + w; }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v);
};

class hkMatrix3
{
public:
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

class hkRotation : public hkMatrix3 {};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}
__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v) { _setMul3(r, v); }

class hkTransform
{
public:
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    __forceinline static const hkTransform& getIdentity() { return reinterpret_cast<const hkTransform&>(hkTransformIdentity); }
    hkRotation m_rotation;
    hkVector4 m_translation;
};

class hkpVelocityAccumulator
{
public:
    hkUint8 m_type;
    bool m_matrixIsIdentity;
    hkUint32 m_deactivationClass;
    hkVector4 m_linearVel;
    hkVector4 m_angularVel;
    hkVector4 m_invMasses;
    __forceinline const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
    __forceinline const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
    hkVector4 m_scratch0;
    hkVector4 m_scratch1;
    hkVector4 m_scratch2;
    hkVector4 m_scratch3;
};

class hkpConstraintQueryIn
{
public:
    hkPadSpu<hkReal> m_substepDeltaTime;
    hkPadSpu<hkReal> m_microStepDeltaTime;
    hkPadSpu<hkReal> m_substepInvDeltaTime;
    hkPadSpu<hkReal> m_frameDeltaTime;
    hkPadSpu<hkReal> m_frameInvDeltaTime;
    hkPadSpu<hkReal> m_invNumSteps;
    hkPadSpu<hkReal> m_invNumStepsTimesMicroSteps;
    hkPadSpu<hkReal> m_rhsFactor;
    hkPadSpu<hkReal> m_virtMassFactor;
    hkPadSpu<hkReal> m_frictionRhsFactor;
    int m_pad28;
    int m_pad2c;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyB;
};

class hkp1Lin2AngJacobian
{
public:
    hkVector4 m_linear0;
    hkVector4 m_angular[2];

    __forceinline hkReal getDiag(const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB) const
    {
        hkVector4 ang0; ang0.setMul4(m_angular[0], m_angular[0]);
        hkVector4 ang1; ang1.setMul4(m_angular[1], m_angular[1]);
        ang0.mul4(mA.m_invMasses);
        ang1.mul4(mB.m_invMasses);
        ang0.add4(ang1);
        hkVector4 lin; lin.setAdd4(mB.m_invMasses, mA.m_invMasses);
        ang0(3) = lin(3);
        hkReal x = ang0.horizontalAdd4();
        return x;
    }
};


__forceinline void setRotatedDirF(hkVector4& o, const hkRotation& r, const hkVector4& v) { o._setRotatedDir(r, v); }
static __forceinline hkReal dotF(const hkVector4& a, const hkVector4& b) { return a.dot3(b); }

static __forceinline void hk1dLinearBilateralBuildJacobian(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& dir,
    const hkpConstraintQueryIn& in, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, hkp1Lin2AngJacobian& jac)
{
    const hkReal virtMassFactor = in.m_virtMassFactor;
    const hkReal rhsFactor = in.m_rhsFactor;
    jac.m_linear0 = dir;
    hkVector4 rA; rA.setSub4(pivotA, mA.getCenterOfMassInWorld());
    hkVector4 rB; rB.setSub4(pivotB, mB.getCenterOfMassInWorld());
    hkVector4 c0; c0.setCross(rA, dir);
    if (mA.m_matrixIsIdentity) { jac.m_angular[0] = c0; }
    else { setRotatedDirF(jac.m_angular[0], mA.getCoreFromWorldMatrix(), c0); }
    hkVector4 c1; c1.setCross(dir, rB);
    if (mB.m_matrixIsIdentity) { jac.m_angular[1] = c1; }
    else { setRotatedDirF(jac.m_angular[1], mB.getCoreFromWorldMatrix(), c1); }
    hkReal diag = jac.getDiag(mA, mB) + HK_REAL_EPSILON;
    jac.m_angular[1](3) = diag;
    jac.m_angular[0](3) = virtMassFactor / diag;
    hkVector4 diff; diff.setSub4(pivotB, pivotA);
    hkReal rhs = dotF(diff, dir);
    jac.m_linear0(3) = rhs * rhsFactor;
}

// pdb: hkBallSocketConstraintBuildJacobian_noSchema | hkpBuildJacobianFromAtoms.obj | fnv360_0721_beta, objrun, medium
// pdb params: posA, posB, in, jac
extern "C" void __cdecl FUN_009f8d90(const hkVector4& posA, const hkVector4& posB, const hkpConstraintQueryIn& in, hkp1Lin2AngJacobian* jac)
{
    const hkpVelocityAccumulator* mA = in.m_bodyA;
    const hkpVelocityAccumulator* mB = in.m_bodyB;
    const hkVector4* dir = &hkTransform::getIdentity().getColumn(0);
    hkp1Lin2AngJacobian* j = jac;
    for (int i = 0; i < 3; i++)
    {
        hk1dLinearBilateralBuildJacobian(posA, posB, *dir, in, *mA, *mB, *j);
        dir++;
        j++;
    }
}

}

// @f3 0x009f0690 (community match, verified in this file)
namespace f3m_009f0690 {

typedef float hkReal;
typedef unsigned long hkUlong;

__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

extern const char DAT_00e80b00[];
extern unsigned int DAT_011697ec;

struct TimerCommand {
    const char* m_commandAndMonitor;
    unsigned int m_time0;
    int m_time1;
};

struct hkMonitorStream {
    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(FUN_00d9b080(DAT_0116913c)); }
    __forceinline bool memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline char* getEnd() { return m_end; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }
};

// The library's timer entry: the name, then the clock, then the stream's end moves on.
__forceinline void TimerA(const char* name)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(FUN_00d9b080(DAT_0116913c));
    char* end = stream->m_end;
    if (end < stream->m_capacityMinus16) {
        TimerCommand* cmd = reinterpret_cast<TimerCommand*>(end);
        cmd->m_commandAndMonitor = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        cmd->m_time0 = ticks;
        stream->m_end = end + 0xc;
    }
}

// The same entry written through the stream's accessors.
__forceinline void TimerB(const char* name)
{
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if (mStream.memoryAvailable()) {
        TimerCommand* h = reinterpret_cast<TimerCommand*>(mStream.getEnd());
        h->m_commandAndMonitor = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->m_time0 = ticks;
        mStream.setEnd(reinterpret_cast<char*>(h + 1));
    }
}

__forceinline void TimerC(const char* name)
{
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if (mStream.memoryAvailable()) {
        unsigned int ticks;
        TimerCommand* h = reinterpret_cast<TimerCommand*>(mStream.getEnd());
        h->m_commandAndMonitor = name;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->m_time0 = ticks;
        mStream.setEnd(mStream.getEnd() + 0xc);
    }
}

struct hkMatrix3;

struct __declspec(align(16)) hkVector4 {
    hkReal x, y, z, w;

    hkReal& operator()(int i) { return (&x)[i]; }
    const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
    }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkMatrix3& r, const hkVector4& v) { _setMul3(r, v); }
};

struct hkQuaternion {
    hkVector4 m_vec;
};

struct hkMatrix3 {
    hkVector4 m_col0, m_col1, m_col2;

    hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    hkReal& operator()(int r, int c) { return getColumn(c)(r); }
    const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }

    void hkRotation_set(const hkQuaternion& q);
};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0); hkReal v1 = v(1); hkReal v2 = v(2);

    x = r(0,0) * v0 + r(0,1) * v1 + r(0,2) * v2;
    y = r(1,0) * v0 + r(1,1) * v1 + r(1,2) * v2;
    z = r(2,0) * v0 + r(2,1) * v1 + r(2,2) * v2;
    w = 0;
}

struct hkTransform {
    hkMatrix3 m_rotation;
    hkVector4 m_translation;

    hkMatrix3& getRotation() { return m_rotation; }
    hkVector4& getTranslation() { return m_translation; }
    void setRotation(const hkQuaternion& q) { m_rotation.hkRotation_set(q); }
};

struct hkSweptTransform {
    hkVector4 m_centerOfMass0;
    hkVector4 m_centerOfMass1;
    hkQuaternion m_rotation0;
    hkQuaternion m_rotation1;
    hkVector4 m_centerOfMassLocal;
};

struct hkSweptTransformUtil {
    static __forceinline void calcTransAtT0(const hkSweptTransform& sweptTrans, hkTransform& transformOut)
    {
        const hkQuaternion& q = sweptTrans.m_rotation0;
        transformOut.setRotation(q);
        hkVector4 centerShift;
        centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
        transformOut.getTranslation().setSub4(sweptTrans.m_centerOfMass0, centerShift);
    }
    static __forceinline void calcTransAtT1(const hkSweptTransform& sweptTrans, hkTransform& transformOut)
    {
        const hkQuaternion& q = sweptTrans.m_rotation1;
        transformOut.setRotation(q);
        hkVector4 centerShift;
        centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
        transformOut.getTranslation().setSub4(sweptTrans.m_centerOfMass1, centerShift);
    }
};

struct hkpCollidable {
    unsigned int unk00;
};

struct hkpEntity {
    unsigned int unk00, unk04, unk08, unk0c;
    hkpCollidable m_collidable;
    unsigned int unk14, unk18, unk1c, unk20;
    unsigned int unk24, unk28, unk2c, unk30;
    unsigned int unk34, unk38, unk3c, unk40;
    unsigned int unk44, unk48, unk4c, unk50;
    unsigned int unk54, unk58, unk5c, unk60;
    unsigned int unk64, unk68, unk6c, unk70;
    unsigned int unk74, unk78, unk7c, unk80;
    unsigned int unk84, unk88, unk8c, unk90;
    unsigned int unk94, unk98, unk9c, unka0;
    unsigned int unka4, unka8, unkac, unkb0;
    unsigned int unkb4, unkb8, unkbc, unkc0;
    unsigned int unkc4, unkc8, unkcc, unkd0;
    unsigned int unkd4, unkd8, unkdc, unke0;
    unsigned int unke4, unke8, unkec, unkf0;
    unsigned int unkf4, unkf8, unkfc, unk100;
    unsigned int unk104, unk108, unk10c, unk110;
    unsigned int unk114, unk118, unk11c;
    hkSweptTransform m_sweptTransform;

    const hkpCollidable* getCollidable() const { return &m_collidable; }
    const hkSweptTransform& getSweptTransform() const { return m_sweptTransform; }
};

template <typename T>
struct hkArray {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    int getSize() const { return m_size; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
};

struct hkpSimulationIsland {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44;
    hkArray<hkpEntity*> m_entities;

    const hkArray<hkpEntity*>& getEntities() const { return m_entities; }
};

struct hkpWorld {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24;
    hkArray<hkpSimulationIsland*> m_activeSimulationIslands;

    const hkArray<hkpSimulationIsland*>& getActiveSimulationIslands() const { return m_activeSimulationIslands; }
};

struct hkDebugDisplayHandler {
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0c() = 0;
    virtual void updateGeometry(const hkTransform& transform, hkUlong id, int tag) = 0;
};

// The viewer's listener part: the function receives a pointer to it, and the display handler sits in the
// viewer 0x14 bytes before it.
struct ViewerPart {
    static int DAT_011697ec;

    hkDebugDisplayHandler* GetDisplay() const;
    void FUN_009f0690(hkpWorld* world);
};

struct Viewer {
    hkDebugDisplayHandler* m_displayHandler;
    unsigned int unk04, unk08, unk0c, unk10;
    ViewerPart part;
};

inline hkDebugDisplayHandler* ViewerPart::GetDisplay() const {
    const Viewer* owner = reinterpret_cast<const Viewer*>(
        reinterpret_cast<const char*>(this) - offsetof(Viewer, part));
    return owner->m_displayHandler;
}

// After each simulation step: show every active body's transform at the start and at the end of the step.
// pdb: hkpSweptTransformDisplayViewer::postSimulationCallback | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void ViewerPart::FUN_009f0690(hkpWorld* world)
{
    TimerA("TthkpSweptTransformDisplayViewer");

    const hkArray<hkpSimulationIsland*>& activeIslands = world->getActiveSimulationIslands();
    for (int i = 0; i < activeIslands.getSize(); i++) {
        const hkArray<hkpEntity*>& activeEntities = activeIslands[i]->getEntities();
        for (int j = 0; j < activeEntities.getSize(); j++) {
            hkpEntity* body = activeEntities[j];
            const hkSweptTransform& sweptTransform = body->getSweptTransform();
            {
                // start of the step: rotation0, and the centre of mass moved back by the rotated local centre
                hkTransform t;
                t.setRotation(sweptTransform.m_rotation0);
                hkVector4 centerShift;
                hkReal v0 = sweptTransform.m_centerOfMassLocal(0);
                hkReal v1 = sweptTransform.m_centerOfMassLocal(1);
                hkReal v2 = sweptTransform.m_centerOfMassLocal(2);
                centerShift.x = t.getRotation()(0,0) * v0 + t.getRotation()(0,1) * v1 + t.getRotation()(0,2) * v2;
                centerShift.y = t.getRotation()(1,0) * v0 + t.getRotation().m_col1.y * v1 + t.getRotation()(1,2) * v2;
                centerShift.z = t.getRotation()(2,0) * v0 + t.getRotation()(2,1) * v1 + t.getRotation()(2,2) * v2;
                centerShift.w = 0;
                t.getTranslation().setSub4(sweptTransform.m_centerOfMass0, centerShift);
                GetDisplay()->updateGeometry(t, hkUlong(body->getCollidable()) + 1, DAT_011697ec);
            }
            {
                // end of the step
                hkTransform t;
                hkSweptTransformUtil::calcTransAtT1(sweptTransform, t);
                GetDisplay()->updateGeometry(t, hkUlong(body->getCollidable()) + 2, DAT_011697ec);
            }
        }
    }

    TimerA("Et");
}

}

// @f3 0x009f83f0 (community match, verified in this file)
namespace f3m_009f83f0 {
namespace w9f83f0 {

struct __declspec(align(16)) V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
};

struct Rot {
    V4 c0, c1, c2;
    __forceinline float operator()(int r, int c) const { return (&(&c0)[c].x)[r]; }
};

__forceinline void setRotatedDir(V4& d, const V4& b, const Rot& a)
{
    const float v0 = b.x;
    const float v1 = b.y;
    const float v2 = b.z;
    d.x = a(0, 0) * v0 + a(0, 1) * v1 + a(0, 2) * v2;
    d.y = a(1, 0) * v0 + a(1, 1) * v1 + a(1, 2) * v2;
    d.z = a(2, 0) * v0 + a(2, 1) * v1 + a(2, 2) * v2;
    d.w = 0.0;
}

__forceinline void rotatePoints(const Rot& m, const V4* in, int n, V4* out)
{
    Rot t = m;
    int i = n - 1;
    do {
        setRotatedDir(out[i], in[i], t);
    } while (--i >= 0);
}

struct TwoRotHolder {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    Rot* m_rot0;
    Rot* m_rot1;
};

struct RotPairSrc {
    V4 unk00;
    V4 m_v[7];
};

struct QuadDst {
    V4 m_v[4];
};

}

// pdb: setLocalRotationsFromAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0721_beta, objopen_prop, low
static __declspec(noinline) void FUN_009f83f0(w9f83f0::RotPairSrc* src,
                                             w9f83f0::TwoRotHolder* holder,
                                             w9f83f0::QuadDst* dst0,
                                             w9f83f0::QuadDst* dst1)
{
    w9f83f0::rotatePoints(*holder->m_rot0, &src->m_v[0], 4, &dst0->m_v[0]);
    w9f83f0::rotatePoints(*holder->m_rot1, &src->m_v[3], 4, &dst1->m_v[0]);
}

volatile void* g_holder_9f83f0;
volatile void* g_src_9f83f0;
volatile void* g_dst0_9f83f0;
volatile void* g_dst1_9f83f0;

void Caller_009f83f0()
{
    FUN_009f83f0((w9f83f0::RotPairSrc*)g_src_9f83f0,
                 (w9f83f0::TwoRotHolder*)g_holder_9f83f0,
                 (w9f83f0::QuadDst*)g_dst0_9f83f0,
                 (w9f83f0::QuadDst*)g_dst1_9f83f0);
}
}   // namespace f3m_009f83f0

// @f3 0x009e2a20 (community match, verified in this file)
#include <math.h>
namespace f3m_009e2a20 {
// FLAGS: /MT /O2 /GS /EHsc /Gy

struct Vec4 {
    float x, y, z, w;
    __forceinline void Blend(const Vec4& a, const Vec4& b, float factor) {
        float blend = 1.0f - factor;
        x = blend * a.x + factor * b.x;
        y = blend * a.y + factor * b.y;
        z = blend * a.z + factor * b.z;
        w = blend * a.w + factor * b.w;
    }
    float Dot(const Vec4& o) const { return x * o.x + y * o.y + z * o.z + w; }
    float Dot3(const Vec4& o) const { return x * o.x + y * o.y + z * o.z; }
};

struct __declspec(align(16)) F3Out {
    float nx, ny, nz, d;    // 0x00
    float t;                // 0x10
    int   i14;              // 0x14
    int   i18;              // 0x18
    int   i1c;              // 0x1c
    int   i20;              // 0x20
    int   i24;              // 0x24
    int   i28;              // 0x28
    int   i2c;              // 0x2c
    int   i30;              // 0x30
    int   i34;              // 0x34
    int   i38;              // 0x38
    int   i3c;              // 0x3c
    int   i40;              // 0x40
    int   i44;              // 0x44
    int   i48;              // 0x48
    int   i4c;              // 0x4c
};

struct F3Arg {
    Vec4 v1;                // 0x00
    Vec4 v2;                // 0x10
    float u20, u24, u28, u2c;
    float r;                // 0x30
    float lim;              // 0x34
};

struct F3Vt {
    virtual void v0(void* a1, F3Out* o);
};

struct F3This {
    float u00, u04, u08, u0c;
    Vec4 n;                 // 0x10
    Vec4 c;                 // 0x20
    Vec4 e;                 // 0x30
    void hkpPlaneShape_castSphere(F3Arg* p, void* a1, F3Vt* a2);
};

// pdb: hkpPlaneShape::castSphere | hkpPlaneShape.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void F3This::hkpPlaneShape_castSphere(F3Arg* arg, void* a1, F3Vt* a2)
{
    const F3Arg& p = *arg;
    float r = p.r;
    float A = n.Dot(p.v1);
    float s0 = A - r;
    const Vec4& pl = n;
    float B = pl.Dot(p.v2);
    float s1 = B - r;
    if (s1 >= 0.0f) return;
    if (s0 - s1 < p.lim) return;
    float t = s0 <= 0.0f ? 0.0f : s0 / (s0 - s1);
    Vec4 out;
    out.Blend(p.v1, p.v2, t);
    out.x = out.x - c.x;
    out.y = out.y - c.y;
    out.z = out.z - c.z;
    out.w = out.w - c.w;
    out.x = fabsf(out.x);
    out.y = fabsf(out.y);
    out.z = fabsf(out.z);
    out.w = fabsf(out.w);
    int m = (out.x <= e.x ? 8 : 0) | (out.y <= e.y ? 4 : 0) | (out.z <= e.z ? 2 : 0) | (out.w <= e.w ? 1 : 0);
    if ((m & 0xe) != 0xe)
        return;
    F3Out o;
    o.t = t;
    o.i14 = -1;
    o.nx = n.x;
    o.i20 = -1;
    o.ny = n.y;
    o.nz = n.z;
    o.d = n.w;
    o.i40 = 0;
    a2->v0(a1, &o);
}
}   // namespace f3m_009e2a20

// @f3 0x009e52e0 (community match, verified in this file)
#include <math.h>
namespace f3m_009e52e0 {
// FLAGS: /MT /O2 /GS- /EHs-c- /Gy

namespace DirectionBasisF3
{
inline float Root(float value) { return sqrtf(value); }
inline float ReciprocalRoot(float value) { return 1.0f / Root(value); }
inline float Magnitude(float value) { return fabsf(value); }

struct __declspec(align(16)) Vector4
{
    float x, y, z, w;
    __forceinline Vector4() {}
    __forceinline float& At(int axis) { return (&x)[axis]; }
    __forceinline const float& At(int axis) const { return (&x)[axis]; }
    __forceinline void Difference(const Vector4& end, const Vector4& start)
    {
        x = end.x - start.x;
        y = end.y - start.y;
        z = end.z - start.z;
        w = end.w - start.w;
    }
    __forceinline void Scale(float factor)
    {
        float multiplier = factor;
        // Fake match: indexed access selects the target x87 operand order.
        At(0) *= multiplier;
        y *= multiplier;
        z *= multiplier;
        w *= multiplier;
    }
    __forceinline float InverseLength() const
    {
        float squared = x*x + y*y + z*z;
        return squared ? ReciprocalRoot(squared) : 0;
    }
    __forceinline void Normalize() { Scale(InverseLength()); }
    __forceinline void Zero() { x = y = z = w = 0; }
    __forceinline void Set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void Cross(const Vector4& a, const Vector4& b)
    {
        const float first = a.At(1)*b.At(2) - a.At(2)*b.At(1);
        const float second = a.At(2)*b.At(0) - a.At(0)*b.At(2);
        const float third = a.At(0)*b.At(1) - a.At(1)*b.At(0);
        Set(first, second, third, 0.0f);
    }
};

__forceinline void MakePerpendicular(const Vector4& direction, Vector4& result)
{
    int least = 0;
    int axisA = 1;
    int axisB = 2;
    float smallest = Magnitude(direction.At(0));
    float next = Magnitude(direction.At(1));
    float last = Magnitude(direction.At(2));
    if (next < smallest)
    {
        axisA = 0;
        least = 1;
        smallest = next;
    }
    if (last < smallest)
    {
        axisB = least;
        least = 2;
    }
    result.Zero();
    result.At(axisA) = direction.At(axisB);
    result.At(axisB) = -direction.At(axisA);
}

struct EndpointBasis
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int unk10, unk14, unk18, unk1C;
    Vector4 first, second, perpendicular, normal;
    void FUN_009e52e0();
};

// pdb: hkpCylinderShape::presetPerpendicularVector | hkpCylinderShape.obj | fnv360_0822_retail, objrun, medium
void EndpointBasis::FUN_009e52e0()
{
    Vector4 direction;
    direction.Difference(second, first);
    direction.Normalize();
    MakePerpendicular(direction, perpendicular);
    perpendicular.Normalize();
    normal.Cross(direction, perpendicular);
}
}
}   // namespace f3m_009e52e0

// @f3 0x009e6380 (community match, verified in this file)
// hkpCylinderShape_castRayImpl = Havok 5.5.0 hkpCylinderShape::castRayImpl (hkpCollide.lib, hkpCylinderShape.obj; the stock release
// object is byte-exact against the game). Ray against a cylinder with convex padding: side hit through the infinite
// line distance, else a hit on the end cap the ray starts beyond.
// Written from the Havok 5.5.0 SDK headers and inline bodies and the hybrid library object's debug records
// (hkpCylinderShape.cpp lines 407-619, locals and blocks); cut to one file by hktrim.py.
namespace f3m_009e6380 {
typedef float  hkReal;
typedef signed short	hkInt16;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
class hkClass;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
	private:
		TYPE m_storage;
};

		extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}

		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};

class hkBaseObject
{
	public:
		
		__forceinline virtual ~hkBaseObject() {}
};

class hkStatisticsCollector;

class hkReferencedObject : public hkBaseObject
{
	public:
		
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;

extern "C" {
        double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

class hkTransform;

class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}

inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

	inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}

	inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

	inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
	}

	inline hkSimdReal hkVector4::normalizeWithLength3()
	{
		hkReal len = this->length3();
		this->mul4( (1.0f)/len );
		return len;
	}

class hkMonitorStream
{
	public:
		static hkMonitorStream& getInstance()
		{
			extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
			return *hkMonitorStream__m_instance.getData();
		}
	public:
		__forceinline char* __cdecl getEnd() { return m_end.val(); }
		__forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); }
		__forceinline hkBool __cdecl memoryAvailable( )
		{
			return getEnd() < getCapacityMinus16();
		}
		__forceinline void __cdecl setEnd(char* ptr) {  m_end = ptr; }
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
	public:
		struct Command
		{
			const char* m_commandAndMonitor;
		};
		struct AddValueCommand : public hkMonitorStream::Command
		{
			float m_value;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			hkUint32	m_time0;
			hkUint32	m_time1;
			__forceinline void setTime();
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			const char* m_nameOfFirstSplit;
		};
};

void hkMonitorStream::TimerCommand::setTime()
{
		hkUint32 ticks;
		__asm {
			rdtsc
			mov dword ptr[ticks], eax
		}
		m_time0 = ticks;
}

class hkAabb
{
	public:
		
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

class hkSphere
{
	public:
		
	protected:
		hkVector4 m_pos;
};

class hkpCdVertex: public hkVector4
{
	public:
};

enum hkpShapeType
{
	HK_SHAPE_INVALID = 0,
	HK_SHAPE_CONVEX,
	HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX,
	HK_SHAPE_SPHERE,
	HK_SHAPE_CYLINDER,
	HK_SHAPE_TRIANGLE,
	HK_SHAPE_BOX,
	HK_SHAPE_CAPSULE,
	HK_SHAPE_CONVEX_VERTICES,
	HK_SHAPE_COLLECTION,
	HK_SHAPE_BV_TREE,
	HK_SHAPE_LIST,
	HK_SHAPE_MOPP,
	HK_SHAPE_CONVEX_TRANSLATE,
	HK_SHAPE_CONVEX_TRANSFORM,
	HK_SHAPE_SAMPLED_HEIGHT_FIELD,
	HK_SHAPE_EXTENDED_MESH,
	HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_MAX_ID_SPU = HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_PACKED_CONVEX_VERTICES,
	HK_SHAPE_MOPP_EMBEDDED,
	HK_SHAPE_CONVEX_PIECE,
	HK_SHAPE_MULTI_SPHERE,
	HK_SHAPE_CONVEX_LIST,
	HK_SHAPE_TRIANGLE_COLLECTION,
	HK_SHAPE_MULTI_RAY,
	HK_SHAPE_HEIGHT_FIELD,
	HK_SHAPE_SPHERE_REP,
	HK_SHAPE_BV,
	HK_SHAPE_PLANE,
	HK_SHAPE_TRANSFORM,
	HK_SHAPE_PHANTOM_CALLBACK,
	HK_SHAPE_USER0,
	HK_SHAPE_USER1,
	HK_SHAPE_USER2,
	HK_SHAPE_MAX_ID,
	HK_SHAPE_ALL = -1
};

struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;

class hkpShape : public hkReferencedObject
{
	public:
		
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			typedef void (__cdecl *GetSupportingVertexFunc)        (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int  (__cdecl *GetNumCollisionSpheresFunc)		(const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc)					(const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				hkPadSpu<GetSupportingVertexFunc>			m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc>				m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc>						m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc>		m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc>			m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc>						m_getAabbFunc;
				hkPadSpu<CastRayFunc>						m_castRay;
				hkPadSpu<GetChildShapeFunc>					m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc		m_convertVertexIdsToVertices;
				WeldContactPointFunc				m_weldContactPointFunc;
				GetCentreFunc						m_getCentreFunc;
				GetNumCollisionSpheresFunc			m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc				m_getCollisionSpheresFunc;
				GetAabbFunc							m_getAabbFunc;
				CastRayFunc							m_castRay;
				GetChildShapeFunc					m_getChildShapeFunc;
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
	public:
		hkUlong m_userData;
	public:
		hkEnum< hkpShapeType, hkUint32> m_type;
};

struct hkpShapeRayCastCollectorOutput
{
	hkVector4 m_normal;
	hkReal m_hitFraction;
	int m_extraInfo;
	int m_pad[2];
};

struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
	public:
		enum { MAX_HIERARCHY_DEPTH = 8 };
	public:
		__forceinline void setKey(hkpShapeKey key);
	public:
		hkpShapeKey m_shapeKeys[MAX_HIERARCHY_DEPTH];
	private:
		int m_shapeKeyIndex;
};

inline void hkpShapeRayCastOutput::setKey(hkpShapeKey key)
{
	m_shapeKeys[m_shapeKeyIndex] = key;
}

class hkpSphereRepShape : public hkpShape
{
	public:
		
	protected:
		virtual int getNumCollisionSpheresImpl(  )  const = 0;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const = 0;
};

class hkpConvexShape : public hkpSphereRepShape
{
	public:
		
		virtual void getFirstVertex(hkVector4& v) const = 0;
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const = 0;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const = 0;
		virtual int weldContactPointImpl(  hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
	protected:
		hkReal m_radius;
};

class hkpCylinderShape : public hkpConvexShape
{
	public:
		
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		inline const hkVector4* getVertices() const;
		__forceinline const hkVector4& getVertex(int i) const;
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool hkpCylinderShape_castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	protected:
		hkReal    m_cylRadius;
		hkReal m_cylBaseRadiusFactorForHeightFieldCollisions;
		hkVector4 m_vertexA;
		hkVector4 m_vertexB;
		hkVector4 m_perpendicular1;
		hkVector4 m_perpendicular2;
	public:
		enum VertexIdEncoding
		{
			VERTEX_ID_ENCODING_IS_BASE_A_SHIFT     = 7,
			VERTEX_ID_ENCODING_SIN_SIGN_SHIFT      = 6,
			VERTEX_ID_ENCODING_COS_SIGN_SHIFT      = 5,
			VERTEX_ID_ENCODING_IS_SIN_LESSER_SHIFT = 4,
			VERTEX_ID_ENCODING_VALUE_MASK          = 0x0f
		};
	private:
		static hkReal s_virtualTesselationParameter;
		static hkReal s_virtualTesselationParameterInv;
		static hkReal s_intRoundUpThreshold;
};

const hkVector4* hkpCylinderShape::getVertices() const
{
	return &m_vertexA;
}

const hkVector4& hkpCylinderShape::getVertex(int i) const
{
	return (getVertices())[i];
}

class hkpCapsuleShape : public hkpConvexShape
{
	public:
		
		enum RayHitType
		{
			HIT_CAP0,
			HIT_CAP1,
			HIT_BODY,
		};
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	public:
		static void __cdecl closestPointLineSeg( const hkVector4& A, const hkVector4& B, const hkVector4& B2, hkVector4& pt );
		static void __cdecl closestInfLineSegInfLineSeg( const hkVector4& A, const hkVector4& dA, const hkVector4& B, const hkVector4& dB, hkReal& distSquared, hkReal& t, hkReal &u, hkVector4& p, hkVector4& q );
	protected:
		hkVector4  m_vertexA;
		hkVector4  m_vertexB;
};

class hkpRayShapeCollectionFilter;

struct hkpShapeRayCastInput
{
	
	hkVector4 m_from;
	hkVector4 m_to;
	hkUint32 m_filterInfo;
	const hkpRayShapeCollectionFilter*	m_rayShapeCollectionFilter;
};

// pdb: hkpCylinderShape::castRayImpl | hkpCylinderShape.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
hkBool hkpCylinderShape::hkpCylinderShape_castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results ) const
{
	const hkpCylinderShape* thisObj = this;
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "T" "t" "rcCylinder"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	hkVector4 radiusAxis;
	radiusAxis.setCross( thisObj->m_perpendicular2, thisObj->m_perpendicular1 );
	radiusAxis.mul4( thisObj->m_radius );
	hkVector4 vertex0; vertex0.setAdd4( thisObj->getVertex(0), radiusAxis );
	hkVector4 vertex1; vertex1.setSub4( thisObj->getVertex(1), radiusAxis );
	hkReal cylTotalRadius = thisObj->m_radius + thisObj->m_cylRadius;
	{
		hkVector4 res;
		hkpCapsuleShape::closestPointLineSeg( input.m_from, vertex0, vertex1, res );
		hkVector4 join; join.setSub4( input.m_from, res );
		hkReal sToCylDist = join.length3();
		if ( sToCylDist < cylTotalRadius )
		{
			hkVector4 axis; axis.setSub4( vertex1, vertex0 );
			hkVector4 fromBottom; fromBottom.setSub4( input.m_from, vertex0 );
			hkReal dot1 = axis.dot3( fromBottom );
			if ( dot1 > 0.0f )
			{
				hkVector4 fromTop; fromTop.setSub4( input.m_from, vertex1 );
				hkReal dot2 = axis.dot3( fromTop );
				if ( dot2 < 0.0f )
				{
					goto returnFalse;
				}
			}
		}
		hkReal infInfDistSquared = 3.40282e+38f;
		hkReal t, u;
		hkVector4 p, q;
		hkVector4 dA; dA.setSub4( input.m_to, input.m_from );
		hkVector4 dB; dB.setSub4( vertex1, vertex0 );
		hkpCapsuleShape::closestInfLineSegInfLineSeg( input.m_from, dA, vertex0, dB, infInfDistSquared, t, u, p, q );
		if ( infInfDistSquared > cylTotalRadius * cylTotalRadius )
		{
			goto returnFalse;
		}
		hkVector4 axis;
		hkReal axisLength;
		hkReal ipT;
		{
			axis = dB;
			const hkReal axisLengthSqrd = axis.lengthSquared3();
			if ( axisLengthSqrd > 1.192092896e-07F )
			{
				axisLength = axis.normalizeWithLength3();
			}
			else
			{
				goto returnFalse;
			}
			hkVector4 dir = dA;
			hkReal component = dir.dot3( axis );
			hkVector4 flatDir; flatDir.setAddMul4( dir, axis, -component );
			hkReal d = hkMath::sqrt( cylTotalRadius * cylTotalRadius - infInfDistSquared );
			if ( flatDir.lengthSquared3() != 0.0f )
			{
				d *= flatDir.lengthInverse3();
				ipT = t - d;
			}
			else
			{
				ipT = -1.0f;
			}
		}
		if ( ipT >= results.m_hitFraction )
		{
			goto returnFalse;
		}
		hkReal pointAProj = vertex0.dot3( axis );
		hkVector4 intersectPt; intersectPt.setInterpolate4( input.m_from, input.m_to, ipT );
		const hkReal ptProj = intersectPt.dot3( axis );
		hkReal ptHeight = ptProj - pointAProj;
		if ( ipT >= 0.0f )
		{
			if ( ptHeight > 0.0f && ptHeight < axisLength )
			{
				hkVector4 projPtOnAxis; projPtOnAxis.setInterpolate4( vertex0, vertex1, ptHeight / axisLength );
				hkVector4 normal; normal.setSub4( intersectPt, projPtOnAxis );
				normal.normalize3();
				results.m_normal = normal;
				results.m_hitFraction = ipT;
				results.setKey( 0xffffffff );
				{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
				return true;
			}
		}
		{
			const hkReal fromPointProj = input.m_from.dot3( axis );
			hkReal axisSign;
			hkVector4 capCenter;
			if ( fromPointProj < pointAProj )
			{
				axisSign = -1.0f;
				capCenter = vertex0;
			}
			else if ( fromPointProj > pointAProj + axisLength )
			{
				axisSign = 1.0f;
				capCenter = vertex1;
			}
			else
			{
				goto returnFalse;
			}
			hkReal hitFract;
			{
				hkVector4 toCap; toCap.setSub4( capCenter, input.m_from );
				hitFract = toCap.dot3( axis ) * axisSign * -1.0f;
				if ( hitFract < 0.0f )
				{
					goto returnFalse;
				}
				hkReal div = axisSign * -1.0f * dA.dot3( axis );
				if ( hitFract >= div * results.m_hitFraction )
				{
					goto returnFalse;
				}
				hitFract /= div;
			}
			hkVector4 hitOnPlane; hitOnPlane.setInterpolate4( input.m_from, input.m_to, hitFract );
			hkReal dist2;
			{
				hkVector4 diff; diff.setSub4( hitOnPlane, capCenter );
				dist2 = diff.lengthSquared3();
			}
			if ( dist2 > cylTotalRadius * cylTotalRadius )
			{
				goto returnFalse;
			}
			results.m_normal.setMul4( axisSign, axis );
			results.m_hitFraction = hitFract;
			results.setKey( 0xffffffff );
			{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
			return true;
		}
	}
returnFalse:
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	return false;
}
}

// @f3 0x009f7d40 (community match, verified in this file)
namespace f3m_009f7d40 {
namespace f3m_009f7d40 {
namespace n9f7d40 {
struct __declspec(align(16)) Vector4 {
    float x, y, z, w;
    Vector4() {}
    Vector4(const Vector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    void operator=(const Vector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
};
struct Transform { Vector4 rotation[3]; Vector4 translation; };
struct Triangle { Vector4 v[3]; };
struct Key { unsigned char a, b, c; };
void __cdecl FUN_00a4ebf0(Triangle* t, int a, int b);
static void __declspec(noinline) FUN_009f7d40(const Transform& a, const Transform& b, const Key* key, int p2, int p3)
{
    Triangle t;
    t.v[0] = a.translation;
    t.v[1] = b.translation;
    t.v[2] = b.rotation[key->c];
    FUN_00a4ebf0(&t, p2, p3);
}
}
void Caller9f7d40(const n9f7d40::Transform& a, const n9f7d40::Transform& b, const n9f7d40::Key* k, int p2, int p3)
{
    n9f7d40::FUN_009f7d40(a, b, k, p2, p3);
}
}
}   // namespace f3m_009f7d40

// @f3 0x009e51f0 (community match, verified in this file)
namespace f3m_009e51f0 {
// 0x009e51f0 — target is a single `ret` (C3, 1 byte).
// pdb: assertRoundUpThreshold | hkpCylinderShape.obj | fnv360_0822_retail, objrun_open, low
void FUN_009e51f0() {}
}   // namespace f3m_009e51f0

// @f3 0x009f22d0 (community match, verified in this file)
namespace f3m_009f22d0 {
// 0x009f22d0 (10 B): mov al,[esp+4]; mov [ecx+0x61],al; ret 4
// thiscall setter: stores the one stack byte argument at this+0x61.
struct StandIn495
{
    unsigned char pad00[0x61];
    unsigned char unk61;
    void FUN_009f22d0(unsigned char value);
};

void StandIn495::FUN_009f22d0(unsigned char value)
{
    unk61 = value;
}
}   // namespace f3m_009f22d0

// @f3 0x009e9a70 (community match, verified in this file)
#include <math.h>
namespace f3m_009e9a70 {
// FLAGS: /MT /O2 /GS /EHsc /Gy

namespace n009e9a70 {
__forceinline float root(float v) { return sqrtf(v); }
__forceinline float inverseRoot(float v) { return 1.0f / root(v); }

struct __declspec(align(16)) Vec {
    float x, y, z, w;
    __forceinline void operator=(const Vec& other) {
        x = other.x; y = other.y; z = other.z; w = other.w;
    }
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline float dot3(const Vec& b) const { return x*b.x + y*b.y + z*b.z; }
    __forceinline float lengthSquared3() const { return dot3(*this); }
    __forceinline void mul4(float scale) {
        float s = scale;
        x *= s; y *= s; z *= s; w *= s;
    }
    __forceinline void normalize3() {
        float square = x*x + y*y + z*z;
        mul4(square ? inverseRoot(square) : 0.0f);
    }
    __forceinline void subtractScaled(float scale, const Vec& b) {
        x -= scale*b.x; y -= scale*b.y; z -= scale*b.z; w -= scale*b.w;
    }
    __forceinline void cross(const Vec& a, const Vec& b) {
        float a0 = a.y*b.z - a.z*b.y;
        float a1 = a.z*b.x - a.x*b.z;
        float a2 = a.x*b.y - a.y*b.x;
        x = a0; y = a1; z = a2; w = 0.0f;
    }
};

static __declspec(noinline) void FUN_009e93b0(const float* data, int count, int stride,
                                           Vec& size, const Vec* basis, Vec& center)
{
    Vec lo, hi;
    lo.x = lo.y = lo.z = lo.w = 1.3611280681974912e38f;
    hi.x = hi.y = hi.z = hi.w = -1.3611280681974912e38f;
    const float* next = data;
    for (int triangle = 0; triangle < count / 3; ++triangle) {
        for (int vertex = 0; vertex < 3; ++vertex) {
            Vec p;
            p.x = next[0]; p.y = next[1]; p.z = next[2]; p.w = 0.0f;
            next = (const float*)((const char*)next + stride);
            for (int axis = 0; axis < 3; ++axis) {
                float projection = basis[axis].dot3(p);
                if (projection < lo(axis)) lo(axis) = projection;
                if (projection > hi(axis)) hi(axis) = projection;
            }
        }
    }
    Vec middle;
    for (int k = 0; k < 4; ++k) {
        middle(k) = hi(k) + lo(k);
        size(k) = hi(k) - lo(k);
    }
    middle.mul4(0.5f);
    size.mul4(0.5f);
    for (int k = 0; k < 4; ++k) {
        center(k) = middle.x * basis[0](k);
        center(k) += middle.y * basis[1](k);
        center(k) += middle.z * basis[2](k);
    }
}

static __declspec(noinline) float FUN_009e97e0(const float* data, int count, int stride, const Vec* p)
{
    Vec axes[3];
    axes[0] = p[0];
    axes[1] = p[1];
    axes[0].normalize3();
    float projection = p[0].dot3(p[1]);
    axes[1].subtractScaled(projection, p[0]);
    axes[1].normalize3();
    axes[2].cross(p[0], p[1]);
    axes[2].normalize3();
    Vec center, size;
    FUN_009e93b0(data, count, stride, size, axes, center);
    return size.x * size.y * size.z;
}

// pdb: getVolumeGradient | hkGeometryUtility.obj | tesv_win, objrun_prop, low
static __declspec(noinline) void FUN_009e9a70(const float* data, int count, int stride, const Vec* p, float d, Vec* out)
{
    Vec t[3];
    t[0] = p[0];
    t[1] = p[1];
    float first = FUN_009e97e0(data, count, stride, p);
    float inv = 1.0f / d;
    for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 3; ++k) {
            t[j](k) = d + t[j](k);
            float volume = FUN_009e97e0(data, count, stride, t);
            out[j](k) = (volume - first) * inv;
            t[j](k) = p[j](k);
        }
        out[j].x = out[j].x * -1.0;
        out[j].y = out[j].y * -1.0;
        out[j].z = out[j].z * -1.0;
        out[j].w = out[j].w * -1.0;
    }
    float len = out[0].lengthSquared3() + out[1].lengthSquared3();
    if (len > 1.0f) {
        float scale = inverseRoot(len);
        out[0].mul4(scale);
        out[1].mul4(scale);
    }
}

// Fake match: this caller keeps the static function emitted with its private convention.
volatile int input;
void caller() {
    FUN_009e9a70((const float*)input, input, input, (const Vec*)input, (float)input, (Vec*)input);
}
}
}   // namespace f3m_009e9a70

// @f3 0x009f9580 (community match, verified in this file)
namespace f3m_009f9580 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace f3m_009f9580 {
struct Rotation;
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void rotate(const Rotation& b, const Vec4& v);
    __forceinline void operator=(const Vec4& v) { x=v.x; y=v.y; z=v.z; w=v.w; }
    __forceinline void negate(const Vec4& v) { x=-v.x; y=-v.y; z=-v.z; w=-v.w; }
    __forceinline void product(const Vec4& a, const Vec4& b) { x=a.x*b.x; y=a.y*b.y; z=a.z*b.z; w=a.w*b.w; }
    __forceinline void multiply(const Vec4& a) { x*=a.x; y*=a.y; z*=a.z; w*=a.w; }
    __forceinline void add(const Vec4& a) { x+=a.x; y+=a.y; z+=a.z; w+=a.w; }
    __forceinline float sum3() const { return x+y+z; }
};
struct Rotation {
    Vec4 col0_00,col1_10,col2_20;
    __forceinline const Vec4& column(int i) const { return (&col0_00)[i]; }
    __forceinline const float& operator()(int r,int c) const { return column(c)(r); }
};
struct BodyInfo {
    unsigned char unk00, isFixed01, unk02, unk03;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    Vec4 invInertiaDiag30, unk40;
    Rotation rot50;
};
struct PairContext {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    const BodyInfo* bodyA;
    const BodyInfo* bodyB;
};
struct JacobianPair { Vec4 angA, angB; };
__forceinline void Vec4::rotate(const Rotation& b, const Vec4& v) {
    float vx=v(0), vy=v(1), vz=v(2);
    Vec4& dst=*this;
    dst(0)=b(0,0)*vx+b(0,1)*vy+b(0,2)*vz;
    dst(1)=b(1,0)*vx+b(1,1)*vy+b(1,2)*vz;
    dst(2)=b(2,0)*vx+b(2,1)*vy+b(2,2)*vz;
    dst(3)=0.0f;
}
__forceinline void build0(const Vec4& axis, const PairContext& ctx, JacobianPair& out, float& invOut) {
    const BodyInfo* a=ctx.bodyA;
    const BodyInfo* b=ctx.bodyB;
    if (a->isFixed01) out.angA=axis;
    else out.angA.rotate(a->rot50,axis);
    if (b->isFixed01) out.angB.negate(axis);
    else {
        Vec4 neg;
        neg.negate(axis);
        out.angB.rotate(b->rot50,neg);
    }
    Vec4 sqA, sqB;
    sqA.product(out.angA,out.angA);
    sqB.product(out.angB,out.angB);
    sqA.multiply(a->invInertiaDiag30);
    sqB.multiply(b->invInertiaDiag30);
    sqA.add(sqB);
    float total=sqA.sum3();
    total=(float)(total+1.1920928955078125e-07);
    float inv=1.0f/total;
    out.angA.w=inv;
    invOut=inv;
}
// Fake match: the inline forwarding layer selects the matching x87 operand order.
// pdb: hk1dAngularVelocityMotorBeginJacobian | hkpBuildJacobianFromAtoms.obj | fnv360_0721_beta, objrun, medium
// pdb params: directionOfConstraint, in, jac, statusOut
void __cdecl FUN_009f9580(const Vec4& axis, const PairContext& ctx, JacobianPair& out, float& invOut) { build0(axis,ctx,out,invOut); }
}
using f3m_009f9580::FUN_009f9580;
}   // namespace f3m_009f9580

// @f3 0x009e5f80 (community match, verified in this file)
#include <math.h>
namespace f3m_009e5f80 {

// 0x009e5f80: the box around a cylinder (hkpCylinderShape::getAabb in Havok terms): the box of the two end points,
// widened along each world axis by the cylinder radius times the sine of the angle between the cylinder axis and
// that world axis, plus the tolerance and the convex radius.

namespace f3m_009e5f80 {

typedef float hkReal;
typedef hkReal hkSimdRealParameter;      // a scalar argument of the vector functions

inline hkReal hkSqrt(hkReal r) { return sqrtf(r); }
inline hkReal hkSqrtInverse(hkReal r) { return 1.0f / hkSqrt(r); }

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    // this = t * b, as a point
    __forceinline void _setTransformedPos(const struct hkTransform& t, const hkVector4& b);
    __forceinline void setAll(hkSimdRealParameter a)
    {
        x = a;
        y = a;
        z = a;
        w = a;
    }
    __forceinline void add4(const hkVector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    __forceinline void sub4(const hkVector4& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        w -= a.w;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a(0) - b(0);
        y = a(1) - b(1);
        z = a(2) - b(2);
        w = a(3) - b(3);
    }
    __forceinline void mul4(hkSimdRealParameter s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }
    __forceinline void setMax4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x > b.x ? a.x : b.x;
        y = a.y > b.y ? a.y : b.y;
        z = a.z > b.z ? a.z : b.z;
        w = a.w > b.w ? a.w : b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    __forceinline hkReal lengthSquared3() const { return dot3(*this); }
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = lengthSquared3();
        return l2 ? hkSqrtInverse(l2) : 0;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    __forceinline void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int column) const { return getColumn(column)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.m_translation;
        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    const hkVector4& p = t.getTranslation();
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + p(0);
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + p(1);
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + p(2);
    w = 0;
}

// moves points by a transform (from a copy, so the output may overlap it)
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
};

class hkpCylinderShape
{
public:
    void FUN_009e5f80(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;

    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    void* m_vtable;
    int unk04;
    unsigned int m_userData;
    int m_type;
    hkReal m_radius;
    hkReal m_cylRadius;
    hkReal m_cylBaseRadiusFactorForHeightFieldCollisions;
    int unk1c;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_perpendicular1;
    hkVector4 m_perpendicular2;
};

// pdb: hkpCylinderShape::getAabbImpl | hkpCylinderShape.obj | tesv_win, objrun, medium
void hkpCylinderShape::FUN_009e5f80(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const
{
    // the two end points in world space
    hkVector4 obj[2];
    transformPoints(localToWorld, getVertices(), 2, obj);

    hkVector4 axis;
    axis.setSub4(obj[1], obj[0]);
    axis.normalize3();

    // the sine of the angle between the cylinder axis and each world axis (a little more than 1 keeps the root real)
    axis(0) = hkSqrt(1.01f - axis(0) * axis(0));
    axis(1) = hkSqrt(1.01f - axis(1) * axis(1));
    axis(2) = hkSqrt(1.01f - axis(2) * axis(2));

    // how far the rims reach along each world axis
    axis.mul4(m_cylRadius);

    hkVector4 tol4;
    tol4.setAll(m_radius + tolerance);
    tol4.add4(axis);

    out.m_min.setMin4(obj[0], obj[1]);
    out.m_min.sub4(tol4);

    out.m_max.setMax4(obj[0], obj[1]);
    out.m_max.add4(tol4);
}

}
}   // namespace f3m_009e5f80

// @f3 0x009e51c0 (community match, verified in this file)
namespace f3m_009e51c0 {
namespace f3m_009e51c0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009e51c0 { int unk00; unsigned short w; void FUN_009e4990(); O009e51c0* FUN_009e51c0(unsigned int flags); };
// pdb: hkpExtendedMeshShape::`scalar deleting destructor' | hkpExtendedMeshShape.obj | fnv360_0822_retail, vtable_prefix, high
O009e51c0* O009e51c0::FUN_009e51c0(unsigned int flags) { FUN_009e4990(); if (flags & 1) { f3m_009e51c0::T* t = (f3m_009e51c0::T*)f3m_009e51c0::DAT_00d9b080(f3m_009e51c0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_009e51c0

// @f3 0x009f22a0 (community match, verified in this file)
namespace f3m_009f22a0 {
extern int DAT_010f3170;
namespace n9f22a0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); };
}
struct O009f22a0 { char pad[4]; unsigned short w; void FUN_009f15d0(); O009f22a0* FUN_009f22a0(unsigned int flags); };
// pdb: hkpSimulationIslandViewer::`scalar deleting destructor' | hkpSimulationIslandViewer.obj | fnv360_0822_retail, vtable, medium
O009f22a0* O009f22a0::FUN_009f22a0(unsigned int flags) {
    FUN_009f15d0();
    if (flags & 1) {
        n9f22a0::T* t = (n9f22a0::T*)n9f22a0::TlsGetValue(*(unsigned long*)&DAT_010f3170);
        t->FUN_008f6d90(this, w, 0x35);
    }
    return this;
}
}

// @f3 0x009fc620 (community match, verified in this file)
namespace f3m_009fc620 {
// Earlier contributor's draft, unchanged (best_attempts of 2026-11-17). Not measurable in this claim: f3check
// stops with "Function entry absent from index: 0x009fc620". Their notes report an exact match under
// /MT,/O2,/GS,/EHsc,/Gy.
namespace w533_hk {
typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef const hkReal& hkSimdRealParameter;

class hkVector4
{
	public:
		inline void operator= (const hkVector4& v);
		inline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		inline void mul4(hkSimdRealParameter r);
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x; y = v.y; z = v.z; w = v.w;
}
inline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& a)
{
	x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w;
}
inline void hkVector4::mul4(hkSimdRealParameter r)
{
	x *= r; y *= r; z *= r; w *= r;
}

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};

class S009fc620_ConstraintInstance;

class S009fc620_VelocityAccumulator
{
	public:
		S009fc620_VelocityAccumulator(const S009fc620_VelocityAccumulator& other);
		int m_type;
		int unk04;
		int unk08;
		int unk0c;
		hkVector4 m_linearVel;
		hkVector4 m_angularVel;
		hkVector4 m_invMasses;
		hkVector4 m_scratch0;
		hkVector4 m_scratch1;
		hkVector4 m_scratch2;
		hkVector4 m_scratch3;
};

class S009fc620_QueryIn
{
	public:
		__declspec(align(16)) hkPadSpu<hkReal> m_substepDeltaTime;
		hkPadSpu<hkReal> m_microStepDeltaTime;
		hkPadSpu<hkReal> m_substepInvDeltaTime;
		hkPadSpu<hkReal> m_frameDeltaTime;
		hkPadSpu<hkReal> m_frameInvDeltaTime;
		hkPadSpu<hkReal> m_invNumSteps;
		hkPadSpu<hkReal> m_invNumStepsTimesMicroSteps;
		hkPadSpu<hkReal> m_rhsFactor;
		hkPadSpu<hkReal> m_virtMassFactor;
		hkPadSpu<hkReal> m_frictionRhsFactor;
		__declspec(align(16)) hkPadSpu<const S009fc620_VelocityAccumulator*> m_bodyA;
		hkPadSpu<const S009fc620_VelocityAccumulator*> m_bodyB;
		hkPadSpu<const void*> m_transformA;
		hkPadSpu<const void*> m_transformB;
		hkPadSpu<hkReal> m_tau;
		hkPadSpu<hkReal> m_damping;
		hkPadSpu<S009fc620_ConstraintInstance*> m_constraintInstance;
		hkPadSpu<void*> m_constraintRuntime;
		hkPadSpu<hkUint32> m_accumulatorAIndex;
		hkPadSpu<hkUint32> m_accumulatorBIndex;
		hkPadSpu<void*> m_constraintRuntimeInMainMemory;
};

class S009fc620_QueryOut
{
	public:
		hkPadSpu<char*> m_jacobianSchemas;
};

struct S009fc620_HeaderSchema
{
	union
	{
		hkReal m_check;
		struct
		{
			hkUint8 m_jacType;
			hkUint8 m_flags;
		};
	};
	hkUint16 m_bodyAIndex;
	hkUint16 m_bodyBIndex;
	int m_numSolverResults;
	S009fc620_ConstraintInstance* m_constraintInstance;
	inline void initHeader(S009fc620_ConstraintInstance* inst, hkUint32 a, hkUint32 b);
};

inline void S009fc620_HeaderSchema::initHeader(S009fc620_ConstraintInstance* inst, hkUint32 a, hkUint32 b)
{
	m_check += 1.1920928955078125e-07;
	m_jacType = 1;
	m_bodyAIndex = hkUint16(a);
	m_bodyBIndex = hkUint16(b);
	m_numSolverResults = 0;
	m_constraintInstance = inst;
	m_flags = 0;
}

struct S009fc620_Atom
{
	hkUint16 m_type;
};

struct S009fc620_MassChangerAtom
{
	hkUint16 m_type;
	hkUint16 unk02;
	int unk04;
	int unk08;
	int unk0c;
	hkUint16 m_modifierAtomSize;
	hkUint16 m_childSize;
	S009fc620_Atom* m_child;
	int unk18;
	int unk1c;
	hkReal m_factorA;
	hkReal m_factorB;
};

class hkBool
{
	public:
		hkBool(bool b) { m_bool = (char)b; }
		char m_bool;
};

void __cdecl FUN_00a4e360(const hkVector4& invMassA, const hkVector4& invMassB, S009fc620_QueryOut& out);
void __cdecl FUN_00a00ec0(const S009fc620_Atom* atom, const S009fc620_QueryIn& in, hkBool writeHeader, S009fc620_QueryOut& out);
void __cdecl FUN_009fccc0(const S009fc620_Atom* atoms, int sizeOfAllAtoms, const S009fc620_QueryIn& in, S009fc620_QueryOut& out);
} // namespace w533_hk

using namespace w533_hk;

static __declspec(noinline) void FUN_009fc620(const S009fc620_MassChangerAtom* atom, const S009fc620_QueryIn& in, S009fc620_QueryOut& out)
{
	S009fc620_QueryIn newIn = in;
	hkReal factorA = atom->m_factorA;
	hkReal factorB = atom->m_factorB;
	S009fc620_Atom* child = atom->m_child;
	int childSize = atom->m_childSize;

	out.m_jacobianSchemas = out.m_jacobianSchemas - sizeof(S009fc620_HeaderSchema);
	{
		S009fc620_HeaderSchema* hs = reinterpret_cast<S009fc620_HeaderSchema*>(out.m_jacobianSchemas.val());
		hs->initHeader(newIn.m_constraintInstance, newIn.m_accumulatorAIndex, newIn.m_accumulatorBIndex);
		out.m_jacobianSchemas = reinterpret_cast<char*>(hs + 1);
	}

	hkVector4 origInvMassA = in.m_bodyA.val()->m_invMasses;
	hkVector4 origInvMassB = in.m_bodyB.val()->m_invMasses;

	S009fc620_VelocityAccumulator accA(*in.m_bodyA.val());
	S009fc620_VelocityAccumulator accB(*in.m_bodyB.val());
	newIn.m_bodyA = &accA;
	newIn.m_bodyB = &accB;

	hkVector4 newInvMassA; newInvMassA.setMul4(factorA, origInvMassA);
	hkVector4 newInvMassB; newInvMassB.setMul4(factorB, origInvMassB);
	accA.m_invMasses.mul4(factorA);
	accB.m_invMasses.mul4(factorB);

	FUN_00a4e360(newInvMassA, newInvMassB, out);

	if (child->m_type == 0x16)
	{
		hkBool writeHeader = true;
		FUN_00a00ec0(child, newIn, writeHeader, out);
	}
	else
	{
		FUN_009fccc0(child, childSize, newIn, out);
	}

	FUN_00a4e360(origInvMassA, origInvMassB, out);
}

volatile int g_S009fc620_in;
void S009fc620_caller(const S009fc620_QueryIn& in, S009fc620_QueryOut& out)
{
	FUN_009fc620((const S009fc620_MassChangerAtom*)g_S009fc620_in, in, out);
}
}   // namespace f3m_009fc620

// @f3 0x009fc3e0 (community match, verified in this file)
namespace f3m_009fc3e0 {
namespace f3m_009fc3e0 {
namespace n9fc3e0 {
typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu(TYPE e) : m_storage(e) {}
		__forceinline TYPE val() const { return m_storage; }
		__forceinline operator TYPE() const { return val(); }
	private:
		TYPE m_storage;
};

class QueryIn
{
	public:
		__declspec(align(16)) hkPadSpu<hkReal> m_substepDeltaTime;
		hkPadSpu<hkReal> m_microStepDeltaTime;
		hkPadSpu<hkReal> m_substepInvDeltaTime;
		hkPadSpu<hkReal> m_frameDeltaTime;
		hkPadSpu<hkReal> m_frameInvDeltaTime;
		hkPadSpu<hkReal> m_invNumSteps;
		hkPadSpu<hkReal> m_invNumStepsTimesMicroSteps;
		hkPadSpu<hkReal> m_rhsFactor;
		hkPadSpu<hkReal> m_virtMassFactor;
		hkPadSpu<hkReal> m_frictionRhsFactor;
		__declspec(align(16)) hkPadSpu<const void*> m_bodyA;
		hkPadSpu<const void*> m_bodyB;
		hkPadSpu<const void*> m_transformA;
		hkPadSpu<const void*> m_transformB;
		hkPadSpu<hkReal> m_tau;
		hkPadSpu<hkReal> m_damping;
		hkPadSpu<void*> m_constraintInstance;
		hkPadSpu<void*> m_constraintRuntime;
		hkPadSpu<hkUint32> m_accumulatorAIndex;
		hkPadSpu<hkUint32> m_accumulatorBIndex;
		hkPadSpu<void*> m_constraintRuntimeInMainMemory;
};

class QueryOut
{
	public:
		hkPadSpu<char*> m_jacobianSchemas;
};

struct Atom
{
	hkUint16 m_type;
};

struct ModifierAtom
{
	hkUint16 m_type;
	hkUint16 unk02;
	int unk04;
	int unk08;
	int unk0c;
	hkUint16 m_modifierAtomSize;
	hkUint16 m_childSize;
	ModifierAtom* m_child;
	int unk18;
	int unk1c;
	hkReal m_tau;
	hkReal m_maxAcceleration;
};

struct ContactPoint
{
	hkReal m_position[4];
	hkReal m_separatingNormal[3];
	hkReal m_distance;
};

struct ContactAtom
{
	hkUint16 m_type;
	hkUint16 unk02;
	hkUint16 m_numContactPoints;
	hkUint16 m_numReservedContactPoints;
	hkUint8 unk08;
	hkUint8 unk09;
	hkUint8 m_contactPointPropertiesStriding;
	hkUint8 unk0b;
	int unk0c[9];
	ContactPoint m_points[1];
};

struct ContactPointProperties
{
	hkReal unk00[4];
	hkReal m_maxImpulse;
};

class hkBool
{
	public:
		hkBool(bool b) { m_bool = (char)b; }
		char m_bool;
};

void __cdecl FUN_00a00ec0(const Atom* atom, const QueryIn& in, hkBool writeHeader, QueryOut& out);
void __cdecl FUN_009fccc0(const Atom* atoms, int sizeOfAllAtoms, const QueryIn& in, QueryOut& out);
}

using namespace n9fc3e0;

static __declspec(noinline) void FUN_009fc3e0(const ModifierAtom* atom, const QueryIn& in, QueryOut& out)
{
	out.m_jacobianSchemas = out.m_jacobianSchemas - 16;
	const hkReal tau = atom->m_tau;
	QueryIn newIn = in;
	newIn.m_virtMassFactor = in.m_virtMassFactor * tau;
	newIn.m_tau = in.m_tau * tau;
	newIn.m_damping = in.m_damping * tau;

	const ModifierAtom* a = atom->m_child;
	while (a->m_type >= 0x17)
		a = a->m_child;
	const ContactAtom* contact = reinterpret_cast<const ContactAtom*>(a);

	const int numPoints = contact->m_numContactPoints;
	ContactPointProperties* cpp = (ContactPointProperties*)((char*)contact + 0x30 + (contact->m_numReservedContactPoints << 5));
	const int striding = contact->m_contactPointPropertiesStriding;
	for (int i = 0; i < numPoints; i++)
	{
		const hkReal distance = contact->m_points[i].m_distance;
		const hkReal allowed = atom->m_maxAcceleration * in.m_microStepDeltaTime * in.m_substepDeltaTime / atom->m_tau;
		if (allowed + distance < cpp->m_maxImpulse)
			cpp->m_maxImpulse = allowed + distance;
		cpp = (ContactPointProperties*)((char*)cpp + striding);
	}

	const int childSize = atom->m_childSize;
	const Atom* child = reinterpret_cast<const Atom*>(atom->m_child);
	if (child->m_type == 0x16)
	{
		hkBool writeHeader = true;
		FUN_00a00ec0(child, newIn, writeHeader, out);
	}
	else
	{
		FUN_009fccc0(child, childSize, newIn, out);
	}
}

volatile int g_009fc3e0_atom;
void Caller009fc3e0(const QueryIn& in, QueryOut& out)
{
	FUN_009fc3e0((const ModifierAtom*)g_009fc3e0_atom, in, out);
}
}
}   // namespace f3m_009fc3e0

// @f3 0x009f7dc0 (community match, verified in this file)
namespace f3m_009f7dc0 {
// 0x009f7dc0: _hkBallSocketConstraintComputeStabilizedRhs of Havok 5.5.0 (hkpConstraintSolver,
// hkpBuildJacobianFromAtoms.cpp; compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-), a file-local (static) function: the
// right-hand side of a stabilized ball-and-socket constraint, the pivots' separation plus, over one time step, the
// difference of the velocities each body's angular velocity gives its pivot (lever arm from the center of mass,
// angular velocity taken from principal axis space to world space).
// The function takes the two pivots in ecx and eax and the result in esi, the bodies and the step on the stack:
// Visual C++ 2005 gives a static function whose address is never taken a register convention of its own when it sees
// every call to it in the same file, without whole-program optimization.
// THE CALLER IN THIS FILE IS A STAND-IN, not a function of the game: it exists only so that the compiler emits the
// static target (a static function with no call in its file is not emitted at all). The real caller is
// buildJacobianFromBallSocketAtom (0x009f9800), where the SDK's builds expand this function inline; in the SDK's
// release object and in the game the out-of-line copy is called by nothing.
// The classes are the SDK's (hkVector4.h with hkFpuVector4.inl, hkRotation.h, hkpVelocityAccumulator.h), cut down to
// what the function touches.
namespace f3m_009f7dc0 {

typedef float hkReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned char hkUint8;
typedef unsigned int hkUint32;

class hkRotation;

class hkVector4
{
  public:
    inline void set( hkReal a, hkReal b, hkReal c, hkReal d )
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    inline hkReal& operator() ( int i )
    {
        return ( &x )[i];
    }

    inline const hkReal& operator() ( int i ) const
    {
        return ( &x )[i];
    }

    inline void setSub4( const hkVector4& v0, const hkVector4& v1 )
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    inline void addMul4( hkSimdRealParameter rs, const hkVector4& a )
    {
        hkReal r = hkReal( rs );
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }

    inline void subMul4( hkSimdRealParameter rs, const hkVector4& a )
    {
        hkReal r = hkReal( rs );
        x -= r * a.x;
        y -= r * a.y;
        z -= r * a.z;
        w -= r * a.w;
    }

    inline void setCross( const hkVector4& v1, const hkVector4& v2 )
    {
        const hkReal nx = v1( 1 ) * v2( 2 ) - v1( 2 ) * v2( 1 );
        const hkReal ny = v1( 2 ) * v2( 0 ) - v1( 0 ) * v2( 2 );
        const hkReal nz = v1( 0 ) * v2( 1 ) - v1( 1 ) * v2( 0 );
        this->set( nx, ny, nz, 0.0f );
    }

    void setRotatedInverseDir( const hkRotation& r, const hkVector4& v );

    __declspec( align( 16 ) ) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

class hkRotation
{
  public:
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

class hkpVelocityAccumulator
{
  public:
    const hkVector4& getCenterOfMassInWorld() const
    {
        return m_scratch0;
    }

    const hkRotation& getCoreFromWorldMatrix() const
    {
        return reinterpret_cast<const hkRotation&>( m_scratch1 );
    }

    hkUint8 m_type;
    hkUint8 m_matrixIsIdentity;
    hkUint32 m_deactivationClass;
    hkVector4 m_linearVel;
    hkVector4 m_angularVel;
    hkVector4 m_invMasses;
    hkVector4 m_scratch0;
    hkVector4 m_scratch1;
    hkVector4 m_scratch2;
    hkVector4 m_scratch3;
};

static void FUN_009f7dc0( const hkpVelocityAccumulator* bodyA, const hkpVelocityAccumulator* bodyB, const hkVector4& pivotA, const hkVector4& pivotB, hkReal invDeltaTime, hkVector4& rhsOut )
{
    const hkReal deltaTime = 1.0f / invDeltaTime;

    rhsOut.setSub4( pivotB, pivotA );

    hkVector4 armA;
    armA.setSub4( pivotA, bodyA->getCenterOfMassInWorld() );
    hkVector4 armB;
    armB.setSub4( pivotB, bodyB->getCenterOfMassInWorld() );

    hkVector4 angVelA;
    angVelA.setRotatedInverseDir( bodyA->getCoreFromWorldMatrix(), bodyA->m_angularVel );
    hkVector4 angVelB;
    angVelB.setRotatedInverseDir( bodyB->getCoreFromWorldMatrix(), bodyB->m_angularVel );

    hkVector4 velA;
    velA.setCross( armA, angVelA );
    hkVector4 velB;
    velB.setCross( armB, angVelB );

    rhsOut.addMul4( deltaTime, velB );
    rhsOut.subMul4( deltaTime, velA );
}

// A STAND-IN caller, not a function of the game: it only makes the compiler emit the static FUN_009f7dc0 above (see the head).
void __cdecl standInCallerOfStabilizedRhs( const hkpVelocityAccumulator* bodyA, const hkpVelocityAccumulator* bodyB, const hkVector4& pivotA, const hkVector4& pivotB, hkReal invDeltaTime, hkVector4& rhsOut )
{
    FUN_009f7dc0( bodyA, bodyB, pivotA, pivotB, invDeltaTime, rhsOut );
}

}  // namespace f3m_009f7dc0
}   // namespace f3m_009f7dc0

// @f3 0x009fa7a0 (community match, verified in this file)
// buildJacobianFromAngMotorAtom — Havok 5.5.0 hkpConstraintSolver.lib / hkpBuildJacobianFromAtoms.obj
// Wrapped in namespace f3m_009fa7a0; the static function carries the pack symbol FUN_009fa7a0.
namespace f3m_009fa7a0 {
typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}

template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}

class hkBool
{
	public:
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};

typedef hkReal hkSimdReal;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;

extern "C"
{
	hkReal __cdecl FUN_00954db0( hkReal x, hkReal y );
}

class hkMatrix3;
class hkRotation;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
	__forceinline void operator= ( const hkVector4& v );
	__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
	__forceinline void add4(const hkVector4& a);
	__forceinline void mul4(const hkVector4& a);
	__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
	__forceinline void setCross( const hkVector4& a, const hkVector4& b );
	__forceinline void setNeg4(const hkVector4& v);
	__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
	__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
	__forceinline hkSimdReal dot3(const hkVector4& a) const;
	__forceinline hkSimdReal horizontalAdd3() const;
	__forceinline hkReal& operator() (int i);
	__forceinline const hkReal& operator() (int i) const;
private:
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};

class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
	__forceinline const hkVector4& getColumn(int i) const;
	__forceinline const hkReal& operator() (int row, int col) const;
protected:
	hkVector4 m_col0;
	hkVector4 m_col1;
	hkVector4 m_col2;
};

class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
};

class hkTransform
{
	public:
		                class MustEndWithSemiColon;
	__forceinline const hkVector4& getColumn(int i) const;
private:
	hkRotation m_rotation;
	hkVector4 m_translation;
};

inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}

inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

	inline void hkVector4::_setMul3( const hkMatrix3& r, const hkVector4& v )
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2;
		t(1) = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2;
		t(2) = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2;
		t(3) = 0;
	}

	inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
	}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::horizontalAdd3() const
{
	return x+y+z;
}

inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}

inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}

const hkVector4& hkTransform::getColumn(int x) const
{
	return m_rotation.getColumn(x);
}

struct hkp1dMotorSolverInfo
{
                    class MustEndWithSemiColon;
    hkReal				m_maxImpulsePerSubstep;
    hkReal				m_minImpulsePerSubstep;
    hkReal				m_velocity;
    hkReal				m_tau;
    hkReal				m_damping;
};

class hkpVelocityAccumulator;

class hkpConstraintQueryStepInfo
{
	public:
		                class MustEndWithSemiColon;
	__declspec(align(16)) hkPadSpu<float> m_substepDeltaTime;
	hkPadSpu<float>		m_microStepDeltaTime;
	hkPadSpu<float>		m_substepInvDeltaTime;
	hkPadSpu<float>		m_frameDeltaTime;
	hkPadSpu<float>		m_frameInvDeltaTime;
	hkPadSpu<float>		m_invNumSteps;
	hkPadSpu<float>		m_invNumStepsTimesMicroSteps;
	hkPadSpu<float>		m_rhsFactor;
	hkPadSpu<float>		m_virtMassFactor;
	hkPadSpu<float> m_frictionRhsFactor;
};

class hkpConstraintQueryIn: public hkpConstraintQueryStepInfo
{
	public:
		                class MustEndWithSemiColon;
	__declspec(align(16)) hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
	hkPadSpu<const hkpVelocityAccumulator*>	m_bodyB;
	hkPadSpu<const hkTransform*>	m_transformA;
	hkPadSpu<const hkTransform*>	m_transformB;
	hkPadSpu<hkReal> m_tau;
	hkPadSpu<hkReal> m_damping;
	hkPadSpu<class hkpConstraintInstance*>	m_constraintInstance;
	hkPadSpu<void*>	m_constraintRuntime;
	hkPadSpu<hkUint32> m_accumulatorAIndex;
	hkPadSpu<hkUint32> m_accumulatorBIndex;
	hkPadSpu<void*> m_constraintRuntimeInMainMemory;
};

class hkpJacobianSchema;

class  hkpConstraintQueryOut
{
	public:
		                class MustEndWithSemiColon;
	hkPadSpu<hkpJacobianSchema*> m_jacobianSchemas;
};

class hkpSolverResults
{
	public:
		                class MustEndWithSemiColon;
	inline hkpSolverResults();
	inline void init();
public:
	hkReal m_impulseApplied;
	hkReal m_internalSolverData;
};

inline void hkpSolverResults::init()
{
	m_impulseApplied = 0.0f;
	m_internalSolverData = 0.0f;
}

inline hkpSolverResults::hkpSolverResults()
{
	init();
}

struct hkpConstraintAtom
{
		                class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		enum AtomType
		{
			TYPE_INVALID = 0,
			TYPE_BRIDGE,
			TYPE_SET_LOCAL_TRANSFORMS,
			TYPE_SET_LOCAL_TRANSLATIONS,
			TYPE_SET_LOCAL_ROTATIONS,
			TYPE_BALL_SOCKET,
			TYPE_STIFF_SPRING,
			TYPE_LIN,
			TYPE_LIN_SOFT,
			TYPE_LIN_LIMIT,
			TYPE_LIN_FRICTION,
			TYPE_LIN_MOTOR,
			TYPE_2D_ANG,
			TYPE_ANG,
			TYPE_ANG_LIMIT,
			TYPE_TWIST_LIMIT,
			TYPE_CONE_LIMIT,
			TYPE_ANG_FRICTION,
			TYPE_ANG_MOTOR,
			TYPE_RAGDOLL_MOTOR,
			TYPE_PULLEY,
			TYPE_OVERWRITE_PIVOT,
			TYPE_CONTACT,
			TYPE_MODIFIER_SOFT_CONTACT,
			TYPE_MODIFIER_MASS_CHANGER,
			TYPE_MODIFIER_VISCOUS_SURFACE,
			TYPE_MODIFIER_MOVING_SURFACE,
			TYPE_MODIFIER_IGNORE_CONSTRAINT,
			TYPE_MAX
		};
		enum CallbackRequest
		{
			CALLBACK_REQUEST_NONE = 0,
			CALLBACK_REQUEST_NEW_CONTACT_POINT = 1,
			CALLBACK_REQUEST_SETUP_PPU_ONLY = 2,
			CALLBACK_REQUEST_SETUP_CALLBACK = 4
		};
	public:
		hkEnum<AtomType,hkUint16> m_type;
};

struct hkpAngMotorConstraintAtom : public hkpConstraintAtom
{
	                class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	__forceinline int numSolverResults() const    { return 1; }
	hkBool m_isEnabled;
	hkUint8 m_motorAxis;
	hkInt16 m_initializedOffset;
	hkInt16 m_previousTargetAngleOffset;
	hkInt16 m_correspondingAngLimitSolverResultOffset;
	hkReal m_targetAngle;
	class hkpConstraintMotor* m_motor;
};

class hkp1dBilateralConstraintStatus
{
	public:
		                class MustEndWithSemiColon;
	    hkPadSpu<hkReal>			m_virtualMass;
};

class hkp1dConstraintMotorInfo
{
	public:
		                class MustEndWithSemiColon;
	    hkPadSpu<hkReal>				m_targetPosition;
	    hkPadSpu<hkReal>				m_targetVelocity;
	    hkPadSpu<hkReal>				m_maxForce;
	    hkPadSpu<hkReal>				m_minForce;
	    hkPadSpu<hkReal>				m_tau;
	    hkPadSpu<hkReal>				m_damping;
};

class hkpConstraintMotorInput: public hkp1dBilateralConstraintStatus
{
	public:
		                class MustEndWithSemiColon;
	    hkPadSpu<const class hkpConstraintQueryStepInfo*> m_stepInfo;
	    class hkpSolverResults m_lastResults;
	    hkPadSpu<hkReal> m_deltaTarget;
	    hkPadSpu<hkReal> m_positionError;
};

class hkpConstraintMotorOutput: public hkp1dConstraintMotorInfo
{
	public:
		                class MustEndWithSemiColon;
};

extern "C"
{
	void __cdecl FUN_00a50540(const hkpConstraintMotor* someMotor, const hkpConstraintMotorInput* input, hkpConstraintMotorOutput* output);
}

class hkpVelocityAccumulator
{
	public:
		                class MustEndWithSemiColon;
	    enum hkpAccumulatorType
	    {
		    HK_RIGID_BODY,
		HK_KEYFRAMED_RIGID_BODY,
		HK_NO_GRAVITY_RIGID_BODY,
		HK_END
	};
	hkEnum<hkpAccumulatorType,hkUint8> m_type;
	hkBool m_matrixIsIdentity;
	hkUint32 m_deactivationClass;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel;
	hkVector4 m_invMasses;
	const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
public:
	hkVector4 m_scratch0;
	hkVector4 m_scratch1;
	hkVector4 m_scratch2;
	hkVector4 m_scratch3;
};

class hkpJacobianSchema
{
	public:
		enum SchemaType
		{
			SCHEMA_TYPE_END = 0,
			SCHEMA_TYPE_HEADER,
			SCHEMA_TYPE_GOTO,
			SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER,
			SCHEMA_TYPE_SIMPLE_BEGIN,
			SCHEMA_TYPE_1D_BILATERAL,
			SCHEMA_TYPE_1D_BILATERAL_USER_TAU,
			SCHEMA_TYPE_1D_LINEAR_LIMITS,
			SCHEMA_TYPE_1D_FRICTION,
			SCHEMA_TYPE_1D_LINEAR_MOTOR,
			SCHEMA_TYPE_1D_PULLEY,
			SCHEMA_TYPE_1D_ANGULAR,
			SCHEMA_TYPE_1D_ANGULAR_LIMITS,
			SCHEMA_TYPE_1D_ANGULAR_FRICTION,
			SCHEMA_TYPE_1D_ANGULAR_MOTOR
		};
		typedef hkEnum<SchemaType, hkInt8> JointSchemaType;
		static __forceinline void __cdecl setType( hkpJacobianSchema* schema, JointSchemaType type )
		{
			hkReal& first = *reinterpret_cast<hkReal*>( schema );
			first = first + 1.192092896e-07F;
			*reinterpret_cast<JointSchemaType*>( schema ) = type;
		}
};

class hkp2AngJacobian
{
	public:
		hkVector4 m_angular[2];
		inline hkReal getInvJacDiag() const { return m_angular[0](3); }
		inline void setInvJacDiag( hkReal v ) { m_angular[0](3) = v; }
		inline void setAngularRhs( hkReal v ) { m_angular[1](3) = v; }
		__forceinline hkReal getAngularDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
};

__forceinline hkReal hkp2AngJacobian::getAngularDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const
{
	const hkp2AngJacobian& jac = *this;
	hkVector4 ang0; ang0.setMul4( jac.m_angular[0], jac.m_angular[0] );
	hkVector4 ang1; ang1.setMul4( jac.m_angular[1], jac.m_angular[1] );
	ang0.mul4( mA.m_invMasses );
	ang1.mul4( mB.m_invMasses );
	ang0.add4( ang1 );
	const hkReal eps = 1.192092896e-07f;
	const hkReal dot = ang0.horizontalAdd3();
	return dot + eps;
}

class hkpJacobian1dAngularMotorSchema
{
	public:
		hkp2AngJacobian m_jac;
		hkp1dMotorSolverInfo m_motorSolverInfo;
		hkReal m_unknown34; hkReal m_unknown38; hkReal m_unknown3c;
		__forceinline hkp1dMotorSolverInfo& init1dAngularMotor( const hkp2AngJacobian& jac )
		{
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>(this), hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_MOTOR );
			return m_motorSolverInfo;
		}
};

class hkpJacobianShiftSolverResultsPointerSchema
{
	public:
		hkUint32 m_padding_1;
		hkUint8 m_numSolverResultsToSkip;
		hkUint32 m_unknown08; hkUint32 m_unknown0c;
		__forceinline void initShiftSolverResultsPointer( hkUint8 numSolverResultsToSkip )
		{
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>(this), hkpJacobianSchema::SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER );
			m_numSolverResultsToSkip = numSolverResultsToSkip;
		}
};

extern const hkUint8 DAT_00e817d9[]; extern const hkUint8 DAT_00e817da[]; extern const double FUN_00dc0760;

static __forceinline void __cdecl _hk1dAngularVelocityMotorCommitJacobian( hkp1dConstraintMotorInfo& info, const hkpConstraintQueryIn& in, hkp2AngJacobian& jac, hkpConstraintQueryOut& out )
{
	jac.setAngularRhs( info.m_targetPosition * in.m_substepInvDeltaTime );
	hkpJacobian1dAngularMotorSchema* schema = reinterpret_cast<hkpJacobian1dAngularMotorSchema*>( out.m_jacobianSchemas.val() );
	hkp1dMotorSolverInfo& motorInfo = schema->init1dAngularMotor( jac );
	motorInfo.m_maxImpulsePerSubstep = info.m_maxForce * in.m_microStepDeltaTime;
	motorInfo.m_minImpulsePerSubstep = info.m_minForce * in.m_microStepDeltaTime;
	motorInfo.m_velocity = info.m_targetVelocity;
	motorInfo.m_tau = info.m_tau;
	motorInfo.m_damping = info.m_damping;
	out.m_jacobianSchemas = reinterpret_cast<hkpJacobianSchema*>( schema + 1 );
}

static __forceinline void __cdecl hkSkipSolverResults( hkUint8 numSolverResultsToSkip, hkpConstraintQueryOut& out )
{
	hkpJacobianShiftSolverResultsPointerSchema* schema = reinterpret_cast<hkpJacobianShiftSolverResultsPointerSchema*>( out.m_jacobianSchemas.val() );
	schema->initShiftSolverResultsPointer( numSolverResultsToSkip );
	out.m_jacobianSchemas = reinterpret_cast<hkpJacobianSchema*>( schema + 1 );
}

static inline void __cdecl FUN_009fa7a0( const hkpAngMotorConstraintAtom& atom, const hkpConstraintQueryIn& in, const hkTransform& baseA, const hkTransform& baseB, hkpConstraintQueryOut& out )
{
	hkUint8& initialized = *static_cast<hkUint8*>( hkAddByteOffset( in.m_constraintRuntime.val(), atom.m_initializedOffset ) );
	hkReal& previousTargetAngle = *static_cast<hkReal*>( hkAddByteOffset( in.m_constraintRuntime.val(), atom.m_previousTargetAngleOffset ) );
	if ( atom.m_motor && atom.m_isEnabled )
	{
		hkpConstraintMotor* motor = atom.m_motor;
		hkReal computedAngle;
		{
			const int axis = atom.m_motorAxis;
			const hkVector4& perpA = *hkAddByteOffsetConst( &baseA.getColumn(0), DAT_00e817d9[atom.m_motorAxis] );
			const hkVector4& perpB = *hkAddByteOffsetConst( &baseB.getColumn(0), DAT_00e817da[atom.m_motorAxis] );
			hkReal sinx = perpA.dot3( perpB );
			const hkVector4& axisB = baseB.getColumn( axis );
			hkVector4 cosCheck; cosCheck.setCross( perpB, axisB );
			hkReal cosx = perpA.dot3( cosCheck );
			computedAngle = FUN_00954db0( sinx, cosx );
		}
		if ( atom.m_correspondingAngLimitSolverResultOffset )
		{
			hkReal lastAngle = -1.0f * static_cast<hkpSolverResults*>( hkAddByteOffset( in.m_constraintRuntime.val(), atom.m_correspondingAngLimitSolverResultOffset ) )->m_internalSolverData;
			while ( lastAngle - computedAngle > 3.14159265358979f )
			{
				computedAngle += FUN_00dc0760;
			}
			while ( computedAngle - lastAngle > 3.14159265358979f )
			{
				computedAngle -= FUN_00dc0760;
			}
		}
		if ( !initialized )
		{
			previousTargetAngle = computedAngle;
		}
		hkpConstraintMotorInput motorIn;
		hkp2AngJacobian& jac = *reinterpret_cast<hkp2AngJacobian*>( out.m_jacobianSchemas.val() );
			const hkVector4& direction = baseA.getColumn( atom.m_motorAxis );
			const hkpVelocityAccumulator* opaA = in.m_bodyA;
			const hkpVelocityAccumulator* opaB = in.m_bodyB;
			if ( opaA->m_matrixIsIdentity )
			{
				jac.m_angular[0] = direction;
			}
			else
			{
				const hkRotation& coreFromWorldA = opaA->getCoreFromWorldMatrix();
                jac.m_angular[0]._setRotatedDir( coreFromWorldA, direction );
			}
			if ( opaB->m_matrixIsIdentity )
			{
				jac.m_angular[1].setNeg4( direction );
			}
			else
			{
				hkVector4 negDir; negDir.setNeg4( direction );
				jac.m_angular[1]._setRotatedDir( opaB->getCoreFromWorldMatrix(), negDir );
			}
			hkReal diag = jac.getAngularDiag( *opaA, *opaB );
			jac.setInvJacDiag( 1.0f / diag );
			motorIn.m_virtualMass = jac.getInvJacDiag();
		motorIn.m_stepInfo = &in;
		motorIn.m_lastResults = *static_cast<hkpSolverResults*>( in.m_constraintRuntime.val() );
		motorIn.m_deltaTarget = atom.m_targetAngle - previousTargetAngle;
		motorIn.m_positionError = previousTargetAngle - computedAngle;
		hkpConstraintMotorOutput motorOut;
		FUN_00a50540( motor, &motorIn, &motorOut );
		_hk1dAngularVelocityMotorCommitJacobian( motorOut, in, jac, out );
		if ( previousTargetAngle != atom.m_targetAngle || !initialized )
		{
			previousTargetAngle = atom.m_targetAngle;
			initialized = true;
		}
	}
	else
	{
		hkSkipSolverResults( hkUint8( atom.numSolverResults() ), out );
	}
}

void __cdecl FUN_009fa7a0_caller( const hkpAngMotorConstraintAtom& atom, const hkpConstraintQueryIn& in, const hkTransform& baseA, const hkTransform& baseB, hkpConstraintQueryOut& out )
{
	FUN_009fa7a0( atom, in, baseA, baseB, out );
}

} // namespace f3m_009fa7a0
