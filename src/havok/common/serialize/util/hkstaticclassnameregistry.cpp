#include "f3_common.h"
// src/havok/common/serialize/util/hkstaticclassnameregistry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkstaticclassnameregistry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct SlotEntry
{
    int unk00;
    SlotEntry* Key();
};

int __cdecl MatchSlotKey(void* p, SlotEntry* key);

struct FUN_00db7ae0_cls
{
    int unk00;
    int unk04;
    int unk08;
    SlotEntry** m_slots;

    void ResetSlots();
    SlotEntry* hkStaticClassNameRegistry_getClassByName(void* p);
};

// Resets the slot table, then scans m_slots for the first entry whose Key matches p via MatchSlotKey and returns it, or 0 if none match.
// @fnv 0x00db7ae0
// pdb: hkStaticClassNameRegistry::getClassByName | hkStaticClassNameRegistry.obj | fnv360_0822_retail, vtable, high
// pdb params: className
// pdb: hkStaticClassNameRegistry::getClassByName | hkStaticClassNameRegistry.obj | fnv360_0822_retail, vtable, high (was: FindSlotByKey)
SlotEntry* FUN_00db7ae0_cls::hkStaticClassNameRegistry_getClassByName(void* apKey)
{
    ResetSlots();
    int i = 0;
    if (m_slots[i] != 0)
    {
        do
        {
            SlotEntry* key = m_slots[i]->Key();
            if (MatchSlotKey(apKey, key) == 0)
            {
                return m_slots[i];
            }
            i++;
        } while (m_slots[i] != 0);
    }
    return 0;
}

struct FnvCpu_FUN_00db7a70_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int hkStaticClassNameRegistry_getName();
};
// @fnv 0x00db7a70
// pdb: hkStaticClassNameRegistry::getName | hkStaticClassNameRegistry.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int FnvCpu_FUN_00db7a70_CpuObject::hkStaticClassNameRegistry_getName()
{
    return value;
}
