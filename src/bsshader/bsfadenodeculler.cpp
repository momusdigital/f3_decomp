#include "f3_common.h"
// src/bsshader/bsfadenodeculler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/bsfadenodeculler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class GlobalObjectO2_00a7b610
{
};

extern GlobalObjectO2_00a7b610 g_01201f84;

// @fnv 0x00bc2bc0
// pdb: NiTMapBase<NiTPointerAllocator<unsigned int>,char const *,NiD3DVertexShader *>::ClearValue | NiD3DShaderProgramFactory.obj | fnv360_0822_debug, objrun_open, low
// pdb params: __formal
GlobalObjectO2_00a7b610* __cdecl FUN_00bc2bc0()
{
    return &g_01201f84;
}

struct FUN_00bc2b20_shell
{
    void __thiscall FUN_00bc2b20(int a, int b, int c);
};

// @fnv 0x00bc2b20
// pdb: BSFadeNodeCuller::Process | BSFadeNodeCuller.obj | fnv360_0822_retail, vtable, medium
// pdb params: apCamera, apScene, apVisibleSet
void __thiscall FUN_00bc2b20_shell::FUN_00bc2b20(int a, int b, int c)
{
    *(int*)((char*)this + 0xc) = a;
}

struct SpawnedBound
{
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fBoundRadius;
};

struct SpawnedObject
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
    unsigned int m_uiObjectFlags;

    SpawnedBound* GetBoundingVolume();
};

struct SpawnedSource
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual SpawnedObject* GetTarget();
};

struct SpawnedPlane
{
    float m_fNx;
    float m_fNy;
    float m_fNz;
    float m_fD;
};

struct FUN_00bc2b30_cls
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
    SpawnedPlane m_kPlaneArray[6];

    void FUN_00bc2b30(SpawnedSource* apSource);
};

// @fnv 0x00bc2b30
// pdb: BSFadeNodeCuller::Process | BSFadeNodeCuller.obj | fnv360_0822_retail, vtable, medium
// pdb params: apObject
void FUN_00bc2b30_cls::FUN_00bc2b30(SpawnedSource* apSource)
{
    SpawnedObject* pTarget = apSource->GetTarget();
    if (pTarget == 0)
    {
        return;
    }
    pTarget->m_uiObjectFlags |= 0x1000;
    unsigned int uFlags = pTarget->m_uiObjectFlags;

    unsigned int uCount = 0;
    do
    {
        SpawnedBound* pBound = pTarget->GetBoundingVolume();
        SpawnedPlane* pPlane = &m_kPlaneArray[uCount];
        float fDot = pPlane->m_fNy * pBound->m_fVectorZ + pPlane->m_fNx * pBound->m_fVectorY +
                              pPlane->m_fNz * pBound->m_fScalarPart;
        float fDist = fDot - pPlane->m_fD;
        if (fDist <= -pBound->m_fBoundRadius)
        {
            break;
        }
        ++uCount;
    } while (uCount < 6);

    if (uCount != 6)
    {
        uFlags |= 0x100000u;
    }
    else
    {
        uFlags &= 0xffefffffu;
    }
    pTarget->m_uiObjectFlags = uFlags;
}
