// NiBSplineInterpolator: the base of the interpolators that evaluate B-spline curves of control points.
// Names: FNV360_PDB (NiBSplineInterpolator, 0822 retail). Vtable: 64 slots, checked against F3_EXE's NiBSplineInterpolator vtable 0x00e3185c (64 slots).
#ifndef FNV_NIBSPLINEINTERPOLATOR_H
#define FNV_NIBSPLINEINTERPOLATOR_H
#include "layout_support.h"
#include "NiInterpolator.h"
class NiBSplineBasisData;
class NiBSplineData;
#pragma pack(push, 4)
class NiBSplineInterpolator : public NiInterpolator
{
  public:
    enum
    {
        MAXIMUM_DIMENSIONALITY = 4,
    };

    virtual ~NiBSplineInterpolator();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkOther);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
    virtual void Collapse();
    virtual void GetActiveTimeRange(float& fBeginTime, float& fEndTime) const;
    virtual void GuaranteeTimeRange(float fStartTime, float fEndTime);
    virtual NiInterpolator* GetSequenceInterpolator(float fStartTime, float fEndTime);

    virtual unsigned short GetChannelCount() const = 0;                                      // 55
    virtual unsigned int GetControlPointCount(unsigned short usChannel) const;               // 56
    virtual unsigned int GetDimension(unsigned short) const = 0;                             // 57
    virtual unsigned int GetDegree(unsigned short) const = 0;                                // 58
    virtual bool GetChannelPosed(unsigned short) const = 0;                                  // 59
    virtual bool UsesCompressedControlPoints() const;                                        // 60
    virtual unsigned int GetAllocatedSize(unsigned short usChannel) const;                   // 61
    virtual unsigned int GetControlHandle(unsigned short) const = 0;                         // 62
    virtual void SetControlHandle(unsigned int, unsigned short) = 0;                         // 63

    float m_fStartTime;                            // +0xC
    float m_fEndTime;                              // +0x10
    NiPointer<NiBSplineData> m_spData;             // +0x14
    NiPointer<NiBSplineBasisData> m_spBasisData;   // +0x18

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBSplineInterpolator) == 0x1C);
FNV_STATIC_ASSERT(offsetof(NiBSplineInterpolator, m_fStartTime) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiBSplineInterpolator, m_fEndTime) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiBSplineInterpolator, m_spData) == 0x14);
FNV_STATIC_ASSERT(offsetof(NiBSplineInterpolator, m_spBasisData) == 0x18);
#endif
