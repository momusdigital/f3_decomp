#include <windows.h>
#include <windows.h>
#include <string.h>
// src/f3staging/f3blk_00620000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00635750 (community match, verified in this file)
namespace f3m_00635750 {
namespace task1716 {
struct TileItem
{
    TileItem* FUN_00bed3c0(int);
    bool FUN_00becf80(int);
    void FUN_00bed970(int);
};

struct SubList
{
    virtual void v0();
    virtual TileItem* Selected();
};

struct CharGenInputMenu
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void HandleClick(int, TileItem*);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual bool v14(int, float);

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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    SubList list;

    bool FUN_00635750(int a1, float amount);
};

// @fnv 0x00754150
// pdb: CharGenMenu::DoGamepad | CharGenMenu.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiButton, afValue
bool CharGenInputMenu::FUN_00635750(int a1, float amount)
{
    bool result = false;

    switch (a1)
    {
    case 3:
    case 4:
        if (this->unk28 == 0 && this->list.Selected())
        {
            int var_8 = (a1 != 4) + 10;
            TileItem* var_c = this->list.Selected()->FUN_00bed3c0(var_8);
            if (var_c && var_c->FUN_00becf80(0xfa3))
            {
                var_c->FUN_00bed970(0xfcb);
                this->HandleClick(var_8, var_c);
            }
            result = true;
        }
        break;

    case 9:
        if (this->unk28 == 1 && this->list.Selected())
        {
            this->HandleClick(9, this->list.Selected());
            result = true;
        }
        else if (this->unk28 == 0)
        {
            result = this->v14(3, 1.0f);
        }
        break;

    case 10:
        if (this->unk28 == 0)
        {
            result = this->v14(4, 1.0f);
        }
        break;
    }

    return result;
}

}
}   // namespace f3m_00635750

// @f3 0x0062ec80 (community match, verified in this file)
extern const char DAT_00e03f9c[],DAT_00e04758[];
namespace f3m_0062ec80 {
namespace Task1947 {
struct NavigationTile
{
    float FUN_00becf40(int trait);
    bool FUN_00becf80(int trait);
};
struct NavigationItem
{
    NavigationTile* tile;
};
struct NavigationNode
{
    NavigationItem* item;
    NavigationNode* next;
    NavigationItem** FUN_006815c0(){return &item;}
    NavigationNode* FUN_00726070(){return next;}
};
struct NavigationBase
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual NavigationTile* GetAt(int current, bool select);
};
struct NavigationList : NavigationBase, NavigationNode
{
    NavigationTile* container;
    NavigationTile* selected;
    NavigationTile* scrollbar;
    const char* templateName;
    unsigned short count;
    bool FUN_0062ebe0();
    NavigationTile* FUN_0062ec80(unsigned int action);
};
float __cdecl FUN_0047ca30(float value, float step);
int FUN_00bea9e0(const char*);int FUN_00becd70(const char*,int);
// @fnv 0x007214b0
// pdb: ListBox<enum MiscStatManager::MiscStatID>::GetHighlightTarget | MenuManager.obj | fnv360_0822_retail, vtable, medium
// pdb params: aeButton
NavigationTile* NavigationList::FUN_0062ec80(unsigned int action)
{
    NavigationTile* result = 0;
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
                          (float)((double)-container->FUN_00becf40(0xfb0) / container->FUN_00becf40(FUN_00bea9e0(DAT_00e03f9c))), 1.0f)
                    : 0;
        break;
    case 16:
        delta = container
                    ? (int)FUN_0047ca30(
                          (float)((double)container->FUN_00becf40(0xfb0) / container->FUN_00becf40(FUN_00bea9e0(DAT_00e03f9c))), 1.0f)
                    : 0;
        break;
    }
    if (FUN_0062ebe0() && delta && count)
    {
        int last = count - 1;
        int current;
        int index;
        NavigationNode* node;
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
            if (result && !result->FUN_00becf80(FUN_00becd70(DAT_00e04758, -1)))
            {
                result = 0;
                if (delta > 0 && ++current > last)
                {
                    current = last - 1;
                    while ((!result || !result->FUN_00becf80(FUN_00becd70(DAT_00e04758, -1))) && current >= 0)
                    {
                        result = GetAt(current--, false);
                    }
                    break;
                }
                else if (delta < 0 && --current < 0)
                {
                    current = 1;
                    while ((!result || !result->FUN_00becf80(FUN_00becd70(DAT_00e04758, -1))) && current <= last)
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

}
}   // namespace f3m_0062ec80
