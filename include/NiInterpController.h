// NiInterpController: a time controller driven by one or more interpolators.
// Names: FNV360_PDB (NiInterpController, 0822 retail). Vtable: 58 slots, checked against F3_EXE's NiInterpController vtable 0x00e2cc54 (58 slots).
#ifndef FNV_NIINTERPCONTROLLER_H
#define FNV_NIINTERPCONTROLLER_H
#include "layout_support.h"
#include "NiTimeController.h"
class NiBlendInterpolator;
class NiFixedString;
class NiInterpolator;
class NiUpdateData;
#pragma pack(push, 4)
class NiInterpController : public NiTimeController
{
  public:
    virtual ~NiInterpController();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
    virtual void Update(NiUpdateData&) = 0;

    virtual unsigned short GetInterpolatorCount() const = 0;                                 // 45
    virtual const char* GetInterpolatorID(unsigned short) = 0;                               // 46
    virtual unsigned short GetInterpolatorIndex(const char*) const = 0;                      // 47
    virtual unsigned short GetInterpolatorIndexFx(const NiFixedString&) const = 0;           // 48
    virtual NiInterpolator* GetInterpolator(unsigned short) const = 0;                       // 49
    virtual void SetInterpolator(NiInterpolator*, unsigned short) = 0;                       // 50
    virtual void ResetTimeExtrema();                                                         // 51
    virtual const char* GetCtlrID();                                                         // 52
    virtual NiInterpolator* CreatePoseInterpolator(unsigned short) = 0;                      // 53
    virtual void SynchronizePoseInterpolator(NiInterpolator*, unsigned short) = 0;           // 54
    virtual NiBlendInterpolator* CreateBlendInterpolator(unsigned short, bool, bool, float, unsigned char) const = 0; // 55
    virtual void GuaranteeTimeRange(float, float) = 0;                                       // 56
    virtual bool InterpolatorIsCorrectType(NiInterpolator*, unsigned short) const = 0;       // 57

    void CopyMembers(NiInterpController* pkDest, NiCloningProcess& kCloning);

    static const NiRTTI ms_RTTI;
    static const unsigned short INVALID_INDEX;
    static const float INVALID_TIME;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiInterpController) == 0x34);
#endif
