#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/pointtoplane/hkppointtoplaneconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtoplane/hkppointtoplaneconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPointToPlaneConstraintData.h"

// Sets b[0] and b[1] to 8 and 1 when a is nonzero, otherwise to 0 and 0.
// @fnv 0x00d84780
// pdb: hkpPulleyConstraintData::getRuntimeInfo | hkpPulleyConstraintData.obj | tesv_win, objrun_open, low
void __stdcall FUN_00d84780(unsigned char a, int* pData)
{
    if (a)
    {
        pData[1] = 1;
        pData[0] = 8;
    }
    else
    {
        pData[1] = 0;
        pData[0] = 0;
    }
}

extern "C" void* __cdecl FUN_00d21a60(void*, int, int);

struct FUN_00d84760 : public hkpPointToPlaneConstraintData
{
    void* PopulateInfo(int a);
};

// @fnv 0x00d84760
// pdb: hkpPointToPlaneConstraintData::getConstraintInfo | hkpPointToPlaneConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: infoOut
void* FUN_00d84760::PopulateInfo(int a)
{
    return FUN_00d21a60(&m_kBridgeAtoms, m_kBridgeAtoms.getSizeOfAllAtoms(), a);
}

// @fnv 0x00d847b0
// pdb: GuardActorPackageData::GetPackageType | GuardPackage.obj | fnv360_0822_retail, vtable, medium
int __cdecl FUN_00d847b0()
{
    return 14;
}

struct ValidationResult
{
    unsigned char value;
    ValidationResult(bool result) : value(result)
    {}
};
struct Transform
{
    ValidationResult IsTransformValid(float tolerance);
};
struct FUN_00d84b70
{
    ValidationResult CheckValid();
};
// Returns true if the Transform at offset 0x20 and the one at offset 0x60 both pass a 0.001 tolerance validation.
// @fnv 0x00d84b70
// pdb: hkpPointToPlaneConstraintData::isValid | hkpPointToPlaneConstraintData.obj | tesv_win, objrun_open, low
ValidationResult FUN_00d84b70::CheckValid()
{
    Transform* pFirstTransform = (Transform*)((char*)this + 0x20);
    Transform* pSecondTransform = (Transform*)((char*)this + 0x60);
    return pFirstTransform->IsTransformValid(0.001f).value && pSecondTransform->IsTransformValid(0.001f).value;
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00d847c0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
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

struct Vec_d849a0
{
    __m128 q;
    float& operator()(int i)
    {
        return q.m128_f32[i];
    }
    const float& operator()(int i) const
    {
        return q.m128_f32[i];
    }
    void setZero4()
    {
        q = _mm_setzero_ps();
    }
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
    void setCross(const Vec_d849a0& a, const Vec_d849a0& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(c0, c1);
    }
};

struct Rot_d849a0
{
    Vec_d849a0 col0;
    Vec_d849a0 col1;
    Vec_d849a0 col2;
    Vec_d849a0& getColumn(int i)
    {
        return (&col0)[i];
    }
};

}  // namespace fnv_00d847c0

namespace fnv_00d849a0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
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

struct Vec_d849a0
{
    __m128 q;
    float& operator()(int i)
    {
        return q.m128_f32[i];
    }
    const float& operator()(int i) const
    {
        return q.m128_f32[i];
    }
    void setZero4()
    {
        q = _mm_setzero_ps();
    }
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
    void setCross(const Vec_d849a0& a, const Vec_d849a0& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(c0, c1);
    }
};

struct Rot_d849a0
{
    Vec_d849a0 col0;
    Vec_d849a0 col1;
    Vec_d849a0 col2;
    Vec_d849a0& getColumn(int i)
    {
        return (&col0)[i];
    }
};

}  // namespace fnv_00d849a0

// @f3twin 0x00a72440 of 0x007ee170
// pdb: hkpSimpleMeshShape::initWeldingInfo | hkpSimpleMeshShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: weldingType
int __cdecl F3_FUN_00a72440()
{
    return 14;
}
