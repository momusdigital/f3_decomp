#include "f3_common.h"
// src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void __cdecl FUN_00d3c440(int a, int b, int c, int d);
// @fnv 0x00d3c590
void __stdcall ForwardToD3C440(int a, int b, int c, int d)
{
    FUN_00d3c440(a, b, c, d);
}

void FlipAndDispatchCollector();
void FUN_00d3c440();
void FUN_00d3cc00();

extern float DAT_0104da48;
extern void __cdecl FUN_00d3cc00(void*, void*, int, void*);
struct hkpSymmetricAgentFlipCollector
{
    virtual void unk00();
    float unk04;
    int unk08;
};
// Builds a hkpSymmetricAgentFlipCollector from DAT_0104da48 and arg4, then calls FUN_00d3cc00 with arg2, arg1, arg3 and the collector.
// @fnv 0x00d3d040
// pdb: hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::staticGetClosestPoints | hkpSphereBoxAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void __cdecl FlipAndDispatchCollector(void* arg1, void* arg2, int arg3, int arg4)
{
    hkpSymmetricAgentFlipCollector local;
    local.unk04 = DAT_0104da48;
    local.unk08 = arg4;
    FUN_00d3cc00(arg2, arg1, arg3, &local);
}

struct S_00d3c3c0_Holder
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(unsigned int idx, int arg);
};
struct S_00d3c3c0_Obj
{
    virtual void v00(int flag);
    int unk04;
    S_00d3c3c0_Holder* unk08;
    unsigned short unk0c;
    void hkpSphereBoxAgent_cleanup(int arg);
};
// If unk0c is not 0xffff, calls v14 on unk08 with unk0c and arg, then calls v00 with 1.
// @fnv 0x00d3c3c0
// pdb: hkpSphereBoxAgent::cleanup | hkpSphereBoxAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void S_00d3c3c0_Obj::hkpSphereBoxAgent_cleanup(int arg)
{
    int idx = unk0c;
    if ((unsigned short)idx != 0xffff)
        unk08->v14(idx, arg);
    v00(1);
}

class D3CF80CollectorBase
{
  public:
    D3CF80CollectorBase() : m_bHit(false)
    {}
    virtual void AddCdPoint(const void* pkEvent) = 0;

    bool m_bHit;
};

class D3CF80Collector : public D3CF80CollectorBase
{
  public:
    D3CF80Collector(int iFilter) : m_iFilter(iFilter)
    {}
    virtual void AddCdPoint(const void* pkEvent);

    int m_iFilter;
};

class D3CF80Agent
{
  public:
    void ForwardToD3C440(void* pkA, void* pkB, void* pkInput, D3CF80Collector* pkCollector);
    void CollectFilteredEvents(void* pkA, void* pkB, void* pkInput, int iFilter);
};

// @fnv 0x00d3cf80
// pdb: hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::getPenetrations | hkpSphereBoxAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void D3CF80Agent::CollectFilteredEvents(void* pkA, void* pkB, void* pkInput, int iFilter)
{
    D3CF80Collector kCollector(iFilter);
    ForwardToD3C440(pkB, pkA, pkInput, &kCollector);
}

extern void __cdecl FUN_00d3c440(int a, int b, int c, int d);

struct CpuCallData
{
    void* descriptor;
    float bound;
    unsigned int value;
};
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject
{
    void FUN_00d3c910(void*, void*, unsigned int, CpuCallData*);
    void FUN_00d3d000(void*, void*, unsigned int, unsigned int);
};
// Builds a CpuCallData from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first, third and the data to FUN_00d3c910.
// @fnv 0x00d3d000
// pdb: hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::getClosestPoints | hkpSphereBoxAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void CpuObject::FUN_00d3d000(void* first, void* second, unsigned int third, unsigned int fourth)
{
    CpuCallData callData;
    callData.value = fourth;
    callData.bound = DAT_0104da48;
    callData.descriptor = &DAT_010ce7fc;
    FUN_00d3c910(second, first, third, &callData);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
}
