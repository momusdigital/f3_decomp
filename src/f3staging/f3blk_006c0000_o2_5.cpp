#include <string.h>
#include <intrin.h>
// src/f3staging/f3blk_006c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006d1320 (community match, verified in this file)
namespace f3m_006d1320 {
struct Buffer446 {
    unsigned int unk00, unk04, unk08, unk0C;
    void FUN_006e05d0();
    void FUN_006e05f0();
    Buffer446() { FUN_006e05d0(); }
    ~Buffer446() { FUN_006e05f0(); }
};

extern "C" void __cdecl FUN_006cd570(const char* fmt, ...);
void __cdecl FUN_0061a520(Buffer446* buffer);
void __cdecl FUN_006c3130(Buffer446* buffer);
struct Sub436500 {
    void FUN_00436500(Buffer446* buffer);
};
extern Sub436500* DAT_0107a0d8;
struct Sub7a7ba0 {
    void FUN_007a7ba0(Buffer446* buffer);
};
extern Sub7a7ba0* DAT_0108c988;

// pdb: BGSSaveLoadGlobalData::FinishLoadGlobalDataRange | BGSSaveLoadGlobalData.obj | fnv360_0822_retail, ustr, medium
// pdb params: aiStart, aiEnd
bool __cdecl FUN_006d1320(unsigned int type, Buffer446* buffer)
{
    switch (type) {
    case 0:
        return false;
    case 1:
        return false;
    case 2:
        DAT_0107a0d8->FUN_00436500(buffer);
        return true;
    case 3:
        return false;
    case 4:
        return false;
    case 5:
        DAT_0108c988->FUN_007a7ba0(buffer);
        return true;
    case 6:
        FUN_0061a520(buffer);
        return true;
    case 7:
        return false;
    case 8:
        return false;
    case 9:
        return false;
    case 10:
        FUN_006c3130(buffer);
        return true;
    case 11:
        return false;
    case 1000:
        return false;
    default:
        FUN_006cd570("DEFAULT: Unknown global data type %i in FinishLoadGlobalData()", type);
        return false;
    }
}
}   // namespace f3m_006d1320
