#include <windows.h>
#include <math.h>
// src/f3staging/f3blk_00640000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0065fab0 (community match, verified in this file)
namespace f3m_0065fab0 {

extern double DAT_00e06648, DAT_00e068f8;
extern float DAT_00e067fc, DAT_00db9220;
extern char DAT_00e06894[], DAT_00e04748[], DAT_00e0473c[];
struct InputState {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned char enabled;
};
extern bool __cdecl FUN_0061c490(int);
extern InputState* __cdecl Interface_GetPipboy();
extern bool __cdecl FUN_00477b00();
extern void __cdecl FUN_0061e7d0(int);
extern void __cdecl FUN_0061b370(int,int,int);
extern void __cdecl Interface_SetStatsMenuVisible(int,int);
struct Controller { int FUN_00be7ee0(int,int); };
struct InputManager { Controller* FUN_006e4eb0(); };
extern InputManager* DAT_0107a0d4;
struct MenuTile {
    void FUN_00bee190(int,float,bool);
    void FUN_00bef830(int,float);
    float FUN_00becf40(int);
    bool FUN_00becf80(void*);
    MenuTile* Tile_GetChildByName(const char*);
};
struct MenuNode { MenuNode* next; MenuNode* previous; MenuTile* tile; };
struct MenuList { int count; MenuNode* first;
    static MenuTile* const& GetNext(MenuNode*& pos) {
        MenuTile* const& result=pos->tile;
        pos=pos->next;
        return result;
    }
};
extern int __cdecl FUN_00bea9e0(const char*);
struct RepeatSetting { float* FUN_00401eb0(); };
extern RepeatSetting DAT_01075c04;
extern unsigned int DAT_01076c98, DAT_01090bb0;
extern void* DAT_01076b98;
struct MapMenu {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void dispatch(int,MenuTile*);
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
    int unk30;
    int unk34;
    MenuList* list;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    MenuTile* root;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int mode;
    MenuTile* map;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
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
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    MenuTile* scroll;
    void FUN_0065ebf0(bool,float);
    void FUN_0065e6e0();
    bool FUN_0065fab0(int event,void* extra);
};
// pdb: MapMenu::DoGamepad | MapMenu.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiButton, afValue
bool MapMenu::FUN_0065fab0(int event,void* extra) {
    if (!FUN_0061c490(0x3ff) || !Interface_GetPipboy()->enabled) return false;
    bool handled=false;
    int axis;
    if (FUN_0061c490(0x3ff)) {
        if (FUN_00477b00()) {
            DAT_0107a0d4->FUN_006e4eb0();
            if (mode==28 || mode==29) {
                axis=DAT_0107a0d4->FUN_006e4eb0()->FUN_00be7ee0(0,8);
                float value=(float)axis;
                if (!((float)fabs(value)<=DAT_00e06648) && axis!=0) {
                    float normal=(float)(value/32767.0);
                    float speed=(float)((float)fabs(normal)*DAT_00e068f8+1.0);
                    FUN_0065ebf0(axis>0,speed);
                    handled=true;
                }
            }
            int x=DAT_0107a0d4->FUN_006e4eb0()->FUN_00be7ee0(0,9);
            axis=DAT_0107a0d4->FUN_006e4eb0()->FUN_00be7ee0(0,10);
            if ((float)fabs((float)x)<=8689.0f) x=0;
            if ((float)fabs((float)axis)<=8689.0f) axis=0;
            switch(mode) {
            case 28: case 29:
                if (map) {
                    if (!x && !axis) {
                        map->FUN_00bee190(0xfea,-1.0f,true);
                        map->FUN_00bee190(0xfeb,-1.0f,true);
                        FUN_0065e6e0();
                    } else {
                        map->FUN_00bee190(0xfea,1.0f,true);
                        map->FUN_00bee190(0xfeb,1.0f,true);
                        float dx=(float)(x*-20.0/32767.0);
                        map->FUN_00bef830(0xfee,dx);
                        float dy=(float)(axis*20.0/32767.0);
                        map->FUN_00bef830(0xfef,dy);
                        handled=true;
                        FUN_0065e6e0();
                    }
                }
                break;
            case 30: case 31: {
                MenuTile* target;
                if (mode==30) target=scroll;
                else target=root->Tile_GetChildByName(DAT_00e06894);
                if (!target || target->FUN_00becf40(0xfa3)==0.0f || !axis) break;
                int step=(axis<0)?1:-1;
                if (!step) break;
                unsigned int last=DAT_01076c98;
                if (last) {
                    float* delay=DAT_01075c04.FUN_00401eb0();
                    if (!((float)(DAT_01090bb0-last)>*delay)) break;
                }
                int trait=FUN_00bea9e0(DAT_00e04748);
                int old=(int)target->FUN_00becf40(trait);
                target->FUN_00bee190(trait,(float)(old+step),false);
                if ((float)old!=target->FUN_00becf40(trait))
                    target->FUN_00bef830(FUN_00bea9e0(DAT_00e0473c),1.0f);
                DAT_01076c98=DAT_01090bb0;
                handled=true;
                break;
            }
            }
        }
        switch(event) {
        case 13:
            FUN_0061e7d0(0x24);FUN_0061b370(1,0,1);handled=true;break;
        case 14:
            FUN_0061e7d0(0x24);Interface_SetStatsMenuVisible(1,0);handled=true;break;
        case 9:
            if (mode==29) {
                MenuNode* pos=list->first;
                while (pos) {
                    MenuTile* tile=MenuList::GetNext(pos);
                    if (tile->FUN_00becf80(DAT_01076b98)) {
                        dispatch(22,tile);handled=true;break;
                    }
                }
            }
            break;
        case 15: case 16:
            if (mode==28 || mode==29) {FUN_0065ebf0(event==16,DAT_00db9220);handled=true;}
            break;
        case 3: case 4:
            mode+=(event==4)?-1:1;
            int newMode=mode;
            if (newMode>32) newMode=28;
            mode=newMode;
            if (newMode<28) newMode=32;
            mode=newMode;
            dispatch(newMode,0);handled=true;
            break;
        }
    }
    return handled;
}
}   // namespace f3m_0065fab0

// @f3 0x00645c40 (community match, verified in this file)
namespace f3m_00645c40 {

namespace Assign645c {
struct Dispatch {int unk00;void (__thiscall* destroy)(void*);};
struct Ref {
    Dispatch* table;long refs;
    void IncRefCount(){InterlockedIncrement(&refs);}
    void DecRefCount(){if(!InterlockedDecrement(&refs))table->destroy(this);}
};
struct Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    NiPointer<Ref> target;
    void FUN_00645c40(Ref*);
};
// pdb: VATSMenu::IsWellFormedMenu | VATSMenu.obj | fnv360_0822_debug, call_gap_sim, low
// pdb params: ai
void Owner::FUN_00645c40(Ref* value) {target=value;}
}
}   // namespace f3m_00645c40

// @f3 0x00643540 (community match, verified in this file)
#include <string.h>
#include <windows.h>
extern unsigned int DAT_010762a4;
extern const char DAT_00e04d1c[];
extern unsigned int DAT_00f63150;
namespace f3m_00643540 {

namespace m643540 {

struct Props {
    bool FUN_00becf80(int trait);
    void FUN_00bee190(int trait, float value, int update);
    const char* Tile_GetString(int trait);
};

struct Sound {
    unsigned int id;
    unsigned char valid;
    unsigned char unk05;
    unsigned short unk06;
    unsigned int state;
    Sound& operator=(const Sound& other) { id = other.id; valid = other.valid; state = other.state; return *this; }
    void FUN_00bd00f0(int a, int b);
    void FUN_00bd00c0(bool b);
};

struct AudioManager {
    Sound BSAudioManager_GetSoundHandleByName(const char* name, unsigned int flags);
};

AudioManager* __cdecl FUN_00bd6800();

struct Entry {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    char unk28;
    unsigned char flag29;
    short unk2a;
    Props* pProps;
    Props* pArgPos;
    bool FUN_00759d80() { return flag29 != 0; }
    void FUN_00617900();
};

// The time is read through a small inline wrapper around the GetTickCount import. Calling the import directly at the
// five sites gives the same instructions but keeps this in a register for the whole function and spills the first
// string length instead; the wrapper is a guess at the source that reproduces the original register assignment.
inline unsigned long GetTimeMS() { return GetTickCount(); }

struct Menu {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Entry* entries[46];
    int unkE0_0, unkE0_1, unkE0_2, unkE0_3, unkE0_4, unkE0_5, unkE0_6, unkE0_7, unkE0_8, unkE0_9, unkE0_10;
    int unk10C_0, unk10C_1, unk10C_2, unk10C_3, unk10C_4, unk10C_5, unk10C_6, unk10C_7;
    Sound sounds[5];
    int unk168;
    void HackingMenu_UpdateScrollingCursor(Entry* entry);
    void FUN_00642e60();
    void FUN_00643540();
};

// The original has no exception state around the static initializer below, so the compiler knew this rounding
// helper cannot throw (its body is not part of this pack).
float __cdecl FUN_0047ca30(float a, float b) throw();

// pdb: HackingMenu::DoIntro | HackingMenu.obj | fnv360_0822_retail, call_seq, medium
void Menu::FUN_00643540()
{
    int i;
    for (i = 0; i < 13; i++)
    {
        if (entries[i] && !entries[i]->FUN_00759d80())
        {
            if (entries[i]->pArgPos)
            {
                if (!entries[i]->pArgPos->FUN_00becf80(0xfa3))
                {
                    entries[i]->pArgPos->FUN_00bee190(0xfa3, 1.0f, 1);
                    DAT_010762a4 = GetTimeMS() + 1000;
                }
                if (GetTimeMS() > DAT_010762a4)
                {
                    unsigned int start = strlen(entries[i]->pProps->Tile_GetString(0xfc4));
                    entries[i]->FUN_00617900();
                    unsigned int end = strlen(entries[i]->pProps->Tile_GetString(0xfc4));
                    for (unsigned int j = 0; j < end - start; j++)
                    {
                        static int s_iTypeTime = (int)(DAT_00f63150 > 1 ? FUN_0047ca30((float)(1000.0 / (float)DAT_00f63150), 1.0f) : 1000.0f);
                        unsigned int delay = s_iTypeTime * j / (end - start);
                        FUN_00bd6800()->BSAudioManager_GetSoundHandleByName(DAT_00e04d1c, 0x121).FUN_00bd00f0(delay, 0);
                    }
                    if (entries[i]->flag29)
                    {
                        sounds[4].FUN_00bd00c0(false);
                        DAT_010762a4 = GetTimeMS() + 500;
                    }
                }
            }
            else if (GetTimeMS() > DAT_010762a4)
            {
                entries[i]->FUN_00617900();
                sounds[3].FUN_00bd00c0(false);
            }
            HackingMenu_UpdateScrollingCursor(entries[i]);
            break;
        }
    }
    if (i == 13 && GetTimeMS() > DAT_010762a4)
        FUN_00642e60();
}

}
}   // namespace f3m_00643540
