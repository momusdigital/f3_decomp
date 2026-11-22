#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpLinearParametricCurve.h"

struct FUN_00e47c20_s : public hkpLinearParametricCurve
{
    double FUN_00e47c20() const;
};

// @fnv 0x00e47c20
// pdb: hkpLinearParametricCurve::getEnd | hkpLinearParametricCurve.obj | fnv360_0822_retail, objrun_open, low
double FUN_00e47c20_s::FUN_00e47c20() const
{
    return static_cast<double>(m_kPoints.m_iElementCount - 1);
}

struct Vec : public hkVector4
{
    void FUN_00c7f640(void const*, hkVector4 const&);
};

struct FUN_00e47e50_class
{
    unsigned char m_ucUnknownByte[0x20];
    Vec* m_pPoints;
    int m_iPointCount;

    void FUN_00e47e50(void const*, void*, void*);
};

// Applies FUN_00c7f640 to each of the m_iPointCount points in m_pPoints, passing data and the point itself.
// @f3 0x0050c990 (community match, verified in this file)
struct SingletonTarget
{
    void FUN_0042c7f0(void* elem, void const* data, void* a2);
};
extern SingletonTarget* g_011f42c0;

// pdb: BGSTextureSet::QueueTextureSet | BGSTextureSet.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aePriority, apParent, abNoSpecular
void FUN_00e47e50_class::FUN_00e47e50(void const* data, void* a2, void* a3)
{
    void** slot = reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x88);
    int count = 6;
    do
    {
        if (*slot != 0)
            g_011f42c0->FUN_0042c7f0(*slot, data, a2);
        ++slot;
    } while (--count != 0);
}


struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    float value;
    void FUN_00e47430(float input);
};
// @fnv 0x00e47430
void CpuObject::FUN_00e47430(float input)
{
    value = input;
}

struct FnvCpu_FUN_00e47400_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    unsigned char* FUN_00e47400(unsigned char* output);
};
// @fnv 0x00e47400
// pdb: hkpLinearParametricCurve::getStart | hkpLinearParametricCurve.obj | fnv360_0822_retail, objopen_prop, low, conflict (skyrim: hkpLinearParametricCurve::isClosedLoop)
unsigned char* FnvCpu_FUN_00e47400_CpuObject::FUN_00e47400(unsigned char* output)
{
    *output = value;
    return output;
}

// Returns the constant float value 0.0f.
// @fnv 0x00e47410
// pdb: hkpLinearParametricCurve::getSmoothingFactor | hkpLinearParametricCurve.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpLinearParametricCurve::getStart)
float __cdecl GetZeroFloat()
{
    return 0.0f;
}

class CurveSmoothingGetter : public hkpParametricCurve
{
  public:
    float m_fSmoothingValue;
    float FUN_00e47420() const;
};

// @fnv 0x00e47420
// pdb: BSFaceGenKeyframe::GetTime | BSFaceGenKeyframe.obj | fnv360_0822_retail, vtable, medium
float CurveSmoothingGetter::FUN_00e47420() const
{
    return m_fSmoothingValue;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

extern const __m128 DAT_010ec7f0;

int __cdecl hkMath_hkFloatToInt(float f);

struct hkSimdRealE474
{
    __m128 m_vValue;

    hkSimdRealE474(const float& f)
    {
        m_vValue = _mm_load_ps1(&f);
    }
};

struct hkVector4E474
{
    __m128 m_vComponents;

    void operator=(const hkVector4E474& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setInterpolate4(const hkVector4E474& a, const hkVector4E474& b, const hkSimdRealE474& t)
    {
        const __m128 kOneMinusT = _mm_sub_ps(DAT_010ec7f0, t.m_vValue);
        m_vComponents = _mm_add_ps(_mm_mul_ps(kOneMinusT, a.m_vComponents), _mm_mul_ps(b.m_vComponents, t.m_vValue));
    }
};

template <class T> struct hkArrayE474
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

namespace fnv_00e474e0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_set_ps1(float);
extern "C" void _mm_store_ss(float*, __m128);
extern int __cdecl hkMath_hkFloatToInt(float f);

extern const __m128 DAT_010ec7f0;

struct Vec_e474e0
{
    __m128 m_vComponents;
    void setSub4(const Vec_e474e0& a, const Vec_e474e0& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMul4(const Vec_e474e0& a, const Vec_e474e0& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setInterpolate4(const Vec_e474e0& a, const Vec_e474e0& b, float t)
    {
        __m128 tt = _mm_set_ps1(t);
        m_vComponents =
            _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, tt), a.m_vComponents), _mm_mul_ps(b.m_vComponents, tt));
    }
    __forceinline float dot3(const Vec_e474e0& b) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, b.m_vComponents);
        __m128 y = _mm_shuffle_ps(x2, x2, 0x55);
        __m128 xy = _mm_add_ss(y, x2);
        __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        __m128 r = _mm_add_ss(z, xy);
        float f;
        _mm_store_ss(&f, r);
        return f;
    }
    float lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline void normalize3()
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_shuffle_ps(x2, x2, 0x55);
        __m128 xy = _mm_add_ss(y, x2);
        __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        __m128 len = _mm_add_ss(z, xy);
        __m128 e = _mm_rsqrt_ss(len);
        __m128 he = _mm_mul_ss(_mm_set_ss(0.5f), e);
        __m128 ree = _mm_mul_ss(_mm_mul_ss(len, e), e);
        __m128 r =
            _mm_andnot_ps(_mm_cmpeq_ss(len, _mm_set_ss(0.0f)), _mm_mul_ss(he, _mm_sub_ss(_mm_set_ss(3.0f), ree)));
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }
};

struct Arr_e474e0
{
    Vec_e474e0* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    Vec_e474e0& operator[](int i)
    {
        return m_data[i];
    }
    const Vec_e474e0& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

}  // namespace fnv_00e474e0

namespace fnv_00e478d0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
}

union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;
};

extern __m128 DAT_010ec7f0;

int __cdecl hkMath_hkFloatToInt(hkReal r);

struct LinearCurveT : public hkpLinearParametricCurve
{
    __forceinline const hkVector4q& P(int i) const
    {
        return reinterpret_cast<const hkVector4q*>(m_kPoints.m_data)[i];
    }
    void GetTangent(hkReal t, hkVector4& tangentOut) const;
};

}  // namespace fnv_00e478d0

int __cdecl hkMath_hkFloatToInt(float f);

class FUN_00e47c30_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int m_uiArrayCount;
    int unk28;
    float* m_iSlotIds;

    float hkpLinearParametricCurve_getLengthFromStart(float t) const;
};

// Linearly interpolates, or extrapolates past the ends, between entries of m_iSlotIds at t using the index from hkMath_hkFloatToInt.
// @fnv 0x00e47c30
// pdb: hkpLinearParametricCurve::getLengthFromStart | hkpLinearParametricCurve.obj | fnv360_0822_retail, caller_sim, high
// pdb params: t
// pdb: hkpLinearParametricCurve::getLengthFromStart | hkpLinearParametricCurve.obj | fnv360_0822_retail, caller_sim, high (was: GetInterpolatedValue)
float FUN_00e47c30_cls::hkpLinearParametricCurve_getLengthFromStart(float t) const
{
    int i = hkMath_hkFloatToInt(t);
    float fInterval;
    if (i >= m_uiArrayCount - 1)
    {
        i = m_uiArrayCount - 1;
        fInterval = m_iSlotIds[i] - m_iSlotIds[i - 1];
    }
    else
    {
        if (i < 0)
            i = 0;
        fInterval = m_iSlotIds[i + 1] - m_iSlotIds[i];
    }
    return (t - i) * fInterval + m_iSlotIds[i];
}

void* FUN_00c85750();

namespace fnv_00e48030 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

static const float DAT_01011d78 = 0.0f;
static const float DAT_01012068 = 1.0f;

extern "C" __m128 _mm_setr_ps(float fA, float fB, float fC, float fD);

struct hkVector4E48
{
    __m128 m_vComponents;

    void set(float fA, float fB, float fC, float fD)
    {
        m_vComponents = _mm_setr_ps(fA, fB, fC, fD);
    }
};

class hkBoolE48
{
  public:
    hkBoolE48(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }

    char m_cBooleanValue;
};

template <class T> struct hkArrayE48
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE48() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkBaseObjectE48
{
  public:
    virtual ~hkBaseObjectE48() throw();
};

class hkReferencedObjectE48 : public hkBaseObjectE48
{
  public:
    hkReferencedObjectE48() throw() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectE48() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00e48030 : public hkReferencedObjectE48
{
  public:
    FUN_00e48030() throw();
    virtual ~FUN_00e48030() throw();

    float m_fSmoothingValue;
    hkBoolE48 m_bClosedLoop;
    hkVector4E48 m_kVector4;
    hkArrayE48<hkVector4E48> m_kPoints;
    hkArrayE48<float> m_fClosestPointDistanceSquared;
    unsigned int unk38, unk3C;
};

// Constructs the object, initializing m_fSmoothingValue to 0.01f, m_bClosedLoop to false, and m_kVector4 to (0, 1, 0, 0).
// @fnv 0x00e48030
FUN_00e48030::FUN_00e48030() throw() : m_fSmoothingValue(0.01f), m_bClosedLoop(false)
{
    m_kVector4.set(DAT_01011d78, DAT_01012068, DAT_01011d78, DAT_01011d78);
}
}  // namespace fnv_00e48030

extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern float DAT_01011d78;
struct Allocator
{
    virtual void dummy0();
    virtual void* allocateChunk(int size);
    virtual void dummy2();
    virtual void* allocate(int* reqSize);
    virtual void deallocate(void* ptr, int size);
};
struct CurveThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* m_pThreadAllocator;
};
extern "C" void* __fastcall FUN_00e48030(void* p);
class ScalarLane
{
    __m128 value;

  public:
    inline ScalarLane(const __m128& v) : value(v)
    {}
    inline operator float() const
    {
        float component;
        _mm_store_ss(&component, value);
        return component;
    }
};
class QuadView
{
    __m128 value;

  public:
    __forceinline ScalarLane lane(int i) const
    {
        switch (i)
        {
        case 0:
            return value;
        case 1:
            return _mm_shuffle_ps(value, value, 85);
        case 2:
            return _mm_shuffle_ps(value, value, 170);
        default:
            return _mm_shuffle_ps(value, value, 255);
        }
    }
    __forceinline void set(float a, float b, float c, float d)
    {
        value = _mm_setr_ps(a, b, c, d);
    }
};

struct LinearParametricCurve : public hkReferencedObject
{
    float m_fSmoothingValue;
    char m_bClosedLoop;
    QuadView m_kVector4;
    hkArray<hkVector4> m_kPoints;
    hkArray<float> m_fClosestPointDistanceSquared;
    LinearParametricCurve* FUN_00e48090();
    void FUN_00e47e80(const hkVector4*);
};
static __forceinline LinearParametricCurve* createCurve()
{
    CurveThreadMemory* memory = (CurveThreadMemory*)FUN_00c85750();
    void* chunk = memory->m_pThreadAllocator->allocateChunk(0x40);
    ((hkReferencedObject*)chunk)->m_usMemSizeAndFlags = 0x40;
    return (LinearParametricCurve*)FUN_00e48030(chunk);
}
template <class T> static __forceinline void arrCopy_e48090(T* dst, int start, const T* src, int n)
{
    for (; start < n; ++start)
    {
        dst[start] = src[start];
    }
}
template <class T>
static __forceinline void copyFromArray_e48090(hkArray<T>& self, Allocator* alloc, const hkArray<T>& a)
{
    if ((self.m_iCapacityState & 0x3fffffff) < a.m_iElementCount)
    {
        if ((self.m_iCapacityState & 0x80000000) == 0)
        {
            alloc->deallocate(self.m_data, (self.m_iCapacityState & 0x3fffffff) * int(sizeof(T)));
        }
        int numBytes = a.m_iElementCount * int(sizeof(T));
        self.m_data = (T*)alloc->allocate(&numBytes);
        self.m_iCapacityState = numBytes / int(sizeof(T));
    }
    self.m_iElementCount = a.m_iElementCount;
    arrCopy_e48090(self.m_data, 0, a.m_data, self.m_iElementCount);
}
// @f3 0x009d4870 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009d4870 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct HeightInfo;
struct HeightBool { char value; HeightBool(bool b):value(b){} };
struct HeightHeap { void FUN_008f6d90(void*,unsigned,int);void* FUN_008f6d30(unsigned,int); };
struct FloatArray {
 float* data;int count;int capacity;
 FloatArray():data(0),count(0),capacity(0x80000000){}
 __forceinline void CopyFrom(const FloatArray& src) {
  int cap=capacity&0x3fffffff;
  if(cap<src.count) {
   if((capacity & 0x80000000u)==0) { HeightHeap* heap=(HeightHeap*)TlsGetValue(DAT_010f3170);heap->FUN_008f6d90(data,cap*4,0x17); }
   HeightHeap* heap=(HeightHeap*)TlsGetValue(DAT_010f3170);
   data=(float*)heap->FUN_008f6d30(src.count*4,0x17);
   capacity=(capacity&0x40000000)|src.count;
  }
  count=src.count;
  const float* in=src.data;float* dst=data;int n=count;
  for(int i=0;i<n;++i)dst[i]=in[i];
 }
};
struct FUN_009a5fa0 {
 virtual void Destroy();
unsigned unk04;
unsigned unk08;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
unsigned unk34;
unsigned unk38;
unsigned unk3c;
unsigned unk40;
unsigned unk44;
unsigned unk48;
unsigned unk4c;
unsigned unk50;
unsigned unk54;
unsigned unk58;
unsigned unk5c;
 FUN_009a5fa0(const HeightInfo&);
};
struct hkpStorageSampledHeightFieldShape : FUN_009a5fa0 {
 FloatArray values;HeightBool closed;
 virtual ~hkpStorageSampledHeightFieldShape();
 hkpStorageSampledHeightFieldShape(const HeightInfo&,const FloatArray&);
};
hkpStorageSampledHeightFieldShape::hkpStorageSampledHeightFieldShape(const HeightInfo& info,const FloatArray& src):FUN_009a5fa0(info),values(),closed(false) {
 values.CopyFrom(src);
}
}   // namespace f3m_009d4870


#include <math.h>
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_set_ss(float);

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

// @f3twin 0x00a75290 of 0x00589a00
struct F3Twin_00a75290 : public CurveSmoothingGetter { float F3_FUN_00a75290() const; };
// pdb: hkpLinearParametricCurve::setSmoothingFactor | hkpLinearParametricCurve.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkpLinearParametricCurve::getSmoothingFactor)
// pdb params: smooth
float F3Twin_00a75290::F3_FUN_00a75290() const
{
    return m_fSmoothingValue;
}
