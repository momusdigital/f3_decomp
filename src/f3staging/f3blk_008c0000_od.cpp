// src/f3staging/f3blk_008c0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008d2b00 (community match, verified in this file)
namespace f3m_008d2b00 {
namespace f3m_008d2b00 {

typedef float hkReal;

struct hkQuaternion;
struct hkQsTransform;

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    hkReal& operator()(int i) { return m_quad[i]; }
    const hkReal& operator()(int i) const { return m_quad[i]; }

    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w)
    {
        m_quad[0] = x;
        m_quad[1] = y;
        m_quad[2] = z;
        m_quad[3] = w;
    }
    __forceinline void setMul4(hkReal r, const hkVector4& v)
    { m_quad[0] = r * v.m_quad[0]; m_quad[1] = r * v.m_quad[1]; m_quad[2] = r * v.m_quad[2]; m_quad[3] = r * v.m_quad[3]; }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_quad[0] = a.m_quad[0] * b.m_quad[0];
        m_quad[1] = a.m_quad[1] * b.m_quad[1];
        m_quad[2] = a.m_quad[2] * b.m_quad[2];
        m_quad[3] = a.m_quad[3] * b.m_quad[3];
    }
    __forceinline void addMul4(hkReal r, const hkVector4& v)
    { m_quad[0] += r * v.m_quad[0]; m_quad[1] += r * v.m_quad[1]; m_quad[2] += r * v.m_quad[2]; m_quad[3] += r * v.m_quad[3]; }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        for (int i = 0; i < 4; i++) m_quad[i] = a.m_quad[i] + b.m_quad[i];
    }
    __forceinline hkReal dot3(const hkVector4& v) const
    { return (m_quad[0] * v.m_quad[0]) + (m_quad[1] * v.m_quad[1]) + (m_quad[2] * v.m_quad[2]); }
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    { const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1); const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2); const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0); set(nx, ny, nz, 0.0f); }
    void FUN_008d2b00(const hkQsTransform& a, const hkVector4& b);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    hkReal getReal() const { return m_vec.m_quad[3]; }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkVector4 ret;
    ret.setMul4(qreal * qreal - 0.5f, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;
};

// pdb: hkVector4::setTransformedPos | hkVector4.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: hkaSkeletonUtils::getBoneChain)
// pdb params: t, v
void hkVector4::FUN_008d2b00(const hkQsTransform& a, const hkVector4& b)
{
    hkVector4 scaled;
    scaled.setMul4(a.m_scale, b);
    hkVector4 rotated;
    rotated.setRotatedDir(a.m_rotation, scaled);
    setAdd4(a.m_translation, rotated);
}

}
}   // namespace f3m_008d2b00
