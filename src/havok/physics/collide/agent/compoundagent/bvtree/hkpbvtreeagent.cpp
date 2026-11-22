#include "f3_common.h"
// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_d2f5a0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int a);
};
struct S_d2f5a0_Entry
{
    int unk0;
    int unk4;
    S_d2f5a0_Obj* m_obj;
};
struct S_d2f5a0_Array
{
    S_d2f5a0_Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_d2f5a0_Entry* begin()
    {
        return m_data;
    }
    S_d2f5a0_Entry* end()
    {
        return m_data + m_iElementCount;
    }
};
struct S_d2f5a0
{
    int unk0;
    int unk4;
    int unk8;
    S_d2f5a0_Array m_aiIndexedValues;
    void FUN_00d2f5a0(int a);
};
// Iterates the entry array and calls v9(a) on each entry whose m_obj is non-null.
// @fnv 0x00d2f5a0
void S_d2f5a0::FUN_00d2f5a0(int a)
{
    for (S_d2f5a0_Entry *it = m_aiIndexedValues.begin(), *pEnd = m_aiIndexedValues.end(); it != pEnd; ++it)
        if (it->m_obj)
            it->m_obj->v9(a);
}

struct __declspec(align(16)) Transform
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3c;

    Transform(void* apFirst, void* apSecond);
};

struct Allocator
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct Global
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};
struct Built
{
    int field00;
    short field04;
    int field08;
    void __thiscall FUN_00d2f980(int);
};
extern "C" Global* __cdecl FUN_00c85750();
// Allocates a 0x40-byte Built from the global allocator, sets its field04 to 0x40, and calls FUN_00d2f980 with arg4.
// @fnv 0x00d2f9d0
void __cdecl FUN_00d2f9d0(int aiUnused1, int aiUnused2, int aiUnused3, int arg4)
{
    Global* global = FUN_00c85750();
    Built* pBuilt = (Built*)global->allocator->allocate(0x40);
    pBuilt->field04 = 0x40;
    pBuilt->FUN_00d2f980(arg4);
}

void __cdecl hkpBvTreeAgent_staticLinearCast(void* apFirst, void* apSecond, void* apThird, void* apFourth, void* apFifth);

// Calls hkpBvTreeAgent_staticLinearCast, passing along all five arguments unchanged.
// @fnv 0x00d315a0
// pdb: hkpBvTreeAgent::linearCast | hkpBvTreeAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpBvTreeAgent_linearCast(void* apFirst, void* apSecond, void* apThird, void* apFourth, void* apFifth)
{
    hkpBvTreeAgent_staticLinearCast(apFirst, apSecond, apThird, apFourth, apFifth);
}

extern "C" void __cdecl FUN_00d31110(void* arg0, void* arg1, void* arg2, void* arg3);
// @fnv 0x00d315d0
// pdb: hkpBvTreeAgent::getClosestPoints | hkpBvTreeAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
extern "C" void __stdcall FUN_00d315d0(void* arg0, void* arg1, void* arg2, void* arg3)
{
    FUN_00d31110(arg0, arg1, arg2, arg3);
}

void __cdecl hkpBvTreeAgent_staticGetPenetrations(void* apA, void* apB, void* apC, void* apD);

// @fnv 0x00d315f0
void __stdcall FUN_00d315f0(void* apA, void* apB, void* apC, void* apD)
{
    hkpBvTreeAgent_staticGetPenetrations(apA, apB, apC, apD);
}

struct D2FA00Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct D2FA00MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2FA00Allocator* m_pStreamAllocator;

    D2FA00Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" D2FA00MemoryRouter& __cdecl FUN_00c85750();
}

class D2FA00ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        D2FA00ReferencedObject* b =
            static_cast<D2FA00ReferencedObject*>(fnvc_adapt::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~D2FA00ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class D2FA00Agent : public D2FA00ReferencedObject
{
  public:
    __declspec(nothrow) D2FA00Agent(void* mgr);

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
};

class D2FA00ShapeAgent : public D2FA00Agent
{
  public:
    D2FA00ShapeAgent(void* mgr) : D2FA00Agent(mgr)
    {}
    virtual ~D2FA00ShapeAgent();
};

// Allocates and constructs a D2FA00ShapeAgent from mgr and returns it; bodyA, bodyB and input are unused.
// @fnv 0x00d2fa00
D2FA00Agent* __cdecl FUN_00d2fa00(const void* bodyA, const void* bodyB, const void* input, void* mgr)
{
    return new D2FA00ShapeAgent(mgr);
}

struct S_00d2f8f0_Elem
{
    int unk00;
    int unk04;
    int unk08;
};

struct S_00d2f8f0_Array
{
    S_00d2f8f0_Elem* m_pEntries;
    int m_iArrayLength;

    S_00d2f8f0_Elem* begin() const
    {
        return m_pEntries;
    }
    S_00d2f8f0_Elem* end() const
    {
        return m_pEntries + m_iArrayLength;
    }
};

struct S_00d2f8f0_ArgVtbl
{
    void* unk00;
    void* unk04;
    void* unk08;
    void(__thiscall* unk0c)(void*, char*, int, int);
    void* unk10;
    void(__thiscall* unk14)(void*, int, char*, void*, int, void*);
};

struct S_00d2f8f0_Arg
{
    S_00d2f8f0_ArgVtbl* m_pVtbl;
    int unk04;
    int unk08;
    int unk0c;
    char m_bFlag10;
};

struct S_00d2f8f0
{
    int unk00;
    int unk04;
    int unk08;
    S_00d2f8f0_Array m_aiIndexedValues;
    int m_iFlags;

    void WriteToStream(S_00d2f8f0_Arg* apStream);
};

// @f3 0x009b8120 (community match, verified in this file)
struct S_00d2f8f0_ArgVtblF3
{
    void* unk00;
    void (__thiscall* unk04)(void*, const char*, int, void*);
    void (__thiscall* unk08)(void*, const char*, int, void*, int, int);
    void (__thiscall* unk0c)(void*, const char*, int, int);
};

struct S_00d2f8f0_ArgF3
{
    S_00d2f8f0_ArgVtblF3* m_pVtbl;
    int unk04;
    int unk08;
    int unk0c;
    char m_bFlag10;
};

// pdb: hkpBvTreeAgent::calcContentStatistics | hkpBvTreeAgent.obj | fnv360_0822_retail, ustr, high
// pdb params: collector, cls
void S_00d2f8f0::WriteToStream(S_00d2f8f0_Arg* apStream)
{
    S_00d2f8f0_ArgF3* pStream = (S_00d2f8f0_ArgF3*)apStream;
    pStream->m_pVtbl->unk04(pStream, "BvTreeAgt", 8, this);

    if ((m_iFlags & 0x80000000u) == 0)
    {
        pStream->m_pVtbl->unk08(pStream, "AgentPtrs", 8, m_aiIndexedValues.m_pEntries,
                                m_aiIndexedValues.m_iArrayLength * (int)sizeof(S_00d2f8f0_Elem),
                                (m_iFlags & 0x3fffffff) * (int)sizeof(S_00d2f8f0_Elem));
    }

    S_00d2f8f0_Elem* p = m_aiIndexedValues.begin();
    S_00d2f8f0_Elem* pEnd = m_aiIndexedValues.end();
    while (p != pEnd)
    {
        if (p->unk08 != 0)
        {
            pStream->m_pVtbl->unk0c(pStream, "Agent", 8, p->unk08);
        }
        ++p;
    }
}


class ListenerD2F5
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C(void* pArg);
};

struct EntryD2F5
{
    int unk00;
    int unk04;
    ListenerD2F5* m_pkListener;
};

template <class T> class hkArrayD2F5
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    T* begin()
    {
        return m_data;
    }
    T* end()
    {
        return m_data + m_iElementCount;
    }
};

class OwnerD2F5
{
  public:
    virtual ~OwnerD2F5();

    int unk04[2];
    hkArrayD2F5<EntryD2F5> m_entries;

    void hkpBvTreeAgent_cleanup(void* pArg);
};

// Invokes vf1C on each non-null listener in m_entries with pArg, then deletes this object.
// @fnv 0x00d2f550
// pdb: hkpBvTreeAgent::cleanup | hkpBvTreeAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void OwnerD2F5::hkpBvTreeAgent_cleanup(void* pArg)
{
    for (EntryD2F5 *it = m_entries.begin(), *itEnd = m_entries.end(); it != itEnd; ++it)
    {
        if (it->m_pkListener)
            it->m_pkListener->vf1C(pArg);
    }
    delete this;
}

typedef void(__thiscall* TUpdateFn)(void* self, float, float, int);

class hkBoolR
{
  public:
    hkBoolR()
    {}
    hkBoolR(bool b) : m_cBooleanValue((char)b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

struct __declspec(align(16)) ShapeBuffer
{
    int m_data[128];
};

struct HkShape
{
    virtual void v00();
    int unk04;
    int unk08;
    int m_type;
};

struct ShapeContainer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const HkShape* GetShapeForKey(unsigned int key, ShapeBuffer& buffer) const;
};

struct CdBody
{
    const HkShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const CdBody* m_parent;

    CdBody(const CdBody* parent)
    {
        m_parent = parent;
        m_pMotionState = parent->m_pMotionState;
    }
    const HkShape* getShape() const
    {
        return m_pCollisionShape;
    }
    void SetCollisionShapeAndKey(const HkShape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct CollisionInput;

struct ShapeCollectionFilter
{
    virtual void v00();
    virtual hkBoolR IsCollisionEnabled(const CollisionInput& input, const CdBody& a, const CdBody& b,
                                       const ShapeContainer& bContainer, unsigned int bKey) const;
};

struct ReferencedObject
{
    virtual void v00();
    int unk04;
};

struct CollidableCollidableFilter
{
    virtual void v00();
};

struct CollisionFilter : ReferencedObject, CollidableCollidableFilter, ShapeCollectionFilter
{
    virtual hkBoolR IsCollisionEnabled(const CollisionInput& input, const CdBody& a, const CdBody& b,
                                       const ShapeContainer& bContainer, unsigned int bKey) const;
};

struct ConstraintOwner;
struct ContactMgr;
struct CollisionAgent;

typedef CollisionAgent*(__cdecl* CreateFunc)(const CdBody& a, const CdBody& b, const CollisionInput& input,
                                             ContactMgr* mgr);

struct CollisionAgentFunctionTable
{
    CreateFunc m_pCreateFunc;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
};

struct CollisionDispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    unsigned char m_ucAgent2TypeTable[32][32];
    unsigned char m_ucAgent3TypeTable[32][32];
    CollisionAgentFunctionTable m_kAgent3FunctionTable[32];

    CollisionAgent* getNewCollisionAgent(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                                         ContactMgr* mgr) const;
};

struct CollisionInput
{
    CollisionDispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    CollisionFilter* m_iFilter;
    int unk10;
    int m_bCreatePredictiveAgents;
};

inline CollisionAgent* CollisionDispatcher::getNewCollisionAgent(const CdBody& bodyA, const CdBody& bodyB,
                                                                 const CollisionInput& input, ContactMgr* mgr) const
{
    int typeA = bodyA.getShape()->m_type;
    int typeB = bodyB.getShape()->m_type;
    const unsigned char* agentTypeTablePtr =
        (input.m_bCreatePredictiveAgents) ? &m_ucAgent3TypeTable[0][0] : &m_ucAgent2TypeTable[0][0];
    int agentType = agentTypeTablePtr[typeA * 32 + typeB];
    CreateFunc f = m_kAgent3FunctionTable[agentType].m_pCreateFunc;
    return f(bodyA, bodyB, input, mgr);
}

struct CollisionAgent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void cleanup(ConstraintOwner& owner);
    virtual void ProcessContactPoints(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                                      ConstraintOwner& owner);
};

struct CollisionAgentMapRecord
{
    unsigned int m_key;
    int unk04;
    CollisionAgent* m_pCollisionAgent;
};

struct AgentArray
{
    CollisionAgentMapRecord* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    CollisionAgentMapRecord& operator[](int i)
    {
        return m_data[i];
    }
};

class ShapeCollectionAgent
{
  public:
    virtual void v00();
    int unk04;
    ContactMgr* m_pContactManager;
    AgentArray m_pAgents;

    void FUN_00d2f760(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                      ConstraintOwner& constraintOwner);
};

// Iterates m_pAgents, creating or cleaning up collision agents per shape key based on filter results, and processes contact points when enabled.
// @f3 0x009b7fa0 (community match, verified in this file)
namespace Native1495 {
CollisionAgent* __cdecl FUN_00990590();
struct Collection:HkShape{virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual const ShapeContainer* GetShapeContainer()const;};
struct Dispatcher;
struct Input{Dispatcher* dispatcher;int unk04;ShapeCollectionFilter* filter;int unk0c;int predictive;};
struct Dispatcher:CollisionDispatcher{
 __forceinline CollisionAgent* Create(const CdBody&a,const CdBody&b,const CollisionInput& input,ContactMgr*mgr)const{
 int typeA=a.getShape()->m_type;int typeB=b.getShape()->m_type;
 const Input& native=reinterpret_cast<const Input&>(input);
 const unsigned char* table=native.predictive?&m_ucAgent3TypeTable[0][0]:&m_ucAgent2TypeTable[0][0];
 int type=table[typeA*32+typeB];CreateFunc f=m_kAgent3FunctionTable[type].m_pCreateFunc;
 return f(a,b,input,mgr);
 }
};
}
// @fnv 0x00d2f760
void ShapeCollectionAgent::FUN_00d2f760(const CdBody& bodyA, const CdBody& bodyB, const CollisionInput& input,
                                        ConstraintOwner& constraintOwner)
{
    const Native1495::Input& native=reinterpret_cast<const Native1495::Input&>(input);
    const Native1495::Collection* collection = static_cast<const Native1495::Collection*>(bodyB.getShape());
    const ShapeContainer* shapeContainer = collection->GetShapeContainer();

    for (int i = 0; i < m_pAgents.GetLogicalSize(); i++)
    {
        ShapeBuffer shapeBuffer;
        const HkShape* shape = shapeContainer->GetShapeForKey(m_pAgents[i].m_key, shapeBuffer);
        CdBody newOperandB(&bodyB);
        newOperandB.SetCollisionShapeAndKey(shape, m_pAgents[i].m_key);

        if (native.filter->IsCollisionEnabled(input, bodyA, bodyB, *shapeContainer, m_pAgents[i].m_key))
        {
            if (m_pAgents[i].m_pCollisionAgent == Native1495::FUN_00990590())
            {
                m_pAgents[i].m_pCollisionAgent =
                    native.dispatcher->Create(bodyA, newOperandB, input, m_pContactManager);
            }
            else
            {
                m_pAgents[i].m_pCollisionAgent->ProcessContactPoints(bodyA, newOperandB, input, constraintOwner);
            }
        }
        else
        {
            if (m_pAgents[i].m_pCollisionAgent != Native1495::FUN_00990590())
            {
                m_pAgents[i].m_pCollisionAgent->cleanup(constraintOwner);
                m_pAgents[i].m_pCollisionAgent = Native1495::FUN_00990590();
            }
        }
    }
}


#include <xmmintrin.h>
struct S_00d2f980_Vec
{
    float x, y, z, w;
    void SetAllComponents(float a)
    {
        reinterpret_cast<__m128&>(*this) = _mm_set1_ps(a);
    }
    void setAllL(const float& a)
    {
        reinterpret_cast<__m128&>(*this) = _mm_load1_ps(&a);
    }
    S_00d2f980_Vec& operator=(const S_00d2f980_Vec& o)
    {
        reinterpret_cast<__m128&>(*this) = reinterpret_cast<const __m128&>(o);
        return *this;
    }
};
struct S_00d2f980_Base
{
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    S_00d2f980_Base()
    {
        m_sReferenceCount = 1;
    }
    virtual void vfn_00();
};
struct S_00d2f980_Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00d2f980_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct S_00d2f980_Mid : S_00d2f980_Base
{
    int m8;
    S_00d2f980_Mid(int p) : m8(p)
    {}
};
struct FUN_00d2f980 : S_00d2f980_Mid
{
    S_00d2f980_Array m_aiIndexedValues;
    int unk18;
    int unk1C;
    __declspec(align(16)) S_00d2f980_Vec m20;
    S_00d2f980_Vec m30;
    FUN_00d2f980(int p);
};
// Initializes m30 and m20 to FLT_MAX, delegating to the S_00d2f980_Mid base constructor with p.
// @fnv 0x00d2f980
FUN_00d2f980::FUN_00d2f980(int p) : S_00d2f980_Mid(p)
{
    m30.SetAllComponents(3.40282e+38f);
    m20 = m30;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>

extern DWORD DAT_0126835c;

struct S_00d30f50_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime(unsigned int& t)
    {
        t = (unsigned int)__rdtsc();
        m_uiStartTicks = *(volatile unsigned int*)&t;
    }
};

struct S_00d30f50_TimerBeginListCommand : S_00d30f50_TimerCommand
{
    const char* m_pFirst;
};

struct S_00d30f50_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00d30f50_MonitorStream& GetMonitorStream()
    {
        return *(S_00d30f50_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

static inline void S_00d30f50_TimerBeginList(const char* name, const char* split, unsigned int& t)
{
    S_00d30f50_MonitorStream& mStream = S_00d30f50_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        S_00d30f50_TimerBeginListCommand* h = (S_00d30f50_TimerBeginListCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->m_pFirst = split;
        _ReadWriteBarrier();
        h->setTime(t);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

static inline void S_00d30f50_Timer(const char* name, unsigned int& t)
{
    S_00d30f50_MonitorStream& mStream = S_00d30f50_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        S_00d30f50_TimerCommand* h = (S_00d30f50_TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        h->setTime(t);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct S_00d30f50_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00d30f50_Router
{
    int unk00, unk04, unk08, unk0C;
    S_00d30f50_Heap* unk10;
    static S_00d30f50_Router& FUN_00c85750();
    S_00d30f50_Heap& heap()
    {
        return *unk10;
    }
};

template <class T> struct S_00d30f50_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T* begin()
    {
        return m_data;
    }
    T* end()
    {
        return m_data + m_iElementCount;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    void _clearAndDeallocate(S_00d30f50_Heap& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~S_00d30f50_Array() throw()
    {
        _clearAndDeallocate(S_00d30f50_Router::FUN_00c85750().heap());
    }
};

template <class T, int N> struct S_00d30f50_InplaceArray : S_00d30f50_Array<T>
{
    T m_kStorage[N];
    S_00d30f50_InplaceArray() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
    ~S_00d30f50_InplaceArray() throw()
    {}
};

struct __declspec(align(16)) S_00d30f50_ShapeBuffer
{
    unsigned int m_data[128];
};

struct __declspec(align(16)) S_00d30f50_Aabb
{
    float m_kMinimumCorner[4];
    float m_kMaximumCorner[4];
};

struct S_00d30f50_ShapeContainer;

struct S_00d30f50_Shape
{
    virtual ~S_00d30f50_Shape();
    int unk04;
    int unk08;
    int m_type;
    int getType() const
    {
        return m_type;
    }
};

struct S_00d30f50_ShapeContainer
{
    virtual ~S_00d30f50_ShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int oldKey) const;
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
    virtual const S_00d30f50_Shape* GetShapeForKey(unsigned int key, S_00d30f50_ShapeBuffer& buffer) const;
};

struct S_00d30f50_BvTreeShape : S_00d30f50_Shape
{
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual const S_00d30f50_ShapeContainer* GetShapeContainer() const;
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void GetAabbHits(const S_00d30f50_Aabb& aabb, S_00d30f50_Array<unsigned int>& hits) const;
};

struct S_00d30f50_MotionState;

struct S_00d30f50_CdBody
{
    const S_00d30f50_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00d30f50_MotionState* m_pMotionState;
    const S_00d30f50_CdBody* m_parent;

    S_00d30f50_CdBody(const S_00d30f50_CdBody* parent)
    {
        m_parent = parent;
        m_pMotionState = parent->m_pMotionState;
    }
    void SetCollisionShapeAndKey(const S_00d30f50_Shape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
    const S_00d30f50_Shape* getShape() const
    {
        return m_pCollisionShape;
    }
};

struct S_00d30f50_LinearCastInput;
struct S_00d30f50_CdPointCollector;

typedef void(__cdecl* S_00d30f50_LinearCastFunc)(const S_00d30f50_CdBody& bodyA, const S_00d30f50_CdBody& bodyB,
                                                 const S_00d30f50_LinearCastInput& input,
                                                 S_00d30f50_CdPointCollector& collector,
                                                 S_00d30f50_CdPointCollector* startCollector);

struct S_00d30f50_Agent2Funcs
{
    void* m_pCreateFunc;
    void* m_pQueryPenetrationsFunc;
    void* m_getClosestPointsFunc;
    S_00d30f50_LinearCastFunc m_pLinearCastFunc;
    void* unk10;
};

struct S_00d30f50_Dispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    S_00d30f50_Agent2Funcs m_agent2Funcs[32];

    S_00d30f50_LinearCastFunc getLinearCastFunc(int typeA, int typeB) const
    {
        int idx = m_agent2TypeMap[typeA][typeB];
        return m_agent2Funcs[idx].m_pLinearCastFunc;
    }
};

struct S_00d30f50_LinearCastInput
{
    S_00d30f50_Dispatcher* m_pCollisionDispatcher;
};

void __cdecl hkpBvTreeAgent_staticLinearCast(const S_00d30f50_CdBody& bodyA, const S_00d30f50_CdBody& bodyB,
                          const S_00d30f50_LinearCastInput& input, S_00d30f50_CdPointCollector& collector,
                          S_00d30f50_CdPointCollector* startCollector) throw();

// Performs a linear cast against a BvTree shape by querying AABB hits and dispatching narrow-phase linear cast for each hit shape.
// @f3 0x009b9ff0 (community match, verified in this file)
void __cdecl FUN_009ba7e0(const S_00d30f50_CdBody& bodyA, const S_00d30f50_CdBody& bodyB, const S_00d30f50_LinearCastInput& input, S_00d30f50_Aabb& aabb);

extern DWORD DAT_010f3170;

struct S_00d30f50_BvTreeShapeFix
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual const S_00d30f50_ShapeContainer* GetShapeContainer() const;
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void GetAabbHits(const S_00d30f50_Aabb& aabb, S_00d30f50_Array<unsigned int>& hits) const;
};

struct S_00d30f50_TlsAlloc
{
    void FUN_008f6d90(void* p, unsigned int numBytes, int tag);
};

struct S_00d30f50_HitStorage
{
    unsigned int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[128];
};

extern DWORD DAT_0116913c;

static inline S_00d30f50_MonitorStream& S_00d30f50_Stream116()
{
    return *(S_00d30f50_MonitorStream*)TlsGetValue(DAT_0116913c);
}

static inline void S_00d30f50_BeginList116(const char* name, const char* split, unsigned int& t)
{
    S_00d30f50_MonitorStream& mStream = S_00d30f50_Stream116();
    if (mStream.memoryAvailable())
    {
        S_00d30f50_TimerBeginListCommand* h = (S_00d30f50_TimerBeginListCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->m_pFirst = split;
        _ReadWriteBarrier();
        h->setTime(t);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

static inline void S_00d30f50_Timer116(const char* name, unsigned int& t)
{
    S_00d30f50_MonitorStream& mStream = S_00d30f50_Stream116();
    if (mStream.memoryAvailable())
    {
        S_00d30f50_TimerCommand* h = (S_00d30f50_TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        h->setTime(t);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

// pdb: hkpBvTreeAgent::staticLinearCast | hkpBvTreeAgent.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkpBvTreeAgent_staticLinearCast(const S_00d30f50_CdBody& bodyA, const S_00d30f50_CdBody& bodyB,
                          const S_00d30f50_LinearCastInput& input, S_00d30f50_CdPointCollector& collector,
                          S_00d30f50_CdPointCollector* startCollector) throw()
{
    unsigned int timerTmp;
    S_00d30f50_BeginList116("LtBvTree", "StQueryTree", timerTmp);

    S_00d30f50_Aabb aabb;
    FUN_009ba7e0(bodyA, bodyB, input, aabb);

    const S_00d30f50_BvTreeShape* pBvTreeShapeB = static_cast<const S_00d30f50_BvTreeShape*>(bodyB.getShape());
    S_00d30f50_HitStorage hitStorage;
    hitStorage.m_data = hitStorage.m_kStorage;
    hitStorage.m_iElementCount = 0;
    hitStorage.m_iCapacityState = 128 | 0x80000000;
    S_00d30f50_Array<unsigned int>& hitList = *(S_00d30f50_Array<unsigned int>*)&hitStorage;
    ((const S_00d30f50_BvTreeShapeFix*)pBvTreeShapeB)->GetAabbHits(aabb, hitList);

    S_00d30f50_Timer116("StNarrowPhase", timerTmp);

    {
        int typeA = bodyA.getShape()->getType();
        unsigned int* itr = hitList.begin();
        unsigned int* end = hitList.end();
        S_00d30f50_CdBody modifiedBodyB(&bodyB);
        const S_00d30f50_ShapeContainer* shapeContainer = ((const S_00d30f50_BvTreeShapeFix*)pBvTreeShapeB)->GetShapeContainer();
        for (; itr != end; itr++)
        {
            S_00d30f50_ShapeBuffer shapeBuffer;
            const S_00d30f50_Shape* shape = shapeContainer->GetShapeForKey(*itr, shapeBuffer);
            modifiedBodyB.SetCollisionShapeAndKey(shape, *itr);
            S_00d30f50_LinearCastFunc linCastFunc =
                input.m_pCollisionDispatcher->getLinearCastFunc(typeA, shape->getType());
            linCastFunc(bodyA, modifiedBodyB, input, collector, startCollector);
        }
    }

    S_00d30f50_Timer116("lt", timerTmp);

    if (((unsigned int)hitStorage.m_iCapacityState & 0x80000000u) != 0)
    {
        return;
    }
    unsigned int count = (unsigned int)hitStorage.m_iCapacityState & 0x3fffffff;
    S_00d30f50_TlsAlloc* alloc = (S_00d30f50_TlsAlloc*)TlsGetValue(DAT_010f3170);
    alloc->FUN_008f6d90(hitStorage.m_data, count * 4, 0x17);
}


namespace fnv_00d2fa40 {
struct FloatSub
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
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    float m_a0;
};

struct FloatOwner
{
    int unk00;
    int unk04;
    FloatSub* m_08;
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

class SlotAllocator
{
  public:
    virtual void* vSlot0();
    virtual void* Alloc(unsigned int size);
};

struct SpawnedObject
{
    virtual ~SpawnedObject()
    {}
    unsigned short m_04;
    SpawnedObject* FUN_00d2f980(int arg);
};

AllocHolder* FUN_00c85750();

// Allocates a 0x40-byte object and calls FUN_00d2f980 with a4; unless the first m_a0 is less than the second, it then calls the destructor; returns the object.
// @fnv 0x00d2fa40
SpawnedObject* FUN_00d2fa40(FloatOwner* apFirstOwner, FloatOwner* apSecondOwner, int aiUnused, int a4)
{
    FloatSub* pFirstSub = apFirstOwner->m_08;
    FloatSub* pSecondSub = apSecondOwner->m_08;
    if (pFirstSub->m_a0 < pSecondSub->m_a0)
    {
        AllocHolder* holder = FUN_00c85750();
        SlotAllocator* alloc = (SlotAllocator*)holder->m_pAllocator;
        SpawnedObject* obj = (SpawnedObject*)alloc->Alloc(0x40);
        obj->m_04 = 0x40;
        return obj->FUN_00d2f980(a4);
    }
    AllocHolder* holder = FUN_00c85750();
    SlotAllocator* alloc = (SlotAllocator*)holder->m_pAllocator;
    SpawnedObject* obj = (SpawnedObject*)alloc->Alloc(0x40);
    obj->m_04 = 0x40;
    obj->FUN_00d2f980(a4);
    obj->SpawnedObject::~SpawnedObject();
    return obj;
}
}  // namespace fnv_00d2fa40

namespace fnv_00d314e0 {
// Descriptor record built on the stack: four callback slots plus two flag bytes.
struct DescRecord
{
    void (*fn0)();
    void (*fn1)();
    void (*fn2)();
    void (*fn3)();
    unsigned char flagA;
    unsigned char flagB;
};

// Stand-in class for the thiscall helper.
struct SpawnedObject
{
    void FUN_00cfbbe0(DescRecord* rec, int a, int b);
};

extern "C" void FUN_00d2fa00();
extern "C" void FUN_00d2e970();
extern "C" void FUN_00d2e9b0();
extern "C" void FUN_00d2e9f0();
extern "C" void FUN_00d2f9d0();
extern "C" void hkpBvTreeAgent_staticGetPenetrations();
extern "C" void FUN_00d31110();
extern "C" void hkpBvTreeAgent_staticLinearCast();
extern "C" void FUN_00d2fa40();

// Sets up three DescRecord entries with function pointers and flags, then passes each to self->FUN_00cfbbe0 with different index pairs.
// @fnv 0x00d314e0
void FUN_00d314e0(SpawnedObject* self)
{
    DescRecord desc;
    desc.fn0 = FUN_00d2fa00;
    desc.fn1 = FUN_00d2e970;
    desc.fn2 = FUN_00d2e9b0;
    desc.fn3 = FUN_00d2e9f0;
    desc.flagA = 1;
    desc.flagB = 1;
    self->FUN_00cfbbe0(&desc, 8, -1);

    desc.fn0 = FUN_00d2f9d0;
    desc.fn1 = hkpBvTreeAgent_staticGetPenetrations;
    desc.fn2 = FUN_00d31110;
    desc.fn3 = hkpBvTreeAgent_staticLinearCast;
    desc.flagA = 0;
    desc.flagB = 1;
    self->FUN_00cfbbe0(&desc, -1, 8);

    desc.fn0 = FUN_00d2fa40;
    desc.fn1 = hkpBvTreeAgent_staticGetPenetrations;
    desc.fn2 = FUN_00d31110;
    desc.fn3 = hkpBvTreeAgent_staticLinearCast;
    desc.flagA = 0;
    desc.flagB = 1;
    self->FUN_00cfbbe0(&desc, 8, 8);
}
}  // namespace fnv_00d314e0

struct S00d31110_Shape;

struct S00d31110_Body
{
    S00d31110_Shape* m_pCollisionShape;
    unsigned int m_key;
    void* m_pMotionState;
    S00d31110_Body* m_parent;

    void SetCollisionShapeAndKey(S00d31110_Shape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_key = key;
    }
};

struct S00d31110_Array
{
    unsigned int* m_data;
    int m_iElementCount;
    int m_capFlags;
};

struct S00d31110_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual S00d31110_Shape* GetShapeContainer();
    virtual S00d31110_Shape* GetShapeForKey(unsigned int key, void* buffer);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void GetAabbHits(void* aabb, S00d31110_Array* hits);
    int unk04;
    int unk08;
    int m_type;
};

typedef void(__cdecl* S00d31110_Func)(S00d31110_Body* a, S00d31110_Body* b, void* input, void* collector);

// Computes the AABB of bodyB, collects shape hits, and dispatches collision callbacks for each enabled child shape via the dispatcher.
// @f3 0x009ba1b0 (community match, verified in this file)
extern unsigned long DAT_0116913c,DAT_010f3170;
extern const char DAT_00e7eb94[],DAT_00e7e9a0[],DAT_00e7eb84[],DAT_00e0811c[];
typedef void*(__stdcall* TlsGetter518)(unsigned long);
struct Monitor518 {void* begin;char* cursor;void* unused;char* end;};
struct Timer518 {const char* name;unsigned int ticks,unused;};
struct ListTimer518 {const char* name;unsigned int ticks,unused;const char* section;};
struct __declspec(align(16)) Vector518 {float x,y,z,w;};
struct __declspec(align(16)) Transform518 {
 Vector518 columns[4];
 void FUN_00925300(const Transform518*,const Transform518*);
};
struct __declspec(align(16)) Aabb518 {Vector518 low,high;};
struct KeyArray518 {unsigned int* data;int size;int capacity;unsigned int storage[128];};
struct Shape518;
struct Container518 {
 virtual void slot00();virtual void slot04();virtual void slot08();virtual void slot0c();virtual void slot10();
 virtual Shape518* GetChild(unsigned int,S_00d30f50_ShapeBuffer&);
};
struct Shape518 {
 virtual void slot00();virtual void slot04();virtual void slot08();virtual void slot0c();virtual void slot10();
 virtual Container518* GetContainer();
 virtual void slot18();
 virtual void GetAabb(const Transform518&,float,Aabb518&);
 virtual void slot20();virtual void slot24();virtual void slot28();
 virtual void GetAabbHits(const Aabb518&,KeyArray518&);
 int memoryFlags,userData,type;
};
struct Body518 {Shape518* shape;unsigned int key;void* motion;Body518* parent;  __forceinline void SetShapeAndKey(Shape518* s,unsigned int k){shape=s;key=k;} };
struct Input518;
struct Filter518 {
 virtual void slot00();
 virtual const bool* Enabled(bool*,Input518*,Body518*,Body518*,Container518*,unsigned int);
};
typedef void(__cdecl* Callback518)(Body518*,Body518*,Input518*,void*);
struct CallbackEntry518 {Callback518 callback;int fields04,fields08,fields0c,fields10;};
struct Dispatcher518 {unsigned char types[0x9a8];CallbackEntry518 entries[1];};
struct Input518 {Dispatcher518* dispatcher;float tolerance;Filter518* filter;};
struct Heap518 {void FUN_008f6d90(void*,int,int);};
// pdb: hkpBvTreeAgent::staticGetClosestPoints | hkpBvTreeAgent.obj | fnv360_0822_retail, call_seq, high
// pdb params: bodyA, bodyB, input, collector
extern "C" void __cdecl FUN_00d31110(void* apBodyA,void* apBodyB,void* apInput,void* collector)
{
 TlsGetter518 getTls=TlsGetValue;
 Body518* a=static_cast<Body518*>(apBodyA);
 Body518* b=static_cast<Body518*>(apBodyB);
 Input518* input=static_cast<Input518*>(apInput);
 volatile unsigned int tick;
 {
  Monitor518* m=static_cast<Monitor518*>(getTls(DAT_0116913c));
  if(m->cursor<m->end) {
   ListTimer518* r=reinterpret_cast<ListTimer518*>(m->cursor);
   r->name=DAT_00e7eb94;r->section=DAT_00e7e9a0;
   _ReadWriteBarrier();tick=static_cast<unsigned int>(__rdtsc());r->ticks=tick;
   m->cursor=reinterpret_cast<char*>(r+1);
  }
 }
 Transform518 relative;
 relative.FUN_00925300(static_cast<const Transform518*>(b->motion),static_cast<const Transform518*>(a->motion));
 Aabb518 aabb;
 a->shape->GetAabb(relative,input->tolerance,aabb);
 Shape518* shape=b->shape;
 KeyArray518 hits;
 hits.data=hits.storage;hits.size=0;hits.capacity=static_cast<int>(0x80000080u);
 shape->GetAabbHits(aabb,hits);
 {
  Monitor518* m=static_cast<Monitor518*>(getTls(DAT_0116913c));
  if(m->cursor<m->end) {
   Timer518* r=reinterpret_cast<Timer518*>(m->cursor);
   r->name=DAT_00e7eb84;_ReadWriteBarrier();tick=static_cast<unsigned int>(__rdtsc());r->ticks=tick;
   m->cursor=reinterpret_cast<char*>(r+1);
  }
 }
 int typeA=a->shape->type;
 {
 unsigned int* it=hits.data;
 unsigned int* end=it+hits.size;
 Body518 child;
 child.motion=b->motion;
 child.parent=b;
 Container518* container=shape->GetContainer();
 S_00d30f50_ShapeBuffer buffer;
 bool enabled;
 for(;it!=end;++it) {
  if(*input->filter->Enabled(&enabled,input,a,b,container,*it)) {
   Shape518* childShape=container->GetChild(*it,buffer);
   child.SetShapeAndKey(childShape,*it);
   unsigned char index=input->dispatcher->types[(typeA+13)*32+child.shape->type];
   input->dispatcher->entries[index].callback(a,&child,input,collector);
  }
 }
 }
 {
  Monitor518* m=static_cast<Monitor518*>(getTls(DAT_0116913c));
  if(m->cursor<m->end) {
   Timer518* r=reinterpret_cast<Timer518*>(m->cursor);
   r->name=DAT_00e0811c;_ReadWriteBarrier();tick=static_cast<unsigned int>(__rdtsc());r->ticks=tick;
   m->cursor=reinterpret_cast<char*>(r+1);
  }
 }
 if((static_cast<unsigned int>(hits.capacity)&0x80000000u)==0) {
  int capacity=hits.capacity&0x3fffffff;
  Heap518* heap=static_cast<Heap518*>(getTls(DAT_010f3170));
  heap->FUN_008f6d90(hits.data,capacity*4,0x17);
 }
}

