#include <new>
// src/f3staging/f3blk_00720000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00723d70 (community match, verified in this file)
namespace f3m_00723d70 {

namespace object_factory_1592 {
struct AllocationHeap { void* FUN_0086b930(unsigned int bytes); void FUN_0086ba60(void* memory); };
extern AllocationHeap DAT_01090a78;
struct HeapAllocated {
    static void* operator new(size_t bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
    static void operator delete(void* memory) { DAT_01090a78.FUN_0086ba60(memory); }
};
struct FUN_007eca70 : HeapAllocated {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FUN_007eca70();
};
struct FUN_007efda0 : HeapAllocated {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    FUN_007efda0();
};
struct FUN_007ee7d0 : HeapAllocated {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    FUN_007ee7d0();
};
struct FUN_007ee150 : HeapAllocated {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_007ee150();
};
struct FUN_005abc50 : HeapAllocated {
    unsigned int unk00;
    unsigned int unk04;
    FUN_005abc50();
};
// pdb: ActorPackageData::CreateActorPackageData | ActorPackageData.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap) + skyrim(call_gap), high
void* __cdecl ActorPackageData_CreateActorPackageData(unsigned int kind) {
    void* object=0;
    switch(kind) {
    case 2: object=new FUN_007eca70; break;
    case 12: object=new FUN_007efda0; break;
    case 13: object=new FUN_007ee7d0; break;
    case 14: object=new FUN_007ee150; break;
    case 16: object=new FUN_005abc50; break;
    default: break;
    }
    return object;
}
}
}   // namespace f3m_00723d70
