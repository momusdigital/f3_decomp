// src/f3staging/f3blk_00c00000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00c163f0 (community match, verified in this file)
extern "C" char __ImageBase;
namespace f3m_00c163f0 {
extern "C" unsigned long __cdecl _exception_code(void);
namespace f3m_00c163f0 {
struct IMAGE_SECTION_HEADER_ {
    unsigned char Name[8];
    unsigned long VirtualSize;
    unsigned long VirtualAddress;
    unsigned long SizeOfRawData;
    unsigned long PointerToRawData;
    unsigned long PointerToRelocations;
    unsigned long PointerToLinenumbers;
    unsigned short NumberOfRelocations;
    unsigned short NumberOfLinenumbers;
    unsigned long Characteristics;
};
extern "C" int __cdecl FUN_00c16370(unsigned char* pImageBase);
extern "C" IMAGE_SECTION_HEADER_* __cdecl FUN_00c163a0(unsigned char* pImageBase, unsigned long rva);
// pdb: _IsNonwritableInCurrentImage | pesect.obj | tesv_win, call_gap, low
extern "C" int __cdecl FUN_00c163f0(unsigned char* pTarget)
{
    unsigned char* pImageBase;
    unsigned long rvaTarget;
    IMAGE_SECTION_HEADER_* pSection;

    pImageBase = (unsigned char*)&__ImageBase;

    __try {
        if (!FUN_00c16370(pImageBase))
            return 0;
        rvaTarget = pTarget - pImageBase;
        pSection = FUN_00c163a0(pImageBase, rvaTarget);
        if (pSection == 0)
            return 0;
        return (pSection->Characteristics & 0x80000000) == 0;
    }
    __except (_exception_code() == 0xc0000005) {
        return 0;
    }
}
}
}   // namespace f3m_00c163f0
