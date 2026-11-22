// src/f3staging/f3blk_00960000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00970580 (community match, verified in this file)
#include <math.h>

template <typename T>
class PaddedScalar
{
public:
    __forceinline void operator=(T val) { m_storage = val; }
    __forceinline operator T() const { return m_storage; }
    __forceinline T val() const { return m_storage; }

private:
    T m_storage;
};

class Vec4Comparison
{
public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_ZW = 3,
        MASK_Y = 4,
        MASK_YW = 5,
        MASK_YZ = 6,
        MASK_YZW = 7,
        MASK_X = 8,
        MASK_XW = 9,
        MASK_XZ = 10,
        MASK_XZW = 11,
        MASK_XY = 12,
        MASK_XYW = 13,
        MASK_XYZ = 14,
        MASK_XYZW = 15
    };

    int allAreSet(Mask m) const { return (m_mask & m) == m; }
    int getMask() const { return m_mask; }
    int getMask(Mask m) const { return m_mask & m; }

private:
    int m_mask;
    friend class Vec4;
};

class Vec4
{
public:
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }

    __forceinline void operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    __forceinline void setAdd4(const Vec4& v0, const Vec4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }

    __forceinline void setSub4(const Vec4& v0, const Vec4& v1)
    {
        x = (float)(v0.x - v1.x);
        y = (float)(v0.y - v1.y);
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    __forceinline void setAddMul4(const Vec4& a, const Vec4& b, float r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }

    __forceinline void mul4(float rs)
    {
        float s = float(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }

    __forceinline void setMul4(float rs, const Vec4& a)
    {
        float r = float(rs);
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }

    __forceinline void setCross(const Vec4& v1, const Vec4& v2)
    {
        const float nx = v1(1) * v2(2) - v1(2) * v2(1);
        const float ny = v1(2) * v2(0) - v1(0) * v2(2);
        const float nz = v1(0) * v2(1) - v1(1) * v2(0);
        this->set(nx, ny, nz, 0.0f);
    }

    __forceinline Vec4Comparison compareLessThan4(const Vec4& a) const
    {
        Vec4Comparison ret;
        ret.m_mask =
            ((x < a.x) ? Vec4Comparison::MASK_X : 0) |
            ((y < a.y) ? Vec4Comparison::MASK_Y : 0) |
            ((z < a.z) ? Vec4Comparison::MASK_Z : 0) |
            ((w < a.w) ? Vec4Comparison::MASK_W : 0);
        return ret;
    }

    __forceinline void setNeg4(const Vec4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }

    __forceinline float dot3(const Vec4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }

    __forceinline float length3() const
    {
        return sqrtf((x * x) + (y * y) + (z * z));
    }

    __forceinline float lengthSquared3() const
    {
        return this->dot3(*this);
    }

    __forceinline float normalizeWithLength3()
    {
        const float len = this->length3();
        const float invLen = (1.0f) / len;
        this->mul4(invLen);
        return len;
    }

    static __forceinline const Vec4& __fastcall getZero()
    {
        extern Vec4 g_zeroVec;
        return g_zeroVec;
    }

private:
    __declspec(align(16)) float x;
    float y;
    float z;
    float w;
};

static inline float __fastcall calcSqrtInverse(float r)
{
    return 1.0f / sqrtf(r);
}

struct LineSegResult
{
    Vec4 m_pointOnEdge;
};

__declspec(noinline) int __cdecl FUN_0096fa60(const Vec4& A, const Vec4& B, const Vec4& B2, LineSegResult& result)
{
    Vec4 d12;
    d12.setSub4(A, B);
    Vec4 dB;
    dB.setSub4(B2, B);

    float S2 = dB.dot3(d12);
    float D2 = dB.dot3(dB);

    if (S2 <= 0.0f)
    {
        result.m_pointOnEdge = B;
        return 8;
    }
    else if (S2 >= D2)
    {
        result.m_pointOnEdge.setAdd4(B, dB);
        return 4;
    }
    else
    {
        S2 = S2 / D2;
        result.m_pointOnEdge.setAddMul4(B, dB, S2);
        return 0;
    }
}

struct ClosestPointTriangleCache
{
    float m_QQ;
    float m_RR;
    float m_QR;
    float m_invTriNormal;
};

struct ClosestPointTriangleResult
{
    Vec4 hitDirection;
    PaddedScalar<float> distance;
};

enum ClosestPointTriangleStatus
{
    HIT_TRIANGLE_FACE = 0,
    HIT_TRIANGLE_EDGE = 1
};

extern const signed char DAT_00e7c768[16];
extern const signed char DAT_00e7c778[4];

static inline int __fastcall getNextModulo3(int i) { return DAT_00e7c778[i + 2]; }
static inline int __fastcall getPrevModulo3(int i) { return DAT_00e7c778[i]; }

// pdb: hkpCollideTriangleUtil::closestPointTriangle | hkpCollideTriangleUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
ClosestPointTriangleStatus __cdecl hkpCollideTriangleUtil_closestPointTriangle(
    const Vec4& position,
    const Vec4* tri,
    const ClosestPointTriangleCache& cache,
    ClosestPointTriangleResult& result)
{
    Vec4 relPos;
    relPos.setSub4(tri[1], position);
    Vec4 Q;
    Q.setSub4(tri[0], tri[1]);
    float sq = relPos.dot3(Q);
    Vec4 R;
    R.setSub4(tri[2], tri[1]);
    float sr = relPos.dot3(R);

    float q = (sr * cache.m_QR) - (cache.m_RR * sq);
    float r = (sq * cache.m_QR) - (cache.m_QQ * sr);

    const float relEps = 1e-3f;

    Vec4 proj;
    proj(0) = (float)(q + relEps);
    proj(1) = 1.0f + relEps - q - r;
    proj(2) = r + relEps;
    proj(3) = relEps;

    Vec4Comparison mask = Vec4::getZero().compareLessThan4(proj);
    if (mask.allAreSet(Vec4Comparison::MASK_XYZ))
    {
        result.hitDirection.setCross(Q, R);
        result.hitDirection.mul4(cache.m_invTriNormal);
        result.distance = result.hitDirection.dot3(relPos);
        if (result.distance > 0.0f)
        {
            result.hitDirection.setNeg4(result.hitDirection);
        }
        else
        {
            result.distance = -result.distance;
        }
        return HIT_TRIANGLE_FACE;
    }

    int index = DAT_00e7c768[mask.getMask(Vec4Comparison::MASK_XYZ)];
    if (index < 0)
    {
        index += 8;
        LineSegResult cpls;
        FUN_0096fa60(position, tri[getNextModulo3(index)], tri[getPrevModulo3(index)], cpls);

        result.hitDirection.setSub4(position, cpls.m_pointOnEdge);
        result.distance = result.hitDirection.normalizeWithLength3();
    }
    else
    {
        LineSegResult cplsA;
        FUN_0096fa60(position, tri[index], tri[getNextModulo3(index)], cplsA);

        LineSegResult cplsB;
        FUN_0096fa60(position, tri[getPrevModulo3(index)], tri[index], cplsB);

        Vec4 t0;
        t0.setSub4(position, cplsA.m_pointOnEdge);
        Vec4 t1;
        t1.setSub4(position, cplsB.m_pointOnEdge);
        float distA = t0.lengthSquared3();
        float distB = t1.lengthSquared3();

        if (distA < distB)
        {
            float inv = calcSqrtInverse(distA);
            result.distance = distA * inv;
            result.hitDirection.setMul4(inv, t0);
        }
        else
        {
            float inv = calcSqrtInverse(distB);
            result.distance = distB * inv;
            result.hitDirection.setMul4(inv, t1);
        }
    }
    return HIT_TRIANGLE_EDGE;
}

// @f3 0x0096fee0 (community match, verified in this file)
namespace f3m_0096fee0 {
struct S0096fee0_TriCache
{
    float m_invEdgeLen[3];
    float m_invTriNormal;
    float m_normalOffset;
};

struct S0096fee0_Matrix4
{
    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;
    Vec4 m_col3;
};

template <typename T>
__forceinline void S0096fee0_swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

// pdb: hkpCollideTriangleUtil::calcTrianglePlaneDirections | hkpCollideTriangleUtil.obj | tesv_win, objrun, medium
void __cdecl FUN_0096fee0(const Vec4* tri, const S0096fee0_TriCache& cache, S0096fee0_Matrix4& planeEquationsOut, Vec4& normalOut)
{
    Vec4 E0;
    E0.setSub4(tri[2], tri[1]);
    Vec4 E1;
    E1.setSub4(tri[0], tri[2]);
    Vec4 E2;
    E2.setSub4(tri[1], tri[0]);

    Vec4 n;
    n.setCross(E0, E1);
    n.mul4(cache.m_invTriNormal);
    normalOut = n;

    E0.mul4(cache.m_invEdgeLen[0]);
    E1.mul4(cache.m_invEdgeLen[1]);
    E2.mul4(cache.m_invEdgeLen[2]);

    planeEquationsOut.m_col0.setCross(E0, n);
    planeEquationsOut.m_col1.setCross(E1, n);
    planeEquationsOut.m_col2.setCross(E2, n);

    S0096fee0_swap(planeEquationsOut.m_col1(0), planeEquationsOut.m_col0(1));
    S0096fee0_swap(planeEquationsOut.m_col2(0), planeEquationsOut.m_col0(2));
    S0096fee0_swap(planeEquationsOut.m_col2(1), planeEquationsOut.m_col1(2));

    planeEquationsOut.m_col0(3) = normalOut(0);
    planeEquationsOut.m_col1(3) = normalOut(1);
    planeEquationsOut.m_col2(3) = normalOut(2);

    planeEquationsOut.m_col3(0) = planeEquationsOut.m_col3(1) = planeEquationsOut.m_col3(2) = planeEquationsOut.m_col3(3) = 0.0f;
    planeEquationsOut.m_col3(0) = -cache.m_invEdgeLen[0] * cache.m_normalOffset;
}
}   // namespace f3m_0096fee0

// @f3 0x0096de30 (community match, verified in this file)
struct S0096de30_Scales
{
    float m_edge0;
    float m_edge1;
    float m_edge2;
    float m_normal;
    float m_unk10;
};

struct S0096de30_Matrix4
{
    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;
    Vec4 m_col3;
};

template <typename T>
static __forceinline void S0096de30_swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

// pdb: hkCollideCapsuleUtil_calcTrianglePlaneDirections | hkpCollideCapsuleUtil.obj | tesv_win, objrun, medium
static __declspec(noinline) void FUN_0096de30(const Vec4* tri, Vec4& plane, const S0096de30_Scales& s, S0096de30_Matrix4& m)
{
    Vec4 e0;
    e0.setSub4(tri[2], tri[1]);
    Vec4 e1;
    e1.setSub4(tri[0], tri[2]);
    Vec4 e2;
    e2.setSub4(tri[1], tri[0]);

    Vec4 n;
    n.setCross(e0, e1);
    n.mul4(s.m_normal);
    plane = n;

    e0.mul4(s.m_edge0);
    e1.mul4(s.m_edge1);
    e2.mul4(s.m_edge2);

    m.m_col0.setCross(e0, n);
    m.m_col1.setCross(e1, n);
    m.m_col2.setCross(e2, n);

    S0096de30_swap(m.m_col1(0), m.m_col0(1));
    S0096de30_swap(m.m_col2(0), m.m_col0(2));
    S0096de30_swap(m.m_col2(1), m.m_col1(2));

    m.m_col0(3) = plane(0);
    m.m_col1(3) = plane(1);
    m.m_col2(3) = plane(2);
    m.m_col3(3) = 0.0f;
    m.m_col3(2) = 0.0f;
    m.m_col3(1) = 0.0f;
    m.m_col3(0) = 0.0f;
    m.m_col3(0) = s.m_unk10 * -s.m_edge0;
}

extern Vec4* volatile g_S0096de30_tri;
extern S0096de30_Scales* volatile g_S0096de30_scales;
extern Vec4* volatile g_S0096de30_plane;
extern S0096de30_Matrix4* volatile g_S0096de30_m;

void S0096de30_caller()
{
    FUN_0096de30(g_S0096de30_tri, *g_S0096de30_plane, *g_S0096de30_scales, *g_S0096de30_m);
}

// @f3 0x009644a0 (community match, verified in this file)
namespace f3m_009644a0 {
class S009644a0_Bool
{
public:
    S009644a0_Bool(bool b) { m_bool = (char)b; }
    char m_bool;
};

static __forceinline void S009644a0_setAbs4(Vec4& v)
{
    v(0) = fabsf(v(0));
    v(1) = fabsf(v(1));
    v(2) = fabsf(v(2));
    v(3) = fabsf(v(3));
}

static __forceinline int S009644a0_lessEqualMask(const Vec4& v, float eps)
{
    return ((v(0) <= eps) ? Vec4Comparison::MASK_X : 0) |
           ((v(1) <= eps) ? Vec4Comparison::MASK_Y : 0) |
           ((v(2) <= eps) ? Vec4Comparison::MASK_Z : 0) |
           ((v(3) <= eps) ? Vec4Comparison::MASK_W : 0);
}

static __forceinline bool S009644a0_equals3(const Vec4& a, const Vec4& b, float eps)
{
    Vec4 diff;
    diff.setSub4(a, b);
    S009644a0_setAbs4(diff);
    return (S009644a0_lessEqualMask(diff, eps) & Vec4Comparison::MASK_XYZ) == Vec4Comparison::MASK_XYZ;
}

static __forceinline bool S009644a0_equals4(const Vec4& a, const Vec4& b, float eps)
{
    Vec4 diff;
    diff.setSub4(a, b);
    S009644a0_setAbs4(diff);
    return (S009644a0_lessEqualMask(diff, eps) & Vec4Comparison::MASK_XYZW) == Vec4Comparison::MASK_XYZW;
}

class S009644a0_QsTransform
{
public:
    S009644a0_Bool FUN_009644a0(const S009644a0_QsTransform& other, float epsilon) const;

    Vec4 m_translation;
    Vec4 m_rotation;
    Vec4 m_scale;
};

S009644a0_Bool S009644a0_QsTransform::FUN_009644a0(const S009644a0_QsTransform& other, float epsilon) const
{
    if (!S009644a0_equals3(m_translation, other.m_translation, epsilon))
    {
        return false;
    }
    if (!S009644a0_equals3(m_scale, other.m_scale, epsilon))
    {
        return false;
    }
    Vec4 q1;
    q1 = m_rotation;
    Vec4 q2;
    q2 = other.m_rotation;
    if (q1(3) * q2(3) < 0.0)
    {
        q1(0) = q1(0) * -1.0;
        q1(1) = q1(1) * -1.0;
        q1(2) = q1(2) * -1.0;
        q1(3) = q1(3) * -1.0;
    }
    return S009644a0_equals4(q1, q2, epsilon);
}
}   // namespace f3m_009644a0

// @f3 0x0096ae60 (community match, verified in this file)
struct S96ae60_Input
{
    float m00;
    Vec4 m10;
    Vec4 m20;
    Vec4 m30;
    Vec4 m40;
    Vec4 m50;
    float m60;
    Vec4 m70;
};

struct S96ae60_Timer
{
    int unk00;
    int unk04;
    float m08;
};

struct S96ae60_Owner
{
    S96ae60_Timer* FUN_0091dd60();
};

struct S96ae60_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Vec4 m10;
};

extern S96ae60_Timer g_S96ae60_timer;

void __cdecl FUN_00a062a0(S96ae60_Input* input, Vec4* velocity);

static __forceinline void S96ae60_mul4(Vec4& v, float s)
{
    v(0) = v(0) * s;
    v(1) = v(1) * s;
    v(2) = v(2) * s;
    v(3) = v(3) * s;
}

static __forceinline void S96ae60_addMul4(Vec4& v, float rs, const Vec4& a)
{
    float r = float(rs);
    v(0) += r * a(0);
    v(1) += r * a(1);
    v(2) += r * a(2);
    v(3) += r * a(3);
}

struct S96ae60_CtrlBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual S96ae60_Node* GetNode();

    int unk004;
    S96ae60_Owner* m08;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    unsigned int m294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
};

struct S96ae60_Ctrl : S96ae60_CtrlBase
{
    void FUN_008e8900();

    Vec4 v2d0;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    Vec4 v320;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    float f340;
    float f344;
    float f348;
    int unk34c;
    int m350;
    int unk354;
    int unk358;
    int unk35c;
    Vec4 v360;
    Vec4 v370;
    int unk380;
    int unk384;
    float f388;
    int unk38c;
    Vec4 v390;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    float f3c0;
    int unk3c4;
    float f3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    float f3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    float f408;
};

void __stdcall FUN_0096ae60(S96ae60_Ctrl* ctrl)
{
    S96ae60_Input input;
    input.m00 = ctrl->f3c0;
    input.m10 = ctrl->v370;
    input.m20 = ctrl->v360;
    input.m40 = ctrl->v390;
    input.m50.set(ctrl->f344, ctrl->f340, ctrl->f348);
    input.m60 = 20.0f;
    input.m70 = ctrl->v320;
    if ((unsigned char)(ctrl->m294 >> 8) & 1)
        input.m30 = ctrl->v2d0;
    else
        input.m30 = ctrl->v360;
    FUN_00a062a0(&input, &ctrl->v390);

    float dt = (float)(ctrl->f408 * (double)0.9f);
    S96ae60_Timer* timer = ctrl->m08 ? ctrl->m08->FUN_0091dd60() : &g_S96ae60_timer;
    if (timer->m08 + dt > ctrl->f3c8)
    {
        if (ctrl->v390(2) > 0.0f)
            ctrl->v390(2) = 0.0f;
        Vec4 up;
        ctrl->GetNode();
        up = ctrl->GetNode()->m10;
        ctrl->GetNode();
        float s = ctrl->f3d8;
        S96ae60_mul4(up, s);
        S96ae60_addMul4(ctrl->v390, ctrl->f388, up);
    }
    if (ctrl->m350 != 11 && ctrl->m350 == 0)
    {
        ctrl->FUN_008e8900();
        Vec4 up;
        ctrl->GetNode();
        up = ctrl->GetNode()->m10;
        ctrl->GetNode();
        float s = ctrl->f3d8;
        S96ae60_mul4(up, s);
        S96ae60_addMul4(ctrl->v390, (float)(-ctrl->f388 * 3.0), up);
    }
}

// @f3 0x00977e70 (community match, verified in this file)
namespace f3m_00977e70 {



struct S977e_Quat
{
    Vec4 m_vec;
};

struct S977e_Rotation
{
    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;

    void set(const S977e_Quat& q);
};

struct S977e_Transform
{
    S977e_Rotation m_rotation;
    Vec4 m_translation;
};

struct S977e_SweptTransform
{
    Vec4 m_centerOfMass0;
    Vec4 m_centerOfMass1;
    S977e_Quat m_rotation0;
    S977e_Quat m_rotation1;
    Vec4 m_centerOfMassLocal;
};

struct S977e_MotionState
{
    S977e_Transform m_transform;
    S977e_SweptTransform m_sweptTransform;
    Vec4 m_deltaAngle;
};

static __forceinline void S977e_setRotatedDir(Vec4& out, const S977e_Rotation& r, const Vec4& b)
{
    const float v0 = b(0);
    const float v1 = b(1);
    const float v2 = b(2);
    out(0) = r.m_col0(0) * v0 + r.m_col1(0) * v1 + r.m_col2(0) * v2;
    out(1) = r.m_col0(1) * v0 + r.m_col1(1) * v1 + r.m_col2(1) * v2;
    out(2) = r.m_col0(2) * v0 + r.m_col1(2) * v1 + r.m_col2(2) * v2;
    out(3) = 0.0f;
}

// pdb: hkSweptTransformUtil::warpTo | hkSweptTransformUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: position, rotation, ms
void __cdecl FUN_00977e70(const Vec4& position, const S977e_Quat& rotation, S977e_MotionState& ms)
{
    S977e_SweptTransform& sweptTransform = ms.m_sweptTransform;
    ms.m_deltaAngle(3) = 0.0f;
    ms.m_deltaAngle(2) = 0.0f;
    ms.m_deltaAngle(1) = 0.0f;
    ms.m_deltaAngle(0) = 0.0f;

    sweptTransform.m_rotation0 = rotation;
    sweptTransform.m_rotation1 = rotation;
    ms.m_transform.m_rotation.set(rotation);
    ms.m_transform.m_translation = position;

    Vec4 centerShift;
    S977e_setRotatedDir(centerShift, ms.m_transform.m_rotation, sweptTransform.m_centerOfMassLocal);

    const float baseTime = sweptTransform.m_centerOfMass0(3);
    sweptTransform.m_centerOfMass0.setAdd4(position, centerShift);
    sweptTransform.m_centerOfMass1 = sweptTransform.m_centerOfMass0;

    sweptTransform.m_centerOfMass0(3) = baseTime;
    sweptTransform.m_centerOfMass1(3) = 0.0f;
}
}   // namespace f3m_00977e70

// @f3 0x009792a0 (community match, verified in this file)
namespace f3m_009792a0 {
namespace c4_009792a0 {

static __forceinline void SetAbs4(Vec4& v)
{
    v(0) = fabsf(v(0));
    v(1) = fabsf(v(1));
    v(2) = fabsf(v(2));
    v(3) = fabsf(v(3));
}

static __forceinline int LessEqualMask(const Vec4& v, float eps)
{
    return ((v(0) <= eps) ? Vec4Comparison::MASK_X : 0) |
           ((v(1) <= eps) ? Vec4Comparison::MASK_Y : 0) |
           ((v(2) <= eps) ? Vec4Comparison::MASK_Z : 0) |
           ((v(3) <= eps) ? Vec4Comparison::MASK_W : 0);
}

bool __cdecl FUN_009792a0(const Vec4& a, const Vec4& b)
{
    Vec4 diff;
    diff.setSub4(a, b);
    SetAbs4(diff);
    return (LessEqualMask(diff, 0.001f) & Vec4Comparison::MASK_XYZW) == Vec4Comparison::MASK_XYZW;
}

}
}   // namespace f3m_009792a0

// @f3 0x009769e0 (community match, verified in this file)
namespace f3m_009769e0 {
namespace c4_009769e0 {

struct Matrix3
{
    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;

    void setZero()
    {
        m_col0.set(0.0f, 0.0f, 0.0f, 0.0f);
        m_col1.set(0.0f, 0.0f, 0.0f, 0.0f);
        m_col2.set(0.0f, 0.0f, 0.0f, 0.0f);
    }
};

struct MassProperties
{
    float m_volume;
    float m_mass;
    Vec4 m_centerOfMass;
    Matrix3 m_inertiaTensor;

    MassProperties() : m_volume(0.0f), m_mass(0.0f)
    {
        m_centerOfMass(3) = 0.0f;
        m_centerOfMass(2) = 0.0f;
        m_centerOfMass(1) = 0.0f;
        m_centerOfMass(0) = 0.0f;
        m_inertiaTensor.setZero();
    }
};

struct Shape;

struct BodyInfo
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
    Matrix3 m_inertiaTensor;
    Vec4 m_centerOfMass;
    float m_mass;
};

void __cdecl FUN_009768c0(const Shape* shape, float mass, MassProperties& result);

void __cdecl FUN_009769e0(const Shape* shape, float mass, BodyInfo& bodyInfo)
{
    MassProperties result;
    FUN_009768c0(shape, mass, result);
    bodyInfo.m_mass = result.m_mass;
    bodyInfo.m_centerOfMass = result.m_centerOfMass;
    bodyInfo.m_inertiaTensor = result.m_inertiaTensor;
}

}
}   // namespace f3m_009769e0

// @f3 0x0097df50 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d25c[];
extern const char DAT_00e32798[];
namespace f3m_0097df50 {
namespace f3m_0097df50 {
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

struct Command { const char* name; unsigned int ticks; unsigned int unk08; 
    // hkMonitorStream::TimerCommand::setTime (class and member names: FNV360_PDB)
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int time; __asm { rdtsc
        mov time, eax } ticks = time; }
};
struct Stream { unsigned int unk00; Command* cursor; unsigned int unk08; Command* limit; };

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void hkVector4_setRotatedDir(const struct Rotation& r, const Vec4& v);
    __forceinline void setRotInv(const struct Rotation& r, const Vec4& d);
    __forceinline void setRotInvF(const struct Rotation& r, float dx, float dy, float dz);
    __forceinline void setTInvPos(const struct Transform& a, const Vec4& b);
    __forceinline void setTInvPos2(const struct Transform& a, const Vec4& b) ;
};

struct Rotation { Vec4 c0, c1, c2; };
struct Transform { Rotation r; Vec4 t; };

struct RayInput {
    Vec4 from;
    Vec4 to;
    unsigned int unk20, unk24, unk28, unk2c;
};

struct RayOutput {
    Vec4 normal;
    float hitFraction;
    int extraInfo;
    unsigned int unk18, unk1c;
    unsigned int keys[8];
    int keyIndex;
};

struct Bool { char b; Bool() {} Bool(bool v) : b(v) {} };

struct Shape {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual Bool CastRay(const RayInput& input, RayOutput& out);
};

struct TransformShape {
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Shape* child;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    Transform xf;
    Bool hkpTransformShape_castRayImpl(const RayInput& input, RayOutput& out);
};

__forceinline void InvPos(Vec4& out, const Transform& a, const Vec4& b)
{
    float dx = b.x - a.t.x;
    float dy = b.y - a.t.y;
    float dz = b.z - a.t.z;
    out.x = a.r.c0.x * dx + a.r.c0.y * dy + a.r.c0.z * dz;
    out.y = a.r.c1.x * dx + a.r.c1.y * dy + a.r.c1.z * dz;
    out.z = a.r.c2.x * dx + a.r.c2.y * dy + a.r.c2.z * dz;
    out.w = 0.0f;
}

__forceinline void InvPos2(Vec4& out, const Transform& a, const Vec4& b)
{
    float dx = b.x - a.t.x;
    float dy = b.y - a.t.y;
    float dz = b.z - a.t.z;
    out.x = a.r.c0.x * dx + a.r.c0.y * dy + a.r.c0.z * dz;
    out.y = a.r.c1.x * dx + (a.r.c1.y * dy + a.r.c1.z * dz);
    out.z = a.r.c2.x * dx + (a.r.c2.y * dy + a.r.c2.z * dz);
    out.w = 0.0f;
}

__forceinline void Vec4::setRotInv(const Rotation& r, const Vec4& d)
{
    float dx = d.x, dy = d.y, dz = d.z;
    x = r.c0.x * dx + r.c0.y * dy + r.c0.z * dz;
    y = r.c1.x * dx + r.c1.y * dy + r.c1.z * dz;
    z = r.c2.x * dx + r.c2.y * dy + r.c2.z * dz;
    w = 0.0f;
}
__forceinline void Vec4::setRotInvF(const Rotation& r, float dx, float dy, float dz)
{
    x = r.c0.x * dx + r.c0.y * dy + r.c0.z * dz;
    y = r.c1.x * dx + r.c1.y * dy + r.c1.z * dz;
    z = r.c2.x * dx + r.c2.y * dy + r.c2.z * dz;
    w = 0.0f;
}
__forceinline void Vec4::setTInvPos(const Transform& a, const Vec4& b)
{
    float dx = b.x - a.t.x;
    float dy = b.y - a.t.y;
    float dz = b.z - a.t.z;
    x = a.r.c0.x * dx + a.r.c0.y * dy + a.r.c0.z * dz;
    y = a.r.c1.x * dx + a.r.c1.y * dy + a.r.c1.z * dz;
    z = a.r.c2.x * dx + a.r.c2.y * dy + a.r.c2.z * dz;
    w = 0.0f;
}
__forceinline void Vec4::setTInvPos2(const Transform& a, const Vec4& b)
{
    setRotInvF(a.r, b.x - a.t.x, b.y - a.t.y, b.z - a.t.z);
}
__forceinline void InvPos3(Vec4& out, const Transform& a, const Vec4& b)
{
    out.setRotInvF(a.r, b.x - a.t.x, b.y - a.t.y, b.z - a.t.z);
}

// pdb: hkpTransformShape::castRayImpl | hkpTransformShape.obj | fnv360_0822_retail, objopen_prop + bridge(caller_sim|vtable) + skyrim(caller_sim), high
Bool TransformShape::hkpTransformShape_castRayImpl(const RayInput& input, RayOutput& out)
{

    Stream* s = (Stream*)FUN_00d9b080(DAT_0116913c);
    Command* c = s->cursor;
    if (c < s->limit) {
        c->name = DAT_00e7d25c;
        c->setTime();
        s->cursor = c + 1;
    }
    RayInput sub = input;
    InvPos(sub.from, xf, input.from);
    sub.to.setTInvPos2(xf, input.to);
    out.keyIndex++;
    Bool hit = child->CastRay(sub, out);
    out.keyIndex--;
    if (hit.b) {
        Vec4 n = out.normal;
        out.normal.hkVector4_setRotatedDir(xf.r, n);
        out.keys[out.keyIndex] = 0;
    }
    Stream* s2 = (Stream*)FUN_00d9b080(DAT_0116913c);
    Command* c2 = s2->cursor;
    if (c2 < s2->limit) {
        c2->name = DAT_00e32798;
        c2->setTime();
        s2->cursor = c2 + 1;
    }
    return hit;
}

}
}   // namespace f3m_0097df50

// @f3 0x0097de00 (community match, verified in this file)
namespace f3m_0097de00 {
namespace f3m_0097de00 {

struct hkTransform
{
    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;
    Vec4 m_translation;
};

static __forceinline void setTransformedPos(Vec4& out, const hkTransform& t, const Vec4& v)
{
    const float b0 = v(0);
    const float b1 = v(1);
    const float b2 = v(2);
    out(0) = t.m_col0(0) * b0 + t.m_col1(0) * b1 + t.m_col2(0) * b2 + t.m_translation(0);
    out(1) = t.m_col0(1) * b0 + t.m_col1(1) * b1 + t.m_col2(1) * b2 + t.m_translation(1);
    out(2) = t.m_col0(2) * b0 + t.m_col1(2) * b1 + t.m_col2(2) * b2 + t.m_translation(2);
}

class hkpShape
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual float getMaximumProjection(const Vec4& direction) const;
    int m_memSizeAndFlags;
    int m_userData;
    int m_type;
};

struct hkpSingleShapeContainer
{
    void* m_vtable;
    const hkpShape* m_childShape;
};

class hkpTransformShape : public hkpShape
{
public:
    hkpSingleShapeContainer m_childShape;
    int m_childShapeSize;
    int m_unk1c;
    Vec4 m_rotation;
    hkTransform m_transform;

    float FUN_0097de00(const Vec4& direction) const;
};

// pdb: hkpTransformShape::getMaximumProjection | hkpTransformShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: direction
float hkpTransformShape::FUN_0097de00(const Vec4& direction) const
{
    Vec4 localDir;
    const float x = direction(0);
    const float y = direction(1);
    const float z = direction(2);
    localDir(0) = m_transform.m_col0(0) * x + m_transform.m_col0(1) * y + m_transform.m_col0(2) * z;
    localDir(1) = m_transform.m_col1(0) * x + m_transform.m_col1(1) * y + m_transform.m_col1(2) * z;
    localDir(2) = m_transform.m_col2(0) * x + m_transform.m_col2(1) * y + m_transform.m_col2(2) * z;
    localDir(3) = 0.0f;
    const float localProjection = m_childShape.m_childShape->getMaximumProjection(localDir);
    Vec4 localPoint;
    localPoint.setMul4(localProjection, localDir);
    Vec4 globalPoint;
    setTransformedPos(globalPoint, m_transform, localPoint);
    return globalPoint.dot3(direction);
}

}
}   // namespace f3m_0097de00

// @f3 0x0096cac0 (community match, verified in this file)
extern const double DAT_00e7c750;
extern const float DAT_00e7c74c;
namespace f3m_0096cac0 {
namespace f3m_0096cac0
{

struct Matrix3
{
    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;
    Vec4& getColumn(int i)
    {
        return (&m_col0)[i];
    }
};

struct Rotation : Matrix3
{
    void FUN_0096cac0();
};
}

// pdb: hkMatrix3::invertSymmetric | hkMatrix3.obj | tesv_win, call_seq, medium
void f3m_0096cac0::Rotation::FUN_0096cac0()
{
    Matrix3& m = *this;
    Vec4 r0;
    r0.setCross(m.getColumn(1), m.getColumn(2));
    Vec4 r1;
    r1.setCross(m.getColumn(2), m.getColumn(0));
    Vec4 r2;
    r2.setCross(m.getColumn(0), m.getColumn(1));
    float det = m.getColumn(0).dot3(r0);
    if (det < DAT_00e7c750)
        det = DAT_00e7c74c;
    float invDet = 1.0f / det;
    m.getColumn(0).setMul4(invDet, r0);
    m.getColumn(1).setMul4(invDet, r1);
    m.getColumn(2).setMul4(invDet, r2);
}
}   // namespace f3m_0096cac0

// @f3 0x0096ba00 (community match, verified in this file)
// Jumping state Update: swing the character's up-row and drive the jump lift.

#include <math.h>

namespace f3m_0096ba00 {

struct TimerRow
{
    float m00;
    float m04;
    float m08;
    float m0c;
};

struct TimerOwner
{
    TimerRow* FUN_0091dda0();
};

struct Ctrl
{
    void FUN_008ea1f0(Vec4* v);
};

struct Mod;

struct ModHolder
{
    Mod* FUN_0092f420(int index);
};

struct Mod
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20(void* owner);
};

} // namespace f3m_0096ba00

extern f3m_0096ba00::TimerRow DAT_01092a50;
extern const double FUN_00db88e8;

static __forceinline void M96c(Vec4& v, float rs)
{
    float s = float(rs);
    v(0) = v(0) * s;
    v(1) = v(1) * s;
    v(2) = v(2) * s;
    v(3) = v(3) * s;
}
void __stdcall FUN_0096ba00(S96ae60_Ctrl* ctrl)
{
    if (ctrl->m350 != 11 && (ctrl->m350 == 0 || ctrl->m350 == 3))
    {
        ctrl->FUN_008e8900();
        return;
    }
    *(volatile unsigned int*)&ctrl->m294 |= 0x2000;
    Vec4 up;
    ctrl->GetNode();
    up = ctrl->GetNode()->m10;
    ctrl->GetNode();
    float s = ctrl->f3d8;
    S96ae60_mul4(up, s);
    float len = up.length3();
    float invLen = 1.0f / len;
    M96c(up, invLen);
    float k = 2.0f * len * fabsf(*(float*)&ctrl->unk3cc);
    float ang = sqrtf(k);
    S96ae60_mul4(up, -ang);
    f3m_0096ba00::TimerRow* timer = ctrl->m08
        ? ((f3m_0096ba00::TimerOwner*)ctrl->m08)->FUN_0091dda0()
        : &DAT_01092a50;
    Vec4 v;
    v(0) = timer->m00;
    v(1) = timer->m04;
    v(3) = timer->m0c;
    ctrl->v390(0) = v(0) + up(0);
    ctrl->v390(1) = v(1) + up(1);
    ctrl->v390(2) = up(2) + 0.0;
    ctrl->v390(3) = v(3) + up(3);
    ((f3m_0096ba00::Ctrl*)ctrl)->FUN_008ea1f0(&v);
    *(float*)&ctrl->unk3d0 = (float)(v(2) * FUN_00db88e8);
    ctrl->m350 = 2;
    ctrl->FUN_008e8900();
    *(volatile unsigned int*)&ctrl->m294 &= 0xFFFDFEFF;
    f3m_0096ba00::Mod* mod = ((f3m_0096ba00::ModHolder*)ctrl->unk26c)->FUN_0092f420(ctrl->unk270);
    mod->v20(ctrl);
}

// @f3 0x0096c050 (community match, verified in this file)
extern const double DAT_00db88e8;
extern float DAT_00e7c748;
extern float DAT_00dc2148;
namespace f3m_0096c050 {
namespace f3m_0096c050 {


struct Mod
{
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(S96ae60_Ctrl* ctrl);
};
struct ModHolder { Mod* FUN_0092f420(int index); };

struct CtrlX : S96ae60_Ctrl
{
    void FUN_008ea1f0(Vec4* out);
    void FUN_008e9380();
    char pad410[0x90];
    bool b4a0;
    char pad4a1[0xf];
    float f4b0, f4b4, f4b8;
};

struct State
{
    int unk00, unk04;
    bool b08;
    void FUN_0096c050(CtrlX* ctrl);
};

// pdb: bhkCharacterStateOnGround::Update | bhkCharacterStateOnGround.obj | fnv360_0721_beta, caller_sim, low
// pdb params: arInput
void State::FUN_0096c050(CtrlX* ctrl)
{
    if (!((unsigned char)(ctrl->m294 >> 8) & 1) && !ctrl->b4a0)
    {
        if (b08)
            ctrl->v390(2) = 0.0f;
        Vec4 pos;
        ctrl->FUN_008ea1f0(&pos);
        *(float*)&ctrl->unk3d0 = (float)(pos(2) * DAT_00db88e8);
        ctrl->m350 = 2;
        ctrl->FUN_008e8900();
        ((ModHolder*)ctrl->unk26c)->FUN_0092f420(ctrl->unk270)->v20(ctrl);
        return;
    }
    if (ctrl->b4a0)
    {
        Vec4 start;
        start(0) = ctrl->f4b0;
        start(1) = ctrl->f4b4;
        start(2) = ctrl->f4b8;
        Vec4 pos;
        ctrl->FUN_008ea1f0(&pos);
        Vec4 d;
        d(0) = pos(0) - start(0);
        d(1) = pos(1) - start(1);
        d(2) = pos(2) - start(2);
        if (d.length3() > 9.14411068f || ctrl->m350 != 11)
            ctrl->b4a0 = false;
    }
    S96ae60_Input input;
    input.m00 = 1.0f;
    input.m10 = ctrl->v370;
    input.m20 = ctrl->v360;
    input.m30 = ctrl->v2d0;
    input.m40 = ctrl->v390;
    if ((unsigned char)(ctrl->m294 >> 11) & 1)
        input.m50.set(ctrl->f344, ctrl->f340, ctrl->f348);
    else
        input.m50.set(ctrl->f344, ctrl->f340, 0.0f);
    input.m60 = DAT_00dc2148;
    input.m70 = ctrl->v320;
    FUN_00a062a0(&input, &ctrl->v390);
    if (!((unsigned char)(ctrl->m294 >> 11) & 1))
    {
        ctrl->v390(2) = input.m40(2);
        Vec4 up;
        up = ctrl->GetNode()->m10;
        float s = (float)(ctrl->f3d8 * 0.5 * *(float*)&ctrl->unk3f4);
        S96ae60_mul4(up, s);
        S96ae60_addMul4(ctrl->v390, ctrl->f388, up);
    }
    ctrl->FUN_008e9380();
    if (ctrl->m350 != 11 && (ctrl->m350 != 1 || ((unsigned char)(ctrl->m294 >> 10) & 1)))
        ctrl->FUN_008e8900();
}
}
}   // namespace f3m_0096c050

// @f3 0x009738d0 (community match, verified in this file)
// 0x009738d0: hkpInertiaTensorComputer::computeVertexCloudMassProperties(const hkReal* vertexIn, int striding,
// int numVertices, hkReal mass, hkpMassProperties& result) of Havok 5.5.0 (hkpUtilities, a static member, compiled
// with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Mass properties of a cloud of point masses: the vertices (striding bytes apart) are copied into a local array; the
// centre of mass is their mean; the inertia tensor sums each point's contribution about the centre, mass / count each.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then lines inside them while the bytes stayed equal); the
// declarations above the function are therefore the SDK's text with its names. The function body follows the
// SDK's unoptimized (hybrid) library object of this function statement by statement, and built with the SDK's
// headers it reproduces both that object and the release object. Only the function itself carries the packet's
// name; its callees keep the SDK's names.
namespace f3m_009738d0 {

typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;
class hkBool;
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
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
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
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
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
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
class hkFinishLoadedObjectFlag;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
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
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
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
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
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
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkVector4() { }
		__forceinline hkVector4(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline hkVector4(const hkQuadReal& q);
		__forceinline hkVector4( const hkVector4& v);
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}
struct hkGeometry;
class hkpShape;
class hkpRigidBodyCinfo;
class hkpRigidBody;
class hkpConstraintInstance;
struct hkpMassProperties
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpMassProperties), HK_MEMORY_CLASS_INERTIA); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpMassProperties() :	m_volume(0.0f),		m_mass(0.0f)	{		m_centerOfMass.setZero4();		m_inertiaTensor.setZero();	}
	void scaleToDensity( hkReal density );
	void scaleToMass( hkReal newMass );
	hkReal	m_volume;
	hkReal	m_mass;
	hkVector4 m_centerOfMass;
	hkMatrix3 m_inertiaTensor;
};
struct hkpMassElement;
class hkpInertiaTensorComputer
{
	public:
		static hkResult __cdecl computeSphereVolumeMassProperties( hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeBoxVolumeMassProperties(const hkVector4& halfExtents, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeCapsuleVolumeMassProperties( const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeSphereSurfaceMassProperties( hkReal radius, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeBoxSurfaceMassProperties(const hkVector4& halfExtents, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeTriangleSurfaceMassProperties(const hkVector4& v0, const hkVector4& v1, const hkVector4& v2, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeCylinderVolumeMassProperties(const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeVertexHullVolumeMassProperties(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl FUN_009738d0(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeGeometrySurfaceMassProperties(const hkGeometry* geom, hkReal surfaceThickness, hkBool distributeUniformly, hkReal mass, hkpMassProperties &result);
		static void __cdecl computeGeometryVolumeMassProperties(const hkGeometry* geom, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeGeometryVolumeMassPropertiesChecked(const hkGeometry* geom, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl combineMassProperties(const hkArray<hkpMassElement>& elements, hkpMassProperties& result );
		static void __cdecl computeShapeVolumeMassProperties(const hkpShape* shape, hkReal mass, hkpMassProperties &result);
		static void __cdecl setShapeVolumeMassProperties(const hkpShape* shape, hkReal mass, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setMassProperties(const hkpMassProperties& props, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setAndScaleToDensity(const hkpMassProperties& props, hkReal density, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setAndScaleToMass(const hkpMassProperties& props, hkReal mass, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl clipInertia(hkReal maxInertiaRatio, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl simplifyInertiaTensorToOrientedParticle(hkMatrix3 &inertia);
		static void __cdecl convertInertiaTensorToPrincipleAxis( hkMatrix3& inertia, hkRotation& principleAxisOut );
		static void __cdecl optimizeInertiasOfConstraintTree( hkpConstraintInstance*const* constraints, int numConstraints, hkpRigidBody* rootBody, hkReal inertiaFactorHint = 1.5f );
		static void __cdecl shiftInertiaToCom(hkVector4& shift, hkReal mass, hkMatrix3& inertia);
		static void __cdecl shiftInertiaFromCom(hkVector4& shift, hkReal mass, hkMatrix3& inertia);
};
hkResult __cdecl hkpInertiaTensorComputer::FUN_009738d0(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties& result)
{
	if ( numVertices <= 0 )
	{
		return HK_FAILURE;
	}
	hkArray<hkVector4> verts;
	verts.setSize( numVertices );
	const hkReal* ptr = vertexIn;
	int i;
	for ( i = 0; i < numVertices; i++ )
	{
		verts[i](0) = ptr[0];
		verts[i](1) = ptr[1];
		verts[i](2) = ptr[2];
		ptr = reinterpret_cast<const hkReal*>( reinterpret_cast<const char*>( ptr ) + striding );
	}
	result.m_mass = mass;
	result.m_inertiaTensor.setZero();
	result.m_centerOfMass.setZero4();
	const hkReal pointMass = mass / hkReal( numVertices );
	for ( i = 0; i < numVertices; i++ )
	{
		result.m_centerOfMass.add4( verts[i] );
	}
	result.m_centerOfMass.setMul4( 1.0f / hkReal( numVertices ), result.m_centerOfMass );
	for ( i = 0; i < numVertices; i++ )
	{
		hkReal rx = verts[i](0) - result.m_centerOfMass(0);
		hkReal ry = verts[i](1) - result.m_centerOfMass(1);
		hkReal rz = verts[i](2) - result.m_centerOfMass(2);
		result.m_inertiaTensor(0,0) += ( ry * ry + rz * rz ) * pointMass;
		result.m_inertiaTensor(1,1) += ( rx * rx + rz * rz ) * pointMass;
		result.m_inertiaTensor(2,2) += ( ry * ry + rx * rx ) * pointMass;
		result.m_inertiaTensor(0,1) -= ry * rx * pointMass;
		result.m_inertiaTensor(1,0) -= ry * rx * pointMass;
		result.m_inertiaTensor(0,2) -= rz * rx * pointMass;
		result.m_inertiaTensor(2,0) -= rz * rx * pointMass;
		result.m_inertiaTensor(2,1) -= ry * rz * pointMass;
		result.m_inertiaTensor(1,2) -= ry * rz * pointMass;
	}
	return HK_SUCCESS;
}

}  // namespace f3m_009738d0

// @f3 0x00975310 (community match, verified in this file)
// 0x00975310: hkpInertiaTensorComputer::computeCylinderVolumeMassProperties(const hkVector4& startAxis,
// const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result)
// of Havok 5.5.0 (hkpUtilities, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Mass properties of a solid cylinder between two points: fails for a mass or radius not above zero or a zero
// height; otherwise the cylinder's frame (rotated from the z axis onto the axis, translated to the centre), one
// mass element with the cylinder's inertia tensor scaled by the mass, combined into result.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py); the declarations above the function are therefore the SDK's
// text with its names. The function body follows the SDK's unoptimized (hybrid) library object of this function
// statement by statement, and built with the SDK's headers it reproduces both that object and the release object.
// Only the function itself carries the packet's name; its callees keep the SDK's names.
namespace f3m_00975310 {

typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;
class hkBool;
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
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
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
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
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
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
class hkFinishLoadedObjectFlag;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
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
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(mytype), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkInplaceArray(int size = 0);
		__forceinline hkInplaceArray(const hkInplaceArray<T,N>& a);
		__forceinline ~hkInplaceArray(){}
		hkArray<T>& operator= (const hkArray<T>& a);
		hkArray<T>& operator= (const hkInplaceArray<T,N>& a);
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		inline hkBool wasReallocated() const;
		inline int stillInplaceUsingMask() const;
	public:
		T m_storage[N];
	public:
		hkInplaceArray(hkFinishLoadedObjectFlag f) : hkArray<T>(f) { }
};
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
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
__forceinline T& hkArray<T>::expandOne( )
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	return m_data[m_size++];
}
template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
extern "C" {
double  __cdecl acos(     double _X);
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float acosf(     float _X)
        {return ((float)acos((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
inline hkReal __cdecl acos(hkReal r)
	{
		;
		if( hkMath::fabs(r) >= 1.0f )
		{
			r = ( r>0 )	? 0 : 3.14159265358979f;
			return r;
		}
		return acosf(r);
	}
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkVector4() { }
		__forceinline hkVector4(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline hkVector4(const hkQuadReal& q);
		__forceinline hkVector4( const hkVector4& v);
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkQuaternion), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline hkVector4::hkVector4( const hkVector4& v)
{
	*this = v;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}
inline void hkMatrix3::setIdentity()
{
	setZero();
	hkReal one = 1.0f;
	(*this)(0,0) = one;
	(*this)(1,1) = one;
	(*this)(2,2) = one;
}
const hkVector4& hkTransform::getColumn(int x) const
{
	return m_rotation.getColumn(x);
}
void hkTransform::setTranslation(const hkVector4& t)
{
	m_translation = t;
}
hkRotation& hkTransform::getRotation()
{
	return m_rotation;
}
const hkTransform& __cdecl hkTransform::getIdentity()
{
	extern hkReal hkTransformIdentity[];
	return reinterpret_cast<const hkTransform&>(hkTransformIdentity);
}
void hkTransform::setIdentity()
{
	m_rotation.setIdentity();
	m_translation.setZero4();
}
struct hkGeometry;
class hkpShape;
class hkpRigidBodyCinfo;
class hkpRigidBody;
class hkpConstraintInstance;
struct hkpMassProperties
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpMassProperties), HK_MEMORY_CLASS_INERTIA); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpMassProperties() :	m_volume(0.0f),		m_mass(0.0f)	{		m_centerOfMass.setZero4();		m_inertiaTensor.setZero();	}
	void scaleToDensity( hkReal density );
	void scaleToMass( hkReal newMass );
	hkReal	m_volume;
	hkReal	m_mass;
	hkVector4 m_centerOfMass;
	hkMatrix3 m_inertiaTensor;
};
struct hkpMassElement
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpMassElement), HK_MEMORY_CLASS_INERTIA); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpMassProperties m_properties;
	hkTransform m_transform;
	hkpMassElement()
	{
		m_transform.setIdentity();
	}
	hkpMassElement(const hkpMassProperties& properties,const hkTransform& transform) :
		m_properties(properties),
		m_transform(transform)
	{
	}
};
class hkpInertiaTensorComputer
{
	public:
		static hkResult __cdecl computeSphereVolumeMassProperties( hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeBoxVolumeMassProperties(const hkVector4& halfExtents, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeCapsuleVolumeMassProperties( const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeSphereSurfaceMassProperties( hkReal radius, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeBoxSurfaceMassProperties(const hkVector4& halfExtents, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeTriangleSurfaceMassProperties(const hkVector4& v0, const hkVector4& v1, const hkVector4& v2, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl FUN_00975310(const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeVertexHullVolumeMassProperties(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeVertexCloudMassProperties(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeGeometrySurfaceMassProperties(const hkGeometry* geom, hkReal surfaceThickness, hkBool distributeUniformly, hkReal mass, hkpMassProperties &result);
		static void __cdecl computeGeometryVolumeMassProperties(const hkGeometry* geom, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeGeometryVolumeMassPropertiesChecked(const hkGeometry* geom, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl combineMassProperties(const hkArray<hkpMassElement>& elements, hkpMassProperties& result );
		static void __cdecl computeShapeVolumeMassProperties(const hkpShape* shape, hkReal mass, hkpMassProperties &result);
		static void __cdecl setShapeVolumeMassProperties(const hkpShape* shape, hkReal mass, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setMassProperties(const hkpMassProperties& props, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setAndScaleToDensity(const hkpMassProperties& props, hkReal density, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setAndScaleToMass(const hkpMassProperties& props, hkReal mass, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl clipInertia(hkReal maxInertiaRatio, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl simplifyInertiaTensorToOrientedParticle(hkMatrix3 &inertia);
		static void __cdecl convertInertiaTensorToPrincipleAxis( hkMatrix3& inertia, hkRotation& principleAxisOut );
		static void __cdecl optimizeInertiasOfConstraintTree( hkpConstraintInstance*const* constraints, int numConstraints, hkpRigidBody* rootBody, hkReal inertiaFactorHint = 1.5f );
		static void __cdecl shiftInertiaToCom(hkVector4& shift, hkReal mass, hkMatrix3& inertia);
		static void __cdecl shiftInertiaFromCom(hkVector4& shift, hkReal mass, hkMatrix3& inertia);
};
// pdb: hkpInertiaTensorComputer::computeCylinderVolumeMassProperties | hkpInertiaTensorComputer.obj | fnv360_0822_retail, objrun, medium
// pdb params: startAxis, endAxis, radius, mass, result
hkResult hkpInertiaTensorComputer::FUN_00975310(const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result)
{
	if (mass <= 0.0f)
	{
		return HK_FAILURE;
	}
	if (radius <= 0.0f)
	{
		return HK_FAILURE;
	}
	hkTransform capsuleToLocal;
	hkVector4 axis; axis.setSub4(endAxis, startAxis);
	hkReal height = axis.length3();
	if (height > 0.0f)
	{
		axis.normalize3();
		hkVector4 canonicalZ = hkTransform::getIdentity().getColumn(2);
		if (hkMath::fabs(axis.dot3(canonicalZ)) < 0.99999f)
		{
			hkVector4 rotAxis; rotAxis.setCross(canonicalZ, axis);
			rotAxis.normalize3();
			hkReal rotAngle = hkMath::acos(axis.dot3(canonicalZ));
			hkQuaternion q; q.setAxisAngle(rotAxis, rotAngle);
			capsuleToLocal.getRotation().set(q);
		}
		else
		{
			capsuleToLocal.setIdentity();
		}
	}
	else
	{
		return HK_FAILURE;
	}
	{
		hkVector4 toCentre; toCentre.setAdd4(startAxis, endAxis);
		toCentre.mul4(0.5f);
		capsuleToLocal.setTranslation(toCentre);
	}
	const hkReal volumeOfCylinder = radius * 3.14159265358979f * radius * height;
	const hkReal massOfCylinder = mass;
	hkInplaceArray<hkpMassElement,1> elements;
	{
		hkpMassElement& cylinderElement = elements.expandOne();
		cylinderElement.m_transform = capsuleToLocal;
		cylinderElement.m_properties.m_centerOfMass.setAll(0.0f);
		cylinderElement.m_properties.m_inertiaTensor.setIdentity();
		cylinderElement.m_properties.m_inertiaTensor(0, 0) = radius * radius * 0.25f + height / 2.0f * height / 2.0f / 3.0f;
		cylinderElement.m_properties.m_inertiaTensor(1, 1) = cylinderElement.m_properties.m_inertiaTensor(0, 0);
		cylinderElement.m_properties.m_inertiaTensor(2, 2) = radius * radius * 0.5f;
		cylinderElement.m_properties.m_inertiaTensor.mul(massOfCylinder);
		cylinderElement.m_properties.m_centerOfMass.setZero4();
		cylinderElement.m_properties.m_volume = volumeOfCylinder;
		cylinderElement.m_properties.m_mass = massOfCylinder;
	}
	hkpInertiaTensorComputer::combineMassProperties(elements, result);
	return HK_SUCCESS;
}

}  // namespace f3m_00975310

// @f3 0x00974950 (community match, verified in this file)
// 0x00974950: hkpInertiaTensorComputer::computeCapsuleVolumeMassProperties(const hkVector4& startAxis,
// const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result) of Havok 5.5.0 (hkpUtilities,
// compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Mass properties of a solid capsule: the capsule's frame from its axis (a rotation from the z axis, or the
// identity for a degenerate or z-aligned axis) and centre, the volumes and masses of the cylinder and the two
// half-sphere caps, one mass element each (cylinder inertia; each cap from the sphere's properties, halved and
// shifted to its centre of mass), combined into the result.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The SDK's int 3 traps in the unused placement
// operators new[] and delete[] were removed by hand. The function body follows the SDK's unoptimized (hybrid)
// library object statement by statement and reproduces the release object. Only the function carries the
// packet's name.
namespace f3m_00974950 {

typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;
class hkBool;
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
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
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
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
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
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
class hkFinishLoadedObjectFlag;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
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
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(mytype), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkInplaceArray(int size = 0);
		__forceinline hkInplaceArray(const hkInplaceArray<T,N>& a);
		__forceinline ~hkInplaceArray(){}
		hkArray<T>& operator= (const hkArray<T>& a);
		hkArray<T>& operator= (const hkInplaceArray<T,N>& a);
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		inline hkBool wasReallocated() const;
		inline int stillInplaceUsingMask() const;
	public:
		T m_storage[N];
	public:
		hkInplaceArray(hkFinishLoadedObjectFlag f) : hkArray<T>(f) { }
};
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
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
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}
template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
extern "C" {
double  __cdecl acos(     double _X);
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float acosf(     float _X)
        {return ((float)acos((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
inline hkReal __cdecl acos(hkReal r)
	{
		;
		if( hkMath::fabs(r) >= 1.0f )
		{
			r = ( r>0 )	? 0 : 3.14159265358979f;
			return r;
		}
		return acosf(r);
	}
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkVector4() { }
		__forceinline hkVector4(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline hkVector4(const hkQuadReal& q);
		__forceinline hkVector4( const hkVector4& v);
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkQuaternion), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline void hkMatrix3::operator= ( const hkMatrix3& a )
{
	m_col0 = a.getColumn(0);
	m_col1 = a.getColumn(1);
	m_col2 = a.getColumn(2);
}
inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}
inline void hkMatrix3::setIdentity()
{
	setZero();
	hkReal one = 1.0f;
	(*this)(0,0) = one;
	(*this)(1,1) = one;
	(*this)(2,2) = one;
}
inline hkQuaternion::hkQuaternion(const hkVector4& axis, hkReal angle)
{
	setAxisAngle(axis,angle);
}
hkVector4& hkTransform::getTranslation()
{
	return m_translation;
}
void hkTransform::setTranslation(const hkVector4& t)
{
	m_translation = t;
}
hkRotation& hkTransform::getRotation()
{
	return m_rotation;
}
void hkTransform::setRotation(const hkQuaternion& quatRotation)
{
	m_rotation.set(quatRotation);
}
void hkTransform::setIdentity()
{
	m_rotation.setIdentity();
	m_translation.setZero4();
}
struct hkGeometry;
class hkpShape;
class hkpRigidBodyCinfo;
class hkpRigidBody;
class hkpConstraintInstance;
struct hkpMassProperties
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpMassProperties), HK_MEMORY_CLASS_INERTIA); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpMassProperties() :	m_volume(0.0f),		m_mass(0.0f)	{		m_centerOfMass.setZero4();		m_inertiaTensor.setZero();	}
	void scaleToDensity( hkReal density );
	void scaleToMass( hkReal newMass );
	hkReal	m_volume;
	hkReal	m_mass;
	hkVector4 m_centerOfMass;
	hkMatrix3 m_inertiaTensor;
};
struct hkpMassElement
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpMassElement), HK_MEMORY_CLASS_INERTIA); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpMassProperties m_properties;
	hkTransform m_transform;
	hkpMassElement()
	{
		m_transform.setIdentity();
	}
	hkpMassElement(const hkpMassProperties& properties,const hkTransform& transform) :
		m_properties(properties),
		m_transform(transform)
	{
	}
};
class hkpInertiaTensorComputer
{
	public:
		static hkResult __cdecl computeSphereVolumeMassProperties( hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeBoxVolumeMassProperties(const hkVector4& halfExtents, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl FUN_00974950( const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeSphereSurfaceMassProperties( hkReal radius, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeBoxSurfaceMassProperties(const hkVector4& halfExtents, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeTriangleSurfaceMassProperties(const hkVector4& v0, const hkVector4& v1, const hkVector4& v2, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeCylinderVolumeMassProperties(const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeVertexHullVolumeMassProperties(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeVertexCloudMassProperties(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeGeometrySurfaceMassProperties(const hkGeometry* geom, hkReal surfaceThickness, hkBool distributeUniformly, hkReal mass, hkpMassProperties &result);
		static void __cdecl computeGeometryVolumeMassProperties(const hkGeometry* geom, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeGeometryVolumeMassPropertiesChecked(const hkGeometry* geom, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl combineMassProperties(const hkArray<hkpMassElement>& elements, hkpMassProperties& result );
		static void __cdecl computeShapeVolumeMassProperties(const hkpShape* shape, hkReal mass, hkpMassProperties &result);
		static void __cdecl setShapeVolumeMassProperties(const hkpShape* shape, hkReal mass, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setMassProperties(const hkpMassProperties& props, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setAndScaleToDensity(const hkpMassProperties& props, hkReal density, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setAndScaleToMass(const hkpMassProperties& props, hkReal mass, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl clipInertia(hkReal maxInertiaRatio, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl simplifyInertiaTensorToOrientedParticle(hkMatrix3 &inertia);
		static void __cdecl convertInertiaTensorToPrincipleAxis( hkMatrix3& inertia, hkRotation& principleAxisOut );
		static void __cdecl optimizeInertiasOfConstraintTree( hkpConstraintInstance*const* constraints, int numConstraints, hkpRigidBody* rootBody, hkReal inertiaFactorHint = 1.5f );
		static void __cdecl shiftInertiaToCom(hkVector4& shift, hkReal mass, hkMatrix3& inertia);
		static void __cdecl shiftInertiaFromCom(hkVector4& shift, hkReal mass, hkMatrix3& inertia);
};
// pdb: hkpInertiaTensorComputer::computeCapsuleVolumeMassProperties | hkpInertiaTensorComputer.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: hkInertiaTensorComputer::computeCapsuleVolumeMassProperties)
// pdb params: startAxis, endAxis, radius, mass, result
hkResult hkpInertiaTensorComputer::FUN_00974950(const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result)
{
	if (mass <= 0.0f) {
		return HK_FAILURE;
	}
	if (radius <= 0.0f) {
		return HK_FAILURE;
	}
	hkVector4 axis; axis.setSub4(endAxis, startAxis);
	hkReal height = axis.length3();
	hkTransform capsuleToLocal;
	if (height > 0.0f)
	{
		axis.normalize3();
		hkVector4 canonicalZ; canonicalZ.set(0.0f, 0.0f, 1.0f);
		if (hkMath::fabs(axis.dot3(canonicalZ)) < 0.99999f)
		{
			hkVector4 rotAxis; rotAxis.setCross(canonicalZ, axis);
			rotAxis.normalize3();
			hkReal rotAngle = hkMath::acos(axis.dot3(canonicalZ));
			hkQuaternion q(rotAxis, rotAngle);
			capsuleToLocal.setRotation(q);
		}
		else
		{	capsuleToLocal.setIdentity();
		}
	}
	else
	{	capsuleToLocal.setIdentity();
	}
	{
		hkVector4 toCentre; toCentre.setAdd4(startAxis, endAxis);
		toCentre.mul4(0.5f);
		capsuleToLocal.setTranslation(toCentre);
	}
	const hkReal volumeOfCaps = 4.0f / 3.0f * 3.14159265358979f * radius * radius * radius;
	const hkReal volumeOfCylinder = 3.14159265358979f * radius * radius * height;
	const hkReal totalVolume = volumeOfCaps + volumeOfCylinder;
	const hkReal massOfCapsules = mass * volumeOfCaps / totalVolume;
	const hkReal massOfCylinder = mass * volumeOfCylinder / totalVolume;
	hkInplaceArray<hkpMassElement,3> elements;
	{
		hkpMassElement cylinderElement;
		cylinderElement.m_transform = capsuleToLocal;
		cylinderElement.m_properties.m_centerOfMass.set(0.0f, 0.0f, 0.0f, 0.0f);
		cylinderElement.m_properties.m_inertiaTensor.setIdentity();
		cylinderElement.m_properties.m_inertiaTensor(0,0) = radius * radius * 0.25f + height / 2.0f * height / 2.0f / 3.0f;
		cylinderElement.m_properties.m_inertiaTensor(1,1) = cylinderElement.m_properties.m_inertiaTensor(0,0);
		cylinderElement.m_properties.m_inertiaTensor(2,2) = radius * radius * 0.5f;
		cylinderElement.m_properties.m_inertiaTensor.mul(massOfCylinder);
		cylinderElement.m_properties.m_centerOfMass.setZero4();
		cylinderElement.m_properties.m_volume = volumeOfCylinder;
		cylinderElement.m_properties.m_mass = massOfCylinder;
		elements.pushBack(cylinderElement);
	}
	{
		hkpMassElement capElement;
		capElement.m_transform = capsuleToLocal;
		hkVector4 pos; pos.set(0.0f, 0.0f, height / 2.0f);
		pos.setRotatedDir(capsuleToLocal.getRotation(), pos);
		pos.add4(capElement.m_transform.getTranslation());
		capElement.m_transform.setTranslation(pos);
		capElement.m_properties.m_centerOfMass.set(0.0f, 0.0f, radius * 0.375f);
		{
			hkpMassProperties sphereResult;
			hkpInertiaTensorComputer::computeSphereVolumeMassProperties(radius, massOfCapsules, sphereResult);
			capElement.m_properties.m_inertiaTensor = sphereResult.m_inertiaTensor;
			capElement.m_properties.m_inertiaTensor.mul(0.5f);
			hkpInertiaTensorComputer::shiftInertiaToCom(capElement.m_properties.m_centerOfMass, massOfCapsules * 0.5f, capElement.m_properties.m_inertiaTensor);
		}
		capElement.m_properties.m_volume = volumeOfCaps * 0.5f;
		capElement.m_properties.m_mass = massOfCapsules * 0.5f;
		elements.pushBack(capElement);
	}
	{
		hkpMassElement capElement;
		capElement.m_transform = capsuleToLocal;
		hkVector4 pos; pos.set(0.0f, 0.0f, -(height / 2.0f));
		pos.setRotatedDir(capsuleToLocal.getRotation(), pos);
		pos.add4(capElement.m_transform.getTranslation());
		capElement.m_transform.setTranslation(pos);
		capElement.m_properties.m_centerOfMass.set(0.0f, 0.0f, radius * -0.375f);
		{
			hkpMassProperties sphereResult;
			hkpInertiaTensorComputer::computeSphereVolumeMassProperties(radius, massOfCapsules, sphereResult);
			capElement.m_properties.m_inertiaTensor = sphereResult.m_inertiaTensor;
			capElement.m_properties.m_inertiaTensor.mul(0.5f);
			hkpInertiaTensorComputer::shiftInertiaToCom(capElement.m_properties.m_centerOfMass, massOfCapsules * 0.5f, capElement.m_properties.m_inertiaTensor);
		}
		capElement.m_properties.m_volume = volumeOfCaps * 0.5f;
		capElement.m_properties.m_mass = massOfCapsules * 0.5f;
		elements.pushBack(capElement);
	}
	hkpInertiaTensorComputer::combineMassProperties(elements, result);
	return HK_SUCCESS;
}

}  // namespace f3m_00974950

// @f3 0x0097fef0 (community match, verified in this file)
// 0x0097fef0: hkpSimulation::processAgentsOfEntities(hkpEntity** entities, int numEntities,
// const hkpProcessCollisionInput& processInput, AgentEntryProcessFunction processingFunction,
// FindContacts findExtraContacts) of Havok 5.5.0 (hkpDynamics, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Runs the collision agents of the given entities once each (a pointer map of the processed collidables skips the
// pairs already done): invalidates the agent's time of impact and calls the processing function; with
// FIND_CONTACTS_EXTRA and a contact found, it rotates the body a little about the contact (with a raised tolerance)
// in three directions to find more contact points, processing the agent after each, and restores the transform.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The SDK's int 3 traps in the unused placement
// operators new[] and delete[] were removed by hand. The body follows the SDK's unoptimized (hybrid) library
// object statement by statement and reproduces the release object. The rotation update of lines 887, 901 and 909
// (set the transform's rotation, rotate the local centre of mass, translation = centre of mass - shift) is a
// file-local inline helper that no shipped header contains; it is written here from the hybrid object's code.
// Only the function carries the packet's name.
namespace f3m_0097fef0 {

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
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
		}
	private:
		char m_bool;
};
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
};
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
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
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		__forceinline hkInplaceArray(int size = 0);
		__forceinline hkInplaceArray(const hkInplaceArray<T,N>& a);
		__forceinline ~hkInplaceArray(){}
	public:
		T m_storage[N];
	public:
		hkInplaceArray(hkFinishLoadedObjectFlag f) : hkArray<T>(f) { }
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
namespace hkSmallArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T>
class hkSmallArray
{
		friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
		__forceinline const T& back() const;
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
	public:
		enum
		{
			CAPACITY_MASK			= hkUint16(0x3fff),
			FLAG_MASK				= hkUint16(0xC000),
			DONT_DEALLOCATE_FLAG	= hkUint16(0x8000),
			LOCKED_FLAG				= hkUint16(0x4000),
			FORCE_SIGNED			= -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T*			m_data;
		hkUint16	m_size;
		hkUint16	m_capacityAndFlags;
	public:
		hkSmallArray(hkFinishLoadedObjectFlag f) { }
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
extern "C" {
double  __cdecl asin(     double _X);
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float asinf(     float _X)
        {return ((float)asin((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
inline hkReal __cdecl asin(hkReal r)
	{
		;
		if( hkMath::fabs(r) >= 1.0f )
		{
			r = ( r>0 )	? 0.5f * 3.14159265358979f : -0.5f * 3.14159265358979f;
			return r;
		}
		return asinf(r);
	}
template <typename T>
	inline T __cdecl max2( T x, T y)
	{
		return x > y ? x : y;
	}
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		inline hkQuaternion() { }
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
		void initSweptTransform( const hkVector4& position, const hkQuaternion& rotation );
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline void hkVector4::_setMul3( const hkMatrix3& r, const hkVector4& v )
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2;
		t(1) = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2;
		t(2) = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2;
		t(3) = 0;
	}
inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
hkVector4& hkTransform::getTranslation()
{
	return m_translation;
}
hkRotation& hkTransform::getRotation()
{
	return m_rotation;
}
void hkTransform::setRotation(const hkQuaternion& quatRotation)
{
	m_rotation.set(quatRotation);
}
hkTransform::hkTransform(const hkTransform& t)
{
	const hkVector4 r0 = t.m_rotation.getColumn(0);
	const hkVector4 r1 = t.m_rotation.getColumn(1);
	const hkVector4 r2 = t.m_rotation.getColumn(2);
	const hkVector4 r3 = t.m_rotation.getColumn(3);
	m_rotation.getColumn(0) = r0;
	m_rotation.getColumn(1) = r1;
	m_rotation.getColumn(2) = r2;
	m_rotation.getColumn(3) = r3;
}
template <typename T>
class hkPointerMapBase
{
	public:
		typedef class Dummy* Iterator;
		hkPointerMapBase();
		hkPointerMapBase(int numElements);
		hkPointerMapBase(void* ptr, int sizeInBytes);
		~hkPointerMapBase();
		Iterator getIterator() const;
		T getKey( Iterator i ) const;
		T getValue( Iterator i ) const;
		void setValue( Iterator i, T val );
		Iterator getNext( Iterator i ) const;
		hkBool isValid( Iterator i ) const;
		void insert( T key, T val );
		Iterator findKey( T key ) const;
		hkBool hasKey( T key ) const { return isValid(findKey(key)); }
		T getWithDefault( T key, T def ) const;
		hkResult get( T key, T* out ) const;
		void remove( Iterator it );
		T* m_elem;
		int m_numElems;
		int m_hashMod;
};
template < typename T >
inline hkBool hkPointerMapBase<T>::isValid( Iterator it ) const
{
	int i = static_cast<int>( reinterpret_cast<T>(it) );
	;
	return i <= m_hashMod;
}
class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkVector4& getPosition() const;
		inline hkVector4& getPosition();
		inline void setPosition(const hkVector4& position);
		inline const hkVector4& getNormal() const;
		inline const hkVector4& getSeparatingNormal() const;
	protected:
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline const hkVector4& hkContactPoint::getNormal() const
{
	return m_separatingNormal;
}
inline hkVector4& hkContactPoint::getPosition()
{
	return m_position;
}
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape;
class hkMotionState;
class hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline const hkMotionState* getMotionState() const;
		__forceinline void setMotionState( const hkMotionState* state );
		__forceinline void setTransform( const hkTransform* t );
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};
class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkUint32 m_id;
		hkpBroadPhaseHandle(): m_id(0){}
	public:
		hkpBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ){}
};
enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_MAX
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};
struct hkAabbUint32;
class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpCollidable( const hkpShape* shape, const hkTransform* ms, int type = 0);
		inline void* getOwner() const
		{
	        return const_cast<char*>( reinterpret_cast<const char*>(this) + m_ownerOffset );
	    }
		void checkPerformance();
		hkpCollidable( class hkFinishLoadedObjectFlag flag );
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable
{
	public:
		struct CollisionEntry
		{
			hkpAgentNnEntry* m_agentEntry;
			hkpLinkedCollidable*	m_partner;
		};
		hkArray<struct CollisionEntry> m_collisionEntries;
};
class hkMultiThreadCheck
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		__forceinline hkMultiThreadCheck();
		__forceinline void init();
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		__forceinline void markForRead( ReadMode mode = RECURSIVE )
		{
			;
		}
		__forceinline void markForWrite( )
		{
		}
		__forceinline bool isMarkedForReadRecursive()
		{
			return true;
		}
		void unmarkForWriteImpl();
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
struct hkpPropertyValue;
class hkpWorld;
namespace hkWorldOperation
{
enum Result
	{
		POSTPONED,
		DONE
	};
}
class hkpWorldObject : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkpCollidable* getCollidable() const;
		inline hkpLinkedCollidable* getLinkedCollidable();
		inline const hkpLinkedCollidable* getLinkedCollidable() const;
		inline const hkpLinkedCollidable* getCollidableMtUnchecked() const;
		inline hkBool isAddedToWorld() const;
		inline hkMultiThreadCheck& getMultiThreadCheck();
		inline const hkMultiThreadCheck& getMultiThreadCheck() const;
		inline void copyProperties( const hkpWorldObject* otherObj );
	protected:
		hkpWorld* m_world;
		hkUlong m_userData;
	protected:
		class hkpLinkedCollidable m_collidable;
	protected:
		class hkMultiThreadCheck m_multiThreadCheck;
		const char* m_name;
		hkArray<class hkpProperty> m_properties;
	public:
		hkpWorldObject( class hkFinishLoadedObjectFlag flag );
};
inline const hkpCollidable* hkpWorldObject::getCollidable() const
{
	return &m_collidable;
}
inline hkpLinkedCollidable* hkpWorldObject::getLinkedCollidable()
{
	return &m_collidable;
}
class hkpMaterial
{
		inline void setFriction( hkReal newFriction );
		inline void setRestitution( hkReal newRestitution );
		static inline hkReal __cdecl getCombinedFriction( hkReal frictionA, hkReal frictionB);
		static inline hkReal __cdecl getCombinedRestitution( hkReal restitutionA, hkReal restitutionB);
		enum ResponseType
		{
			RESPONSE_INVALID,
			RESPONSE_SIMPLE_CONTACT,
			RESPONSE_REPORTING,
			RESPONSE_NONE,
			RESPONSE_MAX_ID
		};
		inline void setResponseType( enum hkpMaterial::ResponseType t );
		inline enum hkpMaterial::ResponseType getResponseType() const;
	private:
		hkEnum<ResponseType,hkInt8> m_responseType;
		hkReal m_friction;
		hkReal m_restitution;
	public:
		hkpMaterial( class hkFinishLoadedObjectFlag flag ) { }
};
class hkpSolverResults
{
	public:
		inline hkReal getImpulseApplied() const;
		inline hkpSolverResults();
		inline void init();
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};
inline void hkpSolverResults::init()
{
	m_impulseApplied = 0.0f;
	m_internalSolverData = 0.0f;
}
inline hkpSolverResults::hkpSolverResults()
{
	init();
}
struct hkpConstraintInfo
{
	int m_maxSizeOfSchema;
	int m_sizeOfSchemas;
	int m_numSolverResults;
	int m_numSolverElemTemps;
	inline void clear( ) { m_maxSizeOfSchema = 0; m_sizeOfSchemas = 0; m_numSolverResults = 0; m_numSolverElemTemps = 0; }
	inline void addHeader( ) { m_sizeOfSchemas += 16; }
	inline void add( const hkpConstraintInfo& other);
	inline void sub( const hkpConstraintInfo& other);
	inline void merge( const hkpConstraintInfo& other);
};
class hkpConstraintData;
class hkpEntity;
class hkpRigidBody;
class hkpConstraintOwner;
class hkpSimulationIsland;
typedef void hkpConstraintRuntime;
class hkpConstraintInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum ConstraintPriority
		{
			PRIORITY_INVALID,
			PRIORITY_PSI,
			PRIORITY_TOI,
			PRIORITY_TOI_HIGHER,
			PRIORITY_TOI_FORCED,
		};
		hkBool				m_wantRuntime;
		const char* m_name;
	public:
		hkUlong m_userData;
		struct hkConstraintInternal* m_internal;
		friend class hkpSaveContactPointsUtil;
		hkpConstraintInstance(){}
};
__declspec(align(16)) struct hkConstraintInternal
{
		friend class hkpWorldConstraintUtil;
		struct hkpConstraintAtom* m_atoms;
		hkUint16 m_atomsSize;
	public:
		hkUint8	m_callbackRequest;
		inline void addConstraintInfo( const hkpConstraintInfo& delta );
		inline void subConstraintInfo( const hkpConstraintInfo& delta );
		hkUint8	m_whoIsMaster;
		hkBool m_isNormalType;
		hkpConstraintRuntime*	m_runtime;
		hkUint16			m_runtimeSize;
		hkObjectIndex		m_slaveIndex;
		friend class hkpSaveContactPointsUtil;
};
class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkMotionState();
		void initMotionState( const hkVector4& position, const hkQuaternion& rotation );
		inline hkTransform& getTransform();
		inline const hkTransform& getTransform() const;
		inline const hkSweptTransform& getSweptTransform() const;
		inline hkSweptTransform& getSweptTransform();
	protected:
		hkTransform m_transform;
		class hkSweptTransform m_sweptTransform;
	public:
		hkVector4 m_deltaAngle;
		hkReal m_objectRadius;
};
hkTransform& hkMotionState::getTransform()
{
	return m_transform;
}
const hkTransform& hkMotionState::getTransform() const
{
	return m_transform;
}
const hkSweptTransform& hkMotionState::getSweptTransform() const
{
	return m_sweptTransform;
}
class hkpMotion : public hkReferencedObject
{
public:
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_SPHERE_INERTIA,
		MOTION_STABILIZED_SPHERE_INERTIA,
		MOTION_BOX_INERTIA,
		MOTION_STABILIZED_BOX_INERTIA,
		MOTION_KEYFRAMED,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};
public:
	inline MotionType getType() const { return m_type; }
	hkpMotion(const hkVector4& position, const hkQuaternion& rotation, bool wantDeactivation = false);
	hkReal getMass() const;
	inline hkSimdReal getMassInv() const;
	virtual void setMass(hkReal m);
	virtual void setMassInv(hkReal mInv);
	virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
	virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
	virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
	virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
	virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
	virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
	virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
	inline const hkVector4& getCenterOfMassLocal() const;
	inline const hkVector4& getCenterOfMassInWorld() const;
	inline hkMotionState* getMotionState();
	inline const hkMotionState* getMotionState() const;
	inline const hkVector4& getPosition() const;
	virtual void setPosition(const hkVector4& position);
	inline const hkQuaternion& getRotation() const;
	virtual void setRotation(const hkQuaternion& rotation);
	virtual void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
	inline const hkTransform& getTransform() const;
	void approxTransformAt( hkTime time, hkTransform& transformOut );
	virtual void setTransform(const hkTransform& transform);
	inline const hkVector4& getLinearVelocity() const;
	virtual void setLinearVelocity(const hkVector4& newVel);
	inline const hkVector4& getAngularVelocity() const;
public:
	hkEnum<MotionType, hkUint8>	m_type;
	hkUint8		m_deactivationIntegrateCounter;
	hkUint16	m_deactivationNumInactiveFrames[2];
	class hkMotionState m_motionState;
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
public:
	hkpMotion( class hkFinishLoadedObjectFlag flag ) { }
};
hkMotionState* hkpMotion::getMotionState()
{
	return &m_motionState;
}
const hkVector4& hkpMotion::getCenterOfMassLocal() const
{
	return m_motionState.getSweptTransform().m_centerOfMassLocal;
}
const hkVector4& hkpMotion::getCenterOfMassInWorld() const
{
	return m_motionState.getSweptTransform().m_centerOfMass1;
}
const hkQuaternion& hkpMotion::getRotation() const
{
	return m_motionState.getSweptTransform().m_rotation1;
}
const hkTransform& hkpMotion::getTransform() const
{
	return m_motionState.getTransform();
}
class hkpKeyframedRigidMotion : public hkpMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpKeyframedRigidMotion( const hkVector4& position, const hkQuaternion& rotation );
		virtual ~hkpKeyframedRigidMotion();
		virtual void setMass(hkReal m);
		virtual void setMassInv(hkReal mInv);
		virtual void getInertiaLocal(hkMatrix3& inertia) const;
		virtual void setInertiaLocal(const hkMatrix3& inertia);
		virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
		virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
		virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		virtual void applyLinearImpulse(const hkVector4& imp);
	protected:
		hkpKeyframedRigidMotion(): hkpMotion(hkFinishLoadedObjectFlag()){ m_savedMotion = 0; }
	public:
	public:
		virtual void setStepPosition( hkReal position, hkReal timestep );
		virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
	public:
		hkpKeyframedRigidMotion( class hkFinishLoadedObjectFlag flag ) : hkpMotion( flag ) {}
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpMaxSizeMotion() : hkpKeyframedRigidMotion( ) {}
		hkpMaxSizeMotion( class hkFinishLoadedObjectFlag flag ) : hkpKeyframedRigidMotion( flag ) {}
	private:
		void operator=(const hkpMaxSizeMotion& other);
		hkpMaxSizeMotion( const hkpMaxSizeMotion& other );
};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpAction;
class hkpDynamicsContactMgr;
class hkSpuCollisionCallbackUtil;
class hkpEntity : public hkpWorldObject
{
	public:
		enum SpuCollisionCallbackEventFilter
		{
		};
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpEntity();
		void addEntityListener( hkpEntityListener* el);
		inline void setProcessContactCallbackDelay( hkUint16 delay );
		inline hkpMaterial& getMaterial();
		inline const hkpMaterial& getMaterial() const;
		inline hkBool isFixed() const;
		inline hkBool isFixedOrKeyframed() const;
				hkSmallArray<struct hkConstraintInternal>&	getConstraintMastersRwImpl();
		const	hkArray<class hkpConstraintInstance*>&	getConstraintSlavesImpl() const;
		hkpEntity( const hkpShape* shape );
	public:
		hkpEntity( class hkFinishLoadedObjectFlag flag );
		inline hkpMotion* getMotion();
		inline hkpSimulationIsland* getSimulationIsland() const;
		virtual void deallocateInternalArrays();
		virtual hkMotionState* getMotionState(){ return 0; }
	protected:
		class hkpMaterial m_material;
	protected:
		friend class hkpWorldConstraintUtil;
	public:
	public:
		class SmallArraySerializeOverrideType
		{
			public:
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				void* m_data;
				hkUint16 m_size;
				hkUint16 m_capacityAndFlags;
		};
	public:		void* m_breakOffPartsUtil;
	public:		hkUint32									m_solverData;
	public: 	hkObjectIndex								m_storageIndex;
	protected:	hkUint16									m_processContactCallbackDelay;
	protected:	hkSmallArray<struct hkConstraintInternal>	m_constraintsMaster;
	protected:	hkArray<hkpConstraintInstance*>				m_constraintsSlave;
	protected:
		hkArray<hkUint8> m_constraintRuntime;
		hkpSimulationIsland* m_simulationIsland;
	public:
		hkInt8  m_autoRemoveLevel;
		hkUint8 m_numUserDatasInContactPointProperties;
		hkUint32 m_uid;
	public:
		struct SpuCollisionCallback
		{
		public:
			hkUint8 m_eventFilter;
			hkUint8	m_userFilter;
		};
		struct ExtendedListeners
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
			hkSmallArray<hkpEntityListener*>				m_entityListeners;
		};
	public:
		struct SpuCollisionCallback m_spuCollisionCallback;
	protected:	mutable ExtendedListeners* m_extendedListeners;
	public:		class hkpMaxSizeMotion m_motion;
	protected:
		friend class hkpEntityCallbackUtil;
		hkSmallArray<hkpAction*>						m_actions;
};
inline hkpSimulationIsland* hkpEntity::getSimulationIsland() const
{
	return m_simulationIsland;
}
inline hkBool hkpEntity::isFixed() const
{
	return m_motion.m_type == hkpMotion::MOTION_FIXED;
}
class hkStepInfo
{
	public:
		hkStepInfo(){}
		void set( hkTime startTime, hkTime endTime)
		{
			m_startTime = startTime;
			m_endTime   = endTime;
			m_deltaTime = endTime - startTime;
			m_invDeltaTime = m_deltaTime == 0.0f ? 0.0f : 1.0f / m_deltaTime;
		}
		hkStepInfo( hkTime startTime, hkTime endTime)
		{
			set( startTime, endTime );
		}
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
struct hkpWorldDynamicsStepInfo;
enum hkpStepResult
{
	HK_STEP_RESULT_SUCCESS,
	HK_STEP_RESULT_MEMORY_FAILURE_BEFORE_INTEGRATION,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_COLLIDE,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_TOI_SOLVE,
};
class hkpConstraintQueryIn;
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
class hkpSimulation: public hkReferencedObject
{
	public:
		enum FindContacts
		{
			FIND_CONTACTS_DEFAULT = 0,
			FIND_CONTACTS_EXTRA
		};
		virtual void removeCollisionInformationForAgent( hkpAgentNnEntry* agent ) {}
		virtual void assertThereIsNoCollisionInformationForAgent( hkpAgentNnEntry* agent ) {}
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationQueue;
		virtual void reintegrateAndRecollideEntities( hkpEntity** entityBatch, int numEntities, hkpWorld* world, int reintegrateRecollideMode );
	protected:
		void checkDeltaTimeIsOk( hkReal deltaTime );
		hkpStepResult reCollideAfterStepFailure();
		virtual void collideInternal( const hkStepInfo& stepInfoIn );
		void integrateInternal( const hkStepInfo& stepInfoIn );
		void applyActions();
		static __forceinline void integrateIsland( hkpSimulationIsland* isle, const hkpWorldDynamicsStepInfo& stepInfo, hkpConstraintQueryIn& constraintQueryIn );
		static __forceinline void collideIslandNarrowPhaseDiscrete( hkpSimulationIsland* isle, const hkpProcessCollisionInput& input);
		hkReal snapSimulateTimeAndGetTimeToAdvanceTo();
		typedef void (hkpSimulation::*AgentEntryProcessFunction)(hkpAgentNnEntry*, const hkpProcessCollisionInput&, hkpProcessCollisionOutput&);
		void FUN_0097fef0( hkpEntity** entities, int numEntities, const hkpProcessCollisionInput& input, AgentEntryProcessFunction processingFunction, FindContacts findExtraContacts );
		void processAgentCollideDiscrete(hkpAgentNnEntry* entry, const hkpProcessCollisionInput& processInput, hkpProcessCollisionOutput& processOutput);
		void processAgentResetCollisionInformation(hkpAgentNnEntry* entry, const hkpProcessCollisionInput& processInput, hkpProcessCollisionOutput& processOutput);
	public:
		enum LastProcessingStep
		{
			INTEGRATE,
			COLLIDE
		};
        hkEnum<LastProcessingStep,hkUint8> m_lastProcessingStep;
		hkTime m_currentTime;
		hkTime m_currentPsiTime;
		hkReal m_physicsDeltaTime;
		hkTime m_simulateUntilTime;
		hkReal m_frameMarkerPsiSnap;
        hkUint32 m_previousStepResult;
};
class hkpCollisionDispatcher;
class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionAgentConfig;
struct hkpCollisionInput
{
	public:
		hkReal getTolerance() const { return m_tolerance; }
		void setTolerance(hkReal t) { m_tolerance = t; }
	public:
		hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
		hkPadSpu<hkReal> m_tolerance;
		hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
		hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
		mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
		struct Aabb32Info
		{
			hkVector4 m_bitOffsetLow;
			hkVector4 m_bitOffsetHigh;
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
};
struct hkpCollisionQualityInfo;
struct hkpProcessCollisionInput : public hkpCollisionInput
{
	public:
		hkStepInfo m_stepInfo;
		mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
		void*	m_dynamicsInfo;
		bool m_enableDeprecatedWelding;
		hkpCollisionAgentConfig* m_config;
};
struct hkpProcessCdPoint
{
	hkContactPoint m_contact;
    hkPadSpu<hkUint32>	m_contactPointId;
};
class hkContactPointMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline void setUserData( hkUlong data );
		inline hkBool32 isPotential();
		inline void setMaxImpulsePerStep( hkUFloat8 impulse );
		inline hkReal getMaxImpulsePerStep();
	protected:
		hkUlong m_userData;
		hkUFloat8 m_friction;
		hkUint8 m_restitution;
	public:
		hkUFloat8 m_maxImpulse;
	public:
		void reset()
		{
			m_friction.m_value = 0;
			m_maxImpulse.m_value = 0;
			m_restitution = 0;
			m_flags = CONTACT_IS_NEW_AND_POTENTIAL;
		}
		enum  FlagEnum
		{
			CONTACT_IS_NEW_AND_POTENTIAL  = 1,
			CONTACT_USES_SOLVER_PATH2 = 2,
			CONTACT_BREAKOFF_OBJECT_ID = 4,
		};
		hkUint8 m_flags;
		friend class hkpSaveContactPointsEndianUtil;
};
class hkpTriangleShape;
class hkpGskCache
{
		typedef hkUint8 GskFlags;
		enum GskFlagValues
		{
			GSK_FLAGS_SHAPE_A_IS_CYLINDER           = 0x01,
			GSK_FLAGS_SHAPE_B_IS_CYLINDER           = 0x02,
			GSK_FLAGS_PROCESS_FUNCTION_CALLED  = 0x40,
			ONE_BIT_STILL_UNUSED     = 0x80
		};
		hkUint8 m_gskFlags;
	public:
		void init( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& btoa );
		void initTriangle( const hkpConvexShape* shapeA, const hkpTriangleShape* shapeB, const hkTransform& btoa );
		inline void flip();
};
__declspec(align(16)) class hkGskCache16 : public hkpGskCache
{
	public:
		void set(const hkGskCache16& other)
		{
				*this = other;
		}
};
struct hkpSimpleContactConstraintAtom;
class hkpContactPointProperties : public hkpSolverResults, public hkContactPointMaterial
{
	public:
		hkReal m_internalDataA;
		typedef hkUint32 UserData;
		static inline int getNumExtendedUserDatas(const hkpSimpleContactConstraintAtom* atom, int bodyIdx);
		inline hkpContactPointProperties::UserData& getExtendedUserData(const hkpSimpleContactConstraintAtom* atom, int bodyIdx, int i);
};
__declspec(align(16)) class hkContactPointPropertiesWithExtendedUserData16 : public hkpContactPointProperties
{
	public:
		void set(const hkContactPointPropertiesWithExtendedUserData16& other)
		{
			*this = other;
		}
		hkpContactPointProperties::UserData m_extendedUserDatas[7];
};
enum {HK_MAX_CONTACT_POINT = 256 };
struct hkpAgentEntry;
struct hkpProcessCollisionData
{
	public:
		hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
		hkPadSpu<hkpConstraintOwner*> m_constraintOwner;
		hkpProcessCdPoint   m_contactPoints[HK_MAX_CONTACT_POINT];
		struct ToiInfo
		{
			public:
				inline ToiInfo();
				inline void flip();
			public:
				hkContactPoint     m_contactPoint;
				hkPadSpu<hkReal>   m_time;
				hkPadSpu<hkReal>      m_seperatingVelocity;
				hkGskCache16			m_gskCache;
				hkContactPointPropertiesWithExtendedUserData16 m_properties;
		};
		struct ToiInfo m_toi;
		inline hkpProcessCollisionData( hkpConstraintOwner* owner );
};
hkpProcessCollisionData::ToiInfo::ToiInfo() : m_time( 3.40282e+38f )
{
}
hkpProcessCollisionData::hkpProcessCollisionData( hkpConstraintOwner* owner )
{
	m_constraintOwner = owner;
}
struct hkpProcessCollisionOutput: public hkpProcessCollisionData
{
	public:
		inline hkpProcessCollisionOutput(hkpConstraintOwner* owner): hkpProcessCollisionData(owner){}
		inline void reset()
		{
			m_firstFreeContactPoint = &m_contactPoints[0];
			m_toi.m_time = 3.40282e+38f;
			m_potentialContacts = 0;
		}
		inline hkpProcessCdPoint* reserveContactPoints( int numberOfPoints=1 )
		{
			return m_firstFreeContactPoint;
		}
		inline void commitContactPoints( int numberOfPoints=1 )
		{
		}
	public:
		struct ContactRef
		{
			hkpProcessCdPoint*	m_contactPoint;
			hkpAgentEntry*		m_agentEntry;
			void*			    m_agentData;
		};
		struct PotentialInfo
		{
			void reset()
			{
				m_firstFreePotentialContact      = &m_potentialContacts[0];
				m_firstFreeRepresentativeContact = &m_representativeContacts[0];
			}
			ContactRef*        m_firstFreePotentialContact;
			hkpProcessCdPoint** m_firstFreeRepresentativeContact;
			hkpProcessCdPoint*  m_representativeContacts[ HK_MAX_CONTACT_POINT ];
			ContactRef         m_potentialContacts[ HK_MAX_CONTACT_POINT ];
		};
	public:
		hkPadSpu<PotentialInfo*>    m_potentialContacts;
};
class hkpContactMgr;
struct hkpAgentEntry
{
	hkUchar     m_streamCommand;
	hkUchar     m_agentType;
	hkUchar     m_numContactPoints;
	hkUchar     m_size;
};
struct hkpAgentNnEntry: hkpAgentEntry
{
	hkObjectIndex		m_agentIndexOnCollidable[2];
	hkpContactMgr*		m_contactMgr;
	hkUchar				m_collisionQualityIndex;
	hkUchar				m_forceCollideOntoPpu;
	hkUchar				m_padding[2];
	hkpLinkedCollidable*	m_collidable[2];
	inline hkpCollidable*  getCollidableA(){ return reinterpret_cast<hkpCollidable*>(m_collidable[0]); }
	inline hkpCollidable*  getCollidableB(){ return reinterpret_cast<hkpCollidable*>(m_collidable[1]); }
};
struct hkpAgentNnSector;
struct hkpAgentNnTrack
{
	hkpAgentNnTrack( )
	{
		m_bytesUsedInLastSector = 512;
		;
	}
	int getSectorSize( int sectorIndex ) const
	{
		if ( sectorIndex+1 == m_sectors.getSize())
		{
			return m_bytesUsedInLastSector;
		}
		return 512;
	}
	hkUint32	m_bytesUsedInLastSector;
	hkInplaceArray<hkpAgentNnSector*,1> m_sectors;
};
class hkpConstraintOwner: public hkReferencedObject
{
	public:
		inline void addConstraintInfo( hkpConstraintInstance* constraint, hkpConstraintInfo& delta )
		{
			;
			if ( constraint->m_internal )
			{
				m_constraintInfo.sub( delta );
				constraint->m_internal->subConstraintInfo( delta );
			}
		}
	public:
		hkpConstraintInfo m_constraintInfo;
};
class hkUnionFind;
class hkpSimulationIsland : public hkpConstraintOwner
{
		hkTime m_timeOfDeactivation;
			hkInplaceArray<hkpEntity*,1> m_entities;
		hkpAgentNnTrack m_agentTrack;
		;
};
class hkpEntityDeactivator : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual hkBool shouldDeactivateHighFrequency( const hkpEntity* entity ) = 0;
		enum DeactivatorType
		{
			DEACTIVATOR_INVALID,
			DEACTIVATOR_NEVER,
			DEACTIVATOR_SPATIAL,
			DEACTIVATOR_MAX_ID
		};
		virtual enum DeactivatorType getRigidBodyDeactivatorType() const = 0;
};
class hkpRigidBodyCinfo;
class hkpRigidBody : public hkpEntity
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpRigidBody( const hkpRigidBodyCinfo& info );
		inline void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
		inline void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
		void setCenterOfMassLocal(const hkVector4& centerOfMass);
		inline const hkVector4& getCenterOfMassLocal() const;
		inline const hkVector4& getCenterOfMassInWorld() const;
		inline const hkVector4& getPosition() const;
		void setPosition(const hkVector4& position);
		inline const hkQuaternion& getRotation() const;
		void setRotation(const hkQuaternion& rotation);
		void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
		inline const hkTransform& getTransform() const;
		void setTransform(const hkTransform& transform);
		void setPositionAndRotationAsCriticalOperation(const hkVector4& position, const hkQuaternion& rotation);
		inline void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		inline void approxCurrentTransform( hkTransform& transformOut ) const;
		inline hkReal getRestitution() const;
		void setFriction( hkReal newFriction );
		void setRestitution( hkReal newRestitution );
		hkWorldOperation::Result setShape(const hkpShape* shape);
		virtual hkpRigidBody* clone() const;
	public:
		inline hkpMotion* getRigidMotion() const;
		void checkPerformance() const;
	public:
		static void __cdecl createDynamicRigidMotion( hkpMotion::MotionType motionType,
																const hkVector4& position, const hkQuaternion& rotation,
																hkReal mass, const hkMatrix3& inertiaLocal, const hkVector4& centreOfMassLocal,
																hkReal maxLinearVelocity, hkReal maxAngularVelocity,
																hkpMaxSizeMotion* motionBufferOut );
		static void __cdecl updateBroadphaseAndResetCollisionInformationOfWarpedBody( hkpEntity* entity );
	protected:
		virtual hkMotionState* getMotionState();
	public:
		hkpRigidBody( class hkFinishLoadedObjectFlag flag ) : hkpEntity( flag ) {}
};
inline hkpMotion* hkpRigidBody::getRigidMotion() const
{
	return const_cast<hkpMaxSizeMotion*>(&m_motion);
}
const hkVector4& hkpRigidBody::getCenterOfMassLocal() const
{
	return getRigidMotion()->getCenterOfMassLocal();
}
const hkVector4& hkpRigidBody::getCenterOfMassInWorld() const
{
	return getRigidMotion()->getCenterOfMassInWorld();
}
inline const hkQuaternion& hkpRigidBody::getRotation() const
{
	return getRigidMotion()->getRotation();
}
inline const hkTransform& hkpRigidBody::getTransform() const
{
	return getRigidMotion()->getTransform();
}
struct hkpCollisionQualityInfo
{
	__declspec(align(16)) hkReal m_keepContact;
	hkReal m_create4dContact;
	hkReal m_createContact;
	hkReal m_manifoldTimDistance;
	hkPadSpu<hkBool32>		m_useContinuousPhysics;
	hkReal m_minSeparation;
	hkReal m_minExtraSeparation;
	hkReal m_minSafeDeltaTime;
	hkReal m_minAbsoluteSafeDeltaTime;
	hkReal m_toiSeparation;
	hkReal m_toiExtraSeparation;
	hkReal m_toiAccuracy;
	hkReal m_maxContraintViolation;
	hkReal m_minToiDeltaTime;
	hkUint16	m_constraintPriority;
	hkBool m_enableToiWeldRejection;
	hkReal calcMinSeparation( hkReal currentDistance ) const
	{
		return m_minSeparation;
	}
};
extern "C"
{
void __cdecl hkAgentNnMachine_InvalidateTimInAgent( hkpAgentNnEntry* entry, hkpCollisionInput& input );
}
struct hkMemoryStatistics;
class hkLimitedMemoryListener;
typedef void (__cdecl *hkMemoryWalkCallback)(void* start, hk_size_t size,hkBool allocated,int pool,void* param);
class hkMemory
{
	public:
		friend class hkThreadMemory;
		hkMemory();
		virtual ~hkMemory();
		virtual void allocateChunkBatch(void** blocksOut, int nblocks, int nbytes) = 0;
		virtual void deallocateChunkBatch(void** blocksOut, int nblocks, int nbytes) = 0;
		virtual void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void deallocateChunk( void*, int nbytes, HK_MEMORY_CLASS cl ) = 0;
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
		static void __cdecl replaceInstance(hkMemory* m);
		__forceinline void addReference();
		__forceinline void removeReference();
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
static __forceinline void hkSimulation_setRotation( hkpRigidBody* body, const hkQuaternion& rotation, hkTransform& transform )
{
	transform.setRotation( rotation );
	hkVector4 centerShift; centerShift._setRotatedDir( transform.getRotation(), body->getCenterOfMassLocal() );
	transform.getTranslation().setSub4( body->getCenterOfMassInWorld(), centerShift );
}
// pdb: hkpSimulation::processAgentsOfEntities | hkpSimulation.obj | fnv360_0822_retail, objrun, medium
// pdb params: entities, numEntities, processInput, processingFunction, findExtraContacts
void hkpSimulation::FUN_0097fef0( hkpEntity** entities, int numEntities, const hkpProcessCollisionInput& processInput, AgentEntryProcessFunction processingFunction, FindContacts findExtraContacts )
{
	hkPointerMapBase<hkUlong> processedEntities( numEntities );
	__declspec(align(16)) typedef hkpProcessCollisionOutput hkAlignedCollisionOutput;
	hkAlignedCollisionOutput processOutput( 0 );
	for ( int i = 0; i < numEntities; i++ )
	{
		hkpEntity* entity = entities[i];
		hkpLinkedCollidable* lColl = entity->getLinkedCollidable();
		processedEntities.insert( hkUlong(lColl), 0 );
		for ( int c = 0; c < lColl->m_collisionEntries.getSize(); c++ )
		{
			hkpLinkedCollidable::CollisionEntry& cEntry = lColl->m_collisionEntries[c];
			hkpLinkedCollidable* partner = cEntry.m_partner;
			hkPointerMapBase<hkUlong>::Iterator it = processedEntities.findKey( hkUlong(partner) );
			if ( processedEntities.isValid( it ) )
			{
				continue;
			}
			hkpAgentNnEntry* entry = cEntry.m_agentEntry;
			{
				hkpEntity* entityA = static_cast<hkpEntity*>( entry->m_collidable[0]->getOwner() );
				hkpEntity* entityB = static_cast<hkpEntity*>( entry->m_collidable[1]->getOwner() );
				hkpSimulationIsland* island = ( entityA->isFixed() ) ? entityB->getSimulationIsland() : entityA->getSimulationIsland();
				processOutput.m_constraintOwner = island;
			}
			hkAgentNnMachine_InvalidateTimInAgent( entry, const_cast<hkpProcessCollisionInput&>( processInput ) );
			(this->*processingFunction)( entry, processInput, processOutput );
			if ( findExtraContacts == FIND_CONTACTS_EXTRA && processOutput.m_firstFreeContactPoint != processOutput.m_contactPoints )
			{
				hkpRigidBody* rb = static_cast<hkpRigidBody*>( entity );
				hkQuaternion origRot = rb->getRotation();
				hkTransform origTrans = rb->getTransform();
				hkVector4 normal = processOutput.m_contactPoints[0].m_contact.getNormal();
				if ( cEntry.m_agentEntry->getCollidableA() != entity->getCollidable() )
				{
					normal.setNeg4( normal );
				}
				hkVector4 diff; diff.setSub4( rb->getCenterOfMassInWorld(), processOutput.m_contactPoints[0].m_contact.getPosition() );
				hkVector4 rotateDir; rotateDir.setCross( normal, diff );
				hkReal len = rotateDir.length3();
				hkReal l = normal.dot3( diff );
				hkReal d = diff.length3();
				hkReal rotateSinFrom = l / d;
				if ( len > 1e-5f && rotateSinFrom < 0.9999f )
				{
					const hkReal toleranceMult = 20.0f;
					hkReal savedTolerance = processInput.m_tolerance;
					hkReal searchTolerance = processInput.m_tolerance * toleranceMult;
					const_cast<hkpProcessCollisionInput&>( processInput ).m_tolerance = searchTolerance;
					hkReal savedCreate4dContact = processInput.m_collisionQualityInfo->m_create4dContact;
					hkReal savedCreateContact = processInput.m_collisionQualityInfo->m_createContact;
					processInput.m_collisionQualityInfo->m_create4dContact = searchTolerance;
					processInput.m_collisionQualityInfo->m_createContact = searchTolerance;
					hkReal rotateSinTo = hkMath::max2( ( l - searchTolerance * ( 1.0f / toleranceMult ) ) / d, 0.0f );
					hkReal rotateAngle = hkMath::asin( rotateSinFrom ) - hkMath::asin( rotateSinTo );
					rotateDir.mul4( 1.0f / len );
					{
						hkQuaternion quat; quat.setAxisAngle( rotateDir, rotateAngle );
						hkQuaternion rbRot; rbRot.setMul( quat, rb->getRotation() );
						hkSimulation_setRotation( rb, rbRot, rb->getRigidMotion()->getMotionState()->getTransform() );
						hkAgentNnMachine_InvalidateTimInAgent( entry, const_cast<hkpProcessCollisionInput&>( processInput ) );
						(this->*processingFunction)( entry, processInput, processOutput );
					}
					{
						hkVector4 rotateCrossDir; rotateCrossDir.setCross( rotateDir, normal );
						rotateCrossDir.normalize3();
						hkQuaternion quat; quat.setAxisAngle( rotateCrossDir, rotateAngle );
						hkQuaternion rbRot; rbRot.setMul( quat, origRot );
						hkSimulation_setRotation( rb, rbRot, rb->getRigidMotion()->getMotionState()->getTransform() );
						hkAgentNnMachine_InvalidateTimInAgent( entry, const_cast<hkpProcessCollisionInput&>( processInput ) );
						(this->*processingFunction)( entry, processInput, processOutput );
						rbRot.setInverseMul( quat, origRot );
						hkSimulation_setRotation( rb, rbRot, rb->getRigidMotion()->getMotionState()->getTransform() );
						hkAgentNnMachine_InvalidateTimInAgent( entry, const_cast<hkpProcessCollisionInput&>( processInput ) );
						(this->*processingFunction)( entry, processInput, processOutput );
					}
					const_cast<hkpProcessCollisionInput&>( processInput ).m_tolerance = savedTolerance;
					processInput.m_collisionQualityInfo->m_create4dContact = savedCreate4dContact;
					processInput.m_collisionQualityInfo->m_createContact = savedCreateContact;
					rb->getRigidMotion()->setTransform( origTrans );
					hkAgentNnMachine_InvalidateTimInAgent( entry, const_cast<hkpProcessCollisionInput&>( processInput ) );
					(this->*processingFunction)( entry, processInput, processOutput );
				}
			}
			if ( hkMemory::getInstance().m_memoryState == hkMemory::MEMORY_STATE_OUT_OF_MEMORY )
			{
				return;
			}
		}
	}
}

}  // namespace f3m_0097fef0

// @f3 0x00962a60 (community match, verified in this file)
// 0x00962a60: hkaSkeletonMapper::mapPose(const hkQsTransform* poseAModelSpace, const hkQsTransform* originalPoseBLocalSpace,
// hkQsTransform* poseBModelSpace, ConstraintSource source) const of Havok 5.5.0 (hkaAnimation, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Maps a model-space pose of skeleton A to skeleton B: simple mappings bone to bone, chain mappings (the chain's
// start and end mapped, the start rotated so the chain points at the mapped end, the children re-derived from their
// local transforms), unmapped bones kept local when asked, then the skeleton's or the pose's constraints.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The SDK's int 3 traps in the unused placement
// operators new[] and delete[] were removed by hand. The function body follows the SDK's unoptimized (hybrid)
// library object statement by statement and reproduces the release object. Only the function carries the
// packet's name.
namespace f3m_00962a60 {

typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
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
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
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
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
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
template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
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
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
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
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}
template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	;
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
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}
template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkQsTransform
{
	public:
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(IdentityInitializer init);
		__forceinline hkQsTransform(ZeroInitializer init);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation);
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline void set(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline void setIdentity();
		__forceinline static const hkQsTransform& __cdecl getIdentity();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline const hkVector4& getScale() const;
		__forceinline void setScale(const hkVector4& s);
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setInterpolate4( const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
		void setFromTransformNoScale (const hkTransform& transform);
		void copyToTransformNoScale (hkTransform& transformOut) const;
		void setFromTransform (const hkTransform& transform);
		void copyToTransform (hkTransform& transformOut) const;
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
		__forceinline void setMulMulInverse( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulEq( const hkQsTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		hkBool set4x4ColumnMajor(const hkReal* p);
		hkBool isOk() const;
		hkBool isApproximatelyEqual( const hkQsTransform& other, hkReal epsilon=1e-3f ) const;
		__forceinline void setZero();
		__forceinline void blendAddMul(const hkQsTransform& other,  hkSimdRealParameter weight = 1.0f );
		__forceinline void blendNormalize( hkSimdRealParameter totalWeight = 1.0f);
		__forceinline void fastRenormalize( hkSimdRealParameter totalWeight = 1.0f);
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( quat.getImag(), direction );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}
inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}
inline void hkQuaternion::operator= (const hkQuaternion& q)
{
	m_vec = q.m_vec;
}
inline void hkQuaternion::setMul(const hkQuaternion& q0, const hkQuaternion& q1)
{
	hkVector4 vec;
	vec.setCross(q0.getImag(), q1.getImag());
	vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
	vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
	hkReal real = q0.getReal() * q1.getReal() - hkReal( q0.m_vec.dot3( q1.m_vec ) );
	m_vec = vec;
	m_vec(3) = real;
}
const hkVector4& hkQsTransform::getTranslation() const
{
	return m_translation;
}
const hkQuaternion& hkQsTransform::getRotation() const
{
	return m_rotation;
}
void hkQsTransform::setRotation(const hkQuaternion& rotation)
{
	m_rotation = rotation;
}
void hkQsTransform::setMul( const hkQsTransform& aTb, const hkQsTransform& bTc )
{
	hkVector4 extraTrans;
	extraTrans.setRotatedDir(aTb.m_rotation, bTc.m_translation);
	m_translation.setAdd4(aTb.m_translation, extraTrans);
	m_rotation.setMul(aTb.m_rotation, bTc.m_rotation);
	m_scale.setMul4(aTb.m_scale, bTc.m_scale);
}
void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
class hkaSkeleton;
class hkaSkeletonMapperData
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		struct SimpleMapping
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			SimpleMapping()
			{
				m_boneA = 0;
				m_boneB = 0;
				m_aFromBTransform.setIdentity();
			}
			hkInt16 m_boneA;
			hkInt16 m_boneB;
			hkQsTransform m_aFromBTransform;
		};
		struct ChainMapping
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			ChainMapping()
			{
				m_startBoneA = 0;
				m_endBoneA = 0;
				m_startBoneB = 0;
				m_endBoneB = 0;
				m_startAFromBTransform.setIdentity();
				m_endAFromBTransform.setIdentity();
			}
			hkInt16 m_startBoneA;
			hkInt16 m_endBoneA;
			hkInt16 m_startBoneB;
			hkInt16 m_endBoneB;
			hkQsTransform m_startAFromBTransform;
			hkQsTransform m_endAFromBTransform;
		};
		hkaSkeletonMapperData()
		{
			m_skeletonA = 0;
			m_skeletonB = 0;
			m_keepUnmappedLocal = true;
		}
		hkaSkeletonMapperData( hkFinishLoadedObjectFlag f ) : m_simpleMappings(f), m_chainMappings(f), m_unmappedBones(f) {}
		const hkaSkeleton* m_skeletonA;
		const hkaSkeleton* m_skeletonB;
		hkArray<struct SimpleMapping> m_simpleMappings;
		hkArray<struct ChainMapping> m_chainMappings;
		hkArray<hkInt16> m_unmappedBones;
		hkBool m_keepUnmappedLocal;
};
class hkaPose;
class hkaSkeletonMapper : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkaSkeletonMapper( const hkaSkeletonMapperData& mapping );
		virtual ~hkaSkeletonMapper();
		enum ConstraintSource
		{
			NO_CONSTRAINTS,
			REFERENCE_POSE,
			CURRENT_POSE
		};
		void __cdecl hkaSkeletonMapper_mapPose(const hkQsTransform* poseAModelSpace, const hkQsTransform* originalPoseBLocalSpace, hkQsTransform* poseBModelSpaceInOut, ConstraintSource source ) const;
		void __cdecl mapPose(const hkaPose& poseAIn, hkaPose& poseBInOut, ConstraintSource source ) const;
	public:
		class hkaSkeletonMapperData m_mapping;
	public:
		static void __cdecl checkMapping(const hkaSkeletonMapperData& mapping);
	public:
		hkaSkeletonMapper( hkFinishLoadedObjectFlag f ) : hkReferencedObject(f), m_mapping(f) { }
};
class hkMonitorStream
{
	public:
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
		__forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); }
		__forceinline char* __cdecl getCapacity() { return m_capacity.val(); }
		__forceinline hkBool __cdecl memoryAvailable( )
		{
			return getEnd() < getCapacityMinus16();
		}
		__forceinline int __cdecl getCurrentMonitorDataSize()
		{
			return (int)(m_end.val() - m_start.val());
		}
		__forceinline void* __cdecl expandby( int size ) { char* h = m_end.val(); char* newEnd = h + size; m_end = newEnd; return h; }
		__forceinline void __cdecl setEnd(char* ptr) {  m_end = ptr; }
		__forceinline hkBool __cdecl isBufferAllocatedOnTheHeap() { return m_isBufferAllocatedOnTheHeap; }
		void __cdecl setStaticBuffer( char* buffer, int bufferSize );
	public:
		static void __cdecl init();
		void __cdecl quit();
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
	public:
		struct Command
		{
			const char* m_commandAndMonitor;
		};
		struct AddValueCommand : public hkMonitorStream::Command
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMonitorStream::AddValueCommand), HK_MEMORY_CLASS_MONITOR); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			float m_value;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMonitorStream::TimerCommand), HK_MEMORY_CLASS_MONITOR); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkUint32	m_time0;
			hkUint32	m_time1;
			__forceinline void setTime();
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMonitorStream::TimerBeginListCommand), HK_MEMORY_CLASS_MONITOR); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MONITOR); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			const char* m_nameOfFirstSplit;
		};
};
void hkMonitorStream::TimerCommand::setTime()
{
		hkUint32 ticks;
		__asm {
			rdtsc
			mov dword ptr[ticks], eax
		}
		m_time0 = ticks;
}
class hkaBone;
class hkaSkeleton
{
	public:
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeleton), HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		inline hkaSkeleton();
		const char* m_name;
		hkInt16* m_parentIndices;
		hkInt32 m_numParentIndices;
		hkaBone** m_bones;
		hkInt32 m_numBones;
		hkQsTransform* m_referencePose;
		int		m_numReferencePose;
		char**	m_floatSlots;
		hkInt32 m_numFloatSlots;
	public:
		__forceinline hkaSkeleton( hkFinishLoadedObjectFlag flag ) {}
};
typedef int (__cdecl* hkStringCompareFunc)(const char*, const char*);
class hkaSkeletonUtils
{
	public:
		static void __cdecl transformLocalPoseToModelPose ( int numTransforms, const hkInt16* parentIndices, const hkQsTransform* poseLocal, hkQsTransform* poseModelOut);
		static void __cdecl transformModelPoseToLocalPose ( int numTransforms, const hkInt16* parentIndices, const hkQsTransform* poseModel, hkQsTransform* poseLocalOut);
		static void __cdecl transformModelPoseToWorldPose ( int numTransforms, const hkQsTransform& worldFromModel, const hkQsTransform* poseModel, hkQsTransform* poseWorldOut);
		static void __cdecl transformWorldPoseToModelPose ( int numTransforms, const hkQsTransform& worldFromModel, const hkQsTransform* poseWorld, hkQsTransform* poseModelOut);
		static void __cdecl transformLocalPoseToWorldPose ( int numTransforms, const hkInt16* parentIndices, const hkQsTransform& worldFromModel, const hkQsTransform* poseLocal, hkQsTransform* poseWorldOut);
		static void __cdecl transformWorldPoseToLocalPose ( int numTransforms, const hkInt16* parentIndices, const hkQsTransform& worldFromModel, const hkQsTransform* poseWorld, hkQsTransform* poseLocalOut);
		static void __cdecl blendPoses( hkUint32 numBones, const hkQsTransform* poseA, const hkQsTransform* poseB, const hkReal* weights, hkQsTransform* poseOut );
		static void __cdecl blendPoses( hkUint32 numBones, const hkQsTransform* poseA, const hkQsTransform* poseB, const hkReal weight, hkQsTransform* poseOut );
		static void __cdecl blendPartialPoses( hkUint32 numBones, hkInt16* bones, const hkQsTransform* poseA, const hkQsTransform* poseB, const hkReal weight, hkQsTransform* poseOut );
		static void __cdecl enforceSkeletonConstraintsLocalSpace(const hkaSkeleton& skeleton, hkQsTransform* poseLocalInOut);
		static void __cdecl enforceSkeletonConstraintsModelSpace(const hkaSkeleton& skeleton, hkQsTransform* poseModelInOut);
		static void __cdecl enforcePoseConstraintsLocalSpace (const hkaSkeleton& skeleton, const hkQsTransform* constraintsLocal, hkQsTransform* poseInOut);
		static void __cdecl enforcePoseConstraintsModelSpace (const hkaSkeleton& skeleton, const hkQsTransform* constraintsLocal, hkQsTransform* poseModelInOut);
		static hkInt16 __cdecl findBoneWithName (const hkaSkeleton& skeleton, const char* name, hkStringCompareFunc compare = 0);
		static void __cdecl lockTranslations (const hkaSkeleton& skeleton, hkBool exceptRoots = true);
		static void __cdecl unlockTranslations (const hkaSkeleton& skeleton);
		static hkBool __cdecl getBoneChain(const hkaSkeleton& skeleton, hkInt16 startBone, hkInt16 endBone, hkArray<hkInt16>& bonesOut);
		static void __cdecl getDescendants(const hkaSkeleton& skeleton, hkInt16 startBone, hkArray<hkInt16>& bonesOut);
		static void __cdecl getLeaves(const hkaSkeleton& skeleton, hkArray<hkInt16>& leavesOut);
		static hkBool __cdecl isBindingOk( const hkaSkeleton& skeleton, const class hkaAnimationBinding& binding );
		static void __cdecl getModelSpaceScale (const hkaSkeleton& skeleton, const hkQsTransform* poseLocal, int boneId, hkVector4& scaleOut);
		static void __cdecl normalizeRotations(hkQsTransform* transformsInOut, int numTransforms );
		static hkResult __cdecl bindByName(const hkaSkeleton& skeleton, const class hkaSkeletalAnimation& anim, hkStringCompareFunc compare, class hkaAnimationBinding& bindingOut);
};
template <typename T>
class hkLocalArray : public hkArray<T>
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkLocalArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkLocalArray( int capacity )
		{
			this->m_data = hkAllocateStack<T>(capacity);
			this->m_capacityAndFlags = capacity | hkArray<T>::DONT_DEALLOCATE_FLAG;
			m_localMemory = this->m_data;
		}
		__forceinline void discardAndResize(int newsize)
		{
			;
			hkDeallocateStack<T>( m_localMemory );
			m_localMemory = this->m_data = hkAllocateStack<T>(newsize);
			this->m_size = newsize;
			this->m_capacityAndFlags = newsize | hkArray<T>::DONT_DEALLOCATE_FLAG;
		}
		void assertNotResized()
		{
			;
		}
		hkBool wasReallocated() const
		{
			return m_localMemory != this->m_data;
		}
		__forceinline ~hkLocalArray()
		{
			hkDeallocateStack<T>( m_localMemory );
		}
		T* m_localMemory;
};
// pdb: hkaSkeletonMapper::mapPose | hkaSkeletonMapper.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void hkaSkeletonMapper::hkaSkeletonMapper_mapPose( const hkQsTransform* poseAModelSpace, const hkQsTransform* originalPoseBLocalSpace, hkQsTransform* poseBModelSpace, ConstraintSource source ) const
{
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "L" "t" "MapPose"; h->m_nameOfFirstSplit = "S" "t" "init"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "simpleMappings"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	{
		const int numSimpleMappings = m_mapping.m_simpleMappings.getSize();
		for ( int i = 0; i < numSimpleMappings; i++ )
		{
			const hkaSkeletonMapperData::SimpleMapping& simpleMapping = m_mapping.m_simpleMappings[i];
			poseBModelSpace[simpleMapping.m_boneB].setMul( poseAModelSpace[simpleMapping.m_boneA], simpleMapping.m_aFromBTransform );
		}
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "chainMappings"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	{
		const int numChainMappings = m_mapping.m_chainMappings.getSize();
		for ( int i = 0; i < numChainMappings; i++ )
		{
			const hkaSkeletonMapperData::ChainMapping& chainMapping = m_mapping.m_chainMappings[i];
			const hkInt16 startBoneA = chainMapping.m_startBoneA;
			const hkInt16 endBoneA = chainMapping.m_endBoneA;
			const hkInt16 startBoneB = chainMapping.m_startBoneB;
			const hkInt16 endBoneB = chainMapping.m_endBoneB;
			poseBModelSpace[startBoneB].setMul( poseAModelSpace[startBoneA], chainMapping.m_startAFromBTransform );
			hkLocalArray<hkInt16> chainBones( endBoneB - startBoneB + 1 );
			hkaSkeletonUtils::getBoneChain( *m_mapping.m_skeletonB, startBoneB, endBoneB, chainBones );
			hkVector4 currentEndModelSpacePos; currentEndModelSpacePos = originalPoseBLocalSpace[endBoneB].getTranslation();
			for ( int b = chainBones.getSize() - 2; b >= 1; b-- )
			{
				hkInt16 bone = chainBones[b];
				currentEndModelSpacePos.setTransformedPos( originalPoseBLocalSpace[bone], currentEndModelSpacePos );
			}
			currentEndModelSpacePos.setTransformedPos( poseBModelSpace[startBoneB], currentEndModelSpacePos );
			{
				const hkVector4& startModelSpacePos = poseBModelSpace[startBoneB].getTranslation();
				hkQsTransform desiredEndModelSpace; desiredEndModelSpace.setMul( poseAModelSpace[endBoneA], chainMapping.m_endAFromBTransform );
				const hkVector4& desiredEndModelSpacePos = desiredEndModelSpace.getTranslation();
				hkVector4 currentDirection; currentDirection.setSub4( currentEndModelSpacePos, startModelSpacePos );
				currentDirection.normalize3();
				hkVector4 desiredDirection; desiredDirection.setSub4( desiredEndModelSpacePos, startModelSpacePos );
				desiredDirection.normalize3();
				hkQuaternion rotationQuaternion; rotationQuaternion.setShortestRotation( currentDirection, desiredDirection );
				hkQuaternion currentRot = poseBModelSpace[startBoneB].getRotation();
				hkQuaternion temp; temp.setMul( rotationQuaternion, currentRot );
				poseBModelSpace[startBoneB].setRotation( temp );
			}
			for ( int b = 1; b < chainBones.getSize() - 1; b++ )
			{
				hkInt16 childIdx = chainBones[b];
				hkInt16 parentIdx = chainBones[b - 1];
				const hkQsTransform& parentFromChild = originalPoseBLocalSpace[childIdx];
				const hkQsTransform& modelFromParent = poseBModelSpace[parentIdx];
				poseBModelSpace[childIdx].setMul( modelFromParent, parentFromChild );
			}
		}
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "unmappedBones"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	{
		const int numUnmapped = m_mapping.m_unmappedBones.getSize();
		if ( m_mapping.m_keepUnmappedLocal )
		{
			for ( int i = 0; i < numUnmapped; i++ )
			{
				const hkInt16 childIdx = m_mapping.m_unmappedBones[i];
				const hkInt16 parentIdx = m_mapping.m_skeletonB->m_parentIndices[childIdx];
				if ( parentIdx != -1 )
				{
					const hkQsTransform& parentFromChild = originalPoseBLocalSpace[childIdx];
					const hkQsTransform& modelFromParent = poseBModelSpace[parentIdx];
					poseBModelSpace[childIdx].setMul( modelFromParent, parentFromChild );
				}
				else
				{	poseBModelSpace[childIdx] = originalPoseBLocalSpace[childIdx];
				}
			}
		}
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "enforceConstraints"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	switch ( source )
	{
		case REFERENCE_POSE:
			hkaSkeletonUtils::enforceSkeletonConstraintsModelSpace( *m_mapping.m_skeletonB, poseBModelSpace );
			break;
		case CURRENT_POSE:
			hkaSkeletonUtils::enforcePoseConstraintsModelSpace( *m_mapping.m_skeletonB, originalPoseBLocalSpace, poseBModelSpace );
			break;
		default:
			break;
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "l" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
}

}  // namespace f3m_00962a60

// @f3 0x00964cd0 (community match, verified in this file)
// hkaSkeletonMapperUtils_createMapping: Havok 5.5.0 hkaSkeletonMapperUtils::createMapping (hkaAnimation): builds the two skeleton mappings
// (A to B and B to A) from the user's simple mappings and chains, then by name or position matching and chain
// detection, and lists the unmapped bones of each skeleton.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers and the
// preprocessed source was cut down mechanically to the declarations the function's code needs (whole declarations by
// hkreduce.py, every cut checked byte for byte against the full compile of this candidate), so the declarations are
// the SDK's text with its names; the SDK's trap instructions in the unused placement operators new[] and delete[] were
// removed. All its types ship in the SDK's headers; Match is the file's own pair of matched bones (the library's debug
// records name it). The body follows the SDK's hybrid library object line by line (all 124 named locals at the
// library's places; the only differences are line numbers inside shipped headers that are 1 to 3 lines off the
// library's copy). It reproduces the SDK's release object (20548 bytes) under Havok's own flags. The parentheses of
// tolSqrd's product (line 290 of the original file) matter: they keep a node the optimizer hashes, which numbers every
// later common subexpression one higher and so fixes the operand order of the six inlined transform products of
// lines 362, 372, 473, 474, 488 and 489.
namespace f3m_00964cd0 {

typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
typedef void* hk_va_list;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __int64 hkUint64;
typedef __int64 hkInt64;
typedef unsigned __w64 hk_size_t;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
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
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
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
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
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
template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
template <typename T>
class hkSingleton
{
	public:
		static T* s_instance;
		static __forceinline T& __cdecl getInstance()
		{
			return *s_instance;
		}
		static void __cdecl replaceInstance(T* t)
		{
			if(s_instance)
			{
				s_instance->removeReference();
			}
			s_instance = t;
		}
		static hkBool __cdecl isInitialised()
		{
			return s_instance != 0;
		}
	protected:
		hkSingleton() { }
		hkSingleton(const hkSingleton&);
		hkSingleton& operator= (const hkSingleton&);
};
class hkOstream;
class hkStreamWriter;
class hkString;
template<typename T> class hkArray;
namespace hkOstreamManip
{
typedef hkOstream& (__cdecl *function)(hkOstream&);
}
class hkOstream : public hkReferencedObject
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_STREAM)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_STREAM); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_STREAM)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_STREAM); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		explicit hkOstream(hkStreamWriter* sr);
		explicit hkOstream(const char* filename);
		hkOstream(void* mem, int memSize, hkBool isString=false);
		explicit hkOstream( hkArray<char>& buf );
		~hkOstream();
		hkBool isOk() const;
		hkOstream& operator<< (const void* p);
		hkOstream& operator<< (hkBool b);
		hkOstream& operator<< (char c);
		hkOstream& operator<< (signed char c);
		hkOstream& operator<< (unsigned char c);
		hkOstream& operator<< (const char* s);
		hkOstream& operator<< (const signed char* s);
		hkOstream& operator<< (const unsigned char* s);
		hkOstream& operator<< (short s);
		hkOstream& operator<< (unsigned short s);
		hkOstream& operator<< (int i);
		hkOstream& operator<< (unsigned int u);
		hkOstream& operator<< (float f);
		hkOstream& operator<< (double d);
		hkOstream& operator<< (hkInt64 i);
		hkOstream& operator<< (hkUint64 u);
		hkOstream& operator<< (const hkString& str);
		int write( const char* buf, int nbytes);
		void printf( const char *fmt, ...);
		void flush();
		hkOstream& operator<< (hkOstreamManip::function f);
		hkStreamWriter* getStreamWriter();
		void setStreamWriter(hkStreamWriter* newWriter);
	protected:
		hkStreamWriter*	m_writer;
};
class hkError : public hkReferencedObject, public hkSingleton<hkError>
{
	public:
		enum Message
		{
			MESSAGE_REPORT,
			MESSAGE_WARNING,
			MESSAGE_ASSERT,
			MESSAGE_ERROR
		};
		virtual int message(Message m, int id, const char* description, const char* file, int line) = 0;
		virtual void setEnabled( int id, hkBool enabled ) = 0;
		virtual hkBool isEnabled( int id ) = 0;
		virtual void enableAll() = 0;
		virtual void sectionBegin(int id, const char* sectionName) {}
		virtual void sectionEnd() {}
};
class hkErrStream : public hkOstream
{
	public:
		hkErrStream( void* buf, int bufSize );
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
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
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
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
__forceinline void __cdecl hkArray<T>::copy(T* dst, const T* src, int n)
{
	for(int i = 0; i < n; ++i)
	{
		dst[i] = src[i];
	}
}
template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
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
__forceinline hkArray<T>& hkArray<T>::operator= (const hkArray<T>& a)
{
	if(getCapacity() < a.m_size)
	{
		releaseMemory();
		m_data = static_cast<T*>( hkThreadMemory::getInstance().allocateChunk( a.m_size * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY));
		m_capacityAndFlags = a.m_size | (m_capacityAndFlags & static_cast<int>(LOCKED_FLAG));
	}
	m_size = a.m_size;
	copy(m_data, a.m_data, m_size);
	return *this;
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
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}
template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}
template <typename T>
__forceinline void hkArray<T>::setSizeUnchecked(int n)
{
	;
	m_size = n;
}
template <typename T>
__forceinline T& hkArray<T>::expandOne( )
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	return m_data[m_size++];
}
template <typename T>
__forceinline void hkArray<T>::setSize(int n, const T& fill)
{
	if(n > m_size)
	{
		int oldsize = m_size;
		reserve(n);
		for(int i = oldsize; i < n; ++i)
		{
			m_data[i] = fill;
		}
	}
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
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkQuaternion), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkQsTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkQsTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(IdentityInitializer init);
		__forceinline hkQsTransform(ZeroInitializer init);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation);
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline void set(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline void setIdentity();
		__forceinline static const hkQsTransform& __cdecl getIdentity();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline const hkVector4& getScale() const;
		__forceinline void setScale(const hkVector4& s);
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setInterpolate4( const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
		void setFromTransformNoScale (const hkTransform& transform);
		void copyToTransformNoScale (hkTransform& transformOut) const;
		void setFromTransform (const hkTransform& transform);
		void copyToTransform (hkTransform& transformOut) const;
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
		__forceinline void setMulMulInverse( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulEq( const hkQsTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		hkBool set4x4ColumnMajor(const hkReal* p);
		hkBool isOk() const;
		hkBool isApproximatelyEqual( const hkQsTransform& other, hkReal epsilon=1e-3f ) const;
		__forceinline void setZero();
		__forceinline void blendAddMul(const hkQsTransform& other,  hkSimdRealParameter weight = 1.0f );
		__forceinline void blendNormalize( hkSimdRealParameter totalWeight = 1.0f);
		__forceinline void fastRenormalize( hkSimdRealParameter totalWeight = 1.0f);
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
__forceinline void hkVector4::setXYZ0(const hkVector4& xyz)
{
	x = xyz.x;
	y = xyz.y;
	z = xyz.z;
	w = 0;
}
inline void hkVector4::setReciprocal3(const hkVector4& v)
{
	x = 1.0f / v.x;
	y = 1.0f / v.y;
	z = 1.0f / v.z;
	w = 1.0f;
}
inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w =  v.w;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}
__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( quat.getImag(), direction );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}
__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
	hkReal qreal = quat.m_vec(3);
	hkReal q2minus1 = qreal*qreal - 0.5f;
	hkVector4 ret;
	ret.setMul4( q2minus1, direction );
	hkReal imagDotDir = quat.getImag().dot3( direction );
	ret.addMul4( imagDotDir, quat.getImag() );
	hkVector4 imagCrossDir;
	imagCrossDir.setCross( direction, quat.getImag() );
	ret.addMul4( qreal, imagCrossDir );
	this->setAdd4( ret, ret );
}
inline const hkVector4& hkQuaternion::getImag() const
{
	return m_vec;
}
inline hkReal hkQuaternion::getReal() const
{
	return m_vec(3);
}
inline void hkQuaternion::operator= (const hkQuaternion& q)
{
	m_vec = q.m_vec;
}
inline void hkQuaternion::setIdentity()
{
	m_vec.set(0,0,0,1);
}
inline void hkQuaternion::setMul(const hkQuaternion& q0, const hkQuaternion& q1)
{
	hkVector4 vec;
	vec.setCross(q0.getImag(), q1.getImag());
	vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
	vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
	hkReal real = q0.getReal() * q1.getReal() - hkReal( q0.m_vec.dot3( q1.m_vec ) );
	m_vec = vec;
	m_vec(3) = real;
}
void hkQuaternion::setInverse( const hkQuaternion &q )
{
	m_vec.setNeg3( q.getImag() );
}
void hkQsTransform::setIdentity()
{
	m_translation.setZero4();
	m_rotation.setIdentity();
	m_scale.setAll(1.0f);
}
void hkQsTransform::setInverse( const hkQsTransform& t )
{
	;
	m_translation.setRotatedInverseDir(t.m_rotation, t.m_translation);
	m_translation.setNeg4(m_translation);
	m_rotation.setInverse(t.m_rotation);
	hkVector4 invScale; invScale.setReciprocal3( t.m_scale );
	m_scale.setXYZ0( invScale );
}
void hkQsTransform::setMul( const hkQsTransform& aTb, const hkQsTransform& bTc )
{
	hkVector4 extraTrans;
	extraTrans.setRotatedDir(aTb.m_rotation, bTc.m_translation);
	m_translation.setAdd4(aTb.m_translation, extraTrans);
	m_rotation.setMul(aTb.m_rotation, bTc.m_rotation);
	m_scale.setMul4(aTb.m_scale, bTc.m_scale);
}
void hkQsTransform::setMulInverseMul( const hkQsTransform& a, const hkQsTransform &b )
{
	hkQsTransform h;
	h.setInverse( a );
	setMul(h, b);
}
class hkString
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_STRING); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkString), HK_MEMORY_CLASS_STRING); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_STRING); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	public:
		__forceinline hkString();
		__forceinline hkString(const char* s);
		__forceinline hkString(const char* b, int len);
		__forceinline hkString(const hkString& s);
	private:
		hkString(char* ptr, int size, int capacity);
		__forceinline	void setLength( int length );
	public:
		__forceinline hkString& operator=(const hkString& s);
		__forceinline hkString& operator=(const char* s);
		__forceinline ~hkString();
		__forceinline char operator[] (int i) const;
		__forceinline void setCapacity(int capacity);
		__forceinline int getCapacity() const;
		void printf(const char* format, ...);
		int indexOf (char c, int startIndex=0, int endIndex=2147483647) const;
		int lastIndexOf (char c, int startIndex=0, int endIndex=2147483647) const;
		__forceinline const char* cString() const;
		int compareTo(const hkString& other) const;
		int compareTo(const char* other) const;
		int compareToIgnoreCase(const hkString& other) const;
		int compareToIgnoreCase(const char* other) const;
		__forceinline hkBool operator< (const hkString& s) const;
		__forceinline hkBool operator== (const hkString& s) const;
		__forceinline hkBool operator!= (const hkString& s) const;
		__forceinline hkBool operator== (const char* s) const;
		__forceinline hkBool operator!= (const char* s) const;
		__forceinline hkBool beginsWith(const hkString& s) const;
		hkBool beginsWith(const char* s) const;
		hkBool endsWith(const hkString& s) const;
		hkBool endsWith(const char* s) const;
		hkString operator+ (const hkString& other) const;
		hkString operator+ (const char* other) const;
		hkString& operator+= (const hkString& other);
		hkString& operator+= (const char* other);
		int getLength() const;
		enum ReplaceType
		{
			REPLACE_ONE,
			REPLACE_ALL
		};
		hkString replace(char from, char to, ReplaceType=REPLACE_ALL) const;
		hkBool replaceInplace(char from, char to, ReplaceType=REPLACE_ALL);
		hkString replace(const hkString& from, const hkString& to, ReplaceType=REPLACE_ALL) const;
		hkBool replaceInplace(const hkString& from, const hkString& to, hkString::ReplaceType rtype=REPLACE_ALL);
		hkString asUpperCase() const;
		void makeUpperCase();
		hkString asLowerCase() const;
		void makeLowerCase();
		__forceinline hkString substr(int index, int maxChars=2147483647) const;
		__forceinline void setAsSubstr(int index, int maxChars=2147483647);
	private:
		hkArray<char> m_string;
	public:
		static char __cdecl toUpper( char c );
		static char __cdecl toLower( char c );
		static int __cdecl snprintf(char* buf, int n, const char* fmt, ...);
		static int __cdecl vsnprintf(char* buf, int len, const char* fmt, hk_va_list hkargs);
		static int __cdecl sprintf(char* buf, const char* fmt, ...);
		static int __cdecl strCmp(const char* s1, const char* s2 );
		static int __cdecl strNcmp(const char* s1, const char* s2, int n);
		static int __cdecl strCasecmp(const char* s1, const char* s2 );
		static int __cdecl strNcasecmp(const char* s1, const char* s2, int n);
		static void __cdecl strCpy(char* dst, const char* src);
		static void __cdecl strNcpy(char* dst, const char* src, int n);
		static int __cdecl strLen(const char* src);
		static int __cdecl atoi(const char* in);
		static hkReal __cdecl atof(const char* in);
		static const char* __cdecl strStr(const char* haystack, const char* needle);
		static hkBool findAllOccurrences(const char* haystack, const char* needle, hkArray<int>& indices, hkString::ReplaceType rtype);
		static const char* __cdecl strChr(const char* haystack, int needle);
		static const char* __cdecl strRchr(const char* haystack, int needle);
		static char* __cdecl strDup(const char* src);
		static char* __cdecl strNdup(const char* src, int maxlen);
		static char* __cdecl strLwr(char* src);
		static char* __cdecl strUpr(char* src);
		static void __cdecl memCpy(void* dst, const void* src, int n);
		static __forceinline void __cdecl memCpy4(void* dst, const void* src, int numWords);
		static __forceinline void __cdecl memCpy16(void* dst, const void* src, int numQuads);
		template<int size>
		static __forceinline void __cdecl memCpy16(void* dst, const void* src);
		static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads);
		static __forceinline void __cdecl memCpy128(void* dst, const void* src);
		static __forceinline void __cdecl memCpy256(void* dst, const void* src);
		static void __cdecl memMove(void* dst, const void* src, int n);
		static void __cdecl memSet(void* dst, const int c, int nBytes);
		static __forceinline void __cdecl memSet4(void* dst, const int value, int numWords);
		static __forceinline void __cdecl memClear16(void* dst, int numQuads);
		static __forceinline void __cdecl memSet16(void* dst, const void* value, int numQuads);
		static int __cdecl memCmp(const void* buf1, const void* buf2, int n);
private:
		static void copyAndReplace( char* dest, const char* orig, int origLen, const hkString& from, const hkString& to, const hkArray<int>& indices);
};
__forceinline const char* hkString::cString() const
{
	return m_string.begin();
}
__forceinline void hkString::setLength( int length )
{
	m_string.setSize( length + 1 );
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
__forceinline hkString::~hkString()
{
}
void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
typedef int (__cdecl* hkStringCompareFunc)(const char*, const char*);
class hkaSkeleton;
class hkaSkeletonUtils
{
	public:
		static void __cdecl transformLocalPoseToModelPose ( int numTransforms, const hkInt16* parentIndices, const hkQsTransform* poseLocal, hkQsTransform* poseModelOut);
		static void __cdecl transformModelPoseToLocalPose ( int numTransforms, const hkInt16* parentIndices, const hkQsTransform* poseModel, hkQsTransform* poseLocalOut);
		static void __cdecl transformModelPoseToWorldPose ( int numTransforms, const hkQsTransform& worldFromModel, const hkQsTransform* poseModel, hkQsTransform* poseWorldOut);
		static void __cdecl transformWorldPoseToModelPose ( int numTransforms, const hkQsTransform& worldFromModel, const hkQsTransform* poseWorld, hkQsTransform* poseModelOut);
		static void __cdecl transformLocalPoseToWorldPose ( int numTransforms, const hkInt16* parentIndices, const hkQsTransform& worldFromModel, const hkQsTransform* poseLocal, hkQsTransform* poseWorldOut);
		static void __cdecl transformWorldPoseToLocalPose ( int numTransforms, const hkInt16* parentIndices, const hkQsTransform& worldFromModel, const hkQsTransform* poseWorld, hkQsTransform* poseLocalOut);
		static void __cdecl blendPoses( hkUint32 numBones, const hkQsTransform* poseA, const hkQsTransform* poseB, const hkReal* weights, hkQsTransform* poseOut );
		static void __cdecl blendPoses( hkUint32 numBones, const hkQsTransform* poseA, const hkQsTransform* poseB, const hkReal weight, hkQsTransform* poseOut );
		static void __cdecl blendPartialPoses( hkUint32 numBones, hkInt16* bones, const hkQsTransform* poseA, const hkQsTransform* poseB, const hkReal weight, hkQsTransform* poseOut );
		static void __cdecl enforceSkeletonConstraintsLocalSpace(const hkaSkeleton& skeleton, hkQsTransform* poseLocalInOut);
		static void __cdecl enforceSkeletonConstraintsModelSpace(const hkaSkeleton& skeleton, hkQsTransform* poseModelInOut);
		static void __cdecl enforcePoseConstraintsLocalSpace (const hkaSkeleton& skeleton, const hkQsTransform* constraintsLocal, hkQsTransform* poseInOut);
		static void __cdecl enforcePoseConstraintsModelSpace (const hkaSkeleton& skeleton, const hkQsTransform* constraintsLocal, hkQsTransform* poseModelInOut);
		static hkInt16 __cdecl findBoneWithName (const hkaSkeleton& skeleton, const char* name, hkStringCompareFunc compare = 0);
		static void __cdecl lockTranslations (const hkaSkeleton& skeleton, hkBool exceptRoots = true);
		static void __cdecl unlockTranslations (const hkaSkeleton& skeleton);
		static hkBool __cdecl getBoneChain(const hkaSkeleton& skeleton, hkInt16 startBone, hkInt16 endBone, hkArray<hkInt16>& bonesOut);
		static void __cdecl getDescendants(const hkaSkeleton& skeleton, hkInt16 startBone, hkArray<hkInt16>& bonesOut);
		static void __cdecl getLeaves(const hkaSkeleton& skeleton, hkArray<hkInt16>& leavesOut);
		static hkBool __cdecl isBindingOk( const hkaSkeleton& skeleton, const class hkaAnimationBinding& binding );
		static void __cdecl getModelSpaceScale (const hkaSkeleton& skeleton, const hkQsTransform* poseLocal, int boneId, hkVector4& scaleOut);
		static void __cdecl normalizeRotations(hkQsTransform* transformsInOut, int numTransforms );
		static hkResult __cdecl bindByName(const hkaSkeleton& skeleton, const class hkaSkeletalAnimation& anim, hkStringCompareFunc compare, class hkaAnimationBinding& bindingOut);
};
class hkaSkeletonMapperData
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeletonMapperData), HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		struct SimpleMapping
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIMATION); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeletonMapperData::SimpleMapping), HK_MEMORY_CLASS_ANIMATION); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIMATION); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			SimpleMapping()
			{
				m_boneA = 0;
				m_boneB = 0;
				m_aFromBTransform.setIdentity();
			}
			hkInt16 m_boneA;
			hkInt16 m_boneB;
			hkQsTransform m_aFromBTransform;
		};
		struct ChainMapping
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIMATION); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeletonMapperData::ChainMapping), HK_MEMORY_CLASS_ANIMATION); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIMATION); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			ChainMapping()
			{
				m_startBoneA = 0;
				m_endBoneA = 0;
				m_startBoneB = 0;
				m_endBoneB = 0;
				m_startAFromBTransform.setIdentity();
				m_endAFromBTransform.setIdentity();
			}
			hkInt16 m_startBoneA;
			hkInt16 m_endBoneA;
			hkInt16 m_startBoneB;
			hkInt16 m_endBoneB;
			hkQsTransform m_startAFromBTransform;
			hkQsTransform m_endAFromBTransform;
		};
		hkaSkeletonMapperData()
		{
			m_skeletonA = 0;
			m_skeletonB = 0;
			m_keepUnmappedLocal = true;
		}
		hkaSkeletonMapperData( hkFinishLoadedObjectFlag f ) : m_simpleMappings(f), m_chainMappings(f), m_unmappedBones(f) {}
		const hkaSkeleton* m_skeletonA;
		const hkaSkeleton* m_skeletonB;
		hkArray<struct SimpleMapping> m_simpleMappings;
		hkArray<struct ChainMapping> m_chainMappings;
		hkArray<hkInt16> m_unmappedBones;
		hkBool m_keepUnmappedLocal;
};
class hkaSkeletonMapperUtils
{
	public:
		struct UserChain
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RUNTIME); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeletonMapperUtils::UserChain), HK_MEMORY_CLASS_ANIM_RUNTIME); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RUNTIME); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			const char* m_start;
			const char* m_end;
		};
		struct UserMapping
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RUNTIME); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeletonMapperUtils::UserMapping), HK_MEMORY_CLASS_ANIM_RUNTIME); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RUNTIME); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			const char* m_boneIn;
			const char* m_boneOut;
		};
		struct Params
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RUNTIME); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeletonMapperUtils::Params), HK_MEMORY_CLASS_ANIM_RUNTIME); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RUNTIME); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			const hkaSkeleton* m_skeletonA;
			const hkaSkeleton* m_skeletonB;
			hkStringCompareFunc m_compareNames;
			hkReal m_positionMatchTolerance;
			hkArray<UserChain> m_userChains;
			hkArray<UserMapping> m_userMappingsAtoB;
			hkArray<UserMapping> m_userMappingsBtoA;
			hkBool m_autodetectSimple;
			hkBool m_autodetectChains;
			Params ( const Params& other) :
				m_skeletonA(other.m_skeletonA), m_skeletonB(other.m_skeletonB),
				m_compareNames(other.m_compareNames),
				m_positionMatchTolerance (other.m_positionMatchTolerance),
				m_autodetectSimple (other.m_autodetectSimple), m_autodetectChains (other.m_autodetectChains)
				{
					m_userChains = other.m_userChains;
					m_userMappingsAtoB = other.m_userMappingsAtoB;
					m_userMappingsBtoA = other.m_userMappingsBtoA;
				}
			Params () :
				m_skeletonA(0), m_skeletonB(0), m_compareNames(0),
				m_positionMatchTolerance(0.0f), m_autodetectSimple(true), m_autodetectChains(true)
			{}
		};
		static void __cdecl hkaSkeletonMapperUtils_createMapping (const Params& params, hkaSkeletonMapperData& aToB, hkaSkeletonMapperData& bToA);
		static const struct hkaSkeletonMapperData::SimpleMapping* __cdecl findSimpleMapping(hkInt16 boneA, const hkaSkeletonMapperData& mapperdata );
		static hkResult __cdecl lockTranslationsAutomatically (const hkaSkeletonMapperData& mapperData);
};
class hkaBone
{
	public:
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaBone), HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		char * m_name;
		hkBool m_lockTranslation;
};
class hkaSkeleton
{
	public:
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkaSkeleton), HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ANIM_RIG); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		inline hkaSkeleton();
		const char* m_name;
		hkInt16* m_parentIndices;
		hkInt32 m_numParentIndices;
		hkaBone** m_bones;
		hkInt32 m_numBones;
		hkQsTransform* m_referencePose;
		int		m_numReferencePose;
		char**	m_floatSlots;
		hkInt32 m_numFloatSlots;
	public:
		__forceinline hkaSkeleton( hkFinishLoadedObjectFlag flag ) {}
};
template <typename T>
class hkLocalArray : public hkArray<T>
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkLocalArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkLocalArray( int capacity )
		{
			this->m_data = hkAllocateStack<T>(capacity);
			this->m_capacityAndFlags = capacity | hkArray<T>::DONT_DEALLOCATE_FLAG;
			m_localMemory = this->m_data;
		}
		__forceinline void discardAndResize(int newsize)
		{
			;
			hkDeallocateStack<T>( m_localMemory );
			m_localMemory = this->m_data = hkAllocateStack<T>(newsize);
			this->m_size = newsize;
			this->m_capacityAndFlags = newsize | hkArray<T>::DONT_DEALLOCATE_FLAG;
		}
		void assertNotResized()
		{
			;
		}
		hkBool wasReallocated() const
		{
			return m_localMemory != this->m_data;
		}
		__forceinline ~hkLocalArray()
		{
			hkDeallocateStack<T>( m_localMemory );
		}
		T* m_localMemory;
};
struct Match
{
	int m_indexA;
	int m_indexB;
};
// pdb: hkaSkeletonMapperUtils::createMapping | hkaSkeletonMapperUtils.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void hkaSkeletonMapperUtils::hkaSkeletonMapperUtils_createMapping( const Params& originalParams, hkaSkeletonMapperData& originalAToB, hkaSkeletonMapperData& originalBToA )
{
	hkError::getInstance().sectionBegin(0x54e4323e, "hkaSkeletonMapperUtils::createMapping");
	bool switchedOrder = false;
	Params params( originalParams );
	if ( originalParams.m_skeletonA->m_numBones > originalParams.m_skeletonB->m_numBones )
	{
		params.m_skeletonA = originalParams.m_skeletonB;
		params.m_skeletonB = originalParams.m_skeletonA;
		params.m_userMappingsAtoB = originalParams.m_userMappingsBtoA;
		params.m_userMappingsBtoA = originalParams.m_userMappingsAtoB;
		switchedOrder = true;
	}
	hkaSkeletonMapperData& aToB = switchedOrder ? originalBToA : originalAToB;
	hkaSkeletonMapperData& bToA = switchedOrder ? originalAToB : originalBToA;
	const int numBonesA = params.m_skeletonA->m_numBones;
	const int numBonesB = params.m_skeletonB->m_numBones;
	hkLocalArray<hkQsTransform> modelPoseA( numBonesA );
	modelPoseA.setSizeUnchecked( numBonesA );
	hkaSkeletonUtils::transformLocalPoseToModelPose( numBonesA, params.m_skeletonA->m_parentIndices, params.m_skeletonA->m_referencePose, modelPoseA.begin() );
	hkLocalArray<hkQsTransform> modelPoseB( numBonesB );
	modelPoseB.setSizeUnchecked( numBonesB );
	hkaSkeletonUtils::transformLocalPoseToModelPose( numBonesB, params.m_skeletonB->m_parentIndices, params.m_skeletonB->m_referencePose, modelPoseB.begin() );
	const int UNMATCHED = -1;
	const int INCHAIN = -2;
	hkLocalArray<hkInt16> map_AtoB( numBonesA ); map_AtoB.setSize( numBonesA, UNMATCHED );
	hkLocalArray<hkInt16> map_BtoA( numBonesB ); map_BtoA.setSize( numBonesB, UNMATCHED );
	aToB.m_skeletonA = params.m_skeletonA;
	aToB.m_skeletonB = params.m_skeletonB;
	bToA.m_skeletonA = params.m_skeletonB;
	bToA.m_skeletonB = params.m_skeletonA;
	{
		const int numMappings = params.m_userMappingsAtoB.getSize();
		for ( int i = 0; i < numMappings; i++ )
		{
			const UserMapping& mapping = params.m_userMappingsAtoB[i];
			const hkInt16 boneIn = hkaSkeletonUtils::findBoneWithName( *params.m_skeletonA, mapping.m_boneIn, params.m_compareNames );
			const hkInt16 boneOut = hkaSkeletonUtils::findBoneWithName( *params.m_skeletonB, mapping.m_boneOut, params.m_compareNames );
			if ( ( boneIn != -1 ) && ( boneOut != -1 ) )
			{
				const hkQsTransform& transformIn = modelPoseA[boneIn];
				const hkQsTransform& transformOut = modelPoseB[boneOut];
				hkaSkeletonMapperData::SimpleMapping simpleMapping;
				simpleMapping.m_boneA = boneIn;
				simpleMapping.m_boneB = boneOut;
				simpleMapping.m_aFromBTransform.setMulInverseMul( transformIn, transformOut );
				aToB.m_simpleMappings.pushBack( simpleMapping );
				map_BtoA[boneOut] = boneIn;
			} else {
				if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf, sizeof(assertBuf)); ostr << "Couldn't find bones for mapping (" << mapping.m_boneIn << " - " << mapping.m_boneOut << ")"; hkError::getInstance().message(hkError::MESSAGE_WARNING, 0xabba1c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 109); } else;
			}
		}
	}
	{
		const int numMappings = params.m_userMappingsBtoA.getSize();
		for ( int i = 0; i < numMappings; i++ )
		{
			const UserMapping& mapping = params.m_userMappingsBtoA[i];
			const hkInt16 boneIn = hkaSkeletonUtils::findBoneWithName( *params.m_skeletonB, mapping.m_boneIn, params.m_compareNames );
			const hkInt16 boneOut = hkaSkeletonUtils::findBoneWithName( *params.m_skeletonA, mapping.m_boneOut, params.m_compareNames );
			if ( ( boneIn != -1 ) && ( boneOut != -1 ) )
			{
				const hkQsTransform& transformIn = modelPoseB[boneIn];
				const hkQsTransform& transformOut = modelPoseA[boneOut];
				hkaSkeletonMapperData::SimpleMapping simpleMapping;
				simpleMapping.m_boneA = boneIn;
				simpleMapping.m_boneB = boneOut;
				simpleMapping.m_aFromBTransform.setMulInverseMul( transformIn, transformOut );
				bToA.m_simpleMappings.pushBack( simpleMapping );
				map_AtoB[boneOut] = boneIn;
			} else {
				if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf, sizeof(assertBuf)); ostr << "Couldn't find bones for mapping (" << mapping.m_boneIn << " - " << mapping.m_boneOut << ")"; hkError::getInstance().message(hkError::MESSAGE_WARNING, 0xabba1c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 141); } else;
			}
		}
	}
	{
		const int numChains = params.m_userChains.getSize();
		for ( int i = 0; i < numChains; i++ )
		{
			const UserChain& chain = params.m_userChains[i];
			hkInt16 startChainA = hkaSkeletonUtils::findBoneWithName( *params.m_skeletonA, chain.m_start, params.m_compareNames );
			hkInt16 endChainA = hkaSkeletonUtils::findBoneWithName( *params.m_skeletonA, chain.m_end, params.m_compareNames );
			hkInt16 startChainB = hkaSkeletonUtils::findBoneWithName( *params.m_skeletonB, chain.m_start, params.m_compareNames );
			hkInt16 endChainB = hkaSkeletonUtils::findBoneWithName( *params.m_skeletonB, chain.m_end, params.m_compareNames );
			if ( ( startChainA < 0 ) && ( startChainB < 0 ) )
			{
				if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf, sizeof(assertBuf)); ostr << "Couldn't make a chain (" << chain.m_start << " - " << chain.m_end << "). Start bone not found in either skeleton."; hkError::getInstance().message(hkError::MESSAGE_WARNING, 0x38521c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 165); } else;
				continue;
			}
			if ( ( endChainA < 0 ) && ( endChainB < 0 ) )
			{
				if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf, sizeof(assertBuf)); ostr << "Couldn't make a chain (" << chain.m_start << " - " << chain.m_end << "). End bone not found in either skeleton."; hkError::getInstance().message(hkError::MESSAGE_WARNING, 0x38521c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 171); } else;
				continue;
			}
			if ( startChainA < 0 ) startChainA = map_BtoA[startChainB];
			if ( endChainA < 0 ) endChainA = map_BtoA[endChainB];
			if ( startChainB < 0 ) startChainB = map_AtoB[startChainA];
			if ( endChainB < 0 ) endChainB = map_AtoB[endChainA];
			hkArray<hkInt16> chainA;
			hkArray<hkInt16> chainB;
			hkBool chainAok = hkaSkeletonUtils::getBoneChain( *params.m_skeletonA, startChainA, endChainA, chainA );
			hkBool chainBok = hkaSkeletonUtils::getBoneChain( *params.m_skeletonB, startChainB, endChainB, chainB );
			if ( !chainAok || !chainBok )
			{
				if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf, sizeof(assertBuf)); ostr << "Couldn't make a chain (" << chain.m_start << " - " << chain.m_end << ")"; hkError::getInstance().message(hkError::MESSAGE_WARNING, 0xabba1c63, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 190); } else;
				continue;
			}
			const int chainLengthA = chainA.getSize();
			const int chainLengthB = chainB.getSize();
			if ( ( chainLengthA < 2 ) || ( chainLengthB < 2 ) )
			{
				if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf, sizeof(assertBuf)); ostr << "Couldn't make a chain (" << chain.m_start << " - " << chain.m_end << ")"; hkError::getInstance().message(hkError::MESSAGE_WARNING, 0xabba1c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 200); } else;
				continue;
			}
			for ( int a = 1; a < chainLengthA - 1; a++ )
			{
				if ( map_AtoB[chainA[a]] != UNMATCHED )
				{
					if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf, sizeof(assertBuf)); ostr << "Couldn't make a chain (" << chain.m_start << " - " << chain.m_end << ")"; hkError::getInstance().message(hkError::MESSAGE_WARNING, 0xabba1c65, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 210); } else;
					continue;
				}
			}
			for ( int b = 1; b < chainLengthB - 1; b++ )
			{
				if ( map_BtoA[chainB[b]] != UNMATCHED )
				{
					if(1) { char assertBuf[512]; hkErrStream ostr(assertBuf, sizeof(assertBuf)); ostr << "Couldn't make a chain (" << chain.m_start << " - " << chain.m_end << ")"; hkError::getInstance().message(hkError::MESSAGE_WARNING, 0xabba1c66, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 219); } else;
					continue;
				}
			}
			{
				if(1) { char reportBuf[512]; hkErrStream ostr(reportBuf,sizeof(reportBuf)); ostr << "Creating chain " << params.m_skeletonA->m_bones[startChainA]->m_name << " - " << params.m_skeletonA->m_bones[endChainA]->m_name; hkError::getInstance().message(hkError::MESSAGE_REPORT, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 229); } else;
				const hkQsTransform& transformStartA = modelPoseA[startChainA];
				const hkQsTransform& transformStartB = modelPoseB[startChainB];
				const hkQsTransform& transformEndA = modelPoseA[endChainA];
				const hkQsTransform& transformEndB = modelPoseB[endChainB];
				{
					hkaSkeletonMapperData::ChainMapping chainMappingAtoB;
					chainMappingAtoB.m_startBoneA = startChainA;
					chainMappingAtoB.m_endBoneA = endChainA;
					chainMappingAtoB.m_startBoneB = startChainB;
					chainMappingAtoB.m_endBoneB = endChainB;
					chainMappingAtoB.m_endAFromBTransform.setMulInverseMul( transformEndA, transformEndB );
					chainMappingAtoB.m_startAFromBTransform.setMulInverseMul( transformStartA, transformStartB );
					aToB.m_chainMappings.pushBack( chainMappingAtoB );
				}
				{
					hkaSkeletonMapperData::ChainMapping chainMappingBtoA;
					chainMappingBtoA.m_startBoneA = startChainB;
					chainMappingBtoA.m_endBoneA = endChainB;
					chainMappingBtoA.m_startBoneB = startChainA;
					chainMappingBtoA.m_endBoneB = endChainA;
					chainMappingBtoA.m_endAFromBTransform.setMulInverseMul( transformEndB, transformEndA );
					chainMappingBtoA.m_startAFromBTransform.setMulInverseMul( transformStartB, transformStartA );
					bToA.m_chainMappings.pushBack( chainMappingBtoA );
				}
				for ( int a = 1; a < chainLengthA - 1; a++ )
				{
					map_AtoB[chainA[a]] = INCHAIN;
				}
				for ( int b = 1; b < chainLengthB - 1; b++ )
				{
					map_BtoA[chainB[b]] = INCHAIN;
				}
			}
		}
	}
	if ( params.m_autodetectSimple )
	{
		hkArray<Match> matches;
		hkStringCompareFunc compare = ( params.m_compareNames == 0 ) ? ( ( params.m_positionMatchTolerance > 0.0 ) ? 0 : hkString::strCasecmp ) : params.m_compareNames;
		hkReal tolSqrd = ( params.m_positionMatchTolerance * params.m_positionMatchTolerance );
		for ( int idxA = 0; idxA < numBonesA; idxA++ )
		{
			if ( compare )
			{
				for ( int idxB = 0; idxB < numBonesB; idxB++ )
				{
					const char* nameA = params.m_skeletonA->m_bones[idxA]->m_name;
					const char* nameB = params.m_skeletonB->m_bones[idxB]->m_name;
					if ( compare( nameA, nameB ) == 0 )
					{
						Match& match = matches.expandOne();
						match.m_indexA = idxA;
						match.m_indexB = idxB;
					}
				}
			} else {
				const hkQsTransform& transformA = modelPoseA[idxA];
				hkReal shortest = 100000.0f;
				int shortestIndex = -1;
				for ( int idxB = 0; idxB < numBonesB; idxB++ )
				{
					const hkQsTransform& transformB = modelPoseB[idxB];
					hkVector4 dif; dif.setSub4( transformA.m_translation, transformB.m_translation );
					hkReal ls = dif.lengthSquared3();
					if ( ls < shortest )
					{
						shortest = ls;
						shortestIndex = idxB;
					}
				}
				if ( shortest < tolSqrd )
				{
					Match& match = matches.expandOne();
					match.m_indexA = idxA;
					match.m_indexB = shortestIndex;
				}
			}
		}
		const int numMatches = matches.getSize();
		for ( int i = 0; i < numMatches; i++ )
		{
			const hkInt16 boneA = static_cast<hkInt16>( matches[i].m_indexA );
			const hkInt16 boneB = static_cast<hkInt16>( matches[i].m_indexB );
			if ( ( map_AtoB[boneA] != UNMATCHED ) || ( map_BtoA[boneB] != UNMATCHED ) )
			{
				continue;
			}
			const hkQsTransform& transformA = modelPoseA[boneA];
			const hkQsTransform& transformB = modelPoseB[boneB];
			{
				hkaSkeletonMapperData::SimpleMapping simpleMappingAtoB;
				simpleMappingAtoB.m_boneA = boneA;
				simpleMappingAtoB.m_boneB = boneB;
				simpleMappingAtoB.m_aFromBTransform.setMulInverseMul( transformA, transformB );
				aToB.m_simpleMappings.pushBack( simpleMappingAtoB );
			}
			{
				hkaSkeletonMapperData::SimpleMapping simpleMappingBtoA;
				simpleMappingBtoA.m_boneA = boneB;
				simpleMappingBtoA.m_boneB = boneA;
				simpleMappingBtoA.m_aFromBTransform.setMulInverseMul( transformB, transformA );
				bToA.m_simpleMappings.pushBack( simpleMappingBtoA );
			}
			map_AtoB[boneA] = boneB;
			map_BtoA[boneB] = boneA;
			hkString msg = hkString( "Matching " ) + params.m_skeletonA->m_bones[boneA]->m_name;
			if(1) { char reportBuf[512]; hkErrStream ostr(reportBuf,sizeof(reportBuf)); ostr << msg.cString(); hkError::getInstance().message(hkError::MESSAGE_REPORT, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 382); } else;
		}
	}
	if ( params.m_autodetectChains )
	{
		for ( int boneA = 0; boneA < numBonesA; boneA++ )
		{
			if ( map_AtoB[boneA] < 0 )
			{
				continue;
			}
			const hkInt16 endChainA = static_cast<hkInt16>( boneA );
			const hkInt16 endChainB = map_AtoB[boneA];
			hkInt16 startChainA = params.m_skeletonA->m_parentIndices[boneA];
			while ( ( startChainA != -1 ) && ( map_AtoB[startChainA] == UNMATCHED ) )
			{
				startChainA = params.m_skeletonA->m_parentIndices[startChainA];
			}
			if ( ( startChainA == -1 ) || ( map_AtoB[startChainA] == INCHAIN ) )
			{
				continue;
			}
			const hkInt16 startChainB = map_AtoB[startChainA];
			hkArray<hkInt16> chainA;
			hkArray<hkInt16> chainB;
			hkBool chainAok = hkaSkeletonUtils::getBoneChain( *params.m_skeletonA, startChainA, endChainA, chainA );
			hkBool chainBok = hkaSkeletonUtils::getBoneChain( *params.m_skeletonB, startChainB, endChainB, chainB );
			if ( !chainAok || !chainBok )
			{
				continue;
			}
			const int chainLengthA = chainA.getSize();
			const int chainLengthB = chainB.getSize();
			if ( ( chainLengthA == 2 ) && ( chainLengthB == 2 ) )
			{
				continue;
			}
			{
				bool ok = true;
				for ( int b = 1; b < chainLengthB - 1; b++ )
				{
					if ( map_BtoA[chainB[b]] != UNMATCHED )
					{
						ok = false;
						continue;
					}
				}
				if ( !ok ) continue;
			}
			{
				if(1) { char reportBuf[512]; hkErrStream ostr(reportBuf,sizeof(reportBuf)); ostr << "Creating chain " << params.m_skeletonA->m_bones[startChainA]->m_name << " - " << params.m_skeletonA->m_bones[endChainA]->m_name; hkError::getInstance().message(hkError::MESSAGE_REPORT, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 458); } else;
				const hkQsTransform& transformStartA = modelPoseA[startChainA];
				const hkQsTransform& transformStartB = modelPoseB[startChainB];
				const hkQsTransform& transformEndA = modelPoseA[endChainA];
				const hkQsTransform& transformEndB = modelPoseB[endChainB];
				{
					hkaSkeletonMapperData::ChainMapping chainMappingAtoB;
					chainMappingAtoB.m_startBoneA = startChainA;
					chainMappingAtoB.m_endBoneA = endChainA;
					chainMappingAtoB.m_startBoneB = startChainB;
					chainMappingAtoB.m_endBoneB = endChainB;
					chainMappingAtoB.m_endAFromBTransform.setMulInverseMul( transformEndA, transformEndB );
					chainMappingAtoB.m_startAFromBTransform.setMulInverseMul( transformStartA, transformStartB );
					aToB.m_chainMappings.pushBack( chainMappingAtoB );
				}
				{
					hkaSkeletonMapperData::ChainMapping chainMappingBtoA;
					chainMappingBtoA.m_startBoneA = startChainB;
					chainMappingBtoA.m_endBoneA = endChainB;
					chainMappingBtoA.m_startBoneB = startChainA;
					chainMappingBtoA.m_endBoneB = endChainA;
					chainMappingBtoA.m_endAFromBTransform.setMulInverseMul( transformEndB, transformEndA );
					chainMappingBtoA.m_startAFromBTransform.setMulInverseMul( transformStartB, transformStartA );
					bToA.m_chainMappings.pushBack( chainMappingBtoA );
				}
				for ( int a = 1; a < chainLengthA - 1; a++ )
				{
					map_AtoB[chainA[a]] = INCHAIN;
				}
				for ( int b = 1; b < chainLengthB - 1; b++ )
				{
					map_BtoA[chainB[b]] = INCHAIN;
				}
			}
		}
	}
	for ( int b = 0; b < numBonesB; b++ )
	{
		if ( map_BtoA[b] == UNMATCHED )
		{
			aToB.m_unmappedBones.pushBack( static_cast<hkInt16>( b ) );
		}
	}
	for ( int a = 0; a < numBonesA; a++ )
	{
		if ( map_AtoB[a] == UNMATCHED )
		{
			bToA.m_unmappedBones.pushBack( static_cast<hkInt16>( a ) );
		}
	}
	aToB.m_keepUnmappedLocal = true;
	bToA.m_keepUnmappedLocal = true;
	hkError::getInstance().sectionEnd();
}

}  // namespace f3m_00964cd0

// @f3 0x0096d120 (community match, verified in this file)
namespace f3m_0096d120 {
// 0x0096d120: hkCollideCapsuleUtilManifoldCapsVsCaps(const hkVector4* capsA, hkReal capsARadius, const hkVector4* capsB,
// hkReal capsBRadius, hkContactPoint* pointsOut) of Havok 5.5.0 (hkpInternal, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The contact manifold of two capsules: the closest points of the two axis segments (parameters t and u clamped, the
// clamp state kept in returnValue), the first contact point and its normal; when the segments are close to
// parallel, up to two more points from the segments' end points projected onto the other segment.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The function body follows the SDK's unoptimized
// (hybrid) library object statement by statement (that object is matched exactly) and its labels end and
// nextPoint are the SDK object's own. It reproduces the SDK's release object (3330 bytes) under Havok's own flags. The
// parentheses of the three solver products (t = S1 * D2 - ( S2 * R ), u = ( t * R ) - S2, t = ( u * R ) + S1) matter:
// each keeps a node the optimizer hashes, which numbers every later common subexpression one higher, and with all three
// the x87 operand order of the inlined hkVector4 scalings is the original's. Only the function carries the packet's name.
namespace f3m_0096d120 {

typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
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
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
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
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
extern "C" {
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
template <typename T>
	inline T __cdecl max2( T x, T y)
	{
		return x > y ? x : y;
	}
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkVector4& getPosition() const;
		inline hkVector4& getPosition();
		inline void setPosition(const hkVector4& position);
		inline const hkVector4& getNormal() const;
		inline const hkVector4& getSeparatingNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setSeparatingNormal( const hkVector4& normal, hkReal dist );
		inline void setSeparatingNormal( const hkVector4& separatingNormal );
		inline void setNormal( const hkVector4& normal );
		inline hkReal getDistance() const;
		inline hkSimdReal getDistanceSimdReal() const;
		inline void setDistance( hkReal d );
		inline void set( const hkVector4& position, const hkVector4& normal, float dist );
		inline void setFlipped( const hkContactPoint& point );
		inline void flip();
	protected:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkContactPoint), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline hkVector4& hkContactPoint::getPosition()
{
	return m_position;
}
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
	return m_separatingNormal;
}
inline hkReal hkContactPoint::getDistance() const
{
	return m_separatingNormal(3);
}
inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}
namespace hkVector4Util
{
__forceinline void __cdecl calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut);
}
inline void __cdecl hkVector4Util::calculatePerpendicularVector(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
	int min = 0;
	int ok1 = 1;
	int ok2 = 2;
	hkReal a0 = hkMath::fabs(vectorIn(0));
	hkReal a1 = hkMath::fabs(vectorIn(1));
	hkReal a2 = hkMath::fabs(vectorIn(2));
	if( a1 < a0 )
	{
		ok1 = 0;
		min = 1;
		a0 = a1;
	}
	if(a2 < a0)
	{
		ok2 = min;
		min = 2;
	}
	biVectorOut.setZero4();
	biVectorOut(ok1) =  vectorIn(ok2);
	biVectorOut(ok2) = -vectorIn(ok1);
}
void __cdecl FUN_0096d120( const  hkVector4* capsA, hkReal capsARadius, const hkVector4* capsB, hkReal capsBRadius,	hkContactPoint* pointsOut );
void __cdecl FUN_0096d120( const hkVector4* capsAPointsIn, hkReal capsARadius, const hkVector4* capsBPoints, hkReal capsBRadius, hkContactPoint* points )
{
	hkVector4 dA; dA.setSub4( capsAPointsIn[1], capsAPointsIn[0] );
	hkVector4 dB; dB.setSub4( capsBPoints[1], capsBPoints[0] );
	hkVector4 capsAPoints[2];
	hkReal R = dA.dot3( dB );
	if ( R < 0.0f )
	{
		R = -R;
		dA.setNeg4( dA );
		capsAPoints[0] = capsAPointsIn[1];
		capsAPoints[1] = capsAPointsIn[0];
	}
	else
	{	capsAPoints[0] = capsAPointsIn[0];
		capsAPoints[1] = capsAPointsIn[1];
	}
	const hkVector4& A = capsAPoints[0];
	const hkVector4& B = capsBPoints[0];
	hkReal S1, S2, D1, D2, denom;
	hkReal t, u;
	int returnValue;
	{
		hkVector4 d12; d12.setSub4( B, A );
		S1 = dA.dot3( d12 );
		S2 = dB.dot3( d12 );
		D1 = dA.dot3( dA );
		D2 = dB.dot3( dB );
		denom = hkMath::fabs( D1 * D2 - R * R );
		hkReal eps = ( R * R + hkMath::fabs( D1 * D2 ) ) * 9.5367431640625e-07f;
		t = S1 * D2 - ( S2 * R );
		if ( t * denom >= denom * denom )
		{
			t = 1.0f;
			returnValue = 1;
		}
		else if ( t <= 0.0f )
		{
			t = 0.0f;
			returnValue = 2;
		}
		else
		{	if ( denom > eps )
			{
				t /= denom;
				returnValue = 0;
			}
			else
			{	t = 1.0f;
				returnValue = 1;
			}
		}
		u = ( t * R ) - S2;
		if ( u >= D2 )
		{
			u = 1.0f;
			returnValue = 4;
		}
		else if ( u <= 0.0f )
		{
			u = 0.0f;
			returnValue = 8;
		}
		else
		{	u /= D2;
			goto end;
		}
		t = ( u * R ) + S1;
		if ( t <= 0.0f )
		{
			t = 0.0f;
			returnValue |= 2; goto end;
		}
		if ( t >= D1 )
		{
			t = 1.0f;
			returnValue |= 1;
			goto end;
		}
		t /= D1;
	}
end:
	{
		hkVector4 a; a.setAddMul4( A, dA, t );
		hkVector4 b; b.setAddMul4( B, dB, u );
		hkVector4 aMinusB; aMinusB.setSub4( a, b );
		hkContactPoint& cpoint = points[0];
		const hkReal radiusSum = capsARadius + capsBRadius;
		const hkReal refDist = hkMath::max2( 1.192092896e-07F, radiusSum + cpoint.getDistance() );
		hkReal distSquared = aMinusB.lengthSquared3();
		if ( distSquared < refDist * refDist )
		{
			cpoint.getSeparatingNormal() = aMinusB;
			hkReal dist;
			if ( distSquared < 1.192092896e-07F )
			{
				dist = 0.0f;
				hkVector4Util::calculatePerpendicularVector( dA, cpoint.getSeparatingNormal() );
				cpoint.getSeparatingNormal().normalize3();
			}
			else
			{	hkReal distInv = hkMath::sqrtInverse( distSquared );
				dist = distInv * distSquared;
				cpoint.getSeparatingNormal().mul4( distInv );
			}
			cpoint.getPosition().setAddMul4( a, cpoint.getSeparatingNormal(), capsBRadius - dist );
			cpoint.setDistance( dist - radiusSum );
		}
		else
		{
			hkReal distInv = hkMath::sqrtInverse( distSquared );
			cpoint.getSeparatingNormal() = aMinusB;
			hkReal dist = distInv * distSquared;
			cpoint.getSeparatingNormal().mul4( distInv );
			cpoint.setDistance( dist - radiusSum );
			return;
		}
	}
	{
		hkReal maxSinAngle = 0.2f;
		if ( denom > maxSinAngle * D1 * D2 )
		{
			return;
		}
	}
	const hkReal invD12 = 1.0f / ( D1 * D2 );
	const hkReal invD1 = D2 * invD12;
	const hkReal invD2 = D1 * invD12;
	{
		hkContactPoint* point = points + 1;
		hkVector4 closestA = capsAPoints[0];
		hkVector4 closestB = capsBPoints[0];
		hkReal pAonB = -S2;
		hkReal pBonA = S1;
		int i = 0;
		int mask = 10;
		while ( 1 )
		{
			if ( ( returnValue & mask ) == 0 )
			{
				if ( pAonB > 0.0f )
				{
					if ( pAonB > D2 )
					{
						goto nextPoint;
					}
					if ( pBonA > 0.0f )
					{
						if ( pBonA > D1 )
						{
							goto nextPoint;
						}
						if ( pAonB * pAonB * invD2 > pBonA * pBonA * invD1 )
						{
							closestA.addMul4( pBonA * invD1, dA );
						}
						else
						{	closestB.addMul4( pAonB * invD2, dB );
						}
					}
					else
					{	closestB.addMul4( pAonB * invD2, dB );
					}
				}
				else
				{	if ( pBonA > 0.0f )
					{
						if ( pBonA > D1 )
						{
							goto nextPoint;
						}
						closestA.addMul4( pBonA * invD1, dA );
					}
				}
				hkVector4 aMinusB; aMinusB.setSub4( closestA, closestB );
				hkContactPoint& cpoint = *point;
				const hkReal radiusSum = capsARadius + capsBRadius;
				const hkReal refDist = cpoint.getDistance() + radiusSum;
				hkReal distSquared = aMinusB.lengthSquared3();
				if ( distSquared < refDist * refDist )
				{
					hkReal dist = hkMath::sqrt( distSquared );
					cpoint.getSeparatingNormal() = aMinusB;
					if ( distSquared > 1.192092896e-07F )
					{
						cpoint.getSeparatingNormal().normalize3();
					}
					else
					{	cpoint.getSeparatingNormal() = points->getSeparatingNormal();
					}
					cpoint.getPosition().setAddMul4( closestA, cpoint.getSeparatingNormal(), capsBRadius - dist );
					cpoint.setDistance( dist - radiusSum );
				}
			}
nextPoint:
			if ( i == 1 )
			{
				break;
			}
			closestA = capsAPoints[1];
			closestB = capsBPoints[1];
			pAonB = D2 - pAonB - R;
			pBonA = D1 - pBonA - R;
			dA.setNeg4( dA );
			dB.setNeg4( dB );
			point++;
			i++;
			mask = 5;
		}
	}
}

}  // namespace f3m_0096d120
}   // namespace f3m_0096d120

// @f3 0x0096e450 (community match, verified in this file)
// 0x0096e450: hkCollideCapsuleUtilCapsVsTri(const hkVector4* capsAPoints, hkReal capsARadius, const hkVector4*
// triVertices, hkReal triBRadius, const hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkReal
// collisionTolerance, int searchManifold, hkContactPoint* points) of Havok 5.5.0 (hkpInternal,
// hkpCollideCapsuleUtil.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-). Collides a capsule with a triangle: builds
// the triangle's plane directions (the file-local hkCollideCapsuleUtil_calcTrianglePlaneDirections, inlined),
// transforms both capsule ends into them, leaves early when the capsule is outside, then either takes the face
// contacts of the end points (or of the segment crossing the plane), or walks the triangle's edges with
// closestLineSegLineSeg (with searchManifold set, through hkCollideCapsuleUtilManifoldCapsVsCaps per edge).
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte); those declarations are the SDK's
// text with its names. The function and its file-local helper follow the SDK's unoptimized (hybrid) library object,
// which this source reproduces with all 58 named locals; the game's build differs from the SDK's release object in
// one place only: its plane helper writes the transform directly, where the SDK's goes through a reference local
// from the transposes on (13 bytes of x87 slot and register order in the transform loop). Only the function
// carries the packet's name.
namespace f3m_0096e450 {

typedef signed char		hkInt8;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
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
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
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
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		void setAnd( hkVector4Comparison a, hkVector4Comparison b ) { m_mask = a.m_mask & b.m_mask; }
		void set( Mask m ) { m_mask = m; }
		hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
		hkBool32 allAreSet() const { return m_mask == MASK_XYZW; }
		hkBool32 anyIsSet() const { return m_mask; }
		int getMask() const { return m_mask; }
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};
extern "C" {
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
}
extern const hkQuadReal hkQuadReal0000;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}
inline hkVector4Comparison hkVector4::compareLessThan4(const hkVector4& a) const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<a.x) ? hkVector4Comparison::MASK_X : 0) |
		((y<a.y) ? hkVector4Comparison::MASK_Y : 0) |
		((z<a.z) ? hkVector4Comparison::MASK_Z : 0) |
		((w<a.w) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}
inline hkVector4Comparison hkVector4::compareLessThanZero4() const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<0) ? hkVector4Comparison::MASK_X : 0) |
		((y<0) ? hkVector4Comparison::MASK_Y : 0) |
		((z<0) ? hkVector4Comparison::MASK_Z : 0) |
		((w<0) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}
inline hkBool32 hkVector4::allLessThan3(hkVector4Parameter a) const
{
	return x<a.x && y<a.y && z<a.z;
}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline void hkVector4::_setMul4xyz1( const hkTransform& t, const hkVector4& v )
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& d = *this;
		d(0) = t(0,0)*v0 + t(0,1)*v1 + t(0,2)*v2 + t(0,3);
		d(1) = t(1,0)*v0 + t(1,1)*v1 + t(1,2)*v2 + t(1,3);
		d(2) = t(2,0)*v0 + t(2,1)*v1 + t(2,2)*v2 + t(2,3);
		d(3) = t(3,0)*v0 + t(3,1)*v1 + t(3,2)*v2 + t(3,3);
	}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
inline const hkVector4& __cdecl hkVector4::getZero()
{
	const hkVector4& zero = *reinterpret_cast<const hkVector4*>(&hkQuadReal0000);
	return zero;
}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
inline void hkMatrix3::getRow( int row, hkVector4& r) const
{
	r.set( getColumn(0)(row), getColumn(1)(row), getColumn(2)(row) );
}
hkVector4& hkTransform::getColumn(int x)
{
	return m_rotation.getColumn(x);
}
hkRotation& hkTransform::getRotation()
{
	return m_rotation;
}
hkTransform::hkTransform(const hkTransform& t)
{
	const hkVector4 r0 = t.m_rotation.getColumn(0);
	const hkVector4 r1 = t.m_rotation.getColumn(1);
	const hkVector4 r2 = t.m_rotation.getColumn(2);
	const hkVector4 r3 = t.m_rotation.getColumn(3);
	m_rotation.getColumn(0) = r0;
	m_rotation.getColumn(1) = r1;
	m_rotation.getColumn(2) = r2;
	m_rotation.getColumn(3) = r3;
}
inline hkReal& hkTransform::operator() (int r, int c)
{
	return m_rotation(r,c);
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkVector4& getPosition() const;
		inline hkVector4& getPosition();
		inline void setPosition(const hkVector4& position);
		inline const hkVector4& getNormal() const;
		inline const hkVector4& getSeparatingNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setSeparatingNormal( const hkVector4& normal, hkReal dist );
		inline void setSeparatingNormal( const hkVector4& separatingNormal );
		inline void setNormal( const hkVector4& normal );
		inline hkReal getDistance() const;
		inline hkSimdReal getDistanceSimdReal() const;
		inline void setDistance( hkReal d );
		inline void set( const hkVector4& position, const hkVector4& normal, float dist );
		inline void setFlipped( const hkContactPoint& point );
		inline void flip();
	protected:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkContactPoint), HK_MEMORY_CLASS_COLLIDE); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_COLLIDE); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline const hkVector4& hkContactPoint::getNormal() const
{
	return m_separatingNormal;
}
inline hkVector4& hkContactPoint::getPosition()
{
	return m_position;
}
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
	return m_separatingNormal;
}
inline hkReal hkContactPoint::getDistance() const
{
	return m_separatingNormal(3);
}
inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}
namespace hkAlgorithm
{
template<typename T>
	__forceinline void __cdecl swap(T& x, T& y)
	{
		T t(x);
		x = y;
		y = t;
	}
}
namespace hkVector4Util
{
__forceinline void __cdecl mul4xyz1Points( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
__forceinline void __cdecl checkRegisters( hkUint32 registerMask );
}
__forceinline void __cdecl hkVector4Util::checkRegisters( hkUint32 registerMask )
{
}
inline void __cdecl hkVector4Util::mul4xyz1Points( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	;
	checkRegisters( 0xf0000000 );
	hkTransform unaliased = t;
	int i = numVectors - 1;
	do
	{
		vectorsOut[i]._setMul4xyz1( unaliased, vectorsIn[i] );
	} while( --i >= 0 );
}
class hkpCollideTriangleUtil
{
	public:
		static void __cdecl calcBarycentricCoordinates(hkVector4Parameter pos, hkVector4Parameter t0, hkVector4Parameter t1, hkVector4Parameter t2, hkPadSpu<hkReal> result[3]);
		enum
		{
			CLSLS_POINTA_START = 1,
			CLSLS_POINTA_END   = 2,
			CLSLS_POINTB_START = 4,
			CLSLS_POINTB_END   = 8
		};
		struct ClosestLineSegLineSegResult
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpCollideTriangleUtil::ClosestLineSegLineSegResult), HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkVector4 m_closestPointA;
			hkVector4 m_closestAminusClosestB;
			hkPadSpu<hkReal>  m_distanceSquared;
		};
		static int __cdecl closestLineSegLineSeg( hkVector4Parameter A, hkVector4Parameter dA, hkVector4Parameter B, hkVector4Parameter dB, ClosestLineSegLineSegResult& result );
		struct ClosestPointLineSegResult
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpCollideTriangleUtil::ClosestPointLineSegResult), HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkVector4 m_pointOnEdge;
		};
		static int __cdecl closestPointLineSeg( hkVector4Parameter A, hkVector4Parameter B0, hkVector4Parameter B1, ClosestPointLineSegResult& result );
		struct ClosestPointTriangleCache
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpCollideTriangleUtil::ClosestPointTriangleCache), HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkReal m_QQ;
			hkReal m_RR;
			hkReal m_QR;
			hkReal m_invTriNormal;
		};
		struct ClosestPointTriangleResult
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpCollideTriangleUtil::ClosestPointTriangleResult), HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkVector4			hitDirection;
			hkPadSpu<hkReal>	distance;
			void calcClosestPoint( hkVector4Parameter point, hkVector4& closestPoint )
			{
				closestPoint.setAddMul4( point, hitDirection, distance.val() );
			}
		};
		static void __cdecl setupClosestPointTriangleCache( const hkVector4* triangle, ClosestPointTriangleCache& cache );
		enum ClosestPointTriangleStatus
		{
			HIT_TRIANGLE_FACE = 0,
			HIT_TRIANGLE_EDGE
		};
		static ClosestPointTriangleStatus __cdecl closestPointTriangle( hkVector4Parameter position, const hkVector4* tri, const ClosestPointTriangleCache& cache, ClosestPointTriangleResult& result );
		struct PointTriangleDistanceCache
		{
			__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpCollideTriangleUtil::PointTriangleDistanceCache), HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
			hkReal m_invEdgeLen[3];
			hkReal m_invNormalLen;
			hkReal m_normalLen;
		};
		static void __cdecl setupPointTriangleDistanceCache( const hkVector4* triangle, PointTriangleDistanceCache& cache );
		static void __cdecl calcTrianglePlaneDirections( const hkVector4* tri, const PointTriangleDistanceCache& cache, hkTransform& planeEquationsOut, hkVector4& normalOut );
		static const hkInt8 maskToIndex[];
		static const hkInt8 vertexToEdgeLut[];
		static inline int __cdecl getNextModulo3( int i ) { return vertexToEdgeLut[i+2]; }
		static inline int __cdecl getPrevModulo3( int i ) { return vertexToEdgeLut[i]; }
	protected:
		hkpCollideTriangleUtil();
};
extern "C"
{
void __cdecl hkCollideCapsuleUtilManifoldCapsVsCaps( const  hkVector4* capsA, hkReal capsARadius, const hkVector4* capsB, hkReal capsBRadius,	hkContactPoint* pointsOut );
}
static __forceinline void hkCollideCapsuleUtil_calcTrianglePlaneDirections( const hkVector4* tri, const hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkTransform& planeEquationsOut, hkVector4& normalOut )
{
	hkVector4 E0; E0.setSub4( tri[2], tri[1] );
	hkVector4 E1; E1.setSub4( tri[0], tri[2] );
	hkVector4 E2; E2.setSub4( tri[1], tri[0] );
	hkVector4 n; n.setCross( E0, E1 );
	n.mul4( cache.m_invNormalLen );
	normalOut = n;
	E0.mul4( cache.m_invEdgeLen[0] );
	E1.mul4( cache.m_invEdgeLen[1] );
	E2.mul4( cache.m_invEdgeLen[2] );
	planeEquationsOut.getColumn(0).setCross( E0, n );
	planeEquationsOut.getColumn(1).setCross( E1, n );
	planeEquationsOut.getColumn(2).setCross( E2, n );
	hkAlgorithm::swap( planeEquationsOut(0,1), planeEquationsOut(1,0) );
	hkAlgorithm::swap( planeEquationsOut(0,2), planeEquationsOut(2,0) );
	hkAlgorithm::swap( planeEquationsOut(1,2), planeEquationsOut(2,1) );
	planeEquationsOut(3,0) = normalOut(0);
	planeEquationsOut(3,1) = normalOut(1);
	planeEquationsOut(3,2) = normalOut(2);
	planeEquationsOut.getColumn(3).setZero4();
	planeEquationsOut(0,3) = -cache.m_invEdgeLen[0] * cache.m_normalLen;
}
void __cdecl FUN_0096e450( const  hkVector4* capsAPoints, hkReal capsARadius, const hkVector4* triVertices, hkReal triBRadius,
								  const hkpCollideTriangleUtil::PointTriangleDistanceCache& cache, hkReal collisionTolerance, int searchManifold, hkContactPoint* points )
{
	hkTransform planeDirections;
	hkVector4 normal;
	hkCollideCapsuleUtil_calcTrianglePlaneDirections( triVertices, cache, planeDirections, normal );
	hkVector4 distances[2];
	distances[0].setSub4( capsAPoints[0], triVertices[0] );
	distances[1].setSub4( capsAPoints[1], triVertices[0] );
	hkVector4Util::mul4xyz1Points( planeDirections, &distances[0], 2, &distances[0] );
	const hkReal radiusSum = capsARadius + triBRadius;
	const hkReal checkRadius = radiusSum + collisionTolerance;
	{
		hkReal d = 3.40282e+38f;
		points[0].setDistance( d );
		points[1].setDistance( d );
		points[2].setDistance( d );
	}
	{
		hkVector4 checkRadius4; checkRadius4.setAll( checkRadius );
		hkVector4Comparison emask0 = checkRadius4.compareLessThan4( distances[0] );
		hkVector4Comparison emask1 = checkRadius4.compareLessThan4( distances[1] );
		hkVector4Comparison both; both.setAnd( emask0, emask1 );
		if ( both.anyIsSet() || ( distances[0](3) < -checkRadius && distances[1](3) < -checkRadius ) )
		{
			return;
		}
	}
	hkPadSpu<int> mask[2];
	mask[0] = distances[0].compareLessThanZero4().getMask();
	mask[1] = distances[1].compareLessThanZero4().getMask();
	if ( ( mask[0] ^ mask[1] ) & hkVector4Comparison::MASK_W )
	{
		hkReal f = distances[0](3) / ( distances[0](3) - distances[1](3) );
		hkVector4 collidingDist; collidingDist.setInterpolate4( distances[0], distances[1], f );
		if ( collidingDist.allLessThan3( hkVector4::getZero() ) )
		{
			hkVector4 dir;
			hkContactPoint* point = &points[1];
			point->setDistance( -3.40282e+38f );
			for ( int i = 0; i < 2; i++ )
			{
				if ( ( mask[i] & hkVector4Comparison::MASK_XYZ ) == hkVector4Comparison::MASK_XYZ )
				{
					hkReal dist = -hkMath::fabs( distances[i](3) ) - radiusSum;
					if ( dist > point->getDistance() )
					{
						if ( mask[i] & hkVector4Comparison::MASK_W )
						{
							point->getSeparatingNormal() = normal;
							point->getPosition().setAddMul4( capsAPoints[i], normal, triBRadius - distances[i](3) );
						}
						else
						{
							point->getSeparatingNormal().setNeg4( normal );
							point->getPosition().setAddMul4( capsAPoints[i], normal, -triBRadius - distances[i](3) );
						}
						point->setDistance( dist );
					}
				}
			}
			dir.setSub4( distances[1], distances[0] );
			for ( int e = 0; e < 3; e++ )
			{
				hkReal dirW = dir(3);
				hkReal dirE = dir(e);
				hkReal lenSquared = dirW * dirW + dirE * dirE;
				hkReal invLenSquared = 1.0f / lenSquared;
				hkReal dist = dirE * distances[0](3) - dirW * distances[0](e);
				hkReal distSquared = dist * dist * invLenSquared;
				hkReal contactDist = point->getDistance() + radiusSum;
				if ( distSquared < contactDist * contactDist )
				{
					hkReal project = dirE * distances[0](e) + dirW * distances[0](3);
					project *= -invLenSquared;
					if ( project > -0.0001f && project < 1.0001f )
					{
						hkVector4 triDir; planeDirections.getRotation().getRow( e, triDir );
						if ( dirW < 0.0f )
						{
							dirW = -dirW;
							dirE = -dirE;
						}
						triDir.mul4( dirW );
						point->getSeparatingNormal().setAddMul4( triDir, normal, -dirE );
						point->getSeparatingNormal().normalize3();
						hkVector4 pos; pos.setInterpolate4( capsAPoints[0], capsAPoints[1], project );
						hkReal d = -hkMath::sqrt( distSquared );
						point->getPosition().setAddMul4( pos, point->getNormal(), triBRadius - d );
						point->setDistance( d - radiusSum );
					}
				}
			}
			return;
		}
	}
	int i = 0;
	hkVector4 diffcapsAPoints; diffcapsAPoints.setSub4( capsAPoints[1], capsAPoints[0] );
	hkContactPoint* point = points;
	bool checkSingle = false;
	if ( ( ( mask[0] | mask[1] ) & hkVector4Comparison::MASK_XYZ ) != hkVector4Comparison::MASK_XYZ )
	{
		if ( searchManifold )
		{
			int orMask = mask[0] | mask[1];
			hkReal d = collisionTolerance;
			points[0].setDistance( d );
			points[1].setDistance( d );
			points[2].setDistance( d );
			hkContactPoint prevCp; prevCp.getSeparatingNormal()(3) = 3.40282e+38f;
			hkVector4 pB[2];
			int maskJ = hkVector4Comparison::MASK_X;
			for ( int j = 0; j < 3; maskJ = ( hkVector4Comparison::MASK_X == 1 ) ? maskJ << 1 : maskJ >> 1, j++ )
			{
				if ( maskJ & orMask )
				{
					continue;
				}
				pB[0] = triVertices[ hkpCollideTriangleUtil::getNextModulo3( j ) ];
				pB[1] = triVertices[ hkpCollideTriangleUtil::getPrevModulo3( j ) ];
				hkCollideCapsuleUtilManifoldCapsVsCaps( capsAPoints, capsARadius, pB, triBRadius, points );
				if ( points[0].getSeparatingNormal()(3) > prevCp.getSeparatingNormal()(3) )
				{
					points[0] = prevCp;
				}
				else
				{
					prevCp = points[0];
				}
			}
			return;
		}
		else
		{
			checkSingle = true;
			goto edges;
		}
	}
	for ( ; i < 2; point++, i++ )
	{
		if ( ( mask[i] & hkVector4Comparison::MASK_XYZ ) == hkVector4Comparison::MASK_XYZ )
		{
			if ( mask[i] & hkVector4Comparison::MASK_W )
			{
				point->getPosition().setAddMul4( capsAPoints[i], normal, -triBRadius - distances[i](3) );
				point->getSeparatingNormal().setNeg4( normal );
				point->setDistance( -distances[i](3) - radiusSum );
			}
			else
			{
				point->getPosition().setAddMul4( capsAPoints[i], normal, triBRadius - distances[i](3) );
				point->getSeparatingNormal() = normal;
				point->setDistance( distances[i](3) - radiusSum );
			}
		}
		else
		{
edges:
			int m = hkVector4Comparison::MASK_X;
			for ( int e = 0; e < 3; m = ( hkVector4Comparison::MASK_X == 1 ) ? m << 1 : m >> 1, e++ )
			{
				if ( !checkSingle )
				{
					if ( mask[i] & m )
					{
						continue;
					}
				}
				else
				{
					if ( mask[0] & mask[1] & m )
					{
						continue;
					}
				}
				const int n = hkpCollideTriangleUtil::getNextModulo3( e );
				const int nn = hkpCollideTriangleUtil::getPrevModulo3( e );
				const hkVector4& P = triVertices[n];
				hkVector4 edge; edge.setSub4( triVertices[nn], P );
				hkpCollideTriangleUtil::ClosestLineSegLineSegResult result;
				int whichPoints = hkpCollideTriangleUtil::closestLineSegLineSeg( capsAPoints[0], diffcapsAPoints, P, edge, result );
				const hkReal refDist = point->getDistance() + radiusSum;
				if ( result.m_distanceSquared < refDist * refDist )
				{
					hkVector4 normalE;
					hkReal dist;
					if ( whichPoints & ( 1 << i ) )
					{
						if ( checkSingle )
						{
							i = 1;
						}
						else
						{
							continue;
						}
					}
					if ( whichPoints == 0 )
					{
						normalE.setCross( diffcapsAPoints, edge );
					}
					else
					{
						if ( result.m_distanceSquared <= 1.192092896e-07F * 1.192092896e-07F )
						{
							planeDirections.getRotation().getRow( e, result.m_closestAminusClosestB );
							normalE.setCross( diffcapsAPoints, edge );
							if ( normalE.lengthSquared3() <= 1.192092896e-07F * 1.192092896e-07F )
							{
								normalE = result.m_closestAminusClosestB;
							}
						}
						else
						{
							normalE = result.m_closestAminusClosestB;
						}
					}
					normalE.normalize3();
					dist = normalE.dot3( result.m_closestAminusClosestB );
					if ( dist < 0.0f )
					{
						dist = -dist;
						normalE.setNeg4( normalE );
					}
					point->getPosition().setAddMul4( result.m_closestPointA, normalE, triBRadius - dist );
					point->getSeparatingNormal() = normalE;
					point->setDistance( dist - radiusSum );
					continue;
				}
			}
		}
		if ( checkSingle )
		{
			break;
		}
	}
}

}  // namespace f3m_0096e450

// @f3 0x00973c80 (community match, verified in this file)
// 0x00973c80: hkpInertiaTensorComputer::computeTriangleSurfaceMassProperties(const hkVector4& v0, const hkVector4& v1,
// const hkVector4& v2, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result) of Havok 5.5.0 (hkpUtilities,
// compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Mass properties of a triangle: a thin triangle (thickness under 1e-5) as a surface (inertia from the vertices and
// the centroid, shifted to the centroid), a degenerate one as a point mass at the centroid, otherwise a prism of
// the given thickness along the normal (six vertices, eight triangles) through computeGeometryVolumeMassProperties.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The body follows the SDK's unoptimized (hybrid)
// library object statement by statement and reproduces the release object. It also defines the same source file's
// hkpInertiaTensorComputer::shiftInertiaToCom (game 0x00971660), written from that function's own hybrid and release
// objects (both match): the library's compiler compiled it before this function, and without its body the frame of
// this function is packed differently. Only the function carries the packet's name.
namespace f3m_00973c80 {

typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;
class hkBool;
// TlsGetValue, under the name the checker's symbol table gives its import slot (0x00d9b080)
__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long dwTlsIndex) throw();
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
				__forceinline T getData() const
				{
					return (T)(hkUlong)FUN_00d9b080(m_slotID) ;
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
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
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
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
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
class hkFinishLoadedObjectFlag;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkArray<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
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
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(mytype), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkInplaceArray(int size = 0);
		__forceinline hkInplaceArray(const hkInplaceArray<T,N>& a);
		__forceinline ~hkInplaceArray(){}
		hkArray<T>& operator= (const hkArray<T>& a);
		hkArray<T>& operator= (const hkInplaceArray<T,N>& a);
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		inline hkBool wasReallocated() const;
		inline int stillInplaceUsingMask() const;
	public:
		T m_storage[N];
	public:
		hkInplaceArray(hkFinishLoadedObjectFlag f) : hkArray<T>(f) { }
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline void __cdecl hkArray<T>::copy(T* dst, const T* src, int n)
{
	for(int i = 0; i < n; ++i)
	{
		dst[i] = src[i];
	}
}
template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
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
__forceinline hkArray<T>& hkArray<T>::operator= (const hkArray<T>& a)
{
	if(getCapacity() < a.m_size)
	{
		releaseMemory();
		m_data = static_cast<T*>( hkThreadMemory::getInstance().allocateChunk( a.m_size * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY));
		m_capacityAndFlags = a.m_size | (m_capacityAndFlags & static_cast<int>(LOCKED_FLAG));
	}
	m_size = a.m_size;
	copy(m_data, a.m_data, m_size);
	return *this;
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
__forceinline T* hkArray<T>::expandBy( int n )
{
	int oldsize = m_size;
	setSize( oldsize + n );
	return m_data+oldsize;
}
template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkVector4() { }
		__forceinline hkVector4(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline hkVector4(const hkQuadReal& q);
		__forceinline hkVector4( const hkVector4& v);
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
struct hkGeometry;
class hkpShape;
class hkpRigidBodyCinfo;
class hkpRigidBody;
class hkpConstraintInstance;
struct hkpMassProperties
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpMassProperties), HK_MEMORY_CLASS_INERTIA); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_INERTIA); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkpMassProperties() :	m_volume(0.0f),		m_mass(0.0f)	{		m_centerOfMass.setZero4();		m_inertiaTensor.setZero();	}
	void scaleToDensity( hkReal density );
	void scaleToMass( hkReal newMass );
	hkReal	m_volume;
	hkReal	m_mass;
	hkVector4 m_centerOfMass;
	hkMatrix3 m_inertiaTensor;
};
struct hkpMassElement;
class hkpInertiaTensorComputer
{
	public:
		static hkResult __cdecl computeSphereVolumeMassProperties( hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeBoxVolumeMassProperties(const hkVector4& halfExtents, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeCapsuleVolumeMassProperties( const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeSphereSurfaceMassProperties( hkReal radius, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeBoxSurfaceMassProperties(const hkVector4& halfExtents, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl FUN_00973c80(const hkVector4& v0, const hkVector4& v1, const hkVector4& v2, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result);
		static hkResult __cdecl computeCylinderVolumeMassProperties(const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius, hkReal mass, hkpMassProperties& result);
		static hkResult __cdecl computeVertexHullVolumeMassProperties(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeVertexCloudMassProperties(const hkReal* vertexIn, int striding, int numVertices, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeGeometrySurfaceMassProperties(const hkGeometry* geom, hkReal surfaceThickness, hkBool distributeUniformly, hkReal mass, hkpMassProperties &result);
		static void __cdecl computeGeometryVolumeMassProperties(const hkGeometry* geom, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl computeGeometryVolumeMassPropertiesChecked(const hkGeometry* geom, hkReal mass, hkpMassProperties &result);
		static hkResult __cdecl combineMassProperties(const hkArray<hkpMassElement>& elements, hkpMassProperties& result );
		static void __cdecl computeShapeVolumeMassProperties(const hkpShape* shape, hkReal mass, hkpMassProperties &result);
		static void __cdecl setShapeVolumeMassProperties(const hkpShape* shape, hkReal mass, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setMassProperties(const hkpMassProperties& props, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setAndScaleToDensity(const hkpMassProperties& props, hkReal density, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl setAndScaleToMass(const hkpMassProperties& props, hkReal mass, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl clipInertia(hkReal maxInertiaRatio, hkpRigidBodyCinfo& bodyInfo);
		static void __cdecl simplifyInertiaTensorToOrientedParticle(hkMatrix3 &inertia);
		static void __cdecl convertInertiaTensorToPrincipleAxis( hkMatrix3& inertia, hkRotation& principleAxisOut );
		static void __cdecl optimizeInertiasOfConstraintTree( hkpConstraintInstance*const* constraints, int numConstraints, hkpRigidBody* rootBody, hkReal inertiaFactorHint = 1.5f );
		static void __cdecl FUN_00971660(hkVector4& shift, hkReal mass, hkMatrix3& inertia);
		static void __cdecl shiftInertiaFromCom(hkVector4& shift, hkReal mass, hkMatrix3& inertia);
};
// the double 9.0 at 0x00dcc5a8, named so by the checker's symbol table
extern const double FUN_00dcc5a8;
struct hkGeometry
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkGeometry), HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	struct Triangle
	{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkGeometry::Triangle), HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_BASE_CLASS); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		int m_a;
		int m_b;
		int m_c;
		void set( int a, int b, int c )
		{
			m_a = a;
			m_b = b;
			m_c = c;
		}
	};
	hkArray<hkVector4> m_vertices;
	hkArray<Triangle> m_triangles;
};
// pdb: hkpInertiaTensorComputer::computeTriangleSurfaceMassProperties | hkpInertiaTensorComputer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: v0, v1, v2, mass, surfaceThickness, result
hkResult hkpInertiaTensorComputer::FUN_00973c80(const hkVector4& v0, const hkVector4& v1, const hkVector4& v2, hkReal mass, hkReal surfaceThickness, hkpMassProperties& result)
{
	if (mass <= 0.0f)
	{
		return HK_FAILURE;
	}
	if (surfaceThickness < 0.0f)
	{
		return HK_FAILURE;
	}
	const hkReal minTwiceArea = 1e-5f;
	hkVector4 com;
	hkVector4 normal;
	{
		hkVector4 cb; cb.setSub4(v2, v1);
		hkVector4 ab; ab.setSub4(v0, v1);
		normal.setCross(cb, ab);
	}
	hkReal twiceArea = normal.length3();
	hkMatrix3 it;
	if (surfaceThickness < 1e-5f)
	{
		com = v0;
		com.add4(v1);
		com.add4(v2);
		com.setMul4(1.0f / 3.0f, com);
		hkReal Ixx = mass / 12.0f * (com(0) * FUN_00dcc5a8 * com(0) + v0(0) * v0(0) + v1(0) * v1(0) + v2(0) * v2(0));
		hkReal Iyy = mass / 12.0f * (com(1) * FUN_00dcc5a8 * com(1) + v0(1) * v0(1) + v1(1) * v1(1) + v2(1) * v2(1));
		hkReal Izz = mass / 12.0f * (com(2) * FUN_00dcc5a8 * com(2) + v0(2) * v0(2) + v1(2) * v1(2) + v2(2) * v2(2));
		hkReal Ixy = mass / 12.0f * (com(0) * FUN_00dcc5a8 * com(1) + v0(0) * v0(1) + v1(0) * v1(1) + v2(0) * v2(1));
		hkReal Ixz = mass / 12.0f * (com(0) * FUN_00dcc5a8 * com(2) + v0(0) * v0(2) + v1(0) * v1(2) + v2(0) * v2(2));
		hkReal Iyz = mass / 12.0f * (com(1) * FUN_00dcc5a8 * com(2) + v0(1) * v0(2) + v1(1) * v1(2) + v2(1) * v2(2));
		it(0,0) = Iyy + Izz;
		it(1,1) = Ixx + Izz;
		it(2,2) = Ixx + Iyy;
		it(0,1) = it(1,0) = -Ixy;
		it(0,2) = it(2,0) = -Ixz;
		it(2,1) = it(1,2) = -Iyz;
		hkpInertiaTensorComputer::FUN_00971660(com, mass, it);
	}
	else
	{
		if (twiceArea < minTwiceArea)
		{
			com = v0;
			com.add4(v1);
			com.add4(v2);
			com.setMul4(1.0f / 3.0f, com);
			hkReal rx = com(0);
			hkReal ry = com(1);
			hkReal rz = com(2);
			it(0,0) = (ry * ry + rz * rz) * mass;
			it(1,1) = (rx * rx + rz * rz) * mass;
			it(2,2) = (ry * ry + rx * rx) * mass;
			it(0,1) = -mass * (ry * rx);
			it(1,0) = -mass * (ry * rx);
			it(0,2) = -mass * (rz * rx);
			it(2,0) = -mass * (rz * rx);
			it(2,1) = -mass * (ry * rz);
			it(1,2) = -mass * (ry * rz);
		}
		else
		{	normal.normalize3();
			hkInplaceArray<hkVector4,6> verts;
			verts.setSize(6);
			verts[0] = v0;
			verts[1] = v0;
			verts[0].addMul4(surfaceThickness * 0.5f, normal);
			verts[1].addMul4(-surfaceThickness * 0.5f, normal);
			verts[2] = v1;
			verts[3] = v1;
			verts[2].addMul4(surfaceThickness * 0.5f, normal);
			verts[3].addMul4(-surfaceThickness * 0.5f, normal);
			verts[4] = v2;
			verts[5] = v2;
			verts[4].addMul4(surfaceThickness * 0.5f, normal);
			verts[5].addMul4(-surfaceThickness * 0.5f, normal);
			hkpMassProperties properties;
			{
				hkGeometry triGeom;
				triGeom.m_vertices = verts;
				triGeom.m_triangles.expandBy(1)->set(0, 2, 4);
				triGeom.m_triangles.expandBy(1)->set(1, 5, 3);
				triGeom.m_triangles.expandBy(1)->set(0, 3, 2);
				triGeom.m_triangles.expandBy(1)->set(0, 1, 3);
				triGeom.m_triangles.expandBy(1)->set(1, 0, 4);
				triGeom.m_triangles.expandBy(1)->set(1, 4, 5);
				triGeom.m_triangles.expandBy(1)->set(2, 5, 4);
				triGeom.m_triangles.expandBy(1)->set(2, 3, 5);
				hkpInertiaTensorComputer::computeGeometryVolumeMassProperties(&triGeom, mass, properties);
			}
			com = properties.m_centerOfMass;
			it = properties.m_inertiaTensor;
		}
	}
	result.m_mass = mass;
	result.m_inertiaTensor = it;
	result.m_centerOfMass = com;
	result.m_volume = twiceArea * 0.5f * surfaceThickness;
	return HK_SUCCESS;
}
void hkpInertiaTensorComputer::FUN_00971660(hkVector4& shift, hkReal mass, hkMatrix3& inertia)
{
	inertia(0,0) -= (shift(1) * shift(1) + shift(2) * shift(2)) * mass;
	inertia(1,1) -= (shift(2) * shift(2) + shift(0) * shift(0)) * mass;
	inertia(2,2) -= (shift(0) * shift(0) + shift(1) * shift(1)) * mass;
	inertia(0,1) = inertia(1,0) += mass * shift(0) * shift(1);
	inertia(1,2) = inertia(2,1) += mass * shift(1) * shift(2);
	inertia(2,0) = inertia(0,2) += mass * shift(2) * shift(0);
}

}  // namespace f3m_00973c80

// @f3 0x0097cd50 (community match, verified in this file)
// 0x0097cd50: hkpListShape::getAabbWithChildShapesForAgent(const hkpCollisionInput& collisionInput, const
// hkpAabbUtil::OffsetAabbInput& input, hkBool32 useContinuousPhysics, const hkTransform& localToWorld, hkReal
// tolerance, hkAabb& rootAabb, hk1AxisSweep::AabbInt* aabbs, int numAabbs) const of Havok 5.5.0 (hkpCollide,
// hkpListShape.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-). For every enabled child of the list shape: the
// child's AABB (swept by the inlined hkpAabbUtil::sweepOffsetAabb when continuous physics is on), the root AABB
// grown by it, and the AABB converted to the integer form of the 1-axis sweep with the child's key in it; returns
// the number of enabled children.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by a reducer, then whole unused lines, every cut checked byte for byte); those declarations are the
// SDK's text with its names. The function's body follows the SDK's unoptimized (hybrid) library object, which the
// same source reproduces with all 15 named locals. Two places are not the SDK's text:
// (1) hkVector4Util::convertAabbToUint32 copies hkAabbUint32MaxVal into a local vector before the two clips; the
//     SDK's header passes the global to both. That is the game's only difference from the SDK's release object
//     (eight instructions and 0x20 bytes of frame).
// (2) hkMath::hkToIntFast, inline assembly in the SDK's header, calls the pack's fnv_FloatToInt (the same
//     fld / fistp pair).
// Only the function carries the packet's name.
namespace f3m_0097cd50 {

typedef float  hkReal;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
typedef void* hk_va_list;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		hkInt32 f = *(int*)&fv;
		hkInt32* minf = (hkInt32*)&hkUFloat8_intToReal[0];
		hkInt32* maxf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
		for (int i = 6; i>=0; i--)
		{
			if ( f > midf[0]){		minf = midf;	}	else	{	maxf = midf;	}
			midf = (hkInt32*)(  (hkUlong(minf)>>1) + (hkUlong(maxf)>>1) );
		}
		if ( f > midf[0])
		{
			midf++;
		}
		hkUlong fi = midf - (hkInt32*)(&hkUFloat8_intToReal[0]);
		m_value = hkUint8(fi);
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
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
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
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
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
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
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
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
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline int __cdecl hkToIntFast( hkReal r )
	{
		return fnv_FloatToInt( r );
	}
}
extern const hkQuadReal hkQuadReal0000;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkSweptTransform() { }
	public:
		__forceinline void _approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		__forceinline hkReal getInterpolationValue( hkTime t ) const;
		__forceinline hkReal getInterpolationValueHiAccuracy( hkTime t, hkReal deltaTimeAddon ) const;
		__forceinline hkTime getBaseTime() const;
		__forceinline hkReal getInvDeltaTime() const;
		void initSweptTransform( const hkVector4& position, const hkQuaternion& rotation );
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};
class hkQsTransform
{
	public:
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(IdentityInitializer init);
		__forceinline hkQsTransform(ZeroInitializer init);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation);
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline void set(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline void setIdentity();
		__forceinline static const hkQsTransform& __cdecl getIdentity();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline const hkVector4& getScale() const;
		__forceinline void setScale(const hkVector4& s);
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setInterpolate4( const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
		void setFromTransformNoScale (const hkTransform& transform);
		void copyToTransformNoScale (hkTransform& transformOut) const;
		void setFromTransform (const hkTransform& transform);
		void copyToTransform (hkTransform& transformOut) const;
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
		__forceinline void setMulMulInverse( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulEq( const hkQsTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		hkBool set4x4ColumnMajor(const hkReal* p);
		hkBool isOk() const;
		hkBool isApproximatelyEqual( const hkQsTransform& other, hkReal epsilon=1e-3f ) const;
		__forceinline void setZero();
		__forceinline void blendAddMul(const hkQsTransform& other,  hkSimdRealParameter weight = 1.0f );
		__forceinline void blendNormalize( hkSimdRealParameter totalWeight = 1.0f);
		__forceinline void fastRenormalize( hkSimdRealParameter totalWeight = 1.0f);
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	;
	return (&x)[i];
}
inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}
inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x < b.x ? a.x : b.x;
		y = a.y < b.y ? a.y : b.y;
		z = a.z < b.z ? a.z : b.z;
		w = a.w < b.w ? a.w : b.w;
	}
inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x > b.x ? a.x : b.x;
		y = a.y > b.y ? a.y : b.y;
		z = a.z > b.z ? a.z : b.z;
		w = a.w > b.w ? a.w : b.w;
	}
inline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& d = *this;
		d(0) = t(0,0)*v0 + t(0,1)*v1 + t(0,2)*v2 + t(0,3);
		d(1) = t(1,0)*v0 + t(1,1)*v1 + t(1,2)*v2 + t(1,3);
		d(2) = t(2,0)*v0 + t(2,1)*v1 + t(2,2)*v2 + t(2,3);
		d(3) = 0;
	}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline const hkVector4& __cdecl hkVector4::getZero()
{
	const hkVector4& zero = *reinterpret_cast<const hkVector4*>(&hkQuadReal0000);
	return zero;
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
const hkVector4& hkTransform::getTranslation() const
{
	return m_translation;
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
class hkString
{
	public:
	public:
		__forceinline hkString();
		__forceinline hkString(const char* s);
		__forceinline hkString(const char* b, int len);
		__forceinline hkString(const hkString& s);
	private:
		hkString(char* ptr, int size, int capacity);
		__forceinline	void setLength( int length );
	public:
		__forceinline hkString& operator=(const hkString& s);
		__forceinline hkString& operator=(const char* s);
		__forceinline ~hkString();
		__forceinline char operator[] (int i) const;
		__forceinline void setCapacity(int capacity);
		__forceinline int getCapacity() const;
		void printf(const char* format, ...);
		int indexOf (char c, int startIndex=0, int endIndex=2147483647) const;
		int lastIndexOf (char c, int startIndex=0, int endIndex=2147483647) const;
		__forceinline const char* cString() const;
		int compareTo(const hkString& other) const;
		int compareTo(const char* other) const;
		int compareToIgnoreCase(const hkString& other) const;
		int compareToIgnoreCase(const char* other) const;
		__forceinline hkBool operator< (const hkString& s) const;
		__forceinline hkBool operator== (const hkString& s) const;
		__forceinline hkBool operator!= (const hkString& s) const;
		__forceinline hkBool operator== (const char* s) const;
		__forceinline hkBool operator!= (const char* s) const;
		__forceinline hkBool beginsWith(const hkString& s) const;
		hkBool beginsWith(const char* s) const;
		hkBool endsWith(const hkString& s) const;
		hkBool endsWith(const char* s) const;
		hkString operator+ (const hkString& other) const;
		hkString operator+ (const char* other) const;
		hkString& operator+= (const hkString& other);
		hkString& operator+= (const char* other);
		int getLength() const;
		enum ReplaceType
		{
			REPLACE_ONE,
			REPLACE_ALL
		};
		hkString replace(char from, char to, ReplaceType=REPLACE_ALL) const;
		hkBool replaceInplace(char from, char to, ReplaceType=REPLACE_ALL);
		hkString replace(const hkString& from, const hkString& to, ReplaceType=REPLACE_ALL) const;
		hkBool replaceInplace(const hkString& from, const hkString& to, hkString::ReplaceType rtype=REPLACE_ALL);
		hkString asUpperCase() const;
		void makeUpperCase();
		hkString asLowerCase() const;
		void makeLowerCase();
		__forceinline hkString substr(int index, int maxChars=2147483647) const;
		__forceinline void setAsSubstr(int index, int maxChars=2147483647);
	private:
		hkArray<char> m_string;
	public:
		static char __cdecl toUpper( char c );
		static char __cdecl toLower( char c );
		static int __cdecl snprintf(char* buf, int n, const char* fmt, ...);
		static int __cdecl vsnprintf(char* buf, int len, const char* fmt, hk_va_list hkargs);
		static int __cdecl sprintf(char* buf, const char* fmt, ...);
		static int __cdecl strCmp(const char* s1, const char* s2 );
		static int __cdecl strNcmp(const char* s1, const char* s2, int n);
		static int __cdecl strCasecmp(const char* s1, const char* s2 );
		static int __cdecl strNcasecmp(const char* s1, const char* s2, int n);
		static void __cdecl strCpy(char* dst, const char* src);
		static void __cdecl strNcpy(char* dst, const char* src, int n);
		static int __cdecl strLen(const char* src);
		static int __cdecl atoi(const char* in);
		static hkReal __cdecl atof(const char* in);
		static const char* __cdecl strStr(const char* haystack, const char* needle);
		static hkBool findAllOccurrences(const char* haystack, const char* needle, hkArray<int>& indices, hkString::ReplaceType rtype);
		static const char* __cdecl strChr(const char* haystack, int needle);
		static const char* __cdecl strRchr(const char* haystack, int needle);
		static char* __cdecl strDup(const char* src);
		static char* __cdecl strNdup(const char* src, int maxlen);
		static char* __cdecl strLwr(char* src);
		static char* __cdecl strUpr(char* src);
		static void __cdecl memCpy(void* dst, const void* src, int n);
		static __forceinline void __cdecl memCpy4(void* dst, const void* src, int numWords);
		static __forceinline void __cdecl memCpy16(void* dst, const void* src, int numQuads);
		template<int size>
		static __forceinline void __cdecl memCpy16(void* dst, const void* src);
		static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads);
		static __forceinline void __cdecl memCpy128(void* dst, const void* src);
		static __forceinline void __cdecl memCpy256(void* dst, const void* src);
		static void __cdecl memMove(void* dst, const void* src, int n);
		static void __cdecl memSet(void* dst, const int c, int nBytes);
		static __forceinline void __cdecl memSet4(void* dst, const int value, int numWords);
		static __forceinline void __cdecl memClear16(void* dst, int numQuads);
		static __forceinline void __cdecl memSet16(void* dst, const void* value, int numQuads);
		static int __cdecl memCmp(const void* buf1, const void* buf2, int n);
private:
		static void copyAndReplace( char* dest, const char* orig, int origLen, const hkString& from, const hkString& to, const hkArray<int>& indices);
};
class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkMotionState();
		void initMotionState( const hkVector4& position, const hkQuaternion& rotation );
		inline hkTransform& getTransform();
		inline const hkTransform& getTransform() const;
		inline const hkSweptTransform& getSweptTransform() const;
		inline hkSweptTransform& getSweptTransform();
	protected:
		hkTransform m_transform;
		class hkSweptTransform m_sweptTransform;
	public:
		hkVector4 m_deltaAngle;
		hkReal m_objectRadius;
		hkReal	m_linearDamping;
		hkReal	m_angularDamping;
		hkUFloat8 m_maxLinearVelocity;
		hkUFloat8 m_maxAngularVelocity;
		hkUint8	m_deactivationClass;
};
const hkSweptTransform& hkMotionState::getSweptTransform() const
{
	return m_sweptTransform;
}
class hkAabb
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkAabb() { }
		__forceinline hkAabb(const hkVector4& min, const hkVector4& max);
		__forceinline hkBool overlaps( const hkAabb& testAabb ) const;
		hkBool isValid() const;
		__forceinline hkBool contains(const hkAabb& other) const;
		__forceinline hkBool containsPoint(const hkVector4& other) const;
		__forceinline void includePoint (const hkVector4& point);
		__forceinline void setEmpty ();
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};
struct hkAabbUint32
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	inline void operator=( const hkAabbUint32& other );
	inline void setInvalid();
	inline void setInvalidY();
	__declspec(align(16)) hkUint32 m_min[3];
	hkUchar m_expansionMin[3];
	hkUchar m_expansionShift;
	hkUint32 m_max[3];
	hkUchar m_expansionMax[3];
	hkUchar m_sortIndex;
};
void hkAabb::setEmpty()
{
	m_min.setAll(3.40282e+38f);
	m_max.setAll(-3.40282e+38f);
}
class hkSphere;
class hkpCdVertex;
enum hkpShapeType
{
	HK_SHAPE_INVALID = 0,
	HK_SHAPE_CONVEX,
	HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX,
	HK_SHAPE_SPHERE,
	HK_SHAPE_CYLINDER,
	HK_SHAPE_TRIANGLE,
	HK_SHAPE_BOX,
	HK_SHAPE_CAPSULE,
	HK_SHAPE_CONVEX_VERTICES,
	HK_SHAPE_COLLECTION,
	HK_SHAPE_BV_TREE,
	HK_SHAPE_LIST,
	HK_SHAPE_MOPP,
	HK_SHAPE_CONVEX_TRANSLATE,
	HK_SHAPE_CONVEX_TRANSFORM,
	HK_SHAPE_SAMPLED_HEIGHT_FIELD,
	HK_SHAPE_EXTENDED_MESH,
	HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_MAX_ID_SPU = HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_PACKED_CONVEX_VERTICES,
	HK_SHAPE_MOPP_EMBEDDED,
	HK_SHAPE_CONVEX_PIECE,
	HK_SHAPE_MULTI_SPHERE,
	HK_SHAPE_CONVEX_LIST,
	HK_SHAPE_TRIANGLE_COLLECTION,
	HK_SHAPE_MULTI_RAY,
	HK_SHAPE_HEIGHT_FIELD,
	HK_SHAPE_SPHERE_REP,
	HK_SHAPE_BV,
	HK_SHAPE_PLANE,
	HK_SHAPE_TRANSFORM,
	HK_SHAPE_PHANTOM_CALLBACK,
	HK_SHAPE_USER0,
	HK_SHAPE_USER1,
	HK_SHAPE_USER2,
	HK_SHAPE_MAX_ID,
	HK_SHAPE_ALL = -1
};
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpShape( hkpShapeType type );
		__forceinline hkpShapeType getType() const;
		__forceinline void getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		__forceinline hkBool castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			static void __cdecl resetShapeFunctions();
			typedef void (__cdecl *GetSupportingVertexFunc)        (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int  (__cdecl *GetNumCollisionSpheresFunc)		(const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc)					(const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				hkPadSpu<GetSupportingVertexFunc>			m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc>				m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc>						m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc>		m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc>			m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc>						m_getAabbFunc;
				hkPadSpu<CastRayFunc>						m_castRay;
				hkPadSpu<GetChildShapeFunc>					m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc		m_convertVertexIdsToVertices;
				WeldContactPointFunc				m_weldContactPointFunc;
				GetCentreFunc						m_getCentreFunc;
				GetNumCollisionSpheresFunc			m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc				m_getCollisionSpheresFunc;
				GetAabbFunc							m_getAabbFunc;
				CastRayFunc							m_castRay;
				GetChildShapeFunc					m_getChildShapeFunc;
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
	public:
	public:
		hkUlong m_userData;
	public:
		hkEnum< hkpShapeType, hkUint32> m_type;
	public:
		hkpShape( class hkFinishLoadedObjectFlag flag ) { m_type = HK_SHAPE_INVALID; }
};
void hkpShape::getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const
{
	getAabbImpl( localToWorld, tolerance, out );
}
class hkpCollisionDispatcher;
class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionInput
{
	public:
		hkReal getTolerance() const { return m_tolerance; }
		void setTolerance(hkReal t) { m_tolerance = t; }
	public:
		hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
		hkPadSpu<hkReal> m_tolerance;
		hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
		hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
		mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
		struct Aabb32Info
		{
			hkVector4 m_bitOffsetLow;
			hkVector4 m_bitOffsetHigh;
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
};
class hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 512 };
		typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
		virtual ~hkpShapeContainer() { }
		virtual int getNumChildShapes() const;
		virtual hkpShapeKey getFirstKey() const = 0;
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const = 0;
		virtual hkUint32 getCollisionFilterInfo( hkpShapeKey key ) const;
		virtual const hkpShape* getChildShape( hkpShapeKey key, ShapeBuffer& buffer ) const = 0;
		virtual hkBool32 isChildEnabled( hkpShapeKey key ) const { return true; }
		virtual bool isWeldingEnabled() const { return true; }
};
class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpShapeCollection( hkpShapeType type );
		hkpShapeCollection( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_COLLECTION; }
		virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
 		virtual void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual const hkpShapeContainer* getContainer() const;
		__forceinline bool isWeldingEnabled() const { return !m_disableWelding; }
	public:
		hkBool m_disableWelding;
};
class hkpAabbUtil
{
	public:
		static void __cdecl calcAabb( const float* vertexArray, int numVertices, int striding, hkAabb& aabbOut );
		static inline void __cdecl calcAabb( const hkTransform& BvToWorld, const hkVector4& halfExtents, const hkVector4& center, float extraRadius, hkAabb& aabbOut);
		static inline void __cdecl calcAabb( const hkTransform& BvToWorld, const hkVector4& halfExtents, float extraRadius, hkAabb& aabbOut);
	public:
		struct OffsetAabbInput
		{
			hkPadSpu<const hkMotionState*> m_motionState;
			hkTransform m_transforms[4];
			hkPadSpu<int> m_numTransforms;
			hkTransform m_startTransform;
			hkTransform m_endTransformInv;
		};
		__forceinline static void __cdecl sweepAabb(const hkMotionState* motionstate, hkReal tolerance, const hkAabb& aabbIn, hkAabb& aabbOut);
		static void __cdecl initOffsetAabbInput(const hkMotionState* motionstate, OffsetAabbInput& input);
		static void __cdecl sweepOffsetAabb(const OffsetAabbInput& input, const hkAabb& aabbIn, hkAabb& aabbOut);
};
__forceinline void __cdecl hkpAabbUtil::sweepOffsetAabb(const hkpAabbUtil::OffsetAabbInput& input, const hkAabb& aabbIn, hkAabb& aabbOut)
{
	hkSimdReal half(0.5f);
	hkVector4 aabbHalfSize; aabbHalfSize.setSub4(aabbIn.m_max, aabbIn.m_min);  aabbHalfSize.mul4(half);
	hkVector4 aabbCenter; aabbCenter.setInterpolate4(aabbIn.m_max, aabbIn.m_min, half);
	hkVector4 arm; arm._setTransformedPos(input.m_endTransformInv, aabbCenter);
	hkVector4 min = aabbCenter;
	hkVector4 max = aabbCenter;
	{
		hkVector4 p; p._setTransformedPos(input.m_startTransform, arm);
		min.setMin4(min, p);
		max.setMax4(max, p);
	}
	const hkVector4 centerOfMassLocal = input.m_motionState->getSweptTransform().m_centerOfMassLocal;
	for (int i = 0; i < input.m_numTransforms; i++)
	{
		hkVector4 extendedArm;
		extendedArm.setSub4(arm, centerOfMassLocal);
		extendedArm.mul4(input.m_transforms[i].getTranslation().getSimdAt(3));
		extendedArm.add4(centerOfMassLocal);
		hkVector4 p; p._setTransformedPos(input.m_transforms[i], extendedArm);
		min.setMin4(min, p);
		max.setMax4(max, p);
	}
	{
		hkSimdReal r = aabbHalfSize.length3();
		hkVector4 radius; radius.setAll(r);
		aabbHalfSize.addMul4(input.m_motionState->m_deltaAngle.getSimdAt(3), radius);
		aabbHalfSize.setMin4(radius, aabbHalfSize);
	}
	aabbOut.m_min.setSub4(min, aabbHalfSize);
	aabbOut.m_max.setAdd4(max, aabbHalfSize);
	aabbOut.m_min.setMin4(aabbIn.m_min, aabbOut.m_min);
	aabbOut.m_max.setMax4(aabbIn.m_max, aabbOut.m_max);
}
class hkShapeKeyPair;
class hk1AxisSweep
{
	public:
		struct AabbInt : public hkAabbUint32
		{
			__forceinline hkUint32 yzDisjoint( const AabbInt& other ) const
			{
				hkUint32 yab = m_max[1] - other.m_min[1];
				hkUint32 yba = other.m_max[1] - m_min[1];
				hkUint32 zab = m_max[2] - other.m_min[2];
				hkUint32 zba = other.m_max[2] - m_min[2];
				hkUint32 combined = (yab | yba) | (zab | zba);
				return combined & 0x80000000;
			}
			hkpShapeKey& getShapeKey() { return m_min[3]; }
			const hkpShapeKey& getShapeKey() const { return m_min[3]; }
			__forceinline bool operator<(const hk1AxisSweep::AabbInt& aabb1) const
			{
				return this->m_min[0] < aabb1.m_min[0];
			}
			static __forceinline bool __cdecl less(const hk1AxisSweep::AabbInt& aabb0, const hk1AxisSweep::AabbInt& aabb1)
			{
				return aabb0.m_min[0] < aabb1.m_min[0];
			}
			void operator=( const AabbInt& other )
			{
				hkString::memCpy16<sizeof(AabbInt)>( this, &other );
			}
		};
};
class hkpListShape : public hkpShapeCollection
{
	public:
		enum { MAX_CHILDREN_FOR_SPU_MIDPHASE = 252 };
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		struct ChildInfo
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			__declspec(align(16)) const hkpShape* m_shape;
			hkUint32 m_collisionFilterInfo;
			mutable int m_shapeSize;
			mutable int m_numChildShapes;
		};
	public:
		hkpListShape( const hkpShape*const* shapeArray, int numShapes );
		hkpListShape( class hkFinishLoadedObjectFlag flag );
		~hkpListShape();
		inline const hkpShape* getChildShapeInl(int i) const { return m_childInfo[i].m_shape; }
		void recalcAabbExtents();
		inline virtual int getNumChildShapes() const { return m_childInfo.getSize(); }
		inline virtual hkpShapeKey getFirstKey() const { return 0; }
		inline virtual hkpShapeKey getNextKey( hkpShapeKey key ) const { return int(++key) < m_childInfo.getSize() ? key : 0xffffffff; }
		virtual hkUint32 getCollisionFilterInfo(  hkpShapeKey key ) const;
		void setCollisionFilterInfo( hkpShapeKey index, hkUint32 filterInfo );
		__forceinline void disableChild( hkpShapeKey index )
		{
			;
			m_enabledChildren[ index>>5 ] &= ~(1<<(index&0x1f));
		}
		__forceinline void enableChild( hkpShapeKey index )
		{
			m_enabledChildren[ index>>5 ] |= (1<<(index&0x1f));
		}
		__forceinline hkBool32 isChildEnabled( hkpShapeKey index ) const
		{
			if ( index < MAX_DISABLED_CHILDREN )
			{
				return m_enabledChildren[ index>>5 ] & (1<<(index&0x1f));
			}
			return true;
		}
		virtual const hkpShape* getChildShape(  hkpShapeKey key, ShapeBuffer& buffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		static void __cdecl registerSimulationFunctions( ShapeFuncs& sf );
		static void __cdecl registerCollideQueryFunctions( ShapeFuncs& sf );
		static void __cdecl registerGetAabbFunction( ShapeFuncs& sf );
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
		int FUN_0097cd50(const hkpCollisionInput& collisionInput, const hkpAabbUtil::OffsetAabbInput& input, hkBool32 useContinuousPhysics, const hkTransform& localToWorld, hkReal tolerance, hkAabb& rootAabb, hk1AxisSweep::AabbInt* aabbs, int numAabbs) const;
	public:
		friend class hkpListAgent;
		hkArray<struct ChildInfo>	m_childInfo;
		hkVector4					m_aabbHalfExtents;
		hkVector4					m_aabbCenter;
		enum { MAX_DISABLED_CHILDREN = 256 };
		hkUint32 m_enabledChildren[ 8 ];
	protected:
		void setShapes( const hkpShape*const* shapeArray, int numShapes, const hkUint32* filterInfoArray = 0);
};
namespace hkVector4Util
{
__forceinline void __cdecl convertToUint32WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkUint32* out);
__forceinline void __cdecl convertAabbToUint32( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut );
extern __declspec(align(16)) float hkAabbUint32MaxVal[4];
}
inline void __cdecl hkVector4Util::convertToUint32WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkUint32* out)
{
	hkVector4 x;
	x.setAdd4(in,offset);
	x.mul4(scale);
	x.setMin4(x,max);
	x.setMax4(x,min);
	out[0] = static_cast<hkUint32>(hkMath::hkToIntFast(x(0)));
	out[1] = static_cast<hkUint32>(hkMath::hkToIntFast(x(1)));
	out[2] = static_cast<hkUint32>(hkMath::hkToIntFast(x(2)));
	out[3] = static_cast<hkUint32>(hkMath::hkToIntFast(x(3)));
}
inline void __cdecl hkVector4Util::convertAabbToUint32( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut )
{
    hkVector4 maxVal = (*reinterpret_cast<const hkVector4*>(&hkVector4Util::hkAabbUint32MaxVal));
    hkVector4Util::convertToUint32WithClip( aabb.m_min, offsetLow,  scale, hkVector4::getZero(), maxVal, aabbOut.m_min );
    hkVector4Util::convertToUint32WithClip( aabb.m_max, offsetHigh, scale, hkVector4::getZero(), maxVal, aabbOut.m_max );
}
int hkpListShape::FUN_0097cd50( const hkpCollisionInput& collisionInput, const hkpAabbUtil::OffsetAabbInput& input, hkBool32 useContinuousPhysics, const hkTransform& localToWorld, hkReal tolerance, hkAabb& rootAabb, hk1AxisSweep::AabbInt* aabbs, int numAabbs ) const
{
    ShapeBuffer buffer;
    rootAabb.setEmpty();
    int enabledShapesCtr = 0;
    for ( hkpShapeKey key = getFirstKey(); key != 0xffffffff; key = getNextKey( key ) )
    {
        if ( !isChildEnabled( key ) )
        {
            continue;
        }
        const hkpShape* child = getChildShape( key, buffer );
        hkAabb aabb;
        child->getAabb( localToWorld, tolerance, aabb );
        if ( useContinuousPhysics )
        {
            hkpAabbUtil::sweepOffsetAabb( input, aabb, aabb );
        }
        rootAabb.m_min.setMin4( rootAabb.m_min, aabb.m_min );
        rootAabb.m_max.setMax4( rootAabb.m_max, aabb.m_max );
        hk1AxisSweep::AabbInt& aabbInt = *aabbs;
        hkVector4Util::convertAabbToUint32( aabb, collisionInput.m_aabb32Info.m_bitOffsetLow, collisionInput.m_aabb32Info.m_bitOffsetHigh, collisionInput.m_aabb32Info.m_bitScale, aabbInt );
        aabbInt.m_min[3] = key;
        aabbs++;
        enabledShapesCtr++;
    }
    return enabledShapesCtr;
}

}  // namespace f3m_0097cd50

// @f3 0x00977030 (community match, verified in this file)
namespace f3m_00977030 {
// hkSweptTransformUtil_lerp2Ha = Havok 5.5.0 hkSweptTransformUtil::lerp2Ha (hkBase.lib, hkSweptTransformUtil.obj; the stock release
// object is byte-exact against the game). No .cpp ships: the two statements are rebuilt from the library's line records
// 24-27 (line 25 = inlined hkSweptTransform::getInterpolationValueHiAccuracy, line 26 = inlined _lerp2 of
// hkSweptTransformUtil.inl); everything else is Havok 5.5.0 SDK header/.inl text, cut to one file with hktrim.py.
// Target named hkSweptTransformUtil_lerp2Ha (free function, the pack symbol).
// sqrt / sqrtf: the CRT's <math.h>, which the pack unit includes.
namespace f3m_00977030 {
typedef float  hkReal;
typedef hkReal hkTime;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

class hkMatrix3;
class hkRotation;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline hkVector4() { }
		__forceinline hkVector4( const hkVector4& v);
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize4();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkQuaternion
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkVector4 m_vec;
};

class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline const hkReal& operator() (int row, int col) const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};

class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
};

class hkTransform
{
	public:
		                class MustEndWithSemiColon;
		__forceinline hkVector4& getTranslation();
		__forceinline hkRotation& getRotation();
		__forceinline void setRotation(const hkQuaternion& quatRotation);
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};

class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	public:
		__forceinline hkReal getInterpolationValueHiAccuracy( hkTime t, hkReal deltaTimeAddon ) const;
		__forceinline hkTime getBaseTime() const;
		__forceinline hkReal getInvDeltaTime() const;
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline hkVector4::hkVector4( const hkVector4& v)
{
	*this = v;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}

inline void hkVector4::sub4(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}

	inline void hkVector4::_setMul3( const hkMatrix3& r, const hkVector4& v )
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2;
		t(1) = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2;
		t(2) = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2;
		t(3) = 0;
	}

	inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
	}

inline hkSimdReal hkVector4::dot4(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z ) + ( w * a.w );
}

inline hkSimdReal hkVector4::lengthSquared4() const
{
	return this->dot4(*this);
}

	inline hkSimdReal hkVector4::lengthInverse4() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z) + (w*w);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

	inline void hkVector4::normalize4()
	{
		this->mul4( this->lengthInverse4() );
	}

inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}

inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}

hkVector4& hkTransform::getTranslation()
{
	return m_translation;
}

hkRotation& hkTransform::getRotation()
{
	return m_rotation;
}

void hkTransform::setRotation(const hkQuaternion& quatRotation)
{
	m_rotation.set(quatRotation);
}

hkTime hkSweptTransform::getBaseTime() const
{
	return hkTime(m_centerOfMass0(3));
}

hkReal hkSweptTransform::getInvDeltaTime() const
{
	return m_centerOfMass1(3);
}

hkReal hkSweptTransform::getInterpolationValueHiAccuracy( hkTime t, hkReal deltaTimeAddon ) const
{
	hkReal dt = t - getBaseTime();
	dt += deltaTimeAddon;
	hkReal ddt = dt * getInvDeltaTime();
	return ddt;
}

namespace hkSweptTransformUtil
{
		__forceinline void __cdecl _lerp2( const hkSweptTransform& sweptTrans, hkReal t, hkQuaternion& quatOut );
		__forceinline void __cdecl _lerp2( const hkSweptTransform& sweptTrans, hkReal t, hkTransform& transformOut );
}

void __cdecl hkSweptTransformUtil::_lerp2( const hkSweptTransform& sweptTrans, hkReal t, hkQuaternion& quatOut )
{
	hkVector4 rot0 = sweptTrans.m_rotation0.m_vec;
	hkVector4 rot1 = sweptTrans.m_rotation1.m_vec;
	{
		quatOut.m_vec.setAdd4( rot0, rot1 );
		hkReal len2 = quatOut.m_vec.lengthSquared4();
		hkReal r = 0.75f - 0.125f * len2;
		r = r * (1.5f - 0.5f * len2 * r * r);
		quatOut.m_vec.mul4(r);
	}
	if ( t < 0.5f )
	{
		quatOut.m_vec.setInterpolate4( rot0, quatOut.m_vec, 2.0f * t);
	}
	else
	{
		quatOut.m_vec.setInterpolate4( quatOut.m_vec, rot1, 2.0f * t - 1.0f);
	}
	quatOut.m_vec.normalize4();
}

void __cdecl hkSweptTransformUtil::_lerp2( const hkSweptTransform& sweptTrans, hkReal t, hkTransform& transformOut )
{
	hkQuaternion qt;
	_lerp2( sweptTrans, t, qt );
	transformOut.setRotation( qt );
	transformOut.getTranslation().setInterpolate4( sweptTrans.m_centerOfMass0, sweptTrans.m_centerOfMass1, t);
	hkVector4 centerShift;
	centerShift._setRotatedDir( transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
	transformOut.getTranslation().sub4( centerShift );
}

// pdb: hkSweptTransformUtil::lerp2Ha | hkSweptTransformUtil.obj | fnv360_0822_debug, objrun + skyrim(call_gap), high
void __cdecl hkSweptTransformUtil_lerp2Ha( const hkSweptTransform& sweptTrans, hkTime t, hkReal tAddOn, hkTransform& transformOut )
{
	hkReal r = sweptTrans.getInterpolationValueHiAccuracy( t, tAddOn );
	hkSweptTransformUtil::_lerp2( sweptTrans, r, transformOut );
}
}
}   // namespace f3m_00977030
