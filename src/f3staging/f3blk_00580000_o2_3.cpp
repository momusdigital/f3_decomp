#include <stdexcept>
#include <new>
#include <new>
#include <new>
#include <new>
#include <new>
#include <string>
#include <vector>
#include <string.h>
#include <new>
#include <intrin.h>
#include <string.h>
// src/f3staging/f3blk_00580000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00581620 (community match, verified in this file)
extern float DAT_00f5f038, DAT_00f5f044, DAT_00f5f050, DAT_00f5f05c, DAT_00f5f068;
namespace f3m_00581620 {
struct Selector162 { int FUN_005a29a0(int); };
// pdb: AiFormulas::AVDeriveHealingRate | AiFormulas.obj | fnv360_0822_retail, objrun, medium
// pdb params: apActor, aiWhich
float FUN_00581620(Selector162* p) {
float result=0.0f;
switch(p->FUN_005a29a0(7)) { case 6: result=DAT_00f5f038; break; case 7: result=DAT_00f5f044; break; case 8: result=DAT_00f5f050; break; case 9: result=DAT_00f5f05c; break; case 10: result=DAT_00f5f068; break; }
return result;
}
}   // namespace f3m_00581620
