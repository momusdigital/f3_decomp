#include <new>
// src/f3staging/f3iso_00962a40_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00962a40 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00962a40 (community match, verified in this file)
extern int DAT_00e7c424;
extern int DAT_00dcc494;
namespace f3m_00962a40 {
// Same bytes, but the manifest symbol is a plain global name, so the function
// must not be a member: __fastcall puts this in ecx and pops nothing (bare ret).

struct S00962a40_Member
{
    void FUN_008e4590();
};

struct S00962a40_Owner
{
    void* m_pVTable;             // +0x00
    int   m_nUnk04;              // +0x04
    S00962a40_Member m_kMember;  // +0x08
};

// pdb: hkaSkeletonMapper::~hkaSkeletonMapper | hkaSkeletonMapper.obj | tesv_win, callee_sim, low
void __fastcall FUN_00962a40(S00962a40_Owner* pThis, int)
{
    pThis->m_pVTable = &DAT_00e7c424;
    pThis->m_kMember.FUN_008e4590();
    pThis->m_pVTable = &DAT_00dcc494;
}
}   // namespace f3m_00962a40
