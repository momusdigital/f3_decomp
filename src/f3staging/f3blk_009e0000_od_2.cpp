#include <windows.h>
#include <math.h>
// src/f3staging/f3blk_009e0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x009ed8b0 (community match, verified in this file)
namespace f3m_009ed8b0 {
namespace n9ed8b0 {

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;

    __forceinline hkVector4() {}
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
};

struct hkTransform
{
    hkVector4 c0, c1, c2, c3;
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t) : c0(t.c0), c1(t.c1), c2(t.c2), c3(t.c3) {}
};

static __forceinline void xformPos(hkVector4& o, const hkVector4& c0, const hkVector4& c1, const hkVector4& c2, const hkVector4& c3, const hkVector4& b)
{
    const float* p0 = &c0.x; const float* p1 = &c1.x; const float* p2 = &c2.x; const float* p3 = &c3.x;
    const float v0 = b.x; const float v1 = b.y; const float v2 = b.z;
    o.x = p0[0] * v0 + p1[0] * v1 + p2[0] * v2 + p3[0];
    o.y = c0.y * v0 + c1.y * v1 + p2[1] * v2 + p3[1];
    o.z = p0[2] * v0 + p1[2] * v1 + p2[2] * v2 + p3[2];
    o.w = 0.0f;
}

static __forceinline void transformSpheres(const hkTransform& t, const hkVector4* in, int num, hkVector4* out)
{
    const hkVector4 c0 = t.c0;
    const hkVector4 c1 = t.c1;
    const hkVector4 c2 = t.c2;
    const hkVector4 c3 = t.c3;
    int i = num - 1;
    do
    {
        hkVector4 v;
        xformPos(v, c0, c1, c2, c3, in[i]);
        v.w = in[i].w;
        out[i] = v;
    } while (--i >= 0);
}

class hkpShape
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual int v24();
    virtual hkVector4* v28(hkVector4* out);
    virtual void v2c();
    virtual void v30();
};

struct hkpTransformShape
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* m_childShapeVtbl;
    hkpShape* m_childShape;
    int unk1c;
    hkTransform m_transform;

    hkVector4* FUN_009ed8b0(hkVector4* out) const;
};

// pdb: hkpConvexTransformShape::getCollisionSpheresImpl | hkpConvexTransformShape.obj | tesv_win, objrun_open, low
hkVector4* hkpTransformShape::FUN_009ed8b0(hkVector4* out) const
{
    const hkVector4* in = m_childShape->v28(out);
    int num = m_childShape->v24();
    transformSpheres(m_transform, in, num, out);
    return out;
}

}
}   // namespace f3m_009ed8b0


// @f3 0x009ea460 (community match, verified in this file)
#include <math.h>
namespace f3m_009ea460 {
// makeSphere (Havok 5.5.0, hkpInternal hkpGeometryUtility.cpp): the smallest sphere through two points, grown by
// extraRadius. A file-local function, so /O2 gives it a register calling convention (eax = p0, ecx = p1, esi =
// the returned sphere). Layouts and inlines follow the Havok 5.5 headers (FPU build,
// HK_DISABLE_VECTOR4_CONSTRUCTORS: hkVector4 has no constructors, operator= copies floats).

namespace f3h_009ea460 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

namespace hkMath
{
    inline hkReal sqrt(hkReal r) { return sqrtf(r); }
}

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        x = v0.x - v1.x;
        y = v0.y - v1.y;
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }
    __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        hkReal r = hkReal(rs);
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline hkSimdReal length3() const { return hkMath::sqrt((x * x) + (y * y) + (z * z)); }
};

class hkSphere
{
public:
    __forceinline hkSphere() {}
    inline hkSphere(const hkVector4& pt, hkReal radius)
    {
        m_pos = pt;
        m_pos(3) = radius;
    }

protected:
    hkVector4 m_pos; // the w part is the radius
};

// pdb: makeSphere | hkGeometryUtility.obj | tesv_win, call_gap_sim, low
static hkSphere FUN_009ea460(const hkVector4& p0, const hkVector4& p1, hkReal extraRadius)
{
    hkVector4 diff;
    diff.setSub4(p1, p0);
    hkVector4 half;
    half.setMul4(0.5f, diff);
    hkVector4 center;
    center.setAdd4(p0, half);
    return hkSphere(center, half.length3() + extraRadius);
}

// Callers in the same file (the real one is the minimum bounding sphere recursion).
hkSphere makeSphereCallerStandIn(const hkVector4* p, hkReal r) { return FUN_009ea460(p[0], p[1], r); }
hkSphere makeSphereCallerStandIn2(const hkVector4* p, hkReal r) { return FUN_009ea460(p[2], p[3], r * 2.0f); }

} // namespace f3h_009ea460
}   // namespace f3m_009ea460

// @f3 0x009fa490 (community match, verified in this file)
#include <math.h>
namespace f3m_009fa490 {
namespace f3m_009fa490 {

typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned long hkUlong;
enum hkResult { HK_SUCCESS = 0, HK_FAILURE = 1 };

const hkReal HK_REAL_EPSILON = 1.192092896e-07f;

extern "C" hkReal __cdecl hkMath_atan2fApproximation(hkReal x, hkReal y);

template <typename TYPE>
__forceinline TYPE* hkAddByteOffset(TYPE* base, hkUlong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }
private:
    TYPE m_storage;
};

template <typename ENUM, typename TYPE>
class hkEnum
{
public:
    __forceinline operator ENUM() const { return static_cast<ENUM>(m_storage); }
private:
    TYPE m_storage;
};

namespace hkMath
{
    __forceinline hkReal sqrt(hkReal r) { return ::sqrtf(r); }
    template <typename T> __forceinline T max2(T x, T y) { return x > y ? x : y; }
    template <typename T> __forceinline T min2(T x, T y) { return x < y ? x : y; }
}

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline void mul4(hkReal rs)
    {
        hkReal s = hkReal(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = hkReal(rs);
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline hkReal length3() const { return hkMath::sqrt((x * x) + (y * y) + (z * z)); }
};

class hkMatrix3
{
public:
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

class hkRotation : public hkMatrix3 {};

class hkTransform
{
public:
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    hkRotation m_rotation;
    hkVector4 m_translation;
};

struct hkpConstraintAtom
{
    hkUint16 m_type;
};

struct hkpConeLimitConstraintAtom : public hkpConstraintAtom
{
    enum MeasurementMode
    {
        ZERO_WHEN_VECTORS_ALIGNED = 0,
        ZERO_WHEN_VECTORS_PERPENDICULAR = 1
    };
    hkUint8 m_isEnabled;
    hkUint8 m_twistAxisInA;
    hkUint8 m_refAxisInB;
    hkEnum<MeasurementMode, hkUint8> m_angleMeasurementMode;
    hkUint8 m_memOffsetToAngleOffset;
    hkReal m_minAngle;
    hkReal m_maxAngle;
    hkReal m_angularLimitsTauFactor;
};

class hkpSolverResults
{
public:
    hkReal m_impulseApplied;
    hkReal m_internalSolverData;
};

class hkpConstraintQueryStepInfo
{
public:
    hkPadSpu<hkReal> m_substepDeltaTime;
    hkPadSpu<hkReal> m_microStepDeltaTime;
    hkPadSpu<hkReal> m_substepInvDeltaTime;
    hkPadSpu<hkReal> m_frameDeltaTime;
    hkPadSpu<hkReal> m_frameInvDeltaTime;
    hkPadSpu<hkReal> m_invNumSteps;
    hkPadSpu<hkReal> m_invNumStepsTimesMicroSteps;
    hkPadSpu<hkReal> m_rhsFactor;
    hkPadSpu<hkReal> m_virtMassFactor;
    hkPadSpu<hkReal> m_frictionRhsFactor;
    int m_pad28;
    int m_pad2c;
};

class hkpConstraintQueryIn : public hkpConstraintQueryStepInfo
{
public:
    hkPadSpu<const void*> m_bodyA;
    hkPadSpu<const void*> m_bodyB;
    hkPadSpu<const hkTransform*> m_transformA;
    hkPadSpu<const hkTransform*> m_transformB;
    hkPadSpu<hkReal> m_tau;
    hkPadSpu<hkReal> m_damping;
    hkPadSpu<void*> m_constraintInstance;
    hkPadSpu<void*> m_constraintRuntime;
};

class hkpConstraintQueryOut;

class hkp1dAngularLimitInfo
{
public:
    hkVector4 m_constrainedDofW;
    hkPadSpu<hkReal> m_min;
    hkPadSpu<hkReal> m_max;
    hkPadSpu<hkReal> m_computedAngle;
    hkPadSpu<hkReal> m_tau;
};

static __forceinline hkResult buildJacobianFromConeLimitAtom(const hkpConeLimitConstraintAtom& atom, const hkpConstraintQueryIn& in,
                                                             const hkTransform& baseA, const hkTransform& baseB,
                                                             hkp1dAngularLimitInfo& info, hkpConstraintQueryOut& out)
{
    const hkVector4& twistAxisAinWorld = baseA.getColumn(atom.m_twistAxisInA);
    const hkVector4& refAxisBinWorld = baseB.getColumn(atom.m_refAxisInB);

    hkVector4 cross;
    cross.setCross(twistAxisAinWorld, refAxisBinWorld);
    hkReal sinAngleSqrd = cross.lengthSquared3();
    if (sinAngleSqrd < HK_REAL_EPSILON)
    {
        return HK_FAILURE;
    }
    static const hkReal flipSignOrNot[2] = { 1.0f, -1.0f };
    static const hkReal shiftResultOrNot[2] = { 0.0f, 3.14159265358979f * 0.5f };
    const int mode = atom.m_angleMeasurementMode;
    hkReal cosAngle = twistAxisAinWorld.dot3(refAxisBinWorld);
    hkReal angle = hkMath_atan2fApproximation(cross.length3(), cosAngle) * flipSignOrNot[mode] + shiftResultOrNot[mode];
    hkReal sign = flipSignOrNot[1 - atom.m_angleMeasurementMode];

    info.m_tau = in.m_tau * atom.m_angularLimitsTauFactor;
    cross.mul4(1.0f / cross.length3());
    info.m_constrainedDofW.setMul4(sign, cross);
    info.m_computedAngle = angle;
    info.m_min = atom.m_minAngle;
    info.m_max = atom.m_maxAngle;
    return HK_SUCCESS;
}

// pdb: buildJacobianFromStabilizedConeLimitAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
static hkResult FUN_009fa490(const hkpConeLimitConstraintAtom& atom, const hkpConstraintQueryIn& in,
                             const hkTransform& baseA, const hkTransform& baseB,
                             hkp1dAngularLimitInfo& info, hkpConstraintQueryOut& out)
{
    const hkResult result = buildJacobianFromConeLimitAtom(atom, in, baseA, baseB, info, out);
    if (result == HK_SUCCESS && atom.m_memOffsetToAngleOffset > 1)
    {
        hkReal coneAngleOffset = *static_cast<hkReal*>(hkAddByteOffset(in.m_constraintRuntime.val(), atom.m_memOffsetToAngleOffset));
        hkpSolverResults* solverResults = static_cast<hkpSolverResults*>(in.m_constraintRuntime.val());
        hkReal impulse = -solverResults->m_internalSolverData;
        hkReal angle = info.m_computedAngle - coneAngleOffset;
        hkReal error = impulse - angle;
        hkReal maxStep = in.m_frameDeltaTime * 0.5f;
        hkReal step = hkMath::max2(coneAngleOffset * 0.05f, maxStep);
        coneAngleOffset = coneAngleOffset - step;
        angle = angle + step;
        hkReal negError = -error;
        hkReal threshold = (maxStep + 2.0f * step) * 0.5f;
        if (negError > threshold && impulse != 0.0f)
        {
            coneAngleOffset = coneAngleOffset - error;
            angle = angle + error;
        }
        coneAngleOffset = hkMath::max2(coneAngleOffset, HK_REAL_EPSILON);
        *static_cast<hkReal*>(hkAddByteOffset(in.m_constraintRuntime.val(), atom.m_memOffsetToAngleOffset)) = coneAngleOffset;
        info.m_computedAngle = angle;
    }
    return result;
}

hkResult hkSolverBuildJacobianConeStandIn(const hkpConeLimitConstraintAtom& atom, const hkpConstraintQueryIn& in,
                                          const hkTransform& baseA, const hkTransform& baseB,
                                          hkp1dAngularLimitInfo& info, hkpConstraintQueryOut& out)
{
    return FUN_009fa490(atom, in, baseA, baseB, info, out);
}

}
}   // namespace f3m_009fa490

// @f3 0x009f7fb0 (community match, verified in this file)
namespace f3m_009f7fb0 {
namespace f3m_009f7fb0 {

typedef float hkReal;

class hkMatrix3;

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v) { *this = v; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void add4(const hkVector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);
};

class hkMatrix3
{
public:
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline hkReal& operator()(int r, int c) { return getColumn(c)(r); }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

class hkRotation : public hkMatrix3 {};

class hkTransform
{
public:
    __forceinline hkVector4& getColumn(int i) { return m_rotation.getColumn(i); }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    __forceinline const hkRotation& getRotation() const { return m_rotation; }
    __forceinline hkVector4& getTranslation() { return m_translation; }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }
    hkRotation m_rotation;
    hkVector4 m_translation;
};

namespace hkVector4Util
{
    __forceinline void rotatePoints(const hkMatrix3& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
    {
        hkMatrix3 unaliased = t;
        int i = numVectors - 1;
        do
        {
            vectorsOut[i]._setMul3(unaliased, vectorsIn[i]);
        } while (--i >= 0);
    }
}

// pdb: setLocalTransform | hkpBuildJacobianFromAtoms.obj | fnv360_0721_beta, objopen_prop, low
static void FUN_009f7fb0(const hkTransform& a, const hkTransform& b, hkTransform& out)
{
    hkVector4Util::rotatePoints(a.getRotation(), &b.getColumn(0), 4, &out.getColumn(0));
    out.getTranslation().add4(a.getTranslation());
}

void hkSolverSetLocalTransformStandIn(const hkTransform& a, const hkTransform& b, hkTransform& out, hkTransform& out2)
{
    FUN_009f7fb0(a, b, out);
    FUN_009f7fb0(a, out, out2);
}

}
}   // namespace f3m_009f7fb0

// @f3 0x009f9eb0 (community match, verified in this file)
extern unsigned char DAT_00e817d9[];
extern unsigned char DAT_00e817da[];
namespace f3m_009f9eb0 {

namespace f3m_009f9eb0 {
namespace S009f9eb0_ns {

typedef float hkReal;
extern "C" hkReal __cdecl hkMath_atan2fApproximation(hkReal x, hkReal y);

class __declspec(align(16)) S009f9eb0_Vector4
{
public:
    hkReal x, y, z, w;
    __forceinline S009f9eb0_Vector4& operator=(const S009f9eb0_Vector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setCross(const S009f9eb0_Vector4& v1, const S009f9eb0_Vector4& v2)
    {
        const hkReal nx = v1.y * v2.z - v1.z * v2.y;
        const hkReal ny = v1.z * v2.x - v1.x * v2.z;
        const hkReal nz = v1.x * v2.y - v1.y * v2.x;
        set(nx, ny, nz, 0.0f);
    }
    __forceinline hkReal dot3(const S009f9eb0_Vector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
};

struct S009f9eb0_Rotation
{
    S009f9eb0_Vector4 m_col[3];
    __forceinline const S009f9eb0_Vector4& getColumn(int i) const { return m_col[i]; }
};

struct S009f9eb0_Atom
{
    unsigned short m_type;
    unsigned char m_isEnabled;
    unsigned char m_limitAxis;
    hkReal m_minAngle;
    hkReal m_maxAngle;
    hkReal m_angularLimitsTauFactor;
};

struct S009f9eb0_Body
{
    int unk00;
    hkReal f04;
};

struct S009f9eb0_QueryIn
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    hkReal m_tau;
    int unk44; int unk48;
    S009f9eb0_Body* m_body;
};

struct S009f9eb0_Info
{
    S009f9eb0_Vector4 m_constrainedDofW;
    hkReal m_min;
    hkReal m_max;
    hkReal m_computedAngle;
    hkReal m_tau;
};

// pdb: buildJacobianFromAngLimitAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun, medium
static __declspec(noinline) int FUN_009f9eb0(const S009f9eb0_Atom* pAtom, const S009f9eb0_QueryIn* pIn,
    const S009f9eb0_Rotation* pA, const S009f9eb0_Rotation* pB, S009f9eb0_Info* pInfo)
{
    const S009f9eb0_Atom& atom = *pAtom;
    const S009f9eb0_QueryIn& in = *pIn;
    const S009f9eb0_Rotation& baseA = *pA;
    const S009f9eb0_Rotation& baseB = *pB;
    S009f9eb0_Info& info = *pInfo;
    if (atom.m_isEnabled)
    {
        const int freeAxis = atom.m_limitAxis;
        const int perpAxis = DAT_00e817d9[freeAxis];
        const int otherAxis = DAT_00e817da[freeAxis];
        info.m_tau = in.m_tau * atom.m_angularLimitsTauFactor;
        info.m_constrainedDofW = baseA.getColumn(freeAxis);
        S009f9eb0_Vector4 W; W = *(const S009f9eb0_Vector4*)((const char*)&baseA + perpAxis);
        S009f9eb0_Vector4 U; U = *(const S009f9eb0_Vector4*)((const char*)&baseB + otherAxis);
        S009f9eb0_Vector4 V; V = baseB.getColumn(freeAxis);
        info.m_min = atom.m_minAngle;
        info.m_max = atom.m_maxAngle;
        S009f9eb0_Vector4 C;
        C.setCross(U, V);
        info.m_computedAngle = hkMath_atan2fApproximation(U.dot3(W), C.dot3(W));
        float n = in.m_body->f04 * -1.0;
        const double kPi = 3.14159265358979323846f;
        const double kTwo = 6.28318530717958647692f;
        while (n - info.m_computedAngle > kPi)
            info.m_computedAngle = (float)(info.m_computedAngle + kTwo);
        while (info.m_computedAngle - n > kPi)
            info.m_computedAngle = (float)(info.m_computedAngle - kTwo);
        return 0;
    }
    return 1;
}

const S009f9eb0_Atom* volatile g_atom9eb0;
const S009f9eb0_QueryIn* volatile g_in9eb0;
const S009f9eb0_Rotation* volatile g_rot9eb0;
S009f9eb0_Info* volatile g_info9eb0;
volatile int g_out9eb0;
void S009f9eb0_caller()
{
    g_out9eb0 = FUN_009f9eb0(g_atom9eb0, g_in9eb0, g_rot9eb0, g_rot9eb0, g_info9eb0);
}
}
}
}   // namespace f3m_009f9eb0

// @f3 0x009eb8c0 (community match, verified in this file)
#include <math.h>
extern unsigned long DAT_010f3170;
namespace f3m_009eb8c0 {


namespace f3m_009eb8c0 {

__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

struct __declspec(align(16)) hkVector4 {
    float x, y, z, w;
    void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    void sub4(const hkVector4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; }
    float& operator()(int i) { return (&x)[i]; }
    void setAbs4(const hkVector4& v)
    {
        x = fabs(v.x);
        y = fabs(v.y);
        z = fabs(v.z);
        w = fabs(v.w);
    }
    void mul4(float s) { x *= s; y *= s; z *= s; w *= s; }
    float dot3(const hkVector4& v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSquared3() const { return x * x + y * y + z * z; }
    void setCross(const hkVector4& a, const hkVector4& b)
    {
        x = a.y * b.z - a.z * b.y;
        y = a.z * b.x - a.x * b.z;
        z = a.x * b.y - a.y * b.x;
        w = 0.0f;
    }
    __forceinline void normalize3()
    {
        float lenSq = lengthSquared3();
        float inv;
        if (lenSq != 0.0f) {
            float len = (float)sqrt(lenSq);
            inv = 1.0f / len;
        } else {
            inv = 0.0f;
        }
        mul4(inv);
    }
    void hkVector4_setRotatedDir(const struct hkRotation& r, const hkVector4& v);
    void hkVector4_setTransformedPos(const struct hkTransform& t, const hkVector4& v);
};

struct hkRotation {
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkRotation() {}
    hkRotation(const hkRotation& r) { m_col0 = r.m_col0; m_col1 = r.m_col1; m_col2 = r.m_col2; }
    void operator=(const hkRotation& r) { m_col0 = r.m_col0; m_col1 = r.m_col1; m_col2 = r.m_col2; }
    void FUN_0096c8f0(float eps);
    void setIdentity()
    {
        m_col0.y = 0.0f; m_col0.z = 0.0f; m_col0.w = 0.0f;
        m_col1.x = 0.0f; m_col1.z = 0.0f; m_col1.w = 0.0f;
        m_col2.x = 0.0f; m_col2.y = 0.0f; m_col2.w = 0.0f;
        m_col0.x = 1.0f; m_col1.y = 1.0f; m_col2.z = 1.0f;
    }
};

struct hkTransform {
    hkRotation m_rotation;
    hkVector4 m_translation;
    hkTransform(const hkRotation& r, const hkVector4& t) : m_rotation(r), m_translation(t) {}
    void hkTransform_setInverse(const hkTransform& t);
};

struct hkStridedVertices {
    const float* m_vertices;
    int m_numVertices;
    int m_striding;
};

struct hkThreadMemory {
    void* FUN_008f6d30(int size, int cls);
    void FUN_008f6d90(void* p, int size, int cls);
    static hkThreadMemory& getInstance() { return *(hkThreadMemory*)FUN_00d9b080(DAT_010f3170); }
};

void __cdecl FUN_00901f10(void* arr, int elemSize);

struct hkVecArray {
    hkVector4* m_data;
    int m_size;
    int m_capacityAndFlags;
    hkVecArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    ~hkVecArray()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int n = m_capacityAndFlags & 0x3fffffff;
            hkThreadMemory& mem = hkThreadMemory::getInstance();
            mem.FUN_008f6d90(m_data, n * 16, 0x17);
        }
    }
    void pushBack(const hkVector4& v)
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, 16);
        m_data[m_size++] = v;
    }
};

hkVector4 __cdecl FUN_009eb6d0(const hkStridedVertices& sv, float eps);

static __declspec(noinline) bool FUN_009e8bc0(const float& a, const float& b, float eps)
{
    float d = fabs(a - b);
    return d < eps;
}

static __declspec(noinline) bool FUN_009e9300(const hkVector4& v, float tol)
{
    hkVector4 a;
    a.x = fabs(v.x);
    a.y = fabs(v.y);
    a.z = fabs(v.z);
    float m = a.x > a.y ? a.x : a.y;
    m = m > a.z ? m : a.z;
    m = fabs(m - 1.0f);
    return m < tol;
}

struct hkLocalVecBuffer {
    hkVector4* m_data;
    int m_size;
    hkLocalVecBuffer(int n) : m_size(n)
    {
        m_data = (hkVector4*)hkThreadMemory::getInstance().FUN_008f6d30(n * 16, 0x17);
    }
    ~hkLocalVecBuffer() { hkThreadMemory::getInstance().FUN_008f6d90(m_data, m_size * 16, 0x17); }
    hkVector4& operator[](int i) { return m_data[i]; }
};

// pdb: getIsBoxGeometry | hkGeometryUtility.obj | tesv_win, uconst, low
bool FUN_009eb8c0(const hkVecArray& points, hkVector4& halfExtents, hkTransform& out, float tolerance)
{
    hkVector4 sphere;
    {
        hkStridedVertices sv;
        const float* verts = (const float*)points.m_data;
        int num = points.m_size;
        sv.m_numVertices = num;
        sv.m_striding = 16;
        sv.m_vertices = verts;
        sphere = FUN_009eb6d0(sv, 1e-5f);
    }

    hkLocalVecBuffer buf(8);

    hkVecArray onSphere;
    int n = points.m_size;
    for (int i = 0; i < n; i++) {
        hkVector4 d;
        d.x = points.m_data[i].x - sphere.x;
        d.y = points.m_data[i].y - sphere.y;
        d.z = points.m_data[i].z - sphere.z;
        float dy = d.y;
        float dx = d.x;
        float dz = d.z;
        float len = dx * dx + dy * dy + dz * dz;
        len = (float)sqrt(len);
        len = len - sphere.w;
        len = fabs(len);
        if (len < tolerance)
            onSphere.pushBack(points.m_data[i]);
    }
    if (onSphere.m_size != 8) {
        return false;
    }

    for (int i = 0; i < 8; i++)
        buf[i] = onSphere.m_data[i];

    hkVector4 e1 = buf[0];
    hkVector4 v1 = buf[1];
    e1.sub4(v1);
    hkVector4 e2 = buf[0];
    hkVector4 v2 = buf[2];
    e2.sub4(v2);
    int k = 3;
    do {
        hkVector4 t = buf[0];
        t.sub4(buf[k]);
        float lt = t.lengthSquared3();
        float l1 = e1.lengthSquared3();
        if (lt < l1) {
            float l2 = e2.lengthSquared3();
            if (l1 < l2)
                e2 = e1;
            e1 = t;
        } else {
            float l2 = e2.lengthSquared3();
            if (lt < l2)
                e2 = t;
        }
    } while (++k < 8);

    float dot = e1.dot3(e2);
    if (dot > 1e-5f) {
        return false;
    }

    hkVector4 e3;
    e3.setCross(e1, e2);
    e1.normalize3();
    e2.normalize3();
    e3.normalize3();

    hkRotation rot;
    rot.m_col0 = e1;
    rot.m_col1 = e2;
    rot.m_col2 = e3;
    rot.FUN_0096c8f0(0.01f);

    for (int i = 0; i < 8; i++)
        buf[i].hkVector4_setRotatedDir(rot, buf[i]);

    float minX;
    float maxX;
    float minY;
    float maxY;
    float minZ;
    float maxZ;
    minX = buf[0].x;
    maxX = buf[0].x;
    minY = buf[0].y;
    maxY = buf[0].y;
    minZ = buf[0].z;
    maxZ = buf[0].z;
    for (int i = 1; i < 8; i++) {
        if (minX > buf[i].x)
            minX = buf[i].x;
        else if (maxX < buf[i].x)
            maxX = buf[i].x;
        if (minY > buf[i].y)
            minY = buf[i].y;
        else if (maxY < buf[i].y)
            maxY = buf[i].y;
        if (minZ > buf[i].z)
            minZ = buf[i].z;
        else if (maxZ < buf[i].z)
            maxZ = buf[i].z;
    }

    for (int i = 0; i < 8; i++) {
        if ((!FUN_009e8bc0(buf[i].x, minX, 0.001f) && !FUN_009e8bc0(buf[i].x, maxX, 0.001f))
            || (!FUN_009e8bc0(buf[i].y, minY, 0.001f) && !FUN_009e8bc0(buf[i].y, maxY, 0.001f))
            || (!FUN_009e8bc0(buf[i].z, minZ, 0.001f) && !FUN_009e8bc0(buf[i].z, maxZ, 0.001f))) {
            return false;
        }
    }

    halfExtents(0) = maxX - minX;
    halfExtents(1) = maxY - minY;
    halfExtents(2) = maxZ - minZ;
    halfExtents.mul4(0.5f);
    hkVector4 center;
    center.x = (minX + maxX) * 0.5f;
    center.y = (minY + maxY) * 0.5f;
    center.z = (minZ + maxZ) * 0.5f;
    center.w = 0.0f;
    center.mul4(-1.0f);

    hkTransform T(rot, center);
    out.hkTransform_setInverse(T);

    if (FUN_009e9300(rot.m_col0, tolerance) && FUN_009e9300(rot.m_col1, tolerance)
        && FUN_009e9300(rot.m_col2, tolerance)) {
        halfExtents.hkVector4_setRotatedDir(out.m_rotation, halfExtents);
        halfExtents(3) = 0.0f;
        halfExtents.setAbs4(halfExtents);
        rot.setIdentity();
        out.m_rotation = rot;
    }
    T.hkTransform_setInverse(out);

    for (int i = 0; i < points.m_size; i++) {
        hkVector4 t;
        t.hkVector4_setTransformedPos(T, points.m_data[i]);
        for (int k = 0; k < 3; k++) {
            if (fabs((&t.x)[k]) > (&halfExtents.x)[k] * 1.001f) {
                    return false;
            }
        }
    }

    return true;
}

}
}   // namespace f3m_009eb8c0
