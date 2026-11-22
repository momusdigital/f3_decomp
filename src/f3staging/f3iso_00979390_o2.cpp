#include <new>
// src/f3staging/f3iso_00979390_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00979390 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00979390 (community match, verified in this file)
namespace f3m_00979390 {
struct VectorArray { const float* values; int count; };
bool FUN_009792a0(const float*,const float*);
// pdb: hkMultiSphereShapeCinfo::~hkMultiSphereShapeCinfo | BSTreeNode.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
bool FUN_00979390(const VectorArray* left,const VectorArray* right) {
    const int count=left->count;
    bool equal=count==right->count;
    if(equal) {
        for(int i=0;i<count && equal;++i) {
            equal=FUN_009792a0(left->values+i*4,right->values+i*4);
        }
    }
    return equal;
}
}   // namespace f3m_00979390
