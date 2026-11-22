#include <windows.h>
#include <windows.h>
#include <string.h>
// src/f3staging/f3blk_00620000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0063ade0 (community match, verified in this file)
namespace f3m_0063ade0 {
namespace n63ade0 {
void __cdecl FUN_0063a400();
struct Menu75d250Pane
{
    virtual void vf00();
    virtual int IsBusy();
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
    unsigned FUN_00629ee0();
    void FUN_00632250();
    void FUN_00633140(int abActive);
};

struct Menu75d250
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void SetState(int aiState, int aiUnk);
    virtual void Notify(int aiID, int aiUnk);
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    Menu75d250Pane m_fMinimumU;
    Menu75d250Pane m_fMaximumU;
    Menu75d250Pane* m_pActive;
    bool FUN_0063ade0(int aiAction, int aiUnused);
};

bool __cdecl FUN_0061c490(int aiID);

// Handles menu actions 13/14 by switching between the two panes and actions 3/4 by resetting the active pane and setting state, returning whether handled.
// @fnv 0x0075d250
// pdb: ContainerMenu::DoGamepad | ContainerMenu.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiButton, afValue
bool Menu75d250::FUN_0063ade0(int aiAction, int aiUnused)
{
    bool bHandled = false;
    if (FUN_0061c490(0x3f0))
    {
        switch (aiAction)
        {
        case 13:
            if (!m_fMinimumU.IsBusy() && m_fMinimumU.FUN_00629ee0() > 0)
            {
                m_fMaximumU.FUN_00632250();
                Notify(0x10, 0);
                m_fMinimumU.FUN_00633140(1);
                bHandled = true;
            }
            break;
        case 14:
            if (!m_fMaximumU.IsBusy() && m_fMaximumU.FUN_00629ee0() > 0)
            {
                m_fMinimumU.FUN_00632250();
                Notify(0x11, 0);
                m_fMaximumU.FUN_00633140(1);
                bHandled = true;
            }
            break;
        case 10:
            FUN_0063a400();
            bHandled=true;
            break;
        case 3:
        case 4:
            if (unk6C != 4)
            {
                if (m_pActive == &m_fMinimumU)
                {
                    m_fMinimumU.FUN_00632250();
                    SetState(aiAction == 4 ? 0 : 2, 0);
                    m_fMinimumU.FUN_00633140(0);
                }
                else
                {
                    m_fMaximumU.FUN_00632250();
                    SetState(aiAction == 4 ? 5 : 7, 0);
                    m_fMaximumU.FUN_00633140(0);
                }
                bHandled = true;
            }
            break;
        }
    }
    return bHandled;
}
}
}   // namespace f3m_0063ade0

// @f3 0x00637340 (community match, verified in this file)
extern const char DAT_00e03f9c[],DAT_00e04758[];
namespace f3m_00637340 {
namespace Task1941 {
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
    bool FUN_00637240();
    NavigationTile* FUN_00637340(unsigned int action);
};
float __cdecl FUN_0047ca30(float value, float step);
int FUN_00bea9e0(const char*);int FUN_00becd70(const char*,int);
// @fnv 0x007214b0
// pdb: ListBox<TERMINAL_MENU_ITEM *>::GetHighlightTarget | ComputersMenu.obj | fnv360_0822_retail, vtable, medium
// pdb params: aeButton
NavigationTile* NavigationList::FUN_00637340(unsigned int action)
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
    if (FUN_00637240() && delta && count)
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
}   // namespace f3m_00637340
