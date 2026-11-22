#include "f3_common.h"
// src/havok/animation/ragdoll/utils/hkaragdollutils_fpfast_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy /fp:fast (unit src/havok/animation/ragdoll/utils/hkaragdollutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/utils/hkaragdollutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/utils/hkaragdollutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C"
{
    int __cdecl FUN_00ce9db0(void*, void*);
}
struct Inner
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual int getSomething();
};
struct Obj
{
    char pad0[0xc];
    Inner* inner;
};
struct hkErrStream
{
    void* p1;
    void* p2;
    void* p3;
    hkErrStream(void* buf, int size) throw();
    ~hkErrStream() throw();
    hkErrStream& operator<<(const char* str) throw();
};
static bool _isConstraintSupported(Obj* obj, bool reportError) throw();
struct Node
{
    int unk00, unk04, unk08, unk0c, unk10;
    void* source;
    void* destination;
};
template <class T> struct GameArray
{
    T* data;
    int count;
    int capacity;
    __forceinline void assign(const T* source, int size) throw();
};
typedef GameArray<void*> IntArray;
typedef GameArray<Node*> NodeArray;
struct HeapAllocator
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void* allocate(int* size);
    virtual void release(void* data, int size);
};
struct ScratchAllocator
{
    unsigned char* cursor;
    int unk04, unk08, unk0c;
    HeapAllocator* heap;
};
struct ScratchArray
{
    int* data;
    int count;
    unsigned int capacity;
    int* initial;
    __forceinline int& operator[](int index) throw()
    {
        return data[index];
    }
};
struct LogText
{
    int unk00, unk04, unk08;
    void FUN_00cb1600(void* storage, int length) throw();
    LogText(void* storage, int length) throw()
    {
        FUN_00cb1600(storage, length);
    }
    ~LogText() throw()
    {
        FUN_00cc00e0();
    }
    LogText* FUN_00cc01c0(const char* value) throw();
    LogText* WriteInt(int value) throw();
    void FUN_00cc00e0() throw();
};
extern "C" void __cdecl FUN_00c908c0(HeapAllocator* allocator, ScratchArray* array, int capacity, int itemSize);
struct BSAudio;
BSAudio* __cdecl _FUN_00c85750() throw();
static ScratchAllocator* scratchState() throw()
{
    return reinterpret_cast<ScratchAllocator*>(_FUN_00c85750());
}
static int* reserveScratch(int bytes) throw()
{
    ScratchAllocator* allocator = scratchState();
    int* result = reinterpret_cast<int*>(allocator->cursor);
    allocator->cursor += bytes;
    return result;
}
static __forceinline void reserveArray(HeapAllocator* allocator, ScratchArray* array, int size) throw()
{
    int capacity = array->capacity & 0x3fffffff;
    if (capacity < size)
    {
        int doubled = capacity * 2;
        int newCapacity = size < doubled ? doubled : size;
        FUN_00c908c0(allocator, array, newCapacity, 4);
    }
}
static __forceinline void fillWords(int* destination, int value, int count) throw()
{
    for (int index = 0; index < count; ++index)
        *destination++ = value;
}
static __forceinline void clearAndFree(HeapAllocator* allocator, ScratchArray* array) throw()
{
    array->count = 0;
    if (!(array->capacity & 0x80000000))
        allocator->release(array->data, (array->capacity & 0x3fffffff) * 4);
    array->data = 0;
    array->capacity = 0x80000000;
}
struct LocalArray : ScratchArray
{
    LocalArray(int size, int bytes) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        int* allocation = reserveScratch(bytes);
        data = allocation;
        capacity = size | 0x80000000;
        initial = allocation;
    }
    LocalArray(int size, int* output) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        ScratchAllocator* allocator = scratchState();
        int* allocation = reinterpret_cast<int*>(allocator->cursor);
        *output = (size * 4 + 127) & ~127;
        allocator->cursor += *output;
        data = allocation;
        capacity = size | 0x80000000;
        initial = allocation;
    }
    __forceinline void SetSizeAndGrow(int size, int value) throw()
    {
        reserveArray(scratchState()->heap, this, size);
        int num = size - count;
        int* destination = data + count;
        fillWords(destination, value, num);
        count = size;
    }
    __forceinline ~LocalArray() throw()
    {
        int* allocation = initial;
        if (allocation == data)
            count = 0;
        scratchState()->cursor = reinterpret_cast<unsigned char*>(allocation);
        clearAndFree(scratchState()->heap, this);
    }
};
static __forceinline void freeBuffer(HeapAllocator* allocator, void* data, unsigned int capacity) throw()
{
    if (!(capacity & 0x80000000))
        allocator->release(data, (capacity & 0x3fffffff) * 4);
}
template <class T> struct LocalBuffer
{
    T* data;
    int count;
    unsigned int capacity;
    LocalBuffer(int size, int bytes) throw()
    {
        count = size;
        data = reinterpret_cast<T*>(reserveScratch(bytes));
        capacity = size | 0x80000000;
    }
    __forceinline ~LocalBuffer() throw()
    {
        scratchState()->cursor = reinterpret_cast<unsigned char*>(data);
        freeBuffer(scratchState()->heap, data, capacity);
    }
    __forceinline T& operator[](int index) throw()
    {
        return data[index];
    }
};

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);

struct Vec4
{
    float x, y, z, w;
};
struct PivotVec;
struct __declspec(align(16)) V4A
{
    float x, y, z, w;
};
struct __declspec(align(16)) Qs
{
    V4A translation;
    V4A rotation;
    V4A scale;
};

struct Shape
{
    virtual int v0();
    virtual int v1();
};

struct Body : public Obj
{
    int unk10;
    Shape* shape;
};

struct List
{
    Body** items;
    int count;
};

// pdb: _isConstraintSupported | hkaRagdollUtils.obj | fnv360_0822_retail, call_gap, high (was: IsSupportedRagdollConstraint)
static __declspec(noinline) bool _isConstraintSupported(Obj* obj, bool reportError) throw()
{
    return obj->inner != 0 && reportError;
}

// pdb: _accessConstraintPivotA | hkaRagdollUtils.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_seq), high
static __declspec(noinline) Vec4* _accessConstraintPivotA(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    return (Vec4*)((char*)inner + (t <= 8 ? 0x20 : 0x50));
}

extern Qs* g_pivotXf;
static __declspec(noinline) int FUN_00ce9880(Qs* xf, Shape* shape) throw()
{
    g_pivotXf = xf;
    int s = shape->v0();
    s += shape->v1();
    return s;
}

struct A1W
{
    List* p;
    A1W(List* q) : p(q)
    {}
};
struct __declspec(align(16)) PivotVec
{
    float x, y, z, w;
    __m128 quad() const
    {
        return _mm_load_ps(&x);
    }
    void setQuad(__m128 q)
    {
        _mm_store_ps(&x, q);
    }
    void operator=(const PivotVec& v)
    {
        setQuad(v.quad());
    }
    void SetAllComponents(float a)
    {
        setQuad(_mm_set_ps1(a));
    }
    float lengthSquared3() const
    {
        __m128 x2 = _mm_mul_ps(quad(), quad());
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        float r;
        _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum));
        return r;
    }
};

struct __declspec(align(16)) PivotXform
{
    PivotVec m_vTranslation;
    PivotVec m_rotation;
    PivotVec m_vScale;
};

// @f3 0x0095e590 (community match, verified in this file)
static __declspec(noinline) bool FUN_0095e380(Obj* obj, bool reportError) throw()
{
    return obj->inner != 0 && reportError;
}

static __declspec(noinline) V4A* FUN_0095e420(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    return (V4A*)((char*)inner + (t <= 8 ? 0x20 : 0x50));
}

// pdb: moveRigidBodyPivot | hkaRagdollUtils.obj | fnv360_0822_retail, call_seq + skyrim(call_gap), high
static __declspec(noinline) int moveRigidBodyPivot(Qs* xf, Shape* shape) throw()
{
    g_pivotXf = xf;
    int s = (*(Shape* volatile*)&shape)->v0();
    s += (*(Shape* volatile*)&shape)->v1();
    return s;
}

int __cdecl FUN_00ce9db0(A1W constraints, void* warnOnAlignment)
{
    const int numConstraints = constraints.p->count;
    int result = 0;
    for (int c = 0; c < numConstraints; c++)
    {
        Body* constraint = constraints.p->items[c];
        if (!FUN_0095e380(constraint, true))
        {
            result = 1;
            continue;
        }
        V4A pivotInA = *FUN_0095e420(constraint);
        Qs childFromConstraint;
        childFromConstraint.rotation.x = 0.0f;
        childFromConstraint.rotation.y = 0.0f;
        childFromConstraint.rotation.z = 0.0f;
        _ReadWriteBarrier();
        Shape* shape = constraint->shape;
        childFromConstraint.rotation.w = 1.0f;
        childFromConstraint.scale.x = 1.0f;
        childFromConstraint.scale.y = 1.0f;
        childFromConstraint.scale.z = 1.0f;
        childFromConstraint.scale.w = 1.0f;
        childFromConstraint.translation.x = pivotInA.x;
        childFromConstraint.translation.y = pivotInA.y;
        childFromConstraint.translation.z = pivotInA.z;
        childFromConstraint.translation.w = pivotInA.w;
        volatile float lenSq = childFromConstraint.translation.z*childFromConstraint.translation.z + (childFromConstraint.translation.x*childFromConstraint.translation.x + childFromConstraint.translation.y*childFromConstraint.translation.y);
        if (lenSq > 1e-6f)
        {
            if (moveRigidBodyPivot(&childFromConstraint, shape) != 0)
                result = 1;
        }
    }
    return result;
}

