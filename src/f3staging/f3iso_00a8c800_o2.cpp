#include <new>
// src/f3staging/f3iso_00a8c800_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a8c800 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a8c800 (community match, verified in this file)
namespace f3m_00a8c800 {
namespace Sa8c800_ {

struct Entry
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48;
    const char* name;
};

struct Owner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    Entry** entries;
    int count;
};

int __cdecl FUN_00cb0fa0(const char*, const char*);

// pdb: hkFindNextChildByName | hkMonitorStreamAnalyzer.obj | fnv360_0822_retail, call_gap_sim, low
static __declspec(noinline) Entry* __cdecl FUN_00a8c800(Owner* ownerHandle, Entry* keyHandle, const char* name)
{
    Owner* owner = ownerHandle;
    Entry* key = keyHandle;
    int index = 0;
    while (index < owner->count)
    {
        if (owner->entries[index] == key)
            break;
        ++index;
    }

    ++index;
    if (index >= owner->count)
        return 0;

    do
    {
        Entry** slot = &owner->entries[index];
        if (!FUN_00cb0fa0(name, (*slot)->name))
            return owner->entries[index];
        ++index;
    } while (index < owner->count);

    return 0;
}

Entry* __cdecl EmitTarget(Owner* owner, Entry* key, const char* name)
{
    return FUN_00a8c800(owner, key, name);
}

}
}   // namespace f3m_00a8c800
