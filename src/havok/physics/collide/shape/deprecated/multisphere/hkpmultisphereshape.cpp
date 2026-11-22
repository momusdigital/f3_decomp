#include "f3_common.h"
// src/havok/physics/collide/shape/deprecated/multisphere/hkpmultisphereshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/multisphere/hkpmultisphereshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMultiSphereShape.h"

class FnvShapeGetter : public hkpSphereRepShape
{
  public:
    hkInt32 unk10;
    hkInt32 FUN_00d2a5f0();
};

// @fnv 0x00d2a5f0
// pdb: hkpCharacterContext::getState | hkpCharacterContext.obj | fnv360_0822_retail, call_seq, medium
hkInt32 FnvShapeGetter::FUN_00d2a5f0()
{
    return unk10;
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;

extern "C" __m128 _mm_sub_ps(__m128, __m128);

extern "C" __m128 _mm_mul_ps(__m128, __m128);

extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);

extern "C" void _ReadWriteBarrier();

struct __declspec(align(16)) Ray
{

    __m128 from;

    __m128 to;
};

struct __declspec(align(16)) Out
{

    __m128 normal;

    float fraction;

    int sphereId;

    int unk18;

    int unk1C;

    int keys[8];

    int keyIndex;
};

struct __declspec(align(16)) Sph
{

    float x, y, z, w;
};

struct FUN_00d2a920
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iSphereCount;
    char pad14[0xC];
    hkVector4 m_kSpheres[8];
    hkVector4* CopySpheres(hkVector4* dst);
};

// Copies m_iSphereCount hkVector4 entries from m_kSpheres into dst using 128-bit moves and returns dst.
// @f3 0x00935bd0 (community match, verified in this file)
struct FUN_00922cb0_Obj { void FUN_00922cb0(); };
struct FUN_00922710_Obj { void FUN_00922710(unsigned int lo, unsigned int hi); };
struct CopySpheresPair { unsigned int lo; unsigned int hi; };
struct CopySpheresList { CopySpheresPair* items; int count; };

// pdb: hkStreamStatisticsCollector::_addKnown | hkStreamStatisticsCollector.obj | fnv360_0822_retail, caller_sim, low
// pdb params: obj
hkVector4* FUN_00d2a920::CopySpheres(hkVector4* dst)
{
    reinterpret_cast<FUN_00922cb0_Obj*>(this)->FUN_00922cb0();
    CopySpheresList* list = reinterpret_cast<CopySpheresList*>(dst);
    for (int i = 0; i < list->count; ++i)
    {
        CopySpheresPair* p = &list->items[i];
        reinterpret_cast<FUN_00922710_Obj*>(this)->FUN_00922710(p->lo, p->hi);
    }
    return reinterpret_cast<hkVector4*>(this);
}


struct RayCtx
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
};

class S00d2ab90_Shape : public hkpSphereRepShape
{
  public:
    void* m_disp;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kSpheres[8];
    char* FUN_00d2ab90(char* ok, RayCtx* in, void* p3);
};

static void* s00d2ab90_addr[10];
static void* s00d2ab90_sink;
void D2abExternCall();

static __declspec(noinline) void* castRayInternal(RayCtx* outB, RayCtx* in, hkVector4* spheres, void* owner, RayCtx* outA)
{
    s00d2ab90_sink = outB;
    s00d2ab90_addr[0] = (void*)&in;
    s00d2ab90_addr[1] = (void*)&spheres;
    s00d2ab90_addr[2] = (void*)&owner;
    s00d2ab90_addr[3] = (void*)&outA;
    return outB;
}

static __declspec(noinline) int FUN_00d2a610(hkVector4* spheres, RayCtx* keyB, RayCtx* keyA, void* r, RayCtx* in,
                                             void* extra)
{
    s00d2ab90_addr[4] = (void*)&spheres;
    s00d2ab90_addr[5] = (void*)&keyB;
    s00d2ab90_addr[6] = (void*)&keyA;
    s00d2ab90_addr[7] = (void*)&r;
    s00d2ab90_sink = in;
    for (int i = 0; i < 4; i++)
    {
        D2abExternCall();
        ((int*)extra)[i] = i;
    }
    return (int)r;
}

// Performs a raycast against m_kSpheres using in and p3, storing whether a hit was found in *ok and returning ok.
// @f3 0x009ae000 (community match, verified in this file)
static __declspec(noinline) int My_Helper(hkVector4* spheres, RayCtx* keyB, RayCtx* keyA, void* r, RayCtx* in, void* extra)
{
    s00d2ab90_addr[4] = (void*)&spheres;
    s00d2ab90_addr[5] = (void*)&keyB;
    s00d2ab90_addr[6] = (void*)&keyA;
    s00d2ab90_addr[7] = (void*)&r;
    s00d2ab90_sink = in;
    char* p = (char*)extra;
    while (*p)
        p++;
    return (int)r;
}

char* S00d2ab90_Shape::FUN_00d2ab90(char* ok, RayCtx* in, void* p3)
{
    RayCtx keys[2];
    void* r = castRayInternal(&keys[0], in, m_kSpheres, m_disp, &keys[1]);
    int v = My_Helper(m_kSpheres, &keys[1], &keys[0], r, in, p3);
    *ok = (v != -1);
    return ok;
}


#include <math.h>

extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);

struct Sph_V
{
    float x, y, z, w;
};
struct Sph_Seg
{
    Sph_V a;
    Sph_V b;
};
union Sph_U
{
    Sph_V v;
    __m128 q;
};

static inline __m128 Sph_sum3(__m128 t)
{
    return _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t));
}

// Finds all spheres in an array that the segment intersects, storing their indices and normalized hit parameters, and returns the count.
// @f3 0x009add70 (community match, verified in this file)
#include <math.h>

extern const char str_00e7e0bc[];
extern const char str_00e32798[];
extern unsigned long DAT_0116913c;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

namespace review_havok_timer {
typedef unsigned int UInt32;
class Monitor
{
public:
    static __forceinline Monitor& getInstance()
    {
        return *static_cast<Monitor*>(DAT_00d9b080(DAT_0116913c));
    }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        UInt32 m_time0;
        UInt32 m_time1;
        __forceinline void setTime()
        {
            UInt32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};
}

static __forceinline float TwiceProjection(const Sph_U& delta, const Sph_U& from)
{
    const float dot = delta.v.x * from.v.x + delta.v.y * from.v.y + delta.v.z * from.v.z;
    return dot + dot;
}

// pdb: castRayInternal | hkpMultiSphereShape.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
static __declspec(noinline) int castRayInternal(const Sph_Seg* seg, const Sph_V* spheres, int n,
                                             int* apHitIndices, float* apHitParams)
{
    {
        review_havok_timer::Monitor& stream = review_havok_timer::Monitor::getInstance();
        if (stream.memoryAvailable())
        {
            review_havok_timer::Monitor::TimerCommand* record =
                reinterpret_cast<review_havok_timer::Monitor::TimerCommand*>(stream.getEnd());
            record->m_commandAndMonitor = str_00e7e0bc;
            record->setTime();
            stream.setEnd(reinterpret_cast<char*>(record + 1));
        }
    }
    int hitCount = 0;
    for (int i = 0; i < n; i++)
    {
        Sph_U e, s, d1;
        e.v = seg->b;
        s.v = seg->a;
        e.v.x = e.v.x - spheres[i].x;
        e.v.y = e.v.y - spheres[i].y;
        e.v.z = e.v.z - spheres[i].z;
        s.v.x = s.v.x - spheres[i].x;
        s.v.y = s.v.y - spheres[i].y;
        s.v.z = s.v.z - spheres[i].z;
        d1.v.x = e.v.x - s.v.x;
        d1.v.y = e.v.y - s.v.y;
        d1.v.z = e.v.z - s.v.z;
        const float B = TwiceProjection(d1, s);
        if (B >= 0.0f)
            continue;
        float A = d1.v.x * d1.v.x + d1.v.y * d1.v.y + d1.v.z * d1.v.z;
        float C = s.v.x * s.v.x + s.v.y * s.v.y + s.v.z * s.v.z;
        float q = spheres[i].w * spheres[i].w;
        float cc = C - q;
        float disc = B * B - cc * (A * 4.0);
        if (disc <= 0.0f)
            continue;
        float sq = (float)sqrt(disc);
        float tn = -B - sq;
        float t = tn * 0.5;
        if (t >= A)
            continue;
        if (t < 0.0f)
            continue;
        apHitParams[hitCount] = t / A;
        apHitIndices[hitCount] = i;
        hitCount++;
    }
    {
        review_havok_timer::Monitor& stream = review_havok_timer::Monitor::getInstance();
        if (stream.memoryAvailable())
        {
            review_havok_timer::Monitor::TimerCommand* record =
                reinterpret_cast<review_havok_timer::Monitor::TimerCommand*>(stream.getEnd());
            record->m_commandAndMonitor = str_00e32798;
            record->setTime();
            stream.setEnd(reinterpret_cast<char*>(record + 1));
        }
    }
    return hitCount;
}


int Sph_caller(const Sph_Seg* seg, const Sph_V* spheres, int n, int* a, float* b)
{
    return castRayInternal(seg, spheres, n, a, b);
}

struct ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkReal m_rayEnforcement;
    hkUint32 m_uiFilterInfo;
};

struct hkMotionState
{
    hkTransform m_kMotionTransform;
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const hkMotionState* m_kMotionState;
    const hkpCdBody* m_parent;
};

struct ShapeRayCastOutput
{
    union
    {
        hkVector4 m_vHitNormal;
        __m128 m_vComponents;
    };
    hkReal m_fHitFraction;
    int m_iExtraInfo;
    int unk18[2];
    hkUint32 m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    ShapeRayCastOutput()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeyIndex = 0;
        m_uiShapeKeys[0] = 0xFFFFFFFFu;
    }

    void reset()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = 0xFFFFFFFFu;
        m_uiShapeKeyIndex = 0;
    }
};

class hkpRayHitCollector
{
  public:
    virtual void CollectRayHit(const hkpCdBody& cdBody, const ShapeRayCastOutput& hitInfo) = 0;
};

// Pack unit supplies static noinline overloads for both helpers:
// a960 Sph_Seg form puts the hitKeys (int*) param in EAX;
// a610 Out-first form puts the out param in EDI.

struct DummyMultiSphere : hkpMultiSphereShape
{
    void hkpMultiSphereShape_castRayWithCollectorImpl(const ShapeRayCastQuery& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector) const;
};

// Ray-casts against the multi-sphere shape, transforms each hit normal into world space, and reports hits to the collector.
// @f3 0x009ae050 (community match, verified in this file)
extern int g_extern();
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

static __declspec(noinline) int FUN_009add70(const ShapeRayCastQuery* query, const hkVector4* spheres, int count, float* fractions, int* hitIndices)
{
    int* volatile p = hitIndices;
    _ReadWriteBarrier();
    g_extern();
    if (count <= 0) return 0;
    return (int)query + (int)spheres + (int)fractions - (int)p;
}

struct __declspec(align(16)) AlignedVec4
{
    float x, y, z, w;
};

// pdb: getBestHit | hkpMultiSphereShape.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
static __declspec(noinline) int getBestHit(ShapeRayCastOutput* output, const hkVector4* spheres, float* fractions, int* hitIndices, int count, const ShapeRayCastQuery* query)
{
    int best = -1;
    for (int i = 0; i < count; i++) {
        if (fractions[i] < output->m_fHitFraction) {
            output->m_fHitFraction = fractions[i];
            best = i;
        }
    }
    if (best >= 0) {
        output->m_uiShapeKeys[output->m_uiShapeKeyIndex] = -1;
        int hitKey = hitIndices[best];
        const float* sph = (const float*)&spheres[hitKey];
        const float* to = (const float*)&query->m_vTo;
        const float* from = (const float*)&query->m_vFrom;
        AlignedVec4 dTo, dFrom;
        dTo.x = to[0] - sph[0]; dTo.y = to[1] - sph[1]; dTo.z = to[2] - sph[2]; dTo.w = to[3] - sph[3];
        dFrom.x = from[0] - sph[0]; dFrom.y = from[1] - sph[1]; dFrom.z = from[2] - sph[2]; dFrom.w = from[3] - sph[3];
        output->m_vHitNormal.x = dFrom.x * (1.0f - output->m_fHitFraction) + dTo.x * output->m_fHitFraction;
        output->m_vHitNormal.y = dFrom.y * (1.0f - output->m_fHitFraction) + dTo.y * output->m_fHitFraction;
        output->m_vHitNormal.z = dFrom.z * (1.0f - output->m_fHitFraction) + dTo.z * output->m_fHitFraction;
        output->m_vHitNormal.w = dFrom.w * (1.0f - output->m_fHitFraction) + dTo.w * output->m_fHitFraction;
        float invR = 1.0f / sph[3];
        output->m_iExtraInfo = hitKey;
        output->m_vHitNormal.x *= invR;
        output->m_vHitNormal.y *= invR;
        output->m_vHitNormal.z *= invR;
        output->m_vHitNormal.w *= invR;
    }
    return best;
}

// pdb: hkpMultiSphereShape::castRayWithCollectorImpl | hkpMultiSphereShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(caller_sim), high
void DummyMultiSphere::hkpMultiSphereShape_castRayWithCollectorImpl(const ShapeRayCastQuery& query, const hkpCdBody& body,
                                     hkpRayHitCollector& collector) const
{
    float fractions[8];
    int hitIndices[8];

    int hits = FUN_009add70(&query, m_kSpheres, m_iSphereCount, fractions, hitIndices);
    ShapeRayCastOutput output;
    if (hits == 0) return;

    do
    {
        output.reset();
        int i = getBestHit(&output, m_kSpheres, fractions, hitIndices, hits, &query);

        const hkTransform& t = body.m_kMotionState->m_kMotionTransform;
        float x = output.m_vHitNormal.x;
        float y = output.m_vHitNormal.y;
        float z = output.m_vHitNormal.z;
        output.m_vHitNormal.x = t.m_rotation.m_kColumn0.x*x + t.m_rotation.m_kColumn1.x*y + t.m_rotation.m_kColumn2.x*z;
        output.m_vHitNormal.y = t.m_rotation.m_kColumn0.y*x + t.m_rotation.m_kColumn1.y*y + t.m_rotation.m_kColumn2.y*z;
        output.m_vHitNormal.z = t.m_rotation.m_kColumn0.z*x + t.m_rotation.m_kColumn1.z*y + t.m_rotation.m_kColumn2.z*z;
        output.m_vHitNormal.w = 0.0f;
        collector.CollectRayHit(body, output);

        hits--;
        fractions[i] = fractions[hits];
        hitIndices[i] = hitIndices[hits];
    } while (hits != 0);
}


struct Vec4
{
    __m128 m_vComponents;
    __m128 get() const
    {
        return m_vComponents;
    }
    void set(__m128 v)
    {
        m_vComponents = v;
    }
};
