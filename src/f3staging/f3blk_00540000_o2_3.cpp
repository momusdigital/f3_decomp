// src/f3staging/f3blk_00540000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00551b90 (community match, verified in this file)
namespace f3m_00551b90 {
namespace f3m_00551b90 {
struct Str {
    char* data;
    unsigned short len;
    unsigned short max;
    Str() : data(0), len(0), max(0) {}
    ~Str();
};
struct FUN_0045bca0 {
    int unk00, unk04, unk08;
    FUN_0045bca0();
};
struct Entry {
    Str a;
    Str b;
    FUN_0045bca0 c;
    Entry();
};
// pdb: RANK_DATA::RANK_DATA | TESFaction.obj | fnv360_0721_retail, objrun_prop, low, conflict (skyrim: RaceTintingTemplateEntry::RaceTintingTemplateEntry)
Entry::Entry() {}
}
}   // namespace f3m_00551b90

// @f3 0x0054ab80 (community match, verified in this file)
namespace f3m_0054ab80 {
namespace f3m_0054ab80 {
struct Stats30 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    void TESActorBaseData_SetSpeedMult(int value);
    void TESActorBaseData_SetKarma(float value);
};
struct Stats90 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20;
    void TESAIForm_SetAggression(int value, int flag);
    void TESAIForm_SetConfidence(int value, int flag);
    void TESAIForm_SetEnergy(int value, int flag);
    void FUN_00450f40(int value, int flag);
    void TESAIForm_SetMood(int value);
};
struct StatsB8 {
    int unk00;
    void FUN_004516e0(int slot, int value, int flag);
};
struct Owner {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    Stats30 stats30;
    Stats90 stats90;
    int valueB4;
    StatsB8 statsB8;
    void FUN_0054ab80(int selector, int value);
};
// pdb: TESActorBase::SetActorValue | TESActorBase.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiWhich, aiValue
void Owner::FUN_0054ab80(int selector, int value)
{
    switch (selector) {
    case 5: statsB8.FUN_004516e0(5, value, 1); break;
    case 6: statsB8.FUN_004516e0(6, value, 1); break;
    case 7: statsB8.FUN_004516e0(7, value, 1); break;
    case 8: statsB8.FUN_004516e0(8, value, 1); break;
    case 9: statsB8.FUN_004516e0(9, value, 1); break;
    case 10: statsB8.FUN_004516e0(10, value, 1); break;
    case 11: statsB8.FUN_004516e0(11, value, 1); break;
    case 16: valueB4 = value; break;
    case 0: stats90.TESAIForm_SetAggression(value, 1); break;
    case 1: stats90.TESAIForm_SetConfidence(value, 1); break;
    case 2: stats90.TESAIForm_SetEnergy(value, 1); break;
    case 3: stats90.FUN_00450f40(value, 1); break;
    case 4: stats90.TESAIForm_SetMood(value); break;
    case 21: stats30.TESActorBaseData_SetSpeedMult(value); break;
    case 23: stats30.TESActorBaseData_SetKarma((float)value); break;
    }
}
}
}   // namespace f3m_0054ab80
