#include "f3_common.h"
// src/havok/common/base/math/matrix/hktransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hktransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Matrix43;
struct Transform
{
    void FUN_00ce5300(Matrix43* out);
};
struct __declspec(align(16)) Matrix43
{
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
    void FUN_00cb2240(Matrix43* a, Matrix43* b);
    void FUN_00cb22c0(Transform* a, Matrix43* b);
};
// @fnv 0x00cb22c0
// pdb: hkTransform::setMul | hkTransform.obj | fnv360_0822_debug, objrun, medium
// pdb params: aTb, bTc
void Matrix43::FUN_00cb22c0(Transform* apTransform, Matrix43* apMatrix)
{
    Matrix43 temp;
    apTransform->FUN_00ce5300(&temp);
    this->FUN_00cb2240(&temp, apMatrix);
}

struct FourFloatVector
{
    float x;
    float y;
    float z;
    float w;
};
struct Matrix44;
struct FUN_00cb21e0_shell
{
    void __thiscall FUN_00cb21e0(const Matrix44* source);
};
struct FUN_00cb2240_shell
{
    void __thiscall FUN_00cb2240(const Matrix44* left, const Matrix44* right);
};
__declspec(align(16)) struct Matrix44
{
    FourFloatVector row0;
    FourFloatVector row1;
    FourFloatVector row2;
    FourFloatVector row3;
    void FUN_00cb2420(const Matrix44* left, const Matrix44* right);
};
// @fnv 0x00cb2420
// pdb: hkTransform::setMul | hkTransform.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkTransform::setMulMulInverse)
// pdb params: aTb, bTc
void Matrix44::FUN_00cb2420(const Matrix44* left, const Matrix44* right)
{
    Matrix44 tempMatrix;
    ((FUN_00cb21e0_shell*)&tempMatrix)->FUN_00cb21e0(right);
    ((FUN_00cb2240_shell*)this)->FUN_00cb2240(left, &tempMatrix);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_unpacklo_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movelh_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movehl_ps(__m128 a, __m128 b);

class hkMatrix3CB22;

struct hkVector4CB22
{
    __m128 m_vComponents;

    hkVector4CB22()
    {}
    hkVector4CB22(const hkVector4CB22& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4CB22& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void _setRotatedDir(const hkMatrix3CB22& r, const hkVector4CB22& b);
    __forceinline void _setRotatedInverseDir(const hkMatrix3CB22& r, const hkVector4CB22& b);
    void setSub4(const hkVector4CB22& a, const hkVector4CB22& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
};

class hkMatrix3CB22
{
  public:
    __forceinline void SetMulInverse(const hkMatrix3CB22& kA, const hkMatrix3CB22& kB)
    {
        hkMatrix3CB22 kATrans;
        kATrans.m_kColumn0 = kA.m_kColumn0;
        kATrans.m_kColumn1 = kA.m_kColumn1;
        kATrans.m_kColumn2 = kA.m_kColumn2;
        kATrans.transpose();
        for (int i = 0; i < 3; i++)
        {
            hkVector4CB22 kCol = kB.getColumn(i);
            getColumn(i)._setRotatedDir(kATrans, kCol);
        }
    }

    hkVector4CB22& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVector4CB22& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    __forceinline void transpose()
    {
        __m128 tmp = _mm_unpacklo_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents),
                                     m_kColumn2.m_vComponents, 0xe4);
        m_kColumn0.m_vComponents = _mm_movelh_ps(tmp, m_kColumn2.m_vComponents);
        tmp = _mm_movehl_ps(m_kColumn0.m_vComponents, tmp);
        m_kColumn1.m_vComponents = _mm_shuffle_ps(tmp, m_kColumn2.m_vComponents, 0xd4);
        m_kColumn2.m_vComponents = ctmp;
    }

    hkVector4CB22 m_kColumn0;
    hkVector4CB22 m_kColumn1;
    hkVector4CB22 m_kColumn2;
};

extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);

extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);

extern __declspec(align(16)) const float g_absMask[4];
extern __declspec(align(16)) const float g_rowMask[4];

extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);

extern const __m128 g_vectorSignMask;

struct S_00cb21e0_Vector4
{
    float x, y, z, w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
};

struct S_00cb21e0_Matrix3
{
    S_00cb21e0_Vector4 m_kColumn0;
    S_00cb21e0_Vector4 m_kColumn1;
    S_00cb21e0_Vector4 m_kColumn2;
    void Transpose(const S_00cb21e0_Matrix3& m);
};

struct S_00cb21e0_Transform
{
    S_00cb21e0_Matrix3 m_rotation;
    S_00cb21e0_Vector4 m_vTranslation;
    void Body(const S_00cb21e0_Transform& t);
};

__forceinline void S_00cb21e0_Transform::Body(const S_00cb21e0_Transform& t)
{
    m_rotation.Transpose(t.m_rotation);
    __declspec(align(16)) S_00cb21e0_Vector4 tr;
    tr.q() = _mm_xor_ps(t.m_vTranslation.q(), g_vectorSignMask);
    __m128 b0 = _mm_shuffle_ps(tr.q(), tr.q(), 0x00);
    __m128 b1 = _mm_shuffle_ps(tr.q(), tr.q(), 0x55);
    __m128 b2 = _mm_shuffle_ps(tr.q(), tr.q(), 0xaa);
    __m128 r0 = _mm_mul_ps(m_rotation.m_kColumn0.q(), b0);
    __m128 r1 = _mm_mul_ps(m_rotation.m_kColumn1.q(), b1);
    __m128 r2 = _mm_mul_ps(m_rotation.m_kColumn2.q(), b2);
    m_vTranslation.q() = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

// @fnv 0x00cb21e0
void FUN_00cb21e0_shell::FUN_00cb21e0(const Matrix44* source)
{
    ((S_00cb21e0_Transform*)this)->Body(*(const S_00cb21e0_Transform*)source);
}

extern "C" __m128 _mm_and_ps(__m128 _A, __m128 _B);
