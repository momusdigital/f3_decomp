#include "f3_common.h"
#include "havok/hkMonitorStream.h"
// src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct D3DD50CollectorBase
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    bool m_bFound;

    D3DD50CollectorBase() : m_bFound(false)
    {}
};

struct D3DD50Collector : D3DD50CollectorBase
{
    int m_iData;

    D3DD50Collector(int iData) : m_iData(iData)
    {}

    virtual void unk00();
    virtual void unk04();
};

void __cdecl D3DD50Query(int a, int b, int c, D3DD50CollectorBase* collector);

// Constructs a D3DD50Collector from d and passes it to D3DD50Query with b, a, c.
// @fnv 0x00d3dd50
// pdb: hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::staticGetPenetrations | hkpSphereBoxAgent.obj | fnv360_0822_retail, caller_sim, high
// pdb params: bodyA, bodyB, input, collector
void __cdecl QueryD3DCollector(int aiArg1, int aiArg2, int aiArg3, int aiData)
{
    D3DD50Collector collector(aiData);
    D3DD50Query(aiArg2, aiArg1, aiArg3, &collector);
}

extern char DAT_010ce7fc[];

struct Functor_d3e110
{
    void* m_vtbl;
    float m_fHitFraction;
    int m_uiFilterValue;
};

void __cdecl FUN_00d3d8c0(int a, int b, int c, Functor_d3e110* f);

// Builds a Functor_d3e110 with a max-float value and d, sets its vtable to DAT_010ce7fc, and calls FUN_00d3d8c0(b, a, c, &f).
// @fnv 0x00d3e110
// pdb: hkpSymmetricAgentLinearCast<hkpSphereTriangleAgent>::staticGetClosestPoints | hkpSphereTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d3e110(int a, int b, int aiArg3, int d)
{
    Functor_d3e110 f;
    f.m_fHitFraction = 3.40282e+38f;
    f.m_uiFilterValue = d;
    f.m_vtbl = DAT_010ce7fc;
    FUN_00d3d8c0(b, a, aiArg3, &f);
}

class hkClass;
class hkStatisticsCollector;
// hkpContactMgr, up to removeContactPointImpl (names from the New Vegas Xbox 360 PDB).
struct SpawnedInner
{
    virtual ~SpawnedInner();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual unsigned short addContactPointImpl();
    virtual int reserveContactPointsImpl(int numPoints);
    virtual void removeContactPointImpl(unsigned short cpId, void* constraintOwner);
};

// hkpSphereTriangleAgent (cleanup is slot 7 of its Fallout 3 vtable, 0x00e7f1c8)
class FUN_00d3d200_cls
{
  public:
    virtual ~FUN_00d3d200_cls();
    int m_unk04;              // +0x04
    SpawnedInner* m_pInner;   // +0x08
    unsigned short m_wFlags;  // +0x0C

    void hkpSphereTriangleAgent_cleanup(void* param);
};

// Removes the agent's contact point from the contact manager if it has one, then deletes the agent.
// @fnv 0x00d3d200
// pdb: hkpSphereTriangleAgent::cleanup | hkpSphereTriangleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void FUN_00d3d200_cls::hkpSphereTriangleAgent_cleanup(void* param)
{
    if (m_wFlags != 0xFFFF)
    {
        m_pInner->removeContactPointImpl(m_wFlags, param);
    }
    delete this;
}

struct hkMemory
{
    virtual void unk0();
    virtual void* allocateChunk(int size);
};

struct hkThreadMemory
{
    char pad[0x10];
    hkMemory* m_pMemoryAllocator;

    void* allocateChunk(int size)
    {
        return m_pMemoryAllocator->allocateChunk(size);
    }
};

extern "C" void __cdecl FUN_00cd7160(void* src, void* dst);
extern "C" const void* DAT_010cf060;
extern "C" const void* DAT_010cf09c;

struct TargetAgent
{
    const void* vtable;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pContactManager;
    unsigned short m_padC;
    short m_padE;
    char m_pAccessManager[0x10];

    TargetAgent(const void* bodyA, void* mgr)
        : m_usMemSizeAndFlags(0x20), m_sReferenceCount(1), m_pContactManager(mgr), m_padC(0xffff)
    {
        vtable = &DAT_010cf060;
        void* triangle = *(void**)bodyA;
        FUN_00cd7160((char*)triangle + 0x20, m_pAccessManager);
        vtable = &DAT_010cf09c;
    }
};

// Allocates a 0x20-byte chunk from the thread memory and constructs a TargetAgent from bodyA and mgr, returning it.
// @f3 0x009c2b20 (community match, verified in this file)
extern "C" unsigned long DAT_010f3170;
extern "C" const char DAT_00e7f064[];
extern "C" const char DAT_00e7f0a0[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
void __cdecl FUN_0096fd30(void*, void*);

struct CapsuleThreadMemorySlot3
{
    void* FUN_008f6d30(int size, int memoryClass);
};
struct CapsuleAgentSlot3
{
    const void* vtable;
    unsigned short memorySize;
    unsigned short referenceCount;
    void* contactManager;
    unsigned short index0;
    unsigned short index1;
    unsigned short index2;
    unsigned short unk12;
    float cache14;
    float cache18;
    float cache1C;
    float cache20;
    float cache24;
};
// pdb: hkpCapsuleTriangleAgent::createTriangleCapsuleAgent | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, uvref, high
// pdb params: bodyA, bodyB, input, mgr
void* __cdecl CreateTargetAgent(void* bodyA, void* bodyB, void* input, void* manager)
{
    CapsuleThreadMemorySlot3* memory = static_cast<CapsuleThreadMemorySlot3*>(TlsGetValue(DAT_010f3170));
    CapsuleAgentSlot3* agent = static_cast<CapsuleAgentSlot3*>(memory->FUN_008f6d30(0x28, 0x1f));
    agent->index0 = 0xffff;
    agent->index1 = 0xffff;
    agent->index2 = 0xffff;
    agent->contactManager = manager;
    agent->memorySize = 0x28;
    agent->referenceCount = 1;
    agent->vtable = DAT_00e7f064;
    void* triangle = *static_cast<void**>(bodyA);
    FUN_0096fd30(static_cast<char*>(triangle) + 0x20, &agent->cache14);
    agent->vtable = DAT_00e7f0a0;
    return agent;
}


extern char DAT_010ce81c[];

struct D3DD10Data
{
    void* vt;
    unsigned char flag;
    unsigned int value;
};

struct D3DD10Object
{
    void __thiscall FUN_00d3d2a0(unsigned int a1, unsigned int a2, unsigned int a3, D3DD10Data* data);

    void __thiscall FUN_00d3dd10(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3);
};

// Builds a D3DD10Data with value p3, flag 0 and vt DAT_010ce81c, then calls FUN_00d3d2a0 with p1, p0, p2 and that data.
// @fnv 0x00d3dd10
// pdb: hkpSymmetricAgentLinearCast<hkpSphereTriangleAgent>::getPenetrations | hkpSphereTriangleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void __thiscall D3DD10Object::FUN_00d3dd10(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int uiValue)
{
    D3DD10Data data;

    data.value = uiValue;
    data.flag = 0;
    data.vt = &DAT_010ce81c[0];

    this->FUN_00d3d2a0(p1, p0, p2, &data);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void setBroadcast3(const hkVector4q& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void addMul4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void xor4(const hkVector4q& b)
    {
        m_vComponents = _mm_xor_ps(m_vComponents, b.m_vComponents);
    }
    __forceinline void setXor4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, b.m_vComponents);
    }
};

typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);

extern "C"
{
    unsigned __int64 __rdtsc();
    void _ReadWriteBarrier();
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
}

extern "C" DWORD DAT_0126835c;

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct Res
{
    Vec4 pt;
    float d;
};

struct ProfRec
{
    const char* name;
    unsigned int tsc;
    unsigned int unk08;
};

struct ProfBuf
{
    unsigned int unk00;
    ProfRec* cur;
    unsigned int unk08;
    ProfRec* end;
};

struct XForm
{
    __m128 r0;
    __m128 r1;
    __m128 r2;
    __m128 t;
};

struct BodyB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct BodyHolderB
{
    BodyB* obj;
    int unk04;
    XForm* xf;
};

// hkpCdBodyPairCollector
struct Sink
{
    virtual ~Sink();
    virtual void addCdBodyPair(BodyHolderB& a, BodyHolderB& b);
};

extern void __cdecl FUN_00cd7850(Vec4* v, void* tri, float* f, Res* out, void* flag);

// non-POD 1-dword wrapper params: block the entry-enregister pass so the
// params are read lazily from their incoming arg slots (see e2fbc0)
struct BHWrap
{
    BodyHolderB* p;
    BHWrap(BodyHolderB* q) : p(q)
    {}
};

struct SinkWrap
{
    Sink* p;
    SinkWrap(Sink* q) : p(q)
    {}
};

class SphereTriAgent
{
  public:
    int unk00, unk04, unk08, unk0C;
    float unk10;
    void FUN_00d3d2a0(BodyHolderB* a, BodyHolderB* b, int c_, Sink* sink);
};

// Tests sphere-triangle collision between two bodies and calls the sink if the distance is within the combined radii.
// @f3 0x009c6fd0 (community match, verified in this file)
extern DWORD DAT_0116913c;
extern char DAT_00e7f23c, DAT_00e32798;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern void __cdecl hkpCollideTriangleUtil_closestPointTriangle(Vec4* projected, void* shape, const hkVector4q* axis, Res* result);

void SphereTriAgent::FUN_00d3d2a0(BodyHolderB* a, BodyHolderB* b, int c_, Sink* sink)
{
    BodyB* sphere;
    BodyB* tri;
    XForm* ma;
    XForm* mb;
    HK_TIMER_BEGIN("SphereTri", HK_NULL);

    sphere = a->obj;
    tri = b->obj;
    ma = a->xf;
    mb = b->xf;
    const float* translation = ma->t.m128_f32;
    float dx = translation[0] - mb->t.m128_f32[0];
    float dy = translation[1] - mb->t.m128_f32[1];
    float dz = translation[2] - mb->t.m128_f32[2];

    Vec4 projected;
    projected.x = mb->r0.m128_f32[0] * dx + mb->r0.m128_f32[1] * dy + mb->r0.m128_f32[2] * dz;
    projected.y = mb->r1.m128_f32[0] * dx + mb->r1.m128_f32[1] * dy + mb->r1.m128_f32[2] * dz;
    projected.z = mb->r2.m128_f32[0] * dx + mb->r2.m128_f32[1] * dy + mb->r2.m128_f32[2] * dz;
    projected.w = 0.0f;

    Res result;
    hkpCollideTriangleUtil_closestPointTriangle(&projected, (char*)tri+0x20, (const hkVector4q*)&unk10, &result);
    float combined = sphere->unk10 + tri->unk10;
    if (result.d < combined)
        sink->addCdBodyPair(*a, *b);

    HK_TIMER_END();
}


// rotate the translation difference by the inverse of B's rotation (HK_TRANSPOSE3), compute the
// closest point, and report a contact when the distance is below the summed radii.

extern DWORD DAT_0126835c;
extern char DAT_010cf0d4[];  // "TtSphereTri"
extern char DAT_010c41f8[];  // "Et"

struct S_00d3d3e0_Entry
{
    const char* name;
    unsigned time;
    int unk08;
};
struct S_00d3d3e0_Hdr
{
    int unk00;
    S_00d3d3e0_Entry* cur;
    int unk08;
    S_00d3d3e0_Entry* end;
};
struct __declspec(align(16)) S_00d3d3e0_V4
{
    float x, y, z, w;
};
struct S_00d3d3e0_Mat
{
    S_00d3d3e0_V4 r0, r1, r2, t;
};
struct S_00d3d3e0_Shape
{
    int unk00, unk04, unk08, unk0c;
    float f10;
};
struct S_00d3d3e0_Obj
{
    int unk00, unk04, unk08, unk0c;
    float f10;
    int unk14, unk18, unk1c;
    int unk20;
};
struct S_00d3d3e0_P1
{
    S_00d3d3e0_Shape* shape;
    int unk04;
    S_00d3d3e0_Mat* mat;
};
struct S_00d3d3e0_P2
{
    S_00d3d3e0_Obj* obj;
    int unk04;
    S_00d3d3e0_Mat* mat;
};
struct S_00d3d3e0_P3
{
    virtual void v0();
    virtual void v1(S_00d3d3e0_P1* a, S_00d3d3e0_P2* b);
};
struct __declspec(align(16)) S_00d3d3e0_Out
{
    int unk00, unk04, unk08, unk0c;
    float f10;
};

void __cdecl FUN_00cd7160(void* a, S_00d3d3e0_V4* out);
void __cdecl FUN_00cd7850(S_00d3d3e0_V4* a, void* b, S_00d3d3e0_V4* c, S_00d3d3e0_Out* d, bool* e);

struct S_00d3d3e0_P1P
{
    S_00d3d3e0_P1* p;
    S_00d3d3e0_P1* val() const
    {
        return p;
    }
};
struct S_00d3d3e0_P2P
{
    S_00d3d3e0_P2* p;
    S_00d3d3e0_P2* val() const
    {
        return p;
    }
};
struct S_00d3d3e0_P3P
{
    S_00d3d3e0_P3* p;
    S_00d3d3e0_P3* val() const
    {
        return p;
    }
};

// @f3 0x009c7130 (community match, verified in this file)
void __cdecl FUN_00cd7850(S_00d3d3e0_V4* a, void* b, S_00d3d3e0_V4* c, S_00d3d3e0_Out* d);
extern DWORD DAT_0116913c;

// pdb: hkpSphereTriangleAgent::staticGetPenetrations | hkpSphereTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, collector
void FUN_00d3d3e0(S_00d3d3e0_P1P a1, S_00d3d3e0_P2P a2, int unused, S_00d3d3e0_P3P a3)
{
    HK_TIMER_BEGIN("SphereTri", HK_NULL);
    S_00d3d3e0_P1* p1 = a1.val();
    S_00d3d3e0_Shape* shape = p1->shape;
    S_00d3d3e0_Obj* obj = a2.val()->obj;
    S_00d3d3e0_V4 q;
    FUN_00cd7160(&obj->unk20, &q);
    S_00d3d3e0_Mat* m1 = p1->mat;
    S_00d3d3e0_Mat* m2 = a2.val()->mat;
    const S_00d3d3e0_V4& t1 = m1->t;
    float dx = t1.x - m2->t.x;
    float dy = t1.y - m2->t.y;
    float dz = t1.z - m2->t.z;
    S_00d3d3e0_V4 v;
    v.x = m2->r0.x * dx + m2->r0.y * dy + m2->r0.z * dz;
    v.y = m2->r1.x * dx + m2->r1.y * dy + m2->r1.z * dz;
    v.z = m2->r2.x * dx + m2->r2.y * dy + m2->r2.z * dz;
    v.w = 0.0f;
    S_00d3d3e0_Out out;
    FUN_00cd7850(&v, &obj->unk20, &q, &out);
    float sum = obj->f10 + shape->f10;
    if (out.f10 < sum)
        a3.val()->v1(p1, a2.val());
    HK_TIMER_END();
}


namespace fnv_00d3e0d0 {
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
    void hkpSphereTriangleAgent_getClosestPoints(void*, void*, unsigned int, CpuCallData*);
    void FUN_00d3e0d0(void*, void*, unsigned int, unsigned int);
};
// Fills a CpuCallData with fourth, DAT_0104da48 and &DAT_010ce7fc, then calls hkpSphereTriangleAgent_getClosestPoints with second, first, third and the data pointer.
// @fnv 0x00d3e0d0
// pdb: hkpSymmetricAgentLinearCast<hkpSphereTriangleAgent>::getClosestPoints | hkpSphereTriangleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void CpuObject::FUN_00d3e0d0(void* first, void* second, unsigned int third, unsigned int uiValue)
{
    CpuCallData data;
    data.value = uiValue;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpSphereTriangleAgent_getClosestPoints(second, first, third, &data);
}
}  // namespace fnv_00d3e0d0
