#include "f3_common.h"
// src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl FUN_00d3f6a0(void* a, void* b, void* c, void* d);
void __stdcall hkpSphereSphereAgent_getPenetrations(void* a, void* c, void* b, void* d);
struct S_00d3f660_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Release(unsigned short id, void* arg);
};
struct S_00d3f660
{
    virtual ~S_00d3f660();
    int unk4;
    S_00d3f660_Owner* unk8;
    unsigned short unkC;
    void hkpSphereSphereAgent_cleanup(void* arg);
};

#include <xmmintrin.h>
#include <windows.h>
unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;

struct SRadius
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fBoundRadius;
    float getRadius() const
    {
        return m_fBoundRadius;
    }
};
struct Vect
{
    __m128 quad;
    void sub(const Vect& a, const Vect& b)
    {
        quad = _mm_sub_ps(a.quad, b.quad);
    }
    float lengthSquared() const
    {
        __m128 p = _mm_mul_ps(quad, quad);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        float r;
        _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
        return r;
    }
};
struct SCenter
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    Vect m_vCenter;
};
struct SProxy
{
    SRadius* m_pProxyRadius;
    void* unk04;
    SCenter* m_pCenter;
};
struct STraceRec
{
    const char* unk00;
    unsigned int unk04;
    unsigned int unk08;
};
struct STraceBuf
{
    void* unk00;
    STraceRec* unk04;
    void* unk08;
    STraceRec* unk0C;
};
struct SListener
{
    virtual void v00() = 0;
    virtual void v04(SProxy* a, SProxy* b) = 0;
};
// @f3 0x009c9820 (community match, verified in this file)
extern unsigned long DAT_0126835c;
extern unsigned long DAT_0116913c;
extern char FUN_00e32798[];
extern void* (__stdcall* FUN_00d9b080)(unsigned long);
// pdb: hkpSphereSphereAgent::staticGetPenetrations | hkpSphereSphereAgent.obj | fnv360_0822_retail, call_seq, high
// pdb params: bodyA, bodyB, input, collector
extern "C" void __cdecl FUN_00d3f6a0(void* a, void* b, void* c, void* d)
{
    void* (__stdcall* getTls)(unsigned long) = FUN_00d9b080;
    STraceBuf* pBuf = (STraceBuf*)getTls(DAT_0126835c);
    if (pBuf->unk04 < pBuf->unk0C)
    {
        STraceRec* pRec = pBuf->unk04;
        pRec->unk00 = "TtSphereSphere";
        {
            _ReadWriteBarrier();
            volatile unsigned int stamp = (unsigned int)__rdtsc();
            pRec->unk04 = stamp;
        }
        pBuf->unk04 = pRec + 1;
    }
    SProxy* pA = (SProxy*)a;
    SProxy* pB = (SProxy*)b;
    const float* cA = reinterpret_cast<const float*>(&pA->m_pCenter->m_vCenter);
    const float* cB = reinterpret_cast<const float*>(&pB->m_pCenter->m_vCenter);
    Vect delta;
    float* dd = reinterpret_cast<float*>(&delta);
    dd[0] = cB[0] - cA[0];
    dd[1] = cB[1] - cA[1];
    dd[2] = cB[2] - cA[2];
    float sumRadius = pA->m_pProxyRadius->getRadius() + pB->m_pProxyRadius->getRadius();
    float dist2 = dd[0] * dd[0] + dd[1] * dd[1] + dd[2] * dd[2];
    if (dist2 < sumRadius * sumRadius)
    {
        ((SListener*)d)->v04(pA, pB);
    }
    STraceBuf* pBuf2 = (STraceBuf*)getTls(DAT_0116913c);
    if (pBuf2->unk04 < pBuf2->unk0C)
    {
        STraceRec* pRec2 = pBuf2->unk04;
        pRec2->unk00 = FUN_00e32798;
        {
            _ReadWriteBarrier();
            volatile unsigned int stamp = (unsigned int)__rdtsc();
            pRec2->unk04 = stamp;
        }
        pBuf2->unk04 = pRec2 + 1;
    }
}

