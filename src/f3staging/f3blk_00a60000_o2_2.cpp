#include <math.h>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_00a60000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a6cc50 (community match, verified in this file)
namespace f3m_00a6cc50 {
// FUN_00a6cc50 -- chain constraint firing (Havok-style physics)

struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;

    hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    hkTransform() { }
    hkTransform(const hkTransform& t)
    {
        m_rotation = t.m_rotation;
        m_translation = t.m_translation;
    }
};

struct RigidBody
{
    char unk00[0xe0];
    hkTransform m_kMotionTransform;   // 0xe0
};

struct ConstraintData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int getType();            // vtable + 0x10
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_pConstraintInfo;          // 0x18
};

struct ChainInstance
{
    int unk00;
    int unk04;
    int unk08;
    ConstraintData* m_data;           // 0x0c
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    RigidBody** m_ppRigidBodies;      // 0x2c
    int m_iEntryCount;                // 0x30
};

struct Listener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Fire(void* pA, void* pB, unsigned int uiFlag, int iArg);   // vtable + 0x20
};

struct ConstraintAtom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00c7f640(hkTransform* pTransform, hkVector4* pPivot);
};

struct StiffSpringInfo
{
    hkVector4 m_kPivotInA;            // 0x00
    hkVector4 m_kPivotInB;            // 0x10
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct BallSocketInfo
{
    hkVector4 m_kPivotInA;            // 0x00
    hkVector4 m_kPivotInB;            // 0x10
};

struct PoweredInfo
{
    hkVector4 m_kPivotInA;            // 0x00
    hkVector4 m_kPivotInB;            // 0x10
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
};

struct F3Twin_00a8f460
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void F3_FUN_00a8f460(void* pListener);
};

struct ChainOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_posA;                 // 0x20
    hkVector4 m_posB;                 // 0x30
    ConstraintAtom m40;               // 0x40
    ConstraintAtom m50;               // 0x50
    hkRotation m_rotA;                // 0x60
    hkRotation m_rotB;                // 0x90
    F3Twin_00a8f460 m_c0;             // 0xc0

    void FUN_00a6cc50(ChainInstance* apChain, Listener* apListener, int aiArg);
    void FUN_00a6a750(int iArg);
    void FUN_00a6a7b0(int iArg);
};

// pdb: hkpHingeLimitsDrawer::drawConstraint | hkpHingeLimitsDrawer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: constraint, displayHandler, id, tag
void ChainOwner::FUN_00a6cc50(ChainInstance* apChain, Listener* apListener, int aiArg)
{
    ConstraintData* data = apChain->m_data;
    m_c0.F3_FUN_00a8f460(apListener);

    int iPairCount = apChain->m_iEntryCount - 1;
    for (int iPair = 0; iPair < iPairCount; iPair++)
    {
        RigidBody* pBodyA = apChain->m_ppRigidBodies[iPair];
        RigidBody* pBodyB = apChain->m_ppRigidBodies[iPair + 1];

        hkTransform transformB = pBodyB->m_kMotionTransform;
        hkTransform transformA = pBodyA->m_kMotionTransform;

        m_rotB = transformB.m_rotation;
        m_rotA = transformA.m_rotation;
        m_posB = transformB.m_translation;
        m_posA = transformA.m_translation;

        hkVector4 pivotB;
        hkVector4 pivotA;
        switch (data->getType())
        {
        case 100:
            pivotB = ((StiffSpringInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInB;
            pivotA = ((StiffSpringInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInA;
            break;
        case 101:
            pivotB = ((BallSocketInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInB;
            pivotA = ((BallSocketInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInA;
            break;
        case 102:
            pivotB = ((PoweredInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInB;
            pivotA = ((PoweredInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInA;
            break;
        }

        m50.FUN_00c7f640(&transformB, &pivotB);
        m40.FUN_00c7f640(&transformA, &pivotA);
        FUN_00a6a750(aiArg);
        FUN_00a6a7b0(aiArg);
        apListener->Fire(&m40, &m50, 0xffff0000, aiArg);
    }
}
}   // namespace f3m_00a6cc50

// @f3 0x00a6b600 (community match, verified in this file)
namespace f3m_00a6b600 {
extern void* __cdecl FUN_00901e90(void* array, unsigned int count, unsigned int size);

struct Obj_00a6b600 {
    unsigned char* unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct Cls_00a6b600 {
    void FUN_00a6b600(Obj_00a6b600* a1);
    void FUN_00a6b1f0(float* out);
};

struct V4_00a6b600 { float x, y, z, w; };

__declspec(noinline) void Cls_00a6b600::FUN_00a6b1f0(float* out)
{
    out[0] = 1.0f; out[1] = 0.0f; out[2] = 0.0f; out[3] = 0.0f;
    out[4] = 0.0f; out[5] = 1.0f; out[6] = 0.0f; out[7] = 0.0f;
    out[8] = 0.0f; out[9] = 0.0f; out[10] = 1.0f; out[11] = 0.0f;
    out[12] = 0.0f; out[13] = 0.0f; out[14] = 0.0f; out[15] = 1.0f;
}

// pdb: hkDisplayPlane::getWireframeGeometry | hkDisplayPlane.obj | fnv360_0822_retail, vtable, medium
// pdb params: lines, a
void Cls_00a6b600::FUN_00a6b600(Obj_00a6b600* a1)
{
    int count = a1->unk08 & 0x3fffffff;
    if (count < 12) {
        int want = count + count;
        if (want <= 12) want = 12;
        FUN_00901e90(a1, want, 0x10);
    }
    __declspec(align(16)) float m[16];
    a1->unk04 = 12;
    FUN_00a6b1f0(m);
    V4_00a6b600* d = (V4_00a6b600*)a1->unk00;
    d[0].x = m[0]; d[0].y = m[1]; d[0].z = m[2]; d[0].w = m[3];
    d = (V4_00a6b600*)a1->unk00 + 1;
    d[0].x = m[4]; d[0].y = m[5]; d[0].z = m[6]; d[0].w = m[7];
    d = (V4_00a6b600*)a1->unk00 + 2;
    d[0].x = m[4]; d[0].y = m[5]; d[0].z = m[6]; d[0].w = m[7];
    d = (V4_00a6b600*)a1->unk00 + 3;
    d[0].x = m[8]; d[0].y = m[9]; d[0].z = m[10]; d[0].w = m[11];
    d = (V4_00a6b600*)a1->unk00 + 4;
    d[0].x = m[8]; d[0].y = m[9]; d[0].z = m[10]; d[0].w = m[11];
    d = (V4_00a6b600*)a1->unk00 + 5;
    d[0].x = m[12]; d[0].y = m[13]; d[0].z = m[14]; d[0].w = m[15];
    d = (V4_00a6b600*)a1->unk00 + 6;
    d[0].x = m[12]; d[0].y = m[13]; d[0].z = m[14]; d[0].w = m[15];
    d = (V4_00a6b600*)a1->unk00 + 7;
    d[0].x = m[0]; d[0].y = m[1]; d[0].z = m[2]; d[0].w = m[3];
    d = (V4_00a6b600*)a1->unk00 + 8;
    d[0].x = m[0]; d[0].y = m[1]; d[0].z = m[2]; d[0].w = m[3];
    d = (V4_00a6b600*)a1->unk00 + 9;
    d[0].x = m[8]; d[0].y = m[9]; d[0].z = m[10]; d[0].w = m[11];
    d = (V4_00a6b600*)a1->unk00 + 10;
    d[0].x = m[4]; d[0].y = m[5]; d[0].z = m[6]; d[0].w = m[7];
    d = (V4_00a6b600*)a1->unk00 + 11;
    d[0].x = m[12]; d[0].y = m[13]; d[0].z = m[14]; d[0].w = m[15];
}
}   // namespace f3m_00a6b600


// @f3 0x00a710b0 (community match, verified in this file)
namespace f3m_00a710b0 {
struct Tail { void __thiscall hkRotation_set(int); };
struct Object {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    volatile float unk20; volatile float unk24; volatile float unk28; volatile float unk2C;
    volatile float unk30; volatile float unk34; volatile float unk38; volatile float unk3C;
    volatile float unk40; volatile float unk44; volatile float unk48; volatile float unk4C;
    Tail unk50;
    void __thiscall FUN_00a710b0(int arg);
};
void Object::FUN_00a710b0(int arg) {
    __declspec(align(16)) float zero = 0.0f;
    unk20 = zero; unk24 = 0.0f; unk28 = 0.0f; unk2C = 0.0f;
    unk30 = 0.0f; unk34 = 0.0f; unk38 = 0.0f; unk3C = 0.0f;
    unk40 = 0.0f; unk44 = 0.0f; unk48 = 0.0f; unk4C = 0.0f;
    unk20 = 1.0f; unk34 = 1.0f; unk48 = 1.0f;
    unk50.hkRotation_set(arg);
}
}   // namespace f3m_00a710b0

// @f3 0x00a740c0 (community match, verified in this file)
#include <windows.h>
extern int FUN_00e83cbc, FUN_00e83cb0, FUN_00e83c9c, FUN_00e83c90, FUN_00e83c84, FUN_00e83c6c;
extern int FUN_00dcc494, FUN_00e32018, FUN_00e32030, FUN_00e32044, FUN_00e32024, FUN_00dcd094;
extern unsigned int DAT_010f3170;
namespace f3m_00a740c0 {
struct ListenerArray740 {
    void** data;
    unsigned short size, capacity;
    int Find(void* p) { for (int i = 0; i < size; ++i) if (data[i] == p) return i; return -1; }
};
struct Actor740 { ListenerArray740* FUN_00a70a70(); void FUN_0090b960(void*); };
struct Slot740 { Actor740* a; ListenerArray740* get() { return a->FUN_00a70a70(); } };
struct Alloc740 { void FUN_008f6d90(void*, int, int); };
struct Shape740 {
    void *v0; int unk04; void *v8, *vc, *v10, *v14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    void* v30; Slot740* data; int size, capacity;
    void FUN_00a740c0();
};
// pdb: hkpDisableEntityCollisionFilter::~hkpDisableEntityCollisionFilter | hkpDisableEntityCollisionFilter.obj | fnv360_0822_retail, call_seq, high
void Shape740::FUN_00a740c0() {
    v0 = &FUN_00e83cbc; v8 = &FUN_00e83cb0; vc = &FUN_00e83c9c; v10 = &FUN_00e83c90; v14 = &FUN_00e83c84; v30 = &FUN_00e83c6c;
    for (int i = 0; i < size; ++i) {
        int offset = i * 4;
        if (((Slot740*)((char*)data + offset))->get()->Find(&v30) >= 0)
            ((Slot740*)((char*)data + offset))->a->FUN_0090b960(&v30);
    }
    if (!(capacity & 0x80000000)) {
        int n = capacity & 0x3fffffff;
        Alloc740* a = (Alloc740*)TlsGetValue(DAT_010f3170);
        a->FUN_008f6d90(data, n * 4, 0x17);
    }
    *(void* volatile*)&v30 = &FUN_00dcd094; *(void* volatile*)&v14 = &FUN_00e32024; *(void* volatile*)&v10 = &FUN_00e32044; *(void* volatile*)&vc = &FUN_00e32030; *(void* volatile*)&v8 = &FUN_00e32018; *(void* volatile*)&v0 = &FUN_00dcc494;
}
}   // namespace f3m_00a740c0

// @f3 0x00a6f9f0 (community match, verified in this file)
namespace f3m_00a6f9f0 {
struct FUN_00a6f9f0_Object {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct FUN_00a6f9f0_Entry {
    int index;
    int count;
    int unk08;
};

struct FUN_00a6f9f0_Pair {
    FUN_00a6f9f0_Object* object;
    unsigned int data;
};

struct FUN_00a6f9f0_Class {
    int unk00;
    int unk04;
    FUN_00a6f9f0_Entry* entries;
    int unk0C;
    int unk10;
    FUN_00a6f9f0_Pair* pairs;

    void FUN_00a6f9f0(int index, const float* values);
};

// pdb: hkpPoweredChainMapper::setTargetOrientation | hkpPoweredChainMapper.obj | fnv360_0822_retail, objrun_open, low
// pdb params: linkIndex, newTarget
void FUN_00a6f9f0_Class::FUN_00a6f9f0(int index, const float* values)
{
    FUN_00a6f9f0_Entry* entry = entries + index;

    int i = 0;
    if (entry->count > i) {
        do {
            FUN_00a6f9f0_Pair* pair = pairs + entry->index + i;
            int offset = pair->object->unk18;
            float* destination = (float*)(pair->data * 0x50 + offset + 0x20);

            destination[0] = values[0];
            destination[1] = values[1];
            destination[2] = values[2];
            destination[3] = values[3];

            ++i;
        } while (i < entry->count);
    }
}
}   // namespace f3m_00a6f9f0

// @f3 0x00a63e10 (community match, verified in this file)
namespace f3m_00a63e10 {
namespace f3m_00a63e10 {
extern unsigned long DAT_010f3170;
struct Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };

template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    __forceinline ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Heap* h = (Heap*)TlsGetValue(DAT_010f3170);
            h->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};

extern void* DAT_00e86de8[];
extern void* DAT_00e86dc8[];
void FUN_00e808e0();
void FUN_00dcc494();

struct B0 { void* vt; int unk04; __forceinline ~B0() throw() { vt = (void*)&FUN_00dcc494; } };
struct B8 { void* vt; __forceinline ~B8() throw() { vt = (void*)&FUN_00e808e0; } };

struct D00a63e10 : B0, B8 {
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Array<int> a20;
    Array<unsigned char> a2C;
    Array<unsigned char> a38;
    ~D00a63e10() throw();
};

// pdb: hkStatisticsProcess::~hkStatisticsProcess | hkStatisticsProcess.obj | fnv360_0822_retail, call_seq, medium
D00a63e10::~D00a63e10() throw()
{
    this->B0::vt = DAT_00e86de8;
    this->B8::vt = DAT_00e86dc8;
}
}
}   // namespace f3m_00a63e10

// @f3 0x00a60250 (community match, verified in this file)
namespace f3m_00a60250 {
struct Item00a60250 { unsigned short id, first, second, third; };
struct Array00a60250 { Item00a60250* data; unsigned int size, capacity; };
void __cdecl FUN_00901f10(Array00a60250*, unsigned int);
struct State00a60250 {
    unsigned int unk00;
    Array00a60250 array;
    void FUN_00a60250(unsigned short value);
};
// pdb: hkGeomHull::initializeWithVertex | hkGeomHull.obj | tesv_win, call_gap_sim, low
void State00a60250::FUN_00a60250(unsigned short value) {
    Item00a60250 item;
    item.first = 0;
    item.second = 0;
    item.id = value;
    array.size = 0;
    Array00a60250* a = &array;
    if (a->size == (a->capacity & 0x3fffffff))
        FUN_00901f10(a, 8);
    a->data[a->size++] = item;
}
}   // namespace f3m_00a60250

// @f3 0x00a6b500 (community match, verified in this file)
extern void* const DAT_00e87080[];
namespace f3m_00a6b500 {

namespace f3m_00a6b500 {

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};

struct Base {
    void* const* vptr;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38;
    int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    int unk58; int unk5c;
    Base(int type);
};

struct FUN_00a6b500 : Base {
    Vec4 a;
    Vec4 b;
    Vec4 c;
    Vec4 d;
    FUN_00a6b500(Vec4* pa, Vec4* pb, Vec4* pc, Vec4* pd);
};

// pdb: hkDisplayPlane::hkDisplayPlane | hkDisplayPlane.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: normal, perpToNormal, center, extent
FUN_00a6b500::FUN_00a6b500(Vec4* pa, Vec4* pb, Vec4* pc, Vec4* pd) : Base(7)
{
    vptr = DAT_00e87080;
    a = *pa;
    b = *pc;
    c = *pb;
    d = *pd;
}

}
}   // namespace f3m_00a6b500

// @f3 0x00a65450 (community match, verified in this file)
namespace f3m_00a65450 {
namespace f3m_00a65450 {
extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
struct FreeNode { FreeNode* next; };
struct FreeList {
    FreeNode* head;
    int count;
    void Push(FreeNode* b) throw() { ++count; b->next = head; head = b; }
};
struct ThreadMemory {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int limit;
    int unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    FreeList row6;
    void FUN_008f6890(int row, void* p, int tag) throw();
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
struct Object { void FUN_00a8d0f0(); };
template <class T> struct hkArray { T* data; int size; int capAndFlags; };
void __stdcall FUN_00a651b0(hkArray<Object*>* out, int flags);
// pdb: hkStreamStatisticsCollector::writeStatistics | hkStreamStatisticsCollector.obj | fnv360_0822_retail, caller_sim, low
// pdb params: outstream, reportLevel
void __stdcall FUN_00a65450(int a, int b)
{
    hkArray<Object*> list;
    list.data = 0;
    list.size = 0;
    list.capAndFlags = 0x80000000;
    FUN_00a651b0(&list, 0);

    while (list.size) {
        Object* p = list.data[list.size - 1];
        if (p) {
            p->FUN_00a8d0f0();
            ThreadMemory* pool = (ThreadMemory*)TlsGetValue(DAT_010f3170);
            FreeList* bucket = &pool->row6;
            if (*(volatile int*)&bucket->count >= pool->limit)
                pool->FUN_008f6890(6, p, 0x1b);
            else
                bucket->Push((FreeNode*)p);
        }
        list.size -= 1;
    }
    if ((list.capAndFlags & 0x80000000) == 0) {
        int cap = list.capAndFlags & 0x3fffffff;
        ThreadMemory* m = (ThreadMemory*)TlsGetValue(DAT_010f3170);
        m->FUN_008f6d90(list.data, cap * 4, 0x17);
    }
}
}
}   // namespace f3m_00a65450

// @f3 0x00a61170 (community match, verified in this file)
extern unsigned int DAT_010f3170;
extern unsigned int DAT_00e86c50;
namespace f3m_00a61170 {
extern "C" unsigned long (__stdcall* const DAT_00fdf044)(unsigned long);

struct Flagged_a61170 { void FUN_00908ab0(int a); };
struct Heap_a61170 { void FUN_008f6d90(void* p, int size, int tag); };

class StandIn_a61170 {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;

    void FUN_00a61170();
};

// pdb: hkProcessFactory::~hkProcessFactory | hkProcessFactory.obj | fnv360_0822_retail, call_seq, high
void StandIn_a61170::FUN_00a61170() {
    unk00 = (unsigned int)&DAT_00e86c50;
    if (unk18 != 0) {
        reinterpret_cast<Flagged_a61170*>(unk18)->FUN_00908ab0(1);
    }

    if ((int)unk10 > 0) {
        int offset = 0;
        int count = (int)unk10;
        do {
            unsigned char* entry = (unsigned char*)unk0C + offset;
            if (!(*(int*)(entry + 8) & 0x80000000)) {
                int size = *(int*)(entry + 8) & 0x3fffffff;
                Heap_a61170* heap = (Heap_a61170*)DAT_00fdf044(DAT_010f3170);
                heap->FUN_008f6d90(*(void**)entry, size, 0x17);
            }
            offset += 0x14;
            --count;
        } while (count);
    }

    if (!(unk14 & 0x80000000)) {
        int n = unk14 & 0x3fffffff;
        Heap_a61170* heap = (Heap_a61170*)DAT_00fdf044(DAT_010f3170);
        heap->FUN_008f6d90((void*)unk0C, n * 20, 0x17);
    }

    unk00 = (unsigned int)&FUN_00dcc494;
}
}   // namespace f3m_00a61170

// @f3 0x00a64790 (community match, verified in this file)
#include <windows.h>
extern "C" unsigned int DAT_010f3170;
namespace f3m_00a64790 {


struct MemCtx {
    void* __thiscall FUN_008f6d30(unsigned int size, unsigned int tag);
};

struct Obj {
    void* vtbl;
    unsigned short memSizeAndFlags;
    short referenceCount;
    void* __thiscall FUN_00a646f0();
};

// pdb: hkDebugDisplayProcess::create | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun, medium
// pdb params: contexts
void* __cdecl FUN_00a64790(void)
{
    MemCtx* ctx = (MemCtx*)TlsGetValue(DAT_010f3170);
    Obj* obj = (Obj*)ctx->FUN_008f6d30(0x24, 0x35);
    obj->memSizeAndFlags = 0x24;
    void* r = obj->FUN_00a646f0();
    if (r)
        return (char*)r + 8;
    return 0;
}
}   // namespace f3m_00a64790

// @f3 0x00a76d80 (community match, verified in this file)
namespace f3m_00a76d80 {
template <class T>
struct Arr00a76d80 {
    T* data;
    int size;
    unsigned int capFlags;
};

struct Entry00a76d80 {
    unsigned short key;
    unsigned short unk02;
};

struct Writer00a76d80 {
    int unk00;
    int unk04;
    Arr00a76d80<unsigned short> words;
    Arr00a76d80<unsigned char> bytes;
    void hkpConvexVerticesConnectivity_addFace(const Entry00a76d80* entries, int count);
};

void FUN_00901f10(void* arr, int elemSize);
template <class T>
inline void Push00a76d80(Arr00a76d80<T>& a, T v, int elemSize) {
    if (a.size == (int)(a.capFlags & 0x3fffffff))
        FUN_00901f10(&a, elemSize);
    a.data[a.size] = v;
    a.size++;
}


// pdb: hkpConvexVerticesConnectivity::addFace | hkpConvexVerticesConnectivity.obj | fnv360_0721_beta, objrun + skyrim(objrun), high
void Writer00a76d80::hkpConvexVerticesConnectivity_addFace(const Entry00a76d80* entries, int count) {
    Push00a76d80(bytes, (unsigned char)count, 1);
    for (int i = 0; i < count; i++) {
        unsigned short key = entries[i].key;
        Push00a76d80(words, key, 2);
    }
}
}   // namespace f3m_00a76d80

// @f3 0x00a61800 (community match, verified in this file)
namespace f3m_00a61800 {
struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* cs);

struct CritSecObj {
    int unk00;int unk04;int unk08;int unk0C;int unk10;int unk14;
    int unk18;
    int unk1C;
    void FUN_00908a00();
};
struct RendererObj {
    void FUN_009ee8d0(int a);
    void FUN_00a625d0(int a);
};
struct IntArr {
    int* data;
    int count;
};
struct FUN_00a61800_Class {
    int unk00;
    int unk04;
    int unk08;
    RendererObj* m_renderer;
    CritSecObj* m_critSec;
    void FUN_00a61800(IntArr* arr);
};

// pdb: hkServerDebugDisplayHandler::sendGeometryData | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: geometries
void FUN_00a61800_Class::FUN_00a61800(IntArr* arr) {
    m_critSec->FUN_00908a00();
    m_renderer->FUN_009ee8d0(arr->count);
    for (int i = 0; i < arr->count; i++)
        m_renderer->FUN_00a625d0(arr->data[i]);
    CritSecObj* cs = m_critSec;
    cs->unk18 = -1;
    cs->unk1C = -1;
    LeaveCriticalSection((_RTL_CRITICAL_SECTION*)cs);
}
}   // namespace f3m_00a61800

// @f3 0x00a705e0 (community match, verified in this file)
namespace f3m_00a705e0 {
struct Ref_a705e0 { int unk00,unk04,unk08,unk0C; signed char unk10; };
struct Pair_a705e0 { unsigned int first,second; };
class Table_a705e0 {
public:
    int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28;
    Pair_a705e0* unk2C;
    int unk30;
    bool* FUN_00a705e0(bool* result, Ref_a705e0* first, Ref_a705e0* second);
};
bool* Table_a705e0::FUN_00a705e0(bool* result, Ref_a705e0* first, Ref_a705e0* second)
{
    unsigned int firstKey = (unsigned int)((int)first + first->unk10);
    unsigned int secondKey = (unsigned int)((int)second + second->unk10);
    unsigned int highKey;
    unsigned int lowKey;
    if (firstKey > secondKey) { highKey = firstKey; lowKey = secondKey; }
    else { highKey = secondKey; lowKey = firstKey; }
    int index = 0;
    int count = unk30;
    if (count > 0) {
        Pair_a705e0* pair = unk2C;
        do {
            if (pair->first == highKey && pair->second == lowKey) goto found;
            ++index; ++pair;
        } while (index < count);
    }
    index = -1;
found:
    *result = index < 0;
    return result;
}
}   // namespace f3m_00a705e0

// @f3 0x00a72710 (community match, verified in this file)
namespace f3m_00a72710 {
struct EntryA727 { int unk00,unk04,unk08; unsigned short value; unsigned short unk0e; };
unsigned short __cdecl FUN_00a560b0(int index, int value, bool enabled);
struct OwnerA727 {
 int unk00,unk04,unk08,unk0c,unk10; unsigned char dirty; int unk18,unk1c,unk20;
 EntryA727* entries; int count; int unk2c,unk30,unk34,unk38,unk3c; unsigned char mode;
 void FUN_00a72710(int value, int modeValue);
};
void OwnerA727::FUN_00a72710(int value, int modeValue) {
 mode = (unsigned char)modeValue;
 int i;
 for (i = 0; i < count; ) {
  bool enabled = modeValue != 5;
  EntryA727* entry = &entries[i];
  entry->value = FUN_00a560b0(i, value, enabled);
  ++i;
 }
 dirty = 1;
}
}   // namespace f3m_00a72710

// @f3 0x00a6ba40 (community match, verified in this file)
namespace f3m_00a6ba40 {
namespace f3m_00a6ba40 {
struct Setter6ba40 {
    char pad00[0x60];
    float b0, b1, b2, b3;
    float a0, a1, a2, a3;
    int mode;
    float f1;
    float f2;
    void FUN_00a6ba40(float first, float second, int kind, const float* a, const float* b);
};
// pdb: hkDisplayCone::setParameters | hkDisplayCone.obj | fnv360_0822_retail, call_gap, medium
// pdb params: coneAngle, coneHeight, numSegments, coneAxis, startPos
void Setter6ba40::FUN_00a6ba40(float first, float second, int kind, const float* a, const float* b)
{
    f1 = first;
    b0 = b[0];
    b1 = b[1];
    b2 = b[2];
    b3 = b[3];
    a0 = a[0];
    a1 = a[1];
    a2 = a[2];
    a3 = a[3];
    mode = kind;
    f2 = second;
}
}
}   // namespace f3m_00a6ba40

// @f3 0x00a692a0 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a692a0 {
namespace f3m_00a692a0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
struct PoolA692 { void* FUN_008f6d30(unsigned int size, unsigned int tag); };
struct ArrA692 {
    int data;
    int size;
    int capacityAndFlags;
    ArrA692() : data(0), size(0), capacityAndFlags(0x80000000) {}
};
class BaseA692 {
public:
    virtual ~BaseA692();
    unsigned short memSize;
    unsigned short refCount;
    BaseA692() throw() { memSize = 0x14; refCount = 1; }
};
class ObjA692 : public BaseA692 {
public:
    ArrA692 arr;
    ObjA692() throw() {}
    virtual ~ObjA692();
};
// pdb: hkpUserConvexRadiusBuildercreate | hkpConvexRadiusBuilder.obj | fnv360_0822_retail, uvref, medium
ObjA692* __cdecl FUN_00a692a0()
{
    PoolA692* pool = static_cast<PoolA692*>(TlsGetValue(DAT_010f3170));
    ObjA692* o = static_cast<ObjA692*>(pool->FUN_008f6d30(0x14, 0x15));
    o->ObjA692::ObjA692();
    return o;
}
}
}   // namespace f3m_00a692a0

// @f3 0x00a655f0 (community match, verified in this file)
namespace f3m_00a655f0 {
extern "C" void __cdecl FUN_00901f10(void* array, int elementSize);

struct Entry655f0 {
    unsigned int value;
    int key;
};

template<class T> struct Array655f0 {
    T* data;
    int size;
    int capacityAndFlags;
    void pushBack(const T& v)
    {
        if (size == (capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = v;
        ++size;
    }
};

struct A655f0 {
    unsigned int unk00;
    unsigned int unk04;
    Array655f0<Entry655f0> m_array;

    void FUN_00a655f0(unsigned int value, int key);
};

// pdb: hkpUserShapeDisplayBuilder::registerUserShapeDisplayBuilder | hkpShapeDisplayBuilder.obj | fnv360_0822_retail, objrun, medium
// pdb params: f, type
void A655f0::FUN_00a655f0(unsigned int value, int key)
{
    for (int i = 0; i < m_array.size; i++) {
        if (m_array.data[i].key == key)
            return;
    }
    Entry655f0 e;
    e.value = value;
    e.key = key;
    m_array.pushBack(e);
}
}   // namespace f3m_00a655f0

// @f3 0x00a60840 (community match, verified in this file)
namespace f3m_00a60840 {
void FUN_00901e90(void* container, int bytes, int elemSize);   // cdecl free (add esp, 0xc)

struct Inner60 {                    // embedded at this+4: head pointer, count, capacity flags
    void* head;                     // 0x04
    int count;                      // 0x08
    volatile unsigned int capFlags;   // 0x0c - the original reloads it from memory, so VC8 cannot fold
};

struct A60 {
    int slot0;                      // 0x00
    Inner60 inner;                  // 0x04 - 0x0f
    void* sentinel;                 // 0x10 - the head points here (lea eax,[esi+0xc])

    A60* FUN_00a60840();            // thiscall member, no stack params (ret)
};

// pdb: hkGeomHull::hkGeomHull | hkGeomHull.obj | tesv_win, call_gap, low
A60* A60::FUN_00a60840() {
    Inner60* in = &inner;               // ORIG: lea esi,[edi+4] up front and keeps it live across the call
    slot0 = 0;
    in->head = (void*)(0xc + (char*)in);   // ORIG: lea eax,[esi+0xc] - based on the container pointer         // ORIG: lea eax,[esi+0xc] ; mov [esi],eax
    in->count = 0;
    in->capFlags = 0x80000080u;

    int v = (0x3fffffffu & in->capFlags);   // ORIG: mov eax,[esi+8] ; and eax,imm ; jge skip
    if (v < 0) {                    // never taken after the mask, but the original emits it anyway
        int want = v + v;           // ORIG: add eax,eax ... branchless `want > 0 ? want : 0`
                int p;
                if (want > 0) p = want; else p = 0;
        FUN_00901e90(in, p, 8);
    }

    in->count = 0;                      // ORIG: mov dword ptr [esi + 4], 0 after the pops
    return this;                    // ORIG: mov eax,edi before that store
}
}   // namespace f3m_00a60840

// @f3 0x00a68f60 (community match, verified in this file)
namespace f3m_00a68f60 {
extern void __cdecl FUN_00901f10(void*, int);

template<class T> struct hkArrayA68 {
    T* data;
    int size;
    int capacity;
    void pushBack(const T& value)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = value;
        ++size;
    }
};

struct PairA68 {
    int value;
    int key;
};

struct OwnerA68 {
    int unk00;
    int unk04;
    hkArrayA68<PairA68> entries;
    void FUN_00a68f60(int value, int key);
};

void OwnerA68::FUN_00a68f60(int value, int key)
{
    for (int i = 0; i < entries.size; i++) {
        if (entries.data[i].key == key)
            return;
    }
    PairA68 pair;
    pair.value = value;
    pair.key = key;
    entries.pushBack(pair);
}
}   // namespace f3m_00a68f60

// @f3 0x00a7fe10 (community match, verified in this file)
extern double DAT_00e01a58;
namespace f3m_00a7fe10 {

struct ClipPlane_a7fe10 {
    float n0;
    float n1;
    float n2;
    int unk0C;
    float* origin;
    int FUN_00a7fe10(float* point, float* lo, float* hi);
};

// pdb: hkpWingedEdge::Triangle::calcStateAndUpdateTolerance | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkWingedEdge::Triangle::calcStateAndUpdateTolerance)
// pdb params: pointOfView, toleranceBorder, previousMinimumDistance
int ClipPlane_a7fe10::FUN_00a7fe10(float* point, float* lo, float* hi)
{
    __declspec(align(16)) float diff[3];
    diff[0] = point[0] - origin[0];
    diff[1] = point[1] - origin[1];
    diff[2] = point[2] - origin[2];
    float t = (float)(n1 * diff[1] + n0 * diff[0] + n2 * diff[2]);
    int result = 1;
    if (t > *lo) {
        if (t < *hi) {
            *hi = t;
        }
    } else {
        double t2 = t + DAT_00e01a58;
        if (*lo < t2) {
            *lo = (float)t2;
        }
        result = 2;
    }
    if (*lo >= *hi) {
        return 4;
    }
    return result;
}
}   // namespace f3m_00a7fe10

// @f3 0x00a61860 (community match, verified in this file)
namespace f3m_00a61860 {
namespace f3m_00a61860 {

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

struct Renderer {
    void FUN_009ee8d0(int a);
    void FUN_009ee560(int a);
    void FUN_009ee930(int a, int b);
    void FUN_00a623b0(int a);
    unsigned char* FUN_009ee770(int* p);
};

struct Lock {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    int unk018;
    int unk01C;
    void FUN_00908a00();
};

int __cdecl FUN_00a617d0();

struct Owner;

struct Part {
    unsigned int unk000;
    Renderer* m_renderer;
    Lock* m_lock;
    Owner* GetOwner() { return (Owner*)((char*)this - 8); }
    bool FUN_00a61860(int a, int b, int c, int d, int e);
};

struct Owner {
    void FUN_00a61800(int a);
};

// pdb: hkServerDebugDisplayHandler::addGeometry | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: geometries, transform, id, tag, shapeIdHint
bool Part::FUN_00a61860(int a, int b, int c, int d, int e)
{
    m_lock->FUN_00908a00();
    if (m_renderer != 0) {
        int k = a;
        m_renderer->FUN_009ee8d0(FUN_00a617d0() + 0x29);
        m_renderer->FUN_009ee560(1);
        GetOwner()->FUN_00a61800(k);
        m_renderer->FUN_00a623b0(b);
        m_renderer->FUN_009ee930(c, 0);
        m_renderer->FUN_009ee8d0(d);
    }
    bool ok = m_renderer != 0 && *m_renderer->FUN_009ee770(&a) != 0;
    Lock* o = m_lock;
    o->unk018 = -1;
    o->unk01C = -1;
    LeaveCriticalSection(o);
    return !ok;
}
}
}   // namespace f3m_00a61860

// @f3 0x00a62200 (community match, verified in this file)
namespace f3m_00a62200 {
namespace f3m_00a62200 {
struct Pool {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    void* freeList;
    int freeCount;
    void* FUN_008f6800(int row, int size) throw();
};
extern "C" __declspec(dllimport) Pool* __stdcall TlsGetValue(unsigned long index);
extern unsigned long DAT_010f3170;
struct Lock;
extern Lock DAT_011692e8;
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(Lock* cs);
extern int (__stdcall* DAT_00d9b1ac)(Lock*, unsigned);
struct Lock {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int owner, recursion;
    unsigned spin;
    Lock* prev;
    Lock* next;
    void FUN_00908a00();
    static void* operator new(unsigned int) throw()
    {
        Pool* pool = TlsGetValue(DAT_010f3170);
        void* p = pool->freeList;
        if (p) {
            pool->freeCount--;
            pool->freeList = *(void**)p;
        } else {
            p = pool->FUN_008f6800(4, 0x15);
        }
        return p;
    }
    __forceinline Lock() throw() : spin(1000), prev(0), next(0)
    {
        DAT_011692e8.FUN_00908a00();
        next = DAT_011692e8.next;
        if (next) next->prev = this;
        prev = &DAT_011692e8;
        DAT_011692e8.next = this;
        DAT_011692e8.owner = -1;
        DAT_011692e8.recursion = -1;
        LeaveCriticalSection(&DAT_011692e8);
        DAT_00d9b1ac(this, 1000);
        owner = -1;
        recursion = -1;
    }
};
struct __declspec(novtable) RefBase {
    unsigned short unk04;
    unsigned short unk06;
    RefBase() : unk06(1) {}
    virtual void Release();
};
struct Interface {
    Interface() {}
    virtual void F0();
};
struct LockHolder : RefBase, Interface {
    int value;
    Lock* lock;
    LockHolder(int v);
    virtual void Release();
    virtual void F0();
};
// pdb: hkServerDebugDisplayHandler::hkServerDebugDisplayHandler | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, call_gap, medium
// pdb params: stream
LockHolder::LockHolder(int v) : value(v)
{
    lock = new Lock;
}
}
}   // namespace f3m_00a62200

// @f3 0x00a6f8c0 (community match, verified in this file)
namespace f3m_00a6f8c0 {
namespace f3m_00a6f8c0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long) throw();   // TlsGetValue
struct ThreadMemory { void FUN_008f6d90(void* p, int bytes, int tag) throw(); };
template <class T> struct Array {
    T* data;
    int size;
    int capacityAndFlags;
    __forceinline void Release() throw()
    {
        if ((capacityAndFlags & 0x80000000) == 0) {
            int capacity = capacityAndFlags & 0x3fffffff;
            ThreadMemory* memory = (ThreadMemory*)DAT_00d9b080(DAT_010f3170);
            memory->FUN_008f6d90(data, capacity * sizeof(T), 0x17);
        }
    }
};
struct Target { void FUN_009316f0() throw(); };   // removeReference
struct Entry {
    Target* target;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    ~Entry() throw() { target->FUN_009316f0(); }
};
class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};
class __declspec(novtable) ReferencedObject : public hkBaseObject {
public:
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
}
class FUN_00a6f8c0 : public f3m_00a6f8c0::ReferencedObject {
public:
    virtual ~FUN_00a6f8c0() throw();
    f3m_00a6f8c0::Array<f3m_00a6f8c0::Entry> entries;   // 0x08
};

// pdb: hkpSerializedDisplayRbTransforms::~hkpSerializedDisplayRbTransforms | hkpSerializedDisplayRbTransforms.obj | fnv360_0822_retail, call_seq, high
FUN_00a6f8c0::~FUN_00a6f8c0() throw()
{
    int count = entries.size;
    for (int i = 0; i < count; i++)
        entries.data[i].~Entry();
    entries.Release();
}
}   // namespace f3m_00a6f8c0

// @f3 0x00a777a0 (community match, verified in this file)
namespace f3m_00a777a0 {
namespace f3m_00a777a0 {
class ReferencedObject {
public:
    virtual ~ReferencedObject();
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if ((unsigned short)referenceCount == 0)
                delete this;
        }
    }
};
template <class T> struct Array {
    T* data;
    int size;
    int capacityAndFlags;
    int indexOf(const T& t) const
    {
        for (int i = 0; i < size; i++)
            if (data[i] == t)
                return i;
        return -1;
    }
    void removeAt(int index) { size--; data[index] = data[size]; }
};
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Array<ReferencedObject*> objects;   // 0x30
    void hkpCollisionFilterList_removeCollisionFilter(ReferencedObject* object);
};
}

// pdb: hkpCollisionFilterList::removeCollisionFilter | hkpCollisionFilterList.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void f3m_00a777a0::Owner::hkpCollisionFilterList_removeCollisionFilter(ReferencedObject* object)
{
    int index = objects.indexOf(object);
    objects.removeAt(index);
    object->removeReference();
}
}   // namespace f3m_00a777a0

// @f3 0x00a619f0 (community match, verified in this file)
namespace f3m_00a619f0 {
struct Renderer19 {
    void FUN_009ee8d0(int value);
    void FUN_009ee560(int value);
    void FUN_009ee8f0(int value);
    unsigned char* FUN_009ee770(int* value);
};

struct Other19 {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    int unk018;
    int unk01C;
    void FUN_00908a00();
};

struct Base19 {
    void FUN_00a61800(int value);
};

int FUN_00a617d0();

struct Owner19 {
    unsigned int unk000;
    Renderer19* m_renderer;
    Other19* m_other;
    bool FUN_00a619f0(int value1, int value2, int value3);
};

// pdb: hkServerDebugDisplayHandler::displayGeometry | hkServerDebugDisplayHandler.obj | fnv360_0721_beta, objopen_prop, medium
// pdb params: geometries, color, id, tag
bool Owner19::FUN_00a619f0(int value1, int value2, int value3)
{
    m_other->FUN_00908a00();
    if (m_renderer != 0) {
        int k = *(volatile int*)&value1;
        m_renderer->FUN_009ee8d0(FUN_00a617d0() + 9);
        m_renderer->FUN_009ee560(6);
        reinterpret_cast<Base19*>(reinterpret_cast<char*>(this) - 8)->FUN_00a61800(k);
        m_renderer->FUN_009ee8f0(value2);
        m_renderer->FUN_009ee8d0(value3);
    }
    bool ok = m_renderer != 0 && *m_renderer->FUN_009ee770(&value1) != 0;
    Other19* o = m_other;
    o->unk018 = -1;
    o->unk01C = -1;
    ::LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(o));
    return !ok;
}
}   // namespace f3m_00a619f0

// @f3 0x00a65650 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a65650 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void __cdecl FUN_00901f10(void* array, int elementSize);

struct FUN_00a65650_Pool;
struct FUN_00a65650_Array {
    void** data;
    int size;
    unsigned int capacityAndFlags;
    FUN_00a65650_Array() : data(0), size(0), capacityAndFlags(0x80000000) {}
};

struct FUN_00a65650_Grid {
    FUN_00a65650_Array a;
    FUN_00a65650_Array b;
    static void* operator new(unsigned int) throw();
};

struct FUN_00a65650_Pool {
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
    void* head;
    int count;
    void* FUN_008f6800(int units, int category);
    void* FUN_008f6d30(int size, int category);
};

struct FUN_00a65650_Object {
    int unk00;
    unsigned short unk04;
    void* FUN_00a67b10(FUN_00a65650_Grid* grid);
};

inline void* FUN_00a65650_Grid::operator new(unsigned int) throw() {
    FUN_00a65650_Pool* pool = (FUN_00a65650_Pool*)TlsGetValue(DAT_010f3170);
    void* memory = pool->head;
    if (memory != 0) {
        pool->count--;
        pool->head = *(void**)memory;
    } else {
        memory = pool->FUN_008f6800(3, 0x27);
    }
    return memory;
}

struct FUN_00a65650_Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;

    void* FUN_00a65650(FUN_00a65650_Array* param);
};

// pdb: hkpShapeDisplayBuilder::getCurrentRawGeometry | hkpShapeDisplayBuilder.obj | fnv360_0822_retail, objrun, medium
// pdb params: displayGeometries
void* FUN_00a65650_Owner::FUN_00a65650(FUN_00a65650_Array* param) {
    if (unk10 == 0) {
        FUN_00a65650_Grid* grid = new FUN_00a65650_Grid;
        FUN_00a65650_Pool* pool2 = (FUN_00a65650_Pool*)TlsGetValue(DAT_010f3170);
        FUN_00a65650_Object* object = (FUN_00a65650_Object*)pool2->FUN_008f6d30(0x60, 8);
        object->unk04 = 0x60;
        unk10 = object->FUN_00a67b10(grid);

        int capacity = param->capacityAndFlags & 0x3fffffff;
        if (param->size == capacity) {
            FUN_00901f10(param, 4);
        }
        param->data[param->size] = unk10;
        param->size++;
    }
    return unk10;
}
}   // namespace f3m_00a65650

// @f3 0x00a6c100 (community match, verified in this file)
namespace f3m_00a6c100 {
namespace f3m_00a6c100 { extern void* (__stdcall* const DAT_00d9b080)(unsigned long); }

struct Vec4 { float x, y, z, w; };
struct VecArr { Vec4* data; int count; unsigned int cap; };
struct TlsCtx { void FUN_008f6d90(void* p, unsigned int bytes, int tag); };
extern unsigned long DAT_010f3170;
void FUN_00901e90(VecArr* a, int n, int elem);

struct FUN_00a6c100_cls {
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    float unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80;
    void FUN_00a6bb60(VecArr* t);
    void FUN_00a6c100(VecArr* out);
};

// pdb: hkDisplayCone::getWireframeGeometry | hkDisplayCone.obj | fnv360_0822_retail, vtable, medium
// pdb params: lines, a
void FUN_00a6c100_cls::FUN_00a6c100(VecArr* out)
{
    __declspec(align(16)) VecArr tmp;
    __declspec(align(16)) Vec4 buf[256];
    tmp.data = buf;
    tmp.count = 0;
    tmp.cap = 0x80000100;
    FUN_00a6bb60(&tmp);

    int n = unk80 * 4;
    unsigned int cap = out->cap & 0x3fffffff;
    if ((int)cap < n) {
        int g = (int)cap * 2;
        if (n >= g) g = n;
        FUN_00901e90(out, g, 16);
    }
    out->count = n;

    int i = 0;
    unsigned int k = 0;
    if (unk80 > 0) { unsigned int j = 0; do {
        Vec4* d = (Vec4*)((char*)out->data + k);
        d->x = unk60; d->y = unk64; d->z = unk68; d->w = unk6c;
        k += 16;
        ++i;
        Vec4* s = (Vec4*)((char*)tmp.data + j);
        d = (Vec4*)((char*)out->data + k);
        d->x = s->x; d->y = s->y; d->z = s->z; d->w = s->w;
        k += 16;
        s = (Vec4*)((char*)tmp.data + j);
        d = (Vec4*)((char*)out->data + k);
        d->x = s->x; d->y = s->y; d->z = s->z; d->w = s->w;
        j += 16;
        k += 16;
        s = (Vec4*)((char*)tmp.data + (i % unk80) * 16);
        d = (Vec4*)((char*)out->data + k);
        d->x = s->x; d->y = s->y; d->z = s->z; d->w = s->w;
        k += 16;
    } while (i < unk80); }

    if ((tmp.cap & 0x80000000) == 0) {
        int c = tmp.cap & 0x3fffffff;
        TlsCtx* ctx = (TlsCtx*)f3m_00a6c100::DAT_00d9b080(DAT_010f3170);
        ctx->FUN_008f6d90(tmp.data, c * sizeof(Vec4), 0x17);
    }
}
}   // namespace f3m_00a6c100

// @f3 0x00a74650 (community match, verified in this file)
namespace f3m_00a74650 {
namespace S00a74650_hk
{
struct Vector4
{
    __declspec(align(16)) float x;
    float y, z, w;
    void setZero4() { x = y = z = w = 0.0f; }
    float& operator()(int i) { return (&x)[i]; }
    void operator=(const Vector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
};
struct Matrix3
{
    Vector4 col0, col1, col2;
    float& operator()(int r, int c) { return (&col0)[c](r); }
    void setZero() { Vector4 zero; zero.setZero4(); col0 = zero; col1 = zero; col2 = zero; }
    void setIdentity() { setZero(); (*this)(0, 0) = 1.0f; (*this)(1, 1) = 1.0f; (*this)(2, 2) = 1.0f; }
};
struct Transform
{
    Matrix3 rotation;
    Vector4 translation;
    void setIdentity() { rotation.setIdentity(); translation.setZero4(); }
};
struct Referenced
{
    void* vtable;
    unsigned short sizeAndFlags;
    short count;
    void AddRef() { if (sizeAndFlags) count += 1; }
    void Release()
    {
        if (sizeAndFlags)
        {
            count -= 1;
            if (count == 0)
            {
                typedef void (__thiscall *Delete)(Referenced*, int);
                (*reinterpret_cast<Delete**>(this))[0](this, 1);
            }
        }
    }
};
struct Owner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Referenced* referenced;
    int unk1c, unk20, unk24, unk28, unk2c;
    Transform first, second;
    void FUN_00a74650(const Vector4& a, const Vector4& b, Referenced* object);
};
void Owner::FUN_00a74650(const Vector4& a, const Vector4& b, Referenced* object)
{
    if (object) object->AddRef();
    if (referenced) referenced->Release();
    referenced = object;
    first.setIdentity();
    second.setIdentity();
    first.translation = a;
    second.translation = b;
}
}
}   // namespace f3m_00a74650

// @f3 0x00a6a7b0 (community match, verified in this file)
namespace f3m_00a6a7b0 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
struct __declspec(align(16)) Vec4 { float x, y, z, w; };
extern unsigned int __cdecl FUN_00921880(float, float, float, float);
struct Drawer { void FUN_00a8f9c0(const Vec4*, const Vec4*, const Vec4*, unsigned int, float, void*); };
struct Cls {
 int unk00, unk04, unk08;
 float opacity;
 int unk10, unk14, unk18, unk1c;
 Vec4 center20, center30, spare40, spare50;
 Vec4 v60, v70, v80, v90, vA0, vB0;
 Drawer drawer;
 void FUN_00a6a7b0(void* context);
};
// pdb: hkpConstraintDrawer::drawBodyFrames | hkpConstraintDrawer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: id, tag
void Cls::FUN_00a6a7b0(void* context)
{
    unsigned int c0 = FUN_00921880(1.0f, 1.0f, 0.0f, 1.0f);
    unsigned int c1 = FUN_00921880(1.0f, 0.5f, 0.0f, 1.0f);
    unsigned int c2 = FUN_00921880(1.0f, 0.0f, 1.0f, 1.0f);
    Vec4 a0, a1, a2, b0, b1, b2;
    a0.x = v60.x; a0.y = v60.y; a0.z = v60.z; a0.w = v60.w;
    a1.x = v70.x; a1.y = v70.y; a1.z = v70.z; a1.w = v70.w;
    a2.x = v80.x; a2.y = v80.y; a2.z = v80.z; a2.w = v80.w;
    b0.x = v90.x; b0.y = v90.y; b0.z = v90.z; b0.w = v90.w;
    b1.x = vA0.x; b1.y = vA0.y; b1.z = vA0.z; b1.w = vA0.w;
    b2.x = vB0.x; b2.y = vB0.y; b2.z = vB0.z; b2.w = vB0.w;
    drawer.FUN_00a8f9c0(&center20, &a0, &a1, 0xffff0000u, opacity, context);
    drawer.FUN_00a8f9c0(&center20, &a1, &a2, 0xff008000u, opacity, context);
    drawer.FUN_00a8f9c0(&center20, &a2, &a0, 0xff0000ffu, opacity, context);
    drawer.FUN_00a8f9c0(&center30, &b0, &b1, c0, opacity, context);
    drawer.FUN_00a8f9c0(&center30, &b1, &b2, c1, opacity, context);
    drawer.FUN_00a8f9c0(&center30, &b2, &b0, c2, opacity, context);
}
}   // namespace f3m_00a6a7b0

// @f3 0x00a60350 (community match, verified in this file)
#include <math.h>
namespace f3m_00a60350 {

namespace f3m_00a60350 {

struct __declspec(align(16)) hkVector4 {
    float x, y, z, w;
    inline void sub4(const hkVector4& o) { x -= o.x; y -= o.y; z -= o.z; w -= o.w; }
    inline void setSub4(const hkVector4& a, const hkVector4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    inline void mul4(float s) { x *= s; y *= s; z *= s; w *= s; }
    inline float lengthSquared3() const { return x * x + y * y + z * z; }
    inline float lengthSquared4() const { return x * x + y * y + z * z + w * w; }
    __forceinline void normalize3()
    {
        float len = lengthSquared3();
        float inv;
        if (len != 0.0f) inv = 1.0f / (float)sqrt(len); else inv = 0.0f;
        mul4(inv);
    }
};

inline float max2(float a, float b) { return a > b ? a : b; }

struct Edge {
    short v;
    short e0;
    short e1;
    short unk06;
    Edge() {}
    Edge(int a, short b, short c) : v((short)a), e0(b), e1(c) {}
};

struct hkArrayUtil {
    static void __cdecl _reserveMore(void* array, int elemSize);
};

struct EdgeArray {
    Edge* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline void pushBack(const Edge& e)
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            hkArrayUtil::_reserveMore(this, sizeof(Edge));
        m_data[m_size] = e;
        m_size++;
    }
};

struct S00a60350_Triangulator {
    hkVector4* m_verts;
    EdgeArray m_edges;
    void splitDegenerate(int a, int b);
    void FUN_00a60350(int a, int b, int c);
};

// pdb: hkGeomHull::initializeWithTriangle | hkGeomHull.obj | tesv_win, call_gap_sim, low
void S00a60350_Triangulator::FUN_00a60350(int a, int b, int c)
{
    m_edges.m_size = 0;
    hkVector4 e0 = m_verts[b]; e0.sub4(m_verts[a]);
    float l0 = e0.lengthSquared4();
    hkVector4 e1 = m_verts[c]; e1.sub4(m_verts[b]);
    float l1 = e1.lengthSquared4();
    hkVector4 e2 = m_verts[a]; e2.sub4(m_verts[c]);
    float l2 = e2.lengthSquared4();
    e0.normalize3();
    e1.normalize3();
    hkVector4 d;
    d.setSub4(e1, e0);
    if (d.lengthSquared3() < 1e-6f)
    {
        float m = max2(l0, max2(l1, l2));
        if (m == l0) { splitDegenerate(a, b); return; }
        if (m == l1) { splitDegenerate(b, c); return; }
        if (m == l2) { splitDegenerate(c, a); }
        return;
    }
    Edge t0(a, 1, 2);
    Edge t1(b, 0, 5);
    Edge t2(b, 3, 4);
    Edge t3(c, 2, 1);
    Edge t4(c, 5, 0);
    Edge t5(a, 4, 3);
    m_edges.pushBack(t0);
    m_edges.pushBack(t1);
    m_edges.pushBack(t2);
    m_edges.pushBack(t3);
    m_edges.pushBack(t4);
    m_edges.pushBack(t5);
}

}
}   // namespace f3m_00a60350

// @f3 0x00a6e650 (community match, verified in this file)
extern double DAT_00de7348;
namespace f3m_00a6e650 {
struct ZScalar { float value; ZScalar(float f):value(f) {} operator float() const { return value; } };
struct __declspec(align(16)) ZVec4 {
 float x,y,z,w;
 void setMul(const ZScalar& scalar,const ZVec4& v) { float f=scalar.value; x=f*v.x;y=f*v.y;z=f*v.z;w=f*v.w; }
 void setMul4(const ZScalar& scalar,const ZVec4& v) { x=scalar.value*v.x;y=scalar.value*v.y;z=scalar.value*v.z;w=scalar.value*v.w; }
 void add(const ZVec4& v) { x=v.x+x;y=v.y+y;z=v.z+z;w=v.w+w; }
 void setAdd(const ZVec4& a,const ZVec4& b) { x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w; }
 void hkVector4_setTransformedPos(const void*,const ZVec4*);
 void hkVector4_setRotatedDir(const void*,const ZVec4*);
};
struct ZTransform { ZVec4 a,b,c,d; };
struct ZLimits {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c;
 ZVec4 unk50,unk60,unk70,unk80,unk90;
 int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4;
 float unkc8,unkcc;
};
struct ZConstraint { int unk00,unk04,unk08; ZLimits* unk0c; };
struct ZDisplay {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
 virtual void Line(const ZVec4&,const ZVec4&,unsigned,int);
};
struct ZDisplaySlot { int unk00; void FUN_00a8f460(ZDisplay*); };
unsigned __cdecl FUN_00921880(float,float,float,float);
struct ZDrawer {
 float unk00; int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 ZVec4 unk40,unk50;
 ZVec4 unk60,unk70,unk80,unk90,unka0,unkb0;
 ZDisplaySlot unkc0;
 void FUN_00a6aa20(ZConstraint*,ZTransform*,ZTransform*);
 void FUN_00a6a750(int); void FUN_00a6a7b0(int);
 void FUN_00a6e650(ZConstraint*,ZDisplay*,int);
};
// pdb: hkpPrismaticDrawer::drawConstraint | hkpPrismaticDrawer.obj | fnv360_0822_retail, call_gap, medium
// pdb params: constraint, displayHandler, id, tag
void ZDrawer::FUN_00a6e650(ZConstraint* constraint,ZDisplay* display,int tag) {
 ZLimits* limits=constraint->unk0c;
 unkc0.FUN_00a8f460(display);
 ZTransform a,b;
 FUN_00a6aa20(constraint,&a,&b);
 unk50.hkVector4_setTransformedPos(&a,&limits->unk90);
 unk40.hkVector4_setTransformedPos(&b,&limits->unk50);
 FUN_00a6a750(tag); FUN_00a6a7b0(tag);
 ZVec4 axis,perp;
 const ZVec4* axisInput=&limits->unk60; const void* rot=&unk90; axis.hkVector4_setRotatedDir(rot,axisInput);
 perp.hkVector4_setRotatedDir(&unk90,&limits->unk70);
 display->Line(unk40,unk50,0xffff0000,tag);
 {
 ZVec4 p0,p1;
 if (limits->unkcc != DAT_00de7348) {
  p1.setMul4(limits->unkcc,axis); p1.add(unk50);
  p0.setMul(limits->unkc8,axis); p0.add(unk50);
  display->Line(p0,p1,FUN_00921880(0.0f,0.5f,1.0f,1.0f),tag);
 } else {
  p1.setMul4(unk00,axis); p1.add(unk50);
  p0.setMul4(-unk00,axis); p0.add(unk50);
  display->Line(p0,p1,FUN_00921880(0.0f,0.5f,1.0f,1.0f),tag);
 }
 }
 float maximum=limits->unkcc;
 float minimum=limits->unkc8;
 {
 ZVec4 temp,point,barA,barB;
 temp.setMul(minimum,axis); point.setAdd(temp,unk50);
 temp.setMul((float)(unk00*0.5),perp); barA.setAdd(point,temp);
 temp.setMul((float)(unk00*-0.5),perp); barB.setAdd(point,temp);
 display->Line(barA,barB,0xffffffff,tag);
 temp.setMul(maximum,axis); point.setAdd(unk50,temp);
 temp.setMul((float)(unk00*0.5),perp); barA.setAdd(point,temp);
 temp.setMul((float)(unk00*-0.5),perp); barB.setAdd(point,temp);
 display->Line(barA,barB,0xffffffff,tag);
 }
}
}   // namespace f3m_00a6e650

// @f3 0x00a602b0 (community match, verified in this file)
namespace f3m_00a602b0 {
namespace Fill356 {
struct __declspec(align(4)) Entry{unsigned short id,a,b;Entry(unsigned short i,unsigned short x,unsigned short y):id(i),a(x),b(y){}};struct Array{Entry* data;int size;unsigned capacity;void push(const Entry& e);};void FUN_00901f10(Array*,int);void Array::push(const Entry&e){if(size==(int)(capacity&0x3fffffff))FUN_00901f10(this,8);data[size]=e;++size;}
// pdb: hkGeomHull::initializeWithEdge | hkGeomHull.obj | tesv_win, call_gap_sim, low
struct Owner{int unk00;Array array;void FUN_00a602b0(unsigned short,unsigned short);};void Owner::FUN_00a602b0(unsigned short a,unsigned short b){array.size=0;Entry first(a,1,1),second(b,0,0);array.push(first);array.push(second);}
}
}   // namespace f3m_00a602b0

// @f3 0x00a6bb60 (community match, verified in this file)
#include <math.h>
extern const double DAT_00dc0760;
namespace f3m_00a6bb60 {
// 0x00a6bb60 (1124 bytes): cone point generation with two inlined quaternion rotations.
// Matches exactly under /MT /O2 /GS /EHsc /Gy (the pack lists /Od, but the original code is optimised:
// aligned frame, esp-relative locals, values kept in esi/ebx/edi and on the x87 stack).
// The x87 operand order depends on the compiler's symbol numbering: the two unused locals at the top
// and the indexed read of the quaternion's real part are needed for the first rotation to match.

namespace f3m_00a6bb60 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;


static const hkReal HK_REAL_PI = 3.14159265358979f;

void __cdecl FUN_00901e90(void* array, int numElements, int elementSize);

struct hkQuaternion;

struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void mul4(hkSimdRealParameter s) { hkReal f = s; x *= f; y *= f; z *= f; w *= f; }
    __forceinline void setMul4(hkSimdRealParameter s, const hkVector4& v)
    {
        x = s * v.x;
        y = s * v.y;
        z = s * v.z;
        w = s * v.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& v)
    {
        hkReal s = rs;
        x += s * v.x;
        y += s * v.y;
        z += s * v.z;
        w += s * v.w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1.y * v2.z - v1.z * v2.y;
        const hkReal ny = v1.z * v2.x - v1.x * v2.z;
        const hkReal nz = v1.x * v2.y - v1.y * v2.x;
        set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& v) const { return x * v.x + y * v.y + z * v.z; }
    __forceinline hkSimdReal lengthSquared3() const { return x * x + y * y + z * z; }
    __forceinline void normalize3()
    {
        hkReal l2 = lengthSquared3();
        hkReal inv;
        if (l2 != 0.0f)
        {
            hkReal r = (hkReal)sqrt(l2);
            inv = 1.0f / r;
        }
        else
            inv = 0.0f;
        mul4(inv);
    }
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    hkQuaternion(const hkVector4& axis, hkReal angle);
    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec.w; }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    const hkReal qreal = quat.m_vec(3);
    const hkReal q2minus1 = qreal * qreal - 0.5;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    const hkReal imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    setAdd4(ret, ret);
}

namespace hkMath {
__forceinline hkReal fabs(hkReal r) { return ::fabsf(r); }
}

__forceinline void calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkMath::fabs(vectorIn(0));
    hkReal a1 = hkMath::fabs(vectorIn(1));
    hkReal a2 = hkMath::fabs(vectorIn(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    biVectorOut.setZero4();
    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = -vectorIn(ok1);
}

template <class T> struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline void setSize(int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = n < cap2 ? cap2 : n;
            FUN_00901e90(this, newSize, sizeof(T));
        }
        m_size = n;
    }
    __forceinline T& operator[](int i) { return m_data[i]; }
};

struct hkDisplayCone
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
    hkVector4 m_startPos;
    hkVector4 m_direction;
    int m_numSegments;
    hkReal m_coneAngle;
    hkReal m_coneHeight;

    void FUN_00a6bb60(hkArray<hkVector4>& conePoints);
};

// pdb: hkDisplayCone::generateConeVertices | hkDisplayCone.obj | fnv360_0822_debug, objrun, medium
// pdb params: conePoints
void hkDisplayCone::FUN_00a6bb60(hkArray<hkVector4>& conePoints)
{
    int numSegments = m_numSegments;
    hkReal coneHeight = m_coneHeight;
    conePoints.setSize(m_numSegments);

    hkVector4 perpVec;
    calculatePerpendicularVector(m_direction, perpVec);
    perpVec.normalize3();

    hkQuaternion q1(perpVec, m_coneAngle);
    hkQuaternion q2(m_direction, DAT_00dc0760 / m_numSegments);

    hkVector4 offsetDir;
    offsetDir.setRotatedDir(q1, m_direction);

    for (int i = 0; i < m_numSegments; i++)
    {
        conePoints[i] = m_startPos;
        conePoints[i].addMul4(m_coneHeight, offsetDir);
        offsetDir.setRotatedDir(q2, offsetDir);
    }
}

}
}   // namespace f3m_00a6bb60

// @f3 0x00a72770 (community match, verified in this file)
namespace f3m_00a72770 {


namespace S00a72770_ns {

struct __declspec(align(16)) S00a72770_Vec4 {
    float x, y, z, w;
    void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void hkVector4_setTransformedPos(const void* transform, const S00a72770_Vec4& v);
};

struct S00a72770_Aabb {
    S00a72770_Vec4 min;
    S00a72770_Vec4 max;
};

struct S00a72770_Shape {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S00a72770_Vec4* vertices;
    int numVertices;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float radius;
    void FUN_00a72770(const void* transform, float tolerance, S00a72770_Aabb& out);
};

}

using namespace S00a72770_ns;

void S00a72770_Shape::FUN_00a72770(const void* transform, float tolerance, S00a72770_Aabb& out)
{
    int dz0 = numVertices;
    out.min.x = 3.40282e38f;
    out.min.y = 3.40282e38f;
    out.min.z = 3.40282e38f;
    out.min.w = 0.0f;
    out.max.x = -3.40282e38f;
    out.max.y = -3.40282e38f;
    out.max.z = -3.40282e38f;
    out.max.w = 0.0f;

    for (int i = 0; i < numVertices; i++) {
        S00a72770_Vec4 v;
        v.hkVector4_setTransformedPos(transform, vertices[i]);
        out.min.x = out.min.x < v.x ? out.min.x : v.x;
        out.min.y = out.min.y < v.y ? out.min.y : v.y;
        out.min.z = out.min.z < v.z ? out.min.z : v.z;
        out.min.w = out.min.w < v.w ? out.min.w : v.w;
        out.max.x = out.max.x > v.x ? out.max.x : v.x;
        out.max.y = out.max.y > v.y ? out.max.y : v.y;
        out.max.z = out.max.z > v.z ? out.max.z : v.z;
        out.max.w = out.max.w > v.w ? out.max.w : v.w;
    }

    float s = radius + tolerance;
    out.min.x -= s;
    out.min.y -= s;
    out.min.z -= s;
    out.min.w -= s;
    out.max.x += s;
    float* py = &out.max.y;
    *py += s;
    out.max.z += s;
    out.max.w += s;
}
}   // namespace f3m_00a72770

// @f3 0x00a61680 (community match, verified in this file)
namespace f3m_00a61680 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;                             // memory router TLS slot
extern const char DAT_00e86c60[];  // "VDB: Found a command (%x) with no handler. Could corrupt the stream."

class hkBool
{
  public:
    char m_bool;
    hkBool(bool b) { m_bool = (char)b; }
};

struct __declspec(align(16)) hkQuadReal
{
    float x, y, z, w;
};

struct Stream
{
    int FUN_00a60ca0(void* buf, int elemSize, int count);
    void FUN_00a62980(void* quad);
    char* FUN_00a60da0(char* result);

    unsigned char read8u()
    {
        unsigned char value;
        FUN_00a60ca0(&value, 1, 1);
        return value;
    }
    unsigned __int64 read64u()
    {
        unsigned __int64 value;
        FUN_00a60ca0(&value, 8, 1);
        return value;
    }
    bool isOk()
    {
        char result;
        return *FUN_00a60da0(&result) != 0;
    }
};

struct MemoryRouter
{
    void* FUN_008f6d30(int size, int tag) throw();
    void FUN_008f6d90(void* p, int size, int tag) throw();
};

inline MemoryRouter* GetMemoryRouter()
{
    return static_cast<MemoryRouter*>(TlsGetValue(DAT_010f3170));
}

class hkString
{
  public:
    char* m_data;
    int m_size;
    int m_capacityAndFlags;

    void Init()
    {
        m_data = static_cast<char*>(GetMemoryRouter()->FUN_008f6d30(1, 0x17));
        m_size = 1;
        m_capacityAndFlags = 1;
        m_data[0] = 0;
    }
    void Release()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int capacity = m_capacityAndFlags & 0x3fffffff;
            MemoryRouter* router = GetMemoryRouter();
            router->FUN_008f6d90(m_data, capacity, 0x17);
        }
    }
    void __cdecl FUN_009236d0(const char* format, ...) throw();
};

struct CommandProcess
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void ExecuteCommand(unsigned char command);
};

struct CommandMap
{
    int FUN_00922820(unsigned long key, CommandProcess** out);
};

struct CommandRouter
{
    int unk00;
    int unk04;
    CommandMap m_commandMap;

    hkBool FUN_00a61680(Stream* stream);
};

// pdb: hkCommandRouter::consumeCommands | hkCommandRouter.obj | fnv360_0822_retail, ustr, medium
// pdb params: stream
hkBool CommandRouter::FUN_00a61680(Stream* stream)
{
    unsigned char command;
    do
    {
        command = stream->read8u();
        if (command != 0xf0)
        {
            CommandProcess* process;
            if (m_commandMap.FUN_00922820(command, &process) == 0 && process)
            {
                process->ExecuteCommand(command);
            }
            else
            {
                hkQuadReal quad;
                if (command == 0xb0)
                {
                    stream->FUN_00a62980(&quad);
                    unsigned __int64 id = stream->read64u();
                }
                else if (command == 0xb1)
                {
                    stream->FUN_00a62980(&quad);
                }
                hkString text;
                text.Init();
                text.FUN_009236d0(DAT_00e86c60, command);
                text.Release();
            }
        }
    } while (stream->isOk() && command != 0xf0);
    return true;
}
}   // namespace f3m_00a61680

// @f3 0x00a67e10 (community match, verified in this file)
namespace f3m_00a67e10 {
namespace c_00a67e10 {

struct __declspec(align(16)) Vec
{
    float x;
    float y;
    float z;
    float w;
    Vec() {}
    Vec& operator=(const Vec& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
    void hkVector4_setTransformedPos(const struct Transform& t, const Vec& v);
};

struct Transform
{
    Vec rows[4];
};

struct VecArray
{
    Vec* data;
    int size;
    int capacityAndFlags;
};
void __cdecl FUN_00901e90(VecArray* array, int capacity, int elementSize);

struct Box
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Transform transform;
    Vec unk50;
    Vec halfExtents;
    void FUN_00a67e10(VecArray& lines);
};

// pdb: hkDisplayBox::getWireframeGeometry | hkDisplayBox.obj | fnv360_0822_retail, vtable, medium
// pdb params: lines, a
void Box::FUN_00a67e10(VecArray& lines)
{
    int capacity = lines.capacityAndFlags & 0x3fffffff;
    if (capacity < 24)
    {
        int grow = capacity * 2;
        FUN_00901e90(&lines, grow > 24 ? grow : 24, 16);
    }
    lines.size = 24;
    Vec corners[8];
    for (int i = 0; i < 8; i++)
    {
        Vec v = halfExtents;
        if (i & 1)
            v.x *= -1.0;
        if (i & 2)
            v.y *= -1.0;
        if (i & 4)
            v.z *= -1.0;
        corners[i].hkVector4_setTransformedPos(transform, v);
    }
    int k = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int bit = 1; bit < 8; bit += bit)
        {
            int j = bit ^ i;
            if (i < j)
            {
                lines.data[k++] = corners[i];
                lines.data[k++] = corners[j];
            }
        }
    }
}

}
}   // namespace f3m_00a67e10

// @f3 0x00a75dd0 (community match, verified in this file)
#include <math.h>
extern float DAT_010f3380;
extern float DAT_010f3384;
extern float DAT_010f3388;
extern double DAT_00e86160;
namespace f3m_00a75dd0 {
namespace f3m_00a75dd0 {
struct Vec3 { float x, y, z; };
struct __declspec(align(16)) Vec4 { float x, y, z, w; };


struct Shape {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    virtual void getDir(float t, Vec4* out);
    int u04, u08, u0c;
    Vec3 axis;
    void FUN_00a75dd0(float t, Vec4* out);
};
void Shape::FUN_00a75dd0(float t, Vec4* out)
{
    Vec4 v;
    getDir(t, &v);
    float dot = DAT_010f3380 * v.x + DAT_010f3384 * v.y + DAT_010f3388 * v.z;
    if (dot < DAT_00e86160)
    {
        const Vec4& a = v;
        const Vec3& b = axis;
        // Fake match: the y and z components are copied into named locals while x is read
        // through the reference. Only this form gives the operand order of the product
        // x * axis.z at +0x6d (x duplicated on the x87 stack, then multiplied from memory).
        float vy = a.y, vz = a.z;
        float nx = vy * b.z - vz * b.y;
        float ny = vz * b.x - a.x * b.z;
        float nz = a.x * b.y - vy * b.x;
        out->x = nx;
        out->y = ny;
        out->z = nz;
        out->w = 0.0f;
    }
    else
    {
        float ax = fabsf(v.x);
        float ay = fabsf(v.y);
        float az = fabsf(v.z);
        int i = 0, j = 1, k = 2;
        if (ay < ax) { ax = ay; j = 0; i = 1; }
        if (az < ax) { k = i; }
        out->x = out->y = out->z = out->w = 0.0f;
        (&out->x)[j] = (&v.x)[k];
        (&out->x)[k] = -(&v.x)[j];
    }
    float len = out->x * out->x + out->y * out->y + out->z * out->z;
    float inv = (len != 0.0f) ? (float)(1.0 / sqrt(len)) : 0.0f;
    out->x *= inv;
    out->y *= inv;
    out->z *= inv;
    out->w *= inv;
}
}
}   // namespace f3m_00a75dd0

// @f3 0x00a6ada0 (community match, verified in this file)
namespace f3m_00a6ada0 {
namespace c_00a6ada0 {

struct Rotation;

struct __declspec(align(16)) Vec
{
    float x;
    float y;
    float z;
    float w;
    Vec& operator=(const Vec& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
    void hkVector4_setRotatedDir(const Rotation& rotation, const Vec& v);
};

// Three columns, 48 bytes: the frame keeps 0x30 bytes for it.
struct __declspec(align(16)) Rotation
{
    Vec col0;
    Vec col1;
    Vec col2;
    void FUN_00924c60(const Vec& axis, float angle);
};

struct VecArray
{
    Vec* data;
    int size;
    int capacityAndFlags;
};
void __cdecl FUN_00901e90(VecArray* array, int capacity, int elementSize);

struct Arc
{
    int unk00[0x18];
    Vec axis;
    Vec startDir;
    Vec center;
    float startAngle;
    float endAngle;
    float radius;
    int numSegments;
    void FUN_00a6ada0(VecArray& points);
};

// pdb: hkDisplaySemiCircle::generatePoints | hkDisplaySemiCircle.obj | fnv360_0822_retail, call_seq, medium
// pdb params: points
void Arc::FUN_00a6ada0(VecArray& points)
{
    float step = (endAngle - startAngle) / numSegments;
    Rotation rotation;
    rotation.FUN_00924c60(axis, startAngle);
    Vec current;
    float r = radius;
    current.x = startDir.x * r;
    current.y = startDir.y * r;
    current.z = startDir.z * r;
    current.w = startDir.w * r;
    current.hkVector4_setRotatedDir(rotation, current);
    current.x = center.x + current.x;
    current.y = center.y + current.y;
    current.z = center.z + current.z;
    current.w = center.w + current.w;
    rotation.FUN_00924c60(axis, step);
    int count = numSegments + 2;
    int capacity = points.capacityAndFlags & 0x3fffffff;
    if (capacity < count)
    {
        int grow = capacity * 2;
        FUN_00901e90(&points, count < grow ? grow : count, 16);
    }
    points.size = count;
    points.data[0] = current;
    // Fake match: the loop reads the centre and the previous point through these two
    // references, not directly. The code is the same; it only makes the loop's operands
    // different expressions from the ones above, which decides which operand of each
    // addition is loaded first (the local first for z in the loop, the centre first elsewhere).
    const Vec& origin = center;
    Vec& previous = current;
    for (int i = 0; i <= numSegments; i++)
    {
        Vec next;
        next.x = previous.x - origin.x;
        next.y = previous.y - origin.y;
        next.z = previous.z - origin.z;
        next.w = previous.w - origin.w;
        next.hkVector4_setRotatedDir(rotation, next);
        next.x = origin.x + next.x;
        next.y = origin.y + next.y;
        next.z = origin.z + next.z;
        next.w = origin.w + next.w;
        points.data[i + 1] = next;
        current = next;
    }
}

}
}   // namespace f3m_00a6ada0

// @f3 0x00a7acf0 (community match, verified in this file)
namespace f3m_00a7acf0 {
// Right-hand side of one angular motor row of a powered chain link: the damped relative angular velocity
// plus the accumulated (summed) angular velocity scaled by the solver factor and tau, subtracted from the
// motor target, written to the angular part of the link's output pair.
namespace hk_00a7acf0 {
struct __declspec(align(16)) Vector
{
    float x, y, z, w;
    void setSub4(const Vector& a, const Vector& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    void setMul4(const Vector& a, const Vector& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    void mul4(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    void setMul4(float s, const Vector& a)
    {
        x = s * a.x;
        y = s * a.y;
        z = s * a.z;
        w = s * a.w;
    }
    void setAdd4(const Vector& a, const Vector& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    float horizontalAdd3() const
    {
        return y + x + z;
    }
    float& operator()(int i)
    {
        return ((float*)this)[i];
    }
    const float& operator()(int i) const
    {
        return ((const float*)this)[i];
    }
};

struct Accumulator
{
    Vector unk00;
    Vector unk10;
    Vector m_angularVel;
    Vector unk30;
    Vector unk40;
    Vector m_sumAngularVel;
    const Vector& getSumAngularVel() const
    {
        return m_sumAngularVel;
    }
};

struct AngularJacobian
{
    Vector m_angularA;
    Vector m_angularB;
};

struct AxisMotor
{
    float m_maxImpulse;
    float m_minImpulse;
    float m_velocity;
    float m_tau;
    float m_damping;
};

struct LinkMotor
{
    unsigned char m_state;
    AxisMotor m_axes[3];
};

struct SolverInfo
{
    Vector unk00;
    Vector unk10;
    Vector unk20;
    Vector unk30;
    float m_factor;
};

struct AccumulatorOffset
{
    int m_bytes;
};

struct ChainSolverState
{
    SolverInfo* m_solver;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    AngularJacobian* m_jacobians;
    AccumulatorOffset* m_offsets;
    Accumulator* m_base;
    int unk20;
    LinkMotor* m_motors;
};

struct VelocityPair
{
    Vector m_linear;
    Vector m_angular;
};

// pdb: hkPoweredChain_RestoreVelocityValue | hkpPoweredChainSolverUtil.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: modifiedConstraintIndex, modifiedCoordinateIndex, info, velocities
void FUN_00a7acf0(int link, int axis, ChainSolverState* info, VelocityPair* output)
{
    // Note: the number of named locals in this block decides the operand order of the first x87 product of
    // each block below (three are needed; with fewer the x lane loads the stack operand first).
    const int offsetA = info->m_offsets[link].m_bytes;
    const int offsetB = info->m_offsets[link + 1].m_bytes;
    const Accumulator& a = *(const Accumulator*)((const char*)info->m_base + offsetA);
    const Accumulator& b = *(const Accumulator*)((const char*)info->m_base + offsetB);
    const LinkMotor& motor = info->m_motors[link];
    const int jacobianIndex = axis + link * 3;
    const AngularJacobian& j = info->m_jacobians[jacobianIndex];
    const float tau = motor.m_axes[axis].m_tau;

    Vector velocities;
    {
        Vector relA, relB, partA, partB;
        relA.setSub4(a.m_angularVel, a.getSumAngularVel());
        relB.setSub4(b.m_angularVel, b.getSumAngularVel());
        partA.setMul4(relA, j.m_angularA);
        partB.setMul4(relB, j.m_angularB);
        velocities.setAdd4(partA, partB);
    }
    Vector sums;
    {
        const Vector sumA = a.getSumAngularVel();
        const Vector sumB = b.getSumAngularVel();
        Vector partA, partB;
        partA.setMul4(sumA, j.m_angularA);
        partB.setMul4(sumB, j.m_angularB);
        sums.setAdd4(partA, partB);
    }
    sums.mul4(info->m_solver->m_factor * tau);
    velocities.setMul4(motor.m_axes[axis].m_damping, velocities);
    Vector total;
    total.setAdd4(sums, velocities);
    float dot = total.horizontalAdd3();
    float result = j.m_angularB(3) * tau - dot;
    output[link].m_angular(axis) = result;
}
}  // namespace hk_00a7acf0
}   // namespace f3m_00a7acf0

// @f3 0x00a75380 (community match, verified in this file)
#include <math.h>
extern const float DAT_00dbea4c;
namespace f3m_00a75380 {
namespace N00a75380 {
int __cdecl FUN_00954d20(float t);
__forceinline float sqrtInvQ(float r) { return 1.0f / (float)sqrt(r); }
struct __declspec(align(16)) VecQ
{
    float x, y, z, w;
    void setSub4(const VecQ& a, const VecQ& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    float dot3(const VecQ& a) const { return x * a.x + y * a.y + z * a.z; }
    float lengthSquared3() const { return x * x + y * y + z * z; }
    void mul4(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void normalize3()
    {
        float l2 = lengthSquared3();
        mul4(l2 ? sqrtInvQ(l2) : 0.0f);
    }
    void setInterpolate4(const VecQ& a, const VecQ& b, float t)
    {
        float s = 1.0f - t;
        x = s * a.x + t * b.x;
        y = s * a.y + t * b.y;
        z = s * a.z + t * b.z;
        w = s * a.w + t * b.w;
    }
};
struct ArrayQ
{
    VecQ* data;
    int size;
    int capacity;
    int getSize() const { return size; }
    VecQ& operator[](int i) { return data[i]; }
};
struct CurveQ
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual float FUN_00a75380(float t, const VecQ& nearPoint, VecQ& pointOnCurve);
    int unk04;
    int unk08;
    bool closedLoop;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    ArrayQ points;
};
// pdb: hkpLinearParametricCurve::getNearestPoint | hkpLinearParametricCurve.obj | tesv_win, objopen_prop, low
float CurveQ::FUN_00a75380(float t, const VecQ& nearPoint, VecQ& pointOnCurve)
{
    if (t < 0.0f)
    {
        t = 0.0f;
    }
    int ia = FUN_00954d20(t);
    int ib = ia + 1;
    if (ib >= points.getSize())
    {
        ib = points.getSize() - 1;
        ia = ib - 1;
    }

    float fraction = 0.0f;
    while (1)
    {
        VecQ dir;
        dir.setSub4(points[ib], points[ia]);
        VecQ a;
        a.setSub4(nearPoint, points[ia]);
        float num = a.dot3(dir);
        float den = dir.dot3(dir);
        fraction = num / den;
        if (fraction < 0.0f)
        {
            if (ia == 0)
            {
                break;
            }
            ia--;
            ib--;
            continue;
        }
        VecQ b;
        b.setSub4(nearPoint, points[ib]);
        int ic = ib + 1;
        if (!(b.dot3(dir) <= 0.0f) && ic < points.getSize())
        {
            VecQ dir1;
            dir1.setSub4(points[ic], points[ib]);
            if (dir1.dot3(b) > 0.0f)
            {
                ia++;
                ib++;
                continue;
            }
            dir.normalize3();
            dir1.normalize3();
            float fDot0 = dir.dot3(b);
            float fDot1 = dir1.dot3(b);
            if (-fDot1 > fDot0)
            {
                fraction = 0.99f;
            }
            else
            {
                fraction = 0.01f;
                ia++;
                ib++;
            }
        }
        break;
    }

    float result = (float)ia + fraction;
    // Fake match: three named copies of the fraction. They add no code; they only change the
    // compiler's internal numbering before the interpolate helper is expanded, which decides
    // whether the first product (one minus fraction times the start point's x at +0x3e6) loads
    // the scalar first and multiplies from memory, as the original does.
    float d0 = fraction;
    float d1 = d0;
    float d2 = d1;
    pointOnCurve.setInterpolate4(points[ia], points[ib], d2);
    if (closedLoop)
    {
        float end = (float)(points.getSize() - 1);
        // The first 0.25 is a named float constant in the image (not the literal pool), loaded before the result.
        if (DAT_00dbea4c > result)
        {
            result = FUN_00a75380(end - (1.0f - result), nearPoint, pointOnCurve);
        }
        else if (result > end - 0.25)
        {
            result = FUN_00a75380(1.0f - (end - result), nearPoint, pointOnCurve);
        }
    }
    return result;
}
}
}   // namespace f3m_00a75380

// @f3 0x00a7da50 (community match, verified in this file)
#include <math.h>
namespace f3m_00a7da50 {

namespace N00a7da50 {

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal sqrt(hkReal r) { return (hkReal)::sqrt(r); }
    __forceinline hkReal min2(hkReal x, hkReal y) { return x < y ? x : y; }
    __forceinline hkReal max2(hkReal x, hkReal y) { return x > y ? x : y; }
}

struct hkMatrix3;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void setZero4()
    {
        x = 0;
        y = 0;
        z = 0;
        w = 0;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void mul4(hkReal rs)
    {
        hkReal r = rs;
        x *= r;
        y *= r;
        z *= r;
        w *= r;
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void subMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x -= r * a.x;
        y -= r * a.y;
        z -= r * a.z;
        w -= r * a.w;
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
    __forceinline void sub4(const hkVector4& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        w -= a.w;
    }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& b);
    __forceinline void _setRotatedInverseDir(const hkMatrix3& r, const hkVector4& b);
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    w = 0;
}

__forceinline void hkVector4::_setRotatedInverseDir(const hkMatrix3& r, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(1, 0) * v1 + r(2, 0) * v2;
    y = r(0, 1) * v0 + r(1, 1) * v1 + r(2, 1) * v2;
    z = r(0, 2) * v0 + r(1, 2) * v1 + r(2, 2) * v2;
    w = 0;
}

struct hkBool
{
    char m_bool;
    __forceinline hkBool& operator=(bool e)
    {
        m_bool = static_cast<char>(e);
        return *this;
    }
};

struct BodyVelocity
{
    hkVector4 m_linear;
    hkVector4 m_angular;
};

struct ConstraintInfo
{
    hkMatrix3 m_angularA;      // 0x000
    hkVector4 unk030;
    hkVector4 unk040;
    hkVector4 unk050;
    hkVector4 unk060;
    hkMatrix3 m_angularB;      // 0x070
    hkVector4 unk0a0;
    hkVector4 unk0b0;
    hkVector4 unk0c0;
    hkVector4 unk0d0;
    hkMatrix3 m_base;          // 0x0e0
    hkMatrix3 m_massMatrix;    // 0x110
    hkMatrix3 m_invMassMatrix; // 0x140
};

struct CollideParams
{
    hkReal unk00;
    hkReal unk04;
    hkReal unk08;
    hkReal unk0c;
    hkReal m_friction;                   // 0x10
    hkReal m_restitution;                // 0x14
    hkReal m_maxImpulse;                 // 0x18
    hkReal m_externalSeparatingVelocity; // 0x1c
    hkReal m_extraSeparatingVelocity;    // 0x20
    hkReal m_extraSlope;                 // 0x24
    hkBool m_contactImpulseLimitBreached;  // 0x28
};

// Relative velocity of the two bodies at the contact point, in the contact's own frame.
__declspec(noinline) void __cdecl FUN_00a7d850(const ConstraintInfo& info, BodyVelocity& velA, BodyVelocity& velB, hkVector4& out)
{
    hkVector4 angular;
    angular._setMul3(info.m_angularA, velA.m_angular);
    hkVector4 angularB;
    angularB._setMul3(info.m_angularB, velB.m_angular);
    hkVector4 linear;
    linear.setSub4(velA.m_linear, velB.m_linear);
    angular.sub4(angularB);
    linear._setRotatedInverseDir(info.m_base, linear);
    out.setAdd4(linear, angular);
}
void __cdecl FUN_00a7d5c0(const ConstraintInfo& info, const hkVector4& imp, BodyVelocity& velA, BodyVelocity& velB);

}

using namespace N00a7da50;

hkReal __cdecl FUN_00a7da50(const ConstraintInfo& info, CollideParams& params, BodyVelocity& velA, BodyVelocity& velB)
{
    hkVector4 delta;
    FUN_00a7d850(info, velA, velB, delta);

    if (delta(0) > params.m_externalSeparatingVelocity)
    {
        delta(0) = params.m_externalSeparatingVelocity;
        if (params.m_externalSeparatingVelocity >= params.m_extraSeparatingVelocity)
        {
            return 0.0f;
        }
    }

    delta.setNeg4(delta);
    delta(0) *= (1.0 + params.m_restitution);
    delta(0) += params.m_extraSeparatingVelocity;

    hkVector4 imp;
    imp._setMul3(info.m_invMassMatrix, delta);

    hkReal maxImpulse = params.m_maxImpulse;
    params.m_contactImpulseLimitBreached = false;
    if (imp(0) > maxImpulse)
    {
        hkReal factor = maxImpulse / imp(0);
        params.m_contactImpulseLimitBreached = true;
        imp.mul4(factor);
        delta.mul4(factor);
    }

    hkVector4 impSqrd;
    impSqrd.setMul4(imp, imp);

    hkReal tangSqrd = impSqrd(1) + impSqrd(2);
    hkReal maxTangSqrd = params.m_friction * params.m_friction * impSqrd(0);
    if (tangSqrd > maxTangSqrd)
    {
        hkReal normalVel = delta(0);
        hkReal vy = delta(1);
        hkReal vz = delta(2);
        hkReal initialTangSqrd = vy * vy + vz * vz;
        imp.setZero4();

        hkReal normal = normalVel * info.m_massMatrix(3, 0);
        imp(0) += normal;
        delta.subMul4(normal, info.m_massMatrix.getColumn(0));

        hkReal t1 = (info.m_massMatrix(1, 1) * delta(1) - info.m_massMatrix(1, 2) * delta(2)) * info.m_massMatrix(3, 1);
        hkReal t2 = (info.m_massMatrix(2, 2) * delta(2) - info.m_massMatrix(1, 2) * delta(2)) * info.m_massMatrix(3, 1);
        hkReal lenSqrd = t1 * t1 + t2 * t2;
        hkReal maxTang = params.m_friction * imp(0);
        hkReal maxTangSq = maxTang * maxTang;
        if (lenSqrd > maxTangSq)
        {
            hkReal f = hkMath::sqrt(maxTangSq / lenSqrd);
            t1 *= f;
            t2 *= f;
        }
        imp(1) = t1;
        imp(2) = t2;
        delta.subMul4(imp(1), info.m_massMatrix.getColumn(1));
        delta.subMul4(imp(2), info.m_massMatrix.getColumn(2));

        hkReal extra = delta(0) * info.m_massMatrix(3, 0);
        hkReal extraImp = hkMath::max2(0.0f, extra);
        imp(0) += extraImp;
        delta.subMul4(extraImp, info.m_massMatrix.getColumn(0));

        hkReal remY = delta(1);
        hkReal remZ = delta(2);
        hkReal remTangSqrd = remY * remY + remZ * remZ;
        remTangSqrd = hkMath::min2(remTangSqrd, initialTangSqrd);
        imp(0) += hkMath::sqrt(remTangSqrd) * info.m_massMatrix(3, 0) * params.m_extraSlope;
    }

    FUN_00a7d5c0(info, imp, velA, velB);
    return imp(0);
}
}   // namespace f3m_00a7da50

// @f3 0x00a7e0c0 (community match, verified in this file)
namespace f3m_00a7e0c0 {
namespace Shape516
{
struct __declspec(align(16)) Vector
{
    float x, y, z, w;
    inline float& operator()(int i) { return (&x)[i]; }
    inline float operator()(int i) const { return (&x)[i]; }
    inline void SetSub4(const Vector& a, const Vector& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
};
struct Rotation
{
    Vector column[3];
    inline const Vector& GetColumn(int i) const { return column[i]; }
    inline float operator()(int r, int c) const { return GetColumn(c)(r); }
};
struct Transform
{
    Rotation rotation;
    Vector translation;
    inline const Vector& GetColumn(int i) const { return rotation.GetColumn(i); }
    inline float operator()(int r, int c) const { return rotation(r, c); }
};
struct Vec4 : Vector
{
    __forceinline void SetRotatedInverseDir(const Rotation& r, const Vector& v)
    {
        float v0 = v.x;
        float v1 = v.y;
        float v2 = v.z;
        // Fake match: the last factor is read through the by-value element accessor instead of the
        // named copy v2; this alone sets the load order of the y-row products here and in the transform.
        x = r.column[0].x * v0 + r.column[0].y * v1 + r.column[0].z * v(2);
        // Fake match: this one element is read through the column accessor, the other eight as members;
        // it turns the second-shape y product of the transform (element at +0x24) element-first.
        y = r.column[1].x * v0 + r.column[1].y * v1 + r.GetColumn(1)(2) * v2;
        z = r.column[2].x * v0 + r.column[2].y * v1 + r.column[2].z * v2;
        w = 0.0f;
    }
    __forceinline void SetTransformedPos(const Transform& t, const Vector& v)
    {
        float v0 = v.x;
        float v1 = v.y;
        float v2 = v.z;
        x = t.rotation.column[0].x * v0 + t.rotation.column[1].x * v1 + t.rotation.column[2].x * v2 + t.translation.x;
        y = t.rotation.column[0].y * v0 + t.rotation.column[1].y * v1 + t.rotation.column[2].y * v2 + t.translation.y;
        z = t.rotation.column[0].z * v0 + t.rotation.column[1].z * v1 + t.rotation.column[2].z * v2 + t.translation.z;
        w = 0.0f;
    }
};
struct Result
{
    Vector difference, first, second;
};
struct Shape
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Support(const Vector&, Vector&);
};
struct Owner
{
    Transform transform;
    int unk40, unk44, unk48, unk4c, unk50;
    Shape* first;
    Shape* second;
    void FUN_00a7e0c0(const Vector&, Result&);
};
// pdb: hkpConvexPenetrationUtil::getPointForSimplex | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, call_dedup, low
// pdb params: direction, result
void Owner::FUN_00a7e0c0(const Vector& direction, Result& result)
{
    first->Support(direction, result.first);
    Vec4 negDir;
    negDir.x = -direction.x;
    negDir.y = -direction.y;
    negDir.z = -direction.z;
    Vec4 dirB;
    dirB.SetRotatedInverseDir(transform.rotation, negDir);
    second->Support(dirB, result.second);
    Vec4 secondInA;
    secondInA.SetTransformedPos(transform, result.second);
    result.difference.SetSub4(result.first, secondInA);
}
}
}   // namespace f3m_00a7e0c0

// @f3 0x00a7d5c0 (community match, verified in this file)
namespace f3m_00a7d5c0 {
// 0x00a7d5c0 (644 B): applies an impulse to two bodies. The impulse rotated by the base matrix changes both
// linear velocities (scaled by each inverse mass); each inverse inertia matrix times the impulse changes the
// angular velocity of its body; the four w components are cleared.
// The pack lists /Od, but the original is optimised (aligned frame, every vector helper inlined): this source
// matches under /MT /O2 /GS /EHsc /Gy.
// The in-place add goes through a three-operand add written on indexed element accessors; the subtract and the
// scaled helpers use named members; the matrix product reads through element accessors.
namespace Na7d5c0 {
typedef float hkReal;
struct hkMatrix3;
struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b) { (*this)(0) = a(0) + b(0); (*this)(1) = a(1) + b(1); (*this)(2) = a(2) + b(2); (*this)(3) = a(3) + b(3); }
    __forceinline void add4(const hkVector4& a) { setAdd4(*this, a); }
    __forceinline void sub4(const hkVector4& a) { x -= a.x; y -= a.y; z -= a.z; w -= a.w; }
    // Fake match: the scale factor of the scaled add and subtract is taken as a double and narrowed into
    // a float local. A float parameter gives the same instructions with two angular add lanes exchanged.
    __forceinline void addMul4(double rs, const hkVector4& a) { float r = (float)rs; x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
    __forceinline void subMul4(double rs, const hkVector4& a) { float r = (float)rs; x -= r * a.x; y -= r * a.y; z -= r * a.z; w -= r * a.w; }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkMatrix3& r, const hkVector4& v);
};
struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
};
__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    w = 0;
}
__forceinline void hkVector4::_setRotatedDir(const hkMatrix3& r, const hkVector4& v)
{
    _setMul3(r, v);
}
struct BodyInfo
{
    hkVector4 m_unk00;
    hkVector4 m_unk10;
    hkVector4 m_unk20;
    hkMatrix3 m_invInertia;
    float m_invMass;
    int unk64;
    int unk68;
    int unk6c;
};
struct ConstraintInfo
{
    BodyInfo m_bodyInfo[2];
    hkMatrix3 m_base;
    hkVector4 m_unk110;
};
struct BodyVelocity
{
    hkVector4 m_linear;
    hkVector4 m_angular;
};
}
using namespace Na7d5c0;

void __cdecl FUN_00a7d5c0(const ConstraintInfo& info, const hkVector4& impulse, BodyVelocity& velA, BodyVelocity& velB)
{
    hkVector4 linear;
    linear._setRotatedDir(info.m_base, impulse);
    velA.m_linear.addMul4(info.m_bodyInfo[0].m_invMass, linear);
    velB.m_linear.subMul4(info.m_bodyInfo[1].m_invMass, linear);
    hkVector4 angularA;
    angularA._setMul3(info.m_bodyInfo[0].m_invInertia, impulse);
    velA.m_angular.add4(angularA);
    hkVector4 angularB;
    angularB._setMul3(info.m_bodyInfo[1].m_invInertia, impulse);
    velB.m_angular.sub4(angularB);
    velA.m_angular.w = 0.0f;
    velB.m_angular.w = 0.0f;
    velA.m_linear.w = 0.0f;
    velB.m_linear.w = 0.0f;
}
}   // namespace f3m_00a7d5c0

// @f3 0x00a75860 (community match, verified in this file)
#include <math.h>
namespace f3m_00a75860 {
int __cdecl FUN_00954d20(float);
namespace N00a75860 {

typedef float hkReal;

__forceinline hkReal sqrtInverse(hkReal r)
{
    hkReal s = (hkReal)sqrt(r);
    return 1.0f / s;
}

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = x * x + y * y + z * z;
        return (l2 != 0.0f) ? sqrtInverse(l2) : 0.0f;
    }
    __forceinline void mul4(hkReal rs)
    {
        hkReal s = rs;
        (*this)(0) *= s;
        (*this)(1) *= s;
        (*this)(2) *= s;
        (*this)(3) *= s;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline void setInterpolate4(const hkVector4& a, const hkVector4& b, hkReal tt)
    {
        hkReal t = tt;
        hkReal s = 1.0f - t;
        (*this)(0) = s * a(0) + t * b(0);
        (*this)(1) = s * a(1) + t * b(1);
        (*this)(2) = s * a(2) + t * b(2);
        (*this)(3) = s * a(3) + t * b(3);
    }
};


struct hkpLinearParametricCurve
{
    int unk00;
    int unk04;
    hkReal m_smoothingFactor;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4* m_points;
    int m_numPoints;

    void FUN_00a75860(hkReal t, hkVector4& tangent);
};

// pdb: hkpLinearParametricCurve::getTangent | hkpLinearParametricCurve.obj | tesv_win, objopen_prop, low
void hkpLinearParametricCurve::FUN_00a75860(hkReal t, hkVector4& tangent)
{
    hkReal smooth_tol = m_smoothingFactor;
    hkReal smooth_tol_inv = 1.0f / smooth_tol;

    int ia = FUN_00954d20(t);
    int ib = ia + 1;

    if (ib >= m_numPoints)
    {
        ib = m_numPoints - 1;
        ia = ib - 1;
    }
    else if (ia < 0)
    {
        ia = 0;
        ib = 1;
    }

    tangent.setSub4(m_points[ib], m_points[ia]);
    tangent.normalize3();

    hkReal ptol = t - ia;
    if (ptol < smooth_tol && ia > 0)
    {
        ia--;
        ib--;
        hkVector4 tangent2;
        tangent2.setSub4(m_points[ib], m_points[ia]);
        tangent2.normalize3();
        hkReal interp = (smooth_tol - ptol) * 0.5 * smooth_tol_inv;
        tangent.setInterpolate4(tangent, tangent2, interp);
        tangent.normalize3();
    }

    ptol = ib - t;
    if (ptol < smooth_tol && ib < m_numPoints - 1)
    {
        hkVector4 tangent2;
        tangent2.setSub4(m_points[ib + 1], m_points[ia + 1]);
        tangent2.normalize3();
        hkReal interp = (smooth_tol - ptol) * 0.5 * smooth_tol_inv;
        tangent.setInterpolate4(tangent, tangent2, interp);
        tangent.normalize3();
    }
}

}
}   // namespace f3m_00a75860

// @f3 0x00a72450 (community match, verified in this file)
#include <math.h>
namespace f3m_00a72450 {
// Real flags /MT /O2 /GS /EHsc /Gy (listed /Od). 12 diff lines: inlined cross-product products load the other memory operand first (same pattern as 0x924ca0/0x924760).
struct TransformA724;
struct __declspec(align(16)) VecA724 {
 float x,y,z,w;
 void FUN_008d2970(const TransformA724&,const VecA724&);
 void FUN_00477880(const TransformA724&,const VecA724&);
 void Zero() {x=0.0f;y=0.0f;z=0.0f;w=0.0f;}
 float& operator()(int i) {float* p=&x;return p[i];}
 const float& operator()(int i) const {const float* p=&x;return p[i];}
 void SetAll(float f) {x=f;y=f;z=f;w=f;}
 void Mul4(const VecA724& v) {x*=v.x;y*=v.y;z*=v.z;w*=v.w;}
 __forceinline void Normalize() {
  float sum=x*x+y*y+z*z;
  float scale;
  if(sum!=0.0f) {float length=sqrtf(sum);scale=1.0f/length;}
  else scale=0.0f;
  VecA724 s;s.SetAll(scale);
  Mul4(s);
 }
 __forceinline void Cross(const VecA724& b,const VecA724& a) {
  float ny=a.z*b.x-a.x*b.z;
  float nz=a.x*b.y-a.y*b.x;
  float nx=a.y*b.z-a.z*b.y;
  x=nx;y=ny;z=nz;w=0.0f;
 }
};
struct RotA724 { VecA724 col0,col1,col2; VecA724& Column(int i) {return (&col0)[i];} };
struct TransformA724 {RotA724 rotation;VecA724 translation;};
static inline float AbsA724(float v) {return (float)fabs(v);}
static __forceinline void PerpA724(const VecA724& in,VecA724& out) {
 int minIdx=0;
 int ok1=1;
 int ok2=2;
 float a0=AbsA724(in(0));
 float a1=AbsA724(in(1));
 float a2=AbsA724(in(2));
 if(a1<a0) {ok1=0;minIdx=1;a0=a1;}
 if(a2<a0) {ok2=minIdx;minIdx=2;}
 out.x=out.y=out.z=out.w=0.0f;
 out(ok1)=in(ok2);
 out(ok2)=-in(ok1);
}

struct PlaneA724 {
 unsigned field00,field04,field08,field0c,field10,field14,field18,field1c;
 VecA724 basisX,basisY,basisZ,pivotA;
 RotA724 axes;
 VecA724 pivotB;
 unsigned short fielda0;
 unsigned char axis;
 void FUN_00a72450(const TransformA724&,const TransformA724&,const VecA724&,const VecA724&);
};
void PlaneA724::FUN_00a72450(const TransformA724& a,const TransformA724& b,const VecA724& pivot,const VecA724& normal) {
 pivotA.FUN_008d2970(a,pivot);
 pivotB.FUN_008d2970(b,pivot);
 basisX.Zero();basisY.Zero();basisZ.Zero();
 basisX(0)=1.0f;basisY(1)=1.0f;basisZ(2)=1.0f;
 int n=axis;
 RotA724& rot=axes;
 rot.Column(n).FUN_00477880(b,normal);
 int i1=(n+1)%3;
 PerpA724(rot.Column(n),rot.Column(i1));
 rot.Column(i1).Normalize();
 int i2=(n+2)%3;
 rot.Column(i2).Cross(rot.Column(i1),rot.Column(n));
}
}   // namespace f3m_00a72450

// @f3 0x00a72c90 (community match, verified in this file)
#include <math.h>
namespace f3m_00a72c90 {
// 0x00a72c90: hkpMultiRayShape::hkpMultiRayShape(const Ray* rays, int nRays, hkReal rayPenetrationDistance) of
// Havok 5.5.0 (hkpCollide, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Copies the rays into the shape's array; each ray keeps its length in the w of its start point and its end
// point is pushed out along the ray by the penetration distance.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector helpers, the array's
// constructor, expandBy, setSize and reserve, the base class constructors) follow the SDK's inline code. The
// constructor's own body is written from the game's code.

namespace f3m_00a72c90 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned long hkUlong;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}  // namespace hkMath

struct hkVector4
{
    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline void add4(const hkVector4& v);
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline hkSimdReal length3() const;
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3();

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::add4(const hkVector4& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline hkSimdReal hkVector4::length3() const
{
    return hkMath::sqrt((x * x) + (y * y) + (z * z));
}

__forceinline hkSimdReal hkVector4::lengthInverse3() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

__forceinline void hkVector4::normalize3()
{
    this->mul4(this->lengthInverse3());
}

namespace hkArrayUtil {
// _reserve: grows the array's storage to numElem elements of sizeElem bytes
void __cdecl FUN_00901e90(void* array, int numElem, int sizeElem) throw();
}  // namespace hkArrayUtil

template <typename T>
class hkArray
{
public:
    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}

    __forceinline int getCapacity() const { return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK)); }
    __forceinline void reserve(int n);
    __forceinline void setSize(int n);
    __forceinline T* expandBy(int n);

    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        DONT_DEALLOCATE_FLAG = int(0x80000000),
    };

protected:
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int cap2 = 2 * capacity;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil::FUN_00901e90(this, newSize, sizeof(T));
    }
}

template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
    reserve(n);
    m_size = n;
}

template <typename T>
__forceinline T* hkArray<T>::expandBy(int n)
{
    int oldsize = m_size;
    setSize(oldsize + n);
    return m_data + oldsize;
}

class hkBaseObject
{
public:
    virtual ~hkBaseObject();
};

class hkReferencedObject : public hkBaseObject
{
public:
    __forceinline hkReferencedObject() : m_referenceCount(1) {}

    hkUint16 m_memSizeAndFlags;
    hkInt16 m_referenceCount;
};

enum hkpShapeType
{
    HK_SHAPE_MULTI_RAY = 23,
};

class hkpShape : public hkReferencedObject
{
public:
    __forceinline hkpShape(hkpShapeType type)
    {
        m_userData = 0;
        m_type = type;
    }

    hkUlong m_userData;
    hkpShapeType m_type;
};

class hkpMultiRayShape : public hkpShape
{
public:
    struct Ray
    {
        hkVector4 m_start;
        hkVector4 m_end;
    };

    hkpMultiRayShape(const Ray* rays, int nRays, hkReal rayPenetrationDistance);
    virtual ~hkpMultiRayShape();

    hkArray<Ray> m_rays;
    hkReal m_rayPenetrationDistance;
};

hkpMultiRayShape::hkpMultiRayShape(const Ray* rays, int nRays, hkReal rayPenetrationDistance)
    : hkpShape(HK_SHAPE_MULTI_RAY)
{
    m_rayPenetrationDistance = rayPenetrationDistance;

    Ray* ray = m_rays.expandBy(nRays);
    for (int i = nRays - 1; i >= 0; i--)
    {
        *ray = *rays;

        // the ray's length goes into the w of its start point
        hkVector4 diff;
        diff.setSub4(ray->m_end, ray->m_start);
        ray->m_start(3) = diff.length3();

        // the end point moves out by the penetration distance
        diff.normalize3();
        diff.mul4(m_rayPenetrationDistance);
        ray->m_end.add4(diff);

        ray++;
        rays++;
    }
}

}  // namespace f3m_00a72c90
}   // namespace f3m_00a72c90

// @f3 0x00a74910 (community match, verified in this file)
namespace f3m_00a74910 {
// 0x00a74910: hkpPointToPathConstraintData::setInWorldSpace(const hkTransform& slidingBodyTransform,
// const hkTransform& referenceBodyTransform, const hkVector4& pivotWs, hkpParametricCurve* path,
// const hkTransform& pathToRefBodyTransform) of Havok 5.5.0 (hkpDynamics, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Takes over the path, stores the path's transform in the reference body's space, finds the point of the path
// nearest to the pivot and builds the constraint's frame there (the path's tangent, its binormal and their cross
// product, placed at the pivot in path space), then stores that frame in the sliding body's space.
// Class and member names follow the Havok 5.5.0 SDK headers; the inline helpers (reference counting, the vector
// and matrix helpers) follow the SDK's inline code. The function's own body is written from the game's code.
namespace f3m_00a74910 {

typedef float hkReal;
typedef signed char hkInt8;
typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned long hkUlong;

struct hkTransform;

struct hkVector4
{
    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);

    // setTransformedInversePos
    void FUN_008d2970(const hkTransform& a, const hkVector4& b);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

struct hkMatrix3
{
    __forceinline void setCols(const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

__forceinline void hkMatrix3::setCols(const hkVector4& r0, const hkVector4& r1, const hkVector4& r2)
{
    m_col0 = r0;
    m_col1 = r1;
    m_col2 = r2;
}

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkRotation& getRotation() { return m_rotation; }
    __forceinline void setTranslation(const hkVector4& t) { m_translation = t; }

    // the assignment, kept out of line
    hkTransform& FUN_008fda60(const hkTransform& t);
    // setMul: this = t1 * t2
    void hkTransform_setMul(const hkTransform& t1, const hkTransform& t2);
    // setMulInverseMul: this = inverse(bTa) * bTc
    void FUN_00925300(const hkTransform& bTa, const hkTransform& bTc);

    hkRotation m_rotation;
    hkVector4 m_translation;
};

class hkReferencedObject
{
public:
    virtual ~hkReferencedObject();
    virtual void calcStatistics(void* collector) const;
    virtual void calcContentStatistics(void* collector, const void* cls) const;

    // objects with m_memSizeAndFlags == 0 are not reference counted
    __forceinline void addReference() const
    {
        if (m_memSizeAndFlags != 0)
        {
            ++m_referenceCount;
        }
    }
    __forceinline void removeReference() const
    {
        if (m_memSizeAndFlags != 0)
        {
            --m_referenceCount;
            if (m_referenceCount == 0)
            {
                delete this;
            }
        }
    }

    hkUint16 m_memSizeAndFlags;
    mutable hkInt16 m_referenceCount;
};

class hkpParametricCurve : public hkReferencedObject
{
public:
    virtual void getPoint(hkReal t, hkVector4& pointOnCurve) const;
    virtual hkReal getNearestPoint(hkReal t, const hkVector4& nearPoint, hkVector4& pointOnPath) const;
    virtual void getTangent(hkReal t, hkVector4& tangent) const;
    virtual hkReal getStart() const;
    virtual hkReal getEnd() const;
    virtual hkReal getLengthFromStart(hkReal t) const;
    virtual void getBinormal(hkReal t, hkVector4& up) const;
};

class hkpConstraintData : public hkReferencedObject
{
public:
    hkUlong m_userData;
};

struct hkpConstraintAtom
{
    hkUint16 m_type;
};

struct hkpBridgeConstraintAtom : hkpConstraintAtom
{
    void* m_buildJacobianFunc;
    hkpConstraintData* m_constraintData;
};

struct hkpBridgeAtoms
{
    hkpBridgeConstraintAtom m_bridgeAtom;
};

class hkpPointToPathConstraintData : public hkpConstraintData
{
public:
    // setInWorldSpace
    void FUN_00a74910(const hkTransform& slidingBodyTransform, const hkTransform& referenceBodyTransform,
                      const hkVector4& pivotWs, hkpParametricCurve* path, const hkTransform& pathToRefBodyTransform);

    hkpBridgeAtoms m_atoms;
    hkpParametricCurve* m_path;
    hkReal m_maxFrictionForce;
    hkInt8 m_angularConstrainedDOF;
    hkTransform m_transform_OS_KS[2];
};

void hkpPointToPathConstraintData::FUN_00a74910(const hkTransform& slidingBodyTransform,
                                                const hkTransform& referenceBodyTransform,
                                                const hkVector4& pivotWs, hkpParametricCurve* path,
                                                const hkTransform& pathToRefBodyTransform)
{
    // take over the path
    if (path)
    {
        path->addReference();
    }
    if (m_path)
    {
        m_path->removeReference();
    }
    m_path = path;

    m_transform_OS_KS[1].FUN_008fda60(pathToRefBodyTransform);

    // the pivot in path space
    hkTransform pathToWorld;
    pathToWorld.hkTransform_setMul(referenceBodyTransform, pathToRefBodyTransform);
    hkVector4 pivotInPath;
    pivotInPath.FUN_008d2970(pathToWorld, pivotWs);

    // the constraint's frame at the path's nearest point: tangent, binormal and their cross product
    hkReal t = m_path->getNearestPoint(0.0f, pivotInPath, pivotInPath);
    hkVector4 tangent;
    m_path->getTangent(t, tangent);
    hkVector4 binormal;
    m_path->getBinormal(t, binormal);
    hkVector4 normal;
    normal.setCross(tangent, binormal);

    hkTransform constraintToPath;
    constraintToPath.getRotation().setCols(tangent, binormal, normal);
    constraintToPath.setTranslation(pivotInPath);

    // and that frame in the sliding body's space
    hkTransform constraintToRefBody;
    constraintToRefBody.hkTransform_setMul(pathToRefBodyTransform, constraintToPath);
    pathToWorld.hkTransform_setMul(referenceBodyTransform, constraintToRefBody);
    hkTransform constraintToSlidingBody;
    constraintToSlidingBody.FUN_00925300(slidingBodyTransform, pathToWorld);
    m_transform_OS_KS[0].FUN_008fda60(constraintToSlidingBody);
}

}  // namespace f3m_00a74910
}   // namespace f3m_00a74910

// @f3 0x00a6d020 (community match, verified in this file)
namespace f3m_00a6d020 {
// 0x00a6d020: hkpPulleyDrawer::drawConstraint(hkpConstraintInstance* constraint,
// hkDebugDisplayHandler* displayHandler, int tag) of Havok 5.5.0 (hkpUtilities, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Draws a pulley constraint for the visual debugger: the two bodies' frames and pivots, a grey line between the
// two fixed pulley points, a white line from body A's pivot to its pulley point, and one white line per rope
// from body B's pivot to its pulley point (as many lines as the leverage on body B, drawn side by side along
// body B's x axis).
// Class and member names follow the Havok 5.5.0 SDK headers; the vector and maths helpers follow the SDK's
// inline code for the x87 build; the names of the ten locals and the statement boundaries follow the debug
// records of the SDK library's object. The function's own body is written from the game's code.
// The reference to the pulley atom is not taken from those records and is not visible in them: a reference the
// compiler folds away leaves none, in the SDK's object or in a compile of this file. With the five member chains
// written out instead, the instructions are the same and one x87 addition loads its operands the other way round.
namespace f3m_00a6d020 {

typedef float hkReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned long hkUlong;
typedef int hkResult;

namespace hkMath {
template <typename T>
inline T max2(T x, T y)
{
    return x > y ? x : y;
}
}  // namespace hkMath

struct hkColor
{
    enum ExtendedColors
    {
        WHITE = 0xFFFFFFFF,
        GREY75 = 0xffc0c0c0
    };
};

struct hkTransform;
struct hkRotation;

struct hkVector4
{
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0);
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);

    // setTransformedPos
    void hkVector4_setTransformedPos(const hkTransform& t, const hkVector4& b);
    // setRotatedDir
    void hkVector4_setRotatedDir(const hkRotation& r, const hkVector4& b);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x + v1.x;
    y = v0.y + v1.y;
    z = v0.z + v1.z;
    w = v0.w + v1.w;
}

__forceinline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
    hkReal r = hkReal(rs);
    x = r * a.x;
    y = r * a.y;
    z = r * a.z;
    w = r * a.w;
}

__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
    x = a.x + r * b.x;
    y = a.y + r * b.y;
    z = a.z + r * b.z;
    w = a.w + r * b.w;
}

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    const hkRotation& getRotation() const { return m_rotation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

class hkReferencedObject
{
public:
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    hkInt16 m_referenceCount;
};

class hkMotionState
{
public:
    const hkTransform& getTransform() const { return m_transform; }

    hkTransform m_transform;
};

class hkpMotion : public hkReferencedObject
{
public:
    const hkTransform& getTransform() const { return m_motionState.getTransform(); }

    hkUint8 m_type;
    hkUint8 m_deactivationIntegrateCounter;
    hkUint16 m_deactivationNumInactiveFrames[2];
    hkMotionState m_motionState;
};

// hkpWorldObject and hkpEntity up to the motion; the members in between are not used here
class hkpEntity : public hkReferencedObject
{
public:
    char m_worldObjectAndEntityMembers[0xc8];
    hkpMotion m_motion;
};

class hkpRigidBody : public hkpEntity
{
public:
    const hkTransform& getTransform() const { return m_motion.getTransform(); }
};

struct hkpConstraintAtom
{
    hkUint16 m_type;
};

struct hkpSetLocalTranslationsConstraintAtom : hkpConstraintAtom
{
    hkVector4 m_translationA;
    hkVector4 m_translationB;
};

struct hkpPulleyConstraintAtom : hkpConstraintAtom
{
    hkVector4 m_fixedPivotAinWorld;
    hkVector4 m_fixedPivotBinWorld;
    hkReal m_ropeLength;
    hkReal m_leverageOnBodyB;
};

class hkpConstraintData : public hkReferencedObject
{
public:
    hkUlong m_userData;
};

class hkpPulleyConstraintData : public hkpConstraintData
{
public:
    struct Atoms
    {
        hkpSetLocalTranslationsConstraintAtom m_translations;
        hkpPulleyConstraintAtom m_pulley;
    };

    __declspec(align(16)) Atoms m_atoms;
};

class hkpConstraintOwner;

class hkpConstraintInstance : public hkReferencedObject
{
public:
    hkpConstraintData* getData() const { return m_data; }
    hkpRigidBody* getRigidBodyB() const { return reinterpret_cast<hkpRigidBody*>(m_entities[1]); }

    hkpConstraintOwner* m_owner;
    hkpConstraintData* m_data;
    hkpConstraintAtom* m_constraintModifiers;
    hkpEntity* m_entities[2];
};

class hkDisplayGeometry;
template <typename T>
class hkArray;

class hkDebugDisplayHandler
{
public:
    virtual ~hkDebugDisplayHandler() {}
    virtual hkResult addGeometry(const hkArray<hkDisplayGeometry*>& geometries, const hkTransform& transform,
                                 hkUlong id, int tag, hkUlong shapeIdHint) = 0;
    virtual hkResult addGeometryInstance(hkUlong origianalGeomId, const hkTransform& transform, hkUlong id, int tag,
                                         hkUlong shapeIdHint) = 0;
    virtual hkResult setGeometryColor(int color, hkUlong id, int tag) = 0;
    virtual hkResult updateGeometry(const hkTransform& transform, hkUlong id, int tag) = 0;
    virtual hkResult removeGeometry(hkUlong id, int tag, hkUlong shapeIdHint) = 0;
    virtual hkResult updateCamera(const hkVector4& from, const hkVector4& to, const hkVector4& up, hkReal nearPlane,
                                  hkReal farPlane, hkReal fov, const char* name) = 0;
    virtual hkResult displayPoint(const hkVector4& position, int colour, int tag) = 0;
    virtual hkResult displayLine(const hkVector4& start, const hkVector4& end, int color, int tag) = 0;
};

class hkpPrimitiveDrawer
{
public:
    // setDisplayHandler
    void FUN_00a8f460(hkDebugDisplayHandler* displayHandler);

protected:
    hkDebugDisplayHandler* m_displayHandler;
};

class hkpConstraintDrawer
{
protected:
    // drawPivots
    void FUN_00a6a7b0(int tag);
    // drawBodyFrames
    void FUN_00a6a750(int tag);
    // updateCommonParameters
    void FUN_00a6aa20(hkpConstraintInstance* constraint, hkTransform& refLocalToWorld, hkTransform& attLocalToWorld);

    hkReal m_lineLength;
    hkReal m_arcRadius;
    hkReal m_pivotSize;
    hkReal m_arrowSize;
    hkReal m_coneSize;
    hkReal m_planeSize;
    int m_numSegments;
    hkVector4 m_bodyAWPos;
    hkVector4 m_bodyBWPos;
    hkVector4 m_bodyAWPivot;
    hkVector4 m_bodyBWPivot;
    hkRotation m_RA;
    hkRotation m_RB;
    hkpPrimitiveDrawer m_primitiveDrawer;
};

class hkpPulleyDrawer : public hkpConstraintDrawer
{
public:
    // drawConstraint
    void FUN_00a6d020(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int tag);
};

// pdb: hkpPulleyDrawer::drawConstraint | hkpPulleyDrawer.obj | fnv360_0822_retail, uconst, low
// pdb params: constraint, displayHandler, id, tag
void hkpPulleyDrawer::FUN_00a6d020(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int tag)
{
    hkpPulleyConstraintData* pulley = static_cast<hkpPulleyConstraintData*>(constraint->getData());

    m_primitiveDrawer.FUN_00a8f460(displayHandler);

    {
        hkTransform refLocalToWorld;
        hkTransform attLocalToWorld;
        FUN_00a6aa20(constraint, refLocalToWorld, attLocalToWorld);
        m_bodyBWPivot.hkVector4_setTransformedPos(refLocalToWorld, pulley->m_atoms.m_translations.m_translationB);
        m_bodyAWPivot.hkVector4_setTransformedPos(attLocalToWorld, pulley->m_atoms.m_translations.m_translationA);
    }

    FUN_00a6a750(tag);
    FUN_00a6a7b0(tag);

    // the rope between the two fixed pulley points, and body A's part of it
    const hkpPulleyConstraintAtom& atom = pulley->m_atoms.m_pulley;
    displayHandler->displayLine(atom.m_fixedPivotAinWorld, atom.m_fixedPivotBinWorld, hkColor::GREY75, tag);
    displayHandler->displayLine(m_bodyAWPivot, atom.m_fixedPivotAinWorld, hkColor::WHITE, tag);

    // body B's part: one line per unit of leverage, side by side along the body's x axis, centred on its pivot
    int numLines = int(hkMath::max2(atom.m_leverageOnBodyB, 1.0f));
    hkVector4 shift; shift.set(0.07f, 0.0f, 0.0f);
    shift.hkVector4_setRotatedDir(constraint->getRigidBodyB()->getTransform().getRotation(), shift);

    hkVector4 base; base.setMul4(-0.5f * (numLines - 1), shift);

    for (int i = 0; i < numLines; i++)
    {
        hkVector4 thisShift; thisShift.setAddMul4(base, shift, hkReal(i));
        hkVector4 a; a.setAdd4(m_bodyBWPivot, thisShift);
        hkVector4 b; b.setAdd4(atom.m_fixedPivotBinWorld, thisShift);
        displayHandler->displayLine(a, b, hkColor::WHITE, tag);
    }
}

}  // namespace f3m_00a6d020
}   // namespace f3m_00a6d020

// @f3 0x00a6d890 (community match, verified in this file)
extern const double DAT_010b7e90;
namespace f3m_00a6d890 {
// 0x00a6d890: hkpPointToPlaneDrawer::drawConstraint(hkpConstraintInstance* constraint,
// hkDebugDisplayHandler* displayHandler, int tag) of Havok 5.5.0 (hkpUtilities, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Draws a point-to-plane constraint for the visual debugger: the two bodies' frames and pivots, the plane as a
// grid of six grey lines through body B's pivot (three along each of the two directions at right angles to the
// plane's normal), and a blue line from body A's pivot to body A.
// Class and member names follow the Havok 5.5.0 SDK headers; the vector helpers follow the SDK's inline code
// for the x87 build; the names and types of the locals and the statement boundaries follow the debug records
// of the SDK library's object. The function's own body is written from the game's code.

namespace f3m_00a6d890 {

typedef float hkReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned long hkUlong;
typedef int hkResult;

struct hkColor
{
    // rgbFromFloats
    static int __cdecl FUN_00921880(hkReal red, hkReal green, hkReal blue, hkReal alpha = 1.0f);
};

struct hkTransform;
struct hkRotation;

struct hkVector4
{
    __forceinline void operator=(const hkVector4& v);
    __forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& a);
    __forceinline void subMul4(hkSimdRealParameter rs, const hkVector4& a);

    // setTransformedPos
    void hkVector4_setTransformedPos(const hkTransform& t, const hkVector4& b);
    // setRotatedDir
    void hkVector4_setRotatedDir(const hkRotation& r, const hkVector4& b);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
    hkReal r = hkReal(rs);
    x += r * a.x;
    y += r * a.y;
    z += r * a.z;
    w += r * a.w;
}

__forceinline void hkVector4::subMul4(hkSimdRealParameter rs, const hkVector4& a)
{
    hkReal r = hkReal(rs);
    x -= r * a.x;
    y -= r * a.y;
    z -= r * a.z;
    w -= r * a.w;
}

struct hkMatrix3
{
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    const hkRotation& getRotation() const { return m_rotation; }
    const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

class hkReferencedObject
{
public:
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    hkInt16 m_referenceCount;
};

struct hkpConstraintAtom
{
    hkUint16 m_type;
};

struct hkpSetLocalTransformsConstraintAtom : hkpConstraintAtom
{
    hkTransform m_transformA;
    hkTransform m_transformB;
};

struct hkpLinConstraintAtom : hkpConstraintAtom
{
    hkUint8 m_axisIndex;
};

class hkpConstraintData : public hkReferencedObject
{
public:
    hkUlong m_userData;
};

class hkpPointToPlaneConstraintData : public hkpConstraintData
{
public:
    struct Atoms
    {
        hkpSetLocalTransformsConstraintAtom m_transforms;
        hkpLinConstraintAtom m_lin;
    };

    __declspec(align(16)) Atoms m_atoms;
};

class hkpConstraintOwner;
class hkpEntity;

class hkpConstraintInstance : public hkReferencedObject
{
public:
    hkpConstraintData* getData() const { return m_data; }

    hkpConstraintOwner* m_owner;
    hkpConstraintData* m_data;
    hkpConstraintAtom* m_constraintModifiers;
    hkpEntity* m_entities[2];
};

class hkDisplayGeometry;
template <typename T>
class hkArray;

class hkDebugDisplayHandler
{
public:
    virtual ~hkDebugDisplayHandler() {}
    virtual hkResult addGeometry(const hkArray<hkDisplayGeometry*>& geometries, const hkTransform& transform,
                                 hkUlong id, int tag, hkUlong shapeIdHint) = 0;
    virtual hkResult addGeometryInstance(hkUlong origianalGeomId, const hkTransform& transform, hkUlong id, int tag,
                                         hkUlong shapeIdHint) = 0;
    virtual hkResult setGeometryColor(int color, hkUlong id, int tag) = 0;
    virtual hkResult updateGeometry(const hkTransform& transform, hkUlong id, int tag) = 0;
    virtual hkResult removeGeometry(hkUlong id, int tag, hkUlong shapeIdHint) = 0;
    virtual hkResult updateCamera(const hkVector4& from, const hkVector4& to, const hkVector4& up, hkReal nearPlane,
                                  hkReal farPlane, hkReal fov, const char* name) = 0;
    virtual hkResult displayPoint(const hkVector4& position, int colour, int tag) = 0;
    virtual hkResult displayLine(const hkVector4& start, const hkVector4& end, int color, int tag) = 0;
};

class hkpPrimitiveDrawer
{
public:
    // setDisplayHandler
    void FUN_00a8f460(hkDebugDisplayHandler* displayHandler);

protected:
    hkDebugDisplayHandler* m_displayHandler;
};

class hkpConstraintDrawer
{
protected:
    // drawPivots
    void FUN_00a6a7b0(int tag);
    // drawBodyFrames
    void FUN_00a6a750(int tag);
    // updateCommonParameters
    void FUN_00a6aa20(hkpConstraintInstance* constraint, hkTransform& refLocalToWorld, hkTransform& attLocalToWorld);

    hkReal m_lineLength;
    hkReal m_arcRadius;
    hkReal m_pivotSize;
    hkReal m_arrowSize;
    hkReal m_coneSize;
    hkReal m_planeSize;
    int m_numSegments;
    hkVector4 m_bodyAWPos;
    hkVector4 m_bodyBWPos;
    hkVector4 m_bodyAWPivot;
    hkVector4 m_bodyBWPivot;
    hkRotation m_RA;
    hkRotation m_RB;
    hkpPrimitiveDrawer m_primitiveDrawer;
};

class hkpPointToPlaneDrawer : public hkpConstraintDrawer
{
public:
    // drawConstraint
    void FUN_00a6d890(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int tag);
};

// pdb: hkpPointToPlaneDrawer::drawConstraint | hkpPointToPlaneDrawer.obj | fnv360_0822_retail, call_gap, medium
// pdb params: constraint, displayHandler, id, tag
void hkpPointToPlaneDrawer::FUN_00a6d890(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int tag)
{
    hkpPointToPlaneConstraintData* plane = static_cast<hkpPointToPlaneConstraintData*>(constraint->getData());

    m_primitiveDrawer.FUN_00a8f460(displayHandler);

    {
        hkTransform refLocalToWorld;
        hkTransform attLocalToWorld;
        FUN_00a6aa20(constraint, refLocalToWorld, attLocalToWorld);
        m_bodyBWPivot.hkVector4_setTransformedPos(refLocalToWorld, plane->m_atoms.m_transforms.m_transformB.getTranslation());
        m_bodyAWPivot.hkVector4_setTransformedPos(attLocalToWorld, plane->m_atoms.m_transforms.m_transformA.getTranslation());
    }

    FUN_00a6a750(tag);

    FUN_00a6a7b0(tag);

    // the two directions in the plane, in world space
    hkVector4 perpVec0; perpVec0.hkVector4_setRotatedDir(m_RB, plane->m_atoms.m_transforms.m_transformB.getColumn((plane->m_atoms.m_lin.m_axisIndex + 1) % 3));
    hkVector4 perpVec1; perpVec1.hkVector4_setRotatedDir(m_RB, plane->m_atoms.m_transforms.m_transformB.getColumn((plane->m_atoms.m_lin.m_axisIndex + 2) % 3));

    // three lines along each direction, through body B's pivot and 1.4 to either side of it
    hkVector4 lines[6][2];
    for (int j = 0; j < 2; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            hkVector4 v0; v0 = j ? perpVec0 : perpVec1;
            hkVector4 v1; v1 = j ? perpVec1 : perpVec0;
            lines[j * 3 + i + 1][0] = m_bodyBWPivot;
            lines[j * 3 + i + 1][1] = m_bodyBWPivot;
            lines[j * 3 + i + 1][0].addMul4(2.0, v0);
            lines[j * 3 + i + 1][1].addMul4(-2.0, v0);
            lines[j * 3 + i + 1][0].addMul4(i * DAT_010b7e90, v1);
            lines[j * 3 + i + 1][1].addMul4(i * DAT_010b7e90, v1);
        }
    }

    for (int i = 0; i < 6; i++)
    {
        displayHandler->displayLine(lines[i][0], lines[i][1], hkColor::FUN_00921880(0.8f, 0.8f, 0.8f), tag);
    }

    // from body A's pivot to body A
    displayHandler->displayLine(m_bodyAWPivot, m_bodyAWPos, hkColor::FUN_00921880(0.3f, 0.3f, 0.8f), tag);
}

}  // namespace f3m_00a6d890
}   // namespace f3m_00a6d890

// @f3 0x00a687a0 (community match, verified in this file)
#include <windows.h>
#include <math.h>
extern DWORD S687a0_tlsIndex;
#include "havok/hkMonitorStream.h"
namespace f3m_00a687a0 {
// 0x00a687a0: hkpContactPointViewer's displayArrow: draws an arrow from `from` along `dir` (the shaft and two
// head lines at 85% of its length), inside a monitor timer ("TthkContactPointViewer_displayArrow" ... "Et").
// /O2 code with a private convention (from in ecx, dir in eax; the handler, color and id on the stack): a static
// function with a caller below. The timer reads the clock with the two-instruction form compiler_tips.md allows.

static inline float S687a0_sqrt(float r) { return (float)sqrt(r); }
static inline float S687a0_fabs(float r) { return (float)fabs(r); }

struct __declspec(align(16)) S687a0_Vector4
{
    float x, y, z, w;

    float& operator()(int i) { return (&x)[i]; }
    const float& operator()(int i) const { return (&x)[i]; }

    void setZero4() { x = y = z = w = 0.0f; }
    void setAdd4(const S687a0_Vector4& a, const S687a0_Vector4& b)
    {
        x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w;
    }
    void setAddMul4(const S687a0_Vector4& a, const S687a0_Vector4& b, float r)
    {
        x = a.x + r * b.x; y = a.y + r * b.y; z = a.z + r * b.z; w = a.w + r * b.w;
    }
    void setSubMul4(const S687a0_Vector4& a, const S687a0_Vector4& b, float r)
    {
        x = a.x - r * b.x; y = a.y - r * b.y; z = a.z - r * b.z; w = a.w - r * b.w;
    }
    void setInterpolate4(const S687a0_Vector4& a, const S687a0_Vector4& b, float t)
    {
        const float s = 1.0f - t;
        x = s * a.x + t * b.x; y = s * a.y + t * b.y; z = s * a.z + t * b.z; w = s * a.w + t * b.w;
    }
    void mul4(float s) { x *= s; y *= s; z *= s; w *= s; }
    float lengthSquared3() const { return x * x + y * y + z * z; }
    float length3() const { return S687a0_sqrt(lengthSquared3()); }
    __forceinline void normalize3()
    {
        const float zero = 0.0f;           // a zero vector stays zero
        float lenSq = lengthSquared3();
        float invLen;
        if (lenSq != zero)
        {
            invLen = 1.0f / S687a0_sqrt(lenSq);
        }
        else
        {
            invLen = zero;
        }
        mul4(invLen);
    }
};

static __forceinline void S687a0_calculatePerpendicularVector(const S687a0_Vector4& vectorIn, S687a0_Vector4& biggestComponentOut)
{
    int min = 0;
    int ma1 = 1;
    int ma2 = 2;
    float a0 = S687a0_fabs(vectorIn(0));
    float a1 = S687a0_fabs(vectorIn(1));
    float a2 = S687a0_fabs(vectorIn(2));
    if (a1 < a0)
    {
        ma1 = 0;
        min = 1;
        a0 = a1;
    }
    if (a2 < a0)
    {
        ma2 = min;
        min = 2;
    }
    biggestComponentOut.setZero4();
    biggestComponentOut(ma1) = vectorIn(ma2);
    biggestComponentOut(ma2) = -vectorIn(ma1);
}

struct S687a0_Handler
{
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1c();
    virtual void displayLine(const S687a0_Vector4& from, const S687a0_Vector4& to, int color, int id);
};


struct S687a0_MonitorStream
{
    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;
};


// pdb: hkContactPointViewer_displayArrow | hkpContactPointViewer.obj | fnv360_0822_retail, ustr, medium
static __declspec(noinline) void FUN_00a687a0(const S687a0_Vector4& from, const S687a0_Vector4& dir, S687a0_Handler* handler, int color, int id)
{
    const S687a0_Vector4& d = dir;     // read through a local reference, which sets the original's operand order
    {
        HK_TIMER_BEGIN("hkContactPointViewer_displayArrow", HK_NULL);
    }
    if (d.lengthSquared3() < 1.1920928955078125e-07f)
    {
        HK_TIMER_END();
        return;
    }

    S687a0_Vector4 to; to.setAdd4(from, d);
    S687a0_Vector4 ort; S687a0_calculatePerpendicularVector(d, ort);
    ort.normalize3();
    ort.mul4(d.length3());

    const float c = 0.85f;
    S687a0_Vector4 p; p.setInterpolate4(from, to, c);
    S687a0_Vector4 left; left.setAddMul4(p, ort, 1.0f - c);
    S687a0_Vector4 right; right.setAddMul4(p, ort, c - 1.0f);
    handler->displayLine(from, to, color, id);
    handler->displayLine(to, left, color, id);
    handler->displayLine(to, right, color, id);

    HK_TIMER_END();
}

volatile int g687a0_in;
S687a0_Vector4 g687a0_a, g687a0_b;
S687a0_Handler* volatile g687a0_h;
void caller_of_S687a0() { FUN_00a687a0(g687a0_b, g687a0_a, g687a0_h, g687a0_in, g687a0_in); }

}   // namespace f3m_00a687a0

// @f3 0x00a6ddd0 (community match, verified in this file)
namespace f3m_00a6ddd0 {
// 0x00a6ddd0: hkpWheelDrawer::drawConstraint(hkpConstraintInstance* constraint,
// hkDebugDisplayHandler* displayHandler, int tag) of Havok 5.5.0 (hkpUtilities, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Draws a wheel constraint for the visual debugger: the two bodies' frames and pivots, a red line between the
// pivots, the suspension axis through body B's pivot (green), a short white cross line at the upper and at the
// lower suspension limit, the steering axis through body B's pivot (yellow) and the axle through body A's pivot
// (blue).
// Class, member and enumerator names follow the Havok 5.5.0 SDK headers; the vector helpers follow the SDK's
// inline code for the x87 build. The locals, their scopes and the statement order follow the debug records and
// the unoptimized code of the SDK's hybrid library object (hkpWheelDrawer.obj): built with the SDK's own headers
// this body reproduces that object and the release object; the classes here are written out by hand for a
// self-contained file.
namespace f3m_00a6ddd0 {

typedef float hkReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned long hkUlong;
typedef int hkResult;

struct hkColor
{
    enum ExtendedColors
    {
        RED = 0xffff0000,
        GREEN = 0xff008000,
        BLUE = 0xff0000ff,
        YELLOW = 0xffffff00,
        WHITE = 0xffffffff
    };
};

struct hkTransform;
struct hkRotation;

struct hkVector4
{
    __forceinline void add4(const hkVector4& v);
    __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a);

    // setTransformedPos
    void hkVector4_setTransformedPos(const hkTransform& t, const hkVector4& b);
    // setRotatedDir
    void hkVector4_setRotatedDir(const hkRotation& r, const hkVector4& b);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline void hkVector4::add4(const hkVector4& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
}

__forceinline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
    hkReal r = hkReal(rs);
    x = r * a.x;
    y = r * a.y;
    z = r * a.z;
    w = r * a.w;
}

struct hkMatrix3
{
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    const hkRotation& getRotation() const { return m_rotation; }
    const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

class hkReferencedObject
{
public:
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    hkInt16 m_referenceCount;
};

struct hkpConstraintAtom
{
    hkUint16 m_type;
};

struct hkpSetLocalTransformsConstraintAtom : hkpConstraintAtom
{
    hkTransform m_transformA;
    hkTransform m_transformB;
};

struct hkpLinLimitConstraintAtom : hkpConstraintAtom
{
    hkUint8 m_axisIndex;
    hkReal m_min;
    hkReal m_max;
};

struct hkpLinSoftConstraintAtom : hkpConstraintAtom
{
    hkUint8 m_axisIndex;
    hkReal m_tau;
    hkReal m_damping;
};

struct hkpLinConstraintAtom : hkpConstraintAtom
{
    hkUint8 m_axisIndex;
};

struct hkpSetLocalRotationsConstraintAtom : hkpConstraintAtom
{
    hkRotation m_rotationA;
    hkRotation m_rotationB;
};

struct hkp2dAngConstraintAtom : hkpConstraintAtom
{
    hkUint8 m_freeRotationAxis;
};

class hkpConstraintData : public hkReferencedObject
{
public:
    hkUlong m_userData;
};

class hkpWheelConstraintData : public hkpConstraintData
{
public:
    struct Atoms
    {
        enum Axis
        {
            AXIS_SUSPENSION = 0,
            AXIS_PERP_SUSPENSION = 1,

            AXIS_AXLE = 0,
            AXIS_STEERING = 1
        };

        hkpSetLocalTransformsConstraintAtom m_suspensionBase;
        hkpLinLimitConstraintAtom m_lin0Limit;
        hkpLinSoftConstraintAtom m_lin0Soft;
        hkpLinConstraintAtom m_lin1;
        hkpLinConstraintAtom m_lin2;
        hkpSetLocalRotationsConstraintAtom m_steeringBase;
        hkp2dAngConstraintAtom m_2dAng;
    };

    __declspec(align(16)) Atoms m_atoms;
};

class hkpConstraintOwner;
class hkpEntity;

class hkpConstraintInstance : public hkReferencedObject
{
public:
    hkpConstraintData* getData() const { return m_data; }

    hkpConstraintOwner* m_owner;
    hkpConstraintData* m_data;
    hkpConstraintAtom* m_constraintModifiers;
    hkpEntity* m_entities[2];
};

class hkDisplayGeometry;
template <typename T>
class hkArray;

class hkDebugDisplayHandler
{
public:
    virtual ~hkDebugDisplayHandler() {}
    virtual hkResult addGeometry(const hkArray<hkDisplayGeometry*>& geometries, const hkTransform& transform,
                                 hkUlong id, int tag, hkUlong shapeIdHint) = 0;
    virtual hkResult addGeometryInstance(hkUlong origianalGeomId, const hkTransform& transform, hkUlong id, int tag,
                                         hkUlong shapeIdHint) = 0;
    virtual hkResult setGeometryColor(int color, hkUlong id, int tag) = 0;
    virtual hkResult updateGeometry(const hkTransform& transform, hkUlong id, int tag) = 0;
    virtual hkResult removeGeometry(hkUlong id, int tag, hkUlong shapeIdHint) = 0;
    virtual hkResult updateCamera(const hkVector4& from, const hkVector4& to, const hkVector4& up, hkReal nearPlane,
                                  hkReal farPlane, hkReal fov, const char* name) = 0;
    virtual hkResult displayPoint(const hkVector4& position, int colour, int tag) = 0;
    virtual hkResult displayLine(const hkVector4& start, const hkVector4& end, int color, int tag) = 0;
};

class hkpPrimitiveDrawer
{
public:
    // setDisplayHandler
    void FUN_00a8f460(hkDebugDisplayHandler* displayHandler);

protected:
    hkDebugDisplayHandler* m_displayHandler;
};

class hkpConstraintDrawer
{
protected:
    // drawBodyFrames
    void FUN_00a6a7b0(int tag);
    // drawPivots
    void FUN_00a6a750(int tag);
    // updateCommonParameters
    void FUN_00a6aa20(hkpConstraintInstance* constraint, hkTransform& refLocalToWorld, hkTransform& attLocalToWorld);

    hkReal m_lineLength;
    hkReal m_arcRadius;
    hkReal m_pivotSize;
    hkReal m_arrowSize;
    hkReal m_coneSize;
    hkReal m_planeSize;
    int m_numSegments;
    hkVector4 m_bodyAWPos;
    hkVector4 m_bodyBWPos;
    hkVector4 m_bodyAWPivot;
    hkVector4 m_bodyBWPivot;
    hkRotation m_RA;
    hkRotation m_RB;
    hkpPrimitiveDrawer m_primitiveDrawer;
};

class hkpWheelDrawer : public hkpConstraintDrawer
{
public:
    // drawConstraint
    void FUN_00a6ddd0(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int tag);
};

// pdb: hkpWheelDrawer::drawConstraint | hkpWheelDrawer.obj | fnv360_0822_retail, call_gap, medium
// pdb params: constraint, displayHandler, id, tag
void hkpWheelDrawer::FUN_00a6ddd0(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int tag)
{
    hkpWheelConstraintData* wheel = static_cast<hkpWheelConstraintData*>(constraint->getData());

    m_primitiveDrawer.FUN_00a8f460(displayHandler);

    {
        hkTransform refLocalToWorld;
        hkTransform attLocalToWorld;
        FUN_00a6aa20(constraint, refLocalToWorld, attLocalToWorld);
        m_bodyBWPivot.hkVector4_setTransformedPos(refLocalToWorld, wheel->m_atoms.m_suspensionBase.m_transformB.getTranslation());
        m_bodyAWPivot.hkVector4_setTransformedPos(attLocalToWorld, wheel->m_atoms.m_suspensionBase.m_transformA.getTranslation());
    }

    FUN_00a6a7b0(tag);

    FUN_00a6a750(tag);

    // between the two pivots
    displayHandler->displayLine(m_bodyAWPivot, m_bodyBWPivot, hkColor::RED, tag);

    hkVector4 suspensionAxis; suspensionAxis.hkVector4_setRotatedDir(m_RB, wheel->m_atoms.m_suspensionBase.m_transformB.getColumn(hkpWheelConstraintData::Atoms::AXIS_SUSPENSION));

    // the suspension axis, through body B's pivot
    {
        hkVector4 p1;
        p1.setMul4(m_lineLength * -0.5f, suspensionAxis);
        p1.add4(m_bodyBWPivot);
        hkVector4 p2; p2.setMul4(m_lineLength * 0.5f, suspensionAxis);
        p2.add4(m_bodyBWPivot);
        displayHandler->displayLine(p1, p2, hkColor::GREEN, tag);
    }

    // a short line across the suspension axis at its upper and at its lower limit
    {
        hkReal suspensionMin = wheel->m_atoms.m_lin0Limit.m_min;
        hkReal suspensionMax = wheel->m_atoms.m_lin0Limit.m_max;

        hkVector4 perpSuspension; perpSuspension.hkVector4_setRotatedDir(m_RB, wheel->m_atoms.m_suspensionBase.m_transformB.getColumn(hkpWheelConstraintData::Atoms::AXIS_PERP_SUSPENSION));

        hkVector4 p1; p1.setMul4(suspensionMax, suspensionAxis);
        p1.add4(m_bodyBWPivot);

        hkVector4 start; start.setMul4(m_lineLength * 0.1f, perpSuspension);
        start.add4(p1);

        hkVector4 end; end.setMul4(m_lineLength * -0.1f, perpSuspension);
        end.add4(p1);

        displayHandler->displayLine(start, end, hkColor::WHITE, tag);

        p1.setMul4(suspensionMin, suspensionAxis);
        p1.add4(m_bodyBWPivot);

        start.setMul4(m_lineLength * 0.1f, perpSuspension);
        start.add4(p1);

        end.setMul4(m_lineLength * -0.1f, perpSuspension);
        end.add4(p1);

        displayHandler->displayLine(start, end, hkColor::WHITE, tag);
    }

    // the steering axis, through body B's pivot
    {
        hkVector4 steeringAxis; steeringAxis.hkVector4_setRotatedDir(m_RB, wheel->m_atoms.m_steeringBase.m_rotationB.getColumn(hkpWheelConstraintData::Atoms::AXIS_STEERING));
        hkVector4 p1; p1.setMul4(m_lineLength * -0.5f, steeringAxis);
        p1.add4(m_bodyBWPivot);
        hkVector4 p2; p2.setMul4(m_lineLength * 0.5f, steeringAxis);
        p2.add4(m_bodyBWPivot);
        displayHandler->displayLine(p1, p2, hkColor::YELLOW, tag);
    }

    // the axle, through body A's pivot
    {
        hkVector4 axle; axle.hkVector4_setRotatedDir(m_RA, wheel->m_atoms.m_steeringBase.m_rotationA.getColumn(hkpWheelConstraintData::Atoms::AXIS_AXLE));

        hkVector4 p1; p1.setMul4(m_lineLength * -0.5f, axle);
        p1.add4(m_bodyAWPivot);

        hkVector4 p2; p2.setMul4(m_lineLength * 0.5f, axle);
        p2.add4(m_bodyAWPivot);

        displayHandler->displayLine(p1, p2, hkColor::BLUE, tag);
    }
}

}  // namespace f3m_00a6ddd0
}   // namespace f3m_00a6ddd0

// @f3 0x00a70cc0 (community match, verified in this file)
namespace f3m_00a70cc0 {
// 0x00a70cc0: builds the Jacobians of a stiff-spring chain (Havok constraint chain): for each link it moves the
// query's body B to body A, steps to the next chained entity (recording its velocity-accumulator offset in an inline
// array of 32), transforms both pivots to world space and emits one stiff-spring schema with the length error, then
// hands the offsets to the chain's solver setup. /O2 code (the listed /Od is wrong).

namespace F3Spring2273 {
struct __declspec(align(16)) Vector {
    float x, y, z, w;
    void hkVector4_setTransformedPos(const void*, const Vector*);
    __forceinline Vector& operator=(const Vector& other) { x=other.x;y=other.y;z=other.z;w=other.w;return *this; }
    __forceinline float NormalizeWithLength3() {
        float length = sqrtf(x*x+y*y+z*z);
        float roundedInverse = 1.0f / length;
        x = roundedInverse*x;
        const double inverse = roundedInverse;
        y = y*inverse; z = z*inverse; w = inverse*w;
        return length;
    }
};
struct Link {
    Vector pivotA, pivotB;
    float restLength;
    unsigned unk24, unk28, unk2c;
};
struct Entity {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned unk80, unk84, unk88, unk8c;
    unsigned velocityOffset;
    unsigned unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    unsigned unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    unsigned unkd0, unkd4, unkd8, unkdc;
    Vector transform;
};
struct Chain {
    unsigned unk00, unk04, unk08, unk0c, unk10;
    Entity* originalA;
    unsigned unk18, unk1c, unk20, unk24, unk28;
    Entity** bodies;
    int bodyCount;
};
struct __declspec(align(16)) Input {
    unsigned unk00, limit, unk08, unk0c;
    unsigned unk10, unk14, unk18, solverLimit;
    float unitScale;
    unsigned unk24, unk28, unk2c;
    const void *accumulatorA, *accumulatorB;
    const Vector* transformA;
    const Vector* transformB;
    unsigned unk40, unk44;
    Chain* chain;
    void* eventBuffer;
    unsigned unk50, unk54, unk58, unk5c;
};
struct Schema { unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; };
struct Output { void* schema; };
struct OffsetArray {
    unsigned* data;
    int size;
    int capacity;
};
struct OffsetFrame {
    OffsetArray array;
    unsigned local[32];
};
struct Pivots { Vector a, b, direction; };
struct Heap { void FUN_008f6d90(void*, unsigned, unsigned); };
extern unsigned DAT_010f3170;
extern Heap* (__stdcall *DAT_00d9b080)(unsigned);
extern const Vector DAT_010f3370;
extern void __cdecl FUN_009fcb10(const Input&, Output&, void*, unsigned);
extern Schema* __cdecl FUN_00a523d0(void*);
extern void __cdecl FUN_00901f10(OffsetArray*, unsigned);
extern void __cdecl FUN_00a4e400(Input*);
extern void __cdecl hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema(const Pivots&, Input&, Schema*, float);
extern void __cdecl FUN_00a520c0(int, float, float, float, const unsigned*, unsigned, Schema*, const Input&, Output&);
struct Solver {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14;
    Link* links;
    unsigned unk1c, unk20;
    float tau, damping, maxError;
    void hkpStiffSpringChainData_buildJacobian(const Input&, Output&);
};
// pdb: hkpStiffSpringChainData::buildJacobian | hkpStiffSpringChainData.obj | fnv360_1110_retail, objrun + bridge(caller_sim|vtable) + skyrim(caller_sim), high
void Solver::hkpStiffSpringChainData_buildJacobian(const Input& input, Output& output)
{
    FUN_009fcb10(input, output, input.eventBuffer, 8);
    Input in = input;
    in.chain = 0;
    in.eventBuffer = 0;
    OffsetFrame offsets;
    offsets.array.data = offsets.local;
    offsets.array.capacity = 0x80000020;
    offsets.array.size = 0;
    Chain* chainInstance = input.chain;
    int numConstraints = chainInstance->bodyCount - 1;
    unsigned base = reinterpret_cast<unsigned>(input.accumulatorA) - chainInstance->originalA->velocityOffset;
    Entity* firstEntity = chainInstance->bodies[0];
    in.accumulatorB = reinterpret_cast<const void*>(base + firstEntity->velocityOffset);
    offsets.array.data[offsets.array.size++] = reinterpret_cast<unsigned>(in.accumulatorB) - base;
    in.transformB = &firstEntity->transform;
    in.unitScale = 1.0f;
    in.solverLimit = in.unk08;
    void* schemaOut = output.schema;     // a named local here sets the register order of the loop below
    Schema* schema = FUN_00a523d0(schemaOut);
    for (int i = 0; i < numConstraints; ++i) {
        in.accumulatorA = in.accumulatorB;
        in.transformA = in.transformB;
        Entity* entity = chainInstance->bodies[i + 1];
        in.accumulatorB = reinterpret_cast<const void*>(base + entity->velocityOffset);
        unsigned offsetB = reinterpret_cast<unsigned>(in.accumulatorB) - base;
        if (offsets.array.size == (offsets.array.capacity & 0x3fffffff))
            FUN_00901f10(&offsets.array, sizeof(unsigned));
        offsets.array.data[offsets.array.size++] = offsetB;
        in.transformB = &entity->transform;
        Pivots pivots;
        pivots.a.hkVector4_setTransformedPos(in.transformA, &links[i].pivotA);
        pivots.b.hkVector4_setTransformedPos(in.transformB, &links[i].pivotB);
        Vector axis;
        axis.x = pivots.a.x - pivots.b.x;
        axis.y = pivots.a.y - pivots.b.y;
        axis.z = pivots.a.z - pivots.b.z;
        axis.w = pivots.a.w - pivots.b.w;
        float springLength = axis.NormalizeWithLength3();
        if (springLength > 0.0f)
            pivots.direction = axis;
        else {
            pivots.direction = DAT_010f3370;
            springLength = 0.0f;
        }
        FUN_00a4e400(&in);
        hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema(pivots, in, schema, links[i].restLength - springLength);
        ++schema;
    }
    FUN_00a520c0(numConstraints, tau, damping, maxError, offsets.array.data, base, schema, input, output);
    if ((offsets.array.capacity & 0x80000000u) == 0) {
        unsigned capacity = offsets.array.capacity & 0x3fffffff;
        Heap* memory = DAT_00d9b080(DAT_010f3170);
        memory->FUN_008f6d90(offsets.array.data, capacity * sizeof(unsigned), 0x17);
    }
}
}

}   // namespace f3m_00a70cc0

// @f3 0x00a74b00 (community match, verified in this file)
#include <math.h>
namespace f3m_00a74b00 {

// Point-to-path constraint: builds the solver rows for one step (x87 build of the vector library).
// Stand-in types; unknown fields are named by offset.

struct __declspec(align(16)) VectorQ {
    float x, y, z, w;
    VectorQ() {}
    VectorQ& operator=(const VectorQ& a) { x = a.x; y = a.y; z = a.z; w = a.w; return *this; }
    float& operator[](int n) { return (&x)[n]; }
    const float& operator[](int n) const { return (&x)[n]; }
    void setCross(const VectorQ& a, const VectorQ& b);
    void setAddMul4(const VectorQ& a, const VectorQ& b, float r) { x = a.x + r * b.x; y = a.y + r * b.y; z = a.z + r * b.z; w = a.w + r * b.w; }
    void FUN_008d2970(const struct TransformQ& t, const VectorQ& v);   // inverse-transform a position
    void hkVector4_setTransformedPos(const struct TransformQ& t, const VectorQ& v);   // transform a position
    void hkVector4_setRotatedDir(const struct TransformQ& t, const VectorQ& v);   // rotate a direction
};

struct __declspec(align(16)) TransformQ {
    VectorQ m_col0, m_col1, m_col2, m_translation;
    void hkTransform_setMul(const TransformQ& a, const TransformQ& b);       // this = a * b
};

__forceinline float absQ(float r) { return fabsf(r); }

__forceinline void swapAxis(int& a, int& b) { int t = a; a = b; b = t; }

// A vector perpendicular to v: zero its smallest component, swap the other two and negate one.
__forceinline void calculatePerpendicularVector(const VectorQ& v, VectorQ& out) {
    int i = 0, j = 1, k = 2;
    float a = absQ(v[0]), b = absQ(v[1]), c = absQ(v[2]);
    if (b < a) { swapAxis(j, i); a = b; }
    if (c < a) swapAxis(i, k);
    out.x = out.y = out.z = out.w = 0.0f;
    out[j] = v[k];
    out[k] = -v[j];
}

__forceinline void normalize3(VectorQ& v) {
    float lengthSquared = v.x * v.x + v.y * v.y + v.z * v.z;
    float inverseLength;
    if (lengthSquared != 0.0f) inverseLength = 1.0f / (float)sqrt(lengthSquared); else inverseLength = 0.0f;
    v.x *= inverseLength;
    v.y *= inverseLength;
    v.z *= inverseLength;
    v.w *= inverseLength;
}

__forceinline void setNeg4(VectorQ& out, const VectorQ& v) { out.x = -v.x; out.y = -v.y; out.z = -v.z; out.w = -v.w; }

__forceinline void VectorQ::setCross(const VectorQ& a, const VectorQ& b) {
    const float nx = a.y * b.z - a.z * b.y;
    const float ny = a.z * b.x - a.x * b.z;
    const float nz = a.x * b.y - a.y * b.x;
    this->x = nx;
    this->y = ny;
    this->z = nz;
    this->w = 0.0f;
}

struct BoolQ { char value; BoolQ(bool v) : value(v) {} };

class PathCurveQ {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual float getNearestPoint(float t, const VectorQ& nearPoint, VectorQ& pointOnPath);
    virtual void getTangent(float t, VectorQ& tangent);
    virtual float getStart();
    virtual float getEnd();
    virtual float getLengthFromStart(float t);
    virtual void getBinormal(float t, VectorQ& up);
    virtual BoolQ isClosedLoop();
};

struct PathRuntime {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    float m_parametricPosition;
};

struct QueryOut { int unk00; };

struct QueryIn {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    const TransformQ* m_transformA;
    const TransformQ* m_transformB;
    int unk40, unk44, unk48;
    PathRuntime* m_constraintRuntime;
};

struct __declspec(align(16)) FrictionRow { VectorQ m_pivot, m_direction; float m_maxFrictionForce; PathRuntime* m_runtime; };
struct __declspec(align(16)) LinearRow { VectorQ m_pivotA, m_pivotB, m_constrainedDof; };
struct __declspec(align(16)) AngularRow { VectorQ m_zeroErrorAxisA, m_perpZeroErrorAxisB, m_constrainedDof; };
struct __declspec(align(16)) LimitRow { VectorQ m_pivotA, m_pivotB, m_constrainedDof; float m_min, m_max; };

extern "C" void AppendEventRecord(const QueryIn&, QueryOut&, PathRuntime*, int);
extern "C" void __cdecl FUN_00a4e900(const FrictionRow*, const QueryIn&, QueryOut&);
extern "C" void __cdecl FUN_00a4ebf0(const LinearRow*, const QueryIn&, QueryOut&);
extern "C" void __cdecl FUN_00a4e410(const AngularRow*, const QueryIn&, QueryOut&);
extern "C" void __cdecl FUN_00a4fb30(const LimitRow*, const QueryIn&, QueryOut&);

struct PointToPathData {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    PathCurveQ* m_path;
    float m_maxFrictionForce;
    signed char m_orientationType;
    int unk24, unk28, unk2c;
    TransformQ m_transforms[2];
    void FUN_00a74b00(const QueryIn& in, QueryOut& out);
};

void PointToPathData::FUN_00a74b00(const QueryIn& in, QueryOut& out)
{
    AppendEventRecord(in, out, in.m_constraintRuntime, 8);

    TransformQ pathToWorld;
    pathToWorld.hkTransform_setMul(*in.m_transformB, m_transforms[1]);
    TransformQ bodyToWorld;
    bodyToWorld.hkTransform_setMul(*in.m_transformA, m_transforms[0]);

    VectorQ& bodyAxis0 = bodyToWorld.m_col0;
    PathRuntime* runtime = in.m_constraintRuntime;

    VectorQ pathPointWs;
    VectorQ tangentWs;
    {
        // the pivot in path space, then the nearest point on the path, in the same vector
        VectorQ pivotLocal;

        pivotLocal.FUN_008d2970(pathToWorld, bodyToWorld.m_translation);
        runtime->m_parametricPosition =
            m_path->getNearestPoint(runtime->m_parametricPosition, pivotLocal, pivotLocal);

        pathPointWs.hkVector4_setTransformedPos(pathToWorld, pivotLocal);
    }
    {
        VectorQ tangentLocal;
        m_path->getTangent(runtime->m_parametricPosition, tangentLocal);
        tangentWs.hkVector4_setRotatedDir(pathToWorld, tangentLocal);
    }

    // two directions perpendicular to the path
    VectorQ perpWs1;
    calculatePerpendicularVector(tangentWs, perpWs1);
    normalize3(perpWs1);

    VectorQ perpWs2;
    perpWs2.setCross(tangentWs, perpWs1);

    // the pivot moved back along the tangent by the distance travelled on the path
    float distance = -m_path->getLengthFromStart(runtime->m_parametricPosition);
    VectorQ pivotOnAxis;
    pivotOnAxis.setAddMul4(bodyToWorld.m_translation, tangentWs, distance);

    if (m_maxFrictionForce > 0.0f)
    {
        FrictionRow friction;
        friction.m_direction = tangentWs;
        friction.m_pivot = pivotOnAxis;
        friction.m_maxFrictionForce = m_maxFrictionForce;
        friction.m_runtime = runtime;
        FUN_00a4e900(&friction, in, out);
    }

    LinearRow linear;
    linear.m_pivotA = bodyToWorld.m_translation;
    linear.m_pivotB = pathPointWs;
    linear.m_constrainedDof = perpWs1;
    FUN_00a4ebf0(&linear, in, out);
    linear.m_constrainedDof = perpWs2;
    FUN_00a4ebf0(&linear, in, out);

    if (1 < m_orientationType)
    {
        AngularRow angular;
        angular.m_zeroErrorAxisA = tangentWs;
        angular.m_constrainedDof = bodyToWorld.m_col2;
        angular.m_perpZeroErrorAxisB = bodyToWorld.m_col1;
        FUN_00a4e410(&angular, in, out);
        angular.m_constrainedDof = bodyToWorld.m_col1;
        setNeg4(angular.m_perpZeroErrorAxisB, bodyToWorld.m_col2);
        FUN_00a4e410(&angular, in, out);

        if (m_orientationType == 3)
        {
            VectorQ binormal;
            m_path->getBinormal(runtime->m_parametricPosition, binormal);

            VectorQ binormalWs;
            binormalWs.hkVector4_setRotatedDir(pathToWorld, binormal);
            angular.m_zeroErrorAxisA = bodyToWorld.m_col2;
            setNeg4(angular.m_constrainedDof, binormalWs);
            angular.m_perpZeroErrorAxisB = bodyAxis0;
            FUN_00a4e410(&angular, in, out);
        }
    }

    if (!m_path->isClosedLoop().value)
    {
        LimitRow limit;
        limit.m_pivotA = bodyToWorld.m_translation;
        limit.m_pivotB = pivotOnAxis;
        limit.m_min = m_path->getLengthFromStart(m_path->getStart());
        limit.m_max = m_path->getLengthFromStart(m_path->getEnd());
        limit.m_constrainedDof = tangentWs;
        FUN_00a4fb30(&limit, in, out);
    }
}
}   // namespace f3m_00a74b00

// @f3 0x00a61e50 (community match, verified in this file)
namespace f3m_00a61e50 {

struct Vec4 { float x, y, z, w; };
struct __declspec(align(16)) AVec4 { float x, y, z, w; };
static void Set(AVec4& d, const Vec4* s) { d.x = s->x; d.y = s->y; d.z = s->z; d.w = s->w; }
struct Obj8 { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; void Prep(); };
struct Cmd {
    void A(int v); void B(int v); void P(const void* p); void C(int v); bool* Q(char* t);
};
struct Self {
    int unk00; Cmd* unk04; Obj8* unk08;
    bool FUN_00a61e50(Vec4* a, Vec4* b, Vec4* c, int d, int e);
};
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
// pdb: hkServerDebugDisplayHandler::displayTriangle | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: a, b, c, color, id, tag
bool Self::FUN_00a61e50(Vec4* a, Vec4* b, Vec4* c, int d, int e)
{
    AVec4 pl[4];
    unk08->Prep();
    if (unk04) {
        Set(pl[0], a); Set(pl[1], b); Set(pl[2], c); Set(pl[3], a);
        AVec4* q = &pl[1];
        for (int i = 0; i < 3; i++, q++) {
            unk04->A(0x21);
            unk04->B(8);
            unk04->P(q - 1);
            unk04->P(q);
            unk04->A(d);
            unk04->C(e);
        }
    }
    bool ok;
    char t;
    if (unk04 && *unk04->Q(&t)) ok = true; else ok = false;
    Obj8* o = unk08;
    o->unk18 = -1; o->unk1c = -1;
    LeaveCriticalSection(o);
    return !ok;
}
}   // namespace f3m_00a61e50

// @f3 0x00a6dbd0 (community match, verified in this file)
namespace f3m_00a6dbd0 {
struct __declspec(align(16)) DbgLineVec4
{
    float x;
    float y;
    float z;
    float w;
    DbgLineVec4() {}
    DbgLineVec4(const DbgLineVec4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
    DbgLineVec4& operator=(const DbgLineVec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
    void setTransformedPos(const struct DbgLineTransform& t, const DbgLineVec4& p);
};

struct DbgLineTransform
{
    DbgLineVec4 m_col0;
    DbgLineVec4 m_col1;
    DbgLineVec4 m_col2;
    DbgLineVec4 m_translation;
    void setMul(const DbgLineTransform& a, const DbgLineTransform& b);
};

struct DbgLineThreadMemory
{
    void deallocateChunk(void* p, int nbytes, int cls);
};

extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

template <class T> inline void DbgLineDeallocateChunk(T* const& p, int numElements, int memoryClass)
{
    DbgLineThreadMemory* mem = (DbgLineThreadMemory*)TlsGetValue(DAT_010f3170);
    mem->deallocateChunk(p, numElements * sizeof(T), memoryClass);
}

struct DbgLineVecArray
{
    DbgLineVec4* m_data;
    int m_size;
    int m_capacityAndFlags;
    int getCapacity() const
    {
        return m_capacityAndFlags & 0x3fffffff;
    }
    void releaseMemory()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
            DbgLineDeallocateChunk(m_data, getCapacity(), 0x17);
    }
};

struct DbgLinePointSource
{
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
    virtual void getPoints(DbgLineVecArray& points);
};

struct DbgLineDrawer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void drawLine(const DbgLineVec4& a, const DbgLineVec4& b, unsigned int color, int id);
};

struct DbgLineScene
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    DbgLinePointSource* m_points;
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
    DbgLineTransform m_motionTransform;
    void getEndPoint(const void* in, DbgLineVec4* out);
};

struct DbgLineExtra
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
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    DbgLineVec4 m_endPoint;
};

struct DbgLineInput
{
    int unk00;
    int unk04;
    int unk08;
    DbgLineScene* m_scene;
    int unk10;
    DbgLineExtra* m_extra;
};

struct DbgLineProcessor
{
    void begin(DbgLineDrawer* drawer);
};

extern float DAT_00dbea4c;
unsigned int __cdecl PackColorBigEndian(float r, float g, float b, float a);

struct DbgLineViewer
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
    DbgLineVec4 m_endPoint;
    DbgLineVec4 m_vContactPosition;
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
    DbgLineProcessor m_processor;

    void computeTransforms(DbgLineInput* input, DbgLineTransform* local, DbgLineTransform* extra);
    void updateA(int id);
    void updateB(int id);
    void FUN_00a6dbd0(DbgLineInput* input, DbgLineDrawer* drawer, int id);
};

// pdb: hkpPointToPathDrawer::drawConstraint | hkpPointToPathDrawer.obj | fnv360_0822_retail, call_gap, medium
// pdb params: constraint, displayHandler, id, tag
void DbgLineViewer::FUN_00a6dbd0(DbgLineInput* input, DbgLineDrawer* drawer, int id)
{
    DbgLineScene* scene = input->m_scene;
    DbgLineTransform localTransform;
    DbgLineTransform worldTransform;
    DbgLineTransform extraTransform;

    m_processor.begin(drawer);
    computeTransforms(input, &localTransform, &extraTransform);
    m_vContactPosition = localTransform.m_translation;
    scene->getEndPoint(&input->m_extra->m_endPoint, &m_endPoint);
    updateA(id);
    updateB(id);

    if (scene->m_points)
    {
        worldTransform.setMul(localTransform, scene->m_motionTransform);
        DbgLinePointSource* source = scene->m_points;
        if (source)
        {
            DbgLineVecArray points;
            points.m_data = 0;
            points.m_size = 0;
            points.m_capacityAndFlags = 0x80000000;
            source->getPoints(points);
            int numPoints = points.m_size;
            for (int i = 1; i < numPoints; i++)
            {
                DbgLineVec4 a;
                DbgLineVec4 b;
                DbgLineVec4 p = points.m_data[i];
                a.setTransformedPos(worldTransform, p);
                p = points.m_data[i - 1];
                b.setTransformedPos(worldTransform, p);
                drawer->drawLine(a, b, PackColorBigEndian(0.0f, DAT_00dbea4c, 1.0f, 1.0f), id);
            }
            points.releaseMemory();
        }
    }
}
}   // namespace f3m_00a6dbd0

// @f3 0x00a6e460 (community match, verified in this file)
#include <math.h>
namespace f3m_00a6e460 {
unsigned int PackColorBigEndian(float r, float g, float b, float a);
struct QTransform;
struct __declspec(align(16)) QVec4 {
    float x, y, z, w;
    void hkVector4_setTransformedPos(const QTransform& t, const QVec4& v);
};
struct __declspec(align(16)) QTransform { QVec4 col0, col1, col2, pos; };
struct QBody {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    QVec4 v20; QVec4 v30; int unk40; float f44;
};
struct QArg { int unk00; int unk04; int unk08; QBody* body; };
struct QDisplay {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void displayLine(const QVec4& a, const QVec4& b, unsigned int color, int tag);
};
struct QC0 { void FUN_00a8f460(QDisplay* d); };
struct QThis {
    void FUN_00a6aa20(QArg* a, QTransform& t1, QTransform& t2);
    void FUN_00a6a750(int tag);
    void FUN_00a6a7b0(int tag);
    void FUN_00a6e460(QArg* a, QDisplay* d, int tag);
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    QVec4 v40; QVec4 v50;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC;
    QC0 cC0;
};
// pdb: hkpStiffSpringDrawer::drawConstraint | hkpStiffSpringDrawer.obj | fnv360_0822_retail, call_gap, medium
// pdb params: constraint, displayHandler, id, tag
void QThis::FUN_00a6e460(QArg* a, QDisplay* d, int tag)
{
    QBody* body = a->body;
    cC0.FUN_00a8f460(d);
    QTransform t1;
    QTransform t2;
    FUN_00a6aa20(a, t1, t2);
    QVec4& end = v50;
    end.hkVector4_setTransformedPos(t1, body->v30);
    QVec4& start = v40;
    start.hkVector4_setTransformedPos(t2, body->v20);
    FUN_00a6a750(tag);
    FUN_00a6a7b0(tag);
    float radius = body->f44;
    QVec4 dir;
    dir.x = end.x - start.x;
    dir.y = end.y - start.y;
    dir.z = end.z - start.z;
    dir.w = end.w - start.w;
    float lenSq = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
    float inv;
    if (lenSq != 0.0f) inv = 1.0f / sqrtf(lenSq);
    else inv = 0.0f;
    dir.x *= inv; dir.y *= inv; dir.z *= inv; dir.w *= inv;
    dir.x *= radius; dir.y *= radius; dir.z *= radius; dir.w *= radius;
    dir.x = start.x + dir.x;
    dir.y = start.y + dir.y;
    dir.z = start.z + dir.z;
    dir.w = start.w + dir.w;
    d->displayLine(start, dir, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), tag);
    d->displayLine(dir, end, 0xffff0000, tag);
}
}   // namespace f3m_00a6e460

// @f3 0x00a6f090 (community match, verified in this file)
namespace f3m_00a6f090 {
unsigned int __cdecl PackColorBigEndian(float r, float g, float b, float a);

struct __declspec(align(16)) QA32Rot { float m[12]; };
struct __declspec(align(16)) QA32Xf { float m[16]; };

struct __declspec(align(16)) QA32V4 {
    float x, y, z, w;
    void hkVector4_setTransformedPos(const QA32Xf& t, const QA32V4& p);
    void hkVector4_setRotatedDir(const QA32Rot& r, const QA32V4& d);
    inline void setMul4(float s, const QA32V4& v) { x = v.x * s; y = v.y * s; z = v.z * s; w = v.w * s; }
    inline void add4(const QA32V4& v) { x += v.x; y += v.y; z += v.z; w += v.w; }
};

struct QA32Obj {
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
    QA32V4 unk50;
    QA32V4 unk60;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    QA32V4 unk90;
};

struct QA32Body { int unk00; int unk04; int unk08; QA32Obj* unk0c; };

struct QA32Disp {
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void displayLine(const QA32V4& a, const QA32V4& b, unsigned int color, int tag);
};

struct QA32Sub { void FUN_00a8f460(QA32Disp* d); };

struct QA32 {
    float unk00;
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
    QA32V4 unk40;
    QA32V4 unk50;
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
    QA32Rot unk90;
    QA32Sub unkc0;

    void FUN_00a6aa20(QA32Body* b, QA32Xf* t1, QA32Xf* t2);
    void FUN_00a6a7b0(int tag);
    void FUN_00a6a750(int tag);
    void FUN_00a6f090(QA32Body* body, QA32Disp* disp, int tag);
};

// pdb: hkpBallSocketDrawer::drawConstraint | hkpBallSocketDrawer.obj | fnv360_0822_retail, call_gap, low, conflict (bridge: hkpHingeDrawer::drawConstraint)
// pdb params: constraint, displayHandler, id, tag
void QA32::FUN_00a6f090(QA32Body* body, QA32Disp* disp, int tag)
{
    QA32Obj* obj = body->unk0c;
    unkc0.FUN_00a8f460(disp);
    QA32Xf t1;
    QA32Xf t2;
    FUN_00a6aa20(body, &t1, &t2);
    unk50.hkVector4_setTransformedPos(t1, obj->unk90);
    unk40.hkVector4_setTransformedPos(t2, obj->unk50);
    FUN_00a6a7b0(tag);
    FUN_00a6a750(tag);
    disp->displayLine(unk40, unk50, 0xffff0000, tag);
    QA32V4 dir;
    dir.hkVector4_setRotatedDir(unk90, obj->unk60);
    QA32V4 a;
    a.setMul4(unk00 * 0.5, dir);
    a.add4(unk50);
    QA32V4 b;
    b.setMul4(unk00 * -0.5, dir);
    b.add4(unk50);
    disp->displayLine(b, a, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), tag);
}
}   // namespace f3m_00a6f090

// @f3 0x00a75f80 (community match, verified in this file)
namespace f3m_00a75f80 {


namespace f3m_00a75f80 {

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    float lengthSquared3() const
    {
        return x * x + y * y + z * z;
    }
};

extern "C" void __cdecl FUN_00901f10(void* array, int elementSize);

template <typename T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
    void pushBack(const T& t)
    {
        if (m_size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        m_data[m_size++] = t;
    }
};

struct PathLengths
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkArray<hkVector4> m_points;
    hkArray<float> m_lengths;

    void FUN_00a75f80(const hkVector4& point);
};

// pdb: hkpLinearParametricCurve::addPoint | hkpLinearParametricCurve.obj | tesv_win, objrun_open, low
void PathLengths::FUN_00a75f80(const hkVector4& point)
{
    m_points.pushBack(point);
    if (m_points.getSize() == 1)
    {
        m_lengths.pushBack(0.0f);
    }
    else
    {
        const hkVector4 previous = m_points[m_points.getSize() - 2];
        hkVector4 d;
        d.setSub4(point, previous);
        const float length = sqrtf(d.lengthSquared3()) + m_lengths[m_lengths.getSize() - 1];
        m_lengths.pushBack(length);
    }
}

}
}   // namespace f3m_00a75f80

// @f3 0x00a77290 (community match, verified in this file)
namespace f3m_00a77290 {
namespace f3m_00a77290 {


static __forceinline float min2(float a, float b)
{
    return a < b ? a : b;
}

static __forceinline float max2(float a, float b)
{
    return a > b ? a : b;
}

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    void setAll3(float r)
    {
        x = r;
        y = r;
        z = r;
        w = 0.0f;
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
};

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
};

struct hkTransform;

struct __declspec(align(16)) hkpShapeBuffer
{
    unsigned int m_data[128];
};

class hkpShape
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void getAabb(const hkTransform& localToWorld, float tolerance, hkAabb& out) const;

    int m_memSizeAndFlags;
    int m_userData;
    int m_type;
};

class hkpShapeContainer
{
public:
    virtual void vf00();
    virtual int getNumChildShapes() const;
    virtual unsigned int getFirstKey() const;
    virtual unsigned int getNextKey(unsigned int oldKey) const;
    virtual unsigned int getCollisionFilterInfo(unsigned int key) const;
    virtual const hkpShape* getChildShape(unsigned int key, hkpShapeBuffer& buffer) const;
};

class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
public:
    void FUN_00a77290(const hkTransform& localToWorld, float tolerance, hkAabb& out) const;
};

// pdb: hkpConvexPieceMeshShape::getAabbImpl | hkpConvexPieceMeshShape.obj | fnv360_0822_retail, objrun, low
// pdb params: localToWorld, tolerance, out
void hkpShapeCollection::FUN_00a77290(const hkTransform& localToWorld, float tolerance, hkAabb& out) const
{
    out.m_min.setAll3(3.40282e38f);
    out.m_max.setAll3(-3.40282e38f);

    hkpShapeBuffer buffer;
    for (unsigned int key = getFirstKey(); key != 0xffffffff; key = getNextKey(key))
    {
        const hkpShape* child = getChildShape(key, buffer);
        hkAabb childAabb;
        child->getAabb(localToWorld, tolerance, childAabb);
        out.m_min.setMin4(out.m_min, childAabb.m_min);
        out.m_max.setMax4(out.m_max, childAabb.m_max);
    }
}

}
}   // namespace f3m_00a77290

// @f3 0x00a7c820 (community match, verified in this file)
namespace f3m_00a7c820 {
namespace f3m_00a7c820 {
struct Vec4 {
 float x, y, z, w;
 __forceinline Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
 __forceinline void setZero() { x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f; }
};
struct __declspec(align(16)) State {
 Vec4 a0, a1, a2, a3, b0, b1, b2, b3, c0, c1, c2, c3;
 __forceinline State& operator=(const State& o) {
  a0 = o.a0; a1 = o.a1; a2 = o.a2; a3 = o.a3; b0 = o.b0; b1 = o.b1; b2 = o.b2; b3 = o.b3;
  c0 = o.c0; c1 = o.c1; c2 = o.c2; c3 = o.c3; return *this;
 }
 __forceinline void setZero() {
  a0.setZero(); a1.setZero(); a2.setZero(); a3.setZero();
  b0.setZero(); b1.setZero(); b2.setZero(); b3.setZero();
  c0.setZero(); c1.setZero(); c2.setZero(); c3.setZero();
 }
};
struct Elem { State s0, s1, s2, s3, s4; };
struct Mat { Vec4 r0, r1, r2, r3; };
struct Flag { bool notLast; Flag(bool b) : notLast(b) {} };
extern void __cdecl FUN_00a798b0(Flag, Elem*, Mat*, State*, State**);
template <class T> inline T maxOf(T a, T b) { return a >= b ? a : b; }
}
using namespace f3m_00a7c820;

// pdb: hkPoweredChain_UpdateLuDecomposition | hkpPoweredChainSolverUtil.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: firstConstraintToProcess, numConstraints, motorsState, triples
void __cdecl FUN_00a7c820(int start, int end, Mat* mats, Elem* elems)
{
 int first = maxOf(start - 1, 0);
 int i = first;
 State state;
 State* prev;
 if (first) {
  state = elems[i - 1].s4;
  prev = &elems[i - 1].s2;
 } else {
  state.setZero();
  prev = &state;
 }
 for (; i < end; ++i)
  FUN_00a798b0(Flag(end - i - 1 != 0), &elems[i], &mats[i], &state, &prev);
}
}   // namespace f3m_00a7c820

// @f3 0x00a7e290 (community match, verified in this file)
namespace f3m_00a7e290 {
struct __declspec(align(16)) QA16Vec
{
    float x, y, z, w;
    void setSub4(const QA16Vec& a, const QA16Vec& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline int compareLessThan4(const QA16Vec& a) const
    {
        return (x < a.x ? 8 : 0) | (y < a.y ? 4 : 0) | (z < a.z ? 2 : 0) | (w < a.w ? 1 : 0);
    }
};

struct QA16Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    QA16Vec* m_p0;
    int unk14;
    int unk18;
    int unk1C;
    QA16Vec* m_p1;
    int unk24;
    int unk28;
    int unk2C;
    QA16Vec* m_p2;
};

struct QA16Edges
{
    QA16Vec e0;
    QA16Vec e1;
    QA16Vec e2;
};

struct QA16Bary : QA16Vec
{
    void FUN_00477880(const QA16Edges* edges, const QA16Tri* tri);
};

struct QA16Shape
{
    int unk00;
    int unk04;
    int unk08;
    int m_0C;
    int m_10;
    int FUN_00a7fed0(const QA16Tri* tri, const QA16Vec* pos, int* a, int* b);
    int FUN_00a991d0(int a, int b, const QA16Vec* pos);
};

struct QA16Tester
{
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
    QA16Vec m_40;
    int FUN_00a7e290(QA16Shape* shape, const QA16Tri* tri, const QA16Vec* pos, int* result);
};

// pdb: hkpConvexPenetrationUtil::tryToExpandPolytope | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, call_dedup, low
// pdb params: we, nearestTriangle, newVertex, failureReason
int QA16Tester::FUN_00a7e290(QA16Shape* shape, const QA16Tri* tri, const QA16Vec* pos, int* result)
{
    QA16Edges edges;
    edges.e0.setSub4(*pos, *tri->m_p0);
    edges.e1.setSub4(*pos, *tri->m_p1);
    edges.e2.setSub4(*pos, *tri->m_p2);
    QA16Bary bary;
    bary.FUN_00477880(&edges, tri);
    if (bary.compareLessThan4(m_40) & 0xe)
    {
        *result = 0;
        return 1;
    }
    int a = 0;
    int b;
    if (shape->FUN_00a7fed0(tri, pos, &a, &b))
    {
        *result = 3;
        return 1;
    }
    if (shape->m_0C - shape->m_10 + 100 < a)
    {
        *result = 2;
        return 1;
    }
    if (shape->FUN_00a991d0(a, b, pos))
    {
        *result = 3;
        return 1;
    }
    return 0;
}
}   // namespace f3m_00a7e290

// @f3 0x00a7e6e0 (community match, verified in this file)
namespace f3m_00a7e6e0 {
namespace f3m_00a7e6e0 {
struct __declspec(align(16)) QVec4 { float x, y, z, w; };
struct QRes {
    QVec4 pos;
    QVec4 unk10;
    QVec4 unk20;
    int unk30;
    QRes& FUN_008e9460(const QRes& o);
};
struct QThis {
    void FUN_00a7e0c0(const QVec4& plane, QRes* out);
    void FUN_00a7e6e0(const QVec4& plane, const QVec4& point, QRes* best, float* dist);
};
// pdb: hkpConvexPenetrationUtil::findBestProjection | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, objrun, medium
// pdb params: direction, from, result, bestDistanceOut
void QThis::FUN_00a7e6e0(const QVec4& plane, const QVec4& point, QRes* best, float* dist)
{
    QVec4 neg;
    neg.x = -plane.x;
    neg.y = -plane.y;
    neg.z = -plane.z;
    neg.w = -plane.w;
    QRes r;
    FUN_00a7e0c0(plane, &r);
    FUN_00a7e0c0(neg, best);
    float d1;
    {
        QVec4 d;
        d.x = r.pos.x - point.x;
        d.y = r.pos.y - point.y;
        d.z = r.pos.z - point.z;
        d1 = plane.x * d.x + plane.y * d.y + plane.z * d.z;
    }
    float d2;
    {
        QVec4 d;
        d.x = best->pos.x - point.x;
        d.y = best->pos.y - point.y;
        d.z = best->pos.z - point.z;
        d2 = d.x * neg.x + d.y * neg.y + d.z * neg.z;
    }
    if (d1 >= d2) {
        best->FUN_008e9460(r);
        *dist = d1;
    } else {
        *dist = d2;
    }
}
}
}   // namespace f3m_00a7e6e0

// @f3 0x00a798b0 (community match, verified in this file)
namespace f3m_00a798b0 {


namespace f3m_00a798b0 {

struct hkQuadReal { float v[4]; };

class __declspec(align(16)) hkVector4
{
public:
    hkQuadReal m_quad;
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& o)
    {
        m_quad.v[0] = o.m_quad.v[0];
        m_quad.v[1] = o.m_quad.v[1];
        m_quad.v[2] = o.m_quad.v[2];
        m_quad.v[3] = o.m_quad.v[3];
    }
    __forceinline void operator=(const hkVector4& o)
    {
        m_quad.v[0] = o.m_quad.v[0];
        m_quad.v[1] = o.m_quad.v[1];
        m_quad.v[2] = o.m_quad.v[2];
        m_quad.v[3] = o.m_quad.v[3];
    }
    __forceinline float& operator()(int i) { return m_quad.v[i]; }
};

class hkMatrix3
{
public:
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline void operator=(const hkMatrix3& o)
    {
        m_col0 = o.m_col0;
        m_col1 = o.m_col1;
        m_col2 = o.m_col2;
    }
    __forceinline float& operator()(int r, int c) { return (&m_col0)[c](r); }
};

class hkMatrix6
{
public:
    hkMatrix3 m_m[2][2];
    __forceinline void operator=(const hkMatrix6& o)
    {
        m_m[0][0] = o.m_m[0][0];
        m_m[0][1] = o.m_m[0][1];
        m_m[1][0] = o.m_m[1][0];
        m_m[1][1] = o.m_m[1][1];
    }
};

template <typename T>
__forceinline T max2(T a, T b) { return a > b ? a : b; }

struct S00a798b0_Obj
{
    hkMatrix6 m000;
    hkMatrix6 m0c0;
    hkMatrix6 m180;
    hkMatrix6 m240;
    hkMatrix6 m300;
};

struct S00a798b0_P1;
struct S00a798b0_P3;

void __cdecl FUN_00a79690(S00a798b0_P3* p3, S00a798b0_P1* p1, hkMatrix6* a, hkMatrix6* b);
void __cdecl FUN_00a797b0(S00a798b0_P3* p3, hkMatrix6* out);
void __cdecl FUN_00a97fa0(S00a798b0_Obj* obj, hkMatrix6* m);
void __cdecl FUN_00a98480(hkMatrix6* out, const hkMatrix6* a, const hkMatrix6* b);
void __cdecl FUN_00a98230(hkMatrix6* m, const hkMatrix6* c);
void __cdecl FUN_00a98f40(hkMatrix6* m, const hkMatrix6* e);

// pdb: hkPoweredChain_ComputeConstraintMatrixLuDecomposition_ForOneRow | hkpPoweredChainSolverUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: isNotLastRow, triple, motorsState, mtxPrevOffdiag, triplePrevUpper
void __cdecl FUN_00a798b0(S00a798b0_P1* p1, S00a798b0_Obj* obj, S00a798b0_P3* p3, hkMatrix6* p4, hkMatrix6** p5)
{
    hkMatrix6 a = obj->m240;
    hkMatrix6 b = obj->m300;
    FUN_00a79690(p3, p1, &a, &b);
    FUN_00a797b0(p3, p4);
    FUN_00a97fa0(obj, p4);
    hkMatrix6 c;
    FUN_00a98480(&c, &obj->m000, *p5);
    obj->m0c0 = a;
    FUN_00a98230(&obj->m0c0, &c);

    const float eps = 1.1920928955078125e-07f;
    obj->m0c0.m_m[0][0](0,0) = max2(obj->m0c0.m_m[0][0](0,0), eps);
    obj->m0c0.m_m[1][1](0,0) = max2(obj->m0c0.m_m[1][1](0,0), eps);
    obj->m0c0.m_m[0][0](1,1) = max2(obj->m0c0.m_m[0][0](1,1), eps);
    obj->m0c0.m_m[1][1](1,1) = max2(obj->m0c0.m_m[1][1](1,1), eps);
    obj->m0c0.m_m[0][0](2,2) = max2(obj->m0c0.m_m[0][0](2,2), eps);
    obj->m0c0.m_m[1][1](2,2) = max2(obj->m0c0.m_m[1][1](2,2), eps);

    hkMatrix6 e = obj->m0c0;
    FUN_00a98f40(&obj->m0c0, &e);
    FUN_00a98480(&obj->m180, &obj->m0c0, &b);
    *p4 = obj->m300;
    *p5 = &obj->m180;
}

}
}   // namespace f3m_00a798b0

// @f3 0x00a72170 (community match, verified in this file)
#include <math.h>
namespace f3m_00a72170 {

typedef float Simd_a72170;
inline float Abs_a72170(float r)
{
    return (float)fabs(r);
}
inline float Sqrt_a72170(float r)
{
    return (float)sqrt(r);
}
inline float SqrtInverse_a72170(float r)
{
    return 1.0f / Sqrt_a72170(r);
}
struct __declspec(align(16)) Vec_a72170
{
    float x, y, z, w;
    float& operator()(int i) { return (&x)[i]; }
    const float& operator()(int i) const { return (&x)[i]; }
    Vec_a72170& operator=(const Vec_a72170& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
    void set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    void setZero4() { x = y = z = w = 0.0f; }
    __forceinline void mul4(Simd_a72170 rs)
    {
        float s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline Simd_a72170 lengthInverse3() const
    {
        float l2 = ((x * x + y * y)) + z * z;
        return l2 ? SqrtInverse_a72170(l2) : 0.0f;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    void setCross(const Vec_a72170& v1, const Vec_a72170& v2)
    {
        const float nx = v1.y * v2.z - v1.z * v2.y;
        const float ny = v1.z * v2.x - v1.x * v2.z;
        const float nz = v1.x * v2.y - v1.y * v2.x;
        set(nx, ny, nz, 0.0f);
    }
};

__forceinline void Perp_a72170(const Vec_a72170& vectorIn, Vec_a72170& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;
    float a0 = Abs_a72170(vectorIn(0));
    float a1 = Abs_a72170(vectorIn(1));
    float a2 = Abs_a72170(vectorIn(2));
    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }
    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }
    biVectorOut.setZero4();
    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = (-vectorIn(ok1));
}

struct Rot_a72170
{
    Vec_a72170 col0;
    Vec_a72170 col1;
    Vec_a72170 col2;
    Vec_a72170& getColumn(int i) { return (&col0)[i]; }
    void setIdentity()
    {
        Vec_a72170 zero;
        zero.setZero4();
        col0 = zero;
        col1 = zero;
        col2 = zero;
        col0(0) = 1.0f;
        col1(1) = 1.0f;
        col2(2) = 1.0f;
    }
};

struct Transform_a72170
{
    Rot_a72170 rotation;
    Vec_a72170 translation;
};

class PointToPlane_a72170
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Transform_a72170 transformA;
    Transform_a72170 transformB;
    unsigned short unkA0;
    unsigned char axisIndex;
    void FUN_00a72170(const Vec_a72170& pivotA, const Vec_a72170& pivotB, const Vec_a72170& normalB);
};

FNV_STATIC_ASSERT(offsetof(PointToPlane_a72170, transformB) == 0x60);
FNV_STATIC_ASSERT(offsetof(PointToPlane_a72170, axisIndex) == 0xa2);

void PointToPlane_a72170::FUN_00a72170(const Vec_a72170& pivotA, const Vec_a72170& pivotB, const Vec_a72170& normalB)
{
    transformA.translation = pivotA;
    transformB.translation = pivotB;
    transformA.rotation.setIdentity();

    int n = axisIndex;
    Vec_a72170* baseB = &transformB.rotation.getColumn(0);
    baseB[n] = normalB;
    int i1 = (n + 1) % 3;
    Perp_a72170(baseB[n], baseB[i1]);
    baseB[i1].normalize3();
    baseB[(n + 2) % 3].setCross(baseB[n], baseB[i1]);
}
}   // namespace f3m_00a72170

// @f3 0x00a68b40 (community match, verified in this file)
#include <windows.h>
#include <math.h>
namespace f3m_00a68b40 {

extern unsigned DAT_0116913c;  // Monitor stream TLS index
extern unsigned DAT_010f3170;  // Thread memory TLS index

extern const char DAT_00e86fd0[];  // TthkpContactPointViewer::drawAllContactPointsInIsland
extern const char DAT_00e32798[];  // Et
extern const char DAT_00e86fac[];  // TtdisplayArrow (name assumed)
extern "C" void _ReadWriteBarrier(void);  // emits nothing; keeps the name store before the clock read

namespace ContactViewer {

typedef unsigned int hkUint32;

struct TimerCommand {
    const char* name;
    hkUint32 time0, time1;

    __forceinline void setTime() {
        hkUint32 ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        time0 = ticks;
    }
};

struct MonitorStream {
    char* start;
    char* end;
    char* capacity;
    char* capacityMinus16;

    static void mark(const char* name) {
        MonitorStream* stream = static_cast<MonitorStream*>(TlsGetValue(DAT_0116913c));
        if (stream->end < stream->capacityMinus16) {
            TimerCommand* command = reinterpret_cast<TimerCommand*>(stream->end);
            command->name = name;
            _ReadWriteBarrier();
            command->setTime();
            stream->end = reinterpret_cast<char*>(command + 1);
        }
    }
};

struct ProfileScope {
    explicit ProfileScope(const char* name) { MonitorStream::mark(name); }
    ~ProfileScope() { MonitorStream::mark(DAT_00e32798); }
};

struct ThreadMemory {
    virtual void* alignedAllocate(int, int, int);
    virtual void alignedDeallocate(void*);
    virtual void setStackArea(void*, int);
    virtual void releaseCachedMemory();
    virtual ~ThreadMemory();
    virtual void* onStackOverflow(int);
    virtual void onStackUnderflow(void*);

    __declspec(align(16)) void* memory;
    int referenceCount;
    __declspec(align(16)) char* current;
    void* previous;
    char* base;
    char* end;

    static ThreadMemory* instance() {
        return static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170));
    }
    void* allocateStack(int bytes) {
        int actual = (bytes + 16) & ~15;  // Includes the stack allocator's reserved space.
        char* p = current;
        char* next = p + actual;
        if (next <= end) {
            current = next;
            return p;
        }
        return onStackOverflow(actual);
    }
    void deallocateStack(void* p) {
        current = static_cast<char*>(p);
        if (p == base)
            onStackUnderflow(p);
    }
    void FUN_008f6d90(void* block, int bytes, int memoryClass);
};

template<class T> struct Array {
    T* data;
    int size;
    unsigned capacityAndFlags;

    enum { CapacityMask = 0x3fffffff, DontDeallocate = 0x80000000u };
    int getSize() const { return size; }
    T& operator[](int index) { return data[index]; }
    const T& operator[](int index) const { return data[index]; }
};

typedef unsigned short ContactId;
struct ContactIds : Array<ContactId> {
    ContactId* localMemory;

    explicit ContactIds(int capacity) {
        data = 0;
        size = 0;
        capacityAndFlags = DontDeallocate;
        data = static_cast<ContactId*>(
            ThreadMemory::instance()->allocateStack(capacity * sizeof(ContactId)));
        capacityAndFlags = capacity | DontDeallocate;
        localMemory = data;
    }

    ~ContactIds() {
        ContactId* saved = localMemory;
        ThreadMemory::instance()->deallocateStack(saved);
        if (!(capacityAndFlags & DontDeallocate)) {
            int capacity = capacityAndFlags & CapacityMask;
            enum { ArrayMemoryClass = 0x17 };
            ThreadMemory::instance()->FUN_008f6d90(data, capacity * sizeof(ContactId), ArrayMemoryClass);
        }
    }
};

struct __declspec(align(16)) Vec4 { float x, y, z, w; };
struct ContactPoint {
    Vec4 position, separatingNormal;
    const Vec4& getPosition() const { return position; }
    const Vec4& getSeparatingNormal() const { return separatingNormal; }
};

struct DisplayHandler {
    virtual ~DisplayHandler();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void displayLine(const Vec4& start, const Vec4& end, int color, int tag);
};

struct Vector4 : Vec4 {
    float& operator()(int i) { return (&x)[i]; }
    const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void setAdd4(const Vec4& a, const Vec4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    __forceinline void mul4(float s) { x *= s; y *= s; z *= s; w *= s; }
    __forceinline void setInterpolate4(const Vec4& a, const Vec4& b, float t) {
        const float s = 1.0f - t;
        x = s * a.x + t * b.x; y = s * a.y + t * b.y; z = s * a.z + t * b.z; w = s * a.w + t * b.w;
    }
    __forceinline void setAddMul4(const Vec4& a, const Vec4& b, float r) { x = a.x + b.x * r; y = a.y + b.y * r; z = a.z + b.z * r; w = a.w + b.w * r; }
};

static __forceinline float lengthSquared3(const Vec4& v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
static __forceinline float length3(const Vec4& v) { return (float)sqrt(lengthSquared3(v)); }

static __forceinline void normalize3(Vector4& v) {
    float lengthSquared = lengthSquared3(v);
    float invLength;
    if (lengthSquared != 0.0f)
        invLength = 1.0f / (float)sqrt(lengthSquared);
    else
        invLength = 0.0f;
    v.mul4(invLength);
}

static __forceinline void calculatePerpendicularVector(const Vec4& vin, Vector4& out) {
    const Vector4& in = static_cast<const Vector4&>(vin);
    int minIndex = 0;
    int ok1 = 1;
    int ok2 = 2;
    float a0 = fabsf(in(0));
    float a1 = fabsf(in(1));
    float a2 = fabsf(in(2));
    if (a1 < a0) {
        ok1 = 0;
        minIndex = 1;
        a0 = a1;
    }
    if (a2 < a0) {
        ok2 = minIndex;
    }
    out.x = out.y = out.z = out.w = 0.0f;
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

// hkContactPointViewer's displayArrow helper.
// Havok displayArrow (0x00a687a0): draws from -> from+dir plus a two-line arrow head.
// Defined here, static and noinline, as in the original file: the compiler then gives it a private convention
// (from in ECX, dir in EAX, rest on the stack), which the caller below relies on. throw() keeps the
// ProfileScope destructor from adding an EH frame, which would change that convention.
static __declspec(noinline) void FUN_00a687a0(DisplayHandler* handler, const Vec4& from, const Vec4& dir,
                                             int color, int tag) throw()
{
    ProfileScope timer(DAT_00e86fac);
    if (lengthSquared3(dir) < 1.192092896e-07f)  // FLT_EPSILON
        return;
    Vector4 to; to.setAdd4(from, dir);
    Vector4 ort; calculatePerpendicularVector(dir, ort);
    normalize3(ort);
    ort.mul4(length3(dir));
    const float c = 0.85f;  // arrow head starts at 85% of the shaft; head width = (1 - c) * length
    Vector4 p; p.setInterpolate4(from, to, c);
    Vector4 p2; p2.setAddMul4(p, ort, 1.0f - c);
    Vector4 p3; p3.setAddMul4(p, ort, -(1.0f - c));
    handler->displayLine(from, to, color, tag);
    handler->displayLine(to, p2, color, tag);
    handler->displayLine(to, p3, color, tag);
}

struct StatisticsCollector;
struct ClassInfo;
struct CdBody;
struct CollisionInput;
struct CollisionOutput;
struct CollisionCache;
struct ConstraintOwner;
struct Collidable;
struct CollisionData;
struct ContactProperties;
struct World;

struct Referenced {
    virtual ~Referenced();
    virtual void calcStatistics(StatisticsCollector*) const;
    virtual void calcContentStatistics(StatisticsCollector*, const ClassInfo*) const;
    unsigned short memorySizeAndFlags;
    short referenceCount;
};

struct ContactManager : Referenced {
    enum Type { SimpleConstraint, Report, ConvexList, Null, User };
    enum Result { Success, Failure };
    enum ToiAccept { Accept, Reject };

    virtual ContactId addContactPointImpl(const CdBody&, const CdBody&, const CollisionInput&,
                                          CollisionOutput&, const CollisionCache*, ContactPoint&) = 0;
    virtual Result reserveContactPointsImpl(int) = 0;
    virtual void removeContactPointImpl(ContactId, ConstraintOwner&) = 0;
    virtual void processContactImpl(const Collidable&, const Collidable&, const CollisionInput&,
                                    CollisionData&) = 0;
    virtual ToiAccept addToiImpl(const CdBody&, const CdBody&, const CollisionInput&, CollisionOutput&,
                                 float, ContactPoint&, const CollisionCache*, float&, ContactProperties&) = 0;
    virtual void removeToiImpl(ConstraintOwner&, ContactProperties&) = 0;
    virtual void cleanup();
    virtual ContactProperties* getContactPointProperties(ContactId);
    virtual ContactPoint* getContactPoint(ContactId);
    virtual void getAllContactPointIds(Array<ContactId>&) const;
    virtual Type getType() const = 0;

    Type type;
    World* world;
};

struct SimpleConstraintContactManager : ContactManager {};

struct AgentEntry {
    unsigned char streamCommand, agentType, numContactPoints, size;
    unsigned short agentIndexOnCollidable[2];
    ContactManager* manager;
};

inline AgentEntry* addBytes(AgentEntry* p, unsigned n) {
    return reinterpret_cast<AgentEntry*>(reinterpret_cast<char*>(p) + n);
}

struct Sector {
    unsigned char bytes[512];
    AgentEntry* begin() { return reinterpret_cast<AgentEntry*>(bytes); }
    AgentEntry* end() { return reinterpret_cast<AgentEntry*>(bytes + sizeof(bytes)); }
};

struct AgentTrack {
    unsigned bytesUsedInLastSector;
    Array<Sector*> sectors;
    Sector* firstSector;
};

struct Island : Referenced {
    int maxSchemaSize, schemaSize, numSolverResults, numSolverTemps;
    World* world;
    int numConstraints;
    unsigned short storageIndex, dirtyListIndex;
    unsigned char splitFrame, islandFlags, integrateFlags;
    unsigned accessThread;
    short markCount;
    unsigned short markBitStack;
    float timeSinceHighCheck, timeSinceLowCheck;
    Array<void*> actions;
    float deactivationTime;
    Array<void*> entities;
    void* firstEntity;
    AgentTrack agentTrack;
};

struct Process {
    virtual ~Process();
    virtual int getProcessTag() = 0;
    bool selectable;
    void* inStream;
    void* outStream;
    DisplayHandler* displayHandler;
    void* processHandler;
};

struct WorldContextListener { virtual ~WorldContextListener(); };
struct WorldPostSimulationListener { virtual ~WorldPostSimulationListener(); };
struct WorldViewer : Referenced, Process, WorldContextListener {
    void* context;
};
struct Viewer : WorldViewer, WorldPostSimulationListener {
    const int color;
    void __thiscall FUN_00a68b40(const Island* island) throw();
};

// pdb: hkpContactPointViewer::drawAllContactPointsInIsland | hkpContactPointViewer.obj | fnv360_0822_retail, ustr, medium
// pdb params: island
void __thiscall Viewer::FUN_00a68b40(const Island* island) throw() {
    ProfileScope timer(DAT_00e86fd0);

    for (int sectorIndex = 0; sectorIndex < island->agentTrack.sectors.getSize();) {
        Sector* sector = island->agentTrack.sectors[sectorIndex];
        AgentEntry* entry = sector->begin();
        ++sectorIndex;
        AgentEntry* end = sectorIndex == island->agentTrack.sectors.getSize()
            ? addBytes(entry, island->agentTrack.bytesUsedInLastSector) : sector->end();

        for (; entry < end; entry = addBytes(entry, entry->size)) {
            ContactManager* manager = entry->manager;
            if (manager->getType() == ContactManager::SimpleConstraint) {
                SimpleConstraintContactManager* constraintManager =
                    static_cast<SimpleConstraintContactManager*>(manager);
                ContactIds contactPoints(256);  // stack capacity, as in hkpContactPointViewer
                constraintManager->getAllContactPointIds(contactPoints);
                for (int index = 0; index < contactPoints.getSize(); ++index) {
                    ContactPoint* point = constraintManager->getContactPoint(contactPoints[index]);
                    const Vec4& pos = point->getPosition();
                    const Vec4& normal = point->getSeparatingNormal();
                    FUN_00a687a0(displayHandler, pos, normal, color, getProcessTag());
                }
            }
        }
    }
}

} // namespace ContactViewer
}   // namespace f3m_00a68b40
