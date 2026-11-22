#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkptoicontactpointviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkptoicontactpointviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int currentState;
// @fnv 0x00d68260
// pdb: NiD3DShaderProgramFactory::GetInstance | NiD3DShaderProgramFactory.obj | fnv360_0822_retail, call_gap, medium
int __cdecl FUN_00d68260() {
    return currentState;
}

struct Allocator {
    virtual void* release();
    virtual void* allocate(int size);
};
struct Global { int unk00; int unk04; int unk08; int unk0c; Allocator* allocator; };
struct Built { int field00; short field04; int field08; int __thiscall FUN_00d682d0(int); };
extern "C" Global* __cdecl FUN_00c85750();
// Allocates a 0x2c-byte Built via the global allocator, sets its field04 to 0x2c, calls FUN_00d682d0(arg), and returns result+8 or 0.
// @fnv 0x00d686b0
int __cdecl FUN_00d686b0(int arg)
{
    Global* global = FUN_00c85750();
    Built* pBuilt = (Built*)global->allocator->allocate(0x2c);
    pBuilt->field04 = 0x2c;
    int result = pBuilt->FUN_00d682d0(arg);
    if (result) return result + 8;
    return 0;
}

struct SpawnedChild {
    int unk00;
    int unk04;
    int m_i08;
    void Dispatch(int arg);
};

struct FUN_00d66bf0_cls {
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
    SpawnedChild* m_pChildObject;

    void DispatchToChild(int arg);
};

// @fnv 0x00d66bf0
// pdb: hkpMousePickingViewer::dragObject | hkpMousePickingViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: newWorldSpacePoint
void FUN_00d66bf0_cls::DispatchToChild(int arg)
{
    SpawnedChild* child = m_pChildObject;
    if (child != 0 && child->m_i08 != 0) {
        child->Dispatch(arg);
    }
}

struct Target {
    void FUN_00c91a20(void* apArg);
};

struct FUN_00d682a0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    void InvokeTargetWithSelfOffset(Target* apTarget);
};

// Calls apTarget->FUN_00c91a20 with a pointer to this+8, or null if this-0x20 is null.
// @fnv 0x00d682a0
// pdb: hkpConstraintViewer::worldRemovedCallback | hkpConstraintViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void FUN_00d682a0_cls::InvokeTargetWithSelfOffset(Target* apTarget)
{
    apTarget->FUN_00c91a20(((char*)this - 0x20) != 0 ? (char*)this + 8 : 0);
}

extern char DAT_0104dd7c[];
extern char DAT_010d1f0c[];
extern char DAT_010d1eec[];
extern char DAT_010d1edc[];
extern char DAT_010d1ebc[];

void __stdcall FUN_00ddccb0(int a1);

struct FUN_00d682d0_cls {
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
    void* m_vtbl28;

    void* FUN_00d682d0(int a1);
};

// Calls FUN_00ddccb0 with a1, then stores five DAT_ pointers into this at offsets 0x28, 0x00, 0x08, 0x20 and 0x28, and returns this.
// @fnv 0x00d682d0
// pdb: hkpToiContactPointViewer::hkpToiContactPointViewer | hkpToiContactPointViewer.obj | fnv360_0822_retail, objrun, high
// pdb params: contexts
void* FUN_00d682d0_cls::FUN_00d682d0(int aiArg)
{
    FUN_00ddccb0(aiArg);
    *(void* volatile*)((char*)this + 0x28) = (void*)&DAT_0104dd7c;
    *(void* volatile*)((char*)this + 0x00) = (void*)&DAT_010d1f0c;
    *(void* volatile*)((char*)this + 0x08) = (void*)&DAT_010d1eec;
    *(void* volatile*)((char*)this + 0x20) = (void*)&DAT_010d1edc;
    *(void* volatile*)((char*)this + 0x28) = (void*)&DAT_010d1ebc;
    return this;
}

struct ItemList {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68;
    void** items;   // +0x6c
    int count;      // +0x70
};

struct Sub {
    virtual void v0();
    virtual void v1(void* item);
};

class FUN_00d68310_cls {
public:
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14;
    Sub m_sub;          // +0x18
    ItemList* m_kNode;   // +0x1c
    void FUN_00d68310();
};

// Iterates the item list and calls m_sub.v1 on each item until the list ends or the count is reached.
// @fnv 0x00d68310
// pdb: hkpContactPointViewer::init | hkpContactPointViewer.obj | fnv360_0822_retail, vtable, medium
void FUN_00d68310_cls::FUN_00d68310() {
    int i = 0;
    while (m_kNode != 0) {
        if (i >= m_kNode->count) break;
        m_sub.v1(m_kNode->items[i]);
        i++;
    }
}

struct Part0_t
{
    virtual ~Part0_t() {}
    int m_i04;
};

struct Part1_t
{
    virtual ~Part1_t() {}
};

struct Part2_t
{
    virtual ~Part2_t() {}
};

struct Part3_t
{
    virtual ~Part3_t() {}
};

struct SubObj_t
{
    virtual ~SubObj_t() {}
    void Add(int aiItem);
};

struct ListBlob_t
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
    int* m_items;
    int m_uiItemCount;
};

struct ParentBase_t
{
    void Init();
};

class FUN_00d68350_cls : public Part0_t, public Part1_t
{
public:
    int m_u0c;
    int m_u10;
    int m_u14;
    int m_u18;
    int m_u1c;
    SubObj_t m_sub;
    ListBlob_t* m_pEntries;
    Part2_t m_pTail;

    void FUN_00d68350();
};

// @fnv 0x00d68350
// pdb: hkpToiContactPointViewer::~hkpToiContactPointViewer | hkpToiContactPointViewer.obj | fnv360_0822_retail, call_seq, medium
void FUN_00d68350_cls::FUN_00d68350()
{
    int i = 0;
    this->Part0_t::~Part0_t();
    this->Part1_t::~Part1_t();
    m_sub.SubObj_t::~SubObj_t();
    m_pTail.Part2_t::~Part2_t();
    while (m_pEntries != 0)
    {
        ListBlob_t* p = m_pEntries;
        if (i >= p->m_uiItemCount)
        {
            break;
        }
        m_sub.Add(p->m_items[i]);
        i++;
    }
    ((Part3_t*)&m_pTail)->Part3_t::~Part3_t();
    ((ParentBase_t*)this)->Init();
}

struct StateTarget {
    int __thiscall Dispatch(const char* name, int (__cdecl* handler)(int));
};

extern StateTarget* g_stateTarget;
extern int g_stateResult;
extern const char str_010d1ea0[];

// @fnv 0x00d686f0
// pdb: hkpConvexRadiusViewer::registerViewer | hkpConvexRadiusViewer.obj | fnv360_0822_retail, ustr, medium
void DispatchStateHandler()
{
    g_stateResult = g_stateTarget->Dispatch(str_010d1ea0, FUN_00d686b0);
}

struct FUN_00d68270_Base0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct FUN_00d68270_Base1 {
    int unk00;
    int unk04;
    void FUN_00d68270(struct FUN_00d68270_Arg* arg);
};
struct FUN_00d68270_Base2 {
    int unk00;
};
struct FUN_00d68270_Derived : public FUN_00d68270_Base0, public FUN_00d68270_Base1, public FUN_00d68270_Base2 {
};
struct FUN_00d68270_Arg {
    void FUN_00c93a20(FUN_00d68270_Base2* obj);
};
// Calls arg->FUN_00c93a20 with the address 8 bytes past this, treated as the Base2 part of the enclosing Derived object.
// @fnv 0x00d68270
// pdb: hkpConstraintViewer::worldAddedCallback | hkpConstraintViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void FUN_00d68270_Base1::FUN_00d68270(FUN_00d68270_Arg* arg)
{
    arg->FUN_00c93a20(reinterpret_cast<FUN_00d68270_Derived*>(reinterpret_cast<char*>(this) - sizeof(FUN_00d68270_Base0)));
}

// sub ecx,0x20; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x20).
struct PrimaryBase
{
    virtual void FUN_00d68710();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct SecondaryBase
{
    virtual void FUN_00d68710();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68710
    virtual void FUN_00d68710();
};

Derived::Derived()
{
}

namespace fnv_00d68730 {
// sub ecx,0x28; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x28).
struct PrimaryBase
{
    virtual void FUN_00d68730();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};

struct SecondaryBase
{
    virtual void FUN_00d68730();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68730
    virtual void FUN_00d68730();
};

Derived::Derived()
{
}
}  // namespace fnv_00d68730

namespace fnv_00d68740 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct FUN_00d68740 {
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00d68740();
    virtual ~FUN_00d68740();
    static void operator delete(void* apMemory)
    {
        AudioHolder* pHolder = FUN_00c85750();
        unsigned int uiSize = ((FUN_00d68740*)apMemory)->m_u04;
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, uiSize);
    }
};

// Constructor that zero-initializes m_u04 and m_u06.
// @fnv 0x00d68740
FUN_00d68740::FUN_00d68740()
{
    m_u04 = 0;
    m_u06 = 0;
}
}  // namespace fnv_00d68740

#include <math.h>

typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    struct { float lane0, lane1, lane2, lane3; };
} __m128;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern const float DAT_010c69c0=(0.85f-1.0f);

struct Vec {
    union {
        __m128 m;
        struct { float x, y, z, w; };
    };
};

class S00d68670_hkBool {
public:
    S00d68670_hkBool(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};

struct S00d68670_ContactPoint {
    Vec m_vContactPosition;
    Vec m_vSeparatingNormal;
    const Vec& getPosition() { return m_vContactPosition; }
    const Vec& getNormal() const { return m_vSeparatingNormal; }
};

struct S00d68670_Collidable {
    int unk00;
};

struct S00d68670_Entity {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d68670_Collidable m_kCollidable;
    const S00d68670_Collidable* getCollidable() const { return &m_kCollidable; }
};

struct S00d68670_ContactPointEvent {
    void* m_pObservedSource;
    S00d68670_Entity* m_apEntities[2];
    void* m_pContactManager;
    int m_type;
    S00d68670_ContactPoint* m_vContactPoint;
    S00d68670_hkBool isToi() const { return m_type <= 0; }
};
