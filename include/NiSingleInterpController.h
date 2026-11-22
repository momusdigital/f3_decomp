// NiSingleInterpController: an interp controller driven by a single interpolator.
// Names: FNV360_PDB (NiSingleInterpController, 0822 retail). Vtable: 59 slots, checked against F3_EXE's NiSingleInterpController vtable 0x00e2d564 (59 slots).
#ifndef FNV_NISINGLEINTERPCONTROLLER_H
#define FNV_NISINGLEINTERPCONTROLLER_H
#include "layout_support.h"
#include "NiInterpController.h"
class NiFixedString;
class NiInterpolator;
class NiObjectNET;
#pragma pack(push, 4)
class NiSingleInterpController : public NiInterpController
{
  public:
    virtual ~NiSingleInterpController();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
    virtual void ProcessClone(NiCloningProcess& kCloning);
    virtual bool TargetIsRequiredType() const;
    virtual unsigned short GetInterpolatorCount() const;
    virtual const char* GetInterpolatorID(unsigned short usIndex);
    virtual unsigned short GetInterpolatorIndex(const char* pcID) const;
    virtual unsigned short GetInterpolatorIndexFx(const NiFixedString& arName) const;
    virtual NiInterpolator* GetInterpolator(unsigned short usIndex) const;
    virtual void SetInterpolator(NiInterpolator* pkInterpolator, unsigned short usIndex);
    virtual void ResetTimeExtrema();
    virtual void GuaranteeTimeRange(float fStartTime, float fEndTime);

    virtual bool InterpTargetIsCorrectType(NiObjectNET*) const = 0;                          // 58

    NiPointer<NiInterpolator> m_spInterpolator;    // +0x34

    void CopyMembers(NiSingleInterpController* pkDest, NiCloningProcess& kCloning);

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiSingleInterpController) == 0x38);
FNV_STATIC_ASSERT(offsetof(NiSingleInterpController, m_spInterpolator) == 0x34);
#endif
