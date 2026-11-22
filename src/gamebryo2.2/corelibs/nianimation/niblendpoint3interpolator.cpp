// gamebryo2.2/corelibs/nianimation/niblendpoint3interpolator.cpp: NiBlendPoint3Interpolator, BlendPointShell (13 functions)
#include "f3_common.h"
#include "niblendpoint3interpolator_decls.h"

// @fnv 0x00a55b90
// pdb: NiBlendPoint3Interpolator::StoreSingleValue | NiBlendPoint3Interpolator.obj | fnv360_0721_retail, objrun, high
// pdb params: fTime, pkInterpTarget, kValue
bool NiBlendPoint3Interpolator::UpdateAccumulatedTransform(float fTime, NiObjectNET* pkTarget, NiPoint3& kValue)
{
    if (m_uFlags & 1)
        fTime = m_fSingleTime;

    if (fTime == DAT_0109696c)
        return false;

    if (m_pkSingleInterpolator->Update(fTime, pkTarget, m_kPoint3Value))
    {
        kValue = m_kPoint3Value;
        return true;
    }

    m_kPoint3Value = DAT_011a9424;
    kValue = m_kPoint3Value;
    return false;
}

// Updates the interpolator: delegates to single or multi-interpolation update based on m_ucInterpCount, stores fTime in m_fLastTime, and returns success.
// @fnv 0x00a55e00
// pdb: NiBlendPoint3Interpolator::Update | NiBlendPoint3Interpolator.obj | fnv360_0721_retail, objrun, medium
// pdb params: fTime, pkInterpTarget, kValue
bool NiBlendPoint3Interpolator::Update(float fTime, NiObjectNET* pkTarget, NiPoint3& kValue)
{
    bool bSuccess = false;
    if (m_ucInterpCount == 1)
        bSuccess = UpdateAccumulatedTransform(fTime, pkTarget, kValue);
    else if (m_ucInterpCount > 0)
    {
        NormalizeWeights();
        bSuccess = UpdateSingleInterpolator(fTime, pkTarget, kValue);
    }
    m_fLastTime = fTime;
    return bSuccess;
}

struct GlobalObjectO2_00a7b610
{
    int x;
};
extern GlobalObjectO2_00a7b610 g_011f406c;
// @fnv 0x00a55af0
// pdb: NiSkinInstance::GetRTTI | BSTempEffectGeometryDecal.obj | fnv360_0822_retail, udata + bridge(vtable|udata), high
GlobalObjectO2_00a7b610* __cdecl NiSkinInstance_GetRTTI()
{
    return &g_011f406c;
}

struct FUN_00a55ec0_shell : public NiBlendPoint3Interpolator
{
    bool FUN_00a55ec0(NiObject*);
};

struct FUN_00a36fd0_tgt
{
    bool FUN_00a36fd0(NiObject*);
};
struct Call_439090_tgt
{
    bool _Call_439090(const void*);
};

// Calls FUN_00a36fd0 on pkObject; if that succeeds, calls _Call_439090 on pkObject+0x30 and returns its negation.
// @fnv 0x00a55ec0
// pdb: NiBlendPoint3Interpolator::IsEqual | NiBlendPoint3Interpolator.obj | tesv_win, caller_sim, low
bool FUN_00a55ec0_shell::FUN_00a55ec0(NiObject* pkObject)
{
    bool r = ((FUN_00a36fd0_tgt*)this)->FUN_00a36fd0(pkObject);
    if (!r)
        return r;
    r = ((Call_439090_tgt*)&m_kPoint3Value)->_Call_439090(&((NiBlendPoint3Interpolator*)pkObject)->m_kPoint3Value);
    r = !r;
    return r;
}

namespace fnv_00a55ef0 {
struct FUN_00a55ef0_shell : public NiBlendPoint3Interpolator
{
    void AppendPoint3Value(void*);
};

struct ActorCombatGroup;
struct GlobalObjectO2_00a7b610
{
    void* p;
};
extern GlobalObjectO2_00a7b610 g_011f406c;
char* FUN_00a7d330(GlobalObjectO2_00a7b610);
struct ViewerBase
{
    void FUN_00a38080(void*);
};
struct ViewerPoint3
{
    char* FUN_00a59af0(const char*);
};
struct ArrSizeHelper
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, ActorCombatGroup*&);
};
struct StrArrView
{
    char pad[8];
    unsigned short maxSize;
    unsigned short count;
    char pad2[2];
    unsigned short growBy;
};
typedef NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> > StrArray;
// @fnv 0x00a55ef0
// pdb: NiBlendPoint3Interpolator::GetViewerStrings | NiBlendPoint3Interpolator.obj | fnv360_0822_retail, ustr_rel, medium
// pdb params: pkStrings
void FUN_00a55ef0_shell::AppendPoint3Value(void* pkStrings)
{
    ((ViewerBase*)this)->FUN_00a38080(pkStrings);
    StrArray* arr = (StrArray*)pkStrings;
    StrArrView* pArrayView = (StrArrView*)pkStrings;
    ActorCombatGroup* pElement = (ActorCombatGroup*)FUN_00a7d330(g_011f406c);
    unsigned int i = pArrayView->count;
    if (i >= pArrayView->maxSize)
        ((ArrSizeHelper*)arr)->SetSize(pArrayView->growBy + i);
    ((ArrSizeHelper*)arr)->SetAt(i, pElement);
    pElement = (ActorCombatGroup*)((ViewerPoint3*)&m_kPoint3Value)->FUN_00a59af0("m_kPoint3Value");
    i = pArrayView->count;
    if (i >= pArrayView->maxSize)
        ((ArrSizeHelper*)arr)->SetSize(pArrayView->growBy + i);
    ((ArrSizeHelper*)arr)->SetAt(i, pElement);
}
}  // namespace fnv_00a55ef0

// Calls the virtual function at vtable offset 0xb0 on p and returns its bool result.
// @fnv 0x00a55a60
// pdb: NiBlendPoint3Interpolator::InterpolatorIsCorrectType | NiBlendPoint3Interpolator.obj | fnv360_0721_retail, objrun_open, low
// pdb params: pkInterpolator
bool __stdcall FUN_00a55a60(NiBlendPoint3Interpolator* p)
{
    return reinterpret_cast<bool(__thiscall*)(NiObject*)>(*reinterpret_cast<const unsigned int*>(
        reinterpret_cast<const unsigned char*>(*reinterpret_cast<const unsigned int*>(p)) + 0xb0))(p);
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
void __fastcall FUN_00a36890(void*);
extern int DAT_0109a49c;
extern int _DAT_011a9424;
extern int _DAT_011a9428;
extern int _DAT_011a942c;
// @fnv 0x00a55a80
// pdb: NiBlendPoint3Interpolator::CreateObject | NiBlendPoint3Interpolator.obj | fnv360_1110_retail, objopen_prop, low
void* FUN_00a55a80()
{
    void* p = BSFadeNode::operator new(64);
    if (p)
    {
        FUN_00a36890(p);
        *(void**)p = (void*)&DAT_0109a49c;
        NiBlendPoint3Interpolator* pkInterp = (NiBlendPoint3Interpolator*)p;
        *(int*)&pkInterp->m_kPoint3Value.x = _DAT_011a9424;
        *(int*)&pkInterp->m_kPoint3Value.y = _DAT_011a9428;
        *(int*)&pkInterp->m_kPoint3Value.z = _DAT_011a942c;
        pkInterp->m_bValidValue = 0;
        return p;
    }
    return 0;
}

struct FUN_00a37ec0_tgt
{
    void FUN_00a37ec0(NiStream&);
};
struct NiColorSaveHelper
{
    void SaveBinary(NiStream&);
};
struct FUN_00a37ec0_shell : public NiBlendPoint3Interpolator
{
    void FUN_00a55ad0(NiStream& stream);
};
// @fnv 0x00a55ad0
// pdb: TESLevItem::SaveGame | TESLevItem.obj | fnv360_0822_retail, vtable, medium
// pdb params: apSaveGameBuffer
void FUN_00a37ec0_shell::FUN_00a55ad0(NiStream& stream)
{
    ((FUN_00a37ec0_tgt*)this)->FUN_00a37ec0(stream);
    ((NiColorSaveHelper*)&m_kPoint3Value)->SaveBinary(stream);
}

void __fastcall DestroyInterpolatorArray(void*);
void __cdecl _delete(void*, unsigned int);
struct Cls_00a55b00
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls DestroyInterpolatorArray on this, frees this with _delete when bit 0 of f is set, and returns this.
// @fnv 0x00a55b00
// pdb: NiMultiTargetTransformController::`scalar deleting destructor' | NiMultiTargetTransformController.obj | fnv360_0822_retail, caller_sim, low
void* Cls_00a55b00::DestroyIfFlagged(unsigned int auiFlags)
{
    DestroyInterpolatorArray(this);
    if (auiFlags & 1)
        _delete(this, 0x40);
    return this;
}

struct CloningProcess;
struct CloneOwner
{
    void FUN_00a37510(void*, void*);
};
struct FUN_00a55b20_shell : public NiBlendPoint3Interpolator
{
    void* NiBlendPoint3Interpolator_CreateClone(CloningProcess*);
};
// Allocates a NiBlendPoint3Interpolator, initialises it, copies the point3 fields and flag from this, and returns the clone.
// @fnv 0x00a55b20
// pdb: NiBlendPoint3Interpolator::CreateClone | NiBlendPoint3Interpolator.obj | fnv360_0721_retail, objrun + bridge(vtable|objrun) + skyrim(caller_sim), high
void* FUN_00a55b20_shell::NiBlendPoint3Interpolator_CreateClone(CloningProcess* kCloning)
{
    NiBlendPoint3Interpolator* pkObject = static_cast<NiBlendPoint3Interpolator*>(BSFadeNode::operator new(0x40));
    if (pkObject)
    {
        FUN_00a36890(pkObject);
        *reinterpret_cast<void**>(pkObject) = &DAT_0109a49c;
        *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.x) = _DAT_011a9424;
        *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.y) = _DAT_011a9428;
        *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.z) = _DAT_011a942c;
        pkObject->m_bValidValue = 0;
    }
    else
    {
        pkObject = 0;
    }
    reinterpret_cast<CloneOwner*>(this)->FUN_00a37510(pkObject, kCloning);
    *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.x) = *reinterpret_cast<int*>(&m_kPoint3Value.x);
    *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.y) = *reinterpret_cast<int*>(&m_kPoint3Value.y);
    *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.z) = *reinterpret_cast<int*>(&m_kPoint3Value.z);
    pkObject->m_bValidValue = m_bValidValue;
    return pkObject;
}

extern int DAT_0109a49c;

struct FUN_00a370b0_tgt
{
    void Init(void* a, float f, void* c);
};

struct FUN_00a55a10
{
    int m_vptr;
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
    NiPoint3 m_kPoint3Value;
    bool m_bValidValue;  // src: FNV360_PDB +0x3C (old: m_bValueValid)

    FUN_00a55a10(void* a, float f, void* c);
};

// @fnv 0x00a55a10
// pdb: NiBlendPoint3Interpolator::NiBlendPoint3Interpolator | NiBlendPoint3Interpolator.obj | fnv360_1110_retail, objrun_open, medium
// pdb params: bManagerControlled, fWeightThreshold, ucArraySize
FUN_00a55a10::FUN_00a55a10(void* apArg, float f, void* c)
{
    ((FUN_00a370b0_tgt*)this)->Init(apArg, f, c);
    m_vptr = reinterpret_cast<int>(&DAT_0109a49c);
    m_kPoint3Value = DAT_011a9424;
    m_bValidValue = false;
}

struct FUN_00a37980_tgt
{
    void FUN_00a37980(NiObjectNET* p);
};
struct FUN_00a59be0_tgt
{
    void FUN_00a59be0(NiObjectNET* p);
};
struct FUN_00a55e60_cls : public NiBlendPoint3Interpolator
{
    void FUN_00a55e60(NiObjectNET* p);
};
// @fnv 0x00a55e60
// pdb: NiBlendPoint3Interpolator::LoadBinary | NiBlendPoint3Interpolator.obj | fnv360_0822_retail, caller_sim, low
// pdb params: kStream
void FUN_00a55e60_cls::FUN_00a55e60(NiObjectNET* apObject)
{
    ((FUN_00a37980_tgt*)this)->FUN_00a37980(apObject);
    NiPoint3* pt = &m_kPoint3Value;
    ((FUN_00a59be0_tgt*)pt)->FUN_00a59be0(apObject);
    if (pt->x != DAT_011a9424.x || pt->y != DAT_011a9424.y || pt->z != DAT_011a9424.z)
    {
        m_bValidValue = true;
    }
}

class NiBlendInterpolator__InterpArrayItem
{
  public:
    NiInterpolator* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    int m_iValueAt14;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};
extern const NiPoint3 DAT_011f426c;
struct BlendPointShell : NiBlendPoint3Interpolator
{
    static NiPoint3& Add(NiPoint3& a, const NiPoint3& b)
    {
        a.x = b.x + a.x;
        float* pa = &a.x;
        pa[1] += b.y;
        pa[2] += b.z;
        return a;
    }
    bool GetTime(unsigned char index, float& time)
    {
        NiBlendInterpolator__InterpArrayItem& item = m_pkInterpArray[index];
        if (!item.m_spControllerInterpolator || item.m_fNormalizedWeight == 0.0f)
            return false;
        if (m_uFlags & 1)
            time = item.m_fLastEvaluationTime;
        return time != DAT_0109696c;
    }
    bool FUN_00a55c30(float time, NiObjectNET* target, NiPoint3& value);
};
// Blends successful controller values using normalized weights, adjusts for skipped weights, and writes the result to value.
// @fnv 0x00a55c30
// pdb: NiBlendPoint3Interpolator::BlendValues | NiBlendPoint3Interpolator.obj | fnv360_0721_retail, objrun, medium
// pdb params: fTime, pkInterpTarget, kValue
bool BlendPointShell::FUN_00a55c30(float time, NiObjectNET* target, NiPoint3& value)
{
    float weight = 1.0f;
    m_bValidValue = false;
    m_kPoint3Value = DAT_011f426c;
    for (unsigned char i = 0; i < m_ucArraySize; ++i)
    {
        NiBlendInterpolator__InterpArrayItem& item = m_pkInterpArray[i];
        if (item.m_spControllerInterpolator && item.m_fNormalizedWeight > 0.0f)
        {
            float updateTime = time;
            if (!GetTime(i, updateTime))
            {
                weight -= item.m_fNormalizedWeight;
                continue;
            }
            NiPoint3 tempPoint;
            if (item.m_spControllerInterpolator->Update(updateTime, target, tempPoint))
            {
                float w = m_pkInterpArray[i].m_fNormalizedWeight;
                NiPoint3 scaledPoint;
                scaledPoint.x = tempPoint.x * w;
                scaledPoint.y = tempPoint.y * w;
                scaledPoint.z = tempPoint.z * w;
                Add(m_kPoint3Value, scaledPoint);
                m_bValidValue = true;
            }
            else
                weight -= m_pkInterpArray[i].m_fNormalizedWeight;
        }
    }
    if (!m_bValidValue)
    {
        m_kPoint3Value = DAT_011a9424;
        value = m_kPoint3Value;
        return false;
    }
    float inverseWeight = 1.0f / weight;
    m_kPoint3Value *= inverseWeight;
    value = m_kPoint3Value;
    return true;
}
