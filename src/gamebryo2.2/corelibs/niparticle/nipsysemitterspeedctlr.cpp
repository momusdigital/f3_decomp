// src/gamebryo2.2/corelibs/niparticle/nipsysemitterspeedctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterspeedctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiPSysModifierFloatCtlr
{
    float m_fValue;
};

struct NiPSysEmitterSpeedCtlr
{
    void FUN_00c2b370(float& rfValue);
};

// @fnv 0x00c2b370
// pdb: NiPSysInitialRotSpeedCtlr::GetTargetFloatValue | NiPSysInitialRotSpeedCtlr.obj | tesv_win, objrun_open, low
void NiPSysEmitterSpeedCtlr::FUN_00c2b370(float& rfValue)
{
    NiPSysModifierFloatCtlr* pkTarget = *(NiPSysModifierFloatCtlr**)(this + 0x3c);
    rfValue = *(float*)((char*)pkTarget + 0x18);
}

namespace fnv_00c29fa0 {
struct NiPSysModifierFloatCtlr
{
    char pad[0x18];
    float m_fTarget;
};

struct NiPSysEmitterSpeedCtlr
{
    char pad[0x3c];
    NiPSysModifierFloatCtlr* m_pFloatCtlr;
    void FUN_00c29fa0(float fValue);
};

// @fnv 0x00c29fa0
// pdb: NiPSysAirFieldAirFrictionCtlr::GetTargetFloatValue | NiPSysAirFieldAirFrictionCtlr.obj | fnv360_0721_retail, objrun_open, low, conflict (skyrim: NiPSysInitialRotSpeedCtlr::SetTargetFloatValue)
// pdb params: fValue
void NiPSysEmitterSpeedCtlr::FUN_00c29fa0(float fValue)
{
    m_pFloatCtlr->m_fTarget = fValue;
}
}  // namespace fnv_00c29fa0

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
extern char DAT_010bf654[];

struct CtorBase_cls
{
    void ctorBase();
};

struct FUN_00c2b380_cls
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_00c32de0(void* obj, unsigned int a1);
    void* FUN_00c2b380(unsigned int a1);
};

// Allocates a 0x40-byte object, runs its base constructor and sets its vtable, then passes it to FUN_00c32de0 with a1 and returns it.
// @fnv 0x00c2b380
// pdb: NiPSysEmitterSpeedCtlr::CreateClone | NiPSysEmitterSpeedCtlr.obj | tesv_win, caller_sim, low
void* FUN_00c2b380_cls::FUN_00c2b380(unsigned int a1)
{
    FUN_00c2b380_cls* p = (FUN_00c2b380_cls*)FUN_00aa13e0(0x40);
    if (p != 0)
    {
        ((CtorBase_cls*)p)->ctorBase();
        p->m_vtbl = (void*)&DAT_010bf654;
    }
    else
    {
        p = 0;
    }
    this->FUN_00c32de0(p, a1);
    return p;
}
