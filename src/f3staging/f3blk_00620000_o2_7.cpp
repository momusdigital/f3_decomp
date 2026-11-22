#include <windows.h>
#include <windows.h>
#include <string.h>
// src/f3staging/f3blk_00620000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00632eb0 (community match, verified in this file)
namespace f3m_00632eb0 {
namespace Nav1940 {extern char str_00e03f9c[],str_00e04758[];int __cdecl FUN_00bea9e0(const char*);int __cdecl FUN_00becd70(const char*,int);
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
    bool FUN_006321b0();
    NavigationTile* FUN_00632eb0(unsigned int action);
};
float __cdecl FUN_0047ca30(float value, float step);

// @fnv 0x007214b0
// pdb: ListBox<ItemChange *>::GetHighlightTarget | BarterMenu.obj | fnv360_0822_retail, vtable, medium
// pdb params: aeButton
NavigationTile* NavigationList::FUN_00632eb0(unsigned int action)
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
    if (FUN_006321b0() && delta && count)
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

}
}   // namespace f3m_00632eb0
