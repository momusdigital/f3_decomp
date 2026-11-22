// src/f3staging/f3blk_004e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004eb6f0 (community match, verified in this file)
namespace f3m_004eb6f0 {
struct RefNode4E7B;

struct BaseForm4E7B
{
    int unk00;
    unsigned char typeID;
};

struct RefForm4E7B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    BaseForm4E7B* baseForm;
};

RefForm4E7B* FUN_004e7b90(RefNode4E7B* start);

// pdb: GrenadeProjectile::ReportCollision | GrenadeProjectile.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: apTargetController, aContactPoint, aContactNormal
int FUN_004eb6f0(RefNode4E7B* node)
{
    int result = 0;
    if (node != 0)
    {
        RefForm4E7B* form = FUN_004e7b90(node);
        if (form != 0)
        {
            switch (form->baseForm->typeID)
            {
            case 0x15:
            case 0x1c:
            case 0x20:
            case 0x21:
                result = 1;
                break;
            case 0x1b:
            case 0x27:
                result = 2;
                break;
            case 0x2a:
            case 0x2b:
                result = 3;
                break;
            case 0x18:
            case 0x1a:
            case 0x28:
            case 0x29:
                result = 4;
                break;
            case 0x1d:
            case 0x1f:
            case 0x2e:
            case 0x32:
                result = 5;
                break;
            default:
                result = 6;
                break;
            }
        }
    }
    return result;
}
}   // namespace f3m_004eb6f0
