#include "f3_common.h"
// src/havok/physics/collide/shape/convex/box/hkpboxshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/box/hkpboxshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBoxShape.h"

// @fnv 0x00c9db70
// pdb: CombatProcedureActivateObject::GetType | CombatProcedureActivateObject.obj | fnv360_0822_retail, vtable, medium
int __cdecl FUN_00c9db70()
{
    return 8;
}

// Returns the smaller of the two float arguments.
// @fnv 0x00c9e0f0
// pdb: BSMIN | ContainerItemExtra.obj | fnv360_0822_debug, call_gap, low, conflict (skyrim: hkMath::min2<float>)
// pdb params: fA, fB
float __cdecl FUN_00c9e0f0(float a, float b)
{
    return a < b ? a : b;
}

extern "C" void* DAT_0102e388;

struct FUN_00c9db80_class
{
    void __thiscall FUN_00c9db80();
};

// @fnv 0x00c9db80
void __thiscall FUN_00c9db80_class::FUN_00c9db80()
{
    *reinterpret_cast<void**>(this) = &DAT_0102e388;
}

struct MemoryManager
{
    virtual ~MemoryManager() {}
    virtual void unused() {}
    virtual void Free(void* object, unsigned short size) = 0;
};

// FUN_00c9e1a0: __stdcall stub returning constant 0x30 (two unused stack params).
// @fnv 0x00c9e1a0
// pdb: hkpBoxShape::calcSizeForSpu | hkpBoxShape.obj | fnv360_0721_beta, objrun_sim, medium
// pdb params: input, spuBufferSizeLeft
int __stdcall FUN_00c9e1a0(int a1, int a2)
{
    return 0x30;
}

struct hkAabb;

void __cdecl ComputeAabbFromTransform(const hkTransform& transform, const hkVector4& halfExtents, hkReal tolerance, hkAabb& out);

struct FUN_00c9dc10_class : public hkpBoxShape
{
    void __thiscall GetAabb(const hkTransform& transform, hkReal tolerance, hkAabb& out) const;
};

// Computes the shape's AABB by calling ComputeAabbFromTransform with the transform, the shape's half extents and tolerance added to a stored value.
// @fnv 0x00c9dc10
// pdb: hkpBoxShape::getAabbImpl | hkpBoxShape.obj | tesv_win, objrun, medium
void __thiscall FUN_00c9dc10_class::GetAabb(const hkTransform& transform, hkReal tolerance, hkAabb& out) const
{
    ComputeAabbFromTransform(transform, m_vHalfExtents, m_fSphereRadius + tolerance, out);
}

struct VectorExtents { float x, y, z, w; };

struct CenteredPointBounds {
    void* m_ppVirtualMethodTable;
    unsigned short m_usAllocationSize;
    unsigned short m_sReferenceCount;
    int m_ulUserData;
    int m_iType;
    float m_fSphereRadius;
    float m_localCenterX;
    float m_localCenterY;
    float m_localCenterZ;
    VectorExtents m_vHalfExtents;

    CenteredPointBounds* SetExtentsAndRadius(const float* extents, float radius);
};

// @f3 0x00916750 (community match, verified in this file)
extern void* FUN_00e36504;
// pdb: hkpBoxShape::hkpBoxShape | hkpBoxShape.obj | fnv360_0822_retail, call_seq, high
// pdb params: halfExtents, radius
CenteredPointBounds* CenteredPointBounds::SetExtentsAndRadius(const float* extents, float radius)
{
    m_fSphereRadius = radius;
    m_sReferenceCount = 1;
    m_ulUserData = 0;
    m_iType = 5;
    m_ppVirtualMethodTable = &FUN_00e36504;
    m_vHalfExtents = *reinterpret_cast<const VectorExtents*>(extents);

    float smaller = m_vHalfExtents.x < m_vHalfExtents.y ? m_vHalfExtents.x : m_vHalfExtents.y;
    m_vHalfExtents.w = smaller;
    m_vHalfExtents.w = m_vHalfExtents.z < m_vHalfExtents.w ? m_vHalfExtents.z : m_vHalfExtents.w;
    return this;
}


union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" int _mm_movemask_ps(__m128);

extern float DAT_010c44d0[4];

namespace fnv_00c9e120 {
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_set_ps1(float f);

extern const __m128 DAT_01017d10;
extern const __m128 DAT_010c44d0;

struct hkVector4C9E1 {
    __m128 m_vComponents;

    void setBroadcast(const hkVector4C9E1& v, int i);
    void setMul4(const hkVector4C9E1& a, const hkVector4C9E1& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    void setAbs4(const hkVector4C9E1& v) { m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10); }
    void setNeg4(const hkVector4C9E1& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0); }
    void setAdd4(const hkVector4C9E1& a, const hkVector4C9E1& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    void add4(const hkVector4C9E1& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
    hkVector4C9E1() {}
    hkVector4C9E1(const hkVector4C9E1& v) { m_vComponents = v.m_vComponents; }
    void operator=(const hkVector4C9E1& v) { m_vComponents = v.m_vComponents; }
    void SetAllComponents(float f) { m_vComponents = _mm_set_ps1(f); }
};

struct hkTransformC9E1 {
    hkVector4C9E1 m_kColumn0;
    hkVector4C9E1 m_kColumn1;
    hkVector4C9E1 m_kColumn2;
    hkVector4C9E1 m_vTranslation;
};

struct hkAabbC9E1 {
    hkVector4C9E1 m_kMinimumCorner;
    hkVector4C9E1 m_kMaximumCorner;
};

struct hkAabbUtilC9E1 {
    static void ComputeAabbFromTransform(const hkTransformC9E1& kLocalToWorld, const hkVector4C9E1& m_kPoint2, float fExtraRadius, hkAabbC9E1& kAabbOut);
};

// Computes an AABB in world space from a transform, a point, and an extra radius, storing the result in kAabbOut.
// @fnv 0x00c9e120
void hkAabbUtilC9E1::ComputeAabbFromTransform(const hkTransformC9E1& kLocalToWorld, const hkVector4C9E1& m_kPoint2, float fExtraRadius, hkAabbC9E1& kAabbOut)
{
    hkVector4C9E1 kX;
    kX.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(m_kPoint2.m_vComponents, m_kPoint2.m_vComponents, 0x00), kLocalToWorld.m_kColumn0.m_vComponents);
    hkVector4C9E1 kY;
    kY.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(m_kPoint2.m_vComponents, m_kPoint2.m_vComponents, 0x55), kLocalToWorld.m_kColumn1.m_vComponents);
    hkVector4C9E1 kZ;
    kZ.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(m_kPoint2.m_vComponents, m_kPoint2.m_vComponents, 0xaa), kLocalToWorld.m_kColumn2.m_vComponents);
    kX.setAbs4(kX);
    kY.setAbs4(kY);
    kZ.setAbs4(kZ);
    hkVector4C9E1 kExtra;
    kExtra.SetAllComponents(fExtraRadius);
    hkVector4C9E1 kExtent;
    kExtent.setAdd4(kX, kY);
    kZ.add4(kExtra);
    kExtent.add4(kZ);
    hkVector4C9E1 kNeg;
    kNeg.setNeg4(kExtent);
    hkVector4C9E1 kMinPoint;
    kMinPoint.setAdd4(kNeg, kLocalToWorld.m_vTranslation);
    hkVector4C9E1 kMaxPoint;
    kMaxPoint.setAdd4(kLocalToWorld.m_vTranslation, kExtent);
    kAabbOut.m_kMaximumCorner = kMaxPoint;
    kAabbOut.m_kMinimumCorner = kMinPoint;
}
}  // namespace fnv_00c9e120

struct hkpBoxShape_Local : public hkpBoxShape
{
    void __thiscall SetHalfExtents(const hkVector4& halfExtents);
};

// Copies halfExtents into m_vHalfExtents and stores the minimum of x, y, and z into the w component.
// @f3 0x009161e0 (community match, verified in this file)
// pdb: hkpBoxShape::getSupportingVertexImpl | hkpBoxShape.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpBoxShape::setHalfExtents)
// pdb params: direction, supportingVertexOut
void hkpBoxShape_Local::SetHalfExtents(const hkVector4& halfExtents)
{
    m_vHalfExtents.x = halfExtents.x;
    m_vHalfExtents.y = halfExtents.y;
    m_vHalfExtents.z = halfExtents.z;
    m_vHalfExtents.w = halfExtents.w;

    float smaller = m_vHalfExtents.x < m_vHalfExtents.y ? m_vHalfExtents.x : m_vHalfExtents.y;
    m_vHalfExtents.w = smaller;
    m_vHalfExtents.w = m_vHalfExtents.z < m_vHalfExtents.w ? m_vHalfExtents.z : m_vHalfExtents.w;
}


extern "C" __m128 _mm_mul_ps(__m128, __m128);

extern "C"
{
    void _ReadWriteBarrier(void);
    __m128 _mm_set_ps1(float);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_cmple_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct BRMonitorStream
{
    struct CommandTimingEntry
    {
        const char* m_pCommandName;
        hkUint32 m_uiStartTicks;
        hkUint32 m_uiEndTicks;

        void setTime()
        {
            _ReadWriteBarrier();
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_uiStartTicks = ticks;
        }
    };

    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;

    static unsigned long ms_uiThreadLocalStorageIndex;

    static BRMonitorStream& GetMonitorStream() { return *(BRMonitorStream*)TlsGetValue(ms_uiThreadLocalStorageIndex); }
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }


    void timerCommandEarly(const char* name) {
        if (memoryAvailable()) {
            CommandTimingEntry* h=(CommandTimingEntry*)m_kRayEnd;
            h->m_pCommandName=name;
            _ReadWriteBarrier();
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            _ReadWriteBarrier();
            h->m_uiStartTicks=ticks;
            m_kRayEnd=(char*)(h+1);
        }
    }

    void timerCommand(const char* name)
    {
        if (memoryAvailable())
        {
            CommandTimingEntry* h = (CommandTimingEntry*)m_kRayEnd;
            h->m_pCommandName = name;
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

extern const __m128 g_brSignMask;

struct BRVector4
{
    __m128 m_vComponents;

    void operator=(const BRVector4& v) { m_vComponents = v.m_vComponents; }
    hkReal& operator()(int i) { return m_vComponents.m128_f32[i]; }
    const hkReal& operator()(int i) const { return m_vComponents.m128_f32[i]; }
    void SetAllComponents(hkReal r) { m_vComponents = _mm_set_ps1(r); }
    void setAdd4(const BRVector4& a, const BRVector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    void setNeg4(const BRVector4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, g_brSignMask); }
    void setZero4() { m_vComponents = _mm_setzero_ps(); }
    int compareLessThanEqual4(const BRVector4& v) const { return _mm_movemask_ps(_mm_cmple_ps(m_vComponents, v.m_vComponents)); }
};

struct BRBool
{
    char m_cBooleanValue;

    BRBool(bool b) : m_cBooleanValue(b) {}
};

struct BRRayCastOutput
{
    BRVector4 m_vHitNormal;
    hkReal m_fHitFraction;
    hkInt32 m_iExtraInfo;
    int unk18; int unk1c;
    hkUint32 m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    void setKey(hkUint32 key) { m_uiShapeKeys[m_uiShapeKeyIndex] = key; }
};
