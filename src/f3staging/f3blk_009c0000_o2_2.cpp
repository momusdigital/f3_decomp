#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_009c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x009de9f0 (community match, verified in this file)
#include <math.h>
namespace f3m_009de9f0 {
struct Scalar863 { float value; Scalar863(float f):value(f) {} operator float() const {return value;} };


template <typename T>
FNV_FORCEINLINE void Swap_e9f0(T& x, T& y)
{
    T t(x);
    x = y;
    y = t;
}

FNV_FORCEINLINE Scalar863 SqrtInverse_e9f0(Scalar863 x)
{
    const float zero = 0.0f;
    if (x != zero)
        return 1.0f / sqrtf(x);
    return zero;
}

class Vec4_e9f0
{
public:
    FNV_FORCEINLINE Vec4_e9f0() {}

    FNV_FORCEINLINE float& operator()(int i)
    {
        return (&x)[i];
    }

    FNV_FORCEINLINE const float& operator()(int i) const
    {
        return (&x)[i];
    }

    FNV_FORCEINLINE void set(float a, float b, float c, float d = 0.0f)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    FNV_FORCEINLINE void setMul4(float rs, const Vec4_e9f0& a)
    {
        float r = float(rs);
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }

    FNV_FORCEINLINE void setCross(const Vec4_e9f0& v1, const Vec4_e9f0& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }

    FNV_FORCEINLINE float lengthSquared3() const
    {
        return (x * x) + (y * y) + (z * z);
    }

    FNV_FORCEINLINE void mul4(float rs)
    {
        float r = float(rs);
        x *= r;
        y *= r;
        z *= r;
        w *= r;
    }

    FNV_FORCEINLINE void normalize3()
    {
        setMul4(SqrtInverse_e9f0(lengthSquared3()), *this);
    }

    FNV_FORCEINLINE Scalar863 dot3(const Vec4_e9f0& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }

private:
    FNV_ALIGN(16) float x;
    float y;
    float z;
    float w;
};

struct Plane_e9f0
{
    Vec4_e9f0 m_normal;
    float m_f40;
    float m_f44;
    float m_dist;
    float m_f4c;
};
struct __declspec(align(16)) Base_e9f0
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
    Vec4_e9f0 m_verts[6];
    int unkB0;
    int unkB4;
    int m_count;
};
void __cdecl FUN_009f90f0(const Plane_e9f0* plane, void* out, int arg);
// pdb: hkpGenericConstraintData::setConeLimitW | hkpGenericConstraintData.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: currentCommand, currentData, scheme, vars, in, out
void __stdcall FUN_009de9f0(const int** pIdx, const Vec4_e9f0** pSrc, int unused, Base_e9f0* base, void* out, int arg)
{
    Plane_e9f0 p;
    int idx = *++(*pIdx);
    p.m_f4c = 0.5f;
    Vec4_e9f0 a = base->m_verts[idx];
    Vec4_e9f0 b = base->m_verts[idx + 3];
    p.m_normal.setCross(a, b);
    if (p.m_normal.lengthSquared3() < 1.1920929e-07f)
        return;
    p.m_normal.normalize3();
    const Vec4_e9f0* src = (*pSrc)++;
    p.m_dist = a.dot3(b);
    p.m_f40 = src->operator()(0);
    p.m_f44 = src->operator()(1);
    FUN_009f90f0(&p, out, arg);
    base->m_count++;
}

}   // namespace f3m_009de9f0

// @f3 0x009c3190 (community match, verified in this file)
namespace f3m_009c3190 {
// 0x009c3190: the closest points between a capsule (body A) and a triangle (body B), reported to a collector
// (hkpCapsuleTriangleAgent::getClosestPoints in Havok terms). Capsule end points and triangle are moved to world
// space, the capsule against triangle routine gives two candidate points using the agent's distance cache, and the
// nearer one, if within tolerance, is handed to the collector.

// from the Windows API (declared here: windows.h cannot be included after intrin.h with this compiler)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_009c3190 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern unsigned long DAT_0116913c;      // TLS slot of the per-thread monitor stream

// holds a value of the given type (padded on other platforms)
template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE val) : m_storage(val) {}
    __forceinline void operator=(TYPE val) { m_storage = val; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    // this = t * b, as a point
    __forceinline void _setTransformedPos(const struct hkTransform& t, const hkVector4& b);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    __forceinline void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int column) const { return getColumn(column)(row); }
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.m_translation;

        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }

    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    const hkVector4& p = t.getTranslation();
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + p(0);
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + p(1);
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + p(2);
    w = 0;
}

// moves points by a transform (from a copy, so the output may overlap it)
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

class hkpConvexShape
{
public:
    __forceinline hkReal getRadius() const { return m_radius; }

    void* m_vtable;
    int unk04;
    unsigned int m_userData;
    int m_type;
    hkReal m_radius;
};

class hkpCapsuleShape : public hkpConvexShape
{
public:
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    int unk14[3];
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpCdBody
{
    const void* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *reinterpret_cast<const hkTransform*>(m_motion); }
    __forceinline const void* getShape() const { return m_shape; }
};

struct hkpCollisionInput
{
    hkPadSpu<void*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;

    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

class hkpTriangleShape : public hkpConvexShape
{
public:
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    int unk14[3];
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

typedef unsigned int hkBool32;

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;

    __forceinline hkReal getDistance() const { return m_separatingNormal(3); }
};

namespace hkpCollideTriangleUtil
{
    struct PointTriangleDistanceCache
    {
        hkReal m_invEdgeLen[3];
        hkReal m_normalLen;
        hkReal m_invNormalLen;
    };
}

// hkCollideCapsuleUtilCapsVsTri: contact points between a capsule and a triangle, both in world space
void __cdecl FUN_0096e450(const hkVector4* capsAPoints, hkReal capsARadius, const hkVector4* triVertices, hkReal triBRadius, const hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkReal collisionTolerance, int searchManifold, hkContactPoint* points);

// contact points between the capsule of body A and the triangle of body B
static __forceinline void getClosestPointsInl(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, int searchManifold, hkContactPoint* points)
{
    const hkpCapsuleShape* capsuleA = static_cast<const hkpCapsuleShape*>(bodyA.getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());

    // capsule and triangle in world space
    hkVector4 endPoints[2];
    transformPoints(bodyA.getTransform(), capsuleA->getVertices(), 2, endPoints);

    hkVector4 triVertices[3];
    transformPoints(bodyB.getTransform(), triB->getVertices(), 3, &triVertices[0]);

    FUN_0096e450(endPoints, capsuleA->getRadius(), triVertices, triB->getRadius(), cache, input.getTolerance(), searchManifold, points);
}

// the nearer of the two contact candidates between capsule and triangle, when within tolerance
static __forceinline hkBool32 getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkContactPoint& cpoint)
{
    hkContactPoint points[3];
    getClosestPointsInl(bodyA, bodyB, input, cache, 0, points);

    // the nearer of the two candidates
    {
        hkReal dist0 = points[0].getDistance();
        hkReal dist1 = points[1].getDistance();
        if (dist0 < dist1)
        {
            if (dist0 < input.getTolerance())
            {
                cpoint = points[0];
                return true;
            }
        }
        else
        {
            if (dist1 < input.getTolerance())
            {
                cpoint = points[1];
                return true;
            }
        }
    }
    return false;
}

struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

class hkpCdPointCollector
{
public:
    virtual void vf00();
    virtual void addCdPoint(const hkpCdPoint& point);
};

typedef unsigned short hkContactPointId;

class hkpCapsuleTriangleAgent
{
public:
    void hkpCapsuleTriangleAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector);

    void* m_vtable;
    int unk04;
    void* m_contactMgr;
    hkContactPointId m_contactPointId[3];
    hkpCollideTriangleUtil::PointTriangleDistanceCache m_triangleCache;
};

// pdb: hkpCapsuleTriangleAgent::getClosestPoints | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpCapsuleTriangleAgent::hkpCapsuleTriangleAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtCapsTriangle";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpCdPoint event(bodyA, bodyB);

    if (getClosestPoint(bodyA, bodyB, input, m_triangleCache, event.m_contact))
    {
        collector.addCdPoint(event);
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009c3190

// @f3 0x009c3590 (community match, verified in this file)
namespace f3m_009c3590 {
// 0x009c3590: the closest points between a capsule (body A) and a triangle (body B), reported to a collector
// (hkpCapsuleTriangleAgent::staticGetClosestPoints in Havok terms). A distance cache is set up for the triangle,
// capsule end points and triangle are moved to world space, the capsule against triangle routine gives two
// candidate points, and the nearer one, if within tolerance, is handed to the collector.

// from the Windows API (declared here: windows.h cannot be included after intrin.h with this compiler)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_009c3590 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern unsigned long DAT_0116913c;      // TLS slot of the per-thread monitor stream

// holds a value of the given type (padded on other platforms)
template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE val) : m_storage(val) {}
    __forceinline void operator=(TYPE val) { m_storage = val; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    // this = t * b, as a point
    __forceinline void _setTransformedPos(const struct hkTransform& t, const hkVector4& b);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    __forceinline void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int column) const { return getColumn(column)(row); }
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.m_translation;

        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }

    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    const hkVector4& p = t.getTranslation();
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + p(0);
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + p(1);
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + p(2);
    w = 0;
}

// moves points by a transform (from a copy, so the output may overlap it)
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

class hkpConvexShape
{
public:
    __forceinline hkReal getRadius() const { return m_radius; }

    void* m_vtable;
    int unk04;
    unsigned int m_userData;
    int m_type;
    hkReal m_radius;
};

class hkpCapsuleShape : public hkpConvexShape
{
public:
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    int unk14[3];
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpCdBody
{
    const void* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *reinterpret_cast<const hkTransform*>(m_motion); }
    __forceinline const void* getShape() const { return m_shape; }
};

struct hkpCollisionInput
{
    hkPadSpu<void*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;

    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

class hkpTriangleShape : public hkpConvexShape
{
public:
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    int unk14[3];
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

typedef unsigned int hkBool32;

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;

    __forceinline hkReal getDistance() const { return m_separatingNormal(3); }
};

namespace hkpCollideTriangleUtil
{
    struct PointTriangleDistanceCache
    {
        hkReal m_invEdgeLen[3];
        hkReal m_normalLen;
        hkReal m_invNormalLen;
    };
}

// hkCollideCapsuleUtilCapsVsTri: contact points between a capsule and a triangle, both in world space
void __cdecl FUN_0096e450(const hkVector4* capsAPoints, hkReal capsARadius, const hkVector4* triVertices, hkReal triBRadius, const hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkReal collisionTolerance, int searchManifold, hkContactPoint* points);

// contact points between the capsule of body A and the triangle of body B
static __forceinline void getClosestPointsInl(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, int searchManifold, hkContactPoint* points)
{
    const hkpCapsuleShape* capsuleA = static_cast<const hkpCapsuleShape*>(bodyA.getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());

    // capsule and triangle in world space
    hkVector4 endPoints[2];
    transformPoints(bodyA.getTransform(), capsuleA->getVertices(), 2, endPoints);

    hkVector4 triVertices[3];
    transformPoints(bodyB.getTransform(), triB->getVertices(), 3, &triVertices[0]);

    FUN_0096e450(endPoints, capsuleA->getRadius(), triVertices, triB->getRadius(), cache, input.getTolerance(), searchManifold, points);
}

// the nearer of the two contact candidates between capsule and triangle, when within tolerance
static __forceinline hkBool32 getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkContactPoint& cpoint)
{
    hkContactPoint points[3];
    getClosestPointsInl(bodyA, bodyB, input, cache, 0, points);

    // the nearer of the two candidates
    {
        hkReal dist0 = points[0].getDistance();
        hkReal dist1 = points[1].getDistance();
        if (dist0 < dist1)
        {
            if (dist0 < input.getTolerance())
            {
                cpoint = points[0];
                return true;
            }
        }
        else
        {
            if (dist1 < input.getTolerance())
            {
                cpoint = points[1];
                return true;
            }
        }
    }
    return false;
}

struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

class hkpCdPointCollector
{
public:
    virtual void vf00();
    virtual void addCdPoint(const hkpCdPoint& point);
};

// setupPointTriangleDistanceCache: precomputes the triangle's edge and normal lengths
void __cdecl FUN_0096fd30(const hkVector4* triVertices, hkpCollideTriangleUtil::PointTriangleDistanceCache& cache);

// pdb: hkpCapsuleTriangleAgent::staticGetClosestPoints | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_009c3590(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtCapsTriangle";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpCollideTriangleUtil::PointTriangleDistanceCache cache;
    {
        const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());
        FUN_0096fd30(triB->getVertices(), cache);
    }

    hkpCdPoint event(bodyA, bodyB);

    if (getClosestPoint(bodyA, bodyB, input, cache, event.m_contact))
    {
        collector.addCdPoint(event);
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009c3590

// @f3 0x009c4120 (community match, verified in this file)
namespace f3m_009c4120 {
// 0x009c4120: contacts between a capsule (body A) and a triangle (body B), hkpCapsuleTriangleAgent::processCollision
// in Havok terms. Capsule end points and triangle are moved to world space, the capsule against triangle routine
// gives up to three contact points, and each is added, refreshed or removed in the contact manager.

// from the Windows API (declared here: windows.h cannot be included after intrin.h with this compiler)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_009c4120 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern unsigned long DAT_0116913c;      // TLS slot of the per-thread monitor stream

// holds a value of the given type (padded on other platforms)
template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE val) : m_storage(val) {}
    __forceinline void operator=(TYPE val) { m_storage = val; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    // this = t * b, as a point
    __forceinline void _setTransformedPos(const struct hkTransform& t, const hkVector4& b);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    __forceinline void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int column) const { return getColumn(column)(row); }
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.m_translation;

        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }

    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    const hkVector4& p = t.getTranslation();
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + p(0);
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + p(1);
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + p(2);
    w = 0;
}

// moves points by a transform (from a copy, so the output may overlap it)
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

class hkpConvexShape
{
public:
    __forceinline hkReal getRadius() const { return m_radius; }

    void* m_vtable;
    int unk04;
    unsigned int m_userData;
    int m_type;
    hkReal m_radius;
};

class hkpCapsuleShape : public hkpConvexShape
{
public:
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    int unk14[3];
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpCdBody
{
    const void* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *reinterpret_cast<const hkTransform*>(m_motion); }
    __forceinline const void* getShape() const { return m_shape; }
};

struct hkpCollisionInput
{
    hkPadSpu<void*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;

    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

class hkpTriangleShape : public hkpConvexShape
{
public:
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    int unk14[3];
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

struct hkpProcessCollisionInput : public hkpCollisionInput
{
};

typedef unsigned short hkContactPointId;
enum { HK_INVALID_CONTACT_POINT = 0xffff };

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;

    __forceinline const hkVector4& getPosition() const { return m_position; }
    __forceinline const hkVector4& getSeparatingNormal() const { return m_separatingNormal; }
    __forceinline hkReal getDistance() const { return m_separatingNormal(3); }
    __forceinline void setPosition(const hkVector4& position) { m_position = position; }
    __forceinline void setSeparatingNormal(const hkVector4& normal) { m_separatingNormal = normal; }
};

struct hkpProcessCdPoint
{
    hkContactPoint m_contact;
    unsigned int m_contactPointId;
    int pad24[3];
};

struct hkpConstraintOwner;

struct hkpProcessCollisionOutput
{
    hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
    hkPadSpu<hkpConstraintOwner*> m_constraintOwner;

    __forceinline hkpProcessCdPoint* reserveContactPoints(int numberOfPoints) { return m_firstFreeContactPoint; }
    __forceinline void commitContactPoints(int numberOfPoints) { m_firstFreeContactPoint = m_firstFreeContactPoint + numberOfPoints; }
    __forceinline void abortContactPoints(int numberOfPoints) {}
};

class hkpContactMgr
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual hkContactPointId addContactPoint(const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const void* event, const hkContactPoint& cp);
    virtual void vf10();
    virtual void removeContactPoint(hkContactPointId cpId, hkpConstraintOwner& info);
};

namespace hkpCollideTriangleUtil
{
    struct PointTriangleDistanceCache
    {
        hkReal m_invEdgeLen[3];
        hkReal m_normalLen;
    };
}

// hkCollideCapsuleUtilCapsVsTri: up to three contact points between a capsule and a triangle, both in world space
void __cdecl FUN_0096e450(const hkVector4* capsAPoints, hkReal capsARadius, const hkVector4* triVertices, hkReal triBRadius, const hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkReal collisionTolerance, int searchManifold, hkContactPoint* points);

class hkpCapsuleTriangleAgent
{
public:
    void hkpCapsuleTriangleAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result);
    static __forceinline void getClosestPointsInl(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkContactPoint* points);

    void* m_vtable;
    int unk04;
    hkpContactMgr* m_contactMgr;
    hkContactPointId m_contactPointId[3];
    hkpCollideTriangleUtil::PointTriangleDistanceCache m_triangleCache;
};

// up to three contact points between the capsule of body A and the triangle of body B
__forceinline void hkpCapsuleTriangleAgent::getClosestPointsInl(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkContactPoint* points)
{
    const hkpCapsuleShape* capsuleA = static_cast<const hkpCapsuleShape*>(bodyA.getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());

    // capsule and triangle in world space
    hkVector4 endPoints[2];
    transformPoints(bodyA.getTransform(), capsuleA->getVertices(), 2, endPoints);

    hkVector4 triVertices[3];
    transformPoints(bodyB.getTransform(), triB->getVertices(), 3, &triVertices[0]);

    FUN_0096e450(endPoints, capsuleA->getRadius(), triVertices, triB->getRadius(), cache, input.getTolerance(), 1, points);
}

// pdb: hkpCapsuleTriangleAgent::processCollision | hkpCapsuleTriangleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpCapsuleTriangleAgent::hkpCapsuleTriangleAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtCapsuleTri";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkContactPoint points[3];
    getClosestPointsInl(bodyA, bodyB, input, m_triangleCache, points);

    {
        for (int p = 0; p < 3; p++)
        {
            if (points[p].getDistance() < input.getTolerance())
            {
                if (m_contactPointId[p] == HK_INVALID_CONTACT_POINT)
                {
                    m_contactPointId[p] = m_contactMgr->addContactPoint(bodyA, bodyB, input, result, 0, points[p]);
                }

                if (m_contactPointId[p] != HK_INVALID_CONTACT_POINT)
                {
                    hkpProcessCdPoint& point = *result.reserveContactPoints(1);
                    result.commitContactPoints(1);
                    point.m_contact.setPosition(points[p].getPosition());
                    point.m_contact.setSeparatingNormal(points[p].getSeparatingNormal());
                    point.m_contactPointId = m_contactPointId[p];
                }
            }
            else
            {
                // too far apart: this slot loses its contact point
                if (m_contactPointId[p] != HK_INVALID_CONTACT_POINT)
                {
                    m_contactMgr->removeContactPoint(m_contactPointId[p], *result.m_constraintOwner.val());
                    m_contactPointId[p] = HK_INVALID_CONTACT_POINT;
                }
            }
        }
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009c4120

// @f3 0x009c5400 (community match, verified in this file)
namespace f3m_009c5400 {
// 0x009c5400: the closest points between two capsules, reported to a collector
// (hkpCapsuleCapsuleAgent::staticGetClosestPoints in Havok terms). Both capsules' end points are moved to world
// space and handed to the capsule against capsule closest point routine; a contact within tolerance is reported.

// from the Windows API (declared here: windows.h cannot be included after intrin.h with this compiler)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_009c5400 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern unsigned long DAT_0116913c;      // TLS slot of the per-thread monitor stream

// holds a value of the given type (padded on other platforms)
template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE val) : m_storage(val) {}
    __forceinline void operator=(TYPE val) { m_storage = val; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    // this = t * b, as a point
    __forceinline void _setTransformedPos(const struct hkTransform& t, const hkVector4& b);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    __forceinline void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int column) const { return getColumn(column)(row); }
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.m_translation;

        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }

    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    const hkVector4& p = t.getTranslation();
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + p(0);
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + p(1);
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + p(2);
    w = 0;
}

// moves points by a transform (from a copy, so the output may overlap it)
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

class hkpConvexShape
{
public:
    __forceinline hkReal getRadius() const { return m_radius; }

    void* m_vtable;
    int unk04;
    unsigned int m_userData;
    int m_type;
    hkReal m_radius;
};

class hkpCapsuleShape : public hkpConvexShape
{
public:
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    int unk14[3];
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpCdBody
{
    const void* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *reinterpret_cast<const hkTransform*>(m_motion); }
    __forceinline const void* getShape() const { return m_shape; }
};

struct hkpCollisionInput
{
    hkPadSpu<void*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;

    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

class hkpCdPointCollector
{
public:
    virtual void vf00();
    virtual void addCdPoint(const hkpCdPoint& point);
};

enum hkResult
{
    HK_SUCCESS = 0,
    HK_FAILURE = 1
};

// the closest points between two capsules given by their end points and radii; fails when they are farther apart
// than the tolerance
hkResult __cdecl FUN_0096e0d0(const hkVector4* capsAPoints, hkReal capsARadius, const hkVector4* capsBPoints, hkReal capsBRadius, hkReal collisionTolerance, hkContactPoint& contactOut);

// the contact between the two capsules, when they are within tolerance
static __forceinline hkBool getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkContactPoint& contact)
{
    const hkpCapsuleShape* capsA = static_cast<const hkpCapsuleShape*>(bodyA.getShape());
    const hkpCapsuleShape* capsB = static_cast<const hkpCapsuleShape*>(bodyB.getShape());

    hkVector4 pA[2];
    transformPoints(bodyA.getTransform(), capsA->getVertices(), 2, &pA[0]);
    hkVector4 pB[2];
    transformPoints(bodyB.getTransform(), capsB->getVertices(), 2, &pB[0]);

    hkResult res = FUN_0096e0d0(pA, capsA->getRadius(), pB, capsB->getRadius(), input.getTolerance(), contact);
    return res == HK_SUCCESS;
}

// pdb: hkpCapsuleCapsuleAgent::staticGetClosestPoints | hkpCapsuleCapsuleAgent.obj | fnv360_0822_retail, ustr_rel + bridge(caller_sim|objrun) + skyrim(ustr_rel), high
void __cdecl hkpCapsuleCapsuleAgent_staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtCapsCaps";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpCdPoint event(bodyA, bodyB);

    if (getClosestPoint(bodyA, bodyB, input, event.m_contact))
    {
        collector.addCdPoint(event);
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009c5400

// @f3 0x009c7b80 (community match, verified in this file)
namespace f3m_009c7b80 {
// 0x009c7b80: contact between a sphere (body A) and a triangle (body B), hkpSphereTriangleAgent::processCollision in
// Havok terms. The triangle is moved to world space, the closest point on it to the sphere centre is found, and one
// contact point is kept while the two are within tolerance, removed otherwise.

// from the Windows API (declared here: windows.h cannot be included after intrin.h with this compiler)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_009c7b80 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern unsigned long DAT_0116913c;      // TLS slot of the per-thread monitor stream

// holds a value of the given type (padded on other platforms)
template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE val) : m_storage(val) {}
    __forceinline void operator=(TYPE val) { m_storage = val; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    // this = t * b, as a point
    __forceinline void _setTransformedPos(const struct hkTransform& t, const hkVector4& b);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    __forceinline void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int column) const { return getColumn(column)(row); }
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.m_translation;

        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }

    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    const hkVector4& p = t.getTranslation();
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + p(0);
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + p(1);
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + p(2);
    w = 0;
}

// moves points by a transform (from a copy, so the output may overlap it)
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

class hkpConvexShape
{
public:
    __forceinline hkReal getRadius() const { return m_radius; }

    void* m_vtable;
    int unk04;
    unsigned int m_userData;
    int m_type;
    hkReal m_radius;
};

class hkpSphereShape : public hkpConvexShape
{
};

class hkpTriangleShape : public hkpConvexShape
{
public:
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    int unk14[3];
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

struct hkpCdBody
{
    const void* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *reinterpret_cast<const hkTransform*>(m_motion); }
    __forceinline const void* getShape() const { return m_shape; }
};

struct hkpProcessCollisionInput;

typedef unsigned short hkContactPointId;
enum { HK_INVALID_CONTACT_POINT = 0xffff };

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;

    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline void setSeparatingNormal(const hkVector4& normal, hkReal dist)
    {
        m_separatingNormal = normal;
        m_separatingNormal(3) = dist;
    }
};

struct hkpProcessCdPoint
{
    hkContactPoint m_contact;
    unsigned int m_contactPointId;
    int pad24[3];
};

struct hkpConstraintOwner;

struct hkpProcessCollisionOutput
{
    hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
    hkPadSpu<hkpConstraintOwner*> m_constraintOwner;

    __forceinline hkpProcessCdPoint* reserveContactPoints(int numberOfPoints) { return m_firstFreeContactPoint; }
    __forceinline void commitContactPoints(int numberOfPoints) { m_firstFreeContactPoint = m_firstFreeContactPoint + numberOfPoints; }
    __forceinline void abortContactPoints(int numberOfPoints) {}
};

class hkpContactMgr
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual hkContactPointId addContactPoint(const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const void* event, const hkContactPoint& cp);
    virtual void vf10();
    virtual void removeContactPoint(hkContactPointId cpId, hkpConstraintOwner& info);
};

namespace hkpCollideTriangleUtil
{
    struct ClosestPointTriangleCache
    {
        int m_data[4];
    };
    struct ClosestPointTriangleResult
    {
        hkVector4 hitDirection;
        hkReal distance;
    };
}

// closestPointTriangle: the closest point on a triangle to a position
int __cdecl hkpCollideTriangleUtil_closestPointTriangle(const hkVector4& position, const hkVector4* triVertices, const hkpCollideTriangleUtil::ClosestPointTriangleCache& cache, hkpCollideTriangleUtil::ClosestPointTriangleResult& result);

struct hkpCollisionInput
{
    void* m_dispatcher;
    hkReal m_tolerance;

    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

struct hkpProcessCollisionInput : public hkpCollisionInput
{
};

class hkpSphereTriangleAgent
{
public:
    void hkpSphereTriangleAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result);

    // the contact between the sphere and the triangle, when they are within tolerance
    static __forceinline hkBool getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCollideTriangleUtil::ClosestPointTriangleCache& cache, hkContactPoint& cpoint);

    void* m_vtable;
    int unk04;
    hkpContactMgr* m_contactMgr;
    hkContactPointId m_contactPointId;
    hkpCollideTriangleUtil::ClosestPointTriangleCache m_closestPointTriangleCache;
};

__forceinline hkBool hkpSphereTriangleAgent::getClosestPoint(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCollideTriangleUtil::ClosestPointTriangleCache& cache, hkContactPoint& cpoint)
{
    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());

    const hkVector4& posA = bodyA.getTransform().getTranslation();

    // the triangle in world space
    hkVector4 triVertices[3];
    transformPoints(bodyB.getTransform(), triB->getVertices(), 3, triVertices);

    hkpCollideTriangleUtil::ClosestPointTriangleResult cpResult;
    hkpCollideTriangleUtil_closestPointTriangle(posA, &triVertices[0], cache, cpResult);

    const hkReal radiusSum = sphereA->getRadius() + triB->getRadius();
    const hkReal maxDist = radiusSum + input.getTolerance();

    if (cpResult.distance < maxDist)
    {
        // on the triangle's surface, under the sphere
        cpoint.getPosition().setAddMul4(posA, cpResult.hitDirection, triB->getRadius() - cpResult.distance);
        cpoint.setSeparatingNormal(cpResult.hitDirection, cpResult.distance - radiusSum);
        return true;
    }
    return false;
}

// pdb: hkpSphereTriangleAgent::processCollision | hkpSphereTriangleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpSphereTriangleAgent::hkpSphereTriangleAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtSphereTri";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpProcessCdPoint& point = *result.reserveContactPoints(1);

    if (getClosestPoint(bodyA, bodyB, input, m_closestPointTriangleCache, point.m_contact))
    {
        if (m_contactPointId == HK_INVALID_CONTACT_POINT)
        {
            m_contactPointId = m_contactMgr->addContactPoint(bodyA, bodyB, input, result, 0, point.m_contact);
        }

        if (m_contactPointId != HK_INVALID_CONTACT_POINT)
        {
            point.m_contactPointId = m_contactPointId;
            result.commitContactPoints(1);
        }
        else
        {
            result.abortContactPoints(1);
        }
    }
    else
    {
        if (m_contactPointId != HK_INVALID_CONTACT_POINT)
        {
            m_contactMgr->removeContactPoint(m_contactPointId, *result.m_constraintOwner.val());
            m_contactPointId = HK_INVALID_CONTACT_POINT;
        }
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009c7b80

// @f3 0x009c8710 (community match, verified in this file)
#include <math.h>
namespace f3m_009c8710 {

// 0x009c8710: the closest points between a sphere (body A) and a capsule (body B), reported to a collector
// (hkpSphereCapsuleAgent::getClosestPoints in Havok terms). The capsule's axis is moved to world space, the closest
// point on it to the sphere centre gives the separating direction (any direction across the axis when the centre
// lies on it), and a contact within tolerance is handed to the collector.

// from the Windows API (declared here: windows.h cannot be included after intrin.h with this compiler)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace f3m_009c8710 {

typedef float hkReal;
typedef unsigned int hkUint32;

extern unsigned long DAT_0116913c;      // TLS slot of the per-thread monitor stream

// holds a value of the given type (padded on other platforms)
template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE val) : m_storage(val) {}
    __forceinline void operator=(TYPE val) { m_storage = val; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

// per-thread timer stream; a timer command is a tag string and a time stamp
class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

inline hkReal hkSqrt(hkReal r) { return sqrtf(r); }
inline hkReal hkSqrtInverse(hkReal r) { return 1.0f / hkSqrt(r); }
inline hkReal hkFabs(hkReal r) { return fabsf(r); }

class __declspec(align(16)) hkVector4
{
public:
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    // this = t * b, as a point
    __forceinline void _setTransformedPos(const struct hkTransform& t, const hkVector4& b);
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a(0) - b(0);
        y = a(1) - b(1);
        z = a(2) - b(2);
        w = a(3) - b(3);
    }
    __forceinline void mul4(hkReal s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    __forceinline hkReal lengthSquared3() const { return dot3(*this); }
    __forceinline hkReal lengthInverse3() const
    {
        hkReal l2 = lengthSquared3();
        return l2 ? hkSqrtInverse(l2) : 0;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }

    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkRotation
{
    __forceinline void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2)
    {
        m_col0 = c0;
        m_col1 = c1;
        m_col2 = c2;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int column) const { return getColumn(column)(row); }
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.m_translation;

        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }

    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    const hkVector4& p = t.getTranslation();
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + p(0);
    y = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + p(1);
    z = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + p(2);
    w = 0;
}

// moves points by a transform (from a copy, so the output may overlap it)
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

class hkpConvexShape
{
public:
    __forceinline hkReal getRadius() const { return m_radius; }

    void* m_vtable;
    int unk04;
    unsigned int m_userData;
    int m_type;
    hkReal m_radius;
};

class hkpCapsuleShape : public hkpConvexShape
{
public:
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    int unk14[3];
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
};

struct hkpCdBody
{
    const void* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;

    __forceinline const hkTransform& getTransform() const { return *reinterpret_cast<const hkTransform*>(m_motion); }
    __forceinline const void* getShape() const { return m_shape; }
};

struct hkpCollisionInput
{
    hkPadSpu<void*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;

    __forceinline hkReal getTolerance() const { return m_tolerance; }
};

class hkpSphereShape : public hkpConvexShape
{
};

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;

    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }
};

namespace hkLineSegmentUtil
{
    struct ClosestPointLineSegResult
    {
        hkVector4 m_pointOnEdge;
    };
}

// closestPointLineSeg: the point on the segment B..B2 closest to A
void __cdecl FUN_0096fa60(const hkVector4& A, const hkVector4& B, const hkVector4& B2, hkLineSegmentUtil::ClosestPointLineSegResult& result);

// a vector at right angles to the given one: the cross product with the axis of its smallest component
__forceinline void calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
    // the smallest component and the other two
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(vectorIn(0));
    hkReal a1 = hkFabs(vectorIn(1));
    hkReal a2 = hkFabs(vectorIn(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    biVectorOut.setZero4();

    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = -vectorIn(ok1);
}

enum ClosestPointResult
{
    ST_CP_MISS = 0,
    ST_CP_HIT = 1
};

// the contact between the sphere of body A and the capsule of body B
static __forceinline ClosestPointResult getClosestPointInl(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkContactPoint& cpoint)
{
    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.getShape());
    const hkpCapsuleShape* capsuleB = static_cast<const hkpCapsuleShape*>(bodyB.getShape());

    const hkVector4& posA = bodyA.getTransform().getTranslation();

    // the capsule's axis in world space
    hkVector4 capsB[2];
    transformPoints(bodyB.getTransform(), capsuleB->getVertices(), 2, capsB);

    hkLineSegmentUtil::ClosestPointLineSegResult result;
    FUN_0096fa60(posA, capsB[0], capsB[1], result);

    hkVector4 aMinusB;
    aMinusB.setSub4(posA, result.m_pointOnEdge);

    const hkReal radiusSum = sphereA->getRadius() + capsuleB->getRadius();
    const hkReal refDist = radiusSum + input.getTolerance();

    hkReal distSquared = aMinusB.lengthSquared3();
    if (distSquared >= refDist * refDist)
    {
        return ST_CP_MISS;
    }

    hkReal dist;
    if (distSquared > 0)
    {
        dist = hkSqrt(distSquared);
        cpoint.getSeparatingNormal() = aMinusB;
    }
    else
    {
        // the centre is on the axis: any direction across it will do
        dist = 0;
        hkVector4 edge;
        edge.setSub4(capsB[1], capsB[0]);
        calculatePerpendicularVector(edge, cpoint.getSeparatingNormal());
    }
    cpoint.getSeparatingNormal().normalize3();

    cpoint.getPosition().setAddMul4(posA, cpoint.getSeparatingNormal(), capsuleB->getRadius() - dist);
    cpoint.setDistance(dist - radiusSum);
    return ST_CP_HIT;
}

struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

class hkpCdPointCollector
{
public:
    virtual void vf00();
    virtual void addCdPoint(const hkpCdPoint& point);
};

class hkpSphereCapsuleAgent
{
public:
    void hkpSphereCapsuleAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector);
};

// pdb: hkpSphereCapsuleAgent::getClosestPoints | hkpSphereCapsuleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpSphereCapsuleAgent::hkpSphereCapsuleAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtSphereCapsule";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkpCdPoint event(bodyA, bodyB);

    if (getClosestPointInl(bodyA, bodyB, input, event.m_contact) != ST_CP_MISS)
    {
        collector.addCdPoint(event);
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

}
}   // namespace f3m_009c8710
