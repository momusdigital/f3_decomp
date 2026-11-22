#include "f3_common.h"
// src/fallout/ai/movement/detailedactorpathhandler_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/movement/detailedactorpathhandler.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "detailedactorpathhandler_decls.h"

extern char DAT_01048858[], DAT_010c6084[], DAT_010c6078[], DAT_01029400[], DAT_010925bc[], DAT_010c606c[],
    DAT_010c6064[], DAT_010c605c[];
struct S
{
    const char* bhkRigidBodyCinfo_GetQualityTypeString();
};
// @f3 0x008fec70 (community match, verified in this file)
extern char DAT_00de30f8[], DAT_00e3480c[], DAT_00e34800[], DAT_00dc85c4[];
extern char DAT_00e1e954[], DAT_00e347f4[], DAT_00e347ec[], DAT_00e347e4[];
struct Layout432 {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned char unkD0, unkD1, unkD2;
    signed char kind;
};
// pdb: bhkRigidBodyCinfo::GetQualityTypeString | bhkRigidBody.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
const char* S::bhkRigidBodyCinfo_GetQualityTypeString() {
    int kind = reinterpret_cast<Layout432*>(this)->kind;
    const char* result = 0;
    switch (kind) {
    case 0: result = DAT_00de30f8; break;
    case 1: result = DAT_00e3480c; break;
    case 2: result = DAT_00e34800; break;
    case 3: result = DAT_00dc85c4; break;
    case 4: result = DAT_00e1e954; break;
    case 5: result = DAT_00e347f4; break;
    case 6: result = DAT_00e347ec; break;
    case 7: result = DAT_00e347e4; break;
    }
    return result;
}

