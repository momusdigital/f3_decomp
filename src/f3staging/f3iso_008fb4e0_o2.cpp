#include <new>
// src/f3staging/f3iso_008fb4e0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x008fb4e0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008fb4e0 (community match, verified in this file)
namespace f3m_008fb4e0 {
namespace S8fb4e0_ {
struct ResourceInfo;
ResourceInfo* __cdecl FUN_008f1d20(int resourceId);
void* __cdecl FUN_0089eb90(unsigned int size);
void __cdecl FUN_0089ec10(void* memory, unsigned int size);

struct FUN_008fb470
{
    void* vtable;
    int unk04;
    int unk08;
    unsigned short flags0c;
    unsigned short unk0e;
    void* target10;
    int unk14;
    float value18;
    float value1c;
    int mode20;
    int unk24;
    int unk28;

    FUN_008fb470(int first, int second, int resourceId,
                 ResourceInfo* info, int finalArgument);
    static __forceinline void* operator new(unsigned int size)
    {
        return FUN_0089eb90(size);
    }
    static __forceinline void operator delete(void* memory)
    {
        FUN_0089ec10(memory, sizeof(FUN_008fb470));
    }
};
typedef char VerifyResourceObject44[(sizeof(FUN_008fb470) == 44) ? 1 : -1];
}

// pdb: WeaponObject::CreateWeaponObject | WeaponObject.obj | fnv360_0822_retail, call_gap, low
// pdb params: aOwnerFilter, apOwner3d, apObject, abDefaultKeyframed
void* __cdecl FUN_008fb4e0(int first, int second, int resourceId, int finalArgument)
{
    S8fb4e0_::FUN_008fb470* result = 0;
    if (resourceId != 0)
    {
        S8fb4e0_::ResourceInfo* info = S8fb4e0_::FUN_008f1d20(resourceId);
        if (info != 0)
            result = new S8fb4e0_::FUN_008fb470(first, second, resourceId,
                                                info, finalArgument);
    }
    return result;
}
}   // namespace f3m_008fb4e0
