// staging/blk_00ce0000_od_o2_gs_nood_nogs_variant.cpp: RayCaster (1 function)
#include "f3_common.h"
#include <windows.h>
// src/staging/blk_00ce0000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00ce0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00ce0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>

__declspec(align(16)) struct Vec4Pod
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfBuf
{
    DWORD unk00;
    ProfRec* m_pCur;
    DWORD unk08;
    ProfRec* m_pRecordEnd;
};

struct RayInput
{
    __m128 m_vFrom;
    __m128 m_vTo;
    unsigned char m_bFlag;
};

struct RayCastQuery
{
    __m128 m_vFrom;
    int m_iOne;
    const __m128* m_pTo;
    int m_uiLogicalSize;
    int m_iZero;
};

class RayCaster;

class RayWorld
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void CastRay(RayCastQuery* q, RayCaster* c, int z);
};

class RayCaster
{
  public:
    void FUN_00cfaa40(RayWorld* world, RayInput* input, char* source, int a4);

    int unk00;
    RayInput* m_pInput;
    char* m_pSource14;
    int m_i0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    char* m_pSource10;
};

// @f3 0x00942ad0 (community match, verified in this file)
struct RayWorldCast
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void CastRay(RayCastQuery* q, RayCaster* c, int z);
};
struct RayCaster44
{
    int unk00;
    RayInput* m_pInput;
    char* m_pSource14;
    int m_i0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40;
    char* m_pSource10;
};
void RayCaster::FUN_00cfaa40(RayWorld* world, RayInput* input, char* source, int a4)
{
    volatile DWORD tick;
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "TtRayCast";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }
    m_pInput = input;
    m_i0C = a4;
    unk10 = 0;
    m_pSource14 = source ? source + 0x14 : 0;
    if (input->m_bFlag)
        ((RayCaster44*)this)->m_pSource10 = source ? source + 0x10 : 0;
    else
        ((RayCaster44*)this)->m_pSource10 = 0;
    RayCastQuery q;
    const float* from = (const float*)&input->m_vFrom;
    float* qf = (float*)&q.m_vFrom;
    qf[0] = from[0];
    qf[1] = from[1];
    qf[2] = from[2];
    qf[3] = from[3];
    q.m_pTo = &input->m_vTo;
    q.m_iOne = 1;
    q.m_uiLogicalSize = 0x10;
    q.m_iZero = 0;
    ((RayWorldCast*)world)->CastRay(&q, this, 0);
    pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "Et";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }
}

