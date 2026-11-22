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

// @f3 0x0058a280 (community match, verified in this file)
namespace f3m_0058a280 {
class BSFaceGenKeyframe {
public:
 int type;float weight;
 BSFaceGenKeyframe():type(-1),weight(0.0f){}
 virtual ~BSFaceGenKeyframe();
 virtual int GetType();
 virtual void unk08();
 virtual float GetWeight();
 void SetType(int t) {if(t!=type) type=t;}
 void SetWeight(float w) {if(w!=weight) weight=w;}
};
class BSFaceGenKeyframeMultiple:public BSFaceGenKeyframe {
public:
 float* values;unsigned int count;
 virtual ~BSFaceGenKeyframeMultiple();
 void FUN_0058a0c0(unsigned int,int);
 float GetValue(unsigned int i) {if(i<count) return values[i];return 0.0f;}
 void SetValue(unsigned int i,float value) {if(i<count && values[i]!=value) values[i]=value;}
 BSFaceGenKeyframeMultiple(BSFaceGenKeyframeMultiple*);
};
// pdb: BSFaceGenKeyframeMultiple::BSFaceGenKeyframeMultiple | BSFaceGenKeyframe.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aOther
BSFaceGenKeyframeMultiple::BSFaceGenKeyframeMultiple(BSFaceGenKeyframeMultiple* other) {
 SetType(other->GetType());
 SetWeight(other->GetWeight());
 values=0;count=0;
 FUN_0058a0c0(other->count,1);
 for(unsigned int i=0;i<count;++i) SetValue(i,other->GetValue(i));
}
}   // namespace f3m_0058a280

// @f3 0x0058a8e0 (community match, verified in this file)
namespace f3m_0058a8e0 {
// pdb: BSFaceGenManager::GetExpressionFromEmotion | BSFaceGenManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: aeWhich
int FUN_0058a8e0(int n)
{
    switch (n)
    {
    case 1:
    case 2:
        return 0;
    case 3:
        return 1;
    case 5:
        return 2;
    case 4:
        return 3;
    case 6:
        return 4;
    case 7:
        return 13;
    }
    return -1;
}
}   // namespace f3m_0058a8e0

// @f3 0x0058a210 (community match, verified in this file)
namespace f3m_0058a210 {
namespace task1340 {
struct Base {
 virtual ~Base();
 int type;
 float time;
 Base(int t) { time=0.0f; type=t; }
};
struct FUN_0058a210 : Base {
 float* values;
 unsigned count;
 FUN_0058a210(int,unsigned);
 virtual ~FUN_0058a210();
 void FUN_0058a0c0(unsigned,bool);
};
// pdb: BSFaceGenKeyframeMultiple::BSFaceGenKeyframeMultiple | BSFaceGenKeyframe.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeType, aiNumQuantities
FUN_0058a210::FUN_0058a210(int t,unsigned n): Base(t) {
 values=0;
 count=0;
 FUN_0058a0c0(n,true);
}
}
}   // namespace f3m_0058a210
