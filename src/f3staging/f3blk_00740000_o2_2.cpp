#include <windows.h>
// src/f3staging/f3blk_00740000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0074a170 (community match, verified in this file)
extern int* DAT_00f6ee80[];
namespace f3m_0074a170 {
namespace allowa1 {
struct Item { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; signed char unk20; };
// pdb: LowProcess::ShouldStopCombatControllerToFinishPackage | LowProcess.obj | fnv360_0822_retail, call_seq, low
// pdb params: apPackage, aiIndex
bool __stdcall FUN_0074a170(Item* item,int index) {
 switch(item->unk20) { case 0: case 1: case 6: case 7: case 13: case 14: case 17: return false; }
 if(item->unk18!=-1 && DAT_00f6ee80[item->unk18][index]==0x35) return false;
 return true;
}
}
}   // namespace f3m_0074a170

// @f3 0x007555b0 (community match, verified in this file)
extern int* DAT_00f6ee80[]; extern const float DAT_00db38b8;
namespace f3m_007555b0 {
struct Target55 { bool FUN_006f8d70(); }; struct Aux55 { unsigned FUN_007ef480(); };
struct Entry55 {
virtual void slot0();
virtual void slot4();
virtual void slot8();
virtual void slotc();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1c();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2c();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3c();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4c();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5c();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6c();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void slot7c();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8c();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual void slot9c();
virtual void slota0();
virtual void slota4();
virtual void slota8();
virtual void slotac();
virtual void slotb0();
virtual void slotb4();
virtual void slotb8();
virtual void slotbc();
virtual void slotc0();
virtual void slotc4();
virtual void slotc8();
virtual void slotcc();
virtual void slotd0();
virtual void slotd4();
virtual void slotd8();
virtual void slotdc();
virtual void slote0();
virtual void slote4();
virtual void slote8();
virtual void slotec();
virtual void slotf0();
virtual void slotf4();
virtual void slotf8();
virtual void slotfc();
virtual void slot100();
virtual void slot104();
virtual void slot108();
virtual void slot10c();
virtual void slot110();
virtual void slot114();
virtual void slot118();
virtual void slot11c();
virtual void slot120();
virtual void slot124();
virtual void slot128();
virtual void slot12c();
virtual void slot130();
virtual void slot134();
virtual void slot138();
virtual bool action(Target55*,int,float,int);
 int unk04,unk08,unk0c,unk10,unk14,row;
 int GetRow() const {return row;}
};
struct Owner55 { virtual void slot0();
virtual void slot4();
virtual void slot8();
virtual void slotc();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1c();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2c();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3c();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4c();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5c();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6c();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void slot7c();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8c();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual void slot9c();
virtual void slota0();
virtual void slota4();
virtual void slota8();
virtual void slotac();
virtual void slotb0();
virtual void slotb4();
virtual void slotb8();
virtual void slotbc();
virtual void slotc0();
virtual void slotc4();
virtual void slotc8();
virtual void slotcc();
virtual void slotd0();
virtual void slotd4();
virtual void slotd8();
virtual void slotdc();
virtual void slote0();
virtual void slote4();
virtual void slote8();
virtual void slotec();
virtual void slotf0();
virtual void slotf4();
virtual void slotf8();
virtual void slotfc();
virtual void slot100();
virtual void slot104();
virtual void slot108();
virtual void slot10c();
virtual void slot110();
virtual void slot114();
virtual void slot118();
virtual void slot11c();
virtual void slot120();
virtual void slot124();
virtual void slot128();
virtual void slot12c();
virtual void slot130();
virtual void slot134();
virtual void slot138();
virtual void slot13c();
virtual void slot140();
virtual void slot144();
virtual void slot148();
virtual void slot14c();
virtual void slot150();
virtual void slot154();
virtual void slot158();
virtual void slot15c();
virtual void slot160();
virtual void slot164();
virtual void slot168();
virtual void slot16c();
virtual void slot170();
virtual void slot174();
virtual void slot178();
virtual void slot17c();
virtual void slot180();
virtual void slot184();
virtual void slot188();
virtual void slot18c();
virtual void slot190();
virtual void slot194();
virtual void slot198();
virtual void slot19c();
virtual void slot1a0();
virtual void slot1a4();
virtual void slot1a8();
virtual void slot1ac();
virtual void slot1b0();
virtual void slot1b4();
virtual void slot1b8();
virtual void slot1bc();
virtual void slot1c0();
virtual void slot1c4();
virtual void slot1c8();
virtual void slot1cc();
virtual void slot1d0();
virtual void slot1d4();
virtual void slot1d8();
virtual void slot1dc();
virtual void slot1e0();
virtual void slot1e4();
virtual void slot1e8();
virtual void slot1ec();
virtual void slot1f0();
virtual void slot1f4();
virtual void slot1f8();
virtual void slot1fc();
virtual void slot200();
virtual void slot204();
virtual void slot208();
virtual void slot20c();
virtual void slot210();
virtual void slot214();
virtual void slot218();
virtual void slot21c();
virtual void slot220();
virtual void slot224();
virtual void slot228();
virtual void slot22c();
virtual void slot230();
virtual void slot234();
virtual void slot238();
virtual void slot23c();
virtual void slot240();
virtual void slot244();
virtual void slot248();
virtual void slot24c();
virtual void slot250();
virtual void slot254();
virtual void slot258();
virtual void slot25c();
virtual void slot260();
virtual void slot264();
virtual void slot268();
virtual void slot26c();
virtual Aux55* aux();
virtual void slot274();
virtual Entry55* entry();
virtual int column();
 int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
unsigned flags;
int Lookup(int row) {return DAT_00f6ee80[row][column()];}
bool FUN_007555b0(Target55*); };
// pdb: MiddleHighProcess::ShouldPickPackIdle | MiddleHighProcess.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apActor
bool Owner55::FUN_007555b0(Target55* target) {
if(flags&0x40) return false;
Entry55* entry=this->entry();
bool result=false;
int type=DAT_00f6ee80[entry->GetRow()][column()];
if(type==42) { Aux55* aux=this->aux(); if(aux) type=aux->FUN_007ef480(); }
switch(type) { case 0: case 1: case 4: case 5: case 6: case 7: case 27: case 28: case 30: case 34: case 44: case 47: case 49: case 53:
if(entry->GetRow()==0) {if(entry->action(target,0,DAT_00db38b8,0)) result=true;}
else {if(target->FUN_006f8d70()) result=true;}
}
return result;
}
}   // namespace f3m_007555b0
