// NiPSysEmitter: the base of the particle emitters; EmitParticles creates particles with randomized speed, direction, color, radius and life.
// Names: FNV360_PDB (NiPSysEmitter, 0822 retail). Vtable: 43 slots, checked against F3_EXE's NiPSysEmitter vtable 0x00e8cb0c (43 slots).
#ifndef FNV_NIPSYSEMITTER_H
#define FNV_NIPSYSEMITTER_H
#include "layout_support.h"
#include "NiPSysModifier.h"
#include "NiColorA.h"
class NiPSysData;
class NiPoint3;
#pragma pack(push, 4)
class NiPSysEmitter : public NiPSysModifier
{
  public:
    virtual ~NiPSysEmitter();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
    virtual void Update(float fTime, NiPSysData* pkData);

    virtual void EmitParticles(float fTime, unsigned short usNumParticles, const float* pfAges); // 41
    virtual void ComputeInitialPositionAndVelocity(NiPoint3&, NiPoint3&) = 0;                // 42

    float m_fSpeed;                                // +0x18
    float m_fSpeedVar;                             // +0x1C
    float m_fDeclination;                          // +0x20
    float m_fDeclinationVar;                       // +0x24
    float m_fPlanarAngle;                          // +0x28
    float m_fPlanarAngleVar;                       // +0x2C
    NiColorA m_kInitialColor;                      // +0x30
    float m_fInitialRadius;                        // +0x40
    float m_fRadiusVar;                            // +0x44
    float m_fLifeSpan;                             // +0x48
    float m_fLifeSpanVar;                          // +0x4C
    float m_fScale;                                // +0x50

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysEmitter) == 0x54);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fSpeed) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fSpeedVar) == 0x1C);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fDeclination) == 0x20);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fDeclinationVar) == 0x24);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fPlanarAngle) == 0x28);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fPlanarAngleVar) == 0x2C);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_kInitialColor) == 0x30);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fInitialRadius) == 0x40);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fRadiusVar) == 0x44);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fLifeSpan) == 0x48);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fLifeSpanVar) == 0x4C);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitter, m_fScale) == 0x50);
#endif
