#include <new>
// src/f3staging/f3iso_00983070_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00983070 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00983070 (community match, verified in this file)
namespace f3m_00983070 {
struct Quality { char prefix[0x20]; unsigned short priority; };
struct Entity { char prefix[0xb8]; Quality* quality; };
struct Pair { int key; Entity* first; Entity* second; };
struct HavokBool { char value; HavokBool(bool b) : value(b) {} };
// pdb: islandLess | hkpWorldOperationQueue.obj | tesv_win, objrun_open, low
HavokBool FUN_00983070(const Pair& a,const Pair& b) {
    unsigned int pa=a.first->quality->priority,pb=b.first->quality->priority;
    return pa<pb || (pa==pb && a.second->quality->priority<b.second->quality->priority);
}
}   // namespace f3m_00983070
