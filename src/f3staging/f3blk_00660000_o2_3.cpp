#include <string.h>
// src/f3staging/f3blk_00660000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0067eac0 (community match, verified in this file)
namespace f3m_0067eac0 {
namespace f3m_0067eac0 {

struct Tile {
    void FUN_00bee190(unsigned int property, float value, int update);
};

struct Holder {
    Tile* tile;             // +0x00
    int unk04;              // +0x04
    unsigned char flag08;   // +0x08
};

struct Menu {
    int unk00;                              // +0x00
    BSSimpleList<Holder*> list;             // +0x04 (item +4, next +8)
    int unk0c;                              // +0x0c
    int unk10;                              // +0x10
    int unk14;                              // +0x14
    int unk18;                              // +0x18
    unsigned short count1c;                 // +0x1c
    unsigned short unk1e;                   // +0x1e
    float unk20;                            // +0x20

    void FUN_0067eac0();
    void FUN_0065f300(Tile* tile);
    void FUN_0067dd00();
    void FUN_0067ac00();
};

// pdb: ListBox<StartMenu::Option *>::Synchronize | StartMenu.obj | fnv360_0822_retail, call_seq, medium
void Menu::FUN_0067eac0()
{
    unk20 = 0.0f;
    count1c = 0;

    BSSimpleList<Holder*>* p = &list;
    while (p && p->m_item) {
        if (!p->m_item->flag08) {
            p->m_item->tile->FUN_00bee190(0xfac, (float)count1c++, 1);
            FUN_0065f300(p->m_item->tile);
        }
        p = p->m_pkNext;
    }

    FUN_0067dd00();
    FUN_0067ac00();
}

}
}   // namespace f3m_0067eac0
