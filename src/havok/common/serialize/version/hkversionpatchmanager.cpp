#include "f3_common.h"
// src/havok/common/serialize/version/hkversionpatchmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/version/hkversionpatchmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* __cdecl FUN_00cb1410(unsigned int);

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct GraphEntry
{
    void* m_pKey;
    int m_iNext;
};

struct GraphTable
{
    GraphEntry* m_pEntries;

    int LookupWithDefault(void* apKey);
};

struct DepthLimit
{
    int unk00;
    int unk04;
    int m_iLimit;

    int FindSlot(void* apItem);
    void FUN_00cb1870(void* apAllocator, void* apItem, int aiFlag);
};

// @f3 0x009407f0 (community match, verified in this file)
struct FUN_00db7e70_Node
{
    int unk00;
    int unk04;
};

class hkClass;
class hkStatisticsCollector;
// hkPackfileReader: Fallout 3's vtable has 12 slots (0x00e86494). Names and order are those of the Havok classes in the
// Just Death PC PDB (2016, proto_justdeath), which has one slot more, getTopLevelObject between getLoadedObjects and
// getUpdateTracker; the calls here fit the shorter order (the array size test on getLoadedObjects, the version string
// compared with the current one and then set).
struct FUN_00db7e70_Obj
{
    virtual ~FUN_00db7e70_Obj();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual int loadEntireFile(void* reader);
    virtual void* getContentsWithRegistry(const char* className, const void* registry);
    virtual void* getContents(const char* className);
    virtual const char* getContentsClassName() const;
    virtual FUN_00db7e70_Node* getLoadedObjects() const;
    virtual int getUpdateTracker() const;
    virtual int getContentsVersion() const;
    virtual void setContentsVersion(int version);
};

int __cdecl FUN_0093e470();
int __cdecl hkString_strCmp(int aiA, int aiB);
int __cdecl FUN_009406e0(FUN_00db7e70_Node* apNode, int aiResult, void* apItem, int aiA, int aiB);

int __cdecl FUN_00db7e70(void* apTarget, void* apItem, GraphTable* apTable, DepthLimit* apDepth)
{
    FUN_00db7e70_Obj* pObj = reinterpret_cast<FUN_00db7e70_Obj*>(apTarget);
    int iA = pObj->getContentsVersion();
    int iB = FUN_0093e470();
    if (hkString_strCmp(iA, iB) != 0)
    {
        FUN_00db7e70_Node* pNode = pObj->getLoadedObjects();
        if (pNode->unk04 != 0 && FUN_009406e0(pNode, pObj->getUpdateTracker(), apItem, iA, iB) == 0)
        {
            pObj->setContentsVersion(iB);
            return 0;
        }
        return 1;
    }
    return 0;
}


namespace fnv_00db8540 {
struct AudioAllocator
{
    virtual void v00();
    virtual void* Allocate(unsigned int auiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct ByteTag
{
    char m_cValue;

    ByteTag() : m_cValue(0)
    {}

    ~ByteTag()
    {}
};

struct ArrayHeader
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ArrayHeader() : m_pData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {}
};

struct PoolHolder
{
    void* m_p00;
    int m_i04;
    int m_i08;

    PoolHolder() : m_p00(0), m_i04(0), m_i08(-1)
    {}

    void ResizeToFit(AudioAllocator* apAllocator, int aiFlag);
};

}  // namespace fnv_00db8540

namespace fnv_00dbe710 {
struct S_00dbe710_Allocator;
struct S_00dbe710_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dbe710_Allocator* m_pStreamAllocator;
    S_00dbe710_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00dbe710_Router* FUN_00c85750();
void ResizeAudioStream(S_00dbe710_Allocator* alloc, void* arr, int elemSize);

}  // namespace fnv_00dbe710

// FindEntry (0x00db7de0, 134 bytes)
//
// Walks a spatial index: it asks the index object (embedded at this+0x18) for
// the next candidate, looks the entry up in the table at this+0x0c, optionally
// validates it and then hands it to the owner object at this+0x08, which
// returns the key that is used to ask the index for the next candidate.
//
// NOTE: FUN_00db7d60 is only DECLARED in the original translation unit, but
// the original code keeps the "key" value in EDX across the call to it (the
// original callee happens to leave the key in EDX).  To make MSVC 2008 pick
// the same register the helper is given a stand-in body that does not touch
// EDX and is marked __declspec(noinline) so that the call is not inlined.

class BDBA270Allocator;

void __cdecl FUN_00c908c0(BDBA270Allocator& kAlloc, void* apvArray, int iReqCapacity, int iElementSize);

inline void* __cdecl operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}

struct BDBA270Element
{
    int m_iA;
    int m_iB;
    int m_iC;
    int m_iD;
};

class BDBA270Array
{
  public:
    BDBA270Element* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void Splice(BDBA270Allocator& kAlloc, int iIndex, int iNumToDel, const BDBA270Element* pkItems, int iNumToInsert);
};

struct DB7F50Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct DB7F50MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DB7F50Allocator* m_pStreamAllocator;

    DB7F50Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" DB7F50MemoryRouter& __cdecl FUN_00c85750() throw();
}

template <class T> struct DB7F50Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~DB7F50Array() throw()
    {
        DB7F50Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace fnv_00db83c0 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& tempHeap()
    {
        return *unk0c;
    }
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
namespace fnvc_adapt {
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();
}
inline AudioMgr* audio()
{
    return (AudioMgr*)fnvc_adapt::FUN_00c85750();
}

__declspec(nothrow) void __cdecl ResizeAudioStream(void*, void*, int);

inline void constructWithCopy(int* p, int n, const int& t)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}
struct hkIntArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void AddBack(const int& e)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(int));
        constructWithCopy(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

}  // namespace fnv_00db83c0

namespace fnv_00db85e0 {
struct DB85E0Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct DB85E0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DB85E0Allocator* m_pStreamAllocator;

    DB85E0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" DB85E0MemoryRouter& __cdecl FUN_00c85750();
}

struct DB85E0Impl
{
    ~DB85E0Impl();

    static void operator delete(void* p, unsigned int nbytes)
    {
        fnvc_adapt::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }

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
};

struct DB85E0MapBase
{
    ~DB85E0MapBase();

    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};

struct DB85E0Map : DB85E0MapBase
{
    void ClearAndRelease(DB85E0Allocator& alloc);
    __forceinline ~DB85E0Map()
    {
        ClearAndRelease(fnvc_adapt::FUN_00c85750().heap());
    }
};

struct DB85E0IntArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~DB85E0IntArray()
    {
        DB85E0Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(int));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class DB85E0ReferencedObject
{
  public:
    virtual ~DB85E0ReferencedObject() throw()
    {}

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

}  // namespace fnv_00db85e0

namespace fnv_00dba1e0 {
struct DBA1E0Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct DBA1E0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DBA1E0Allocator* m_pStreamAllocator;

    DBA1E0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" DBA1E0MemoryRouter& __cdecl FUN_00c85750();
}

class DBA1E0ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        DBA1E0ReferencedObject* b =
            static_cast<DBA1E0ReferencedObject*>(fnvc_adapt::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~DBA1E0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

}  // namespace fnv_00dba1e0

namespace fnv_00db95c0 {
// Reordered source-vector loop and allocator acquisition; official check pending.
extern "C" void* __cdecl FUN_00cb1410(unsigned int);
struct AllocObj
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void Free(void* p, int sz) throw();
};
void __cdecl FUN_00c908c0(AllocObj* a, void* arr, int sz, int elem) throw();
void __cdecl ResizeAudioStream(AllocObj* a, void* arr, int elem) throw();
struct VecP
{
    void** m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void release(AllocObj& allocator, int elementBytes)
    {
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            allocator.Free(m_pData, (m_iCapacity & 0x3fffffff) * elementBytes);
    }

    ~VecP() throw()
    {
        DB7F50Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            alloc.ReturnMemory(m_pData, (m_iCapacity & 0x3fffffff) * 4);
        m_pData = 0;
        m_iCapacity = (int)0x80000000;
    }
};
struct VecPair
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void release(AllocObj& allocator, int elementBytes)
    {
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            allocator.Free(m_pData, (m_iCapacity & 0x3fffffff) * elementBytes);
    }

    ~VecPair() throw()
    {
        DB7F50Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            alloc.ReturnMemory(m_pData, (m_iCapacity & 0x3fffffff) * 8);
        m_pData = 0;
        m_iCapacity = (int)0x80000000;
    }
};
struct Vec16
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void release(AllocObj& allocator, int elementBytes)
    {
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            allocator.Free(m_pData, (m_iCapacity & 0x3fffffff) * elementBytes);
    }

    ~Vec16() throw()
    {
        DB7F50Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            alloc.ReturnMemory(m_pData, (m_iCapacity & 0x3fffffff) * 16);
        m_pData = 0;
        m_iCapacity = (int)0x80000000;
    }
};
struct ClassMember
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
struct IndexedMemberArray
{
    ClassMember* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    IndexedMemberArray() throw()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = (int)0x80000000;
    }
    ~IndexedMemberArray() throw()
    {
        DB7F50Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(ClassMember));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct ObjCB
{
    void* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void ResizeToFit(AllocObj* a, int b) throw();
    int FUN_00cb1c60(unsigned __int64 key) throw();
    void InsertKeyValue(AllocObj* a, unsigned __int64 key, __int64 value) throw();
    void FUN_00cb1e40(AllocObj* a) throw();
    void FUN_00a29680() throw();
};
struct StrX
{
    int m_00;
    void FUN_00dba650(void* a) throw();
    int FUN_00dba670() throw();
    void FUN_00dba660() throw();
};
struct HelperX
{
    int m_00;
    int m_04;
    int m_08;
    void FUN_00dc8030() throw();
    void FUN_00dc8080() throw();
    void* FUN_00dc7300(int a) throw();
    void FUN_00dc8270(void* a) throw();
    void* CreateItem(void* a) throw();
    void FUN_00dc7390(void* a) throw();
    void FUN_00dc73f0(StrX* a, int b, int c) throw();
    void FUN_00dc7d20(StrX* a, int b, int c, int d, int e) throw();
    void FUN_00dc7600(StrX* a, int b) throw();
    void AssignRefCountedSlot(StrX* a, StrX* b) throw();
    void ReleaseRef(StrX* a) throw();
    void FUN_00dc7320(StrX* a, int b) throw();
    void FUN_00dc72e0(StrX* a, int b) throw();
};
struct ClassWorld : HelperX
{
    ClassWorld() throw()
    {
        FUN_00dc8030();
    }
    ~ClassWorld() throw()
    {
        FUN_00dc8080();
    }
};
struct PointerMap : ObjCB
{
    PointerMap() throw()
    {
        m_pData = 0;
        m_iArrayLength = 0;
        m_iCapacity = -1;
        AudioHolder* holder = (AudioHolder*)&fnvc_adapt::FUN_00c85750();
        ResizeToFit((AllocObj*)holder->m_pAllocator, 0);
    }
    ~PointerMap() throw()
    {
        FUN_00cb1e40((AllocObj*)fnvc_adapt::FUN_00c85750().m_pStreamAllocator);
        FUN_00a29680();
    }
};
}  // namespace fnv_00db95c0

extern "C" void* __cdecl FUN_00cb1410(unsigned int);

namespace fnv_00dba4d0 {
struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, void* list, unsigned int elemSize);

}  // namespace fnv_00dba4d0

namespace fnv_00dba580 {
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
}  // namespace fnv_00dba580

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

extern "C" void _ReadWriteBarrier(void);
void __cdecl ResizeAudioStream(AudioAllocator* apAllocator, void* apContainer, unsigned int auiElemSize);

extern "C" void _ReadWriteBarrier(void);
extern "C" void __cdecl ResizeAudioStream(void* alloc, void* vec, unsigned int n);
