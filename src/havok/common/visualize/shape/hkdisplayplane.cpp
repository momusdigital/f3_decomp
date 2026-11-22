#include "f3_common.h"
// src/havok/common/visualize/shape/hkdisplayplane.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplayplane.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct __declspec(intrin_type) __declspec(align(16)) __m128
{
    float x, y, z, w;
};
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
struct Vec4_de4e20
{
    __m128 q;
    void setCross(const Vec4_de4e20& a, const Vec4_de4e20& b)
    {
        __m128 t0 = _mm_shuffle_ps(a.q, a.q, 0xc9);
        __m128 t1 = _mm_shuffle_ps(b.q, b.q, 0xd2);
        __m128 t2 = _mm_shuffle_ps(a.q, a.q, 0xd2);
        __m128 t3 = _mm_shuffle_ps(b.q, b.q, 0xc9);
        q = _mm_sub_ps(_mm_mul_ps(t0, t1), _mm_mul_ps(t2, t3));
    }
    void SetProduct(const Vec4_de4e20& a, const Vec4_de4e20& b)
    {
        q = _mm_mul_ps(a.q, b.q);
    }
    void mul(const Vec4_de4e20& b)
    {
        q = _mm_mul_ps(q, b.q);
    }
    void set(const Vec4_de4e20& b)
    {
        q = b.q;
    }

    void add(const Vec4_de4e20& o)
    {
        q = _mm_add_ps(q, o.q);
    }
    void sub(const Vec4_de4e20& o)
    {
        q = _mm_sub_ps(q, o.q);
    }
};
struct Cls_00de4e20
{
    __m128 unk00, unk10, unk20, unk30, unk40, unk50;
    Vec4_de4e20 m_kPointA;
    Vec4_de4e20 m_p;
    Vec4_de4e20 m_kPointB;
    Vec4_de4e20 m_q;
    void __thiscall FUN_00de4e20(Vec4_de4e20* out);
};
// @fnv 0x00de4e20
void __thiscall Cls_00de4e20::FUN_00de4e20(Vec4_de4e20* out)
{
    Vec4_de4e20 cross;
    cross.setCross(m_kPointA, m_kPointB);
    out[0].set(m_p);
    out[1].set(m_p);
    out[2].set(m_p);
    out[3].set(m_p);
    Vec4_de4e20 t0 = cross, t1;
    t1.q = m_kPointB.q;
    t0.mul(m_q);
    t1.mul(m_q);
    out[0].add(t0);
    out[0].add(t1);
    out[1].add(t0);
    out[1].sub(t1);
    out[2].sub(t0);
    out[2].add(t1);
    out[3].sub(t0);
    out[3].sub(t1);
}

struct VecBuf
{
    unsigned char* m_data;       // +0x00
    unsigned int m_uiItemCount;  // +0x04
    unsigned int m_iElementCount;         // +0x08 (low 30 bits = size)
};

__declspec(align(16)) struct VecTemp4
{
    unsigned int m_00, m_04, m_08, m_0c;
    unsigned int m_10, m_14, m_18, m_1c;
    unsigned int m_20, m_24, m_28, m_2c;
    unsigned int m_30, m_34, m_38, m_3c;
};

extern "C" void __cdecl FUN_00c908c0(unsigned int a1, VecBuf* v, int cap, int elem);

struct S_00de5110_Heap
{
    virtual void v00() throw();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
};

struct S_00de5110_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00de5110_Heap* m_pStreamAllocator;
    S_00de5110_Heap& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};

S_00de5110_Router& FUN_00c85750() throw();
void FUN_00c908c0(S_00de5110_Heap& alloc, void* array, int numElements, int sizeElem) throw();

template <typename T> struct S_00de5110_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00de5110_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i) throw()
    {
        return m_data[i];
    }
    T* begin() throw()
    {
        return m_data;
    }

    __forceinline void GrowArrayCapacity(S_00de5110_Heap& a, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(a, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S_00de5110_Heap& a, int n) throw()
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }
    __forceinline T* _expandBy(S_00de5110_Heap& a, int n) throw()
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(a, oldsize + n);
        m_iElementCount += n;
        return m_data + oldsize;
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        _setSize(FUN_00c85750().heap(), n);
    }
    __forceinline T* expandBy(int n) throw()
    {
        return _expandBy(FUN_00c85750().heap(), n);
    }
};

struct __declspec(align(16)) S_00de5110_Vector4
{
    float x, y, z, w;
    void operator=(const S_00de5110_Vector4& v) throw()
    {
        reinterpret_cast<__m128&>(*this) = reinterpret_cast<const __m128&>(v);
    }
};

struct S_00de5110_Triangle
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
    void set(int a, int b, int c, int material = -1) throw()
    {
        m_kPointA = a;
        m_kPointB = b;
        m_iThirdValue = c;
        m_iMaterialIndex = material;
    }
};

struct S_00de5110_Geometry
{
    S_00de5110_Array<S_00de5110_Vector4> m_kVertices;
    S_00de5110_Array<S_00de5110_Triangle> m_uiTriangleCount;

    S_00de5110_Geometry() throw()
    {}
    static void* operator new(unsigned int n) throw()
    {
        return FUN_00c85750().heap().AllocateMemoryBlock(n);
    }
    static void operator delete(void*) throw()
    {}
};

struct S_00de5110_Pyramid
{
    int unk0;
    int unk4;
    S_00de5110_Geometry* m_pSourceGeometry;
    int unkC;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    S_00de5110_Vector4 m_apex;

    void FUN_00de4e20(S_00de5110_Vector4* verts);
    void BuildPyramidGeometry();
};

// Allocates a Geometry, sets 5 vertices with the apex at index 4, and adds 4 triangles connecting the base to the apex.
// @f3 0x00a6b7c0 (community match, verified in this file)
#include <windows.h>


struct S_00a6b7c0_FreeElem
{
    S_00a6b7c0_FreeElem* m_next;
};

struct S_00a6b7c0_FreeList
{
    S_00a6b7c0_FreeElem* m_head;
    int m_numElem;
};

struct S_00a6b7c0_ThreadMemory
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
    S_00a6b7c0_FreeList m_free_list[8];

    static DWORD s_tlsIndex;

    void* onRowEmpty(int row, int memClass);

    static S_00a6b7c0_ThreadMemory& getInstance()
    {
        return *static_cast<S_00a6b7c0_ThreadMemory*>(TlsGetValue(s_tlsIndex));
    }

    __forceinline void* allocateChunk(int row, int memClass)
    {
        S_00a6b7c0_FreeList& fl = m_free_list[row];
        S_00a6b7c0_FreeElem* n = fl.m_head;
        if (n)
        {
            fl.m_numElem--;
            fl.m_head = n->m_next;
            return n;
        }
        return onRowEmpty(row, memClass);
    }
};

struct S_00a6b7c0_ArrayUtil
{
    static void __cdecl _reserve(void* array, int numElem, int sizeElem);
};

template <typename T> struct S_00a6b7c0_Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    S_00a6b7c0_Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000)
    {}

    int getCapacity() const
    {
        return m_capacityAndFlags & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    T* begin()
    {
        return m_data;
    }
    __forceinline void reserve(int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            S_00a6b7c0_ArrayUtil::_reserve(this, newSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_size = n;
    }
    __forceinline T* expandBy(int n)
    {
        int oldsize = m_size;
        SetSizeAndGrow(oldsize + n);
        return m_data + oldsize;
    }
};

struct S_00a6b7c0_Vector4
{
    float x, y, z, w;
    void operator=(const S_00a6b7c0_Vector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
};

struct S_00a6b7c0_Triangle
{
    int m_a;
    int m_b;
    int m_c;
    void set(int a, int b, int c)
    {
        m_a = a;
        m_b = b;
        m_c = c;
    }
};

struct S_00a6b7c0_Geometry
{
    S_00a6b7c0_Array<S_00a6b7c0_Vector4> m_kVertices;
    S_00a6b7c0_Array<S_00a6b7c0_Triangle> m_uiTriangleCount;

    static void* operator new(unsigned int)
    {
        return S_00a6b7c0_ThreadMemory::getInstance().allocateChunk(3, 0x27);
    }
    static void operator delete(void*)
    {}
};

// pdb: hkDisplayPlane::buildGeometry | hkDisplayPlane.obj | fnv360_0822_retail, vtable, medium
void S_00de5110_Pyramid::BuildPyramidGeometry()
{
    m_pSourceGeometry = reinterpret_cast<S_00de5110_Geometry*>(new S_00a6b7c0_Geometry());
    reinterpret_cast<S_00a6b7c0_Geometry*>(m_pSourceGeometry)->m_kVertices.SetSizeAndGrow(5);
    reinterpret_cast<S_00a6b7c0_Geometry*>(m_pSourceGeometry)->m_kVertices[4] = reinterpret_cast<const S_00a6b7c0_Vector4&>(m_apex);
    FUN_00de4e20(reinterpret_cast<S_00de5110_Vector4*>(reinterpret_cast<S_00a6b7c0_Geometry*>(m_pSourceGeometry)->m_kVertices.begin()));
    reinterpret_cast<S_00a6b7c0_Geometry*>(m_pSourceGeometry)->m_uiTriangleCount.expandBy(1)->set(2, 4, 3);
    reinterpret_cast<S_00a6b7c0_Geometry*>(m_pSourceGeometry)->m_uiTriangleCount.expandBy(1)->set(0, 4, 2);
    reinterpret_cast<S_00a6b7c0_Geometry*>(m_pSourceGeometry)->m_uiTriangleCount.expandBy(1)->set(1, 4, 0);
    reinterpret_cast<S_00a6b7c0_Geometry*>(m_pSourceGeometry)->m_uiTriangleCount.expandBy(1)->set(3, 4, 1);
}


extern "C" __m128 _mm_setzero_ps(void);

// Today's unit (hkdisplayplane.cpp) defines __m128 and its intrinsics itself;
// declare the one the matched code needs that the unit does not have.
extern "C" __m128 _mm_setzero_ps(void);

struct S_00de4ff0_Vec4
{
    __m128 m_vComponents;
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct S_00de4ff0_Rotation
{
    S_00de4ff0_Vec4 m_kColumn0;
    S_00de4ff0_Vec4 m_kColumn1;
    S_00de4ff0_Vec4 m_kColumn2;

    __forceinline float& operator()(int r, int c)
    {
        return ((float*)this)[c * 4 + r];
    }
    __forceinline void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    __forceinline void setDiagonal(float x, float y, float z)
    {
        setZero();
        (*this)(0, 0) = x;
        (*this)(1, 1) = y;
        (*this)(2, 2) = z;
    }
    __forceinline void setIdentity()
    {
        setDiagonal(1.0f, 1.0f, 1.0f);
    }
};

struct S_00de4ff0_Transform
{
    S_00de4ff0_Rotation m_rotation;
    S_00de4ff0_Vec4 m_vTranslation;

    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

struct __declspec(novtable) S_00de4ff0_RefObj
{
    virtual void vfn_00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    __forceinline S_00de4ff0_RefObj() throw() : m_sReferenceCount(1)
    {}
};

struct __declspec(novtable) S_00de4ff0_Base : S_00de4ff0_RefObj
{
    int m_field08;
    int unk0C;
    S_00de4ff0_Transform m_kMotionTransform;
    int m_field50;
    int unk54;
    int unk58;
    int unk5C;
    S_00de4ff0_Vec4 m_vec60;
    S_00de4ff0_Vec4 m_vec70;
    S_00de4ff0_Vec4 m_vec80;
    S_00de4ff0_Vec4 m_vec90;

    __forceinline S_00de4ff0_Base() throw() : m_field08(0), m_field50(7)
    {
        m_kMotionTransform.setIdentity();
    }
};
