#include <new>
// src/f3staging/f3iso_0076dbf0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x0076dbf0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0076dbf0 (community match, verified in this file)
namespace f3m_0076dbf0 {
int __cdecl ImageSpaceModifierInstance_Stop(int handle);

// pdb: PlayerCharacter::StopIronSightsImageSpace | PlayerCharacter.obj | fnv360_0822_retail, call_gap_sim, low
void __fastcall FUN_0076dbf0(void* pThis)
{
    int file = *(int*)((char*)pThis + 0x578);
    if (file)
    {
        ImageSpaceModifierInstance_Stop(file);
        *(int*)((char*)pThis + 0x578) = 0;
    }
}
}   // namespace f3m_0076dbf0
