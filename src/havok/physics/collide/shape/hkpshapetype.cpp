#include "f3_common.h"
// src/havok/physics/collide/shape/hkpshapetype.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/hkpshapetype.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkpCollisionDispatcher
{
    void FUN_00cfbf60(int, int);
};

// @f3 0x009d45d0 (community match, verified in this file)
// pdb: hkRegisterAlternateShapeTypes | hkpShapeType.obj | fnv360_0822_retail, objrun_prop + bridge(call_gap|objrun_prop) + skyrim(call_gap_sim), high
void hkRegisterAlternateShapeTypes(hkpCollisionDispatcher* dispatcher)
{
    dispatcher->FUN_00cfbf60(2, 1);
    dispatcher->FUN_00cfbf60(4, 1);
    dispatcher->FUN_00cfbf60(5, 1);
    dispatcher->FUN_00cfbf60(6, 1);
    dispatcher->FUN_00cfbf60(3, 1);
    dispatcher->FUN_00cfbf60(7, 1);
    dispatcher->FUN_00cfbf60(0xc, 1);
    dispatcher->FUN_00cfbf60(0xd, 1);
    dispatcher->FUN_00cfbf60(0x13, 1);
    dispatcher->FUN_00cfbf60(0x16, 8);
    dispatcher->FUN_00cfbf60(0xa, 8);
    dispatcher->FUN_00cfbf60(0xf, 8);
    dispatcher->FUN_00cfbf60(0x1e, 8);
    dispatcher->FUN_00cfbf60(0x1f, 8);
    dispatcher->FUN_00cfbf60(0xb, 9);
    dispatcher->FUN_00cfbf60(1, 0x19);
    dispatcher->FUN_00cfbf60(0x1b, 0x18);
    dispatcher->FUN_00cfbf60(0xe, 0x18);
}
