#include <windows.h>
#include <math.h>
#include <stdlib.h>
// src/f3staging/f3blk_00680000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00683980 (community match, verified in this file)
namespace f3m_00683980 {
namespace Task1882 {
struct Tile{bool FUN_00beac40();bool FUN_00becf80(int);float FUN_00becf40(int);void FUN_00bed970(int);Tile* FUN_00bed3c0(int);void FUN_00bee190(int,float,bool);void FUN_00bf11a0(int,const char*,bool);};
struct Option{virtual void v0();int unk04;void(*callback)();unsigned modes;int unk10;};
struct UserOption:Option{int value;int unk18;int type;unsigned count;};
struct OptionList{virtual void v0();virtual Tile* GetHighlightedItem();Option* FUN_00632d70();void FUN_0067a7f0(int);void FUN_0067d9c0(int);void FUN_00655800(void(*)(),int,int);bool FUN_0067a880();};
struct Input{bool FUN_00be9a90();};struct Controls{Input* FUN_006e4eb0(int,int,unsigned char);};extern Controls* DAT_0107a0d4;
struct Pause{bool FUN_00658af0();};extern Pause* DAT_010769ac;
struct Setting{int unk00;const char* value;};extern Setting* DAT_01073954[];extern const char* DAT_00f64ac4;extern const char* DAT_00f62c88;
struct ResetState{int first;int second;void Reset(){second=0;first=0;}};ResetState* FUN_0067aea0();
bool FUN_0061c490(int);int FUN_0061efa0(int);bool FUN_00477b00();int Tile_GetMenuByClass(int);void FUN_0061e7d0(int);void FUN_00619700(const char*,int,int,int,int,int,const char*,int);void FUN_006213f0(int);void FUN_006809b0();void FUN_0067d410();void FUN_0067c6f0();float FUN_0047ca30(float,float);
extern "C" void* __cdecl FUN_00c0050a(void*,int,const void*,const void*,int);extern char DAT_00f6b3e8;extern char DAT_00f6b408;
struct Menu{virtual void v0();virtual void v4();virtual void v8();virtual void Click(int,Tile*); int unk04;int unk08;int unk0c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
Tile* tile38;
Tile* tile3c;
int unk040;
int unk044;
int unk048;
Tile* tile4c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
Tile* tile64;
Tile* tile68;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
OptionList list;
int unk110;
int unk114;
int unk118;
int unk11c;
int unk120;
int unk124;
int unk128;
int unk12c;
int unk130;
int unk134;
int unk138;
int unk13c;
int unk140;
int unk144;
int unk148;
int unk14c;
int unk150;
int unk154;
int unk158;
int unk15c;
int unk160;
int unk164;
int unk168;
int unk16c;
int unk170;
int unk174;
int unk178;
int unk17c;
int unk180;
int unk184;
int unk188;
int unk18c;
int unk190;
int unk194;
int unk198;
UserOption* dirty;
unsigned flags;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int mode;
bool Flag(unsigned f){return (flags&f)!=0;}bool FUN_0067aee0();void StartMenu__UpdateProfileSpecificData();bool FUN_00683980(int,int);
};extern Menu* DAT_010770ac;
// pdb: StartMenu::DoGamepad | StartMenu.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiButton, afValue
bool Menu::FUN_00683980(int button,int unused){
if(FUN_0061c490(0x3f5)){
if(button>0){
if(Flag(0x80000)&&DAT_010769ac)return DAT_010769ac->FUN_00658af0();
else if(DAT_010770ac->mode==3&&FUN_0067aee0()){
int action=list.FUN_00632d70()->modes;int key=FUN_0061efa0(button);
if(DAT_0107a0d4->FUN_006e4eb0(action,3,(unsigned char)key)->FUN_00be9a90()){
if(FUN_00477b00())tile68->FUN_00bee190(0xfa3,0.0f,true);else {Setting* setting=DAT_01073954[mode];tile68->FUN_00bf11a0(0xfc4,setting?setting->value:0,true);}
list.FUN_0067a7f0(1);list.FUN_0067d9c0(1);list.FUN_00655800(FUN_0067d410,0,0x7fffffff);flags|=2;tile3c->FUN_00bee190(0xfaf,1.0f,true);
}else if(!Tile_GetMenuByClass(0x3e9)){FUN_0061e7d0(10);FUN_00619700(DAT_00f64ac4,0,0,0,1,0x12,DAT_00f62c88,0);}return true;}}
switch(button){
case 10: if(tile3c->FUN_00becf80(0xfaf)){FUN_006213f0(10);FUN_006809b0();return true;}
case 5:case 9: if(!Flag(1)&&tile4c->FUN_00becf80(0xfa3)&&tile4c->FUN_00becf40(0xfa9)!=0.0){StartMenu__UpdateProfileSpecificData();FUN_0067aea0()->Reset();return true;}break;
case 12:if(tile38->FUN_00beac40()&&tile38->FUN_00becf80(0xfaf)){tile38->FUN_00bed970(0xfcb);Click(4,tile38);return true;}break;
case 11:if(tile64->FUN_00beac40()&&tile64->FUN_00becf80(0xfaf)){tile64->FUN_00bed970(0xfcb);Click(15,tile64);return true;}break;
case 3:case 4:if(list.FUN_0067a880()&&list.GetHighlightedItem()){int id=button==4?100:101;Tile*tile=list.GetHighlightedItem()->FUN_00bed3c0(id);if(tile&&tile->FUN_00beac40()&&tile->FUN_00becf80(0xfaf)){Click(id,tile);tile->FUN_00bed970(0xfcb);return true;}else if(id==101&&list.FUN_00632d70()&&list.FUN_00632d70()->callback==FUN_0067c6f0){Click(-1,list.GetHighlightedItem());tile->FUN_00bed970(0xfcb);return true;}}break;
case 15:case 16:if(list.FUN_0067a880()){UserOption* option=(UserOption*)FUN_00c0050a(list.FUN_00632d70(),0,&DAT_00f6b3e8,&DAT_00f6b408,0);if(option&&option->type==2){int delta=(int)FUN_0047ca30(list.GetHighlightedItem()->FUN_00becf40(0x1005),1.0f);int id=101;if(button==15){delta*=-1;id=100;}option->value+=delta;if(option->value<0)option->value=0;else if((unsigned)option->value>=option->count)option->value=option->count-1;dirty=option;list.GetHighlightedItem()->FUN_00bed3c0(id)->FUN_00bed970(0xfcb);return true;}}break;
}}return false;}
}
}   // namespace f3m_00683980
