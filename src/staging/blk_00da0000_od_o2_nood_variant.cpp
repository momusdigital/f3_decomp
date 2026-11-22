#include "f3_common.h"
// src/staging/blk_00da0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00da0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00da0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

struct ScratchBlock
{
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
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
};

void __cdecl FUN_00da6fd0(ScratchBlock* block);

class ScratchOwner
{
  public:
    void AddEntry(ScratchBlock* block, int a, int b);
};

// @fnv 0x00da7020
// pdb: hkBvTreeAgent3::registerAgent3 | hkpBvTreeAgent3.obj | fnv360_0822_retail, objrun, medium
// pdb params: dispatcher
void __cdecl FUN_00da7020(ScratchOwner* owner)
{
    __declspec(align(16)) ScratchBlock s;
    s.unk30 = 0;
    s.unk31 = 0;
    s.unk32 = 0;
    s.unk18 = 0;
    s.unk1C = 0;
    s.unk20 = 0;
    s.unk24 = 0;
    s.unk28 = 0;
    FUN_00da6fd0(&s);
    owner->AddEntry(&s, -1, 9);
}

struct FinishingFlag
{
    int m_bFinishing;
};

struct S00da0780_Member
{
    S00da0780_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class __declspec(align(16)) S00da0780_Object
{
  public:
    S00da0780_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    S00da0780_Member m_kMember;
    int unk0C;
};

// @f3 0x00a068c0 (community match, verified in this file)
extern int DAT_00e81ac0;

struct Quad_00da0780
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct Block16_00da0780
{
    Quad_00da0780 unk00;
    Quad_00da0780 unk10;
    Quad_00da0780 unk20;
    Quad_00da0780 unk30;
};

struct FUN_009a1c00
{
    Block16_00da0780 unk00;
    Block16_00da0780 unk40;
    Block16_00da0780 unk80;
    Block16_00da0780 unkc0;
    FUN_009a1c00(FinishingFlag flag);
};

class __declspec(align(16)) Local_00da0780
{
public:
    void* m_pVtable;
    short unk04;
    short m_flags;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_009a1c00 m_kMember;

    Local_00da0780(FinishingFlag flag)
        : m_flags(1), m_kMember((m_pVtable = &DAT_00e81ac0, flag))
    {}
};

// pdb: getVtablehkpSerializedAgentNnEntry | hkpUtilitiesReflections.obj | tesv_win, objrun_prop, low
const void* __cdecl FUN_00da0780()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    Local_00da0780 kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}


namespace fnv_00da07d0 {
struct FinishingFlag
{
    int m_bFinishing;
};

struct S00da07d0_Member
{
    S00da07d0_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class __declspec(align(16)) S00da07d0_Object
{
  public:
    S00da07d0_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    S00da07d0_Member m_kMember;
    int unk68;
    int unk6C;
};

}  // namespace fnv_00da07d0

#include <xmmintrin.h>
__declspec(align(16)) struct FUN_00da7180_cls
{
    __m128 m_v00;
    __m128 m_v10;
    float m_f20;
    unsigned int m_i24;
    float m_f28;
    unsigned int m_i2C;
    unsigned int m_i30;

    FUN_00da7180_cls* FUN_00da7180(const FUN_00da7180_cls* src);
};

namespace fnv_00db7c40 {
struct FinishingFlag
{
    int m_bFinishing;
};

struct S00db7c40_Member
{
    S00db7c40_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class __declspec(align(16)) S00db7c40_Object
{
  public:
    S00db7c40_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
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
    S00db7c40_Member m_kMember;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

}  // namespace fnv_00db7c40
