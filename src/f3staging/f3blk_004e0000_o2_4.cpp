// src/f3staging/f3blk_004e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004f1620 (community match, verified in this file)
extern char DAT_00f46078;
extern char DAT_00f4efe8;
extern char DAT_00f47aa8;
namespace f3m_004f1620 {

struct Tag4F {
    int unk00;
    unsigned char type;
};

struct Interface4F {
    void** table;
    Interface4F* Value() { return ((Interface4F* (__thiscall*)(Interface4F*))table[0])(this); }
    bool Matches(void* value) { return ((bool (__thiscall*)(Interface4F*,void*))table[15])(this,value); }
    unsigned char FUN_004eb8f0();
};

struct Owner4F {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Interface4F unk18;
    unsigned char FUN_004eb8f0();
    bool FUN_004f1620(Tag4F* tag);
};

extern bool __cdecl TESObjectCELL_IsFormTypeCellChild(unsigned char type);
extern Interface4F* __cdecl FUN_00c0050a(
    Tag4F* tag, int zero, const char* kind, const char* name, int flags);

// pdb: TESObjectREFR::SavesBefore | TESObjectREFR.obj | fnv360_0822_retail, vtable, medium
// pdb params: apForm
bool Owner4F::FUN_004f1620(Tag4F* tag)
{
    bool result = false;
    if (TESObjectCELL_IsFormTypeCellChild(tag->type)) {
        Interface4F* helper =
            FUN_00c0050a(tag, 0, &DAT_00f46078, &DAT_00f4efe8, 0);
        Interface4F* helperValue = helper->Value();
        if (helperValue == unk18.Value()) {
            switch (tag->type) {
            case 0x42:
            case 0x43:
                result = FUN_004eb8f0();
                break;
            case 0x3a:
            case 0x3b:
            case 0x3c:
            case 0x3d:
            case 0x3e:
            case 0x3f:
            case 0x40:
            {
            Interface4F* other =
                FUN_00c0050a(tag, 0, &DAT_00f46078, &DAT_00f47aa8, 0);
            if (FUN_004eb8f0()) {
                if (other && !other->FUN_004eb8f0()) {
                    result = true;
                    break;
                }
                break;
            }
            result = false;
            break;
            }
            default:
            break;
            }
        } else {
            result = unk18.Value()->Matches(helperValue);
        }
    } else {
        result = unk18.Value()->Matches(tag);
    }
    return result;
}
}   // namespace f3m_004f1620
