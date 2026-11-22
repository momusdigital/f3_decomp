// NiBSplineData: the control points of one or more B-spline curves, full or compact (16-bit).
// Names: FNV360_PDB (NiBSplineData, 0822 retail). Vtable: 35 slots, checked against F3_EXE's NiBSplineData vtable 0x00e3087c (35 slots).
#ifndef FNV_NIBSPLINEDATA_H
#define FNV_NIBSPLINEDATA_H
#include "layout_support.h"
#include "NiObject.h"
#pragma pack(push, 4)
class NiBSplineData : public NiObject
{
  public:
    enum
    {
        INVALID_HANDLE = 65535,
    };

    virtual ~NiBSplineData();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pStrings);

    float* m_pafControlPoints;                     // +0x8
    short* m_pasCompactControlPoints;              // +0xC
    unsigned int m_uiControlPointCount;            // +0x10
    unsigned int m_uiCompactControlPointCount;     // +0x14

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBSplineData) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_pafControlPoints) == 0x8);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_pasCompactControlPoints) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_uiControlPointCount) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_uiCompactControlPointCount) == 0x14);
#endif
