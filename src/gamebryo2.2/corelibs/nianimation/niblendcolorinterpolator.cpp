#include "f3_common.h"
// src/gamebryo2.2/corelibs/nianimation/niblendcolorinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niblendcolorinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiStream;

struct RgbaColor
{
    float r, g, b, a;
    void SaveBinary(NiStream& kStream);
};

struct FUN_00a37ec0_tgt
{
    void FUN_00a37ec0(NiStream& kStream);
};

struct NiBlendColorInterpolator
{
    char unk00[0xe];
    unsigned char m_ucInterpCount;  // src: FNV360_PDB NiBlendInterpolator +0xE (old: m_Base)
    char unk0F[0x30 - 0xf];
    RgbaColor m_kColorValue;  // src: FNV360_PDB +0x30
    bool m_bValidValue;  // src: FNV360_PDB +0x40
    void FUN_00a56040(NiStream& kStream);
};

// @fnv 0x00a56040
// pdb: NiBlendQuaternionInterpolator::LoadBinary | NiBlendQuaternionInterpolator.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: kStream
void NiBlendColorInterpolator::FUN_00a56040(NiStream& kStream)
{
    ((FUN_00a37ec0_tgt*)this)->FUN_00a37ec0(kStream);
    m_kColorValue.SaveBinary(kStream);
}

extern "C" void* g_011f4074;

void __fastcall FUN_00a36890(void*);
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
extern RgbaColor const DAT_011a9430;
extern int DAT_011a9434;
extern int DAT_011a9438;
extern int DAT_011a943c;
extern int DAT_0109a58c;

// @fnv 0x00a55ff0
// pdb: NiBlendColorInterpolator::CreateObject | NiBlendColorInterpolator.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
NiBlendColorInterpolator* __cdecl CreateBlendColorInterpolator()
{
    NiBlendColorInterpolator* pInterpolator = (NiBlendColorInterpolator*)BSFadeNode::operator new(0x44);
    if (pInterpolator)
    {
        FUN_00a36890(pInterpolator);
        *(int*)pInterpolator = (int)&DAT_0109a58c;
        ((int*)&pInterpolator->m_kColorValue)[0] = *(int*)&DAT_011a9430;
        ((int*)&pInterpolator->m_kColorValue)[1] = DAT_011a9434;
        ((int*)&pInterpolator->m_kColorValue)[2] = DAT_011a9438;
        ((int*)&pInterpolator->m_kColorValue)[3] = DAT_011a943c;
        pInterpolator->m_bValidValue = 0;
    }
    else
    {
        pInterpolator = 0;
    }
    return pInterpolator;
}

struct NiBlendInterpolator
{
    NiBlendInterpolator(bool, float, unsigned char);
    char _pad[0x30];
};
struct FUN_00a55f80 : NiBlendInterpolator
{
    RgbaColor m_kColorValue;  // src: FNV360_PDB NiBlendColorInterpolator +0x30 (old: _c)
    bool m_bValidValue;  // src: FNV360_PDB NiBlendColorInterpolator +0x40 (old: m_kPointB)
    FUN_00a55f80(bool, float, unsigned char);
};
// Constructs the object: installs the vtable, copies four ints from DAT_011a9430 into offset 0x30, and clears the flag at the end.
// @fnv 0x00a55f80
// pdb: NiBlendColorInterpolator::NiBlendColorInterpolator | NiBlendColorInterpolator.obj | fnv360_1110_retail, objopen_prop, medium
// pdb params: bManagerControlled, fWeightThreshold, ucArraySize
FUN_00a55f80::FUN_00a55f80(bool a, float b, unsigned char c) : NiBlendInterpolator(a, b, c)
{
    *(void**)this = (void*)&DAT_0109a58c;
    ((int*)&m_kColorValue)[0] = ((int*)&DAT_011a9430)[0];
    ((int*)&m_kColorValue)[1] = ((int*)&DAT_011a9430)[1];
    ((int*)&m_kColorValue)[2] = ((int*)&DAT_011a9430)[2];
    ((int*)&m_kColorValue)[3] = ((int*)&DAT_011a9430)[3];
    m_bValidValue = 0;
}

void __fastcall DestroyInterpolatorArray(void*);
void __cdecl _delete(void*, unsigned int);
struct NiBlendColorInterpolator_shell : NiBlendColorInterpolator
{
    void* FUN_00a56070(unsigned int flags);
};
// @fnv 0x00a56070
void* NiBlendColorInterpolator_shell::FUN_00a56070(unsigned int flags)
{
    DestroyInterpolatorArray(this);
    if (flags & 1)
        _delete(this, 0x44);
    return this;
}

namespace fnv_00a56460 {
struct NiColorA_Helper
{
    void LoadBinary(NiStream&);
};
struct NiBlendInterpolator
{
    void LoadBinary(NiStream&);
};
struct NiColorA_Compare
{
    bool operator!=(RgbaColor const* other);
};

struct NiBlendColorInterpolator_shell : public NiBlendInterpolator
{
    char unk00[0x30];
    char m_kColorValue[0x10];  // src: FNV360_PDB NiBlendColorInterpolator +0x30 (NiColorA)
    bool m_bValidValue;  // src: FNV360_PDB NiBlendColorInterpolator +0x40
    void FUN_00a56460(NiStream& kStream);
};

// @fnv 0x00a56460
// pdb: NiBlendColorInterpolator::LoadBinary | NiBlendColorInterpolator.obj | fnv360_0822_retail, objrun, low, conflict (bridge: NiBlendQuaternionInterpolator::LoadBinary)
// pdb params: kStream
void NiBlendColorInterpolator_shell::FUN_00a56460(NiStream& kStream)
{
    ((NiBlendInterpolator*)this)->LoadBinary(kStream);
    ((NiColorA_Helper*)m_kColorValue)->LoadBinary(kStream);
    if (((NiColorA_Compare*)m_kColorValue)->operator!=(&DAT_011a9430))
        m_bValidValue = true;
}
}  // namespace fnv_00a56460

// ---- stand-in for NiInterpolator (not declared in unit prelude) ----
struct NiInterpolator
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual bool ControlsTransform();
};

// Calls the interpolator's virtual method at slot 44 and returns its boolean result.
// @fnv 0x00a55fd0
// pdb: NiBlendColorInterpolator::InterpolatorIsCorrectType | NiBlendColorInterpolator.obj | fnv360_1110_retail, objrun_open, low
// pdb params: pkInterpolator
bool __stdcall FUN_00a55fd0(NiInterpolator* pkInterpolator)
{
    return pkInterpolator->ControlsTransform();
}

struct CloningProcess
{
    void* m_pCloneMap;
};
struct CloneOwner
{
    void FUN_00a37510(void*, void*);
};
struct FUN_00a56090_shell : NiBlendColorInterpolator
{
    void* NiBlendColorInterpolator_CreateClone(CloningProcess&);
};
// Allocates a NiBlendColorInterpolator, initialises it from DAT_011a9430, copies color fields from this, and returns the clone.
// @fnv 0x00a56090
// pdb: NiBlendColorInterpolator::CreateClone | NiBlendColorInterpolator.obj | fnv360_0822_retail, objrun + bridge(vtable|objopen_prop) + skyrim(caller_sim), high
void* FUN_00a56090_shell::NiBlendColorInterpolator_CreateClone(CloningProcess& kCloning)
{
    NiBlendColorInterpolator* pkObject = (NiBlendColorInterpolator*)BSFadeNode::operator new(0x44);
    if (pkObject)
    {
        FUN_00a36890(pkObject);
        *(void**)pkObject = &DAT_0109a58c;
        ((int*)&pkObject->m_kColorValue)[0] = *(int*)&DAT_011a9430;
        ((int*)&pkObject->m_kColorValue)[1] = DAT_011a9434;
        ((int*)&pkObject->m_kColorValue)[2] = DAT_011a9438;
        ((int*)&pkObject->m_kColorValue)[3] = DAT_011a943c;
        pkObject->m_bValidValue = 0;
    }
    else
    {
        pkObject = 0;
    }
    ((CloneOwner*)this)->FUN_00a37510(pkObject, &kCloning);
    pkObject->m_kColorValue = m_kColorValue;
    pkObject->m_bValidValue = m_bValidValue;
    return pkObject;
}

// ---- placeholder declarations ----
struct NiObjectNET;
struct NiBlendColorInterpolator;

struct FUN_00a56110_shell;

struct FUN_00a37260_shell
{
    void UpdateNormalizedWeights();
};

struct FUN_00a56400_shell : NiBlendColorInterpolator
{
    bool NiBlendColorInterpolator_StoreSingleValue(float fTime, NiObjectNET* pkTarget, RgbaColor* kValue);
    bool UpdateBlend(float fTime, NiObjectNET* pkTarget, RgbaColor* kValue);
    bool InterpolateValue(float fTime, NiObjectNET* pkInterpTarget, RgbaColor& kValue);
};

// @fnv 0x00a56400
// pdb: NiBlendColorInterpolator::Update | NiBlendColorInterpolator.obj | fnv360_0822_retail, objrun, medium
// pdb params: fTime, pkInterpTarget, kValue
bool FUN_00a56400_shell::InterpolateValue(float fTime, NiObjectNET* pkInterpTarget, RgbaColor& kValue)
{
    bool bReturnValue = false;
    unsigned char ucInterpCount = m_ucInterpCount;
    if (ucInterpCount == 1)
    {
        bReturnValue = NiBlendColorInterpolator_StoreSingleValue(fTime, pkInterpTarget, &kValue);
    }
    else if (ucInterpCount > 0)
    {
        ((FUN_00a37260_shell*)this)->UpdateNormalizedWeights();
        bReturnValue = UpdateBlend(fTime, pkInterpTarget, &kValue);
    }
    *(float*)((char*)this + 8) = fTime;
    return bReturnValue;
}

extern float DAT_0109696c;

struct FUN_00a56110_color
{
    int c00;
    int c04;
    int c08;
    int c0c;
};

struct FUN_00a56110_target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual bool GetColor(float fTime, NiObjectNET* pkTarget, FUN_00a56110_color* kValue);
};

struct FUN_00a56110_shell
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char flags0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    int unk10;
    int unk14;
    FUN_00a56110_target* pTarget;
    int unk1c;
    float fValue20;
    int unk24;
    int unk28;
    int unk2c;
    FUN_00a56110_color color30;
    bool NiBlendColorInterpolator_StoreSingleValue(float fTime, NiObjectNET* pkTarget, FUN_00a56110_color* kOut);
};

// @fnv 0x00a56110
// pdb: NiBlendColorInterpolator::StoreSingleValue | NiBlendColorInterpolator.obj | fnv360_0822_retail, objrun, high
// pdb params: fTime, pkInterpTarget, kValue
// pdb: NiBlendColorInterpolator::StoreSingleValue | NiBlendColorInterpolator.obj | fnv360_0822_retail, objrun, high (was: GetColorAtTime)
bool FUN_00a56110_shell::NiBlendColorInterpolator_StoreSingleValue(float fTime, NiObjectNET* pkTarget, FUN_00a56110_color* kOut)
{
    if (flags0c & 1)
    {
        fTime = fValue20;
    }
    if (fTime == DAT_0109696c)
    {
        return false;
    }
    if (pTarget->GetColor(fTime, pkTarget, &color30))
    {
        *kOut = color30;
        return true;
    }
    const int* piDefaultColor = reinterpret_cast<const int*>(&DAT_011a9430);
    kOut->c00 = piDefaultColor[0];
    kOut->c04 = piDefaultColor[1];
    kOut->c08 = piDefaultColor[2];
    kOut->c0c = piDefaultColor[3];
    color30 = *kOut;
    return false;
}

bool __stdcall FUN_00a36fd0(void* pkObject);

struct NiColorA_shell : RgbaColor
{
    bool FUN_004a4c90(void* pkOther);
};

struct FUN_00a564a0_cls : NiBlendColorInterpolator
{
    bool FUN_00a564a0(void* pkOther);
};

// @fnv 0x00a564a0
// pdb: NiBlendColorInterpolator::IsEqual | NiBlendColorInterpolator.obj | tesv_win, caller_sim, low
bool FUN_00a564a0_cls::FUN_00a564a0(void* pkOther)
{
    if (!FUN_00a36fd0(pkOther))
    {
        return false;
    }
    void* pkSub = (char*)pkOther + 0x30;
    NiColorA_shell* pkColor = (NiColorA_shell*)&m_kColorValue;
    unsigned char bOk = pkColor->FUN_004a4c90(pkSub) == 0;
    return bOk;
}

extern "C" void* g_011f4074;

struct CA61c0
{
    float r, g, b, a;
    CA61c0()
    {}
    CA61c0(float r0, float g0, float b0, float a0)
    {
        r = r0;
        g = g0;
        b = b0;
        a = a0;
    }
    CA61c0 operator*(float f) const
    {
        CA61c0 res = *this;
        res.r *= f;
        res.g *= f;
        res.b *= f;
        res.a *= f;
        return res;
    }
    CA61c0& operator+=(CA61c0 c)
    {
        CA61c0& t = *this;
        t.r += c.r;
        g += c.g;
        t.b += c.b;
        a += c.a;
        return *this;
    }
    CA61c0& operator/=(float f)
    {
        r /= f;
        g /= f;
        b /= f;
        a /= f;
        return *this;
    }
};
struct Interp61c0
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual bool Update(float fTime, NiObjectNET* pkTarget, CA61c0& kValue);
};
struct SP61c0
{
    Interp61c0* m_pObject;
    operator Interp61c0*() const
    {
        return m_pObject;
    }
    Interp61c0* operator->() const
    {
        return m_pObject;
    }
};
struct Item61c0
{
    SP61c0 m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    int m_cPriority;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};
struct Blend61c0
{
    int pad0[3];
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    char pad0e[6];
    Item61c0* m_pInterpArray;
    int pad18[6];
    CA61c0 m_kColorValue;
    bool m_bValueValid;
    bool GetUpdateTimeForItem(float& fTime, Item61c0& kItem)
    {
        Interp61c0* pkInterpolator = kItem.m_spControllerInterpolator;
        if (pkInterpolator && kItem.m_fNormalizedWeight != 0.0f)
        {
            if (m_uiObjectFlags & 1)
                fTime = kItem.m_fLastEvaluationTime;
            if (fTime == DAT_0109696c)
                return false;
            return true;
        }
        return false;
    }
    bool UpdateBlend(float fTime, NiObjectNET* pkInterpTarget, CA61c0& kValue);
};
// @fnv 0x00a561c0
// pdb: NiBlendColorInterpolator::BlendValues | NiBlendColorInterpolator.obj | fnv360_0822_retail, objrun, medium
// pdb params: fTime, pkInterpTarget, kValue
bool Blend61c0::UpdateBlend(float fTime, NiObjectNET* pkInterpTarget, CA61c0& kValue)
{
    m_bValueValid = false;
    m_kColorValue = CA61c0(0.0f, 0.0f, 0.0f, 0.0f);
    float fTotalWeight = 1.0f;
    for (unsigned char uc = 0; uc < m_ucArraySize; uc++)
    {
        Item61c0& kItem = m_pInterpArray[uc];
        if (kItem.m_spControllerInterpolator && kItem.m_fNormalizedWeight > 0.0f)
        {
            CA61c0 kTempValue(0.0f, 0.0f, 0.0f, 0.0f);
            float fUpdateTime = fTime;
            Item61c0& kItem2 = m_pInterpArray[uc];
            if (!GetUpdateTimeForItem(fUpdateTime, kItem2))
            {
                fTotalWeight -= kItem.m_fNormalizedWeight;
                continue;
            }
            bool bSuccess = kItem.m_spControllerInterpolator->Update(fUpdateTime, pkInterpTarget, kTempValue);
            if (bSuccess)
            {
                m_kColorValue += kTempValue * m_pInterpArray[uc].m_fNormalizedWeight;
                m_bValueValid = true;
            }
            else
            {
                fTotalWeight -= m_pInterpArray[uc].m_fNormalizedWeight;
            }
        }
    }
    if (!m_bValueValid)
    {
        m_kColorValue = *(const CA61c0*)&DAT_011a9430;
        kValue = m_kColorValue;
        return false;
    }
    m_kColorValue /= fTotalWeight;
    kValue = m_kColorValue;
    return true;
}
