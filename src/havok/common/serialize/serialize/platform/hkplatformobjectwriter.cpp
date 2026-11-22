#include "f3_common.h"
// src/havok/common/serialize/serialize/platform/hkplatformobjectwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/serialize/platform/hkplatformobjectwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct E02A40StreamWriter
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int write(const void* buf, int nbytes);
};

// Calls writer->write with buf and nbytes and returns nonzero if the number of bytes written differs from nbytes.
// @fnv 0x00e02a40
// pdb: hkPlatformObjectWriter::writeRaw | hkPlatformObjectWriter.obj | fnv360_0822_retail, vtable, high
// pdb params: writer, data, dataLen
// pdb: hkPlatformObjectWriter::writeRaw | hkPlatformObjectWriter.obj | fnv360_0822_retail, vtable, high (was: WriteAllOrFail)
int __stdcall hkPlatformObjectWriter_writeRaw(E02A40StreamWriter* writer, const void* buf, int aiNumBytes)
{
    return writer->write(buf, aiNumBytes) != aiNumBytes;
}

struct OffsetView
{
    int unk00;
    int unk04;
    char* unk08;
    char* FUN_00e02a70();
};
// @fnv 0x00e02a70
// pdb: hkPlatformObjectWriter::getLayout | hkPlatformObjectWriter.obj | fnv360_0822_debug, objrun, medium
char* OffsetView::FUN_00e02a70()
{
    return unk08 + 12;
}

void* __cdecl FUN_00c85750();
struct BaseE02c70
{
    int unk04;
    virtual __declspec(nothrow) ~BaseE02c70()
    {}
};

struct IntTemp
{
    int m_v;
    IntTemp(int v) : m_v(v)
    {}
    IntTemp(const IntTemp& o) : m_v(o.m_v)
    {}
};

struct FUN_00e02bb0_cls
{
    void* m_vptr;
    unsigned short unk04;
    unsigned short m_w06;
    void* m_p08;
    void* m_p0c;

    char* FUN_00e02a70();
    FUN_00e02bb0_cls* FUN_00e02bb0(int a1);
};

// Sets the vtable and flag, allocates and initialises a blob from a key and a1, and conditionally allocates a small object whose Make result is stored in m_p0c.
// @f3 0x00a4c8d0 (community match, verified in this file)
namespace NativePlatformWriter
{
struct Cache;
struct ThreadAllocator
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    Cache* freeHead;
    int freeCount;
    void* FUN_008f6d30(int bytes, int category) throw();
    Cache* FUN_008f6800(int sizeClass, int category) throw();
    Cache* AllocateCache() throw()
    {
        Cache* node = freeHead;
        if (node) {
            --freeCount;
            freeHead = *reinterpret_cast<Cache**>(node);
            return node;
        }
        return FUN_008f6800(4, 5);
    }
};
extern ThreadAllocator* (__stdcall *DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
extern const unsigned int DAT_01061524;
extern void* DAT_00e86a0c[];

struct Layout
{
    const void* data;
    void FUN_009b2540(const unsigned int* layout) throw();
};
struct WriteMode
{
    unsigned int value;
    WriteMode(unsigned int mode) throw() : value(mode) {}
    WriteMode(const WriteMode& mode) throw() : value(mode.value) {}
};
struct Buffer
{
    int unk00;
    unsigned short allocationSize;
    unsigned short unk06;
    int unk08, unk0c, unk10, unk14;
    Buffer* FUN_009b3190(Layout*, int stream, WriteMode mode) throw();
};
struct PointerMap
{
    int unk00, unk04, unk08;
    void FUN_00922cb0() throw();
};
struct Cache
{
    PointerMap source, target;
    void* relocations;
    int relocationCount;
    unsigned int relocationCapacity;
    static void* operator new(size_t, ThreadAllocator* allocator) throw() { return allocator->AllocateCache(); }
    Cache() throw()
    {
        source.FUN_00922cb0();
        target.FUN_00922cb0();
        relocations = 0;
        relocationCount = 0;
        relocationCapacity = 0x80000000u;
    }
};
}

// pdb: hkPlatformObjectWriter::hkPlatformObjectWriter | hkPlatformObjectWriter.obj | fnv360_0822_retail, call_seq, high
// pdb params: layout
FUN_00e02bb0_cls* FUN_00e02bb0_cls::FUN_00e02bb0(int stream)
{
    using namespace NativePlatformWriter;
    ThreadAllocator* (__stdcall *lookupAllocator)(unsigned long) = DAT_00d9b080;
    m_w06 = 1;
    m_vptr = DAT_00e86a0c;
    ThreadAllocator* allocator = lookupAllocator(DAT_010f3170);
    Buffer* storage = static_cast<Buffer*>(allocator->FUN_008f6d30(sizeof(Buffer), 0x15));
    storage->allocationSize = sizeof(Buffer);
    Layout targetLayout;
    targetLayout.FUN_009b2540(&DAT_01061524);
    m_p08 = storage->FUN_009b3190(&targetLayout, stream, WriteMode(2));

    const unsigned char* layout = (const unsigned char*)FUN_00e02a70();
    const unsigned char* native = reinterpret_cast<const unsigned char*>(&DAT_01061524);
    // a cache is needed only when the stream's byte layout differs from the native one
    m_p0c = (layout[0] != native[0] || layout[1] != native[1] || layout[2] != native[2] || layout[3] != native[3])
                ? new (lookupAllocator(DAT_010f3170)) Cache
                : 0;
    return this;
}


struct hkMemoryHeapE02
{
    int unk00;
};

struct hkThreadMemoryE02
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryHeapE02* m_pkHeap;
};

extern "C" hkThreadMemoryE02& __cdecl hkThreadMemoryInstanceE02();
void __cdecl hkArrayReserveMoreE02(hkMemoryHeapE02* pkHeap, void* pArray, int iElemSize);

template <class T> inline void hkArrayConstructE02(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}

template <class T> class hkArrayE02
{
  public:
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkThreadMemoryE02& kMem = hkThreadMemoryInstanceE02();
        if (m_iElementCount == getCapacity())
            hkArrayReserveMoreE02(kMem.m_pkHeap, this, sizeof(T));
        hkArrayConstructE02(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct hkFlagsE02
{
    hkFlagsE02(int iFlags) : m_iFlags(iFlags)
    {}
    hkFlagsE02(const hkFlagsE02& kOther) : m_iFlags(kOther.m_iFlags)
    {}
    int m_iFlags;
};

class hkObjectE02;
class hkRegistryE02;

class hkLoaderE02;
hkObjectE02* __cdecl CreateObjectE02(const char* pcName, hkRegistryE02* pkRegistry, hkLoaderE02* pkLoader, int iUnk,
                                     int iUnk2, hkFlagsE02 kFlags);

class hkTrackerE02
{
  public:
    void Track(hkObjectE02* pkObject, void* pvOwner, int iUnk);
};

enum hkResultE02
{
    HK_SUCCESS_E02 = 0,
    HK_FAILURE_E02 = 1
};

class hkLoaderE02
{
  public:
    hkResultE02 Get(const char* pcName, hkObjectE02** ppkOut);
    hkObjectE02* GetOrCreateObject(const char* pcName, hkTrackerE02* pkTracker);

    int unk00;
    int unk04;
    int unk08;
    int m_kOwner;
    int unk10;
    int unk14;
    hkArrayE02<hkObjectE02*> m_kThirdFollowingStreamField;
};

// Looks up pcName via Get; if not found, creates the object, appends it to the array, tracks it with pkTracker, and returns it.
// @f3 0x00a4ca40 (community match, verified in this file)
extern int DAT_0116a994;

struct FUN_00922820_cls
{
    int FUN_00922820(const char* pcName, hkObjectE02** ppkOut);
};

struct FUN_009b2a50_cls
{
    void FUN_009b2a50(hkObjectE02* pkObject, void* pvOwner);
};

void __cdecl FUN_00901f10(void* pArray, int iElemSize);

// pdb: hkPlatformObjectWriter::Cache::get | hkPlatformObjectWriter.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: klass, layout
hkObjectE02* hkLoaderE02::GetOrCreateObject(const char* pcName, hkTrackerE02* pkTracker)
{
    hkObjectE02* pkObject;
    if (reinterpret_cast<FUN_00922820_cls*>(this)->FUN_00922820(pcName, &pkObject) == HK_SUCCESS_E02)
        return pkObject;

    hkObjectE02* pkNew = CreateObjectE02(pcName, reinterpret_cast<hkRegistryE02*>(&DAT_0116a994), this, 0, 0, hkFlagsE02(0));
    hkArrayE02<hkObjectE02*>* pkArray = &m_kThirdFollowingStreamField;
    if (pkArray->m_iElementCount == pkArray->getCapacity())
        FUN_00901f10(pkArray, 4);
    pkArray->m_data[pkArray->m_iElementCount] = pkNew;
    pkArray->m_iElementCount++;
    reinterpret_cast<FUN_009b2a50_cls*>(pkTracker)->FUN_009b2a50(pkNew, &m_kOwner);
    return pkNew;
}


struct E02DE0Allocator;

struct E02DE0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E02DE0Allocator* m_pStreamAllocator;

    E02DE0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" E02DE0MemoryRouter& __cdecl FUN_00c85750();
}

struct E02DE0Map
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    E02DE0Map() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {
        reserve(fnvc_adapt::FUN_00c85750().heap(), 0);
    }

    void reserve(E02DE0Allocator& alloc, int numElements);
};

struct E02DE0Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E02DE0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

// Initializes the two maps and the array member by running their default constructors.
// @f3 0x004e0ca0 (community match, verified in this file)
namespace f3m_004e0ca0 {
struct Obj004e0ca0_Target {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void* v98();
};
struct Sub28 {
    int unk00;
    Obj004e0ca0_Target* FUN_00410f00();
    void FUN_00410e20(void*);
};
struct GlobalMgr {
    void FUN_0056ada0(void*);
};
extern GlobalMgr* DAT_01071528;
struct Owner004e0ca0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned char unk24, unk25, unk26, unk27;
    Sub28 unk28;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0;
    int unka4;
    int unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    unsigned char unkd0, unkd1, unkd2, unkd3;
    void FUN_004e0b30();
    void FUN_004e0ca0();
};
// pdb: TESObjectCELL::Clear3D | TESObjectCELL.obj | fnv360_0822_retail, call_gap, low
void Owner004e0ca0::FUN_004e0ca0() {
    Obj004e0ca0_Target* target = unk28.FUN_00410f00();
    if (target && DAT_01071528) {
        DAT_01071528->FUN_0056ada0(target->v98());
    }
    unk26 = 1;
    FUN_004e0b30();
    unk28.FUN_00410e20(0);
    unka4 = 0;
    unka0 = 0;
    unk26 = 0;
    unkd1 = 0;
}
}


namespace fnv_00e02e40 {
struct E02E40Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct E02E40MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E02E40Allocator* m_pStreamAllocator;

    E02E40Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" E02E40MemoryRouter& __cdecl FUN_00c85750();

struct FUN_00e02e40
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00e02e40();
    virtual ~FUN_00e02e40();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00e02e40* b = static_cast<FUN_00e02e40*>(p);
        FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// Default constructor with an empty body; the object layout includes m_usMemSizeAndFlags and m_sReferenceCount.
// @fnv 0x00e02e40
FUN_00e02e40::FUN_00e02e40()
{}
}  // namespace fnv_00e02e40

struct E02A80LayoutView : OffsetView
{
    __declspec(noinline) char* FUN_00e02a70();
};

__declspec(noinline) char* E02A80LayoutView::FUN_00e02a70()
{
    return unk08 + 12;
}

extern const char str_010d66fc[];

int __cdecl FUN_00cb0fa0(const char* name, const char* s);

struct E02A80Helper
{
    E02A80Helper* Resolve(void* a, char* p);
    const char* Name();
};

class hkClass;
class hkStatisticsCollector;
// hkObjectCopier: the slots of its Fallout 3 vtable (0x00e7e8a0) up to copyObject (New Vegas Xbox 360 PDB names).
struct E02A80Iface
{
    virtual ~E02A80Iface();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual int copyObject(void* dataIn, void* klassIn, void* dataOut, void* klassOut, void* reloc);
};

// hkBool: a class with a constructor, so it comes back through a hidden result pointer.
struct E02A80Bool
{
    char m_bool;
    E02A80Bool(bool b) : m_bool((char)b) {}
};
// hkStreamWriter: the slots of the Fallout 3 vtables up to tell (New Vegas Xbox 360 PDB names).
struct E02A80Arg
{
    virtual ~E02A80Arg();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual E02A80Bool isOk() const;
    virtual int write(const void* buf, int nbytes);
    virtual void flush();
    virtual E02A80Bool seekTellSupported() const;
    virtual int seek(int offset, int whence);
    virtual int tell() const;
};

struct E02A80Local
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    E02A80Local();
    int Seek(int pos, int origin);
};

struct E02A80Box
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void Finish();
};

struct E02A80_cls
{
    int unk00;
    int unk04;
    E02A80Iface* m_copier;   // +0x08
    E02A80Helper* m_cache;   // +0x0C

    int hkPlatformObjectWriter_writeObject(E02A80Arg* arg1, int arg2, E02A80Helper* arg3, int arg4);
};

// Resolves a helper, optionally seeks and builds a box via the iface, then calls unk0C and returns whether the result string is empty.
// @fnv 0x00e02a80
// pdb: hkPlatformObjectWriter::writeObject | hkPlatformObjectWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int E02A80_cls::hkPlatformObjectWriter_writeObject(E02A80Arg* apArg, int aiValue, E02A80Helper* apHelper, int arg4)
{
    E02A80Helper* pResolvedHelper;
    E02A80Helper* pHelper = m_cache;
    if (pHelper != 0)
    {
        pResolvedHelper = pHelper->Resolve(apHelper, reinterpret_cast<E02A80LayoutView*>(this)->FUN_00e02a70());
    }
    else
    {
        pResolvedHelper = apHelper;
    }
    E02A80Local a;
    void* b;
    E02A80Arg* e;
    if (m_cache != 0 && FUN_00cb0fa0(pResolvedHelper->Name(), str_010d66fc) == 0)
    {
        b = m_cache->Resolve(reinterpret_cast<void*>(aiValue), reinterpret_cast<E02A80LayoutView*>(this)->FUN_00e02a70());
        e = apArg;
        a.Seek(e->tell(), 0);
        E02A80Box box;
        box.unk08 = (int)0x80000000;
        box.unk14 = (int)0x80000000;
        box.unk20 = (int)0x80000000;
        box.unk2c = (int)0x80000000;
        box.unk00 = 0;
        box.unk04 = 0;
        box.unk0c = 0;
        box.unk10 = 0;
        box.unk18 = 0;
        box.unk1c = 0;
        box.unk24 = 0;
        box.unk28 = 0;
        box.unk30 = 0;
        m_copier->copyObject(b, apHelper, apArg, pResolvedHelper, &box);
        e = reinterpret_cast<E02A80Arg*>(&a);
        box.Finish();
    }
    else
    {
        e = apArg;
    }
    m_copier->copyObject(reinterpret_cast<void*>(aiValue), apHelper, e, pResolvedHelper, reinterpret_cast<void*>(arg4));
    return e->isOk().m_bool == 0;
}
