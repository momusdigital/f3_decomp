#include <new>
// src/f3staging/f3iso_00986650_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00986650 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00986650 (community match, verified in this file)
extern char DAT_00e7d734[];
namespace f3m_00986650 {
struct Entity { char prefix[0x96]; unsigned short priority; };
struct Constraint {
    void* vtable; unsigned short size, references; int count, data;
    Entity* first; Entity* second; unsigned short priority;
    Constraint* FUN_00986650(int,Entity*,Entity*);
};
// pdb: hkpReportContactMgr::hkpReportContactMgr | hkpReportContactMgr.obj | tesv_win, uvref, medium
Constraint* Constraint::FUN_00986650(int value,Entity* a,Entity* b) {
    references=1; count=1; vtable=DAT_00e7d734;
    unsigned short pb=b->priority,pa=a->priority;
    priority=pa<pb?pa:pb;
    first=a; second=b; data=value; return this;
}
}   // namespace f3m_00986650
