#include "f3_common.h"
// src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkphavoksnapshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CallbackInterface
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void notify(void*, unsigned short);
};
struct State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    CallbackInterface* interface10;
};
State* __cdecl FUN_00c85750();

struct D481D0StringPtr
{
    const char* m_pcText;

    D481D0StringPtr();
    void operator=(const char* s);
};

struct D481D0Class
{
    const char* getName() const;
};

struct D481D0ReferencedObject;

struct D481D0RefVariant
{
    D481D0ReferencedObject* m_ptr;

    D481D0RefVariant() : m_ptr(0)
    {}
    void set(D481D0ReferencedObject* obj, const D481D0Class* pClassInfo);
    const D481D0Class* GetVariantValue() const;
};

struct CC0D30Result
{
    CC0D30Result();

    int m_iResultCode;
    int m_data;
};

struct CC0D30Registry
{
    int unk00;
};

extern CC0D30Registry g_CC0D30DefaultRegistry;

CC0D30Result __cdecl FUN_00cc0bc0(const void* data, const CC0D30Registry& registry, const void* pClassInfo, void* out,
                                  int flags);

// @fnv 0x00cc0d30
// pdb: hkpHavokSnapshot::save | hkpHavokSnapshot.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: data, writer, binaryFormat, targetLayout
CC0D30Result __cdecl FUN_00cc0d30(const void* data, const void* pClassInfo, void* out, int flags)
{
    return FUN_00cc0bc0(data, g_CC0D30DefaultRegistry, pClassInfo, out, flags);
}

struct S_00cc0d60_R
{
    char v;
    S_00cc0d60_R()
    {}
};
struct S_00cc0d60_A
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    void FUN_00d4c220();
    void hkpPhysicsData_populateFromWorld(void* a, int b);
    void FUN_00d4c250();
};
S_00cc0d60_R* FUN_00cc0d30(void** pa, S_00cc0d60_A* a, void* b, int c, int d);
// @fnv 0x00cc0d60
// pdb: hkpHavokSnapshot::save | hkpHavokSnapshot.obj | fnv360_0822_retail, call_gap, medium
// pdb params: world, writer, binaryFormat, targetLayout, saveContactPoints
S_00cc0d60_R FUN_00cc0d60(void* a2, void* a3, int a4, int a5, int a6)
{
    S_00cc0d60_R res;
    void* c;
    c = a2;
    if (c && a3)
    {
        S_00cc0d60_A obj;
        obj.FUN_00d4c220();
        obj.hkpPhysicsData_populateFromWorld(c, a6);
        char r = FUN_00cc0d30(&a2, &obj, a3, a4, a5)->v;
        obj.FUN_00d4c250();
        res.v = r;
    }
    else
    {
        res.v = 0;
    }
    return res;
}

struct hkBool
{
    char m_kPointB;
    hkBool()
    {}
    hkBool(bool b) : m_kPointB(b)
    {}
    operator bool() const
    {
        return m_kPointB != 0;
    }
};

struct PtrList;

struct PtrList
{
    void** m_00;
    unsigned int m_04;
    unsigned int m_08;

    void** Add(void* o)
    {
        unsigned int i = m_04;
        void** slot = &m_00[i];
        *slot = o;
        if (slot == 0)
        {
            return 0;
        }
        m_04++;
        return slot;
    }
};

struct FUN_00cc08f0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    PtrList m_08;

    void hkpHavokSnapshot_ConvertListener_addObjectCallback(void** a1, void** a2);
};

// Checks type matchers on *a2, allocates and links a new object into m_08, or clears the pointer when the back-reference matches.
// @f3 0x00943e70 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;

struct QHeap39
{
    void* FUN_008f6d30(unsigned int size, unsigned int tag);
};
struct QMatcher39
{
    hkBool hkClass_isSuperClass(void* v);
};
extern QMatcher39 DAT_011696e4;
extern QMatcher39 DAT_011695f4;
extern QMatcher39 DAT_01169464;
extern QMatcher39 DAT_011693f4;
extern int DAT_01169674;
extern int DAT_01169524;
extern int DAT_01169434;
void __cdecl FUN_00901f10(PtrList* l, unsigned int n);

struct QObjA39
{
    unsigned int unk00;
    unsigned short m_04;
    QObjA39* FUN_009d69b0(void* v);
};
struct QObjB39
{
    unsigned int unk00;
    unsigned short m_04;
    QObjB39* FUN_009d5cb0(void* v);
};
struct QObjC39
{
    unsigned int unk00;
    unsigned short m_04;
    QObjC39* FUN_009d49a0(void* v);
};
struct QLink39
{
    int unk00;
    int unk04;
    QLink39* m_08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    QLink39* m_24;
};

static inline void* QAlloc39(unsigned int size)
{
    QHeap39* h = (QHeap39*)TlsGetValue(DAT_010f3170);
    return h->FUN_008f6d30(size, 0x27);
}

// pdb: hkpHavokSnapshot::ConvertListener::addObjectCallback | hkpHavokSnapshot.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void FUN_00cc08f0_cls::hkpHavokSnapshot_ConvertListener_addObjectCallback(void** a1, void** a2)
{
    if (DAT_011696e4.hkClass_isSuperClass(*a2) && *a2 != (void*)&DAT_01169674)
    {
        void* v = *a1;
        QObjA39* o = (QObjA39*)QAlloc39(0x70);
        o->m_04 = 0x70;
        o = o->FUN_009d69b0(v);
        PtrList* list = &m_08;
        if (list->m_04 == (list->m_08 & 0x3fffffff))
            FUN_00901f10(list, 4);
        list->m_00[list->m_04] = o;
        list->m_04++;
        *a1 = o;
        *a2 = (void*)&DAT_01169674;
    }
    if (DAT_011695f4.hkClass_isSuperClass(*a2) && *a2 != (void*)&DAT_01169524)
    {
        void* v = *a1;
        QObjB39* o = (QObjB39*)QAlloc39(0xe0);
        o->m_04 = 0xe0;
        o = o->FUN_009d5cb0(v);
        PtrList* list = &m_08;
        if (list->m_04 == (list->m_08 & 0x3fffffff))
            FUN_00901f10(list, 4);
        list->m_00[list->m_04] = o;
        list->m_04++;
        *a1 = o;
        *a2 = (void*)&DAT_01169524;
        return;
    }
    if (DAT_01169464.hkClass_isSuperClass(*a2) && *a2 != (void*)&DAT_01169434)
    {
        void* v = *a1;
        QObjC39* o = (QObjC39*)QAlloc39(0x70);
        o->m_04 = 0x70;
        o = o->FUN_009d49a0(v);
        PtrList* list = &m_08;
        if (list->m_04 == (list->m_08 & 0x3fffffff))
            FUN_00901f10(list, 4);
        list->m_00[list->m_04] = o;
        list->m_04++;
        *a1 = o;
        *a2 = (void*)&DAT_01169434;
        return;
    }
    if (DAT_011693f4.hkClass_isSuperClass(*a2))
    {
        QLink39* v = (QLink39*)*a1;
        QLink39* back = v->m_08;
        if (back != 0 && back->m_24 == v)
        {
            *a1 = 0;
            *a2 = 0;
        }
    }
}


namespace fnv_00cc0ae0 {

struct FixedAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FixedAllocator* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00cc0ae0

namespace fnv_00cc0b50 {
struct SlotRec
{
    unsigned short m_u0;
    unsigned short m_flag;
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
};

struct SpawnedObject
{
    virtual void* v00();
    SlotRec m_slot;
    void FUN_00cc0ae0();
    SpawnedObject()
    {
        m_slot.m_flag = 1;
        m_slot.m_kPointA = 0;
        m_slot.m_kPointB = 0;
        m_slot.m_iThirdValue = 0x80000000;
    }
};

int FUN_00d485a0(unsigned int a, unsigned int b, unsigned int c, int d, SpawnedObject* e);

struct InputBool223
{
    unsigned char value;
    inline operator bool() const
    {
        return value != 0;
    }
};
// Calls FUN_00d485a0 with a2, a3, a4, (bool)a5 and ctx (or a local object if null), stores whether it returned 0 into *out, and returns out.
// @fnv 0x00cc0b50
unsigned char* FUN_00cc0b50(unsigned char* apResult, unsigned int a2, unsigned int a3, unsigned int a4,
                            InputBool223 abFlag, unsigned int unk2c, SpawnedObject* ctx)
{
    SpawnedObject* pCtx = ctx;
    SpawnedObject localCtx;
    if (pCtx == 0)
    {
        pCtx = &localCtx;
    }
    int r = FUN_00d485a0(a2, a3, a4, (bool)abFlag, pCtx);
    *apResult = (unsigned char)(r == 0);
    localCtx.FUN_00cc0ae0();
    return apResult;
}
}  // namespace fnv_00cc0b50
