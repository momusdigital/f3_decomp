#include "f3_common.h"
// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl hkpBvTreeAgent_staticGetPenetrations(void*, void*, void*, void*);

struct FUN_00d2dd30_class
{
    void __thiscall hkpBvTreeStreamAgent_getPenetrations(void* a, void* b, void* c, void* d);
};

// @fnv 0x00d2dd30
// pdb: hkpBvTreeStreamAgent::getPenetrations | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __thiscall FUN_00d2dd30_class::hkpBvTreeStreamAgent_getPenetrations(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    hkpBvTreeAgent_staticGetPenetrations(apArg1, apArg2, apArg3, apArg4);
}

extern "C" void __cdecl hkAgent1nMachine_InvalidateTim(void* a, void* b);

// hkpBvTreeStreamAgent: the members these functions use, at their Fallout 3 offsets (New Vegas Xbox 360 PDB names).
struct hkpBvTreeStreamAgentData
{
    int unk00;
    int unk04;
    int m_contactMgr;          // +0x08
    int m_dispatcher;          // +0x0C
    char m_cachedAabb[0x20];   // +0x10 hkAabb
    int m_agentTrack;          // +0x30 hkpAgent1nTrack (m_sectors first)
};
struct FUN_00d2ddd0_class : hkpBvTreeStreamAgentData
{
    void __thiscall FUN_00d2ddd0(int a);
};

// @fnv 0x00d2ddd0
void __thiscall FUN_00d2ddd0_class::FUN_00d2ddd0(int aiValue)
{
    hkAgent1nMachine_InvalidateTim(&m_agentTrack, (void*)aiValue);
}

extern "C" void __cdecl FUN_00d31110(void*, void*, void*, void*);
// @fnv 0x00d2dd50
// pdb: hkpBvTreeStreamAgent::getClosestPoints | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
extern "C" void __stdcall FUN_00d2dd50(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_00d31110(apArg1, apArg2, apArg3, apArg4);
}

void __cdecl hkpBvTreeAgent_staticLinearCast(void*, void*, void*, void*, void*);
struct OperationAdapter
{
    void FUN_00d2dd70(void* a, void* b, void* c, void* d, void* e);
};
// Forwards all five arguments to hkpBvTreeAgent_staticLinearCast.
// @fnv 0x00d2dd70
void OperationAdapter::FUN_00d2dd70(void* a, void* b, void* c, void* d, void* e)
{
    hkpBvTreeAgent_staticLinearCast(a, b, c, d, e);
}

struct FUN_00d2dda0_class
{
    virtual void finish(int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void __thiscall FUN_00d2dda0(int value);
};
extern void __cdecl hkAgent1nMachine_Destroy(void*, int, int, int);
// Passes unk0c, unk08 and value to hkAgent1nMachine_Destroy with &unk30, then calls finish(1).
// @fnv 0x00d2dda0
void FUN_00d2dda0_class::FUN_00d2dda0(int value)
{
    hkAgent1nMachine_Destroy(&unk30, unk0c, unk08, value);
    finish(1);
}

void __cdecl hkAgent1nMachine_WarpTime(void* self, float a, float b, void* c);
struct FUN_00d2ddf0_Class : hkpBvTreeStreamAgentData
{
    void __thiscall FUN_00d2ddf0(float a, float b, void* c);
};
// Warps the times of the agent track by the three arguments.
// @fnv 0x00d2ddf0
// pdb: hkpBvTreeStreamAgent::warpTime | hkpBvTreeStreamAgent.obj | tesv_win, vtable, medium
void __thiscall FUN_00d2ddf0_Class::FUN_00d2ddf0(float a, float b, void* c)
{
    hkAgent1nMachine_WarpTime(&m_agentTrack, a, b, c);
}

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

void FUN_00d2e680();
void FUN_00d2e970();
void FUN_00d2e9b0();
void FUN_00d2e9f0();
void FUN_00d2df50();

void FUN_00d31110();
void hkpBvTreeAgent_staticLinearCast();

typedef void*(__cdecl* S_00d2e8e0_CreateFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_GetPenetrationsFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_GetClosestPointsFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_LinearCastFunc)(void*, void*, void*, void*, void*);

void* hkpBvTreeStreamAgent_dispatchBvTreeConvexList(void*, void*, void*, void*);
void FUN_00d2e970(void*, void*, void*, void*);
void FUN_00d2e9b0(void*, void*, void*, void*);
void FUN_00d2e9f0(void*, void*, void*, void*, void*);
void* hkpBvTreeStreamAgent_dispatchConvexListBvTree(void*, void*, void*, void*);
void FUN_00d31110(void*, void*, void*, void*);
void hkpBvTreeAgent_staticLinearCast(void*, void*, void*, void*, void*);

extern float g_D2E9B0MaxDistance;

struct D2E9B0CollectorBase
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    float m_fEarlyOutDistance;

    D2E9B0CollectorBase() : m_fEarlyOutDistance(g_D2E9B0MaxDistance)
    {}
};

struct D2E9B0Collector : D2E9B0CollectorBase
{
    int m_iData;

    D2E9B0Collector(int iData) : m_iData(iData)
    {}

    virtual void unk00();
    virtual void unk04();
};

void __cdecl FUN_00d31110(int a, int b, int c, D2E9B0CollectorBase* collector);

// Constructs a D2E9B0Collector from d and passes it with b, a, c to FUN_00d31110.
// @fnv 0x00d2e9b0
// pdb: hkpSymmetricAgentLinearCast<hkpBvTreeAgent>::staticGetClosestPoints | hkpBvTreeStreamAgent.obj | fnv360_0721_beta, objrun_open, low
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d2e9b0(int aiArg1, int aiArg2, int aiArg3, int aiData)
{
    D2E9B0Collector collector(aiData);
    FUN_00d31110(aiArg2, aiArg1, aiArg3, &collector);
}

extern float DAT_0104da48;
struct hkpSymmetricAgentFlipCollector
{
    virtual void dispose();
    virtual void collect(float value);
    virtual void process(void* value);
    float threshold;
    void* object;
};
struct Context
{
    void FUN_00d43880(void* first, void* second, void* third, hkpSymmetricAgentFlipCollector* collector);
    void FUN_00d2edd0(void* first, void* second, void* third, void* fourth);
};
// Builds a collector with threshold DAT_0104da48 and object fourth, then calls FUN_00d43880 with second, first, third and the collector.
// @fnv 0x00d2edd0
// pdb: hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::getClosestPoints | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void Context::FUN_00d2edd0(void* first, void* second, void* third, void* fourth)
{
    hkpSymmetricAgentFlipCollector collector;
    collector.threshold = DAT_0104da48;
    collector.object = fourth;
    FUN_00d43880(second, first, third, &collector);
}

struct VisitTarget
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void Visit(int kind, const char* name, void* data, unsigned int size, void* extra)
    {}
    int unk04;
    int m_08;
    int unk0C;
    unsigned char m_10;
};

extern "C" const void* DAT_010ce81c;

struct Collector
{
    const void* vtable;
    char flip;
    void* collector;
};

// Builds a Collector on the stack with the given collector and vtable, then calls hkpBvTreeAgent_staticGetPenetrations with bodyB, bodyA, arg3 and the Collector.
// @fnv 0x00d2e970
// pdb: hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticGetPenetrations | hkpMoppBvTreeStreamAgent.obj | fnv360_0721_beta, objrun_open, low
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d2e970(void* bodyA, void* bodyB, void* arg3, void* orig_collector)
{
    Collector c;
    c.collector = orig_collector;
    c.flip = 0;
    c.vtable = &DAT_010ce81c;
    hkpBvTreeAgent_staticGetPenetrations(bodyB, bodyA, arg3, &c);
}

struct FUN_00d2eb50_nib
{
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct FUN_00d2eb50_cls
{
    unsigned short m_w00;
    unsigned short m_w02;
    unsigned short m_w04;
    unsigned char m_unk06;
    unsigned char m_unk07;
    unsigned char m_b08;
    unsigned char m_b09;
    FUN_00d2eb50_nib m_nib0a;
    void __thiscall SwapFields();
};

// @fnv 0x00d2eb50
// pdb: hkAgent1nMachine_flipInput | hkpAgent1nMachineProcess.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkpGskCache::flip)
void FUN_00d2eb50_cls::SwapFields()
{
    unsigned char lo = m_nib0a.lo;
    m_nib0a.lo = m_nib0a.hi;
    m_nib0a.hi = lo;

    unsigned char t = m_b08;
    m_b08 = m_b09;
    m_b09 = t;

    unsigned short* w = (unsigned short*)this;
    unsigned int uiIndex = (unsigned int)m_b08 + (unsigned int)m_b09 - 1;
    unsigned short first = w[0];
    unsigned short usTemp = w[uiIndex];
    w[0] = usTemp;
    w[uiIndex] = first;

    if ((unsigned char)(m_b08 & m_b09) == 2)
    {
        unsigned short a = m_w02;
        m_w02 = m_w04;
        m_w04 = a;
    }
}

namespace fnv_00d2ebb0 {
extern char DAT_010ce81c;

struct FUN_00d2ebb0_tmp
{
    const void* vt;
    unsigned char flag;
    unsigned int a4;
};

struct FUN_00d2dd30_obj
{
    void __thiscall hkpBvTreeStreamAgent_getPenetrations(void* a, void* b, void* c, void* d);
};

struct FUN_00d2ebb0_cls
{
    void __thiscall DispatchWithFlag(void* a1, void* a2, void* a3, unsigned int a4);
};

// Builds a temporary holding a4 and a zero flag with a vtable pointer, then forwards a2, a1, a3 and the temporary to hkpBvTreeStreamAgent_getPenetrations.
// @fnv 0x00d2ebb0
// pdb: hkpSymmetricAgentLinearCast<hkpBvTreeStreamAgent>::getPenetrations | hkpBvTreeStreamAgent.obj | fnv360_0721_beta, vtable, high
// pdb params: bodyA, bodyB, input, collector
void FUN_00d2ebb0_cls::DispatchWithFlag(void* a1, void* a2, void* a3, unsigned int a4)
{
    FUN_00d2ebb0_tmp t;
    t.a4 = a4;
    t.flag = 0;
    t.vt = &DAT_010ce81c;
    ((FUN_00d2dd30_obj*)this)->hkpBvTreeStreamAgent_getPenetrations(a2, a1, a3, &t);
}
}  // namespace fnv_00d2ebb0

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
    void FUN_00d2dd50(void*, void*, unsigned int, CpuCallData*);
    void DispatchWithBoundData(void*, void*, unsigned int, unsigned int);
};
// Builds a CpuCallData from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first, third and the data to FUN_00d2dd50.
// @fnv 0x00d2ebf0
// pdb: hkpSymmetricAgentLinearCast<hkpBvTreeStreamAgent>::getClosestPoints | hkpBvTreeStreamAgent.obj | fnv360_0721_beta, vtable, high
// pdb params: bodyA, bodyB, input, collector
void CpuObject::DispatchWithBoundData(void* first, void* second, unsigned int third, unsigned int fourth)
{
    CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d2dd50(second, first, third, &data);
}

struct CallTarget_00d2de20
{
    int FUN_00d2de20(int, int, int, int);
};
struct SearchObject
{
    int CallTarget(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d2ec30
// pdb: hkpSymmetricAgentLinearCast<hkpBvTreeStreamAgent>::updateShapeCollectionFilter | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, constraintOwner
int SearchObject::CallTarget(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00d2de20*)this)->FUN_00d2de20((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)callResult0;
}

namespace fnv_00d2ed70 {
struct CallTarget_00d43f10
{
    int FUN_00d43f10(int, int, int, int);
};
struct SearchObject
{
    int FUN_00d2ed70(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d2ed70
// pdb: hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::updateShapeCollectionFilter | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, constraintOwner
int SearchObject::FUN_00d2ed70(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00d43f10*)this)->FUN_00d43f10((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)callResult0;
}
}  // namespace fnv_00d2ed70

// Havok style body collector: a virtual table pointer, an "active" flag and a payload pointer.
struct hkpCollectorBase
{
    char active;
    hkpCollectorBase()
    {
        active = 0;
    }
};

struct hkpSymmetricAgentFlipBodyCollector : hkpCollectorBase
{
    virtual void addBody();
    virtual void reset();
    void* payload;
};

// Game side wrapper that fills the collector and hands it to the query routine.
struct FUN_00d43cd0_class
{
    void __thiscall hkpShapeCollectionAgent_getPenetrations(void* a, void* b, void* c, void* d);
    void __thiscall FUN_00d2ed90(void* a1, void* a2, void* a3, void* a4);
};

// Builds a flip-body collector holding a4 and forwards a2, a1, a3 and the collector to hkpShapeCollectionAgent_getPenetrations.
// @fnv 0x00d2ed90
// pdb: hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::getPenetrations | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void __thiscall FUN_00d43cd0_class::FUN_00d2ed90(void* a1, void* a2, void* a3, void* apPayload)
{
    hkpSymmetricAgentFlipBodyCollector collector;
    collector.payload = apPayload;
    this->hkpShapeCollectionAgent_getPenetrations(a2, a1, a3, &collector);
}

#include <xmmintrin.h>
extern "C" void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(void* a, void* b);

struct FUN_00d2de20_obj
{
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual int vSlot10();
};

struct __declspec(align(16)) ArgPack
{
    int m_00;
    void* m_04;
    int unk08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
};

struct FUN_00d2de20_cls
{
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    __m128 m_10;
    __m128 m_20;
    int m_30;

    void FUN_00d2de20(int a0, FUN_00d2de20_obj** a1, int a2, int a3);
};

// Zeroes m_10 and m_20, builds an ArgPack from a0, a1, a2, m_08, a3 and the vSlot10 result, then calls hkAgent1nMachine_UpdateShapeCollectionFilter with m_30 and the pack.
// @fnv 0x00d2de20
void FUN_00d2de20_cls::FUN_00d2de20(int a0, FUN_00d2de20_obj** a1, int a2, int a3)
{
    m_10 = _mm_setzero_ps();
    m_20 = _mm_setzero_ps();
    ArgPack args;
    int r = (*a1)->vSlot10();
    args.m_00 = a0;
    args.m_04 = a1;
    args.m_10 = a2;
    args.m_14 = m_08;
    args.m_0C = r;
    args.m_18 = a3;
    hkAgent1nMachine_UpdateShapeCollectionFilter(&m_30, &args);
}

struct FUN_00d2def0_cls
{
    int m_vptr;
    unsigned short unk04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    __m128 m_10;
    __m128 m_20;
    int m_30;
    int m_34;
    unsigned int m_38;

    FUN_00d2def0_cls* FUN_00d2def0(void* a1, void* a2, int* a3, int a4);
};

extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d2e9
{
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union
    {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9
{
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

void __cdecl hkpBvTreeAgent_staticLinearCast(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

namespace fnv_00d2ec50 {
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

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void FUN_00d2df90(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void FUN_00d2ec50(int a, int b, int c, Simplex* s);
};

}  // namespace fnv_00d2ec50

namespace fnv_00d2ef30 {
extern float DAT_0104da48;
extern unsigned int DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct Vector4f
{
    int x, y, z, w;
};

__declspec(align(16)) struct QueryObj
{
    const void* vtable;
    float scale;
    int unk08;
    int unk0c;
    Vector4f vec;
    int extra;
    void Init(const Vector4f& v, int e)
    {
        vtable = &DAT_010ce80c;
        scale = DAT_0104da48;
        vec = v;
        extra = e;
    }
};

}  // namespace fnv_00d2ef30

namespace fnv_00d2f000 {
extern float DAT_0104da48;
extern __m128 DAT_010c44d0;

struct S_00d2f000_V4
{
    unsigned x, y, z, w;
};

struct S_00d2f000_Base
{
    float m_f04;
    unsigned unk08, unk0C;
    S_00d2f000_V4 m_v10;
    unsigned m_p20;
    unsigned unk24, unk28, unk2C;
    S_00d2f000_Base()
    {}
    S_00d2f000_Base(float f, const S_00d2f000_V4& v, unsigned p)
    {
        m_f04 = f;
        m_v10 = v;
        m_p20 = p;
    }
};

struct __declspec(align(16)) S_00d2f000_Flip : public S_00d2f000_Base
{
    S_00d2f000_Flip()
    {}
    S_00d2f000_Flip(float f, const S_00d2f000_V4& v, unsigned p) : S_00d2f000_Base(f, v, p)
    {}
    virtual void vtbl00(void);
    virtual void vtbl04(void);
};

}  // namespace fnv_00d2f000

namespace fnv_00d2e5a0 {
struct Allocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* m_pAllocator;
};

AllocHolder* FUN_00c85750();

struct FUN_00d2def0_cls
{
    void* FUN_00d2def0(void* a, void* b, void* c, void* d);
};

struct SpawnedObject
{
    virtual ~SpawnedObject() throw()
    {}
    unsigned short m_iElementCount;
};

// Allocates and constructs a 0x40 or 0x38 byte object chosen by a3's Select(a1, a2, a3) when a4 is non-zero; with a4 zero it builds a 0x40 one and destructs it.
// @f3 0x009b6cf0 (community match, verified in this file)
namespace f_009b6cf0 {
struct Sel
{
    virtual void Unknown0() = 0;
    virtual void Unknown1() = 0;
    virtual void Unknown2() = 0;
    virtual int Classify(void* second, void* first, void* context) = 0;
};
struct Ctx
{
    unsigned int unk00, unk04, unk08;
    Sel* selector;
};
struct Heap
{
    void* __thiscall FUN_008f6d30(int size, int align);
};
extern void* DAT_010f3170;
extern Heap* (__stdcall* DAT_00d9b080)(void*);
extern void* g_00e7ea34[];
struct Hdr
{
    void** vtable;
    unsigned short size, unk06;
};
struct Init56View
{
    void* FUN_009d1db0(void* second, void* first, void* context, unsigned int flags);
};
struct Init64View
{
    void* FUN_009b5e00(void* second, void* first, void* context, unsigned int flags);
};
struct O64 : Hdr
{
    void FUN_009b5e00(void* second, void* first, void* context, unsigned int flags);
};
static __forceinline O64* Make64(void* second, void* first, void* context, unsigned int flags)
{
    Heap* heap = DAT_00d9b080(DAT_010f3170);
    O64* obj = (O64*)heap->FUN_008f6d30(0x40, 0x1f);
    obj->size = 0x40;
    obj->FUN_009b5e00(second, first, context, flags);
    obj->vtable = g_00e7ea34;
    return obj;
}
}
void* __cdecl hkpBvTreeStreamAgent_dispatchConvexListBvTree(void* second, void* first, void* context, void* flags);
namespace fnv_00d2e5a0 { void* __cdecl hkpBvTreeStreamAgent_dispatchConvexListBvTree(void* second, void* first, void* context, void* flags); }
// pdb: hkpBvTreeStreamAgent::dispatchConvexListBvTree | hkpBvTreeStreamAgent.obj | fnv360_0822_debug, objrun + bridge(caller_sim|caller_sim) + skyrim(objrun), high
void* __cdecl ::fnv_00d2e5a0::hkpBvTreeStreamAgent_dispatchConvexListBvTree(void* second, void* first, void* context, void* flags)
{
    if (flags)
    {
        switch (reinterpret_cast<f_009b6cf0::Ctx*>(context)->selector->Classify(second, first, context))
        {
        case 1:
        {
            f_009b6cf0::Heap* heap = f_009b6cf0::DAT_00d9b080(f_009b6cf0::DAT_010f3170);
            f_009b6cf0::Hdr* obj = static_cast<f_009b6cf0::Hdr*>(heap->FUN_008f6d30(0x38, 0x1f));
            obj->size = 0x38;
            return reinterpret_cast<f_009b6cf0::Init56View*>(obj)->FUN_009d1db0(second, first, context,
                                                                                 reinterpret_cast<unsigned int>(flags));
        }
        case 0:
        case 2:
        {
            f_009b6cf0::Heap* heap = f_009b6cf0::DAT_00d9b080(f_009b6cf0::DAT_010f3170);
            f_009b6cf0::Hdr* obj = static_cast<f_009b6cf0::Hdr*>(heap->FUN_008f6d30(0x40, 0x1f));
            obj->size = 0x40;
            return reinterpret_cast<f_009b6cf0::Init64View*>(obj)->FUN_009b5e00(second, first, context,
                                                                                 reinterpret_cast<unsigned int>(flags));
        }
        default:
            return 0;
        }
    }
    return f_009b6cf0::Make64(first, second, context, 0);
}

}  // namespace fnv_00d2e5a0

inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

struct hkpBvTreeStreamAgent
{
    virtual void Destroy();
    unsigned short unk04;
    hkpBvTreeStreamAgent(void* a, void* b, void* c, void* d);
};

template <class Agent> struct hkpSymmetricAgent : Agent
{
    hkpSymmetricAgent(void* a, void* b, void* c, void* d) : Agent(b, a, c, d)
    {}
    virtual void Destroy();
};

namespace fnv_00d2e6d0 {

extern "C"
{
    void FUN_00d2e680();
    void FUN_00d2e970();
    void FUN_00d2e9b0();
    void FUN_00d2e9f0();

    void FUN_00d2df50();
    void FUN_00d31110();
    void hkpBvTreeAgent_staticLinearCast();
}

}  // namespace fnv_00d2e6d0

namespace fnv_00d2eae0 {
// ---------------------------------------------------------------------------
// The agent object that the game tears down in FUN_00d2eae0.
//
// The first word of the object holds the vtable pointer.  While the agent is
// alive the pointer refers to the table of the agent class, once the agent
// has been released it is reset to the table of the base class.
// ---------------------------------------------------------------------------

// A vtable: a list of function pointers.
struct VTable
{
    void* entries[4];
};

struct hkpBvTreeStreamAgent
{
    const VTable* vtbl;    // +0x00
    unsigned short id;     // +0x04
    unsigned short unk06;  // +0x06
    void* unk08;           // +0x08
    int unk0c;             // +0x0c
    int unk10;             // +0x10
    int unk14;             // +0x14
    int unk18;             // +0x18
    int unk1c;             // +0x1c
    int unk20;             // +0x20
    int unk24;             // +0x24
    int unk28;             // +0x28
    int unk2c;             // +0x2c
    void* buffer;          // +0x30
    int unk34;             // +0x34
    int unk38;             // +0x38

    void* __thiscall FUN_00d2eae0(unsigned int flags);
};

// The functions the vtables of the agent class and of its base class point
// at (the game keeps them in the tables).
void __cdecl AgentRelease(void* agent, unsigned short id);
void __cdecl AgentFlush(void* buffer, int bytes);

// The vtables of the agent class and of its base class.
static const VTable g_vtblAgent = {
    {(void*)&AgentRelease, (void*)&AgentFlush, (void*)&AgentRelease, (void*)&AgentFlush}};

static const VTable g_vtblBase = {{(void*)&AgentFlush, (void*)&AgentRelease, (void*)&AgentFlush, (void*)&AgentRelease}};

// The handler that owns the agents.
struct AgentHandler
{
    virtual void unk00();
    virtual void unk04();
    virtual void release(hkpBvTreeStreamAgent* agent, unsigned short id);
    virtual void unk0c();
    virtual void flush(void* buffer, int bytes);
};

// The global that hands out the manager of the agents.
struct AgentManagerHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    AgentHandler* unk10;
};

extern "C" AgentManagerHolder* __cdecl FUN_00c85750();

}  // namespace fnv_00d2eae0

struct StreamDispatchInput;
struct Selector
{
    virtual void Unknown0() = 0;
    virtual void Unknown1() = 0;
    virtual void Unknown2() = 0;
    virtual int Classify(void* second, void* first, StreamDispatchInput* context) = 0;
};
struct StreamDispatchInput
{
    unsigned int unk00, unk04, unk08, unk0c;
    Selector* selector;
};
extern "C" void* g_010ce8b0[];
extern "C" void* g_010ce874[];
struct Header
{
    void** vtable;
    unsigned short size, unk06;
};
struct Obj56 : Header
{
    void FUN_00d440f0(void* second, void* first, StreamDispatchInput* context, unsigned int flags);
};
struct Obj64 : Header
{
    void FUN_00d2def0(void* second, void* first, StreamDispatchInput* context, unsigned int flags);
};
static __forceinline Obj56* Create56(void* second, void* first, StreamDispatchInput* context, unsigned int flags)
{
    AudioMgr* owner = audio();
    hkMemoryAllocator* allocator = owner->unk10;
    Obj56* obj = static_cast<Obj56*>(allocator->AllocateMemoryBlock(0x38));
    obj->size = 0x38;
    obj->FUN_00d440f0(second, first, context, flags);
    obj->vtable = g_010ce8b0;
    return obj;
}
static __forceinline Obj64* Create64(void* second, void* first, StreamDispatchInput* context, unsigned int flags)
{
    AudioMgr* owner = audio();
    hkMemoryAllocator* allocator = owner->unk10;
    Obj64* obj = static_cast<Obj64*>(allocator->AllocateMemoryBlock(0x40));
    obj->size = 0x40;
    obj->FUN_00d2def0(second, first, context, flags);
    obj->vtable = g_010ce874;
    return obj;
}
// Creates an Obj56 or Obj64 stream object based on the selector's classification, or a default Obj64 when flags is zero.
// @f3 0x009b6f40 (community match, verified in this file)
struct SelectorB
{
    virtual void Unknown0() = 0;
    virtual void Unknown1() = 0;
    virtual void Unknown2() = 0;
    virtual int Classify(void* second, void* first, void* context) = 0;
};
struct CtxB
{
    unsigned int unk00, unk04, unk08;
    SelectorB* selector;
};
struct HeapB
{
    void* __thiscall FUN_008f6d30(int size, int align);
};
extern "C" void* DAT_010f3170;
extern "C" HeapB* (__stdcall* DAT_00d9b080)(void*);
extern "C" void* g_00e7ea70[];
extern "C" void* g_00e7ea34[];
struct Obj56B : Header
{
    void FUN_009d1db0(void* second, void* first, void* context, unsigned int flags);
};
struct Obj64B : Header
{
    void FUN_009b5e00(void* second, void* first, void* context, unsigned int flags);
};
static __forceinline Obj56B* Make56B(void* second, void* first, void* context, unsigned int flags)
{
    HeapB* heap = DAT_00d9b080(DAT_010f3170);
    Obj56B* obj = (Obj56B*)heap->FUN_008f6d30(0x38, 0x1f);
    obj->size = 0x38;
    obj->FUN_009d1db0(second, first, context, flags);
    obj->vtable = g_00e7ea70;
    return obj;
}
static __forceinline Obj64B* Make64B(void* second, void* first, void* context, unsigned int flags)
{
    HeapB* heap = DAT_00d9b080(DAT_010f3170);
    Obj64B* obj = (Obj64B*)heap->FUN_008f6d30(0x40, 0x1f);
    obj->size = 0x40;
    obj->FUN_009b5e00(second, first, context, flags);
    obj->vtable = g_00e7ea34;
    return obj;
}
// pdb: hkpBvTreeStreamAgent::dispatchBvTreeConvexList | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, caller_sim + skyrim(objrun_prop), high
Header* hkpBvTreeStreamAgent_dispatchBvTreeConvexList(void* first, void* second, StreamDispatchInput* context, unsigned int flags)
{
    if (flags)
    {
        switch (reinterpret_cast<CtxB*>(context)->selector->Classify(second, first, context))
        {
        case 1:
            return Make56B(second, first, context, flags);
        case 0:
        case 2:
            return Make64B(second, first, context, flags);
        default:
            return 0;
        }
    }
    return Make64B(second, first, context, 0);
}

