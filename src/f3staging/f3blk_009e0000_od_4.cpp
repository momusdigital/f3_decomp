// src/f3staging/f3blk_009e0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x009e97e0 (community match, verified in this file)
#include <math.h>
namespace f3m_009e97e0 {
// getVolumeFromAxes (Havok 5.5.0, hkpInternal hkpGeometryUtility.cpp): a file-local function, so /O2 gives it a
// register calling convention (esi = axes). It calls makeOBBUsingAxes (FUN_009e93b0), also file-local, whose
// register convention (eax = vertices, ecx = axes, edi = center) comes from its body, so that body is here too.
// Layouts and inlines follow the Havok 5.5 headers (FPU build, HK_DISABLE_VECTOR4_CONSTRUCTORS).

namespace f3h_009e97e0 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned long hkUlong;

static const hkReal HK_REAL_MAX = 3.40282e+38f; // hkFpuMathFuncs.inl: a little under FLT_MAX

namespace hkMath
{
    inline hkReal sqrt(hkReal r) { return sqrtf(r); }
    inline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

template <typename TYPE>
__forceinline const TYPE* hkAddByteOffsetConst(const TYPE* base, hkUlong offset)
{
    return reinterpret_cast<const TYPE*>(reinterpret_cast<const char*>(base) + offset);
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

    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0) { x = a; y = b; z = c; w = d; }
    __forceinline void setAll3(hkReal a) { x = a; y = a; z = a; w = a; }
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
    __forceinline void subMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        hkReal r = hkReal(rs);
        x -= r * a.x;
        y -= r * a.y;
        z -= r * a.z;
        w -= r * a.w;
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
};

// makeOBBUsingAxes: the extents of the vertices along three axes (min/max of the projections), as half extents
// and a center. Its own bytes are not the target here; it fixes the call convention used by FUN_009e97e0.
static void FUN_009e93b0(const float* vertices, int numVertices, int striding, hkVector4& halfExtents,
                         const hkVector4* axes, hkVector4& center)
{
    hkVector4 minv;
    minv.setAll3(HK_REAL_MAX);
    hkVector4 maxv;
    maxv.setAll3(-HK_REAL_MAX);
    for (int i = 0; i < numVertices / 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            hkVector4 v;
            v.set(vertices[0], vertices[1], vertices[2]);
            vertices = hkAddByteOffsetConst(vertices, striding);
            {
                hkReal d = axes[0].dot3(v);
                if (d < minv(0)) minv(0) = d;
                if (d > maxv(0)) maxv(0) = d;
            }
            {
                hkReal d = axes[1].dot3(v);
                if (d < minv(1)) minv(1) = d;
                if (d > maxv(1)) maxv(1) = d;
            }
            {
                hkReal d = axes[2].dot3(v);
                if (d < minv(2)) minv(2) = d;
                if (d > maxv(2)) maxv(2) = d;
            }
        }
    }
    hkVector4 mid;
    mid.setAdd4(minv, maxv);
    mid.mul4(0.5f);
    halfExtents.setSub4(maxv, minv);
    halfExtents.mul4(0.5f);
    center.setMul4(mid(0), axes[0]);
    center.addMul4(mid(1), axes[1]);
    center.addMul4(mid(2), axes[2]);
}

// The volume of the box around the vertices, with the axes made orthonormal first.
// pdb: getVolumeFromAxes | hkGeometryUtility.obj | tesv_win, objrun_prop, low
static hkReal FUN_009e97e0(const float* vertices, int numVertices, int striding, const hkVector4* axesIn)
{
    hkVector4 axes[3];
    axes[0] = axesIn[0];
    axes[1] = axesIn[1];
    axes[0].normalize3();
    axes[1].subMul4(axesIn[1].dot3(axesIn[0]), axesIn[0]);
    axes[1].normalize3();
    axes[2].setCross(axesIn[0], axesIn[1]);
    axes[2].normalize3();
    hkVector4 halfExtents;
    hkVector4 center;
    FUN_009e93b0(vertices, numVertices, striding, halfExtents, axes, center);
    return halfExtents(0) * halfExtents(1) * halfExtents(2);
}

// Callers in the same file (the real ones are the steepest-descent OBB fitting functions).
float getVolumeFromAxesCallerStandIn(const float* v, int n, int s, const hkVector4* a)
{
    return FUN_009e97e0(v, n, s, a) + FUN_009e97e0(v, n, s, a + 3);
}

} // namespace f3h_009e97e0
}   // namespace f3m_009e97e0
