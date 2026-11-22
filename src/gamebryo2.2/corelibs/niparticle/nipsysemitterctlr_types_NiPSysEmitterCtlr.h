// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPSYSEMITTERCTLR_H
#define FNV_NIPSYSEMITTERCTLR_H
#include "f3_common.h"
#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
#include "NiObjectNET.h"
#include "NiSingleInterpController.h"
#include "NiInterpolator.h"
#include "layout_support.h"
class NiInterpController;
class NiInterpolator;
class NiFloatData;
class NiCloningProcess;
class NiStream;
class NiPSysEmitterCtlr;
class NiPSysModifier;
class NiPSysModifierCtlr;
class NiSingleInterpController;
class NiTPrimitiveSet_float_;
class NiTSet_float_NiTMallocInterface_float___;
#pragma pack(push, 4)
class NiPSysModifierCtlr : public NiSingleInterpController
{
  public:
    // base NiSingleInterpController at +0x0, size 56
    NiFixedString m_kModifierName;  // +0x38, 4 bytes  // src: FNV360_PDB +0x38 (old: m_kTargetModifierName)
    NiPSysModifier* m_pkModifier;   // +0x3C, 4 bytes  // src: FNV360_PDB +0x3C (old: m_pkTargetModifier)
    void LoadBinary(NiStream& stream);
    void LinkObject(NiStream& stream);
    void ProcessClone(NiCloningProcess& process);
    void CopyMemberData(NiPSysModifierCtlr* destination, NiCloningProcess& process);
    // const NiRTTI* __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(NiPSysModifierCtlr*, NiCloningProcess&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // bool __cdecl NiPSysModifierCtlr::*(NiStream&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // bool __cdecl NiPSysModifierCtlr::*(NiObject*)
    // void __cdecl NiPSysModifierCtlr::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(NiObjectNET*)
    // const NiFixedString& __cdecl NiPSysModifierCtlr::*()
    // NiPSysModifier* __cdecl NiPSysModifierCtlr::*()
    // const char* __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(NiCloningProcess&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // NiPSysModifierCtlr
    // bool __cdecl NiPSysModifierCtlr::*(NiObjectNET*)
    // void __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(const NiFixedString&)
    // NiPSysModifierCtlr& __cdecl NiPSysModifierCtlr::*(const NiPSysModifierCtlr&)
    // void __cdecl NiPSysModifierCtlr::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysModifierCtlr) == 64);
FNV_STATIC_ASSERT(offsetof(NiPSysModifierCtlr, m_kModifierName) == 56);
FNV_STATIC_ASSERT(offsetof(NiPSysModifierCtlr, m_pkModifier) == 60);
#pragma pack(push, 4)
class NiPSysModifierBoolCtlr : public NiPSysModifierCtlr
{
  public:
    NiPSysModifierBoolCtlr() throw();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysModifierBoolCtlr) == 64);


class NiFloatInterpolator : public NiInterpolator
{
  public:
    NiFloatInterpolator(NiFloatData* data) throw();
    void SetAnimationKeys(void* keys, unsigned int count, unsigned int keyType);
};

class NiBoolInterpolator : public NiInterpolator
{
  public:
    NiBoolInterpolator(void* data) throw();
    void SetAnimationKeys(void* keys, unsigned int keyType, unsigned int count);
};

class NiBoolInterpController : public NiInterpolator
{
  public:
    NiBoolInterpolator* LinkObject(NiStream* stream);
};

#pragma pack(push, 4)
class NiTSet_float_NiTMallocInterface_float___
{
  public:
    float* m_pBase;                      // +0x0, 4 bytes
    unsigned int m_uiAlloced;       // +0x4, 4 bytes  // src: FNV360_PDB +0x4 (old: m_uiElementCount)
    unsigned int m_uiUsed;  // +0x8, 4 bytes  // src: FNV360_PDB +0x8 (old: m_uiAllocatedCapacity)
    // NiTSet<float,NiTMallocInterface<float> >
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // unsigned int __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // float* __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // GetAt
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int)
    // bool __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // bool __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int, const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // Realloc
    // int __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // NiTSet<float,NiTMallocInterface<float> >& __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const NiTSet<float,NiTMallocInterface<float> >&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // void* __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTSet_float_NiTMallocInterface_float___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTSet_float_NiTMallocInterface_float___, m_pBase) == 0);
FNV_STATIC_ASSERT(offsetof(NiTSet_float_NiTMallocInterface_float___, m_uiAlloced) == 4);
FNV_STATIC_ASSERT(offsetof(NiTSet_float_NiTMallocInterface_float___, m_uiUsed) == 8);
#pragma pack(push, 4)
class NiTPrimitiveSet_float_ : public NiTSet_float_NiTMallocInterface_float___
{
  public:
    // base NiTSet<float,NiTMallocInterface<float> > at +0x0, size 12
    // NiTPrimitiveSet<float>
    // void __cdecl NiTPrimitiveSet<float>::*()
    // NiTPrimitiveSet<float>& __cdecl NiTPrimitiveSet<float>::*(const NiTPrimitiveSet<float>&)
    // void __cdecl NiTPrimitiveSet<float>::*()
    // void* __cdecl NiTPrimitiveSet<float>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveSet_float_) == 12);
#pragma pack(push, 4)
class NiPSysEmitterCtlr : public NiPSysModifierCtlr
{
  public:
    static void* operator new(unsigned int size);
    // base NiPSysModifierCtlr at +0x0, size 64
    NiPointer<NiInterpolator> m_spEmitterActiveInterpolator;  // +0x40, 4 bytes  // src: FNV360_PDB +0x40 (old: m_spVisibilityInterpolator)
    NiInterpolator* m_pkLastBirthRateInterpolator;          // +0x44, 4 bytes  // src: FNV360_PDB +0x44 (old: m_pEmitterActiveInterpolator)
    float m_fLastScaledTime;                               // +0x48, 4 bytes  // src: FNV360_PDB +0x48 (old: m_fScaledLastTime)
    bool m_bLastActive;                                 // +0x4C, 1 bytes  // src: FNV360_PDB +0x4C (old: m_bIsInitialized)
    unsigned char layoutPadding4D[3];
    NiTPrimitiveSet_float_ m_kParticleAges;  // +0x50, 12 bytes  // src: FNV360_PDB +0x50 (old: m_kBirthRateKeys)
    void LoadBinary(NiStream& stream);
    void LinkObject(NiStream& stream);
    void ProcessClone(NiCloningProcess& process);
    void CopyMemberData(NiPSysEmitterCtlr* destination, NiCloningProcess& process);
    NiObject* MakeClone(NiCloningProcess& process);
    // const NiRTTI* __cdecl NiPSysEmitterCtlr::*()
    // NiObject* __cdecl NiPSysEmitterCtlr::*(NiCloningProcess&)
    // void __cdecl NiPSysEmitterCtlr::*(NiPSysEmitterCtlr*, NiCloningProcess&)
    // void __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // void __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // bool __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // void __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // bool __cdecl NiPSysEmitterCtlr::*(NiObject*)
    // NiObject* __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(NiTPrimitiveArray<char *>*)
    // NiPSysEmitterCtlr
    // void __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(NiUpdateData&)
    // NiFloatInterpolator* __cdecl NiPSysEmitterCtlr::*()
    // NiBoolInterpolator* __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(NiFloatInterpolator*)
    // void __cdecl NiPSysEmitterCtlr::*(NiBoolInterpolator*)
    // void __cdecl NiPSysEmitterCtlr::*(float, float)
    // void __cdecl NiPSysEmitterCtlr::*()
    // unsigned short __cdecl NiPSysEmitterCtlr::*()
    // const char* __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // unsigned short __cdecl NiPSysEmitterCtlr::*(const char*)
    // NiInterpolator* __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // void __cdecl NiPSysEmitterCtlr::*(NiInterpolator*, unsigned short)
    // NiInterpolator* __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // void __cdecl NiPSysEmitterCtlr::*(NiInterpolator*, unsigned short)
    // NiBlendInterpolator* __cdecl NiPSysEmitterCtlr::*(unsigned short, bool, bool, float, unsigned char)
    // void __cdecl NiPSysEmitterCtlr::*(NiCloningProcess&)
    // unsigned short __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // bool __cdecl NiPSysEmitterCtlr::*(NiInterpolator*, unsigned short)
    // bool __cdecl NiPSysEmitterCtlr::*(NiObjectNET*)
    // bool __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(float, float, float, float, float, float)
    // void __cdecl NiPSysEmitterCtlr::*()
    // NiPSysEmitterCtlr& __cdecl NiPSysEmitterCtlr::*(const NiPSysEmitterCtlr&)
    // void __cdecl NiPSysEmitterCtlr::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysEmitterCtlr) == 92);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitterCtlr, m_spEmitterActiveInterpolator) == 64);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitterCtlr, m_pkLastBirthRateInterpolator) == 68);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitterCtlr, m_fLastScaledTime) == 72);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitterCtlr, m_bLastActive) == 76);
FNV_STATIC_ASSERT(offsetof(NiPSysEmitterCtlr, m_kParticleAges) == 80);
#endif
