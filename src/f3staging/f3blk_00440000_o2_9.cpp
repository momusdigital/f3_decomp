#include <stdlib.h>
#include <string.h>
// src/f3staging/f3blk_00440000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00450be0 (community match, verified in this file)
namespace f3m_00450be0 {
struct FilterForm {
    unsigned unk00;
    unsigned char type;
};
extern int __cdecl FUN_0044cf60(const FilterForm*);

class FormFilter {
public:
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned flags;
    unsigned char FUN_00450be0(const FilterForm* form);
};

// pdb: TESAIForm::SellBuysItem | TESAIForm.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject
unsigned char FormFilter::FUN_00450be0(const FilterForm* form)
{
    unsigned char result = 0;
    switch (form->type) {
    case 40:
    case 41:
        result = (unsigned char)flags & 1;
        break;
    case 24:
        result = ((unsigned char)flags >> 1) & 1;
        break;
    case 47:
        switch (FUN_0044cf60(form)) {
        case 10:
            result = ((unsigned char)flags >> 5) & 1;
            break;
        case 11:
            result = ((unsigned char)flags >> 6) & 1;
            break;
        case 12:
            result = ((unsigned char)flags >> 4) & 1;
            break;
        case 13:
            result = ((unsigned char)flags >> 2) & 1;
            break;
        }
        break;
    case 25:
        result = ((unsigned char)flags >> 3) & 1;
        break;
    case 31:
    case 50:
        result = (unsigned char)(flags >> 10) & 1;
        break;
    }
    return result;
}

}   // namespace f3m_00450be0
