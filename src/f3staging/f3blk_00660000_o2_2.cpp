#include <stdio.h>
#include <string.h>
#include <string.h>
// src/f3staging/f3blk_00660000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0067c070 (community match, verified in this file)
extern char str_00e03f9c[], str_00e04758[];
namespace f3m_0067c070 {
int __cdecl FUN_00bea9e0(const char*);
int __cdecl FUN_00becd70(const char*, int);
struct Task1939Tile
{
    float FUN_00becf40(int trait);
    bool FUN_00becf80(int trait);
};
struct Task1939Item
{
    Task1939Tile* tile;
};
struct Task1939Node
{
    Task1939Item* item;
    Task1939Node* next;
    Task1939Item** FUN_006815c0() { return &item; }
    Task1939Node* FUN_00726070() { return next; }
};
struct Task1939Base
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual Task1939Tile* GetAt(int current, bool select);
};
struct Task1939List : Task1939Base, Task1939Node
{
    Task1939Tile* container;
    Task1939Tile* selected;
    Task1939Tile* scrollbar;
    const char* templateName;
    unsigned short count;
    bool FUN_0067a880();
    Task1939Tile* FUN_0067c070(unsigned int action);
};
float __cdecl FUN_0047ca30(float value, float step);
// @fnv 0x007214b0
// pdb: ListBox<StartMenu::Option *>::GetHighlightTarget | StartMenu.obj | fnv360_0822_retail, vtable, medium
// pdb params: aeButton
Task1939Tile* Task1939List::FUN_0067c070(unsigned int action)
{
    Task1939Tile* result = 0;
    int delta = 0;
    switch (action)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta = container
                    ? (int)FUN_0047ca30(
                          -container->FUN_00becf40(0xfb0) / container->FUN_00becf40(FUN_00bea9e0(str_00e03f9c)), 1.0f)
                    : 0;
        break;
    case 16:
        delta = container
                    ? (int)FUN_0047ca30(
                          container->FUN_00becf40(0xfb0) / container->FUN_00becf40(FUN_00bea9e0(str_00e03f9c)), 1.0f)
                    : 0;
        break;
    }
    if (FUN_0067a880() && delta && count)
    {
        int last = count - 1;
        int current;
        int index;
        Task1939Node* node;
        if (selected)
        {
            index = (int)selected->FUN_00becf40(0xfac);
            if ((current = index + delta) < 0)
                current = 0;
            else if (current > last)
                current = last;
        }
        else
        {
            if (delta > 0)
                current = 0;
            else
                current = last;
        }
        while (true)
        {
            for (node = this; !result && node && *node->FUN_006815c0(); node = node->FUN_00726070())
            {
                if ((*node->FUN_006815c0())->tile->FUN_00becf40(0xfac) == current)
                    result = (*node->FUN_006815c0())->tile;
            }
            if (result && !result->FUN_00becf80(FUN_00becd70(str_00e04758, -1)))
            {
                result = 0;
                if (delta > 0 && ++current > last)
                {
                    current = last - 1;
                    while ((!result || !result->FUN_00becf80(FUN_00becd70(str_00e04758, -1))) && current >= 0)
                    {
                        result = GetAt(current--, false);
                    }
                    break;
                }
                else if (delta < 0 && --current < 0)
                {
                    current = 1;
                    while ((!result || !result->FUN_00becf80(FUN_00becd70(str_00e04758, -1))) && current <= last)
                    {
                        result = GetAt(current++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return result != selected ? result : 0;
}
}   // namespace f3m_0067c070

// @f3 0x00660dc0 (community match, verified in this file)
extern int DAT_00e03f9c;
extern int DAT_00e04758;
namespace f3m_00660dc0 {
namespace task1938 {
struct Obj {
    double FUN_00becf40(int id);
    bool FUN_00becf80(int id);
};
struct Item { Obj* obj; };
struct Node { Item* item; Node* next; };
int __cdecl FUN_00bea9e0(int*);
int __cdecl FUN_00becd70(int*, int);
float __cdecl FUN_0047ca30(float, float);
int __cdecl FUN_00c00690(float);

struct FUN_00660dc0_cls {
    Node list;
    Obj* unk0c;
    Obj* unk10;
    int unk14;
    int unk18;
    unsigned short unk1c;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Obj* v5(int, int);
    bool FUN_00660d20();
    Obj* FUN_00660dc0(int code);
};

// pdb: ListBox<BGSNote *>::GetHighlightTarget | MapMenu.obj | fnv360_0822_retail, vtable, medium
// pdb params: aeButton
Obj* FUN_00660dc0_cls::FUN_00660dc0(int code)
{
    Obj* found = 0;
    int v = 0;
    switch (code) {
    case 2: v = 1; break;
    case 1: v = -1; break;
    case 15:
        if (unk0c) {
            double num = -unk0c->FUN_00becf40(0xfb0);
            v = (int)FUN_0047ca30((float)(num / unk0c->FUN_00becf40(FUN_00bea9e0(&DAT_00e03f9c))), 1.0f);
        } else {
            v = 0;
        }
        break;
    case 16:
        if (unk0c) {
            double num = unk0c->FUN_00becf40(0xfb0);
            v = (int)FUN_0047ca30((float)(num / unk0c->FUN_00becf40(FUN_00bea9e0(&DAT_00e03f9c))), 1.0f);
        } else {
            v = 0;
        }
        break;
    }
    if (FUN_00660d20() && v != 0 && unk1c != 0) {
        int last = unk1c - 1;
        int cur;
        if (unk10) {
            cur = (int)unk10->FUN_00becf40(0xfac) + v;
            if (cur < 0) cur = 0;
            else if (cur > last) cur = last;
        } else {
            cur = (v > 0 ? 0 : -1) & last;
        }
        int i;
        Node* n;
    top:
        n = &list;
    scan:
        if (n && n->item) {
            if (n->item->obj->FUN_00becf40(0xfac) == cur)
                found = n->item->obj;
            n = n->next;
            if (!found) goto scan;
        } else if (!found) goto end;
    check:
        if (found->FUN_00becf80(FUN_00becd70(&DAT_00e04758, -1))) goto end;
        found = 0;
        if (v > 0) {
            cur++;
            if (cur > last) goto desc;
        }
        if (v < 0) {
            cur--;
            if (cur >= 0) goto top;
            i = 1;
            for (;;) {
                if (found && found->FUN_00becf80(FUN_00becd70(&DAT_00e04758, -1))) goto end;
                if (i > last) goto end;
                found = v5(i, 0);
                i++;
            }
        }
        goto top;
    desc:
        i = last - 1;
        for (;;) {
            if (found && found->FUN_00becf80(FUN_00becd70(&DAT_00e04758, -1))) goto end;
            if (i < 0) goto end;
            found = v5(i, 0);
            i--;
        }
    }
  end:
    return found != unk10 ? found : 0;
}
}

}   // namespace f3m_00660dc0

// @f3 0x00674aa0 (community match, verified in this file)
namespace f3m_00674aa0 {



namespace NativeSleepWait {

struct SwTile;

struct SwMenu {
    virtual ~SwMenu();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual int GetID();

    SwTile* unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    SwTile* slots[6];
    int unk40;
    unsigned char unk44;
    bool m_bSleep;

    void FUN_00bfc570(SwTile* tile, bool propagate);
    void FUN_00674820();
    void FUN_00bfd010(int mode);
};

struct SwTile {
    SwTile* FUN_00bf37b0(const char* path);
    SwMenu* FUN_00beab90();
    float FUN_00becf40(int id);
    void FUN_00bee190(int id, float value, bool propagate);
    SwTile* Tile_GetChildByName(const char* name);
    void FUN_00bf11a0(int id, const char* text, bool propagate);
};

struct SwIface {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98;
    SwTile* unk9C;
};

struct SwSound {
    int id;
    bool flag;
    int m8;
    SwSound() : id(-1), flag(false), m8(0) {}
    bool FUN_00bd00c0();
};

struct SwAudio {
    SwSound FUN_00bcfcd0(const char* name, int flags, int arg);
};

extern SwIface* DAT_01075b24;
extern SwMenu* DAT_01076fd8;
extern SwAudio* DAT_011790c8;
extern const char* DAT_00f64668;
extern const char* DAT_00f6465c;
extern const char* DAT_00f64680;
extern const char* DAT_00f6468c;
extern const char* DAT_00f62cac;
extern float DAT_01073294;
extern const char DAT_00e07730[], DAT_00dc552c[], DAT_00e06fe8[], DAT_00e07728[], DAT_00e07718[];
extern const double DAT_00e04a70;
extern const float DAT_00e04a78;
extern const double DAT_00dbeb78;

SwMenu* __cdecl Tile_GetMenuByClass(int id);
float __cdecl Tile_GetMaximumDepth();
int __cdecl FUN_00c048fb(int c);


// pdb: SleepWaitMenu::Create | SleepWaitMenu.obj | fnv360_0822_retail, ustr, medium
// pdb params: abSleep
SwTile* __cdecl FUN_00674aa0(bool sleep)
{
    SwIface* interfaceState = DAT_01075b24;
    if (SwMenu* existing = Tile_GetMenuByClass(0x3f4))
        delete existing;

    SwTile* loaded = interfaceState->unk9C->FUN_00bf37b0(DAT_00e07730);
    DAT_01076fd8 = loaded->FUN_00beab90();
    if (DAT_01076fd8 && DAT_01076fd8->GetID() == 0x3f4) {
        DAT_01076fd8->FUN_00bfc570(loaded, false);
        int i = 0;
        SwTile** slot = DAT_01076fd8->slots;
        for (; i < 6; ++i, ++slot) {
            if (!*slot)
                return 0;
        }

        DAT_011790c8->FUN_00bcfcd0(DAT_00dc552c, 0x121, 0).FUN_00bd00c0();
        if (loaded->FUN_00becf40(0xfa7) == 6006.0f ||
            loaded->FUN_00becf40(0xfa7) == DAT_00e04a70) {
            loaded->FUN_00bee190(0xfad, Tile_GetMaximumDepth(), true);
        }

        DAT_01076fd8->m_bSleep = sleep;
        char verb[260], caption[260];
        if (sleep)
            strcpy_s(verb, sizeof(verb), DAT_00f64668);
        else
            strcpy_s(verb, sizeof(verb), DAT_00f6465c);

        sprintf_s(caption, sizeof(caption), DAT_00e06fe8, DAT_00f64680, verb);
        DAT_01076fd8->slots[0]->FUN_00bf11a0(0xfc4, caption, true);
        verb[0] = static_cast<char>(FUN_00c048fb(verb[0]));
        DAT_01076fd8->slots[4]->FUN_00bf11a0(0xfc4, verb, true);

        sprintf_s(caption, sizeof(caption), DAT_00e07728, DAT_00f6468c);
        DAT_01076fd8->slots[2]->FUN_00bf11a0(0xfc4, caption, true);
        DAT_01076fd8->FUN_00674820();
        DAT_01076fd8->slots[5]->FUN_00bf11a0(0xfc4, DAT_00f62cac, true);

        SwTile* root = DAT_01076fd8->unk04;
        const float opacity = DAT_01073294 * DAT_00dbeb78;
        root->Tile_GetChildByName(DAT_00e07718)->FUN_00bee190(0xfa9, opacity, true);
        DAT_01076fd8->FUN_00bfd010(0);
        return loaded;
    } else if (DAT_01076fd8 && DAT_01076fd8->unk04) {
        delete DAT_01076fd8;
    }
    return 0;
}
}
}   // namespace f3m_00674aa0
