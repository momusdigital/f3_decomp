#include "f3_common.h"
// src/havok/common/serialize/version/hkversionutil_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/serialize/version/hkversionutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/version/hkversionutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/version/hkversionutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Object
{
    void FUN_00e03160();
};
struct FUN_00d46d40_s
{
    const char* FUN_00d46d40() const throw();
};
class hkClassMemberDC11
{
  public:
    enum Type
    {
        TYPE_POINTER = 0x14,
        TYPE_ARRAY = 0x16,
        TYPE_STRUCT = 0x19,
        TYPE_SIMPLEARRAY = 0x1a,
        TYPE_VARIANT = 0x1c,
        TYPE_CSTRING = 0x1d,
        TYPE_STRINGPTR = 0x21
    };

    const char* m_name;
    const void* m_class;
    const void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;

    int FUN_00d86920() const throw();
    const FUN_00d46d40_s& FUN_00d86910() const throw();
};
class hkMemoryAllocatorDC12;
struct hkMemoryRouterDC12
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC12* m_pStreamAllocator;
    hkMemoryAllocatorDC12& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDC12& __cdecl FUN_00c85750();
class hkPointerMapDC12
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkPointerMapDC12() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~hkPointerMapDC12() throw()
    {
        FUN_00a29680();
    }

    void EnsureCapacity(hkMemoryAllocatorDC12& kAlloc, int iNumElems) throw();
    void ProcessArgument(hkMemoryAllocatorDC12& kAlloc) throw();
    void FUN_00a29680() throw();
};
class hkVisitorDC12
{
  public:
    int unk00;

    hkVisitorDC12() throw()
    {
        FUN_00dc1670();
    }
    void FUN_00dc1670() throw();
    void hkStructureLayout_computeMemberOffsetsInplace(void* pvObject, hkPointerMapDC12& kDone, int iFlags) throw();
};
// @fnv 0x00dc1230
class hkBoolDC10
{
  public:
    hkBoolDC10(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};
struct S00dc15a0_Buffer
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(int* indices, unsigned int size);
};
struct S00dc15a0_AudioSystem
{
    int unk00;
    int unk04;
    int unk08;
    S00dc15a0_Buffer* unk0C;
};
struct S00dc15a0_Params
{
    void* unk00;
    int unk04;
};
struct S00dc15a0_Array
{
    int* m_data;
    int m_iElementCount;
    int m_capFlags;
};
namespace fnvc_adapt {
extern "C" S00dc15a0_AudioSystem* __cdecl FUN_00c85750();
}
static __declspec(noinline) int FUN_00dc12c0(S00dc15a0_Params* params, int value, int flags, S00dc15a0_Array* arr)
{
    arr->m_iElementCount = (int)&params + (int)&value + (int)&flags;
    return arr->m_capFlags;
}

struct ByteBuffer
{
    ~ByteBuffer();
    char* data;
    int size;
    int capacity;
};
struct IndexArray
{
    int* data;
    int size;
    int capacity;
};
struct ObjectEntry
{
    void* object;
    int type;
};
struct ObjectArray
{
    ObjectEntry* data;
    int size;
    int capacity;
};
struct OffsetEntry
{
    int offset;
    int type;
};
struct OffsetArray
{
    OffsetEntry* data;
    int size;
    int capacity;
};
struct CopyAllocator
{
    virtual void slot0() = 0;
    virtual char* allocate(int size) = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void release(void* data, int size) = 0;
};
struct CopyRouter
{
    void* field00;
    void* field04;
    void* field08;
    void* field0c;
    CopyAllocator* allocator;
};

struct OffsetMap
{
    void* entries;
    int size;
    int capacity;
    void EnsureCapacity(CopyAllocator*, int);
    void FUN_00cb1870(CopyAllocator*, void*, int);
    void ProcessArgument(CopyAllocator*);
    void FUN_00a29680();
    ~OffsetMap()
    {
        ProcessArgument(((CopyRouter*)&FUN_00c85750())->allocator);
        FUN_00a29680();
    }
};
struct ByteBufferWriter
{
    void* vtable;
    unsigned short flags;
    unsigned short references;
    void* writer;
    void FUN_00cc0630(ByteBuffer*);
    void FUN_00cc00e0();
    ~ByteBufferWriter()
    {
        FUN_00cc00e0();
    }
};
struct CopyOption
{
    int value;
    void FUN_00dc1680(const int*);
};
struct Relocation
{
    int offset;
    int target;
};
struct Import
{
    int offset;
    void* name;
    int field08;
    int field0c;
};
struct Relocations
{
    Relocation* local;
    int localCount;
    int localCapacity;
    Import* imports;
    int importCount;
    int importCapacity;
    void* exports;
    int exportCount;
    int exportCapacity;
    void* global;
    int globalCount;
    int globalCapacity;
    void* extra;
    void FUN_00e028e0();
    ~Relocations()
    {
        FUN_00e028e0();
    }
};
struct CopyWriter : Object
{
    void* vtable;
    int field04;
    int field08;
    int field0c;
    int position;
    int options;
    void FUN_00dc1040(CopyOption*, CopyOption*);
    int hkObjectCopier_copyObject(void*, int, int, int, Relocations*);
    ~CopyWriter()
    {
        FUN_00e03160();
    }
};
struct CopyListener
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void AddMemoryChunk(char*, int, int) = 0;
    virtual void addImport(void*, char*) = 0;
};

struct ObjectInput
{
    ObjectArray* p;
    ObjectInput(ObjectArray* q) : p(q)
    {}
};
struct OffsetInput
{
    OffsetArray* p;
    OffsetInput(OffsetArray* q) : p(q)
    {}
};
struct ListenerInput
{
    CopyListener* p;
    ListenerInput(CopyListener* q) : p(q)
    {}
};
// @f3 0x0093fdc0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
extern int DAT_01061524;

struct F3Heap
{
    char* FUN_008f6d30(int size, int kind);
    void FUN_008f6d90(void* data, int size, int kind);
};

static inline F3Heap* GetHeap()
{
    return (F3Heap*)TlsGetValue(DAT_010f3170);
}

struct F3Buffer
{
    enum { DONT_DEALLOCATE_FLAG = 0x80000000 };
    char* data;
    int size;
    int capacity;
    void releaseMemory()
    {
        if ((capacity & DONT_DEALLOCATE_FLAG) == 0)
            GetHeap()->FUN_008f6d90(data, getCapacity(), 0x17);
    }
    int getCapacity() const { return capacity & 0x3fffffff; }
    ~F3Buffer()
    {
        releaseMemory();
    }
};

struct F3Stream
{
    void* vtable;
    int flags;
    void* writer;
    F3Stream(F3Buffer* buffer) { FUN_00943b30(buffer); }
    ~F3Stream() { FUN_00943a60(); }
    void FUN_00943b30(F3Buffer* buffer);
    void FUN_00943a60();
};

struct F3Map
{
    void* entries;
    int size;
    int capacity;
    F3Map() { FUN_00922cb0(); }
    ~F3Map() { FUN_00922cf0(); }
    void FUN_00922cb0();
    void FUN_00922cf0();
    void FUN_00922710(void* object, int offset);
};

struct F3Import
{
    int offset;
    void* name;
    int field08;
};

struct F3Fixups
{
    Relocation* local;
    int localCount;
    int localCapacity;
    F3Import* imports;
    int importCount;
    int importCapacity;
    void* exports;
    int exportCount;
    int exportCapacity;
    void* global;
    int globalCount;
    int globalCapacity;
    void* extra;
    F3Fixups()
    {
        local = 0;
        localCount = 0;
        localCapacity = (int)0x80000000u;
        imports = 0;
        importCount = 0;
        importCapacity = (int)0x80000000u;
        exports = 0;
        exportCount = 0;
        exportCapacity = (int)0x80000000u;
        global = 0;
        globalCount = 0;
        globalCapacity = (int)0x80000000u;
        extra = 0;
    }
    ~F3Fixups() { FUN_009b2fd0(); }
    void FUN_009b2fd0();
};

struct F3Option
{
    int value;
    F3Option(const int* src) { FUN_009b2540(src); }
    void FUN_009b2540(const int* src);
};

struct F3Flag
{
    int value;
    F3Flag(int v) : value(v) {}
    F3Flag(const F3Flag& o) : value(o.value) {}
};

struct F3Writer
{
    void* vtable;
    int field04;
    int field08;
    int field0c;
    int position;
    int options;
    F3Writer(F3Option* a, F3Option* b, F3Flag f) { FUN_009b3190(a, b, f); }
    ~F3Writer() { FUN_009b31d0(); }
    void FUN_009b3190(F3Option* a, F3Option* b, F3Flag f);
    void FUN_009b31d0();
    int FUN_009b4850(void* object, int objectType, void* writer, int type, F3Fixups* fixups);
};

extern "C" void __cdecl FUN_009234e0(char* dst, const char* src, int size);

// pdb: `anonymous namespace'::copySomeObjects | hkVersionUtil.obj | fnv360_0822_retail, caller_sim, low
static __declspec(noinline) char* FUN_00dc12c0(IndexArray* indices, ObjectInput objectInput, OffsetInput offsetInput,
                                               CopyListener* listener)
{
    F3Buffer buffer;
    buffer.data = 0;
    buffer.size = 0;
    buffer.capacity = (int)0x80000000u;
    F3Stream stream(&buffer);
    F3Fixups fixups;
    F3Map map;
    int i;
    for (i = 0; i < indices->size; ++i)
    {
        int index = indices->data[i];
        ObjectEntry* object = &objectInput.p->data[index];
        F3Option first(&DAT_01061524);
        F3Option second(&DAT_01061524);
        F3Writer writer(&second, &first, F3Flag(0));
        OffsetEntry* entry = &offsetInput.p->data[index];
        int type = entry->type;
        entry->offset = buffer.size;
        map.FUN_00922710(object->object, buffer.size);
        writer.FUN_009b4850(object->object, object->type, stream.writer, type, &fixups);
    }
    if (buffer.size)
    {
    int size = buffer.size;
    char* result = GetHeap()->FUN_008f6d30(size, 5);
    listener->AddMemoryChunk(result, buffer.size, 5);
    FUN_009234e0(result, buffer.data, buffer.size);
    for (i = 0; i < indices->size; ++i)
    {
        OffsetEntry& e = offsetInput.p->data[indices->data[i]];
        e.offset += (int)result;
    }
    for (i = 0; i < fixups.localCount; ++i)
    {
        *(int*)(result + fixups.local[i].offset) = fixups.local[i].target + (int)result;
    }
    for (i = 0; i < fixups.importCount; ++i)
    {
        listener->addImport(fixups.imports[i].name, result + fixups.imports[i].offset);
    }
    return result;
    }
    return 0;
}


extern "C" IndexArray* get_indices();
char* invoke_copy(ObjectInput a, OffsetInput b, ListenerInput c)
{
    return FUN_00dc12c0(get_indices(), a, b, c.p);
}

inline ByteBuffer::~ByteBuffer()
{
    CopyAllocator* allocator = ((CopyRouter*)&FUN_00c85750())->allocator;
    size = 0;
    if ((capacity & (int)0x80000000u) == 0)
        allocator->release(data, capacity & 0x3fffffff);
}
