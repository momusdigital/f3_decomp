#include <stdlib.h>
#include <string.h>
// src/f3staging/f3blk_00440000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0044dc10 (community match, verified in this file)
namespace f3m_0044dc10 {
__declspec(noinline) unsigned char __cdecl FUN_0044dba0(unsigned char* object){unsigned char result=0;if(object){switch((int)object[4]){case 0x15:case 0x17:case 0x1b:case 0x1c:result=1;}}return result;}
// pdb: BGSOpenCloseForm::GetAsOpenCloseForm | BGSOpenCloseForm.obj | fnv360_0721_retail, call_seq, low, conflict (skyrim: PlayerControls::QShoutButtonHeld)
// pdb params: apForm
unsigned char* __cdecl FUN_0044dc10(unsigned char* object){unsigned char* result=0;if(object&&FUN_0044dba0(object)){switch((int)object[4]){case 0x15:result=object+0x70;break;case 0x16:break;case 0x17:result=object+0x70;break;case 0x18:break;case 0x19:break;case 0x1a:break;case 0x1c:result=object+0x70;break;case 0x1b:result=object+0x84;break;}}return result;}
}   // namespace f3m_0044dc10
