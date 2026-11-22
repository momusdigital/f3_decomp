// src/f3staging/f3blk_00a40000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a54650 (community match, verified in this file)
extern float DAT_00dbe1e0, DAT_00dbe620, DAT_00db91dc;
namespace f3m_00a54650 {
struct FUN_00a549f0 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FUN_00a549f0(void* context) throw();
};
struct FUN_00a54a50 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    FUN_00a54a50(void* context) throw();
};
struct FUN_00a54650 {
    unsigned int unk00;
    void* volatile pointer;
    FUN_00a549f0 first;
    FUN_00a54a50 second;
    float value40, value44, value48, unk4C, value50, value54;
    volatile float value58, value5C;
    unsigned int count;
    volatile bool enabled;
    FUN_00a54650(void* context);
};
// pdb: hkpMoppCompiler::hkpMoppCompiler | hkpMoppCompiler.obj | fnv360_0822_retail, callee_sim, high
// pdb params: meshType
FUN_00a54650::FUN_00a54650(void* context) : first(context), second(context) {
    value40 = DAT_00dbe1e0;
    count = 5;
    float common = DAT_00dbe620;
    value44 = common;
    value48 = 1.0f;
    value50 = common;
    value54 = common;
    value58 = DAT_00db91dc;
    value5C = 0.0f;
    enabled = true;
    pointer = 0;
}

}   // namespace f3m_00a54650
