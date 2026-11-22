#include "f3_common.h"
// src/havok/common/base/math/matrix/hkmatrix4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix4.cpp).
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

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void operator=(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};

struct hkMatrix4
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_kColumn3;
    void FUN_00de8da0(const hkMatrix4& a, const hkMatrix4& b);
    void FUN_00de8e50(const hkMatrix4& b);
    void operator=(const hkMatrix4& o)
    {
        m_kColumn0 = o.m_kColumn0;
        m_kColumn1 = o.m_kColumn1;
        m_kColumn2 = o.m_kColumn2;
        m_kColumn3 = o.m_kColumn3;
    }
};

struct CB20B0_Class
{
    void FUN_00cb20b0(void* src);
};
struct Matrix44_shell
{
    float m_data[16];
    void TESForm_LoadForm(CB20B0_Class* dst);
};
// @fnv 0x00de9130
// pdb: TESForm::LoadForm | TESForm.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap) + skyrim(call_gap), high
void Matrix44_shell::TESForm_LoadForm(CB20B0_Class* dst)
{
    dst->FUN_00cb20b0(this);
}

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

struct Row
{
    __m128 v;
    void operator+=(const Row& o)
    {
        __m128 t = o.v;
        v = _mm_add_ps(t, v);
    }
};

__declspec(align(16)) struct S00de9270_Vec
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};

extern "C" __m128 _mm_sub_ps(__m128, __m128);

extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

extern "C"
{
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

struct Matrix4Q
{
    hkVector4 row0;
    hkVector4 row1;
    hkVector4 row2;
    hkVector4 row3;

    Matrix4Q(const Matrix4Q& value)
    {
        *(__m128*)&row0 = *(const __m128*)&value.row0;
        *(__m128*)&row1 = *(const __m128*)&value.row1;
        *(__m128*)&row2 = *(const __m128*)&value.row2;
        *(__m128*)&row3 = *(const __m128*)&value.row3;
    }

    __declspec(noinline) void __fastcall SwapFields(hkMatrix4* context);
};

extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_cmple_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
}
