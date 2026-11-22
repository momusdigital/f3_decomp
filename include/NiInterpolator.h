// NiInterpolator: the base of every interpolator; Update computes a value of one type at a time.
// Names: FNV360_PDB (NiInterpolator, 0822 retail/debug). Vtable: 55 slots, checked against F3_EXE's NiInterpolator
// vtable 0x00e312f4 (55 slots). Visual C++ lays out the Update overloads in the reverse of their declaration order
// (slots 35-40: NiQuatTransform, NiColorA, NiPoint3, NiQuaternion, float, bool).
#ifndef FNV_NIINTERPOLATOR_H
#define FNV_NIINTERPOLATOR_H
#include "layout_support.h"
#include "NiObject.h"
class NiAVObjectPalette;
class NiBoolInterpolator;
class NiColorA;
class NiObjectNET;
class NiPoint3;
class NiQuatTransform;
class NiQuaternion;
#pragma pack(push, 4)
class NiInterpolator : public NiObject
{
  public:
    virtual ~NiInterpolator();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);

    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, bool& bValue);             // 40
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, float& fValue);            // 39
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuaternion& kValue);     // 38
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue);         // 37
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiColorA& kValue);         // 36
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);  // 35
    virtual bool IsBoolValueSupported() const;                                               // 41
    virtual bool IsFloatValueSupported() const;                                              // 42
    virtual bool IsQuaternionValueSupported() const;                                         // 43
    virtual bool IsPoint3ValueSupported() const;                                             // 44
    virtual bool IsColorAValueSupported() const;                                             // 45
    virtual bool IsTransformValueSupported() const;                                          // 46
    virtual void Collapse();                                                                 // 47
    virtual void GetActiveTimeRange(float& fBeginKeyTime, float& fEndKeyTime) const;         // 48
    virtual void GuaranteeTimeRange(float fStartTime, float fEndTime);                       // 49
    virtual NiInterpolator* GetSequenceInterpolator(float fStartTime, float fEndTime);       // 50
    virtual bool ResolveDependencies(NiAVObjectPalette* pkPalette);                          // 51
    virtual bool SetUpDependencies();                                                        // 52
    virtual bool AlwaysUpdate() const;                                                       // 53
    virtual NiBoolInterpolator* IsNiBoolInterpolator();                                      // 54

    void CopyMembers(NiInterpolator* pkDest, NiCloningProcess& kCloning);

    float m_fLastTime;  // +0x8

    static const NiRTTI ms_RTTI;
    static const unsigned char INVALID_BOOL;
    static const float INVALID_FLOAT;
    static const NiQuaternion INVALID_QUATERNION;
    static const NiPoint3 INVALID_POINT3;
    static const NiColorA INVALID_COLORA;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiInterpolator) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiInterpolator, m_fLastTime) == 0x8);
#endif
