#include <stdlib.h>
#include <string.h>
// src/f3staging/f3blk_00440000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004566c0 (community match, verified in this file)
namespace f3m_004566c0 {
// pdb: TESHealthForm::GetFormAsHealthForm | TESHealthForm.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apForm
void* FUN_004566c0(void* obj)
{
    void* result = 0;
    if (obj)
    {
        switch (*(unsigned char*)((char*)obj + 4))
        {
        case 0x28:
            result = (char*)obj + 0x94;
            break;
        case 0x18:
            result = (char*)obj + 0x68;
            break;
        case 0x2a:
        case 0x2b:
            result = (char*)obj + 0xb0;
            break;
        }
    }
    return result;
}
}   // namespace f3m_004566c0
