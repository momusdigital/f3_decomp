// src/f3staging/f3blk_00640000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006477e0 (community match, verified in this file)
namespace f3m_006477e0 {
struct Tile6 {
    void FUN_00bee190(void* trait, float value, int update);
};

struct Holder6 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    Tile6* tiles[58];
    void FUN_00646c00();
};

extern Holder6* DAT_010762b4;

// pdb: HUDMainMenu::ResetHUDOpacity | HUDMainMenu.obj | fnv360_0822_debug, caller, medium
// pdb params: afHUDOpacity
void __cdecl FUN_006477e0(float value)
{
    if (!DAT_010762b4) return;
    DAT_010762b4->FUN_00646c00();
    for (int i = 0; i < 58; i++) {
        switch (i - 14) {
        case 0: case 1: case 2: case 3: case 4: case 5:
        case 9: case 10: case 11: case 12:
        case 29: case 35:
        case 37: case 38: case 39: case 40: case 41: case 42: case 43:
            continue;
        }
        float t = value * 255.0;
        DAT_010762b4->tiles[i]->FUN_00bee190((void*)0xfa9, t, 1);
    }
}
}   // namespace f3m_006477e0

// @f3 0x00654e20 (community match, verified in this file)
namespace f3m_00654e20 {
namespace Task1394 {
struct LevelGamepadTile
{
    LevelGamepadTile* FUN_00bed3c0(int id);
    bool FUN_00becf80(int trait);
    void FUN_00bed970(int trait);
};

struct LevelGamepadList
{
    virtual void vfunc0();
    virtual LevelGamepadTile* GetSelectedTile();
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
};

class LevelGamepadView
{
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void HandleClick(int id, LevelGamepadTile* tile);
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual bool FUN_00654e20(int code, float val);

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
    LevelGamepadTile* tile4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    LevelGamepadList list60;
    LevelGamepadList list90;
};

// @fnv 0x00785ed0
// pdb: LevelUpMenu::DoGamepad | LevelUpMenu.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiButton, afValue
bool LevelGamepadView::FUN_00654e20(int aiButtonCode, float afValue)
{
    bool bHandled = false;
    switch (aiButtonCode)
    {
    case 4:
        if (this->unk28 == 0 && this->list60.GetSelectedTile())
        {
            LevelGamepadTile* pTile1 = this->list60.GetSelectedTile()->FUN_00bed3c0(12);
            if (pTile1->FUN_00becf80(0xfa3))
            {
                pTile1->FUN_00bed970(0xfcb);
                this->HandleClick(12, pTile1);
            }
            bHandled = true;
        }
        break;
    case 3:
        if (this->unk28 == 0 && this->list60.GetSelectedTile())
        {
            LevelGamepadTile* pTile2 = this->list60.GetSelectedTile()->FUN_00bed3c0(13);
            if (pTile2->FUN_00becf80(0xfa3))
            {
                pTile2->FUN_00bed970(0xfcb);
                this->HandleClick(13, pTile2);
            }
            bHandled = true;
        }
        break;
    case 9:
        if (this->unk28 == 1 && this->list90.GetSelectedTile())
        {
            this->list90.GetSelectedTile()->FUN_00bed970(0xfcb);
            this->HandleClick(11, this->list90.GetSelectedTile());
            bHandled = true;
        }
        else if (this->unk28 == 0)
        {
            bHandled = this->FUN_00654e20(3, 1.0f);
        }
        break;
    case 10:
        if (this->unk28 == 1)
        {
            this->tile4C->FUN_00bed970(0xfcb);
            this->HandleClick(8, 0);
            bHandled = true;
        }
        else if (this->unk28 == 0)
        {
            bHandled = this->FUN_00654e20(4, 1.0f);
        }
        break;
    }
    return bHandled;
}

}
}   // namespace f3m_00654e20
