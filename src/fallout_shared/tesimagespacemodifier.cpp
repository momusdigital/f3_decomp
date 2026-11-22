// fallout_shared/tesimagespacemodifier.cpp: TESImageSpaceModifier, RgbaColor, ImageSpaceModifierEffectData, NiColorInterpolator and more (10 functions)
#include "f3_common.h"
#include "tesimagespacemodifier_decls.h"

// @fnv 0x0052bd40
void TESImageSpaceModifier::ResetFormData()
{
    int i, j, kKey;
    memset(&Data, 0, sizeof(Data));
    Data.m_bOverride = false;
    Data.fDuration = 1.0f;
    Data.m_bUseRadialBlur = false;
    Data.m_kRadialBlurCenter = NiPoint2(0.5f, 0.5f);
    Data.m_bUseEffectEntries = false;
    Data.m_ucEffectMode = 0;
    for (i = 0; i < 21; ++i)
        for (j = 0; j < 2; ++j)
        {
            Data.m_auiKeyframeCountsByTypeAndChannel[i][j] = 2;
            pEffectEntryTable[i][j] = new TimedFloatKey[2];
            for (kKey = 0; kKey < 2; ++kKey)
            {
                pEffectEntryTable[i][j][kKey].FUN_0052ce20(DAT_0118aba0[kKey]);
                pEffectEntryTable[i][j][kKey].FUN_004f5d90(DAT_0118aba8[j]);
            }
            m_akFloatInterpolators[i][j].SetAnimationKeys(
                pEffectEntryTable[i][j], Data.m_auiKeyframeCountsByTypeAndChannel[i][j], AnimationKey::LINKEY);
        }
    Data.m_uiEffectEntryCountFirst = 2;
    pFirstEffectRecordArray = new AlphaColor[2];
    for (i = 0; i < 2; ++i)
    {
        pFirstEffectRecordArray[i].FUN_0052ce20(DAT_0118aba0[i]);
        pFirstEffectRecordArray[i].FUN_0052cfc0(RgbaColor(1.0f, 1.0f, 1.0f, 0.0f));
    }
    m_kColorInterpolatorOne.SetAnimationKeys(pFirstEffectRecordArray, Data.m_uiEffectEntryCountFirst,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountTwelfth = 2;
    pSecondEffectRecordArray = new AlphaColor[2];
    for (i = 0; i < 2; ++i)
    {
        pSecondEffectRecordArray[i].FUN_0052ce20(DAT_0118aba0[i]);
        pSecondEffectRecordArray[i].FUN_0052cfc0(RgbaColor(1.0f, 1.0f, 1.0f, 0.0f));
    }
    m_kColorInterpolatorTwo.SetAnimationKeys(pSecondEffectRecordArray, Data.m_uiEffectEntryCountTwelfth,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSecond = 2;
    pSecondEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pSecondEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pSecondEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorOne.SetAnimationKeys(pSecondEffectEntries, Data.m_uiEffectEntryCountSecond,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountThird = 2;
    pThirdEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pThirdEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pThirdEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorTwo.SetAnimationKeys(pThirdEffectEntries, Data.m_uiEffectEntryCountThird, AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountFourth = 2;
    pTenthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pTenthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pTenthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorNine.SetAnimationKeys(pTenthEffectEntries, Data.m_uiEffectEntryCountFourth,
                                              AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountFifth = 2;
    pEleventhEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pEleventhEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pEleventhEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorTen.SetAnimationKeys(pEleventhEffectEntries, Data.m_uiEffectEntryCountFifth,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSixth = 2;
    pTwelfthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pTwelfthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pTwelfthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorEleven.SetAnimationKeys(pTwelfthEffectEntries, Data.m_uiEffectEntryCountSixth,
                                                AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountTenth = 2;
    pFourthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pFourthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pFourthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorThree.SetAnimationKeys(pFourthEffectEntries, Data.m_uiEffectEntryCountTenth,
                                               AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountEleventh = 2;
    pFifthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pFifthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pFifthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorFour.SetAnimationKeys(pFifthEffectEntries, Data.m_uiEffectEntryCountEleventh,
                                              AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSeventh = 2;
    pSeventhEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pSeventhEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pSeventhEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorFive.SetAnimationKeys(pSeventhEffectEntries, Data.m_uiEffectEntryCountSeventh,
                                              AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountEighth = 2;
    pEighthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pEighthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pEighthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorSix.SetAnimationKeys(pEighthEffectEntries, Data.m_uiEffectEntryCountEighth,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountNinth = 2;
    pNinthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pNinthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pNinthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorSeven.SetAnimationKeys(pNinthEffectEntries, Data.m_uiEffectEntryCountNinth,
                                               AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountThirteenth = 2;
    pSixthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pSixthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pSixthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorEight.SetAnimationKeys(pSixthEffectEntries, Data.m_uiEffectEntryCountThirteenth,
                                               AnimationKey::LINKEY);
    pIntroSound = 0;
    pOutroSound = 0;
}

// Sets the form type to IMAD, calls the initializer, and if this is the global instance DAT_011c9750 calls the second initializer.
// @fnv 0x0052b8f0
TESImageSpaceModifier::TESImageSpaceModifier()
{
    SetFormType(ENUM_FORM_ID_IMAD_ID);
    ResetFormData();
    if (this == &DAT_011c9750)
        NotifySaveLoadGameOfFormChange();
}
// @fnv 0x0052d260
// @f3 0x004a3bb0 (community match, verified in this file)
inline bool TESForm::IsFormInitialized() const { return (iFormFlags >> 3) & 1; }
inline unsigned int TESForm::GetFormID() { return iFormID; }

class ISMStandIn : public TESForm
{
  public:
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    TESSound* pIntroSound;
    TESSound* pOutroSound;
};
FNV_STATIC_ASSERT(offsetof(ISMStandIn, pIntroSound) == 0xa8);
FNV_STATIC_ASSERT(offsetof(ISMStandIn, pOutroSound) == 0xac);

extern char DAT_00f49948, DAT_00f460fc, DAT_00f46078;
void* __cdecl FUN_00c0050a(void*, int, const void*, const void*, int);

// pdb: BGSConstructibleObject::InitItem | BGSConstructibleObject.obj | fnv360_0822_retail, vtable, medium
void TESImageSpaceModifier::InitItem()
{
    if (IsFormInitialized())
        return;
    ResetFormData();
    ISMStandIn* pThis = (ISMStandIn*)this;
    unsigned int formID = (unsigned int)pThis->pIntroSound;
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pThis->pIntroSound = static_cast<TESSound*>(FUN_00c0050a(TESForm::GetFormByID(formID), 0, &DAT_00f46078, &DAT_00f49948, 0));
        if (!pThis->pIntroSound)
            Warning("MASTERFILE: Could not find item list (%08X) on constructible object '%s' (%08X).", formID,
                    GetFormEditorID(), GetFormID());
    }
    formID = (unsigned int)pThis->pOutroSound;
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pThis->pOutroSound = static_cast<TESSound*>(FUN_00c0050a(TESForm::GetFormByID(formID), 0, &DAT_00f46078, &DAT_00f460fc, 0));
        if (!pThis->pOutroSound)
            Warning("MASTERFILE: Could not find created item (%08X) on constructible object '%s' (%08X).", formID,
                    GetFormEditorID(), GetFormID());
    }
    SetInitializationState(true);
}

// @fnv 0x005316c0

// Multiplies the r, g, b and a components by scale and returns a reference to this object.
// @fnv 0x005321d0
// @fnv 0x0052bad0
TESImageSpaceModifier::ImageSpaceModifierEffectData::ImageSpaceModifierEffectData()
{}
// @fnv 0x0052d3b0
// @fnv 0x00532fd0
NiPoint2 operator*(float scale, const NiPoint2& arPoint)
{
    return arPoint * scale;
}

struct NiStream;
struct blob12
{
    char b[12];
};
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
typedef char _sizecheck_NiMatrix3[sizeof(ThreeByThreeMatrix) == 48 ? 1 : -1];

struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct Obj52 : NiMemObject
{
    void FUN_00a3cc80();
    void* FUN_0052cf90(unsigned int);
    static void operator delete(void*, unsigned int);
};

namespace fnv_0052d130 {
struct Obj52 : NiMemObject
{
    void FUN_00a3cc80();
    void* FUN_0052d130(unsigned int);
    static void operator delete(void*, unsigned int);
};
}  // namespace fnv_0052d130

namespace fnv_0052d120 {
struct NiRTTI;

struct NiColorData
{
    NiRTTI* __thiscall GetRTTI() const;
};

}  // namespace fnv_0052d120

struct FUN_00533060_shell
{
    void* __thiscall FUN_00533060(void** a, void** b, char* c);
};

namespace fnv_00533000 {
struct Flt
{
    operator unsigned int();
};
struct FUN_00533060_shell
{
    void* FUN_00533060(void**, void**, char*);
};
}  // namespace fnv_00533000

struct FUN_0052bb70
{
    virtual ~FUN_0052bb70();
    char pad[0x20];
};

struct FUN_00532ec0_v4
{
    float x;
    float y;
    float z;
    float w;
};
struct FUN_00532ec0
{
    FUN_00532ec0_v4* SUB(FUN_00532ec0_v4* result, const FUN_00532ec0_v4& sub);
};

namespace Real {
struct InterpolatorBase
{
    unsigned int referenceCount;
    unsigned int flags;
    float lastTime;
    float currentTime;
    float startTime;
    float endTime;
    void* controller;
    ~InterpolatorBase();
};
struct ColorDataReference
{
    void* colorData;
    ~ColorDataReference();
};
struct FUN_0052bb70 : InterpolatorBase
{
    ColorDataReference colorData;
    ~FUN_0052bb70();
};
}

struct SpawnedObject
{
    void Method(float* pOut, float f);
};

// @fnv 0x00532f40
float* __cdecl FUN_00532f40(float* pOut, float f, SpawnedObject* pObj)
{
    pObj->Method(pOut, f);
    return pOut;
}

struct BlendColor
{
    float r, g, b, a;
    BlendColor(float, float, float, float);
    BlendColor FUN_00532ec0(const BlendColor&) const;
    BlendColor AddDelta(const BlendColor&) const;
};
BlendColor FUN_00532f40(float, const BlendColor&);
