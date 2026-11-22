#include "f3_common.h"
// src/gamebryo2.2/corelibs/nianimation/nilightdimmercontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nilightdimmercontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" char __stdcall FUN_00a57c10(void* a);

// @fnv 0x00a4cf50
// pdb: NiAlphaAccumulator::IsEqual | NiAlphaAccumulator.obj | fnv360_0822_retail, objrun + bridge(vtable|objrun) + skyrim(caller_sim), high
char __stdcall NiAlphaAccumulator_IsEqual(void* pThis)
{
    return FUN_00a57c10(pThis) != 0;
}

struct NiLight
{
    float m_uiFilterValue;  // at offset 0xc4
};

struct NiLightDimmerController
{
    void GetLightDimmer(float& fValue);
};

// @fnv 0x00a4cf70
// pdb: NiLightDimmerController::GetTargetFloatValue | NiLightDimmerController.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: fValue
void NiLightDimmerController::GetLightDimmer(float& fValue)
{
    NiLight* apTargetLight = *reinterpret_cast<NiLight**>(reinterpret_cast<char*>(this) + 0x2c);
    if (apTargetLight)
    {
        fValue = *reinterpret_cast<float*>(reinterpret_cast<char*>(apTargetLight) + 0xc4);
    }
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiFloatInterpController
{
    NiFloatInterpController();
};
extern int DAT_01098ccc;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// @fnv 0x00a4d0d0
// pdb: NiLightDimmerController::CreateObject | NiLightDimmerController.obj | fnv360_0822_retail, objopen_prop, low
void* FUN_00a4d0d0()
{
    void* p = BSFadeNode::operator new(0x38);
    if (p)
    {
        new (p) NiFloatInterpController();
        *(void**)p = &DAT_01098ccc;
        return p;
    }
    return 0;
}

template <typename T> struct NiTMallocInterface
{
};
template <typename T, typename A> struct NiTPrimitiveArray
{
    char _pad[8];
    unsigned short m_pRayCursor;
    unsigned short m_iElementCount;
    unsigned short _pad2;
    unsigned short m_grow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);

struct FloatInterpOwner
{
    void FUN_00a57620(void* obj, int arg);
    void* CreateFloatInterpController(int arg);
};

// @fnv 0x00a4d080
// pdb: NiLightDimmerController::CreateClone | NiLightDimmerController.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: kCloning
void* FloatInterpOwner::CreateFloatInterpController(int arg)
{
    NiFloatInterpController* obj = (NiFloatInterpController*)FUN_00aa13e0(0x38);
    if (obj != 0)
    {
        obj->NiFloatInterpController::NiFloatInterpController();
        *(int*)obj = (int)&DAT_01098ccc;
    }
    else
    {
        obj = 0;
    }
    FUN_00a57620(obj, arg);
    return obj;
}

extern const float DAT_01096324;

class NiLightW
{
  public:
    char m_pad00[0xa8];
    unsigned int m_uiRevID;
    char m_padac[0x18];
    float m_fDimmer;

    void SetDimmer(float fDimmer)
    {
        m_fDimmer = fDimmer;
        m_uiRevID++;
    }
};

class NiInterpolatorW
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual bool Update(float fTime, void* pkInterpTarget, float& fValue);
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual bool AlwaysUpdate();
};

class NiLightDimmerControllerW
{
  public:
    void* m_vtbl;
    int m_unk04;
    unsigned short m_uiObjectFlags;
    char m_pad0a[0x1e];
    float m_fControllerTime;
    void* m_pkTarget;
    int m_unk30;
    NiInterpolatorW* m_spControllerInterpolator;

    bool GetManagerControlled() const
    {
        return ((m_uiObjectFlags >> 5) & 1) != 0;
    }
    bool NiTimeController_DontDoUpdate(float fTime);
    void NiLightDimmerController_Update(const float& fTime);
};

// @f3 0x008c6ee0 (community match, verified in this file)
extern int DAT_0108f41c;
void* __cdecl FUN_00424d50(const void* pkType, void* pkObject);
// pdb: NiLightDimmerController::Update | NiLightDimmerController.obj | fnv360_0822_retail, caller_sim, high
// pdb params: UpdateData
// pdb: NiLightDimmerController::Update | NiLightDimmerController.obj | fnv360_0822_retail, caller_sim, high (was: UpdateDimmer)
void NiLightDimmerControllerW::NiLightDimmerController_Update(const float& fTime)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = DAT_01096324;
    }
    else if (NiTimeController_DontDoUpdate(fTime) && (!m_spControllerInterpolator || !m_spControllerInterpolator->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator)
    {
        float fValue;
        if (m_spControllerInterpolator->Update(m_fControllerTime, m_pkTarget, fValue))
        {
            if (m_pkTarget)
            {
                NiLightW* pkLight =
                    (NiLightW*)FUN_00424d50(&DAT_0108f41c, m_pkTarget);
                pkLight->SetDimmer(fValue);
            }
        }
    }
}


extern void FUN_00a57c70();

// @fnv 0x00a4cf40
// pdb: BGSTerrainManager::ShowMinimumDetail | BGSTerrainManager.obj | fnv360_0822_retail, call_gap, low
void FUN_00a4cf40()
{
    FUN_00a57c70();
}

#include <windows.h>
extern int DAT_01098ccc;

struct a4d030_Counted
{
    virtual void v00();
    virtual void Release();
    int refCount;
};

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00a4d030_cls
{
    int m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    a4d030_Counted* m_pCounted;

    void BaseCleanup();
    FUN_00a4d030_cls* FUN_00a4d030(unsigned char acFlags);
};

// Decrements m_pCounted's reference count and calls Release at zero, then runs BaseCleanup and calls FUN_00aa1460 when bit 0 is set.
// @fnv 0x00a4d030
// pdb: NiLightDimmerController::`scalar deleting destructor' | NiLightDimmerController.obj | fnv360_0822_retail, objopen_prop, low
FUN_00a4d030_cls* FUN_00a4d030_cls::FUN_00a4d030(unsigned char acFlags)
{
    *(volatile int*)&m_vptr = (int)&DAT_01098ccc;
    a4d030_Counted* pCounted = *(a4d030_Counted* volatile*)&m_pCounted;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->refCount) == 0)
        {
            pCounted->Release();
        }
    }
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x38);
    }
    return this;
}
