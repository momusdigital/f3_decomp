// src/f3staging/f3blk_00540000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00552e30 (community match, verified in this file)
#include <string.h>
namespace f3m_00552e30 {
extern "C" void* __cdecl _alloca(unsigned int size);
namespace Small552e30 {
struct String {
    char* value;
    unsigned short length;
    unsigned short capacity;
    bool FUN_004019c0(const char* value, unsigned int length);
    int CompareNoCase(const char* other) const {
        if (other) {
            if (value)
                return _stricmp(value, other);
        } else {
            if (!value)
                return 0;
        }
        return other ? -1 : 1;
    }
};
struct Owner {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    String name;
    bool FUN_00552e30(const char* value);
};
// pdb: TESIdleForm::SetFormEditorID | TESIdleForm.obj | fnv360_0822_retail, vtable, medium
// pdb params: apEditorID
bool Owner::FUN_00552e30(const char* value) {
    unsigned int size = static_cast<unsigned int>(strlen(value)) + 1;
    char* copy = static_cast<char*>(_alloca(size));
    strcpy_s(copy, size, value);
    if (name.CompareNoCase(copy) == 0)
        return false;
    name.FUN_004019c0(copy, 0);
    return true;
}
}
}   // namespace f3m_00552e30
