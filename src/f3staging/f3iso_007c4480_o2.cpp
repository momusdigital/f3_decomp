#include <new>
// src/f3staging/f3iso_007c4480_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x007c4480 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x007c4480 (community match, verified in this file)
namespace f3m_007c4480 {
// f3decomp candidate for 0x007c4480 (??0FUN_007c4480@@QAE@H@Z)
// MissileProjectile ABI projection: the secondary ChildCell interface is at +18.
// SpawnedBase retains the pack's imported Projectile(int) constructor name.
struct AaronProjectileForm7C4480
{
    virtual ~AaronProjectileForm7C4480();
    unsigned char m_04;
    unsigned char unk05;
    unsigned short unk06;
    unsigned int m_08;
    unsigned int m_0c;
    void* m_10;
    void* m_14;
};
struct TESObjectCELL;
struct AaronChildCell7C4480
{
    virtual TESObjectCELL* GetParentCell();
};
class SpawnedBase : public AaronProjectileForm7C4480, public AaronChildCell7C4480
{
public:
    virtual ~SpawnedBase();
    virtual void Tick();
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    SpawnedBase(int value);
};
class FUN_007c4480 : public SpawnedBase
{
public:
    int m_140;
    unsigned char m_144;
    virtual ~FUN_007c4480();
    FUN_007c4480(int value);
};
// pdb: MissileProjectile::MissileProjectile | MissileProjectile.obj | fnv360_0822_retail, call_gap, low
// pdb params: abAdd
FUN_007c4480::FUN_007c4480(int value)
    : SpawnedBase(value), m_140(0), m_144(0)
{
    m_04 = 0x3d;
}

}   // namespace f3m_007c4480
