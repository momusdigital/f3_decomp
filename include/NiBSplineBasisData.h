// NiBSplineBasisData: the degree 3 B-spline basis shared by the curves of an NiBSplineData.
// Names: FNV360_PDB (NiBSplineBasisData, 0822 retail). Vtable: 35 slots, checked against F3_EXE's NiBSplineBasisData vtable 0x00e3094c (35 slots).
#ifndef FNV_NIBSPLINEBASISDATA_H
#define FNV_NIBSPLINEBASISDATA_H
#include "layout_support.h"
#include "NiObject.h"
#include "NiBSplineBasis.h"
#pragma pack(push, 4)
class NiBSplineBasisData : public NiObject
{
  public:
    virtual ~NiBSplineBasisData();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* CreateClone(NiCloningProcess& kCloning);
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pStrings);

    NiBSplineBasis<float, 3>& GetDegree3Basis();

    NiBSplineBasis<float, 3> m_kBasisDegree3;  // +0x8

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBSplineBasisData) == 0x28);
FNV_STATIC_ASSERT(offsetof(NiBSplineBasisData, m_kBasisDegree3) == 0x8);
#endif
