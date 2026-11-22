#include "f3_common.h"
// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d3ef70_CdBody;
struct S_00d3ef70_Input;
struct S_00d3ef70_Agent;
struct S_00d3ef70_Collector;

typedef S_00d3ef70_Agent* (*S_00d3ef70_CreateFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, void*);
typedef void (*S_00d3ef70_GetPenetrationsFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_GetClosestPointsFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_LinearCastFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&, S_00d3ef70_Collector*);

void FUN_00d3f040(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void FUN_00d3e330(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);

class InnerCls {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned short a, int b);
};

inline void InnerCls::v0() {}
inline void InnerCls::v1() {}
inline void InnerCls::v2() {}
inline void InnerCls::v3() {}
inline void InnerCls::v4() {}
inline void InnerCls::v5(unsigned short a, int b) { a; b; }

class FUN_00d3e2b0_cls {
public:
    virtual void v0(int a);
    int m_i04;
    InnerCls *m_pInner;
    unsigned short m_w0c;
    void FUN_00d3e2b0(int a1);
};

// @fnv 0x00d3e2b0
inline void FUN_00d3e2b0_cls::v0(int aiValue) { aiValue; }

void FUN_00d3e2b0_cls::FUN_00d3e2b0(int a1)
{
    if (m_w0c != 0xffff) {
        m_pInner->v5(m_w0c, a1);
    }
    v0(1);
}

void __cdecl FUN_00d3e330(int a, int b, int c, int d);

// @fnv 0x00d3e510
// pdb: hkpSphereCapsuleAgent::getPenetrations | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, vtable + skyrim(vtable), high
void __stdcall hkpSphereCapsuleAgent_getPenetrations(int a, int b, int c, int d)
{
    FUN_00d3e330(a, b, c, d);
}

extern char DAT_010ce81c;

struct FUN_00d3f040_tmp {
    const char* str;
    unsigned char flag;
    unsigned int value;
};

void __cdecl FUN_00d3e330(unsigned int a, unsigned int b, unsigned int c, FUN_00d3f040_tmp* p);

// Builds a FUN_00d3f040_tmp with value a3, flag 0 and str pointing at DAT_010ce81c, then calls FUN_00d3e330(a1, a0, a2, &t).
// @fnv 0x00d3f040
// pdb: hkpSymmetricAgentLinearCast<hkpSphereTriangleAgent>::staticGetPenetrations | hkpSphereTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d3f040(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int uiValue)
{
    FUN_00d3f040_tmp t;
    t.value = uiValue;
    t.flag = 0;
    t.str = &DAT_010ce81c;
    FUN_00d3e330(a1, a0, a2, &t);
}

extern char DAT_010ce81c;
struct AgentDispatchDescriptor {
    const void* dispatchTable;
    unsigned char isFlipped;
    volatile unsigned int tag;
};
struct CollisionDispatcher {
    void hkpSphereCapsuleAgent_getPenetrations(void* bodyB, void* bodyA, void* input, AgentDispatchDescriptor* descriptor);
    void FUN_00d3f000(void* bodyA, void* bodyB, void* volatile input, unsigned int tag);
};
// Builds an AgentDispatchDescriptor with the given tag and a fixed dispatch table, then calls hkpSphereCapsuleAgent_getPenetrations with the bodies swapped.
// @fnv 0x00d3f000
// pdb: hkpSymmetricAgentLinearCast<hkpSphereCapsuleAgent>::getPenetrations | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
void CollisionDispatcher::FUN_00d3f000(void* bodyA, void* bodyB, void* volatile input, unsigned int tag)
{
    AgentDispatchDescriptor descriptor;
    descriptor.tag = tag;
    descriptor.isFlipped = false;
    descriptor.dispatchTable = &DAT_010ce81c;
    hkpSphereCapsuleAgent_getPenetrations(bodyB, bodyA, input, &descriptor);
}

union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct SphCap_Vector4 {
    __m128 m_vComponents;
};

struct SphCap_Transform {
    SphCap_Vector4 m_kColumn0;
    SphCap_Vector4 m_kColumn1;
    SphCap_Vector4 m_kColumn2;
    SphCap_Vector4 m_vTranslation;
};

struct __declspec(align(16)) SphCap_Vector4F {
    float x;
    float y;
    float z;
    float w;
};

struct SphCap_Shape {
    void* m_vtbl;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    float m_fSphereRadius;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    SphCap_Vector4 m_kVertexA;
    SphCap_Vector4 m_kVertexB;
};

struct S_00d3ef70_CdBody {
    const SphCap_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const SphCap_Transform* m_pMotionState;
};

struct S_00d3ef70_Collector {
    virtual void slot00();
    virtual void AddCdBodyPair(const S_00d3ef70_CdBody& a, const S_00d3ef70_CdBody& b);
};

// @f3 0x009c80e0 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char str_00e7f2c0[];
extern const char str_00e32798[];

namespace N009c80e0 {

typedef float hkReal;
struct hkTransform;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return x * a.x + y * a.y + z * a.z; }
    __forceinline hkReal lengthSquared3() const { return dot3(*this); }
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
    __forceinline void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.getColumn(3);
        m_rotation.m_col0 = col0;
        m_rotation.m_col1 = col1;
        m_rotation.m_col2 = col2;
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
    __forceinline const hkReal& operator()(int r, int c) const { return m_rotation(r, c); }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2 + t(0, 3);
    y = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2 + t(1, 3);
    z = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2 + t(2, 3);
    w = 0;
}

__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

struct hkpConvexShape
{
    void* m_vtbl;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    hkReal m_radius;
    __forceinline hkReal getRadius() const { return m_radius; }
};

struct hkpSphereShape : hkpConvexShape
{
};

struct hkpCapsuleShape : hkpConvexShape
{
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }
};

struct ClosestPointLineSegResult
{
    hkVector4 m_pointOnEdge;
};

struct hkpCdBody
{
    const hkpConvexShape* m_shape;
    unsigned int m_shapeKey;
    const hkTransform* m_motion;
    __forceinline const hkpConvexShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *m_motion; }
};

struct TimerCommand
{
    const char* m_commandAndMonitor;
    unsigned int m_time0;
    unsigned int m_time1;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_time0 = ticks;
    }
};

struct hkBool
{
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }
    char m_bool;
};

struct hkMonitorStream
{
    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16; }
    __forceinline hkBool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline void setEnd(char* e) { m_end = e; }
};

__forceinline hkMonitorStream& getMonitorStream()
{
    return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c));
}

__forceinline void timerCommand(const char* name)
{
    hkMonitorStream& mStream = getMonitorStream();
    if (mStream.memoryAvailable())
    {
        TimerCommand* h = reinterpret_cast<TimerCommand*>(mStream.getEnd());
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.setEnd((char*)(h + 1));
    }
}

void __cdecl FUN_0096fa60(const hkVector4& point, const hkVector4& start, const hkVector4& end,
                          ClosestPointLineSegResult& result);

}

using namespace N009c80e0;

void FUN_00d3e330(const S_00d3ef70_CdBody& bodyAIn, const S_00d3ef70_CdBody& bodyBIn, const S_00d3ef70_Input& input,
                  S_00d3ef70_Collector& collector)
{
    timerCommand(str_00e7f2c0);

    const hkpCdBody& bodyA = reinterpret_cast<const hkpCdBody&>(bodyAIn);
    const hkpCdBody& bodyB = reinterpret_cast<const hkpCdBody&>(bodyBIn);

    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.getShape());
    const hkpCapsuleShape* capsuleB = static_cast<const hkpCapsuleShape*>(bodyB.getShape());

    const hkVector4& posA = bodyA.getTransform().getTranslation();

    hkVector4 capsB[2];
    transformPoints(bodyB.getTransform(), capsuleB->getVertices(), 2, &capsB[0]);

    ClosestPointLineSegResult result;
    FUN_0096fa60(posA, capsB[0], capsB[1], result);

    hkVector4 aMinusB;
    aMinusB.setSub4(result.m_pointOnEdge, posA);

    const hkReal radiusSum = sphereA->getRadius() + capsuleB->getRadius();
    const hkReal refDist2 = radiusSum * radiusSum;

    hkReal distSquared = aMinusB.lengthSquared3();
    if (distSquared < refDist2)
    {
        collector.AddCdBodyPair(bodyAIn, bodyBIn);
    }

    timerCommand(str_00e32798);
}

