#include "f3_common.h"
// src/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Callback
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void invoke(unsigned short, int);
};
struct FUN_00d3b3d0_Class
{
    virtual void release(int);
    int unk04;
    Callback* unk08;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    void hkpCapsuleCapsuleAgent_cleanup(int);
};
typedef void(__cdecl* HandlerFn)();
void __cdecl FUN_00d3b420();
void __cdecl FUN_00d3b420(const void* a, const void* b, const void* c, void* d);

#include <xmmintrin.h>
#include <windows.h>
// The profiler keeps one 12 byte entry per marked call site in a per thread buffer.
// The entry holds the name of the marked site and a timestamp taken from the TSC.
struct ProfilerTls
{
    int unk00;
    char* unk04;  // write cursor
    char* unk08;
    char* unk0C;  // end of the buffer
};

// A 16 byte aligned vector of four floats.
struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

// One row of a 4x4 matrix.  The rows are copied as raw dwords, so the
// stand-in keeps them as 32 bit words.
struct __declspec(align(16)) MatRow
{
    unsigned int c0, c1, c2, c3;
};

// The four rows of a transform matrix.  Row 0 of the source matrix is kept in
// the last slot, row 1 in the first one and so on (the rows are rotated).
struct MatSlots
{
    MatRow m0;  // slot 0  <- source row 1
    MatRow m1;  // slot 1  <- source row 2
    MatRow m2;  // slot 2  <- source row 3
    MatRow m3;  // slot 3  <- source row 0
};

// The two transformed segments: the ray (v2,v3) and the segment (v0,v1).
struct Segments
{
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    Vec4 v3;
};

// A capsule: four points (the last two are the segment ends) plus its transform.
struct Capsule
{
    float* unk00;
    int unk04;
    float* unk08;
};

template <class T> struct LazyPtr
{
    T* p;
    LazyPtr(T* q) : p(q)
    {}
    T* operator->() const
    {
        return p;
    }
    operator T*() const
    {
        return p;
    }
};

#include <xmmintrin.h>
namespace fnv_00d3b6f0 {
struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};
struct __declspec(align(16)) MatRow
{
    unsigned int c0, c1, c2, c3;
};
struct MatSlots
{
    MatRow m0, m1, m2, m3;
};
struct Segments
{
    Vec4 v0, v1, v2, v3;
};
struct Capsule
{
    float* unk00;
    int unk04;
    float* unk08;
};
struct Context
{
    int unk00, unk04;
    float scale;
};
struct TransformOutput
{
    float rows[3][8];
};
void __cdecl FUN_00cd58b0(const void*, float, const void*, float, TransformOutput*);
// @fnv 0x00d3b6f0
Context* volatile contextSource;
Capsule* volatile firstSource;
TransformOutput* volatile outputSource;
Capsule* volatile secondSource;
}  // namespace fnv_00d3b6f0

struct TimerEntry
{
    const char* tag;
    unsigned stamp;
    unsigned extra;
};

struct CapsuleShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1C;
    Vec4 m_kVertexA;
    Vec4 m_kVertexB;

    const Vec4* GetIndexedVertices() const
    {
        return &m_kVertexA;
    }
};

struct CdBody
{
    CapsuleShape* m_pCollisionShape;
    int unk04;
    const MatSlots* m_kMotionState;
};

struct CollisionInput
{
    int unk00;
    int unk04;
    float m_fScalar;
};

struct PointResult
{
    struct
    {
        float x, y, z, w;
    } m_vHitNormal;
    float m_posAndDistX;
    float m_posAndDistY;
    float m_posAndDistZ;
    float m_fClosestPointDistanceSquared;
};

struct AlignedPairData
{
    Vec4 m_vec0;
    Vec4 m_vec1;
    unsigned int m_usContactPointId;
    int unk24;
    int unk28;
    int unk2C;
};

struct Collector
{
    AlignedPairData* m_cur;
    int m_unk04;
};

struct MyCallback
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual unsigned short slot0C(const CdBody* a, const CdBody* b, const CollisionInput* c, Collector* d, int e,
                                  PointResult* f);
    virtual void slot10();
    virtual void invoke(unsigned short id, int unk);
};

extern "C" void __cdecl FUN_00cd58b0(const Vec4* verticesA, float radiusA, const Vec4* verticesB, float radiusB,
                                     PointResult* results);

struct Agent : FUN_00d3b3d0_Class
{
    void FUN_00d3c060(const CdBody* bodyA, const CdBody* bodyB, const CollisionInput* input, Collector* collector);
};

// @f3 0x009c57b0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7f134[], DAT_00e32798[];
namespace f3m_009c57b0 {
struct DeadFloats { float f0; float f1; float f2; __forceinline void operator=(const DeadFloats& o) { f0 = o.f0; f1 = o.f1; f2 = o.f2; } };
struct NativeCollisionInput { int unk00; float tolerance; };
extern "C" void __cdecl FUN_0096d120(const void*, float, const void*, float, PointResult*);
struct __declspec(align(16)) NativeFloat4 {
    float x, y, z, w;
    __forceinline NativeFloat4() {}
    __forceinline void operator=(const NativeFloat4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline float& operator()(int i) { if (i == 0) return x; if (i == 1) return y; if (i == 2) return z; return w; }
    __forceinline const float& operator()(int i) const { if (i == 0) return x; if (i == 1) return y; if (i == 2) return z; return w; }
};
struct NativeMat3 {
    NativeFloat4 m_col0, m_col1, m_col2;
    __forceinline NativeFloat4& getColumn(int i) { if (i == 0) return m_col0; if (i == 1) return m_col1; return m_col2; }
    __forceinline const NativeFloat4& getColumn(int i) const { if (i == 0) return m_col0; if (i == 1) return m_col1; return m_col2; }
    __forceinline float& operator()(int r, int c) { return getColumn(c)(r); }
    __forceinline const float& operator()(int r, int c) const { return getColumn(c)(r); }
};
struct __declspec(align(16)) NativeRot : public NativeMat3 {};
struct NativeTransform {
    NativeRot m_rotation;
    NativeFloat4 m_translation;
    __forceinline NativeTransform(const NativeTransform& t) {
        const NativeFloat4 r0 = t.m_rotation.getColumn(0);
        const NativeFloat4 r1 = t.m_rotation.getColumn(1);
        const NativeFloat4 r2 = t.m_rotation.getColumn(2);
        const NativeFloat4 r3 = t.m_translation;
        m_rotation.getColumn(0) = r0;
        m_rotation.getColumn(1) = r1;
        m_rotation.getColumn(2) = r2;
        m_translation = r3;
    }
    __forceinline const NativeRot& getRotation() const { return m_rotation; }
    __forceinline const NativeFloat4& getTranslation() const { return m_translation; }
};
struct ScalarReal {
    float value;
    __forceinline ScalarReal(float v) : value(v) {}
    friend __forceinline double operator*(float c, const ScalarReal& s) { return s.value * c; }
};
__forceinline void NativeTransformPoints(const NativeTransform& transform, const NativeFloat4* source, NativeFloat4* destination, int count) {
    NativeTransform unaliased = transform;
    int i = count - 1;
    do {
        const NativeFloat4& b = source[i];
        NativeFloat4& t = destination[i];
        const NativeRot& r = unaliased.getRotation();
        const NativeFloat4& tr = unaliased.getTranslation();
        ScalarReal v0(b(0));
        ScalarReal v1(b(1));
        ScalarReal v2(b(2));
        t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + tr(0);
        t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + tr(1);
        t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + tr(2);
        t(3) = 0;
    } while (--i >= 0);
}
static __forceinline void GetClosest(const CdBody* bodyA, const CdBody* bodyB, const CollisionInput* input, PointResult* points) {
    float tol = reinterpret_cast<const NativeCollisionInput*>(input)->tolerance;
    points[0].m_fClosestPointDistanceSquared = tol;
    points[1].m_fClosestPointDistanceSquared = tol;
    points[2].m_fClosestPointDistanceSquared = tol;
    const CapsuleShape* capA = bodyA->m_pCollisionShape;
    const CapsuleShape* capB = bodyB->m_pCollisionShape;
    NativeFloat4 capsuleA[2];
    if (0) { DeadFloats d0; DeadFloats u0 = *reinterpret_cast<const DeadFloats*>(input); d0 = u0; }
    NativeTransformPoints(*reinterpret_cast<const NativeTransform*>(bodyA->m_kMotionState), reinterpret_cast<const NativeFloat4*>(capA->GetIndexedVertices()), capsuleA, 2);
    NativeFloat4 capsuleB[2];
    NativeTransformPoints(*reinterpret_cast<const NativeTransform*>(bodyB->m_kMotionState), reinterpret_cast<const NativeFloat4*>(capB->GetIndexedVertices()), capsuleB, 2);
    FUN_0096d120(capsuleA, capA->m_fSphereRadius, capsuleB, capB->m_fSphereRadius, points);
}
}
void Agent::FUN_00d3c060(const CdBody* bodyA, const CdBody* bodyB, const CollisionInput* input, Collector* collector)
{
    using namespace f3m_009c57b0;
    {
        ProfilerTls* pBuf = (ProfilerTls*)TlsGetValue(DAT_0116913c);
        TimerEntry* pRec = (TimerEntry*)pBuf->unk04;
        if (pRec < (TimerEntry*)pBuf->unk0C)
        {
            pRec->tag = DAT_00e7f134;
            DWORD tick;
            __asm {
                rdtsc
                mov dword ptr [tick], eax
            }
            pRec->stamp = tick;
            pBuf->unk04 = (char*)(pRec + 1);
        }
    }

    PointResult results[3];
    GetClosest(bodyA, bodyB, input, results);

    unsigned short* contactId = &this->unk0C;
    PointResult* res = results;
    for (int i = 0; i < 3; ++i, ++contactId, ++res)
    {
        if (res->m_fClosestPointDistanceSquared < reinterpret_cast<const NativeCollisionInput*>(input)->tolerance)
        {
            if (*contactId == 0xffff)
            {
                *contactId = ((MyCallback*)this->unk08)->slot0C(bodyA, bodyB, input, collector, 0, res);
                if (*contactId == 0xffff)
                {
                    goto next;
                }
            }
            AlignedPairData* outPoint = collector->m_cur;
            collector->m_cur = outPoint + 1;
            outPoint->m_vec0.x = res->m_vHitNormal.x;
            outPoint->m_vec0.y = res->m_vHitNormal.y;
            outPoint->m_vec0.z = res->m_vHitNormal.z;
            outPoint->m_vec0.w = res->m_vHitNormal.w;
            outPoint->m_vec1.x = res->m_posAndDistX;
            outPoint->m_vec1.y = res->m_posAndDistY;
            outPoint->m_vec1.z = res->m_posAndDistZ;
            outPoint->m_vec1.w = res->m_fClosestPointDistanceSquared;
            outPoint->m_usContactPointId = *contactId;
        }
        else
        {
            if (*contactId != 0xffff)
            {
                ((MyCallback*)this->unk08)->invoke(*contactId, collector->m_unk04);
                *contactId = 0xffff;
            }
        }
    next:;
    }

    {
        ProfilerTls* pBuf = (ProfilerTls*)TlsGetValue(DAT_0116913c);
        TimerEntry* pRec = (TimerEntry*)pBuf->unk04;
        if (pRec < (TimerEntry*)pBuf->unk0C)
        {
            pRec->tag = DAT_00e32798;
            DWORD tick;
            __asm {
                rdtsc
                mov dword ptr [tick], eax
            }
            pRec->stamp = tick;
            pBuf->unk04 = (char*)(pRec + 1);
        }
    }
}

