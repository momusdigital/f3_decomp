#include "f3_common.h"
// src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppcodegenerator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/assembler/hkpmoppcodegenerator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    void* __cdecl FUN_00c85750(void);
    void __cdecl FUN_00c856c0(void*, void*);
}
struct Buffer
{
    void* data;
    int size;
    unsigned int capacity;
    __forceinline void clear(void* allocator)
    {
        unsigned int flags = capacity;
        size = 0;
        if ((flags & 0x80000000u) == 0)
        {
            typedef void(__thiscall * FreeFn)(void*, void*, unsigned int);
            FreeFn freeFn = (FreeFn) * (void**)((char*)*(void**)allocator + 0x10);
            freeFn(allocator, data, (flags & 0x3fffffffu) * 8);
        }
        data = 0;
        capacity = 0x80000000u;
    }
};

struct E06490Allocator;

struct E06490MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E06490Allocator* m_pStreamAllocator;

    E06490Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

void __cdecl FUN_00c856c0(E06490Allocator* alloc, void* p);
extern "C" void __cdecl FUN_00cb1280(void* dst, int c, int n);
extern "C" void __cdecl FUN_00cb1260(void* dst, const void* src, int nbytes);

struct E06490Stack
{
    int unk00;
    int unk04;
    int m_pRayCursor;
    int unk0C;
    char* m_buffer;

    void hkpMoppCodeGenerator_resize();
};

// @f3 0x00a85cb0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall* FUN_00d9b080)(unsigned long);

struct FUN_008f6f60_obj
{
    void* FUN_008f6f60(int numBytes, int tag);
    void FUN_008f6f90(void* p);
};

// pdb: hkpMoppCodeGenerator::resize | hkpMoppCodeGenerator.obj | fnv360_0822_retail, call_seq, high
// pdb: hkpMoppCodeGenerator::resize | hkpMoppCodeGenerator.obj | fnv360_0822_retail, call_seq, high (was: GrowBuffer)
void E06490Stack::hkpMoppCodeGenerator_resize()
{
    void* (__stdcall* tlsGetValue)(unsigned long) = FUN_00d9b080;
    int newCapacity = m_pRayCursor * 2;
    FUN_008f6f60_obj* heap = (FUN_008f6f60_obj*)tlsGetValue(DAT_010f3170);
    char* newBuffer = (char*)heap->FUN_008f6f60(newCapacity, 0x28);
    FUN_00cb1280(newBuffer, 0xcd, m_pRayCursor);
    FUN_00cb1260(newBuffer + m_pRayCursor, m_buffer, m_pRayCursor);
    char* oldBuffer = m_buffer;
    m_pRayCursor *= 2;
    FUN_008f6f60_obj* heap2 = (FUN_008f6f60_obj*)tlsGetValue(DAT_010f3170);
    heap2->FUN_008f6f90(oldBuffer);
    m_buffer = newBuffer;
}


struct hkMemoryAllocatorE06;

struct hkThreadMemoryE06
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE06* m_pkHeap;
};

extern "C" hkThreadMemoryE06& __cdecl hkThreadMemoryInstanceE06() throw();
void* __cdecl hkAllocateE06(hkMemoryAllocatorE06* pkHeap, int iNumBytes) throw();

template <class T> class hkArrayE06
{
  public:
    hkArrayE06() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkReferencedObjectE06
{
  public:
    hkReferencedObjectE06() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectE06();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00e065f0 : public hkReferencedObjectE06
{
  public:
    FUN_00e065f0(int iSize);
    virtual ~FUN_00e065f0();

    int m_uiLogicalSize;
    int m_iUsed;
    void* m_pData;
    hkArrayE06<int> m_kArray;
};

// @fnv 0x00e065f0
FUN_00e065f0::FUN_00e065f0(int iSize)
{
    hkMemoryAllocatorE06* pkHeap = hkThreadMemoryInstanceE06().m_pkHeap;
    m_pData = hkAllocateE06(pkHeap, iSize);
    m_uiLogicalSize = iSize;
    m_iUsed = 0;
}

#include <xmmintrin.h>
extern "C" void __cdecl FUN_00c908c0(void* heap, void* arr, int n, int elemSize);
extern "C" void __cdecl FUN_00cb1260(void* dst, const void* src, int n);

struct S_00e064f0_Heap
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int n);
};

struct S_00e064f0_Router
{
    int unk00, unk04, unk08, unk0C;
    S_00e064f0_Heap* m10;
    static S_00e064f0_Router& GetMonitorStream()
    {
        return *(S_00e064f0_Router*)FUN_00c85750();
    }
    S_00e064f0_Heap& heap()
    {
        return *m10;
    }
};

struct S_00e064f0_Arr
{
    char* m_data;
    int m_iElementCount;
    unsigned m_cap;
    S_00e064f0_Arr() throw()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
    void reserveExactly(int n)
    {
        S_00e064f0_Router& r = S_00e064f0_Router::GetMonitorStream();
        if ((int)(m_cap & 0x3fffffff) < n)
            FUN_00c908c0(r.m10, this, n, 1);
    }
    __forceinline void GrowArrayCapacity(S_00e064f0_Heap& a, int n)
    {
        int c = m_cap & 0x3fffffff;
        if (c < n)
        {
            int dbl = c * 2;
            FUN_00c908c0(&a, this, (n < dbl) ? dbl : n, 1);
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(S_00e064f0_Router::GetMonitorStream().heap(), n);
        m_iElementCount = n;
    }
};

struct S_00e064f0_Ref
{
    virtual void vfn00();
    short m_usAllocationSize;
    short m_ref;
    static void* operator new(unsigned n)
    {
        char* p = (char*)S_00e064f0_Router::GetMonitorStream().heap().AllocateMemoryBlock(n);
        *(short*)(p + 4) = (short)n;
        return p;
    }
    static void operator delete(void*)
    {}
    S_00e064f0_Ref() throw()
    {
        m_ref = 1;
    }
};

struct S_00e064f0_Obj : S_00e064f0_Ref
{
    int unk08, unk0C;
    __m128 m10;
    S_00e064f0_Arr m_aiIndexedValues;
    char m2c;
    S_00e064f0_Obj() throw()
    {
        m10 = _mm_setzero_ps();
        m2c = 2;
    }
    virtual void vfn00();
};

namespace fnv_00e066c0 {
struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00e066c0

// @f3 0x00a85c40 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
namespace f3m_00a85c40 {
struct hkMemAllocStandIn
{
    void* FUN_008f6f60(int iNumBytes, int iAlign);
};
class FUN_00e065f0 : public hkReferencedObjectE06
{
  public:
    FUN_00e065f0(int iSize);
    virtual ~FUN_00e065f0();

    int m_uiLogicalSize;
    int m_iUsed;
    void* m_pData;
};
// pdb: hkpMoppCodeGenerator::hkpMoppCodeGenerator | hkpMoppCodeGenerator.obj | fnv360_0822_retail, call_gap, medium
// pdb params: size
FUN_00e065f0::FUN_00e065f0(int iSize)
{
    hkMemAllocStandIn* pkHeap = reinterpret_cast<hkMemAllocStandIn*>(TlsGetValue(DAT_010f3170));
    m_pData = pkHeap->FUN_008f6f60(iSize, 0x28);
    m_uiLogicalSize = iSize;
    m_iUsed = 0;
}
FUN_00e065f0::~FUN_00e065f0()
{
}
}   // namespace f3m_00a85c40
