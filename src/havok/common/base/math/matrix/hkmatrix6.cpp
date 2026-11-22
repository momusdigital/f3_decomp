#include "f3_common.h"
// src/havok/common/base/math/matrix/hkmatrix6.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix6.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

struct hkVector4
{
    __m128 m_vComponents;
    void add4(const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
};

struct hkMatrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    void add(const hkMatrix3& a)
    {
        m_kColumn0.add4(a.m_kColumn0);
        m_kColumn1.add4(a.m_kColumn1);
        m_kColumn2.add4(a.m_kColumn2);
    }
};

struct E29250Matrix3
{
    float m_kColumn0[4];
    float m_kColumn1[4];
    float m_kColumn2[4];

    void SetFromMatrix(const E29250Matrix3& s);
};

struct E29250Matrix6
{
    E29250Matrix3 m_iUnknownValue2[2][2];
};

// @fnv 0x00e29250
// pdb: hkMatrix6SetTranspose | hkMatrix6.obj | fnv360_0822_retail, caller_sim, low
// pdb params: out, in
void __cdecl FUN_00e29250(E29250Matrix6& out, const E29250Matrix6& in)
{
    out.m_iUnknownValue2[0][0].SetFromMatrix(in.m_iUnknownValue2[0][0]);
    out.m_iUnknownValue2[0][1].SetFromMatrix(in.m_iUnknownValue2[1][0]);
    out.m_iUnknownValue2[1][0].SetFromMatrix(in.m_iUnknownValue2[0][1]);
    out.m_iUnknownValue2[1][1].SetFromMatrix(in.m_iUnknownValue2[1][1]);
}

extern "C" __m128 _mm_load_ps(const float* p);

__forceinline void AddVector(__m128& dst, const __m128& src)
{
    dst = _mm_add_ps(dst, src);
}
__forceinline __m128 AddValues(__m128 dst, __m128 src)
{
    return _mm_add_ps(dst, src);
}
__forceinline void AddPointers(__m128* dst, const __m128* src)
{
    *dst = _mm_add_ps(_mm_load_ps((float*)dst), _mm_load_ps((const float*)src));
}

struct WrappedPointer
{
    void* p;
    WrappedPointer(void* q) : p(q)
    {}
};

// @f3 0x00a98480 (community match, verified in this file)
inline void AddScalar(float& out, float const volatile& value) { out = value + out; }
void __cdecl FUN_0096cd80(void* out, const void* a,
                          const void* b);

// pdb: hkMatrix6SetMul | hkMatrix6.obj | fnv360_0822_retail, objrun, medium
// pdb params: out, a, b
void __cdecl FUN_00e29470(void* dest, WrappedPointer src, WrappedPointer rhs)
{
    float* source = (float*)src.p;
    float* right = (float*)rhs.p;
    float* output = (float*)dest + 6;
    __declspec(align(16)) float temporary[12];
    int outerCount = 2;

    do {
        float* currentRight = right;
        int innerCount = 2;

        do {
            FUN_0096cd80(temporary, *(float* volatile*)&source, currentRight);
            float* first = output - 6;
            FUN_0096cd80(first, source + 12, currentRight + 24);

            first[0] += temporary[0];
            AddScalar(output[-5],temporary[1]);
            output[-4] = output[-4] + temporary[2];
            output[-3] = *(volatile float*)&output[-3] + temporary[3];
            output[-2] = output[-2] + temporary[4];
            output[-1] = output[-1] + temporary[5];
            output[0] = output[0] + temporary[6];
            AddScalar(output[1],temporary[7]);
            AddScalar(output[2],temporary[8]);
            AddScalar(output[3],temporary[9]);
            output[4] = *(volatile float*)&output[4] + temporary[10];
            output[5] = output[5] + temporary[11];

            currentRight += 12;
            output += 12;
        } while (--innerCount != 0);

        source += 24;
    } while (--outerCount != 0);
}
