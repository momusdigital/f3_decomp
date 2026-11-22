// NiTimeController: a controller that animates a target object over time; controllers of one target form a list (m_spNext).
// Names: FNV360_PDB (NiTimeController, 0822 retail). Vtable: 45 slots, checked against F3_EXE's NiTimeController vtable 0x00e22014 (45 slots).
#ifndef FNV_NITIMECONTROLLER_H
#define FNV_NITIMECONTROLLER_H
#include "layout_support.h"
#include "NiObject.h"
class NiObjectNET;
class NiUpdateData;
#pragma pack(push, 4)
class NiTimeController : public NiObject
{
  public:
    enum AnimType
    {
        APP_TIME = 0,
        APP_INIT = 1,
    };

    enum CycleType
    {
        LOOP = 0,
        REVERSE = 1,
        CLAMP = 2,
        MAX_CYCLE_TYPES = 3,
    };

    enum
    {
        MAX_POS = 5,
    };

    virtual ~NiTimeController();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
    virtual void ProcessClone(NiCloningProcess& kCloning);

    virtual void Start(float fTime);                                                         // 35
    virtual void Stop();                                                                     // 36
    virtual void Update(NiUpdateData&) = 0;                                                  // 37
    virtual void SetTarget(NiObjectNET* pkTarget);                                           // 38
    virtual bool IsTransformController() const;                                              // 39
    virtual bool IsVertexController() const;                                                 // 40
    virtual float ComputeScaledTime(float fTime);                                            // 41
    virtual void OnPreDisplay();                                                             // 42
    virtual bool IsStreamable() const;                                                       // 43
    virtual bool TargetIsRequiredType() const = 0;                                           // 44

    unsigned short m_uFlags;                       // +0x8
    float m_fFrequency;                            // +0xC
    float m_fPhase;                                // +0x10
    float m_fLoKeyTime;                            // +0x14
    float m_fHiKeyTime;                            // +0x18
    float m_fStartTime;                            // +0x1C
    float m_fLastTime;                             // +0x20
    float m_fWeightedLastTime;                     // +0x24
    float m_fScaledTime;                           // +0x28
    NiObjectNET* m_pkTarget;                       // +0x2C
    NiPointer<NiTimeController> m_spNext;          // +0x30

    void CopyMembers(NiTimeController* pkDest, NiCloningProcess& kCloning);

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTimeController) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_uFlags) == 0x8);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fFrequency) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fPhase) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fLoKeyTime) == 0x14);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fHiKeyTime) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fStartTime) == 0x1C);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fLastTime) == 0x20);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fWeightedLastTime) == 0x24);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fScaledTime) == 0x28);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_pkTarget) == 0x2C);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_spNext) == 0x30);
#endif
