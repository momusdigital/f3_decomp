#include "f3_common.h"
// src/havok/physics/collide/shape/convex/cylinder/hkpcylindershape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/cylinder/hkpcylindershape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCylinderShape.h"

// @fnv 0x00d571b0
// pdb: hkpCylinderShape::getNumCollisionSpheresImpl | hkpCylinderShape.obj | fnv360_0822_retail, objrun + skyrim(objrun_open), high
int __cdecl hkpCylinderShape_getNumCollisionSpheresImpl()
{
    return 0x12;
}

// FUN_00d571a0: __thiscall getter returning the float at this+0x14,
// which is hkpCylinderShape::m_fCylinderRadius in the pack's layout
// (vptr 0x0, m_usMemSizeAndFlags 0x4, m_sReferenceCount 0x6, m_ulUserData 0x8,
//  m_type 0xC, m_fSphereRadius 0x10, m_fCylinderRadius 0x14).

class hkpCylinderShapeGetCylRadius : public hkpCylinderShape {
public:
    hkReal FUN_00d571a0();
};

// @fnv 0x00d571a0
hkReal hkpCylinderShapeGetCylRadius::FUN_00d571a0() {
    return m_fCylinderRadius;
}

// hkVector4: components through operator(), as the SDK writes them.
struct __declspec(align(16)) Vector4C573 {
    float m_quad[4];
    float& operator()(int i) { return m_quad[i]; }
};
// hkpCylinderShape: the convex radius, the cylinder radius and the two end points (New Vegas Xbox 360 PDB names).
struct C00d573e0 {
    int unk00, unk04, unk08, unk0C;
    float m_radius;       // +0x10
    float m_cylRadius;    // +0x14
    float m_cylBaseRadiusFactorForHeightFieldCollisions;
    int unk1C;
    Vector4C573 m_vertexA;  // +0x20
    Vector4C573 m_vertexB;  // +0x30
    void SetValue(float v);
};

// @fnv 0x00d573e0
// pdb: hkpCylinderShape::setCylinderRadius | hkpCylinderShape.obj | fnv360_0822_retail, objrun, high
// pdb params: radius
void C00d573e0::SetValue(float afValue) {
        m_cylRadius = afValue;
    m_vertexA(3) = m_radius + afValue;
    m_vertexB(3) = afValue + m_radius;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

static __declspec(noinline) float FUN_00d571d0()
{
    return 0.0f;
}

struct S00d57b20_Obj {
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;

    S00d57b20_Obj* __thiscall FUN_00d57b20(int condition);
};

// @f3 0x009e5f30 (community match, verified in this file)
extern char DAT_00e806bc;
extern float DAT_01062ec8;

static __declspec(noinline) float FUN_009e5290()
{
    return 0.0f;
}

// pdb: hkpCylinderShape::hkpCylinderShape | hkpCylinderShape.obj | fnv360_0822_retail, objrun, high
// pdb params: flag
S00d57b20_Obj* __thiscall S00d57b20_Obj::FUN_00d57b20(int condition)
{
    *(unsigned short*)((char*)this + 6) = 1;
    unk0C = 1;
    unk00 = &DAT_00e806bc;
    if (condition && DAT_01062ec8 < 0.0f)
        DAT_01062ec8 = 1.0f - FUN_009e5290();
    unk0C = 3;
    return this;
}


#include <xmmintrin.h>
#include <math.h>
namespace fnv_00d57220 {
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

struct Vec_d57220v {
    __m128 q;
    float& operator()(int i) { return q.m128_f32[i]; }
    const float& operator()(int i) const { return q.m128_f32[i]; }
    void setZero4() { q = _mm_setzero_ps(); }
    __forceinline void normalize3()
    {
        __m128 v = q;
        __m128 x2 = _mm_mul_ps(v, v);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 mask = _mm_cmpeq_ss(len2, _mm_set_ss(0.0f));
        __m128 t = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e));
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), t);
        r = _mm_andnot_ps(mask, r);
        q = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v);
    }
    void setCross(const Vec_d57220v& a, const Vec_d57220v& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(c0, c1);
    }
};

}  // namespace fnv_00d57220

namespace fnv_00d571d0 {
namespace c571 { const float DAT_01056528 = 1.1f; }
using namespace c571;
// @fnv 0x00d571d0
float __cdecl FUN_00d571d0()
{
    for (float fValue = 0.0f; fValue < DAT_01056528; fValue += 0.009999999776482582)
    {
        if (fnv_FloatToInt(fValue) != 0)
            return fValue;
    }
    return 1.0f;
}
}  // namespace fnv_00d571d0
