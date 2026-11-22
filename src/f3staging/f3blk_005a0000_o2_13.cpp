#include <string.h>
#include <string.h>
#include <string.h>
// src/f3staging/f3blk_005a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005a9b40 (community match, verified in this file)
namespace f3m_005a9b40 {
struct Heap5a9b40 { void* FUN_0086b930(unsigned int bytes); void FUN_0086ba60(void* p); };
namespace n5a9b40 { extern Heap5a9b40 DAT_01090a78; }
struct Base5a9b40 {
    void TESPackage_SetPackType(int type);
    static void* operator new(unsigned int n) { return n5a9b40::DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p) { n5a9b40::DAT_01090a78.FUN_0086ba60(p); }
};
struct FUN_007eae60 : Base5a9b40 { char pad[0xd0]; FUN_007eae60(); };
struct FUN_0079a3f0 : Base5a9b40 { char pad[0x188]; FUN_0079a3f0(int a, int b, int c); };
struct FUN_007ea8e0 : Base5a9b40 { char pad[0x88]; FUN_007ea8e0(); };
struct FUN_007ed3c0 : Base5a9b40 { char pad[0xac]; FUN_007ed3c0(int a, int b, int c); };
struct FUN_007f31b0 : Base5a9b40 { char pad[0x9c]; FUN_007f31b0(); };
struct FUN_007f2a20 : Base5a9b40 { char pad[0xb4]; FUN_007f2a20(); };
struct FUN_005a8440 : Base5a9b40 { char pad[0x80]; FUN_005a8440(); };
// pdb: TESPackage::CreatePackage | Package.obj | fnv360_0822_retail, call_gap, medium
// pdb params: aPackageType
Base5a9b40* __cdecl FUN_005a9b40(int type)
{
    Base5a9b40* p = 0;
    switch (type) {
    case -1: case 9: case 17: case 39:
        break;
    case 15: case 28:
        p = new FUN_007eae60;
        break;
    case 18:
        p = new FUN_0079a3f0(0, 0, 0);
        break;
    case 21:
        p = new FUN_007ea8e0;
        break;
    case 22:
        p = new FUN_007ed3c0(0, 0, 0);
        break;
    case 23:
        p = new FUN_007f31b0;
        break;
    case 24:
        p = new FUN_007f2a20;
        break;
    default:
        p = new FUN_005a8440;
        break;
    }
    if (p) p->TESPackage_SetPackType(type);
    return p;
}
}   // namespace f3m_005a9b40
