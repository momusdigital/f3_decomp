// src/f3staging/f3blk_00680000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006875c0 (community match, verified in this file)
namespace f3m_006875c0 {
__declspec(selectany) extern const char DAT_00e055d0[]="Interface\\Stats\\face_%02d.dds";
__declspec(selectany) extern const char DAT_00e06008[]="%d/%d";
__declspec(selectany) extern const char DAT_00e08464[]="(%d) %s";
__declspec(selectany) extern const char DAT_00dbab78[]="%s";
__declspec(selectany) extern const char DAT_00e085c8[]="%d%%";
__declspec(selectany) extern const char DAT_00e055b8[]="Interface\\Stats\\%s.dds";
__declspec(selectany) extern const char DAT_00e05598[]="Interface\\Stats\\%s_broken.dds";
__declspec(selectany) extern const char DAT_00e035d8[]="_Value";
__declspec(selectany) extern const char DAT_00e0858c[]="Interface\\Icons\\PipboyImages\\Karma icons\\karma_neutral.dds";
__declspec(selectany) extern const char DAT_00e08554[]="Interface\\Icons\\PipboyImages\\Karma icons\\karma_good.dds";
__declspec(selectany) extern const char DAT_00e0851c[]="Interface\\Icons\\PipboyImages\\Karma icons\\karma_bad.dds";
__declspec(selectany) extern const char DAT_00e084e0[]="Interface\\Icons\\PipboyImages\\Karma icons\\karma_saintly.dds";
__declspec(selectany) extern const char DAT_00e084a8[]="Interface\\Icons\\PipboyImages\\Karma icons\\karma_evil.dds";
struct UITile { void FUN_00bf11a0(unsigned, const char*, bool); const char* Tile_GetString(unsigned); void FUN_00bee190(unsigned, float, bool); };
struct HeapHolder { void FUN_0086ba60(void*); };
extern HeapHolder DAT_01090a78;
struct MenuString {
    char* text; unsigned short length, capacity;
    MenuString() : text(0), length(0), capacity(0) {}
    ~MenuString() { char* old=text; if(old) DAT_01090a78.FUN_0086ba60(old); text=0; capacity=0; length=0; }
    __declspec(noalias) bool FUN_004019c0(const char*, unsigned);
    __declspec(noalias) int FUN_00403a00(const char*, ...);
};
extern int __cdecl Format(MenuString*, const char*, ...);
struct Item { void FUN_0047fd30(); int FUN_007270f0(); };
struct ValueOwner {
    virtual void v00(); virtual void v04(); virtual int CurrentInt(int);
    virtual float Current(int); virtual void v10(); virtual void v14(); virtual void v18(); virtual int Maximum(int);
    int FUN_005a29a0(int);
};
struct Player {
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
    unsigned unkC;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1C;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2C;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3C;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4C;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5C;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6C;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7C;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8C;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    ValueOwner values;
    Item* FUN_004e8ab0(unsigned, int);
    unsigned short Actor_GetLevel();
};
extern Player* DAT_0107a104;
struct Setting { int* FUN_004241e0(); };
extern Setting DAT_00f62300;
extern const char* DAT_00f64cd4;
extern const char* DAT_00f64c74;
extern const char* DAT_00f64c68;
extern const char* DAT_00f64c80;
extern const char* DAT_00f64c8c;
extern const char* DAT_00f64c98;
extern const char* DAT_00f6b5c8[];
extern float DAT_00f61e9c;
extern double DAT_00dba730;
extern int __cdecl FUN_005850f0(int);
extern unsigned __cdecl FUN_00becd70(const char*, int);
extern int __cdecl FUN_0044f380(float);
extern void __cdecl FUN_006844f0();
extern void __cdecl FUN_00684530(void*, int);
extern void __cdecl FUN_006845f0(void*, int);
struct Entry { void* data; int key; };
struct Node { Entry* item; Node* next; };
struct List {
    unsigned unk0; Node head;
    __forceinline void* Find(int key) {
        List* list=this;
        if(list) { Node* n=&list->head; if(n) { while(n) { Entry* const& item=n->item; if(!item) break; if(item->key==key) return item->data; n=n->next; } } }
        return 0;
    }
};
struct ItemSlot { unsigned key; UITile* tile; Item* item; bool (__cdecl* predicate)(unsigned*); __forceinline UITile* GetTile() { return tile; } };
struct StatsMenu {
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
    unsigned unkC;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1C;
    unsigned unk20;
    unsigned unk24;
    ItemSlot slots[3];
    unsigned unk58;
    unsigned unk5C;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6C;
    unsigned unk70;
    UITile* tiles[46];
    List listA;
    unsigned unk138;
    unsigned unk13C;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14C;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    List listB;
    unsigned unk168;
    unsigned unk16C;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17C;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18C;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19C;
    unsigned unk1A0;
    unsigned unk1A4;
    unsigned unk1A8;
    unsigned unk1AC;
    unsigned unk1B0;
    unsigned unk1B4;
    unsigned unk1B8;
    unsigned unk1BC;
    unsigned unk1C0;
    unsigned unk1C4;
    unsigned unk1C8;
    unsigned unk1CC;
    unsigned unk1D0;
    unsigned unk1D4;
    unsigned unk1D8;
    unsigned unk1DC;
    unsigned unk1E0;
    unsigned unk1E4;
    unsigned unk1E8;
    unsigned unk1EC;
    unsigned unk1F0;
    unsigned unk1F4;
    unsigned unk1F8;
    unsigned unk1FC;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20C;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned char active;
    int FUN_00684cd0(); void FUN_006843b0(); void FUN_00686ee0(); void FUN_00685b10();
    __forceinline UITile* Root() { return (UITile*)unk4; }
    __forceinline UITile* VisibilityTile() { return tiles[9]; }
    void FUN_006875c0(int value);
    __forceinline void UpdateSlot(int i) {
        MenuString label;
        Item* old=slots[i].item;
        if(old) { old->FUN_0047fd30(); DAT_01090a78.FUN_0086ba60(old); }
        slots[i].item=DAT_0107a104->FUN_004e8ab0(slots[i].key,0);
        bool enabled=slots[i].predicate(&slots[i].key);
        slots[i].GetTile()->FUN_00bee190(0xfaf,(float)enabled,true);
        if(i==0) {
            
            if(slots[i].item) { label.FUN_00403a00(DAT_00e08464,slots[i].item->FUN_007270f0(),slots[i].GetTile()->Tile_GetString(0x1004)); VisibilityTile()->FUN_00bee190(0xfaf,1.f,true); }
            else { const char* defaultText=slots[i].GetTile()->Tile_GetString(0x1004); label.FUN_004019c0(defaultText,0); if(active) FUN_00685b10(); VisibilityTile()->FUN_00bee190(0xfaf,0.f,true); }

        } else {
            if(slots[i].item) label.FUN_00403a00(DAT_00e08464,slots[i].item->FUN_007270f0(),slots[i].GetTile()->Tile_GetString(0x1004));
            else { const char* defaultText=slots[i].GetTile()->Tile_GetString(0x1004); label.FUN_004019c0(defaultText,0); }
        }
        slots[i].GetTile()->FUN_00bf11a0(0xfc4,label.text,true);
    }
};
// pdb: StatsMenu::UpdateActorValue | StatsMenu.obj | fnv360_0822_retail, ustr, medium
// pdb params: aeWhich
void StatsMenu::FUN_006875c0(int value) {
    MenuString formatted;
    int tileIndex, valueIndex;
    switch(value) {
    case 16: {
        formatted.FUN_00403a00(DAT_00e055d0,FUN_00684cd0());
        tiles[24]->FUN_00bf11a0(0xfcc,formatted.text,true);
        
        formatted.FUN_00403a00(DAT_00e06008,DAT_0107a104->values.CurrentInt(16),DAT_0107a104->values.Maximum(16));
        Root()->FUN_00bf11a0(0x1009,formatted.text,true);
        if(DAT_0107a104) for(int i=0;i<3;++i) { switch(i) { case 0: UpdateSlot(i); break; } }
        break;
    }
    case 12: {
        
        formatted.FUN_00403a00(DAT_00e06008,DAT_0107a104->values.CurrentInt(12),DAT_0107a104->values.Maximum(12));
        Root()->FUN_00bf11a0(0x100a,formatted.text,true); break;
    }
    case 24: {
        int level=DAT_0107a104->Actor_GetLevel();
        if(level>=*DAT_00f62300.FUN_004241e0()) formatted.FUN_00403a00(DAT_00dbab78,DAT_00f64cd4);
        else {  formatted.FUN_00403a00(DAT_00e06008,DAT_0107a104->values.CurrentInt(24),FUN_005850f0(DAT_0107a104->Actor_GetLevel()+1)); }
        Root()->FUN_00bf11a0(0x100b,formatted.text,true); break;
    }
    case 54:
        FUN_006843b0();
        if(DAT_0107a104) { int i=0; do { if(i==2) UpdateSlot(i); ++i; } while(i<3); }
        FUN_00686ee0(); break;
    case 20: {
        int r=DAT_0107a104->values.FUN_005a29a0(20);
        int limit=(int)DAT_00f61e9c;
        formatted.FUN_00403a00(DAT_00e085c8,limit<r?limit:r);
        tiles[38]->FUN_00bf11a0(0xfc4,formatted.text,true);
        FUN_00686ee0(); break;
    }
    case 25: tileIndex=12; valueIndex=tileIndex+1; goto limb;
    case 26: tileIndex=14; valueIndex=tileIndex+1; goto limb;
    case 27: tileIndex=16; valueIndex=tileIndex+1; goto limb;
    case 28: tileIndex=18; valueIndex=tileIndex+1; goto limb;
    case 29: tileIndex=20; valueIndex=tileIndex+1; goto limb;
    case 30: tileIndex=22; valueIndex=tileIndex+1;
    limb: {
        float ratio=(float)(DAT_0107a104->values.Current(value)/DAT_00dba730);
        formatted.FUN_00403a00(ratio>0?DAT_00e055b8:DAT_00e05598,DAT_00f6b5c8[value]);
        tiles[tileIndex]->FUN_00bf11a0(0xfcc,formatted.text,true);
        tiles[valueIndex]->FUN_00bee190(FUN_00becd70(DAT_00e035d8,-1),ratio,true);
        if(active && DAT_0107a104) for(int i=0;i<3;++i) { switch(i) { case 0: UpdateSlot(i); break; } }
        break;
    }
    case 23:
        switch(FUN_0044f380(DAT_0107a104->values.Current(23))) {
        case 1: tiles[36]->FUN_00bf11a0(0xfcc,DAT_00e0858c,true); tiles[35]->FUN_00bf11a0(0xfc4,DAT_00f64c74,true); break;
        case 0: tiles[36]->FUN_00bf11a0(0xfcc,DAT_00e08554,true); tiles[35]->FUN_00bf11a0(0xfc4,DAT_00f64c68,true); break;
        case 2: tiles[36]->FUN_00bf11a0(0xfcc,DAT_00e0851c,true); tiles[35]->FUN_00bf11a0(0xfc4,DAT_00f64c80,true); break;
        case 3: tiles[36]->FUN_00bf11a0(0xfcc,DAT_00e084e0,true); tiles[35]->FUN_00bf11a0(0xfc4,DAT_00f64c8c,true); break;
        case 4: tiles[36]->FUN_00bf11a0(0xfcc,DAT_00e084a8,true); tiles[35]->FUN_00bf11a0(0xfc4,DAT_00f64c98,true); break;
        }
        FUN_006844f0(); break;
    default:
        FUN_00684530(listA.Find(value),value);
        FUN_006845f0(listB.Find(value),value);
    }
}
}   // namespace f3m_006875c0
