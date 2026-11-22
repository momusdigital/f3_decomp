// src/f3staging/f3blk_00940000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00950780 (community match, verified in this file)
extern int DAT_01169240;
extern const char DAT_00df71b0[];
extern const char DAT_00e7b7cc[];
extern const char DAT_00e7b7c8[];
extern float DAT_00f7a690;
namespace f3m_00950780 {
unsigned FUN_00847b50(int);
unsigned FUN_00847dd0(const char*, float);

struct V3 {
    float x, y, z;
    unsigned FUN_00823dc0(const char*);
};

struct Arr {
    unsigned short unk0;
    unsigned short unk2;
    unsigned short unk4;
    unsigned short unk6;
    unsigned short cap;
    unsigned short count;
    unsigned short unkc;
    unsigned short grow;
    void FUN_00555790(unsigned);
    void FUN_005b3880(unsigned, unsigned*);
    void Push(unsigned& v) {
        unsigned idx = count;
        if (idx >= cap) FUN_00555790(grow + idx);
        FUN_005b3880(idx, &v);
    }
};

struct __declspec(align(16)) Desc {
    int unk0;
    float f4;
    float unk8, unkc;
    float ax, ay, az, aw;
    float bx, by, bz, bw;
    float unk20;
};

struct Owner {
    void FUN_0090c5a0(Arr*);
    void bhkCylinderShape_CopyCinfo(Desc*);
    void FUN_00950780(Arr* a);
};

// pdb: bhkCylinderShape::GetViewerStrings | bhkCylinderShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apStrings
void Owner::FUN_00950780(Arr* a)
{
    unsigned val;
    FUN_0090c5a0(a);
    val = FUN_00847b50(DAT_01169240);
    a->Push(val);
    Desc d;
    d.f4 = DAT_00f7a690;
    d.unk20 = 0.0f;
    d.ax = 0.0f;
    d.unk0 = 0;
    d.ay = 0.0f;
    d.az = 0.0f;
    d.aw = 0.0f;
    d.bx = 1.0f;
    d.by = 0.0f;
    d.bz = 0.0f;
    d.bw = 0.0f;
    bhkCylinderShape_CopyCinfo(&d);
    val = FUN_00847dd0(DAT_00df71b0, d.unk20);
    a->Push(val);
    V3 v = { d.ax, d.ay, d.az };
    val = v.FUN_00823dc0(DAT_00e7b7cc);
    a->Push(val);
    v.x = d.bx; v.y = d.by; v.z = d.bz;
    val = v.FUN_00823dc0(DAT_00e7b7c8);
    a->Push(val);
}
}   // namespace f3m_00950780

// @f3 0x00957110 (community match, verified in this file)
#include <math.h>
namespace f3m_00957110 {
namespace f3m_00957110 {

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal sqrt(const hkReal r) { return ::sqrtf(r); }
    __forceinline hkReal sqrtInverse(const hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    __forceinline void operator=(const hkVector4& v)
    {
        m_quad[0] = v.m_quad[0];
        m_quad[1] = v.m_quad[1];
        m_quad[2] = v.m_quad[2];
        m_quad[3] = v.m_quad[3];
    }

    hkReal& operator()(int i) { return m_quad[i]; }
    const hkReal& operator()(int i) const { return m_quad[i]; }

    __forceinline hkReal dot3(const hkVector4& v) const
    {
        return m_quad[0] * v.m_quad[0] + m_quad[1] * v.m_quad[1] + m_quad[2] * v.m_quad[2];
    }
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w)
    {
        m_quad[0] = x;
        m_quad[1] = y;
        m_quad[2] = z;
        m_quad[3] = w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0.0f);
    }
    __forceinline void mul4(hkReal s)
    {
        m_quad[0] *= s;
        m_quad[1] *= s;
        m_quad[2] *= s;
        m_quad[3] *= s;
    }
    __forceinline hkReal dot4(const hkVector4& v) const
    {
        return m_quad[0] * v.m_quad[0] + m_quad[1] * v.m_quad[1] + m_quad[2] * v.m_quad[2] + m_quad[3] * v.m_quad[3];
    }
    __forceinline hkReal lengthSquared4() const
    {
        return this->dot4(*this);
    }
    __forceinline hkReal lengthInverse4() const
    {
        const hkReal l2 = lengthSquared4();
        return (l2 != 0.0f) ? hkMath::sqrtInverse(l2) : 0.0f;
    }
    __forceinline void normalize4()
    {
        mul4(lengthInverse4());
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline void setIdentity()
    {
        m_vec.m_quad[0] = 0.0f;
        m_vec.m_quad[1] = 0.0f;
        m_vec.m_quad[2] = 0.0f;
        m_vec.m_quad[3] = 1.0f;
    }
    void setFlippedRotation(const hkVector4& from);
    void FUN_00957110(hkReal gain, const hkVector4& from, const hkVector4& to);
};

void hkQuaternion::FUN_00957110(hkReal gain, const hkVector4& from, const hkVector4& to)
{
    const hkReal fx = from(0), tz = to(2);
    const hkReal dotProd = fx * to(0) + from(1) * to(1) + from(2) * tz;
    const hkReal dampedDot = 1.0f - gain + gain * dotProd;
    const hkReal nearlyOne = 1.0f - 1e-6f;

    const hkReal c = (dampedDot + 1.0f) * 0.5f;
    if ((c <= 0.0f) || (dotProd < -nearlyOne))
    {
        setFlippedRotation(from);
    }
    else
    {
        if (dotProd > nearlyOne)
        {
            setIdentity();
        }
        else
        {
            const hkReal cosT2 = hkMath::sqrt(c);

            hkVector4 cross;
            cross.setCross(from, to);

            const hkReal rescaleSin = gain * 0.5f / cosT2;
            cross.mul4(rescaleSin);
            cross(3) = cosT2;

            cross.normalize4();
            m_vec = cross;
        }
    }
}

}
}   // namespace f3m_00957110

// @f3 0x009582b0 (community match, verified in this file)
namespace f3m_009582b0 {
namespace f3m_009582b0 {

typedef float hkReal;

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
    __forceinline void setRotatedDir(const struct hkQuaternion& quat, const hkVector4& direction);
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    { const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1); const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2); const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0); set(nx, ny, nz, 0.0f); }
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    hkReal getReal() const { return m_vec.m_quad[3]; }
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1);
};

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

struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        hkVector4 extraTrans;
        extraTrans.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(t1.m_translation, extraTrans);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);
        m_scale.setMul4(t1.m_scale, t2.m_scale);
    }
};

}

// pdb: hkaSkeletonUtils::transformLocalPoseToWorldPose | hkaSkeletonUtils.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void hkaSkeletonUtils_transformLocalPoseToWorldPose(int numTransforms, const short* parentIndices, const f3m_009582b0::hkQsTransform& worldFromModel,
                  const f3m_009582b0::hkQsTransform* poseLocal, f3m_009582b0::hkQsTransform* poseModelOut)
{
    using namespace f3m_009582b0;
    for (int i = 0; i < numTransforms; i++)
    {
        const int parentId = parentIndices[i];
        const hkQsTransform& worldFromParent = (parentId != -1) ? poseModelOut[parentId] : worldFromModel;
        poseModelOut[i].setMul(worldFromParent, poseLocal[i]);
    }
}
}   // namespace f3m_009582b0

// @f3 0x0095b800 (community match, verified in this file)
namespace f3m_0095b800 {
namespace f3m_0095b800 {

typedef float hkReal;

namespace hkMath
{
    __forceinline hkReal sqrt(const hkReal r) { return ::sqrtf(r); }
}

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    __forceinline void operator=(const hkVector4& v)
    {
        m_quad[0] = v.m_quad[0];
        m_quad[1] = v.m_quad[1];
        m_quad[2] = v.m_quad[2];
        m_quad[3] = v.m_quad[3];
    }

    hkReal& operator()(int i) { return m_quad[i]; }
    const hkReal& operator()(int i) const { return m_quad[i]; }

    __forceinline hkReal dot3(const hkVector4& v) const
    {
        return m_quad[0] * v.m_quad[0] + m_quad[1] * v.m_quad[1] + m_quad[2] * v.m_quad[2];
    }
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w)
    {
        m_quad[0] = x;
        m_quad[1] = y;
        m_quad[2] = z;
        m_quad[3] = w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0.0f);
    }
    __forceinline void mul4(hkReal s)
    {
        m_quad[0] *= s;
        m_quad[1] *= s;
        m_quad[2] *= s;
        m_quad[3] *= s;
    }
    __forceinline hkReal length3() const
    {
        return hkMath::sqrt(hkReal((double)m_quad[0] * m_quad[0] + (double)m_quad[1] * m_quad[1] + (double)m_quad[2] * m_quad[2]));
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline void setIdentity()
    {
        m_vec.m_quad[0] = 0.0f;
        m_vec.m_quad[1] = 0.0f;
        m_vec.m_quad[2] = 0.0f;
        m_vec.m_quad[3] = 1.0f;
    }
    void setFlippedRotation(const hkVector4& from);
    void FUN_0095b800(const hkVector4& from, const hkVector4& to);
};

// pdb: hkQuaternion::setShortestRotation | bhkCartTether.obj | tesv_win, call_dedup, low
void hkQuaternion::FUN_0095b800(const hkVector4& from, const hkVector4& to)
{
    const hkReal fx = from(0), tz = to(2);
    const hkReal dotProd = fx * to(0) + from(1) * to(1) + from(2) * tz;
    const hkReal nearlyOne = 1.0f - 1e-5f;
    const hkReal somewhatNearlyMinusOne = -(1.0f - 1e-3f);
    if (dotProd > nearlyOne)
    {
        setIdentity();
    }
    else if (dotProd < -nearlyOne)
    {
        setFlippedRotation(from);
    }
    else
    {
        const hkReal c = hkMath::sqrt((dotProd + 1.0f) * 0.5f);
        const hkReal cosT2 = c;
        hkVector4 cross;
        cross.setCross(from, to);
        hkReal rescaleSin = 0.5f / cosT2;
        if (dotProd < somewhatNearlyMinusOne)
        {
            const hkReal sinT2 = hkMath::sqrt(cosT2 * cosT2 - dotProd);
            const hkReal approxSinTheta = 2.0f * sinT2 * cosT2;
            const hkReal lenCross = cross.length3();
            rescaleSin *= (approxSinTheta / lenCross);
        }
        cross.mul4(rescaleSin);
        cross(3) = cosT2;
        m_vec = cross;
    }
}

}
}   // namespace f3m_0095b800

// @f3 0x0095e7a0 (community match, verified in this file)
#include <math.h>

namespace f3m_0095e7a0 {

typedef float hkReal;

__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

struct S0095e7a0_Heap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
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
    void* freeList40;
    int freeCount44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    void* freeList58;
    int freeCount5c;
    void* FUN_008f6800(int a, int b);
    void* FUN_008f6f60(int bytes, int tag);
};

extern unsigned long DAT_010f3170;

static inline S0095e7a0_Heap* S0095e7a0_GetHeap()
{
    return (S0095e7a0_Heap*)FUN_00d9b080(DAT_010f3170);
}

extern const char DAT_00e365d4[];
extern const char DAT_00e7c1a8[];

struct hkQuaternion;

struct __declspec(align(16)) hkVector4
{
    hkReal m_quad[4];

    hkVector4& operator=(const hkVector4& v)
    {
        m_quad[0] = v.m_quad[0];
        m_quad[1] = v.m_quad[1];
        m_quad[2] = v.m_quad[2];
        m_quad[3] = v.m_quad[3];
        return *this;
    }

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
    {
        m_quad[0] = r * v.m_quad[0];
        m_quad[1] = r * v.m_quad[1];
        m_quad[2] = r * v(2);
        m_quad[3] = r * v.m_quad[3];
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_quad[0] = a.m_quad[0] * b.m_quad[0];
        m_quad[1] = a.m_quad[1] * b.m_quad[1];
        m_quad[2] = a.m_quad[2] * b.m_quad[2];
        m_quad[3] = a.m_quad[3] * b.m_quad[3];
    }
    __forceinline void addMul4(hkReal r, const hkVector4& v)
    {
        m_quad[0] += r * v.m_quad[0];
        m_quad[1] += r * v.m_quad[1];
        m_quad[2] += r * v.m_quad[2];
        m_quad[3] += r * v.m_quad[3];
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        for (int i = 0; i < 4; i++) m_quad[i] = a.m_quad[i] + b.m_quad[i];
    }
    __forceinline hkReal dot3(const hkVector4& v) const
    {
        return m_quad[0] * v.m_quad[0] + m_quad[1] * v.m_quad[1] + m_quad[2] * v.m_quad[2];
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0.0f);
    }
    void setRotatedInvDir(const hkQuaternion& quat, const hkVector4& direction);
    void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    void FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1);
};

// this = rotated by the inverse of quat (rotate-by-conjugate form)
__forceinline void hkVector4::setRotatedInvDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(direction, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// this = rotated by quat (rotate form)
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

struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;

    void FUN_009643d0(const hkQsTransform& src);

    __forceinline void setConjugate(const hkQsTransform& t)
    {
        m_translation.setRotatedInvDir(t.m_rotation, t.m_translation);
        m_translation.m_quad[0] = -m_translation.m_quad[0];
        m_translation.m_quad[1] = -m_translation.m_quad[1];
        m_translation.m_quad[2] = -m_translation.m_quad[2];
        m_translation.m_quad[3] = -m_translation.m_quad[3];
        m_rotation.m_vec(0) = -t.m_rotation.m_vec(0);
        m_rotation.m_vec(1) = -t.m_rotation.m_vec(1);
        m_rotation.m_vec(2) = -t.m_rotation.m_vec(2);
        m_rotation.m_vec(3) = t.m_rotation.m_vec(3);
        hkVector4 invScale;
        invScale(0) = 1.0f / t.m_scale(0);
        invScale(1) = 1.0f / t.m_scale(1);
        invScale(2) = 1.0f / t.m_scale(2);
        m_scale.set(invScale(0), invScale(1), invScale(2), 0.0f);
    }

    __forceinline void setMul(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        hkVector4 extraTrans;
        extraTrans.setRotatedDir(t1.m_rotation, t2.m_translation);
        m_translation.setAdd4(extraTrans, t1.m_translation);
        m_rotation.FUN_008d3290(t1.m_rotation, t2.m_rotation);
        m_scale.setMul4(t2.m_scale, t1.m_scale);
    }
};

// hkQuaternion::setMul (q0 * q1), defined in this file: the compiler sees that it writes only *this
__declspec(noinline) void hkQuaternion::FUN_008d3290(const hkQuaternion& q0, const hkQuaternion& q1)
{
    hkVector4 vec;
    vec.setCross(q0.getImag(), q1.getImag());
    const hkReal q0Real = q0.m_vec(3);
    vec.addMul4(q0Real, q1.getImag());
    const hkReal q1Real = q1.m_vec(3);
    vec.addMul4(q1Real, q0.getImag());
    hkReal w = q0Real * q1Real - q0.getImag().dot3(q1.getImag());
    m_vec = vec;
    m_vec(3) = w;
}

struct S0095e7a0_RigidBody
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
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
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    const char* name;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    hkQsTransform transform;
};

struct S0095e7a0_BodyList
{
    S0095e7a0_RigidBody** data;
    int size;
};

struct S0095e7a0_Constraint
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S0095e7a0_RigidBody* parent;
};

struct S0095e7a0_ConstraintList
{
    S0095e7a0_Constraint** data;
    int size;
};

struct S0095e7a0_Bone
{
    void* name;
    bool lockTranslation;

    static void* operator new(unsigned int)
    {
        S0095e7a0_Heap* h = S0095e7a0_GetHeap();
        void* p = h->freeList40;
        if (p != 0)
        {
            h->freeCount44--;
            h->freeList40 = *(void**)p;
            return p;
        }
        return h->FUN_008f6800(1, 0x3b);
    }
};

struct S0095e7a0_Logger
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Report(int level, int code, const char* msg, const char* file, int line);
};
extern S0095e7a0_Logger* DAT_010f3364;

struct S0095e7a0_ErrStream
{
    char* buffer;
    int capacity;
    int length;

    void FUN_00923070(char* buf, int size);
    void FUN_00943710(const char* s);
    void FUN_00943a60();
};

struct S0095e7a0_Skeleton
{
    void* name;
    short* parentsData;
    int parentsCount;
    S0095e7a0_Bone** bonesData;
    int bonesCount;
    hkQsTransform* poseData;
    int poseCount;
    int unk1c;
    int unk20;

    S0095e7a0_Skeleton()
    {
        name = 0;
        parentsData = 0;
        parentsCount = 0;
        bonesData = 0;
        bonesCount = 0;
        poseData = 0;
        poseCount = 0;
        unk1c = 0;
        unk20 = 0;
    }
    static void* operator new(unsigned int)
    {
        S0095e7a0_Heap* h = S0095e7a0_GetHeap();
        void* p = h->freeList58;
        if (p != 0)
        {
            h->freeCount5c--;
            h->freeList58 = *(void**)p;
            return p;
        }
        return h->FUN_008f6800(4, 0x3b);
    }
};

void* __cdecl FUN_00923640(const char* name);

// pdb: hkaRagdollUtils::constructSkeletonForRagdoll | hkaRagdollUtils.obj | fnv360_0822_retail, ustr_rel, medium
// pdb params: rigidBodies, constraints
S0095e7a0_Skeleton* __cdecl FUN_0095e7a0(S0095e7a0_BodyList* bodies, S0095e7a0_ConstraintList* constraints)
{
    S0095e7a0_Skeleton* S = new S0095e7a0_Skeleton;

    int n = bodies->size;
    S->bonesCount = n;
    S->bonesData = (S0095e7a0_Bone**)S0095e7a0_GetHeap()->FUN_008f6f60(n * 4, 0xd);
    S->parentsCount = n;
    S->parentsData = (short*)S0095e7a0_GetHeap()->FUN_008f6f60(n * 2, 0xd);
    S->poseCount = n;
    S->poseData = (hkQsTransform*)S0095e7a0_GetHeap()->FUN_008f6f60(n * 48, 0xd);

    for (int i = 0; i < n; i++)
    {
        int parentIndex = -1;
        if (i != 0)
        {
            S0095e7a0_RigidBody* parent = constraints->data[i - 1]->parent;
            for (int j = 0; j < i; j++)
            {
                if (bodies->data[j] == parent)
                {
                    parentIndex = j;
                    break;
                }
            }
        }
        S->parentsData[i] = (short)parentIndex;

        S0095e7a0_RigidBody* body = bodies->data[i];

        S0095e7a0_Bone* bone = new S0095e7a0_Bone;

        if (parentIndex >= 0)
        {
            S0095e7a0_RigidBody* parentBody = bodies->data[parentIndex];
            hkQsTransform childPose;
            childPose.FUN_009643d0(body->transform);
            hkQsTransform parentPose;
            parentPose.FUN_009643d0(parentBody->transform);
            hkQsTransform& out = S->poseData[i];
            hkQsTransform inversePose;
            inversePose.setConjugate(parentPose);
            out.setMul(inversePose, childPose);
        }
        else
        {
            S->poseData[i].FUN_009643d0(body->transform);
        }

        if (body->name != 0)
        {
            bone->name = FUN_00923640(body->name);
        }
        else
        {
            char buffer[0x200];
            S0095e7a0_ErrStream stream;
            stream.FUN_00923070(buffer, 0x200);
            stream.FUN_00943710(DAT_00e365d4);
            DAT_010f3364->Report(1, 0xabbacc14, buffer, DAT_00e7c1a8, 0x234);
            stream.FUN_00943a60();
            bone->name = 0;
        }
        bone->lockTranslation = (i != 0);
        S->bonesData[i] = bone;
    }

    if (S->bonesCount > 0)
    {
        S->name = S->bonesData[0]->name;
    }
    else
    {
        S->name = 0;
    }
    return S;
}

}  // namespace f3m_0095e7a0

// @f3 0x00942350 (community match, verified in this file)
// FUN_00942350 = Havok 5.5.0 WorkerThreadFunc (hkpUtilities.lib, hkpMultithreadingUtil.obj; hkpMultithreadingUtil.cpp
// lines 424-710), the worker thread entry of hkpMultithreadingUtil, with one game-side change: the local stack size
// is the constant 2000000 instead of state.m_localStackSize. Written from the SDK headers and the library objects
// debug records (the .cpp is not shipped); reduced from sdk_game.cpp with hktrim.py. See note.txt.
namespace f3m_00942350 {
typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};

		typedef unsigned __int64 hkUint64;
			typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
	private:
		char m_bool;
};

class hkHalf
{
    private:
	    hkInt16 m_value;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline TYPE val() const
		{
			return m_storage;
		}
	private:
		TYPE m_storage;
};

		extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
			__declspec(dllimport) int _stdcall TlsSetValue( unsigned long dwTlsIndex, void* lpTlsValue);
		}

		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				__forceinline void setData(T p)
				{
					hkUlong v = hkUlong(p);
					TlsSetValue( m_slotID, (void*)v );
				}
				unsigned long m_slotID;
		};

enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };

class hkMemory;

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}

hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocate(int numberOfObjects, HK_MEMORY_CLASS cl)
{
	return static_cast<TYPE*>(hkThreadMemory::getInstance().allocate(numberOfObjects*int(sizeof(TYPE)), cl));
}

template <typename TYPE>
__forceinline void __cdecl hkDeallocate(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocate(static_cast<void *>(ptr));
}

class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
};

class hkStatisticsCollector;

class hkReferencedObject : public hkBaseObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};

class hkOstream;

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};


class hkVector4
{
	public:
		                class MustEndWithSemiColon;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

namespace hkBaseSystem
{
	hkResult __cdecl initThread( hkThreadMemory* threadMemory );
	hkResult __cdecl clearThreadResources(  );
}

class hkSemaphore
{
	public:
		                class MustEndWithSemiColon;
		void acquire();
		void release(int count = 1);
	protected:	void* m_semaphore;
};

class hkThread
{
	public:
		                class MustEndWithSemiColon;
		typedef void* (__cdecl *StartFunction)(void*);
		enum Status
		{
			THREAD_TERMINATED,
			THREAD_RUNNING,
			THREAD_NOT_STARTED
		};
	protected:
		void* m_thread;
		hkUint64 m_threadId;
};

class hkMultiThreadCheck
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};

class hkStepInfo
{
	public:
		                class MustEndWithSemiColon;
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};

struct hkpSolverInfo
{
	                class MustEndWithSemiColon;
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		                class MustEndWithSemiColon;
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};

class hkAabb
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

class hkpWorldCinfo : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum SolverType
		{
			SOLVER_TYPE_INVALID,
			SOLVER_TYPE_2ITERS_SOFT,
			SOLVER_TYPE_2ITERS_MEDIUM,
			SOLVER_TYPE_2ITERS_HARD,
			SOLVER_TYPE_4ITERS_SOFT,
			SOLVER_TYPE_4ITERS_MEDIUM,
			SOLVER_TYPE_4ITERS_HARD,
			SOLVER_TYPE_8ITERS_SOFT,
			SOLVER_TYPE_8ITERS_MEDIUM,
			SOLVER_TYPE_8ITERS_HARD,
			SOLVER_TYPE_MAX_ID
		};
		enum SimulationType
		{
			SIMULATION_TYPE_INVALID,
			SIMULATION_TYPE_DISCRETE,
			SIMULATION_TYPE_CONTINUOUS,
			SIMULATION_TYPE_MULTITHREADED,
		};
		enum ContactPointGeneration
		{
			CONTACT_POINT_ACCEPT_ALWAYS,
			CONTACT_POINT_REJECT_DUBIOUS,
			CONTACT_POINT_REJECT_MANY,
		};
		enum BroadPhaseBorderBehaviour
		{
			BROADPHASE_BORDER_ASSERT,
			BROADPHASE_BORDER_FIX_ENTITY,
			BROADPHASE_BORDER_REMOVE_ENTITY,
			BROADPHASE_BORDER_DO_NOTHING,
		};
	public:
		hkVector4 m_gravity;
		hkInt32 m_broadPhaseQuerySize;
		hkReal m_contactRestingVelocity;
		hkEnum<BroadPhaseBorderBehaviour,hkInt8> m_broadPhaseBorderBehaviour;
		class hkAabb m_broadPhaseWorldAabb;
		hkReal m_collisionTolerance;
		class hkpCollisionFilter* m_collisionFilter;
		class hkpConvexListFilter* m_convexListFilter;
		hkReal m_expectedMaxLinearVelocity;
		int m_sizeOfToiEventQueue;
		hkReal m_expectedMinPsiDeltaTime;
		class hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
		hkInt32 m_broadPhaseNumMarkers;
		hkEnum<ContactPointGeneration, hkInt8> m_contactPointGeneration;
		hkReal m_solverTau;
		hkReal m_solverDamp;
		hkInt32 m_solverIterations;
		hkInt32 m_solverMicrosteps;
		hkBool m_forceCoherentConstraintOrderingInSolver;
		hkReal m_snapCollisionToConvexEdgeThreshold;
		hkReal m_snapCollisionToConcaveEdgeThreshold;
		hkBool m_enableToiWeldRejection;
		hkBool m_enableDeprecatedWelding;
		hkReal m_iterativeLinearCastEarlyOutDistance;
		hkInt32 m_iterativeLinearCastMaxIterations;
		hkReal m_highFrequencyDeactivationPeriod;
		hkReal m_lowFrequencyDeactivationPeriod;
		hkUint8 m_deactivationNumInactiveFramesSelectFlag0;
		hkUint8 m_deactivationNumInactiveFramesSelectFlag1;
		hkUint8 m_deactivationIntegrateCounter;
		hkBool m_shouldActivateOnRigidBodyTransformChange;
		hkReal m_deactivationReferenceDistance;
		hkReal m_toiCollisionResponseRotateNormal;
		int m_maxSectorsPerCollideTask;
		hkBool m_processToisMultithreaded;
		int m_maxEntriesPerToiCollideTask;
		hkBool m_enableDeactivation;
		hkEnum<SimulationType, hkInt8> m_simulationType;
		hkBool m_enableSimulationIslands;
		hkUint32 m_minDesiredIslandSize;
		hkBool m_processActionsInSingleThread;
		hkReal m_frameMarkerPsiSnap;
		virtual ~hkpWorldCinfo() {}
};

class hkpCollisionDispatcher;
struct hkpProcessCollisionInput;
class hkpCollisionListener;
class hkpTypedBroadPhaseDispatcher;
class hkpBroadPhase;
class hkpEntityListener;
class hkpRigidBody;
class hkpPhantom;
class hkpPhantomListener;
class hkpPhantomBroadPhaseListener;
class hkpEntityEntityBroadPhaseListener;
class hkpBroadPhaseBorderListener;
class hkpActionListener;
class hkpConstraintListener;
class hkpSimulationIsland;
struct hkpMultithreadedSimulationJobData;
class hkpWorldPostSimulationListener;
class hkpWorldPostIntegrateListener;
class hkpWorldPostCollideListener;
class hkpWorldDeletionListener;
class hkpIslandActivationListener;
class hkpContactImpulseLimitBreachedListener;
class hkpIslandPostIntegrateListener;
class hkpIslandPostCollideListener;
class hkpSimulation;
class hkpWorldOperationQueue;
struct hkpDebugInfoOnPendingOperationQueues;
class hkpWorldMaintenanceMgr;

struct hkpWorldDynamicsStepInfo
{
	                class MustEndWithSemiColon;
	hkStepInfo   m_stepInfo;
	hkpSolverInfo m_solverInfo;
};

enum hkpThreadToken
{
	HK_THREAD_TOKEN_FIRST,
	HK_THREAD_TOKEN_SECOND,
	HK_THREAD_TOKEN_THIRD,
	HK_THREAD_TOKEN_FORTH,
	HK_THREAD_TOKEN_FIFTH,
	HK_THREAD_TOKEN_SIXTH,
};

enum hkpStepResult
{
	HK_STEP_RESULT_SUCCESS,
	HK_STEP_RESULT_MEMORY_FAILURE_BEFORE_INTEGRATION,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_COLLIDE,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_TOI_SOLVE,
};

class hkpWorld : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
        static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum ReintegrationRecollideMode
		{
			RR_MODE_REINTEGRATE = 1,
			RR_MODE_RECOLLIDE_BROADPHASE = 2,
			RR_MODE_RECOLLIDE_NARROWPHASE = 4,
			RR_MODE_ALL = 7
		};
		void calcStatistics( hkStatisticsCollector* collector ) const;
		enum MtAccessChecking
		{
			MT_ACCESS_CHECKING_ENABLED = 0,
			MT_ACCESS_CHECKING_DISABLED
		};
		hkpStepResult advanceTime();
		void setFrameTimeMarker( hkReal frameDeltaTime );
		bool isSimulationAtMarker() const;
		bool isSimulationAtPsi() const;
		void stepBeginSt( hkReal physicsDeltaTime );
		void stepProcessMt( const hkpThreadToken& token );
		void stepEndSt();
		class hkJobQueue* getJobQueue();
		~hkpWorld();
	public:
		hkpSimulation* m_simulation;
		hkVector4			m_gravity;
        hkpSimulationIsland* m_fixedIsland;
			hkpRigidBody*	m_fixedRigidBody;
        hkArray<hkpSimulationIsland*> m_activeSimulationIslands;
        hkArray<hkpSimulationIsland*> m_inactiveSimulationIslands;
        hkArray<hkpSimulationIsland*> m_dirtySimulationIslands;
        hkpWorldMaintenanceMgr* m_maintenanceMgr;
        hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
        hkpBroadPhase* m_broadPhase;
        hkpTypedBroadPhaseDispatcher*    m_broadPhaseDispatcher;
        hkpPhantomBroadPhaseListener*    m_phantomBroadPhaseListener;
        hkpEntityEntityBroadPhaseListener* m_entityEntityBroadPhaseListener;
        hkpBroadPhaseBorderListener* m_broadPhaseBorderListener;
        hkpMultithreadedSimulationJobData* m_multithreadedSimulationJobData;
        hkpProcessCollisionInput* m_collisionInput;
            hkpCollisionFilter*       m_collisionFilter;
            hkpCollisionDispatcher*   m_collisionDispatcher;
            hkpConvexListFilter*     m_convexListFilter;
        hkpWorldOperationQueue* m_pendingOperations;
			int m_pendingOperationsCount;
			int m_criticalOperationsLockCount;
			int m_criticalOperationsLockCountForPhantoms;
			hkBool m_blockExecutingPendingOperations;
			hkBool m_criticalOperationsAllowed;
            hkpDebugInfoOnPendingOperationQueues* m_pendingOperationQueues;
			int m_pendingOperationQueueCount;
        mutable class hkMultiThreadCheck m_multiThreadCheck;
		hkBool m_processActionsInSingleThread;
		hkUint32 m_minDesiredIslandSize;
        class hkCriticalSection* m_modifyConstraintCriticalSection;
        class hkCriticalSection* m_worldLock;
        class hkCriticalSection* m_islandDirtyListCriticalSection;
		struct PropertyLock
		{
			                class MustEndWithSemiColon;
			hkUint32 m_key;
			mutable hkMultiThreadCheck m_multiThreadCheck;
		};
        class hkCriticalSection* m_propertyMasterLock;
		hkBool m_wantSimulationIslands;
		hkReal m_snapCollisionToConvexEdgeThreshold;
		hkReal m_snapCollisionToConcaveEdgeThreshold;
		hkBool m_enableToiWeldRejection;
		hkBool m_wantDeactivation;
		hkBool m_shouldActivateOnRigidBodyTransformChange;
		hkReal m_deactivationReferenceDistance;
		hkReal m_toiCollisionResponseRotateNormal;
		hkBool m_processToisMultithreaded;
		int m_maxSectorsPerCollideTask;
		int m_maxEntriesPerToiCollideTask;
        hkEnum<hkpWorldCinfo::SimulationType,hkInt32>  m_simulationType;
		static hkBool m_forceMultithreadedSimulation;
		class IgnoreForceMultithreadedSimulation
		{
			public:
				                class MustEndWithSemiColon;
			public:
				hkBool m_originalForceMultithreadedSimulationValue;
		};
	protected:
		hkUint32 m_lastEntityUid;
	public:
		friend class hkpWorldOperationUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpSimulation;
		friend class hkHalfstepSimulation;
		friend class hkpContinuousSimulation;
		friend class hkpMultiThreadedSimulation;
		friend class hkpSimpleConstraintContactMgr;
		hkArray<hkpPhantom*> m_phantoms;
        hkArray<hkpActionListener*>              m_actionListeners;
        hkArray<hkpEntityListener*>              m_entityListeners;
        hkArray<hkpPhantomListener*>             m_phantomListeners;
        hkArray<hkpConstraintListener*>          m_constraintListeners;
        hkArray<hkpWorldDeletionListener*>       m_worldDeletionListeners;
        hkArray<hkpIslandActivationListener*>    m_islandActivationListeners;
        hkArray<hkpWorldPostSimulationListener*> m_worldPostSimulationListeners;
        hkArray<hkpWorldPostIntegrateListener*>  m_worldPostIntegrateListeners;
        hkArray<hkpWorldPostCollideListener*>    m_worldPostCollideListeners;
        hkArray<hkpIslandPostIntegrateListener*> m_islandPostIntegrateListeners;
        hkArray<hkpIslandPostCollideListener*>   m_islandPostCollideListeners;
        hkArray<hkpCollisionListener*>           m_collisionListeners;
        hkArray<hkpContactImpulseLimitBreachedListener*> m_contactImpulseLimitBreachedListeners;
        class hkpBroadPhaseBorder*               m_broadPhaseBorder;
	public:
		struct hkpWorldDynamicsStepInfo m_dynamicsStepInfo;
		hkVector4 m_broadPhaseExtents[2];
		int			m_broadPhaseNumMarkers;
		int			m_sizeOfToiEventQueue;
		hkInt32		m_broadPhaseQuerySize;
		hkInt32		m_broadPhaseUpdateSize;
        hkEnum<hkpWorldCinfo::ContactPointGeneration, hkInt8> m_contactPointGeneration;
};

struct hkpMultithreadingUtilCinfo
{
	                class MustEndWithSemiColon;
	hkpWorld* m_world;
	int m_numThreads;
	int m_localStackSize;
	bool m_enableTimers;
	class hkSpuUtil* m_spuUtil;
	class hkpJobDispatcherUtil* m_jobDispatcherUtil;
};

class hkpMultithreadingUtil
{
	public:
		                class MustEndWithSemiColon;
		enum { MAX_NUM_PHYSICS_THREADS = 6 };
	public:
		struct State;
		struct WorkerThreadData
		{
			                class MustEndWithSemiColon;
			State* m_state;
			hkThread m_thread;
			int m_threadId;
			bool m_killThread;
			hkSemaphore m_semaphore;
			hkpThreadToken m_threadToken;
			char* m_monitorStreamBegin;
			char* m_monitorStreamEnd;
		};
		struct State
		{
			                class MustEndWithSemiColon;
			class hkpWorld* m_world;
			hkReal m_deltaTime;
			hkReal m_frameDeltaTime;
			hkSemaphore m_workerThreadFinished;
			hkSemaphore m_stepInitSemaphore;
			hkSemaphore m_stepEndSemaphore;
			hkSemaphore m_asyncSetupSemaphore;
			hkSemaphore m_asyncFinishSemaphore;
			hkSemaphore m_physicsBarrierSemaphore;
			hkBool m_physicsRunning;
			WorkerThreadData m_workerThreads[MAX_NUM_PHYSICS_THREADS];
			int m_numThreads;
			int m_localStackSize;
			bool m_enableTimers;
			hkSpuUtil* m_spuUtil;
			hkBool					m_useImplicitSimulateDispatcher;
			hkpJobDispatcherUtil*	m_jobDispatcherUtil;
			hkJobQueue*				m_dispatcherUtilJobQueue;
			hkBool m_clearTimers;
		};
	public:
		State m_state;
};


extern "C" {
typedef unsigned long       DWORD;
typedef unsigned short      WORD;
extern "C" {
extern "C" {
    typedef __w64 unsigned long ULONG_PTR, *PULONG_PTR;
}
typedef long LONG;
typedef void *HANDLE;
typedef struct _LIST_ENTRY {
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, * PRLIST_ENTRY;
typedef struct _RTL_CRITICAL_SECTION_DEBUG {
    WORD   Type;
    WORD   CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD   CreatorBackTraceIndexHigh;
    WORD   SpareWORD  ;
} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, RTL_RESOURCE_DEBUG, *PRTL_RESOURCE_DEBUG;
typedef struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;
}
}

extern "C" {
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
}

extern "C" {
}

extern "C" {
}

class hkCriticalSection
{
	public:
		                class MustEndWithSemiColon;
		static inline void __cdecl setTimersEnabled();
		static inline void __cdecl setTimersDisabled();
	public:
		CRITICAL_SECTION  m_section;
		hkUint64 m_currentThread;
		struct SectionList
		{
			int m_spinCount;
			hkCriticalSection* m_prev;
			hkCriticalSection* m_next;
			static hkCriticalSection s_listHead;
		};
		SectionList m_list;
};

	extern hkThreadLocalData<int> hkCriticalSection__m_timeLocks;

class hkMonitorStream
{
	public:
		                class MustEndWithSemiColon;
		static hkMonitorStream& getInstance()
		{
			extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
			return *hkMonitorStream__m_instance.getData();
		}
		void __cdecl reset();
		void __cdecl resize( int newSize );
	public:
		__forceinline char* __cdecl getStart() { return m_start.val(); }
		__forceinline char* __cdecl getEnd() { return m_end.val(); }
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
	public:
		struct Command
		{
			                class MustEndWithSemiColon;
			const char* m_commandAndMonitor;
		};
		struct AddValueCommand : public hkMonitorStream::Command
		{
			                class MustEndWithSemiColon;
			float m_value;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			                class MustEndWithSemiColon;
			hkUint32	m_time0;
			hkUint32	m_time1;
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			                class MustEndWithSemiColon;
			const char* m_nameOfFirstSplit;
		};
};

inline void hkCriticalSection::setTimersEnabled()
{
	hkCriticalSection__m_timeLocks.setData(1);
}

inline void hkCriticalSection::setTimersDisabled()
{
	hkCriticalSection__m_timeLocks.setData(0);
}

typedef hkSemaphore hkSemaphoreBusyWait;

template <typename T>
class hkQueue
{
	public:
		                class MustEndWithSemiColon;
	private:
		T* m_data;
		int m_capacity;
		int m_head;
		int m_tail;
		int m_elementsInUse;
};

struct hkJobHelperBaseClass
{
	public:
		enum hkJobBaseId
		{
			HK_DYNAMICS_JOB_BASE		=   0,
			HK_COLLISION_JOB_BASE		=  30,
			HK_COLLISION_QUERY_JOB_BASE	=  40,
			HK_ANIMATION_JOB_BASE		=  60,
			HK_BEHAVIOR_JOB_BASE		=  80,
			HK_END_JOB_BASE				=  100
		};
		__declspec(align(16)) hkObjectIndex m_jobType;
};

class hkJobQueue
{
	public:
		enum Rules
		{
			NO_SPU_AVAILABLE,
			SPU_AVAILABLE_AND_PPU_CAN_TAKE_SPU_TASKS,
			SPU_AVAILABLE_AND_PPU_CANNOT_TAKE_SPU_TASKS
		};
		struct JobQueueEntry
		{
			__declspec(align(16)) hkUchar m_data[128];
		};
		enum JobType
		{
			JOB_TYPE_CPU			= 0,
			JOB_TYPE_CPU_BROADPHASE	= 1,
			JOB_TYPE_CPU_MASTER		= 2,
			JOB_TYPE_HINT_SPU		= 0,
			JOB_TYPE_HINT_SPU_CD	= 0,
			JOB_TYPE_HINT_SPU_CQ	= 0,
			JOB_TYPE_MAX			= 3,
		};
		struct DynamicData
		{
			                class MustEndWithSemiColon;
			__declspec(align(16)) int m_numActiveJobs;
			int m_numCpuThreadsWaitingForJobs;
			int m_numSpuThreadsWaitingForJobs;
			int m_numMasterThreadsWaitingForJobs;
			hkBool m_dontReleaseSpus;
			hkQueue< JobQueueEntry > m_jobQueue[JOB_TYPE_MAX];
		};
		enum ThreadType
		{
			THREAD_TYPE_CPU				= JOB_TYPE_CPU,
			THREAD_TYPE_CPU_BROADPHASE	= JOB_TYPE_CPU_BROADPHASE,
			THREAD_TYPE_CPU_MASTER		= JOB_TYPE_CPU_MASTER,
			THREAD_TYPE_MAX				= JOB_TYPE_MAX,
			THREAD_TYPE_INVALID			= -1,
		};
		enum JobPriority
		{
			JOB_HIGH_PRIORITY,
			JOB_LOW_PRIORITY,
		};
		enum JobPopFuncResult
		{
			POP_QUEUE_ENTRY,
			DO_NOT_POP_QUEUE_ENTRY
		};
		typedef JobPopFuncResult (__cdecl *JobPopFunc)( hkJobQueue& queue, hkJobQueue::DynamicData* data, JobQueueEntry& jobIn, JobQueueEntry& jobOut );
		enum JobCreationStatus
		{
			JOB_CREATED,
			NO_JOB_CREATED
		};
		struct JobQueueEntryInput
		{
			hkPadSpu<hkUint32>	m_jobThreadType;
			hkPadSpu<hkUint32>	m_jobPriority;
			JobQueueEntry		m_job;
		};
		typedef JobCreationStatus (__cdecl *FinishJobFunc)( hkJobQueue& queue, DynamicData* data, const JobQueueEntry& jobIn, JobQueueEntryInput& newJobCreatedOut );
	public:
		enum WaitStatus
		{
			WAIT_FOR_NEXT_JOB,
			DO_NOT_WAIT_FOR_NEXT_JOB
		};
		enum JobStatus
		{
			GOT_NEXT_JOB,
			NO_JOBS_AVAILABLE,
			JOBS_AVAILABLE_BUT_NOT_FOR_CURRENT_ELF,
			ALL_JOBS_FINISHED
		};
	public:
		__declspec(align(64)) hkCriticalSection m_criticalSection;
		DynamicData* m_data;
		struct JobQueryRule
		{
			hkUint8 m_numJobTypesAvailable;
			hkEnum<JobType, hkUint8> m_jobTypeOrder[JOB_TYPE_MAX];
		};
		JobQueryRule m_jobQueryRules[JOB_TYPE_MAX];
		JobPopFunc m_jobPopFunc;
		FinishJobFunc m_finishJobFunc;
		hkUlong m_userData;
		hkSemaphoreBusyWait* m_masterThreadWaitSemaphore;
		hkSemaphoreBusyWait* m_cpuWaitSemaphore;
		hkSemaphoreBusyWait* m_taskCompletionSemaphore;
		hkSemaphoreBusyWait* m_spuWaitSemaphore;
};

class hkpJobDispatcherUtil
{
	public:
		                class MustEndWithSemiColon;
		enum
		{
			MAX_JOB_FUNCS = hkJobHelperBaseClass::HK_END_JOB_BASE
		};
		typedef hkJobQueue::JobStatus (__cdecl *ProcessJobFunc)( hkJobQueue::ThreadType threadType, hkpProcessCollisionInput& input, hkJobQueue& jobQueue, hkJobQueue::JobQueueEntry& jobInOut );
	public:
		hkJobQueue::JobStatus processNextJob( hkJobQueue::ThreadType threadType, hkpProcessCollisionInput& input, hkJobQueue& jobQueue );
	private:
		ProcessJobFunc m_jobFuncs[MAX_JOB_FUNCS];
};

struct hkMemoryStatistics
{
    static const hk_size_t INFINITE_SIZE = (hk_size_t(0)-1);
    hk_size_t m_allocated;
    hk_size_t m_used;
    hk_size_t m_available;
    hk_size_t m_totalAvailable;
    hk_size_t m_largestBlock;
	        class MustEndWithSemiColon;
};

class hkLimitedMemoryListener
{
public:
	        class MustEndWithSemiColon;
	virtual ~hkLimitedMemoryListener(){}
    virtual void cannotAllocate(hkMemory* mem,hk_size_t size) =0;
    virtual void allocationFailure(hkMemory* mem,hk_size_t size) = 0;
};

typedef void (__cdecl *hkMemoryWalkCallback)(void* start, hk_size_t size,hkBool allocated,int pool,void* param);

class hkMemory
{
	public:
		        class MustEndWithSemiColon;
		friend class hkThreadMemory;
		virtual ~hkMemory();
		virtual void allocateChunkBatch(void** blocksOut, int nblocks, int nbytes) = 0;
		virtual void deallocateChunkBatch(void** blocksOut, int nblocks, int nbytes) = 0;
		virtual void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void deallocateChunk( void*, int nbytes, HK_MEMORY_CLASS cl ) = 0;
		virtual void* allocateRuntimeBlock(int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void deallocateRuntimeBlock(void*, int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void preAllocateRuntimeBlock(int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void provideRuntimeBlock(void*, int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void freeRuntimeBlocks() = 0;
		virtual void reservePagesFromSystemMemory( int numBytes ) {}
        virtual void garbageCollect() {}
        virtual void optimize() {}
		virtual void releaseUnusedPagesToSystemMemory( void ) {}
		virtual void printStatistics(hkOstream* c) = 0;
		virtual int getAllocatedSize( int size );
		virtual bool isDebugMemory(){ return false; }
        virtual void calculateStatistics(hkMemoryStatistics& stats ) =0;
        virtual void setMemoryHardLimit(hk_size_t maxMemory) { }
        virtual hk_size_t getMemoryHardLimit() { return 0; }
        virtual void setMemorySoftLimit(hk_size_t maxMemory) { }
        virtual hk_size_t getMemorySoftLimit() { return 0; }
        virtual void setLimitedMemoryListener(hkLimitedMemoryListener* listener) {}
        virtual hkLimitedMemoryListener* getLimitedMemoryListener() { return 0; }
        virtual hkBool hasMemoryAvailable(hk_size_t size) { return true; }
		virtual hkBool isOk() const;
		virtual void* findBaseAddress(void* p, int nbytes) { return 0; }
		virtual void lockBlock(void* p) {}
		virtual void unlockBlock(void* p) {}
        virtual hkResult walkMemory(hkMemoryWalkCallback callback,void* param) { return HK_FAILURE; }
		enum MemoryState
		{
			MEMORY_STATE_OK,
			MEMORY_STATE_OUT_OF_MEMORY
		};
		MemoryState m_memoryState;
		int m_criticalMemoryLimit;
        int m_memoryUsed;
		static inline hkMemory& __cdecl getInstance();
		enum MemoryFill
		{
			MEMORY_FILL_GUARD_AREA = 0xFD,
			MEMORY_FILL_FREE_SPACE = 0xDD,
			MEMORY_FILL_RETURNED_TO_USER = 0xCD
		};
	protected:
		static hkMemory* s_instance;
		int m_referenceCount;
		struct BigBlockData
		{
			hkBool m_available;
			int m_size;
			void* m_memory;
			HK_MEMORY_CLASS m_class;
			hkBool m_providedByOutside;
		};
		enum { BIG_BLOCKS_SLOTS=128 };
		int m_numValidBigBlocks;
		BigBlockData m_bigBlockDataArray[BIG_BLOCKS_SLOTS];
	public:
		static hkInt32 s_fillGuardArea;
		static hkInt32 s_fillFreeSpace;
		static hkInt32 s_fillReturnedToUser;
};

hkMemory& __cdecl hkMemory::getInstance()
{
	return *s_instance;
}

class hkIstream;

struct hkCheckDeterminismUtil
{
	public:
		                class MustEndWithSemiColon;
		struct Fuid
		{
			                class MustEndWithSemiColon;
			hkUint32 m_0, m_1, m_2, m_3;
		};
		static __forceinline void __cdecl workerThreadStartFrame(hkBool isPrimaryWorkerThread){  }
	public:
		enum Mode
		{
			MODE_IDLE,
			MODE_WRITE,
			MODE_COMPARE
		};
		Mode m_mode;
		hkBool m_inSingleThreadedCode;
		hkIstream* m_sharedInputStream;
		hkOstream* m_sharedOutputStream;
		hkIstream* m_primaryWorkerThreadInputStream;
		hkOstream* m_primaryWorkerThreadOutputStream;
		int m_primaryWorkerThreadJobInfoIdx;
		hkCriticalSection* m_shared;
		struct JobInfo
		{
			                class MustEndWithSemiColon;
			Fuid	  m_jobFuid;
			hkArray<char>* m_data;
			hkBool		  m_isOpen;
		};
		hkArray<JobInfo> m_registeredJobs;
		hkBool m_writingStFromWorker;
};

void* __cdecl FUN_00942350(void *v)
{
	hkpMultithreadingUtil::WorkerThreadData& data = *static_cast<hkpMultithreadingUtil::WorkerThreadData*>(v);
	hkpMultithreadingUtil::State& state = *data.m_state;
	hkThreadMemory threadMemory(&hkMemory::getInstance(), 16);
	hkBaseSystem::initThread( &threadMemory );
	char* stackBuffer;
	{
		int stackSize = 2000000;
		stackBuffer = hkAllocate<char>( stackSize, HK_MEMORY_CLASS_BASE );
		threadMemory.setStackArea( stackBuffer, stackSize );
	}
	if ( state.m_enableTimers )
	{
		int monitorStreamSize = 2000000;
		hkMonitorStream::getInstance().resize( monitorStreamSize );
	}
	data.m_monitorStreamBegin = hkMonitorStream::getInstance().getStart();
	data.m_monitorStreamEnd = hkMonitorStream::getInstance().getEnd();
	data.m_semaphore.acquire();
	hkpThreadToken token = data.m_threadToken;
	while ( data.m_killThread == false )
	{
		hkCheckDeterminismUtil::workerThreadStartFrame( data.m_threadToken == HK_THREAD_TOKEN_FIRST );
		if ( state.m_clearTimers )
		{
			hkMonitorStream::getInstance().reset();
		}
		data.m_monitorStreamEnd = hkMonitorStream::getInstance().getEnd();
		state.m_physicsBarrierSemaphore.acquire();
		hkCriticalSection::setTimersEnabled();
		if ( state.m_useImplicitSimulateDispatcher == true )
		{
			if ( state.m_frameDeltaTime == -1.0 )
			{
				if ( token == HK_THREAD_TOKEN_FIRST )
				{
					state.m_world->stepBeginSt( state.m_deltaTime );
					state.m_stepInitSemaphore.release( state.m_numThreads );
				}
				state.m_stepInitSemaphore.acquire();
				state.m_world->stepProcessMt( token );
				if ( token == HK_THREAD_TOKEN_FIRST )
				{
					state.m_world->stepEndSt();
				}
			}
			else
			{
				if ( token == HK_THREAD_TOKEN_FIRST )
				{
					state.m_world->setFrameTimeMarker( state.m_frameDeltaTime );
					state.m_world->advanceTime();
					state.m_asyncSetupSemaphore.release( state.m_numThreads );
				}
				state.m_asyncSetupSemaphore.acquire();
				while ( !state.m_world->isSimulationAtMarker() )
				{
					if ( token == HK_THREAD_TOKEN_FIRST )
					{
						for ( int t = 0; t < state.m_numThreads - 1; ++t )
						{
							state.m_asyncFinishSemaphore.acquire();
						}
					}
					else
					{
						state.m_asyncFinishSemaphore.release();
					}
					if ( token == HK_THREAD_TOKEN_FIRST )
					{
						state.m_world->stepBeginSt( state.m_deltaTime );
						state.m_stepInitSemaphore.release( state.m_numThreads );
					}
					state.m_stepInitSemaphore.acquire();
					state.m_world->stepProcessMt( token );
					if ( token == HK_THREAD_TOKEN_FIRST )
					{
						state.m_world->stepEndSt();
						if ( state.m_world->isSimulationAtPsi() )
						{
						}
						state.m_stepEndSemaphore.release( state.m_numThreads );
					}
					state.m_stepEndSemaphore.acquire();
					if ( token == HK_THREAD_TOKEN_FIRST )
					{
						for ( int t = 0; t < state.m_numThreads - 1; ++t )
						{
							state.m_asyncFinishSemaphore.acquire();
						}
					}
					else
					{
						state.m_asyncFinishSemaphore.release();
					}
				}
			}
		}
		else
		{
			state.m_jobDispatcherUtil->processNextJob( hkJobQueue::THREAD_TYPE_CPU, *state.m_world->m_collisionInput, *state.m_dispatcherUtilJobQueue );
		}
		hkCriticalSection::setTimersDisabled();
		hkMonitorStream& stream = hkMonitorStream::getInstance();
		data.m_monitorStreamEnd = stream.getEnd();
		state.m_workerThreadFinished.release();
		data.m_semaphore.acquire();
	}
	threadMemory.setStackArea( 0, 0 );
	hkDeallocate( stackBuffer );
	hkBaseSystem::clearThreadResources();
	state.m_workerThreadFinished.release();
	return 0;
}
}

// @f3 0x00940e70 (community match, verified in this file)
// FUN_00940e70 = Havok 5.5.0 hkVersionUtil::generateCppClassList (hkSerialize.lib, hkVersionUtil.obj).
// Written from the SDK headers and the library objects' debug records (the .cpp is not shipped); reduced from
// sdk_final.cpp with hktrim.py. generateEnum (record lines 114-125) is the file-local callee from the same .cpp.
// See note.txt.
namespace f3m_00940e70 {
typedef float  hkReal;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};

class hkClass;
typedef int hkBool32;

class hkBool
{
	public:
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	private:
		STORAGE m_storage;
};

template<typename BITS, typename STORAGE>
class hkFlags
{
	public:
		STORAGE get() const
		{
			return m_storage;
		}
	private:
		STORAGE m_storage;
};

		extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}

		template<typename T>
		class hkThreadLocalData
		{
			public:
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};

enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };

class hkMemory;

class hkThreadMemory
{
	public:
		        class MustEndWithSemiColon;
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void deallocate(void*);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};

hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}

hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}

template <typename TYPE>
__forceinline void __cdecl hkDeallocate(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocate(static_cast<void *>(ptr));
}

class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
};

class hkStatisticsCollector;

class hkReferencedObject : public hkBaseObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkReferencedObject() { }
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};

class hkStreamWriter;

class hkOstream : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		~hkOstream();
		hkOstream& operator<< (const char* s);
		void printf( const char *fmt, ...);
	protected:
		hkStreamWriter*	m_writer;
};

namespace hkArrayUtil
{
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		                class MustEndWithSemiColon;
		__forceinline hkArray();
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	public:
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void reserve(int n);
		__forceinline void setSize(int size);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline const_iterator begin() const;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}

template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}

template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}

template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline hkArray<T>::hkArray(int n, const T& t)
	:	m_data( static_cast<T*>(hkThreadMemory::getInstance().allocateChunk(n * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY))),
		m_size(n),
		m_capacityAndFlags(n)
{
	for(int i = 0; i < n; ++i)
	{
		m_data[i] = t;
	}
}

template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}

template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
	:	m_data(ptr),
		m_size(size),
		m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}

template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}

template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
	const int capacity = getCapacity();
	if( capacity < n)
	{
		int cap2 = 2 * capacity;
		int newSize = (n < cap2) ? cap2 : n;
		hkArrayUtil::_reserve(this, newSize, sizeof(T));
	}
}

template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}

template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}

template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::begin() const
{
	return m_data;
}

class hkString
{
	public:
		                class MustEndWithSemiColon;
	public:
		__forceinline hkString();
		__forceinline hkString(const char* s);
	private:
		__forceinline	void setLength( int length );
	public:
		__forceinline hkString& operator=(const char* s);
		__forceinline ~hkString();
		void printf(const char* format, ...);
		__forceinline const char* cString() const;
		hkString& operator+= (const hkString& other);
		hkString& operator+= (const char* other);
		int getLength() const;
		enum ReplaceType
		{
			REPLACE_ONE,
			REPLACE_ALL
		};
		hkString replace(const hkString& from, const hkString& to, ReplaceType=REPLACE_ALL) const;
	private:
		hkArray<char> m_string;
	public:
		static int __cdecl strLen(const char* src);
		static char* __cdecl strDup(const char* src);
		static void __cdecl memCpy(void* dst, const void* src, int n);
};

__forceinline int hkString::getLength() const
{
	return m_string.getSize() - 1;
}

__forceinline const char* hkString::cString() const
{
	return m_string.begin();
}

__forceinline void hkString::setLength( int length )
{
	m_string.setSize( length + 1 );
}

__forceinline hkString::hkString()
:m_string(1, 0)
{
}

__forceinline hkString::hkString(const char* s)
{
	if( s != 0 )
	{
		setLength( strLen(s) );
		hkString::memCpy(m_string.begin(), s, m_string.getSize() );
	}
	else
	{
		setLength(0);
		m_string[0] = 0;
	}
}

__forceinline hkString& hkString::operator= (const char* s)
{
	if(s != 0 && *s != 0)
	{
		int slen = strLen(s);
		setLength( slen );
		hkString::memCpy(m_string.begin(), s, slen+1);
	}
	else
	{
		setLength(0);
		m_string[0] = 0;
	}
	return *this;
}

__forceinline hkString::~hkString()
{
}

template <typename T>
class hkPointerMapBase
{
	public:
		                class MustEndWithSemiColon;
		typedef class Dummy* Iterator;
		hkPointerMapBase();
		~hkPointerMapBase();
		Iterator getIterator() const;
		T getValue( Iterator i ) const;
		Iterator getNext( Iterator i ) const;
		hkBool isValid( Iterator i ) const;
		void insert( T key, T val );
		Iterator findKey( T key ) const;
		hkBool hasKey( T key ) const { return isValid(findKey(key)); }
	protected:
		enum
		{
			NUM_ELEMS_MASK = int(0x7FFFFFFF),
			DONT_DEALLOCATE_FLAG = int(0x80000000)
		};
		T* m_elem;
		int m_numElems;
		int m_hashMod;
};

template < typename T >
inline typename hkPointerMapBase<T>::Iterator hkPointerMapBase<T>::getIterator() const
{
	int i;
	for( i = 0; i <= m_hashMod; ++i )
	{
		if( m_elem[i] != T(-1) )
		{
			break;
		}
	}
	return reinterpret_cast<Iterator>( T(i) );
}

template < typename T >
inline T hkPointerMapBase<T>::getValue(Iterator it) const
{
	int i = static_cast<int>( reinterpret_cast<T>(it) );
	return m_elem[i+m_hashMod+1];
}

template < typename T >
inline typename hkPointerMapBase<T>::Iterator hkPointerMapBase<T>::getNext( Iterator it ) const
{
	int i = static_cast<int>( reinterpret_cast<T>(it) );
	for( i += 1; i <= m_hashMod; ++i )
	{
		if( m_elem[i] != T(-1) )
		{
			break;
		}
	}
	return reinterpret_cast<Iterator>( T(i) );
}

template < typename T >
inline hkBool hkPointerMapBase<T>::isValid( Iterator it ) const
{
	int i = static_cast<int>( reinterpret_cast<T>(it) );
	return i <= m_hashMod;
}

template <typename K, typename V>
class hkPointerMap
{
	public:
		                class MustEndWithSemiColon;
		typedef hkPointerMapBase<hkUlong>::Iterator Iterator;
		__forceinline void insert( K key, V val )
		{
			m_map.insert( hkUlong(key), hkUlong(val) );
		}
		__forceinline hkBool hasKey( K key ) const
		{
			return m_map.hasKey( hkUlong(key) );
		}
		Iterator getIterator() const
		{
			return m_map.getIterator();
		}
		V getValue( Iterator i ) const
		{
			return (V)m_map.getValue(i);
		}
		Iterator getNext( Iterator i ) const
		{
			return m_map.getNext(i);
		}
		hkBool isValid( Iterator i ) const
		{
			return m_map.isValid(i);
		}
	protected:
		hkPointerMapBase<hkUlong> m_map;
};

class hkClassEnum;
class hkCustomAttributes;

class hkClassMember
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum Type
		{
			TYPE_VOID = 0,
			TYPE_BOOL,
			TYPE_CHAR,
			TYPE_INT8,
			TYPE_UINT8,
			TYPE_INT16,
			TYPE_UINT16,
			TYPE_INT32,
			TYPE_UINT32,
			TYPE_INT64,
			TYPE_UINT64,
			TYPE_REAL,
			TYPE_VECTOR4,
			TYPE_QUATERNION,
			TYPE_MATRIX3,
			TYPE_ROTATION,
			TYPE_QSTRANSFORM,
			TYPE_MATRIX4,
			TYPE_TRANSFORM,
			TYPE_ZERO,
			TYPE_POINTER,
			TYPE_FUNCTIONPOINTER,
			TYPE_ARRAY,
			TYPE_INPLACEARRAY,
			TYPE_ENUM,
			TYPE_STRUCT,
			TYPE_SIMPLEARRAY,
			TYPE_HOMOGENEOUSARRAY,
			TYPE_VARIANT,
			TYPE_CSTRING,
			TYPE_ULONG,
			TYPE_FLAGS,
			TYPE_MAX
		};
		enum FlagValues
		{
			FLAGS_NONE = 0,
			ALIGN_8 = 128,
            ALIGN_16 = 256,
            NOT_OWNED = 512,
            SERIALIZE_IGNORED = 1024
		};
		typedef hkFlags<FlagValues, hkUint16> Flags;
		enum DeprecatedFlagValues
		{
			DEPRECATED_SIZE_8 = 8,
			DEPRECATED_ENUM_8 = 8,
			DEPRECATED_SIZE_16 = 16,
			DEPRECATED_ENUM_16 = 16,
			DEPRECATED_SIZE_32 = 32,
			DEPRECATED_ENUM_32 = 32
		};
		struct TypeProperties
		{
			hkEnum<hkClassMember::Type,hkUint8> m_type;
			const char* m_name;
			short m_size;
			short m_align;
			                class MustEndWithSemiColon;
		};
	private:
		const char* m_name;
		const hkClass* m_class;
		const hkClassEnum* m_enum;
		hkEnum<Type,hkUint8> m_type;
		hkEnum<Type,hkUint8> m_subtype;
		hkInt16 m_cArraySize;
		Flags m_flags;
		hkUint16 m_offset;
		const hkCustomAttributes* m_attributes;
};

class hkClassEnum
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		class Item
		{
			public:
				                class MustEndWithSemiColon;
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				const char* getName() const { return m_name; }
				int getValue() const { return m_value; }
			private:
				int m_value;
				const char* m_name;
		};
		enum FlagValues
		{
			FLAGS_NONE = 0
		};
		typedef hkFlags<FlagValues, hkUint32> Flags;
		const char* getName() const;
		int getNumItems() const;
		const hkClassEnum::Item& getItem(int i) const;
		inline const Flags& getFlags() const;
	private:
		const char* m_name;
		const class Item* m_items;
		int m_numItems;
		class hkCustomAttributes* m_attributes;
		Flags m_flags;
};

inline const char* hkClassEnum::getName() const
{
 	return m_name;
}

inline int hkClassEnum::getNumItems() const
{
	return m_numItems;
}

inline const hkClassEnum::Item& hkClassEnum::getItem(int i) const
{
	return m_items[i];
}

inline const hkClassEnum::Flags& hkClassEnum::getFlags() const
{
	return m_flags;
}

class hkClass
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		enum SignatureFlags
		{
			SIGNATURE_LOCAL = 1
		};
		enum FlagValues
        {
			FLAGS_NONE = 0,
			FLAGS_NOT_SERIALIZABLE = 1
        };
		typedef hkFlags<FlagValues, hkUint32> Flags;
		const char* getName() const;
		const hkClassEnum& getDeclaredEnum(int i) const;
		int getNumDeclaredEnums() const;
		const hkClassMember& getDeclaredMember(int i) const;
		int getNumDeclaredMembers() const;
		typedef hkPointerMap<const hkClass*, hkInt32> UpdateFlagFromClassMap;
	protected:
		const char* m_name;
		const hkClass* m_parent;
		int m_objectSize;
		int m_numImplementedInterfaces;
		const class hkClassEnum* m_declaredEnums;
		int m_numDeclaredEnums;
		const class hkClassMember* m_declaredMembers;
		int m_numDeclaredMembers;
		const void* m_defaults;
		const hkCustomAttributes* m_attributes;
		Flags m_flags;
		int m_describedVersion;
};

template <typename Operations>
class hkCachedHashMap
{
	public:
		                class MustEndWithSemiColon;
		typedef class Dummy* Iterator;
		hkCachedHashMap(Operations ops = Operations());
		~hkCachedHashMap();
		void insert( hkUlong key, hkUlong val );
	protected:
		hkUlong* m_elem;
		int m_numElems;
		int m_hashMod;
		Operations m_ops;
};

struct hkStringMapOperations
{
};

class hkStringMapBase : public hkCachedHashMap<hkStringMapOperations>
{
};

template <typename V>
class hkStringMap
{
	public:
		                class MustEndWithSemiColon;
		typedef hkStringMapBase::Iterator Iterator;
		__forceinline void insert( const char* key, V val )
		{
			m_map.insert( hkUlong(key), hkUlong(val) );
		}
	protected:
		hkStringMapBase m_map;
};

namespace hkVersionUtil
{
	const char* __cdecl getCurrentVersion();
}

class CollectClassDefinitions
{
public:
	CollectClassDefinitions(const hkArray<const hkClass*>& originalClassList,
							hkPointerMap<const hkClassEnum*, char*>& enumNameFromPointer,
							hkStringMap<hkBool32>& enumDoneFlagFromName);
	const hkString& getClassExternList() const;
	const hkString& getClassDefinitionList() const;
	void defineClassClass(const hkClass& klass);
private:
	const hkClassEnum* m_classMemberEnumType;
	const hkArray<const hkClass*>& m_originalClassList;
	hkString m_classExternList;
	hkString m_classDefinitionList;
	hkPointerMap<const hkClassEnum*, char*>& m_enumNameFromPointer;
	hkStringMap<hkBool32>& m_enumDoneFlagFromName;
	hkStringMap<hkBool32> m_doneClasses;
};

struct hkInternalCustomAttributes
{
	struct Attribute
	{
		const char* m_name;
		const void* m_data;
		const hkClass* m_klass;
		        class MustEndWithSemiColon;
	};
	const Attribute* m_attributes;
	int m_numAttributes;
	        class MustEndWithSemiColon;
};

struct hkInternalClassMember
{
	const char* m_name;
	const hkClass* m_class;
	const hkClassEnum* m_enum;
	hkUint8 m_type;
	hkUint8 m_subtype;
	hkUint16 m_cArraySize;
	hkUint16 m_flags;
	hkUint16 m_offset;
	const hkInternalCustomAttributes* m_attributes;
	        class MustEndWithSemiColon;
};

static const char s_commonHeaders[] =
	"#include <Common/Base/Reflection/hkClass.h>\r\n"
	"#include <Common/Base/Reflection/hkInternalClassMember.h>\r\n"
	"\r\n"
	"#include <Common/Compat/hkHavokAllClasses.h>\r\n"
	"\r\n";

static const char s_namespaceOpen[] = "namespace hkHavok%sClasses\r\n{\r\n";

static const char s_commonForwardDeclaration[] =
	"\textern const char VersionString[];\r\n"
	"\textern const int ClassVersion;\r\n"
	"\textern const hkStaticClassNameRegistry %s;\r\n";

static const char s_namespaceClose[] = "} // namespace hkHavok%sClasses\r\n";
static const char s_enumItemsStart[] = "\tstatic const hkInternalClassEnumItem %sEnumItems[] =\r\n\t{\r\n";
static const char s_enumItemDefinition[] = "\t\t{%d, \"%s\"},\r\n";
static const char s_enumItemsEnd[] = "\t};\r\n";

static const char s_classStaticRegistry[] =
	"\tstatic hkClass* const Classes[] =\r\n"
	"\t{\r\n"
	"%s"
	"\t\tHK_NULL\r\n"
	"\t};\r\n"
	"\r\n"
	"\tconst hkStaticClassNameRegistry %s(Classes, ClassVersion, VersionString);\r\n";

static const char s_enumsStart[] = "\tstatic const hkInternalClassEnum %sEnums[] =\r\n\t{\r\n";
static const char s_enumDefinition[] = "\t\t{\"%s\", %sEnumItems, %d, HK_NULL, %d },\r\n";
static const char s_enumsEnd[] = "\t};\r\n";
static const char s_enumExtern[] = "\textern const hkClassEnum* %sEnum = reinterpret_cast<const hkClassEnum*>(&%sEnums[%d]);\r\n";
static const char s_enumForward[] = "\textern const hkClassEnum* %sEnum;\r\n";

static inline void generateEnum(const char* completeEnumName, const hkClassEnum& classEnum, hkString& outputString)
{
	hkString buffer;
	buffer.printf(s_enumItemsStart, completeEnumName);
	outputString += buffer;
	for( int item = 0; item < classEnum.getNumItems(); ++item )
	{
		const hkClassEnum::Item& enumItem = classEnum.getItem(item);
		buffer.printf(s_enumItemDefinition, enumItem.getValue(), enumItem.getName());
		outputString += buffer;
	}
	outputString += s_enumItemsEnd;
}

template <typename T>
static int getNumElements(T** p)
{
	int i = 0;
	while( *p != 0 )
	{
		++i;
		++p;
	}
	return i;
}

hkResult __cdecl FUN_00940e70(hkOstream& os, const hkClass*const* classesToGenerate, const char* pchfilename, const char* registryVariableName)
{
	if( classesToGenerate == 0 || registryVariableName == 0 )
	{
		return HK_FAILURE;
	}
	if( pchfilename )
	{
		os << "#include <";
		os << pchfilename;
		os << ">\r\n";
	}
	os << s_commonHeaders;
	hkString buffer;
	hkString version = hkString(hkVersionUtil::getCurrentVersion()).replace("Havok", "").replace("-", "").replace(".", "");
	os.printf(s_namespaceOpen, version.cString());
	os.printf(s_commonForwardDeclaration, registryVariableName);
	os << "\r\n";
	int numOfClasses = getNumElements(const_cast<const hkClass**>(classesToGenerate));
	hkArray<const hkClass*> originalClassList(const_cast<const hkClass**>(classesToGenerate), numOfClasses, numOfClasses);
	hkPointerMap<const hkClassEnum*, char*> enumNameFromPointer;
	hkStringMap<hkBool32> enumDoneFlagFromName;
	hkString enumForward;
	int i;
	{
		hkString completeEnumName;
		for( i = 0; i < originalClassList.getSize(); ++i )
		{
			const hkClass& klass = *originalClassList[i];
			for( int e = 0; e < klass.getNumDeclaredEnums(); ++e )
			{
				const hkClassEnum& classEnum = klass.getDeclaredEnum(e);
				if( enumNameFromPointer.hasKey(&classEnum) )
				{
					continue;
				}
				completeEnumName.printf("%s%s", klass.getName(), classEnum.getName());
				enumNameFromPointer.insert(&classEnum, hkString::strDup(completeEnumName.cString()));
				buffer.printf(s_enumForward, completeEnumName.cString());
				enumForward += buffer;
			}
		}
	}
	hkBool32 foundGlobalEnum = false;
	hkString enumItemsDefinitionList;
	hkString enumsDefinitionList;
	hkString enumExtern;
	hkString classExternList;
	hkString classDefinitionList;
	int globalEnumIdx = 0;
	for( i = 0; i < originalClassList.getSize(); ++i )
	{
		const hkClass& klass = *originalClassList[i];
		for( int m = 0; m < klass.getNumDeclaredMembers(); ++m )
		{
			const hkInternalClassMember& mem = reinterpret_cast<const hkInternalClassMember&>(klass.getDeclaredMember(m));
			if( mem.m_enum )
			{
				if( enumNameFromPointer.hasKey(mem.m_enum) )
				{
					continue;
				}
				const hkClassEnum& classEnum = *mem.m_enum;
				char* completeEnumName = hkString::strDup(classEnum.getName());
				enumNameFromPointer.insert(&classEnum, completeEnumName);
				enumDoneFlagFromName.insert(completeEnumName, true);
				if( !foundGlobalEnum )
				{
					foundGlobalEnum = true;
					buffer.printf(s_enumsStart, "");
					enumsDefinitionList += buffer;
				}
				generateEnum(completeEnumName, classEnum, enumItemsDefinitionList);
				buffer.printf(s_enumDefinition, classEnum.getName(), completeEnumName, classEnum.getNumItems(), classEnum.getFlags().get());
				enumsDefinitionList += buffer;
				buffer.printf(s_enumExtern, completeEnumName, "", globalEnumIdx++);
				enumExtern += buffer;
			}
		}
	}
	if( foundGlobalEnum )
	{
		enumsDefinitionList += s_enumsEnd;
		enumsDefinitionList += enumExtern;
		classDefinitionList += enumItemsDefinitionList;
		classDefinitionList += enumsDefinitionList;
	}
	CollectClassDefinitions classDef(originalClassList, enumNameFromPointer, enumDoneFlagFromName);
	for( int i = 0; i < originalClassList.getSize(); ++i )
	{
		classDef.defineClassClass(*originalClassList[i]);
	}
	os << classDef.getClassExternList().cString();
	os << "\r\n";
	if( enumForward.getLength() > 0 )
	{
		os << enumForward.cString();
		os << "\r\n";
	}
	os << classDef.getClassDefinitionList().cString();
	classDefinitionList = "";
	for( int i = 0; i < originalClassList.getSize(); ++i )
	{
		buffer.printf("\t\t&%sClass,\r\n", originalClassList[i]->getName());
		classDefinitionList += buffer;
	}
	os.printf(s_classStaticRegistry, classDefinitionList.cString(), registryVariableName);
	os.printf(s_namespaceClose, version.cString());
	hkPointerMap<const hkClassEnum*, char*>::Iterator iter = enumNameFromPointer.getIterator();
	while( enumNameFromPointer.isValid(iter) )
	{
		char* enumName = enumNameFromPointer.getValue(iter);
		hkDeallocate(enumName);
		iter = enumNameFromPointer.getNext(iter);
	}
	return HK_SUCCESS;
}
}
