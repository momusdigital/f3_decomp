#include "f3_common.h"
// src/gamebryo2.2/corelibs/niparticle/bsstripparticlesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/bsstripparticlesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* g_01202560;

struct NiRenderer
{
    void* _vt;
    char _pad0[508];
    int m_iRendererState;
    char _pad1[4];
    bool m_bRendererFlagA;
};
struct FUN_00a80610_shell
{
    void __thiscall FUN_00a80610(NiRenderer*);
    void __thiscall FUN_00c25730(NiRenderer*);
};
// @fnv 0x00c25730
void __thiscall FUN_00a80610_shell::FUN_00c25730(NiRenderer* apkRenderer)
{
    this->FUN_00a80610(apkRenderer);
    NiRenderer* pkRenderer = apkRenderer;
    if ((pkRenderer->m_iRendererState == 1 || pkRenderer->m_iRendererState == 2) && pkRenderer->m_bRendererFlagA == 1)
        ((void(__thiscall*)(NiRenderer*, FUN_00a80610_shell*))(*(void***)pkRenderer)[112])(pkRenderer, this);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
extern unsigned int UNK_010be35c;
struct ParticleSystem
{
    unsigned int* vtable;
    void __thiscall FUN_00c1b5c0();
};
struct ParticleOwner
{
    void __thiscall FUN_00c1b6f0(ParticleSystem* object, unsigned int flags);
    ParticleSystem* __thiscall CreateParticleSystem(unsigned int flags);
};
// Allocates a 0x110-byte ParticleSystem, initialises it and its vtable, passes it to FUN_00c1b6f0 with flags, and returns it.
// @fnv 0x00c257d0
// pdb: BSStripParticleSystem::CreateClone | BSStripParticleSystem.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: kCloning
ParticleSystem* ParticleOwner::CreateParticleSystem(unsigned int flags)
{
    ParticleSystem* object = static_cast<ParticleSystem*>(FUN_00aa13e0(0x110));
    if (object)
    {
        object->FUN_00c1b5c0();
        object->vtable = &UNK_010be35c;
    }
    else
    {
        object = 0;
    }
    this->FUN_00c1b6f0(object, flags);
    return object;
}

void __cdecl FUN_00c1b0b0();
// @fnv 0x00c21940
// pdb: NiSpotLight::LinkObject | NiSpotLight.obj | fnv360_0822_retail, objrun_prop + bridge(vtable|objrun_prop) + skyrim(objrun), high
void __cdecl NiSpotLight_LinkObject()
{
    FUN_00c1b0b0();
}

struct NiCullingProcess
{
    void* p;
};
struct NiGeometry
{
    void __thiscall OnVisible(NiCullingProcess&);
};
struct FUN_00c256f0_cls : NiGeometry
{
    void __thiscall FUN_00c256f0(NiCullingProcess&);
};
// @fnv 0x00c256f0
void __thiscall FUN_00c256f0_cls::FUN_00c256f0(NiCullingProcess& a)
{
    NiGeometry::OnVisible(a);
}

void __cdecl FUN_00c1b3a0();
// @fnv 0x00c25700
// pdb: NiParticleMeshes::LoadBinary | NiParticleMeshes.obj | fnv360_0822_retail, caller_sim, low
// pdb params: kStream
void __cdecl FUN_00c25700()
{
    FUN_00c1b3a0();
}

extern "C" void __cdecl LoadModifiers();
// @fnv 0x00c25710
// pdb: NiParticleMeshes::SaveBinary | NiParticleMeshes.obj | fnv360_0822_retail, caller_sim, low
// pdb params: kStream
void __cdecl FUN_00c25710()
{
    LoadModifiers();
}

void __cdecl FUN_00c1b400();
// @fnv 0x00c25720
// pdb: NiParticleMeshes::IsEqual | NiParticleMeshes.obj | fnv360_0822_retail, caller_sim, high
// pdb params: pkObject
void __cdecl FUN_00c25720()
{
    FUN_00c1b400();
}

extern void FUN_00c1b1d0();

// @fnv 0x00c21950
// pdb: NiSpotLight::RegisterStreamables | NiSpotLight.obj | fnv360_0822_retail, caller_sim + bridge(vtable|caller_sim) + skyrim(objrun), high
void NiSpotLight_RegisterStreamables()
{
    FUN_00c1b1d0();
}
