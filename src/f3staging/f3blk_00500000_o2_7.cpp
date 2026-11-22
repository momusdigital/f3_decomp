// src/f3staging/f3blk_00500000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00509780 (community match, verified in this file)
namespace f3m_00509780 {
// pdb: BSEndian | EffectSetting.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: apData, __formal
unsigned __cdecl FUN_00509780(unsigned type) {unsigned result=4;switch(type) {
case 0:case 10:case 19:result=0;break;
case 2:case 18:result=1;break;
case 4:result=2;break;
case 3:case 24:result=3;break;
case 16:case 17:case 22:case 23:case 25:case 28:case 29:result=9;break;
case 9:case 12:case 30:case 31:result=5;break;
case 6:case 7:result=6;break;
case 8:result=8;break;
case 1:result=7;break;
case 5:case 11:case 13:case 14:case 15:case 20:case 21:case 26:case 27:result=4;break;
default:break;
}return result;}


}   // namespace f3m_00509780
