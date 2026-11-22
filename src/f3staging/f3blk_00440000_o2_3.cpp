#include <stdlib.h>
#include <string.h>
// src/f3staging/f3blk_00440000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0044cf60 (community match, verified in this file)
namespace f3m_0044cf60 {
struct Obj44cf60
{
    int unk000;
    unsigned char unk004;
    unsigned char unk005;
    unsigned char unk006;
    unsigned char unk007;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
};

// pdb: BGSEquipType::GetEquipType | BGSEquipType.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: BGSEquipType::GetEquipSlotForForm)
// pdb params: apForm
int FUN_0044cf60(Obj44cf60* p)
{
    int r = -1;
    if (p != 0) {
        switch (p->unk004) {
        case 0x28: r = p->unk0C8; break;
        case 0x18: r = p->unk158; break;
        case 0x1a: r = p->unk150; break;
        case 0x2f: r = p->unk0A0; break;
        case 0x1d: r = p->unk090; break;
        }
    }
    return r;
}
}   // namespace f3m_0044cf60
