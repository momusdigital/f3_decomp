// src/havok/common/internal/convexhull/hkgeometryutility_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/convexhull/hkgeometryutility_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/havok/common/internal/convexhull/hkgeometryutility_gs_nogs_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/internal/convexhull/hkgeometryutility.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/internal/convexhull/hkgeometryutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkgeometryutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void __cdecl InitAndSetB(void* a1, int a2);
struct D5C110Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct D5C110MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D5C110Allocator* m_pStreamAllocator;

    D5C110Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" D5C110MemoryRouter& __cdecl FUN_00c85750();
struct D5C110Vector4
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};
// hkArray<hkVector4> without a destructor (Havok was built without EH): explicit cleanup.
struct D5C110VertexArray
{
    D5C110Vector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    D5C110VertexArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    void ClearAndRelease()
    {
        D5C110Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(D5C110Vector4));
    }
};
struct D5C110StridedVertices
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};
struct D5C110Geometry
{
    int unk00;
    int m_iStridedVertexCount;
    int unk08;
    int unk0C;
    int m_iTriangleCount;
};
void __cdecl ProcessArg(const void* shape, D5C110VertexArray& vertices);
void __cdecl InitAndSetB(const D5C110StridedVertices& vertices, D5C110Geometry& out);
struct D5C110VertexArray;
void __cdecl ProcessArg(const void* shape, D5C110VertexArray& vertices);
#include <math.h>
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setr_ps(float, float, float, float);
struct __declspec(align(16)) S00d5c060_Result
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" void _mm_store_ss(float*, __m128);
struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
#include <math.h>
static __forceinline float RowLen(const float* r)
{
    __m128 v = _mm_load_ps(r);
    __m128 sq = _mm_mul_ps(v, v);
    __m128 a = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 b = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 s = _mm_add_ss(a, sq);
    __m128 t = _mm_add_ss(b, s);
    __m128 len = _mm_sqrt_ss(t);
    float out;
    _mm_store_ss(&out, len);
    return out;
}
static __forceinline float ScalarSqrt(float x)
{
    return sqrt(x);
}
static __forceinline float ScalarAbs(float x)
{
    return fabs(x);
}

static __forceinline int S00d5a6e0_FindCol(const float* sub, int start)
{
    int i;
    for (i = start; i <= 1; i++)
    {
        if (ScalarAbs(sub[i]) < 1e-6f)
            break;
    }
    return i;
}

// @f3 0x009e8c20 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();

hkBool __cdecl FUN_00d5a6e0(float m[3][4], int maxIterations)
{
    float maxLen = 0.0f;
    for (int i = 0; i < 3; i++)
    {
        float sq = m[i][0] * m[i][0] + m[i][1] * m[i][1] + m[i][2] * m[i][2];
        float len = ScalarSqrt(sq);
        if (len > maxLen)
            maxLen = len;
    }
    if (maxLen != 0.0f)
    {
        float* p = &m[2][0];
        int j = 3;
        do
        {
            p[-8] /= maxLen;
            p[-4] /= maxLen;
            *p /= maxLen;
            p++;
        } while (--j);
    }
    float fG, fR, fSin, fCos, fP, fF, fB;
    float afDiag[3];
    float afSubDiag[3];
    if (m[2][0] != 0.0f)
    {
        afDiag[0] = m[0][0];
        afSubDiag[2] = 0.0f;
        float fLen = ScalarSqrt(m[1][0] * m[1][0] + m[2][0] * m[2][0]);
        float v0 = m[1][0] / fLen;
        float v1 = m[2][0] / fLen;
        float q = v1 * (m[2][2] - m[1][1]) + 2.0f * v0 * m[2][1];
        afDiag[1] = m[1][1] + q * v1;
        afDiag[2] = m[2][2] - q * v1;
        afSubDiag[0] = fLen;
        afSubDiag[1] = m[2][1] - v0 * q;
        m[0][0] = 1.0f;
        m[1][0] = 0.0f;
        m[2][0] = 0.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][1] = v0;
        m[2][1] = v1;
        m[1][2] = v1;
        m[2][2] = -v0;
    }
    else
    {
        afDiag[0] = m[0][0];
        afDiag[1] = m[1][1];
        afDiag[2] = m[2][2];
        afSubDiag[0] = m[1][0];
        afSubDiag[1] = m[2][1];
        __m128 zero;
        m[2][3] = m[2][2] = m[2][1] = m[2][0] =
        m[1][3] = m[1][2] = m[1][1] = m[1][0] =
        m[0][3] = m[0][2] = m[0][1] = m[0][0] =
        afSubDiag[2] = zero.m128_f32[0] = 0.0f;
        _ReadWriteBarrier();
        m[0][0] = 1.0f;
        m[1][1] = 1.0f;
        m[2][2] = 1.0f;
    }
    for (int iRow = 0; iRow < 3; iRow++)
    {
        int iIter;
        for (iIter = 0; iIter < maxIterations; iIter++)
        {
            int iCol = S00d5a6e0_FindCol(afSubDiag, iRow);
            if (iCol == iRow)
                break;
            fG = (afDiag[iRow + 1] - afDiag[iRow]) / (2.0f * afSubDiag[iRow]);
            fR = ScalarSqrt((float)((double)(fG * fG) + 1.0));
            if (fG < 0.0f)
                fG = (afDiag[iCol] - afDiag[iRow]) + afSubDiag[iRow] / (fG - fR);
            else
                fG = (afDiag[iCol] - afDiag[iRow]) + afSubDiag[iRow] / (fG + fR);
            fSin = 1.0f;
            fCos = 1.0f;
            fP = 0.0f;
            for (int iM = iCol - 1; iM >= iRow; iM--)
            {
                fF = fSin * afSubDiag[iM];
                fB = fCos * afSubDiag[iM];
                if (ScalarAbs(fF) > ScalarAbs(fG))
                {
                    float ratio = -fG / fF;
                    fSin = (float)(-1.0 / ScalarSqrt((float)((double)(ratio * ratio) + 1.0)));
                    fCos = ratio * fSin;
                    fSin = -fSin;
                    afSubDiag[iM + 1] = fF / fSin;
                }
                else
                {
                    float ratio = -fF / fG;
                    fCos = (float)(-1.0 / ScalarSqrt((float)((double)(ratio * ratio) + 1.0)));
                    fSin = ratio * fCos;
                    fCos = -fCos;
                    afSubDiag[iM + 1] = fG / fCos;
                }
                fG = afDiag[iM + 1] - fP;
                fR = (afDiag[iM] - fG) * fSin + 2.0f * fB * fCos;
                fP = fSin * fR;
                afDiag[iM + 1] = fG + fP;
                fG = fCos * fR - fB;

                for (int j = 0; j < 3; ++j)
                {
                    fR = m[iM + 1][j];
                    float previous = m[iM][j];
                    m[iM + 1][j] = fSin * previous + fCos * fR;
                    m[iM][j] = fCos * m[iM][j] - fSin * fR;
                }
            }
            afDiag[iRow] -= fP;
            afSubDiag[iRow] = fG;
            afSubDiag[iCol] = 0.0f;
        }
        if (iIter == maxIterations)
            return false;
    }
    return true;
}


extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);

class S00d5ae60_SimdReal
{
  public:
    S00d5ae60_SimdReal(const __m128& x) : m_vValue(x)
    {}
    S00d5ae60_SimdReal(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    __m128 m_vValue;
};

class S00d5ae60_Vector4
{
  public:
    inline void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    inline void SetAllComponents(float a)
    {
        m_vComponents = _mm_set_ps1(a);
    }
    inline void setAdd4(const S00d5ae60_Vector4& v0, const S00d5ae60_Vector4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void setSub4(const S00d5ae60_Vector4& v0, const S00d5ae60_Vector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void mul4(const S00d5ae60_SimdReal& s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    inline void setMul4(const S00d5ae60_SimdReal& r, const S00d5ae60_Vector4& v1)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
    }
    inline void addMul4(const S00d5ae60_SimdReal& r, const S00d5ae60_Vector4& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    inline S00d5ae60_SimdReal dot3(const S00d5ae60_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    inline float& operator()(int a)
    {
        return reinterpret_cast<float*>(&m_vComponents)[a];
    }
    inline const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[a];
    }

    __m128 m_vComponents;
};
