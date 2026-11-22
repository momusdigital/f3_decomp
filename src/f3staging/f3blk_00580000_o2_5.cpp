#include <stdexcept>
#include <new>
#include <new>
#include <new>
#include <new>
#include <new>
#include <string>
#include <vector>
#include <string.h>
#include <new>
#include <intrin.h>
#include <string.h>
// src/f3staging/f3blk_00580000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00597740 (community match, verified in this file)
namespace f3m_00597740 {
namespace Dispatch7740 {
struct Entry;
struct Table { void* unk00; void (__thiscall *Call)(Entry*,unsigned,unsigned,float); };
struct Entry { Table* table; };
struct Owner; 
struct Owner { int unk00; int unk04; Entry** group3; Entry** group2; Entry** group0; Entry** group1;
  void FUN_00597740(unsigned group,unsigned index,unsigned a,unsigned b,float value); };
// pdb: BSFaceGenMorphDataHead::ApplyMorph | BSFaceGenMorphData.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeType, aiIndex, apGeom, apBaseMorph, afModifier
void Owner::FUN_00597740(unsigned group,unsigned index,unsigned a,unsigned b,float value)
{
    Entry* entry;
    switch(group) {
    case 1: if(!group3 || index>14) return; entry=group3[index]; break;
    case 2: if(!group2 || index>16) return; entry=group2[index]; break;
    case 0: if(!group0 || index>15) return; entry=group0[index]; break;
    case 3: if(!group1 || index>0) return; entry=group1[index]; break;
    default: return;
    }
    if(!entry) return;
    entry->table->Call(entry,a,b,value);
}
}
}   // namespace f3m_00597740
