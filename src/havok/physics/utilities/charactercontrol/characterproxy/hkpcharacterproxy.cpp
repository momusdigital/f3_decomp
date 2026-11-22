#include "f3_common.h"
// src/havok/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cad480_Class {
    void __thiscall FUN_00cad480(void* arg);
};

// Iterates the proxy list at this+0x80 in reverse and calls each proxy's third virtual method with this and arg.
// @f3 0x0091ec60 (community match, verified in this file)
struct FUN_00cad480_Proxy
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void* arg);
};
// pdb: hkpCharacterProxy::fireContactRemoved | hkpCharacterProxy.obj | tesv_win, call_dedup, low
void __thiscall FUN_00cad480_Class::FUN_00cad480(void* arg)
{
    int count = *(int*)((char*)this + 0x84);
    for (--count; count >= 0; --count) {
        FUN_00cad480_Proxy* proxy = *(FUN_00cad480_Proxy**)((char*)*(void**)((char*)this + 0x80) + count * 4);
        proxy->v08(arg);
    }
}


struct S_00cad440;

struct S_00cad440_Listener {
    virtual void unk0();
    virtual void Notify(S_00cad440* src, void* a, void* b);
};

struct S_00cad440 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    S_00cad440_Listener** unk80;
    int unk84;
    void FUN_00cad440(void* a, void* b);
};

// Iterates the listener array backwards from unk84 and calls Notify(this, a, b) on each listener.
// @f3 0x0091ec20 (community match, verified in this file)
struct ReverseNotifyListener {
    virtual void Reserved();
    virtual void Notify(void* first, void* second);
};

// pdb: hkpCharacterProxy::fireContactAdded | hkpCharacterProxy.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: hkpCharacterProxy::fireConstraintsProcessed)
// pdb params: point
void S_00cad440::FUN_00cad440(void* first, void* second)
{
    for (int index = unk84 - 1; index >= 0; --index)
        reinterpret_cast<ReverseNotifyListener*>(unk80[index])->Notify(first, second);
}


struct CAD4C0Owner;

struct CAD4C0Listener {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void notify(CAD4C0Owner* owner, void* data);
};

struct CAD4C0Owner {
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
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    CAD4C0Listener** m_kListeners;
    int m_numListeners;

    void FUN_00cad4c0(void* data);
};

struct FNVAllocator {
    virtual void Release();
    virtual void* Allocate(unsigned int bytes);
};
struct FNVMemoryManager {
    FNVAllocator* GetAllocator() {
        return *reinterpret_cast<FNVAllocator**>(reinterpret_cast<char*>(this) + 0x10);
    }
};
FNVMemoryManager* __cdecl FUN_00c85750();

struct FNVArray {
    int* values;
    unsigned short size;
    unsigned short flags;
    FNVArray() : values(0), size(0), flags(0x8000) {}
};
struct FNVBuffers {
    FNVArray spare;
    FNVArray elements;
    static void* operator new(unsigned int bytes) {
        return FUN_00c85750()->GetAllocator()->Allocate(bytes);
    }
};
struct FNVOwner {
    FNVBuffers*& Buffers() {
        return *reinterpret_cast<FNVBuffers**>(reinterpret_cast<char*>(this) + 0x214);
    }
    void hkpEntity_addEntityListener(int value);
};
// Ensures the buffers exist, stores value into the first empty element slot or appends it, growing the array when full.
// @f3 0x0090b880 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
void* __stdcall FUN_008f6800(int, int);
void __cdecl FUN_0098a9f0(FNVArray*, unsigned int);
// pdb: hkpEntity::addEntityListener | hkpEntity.obj | fnv360_0822_retail, call_seq + bridge(call_gap_sim|call_seq) + skyrim(objrun), high
void FNVOwner::hkpEntity_addEntityListener(int value) {
    FNVBuffers*& buffers = *reinterpret_cast<FNVBuffers**>(reinterpret_cast<char*>(this) + 0xcc);
    if (buffers == 0) {
        char* pool = static_cast<char*>(TlsGetValue(DAT_010f3170));
        void* block = *reinterpret_cast<void**>(pool + 0x48);
        if (block) {
            --*reinterpret_cast<int*>(pool + 0x4c);
            *reinterpret_cast<void**>(pool + 0x48) = *static_cast<void**>(block);
        } else {
            block = FUN_008f6800(2, 4);
        }
        if (block) {
            FNVBuffers* created = static_cast<FNVBuffers*>(block);
            created->spare.values = 0;
            created->spare.size = 0;
            created->spare.flags = 0x8000;
            created->elements.values = 0;
            created->elements.size = 0;
            created->elements.flags = 0x8000;
        } else {
            block = 0;
        }
        buffers = static_cast<FNVBuffers*>(block);
    }
    FNVArray& array = buffers->elements;
    for (int i = 0; i < array.size; ++i) {
        if (!array.values[i]) {
            if (i >= 0) {
                array.values[i] = value;
                return;
            }
            break;
        }
    }
    if (array.size == (array.flags & 0x3fff)) {
        FUN_0098a9f0(&array, sizeof(int));
    }
    array.values[array.size] = value;
    ++array.size;
}


namespace fnv_00cac120 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00cac120_cls {
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00cadb00();

    FUN_00cac120_cls* FUN_00cac120(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

}  // namespace fnv_00cac120

extern __declspec(thread) int g_tlsMemContext;

struct S_00cac150_Scope {
    int m_oldContext;
    S_00cac150_Scope(int ctx) {
        m_oldContext = g_tlsMemContext;
        g_tlsMemContext = ctx;
    }
    ~S_00cac150_Scope() {
        g_tlsMemContext = m_oldContext;
    }
};

struct CpuScalar {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int value;
};
struct CpuObject {
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
    CpuScalar* value;
    unsigned int FUN_00cac910();
};
// @fnv 0x00cac910
// pdb: hkpCharacterProxy::getPosition | hkpCharacterProxy.obj | tesv_win, call_seq, medium
unsigned int CpuObject::FUN_00cac910()
{
    return value->value + 48u;
}

extern float DAT_0101e2bc;

struct FUN_00cacf10_cls {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70;
    int m_74;
    int m_78;

    float FUN_00cafd90(void* a, void* b);
    int FUN_00cacf10(void* arg);
};

// @f3 0x0091e630 (community match, verified in this file)
struct ArgminLocal {
    volatile float best;
    volatile int idx;
};

struct Stub_00921660 {
    float hkpCharacterProxy_surfaceDistance(void* a, void* b);
};

// pdb: hkpCharacterProxy::findSurface | hkpCharacterProxy.obj | fnv360_0822_debug, callee_sim, low, conflict (skyrim: hkpCharacterProxy::fireContactAdded)
// pdb params: info
int FUN_00cacf10_cls::FUN_00cacf10(void* arg) {
    ArgminLocal s;
    s.best = DAT_0101e2bc;
    s.idx = -1;
    int i = 0;
    if (m_78 <= 0) {
        return -1;
    }
    do {
        float d = ((Stub_00921660*)this)->hkpCharacterProxy_surfaceDistance(arg, (void*)(m_74 + i * 0x40));
        if (d < s.best) {
            s.best = d;
            s.idx = i;
        }
    } while (++i < m_78);
    return s.idx;
}


// Stand-in model for the object whose method RemoveTarget is being rebuilt.
// Layout is taken from the original disassembly, not from the pack's unit file.

struct BhkShape {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char unk10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    unsigned char unk18;
};

// 0x70 bytes; the pointer to the shape sits at +0x48.
struct BhkElem {
    __int64 q00;
    __int64 q08;
    __int64 q10;
    __int64 q18;
    __int64 q20;
    __int64 q28;
    __int64 q30;
    __int64 q38;
    __int64 q40;
    BhkShape* p;
    __int64 q50;
    __int64 q58;
    __int64 q60;
    __int64 q68;
};

struct BhkTarget {
    void FUN_00c9c670(void* v);
};

struct BhkProxy {
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
    volatile BhkElem* m_elements;
    int m_uiItemCount;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    BhkTarget** m_ids;
    volatile int m_idcount;

    void RemoveTarget(BhkTarget* arg1);
};

// Notifies arg1, then removes matching elements and the id entry from the proxy's arrays, compacting both.
// @f3 0x0091ed00 (community match, verified in this file)
struct BhkElem40 {
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    int u20;
    int u24;
    BhkShape* p28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    void operator=(const BhkElem40& src) {
        f00 = src.f00;
        f04 = src.f04;
        f08 = src.f08;
        f0c = src.f0c;
        f10 = src.f10;
        f14 = src.f14;
        f18 = src.f18;
        f1c = src.f1c;
        u20 = src.u20;
        u24 = src.u24;
        p28 = src.p28;
        u2c = src.u2c;
        u30 = src.u30;
        u34 = src.u34;
        u38 = src.u38;
    }
};

struct E1StubRemoveTarget {
    void FUN_0090b960(void* p);
};

struct BhkProxyLayout {
    int unk[27];
    BhkElem40* m_elements;
    volatile int m_uiItemCount;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    BhkTarget** m_ids;
    volatile int m_idcount;
};

// pdb: hkpCharacterProxy::entityRemovedCallback | hkpCharacterProxy.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: entity
void BhkProxy::RemoveTarget(BhkTarget* pTarget)
{
    BhkProxyLayout* self = reinterpret_cast<BhkProxyLayout*>(this);
    void* pProxy;
    if ((int*)(&this->unk00) - 2)
        pProxy = (void*)this;
    else
        pProxy = (void*)0;
    reinterpret_cast<E1StubRemoveTarget*>(pTarget)->FUN_0090b960(pProxy);

    for (int i = self->m_uiItemCount - 1; i >= 0; --i) {
        BhkShape* p = self->m_elements[i].p28;
        BhkTarget* key;
        if (p->unk18 == 1)
            key = (BhkTarget*)((char*)p + p->unk10);
        else
            key = 0;
        if (key == pTarget) {
            --self->m_uiItemCount;
            self->m_elements[i] = self->m_elements[self->m_uiItemCount];
        }
    }

    int n = self->m_idcount;
    int idx = 0;
    bool found = false;
    while (idx < n) {
        if (self->m_ids[idx] == pTarget) {
            found = true;
            break;
        }
        ++idx;
    }
    if (!found)
        idx = -1;
    --self->m_idcount;
    int last = self->m_idcount;
    BhkTarget** ids = self->m_ids;
    ids[idx] = ids[last];
}


namespace fnv_00cada30 {
struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct PtrList {
    void** m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

AllocHolder* FUN_00c85750();
void ResizeAudioStream(void* allocator, PtrList* list, unsigned int elemSize);

}  // namespace fnv_00cada30

extern float DAT_0104da48;
struct __declspec(align(16)) Vec289 {float x,y,z,w;};
struct RootContact289 {
 Vec289 position,normal;
 void* rootA; unsigned shapeKeyA; unsigned pathA[8];
 void* rootB; unsigned shapeKeyB; unsigned pathB[8];
};
struct Allocator289 {virtual void f0();virtual void f1();virtual void f2();virtual void f3();__declspec(nothrow) virtual void Free(void*,unsigned) throw();};
struct Router289 {int unk00,unk04,unk08,unk0c;Allocator289* heap; Allocator289* GetAllocator() {return heap;}};
namespace Memory289 {extern "C" Router289* FUN_00c85750() throw();}
class hkpCdPointCollector {
public:
 __declspec(nothrow) __forceinline virtual ~hkpCdPointCollector() {}
 virtual void AddCdPoint(const void*)=0;
 virtual void reset() {limit=DAT_0104da48;}
 float limit;
 __declspec(nothrow) hkpCdPointCollector():limit(DAT_0104da48) {}
};
struct ContactArray289 {
 RootContact289* data;int count;unsigned capacity;
 RootContact289 local[8];
 __declspec(nothrow) ContactArray289():data(local),count(0),capacity(0x80000008) {}
 __declspec(nothrow) __forceinline ~ContactArray289() {
  Allocator289* alloc=Memory289::FUN_00c85750()->GetAllocator();
  count=0;
  if((capacity&0x80000000)==0) alloc->Free(data,(capacity&0x3fffffff)*sizeof(RootContact289));
  data=0;capacity=0x80000000;
 }
};
class hkpAllCdPointCollector:public hkpCdPointCollector {
public:
 ContactArray289 contacts;
 __declspec(nothrow) hkpAllCdPointCollector() {}
 __declspec(nothrow) __forceinline virtual ~hkpAllCdPointCollector() {}
 virtual void AddCdPoint(const void*);
 virtual void reset() {contacts.count=0;limit=DAT_0104da48;}
};

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

extern float DAT_0104da4c;

struct S00cacaa0_Vec {
    __m128 m_vComponents;
};

struct S00cacaa0_Base {
    unsigned int f00, f04, f08, f0c, f10, f14;
    S00cacaa0_Vec v20;
    S00cacaa0_Vec v30;
    S00cacaa0_Vec v40;
};

struct S00cacaa0_Input : S00cacaa0_Base {
    S00cacaa0_Vec v50;
    float f60;
    float f64;
    unsigned int f68;
    S00cacaa0_Input() { f04 = 0; f60 = DAT_0104da4c; }
};

struct S00cacaa0_Shape {
    unsigned int unk00, unk04, unk08;
    unsigned int m_type;
};

struct S00cacaa0_Coll {
    S00cacaa0_Shape* m_pCollisionShape;
};

typedef void (__cdecl *S00cacaa0_Fn)(S00cacaa0_Coll* a, S00cacaa0_Coll* b, S00cacaa0_Input* in, void* c, void* d);

namespace fnv_00cacf80 {
union __declspec(intrin_type) __declspec(align(16)) __m128 {struct {float x,y,z,w;};};
extern "C" {
__m128 _mm_load_ss(const float*);
void _mm_store_ss(float*,__m128);
__m128 _mm_set_ps1(float);
__m128 _mm_setzero_ps();
__m128 _mm_shuffle_ps(__m128,__m128,int);
__m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_add_ps(__m128,__m128);
__m128 _mm_sub_ps(__m128,__m128);
__m128 _mm_add_ss(__m128,__m128);
}

struct FloatMatrix3;
struct __declspec(align(16)) Vec4 {
    union {__m128 quad;struct {float x,y,z,w;};};
    __m128 load() const {return quad;}
    void set(__m128 v) {quad=v;}

    void setSub4(const Vec4& a,const Vec4& b){quad=_mm_sub_ps(a.quad,b.quad);}
    void sub4(const Vec4& b){quad=_mm_sub_ps(quad,b.quad);}
    void add4(const Vec4& b){quad=_mm_add_ps(quad,b.quad);}
    void setCross(const Vec4& a,const Vec4& b) {
        __m128 ay=_mm_shuffle_ps(a.quad,a.quad,0xc9),bz=_mm_shuffle_ps(b.quad,b.quad,0xd2);
        __m128 az=_mm_shuffle_ps(a.quad,a.quad,0xd2),by=_mm_shuffle_ps(b.quad,b.quad,0xc9);
        quad=_mm_sub_ps(_mm_mul_ps(ay,bz),_mm_mul_ps(az,by));
    }
    float dot3(const Vec4& b)const {
        __m128 t=_mm_mul_ps(quad,b.quad);
        __m128 y=_mm_shuffle_ps(t,t,0x55),z=_mm_shuffle_ps(t,t,0xaa);
        float result;_mm_store_ss(&result,_mm_add_ss(z,_mm_add_ss(y,t)));return result;
    }
    void FUN_00c7f750(const FloatMatrix3*, const Vec4*);
};
struct FloatMatrix3 { Vec4 rows[3]; };
struct ContactShape {
    int unk00,unk04,unk08,unk0c;
    signed char childOffset;
    char unk11,unk12,unk13,unk14,unk15,unk16,unk17;
    unsigned char active;
};
struct PropertyValue {unsigned __int64 data; unsigned int get() const {return (unsigned int)data;} };
struct ShapeAttribute {unsigned int kind,arg04; PropertyValue value;};
struct Motion {
    void** vtable;
    unsigned int unk04;
    unsigned char kind;
    unsigned char unk09,unk0a,unk0b;
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
    Vec4 reference;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    Vec4 inertiaAndMass;
    Vec4 translation;
    Vec4 angular;
};
struct ShapeData {
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
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    ShapeAttribute* attrs;
    int attrCount;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    Motion motion;
    bool hasProperty(unsigned int k) const {
        for (int i=0;i<attrCount;++i) if(attrs[i].kind==k) return true;
        return false;
    }
    __forceinline PropertyValue getProperty(unsigned int k) const {
        for (int i=0;i<attrCount;++i) if(attrs[i].kind==k) return attrs[i].value;
        PropertyValue z={0};return z;
    }
    void FUN_00c9c1d0();
};
struct ContactBlock {
    Vec4 position,normalAndDepth;
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
    ContactShape* shape;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
};
struct ContactSolver;
struct ContactListener {
    virtual void v0();virtual void v1();virtual void v2();virtual void v3();
    virtual void Begin(ContactSolver*,unsigned int,ContactBlock*);
    virtual void Post(ContactSolver*,Vec4*,Vec4*);
};
struct Output {Vec4 impulse,location;ShapeData* body;unsigned int unk24,unk28,unk2c;};
template<class T> struct ArrayBase {T* data;int size;unsigned int capacityFlags;T& operator[](int i) {return data[i];}};
template<class T> struct Array: ArrayBase<T> {};
struct ContactSolver {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    Vec4 localOrigin;
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    float minSpeed,correctionScale;
    Array<ContactBlock> contacts;
    ContactListener** listeners;
    int listenerCount;
    ContactListener*& listenerAt(int i) {return listeners[i];}
    void FUN_00cacf80(const float*,const Vec4*,Output**,int);
};
}  // namespace fnv_00cacf80

struct HkEntity289 {
    void FUN_00c9c670(void* listener) throw();
};
struct HkPhantom289 {
    void RemoveListener(void* listener) throw();
};
struct HkWorldLock289 {
    int unk00;
    int unk04;
};
struct HkWorld289 {
    void FUN_00cd2a50(HkWorldLock289* apOut, unsigned int auiFlags) throw();
    void FUN_00c905b0() throw();
};

template <class T> struct HkArray289 {
    T* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;

    void clear() { m_iElementCount = 0; }
    ~HkArray289() throw() {
        Allocator289* alloc = Memory289::FUN_00c85750()->GetAllocator();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc->Free(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct HkBaseObject289 {
    virtual ~HkBaseObject289() {}
};
struct HkReferencedObject289 : HkBaseObject289 {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct HkEntityListener289 {
    virtual ~HkEntityListener289() {}
};
struct HkPhantomListener289 {
    virtual ~HkPhantomListener289() {}
};

struct FUN_00cadb00 : HkReferencedObject289, HkEntityListener289, HkPhantomListener289 {
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    HkWorld289* m_pOwningWorld;
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
    HkArray289<BhkElem> m_elements;
    HkArray289<int> m_ids;
    HkArray289<HkEntity289*> m_kActorEntries;
    HkArray289<HkPhantom289*> m_kPhantoms;

    virtual ~FUN_00cadb00();
};

// Removes this listener from every entity and phantom, clears both arrays, then calls FUN_00cd2a50 and FUN_00c905b0 on m_pOwningWorld.
// @f3 0x0091f0b0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;

struct HkThreadMem289 {
    void FUN_008f6d90(void* p, unsigned int n, int tag) throw();
};

// The element arrays of FUN_00cadb00 are Havok arrays: releasing one asks the
// thread heap obtained from TLS to free capacity * element-stride bytes, tagged
// 0x17.  HkArray289's own destructor releases through Memory289, so the release
// path is specialized here for the four element types this class stores.
template <> HkArray289<BhkElem>::~HkArray289() throw()
{
    if ((m_iCapacityState & 0x80000000) == 0) {
        unsigned int n = m_iCapacityState & 0x3fffffff;
        HkThreadMem289* h = static_cast<HkThreadMem289*>(TlsGetValue(DAT_010f3170));
        h->FUN_008f6d90(m_data, n * 64, 0x17);   // 64-byte element stride
    }
}

template <> HkArray289<int>::~HkArray289() throw()
{
    if ((m_iCapacityState & 0x80000000) == 0) {
        unsigned int n = m_iCapacityState & 0x3fffffff;
        HkThreadMem289* h = static_cast<HkThreadMem289*>(TlsGetValue(DAT_010f3170));
        h->FUN_008f6d90(m_data, n * sizeof(int), 0x17);
    }
}

template <> HkArray289<HkEntity289*>::~HkArray289() throw()
{
    if ((m_iCapacityState & 0x80000000) == 0) {
        unsigned int n = m_iCapacityState & 0x3fffffff;
        HkThreadMem289* h = static_cast<HkThreadMem289*>(TlsGetValue(DAT_010f3170));
        h->FUN_008f6d90(m_data, n * sizeof(HkEntity289*), 0x17);
    }
}

template <> HkArray289<HkPhantom289*>::~HkArray289() throw()
{
    if ((m_iCapacityState & 0x80000000) == 0) {
        unsigned int n = m_iCapacityState & 0x3fffffff;
        HkThreadMem289* h = static_cast<HkThreadMem289*>(TlsGetValue(DAT_010f3170));
        h->FUN_008f6d90(m_data, n * sizeof(HkPhantom289*), 0x17);
    }
}

// pdb: hkpCharacterProxy::~hkpCharacterProxy | hkpCharacterProxy.obj | fnv360_0822_retail, call_seq, medium
FUN_00cadb00::~FUN_00cadb00()
{
    for (int i = 0; i < m_kActorEntries.m_iElementCount; i++) {
        m_kActorEntries.m_data[i]->FUN_00c9c670(static_cast<HkEntityListener289*>(this));
    }
    m_kActorEntries.clear();

    for (int i = 0; i < m_kPhantoms.m_iElementCount; i++) {
        m_kPhantoms.m_data[i]->RemoveListener(static_cast<HkPhantomListener289*>(this));
    }
    m_kPhantoms.clear();

    HkWorldLock289 lock;
    m_pOwningWorld->FUN_00cd2a50(&lock, 0x1300);
    m_pOwningWorld->FUN_00c905b0();
}


extern float DAT_0104da48;

struct S_Heap {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n) throw();
};

struct S_Router {
    int unk00, unk04, unk08, unk0C;
    S_Heap* m_pStreamAllocator;
    S_Heap& heap() { return *m_pStreamAllocator; }
};



struct __declspec(align(16)) S_Contact {
    int c00; int c04; int c08; int c0C; int c10; int c14; int c18;
    int c1C; int c20; int c24; int c28; int c2C; int c30; int c34;
    int c38; int c3C; int c40; int c44; int c48; int c4C; int c50;
    int c54; int c58; int c5C; int c60; int c64; int c68; int c6C;
};

struct S_CdBase {
    float m_eps;
    S_CdBase() throw() { m_eps = DAT_0104da48; }
    virtual ~S_CdBase() throw() {}
    virtual void v1();
};

struct S_Arr {
    S_Contact* m_data;
    int m_iElementCount;
    int m_cap;
    void _clearAndDeallocate(S_Heap& h) throw() {
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0) {
            h.ReturnMemory(m_data, (m_cap & 0x3fffffff) * (int)sizeof(S_Contact));
        }
        m_data = 0;
        m_cap = 0x80000000;
    }
    ~S_Arr() throw() {
        _clearAndDeallocate(((S_Router*)FUN_00c85750())->heap());
    }
};

struct S_InplArr : S_Arr {
    int unk0C;
    S_Contact m_store[8];
    S_InplArr() throw() {
        m_data = m_store;
        m_iElementCount = 0;
        m_cap = 0x80000008;
    }
};

struct S_Collector : S_CdBase {
    int unk08, unk0C;
    S_InplArr m_kHits;
    S_Collector() throw() { m_kHits.m_iElementCount = 0; }
    virtual ~S_Collector() throw() {}
};

// fires added/removed notifications and keeps entity/phantom listeners attached to the touched objects.

struct S_00caf4d0_Heap {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct S_00caf4d0_Stack {
    char* m_next;
    void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    void deallocateStack(void* p) throw() { m_next = (char*)p; }
};
struct S_00caf4d0_Router {
    S_00caf4d0_Stack m_aiEntries;
    int unk04;
    int unk08;
    int unk0C;
    S_00caf4d0_Heap* m_pStreamAllocator;
    S_00caf4d0_Stack& stack() throw() { return m_aiEntries; }
    S_00caf4d0_Heap& heap() throw() { return *m_pStreamAllocator; }
};
static __forceinline S_00caf4d0_Router* GetRouter37() throw() { return reinterpret_cast<S_00caf4d0_Router*>(FUN_00c85750()); }
void ResizeAudioStream(S_00caf4d0_Heap& alloc, void* array, int elemSize) throw();

inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }

struct __declspec(align(16)) S_00caf4d0_Vector4 {
    float x, y, z, w;
    S_00caf4d0_Vector4() throw() {}
    S_00caf4d0_Vector4(const S_00caf4d0_Vector4& v) throw()
    {
        reinterpret_cast<__m128&>(*this) = reinterpret_cast<const __m128&>(v);
    }
};

struct S_00caf4d0_Collidable {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset; // 0x10
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_type;               // 0x18
    void* getOwner() const throw() { return (void*)((char*)this + m_iOwnerOffset); }
};

struct S_00caf4d0_Point {
    S_00caf4d0_Vector4 m_vContactPosition;            // 0x00
    S_00caf4d0_Vector4 m_vSeparatingNormal;    // 0x10 (w = distance)
    int m_pCollidableA;                        // 0x20
    int m_uiShapeKeyA;                          // 0x24
    int m_kContactPointB[8];                      // 0x28
    S_00caf4d0_Collidable* m_pCollidableB;     // 0x48
    int m_uiShapeKeyB;                          // 0x4c
    int m_kContactPointC[8];                      // 0x50

    S_00caf4d0_Point& operator=(const S_00caf4d0_Point& other) throw();
    float getDistance() const throw() { return m_vSeparatingNormal.w; }
};

static __forceinline void memCpy8(void* dst, const void* src, int n) throw()
{
    const unsigned __int64* s = (const unsigned __int64*)src;
    unsigned __int64* d = (unsigned __int64*)dst;
    for (int i = 0; i < n; i++)
        d[i] = s[i];
}

template <class T> __forceinline void constructWithCopy(T* p, const T& t) throw()
{
    new (p) T(t);
}
template <class T> __forceinline void constructWithCopy(T** p, T* const& t) throw()
{
    for (int k = 0; k < 1; k++)
        p[k] = t;
}

template <class T> struct S_00caf4d0_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const throw() { return m_iElementCount; }
    T& operator[](int i) throw() { return m_data[i]; }
    const T& operator[](int i) const throw() { return m_data[i]; }
    void clear() throw() { m_iElementCount = 0; }
    int indexOf(const T& t) const throw()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void AddBack(const T& t) throw()
    {
        S_00caf4d0_Router* router = GetRouter37();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->heap(), this, sizeof(T));
        constructWithCopy(m_data + m_iElementCount, t);
        m_iElementCount++;
    }
    void removeAt(int index) throw()
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy8(m_data + index, m_data + m_iElementCount, sizeof(T) / 8);
    }
};

template <class T> struct S_00caf4d0_LocalArray : S_00caf4d0_Array<T> {
    T* m_pStackAllocation;
    __forceinline S_00caf4d0_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)GetRouter37()->stack().allocateStack(capacity * sizeof(T));
        this->m_iElementCount = 0;
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~S_00caf4d0_LocalArray() throw()
    {
        GetRouter37()->stack().deallocateStack(m_pStackAllocation);
        S_00caf4d0_Heap& heap = GetRouter37()->heap();
        if ((this->m_iCapacityState & 0x80000000) == 0)
            heap.ReturnMemory(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
};

extern float DAT_0104da48;

struct CadColl {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    unsigned char m_type;
    void* getOwner() const throw() { return (void*)((char*)this + m_iOwnerOffset); }
};

struct CadPhantomListener {
    virtual void plUnk00();
    virtual void FUN_00cad820(struct CadPhantom* p) throw();
};
struct CadPhantom {
    void RemoveListener(CadPhantomListener* l) throw();
};
struct CadPtrArray {
    CadPhantom** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const throw() { return m_iElementCount; }
    CadPhantom*& operator[](int i) throw() { return m_data[i]; }
    int indexOf(CadPhantom* const& t) const throw()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int index) throw()
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_setzero_ps(void);

struct S00cafd90_Vec {
    __m128 m_vComponents;
};

struct S00cafd90_Info {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char unk10;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char unk18;
};

struct S00cafd90_Body;

struct S00cafd90_Body {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00cafd90_Vec unk10;
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
    S00cafd90_Info* unk48;
};

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(const float* p);
typedef float S00cacd60_Real;
class S00cacd60_SimdReal {
public:
    S00cacd60_SimdReal(const __m128& x) : m_vValue(x) {}
    S00cacd60_SimdReal(S00cacd60_Real x) { m_vValue = _mm_load_ss(&x); }
    operator S00cacd60_Real() const {
        S00cacd60_Real s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
private:
    __m128 m_vValue;
};
typedef const S00cacd60_SimdReal& S00cacd60_SimdParam;
class S00cacd60_Vec {
public:
    __forceinline S00cacd60_Vec() {}
    __forceinline void operator=(const S00cacd60_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline S00cacd60_Real& operator()(int a) { return reinterpret_cast<S00cacd60_Real*>(&m_vComponents)[a]; }
    __forceinline const S00cacd60_Real& operator()(int a) const { return reinterpret_cast<const S00cacd60_Real*>(&m_vComponents)[a]; }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void add4(const S00cacd60_Vec& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const S00cacd60_Vec& a, const S00cacd60_Vec& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(S00cacd60_SimdParam s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void setMul4(S00cacd60_SimdParam r, const S00cacd60_Vec& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
    __forceinline void addMul4(S00cacd60_SimdParam r, const S00cacd60_Vec& v) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents)); }
    __forceinline void setCross(const S00cacd60_Vec& v0, const S00cacd60_Vec& v1) {
        __m128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline S00cacd60_SimdReal dot3(const S00cacd60_Vec& a) const {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __m128 m_vComponents;
};
class S00cacd60_Bool {
public:
    __forceinline S00cacd60_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};
struct S00cacd60_Swept {
    S00cacd60_Vec m_vCenterOfMass0;
    S00cacd60_Vec m_vCenterOfMass1;
    __forceinline S00cacd60_Real getInvDeltaTime() const { return m_vCenterOfMass1(3); }
};
enum S00cacd60_MotionType { S00cacd60_KEYFRAMED = 4, S00cacd60_FIXED = 5 };
struct S00cacd60_MotionState {
    S00cacd60_Vec m_t0; S00cacd60_Vec m_t1; S00cacd60_Vec m_t2; S00cacd60_Vec m_t3;
    S00cacd60_Swept m_kSweptTransform;
    S00cacd60_Vec m_qRotation0; S00cacd60_Vec m_qRotation1; S00cacd60_Vec m_vCenterOfMassLocal;
    S00cacd60_Vec m_kDeltaAngle;
    __forceinline const S00cacd60_Swept& getSweptTransform() const { return m_kSweptTransform; }
};
struct S00cacd60_Motion {
    void* vtbl;
    int m_refs;
    signed char m_type;
    int unk0c;
    S00cacd60_MotionState m_kMotionState;
    __forceinline S00cacd60_MotionType getType() const { return static_cast<S00cacd60_MotionType>(m_type); }
    __forceinline S00cacd60_MotionState* GetMotionState() { return &m_kMotionState; }
};
struct S00cacd60_Collidable {
    int m_pCollisionShape; int m_uiCollisionShapeKey; int m_pMotionState; int m_parent;
    signed char m_iOwnerOffset;
    int m_iOwnerObjectOffset;
    signed char m_type;
    __forceinline int getType() const { return m_type; }
    __forceinline void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this) + m_iOwnerOffset); }
};
class S00cacd60_Body {
public:
    S00cacd60_Collidable m_coll;
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
    S00cacd60_Motion m_pMotionState;
    __forceinline S00cacd60_Motion* getRigidMotion() const { return const_cast<S00cacd60_Motion*>(&m_pMotionState); }
    __forceinline S00cacd60_MotionType getMotionType() const { return getRigidMotion()->getType(); }
    __forceinline S00cacd60_Bool isFixedOrKeyframed() const { return (m_pMotionState.m_type == S00cacd60_FIXED) || (m_pMotionState.m_type == S00cacd60_KEYFRAMED); }
    __forceinline const S00cacd60_Vec& getCenterOfMassInWorld() const { return getRigidMotion()->GetMotionState()->getSweptTransform().m_vCenterOfMass1; }
    void FUN_00ca0c40(const S00cacd60_Vec& p, S00cacd60_Vec& vel) const;
};
struct S00cacd60_Contact {
    S00cacd60_Vec m_vContactPosition;
    S00cacd60_Vec m_vSeparatingNormal;
    __forceinline const S00cacd60_Vec& getPosition() const { return m_vContactPosition; }
    __forceinline const S00cacd60_Vec& getNormal() const { return m_vSeparatingNormal; }
    __forceinline const S00cacd60_Vec& getSeparatingNormal() const { return m_vSeparatingNormal; }
};

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct __declspec(align(16)) Contact {
    __m128 normal;
    __m128 tangent;
    float distance;
    float friction;
    float restitution;
    float bias;
    unsigned int identifier;
    unsigned int contactFlags;
    float accumulatedImpulse;
    float reservedWeight;
};

struct ContactBuffer {
    Contact* entries;
    unsigned int count;
    unsigned int capacityFlags;
};

volatile unsigned g_i; ContactBuffer* volatile g_b; volatile float g_d; const __m128* volatile g_p; volatile int g_o;

extern "C" void _mm_store_ps(float*, __m128);

__declspec(align(16)) struct S_V4 { float x, y, z, w; };

template<class T> struct S_Pad { T* p; T* val() const { return p; } };

#include <math.h>
extern "C" void _ReadWriteBarrier(void);

extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_setzero_ps(void);

struct S_00cad500_V4 {
    float x, y, z, w;
};

struct S_00cad500_Elem16 {
    int m_iOwnerObjectOffset;
    int unk04;
    int unk08;
    int unk0C;
};

struct S_00cad500_This;

struct S_00cad500_Pair {
    S_00cad500_This* a;
    int b;
    S_00cad500_Pair(S_00cad500_This* a_, int b_) { a = a_; b = b_; }
    S_00cad500_Pair(const S_00cad500_Pair& o) { a = o.a; b = o.b; }
};

struct S_00cad500_Ref {
    int unk00;
    int unk04;
    int m_08;
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
    S_00cad500_Elem16* m_78;
    int m_7c;
    void FUN_00c90510();
    void FUN_00c905b0();
    void AddEntry(int id, S_00cad500_Pair p);
};

struct S_00cad500_E1 {
    void FUN_00c9c670(void* p);
};
struct S_00cad500_E2 {
    void RemoveListener(void* p);
};


struct S_00cad500_Src {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00cad500_V4 m_10;
    float m_20;
    float m_24;
    float m_28;
    int unk2C;
    S_00cad500_V4 m_30;
    float m_40;
    float m_44;
    S_00cad500_Ref* m_48;
    float m_4c;
    float m_50;
    int m_54;
    float m_58;
    float m_5c;
    float m_60;
    float m_64;
    float m_68;
    int m_6c;
    char m_70;
    int unk71;
};

struct S_00cad500_This {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00cad500_V4 m_10;
    S_00cad500_V4 m_20;
    S_00cad500_Ref* m_30;
    float m_34;
    float m_38;
    int unk3C;
    S_00cad500_V4 m_40;
    float m_50;
    float m_54;
    float m_58;
    float m_5c;
    float m_60;
    int m_64;
    float m_68;
    float m_6c;
    float m_70;
    int unk74;
    int m_78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    S_00cad500_E1** m_8c;
    int m_90;
    int unk94;
    S_00cad500_E2** m_98;
    int m_9c;
    int unkA0;
    float m_a4;
    float m_a8;
    int m_ac;
    char m_b0;
    int unkB1;
    void FUN_00cad500(S_00cad500_Src* a);
    void FUN_00cac920(S_00cad500_Src* a);
};

__forceinline void S_00cad500_Normalize3(S_00cad500_V4& v, float zero, float three, float half)
{
    __m128 q = reinterpret_cast<__m128&>(v);
    __m128 t = _mm_mul_ps(q, q);
    __m128 l = _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t);
    l = _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), l);
    __m128 r = _mm_rsqrt_ss(l);
    __m128 mask = _mm_cmpeq_ss(l, _mm_set_ss(zero));
    __m128 lrr = _mm_mul_ss(_mm_mul_ss(l, r), r);
    __m128 inv = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(half), r), _mm_sub_ss(_mm_set_ss(three), lrr));
    inv = _mm_andnot_ps(mask, inv);
    inv = _mm_shuffle_ps(inv, inv, 0);
    reinterpret_cast<__m128&>(v) = _mm_mul_ps(inv, q);
}

// Copies fields from a, normalizes m_40, zeroes m_20, runs FUN_00c9c670/RemoveListener over the m_8c and m_98 entries, then registers 0x1300 on m_30 unless present.
// @f3 0x0091df10 (community match, verified in this file)
struct S_00cad500_RefStub
{
    void FUN_009316e0();
    void FUN_009316f0();
    void hkpWorldObject_addProperty(int id, S_00cad500_Pair p);
};
struct S_00cad500_E1Stub
{
    void FUN_0090b960(void* p);
};
struct S_00cad500_E2Stub
{
    void hkpPhantom_removePhantomListener(void* p);
};
struct S_00cad500_ThisStub
{
    void hkpCharacterProxy_setPosition(S_00cad500_Src* a);
};

void S_00cad500_This::FUN_00cad500(S_00cad500_Src* apSrc)
{
    reinterpret_cast<S_00cad500_RefStub*>(apSrc->m_48)->FUN_009316e0();
    if (m_30) {
        reinterpret_cast<S_00cad500_RefStub*>(m_30)->FUN_009316f0();
    }
    m_10.x = apSrc->m_10.x;
    m_10.y = apSrc->m_10.y;
    m_10.z = apSrc->m_10.z;
    m_10.w = apSrc->m_10.w;
    m_34 = apSrc->m_20;
    m_38 = apSrc->m_24;
    m_5c = apSrc->m_28;
    m_50 = apSrc->m_40;
    m_54 = apSrc->m_44;
    m_58 = apSrc->m_4c;
    m_30 = apSrc->m_48;
    m_60 = apSrc->m_50;
    m_64 = apSrc->m_54;
    m_68 = apSrc->m_58;
    m_6c = apSrc->m_5c;
    m_70 = apSrc->m_60;
    float c = (float)cos(apSrc->m_64);
    m_a4 = c;
    m_a8 = apSrc->m_68;
    m_ac = apSrc->m_6c;
    m_b0 = apSrc->m_70;
    m_40.x = apSrc->m_30.x;
    m_40.y = apSrc->m_30.y;
    m_40.z = apSrc->m_30.z;
    m_40.w = apSrc->m_30.w;
    float l = (m_40.x * m_40.x + m_40.y * m_40.y) + m_40.z * m_40.z;
    float inv;
    if (l != 0.0f) {
        float s = (float)sqrt(l);
        inv = 1.0f / s;
    } else {
        inv = 0.0f;
    }
    m_40.x = m_40.x * inv;
    m_40.y = m_40.y * inv;
    m_40.z = m_40.z * inv;
    m_40.w = m_40.w * inv;
    _ReadWriteBarrier();
    if (m_30->m_08 != 0) {
        reinterpret_cast<S_00cad500_ThisStub*>(this)->hkpCharacterProxy_setPosition(apSrc);
    }
    int i = 0;
    m_20.w = 0.0f;
    m_20.z = 0.0f;
    m_20.y = 0.0f;
    m_20.x = 0.0f;
    _ReadWriteBarrier();
    for (; i < m_90; i++) {
        reinterpret_cast<S_00cad500_E1Stub*>(m_8c[i])->FUN_0090b960(&unk08);
    }
    m_90 = 0;
    for (int j = 0; j < m_9c; j++) {
        reinterpret_cast<S_00cad500_E2Stub*>(m_98[j])->hkpPhantom_removePhantomListener(&unk0C);
    }
    m_9c = 0;
    m_78 = 0;
    for (int k = 0, n = (int)(intptr_t)m_30->m_78; k < n; k++) {
        if (((S_00cad500_Elem16*)(intptr_t)m_30->unk74)[k].m_iOwnerObjectOffset == 0x1300) {
            return;
        }
    }
    reinterpret_cast<S_00cad500_RefStub*>(m_30)->hkpWorldObject_addProperty(0x1300, S_00cad500_Pair(this, 0));
}


typedef float hkReal;

struct hkVector4 {
    __m128 m_vComponents;
    void operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; }
};

struct hkpCharacterProxyCinfo {
    hkVector4 m_vContactPosition;
    hkVector4 m_fVelocity;
    hkReal m_fDynamicFriction;
    hkReal m_fStaticFriction;
    hkReal m_fKeepContactTolerance;
    int m_2c;
    hkVector4 m_vStart;
    hkReal m_fExtraUpStaticFriction;
    hkReal m_fExtraDownStaticFriction;
    void* m_pCharacterPhantom;
    hkReal m_fKeepDistance;
    hkReal m_fContactAngleSensitivity;
    int m_uiUserPlanes;
    hkReal m_fMaxCharacterSpeedForSolver;
    hkReal m_fCharacterStrength;
    hkReal m_fCharacterMass;
    hkReal m_fMaximumSlope;
    hkReal m_fPenetrationRecoverySpeed;
    int m_iMaxCastIterations;
    bool m_bRefreshManifoldInCheckSupport;
};

namespace MathUtilities {
    inline hkReal fabs(hkReal r) { return hkReal(::fabs(r)); }
    inline hkReal acos(hkReal r)
    {
        if (MathUtilities::fabs(r) >= 1.0f)
        {
            r = (r > 0) ? 0 : 3.14159265358979f;
            return r;
        }
        return hkReal(::acos(r));
    }
}

struct hkpCharacterProxy {
    int m_00, m_04, m_08, m_0c;
    hkVector4 m_fVelocity;
    int m_20, m_24, m_28, m_2c;
    void* m_pCharacterPhantom;
    hkReal m_fDynamicFriction;
    hkReal m_fStaticFriction;
    int m_3c;
    hkVector4 m_vStart;
    hkReal m_fExtraUpStaticFriction;
    hkReal m_fExtraDownStaticFriction;
    hkReal m_fKeepDistance;
    hkReal m_fKeepContactTolerance;
    hkReal m_fContactAngleSensitivity;
    int m_uiUserPlanes;
    hkReal m_fMaxCharacterSpeedForSolver;
    hkReal m_fCharacterStrength;
    hkReal m_fCharacterMass;
    int m_74, m_78, m_7c, m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0;
    hkReal m_fMaximumSlopeAngle;
    hkReal m_fPenetrationRecoverySpeed;
    int m_iMaxCastIterations;
    bool m_bRefreshManifoldInCheckSupport;

    const hkVector4& getPosition() const;
    void FUN_00cac9a0(hkpCharacterProxyCinfo& info) const;
};

// @f3 0x0091ddf0 (community match, verified in this file)
static void CopyVec(hkVector4& dst, const hkVector4& src)
{
    float* d = reinterpret_cast<float*>(&dst);
    const float* s = reinterpret_cast<const float*>(&src);
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
}

void hkpCharacterProxy::FUN_00cac9a0(hkpCharacterProxyCinfo& info) const
{
    CopyVec(info.m_vContactPosition, getPosition());
    CopyVec(info.m_fVelocity, m_fVelocity);
    info.m_pCharacterPhantom = m_pCharacterPhantom;
    info.m_fDynamicFriction = m_fDynamicFriction;
    info.m_fStaticFriction = m_fStaticFriction;
    info.m_fKeepContactTolerance = m_fKeepContactTolerance;
    CopyVec(info.m_vStart, m_vStart);
    info.m_fExtraUpStaticFriction = m_fExtraUpStaticFriction;
    info.m_fExtraDownStaticFriction = m_fExtraDownStaticFriction;
    info.m_fKeepDistance = m_fKeepDistance;
    info.m_fContactAngleSensitivity = m_fContactAngleSensitivity;
    info.m_uiUserPlanes = m_uiUserPlanes;
    info.m_fMaxCharacterSpeedForSolver = m_fMaxCharacterSpeedForSolver;
    info.m_fCharacterStrength = m_fCharacterStrength;
    info.m_fCharacterMass = m_fCharacterMass;
    info.m_fMaximumSlope = MathUtilities::acos(m_fMaximumSlopeAngle);
    info.m_fPenetrationRecoverySpeed = m_fPenetrationRecoverySpeed;
    info.m_iMaxCastIterations = m_iMaxCastIterations;
    info.m_bRefreshManifoldInCheckSupport = m_bRefreshManifoldInCheckSupport;
}


namespace sse_ca0c40 {
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
};
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ps(float* p, __m128 a);
}

static const float DAT_010c851c = -0.08f;
extern const __m128 DAT_01017d10;
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
__m128 _mm_and_ps(__m128, __m128);
__m128 _mm_cmple_ps(__m128, __m128);
int _mm_movemask_ps(__m128);
__m128 _mm_set_ps1(float);
__m128 _mm_setr_ps(float, float, float, float);
}
extern DWORD DAT_0126835c;
typedef __m128 S00cae900_Quad;
typedef float S00cae900_Real;

class S00cae900_SimdReal {
public:
    S00cae900_SimdReal(const S00cae900_Quad& x) : m_vValue(x) {}
    S00cae900_SimdReal(S00cae900_Real x) { m_vValue = _mm_load_ss(&x); }
    operator S00cae900_Real() const {
        S00cae900_Real s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline S00cae900_Quad broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const S00cae900_Quad& getQuad() const { return m_vValue; }
private:
    S00cae900_Quad m_vValue;
};
typedef const S00cae900_SimdReal& S00cae900_SimdParam;

class S00cae900_Comparison {
public:
    enum Mask { MASK_XYZ = 7 };
    __forceinline int allAreSet(Mask m) const { return (_mm_movemask_ps(m_uiMask) & m) == m; }
    S00cae900_Quad m_uiMask;
};

// hkVector4
class S00cae900_Vec {
public:
    __forceinline S00cae900_Vec() {}
    __forceinline void operator=(const S00cae900_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void SetAllComponents(S00cae900_Real a) { m_vComponents = _mm_set_ps1(a); }
    __forceinline void set(S00cae900_Real a, S00cae900_Real b, S00cae900_Real c, S00cae900_Real d = 0.0f) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    __forceinline void setAll3(S00cae900_Real a) { m_vComponents = _mm_set_ps1(a); }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void add4(const S00cae900_Vec& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const S00cae900_Vec& a, const S00cae900_Vec& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setSub4(const S00cae900_Vec& a, const S00cae900_Vec& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAbs4(const S00cae900_Vec& v) {
        m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10);
    }
    __forceinline S00cae900_Comparison compareLessThanEqual4(const S00cae900_Vec& a) const {
        S00cae900_Comparison m;
        m.m_uiMask = _mm_cmple_ps(m_vComponents, a.m_vComponents);
        return m;
    }
    __forceinline int equals3(const S00cae900_Vec& v, S00cae900_Real epsilon = 1e-3f) const;
    __forceinline void sub4(const S00cae900_Vec& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void mul4(S00cae900_SimdParam s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void addMul4(S00cae900_SimdParam r, const S00cae900_Vec& v) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents)); }
    __forceinline void setAddMul4(const S00cae900_Vec& a, const S00cae900_Vec& b, S00cae900_SimdParam r) { m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents)); }
    __forceinline S00cae900_SimdReal dot3(const S00cae900_Vec& a) const {
        S00cae900_Quad x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        S00cae900_Quad xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00cae900_SimdReal lengthSquared3() const { return dot3(*this); }
    __forceinline S00cae900_SimdReal lengthInverse3() const {
        const S00cae900_Quad half = _mm_set_ss(0.5f);
        const S00cae900_Quad three = _mm_set_ss(3.0f);
        const S00cae900_Quad zero = _mm_set_ss(0.0f);
        const S00cae900_Quad len2 = dot3(*this).getQuad();
        const S00cae900_Quad len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const S00cae900_Quad approx = _mm_rsqrt_ss(len2);
        const S00cae900_Quad refined = _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3() {
        S00cae900_Quad lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    S00cae900_Quad m_vComponents;
};

// hkBool
class S00cae900_Bool {
public:
    __forceinline S00cae900_Bool() {}
    __forceinline S00cae900_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    __forceinline void operator=(bool b) { m_cBooleanValue = static_cast<char>(b); }
    char m_cBooleanValue;
};

struct S00cae900_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename TYPE>
    __forceinline void _bufFree(void* p, int numElem) {
        const int SIZE_ELEM = sizeof(TYPE);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};
__forceinline void* S00cae900_addByteOffset(void* base, int offset) { return reinterpret_cast<char*>(base) + offset; }
class S00cae900_Stack {
public:
    __forceinline void* allocateStack(int numBytes, const char* what) {
        void* current = m_next;
        m_next = S00cae900_addByteOffset(current, numBytes);
        return current;
    }
    __forceinline void* allocateStackRoundSizeTo128(int numBytes, const char* what) {
        int allocationSize = (numBytes + 127) & ~127;
        return allocateStack(allocationSize, what);
    }
    __forceinline void deallocateStack(void* p) { m_next = p; }
    void* m_next;
    int unk04;
    int unk08;
    int unk0c;
};
class S00cae900_Router {
public:
    __forceinline S00cae900_Stack& stack() { return m_aiEntries; }
    __forceinline S00cae900_Alloc& heap() { return *m_pStreamAllocator; }
    S00cae900_Stack m_aiEntries;
    S00cae900_Alloc* m_pStreamAllocator;
};
__forceinline S00cae900_Router& S00cae900_getRouter() { return *reinterpret_cast<S00cae900_Router*>(FUN_00c85750()); }

template <typename T>
__forceinline T* S00cae900_allocateStack(int n, const char* what = 0) {
    S00cae900_Router& mem = S00cae900_getRouter();
    return static_cast<T*>(mem.stack().allocateStack((n * sizeof(T) + 127) & ~127, what));
}
template <typename T>
__forceinline void S00cae900_deallocateStack(T* ptr) { S00cae900_getRouter().stack().deallocateStack(static_cast<void*>(ptr)); }

struct S00cae900_HeapAllocator {
    __forceinline S00cae900_Alloc& get(const void*) { return S00cae900_getRouter().heap(); }
};
template <bool N> struct S00cae900_TraitBool { typedef S00cae900_TraitBool<N> type; };
typedef S00cae900_TraitBool<true> S00cae900_TypeIsPod;
typedef S00cae900_TraitBool<false> S00cae900_TypeIsClass;
template <typename T> struct S00cae900_IsPodType : public S00cae900_TraitBool<false> {};
template <> struct S00cae900_IsPodType<S00cae900_Vec> : public S00cae900_TraitBool<true> {};
struct S00cae900_PlacementNewArg;
inline void* operator new(unsigned int, S00cae900_PlacementNewArg* p) { return p; }
template <typename T> __forceinline void S00cae900_construct(T* t, int n, S00cae900_TypeIsPod) {}
template <typename T> __forceinline void S00cae900_construct(T* t, int n, S00cae900_TypeIsClass) {
    for (int i = 0; i < n; ++i) {
        ::new (reinterpret_cast<S00cae900_PlacementNewArg*>(t + i)) T;
    }
}
template <typename T> __forceinline void S00cae900_destruct(T* t, int n, S00cae900_TypeIsPod) {}
template <typename T> __forceinline void S00cae900_destruct(T* t, int n, S00cae900_TypeIsClass) {
    for (int i = 0; i < n; ++i) {
        static_cast<T*>(t)[i].~T();
    }
}

struct S00cae900_ArrRaw;
extern "C" void __cdecl ResizeAudioStream(S00cae900_Alloc& alloc, S00cae900_ArrRaw* arr, int elemSize);
extern "C" void __cdecl FUN_00c908c0(S00cae900_Alloc& alloc, S00cae900_ArrRaw* arr, int newCap, int elemSize);

template <typename T>
class S00cae900_ArrayBase {
public:
    enum { CAPACITY_MASK = 0x3fffffff, DONT_DEALLOCATE_FLAG = 0x80000000 };
    __forceinline S00cae900_ArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG) {}
    __forceinline void destroyBase() {}
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & CAPACITY_MASK; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline T* begin() { return m_data; }
    __forceinline void _clearAndDeallocate(S00cae900_Alloc& alloc) {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void clear() {
        S00cae900_destruct(m_data, m_iElementCount, typename S00cae900_IsPodType<T>::type());
        m_iElementCount = 0;
    }
    __forceinline void setSizeUnchecked(int n) {
        S00cae900_destruct(m_data + n, m_iElementCount - n, typename S00cae900_IsPodType<T>::type());
        S00cae900_construct(m_data + m_iElementCount, n - m_iElementCount, typename S00cae900_IsPodType<T>::type());
        m_iElementCount = n;
    }
    __forceinline void GrowArrayCapacity(S00cae900_Alloc& alloc, int n) {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, reinterpret_cast<S00cae900_ArrRaw*>(this), newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S00cae900_Alloc& alloc, int n) {
        GrowArrayCapacity(alloc, n);
        S00cae900_destruct(m_data + n, m_iElementCount - n, typename S00cae900_IsPodType<T>::type());
        S00cae900_construct(m_data + m_iElementCount, n - m_iElementCount, typename S00cae900_IsPodType<T>::type());
        m_iElementCount = n;
    }
    __forceinline T& _expandOne(S00cae900_Alloc& alloc) {
        if (m_iElementCount == getCapacity()) {
            ResizeAudioStream(alloc, reinterpret_cast<S00cae900_ArrRaw*>(this), sizeof(T));
        }
        S00cae900_construct(m_data + m_iElementCount, 1, typename S00cae900_IsPodType<T>::type());
        return m_data[m_iElementCount++];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T>
class S00cae900_Array : public S00cae900_ArrayBase<T> {
public:
    __forceinline S00cae900_Array() {}
    __forceinline void reserve(int n) { this->GrowArrayCapacity(S00cae900_HeapAllocator().get(this), n); }
    __forceinline void SetSizeAndGrow(int n) { this->_setSize(S00cae900_HeapAllocator().get(this), n); }
    __forceinline T& AllocatePair() { return this->_expandOne(S00cae900_HeapAllocator().get(this)); }
    __forceinline void ClearAndRelease() { this->_clearAndDeallocate(S00cae900_HeapAllocator().get(this)); }
    __forceinline void destroyArray() {
        ClearAndRelease();
        this->destroyBase();
    }
};

template <typename T>
class S00cae900_LocalArray : public S00cae900_Array<T> {
public:
    __forceinline S00cae900_LocalArray(int capacity) {
        this->m_data = S00cae900_allocateStack<T>(capacity);
        this->m_iCapacityState = capacity | S00cae900_ArrayBase<T>::DONT_DEALLOCATE_FLAG;
        m_pStackAllocation = this->m_data;
    }
    __forceinline S00cae900_Bool wasReallocated() const { return m_pStackAllocation != this->m_data; }
    __forceinline void destruct() {
        if (!wasReallocated()) {
            this->clear();
        }
        S00cae900_deallocateStack<T>(m_pStackAllocation);
        this->destroyArray();
    }
    T* m_pStackAllocation;
};

struct S00cae900_ConstraintInfo {
    S00cae900_Vec m_kTriangleNormal;
    S00cae900_Vec m_fVelocity;
    float m_fStaticFriction;
    float m_fExtraUpStaticFriction;
    float m_fExtraDownStaticFriction;
    float m_fDynamicFriction;
    int m_priority;
};
struct S00cae900_Interaction {
    unsigned char m_ucByte0;
    unsigned char m_ucByte1;
    float m_fValue0;
    float m_fValue1;
    int m_iResultCode;
};
struct S00cae900_SolverInput {
    __forceinline S00cae900_SolverInput() {
        m_vFourthInputVector.set(0, 1, 0);
        m_vThirdInputVector.setAll3(1.192092896e-07f);
        m_vContactPosition.setZero4();
    }
    S00cae900_Vec m_vContactPosition;
    S00cae900_Vec m_fVelocity;
    S00cae900_Vec m_vThirdInputVector;
    S00cae900_Vec m_vFourthInputVector;
    float m_fTimeStep;
    float m_fConstraintParameter;
    S00cae900_ConstraintInfo* m_ppConstraints;
    int m_iConstraintCount;
};
struct S00cae900_SolverOutput {
    S00cae900_Vec m_vContactPosition;
    S00cae900_Vec m_fVelocity;
    float m_fTimeStep;
    S00cae900_Interaction* m_pPlaneStatuses;
};
// hkpSurfaceInfo
struct S00cae900_SurfaceInfo {
    enum SupportedState { UNSUPPORTED = 0, SLIDING = 1, SUPPORTED = 2 };
    SupportedState m_eSupportedState;
    S00cae900_Vec m_vNormal;
    S00cae900_Vec m_vSurfaceVelocity;
    float m_fSurfaceDistance;
};

extern "C" void __cdecl FUN_00d24360(const S00cae900_SolverInput& input, S00cae900_SolverOutput& output);

class S00cae900_PadPtr {
public:
    __forceinline void operator=(char* e) { m_kStorage = e; }
    __forceinline char* val() const { return m_kStorage; }
    char* m_kStorage;
};
class S00cae900_Monitor {
public:
    struct CommandTimingEntry {
        const char* m_pCommandName;
        unsigned int m_uiStartTicks;
        unsigned int m_uiEndTicks;
        __forceinline void setTime() {
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_uiStartTicks = ticks;
        }
    };
    static __forceinline S00cae900_Monitor& GetMonitorStream() { return *static_cast<S00cae900_Monitor*>(TlsGetValue(DAT_0126835c)); }
    __forceinline char* GetStreamEnd() { return m_kRayEnd.val(); }
    __forceinline char* getCapacityMinus16() { return m_pCurrentCommand.val(); }
    __forceinline S00cae900_Bool memoryAvailable() { return GetStreamEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_kRayEnd = ptr; }
    S00cae900_PadPtr m_kRayStart;
    S00cae900_PadPtr m_kRayEnd;
    S00cae900_PadPtr m_pRayCursor;
    S00cae900_PadPtr m_pCurrentCommand;
};

typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
__m128 _mm_set_ps1(float);
__m128 _mm_setr_ps(float, float, float, float);
}
extern DWORD DAT_0126835c;
static const float kInvSixtySV = 1.0f / 60.0f;
static const float kMinSurfaceDotSV = -0.08f;
typedef __m128 S00caefd0_Quad;
typedef float S00caefd0_Real;

class S00caefd0_SimdReal {
public:
    S00caefd0_SimdReal(const S00caefd0_Quad& x) : m_vValue(x) {}
    S00caefd0_SimdReal(S00caefd0_Real x) { m_vValue = (_mm_load_ss)(&x); }
    operator S00caefd0_Real() const {
        S00caefd0_Real s;
        (_mm_store_ss)(&s, m_vValue);
        return s;
    }
    __forceinline S00caefd0_Quad broadcast() const { return (_mm_shuffle_ps)(m_vValue, m_vValue, 0); }
    __forceinline const S00caefd0_Quad& getQuad() const { return m_vValue; }
private:
    S00caefd0_Quad m_vValue;
};
typedef const S00caefd0_SimdReal& S00caefd0_SimdParam;

// hkVector4
class S00caefd0_Vec {
public:
    __forceinline S00caefd0_Vec() {}
    __forceinline void operator=(const S00caefd0_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void SetAllComponents(S00caefd0_Real a) { m_vComponents = (_mm_set_ps1)(a); }
    __forceinline void set(S00caefd0_Real a, S00caefd0_Real b, S00caefd0_Real c, S00caefd0_Real d = 0.0f) { m_vComponents = (_mm_setr_ps)(a, b, c, d); }
    __forceinline void setAll3(S00caefd0_Real a) { m_vComponents = (_mm_set_ps1)(a); }
    __forceinline void setZero4() { m_vComponents = (_mm_setzero_ps)(); }
    __forceinline void add4(const S00caefd0_Vec& v) { m_vComponents = (_mm_add_ps)(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const S00caefd0_Vec& a, const S00caefd0_Vec& b) { m_vComponents = (_mm_add_ps)(a.m_vComponents, b.m_vComponents); }
    __forceinline void sub4(const S00caefd0_Vec& v) { m_vComponents = (_mm_sub_ps)(m_vComponents, v.m_vComponents); }
    __forceinline void mul4(S00caefd0_SimdParam s) { m_vComponents = (_mm_mul_ps)(s.broadcast(), m_vComponents); }
    __forceinline void addMul4(S00caefd0_SimdParam r, const S00caefd0_Vec& v) { m_vComponents = (_mm_add_ps)(m_vComponents, (_mm_mul_ps)(r.broadcast(), v.m_vComponents)); }
    __forceinline void setAddMul4(const S00caefd0_Vec& a, const S00caefd0_Vec& b, S00caefd0_SimdParam r) { m_vComponents = (_mm_add_ps)(a.m_vComponents, (_mm_mul_ps)(r.broadcast(), b.m_vComponents)); }
    __forceinline S00caefd0_SimdReal dot3(const S00caefd0_Vec& a) const {
        S00caefd0_Quad x2 = (_mm_mul_ps)(m_vComponents, a.m_vComponents);
        S00caefd0_Quad xySum = (_mm_add_ss)((_mm_shuffle_ps)(x2, x2, 0x55), x2);
        return (_mm_add_ss)((_mm_shuffle_ps)(x2, x2, 0xaa), xySum);
    }
    __forceinline S00caefd0_SimdReal lengthSquared3() const { return dot3(*this); }
    __forceinline S00caefd0_SimdReal lengthInverse3() const {
        const S00caefd0_Quad half = (_mm_set_ss)(0.5f);
        const S00caefd0_Quad three = (_mm_set_ss)(3.0f);
        const S00caefd0_Quad zero = (_mm_set_ss)(0.0f);
        const S00caefd0_Quad len2 = dot3(*this).getQuad();
        const S00caefd0_Quad len2EqualsZero = (_mm_cmpeq_ss)(len2, zero);
        const S00caefd0_Quad approx = (_mm_rsqrt_ss)(len2);
        const S00caefd0_Quad refined = (_mm_mul_ss)((_mm_mul_ss)(half, approx), (_mm_sub_ss)(three, (_mm_mul_ss)((_mm_mul_ss)(len2, approx), approx)));
        return (_mm_andnot_ps)(len2EqualsZero, refined);
    }
    __forceinline void normalize3() {
        S00caefd0_Quad lenInv = lengthInverse3().broadcast();
        m_vComponents = (_mm_mul_ps)(lenInv, m_vComponents);
    }
    S00caefd0_Quad m_vComponents;
};

// hkBool
class S00caefd0_Bool {
public:
    __forceinline S00caefd0_Bool() {}
    __forceinline S00caefd0_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    __forceinline void operator=(bool b) { m_cBooleanValue = static_cast<char>(b); }
    char m_cBooleanValue;
};

struct S00caefd0_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename TYPE>
    __forceinline void _bufFree(void* p, int numElem) {
        const int SIZE_ELEM = sizeof(TYPE);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};
__forceinline void* S00caefd0_addByteOffset(void* base, int offset) { return reinterpret_cast<char*>(base) + offset; }
class S00caefd0_Stack {
public:
    __forceinline void* allocateStack(int numBytes, const char* what) {
        void* current = m_next;
        m_next = S00caefd0_addByteOffset(current, numBytes);
        return current;
    }
    __forceinline void* allocateStackRoundSizeTo128(int numBytes, const char* what) {
        int allocationSize = (numBytes + 127) & ~127;
        return allocateStack(allocationSize, what);
    }
    __forceinline void deallocateStack(void* p) { m_next = p; }
    void* m_next;
    int unk04;
    int unk08;
    int unk0c;
};
class S00caefd0_Router {
public:
    __forceinline S00caefd0_Stack& stack() { return m_aiEntries; }
    __forceinline S00caefd0_Alloc& heap() { return *m_pStreamAllocator; }
    S00caefd0_Stack m_aiEntries;
    S00caefd0_Alloc* m_pStreamAllocator;
};
__forceinline S00caefd0_Router& S00caefd0_getRouter() { return *reinterpret_cast<S00caefd0_Router*>(FUN_00c85750()); }

template <typename T>
__forceinline T* S00caefd0_allocateStack(int n, const char* what = 0) {
    S00caefd0_Router& mem = S00caefd0_getRouter();
    return static_cast<T*>(mem.stack().allocateStack((n * sizeof(T) + 127) & ~127, what));
}
template <typename T>
__forceinline void S00caefd0_deallocateStack(T* ptr) { S00caefd0_getRouter().stack().deallocateStack(static_cast<void*>(ptr)); }

struct S00caefd0_HeapAllocator {
    __forceinline S00caefd0_Alloc& get(const void*) { return S00caefd0_getRouter().heap(); }
};
struct S00caefd0_PodTag {};
__forceinline void S00caefd0_construct(void*, int, S00caefd0_PodTag) {}
__forceinline void S00caefd0_destruct(void*, int, S00caefd0_PodTag) {}

struct S00caefd0_ArrRaw;
void __cdecl ResizeAudioStream(S00caefd0_Alloc& alloc, S00caefd0_ArrRaw* arr, int elemSize);
void __cdecl FUN_00c908c0(S00caefd0_Alloc& alloc, S00caefd0_ArrRaw* arr, int newCap, int elemSize);

template <typename T>
class S00caefd0_ArrayBase {
public:
    enum { CAPACITY_MASK = 0x3fffffff, DONT_DEALLOCATE_FLAG = 0x80000000 };
    __forceinline S00caefd0_ArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG) {}
    __forceinline void destroyBase() {}
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & CAPACITY_MASK; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline T* begin() { return m_data; }
    __forceinline void _clearAndDeallocate(S00caefd0_Alloc& alloc) {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void clear() {
        S00caefd0_destruct(m_data, m_iElementCount, S00caefd0_PodTag());
        m_iElementCount = 0;
    }
    __forceinline void setSizeUnchecked(int n) {
        S00caefd0_destruct(m_data + n, m_iElementCount - n, S00caefd0_PodTag());
        S00caefd0_construct(m_data + m_iElementCount, n - m_iElementCount, S00caefd0_PodTag());
        m_iElementCount = n;
    }
    __forceinline void GrowArrayCapacity(S00caefd0_Alloc& alloc, int n) {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, reinterpret_cast<S00caefd0_ArrRaw*>(this), newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S00caefd0_Alloc& alloc, int n) {
        GrowArrayCapacity(alloc, n);
        S00caefd0_destruct(m_data + n, m_iElementCount - n, S00caefd0_PodTag());
        S00caefd0_construct(m_data + m_iElementCount, n - m_iElementCount, S00caefd0_PodTag());
        m_iElementCount = n;
    }
    __forceinline T& _expandOne(S00caefd0_Alloc& alloc) {
        if (m_iElementCount == getCapacity()) {
            ResizeAudioStream(alloc, reinterpret_cast<S00caefd0_ArrRaw*>(this), sizeof(T));
        }
        S00caefd0_construct(m_data + m_iElementCount, 1, S00caefd0_PodTag());
        return m_data[m_iElementCount++];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T>
class S00caefd0_Array : public S00caefd0_ArrayBase<T> {
public:
    __forceinline S00caefd0_Array() {}
    __forceinline void reserve(int n) { this->GrowArrayCapacity(S00caefd0_HeapAllocator().get(this), n); }
    __forceinline void SetSizeAndGrow(int n) { this->_setSize(S00caefd0_HeapAllocator().get(this), n); }
    __forceinline T& AllocatePair() { return this->_expandOne(S00caefd0_HeapAllocator().get(this)); }
    __forceinline void ClearAndRelease() { this->_clearAndDeallocate(S00caefd0_HeapAllocator().get(this)); }
    __forceinline void destroyArray() {
        ClearAndRelease();
        this->destroyBase();
    }
};

template <typename T>
class S00caefd0_LocalArray : public S00caefd0_Array<T> {
public:
    __forceinline S00caefd0_LocalArray(int capacity) {
        this->m_data = S00caefd0_allocateStack<T>(capacity);
        this->m_iCapacityState = capacity | S00caefd0_ArrayBase<T>::DONT_DEALLOCATE_FLAG;
        m_pStackAllocation = this->m_data;
    }
    __forceinline S00caefd0_Bool wasReallocated() const { return m_pStackAllocation != this->m_data; }
    __forceinline void destruct() {
        if (!wasReallocated()) {
            this->clear();
        }
        S00caefd0_deallocateStack<T>(m_pStackAllocation);
        this->destroyArray();
    }
    T* m_pStackAllocation;
};

struct S00caefd0_ConstraintInfo {
    S00caefd0_Vec m_kTriangleNormal;
    S00caefd0_Vec m_fVelocity;
    float m_fStaticFriction;
    float m_fExtraUpStaticFriction;
    float m_fExtraDownStaticFriction;
    float m_fDynamicFriction;
    int m_priority;
};
struct S00caefd0_Interaction {
    unsigned char m_ucByte0;
    unsigned char m_ucByte1;
    float m_fValue0;
    float m_fValue1;
    int m_iResultCode;
};
struct S00caefd0_SolverInput {
    __forceinline S00caefd0_SolverInput() {
        m_vFourthInputVector.set(0, 1, 0);
        m_vThirdInputVector.setAll3(1.192092896e-07f);
        m_vContactPosition.setZero4();
    }
    S00caefd0_Vec m_vContactPosition;
    S00caefd0_Vec m_fVelocity;
    S00caefd0_Vec m_vThirdInputVector;
    S00caefd0_Vec m_vFourthInputVector;
    float m_fTimeStep;
    float m_fConstraintParameter;
    S00caefd0_ConstraintInfo* m_ppConstraints;
    int m_iConstraintCount;
};
struct S00caefd0_SolverOutput {
    S00caefd0_Vec m_vContactPosition;
    S00caefd0_Vec m_fVelocity;
    float m_fTimeStep;
    S00caefd0_Interaction* m_pPlaneStatuses;
};

void __cdecl FUN_00d24360(const S00caefd0_SolverInput& input, S00caefd0_SolverOutput& output);

class S00caefd0_PadPtr {
public:
    __forceinline void operator=(char* e) { m_kStorage = e; }
    __forceinline char* val() const { return m_kStorage; }
    char* m_kStorage;
};
class S00caefd0_Monitor {
public:
    struct CommandTimingEntry {
        const char* m_pCommandName;
        unsigned int m_uiStartTicks;
        unsigned int m_uiEndTicks;
        __forceinline void setTime() {
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_uiStartTicks = ticks;
        }
    };
    static __forceinline S00caefd0_Monitor& GetMonitorStream() { return *static_cast<S00caefd0_Monitor*>(TlsGetValue(DAT_0126835c)); }
    __forceinline char* GetStreamEnd() { return m_kRayEnd.val(); }
    __forceinline char* getCapacityMinus16() { return m_pCurrentCommand.val(); }
    __forceinline S00caefd0_Bool memoryAvailable() { return GetStreamEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_kRayEnd = ptr; }
    S00caefd0_PadPtr m_kRayStart;
    S00caefd0_PadPtr m_kRayEnd;
    S00caefd0_PadPtr m_pRayCursor;
    S00caefd0_PadPtr m_pCurrentCommand;
};
