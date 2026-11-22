#include "f3_common.h"
// src/havok/physics/collide/agent3/list3/hkplistagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/list3/hkplistagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl hkAgent1nMachine_WarpTime(int a1, float a2, float a3, int a4);

// Calls hkAgent1nMachine_WarpTime with unk08, unk0C, unk10 and unk14, dropping unk04.
// @fnv 0x00da6e30
// pdb: hkpCollectionCollectionAgent3::warpTime | hkpCollectionCollectionAgent3.obj | tesv_win, objrun, medium
void __cdecl FUN_00da6e30(int aiUnused, int aiArg1, float afArg2, float afArg3, int aiArg4)
{
    hkAgent1nMachine_WarpTime(aiArg1, afArg2, afArg3, aiArg4);
}
