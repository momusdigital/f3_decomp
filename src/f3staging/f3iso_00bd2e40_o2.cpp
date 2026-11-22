#include <new>
// src/f3staging/f3iso_00bd2e40_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00bd2e40 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00bd2e40 (community match, verified in this file)
extern unsigned int DAT_0108ec68;
namespace f3m_00bd2e40 {
struct Ptr_bd2e40_Layout {
    void* p;
    __forceinline Ptr_bd2e40_Layout(void* q = 0) : p(q) {}
    __forceinline Ptr_bd2e40_Layout(const Ptr_bd2e40_Layout& o) : p(o.p) {}
    __forceinline ~Ptr_bd2e40_Layout() {}
};
struct Vec3_bd2e40_Layout {
    float x, y, z;
};
struct BD2E40Ctx_Layout
{
    void FUN_00bd24f0(int kind, int a, int b, int c, Ptr_bd2e40_Layout owner, Vec3_bd2e40_Layout position);
    void FUN_00bd2e40();
};
// pdb: BSAudioManager::VolumeChanged | BSAudioManager.obj | fnv360_0822_retail, call_seq, low
void BD2E40Ctx_Layout::FUN_00bd2e40()
{
    FUN_00bd24f0(14, 0, 0, 0, Ptr_bd2e40_Layout(), *reinterpret_cast<const Vec3_bd2e40_Layout*>(&DAT_0108ec68));
}
}   // namespace f3m_00bd2e40
