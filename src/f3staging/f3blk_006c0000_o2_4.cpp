#include <string.h>
#include <intrin.h>
// src/f3staging/f3blk_006c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006d2250 (community match, verified in this file)
namespace f3m_006d2250 {
struct Q6d_A { void FUN_004365b0(int a); };
struct Q6d_B { void FUN_00791880(int a); void FUN_00794ba0(int a); };
struct Q6d_C { void FUN_007a9190(int a); };
extern Q6d_A* DAT_0107a0d8;
extern Q6d_B DAT_0107c0a0;
extern Q6d_C* DAT_0108c988;
void __cdecl FUN_006d1ab0();
void __cdecl FUN_006d2050();
void __cdecl FUN_0061d130(int a);
void __cdecl FUN_0048c590(int a);
void __cdecl FUN_005a1d60(int a);
void __cdecl FalloutRadio_Revert(int a);
void __cdecl FUN_00c24b70(int a);
void __cdecl FUN_006cd570(const char* fmt, ...);

// pdb: BGSSaveLoadGlobalData::RevertGlobalDataRange | BGSSaveLoadGlobalData.obj | fnv360_0822_retail, ustr, medium
// pdb params: aiStart, aiEnd, abFullRevert
bool __cdecl FUN_006d2250(unsigned int type, int data, bool flag)
{
    switch (type) {
    case 2:
        DAT_0107a0d8->FUN_004365b0(data);
        return true;
    case 3:
        if (!flag) return false;
        FUN_006d1ab0();
        return true;
    case 4:
        DAT_0107c0a0.FUN_00791880(data);
        return true;
    case 5:
        DAT_0108c988->FUN_007a9190(data);
        return true;
    case 6:
        FUN_0061d130(data);
        return true;
    case 7:
        FUN_006d2050();
        return true;
    case 0:
        FUN_0048c590(data);
        return true;
    case 1:
    case 8:
        return false;
    case 9:
        FUN_005a1d60(data);
        return true;
    case 10:
        FalloutRadio_Revert(data);
        return true;
    case 11:
        FUN_00c24b70(data);
        return true;
    case 1000:
        DAT_0107c0a0.FUN_00794ba0(data);
        return true;
    default:
        FUN_006cd570("DEFAULT: Unknown global data type %i in RevertGlobalData()", type);
        return false;
    }
}
}   // namespace f3m_006d2250
