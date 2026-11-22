#include "f3_common.h"
// src/havok/physics/utilities/actions/spring/hkpspringaction_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/spring/hkpspringaction.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/spring/hkpspringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/spring/hkpspringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpSpringAction.h"
extern int g_unk01269168;
int* __cdecl FUN_00cf4ef0();
void* __cdecl _fnv_zlib_memset(void* pvDst, int iValue, unsigned int uiNumBytes);
struct hkShape00D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x47];
    hkShape00D4F0()
    {
        m_type = 2;
    }
};
struct hkShape90D4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape90D4F0()
    {
        m_type = 9;
    }
};
struct hkShape9CD4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape9CD4F0()
    {
        m_type = 8;
    }
};
struct hkShapeA8D4F0
{
    unsigned short m_type;
    unsigned short unk02;
    hkShapeA8D4F0()
    {
        m_type = 7;
    }
};
struct hkShapeB0D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x37];
    hkShapeB0D4F0()
    {
        m_type = 4;
    }
};
struct hkShape120D4F0
{
    unsigned short m_type;
    hkShape120D4F0()
    {
        m_type = 12;
    }
};
class FUN_00d4f000
{
  public:
    hkShape00D4F0 m_s00;
    hkShape90D4F0 m_s90;
    hkShape9CD4F0 m_s9C;
    hkShapeA8D4F0 m_sA8;
    hkShapeA8D4F0 m_sAC;
    hkShapeB0D4F0 m_sB0;
    hkShape120D4F0 m_s120;

    FUN_00d4f000() throw();
};
struct FUN_00cf4d80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    float m_fMass;
    float m_fSpringConstant;
    float m_fDamping;
    bool m_bModifierActive;
    bool m_bEnableState;
    FUN_00cf4d80(void* a, void* b, unsigned long c);
};
extern int DAT_010d08f4;
extern float DAT_01013974;
extern float DAT_0101e2bc;
struct FUN_00d4d340 : FUN_00cf4d80
{
    FUN_00d4d340(void* a, void* b, unsigned long c);
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_sqrt_ss(__m128 a);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);
struct hkSimdRealD4D3
{
    __m128 m_vValue;

    hkSimdRealD4D3(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};
struct hkTransformD4D3;
struct hkVector4D4D3
{
    __m128 m_vComponents;

    void FUN_00c7f690(const hkTransformD4D3& kT, const hkVector4D4D3& kV);
    void setSub4(const hkVector4D4D3& a, const hkVector4D4D3& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealD4D3 length3() const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum));
    }
};
struct hkTransformD4D3
{
    hkVector4D4D3 m_rotation[3];
    hkVector4D4D3 m_vTranslation;
};
struct hkpEntityD4D3
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    unsigned int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    hkTransformD4D3 m_kMotionTransform;
};
class hkBaseObjectD4D3
{
  public:
    virtual ~hkBaseObjectD4D3() throw();
};
class hkpStiffSpringWrapperD4D3 : public hkBaseObjectD4D3
{
  public:
    void UpdatePivotsAndRestLength(const hkVector4D4D3& kPivotAW, const hkVector4D4D3& kPivotBW);

    unsigned int unk04, unk08, unk0C, unk10, unk14;
    hkpEntityD4D3* m_pEntityA;
    hkpEntityD4D3* m_pEntityB;
    unsigned int unk20, unk24, unk28, unk2C;
    hkVector4D4D3 m_kPivotInA;
    hkVector4D4D3 m_kPivotInB;
    float m_fSpringRestLength;
};

extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_load_ps1(const float*);
extern const float DAT_01017d00;
struct __declspec(align(16)) SpringVector
{
    __m128 q;
    __m128 get() const
    {
        return q;
    }
    void set(__m128 v)
    {
        q = v;
    }
    void __thiscall FUN_00c7f640(const void* transform, const hkVector4* local);
};
struct SpringMotion
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void apply(float dt, const hkVector4* force, const SpringVector* point);
};
class hkpEntity
{
  public:
    unsigned unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    SpringMotion motion;
    unsigned unkE4, unkE8, unkEC;
    hkTransform transform;
    void __thiscall FUN_00ca0c40(const SpringVector* point, SpringVector* velocity);
    void __thiscall FUN_00c9c1d0();
    void ApplyForceAtPoint(float dt, const hkVector4& force, const SpringVector& point)
    {
        FUN_00c9c1d0();
        motion.apply(dt, &force, &point);
    }
};
struct SpringStep
{
    float unk00, unk04, deltaTime;
};
struct SpringAction : hkpSpringAction
{
    void __thiscall hkpSpringAction_applyAction(const SpringStep& step);
};
static __m128 dot3(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(p, p, 0x55);
    __m128 z = _mm_shuffle_ps(p, p, 0xaa);
    y = _mm_add_ss(y, p);
    z = _mm_add_ss(z, y);
    return z;
}
static float SpringLength3(__m128 v)
{
    float r;
    _mm_store_ss(&r, _mm_sqrt_ss(dot3(v, v)));
    return r;
}
static float SpringDot3(__m128 a, __m128 b)
{
    float r;
    _mm_store_ss(&r, dot3(a, b));
    return r;
}
extern "C" __m128 _mm_set_ss(float);
static __m128 SpringSplat(float v)
{
    __m128 s = _mm_set_ss(v);
    return _mm_shuffle_ps(s, s, 0);
}
extern "C" __m128 _mm_load_ss(const float*);
static __m128 SpringSplatRef(const float& v)
{
    __m128 s = _mm_load_ss(&v);
    return _mm_shuffle_ps(s, s, 0);
}
extern "C" __m128 _mm_set_ps1(float);
static __m128 SpringSplatMem(float v)
{
    __m128 s = _mm_load_ss(&v);
    return _mm_shuffle_ps(s, s, 0);
}
static __m128 broadcast(float v)
{
    return _mm_load_ps1(&v);
}
// @f3 0x009da0c0 (community match, verified in this file)
#include <math.h>

extern const float DAT_00db7df0;

struct __declspec(align(16)) NativeSpringVector {
    float x, y, z, w;
    void hkVector4_setTransformedPos(const hkTransform* transform, const hkVector4* local);

    void SetDifference(const NativeSpringVector& a, const NativeSpringVector& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    float Length3() const
    {
        float squareLength = y * y + x * x + z * z;
        float length = static_cast<float>(sqrt(squareLength));
        return length;
    }
    void Scale(float value)
    {
        x *= value;
        y *= value;
        z *= value;
        w *= value;
    }
    float Dot3(const NativeSpringVector& other) const
    {
        return y * other.y + x * other.x + z * other.z;
    }
};
struct NativeSpringMotion {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Apply(float delta, const hkVector4* force, const NativeSpringVector* point);
};
struct NativeSpringBody {
    char unknown00[0xd0];
    NativeSpringMotion motion;
    char unknownD4[0xc];
    hkTransform transform;

    void FUN_00917120(const NativeSpringVector* point, NativeSpringVector* velocity);
    void FUN_0090b500();
    void ApplyForce(float delta, const hkVector4& force, const NativeSpringVector& point)
    {
        FUN_0090b500();
        motion.Apply(delta, &force, &point);
    }
};

static __forceinline void SetSpringForce(hkVector4& force, const NativeSpringVector& direction, float magnitude)
{
    force.x = direction.x * magnitude;
    force.y = direction.y * magnitude;
    force.z = direction.z * magnitude;
    force.w = direction.w * magnitude;
}

// pdb: hkpSpringAction::applyAction | hkpSpringAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void SpringAction::hkpSpringAction_applyAction(const SpringStep& step)
{
    NativeSpringBody* a = reinterpret_cast<NativeSpringBody*>(m_pEntityA);
    NativeSpringBody* b = reinterpret_cast<NativeSpringBody*>(m_pEntityB);
    NativeSpringVector pointA, pointB, direction, velocityA, velocityB;
    pointA.hkVector4_setTransformedPos(&a->transform, &m_kPositionA);
    pointB.hkVector4_setTransformedPos(&b->transform, &m_kPositionB);
    direction.SetDifference(pointB, pointA);
    float length = direction.Length3();
    if (DAT_00db7df0 > length)
        return;
    direction.Scale(1.0f / length);
    if (!m_bSpringEnabled && length < m_fRestLength)
        return;
    if (!m_bElastic && length > m_fRestLength)
        return;
    a->FUN_00917120(&pointA, &velocityA);
    b->FUN_00917120(&pointB, &velocityB);
    NativeSpringVector velocity;
    velocity.SetDifference(velocityB, velocityA);
    float force = (length - m_fRestLength) * m_fSpringStrength
        + m_fMotorDamping * velocity.Dot3(direction);
    SetSpringForce(m_kLastForce, direction, -force);
    b->ApplyForce(step.deltaTime, m_kLastForce, pointB);
    SetSpringForce(m_kLastForce, direction, force);
    a->ApplyForce(step.deltaTime, m_kLastForce, pointA);
}

