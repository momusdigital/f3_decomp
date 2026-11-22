#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkppointtopathconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtopath/hkppointtopathconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPointToPathConstraintData.h"

// @fnv 0x00dee720
// pdb: hkpPointToPathConstraintData::getConstraintInfo | hkpPointToPathConstraintData.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: info
void __stdcall FUN_00dee720(int aiUnused, void* apData)
{
    *(int*)((char*)apData + 4) = 7;
    *(int*)apData = 0x3c;
}

struct FUN_00dee7f0_class
{
    void __thiscall FUN_00dee7f0(void* a);
};

// Fills the struct at a with a pointer to this+0xc and constant fields 0, 0x180, 7, 8, 0xc.
// @fnv 0x00dee7f0
// pdb: hkpPointToPathConstraintData::getConstraintInfo | hkpPointToPathConstraintData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: info
void __thiscall FUN_00dee7f0_class::FUN_00dee7f0(void* a)
{
    *(int*)((char*)a + 0x10) = (int)((char*)this + 0xc);
    *(int*)((char*)a + 0x14) = 0xc;
    *(int*)((char*)a + 0x0) = 0;
    *(int*)((char*)a + 0x4) = 0x180;
    *(int*)((char*)a + 0x8) = 7;
    *(int*)((char*)a + 0xc) = 8;
}

// @fnv 0x00dee740
// pdb: hkpPointToPathConstraintData::getType | hkpPointToPathConstraintData.obj | fnv360_0721_beta, objrun_open, low
int __cdecl FUN_00dee740()
{
    return 3;
}

struct FUN_00c7f640_Class
{
    void __thiscall FUN_00c7f640(unsigned int arg, void* position);
};
class FUN_00dee820_Class
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int m_60;
    void hkpPointToPathConstraintData_calcPivot(unsigned int a, FUN_00c7f640_Class* owner);
};
// @fnv 0x00dee820
// pdb: hkpPointToPathConstraintData::calcPivot | hkpPointToPathConstraintData.obj | fnv360_0822_retail, call_gap + bridge(call_seq|call_gap) + skyrim(caller_sim), high
void FUN_00dee820_Class::hkpPointToPathConstraintData_calcPivot(unsigned int uiValue, FUN_00c7f640_Class* owner)
{
    owner->FUN_00c7f640(uiValue, &m_60);
}

struct hkBoolDEE8
{
    char m_cBooleanValue;
    hkBoolDEE8(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

class hkObjectDEE8
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_18;
    int unk1c;
    char m_20;

    hkBoolDEE8 FUN_00dee840() const;
};

// Returns true when m_18 is non-null and m_20 is set.
// @fnv 0x00dee840
// pdb: hkpPointToPathConstraintData::isValid | hkpPointToPathConstraintData.obj | fnv360_0822_retail, objrun_open, low
hkBoolDEE8 hkObjectDEE8::FUN_00dee840() const
{
    return m_18 != 0 && m_20;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4DEE7
{
    __m128 m_vComponents;

    hkVector4DEE7()
    {}
    hkVector4DEE7(const hkVector4DEE7& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4DEE7& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct hkMatrix3DEE7
{
    hkVector4DEE7 m_kColumn0;
    hkVector4DEE7 m_kColumn1;
    hkVector4DEE7 m_kColumn2;

    void setIdentity()
    {
        hkVector4DEE7 kZero;
        kZero.setZero4();
        m_kColumn0 = kZero;
        m_kColumn1 = kZero;
        m_kColumn2 = kZero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransformDEE7
{
    hkMatrix3DEE7 m_rotation;
    hkVector4DEE7 m_vTranslation;

    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

class hkBaseObjectDEE7
{
  public:
    virtual ~hkBaseObjectDEE7() throw();
};

class hkReferencedObjectDEE7 : public hkBaseObjectDEE7
{
  public:
    hkReferencedObjectDEE7() throw() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectDEE7() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpConstraintDataDEE7 : public hkReferencedObjectDEE7
{
  public:
    hkpConstraintDataDEE7() throw() : m_ulUserData(0)
    {}
    virtual ~hkpConstraintDataDEE7() throw();

    unsigned long m_ulUserData;
};

struct hkpConstraintAtomDEE7
{
    hkpConstraintAtomDEE7(unsigned short usType) : m_type(usType)
    {}

    unsigned short m_type;
};

struct hkpBridgeConstraintAtomDEE7 : public hkpConstraintAtomDEE7
{
    hkpBridgeConstraintAtomDEE7() : hkpConstraintAtomDEE7(1)
    {}

    void FUN_00d21ce0(void* pkConstraintData);

    void* m_pBridge;
    void* m_pConstraintData;
};

namespace fnv_00dee870 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

struct Vec_00dee870
{
    __m128 m_vComponents;
    void FUN_00c7f690(const void* m, const void* src);
    __forceinline void setCross(const Vec_00dee870& a, const Vec_00dee870& b)
    {
        __m128 t1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9);
        __m128 t2 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9);
        __m128 t3 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2);
        __m128 t0 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2);
        m_vComponents = _mm_sub_ps(_mm_mul_ps(t1, t0), _mm_mul_ps(t3, t2));
    }
};

struct Mat_00dee870
{
    Vec_00dee870 c0;
    Vec_00dee870 c1;
    Vec_00dee870 c2;
    Vec_00dee870 c3;
    void FUN_00cb2240(const void* a, const void* b);
    void FUN_00cb22f0(const void* a, const void* b);
    __forceinline void copyFrom(const Mat_00dee870& o)
    {
        c0.m_vComponents = o.c0.m_vComponents;
        c1.m_vComponents = o.c1.m_vComponents;
        c2.m_vComponents = o.c2.m_vComponents;
        c3.m_vComponents = o.c3.m_vComponents;
    }
};

extern void __fastcall FUN_00c90510(void* a);
extern void __fastcall FUN_00c905b0(void* a);

}  // namespace fnv_00dee870

namespace fnv_00deea00 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

namespace hkDEEA {
struct hkVector4
{
    __m128 m_vComponents;

    hkVector4()
    {}
    hkVector4(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct hkMatrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;

    void setIdentity()
    {
        hkVector4 kZero;
        kZero.setZero4();
        m_kColumn0 = kZero;
        m_kColumn1 = kZero;
        m_kColumn2 = kZero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransform
{
    hkMatrix3 m_rotation;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
    void setTranslation(const hkVector4& v)
    {
        m_vTranslation = v;
    }
};

class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw();
};

class hkReferencedObject : public hkBaseObject
{
  public:
    void FUN_00c90510() throw();
    void FUN_00c905b0() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpParametricCurve : public hkReferencedObject
{
};

struct hkpSetLocalTransformsConstraintAtom
{
    unsigned short m_type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0C;
    hkTransform m_kBodyALocalFrame;
    hkTransform m_kBodyBLocalFrame;
};

struct hkpPointToPathAtoms
{
    hkpSetLocalTransformsConstraintAtom m_kTransforms;
};

class hkpConstraintData : public hkReferencedObject
{
  public:
    unsigned long m_ulUserData;
};

class hkpPointToPathConstraintData : public hkpConstraintData
{
  public:
    void FUN_00deea00(const hkVector4& kPivotA, const hkVector4& kPivotB, hkpParametricCurve* pkPath);

    unsigned int unk0C, unk10, unk14;
    hkpParametricCurve* m_path;
    unsigned int unk1C;
    hkpPointToPathAtoms m_kBridgeAtoms;
};

}
}  // namespace fnv_00deea00

#include <math.h>
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
}

struct TransformQ;

struct VectorQ
{
    __m128 m_vComponents;

    __forceinline void operator=(const VectorQ& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }

    void FUN_00c7f690(const TransformQ& t, const VectorQ& v);
    void FUN_00c7f640(const TransformQ& t, const VectorQ& v);
    void FUN_00c7f700(const TransformQ& t, const VectorQ& v);
};

struct TransformQ
{
    VectorQ m_kColumn0;
    VectorQ m_kColumn1;
    VectorQ m_kColumn2;
    VectorQ m_vTranslation;

    void FUN_00cb2240(const hkTransform& a, const hkTransform& b);
};

class hkBoolC
{
  public:
    char m_cBooleanValue;
    hkBoolC(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkpParametricCurve
{
  public:
    virtual ~hkpParametricCurve();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual hkReal FindNearestPoint(hkReal t, const VectorQ& point, VectorQ& nearestPointOut);
    virtual void GetTangentAt(hkReal t, VectorQ& tangentOut);
    virtual hkReal GetStreamStart();
    virtual hkReal GetStreamEnd();
    virtual hkReal GetCurvature(hkReal t);
    virtual void GetBinormal(hkReal t, VectorQ& binormalOut);
    virtual hkBoolC IsClosedCurve();
};

typedef hkReal(__thiscall* CurveLengthCall)(hkpParametricCurve*, hkReal);

static __forceinline void hkSetCross(VectorQ& out, const VectorQ& v0, const VectorQ& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}
