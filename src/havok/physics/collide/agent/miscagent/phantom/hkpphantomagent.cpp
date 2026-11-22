#include "f3_common.h"
// src/havok/physics/collide/agent/miscagent/phantom/hkpphantomagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/phantom/hkpphantomagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct InterfaceA
{
    virtual void First(int);
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void Dispatch(int, int);
};
struct InterfaceB
{
    virtual void First(int);
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void Dispatch(int, int);
};
struct Owner
{
    virtual void First(int);
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    int unk04;
    int unk08;
    int argA;
    int argB;
    InterfaceA* first;
    InterfaceB* second;
    int selectorA;
    int selectorB;
    void hkpPhantomAgent_cleanup(int);
};
// If selectorA or selectorB equals 0x1D, dispatches argA/argB to first or second respectively, then calls First(1).
// @f3 0x009cd100 (community match, verified in this file)
struct DispatchF3
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void Dispatch(int, int);
};
// pdb: hkpPhantomAgent::cleanup | hkpPhantomAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Owner::hkpPhantomAgent_cleanup(int)
{
    if (selectorA == 0x1D)
        ((DispatchF3*)first)->Dispatch(argA, argB);
    if (selectorB == 0x1D)
        ((DispatchF3*)second)->Dispatch(argB, argA);
    First(1);
}


struct S_00d42790_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int m_type;
};

struct S_00d42790_CdBody
{
    const S_00d42790_Shape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S_00d42790_CdBody* m_parent;

    const S_00d42790_CdBody* getRootCdBody() const
    {
        const S_00d42790_CdBody* body = this;
        while (body->m_parent)
        {
            body = body->m_parent;
        }
        return body;
    }
};

struct __declspec(novtable) S_00d42790_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d42790_RefObj()
    {
        m_sReferenceCount = 1;
    }
    virtual void v00() = 0;
};

struct __declspec(novtable) S_00d42790_Agent : S_00d42790_RefObj
{
    void* m_pContactManager;
    S_00d42790_Agent(void* mgr) : m_pContactManager(mgr)
    {}
};

struct hkpPhantomAgent : S_00d42790_Agent // src: F3_EXE vtable 0x00e7f3a0 (old: FUN_00d42790)
{
    const S_00d42790_CdBody* m_pBodyA;
    const S_00d42790_CdBody* m_pBodyB;
    int unk14;
    int unk18;
    int m_iAgentTypeA;
    int m_iAgentTypeB;

    hkpPhantomAgent(const S_00d42790_CdBody& bodyA, const S_00d42790_CdBody& bodyB, void* mgr);
    virtual void v00();
};

// Stores the root bodies and shape types of two collision bodies in a new agent.
// @fnv 0x00d42790
// pdb: hkpPhantomAgent::hkpPhantomAgent | hkpPhantomAgent.obj | fnv360_0822_retail, uvref, high
// pdb params: bodyA, bodyB, contactMgr
hkpPhantomAgent::hkpPhantomAgent(const S_00d42790_CdBody& bodyA, const S_00d42790_CdBody& bodyB, void* mgr)
    : S_00d42790_Agent(mgr)
{
    m_pBodyA = bodyA.getRootCdBody();
    m_pBodyB = bodyB.getRootCdBody();
    m_iAgentTypeA = bodyA.m_pCollisionShape->m_type;
    m_iAgentTypeB = bodyB.m_pCollisionShape->m_type;
}

struct Dispatch
{
    virtual void v00();
    virtual int V04(void* apFirst, void* apSecond);
};

// Forwards apFirst and apSecond to apDispatch->V04 and returns its result.
// @fnv 0x00d42710
// pdb: hkpPhantomAgent::getPenetrations | hkpPhantomAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
// pdb: hkpPhantomAgent::getPenetrations | hkpPhantomAgent.obj | fnv360_0822_retail, vtable, high (was: DispatchToV04)
int __stdcall hkpPhantomAgent_getPenetrations(void* apFirst, void* apSecond, void* apThird, Dispatch* apDispatch)
{
    return apDispatch->V04(apFirst, apSecond);
}

struct FUN_00d42730_obj
{
    virtual void v0();
    virtual int v1(int a, int b);
};

// @fnv 0x00d42730
// pdb: hkpPhantomAgent::staticGetPenetrations | hkpPhantomAgent.obj | fnv360_0822_retail, objrun, high
// pdb params: bodyA, bodyB, input, collector
// pdb: hkpPhantomAgent::staticGetPenetrations | hkpPhantomAgent.obj | fnv360_0822_retail, objrun, high (was: CallVirtualMethod)
int __cdecl hkpPhantomAgent_staticGetPenetrations(int a1, int a2, int aiUnused, FUN_00d42730_obj* apObj)
{
    return apObj->v1(a1, a2);
}

// @fnv 0x00d42700
// pdb: hkpPhantomAgent::processCollision | hkpPhantomAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpPhantomAgent_processCollision(int, int, int, int)
{}

// @fnv 0x00d42750
void __stdcall FUN_00d42750(int, int, int, int)
{}

// @fnv 0x00d42770
// pdb: hkpPhantomAgent::linearCast | hkpPhantomAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpPhantomAgent_linearCast(int, int, int, int, int)
{}
