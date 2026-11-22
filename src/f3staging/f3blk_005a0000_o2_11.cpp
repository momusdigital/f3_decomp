#include <string.h>
#include <string.h>
#include <string.h>
// src/f3staging/f3blk_005a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005a1900 (community match, verified in this file)
namespace f3m_005a1900 {
// pdb: ActionPoints::GetAttackAction | ActionPoints.obj | fnv360_0721_retail, caller, medium
// pdb params: aeWeaponType
unsigned __cdecl FUN_005a1900(unsigned type){unsigned result=16;if(type<=12){switch(type){case 0:result=0;break;case 1:result=1;break;case 2:result=2;break;case 3:case 4:result=3;break;case 5:case 6:case 7:result=4;break;case 8:result=5;break;case 9:result=6;break;case 10:result=7;break;case 11:result=8;break;}}return result;}
}   // namespace f3m_005a1900
