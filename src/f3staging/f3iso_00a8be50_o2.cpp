#include <new>
// src/f3staging/f3iso_00a8be50_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a8be50 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a8be50 (community match, verified in this file)
extern const unsigned int* DAT_010661dc[];
namespace f3m_00a8be50 {
static __declspec(noinline) void FUN_00a8be00(int digit,int stride,int* pixels) {
    const unsigned int* pattern=DAT_010661dc[digit];
    for(int x=0;x<8;++x) {
        for(int y=0;y<7;++y) {
            if((pattern[6-y]<<(x*4))&0xf0000000)
                pixels[y*stride+x]=0xff000000;
        }
    }
}
// pdb: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::reserve | hkMap.obj | fnv360_0822_retail, call_dedup, low
// pdb params: alloc, numElements
static __declspec(noinline) void FUN_00a8be50(int value,int stride,int* pixels) {
    int x=0;
    for(int place=1000;place>=1;place/=10) {
        FUN_00a8be00((value/place)%10,stride,pixels+x);
        x+=7;
    }
}
struct DisplayRows { int firstRow; int state[3]; int rowHeight,width; };
void drawDisplayRowNumber(const DisplayRows& rows,int* texture,int value,int row,int origin,int columns) {
    if(columns>1)
        FUN_00a8be50(value,rows.width,texture+(row-rows.rowHeight-origin)*rows.width);
}
}   // namespace f3m_00a8be50
