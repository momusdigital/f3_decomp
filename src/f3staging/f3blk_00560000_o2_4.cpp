// src/f3staging/f3blk_00560000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00563c10 (community match, verified in this file)
extern unsigned int DAT_00f4a768;extern int DAT_00f47bf4,DAT_00f46078;
namespace f3m_00563c10 {
namespace Message146{
extern void* __cdecl TESForm_GetFormByNumericID(unsigned int);
extern void* __cdecl FUN_00c0050a(void*,int,const void*,const void*,int);
struct Message146{unsigned int tag,unk04,id,action;};
struct Owner146{virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual bool Apply(void*);
bool FUN_00455330(Message146*);
bool FUN_00563c10(Message146*);
};
// pdb: TESTopicInfo::SavesBefore | TESTopicInfo.obj | fnv360_0822_retail, vtable, medium
// pdb params: apGroupFORM
bool Owner146::FUN_00563c10(Message146* message){
 bool result=false;
 if(message&&message->tag==DAT_00f4a768){
  switch(message->action){
   case 0:result=FUN_00455330(message);break;
   case 1:case 2:case 3:case 4:case 5:case 6:result=false;break;
   case 7:{void* object=FUN_00c0050a(TESForm_GetFormByNumericID(message->id),0,&DAT_00f46078,&DAT_00f47bf4,0);if(object)result=Apply(object);break;}
  }
 }
 return result;
}
}
}   // namespace f3m_00563c10
