#include "f3_common.h"
// src/staging/blk_00de0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00de0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00de0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

struct __declspec(align(8)) Entry8
{
    int m_key;
    int m_uiFilterValue;
};

struct FinishingFlag
{
    int m_bFinishing;
};

__declspec(align(16)) struct HavokObjDfd
{
    void* m_ppVirtualMethodTable;
    int m_04, m_08, m_0c;
    int m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c;
    int m_50, m_54, m_58, m_5c, m_60, m_64, m_68, m_6c;
    int m_70, m_74, m_78, m_7c, m_80, m_84, m_88, m_8c;
    int m_90, m_94, m_98, m_9c, m_a0, m_a4, m_a8, m_ac;
    int m_b0, m_b4, m_b8, m_bc, m_c0, m_c4, m_c8, m_cc;
    int m_d0, m_d4, m_d8, m_dc, m_e0, m_e4, m_e8, m_ec;

    HavokObjDfd(FinishingFlag flag);
};

struct DFFFinishFlag
{
    int m_bFinishing;
};

struct __declspec(align(16)) DFFObject
{
    void* m_vtbl;
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
    DFFObject(DFFFinishFlag flag);
};

// @fnv 0x00dff1a0
// pdb: hkpBallSocketChainData::hkpBallSocketChainData | hkpBallSocketChainData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: getVtablehkpBallSocketChainData)
// pdb params: f
void* FUN_00dff1a0()
{
    DFFFinishFlag f;
    f.m_bFinishing = 0;
    DFFObject o(f);
    return o.m_vtbl;
}

struct FinishFlag
{
    int m_bFinishing;
};

struct __declspec(align(16)) FinishLoadedShape
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FinishLoadedShape(FinishFlag flag);
};

#include <xmmintrin.h>

typedef __m128 S_00de2010_Vec;

struct __declspec(align(16)) Vec4
{
    __m128 m_vComponents;

    void operator=(const Vec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct __declspec(align(16)) SetupTarget
{
    int unk00;
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
    Vec4 m_vec60;
    Vec4 m_vec70;
    Vec4 m_vec80;
    float m_float90;
    float m_float94;
    float m_float98;
    int m_int9C;

    void FUN_00de4950(float f98, float f90, float f94, int i9C, const Vec4& v80, const Vec4& v60, const Vec4& v70);
};

struct S00de49b0_Vec4
{
    float x, y, z, w;
};

struct S00de49b0_Quad
{
    __m128 m_vComponents;
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct S00de49b0_Rotation
{
    S00de49b0_Quad m_kColumn0;
    S00de49b0_Quad m_kColumn1;
    S00de49b0_Quad m_kColumn2;
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct S00de49b0_Transform
{
    S00de49b0_Rotation m_rotation;
    __m128 m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation = _mm_setzero_ps();
    }
};

class __declspec(novtable) S00de49b0_RefObject
{
  public:
    S00de49b0_RefObject() : m_sReferenceCount(1)
    {}
    virtual void vf00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class __declspec(novtable) S00de49b0_Base : public S00de49b0_RefObject
{
  public:
    S00de49b0_Base() : m_ulUserData(0), m_type(5)
    {
        m_kMotionTransform.setIdentity();
    }
    S00de49b0_Base(int type);
    unsigned int m_ulUserData;
    S00de49b0_Transform m_kMotionTransform;
    int m_type;
};

class hkDisplaySemiCircle : public S00de49b0_Base // src: F3_EXE vtable 0x00e87068 (old: FUN_00de49b0)
{
  public:
    hkDisplaySemiCircle(const S00de49b0_Vec4& kC, const S00de49b0_Vec4& kA, const S00de49b0_Vec4& kB, float f1, float f2,
                 float f3, int i1);
    virtual void vf00();

    S00de49b0_Vec4 m_kA;
    S00de49b0_Vec4 m_kB;
    S00de49b0_Vec4 m_kC;
    float m_f90;
    float m_f94;
    float m_f98;
    int m_i9C;
};

// @f3 0x00a6ac90 (community match, verified in this file)
// pdb: hkDisplaySemiCircle::hkDisplaySemiCircle | hkDisplaySemiCircle.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: center, normal, startPerp, thetaMin, thetaMax, radius, numSegments
hkDisplaySemiCircle::hkDisplaySemiCircle(const S00de49b0_Vec4& kC, const S00de49b0_Vec4& kA, const S00de49b0_Vec4& kB,
                           float f1, float f2, float f3, int i1)
    : S00de49b0_Base(5)
{
    m_kA = kA;
    m_kB = kB;
    m_kC = kC;
    m_f90 = f1;
    m_f94 = f2;
    m_f98 = f3;
    m_i9C = i1;
}


struct S00de53b0_Quad
{
    __m128 m_vComponents;
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct S00de53b0_Rotation
{
    S00de53b0_Quad m_kColumn0;
    S00de53b0_Quad m_kColumn1;
    S00de53b0_Quad m_kColumn2;
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct S00de53b0_Transform
{
    S00de53b0_Rotation m_rotation;
    __m128 m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation = _mm_setzero_ps();
    }
};

class __declspec(novtable) S00de53b0_RefObject
{
  public:
    S00de53b0_RefObject() : m_sReferenceCount(1)
    {}
    virtual void vf00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class __declspec(novtable) S00de53b0_Base : public S00de53b0_RefObject
{
  public:
    S00de53b0_Base() : m_ulUserData(0), m_type(4)
    {
        m_kMotionTransform.setIdentity();
    }
    unsigned int m_ulUserData;
    S00de53b0_Transform m_kMotionTransform;
    int m_type;
};

struct __declspec(align(16)) Vector4_df07c0
{
    float q[4];
};

struct Motion_df07c0
{
    int unk00;
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
    Vector4_df07c0 m_kTranslationalVelocity[3];  // +0x30
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    Vector4_df07c0 m_kAngularVelocity[3];  // +0x90
};

struct MotionArgument
{
    Motion_df07c0* p;
    MotionArgument(Motion_df07c0* q) : p(q)
    {}
};

struct FUN_00c93d10_arg
{
    int m_uiFilterValue;
};

struct __declspec(align(16)) Holder
{
    void* m_pVTable;
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
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    void FUN_00c93d10(FUN_00c93d10_arg arg);
};

class __declspec(align(16)) S00dfb2b0_Object
{
  public:
    S00dfb2b0_Object(FinishingFlag flag);  // FUN_00dfb2d0
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfb2b0
// pdb: getVtablehkpStorageExtendedMeshShapeShapeSubpartStorage | hkpCollidehkpExtendedMeshShapeReflections.obj | tesv_win, objrun_prop, low
const void* __cdecl FUN_00dfb2b0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfb2b0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

namespace fnv_00dfb2d0 {

struct FinishFlag
{
    int m_bFinishing;
};

}  // namespace fnv_00dfb2d0

class __declspec(align(16)) S00dfb400_Object
{
  public:
    S00dfb400_Object(FinishingFlag flag);  // FUN_00e2ea20
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfb400
// pdb: getVtablehkpMalleableConstraintData | hkpDynamicsReflections.obj | tesv_win, caller_sim, low
const void* __cdecl FUN_00dfb400()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfb400_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dfb460_Object
{
  public:
    S00dfb460_Object(FinishingFlag flag);  // Init
    void* m_ppVirtualMethodTable;
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
};

class __declspec(align(16)) S00dfba80_Object
{
  public:
    S00dfba80_Object(FinishingFlag flag);  // FUN_00e34800
    void* m_ppVirtualMethodTable;
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
};

class __declspec(align(16)) S00dfc7a0_Object
{
  public:
    S00dfc7a0_Object(FinishingFlag flag);  // ReleaseLinks
    void* m_ppVirtualMethodTable;
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
};

struct DFC830Zero
{
    int m_uiFilterValue;
};

struct __declspec(align(16)) DFC830Obj
{
    int unk00;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    void FUN_00dfc850(DFC830Zero arg);
};

class __declspec(align(16)) S00dfcb70_Object
{
  public:
    S00dfcb70_Object(FinishingFlag flag);  // FUN_00e3b960
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfcb70
// pdb: getVtablehkpBallGun | hkpUtilitiesReflections.obj | tesv_win, objopen_prop, low
const void* __cdecl FUN_00dfcb70()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfcb70_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct Handle_dfce10
{
    int m_v;
};
struct __declspec(align(16)) FUN_00d53df0
{
    FUN_00d53df0(Handle_dfce10 kHandle);
    int m_iResult;
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
};
// @fnv 0x00dfce10
// pdb: hkpPoweredChainData::hkpPoweredChainData | hkpPoweredChainData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: getVtablehkpPoweredChainData)
// pdb params: f
int __cdecl FUN_00dfce10()
{
    Handle_dfce10 kHandle = {0};
    FUN_00d53df0 kQuery(kHandle);
    return kQuery.m_iResult;
}

class __declspec(align(16)) S00dfcf40_Object
{
  public:
    S00dfcf40_Object(FinishingFlag flag);  // InitializeVtables
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dfcf40
// pdb: getVtablehkpStorageMeshShapeSubpartStorage | hkpCollidehkpMeshShapeReflections.obj | tesv_win, objrun_prop, low
const void* __cdecl FUN_00dfcf40()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dfcf40_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dfd200_Object
{
  public:
    S00dfd200_Object(FinishingFlag flag);  // FUN_00cf56f0
    void* m_ppVirtualMethodTable;
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
    int unk64;
    int unk68;
    int unk6C;
};

class __declspec(align(16)) S00dfd280_Object
{
  public:
    S00dfd280_Object(FinishingFlag flag);  // FUN_00d59830
    void* m_ppVirtualMethodTable;
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
    int unk64;
    int unk68;
    int unk6C;
};

// FUN_00dfd630 (0x00dfd630, 28 bytes, pack /MT /Od /Oy- /GS /EHsc /Gy)
//
// Original: push ebp / mov ebp,esp / and esp,-16 / sub esp,0x70
//           xor eax,eax / push eax        -> byval 1-int zero UDT arg
//           lea ecx,[esp+4]               -> this = 0x70-byte stack object at frame bottom
//           call FUN_00e3e380             -> thiscall ctor, callee pops its 4-byte arg
//           mov eax,[esp]                 -> return object's first dword
//           mov esp,ebp / pop ebp / ret
//
// The simple aligned ESP frame is /O2 WITHOUT /Oy- output (dfc830/d4b330 twins:
// proofs accepted). Source mirrors the accepted dfc830 draft.
struct Zero
{
    int v;
};

struct __declspec(align(16)) Dfd630Obj
{
    int unk00;  // vptr slot written by the ctor
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
    int unk64;
    int unk68;
    int unk6C;
    void FUN_00e3e380(Zero arg);
};

unsigned int DAT_010e33dc;

struct FUN_00dfd9b0_arg
{
    int m_uiFilterValue;
};

struct FUN_00dfd9b0_sub
{
    int m_00;
    void FUN_00cb0a70(FUN_00dfd9b0_arg arg);
};

struct __declspec(align(16)) FUN_00dfd9b0_holder
{
    unsigned int* m_pTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dfd9b0_sub m_sub;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

class __declspec(align(16)) S00dfda80_Object
{
  public:
    S00dfda80_Object(FinishingFlag flag);  // FUN_00e3f510
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class __declspec(align(16)) S00dfe280_Object
{
  public:
    S00dfe280_Object(FinishingFlag flag);  // FUN_00ce25f0
    void* m_ppVirtualMethodTable;
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
};

int DAT_010cb864;

struct ZArgDFE2F0
{
    int m_uiFilterValue;
};

struct ZSubDFE2F0
{
    int m_00;
    void FUN_00ce5360(ZArgDFE2F0 arg);
};

struct __declspec(align(16)) ZHolderDFE2F0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ZSubDFE2F0 m_sub;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

struct FUN_00dfe440_arg
{
    int m_uiFilterValue;
};

struct __declspec(align(16)) FUN_00dfe440_obj
{
    int m_pVTable;
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
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    void FUN_00e40ca0(FUN_00dfe440_arg arg);
};

struct Handle_dff130
{
    int m_v;
};
struct FUN_00dff130_sub
{
    void FUN_00cb0a70(Handle_dff130 kHandle);
    int m_00;
};
struct __declspec(align(16)) FUN_00dff130_obj
{
    int* m_pVtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dff130_sub m_kSub;
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
};

class __declspec(align(16)) S00dff310_Object
{
  public:
    S00dff310_Object(FinishingFlag flag);  // Initialize
    void* m_ppVirtualMethodTable;
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
    int unk64;
    int unk68;
    int unk6C;
};

class __declspec(align(16)) S00dff4f0_Object
{
  public:
    S00dff4f0_Object(FinishingFlag flag);  // FUN_00e46300
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dff4f0
// pdb: getVtablehkpGenericConstraintData | hkpDynamicsReflections.obj | tesv_win, caller_sim, low
const void* __cdecl FUN_00dff4f0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dff4f0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dff8b0_Object
{
  public:
    S00dff8b0_Object(FinishingFlag flag);  // InitializeRecordPointers
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dff8b0
const void* __cdecl FUN_00dff8b0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dff8b0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dffa70_Object
{
  public:
    S00dffa70_Object(FinishingFlag flag);  // FUN_00dffa90
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dffa70
const void* __cdecl FUN_00dffa70()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dffa70_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dffbb0_Object
{
  public:
    S00dffbb0_Object(FinishingFlag flag);  // FUN_00e46f20
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dffbb0
// pdb: getVtablehkpCylinderShape | hkpCollideReflections.obj | tesv_win, caller_sim, low
const void* __cdecl FUN_00dffbb0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dffbb0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

class __declspec(align(16)) S00dfffa0_Object
{
  public:
    S00dfffa0_Object(FinishingFlag flag);  // FUN_00cdf760
    virtual void vf00();
    int m_kNextStreamField[7];
};

struct __declspec(align(16)) Quad_de1190
{
    float q[4];
};  // hkVector4 storage (float[4]: see the vptr padding note)

struct RefObject_de1190
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    RefObject_de1190()
    {
        m_sReferenceCount = 1;
    }
    virtual ~RefObject_de1190()
    {}
};

struct TransformShape_de1190 : RefObject_de1190
{
    int m_type;
    int unk0c;
    Quad_de1190 m_rotation[3];
    Quad_de1190 m_vTranslation;
    int m_userType;
    int unk54, unk58, unk5c;
    TransformShape_de1190()
    {
        m_type = 0;
        m_userType = 3;
        __m128 kZero = _mm_setzero_ps();
        _mm_store_ps(m_rotation[0].q, kZero);
        _mm_store_ps(m_rotation[1].q, kZero);
        _mm_store_ps(m_rotation[2].q, kZero);
        m_rotation[0].q[0] = 1.0f;
        m_rotation[1].q[1] = 1.0f;
        m_rotation[2].q[2] = 1.0f;
        _mm_store_ps(m_vTranslation.q, kZero);
    }
    virtual ~TransformShape_de1190()
    {}
};

namespace SIMD56 {
struct __declspec(intrin_type) __declspec(align(16)) __m128
{
    float x, y, z, w;
};
}
struct SplitB
{
    int f0;
    int f4;
};

struct SplitA
{
    int f0;
    int f4;
    short lo;
    short hi;
};

struct Output56
{
    unsigned int flags;
    int v;
    void setPlanes(short lo, short hi)
    {
        v = 0;
        ((short*)&v)[0] = lo;
        ((short*)&v)[1] = hi;
    }
};

__declspec(noalias) int FUN_00df4ec0(SplitB* a, int b, int c, SplitA* sa, int* p5, SplitB* sb, SIMD56::__m128* v20,
                                     SIMD56::__m128* v40);

struct S00dfbe20_Member
{
    S00dfbe20_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class S00dfbe20_Base
{
  public:
    S00dfbe20_Base(FinishingFlag flag)
    {}
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class S00dfbe20_Mid : public S00dfbe20_Base
{
  public:
    S00dfbe20_Mid(FinishingFlag flag) : S00dfbe20_Base(flag), m_kMember(flag)
    {}
    virtual void vf00();
    S00dfbe20_Member m_kMember;
};

class __declspec(align(16)) S00dfbe20_Object : public S00dfbe20_Mid
{
  public:
    S00dfbe20_Object(FinishingFlag flag) : S00dfbe20_Mid(flag)
    {}
    virtual void vf00();
    int m_kNextStreamField[48];
};

class __declspec(align(16)) S00dfe5e0_Object
{
  public:
    S00dfe5e0_Object(FinishingFlag flag)
    {
        FUN_00dfd9b0_arg arg;
        arg.m_uiFilterValue = flag.m_bFinishing;
        m_kFirst.FUN_00cb0a70(arg);
        m_kSecond.FUN_00cb0a70(arg);
    }
    virtual void vf00();
    int unk04;
    FUN_00dfd9b0_sub m_kFirst;
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
    FUN_00dfd9b0_sub m_kSecond;
    int unk58;
    int unk5C;
};

struct S00dfba10_Member
{
    S00dfba10_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};

class __declspec(align(16)) S00dfba10_Object
{
  public:
    S00dfba10_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    S00dfba10_Member m_kMember;
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
};

struct S00dfc400_Member
{
    S00dfc400_Member(FinishingFlag flag);
    int m_iWordAt00;
};

class __declspec(align(16)) S00dfc400_Object
{
  public:
    S00dfc400_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S00dfc400_Member m_kMember;
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
};

class __declspec(align(16)) AnimationBindingVtableProbe
{
  public:
    AnimationBindingVtableProbe(FinishingFlag flag)
    {
        FUN_00dfd9b0_arg argument = {flag.m_bFinishing};
        m_skeletonName.FUN_00cb0a70(argument);
    }
    virtual void vf00();
    int unk04;
    FUN_00dfd9b0_sub m_skeletonName;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct __declspec(align(16)) SpringVtableObject
{
    int* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dff130_sub m_name;
    int unk18;
    int unk1C;
    float m_lastForceX;
    float m_lastForceY;
    float m_lastForceZ;
    float m_lastForceW;
    float m_pivotAX;
    float m_pivotAY;
    float m_pivotAZ;
    float m_pivotAW;
    float m_pivotBX;
    float m_pivotBY;
    float m_pivotBZ;
    float m_pivotBW;
    float m_fRestLength;
    float m_fSpringStrength;
    float m_fMotorDamping;
    bool m_compression;
    bool m_extension;
};

struct __declspec(align(16)) ContactSystemView
{
    int* table;
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
    FUN_00dfd9b0_sub name;
    int userData;
    int active;
    int contactsData;
    int contactsSize;
    int contactsCapacity;
};

struct __declspec(align(16)) VtableProbeDff2b0
{
    int* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dff130_sub m_name;
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
};

class __declspec(align(16)) S00dff380_Object : public S00dfbe20_Mid
{
  public:
    S00dff380_Object(FinishingFlag flag) : S00dfbe20_Mid(flag)
    {}
    virtual void vf00();
    int unkD18;
    int unkD1C;
    int unkD20;
    int unkD24;
    int unkD28;
    int unkD2C;
    int unkD30;
    int unkD34;
    int unkD38;
    int unkD3C;
};

struct __declspec(align(16)) DashpotTypeInfoObject
{
    FUN_00dff130_obj m_pAction;
    float m_impulseX;
    float m_impulseY;
    float m_impulseZ;
    float m_impulseW;
};

struct __declspec(align(16)) AngularActionVtableObject
{
    int* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00dff130_sub m_name;
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
};
