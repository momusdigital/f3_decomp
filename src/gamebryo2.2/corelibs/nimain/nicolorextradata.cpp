#include "f3_common.h"
// src/gamebryo2.2/corelibs/nimain/nicolorextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nicolorextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00a893b0_shell
{
    void __thiscall SetValues(int a, int b, int c, int d);
};

// @fnv 0x00a893b0
// pdb: NiColorExtraData::SetValue | NiColorExtraData.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: kColorA
void __thiscall FUN_00a893b0_shell::SetValues(int aiValue0, int aiValue1, int aiValue2, int aiValue3)
{
    *(int*)(this + 0xc) = aiValue0;
    *(int*)(this + 0x10) = aiValue1;
    *(int*)(this + 0x14) = aiValue2;
    *(int*)(this + 0x18) = aiValue3;
}

extern void* g_011f5b68;

extern int DAT_0109eccc;

struct NiStream;

struct NiExtraData
{
    NiExtraData();
    virtual ~NiExtraData();
    void SaveBinary(NiStream& kStream);
};

struct RgbaColor
{
    RgbaColor();
    void SaveBinary(NiStream& kStream);
};

struct NiColorExtraData : NiExtraData
{
    unsigned char _pad[8];
    RgbaColor m_kPrimaryColor;
    void FUN_00a893d0(NiStream& kStream);
};

// @fnv 0x00a893d0
// pdb: NiColorExtraData::SaveBinary | NiColorExtraData.obj | fnv360_0822_retail, caller_sim, high
// pdb params: kStream
void NiColorExtraData::FUN_00a893d0(NiStream& kStream)
{
    NiExtraData::SaveBinary(kStream);
    m_kPrimaryColor.SaveBinary(kStream);
}

struct NiColor
{
    float r, g, b;
    void __thiscall LoadBinary(NiStream& kStream);
};

struct NiStream
{
    unsigned char _pad[0xd8];
    unsigned int m_uiNifVersion;
};

struct NiColorA_LoadBinary_helper
{
    void __thiscall LoadBinary(NiStream& kStream);
};

struct NiExtraData_LoadBinary_helper
{
    void __thiscall LoadBinary(NiStream& kStream);
};

struct FUN_00a894f0_shell : NiColorExtraData
{
    void FUN_00a894f0(NiStream& kStream);
};

// @fnv 0x00a894f0
// pdb: NiColorExtraData::LoadBinary | NiColorExtraData.obj | fnv360_0721_beta, objrun, medium
// pdb params: kStream
void FUN_00a894f0_shell::FUN_00a894f0(NiStream& kStream)
{
    ((NiExtraData_LoadBinary_helper*)this)->LoadBinary(kStream);
    if (kStream.m_uiNifVersion < 0x0500000e)
    {
        NiColor kTmpColor;
        kTmpColor.r = 0.0f;
        kTmpColor.g = 0.0f;
        kTmpColor.b = 0.0f;
        kTmpColor.LoadBinary(kStream);
        float* pColor = (float*)&m_kPrimaryColor;
        pColor[0] = kTmpColor.r;
        pColor[1] = kTmpColor.g;
        pColor[2] = kTmpColor.b;
        pColor[3] = 1.0f;
    }
    else
    {
        ((NiColorA_LoadBinary_helper*)&m_kPrimaryColor)->LoadBinary(kStream);
    }
}

class A89400CloningProcess;

class A89400ColorA
{
  public:
    float r;
    float g;
    float b;
    float a;

    A89400ColorA() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}

    static const A89400ColorA BLACK;
};

class A89400ExtraData
{
  public:
    A89400ExtraData() throw();
    virtual ~A89400ExtraData();
    static void* operator new(unsigned int uiSize) throw();
    static void operator delete(void* pvMem);

    void CopyMemberData(A89400ExtraData* pkDest, A89400CloningProcess& kCloning);

    unsigned int m_uiRefCount;
    char* m_kName;
};

class A89400ColorExtraData : public A89400ExtraData
{
  public:
    __forceinline A89400ColorExtraData() throw()
    {
        m_kFogTint = A89400ColorA::BLACK;
    }
    virtual ~A89400ColorExtraData();

    void CopyMemberData(A89400ColorExtraData* pkDest, A89400CloningProcess& kCloning)
    {
        A89400ExtraData::CopyMemberData(pkDest, kCloning);
        pkDest->m_kFogTint = m_kFogTint;
    }
    A89400ColorExtraData* NiColorExtraData_CreateClone(A89400CloningProcess& kCloning);

    A89400ColorA m_kFogTint;
};

// @fnv 0x00a89400
// pdb: NiColorExtraData::CreateClone | NiColorExtraData.obj | fnv360_0822_retail, objrun + bridge(vtable|objrun) + skyrim(caller_sim), high
A89400ColorExtraData* A89400ColorExtraData::NiColorExtraData_CreateClone(A89400CloningProcess& kCloning)
{
    A89400ColorExtraData* pkDest = new A89400ColorExtraData;
    CopyMemberData(pkDest, kCloning);
    return pkDest;
}

struct S_00a89590_Member
{
    int unk00;
    int unk04;
    int unk08;
    bool FUN_004a4c90(S_00a89590_Member* other);
};

struct S_00a89590
{
    int unk00;
    int unk04;
    int unk08;
    S_00a89590_Member m_unk0c;
    bool FUN_00a89590(S_00a89590* other);
};

// @fnv 0x00a89590
// pdb: NiColorExtraData::IsEqual | NiColorExtraData.obj | tesv_win, hash, low
bool S_00a89590::FUN_00a89590(S_00a89590* other)
{
    if (!other)
        return false;
    if (m_unk0c.FUN_004a4c90(&other->m_unk0c))
        return false;
    return true;
}

extern void* g_011f5b68;

#include <stddef.h>

extern int DAT_0109eccc;
