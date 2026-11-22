#include "f3_common.h"
#include "havok/hkMonitorStream.h"
// src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl hkAgent1nMachine_InvalidateTim(void*, void*);

// hkpGskfAgent and hkpConvexListAgent: the members the agent's functions here use, at their Fallout 3 offsets (names
// from the New Vegas Xbox 360 PDB). Outside GSK mode the agent keeps its hkpAgent1nTrack in the bytes of the GSK
// manifold, whose first word is the track's sector array.
struct hkpGskfAgent
{
    int unk00;
    int unk04;
    void* m_contactMgr;         // +0x08
    char unk0C[0x24];
    char m_manifold[0x50];      // +0x30
    void __thiscall hkpGskfAgent_commitPotential(int a);
};
struct hkpConvexListAgentData : hkpGskfAgent
{
    void* m_dispatcher;         // +0x80
    char m_inGskMode;           // +0x84 hkBool
    char m_processFunctionCalled;
    short m_inStreamModeCounter;
};
struct hkpConvexListAgent : hkpConvexListAgentData
{
    void __thiscall RemovePoint(int a);
    void __thiscall FUN_00d33770(int a);
};

// @fnv 0x00d33770
// pdb: hkpConvexListAgent::invalidateTim | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix, high
// pdb params: input
void __thiscall hkpConvexListAgent::FUN_00d33770(int a)
{
    if (m_inGskMode)
        RemovePoint(a);
    else
        hkAgent1nMachine_InvalidateTim(m_manifold, (void*)a);
}

extern "C" void __cdecl FUN_00d339d0(int, int, int, int);

struct FUN_00d33b70_cls
{
    void __thiscall hkpConvexListAgent_getClosestPoints(int a, int b, int c, int d);
};

// @fnv 0x00d33b70
// pdb: hkpConvexListAgent::getClosestPoints | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix + bridge(vtable_prefix|vtable) + skyrim(vtable_prefix), high
void __thiscall FUN_00d33b70_cls::hkpConvexListAgent_getClosestPoints(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    FUN_00d339d0(aiArg1, aiArg2, aiArg3, aiArg4);
}

extern "C"
{
    void __cdecl FUN_00d33b90(void* a, void* b, void* c, void* d);
}

struct FUN_00d33c80_class
{
    void __thiscall hkpConvexListAgent_getPenetrations(void* a, void* b, void* c, void* d);
};

// @fnv 0x00d33c80
// pdb: hkpConvexListAgent::getPenetrations | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix + bridge(vtable_prefix|vtable) + skyrim(vtable_prefix), high
void __thiscall FUN_00d33c80_class::hkpConvexListAgent_getPenetrations(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_00d33b90(apArg1, apArg2, apArg3, apArg4);
}

extern void* __cdecl hkpConvexListAgent_createConvexListConvexAgent();
extern void* __cdecl FUN_00d33ca0();

struct FUN_00d337f0_self : hkpConvexListAgentData
{
    void __thiscall FUN_00dacb20(int a);
    void __thiscall hkpConvexListAgent_removePoint(int a);
};

// @fnv 0x00d337f0
// pdb: hkpConvexListAgent::removePoint | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix + bridge(vtable_prefix|vtable) + skyrim(vtable_prefix), high
void __thiscall FUN_00d337f0_self::hkpConvexListAgent_removePoint(int a)
{
    if (m_inGskMode)
        FUN_00dacb20(a);
}

struct FUN_00d33810_cls : hkpConvexListAgentData
{
    void __thiscall hkpConvexListAgent_commitPotential(int a);
};

// @fnv 0x00d33810
// pdb: hkpConvexListAgent::commitPotential | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix + bridge(vtable_prefix|vtable) + skyrim(vtable_prefix), high
void FUN_00d33810_cls::hkpConvexListAgent_commitPotential(int a)
{
    if (m_inGskMode)
        hkpGskfAgent::hkpGskfAgent_commitPotential(a);
}

namespace fnv_00d33830 {
struct hkpGskfAgent
{
    void __thiscall hkpGskfAgent_createZombie(int a);
};
// hkpConvexListAgent, as above.
struct FUN_00d33830_cls : ::hkpConvexListAgentData
{
    void __thiscall FUN_00d33830(int a);
};

// @fnv 0x00d33830
void __thiscall FUN_00d33830_cls::FUN_00d33830(int aiArg)
{
        if (m_inGskMode)
        ((fnv_00d33830::hkpGskfAgent*)this)->hkpGskfAgent_createZombie(aiArg);
}
}  // namespace fnv_00d33830

struct FUN_00d33740_cls : hkpConvexListAgentData
{
    void __thiscall FUN_00d33740(int a);
};

// Outside GSK mode, passes the agent track, the pointer at a+4 and a to FUN_00a26d90.
// @f3 0x009bd500 (community match, verified in this file)
extern void __cdecl FUN_00a26d90(void*, void*, void*);

void __thiscall FUN_00d33740_cls::FUN_00d33740(int a)
{
    if (m_inGskMode == 0)
    {
        FUN_00a26d90(m_manifold, *(void**)(a + 4), (void*)a);
    }
}


void __cdecl hkAgent1nMachine_Destroy(void*, int, int, int);
struct FUN_00d33850_cls : hkpConvexListAgentData
{
    void __thiscall hkpConvexListAgent_switchToGskMode(int a);
};
// Destroys the agent track with the dispatcher and contact manager, clears it and switches to GSK mode.
// @fnv 0x00d33850
// pdb: hkpConvexListAgent::switchToGskMode | hkpConvexListAgent.obj | fnv360_0822_retail, objrun + bridge(hash|objrun) + skyrim(hash), high
void __thiscall FUN_00d33850_cls::hkpConvexListAgent_switchToGskMode(int a)
{
    hkAgent1nMachine_Destroy(m_manifold, (int)m_dispatcher, (int)m_contactMgr, a);
    *(int*)m_manifold = 0;
    m_inGskMode = 1;
}

// Forwards all five arguments to FUN_00d33ca0 and returns its result.
// @fnv 0x00d33da0
void* __stdcall FUN_00d33da0(void* a, void* b, void* c, void* d, void* e)
{
    return ((void*(__cdecl*)(void*, void*, void*, void*, void*))FUN_00d33ca0)(a, b, c, d, e);
}

struct D338e0Agent
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10();
};

inline void D338e0Agent::vf00()
{}
inline void D338e0Agent::vf04()
{}
inline void D338e0Agent::vf08()
{}
inline void D338e0Agent::vf0C()
{}
inline int D338e0Agent::vf10()
{
    return 0;
}

struct D338e0Local
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
};

struct D338e0Owner
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    unsigned char unk84;

    void __thiscall hkpConvexListAgent_updateShapeCollectionFilter(int param1, int param2, int param3, int param4);
};

extern "C" void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(int*, D338e0Local*);

inline void D338e0Dispatch(D338e0Local* local, int* ownerField, int result)
{
    local->field0C = result;
    hkAgent1nMachine_UpdateShapeCollectionFilter(ownerField, local);
}

// Outside GSK mode, fills the visitor input from the parameters and the contact manager (unk08), takes body B's shape container, and updates the agent track (unk30).
// @f3 0x009bd6a0 (community match, verified in this file)
class hkClass;
class hkStatisticsCollector;
// hkpShape: the Fallout 3 slots up to getContainer (the order of the shape vtables, hkpSphereShape 0x00e7c8d4; names
// from the New Vegas Xbox 360 PDB).
struct D338e0AgentF3
{
    virtual ~D338e0AgentF3();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual float getMaximumProjection(const void* direction) const;
    virtual void castRayWithCollectorImpl(const void* input, const void* cdBody, void* collector) const;
    virtual int getContainer() const;
};
// pdb: hkpConvexListAgent::updateShapeCollectionFilter | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix + bridge(vtable_prefix|vtable) + skyrim(vtable_prefix), high
void __thiscall D338e0Owner::hkpConvexListAgent_updateShapeCollectionFilter(int aiArg1, int apAgentPtr, int aiArg3, int aiArg4)
{
    if (*(char*)&unk84 == 0)
    {
        D338e0Local local;
        local.field00 = aiArg1;
        local.field04 = apAgentPtr;
        local.field10 = aiArg3;
        local.field14 = unk08;
        local.field18 = aiArg4;

        D338e0AgentF3** ppAgent = reinterpret_cast<D338e0AgentF3**>(apAgentPtr);
        int result = (*ppAgent)->getContainer();

        D338e0Dispatch(&local, &unk30, result);
    }
}


struct hkAllocatorD33D
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterD33D
{
    void* m_apvUnk00[4];
    hkAllocatorD33D* m_pkHeap;
    hkAllocatorD33D& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterD33D* __cdecl FUN_00c85750() throw();

struct hkpCdBodyD33D;
struct hkpContactMgrD33D;
struct hkpCollisionInputD33D;

class hkpConvexListFilterD33D
{
  public:
    virtual ~hkpConvexListFilterD33D() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int ShouldBodiesCollide(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                    const hkpCollisionInputD33D& kInput) const throw();
};

struct hkpCollisionInputD33D
{
    int m_aiUnk00[4];
    hkpConvexListFilterD33D* m_pConvexListCollisionFilter;
};

class hkpCollisionAgentD33D
{
  public:
    virtual ~hkpCollisionAgentD33D() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpCollisionAgentD33D* p = (hkpCollisionAgentD33D*)FUN_00c85750()->heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
};

class FUN_00d33940 : public hkpCollisionAgentD33D
{
  public:
    FUN_00d33940(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB, const hkpCollisionInputD33D& kInput,
                 hkpContactMgrD33D* pkMgr) throw();
    char m_acUnk08[0x88];
};

class hkpSymmetricConvexListAgentD33D : public FUN_00d33940
{
  public:
    __forceinline hkpSymmetricConvexListAgentD33D(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                                  const hkpCollisionInputD33D& kInput, hkpContactMgrD33D* pkMgr) throw()
        : FUN_00d33940(kBodyB, kBodyA, kInput, pkMgr)
    {}
    virtual ~hkpSymmetricConvexListAgentD33D() throw();
};

class FUN_00d440f0 : public hkpCollisionAgentD33D
{
  public:
    FUN_00d440f0(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB, const hkpCollisionInputD33D& kInput,
                 hkpContactMgrD33D* pkMgr) throw();
    char m_acUnk08[0x30];
};

class FUN_00dacbd0 : public hkpCollisionAgentD33D
{
  public:
    FUN_00dacbd0(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB, hkpContactMgrD33D* pkMgr) throw();
    char m_acUnk08[0x78];
};

class hkpPredGskfAgentD33D : public FUN_00dacbd0
{
  public:
    __forceinline hkpPredGskfAgentD33D(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                       hkpContactMgrD33D* pkMgr) throw()
        : FUN_00dacbd0(kBodyA, kBodyB, pkMgr)
    {}
    virtual ~hkpPredGskfAgentD33D() throw();
};

// Creates a collision agent for the two bodies: picks the agent class from the convex list filter's result, or a default agent when pkMgr is null.
// @f3 0x009bdb80 (community match, verified in this file)
struct F3InputView
{
    int m_aiUnk00[3];
    hkpConvexListFilterD33D* m_pConvexListCollisionFilter;
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
struct F3ThreadMemory
{
    void* FUN_008f6d30(int iNumBytes, int iMemClass) throw();
};

inline void* operator new(unsigned int, void* pWhere)
{
    return pWhere;
}

static __forceinline hkpCollisionAgentD33D* AllocAgent(unsigned int uiSize)
{
    F3ThreadMemory* pThreadMemory = (F3ThreadMemory*)TlsGetValue(DAT_010f3170);
    hkpCollisionAgentD33D* p = (hkpCollisionAgentD33D*)pThreadMemory->FUN_008f6d30((int)uiSize, 0x1f);
    p->m_usMemSizeAndFlags = (unsigned short)uiSize;
    return p;
}

// pdb: hkpConvexListAgent::createConvexListConvexAgent | hkpConvexListAgent.obj | fnv360_0822_debug, objrun, high
// pdb params: bodyA, bodyB, input, mgr
// pdb: hkpConvexListAgent::createConvexListConvexAgent | hkpConvexListAgent.obj | fnv360_0822_debug, objrun, high (was: CreateConvexListAgent)
hkpCollisionAgentD33D* __cdecl hkpConvexListAgent_createConvexListConvexAgent(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                                     const hkpCollisionInputD33D& kInput,
                                                     hkpContactMgrD33D* pkMgr) throw()
{
    if (pkMgr)
    {
        const F3InputView& input = *(const F3InputView*)&kInput;
        switch (input.m_pConvexListCollisionFilter->ShouldBodiesCollide(kBodyA, kBodyB, kInput))
        {
        case 0:
            return ::new (AllocAgent(sizeof(hkpSymmetricConvexListAgentD33D)))
                hkpSymmetricConvexListAgentD33D(kBodyA, kBodyB, kInput, pkMgr);
        case 1:
            return ::new (AllocAgent(sizeof(FUN_00d440f0)))
                FUN_00d440f0(kBodyA, kBodyB, kInput, pkMgr);
        case 2:
            return ::new (AllocAgent(sizeof(hkpPredGskfAgentD33D)))
                hkpPredGskfAgentD33D(kBodyA, kBodyB, pkMgr);
        }
        return 0;
    }
    return ::new (AllocAgent(sizeof(FUN_00d440f0)))
        FUN_00d440f0(kBodyA, kBodyB, kInput, 0);
}


void __cdecl hkGskManifold_cleanup(void* out, void* src, void* arg);
void InitBlockPool(void* p);

struct hkArrayD33E
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD33E() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};

struct hkObjD33E
{
    int unk00;
    int unk04;
    void* m_pObservedSource;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkArrayD33E m_ppData;
    float m_3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    char m_84;
    char unk85;
    short m_86;

    void hkpConvexListAgent_switchToStreamMode(void* arg);
};

// Reinitializes the embedded array, clears m_84 and m_3c, and sets m_86 to 0x19.
// @fnv 0x00d33ef0
// pdb: hkpConvexListAgent::switchToStreamMode | hkpConvexListAgent.obj | fnv360_0822_retail, objrun + bridge(call_dedup|objrun) + skyrim(call_gap), high
void hkObjD33E::hkpConvexListAgent_switchToStreamMode(void* arg)
{
    hkGskManifold_cleanup(&m_ppData, m_pObservedSource, arg);
    m_84 = 0;
    new (&m_ppData) hkArrayD33E();
    InitBlockPool(&m_ppData);
    m_3c = 0.0f;
    m_86 = 0x19;
}

namespace fnv_00d343f0 {
struct hkAllocatorD343
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterD343
{
    void* m_apvUnk00[4];
    hkAllocatorD343* m_pkHeap;
    hkAllocatorD343& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterD343* __cdecl FUN_00c85750() throw();

struct hkpCdBodyD343;
struct hkpContactMgrD343;
struct hkpCollisionInputD343;

class hkpConvexListFilterD343
{
  public:
    virtual ~hkpConvexListFilterD343() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int ShouldBodiesCollide(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB,
                                    const hkpCollisionInputD343& kInput) const throw();
};

struct hkpCollisionInputD343
{
    int m_aiUnk00[4];
    hkpConvexListFilterD343* m_pConvexListCollisionFilter;
};

class hkpCollisionAgentD343
{
  public:
    virtual ~hkpCollisionAgentD343() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpCollisionAgentD343* p = (hkpCollisionAgentD343*)FUN_00c85750()->heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
};

class FUN_00d33940 : public hkpCollisionAgentD343
{
  public:
    FUN_00d33940(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB, const hkpCollisionInputD343& kInput,
                 hkpContactMgrD343* pkMgr) throw();
    char m_acUnk08[0x88];
};

class FUN_00d440f0 : public hkpCollisionAgentD343
{
  public:
    FUN_00d440f0(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB, const hkpCollisionInputD343& kInput,
                 hkpContactMgrD343* pkMgr) throw();
    char m_acUnk08[0x30];
};

class hkpSymmetricAgentD343 : public FUN_00d440f0
{
  public:
    __forceinline hkpSymmetricAgentD343(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB,
                                        const hkpCollisionInputD343& kInput, hkpContactMgrD343* pkMgr) throw()
        : FUN_00d440f0(kBodyB, kBodyA, kInput, pkMgr)
    {}
    virtual ~hkpSymmetricAgentD343() throw();
};

class FUN_00dacbd0 : public hkpCollisionAgentD343
{
  public:
    FUN_00dacbd0(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB, hkpContactMgrD343* pkMgr) throw();
    char m_acUnk08[0x78];
};

class hkpPredGskfAgentD343 : public FUN_00dacbd0
{
  public:
    __forceinline hkpPredGskfAgentD343(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB,
                                       hkpContactMgrD343* pkMgr) throw()
        : FUN_00dacbd0(kBodyA, kBodyB, pkMgr)
    {}
    virtual ~hkpPredGskfAgentD343() throw();
};

}  // namespace fnv_00d343f0

class hkCollectorBaseD347
{
  public:
    hkCollectorBaseD347() : m_bHasHit(false)
    {}
    virtual void AddHit(void* hit) = 0;

    bool m_bHasHit;
};

class hkCollectorD347 : public hkCollectorBaseD347
{
  public:
    hkCollectorD347(int filter) : m_iFilter(filter)
    {}
    virtual void AddHit(void* hit);

    int m_iFilter;
};

extern "C" void __cdecl FUN_00d43dc0(void* a, void* b, void* c, hkCollectorBaseD347& collector);

// Constructs an hkCollectorD347 with the given filter and passes it to FUN_00d43dc0 along with a, b and c.
// @fnv 0x00d34790
// pdb: hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetPenetrations | hkpConvexListAgent.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d34790(void* b, void* a, void* c, int filter)
{
    hkCollectorD347 collector(filter);
    FUN_00d43dc0(a, b, c, collector);
}

extern "C" void __cdecl FUN_00d34810();

struct hkMemberD337
{
    int unk00;
};

void __cdecl hkAgent1nMachine_WarpTime(hkMemberD337* member, float a, float b, int c);

class hkObjD337
{
  public:
    int unk00[12];
    hkMemberD337 m_30;
    int unk34[20];
    bool m_84;

    void hkpGskBaseAgent_warpTime(float a, float b, int c);
    void SetValue(float a, float b, int c);
};

// Sets a value on the object, calling hkpGskBaseAgent_warpTime when m_84 is true, otherwise delegating to hkAgent1nMachine_WarpTime on m_30.
// @fnv 0x00d337a0
// pdb: hkpConvexListAgent::warpTime | hkpConvexListAgent.obj | fnv360_0822_retail, vtable_prefix, high
// pdb params: oldTime, newTime, input
void hkObjD337::SetValue(float a, float b, int c)
{
    if (m_84)
        hkpGskBaseAgent_warpTime(a, b, c);
    else
        hkAgent1nMachine_WarpTime(&m_30, a, b, c);
}

// @fnv 0x00d33890
extern void __cdecl hkGskManifold_cleanup(void*, int, void*);
struct ContactAgent
{
    virtual void Invalidate(int);
    int unk04, collidable08;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int contact30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int state80;
    unsigned char flag84;
    void FUN_00d33890(void*);
};
void ContactAgent::FUN_00d33890(void* input)
{
    if (flag84)
    {
        hkGskManifold_cleanup(&contact30, collidable08, input);
    }
    else
    {
        hkAgent1nMachine_Destroy(&contact30, state80, collidable08, (int)input);
    }
    Invalidate(1);
}

extern float DAT_01012054;
extern char DAT_010cebf0[];

struct __declspec(align(16)) S00d33940_Out
{
    float x;
    float y;
    float z;
    float w;
    float x1;
    float y1;
    float z1;
    float w1;
    float x2;
    float y2;
    float z2;
    float w2;
    float x3;
    float y3;
    float z3;
    float w3;
    void FUN_00cb22f0(int a, int b);
};

struct S00d33940_Sub
{
    void FUN_00dafcd0(int a, int b, S00d33940_Out* c);
};

struct S00d33940_Base
{
    int vt;
    void FUN_00dacbd0(int* a, int* b, void* d);
};

struct S00d33940_Obj : S00d33940_Base
{
    int unk04;
    int unk08;
    S00d33940_Sub unk0c;
    char unk0d;
    char unk0e;
    char unk0f;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    float unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    unsigned char unk84;
    unsigned char unk85;
    S00d33940_Obj* FUN_00d33940(int* a, int* b, int* c, void* d);
};

// Calls FUN_00dacbd0(a, b, d), sets vt to DAT_010cebf0 and unk80 to *c, sets unk84/85, calls FUN_00dafcd0 on unk0c, and sets unk18 and unk2c to DAT_01012054.
// @fnv 0x00d33940
// pdb: hkpConvexListAgent::hkpConvexListAgent | hkpConvexListAgent.obj | fnv360_0822_retail, uvref, high
// pdb params: bodyA, bodyB, input, mgr
S00d33940_Obj* S00d33940_Obj::FUN_00d33940(int* a, int* b, int* c, void* d)
{
    FUN_00dacbd0(a, b, d);
    vt = (int)DAT_010cebf0;
    unk80 = *c;
    unk84 = 1;
    unk85 = 0;
    int v1 = a[0];
    int v0 = b[0];
    S00d33940_Out o;
    o.FUN_00cb22f0(a[2], b[2]);
    unk0c.FUN_00dafcd0(v1, v0, &o);
    float* __restrict p2 = &unk2c;
    float* __restrict p1 = &unk18;
    *p1 = *p2 = DAT_01012054;
    return this;
}

extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
extern char DAT_010cebd0;

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
    const char* m_pName2;
};

struct ProfBuf
{
    DWORD unk00;
    char* m_pCur;
    DWORD unk08;
    char* m_pRecordEnd;
};

struct HitCollector
{
    void* m_vtbl;
    bool m_bHit;
};

void __cdecl hkpGskBaseAgent_staticGetPenetrations(void* a, void* b, void* c, HitCollector* col);
void __cdecl FUN_00d34790(void* a, void* b, void* c, void* d);

// Writes timer entries (LtCvxList/StcheckHull, Stchildren, lt), calls hkpGskBaseAgent_staticGetPenetrations with a collector, and calls FUN_00d34790 if the collector registered a hit.
// @fnv 0x00d33b90
// pdb: hkpConvexListAgent::staticGetPenetrations | hkpConvexListAgent.obj | fnv360_0822_retail, call_seq, high
// pdb params: bodyA, bodyB, input, collector
extern "C" void __cdecl FUN_00d33b90(void* a, void* b, void* c, void* d)
{
    HK_TIMER_BEGIN_LIST("CvxList", "checkHull");

    HitCollector col;
    col.m_vtbl = &DAT_010cebd0;
    col.m_bHit = false;
    hkpGskBaseAgent_staticGetPenetrations(a, b, c, &col);
    if (col.m_bHit)
    {
        HK_TIMER_SPLIT_LIST("children");
        FUN_00d34790(a, b, c, d);
    }

    HK_TIMER_END_LIST();
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);

extern unsigned long DAT_0126835c;
extern const char str_01076f38[];
extern int DAT_010c476c;
extern float DAT_0104da48;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

extern "C" int __cdecl hkpGskBaseAgent_staticGetPenetrations(const void* a, const void* b, const void* c, void* d);

struct StringCursor
{
    int unk00;
    char* m_commandPointer;
    int unk08;
    char* m_endCommandPointer;
};

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;

struct hkVector4
{
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& other)
    {
        m_vComponents = other.m_vComponents;
        return *this;
    }
};

struct hkContactPoint
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    float getDistance() const
    {
        return m_vSeparatingNormal.m_vComponents.m128_f32[3];
    }
    hkContactPoint& operator=(const hkContactPoint& other)
    {
        m_vContactPosition = other.m_vContactPosition;
        m_vSeparatingNormal = other.m_vSeparatingNormal;
        return *this;
    }
};

struct RootContactPoint
{
    hkContactPoint m_kPoint;
    const void* m_pRootCollidableA;
    unsigned int m_uiShapeKeyA;
    const void* m_pRootCollidableB;
    unsigned int m_uiShapeKeyB;
};

struct hkpFlagCdBodyPairCollector
{
    const void* vtbl;
    bool m_flag;
    hkpFlagCdBodyPairCollector() : vtbl(&DAT_010cebd0), m_flag(false)
    {}
    bool DidHit() const
    {
        return m_flag;
    }
};

struct hkpClosestCdPointCollector
{
    const void* vtbl;
    float m_fEarlyOutDistance;
    int unk08;
    int unk0C;
    RootContactPoint m_kHitPoint;
    RootContactPoint m_unweldedHitPoint;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;

    hkpClosestCdPointCollector()
    {
        m_kHitPoint.m_kPoint.m_vSeparatingNormal.m_vComponents.m128_f32[3] = DAT_0104da48;
        m_fEarlyOutDistance = DAT_0104da48;
        vtbl = &DAT_010c476c;
        m_kHitPoint.m_pRootCollidableA = 0;
    }

    bool DidHit() const
    {
        return m_kHitPoint.m_pRootCollidableA != 0;
    }
};

struct hkpCdBody
{
    const void* m_pCollisionShape;
};

struct hkpConvexListShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_minDistanceToUseConvexHull;
};

struct ContactPointPair
{
    hkContactPoint m_kPoint;
    const void* m_pBodyA;
    const void* m_pBodyB;
};

struct hkpCdPointCollector
{
    virtual void unk00() = 0;
    virtual void AddCdPoint(const ContactPointPair& point) = 0;
};

// If hkpGskBaseAgent_staticGetPenetrations reports a hit calls QueryClosestPoints; else adds the closest point to a4 when its distance exceeds b's shape threshold, otherwise calls QueryClosestPoints.
// @f3 0x009bd790 (community match, verified in this file)
extern "C" void __cdecl FUN_00a34cf0(const void* a, const void* b, const void* c, void* d);
extern "C" void __cdecl FUN_00a34e90(const void* a, const void* b, const void* c, void* d);
extern "C" void __cdecl FUN_009be640(const void* a, const void* b, const void* c, void* d);
struct FUN_005686c0_cls
{
    void __thiscall FUN_005686c0(const hkContactPoint& p);
};
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern char DAT_00e7ee20;
extern char DAT_00e7ee14;
extern char DAT_00e7ee08;
extern char DAT_00e0811c;
extern char DAT_00e7edb0;
extern char DAT_00e3365c;
extern float DAT_00de6e60;
struct FlagCollectorQ
{
    const void* vtbl;
    bool m_flag;
};
struct ClosestCollectorQ
{
    const void* vtbl;
    float m_fEarlyOutDistance;
    int unk08;
    int unk0C;
    RootContactPoint m_kHitPoint;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

// pdb: hkpConvexListAgent::staticGetClosestPoints | hkpConvexListAgent.obj | fnv360_0822_retail, call_seq, high
// pdb params: bodyA, bodyB, input, collector
extern "C" void __cdecl FUN_00d339d0(int apBodyA, int apBodyB, int a3, int apCollector)
{
    {
        StringCursor* pForm = (StringCursor*)DAT_00d9b080(DAT_0126835c);
        char* p = pForm->m_commandPointer;
        if (p < pForm->m_endCommandPointer)
        {
            *(const void**)p = &DAT_00e7ee20;
            *(const void**)(p + 12) = &DAT_00e7ee14;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = t;
            pForm->m_commandPointer = p + 16;
        }
    }

    FlagCollectorQ flagCollector;
    flagCollector.vtbl = &DAT_00e7edb0;
    flagCollector.m_flag = false;
    FUN_00a34cf0((const void*)apBodyA, (const void*)apBodyB, (const void*)a3, &flagCollector);

    volatile unsigned int tick;
    if (flagCollector.m_flag)
    {
        StringCursor* c1 = (StringCursor*)DAT_00d9b080(DAT_0126835c);
        char* q1 = c1->m_commandPointer;
        if (q1 < c1->m_endCommandPointer)
        {
            *(const void**)q1 = &DAT_00e7ee08;
            
            _ReadWriteBarrier();
volatile unsigned int t1 = (unsigned int)__rdtsc();
            *(unsigned int*)(q1 + 4) = t1;
            c1->m_commandPointer = q1 + 12;
        }
        FUN_009be640((const void*)apBodyA, (const void*)apBodyB, (const void*)*(volatile int*)&a3, (void*)apCollector);
    }
    else
    {
        ClosestCollectorQ x;
        x.m_kHitPoint.m_kPoint.m_vSeparatingNormal.m_vComponents.m128_f32[3] = DAT_00de6e60;
        x.m_fEarlyOutDistance = DAT_00de6e60;
        x.vtbl = &DAT_00e3365c;
        x.m_kHitPoint.m_pRootCollidableA = 0;
        FUN_00a34e90((const void*)apBodyA, (const void*)apBodyB, (const void*)a3, &x);
        if (x.m_kHitPoint.m_pRootCollidableA != 0)
        {
            const hkpConvexListShape* shapeB = (const hkpConvexListShape*)((const hkpCdBody*)apBodyB)->m_pCollisionShape;
            if (x.m_kHitPoint.m_kPoint.getDistance() > shapeB->m_minDistanceToUseConvexHull)
            {
                ContactPointPair point;
                point.m_pBodyA = (const void*)apBodyA;
                point.m_pBodyB = (const void*)apBodyB;
                ((FUN_005686c0_cls*)&point.m_kPoint)->FUN_005686c0(x.m_kHitPoint.m_kPoint);
                ((hkpCdPointCollector*)apCollector)->AddCdPoint(point);
            }
            else
            {
                StringCursor* c2 = (StringCursor*)DAT_00d9b080(DAT_0126835c);
                char* q2 = c2->m_commandPointer;
                if (q2 < c2->m_endCommandPointer)
                {
                    *(const void**)q2 = &DAT_00e7ee08;
                    _ReadWriteBarrier();
volatile unsigned int t2 = (unsigned int)__rdtsc();
_ReadWriteBarrier();
                    *(unsigned int*)(q2 + 4) = t2;
                    c2->m_commandPointer = q2 + 12;
                }
                FUN_009be640((const void*)apBodyA, (const void*)apBodyB, (const void*)*(volatile int*)&a3, (void*)apCollector);
            }
        }
    }

    {
        StringCursor* pForm = (StringCursor*)DAT_00d9b080(DAT_0126835c);
        char* p = pForm->m_commandPointer;
        if (p < pForm->m_endCommandPointer)
        {
            *(const void**)p = &DAT_00e0811c;
            _ReadWriteBarrier();
            tick = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = tick;
            pForm->m_commandPointer = p + 12;
        }
    }
}


namespace fnv_00d33ca0 {
#include <intrin.h>

extern "C" __declspec(dllimport) unsigned long __stdcall TlsGetValue(unsigned long);
extern "C" void __cdecl FUN_00d34810(int, int, int, int, int);
extern "C" void __cdecl FUN_00daf8e0(int, int, int, void*, void*);

extern int DAT_0126835c;
extern float DAT_0104da48;
extern int DAT_010cebe0;
extern char str_010cec54[];
extern char str_010cec34[];
extern char str_010cec4c[];
extern char str_01076f38[];

struct S00d33ca0_Buf
{
    int unk00;
    unsigned int* cur;
    int unk08;
    unsigned int* limit;
};

struct __declspec(align(16)) S00d33ca0_Local
{
    void* unk00;
    float unk04;
    char unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    volatile float unk2c;
};

// Writes a timer entry, calls FUN_00daf8e0, and if local.unk08 is set writes another entry and calls FUN_00d34810; then writes a closing timer entry.
// @fnv 0x00d33ca0
extern "C" void __cdecl FUN_00d33ca0(int a, int b, int c, int d, int e)
{
    S00d33ca0_Buf* buf;
    unsigned int* p;
    volatile unsigned int ts;

    buf = (S00d33ca0_Buf*)TlsGetValue(DAT_0126835c);
    p = buf->cur;
    if (p < buf->limit)
    {
        p[0] = (unsigned int)&str_010cec54[0];
        p[3] = (unsigned int)&str_010cec34[0];
        _ReadWriteBarrier();
        ts = __rdtsc();
        p[1] = ts;
        buf->cur = p + 4;
    }

    {
        S00d33ca0_Local local;
        local.unk2c = DAT_0104da48;
        local.unk04 = DAT_0104da48;
        local.unk00 = &DAT_010cebe0;
        local.unk08 = 0;
        FUN_00daf8e0(a, b, c, &local, &local);
        if (local.unk08 != 0)
        {
            buf = (S00d33ca0_Buf*)TlsGetValue(DAT_0126835c);
            p = buf->cur;
            if (p < buf->limit)
            {
                p[0] = (unsigned int)&str_010cec4c[0];
                _ReadWriteBarrier();
                ts = __rdtsc();
                p[1] = ts;
                buf->cur = p + 3;
            }
            FUN_00d34810(a, b, c, d, e);
        }
    }

    buf = (S00d33ca0_Buf*)TlsGetValue(DAT_0126835c);
    p = buf->cur;
    if (p < buf->limit)
    {
        p[0] = (unsigned int)&str_01076f38[0];
        _ReadWriteBarrier();
        ts = __rdtsc();
        p[1] = ts;
        buf->cur = p + 3;
    }
}
}  // namespace fnv_00d33ca0

namespace fnv_00d34510 {
struct ChunkAllocator
{
    virtual void* vfunc0();
    virtual void* allocate(int size);
};

struct MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ChunkAllocator* m_pThreadAllocator;
};

extern "C"
{
    MemoryRouter* __cdecl FUN_00c85750();
    void* __cdecl FUN_00dacbd0();
    void* __cdecl FUN_00d440f0();
    void* __cdecl FUN_00d33940();
}

typedef void*(__thiscall* PfnDacbd0)(void* self, void* bodyA, void* bodyB, void* contactMgr);
typedef void*(__thiscall* PfnD440f0)(void* self, void* bodyA, void* bodyB, void* input, void* contactMgr);
typedef void*(__thiscall* PfnD33940)(void* self, void* bodyA, void* bodyB, void* input, void* contactMgr);

}  // namespace fnv_00d34510
