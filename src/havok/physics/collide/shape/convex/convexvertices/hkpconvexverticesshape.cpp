#include "f3_common.h"
// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexVerticesShape.h"

struct FUN_00d58d60_t
{
    char pad[0x40];
    float* m;
    void hkpConvexVerticesShape_getFirstVertex(float* out);
};

// @fnv 0x00d58d60
// pdb: hkpConvexVerticesShape::getFirstVertex | hkpConvexVerticesShape.obj | fnv360_0822_retail, objrun + bridge(hash|vtable) + skyrim(hash), high
void FUN_00d58d60_t::hkpConvexVerticesShape_getFirstVertex(float* out)
{
    float* p = m;
    out[0] = p[0];
    out[1] = p[4];
    out[2] = p[8];
    out[3] = 0.0f;
}

struct FUN_00d591d0_class : public hkpConvexVerticesShape
{
    void FUN_00d591d0(void*, float, int);
};

void __cdecl FUN_00d26230(void*, void*, void*, float, int);

// Transforms the local AABB (half extents and centre) to world space, grown by the radius plus the tolerance.
// @fnv 0x00d591d0
// pdb: hkpConvexVerticesShape::getAabbImpl | hkpConvexVerticesShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: localToWorld, tolerance, out
void FUN_00d591d0_class::FUN_00d591d0(void* a, float afDelta, int c)
{
    FUN_00d26230(a, &m_kAabbHalfExtents, &m_kAabbCenter, m_fSphereRadius + afDelta, c);
}

struct Vec4 { float x, y, z, w; };

// @fnv 0x00d58d40
// pdb: hkpConvexVerticesShape::getCentreImpl | hkpConvexVerticesShape.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: ConvexVerticesShape_FetchVectorFromPpuArray)
// pdb params: centreOut
static Vec4* __cdecl FUN_00d58d40(Vec4* base, int index)
{
    return base + index;
}

Vec4* caller_d58d40(Vec4* base, int index)
{
    return FUN_00d58d40(base, index);
}

struct FnvCpu_FUN_00d58d10_CpuObject {
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
    int value;
    int FUN_00d58d10();
};
// @fnv 0x00d58d10
// pdb: hkpConvexVerticesShape::getNumCollisionSpheresImpl | hkpConvexVerticesShape.obj | fnv360_0822_retail, objrun_open, low
int FnvCpu_FUN_00d58d10_CpuObject::FUN_00d58d10()
{
    return value;
}

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_setr_ps(float, float, float, float);
struct hkVec4Q {
    __m128 m_vComponents;
    void set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    const float& operator()(int i) const { return ((const float*)&m_vComponents)[i]; }
};
struct hkSphereQ {
    hkVec4Q m_pos;
    hkVec4Q& getPositionAndRadius() { return m_pos; }
};
struct FourVectorsQ { hkVec4Q m_uiX; hkVec4Q m_uiY; hkVec4Q m_uiZ; };
struct ConvexVertsQ : public hkpShape {
    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kAabbHalfExtents;
    hkVector4 m_kAabbCenter;
    FourVectorsQ* m_kRotatedVertices;
    int m_rotatedSize;
    int m_rotatedCapacity;
    int m_iStridedVertexCount;
    hkSphereQ* FillSphereBuffer(hkSphereQ* sphereBuffer) const;
};

namespace fnv_00d59cc0 {
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" {
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_xor_ps(__m128, __m128);
__m128 _mm_unpacklo_ps(__m128, __m128);
__m128 _mm_unpackhi_ps(__m128, __m128);
__m128 _mm_movelh_ps(__m128, __m128);
__m128 _mm_movehl_ps(__m128, __m128);
}

typedef __m128 hkQuadReal;

extern const hkQuadReal hkQuadRealSignMask;

struct hkSimdRealq
{
    hkQuadReal m_vValue;
};

struct hkMatrix3q;

struct hkVector4q
{
    hkQuadReal m_vComponents;

    __forceinline void operator=(const hkVector4q& v) { m_vComponents = v.m_vComponents; }
    __forceinline void setNeg4(const hkVector4q& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, hkQuadRealSignMask); }
    __forceinline void _setRotatedInverseDir(const hkMatrix3q& r, const hkVector4q& b);
    void SetRotatedDirection(const hkMatrix3q& r, const hkVector4q& b) throw();
    __forceinline hkSimdRealq dot4xyz1(const hkVector4q& a) const
    {
        const hkQuadReal xx = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const hkQuadReal x2 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0x55), xx);
        const hkQuadReal x3 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0xaa), _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
        hkSimdRealq r;
        r.m_vValue = _mm_add_ps(x3, x2);
        return r;
    }
    __forceinline void setW(const hkSimdRealq& w)
    {
        const hkQuadReal ww = _mm_shuffle_ps(w.m_vValue, w.m_vValue, 0);
        m_vComponents = _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, ww), 0xc4);
    }
};

struct hkMatrix3q
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
};

struct hkMemoryAllocatorq
{
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkThreadMemoryq
{
    char* m_stackTop;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorq* m_pStreamAllocator;

    __forceinline hkMemoryAllocatorq& heap() { return *m_pStreamAllocator; }
};

void* __cdecl FUN_00c85750() throw();

static __forceinline hkThreadMemoryq* hkGetThreadMemory() { return (hkThreadMemoryq*)FUN_00c85750(); }

template <class T>
struct hkArrayq
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkArrayq() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~hkArrayq()
    {
        hkMemoryAllocatorq& alloc = hkGetThreadMemory()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
    __forceinline T* begin() { return m_data; }
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
};

template <class T>
__forceinline T* hkAllocateStack(int n)
{
    hkThreadMemoryq* mem = hkGetThreadMemory();
    char* p = mem->m_stackTop;
    mem->m_stackTop = p + ((n * sizeof(T) + 127) & ~127);
    return (T*)p;
}

template <class T>
__forceinline void hkDeallocateStack(T* p)
{
    hkGetThreadMemory()->m_stackTop = (char*)p;
}

template <class T>
struct hkLocalArrayq : public hkArrayq<T>
{
    T* m_pStackAllocation;

    __forceinline hkLocalArrayq(int n)
    {
        this->m_data = hkAllocateStack<T>(n);
        m_pStackAllocation = this->m_data;
        this->m_iCapacityState = n | 0x80000000;
    }
    __forceinline ~hkLocalArrayq()
    {
        if (m_pStackAllocation == this->m_data)
        {
            this->m_iElementCount = 0;
        }
        hkDeallocateStack<T>(m_pStackAllocation);
    }
};

}  // namespace fnv_00d59cc0

struct AllocatorD5A360 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& iNumBytesInOut);
    virtual void ReturnMemory(void* p, int iNumBytes);
};
struct RouterD5A360 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocatorD5A360* m_pkHeap;
};
RouterD5A360* GetRouterD5A360();
struct __declspec(align(16)) Vector4D5A360 {
    float x;
    float y;
    float z;
    float w;
    void operator=(const Vector4D5A360& v) { *reinterpret_cast<__m128*>(this) = *reinterpret_cast<const __m128*>(&v); }
};
template <class T> __forceinline void CopyD5A360(T* pDst, const T* pSrc, int iEntryIndex)
{
    for (int i = 0; i < iEntryIndex; i++)
        pDst[i] = pSrc[i];
}
template <class T> struct ArrayD5A360 {
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline ArrayD5A360& operator=(const ArrayD5A360& a)
    {
        AllocatorD5A360& kAlloc = *GetRouterD5A360()->m_pkHeap;
        if (getCapacity() < a.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kAlloc.AllocateBufferWithSize(iNumBytes));
            m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        m_iElementCount = a.m_iElementCount;
        CopyD5A360(m_data, a.m_data, m_iElementCount);
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkpConvexVerticesShapeFourVectors
{
public:
    hkReal m_uiX[4];
    hkReal m_uiY[4];
    hkReal m_uiZ[4];
};

struct Vector4WithInt24W
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkUint32 w;
    hkReal& operator()(int i) { return (&x)[i]; }
    void set(hkReal a, hkReal b, hkReal c) { x = a; y = b; z = c; }
    void setInt24W(int value) { w = (hkUint32)value | 0x3f000000; }
};

typedef hkUint16 hkpVertexId;

class hkpConvexVerticesShapeImpl : public hkpConvexVerticesShape
{
public:
    void FUN_00d59060(const hkpVertexId* ids, int numIds, Vector4WithInt24W* verticesOut) const;
};

// Copies numIds rotated vertex positions from m_kRotatedVertices into verticesOut, packing each vertexId into the w field.
// @fnv 0x00d59060
// pdb: hkpConvexVerticesShape::convertVertexIdsToVerticesImpl | hkpConvexVerticesShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: ids, numIds, verticesOut
void hkpConvexVerticesShapeImpl::FUN_00d59060(const hkpVertexId* ids, int numIds, Vector4WithInt24W* verticesOut) const
{
    int i = numIds - 1;
    __assume(i >= 0);
    for (; i >= 0; i--)
    {
        int vertexId = ids[0];
        const hkpConvexVerticesShapeFourVectors& fv = m_kRotatedVertices.m_data[vertexId >> 2];
        int a = vertexId & 3;
        Vector4WithInt24W& v = verticesOut[0];
        v(0) = fv.m_uiX[a];
        v(1) = fv.m_uiY[a];
        v(2) = fv.m_uiZ[a];
        v.setInt24W(vertexId);
        verticesOut++;
        ids++;
    }
}

class SpliceAllocator;
void __cdecl FUN_00c908c0(SpliceAllocator& allocator,void* array,int capacity,int elementBytes);

class hkMemoryAllocatorD598 {
public:
    virtual ~hkMemoryAllocatorD598() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD598 {
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD598* m_pStreamAllocator;

    hkMemoryAllocatorD598& heap() { return *m_pStreamAllocator; }
};

extern "C" hkMemoryRouterD598& __cdecl FUN_00c85750() throw();

template <class T>
class hkArrayD598 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD598() throw()
    {
        hkMemoryAllocatorD598& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkD598 {
    class hkBaseObject {
    public:
        virtual ~hkBaseObject() throw() {}
    };

    class hkReferencedObject : public hkBaseObject {
    public:
        unsigned short m_usMemSizeAndFlags;
        short m_sReferenceCount;
        void FUN_00c905b0() throw();
    };

    class hkpShape : public hkReferencedObject {
    public:
        unsigned long m_ulUserData;
        int m_type;
    };

    class hkpSphereRepShape : public hkpShape {
    };

    class hkpConvexShape : public hkpSphereRepShape {
    public:
        float m_fSphereRadius;
    };

    struct hkVector4D598 {
        float x, y, z, w;
    };

    struct hkFourTransposedPointsD598 {
        hkVector4D598 m_uiX, m_uiY, m_uiZ;
    };
}

namespace FUN_00d59870 {
    class hkpConvexVerticesShape : public hkD598::hkpConvexShape {
    public:
        virtual ~hkpConvexVerticesShape();

        int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
        hkArrayD598<hkD598::hkFourTransposedPointsD598> m_kRotatedVertices;
        int m_iStridedVertexCount;
        int unk50;
        hkArrayD598<hkD598::hkVector4D598> m_kVertexPositions;
        hkD598::hkReferencedObject* m_pConnectivity;
    };

// Releases the m_pConnectivity referenced object by calling FUN_00c905b0 if it is not null.
// @fnv 0x00d59870
    hkpConvexVerticesShape::~hkpConvexVerticesShape()
    {
        if (m_pConnectivity)
            m_pConnectivity->FUN_00c905b0();
    }
}

extern "C" __m128 _mm_load_ps(const float*);
struct SelectBits { __m128 v; };
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmplt_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_andnot_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_or_ps(__m128 a, __m128 b);

struct MatchVector
{
    __m128 m_vComponents;

    MatchVector() {}
 SelectBits compare(const MatchVector& a) const { SelectBits result; result.v=_mm_cmplt_ps(m_vComponents,a.m_vComponents); return result; }
    MatchVector(const MatchVector& v) { m_vComponents = v.m_vComponents; }
    MatchVector(float v)
    {
        m_vComponents.m128_f32[0] = v;
        m_vComponents.m128_f32[1] = v;
        m_vComponents.m128_f32[2] = v;
        m_vComponents.m128_f32[3] = v;
    }
    void operator=(const MatchVector& v) { m_vComponents = v.m_vComponents; }
    float& operator()(int i) { return m_vComponents.m128_f32[i]; }
    const float& operator()(int i) const { return m_vComponents.m128_f32[i]; }
    void setMul4(const MatchVector& a, const MatchVector& b) { m_vComponents = _mm_mul_ps(_mm_load_ps((const float*)&a.m_vComponents), b.m_vComponents); }
    void addMul4(const MatchVector& a, const MatchVector& b) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_load_ps((const float*)&a.m_vComponents), b.m_vComponents)); }
    void add4(const MatchVector& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
    void setSelect4(const SelectBits& comp, const MatchVector& trueValue, const MatchVector& falseValue) { m_vComponents = _mm_or_ps(_mm_and_ps(comp.v, trueValue.m_vComponents), _mm_andnot_ps(comp.v, falseValue.m_vComponents)); }
    void selectIndex(const SelectBits& comp,const MatchVector& trueValue,const MatchVector& falseValue) {m_vComponents=_mm_or_ps(_mm_and_ps(comp.v,trueValue.m_vComponents),_mm_andnot_ps(_mm_load_ps((const float*)&comp.v),falseValue.m_vComponents));}
void setInt24W(int value) { ((int*)&m_vComponents)[3] = value | 0x3f000000; }
};

extern void* DAT_010d0fc4;
extern "C" void _ReadWriteBarrier();


template<class T> struct ConstructedArray : ArrayD5A360<T> {
    __forceinline ConstructedArray() : ArrayD5A360<T>() {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct RefPart {
    void** m_ppVirtualMethodTable;
    unsigned short unk04;
    unsigned short referenceCount;
    __forceinline RefPart() : referenceCount(1) {}
};
struct ShapePart : RefPart {
    int userData;
    int type;
    __forceinline ShapePart(int shapeType) { userData = 0; type = shapeType; m_ppVirtualMethodTable = &DAT_010d0fc4; }
};
struct SpherePart : ShapePart {
    __forceinline SpherePart(int shapeType) : ShapePart(shapeType) {}
};
struct ConvexPart : SpherePart {
    float radius;
    __forceinline ConvexPart(int shapeType, float r) : SpherePart(shapeType) { radius = r; }
};

extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct ConvexPiece;


struct hkBoolRet {
    char m_cBooleanValue;
    hkBoolRet(bool b) { m_cBooleanValue = (char)b; }
};

struct __declspec(align(16)) V4 { float x, y, z, w; };

struct ConvexPiece {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    const unsigned char* m_bytes;
    int unk20, unk24;
    const unsigned short* m_kIndices;
    int m_numFaces;
};

static __forceinline float Dot4xyz1(const V4& p, const V4& v)
{
    __m128 q = *(const __m128*)&p;
    __m128 xx = _mm_mul_ps(q, *(const __m128*)&v);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0x55), xx);
    __m128 zw = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0xaa), _mm_shuffle_ps(q, q, 0xff));
    float r;
    _mm_store_ss(&r, _mm_add_ps(xy, zw));
    return r;
}

struct VertArray96Q {
    hkVec4Q* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkVec4Q& operator[](int i) { return m_data[i]; }
    void SetSizeAndGrow(int n)
    {
        hkMemoryAllocatorD598& alloc = FUN_00c85750().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap + cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(reinterpret_cast<SpliceAllocator&>(alloc), this, newSize, sizeof(hkVec4Q));
        }
        m_iElementCount = n;
    }
};

struct ConvexVertsQ_d59200 : ConvexVertsQ {
    void FUN_00d59200(VertArray96Q& vertices) const;
};

// @f3 0x009e8020 (community match, verified in this file)
struct Vector458 {
    float x, y, z, w;
    __forceinline void Set(float a, float b, float c, float d) { x=a; y=b; z=c; w=d; }
};
struct Array458 { Vector458* data; int size, capacity; };
struct Bundle458 { float x[4], y[4], z[4]; };
struct Shape458 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    Bundle458* bundles; int size,capacity,count;
};
void __cdecl FUN_00901e90(Array458*,int,int);
__forceinline void Resize458(Array458& array,int count) {
    int capacity=array.capacity&0x3fffffff;
    if(capacity<count) {
        int doubled=capacity+capacity;
        int target=count<doubled?doubled:count;
        FUN_00901e90(&array,target,16);
    }
    array.size=count;
}
// pdb: hkpConvexVerticesShape::getOriginalVertices | hkpConvexVerticesShape.obj | fnv360_0822_retail, call_seq, medium
// pdb params: vertices
void ConvexVertsQ_d59200::FUN_00d59200(VertArray96Q& vertices) const {
    Array458& array=reinterpret_cast<Array458&>(vertices);
    const Shape458* shape=reinterpret_cast<const Shape458*>(this);
    Resize458(array,shape->count);
    for(int i=0;i<shape->count;++i) {
        int a=i/4;
        int b=i&3;
        array.data[i].Set(shape->bundles[a].x[b],shape->bundles[a].y[b],shape->bundles[a].z[b],0.0f);
    }
}


extern __m128 DAT_010c71d0;

struct hkMemoryAllocator;
struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    __forceinline hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};
NineIntegerRecord* GetMemoryRouter_c85750();
void __cdecl ArrayUtilReserve_c908c0(hkMemoryAllocator& alloc, void* array, int numElements, int sizeElem);

struct FourFloatVector
{
    __m128 m_vComponents;
    __forceinline float& operator()(int i) { return m_vComponents.m128_f32[i]; }
};

struct FourVectors
{
    FourFloatVector m_uiX;
    FourFloatVector m_uiY;
    FourFloatVector m_uiZ;
};

template <class T> struct Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ArrayUtilReserve_c908c0(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n) { _setSize(GetMemoryRouter_c85750()->heap(), n); }
    __forceinline T& operator[](int i) { return m_data[i]; }
};

struct Aabb
{
    FourFloatVector m_kMinimumCorner;
    FourFloatVector m_kMaximumCorner;

    __forceinline void getCenter(FourFloatVector& center) const
    {
        center.m_vComponents = _mm_mul_ps(_mm_add_ps(m_kMinimumCorner.m_vComponents, m_kMaximumCorner.m_vComponents), DAT_010c71d0);
    }
    __forceinline void getHalfExtents(FourFloatVector& halfExtents) const
    {
        halfExtents.m_vComponents = _mm_mul_ps(_mm_sub_ps(m_kMaximumCorner.m_vComponents, m_kMinimumCorner.m_vComponents), DAT_010c71d0);
    }
};

void __cdecl CalcAabb_cbeaf0(const float* vertexArray, int numVertices, int striding, Aabb& aabbOut);

struct ConvexVerticesShape
{
    void* vtable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    float m_fSphereRadius;
    float unk14;
    float unk18;
    float unk1C;
    FourFloatVector m_kAabbHalfExtents;
    FourFloatVector m_kAabbCenter;
    Array<FourVectors> m_kRotatedVertices;
    int m_iStridedVertexCount;

    void FUN_00d59900(const float* vertexIn, int byteStriding, int numVertices);
};

// Stores numVertices, copies vertexIn into m_kRotatedVertices padded to a multiple of four, and computes the AABB center and half-extents.
// @f3 0x009e80c0 (community match, verified in this file)
__forceinline void ResizeLocal(Array<FourVectors>& array, int n) {
    int cap = array.m_iCapacityState & 0x3fffffff;
    if (cap < n) {
        int cap2 = cap + cap;
        int target = n < cap2 ? cap2 : n;
        FUN_00901e90(reinterpret_cast<Array458*>(&array),target,sizeof(FourVectors));
    }
    array.m_iElementCount = n;
}
void ConvexVerticesShape::FUN_00d59900(const float* vertexIn, int byteStriding, int numVertices)
{
    m_iStridedVertexCount = numVertices;
    int paddedSize = (numVertices + 3) & ~3;
    ResizeLocal(m_kRotatedVertices,paddedSize / 4);

    const float* v = vertexIn;
    int i;
    for (i = 0; i < numVertices; i++)
    {
        int a = (unsigned)i >> 2;
        int b = i & 3;
        m_kRotatedVertices[a].m_uiX(b) = v[0];
        m_kRotatedVertices[a].m_uiY(b) = v[1];
        m_kRotatedVertices[a].m_uiZ(b) = v[2];
        v = (const float*)((const char*)v + byteStriding);
    }

    v = (const float*)((const char*)v - byteStriding);
    // i == numVertices <= paddedSize; strict < drops the unroller's redundant
    // overflow guard. Equality still exits through the scalar cmp.
    __assume(i < paddedSize);
    for (; i < paddedSize; i++)
    {
        int a = i >> 2;
        int b = i & 3;
        m_kRotatedVertices[a].m_uiX(b) = v[0];
        m_kRotatedVertices[a].m_uiY(b) = v[1];
        m_kRotatedVertices[a].m_uiZ(b) = v[2];
    }

    Aabb aabb;
    CalcAabb_cbeaf0(vertexIn, numVertices, byteStriding, aabb);
    m_kAabbCenter(0) = aabb.m_kMinimumCorner(0) + aabb.m_kMaximumCorner(0);
    m_kAabbCenter(1) = aabb.m_kMinimumCorner(1) + aabb.m_kMaximumCorner(1);
    m_kAabbCenter(2) = aabb.m_kMinimumCorner(2) + aabb.m_kMaximumCorner(2);
    m_kAabbCenter(3) = aabb.m_kMinimumCorner(3) + aabb.m_kMaximumCorner(3);
    m_kAabbCenter(0) *= 0.5;
    m_kAabbCenter(1) *= 0.5;
    m_kAabbCenter(2) *= 0.5;
    m_kAabbCenter(3) *= 0.5;
    m_kAabbHalfExtents(0) = aabb.m_kMaximumCorner(0) - aabb.m_kMinimumCorner(0);
    m_kAabbHalfExtents(1) = aabb.m_kMaximumCorner(1) - aabb.m_kMinimumCorner(1);
    m_kAabbHalfExtents(2) = aabb.m_kMaximumCorner(2) - aabb.m_kMinimumCorner(2);
    m_kAabbHalfExtents(3) = aabb.m_kMaximumCorner(3) - aabb.m_kMinimumCorner(3);
    m_kAabbHalfExtents(0) *= 0.5;
    m_kAabbHalfExtents(1) *= 0.5;
    m_kAabbHalfExtents(2) *= 0.5;
    m_kAabbHalfExtents(3) *= 0.5;
}

