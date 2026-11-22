// src/f3staging/f3blk_00960000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x009604c0 (community match, verified in this file)
#include <math.h>
namespace f3m_009604c0 {
// hkRemoveTwist (Havok 5.5.0, hkaRagdoll hkaPoseMatchingUtility.cpp): a file-local function, so /O2 gives it
// a register calling convention (edi = twistAxis, esi = rotation). Layouts and inlines follow the Havok 5.5
// headers (FPU build, HK_DISABLE_VECTOR4_CONSTRUCTORS: hkVector4 has no constructors, operator= copies floats).

namespace f3h_009604c0 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

namespace hkMath
{
    inline hkReal sqrt(hkReal r) { return sqrtf(r); }
    inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
    inline hkReal fabs(hkReal r) { return fabsf(r); }
}

class hkQuaternion;

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

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
    __forceinline void setZero4() { x = y = z = w = 0; }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }
    __forceinline void mul4(hkSimdRealParameter rs)
    {
        hkReal s = hkReal(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        hkReal r = hkReal(rs);
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        hkReal r = hkReal(rs);
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setNeg3(const hkVector4& v) { x = -v.x; y = -v.y; z = -v.z; w = v.w; }
    __forceinline void setAbs4(const hkVector4& v)
    {
        x = hkMath::fabs(v.x);
        y = hkMath::fabs(v.y);
        z = hkMath::fabs(v.z);
        w = hkMath::fabs(v.w);
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }
    __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline hkSimdReal lengthInverse3() const
    {
        hkReal l2 = (x * x) + (y * y) + (z * z);
        return l2 ? hkMath::sqrtInverse(l2) : 0;
    }
    __forceinline void normalize3() { this->mul4(this->lengthInverse3()); }
    __forceinline int getMajorAxis() const
    {
        hkVector4 tmp;
        tmp.setAbs4(*this);
        return tmp(0) < tmp(1) ? (tmp(1) < tmp(2) ? 2 : 1) : (tmp(0) < tmp(2) ? 2 : 0);
    }
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

class hkMatrix3
{
public:
    __forceinline hkMatrix3() {}
    __forceinline void setCols(const hkVector4& r0, const hkVector4& r1, const hkVector4& r2)
    {
        m_col0 = r0;
        m_col1 = r1;
        m_col2 = r2;
    }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

class hkRotation : public hkMatrix3
{
};

class hkQuaternion
{
public:
    inline hkQuaternion() {}
    inline void operator=(const hkQuaternion& q) { m_vec = q.m_vec; }
    __forceinline const hkVector4& getImag() const { return m_vec; }
    inline void setInverse(const hkQuaternion& q) { m_vec.setNeg3(q.getImag()); }
    void set(const hkRotation& r);                              // out of line in hkQuaternion.cpp
    inline hkReal getReal() const { return m_vec(3); }
    inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1); // the compiler calls it, not inlined

    hkVector4 m_vec;
};

inline void hkQuaternion::setMul(const hkQuaternion& q0, const hkQuaternion& q1)
{
    hkVector4 vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0.m_vec(3), q1.getImag());
    vec.addMul4(q1.m_vec(3), q0.getImag());
    hkReal real = q0.getReal() * q1.getReal() - hkReal(q0.m_vec.dot3(q1.m_vec));
    m_vec = vec;
    m_vec(3) = real;
}

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// Rotates 'rotation' so that it no longer twists about twistAxis.
// pdb: hkRemoveTwist | hkaPoseMatchingUtility.obj | tesv_win, call_seq, medium
static void FUN_009604c0(const hkVector4& twistAxis, hkQuaternion& rotation)
{
    hkVector4 perp;
    perp.setZero4();
    perp((twistAxis.getMajorAxis() + 1) % 3) = 1.0f;
    perp.setRotatedDir(rotation, perp);
    hkVector4 c;
    c.setCross(perp, twistAxis);
    c.normalize3();
    perp.setCross(twistAxis, c);
    hkRotation r;
    r.setCols(perp, twistAxis, c);
    hkQuaternion q;
    q.set(r);
    hkQuaternion conj;
    conj.setInverse(q);
    hkQuaternion res;
    res.setMul(conj, rotation);
    rotation = res;
}

// Callers in the same file (the real ones are the hkaPoseMatchingUtility pose functions).
void hkRemoveTwistCallerStandIn(const hkVector4& a, hkQuaternion& q) { FUN_009604c0(a, q); }
void hkRemoveTwistCallerStandIn2(const hkVector4* a, hkQuaternion* q) { FUN_009604c0(a[1], q[2]); }

} // namespace f3h_009604c0
}   // namespace f3m_009604c0
