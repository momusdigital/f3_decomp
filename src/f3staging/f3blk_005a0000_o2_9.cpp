#include <string.h>
#include <string.h>
#include <string.h>
// src/f3staging/f3blk_005a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005a23d0 (community match, verified in this file)
namespace f3m_005a23d0 {
// pdb: TESObjectWEAP::GetAttackSound | TESObjectWEAP.obj | fnv360_0822_retail, call_gap_sim, low, conflict (bridge: ActorValue::IsResistance)
// pdb params: bModSound
bool FUN_005a23d0(unsigned value){bool result=false;switch(value){case 18:case 19:case 20:case 52:case 58:case 59:case 60:case 61:result=true;break;}return result;}
}   // namespace f3m_005a23d0
