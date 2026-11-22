#include "f3_common.h"
// src/havok/common/base/math/matrix/hkmatrix3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CD4AF0Bool
{
    char m_cBooleanValue;

    CD4AF0Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S_00cd4b60
{
    float m[3][4];
    void FUN_00cd4b60();
};
static inline void S_00cd4b60_Swap(float& a, float& b)
{
    float t = a;
    a = b;
    b = t;
}
// @fnv 0x00cd4b60
// pdb: hkMatrix3::transpose | hkMatrix3.obj | fnv360_0822_retail, objrun, low, conflict (bridge: hkMatrix3::sub)
void S_00cd4b60::FUN_00cd4b60()
{
    S_00cd4b60_Swap(m[1][0], m[0][1]);
    S_00cd4b60_Swap(m[2][0], m[0][2]);
    S_00cd4b60_Swap(m[2][1], m[1][2]);
}

struct S_00cd55a0
{
    void FUN_00cd5050();
};
// @fnv 0x00cd55a0
void FUN_00cd55a0(S_00cd55a0* p)
{
    p->FUN_00cd5050();
}

struct CD4BA0Matrix3
{
    float m_kColumn0[4];
    float m_kColumn1[4];
    float m_kColumn2[4];

    void Transpose(const CD4BA0Matrix3& s);
};

// Copies the transpose of s into this matrix: diagonal entries copied directly, off-diagonal entries swapped, and the fourth column zeroed.
// @fnv 0x00cd4ba0
// pdb: hkMatrix3::setTranspose | hkMatrix3.obj | fnv360_0822_retail, call_seq, high
// pdb params: s
void CD4BA0Matrix3::Transpose(const CD4BA0Matrix3& s)
{
    m_kColumn0[0] = s.m_kColumn0[0];
    m_kColumn1[1] = s.m_kColumn1[1];
    m_kColumn2[2] = s.m_kColumn2[2];
    m_kColumn2[3] = m_kColumn1[3] = m_kColumn0[3] = 0.0f;
    m_kColumn0[1] = s.m_kColumn1[0];
    m_kColumn1[0] = s.m_kColumn0[1];
    m_kColumn0[2] = s.m_kColumn2[0];
    m_kColumn2[0] = s.m_kColumn0[2];
    m_kColumn1[2] = s.m_kColumn2[1];
    m_kColumn2[1] = s.m_kColumn1[2];
}

struct Matrix3x4
{
    float m[3][4];
};
class CMatrixOps
{
  public:
    bool FUN_00cd4e90(struct S_91db00* arInfo);

  private:
    Matrix3x4 m_mat;
    unsigned char* FUN_00cd4e00(unsigned char* out, const Matrix3x4* temp, float epsilon);
};
// @f3 0x0091db00 (community match, verified in this file)
class CMatrixOpsBridge
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual bool v47(void* p);
    void FUN_0091d450(const float* pB, const float* pA, float f);
};

// The capsule's construction info: the radius and the two end points.
struct S_91db00
{
    int unk00;
    float m_04;
    int unk08;
    int unk0C;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
};
// pdb: bhkCapsuleShape::Init | bhkCapsuleShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: arInfo
bool CMatrixOps::FUN_00cd4e90(S_91db00* p)
{
    if (p != 0)
    {
        __declspec(align(16)) float a[4];
        __declspec(align(16)) float b[4];
        a[0] = p->m_20;
        a[1] = p->m_24;
        a[2] = p->m_28;
        a[3] = p->m_2c;
        b[0] = p->m_10;
        b[1] = p->m_14;
        b[2] = p->m_18;
        b[3] = p->m_1c;
        reinterpret_cast<CMatrixOpsBridge*>(this)->FUN_0091d450(b, a, p->m_04);
    }
    return reinterpret_cast<CMatrixOpsBridge*>(this)->v47(p);
}


struct CdOwner_cls;

struct CdPairOut_cls
{
    unsigned int m_00;
    unsigned int m_04;
    void FUN_00cd5610(CdOwner_cls* owner, unsigned int a1);
};

__declspec(align(16)) struct CdBlob_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
};

struct FUN_00cd5880_cls
{
    unsigned int unk00;
    unsigned int unk04;
    void FUN_00cd55b0(unsigned int a1, CdPairOut_cls* out);
    void FUN_00cd5880(unsigned int a1);
};

struct CdOwner_cls
{
    unsigned int unk00;
    unsigned int unk04;
};

// @fnv 0x00cd5880
// pdb: hkMatrix3::changeBasis | hkMatrix3.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: r
void FUN_00cd5880_cls::FUN_00cd5880(unsigned int a1)
{
    CdBlob_cls blob;
    ((CdPairOut_cls*)&blob.m_00)->FUN_00cd5610((CdOwner_cls*)this, a1);
    this->FUN_00cd55b0(a1, (CdPairOut_cls*)&blob.m_00);
}

#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
#endif

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_unpacklo_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_movelh_ps(__m128 a, __m128 b);
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_movehl_ps(__m128 a, __m128 b);
#endif

class hkMatrix3CD4B;

struct hkVector4CD4B
{
    __m128 m_vComponents;

    hkVector4CD4B()
    {}
    hkVector4CD4B(const hkVector4CD4B& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4CD4B& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void _setRotatedDir(const hkMatrix3CD4B& r, const hkVector4CD4B& b);
};

class hkMatrix3CD4B
{
  public:
    void FUN_00cd4bf0(const hkMatrix3CD4B& kA, const hkMatrix3CD4B& kB);

    hkVector4CD4B& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVector4CD4B& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    void transpose()
    {
        __m128 tmp = _mm_unpacklo_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents),
                                     m_kColumn2.m_vComponents, 0xe4);
        m_kColumn0.m_vComponents = _mm_movelh_ps(tmp, m_kColumn2.m_vComponents);
        tmp = _mm_movehl_ps(m_kColumn0.m_vComponents, tmp);
        m_kColumn1.m_vComponents = _mm_shuffle_ps(tmp, m_kColumn2.m_vComponents, 0xd4);
        m_kColumn2.m_vComponents = ctmp;
    }

    hkVector4CD4B m_kColumn0;
    hkVector4CD4B m_kColumn1;
    hkVector4CD4B m_kColumn2;
};

#include <math.h>
struct JacobiRot
{
    float c;
    float s;
    int q;
    int p;
};

struct RotRef
{
    JacobiRot* p;
    JacobiRot* operator->() const
    {
        return p;
    }
};
struct Mat34
{
    float m[3][4];
};

volatile int g_p5270;
volatile int g_q5270;
Mat34 g_m5270;
JacobiRot g_r5270;

// Computes the Euclidean norm of the 3x3 block formed by the first three entries of each row.
// @f3 0x00bbd320 (community match, verified in this file)
#include <math.h>

struct VectorNormBBD320
{
    float elements[5];
    int count;

    float FUN_00bbd320() const;
};

// pdb: CIdvBezierSpline::CIdvBezierSpline | IdvSpline.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: cRight
float VectorNormBBD320::FUN_00bbd320() const
{
    float sum = 0.0f;
    for (int i = 0; i < count; ++i)
        sum += elements[i] * elements[i];
    return sqrtf(sum);
}


struct S_00cd53a0_Matrix3
{
    float m_col[3][4];
    float FUN_00cd53a0();
};

namespace cd5400 {
struct Vec4
{
    float x, y, z, w;
};
struct Mat3
{
    Vec4 col[3];
    float& operator()(int r, int c)
    {
        return (&col[c].x)[r];
    }
};
}

// Finds the element with the largest absolute value in the upper triangle of m and stores its row and column indices.
// @f3 0x007abac0 (community match, verified in this file)
#include <math.h>

namespace w3_79a8e0 {
struct Actor {
    int unk00;
};
struct Ctl {
    int unk00;
    int unk04;
    int unk08;
    Actor* unk0C;
    Actor* unk10;
    Actor* unk14;
    Actor* unk18;
    Actor* unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    Actor* FUN_007abac0();
};
// pdb: CombatState::GetBestCombatWeapon | CombatState.obj | fnv360_0822_retail, call_gap, low
Actor* Ctl::FUN_007abac0()
{
    float best = 0.0f;
    Actor* sel = 0;
    float v = unk38;
    if (v > best) { sel = unk0C; best = v; }
    v = unk3C;
    if (v > best) { sel = unk10; best = v; }
    v = unk40;
    if (v > best) { sel = unk14; best = v; }
    v = unk44;
    if (v > best) { sel = unk18; best = v; }
    v = unk48;
    if (v > best) { sel = unk1C; best = v; }
    if (unk4C > best)
        return 0;
    return sel;
}
}


struct VProduct
{
    __m128 q;
    VProduct()
    {}
    VProduct(const VProduct& a) : q(a.q)
    {}
    void operator=(const VProduct& a)
    {
        q = a.q;
    }
    void product(const VProduct& a, const VProduct& b)
    {
        q = _mm_mul_ps(a.q, b.q);
    }
    void accum(const VProduct& a, const VProduct& b)
    {
        q = _mm_add_ps(q, _mm_mul_ps(a.q, b.q));
    }
    template <int lane> void broadcast(const VProduct& a)
    {
        q = _mm_shuffle_ps(a.q, a.q, lane);
    }
};
struct MProduct
{
    VProduct columns[3];
    void FUN_00cd55b0(const MProduct& a, const MProduct& b);
};
// Computes the matrix product of a and b, storing the result in columns.
// @fnv 0x00cd55b0
void MProduct::FUN_00cd55b0(const MProduct& aLeft, const MProduct& aRight)
{
    MProduct m = aLeft;
    for (int i = 2; i >= 0; --i)
    {
        const VProduct& v = aRight.columns[i];
        VProduct x, y, z;
        x.broadcast<0>(v);
        y.broadcast<85>(v);
        z.broadcast<170>(v);
        VProduct r;
        r.product(x, m.columns[0]);
        r.accum(y, m.columns[1]);
        r.accum(z, m.columns[2]);
        columns[i] = r;
    }
}

extern "C" __m128 _mm_setzero_ps(void);
extern "C" void _mm_store_ps(float* p, __m128 a);

extern "C" __m128 _mm_setr_ps(float, float, float, float);

struct S00cd4cc0_V
{
    __m128 q;
    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        q = _mm_setr_ps(a, b, c, d);
    }
};

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" void _mm_store_ss(float* p, __m128 a);

typedef __m128 VectorComponentValue;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }

    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    __forceinline void setMul4(VectorComponentValue r, const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
    }

    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};

struct hkMatrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;

    __forceinline hkVector4& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    __forceinline const hkVector4& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }

    float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }

    void transpose()
    {
        float h1 = (*this)(0, 1);
        (*this)(0, 1) = (*this)(1, 0);
        (*this)(1, 0) = h1;
        float h2 = (*this)(0, 2);
        (*this)(0, 2) = (*this)(2, 0);
        (*this)(2, 0) = h2;
        float h3 = (*this)(1, 2);
        (*this)(1, 2) = (*this)(2, 1);
        (*this)(2, 1) = h3;
    }

    int FUN_00cd4f10(float epsilon);
};

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" void _mm_store_ss(float* p, __m128 a);

extern double DAT_010cb418;
extern float DAT_010cb414;

struct InvScale
{
    __m128 q;
    InvScale(float f)
    {
        q = _mm_load_ss(&f);
        q = _mm_shuffle_ps(q, q, 0);
    }
    __m128 get() const
    {
        return q;
    }
};
struct hkVecInv
{
    __m128 m_vComponents;
    void setCross(const hkVecInv& v1, const hkVecInv& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    void scale(const InvScale& s, const hkVecInv& a)
    {
        m_vComponents = _mm_mul_ps(s.get(), a.m_vComponents);
    }
    float dot3(const hkVecInv& a) const
    {
        __m128 x = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(x, x, 0xaa), _mm_add_ss(_mm_shuffle_ps(x, x, 0x55), x));
        float r;
        _mm_store_ss(&r, s);
        return r;
    }
};

struct hkMatInv
{
    hkVecInv m_kColumn0;
    hkVecInv m_kColumn1;
    hkVecInv m_kColumn2;
    hkVecInv& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
};

// Computes three column cross products, substitutes a value when the determinant is below a threshold, then scales the columns by its reciprocal.
// @fnv 0x00cd5050
void S_00cd55a0::FUN_00cd5050()
{
    hkMatInv* m = (hkMatInv*)this;
    hkVecInv r0;
    r0.setCross(m->getColumn(1), m->getColumn(2));
    hkVecInv r1;
    r1.setCross(m->getColumn(2), m->getColumn(0));
    hkVecInv r2;
    r2.setCross(m->getColumn(0), m->getColumn(1));
    float det = m->getColumn(0).dot3(r0);
    if (det < DAT_010cb418)
        det = DAT_010cb414;
    float fInvDet = 1.0f / det;
    InvScale d(fInvDet);
    m->getColumn(0).scale(d, r0);
    m->getColumn(1).scale(d, r1);
    m->getColumn(2).scale(d, r2);
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);
struct DiagVec
{
    union
    {
        __m128 q;
        float f[4];
    };
    DiagVec()
    {}
    DiagVec(const DiagVec& v)
    {
        q = v.q;
    }
    void operator=(const DiagVec& v)
    {
        q = v.q;
    }
};
class DiagMat
{
  public:
    DiagVec c0, c1, c2;
    DiagMat()
    {}
    DiagMat(const DiagMat& v)
    {
        c0 = v.c0;
        c1 = v.c1;
        c2 = v.c2;
    }
    int FUN_00cd56c0(DiagMat& vectors, DiagVec& values, int maxIter, float epsilon) const;
    void FUN_00cd5680(const DiagMat& other);
    void FUN_00cd55b0(const DiagMat& a, const DiagMat& b);
    void FUN_00cd4b60();
    float offnorm()
    {
        return ((S_00cd53a0_Matrix3*)this)->FUN_00cd53a0();
    }
    float& at(int row, int col)
    {
        return (&c0)[col].f[row];
    }
    void identity()
    {
        c0.q = _mm_setzero_ps();
        c1.q = _mm_setzero_ps();
        c2.q = _mm_setzero_ps();
        at(0, 0) = 1.0f;
        at(1, 1) = 1.0f;
        at(2, 2) = 1.0f;
    }
};

extern "C" __declspec(align(16)) const __m128 g_signClear;

struct TransposeReceiver : CD4BA0Matrix3
{
    void Transpose(const CD4BA0Matrix3& source);
};
__declspec(noinline) void TransposeReceiver::Transpose(const CD4BA0Matrix3& source)
{
    m_kColumn0[0] = source.m_kColumn0[0];
    m_kColumn1[1] = source.m_kColumn1[1];
    m_kColumn2[2] = source.m_kColumn2[2];
    m_kColumn0[3] = 0.0f;
    m_kColumn1[3] = 0.0f;
    m_kColumn2[3] = 0.0f;
    m_kColumn0[1] = source.m_kColumn1[0];
    m_kColumn1[0] = source.m_kColumn0[1];
    m_kColumn0[2] = source.m_kColumn2[0];
    m_kColumn2[0] = source.m_kColumn0[2];
    m_kColumn1[2] = source.m_kColumn2[1];
    m_kColumn2[1] = source.m_kColumn1[2];
}
struct MatrixProduct
{
    hkVector4CD4B m_kColumn0, m_kColumn1, m_kColumn2;
    hkVector4CD4B& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    void FUN_00cd5610(const hkMatrix3CD4B& a, const CD4BA0Matrix3& b);
};
// Multiplies a by the transpose of b and stores the result in this object's columns.
// @fnv 0x00cd5610
void MatrixProduct::FUN_00cd5610(const hkMatrix3CD4B& apLeft, const CD4BA0Matrix3& apRight)
{
    hkMatrix3CD4B t;
    reinterpret_cast<TransposeReceiver&>(t).Transpose(apRight);
    hkMatrix3CD4B aaLeft = apLeft;
    for (int i = 2; i >= 0; i--)
    {
        const hkVector4CD4B& src = t.getColumn(i);
        __m128 vSrc = src.m_vComponents;
        __m128 b0 = _mm_shuffle_ps(src.m_vComponents, src.m_vComponents, 0x00);
        __m128 r0 = _mm_mul_ps(aaLeft.m_kColumn0.m_vComponents, b0);
        __m128 b1 = _mm_shuffle_ps(vSrc, vSrc, 0x55);
        __m128 r1 = _mm_mul_ps(aaLeft.m_kColumn1.m_vComponents, b1);
        __m128 b2 = _mm_shuffle_ps(src.m_vComponents, src.m_vComponents, 0xaa);
        __m128 r2 = _mm_mul_ps(aaLeft.m_kColumn2.m_vComponents, b2);
        getColumn(i).m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
    }
}

extern "C" __m128 _mm_load_ps(float const* p);

struct __declspec(align(16)) FUN_00cd5680_tmp
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
};

extern "C" __m128 _mm_load_ps(const float* p);

extern "C" __m128 _mm_load_ps(const float* p);

// out[i] = m * in[i] for the three columns of a 3x4 SSE matrix (columns processed last to first).
// @fnv 0x00cd5530
void __cdecl FUN_00cd5530(float* out, const float* apMatrix, const float* in)
{
    __m128 r0 = _mm_load_ps(apMatrix);
    __m128 r1 = _mm_load_ps(apMatrix + 4);
    __m128 r2 = _mm_load_ps(apMatrix + 8);
    int i = 2;
    for (; i >= 0; --i)
    {
        const float* col = in + i * 4;
        __m128 v = _mm_load_ps(col);
        __m128 x = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(col), _mm_load_ps(col), 0), r0);
        __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 85), r1);
        __m128 result = _mm_add_ps(x, y);
        result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(v, v, 170), r2));
        _mm_store_ps(out + i * 4, result);
    }
}

extern const float DAT_0104da4c = 1.1920929e-7f;
extern "C" void FUN_00cd5530(void*, const void*, const void*);
extern "C" void FUN_00cd55a0(void*);

class ChainScalar
{
    __m128 value;

  public:
    ChainScalar(const __m128& v) : value(v)
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
};
class ChainVec
{
    union
    {
        __m128 value;
        float lanes[4];
    };

  public:
    ChainVec()
    {}
    ChainVec(const __m128& q)
    {
        value = q;
    }
    void operator=(const __m128& q)
    {
        value = q;
    }
    void copy(const ChainVec& q)
    {
        value = q.value;
    }
    void set(const __m128& q)
    {
        value = q;
    }
    ChainVec(const ChainVec& v)
    {
        value = v.value;
    }
    void operator=(const ChainVec& v)
    {
        value = v.value;
    }
    operator __m128() const
    {
        return value;
    }
    float& operator()(int i)
    {
        return lanes[i];
    }
    const float& operator()(int i) const
    {
        return lanes[i];
    }
    __forceinline void zero()
    {
        value = _mm_setzero_ps();
    }
    __forceinline void product(const ChainVec& a, const ChainVec& b)
    {
        value = _mm_mul_ps((__m128)a, (__m128)b);
    }
    __forceinline void mul(const ChainVec& a)
    {
        value = _mm_mul_ps(value, a.value);
    }
    __forceinline void add(const ChainVec& a)
    {
        value = _mm_add_ps(value, a.value);
    }
    __forceinline void sub(const ChainVec& a)
    {
        value = _mm_sub_ps(value, a.value);
    }
    __forceinline void splat(const ChainVec& a, int lane)
    {
        value = _mm_shuffle_ps((__m128)a, (__m128)a, 255);
    }
    __forceinline ChainScalar sum() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(value, value, 85), value);
        return _mm_add_ss(_mm_shuffle_ps(value, value, 170), xy);
    }
};
class ChainMat
{
  public:
    ChainVec c0, c1, c2;
    ChainMat()
    {}
    ChainMat(const ChainMat& a)
    {
        c0 = a.c0;
        c1 = a.c1;
        c2 = a.c2;
    }
    void operator=(const ChainMat& a)
    {
        c0 = a.col(0);
        c1 = a.col(1);
        c2 = a.col(2);
    }
    ChainVec& col(int i)
    {
        return (&c0)[i];
    }
    const ChainVec& col(int i) const
    {
        return (&c0)[i];
    }
    float& operator()(int r, int c)
    {
        return col(c)(r);
    }
    const float& operator()(int r, int c) const
    {
        return col(c)(r);
    }
    void zeroCached()
    {
        ChainVec v;
        v.zero();
        ChainVec& copy = v;
        c0 = copy;
        c1 = copy;
        c2 = copy;
    }
    void zero()
    {
        c0.zero();
        c1.zero();
        c2.zero();
    }
    void transpose(const ChainMat& a)
    {
        (*this)(0, 0) = a(0, 0);
        (*this)(1, 1) = a(1, 1);
        (*this)(2, 2) = a(2, 2);
        (*this)(3, 0) = 0.0f;
        (*this)(3, 1) = 0.0f;
        (*this)(3, 2) = 0.0f;
        (*this)(1, 0) = a(0, 1);
        (*this)(0, 1) = a(1, 0);
        (*this)(2, 0) = a(0, 2);
        (*this)(0, 2) = a(2, 0);
        (*this)(2, 1) = a(1, 2);
        (*this)(1, 2) = a(2, 1);
    }
    void product(const ChainMat& a, const ChainMat& b)
    {
        FUN_00cd5530(static_cast<void*>(this), static_cast<const void*>(&a), static_cast<const void*>(&b));
    }
    void sub(const ChainMat& a)
    {
        c0.sub(a.c0);
        c1.sub(a.c1);
        c2.sub(a.c2);
    }
};
struct ChainBody
{
    unsigned type;
    unsigned deactivation;
    float gravity;
    ChainVec linearVelocity, angularVelocity, mass;
};

struct ProbeJac
{
    ChainVec linear;
    ChainVec angular0;
    ChainVec angular1;
    __forceinline float paired(const ChainBody& a, const ChainBody& b, const ProbeJac& q) const;
    __forceinline float pairedCore(const ChainBody& a, const ChainBody& b, const ProbeJac& q) const;
    __forceinline float shared(const ChainBody& a, const ProbeJac& q) const;
};

template <class T> __forceinline const T* offsetValue(const T* p, unsigned n)
{
    return reinterpret_cast<const T*>(reinterpret_cast<const char*>(p) + n);
}
struct ProbeOffset
{
    unsigned offset;
    const ChainBody& body(const ChainBody* p)
    {
        return *offsetValue(p, offset);
    }
};
struct ProbeRow
{
    ChainMat lower, diag, upper;
};
// Fills ProbeRow output with lower, diag, and upper matrices by computing paired and shared Jacobian terms over ChainBody offsets.
// @fnv 0x00dd0660
volatile int probe_count;
volatile float probe_cfm;
ProbeJac* volatile probe_jac;
ProbeOffset* volatile probe_offsets;
const ChainBody* volatile probe_bodies;
ProbeRow* volatile probe_rows;
