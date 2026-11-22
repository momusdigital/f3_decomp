#include "f3_common.h"
// src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkpGskBaseAgent
{
    virtual void FUN_00dabe90(bool);
};
// @fnv 0x00dabe90
// pdb: hkpGskBaseAgent::cleanup | hkpGskBaseAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: constraintOwner
void hkpGskBaseAgent::FUN_00dabe90(bool)
{
    if (this)
        FUN_00dabe90(true);
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;

extern float DAT_01012054;

extern float DAT_01012054;

class FUN_00dabed0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float m_18;
    int unk1c;
    __m128 m_20;

    void hkpGskBaseAgent_warpTime(float expected, float value, int unused);
};

// If m_18 equals expected, stores value into m_18; otherwise sets m_18 to DAT_01012054 and zeroes m_20.
// @f3 0x00a348c0 (community match, verified in this file)
namespace Defaults370 { extern const float DAT_00db38b8; }
// pdb: hkpGskBaseAgent::warpTime | hkpGskBaseAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: oldTime, newTime, input
// pdb: hkpGskBaseAgent::warpTime | hkpGskBaseAgent.obj | fnv360_0822_retail, vtable, high (was: SetValueIfExpected)
void FUN_00dabed0_cls::hkpGskBaseAgent_warpTime(float expected, float value, int unused) {
    if (m_18 == expected) {
        m_18 = value;
    } else {
        m_18 = Defaults370::DAT_00db38b8;
        float* components = reinterpret_cast<float*>(&m_20);
        components[0] = components[1] = components[2] = components[3] = 0.0f;
    }
}


extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

struct hkpCdBody
{
    const void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    const void* m_pMotionState;
};

struct GskAgentInput
{
    int unk00;
    int unk04;
    float m_fScalar;
};

struct hkContactPoint
{
    __m128 m_vContactPosition;
    __m128 m_vSeparatingNormal;
};

struct ContactPointPair
{
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
};

struct hkpCdPointCollector
{
    virtual void vfunc00();
    virtual void AddCdPoint(const ContactPointPair& point);
};

class FUN_00dac9e0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    void hkpGskBaseAgent_getClosestPoints(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const GskAgentInput* input,
                           hkpCdPointCollector* collector);
};

struct StringCursor
{
    void* m_kRayStart;
    char* m_cur;
    void* m_auiShapeKeys;
    char* m_kRayEnd;
};

// @f3 0x00a35510 (community match, verified in this file)
extern unsigned int DAT_0116913c;
struct __declspec(align(16)) hkVector4F3
{
    float x, y, z, w;
    hkVector4F3& operator=(const hkVector4F3& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
};
struct hkTransformF3
{
    float m_col[16];
    void FUN_00925300(const void* a, const void* b);
};
struct GskAgentInputF3
{
    int unk00;
    float m_fScalar;
};
struct GskInputF3
{
    const hkTransformF3* m_kTransform;
    const void* m_pTransformB;
    const void* m_pShapeA;
    const void* m_pShapeB;
    float m_fScalar;
};
struct GskOutputF3
{
    hkVector4F3 m_pos;
    hkVector4F3 m_vHitNormal;
};
struct ContactPointPairF3
{
    hkVector4F3 m_vContactPosition;
    hkVector4F3 m_vSeparatingNormal;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
};
struct hkpCdPointCollectorF3
{
    virtual void vfunc00();
    virtual void AddCdPoint(const ContactPointPairF3& point);
};
int FUN_00a345e0(const GskInputF3* input, void* status, hkVector4F3* out1, hkVector4F3* out2);

// pdb: hkpGskBaseAgent::getClosestPoints | hkpGskBaseAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
// pdb: hkpGskBaseAgent::getClosestPoints | hkpGskBaseAgent.obj | fnv360_0822_retail, vtable, high (was: ProcessGskContact)
void FUN_00dac9e0_cls::hkpGskBaseAgent_getClosestPoints(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const GskAgentInput* input,
                                         hkpCdPointCollector* collector)
{
    StringCursor* pProfilerBuffer = (StringCursor*)TlsGetValue(DAT_0116913c);
    char* pWriteCursor = pProfilerBuffer->m_cur;
    if (pWriteCursor < pProfilerBuffer->m_kRayEnd)
    {
        *(const char**)pWriteCursor = "TtGsk";
        _ReadWriteBarrier();
        volatile unsigned int uiTimestamp = (unsigned int)__rdtsc();
        *(unsigned int*)(pWriteCursor + 4) = uiTimestamp;
        pWriteCursor += 12;
        pProfilerBuffer->m_cur = pWriteCursor;
    }

    hkTransformF3 aTb;
    aTb.FUN_00925300(bodyA->m_pMotionState, bodyB->m_pMotionState);

    GskInputF3 queryInput;
    queryInput.m_pShapeA = bodyA->m_pCollisionShape;
    queryInput.m_pShapeB = bodyB->m_pCollisionShape;
    queryInput.m_kTransform = &aTb;
    queryInput.m_pTransformB = bodyA->m_pMotionState;
    queryInput.m_fScalar = ((const GskAgentInputF3*)input)->m_fScalar;

    GskOutputF3 out;
    if (FUN_00a345e0(&queryInput, &this->unk0c, &out.m_vHitNormal, &out.m_pos) == 0)
    {
        ContactPointPairF3 point;
        point.m_vContactPosition = out.m_pos;
        point.m_pBodyA = bodyA;
        point.m_pBodyB = bodyB;
        point.m_vSeparatingNormal = out.m_vHitNormal;
        ((hkpCdPointCollectorF3*)collector)->AddCdPoint(point);
    }

    pProfilerBuffer = (StringCursor*)TlsGetValue(DAT_0116913c);
    pWriteCursor = pProfilerBuffer->m_cur;
    if (pWriteCursor < pProfilerBuffer->m_kRayEnd)
    {
        *(const char**)pWriteCursor = "Et";
        _ReadWriteBarrier();
        volatile unsigned int uiTimestamp = (unsigned int)__rdtsc();
        *(unsigned int*)(pWriteCursor + 4) = uiTimestamp;
        pWriteCursor += 12;
        pProfilerBuffer->m_cur = pWriteCursor;
    }
}


// @fnv 0x00dabe80
// pdb: hkpGskBaseAgent::processCollision | hkpGskBaseAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpGskBaseAgent_processCollision(int, int, int, int)
{}

extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

struct hkVector4DAC0
{
    __m128 m_vComponents;

    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
    __forceinline void _setRotatedDir(const struct hkMatrix3DAC0& r, const hkVector4DAC0& b);
};

struct hkMatrix3DAC0
{
    hkVector4DAC0 m_kColumn0;
    hkVector4DAC0 m_kColumn1;
    hkVector4DAC0 m_kColumn2;
};

struct hkTransformDAC0
{
    hkMatrix3DAC0 m_rotation;
    hkVector4DAC0 m_vTranslation;

    void FUN_00cb22f0(const hkTransformDAC0& kA, const hkTransformDAC0& kB);

    const hkMatrix3DAC0& getRotation() const
    {
        return m_rotation;
    }
};

extern char g_gskBaseAgentVtbl;

struct GskNode;

__declspec(align(16)) struct GskTmp
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    void Setup(int a, int b);
};

struct GskSub
{
    int m_00;
    int m_04;
    int m_08;
    void Init(GskNode* a, GskNode* b, GskTmp* t);
    void Init2(GskNode* a, GskNode* b, GskTmp* t);
};

struct GskNode
{
    GskNode* m_00;
    int unk04;
    int m_08;
    GskNode* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    float m_4c;
};

struct FUN_00dabf10_cls
{
    void* m_00;
    short unk04;
    short m_06;
    int m_08;
    GskSub m_0c;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;

    FUN_00dabf10_cls* FUN_00dabf10(GskNode* a1, GskNode* a2, int a3);
};

// Initializes the GskSub at m_0c from the two nodes, sets m_06, m_08 and the vtable, and stores the smaller of the two chain-end nodes' m_4c in m_1c.
// @f3 0x00a34900 (community match, verified in this file)
// pdb: hkpGskBaseAgent::hkpGskBaseAgent | hkpGskBaseAgent.obj | fnv360_0822_retail, uvref, high
// pdb params: bodyA, bodyB, mgr
FUN_00dabf10_cls* FUN_00dabf10_cls::FUN_00dabf10(GskNode* apNodeA, GskNode* apNodeB, int a3)
{
    m_06 = 1;
    m_08 = a3;
    m_00 = &g_gskBaseAgentVtbl;

    GskNode* ebx = apNodeB->m_00;
    int a2k = apNodeB->m_08;
    int a1k = apNodeA->m_08;
    GskNode* a1base = apNodeA->m_00;
    GskTmp tmp;
    tmp.Setup(a1k, a2k);

    if ((int)ebx->m_0c == 4)
    {
        m_0c.Init(a1base, ebx, &tmp);
    }
    else
    {
        m_0c.Init2(a1base, ebx, &tmp);
    }

    *(volatile float*)&m_2c = 0.0f;
    m_28 = 0.0f;
    m_24 = 0.0f;
    m_20 = 0.0f;
    m_2c = -1.0f;
    m_18 = -1.0f;

    GskNode* p = apNodeA;
    while (p->m_0c != 0)
    {
        p = p->m_0c;
    }
    float fa = *(float*)((char*)p + 0x48);

    GskNode* r = apNodeB;
    while (r->m_0c != 0)
    {
        r = r->m_0c;
    }
    float fb = *(float*)((char*)r + 0x48);

    m_1c = (fa < fb) ? fa : fb;
    return this;
}


struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b)
    {}
    hkBool(char b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
}

#include <windows.h>

struct S_00dac2b0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};

struct S_00dac2b0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00dac2b0_MonitorStream& GetMonitorStream()
    {
        return *(S_00dac2b0_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    void timer(const char* name)
    {
        if (memoryAvailable())
        {
            S_00dac2b0_TimerCommand* h = (S_00dac2b0_TimerCommand*)m_kRayEnd;
            h->m_pCommandName = name;
            _ReadWriteBarrier();
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

struct __declspec(align(16)) S_00dac2b0_Transform
{
    float m[16];
    void FUN_00cb22f0(const S_00dac2b0_Transform* a, const S_00dac2b0_Transform* b);
};

struct __declspec(align(16)) S_00dac2b0_Vec
{
    float x, y, z, w;
};

struct S_00dac2b0_Shape;

struct S_00dac2b0_Shape
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, S_00dac2b0_Vec* out) const;
    int unk04;
    int unk08;
    int m_type;
    float m_fSphereRadius;
};

struct __declspec(align(16)) S_00dac2b0_Gsk
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_maxA;
    int m_maxB;
    int m_iCachedVertexCount;
    int m_zero;
    int unk18;
    int unk1C;
    S_00dac2b0_Vec m_vertsA[12];
    S_00dac2b0_Vec m_vertsB[10];
    int FUN_00daad40(const S_00dac2b0_Shape* a, const S_00dac2b0_Shape* b, const S_00dac2b0_Transform* t,
                     S_00dac2b0_Vec* out);
};

struct S_00dac2b0_Body
{
    const S_00dac2b0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00dac2b0_Transform* m_pMotionState;
};

struct S_00dac2b0_Collector
{
    virtual void v0();
    virtual void AddCdBodyPair(const S_00dac2b0_Body& a, const S_00dac2b0_Body& b);
};

// Runs the GSK step (timed as TtGsk) on the two bodies' shapes and adds the pair to the collector if the result is nonzero or the distance is below the radii.
// @f3 0x00a34cf0 (community match, verified in this file)
#include <windows.h>

extern unsigned int DAT_0116913c;

struct S_00dac2b0_TimerCommandX
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};

struct S_00dac2b0_MonitorStreamX
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00dac2b0_MonitorStreamX& GetMonitorStream()
    {
        return *(S_00dac2b0_MonitorStreamX*)TlsGetValue(DAT_0116913c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    void timer(const char* name)
    {
        if (memoryAvailable())
        {
            S_00dac2b0_TimerCommandX* h = (S_00dac2b0_TimerCommandX*)m_kRayEnd;
            h->m_pCommandName = name;
            _ReadWriteBarrier();
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

struct __declspec(align(16)) S_00dac2b0_TransformX
{
    float m[16];
    void FUN_00925300(const S_00dac2b0_TransformX* a, const S_00dac2b0_TransformX* b);
};

struct S_00dac2b0_ShapeX;

struct S_00dac2b0_CacheX
{
    unsigned short id0, id1, id2, id3;
    unsigned char dimA, dimB, dims;
    void hkpGskCache_initTriangle(const S_00dac2b0_ShapeX* a, const S_00dac2b0_ShapeX* b, const S_00dac2b0_TransformX* t);
    void hkpGskCache_init(const S_00dac2b0_ShapeX* a, const S_00dac2b0_ShapeX* b, const S_00dac2b0_TransformX* t);
};

struct S_00dac2b0_ShapeX
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, S_00dac2b0_Vec* out) const;
    int unk04;
    int unk08;
    int m_type;
    float m_fSphereRadius;
};

struct __declspec(align(16)) S_00dac2b0_GskX
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_maxA;
    int m_maxB;
    int m_iCachedVertexCount;
    int m_zero;
    int unk18;
    int unk1C;
    S_00dac2b0_Vec m_vertsA[12];
    S_00dac2b0_Vec m_vertsB[10];
    int hkpGsk_getClosestFeature(const S_00dac2b0_ShapeX* a, const S_00dac2b0_ShapeX* b, const S_00dac2b0_TransformX* t,
                     S_00dac2b0_Vec* out);
};

// pdb: hkpGskBaseAgent::staticGetPenetrations | hkpGskBaseAgent.obj | fnv360_0822_retail, call_seq, high
// pdb params: bodyA, bodyB, input, collector
// pdb: hkpGskBaseAgent::staticGetPenetrations | hkpGskBaseAgent.obj | fnv360_0822_retail, call_seq, high (was: TestGsk)
void __cdecl hkpGskBaseAgent_staticGetPenetrations(const S_00dac2b0_Body& bodyA, const S_00dac2b0_Body& bodyB, const void* input,
                     S_00dac2b0_Collector& collector)
{
    S_00dac2b0_MonitorStreamX::GetMonitorStream().timer("TtGsk");

    const S_00dac2b0_ShapeX* shapeA = (const S_00dac2b0_ShapeX*)bodyA.m_pCollisionShape;
    const S_00dac2b0_ShapeX* shapeB = (const S_00dac2b0_ShapeX*)bodyB.m_pCollisionShape;

    S_00dac2b0_TransformX aTb;
    aTb.FUN_00925300((const S_00dac2b0_TransformX*)bodyA.m_pMotionState,
                     (const S_00dac2b0_TransformX*)bodyB.m_pMotionState);

    S_00dac2b0_CacheX cache;
    if (shapeB->m_type == 4)
    {
        cache.hkpGskCache_initTriangle(shapeA, shapeB, &aTb);
    }
    else
    {
        cache.hkpGskCache_init(shapeA, shapeB, &aTb);
    }

    S_00dac2b0_GskX gsk;
    gsk.m_ucDimensionA = cache.dimA;
    gsk.m_ucDimensionB = cache.dimB;
    gsk.m_maxA = cache.dims & 0xf;
    gsk.m_iCachedVertexCount = 1;
    gsk.m_maxB = cache.dims >> 4;
    gsk.m_zero = 0;
    shapeA->GetVerticesForIds(&cache.id0, cache.dimA, gsk.m_vertsA);
    shapeB->GetVerticesForIds(&cache.id0 + gsk.m_ucDimensionA, gsk.m_ucDimensionB, gsk.m_vertsB);

    S_00dac2b0_Vec out;
    int iResult = gsk.hkpGsk_getClosestFeature(shapeA, shapeB, &aTb, &out);

    S_00dac2b0_MonitorStreamX::GetMonitorStream().timer("Et");

    if (iResult == 0)
    {
        float d = out.w - shapeA->m_fSphereRadius - shapeB->m_fSphereRadius;
        if (d < 0.0f)
        {
            collector.AddCdBodyPair(bodyA, bodyB);
        }
    }
    else
    {
        collector.AddCdBodyPair(bodyA, bodyB);
    }
}


union EarlyScratch
{
    volatile unsigned int ticks;
    int result;
    float distance;
};

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern unsigned long hkMonitorStreamTls;

struct S_00dac0b0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00dac0b0_TimerBeginListCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    const char* m_pFirst;
};

struct S_00dac0b0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00dac0b0_TimerBeginList(const char* name, const char* firstSplit, EarlyScratch& scratch)
{
    S_00dac0b0_MonitorStream* s = (S_00dac0b0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00dac0b0_TimerBeginListCommand* h = (S_00dac0b0_TimerBeginListCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        h->m_pFirst = firstSplit;
        _ReadWriteBarrier();
        scratch.ticks = (unsigned int)__rdtsc();
        h->m_uiStartTicks = scratch.ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

static inline void S_00dac0b0_Timer(const char* name, EarlyScratch& scratch)
{
    S_00dac0b0_MonitorStream* s = (S_00dac0b0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00dac0b0_TimerCommand* h = (S_00dac0b0_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        scratch.ticks = (unsigned int)__rdtsc();
        h->m_uiStartTicks = scratch.ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

static inline void S_00dac0b0_TimerEnd()
{
    {
        S_00dac0b0_MonitorStream* s = (S_00dac0b0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
        if (s->m_kRayEnd < s->m_pCurrentCommand)
        {
            S_00dac0b0_TimerCommand* h = (S_00dac0b0_TimerCommand*)s->m_kRayEnd;
            h->m_pCommandName = "lt";
            _ReadWriteBarrier();
            struct Tk
            {
                unsigned int v;
            };
            Tk t;
            *(volatile unsigned int*)&t.v = (unsigned int)__rdtsc();
            *(Tk*)&h->m_uiStartTicks = t;
            s->m_kRayEnd = (char*)(h + 1);
        }
    }
}

struct S_00dac0b0_Vertex
{
    float x, y, z, w;
};

struct S_00dac0b0_Transform
{
    S_00dac0b0_Vertex col0;
    S_00dac0b0_Vertex col1;
    S_00dac0b0_Vertex col2;
    S_00dac0b0_Vertex trans;
    void FUN_00cb22f0(const S_00dac0b0_Transform* a, const S_00dac0b0_Transform* b);
};

struct S_00dac0b0_Shape
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
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, S_00dac0b0_Vertex* out) const;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
};

struct S_00dac0b0_Body
{
    S_00dac0b0_Shape* m_pCollisionShape;
    int unk04;
    const S_00dac0b0_Transform* m_kMotionTransform;
};

struct S_00dac0b0_PackedCache
{
    unsigned short id0, id1, id2, id3;
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    unsigned char m_flags;
};

template <class T> struct S_00dac0b0_Pad
{
    T* m_p;
    T* val() const
    {
        return m_p;
    }
};

struct S_00dac0b0_Out
{
    virtual void v00();
    virtual void v04(const S_00dac0b0_Body& a, const S_00dac0b0_Body& b);
};

struct S_00dac0b0_Agent : hkpGskBaseAgent
{
    int unk04;
    int unk08;
    S_00dac0b0_PackedCache m_pAccessManager;
    int unk18;
    int unk1C;
    S_00dac0b0_Vertex m_sepNormal;
    void hkpGskBaseAgent_getPenetrations(S_00dac0b0_Pad<const S_00dac0b0_Body> pA, S_00dac0b0_Pad<const S_00dac0b0_Body> pB,
                      const void* input, S_00dac0b0_Pad<S_00dac0b0_Out> pOut);
};

// @f3 0x00a34ac0 (community match, verified in this file)
extern const char DAT_00e85ff8[], DAT_00e85ff0[], DAT_00e85fe4[], DAT_00e0811c[];
struct S_00dac0b0_Transform;
struct S_00dac0b0_PackedCache;
struct NativeVertexIdShape58
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void GetVerticesForIds(const unsigned short*,int,S_00dac0b0_Vertex*) const;
};
typedef void* (__stdcall* TlsGetter58)(unsigned int);
extern TlsGetter58 DAT_00d9b080;
struct __declspec(align(16)) Transform58 {
    S_00dac0b0_Vertex col0,col1,col2,trans;
    void FUN_00925300(const S_00dac0b0_Transform*,const S_00dac0b0_Transform*);
};
struct __declspec(align(16)) Gsk58 {
    int dimA,dimB,maxA,maxB,count,changed,unk18,unk1c;
    S_00dac0b0_Vertex a00;
    S_00dac0b0_Vertex a01;
    S_00dac0b0_Vertex a02;
    S_00dac0b0_Vertex a03;
    S_00dac0b0_Vertex a04;
    S_00dac0b0_Vertex a05;
    S_00dac0b0_Vertex a06;
    S_00dac0b0_Vertex a07;
    S_00dac0b0_Vertex a08;
    S_00dac0b0_Vertex a09;
    S_00dac0b0_Vertex a10;
    S_00dac0b0_Vertex a11;
    S_00dac0b0_Vertex b00;
    S_00dac0b0_Vertex b01;
    S_00dac0b0_Vertex b02;
    S_00dac0b0_Vertex b03;
    S_00dac0b0_Vertex b04;
    S_00dac0b0_Vertex b05;
    S_00dac0b0_Vertex b06;
    S_00dac0b0_Vertex b07;
    S_00dac0b0_Vertex b08;
    S_00dac0b0_Vertex b09;
    Transform58 aTb;
    int hkpGsk_getClosestFeature(const S_00dac0b0_Shape*,const S_00dac0b0_Shape*,const Transform58*,S_00dac0b0_Vertex*);
    void FUN_00a30af0(S_00dac0b0_PackedCache*);
};
template<class Result, class Matrix, class Vector>
static __forceinline void SetRotated(Result& result,const Matrix& t,const Vector& v) {
    const float vy = v.y;
    const float vx = v.x;
    const float vz = v.z;
    result.x=vy*t.col1.x+vx*t.col0.x+vz*t.col2.x;
    const double yProduct = t.col1.y * vy;
    result.y=yProduct+vx*t.col0.y+vz*t.col2.y;
    const double zProduct = t.col1.z * vy;
    result.z=zProduct+vx*t.col0.z+vz*t.col2.z;
    result.w=0.0f;
}
// pdb: hkpGskBaseAgent::getPenetrations | hkpGskBaseAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void S_00dac0b0_Agent::hkpGskBaseAgent_getPenetrations(S_00dac0b0_Pad<const S_00dac0b0_Body> pA,S_00dac0b0_Pad<const S_00dac0b0_Body> pB,const void* input,S_00dac0b0_Pad<S_00dac0b0_Out> pOut) {
    EarlyScratch scratch;
    TlsGetter58 getter=DAT_00d9b080;
    {
        S_00dac0b0_MonitorStream* stream=(S_00dac0b0_MonitorStream*)getter(DAT_0116913c);
        if(stream->m_kRayEnd<stream->m_pCurrentCommand) {
            S_00dac0b0_TimerBeginListCommand* command=(S_00dac0b0_TimerBeginListCommand*)stream->m_kRayEnd;
            command->m_pCommandName=DAT_00e85ff8;
            command->m_pFirst=DAT_00e85ff0;
            _ReadWriteBarrier();
            scratch.ticks=static_cast<unsigned int>(__rdtsc());
            command->m_uiStartTicks=scratch.ticks;
            stream->m_kRayEnd=(char*)(command+1);
        }
    }
    {
        S_00dac0b0_MonitorStream* stream=(S_00dac0b0_MonitorStream*)getter(DAT_0116913c);
        if(stream->m_kRayEnd<stream->m_pCurrentCommand) {
            S_00dac0b0_TimerCommand* command=(S_00dac0b0_TimerCommand*)stream->m_kRayEnd;
            command->m_pCommandName=DAT_00e85fe4;
            _ReadWriteBarrier();
            scratch.ticks=static_cast<unsigned int>(__rdtsc());
            command->m_uiStartTicks=scratch.ticks;
            stream->m_kRayEnd=(char*)(command+1);
        }
    }
    const S_00dac0b0_Shape* shapeA=pA.val()->m_pCollisionShape;
    const S_00dac0b0_Shape* shapeB=pB.val()->m_pCollisionShape;
    Gsk58 gsk;
    gsk.aTb.FUN_00925300(pA.val()->m_kMotionTransform,pB.val()->m_kMotionTransform);
    S_00dac0b0_PackedCache* cache=&m_pAccessManager;
    gsk.dimA=cache->m_ucDimensionA;
    gsk.dimB=cache->m_ucDimensionB;
    gsk.maxA=cache->m_flags&15;
    gsk.maxB=cache->m_flags>>4;
    gsk.count=1;
    gsk.changed=0;
    reinterpret_cast<const NativeVertexIdShape58*>(shapeA)->GetVerticesForIds(&cache->id0,gsk.dimA,&gsk.a00);
    reinterpret_cast<const NativeVertexIdShape58*>(shapeB)->GetVerticesForIds(&cache->id0+gsk.dimA,gsk.dimB,&gsk.b00);
    S_00dac0b0_Vertex normal;
    int result=gsk.hkpGsk_getClosestFeature(shapeA,shapeB,&gsk.aTb,&normal);
    if(gsk.changed)gsk.FUN_00a30af0(cache);
    if(result==0) {
        float distance=normal.w-shapeA->m_fSphereRadius-shapeB->m_fSphereRadius;
        SetRotated(m_sepNormal,*pA.val()->m_kMotionTransform,normal);
        m_sepNormal.w=distance;
        if(distance<0.0f)pOut.val()->v04(*pA.val(),*pB.val());
    } else {
        m_sepNormal.w=0.0f;m_sepNormal.z=0.0f;m_sepNormal.y=0.0f;m_sepNormal.x=0.0f;
        pOut.val()->v04(*pA.val(),*pB.val());
    }
    {
        S_00dac0b0_MonitorStream* stream=(S_00dac0b0_MonitorStream*)DAT_00d9b080(DAT_0116913c);
        if(stream->m_kRayEnd<stream->m_pCurrentCommand) {
            S_00dac0b0_TimerCommand* command=(S_00dac0b0_TimerCommand*)stream->m_kRayEnd;
            command->m_pCommandName=DAT_00e0811c;
            _ReadWriteBarrier();
            scratch.ticks=static_cast<unsigned int>(__rdtsc());
            command->m_uiStartTicks=scratch.ticks;
            stream->m_kRayEnd=(char*)(command+1);
        }
    }
}

