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

// @f3 0x00586fa0 (community match, verified in this file)
namespace f3m_00586fa0 {
namespace Task1723 {
struct Heap { void* FUN_0086b930(unsigned int); }; extern Heap DAT_01090a78;
class FUN_0058a210 { public:
virtual ~FUN_0058a210();
virtual void v04();
virtual void v08();
virtual void v0c();
virtual void v10();
virtual void v14();
virtual void v18();
virtual void v1c();
virtual void v20(bool);
virtual void v24();
virtual void v28();
virtual bool v2c(FUN_0058a210*);
virtual void v30();
virtual void v34();
virtual void v38();
int type; float time; float* quantities; unsigned count;
FUN_0058a210(int,unsigned); bool FUN_00585b00(unsigned,float);
static void* operator new(unsigned int n) { return DAT_01090a78.FUN_0086b930(n); }
};
class Animation { public:
virtual void v000();
virtual void v004();
virtual void v008();
virtual void v00c();
virtual void v010();
virtual void v014();
virtual void v018();
virtual void v01c();
virtual void v020();
virtual void v024();
virtual void v028();
virtual void v02c();
virtual void v030();
virtual void v034();
virtual void v038();
virtual void v03c();
virtual void v040();
virtual void v044();
virtual void v048();
virtual void v04c();
virtual void v050();
virtual void v054();
virtual void v058();
virtual void v05c();
virtual void v060();
virtual void v064();
virtual void v068();
virtual void v06c();
virtual void v070();
virtual void v074();
virtual void v078();
virtual void v07c();
virtual void v080();
virtual void v084();
virtual void v088();
virtual void v08c();
virtual void v090();
virtual void v094();
virtual void v098();
virtual void v09c();
virtual void v0a0();
virtual void v0a4();
virtual void v0a8();
virtual void v0ac();
virtual void v0b0();
virtual void v0b4();
virtual void v0b8();
virtual void v0bc();
virtual void v0c0();
virtual void v0c4();
virtual void v0c8();
virtual void v0cc();
virtual void v0d0();
virtual void v0d4();
virtual void v0d8();
virtual void v0dc();
virtual void v0e0();
virtual void v0e4();
virtual void v0e8();
virtual void v0ec();
virtual void v0f0();
virtual void v0f4();
virtual void v0f8();
virtual void v0fc();
virtual void v100();
virtual void v104();
virtual void v108();
virtual void v10c();
virtual void v110();
virtual void v114();
virtual void v118();
virtual void v11c();
virtual void v120();
unsigned unk04,unk08; FUN_0058a210* target; FUN_0058a210 current;
int unk024;int unk028;int unk02c;int unk030;int unk034;int unk038;int unk03c;int unk040;int unk044;int unk048;int unk04c;int unk050;int unk054;int unk058;int unk05c;int unk060;int unk064;int unk068;int unk06c;int unk070;int unk074;int unk078;int unk07c;int unk080;int unk084;int unk088;int unk08c;int unk090;int unk094;int unk098;int unk09c;int unk0a0;int unk0a4;int unk0a8;int unk0ac;int unk0b0;int unk0b4;int unk0b8;int unk0bc;int unk0c0;int unk0c4;int unk0c8;int unk0cc;int unk0d0;int unk0d4;int unk0d8;int unk0dc;int unk0e0;int unk0e4;int unk0e8;int unk0ec;int unk0f0;int unk0f4;int unk0f8;int unk0fc;int unk100;int unk104;int unk108;int unk10c;int unk110;int unk114;int unk118;int unk11c;int unk120;int unk124;int unk128;int unk12c;int unk130;int unk134;int unk138;int unk13c;int unk140;int unk144;int unk148;int unk14c;int unk150;int unk154;int unk158;int unk15c;int unk160;int unk164;int unk168;int unk16c;int unk170;int unk174;int unk178;int unk17c;int unk180;int unk184;int unk188;unsigned char unk18c,unk18d;bool blocked;void FUN_00586fa0(int,bool);
};
// pdb: BSFaceGenAnimationData::SetExpressionTargetFromMood | BSFaceGenAnimationData.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiMoodindex, abTalking
void Animation::FUN_00586fa0(int mood,bool talking){if(target)target->v20(true);else{target=new FUN_0058a210(1,15);target->v38();}if(blocked)return;switch(mood){case 0:target->FUN_00585b00(5,1.0f);break;case 1:target->FUN_00585b00(6,1.0f);break;case 2:target->FUN_00585b00(7,1.0f);break;case 3:target->FUN_00585b00(8,1.0f);break;case 4:target->FUN_00585b00(9,1.0f);break;case 5:target->FUN_00585b00(10,1.0f);break;case 6:target->FUN_00585b00(11,1.0f);break;case 7:target->FUN_00585b00(12,1.0f);break;}if(!current.v2c(target))v120();}
}
}   // namespace f3m_00586fa0
