#include "f3_common.h"
// src/havok/common/serialize/packfile/binary/hkbinarypackfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/binary/hkbinarypackfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalObjectO2_00d472a0
{
    int x;
};
extern GlobalObjectO2_00d472a0 g_0126ca58;
extern GlobalObjectO2_00d472a0 g_0126ca88;
extern GlobalObjectO2_00d472a0 g_0126cab8;
extern GlobalObjectO2_00d472a0 g_0126cae8;
extern int DAT_011b7a7c;
extern int DAT_011b7aec;
extern void* DAT_010d65bc;
struct FUN_00dbdf30_s
{
    void hkPackfileWriter_setSectionForClass(GlobalObjectO2_00d472a0*, int);
};
struct FUN_00dbc670
{
    void* m_vft;
    void FUN_00dbdef0(int);
    FUN_00dbc670();
};
extern void FUN_00dbe4d0();
// Calls FUN_00dbe4d0, sets m_vft, then calls FUN_00dbdef0 and hkPackfileWriter_setSectionForClass on four global objects with DAT_011b7aec.
// @fnv 0x00dbc670
FUN_00dbc670::FUN_00dbc670()
{
    FUN_00dbe4d0();
    m_vft = &DAT_010d65bc;
    FUN_00dbdef0(DAT_011b7a7c);
    ((FUN_00dbdf30_s*)this)->hkPackfileWriter_setSectionForClass(&g_0126cae8, DAT_011b7aec);
    ((FUN_00dbdf30_s*)this)->hkPackfileWriter_setSectionForClass(&g_0126ca58, DAT_011b7aec);
    ((FUN_00dbdf30_s*)this)->hkPackfileWriter_setSectionForClass(&g_0126cab8, DAT_011b7aec);
    ((FUN_00dbdf30_s*)this)->hkPackfileWriter_setSectionForClass(&g_0126ca88, DAT_011b7aec);
}

// @fnv 0x00dbd720
// pdb: `anonymous namespace'::getArraySizeInBytes<class hkPackfileSectionHeader> | hkBinaryPackfileWriter.obj | tesv_win, call_seq, medium
unsigned int __cdecl FUN_00dbd720(unsigned int arg)
{
    return *reinterpret_cast<unsigned int*>(arg + 4) * 3 * 16;
}

struct CallbackTarget
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void Send(void* value);
};
struct FUN_00dbd730_class
{
    int unk00;
    int unk04;
    CallbackTarget* target;
    void* ForwardToTarget(void* value);
};
// @fnv 0x00dbd730
// pdb: hkOArchive::isOk | hkOArchive.obj | fnv360_0822_retail, call_seq, high
void* FUN_00dbd730_class::ForwardToTarget(void* value)
{
    target->Send(value);
    return value;
}

class hkClass;
class hkStatisticsCollector;
// hkBool: a class with a constructor, so it comes back through a hidden result pointer.
struct SubStreamBool
{
    char m_bool;
    SubStreamBool(bool b) : m_bool((char)b) {}
};
// hkStreamWriter: the slots of the Fallout 3 hkSubStreamWriter vtable (0x00e800c0) up to seekTellSupported, named as
// the New Vegas Xbox 360 PDB names them.
struct S_00dbd770_Inner
{
    virtual ~S_00dbd770_Inner();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual SubStreamBool isOk() const;
    virtual int write(const void* buf, int nbytes);
    virtual void flush();
    virtual SubStreamBool seekTellSupported() const;
};

// hkSubStreamWriter
struct S_00dbd770
{
    int unk0;
    int unk4;
    S_00dbd770_Inner* m_childStream;  // +0x08
    SubStreamBool hkSubStreamWriter_seekTellSupported() const;
};

// @fnv 0x00dbd770
// pdb: hkSubStreamWriter::seekTellSupported | hkBinaryPackfileWriter.obj | fnv360_0822_retail, vtable, high
// pdb: hkSubStreamWriter::seekTellSupported | hkBinaryPackfileWriter.obj | fnv360_0822_retail, vtable, high (was: ForwardToInner)
SubStreamBool S_00dbd770::hkSubStreamWriter_seekTellSupported() const
{
    return m_childStream->seekTellSupported();
}

struct Inner
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual int f8();
};
struct FUN_00dbd7d0_Class
{
    int unk00;
    int unk04;
    Inner* object;
    int offset;
    int GetAdjustedValue();
};
// @fnv 0x00dbd7d0
// pdb: hkSubStreamWriter::tell | hkBinaryPackfileWriter.obj | tesv_win, vtable, medium
int FUN_00dbd7d0_Class::GetAdjustedValue()
{
    return object->f8() - offset;
}

struct Triple
{
    int x;
    int y;
    int z;
    Triple() : x(0), y(0), z(0x80000000)
    {}
};
struct FUN_00dbd870
{
    Triple first;
    Triple second;
    Triple third;
    Triple fourth;
    int trailing;
    FUN_00dbd870();
};
// Default-constructs four Triple members and sets trailing to 0.
// @fnv 0x00dbd870
// pdb: hkRelocationInfo::hkRelocationInfo | hkDeepCopier.obj | tesv_win, hash, low
FUN_00dbd870::FUN_00dbd870() : trailing(0)
{}

struct FUN_00dbc6f0_cls_callee
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Write(void* apNode, int aiValue);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int Count();
};

struct FUN_00dbc6f0_cls_store
{
    int unk00;
    void Store(void* apNode, int aiDiff);
};

struct FUN_00dbc6f0_cls_owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_00dbc6f0_cls_callee* m_pCallee;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    FUN_00dbc6f0_cls_store m_store;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    unsigned char m_byReverse;
};

struct FUN_00dbc6f0_cls_source
{
    int Lookup(int aiFlag);
    void* Resolve();
};

struct FUN_00dbc6f0_cls_key
{
    int m_iValue;
    unsigned char m_byTag;
};

int __cdecl hkString_strLen(void* apNode);

typedef void(__thiscall* S_WriteFn)(FUN_00dbc6f0_cls_callee*, void*, int);

static inline void S_Swap(unsigned char& a, unsigned char& b)
{
    unsigned char t = a;
    a = b;
    b = t;
}

static inline int S_Rev(int v)
{
    unsigned char* p = (unsigned char*)&v;
    S_Swap(p[0], p[3]);
    S_Swap(p[1], p[2]);
    return v;
}

// @fnv 0x00dbc6f0
// pdb: hkBinaryPackfileWriter::writeClassName | hkBinaryPackfileWriter.obj | fnv360_0822_retail, caller_sim, high
// pdb params: context, k, absoluteDataStart
// pdb: hkBinaryPackfileWriter::writeClassName | hkBinaryPackfileWriter.obj | fnv360_0822_retail, caller_sim, high (was: WriteNodeDiff)
void __stdcall hkBinaryPackfileWriter_writeClassName(FUN_00dbc6f0_cls_owner* apOwner, FUN_00dbc6f0_cls_source* apSource, int aiDiff)
{
    int x = apSource->Lookup(0);
    if (apOwner->m_byReverse != 0)
        x = S_Rev(x);
    FUN_00dbc6f0_cls_key key;
    key.m_iValue = x;
    key.m_byTag = 9;
    apOwner->m_pCallee->Write(&key, 5);
    void* pNode = apSource->Resolve();
    int iDiff = apOwner->m_pCallee->Count() - aiDiff;
    apOwner->m_store.Store(pNode, iDiff);
    void** pVtable = *(void***)apOwner->m_pCallee;
    ((S_WriteFn)pVtable[4])(apOwner->m_pCallee, pNode, hkString_strLen(pNode) + 1);
}

// hkStreamWriter, up to flush (Fallout 3 vtables, PDB names).
struct Target
{
    virtual ~Target();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual SubStreamBool isOk() const;
    virtual int write(const void* buf, int nbytes);
    virtual void flush();
};

struct FUN_00dbd760_cls
{
    int unk00;
    int unk04;
    Target* m_08;
    void hkOstream_flush();
};

// @fnv 0x00dbd760
// pdb: hkOstream::flush | hkOStream.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void FUN_00dbd760_cls::hkOstream_flush()
{
    m_08->flush();
}

struct S_00dbd790_Obj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(int a, int b);
};
struct S_00dbd790_Class
{
    int unk00;
    int unk04;
    S_00dbd790_Obj* object;
    int offset;
    void hkSubStreamWriter_seek(int a, int b);
};
// Calls the object's f7 virtual method, passing a plus offset when b is zero and a otherwise, along with b.
// @fnv 0x00dbd790
// pdb: hkSubStreamWriter::seek | hkBinaryPackfileWriter.obj | fnv360_0822_retail, vtable, high
// pdb params: offset, whence
// pdb: hkSubStreamWriter::seek | hkBinaryPackfileWriter.obj | fnv360_0822_retail, vtable, high (was: DispatchToObject)
void S_00dbd790_Class::hkSubStreamWriter_seek(int aiValue, int b)
{
    object->f7(b == 0 ? aiValue + offset : aiValue, b);
}

extern void* FUN_00c85750();
extern void __cdecl ResizeAudioStream(void* allocator, void* vec, unsigned int elemSize);

struct S_00dbd8a0_Sub
{
    char unk0;
    char unk1;
};

struct S_00dbd8a0_Arg
{
    int unk00;
    S_00dbd8a0_Sub unk04;
};

struct S_00dbd8a0_Byte
{
    char c;
    S_00dbd8a0_Byte(char v) : c(v)
    {}
};

struct S_00dbd8a0_Mem20
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dbd8a0_Mem20(S_00dbd8a0_Sub* p);
};

struct S_00dbd8a0_Mem30
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dbd8a0_Mem30(S_00dbd8a0_Byte b);
};

extern char DAT_011b7b89;

struct FUN_00dbd8a0
{
    S_00dbd8a0_Arg* unk00;
    Triple first;
    Triple second;
    int unk1c;
    S_00dbd8a0_Mem20 unk20;
    S_00dbd8a0_Mem30 unk30;
    Triple third;
    bool unk4c;
    FUN_00dbd8a0(S_00dbd8a0_Arg* p);
};

// Initialises members from p: stores p, builds unk20 from p->unk04 and unk30 from byte 0, and sets unk4c by comparing DAT_011b7b89 with p->unk04.unk1.
// @fnv 0x00dbd8a0
// pdb: hkBinaryPackfileWriter::SaveContext::SaveContext | hkBinaryPackfileWriter.obj | fnv360_0822_debug, call_seq, high
// pdb params: options
FUN_00dbd8a0::FUN_00dbd8a0(S_00dbd8a0_Arg* apArg) : unk00(apArg), unk20(&apArg->unk04), unk30(S_00dbd8a0_Byte(0))
{
    unk4c = DAT_011b7b89 != apArg->unk04.unk1;
}

class BDBD910Allocator
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};

class BDBD910Router
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BDBD910Allocator* m_pkHeap;

    BDBD910Allocator& heap()
    {
        return *m_pkHeap;
    }
};

BDBD910Router* BDBD910GetRouter();

template <class T> __forceinline void BDBD910Destruct(T* pkData, int iCount)
{
    for (int i = 0; i < iCount; i++)
        pkData[i].~T();
}

template <class T> class BDBD910Array
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~BDBD910Array()
    {
        BDBD910Allocator& kAlloc = BDBD910GetRouter()->heap();
        BDBD910Destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace fnv_00dbd620 {

unsigned int __cdecl FUN_00dbd720(unsigned int arg);

}  // namespace fnv_00dbd620

// Havok patch manager: rebuild patch dependency order (topological sort).
typedef unsigned __int64 S_00db8670_Uint64;
typedef unsigned long S_00db8670_Ulong;

struct S_00db8670_Heap
{
    virtual void unkVfn0();
    virtual void* AllocateMemoryBlock(int n);
    virtual void unkVfn2();
    virtual void unkVfn3();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00db8670_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00db8670_Heap* m_pStreamAllocator;
    S_00db8670_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern void* __cdecl FUN_00c85750();
__forceinline S_00db8670_Router& S_GetRouter() throw()
{
    return *(S_00db8670_Router*)FUN_00c85750();
}
void __cdecl FUN_00c908c0(S_00db8670_Heap& alloc, void* array, int reqCapacity, int sizeElem) throw();

template <typename T> __forceinline void S_ConstructWithCopy(T* p, int n, const T& fill) throw()
{
    for (int i = 0; i < n; ++i)
        p[i] = fill;
}

template <typename T> struct S_00db8670_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00db8670_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~S_00db8670_Array() throw()
    {
        _clearAndDeallocate(S_GetRouter().heap());
    }

    int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i) throw()
    {
        return m_data[i];
    }
    const T& operator[](int i) const throw()
    {
        return m_data[i];
    }

    void _clearAndDeallocate(S_00db8670_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(S_00db8670_Heap& alloc, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S_00db8670_Heap& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    __forceinline void _setSize(S_00db8670_Heap& alloc, int n, const T& fill) throw()
    {
        GrowArrayCapacity(alloc, n);
        S_ConstructWithCopy(m_data + m_iElementCount, n - m_iElementCount, fill);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n) throw()
    {
        _setSize(S_GetRouter().heap(), n);
    }
    void SetSizeAndGrow(int n, const T& fill) throw()
    {
        _setSize(S_GetRouter().heap(), n, fill);
    }

    // copy assignment (out of line)
    void SwapThreeInts(const S_00db8670_Array& other) throw();
};

struct S_00db8670_MapBase64
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    S_00db8670_MapBase64() throw() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~S_00db8670_MapBase64() throw();

    void ResizeToFit(S_00db8670_Heap& alloc, int numElements) throw();
    void FUN_00cb1e40(S_00db8670_Heap& alloc) throw();
    void FUN_00cb1e00() throw();
    int FUN_00cb1c60(S_00db8670_Uint64 key) const throw();
    void InsertKeyValue(S_00db8670_Heap& alloc, S_00db8670_Uint64 key, S_00db8670_Uint64 val) throw();
    S_00db8670_Uint64 FUN_00cb1cb0(S_00db8670_Uint64 key, S_00db8670_Uint64 def) const throw();
};

struct S_00db8670_Map64 : S_00db8670_MapBase64
{
    S_00db8670_Map64() throw()
    {
        ResizeToFit(S_GetRouter().heap(), 0);
    }
    ~S_00db8670_Map64() throw()
    {
        FUN_00cb1e40(S_GetRouter().heap());
    }

    void clear() throw()
    {
        FUN_00cb1e00();
    }
    int hasKey(S_00db8670_Uint64 key) const throw()
    {
        return FUN_00cb1c60(key) <= m_iPairCount;
    }
    void insert(S_00db8670_Uint64 key, const int& val) throw()
    {
        S_00db8670_Router& router = S_GetRouter();
        InsertKeyValue(router.heap(), key, val);
    }
    S_00db8670_Uint64 FindValueForKey(S_00db8670_Uint64 key, S_00db8670_Uint64 def) const throw()
    {
        return FUN_00cb1cb0(key, def);
    }
};

struct S_00db8670_MapBaseUlong
{
    struct Pair
    {
        S_00db8670_Ulong key;
        S_00db8670_Ulong val;
    };
    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    S_00db8670_MapBaseUlong() throw() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~S_00db8670_MapBaseUlong() throw();

    void EnsureCapacity(S_00db8670_Heap& alloc, int numElements) throw();
    S_00db8670_Ulong LookupHashEntry(S_00db8670_Ulong key, S_00db8670_Ulong def) const throw();
    void FUN_00cb1870(S_00db8670_Heap& alloc, S_00db8670_Ulong key, S_00db8670_Ulong value) throw();
    void ProcessArgument(S_00db8670_Heap& alloc) throw();

    int GetFirstIterator() const throw()
    {
        int i;
        for (i = 0; i <= m_iPairCount; i++)
        {
            if (m_kPrimitiveElement[i].key != S_00db8670_Ulong(-1))
            {
                break;
            }
        }
        return i;
    }
    int getNext(int it) const throw()
    {
        int i;
        for (i = it + 1; i <= m_iPairCount; i++)
        {
            if (m_kPrimitiveElement[i].key != S_00db8670_Ulong(-1))
            {
                break;
            }
        }
        return i;
    }
    int isValid(int it) const throw()
    {
        return it <= m_iPairCount;
    }
    S_00db8670_Ulong GetIteratorKey(int it) const throw()
    {
        return m_kPrimitiveElement[it].key;
    }
};

struct S_00db8670_MapUlong : S_00db8670_MapBaseUlong
{
    S_00db8670_MapUlong() throw()
    {
        EnsureCapacity(S_GetRouter().heap(), 0);
    }
    ~S_00db8670_MapUlong() throw()
    {
        ProcessArgument(S_GetRouter().heap());
    }
};

struct S_00db8670_ChainValue
{
    int value;
    int next;
};

struct S_00db8670_MultiMap64
{
    S_00db8670_Array<S_00db8670_ChainValue> m_kChainValues;
    S_00db8670_Map64 m_pHashFunction;
    int m_iFreeListHead;

    S_00db8670_MultiMap64() throw() : m_iFreeListHead(-1)
    {}

    int AllocateSlot() throw();
    int CallHelperWithDefaults(S_00db8670_Uint64 key) const throw();
    void Insert(S_00db8670_Uint64 key, const int& value) throw();
    int GetNextChainIndex(int i) const throw()
    {
        return m_kChainValues[i].next;
    }
    int getValue(int i) const throw()
    {
        return m_kChainValues[i].value;
    }
};

struct S_00db8670_MultiMapUlong
{
    S_00db8670_Array<S_00db8670_ChainValue> m_kChainValues;
    S_00db8670_MapUlong m_pHashFunction;
    int m_iFreeListHead;

    S_00db8670_MultiMapUlong() throw() : m_iFreeListHead(-1)
    {}

    int AllocateSlot() throw();
    int LookupWithDefault(S_00db8670_Ulong key) const throw();
    void FUN_00dc9ec0(S_00db8670_Ulong key, const int& value) throw();
    int GetNextChainIndex(int i) const throw()
    {
        return m_kChainValues[i].next;
    }
    int getValue(int i) const throw()
    {
        return m_kChainValues[i].value;
    }
};

struct Dbc860Triple
{
    int x;
    int y;
    int z;
};

struct Dbc860Frame
{
    Dbc860Triple first;
    Dbc860Triple second;
    Dbc860Triple third;
    Dbc860Triple fourth;
    int trailing;
    void FUN_00e028e0();
};

struct Dbc860Src
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    void* m_0c;
};

struct Dbc860Guid
{
    unsigned char b0;
    unsigned char b1;
    unsigned short s2;
    unsigned int d4;
    unsigned int d8;
    unsigned int dc;
};

struct Dbc860Header
{
    unsigned int magic0;
    unsigned int magic1;
    unsigned int id;
    unsigned int type;
    unsigned int data;
    unsigned int extra;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    Dbc860Guid guid;
    unsigned int tail0;
    unsigned int tail1;
};

struct Dbc860Sink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Call(int value, void* a, void* b, void* c);
};

extern "C" void __cdecl FUN_00cb1280(void* dst, int a, int b);
extern "C" void __cdecl CopyIfNonEmpty(void* dst, void* src, int n);

// Builds a Dbc860Header and initializes a Dbc860Frame, then calls sink->Call with the value, header, DAT_0126c6c8, and frame.
// @f3 0x009d7ac0 (community match, verified in this file)
namespace task1446 {
struct Dbc860Triple
{
    int x;
    int y;
    int z;
};
struct Dbc860Frame
{
    Dbc860Triple first;
    Dbc860Triple second;
    Dbc860Triple third;
    Dbc860Triple fourth;
    int trailing;
    void FUN_009b2fd0();
};
}
extern "C" void __cdecl FUN_00923500(void* dst, int a, int b);
extern "C" void __cdecl FUN_009234e0(void* dst, void* src, int n);
extern "C" void __cdecl FUN_009233d0(void* dst, void* src, int n);
extern "C" void __cdecl FUN_00a4a570(void* dst, int n);
extern int DAT_0116c41c;
// pdb: hkBinaryPackfileWriter::fillSectionTags | hkBinaryPackfileWriter.obj | fnv360_0822_debug, call_seq, low, conflict (skyrim: saveFileHeader)
// pdb params: context
static __declspec(noinline) void FUN_00dbc860(Dbc860Src* apSrc, int value, int extra, Dbc860Sink* sink)
{
    Dbc860Header header;
    task1446::Dbc860Frame f;

    FUN_00923500(&header, -1, 0x40);
    header.magic0 = 0x57e0e057;
    header.magic1 = 0x10c0c010;
    header.guid.b0 = 0;
    header.id = apSrc->m_00;
    header.type = 5;
    FUN_009234e0(&header.data, &apSrc->m_04, 4);
    header.extra = extra;
    FUN_00923500(&header.tail0, -1, 8);
    if (apSrc->m_0c == 0)
    {
        FUN_00a4a570(&header.guid, 0x10);
    }
    else
    {
        FUN_009233d0(&header.guid, apSrc->m_0c, 0x10);
    }
    f.first.z = (int)0x80000000;
    f.second.z = (int)0x80000000;
    f.third.z = (int)0x80000000;
    f.fourth.z = (int)0x80000000;
    f.first.x = 0;
    f.first.y = 0;
    f.second.x = 0;
    f.second.y = 0;
    f.third.x = 0;
    f.third.y = 0;
    f.fourth.x = 0;
    f.fourth.y = 0;
    f.trailing = 0;
    sink->Call(value, &header, &DAT_0116c41c, &f);
    f.FUN_009b2fd0();
}


volatile int g_dbc860_value;
volatile int g_dbc860_extra;
Dbc860Src* volatile g_dbc860_self;
Dbc860Sink* volatile g_dbc860_sink;
void CallTarget_dbc860()
{
    FUN_00dbc860(g_dbc860_self, g_dbc860_value, g_dbc860_extra, g_dbc860_sink);
}

// hkStreamWriter, up to tell (Fallout 3 vtables, PDB names).
struct S00dbcdd0_Obj
{
    virtual ~S00dbcdd0_Obj();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual SubStreamBool isOk() const;
    virtual void write(void* p, unsigned int n);
    virtual void flush();
    virtual SubStreamBool seekTellSupported() const;
    virtual int seek(int offset, int whence);
    virtual unsigned int tell() const;
};

struct S00dbcdd0_Alloc
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Free(void* p, unsigned int n);
};

struct S00dbcdd0_Holder
{
    int u00;
    int u04;
    int u08;
    int u0C;
    S00dbcdd0_Alloc* m_pAllocator;
    S00dbcdd0_Alloc& heap()
    {
        return *m_pAllocator;
    }
};

struct S00dbcdd0_Arr
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
    int u0;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
};

extern void FUN_00c908c0(void* alloc, void** pData, int newCap, int flag);
extern void FUN_00ec61c0(void* dst, int value, int n);

template <class T> __forceinline void S00dbcdd0_Construct(T* p, int n, const T& fill)
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = fill;
    }
}

// Fills count bytes with -1, calls obj->unk10 when r is nonzero, then frees the buffer if heap-allocated.
// @f3 0x009d7980 (community match, verified in this file)
extern "C" void __cdecl FUN_00901e90(void** buffer, int capacity, int flag);
struct S00dbcdd0_Tls
{
    void __thiscall FUN_008f6d90(void* buffer, unsigned int capacity, int type);
};
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern int DAT_010f3170;

struct MyArr : S00dbcdd0_Arr
{
    __forceinline MyArr()
    {
        m_data = &u0;
        m_iElementCount = 0;
        m_capFlags = 0x80000020;
    }
};

static __declspec(noinline) void FUN_00dbcdd0(S00dbcdd0_Obj* obj, unsigned int count)
{
    int value = (int)obj->tell();
    MyArr arr;
    S00dbcdd0_Tls* tls;

    if ((int)count > 0) {
        if ((int)count > 0x20) {
            int new_capacity;
            if ((int)count < 0x40) {
                new_capacity = 0x40;
            } else {
                new_capacity = (int)count;
            }
            FUN_00901e90(&arr.m_data, new_capacity, 1);
        }

        for (int index = 0; index < (int)count; ++index) {
            ((char*)arr.m_data)[index] = (char)0xff;
        }
    }

    int remainder = ((int)count - 1) & value;
    arr.m_iElementCount = (int)count;
    if (remainder != 0) {
        obj->write(arr.m_data, count - remainder);
    }

    if ((arr.m_capFlags & 0x80000000) == 0) {
        unsigned int capacity = arr.m_capFlags & 0x3fffffff;
        tls = (S00dbcdd0_Tls*)DAT_00d9b080((unsigned long)DAT_010f3170);
        tls->FUN_008f6d90(arr.m_data, capacity, 0x17);
    }
}

volatile S00dbcdd0_Obj* g_pObj;
volatile unsigned int g_count;
void S00dbcdd0_Entry()
{
    FUN_00dbcdd0((S00dbcdd0_Obj*)g_pObj, g_count);
}


void S00dbcdd0_Entry(S00dbcdd0_Obj* obj, unsigned int count)
{
    FUN_00dbcdd0(obj, count);
}

namespace fnv_00dbd7f0 {
struct S_00dbd7f0_Allocator
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct S_00dbd7f0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dbd7f0_Allocator* m_pStreamAllocator;
    S_00dbd7f0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00dbd7f0_Router* FUN_00c85750();

struct S_00dbd7f0_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00dbd7f0_RefObj();
    void operator delete(void* p)
    {
        S_00dbd7f0_RefObj* b = static_cast<S_00dbd7f0_RefObj*>(p);
        FUN_00c85750()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

}  // namespace fnv_00dbd7f0

extern "C" void _ReadWriteBarrier();
struct OuterOffsets
{
    int fixup;
    int section;
    void step()
    {
        section += 48;
        fixup += 52;
    }
};
struct WriterBool
{
    unsigned char value;
};
struct BinaryWriter
{
    void* stream;
    int mode;
    int state;
    int extra;
    void FUN_00d60830(void*, WriterBool);
    void FUN_00d60590();
    void WriteInt(int);
    void FUN_00d60aa0(int*, int);
};
struct OutputStream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void seek(int, int);
};
struct HashLookup
{
    int state;
    int LookupHashEntry(int, int);
};
struct KeyLookup
{
    int state;
    int GetValue(int, int);
};
struct RootObject
{
    int FUN_00d46d40();
};
struct RootEntry
{
    RootObject* object;
    int a04;
    int a08;
    int a0c;
    int a10;
    int a14;
};
struct WriterOwner
{
    int a00;
    int a04;
    RootEntry* roots;
    int a0c;
    int a10;
    HashLookup hash;
    int a18;
    int a1c;
    int a20;
    int a24;
    int a28;
    int a2c;
    int a30;
    int a34;
    int a38;
    int a3c;
    int a40;
    int a44;
    int a48;
    int a4c;
    int a50;
    int a54;
    int a58;
    int a5c;
    int a60;
    int a64;
    int a68;
    int a6c;
    int a70;
    int a74;
    int a78;
    int a7c;
    int a80;
    int a84;
    int a88;
    int rootIndex;
    int objectIndex;
    void FUN_00dbc960(struct SourceData*, int);
};
struct PointerPair
{
    int first;
    int second;
};
struct Fixup
{
    int location;
    int key;
    int a08;
    int a0c;
};
struct LocalFixup
{
    int location;
    int key;
};
struct ReserveAllocator;
template <class T> struct ArrayBase
{
    T* data;
    int size;
    int capacity;
    void reserve(ReserveAllocator& allocator, int wanted);
    void resize(int wanted, const int& value);
    void resize(int wanted);
    void clear();
    void releaseOnly();
    T& operator[](int i)
    {
        return data[i];
    }
};
template <class T> struct LocalArray : ArrayBase<T>
{
    LocalArray()
    {
        data = 0;
        size = 0;
        *(volatile int*)&capacity = 0x80000000;
    }
};
struct SectionRecord
{
    int a00;
    int a04;
    int a08;
    int a0c;
    int a10;
    int base;
    int a18;
    int globalOffset;
    int localOffset;
    int a24;
    int a28;
    int a2c;
};
struct SectionFixups
{
    LocalArray<int> first;
    LocalArray<Fixup> globals;
    LocalArray<LocalFixup> locals;
    int a24;
    int a28;
    int a2c;
    int a30;
};
struct SectionContext
{
    Triple first;
    Triple second;
    Triple third;
    Triple fourth;
    int trailing;
    void FUN_00e028e0();
};
struct Serializer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void serialize(OutputStream*, SectionRecord*, int*, SectionContext*);
    int a04;
    int a08;
    int a0c;
    int* FUN_00e02a70();
};
struct SourceData
{
    int a00;
    LocalArray<SectionRecord> sections;
    LocalArray<PointerPair> pointers;
    OutputStream* stream;
    Serializer serializer;
    KeyLookup keys;
    int a34;
    int a38;
    int a3c;
    LocalArray<SectionFixups> fixups;
    WriterBool reverse;
};
extern void __cdecl FUN_00c908c0(void*, void*, int, int);
struct ReserveAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void release(void*, int);
};
struct ReserveRouter
{
    int a00;
    int a04;
    int a08;
    int a0c;
    ReserveAllocator* allocator;
    ReserveAllocator& heap()
    {
        return *allocator;
    }
};
template <class T> __forceinline void ArrayBase<T>::reserve(ReserveAllocator& allocator, int wanted)
{
    int cap = capacity & 0x3fffffff;
    if (cap < wanted)
    {
        int newCapacity = wanted < cap * 2 ? cap * 2 : wanted;
        FUN_00c908c0(&allocator, this, newCapacity, sizeof(T));
    }
}
template <class T> __forceinline void ArrayBase<T>::resize(int wanted, const int& value)
{
    reserve(((ReserveRouter*)FUN_00c85750())->heap(), wanted);
    int remaining = wanted - size;
    T* fill = data + size;
    for (int n = 0; n < remaining; n++)
        fill[n] = value;
    size = wanted;
}
template <class T> __forceinline void ArrayBase<T>::resize(int wanted)
{
    reserve(((ReserveRouter*)FUN_00c85750())->heap(), wanted);
    size = wanted;
}
template <class T> __forceinline void ArrayBase<T>::clear()
{
    ReserveAllocator& allocator = ((ReserveRouter*)FUN_00c85750())->heap();
    size = 0;
    if ((capacity & 0x80000000) == 0)
        allocator.release(data, (capacity & 0x3fffffff) * sizeof(T));
    data = 0;
    capacity = 0x80000000;
}
template <class T> __forceinline void ArrayBase<T>::releaseOnly()
{
    ReserveAllocator& allocator = ((ReserveRouter*)FUN_00c85750())->heap();
    size = 0;
    if ((capacity & 0x80000000) == 0)
        allocator.release(data, (capacity & 0x3fffffff) * sizeof(T));
}
// Writes global and local fixup data for each section, then serializes each section and writes the root object header to the stream.
// @f3 0x009d7bc0 (community match, verified in this file)
struct OutputArrayRouter {
    void FUN_008f6d90(void* data, int bytes, int tag);
};
template<class T> struct OutputArrayBase {
    T* data;
    int size;
    int capacity;
    __forceinline void reserve(int wanted) {
        int cap;
        cap = capacity & 0x3fffffff;
        if (cap < wanted) {
            int newCapacity;
            newCapacity = wanted < cap*2 ? cap*2 : wanted;
            FUN_00901e90((void**)this, newCapacity, sizeof(T));
        }
    }
    __forceinline void resize(int wanted, const int& value) {
        int oldSize = size;
        if ((capacity & 0x3fffffff) < wanted)
            FUN_00901e90((void**)this, wanted, sizeof(T));
        for (int i = oldSize; i < wanted; i++) data[i] = value;
        size = wanted;
    }
    __forceinline void resize(int wanted) {
        reserve(wanted);
        size = wanted;
    }
    __forceinline void release() {
        if ((capacity & 0x80000000u) == 0) {
            int count = capacity & 0x3fffffff;
            OutputArrayRouter* router;
            router = static_cast<OutputArrayRouter*>(DAT_00d9b080(DAT_010f3170));
            router->FUN_008f6d90(data, count*sizeof(T), 0x17);
        }
    }
};
template<class T> struct TemporaryOutput : OutputArrayBase<T> {
    TemporaryOutput() { data = 0; size = 0; *(volatile int*)&capacity = 0x80000000; }
    __forceinline void initializeSize(int wanted, const int& value) {
        if (wanted > 0) {
            FUN_00901e90((void**)this, wanted, sizeof(T));
            for (int i = 0; wanted > i; i++) data[i] = value;
        }
        size = wanted;
    }
    __forceinline void release() {
        if ((capacity & 0x80000000u) == 0) {
            int count = capacity & 0x3fffffff;
            OutputArrayRouter* router;
            router = static_cast<OutputArrayRouter*>(DAT_00d9b080(DAT_010f3170));
            router->FUN_008f6d90(data, count*sizeof(T), 0x17);
        }
    }
};
struct FixupThree {
    int location;
    int key;
    int a08;
};
extern int DAT_0116c44c;
extern char DAT_011b7b89;
// pdb: hkBinaryPackfileWriter::doDeferredWrites | hkBinaryPackfileWriter.obj | fnv360_0822_retail, callee_sim, medium
// pdb params: context, sectionHeadersStart
void WriterOwner::FUN_00dbc960(SourceData* source, int position)
{
    BinaryWriter values;
    values.FUN_00d60830(source->stream, source->reverse);
    {
        int ptr;
        ptr = 0;
        if (ptr < source->sections.size)
        {
            do
            {
                int sectionOffset = ptr*sizeof(SectionRecord);
                SectionFixups* pFixups = (&source->fixups.data[ptr]);
                LocalArray<FixupThree>* pGlobals;
                OutputArrayBase<int> localOut;
                {
                    SectionRecord* globalSection = ((SectionRecord*)((char*)source->sections.data + sectionOffset));
                    pGlobals = (LocalArray<FixupThree>*)&pFixups->globals;
                    TemporaryOutput<int> n;
                    n.initializeSize((*(volatile int*)&pGlobals->size) * 3, -1);
                    _ReadWriteBarrier();
                    int j;
                    j = 0;
                    unsigned int writer = 0;
                    if (pGlobals->size > 0)
                    {
                        do
                        {
                            int q;
                            int key = pGlobals->data[j].key;
                            q = hash.LookupHashEntry(key, -3);
                            if (0 <= q && source->pointers.data[q].first >= 0)
                            {
                                n.data[writer] = pGlobals->data[j].location - globalSection->base;
                                n.data[writer + 1] = source->pointers.data[q].first;
                                n.data[writer + 2] = source->pointers.data[q].second;
                                writer += 3;
                            }
                        } while (++j < pGlobals->size);
                    }
                    source->stream->seek(globalSection->base + globalSection->globalOffset, 0);
                    values.FUN_00d60aa0(n.data, n.size);
                    n.release();
                }
                LocalArray<LocalFixup>* b;
                b = &source->fixups.data[ptr].locals;
                SectionRecord* localSection = ((SectionRecord*)((char*)source->sections.data + sectionOffset));

                OutputArrayBase<int>& out = localOut;
                out.data = 0;
                out.size = 0;
                out.capacity = 0x80000000;
                out.resize(b->size * 3);
                for (int k = 0, offset = 0; k < b->size; k++, offset += 3)
                {
                    out.data[offset] = b->data[k].location - localSection->base;
                    out.data[1 + offset] = 0;
                    int localKey = b->data[k].key;
                    int mapped;
                    mapped = source->keys.GetValue(localKey, -1);
                    out.data[2 + offset] = mapped;
                }
                source->stream->seek(localSection->localOffset + localSection->base, 0);
                values.FUN_00d60aa0(out.data, out.size);
                out.release();
            } while (++ptr < source->sections.size);
        }
    }
    source->stream->seek(position, 0);
    for (int s = 0; s < source->sections.size; s++)
    {
        SectionContext context;
        context.trailing = 0;
        source->serializer.serialize(source->stream, &source->sections.data[s], &DAT_0116c44c, &context);
        context.FUN_00e028e0();
    }
    source->stream->seek(24, 0);
    WriterBool p;
    p.value = (unsigned char)(((unsigned int)*source->serializer.FUN_00e02a70()) >> 8) != (unsigned char)DAT_011b7b89;
    BinaryWriter ptr;
    ptr.FUN_00d60830(source->stream, p);
    ptr.WriteInt(source->pointers.data[rootIndex].first);
    ptr.WriteInt(source->pointers.data[rootIndex].second);
    RootObject* section;
    section = roots[objectIndex].object;
    ptr.WriteInt(0);
    unsigned long index;
    index = section->FUN_00d46d40();
    ptr.WriteInt(source->keys.GetValue(index, -1));
    ptr.FUN_00d60590();
    values.FUN_00d60590();
}


// Grouped serialization and offset-table construction.
struct ClockObj
{
    virtual void c00();
    virtual void c04();
    virtual void c08();
    virtual void c0c();
    virtual void c10(int a, int b);
    virtual void c14();
    virtual void c18();
    virtual int c1c(int n, int f);
    virtual int Get20();
};
struct FUN_00d46d40_s
{
    const char* text;
    __declspec(noinline) const char* FUN_00d46d40();
};

struct MapBool
{
    char value;
    MapBool(bool v) : value(v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct Pair8
{
    int p0;
    int p1;
};
struct Record16
{
    int value;
    int key;
    int unk08;
    int unk0c;
    __forceinline int GetIteratorKey() const
    {
        return key;
    }
};
struct Record12
{
    int value;
    int key;
    int unk08;
};
template <class T> struct Vec
{
    T* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    Vec() : m_data(0), m_iElementCount(0), m_cap((int)0x80000000)
    {}
};
typedef Vec<Pair8> Arr8;
struct Stats
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int start;
    int end1;
    int end2;
    int end3;
    int end4;
    int end5;
    int end6;
};
struct SrcOptions
{
    int unk00;
    int unk04;
    unsigned char flag08;
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct Entry52
{
    Triple first;
    Triple second;
    Triple third;
    Triple fourth;
    int trailing;
    Entry52() : trailing(0)
    {}
    void FUN_00e028e0();
};
struct Arr52
{
    Entry52* m_data;
    int m_iElementCount;
    int m_cap;
};
struct Sub20Obj
{
    virtual void c00();
    virtual void c04();
    virtual void c08();
    virtual void write(ClockObj* c, int a, int b, Arr8* arr);
    int unk04;
    int unk08;
    int unk0c;
};
struct Src
{
    SrcOptions* unk00;
    Stats* unk04;
    int count08;
    int unk0c;
    Arr8 arr10;
    ClockObj* clock1c;
    Sub20Obj sub20;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Arr52 arr40;
    unsigned char flag4c;
    unsigned char unk4d;
    unsigned char unk4e;
    unsigned char unk4f;
};
struct ThisEntry
{
    int t00;
    int t04;
    int t08;
    int t0c;
    int t10;
    int t14;
    __forceinline const char* getName();
};
__forceinline const char* ThisEntry::getName()
{
    return ((FUN_00d46d40_s*)t04)->FUN_00d46d40();
}
struct ThisSub
{
    int d00;
    int d04;
    int d08;
    int LookupHashEntry(int val, int def);
};
struct ThisSub1
{
    int d00;
    int LookupHashEntry(int val, int def);
};
struct PairMap
{
    Pair8* data;
    int size;
    int last;
};
struct ThisCls
{
    int unk00;
    int unk04;
    Vec<ThisEntry> entries;
    ThisSub sub14;
    ThisSub1 sub20o;
    int unk24;
    int unk28;
    PairMap map2c;
    void hkBinaryPackfileWriter_writeClassName(Src* src, void* glob, int diff);
    int GetOrAddString(int v);
    void hkBinaryPackfileWriter_writeAllObjects(Src* arg);
};
extern int DAT_011b7aec;
void* FUN_00c85750();
extern void __cdecl ResizeAudioStream(void* allocator, void* vec, unsigned int elemSize);
extern void __cdecl FUN_00c908c0(void* a, void* vec, int n, int elem);
extern int __cdecl hkString_strLen(void* p);
struct Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BDBD910Allocator* heap;
    __forceinline BDBD910Allocator& getHeap()
    {
        return *heap;
    }
};
extern "C" void _ReadWriteBarrier();

extern void FUN_00ec61c0(void* dst, int value, int n);
static __declspec(noinline) void FUN_00dbcdd0(ClockObj* obj0, unsigned int count)
{
    S00dbcdd0_Obj* obj = (S00dbcdd0_Obj*)obj0;
    int value = (int)obj->tell();
    S00dbcdd0_Arr arr;
    arr.m_data = &arr.u0;
    arr.m_iElementCount = 0;
    arr.m_capFlags = 0x80000020;
    S00dbcdd0_Alloc& heap = ((S00dbcdd0_Holder*)FUN_00c85750())->heap();
    int cap = (int)(arr.m_capFlags & 0x3fffffff);
    if (cap < (int)count)
    {
        int newCap = cap + cap;
        if ((int)count >= newCap)
        {
            newCap = (int)count;
        }
        FUN_00c908c0(&heap, &arr, newCap, 1);
    }
    int end = (int)arr.m_data + arr.m_iElementCount;
    int fill = (int)count - arr.m_iElementCount;
    if (fill > 0)
    {
        FUN_00ec61c0((void*)end, -1, fill);
    }
    int r = ((int)count - 1) & value;
    arr.m_iElementCount = (int)count;
    if (r != 0)
    {
        obj->write(arr.m_data, count - r);
    }
    S00dbcdd0_Alloc& heap2 = ((S00dbcdd0_Holder*)FUN_00c85750())->heap();
    unsigned int capFlags = arr.m_capFlags;
    arr.m_iElementCount = 0;
    if ((capFlags & 0x80000000u) == 0)
    {
        heap2.Free(arr.m_data, capFlags & 0x3fffffff);
    }
}

struct Work
{
    Arr8 a1;
    Vec<Record16> a2;
    Vec<Record12> a3;
    Arr8 a4;
    int extra;
    Work() : extra(0)
    {}
    void FUN_00e028e0();
};

template <class A> __forceinline void Reserve(A& array, BDBD910Allocator& alloc, int n, int size)
{
    int cap = array.m_cap & 0x3fffffff;
    if (cap < n)
    {
        cap *= 2;
        if (n >= cap)
            cap = n;
        FUN_00c908c0(&alloc, &array, cap, size);
    }
}
template <class T> __forceinline void Destroy(T* p, int count)
{
    for (int i = 0; i < count; ++i)
        p[i].FUN_00e028e0();
}
template <class T> __forceinline void Construct(T* p, int count)
{
    for (int i = 0; i < count; ++i)
        new (p + i) T();
}
__forceinline void Resize52(Arr52& a, int n)
{
    BDBD910Allocator& alloc = ((Router*)FUN_00c85750())->getHeap();
    Reserve(a, alloc, n, 52);
    Destroy(a.m_data + n, a.m_iElementCount - n);
    Construct(a.m_data + a.m_iElementCount, n - a.m_iElementCount);
    a.m_iElementCount = n;
}
__forceinline void Resize8(Arr8& a, int n)
{
    BDBD910Allocator& alloc = ((Router*)FUN_00c85750())->getHeap();
    Reserve(a, alloc, n, 8);
    a.m_iElementCount = n;
}
template <unsigned Bytes> __forceinline void CopyWords(void* dst, const void* src)
{
    unsigned cursor = 0;
    do
    {
        ((unsigned*)dst)[cursor] = ((const unsigned*)src)[cursor];
    } while (++cursor < Bytes / sizeof(unsigned));
}

typedef void* MapIter;
__forceinline Pair8& ExpandOne(Arr8& a, Router& router)
{
    if (a.m_iElementCount == (a.m_cap & 0x3fffffff))
        ResizeAudioStream(router.heap, &a, 8);
    return a.m_data[a.m_iElementCount++];
}
__forceinline void RemoveAt(Vec<Record16>& a, int index, int byteOffset)
{
    --a.m_iElementCount;
    if (a.m_iElementCount != index)
        CopyWords<16>((char*)a.m_data + byteOffset, a.m_data + a.m_iElementCount);
}
__forceinline MapIter BeginPairs(PairMap* map)
{
    int i = 0;
    while (i <= map->last)
    {
        if (map->data[i].p0 != -1)
            break;
        ++i;
    }
    return (MapIter)i;
}
__forceinline MapIter NextPair(PairMap* map, MapIter previous)
{
    int i = (int)previous + 1;
    while (i <= map->last)
    {
        if (map->data[i].p0 != -1)
            break;
        ++i;
    }
    return (MapIter)i;
}
// Calls hkBinaryPackfileWriter_writeClassName for four globals and unseen entries, writes per-counter data, records timings, and resizes two arrays.
// @f3 0x009d7fd0 (community match, verified in this file)
// Writes every pending object of a binary packfile, section by section, and collects the fixups of each section.
// The container and stream types below are the inline library code this function was built from.
namespace pfw9d7fd0 {
extern "C" void __cdecl FUN_00901f10(void* arr, int elemSize);
extern "C" int __cdecl FUN_009233f0(const char* s);

struct ThreadMemory {
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
};

// One-byte boolean class.
struct Bool {
    char m_bool;
    Bool(bool b) : m_bool(b) {}
    operator bool() const { return m_bool != 0; }
};

// Untyped view of an array header; FUN_00929ad0 exchanges two headers.
struct ArrayBase {
    void* m_data;
    int m_size;
    int m_capacityAndFlags;
    void FUN_00929ad0(ArrayBase& other) throw();
};
__declspec(noinline) void ArrayBase::FUN_00929ad0(ArrayBase& other) throw()
{
    void* data = m_data;
    m_data = other.m_data;
    other.m_data = data;
    int size = m_size;
    m_size = other.m_size;
    other.m_size = size;
    int capacityAndFlags = m_capacityAndFlags;
    m_capacityAndFlags = other.m_capacityAndFlags;
    other.m_capacityAndFlags = capacityAndFlags;
}

// Growable array: data, size, and a capacity whose top bit means "storage not owned".
enum { CAPACITY_MASK = int(0x3fffffff), DONT_DEALLOCATE_FLAG = int(0x80000000) };
template <class T> struct Array {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    Array() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & CAPACITY_MASK; }
    T* begin() { return m_data; }
    T& operator[](int i) { return m_data[i]; }
    void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0) {
            int capacity = getCapacity();
            ThreadMemory* memory = (ThreadMemory*)DAT_00d9b080((unsigned long)DAT_010f3170);
            memory->FUN_008f6d90(m_data, capacity * sizeof(T), 0x17);
        }
    }
    void reserve(int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int doubled = 2 * capacity;
            int newSize = (n < doubled) ? doubled : n;
            FUN_00901e90((void**)this, newSize, sizeof(T));
        }
    }
    void setSize(int n) { reserve(n); m_size = n; }
    void setSizeUnchecked(int n) { m_size = n; }
    T& expandOne()
    {
        if (m_size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        return m_data[m_size++];
    }
    void removeAt(int index)
    {
        m_size--;
        m_data[index] = m_data[m_size];
    }
    void swap(Array& other) { ((ArrayBase*)this)->FUN_00929ad0(*(ArrayBase*)&other); }
    // Forwarding wrapper (a tail jump in the image) to the untyped exchange.
    __declspec(noinline) void FUN_00a82280(Array& other) throw() { ((ArrayBase*)this)->FUN_00929ad0(*(ArrayBase*)&other); }
};
// An array local that gives its storage back when it goes out of scope.
template <class T> struct ScopedArray : Array<T> {
    ~ScopedArray() throw() { releaseMemory(); }
};

struct LocalFixup { int fromOffset; int toOffset; };
struct GlobalFixup { int fromOffset; void* toAddress; const void* toClass; };
struct FinishFixup { int fromOffset; const void* klass; };
struct ImportFixup { int fromOffset; const char* identifier; };
struct StringPool;
// The fixups gathered while one section is written.
struct RelocationInfo {
    Array<LocalFixup> m_local;
    Array<GlobalFixup> m_global;
    Array<FinishFixup> m_finish;
    Array<ImportFixup> m_imports;
    StringPool* m_pool;
    RelocationInfo() : m_pool(0) {}
    RelocationInfo(const RelocationInfo&) {}
    void FUN_009b2fd0() throw(); // releases the four arrays
};

// Array of objects with constructors: growth copy-constructs into new storage and destroys the old elements.
template <class T> struct ObjectArray {
    Array<T> m_array;
    __forceinline void reserve(int n)
    {
        if (n > m_array.getCapacity()) {
            int doubled = 2 * m_array.getCapacity();
            int newSize = n < doubled ? doubled : n;
            int size = m_array.getSize();
            ScopedArray<T> old;
            old.FUN_00a82280(m_array);
            m_array.reserve(newSize);
            construct(m_array.begin(), size, old.begin());
            m_array.setSizeUnchecked(size);
            for (int j = 0; j < old.getSize(); ++j)
                old[j].FUN_009b2fd0();
        }
    }
    static __forceinline void construct(T* t, int from, int to)
    {
        for (int i = from; i < to; ++i)
            new (t + i) T;
    }
    static __forceinline void construct(T* t, int n, const T* from)
    {
        for (int i = 0; i < n; ++i)
            new (t + i) T(from[i]);
    }
    __forceinline void setSize(int n)
    {
        int size = m_array.getSize();
        if (n < size) {
            for (int i = n; i < size; ++i)
                m_array[i].FUN_009b2fd0();
        } else {
            reserve(n);
            construct(m_array.begin(), size, n);
        }
        m_array.setSizeUnchecked(n);
    }
};

struct Stream {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void write(const void* data, int nbytes) throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual int seek(int offset, int whence) throw();
    virtual int tell() throw();
};
struct ObjectWriter {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void writeObject(Stream* stream, const void* data, const void* klass, RelocationInfo& fixups) throw();
    int unk04;
    int unk08;
    int unk0c;
};
// Endian-aware archive over a stream.
struct Archive {
    void* m_stream;
    int m_byteSwap;
    int unk08;
    int unk0c;
    void FUN_009ee7e0(Stream* stream, Bool byteSwap) throw();
    void FUN_009ee850() throw();
    void FUN_009ee590(const void* data, int elemSize, int count) throw();
    void FUN_009ee8d0(int value) throw();
    void FUN_009ee740(const void* data, int nbytes) throw();
};
struct Options {
    int unk00;
    int unk04;
    unsigned char writeMetaInfo;
};
struct SectionHeader {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int absoluteDataStart;
    int localFixupsOffset;
    int globalFixupsOffset;
    int virtualFixupsOffset;
    int exportsOffset;
    int importsOffset;
    int endOffset;
};
struct Location {
    int sectionIndex;
    int offset;
};
struct SaveContext {
    Options* options;
    Array<SectionHeader> sections;
    Array<Location> locations;
    Stream* stream;
    ObjectWriter writer;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    ObjectArray<RelocationInfo> fixups;
    Bool byteSwap;
};
struct PendingWrite {
    const void* pointer;
    const void* klass;
    int unk08;
    int unk0c;
    int sectionIndex;
    int dataSize;
};
// Pointer-keyed hash map with an out-of-line lookup.
struct PointerMap {
    unsigned long* m_elem;
    int m_numElems;
    int m_hashMod;
    unsigned long FUN_009227d0(unsigned long key, unsigned long def) throw();
};
// Hash map stored as a run of keys followed by a run of values.
// Typed front of a pointer map from addresses to names.
struct NameMap {
    PointerMap m_map;
    const char* getWithDefault(void* key, const char* def) { return (const char*)m_map.FUN_009227d0((unsigned long)key, (unsigned long)def); }
};
struct ExportMap {
    unsigned long* m_elem;
    int m_numElems;
    int m_hashMod;
    int getIterator() const
    {
        int i;
        for (i = 0; i <= m_hashMod; ++i) {
            if (m_elem[i] != (unsigned long)-1)
                break;
        }
        return i;
    }
    int getNext(int it) const
    {
        int i;
        for (i = it + 1; i <= m_hashMod; ++i) {
            if (m_elem[i] != (unsigned long)-1)
                break;
        }
        return i;
    }
    bool isValid(int it) const { return it <= m_hashMod; }
    unsigned long getKey(int it) const { return m_elem[it]; }
    unsigned long getValue(int it) const { return m_elem[m_hashMod + 1 + it]; }
};
struct ClassMapBase {
    void* m_elem;
    int m_numElems;
    int m_hashMod;
    int FUN_009b0dc0() throw();
    Bool FUN_009b0e40(int it) throw();
    const void* FUN_009b0df0(int it) throw();
    int FUN_009b0e10(int it) throw();
};
// Typed front of the class map: every member forwards to the untyped map.
struct ClassMap {
    ClassMapBase m_map;
    int getIterator() { return m_map.FUN_009b0dc0(); }
    Bool isValid(int it) { return m_map.FUN_009b0e40(it); }
    const void* getValue(int it) { return m_map.FUN_009b0df0(it); }
    int getNext(int it) { return m_map.FUN_009b0e10(it); }
};
struct Writer {
    int unk00;
    int unk04;
    Array<PendingWrite> pendingWrites;
    PointerMap knownObjects;
    NameMap imports;
    ExportMap exports;
    ClassMap knownClasses;
    void FUN_009d78d0(SaveContext& context, const void* klass, int absoluteDataStart) throw();
    int FUN_00a4a7b0(int tag) throw();
    __forceinline void writeAllObjects(SaveContext& context);
};

inline void padUp(Stream* stream, int pad) { FUN_00dbcdd0((S00dbcdd0_Obj*)stream, (unsigned int)pad); }

__forceinline void Writer::writeAllObjects(SaveContext& context)
{
    {
        SectionHeader& section = context.sections[0];
        section.absoluteDataStart = context.stream->tell();
        const void* specialClasses[4];
        specialClasses[0] = &g_0126cae8;
        specialClasses[1] = &g_0126ca58;
        specialClasses[2] = &g_0126cab8;
        specialClasses[3] = &g_0126ca88;
        for (int i = 0; i < 4; ++i)
            FUN_009d78d0(context, specialClasses[i], section.absoluteDataStart);
        for (int it = knownClasses.getIterator(); knownClasses.isValid(it); it = knownClasses.getNext(it))
            FUN_009d78d0(context, knownClasses.getValue(it), section.absoluteDataStart);
        padUp(context.stream, 16);
        int offset = context.stream->tell() - section.absoluteDataStart;
        section.localFixupsOffset = offset;
        section.globalFixupsOffset = offset;
        section.virtualFixupsOffset = offset;
        section.exportsOffset = offset;
        section.importsOffset = offset;
        section.endOffset = offset;
    }
    context.locations.setSize(pendingWrites.getSize());
    context.fixups.setSize(context.sections.getSize());
    int typesIndex = FUN_00a4a7b0(DAT_011b7aec);
    for (int sectionIndex = 1; sectionIndex < context.sections.getSize(); ++sectionIndex) {
        SectionHeader& section = context.sections[sectionIndex];
        section.absoluteDataStart = context.stream->tell();
        RelocationInfo fixups;
        if (context.options->writeMetaInfo == 0 && sectionIndex == typesIndex) {
            for (int i = 0; i < pendingWrites.getSize(); ++i) {
                if (pendingWrites[i].sectionIndex == typesIndex) {
                    context.locations[i].sectionIndex = -1;
                    context.locations[i].offset = -1;
                }
            }
        } else {
            for (int i = 0; i < pendingWrites.getSize(); ++i) {
                PendingWrite& pending = pendingWrites[i];
                if (pending.sectionIndex == sectionIndex) {
                    const void* pointer = pending.pointer;
                    const void* klass = pending.klass;
                    context.locations[i].sectionIndex = sectionIndex;
                    Location& location = context.locations[i];
                    location.offset = context.stream->tell() - section.absoluteDataStart;
                    if (klass)
                        context.writer.writeObject(context.stream, pointer, klass, fixups);
                    else
                        context.stream->write(pending.pointer, pending.dataSize);
                }
            }
        }
        for (int k = 0; k < fixups.m_local.getSize(); ++k) {
            fixups.m_local[k].fromOffset -= section.absoluteDataStart;
            fixups.m_local[k].toOffset -= section.absoluteDataStart;
        }
        for (int g = fixups.m_global.getSize() - 1; g >= 0; --g) {
            const char* name = imports.getWithDefault(fixups.m_global[g].toAddress, 0);
            if (name) {
                GlobalFixup& global = fixups.m_global[g];
                ImportFixup& import = fixups.m_imports.expandOne();
                import.fromOffset = global.fromOffset - section.absoluteDataStart;
                import.identifier = name;
                fixups.m_global.removeAt(g);
            }
        }
        Archive oa;
        oa.FUN_009ee7e0(context.stream, context.byteSwap);
        section.localFixupsOffset = context.stream->tell() - section.absoluteDataStart;
        oa.FUN_009ee590(fixups.m_local.begin(), 4, fixups.m_local.getSize() * 2);
        padUp(context.stream, 16);
        section.globalFixupsOffset = context.stream->tell() - section.absoluteDataStart;
        context.stream->seek(fixups.m_global.getSize() * 12, 1);
        context.fixups.m_array[sectionIndex].m_global.swap(fixups.m_global);
        padUp(context.stream, 16);
        section.virtualFixupsOffset = context.stream->tell() - section.absoluteDataStart;
        context.stream->seek(fixups.m_finish.getSize() * 12, 1);
        context.fixups.m_array[sectionIndex].m_finish.swap(fixups.m_finish);
        padUp(context.stream, 16);
        section.exportsOffset = context.stream->tell() - section.absoluteDataStart;
        {
            int it = exports.getIterator();
            bool exported = false;
            for (; exports.isValid(it); it = exports.getNext(it)) {
                int index = (int)knownObjects.FUN_009227d0(exports.getKey(it), (unsigned long)-1);
                if (index >= 0 && pendingWrites[index].sectionIndex == sectionIndex) {
                    const char* name = (const char*)exports.getValue(it);
                    exported = true;
                    oa.FUN_009ee8d0(context.locations[index].offset);
                    oa.FUN_009ee740(name, FUN_009233f0(name) + 1);
                    padUp(context.stream, 4);
                }
            }
            if (exported) {
                oa.FUN_009ee8d0(-1);
                padUp(context.stream, 16);
            }
        }
        section.importsOffset = context.stream->tell() - section.absoluteDataStart;
        for (int m = 0; m < fixups.m_imports.getSize(); ++m) {
            ImportFixup& import = fixups.m_imports[m];
            oa.FUN_009ee8d0(import.fromOffset);
            oa.FUN_009ee740(import.identifier, FUN_009233f0(import.identifier) + 1);
            padUp(context.stream, 4);
        }
        if (fixups.m_imports.getSize() != 0) {
            oa.FUN_009ee8d0(-1);
            context.fixups.m_array[sectionIndex].m_imports.swap(fixups.m_imports);
            padUp(context.stream, 16);
        }
        section.endOffset = context.stream->tell() - section.absoluteDataStart;
        oa.FUN_009ee850();
        fixups.FUN_009b2fd0();
    }
}
}

// The stand-in classes of the pack for the writer and its save context do not describe the layouts used here
// (12-byte global fixups, key/value export map), so the body is written on the layouts above.
// pdb: hkBinaryPackfileWriter::writeAllObjects | hkBinaryPackfileWriter.obj | fnv360_0822_debug, call_seq + bridge(call_seq|callee_sim) + skyrim(call_seq), high
void ThisCls::hkBinaryPackfileWriter_writeAllObjects(Src* context)
{
    ((pfw9d7fd0::Writer*)this)->writeAllObjects(*(pfw9d7fd0::SaveContext*)context);
}


namespace SectionTagsPrivate {

struct Header
{
    char tag[19];
    char terminator;
    int dataStart;
    int localFixups;
    int globalFixups;
    int finishFixups;
    int exports;
    int imports;
    int end;
    Header()
    {
        FUN_00cb1280(this, 0, 4);
    }
};

struct HeaderArray
{
    Header* data;
    int size;
    int capacity;
    int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
};

struct Context
{
    void* options;
    HeaderArray headers;
};

extern "C" unsigned int __cdecl FUN_00dbd720(const HeaderArray* headers);
extern "C" void __cdecl CopyIfNonEmpty(char* dst, const char* src, int count);

template <class T> __forceinline void ConstructHeaders(T* first, int count)
{
    for (int i = 0; i < count; ++i)
        new (first + i) T;
}

struct Writer
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    const char** tags;
    int tagCount;
    void __thiscall FUN_00dbc7a0(Context* context);
};

// Resizes the header array to tagCount, initializes its data range to -1, and copies 19 bytes from each tag.
// @f3 0x009d7a40 (community match, verified in this file)
extern "C" int __cdecl FUN_009d88b0(SectionTagsPrivate::HeaderArray* a);

// pdb: hkSubStreamWriter::hkSubStreamWriter | hkBinaryPackfileWriter.obj | fnv360_0822_debug, call_seq, low, conflict (skyrim: hkBinaryPackfileWriter::fillSectionTags)
// pdb params: child
void SectionTagsPrivate::Writer::FUN_00dbc7a0(SectionTagsPrivate::Context* context)
{
    SectionTagsPrivate::HeaderArray* headers = &context->headers;
    int count = tagCount;

    if (headers->getCapacity() < count) {
        int newCap = headers->getCapacity() * 2;
        if (count >= newCap)
            newCap = count;
        FUN_00901e90((void**)headers, newCap, 0x30);
    }

    headers->size = count;

    int len = FUN_009d88b0(headers);
    FUN_00923500(headers->data, -1, len);

    for (int i = 0; i < tagCount; ++i)
        FUN_009233d0((char*)headers->data + i * 48, (void*)tags[i], 0x13);
}


}

// @f3twin 0x00a82a00 of 0x009d8900
struct F3Twin_00a82a00 : public S_00dbd770 { SubStreamBool F3_FUN_00a82a00() const; };
SubStreamBool F3Twin_00a82a00::F3_FUN_00a82a00() const
{
    return m_childStream->seekTellSupported();
}
