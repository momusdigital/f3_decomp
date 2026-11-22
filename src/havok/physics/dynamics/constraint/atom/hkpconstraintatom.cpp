#include "f3_common.h"
// src/havok/physics/dynamics/constraint/atom/hkpconstraintatom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/atom/hkpconstraintatom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConstraintAtom.h"

// Walks a linked list from self while the node's first ushort is at least 0x17, OR-ing each node's FUN_00d22090(a, b) result and returning it.
// @f3 0x009a1f20 (community match, verified in this file)
struct ConstraintNode {
    unsigned short type, unk02;
    unsigned int unk04, unk08, unk0c, unk10;
    ConstraintNode* next;
    int FUN_009a1ee0(void* payload);
};
// pdb: hkpModifierConstraintAtom::addAllModifierDataToConstraintInfo | hkpConstraintAtom.obj | tesv_win, call_gap, low
int __cdecl FUN_00d22120(void* first, void* payload, void*) {
    ConstraintNode* node = static_cast<ConstraintNode*>(first);
    int result = 0;
    while (node->type >= 23) {
        result |= node->FUN_009a1ee0(payload);
        node = node->next;
    }
    return result;
}


// @fnv 0x00d21d00
// pdb: hkpMassChangerModifierConstraintAtom::collisionResponseEndCallback | hkpConstraintAtom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: cp, impulseApplied, inA, velA, inB, velB
void __stdcall FUN_00d21d00(int, int, int, int, int, int)
{}

struct FUN_00d21de0_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    FUN_00d21de0_cls* __thiscall FUN_00d21de0(int a);
};

// @f3 0x009a1c00 (community match, verified in this file)
// pdb: hkpSimpleContactConstraintAtom::hkpSimpleContactConstraintAtom | hkpConstraintAtom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: f
FUN_00d21de0_cls* FUN_00d21de0_cls::FUN_00d21de0(int) {
    unk0A = (unsigned char)((unk09 + unk08 + 5) * 4);
    return this;
}


struct ConstraintAtom;
struct ConstraintInfo
{
    int maxSizeOfSchema;
    int sizeOfSchemas;
    int numSolverResults;
    int numSolverElemTemps;
    ConstraintAtom* atoms;
    unsigned int sizeOfAllAtoms;
};
struct ConstraintAtom
{
    unsigned short type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short count;
    ConstraintAtom* next;
    int FUN_00d22030(ConstraintInfo* info);
};
void __cdecl FUN_00d21a60(ConstraintAtom* atom, unsigned int count, ConstraintInfo* result);

// Walks the atom chain while type >= 23, then subtracts the partial solver temps, results and schema size from info unless the atom type is 22 or 1.
// @fnv 0x00d22030
// pdb: hkpIgnoreModifierConstraintAtom::getConstraintInfo | hkpConstraintAtom.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: info
int ConstraintAtom::FUN_00d22030(ConstraintInfo* info)
{
    ConstraintAtom* atom = this;
    unsigned int count = 0;
    while (atom->type >= 23)
    {
        count = atom->count;
        atom = atom->next;
    }
    if (atom->type != 22 && atom->type != 1)
    {
        ConstraintInfo partialInfo;
        FUN_00d21a60(atom, count, &partialInfo);
        info->numSolverElemTemps -= partialInfo.numSolverElemTemps;
        info->numSolverResults -= partialInfo.numSolverResults;
        info->sizeOfSchemas -= partialInfo.sizeOfSchemas;
    }
    return 0;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void mul4(const hkVector4q& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return m_vComponents.m128_f32[i];
    }
};

struct hkSimdRealq
{
    __m128 m_vValue;

    __forceinline hkSimdRealq(const __m128& q)
    {
        m_vValue = q;
    }
};

struct hkMatrix3q
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    __forceinline float& operator()(int r, int c)
    {
        return (&m_kColumn0)[c](r);
    }

    void setTransposeMul(const hkMatrix3q& a, const hkMatrix3q& b);
    void SetProduct(const hkMatrix3q& a, const hkMatrix3q& b);
    void SetInverseProduct(const hkMatrix3q& a, const hkMatrix3q& b);
    void mul(const hkSimdRealq& scale);
};

namespace fnv_00d21f50 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

struct hkSimdRealD21F
{
    __m128 m_vValue;

    hkSimdRealD21F(const __m128& x) : m_vValue(x)
    {}
};

struct hkVector4D21F
{
    __m128 m_vComponents;

    hkSimdRealD21F dot3(const hkVector4D21F& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    void subMul4(const hkSimdRealD21F& s, const hkVector4D21F& a)
    {
        m_vComponents =
            _mm_sub_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), a.m_vComponents));
    }
    void add4(const hkVector4D21F& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};

}  // namespace fnv_00d21f50

extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, int c);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);

struct Vec4
{
    __m128 m_vComponents;

    __forceinline void sub4(const Vec4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setCross(const Vec4& v1, const Vec4& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xC9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xD2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xD2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xC9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};

extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
