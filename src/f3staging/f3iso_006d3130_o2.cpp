#include <new>
// src/f3staging/f3iso_006d3130_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x006d3130 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006d3130 (community match, verified in this file)
#include <string.h>
namespace f3m_006d3130 {

namespace moved_record {
struct Id { unsigned char bytes[3]; unsigned FUN_006d6cd0() const; };
struct Vec { float x,y,z; };

struct Basic { Id ref; Vec pos, rot; };
struct Interior { Id ref; Vec pos, rot; unsigned char flag; Id cell; };
struct Exterior { Id ref; unsigned char pos[12],rot[12]; Id world; short x,y; };

struct Decoded { unsigned ref,cell,world; int x,y; Vec pos,rot; unsigned char flag;
void basic(const Basic&); void interior(const Interior&); void FUN_006d3130(const Exterior&); };
// pdb: ReferenceInitialData::Initialize | BGSSaveLoadInitialData.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apMovedReferenceInitialData
void Decoded::FUN_006d3130(const Exterior& r){ref=r.ref.FUN_006d6cd0();cell=0;world=r.world.FUN_006d6cd0();x=r.x;y=r.y; memcpy(&pos,r.pos,sizeof(pos));memcpy(&rot,r.rot,sizeof(rot));flag=0;}
}

}   // namespace f3m_006d3130
