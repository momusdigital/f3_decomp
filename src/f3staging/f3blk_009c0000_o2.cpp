#pragma intrinsic(__rdtsc)
#pragma intrinsic(_ReadWriteBarrier)
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_009c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009d5cb0 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009d5cb0 {
struct unkAlloc { void Free(void* p, int n, int t); void* Alloc(int n, int t); };
extern unkAlloc* (__stdcall *FUN_00d9b080)(int);

struct unkBnd { int a, b, c; unkBnd() : a(0), b(0), c(0x80000000) {} };
struct unkElem { int u0, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15; };
struct __declspec(novtable) unkB1 {
    unkB1(float f, int i);
    virtual void v0();
    int unk04; int unk08; int unk0c;
};
struct __declspec(novtable) unkB2 {
    virtual void w0();
    unsigned char unk14; int unk18; int unk1c;
    float unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unkElem* unk50; int unk54; unkElem* unk58; int unk5c;
    short* unk60; int unk64; unsigned int unk68; unsigned char unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    float unkb0; int unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4;
};
struct FUN_009d5cb0 : unkB1, unkB2 {
    FUN_009d5cb0(const FUN_009d5cb0& s);
    virtual void v0();
    virtual void w0();
    void hkpStorageExtendedMeshShape_addTrianglesSubpart(unkElem*);
    void FUN_009d5910(unkElem*);
    void FUN_009e37e0();
};
// pdb: hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape | hkpStorageExtendedMeshShape.obj | fnv360_0822_retail, call_dedup, high
// pdb params: mesh
FUN_009d5cb0::FUN_009d5cb0(const FUN_009d5cb0& s) : unkB1(s.unkb0, s.unk18)
{
    int i = 0;
    volatile int* vp = &unkc0;
    vp[0] = i; vp[1] = i; vp[2] = 0x80000000; vp[3] = i; vp[4] = i; vp[5] = 0x80000000;
    unk20 = s.unk20; unk24 = s.unk24; unk28 = s.unk28; unk2c = s.unk2c;
    unk08 = s.unk08;
    unk14 = s.unk14;
    for (; i < s.unk54; i++) hkpStorageExtendedMeshShape_addTrianglesSubpart(&s.unk50[i]);
    for (i = 0; i < s.unk5c; i++) FUN_009d5910(&s.unk58[i]);
    int cap = unk68 & 0x3fffffff;
    if (cap < s.unk64) {
        unkAlloc* (__stdcall *get)(int) = FUN_00d9b080;
        if ((unk68 & 0x80000000u) == 0) { unkAlloc* a = get(DAT_010f3170); a->Free(unk60, cap * 2, 0x17); }
        unkAlloc* b = get(DAT_010f3170);
        unk60 = (short*)b->Alloc(s.unk64 * 2, 0x17);
        unk68 = (unk68 & 0x40000000) | s.unk64;
    }
    int n = s.unk64;
    unk64 = n;
    short* d = unk60;
    const char* sc = (const char*)*(short* const volatile*)&s.unk60;
    if (n > 0) {
        int diff = sc - (const char*)d;
        do { *d = *(const short*)((const char*)d + diff); d++; } while (--n);
    }
    unk6c = s.unk6c;
    FUN_009e37e0();
}
}   // namespace f3m_009d5cb0

// @f3 0x009df310 (community match, verified in this file)
namespace f3m_009df310 {
// clm_8aff894bb91f435ba44b: FUN_009df310 (variant A)
struct ListArr {
    unsigned int* pData;
    unsigned int count;
    unsigned int unk8;     // Parent+0x24: capacity with flags (mask 0x3fffffff)
};

struct Parent {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    ListArr list;          // +0x1c
};

void __cdecl FUN_00901f10(ListArr* list, int n);

struct Owner {
    int unk00;
    Parent* m_parent;      // +4
    void FUN_009df310(unsigned int v);
};

void Owner::FUN_009df310(unsigned int v)
{
    ListArr* list = &m_parent->list;
    if (list->count == (list->unk8 & 0x3fffffff)) {
        FUN_00901f10(list, 4);
    }
    list->pData[list->count] = 6;
    list->count++;

    list = &m_parent->list;
    if (list->count == (list->unk8 & 0x3fffffff)) {
        FUN_00901f10(list, 4);
    }
    list->pData[list->count] = v;
    list->count++;

    Parent* p = m_parent;
    p->unk08++;
    p->unk0c++;
    p->unk04 += 0x30;
}
}   // namespace f3m_009df310

// @f3 0x009d9510 (community match, verified in this file)
namespace f3m_009d9510 {
namespace f3m_009d9510 {

struct Result {
    int unk00;
    bool done;
};

struct Handler {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void Handle(void* context, void* data, void* arg, Result* result);
};

struct Entry {
    Handler* handler;
    void* data;
};

struct Owner {
    char unk00[0x6c];
    void* unk6C;
};

struct Dispatcher {
    int unk00;
    int unk04;
    Owner* owner;
    int unk0C;
    char context[0x140];
    Entry* entries;
    int count;
    void FUN_009d9510(Result* result, void* arg);
};

// pdb: hkpCachingShapePhantom::getPenetrations | hkpCachingShapePhantom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: collector, input
void Dispatcher::FUN_009d9510(Result* result, void* arg)
{
    if (!arg)
        arg = owner->unk6C;
    for (int i = count - 1; i >= 0; i--) {
        Entry& e = entries[i];
        e.handler->Handle(context, e.data, arg, result);
        if (result->done)
            break;
    }
}

}
}   // namespace f3m_009d9510

// @f3 0x009df480 (community match, verified in this file)
namespace f3m_009df480 {
extern void __cdecl FUN_00901f10(void* apArray, int aiElemSize);

struct F3Array
{
    int* m_pData;                     // +0x00
    int m_iSize;                      // +0x04
    unsigned int m_uCapacityAndFlags; // +0x08

    void AddBack(int aiValue);
};

struct F3Writer
{
    int unk00;         // +0x00
    int m_iBits;       // +0x04
    int m_iCountA;     // +0x08
    int m_iCountB;     // +0x0C
    int unk10;         // +0x10
    int unk14;         // +0x14
    int unk18;         // +0x18
    F3Array m_kArray;  // +0x1C

    void Add();
};

struct F3Owner
{
    int unk00;           // +0x00
    F3Writer* m_pkWriter;// +0x04

    void FUN_009df480(int aiValue);
};

void F3Array::AddBack(int aiValue)
{
    if (m_iSize == (int)(m_uCapacityAndFlags & 0x3fffffff))
        FUN_00901f10(this, 4);
    m_pData[m_iSize] = aiValue;
    m_iSize = m_iSize + 1;
}

void F3Writer::Add()
{
    m_iCountA = m_iCountA + 1;
    m_iCountB = m_iCountB + 1;
    m_iBits = m_iBits + 0x30;
}

void F3Owner::FUN_009df480(int aiValue)
{
    m_pkWriter->m_kArray.AddBack(0xc);
    m_pkWriter->m_kArray.AddBack(aiValue);
    m_pkWriter->Add();
    m_pkWriter->Add();
}
}   // namespace f3m_009df480

// @f3 0x009cb0c0 (community match, verified in this file)
extern int DAT_010f3170;
extern double DAT_00e7f380;
namespace f3m_009cb0c0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);


struct Rec {
    void* shape;
    int unk04;
    int unk08;
};

struct Obj {
    Rec* record;
};

struct Shape {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    int unk14;
    int unk18;
    int unk1C;
    float unk20;
    int unk24;
    int unk28;
    int unk2C;
    float unk30;
    float FUN_009e5240();
};

struct Node {
    int unk00;
    unsigned short unk04;
    void* FUN_009a2610(void* a, void* b, float v);
};

struct Holder {
    void* FUN_008f6d30(int a, int b);
};

struct Entry {
    void* m_node;
    int m_uiEdgeIndex;
    int unk08;
    Rec* record;
};

struct ObjsArg { Obj** p; };
struct OutArg { Entry* p; };

// pdb: replaceCylindersWithCapsulesInCdBodies | hkpPredGskCylinderAgent3.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
static __declspec(noinline) void replaceCylindersWithCapsulesInCdBodies(int* a, Rec** apRecords, ObjsArg objs, OutArg out)
{
    for (int i = 0; i < 2; ++i)
    {

        if (a[i] != 0)
        {
            Obj* obj = objs.p[i];
            Rec* rec = obj->record;
            Shape* shape = (Shape*)rec->shape;
            Holder* holder = (Holder*)TlsGetValue(DAT_010f3170);
            Node* node = (Node*)holder->FUN_008f6d30(0x40, 0x27);
            node->unk04 = 0x40;
            float t = shape->unk10;
            float val = t + shape->FUN_009e5240() + DAT_00e7f380;
            void* p = node->FUN_009a2610(&shape->unk20, &shape->unk30, val);
            if (out.p)
            {
                Rec* r2 = objs.p[i]->record;
                int u = r2->unk08;
                out.p->record = r2;
                out.p->unk08 = u;
            }
            out.p->m_node = p;
            out.p->m_uiEdgeIndex = -1;
            apRecords[i] = objs.p[i]->record;
            objs.p[i]->record = (Rec*)out.p;
        }
        else
        {
            apRecords[i] = 0;
        }
        out.p += 1;
    }
}

volatile int g_in0;
volatile int g_in1;
volatile Rec* g_r;
volatile Obj* g_o;
volatile Entry* g_out;

void caller_of_FUN_009cb0c0()
{
    int a[2] = { g_in0, g_in1 };
    Rec* recs[2] = { (Rec*)g_r, (Rec*)g_r };
    Obj* objs[2] = { (Obj*)g_o, (Obj*)g_o };
    Entry out[2];
    ObjsArg oa; oa.p = objs;
    OutArg ou; ou.p = out;
    replaceCylindersWithCapsulesInCdBodies(a, recs, oa, ou);
    g_out = out;
}
}   // namespace f3m_009cb0c0

// @f3 0x009d70e0 (community match, verified in this file)
namespace n9d70e0 {
struct Factory {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* Get();
};
extern Factory* DAT_010f3438;
extern int DAT_011693ac;
struct Obj {
    void FUN_009d7020(int a, int b, void* c, int d);
    void FUN_009d70e0(int a, int b);
};
void Obj::FUN_009d70e0(int a, int b)
{
    FUN_009d7020(a, b, DAT_010f3438->Get(), DAT_011693ac);
}
}

// @f3 0x009dfbc0 (community match, verified in this file)
namespace f3m_009dfbc0 {
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct Vec9dfbc0 { float x, y, z, w; };
template <class T> struct hkArr9dfbc0 {
    T* data;
    int size;
    int capFlags;
    void PushBack(const T& t) {
        if (size == (capFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = t;
        size++;
    }
    T& ExpandOne() {
        if (size == (capFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        return data[size++];
    }
};
struct Geom9dfbc0 {
    char pad00[0x10];
    hkArr9dfbc0<Vec9dfbc0> verts;
    hkArr9dfbc0<int> flags;
};
struct Builder9dfbc0 {
    int unk00;
    Geom9dfbc0* geom;
    char pad08[0x10];
    bool dirty;
    int hkpConstraintConstructionKit_setPivotA(const Vec9dfbc0& v);
};
// pdb: hkpConstraintConstructionKit::setPivotA | hkpConstraintConstructionKit.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(call_seq), high
int Builder9dfbc0::hkpConstraintConstructionKit_setPivotA(const Vec9dfbc0& v)
{
    geom->flags.PushBack(1);
    int idx = geom->verts.size;
    Vec9dfbc0& e = geom->verts.ExpandOne();
    e.x = v.x; e.y = v.y; e.z = v.z; e.w = v.w;
    dirty = true;
    return idx;
}
}   // namespace f3m_009dfbc0

// @f3 0x009d4080 (community match, verified in this file)
namespace f3m_009d4080 {
extern unsigned long DAT_010f3170;
struct Alloc4080 { void* FUN_008f6d30(unsigned int bytes, unsigned int tag) throw(); };
extern "C" __declspec(dllimport) Alloc4080* __stdcall TlsGetValue(unsigned long);
class Base4080 {
public:
    virtual void v0();
    unsigned short w4; unsigned short w6; int a8, ac, a10;
    Base4080(int a, int b, int c, int d) throw();
    static void* operator new(unsigned int n) {
        Alloc4080* a = TlsGetValue(DAT_010f3170);
        void* p = a->FUN_008f6d30(n, 0x1f);
        ((Base4080*)p)->w4 = (unsigned short)n;
        return p;
    }
};
class Derived4080 : public Base4080 {
public:
    Derived4080(int a, int b, int c, int d) throw() : Base4080(b, a, c, d) {}
    virtual void v0();
};
// pdb: hkpBvAgent::createShapeBvAgent | hkpBvAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
Base4080* __cdecl hkpBvAgent_createShapeBvAgent(int a, int b, int c, int d) { return new Derived4080(a, b, c, d); }
}

// @f3 0x009ce2a0 (community match, verified in this file)
extern const char DAT_00e7f478[];
namespace f3m_009ce2a0 {
struct Object009ce2a0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(const char* value);
    virtual void f5();
};
void __cdecl FUN_00a26d90(unsigned int a, unsigned int b, Object009ce2a0* object);
// pdb: hkpCollectionCollectionAgent3::calcStatistics | hkpCollectionCollectionAgent3.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl hkpCollectionCollectionAgent3_calcStatistics(unsigned int unused, unsigned int a, unsigned int b, Object009ce2a0* object) {
    object->f4(DAT_00e7f478);
    FUN_00a26d90(a, b, object);
    object->f5();
}
}   // namespace f3m_009ce2a0

// @f3 0x009dac20 (community match, verified in this file)
namespace f3m_009dac20 {
namespace n9dac20 {
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Get(void* out);
};
}
struct Obj9dac20 {
    char pad[0x18];
    n9dac20::Inner* inner;
    void* FUN_009dac20(void* out);
};
// pdb: hkpBreakableConstraintData::isValid | hkpBreakableConstraintData.obj | fnv360_0822_debug, objrun_open, low
void* Obj9dac20::FUN_009dac20(void* out)
{
    inner->Get(out);
    return out;
}
}   // namespace f3m_009dac20

// @f3 0x009c00e0 (community match, verified in this file)
namespace f3m_009c00e0 {
namespace task0789 {
void hkpMultiRayConvexAgent_staticGetPenetrations();
void hkpMultiRayConvexAgent_createConvexMultiRayAgent();
void FUN_009c0170();
void FUN_009c01b0();
void FUN_009c1960();
void hkpMultiRayConvexAgent_createMultiRayConvexAgent();

void hkpMultiRayConvexAgent_staticGetClosestPoints();
void FUN_00a3ab70();
struct Conversion
{
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry
{
    void FUN_00985b30(Conversion*, int, int);
};
// @fnv 0x00d2e760
// pdb: hkpMultiRayConvexAgent::registerAgent | hkpMultiRayConvexAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void FUN_009c00e0(Registry* registry)
{
    Conversion conversionEntry;
    conversionEntry.convert = hkpMultiRayConvexAgent_createConvexMultiRayAgent;
    conversionEntry.create = FUN_009c0170;
    conversionEntry.copy = FUN_009c01b0;
    conversionEntry.destroy = FUN_009c1960;
    conversionEntry.enabled = true;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, 1, 23);
    conversionEntry.convert = hkpMultiRayConvexAgent_createMultiRayConvexAgent;
    conversionEntry.create = (void (*)())hkpMultiRayConvexAgent_staticGetPenetrations;
    conversionEntry.copy = hkpMultiRayConvexAgent_staticGetClosestPoints;
    conversionEntry.destroy = FUN_00a3ab70;
    conversionEntry.enabled = false;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, 23, 1);
}

}
}   // namespace f3m_009c00e0

// @f3 0x009d40d0 (community match, verified in this file)
namespace f3m_009d40d0 {
namespace Task0790 {
void hkpBvAgent_createShapeBvAgent();
void FUN_009d4160();
void FUN_009d41a0();
void FUN_009d41e0();
void hkpBvAgent_createBvShapeAgent();
void FUN_009d3f20();
void FUN_009d3c40();
void FUN_009d3950();
struct Conversion {
 void (*convert)(); void (*create)(); void (*copy)(); void (*destroy)();
 bool enabled; bool supported;
};
struct Registry {void FUN_00985b30(Conversion*,int,int);};
// @fnv 0x009d40d0
// pdb: hkpBvAgent::registerAgent | hkpBvAgent.obj | fnv360_0822_retail, objrun, medium, conflict (skyrim: hkpMultiSphereAgent::registerAgent)
// pdb params: dispatcher
void FUN_009d40d0(Registry* registry)
{
    Conversion conversionEntry;
    conversionEntry.convert = hkpBvAgent_createShapeBvAgent;
    conversionEntry.create = FUN_009d4160;
    conversionEntry.copy = FUN_009d41a0;
    conversionEntry.destroy = FUN_009d41e0;
    conversionEntry.enabled = true;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, -1, 26);
    conversionEntry.convert = hkpBvAgent_createBvShapeAgent;
    conversionEntry.create = (void (*)())FUN_009d3f20;
    conversionEntry.copy = FUN_009d3c40;
    conversionEntry.destroy = FUN_009d3950;
    conversionEntry.enabled = false;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, 26, -1);
}

}
}   // namespace f3m_009d40d0

// @f3 0x009c0050 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009c0050 {
namespace n9c0050 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
extern Alloc* (__stdcall* const FUN_00d9b080)(int);
struct FUN_009bffd0 {
    int vtbl;
    unsigned short memSize;
    short refCount;
    char pad[0x18];
    FUN_009bffd0(int a, int b, int c, int d) throw();
    static void* operator new(unsigned int size)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x1f);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, ((unsigned short*)p)[2], 0x1f);
    }
};
}
// pdb: hkpMultiRayConvexAgent::createMultiRayConvexAgent | hkpMultiRayConvexAgent.obj | fnv360_0822_retail, objrun + bridge(caller_sim|caller_sim) + skyrim(objrun), high
n9c0050::FUN_009bffd0* __cdecl hkpMultiRayConvexAgent_createMultiRayConvexAgent(int a, int b, int c, int d)
{
    return new n9c0050::FUN_009bffd0(a, b, c, d);
}
}   // namespace f3m_009c0050

// @f3 0x009d1fd0 (community match, verified in this file)
namespace f3m_009d1fd0 {
namespace task0791 {
void hkpShapeCollectionAgent_createListBAgent();
void FUN_009be600();
void FUN_009be640();
void FUN_009be680();
void hkpShapeCollectionAgent_createListAAgent();
void FUN_009d1aa0();
void FUN_009d1620();
void FUN_009d1840();
struct Conversion { void (*convert)(); void (*create)(); void (*copy)(); void (*destroy)(); bool enabled,supported; };
struct Registry { void FUN_00985b30(Conversion*,int,int); };
// @fnv 0x00d2e760
// pdb: hkpShapeCollectionAgent::registerAgent | hkpShapeCollectionAgent.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: dispatcher
void FUN_009d1fd0(Registry* registry)
{
    Conversion conversionEntry;
    conversionEntry.convert = hkpShapeCollectionAgent_createListBAgent;
    conversionEntry.create = FUN_009be600;
    conversionEntry.copy = FUN_009be640;
    conversionEntry.destroy = FUN_009be680;
    conversionEntry.enabled = true;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, -1, 8);
    conversionEntry.convert = hkpShapeCollectionAgent_createListAAgent;
    conversionEntry.create = (void (*)())FUN_009d1aa0;
    conversionEntry.copy = FUN_009d1620;
    conversionEntry.destroy = FUN_009d1840;
    conversionEntry.enabled = false;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, 8, -1);
}

}
}   // namespace f3m_009d1fd0

// @f3 0x009c9010 (community match, verified in this file)
namespace f3m_009c9010 {
namespace task0793 {
void hkpSphereCapsuleAgent_createCapsuleSphereAgent(); void FUN_009c90e0(); void FUN_009c9600(); void FUN_009c1960();
void hkpSphereCapsuleAgent_createSphereCapsuleAgent(); void FUN_009c80e0(); void hkpSphereCapsuleAgent_staticGetClosestPoints(); void FUN_00a3ab70();
struct AgentFunctions {
 void (*create)(); void (*getPenetrations)(); void (*getClosestPoints)(); void (*linearCast)();
 bool flipped; bool predictive;
};
struct Registry { void FUN_00985b30(AgentFunctions*, int, int); };
// pdb: hkpSphereCapsuleAgent::registerAgent | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void FUN_009c9010(Registry* registry) {
 AgentFunctions entry;
 entry.create=hkpSphereCapsuleAgent_createCapsuleSphereAgent;
 entry.getPenetrations=FUN_009c90e0;
 entry.getClosestPoints=FUN_009c9600;
 entry.linearCast=FUN_009c1960;
 entry.flipped=true;
 entry.predictive=false;
 registry->FUN_00985b30(&entry,6,2);
 entry.create=hkpSphereCapsuleAgent_createSphereCapsuleAgent;
 entry.getPenetrations=FUN_009c80e0;
 entry.getClosestPoints=hkpSphereCapsuleAgent_staticGetClosestPoints;
 entry.linearCast=FUN_00a3ab70;
 entry.flipped=false;
 entry.predictive=false;
 registry->FUN_00985b30(&entry,2,6);
}
}
}   // namespace f3m_009c9010

// @f3 0x009c6bf0 (community match, verified in this file)
namespace f3m_009c6bf0 {
namespace task0794 {
void hkpSphereBoxAgent_staticGetPenetrations();
void hkpSphereBoxAgent_createBoxSphereAgent();
void FUN_009c6cc0();
void FUN_009c6d40();
void FUN_009c1960();
void hkpSphereBoxAgent_createSphereBoxAgent();

void hkpSphereBoxAgent_staticGetClosestPoints();
void FUN_00a3ab70();
struct Conversion
{
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry
{
    void FUN_00985b30(Conversion*, int, int);
};
// @fnv 0x00d2e760
// pdb: hkpSphereBoxAgent::registerAgent | hkpSphereBoxAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void FUN_009c6bf0(Registry* registry)
{
    Conversion conversionEntry;
    conversionEntry.convert = hkpSphereBoxAgent_createBoxSphereAgent;
    conversionEntry.create = FUN_009c6cc0;
    conversionEntry.copy = FUN_009c6d40;
    conversionEntry.destroy = FUN_009c1960;
    conversionEntry.enabled = true;
    conversionEntry.supported = false;
    registry->FUN_00985b30(&conversionEntry, 5, 2);
    conversionEntry.convert = hkpSphereBoxAgent_createSphereBoxAgent;
    conversionEntry.create = (void (*)())hkpSphereBoxAgent_staticGetPenetrations;
    conversionEntry.copy = hkpSphereBoxAgent_staticGetClosestPoints;
    conversionEntry.destroy = FUN_00a3ab70;
    conversionEntry.enabled = false;
    conversionEntry.supported = false;
    registry->FUN_00985b30(&conversionEntry, 2, 5);
}

}
}   // namespace f3m_009c6bf0

// @f3 0x009d2e40 (community match, verified in this file)
namespace f3m_009d2e40 {
namespace task0795 {
void hkpMultiSphereAgent_staticGetPenetrations();
void hkpMultiSphereAgent_createListBAgent();
void FUN_009d2ed0();
void FUN_009d2f10();
void FUN_009d2f50();
void hkpMultiSphereAgent_createListAAgent();

void hkpMultiSphereAgent_staticGetClosestPoints();
void hkpMultiSphereAgent_staticLinearCast();
struct Conversion
{
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry
{
    void FUN_00985b30(Conversion*, int, int);
};
// @fnv 0x00d2e760
// pdb: hkpMultiSphereAgent::registerAgent | hkpMultiSphereAgent.obj | fnv360_0822_retail, objrun, medium, conflict (skyrim: hkpTransformAgent::registerAgent)
// pdb params: dispatcher
void FUN_009d2e40(Registry* registry)
{
    Conversion conversionEntry;
    conversionEntry.convert = hkpMultiSphereAgent_createListBAgent;
    conversionEntry.create = FUN_009d2ed0;
    conversionEntry.copy = FUN_009d2f10;
    conversionEntry.destroy = FUN_009d2f50;
    conversionEntry.enabled = true;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, -1, 20);
    conversionEntry.convert = hkpMultiSphereAgent_createListAAgent;
    conversionEntry.create = (void (*)())hkpMultiSphereAgent_staticGetPenetrations;
    conversionEntry.copy = hkpMultiSphereAgent_staticGetClosestPoints;
    conversionEntry.destroy = hkpMultiSphereAgent_staticLinearCast;
    conversionEntry.enabled = false;
    conversionEntry.supported = true;
    registry->FUN_00985b30(&conversionEntry, 20, -1);
}

}
}   // namespace f3m_009d2e40

// @f3 0x009c18d0 (community match, verified in this file)
namespace f3m_009c18d0 {
namespace task0799 {
void hkpMultiSphereTriangleAgent_createTriangleMultiSphereAgent();
void FUN_009c1aa0();
void FUN_009c1f90();
void FUN_009c1960();
void FUN_009c0910();
void hkpMultiSphereTriangleAgent_staticGetPenetrations();
void hkpMultiSphereTriangleAgent_staticGetClosestPoints();
void FUN_00a3ab70();
struct Conversion { void (*convert)(); void (*create)(); void (*copy)(); void (*destroy)(); bool enabled,supported; };
struct Registry { void FUN_00985b30(Conversion*,int,int); };
// @fnv 0x00d2e760
// pdb: hkpMultiSphereTriangleAgent::registerAgent | hkpMultiSphereTriangleAgent.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dispatcher
void FUN_009c18d0(Registry* registry)
{
    Conversion conversionEntry;
    conversionEntry.convert = hkpMultiSphereTriangleAgent_createTriangleMultiSphereAgent;
    conversionEntry.create = FUN_009c1aa0;
    conversionEntry.copy = FUN_009c1f90;
    conversionEntry.destroy = FUN_009c1960;
    conversionEntry.enabled = true;
    conversionEntry.supported = false;
    registry->FUN_00985b30(&conversionEntry, 4, 20);
    conversionEntry.convert = FUN_009c0910;
    conversionEntry.create = (void (*)())hkpMultiSphereTriangleAgent_staticGetPenetrations;
    conversionEntry.copy = hkpMultiSphereTriangleAgent_staticGetClosestPoints;
    conversionEntry.destroy = FUN_00a3ab70;
    conversionEntry.enabled = false;
    conversionEntry.supported = false;
    registry->FUN_00985b30(&conversionEntry, 20, 4);
}

}
}   // namespace f3m_009c18d0

// @f3 0x009cdc20 (community match, verified in this file)
namespace f3m_009cdc20 {
namespace task0792 {
typedef void* (__cdecl *CreateFunc)(void*, void*, void*, void*);
typedef void (__cdecl *ContactFunc)(void*, void*, void*, void*);
typedef void (__cdecl *LinearCastFunc)(void*, void*, void*, void*, void*);
void* __cdecl FUN_009cdb30(void*, void*, void*, void*);
void __cdecl FUN_009cde30(void*, void*, void*, void*);
void __cdecl FUN_009cde70(void*, void*, void*, void*);
void __cdecl FUN_009cdeb0(void*, void*, void*, void*, void*);
void* __cdecl FUN_009cd4e0(void*, void*, void*, void*);
void __cdecl FUN_009cda40(void*, void*, void*, void*);
void __cdecl FUN_009cd950(void*, void*, void*, void*);
void __cdecl FUN_009cd860(void*, void*, void*, void*, void*);
struct AgentFuncs {
    CreateFunc create;
    ContactFunc getPenetrations;
    ContactFunc getClosestPoints;
    LinearCastFunc linearCast;
    bool flipped;
    bool predictive;
};
struct Dispatcher {
    void FUN_00985b30(AgentFuncs*, int typeA, int typeB);
};
}
// pdb: hkpTransformAgent::registerAgent | hkpTransformAgent.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: hkpBvAgent::registerAgent)
// pdb params: dispatcher
void __cdecl FUN_009cdc20(task0792::Dispatcher* dispatcher)
{
    task0792::AgentFuncs funcs;
    funcs.create = task0792::FUN_009cdb30;
    funcs.getPenetrations = task0792::FUN_009cde30;
    funcs.getClosestPoints = task0792::FUN_009cde70;
    funcs.linearCast = task0792::FUN_009cdeb0;
    funcs.flipped = true;
    funcs.predictive = true;
    dispatcher->FUN_00985b30(&funcs, -1, 28);
    funcs.create = task0792::FUN_009cd4e0;
    funcs.getPenetrations = task0792::FUN_009cda40;
    funcs.getClosestPoints = task0792::FUN_009cd950;
    funcs.linearCast = task0792::FUN_009cd860;
    funcs.flipped = false;
    funcs.predictive = true;
    dispatcher->FUN_00985b30(&funcs, 28, -1);
}
}   // namespace f3m_009cdc20

// @f3 0x009d4f80 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009d4f80 {
namespace f3m_009d4f80 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
struct Mem { void FUN_008f6d90(void* p, int n, int t); };
struct Obj {
    int unk00;
    unsigned short size;
    char unk06[0x5a];
    int* data;
    int count;
    unsigned int capFlags;
    void FUN_009a5e50();
    Obj* FUN_009d4f80(unsigned int flags);
};
// pdb: hkpStorageSampledHeightFieldShape::`scalar deleting destructor' | hkpStorageSampledHeightFieldShapeClass.obj | fnv360_0822_retail, vtable_prefix, high
Obj* Obj::FUN_009d4f80(unsigned int flags) {
    if ((capFlags & 0x80000000u) == 0) {
        int cap = capFlags & 0x3fffffff;
        Mem* m = (Mem*)TlsGetValue(DAT_010f3170);
        m->FUN_008f6d90(data, cap * 4, 0x17);
    }
    FUN_009a5e50();
    if (flags & 1) {
        Mem* m = (Mem*)TlsGetValue(DAT_010f3170);
        m->FUN_008f6d90(this, size, 0x27);
    }
    return this;
}
}
}   // namespace f3m_009d4f80

// @f3 0x009d9da0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
namespace f3m_009d9da0 {
struct ThreadMem { void FUN_008f6d90(void* p, int size, int cls); };
extern unsigned long DAT_010f3170;
struct Obj {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
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
    void* data;
    int size;
    unsigned int capacity;
    void FUN_0090dc40();
    void FUN_009d9da0();
};
void Obj::FUN_009d9da0() {
    if (size == 0) {
        if ((capacity & 0x80000000) == 0) {
            unsigned int cap = capacity & 0x3fffffff;
            ThreadMem* mem = (ThreadMem*)TlsGetValue(DAT_010f3170);
            mem->FUN_008f6d90(data, cap * 8, 0x17);
        }
        data = 0;
        size = 0;
        capacity = (capacity & 0xc0000000) | 0x80000000;
    }
    FUN_0090dc40();
}
}

// @f3 0x009d7140 (community match, verified in this file)
namespace f3m_009d7140 {
struct O_9d7140 { int a0, a4, a8, ac; O_9d7140* FUN_009d7140(); };
O_9d7140* O_9d7140::FUN_009d7140() { a0 = 0; a8 = 0; ac = 0; a4 = 0; return this; }
}   // namespace f3m_009d7140

// @f3 0x009d2db0 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009d2db0 {
namespace n9d2db0 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
};
extern Alloc* (__stdcall* const FUN_00d9b080)(int);
struct Obj {
    void* vtbl;
    unsigned short memSize;
    short refCount;
    Obj* FUN_009d2b40(int a, int b, int c, int d);  // constructor
};
}
// pdb: hkpMultiSphereAgent::createListAAgent | hkpMultiSphereAgent.obj | fnv360_0822_debug, objrun + bridge(caller_sim|caller_sim) + skyrim(objrun), high
n9d2db0::Obj* hkpMultiSphereAgent_createListAAgent(int a, int b, int c, int d) {
    n9d2db0::Alloc* al = n9d2db0::FUN_00d9b080(DAT_010f3170);
    n9d2db0::Obj* o = (n9d2db0::Obj*)al->FUN_008f6d30(0x38, 0x1f);
    o->memSize = 0x38;
    return o->FUN_009d2b40(a, b, c, d);
}
}   // namespace f3m_009d2db0

// @f3 0x009d6ca0 (community match, verified in this file)
namespace f3m_009d6ca0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
namespace Delete346{
extern unsigned long DAT_010f3170;struct Heap346{void FUN_008f6d90(void*,unsigned int,int);};
struct Owner346{void*vtable;unsigned short memory,refs;void FUN_009d6380();Owner346* FUN_009d6ca0(unsigned int);};
// pdb: hkpStorageMeshShape::`scalar deleting destructor' | hkpStorageMeshShape.obj | fnv360_0822_retail, vtable_prefix, high
Owner346* Owner346::FUN_009d6ca0(unsigned int flags){FUN_009d6380();if(flags&1){Heap346*heap=(Heap346*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(this,memory,39);}return this;}
}
}   // namespace f3m_009d6ca0

// @f3 0x009d5050 (community match, verified in this file)
namespace f3m_009d5050 {
class B_009d5050 { public: virtual void v0(); unsigned short w4; unsigned short w6; B_009d5050() { w6 = 1; } };
class FUN_009d5050 : public B_009d5050 { public: FUN_009d5050(int x); virtual void v0(); };
FUN_009d5050::FUN_009d5050(int x) {}
}   // namespace f3m_009d5050

// @f3 0x009d5070 (community match, verified in this file)
namespace f3m_009d5070 {
class B_009d5070 { public: virtual void v0(); unsigned short w4; unsigned short w6; B_009d5070() { w6 = 1; } };
class FUN_009d5070 : public B_009d5070 { public: FUN_009d5070(int x); virtual void v0(); };
// pdb: hkpStorageExtendedMeshShape::ShapeSubpartStorage::ShapeSubpartStorage | hkpStorageExtendedMeshShape.obj | tesv_win, objrun_sim, low
FUN_009d5070::FUN_009d5070(int x) {}
}   // namespace f3m_009d5070

// @f3 0x009c4060 (community match, verified in this file)
namespace f3m_009c4060 {
namespace task0888 {
typedef void (*Fn)();
struct Entry { Fn create,penetrations,closest,cast; bool flipped,predictive; };
struct Dispatcher { void FUN_00985b30(Entry&,int,int); };
void FUN_009c4030(void**);
void FUN_009c2a70(); void FUN_009c3cc0(); void FUN_009c3590(); void FUN_00a3ab70();
// pdb: hkpCapsuleTriangleAgent::initAgentFunc | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun + bridge(call_gap|objrun) + skyrim(call_seq), high
__declspec(noinline) void hkpCapsuleTriangleAgent_initAgentFunc(void* p) {
 Entry* s=(Entry*)p;
 s->create=FUN_009c2a70; s->penetrations=FUN_009c3cc0; s->closest=FUN_009c3590; s->cast=FUN_00a3ab70;
 s->flipped=0; s->predictive=0;
}
// pdb: hkpCapsuleTriangleAgent::registerAgent | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void FUN_009c4060(Dispatcher* obj) {
 Entry s;
 s.flipped=0; s.predictive=0;
 FUN_009c4030((void**)&s);
 obj->FUN_00985b30(s,4,6);
 s.flipped=0; s.predictive=0;
 hkpCapsuleTriangleAgent_initAgentFunc(&s);
 obj->FUN_00985b30(s,6,4);
}
}
}   // namespace f3m_009c4060

// @f3 0x009c7aa0 (community match, verified in this file)
namespace f3m_009c7aa0 {
namespace Task0891 {
typedef void (*Fn)();
struct Entry {Fn create,penetrations,closest,linear; bool flipped,predictive;};
struct Dispatcher {void FUN_00985c10(Entry&,int,int);};
void FUN_009c7a10(void**);
void FUN_009c6ee0();void FUN_009c7130();void FUN_009c7730();void FUN_00a3ab70();
__declspec(noinline) void FUN_009c79e0(void* p) {
 Entry* s=(Entry*)p;
 s->create=FUN_009c6ee0;s->penetrations=FUN_009c7130;s->closest=FUN_009c7730;s->linear=FUN_00a3ab70;
 s->flipped=0;s->predictive=0;
}
// pdb: hkpSphereTriangleAgent::registerAgent2 | hkpSphereTriangleAgent.obj | fnv360_1110_retail, objrun, low, conflict (bridge: hkpSphereSphereAgent::registerAgent2)
// pdb params: dispatcher
void FUN_009c7aa0(Dispatcher* obj) {
 Entry s;s.flipped=0;s.predictive=0;
 FUN_009c7a10((void**)&s);
 obj->FUN_00985c10(s,4,2);
 s.flipped=0;s.predictive=0;
 FUN_009c79e0(&s);
 obj->FUN_00985c10(s,2,4);
}
}
}   // namespace f3m_009c7aa0

// @f3 0x009c0910 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009c0910 {
namespace n9c0910 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
extern Alloc* (__stdcall* const FUN_00d9b080)(int);
void __cdecl FUN_0096fbc0(void* src, void* dst) throw();
struct RefObj {
    unsigned short memSize;
    short refCount;
    RefObj() : refCount(1) {}
    virtual ~RefObj();
    static void* operator new(unsigned int size)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x1f);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, ((unsigned short*)p)[2], 0x1f);
    }
};
struct Source { char* data; };
struct Obj : RefObj {
    int m8;
    char mc[0x10];
    struct Quad { int a, b, c, d; Quad() : a(-1), b(-1), c(-1), d(-1) {} } q;
    Obj(Source* src, int v) : m8(v) {
        FUN_0096fbc0(src->data + 0x20, mc);
    }
    virtual ~Obj();
};
}
n9c0910::Obj* __cdecl FUN_009c0910(void* unused, n9c0910::Source* src, void* unused2, int v) {
    return new n9c0910::Obj(src, v);
}
}   // namespace f3m_009c0910

// @f3 0x009d6200 (community match, verified in this file)
namespace f3m_009d6200 {
struct X_009d6200 { int FUN_009d5090(int k); };
// pdb: hkEnum<enum hkpMeshShape::MeshShapeMaterialIndexStridingType,signed char>::operator= | hkpStorageMeshShape.obj | fnv360_0822_debug, objopen_prop, low, conflict (skyrim: finishLoadedObjecthkpStorageExtendedMeshShape)
// pdb params: e
int __cdecl FUN_009d6200(X_009d6200* x) { int r = 1; if (x) r = x->FUN_009d5090(r); return r; }
}   // namespace f3m_009d6200

// @f3 0x009d6cd0 (community match, verified in this file)
namespace f3m_009d6cd0 {
struct X_009d6cd0 { int FUN_009d6320(int k); };
// pdb: finishLoadedObjecthkpStorageMeshShapeSubpartStorage | hkpCollidehkpMeshShapeReflections.obj | tesv_win, objrun_prop, low
int __cdecl FUN_009d6cd0(X_009d6cd0* x) { int r = 1; if (x) r = x->FUN_009d6320(r); return r; }
}   // namespace f3m_009d6cd0

// @f3 0x009d6d20 (community match, verified in this file)
namespace f3m_009d6d20 {
struct X_009d6d20 { int FUN_009d6930(int k); };
// pdb: finishLoadedObjecthkpStorageMeshShape | hkpCollidehkpMeshShapeReflections.obj | tesv_win, caller_sim, low
int __cdecl FUN_009d6d20(X_009d6d20* x) { int r = 1; if (x) r = x->FUN_009d6930(r); return r; }
}   // namespace f3m_009d6d20

// @f3 0x009d6160 (community match, verified in this file)
namespace f3m_009d6160 {
struct X_9d6160 { int FUN_009d5050(int k); };
// pdb: finishLoadedObjecthkpExtendedMeshShapeShapesSubpart | hkpCollidehkpExtendedMeshShapeReflections.obj | tesv_win, objrun_open, low
int __cdecl FUN_009d6160(X_9d6160* x) { int r = 1; if (x) r = x->FUN_009d5050(r); return r; }
}   // namespace f3m_009d6160

// @f3 0x009d4ae0 (community match, verified in this file)
namespace f3m_009d4ae0 {
struct O_9d4ae0 { char pad[0x10]; int stride; char pad2[0x4c]; float* data; float FUN_009d4ae0(int x, int y); };
float O_9d4ae0::FUN_009d4ae0(int x, int y) { return data[stride * y + x]; }
}   // namespace f3m_009d4ae0

// @f3 0x009c40c0 (community match, verified in this file)
namespace f3m_009c40c0 {
namespace Task0889 {
typedef void (*Fn)();
struct Entry {Fn create,penetrations,closest,linear; bool flipped,predictive;};
struct Dispatcher {void FUN_00985c10(Entry&,int,int);};
void FUN_009c4030(void**);
void FUN_009c2a70();void FUN_009c3cc0();void FUN_009c3590();void FUN_00a3ab70();
// pdb: hkpCapsuleTriangleAgent::initAgentFunc | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun + bridge(call_gap|objrun) + skyrim(call_seq), high
__declspec(noinline) void hkpCapsuleTriangleAgent_initAgentFunc(void* p) {
 Entry* s=(Entry*)p;
 s->create=FUN_009c2a70;s->penetrations=FUN_009c3cc0;s->closest=FUN_009c3590;s->linear=FUN_00a3ab70;
 s->flipped=0;s->predictive=0;
}
// pdb: hkpCapsuleTriangleAgent::registerAgent2 | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void FUN_009c40c0(Dispatcher* obj) {
 Entry s;s.flipped=0;s.predictive=0;
 FUN_009c4030((void**)&s);
 obj->FUN_00985c10(s,4,6);
 s.flipped=0;s.predictive=0;
 hkpCapsuleTriangleAgent_initAgentFunc(&s);
 obj->FUN_00985c10(s,6,4);
}
}
}   // namespace f3m_009c40c0

// @f3 0x009c7a40 (community match, verified in this file)
namespace f3m_009c7a40 {
namespace task0890 {
typedef void(__cdecl* Fn)();
struct AgentFuncs {Fn create,penetrations,closest,cast; bool flipped,predictive;};
struct Dispatcher {void FUN_00985b30(AgentFuncs&,int,int);};
void FUN_009c7a10(void**);
void FUN_009c6ee0();void FUN_009c7130();void FUN_009c7730();void FUN_00a3ab70();
__declspec(noinline) void FUN_009c79e0(void* p) {
 AgentFuncs* s=(AgentFuncs*)p;
 s->create=FUN_009c6ee0; s->penetrations=FUN_009c7130;
 s->closest=FUN_009c7730; s->cast=FUN_00a3ab70;
 s->flipped=0; s->predictive=0;
}
// pdb: hkpSphereTriangleAgent::registerAgent | hkpSphereTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void __cdecl FUN_009c7a40(Dispatcher* obj) {
 AgentFuncs s;
 s.flipped=0; s.predictive=0;
 FUN_009c7a10((void**)&s);
 obj->FUN_00985b30(s,4,2);
 s.flipped=0; s.predictive=0;
 FUN_009c79e0(&s);
 obj->FUN_00985b30(s,2,4);
}
}
}   // namespace f3m_009c7a40

// @f3 0x009dad50 (community match, verified in this file)
namespace f3m_009dad50 {
struct FUN_009dad50_Target {
    virtual void vf00(int value);
    unsigned short unk04;
    short unk06;
};

struct FUN_009dad50_Owner {
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    void FUN_009dad50();
};

extern void FUN_00e7a84c();
extern void FUN_00dcc494();

// pdb: hkpBreakableConstraintData::~hkpBreakableConstraintData | hkpBreakableConstraintData.obj | fnv360_0822_retail, objrun, medium
void FUN_009dad50_Owner::FUN_009dad50()
{
    FUN_009dad50_Target* target = (FUN_009dad50_Target*)unk18;

    *(void**)this = (void*)&FUN_00e7a84c;

    if (target->unk04 != 0) {
        target->unk06 = target->unk06 - 1;
        if ((unsigned short)target->unk06 == 0) {
            target->vf00(1);
        }
    }

    *(void**)this = (void*)&FUN_00dcc494;
}
}   // namespace f3m_009dad50

// @f3 0x009d6ef0 (community match, verified in this file)
namespace n9d6ef0 {
extern unsigned long DAT_010f3170;
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
extern Alloc* (__stdcall* const FUN_00d9b080)(unsigned long);
void __cdecl FUN_00901e90(void* arr, int cap, int elemSize) throw();
struct RefObj {
    unsigned short memSize;
    short refCount;
    virtual ~RefObj() throw() {}
    void removeReference() throw() {
        if (memSize != 0) {
            --refCount;
            if (refCount == 0) delete this;
        }
    }
};
struct Entity : RefObj {
    virtual void v4() throw(); virtual void v8() throw(); virtual void vc() throw();
    virtual void v10() throw();
};
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    void setSize(int n) throw() {
        int cap = capAndFlags & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
        size = n;
    }
    ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
}
struct FUN_009d6ef0 : n9d6ef0::RefObj {
    n9d6ef0::Array<n9d6ef0::Entity*> arr;
    virtual ~FUN_009d6ef0() throw();
};
// pdb: hkResource::getContents<hkRootLevelContainer> | hkpHavokSnapshot.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: hkLoader::~hkLoader)
FUN_009d6ef0::~FUN_009d6ef0() throw()
{
    for (int i = 0; i < arr.size; i++) {
        n9d6ef0::Entity* e = arr.data[i];
        if (e->refCount == 1)
            e->v10();
    }
    for (int i = 0; i < arr.size; i++)
        arr.data[i]->removeReference();
    arr.setSize(0);
}

// @f3 0x009dd230 (community match, verified in this file)
namespace f3m_009dd230 {
namespace task0968 {
struct Floats{float x,y,z,w;};
struct Link {
int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
Floats* values;};
struct Arg{
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
Link* link;};
struct Object{
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
short unka0;bool enabled;char unka3;int unka4,unka8,unkac;short unkb0;bool disabled;void FUN_009dd230(Arg*,bool);};
// pdb: hkpPrismaticConstraintData::setMotorActive | hkpPrismaticConstraintData.obj | tesv_win, objrun_sim, low
void Object::FUN_009dd230(Arg* a,bool b){enabled=b;disabled=!b;if(a){Link* p=a->link;if(p){Floats* f=p->values;if(f){f->x=0.0f;f->y=0.0f;f->z=0.0f;f->w=0.0f;}}}}
}
}   // namespace f3m_009dd230

// @f3 0x009d5000 (community match, verified in this file)
extern char DAT_00e7f91c;
namespace f3m_009d5000 {
struct O_9d5000 { void* vt; unsigned short w4; unsigned short w6; int a8; int ac; };
void __cdecl FUN_009d5000(O_9d5000* o) { if (o) { o->w6 = 1; o->ac = 0xe; o->vt = &DAT_00e7f91c; } }
}   // namespace f3m_009d5000

// @f3 0x009caf70 (community match, verified in this file)
namespace f3m_009caf70 {
namespace task1000 {
struct Funcs{void* p1;void* p2;void* p3;void* p4;unsigned char b1,b2;};
void __cdecl FUN_009caf40(Funcs*);
struct Registry{void FUN_00985b30(const Funcs&,int,int);};
// pdb: hkpBoxBoxAgent::registerAgent | hkpBoxBoxAgent.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dispatcher
void __cdecl FUN_009caf70(Registry* p){Funcs f;f.b1=0;f.b2=0;FUN_009caf40(&f);p->FUN_00985b30(f,5,5);}
}
}   // namespace f3m_009caf70

// @f3 0x009c9fd0 (community match, verified in this file)
namespace f3m_009c9fd0 {
namespace task0999 {
struct Funcs {void* p1; void* p2; void* p3; void* p4; unsigned char b1,b2;};
void __cdecl FUN_009c9f80(Funcs*);
struct Registry { void FUN_00985c10(const Funcs&,int,int); };
// pdb: hkpSphereSphereAgent::registerAgent2 | hkpSphereSphereAgent.obj | tesv_win, caller_sim, low
void __cdecl FUN_009c9fd0(Registry* r) {Funcs f; f.b1=0; f.b2=0; FUN_009c9f80(&f); r->FUN_00985c10(f,2,2);}
}
}   // namespace f3m_009c9fd0

// @f3 0x009d76f0 (community match, verified in this file)
namespace f3m_009d76f0 {
namespace task1048 {
extern void* DAT_00e7ff4c;void __cdecl FUN_00401010(void*);
struct Member{void FUN_00922cf0();};
struct Object{void* table;int unk04,unk08,unk0c;Member member;Object* FUN_009d76f0(unsigned char);};
// pdb: GSwitchFormatter::`vector deleting destructor' | GMsgFormat.obj | tesv_win, hash, low
Object* Object::FUN_009d76f0(unsigned char flags){member.FUN_00922cf0();table=&DAT_00e7ff4c;if(flags&1)FUN_00401010(this);return this;}
}
}   // namespace f3m_009d76f0

// @f3 0x009d70c0 (community match, verified in this file)
extern char DAT_01169784;
namespace f3m_009d70c0 {
struct O_9d70c0 { int FUN_009d7020(int a, void* tbl, int b, int c); int FUN_009d70c0(int a, int b, int c); };
int O_9d70c0::FUN_009d70c0(int a, int b, int c) { return FUN_009d7020(a, &DAT_01169784, b, c); }
}   // namespace f3m_009d70c0

// @f3 0x009df2a0 (community match, verified in this file)
namespace f3m_009df2a0 {
namespace f3m_009df2a0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct MemMgr {
    void Free(void* p, int n, int t);
};

struct Target {
    int unk00;
    unsigned short unk04;
    void FUN_009ddf00();
    void* FUN_009df2a0(unsigned int flags);
};

// pdb: hkpGenericConstraintData::`scalar deleting destructor' | hkpGenericConstraintData.obj | fnv360_0822_retail, vtable_prefix, high
void* Target::FUN_009df2a0(unsigned int flags)
{
    FUN_009ddf00();
    if (flags & 1) {
        MemMgr* mgr = (MemMgr*)TlsGetValue(DAT_010f3170);
        mgr->Free(this, unk04, 0x2c);
    }
    return this;
}

}
}   // namespace f3m_009df2a0

// @f3 0x009d6fd0 (community match, verified in this file)
extern char DAT_01169784;
namespace f3m_009d6fd0 {
struct O_9d6fd0 { int FUN_009d6dd0(int a, void* tbl, int b, int c); int FUN_009d6fd0(int a, int b, int c); };
int O_9d6fd0::FUN_009d6fd0(int a, int b, int c) { return FUN_009d6dd0(a, &DAT_01169784, b, c); }
}   // namespace f3m_009d6fd0

// @f3 0x009dc810 (community match, verified in this file)
namespace f3m_009dc810 {
struct FUN_009dc810_Class {
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;

    void FUN_009dc810(float* out);
};

void FUN_009dc810_Class::FUN_009dc810(float* out) {
    out[0] = *(float*)((char*)this + 0x20);
    out[1] = *(float*)((char*)this + 0x24);
    out[2] = *(float*)((char*)this + 0x28);
    out[3] = *(float*)((char*)this + 0x2C);
    out[4] = *(float*)((char*)this + 0x30);
    out[5] = *(float*)((char*)this + 0x34);
    out[6] = *(float*)((char*)this + 0x38);
    out[7] = *(float*)((char*)this + 0x3C);
    out[8] = *(float*)((char*)this + 0x40);
    out[9] = *(float*)((char*)this + 0x44);
    out[10] = *(float*)((char*)this + 0x48);
    out[11] = *(float*)((char*)this + 0x4C);
}
}   // namespace f3m_009dc810

// @f3 0x009c08e0 (community match, verified in this file)
namespace f3m_009c08e0 {
struct V4_9c08e0 { float x, y, z, w; V4_9c08e0& operator=(const V4_9c08e0& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct O_9c08e0 { char pad[0x10]; V4_9c08e0 v; void FUN_009c08e0(const V4_9c08e0* p, float f); };
void O_9c08e0::FUN_009c08e0(const V4_9c08e0* p, float f) { v = *p; v.w = f; }
}   // namespace f3m_009c08e0

// @f3 0x009d6c00 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long index);
namespace n9d6c00 {
extern unsigned long DAT_010f3170;
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
struct RefObj {
    unsigned short memSize;
    short refCount;
    virtual ~RefObj() throw() {}
    int m08, m0c;
};
struct Listener {
    virtual void v0() throw();
    ~Listener() throw() {}
    int pad[8];
};
struct Elem { int v[14]; };
template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = (Alloc*)::FUN_00d9b080(DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};
}
struct __declspec(novtable) FUN_009d6c00 : n9d6c00::RefObj, n9d6c00::Listener {

    n9d6c00::Array<n9d6c00::Elem> elems;
    n9d6c00::Array<short> shorts;
    virtual ~FUN_009d6c00() throw();
};
// pdb: hkpMeshShape::~hkpMeshShape | hkpStorageMeshShape.obj | fnv360_0822_retail, call_seq, high
FUN_009d6c00::~FUN_009d6c00() throw()
{
}

// @f3 0x009c4740 (community match, verified in this file)
#include <new>
namespace task9c4740 {
extern unsigned int DAT_010f3170;
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
struct Heap { void* FUN_008f6d30(int,int); };
struct Item { virtual void Slot(); short size,refs; int value; unsigned short a,b,c; Item(int v):value(v),a(0xffff),b(0xffff),c(0xffff){} };
// pdb: hkpCapsuleCapsuleAgent::createCapsuleCapsuleAgent | hkpCapsuleCapsuleAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
Item* __cdecl hkpCapsuleCapsuleAgent_createCapsuleCapsuleAgent(int a,int b,int c,int value) {
 Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);
 Item* p=(Item*)heap->FUN_008f6d30(0x14,0x1f);
 p->size=0x14; p->refs=1;
 return new(p) Item(value);
}
}

// @f3 0x009dd9b0 (community match, verified in this file)
namespace n9dd9b0 {
extern unsigned long DAT_010f3170;
struct Alloc { void* FUN_008f6d30(int size, int tag); void FUN_008f6d90(void* p, int size, int tag); };
extern Alloc* (__stdcall* const FUN_00d9b080)(unsigned long);
}
struct FUN_009de610 {
    void* vtbl;
    unsigned short memSize;
    short refCount;
    FUN_009de610();
    static void* operator new(unsigned int size) {
        n9dd9b0::Alloc* a = n9dd9b0::FUN_00d9b080(n9dd9b0::DAT_010f3170);
        FUN_009de610* p = (FUN_009de610*)a->FUN_008f6d30(size, 0x2c);
        p->memSize = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p, unsigned int size) {
        n9dd9b0::FUN_00d9b080(n9dd9b0::DAT_010f3170)->FUN_008f6d90(p, size, 0x2c);
    }
    char pad[0x58 - 8];
};
struct C9dd9b0 {
    void FUN_008fc3f0(FUN_009de610* obj, int b);
    void FUN_009dd9b0(FUN_009de610* obj, int b);
};
// pdb: hkGenericConstraintCinfo::CloneData | bhkGenericConstraint.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apData, arCloneData
void C9dd9b0::FUN_009dd9b0(FUN_009de610* obj, int b)
{
    if (!obj)
        obj = new FUN_009de610;
    FUN_008fc3f0(obj, b);
}

// @f3 0x009d60c0 (community match, verified in this file)
namespace f3m_009d60c0 {
namespace f3m_009d60c0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009d60c0 { char pad[4]; unsigned short w; void FUN_009d5ef0(); O009d60c0* FUN_009d60c0(unsigned int flags); };
// pdb: hkpStorageExtendedMeshShape::MeshSubpartStorage::`scalar deleting destructor' | hkpStorageExtendedMeshShape.obj | fnv360_0822_retail, vtable, high
O009d60c0* O009d60c0::FUN_009d60c0(unsigned int flags) { FUN_009d5ef0(); if (flags & 1) { f3m_009d60c0::T* t = (f3m_009d60c0::T*)f3m_009d60c0::DAT_00d9b080(f3m_009d60c0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x25); } return this; }
}   // namespace f3m_009d60c0

// @f3 0x009d60f0 (community match, verified in this file)
namespace f3m_009d60f0 {
namespace f3m_009d60f0 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009d60f0 { char pad[4]; unsigned short w; void FUN_009d6000(); O009d60f0* FUN_009d60f0(unsigned int flags); };
// pdb: hkpStorageExtendedMeshShape::ShapeSubpartStorage::`scalar deleting destructor' | hkpStorageExtendedMeshShape.obj | fnv360_0822_retail, vtable, high
O009d60f0* O009d60f0::FUN_009d60f0(unsigned int flags) { FUN_009d6000(); if (flags & 1) { f3m_009d60f0::T* t = (f3m_009d60f0::T*)f3m_009d60f0::DAT_00d9b080(f3m_009d60f0::DAT_010f3170); t->FUN_008f6d90(this, w, 0x25); } return this; }
}   // namespace f3m_009d60f0

// @f3 0x009d6130 (community match, verified in this file)
namespace f3m_009d6130 {
namespace f3m_009d6130 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009d6130 { char pad[4]; unsigned short w; void FUN_009d51f0(); O009d6130* FUN_009d6130(unsigned int flags); };
// pdb: hkpStorageExtendedMeshShape::`scalar deleting destructor' | hkpStorageExtendedMeshShape.obj | fnv360_0822_retail, vtable_prefix, high
O009d6130* O009d6130::FUN_009d6130(unsigned int flags) { FUN_009d51f0(); if (flags & 1) { f3m_009d6130::T* t = (f3m_009d6130::T*)f3m_009d6130::DAT_00d9b080(f3m_009d6130::DAT_010f3170); t->FUN_008f6d90(this, w, 0x27); } return this; }
}   // namespace f3m_009d6130

// @f3 0x009d7300 (community match, verified in this file)
namespace f3m_009d7300 {
namespace f3m_009d7300 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009d7300 { char pad[4]; unsigned short w; void FUN_009d8e80(); O009d7300* FUN_009d7300(unsigned int flags); };
// pdb: hkpPhysicsData::`scalar deleting destructor' | hkpPhysicsDataClass.obj | fnv360_0822_retail, vtable, high
O009d7300* O009d7300::FUN_009d7300(unsigned int flags) { FUN_009d8e80(); if (flags & 1) { f3m_009d7300::T* t = (f3m_009d7300::T*)f3m_009d7300::DAT_00d9b080(f3m_009d7300::DAT_010f3170); t->FUN_008f6d90(this, w, 0xd); } return this; }
}   // namespace f3m_009d7300

// @f3 0x009d9470 (community match, verified in this file)
namespace f3m_009d9470 {
namespace f3m_009d9470 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009d9470 { char pad[4]; unsigned short w; void FUN_00a4e240(); O009d9470* FUN_009d9470(unsigned int flags); };
// pdb: hkpPhysicsSystemWithContacts::`scalar deleting destructor' | hkpPhysicsData.obj | fnv360_0822_retail, vtable, high
O009d9470* O009d9470::FUN_009d9470(unsigned int flags) { FUN_00a4e240(); if (flags & 1) { f3m_009d9470::T* t = (f3m_009d9470::T*)f3m_009d9470::DAT_00d9b080(f3m_009d9470::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2f); } return this; }
}   // namespace f3m_009d9470

// @f3 0x009d9e20 (community match, verified in this file)
namespace f3m_009d9e20 {
namespace f3m_009d9e20 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009d9e20 { char pad[4]; unsigned short w; void FUN_009d98c0(); O009d9e20* FUN_009d9e20(unsigned int flags); };
// pdb: hkpCachingShapePhantom::`scalar deleting destructor' | hkpCachingShapePhantom.obj | fnv360_0822_retail, vtable_prefix, high
O009d9e20* O009d9e20::FUN_009d9e20(unsigned int flags) { FUN_009d98c0(); if (flags & 1) { f3m_009d9e20::T* t = (f3m_009d9e20::T*)f3m_009d9e20::DAT_00d9b080(f3m_009d9e20::DAT_010f3170); t->FUN_008f6d90(this, w, 0x31); } return this; }
}   // namespace f3m_009d9e20

// @f3 0x009dd800 (community match, verified in this file)
namespace f3m_009dd800 {
namespace f3m_009dd800 { extern unsigned long DAT_010f3170; extern void* (__stdcall* DAT_00d9b080)(unsigned long); struct T { void FUN_008f6d90(void* p, unsigned int a, unsigned int b); }; }
struct O009dd800 { char pad[4]; unsigned short w; void FUN_009dd1f0(); O009dd800* FUN_009dd800(unsigned int flags); };
// pdb: hkpPrismaticConstraintData::`scalar deleting destructor' | hkpPrismaticConstraintData.obj | fnv360_0822_retail, vtable_prefix, medium
O009dd800* O009dd800::FUN_009dd800(unsigned int flags) { FUN_009dd1f0(); if (flags & 1) { f3m_009dd800::T* t = (f3m_009dd800::T*)f3m_009dd800::DAT_00d9b080(f3m_009dd800::DAT_010f3170); t->FUN_008f6d90(this, w, 0x2c); } return this; }
}   // namespace f3m_009dd800

// @f3 0x009c97e0 (community match, verified in this file)
namespace f3m_009c97e0 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
struct Pool_009c97e0 { void* FUN_008f6d30(int size, int kind); };
class Base_009c97e0 {
public:
    virtual ~Base_009c97e0() {}
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    unsigned short unk0C;
    Base_009c97e0(int a) { unk06 = 1; unk08 = a; }
};
class Obj_009c97e0 : public Base_009c97e0 {
public:
    virtual ~Obj_009c97e0();
    Obj_009c97e0(int a) : Base_009c97e0(a) { unk0C = 0xffff; }
    static void* operator new(unsigned int size) {
        Pool_009c97e0* pool = (Pool_009c97e0*)DAT_00d9b080(DAT_010f3170);
        Base_009c97e0* p = (Base_009c97e0*)pool->FUN_008f6d30(0x10, 0x1f);
        p->unk04 = 0x10;
        return p;
    }
    static void operator delete(void* p);
};
// pdb: hkpSphereSphereAgent::createSphereSphereAgent | hkpSphereSphereAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
Obj_009c97e0* __cdecl hkpSphereSphereAgent_createSphereSphereAgent(int, int, int, int a) {
    return new Obj_009c97e0(a);
}
}   // namespace f3m_009c97e0

// @f3 0x009c80a0 (community match, verified in this file)
namespace f3m_009c80a0 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
struct Pool_009c80a0 { void* FUN_008f6d30(int size, int kind); };
class Base_009c80a0 {
public:
    virtual ~Base_009c80a0() {}
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    unsigned short unk0C;
    Base_009c80a0(int a) { unk06 = 1; unk08 = a; unk0C = 0xffff; }
};
class Obj_009c80a0 : public Base_009c80a0 {
public:
    virtual ~Obj_009c80a0();
    Obj_009c80a0(int a) : Base_009c80a0(a) { }
    static void* operator new(unsigned int size) {
        Pool_009c80a0* pool = (Pool_009c80a0*)DAT_00d9b080(DAT_010f3170);
        Base_009c80a0* p = (Base_009c80a0*)pool->FUN_008f6d30(0x10, 0x1f);
        p->unk04 = 0x10;
        return p;
    }
    static void operator delete(void* p);
};
// pdb: hkpSphereCapsuleAgent::createCapsuleSphereAgent | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
Obj_009c80a0* __cdecl hkpSphereCapsuleAgent_createCapsuleSphereAgent(int, int, int, int a) {
    return new Obj_009c80a0(a);
}
}   // namespace f3m_009c80a0

// @f3 0x009c8030 (community match, verified in this file)
namespace f3m_009c8030 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
struct Pool_009c8030 { void* FUN_008f6d30(int size, int kind); };
class Base_009c8030 {
public:
    virtual ~Base_009c8030() {}
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    unsigned short unk0C;
    Base_009c8030(int a) { unk06 = 1; unk08 = a; }
};
class Obj_009c8030 : public Base_009c8030 {
public:
    virtual ~Obj_009c8030();
    Obj_009c8030(int a) : Base_009c8030(a) { unk0C = 0xffff; }
    static void* operator new(unsigned int size) {
        Pool_009c8030* pool = (Pool_009c8030*)DAT_00d9b080(DAT_010f3170);
        Base_009c8030* p = (Base_009c8030*)pool->FUN_008f6d30(0x10, 0x1f);
        p->unk04 = 0x10;
        return p;
    }
    static void operator delete(void* p);
};
// pdb: hkpSphereCapsuleAgent::createSphereCapsuleAgent | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
Obj_009c8030* __cdecl hkpSphereCapsuleAgent_createSphereCapsuleAgent(int, int, int, int a) {
    return new Obj_009c8030(a);
}
}   // namespace f3m_009c8030

// @f3 0x009c5bf0 (community match, verified in this file)
namespace f3m_009c5bf0 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
struct Pool_009c5bf0 { void* FUN_008f6d30(int size, int kind); };
class Base_009c5bf0 {
public:
    virtual ~Base_009c5bf0() {}
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    unsigned short unk0C;
    Base_009c5bf0(int a) { unk06 = 1; unk08 = a; }
};
class Obj_009c5bf0 : public Base_009c5bf0 {
public:
    virtual ~Obj_009c5bf0();
    Obj_009c5bf0(int a) : Base_009c5bf0(a) { unk0C = 0xffff; }
    static void* operator new(unsigned int size) {
        Pool_009c5bf0* pool = (Pool_009c5bf0*)DAT_00d9b080(DAT_010f3170);
        Base_009c5bf0* p = (Base_009c5bf0*)pool->FUN_008f6d30(0x10, 0x1f);
        p->unk04 = 0x10;
        return p;
    }
    static void operator delete(void* p);
};
// pdb: hkpSphereBoxAgent::createSphereBoxAgent | hkpSphereBoxAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
Obj_009c5bf0* __cdecl hkpSphereBoxAgent_createSphereBoxAgent(int, int, int, int a) {
    return new Obj_009c5bf0(a);
}
}   // namespace f3m_009c5bf0

// @f3 0x009c5bb0 (community match, verified in this file)
namespace f3m_009c5bb0 {
extern void* (__stdcall* const DAT_00d9b080)(unsigned int);
struct Pool_009c5bb0 { void* FUN_008f6d30(int size, int kind); };
class Base_009c5bb0 {
public:
    virtual ~Base_009c5bb0() {}
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    unsigned short unk0C;
    Base_009c5bb0(int a) { unk06 = 1; unk08 = a; unk0C = 0xffff; }
};
class Obj_009c5bb0 : public Base_009c5bb0 {
public:
    virtual ~Obj_009c5bb0();
    Obj_009c5bb0(int a) : Base_009c5bb0(a) { }
    static void* operator new(unsigned int size) {
        Pool_009c5bb0* pool = (Pool_009c5bb0*)DAT_00d9b080(DAT_010f3170);
        Base_009c5bb0* p = (Base_009c5bb0*)pool->FUN_008f6d30(0x10, 0x1f);
        p->unk04 = 0x10;
        return p;
    }
    static void operator delete(void* p);
};
// pdb: hkpSphereBoxAgent::createBoxSphereAgent | hkpSphereBoxAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
Obj_009c5bb0* __cdecl hkpSphereBoxAgent_createBoxSphereAgent(int, int, int, int a) {
    return new Obj_009c5bb0(a);
}
}   // namespace f3m_009c5bb0

// @f3 0x009dd0e0 (community match, verified in this file)
namespace f3m_009dd0e0 {
namespace f3m_009dd0e0 {

struct RefObj {
    virtual void DeleteThis(int b);
    short unk04;
    short unk06;
    void IncRef() { if (unk04) unk06++; }
    void DecRef() { if (unk04 && --unk06 == 0) DeleteThis(1); }
};

struct Owner {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    RefObj* m_p;

    void FUN_009dd0e0(RefObj* p);
};

void Owner::FUN_009dd0e0(RefObj* p)
{
    if (p) p->IncRef();
    if (m_p) m_p->DecRef();
    m_p = p;
}

}
}   // namespace f3m_009dd0e0

// @f3 0x009dac50 (community match, verified in this file)
namespace f3m_009dac50 {
// FUN_009dac50: assign a ref-counted, polymorphic object to this->unk18
// (addref new if its "live" word is set, release old, then store).

struct RFObj {
    virtual void vf00(int a);
    short unk04;
    short unk06;
};

struct RFHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    RFObj* unk18;
    void FUN_009dac50(RFObj* p);
};

// pdb: hkpBreakableConstraintData::SetWrappedConstraintData | hkpBreakableConstraintData.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: apData
void RFHolder::FUN_009dac50(RFObj* p)
{
    if (p != 0 && p->unk04 != 0)
        p->unk06 = p->unk06 + 1;

    RFObj* old = unk18;
    if (old != 0 && old->unk04 != 0)
    {
        old->unk06 = old->unk06 - 1;
        if (old->unk06 == 0)
            old->vf00(1);
    }
    unk18 = p;
}
}   // namespace f3m_009dac50

// @f3 0x009da010 (community match, verified in this file)
namespace f3m_009da010 {


extern DWORD DAT_010f3170;

struct Ref {
    int unk00;
    int unk04;
};

struct SrcA {
    Ref* ref;
    int unk04;
};

struct SrcB {
    int unk00;
    int unk04;
};

struct Obj {
    int unk00;
    unsigned short type;
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
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    unsigned char unk5c;
    unsigned char unk5d;
    Obj* Init(int a, int b, int c);
};

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
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    unsigned char unk5c;
    unsigned char unk5d;
    Obj* hkpSpringAction_clone(SrcA* a, SrcB* b);
};

struct Pool {
    Obj* Alloc(unsigned int size, int tag);
};

// pdb: hkpSpringAction::clone | hkpSpringAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
Obj* Owner::hkpSpringAction_clone(SrcA* a, SrcB* b)
{
    if (a->unk04 != 2) {
        return 0;
    }
    if (b->unk04 != 0) {
        return 0;
    }
    Pool* pool = (Pool*)TlsGetValue(DAT_010f3170);
    Obj* obj = pool->Alloc(0x60, 0x29);
    obj->type = 0x60;
    obj = obj->Init(a->ref->unk00, a->ref->unk04, unk10);
    obj->unk30 = unk30;
    obj->unk34 = unk34;
    obj->unk38 = unk38;
    obj->unk3c = unk3c;
    obj->unk40 = unk40;
    obj->unk44 = unk44;
    obj->unk48 = unk48;
    obj->unk4c = unk4c;
    obj->unk50 = unk50;
    obj->unk54 = unk54;
    obj->unk58 = unk58;
    obj->unk5c = unk5c;
    obj->unk5d = unk5d;
    return obj;
}
}   // namespace f3m_009da010

// @f3 0x009cd250 (community match, verified in this file)
namespace f3m_009cd250 {


extern DWORD DAT_010f3170;

struct Node;

struct Obj {
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    virtual void Visit(Node* first, Node* second, int tag) {}
};

struct Node {
    Obj* unk00;
    int unk04;
    int unk08;
    Node* unk0c;
};

struct Rec {
    int unk00;
    unsigned short unk04;
    int unk08;
    int unk0c;
    int unk10;
    Obj* unk14;
    Obj* unk18;
    int unk1c;
    int unk20;
    Rec* FUN_009cd1e0(Node* a, Node* b, int c);
};

struct Heap {
    Rec* FUN_008f6d30(unsigned int size, int tag);
};

// pdb: hkpPhantomAgent::createPhantomAgent | hkpPhantomAgent.obj | fnv360_0822_debug, objrun + skyrim(objrun), high
Rec* hkpPhantomAgent_createPhantomAgent(Node* a1, Node* a2, int a3, int a4) {
    Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
    Rec* rec = heap->FUN_008f6d30(0x24, 0x1f);
    rec->unk04 = 0x24;
    Rec* r = rec->FUN_009cd1e0(a1, a2, a4);
    if (r->unk1c == 0x1d) {
        Obj* o = a1->unk00;
        Node* last2 = a2;
        while (last2->unk0c != 0) last2 = last2->unk0c;
        Node* last1 = a1;
        while (last1->unk0c != 0) last1 = last1->unk0c;
        o->Visit(last1, last2, a3);
        r->unk14 = o;
    }
    if (r->unk20 == 0x1d) {
        Obj* o = a2->unk00;
        Node* last1 = a1;
        while (last1->unk0c != 0) last1 = last1->unk0c;
        Node* last2 = a2;
        while (last2->unk0c != 0) last2 = last2->unk0c;
        o->Visit(last2, last1, a3);
        r->unk18 = o;
    }
    return r;
}
}   // namespace f3m_009cd250

// @f3 0x009d3da0 (community match, verified in this file)
#include <windows.h>
extern unsigned long DAT_0116913c;
namespace f3m_009d3da0 {
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
struct S_00d45970_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = *(volatile unsigned int*)&t;
    }
};

struct S_00d45970_TimerBeginListCommand : S_00d45970_TimerCommand
{
    const char* m_pFirst;
};

struct S_00d45970_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00d45970_MonitorStream& GetMonitorStream()
    {
        return *(S_00d45970_MonitorStream*)TlsGetValue(DAT_0116913c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

struct S_00d45970_Shape
{
    void* vtbl;
    int unk04;
    int unk08;
    int m_type;
};

struct S_00d45970_BvShape : S_00d45970_Shape
{
    const S_00d45970_Shape* m_pBvShapeReference;
    void* m_childVtbl;
    const S_00d45970_Shape* m_pContainedShape;
};

struct S_00d45970_CdBody
{
    const S_00d45970_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S_00d45970_CdBody* m_parent;
    S_00d45970_CdBody(const S_00d45970_CdBody* parent) : m_parent(parent)
    {
        m_pMotionState = parent->m_pMotionState;
    }
    void SetCollisionShapeAndKey(const S_00d45970_Shape* s, unsigned int key)
    {
        m_pCollisionShape = s;
        m_uiCollisionShapeKey = key;
    }
};

struct S_00d45970_CollectorBase
{
    virtual void AddCdBodyPair(const S_00d45970_CdBody&, const S_00d45970_CdBody&);
    virtual void reset();
};

struct S_00d45dd0_FlagCollector : S_00d45970_CollectorBase
{
    bool m_bHit;
    S_00d45dd0_FlagCollector()
    {
        m_bHit = false;
    }
    virtual void AddCdBodyPair(const S_00d45970_CdBody&, const S_00d45970_CdBody&);
    virtual void reset();
};

struct S_00d45970_Agent;
struct S_00d45970_Input;
struct S_00d45970_ContactMgr;

typedef S_00d45970_Agent*(__cdecl* S_00d45970_CreateFunc)(const S_00d45970_CdBody&, const S_00d45970_CdBody&,
                                                          const S_00d45970_Input&, S_00d45970_ContactMgr*);

struct S_00d45970_Funcs
{
    S_00d45970_CreateFunc m_pCreateFunc;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
};

struct S_00d45970_Dispatcher
{
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
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    S_00d45970_Funcs m_agent2Funcs[64];

    __forceinline int getAgentType(int typeA, int typeB, unsigned int predictive) const
    {
        const unsigned char* table = predictive ? &m_agent3TypeMap[0][0] : &m_agent2TypeMap[0][0];
        table += typeA * 32;
        return table[typeB];
    }
    __forceinline int getAgentType2(int typeA, int typeB, unsigned int predictive) const
    {
        return predictive ? m_agent3TypeMap[typeA][typeB] : m_agent2TypeMap[typeA][typeB];
    }
    S_00d45970_Agent* getNewCollisionAgent(const S_00d45970_CdBody& bodyA, const S_00d45970_CdBody& bodyB,
                                           const S_00d45970_Input& input, S_00d45970_ContactMgr* mgr) const;
};

struct S_00d45970_Input
{
    S_00d45970_Dispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_bCreatePredictiveAgents;
};

__forceinline S_00d45970_Agent* S_00d45970_Dispatcher::getNewCollisionAgent(const S_00d45970_CdBody& bodyA,
                                                                            const S_00d45970_CdBody& bodyB,
                                                                            const S_00d45970_Input& input,
                                                                            S_00d45970_ContactMgr* mgr) const
{
    int typeA = bodyA.m_pCollisionShape->m_type;
    int typeB = bodyB.m_pCollisionShape->m_type;
    int idx = getAgentType(typeA, typeB, input.m_bCreatePredictiveAgents);
    S_00d45970_CreateFunc f = m_agent2Funcs[idx].m_pCreateFunc;
    return f(bodyA, bodyB, input, mgr);
}

struct S_00d45970_Output;

struct S_00d45970_Agent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void getPenetrations(const S_00d45970_CdBody& bodyA, const S_00d45970_CdBody& bodyB,
                                 const S_00d45970_Input& input, S_00d45970_CollectorBase& collector);
};

struct S_00d45970_BvAgent;

struct S_00d45970_BvAgentBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void getPenetrations(const S_00d45970_CdBody& bodyA, const S_00d45970_CdBody& bodyB,
                                 const S_00d45970_Input& input, S_00d45970_CollectorBase& collector);
};

struct S_00d45970_BvAgent
{
    void* vtbl;
    int unk04;
    S_00d45970_ContactMgr* m_pContactManager;
    S_00d45970_BvAgentBase* m_pBoundingVolumeAgent;
    S_00d45970_Agent* m_pAgent;

    void hkpBvAgent_getPenetrations(const S_00d45970_CdBody& bodyA, const S_00d45970_CdBody& bodyB, const S_00d45970_Input& input,
                         S_00d45970_CollectorBase& result);
};

// @fnv 0x00d45970
// pdb: hkpBvAgent::getPenetrations | hkpBvAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void S_00d45970_BvAgent::hkpBvAgent_getPenetrations(const S_00d45970_CdBody& bodyA, const S_00d45970_CdBody& bodyB,
                                         const S_00d45970_Input& input, S_00d45970_CollectorBase& result)
{
    {
        S_00d45970_MonitorStream& mStream = S_00d45970_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            S_00d45970_TimerBeginListCommand* h = (S_00d45970_TimerBeginListCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "LthkpBvAgent";
            h->m_pFirst = "StcheckBvShape";
            _ReadWriteBarrier();
            h->setTime();
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }

    {
        const S_00d45970_BvShape* bvShape = (const S_00d45970_BvShape*)bodyA.m_pCollisionShape;

        S_00d45970_CdBody newBodyA(&bodyA);
        newBodyA.SetCollisionShapeAndKey(bvShape->m_pBvShapeReference, 0xffffffff);

        S_00d45dd0_FlagCollector checker;
        m_pBoundingVolumeAgent->getPenetrations(newBodyA, bodyB, input, checker);

        if (checker.m_bHit)
        {
            {
                S_00d45970_MonitorStream& mStream = S_00d45970_MonitorStream::GetMonitorStream();
                if (mStream.memoryAvailable())
                {
                    S_00d45970_TimerCommand* h = (S_00d45970_TimerCommand*)mStream.m_kRayEnd;
                    h->m_pCommandName = "Stchild";
                    _ReadWriteBarrier();
                    h->setTime();
                    mStream.m_kRayEnd = (char*)(h + 1);
                }
            }
            newBodyA.SetCollisionShapeAndKey(bvShape->m_pContainedShape, 0);
            if (!m_pAgent)
            {
                m_pAgent =
                    input.m_pCollisionDispatcher->getNewCollisionAgent(newBodyA, bodyB, input, m_pContactManager);
            }
            m_pAgent->getPenetrations(newBodyA, bodyB, input, result);
        }
    }

    {
        S_00d45970_MonitorStream& mStream = S_00d45970_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            S_00d45970_TimerCommand* h = (S_00d45970_TimerCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "lt";
            _ReadWriteBarrier();
            h->setTime();
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }
}
}   // namespace f3m_009d3da0

// @f3 0x009d6bd0 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009d6bd0 {

namespace n9d6bd0 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag); };
extern Heap* (__stdcall* const FUN_00d9b080)(unsigned long);
class RefObj {
public:
    unsigned short memSizeAndFlags;
    short refCount;
    virtual ~RefObj();
    static void* operator new(unsigned int n);
    static void operator delete(void* p) {
        RefObj* o = static_cast<RefObj*>(p);
        Heap* h = FUN_00d9b080(DAT_010f3170);
        h->FUN_008f6d90(p, o->memSizeAndFlags, 0x25);
    }
};
}
struct FUN_009d6bd0 : n9d6bd0::RefObj {
};
void* Make9d6bd0() { return new FUN_009d6bd0; }
}   // namespace f3m_009d6bd0

// @f3 0x009c5770 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009c5770 {
namespace n9c5770 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag); };
extern Heap* (__stdcall* const FUN_00d9b080)(int);
class RefObj {
public:
    virtual ~RefObj() {}
    unsigned short memSizeAndFlags;
    short refCount;
};
}
struct FUN_009c5770 : n9c5770::RefObj {
    static void* operator new(unsigned int n);
    // pdb: HavokStreambufFactory::`scalar deleting destructor' | HavokStream.obj | fnv360_0822_retail, vtable, high
    static void operator delete(void* p) {
        FUN_009c5770* o = static_cast<FUN_009c5770*>(p);
        n9c5770::Heap* h = n9c5770::FUN_00d9b080(DAT_010f3170);
        h->FUN_008f6d90(p, o->memSizeAndFlags, 0x1f);
    }
};
void* Make9c5770() { return new FUN_009c5770; }
}   // namespace f3m_009c5770

// @f3 0x009d7720 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009d7720 {
namespace n9d7720 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag); };
extern Heap* (__stdcall* const FUN_00d9b080)(int);
class Base {
public:
    unsigned short memSizeAndFlags;
    short refCount;
    virtual ~Base();
};
}
struct FUN_009d7720 : n9d7720::Base {
    static void* operator new(unsigned int n);
    // pdb: hkPackfileWriter::`scalar deleting destructor' | hkPackfileWriter.obj | fnv360_0822_retail, vtable, high
    static void operator delete(void* p) {
        FUN_009d7720* o = static_cast<FUN_009d7720*>(p);
        n9d7720::Heap* h = n9d7720::FUN_00d9b080(DAT_010f3170);
        h->FUN_008f6d90(p, o->memSizeAndFlags, 6);
    }
};
void* Make9d7720() { return new FUN_009d7720; }
}   // namespace f3m_009d7720

// @f3 0x009d8980 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009d8980 {
namespace n9d8980 {
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag); };
extern Heap* (__stdcall* const FUN_00d9b080)(int);
class Base {
public:
    unsigned short memSizeAndFlags;
    short refCount;
    virtual ~Base();
};
}
struct FUN_009d8980 : n9d8980::Base {
    static void* operator new(unsigned int n);
    // pdb: hkBinaryPackfileWriter::`scalar deleting destructor' | hkBinaryPackfileWriter.obj | fnv360_0822_retail, vtable, high
    static void operator delete(void* p) {
        FUN_009d8980* o = static_cast<FUN_009d8980*>(p);
        n9d8980::Heap* h = n9d8980::FUN_00d9b080(DAT_010f3170);
        h->FUN_008f6d90(p, o->memSizeAndFlags, 6);
    }
};
void* Make9d8980() { return new FUN_009d8980; }
}   // namespace f3m_009d8980

// @f3 0x009d87c0 (community match, verified in this file)
extern int DAT_00e800c0;
extern int DAT_00dcc494;
namespace f3m_009d87c0 {
struct Poly
{
    virtual void p00(); virtual void p04(); virtual void p08(); virtual void p0c();
    virtual void p10(); virtual void p14(); virtual void p18();
    virtual void v7(void* p, unsigned int n);
    virtual void* v8();
};

inline void Seek(Poly* writer,void* position,unsigned mode){writer->v7(position,mode);}
struct Writer { void* vtbl; unsigned short unk04; unsigned short unk06; void* unk08; void* unk0c; };

extern unsigned int __cdecl FUN_009d88b0(unsigned int p);

struct FUN_009d89b0
{
    void* unk00; void* unk04; void* unk08; void* unk0c; void* unk10;
    void* unk14; void* unk18; void* unk1c; void* unk20; void* unk24;
    void* unk28; void* unk2c; void* unk30; void* unk34; void* unk38;
    void* unk3c; void* unk40; void* unk44; void* unk48; void* unk4c;
    FUN_009d89b0(void* a);
    void FUN_009d8a20();
};

struct Ctx
{
    void FUN_009d7a40(FUN_009d89b0* o);
    void FUN_009d7fd0(FUN_009d89b0* o);
    void FUN_009d7bc0(FUN_009d89b0* o, void* p);
    int hkBinaryPackfileWriter_save(Poly* pPoly, void* a2);
};

struct Arg { void* unk00; unsigned int unk04; unsigned int unk08; void* unk0c; };

void __cdecl FUN_00923500(void*,int,int);void __cdecl FUN_009234e0(void*,void*,int);void __cdecl FUN_009233d0(void*,void*,int);void __cdecl FUN_00a4a570(void*,int);extern int DAT_0116c41c;
struct Vt {virtual void v0();virtual void v1();virtual void v2();virtual void v3(void*,void*,void*,void*);};
struct Arr {void* data;int size;unsigned cap;};struct Data {Arr a,b,c,d;int tail;void FUN_009b2fd0();};
struct Header {unsigned magic1,magic2;void* source;unsigned version;unsigned arg4;void* object;unsigned u18,u1c,u20,u24;unsigned guid[4];unsigned u38,u3c;};
static __declspec(noinline) void FUN_009d7ac0(Vt* o,void* raw,void* stream,void* object){Arg*a=(Arg*)raw;Header h;FUN_00923500(&h,-1,64);h.magic1=0x57e0e057;h.magic2=0x10c0c010;h.source=a->unk00;h.version=5;*(unsigned char*)&h.guid[0]=0;FUN_009234e0(&h.arg4,&a->unk04,4);h.object=object;FUN_00923500(&h.u38,-1,8);if(a->unk0c)FUN_009233d0(h.guid,a->unk0c,16);else FUN_00a4a570(h.guid,16);Data data;data.a.data=0;data.a.size=0;data.a.cap=0x80000000;data.b.data=0;data.b.size=0;data.b.cap=0x80000000;data.c.data=0;data.c.size=0;data.c.cap=0x80000000;data.d.data=0;data.d.size=0;data.d.cap=0x80000000;data.tail=0;o->v3(stream,&h,&DAT_0116c41c,&data);data.FUN_009b2fd0();}

// pdb: hkBinaryPackfileWriter::save | hkBinaryPackfileWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int Ctx::hkBinaryPackfileWriter_save(Poly* pPoly, void* a2)
{
    FUN_009d89b0 obj(a2);
    Writer writer;
    writer.unk06 = 1;
    writer.vtbl = &DAT_00e800c0;
    writer.unk08 = pPoly;
    writer.unk0c = ((Poly*)writer.unk08)->v8();
    obj.unk1c = &writer;
    FUN_009d7a40(&obj);
    FUN_009d7ac0((Vt*)&obj.unk20, a2, obj.unk1c, obj.unk08);
    void* pSaved = ((Poly*)&writer)->v8();
    unsigned int one=1;
    ((Poly*)&writer)->v7((void*)FUN_009d88b0((unsigned int)&obj.unk04),one);
    FUN_009d7fd0(&obj);
    void* pSaved2 = ((Poly*)&writer)->v8();
    FUN_009d7bc0(&obj, pSaved);
    ((Poly*)&writer)->v7(pSaved2, 0);
    writer.vtbl = &DAT_00dcc494;
    obj.FUN_009d8a20();
    return 0;
}
}   // namespace f3m_009d87c0

// @f3 0x009df510 (community match, verified in this file)
namespace f3m_009df510 {
extern void __cdecl FUN_00901f10(void* apArray, int aiElemSize);

struct FUN_009df510_Array {
    int* pData;
    int size;
    unsigned int capacityAndFlags;
};

struct FUN_009df510_Parent {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FUN_009df510_Array list;

    void AddCountsAndBits() {
        unk08 += 1;
        unk0c += 1;
        unk04 += 0x30;
    }

    void AddBitsAndCounts() {
        unk04 += 0x30;
        unk08 += 1;
        unk0c += 1;
    }
};

struct FUN_009df510_Owner {
    int unk00;
    FUN_009df510_Parent* m_parent;

    void FUN_009df510();
};

void FUN_009df510_Owner::FUN_009df510()
{
    FUN_009df510_Array* array = &m_parent->list;
    if (array->size == (int)(array->capacityAndFlags & 0x3fffffff)) {
        FUN_00901f10(array, 4);
    }
    array->pData[array->size] = 0xd;
    array->size += 1;

    m_parent->AddCountsAndBits();
    m_parent->AddBitsAndCounts();
    m_parent->AddBitsAndCounts();
}
}   // namespace f3m_009df510

// @f3 0x009d9880 (community match, verified in this file)
namespace f3m_009d9880 {
struct FUN_0090de70 {
virtual ~FUN_0090de70() throw();
int unk4;
int unk8;
int unkc;
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
int unke4;
int unke8;
int unkec;
int unkf0;
int unkf4;
int unkf8;
int unkfc;
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
FUN_0090de70(int,int) throw();
};
struct DetailArray1292 {void* data;int size;int capacity;DetailArray1292():data(0),size(0),capacity(0x80000000){} };
struct FUN_009d9880: FUN_0090de70 {
DetailArray1292 details;
virtual ~FUN_009d9880() throw();
FUN_009d9880(int,int,int) throw();
};
// pdb: hkpCachingShapePhantom::hkpCachingShapePhantom | hkpCachingShapePhantom.obj | fnv360_0822_retail, caller_sim, high
// pdb params: shape, transform, collisionFilterInfo
FUN_009d9880::FUN_009d9880(int a,int b,int c) throw():FUN_0090de70(a,b) {unk2c=c;}
}   // namespace f3m_009d9880

// @f3 0x009dd270 (community match, verified in this file)
namespace f3m_009dd270 {
namespace prismatic_constraint_constructor {
struct __declspec(align(16)) Vector4 { float x,y,z,w;__forceinline void SetZero(){x=y=z=w=0.0f;} __forceinline void ClearForward(){x=0.0f;y=0.0f;z=0.0f;w=0.0f;} };
struct __declspec(align(16)) Matrix3 {
 Vector4 columns[3];
 __forceinline void SetIdentity(){
  for(unsigned int i=0;i<3;++i)columns[i].ClearForward();
  columns[0].x=1.0f;columns[1].y=1.0f;columns[2].z=1.0f;
 }
};
struct __declspec(align(16)) Transform { Matrix3 rotation;Vector4 translation;__forceinline void SetIdentity(){rotation.SetIdentity();translation.SetZero();} };
struct __declspec(align(16)) LocalTransformsAtom { unsigned short type,unk02;unsigned int unk04,unk08,unk0C;Transform a,b; };
struct hkBool { char value;__forceinline hkBool& operator=(bool v){value=v?1:0;return *this;} };
struct MotorAtom { unsigned short type;hkBool enabled;unsigned char axis;unsigned short initializedOffset,previousTargetOffset;float force;void* motor; };
struct FrictionAtom { unsigned short type;hkBool enabled;unsigned char axis;float force; };
struct AngularAtom { unsigned short type;unsigned char firstAxis,axisCount; };
struct LinearAtom { unsigned short type;unsigned char axis,unk03; };
struct LimitAtom { unsigned short type;unsigned char axis,unk03;float minimum,maximum; };
struct Atoms { LocalTransformsAtom transforms;MotorAtom motor;FrictionAtom friction;AngularAtom angular;LinearAtom perpendicularA,perpendicularB;LimitAtom limit;Atoms() throw(); };
struct hkBaseObject { virtual ~hkBaseObject() throw(); };
struct hkReferencedObject : hkBaseObject { unsigned short memorySizeAndFlags,referenceCount;__forceinline hkReferencedObject() throw():referenceCount(1){} };
struct hkpConstraintData : hkReferencedObject { unsigned int userData;__forceinline hkpConstraintData() throw():userData(0){} };
struct hkpPrismaticConstraintData : hkpConstraintData { Atoms atoms;hkpPrismaticConstraintData() throw(); };
// pdb: hkpPrismaticConstraintData::hkpPrismaticConstraintData | hkpPrismaticConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
hkpPrismaticConstraintData::hkpPrismaticConstraintData() throw() {
 atoms.transforms.a.SetIdentity();atoms.transforms.b.SetIdentity();
 const float range=3.40282e38f;
 atoms.limit.axis=0;atoms.limit.minimum=-range;atoms.friction.axis=0;atoms.limit.maximum=range;
 atoms.friction.force=0.0f;atoms.motor.enabled=false;atoms.motor.motor=0;atoms.motor.force=0.0f;atoms.motor.axis=0;atoms.angular.firstAxis=0;
 atoms.motor.initializedOffset=0x40;atoms.motor.previousTargetOffset=0x44;atoms.angular.axisCount=3;atoms.perpendicularA.axis=1;atoms.perpendicularB.axis=2;
}
}

}   // namespace f3m_009dd270

// @f3 0x009d46a0 (community match, verified in this file)
namespace f3m_009d46a0 {
// pdb: hkGetShapeTypeName | hkpShapeType.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
const char* __cdecl hkGetShapeTypeName(int shapeType) {
 switch(shapeType) {
  case 0: return "HK_SHAPE_INVALID";
  case -1: return "HK_SHAPE_ALL";
  case 1: return "HK_SHAPE_CONVEX";
  case 8: return "HK_SHAPE_COLLECTION";
  case 9: return "HK_SHAPE_BV_TREE";
  case 2: return "HK_SHAPE_SPHERE";
  case 4: return "HK_SHAPE_TRIANGLE";
  case 5: return "HK_SHAPE_BOX";
  case 6: return "HK_SHAPE_CAPSULE";
  case 3: return "HK_SHAPE_CYLINDER";
  case 7: return "HK_SHAPE_CONVEX_VERTICES";
  case 19: return "HK_SHAPE_CONVEX_PIECE";
  case 20: return "HK_SHAPE_MULTI_SPHERE";
  case 10: return "HK_SHAPE_LIST";
  case 21: return "HK_SHAPE_CONVEX_LIST";
  case 22: return "HK_SHAPE_TRIANGLE_COLLECTION";
  case 23: return "HK_SHAPE_MULTI_RAY";
  case 24: return "HK_SHAPE_HEIGHT_FIELD";
  case 14: return "HK_SHAPE_SAMPLED_HEIGHT_FIELD";
  case 25: return "HK_SHAPE_SPHERE_REP";
  case 26: return "HK_SHAPE_BV";
  case 27: return "HK_SHAPE_PLANE";
  case 11: return "HK_SHAPE_MOPP";
  case 28: return "HK_SHAPE_TRANSFORM";
  case 12: return "HK_SHAPE_CONVEX_TRANSLATE";
  case 13: return "HK_SHAPE_CONVEX_TRANSFORM";
  case 15: return "HK_SHAPE_EXTENDED_MESH";
  case 17: return "HK_SHAPE_PACKED_CONVEX_VERTICES";
  case 18: return "HK_SHAPE_MOPP_EMBEDDED";
  case 29: return "HK_SHAPE_PHANTOM_CALLBACK";
  case 30: return "HK_SHAPE_USER0";
  case 31: return "HK_SHAPE_USER1";
  case 32: return "HK_SHAPE_USER2";
  default: return 0;
 }
}
}   // namespace f3m_009d46a0

// @f3 0x009c0090 (community match, verified in this file)
namespace f3m_009c0090 {
extern unsigned long DAT_010f3170;
struct Allocc0090 { void* FUN_008f6d30(unsigned int bytes, unsigned int tag) throw(); };
extern "C" __declspec(dllimport) Allocc0090* __stdcall TlsGetValue(unsigned long);
class Basec0090 {
public:
    virtual void v0();
    unsigned short w4; unsigned short w6; int a8, ac, a10, a14, a18, a1c;
    Basec0090(int a, int b, int c, int d) throw();
    static void* operator new(unsigned int n) {
        Allocc0090* a = TlsGetValue(DAT_010f3170);
        void* p = a->FUN_008f6d30(n, 0x1f);
        ((Basec0090*)p)->w4 = (unsigned short)n;
        return p;
    }
};
class Derivedc0090 : public Basec0090 {
public:
    Derivedc0090(int a, int b, int c, int d) throw() : Basec0090(b, a, c, d) {}
    virtual void v0();
};
// pdb: hkpMultiRayConvexAgent::createConvexMultiRayAgent | hkpMultiRayConvexAgent.obj | fnv360_0822_retail, objrun + bridge(caller_sim|uvref) + skyrim(objrun), high
Basec0090* __cdecl hkpMultiRayConvexAgent_createConvexMultiRayAgent(int a, int b, int c, int d) { return new Derivedc0090(a, b, c, d); }
}

// @f3 0x009d1f80 (community match, verified in this file)
namespace f3m_009d1f80 {
extern unsigned long DAT_010f3170;
struct Allocd1f80 { void* FUN_008f6d30(unsigned int bytes, unsigned int tag) throw(); };
extern "C" __declspec(dllimport) Allocd1f80* __stdcall TlsGetValue(unsigned long);
class Based1f80 {
public:
    virtual void v0();
    unsigned short w4; unsigned short w6; int a8, ac, a10, a14, a18, a1c, a20, a24, a28, a2c, a30, a34;
    Based1f80(int a, int b, int c, int d) throw();
    static void* operator new(unsigned int n) {
        Allocd1f80* a = TlsGetValue(DAT_010f3170);
        void* p = a->FUN_008f6d30(n, 0x1f);
        ((Based1f80*)p)->w4 = (unsigned short)n;
        return p;
    }
};
class Derivedd1f80 : public Based1f80 {
public:
    Derivedd1f80(int a, int b, int c, int d) throw() : Based1f80(b, a, c, d) {}
    virtual void v0();
};
// pdb: hkpShapeCollectionAgent::createListBAgent | hkpShapeCollectionAgent.obj | fnv360_0822_debug, objrun + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
Based1f80* __cdecl hkpShapeCollectionAgent_createListBAgent(int a, int b, int c, int d) { return new Derivedd1f80(a, b, c, d); }
}

// @f3 0x009d2df0 (community match, verified in this file)
namespace f3m_009d2df0 {
extern unsigned long DAT_010f3170;
struct Allocd2df0 { void* FUN_008f6d30(unsigned int bytes, unsigned int tag) throw(); };
extern "C" __declspec(dllimport) Allocd2df0* __stdcall TlsGetValue(unsigned long);
class Based2df0 {
public:
    virtual void v0();
    unsigned short w4; unsigned short w6; int a8, ac, a10, a14, a18, a1c, a20, a24, a28, a2c, a30, a34;
    Based2df0(int a, int b, int c, int d) throw();
    static void* operator new(unsigned int n) {
        Allocd2df0* a = TlsGetValue(DAT_010f3170);
        void* p = a->FUN_008f6d30(n, 0x1f);
        ((Based2df0*)p)->w4 = (unsigned short)n;
        return p;
    }
};
class Derivedd2df0 : public Based2df0 {
public:
    Derivedd2df0(int a, int b, int c, int d) throw() : Based2df0(b, a, c, d) {}
    virtual void v0();
};
// pdb: hkpMultiSphereAgent::createListBAgent | hkpMultiSphereAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
Based2df0* __cdecl hkpMultiSphereAgent_createListBAgent(int a, int b, int c, int d) { return new Derivedd2df0(a, b, c, d); }
}

// @f3 0x009dc0f0 (community match, verified in this file)
namespace f3m_009dc0f0 {
namespace wheel_constraint_constructor {
struct __declspec(align(16)) Vector4 { float x,y,z,w;__forceinline void SetZero(){x=y=z=w=0.0f;} __forceinline void ClearForward(){x=0.0f;y=0.0f;z=0.0f;w=0.0f;} };
struct __declspec(align(16)) Matrix3 {
 Vector4 columns[3];
 __forceinline void SetIdentity(){
  for(unsigned int i=0;i<3;++i)columns[i].ClearForward();
  columns[0].x=1.0f;columns[1].y=1.0f;columns[2].z=1.0f;
 }
};
struct __declspec(align(16)) Transform { Matrix3 rotation;Vector4 translation;__forceinline void SetIdentity(){rotation.SetIdentity();translation.SetZero();} };
struct __declspec(align(16)) LocalTransformsAtom { unsigned short type,unk02;unsigned int unk04,unk08,unk0C;Transform a,b; };

struct LimitAtom {unsigned short type;unsigned char axis,unk03;float minimum,maximum;};
struct SoftAtom {unsigned short type;unsigned char axis,unk03;float tau,damping;};
struct LinearAtom {unsigned short type;unsigned char axis,unk03;};
struct __declspec(align(16)) LocalRotationsAtom {unsigned short type,unk02;unsigned int unk04,unk08,unk0c;Matrix3 a,b;};
struct Angular2DAtom {unsigned short type;unsigned char freeAxis,unk03;};
struct Atoms {LocalTransformsAtom transforms;LimitAtom limit;SoftAtom suspension;LinearAtom perpendicularA,perpendicularB;LocalRotationsAtom steering;Angular2DAtom angular;Atoms() throw();};
struct hkBaseObject {virtual ~hkBaseObject() throw();};
struct hkReferencedObject : hkBaseObject {unsigned short memorySizeAndFlags,referenceCount;__forceinline hkReferencedObject() throw():referenceCount(1){} };
struct hkpConstraintData : hkReferencedObject {unsigned int userData;__forceinline hkpConstraintData() throw():userData(0){} };
struct hkpWheelConstraintData : hkpConstraintData {Atoms atoms;hkpWheelConstraintData() throw();};
hkpWheelConstraintData::hkpWheelConstraintData() throw() {
 atoms.limit.minimum=-0.5f;atoms.limit.axis=0;atoms.limit.maximum=0.5f;atoms.suspension.axis=0;
 atoms.perpendicularA.axis=1;atoms.perpendicularB.axis=2;atoms.suspension.damping=atoms.suspension.tau=0.0f;
 atoms.steering.a.SetIdentity();atoms.steering.b.SetIdentity();
 atoms.transforms.a.SetIdentity();atoms.transforms.b.SetIdentity();atoms.angular.freeAxis=0;
}
}
}   // namespace f3m_009dc0f0

// @f3 0x009c6f70 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009c6f70 {
namespace f3m_009c6f70 {
struct Mem_6f70 {
    void* FUN_008f6d30(int bytes, int tag) throw();
};
__declspec(dllimport) Mem_6f70* __stdcall FUN_00d9b080(int) throw();

struct Src_6f70 {
    char* data;
};
void __cdecl FUN_0096fbc0(void* src, void* dst) throw();

class Ref_6f70 {
public:
    virtual ~Ref_6f70() throw();
    unsigned short memSizeAndFlags;
    short referenceCount;
    Ref_6f70() throw() : referenceCount(1) {}
    static void* operator new(unsigned int size)
    {
        Mem_6f70* mem = FUN_00d9b080(DAT_010f3170);
        Ref_6f70* p = (Ref_6f70*)mem->FUN_008f6d30(size, 0x1f);
        p->memSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p) throw();
};
class Mid_6f70 : public Ref_6f70 {
public:
    int unk08;
    short unk0C;
    int unk10[4];
    Mid_6f70(Src_6f70* src, int x) throw() : unk08(x), unk0C(-1)
    {
        FUN_0096fbc0(src->data + 0x20, unk10);
    }
    virtual ~Mid_6f70() throw();
};
class Obj_6f70 : public Mid_6f70 {
public:
    Obj_6f70(Src_6f70* src, int x) throw() : Mid_6f70(src, x) {}
    virtual ~Obj_6f70() throw();
};
}
using namespace f3m_009c6f70;

// pdb: hkpSphereTriangleAgent::createTriangleSphereAgent | hkpSphereTriangleAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
Obj_6f70* __cdecl hkpSphereTriangleAgent_createTriangleSphereAgent(Src_6f70* src, int a2, int a3, int x)
{
    return new Obj_6f70(src, x);
}
}   // namespace f3m_009c6f70

// @f3 0x009d8e80 (community match, verified in this file)
namespace f3m_009d8e80 {
namespace release9d {
extern int DAT_00e7ff3c,DAT_00dcc494;extern unsigned long DAT_010f3170;extern void* (__stdcall *DAT_00d9b080)(unsigned long);
struct Memory {void FUN_008f6d90(void*,int,int);};
struct Ref {virtual void Destroy(unsigned int);unsigned short size;short refs;void Release(){if(size){--refs;if(!refs)Destroy(1);}}};
struct Owner {int* table;int unk04;Ref* ref;Ref** data;int count;int capacity;void FUN_009d8e80();};
// pdb: hkpPhysicsData::~hkpPhysicsData | hkpPhysicsData.obj | fnv360_0822_retail, call_seq, high
void Owner::FUN_009d8e80(){table=&DAT_00e7ff3c;if(ref)ref->Release();for(int i=0;i<count;++i)data[i]->Release();if(!(capacity&0x80000000)){int n=capacity&0x3fffffff;Memory* memory=(Memory*)DAT_00d9b080(DAT_010f3170);memory->FUN_008f6d90(data,n*4,0x17);}table=&DAT_00dcc494;}
}
}   // namespace f3m_009d8e80

// @f3 0x009dda40 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009dda40 {
namespace f3m_009dda40 {
struct Mem_da40 {
    void* FUN_008f6d30(int bytes, int tag);
    void FUN_008f6d90(void* p, int bytes, int tag);
};
__declspec(dllimport) Mem_da40* __stdcall FUN_00d9b080(int);

class FUN_009de610 {
public:
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    char pad08[0x58 - 8];

    FUN_009de610();
    static void* operator new(unsigned int size)
    {
        Mem_da40* mem = FUN_00d9b080(DAT_010f3170);
        FUN_009de610* p = (FUN_009de610*)mem->FUN_008f6d30(size, 0x2c);
        p->memSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p, unsigned int size)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, size, 0x2c);
    }
};
struct Owner_da40 {
    int unk00;
    FUN_009de610* obj;
    int FUN_009dda40();
};
}
using namespace f3m_009dda40;

// pdb: hkFixedConstraintCinfo::CreateData | bhkFixedConstraint.obj | fnv360_0822_retail, caller_sim, low
int Owner_da40::FUN_009dda40()
{
    if (!obj)
        obj = new FUN_009de610();
    return sizeof(FUN_009de610);
}
}   // namespace f3m_009dda40

// @f3 0x009df580 (community match, verified in this file)
namespace f3m_009df580 {
struct MarkerArray {unsigned* data;int size;unsigned capacity;};
void __cdecl FUN_00901f10(MarkerArray*,unsigned);
struct MarkerOwner {int unk00,unk04,unk08,unk0C,unk10,unk14,unk18;MarkerArray markers;};
struct MarkerContext {int unk00;MarkerOwner* owner;int depth;void FUN_009df580();};
void MarkerContext::FUN_009df580(){--depth;MarkerArray* array=&owner->markers;if(array->size==(array->capacity&0x3fffffff))FUN_00901f10(array,4);array->data[array->size]=0x17;++array->size;}
}   // namespace f3m_009df580

// @f3 0x009ddac0 (community match, verified in this file)
#include <cstddef>
namespace f3m_009ddac0 {
// pdb: bhkFixedConstraint::CreateCinfo | bhkFixedConstraint.obj | fnv360_1110_retail, objrun_open, low
// pdb params: arCreated
namespace Task9dda{struct Heap{void*FUN_0086b930(unsigned);};extern Heap DAT_01090a78;extern int DAT_00e7ae04;struct Serializable{int value;int refs;};struct Object{void*methods;Serializable base;int unk0c;int unk10;Object(){base.value=0;unk0c=0;unk10=0;base.refs=1;methods=&DAT_00e7ae04;}static void*operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}static Serializable* Create(){Object*p=new Object;return p?&p->base:0;}static Object*From(Serializable*p){return p?(Object*)((char*)p - offsetof(Object,base)):0;}};struct Owner{int unk00;int unk04;int active;Serializable*cached;void FUN_008fc420(Object*);Serializable*FUN_009ddac0(bool*);};Serializable* Owner::FUN_009ddac0(bool*created){if(!cached){cached=Object::Create();if(active)FUN_008fc420(Object::From(cached));*created=true;}else *created=false;return cached;}}
}   // namespace f3m_009ddac0

// @f3 0x009dd8f0 (community match, verified in this file)
extern CRITICAL_SECTION DAT_010f3194;
extern int DAT_010f31f8, DAT_011697b4;
namespace f3m_009dd8f0 {
struct _RTL_CRITICAL_SECTION;
typedef _RTL_CRITICAL_SECTION CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
namespace task1373 {
void* __cdecl FUN_0089eb90(unsigned int);
struct FUN_008f7c10 {
    virtual void slot0();
    unsigned int refCount, unk08;
    FUN_008f7c10();
};
struct bhkConstraint : FUN_008f7c10 {
    unsigned int data;
    virtual void slot1();
    bhkConstraint() { data=0; DAT_010f31f8+=1; }
};
struct bhkGenericConstraint : bhkConstraint {
    virtual void slot2();
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    bhkGenericConstraint() { DAT_011697b4+=1; }
};
struct Factory {
    void FUN_008fbc00(void*, int);
    void* FUN_009dd8f0(int);
};
void* Factory::FUN_009dd8f0(int arg) {
    EnterCriticalSection(&DAT_010f3194);
    bhkGenericConstraint* obj = new bhkGenericConstraint();
    FUN_008fbc00(obj, arg);
    LeaveCriticalSection(&DAT_010f3194);
    return obj;
}
}
}   // namespace f3m_009dd8f0

// @f3 0x009da5d0 (community match, verified in this file)
extern int DAT_010f3170;

namespace f3m_009d5cb0 {
extern unkAlloc* (__stdcall *FUN_00d9b080)(int);
}

namespace f3m_009da5d0 {

struct SourceData {
    int value0;
    int value1;
};

struct Source {
    SourceData* data;
    int count;
};

struct Check {
    int value0;
    int flag;
};

struct Node {
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
    float unk40;
    float unk44;
    int unk48;
    int unk4C;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;

    Node* __thiscall FUN_009da570(int value0, int value1, int value2);
};

struct Holder {
    Node* __thiscall FUN_008f6d30(int value0, int value1);
};

struct Object {
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
    float unk40;
    float unk44;
    int unk48;
    int unk4C;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;

    Node* __thiscall hkpDashpotAction_clone(Source* source, Check* check);
};

// pdb: hkpDashpotAction::clone | hkpDashpotAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
Node* __thiscall Object::hkpDashpotAction_clone(Source* source, Check* check)
{
    if (source->count != 2)
        return 0;

    if (check->flag != 0)
        return 0;

    Holder* holder = (Holder*)f3m_009d5cb0::FUN_00d9b080(DAT_010f3170);
    Node* node = holder->FUN_008f6d30(0x60, 0x29);
    *(unsigned short*)((char*)node + 4) = 0x60;

    node = node->FUN_009da570(
        source->data->value0,
        source->data->value1,
        unk10);

    node->unk20 = unk20;
    node->unk24 = unk24;
    node->unk28 = unk28;
    node->unk2C = unk2C;
    node->unk30 = unk30;
    node->unk34 = unk34;
    node->unk38 = unk38;
    node->unk3C = unk3C;
    node->unk40 = unk40;
    node->unk44 = unk44;
    node->unk50 = unk50;
    node->unk54 = unk54;
    node->unk58 = unk58;
    node->unk5C = unk5C;

    return node;
}

}

// @f3 0x009d35d0 (community match, verified in this file)
namespace f3m_009d35d0 {
namespace t9d35d0 {
struct Node { int unk00; short unk04; void FUN_009d3530(int,int,int,int); };
// pdb: hkpBvAgent::createBvShapeAgent | hkpBvAgent.obj | fnv360_0822_debug, objrun + bridge(caller_sim|caller_sim) + skyrim(objrun), high
void __cdecl hkpBvAgent_createBvShapeAgent(int a1,int a2,int a3,int a4) {
    f3m_009cb0c0::Holder* h=(f3m_009cb0c0::Holder*)f3m_009cb0c0::TlsGetValue(DAT_010f3170);
    Node* node=(Node*)h->FUN_008f6d30(0x14,0x1f);
    node->unk04=0x14;
    node->FUN_009d3530(a1,a2,a3,a4);
}
}
}   // namespace f3m_009d35d0

// @f3 0x009dad20 (community match, verified in this file)
namespace f3m_009dad20 {
struct FinishLoaded {int finishing;};
struct hkBaseObject {virtual ~hkBaseObject(){}};
struct hkReferencedObject:hkBaseObject {unsigned short memoryFlags;short refCount;hkReferencedObject(FinishLoaded){refCount=1;}};
struct FUN_00d50c90:hkReferencedObject {FUN_00d50c90(FinishLoaded flag):hkReferencedObject(flag){}virtual ~FUN_00d50c90(){}};
struct BridgeAtom {unsigned short type,unk02;void* function;FUN_00d50c90* owner;BridgeAtom(FinishLoaded){FUN_00d21ce0(owner);}void FUN_00d21ce0(FUN_00d50c90*) throw();};
struct hkpBreakableConstraintData:FUN_00d50c90 {FUN_00d50c90* child; BridgeAtom bridge;hkpBreakableConstraintData(FinishLoaded flag);virtual ~hkpBreakableConstraintData();};
// pdb: hkpBreakableConstraintData::hkpBreakableConstraintData | hkpBreakableConstraintData.obj | fnv360_0822_retail, caller_sim, high
// pdb params: f
hkpBreakableConstraintData::hkpBreakableConstraintData(FinishLoaded flag):FUN_00d50c90(flag),bridge(flag){bridge.FUN_00d21ce0(this);}
}   // namespace f3m_009dad20

// @f3 0x009cd430 (community match, verified in this file)
namespace f3m_009cd430 {
namespace transform_agent_serializer {
struct Serializer {virtual void v00();virtual void Begin(const char*,int,void*);virtual void v08();virtual void Child(const char*,int,void*);virtual void v10();virtual void v14();virtual void Finish();};
struct Owner {unsigned int unk00,unk04,unk08;void* child;void hkpTransformAgent_calcContentStatistics(Serializer*);};
// pdb: hkpTransformAgent::calcContentStatistics | hkpTransformAgent.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void Owner::hkpTransformAgent_calcContentStatistics(Serializer* serializer){serializer->Begin("TransformAgent",8,this);serializer->Child("ChildAgent",8,child);serializer->Finish();}
}
}   // namespace f3m_009cd430

// @f3 0x009c0880 (community match, verified in this file)
extern int DAT_00dcc494;
namespace f3m_009c0880 {

namespace f3m_009c0880 {

extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long dwTlsIndex);


struct MemMgr {
    void Free(void* p, int n, int t);
};

struct Agent {
    int m_vtbl;              /* +0x00 */
    unsigned short m_size;   /* +0x04 */
    int unk08;               /* +0x08 */
    short* m_pData;          /* +0x0c */
    int m_numElems;          /* +0x10 */
    int m_capacityAndFlags;  /* +0x14 */

    void* FUN_009c0880(unsigned int flags);
};

// pdb: hkpMultiRayConvexAgent::`scalar deleting destructor' | hkpMultiRayConvexAgent.obj | fnv360_0822_retail, vtable, high
void* Agent::FUN_009c0880(unsigned int flags)
{
    if ((m_capacityAndFlags & 0x80000000) == 0) {
        int cap = m_capacityAndFlags & 0x3fffffff;
        MemMgr* mem = (MemMgr*)FUN_00d9b080(DAT_010f3170);
        mem->Free(m_pData, cap * 2, 0x17);
    }

    m_vtbl = (int)&DAT_00dcc494;

    if (flags & 1) {
        MemMgr* mem = (MemMgr*)FUN_00d9b080(DAT_010f3170);
        mem->Free(this, m_size, 0x1f);
    }
    return this;
}

}
}   // namespace f3m_009c0880

// @f3 0x009deff0 (community match, verified in this file)
namespace f3m_009deff0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_009deff0 {

using f3m_009d5cb0::unkAlloc;

struct Arr {
    void* m_pData;
    int m_iCount;
    unsigned int m_uCapAndFlags;
};

struct Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Arr unk10;
    Arr unk1c;
    Arr unk28;
    Arr unk34;
    void FUN_009deff0();
};

// pdb: hkpGenericConstraintDataScheme::~hkpGenericConstraintDataScheme | hkpGenericConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void Obj::FUN_009deff0()
{
    void* (__stdcall *get)(unsigned long) = TlsGetValue;
    int n;
    if ((unk34.m_uCapAndFlags & 0x80000000u) == 0) {
        n = unk34.m_uCapAndFlags & 0x3fffffff;
        unkAlloc* a = (unkAlloc*)get(DAT_010f3170);
        a->Free(unk34.m_pData, n * 4, 0x17);
    }
    if ((unk28.m_uCapAndFlags & 0x80000000u) == 0) {
        n = unk28.m_uCapAndFlags & 0x3fffffff;
        unkAlloc* a = (unkAlloc*)get(DAT_010f3170);
        a->Free(unk28.m_pData, n * 4, 0x17);
    }
    if ((unk1c.m_uCapAndFlags & 0x80000000u) == 0) {
        n = unk1c.m_uCapAndFlags & 0x3fffffff;
        unkAlloc* a = (unkAlloc*)get(DAT_010f3170);
        a->Free(unk1c.m_pData, n * 4, 0x17);
    }
    if ((unk10.m_uCapAndFlags & 0x80000000u) == 0) {
        n = unk10.m_uCapAndFlags & 0x3fffffff;
        unkAlloc* a = (unkAlloc*)get(DAT_010f3170);
        a->Free(unk10.m_pData, n * 16, 0x17);
    }
}

}
}   // namespace f3m_009deff0

// @f3 0x009c6ee0 (community match, verified in this file)
extern int DAT_010f3170;
extern void* const VTBL_00e7f1c8;
namespace f3m_009c6ee0 {
// 0x009c6ee0  ?CreateRetObj@@YAXXZ

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

extern void __cdecl FUN_0096fbc0(void* src, void* dst);

namespace f3m_009c6ee0 {


struct Node {
    void* vtbl;      // 0x00
    short unk04;     // 0x04
    short unk06;     // 0x06
    int   unk08;     // 0x08
    short unk0c;     // 0x0c
    short unk0e;     // 0x0e
    float rot[4];    // 0x10
};

// pdb: hkpSphereTriangleAgent::createSphereTriangleAgent | hkpSphereTriangleAgent.obj | fnv360_0822_retail, objrun_open, low
// pdb params: bodyA, bodyB, input, mgr
void* FUN_009c6ee0(int a, void* b, int c, int d)
{
    f3m_009cb0c0::Holder* holder = (f3m_009cb0c0::Holder*)TlsGetValue(DAT_010f3170);
    Node* n = (Node*)holder->FUN_008f6d30(0x20, 0x1f);
    n->unk08 = d;
    n->unk04 = 0x20;
    n->unk06 = 1;
    n->vtbl = (void*)&VTBL_00e7f1c8;
    n->unk0c = 0xffff;
    FUN_0096fbc0((char*)*(void**)b + 0x20, n->rot);
    return n;
}

}
}   // namespace f3m_009c6ee0

// @f3 0x009d3320 (community match, verified in this file)
namespace f3m_009d3320 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
// pdb: hkpMultiSphereAgent::`scalar deleting destructor' | hkpMultiSphereAgent.obj | fnv360_0822_retail, vtable, high
namespace Delete391{extern unsigned long DAT_010f3170;extern int DAT_00dcc494;struct Heap{void FUN_008f6d90(void*,unsigned int,int);};struct Entry{unsigned int key,value;};struct Array{Entry*data;unsigned int size,capacityFlags;void Free(){if(!(capacityFlags&0x80000000)){unsigned int capacity=capacityFlags&0x3fffffff;Heap*heap=(Heap*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(data,capacity*8,23);}}};struct Owner{void*vtable;unsigned short memory,refs;unsigned int unk08;Array array;Owner*FUN_009d3320(unsigned int);};Owner*Owner::FUN_009d3320(unsigned int flags){array.Free();vtable=&DAT_00dcc494;if(flags&1){Heap*heap=(Heap*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(this,memory,31);}return this;}}
}   // namespace f3m_009d3320

// @f3 0x009d1f40 (community match, verified in this file)
namespace f3m_009d1f40 {
namespace prefixed_constraint_factory {
extern unsigned int DAT_010f3170;extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
struct Heap {void* FUN_008f6d30(unsigned int,int);};
struct Object {void* vtable;unsigned short allocationBytes,refCount;unsigned int unk08;unsigned int unk0c;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1c;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2c;unsigned int unk30;unsigned int unk34; Object* FUN_009d1db0(void*,void*,void*,int);};
// pdb: hkpShapeCollectionAgent::createListAAgent | hkpShapeCollectionAgent.obj | fnv360_0822_debug, objrun + bridge(caller_sim|caller_sim) + skyrim(objrun), high
Object* __cdecl hkpShapeCollectionAgent_createListAAgent(void* a,void* b,void* c,int d){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);Object* memory=(Object*)heap->FUN_008f6d30(sizeof(Object),31);memory->allocationBytes=sizeof(Object);return memory->FUN_009d1db0(a,b,c,d);}
}
}   // namespace f3m_009d1f40

// @f3 0x009ddec0 (community match, verified in this file)
namespace f3m_009ddec0 {
struct FinishLoaded {int finishing;};
struct hkBaseObject {virtual ~hkBaseObject(){}};
struct hkReferencedObject:hkBaseObject {unsigned short memoryFlags;short refCount;hkReferencedObject(FinishLoaded){refCount=1;}};
struct FUN_00d50c90:hkReferencedObject {FUN_00d50c90(FinishLoaded flag):hkReferencedObject(flag){}virtual ~FUN_00d50c90(){}};
struct BridgeAtom {unsigned short type,unk02;void* function;FUN_00d50c90* owner;BridgeAtom(FinishLoaded){FUN_00d21ce0(owner);}void FUN_00d21ce0(FUN_00d50c90*) throw();};
struct FUN_00dd0420_Class {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;FUN_00dd0420_Class* FUN_00dd0420(int) throw();};
struct hkpGenericConstraintData:FUN_00d50c90 {FUN_00d50c90* child; BridgeAtom bridge;FUN_00dd0420_Class scheme;hkpGenericConstraintData(FinishLoaded flag);virtual ~hkpGenericConstraintData();};
// pdb: hkpGenericConstraintData::hkpGenericConstraintData | hkpGenericConstraintData.obj | fnv360_0822_retail, caller_sim, high
// pdb params: f
hkpGenericConstraintData::hkpGenericConstraintData(FinishLoaded flag):FUN_00d50c90(flag),bridge(flag){scheme.FUN_00dd0420(flag.finishing);bridge.FUN_00d21ce0(this);}
}   // namespace f3m_009ddec0

// @f3 0x009d7150 (community match, verified in this file)
namespace f3m_009d7150 {
struct FUN_00d46d40_s {const char* name;const char* FUN_00d46d40();};
namespace named_variant_constructor {
struct NamedVariant {const char* name;const char* className;void* object;FUN_00d46d40_s* type;NamedVariant(const char*,void*,FUN_00d46d40_s*);};
NamedVariant::NamedVariant(const char* n,void* o,FUN_00d46d40_s* t){name=n;object=o;type=t;className=t?t->FUN_00d46d40():0;}
}
}   // namespace f3m_009d7150

// @f3 0x009df400 (community match, verified in this file)
namespace f3m_009df400 {
namespace scheme_command_append {
struct Array;void __cdecl FUN_00901f10(Array*,int);
struct Array {int* data;int count;unsigned int capacity;__forceinline void Append(int value){if(count==(int)(capacity&0x3fffffffu))FUN_00901f10(this,sizeof(int));data[count]=value;++count;}};
struct Scheme {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;Array commands;};
struct Owner {unsigned int unk00;Scheme* scheme;unsigned int unk08,unk0c,unk10;unsigned char unk14,unk15;bool linear,angular;void FUN_009df400();};
void Owner::FUN_009df400(){scheme->commands.Append(10);linear=true;}
}
}   // namespace f3m_009df400

// @f3 0x009df440 (community match, verified in this file)
namespace f3m_009df440 {
namespace scheme_command_append {
struct Array;void __cdecl FUN_00901f10(Array*,int);
struct Array {int* data;int count;unsigned int capacity;__forceinline void Append(int value){if(count==(int)(capacity&0x3fffffffu))FUN_00901f10(this,sizeof(int));data[count]=value;++count;}};
struct Scheme {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;Array commands;};
struct Owner {unsigned int unk00;Scheme* scheme;unsigned int unk08,unk0c,unk10;unsigned char unk14,unk15;bool linear,angular;void FUN_009df440();};
void Owner::FUN_009df440(){scheme->commands.Append(11);angular=true;}
}
}   // namespace f3m_009df440

// @f3 0x009df5c0 (community match, verified in this file)
namespace f3m_009df5c0 {
namespace scheme_command_append {
struct Array;void __cdecl FUN_00901f10(Array*,int);
struct Array {int* data;int count;unsigned int capacity;__forceinline void Append(int value){if(count==(int)(capacity&0x3fffffffu))FUN_00901f10(this,sizeof(int));data[count]=value;++count;}};
struct Scheme {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;Array commands;};
struct Owner {unsigned int unk00;Scheme* scheme;unsigned int unk08,unk0c,unk10;unsigned char unk14,unk15;bool linear,angular;void FUN_009df5c0();};
void Owner::FUN_009df5c0(){scheme->commands.Append(0);}
}
}   // namespace f3m_009df5c0

// @f3 0x009dcd80 (community match, verified in this file)
namespace deletion_009dcd80 {
extern unsigned int DAT_010f3170;extern "C" void* (__stdcall* DAT_00d9b080)(unsigned int);
extern const void* const DAT_00dcc494[];
struct Heap {void FUN_008f6d90(void*,int,int);};
struct Header {const void* const* vtable;unsigned short memorySizeAndFlags;short refCount;Header* FUN_009dcd80(unsigned int);};
Header* Header::FUN_009dcd80(unsigned int flags){bool release=(flags&1)!=0;vtable=DAT_00dcc494;if(release){Heap* heap=(Heap*)DAT_00d9b080(DAT_010f3170);heap->FUN_008f6d90(this,memorySizeAndFlags,44);}return this;}
}

// @f3 0x009d6270 (community match, verified in this file)
namespace f3m_009d6270 {
struct S9e4a80 { int FUN_009e4a80(int); };

// pdb: finishLoadedObjecthkbStateMachine | hkbBehaviorReflections.obj | tesv_win, caller_sim, low
int FUN_009d6270(S9e4a80* p)
{
    int result = 1;
    if (p)
        result = p->FUN_009e4a80(result);
    return result;
}
}   // namespace f3m_009d6270

// @f3 0x009dc390 (community match, verified in this file)
namespace f3m_009dc390 {
struct hkBaseObject { virtual ~hkBaseObject() {} };
struct hkReferencedObject : hkBaseObject {
    unsigned short memoryFlags; short references;
    hkReferencedObject() : references(1) {}
};
struct hkpConstraintData : hkReferencedObject {
    void* userData;
    hkpConstraintData() : userData(0) {}
};
struct __declspec(align(16)) Vector4 {
    float x,y,z,w;
    void Zero() { x=y=z=w=0.0f; }
};
struct LocalTranslationsAtom {
    unsigned short type;
    Vector4 first,second;
    LocalTranslationsAtom() : type(3) {}
};
struct SpringAtom {
    unsigned short type; float length;
    SpringAtom() : type(6) {}
};
struct hkpStiffSpringConstraintData : hkpConstraintData {
    LocalTranslationsAtom translations; SpringAtom spring;
    hkpStiffSpringConstraintData();
};
// pdb: hkpStiffSpringConstraintData::hkpStiffSpringConstraintData | hkpStiffSpringConstraintData.obj | tesv_win, objrun_open, low
hkpStiffSpringConstraintData::hkpStiffSpringConstraintData() {
    translations.first.Zero(); translations.second.Zero(); spring.length=0.0f;
}
}   // namespace f3m_009dc390

// @f3 0x009dd1f0 (community match, verified in this file)
namespace nullable_header_1953 {
struct RefObject {virtual void* Destroy(unsigned int);unsigned short allocationBytes;short references;
void Retain(){if(allocationBytes!=0)++references;}
void Release(){if(allocationBytes!=0){--references;if(references==0)Destroy(1);}}};
extern const void* DAT_00e80360[];extern const void* DAT_00dcc494[];
struct Owner {const void** vtable;unsigned short allocationBytes;short references;unsigned int unk08;unsigned int unk0C;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1C;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2C;unsigned int unk30;unsigned int unk34;unsigned int unk38;unsigned int unk3C;unsigned int unk40;unsigned int unk44;unsigned int unk48;unsigned int unk4C;unsigned int unk50;unsigned int unk54;unsigned int unk58;unsigned int unk5C;unsigned int unk60;unsigned int unk64;unsigned int unk68;unsigned int unk6C;unsigned int unk70;unsigned int unk74;unsigned int unk78;unsigned int unk7C;unsigned int unk80;unsigned int unk84;unsigned int unk88;unsigned int unk8C;unsigned int unk90;unsigned int unk94;unsigned int unk98;unsigned int unk9C;unsigned int unkA0;unsigned int unkA4;unsigned int unkA8;RefObject* child;void FUN_009dd1f0();};
void Owner::FUN_009dd1f0(){RefObject* object=child;vtable=DAT_00e80360;if(object)object->Release();vtable=DAT_00dcc494;}
}

// @f3 0x009d7020 (community match, verified in this file)
namespace f3m_009d7020 {
namespace f3m_009d7020 {

struct Val {
    void* unk00;
    short unk04;
    short unk06;
    int*  unk08;
    int* InitFromValue(int* p);
    unsigned char* GetInto(unsigned char* p);
    void Release();
};

struct Owner {
    int FUN_009d6dd0(int* p, int a, int b, int c);
    int FUN_009d7020(int* a0, int a1, int a2, int a3);
};

// pdb: hkLoader::load | hkLoader.obj | tesv_win, caller_sim, low
int Owner::FUN_009d7020(int* a0, int a1, int a2, int a3)
{
    Val v;
    v.InitFromValue(a0);
    if (*v.GetInto((unsigned char*)&a0)) {
        int r = FUN_009d6dd0(v.unk08, a1, a2, a3);
        v.Release();
        return r;
    }
    v.Release();
    return 0;
}

}
}   // namespace f3m_009d7020

// @f3 0x009d8a20 (community match, verified in this file)
namespace f3m_009d8a20 {
// FUN_009d8a20 -- destructor-like body of the class built at 0x9d89b0
// (FUN_00dbd8a0::FUN_00dbd8a0(S_00dbd8a0_Arg*)): releases the three dynamic
// arrays (0x04 / 0x10 / 0x40) and the two member objects (0x20 / 0x30).

struct E02A80Box
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    void Finish();
};

struct FUN_00e02c70_Obj
{
    int unk00, unk04, unk08, unk0c;
    void FUN_00e02c70();
};

namespace f3m_009d8a20 {

struct Holder
{
    void FUN_008f6d90(void* p, int size, int type);
};

struct Mem30
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_009b1160();
};

struct Obj
{
    int unk00;
    void* unk04;
    int unk08;
    unsigned int unk0c;
    void* unk10;
    int unk14;
    unsigned int unk18;
    int unk1c;
    FUN_00e02c70_Obj m20;
    Mem30 m30;
    E02A80Box* unk40;
    int unk44;
    unsigned int unk48;
    unsigned char unk4c;

    void FUN_009d8a20();
};

// pdb: hkBinaryPackfileWriter::SaveContext::~SaveContext | hkBinaryPackfileWriter.obj | fnv360_0822_retail, call_gap, high
void Obj::FUN_009d8a20()
{
    int n = unk44;
    for (int i = 0; i < n; i++)
        unk40[i].Finish();

    f3m_009d5cb0::unkAlloc* (__stdcall *get)(int) = f3m_009d5cb0::FUN_00d9b080;
    if ((unk48 & 0x80000000u) == 0)
    {
        unsigned int cap = unk48 & 0x3fffffff;
        Holder* holder = (Holder*)get(DAT_010f3170);
        holder->FUN_008f6d90(unk40, cap * sizeof(E02A80Box), 0x17);
    }
    m30.FUN_009b1160();
    m20.FUN_00e02c70();
    if ((unk18 & 0x80000000u) == 0)
    {
        unsigned int cap = unk18 & 0x3fffffff;
        Holder* holder = (Holder*)get(DAT_010f3170);
        holder->FUN_008f6d90(unk10, cap * 8, 0x17);
    }
    if ((unk0c & 0x80000000u) == 0)
    {
        unsigned int cap = unk0c & 0x3fffffff;
        Holder* holder = (Holder*)get(DAT_010f3170);
        holder->FUN_008f6d90(unk04, cap * 0x30, 0x17);
    }
}

}
}   // namespace f3m_009d8a20

// @f3 0x009cc850 (community match, verified in this file)
extern int DAT_010f3170;
extern int DAT_00e7ed74;
namespace f3m_009cc850 {

namespace f3m_009cc850 {

struct Blk {
    int unk00;
    unsigned short unk04;
    void FUN_00dacbd0(int a, int b, int c);
    void* FUN_00dabf10(int a, int b, int c);
};

// pdb: hkpPredGskfAgent::createPredGskfAgent | hkpPredGskfAgent.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: bodyA, bodyB, input, mgr
void* FUN_009cc850(int a, int b, int d, int flag)
{
    if (flag)
    {
        f3m_009cb0c0::Holder* h = (f3m_009cb0c0::Holder*)f3m_009cb0c0::TlsGetValue(DAT_010f3170);
        Blk* p = (Blk*)h->FUN_008f6d30(0x80, 0x1f);
        p->unk04 = 0x80;
        p->FUN_00dacbd0(a, b, flag);
        p->unk00 = (int)&DAT_00e7ed74;
        return p;
    }
    f3m_009cb0c0::Holder* h = (f3m_009cb0c0::Holder*)f3m_009cb0c0::TlsGetValue(DAT_010f3170);
    Blk* p = (Blk*)h->FUN_008f6d30(0x30, 0x1f);
    p->unk04 = 0x30;
    return p->FUN_00dabf10(a, b, 0);
}

}
}   // namespace f3m_009cc850

// @f3 0x009dc860 (community match, verified in this file)
namespace f3m_009dc860 {
namespace f3m_009dc860 {

struct Dst {
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
};

struct __declspec(novtable) Src {
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
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    float unk70;
    float unk74;
    float unk78;
    float unk7c;

    void FUN_009dc860(Dst* out);
};

void Src::FUN_009dc860(Dst* out)
{
    out->unk00 = unk50;
    out->unk04 = unk54;
    out->unk08 = unk58;
    out->unk0c = unk5c;
    out->unk10 = unk60;
    out->unk14 = unk64;
    out->unk18 = unk68;
    out->unk1c = unk6c;
    out->unk20 = unk70;
    out->unk24 = unk74;
    out->unk28 = unk78;
    out->unk2c = unk7c;
}

}
}   // namespace f3m_009dc860

// @f3 0x009d5e10 (community match, verified in this file)
namespace f3m_009d5e10 {

struct FUN_009d5e10_Object {
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
    int unk30;
    int unk34;
    unsigned char unk38;
    unsigned char unk39;
    int unk3C;

    FUN_009d5e10_Object* FUN_009d5e10(FUN_009d5e10_Object* source);
};

// pdb: hkpExtendedMeshShape::TrianglesSubpart::operator= | hkpStorageExtendedMeshShape.obj | tesv_win, call_gap_sim, low
FUN_009d5e10_Object* FUN_009d5e10_Object::FUN_009d5e10(FUN_009d5e10_Object* source)
{
    unk00 = source->unk00;
    unk04 = source->unk04;
    unk08 = source->unk08;
    unk0C = source->unk0C;
    unk10 = source->unk10;
    unk14 = source->unk14;
    unk18 = source->unk18;
    unk1C = source->unk1C;
    unk20 = source->unk20;
    unk24 = source->unk24;
    unk28 = source->unk28;
    unk2C = source->unk2C;
    unk30 = source->unk30;
    unk34 = source->unk34;
    unk38 = source->unk38;
    unk39 = source->unk39;
    unk3C = source->unk3C;
    return this;
}
}   // namespace f3m_009d5e10

// @f3 0x009da900 (community match, verified in this file)
extern int DAT_010f3170;
namespace f3m_009da900 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);

struct Record_009da900 {
    int unk00;
    int unk04;
};

struct Arg1_009da900 {
    Record_009da900* record;
    int kind;
};

struct Arg2_009da900 {
    void* unk00;
    int unk04;
};

struct Holder_009da900 {
    void* FUN_008f6d30(int a, int b);
};

struct Node_009da900 {
    int unk00;
    unsigned short unk04;
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
    float unk30;
    float unk34;

    void* FUN_009da8b0(int a, int b, int c);
};

struct Shape_009da900 {
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
    float unk30;
    float unk34;

    void* hkpAngularDashpotAction_clone(Arg1_009da900* first, Arg2_009da900* second);
};

// pdb: hkpAngularDashpotAction::clone | hkpAngularDashpotAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void* Shape_009da900::hkpAngularDashpotAction_clone(Arg1_009da900* first,
                                  Arg2_009da900* second)
{
    if (first->kind != 2) return 0;
    if (second->unk04 != 0) return 0;

    Holder_009da900* holder = (Holder_009da900*)TlsGetValue(DAT_010f3170);
    Node_009da900* node = (Node_009da900*)holder->FUN_008f6d30(0x40, 0x29);

    node->unk04 = 0x40;

    Record_009da900* record = first->record;
    Node_009da900* result =
        (Node_009da900*)node->FUN_009da8b0(record->unk00, record->unk04, this->unk10);

    result->unk20 = this->unk20;
    result->unk24 = this->unk24;
    result->unk28 = this->unk28;
    result->unk2c = this->unk2c;
    result->unk30 = this->unk30;
    result->unk34 = this->unk34;

    return result;
}
}   // namespace f3m_009da900

// @f3 0x009d6d80 (community match, verified in this file)
#include <new>
namespace f3m_009d6d80 {
namespace task1732 {
struct FinishFlag {
    int finishing;
    FinishFlag() : finishing(1) {}
};
struct FUN_00a45d60 {
    virtual void vf00();
    unsigned short unk04,flags06;
    unsigned int unk08,type0c;
    void* interface10;
    unsigned int unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30;
    void* entries34;
    int count38;
    FUN_00a45d60(FinishFlag) throw();
};
// pdb: finishLoadedObjecthkpMeshShape | hkpMeshShapeClass.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(caller_sim), high
void __cdecl finishLoadedObjecthkpMeshShape(void* memory) {
    FinishFlag flag;
    new (memory) FUN_00a45d60(flag);
}
}
}   // namespace f3m_009d6d80

// @f3 0x009d6dd0 (community match, verified in this file)
namespace f3m_009d6dd0 {
namespace slot29d6dd0 {
struct Alloc {void* FUN_008f6d30(int,int);};extern unsigned DAT_010f3170;extern Alloc*(__stdcall*const DAT_00d9b080)(unsigned);
struct Kind {int value;Kind(const Kind& other):value(other.value){} };
Kind __cdecl FUN_00a49950(void*);void __cdecl FUN_009407f0(void*,void*);void __cdecl FUN_00901f10(void*,int);
struct Object;struct Shared {void** table;unsigned short size,refs;};
struct Table {void(__thiscall* destroy)(Object*,int);void* slot04;void* slot08;int(__thiscall* check)(Object*,void*);int(__thiscall* build)(Object*,void*);void* slot14;void* slot18;void* slot1c;void* slot20;void* slot24;void* slot28;Shared*(__thiscall* shared)(Object*);};
struct Object {Table* table;unsigned short size,refs;Object* FUN_00a48890();Object* FUN_00a47330();};
struct Context {void* FUN_009b0490(void*);};
struct Array {Shared** data;int count;unsigned capacity;void Add(Shared* value){if(count==(int)(capacity&0x3fffffffu))FUN_00901f10(this,4);data[count++]=value;}};
struct Owner {int unk00,unk04;Array array;int FUN_009d6dd0(void*,Context*,void*,void*);};
int Owner::FUN_009d6dd0(void* type,Context* context,void* arg3,void* arg4)
{
 Object* object;
 void* original=type;
 switch(FUN_00a49950(original).value){
 case 3:{Alloc* alloc=DAT_00d9b080(DAT_010f3170);Object* storage=(Object*)alloc->FUN_008f6d30(0x48,6);storage->size=0x48;object=storage->FUN_00a48890();break;}
 case 2:{Alloc* alloc=DAT_00d9b080(DAT_010f3170);Object* storage=(Object*)alloc->FUN_008f6d30(0x88,6);storage->size=0x88;object=storage->FUN_00a47330();break;}
 default:return 0;
 }
 if(object->table->check(object,original))return 0;
 if(arg4)FUN_009407f0(object,arg4);
 Table* ops=object->table;
 void* value=context->FUN_009b0490(arg3);
 int result=ops->build(object,value);
 if(result){Shared* shared=object->table->shared(object);if(shared->size)++shared->refs;array.Add(shared);}
 object->table->destroy(object,1);
 return result;
}
}

}   // namespace f3m_009d6dd0

// @f3 0x009dfc50 (community match, verified in this file)
namespace f3m_009dfc50 {
namespace f3m_009df480 {
extern void __cdecl FUN_00901f10(void* apArray, int aiElemSize);
}

struct F3C50FloatArray {
    float* data;
    int count;
    unsigned int capacity;
};

struct F3C50IntArray {
    int* data;
    int count;
    unsigned int capacity;
};

struct F3C50Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    F3C50FloatArray first;
    F3C50IntArray second;
};

struct F3C50Object {
    int unk00;
    F3C50Owner* unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned char unk19;

    int __thiscall FUN_009dfc50(float* values);
};

// pdb: hkpConstraintConstructionKit::setPivotB | hkpConstraintConstructionKit.obj | tesv_win, call_seq, medium
int __thiscall F3C50Object::FUN_009dfc50(float* values)
{
    F3C50Object* self = this;
    F3C50IntArray* ints = &self->unk04->second;

    if (ints->count == (int)(ints->capacity & 0x3fffffff)) {
        f3m_009df480::FUN_00901f10(ints, 4);
    }
    ints->data[ints->count] = 2;
    ints->count++;

    F3C50Owner* owner = self->unk04;
    int result = owner->first.count;
    F3C50FloatArray* floats = &owner->first;

    if (floats->count == (int)(floats->capacity & 0x3fffffff)) {
        f3m_009df480::FUN_00901f10(floats, 0x10);
    }

    float* destination = floats->data + floats->count * 4;
    floats->count++;
    destination[0] = values[0];
    destination[1] = values[1];
    destination[2] = values[2];
    destination[3] = values[3];

    *((unsigned char*)self + 0x19) = 1;
    return result;
}
}   // namespace f3m_009dfc50

// @f3 0x009d7090 (community match, verified in this file)
extern unsigned int DAT_011693ac;
struct RuntimeService{virtual void slot0();virtual void slot4();virtual void slot8();virtual void* GetContext();};
extern RuntimeService* DAT_010f3438;
struct RuntimeOwner{int FUN_009d6fd0(void* key,void* context,unsigned int bytes);int FUN_009d7090(void* key);};
int RuntimeOwner::FUN_009d7090(void* key){return FUN_009d6fd0(key,DAT_010f3438->GetContext(),DAT_011693ac);}

// @f3 0x009d7110 (community match, verified in this file)
extern unsigned int DAT_011693ac;
extern RuntimeService* DAT_010f3438;
namespace f3m_009d7110 {
struct RuntimeService{virtual void slot0();virtual void slot4();virtual void slot8();virtual void* GetContext();};
struct RuntimeOwner{int FUN_009d70c0(void* key,void* context,unsigned int bytes);int FUN_009d7110(void* key);};
// pdb: hkpPhysicsData::operator delete | hkpPhysicsDataClass.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkLoader::load)
// pdb params: p
int RuntimeOwner::FUN_009d7110(void* key){return FUN_009d70c0(key,DAT_010f3438->GetContext(),DAT_011693ac);}
}   // namespace f3m_009d7110

// @f3 0x009d6ff0 (community match, verified in this file)
extern unsigned int DAT_011693ac;
extern RuntimeService* DAT_010f3438;
namespace f3m_009d6ff0 {
struct RuntimeService{virtual void slot0();virtual void slot4();virtual void slot8();virtual void* GetContext();};
struct RuntimeOwner{void FUN_009d6dd0(void* key,void* descriptor,void* context,unsigned int bytes);void FUN_009d6ff0(void* key,void* descriptor);};
void RuntimeOwner::FUN_009d6ff0(void* key,void* descriptor){FUN_009d6dd0(key,descriptor,DAT_010f3438->GetContext(),DAT_011693ac);}
}   // namespace f3m_009d6ff0

// @f3 0x009d61b0 (community match, verified in this file)
namespace f3m_009d61b0 {
class S009d5070 {
public:
    int FUN_009d5070(int);
};

// pdb: finishLoadedObjecthkpStorageExtendedMeshShapeShapeSubpartStorage | hkpCollidehkpExtendedMeshShapeReflections.obj | tesv_win, objrun_prop, low
int FUN_009d61b0(void* self)
{
    int result = 1;
    if (self)
        result = ((S009d5070*)self)->FUN_009d5070(result);
    return result;
}
}   // namespace f3m_009d61b0

// @f3 0x009d73c0 (community match, verified in this file)
extern int DAT_010f3170;
extern int DAT_00e7ff88;
extern int DAT_00dcc494;
extern const char* DAT_01065194;
namespace f3m_009d73c0 {


extern "C" void _ReadWriteBarrier();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex) throw();

struct StreamWriter;

struct ClassObj
{
    const char* FUN_009b0490() const throw();
    unsigned int FUN_009b0bb0(int flags) const throw();
};

struct VariantObj
{
    void* m_object;
    const ClassObj* m_class;
};

struct PendingWrite
{
    const void* m_pointer;
    const ClassObj* m_klass;
    const void* m_origPointer;
    const ClassObj* m_origClass;
    int m_sectionIndex;
    int m_dataSize;
};

struct PointerMap
{
    void* m_elem;
    int m_numElems;
    int m_hashMod;

    PointerMap() throw()
    {
        FUN_00922cb0();
    }
    ~PointerMap() throw()
    {
        FUN_00922cf0();
    }
    void FUN_00922cb0() throw();
    void FUN_00922cf0() throw();
    int FUN_00922710(const void* key, int val) throw();
    unsigned long FUN_009227d0(unsigned long key, unsigned long def) const throw();
    const char* getWithDefault(const void* key, const char* def) const throw()
    {
        return (const char*)FUN_009227d0((unsigned long)key, (unsigned long)def);
    }
};

struct StringMap
{
    void* m_elem;
    int m_numElems;
    int m_hashMod;
    int m_unk0c;
};

template <typename T>
struct ArrayBase
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    int getSize() const throw() { return m_size; }
    T& operator[](int i) throw() { return m_data[i]; }
    const T& operator[](int i) const throw() { return m_data[i]; }
};

struct AddressNamer
{
    void* vftable;
    const PointerMap* m_knownObjects;
    const PointerMap* m_replacements;
    const PointerMap* m_imports;
    PointerMap m_map;

    AddressNamer(const PointerMap& known, const PointerMap& replace, const PointerMap& imports) throw()
        : vftable(&DAT_00e7ff88),
          m_knownObjects(&known),
          m_replacements(&replace),
          m_imports(&imports)
    {
    }

    void ignore(const void* p) throw()
    {
        m_map.FUN_00922710(p, 0);
    }

    int FUN_009d7750(const void* addr, char* buf, int bufSize) throw();
};

struct MemAlloc
{
    void FUN_008f6d90(void* p, int n, int t) throw();
};

struct InplaceCharArray
{
    char* m_data;
    int m_size;
    int m_capacityAndFlags;
    int m_s0, m_s1, m_s2, m_s3;

    ~InplaceCharArray() throw()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int cap = m_capacityAndFlags & 0x3fffffff;
            _ReadWriteBarrier();
            MemAlloc* a = (MemAlloc*)TlsGetValue(DAT_010f3170);
            a->FUN_008f6d90(m_data, cap, 0x17);
        }
    }
};

struct XmlObjBase
{
    void* vftable;
    int m_memSizeAndFlags;

    ~XmlObjBase() throw()
    {
        vftable = &DAT_00dcc494;
    }
};

struct XmlObjWriter : XmlObjBase
{
    InplaceCharArray m_indent;
    AddressNamer* m_nameFromAddress;

    XmlObjWriter(AddressNamer& namer) throw()
    {
        FUN_00a4b920(namer);
    }

    void FUN_00a4b920(AddressNamer& namer) throw();
    void FUN_00a4b900(int delta) throw();
    int FUN_00a4c480(StreamWriter* writer, const void* data, const ClassObj& klass, const char* name, const char* const* attributes) throw();
};

struct StreamOut
{
    void* vftable;
    int m_memSizeAndFlags;
    StreamWriter* m_writer;

    StreamOut(StreamWriter* s) throw()
    {
        FUN_00943a00(s);
    }
    ~StreamOut() throw()
    {
        FUN_00943a60();
    }

    void FUN_00943a00(StreamWriter* s) throw();
    void FUN_00943a60() throw();
};

void __cdecl FUN_00943960(StreamOut* os, const char* fmt, ...) throw();
void __cdecl FUN_00a4a570(char* buf, int bufLen) throw();
int __cdecl FUN_00923280(char* buf, int len, const char* fmt, ...) throw();

struct SaveOptions
{
    unsigned int m_userTag;
    int m_layout;
    bool m_writeMetaInfo;
    const char* m_contentsVersion;
};

struct VerBuf
{
    int b0, b1, b2, b3, b4, b5, b6, b7;
};

struct AttrList
{
    const char* a0;
    const char* a1;
    const char* a2;
    const char* a3;
    const char* a4;
};

struct SigBuf
{
    int s0, s1, s2;
};

struct NameBuf
{
    int n00, n01, n02, n03, n04, n05, n06, n07;
    int n08, n09, n10, n11, n12, n13, n14, n15;
    int n16, n17, n18, n19, n20, n21, n22, n23;
    int n24, n25, n26, n27, n28, n29, n30, n31;
    int n32, n33, n34, n35, n36, n37, n38, n39;
    int n40, n41, n42, n43, n44, n45, n46, n47;
    int n48, n49, n50, n51, n52, n53, n54, n55;
    int n56, n57, n58, n59, n60, n61, n62, n63;
};

struct XmlPackfileWriter
{
    void* vftable;
    int m_memSizeAndFlags;
    ArrayBase<PendingWrite> m_pendingWrites;
    PointerMap m_knownObjects;
    PointerMap m_imports;
    PointerMap m_exports;
    StringMap m_knownClasses;
    StringMap m_knownEnums;
    PointerMap m_replacements;
    ArrayBase<char*> m_knownSections;
    StringMap m_sectionTagToIndex;
    ArrayBase<VariantObj> m_objectsWithUnregisteredClass;

    int FUN_00a4a7b0(const char* sectionTag) throw();
    int FUN_009d73c0(StreamWriter* stream, const SaveOptions& options) throw();
};

int XmlPackfileWriter::FUN_009d73c0(StreamWriter* stream, const SaveOptions& options) throw()
{
    AddressNamer namer(m_knownObjects, m_replacements, m_imports);
    XmlObjWriter writer(namer);
    int classSectionIndex = FUN_00a4a7b0(DAT_01065194);

    if (options.m_writeMetaInfo == false)
    {
        for (int pendingIndex = 0; pendingIndex < m_pendingWrites.getSize(); ++pendingIndex)
        {
            const PendingWrite& pending = m_pendingWrites[pendingIndex];
            if (pending.m_sectionIndex == classSectionIndex)
            {
                namer.ignore(pending.m_origPointer);
                if (pending.m_origPointer != pending.m_pointer)
                {
                    namer.ignore(pending.m_pointer);
                }
            }
        }
    }

    StreamOut os(stream);
    {
        FUN_00943960(&os, "<?xml version=\"1.0\" encoding=\"ascii\"?>\n");
        const char* contentsversion = options.m_contentsVersion;
        VerBuf defaultContentsVersion;
        if (contentsversion == 0)
        {
            FUN_00a4a570((char*)&defaultContentsVersion, 32);
            contentsversion = (const char*)&defaultContentsVersion;
        }
        FUN_00943960(&os, "<hkpackfile classversion=\"5\" contentsversion=\"%s\">\n", contentsversion);
        writer.FUN_00a4b900(1);
    }

    for (int skippedIndex = 0; skippedIndex < m_objectsWithUnregisteredClass.getSize(); ++skippedIndex)
    {
        const VariantObj& v = m_objectsWithUnregisteredClass[skippedIndex];
        FUN_00943960(&os, "\t<!-- Skipped %s at address %p -->\n", v.m_class->FUN_009b0490(), v.m_object);
    }

    for (int sectionIndex = 0; sectionIndex < m_knownSections.getSize(); ++sectionIndex)
    {
        if (options.m_writeMetaInfo || sectionIndex != classSectionIndex)
        {
            FUN_00943960(&os, "\n\t<hksection name=\"%s\">\n", m_knownSections[sectionIndex]);
            writer.FUN_00a4b900(1);
            for (int pendingIndex = 0; pendingIndex < m_pendingWrites.getSize(); ++pendingIndex)
            {
                const PendingWrite& pending = m_pendingWrites[pendingIndex];
                if (pending.m_sectionIndex == sectionIndex)
                {
                    NameBuf namebuffer;
                    namer.FUN_009d7750(pending.m_origPointer, (char*)&namebuffer, 256);
                    SigBuf sigbuffer;
                    FUN_00923280((char*)&sigbuffer, 11, "%#08x", pending.m_klass->FUN_009b0bb0(0));
                    AttrList attributes;
                    attributes.a0 = "signature";
                    attributes.a1 = (const char*)&sigbuffer;
                    if (const char* exported = m_exports.getWithDefault(pending.m_pointer, 0))
                    {
                        attributes.a2 = "export";
                        attributes.a3 = exported;
                        attributes.a4 = 0;
                    }
                    else
                    {
                        attributes.a2 = 0;
                    }
                    writer.FUN_00a4c480(stream, pending.m_pointer, *pending.m_klass, (const char*)&namebuffer, &attributes.a0);
                    FUN_00943960(&os, "\n");
                }
            }
            writer.FUN_00a4b900(-1);
            FUN_00943960(&os, "\n\t</hksection>");
        }
    }

    writer.FUN_00a4b900(-1);
    FUN_00943960(&os, "\n\n</hkpackfile>\n");
    return 0;
}
}   // namespace f3m_009d73c0

// @f3 0x009df7f0 (community match, verified in this file)
namespace f3m_009df7f0 {
namespace f3m_009df7f0 {
void __cdecl FUN_00901f10(void* arr, int elemSize);
struct Vec9df7f0 { float x, y, z, w; };
template <class T> struct hkArr9df7f0 {
    T* data;
    int size;
    int capFlags;
    void PushBack(const T& t) {
        if (size == (capFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = t;
        size++;
    }
    T& ExpandOne() {
        if (size == (capFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        return data[size++];
    }
};
struct Geom9df7f0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkArr9df7f0<Vec9df7f0> verts;
    hkArr9df7f0<int> flags;
};
struct Builder9df7f0 {
    int unk00;
    Geom9df7f0* geom;
    int unk08;
    int unk0C;
    char unk10;
    char unk11;
    char unk12;
    bool unk13[8];
    int FUN_009df7f0(const Vec9df7f0& v, int type);
};
// pdb: hkpConstraintConstructionKit::setLinearDofB | hkpConstraintConstructionKit.obj | tesv_win, objrun_sim, low
int Builder9df7f0::FUN_009df7f0(const Vec9df7f0& v, int type)
{
    geom->flags.PushBack(4);
    geom->flags.PushBack(type);
    int idx = geom->verts.size;
    Vec9df7f0& e = geom->verts.ExpandOne();
    e.x = v.x; e.y = v.y; e.z = v.z; e.w = v.w;
    unk13[type] = true;
    return idx;
}
}
}   // namespace f3m_009df7f0

// @f3 0x009d5e80 (community match, verified in this file)
namespace f3m_009d5e80 {
namespace f3m_009d5e80 {
struct Obj9d5e80 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned char unk18;
    unsigned char unk19;
    int unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    Obj9d5e80* FUN_009d5e80(const Obj9d5e80* src);
};
Obj9d5e80* Obj9d5e80::FUN_009d5e80(const Obj9d5e80* src)
{
    unk00 = src->unk00;
    unk04 = src->unk04;
    unk08 = src->unk08;
    unk0c = src->unk0c;
    unk10 = src->unk10;
    unk14 = src->unk14;
    unk18 = src->unk18;
    unk19 = src->unk19;
    unk20 = src->unk20;
    unk24 = src->unk24;
    unk28 = src->unk28;
    unk2c = src->unk2c;
    unk30 = src->unk30;
    unk34 = src->unk34;
    unk38 = src->unk38;
    unk3c = src->unk3c;
    return this;
}
}
}   // namespace f3m_009d5e80

// @f3 0x009d98c0 (community match, verified in this file)
extern int DAT_010f3170;
extern int DAT_00e801dc;
extern int DAT_00e7d9c4;
namespace f3m_009d98c0 {
namespace f3m_009d98c0 {
struct Alloc { void FUN_008f6d90(void* p, int n, int t); };
extern Alloc* (__stdcall* const FUN_00d9b080)(int);
struct Vis { void* vtable; short unk04; short flag06; int unk08; int unk0C; int unk10; int unk14; };
struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(Vis* v); };
struct Ent { Obj* obj; int unk04; };
struct Arr {
    Ent* data;
    int count;
    unsigned int capFlags;
    __forceinline void Free() {
        if (!(capFlags & 0x80000000)) {
            unsigned int cap = capFlags & 0x3fffffff;
            Alloc* a = FUN_00d9b080(DAT_010f3170);
            a->FUN_008f6d90(data, cap * 8, 0x17);
        }
    }
};
struct Owner {
    void* vtable;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    Arr arr;
    void FUN_00989aa0();
    __forceinline void Visit() {
        Vis vis;
        vis.flag06 = 1;
        vis.vtable = &DAT_00e7d9c4;
        for (int i = arr.count - 1; i >= 0; --i) {
            Ent& e = arr.data[i];
            e.obj->v7(&vis);
        }
    }
    void FUN_009d98c0();
};
// pdb: hkpCachingShapePhantom::~hkpCachingShapePhantom | hkpCachingShapePhantom.obj | fnv360_0822_retail, call_seq, high
void Owner::FUN_009d98c0() {
    vtable = &DAT_00e801dc;
    Visit();
    arr.count = 0;
    arr.Free();
    FUN_00989aa0();
}
}
}   // namespace f3m_009d98c0

// @f3 0x009d7750 (community match, verified in this file)
extern const char DAT_00dfa2f8[];
void __cdecl FUN_009233d0(char* d, const char* s, int n);
int __cdecl FUN_009233f0(const char* s);
namespace f3m_009d73c0 {

int AddressNamer::FUN_009d7750(const void* addr, char* buf, int bufSize) throw()
{
    if (addr) {
        while (const void* r = m_replacements->getWithDefault(addr, 0))
            addr = r;
        if (const char* name = m_imports->getWithDefault(addr, 0)) {
            FUN_009233d0(buf, DAT_00dfa2f8, bufSize);
            FUN_009233d0(buf + 1, name, bufSize - 1);
            return FUN_009233f0(buf);
        }
        int id = (int)m_map.FUN_009227d0((unsigned long)addr, (unsigned long)-1);
        if (id == -1) {
            if ((int)m_knownObjects->FUN_009227d0((unsigned long)addr, 0) == -1)
                goto null_out;
            id = (m_map.m_numElems & 0x7fffffff) + 1;
            m_map.FUN_00922710(addr, id);
        }
        if (id)
            return FUN_00923280(buf, bufSize, "#%04i", id);
    }
null_out:
    FUN_009233d0(buf, "null", bufSize);
    return 4;
}
}

// @f3 0x009d6000 (community match, verified in this file)
extern int DAT_010f3170;
extern void DAT_00e7fa54();
extern void FUN_00dcc494();
namespace a299 {
struct Alloc { void FUN_008f6d90(void* p, int size, int tag) throw(); };
typedef Alloc* (__stdcall* Getter)(int);
extern Getter FUN_00d9b080;
template <class T> struct Arr { T* data; int size; unsigned int cap;
    void Release(Getter get) { if ((cap & 0x80000000) == 0) { int n = cap & 0x3fffffff; Alloc* a = get(DAT_010f3170); a->FUN_008f6d90(data, n * sizeof(T), 0x17); } }
};
struct Owner {
    void* vtbl; int unk04; Arr<int> a08; Arr<char> a14; Arr<int> a20; Arr<short> a2c;
    void FUN_009d6000();
};
// pdb: hkpStorageExtendedMeshShape::ShapeSubpartStorage::~ShapeSubpartStorage | hkpStorageExtendedMeshShape.obj | fnv360_0822_retail, call_seq, medium
void Owner::FUN_009d6000()
{
    vtbl = (void*)&DAT_00e7fa54;
    Getter get = FUN_00d9b080;
    a2c.Release(get); a20.Release(get); a14.Release(get); a08.Release(get);
    vtbl = (void*)&FUN_00dcc494;
}
}

// @f3 0x009c09c0 (community match, verified in this file)
namespace f3m_009c09c0 {
namespace f3m_009c09c0 {
namespace n9c09c0 {
struct Alloc {
    void* FUN_008f6d30(int size, int tag);
    void FUN_008f6d90(void* p, int size, int tag);
};
extern Alloc* (__stdcall* const FUN_00d9b080)(int);
void __cdecl FUN_0096fbc0(void* src, void* dst) throw();
struct RefObj {
    unsigned short memSize;
    short refCount;
    RefObj() : refCount(1) {}
    virtual ~RefObj();
    static void* operator new(unsigned int size)
    {
        Alloc* al = FUN_00d9b080(DAT_010f3170);
        void* p = al->FUN_008f6d30(size, 0x1f);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p)
    {
        FUN_00d9b080(DAT_010f3170)->FUN_008f6d90(p, ((unsigned short*)p)[2], 0x1f);
    }
};
struct Source { char* data; };
struct Base : RefObj {
    int m8;
    char mc[0x10];
    struct Quad { int a, b, c, d; Quad() : a(-1), b(-1), c(-1), d(-1) {} } q;
    Base(Source* src, int v) : m8(v) {
        FUN_0096fbc0(src->data + 0x20, mc);
    }
    virtual ~Base();
};
struct Obj : Base {
    Obj(Source* src, int v) : Base(src, v) {}
    virtual ~Obj();
};
}
// pdb: hkpMultiSphereTriangleAgent::createTriangleMultiSphereAgent | hkpMultiSphereTriangleAgent.obj | fnv360_0822_retail, uvref + bridge(uvref|uvref) + skyrim(uvref), high
n9c09c0::Obj* __cdecl hkpMultiSphereTriangleAgent_createTriangleMultiSphereAgent(n9c09c0::Source* src, void* unused, void* unused2, int v) {
    return new n9c09c0::Obj(src, v);
}
}
}   // namespace f3m_009c09c0

// @f3 0x009d6ac0 (community match, verified in this file)
#include <windows.h>
namespace Storage2079 {
extern unsigned int DAT_010f3170;
struct Heap {__declspec(nothrow) void __thiscall FUN_008f6d90(void*,unsigned int,int);};
template<class T>struct Array {
    T* data;int size;unsigned int capacity;
    __declspec(nothrow) ~Array(){
        if((capacity&0x80000000u)==0){
            int count=capacity&0x3fffffff;
            Heap* heap=static_cast<Heap*>(TlsGetValue(DAT_010f3170));
            heap->FUN_008f6d90(data,count*sizeof(T),0x17);
        }
    }
};
struct RefObject {virtual ~RefObject(){};unsigned short memorySize;short references;};
struct Storage:RefObject {
    Array<float> vertices;
    Array<unsigned short> indices16;
    Array<unsigned int> indices32;
    Array<unsigned char> materialIndices8;
    Array<unsigned int> materials;
    Array<unsigned short> materialIndices16;
    virtual ~Storage();
};
// pdb: hkpStorageMeshShape::SubpartStorage::~SubpartStorage | hkpStorageMeshShape.obj | fnv360_0822_retail, call_seq, high
Storage::~Storage(){}
}

// @f3 0x009d5ef0 (community match, verified in this file)
namespace f3m_009d5ef0 {
// FUN_009d5ef0: destructor of an hkBaseObject-derived object holding six
// growable arrays; each Array dtor returns its buffer to the TLS pool with
// tag 0x17 under the bit-31 flag test. Real destructor: the derived vftable
// store at entry and the hkBaseObject vftable store at exit are compiler
// generated.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct hkBaseObject { virtual ~hkBaseObject() throw() {} };

namespace n5ef0 {

struct Alloc { void FUN_008f6d90(void* p, int size, int tag); };

template <class T> struct Array {
    T* data;
    int size;
    int capAndFlags;
    ~Array() throw() {
        if ((capAndFlags & 0x80000000) == 0) {
            int cap = capAndFlags & 0x3fffffff;
            Alloc* al = (Alloc*)TlsGetValue(::DAT_010f3170);
            al->FUN_008f6d90(data, cap * sizeof(T), 0x17);
        }
    }
};

struct E16 { int v[4]; };

}

struct FUN_009d5ef0 : hkBaseObject {
    unsigned short memSize;
    short refCount;
    n5ef0::Array<n5ef0::E16> a0;
    n5ef0::Array<short> a1;
    n5ef0::Array<int> a2;
    n5ef0::Array<char> a3;
    n5ef0::Array<int> a4;
    n5ef0::Array<short> a5;
    virtual ~FUN_009d5ef0() throw();
};

// pdb: hkpStorageExtendedMeshShape::MeshSubpartStorage::~MeshSubpartStorage | hkpStorageExtendedMeshShape.obj | fnv360_0822_retail, call_seq, medium
FUN_009d5ef0::~FUN_009d5ef0() throw()
{
}
}   // namespace f3m_009d5ef0

// @f3 0x009df980 (community match, verified in this file)
namespace f3m_009df980 {
namespace AppendGeometry2216 {
struct Vec {
    float x,y,z,w;
    void Copy(const Vec& v){x=v.x;y=v.y;z=v.z;w=v.w;}
};
void __cdecl FUN_00901f10(void*,unsigned);
template<class T> struct Array {
    T* data; int size; unsigned capacity;
    void Ensure() {
        if (size==static_cast<int>(capacity & 0x3fffffff))
            FUN_00901f10(this,sizeof(T));
    }
};
struct Storage {
    unsigned unk00,unk04,unk08,unk0C;
    Array<Vec> points;
    Array<unsigned> commands;
};
struct Owner {
    unsigned unk00;
    Storage* storage;
    unsigned unk08,unk0C,unk10;
    unsigned short unk14;
    bool dirty;
    int FUN_009df980(const Vec*);
};
// pdb: hkpConstraintConstructionKit::setAngularBasisA | hkpConstraintConstructionKit.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: dofBasis
int Owner::FUN_009df980(const Vec* source) {
    Array<unsigned>& commands=storage->commands;
    commands.Ensure();
    commands.data[commands.size]=8;
    ++commands.size;
    const int previous=storage->points.size;
    Array<Vec>& first=storage->points;
    first.Ensure();
    Vec* firstPoint=&first.data[first.size];
    ++first.size;
    Array<Vec>& second=storage->points;
    firstPoint->Copy(source[0]);
    second.Ensure();
    Vec* p=&second.data[second.size];
    ++second.size;
    Array<Vec>& third=storage->points;
    p->Copy(source[1]);
    third.Ensure();
    p=&third.data[third.size];
    ++third.size;
    p->Copy(source[2]);
    dirty=true;
    return previous;
}
}
}   // namespace f3m_009df980

// @f3 0x009dfaa0 (community match, verified in this file)
namespace f3m_009dfaa0 {
namespace AppendGeometry2217 {
struct Vec {
    float x,y,z,w;
    void Copy(const Vec& v){x=v.x;y=v.y;z=v.z;w=v.w;}
};
void __cdecl FUN_00901f10(void*,unsigned);
template<class T> struct Array {
    T* data; int size; unsigned capacity;
    void Ensure() {
        if (size==static_cast<int>(capacity & 0x3fffffff))
            FUN_00901f10(this,sizeof(T));
    }
};
struct Storage {
    unsigned unk00,unk04,unk08,unk0C;
    Array<Vec> points;
    Array<unsigned> commands;
};
struct Owner {
    unsigned unk00;
    Storage* storage;
    unsigned unk08,unk0C,unk10;
    unsigned short unk14;
    bool unk16;
    bool dirty;
    int FUN_009dfaa0(const Vec*);
};
// pdb: hkpConstraintConstructionKit::setAngularBasisB | hkpConstraintConstructionKit.obj | tesv_win, objrun_sim, low
int Owner::FUN_009dfaa0(const Vec* source) {
    Array<unsigned>& commands=storage->commands;
    commands.Ensure();
    commands.data[commands.size]=9;
    ++commands.size;
    const int previous=storage->points.size;
    Array<Vec>& first=storage->points;
    first.Ensure();
    Vec* firstPoint=&first.data[first.size];
    ++first.size;
    Array<Vec>& second=storage->points;
    firstPoint->Copy(source[0]);
    second.Ensure();
    Vec* p=&second.data[second.size];
    ++second.size;
    Array<Vec>& third=storage->points;
    p->Copy(source[1]);
    third.Ensure();
    p=&third.data[third.size];
    ++third.size;
    p->Copy(source[2]);
    dirty=true;
    return previous;
}
}
}   // namespace f3m_009dfaa0

// @f3 0x009ddc20 (community match, verified in this file)
extern int DAT_01062d90[];
namespace f3m_009ddc20 {
namespace F3Angle9ddc {
struct Vec4 {
    float x,y,z,w;
    float Dot3(const Vec4& other) const {
        return y*other.y + static_cast<const volatile float&>(x)*other.x + z*other.z;
    }
};
float __cdecl FUN_00954db0(float first, float second);
// pdb: calcDeltaAngleAroundAxis | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun_prop, medium
float __fastcall FUN_009ddc20(int index, const Vec4* vectors)
{
    const int first=static_cast<const volatile int&>(DAT_01062d90[index]);
    const int second=static_cast<const volatile int&>(DAT_01062d90[index+1]);
    const Vec4& left=vectors[second+8];
    const Vec4& middle=vectors[first+5];
    
    float firstDot=left.Dot3(middle);
    float secondDot=vectors[first+8].Dot3(middle);
    return FUN_00954db0(firstDot, secondDot);
}
}


}   // namespace f3m_009ddc20

// @f3 0x009da340 (community match, verified in this file)
#include <math.h>
extern int DAT_00e80244;
namespace f3m_009da340 {

namespace workerA9da3 {

struct Vec4 {
    float x;
    float y;
    float z;
    float w;
};

struct Owner {
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float x;
    float y;
    float z;
    float w;
    float a;
    float b;
    volatile unsigned char active;

    void FUN_009ae990(void* source, int unused);
    Owner* FUN_009da340(void* source, const Vec4* direction, float first, float second);
};

// pdb: hkpMotorAction::hkpMotorAction | hkpMotorAction.obj | fnv360_0822_retail, call_seq, high
// pdb params: body, axis, spinRate, gain
Owner* Owner::FUN_009da340(void* source, const Vec4* direction, float first, float second)
{
    FUN_009ae990(source, 0);

    vtable = &DAT_00e80244;
    x = direction->x;
    y = direction->y;
    z = direction->z;
    w = direction->w;
    a = first;
    b = second;
    active = 1;

    float sum = x * x + y * y + z * z + w * w;
    float scale;

    if (sum != 0.0f)
        scale = 1.0f / (float)sqrt(sum);
    else
        scale = 0.0f;

    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;

    return this;
}

}
}   // namespace f3m_009da340

// @f3 0x009d62a0 (community match, verified in this file)
namespace f3m_009d62a0 {
namespace task1081 {
struct W{int x;};struct __declspec(align(16)) Holder{
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
int unk040;
int unk044;
int unk048;
int unk04c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
void FUN_009e4a80(int);};
// pdb: hkpStorageMeshShape::SubpartStorage::operator delete | hkpStorageMeshShape.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: getVtablehkbStateMachine)
// pdb params: p
int FUN_009d62a0(){Holder h;h.FUN_009e4a80(W().x);return h.unk000;}
}
}   // namespace f3m_009d62a0

// @f3 0x009cdeb0 (community match, verified in this file)
extern int DAT_00e7e9c8;extern float DAT_00de6e60;
namespace f3m_009cdeb0 {
namespace transform9c {
struct Vector {float x,y,z,w;};
struct Transform {__declspec(align(16)) Vector rows[7];};
struct Parameter {__declspec(align(16)) int* table;float scale;int unk08;int unk0C;Vector position;void* object;
 Parameter(const Vector& v,void* p):table(&DAT_00e7e9c8),scale(DAT_00de6e60),position(v),object(p){}
};
void FUN_009cd860(void*,void*,Transform*,Parameter*,Parameter*);
// pdb: hkpSymmetricAgentLinearCast<hkpTransformAgent>::staticLinearCast | hkpTransformAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void FUN_009cdeb0(void* first,void* second,const Transform* input,void* a,void* b){
 Transform inverted=*input;inverted.rows[5].x=-input->rows[5].x;inverted.rows[5].y=-input->rows[5].y;inverted.rows[5].z=-input->rows[5].z;inverted.rows[5].w=-input->rows[5].w;
 Parameter pa(input->rows[5],a);
 if(b){Parameter pb(input->rows[5],b);FUN_009cd860(second,first,&inverted,&pa,&pb);}else FUN_009cd860(second,first,&inverted,&pa,0);
}
}
}   // namespace f3m_009cdeb0

// @f3 0x009dfe30 (community match, verified in this file)
namespace f3m_009dfe30 {
// pdb: hkpConstraintConstructionKit::setAngularLimit | hkpConstraintConstructionKit.obj | tesv_win, objrun_open, low
namespace Command426{struct __declspec(align(16)) Vector{float x,y,z,w;Vector(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}Vector&operator=(const Vector&v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}};template<class T>struct Array{T*data;unsigned int size,capacityFlags;__forceinline void Push(const T&value);};void __cdecl FUN_00901f10(void*,unsigned int);template<class T>__forceinline void Array<T>::Push(const T&value){if(size==(capacityFlags&0x3fffffff))FUN_00901f10(this,sizeof(T));data[size++]=value;}struct Storage{unsigned int unk00,bytes,firstCount,secondCount;Array<Vector>vectors;Array<unsigned int>commands;};struct Owner{unsigned int unk00;Storage*storage;unsigned int FUN_009dfe30(unsigned char,float,float);};unsigned int Owner::FUN_009dfe30(unsigned char kind,float x,float y){storage->commands.Push(17);storage->commands.Push(kind);unsigned int index=storage->vectors.size;storage->vectors.Push(Vector(x,y,0,0));Storage*target=storage;target->bytes+=48;++target->firstCount;++target->secondCount;return index;}}

}   // namespace f3m_009dfe30

// @f3 0x009d41e0 (community match, verified in this file)
namespace f3m_009d41e0 {
// FUN_009d41e0  --  0x009d41e0, 252 bytes
extern const float DAT_00de6e60;
extern char DAT_00e7e9c8;

struct __declspec(align(16)) V4
{
    float x, y, z, w;
};

struct __declspec(align(16)) RCC
{
    const void* p;   // +0x00
    float       f;   // +0x04
    V4          q;   // +0x10
    int         e;   // +0x20
};

struct __declspec(align(16)) BIG
{
    int   unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int   unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int   unk40, unk44, unk48, unk4C;
    V4    q;                   // +0x50
    int   unk60, unk64, unk68, unk6C;
};

extern "C" void __cdecl FUN_009d3950(int, int, BIG*, RCC*, RCC*);

// pdb: hkpSymmetricAgentLinearCast<hkpBvAgent>::staticLinearCast | hkpBvAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, collector, startCollector
void FUN_009d41e0(int a1, int a2, BIG* src, int p4, int p5)
{
    BIG buf = *src;

    buf.q.x = -src->q.x;
    buf.q.y = -src->q.y;
    buf.q.z = -src->q.z;
    buf.q.w = -src->q.w;

    RCC a;
    RCC b;

    b.p = &DAT_00e7e9c8;
    b.f = DAT_00de6e60;
    b.q = src->q;
    b.e = p4;

    if (p5)
    {
        a.p = &DAT_00e7e9c8;
        a.f = DAT_00de6e60;
        a.q = src->q;
        a.e = p5;
        FUN_009d3950(a2, a1, &buf, &b, &a);
    }
    else
    {
        FUN_009d3950(a2, a1, &buf, &b, 0);
    }
}
}   // namespace f3m_009d41e0

// @f3 0x009d2f50 (community match, verified in this file)
extern int DAT_00e7e9c8;extern float DAT_00de6e60;
namespace f3m_009d2f50 {
namespace Native1702 {
struct __declspec(align(16)) Vec {float x,y,z,w;};
struct Input {
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
Vec v;unsigned unk60,unk64,unk68,unk6c;};
struct Q {void* vtable;float scalar;unsigned unk08,unk0c;Vec v;int filter;unsigned unk24,unk28,unk2c;};
void hkpMultiSphereAgent_staticLinearCast(int,int,Input*,Q*,Q*);
// pdb: hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::staticLinearCast | hkpMultiSphereAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, collector, startCollector
void FUN_009d2f50(int a,int b,Input* p,int d,int e){
Input copy=*p;
copy.v.x=-p->v.x;copy.v.y=-p->v.y;copy.v.z=-p->v.z;copy.v.w=-p->v.w;
Q qa;qa.scalar=DAT_00de6e60;qa.vtable=&DAT_00e7e9c8;qa.v=p->v;qa.filter=d;
if(e){Q qb;qb.vtable=&DAT_00e7e9c8;qb.scalar=DAT_00de6e60;qb.v=p->v;qb.filter=e;hkpMultiSphereAgent_staticLinearCast(b,a,&copy,&qa,&qb);}
else hkpMultiSphereAgent_staticLinearCast(b,a,&copy,&qa,0);
}
}
}   // namespace f3m_009d2f50

// @f3 0x009c0790 (community match, verified in this file)
extern int DAT_00e7e9c8;extern float DAT_00de6e60;
namespace f3m_009c0790 {
namespace Native1791 {
struct __declspec(align(16)) Vec {float x,y,z,w;};
struct Input {
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
Vec v;unsigned unk60,unk64,unk68,unk6c;};
struct Q {void* vtable;float scalar;unsigned unk08,unk0c;Vec v;int filter;unsigned unk24,unk28,unk2c;};
struct Owner { void FUN_00a3a750(int,int,Input*,Q*,Q*); void FUN_009c0790(int,int,Input*,int,int); };
void Owner::FUN_009c0790(int a,int b,Input* p,int d,int e){
Input copy=*p;
copy.v.x=-p->v.x;copy.v.y=-p->v.y;copy.v.z=-p->v.z;copy.v.w=-p->v.w;
Q qa;qa.scalar=DAT_00de6e60;qa.vtable=&DAT_00e7e9c8;qa.v=p->v;qa.filter=d;
if(e){Q qb;qb.vtable=&DAT_00e7e9c8;qb.scalar=DAT_00de6e60;qb.v=p->v;qb.filter=e;FUN_00a3a750(b,a,&copy,&qa,&qb);}
else FUN_00a3a750(b,a,&copy,&qa,0);
}
}
}   // namespace f3m_009c0790

// @f3 0x009ce1b0 (community match, verified in this file)
extern float DAT_00de6e60;
namespace f3m_009ce1b0 {
namespace n9ce1b0 {
struct __declspec(align(16)) V { float x, y, z, w; };
struct Body {
    V a, b, c, d, e;
    V v;
    V g;
};
struct Collector {
    virtual void v00();
    float tol;
    Collector() : tol(DAT_00de6e60) {}
};
struct Filter : Collector {
    V v;
    void* p;
    Filter(const V& a, void* b) : v(a), p(b) {}
};
}
struct C9ce1b0 {
    void FUN_009cd7f0(int a, int b, const n9ce1b0::Body* body, n9ce1b0::Filter* f1, n9ce1b0::Filter* f2);
    void FUN_009ce1b0(int a, int b, const n9ce1b0::Body* body, void* p1, void* p2);
};
// pdb: hkpSymmetricAgent<hkpTransformAgent>::linearCast | hkpTransformAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void C9ce1b0::FUN_009ce1b0(int a, int b, const n9ce1b0::Body* body, void* p1, void* p2)
{
    n9ce1b0::Body c = *body;
    c.v.x = -body->v.x;
    c.v.y = -body->v.y;
    c.v.z = -body->v.z;
    c.v.w = -body->v.w;
    n9ce1b0::Filter f1(body->v, p1);
    if (p2) {
        n9ce1b0::Filter f2(body->v, p2);
        FUN_009cd7f0(b, a, &c, &f1, &f2);
    } else {
        FUN_009cd7f0(b, a, &c, &f1, 0);
    }
}
}   // namespace f3m_009ce1b0

// @f3 0x009de870 (community match, verified in this file)
namespace f3m_009de870 {
struct FaceVector {
    float x,y,z,w;
    FaceVector() {}
    FaceVector(const FaceVector& v):x(v.x),y(v.y),z(v.z),w(v.w){}
    FaceVector& operator=(const FaceVector& v) {x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
};
struct FaceTriangle {
    __declspec(align(16)) FaceVector a;
    FaceVector b,c;
    FaceTriangle(const FaceVector& x,const FaceVector& y,const FaceVector& z) { a=x;c=z;b=y; }
};
struct FaceSubdivision {
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
    FaceVector a,b,c,d,e,f;
    int unkb0,unkb4;
    int triangleCount;
};
extern "C" void __cdecl FUN_00a4e410(FaceTriangle*,void*,void*);
// pdb: hkpGenericConstraintData::constrainAllAngularW | hkpGenericConstraintData.obj | tesv_win, objrun, medium
void __stdcall FUN_009de870(void*,void*,void*,FaceSubdivision* shape,void* arg5,void* arg6)
{
    FaceTriangle first(shape->a,shape->c,shape->e);
    FUN_00a4e410(&first,arg5,arg6);
    FaceTriangle second(shape->b,first.a,shape->f);
    FUN_00a4e410(&second,arg5,arg6);
    second.c=shape->d;
    second.b=second.a;
    second.a=first.b;
    FUN_00a4e410(&second,arg5,arg6);
    shape->triangleCount+=3;
}
}   // namespace f3m_009de870

// @f3 0x009c1960 (community match, verified in this file)
namespace n9c1960 {

struct __declspec(align(16)) Key { unsigned k0,k1,k2,k3; };

struct Input {

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

    union { Key key; struct {float x,y,z,w;} values; };

    int unk60,unk64,unk68,unk6c;

};

struct Record { const void* table; float scalar; Key key; int filter; };

extern int DAT_00e7e9c8;

extern const float DAT_00de6e60;

void __cdecl FUN_00a3ab70(int,int,Input*,Record*,Record*);

// pdb: hkpSymmetricAgentLinearCast<hkpMultiRayConvexAgent>::staticLinearCast | hkpMultiRayConvexAgent.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: bodyA, bodyB, input, collector, startCollector
void __cdecl FUN_009c1960(int a2,int a1,const Input* input,int value,int optional) {

    Input local=*input;

    local.values.x=-input->values.x;

    local.values.y=-input->values.y;

    local.values.z=-input->values.z;

    local.values.w=-input->values.w;

    Record rec;

    rec.table=&DAT_00e7e9c8;

    rec.scalar=DAT_00de6e60;

    rec.key=input->key;

    rec.filter=value;

    if(optional) {

        Record rec2;

        rec2.table=&DAT_00e7e9c8;

        rec2.scalar=DAT_00de6e60;

        rec2.key=input->key;

        rec2.filter=optional;

        FUN_00a3ab70(a1,a2,&local,&rec,&rec2);

    } else FUN_00a3ab70(a1,a2,&local,&rec,0);

}

}

// @f3 0x009dde10 (community match, verified in this file)
namespace f3m_009dde10 {
// ---- stand-in types -------------------------------------------------------
class Vec4
{
public:
    float x, y, z, w;
};

class Vec2
{
public:
    float u, v;
};

class __declspec(align(16)) Quad
{
public:
    Vec4  m_kA;     // 0x00
    Vec4  m_kB;     // 0x10
    float m_fC;     // 0x20
    Vec2* m_pD;     // 0x24
};

class Mat
{
public:
    Vec4 m_kRows[11];       // 0x00 .. 0xaf
    int  m_iUnkB0;          // 0xb0
    int  m_iUnkB4;          // 0xb4
    int  m_iIndex;          // 0xb8
};

class Owner
{
public:
    char  m_kUnk00[0x4c];   // 0x00
    Vec2* m_pArray;         // 0x4c
};

void __cdecl FUN_00a4e900(const Quad* q, Owner* owner, void* out);

// NOTE: check this with --flags /MT,/O2,/GS,/EHsc,/Gy. The pack's listed
// /Od /Oy- flags compile it to 270 bytes; they cannot reproduce the target.
// pdb: hkpGenericConstraintData::setLinearFrictionW | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: currentCommand, currentData, scheme, vars, in, out
void __stdcall FUN_009dde10(int** pos, Vec4** vp, void* unused, Mat* mat,
                            Owner* owner, void* out)
{
    Quad q;
    Vec2* arr;
    Vec4* v;
    int i;

    arr = owner->m_pArray;

    ++*pos;
    i = **pos + 2;

    q.m_kB.x = mat->m_kRows[i].x;
    q.m_kB.y = mat->m_kRows[i].y;
    q.m_kB.z = mat->m_kRows[i].z;
    q.m_kB.w = mat->m_kRows[i].w;

    q.m_kA.x = mat->m_kRows[0].x - mat->m_kRows[1].x;
    q.m_kA.y = mat->m_kRows[0].y - mat->m_kRows[1].y;
    q.m_kA.z = mat->m_kRows[0].z - mat->m_kRows[1].z;
    double a = mat->m_kRows[0].w;
    v = (*vp)++;
    q.m_kA.w = (float)(a - mat->m_kRows[1].w);
    q.m_fC = v->x;

    q.m_pD = &arr[mat->m_iIndex];

    FUN_00a4e900(&q, owner, out);

    ++mat->m_iIndex;
}
}   // namespace f3m_009dde10

// @f3 0x009d23c0 (community match, verified in this file)
namespace f3m_009d23c0 {
namespace f3m_009d23c0 {
struct __declspec(align(16)) Vec { float x,y,z,w; };
struct __declspec(align(16)) Matrix { Vec c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10; void FUN_009cdcb0(void*); };
struct Params { float unk00,unk04,unk08; int mode; float scalar; int unk14,unk18,unk1c; void FUN_00970f60(float); };
struct Point { float x,y,z,weight; };
struct InputData { int unk00,unk04,unk08,unk0c,count,unk14,unk18,unk1c; Point points[1]; };
struct Wrapper { InputData* data; int unk04; void* transform; };
struct Context { int unk00,unk04,unk08, offset; };
struct Indirect { Context* context; };
struct CallbackData { Params* params; int index; Matrix* matrix; Wrapper* source; };
typedef void (__cdecl *Callback)(CallbackData*,Indirect*,void*,int);
// pdb: hkpMultiSphereAgent::staticGetClosestPoints | hkpMultiSphereAgent.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void __cdecl hkpMultiSphereAgent_staticGetClosestPoints(Wrapper* source, Indirect* ind, void* table, int arg) {
    InputData* data=source->data;
    Matrix matrix; matrix.FUN_009cdcb0(source->transform);
    Params params; params.FUN_00970f60(0.0f);
    CallbackData cd; cd.source=source; cd.matrix=&matrix;
    int offset=ind->context->offset;
    for (int i=0;i<data->count;++i) {
        Point* p=&data->points[i];
        float x=p->x,y=p->y,z=p->z;
        Vec temp;
        temp.x=matrix.c0.x*x+matrix.c1.x*y+matrix.c2.x*z;
        temp.y=matrix.c0.y*x+matrix.c1.y*y+matrix.c2.y*z;
        temp.z=matrix.c0.z*x+matrix.c1.z*y+matrix.c2.z*z;
        Vec* translation=(Vec*)((char*)source->transform+0x30);
        matrix.c3.x=translation->x+temp.x; matrix.c3.y=translation->y+temp.y;
        matrix.c3.z=translation->z+temp.z; matrix.c3.w=translation->w+0.0;
        params.scalar=p->weight; cd.params=&params; cd.index=i;
        char* base=*(char**)table;
        unsigned int index=*(unsigned char*)(base+offset+(params.mode+13)*32);
        Callback fn=*(Callback*)(base+0x9a8+index*20);
        fn(&cd,ind,table,arg);
    }
}
}



}   // namespace f3m_009d23c0

// @f3 0x009d7190 (community match, verified in this file)
namespace f3m_009d7190 {
struct NodeObj
{
    int FUN_009b0490();
    int Safe() { return this ? FUN_009b0490() : 0; }
};
struct SrcPair { int m_key; NodeObj* m_obj; };
struct Entry
{
    int m_flags;
    int m_value;
    SrcPair m_pair;
    Entry* FUN_009d7190(int a, const SrcPair* b);
    Entry* FUN_009d7190(int a, const SrcPair& b);
};

Entry* Entry::FUN_009d7190(int a, const SrcPair* b) { m_flags = a; m_pair = *b; m_value = m_pair.m_obj ? m_pair.m_obj->FUN_009b0490() : 0; return this; }
}   // namespace f3m_009d7190

// @f3 0x009d9960 (community match, verified in this file)
#include <new>
extern int DAT_010f3170;
namespace f3m_009d9960 {
namespace NativeClone9d9960 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
struct hkThreadMemory {
    void* FUN_008f6d30(int nbytes, int cls) throw();
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    static hkThreadMemory* getInstance() { return (hkThreadMemory*)TlsGetValue(DAT_010f3170); }
};

template <class T> __forceinline void _copy(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
        dst[i] = src[i];
}
template <class T> struct hkArray {
    T* data;
    int size;
    int capacityAndFlags;
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    __forceinline hkArray& operator=(const hkArray& a) {
        if (getCapacity() < a.size) {
            if ((capacityAndFlags & 0x80000000) == 0)
                hkThreadMemory::getInstance()->FUN_008f6d90(data, getCapacity() * sizeof(T), 0x17);
            data = (T*)hkThreadMemory::getInstance()->FUN_008f6d30(a.size * sizeof(T), 0x17);
            capacityAndFlags = (capacityAndFlags & 0x40000000) | a.size;
        }
        size = a.size;
        _copy(data, a.data, size);
        return *this;
    }
};

class FUN_009d9880 {
public:
    static void* operator new(unsigned int n) throw() {
        void* p = hkThreadMemory::getInstance()->FUN_008f6d30(n, 0x31);
        ((unsigned short*)p)[2] = (unsigned short)n;
        return p;
    }
    FUN_009d9880(int a, void* b, int c) throw();

    void* vtbl;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08, unk0c;
    int unk10;
    int unk14, unk18, unk1c, unk20, unk24, unk28;
    int unk2C;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    hkArray<void*> arr80;
    hkArray<void*> arr8C;
    int unk98, unk9c;
    struct ConstructionData {
        unsigned int unk00, unk04, unk08, unk0c;
        unsigned int unk10, unk14, unk18, unk1c;
        unsigned int unk20, unk24, unk28, unk2c;
        unsigned int unk30, unk34, unk38, unk3c;
        unsigned int unk40, unk44, unk48, unk4c;
        unsigned int unk50, unk54, unk58, unk5c;
        unsigned int unk60, unk64, unk68, unk6c;
        unsigned int unk70, unk74, unk78, unk7c;
        unsigned int unk80, unk84, unk88, unk8c;
        unsigned int unk90, unk94, unk98, unk9c;
        unsigned int unka0, unka4, unka8, unkac;
        unsigned int unkb0, unkb4, unkb8, unkbc;
    } info;

    void FUN_0090d960(FUN_009d9880* other) throw();
    FUN_009d9880* FUN_009d9960();
};

// pdb: hkpCachingShapePhantom::clone | hkpCachingShapePhantom.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
FUN_009d9880* FUN_009d9880::FUN_009d9960()
{
    void* storage = FUN_009d9880::operator new(sizeof(FUN_009d9880));
    const int mode = unk2C;
    const int flags = unk10;
    FUN_009d9880* copy = ::new (storage) FUN_009d9880(flags, &info, mode);
    copy->arr80 = arr80;
    copy->arr8C = arr8C;
    copy->FUN_0090d960(this);
    return copy;
}
}
}   // namespace f3m_009d9960

// @f3 0x009dec70 (community match, verified in this file)
namespace f3m_009dec70 {
namespace NativeConstraintCommand {
struct Vector4 {
    float x, y, z, w;
    __forceinline void operator=(const Vector4& source) {
        x = source.x;
        y = source.y;
        z = source.z;
        w = source.w;
    }
};
struct __declspec(align(16)) ConstraintPacket {
    Vector4 first, second, selected;
    float minimum, maximum;
};
struct ConstraintState {
    Vector4 vectors[11];
    unsigned int unkB0, unkB4, current;
};
void __cdecl FUN_00a4fb30(ConstraintPacket*, int*, int);

// pdb: hkpGenericConstraintData::setLinearLimitW | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun, medium
// pdb params: currentCommand, currentData, scheme, vars, in, out
void __stdcall FUN_009dec70(int** commands, float** values, void* scheme,
                          ConstraintState* state, int* configuration, int index)
{
    ++*commands;
    const int vectorIndex = **commands;
    ConstraintPacket packet;
    packet.selected = state->vectors[vectorIndex + 2];
    packet.first = state->vectors[0];
    packet.second = state->vectors[1];
    float* bounds = *values;
    *values = bounds + 4;
    packet.minimum = bounds[0];
    packet.maximum = bounds[1];
    FUN_00a4fb30(&packet, configuration, index);
    ++state->current;
}
}
}   // namespace f3m_009dec70

// @f3 0x009d44e0 (community match, verified in this file)
namespace f3m_009d44e0 {
namespace f3m_009d44e0 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; };
struct Xform { Vec4 r0, r1, r2, r3, r4, pos, r6; };
struct CollectorBase {
    CollectorBase() : early(3.40282e38f) {}
    virtual void F();
    float early;
};
struct Collector : CollectorBase {
    Collector(const Vec4& d, void* u) : dir(d), user(u) {}
    virtual void F();
    Vec4 dir;
    void* user;
};
struct Caster {
    void FUN_009d37b0(void* a, void* b, Xform* t, CollectorBase* c1, CollectorBase* c2);
    void FUN_009d44e0(void* a, void* b, const Xform& t, void* c, void* d);
};
// pdb: hkpSymmetricAgent<hkpBvAgent>::linearCast | hkpBvAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void Caster::FUN_009d44e0(void* a, void* b, const Xform& t, void* c, void* d) {
    Xform copy = t;
    copy.pos.x = -t.pos.x;
    copy.pos.y = -t.pos.y;
    copy.pos.z = -t.pos.z;
    copy.pos.w = -t.pos.w;
    Collector c1(t.pos, c);
    if (d) {
        Collector c2(t.pos, d);
        FUN_009d37b0(b, a, &copy, &c1, &c2);
    } else
        FUN_009d37b0(b, a, &copy, &c1, 0);
}
}

}   // namespace f3m_009d44e0

// @f3 0x009c0d40 (community match, verified in this file)
namespace f3m_009c0d40 {
struct hkQuadReal
{
    float x;
    float y;
    float z;
    float w;
};

struct FNV_ALIGN(16) hkVector4
{
    FNV_FORCEINLINE hkVector4() {}
    FNV_FORCEINLINE hkVector4(const hkVector4& v) { m_quad = v.m_quad; }
    FNV_FORCEINLINE void operator=(const hkVector4& v) { m_quad = v.m_quad; }

    hkQuadReal m_quad;
};

struct hkTransform
{
    FNV_FORCEINLINE hkTransform(const hkTransform& t)
    {
        m_col0 = t.m_col0;
        m_col1 = t.m_col1;
        m_col2 = t.m_col2;
        m_translation = t.m_translation;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4 m_translation;
};

struct hkpShape
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
};

struct hkpTriangleShape : hkpShape
{
    float radius;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 vertices[3];
};

struct hkpMultiSphereShape : hkpShape
{
    int numSpheres;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 spheres[8];
};

struct hkpCdBody
{
    const hkpShape* shape;
    unsigned int shapeKey;
    const hkTransform* motion;
    const hkpCdBody* parent;
};

class hkpCdBodyPairCollector
{
public:
    virtual ~hkpCdBodyPairCollector();
    virtual void addCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
};

struct ClosestPointTriangleCache
{
    float QQ;
    float RR;
    float QR;
    float invTriNormalLen;
};

struct ClosestPointTriangleResult
{
    hkVector4 hitDirection;
    float distance;
};

void __cdecl FUN_0096fbc0(const hkVector4* triangle, ClosestPointTriangleCache& cache);
void __cdecl hkpCollideTriangleUtil_closestPointTriangle(const hkVector4& position, const hkVector4* triangle,
                          const ClosestPointTriangleCache& cache, ClosestPointTriangleResult& result);

// Same as transformPoints; the c0y copy keeps the original operand order.
static FNV_FORCEINLINE void transformVertices(const hkTransform& t, const hkVector4* in, int count, hkVector4* out)
{
    hkVector4 c0 = t.m_col0;
    hkVector4 c1 = t.m_col1;
    hkVector4 c2 = t.m_col2;
    hkVector4 tr = t.m_translation;
    int i = count - 1;
    do
    {
        float c0x = c0.m_quad.x;
        float c1x = c1.m_quad.x;
        float c2x = c2.m_quad.x;
        float c0y = c0.m_quad.y;
        float x = in[i].m_quad.x;
        float y = in[i].m_quad.y;
        float z = in[i].m_quad.z;
        hkVector4& o = out[i];
        o.m_quad.x = (c0x * x + c1x * y + c2x * z) + tr.m_quad.x;
        o.m_quad.y = (c0y * x + c1.m_quad.y * y + c2.m_quad.y * z) + tr.m_quad.y;
        o.m_quad.z = (c0.m_quad.z * x + c1.m_quad.z * y + c2.m_quad.z * z) + tr.m_quad.z;
        o.m_quad.w = 0.0f;
    } while (--i >= 0);
}

static FNV_FORCEINLINE void transformPoints(const hkTransform& t, const hkVector4* in, int count, hkVector4* out)
{
    hkVector4 c0 = t.m_col0;
    hkVector4 c1 = t.m_col1;
    hkVector4 c2 = t.m_col2;
    hkVector4 tr = t.m_translation;
    int i = count - 1;
    do
    {
        float c0x = c0.m_quad.x;
        float c1x = c1.m_quad.x;
        float c2x = c2.m_quad.x;
        float x = in[i].m_quad.x;
        float y = in[i].m_quad.y;
        float z = in[i].m_quad.z;
        hkVector4& o = out[i];
        o.m_quad.x = (c0x * x + c1x * y + c2x * z) + tr.m_quad.x;
        o.m_quad.y = (c0.m_quad.y * x + c1.m_quad.y * y + c2.m_quad.y * z) + tr.m_quad.y;
        o.m_quad.z = (c0.m_quad.z * x + c1.m_quad.z * y + c2.m_quad.z * z) + tr.m_quad.z;
        o.m_quad.w = 0.0f;
    } while (--i >= 0);
}

// pdb: hkpMultiSphereTriangleAgent::staticGetPenetrations | hkpMultiSphereTriangleAgent.obj | fnv360_0822_retail, objrun + bridge(caller_sim|objrun) + skyrim(caller_sim), high
void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const void* input,
                          hkpCdBodyPairCollector& collector)
{
    const hkpTriangleShape* triangleShape = static_cast<const hkpTriangleShape*>(bodyB.shape);
    hkVector4 worldVertices[3];
    transformVertices(*bodyB.motion, &triangleShape->vertices[0], 3, &worldVertices[0]);

    const hkpMultiSphereShape* sphereShape = static_cast<const hkpMultiSphereShape*>(bodyA.shape);
    const int numSpheres = sphereShape->numSpheres;
    const hkVector4* localSpheres = &sphereShape->spheres[0];
    hkVector4 worldSpheres[8];
    transformPoints(*bodyA.motion, localSpheres, numSpheres, &worldSpheres[0]);

    ClosestPointTriangleCache cache;
    FUN_0096fbc0(&triangleShape->vertices[0], cache);

    for (int i = 0; i < numSpheres; ++i)
    {
        float triRadius = triangleShape->radius;
        float radiusSum = localSpheres[i].m_quad.w + triRadius;
        ClosestPointTriangleResult result;
        hkpCollideTriangleUtil_closestPointTriangle(worldSpheres[i], &worldVertices[0], cache, result);
        if (result.distance < radiusSum)
        {
            collector.addCdBodyPair(bodyA, bodyB);
            break;
        }
    }
}
}   // namespace f3m_009c0d40

// @f3 0x009d51f0 (community match, verified in this file)
extern const void* const DAT_00e7fa88[];
extern const void* const DAT_00e7fa64[];
extern int DAT_010f3170;
namespace f3m_009d51f0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Heap { void FUN_008f6d90(void*, int, int); };


struct RefObj {
    unsigned short unk04;
    short ref;
    virtual void Release(int flag) = 0;
};

struct Sub {
    char pad0[0x10];
    RefObj** arr;
    int count;
    char pad18[0x40 - 0x18];
};

struct Obj {
    const void* vtable;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned int unk0C;
    const void* vtable2;
    char pad14[0x58 - 0x14];
    Sub* group58;
    int cnt5c;
    char pad60[0xC0 - 0x60];
    RefObj** arrC0;
    int cntC4;
    int encodedC8;
    RefObj** arrCC;
    int cntD0;
    int encodedD4;
    void FUN_009d51f0();
};

struct Base9e4990 {
    void FUN_009e4990();
};



static inline void Rel(RefObj* p) { if (p->unk04 != 0) { if (--p->ref == 0) p->Release(1); } }
// pdb: hkpStorageExtendedMeshShape::~hkpStorageExtendedMeshShape | hkpStorageExtendedMeshShape.obj | fnv360_0822_retail, call_seq, medium
void Obj::FUN_009d51f0() {
    this->vtable = DAT_00e7fa88;
    this->vtable2 = DAT_00e7fa64;
    for (int i = 0; i < cntC4; i++) Rel(arrC0[i]);
    for (int g = 0; g < cnt5c; g++) {
        Sub* s = &group58[g];
        for (int j = 0; j < s->count; j++) Rel(s->arr[j]);
    }
    cnt5c = 0;
    for (int k = 0; k < cntD0; k++) Rel(arrCC[k]);
    if ((this->encodedD4 & 0x80000000u) == 0) {
        unsigned r = this->encodedD4 & 0x3fffffff;
        void* sub = TlsGetValue(DAT_010f3170);
        unsigned cnt = r * 4;
        ((Heap*)sub)->FUN_008f6d90(this->arrCC, cnt, 0x17);
    }
    if ((this->encodedC8 & 0x80000000u) == 0) {
        unsigned r = this->encodedC8 & 0x3fffffff;
        void* sub = TlsGetValue(DAT_010f3170);
        unsigned cnt = r * 4;
        ((Heap*)sub)->FUN_008f6d90(this->arrC0, cnt, 0x17);
    }
    ((Base9e4990*)this)->FUN_009e4990();
}
}   // namespace f3m_009d51f0

// @f3 0x009d96f0 (community match, verified in this file)
namespace f3m_009d96f0 {
enum QShapeType { QSHAPE_INVALID = 0, QSHAPE_MAX = 32 };
struct QShape { void* vtbl; int unk04; int unk08; QShapeType m_type; QShapeType getType() const { return m_type; } };
struct QCdBody { QShape* m_shape; const QShape* getShape() const { return m_shape; } };
struct QInput;
struct QMgr;
typedef int (__cdecl *QCreateFunc)(const QCdBody&, const QCdBody&, const QInput&, QMgr*);
struct QAgentFuncs { QCreateFunc m_createFunc; int unk04, unk08, unk0C, unk10; };

struct QDispatcher {
    int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC;
    int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C;
    unsigned char m_agent2Types[QSHAPE_MAX][QSHAPE_MAX];
    unsigned char m_agent2TypesPred[QSHAPE_MAX][QSHAPE_MAX];
    QAgentFuncs m_agent2Func[240];
    int unk1C60;
    int getNewCollisionAgent(const QCdBody& a, const QCdBody& b, const QInput& in, QMgr* mgr) const;
};

struct __declspec(align(16)) QInput {
    QDispatcher* m_dispatcher;
    int unk004; int unk008; int unk00C; int m_createPredictiveAgents; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038;
    int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054;
    int unk058; int unk05C; void* unk060; int unk064; int unk068; int unk06C;
};

struct QWorld {
    int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068;
    QInput* unk06C;
};
struct QPair { int unk00; const QCdBody* unk04; };
struct QArr {
    enum { CAPACITY_MASK = 0x3FFFFFFF };
    QPair* m_data; int m_size; unsigned int m_capacityAndFlags;
};
void __cdecl FUN_00901f10(void* arr, int elemSize);

struct QSelf {
    int unk000; int unk004;
    QWorld* unk008;
    int unk00C;
    QCdBody unk010;
    int unk014;
    int unk018; int unk01C; int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034;
    int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054;
    int unk058; int unk05C; int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074;
    int unk078; int unk07C; int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094;
    int unk098; int unk09C; int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4;
    int unk0B8; int unk0BC; int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4;
    int unk0D8; int unk0DC; int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4;
    int unk0F8; int unk0FC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114;
    int unk118; int unk11C; int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134;
    int unk138; int unk13C; int unk140; int unk144; int unk148; int unk14C;
    QArr m_arr;
    int FUN_0091a520(const QCdBody* a);
    void FUN_009d96f0(const QCdBody* a);
};

__forceinline int QDispatcher::getNewCollisionAgent(const QCdBody& a, const QCdBody& b, const QInput& in, QMgr* mgr) const
{
    QShapeType ta = a.getShape()->getType();
    QShapeType tb = b.getShape()->getType();
    const unsigned char* table = in.m_createPredictiveAgents ? &m_agent2TypesPred[0][0] : &m_agent2Types[0][0];
    int idx = table[ta * QSHAPE_MAX + tb];
    QCreateFunc f = m_agent2Func[idx].m_createFunc;
    return f(a, b, in, mgr);
}

// pdb: hkpCachingShapePhantom::addOverlappingCollidable | hkpCachingShapePhantom.obj | tesv_win, objopen_prop, low
void QSelf::FUN_009d96f0(const QCdBody* a)
{
    if (a->m_shape != 0 && FUN_0091a520(a) == 0)
    {
        QArr* arr = &m_arr;
        if (arr->m_size == (int)(arr->m_capacityAndFlags & QArr::CAPACITY_MASK))
            FUN_00901f10(arr, 8);
        QPair* slot = &arr->m_data[arr->m_size++];
        QInput input = *unk008->unk06C;
        input.unk060 = &input.m_dispatcher->unk1C60;
        input.m_createPredictiveAgents = 0;
        slot->unk00 = input.m_dispatcher->getNewCollisionAgent(unk010, *a, input, 0);
        slot->unk04 = a;
    }
}
}   // namespace f3m_009d96f0

// @f3 0x009ce030 (community match, verified in this file)
namespace f3m_009ce030 {
namespace cast3040 {
typedef __declspec(align(16)) float SimdReal;
struct __declspec(align(16)) hkVector4 {
 float x,y,z,w;
 SimdReal getSimdAt3() const { SimdReal r; r=w; return r; }
 void addMul4(const SimdReal& a,const hkVector4& b) { x+=a*b.x; y+=a*b.y; z+=a*b.z; w+=a*b.w; }
 void negate3(const hkVector4& a) {x=-a.x;y=-a.y;z=-a.z;w=a.w;}
};
struct Point { hkVector4 m_pos,m_vHitNormal;int u20,u24,u28,u2c;
 void flip(){m_pos.addMul4(m_vHitNormal.getSimdAt3(),m_vHitNormal);m_vHitNormal.negate3(m_vHitNormal);}
};
struct SubShapeId {
    unsigned char m_kPointA : 4;
    unsigned char m_kPointB : 4;
};

struct CastCollector {
    Point* m_currentPoint;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Point m_point000; Point m_point001; Point m_point002; Point m_point003;
    Point m_point004; Point m_point005; Point m_point006; Point m_point007;
    Point m_point008; Point m_point009; Point m_point010; Point m_point011;
    Point m_point012; Point m_point013; Point m_point014; Point m_point015;
    Point m_point016; Point m_point017; Point m_point018; Point m_point019;
    Point m_point020; Point m_point021; Point m_point022; Point m_point023;
    Point m_point024; Point m_point025; Point m_point026; Point m_point027;
    Point m_point028; Point m_point029; Point m_point030; Point m_point031;
    Point m_point032; Point m_point033; Point m_point034; Point m_point035;
    Point m_point036; Point m_point037; Point m_point038; Point m_point039;
    Point m_point040; Point m_point041; Point m_point042; Point m_point043;
    Point m_point044; Point m_point045; Point m_point046; Point m_point047;
    Point m_point048; Point m_point049; Point m_point050; Point m_point051;
    Point m_point052; Point m_point053; Point m_point054; Point m_point055;
    Point m_point056; Point m_point057; Point m_point058; Point m_point059;
    Point m_point060; Point m_point061; Point m_point062; Point m_point063;
    Point m_point064; Point m_point065; Point m_point066; Point m_point067;
    Point m_point068; Point m_point069; Point m_point070; Point m_point071;
    Point m_point072; Point m_point073; Point m_point074; Point m_point075;
    Point m_point076; Point m_point077; Point m_point078; Point m_point079;
    Point m_point080; Point m_point081; Point m_point082; Point m_point083;
    Point m_point084; Point m_point085; Point m_point086; Point m_point087;
    Point m_point088; Point m_point089; Point m_point090; Point m_point091;
    Point m_point092; Point m_point093; Point m_point094; Point m_point095;
    Point m_point096; Point m_point097; Point m_point098; Point m_point099;
    Point m_point100; Point m_point101; Point m_point102; Point m_point103;
    Point m_point104; Point m_point105; Point m_point106; Point m_point107;
    Point m_point108; Point m_point109; Point m_point110; Point m_point111;
    Point m_point112; Point m_point113; Point m_point114; Point m_point115;
    Point m_point116; Point m_point117; Point m_point118; Point m_point119;
    Point m_point120; Point m_point121; Point m_point122; Point m_point123;
    Point m_point124; Point m_point125; Point m_point126; Point m_point127;
    Point m_point128; Point m_point129; Point m_point130; Point m_point131;
    Point m_point132; Point m_point133; Point m_point134; Point m_point135;
    Point m_point136; Point m_point137; Point m_point138; Point m_point139;
    Point m_point140; Point m_point141; Point m_point142; Point m_point143;
    Point m_point144; Point m_point145; Point m_point146; Point m_point147;
    Point m_point148; Point m_point149; Point m_point150; Point m_point151;
    Point m_point152; Point m_point153; Point m_point154; Point m_point155;
    Point m_point156; Point m_point157; Point m_point158; Point m_point159;
    Point m_point160; Point m_point161; Point m_point162; Point m_point163;
    Point m_point164; Point m_point165; Point m_point166; Point m_point167;
    Point m_point168; Point m_point169; Point m_point170; Point m_point171;
    Point m_point172; Point m_point173; Point m_point174; Point m_point175;
    Point m_point176; Point m_point177; Point m_point178; Point m_point179;
    Point m_point180; Point m_point181; Point m_point182; Point m_point183;
    Point m_point184; Point m_point185; Point m_point186; Point m_point187;
    Point m_point188; Point m_point189; Point m_point190; Point m_point191;
    Point m_point192; Point m_point193; Point m_point194; Point m_point195;
    Point m_point196; Point m_point197; Point m_point198; Point m_point199;
    Point m_point200; Point m_point201; Point m_point202; Point m_point203;
    Point m_point204; Point m_point205; Point m_point206; Point m_point207;
    Point m_point208; Point m_point209; Point m_point210; Point m_point211;
    Point m_point212; Point m_point213; Point m_point214; Point m_point215;
    Point m_point216; Point m_point217; Point m_point218; Point m_point219;
    Point m_point220; Point m_point221; Point m_point222; Point m_point223;
    Point m_point224; Point m_point225; Point m_point226; Point m_point227;
    Point m_point228; Point m_point229; Point m_point230; Point m_point231;
    Point m_point232; Point m_point233; Point m_point234; Point m_point235;
    Point m_point236; Point m_point237; Point m_point238; Point m_point239;
    Point m_point240; Point m_point241; Point m_point242; Point m_point243;
    Point m_point244; Point m_point245; Point m_point246; Point m_point247;
    Point m_point248; Point m_point249; Point m_point250; Point m_point251;
    Point m_point252; Point m_point253; Point m_point254; Point m_point255;
    hkVector4 m_normal3020;
    float m_dist3030;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_uiShapeKeys[4];
    unsigned char m_byte3048;
    unsigned char m_byte3049;
    SubShapeId m_byte304a;
};

class LinearCastAgent {
public:
    void FUN_009cd5c0(int bodyB, int bodyA, int input, int collector);
    void FUN_009ce030(int bodyA, int bodyB, int input, int collector);
};

// @fnv 0x00d34c10
// pdb: hkpSymmetricAgentLinearCast<hkpTransformAgent>::processCollision | hkpTransformAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void LinearCastAgent::FUN_009ce030(int bodyA, int bodyB, int input, int collectorRaw) {
    CastCollector& collector = *(CastCollector*)collectorRaw;
    float saved_dist = collector.m_dist3030;
    Point* y = collector.m_currentPoint;

    FUN_009cd5c0(bodyB, bodyA, input, collectorRaw);

    for (; y < collector.m_currentPoint; ++y) {
        y->flip();
    }

    if (saved_dist != collector.m_dist3030) {
        hkVector4* pNormal = &collector.m_normal3020;
        pNormal->negate3(*pNormal);
        

        unsigned char p = collector.m_byte304a.m_kPointB;
        unsigned char low = collector.m_byte304a.m_kPointA;
        collector.m_byte304a.m_kPointA = p;
        collector.m_byte304a.m_kPointB = low;

        unsigned char cByte48 = collector.m_byte3048;
        unsigned char old49 = collector.m_byte3049;
        collector.m_byte3049 = cByte48;
        unsigned int idx = cByte48;
        idx += old49;
        idx -= 1;
        collector.m_byte3048 = old49;
        unsigned short (&shapeKeys)[4] = collector.m_uiShapeKeys;
        unsigned short old48 = shapeKeys[0];
        shapeKeys[0] = shapeKeys[idx];
        shapeKeys[idx] = old48;

        unsigned char* p48 = &collector.m_byte3048;
        if ((*p48 & collector.m_byte3049) == 2) {
            unsigned short t = collector.m_uiShapeKeys[1];
            collector.m_uiShapeKeys[1] = collector.m_uiShapeKeys[2];
            collector.m_uiShapeKeys[2] = t;
        }
    }
}

}
}   // namespace f3m_009ce030

// @f3 0x009d5910 (community match, verified in this file)
namespace NativeExtendedMesh {
void __cdecl FUN_00901f10(void* array, int elementSize);
void __cdecl FUN_00901e90(void* array, int capacity, int elementSize);
struct ThreadAllocator { void* FUN_008f6d30(unsigned int bytes, int category); };
extern ThreadAllocator* (__stdcall* const DAT_00d9b080)(unsigned long slot);
extern unsigned long DAT_010f3170;
extern const void* DAT_00e7fa54[];

template<class T> struct Array {
    T* data;
    int count;
    unsigned int capacityAndFlags;
    void Initialize() {
        data = 0;
        count = 0;
        capacityAndFlags = 0x80000000u;
    }
    void Append(T value) {
        if (count == static_cast<int>(capacityAndFlags & 0x3fffffffu))
            FUN_00901f10(this, sizeof(T));
        data[count] = value;
        ++count;
    }
    void AppendCopy(const T* value) {
        if (count == static_cast<int>(capacityAndFlags & 0x3fffffffu))
            FUN_00901f10(this, sizeof(T));
        data[count] = *value;
        ++count;
    }
    T* GrowBy(int extra) {
        const int previous = count;
        const int required = previous + extra;
        int capacity = capacityAndFlags & 0x3fffffffu;
        if (capacity < required) {
            capacity += capacity;
            FUN_00901e90(this, required < capacity ? capacity : required, sizeof(T));
        }
        T* start = data + previous;
        count = required;
        return start;
    }
    T& Last() { return data[count - 1]; }
};

struct Shape {
    void* table;
    unsigned short sizeAndFlags;
    unsigned short references;
    void Retain() { if (sizeAndFlags) ++references; }
};
struct ShapeSubpart {
    unsigned char unk00;
    signed char indexType;
    short materialStride;
    const unsigned char* indexBase;
    unsigned short indexStride;
    unsigned short materialCount;
    const unsigned char* materialBase;
    Array<Shape*> childShapes;
    void FUN_009d5e80(const ShapeSubpart* source);
};
struct ShapeSubpartStorage {
    const void* table;
    unsigned short sizeAndFlags, references;
    Array<Shape*> shapes;
    Array<unsigned char> byteIndices;
    Array<unsigned int> materials;
    Array<unsigned short> wordIndices;
};
struct StorageExtendedMesh {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8;
    Array<ShapeSubpartStorage*> subpartStorage;
    ShapeSubpart* hkpExtendedMeshShape_expandOneShapesSubparts();
    void FUN_009e37e0();
    void FUN_009d5910(const ShapeSubpart* input);
};

// pdb: hkpStorageExtendedMeshShape::addShapesSubpart | hkpStorageExtendedMeshShape.obj | fnv360_0822_retail, callee_sim, medium
// pdb params: partIn
void StorageExtendedMesh::FUN_009d5910(const ShapeSubpart* input)
{
    ShapeSubpart* part = hkpExtendedMeshShape_expandOneShapesSubparts();
    ThreadAllocator* allocator = DAT_00d9b080(DAT_010f3170);
    ShapeSubpartStorage* storage = static_cast<ShapeSubpartStorage*>(allocator->FUN_008f6d30(sizeof(ShapeSubpartStorage), 0x25));
    storage->sizeAndFlags = sizeof(ShapeSubpartStorage);
    storage->references = 1;
    storage->table = DAT_00e7fa54;
    storage->shapes.Initialize();
    storage->byteIndices.Initialize();
    storage->materials.Initialize();
    storage->wordIndices.Initialize();
    subpartStorage.Append(storage);
    storage = subpartStorage.Last();
    part->FUN_009d5e80(input);

    for (int i = 0; i < input->childShapes.count; ++i) {
        Shape* shape = input->childShapes.data[i];
        storage->shapes.Append(shape);
        shape->Retain();
    }
    part->childShapes.data = storage->shapes.data;
    part->indexType = input->indexType;
    const unsigned char* indices = input->indexBase;
    if (indices) {
        if (input->indexType == 1) {
            if (input->indexStride == 0) {
                storage->byteIndices.AppendCopy(indices);
                part->indexBase = &storage->byteIndices.Last();
            } else {
                const int childCount = input->childShapes.count;
                unsigned char* destination = storage->byteIndices.GrowBy(childCount);
                part->indexBase = destination;
                const unsigned char* source = input->indexBase;
                for (int i = 0; i < childCount; ++i) {
                    destination[i] = *source;
                    source += input->indexStride;
                }
            }
        } else {
            if (input->indexStride == 0) {
                storage->wordIndices.AppendCopy(reinterpret_cast<const unsigned short*>(indices));
                part->indexBase = reinterpret_cast<const unsigned char*>(&storage->wordIndices.Last());
            } else {
                const int childCount = input->childShapes.count;
                unsigned short* destination = storage->wordIndices.GrowBy(childCount);
                part->indexBase = reinterpret_cast<const unsigned char*>(destination);
                const unsigned char* source = input->indexBase;
                for (int i = 0; i < childCount; ++i) {
                    destination[i] = *reinterpret_cast<const unsigned short*>(source);
                    source += input->indexStride;
                }
            }
        }
        part->indexStride = input->indexStride;
        if (part->indexStride) {
            switch (part->indexType) {
            case 1: part->indexStride = sizeof(unsigned char); break;
            case 2: part->indexStride = sizeof(unsigned short); break;
            }
        }
    } else {
        part->indexBase = 0;
        part->indexStride = 0;
    }

    if (part->indexBase) {
        if (input->materialStride == 0) {
            const unsigned char* materials = input->materialBase;
            storage->materials.AppendCopy(reinterpret_cast<const unsigned int*>(materials));
            part->materialStride = 0;
            part->materialCount = 1;
        } else {
            unsigned int* destination = storage->materials.GrowBy(input->materialCount);
            const unsigned char* materials = input->materialBase;
            for (int i = 0; i < input->materialCount; ++i) {
                destination[i] = *reinterpret_cast<const unsigned int*>(materials);
                materials += input->materialStride;
            }
            part->materialStride = sizeof(unsigned int);
            part->materialCount = input->materialCount;
        }
        part->materialBase = reinterpret_cast<const unsigned char*>(storage->materials.data);
    }
    FUN_009e37e0();
}
}

// @f3 0x009ded20 (community match, verified in this file)
extern double DAT_00dc0760;
namespace f3m_009ded20 {
struct __declspec(align(16)) Vec4 { float x,y,z,w; };
struct AngleRecord { float x,y,angle,unk0c; };
struct AnglePool { Vec4 basis0,basis1,basis2,basis3,basis4,basis5,basis6,basis7,basis8,basis9,basis10; int unkB0,unkB4,count,unkBC; };
struct __declspec(align(16)) SolverInfo { Vec4 jacobian; float f0,f1,out,scale; };
float __fastcall FUN_009ddc20(int index, AnglePool* pool);
void __cdecl FUN_009f90f0(SolverInfo*,void*,void*);
// pdb: hkpGenericConstraintData::setAngularLimitW | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun, medium
// pdb params: currentCommand, currentData, scheme, vars, in, out
void __stdcall FUN_009ded20(int** stream, AngleRecord** cursor, int unused, AnglePool* pool, void* a, void* b) {
 SolverInfo info;
 ++*stream;
 int index=**stream;
 info.scale=0.5f;
 const Vec4& v=((Vec4*)pool)[index+5];
 info.jacobian.x=v.x; info.jacobian.y=v.y; info.jacobian.z=v.z; info.jacobian.w=v.w;
 info.out=FUN_009ddc20(index,pool);
 AngleRecord* p=*cursor;
 info.f0=p->x; *cursor=p+1; info.f1=p->y;
 if(info.out<0.0f && p->angle>0.0f) {
  double adjusted=info.out+DAT_00dc0760;
  if(p->angle-info.out>3.1415927410125732) info.out=adjusted;
 }
 if(info.out>0.0f && p->angle<0.0f) {
  double adjusted=info.out-DAT_00dc0760;
  if(info.out-p->angle>3.1415927410125732) info.out=adjusted;
 }
 p->angle=info.out;
 FUN_009f90f0(&info,a,b);
 ++pool->count;
}

}   // namespace f3m_009ded20

// @f3 0x009d3230 (community match, verified in this file)
extern float DAT_00de6e60;
namespace f3m_009d3230 {
namespace f3m_009d3230 {
struct __declspec(align(16)) Vec { float x, y, z, w; };
struct Transform { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; Vec v; int unk60,unk64,unk68,unk6c; };
struct CollectorBase {
    virtual void Fn();
    float early;
};
struct Collector : CollectorBase {
    Vec v;
    void* target;
    __forceinline Collector(const Vec& d, void* t) { early = DAT_00de6e60; v = d; target = t; }
};
struct Owner {
    void FUN_009d3230(void* a, void* b, const Transform* t, void* c, void* d);
    void hkpMultiSphereAgent_linearCast(void* b, void* a, const Transform* t, const Collector* c, const Collector* d);
};
// pdb: hkpSymmetricAgent<hkpMultiSphereAgent>::linearCast | hkpMultiSphereAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector, startCollector
void Owner::FUN_009d3230(void* a, void* b, const Transform* t, void* c, void* d) {
    Transform m = *t;
    m.v.x = -t->v.x;
    m.v.y = -t->v.y;
    m.v.z = -t->v.z;
    m.v.w = -t->v.w;
    Collector c1(t->v, c);
    if (d) {
        Collector c2(t->v, d);
        hkpMultiSphereAgent_linearCast(b, a, &m, &c1, &c2);
    } else {
        hkpMultiSphereAgent_linearCast(b, a, &m, &c1, 0);
    }
}
}
}   // namespace f3m_009d3230

// @f3 0x009d2b40 (community match, verified in this file)
namespace f3m_009d2b40 {
namespace SphereAgent2053 {
struct __declspec(align(16)) Vector4 {
    float x,y,z,w;
    void Add(const Vector4& a,const Vector4& b){x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w;}
};
struct Transform {
    Vector4 col0,col1,col2,position,center0,center1,unk60,unk70,unk80,unk90,unkA0;
    void FUN_009cdcb0(const Transform*);
};
struct Shape {unsigned int unk00,unk04,unk08;int type;};
struct MultiShape:Shape {int count;unsigned int unk14,unk18,unk1C;Vector4 spheres[8];};
struct __declspec(align(16)) Sphere {
    void* vtable;unsigned short memorySize,refs;unsigned int userData;int type;float radius;
    Sphere(float);
};
struct Body {
    const Shape* shape;unsigned int key;const Transform* transform;const Body* parent;
    Body(const Body* p,const Transform* t):transform(t),parent(p){}
    void Set(const Sphere* s,unsigned int k){shape=(const Shape*)s;key=k;}
};
struct Input;
struct FUN_009d2b40;
typedef FUN_009d2b40* (__cdecl* Create)(const Body&,const Body&,const Input&,void*);
struct DispatchEntry {Create create;unsigned int unk04,unk08,unk0C,unk10;};
struct Dispatcher {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
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
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned char primary[32][32],secondary[32][32];
    DispatchEntry entries[32];
    FUN_009d2b40* NewAgent(const Body&,const Body&,const Input&,void*);
};
struct Input {Dispatcher* dispatcher;unsigned int unk04,unk08,unk0C;int mode;};
inline FUN_009d2b40* Dispatcher::NewAgent(const Body& a,const Body& b,const Input& input,void* manager){
    int firstType=a.shape->type;
    int secondType=b.shape->type;
    unsigned char (*table)[32]=input.mode?secondary:primary;
    Create create=entries[table[firstType][secondType]].create;
    return create(a,b,input,manager);
}
struct Entry {int index;FUN_009d2b40* agent;};
struct Array {Entry* data;int size;unsigned int capacity;};
void __cdecl FUN_00901e90(Array*,int,int);
struct InlineArray:Array {
    Entry local[4];
    InlineArray(){data=local;size=0;capacity=0x80000004;}
    void Reserve(int count){int old=capacity&0x3fffffff;if(old<count){int target=old*2;target=count<target?target:count;FUN_00901e90(this,target,8);}}
    Entry& Append(){int old=size;size=old+1;return data[old];}
};
struct AgentBase {virtual void Slot0();unsigned short memorySize,refs;void* manager;AgentBase(void* p):refs(1),manager(p){}};
struct FUN_009d2b40:AgentBase {
    virtual void Slot0();InlineArray agents;
    FUN_009d2b40(const Body*,const Body&,const Input&,void*);
};
// pdb: hkpMultiSphereAgent::hkpMultiSphereAgent | hkpMultiSphereAgent.obj | fnv360_0822_retail, uvref, high
// pdb params: bodyA, bodyB, input, mgr
FUN_009d2b40::FUN_009d2b40(const Body* first,const Body& second,const Input& input,void* manager):AgentBase(manager),agents() {
    InlineArray* entries=&agents;
    const Body* source=first;
    const MultiShape* shape=(const MultiShape*)source->shape;
    int count=shape->count;
    entries->Reserve(count);
    Sphere sphere(0.0f);
    Transform transformed;
    transformed.FUN_009cdcb0(source->transform);
    Body child(source,&transformed);
    const Vector4* current=shape->spheres;
    for(int i=0;i<count;++i,++current) {
        const Transform* original=first->transform;
        float y,z,x;x=current->x;y=current->y;z=current->z;
        Vector4 rotated;
        rotated.x=transformed.col0.x*x+transformed.col1.x*y+transformed.col2.x*z;
        rotated.y=transformed.col0.y*x+transformed.col1.y*y+transformed.col2.y*z;
        rotated.z=transformed.col0.z*x+transformed.col1.z*y+transformed.col2.z*z;
        rotated.w=0;
        transformed.position.Add(original->position,rotated);
        transformed.center0.Add(original->center0,rotated);
        transformed.center1.Add(original->center1,rotated);
        sphere.radius=current->w;
        child.Set(&sphere,i);
        Entry& entry=entries->Append();
        entry.agent=input.dispatcher->NewAgent(child,second,input,manager);
        entry.index=i;
    }
}
}

}   // namespace f3m_009d2b40

// @f3 0x009d20a0 (community match, verified in this file)
namespace f3m_009d20a0 {

namespace f3m_009d20a0 {
struct __declspec(align(16)) Vec_x { float x,y,z,w;
    __forceinline void setAdd4(const Vec_x& a,const Vec_x& b) {
        x=a.x+b.x; y=a.y+b.y; z=a.z+b.z; w=a.w+b.w;
    }
};
struct Transform_x { Vec_x c0,c1,c2,pos; };
struct Motion_x {
    Transform_x transform;
    Vec_x center0,center1,rotation0,rotation1,deltaAngle;
    float radius,linearDamping,angularDamping,timeFactor;
    float maxLinear,maxAngular,deactivation,unused;
    Motion_x(const Motion_x&);
};
struct Shape_x { void* vtable; unsigned short size,flags; int user; int type; };
struct __declspec(align(16)) Sphere_x : Shape_x { float radius; Sphere_x(float); };
struct Multi_x : Shape_x { int count; Vec_x spheres[8]; };
struct Body_x { Shape_x* shape; unsigned key; const Motion_x* motion; const Body_x* parent;
    Body_x(const Body_x* p,const Motion_x* m) { parent=p; motion=m; }
};
struct Child_x {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void process(const Body_x& body,int a,int b,int c);
};
struct ChildEntry_x { int index; Child_x* child; };
struct List_x {
    void* vtable;
    int unk04;
    int unk08;
    ChildEntry_x* entries;
    int count;
    void hkpMultiSphereAgent_processCollision(const Body_x& a,int b,int c,int d);
};

// pdb: hkpMultiSphereAgent::processCollision | hkpMultiSphereAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void List_x::hkpMultiSphereAgent_processCollision(const Body_x& a,int b,int c,int d)
{
    const Multi_x* multi=static_cast<const Multi_x*>(a.shape);
    Motion_x ms(*a.motion);
    Sphere_x sphere(0.0f);
    Body_x operand(&a,&ms);
    ChildEntry_x* e=entries;
    Vec_x rotated;
    for (int i=count-1;i>=0;i--) {
        const Vec_x& v=multi->spheres[e->index];
        float x=v.x,y=v.y,z=v.z;
        rotated.x=ms.transform.c1.x*y+ms.transform.c0.x*x+ms.transform.c2.x*z;
        rotated.y=ms.transform.c1.y*y+ms.transform.c0.y*x+ms.transform.c2.y*z;
        rotated.z=ms.transform.c1.z*y+ms.transform.c0.z*x+ms.transform.c2.z*z;
        rotated.w=0.0f;
        ms.transform.pos.setAdd4(a.motion->transform.pos,rotated);
        ms.center0.setAdd4(a.motion->center0,rotated);
        ms.center1.setAdd4(a.motion->center1,rotated);
        sphere.radius=v.w;
        operand.shape=&sphere;
        operand.key=i;
        e->child->process(operand,b,c,d);
        e++;
    }
}
}
}   // namespace f3m_009d20a0

// @f3 0x009ddf50 (community match, verified in this file)
namespace f3m_009ddf50 {
// hkpGenericConstraintData scheme interpreter (x87 Havok build).

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    __forceinline hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
    void hkVector4_setTransformedPos(const struct hkTransform* t, const hkVector4* v);
};

struct hkMatrix3
{
    hkVector4 c0, c1, c2;

    void FUN_008dbcd0(const struct hkTransform* t);
    void FUN_0096ce80(const struct hkTransform* t, const hkVector4* m);
};

struct hkTransform
{
    hkMatrix3 m_rotation;
    hkVector4 m_translation;
};

static __forceinline void setRotatedDir(hkVector4& out, const hkMatrix3& m, const hkVector4& v)
{
    float vx = v.x;
    float vy = v.y;
    float vz = v.z;
    out.x = m.c0.x * vx + m.c1.x * vy + m.c2.x * vz;
    out.y = m.c0.y * vx + m.c1.y * vy + m.c2.y * vz;
    out.z = m.c0.z * vx + m.c1.z * vy + m.c2.z * vz;
    out.w = 0.0f;
}

struct hkpGenericConstraintDataScheme
{
    int m_info0, m_info4, m_info8, m_infoC;
    hkVector4* m_data;
    int m_dataSize;
    int m_dataCapacity;
    int* m_commands;
    int m_commandsSize;
    int m_commandsCapacity;
    struct ModifierD9DD** m_modifiers;
    int m_modifiersSize;
    int m_modifiersCapacity;
    struct ConstraintMotorD9DD** m_motors;
};

struct ConstraintMotorD9DD;

struct JacD9DD
{
    int row0;
    int row1;
};

struct InputD9DD
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    union
    {
        float real;
        int bits;
    } factor;
    int unk24, unk28, unk2c, unk30, unk34;
    hkTransform* transformA;
    hkTransform* transformB;
    int unk40, unk44, unk48;
    JacD9DD* jacobians;
    int unk50, unk54, unk58, unk5c;
};

struct StateD9DD
{
    hkVector4 pivotA;
    hkVector4 pivotB;
    hkVector4 axes[3];
    hkMatrix3 basisA;
    hkMatrix3 basisB;
    hkTransform* transformA;
    hkTransform* transformB;
    int count;

    StateD9DD() : count(0) {}
};

struct ModifierD9DD
{
    virtual void v00();
    virtual void Apply(StateD9DD* state, int arg);
};

struct PacketD9DD
{
    hkVector4 r0, r1, r2;
};

void __cdecl FUN_00a4ebf0(PacketD9DD* packet, InputD9DD* input, void* output);
void __cdecl FUN_00a4e410(PacketD9DD* packet, InputD9DD* input, void* output);

struct InterpreterD9DD
{
    void hkpGenericConstraintData_hatchScheme(hkpGenericConstraintDataScheme* scheme, const InputD9DD* input, void* output);
    void FUN_009ddb70(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009de6a0(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009de740(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009de870(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009dec70(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009ded20(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009de9f0(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009debd0(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009df0b0(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009dee30(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009def70(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
    void FUN_009dde10(int**, hkVector4**, hkpGenericConstraintDataScheme*, StateD9DD*, InputD9DD*, void*);
};

// Same-file handlers (bodies written from their listings; reduced where marked).
struct JacParamsD9DD
{
    PacketD9DD packet;
    float value0;
    float value1;
};

struct AngleParamsD9DD
{
    hkVector4 axis;
    float minLimit;
    float maxLimit;
    float current;
    float target;
};

struct JacPtrParamsD9DD
{
    JacD9DD* jacobian;
    int numRows;
    const hkVector4* axis;
    float value;
};

struct MotorParamsD9DD
{
    hkVector4 axis;
    float rhs;
    JacD9DD* jacobian;
};

float __cdecl FUN_00bff9a0(float y, float x);
void __cdecl FUN_00a4fb30(JacParamsD9DD* params, InputD9DD* input, void* output);
void __cdecl FUN_009f90f0(AngleParamsD9DD* params, InputD9DD* input, void* output);
void __cdecl FUN_00a50370(const hkVector4* a0, const hkVector4* b0, const hkVector4* a1, const hkVector4* b1,
                          hkVector4* axisOut, float* angleOut);
void __cdecl FUN_00a4e670(JacPtrParamsD9DD* params, InputD9DD* input, void* output);
void __cdecl FUN_00a4e900(MotorParamsD9DD* params, InputD9DD* input, void* output);
void __cdecl FUN_00a507b0(MotorParamsD9DD* params, hkVector4* axis, InputD9DD* input, void* output, hkVector4* lin);
void __cdecl FUN_00a50540(ConstraintMotorD9DD* motor, MotorParamsD9DD* params, void* out);
void __cdecl FUN_00a50a80(MotorParamsD9DD* params, InputD9DD* input, ConstraintMotorD9DD* motor, void* output);
float __cdecl FUN_009ddc20(const StateD9DD* state, int axis);

// case 7 (0x9ddb70): ball-and-socket, three rows along the unit axes; does not use the command cursor.
void InterpreterD9DD::FUN_009ddb70(int**, hkVector4**, hkpGenericConstraintDataScheme*,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    PacketD9DD packet;
    packet.r0 = state->pivotA;
    packet.r1 = state->pivotB;
    packet.r2.x = 1.0f;
    packet.r2.y = 0.0f;
    packet.r2.z = 0.0f;
    packet.r2.w = 0.0f;
    FUN_00a4ebf0(&packet, input, output);
    packet.r2.x = 0.0f;
    packet.r2.y = 1.0f;
    FUN_00a4ebf0(&packet, input, output);
    packet.r2.y = 0.0f;
    packet.r2.z = 1.0f;
    FUN_00a4ebf0(&packet, input, output);
    state->count += 3;
}

// case 6 (0x9de6a0)
void InterpreterD9DD::FUN_009de6a0(int** commands, hkVector4**, hkpGenericConstraintDataScheme*,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    PacketD9DD packet;
    packet.r2 = state->axes[**commands];
    packet.r0 = state->pivotA;
    packet.r1 = state->pivotB;
    FUN_00a4ebf0(&packet, input, output);
    ++state->count;
}

// case 12 (0x9de740)
void InterpreterD9DD::FUN_009de740(int** commands, hkVector4**, hkpGenericConstraintDataScheme*,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    PacketD9DD packet;
    packet.r2 = state->axes[**commands];
    packet.r0 = state->pivotA;
    packet.r1 = state->pivotB;
    FUN_00a4e410(&packet, input, output);
    ++state->count;
}

// case 13 (0x9de870)
void InterpreterD9DD::FUN_009de870(int** commands, hkVector4**, hkpGenericConstraintDataScheme*,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    PacketD9DD packet;
    packet.r2 = state->axes[**commands];
    packet.r0 = state->pivotA;
    packet.r1 = state->pivotB;
    FUN_00a4e410(&packet, input, output);
    ++state->count;
}

// case 16 (0x9dec70): linear limit along axes[i], limits from the data block.
void InterpreterD9DD::FUN_009dec70(int** commands, hkVector4** data, hkpGenericConstraintDataScheme*,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    JacParamsD9DD params;
    params.packet.r2 = state->axes[**commands];
    const hkVector4* limits = *data;
    ++*data;
    params.packet.r0 = state->pivotA;
    params.packet.r1 = state->pivotB;
    params.value0 = limits->x;
    params.value1 = limits->y;
    FUN_00a4fb30(&params, input, output);
    ++state->count;
}

// case 17 (0x9ded20): angular limit about basisA column i. Reduced: the wrap of the stored
// target angle into the current angle's half turn is kept as one test per side.
void InterpreterD9DD::FUN_009ded20(int** commands, hkVector4** data, hkpGenericConstraintDataScheme*,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    int axis = **commands;
    AngleParamsD9DD params;
    params.axis = (&state->basisA.c0)[axis];
    params.current = FUN_009ddc20(state, axis);
    hkVector4* limits = *data;
    ++*data;
    params.minLimit = limits->x;
    params.maxLimit = limits->y;
    float target = limits->z;
    if (params.current - target > 3.14159265f)
    {
        target += 6.28318531f;
    }
    else if (target - params.current > 3.14159265f)
    {
        target -= 6.28318531f;
    }
    limits->z = target;
    params.target = target;
    FUN_009f90f0(&params, input, output);
    ++state->count;
}

// case 18 (0x9de9f0): twist limit. Reduced: current angle from atan2 of the two basis projections.
void InterpreterD9DD::FUN_009de9f0(int** commands, hkVector4** data, hkpGenericConstraintDataScheme*,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    int axis = **commands;
    const hkVector4& a = (&state->basisA.c0)[axis];
    const hkVector4& b = (&state->basisB.c0)[axis];
    AngleParamsD9DD params;
    params.axis.x = a.y * b.z - a.z * b.y;
    params.axis.y = a.z * b.x - a.x * b.z;
    params.axis.z = a.x * b.y - a.y * b.x;
    params.axis.w = 0.0f;
    params.current = FUN_00bff9a0(params.axis.x, a.x * b.x + a.y * b.y + a.z * b.z);
    const hkVector4* limits = *data;
    ++*data;
    params.minLimit = limits->x;
    params.maxLimit = limits->y;
    FUN_009f90f0(&params, input, output);
    ++state->count;
}

// case 19 (0x9debd0): cone limit between two axis pairs; reads two command words.
void InterpreterD9DD::FUN_009debd0(int** commands, hkVector4** data, hkpGenericConstraintDataScheme*,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    int first = **commands;
    ++*commands;
    int second = **commands;
    AngleParamsD9DD params;
    float angle = 0.0f;
    FUN_00a50370(&(&state->basisA.c0)[first], &(&state->basisB.c0)[first],
                 &(&state->basisA.c0)[second], &(&state->basisB.c0)[second], &params.axis, &angle);
    params.current = angle;
    const hkVector4* limits = *data;
    ++*data;
    params.minLimit = limits->x;
    params.maxLimit = limits->y;
    FUN_009f90f0(&params, input, output);
    ++state->count;
}

// case 14 (0x9df0b0): angular motor. Reduced to the motor lookup and the solver call.
void InterpreterD9DD::FUN_009df0b0(int** commands, hkVector4** data, hkpGenericConstraintDataScheme* scheme,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    int axis = **commands;
    const hkVector4* motorData = *data;
    ++*data;
    ConstraintMotorD9DD* motor = scheme->m_motors[(int)motorData->x];
    if (motor)
    {
        MotorParamsD9DD params;
        params.axis = (&state->basisA.c0)[axis];
        params.rhs = motorData->y - motorData->z;
        params.jacobian = input->jacobians + state->count;
        FUN_00a50540(motor, &params, output);
    }
    ++state->count;
}

// case 15 (0x9dee30): linear motor along axes[i]. Reduced to the motor lookup and the three calls.
void InterpreterD9DD::FUN_009dee30(int** commands, hkVector4** data, hkpGenericConstraintDataScheme* scheme,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    int axis = **commands;
    const hkVector4* motorData = *data;
    ++*data;
    ConstraintMotorD9DD* motor = scheme->m_motors[(int)motorData->x];
    MotorParamsD9DD params;
    params.axis = state->axes[axis];
    hkVector4 diff;
    diff.x = state->pivotA.x - state->pivotB.x;
    diff.y = state->pivotA.y - state->pivotB.y;
    diff.z = state->pivotA.z - state->pivotB.z;
    diff.w = 0.0f;
    params.rhs = params.axis.x * diff.x + params.axis.y * diff.y + params.axis.z * diff.z;
    params.jacobian = input->jacobians + state->count;
    if (motor)
    {
        FUN_00a507b0(&params, &params.axis, input, output, &diff);
        FUN_00a50540(motor, &params, output);
        FUN_00a50a80(&params, input, motor, output);
    }
    ++state->count;
}

// case 20 (0x9def70): one row along basisA column i, value from the data block.
void InterpreterD9DD::FUN_009def70(int** commands, hkVector4** data, hkpGenericConstraintDataScheme*,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    JacPtrParamsD9DD params;
    params.axis = &(&state->basisA.c0)[**commands];
    const hkVector4* values = *data;
    ++*data;
    params.value = values->x;
    params.jacobian = input->jacobians + state->count;
    params.numRows = 1;
    FUN_00a4e670(&params, input, output);
    state->count += 1;
}

// case 21 (0x9dde10): linear row along axes[i] using the pivot difference.
void InterpreterD9DD::FUN_009dde10(int** commands, hkVector4** data, hkpGenericConstraintDataScheme*,
                                   StateD9DD* state, InputD9DD* input, void* output)
{
    ++*commands;
    MotorParamsD9DD params;
    params.axis = state->axes[**commands];
    const hkVector4* values = *data;
    ++*data;
    params.rhs = values->x;
    params.jacobian = input->jacobians + state->count;
    FUN_00a4e900(&params, input, output);
    ++state->count;
}

// pdb: hkpGenericConstraintData::hatchScheme | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun_prop + bridge(caller_sim|call_seq) + skyrim(caller_sim), high
void InterpreterD9DD::hkpGenericConstraintData_hatchScheme(hkpGenericConstraintDataScheme* scheme, const InputD9DD* input, void* output)
{
    InputD9DD localInput = *input;
    StateD9DD state;
    state.transformA = localInput.transformA;
    state.transformB = localInput.transformB;
    hkVector4* data = scheme->m_data;
    int* command = scheme->m_commands;
    ModifierD9DD** modifiers = scheme->m_modifiers;
    for (;;)
    {
        switch (*command)
        {
        case 0:
            return;
        case 3: {
            setRotatedDir(state.axes[*++command], state.transformA->m_rotation, *data);
            ++data;
            break;
        }
        case 4: {
            setRotatedDir(state.axes[*++command], state.transformB->m_rotation, *data);
            ++data;
            break;
        }
        case 5:
            state.axes[*++command] = *data;
            ++data;
            break;
        case 6:
            FUN_009de6a0(&command, &data, scheme, &state, &localInput, output);
            break;
        case 7:
            FUN_009ddb70(&command, &data, scheme, &state, &localInput, output);
            break;
        case 8: {
            hkVector4* m = data;
            data += 3;
            state.basisA.FUN_0096ce80(state.transformA, m);
            break;
        }
        case 9: {
            hkVector4* m = data;
            data += 3;
            state.basisB.FUN_0096ce80(state.transformB, m);
            break;
        }
        case 10:
            state.basisA.FUN_008dbcd0(state.transformA);
            break;
        case 11:
            state.basisB.FUN_008dbcd0(state.transformB);
            break;
        case 12:
            FUN_009de740(&command, &data, scheme, &state, &localInput, output);
            break;
        case 13:
            FUN_009de870(&command, &data, scheme, &state, &localInput, output);
            break;
        case 16:
            FUN_009dec70(&command, &data, scheme, &state, &localInput, output);
            break;
        case 17:
            FUN_009ded20(&command, &data, scheme, &state, &localInput, output);
            break;
        case 18:
            FUN_009de9f0(&command, &data, scheme, &state, &localInput, output);
            break;
        case 19:
            FUN_009debd0(&command, &data, scheme, &state, &localInput, output);
            break;
        case 14:
            FUN_009df0b0(&command, &data, scheme, &state, &localInput, output);
            break;
        case 15:
            FUN_009dee30(&command, &data, scheme, &state, &localInput, output);
            break;
        case 20:
            FUN_009def70(&command, &data, scheme, &state, &localInput, output);
            break;
        case 21:
            FUN_009dde10(&command, &data, scheme, &state, &localInput, output);
            break;
        case 1:
            state.pivotA.hkVector4_setTransformedPos(state.transformA, data);
            ++data;
            break;
        case 2:
            state.pivotB.hkVector4_setTransformedPos(state.transformB, data);
            ++data;
            break;
        case 22: {
            float scale = data->x;
            ++data;
            localInput.factor.real *= scale;
            break;
        }
        case 23:
            localInput.factor.bits = input->factor.bits;
            break;
        case 24: {
            ModifierD9DD* modifier = *modifiers;
            modifier->Apply(&state, *++command);
            ++modifiers;
            break;
        }
        }
        ++command;
    }
}
}   // namespace f3m_009ddf50

// @f3 0x009df8b0 (community match, verified in this file)
namespace f3m_009df8b0 {
void __cdecl FUN_00901f10(void* arr, int elemSize);

struct Vec4009df8b0 {
    float x, y, z, w;
};

template <class T> struct Arr009df8b0 {
    T* data;
    int size;
    int capFlags;
    void PushBack(const T& t) {
        if (size == (capFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = t;
        size++;
    }
    T& ExpandOne() {
        if (size == (capFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        return data[size++];
    }
};

struct Inner009df8b0 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    Arr009df8b0<Vec4009df8b0> verts;
    Arr009df8b0<int> flags;
};

struct Owner009df8b0 {
    unsigned int unk00;
    Inner009df8b0* inner;
    int FUN_009df8b0(const Vec4009df8b0* v, unsigned int idx);
};

// pdb: hkpConstraintConstructionKit::setLinearDofWorld | hkpConstraintConstructionKit.obj | tesv_win, objrun_sim, low
int Owner009df8b0::FUN_009df8b0(const Vec4009df8b0* v, unsigned int idx) {
    inner->flags.PushBack(5);
    inner->flags.PushBack(idx);
    int index = inner->verts.size;
    Vec4009df8b0& e = inner->verts.ExpandOne();
    e.x = v->x;
    e.y = v->y;
    e.z = v->z;
    e.w = v->w;
    unsigned char* bytes = reinterpret_cast<unsigned char*>(this) + 0x10;
    bytes[idx] = 1;
    bytes[idx + 3] = 1;
    return index;
}
}   // namespace f3m_009df8b0

// @f3 0x009dabd0 (community match, verified in this file)
namespace f3m_009dabd0 {
// Hands the result record to the writer interface held at +0x18 and points it at the cached block.

struct F3Writer_9dabd0
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
    virtual void v2c(void* pRecord);
};

struct F3Owner_9dabd0
{
    char pad00[0x18];
    F3Writer_9dabd0* pWriter18;
};

struct F3Result_9dabd0
{
    char pad00[0x10];
    void* pData10;
    int iCount14;
};

// pdb: hkpBreakableConstraintData::isValid | hkpBreakableConstraintData.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpBreakableConstraintData::getConstraintInfo)
void __fastcall FUN_009dabd0(F3Owner_9dabd0* pThis, int iUnused, F3Result_9dabd0* pResult)
{
    pThis->pWriter18->v2c(pResult);
    pResult->pData10 = (char*)pThis + 0xc;
    pResult->iCount14 = 0xc;
}
}   // namespace f3m_009dabd0

// @f3 0x009d9ea0 (community match, verified in this file)
#include <math.h>
namespace f3m_009d9ea0 {
namespace Spring337 {
struct __declspec(align(16)) Vec{float x,y,z,w;void FUN_008d2970(const void*,const Vec&);__forceinline void sub(const Vec&a,const Vec&b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}__forceinline float length(){float square=x*x+y*y+z*z;return (float)sqrt(square);}};
// pdb: hkpSpringAction::setPositionsInWorldSpace | hkpSpringAction.obj | fnv360_0822_retail, objrun, medium
// pdb params: pivotA, pivotB
struct Entity{int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; Vec transform;};struct Owner{int unk00,unk04,unk08,unk0c,unk10,unk14;Entity* a;Entity* b;int unk20,unk24,unk28,unk2c;Vec pivotA,pivotB;float rest;void FUN_009d9ea0(const Vec&,const Vec&);};void Owner::FUN_009d9ea0(const Vec& x,const Vec& y){Entity* first=a;Entity* second=b;pivotA.FUN_008d2970(&first->transform,x);pivotB.FUN_008d2970(&second->transform,y);Vec diff;diff.sub(x,y);rest=diff.length();}
}
}   // namespace f3m_009d9ea0

// @f3 0x009df730 (community match, verified in this file)
namespace f3m_009df730 {
namespace c3_009df730 {

void __cdecl FUN_00901f10(void* arr, int elemSize);

struct Vec4
{
    float x, y, z, w;
};

template <class T> struct hkArr
{
    T* data;
    int size;
    int capFlags;

    void PushBack(const T& t)
    {
        if (size == (capFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = t;
        size++;
    }

    T& ExpandOne()
    {
        if (size == (capFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        return data[size++];
    }
};

struct Geom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkArr<Vec4> verts;
    hkArr<int> commands;
};

struct Builder
{
    int unk00;
    Geom* geom;
    int unk08;
    int unk0c;
    bool used[4];

    int FUN_009df730(const Vec4& v, int slot);
};

// pdb: hkpConstraintConstructionKit::setLinearDofA | hkpConstraintConstructionKit.obj | tesv_win, objrun_sim, low
int Builder::FUN_009df730(const Vec4& v, int slot)
{
    geom->commands.PushBack(3);
    geom->commands.PushBack(slot);
    int idx = geom->verts.size;
    Vec4& e = geom->verts.ExpandOne();
    e.x = v.x;
    e.y = v.y;
    e.z = v.z;
    e.w = v.w;
    used[slot] = true;
    return idx;
}

}
}   // namespace f3m_009df730

// @f3 0x009d49a0 (community match, verified in this file)
namespace f3m_009d49a0 {
extern void* const DAT_00e7f91c[];
void __cdecl FUN_00901e90(void* array, int numElements, int sizeOfElement);

struct Vec4 { float x, y, z, w; Vec4& operator=(const Vec4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct TypeCode { unsigned char value; };

struct Source {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual float GetValue(int x, int y);
    virtual TypeCode GetType();
    int unk04, unk08, unk0c;
    int width, height;
    float f18; int unk1c;
    Vec4 rows[4];
};

struct FloatArray {
    float* data;
    int size;
    int capacityAndFlags;
    FloatArray() : data(0), size(0), capacityAndFlags(0x80000000) {}
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    void setSize(int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(float));
        }
        size = n;
    }
};

struct hkReferencedObject {
    void* const* vptr;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    hkReferencedObject() : referenceCount(1) {}
};
struct Shape : hkReferencedObject {
    int unk08;
    int type;
    Shape() { unk08 = 0; type = 14; vptr = DAT_00e7f91c; }
};
struct Grid : Shape {
    int width, height;
    float f18; int unk1c;
    Vec4 rows[4];
    FloatArray values;
    unsigned char typeCode;
    Grid(Source* src);
};

// pdb: hkpStorageSampledHeightFieldShape::hkpStorageSampledHeightFieldShape | hkpStorageSampledHeightFieldShape.obj | fnv360_0822_retail, call_dedup, high
// pdb params: hf
Grid::Grid(Source* src)
{
    width = src->width;
    height = src->height;
    typeCode = src->GetType().value;
    f18 = src->f18;
    rows[0] = src->rows[0]; rows[1] = src->rows[1]; rows[2] = src->rows[2]; rows[3] = src->rows[3];
    values.setSize(width * height);
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            float& slot = values.data[width * y + x];
            slot = src->GetValue(x, y);
        }
}
}

// @f3 0x009d7250 (community match, verified in this file)
namespace f3m_009d7250 {
namespace Small521 {
struct Entry {const char* name;unsigned unk04,value,unk0c; __forceinline const char* GetName() const { return name; }};
int __cdecl hkString_strCmp(const char*,const char*);
struct Table {
    Entry* entries;
    int count;
    __forceinline Entry* At(int i) { return &entries[i]; }
    __forceinline int Start(unsigned previous) {
        int i = 0;
        Entry* e;
        do {
            if (!previous || i >= count)
                break;
            e = &entries[i];
            ++i;
        } while (e->value != previous);
        return i;
    }
    unsigned FUN_009d7250(const char*,unsigned);
};
// pdb: hkRootLevelContainer::findObjectByName | hkRootLevelContainer.obj | fnv360_0822_retail, call_dedup, low
// pdb params: objectName, prevObject
unsigned Table::FUN_009d7250(const char* name,unsigned previous){
    int i=Start(previous);
    for(;i<count;++i){
        if(hkString_strCmp(name,entries[i].GetName())==0)return entries[i].value;
    }
    return 0;
}
}
}   // namespace f3m_009d7250

// @f3 0x009c9d60 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
#pragma intrinsic(__rdtsc)
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

extern unsigned long hkMonitorStreamTls;

namespace f3m_009c9d60 {

struct hkMonitorTimerCommand
{
    const char* m_commandAndMonitor;
    unsigned int m_time0;
    unsigned int m_time1;
};

struct hkMonitorStream
{
    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;
};

static __forceinline void timerCommand(const char* name, unsigned int& ticks)
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(hkMonitorStreamTls);
    hkMonitorTimerCommand* h = (hkMonitorTimerCommand*)stream->m_end;
    if (h < (hkMonitorTimerCommand*)stream->m_capacityMinus16)
    {
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = *(volatile unsigned int*)&ticks;
        stream->m_end = (char*)(h + 1);
    }
}

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline float lengthSquared3() const
    {
        return x * x + y * y + z * z;
    }
    __forceinline void setMul4(float r, const hkVector4& v)
    {
        x = r * v.x;
        y = r * v.y;
        z = r * v.z;
        w = r * v.w;
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, float r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }
    __forceinline void setXYZ(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
    }
};

extern hkVector4 DAT_010f3370;

struct hkTransform
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4 m_translation;
};

struct hkpSphereShape
{
    void* m_vtable;
    int m_memSizeAndFlags;
    int m_userData;
    int m_type;
    float m_radius;
    float getRadius() const { return m_radius; }
};

struct hkpCdBody
{
    const hkpSphereShape* m_shape;
    unsigned int m_shapeKey;
    const hkTransform* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionInput
{
    void* m_dispatcher;
    float m_tolerance;
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpCdPoint
{
    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
    hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}
};

class hkpCdPointCollector
{
public:
    virtual void vf00();
    virtual void addCdPoint(const hkpCdPoint& event);
};

static __forceinline float distanceAfterRadii(float dist, const float& radiusB, const float& radiusA)
{
    return dist - (radiusB + radiusA);
}

}

using namespace f3m_009c9d60;

#include <math.h>

// pdb: hkpSphereSphereAgent::staticGetClosestPoints | hkpSphereSphereAgent.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel) + skyrim(ustr_rel), high
void __cdecl hkpSphereSphereAgent_staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
                          hkpCdPointCollector& collector)
{
    union
    {
        float f;
        unsigned int u;
    } reusable;
    union
    {
        unsigned int tick;
        float distance;
    } scratch;
    timerCommand("TtSphereSphere", const_cast<unsigned int&>(scratch.tick));

    const hkpSphereShape* sphereA = bodyA.m_shape;
    const hkVector4& posB = bodyB.m_motion->m_translation;
    const hkpSphereShape* sphereB = bodyB.m_shape;
    hkpCdPoint event(bodyA, bodyB);
    const hkVector4& posA = bodyA.m_motion->m_translation;

    hkVector4 vec;
    vec.setSub4(posA, posB);
    scratch.distance = vec.lengthSquared3();
    reusable.f = sphereA->getRadius() + sphereB->getRadius() + input.m_tolerance;
    const float& radiusSum = reusable.f;
    const float& distSquared = scratch.distance;

    if (distSquared < radiusSum * radiusSum)
    {
        float& dist = scratch.distance;
        if (distSquared > 0.0f)
        {
            const float invDist = 1.0f / sqrtf(distSquared);
            event.m_contact.m_separatingNormal.setMul4(invDist, vec);
            dist = distSquared * invDist;
        }
        else
        {
            dist = 0.0f;
            event.m_contact.m_separatingNormal.setXYZ(DAT_010f3370);
        }
        float w = distanceAfterRadii(dist, sphereB->getRadius(), sphereA->getRadius());
        event.m_contact.m_position.setAddMul4(posB, event.m_contact.m_separatingNormal, sphereB->getRadius());
        event.m_contact.m_separatingNormal.w = w;
        collector.addCdPoint(event);
    }

    timerCommand("Et", const_cast<unsigned int&>(scratch.tick));
}

// @f3 0x009da980 (community match, verified in this file)
#include <math.h>
extern const double DAT_00db8b00;
extern const float DAT_00db7df0;
namespace f3m_009da980 {

namespace AngularDashpot {
struct Coord {float value; operator float()const{return value;} Coord& operator*=(float f){value*=f;return *this;} Coord& operator=(const Coord& c){value=c.value;return *this;} Coord& operator=(float f){value=f;return *this;}};



struct __declspec(align(16)) Quad {
    Coord x,y,z; float w;
};

struct __declspec(align(16)) VelocityScratch {float x; Coord y,z; float w;};

struct __declspec(align(16)) Quaternion {
    Coord x,y,z; float w;

    void FUN_008d3290(const Quaternion* left, const void* right);
    float FUN_008db810() const;
};

class Motion {
public:
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2c();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3c();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4c();
    virtual void ApplyImpulse(const Quad* impulse);
};

struct Body {
    unsigned int unknown000;
    unsigned int unknown004;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    unsigned int unknown018;
    unsigned int unknown01c;
    unsigned int unknown020;
    unsigned int unknown024;
    unsigned int unknown028;
    unsigned int unknown02c;
    unsigned int unknown030;
    unsigned int unknown034;
    unsigned int unknown038;
    unsigned int unknown03c;
    unsigned int unknown040;
    unsigned int unknown044;
    unsigned int unknown048;
    unsigned int unknown04c;
    unsigned int unknown050;
    unsigned int unknown054;
    unsigned int unknown058;
    unsigned int unknown05c;
    unsigned int unknown060;
    unsigned int unknown064;
    unsigned int unknown068;
    unsigned int unknown06c;
    unsigned int unknown070;
    unsigned int unknown074;
    unsigned int unknown078;
    unsigned int unknown07c;
    unsigned int unknown080;
    unsigned int unknown084;
    unsigned int unknown088;
    unsigned int unknown08c;
    unsigned int unknown090;
    unsigned int unknown094;
    unsigned int unknown098;
    unsigned int unknown09c;
    unsigned int unknown0a0;
    unsigned int unknown0a4;
    unsigned int unknown0a8;
    unsigned int unknown0ac;
    unsigned int unknown0b0;
    unsigned int unknown0b4;
    unsigned int unknown0b8;
    unsigned int unknown0bc;
    unsigned int unknown0c0;
    unsigned int unknown0c4;
    unsigned int unknown0c8;
    unsigned int unknown0cc;
    Motion motion;
    unsigned int unknown0d4;
    unsigned int unknown0d8;
    unsigned int unknown0dc;
    unsigned int unknown0e0;
    unsigned int unknown0e4;
    unsigned int unknown0e8;
    unsigned int unknown0ec;
    unsigned int unknown0f0;
    unsigned int unknown0f4;
    unsigned int unknown0f8;
    unsigned int unknown0fc;
    unsigned int unknown100;
    unsigned int unknown104;
    unsigned int unknown108;
    unsigned int unknown10c;
    unsigned int unknown110;
    unsigned int unknown114;
    unsigned int unknown118;
    unsigned int unknown11c;
    unsigned int unknown120;
    unsigned int unknown124;
    unsigned int unknown128;
    unsigned int unknown12c;
    unsigned int unknown130;
    unsigned int unknown134;
    unsigned int unknown138;
    unsigned int unknown13c;
    unsigned int unknown140;
    unsigned int unknown144;
    unsigned int unknown148;
    unsigned int unknown14c;
    Quaternion orientation;
    unsigned int unknown160;
    unsigned int unknown164;
    unsigned int unknown168;
    unsigned int unknown16c;
    unsigned int unknown170;
    unsigned int unknown174;
    unsigned int unknown178;
    unsigned int unknown17c;
    unsigned int unknown180;
    unsigned int unknown184;
    unsigned int unknown188;
    unsigned int unknown18c;
    unsigned int unknown190;
    unsigned int unknown194;
    unsigned int unknown198;
    unsigned int unknown19c;
    unsigned int unknown1a0;
    unsigned int unknown1a4;
    unsigned int unknown1a8;
    unsigned int unknown1ac;
    Quad angularVelocity;

    void FUN_0090b500();
};

struct Input {
    unsigned int unknown00, unknown04;
    float stepTime;
};

struct Action {
    unsigned int unknown000;
    unsigned int unknown004;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    Body* bodyA;
    Body* bodyB;
    Quaternion rotation;
    float springStrength;
    float damping;

    void hkpAngularDashpotAction_applyAction(const Input& input);
};

// pdb: hkpAngularDashpotAction::applyAction | hkpAngularDashpotAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Action::hkpAngularDashpotAction_applyAction(const Input& input)
{
    float weight = static_cast<float>(input.stepTime * DAT_00db8b00);
    Body* a = bodyA;
    Body* b = bodyB;
    struct WorkVectors {Quad correction; VelocityScratch temporary; Quad impulse; Quaternion product;} work;
    work.product.FUN_008d3290(&b->orientation, &rotation);
    work.temporary.x = -work.product.x;
    work.temporary.y = -work.product.y;
    work.temporary.z = -work.product.z;
    work.temporary.w = work.product.w;
    work.product.FUN_008d3290(&a->orientation, &work.temporary);

    work.temporary.x = a->angularVelocity.x - b->angularVelocity.x;
    work.temporary.y = a->angularVelocity.y - b->angularVelocity.y;
    work.temporary.z = a->angularVelocity.z - b->angularVelocity.z;
    work.temporary.w = a->angularVelocity.w - b->angularVelocity.w;

    const float angle = work.product.FUN_008db810();
    work.correction.x = work.correction.y = work.correction.z = work.correction.w = 0.0f;
    const float magnitude = static_cast<float>(fabs(angle));
    if (magnitude > 0.001f) {
        work.correction.x = work.product.x * angle;
        work.correction.y = work.product.y * angle;
        work.correction.z = work.product.z * angle;
        work.correction.w = work.product.w * angle;
    }

    const float springWeight = weight * springStrength;
    work.correction.x *= springWeight;
    work.correction.y *= springWeight;
    work.correction.z *= springWeight;
    work.correction.w *= springWeight;
    const float dampingWeight = weight * damping;
    work.temporary.x *= dampingWeight;
    work.temporary.y *= dampingWeight;
    work.temporary.z *= dampingWeight;
    work.temporary.w *= dampingWeight;

    work.impulse.x = work.correction.x + work.temporary.x;
    work.impulse.y = work.correction.y + work.temporary.y;
    work.impulse.z = work.correction.z + work.temporary.z;
    work.impulse.w = work.correction.w + work.temporary.w;
    b->FUN_0090b500();
    b->motion.ApplyImpulse(&work.impulse);
    work.impulse.x = -work.impulse.x;
    work.impulse.y = -work.impulse.y;
    work.impulse.z = -work.impulse.z;
    work.impulse.w = -work.impulse.w;
    a->FUN_0090b500();
    a->motion.ApplyImpulse(&work.impulse);
}

}


}   // namespace f3m_009da980

// @f3 0x009cb070 (community match, verified in this file)
namespace f3m_009cb070 {
namespace ns_9cb070 {
struct hkReferencedObject
{
    virtual void destroy(int flags);
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    void removeReference()
    {
        if (m_memSizeAndFlags != 0)
        {
            --m_referenceCount;
            if (m_referenceCount == 0)
                destroy(1);
        }
    }
};
struct Holder
{
    hkReferencedObject* m_object;
};
// pdb: convertCylinderCacheToCapsuleCache | hkpPredGskCylinderAgent3.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: restoreOriginalShapesInCdBodies)
static __declspec(noinline) void FUN_009cb070(Holder*** slots, Holder** replacements)
{
    for (int i = 0; i < 2; ++i)
    {
        if (replacements[i])
        {
            (*slots[i])->m_object->removeReference();
            *slots[i] = replacements[i];
        }
    }
}
volatile int g_in_9cb070;
void caller_of_FUN_009cb070()
{
    FUN_009cb070((Holder***)g_in_9cb070, (Holder**)g_in_9cb070);
}
}
}   // namespace f3m_009cb070

// @f3 0x009c7ed0 (community match, verified in this file)
namespace f3m_009c7ed0 {
namespace f3m_009c7ed0 {

struct hkSimdReal
{
    float m_real;
    __forceinline hkSimdReal(const float& x) { m_real = x; }
    __forceinline operator float() const { return m_real; }
};

struct __declspec(align(16)) hkQuadReal
{
    float v[4];
};

struct __declspec(align(16)) hkVector4
{
    hkQuadReal m_quad;

    __forceinline hkSimdReal getSimdAt(int i) const { hkQuadReal q; q.v[i] = m_quad.v[i]; return q.v[i]; }
    __forceinline void addMul4(hkSimdReal r, const hkVector4& a)
    {
        m_quad.v[0] += r * a.m_quad.v[0];
        m_quad.v[1] += r * a.m_quad.v[1];
        m_quad.v[2] += r * a.m_quad.v[2];
        m_quad.v[3] += r * a.m_quad.v[3];
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        m_quad.v[0] = -v.m_quad.v[0];
        m_quad.v[1] = -v.m_quad.v[1];
        m_quad.v[2] = -v.m_quad.v[2];
        m_quad.v[3] = v.m_quad.v[3];
    }
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;

    __forceinline hkSimdReal getDistanceSimdReal() const { return m_separatingNormal.getSimdAt(3); }
    __forceinline void flip()
    {
        m_position.addMul4(getDistanceSimdReal(), m_separatingNormal);
        m_separatingNormal.setNeg3(m_separatingNormal);
    }
};

struct __declspec(align(16)) hkpProcessCdPoint
{
    hkContactPoint m_contact;
    unsigned int m_contactPointId;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
};

struct hkpGskCache
{
    unsigned short m_vertices[4];
    unsigned char m_dimA;
    unsigned char m_dimB;
    unsigned char m_maxDimA : 4;
    unsigned char m_maxDimB : 4;
    unsigned char unk0b;

    __forceinline void flip()
    {
        unsigned char t = m_maxDimA;
        m_maxDimA = m_maxDimB;
        m_maxDimB = t;
        unsigned char t2 = m_dimA;
        m_dimA = m_dimB;
        m_dimB = t2;
        int n = m_dimA + m_dimB - 1;
        unsigned short v0 = m_vertices[0];
        m_vertices[0] = m_vertices[n];
        m_vertices[n] = v0;
        if ((m_dimA & m_dimB) == 2)
        {
            unsigned short v1 = m_vertices[1];
            m_vertices[1] = m_vertices[2];
            m_vertices[2] = v1;
        }
    }
};

struct __declspec(align(16)) hkpToiInfo
{
    hkContactPoint m_contact;
    float m_time;
    float m_seperatingVelocity;
    unsigned int unk08;
    unsigned int unk0c;
    hkpGskCache m_gskCache;

    __forceinline void flip()
    {
        m_contact.m_separatingNormal.m_quad.v[0] = -m_contact.m_separatingNormal.m_quad.v[0];
        m_contact.m_separatingNormal.m_quad.v[1] = -m_contact.m_separatingNormal.m_quad.v[1];
        m_contact.m_separatingNormal.m_quad.v[2] = -m_contact.m_separatingNormal.m_quad.v[2];
        m_gskCache.flip();
    }
};

struct __declspec(align(16)) hkpProcessCollisionOutput
{
    hkpProcessCdPoint* m_firstFreeContactPoint;
    hkpProcessCdPoint m_contactPoints[256];
    hkpToiInfo m_toi;
};

}

using namespace f3m_009c7ed0;

struct hkpSymmetricAgentStandIn
{
    void hkpSphereTriangleAgent_processCollision(const void* bodyA, const void* bodyB, const void* input, hkpProcessCollisionOutput* result);
    void FUN_009c7ed0(const void* bodyA, const void* bodyB, const void* input, hkpProcessCollisionOutput* result);
};

// pdb: hkpSymmetricAgentLinearCast<hkpSphereTriangleAgent>::processCollision | hkpSphereTriangleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void hkpSymmetricAgentStandIn::FUN_009c7ed0(const void* bodyA, const void* bodyB, const void* input,
                                            hkpProcessCollisionOutput* result)
{
    hkpProcessCdPoint* p = result->m_firstFreeContactPoint;
    float toi = result->m_toi.m_time;
    hkpSphereTriangleAgent_processCollision(bodyB, bodyA, input, result);
    for (; p < result->m_firstFreeContactPoint; p++)
    {
        p->m_contact.flip();
    }
    if (toi != result->m_toi.m_time)
    {
        result->m_toi.flip();
    }
}
}   // namespace f3m_009c7ed0

// @f3 0x009ddd20 (community match, verified in this file)
namespace f3m_009ddd20 {
namespace Copy1043 {
struct Vec4 {
    float x, y, z, w;
    Vec4& operator=(const Vec4& b) { x=b.x; y=b.y; z=b.z; w=b.w; return *this; }
};
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Vec4* values;
    void FUN_009ddd20(int start, int count, const Vec4* source);
};
void Owner::FUN_009ddd20(int start, int count, const Vec4* source) {
    int end = start + count;
    for (int i = start; i < end; ++i)
    {
        values[i] = *source;
        ++source;
    }
}
}
}   // namespace f3m_009ddd20

// @f3 0x009daca0 (community match, verified in this file)
extern int DAT_00e7a84c;
extern const float DAT_00db8ea4;
namespace f3m_009daca0 {
namespace Build330 {
struct Flag330 { unsigned char value; Flag330(unsigned char v) : value(v) {} Flag330(const Flag330& rhs) : value(rhs.value) {} };
struct Bounds330 { unsigned short first; unsigned short unk02; unsigned short second; unsigned short unk06; };
struct Parent330 { virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc(); virtual void v10(); virtual void NiGeometryData_GetNormalsIterator(Flag330, Bounds330*); unsigned short memory; short refs; };
struct Handle330 { unsigned short marker; unsigned short unk02; unsigned int unk04; unsigned int unk08; void hkpBridgeConstraintAtom_init(void*); };
struct Owner330 { void* vtable; unsigned short memory; short refs; unsigned int unk08; Handle330 handle; Parent330* parent; unsigned short first; unsigned short second; float value; unsigned char flag24; unsigned char flag25; unsigned char unk26; unsigned char unk27; unsigned int unk28; Owner330* FUN_009daca0(Parent330* input); };
// pdb: hkpBreakableConstraintData::hkpBreakableConstraintData | hkpBreakableConstraintData.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: constraintData
Owner330* Owner330::FUN_009daca0(Parent330* input) { Parent330* supplied = input; (void)static_cast<Parent330* const volatile&>(input); const double threshold = static_cast<const volatile float&>(DAT_00db8ea4); refs=1; unk08=0; vtable=&DAT_00e7a84c; unsigned short* marker=&handle.marker; static_cast<volatile unsigned short&>(*marker)=1; static_cast<volatile float&>(value)=static_cast<float>(threshold); parent=supplied; flag24=0; unk28=0; static_cast<volatile unsigned char&>(flag25)=0; Parent330* child=static_cast<Parent330* const volatile&>(parent); if(child->memory) ++child->refs; Bounds330 bounds; Bounds330* boundsPtr=&bounds; parent->NiGeometryData_GetNormalsIterator(Flag330(1), boundsPtr); first=bounds.first; second=bounds.second; handle.hkpBridgeConstraintAtom_init(this); return this; }
}
}   // namespace f3m_009daca0

// @f3 0x009d78c0 (community match, verified in this file)
extern void* DAT_00e80090[];
namespace f3m_009d78c0 {
struct CleanupObject9d78c0 {
 void** table;
 void FUN_00a4ab20();
 void FUN_009d78c0();
};
// pdb: hkBinaryPackfileWriter::~hkBinaryPackfileWriter | hkBinaryPackfileWriter.obj | fnv360_0822_retail, objrun, medium
void CleanupObject9d78c0::FUN_009d78c0(){table=DAT_00e80090;FUN_00a4ab20();}
}   // namespace f3m_009d78c0

// @f3 0x009d30d0 (community match, verified in this file)
namespace f3m_009d30d0 {
struct __declspec(align(16)) Slot7SimdReal
{
    float m_real;
    Slot7SimdReal(const float& r) : m_real(r) {}
    operator float() const { return m_real; }
};
struct __declspec(align(16)) Slot7Vector4
{
    float x, y, z, w;
    Slot7SimdReal getSimdAt3() const { return Slot7SimdReal(w); }
    void addMul4(const Slot7Vector4& a, float r)
    {
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    void setNeg3(const Slot7Vector4& v) { x = -v.x; y = -v.y; z = -v.z; w = v.w; }
};
struct Slot7ContactPoint
{
    Slot7Vector4 m_position;
    Slot7Vector4 m_separatingNormal;
    void flip()
    {
        m_position.addMul4(m_separatingNormal, m_separatingNormal.getSimdAt3());
        m_separatingNormal.setNeg3(m_separatingNormal);
    }
};
struct Slot7RootCdPoint
{
    Slot7ContactPoint m_contact;
    int unk20, unk24, unk28, unk2c;
};
struct Slot7Tail
{
    Slot7Vector4 m_normal;
    float m_distance;
    int unk14, unk18, unk1c;
    unsigned short features[4];
    unsigned char countA, countB;
    unsigned char packedLow : 4;
    unsigned char packedHigh : 4;
};
struct Slot7Collector
{
    Slot7RootCdPoint* end;
    int unk04, unk08, unk0c;
    Slot7RootCdPoint points[256];
    int unk3010, unk3014, unk3018, unk301c;
    Slot7Tail tail;
};
struct Slot7Agent
{
    void hkpMultiSphereAgent_processCollision(void* a, void* b, void* c, Slot7Collector* collector);
    void FUN_009d30d0(void* a, void* b, void* c, Slot7Collector* collector);
};
// pdb: hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::processCollision | hkpMultiSphereAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void Slot7Agent::FUN_009d30d0(void* a, void* b, void* c, Slot7Collector* collector)
{
    Slot7RootCdPoint* current = collector->end;
    float previous = collector->tail.m_distance;
    hkpMultiSphereAgent_processCollision(b, a, c, collector);
    while (current < collector->end)
    {
        current->m_contact.flip();
        ++current;
    }
    Slot7Tail& tail = collector->tail;
    if (previous != tail.m_distance)
    {
        Slot7Vector4& n = tail.m_normal;
        n.x = -n.x;
        n.y = -n.y;
        n.z = -n.z;
        {
            unsigned char t = collector->tail.packedLow;
            collector->tail.packedLow = collector->tail.packedHigh;
            collector->tail.packedHigh = t;
        }
        {
            unsigned char t = collector->tail.countA;
            collector->tail.countA = collector->tail.countB;
            collector->tail.countB = t;
        }
        int last = collector->tail.countA + collector->tail.countB - 1;
        unsigned short f = collector->tail.features[0];
        collector->tail.features[0] = collector->tail.features[last];
        collector->tail.features[last] = f;
        if ((collector->tail.countA & collector->tail.countB) == 2)
        {
            unsigned short s = collector->tail.features[1];
            collector->tail.features[1] = collector->tail.features[2];
            collector->tail.features[2] = s;
        }
    }
}
}   // namespace f3m_009d30d0

// @f3 0x009c1fd0 (community match, verified in this file)
namespace f3m_009c1fd0 {
struct __declspec(align(16)) Slot7SimdReal
{
    float m_real;
    Slot7SimdReal(const float& r) : m_real(r) {}
    operator float() const { return m_real; }
};
struct __declspec(align(16)) Slot7Vector4
{
    float x, y, z, w;
    Slot7SimdReal getSimdAt3() const { return Slot7SimdReal(w); }
    void addMul4(const Slot7Vector4& a, float r)
    {
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    void setNeg3(const Slot7Vector4& v) { x = -v.x; y = -v.y; z = -v.z; w = v.w; }
};
struct Slot7ContactPoint
{
    Slot7Vector4 m_position;
    Slot7Vector4 m_separatingNormal;
    void flip()
    {
        m_position.addMul4(m_separatingNormal, m_separatingNormal.getSimdAt3());
        m_separatingNormal.setNeg3(m_separatingNormal);
    }
};
struct Slot7RootCdPoint
{
    Slot7ContactPoint m_contact;
    int unk20, unk24, unk28, unk2c;
};
struct Slot7Tail
{
    Slot7Vector4 m_normal;
    float m_distance;
    int unk14, unk18, unk1c;
    unsigned short features[4];
    unsigned char countA, countB;
    unsigned char packedLow : 4;
    unsigned char packedHigh : 4;
};
struct Slot7Collector
{
    Slot7RootCdPoint* end;
    int unk04, unk08, unk0c;
    Slot7RootCdPoint points[256];
    int unk3010, unk3014, unk3018, unk301c;
    Slot7Tail tail;
};
struct Slot7Agent
{
    void hkpMultiSphereTriangleAgent_processCollision(void* a, void* b, void* c, Slot7Collector* collector);
    void FUN_009c1fd0(void* a, void* b, void* c, Slot7Collector* collector);
};
// pdb: hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::processCollision | hkpMultiSphereTriangleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void Slot7Agent::FUN_009c1fd0(void* a, void* b, void* c, Slot7Collector* collector)
{
    Slot7RootCdPoint* current = collector->end;
    float previous = collector->tail.m_distance;
    hkpMultiSphereTriangleAgent_processCollision(b, a, c, collector);
    while (current < collector->end)
    {
        current->m_contact.flip();
        ++current;
    }
    Slot7Tail& tail = collector->tail;
    if (previous != tail.m_distance)
    {
        Slot7Vector4& n = tail.m_normal;
        n.x = -n.x;
        n.y = -n.y;
        n.z = -n.z;
        {
            unsigned char t = collector->tail.packedLow;
            collector->tail.packedLow = collector->tail.packedHigh;
            collector->tail.packedHigh = t;
        }
        {
            unsigned char t = collector->tail.countA;
            collector->tail.countA = collector->tail.countB;
            collector->tail.countB = t;
        }
        int last = collector->tail.countA + collector->tail.countB - 1;
        unsigned short f = collector->tail.features[0];
        collector->tail.features[0] = collector->tail.features[last];
        collector->tail.features[last] = f;
        if ((collector->tail.countA & collector->tail.countB) == 2)
        {
            unsigned short s = collector->tail.features[1];
            collector->tail.features[1] = collector->tail.features[2];
            collector->tail.features[2] = s;
        }
    }
}
}   // namespace f3m_009c1fd0

// @f3 0x009d4380 (community match, verified in this file)
namespace f3m_009d4380 {
struct __declspec(align(16)) Slot7SimdReal
{
    float m_real;
    Slot7SimdReal(const float& r) : m_real(r) {}
    operator float() const { return m_real; }
};
struct __declspec(align(16)) Slot7Vector4
{
    float x, y, z, w;
    Slot7SimdReal getSimdAt3() const { return Slot7SimdReal(w); }
    void addMul4(const Slot7Vector4& a, float r)
    {
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    void setNeg3(const Slot7Vector4& v) { x = -v.x; y = -v.y; z = -v.z; w = v.w; }
};
struct Slot7ContactPoint
{
    Slot7Vector4 m_position;
    Slot7Vector4 m_separatingNormal;
    void flip()
    {
        m_position.addMul4(m_separatingNormal, m_separatingNormal.getSimdAt3());
        m_separatingNormal.setNeg3(m_separatingNormal);
    }
};
struct Slot7RootCdPoint
{
    Slot7ContactPoint m_contact;
    int unk20, unk24, unk28, unk2c;
};
struct Slot7Tail
{
    Slot7Vector4 m_normal;
    float m_distance;
    int unk14, unk18, unk1c;
    unsigned short features[4];
    unsigned char countA, countB;
    unsigned char packedLow : 4;
    unsigned char packedHigh : 4;
};
struct Slot7Collector
{
    Slot7RootCdPoint* end;
    int unk04, unk08, unk0c;
    Slot7RootCdPoint points[256];
    int unk3010, unk3014, unk3018, unk301c;
    Slot7Tail tail;
};
struct Slot7Agent
{
    void FUN_009d3610(void* a, void* b, void* c, Slot7Collector* collector);
    void FUN_009d4380(void* a, void* b, void* c, Slot7Collector* collector);
};
// pdb: hkpSymmetricAgentLinearCast<hkpBvAgent>::processCollision | hkpBvAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void Slot7Agent::FUN_009d4380(void* a, void* b, void* c, Slot7Collector* collector)
{
    Slot7RootCdPoint* current = collector->end;
    float previous = collector->tail.m_distance;
    FUN_009d3610(b, a, c, collector);
    while (current < collector->end)
    {
        current->m_contact.flip();
        ++current;
    }
    Slot7Tail& tail = collector->tail;
    if (previous != tail.m_distance)
    {
        Slot7Vector4& n = tail.m_normal;
        n.x = -n.x;
        n.y = -n.y;
        n.z = -n.z;
        {
            unsigned char t = collector->tail.packedLow;
            collector->tail.packedLow = collector->tail.packedHigh;
            collector->tail.packedHigh = t;
        }
        {
            unsigned char t = collector->tail.countA;
            collector->tail.countA = collector->tail.countB;
            collector->tail.countB = t;
        }
        int last = collector->tail.countA + collector->tail.countB - 1;
        unsigned short f = collector->tail.features[0];
        collector->tail.features[0] = collector->tail.features[last];
        collector->tail.features[last] = f;
        if ((collector->tail.countA & collector->tail.countB) == 2)
        {
            unsigned short s = collector->tail.features[1];
            collector->tail.features[1] = collector->tail.features[2];
            collector->tail.features[2] = s;
        }
    }
}
}   // namespace f3m_009d4380

// @f3 0x009c45e0 (community match, verified in this file)
namespace f3m_009c45e0 {
struct __declspec(align(16)) Slot7SimdReal
{
    float m_real;
    Slot7SimdReal(const float& r) : m_real(r) {}
    operator float() const { return m_real; }
};
struct __declspec(align(16)) Slot7Vector4
{
    float x, y, z, w;
    Slot7SimdReal getSimdAt3() const { return Slot7SimdReal(w); }
    void addMul4(const Slot7Vector4& a, float r)
    {
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    void setNeg3(const Slot7Vector4& v) { x = -v.x; y = -v.y; z = -v.z; w = v.w; }
};
struct Slot7ContactPoint
{
    Slot7Vector4 m_position;
    Slot7Vector4 m_separatingNormal;
    void flip()
    {
        m_position.addMul4(m_separatingNormal, m_separatingNormal.getSimdAt3());
        m_separatingNormal.setNeg3(m_separatingNormal);
    }
};
struct Slot7RootCdPoint
{
    Slot7ContactPoint m_contact;
    int unk20, unk24, unk28, unk2c;
};
struct Slot7Tail
{
    Slot7Vector4 m_normal;
    float m_distance;
    int unk14, unk18, unk1c;
    unsigned short features[4];
    unsigned char countA, countB;
    unsigned char packedLow : 4;
    unsigned char packedHigh : 4;
};
struct Slot7Collector
{
    Slot7RootCdPoint* end;
    int unk04, unk08, unk0c;
    Slot7RootCdPoint points[256];
    int unk3010, unk3014, unk3018, unk301c;
    Slot7Tail tail;
};
struct Slot7Agent
{
    void hkpCapsuleTriangleAgent_processCollision(void* a, void* b, void* c, Slot7Collector* collector);
    void FUN_009c45e0(void* a, void* b, void* c, Slot7Collector* collector);
};
// pdb: hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::processCollision | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void Slot7Agent::FUN_009c45e0(void* a, void* b, void* c, Slot7Collector* collector)
{
    Slot7RootCdPoint* current = collector->end;
    float previous = collector->tail.m_distance;
    hkpCapsuleTriangleAgent_processCollision(b, a, c, collector);
    while (current < collector->end)
    {
        current->m_contact.flip();
        ++current;
    }
    Slot7Tail& tail = collector->tail;
    if (previous != tail.m_distance)
    {
        Slot7Vector4& n = tail.m_normal;
        n.x = -n.x;
        n.y = -n.y;
        n.z = -n.z;
        {
            unsigned char t = collector->tail.packedLow;
            collector->tail.packedLow = collector->tail.packedHigh;
            collector->tail.packedHigh = t;
        }
        {
            unsigned char t = collector->tail.countA;
            collector->tail.countA = collector->tail.countB;
            collector->tail.countB = t;
        }
        int last = collector->tail.countA + collector->tail.countB - 1;
        unsigned short f = collector->tail.features[0];
        collector->tail.features[0] = collector->tail.features[last];
        collector->tail.features[last] = f;
        if ((collector->tail.countA & collector->tail.countB) == 2)
        {
            unsigned short s = collector->tail.features[1];
            collector->tail.features[1] = collector->tail.features[2];
            collector->tail.features[2] = s;
        }
    }
}
}   // namespace f3m_009c45e0

// @f3 0x009c6d80 (community match, verified in this file)
namespace f3m_009c6d80 {
struct __declspec(align(16)) Slot7SimdReal
{
    float m_real;
    Slot7SimdReal(const float& r) : m_real(r) {}
    operator float() const { return m_real; }
};
struct __declspec(align(16)) Slot7Vector4
{
    float x, y, z, w;
    Slot7SimdReal getSimdAt3() const { return Slot7SimdReal(w); }
    void addMul4(const Slot7Vector4& a, float r)
    {
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    void setNeg3(const Slot7Vector4& v) { x = -v.x; y = -v.y; z = -v.z; w = v.w; }
};
struct Slot7ContactPoint
{
    Slot7Vector4 m_position;
    Slot7Vector4 m_separatingNormal;
    void flip()
    {
        m_position.addMul4(m_separatingNormal, m_separatingNormal.getSimdAt3());
        m_separatingNormal.setNeg3(m_separatingNormal);
    }
};
struct Slot7RootCdPoint
{
    Slot7ContactPoint m_contact;
    int unk20, unk24, unk28, unk2c;
};
struct Slot7Tail
{
    Slot7Vector4 m_normal;
    float m_distance;
    int unk14, unk18, unk1c;
    unsigned short features[4];
    unsigned char countA, countB;
    unsigned char packedLow : 4;
    unsigned char packedHigh : 4;
};
struct Slot7Collector
{
    Slot7RootCdPoint* end;
    int unk04, unk08, unk0c;
    Slot7RootCdPoint points[256];
    int unk3010, unk3014, unk3018, unk301c;
    Slot7Tail tail;
};
struct Slot7Agent
{
    void hkpSphereBoxAgent_processCollision(void* a, void* b, void* c, Slot7Collector* collector);
    void FUN_009c6d80(void* a, void* b, void* c, Slot7Collector* collector);
};
// pdb: hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::processCollision | hkpSphereBoxAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void Slot7Agent::FUN_009c6d80(void* a, void* b, void* c, Slot7Collector* collector)
{
    Slot7RootCdPoint* current = collector->end;
    float previous = collector->tail.m_distance;
    hkpSphereBoxAgent_processCollision(b, a, c, collector);
    while (current < collector->end)
    {
        current->m_contact.flip();
        ++current;
    }
    Slot7Tail& tail = collector->tail;
    if (previous != tail.m_distance)
    {
        Slot7Vector4& n = tail.m_normal;
        n.x = -n.x;
        n.y = -n.y;
        n.z = -n.z;
        {
            unsigned char t = collector->tail.packedLow;
            collector->tail.packedLow = collector->tail.packedHigh;
            collector->tail.packedHigh = t;
        }
        {
            unsigned char t = collector->tail.countA;
            collector->tail.countA = collector->tail.countB;
            collector->tail.countB = t;
        }
        int last = collector->tail.countA + collector->tail.countB - 1;
        unsigned short f = collector->tail.features[0];
        collector->tail.features[0] = collector->tail.features[last];
        collector->tail.features[last] = f;
        if ((collector->tail.countA & collector->tail.countB) == 2)
        {
            unsigned short s = collector->tail.features[1];
            collector->tail.features[1] = collector->tail.features[2];
            collector->tail.features[2] = s;
        }
    }
}
}   // namespace f3m_009c6d80

// @f3 0x009c9640 (community match, verified in this file)
namespace f3m_009c9640 {
struct __declspec(align(16)) Slot7SimdReal
{
    float m_real;
    Slot7SimdReal(const float& r) : m_real(r) {}
    operator float() const { return m_real; }
};
struct __declspec(align(16)) Slot7Vector4
{
    float x, y, z, w;
    Slot7SimdReal getSimdAt3() const { return Slot7SimdReal(w); }
    void addMul4(const Slot7Vector4& a, float r)
    {
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    void setNeg3(const Slot7Vector4& v) { x = -v.x; y = -v.y; z = -v.z; w = v.w; }
};
struct Slot7ContactPoint
{
    Slot7Vector4 m_position;
    Slot7Vector4 m_separatingNormal;
    void flip()
    {
        m_position.addMul4(m_separatingNormal, m_separatingNormal.getSimdAt3());
        m_separatingNormal.setNeg3(m_separatingNormal);
    }
};
struct Slot7RootCdPoint
{
    Slot7ContactPoint m_contact;
    int unk20, unk24, unk28, unk2c;
};
struct Slot7Tail
{
    Slot7Vector4 m_normal;
    float m_distance;
    int unk14, unk18, unk1c;
    unsigned short features[4];
    unsigned char countA, countB;
    unsigned char packedLow : 4;
    unsigned char packedHigh : 4;
};
struct Slot7Collector
{
    Slot7RootCdPoint* end;
    int unk04, unk08, unk0c;
    Slot7RootCdPoint points[256];
    int unk3010, unk3014, unk3018, unk301c;
    Slot7Tail tail;
};
struct Slot7Agent
{
    void hkpSphereCapsuleAgent_processCollision(void* a, void* b, void* c, Slot7Collector* collector);
    void FUN_009c9640(void* a, void* b, void* c, Slot7Collector* collector);
};
// pdb: hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::processCollision | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, result
void Slot7Agent::FUN_009c9640(void* a, void* b, void* c, Slot7Collector* collector)
{
    Slot7RootCdPoint* current = collector->end;
    float previous = collector->tail.m_distance;
    hkpSphereCapsuleAgent_processCollision(b, a, c, collector);
    while (current < collector->end)
    {
        current->m_contact.flip();
        ++current;
    }
    Slot7Tail& tail = collector->tail;
    if (previous != tail.m_distance)
    {
        Slot7Vector4& n = tail.m_normal;
        n.x = -n.x;
        n.y = -n.y;
        n.z = -n.z;
        {
            unsigned char t = collector->tail.packedLow;
            collector->tail.packedLow = collector->tail.packedHigh;
            collector->tail.packedHigh = t;
        }
        {
            unsigned char t = collector->tail.countA;
            collector->tail.countA = collector->tail.countB;
            collector->tail.countB = t;
        }
        int last = collector->tail.countA + collector->tail.countB - 1;
        unsigned short f = collector->tail.features[0];
        collector->tail.features[0] = collector->tail.features[last];
        collector->tail.features[last] = f;
        if ((collector->tail.countA & collector->tail.countB) == 2)
        {
            unsigned short s = collector->tail.features[1];
            collector->tail.features[1] = collector->tail.features[2];
            collector->tail.features[2] = s;
        }
    }
}
}   // namespace f3m_009c9640

// @f3 0x009c0a30 (community match, verified in this file)
namespace f3m_009c0a30 {
// 0x009c0a30: hkpMultiSphereTriangleAgent::getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpCollisionInput& input, hkpCdBodyPairCollector& collector) of Havok 5.5.0 (hkpCollide, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Transforms the triangle's vertices and the multi sphere's centres to world space and reports the body pair to
// the collector as soon as one sphere is closer to the triangle than the two radii together. The triangle's
// cache for the closest-point query is the agent's own member.
// Class and member names follow the Havok 5.5.0 SDK headers; the vector and transform helpers follow the forms
// of the SDK's inline maths for the x87 build.
namespace f3m_009c0a30 {

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    inline void operator=(const hkVector4& v);
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

inline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

struct hkMatrix3
{
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline const hkReal& operator()(int row, int column) const { return m_rotation(row, column); }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

// the translation is the rotation's fourth column
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
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

namespace hkVector4Util {
// transforms numVectors points, the last one first; the transform is copied so that the output may alias it
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                   hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

struct hkpShape
{
    virtual ~hkpShape();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpTriangleShape : hkpShape
{
    hkReal getRadius() const { return m_radius; }
    const hkVector4* getVertices() const { return &m_vertexA; }

    hkReal m_radius;
    hkUint16 m_weldingInfo;
    unsigned char m_weldingType;
    unsigned char m_isExtruded;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

struct hkpMultiSphereShape : hkpShape
{
    int getNumSpheres() const { return m_numSpheres; }
    const hkVector4* getSpheres() const { return &m_spheres[0]; }

    int m_numSpheres;
    hkVector4 m_spheres[8];
};

struct hkpCdBody
{
    const hkpShape* getShape() const { return m_shape; }
    const hkTransform& getTransform() const { return *(const hkTransform*)m_motion; }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionInput;

struct hkpCdBodyPairCollector
{
    virtual ~hkpCdBodyPairCollector();
    virtual void addCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
};

namespace hkpCollideTriangleUtil {
struct ClosestPointTriangleCache
{
    hkReal m_QQ;
    hkReal m_RR;
    hkReal m_QR;
    hkReal m_invTriNormal;
};

struct ClosestPointTriangleResult
{
    hkVector4 hitDirection;
    hkReal distance;
};

// closestPointTriangle
void __cdecl hkpCollideTriangleUtil_closestPointTriangle(const hkVector4& position, const hkVector4* triangle, const ClosestPointTriangleCache& cache,
                          ClosestPointTriangleResult& result);
}  // namespace hkpCollideTriangleUtil

struct hkpContactMgr;

struct hkpMultiSphereTriangleAgent
{
    virtual ~hkpMultiSphereTriangleAgent();

    void hkpMultiSphereTriangleAgent_getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
                      hkpCdBodyPairCollector& collector);

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    hkpContactMgr* m_contactMgr;
    hkpCollideTriangleUtil::ClosestPointTriangleCache m_closestPointTriangleCache;
};

// pdb: hkpMultiSphereTriangleAgent::getPenetrations | hkpMultiSphereTriangleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpMultiSphereTriangleAgent::hkpMultiSphereTriangleAgent_getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                               const hkpCollisionInput& input, hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());
    hkVector4 triVertices[3];
    const hkVector4* vertices = triB->getVertices();
    hkVector4Util::transformPoints(bodyB.getTransform(), vertices, 3, &triVertices[0]);

    const hkVector4* localSpheres = msA->getSpheres();
    hkVector4 worldSpheres[8];
    const int nsphere = msA->getNumSpheres();
    hkVector4Util::transformPoints(bodyA.getTransform(), localSpheres, nsphere, &worldSpheres[0]);

    for (int i = 0; i < nsphere; ++i)
    {
        hkReal radiusSum = localSpheres[i](3);
        radiusSum += triB->getRadius();
        hkpCollideTriangleUtil::ClosestPointTriangleResult cpr;
        hkpCollideTriangleUtil::hkpCollideTriangleUtil_closestPointTriangle(worldSpheres[i], &triVertices[0], m_closestPointTriangleCache, cpr);
        if (cpr.distance < radiusSum)
        {
            collector.addCdBodyPair(bodyA, bodyB);
            break;
        }
    }
}

}  // namespace f3m_009c0a30
}   // namespace f3m_009c0a30

// @f3 0x009ca8f0 (community match, verified in this file)
namespace f3m_009ca8f0 {
// 0x009ca8f0: hkpBoxBoxAgent::staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpCollisionInput& input, hkpCdPointCollector& collector) of Havok 5.5.0 (hkpCollide, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Sets up a box-box detector for the two bodies (half extents grown by the shapes' radii, B's transform in A's
// space, the tolerance), asks it for the closest point and hands the point with the two bodies to the collector
// when there is one. A timer brackets it.
// Names follow the Havok 5.5.0 SDK headers where the SDK declares them (the contact point, the collector, the
// monitor stream, the shapes); the detector class is not in the SDK's headers, so its members are named from
// their use. The vector helpers follow the forms of the SDK's inline maths; the function's body is written from
// the game's code. The timer reads the clock with the project's accepted two-instruction block
// (kit/compiler_tips.md, "Timer slot still off"): with a plain counter read all code is equal and only stack slots
// differ (the result flag, the float slot the time stamps share, the contact event and the detector).
namespace f3m_009ca8f0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

extern unsigned int DAT_0116913c;  // thread-local slot of the thread's hkMonitorStream
extern const char DAT_00e7f370[];  // "TtBoxBox"

struct hkMonitorStream
{
    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
    };

    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    char* getEnd() { return m_end.val(); }
    char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    bool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
};

// one timer command in the thread's monitor stream: the name, then the low half of the time stamp counter
__forceinline void hkTimerCommand(const char* name)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* command = (hkMonitorStream::TimerCommand*)stream.getEnd();
        command->m_commandAndMonitor = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        command->m_time0 = ticks;
        stream.setEnd((char*)(command + 1));
    }
}

struct __declspec(align(16)) hkVector4
{
    void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    void setAll(hkReal a)
    {
        x = a;
        y = a;
        z = a;
        w = a;
    }
    void add4(const hkVector4& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }
    void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkTransform
{
    hkTransform() {}
    // setMulInverseMul: this = inverse(bTa) * bTc
    void FUN_00925300(const hkTransform& bTa, const hkTransform& bTc);
    // the four columns are copied out first and then assigned
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.m_rotation.m_col0;
        const hkVector4 col1 = t.m_rotation.m_col1;
        const hkVector4 col2 = t.m_rotation.m_col2;
        const hkVector4 col3 = t.m_translation;
        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkpShape
{
    virtual ~hkpShape();

    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

struct hkpBoxShape : hkpConvexShape
{
    const hkVector4& getHalfExtents() const { return m_halfExtents; }

    hkVector4 m_halfExtents;
};

struct hkpCdBody
{
    const hkpShape* getShape() const { return m_shape; }
    const hkTransform& getTransform() const { return *(const hkTransform*)m_motion; }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;
struct hkpContactMgr;
struct hkpProcessCollisionOutput;

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

// a contact point with the two bodies it belongs to
struct hkpCdPoint
{
    hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

struct hkpCdPointCollector
{
    virtual ~hkpCdPointCollector();
    virtual void addCdPoint(const hkpCdPoint& point) = 0;

    hkReal m_earlyOutDistance;
};

struct hkpCollisionInput
{
    hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

// the box-box detector: the two bodies, their world transforms, B's transform in A's space, the half extents
// with the radii added, the tolerance in the forms the detector works with
struct hkpBoxBoxCollisionDetection
{
    __forceinline hkpBoxBoxCollisionDetection(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                              const hkpCollisionInput* env,
                                hkpContactMgr* mgr, hkpProcessCollisionOutput* result, const hkTransform& aTb,
                                const hkTransform& wTa, const hkVector4& radiusA, const hkTransform& wTb,
                                const hkVector4& radiusB, hkReal tolerance)
        : m_bodyA(&bodyA), m_bodyB(&bodyB), m_env(env), m_contactMgr(mgr), m_result(result), m_wTa(&wTa), m_wTb(&wTb),
          m_aTb(aTb), m_radiusA(radiusA), m_radiusB(radiusB)
    {
        m_tolerance = tolerance;
        m_boundaryTolerance = 0.01f;
        m_tolerance4.setAll(tolerance);
        m_keepRadiusA.setAdd4(radiusA, m_tolerance4);
        m_keepRadiusB.setAdd4(radiusB, m_tolerance4);
    }

    hkBool hkpBoxBoxCollisionDetection_calculateClosestPoint(hkContactPoint& contact) const;  // calculateClosestPoint

    const hkpCdBody* m_bodyA;
    const hkpCdBody* m_bodyB;
    const hkpCollisionInput* m_env;
    hkpContactMgr* m_contactMgr;
    hkpProcessCollisionOutput* m_result;
    const hkTransform* m_wTa;
    const hkTransform* m_wTb;
    hkTransform m_aTb;
    hkVector4 m_radiusA;
    hkVector4 m_radiusB;
    hkVector4 m_tolerance4;
    hkVector4 m_keepRadiusA;
    hkVector4 m_keepRadiusB;
    hkReal m_tolerance;
    hkReal m_boundaryTolerance;
    hkVector4 m_unkC0;
    hkVector4 m_unkD0;
    hkVector4 m_unkE0;
    hkVector4 m_unkF0;
    hkVector4 m_unk100;
    hkVector4 m_unk110;
    hkVector4 m_unk120;
};

// pdb: hkpBoxBoxAgent::staticGetClosestPoints | hkpBoxBoxAgent.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkpBoxBoxAgent_staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
                          hkpCdPointCollector& collector)
{
    hkTimerCommand(DAT_00e7f370);

    const hkpBoxShape* boxA = static_cast<const hkpBoxShape*>(bodyA.getShape());
    const hkpBoxShape* boxB = static_cast<const hkpBoxShape*>(bodyB.getShape());

    // the boxes' half extents grown by their radii
    hkVector4 radiusA;
    radiusA.setAll(boxA->getRadius());
    radiusA.add4(boxA->getHalfExtents());

    hkVector4 radiusB;
    radiusB.setAll(boxB->getRadius());
    radiusB.add4(boxB->getHalfExtents());

    hkTransform aTb;
    aTb.FUN_00925300(bodyA.getTransform(), bodyB.getTransform());

    hkpBoxBoxCollisionDetection detector(bodyA, bodyB, 0, 0, 0, aTb, bodyA.getTransform(), radiusA,
                                         bodyB.getTransform(), radiusB, input.getTolerance());

    hkpCdPoint event(bodyA, bodyB);

    hkBool hasPoint = detector.hkpBoxBoxCollisionDetection_calculateClosestPoint(event.m_contact);
    if (hasPoint)
    {
        collector.addCdPoint(event);
    }

    hkTimerCommand("Et");
}

}  // namespace f3m_009ca8f0
}   // namespace f3m_009ca8f0

// @f3 0x009c6310 (community match, verified in this file)
#include <math.h>
namespace f3m_009c6310 {
// 0x009c6310: hkpSphereBoxAgent::getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpCollisionInput& input, hkpCdPointCollector& collector) of Havok 5.5.0 (hkpCollide, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Finds the closest point between sphere A and box B: the sphere's centre in the box's space is clipped to the
// half extents; outside the box the normal is the clipped difference, inside it the axis of the nearest face.
// When the distance is within the tolerance the point goes to the collector with the two bodies. A timer
// brackets it.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector helpers, the contact
// point's accessors, the timer command) follow the SDK's inline code for the x87 build. The body of the inline
// closest-point helper follows the unit's verified twin 0x009c6780 (the static form of the same query).
// The timer reads the clock with the project's accepted two-instruction block (kit/compiler_tips.md, "Timer slot
// still off"), as the SDK's own inline timer code does; it is the only difference from the plain counter-read
// source.

namespace f3m_009c6310 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

extern unsigned int DAT_0116913c;  // thread-local slot of the thread's hkMonitorStream

namespace hkMath {
__forceinline hkReal fabs(hkReal r) { return hkReal(::fabs(r)); }
__forceinline hkReal sqrt(hkReal r) { return hkReal(::sqrt(r)); }
}  // namespace hkMath

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

struct hkMonitorStream
{
    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
    };

    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    char* getEnd() { return m_end.val(); }
    char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    bool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
};

// one timer command in the thread's monitor stream: the name, then the low half of the time stamp counter
__forceinline void hkTimerCommand(const char* name)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* command = (hkMonitorStream::TimerCommand*)stream.getEnd();
        command->m_commandAndMonitor = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        command->m_time0 = ticks;
        stream.setEnd((char*)(command + 1));
    }
}

struct hkVector4Comparison
{
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_Y = 4,
        MASK_X = 8,
        MASK_XYZ = 14
    };

    __forceinline int anyIsSet(Mask m) const { return m_mask & m; }

    int m_mask;
};

struct hkMatrix3;
struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    // setTransformedInversePos: this = inverse(t) * v
    void FUN_008d2970(const hkTransform& t, const hkVector4& v);

    __forceinline void setAbs4(const hkVector4& v)
    {
        x = hkMath::fabs(v.x);
        y = hkMath::fabs(v.y);
        z = hkMath::fabs(v.z);
        w = hkMath::fabs(v.w);
    }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline hkVector4Comparison compareLessThanZero4() const
    {
        hkVector4Comparison ret;
        ret.m_mask = ((x < 0) ? hkVector4Comparison::MASK_X : 0) |
                     ((y < 0) ? hkVector4Comparison::MASK_Y : 0) |
                     ((z < 0) ? hkVector4Comparison::MASK_Z : 0) |
                     ((w < 0) ? hkVector4Comparison::MASK_W : 0);
        return ret;
    }
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return x * a.x + y * a.y + z * a.z; }
    __forceinline hkSimdReal length3() const { return hkMath::sqrt(dot3(*this)); }
    __forceinline void mul4(hkSimdRealParameter s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline hkSimdReal normalizeWithLength3()
    {
        hkReal len = length3();
        mul4(1.0f / len);
        return len;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setXYZ(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkMatrix3& r, const hkVector4& v) { _setMul3(r, v); }

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkMatrix3
{
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    const hkReal v0 = v.x;
    const hkReal v1 = v.y;
    const hkReal v2 = v.z;
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    w = 0;
}

namespace hkVector4Util {
// gives each component of inout the sign of the product with the matching component of signv
__forceinline void mulSigns4(hkVector4& inout, const hkVector4& signv)
{
    hkUint32* intp = reinterpret_cast<hkUint32*>(&inout);
    const hkUint32* sign = reinterpret_cast<const hkUint32*>(&signv);
    intp[0] ^= (sign[0] & 0x80000000);
    intp[1] ^= (sign[1] & 0x80000000);
    intp[2] ^= (sign[2] & 0x80000000);
    intp[3] ^= (sign[3] & 0x80000000);
}
}  // namespace hkVector4Util

struct hkpShape
{
    virtual ~hkpShape();

    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    __forceinline hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

struct hkpSphereShape : hkpConvexShape
{
};

struct hkpBoxShape : hkpConvexShape
{
    __forceinline const hkVector4& getHalfExtents() const { return m_halfExtents; }

    hkVector4 m_halfExtents;
};

struct hkpCdBody
{
    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;

struct hkpCollisionInput
{
    __forceinline hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

struct hkContactPoint
{
    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline const hkVector4& getNormal() const { return m_separatingNormal; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setNormal(const hkVector4& normal) { m_separatingNormal.setXYZ(normal); }
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

// a contact point with the two bodies it belongs to
struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

struct hkpCdPointCollector
{
    virtual ~hkpCdPointCollector();
    virtual void addCdPoint(const hkpCdPoint& point) = 0;

    hkReal m_earlyOutDistance;
};

struct hkpSphereBoxAgent
{
    virtual ~hkpSphereBoxAgent();

    static __forceinline hkBool getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                const hkpCollisionInput& input, hkContactPoint& contactOut);

    // getClosestPoints
    void hkpSphereBoxAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
                      hkpCdPointCollector& collector);
};

__forceinline hkBool hkpSphereBoxAgent::getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                        const hkpCollisionInput& input, hkContactPoint& contactOut)
{
    const hkVector4& posA = bodyA.getTransform().getTranslation();
    hkVector4 posLocalB;
    posLocalB.FUN_008d2970(bodyB.getTransform(), posA);

    const hkpBoxShape* boxB = static_cast<const hkpBoxShape*>(bodyB.getShape());
    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.getShape());

    hkVector4 absPosB;
    absPosB.setAbs4(posLocalB);
    hkVector4 clippedAbsPos;
    clippedAbsPos.setMin4(absPosB, boxB->getHalfExtents());
    hkVector4 delta;
    delta.setSub4(clippedAbsPos, absPosB);

    hkReal distance;
    if (delta.compareLessThanZero4().anyIsSet(hkVector4Comparison::MASK_XYZ))
    {
        // the centre is outside the box
        distance = delta.normalizeWithLength3();
        distance = distance - (sphereA->getRadius() + boxB->getRadius());
        if (distance > input.getTolerance())
        {
            return false;
        }
        hkVector4Util::mulSigns4(delta, posLocalB);
        delta.setNeg4(delta);
        contactOut.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(), delta);
    }
    else
    {
        // the centre is inside the box: the face it is nearest to
        hkReal d0 = absPosB.x - boxB->getHalfExtents().x;
        hkReal d1 = absPosB.y - boxB->getHalfExtents().y;
        hkReal d2 = absPosB.z - boxB->getHalfExtents().z;
        int i;
        if (d0 > d1)
        {
            if (d0 > d2)
            {
                i = 0;
                contactOut.setNormal(bodyB.getTransform().getColumn(0));
                distance = d0;
            }
            else
            {
                i = 2;
                contactOut.setNormal(bodyB.getTransform().getColumn(2));
                distance = d2;
            }
        }
        else
        {
            if (d1 > d2)
            {
                i = 1;
                contactOut.setNormal(bodyB.getTransform().getColumn(1));
                distance = d1;
            }
            else
            {
                i = 2;
                contactOut.setNormal(bodyB.getTransform().getColumn(2));
                distance = d2;
            }
        }
        if (posLocalB(i) < 0)
        {
            contactOut.getSeparatingNormal().setNeg4(contactOut.getSeparatingNormal());
        }
        distance = distance - boxB->getRadius() - sphereA->getRadius();
    }

    contactOut.getPosition().setAddMul4(posA, contactOut.getNormal(), -distance - sphereA->getRadius());
    contactOut.setDistance(distance);
    return true;
}

// pdb: hkpSphereBoxAgent::getClosestPoints | hkpSphereBoxAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpSphereBoxAgent::hkpSphereBoxAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                     const hkpCollisionInput& input, hkpCdPointCollector& collector)
{
    hkTimerCommand("TtSphereBox");

    hkpCdPoint event(bodyA, bodyB);
    if (getClosestPoint(bodyA, bodyB, input, event.m_contact))
    {
        collector.addCdPoint(event);
    }

    hkTimerCommand("Et");
}

}  // namespace f3m_009c6310
}   // namespace f3m_009c6310

// @f3 0x009dca10 (community match, verified in this file)
#include <math.h>
namespace f3m_009dca10 {
// 0x009dca10: hkpRagdollLimitsData::setInWorldSpace(const hkTransform& bodyATransform,
// const hkTransform& bodyBTransform, const hkVector4& twistAxisW, const hkVector4& planeAxisW) of Havok 5.5.0
// (hkpDynamics, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Builds the constraint's basis in world space (the normalized twist axis, the normalized plane axis and their
// cross product) and stores it in each body's local space: the inverse of the body's rotation times the basis.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, the
// rotate-inverse-points loop) follow the SDK's inline code for the x87 build; the local's name and type (an
// array of three vectors, not a rotation) and the statement boundaries follow the debug records of the SDK
// library's object. The function's own body is written from the game's code.

namespace f3m_009dca10 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}  // namespace hkMath

struct hkRotation;

struct hkVector4
{
    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
    __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& v);
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3();

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkMatrix3
{
    __forceinline hkMatrix3() {}
    __forceinline hkMatrix3(const hkMatrix3& other);

    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline const hkRotation& getRotation() const { return m_rotation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
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

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& v)
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

__forceinline hkSimdReal hkVector4::lengthInverse3() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

__forceinline void hkVector4::normalize3()
{
    this->mul4(this->lengthInverse3());
}

__forceinline hkMatrix3::hkMatrix3(const hkMatrix3& other)
{
    m_col0 = other.m_col0;
    m_col1 = other.m_col1;
    m_col2 = other.m_col2;
}

namespace hkVector4Util {
// rotates numVectors directions by the inverse of t, the last one first; t is copied so that the output may
// alias it
__forceinline void rotateInversePoints(const hkRotation& t, const hkVector4* vectorsIn, int numVectors,
                                       hkVector4* vectorsOut)
{
    hkRotation unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setRotatedInverseDir(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

struct hkReferencedObject
{
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpConstraintData : hkReferencedObject
{
    unsigned long m_userData;
};

struct hkpConstraintAtom
{
    hkUint16 m_type;
};

struct hkpSetLocalRotationsConstraintAtom : hkpConstraintAtom
{
    hkRotation m_rotationA;
    hkRotation m_rotationB;
};

struct hkpRagdollLimitsData : hkpConstraintData
{
    struct Atoms
    {
        hkpSetLocalRotationsConstraintAtom m_rotations;
    };

    // setInWorldSpace
    void FUN_009dca10(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                      const hkVector4& twistAxisW, const hkVector4& planeAxisW);

    Atoms m_atoms;
};

void hkpRagdollLimitsData::FUN_009dca10(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                        const hkVector4& twistAxisW, const hkVector4& planeAxisW)
{
    // the constraint's basis in world space
    hkVector4 constraintBaseInW[3];
    constraintBaseInW[0] = twistAxisW; constraintBaseInW[0].normalize3();
    constraintBaseInW[1] = planeAxisW; constraintBaseInW[1].normalize3();
    constraintBaseInW[2].setCross(constraintBaseInW[0], constraintBaseInW[1]);

    // and in each body's space
    hkVector4Util::rotateInversePoints(bodyATransform.getRotation(), constraintBaseInW, 3, &m_atoms.m_rotations.m_rotationA.getColumn(0));
    hkVector4Util::rotateInversePoints(bodyBTransform.getRotation(), constraintBaseInW, 3, &m_atoms.m_rotations.m_rotationB.getColumn(0));
}

}  // namespace f3m_009dca10
}   // namespace f3m_009dca10

// @f3 0x009dd3a0 (community match, verified in this file)
#include <math.h>
namespace f3m_009dd3a0 {
// 0x009dd3a0: hkpPrismaticConstraintData::setInWorldSpace(const hkTransform& bodyATransform,
// const hkTransform& bodyBTransform, const hkVector4& pivot, const hkVector4& axis) of Havok 5.5.0
// (hkpDynamics, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Builds the constraint's basis in world space (the normalized axis, a vector at right angles to it and their
// cross product), stores it in each body's local space (the inverse of the body's rotation times the basis) and
// stores the pivot in each body's local space.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, the
// perpendicular vector, the rotate-inverse-points loop) follow the SDK's inline code for the x87 build; the
// local's name and type (an array of three vectors) and the statement boundaries follow the debug records of the
// SDK library's object. The function's own body is written from the game's code.

namespace f3m_009dd3a0 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal fabs(hkReal r) { return fabsf(r); }
}  // namespace hkMath

struct hkRotation;
struct hkTransform;

struct hkVector4
{
    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f);
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
    __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& v);
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3();

    // setTransformedInversePos
    void FUN_008d2970(const hkTransform& t, const hkVector4& p);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkMatrix3
{
    __forceinline hkMatrix3() {}
    __forceinline hkMatrix3(const hkMatrix3& other);

    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkVector4& getColumn(int i) { return m_rotation.getColumn(i); }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
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

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& v)
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

__forceinline hkSimdReal hkVector4::lengthInverse3() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

__forceinline void hkVector4::normalize3()
{
    this->mul4(this->lengthInverse3());
}

__forceinline hkMatrix3::hkMatrix3(const hkMatrix3& other)
{
    m_col0 = other.m_col0;
    m_col1 = other.m_col1;
    m_col2 = other.m_col2;
}

namespace hkVector4Util {
// a vector at right angles to vectorIn: its smallest component is left out, the other two are swapped and one
// of them negated
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

// rotates numVectors directions by the inverse of t, the last one first; t is copied so that the output may
// alias it
__forceinline void rotateInversePoints(const hkRotation& t, const hkVector4* vectorsIn, int numVectors,
                                       hkVector4* vectorsOut)
{
    hkRotation unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setRotatedInverseDir(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

struct hkReferencedObject
{
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpConstraintData : hkReferencedObject
{
    unsigned long m_userData;
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

struct hkpPrismaticConstraintData : hkpConstraintData
{
    struct Atoms
    {
        hkpSetLocalTransformsConstraintAtom m_transforms;
    };

    // setInWorldSpace
    void FUN_009dd3a0(const hkTransform& bodyATransform, const hkTransform& bodyBTransform, const hkVector4& pivot,
                      const hkVector4& axis);

    Atoms m_atoms;
};

void hkpPrismaticConstraintData::FUN_009dd3a0(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                              const hkVector4& pivot, const hkVector4& axis)
{
    // the constraint's basis in world space: the axis, a vector at right angles to it, and their cross product
    hkVector4 constraintBaseInW[3];
    constraintBaseInW[0] = axis; constraintBaseInW[0].normalize3();
    hkVector4Util::calculatePerpendicularVector(constraintBaseInW[0], constraintBaseInW[1]); constraintBaseInW[1].normalize3();
    constraintBaseInW[2].setCross(constraintBaseInW[0], constraintBaseInW[1]);

    // the basis in each body's space
    hkVector4Util::rotateInversePoints(bodyATransform.getRotation(), constraintBaseInW, 3, &m_atoms.m_transforms.m_transformA.getColumn(0));
    hkVector4Util::rotateInversePoints(bodyBTransform.getRotation(), constraintBaseInW, 3, &m_atoms.m_transforms.m_transformB.getColumn(0));

    // the pivot in each body's space
    m_atoms.m_transforms.m_transformA.getTranslation().FUN_008d2970(bodyATransform, pivot);
    m_atoms.m_transforms.m_transformB.getTranslation().FUN_008d2970(bodyBTransform, pivot);
}

}  // namespace f3m_009dd3a0
}   // namespace f3m_009dd3a0

// @f3 0x009db830 (community match, verified in this file)
#include <math.h>
namespace f3m_009db830 {
// 0x009db830: hkpWheelConstraintData::setInBodySpace(const hkVector4& pivotA, const hkVector4& pivotB,
// const hkVector4& axleA, const hkVector4& axleB, const hkVector4& suspensionAxisB,
// const hkVector4& steeringAxisB) of Havok 5.5.0 (hkpDynamics, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Sets the wheel constraint up from body-space data: the two pivots, the suspension base (the identity for body
// A; for body B the suspension axis, a vector at right angles to it and their cross product), the steering base
// of each body (the normalized axle, a second axis and their cross product; the second axis is at right angles
// to the axle for body A and the given steering axis for body B) and the initial axle and steering axis of B.
// Class, member and enumerator names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, the
// perpendicular vector) follow the SDK's inline code for the x87 build; which statements share a line follows
// the line table of the SDK library's object. The function's own body is written from the game's code. The
// three base pointers and the two blocks are this source's own way of writing it: the SDK object's debug
// records name no local for this function (a pointer the compiler folds away leaves none).

namespace f3m_009db830 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal fabs(hkReal r) { return fabsf(r); }
}  // namespace hkMath

struct hkRotation;
struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f);
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
    __forceinline void operator=(const hkVector4& v);
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3();


    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkMatrix3
{
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline hkReal& operator()(int r, int c) { return getColumn(c)(r); }
    __forceinline void setZero();
    __forceinline void setIdentity();

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkVector4& getColumn(int i) { return m_rotation.getColumn(i); }
    __forceinline hkRotation& getRotation() { return m_rotation; }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkMatrix3::setZero()
{
    hkVector4 zero; zero.setZero4();
    getColumn(0) = zero;
    getColumn(1) = zero;
    getColumn(2) = zero;
}

__forceinline void hkMatrix3::setIdentity()
{
    setZero();
    hkReal one = 1.0f;
    (*this)(0, 0) = one;
    (*this)(1, 1) = one;
    (*this)(2, 2) = one;
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

namespace hkVector4Util {
// a vector at right angles to vectorIn: its smallest component is left out, the other two are swapped and one
// of them negated
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
}  // namespace hkVector4Util

struct hkReferencedObject
{
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpConstraintData : hkReferencedObject
{
    unsigned long m_userData;
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
    unsigned char m_axisIndex;
    hkReal m_min;
    hkReal m_max;
};

struct hkpLinSoftConstraintAtom : hkpConstraintAtom
{
    unsigned char m_axisIndex;
    hkReal m_tau;
    hkReal m_damping;
};

struct hkpLinConstraintAtom : hkpConstraintAtom
{
    unsigned char m_axisIndex;
};

struct hkpSetLocalRotationsConstraintAtom : hkpConstraintAtom
{
    hkRotation m_rotationA;
    hkRotation m_rotationB;
};

struct hkp2dAngConstraintAtom : hkpConstraintAtom
{
    unsigned char m_freeRotationAxis;
};

struct hkpWheelConstraintData : hkpConstraintData
{
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

    // setInBodySpace
    void FUN_009db830(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axleA,
                      const hkVector4& axleB, const hkVector4& suspensionAxisB, const hkVector4& steeringAxisB);

    Atoms m_atoms;
    hkVector4 m_initialAxleInB;
    hkVector4 m_initialSteeringAxisInB;
};

void hkpWheelConstraintData::FUN_009db830(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axleA,
                                          const hkVector4& axleB, const hkVector4& suspensionAxisB,
                                          const hkVector4& steeringAxisB)
{
    m_atoms.m_suspensionBase.m_transformA.getTranslation() = pivotA;
    m_atoms.m_suspensionBase.m_transformB.getTranslation() = pivotB;

    // the suspension base: the identity for body A; for body B the suspension axis, a vector at right angles
    // to it and their cross product
    m_atoms.m_suspensionBase.m_transformA.getRotation().setIdentity();
    {
        hkVector4* baseB = &m_atoms.m_suspensionBase.m_transformB.getColumn(0);
        baseB[Atoms::AXIS_SUSPENSION] = suspensionAxisB;
        hkVector4Util::calculatePerpendicularVector(baseB[Atoms::AXIS_SUSPENSION], baseB[Atoms::AXIS_PERP_SUSPENSION]); baseB[Atoms::AXIS_PERP_SUSPENSION].normalize3();
        baseB[2].setCross(baseB[Atoms::AXIS_SUSPENSION], baseB[Atoms::AXIS_PERP_SUSPENSION]);
    }

    // the steering base of each body: the axle, the steering axis and their cross product
    {
        hkVector4* baseA = &m_atoms.m_steeringBase.m_rotationA.getColumn(0);
        hkVector4* baseB = &m_atoms.m_steeringBase.m_rotationB.getColumn(0);
        baseA[Atoms::AXIS_AXLE] = axleA; baseA[Atoms::AXIS_AXLE].normalize3();
        baseB[Atoms::AXIS_AXLE] = axleB; baseB[Atoms::AXIS_AXLE].normalize3();
        m_initialAxleInB = baseB[Atoms::AXIS_AXLE];

        hkVector4Util::calculatePerpendicularVector(baseA[Atoms::AXIS_AXLE], baseA[Atoms::AXIS_STEERING]); baseA[Atoms::AXIS_STEERING].normalize3();
        baseB[Atoms::AXIS_STEERING] = steeringAxisB; baseB[Atoms::AXIS_STEERING].normalize3();
        m_initialSteeringAxisInB = baseB[Atoms::AXIS_STEERING];

        baseA[2].setCross(baseA[Atoms::AXIS_AXLE], baseA[Atoms::AXIS_STEERING]);
        baseB[2].setCross(baseB[Atoms::AXIS_AXLE], baseB[Atoms::AXIS_STEERING]);
    }
}

}  // namespace f3m_009db830
}   // namespace f3m_009db830

// @f3 0x009db3b0 (community match, verified in this file)
#include <math.h>
namespace f3m_009db3b0 {
// 0x009db3b0: hkpWheelConstraintData::setInWorldSpace(const hkTransform& bodyATransform,
// const hkTransform& bodyBTransform, const hkVector4& pivot, const hkVector4& axleTmp,
// const hkVector4& suspensionAxis, const hkVector4& steeringAxisTmp) of Havok 5.5.0 (hkpDynamics, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Sets the wheel constraint up from world-space data: the pivot in each body's space, the suspension base (the
// identity for body A; for body B the suspension axis, a vector at right angles to it and their cross product),
// the steering base of each body (the axle, the steering axis and their cross product) and the initial axle and
// steering axis in body B's space.
// Class, member and enumerator names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, the
// perpendicular vector) follow the SDK's inline code for the x87 build; the names of the four vector locals,
// their frame offsets (the two pivot vectors share one, so each has a block) and which statements share a line
// follow the debug records of the SDK library's object. The function's own body is written from the game's
// code. The two steering base pointers are this source's own names: the game's code keeps the address of each
// steering rotation's first column in a register and reaches the other columns from it, and reaches the
// suspension base's columns from `this`; the SDK object's debug records name no such pointer.

namespace f3m_009db3b0 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal fabs(hkReal r) { return fabsf(r); }
}  // namespace hkMath

struct hkRotation;
struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f);
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2);
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void operator=(const hkVector4& v);
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3();

    // setRotatedInverseDir
    void FUN_00477880(const hkRotation& r, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkMatrix3
{
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline hkReal& operator()(int r, int c) { return getColumn(c)(r); }
    __forceinline void setZero();
    __forceinline void setIdentity();

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkVector4& getColumn(int i) { return m_rotation.getColumn(i); }
    __forceinline hkRotation& getRotation() { return m_rotation; }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkMatrix3::setZero()
{
    hkVector4 zero; zero.setZero4();
    getColumn(0) = zero;
    getColumn(1) = zero;
    getColumn(2) = zero;
}

__forceinline void hkMatrix3::setIdentity()
{
    setZero();
    hkReal one = 1.0f;
    (*this)(0, 0) = one;
    (*this)(1, 1) = one;
    (*this)(2, 2) = one;
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

namespace hkVector4Util {
// a vector at right angles to vectorIn: its smallest component is left out, the other two are swapped and one
// of them negated
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
}  // namespace hkVector4Util

struct hkReferencedObject
{
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpConstraintData : hkReferencedObject
{
    unsigned long m_userData;
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
    unsigned char m_axisIndex;
    hkReal m_min;
    hkReal m_max;
};

struct hkpLinSoftConstraintAtom : hkpConstraintAtom
{
    unsigned char m_axisIndex;
    hkReal m_tau;
    hkReal m_damping;
};

struct hkpLinConstraintAtom : hkpConstraintAtom
{
    unsigned char m_axisIndex;
};

struct hkpSetLocalRotationsConstraintAtom : hkpConstraintAtom
{
    hkRotation m_rotationA;
    hkRotation m_rotationB;
};

struct hkp2dAngConstraintAtom : hkpConstraintAtom
{
    unsigned char m_freeRotationAxis;
};

struct hkpWheelConstraintData : hkpConstraintData
{
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

    // setInWorldSpace
    void FUN_009db3b0(const hkTransform& bodyATransform, const hkTransform& bodyBTransform, const hkVector4& pivot,
                      const hkVector4& axleTmp, const hkVector4& suspensionAxis, const hkVector4& steeringAxisTmp);

    Atoms m_atoms;
    hkVector4 m_initialAxleInB;
    hkVector4 m_initialSteeringAxisInB;
};

void hkpWheelConstraintData::FUN_009db3b0(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                          const hkVector4& pivot, const hkVector4& axleTmp,
                                          const hkVector4& suspensionAxis, const hkVector4& steeringAxisTmp)
{
    hkVector4 axle = axleTmp; axle.normalize3();
    hkVector4 steeringAxis = steeringAxisTmp; steeringAxis.normalize3();

    // the pivot in each body's space
    {
        hkVector4 pivotAinW; pivotAinW.setSub4(pivot, bodyATransform.getTranslation());
        m_atoms.m_suspensionBase.m_transformA.getTranslation().FUN_00477880(bodyATransform.getRotation(), pivotAinW);
    }
    {
        hkVector4 pivotBinW; pivotBinW.setSub4(pivot, bodyBTransform.getTranslation());
        m_atoms.m_suspensionBase.m_transformB.getTranslation().FUN_00477880(bodyBTransform.getRotation(), pivotBinW);
    }

    // the suspension base: the identity for body A; for body B the suspension axis, a vector at right angles
    // to it and their cross product
    m_atoms.m_suspensionBase.m_transformA.getRotation().setIdentity();
    m_atoms.m_suspensionBase.m_transformB.getColumn(Atoms::AXIS_SUSPENSION).FUN_00477880(bodyBTransform.getRotation(), suspensionAxis);
    hkVector4Util::calculatePerpendicularVector(m_atoms.m_suspensionBase.m_transformB.getColumn(Atoms::AXIS_SUSPENSION), m_atoms.m_suspensionBase.m_transformB.getColumn(Atoms::AXIS_PERP_SUSPENSION)); m_atoms.m_suspensionBase.m_transformB.getColumn(Atoms::AXIS_PERP_SUSPENSION).normalize3();
    m_atoms.m_suspensionBase.m_transformB.getColumn(2).setCross(m_atoms.m_suspensionBase.m_transformB.getColumn(Atoms::AXIS_SUSPENSION), m_atoms.m_suspensionBase.m_transformB.getColumn(Atoms::AXIS_PERP_SUSPENSION));

    // the steering base of each body: the axle, the steering axis and their cross product
    {
        hkVector4* baseA = &m_atoms.m_steeringBase.m_rotationA.getColumn(0);
        hkVector4* baseB = &m_atoms.m_steeringBase.m_rotationB.getColumn(0);
        baseA[Atoms::AXIS_AXLE].FUN_00477880(bodyATransform.getRotation(), axle);
        baseB[Atoms::AXIS_AXLE].FUN_00477880(bodyBTransform.getRotation(), axle);
        m_initialAxleInB = baseB[Atoms::AXIS_AXLE];

        baseA[Atoms::AXIS_STEERING].FUN_00477880(bodyATransform.getRotation(), steeringAxis);
        baseB[Atoms::AXIS_STEERING].FUN_00477880(bodyBTransform.getRotation(), steeringAxis);
        m_initialSteeringAxisInB = baseB[Atoms::AXIS_STEERING];

        baseA[2].setCross(baseA[Atoms::AXIS_AXLE], baseA[Atoms::AXIS_STEERING]);
        baseB[2].setCross(baseB[Atoms::AXIS_AXLE], baseB[Atoms::AXIS_STEERING]);
    }
}

}  // namespace f3m_009db3b0
}   // namespace f3m_009db3b0

// @f3 0x009dad90 (community match, verified in this file)
#include <math.h>
namespace f3m_009dad90 {
// 0x009dad90: hkpBreakableConstraintData::buildJacobianCallback(const hkpConstraintQueryIn& in) of Havok 5.5.0
// (hkpDynamics, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Sums the squares of the wrapped constraint's applied impulses; when the sum passes the breaking threshold the
// constraint is marked broken, its setup callback is switched off, the listener is told, and, if asked for, the
// two bodies' velocities are blended back towards the ones saved before the step. The applied impulses are
// cleared in any case.
// Class and member names follow the Havok 5.5.0 SDK headers; the vector and maths helpers follow the SDK's
// inline maths for the x87 build. The locals, their scopes and the statement order follow the debug records
// and the unoptimized code of the SDK's hybrid library object (hkpBreakableConstraintData.obj): built with the
// SDK's own headers this body reproduces that object and the release object; the classes here are written out
// by hand for a self-contained file.

namespace f3m_009dad90 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long hkUlong;
typedef void hkpConstraintRuntime;

namespace hkMath {
inline hkReal sqrt(hkReal r) { return sqrtf(r); }
inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}  // namespace hkMath

template <typename TYPE>
__forceinline TYPE* hkAddByteOffset(TYPE* base, hkUlong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }
    inline hkBool& operator=(bool e)
    {
        m_bool = static_cast<char>(e);
        return *this;
    }

private:
    char m_bool;
};

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0);
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt);

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

__forceinline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
    hkReal t = hkReal(rt);
    hkReal s = 1.0f - t;
    hkVector4& d = *this;
    d(0) = s * v0(0) + t * v1(0);
    d(1) = s * v0(1) + t * v1(1);
    d(2) = s * v0(2) + t * v1(2);
    d(3) = s * v0(3) + t * v1(3);
}

struct hkpConstraintAtom
{
    enum CallbackRequest
    {
        CALLBACK_REQUEST_NONE = 0,
        CALLBACK_REQUEST_NEW_CONTACT_POINT = 1,
        CALLBACK_REQUEST_SETUP_PPU_ONLY = 2,
        CALLBACK_REQUEST_SETUP_CALLBACK = 4
    };

    hkUint16 m_type;
};

class hkpConstraintInstance;
class hkpConstraintOwner;
class hkpConstraintData;
class hkpEntity;

struct hkConstraintInternal
{
    hkpConstraintInstance* m_constraint;
    hkpEntity* m_entities[2];
    hkpConstraintAtom* m_atoms;
    hkUint16 m_atomsSize;
    hkUint8 m_callbackRequest;
    hkUint8 m_priority;
};

class hkReferencedObject
{
public:
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
};

class hkpConstraintInstance : public hkReferencedObject
{
public:
    hkpConstraintOwner* m_owner;
    hkpConstraintData* m_data;
    hkpConstraintAtom* m_constraintModifiers;
    hkpEntity* m_entities[2];
    hkUint8 m_priority;
    hkBool m_wantRuntime;
    const char* m_name;
    hkUlong m_userData;
    hkConstraintInternal* m_internal;
};

struct hkpVelocityAccumulator
{
    hkUint8 m_type;
    hkBool m_matrixIsIdentity;
    hkUint32 m_deactivationClass;
    hkVector4 m_linearVel;
    hkVector4 m_angularVel;
    hkVector4 m_invMasses;
};

class hkpSolverResults
{
public:
    hkReal m_impulseApplied;
    hkReal m_internalSolverData;
};

struct hkTransform;

class hkpConstraintQueryStepInfo
{
public:
    __declspec(align(16)) hkPadSpu<float> m_substepDeltaTime;
    hkPadSpu<float> m_microStepDeltaTime;
    hkPadSpu<float> m_substepInvDeltaTime;
    hkPadSpu<float> m_frameDeltaTime;
    hkPadSpu<float> m_frameInvDeltaTime;
    hkPadSpu<float> m_invNumSteps;
    hkPadSpu<float> m_invNumStepsTimesMicroSteps;
    hkPadSpu<float> m_rhsFactor;
    hkPadSpu<float> m_virtMassFactor;
    hkPadSpu<float> m_frictionRhsFactor;
};

class hkpConstraintQueryIn : public hkpConstraintQueryStepInfo
{
public:
    __declspec(align(16)) hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
    hkPadSpu<const hkpVelocityAccumulator*> m_bodyB;
    hkPadSpu<const hkTransform*> m_transformA;
    hkPadSpu<const hkTransform*> m_transformB;
    hkPadSpu<hkReal> m_tau;
    hkPadSpu<hkReal> m_damping;
    hkPadSpu<hkpConstraintInstance*> m_constraintInstance;
    hkPadSpu<void*> m_constraintRuntime;
};

class hkpBreakableConstraintData;

class hkpBreakableConstraintEvent
{
public:
    hkpConstraintInstance* m_constraintInstance;
    hkpBreakableConstraintData* m_breakableConstraintData;
    hkReal m_forceMagnitude;
    hkBool m_removed;
};

class hkpBreakableListener
{
public:
    virtual void constraintBrokenCallback(hkpBreakableConstraintEvent& event) = 0;
    virtual ~hkpBreakableListener() {}
};

class hkpConstraintData : public hkReferencedObject
{
public:
    hkUlong m_userData;
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

class hkpBreakableConstraintData : public hkpConstraintData
{
public:
    struct Runtime
    {
        hkBool m_isBroken;
        hkReal m_linearVelcityA[3];
        hkReal m_linearVelcityB[3];
        hkReal m_angularVelcityA[3];
        hkReal m_angularVelcityB[3];
    };

    inline Runtime* getRuntime(hkpConstraintRuntime* runtime)
    {
        return reinterpret_cast<Runtime*>(hkAddByteOffset(runtime, m_childRuntimeSize));
    }

    // buildJacobianCallback
    void FUN_009dad90(const hkpConstraintQueryIn& in);

    hkpBridgeAtoms m_atoms;
    hkpConstraintData* m_constraintData;
    hkUint16 m_childRuntimeSize;
    hkUint16 m_childNumSolverResults;
    hkReal m_solverResultLimit;
    hkBool m_removeWhenBroken;
    hkBool m_revertBackVelocityOnBreak;
    hkpBreakableListener* m_listener;
};

// pdb: hkpBreakableConstraintData::setBroken | hkpBreakableConstraintData.obj | fnv360_0822_retail, objrun, medium
// pdb params: instance, broken, currentForce
void hkpBreakableConstraintData::FUN_009dad90(const hkpConstraintQueryIn& in)
{
    hkpSolverResults* results = static_cast<hkpSolverResults*>(in.m_constraintRuntime.val());
    int numResults = m_childNumSolverResults;
    // (the debug build asserts here that the wrapped constraint has a runtime)

    Runtime* runtime = getRuntime(in.m_constraintRuntime);
    if (!runtime->m_isBroken)
    {
        hkReal sumReactionForce = 0.0f;
        for (int j = 0; j < numResults; j++)
        {
            hkReal impulse = results[j].m_impulseApplied;
            sumReactionForce += impulse * impulse;
        }

        if (sumReactionForce > m_solverResultLimit * m_solverResultLimit)
        {
            // the constraint breaks: no more setup callbacks, and the listener hears of it
            runtime->m_isBroken = true;
            in.m_constraintInstance->m_internal->m_callbackRequest &= ~hkpConstraintAtom::CALLBACK_REQUEST_SETUP_CALLBACK;

            if (m_listener)
            {
                hkpConstraintInstance* constraintInstance = in.m_constraintInstance.val();
                hkpBreakableConstraintEvent data; data.m_constraintInstance = constraintInstance;
                data.m_forceMagnitude = hkMath::sqrt(sumReactionForce);
                data.m_removed = m_removeWhenBroken;
                data.m_breakableConstraintData = this;
                m_listener->constraintBrokenCallback(data);
            }

            if (m_revertBackVelocityOnBreak)
            {
                // blend the bodies' velocities back towards the ones saved before the step
                hkReal f = m_solverResultLimit * hkMath::sqrtInverse(sumReactionForce);

                hkVector4 linA; { hkReal* s = runtime->m_linearVelcityA; linA.set(s[0], s[1], s[2]); }
                hkVector4 linB; { hkReal* s = runtime->m_linearVelcityB; linB.set(s[0], s[1], s[2]); }
                hkVector4 angA; { hkReal* s = runtime->m_angularVelcityA; angA.set(s[0], s[1], s[2]); }
                hkVector4 angB; { hkReal* s = runtime->m_angularVelcityB; angB.set(s[0], s[1], s[2]); }

                hkpVelocityAccumulator* bodyA = const_cast<hkpVelocityAccumulator*>(in.m_bodyA.val());
                hkpVelocityAccumulator* bodyB = const_cast<hkpVelocityAccumulator*>(in.m_bodyB.val());
                { hkVector4& d = bodyA->m_linearVel; d.setInterpolate4(linA, d, f); }
                { hkVector4& d = bodyB->m_linearVel; d.setInterpolate4(linB, d, f); }
                { hkVector4& d = bodyA->m_angularVel; d.setInterpolate4(angA, d, f); }
                { hkVector4& d = bodyB->m_angularVel; d.setInterpolate4(angB, d, f); }
            }
        }
    }

    for (int j = 0; j < numResults; j++)
    {
        results[j].m_impulseApplied = 0.0f;
    }
}

}  // namespace f3m_009dad90
}   // namespace f3m_009dad90

// @f3 0x009c9120 (community match, verified in this file)
// 0x009c9120: hkpSphereCapsuleAgent::processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result) of Havok 5.5.0 (hkpCollide, compiled
// with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Finds the closest point between sphere A and capsule B straight into the output's next free contact point.
// While the two are within the tolerance the agent keeps one contact point with the contact manager (added on
// first touch, committed to the output each step); when they part the point is removed again. A timer brackets
// it.
// This file is built from the Havok 5.5.0 SDK's own headers: the function and its inline helper
// getClosestPointInl (at the end of the file) were compiled with the real headers, and the preprocessed source
// was cut down mechanically to the declarations the function's code needs; the declarations above the two
// functions are therefore the SDK's text with its names. The two function bodies are written from the game's
// code; local names and statement order follow the debug records of the SDK's library objects, and built with
// the SDK's headers this source reproduces both the SDK's unoptimized (hybrid) object and its release object of
// this function. Only the function itself carries the packet's name; the clock read in
// hkMonitorStream::TimerCommand::setTime is the SDK's own two-instruction block, the one the kit accepts.
namespace f3m_009c9120 {

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
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
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
		{
			if ( f > midf[0]){		minf = midf;	}	else	{	maxf = midf;	}
			midf = (hkInt32*)(  (hkUlong(minf)>>1) + (hkUlong(maxf)>>1) );
		}
		if ( f > midf[0])
		{
			midf++;
		}
		hkUlong fi = midf - (hkInt32*)(&hkUFloat8_intToReal[0]);
		m_value = hkUint8(fi);
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
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
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
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
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
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
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
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
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
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
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
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
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
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
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
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
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
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
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
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
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
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
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
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
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
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
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
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
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
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
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
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}
inline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& d = *this;
		d(0) = t(0,0)*v0 + t(0,1)*v1 + t(0,2)*v2 + t(0,3);
		d(1) = t(1,0)*v0 + t(1,1)*v1 + t(1,2)*v2 + t(1,3);
		d(2) = t(2,0)*v0 + t(2,1)*v1 + t(2,2)*v2 + t(2,3);
		d(3) = 0;
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
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
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
const hkVector4& hkTransform::getTranslation() const
{
	return m_translation;
}
hkTransform::hkTransform(const hkTransform& t)
{
	const hkVector4 r0 = t.m_rotation.getColumn(0);
	const hkVector4 r1 = t.m_rotation.getColumn(1);
	const hkVector4 r2 = t.m_rotation.getColumn(2);
	const hkVector4 r3 = t.m_rotation.getColumn(3);
	m_rotation.getColumn(0) = r0;
	m_rotation.getColumn(1) = r1;
	m_rotation.getColumn(2) = r2;
	m_rotation.getColumn(3) = r3;
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
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
class hkMotionState;
class hkAabb;
class hkSphere;
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
		inline void setNormal( const hkVector4& normal );
		inline hkReal getDistance() const;
		inline hkSimdReal getDistanceSimdReal() const;
		inline void setDistance( hkReal d );
		inline void set( const hkVector4& position, const hkVector4& normal, float dist );
		inline void setFlipped( const hkContactPoint& point );
		inline void flip();
	protected:
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline const hkVector4& hkContactPoint::getNormal() const
{
	return m_separatingNormal;
}
inline hkVector4& hkContactPoint::getPosition()
{
	return m_position;
}
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
	return m_separatingNormal;
}
inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}
class hkpCdVertex;
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
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpShape( hkpShapeType type );
		__forceinline hkpShapeType getType() const;
		__forceinline void getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		__forceinline hkBool castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const;
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
	public:
		hkUlong m_userData;
	public:
		hkEnum<hkpShapeType, hkUint32> m_type;
	public:
		hkpShape( class hkFinishLoadedObjectFlag flag ) { m_type = HK_SHAPE_INVALID; }
};
class hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpCdBody(  ){}
		friend class hkpCollidable;
		__forceinline hkpCdBody( const hkpShape* shape, const hkMotionState* motionState );
		__forceinline hkpCdBody( const hkpShape* shape, const hkTransform* t );
		__forceinline hkpCdBody( const hkpCdBody& body ){}
		__forceinline const hkTransform& getTransform() const;
		__forceinline const hkpShape* getShape() const;
		__forceinline const hkpCollidable* getRootCollidable() const;
		__forceinline hkpShapeKey getShapeKey() const ;
		__forceinline const hkpCdBody* getParent() const;
	public:
		explicit __forceinline hkpCdBody( const hkpCdBody* parent );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkMotionState* ms );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkTransform* t );
		__forceinline void setShape( const hkpShape* shape, hkpShapeKey key );
		__forceinline const hkMotionState* getMotionState() const;
		__forceinline void setMotionState( const hkMotionState* state );
		__forceinline void setTransform( const hkTransform* t );
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};
const hkTransform& hkpCdBody::getTransform() const
{
	;
	return *static_cast<const hkTransform*>(m_motion);
}
const hkpShape* hkpCdBody::getShape() const
{
	return m_shape;
}
struct hkpAgentEntry;
struct hkpCollisionQualityInfo;
class hkpCollisionDispatcher;
class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionAgentConfig;
struct hkpCollisionInput
{
	public:
		hkReal getTolerance() const { return m_tolerance; }
		void setTolerance(hkReal t) { m_tolerance = t; }
	public:
		hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
		hkPadSpu<hkReal> m_tolerance;
		hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
		hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
		mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
		struct Aabb32Info
		{
			hkVector4 m_bitOffsetLow;
			hkVector4 m_bitOffsetHigh;
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
};
struct hkpProcessCollisionData;
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
class hkpGskCache;
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
class hkContactPointMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkReal getFriction( ) const;
		inline void setFriction( hkReal r );
		inline hkReal getRestitution( ) const;
		inline void setRestitution( hkReal r );
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
		void set(const hkContactPointPropertiesWithExtendedUserData16& other)
		{
			*this = other;
		}
		hkpContactPointProperties::UserData m_extendedUserDatas[7];
};
class hkpConstraintOwner;
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
		__forceinline hkContactPointId addContactPoint( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const hkpGskCache* contactCache, hkContactPoint& cp );
		__forceinline hkResult reserveContactPoints( int numPoints );
		__forceinline void removeContactPoint( hkContactPointId cpId, hkpConstraintOwner& constraintOwner );
		__forceinline void removeToi( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties );
	public:
		virtual hkContactPointId addContactPointImpl( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const hkpGskCache* contactCache, hkContactPoint& cp ) = 0;
		virtual hkResult reserveContactPointsImpl( int numPoints ) = 0;
		virtual void removeContactPointImpl( hkContactPointId cpId, hkpConstraintOwner& constraintOwner ) = 0;
		virtual void removeToiImpl( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties ) = 0;
		virtual void cleanup(){}
	public:
		Type m_type;
};
hkContactPointId hkpContactMgr::addContactPoint( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const hkpGskCache* contactCache, hkContactPoint& cp )
{
	return addContactPointImpl( a, b, input, output, contactCache, cp );
}
void hkpContactMgr::removeContactPoint( hkContactPointId cpId, hkpConstraintOwner& constraintOwner )
{
	removeContactPointImpl( cpId, constraintOwner );
}
struct hkpProcessCdPoint
{
	hkContactPoint m_contact;
    hkPadSpu<hkUint32>	m_contactPointId;
};
struct hkpLinearCastCollisionInput;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
class hkpCollisionAgent : public hkReferencedObject
{
	public:
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector ) = 0;
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector  ) = 0;
	public:
		virtual void processCollision( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result ) = 0;
		virtual void cleanup(hkpConstraintOwner& info) = 0;
		virtual void invalidateTim(hkpCollisionInput& input);
		virtual void warpTime(hkTime oldTime, hkTime newTime, hkpCollisionInput& input);
		virtual void removePoint( hkContactPointId idToRemove );
		virtual void commitPotential( hkContactPointId newId );
		virtual void createZombie( hkContactPointId idTobecomeZombie );
	protected:
		inline virtual ~hkpCollisionAgent();
		inline hkpCollisionAgent( hkpContactMgr* contactMgr );
	protected:
		hkpContactMgr* m_contactMgr;
	public:
		inline hkpContactMgr* getContactMgr();
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
struct hkpProcessCollisionInput : public hkpCollisionInput
{
	public:
		hkStepInfo m_stepInfo;
		mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
		void*	m_dynamicsInfo;
		bool m_enableDeprecatedWelding;
		hkpCollisionAgentConfig* m_config;
};
class hkpTriangleShape;
class hkpGskCache
{
	public:
		hkUint16  m_vertices[4];
		hkUint8	  m_dimA;
		hkUint8	  m_dimB;
		enum MaxDim
		{
			MAX_DIM_MAX = 15
		};
		hkUint8	  m_maxDimA : 4;
		hkUint8	  m_maxDimB : 4;
		typedef hkUint8 GskFlags;
		enum GskFlagValues
		{
			GSK_FLAGS_SHAPE_A_IS_CYLINDER           = 0x01,
			GSK_FLAGS_SHAPE_B_IS_CYLINDER           = 0x02,
			GSK_FLAGS_REPLACE_SHAPE_A_WITH_CAPSULE  = 0x04,
			GSK_FLAGS_REPLACE_SHAPE_B_WITH_CAPSULE  = 0x08,
			GSK_FLAGS_CYLINDER_AGENT_FLAGS          = 0x0f,
			GSK_FLAGS_DISABLE_CONTACT_TIMS     = 0x10,
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
enum {HK_MAX_CONTACT_POINT = 256 };
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
				hkContactPoint     m_contactPoint;
				hkPadSpu<hkReal>   m_time;
				hkPadSpu<hkReal>      m_seperatingVelocity;
				hkGskCache16			m_gskCache;
				hkContactPointPropertiesWithExtendedUserData16 m_properties;
		};
		struct ToiInfo m_toi;
		inline hkpProcessCollisionData( hkpConstraintOwner* owner );
};
struct hkpProcessCollisionOutput: public hkpProcessCollisionData
{
	public:
		inline hkpProcessCollisionOutput(hkpConstraintOwner* owner): hkpProcessCollisionData(owner){}
		inline void reset()
		{
			m_firstFreeContactPoint = &m_contactPoints[0];
			m_toi.m_time = 3.40282e+38f;
			m_potentialContacts = 0;
		}
		inline hkpProcessCdPoint* reserveContactPoints( int numberOfPoints=1 )
		{
			return m_firstFreeContactPoint;
		}
		inline void commitContactPoints( int numberOfPoints=1 )
		{
			m_firstFreeContactPoint= m_firstFreeContactPoint + numberOfPoints;
			;
		}
		inline void abortContactPoints( int numberOfPoints=1 )
		{
		}
	public:
		struct ContactRef
		{
			hkpProcessCdPoint*	m_contactPoint;
			hkpAgentEntry*		m_agentEntry;
			void*			    m_agentData;
		};
		struct PotentialInfo
		{
			void reset()
			{
				m_firstFreePotentialContact      = &m_potentialContacts[0];
				m_firstFreeRepresentativeContact = &m_representativeContacts[0];
			}
			ContactRef*        m_firstFreePotentialContact;
			hkpProcessCdPoint** m_firstFreeRepresentativeContact;
			hkpProcessCdPoint*  m_representativeContacts[ HK_MAX_CONTACT_POINT ];
			ContactRef         m_potentialContacts[ HK_MAX_CONTACT_POINT ];
		};
	public:
		hkPadSpu<PotentialInfo*>    m_potentialContacts;
};
class hkpIterativeLinearCastAgent : public hkpCollisionAgent
{
	public:
		hkpIterativeLinearCastAgent(hkpContactMgr* contactMgr): hkpCollisionAgent(contactMgr){}
		__forceinline ~hkpIterativeLinearCastAgent(){}
};
class hkpSphereCapsuleAgent : public hkpIterativeLinearCastAgent
{
    public:
		static void __cdecl registerAgent(hkpCollisionDispatcher* dispatcher);
        // processCollision (virtual inline in the SDK header)
        void hkpSphereCapsuleAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result);
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& pointDetails);
		virtual void getPenetrations(const  hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		virtual void cleanup(hkpConstraintOwner& info);
	protected:
		__forceinline hkpSphereCapsuleAgent( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr );
		static hkpCollisionAgent* __cdecl createSphereCapsuleAgent(const 	hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr);
	public:
		enum ClosestPointResult
		{
			ST_CP_MISS,
			ST_CP_HIT,
		};
	private:
		static __forceinline ClosestPointResult getClosestPointInl( const  hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkContactPoint& cpoint);
	protected:
		static ClosestPointResult __cdecl getClosestPoint( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkContactPoint& cpoint);
		hkContactPointId m_contactPointId;
};
class hkpSphereRepShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline int getNumCollisionSpheres( )  const;
		__forceinline const hkSphere* getCollisionSpheres( hkSphere* sphereBuffer ) const;
	protected:
		virtual int getNumCollisionSpheresImpl(  )  const = 0;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const = 0;
	public:
		hkpSphereRepShape( hkpShapeType type ) : hkpShape( type ) {}
		hkpSphereRepShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_SPHERE_REP; }
};
class hkpConvexShape : public hkpSphereRepShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void getSupportingVertex( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		__forceinline void convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const ;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		inline hkReal getRadius() const;
		inline void setRadius(hkReal radius);
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
		__forceinline hkpConvexShape::WeldResult weldContactPoint(	hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
																	hkVector4& contactPointWs, const hkTransform* thisObjTransform,
																	const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		__forceinline void getCentre( hkVector4& centreOut ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const = 0;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const = 0;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
	protected:
		inline hkpConvexShape( hkpShapeType type, hkReal radius );
		hkReal m_radius;
	public:
		hkpConvexShape( hkFinishLoadedObjectFlag flag ) : hkpSphereRepShape(flag) { m_type = HK_SHAPE_CONVEX; }
};
inline hkReal hkpConvexShape::getRadius() const
{
	return m_radius;
}
class hkpSphereShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		hkpSphereShape(hkReal radius);
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		static void __cdecl registerSimulationFunctions( ShapeFuncs& sf );
		static void __cdecl registerCollideQueryFunctions( ShapeFuncs& sf );
		static void __cdecl registerGetAabbFunction( ShapeFuncs& sf );
	public:
		hkpSphereShape( hkFinishLoadedObjectFlag flag ) : hkpConvexShape(flag) { m_type = HK_SHAPE_SPHERE; }
		hkUint32 m_pad16[3];
};
class hkpCapsuleShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum RayHitType
		{
			HIT_CAP0,
			HIT_CAP1,
			HIT_BODY,
		};
		hkpCapsuleShape( const hkVector4& vertexA,const hkVector4& vertexB, hkReal radius );
		inline const hkVector4* getVertices() const;
		__forceinline const hkVector4& getVertex(int i) const;
		__forceinline void setVertex(int i, const hkVector4& position );
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		static void __cdecl registerSimulationFunctions( ShapeFuncs& sf );
		static void __cdecl registerCollideQueryFunctions( ShapeFuncs& sf );
		static void __cdecl registerGetAabbFunction( ShapeFuncs& sf );
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	public:
		static void __cdecl closestPointLineSeg( const hkVector4& A, const hkVector4& B, const hkVector4& B2, hkVector4& pt );
	protected:
		hkVector4  m_vertexA;
		hkVector4  m_vertexB;
	public:
		hkpCapsuleShape( hkFinishLoadedObjectFlag flag ) : hkpConvexShape(flag) { m_type = HK_SHAPE_CAPSULE; }
};
const hkVector4* hkpCapsuleShape::getVertices() const
{
	return &m_vertexA;
}
class hkpCollideTriangleUtil
{
	public:
		enum
		{
			CLSLS_POINTA_START = 1,
			CLSLS_POINTA_END   = 2,
			CLSLS_POINTB_START = 4,
			CLSLS_POINTB_END   = 8
		};
		struct ClosestLineSegLineSegResult
		{
			hkVector4 m_closestPointA;
			hkVector4 m_closestAminusClosestB;
			hkPadSpu<hkReal>  m_distanceSquared;
		};
		struct ClosestPointLineSegResult
		{
			hkVector4 m_pointOnEdge;
		};
		static int __cdecl closestPointLineSeg( hkVector4Parameter A, hkVector4Parameter B0, hkVector4Parameter B1, ClosestPointLineSegResult& result );
		struct ClosestPointTriangleCache
		{
			hkReal m_QQ;
			hkReal m_RR;
			hkReal m_QR;
			hkReal m_invTriNormal;
		};
		struct ClosestPointTriangleResult
		{
			hkVector4			hitDirection;
			hkPadSpu<hkReal>	distance;
			void calcClosestPoint( hkVector4Parameter point, hkVector4& closestPoint )
			{
				closestPoint.setAddMul4( point, hitDirection, distance.val() );
			}
		};
		static void __cdecl setupClosestPointTriangleCache( const hkVector4* triangle, ClosestPointTriangleCache& cache );
		enum ClosestPointTriangleStatus
		{
			HIT_TRIANGLE_FACE = 0,
			HIT_TRIANGLE_EDGE
		};
		struct PointTriangleDistanceCache
		{
			hkReal m_invEdgeLen[3];
			hkReal m_invNormalLen;
			hkReal m_normalLen;
		};
		static void __cdecl setupPointTriangleDistanceCache( const hkVector4* triangle, PointTriangleDistanceCache& cache );
		static const hkInt8 maskToIndex[];
		static const hkInt8 vertexToEdgeLut[];
		static inline int __cdecl getNextModulo3( int i ) { return vertexToEdgeLut[i+2]; }
		static inline int __cdecl getPrevModulo3( int i ) { return vertexToEdgeLut[i]; }
	protected:
		hkpCollideTriangleUtil();
};
namespace hkVector4Util
{
__forceinline void __cdecl calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut);
__forceinline void __cdecl transformPoints( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
__forceinline void __cdecl checkRegisters( hkUint32 registerMask );
}
__forceinline void __cdecl hkVector4Util::checkRegisters( hkUint32 registerMask )
{
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
inline void __cdecl hkVector4Util::transformPoints( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	;
	checkRegisters( 0xf0000000 );
	hkTransform unaliased = t;
	int i = numVectors - 1;
	do
	{
		vectorsOut[i]._setTransformedPos( unaliased, vectorsIn[i] );
	} while( --i >= 0 );
}
__forceinline hkpSphereCapsuleAgent::ClosestPointResult hkpSphereCapsuleAgent::getClosestPointInl( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkContactPoint& cpoint )
{
	const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>( bodyA.getShape() );
	const hkpCapsuleShape* capsuleB = static_cast<const hkpCapsuleShape*>( bodyB.getShape() );
	const hkVector4& posA = bodyA.getTransform().getTranslation();
	hkVector4 capsB[2];
	hkVector4Util::transformPoints( bodyB.getTransform(), capsuleB->getVertices(), 2, capsB );
	hkpCollideTriangleUtil::ClosestPointLineSegResult result;
	hkpCollideTriangleUtil::closestPointLineSeg( posA, capsB[0], capsB[1], result );
	hkVector4 aMinusB;
	aMinusB.setSub4( posA, result.m_pointOnEdge );
	const hkReal radiusSum = sphereA->getRadius() + capsuleB->getRadius();
	const hkReal refDist = radiusSum + input.getTolerance();
	hkReal distSquared = aMinusB.lengthSquared3();
	if ( distSquared >= refDist * refDist )
	{
		return ST_CP_MISS;
	}
	hkReal dist;
	if ( distSquared > 0 )
	{
		dist = hkMath::sqrt( distSquared );
		cpoint.getSeparatingNormal() = aMinusB;
	}
	else
	{
		dist = 0;
		hkVector4 edge;
		edge.setSub4( capsB[1], capsB[0] );
		hkVector4Util::calculatePerpendicularVector( edge, cpoint.getSeparatingNormal() );
	}
	cpoint.getSeparatingNormal().normalize3();
	cpoint.getPosition().setAddMul4( posA, cpoint.getNormal(), capsuleB->getRadius() - dist );
	cpoint.setDistance( dist - radiusSum );
	return ST_CP_HIT;
}
// pdb: hkpSphereCapsuleAgent::processCollision | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpSphereCapsuleAgent::hkpSphereCapsuleAgent_processCollision( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result )
{
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "T" "t" "SphereCapsule"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	hkpProcessCdPoint& point = *result.reserveContactPoints( 1 );
	if ( getClosestPointInl( bodyA, bodyB, input, point.m_contact ) != ST_CP_MISS )
	{
		if ( m_contactPointId == (0xffff) )
		{
			m_contactPointId = m_contactMgr->addContactPoint( bodyA, bodyB, input, result, 0, point.m_contact );
		}
		if ( m_contactPointId != (0xffff) )
		{
			point.m_contactPointId = m_contactPointId;
			result.commitContactPoints( 1 );
		}
		else
		{
			result.abortContactPoints( 1 );
		}
	}
	else
	{
		if ( m_contactPointId != (0xffff) )
		{
			m_contactMgr->removeContactPoint( m_contactPointId, *result.m_constraintOwner.val() );
			m_contactPointId = (0xffff);
		}
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
}

}  // namespace f3m_009c9120

// @f3 0x009c2240 (community match, verified in this file)
namespace f3m_009c2240 {
// 0x009c2240: hkCapsuleTriangleAgent3::sepNormal(const hkpAgent3Input& input, hkpAgentEntry* entry,
// hkpAgentData* agentData, hkVector4& separatingNormalOut) of Havok 5.5.0 (hkpInternal, a function of the
// hkCapsuleTriangleAgent3 namespace, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The separating normal of a capsule and a triangle for the agent3 machine: both shapes are taken into world space
// (the capsule's two end points, the triangle's three vertices), hkCollideCapsuleUtilCapsVsTri finds the closest
// points with the agent's cached triangle data, and the normal of the nearer of the first two points is returned.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector's assignment, the
// transform's copy, transformPoints, the bodies' and shapes' accessors) follow the SDK's inline code for the x87
// build, after this account's hkpCapsuleTriangleAgent::staticGetClosestPoints (0x009c3590). The locals, their names
// and the statement order are those of the SDK's unoptimized library object of this function.

namespace f3m_009c2240 {

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef hkUint16 hkContactPointId;

template <typename T> struct hkPadSpu
{
    T operator->() const { return m_storage; }
    operator T() const { return m_storage; }
    T val() const { return m_storage; }

    T m_storage;
};

const hkReal HK_REAL_MAX = 3.40282e+38f;

struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    inline void operator=(const hkVector4& v);
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

inline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

struct hkMatrix3
{
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline const hkReal& operator()(int row, int column) const { return m_rotation(row, column); }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

// the translation is the rotation's fourth column
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
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

namespace hkVector4Util {
// transforms numVectors points, the last one first; the transform is copied so that the output may alias it
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                   hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

struct hkContactPoint
{
    hkReal getDistance() const { return m_separatingNormal(3); }
    const hkVector4& getSeparatingNormal() const { return m_separatingNormal; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpShape
{
    virtual ~hkpShape();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    inline hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

struct hkpCapsuleShape : hkpConvexShape
{
    inline const hkVector4* getVertices() const { return &m_vertexA; }

    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpTriangleShape : hkpConvexShape
{
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    hkUint16 m_weldingInfo;
    unsigned char m_weldingType;
    unsigned char m_isExtruded;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

struct hkpCdBody
{
    const hkpShape* getShape() const { return m_shape; }
    const hkTransform& getTransform() const { return *(const hkTransform*)m_motion; }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;

struct hkpCollisionInput
{
    hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

namespace hkpCollideTriangleUtil {
struct PointTriangleDistanceCache
{
    hkReal m_invEdgeLen[3];
    hkReal m_invNormalLen;
    hkReal m_normalLen;
};

}  // namespace hkpCollideTriangleUtil

// hkCollideCapsuleUtilCapsVsTri: up to three closest points; the nearest is one of the first two
void __cdecl FUN_0096e450(const hkVector4* capsAPoints, hkReal capsARadius, const hkVector4* triVertices,
                          hkReal triBRadius, const hkpCollideTriangleUtil::PointTriangleDistanceCache& cache,
                          hkReal collisionTolerance, int searchManifold, hkContactPoint* points);

struct hkpProcessCollisionInput;
struct hkpContactMgr;
struct hkpAgentEntry;
typedef void hkpAgentData;

struct hkpAgent3Input
{
    hkPadSpu<const hkpCdBody*> m_bodyA;
    hkPadSpu<const hkpCdBody*> m_bodyB;
    hkPadSpu<const hkpProcessCollisionInput*> m_input;
    hkPadSpu<hkpContactMgr*> m_contactMgr;
};

struct hkpCapsuleTriangleCache3
{
    hkContactPointId m_contactPointId[3];
    hkpCollideTriangleUtil::PointTriangleDistanceCache m_triangleCache;
};

namespace hkCapsuleTriangleAgent3 {

// sepNormal
// pdb: hkCapsuleTriangleAgent3::sepNormal | hkpCapsuleTriangleAgent3.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: input, entry, agentData, separatingNormalOut
void __cdecl FUN_009c2240(const hkpAgent3Input& input, hkpAgentEntry* entry, hkpAgentData* agentData,
                          hkVector4& separatingNormalOut)
{
    hkpCapsuleTriangleCache3* capsTriCache = reinterpret_cast<hkpCapsuleTriangleCache3*>(agentData);

    const hkpCapsuleShape* capsuleA = static_cast<const hkpCapsuleShape*>(input.m_bodyA->getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(input.m_bodyB->getShape());

    // both shapes in world space
    hkVector4 endPoints[2]; hkVector4Util::transformPoints(input.m_bodyA->getTransform(), capsuleA->getVertices(), 2, endPoints);
    hkVector4 triVertices[3]; hkVector4Util::transformPoints(input.m_bodyB->getTransform(), triB->getVertices(), 3, triVertices);

    int searchManifold = 0;

    hkContactPoint points[3]; FUN_0096e450(endPoints, capsuleA->getRadius(), triVertices, triB->getRadius(), capsTriCache->m_triangleCache, HK_REAL_MAX, searchManifold, points);

    hkReal dist0 = points[0].getDistance();
    hkReal dist1 = points[1].getDistance();
    if (dist0 < dist1)
    {
        separatingNormalOut = points[0].getSeparatingNormal();
    }
    else
    {
        separatingNormalOut = points[1].getSeparatingNormal();
    }
}

}  // namespace hkCapsuleTriangleAgent3

}  // namespace f3m_009c2240
}   // namespace f3m_009c2240

// @f3 0x009dc3d0 (community match, verified in this file)
#include <math.h>
namespace f3m_009dc3d0 {

// 0x009dc3d0: sets up the two rotation frames of a ragdoll limits constraint from axes given in the space of each
// body (hkpRagdollLimitsData::setInBodySpace in Havok terms). For each body the twist axis and the plane axis are
// copied and normalized, and their cross product completes the frame.

namespace f3m_009dc3d0 {

typedef float hkReal;

inline hkReal hkSqrt(hkReal r) { return sqrtf(r); }
inline hkReal hkSqrtInverse(hkReal r) { return 1.0f / hkSqrt(r); }

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void mul4(hkReal rs)
    {
        hkReal s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline hkReal lengthSquared3() const
    {
        return (x * x) + (y * y) + (z * z);
    }
    // 1 / length, or 0 for a zero vector
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = lengthSquared3();
        return l2 ? hkSqrtInverse(l2) : 0;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
};

// constraint atom holding one frame per body
struct hkpSetLocalRotationsConstraintAtom
{
    unsigned short m_type;
    hkRotation m_rotationA;
    hkRotation m_rotationB;
};

struct hkpRagdollLimitsData
{
    // columns of each frame
    enum Axis
    {
        AXIS_TWIST = 0,
        AXIS_PLANES = 1,
        AXIS_CROSS_PRODUCT = 2
    };

    void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_userData;
    hkpSetLocalRotationsConstraintAtom m_rotations;

    void FUN_009dc3d0(const hkVector4& planeAxisA, const hkVector4& planeAxisB, const hkVector4& twistAxisA, const hkVector4& twistAxisB);
};

void hkpRagdollLimitsData::FUN_009dc3d0(const hkVector4& planeAxisA, const hkVector4& planeAxisB, const hkVector4& twistAxisA, const hkVector4& twistAxisB)
{
    hkVector4* baseA = &m_rotations.m_rotationA.getColumn(0);
    baseA[AXIS_TWIST] = twistAxisA; baseA[AXIS_TWIST].normalize3();
    baseA[AXIS_PLANES] = planeAxisA; baseA[AXIS_PLANES].normalize3();
    baseA[AXIS_CROSS_PRODUCT].setCross(baseA[AXIS_TWIST], baseA[AXIS_PLANES]);

    hkVector4* baseB = &m_rotations.m_rotationB.getColumn(0);
    baseB[AXIS_TWIST] = twistAxisB; baseB[AXIS_TWIST].normalize3();
    baseB[AXIS_PLANES] = planeAxisB; baseB[AXIS_PLANES].normalize3();
    baseB[AXIS_CROSS_PRODUCT].setCross(baseB[AXIS_TWIST], baseB[AXIS_PLANES]);
}

}
}   // namespace f3m_009dc3d0

// @f3 0x009dcdc0 (community match, verified in this file)
#include <math.h>
namespace f3m_009dcdc0 {

// 0x009dcdc0: sets up the two body frames of a limited hinge constraint from pivots and axes given in the space of
// each body (hkpLimitedHingeConstraintData::setInBodySpace in Havok terms). For each body the pivot becomes the
// frame's origin, the hinge axis and its perpendicular are copied and normalized, and their cross product completes
// the frame.

namespace f3m_009dcdc0 {

typedef float hkReal;

inline hkReal hkSqrt(hkReal r) { return sqrtf(r); }
inline hkReal hkSqrtInverse(hkReal r) { return 1.0f / hkSqrt(r); }

// four floats, plain x87 version
struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void mul4(hkReal rs)
    {
        hkReal s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline hkReal lengthSquared3() const
    {
        return (x * x) + (y * y) + (z * z);
    }
    // 1 / length, or 0 for a zero vector
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = lengthSquared3();
        return l2 ? hkSqrtInverse(l2) : 0;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    // this = v1 x v2, w = 0
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
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

    __forceinline hkVector4& getColumn(int i) { return (&m_rotation.m_col0)[i]; }
    __forceinline hkVector4& getTranslation() { return m_translation; }
};

// constraint atom holding one frame per body
struct hkpSetLocalTransformsConstraintAtom
{
    unsigned short m_type;
    hkTransform m_transformA;
    hkTransform m_transformB;
};

struct hkpLimitedHingeConstraintData
{
    void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_userData;
    hkpSetLocalTransformsConstraintAtom m_transforms;

    void FUN_009dcdc0(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axisA, const hkVector4& axisB, const hkVector4& axisAPerp, const hkVector4& axisBPerp);
};

void hkpLimitedHingeConstraintData::FUN_009dcdc0(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axisA, const hkVector4& axisB, const hkVector4& axisAPerp, const hkVector4& axisBPerp)
{
    m_transforms.m_transformA.getTranslation() = pivotA;
    m_transforms.m_transformB.getTranslation() = pivotB;

    hkVector4* baseA = &m_transforms.m_transformA.getColumn(0);
    baseA[0] = axisA; baseA[0].normalize3();
    baseA[1] = axisAPerp; baseA[1].normalize3();
    baseA[2].setCross(baseA[0], baseA[1]);

    hkVector4* baseB = &m_transforms.m_transformB.getColumn(0);
    baseB[0] = axisB; baseB[0].normalize3();
    baseB[1] = axisBPerp; baseB[1].normalize3();
    baseB[2].setCross(baseB[0], baseB[1]);
}

}
}   // namespace f3m_009dcdc0

// @f3 0x009c0630 (community match, verified in this file)
namespace f3m_009c0630 {
struct QSimd
{
    float m_real;
    __forceinline operator float() const { return m_real; }
};

struct __declspec(align(16)) QVec4
{
    float x, y, z, w;

    __forceinline void addMul4(const QVec4& a, const float& r)
    {
        x += a.x * r;
        y += a.y * r;
        z += a.z * r;
        w += a.w * r;
    }
    __forceinline QSimd getSimdAt(int i) const
    {
        QVec4 t;
        t.setBroadcast(*this, i);
        QSimd r;
        r.m_real = t.x;
        return r;
    }
    __forceinline void addMul4s(const QSimd& r, const QVec4& a)
    {
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setBroadcast(const QVec4& a, int i)
    {
        float v = (&a.x)[i];
        x = v; y = v; z = v; w = v;
    }
    __forceinline void addMul4v(const QVec4& a, const QVec4& b)
    {
        for (int i = 0; i < 4; i++)
            (&x)[i] += (&a.x)[i] * (&b.x)[i];
    }
    __forceinline void negate3()
    {
        x = -x;
        y = -y;
        z = -z;
    }
    __forceinline void setNeg3(const QVec4& a)
    {
        x = -a.x;
        y = -a.y;
        z = -a.z;
        w = a.w;
    }
};

struct QRootCdPoint
{
    QVec4 m_position;
    QVec4 m_normal;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct QGskOut
{
    QRootCdPoint* m_firstFree;
    int unk04;
    int unk08;
    int unk0C;
    QRootCdPoint m_points[256];
    QVec4 unk3010;
    QVec4 unk3020;
    float unk3030;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_vertices[4];
    unsigned char m_dimA;
    unsigned char m_dimB;
    unsigned char m_lo : 4;
    unsigned char m_hi : 4;
};

struct QSymAgent
{
    void FUN_009c01f0(void* a, void* b, void* c, QGskOut* out);
    void FUN_009c0630(void* a, void* b, void* c, QGskOut* out);
};

// pdb: hkpSymmetricAgentLinearCast<hkpMultiRayConvexAgent>::processCollision | hkpMultiRayConvexAgent.obj | fnv360_0822_debug, objrun, high
// pdb params: bodyA, bodyB, input, result
void QSymAgent::FUN_009c0630(void* a, void* b, void* c, QGskOut* out)
{
    float oldDist = out->unk3030;
    QRootCdPoint* p = out->m_firstFree;
    FUN_009c01f0(b, a, c, out);
    for (; p < out->m_firstFree; p++)
    {
        p->m_position.addMul4s(p->m_normal.getSimdAt(3), p->m_normal);
        p->m_normal.setNeg3(p->m_normal);
    }
    if (oldDist != out->unk3030)
    {
        out->unk3020.negate3();
        unsigned char tn = out->m_lo;
        out->m_lo = out->m_hi;
        out->m_hi = tn;
        unsigned char t = out->m_dimA;
        out->m_dimA = out->m_dimB;
        out->m_dimB = t;
        int i = out->m_dimA + out->m_dimB - 1;
        unsigned short v = out->m_vertices[0];
        out->m_vertices[0] = out->m_vertices[i];
        out->m_vertices[i] = v;
        if ((out->m_dimA & out->m_dimB) == 2)
        {
            unsigned short v1 = out->m_vertices[1];
            out->m_vertices[1] = out->m_vertices[2];
            out->m_vertices[2] = v1;
        }
    }
}
}   // namespace f3m_009c0630

// @f3 0x009c1070 (community match, verified in this file)
namespace f3m_009c1070 {
// 0x009c1070: hkpMultiSphereTriangleAgent::getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpCollisionInput& input, hkpCdPointCollector& collector) of Havok 5.5.0 (hkpCollide, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Takes the triangle's vertices and the multi sphere's spheres to world space, asks the triangle utility for the
// closest point of each sphere and hands every point that is within the radii plus the tolerance to the
// collector, with the two bodies. A timer brackets it.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector helpers, the
// transform's copy, transformPoints, the contact point's accessors, the timer command) follow the SDK's inline
// code for the x87 build, as in our verified 0x009c0a30 (getPenetrations of the same agent). The function's own
// body is written from the game's code.
// The timer reads the clock with the project's accepted two-instruction block (kit/compiler_tips.md, "Timer slot
// still off"), as the SDK's own inline timer code does; it is the only difference from the plain counter-read
// source.
namespace f3m_009c1070 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef float hkReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

extern unsigned int DAT_0116913c;  // thread-local slot of the thread's hkMonitorStream

struct hkMonitorStream
{
    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
    };

    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    char* getEnd() { return m_end.val(); }
    char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    bool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
};

// one timer command in the thread's monitor stream: the name, then the low half of the time stamp counter
__forceinline void hkTimerCommand(const char* name)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* command = (hkMonitorStream::TimerCommand*)stream.getEnd();
        command->m_commandAndMonitor = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        command->m_time0 = ticks;
        stream.setEnd((char*)(command + 1));
    }
}

struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    inline void operator=(const hkVector4& v);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

inline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
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
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline const hkReal& operator()(int row, int column) const { return m_rotation(row, column); }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

// the translation is the rotation's fourth column
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
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

namespace hkVector4Util {
// transforms numVectors points, the last one first; the transform is copied so that the output may alias it
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                   hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

struct hkpShape
{
    virtual ~hkpShape();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

// up to eight spheres, the radius in each w
struct hkpMultiSphereShape : hkpShape
{
    __forceinline const hkVector4* getSpheres() const { return &m_spheres[0]; }
    __forceinline int getNumSpheres() const { return m_numSpheres; }

    enum
    {
        MAX_SPHERES = 8
    };

    int m_numSpheres;
    hkVector4 m_spheres[8];
};

struct hkpTriangleShape : hkpShape
{
    __forceinline hkReal getRadius() const { return m_radius; }
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    hkReal m_radius;
    hkUint16 m_weldingInfo;
    unsigned char m_weldingType;
    unsigned char m_isExtruded;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

struct hkpCdBody
{
    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;

struct hkpCollisionInput
{
    __forceinline hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

struct hkContactPoint
{
    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

// a contact point with the two bodies it belongs to
struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

struct hkpCdPointCollector
{
    virtual ~hkpCdPointCollector();
    virtual void addCdPoint(const hkpCdPoint& point) = 0;

    hkReal m_earlyOutDistance;
};

struct hkReferencedObject
{
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpContactMgr;

struct hkpCollisionAgent : hkReferencedObject
{
    hkpContactMgr* m_contactMgr;
};

struct hkpIterativeLinearCastAgent : hkpCollisionAgent
{
};

namespace hkpCollideTriangleUtil {
struct ClosestPointTriangleCache
{
    hkReal m_QQ;
    hkReal m_RR;
    hkReal m_QR;
    hkReal m_invTriNormal;
};

struct ClosestPointTriangleResult
{
    hkVector4 hitDirection;
    hkPadSpu<hkReal> distance;
};

enum ClosestPointTriangleStatus
{
    HIT_TRIANGLE_FACE = 0,
    HIT_TRIANGLE_EDGE
};

// closestPointTriangle
ClosestPointTriangleStatus __cdecl hkpCollideTriangleUtil_closestPointTriangle(const hkVector4& position, const hkVector4* tri,
                                                const ClosestPointTriangleCache& cache,
                                                ClosestPointTriangleResult& result);
}  // namespace hkpCollideTriangleUtil

struct hkpMultiSphereTriangleAgent : hkpIterativeLinearCastAgent
{
    // getClosestPoints
    void hkpMultiSphereTriangleAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
                      hkpCdPointCollector& collector);

    hkpCollideTriangleUtil::ClosestPointTriangleCache m_closestPointTriangleCache;
};

// pdb: hkpMultiSphereTriangleAgent::getClosestPoints | hkpMultiSphereTriangleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpMultiSphereTriangleAgent::hkpMultiSphereTriangleAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                               const hkpCollisionInput& input, hkpCdPointCollector& collector)
{
    hkTimerCommand("TtMultiSphereTriangle");

    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());

    hkVector4 triVertices[3];
    const hkVector4* vertices = triB->getVertices();
    hkVector4Util::transformPoints(bodyB.getTransform(), vertices, 3, &triVertices[0]);

    const hkVector4* localSpheres = msA->getSpheres();
    hkVector4 worldSpheres[hkpMultiSphereShape::MAX_SPHERES];
    const int nsphere = msA->getNumSpheres();
    hkVector4Util::transformPoints(bodyA.getTransform(), localSpheres, nsphere, &worldSpheres[0]);

    hkpCdPoint event(bodyA, bodyB);

    for (int i = 0; i < nsphere; ++i)
    {
        const hkVector4& sphere = worldSpheres[i];
        const hkReal sphereRadius = localSpheres[i](3);
        const hkReal radiusSum = sphereRadius + triB->getRadius();

        hkpCollideTriangleUtil::ClosestPointTriangleResult cpResult;
        hkpCollideTriangleUtil::hkpCollideTriangleUtil_closestPointTriangle(sphere, &triVertices[0], m_closestPointTriangleCache, cpResult);

        if (cpResult.distance < radiusSum + input.getTolerance())
        {
            event.m_contact.getPosition().setAddMul4(sphere, cpResult.hitDirection,
                                                     triB->getRadius() - cpResult.distance);
            event.m_contact.getSeparatingNormal() = cpResult.hitDirection;
            event.m_contact.setDistance(cpResult.distance - radiusSum);
            collector.addCdPoint(event);
        }
    }

    hkTimerCommand("Et");
}

}  // namespace f3m_009c1070
}   // namespace f3m_009c1070

// @f3 0x009c14a0 (community match, verified in this file)
namespace f3m_009c14a0 {
// 0x009c14a0: hkpMultiSphereTriangleAgent::staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpCollisionInput& input, hkpCdPointCollector& collector) of Havok 5.5.0 (hkpCollide, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The static form of the multi sphere against triangle query: takes the triangle's vertices and the spheres to
// world space, sets up the closest-point cache from the triangle's own vertices, asks the triangle utility for the closest
// point of each sphere and hands every point within the radii plus the tolerance to the collector. A timer
// brackets it.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector helpers, the
// transform's copy, transformPoints, the contact point's accessors, the timer commands as the SDK's macros expand)
// follow the SDK's inline code for the x87 build. The function's own body is written from the game's code; local
// names and the order of the statements follow the debug records of the SDK's library object.
// The timer reads the clock with the project's accepted two-instruction block (kit/compiler_tips.md, "Timer slot
// still off"), as the SDK's own inline timer code does; it is the only difference from the plain counter-read
// source.
namespace f3m_009c14a0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef float hkReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

extern unsigned int DAT_0116913c;  // thread-local slot of the thread's hkMonitorStream

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

struct hkMonitorStream
{
    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : Command
    {
        // the low half of the time stamp counter
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }

        hkUint32 m_time0;
        hkUint32 m_time1;
    };

    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    __forceinline char* getEnd() { return m_end.val(); }
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    __forceinline hkBool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
};

struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    inline void operator=(const hkVector4& v);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

inline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
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
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline const hkReal& operator()(int row, int column) const { return m_rotation(row, column); }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

// the translation is the rotation's fourth column
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
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

namespace hkVector4Util {
// transforms numVectors points, the last one first; the transform is copied so that the output may alias it
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                   hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

struct hkpShape
{
    virtual ~hkpShape();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

// up to eight spheres, the radius in each w
struct hkpMultiSphereShape : hkpShape
{
    __forceinline const hkVector4* getSpheres() const { return &m_spheres[0]; }
    __forceinline int getNumSpheres() const { return m_numSpheres; }

    enum
    {
        MAX_SPHERES = 8
    };

    int m_numSpheres;
    hkVector4 m_spheres[8];
};

struct hkpTriangleShape : hkpShape
{
    __forceinline hkReal getRadius() const { return m_radius; }
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    hkReal m_radius;
    hkUint16 m_weldingInfo;
    unsigned char m_weldingType;
    unsigned char m_isExtruded;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

struct hkpCdBody
{
    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;

struct hkpCollisionInput
{
    __forceinline hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

struct hkContactPoint
{
    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

// a contact point with the two bodies it belongs to
struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

struct hkpCdPointCollector
{
    virtual ~hkpCdPointCollector();
    virtual void addCdPoint(const hkpCdPoint& point) = 0;

    hkReal m_earlyOutDistance;
};

struct hkReferencedObject
{
    virtual ~hkReferencedObject();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpContactMgr;

struct hkpCollisionAgent : hkReferencedObject
{
    hkpContactMgr* m_contactMgr;
};

struct hkpIterativeLinearCastAgent : hkpCollisionAgent
{
};

namespace hkpCollideTriangleUtil {
struct ClosestPointTriangleCache
{
    hkReal m_QQ;
    hkReal m_RR;
    hkReal m_QR;
    hkReal m_invTriNormal;
};

struct ClosestPointTriangleResult
{
    hkVector4 hitDirection;
    hkPadSpu<hkReal> distance;
};

enum ClosestPointTriangleStatus
{
    HIT_TRIANGLE_FACE = 0,
    HIT_TRIANGLE_EDGE
};

// setupClosestPointTriangleCache
void __cdecl FUN_0096fbc0(const hkVector4* tri, ClosestPointTriangleCache& cache);

// closestPointTriangle
ClosestPointTriangleStatus __cdecl hkpCollideTriangleUtil_closestPointTriangle(const hkVector4& position, const hkVector4* tri,
                                                const ClosestPointTriangleCache& cache,
                                                ClosestPointTriangleResult& result);
}  // namespace hkpCollideTriangleUtil

struct hkpMultiSphereTriangleAgent : hkpIterativeLinearCastAgent
{
    // staticGetClosestPoints
    static void __cdecl hkpMultiSphereTriangleAgent_staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
                                     hkpCdPointCollector& collector);

    hkpCollideTriangleUtil::ClosestPointTriangleCache m_closestPointTriangleCache;
};

// pdb: hkpMultiSphereTriangleAgent::staticGetClosestPoints | hkpMultiSphereTriangleAgent.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel) + skyrim(ustr_rel), high
void __cdecl hkpMultiSphereTriangleAgent::hkpMultiSphereTriangleAgent_staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                       const hkpCollisionInput& input, hkpCdPointCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtMultiSphereTriangle";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());

    hkVector4 triVertices[3];
    const hkVector4* vertices = triB->getVertices();
    hkVector4Util::transformPoints(bodyB.getTransform(), vertices, 3, &triVertices[0]);

    const hkVector4* localSpheres = msA->getSpheres();
    hkVector4 worldSpheres[hkpMultiSphereShape::MAX_SPHERES];
    const int nsphere = msA->getNumSpheres();
    hkVector4Util::transformPoints(bodyA.getTransform(), localSpheres, nsphere, &worldSpheres[0]);

    hkpCdPoint event(bodyA, bodyB);

    hkpCollideTriangleUtil::ClosestPointTriangleCache closestPointTriangleCache;
    hkpCollideTriangleUtil::FUN_0096fbc0(triB->getVertices(), closestPointTriangleCache);

    for (int i = 0; i < nsphere; ++i)
    {
        const hkVector4& sphere = worldSpheres[i];
        const hkReal sphereRadius = localSpheres[i](3);
        const hkReal radiusSum = sphereRadius + triB->getRadius();

        hkpCollideTriangleUtil::ClosestPointTriangleResult cptr;
        hkpCollideTriangleUtil::hkpCollideTriangleUtil_closestPointTriangle(sphere, &triVertices[0], closestPointTriangleCache, cptr);

        if (cptr.distance < radiusSum + input.getTolerance())
        {
            event.m_contact.getPosition().setAddMul4(sphere, cptr.hitDirection,
                                                     triB->getRadius() - cptr.distance);
            event.m_contact.getSeparatingNormal() = cptr.hitDirection;
            event.m_contact.setDistance(cptr.distance - radiusSum);
            collector.addCdPoint(event);
        }
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}  // namespace f3m_009c14a0
}   // namespace f3m_009c14a0

// @f3 0x009c1ae0 (community match, verified in this file)
namespace f3m_009c1ae0 {
// 0x009c1ae0: hkpMultiSphereTriangleAgent::processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result) of Havok 5.5.0 (hkpCollide, compiled
// with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Takes the triangle's vertices and the multi sphere's spheres to world space and asks the triangle utility for
// the closest point of each sphere. A sphere within the radii plus the tolerance gets a contact point in the
// output and keeps one id with the contact manager (added on first touch); a sphere that has parted gives its id
// back. The ids are kept in the reverse order of the spheres. A timer brackets it.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector helpers, the
// transform's copy, transformPoints, the contact point's accessors, the output's reserve and commit, the contact
// manager's wrappers, the timer command) follow the SDK's inline code for the x87 build, as in our verified
// 0x009c0a30 (getPenetrations of the same agent). The function's own body is written from the game's code.
// The timer reads the clock with the project's accepted two-instruction block (kit/compiler_tips.md, "Timer slot
// still off"), as the SDK's own inline timer code does; it is the only difference from the plain counter-read
// source.
namespace f3m_009c1ae0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef float hkReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

extern unsigned int DAT_0116913c;  // thread-local slot of the thread's hkMonitorStream

struct hkMonitorStream
{
    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
    };

    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    char* getEnd() { return m_end.val(); }
    char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    bool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
};

// one timer command in the thread's monitor stream: the name, then the low half of the time stamp counter
__forceinline void hkTimerCommand(const char* name)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* command = (hkMonitorStream::TimerCommand*)stream.getEnd();
        command->m_commandAndMonitor = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        command->m_time0 = ticks;
        stream.setEnd((char*)(command + 1));
    }
}

struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    inline void operator=(const hkVector4& v);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

inline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
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
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline const hkReal& operator()(int row, int column) const { return m_rotation(row, column); }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

// the translation is the rotation's fourth column
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
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

namespace hkVector4Util {
// transforms numVectors points, the last one first; the transform is copied so that the output may alias it
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                   hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

struct hkpShape
{
    virtual ~hkpShape();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    __forceinline hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

// up to eight spheres, the radius in each w
struct hkpMultiSphereShape : hkpShape
{
    __forceinline const hkVector4* getSpheres() const { return &m_spheres[0]; }
    __forceinline int getNumSpheres() const { return m_numSpheres; }

    enum
    {
        MAX_SPHERES = 8
    };

    int m_numSpheres;
    hkVector4 m_spheres[8];
};

struct hkpTriangleShape : hkpConvexShape
{
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    hkUint16 m_weldingInfo;
    unsigned char m_weldingType;
    unsigned char m_isExtruded;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

struct hkpCdBody
{
    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;

struct hkpCollisionInput
{
    __forceinline hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

struct hkpProcessCollisionInput : hkpCollisionInput
{
};

struct hkContactPoint
{
    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

// one contact point of the output with the id the contact manager gave it
struct hkpProcessCdPoint
{
    hkContactPoint m_contact;
    hkPadSpu<hkUint32> m_contactPointId;
};

struct hkpConstraintOwner;
typedef hkpConstraintOwner hkCollisionConstraintOwner;

struct hkpProcessCollisionOutput
{
    __forceinline hkpProcessCdPoint* reserveContactPoints(int numberOfPoints) { return m_firstFreeContactPoint; }
    __forceinline void commitContactPoints(int numberOfPoints)
    {
        m_firstFreeContactPoint = m_firstFreeContactPoint + numberOfPoints;
    }
    __forceinline void abortContactPoints(int numberOfPoints) {}

    hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
    hkPadSpu<hkpConstraintOwner*> m_constraintOwner;
};

typedef hkUint16 hkContactPointId;
enum { HK_INVALID_CONTACT_POINT = 0xffff };

struct hkStatisticsCollector;
struct hkClass;
struct hkpGskCache;

struct hkReferencedObject
{
    virtual ~hkReferencedObject();
    virtual void calcStatistics(hkStatisticsCollector* collector) const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpContactMgr : hkReferencedObject
{
    __forceinline hkContactPointId addContactPoint(const hkpCdBody& a, const hkpCdBody& b,
                                                   const hkpProcessCollisionInput& input,
                                                   hkpProcessCollisionOutput& output, const hkpGskCache* contactCache,
                                                   hkContactPoint& cp)
    {
        return addContactPointImpl(a, b, input, output, contactCache, cp);
    }
    __forceinline void removeContactPoint(hkContactPointId cpId, hkCollisionConstraintOwner& constraintOwner)
    {
        removeContactPointImpl(cpId, constraintOwner);
    }

    virtual hkContactPointId addContactPointImpl(const hkpCdBody& a, const hkpCdBody& b,
                                                 const hkpProcessCollisionInput& input,
                                                 hkpProcessCollisionOutput& output, const hkpGskCache* contactCache,
                                                 hkContactPoint& cp) = 0;
    virtual int reserveContactPointsImpl(int numPoints) = 0;
    virtual void removeContactPointImpl(hkContactPointId cpId, hkCollisionConstraintOwner& constraintOwner) = 0;
};

struct hkpCollisionAgent : hkReferencedObject
{
    hkpContactMgr* m_contactMgr;
};

struct hkpIterativeLinearCastAgent : hkpCollisionAgent
{
};

namespace hkpCollideTriangleUtil {
struct ClosestPointTriangleCache
{
    hkReal m_QQ;
    hkReal m_RR;
    hkReal m_QR;
    hkReal m_invTriNormal;
};

struct ClosestPointTriangleResult
{
    hkVector4 hitDirection;
    hkPadSpu<hkReal> distance;
};

// closestPointTriangle
void __cdecl hkpCollideTriangleUtil_closestPointTriangle(const hkVector4& position, const hkVector4* tri, const ClosestPointTriangleCache& cache,
                          ClosestPointTriangleResult& result);
}  // namespace hkpCollideTriangleUtil

struct hkpMultiSphereTriangleAgent : hkpIterativeLinearCastAgent
{
    // processCollision
    void hkpMultiSphereTriangleAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input,
                      hkpProcessCollisionOutput& result);

    hkpCollideTriangleUtil::ClosestPointTriangleCache m_closestPointTriangleCache;
    hkContactPointId m_contactPointId[hkpMultiSphereShape::MAX_SPHERES];
};

// pdb: hkpMultiSphereTriangleAgent::processCollision | hkpMultiSphereTriangleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpMultiSphereTriangleAgent::hkpMultiSphereTriangleAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                               const hkpProcessCollisionInput& input,
                                               hkpProcessCollisionOutput& result)
{
    hkTimerCommand("TtMultiSphereTri");

    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());

    hkVector4 triVertices[3];
    const hkVector4* vertices = triB->getVertices();
    hkVector4Util::transformPoints(bodyB.getTransform(), vertices, 3, &triVertices[0]);

    const hkVector4* localSpheres = msA->getSpheres();
    hkVector4 worldSpheres[hkpMultiSphereShape::MAX_SPHERES];
    const int nsphere = msA->getNumSpheres();
    hkVector4Util::transformPoints(bodyA.getTransform(), localSpheres, nsphere, &worldSpheres[0]);

    const hkVector4* sphere = &worldSpheres[0];
    const hkVector4* localSphere = localSpheres;
    for (int j = nsphere - 1; j >= 0; sphere++, localSphere++, j--)
    {
        const hkReal sphereRadius = (*localSphere)(3);
        const hkReal radiusSum = sphereRadius + triB->getRadius();

        hkpCollideTriangleUtil::ClosestPointTriangleResult cpResult;
        hkpCollideTriangleUtil::hkpCollideTriangleUtil_closestPointTriangle(*sphere, &triVertices[0], m_closestPointTriangleCache, cpResult);

        if (cpResult.distance < radiusSum + input.getTolerance())
        {
            hkpProcessCdPoint& point = *result.reserveContactPoints(1);
            point.m_contact.getPosition().setAddMul4(*sphere, cpResult.hitDirection,
                                                     triB->getRadius() - cpResult.distance);
            point.m_contact.getSeparatingNormal() = cpResult.hitDirection;
            point.m_contact.setDistance(cpResult.distance - radiusSum);

            if (m_contactPointId[j] == HK_INVALID_CONTACT_POINT)
            {
                m_contactPointId[j] = m_contactMgr->addContactPoint(bodyA, bodyB, input, result, 0, point.m_contact);
            }

            if (m_contactPointId[j] != HK_INVALID_CONTACT_POINT)
            {
                result.commitContactPoints(1);
                point.m_contactPointId = m_contactPointId[j];
            }
            else
            {
                result.abortContactPoints(1);
            }
        }
        else
        {
            if (m_contactPointId[j] != HK_INVALID_CONTACT_POINT)
            {
                m_contactMgr->removeContactPoint(m_contactPointId[j], *result.m_constraintOwner.val());
                m_contactPointId[j] = HK_INVALID_CONTACT_POINT;
            }
        }
    }

    hkTimerCommand("Et");
}

}  // namespace f3m_009c1ae0
}   // namespace f3m_009c1ae0

// @f3 0x009c2b90 (community match, verified in this file)
namespace f3m_009c2b90 {
// FUN_009c2b90: transform the two points of shape A and the three points of
// shape B by their local transforms, then hand the world-space points to the
// collision routine.
struct __declspec(align(16)) V4 { float x, y, z, w; };

struct Shape {
    int unk00, unk04, unk08, unk0c;
    float unk10;
    int unk14, unk18, unk1c;
    V4 pts[3];
};

struct Wrap {
    Shape* shape;
    int unk04;
    V4* mat;
};

struct P2 { int unk00; float unk04; };

extern "C" void FUN_0096e450(V4* a, float ra, V4* b, float rb, int a5, float a6, int a7, int a8);

// pdb: hkpCapsuleTriangleAgent::getClosestPointsPublic | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, cache, searchManifold, points
void FUN_009c2b90(Wrap* a, Wrap* b, P2* p2, int p3, int p4, int p5)
{
    Shape* sa = a->shape;
    Shape* sb = b->shape;
    V4* ma = a->mat;

    V4 outA[2];
    {
        V4 c0 = ma[0], c1 = ma[1], c2 = ma[2], c3 = ma[3];
        float A0 = c0.x, A1 = c0.y, A2 = c0.z;
        float B0 = c1.x, B1 = c1.y, B2 = c1.z;
        float C0 = c2.x, C1 = c2.y, C2 = c2.z;
        float D0 = c3.x, D1 = c3.y, D2 = c3.z;
        int i = 1;
        do {
            const V4& p = sa->pts[i];
            float vx = p.x;
            float vy = p.y;
            float vz = p.z;
            V4& o = outA[i];
            o.x = vx*A0 + vy*B0 + vz*C0 + D0;
            o.y = vx*A1 + vy*B1 + vz*C1 + D1;
            o.z = vx*A2 + vy*B2 + vz*C2 + D2;
            o.w = 0.0f;
        } while (--i >= 0);
    }

    V4 outB[3];
    {
        V4* mb = b->mat;
        V4 c0 = mb[0], c1 = mb[1], c2 = mb[2], c3 = mb[3];
        float A0 = c0.x, A2 = c0.z;
        float B0 = c1.x, B2 = c1.z;
        float C0 = c2.x, C2 = c2.z;
        float D0 = c3.x, D1 = c3.y, D2 = c3.z;
        int i = 2;
        do {
            const V4& p = sb->pts[i];
            float vx = p.x;
            float vy = p.y;
            float vz = p.z;
            V4& o = outB[i];
            o.x = vx*A0 + vy*B0 + vz*C0 + D0;
            o.y = vy**(const volatile float*)&c1.y + vx**(const volatile float*)&c0.y
                + vz**(const volatile float*)&c2.y + D1;
            o.z = vx*A2 + vy*B2 + vz*C2 + D2;
            o.w = 0.0f;
        } while (--i >= 0);
    }

    FUN_0096e450(&outA[0], sa->unk10, &outB[0], sb->unk10, p3, p2->unk04, p4, p5);
}
}   // namespace f3m_009c2b90

// @f3 0x009c2e20 (community match, verified in this file)
namespace f3m_009c2e20 {
// 0x009c2e20: hkpCapsuleTriangleAgent::getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpCollisionInput& input, hkpCollideTriangleUtil::PointTriangleDistanceCache& cache,
// hkContactPoint& cpoint) of Havok 5.5.0 (hkpCollide, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Takes the capsule's two end points and the triangle's three vertices to world space, asks the
// capsule-triangle utility for the closest points and hands back the nearer of the first two when it lies
// within the tolerance.
// Class and member names follow the Havok 5.5.0 SDK headers; the vector and transform helpers follow the forms
// of the SDK's inline maths for the x87 build. The function's own body and the bodies of the agent's inline
// helpers are written from the game's code; the helpers' names are the ones the SDK's header declares.
namespace f3m_009c2e20 {

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    inline void operator=(const hkVector4& v);
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

inline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

struct hkMatrix3
{
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline const hkReal& operator()(int row, int column) const { return m_rotation(row, column); }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

// the translation is the rotation's fourth column
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
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

namespace hkVector4Util {
// transforms numVectors points, the last one first; the transform is copied so that the output may alias it
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                   hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

struct hkContactPoint
{
    __forceinline const hkVector4& getPosition() const { return m_position; }
    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline void setPosition(const hkVector4& position) { m_position = position; }
    __forceinline const hkVector4& getSeparatingNormal() const { return m_separatingNormal; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setSeparatingNormal(const hkVector4& separatingNormal) { m_separatingNormal = separatingNormal; }
    __forceinline void set(const hkVector4& position, const hkVector4& normal, hkReal dist)
    {
        m_position = position;
        m_separatingNormal = normal;
        m_separatingNormal(3) = dist;
    }
    hkReal getDistance() const { return m_separatingNormal(3); }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpShape
{
    virtual ~hkpShape();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    inline hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

struct hkpCapsuleShape : hkpConvexShape
{
    inline const hkVector4* getVertices() const { return &m_vertexA; }

    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpTriangleShape : hkpConvexShape
{
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    hkUint16 m_weldingInfo;
    unsigned char m_weldingType;
    unsigned char m_isExtruded;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

struct hkpCdBody
{
    const hkpShape* getShape() const { return m_shape; }
    const hkTransform& getTransform() const { return *(const hkTransform*)m_motion; }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;

struct hkpCollisionInput
{
    hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

namespace hkpCollideTriangleUtil {
struct PointTriangleDistanceCache
{
    hkReal m_invEdgeLen[3];
    hkReal m_invNormalLen;
    hkReal m_normalLen;
};
}  // namespace hkpCollideTriangleUtil

// hkCollideCapsuleUtilCapsVsTri: up to three closest points; the nearest is one of the first two
void __cdecl FUN_0096e450(const hkVector4* capsAPoints, hkReal capsARadius, const hkVector4* triVertices,
                          hkReal triBRadius, const hkpCollideTriangleUtil::PointTriangleDistanceCache& cache,
                          hkReal collisionTolerance, int searchManifold, hkContactPoint* points);

struct hkpCapsuleTriangleAgent
{
    enum ClosestPointResult
    {
        ST_CP_MISS,
        ST_CP_HIT,
    };

    static __forceinline void getClosestPointsInl(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                  const hkpCollisionInput& input,
                                                  hkpCollideTriangleUtil::PointTriangleDistanceCache& cache,
                                                  int searchManifold, hkContactPoint* points);

    static __forceinline ClosestPointResult getClosestPointInternal(
        const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
        hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkContactPoint& cpoint);

    // getClosestPoint
    static ClosestPointResult __cdecl FUN_009c2e20(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                   const hkpCollisionInput& input,
                                                   hkpCollideTriangleUtil::PointTriangleDistanceCache& cache,
                                                   hkContactPoint& cpoint);
};

__forceinline void hkpCapsuleTriangleAgent::getClosestPointsInl(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
    hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, int searchManifold, hkContactPoint* points)
{
    const hkpCapsuleShape* capsuleA = static_cast<const hkpCapsuleShape*>(bodyA.getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());

    hkVector4 endPoints[2];
    hkVector4Util::transformPoints(bodyA.getTransform(), capsuleA->getVertices(), 2, endPoints);

    hkVector4 triVertices[3];
    hkVector4Util::transformPoints(bodyB.getTransform(), triB->getVertices(), 3, triVertices);

    FUN_0096e450(endPoints, capsuleA->getRadius(), triVertices, triB->getRadius(), cache, input.getTolerance(),
                 searchManifold, points);
}

__forceinline hkpCapsuleTriangleAgent::ClosestPointResult hkpCapsuleTriangleAgent::getClosestPointInternal(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
    hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkContactPoint& cpoint)
{
    hkContactPoint points[3];
    getClosestPointsInl(bodyA, bodyB, input, cache, 0, points);

    const hkReal dist0 = points[0].getDistance();
    const hkReal dist1 = points[1].getDistance();
    if (dist0 < dist1)
    {
        if (dist0 < input.getTolerance())
        {
            cpoint = points[0];
            return ST_CP_HIT;
        }
    }
    else
    {
        if (dist1 < input.getTolerance())
        {
            cpoint = points[1];
            return ST_CP_HIT;
        }
    }
    return ST_CP_MISS;
}

// pdb: hkpCapsuleTriangleAgent::getClosestPoint | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, cache, cpoint
hkpCapsuleTriangleAgent::ClosestPointResult __cdecl hkpCapsuleTriangleAgent::FUN_009c2e20(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
    hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkContactPoint& cpoint)
{
    return getClosestPointInternal(bodyA, bodyB, input, cache, cpoint);
}

}  // namespace f3m_009c2e20
}   // namespace f3m_009c2e20

// @f3 0x009c5e70 (community match, verified in this file)
#include <math.h>
namespace f3m_009c5e70 {
// 0x009c5e70: hkpSphereBoxAgent::processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result) of Havok 5.5.0 (hkpCollide, compiled
// with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Finds the closest point between sphere A and box B straight into the output's next free contact point. While
// the two are within the tolerance the agent keeps one contact point with the contact manager (added on first
// touch, committed to the output each step); when they part the point is removed again. A timer brackets it.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector helpers, the contact
// point's accessors, the output's reserve and commit, the contact manager's wrappers, the timer command) follow
// the SDK's inline code for the x87 build. The body of the inline closest-point helper follows the unit's
// verified twin 0x009c6780; the function's own body is written from the game's code.
// The timer reads the clock with the project's accepted two-instruction block (kit/compiler_tips.md, "Timer slot
// still off"), as the SDK's own inline timer code does; it is the only difference from the plain counter-read
// source.

namespace f3m_009c5e70 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

extern unsigned int DAT_0116913c;  // thread-local slot of the thread's hkMonitorStream

namespace hkMath {
__forceinline hkReal fabs(hkReal r) { return hkReal(::fabs(r)); }
__forceinline hkReal sqrt(hkReal r) { return hkReal(::sqrt(r)); }
}  // namespace hkMath

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

struct hkMonitorStream
{
    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
    };

    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    char* getEnd() { return m_end.val(); }
    char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    bool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
};

// one timer command in the thread's monitor stream: the name, then the low half of the time stamp counter
__forceinline void hkTimerCommand(const char* name)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* command = (hkMonitorStream::TimerCommand*)stream.getEnd();
        command->m_commandAndMonitor = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        command->m_time0 = ticks;
        stream.setEnd((char*)(command + 1));
    }
}

struct hkVector4Comparison
{
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_Y = 4,
        MASK_X = 8,
        MASK_XYZ = 14
    };

    __forceinline int anyIsSet(Mask m) const { return m_mask & m; }

    int m_mask;
};

struct hkMatrix3;
struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    // setTransformedInversePos: this = inverse(t) * v
    void FUN_008d2970(const hkTransform& t, const hkVector4& v);

    __forceinline void setAbs4(const hkVector4& v)
    {
        x = hkMath::fabs(v.x);
        y = hkMath::fabs(v.y);
        z = hkMath::fabs(v.z);
        w = hkMath::fabs(v.w);
    }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x < b.x ? a.x : b.x;
        y = a.y < b.y ? a.y : b.y;
        z = a.z < b.z ? a.z : b.z;
        w = a.w < b.w ? a.w : b.w;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline hkVector4Comparison compareLessThanZero4() const
    {
        hkVector4Comparison ret;
        ret.m_mask = ((x < 0) ? hkVector4Comparison::MASK_X : 0) |
                     ((y < 0) ? hkVector4Comparison::MASK_Y : 0) |
                     ((z < 0) ? hkVector4Comparison::MASK_Z : 0) |
                     ((w < 0) ? hkVector4Comparison::MASK_W : 0);
        return ret;
    }
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return x * a.x + y * a.y + z * a.z; }
    __forceinline hkSimdReal length3() const { return hkMath::sqrt(dot3(*this)); }
    __forceinline void mul4(hkSimdRealParameter s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline hkSimdReal normalizeWithLength3()
    {
        hkReal len = length3();
        mul4(1.0f / len);
        return len;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setXYZ(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkMatrix3& r, const hkVector4& v) { _setMul3(r, v); }

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkMatrix3
{
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    const hkReal v0 = v.x;
    const hkReal v1 = v.y;
    const hkReal v2 = v.z;
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    w = 0;
}

namespace hkVector4Util {
// gives each component of inout the sign of the product with the matching component of signv
__forceinline void mulSigns4(hkVector4& inout, const hkVector4& signv)
{
    hkUint32* intp = reinterpret_cast<hkUint32*>(&inout);
    const hkUint32* sign = reinterpret_cast<const hkUint32*>(&signv);
    intp[0] ^= (sign[0] & 0x80000000);
    intp[1] ^= (sign[1] & 0x80000000);
    intp[2] ^= (sign[2] & 0x80000000);
    intp[3] ^= (sign[3] & 0x80000000);
}
}  // namespace hkVector4Util

struct hkpShape
{
    virtual ~hkpShape();

    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    __forceinline hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

struct hkpSphereShape : hkpConvexShape
{
};

struct hkpBoxShape : hkpConvexShape
{
    __forceinline const hkVector4& getHalfExtents() const { return m_halfExtents; }

    hkVector4 m_halfExtents;
};

struct hkpCdBody
{
    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;

struct hkpCollisionInput
{
    __forceinline hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

struct hkContactPoint
{
    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline const hkVector4& getNormal() const { return m_separatingNormal; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setNormal(const hkVector4& normal) { m_separatingNormal.setXYZ(normal); }
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpProcessCollisionInput : hkpCollisionInput
{
};

// one contact point of the output with the id the contact manager gave it
struct hkpProcessCdPoint
{
    hkContactPoint m_contact;
    hkPadSpu<hkUint32> m_contactPointId;
};

struct hkpConstraintOwner;
typedef hkpConstraintOwner hkCollisionConstraintOwner;

struct hkpProcessCollisionOutput
{
    __forceinline hkpProcessCdPoint* reserveContactPoints(int numberOfPoints) { return m_firstFreeContactPoint; }
    __forceinline void commitContactPoints(int numberOfPoints)
    {
        m_firstFreeContactPoint = m_firstFreeContactPoint + numberOfPoints;
    }
    __forceinline void abortContactPoints(int numberOfPoints) {}

    hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
    hkPadSpu<hkpConstraintOwner*> m_constraintOwner;
};

typedef unsigned short hkUint16;
typedef hkUint16 hkContactPointId;
enum { HK_INVALID_CONTACT_POINT = 0xffff };

struct hkStatisticsCollector;
struct hkClass;
struct hkpGskCache;

struct hkReferencedObject
{
    virtual ~hkReferencedObject();
    virtual void calcStatistics(hkStatisticsCollector* collector) const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
};

struct hkpContactMgr : hkReferencedObject
{
    __forceinline hkContactPointId addContactPoint(const hkpCdBody& a, const hkpCdBody& b,
                                                   const hkpProcessCollisionInput& input,
                                                   hkpProcessCollisionOutput& output, const hkpGskCache* contactCache,
                                                   hkContactPoint& cp)
    {
        return addContactPointImpl(a, b, input, output, contactCache, cp);
    }
    __forceinline void removeContactPoint(hkContactPointId cpId, hkCollisionConstraintOwner& constraintOwner)
    {
        removeContactPointImpl(cpId, constraintOwner);
    }

    virtual hkContactPointId addContactPointImpl(const hkpCdBody& a, const hkpCdBody& b,
                                                 const hkpProcessCollisionInput& input,
                                                 hkpProcessCollisionOutput& output, const hkpGskCache* contactCache,
                                                 hkContactPoint& cp) = 0;
    virtual int reserveContactPointsImpl(int numPoints) = 0;
    virtual void removeContactPointImpl(hkContactPointId cpId, hkCollisionConstraintOwner& constraintOwner) = 0;
};

struct hkpCollisionAgent : hkReferencedObject
{
    hkpContactMgr* m_contactMgr;
};

struct hkpIterativeLinearCastAgent : hkpCollisionAgent
{
};

struct hkpSphereBoxAgent : hkpIterativeLinearCastAgent
{
    static __forceinline hkBool getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                const hkpCollisionInput& input, hkContactPoint& contactOut);

    // processCollision
    void hkpSphereBoxAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input,
                      hkpProcessCollisionOutput& result);

    hkContactPointId m_contactPointId;
};

__forceinline hkBool hkpSphereBoxAgent::getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                        const hkpCollisionInput& input, hkContactPoint& contactOut)
{
    const hkVector4& posA = bodyA.getTransform().getTranslation();
    hkVector4 posLocalB;
    posLocalB.FUN_008d2970(bodyB.getTransform(), posA);

    const hkpBoxShape* boxB = static_cast<const hkpBoxShape*>(bodyB.getShape());
    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.getShape());

    hkVector4 absPosB;
    absPosB.setAbs4(posLocalB);
    hkVector4 clippedAbsPos;
    clippedAbsPos.setMin4(absPosB, boxB->getHalfExtents());
    hkVector4 delta;
    delta.setSub4(clippedAbsPos, absPosB);

    hkReal distance;
    if (delta.compareLessThanZero4().anyIsSet(hkVector4Comparison::MASK_XYZ))
    {
        // the centre is outside the box
        distance = delta.normalizeWithLength3();
        distance = distance - (sphereA->getRadius() + boxB->getRadius());
        if (distance > input.getTolerance())
        {
            return false;
        }
        hkVector4Util::mulSigns4(delta, posLocalB);
        delta.setNeg4(delta);
        contactOut.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(), delta);
    }
    else
    {
        // the centre is inside the box: the face it is nearest to
        hkReal d0 = absPosB.x - boxB->getHalfExtents().x;
        hkReal d1 = absPosB.y - boxB->getHalfExtents().y;
        hkReal d2 = absPosB.z - boxB->getHalfExtents().z;
        int i;
        if (d0 > d1)
        {
            if (d0 > d2)
            {
                i = 0;
                contactOut.setNormal(bodyB.getTransform().getColumn(0));
                distance = d0;
            }
            else
            {
                i = 2;
                contactOut.setNormal(bodyB.getTransform().getColumn(2));
                distance = d2;
            }
        }
        else
        {
            if (d1 > d2)
            {
                i = 1;
                contactOut.setNormal(bodyB.getTransform().getColumn(1));
                distance = d1;
            }
            else
            {
                i = 2;
                contactOut.setNormal(bodyB.getTransform().getColumn(2));
                distance = d2;
            }
        }
        if (posLocalB(i) < 0)
        {
            contactOut.getSeparatingNormal().setNeg4(contactOut.getSeparatingNormal());
        }
        distance = distance - boxB->getRadius() - sphereA->getRadius();
    }

    contactOut.getPosition().setAddMul4(posA, contactOut.getNormal(), -distance - sphereA->getRadius());
    contactOut.setDistance(distance);
    return true;
}

// pdb: hkpSphereBoxAgent::processCollision | hkpSphereBoxAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpSphereBoxAgent::hkpSphereBoxAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                     const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result)
{
    hkTimerCommand("TtSphereBox");

    hkpProcessCdPoint& point = *result.reserveContactPoints(1);

    if (getClosestPoint(bodyA, bodyB, input, point.m_contact))
    {
        if (m_contactPointId == HK_INVALID_CONTACT_POINT)
        {
            m_contactPointId = m_contactMgr->addContactPoint(bodyA, bodyB, input, result, 0, point.m_contact);
        }

        if (m_contactPointId != HK_INVALID_CONTACT_POINT)
        {
            point.m_contactPointId = m_contactPointId;
            result.commitContactPoints(1);
        }
        else
        {
            result.abortContactPoints(1);
        }
    }
    else
    {
        if (m_contactPointId != HK_INVALID_CONTACT_POINT)
        {
            m_contactMgr->removeContactPoint(m_contactPointId, *result.m_constraintOwner.val());
            m_contactPointId = HK_INVALID_CONTACT_POINT;
        }
    }

    hkTimerCommand("Et");
}

}  // namespace f3m_009c5e70
}   // namespace f3m_009c5e70

// @f3 0x009c8340 (community match, verified in this file)
#include <math.h>
namespace f3m_009c8340 {
// 0x009c8340: hkpSphereCapsuleAgent::getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpCollisionInput& input, hkContactPoint& cpoint) of Havok 5.5.0 (hkpCollide, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Takes the capsule's two end points to world space, finds the point of that segment closest to the sphere's
// centre and, when the two shapes are within the tolerance, fills the contact point: the normal from the segment
// to the centre (any direction across the capsule's axis when the centre lies on it), the position on the
// capsule's surface side and the distance between the surfaces.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector helpers, the
// transform's copy, transformPoints, calculatePerpendicularVector, the contact point's accessors) follow the
// SDK's inline code for the x87 build. The function's own body and the body of its inline helper
// (getClosestPointInl, which the SDK declares) are written from the game's code; the helper's local names follow
// the debug records of the SDK's library object for the agent's sibling function.

namespace f3m_009c8340 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

namespace hkMath {
__forceinline hkReal sqrt(hkReal r) { return sqrtf(r); }
__forceinline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
__forceinline hkReal fabs(hkReal r) { return fabsf(r); }
}  // namespace hkMath

struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    inline void operator=(const hkVector4& v);
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkSimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3() { this->mul4(this->lengthInverse3()); }
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

inline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
    x = a.x + r * b.x;
    y = a.y + r * b.y;
    z = a.z + r * b.z;
    w = a.w + r * b.w;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline hkSimdReal hkVector4::lengthInverse3() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

struct hkMatrix3
{
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline const hkReal& operator()(int row, int column) const { return m_rotation(row, column); }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

// the translation is the rotation's fourth column
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
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

namespace hkVector4Util {
// transforms numVectors points, the last one first; the transform is copied so that the output may alias it
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                   hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

// a vector at right angles to vectorIn: its smallest component is left out, the other two are swapped and one
// of them negated
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
}  // namespace hkVector4Util

struct hkContactPoint
{
    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline const hkVector4& getNormal() const { return m_separatingNormal; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpShape
{
    virtual ~hkpShape();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    inline hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

struct hkpSphereShape : hkpConvexShape
{
};

struct hkpCapsuleShape : hkpConvexShape
{
    inline const hkVector4* getVertices() const { return &m_vertexA; }

    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpCdBody
{
    const hkpShape* getShape() const { return m_shape; }
    const hkTransform& getTransform() const { return *(const hkTransform*)m_motion; }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;

struct hkpCollisionInput
{
    hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

namespace hkpCollideTriangleUtil {
struct ClosestPointLineSegResult
{
    hkVector4 m_pointOnEdge;
};

// closestPointLineSeg: the point of the segment B0-B1 closest to A
int __cdecl FUN_0096fa60(const hkVector4& A, const hkVector4& B0, const hkVector4& B1, ClosestPointLineSegResult& result);
}  // namespace hkpCollideTriangleUtil

struct hkpSphereCapsuleAgent
{
    enum ClosestPointResult
    {
        ST_CP_MISS,
        ST_CP_HIT,
    };

    static __forceinline ClosestPointResult getClosestPointInl(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                               const hkpCollisionInput& input, hkContactPoint& cpoint);

    // getClosestPoint
    static ClosestPointResult __cdecl hkpSphereCapsuleAgent_getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                   const hkpCollisionInput& input, hkContactPoint& cpoint);
};

__forceinline hkpSphereCapsuleAgent::ClosestPointResult hkpSphereCapsuleAgent::getClosestPointInl(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkContactPoint& cpoint)
{
    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.getShape());
    const hkpCapsuleShape* capsuleB = static_cast<const hkpCapsuleShape*>(bodyB.getShape());

    const hkVector4& posA = bodyA.getTransform().getTranslation();

    hkVector4 capsB[2];
    hkVector4Util::transformPoints(bodyB.getTransform(), capsuleB->getVertices(), 2, capsB);

    hkpCollideTriangleUtil::ClosestPointLineSegResult result;
    hkpCollideTriangleUtil::FUN_0096fa60(posA, capsB[0], capsB[1], result);

    hkVector4 aMinusB;
    aMinusB.setSub4(posA, result.m_pointOnEdge);

    const hkReal radiusSum = sphereA->getRadius() + capsuleB->getRadius();
    const hkReal refDist = radiusSum + input.getTolerance();

    hkReal distSquared = aMinusB.lengthSquared3();
    if (distSquared >= refDist * refDist)
    {
        return ST_CP_MISS;
    }

    hkReal dist;
    if (distSquared > 0)
    {
        dist = hkMath::sqrt(distSquared);
        cpoint.getSeparatingNormal() = aMinusB;
    }
    else
    {
        // the centre lies on the capsule's axis: any direction across the axis will do
        dist = 0;
        hkVector4 edge;
        edge.setSub4(capsB[1], capsB[0]);
        hkVector4Util::calculatePerpendicularVector(edge, cpoint.getSeparatingNormal());
    }
    cpoint.getSeparatingNormal().normalize3();

    cpoint.getPosition().setAddMul4(posA, cpoint.getNormal(), capsuleB->getRadius() - dist);
    cpoint.setDistance(dist - radiusSum);
    return ST_CP_HIT;
}

// pdb: hkpSphereCapsuleAgent::getClosestPoint | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
hkpSphereCapsuleAgent::ClosestPointResult __cdecl hkpSphereCapsuleAgent::hkpSphereCapsuleAgent_getClosestPoint(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkContactPoint& cpoint)
{
    return getClosestPointInl(bodyA, bodyB, input, cpoint);
}

}  // namespace f3m_009c8340
}   // namespace f3m_009c8340

// @f3 0x009c8b90 (community match, verified in this file)
namespace f3m_009c8b90 {
// 0x009c8b90: hkpSphereCapsuleAgent::staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpCollisionInput& input, hkpCdPointCollector& collector) of Havok 5.5.0 (hkpCollide, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The static form of the sphere against capsule query: finds the closest point between sphere A and capsule B
// and hands it with the two bodies to the collector when the two shapes are within the tolerance. A timer
// brackets it.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector helpers, the
// transform's copy, transformPoints, calculatePerpendicularVector, the contact point's accessors, the timer
// commands as the SDK's macros expand) follow the SDK's inline code for the x87 build. The function's own body
// and the body of its inline helper (getClosestPointInl, which the SDK declares) are written from the game's
// code; local names and the order of the statements follow the debug records of the SDK's library object.
// The timer reads the clock with the project's accepted two-instruction block (kit/compiler_tips.md, "Timer slot
// still off"), as the SDK's own inline timer code does; it is the only difference from the plain counter-read
// source.


namespace f3m_009c8b90 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

namespace hkMath {
__forceinline hkReal sqrt(hkReal r) { return sqrtf(r); }
__forceinline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
__forceinline hkReal fabs(hkReal r) { return fabsf(r); }
}  // namespace hkMath

extern unsigned int DAT_0116913c;  // thread-local slot of the thread's hkMonitorStream

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

struct hkMonitorStream
{
    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : Command
    {
        // the low half of the time stamp counter
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }

        hkUint32 m_time0;
        hkUint32 m_time1;
    };

    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    __forceinline char* getEnd() { return m_end.val(); }
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    __forceinline hkBool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
};

struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    inline void operator=(const hkVector4& v);
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
    __forceinline void mul4(hkSimdRealParameter rs);
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkSimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3() { this->mul4(this->lengthInverse3()); }
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

inline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    x = v0.x - v1.x;
    y = v0.y - v1.y;
    z = v0.z - v1.z;
    w = v0.w - v1.w;
}

__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
    x = a.x + r * b.x;
    y = a.y + r * b.y;
    z = a.z + r * b.z;
    w = a.w + r * b.w;
}

__forceinline void hkVector4::mul4(hkSimdRealParameter rs)
{
    hkReal s = hkReal(rs);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline hkSimdReal hkVector4::lengthInverse3() const
{
    hkReal l2 = (x * x) + (y * y) + (z * z);
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}

struct hkMatrix3
{
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline const hkReal& operator()(int row, int column) const { return m_rotation(row, column); }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

// the translation is the rotation's fourth column
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
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

namespace hkVector4Util {
// transforms numVectors points, the last one first; the transform is copied so that the output may alias it
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                   hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

// a vector at right angles to vectorIn: its smallest component is left out, the other two are swapped and one
// of them negated
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
}  // namespace hkVector4Util

struct hkContactPoint
{
    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline const hkVector4& getNormal() const { return m_separatingNormal; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpShape
{
    virtual ~hkpShape();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    inline hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

struct hkpSphereShape : hkpConvexShape
{
};

struct hkpCapsuleShape : hkpConvexShape
{
    inline const hkVector4* getVertices() const { return &m_vertexA; }

    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpCdBody
{
    const hkpShape* getShape() const { return m_shape; }
    const hkTransform& getTransform() const { return *(const hkTransform*)m_motion; }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;

struct hkpCollisionInput
{
    hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

namespace hkpCollideTriangleUtil {
struct ClosestPointLineSegResult
{
    hkVector4 m_pointOnEdge;
};

// closestPointLineSeg: the point of the segment B0-B1 closest to A
int __cdecl FUN_0096fa60(const hkVector4& A, const hkVector4& B0, const hkVector4& B1, ClosestPointLineSegResult& result);
}  // namespace hkpCollideTriangleUtil

// a contact point with the two bodies it belongs to
struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

struct hkpCdPointCollector
{
    virtual ~hkpCdPointCollector();
    virtual void addCdPoint(const hkpCdPoint& point) = 0;

    hkReal m_earlyOutDistance;
};

struct hkpSphereCapsuleAgent
{
    enum ClosestPointResult
    {
        ST_CP_MISS,
        ST_CP_HIT,
    };

    static __forceinline ClosestPointResult getClosestPointInl(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                               const hkpCollisionInput& input, hkContactPoint& cpoint);

    // staticGetClosestPoints
    static void __cdecl hkpSphereCapsuleAgent_staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
                                     hkpCdPointCollector& collector);
};

__forceinline hkpSphereCapsuleAgent::ClosestPointResult hkpSphereCapsuleAgent::getClosestPointInl(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkContactPoint& cpoint)
{
    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.getShape());
    const hkpCapsuleShape* capsuleB = static_cast<const hkpCapsuleShape*>(bodyB.getShape());

    const hkVector4& posA = bodyA.getTransform().getTranslation();

    hkVector4 capsB[2];
    hkVector4Util::transformPoints(bodyB.getTransform(), capsuleB->getVertices(), 2, capsB);

    hkpCollideTriangleUtil::ClosestPointLineSegResult result;
    hkpCollideTriangleUtil::FUN_0096fa60(posA, capsB[0], capsB[1], result);

    hkVector4 aMinusB;
    aMinusB.setSub4(posA, result.m_pointOnEdge);

    const hkReal radiusSum = sphereA->getRadius() + capsuleB->getRadius();
    const hkReal refDist = radiusSum + input.getTolerance();

    hkReal distSquared = aMinusB.lengthSquared3();
    if (distSquared >= refDist * refDist)
    {
        return ST_CP_MISS;
    }

    hkReal dist;
    if (distSquared > 0)
    {
        dist = hkMath::sqrt(distSquared);
        cpoint.getSeparatingNormal() = aMinusB;
    }
    else
    {
        // the centre lies on the capsule's axis: any direction across the axis will do
        dist = 0;
        hkVector4 edge;
        edge.setSub4(capsB[1], capsB[0]);
        hkVector4Util::calculatePerpendicularVector(edge, cpoint.getSeparatingNormal());
    }
    cpoint.getSeparatingNormal().normalize3();

    cpoint.getPosition().setAddMul4(posA, cpoint.getNormal(), capsuleB->getRadius() - dist);
    cpoint.setDistance(dist - radiusSum);
    return ST_CP_HIT;
}

// pdb: hkpSphereCapsuleAgent::staticGetClosestPoints | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|objrun) + skyrim(ustr_rel), high
void __cdecl hkpSphereCapsuleAgent::hkpSphereCapsuleAgent_staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                 const hkpCollisionInput& input, hkpCdPointCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtSphereCapsule";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpCdPoint event(bodyA, bodyB);

    if (getClosestPointInl(bodyA, bodyB, input, event.m_contact) != ST_CP_MISS)
    {
        collector.addCdPoint(event);
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}  // namespace f3m_009c8b90
}   // namespace f3m_009c8b90

// @f3 0x009ca4c0 (community match, verified in this file)
namespace f3m_009ca4c0 {
namespace task0912 {
struct __declspec(align(16)) AgentFuncs {
    void* create;
    int unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28;
    void* unk2c;
    bool flipped;
    bool predictive;
    bool unk32;
    AgentFuncs() {
        flipped = false;
        predictive = false;
        unk32 = false;
        unk18 = 0;
        unk1c = 0;
        unk20 = 0;
        unk24 = 0;
        unk28 = 0;
    }
};
void __cdecl FUN_009ca480(AgentFuncs*);
struct Dispatcher { void FUN_00985cb0(AgentFuncs*, int, int); };
}
// pdb: hkBoxBoxAgent3::registerAgent3 | hkpBoxBoxAgent3.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dispatcher
void __cdecl FUN_009ca4c0(task0912::Dispatcher* target)
{
    task0912::AgentFuncs funcs;
    task0912::FUN_009ca480(&funcs);
    target->FUN_00985cb0(&funcs, 5, 5);
}
}   // namespace f3m_009ca4c0

// @f3 0x009d1540 (community match, verified in this file)
namespace f3m_009d1540 {
extern unsigned DAT_0116913c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);

extern "C" void _ReadWriteBarrier(void);

extern const char str_00e7f4f8[];
extern const char str_00e32798[];
namespace c_009d1540 {
struct MonitorStream { int unk00; char* end; int unk08; char* capacityEnd; };
static __forceinline void TimerMark(const char* name)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0116913c);
    char* p = s->end;
    if (p < s->capacityEnd) {
        *(const char**)p = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        ((unsigned int*)p)[1] = t;
        s->end = p + 0xc;
    }
}
struct __declspec(align(16)) ShapeBuffer { int data[0x80]; };
struct Shape;
struct Container {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual Shape* GetChildShape(unsigned int key, ShapeBuffer* buf);
};
struct Shape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual Container* GetContainer();
};
struct CdBody { Shape* shape; unsigned int key; void* motion; const CdBody* parent; };
struct Agent {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void Process(const CdBody* body, void* b, void* c, void* d);
};
struct KeyAgent { unsigned int key; Agent* agent; };
struct ShapeCollectionAgent {
    int unk00[3];
    KeyAgent* agents;
    int numAgents;
    void hkpShapeCollectionAgent_getClosestPoints(const CdBody* a, void* b, void* c, void* d);
};
// pdb: hkpShapeCollectionAgent::getClosestPoints | hkpShapeCollectionAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void ShapeCollectionAgent::hkpShapeCollectionAgent_getClosestPoints(const CdBody* a, void* b, void* c, void* d)
{
    TimerMark(str_00e7f4f8);
    Container* container = a->shape->GetContainer();
    CdBody body;
    body.motion = a->motion;
    body.parent = a;
    ShapeBuffer buffer;
    KeyAgent* it = agents;
    for (int i = numAgents - 1; i >= 0; i--) {
        unsigned int key = it->key;
        body.shape = container->GetChildShape(key, &buffer);
        body.key = key;
        it->agent->Process(&body, b, c, d);
        it++;
    }
    TimerMark(str_00e32798);
}
}
}   // namespace f3m_009d1540

// @f3 0x009d2540 (community match, verified in this file)
namespace f3m_009d2540 {
namespace f3m_009d2540
{
typedef float hkReal;
typedef unsigned int hkUint32;

struct hkMatrix3;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedDir(const hkMatrix3& r, const hkVector4& v) { _setMul3(r, v); }
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }
};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    const hkReal v0 = v.x;
    const hkReal v1 = v.y;
    const hkReal v2 = v.z;
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    w = 0;
}

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
};

struct hkMotionState
{
    hkTransform m_transform;
    hkVector4 m_sweptCenterOfMass0;
    hkVector4 m_sweptCenterOfMass1;
    hkVector4 m_sweptRotation0;
    hkVector4 m_sweptRotation1;
    hkVector4 m_sweptCenterOfMassLocal;
    hkVector4 m_deltaAngle;
    hkReal m_objectRadius;
    hkReal m_maxLinearVelocity;
    hkReal m_maxAngularVelocity;
    hkReal m_linearDamping;
    hkMotionState(const hkMotionState& other);
    __forceinline hkTransform& getTransform() { return m_transform; }
};

struct hkpShape
{
    void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    hkUint32 m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    hkReal m_radius;
};

struct hkpSphereShape : hkpConvexShape
{
    hkUint32 m_pad16[3];
    hkpSphereShape(hkReal radius);
};

struct hkpMultiSphereShape : hkpShape
{
    int m_numSpheres;
    hkUint32 m_pad[3];
    hkVector4 m_spheres[8];
};

struct hkpCdBody
{
    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline hkpCdBody(const hkpCdBody* parent, const hkMotionState* ms)
    {
        m_parent = parent;
        m_motion = ms;
    }
    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkMotionState* getMotionState() const { return static_cast<const hkMotionState*>(m_motion); }
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }
    __forceinline void setShape(const hkpShape* shape, hkUint32 key)
    {
        m_shape = shape;
        m_shapeKey = key;
    }
};

struct hkpLinearCastCollisionInput;
struct hkpCdPointCollector;

struct hkpCollisionAgent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void linearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input,
                            hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

struct KeyAgentPair
{
    hkUint32 m_key;
    hkpCollisionAgent* m_agent;
};

struct hkpMultiSphereAgent
{
    void* m_vtable;
    int m_memSizeAndFlags;
    void* m_contactMgr;
    KeyAgentPair* m_agents;
    int m_numAgents;

    void hkpMultiSphereAgent_linearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};
}

// pdb: hkpMultiSphereAgent::linearCast | hkpMultiSphereAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void f3m_009d2540::hkpMultiSphereAgent::hkpMultiSphereAgent_linearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                     const hkpLinearCastCollisionInput& input,
                                                     hkpCdPointCollector& collector,
                                                     hkpCdPointCollector* startCollector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());

    hkMotionState ms(*bodyA.getMotionState());
    hkpSphereShape sphereShape(0.0f);
    hkpCdBody newOperandA(&bodyA, &ms);
    KeyAgentPair* agents = m_agents;

    for (int i = m_numAgents - 1; i >= 0; i--)
    {
        const hkVector4& b = msA->m_spheres[i];
        hkVector4 rotated;
        rotated._setRotatedDir(ms.getTransform().getRotation(), b);
        ms.getTransform().m_translation.setAdd4(bodyA.getTransform().getTranslation(), rotated);
        sphereShape.m_radius = b(3);
        newOperandA.setShape(&sphereShape, i);
        agents->m_agent->linearCast(newOperandA, bodyB, input, collector, startCollector);
    }
}
}   // namespace f3m_009d2540

// @f3 0x009d9f40 (community match, verified in this file)
namespace f3m_009d9f40 {

namespace f3m_009d9f40 {
struct Transform;
struct __declspec(align(16)) Vector { float x, y, z, w; void hkVector4_setTransformedPos(const Transform* t, const Vector* v); };
struct Point4 { float x, y, z, w; void Set(const Point4& p) { x = p.x; y = p.y; z = p.z; w = p.w; } };
struct Node {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    Transform* World() { return (Transform*)&worldE0; }
    int worldE0;
};
struct Link {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Node* nodeA;
    Node* nodeB;
    int unk20, unk24, unk28, unk2c;
    Point4 localA;
    Point4 localB;
    float distance;
    void hkpSpringAction_setPositionsInBodySpace(const Point4* a, const Point4* b);
};
// pdb: hkpSpringAction::setPositionsInBodySpace | hkpSpringAction.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void Link::hkpSpringAction_setPositionsInBodySpace(const Point4* a, const Point4* b)
{
    Node* na = nodeA;
    Node* nb = nodeB;
    localA.Set(*a);
    localB.Set(*b);
    Vector wa;
    Vector wb;
    wa.hkVector4_setTransformedPos(na->World(), (const Vector*)a);
    wb.hkVector4_setTransformedPos(nb->World(), (const Vector*)b);
    Point4 d;
    d.x = wa.x - wb.x;
    d.y = wa.y - wb.y;
    d.z = wa.z - wb.z;
    distance = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
}
}
}   // namespace f3m_009d9f40

// @f3 0x009dbf00 (community match, verified in this file)
namespace f3m_009dbf00
{
class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = (char)b; }
    __forceinline operator bool() const { return m_bool != 0; }
    char m_bool;
};

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
};

extern hkVector4 DAT_01092a50;

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline hkMatrix3() {}
    __forceinline hkMatrix3(const hkMatrix3& other)
    {
        m_col0 = other.m_col0;
        m_col1 = other.m_col1;
        m_col2 = other.m_col2;
    }
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;
    __forceinline hkTransform(const hkRotation& r, const hkVector4& t) : m_rotation(r), m_translation(t) {}
    hkBool FUN_00924ca0(float epsilon) const;
};

struct hkpWheelConstraintData
{
    int unk00[8];
    hkTransform m_bodyAFrame;
    hkTransform m_bodyBFrame;
    int unka0;
    float m_suspensionMin;
    float m_suspensionMax;
    int unkac[9];
    hkRotation m_rotationA;
    hkRotation m_rotationB;
    hkBool hkpWheelConstraintData_isValid() const;
};
}

// pdb: hkpWheelConstraintData::isValid | hkpWheelConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(caller_sim), high
f3m_009dbf00::hkBool f3m_009dbf00::hkpWheelConstraintData::hkpWheelConstraintData_isValid() const
{
    hkTransform t1(m_rotationA, DAT_01092a50);
    hkTransform t2(m_rotationB, DAT_01092a50);
    return m_bodyAFrame.FUN_00924ca0(0.001f) && m_bodyBFrame.FUN_00924ca0(0.001f) && t1.FUN_00924ca0(0.001f) &&
           t2.FUN_00924ca0(0.001f) && (m_suspensionMin <= m_suspensionMax);
}

// @f3 0x009dfd50 (community match, verified in this file)
namespace f3m_009dfd50 {
namespace f3m_009dfd50 {

void __cdecl FUN_00901f10(void* array, int elementSize);

struct __declspec(align(16)) hkVector4 {
    float x; float y; float z; float w;
    void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
};

template <typename T>
struct hkArray {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    void pushBack(const T& e)
    {
        if (m_size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        m_data[m_size++] = e;
    }
    T& expandOne()
    {
        if (m_size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        return m_data[m_size++];
    }
};

struct Geometry {
    int unk00;
    int m_numBytes;
    int m_unk08;
    int m_unk0c;
    hkArray<hkVector4> m_vectors;
    hkArray<int> m_commands;
};

struct Builder {
    int unk00;
    Geometry* m_geometry;
    int FUN_009dfd50(bool flag, float x, float y);
};

// pdb: hkpConstraintConstructionKit::setLinearLimit | hkpConstraintConstructionKit.obj | tesv_win, objrun_open, low
int Builder::FUN_009dfd50(bool flag, float x, float y)
{
    m_geometry->m_commands.pushBack(0x10);
    m_geometry->m_commands.pushBack(flag);
    int index = m_geometry->m_vectors.getSize();
    hkVector4 v;
    v.set(x, y, 0.0f, 0.0f);
    m_geometry->m_vectors.expandOne() = v;
    Geometry* geometry = m_geometry;
    geometry->m_numBytes += 0x40;
    geometry->m_unk08++;
    geometry->m_unk0c++;
    return index;
}

}
}   // namespace f3m_009dfd50

// @f3 0x009c4e40 (community match, verified in this file)
namespace f3m_009c4e40 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace f3m_009c4e40 {
struct Transform;
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline float& at(int i) { return (&x)[i]; }
    __forceinline const float& at(int i) const { return (&x)[i]; }
    __forceinline void assign(const Vec4& v) { x=v.x; y=v.y; z=v.z; w=v.w; }
    __forceinline void transformed(const Transform&, const Vec4&);
};
struct Transform {
    Vec4 c0, c1, c2, t;
    __forceinline const Vec4& column(int i) const { return (&c0)[i]; }
    __forceinline Vec4& column(int i) { return (&c0)[i]; }
    __forceinline const float& at(int r,int c) const { return column(c).at(r); }
    __forceinline Transform(const Transform& other) {
        const Vec4 r0=other.column(0), r1=other.column(1), r2=other.column(2), r3=other.column(3);
        column(0).assign(r0); column(1).assign(r1); column(2).assign(r2); column(3).assign(r3);
    }
};
__forceinline void Vec4::transformed(const Transform& tr, const Vec4& v) {
    float vx=v.at(0), vy=v.at(1), vz=v.at(2);
    at(0)=tr.at(0,0)*vx+tr.at(0,1)*vy+tr.at(0,2)*vz+tr.at(0,3);
    at(1)=tr.at(1,0)*vx+tr.at(1,1)*vy+tr.at(1,2)*vz+tr.at(1,3);
    at(2)=tr.at(2,0)*vx+tr.at(2,1)*vy+tr.at(2,2)*vz+tr.at(2,3);
    at(3)=0;
}
struct Motion { Transform transform; };
struct CapsuleShape {
    void* vtable; unsigned short size; short refs; unsigned user; int type;
    float radius; int unk14,unk18,unk1c; Vec4 vertices[2];
    __forceinline float getRadius() const { return radius; }
};
struct CdBody {
    const CapsuleShape* shape; unsigned key; const Motion* motion; const CdBody* parent;
    __forceinline const CapsuleShape* getShape() const { return shape; }
    __forceinline const Transform& getTransform() const { return motion->transform; }
};
struct CollisionInput { int unk00; float tolerance; __forceinline float getTolerance() const { return tolerance; } };
struct Contact;
extern "C" int FUN_0096e0d0(const Vec4*,float,const Vec4*,float,float,Contact*);
static __forceinline void transformPoints(const Transform& tr,const Vec4* in,int n,Vec4* out) {
    Transform local(tr);
    int i=n-1;
    do { out[i].transformed(local,in[i]); } while (--i>=0);
}
// pdb: getClosestPointInternal | hkpCapsuleCapsuleAgent.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) int FUN_009c4e40(const CdBody& a,const CdBody& b,const CollisionInput& input,Contact* contact) {
    const CapsuleShape* capsA=a.getShape();
    const CapsuleShape* capsB=b.getShape();
    Vec4 ptsA[2];
    Vec4 ptsB[2];
    transformPoints(a.getTransform(),capsA->vertices,2,ptsA);
    transformPoints(b.getTransform(),capsB->vertices,2,ptsB);
    return FUN_0096e0d0(ptsA,capsA->getRadius(),ptsB,capsB->getRadius(),input.getTolerance(),contact);
}
// Fake match: caller forces emission of the file-local function's private register ABI.
int caller_of_FUN_009c4e40(const CdBody& a,const CdBody& b,const CollisionInput& input,Contact* contact) {
    return FUN_009c4e40(a,b,input,contact);
}
}
}   // namespace f3m_009c4e40

// @f3 0x009cb050 (community match, verified in this file)
namespace f3m_009cb050 {
struct Rec9cb050
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
};

void __cdecl FUN_00a36820(Rec9cb050* src, int c, int a);

// pdb: hkPredGskAgent3::destroy | hkpPredGskAgent3.obj | fnv360_0822_debug, caller_sim, low, conflict (skyrim: resetGskManifold)
// pdb params: entry, agentData, mgr, constraintOwner, dispatcher
static __declspec(noinline) void FUN_009cb050(Rec9cb050* src, int c, int a, Rec9cb050* dst)
{
    FUN_00a36820(src, c, a);
    dst->unk02 = src->unk02;
}

Rec9cb050* volatile g_src9cb050;
Rec9cb050* volatile g_dst9cb050;
volatile int g_c9cb050;
volatile int g_a9cb050;

void Caller9cb050()
{
    FUN_009cb050(g_src9cb050, (int)g_c9cb050, (int)g_a9cb050, g_dst9cb050);
}
}   // namespace f3m_009cb050

// @f3 0x009d6340 (community match, verified in this file)
namespace f3m_009d6340 {
struct BaseA9d6340
{
    virtual ~BaseA9d6340();
    int unk04;
    int unk08;
    int unk0c;
};

struct BaseB9d6340
{
    virtual ~BaseB9d6340();
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
};

struct Base9d6340 : BaseA9d6340, BaseB9d6340
{
    Base9d6340(float a, int b);
    virtual ~Base9d6340();
};

struct Array9d6340
{
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    Array9d6340() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
};

struct FUN_009d6340 : Base9d6340
{
    Array9d6340 m_array;
    FUN_009d6340(float a, int b);
    virtual ~FUN_009d6340();
};

// pdb: hkpStorageMeshShape::hkpStorageMeshShape | hkpStorageMeshShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: radius, numbits
FUN_009d6340::FUN_009d6340(float a, int b) : Base9d6340(a, b)
{
}
}   // namespace f3m_009d6340

// @f3 0x009d9af0 (community match, verified in this file)
#include <math.h>
namespace f3m_009d9af0 {

// 0x009d9af0: moves a simple shape phantom to a new position and casts its shape along a path from there
// (hkpSimpleShapePhantom::setPositionAndLinearCast in Havok terms). The phantom's broad phase box is grown to cover
// the whole path, then every overlapping collidable's agent does the linear cast.

namespace f3m_009d9af0 {

typedef float hkReal;

inline hkReal hkSqrt(hkReal r) { return sqrtf(r); }

class __declspec(align(16)) hkVector4
{
public:
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void add4(const hkVector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
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
    __forceinline hkReal length3() const
    {
        return hkSqrt((x * x) + (y * y) + (z * z));
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
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

    __forceinline void setTranslation(const hkVector4& t) { m_translation = t; }
};

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
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
    virtual void getAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
};

struct hkpCollidable
{
    const hkpShape* m_shape;

    __forceinline const hkpShape* getShape() const { return m_shape; }
};

struct hkpCollisionInput
{
    void* m_dispatcher;
    hkReal m_tolerance;
    int pad08[18];

    __forceinline hkReal getTolerance() const { return m_tolerance; }
    void FUN_00921790(const hkpCollisionInput& other);      // assignment
};

struct hkpProcessCollisionInput : public hkpCollisionInput
{
    int pad50[7];
    void* m_config;
};

struct hkpLinearCastCollisionInput : public hkpCollisionInput
{
    __forceinline hkpLinearCastCollisionInput() { m_maxExtraPenetration = 1.1920928955078125e-07f; }
    __forceinline void set(const hkpProcessCollisionInput& input)
    {
        FUN_00921790(input);
        m_config = input.m_config;
    }
    __forceinline void setPathAndTolerance(const hkVector4& path, hkReal tolerance)
    {
        m_path = path;
        m_cachedPathLength = path.length3();
        m_tolerance = tolerance;
    }

    hkVector4 m_path;
    hkReal m_maxExtraPenetration;
    hkReal m_cachedPathLength;
    void* m_config;
};

struct hkpLinearCastInput
{
    hkVector4 m_to;
    hkReal m_maxExtraPenetration;
    hkReal m_startPointTolerance;
};

class hkpCdPointCollector;

class hkpCollisionAgent
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void linearCast(const hkpCollidable& bodyA, const hkpCollidable& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

struct hkpWorld
{
    char pad00[0x6c];
    hkpProcessCollisionInput* m_collisionInput;

    __forceinline const hkpProcessCollisionInput* getCollisionInput() const { return m_collisionInput; }
};

template <typename T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline int getSize() const { return m_size; }
    __forceinline T& operator[](int i) { return m_data[i]; }
};

class hkpSimpleShapePhantom
{
public:
    struct CollisionDetail
    {
        hkpCollisionAgent* m_agent;
        hkpCollidable* m_collidable;
    };

    void FUN_00989c00(const hkAabb& aabb);      // updateBroadPhase
    void FUN_009d9af0(const hkVector4& position, const hkpLinearCastInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector);

    void* m_vtable;
    int unk04;
    hkpWorld* m_world;
    int unk0c;
    hkpCollidable m_collidable;
    char pad14[0xa0 - 0x14];
    hkTransform m_transform;        // of the motion state
    char pade0[0x150 - 0xe0];
    hkArray<CollisionDetail> m_collisionDetails;
};

void hkpSimpleShapePhantom::FUN_009d9af0(const hkVector4& position, const hkpLinearCastInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector)
{
    m_transform.setTranslation(position);

    hkAabb aabb;
    hkReal halfTolerance = 0.5f * m_world->getCollisionInput()->getTolerance();
    m_collidable.getShape()->getAabb(m_transform, halfTolerance + input.m_startPointTolerance, aabb);

    // grow the box to cover the whole path
    hkVector4 path;
    path.setSub4(input.m_to, position);
    hkVector4 zero;
    zero.setZero4();
    hkVector4 pathMin;
    pathMin.setMin4(zero, path);
    hkVector4 pathMax;
    pathMax.setMax4(zero, path);

    aabb.m_min.add4(pathMin);
    aabb.m_max.add4(pathMax);

    FUN_00989c00(aabb);

    // the input of the linear cast
    hkpLinearCastCollisionInput lcInput;
    {
        lcInput.set(*m_world->getCollisionInput());
        lcInput.setPathAndTolerance(path, input.m_startPointTolerance);
        lcInput.m_maxExtraPenetration = input.m_maxExtraPenetration;
    }

    // the cast, against everything that overlaps
    {
        for (int i = m_collisionDetails.getSize() - 1; i >= 0; i--)
        {
            CollisionDetail& det = m_collisionDetails[i];
            det.m_agent->linearCast(m_collidable, *det.m_collidable, lcInput, castCollector, startCollector);
        }
    }
}

}
}   // namespace f3m_009d9af0

// @f3 0x009c9b60 (community match, verified in this file)
#include <math.h>
namespace f3m_009c9b60 {

// from the Windows API (declared here: windows.h cannot be included after intrin.h with this compiler)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

// 0x009c9b60: closest point between two spheres (hkpSphereSphereAgent::getClosestPoints in Havok terms). When the
// spheres are closer than the tolerance, one point is reported to the collector: on the surface of sphere B, with
// the normal pointing from B to A and the gap between the surfaces as distance.

namespace f3m_009c9b60 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern unsigned long DAT_0116913c;      // TLS slot of the per-thread monitor stream

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

inline hkReal hkSqrt(hkReal r) { return sqrtf(r); }
inline hkReal hkSqrtInverse(hkReal r) { return 1.0f / hkSqrt(r); }

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setXYZ(const hkVector4& xyz)
    {
        x = xyz.x;
        y = xyz.y;
        z = xyz.z;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }
    __forceinline hkReal lengthSquared3() const
    {
        return (x * x) + (y * y) + (z * z);
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
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

    __forceinline const hkVector4& getColumn(int i) const { return (&m_rotation.m_col0)[i]; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
    static __forceinline const hkTransform& getIdentity();
};

extern const hkTransform DAT_010f3370;      // the identity transform

__forceinline const hkTransform& hkTransform::getIdentity() { return DAT_010f3370; }

class hkpSphereShape
{
public:
    __forceinline hkReal getRadius() const { return m_radius; }

    void* m_vtable;
    int unk04;
    unsigned int m_userData;
    int m_type;
    hkReal m_radius;
};

struct hkpCdBody
{
    const void* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }
    __forceinline const void* getShape() const { return m_shape; }
};

struct hkpCollisionInput
{
    void* m_dispatcher;
    hkReal m_tolerance;

    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;

    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline const hkVector4& getNormal() const { return m_separatingNormal; }
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }
    __forceinline void setNormal(const hkVector4& normal) { m_separatingNormal.setXYZ(normal); }
};

struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

class hkpCdPointCollector
{
public:
    virtual void vf00();
    virtual void addCdPoint(const hkpCdPoint& point);
};

class hkpSphereSphereAgent
{
public:
    void hkpSphereSphereAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector);
};

// pdb: hkpSphereSphereAgent::getClosestPoints | hkpSphereSphereAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpSphereSphereAgent::hkpSphereSphereAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtSphereSphere";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpCdPoint event(bodyA, bodyB);

    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.getShape());
    const hkpSphereShape* sphereB = static_cast<const hkpSphereShape*>(bodyB.getShape());

    const hkVector4& posA = bodyA.getTransform().getTranslation();
    const hkVector4& posB = bodyB.getTransform().getTranslation();

    hkVector4 vec;
    vec.setSub4(posA, posB);

    const hkReal distSquared = vec.lengthSquared3();
    const hkReal radiusSumPlusTolerance = sphereA->getRadius() + sphereB->getRadius() + input.getTolerance();

    if (distSquared < radiusSumPlusTolerance * radiusSumPlusTolerance)
    {
        hkReal dist;
        if (distSquared > 0.0f)
        {
            hkReal invDist = hkSqrtInverse(distSquared);
            event.m_contact.getSeparatingNormal().setMul4(invDist, vec);
            dist = distSquared * invDist;
        }
        else
        {
            dist = 0.0f;
            event.m_contact.setNormal(hkTransform::getIdentity().getColumn(0));
        }

        const hkReal radiusA = sphereA->getRadius();
        const hkReal radiusB = sphereB->getRadius();
        event.m_contact.getPosition().setAddMul4(posB, event.m_contact.getNormal(), sphereB->getRadius());
        event.m_contact.setDistance(dist - (radiusA + radiusB));

        collector.addCdPoint(event);
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009c9b60

// @f3 0x009cac30 (community match, verified in this file)
namespace f3m_009cac30 {
// 0x009cac30: do two boxes overlap (hkpBoxBoxAgent::staticGetPenetrations in Havok terms). A box-box collision
// detector is set up with both boxes (half extents grown by their radius), the transform of B relative to A and the
// tolerance; when it finds the boxes intersecting, the pair is reported to the collector.

// from the Windows API (declared here: windows.h cannot be included after intrin.h with this compiler)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_009cac30 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern unsigned long DAT_0116913c;      // TLS slot of the per-thread monitor stream

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

class __declspec(align(16)) hkVector4
{
public:
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setAll(hkReal a)
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
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        m_rotation.m_col0 = t.m_rotation.m_col0;
        m_rotation.m_col1 = t.m_rotation.m_col1;
        m_rotation.m_col2 = t.m_rotation.m_col2;
        m_translation = t.m_translation;
    }
    // this = a^-1 * b
    void FUN_00925300(const hkTransform& a, const hkTransform& b);

    hkRotation m_rotation;
    hkVector4 m_translation;
};

class hkpBoxShape
{
public:
    __forceinline hkReal getRadius() const { return m_radius; }
    __forceinline const hkVector4& getHalfExtents() const { return m_halfExtents; }

    void* m_vtable;
    int unk04;
    unsigned int m_userData;
    int m_type;
    hkReal m_radius;
    hkVector4 m_halfExtents;
};

struct hkpCdBody
{
    const void* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }
    __forceinline const void* getShape() const { return m_shape; }
};

struct hkpCollisionInput
{
    void* m_dispatcher;
    hkReal m_tolerance;

    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

class hkpCdBodyPairCollector
{
public:
    virtual void vf00();
    virtual void addCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
};

struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
class hkpContactMgr;

// the box against box test; only the part set up by the constructor is described here
class hkpBoxBoxCollisionDetection
{
public:
    __forceinline hkpBoxBoxCollisionDetection(
        const hkpCdBody& bodyA, const hkpCdBody& bodyB,
        const hkpProcessCollisionInput* env, hkpContactMgr* mgr, hkpProcessCollisionOutput* result,
        const hkTransform& wTa, const hkTransform& wTb, const hkTransform& aTb,
        const hkVector4& radiusA, const hkVector4& radiusB, hkReal tolerance)
        : m_bodyA(bodyA), m_bodyB(bodyB), m_env(env), m_contactMgr(mgr), m_result(result),
          m_wTa(wTa), m_wTb(wTb), m_aTb(aTb), m_radiusA(radiusA), m_radiusB(radiusB),
          m_tolerance(tolerance), m_boundaryTolerance(0.01f)
    {
        m_tolerance4.setAll(tolerance);
        m_keepRadiusA.setAdd4(m_radiusA, m_tolerance4);
        m_keepRadiusB.setAdd4(m_radiusB, m_tolerance4);
    }

    void FUN_009cafa0();                                    // sets up the work variables
    int FUN_00a3bc00(const hkVector4& tolerance4);          // checkIntersection: 0 when the boxes intersect

    const hkpCdBody& m_bodyA;
    const hkpCdBody& m_bodyB;
    const hkpProcessCollisionInput* m_env;
    hkpContactMgr* m_contactMgr;
    hkpProcessCollisionOutput* m_result;
    const hkTransform& m_wTa;
    const hkTransform& m_wTb;
    hkTransform m_aTb;
    hkVector4 m_radiusA;
    hkVector4 m_radiusB;
    hkVector4 m_tolerance4;
    hkVector4 m_keepRadiusA;
    hkVector4 m_keepRadiusB;
    hkReal m_tolerance;
    hkReal m_boundaryTolerance;
    int m_work[28];
};

// pdb: hkpBoxBoxAgent::staticGetPenetrations | hkpBoxBoxAgent.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkpBoxBoxAgent_staticGetPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtBoxBox";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    const hkpBoxShape* boxA = static_cast<const hkpBoxShape*>(bodyA.getShape());
    const hkpBoxShape* boxB = static_cast<const hkpBoxShape*>(bodyB.getShape());

    // half extents grown by the radius
    hkVector4 rA;
    rA.setAll(boxA->getRadius());
    rA.setAdd4(boxA->getHalfExtents(), rA);
    hkVector4 rB;
    rB.setAll(boxB->getRadius());
    rB.setAdd4(boxB->getHalfExtents(), rB);

    hkTransform aTb;
    aTb.FUN_00925300(bodyA.getTransform(), bodyB.getTransform());

    hkpBoxBoxCollisionDetection detector(bodyA, bodyB, 0, 0, 0, bodyA.getTransform(), bodyB.getTransform(), aTb, rA, rB, input.getTolerance());
    detector.FUN_009cafa0();

    if (detector.FUN_00a3bc00(detector.m_tolerance4) == 0)
    {
        collector.addCdBodyPair(bodyA, bodyB);
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009cac30

// @f3 0x009cafa0 (community match, verified in this file)
namespace f3m_009cafa0 {
struct V {
    float x, y, z, w;
    V& operator=(const V& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};

struct Loc { float y, x, z; };

struct S {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    V v;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    V p;
    float r0, r1, r2, r3;
    void FUN_009cafa0();
};

// pdb: hkpProcessCollisionOutput::commitContactPoints | hkpHeightFieldAgent.obj | fnv360_0822_debug, call_gap, low, conflict (skyrim: hkpBoxBoxCollisionDetection::initWorkVariables)
// pdb params: numberOfPoints
void S::FUN_009cafa0()
{
    p = v;
    Loc f;
    f.x = p.x;
    f.y = p.y;
    f.z = p.z;
    r0 = m00 * f.x + m01 * f.y + m02 * f.z;
    r1 = m10 * f.x + m11 * f.y + m12 * f.z;
    r2 = m20 * f.x + m21 * f.y + m22 * f.z;
    r3 = 0.0f;
}
}   // namespace f3m_009cafa0

// @f3 0x009d6320 (community match, verified in this file)
namespace f3m_009d6320 {
namespace f3m_009d6320 {
struct Tail {
    int a;
    int b;
    unsigned int c;
};
__forceinline void init_tail(Tail* t) { t->a = 0; t->b = 0; t->c = 0x80000000; }
struct Obj {
    void* vptr;
    short unk04;
    unsigned short unk06;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    int unk38, unk3c, unk40;
    Tail tail;
    Obj* FUN_009d6320(int flag);
};
// pdb: hkpStorageMeshShape::SubpartStorage::SubpartStorage | hkpStorageMeshShape.obj | tesv_win, objrun, medium
Obj* Obj::FUN_009d6320(int flag) {
    unk06 = 1;
    vptr = (void*)0x00e7fd3c;
    init_tail(&tail);
    return this;
}
}
}   // namespace f3m_009d6320
