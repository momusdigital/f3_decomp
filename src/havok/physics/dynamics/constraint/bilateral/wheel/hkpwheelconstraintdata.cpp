#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpWheelConstraintData.h"

// Writes 6 and 0x30 into a2[1] and a2[0] when a1 is nonzero, otherwise writes zeros to both.
// @fnv 0x00d4e580
// pdb: hkpWheelConstraintData::getRuntimeInfo | hkpWheelConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: wantRuntime, infoOut
void __stdcall FUN_00d4e580(char a1, int* a2)
{
    if (a1)
    {
        a2[1] = 6;
        a2[0] = 0x30;
    }
    else
    {
        a2[1] = 0;
        a2[0] = 0;
    }
}

void* __cdecl FUN_00d21a60(void* a, int b, int c);
struct FUN_00d4e560 : public hkpWheelConstraintData
{
    void* __thiscall PopulateInfo(int ai);
};
// @fnv 0x00d4e560
// pdb: hkpWheelConstraintData::getConstraintInfo | hkpWheelConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: infoOut
void* __thiscall FUN_00d4e560::PopulateInfo(int aiIndex)
{
    return FUN_00d21a60(&m_kBridgeAtoms, 0x124, aiIndex);
}

// @fnv 0x00d4e5b0
// pdb: hkpWheelConstraintData::getType | hkpWheelConstraintData.obj | tesv_win, objrun_sim, low
int __cdecl FUN_00d4e5b0()
{
    return 9;
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00d4e5c0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
}

union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;

    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
};

struct hkVector4Out : public hkVector4
{
    void setRotatedInverseDir(const hkRotation& r, const hkVector4& v);
};

struct hkRotationQ
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
};

struct hkTransformQ
{
    hkRotationQ m_rotation;
    hkVector4q m_vTranslation;
};

struct hkpWheelAtomsQ
{
    char m_suspensionBaseHeader[0x10];
    hkTransformQ m_kBodyALocalFrame;
    hkTransformQ m_kBodyBLocalFrame;
    char m_steeringBaseHeader[0x30];
    hkRotationQ m_kRotationA;
    hkRotationQ m_kRotationB;
    char pad120[0x10];
};

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline void hkSetCross(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

static __forceinline void hkSetRotatedInverseDir(hkVector4q& out, const hkTransform& t, const hkVector4& v)
{
    static_cast<hkVector4Out&>(out.m_vec).setRotatedInverseDir(t.m_rotation, v);
}

}  // namespace fnv_00d4e5c0

namespace fnv_00d4e960 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
}

union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;

    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
};

struct hkVector4Out : public hkVector4
{
    void setRotatedInverseDir(const hkRotation& r, const hkVector4& v);
};

struct hkRotationQ
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    __forceinline hkVector4q& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
};

struct hkTransformQ
{
    hkRotationQ m_rotation;
    hkVector4q m_vTranslation;
};

struct hkpWheelAtomsQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkTransformQ m_kBodyALocalFrame;
    hkTransformQ m_kBodyBLocalFrame;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    hkRotationQ m_kRotationA;
    hkRotationQ m_kRotationB;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
};

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline void hkCalculatePerpendicularVector(const hkVector4q& in, hkVector4q& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    out.m_vComponents = _mm_setzero_ps();
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

static __forceinline hkReal getP(const hkVector4q& v, int i)
{
    const hkReal* p = reinterpret_cast<const hkReal*>(&v) + i;
    return *p;
}
static __forceinline hkReal& refP(hkVector4q& v, int i)
{
    hkReal* p = reinterpret_cast<hkReal*>(&v) + i;
    return *p;
}

static __forceinline void hkSetCross(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

static __forceinline void hkSetRotatedInverseDir(hkVector4q& out, const hkTransform& t, const hkVector4& v)
{
    static_cast<hkVector4Out&>(out.m_vec).setRotatedInverseDir(t.m_rotation, v);
}

static __forceinline void hkSetTransformedInversePos(hkVector4q& out, const hkTransform& t, const hkVector4& p)
{
    hkVector4q s;
    s.m_vComponents = _mm_sub_ps(reinterpret_cast<const __m128&>(p), reinterpret_cast<const __m128&>(t.m_vTranslation));
    hkSetRotatedInverseDir(out, t, s.m_vec);
}

static __forceinline void hkSetCrossC(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    __m128 a = v0.m_vComponents;
    __m128 b = v1.m_vComponents;
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}
static __forceinline void hkSetCrossD(hkVector4q& out, const hkVector4q& v0, const hkVector4q& v1)
{
    hkVector4q t;
    hkSetCross(t, v0, v1);
    out.m_vComponents = t.m_vComponents;
}

}  // namespace fnv_00d4e960

extern int DAT_010d0a64;
struct WheelHeader
{
    int* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags, m_sReferenceCount;
    unsigned int m_ulUserData;
    WheelHeader() : m_sReferenceCount(1), m_ulUserData(0)
    {
        m_ppVirtualMethodTable = &DAT_010d0a64;
    }
};
union Vec4
{
    __m128 simd;
    volatile float component[4];
};
struct FloatMatrix3
{
    Vec4 axis0, axis1, axis2;
    void SetIdentity()
    {
        __m128 zero = _mm_setzero_ps();
        axis0.simd = zero;
        axis1.simd = zero;
        axis2.simd = zero;
        axis0.component[0] = 1.0f;
        axis1.component[1] = 1.0f;
        axis2.component[2] = 1.0f;
    }
};

struct hkBoolRet
{
    char m_cBooleanValue;
    hkBoolRet()
    {}
    hkBoolRet(bool b) : m_cBooleanValue((char)b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DummyTransform
{
};
typedef hkBoolRet (DummyTransform::*MemFn)(float tol);
