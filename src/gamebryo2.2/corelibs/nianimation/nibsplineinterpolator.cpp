// gamebryo2.2/corelibs/nianimation/nibsplineinterpolator.cpp: NiBSplineInterpolator (10 functions)
#include "f3_common.h"
#include "NiBSplineBasisData.h"
#include "NiBSplineData.h"
#include "NiBSplineInterpolator.h"
#include "NiStream.h"
#include "NiViewerStrings.h"

// Loads the interpolator base data, reads start and end times from the stream, and assigns both spline objects from the stream.
// @fnv 0x00a58080
// pdb: NiBSplineInterpolator::LoadBinary | NiBSplineInterpolator.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void NiBSplineInterpolator::LoadBinary(NiStream& kStream)
{
    NiInterpolator::LoadBinary(kStream);
    NiStreamLoadBinary(kStream, m_fStartTime);
    NiStreamLoadBinary(kStream, m_fEndTime);
    m_spData = (NiBSplineData*)kStream.ResolveLinkID();
    m_spBasisData = (NiBSplineBasisData*)kStream.ResolveLinkID();
}

struct FUN_00a57f70_shell : public NiBSplineInterpolator
{
    void* FUN_00a57f70();
};

extern "C" const char* g_011f3fe4_arg1;

// @fnv 0x00a57f70
// pdb: MagicShaderHitEffect::GetRTTI | MagicShaderHitEffect.obj | fnv360_0822_retail, vtable, low
void* FUN_00a57f70_shell::FUN_00a57f70()
{
    return &g_011f3fe4_arg1;
}

// @fnv 0x00a57e50
// pdb: NiBSplineInterpolator::RegisterStreamables | NiBSplineInterpolator.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: kStream
bool NiBSplineInterpolator::RegisterStreamables(NiStream& kStream)
{
    if (!NiInterpolator::RegisterStreamables(kStream))
        return false;
    if (m_spData)
        m_spData->RegisterStreamables(kStream);
    if (m_spBasisData)
        m_spBasisData->RegisterStreamables(kStream);
    return true;
}

void __fastcall FUN_00a57f80(void*);
void __cdecl _delete(void*, unsigned int);
struct FUN_00a581e0_shell
{
    void* FUN_00a581e0(unsigned int);
};
// Calls FUN_00a57f80 on this, deletes this with size 0x1c when bit 0 of a1 is set, and returns this.
// @fnv 0x00a581e0
// pdb: ImageSpaceModifierInstance::`scalar deleting destructor' | ImageSpaceModifierInstance.obj | fnv360_0822_retail, vtable, high
void* FUN_00a581e0_shell::FUN_00a581e0(unsigned int auiFlags)
{
    FUN_00a57f80(this);
    if (auiFlags & 1)
        _delete(this, 0x1c);
    return this;
}

extern double DAT_010231b0;
extern double DAT_010241b0;
struct FUN_00a57d60_holder
{
    char _pad[12];
    float _st;
    float _en;
    void FUN_00a57d60(float&, float&);
};
// @fnv 0x00a57d60
// pdb: NiBSplineInterpolator::GetActiveTimeRange | NiBSplineInterpolator.obj | tesv_win, hash, low
void FUN_00a57d60_holder::FUN_00a57d60(float& fBegin, float& m_fEndValue)
{
    if (fBegin == DAT_010231b0 && m_fEndValue == DAT_010241b0)
        m_fEndValue = fBegin = 0.0f;
    else
    {
        fBegin = _st;
        m_fEndValue = _en;
    }
}

// The size in bytes of one channel's control points: 16-bit when compressed, floats otherwise.
// @fnv 0x00a57da0
// pdb: NiBSplineInterpolator::GetAllocatedSize | NiBSplineInterpolator.obj | fnv360_0822_retail, objrun_open, low
// pdb params: usChannel
unsigned int NiBSplineInterpolator::GetAllocatedSize(unsigned short usChannel) const
{
    if (UsesCompressedControlPoints())
        return GetDimension(usChannel) * GetControlPointCount(usChannel) * sizeof(short);
    return GetDimension(usChannel) * GetControlPointCount(usChannel) * sizeof(float);
}

// @fnv 0x00a57e00
// pdb: NiBSplineInterpolator::GetControlPointCount | NiBSplineInterpolator.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: usChannel
unsigned int NiBSplineInterpolator::GetControlPointCount(unsigned short usChannel) const
{
    if (usChannel < GetChannelCount() && m_spData)
    {
        if (GetControlHandle(usChannel) != NiBSplineData::INVALID_HANDLE)
            return m_spBasisData->GetDegree3Basis().GetQuantity();
    }
    return 0;
}

// Shipped as Gamebryo wrote it: equal times return true before the data is compared, and the comparison of the data
// and the basis falls through to false.
// @fnv 0x00a57e90
// pdb: NiBSplineInterpolator::IsEqual | NiBSplineInterpolator.obj | fnv360_0822_retail, caller_sim + bridge(vtable|objrun_prop) + skyrim(call_seq), high
bool NiBSplineInterpolator::IsEqual(NiObject* pkOther)
{
    if (!NiInterpolator::IsEqual(pkOther))
        return false;
    NiBSplineInterpolator* pkInterp = (NiBSplineInterpolator*)pkOther;
    if (m_fStartTime == pkInterp->m_fStartTime && m_fEndTime == pkInterp->m_fEndTime)
        return true;
    if ((m_spData && !pkInterp->m_spData) || (!m_spData && pkInterp->m_spData))
        return false;
    if (m_spData && !m_spData->IsEqual(pkInterp->m_spData))
        return false;
    if ((m_spBasisData && !pkInterp->m_spBasisData) || (!m_spBasisData && pkInterp->m_spBasisData))
        return false;
    if (m_spBasisData && !m_spBasisData->IsEqual(pkInterp->m_spBasisData))
        return false;
    return false;
}

// @fnv 0x00a58160
// pdb: NiBSplineInterpolator::SaveBinary | NiBSplineInterpolator.obj | fnv360_0721_beta, call_seq, high
// pdb params: kStream
void NiBSplineInterpolator::SaveBinary(NiStream& kStream)
{
    NiInterpolator::SaveBinary(kStream);
    NiStreamSaveBinary(kStream, m_fStartTime);
    NiStreamSaveBinary(kStream, m_fEndTime);
    kStream.SaveLinkID(m_spData);
    kStream.SaveLinkID(m_spBasisData);
}

// @fnv 0x00a58200
// pdb: NiBSplineInterpolator::GetViewerStrings | NiBSplineInterpolator.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void NiBSplineInterpolator::GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings)
{
    NiInterpolator::GetViewerStrings(pkStrings);
    pkStrings->Add(NiGetViewerString(ms_RTTI.GetName()));
    pkStrings->Add(NiGetViewerString("m_fStartTime", m_fStartTime));
    pkStrings->Add(NiGetViewerString("m_fEndTime", m_fEndTime));
    if (m_spData)
        m_spData->GetViewerStrings(pkStrings);
    if (m_spBasisData)
        m_spBasisData->GetViewerStrings(pkStrings);
}
