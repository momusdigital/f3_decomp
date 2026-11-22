#include "f3_common.h"
// src/havok/common/serialize/packfile/hkpackfiledata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/hkpackfiledata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00e05950_class
{
    int* m_p;
    int m_auiShapeKeys;
    int m_uiItemCount;
    int FindFirstNonEmptySlot();
};

void* FUN_00c85750();

struct FUN_00e05250_Archive
{
    void** m_ppVirtualMethodTable;
    char m_auiShapeKeys[0x0c];
    unsigned char m_flag;
};

typedef void(__thiscall* FUN_00e05250_Write)(FUN_00e05250_Archive*, int, const char*, void*, int, int);

struct ByteSink
{
    void hkpMoppCodeGenerator_addCommand8(char a, char b);
};
struct E06C20Writer
{
    void FUN_00e069a0(int a, void* b);
};
struct FUN_00e06800_Class
{
    void hkpMoppCodeGenerator_addCommand16(int a, void* b);
};

struct FUN_00e06d70_Class
{
    char pad[0x10];
    void* m_pWriter;
    void WriteSize(unsigned int size);
};

// @fnv 0x00e06d70
// pdb: hkpMoppDefaultAssembler::addTermIdOffset | hkpMoppDefaultAssembler.obj | fnv360_0822_retail, objrun, medium
// pdb params: offset
void FUN_00e06d70_Class::WriteSize(unsigned int size)
{
    void* p = m_pWriter;
    if (size < 0x100)
        ((ByteSink*)p)->hkpMoppCodeGenerator_addCommand8(9, (char)size);
    else if (size < 0x10000)
        ((FUN_00e06800_Class*)p)->hkpMoppCodeGenerator_addCommand16(0xa, (void*)size);
    else
        ((E06C20Writer*)p)->FUN_00e069a0(0xb, (void*)size);
}

struct hkAllocatorE054;

struct hkMemoryRouterE054
{
    void* m_apvUnk00[4];
    hkAllocatorE054* m_pkHeap;
    hkAllocatorE054& heap()
    {
        return *m_pkHeap;
    }
};
void __cdecl FUN_00c908c0(hkAllocatorE054& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
inline void __cdecl operator delete(void*, void*) throw()
{}

template <typename T> __forceinline T min2E054(T x, T y)
{
    return x < y ? x : y;
}

template <typename T> __forceinline void copyE054(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <typename T> __forceinline void constructWithArrayE054(T* dst, int n, const T* src)
{
    for (int i = 0; i < n; i++)
        new (dst + i) T(src[i]);
}

template <typename T> struct hkArrayE054
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(hkAllocatorE054& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline void _copyFromArray(hkAllocatorE054& kAlloc, const hkArrayE054<T>& a)
    {
        const int iOldSize = m_iElementCount;
        int iNewSize = a.m_iElementCount;
        int iCopiedSize = (iNewSize > iOldSize) ? iOldSize : iNewSize;
        GrowArrayCapacity(kAlloc, iNewSize);
        copyE054<T>(m_data, a.m_data, iCopiedSize);
        constructWithArrayE054<T>(m_data + iCopiedSize, iNewSize - iCopiedSize, a.m_data + iCopiedSize);
        m_iElementCount = iNewSize;
    }
    __forceinline hkArrayE054& operator=(const hkArrayE054<T>& a)
    {
        _copyFromArray(((hkMemoryRouterE054*)FUN_00c85750())->heap(), a);
        return *this;
    }
};

struct hkBoolE055
{
    char m_bValue;
    hkBoolE055()
    {}
};

struct hkPointerMapPairE055
{
    unsigned long m_uiKey;
    unsigned long m_uiCurrentValue;
};

struct hkPointerMapE055 : public FUN_00e05950_class
{
    int isValid(int iIt) const
    {
        return iIt <= m_uiItemCount;
    }
    int getNext(int iIt) const
    {
        int i = iIt;
        for (i += 1; i <= m_uiItemCount; ++i)
        {
            if (((hkPointerMapPairE055*)m_p)[i].m_uiKey != (unsigned long)-1)
                break;
        }
        return i;
    }
    unsigned long GetIteratorKey(int iIt) const
    {
        return ((hkPointerMapPairE055*)m_p)[iIt].m_uiKey;
    }
    unsigned long getValue(int iIt) const
    {
        return ((hkPointerMapPairE055*)m_p)[iIt].m_uiCurrentValue;
    }
};

extern "C" const void* DAT_010ea51c;

void* FUN_00c85750();
void __cdecl FUN_00c856c0(void* heap, void* ptr);

struct hkMemoryAllocator
{
    virtual void func0() = 0;
    virtual void func4() = 0;
    virtual void ReleaseBlock(void* ptr, int numBytes) = 0;
    virtual void funcC() = 0;
    virtual void deallocateChunk(void* ptr, int numBytes) = 0;
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease(hkMemoryAllocator* alloc)
    {
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc->deallocateChunk(this->m_data, (cap & 0x3fffffff) * sizeof(T));
        }
        this->m_data = 0;
        this->m_iCapacityState = 0x80000000;
    }
};

struct Map1Type
{
    void* m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    void ProcessArgument(void* heap);
    void FUN_00a29680();

    void ClearAndRelease()
    {
        NineIntegerRecord* router = (NineIntegerRecord*)FUN_00c85750();
        this->ProcessArgument(router->m_pStreamAllocator);
        this->FUN_00a29680();
    }
};

class FUN_00e057c0
{
  public:
    ~FUN_00e057c0() throw();
};

class hkMemoryAllocatorXe05970
{
  public:
    virtual ~hkMemoryAllocatorXe05970() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterXe05970
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXe05970* m_pStreamAllocator;

    hkMemoryAllocatorXe05970& heap()
    {
        return *m_pStreamAllocator;
    }
};

class hkObje05970 : public FUN_00e057c0
{
  public:
    hkObje05970* FUN_00e05970(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        static_cast<hkMemoryRouterXe05970*>(FUN_00c85750())
            ->heap()
            .ReleaseBlock(p, static_cast<hkObje05970*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

struct Crux53_HkRouter
{
    int unk00, unk04, unk08, unk0c;
    void* heap;
};
void* FUN_00c85750();
void __cdecl FUN_00c856c0(void* heap, void* ptr);
inline void Crux53_FreeName(char* existing)
{
    Crux53_HkRouter* router = (Crux53_HkRouter*)FUN_00c85750();
    FUN_00c856c0(router->heap, existing);
}
struct Crux53_Named
{
    int unk00, unk04, unk08;
    char* name;
    void SetName(const char* newName);
};
// Frees the current name string and assigns the result of FUN_00cb1410(newName).
// @f3 0x00a49b80 (community match, verified in this file)
typedef void* (__stdcall *TlsGetter366)(unsigned long index);
extern TlsGetter366 DAT_00d9b080;
namespace NameHeap366 {
extern unsigned long DAT_010f3170;
struct Heap { void FUN_008f6f90(void* memory); };
}
char* __cdecl FUN_00923640(const char* text);
struct NamedLayout366 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    char* name;
};
void Crux53_Named::SetName(const char* newName) {
    NamedLayout366* actual = reinterpret_cast<NamedLayout366*>(this);
    char* previous = actual->name;
    NameHeap366::Heap* heap = static_cast<NameHeap366::Heap*>(DAT_00d9b080(NameHeap366::DAT_010f3170));
    heap->FUN_008f6f90(previous);
    actual->name = FUN_00923640(newName);
}


template <int SIZE> __forceinline void memCpyOneAlignedE051(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

template <class T> class hkArrayE051
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpyOneAlignedE051<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

namespace fnv_00e051e0 {

template <unsigned int SIZE> inline void memCpyOneAlignedE051(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < (int)(SIZE / 4));
}

template <class T> class hkArrayE051
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpyOneAlignedE051<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

}  // namespace fnv_00e051e0

extern "C" const void* DAT_010ea51c;

struct S00e05700_Arr
{
    void* m_data;
    int m_iElementCount;
    int m_capFlags;

    void reset(int capFlags)
    {
        m_data = 0;
        m_iElementCount = 0;
        m_capFlags = capFlags;
    }
};
