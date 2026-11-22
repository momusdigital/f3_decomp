// NiPSysModifier: one step of a particle system's update (emitter, force, collider, ...), run in m_uiOrder order.
// Names: FNV360_PDB (NiPSysModifier, 0822 retail). Vtable: 41 slots, checked against F3_EXE's NiPSysModifier vtable 0x00e8d1d4 (41 slots).
#ifndef FNV_NIPSYSMODIFIER_H
#define FNV_NIPSYSMODIFIER_H
#include "layout_support.h"
#include "NiObject.h"
#include "NiFixedString.h"
class NiPSysData;
class NiParticleSystem;
#pragma pack(push, 4)
class NiPSysModifier : public NiObject
{
  public:
    enum
    {
        ORDER_KILLOLDPARTICLES = 0,
        ORDER_EMITTER = 1000,
        ORDER_SPAWN = 2000,
        ORDER_POSTSPAWNUPDATE = 2500,
        ORDER_GENERAL = 3000,
        ORDER_FORCE = 4000,
        ORDER_COLLIDER = 5000,
        ORDER_POSUPDATE = 6000,
        ORDER_POSTPOSUPDATE = 6500,
        ORDER_BOUNDUPDATE = 7000,
    };

    virtual ~NiPSysModifier();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
    virtual void ProcessClone(NiCloningProcess& kCloning);

    virtual void Update(float, NiPSysData*) = 0;                                             // 35
    virtual void Initialize(NiPSysData* pkData, unsigned short usNewParticle);               // 36
    virtual void HandleReset();                                                              // 37
    virtual void SetActive(bool bActive);                                                    // 38
    virtual void SetSystemPointer(NiParticleSystem* pkTarget);                               // 39
    virtual bool IsBSPSysStripUpdateModifier();                                              // 40

    NiFixedString m_kName;                         // +0x8
    unsigned int m_uiOrder;                        // +0xC
    NiParticleSystem* m_pkTarget;                  // +0x10
    bool m_bActive;                                // +0x14

    static const NiRTTI ms_RTTI;
    static const float ms_fEpsilon;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysModifier) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_kName) == 0x8);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_uiOrder) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_pkTarget) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiPSysModifier, m_bActive) == 0x14);
#endif
