#include "f3_common.h"
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterplanaranglectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterplanaranglectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiPSysModifierFloatCtlr
{
};
struct NiPSysEmitterPlanarAngleCtlr : NiPSysModifierFloatCtlr
{
    void FUN_00c2b560(float& fValue);
};

// @fnv 0x00c2b560
void NiPSysEmitterPlanarAngleCtlr::FUN_00c2b560(float& fValue)
{
    fValue = *(float*)((char*)*(void**)((char*)this + 0x3c) + 0x28);
}

struct PlanarAngleControllerData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    float unk28;
};
struct FUN_00c2b570_class : NiPSysEmitterPlanarAngleCtlr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    PlanarAngleControllerData* unk3C;
    void __thiscall FUN_00c2b570(float fValue);
};
// @fnv 0x00c2b570
void __thiscall FUN_00c2b570_class::FUN_00c2b570(float fValue)
{
    unk3C->unk28 = fValue;
}

void* __cdecl FUN_00aa13e0(unsigned int);

struct S_00c2b580_Base
{
    S_00c2b580_Base() throw();
    virtual void vfn_00();
};

struct S_00c2b580_TargetObj : S_00c2b580_Base
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void*, unsigned int) throw()
    {}
    S_00c2b580_TargetObj() throw()
    {}
};

struct S_00c2b580
{
    void __thiscall FUN_00c32de0(void* obj, void* arg);
    void* __thiscall CreateTargetObj(void* arg);
};

// Allocates a S_00c2b580_TargetObj, initializes it via FUN_00c32de0 with arg, and returns it.
// @fnv 0x00c2b580
// pdb: NiPSysEmitterPlanarAngleCtlr::CreateClone | NiPSysEmitterPlanarAngleCtlr.obj | tesv_win, caller_sim, low
void* __thiscall S_00c2b580::CreateTargetObj(void* arg)
{
    S_00c2b580_TargetObj* obj = new S_00c2b580_TargetObj();
    FUN_00c32de0(obj, arg);
    return obj;
}
