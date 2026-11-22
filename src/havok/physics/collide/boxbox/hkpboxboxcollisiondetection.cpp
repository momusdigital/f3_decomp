#include "f3_common.h"
// src/havok/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// RemoveValueAt - drops slot <index> of the eight-slot table held by
// FUN_00db0920: the last slot in use is moved into the hole and the used-slot
// counter goes down by one.
struct FUN_00db0920
{
    int values[8];        // +0x00: eight four-byte slots, low half holds the key
    unsigned char unk20;  // +0x20
    unsigned char count;  // +0x21: number of slots in use
    unsigned char flag;   // +0x22
    void RemoveValueAt(int index);
};

// @fnv 0x00db0900
// pdb: hkpBoxBoxManifold::removePoint | hkpBoxBoxManifold.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: i
void FUN_00db0920::RemoveValueAt(int index)
{
    // Stored through an alias on purpose: with a direct member store the
    // compiler hoists the count load above the store, the original does not.
    unsigned char* pFlag = &flag;
    *pFlag = 0;
    values[index] = values[count - 1];
    count--;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
}

extern "C"
{
}
extern "C++"
{
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkVector4
{
    __m128 m_vComponents;
    __m128 q() const
    {
        return m_vComponents;
    }
    void set(__m128 v)
    {
        m_vComponents = v;
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(this)[i];
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(this)[i];
    }
};

static __forceinline __m128 dot3v(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
}

static __forceinline float toReal(__m128 v)
{
    float r;
    _mm_store_ss(&r, v);
    return r;
}
