#include "f3_common.h"
// src/havok/physics/collide/shape/convex/sphere/hkpsphereshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/sphere/hkpsphereshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSphereShape.h"

// @fnv 0x00cd8050
// pdb: BSSimpleList<bhkLiquidAction *>::GetNext | bhkLiquidAction.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkpHingeConstraintData::getType)
int __cdecl FUN_00cd8050()
{
    return 1;
}

// @fnv 0x00cd87f0
// pdb: hkpSphereShape::calcSizeForSpu | hkpSphereShape.obj | fnv360_0721_beta, objrun_open, low
// pdb params: input, spuBufferSizeLeft
int __stdcall FUN_00cd87f0(int a1, int a2)
{
    return 0x20;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);

#include "havok/hkMonitorStream.h"

void* __cdecl FUN_00cd85c0(void* pvResult, float fValue, int a, int b);

class HostCD81
{
  public:
    int unk00, unk04, unk08, unk0C;
    float m_fValue;
    void* hkpSphereShape_castRayImpl(void* pvResult, int a, int b);
};

// Writes start and end timer commands to the TLS monitor stream around a call to FUN_00cd85c0, then returns pvResult.
// @fnv 0x00cd8190
// pdb: hkpSphereShape::castRayImpl | hkpSphereShape.obj | fnv360_0822_retail, ustr, high
// pdb params: input, results
// pdb: hkpSphereShape::castRayImpl | hkpSphereShape.obj | fnv360_0822_retail, ustr, high (was: RecordTimerCommands)
void* HostCD81::hkpSphereShape_castRayImpl(void* pvResult, int a, int b)
{
    HK_TIMER_BEGIN("rcSphere", HK_NULL);
    FUN_00cd85c0(pvResult, m_fValue, a, b);
    HK_TIMER_END();
    return pvResult;
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_set_ps1(float);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_cmplt_ps(__m128, __m128);
extern "C" __m128 _mm_cmple_ps(__m128, __m128);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_or_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_rcp_ps(__m128);
extern "C" int _mm_movemask_ps(__m128);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
class RayMask
{
    __m128 bits;
    friend class RayVector;

  public:
    enum Component
    {
        X = 1,
        Y = 2,
        Z = 4,
        W = 8
    };
    static const Component components[4];
    __forceinline void intersect(const RayMask& a, const RayMask& b)
    {
        bits = _mm_and_ps(a.bits, b.bits);
    }
    __forceinline int any(Component lane) const
    {
        return _mm_movemask_ps(bits) & lane;
    }
};
const RayMask::Component RayMask::components[4] = {RayMask::X, RayMask::Y, RayMask::Z, RayMask::W};
static const __m128 signVector = {{-0.0f, -0.0f, -0.0f, -0.0f}};
static const __m128 tripleVector = {{3.0f, 3.0f, 3.0f, 3.0f}};
static const __m128 halfVector = {{0.5f, 0.5f, 0.5f, 0.5f}};
static __forceinline __m128 reciprocalVector(__m128 value)
{
    __m128 estimate = _mm_rcp_ps(value);
    return _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, value), estimate));
}
class RayVector
{
    __m128 value;

  public:
    __forceinline RayVector()
    {}
    __forceinline RayVector(const RayVector& other)
    {
        value = other.value;
    }
    __forceinline RayVector(const __m128& other)
    {
        value = other;
    }
    __forceinline void operator=(const RayVector& other)
    {
        value = other.value;
    }
    __forceinline __m128& quad()
    {
        return value;
    }
    __forceinline const __m128& quad() const
    {
        return value;
    }
    __forceinline operator __m128() const
    {
        return value;
    }
    __forceinline float& operator()(int lane)
    {
        return ((float*)&value)[lane];
    }
    __forceinline void splat(float number)
    {
        value = _mm_set_ps1(number);
    }
    __forceinline void zero()
    {
        value = _mm_setzero_ps();
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        value = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void product(const RayVector& a, const RayVector& b)
    {
        value = _mm_mul_ps(a.value, b.value);
    }
    __forceinline void accumulate(const RayVector& a, const RayVector& b)
    {
        value = _mm_add_ps(value, _mm_mul_ps(a.value, b.value));
    }
    __forceinline void difference(const RayVector& a, const RayVector& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void multiply(const RayVector& rhs)
    {
        value = _mm_mul_ps(value, rhs.value);
    }
    __forceinline void add(const RayVector& rhs)
    {
        value = _mm_add_ps(value, rhs.value);
    }
    __forceinline void subtract(const RayVector& rhs)
    {
        value = _mm_sub_ps(value, rhs.value);
    }
    __forceinline void negate(const RayVector& rhs)
    {
        value = _mm_xor_ps(rhs.value, signVector);
    }
    __forceinline void reciprocal(const RayVector& rhs)
    {
        value = reciprocalVector(rhs.value);
    }
    __forceinline void choose(const RayVector& a, const RayVector& b, const RayMask& mask)
    {
        value = _mm_or_ps(_mm_and_ps(mask.bits, b.value), _mm_andnot_ps(mask.bits, a.value));
    }
    __forceinline RayMask greater(const RayVector& rhs) const
    {
        RayMask result;
        result.bits = _mm_cmplt_ps(rhs.value, value);
        return result;
    }
    __forceinline RayMask less(const RayVector& rhs) const
    {
        RayMask result;
        result.bits = _mm_cmplt_ps(value, rhs.value);
        return result;
    }
    __forceinline RayMask atLeast(const RayVector& rhs) const
    {
        RayMask result;
        result.bits = _mm_cmple_ps(rhs.value, value);
        return result;
    }
};
struct RayHitBase
{
    RayVector m_vHitNormal;
    float m_fHitFraction;
    int unk14, unk18, unk1c;
};
struct RayHit : RayHitBase
{
    unsigned m_uiShapeKeys[8];

  private:
    int m_uiShapeKeyIndex;

  public:
    __forceinline void setKey(unsigned key)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = key;
    }
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

extern "C" __m128 _mm_setzero_ps(void);
extern "C" void _mm_store_ps(float*, __m128);

extern "C" __m128 _mm_setzero_ps(void);

struct __declspec(align(16)) CentreVectorCD80
{
    __m128 m_vComponents;

    void zero()
    {
        m_vComponents = _mm_setzero_ps();
    }
};
