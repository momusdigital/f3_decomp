#include "f3_common.h"
// src/havok/common/serialize/util/hkrootlevelcontainer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkrootlevelcontainer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkRootLevelContainer.h"

struct FUN_00d46d40_s
{
    const char* FUN_00d46d40();
};

int __cdecl FUN_00cb0fa0(int a, int b);

struct hkClassObj : FUN_00d46d40_s
{
};

struct FUN_00d477a0_s
{
    void* m_object;

    hkClassObj* FUN_00d477a0();
};

struct EntryD480
{
    int unk00;
    unsigned int m_pcText;
    FUN_00d477a0_s m_pReferencedResource;

    const void* GetUnderlyingObject() const
    {
        return m_pReferencedResource.m_object;
    }
    const char* getName()
    {
        return m_pReferencedResource.FUN_00d477a0() ? m_pReferencedResource.FUN_00d477a0()->FUN_00d46d40()
                                                    : (const char*)(m_pcText & ~1u);
    }
};

struct Ent_d48150
{
    unsigned int unk00;
    int unk04;
    int unk08;
};

int __cdecl FUN_00cb0fa0(void* a, unsigned int b);

struct Cls_d48150
{
    Ent_d48150* m_data;
    int m_iElementCount;
    int idx(int key)
    {
        int i = 0;
        Ent_d48150* e;
        while (key != 0 && i < m_iElementCount && (e = &m_data[i], i++, e->unk08 != key))
        {
        }
        return i;
    }
    int FUN_00d48150(void* ctx, int key);
};

// @f3 0x009d71d0 (community match, verified in this file)
struct D481D0Class
{
    const char* getName() const;
};

struct SlotNameEntry
{
    unsigned int unk00;
    const char* unk04;
    int unk08;
    D481D0Class* unk0c;

    const char* getName() const
    {
        return unk0c ? unk0c->getName() : unk04;
    }
};
int __cdecl MatchSlotKey(void* ctx, const char* name);

// pdb: hkRootLevelContainer::findObjectByType | hkRootLevelContainer.obj | fnv360_0822_retail, call_dedup, low
// pdb params: typeName, prevObject
int Cls_d48150::FUN_00d48150(void* ctx, int key)
{
    int i = 0;
    SlotNameEntry* e;
    while (key != 0 && i < m_iElementCount && (e = &((SlotNameEntry*)m_data)[i], i++, e->unk08 != key))
    {
    }
    int iIndex = i;
    for (; iIndex < m_iElementCount; iIndex++)
    {
        if (MatchSlotKey(ctx, ((SlotNameEntry*)m_data)[iIndex].getName()) == 0)
            return ((SlotNameEntry*)m_data)[iIndex].unk08;
    }
    return 0;
}

