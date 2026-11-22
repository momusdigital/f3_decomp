#include <windows.h>
#include <string.h>
#include <string.h>
// src/f3staging/f3blk_005a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005a2430 (community match, verified in this file)
namespace f3m_005a2430 {
// pdb: ActorValue::ToActorValue | ActorValue.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
int ActorValue_ToActorValue(int code, char ch)
{
    switch (code) {
    case 0:
        return ch + 5;
    case 1:
        return ch + 12;
    case 2:
        return ch + 32;
    case 3:
        return ch;
    case 4:
        return ch + 25;
    case 5:
        return ch + 46;
    }
    return 0;
}
}   // namespace f3m_005a2430

