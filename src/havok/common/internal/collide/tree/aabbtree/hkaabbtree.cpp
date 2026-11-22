// havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp: ElemPool, Owner, RecordPool, MapD9 and more (2 functions)
#include "f3_common.h"
#include <xmmintrin.h>
// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/hkaabbtree.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    signed char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
};
#endif

struct Vec4 {
    __m128 m_vComponents;
    Vec4& operator=(const Vec4& o) { m_vComponents = o.m_vComponents; return *this; }
};

struct Key {
    int a;
    int b;
    Key& operator=(const Key& o) { a = o.a; b = o.b; a = o.a; return *this; }
};

struct IntArray {
    int* m_data;
    int m_iElementCount;
    int& back() { return m_data[m_iElementCount - 1]; }
    void popBack() { m_iElementCount--; }
    int GetLogicalSize() const { return m_iElementCount; }
};

struct UnsignedShortArray { unsigned short* elements; unsigned int count; unsigned int capacity; };
struct AllocationContext { int unknown00, unknown04, unknown08, unknown0c; void* memory; };
void __cdecl ResizeAudioStream(void* memory, UnsignedShortArray* buffer, unsigned int count);
struct Owner { int unknown00, unknown04, unknown08; UnsignedShortArray buffer; AllocationContext* FUN_00c85750(); unsigned short* AppendElement(unsigned short value); };
// Grows the buffer if it is full, appends value at the end, increments the count and returns a pointer to the stored element.
// @fnv 0x00d9bef0
unsigned short* Owner::AppendElement(unsigned short value) {
    UnsignedShortArray* pBuffer = &buffer;
    AllocationContext* context = FUN_00c85750();
    if (pBuffer->count == (pBuffer->capacity & 0x3fffffff))
        ResizeAudioStream(context->memory, pBuffer, 2);
    unsigned short* pElement = pBuffer->elements + pBuffer->count;
    *pElement = value;
    ++pBuffer->count;
    return pElement;
}

struct Allocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void* p, unsigned int bytes);
};

struct AllocHolder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Allocator* m_pThreadAllocator;
};

AllocHolder* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(Allocator* allocator, void** data, unsigned int capacity, unsigned int elemSize);

struct S_d9bf30_Rec {
    int unk0; int unk4; int unk8; int unkc;
    unsigned short unk10; unsigned short unk12;
};

struct S_d9bf30_Words {
    unsigned short* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
    void push(unsigned short v) {
        unsigned short* p = m_data + m_uiItemCount;
        for (int k = 0; k < 1; k++) p[k] = v;
        m_uiItemCount++;
    }
    __forceinline void refill(unsigned short newSize, int oldCount) {
        AllocHolder* holder = FUN_00c85750();
        Allocator* alloc = holder->m_pThreadAllocator;

        unsigned int cap = m_capFlags & 0x3fffffffu;
        if ((int)cap < (int)newSize) {
            unsigned int nc = cap + cap;
            if ((int)newSize >= (int)nc) {
                nc = newSize;
            }
            FUN_00c908c0(alloc, (void**)&m_data, nc, 2);
        }

        for (int i = (int)newSize - 1; i >= oldCount; --i) {
            push((unsigned short)i);
        }
    }
};

struct FUN_00d9bf30_cls {
    S_d9bf30_Rec* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
    S_d9bf30_Words m_free;

    void AllocateRecords(unsigned short newSize, S_d9bf30_Rec** out, unsigned short* idx);
};

namespace fnv_00d9c010 {
// ---------------------------------------------------------------------------
// ClearBuffers
//
// Releases the two growable buffers that the object owns and marks both of
// them empty again.
//
// Every buffer is described by a data pointer, the number of live items and
// the capacity that was reserved for it.  A capacity of 0x80000000 is the
// "empty" marker, a capacity with the sign bit set therefore means that
// nothing was reserved and nothing has to be released.
//
// The memory itself belongs to the audio sink that is reached through the
// thread local BSAudio instance; the number of bytes that is reported back
// to the sink is the masked capacity multiplied by the size of one item,
// because that is the number of bytes the sink handed out in the first
// place.  The release goes through the fifth entry of the sink's vtable.
// ---------------------------------------------------------------------------

// The sink that owns the memory of the streamed buffers.
struct AudioSink {
    virtual void* unk00();
    virtual void* unk04();
    virtual void* unk08();
    virtual void* unk0c();
    virtual void release(void* data, int size);
};

// The thread local audio system, the sink is its fifth member.
struct BSAudio {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioSink* m_sink;
};

// The thread local getter of the audio system (it is declared, not defined,
// because it lives in another translation unit).
BSAudio* __cdecl FUN_00c85750();

}  // namespace fnv_00d9c010

namespace fnv_00d9c090 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00d9c090

namespace fnv_00d9c280 {
// PopGlyphRecord - pops one 16-bit entry off the object's stack and returns the
// record it names.  The stack is refilled (in blocks of 0x80 records) by
// AllocateRecords when it runs empty.
//
// Object layout (from the disassembly):
//   +0x00  Glyph20* m_pRecords   array of 0x14-byte records
//   +0x04  int      m_nRecords   number of records
//   +0x08  int      m_capRecords record capacity
//   +0x0c  ushort*  m_pStackBuffer     array of 16-bit stack entries
//   +0x10  int      m_nStack     number of stack entries
//   +0x14  int      m_capStack   stack capacity

struct FUN_00d9bf30_cls {
    void __thiscall AllocateRecords(unsigned short index, int* outRecord, unsigned short* inChar);
};

}  // namespace fnv_00d9c280

namespace fnv_00d9c320 {

struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

}  // namespace fnv_00d9c320

namespace fnv_00d9c360 {
struct D9C360Allocator {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct D9C360MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D9C360Allocator* m_pStreamAllocator;

    D9C360Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D9C360MemoryRouter& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct D9C360Node {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_pChildAtom;
    int unk24;
    unsigned int m_flags;
    int m_sibling;
};

// hkInplaceArray<D9C360Node*, 128> without a destructor (Havok was built without EH).
struct D9C360NodeStack {
    D9C360Node** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    D9C360Node* m_kStorage[128];

    D9C360NodeStack() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(0x80000080) {}

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void AddBack(D9C360Node* n)
    {
        D9C360Allocator& alloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(D9C360Node*));
        m_data[m_iElementCount++] = n;
    }

    void release()
    {
        D9C360Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(D9C360Node*));
    }
};

}  // namespace fnv_00d9c360

struct S_00d9d650_Heap
{
    virtual void unkVfn0();
    virtual void unkVfn1();
    virtual void unkVfn2();
    virtual void unkVfn3();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00d9d650_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d9d650_Heap* m_pStreamAllocator;
    S_00d9d650_Heap& heap() { return *m_pStreamAllocator; }
};

namespace fnvc_adapt { S_00d9d650_Router& __cdecl FUN_00c85750(); }
void __cdecl FUN_00c908c0(S_00d9d650_Heap& alloc, void* array, int reqCapacity, int sizeElem);

template <typename T>
struct S_00d9d650_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00d9d650_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~S_00d9d650_Array() throw() { _clearAndDeallocate(fnvc_adapt::FUN_00c85750().heap()); }

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }

    void _clearAndDeallocate(S_00d9d650_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(S_00d9d650_Heap& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S_00d9d650_Heap& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n) { _setSize(fnvc_adapt::FUN_00c85750().heap(), n); }
};

struct S_00d9d650_Vector4
{
    __m128 m_vComponents;
    void operator=(const S_00d9d650_Vector4& v) { m_vComponents = v.m_vComponents; }
};

struct S_00d9d650_Aabb
{
    S_00d9d650_Vector4 m_kMinimumCorner;
    S_00d9d650_Vector4 m_kMaximumCorner;
};

struct S_00d9d650_Node
{
    S_00d9d650_Aabb m_kBounds;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    void setLeaf(int key)
    {
        m_20 = key;
        m_28 |= 0x80000000;
    }
};

void __cdecl AppendElement();

// @fnv 0x00d9c2d0
// pdb: hkString::strStr | hkString.obj | fnv360_0822_debug, objrun + bridge(caller_sim|call_gap) + skyrim(caller_sim), high
void __cdecl hkString_strStr(int param_1, unsigned short param_2) {
    AppendElement();
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setr_ps(float e0, float e1, float e2, float e3);
#endif

struct hkVector4 {
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& o) { m_vComponents = o.m_vComponents; return *this; }
    void set(float x, float y, float z, float w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
};

struct Range {
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    Range() : m_kPointA(0), m_kPointB(0), m_iThirdValue(0x80000000u) {}
};

inline void* operator new(unsigned int, void* p) { return p; }

template <class T> struct hkArray_d9c4 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void reserve(int n)
    {
        S_00d9d650_Heap& heap = fnvc_adapt::FUN_00c85750().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00c908c0(heap, this, n < cap2 ? cap2 : n, sizeof(T));
        }
    }
    static void construct(T* p, int n)
    {
        for (int i = 0; i < n; i++)
            new (p + i) T();
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
    __forceinline void pushBackUnchecked(const T& t)
    {
        T* p = &m_data[m_iElementCount];
        __assume(p != 0);
        new (p) T(t);
        m_iElementCount++;
    }
};

struct Handle_d9c4 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int m_pOwnerObject;
    int unk2C;
    Handle_d9c4() { m_pOwnerObject = 0; }
};

struct __declspec(align(16)) Block32 {
    __m128 m00;
    __m128 m10;
};

__declspec(noalias) void __stdcall FUN_00d9b240(int key, unsigned int* out);

struct __declspec(align(16)) S_00d9c180_Vec { float x, y, z, w; };

struct S_00d9c180_Arr { int m_data; int m_iElementCount; int m_cap; S_00d9c180_Arr() { m_data = 0; m_iElementCount = 0; m_cap = 0x80000000; } };

struct S_00d9c180_Base
{
    virtual void Reserved0();
};

struct __declspec(align(16)) FUN_00d9c180 : S_00d9c180_Base
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short unk14;
    unsigned short unk16;
    int unk18;
    S_00d9c180_Arr unk1C;
    S_00d9c180_Arr unk28;
    int unk34;
    int unk38;
    int unk3C;
    S_00d9c180_Vec unk40;
    S_00d9c180_Vec unk50;
    S_00d9c180_Vec unk60;
    S_00d9c180_Vec unk70;
    FUN_00d9c180(const S_00d9c180_Vec* a, const S_00d9c180_Vec* b, const S_00d9c180_Vec* c);
};
