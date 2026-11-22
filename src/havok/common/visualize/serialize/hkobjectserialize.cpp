#include "f3_common.h"
// src/havok/common/visualize/serialize/hkobjectserialize.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkobjectserialize.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef unsigned int C68E30size_t;

struct C68E30Allocator;

struct C68E30MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C68E30Allocator* m_pStreamAllocator;

    C68E30Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" C68E30MemoryRouter& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct C68E30Listener
{
    int unk00;
};

struct C68E30Pair
{
    C68E30Listener* m_kListener;
    int m_uiFilterValue;

    static void* operator new(C68E30size_t, void* p) throw()
    {
        return p;
    }
};

struct C68E30PairArray
{
    C68E30Pair* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _pushBack(C68E30Allocator& alloc, const C68E30Pair& pair)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(C68E30Pair));
        new (m_data + m_iElementCount) C68E30Pair(pair);
        m_iElementCount++;
    }

    void AddBack(const C68E30Pair& pair)
    {
        _pushBack(FUN_00c85750().heap(), pair);
    }
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* volatile m_pAllocator;
};

namespace fnvc_adapt {
AudioHolder* __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(void* apOwner, void* apArray, int aiSize, int aiAlign);

struct SweptVirtualObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(void* apItem, int aiFlag, int aiZero);
};

struct SweptItemArray
{
    void** m_00;
    int m_04;
    unsigned int m_08;
};

struct SweptEntry
{
    int unk00;
    SweptItemArray m_04;
};

struct FUN_00d641f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    SweptVirtualObj* m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    SweptEntry** m_30;
    int m_34;

    void ClearSweptEntry(int aiIndex);
};

// @f3 0x009f0c30 (community match, verified in this file)
extern int DAT_011697ec;
void __cdecl FUN_00901e90(void* array, int count, int elementSize);

// pdb: hkpSweptTransformDisplayViewer::removeAllGeometries | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, objrun, medium
// pdb params: worldIndex
void FUN_00d641f0_cls::ClearSweptEntry(int index)
{
    SweptEntry* entry = m_30[index];
    int i = 0;
    if (entry->m_04.m_04 > 0)
    {
        do
        {
            m_18->v14(entry->m_04.m_00[i], DAT_011697ec, 0);
            ++i;
        } while (i < entry->m_04.m_04);
    }
    SweptItemArray* array = &entry->m_04;
    int capacity = static_cast<int>(array->m_08 & 0x3fffffffu);
    if (capacity < 0)
        FUN_00901e90(array, capacity * 2 > 0 ? capacity * 2 : 0, 4);
    array->m_04 = 0;
}


struct Sink
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual bool* Get(bool* out) throw();
    virtual void Put(const void* data, unsigned int size) throw();
};

struct Entry8
{
    unsigned int first, second;
};
struct Entry16
{
    unsigned int first, second, third, unused;
};
struct Data
{
    Entry8* pairs;
    unsigned int pairCount;
    unsigned int pairCapacity;
    Entry16* triples;
    unsigned int tripleCount;
};

struct ByteSwap
{
    bool value;
};
struct Buffer
{
    void* vtable;
    unsigned short state, references;
    Sink* stream;
    bool byteSwap;
    void FUN_00d60830(Sink*, ByteSwap) throw();
    void hkOArchive_write64u(unsigned int, unsigned int) throw();
    void WriteInt(unsigned int) throw();
    void hkOArchive_write32u(unsigned int) throw();
    void FUN_00d60590() throw();
};

// Serializes a1-a4, data pairs/triples, and payload into sink via buffer, returning total bytes written or -1 on failure.
// @f3 0x00a8b5b0 (community match, verified in this file)
namespace Task1491 { struct Entry12 { unsigned first,second,third; }; }
// @fnv 0x00e0b850
// pdb: _writeData | hkObjectSerialize.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(caller_sim), high
static __declspec(noinline) int _writeData(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4,
                                             const void* payload, unsigned int payloadBytes, ByteSwap byteSwap,
                                             Data* data, Sink* sink)
{
    bool status;
    unsigned int bytes;
    unsigned int count;
    Buffer buffer;
    buffer.FUN_00d60830(sink, byteSwap);
    buffer.hkOArchive_write64u(a1, a2);
    if (!*sink->Get(&status))
    {
        buffer.FUN_00d60590();
        return -1;
    }
    buffer.hkOArchive_write64u(a3, a4);
    if (!*sink->Get(&status))
    {
        buffer.FUN_00d60590();
        return -1;
    }
    count = data->pairCount;
    buffer.hkOArchive_write32u(count);
    bytes = 0x14;
    for (unsigned int i = 0; i < count; ++i)
    {
        buffer.WriteInt(data->pairs[i].first);
        buffer.WriteInt(data->pairs[i].second);
        if (!*sink->Get(&status))
        {
            buffer.FUN_00d60590();
            return -1;
        }
        bytes += 8;
    }
    count = data->tripleCount;
    buffer.hkOArchive_write32u(count);
    bytes += 4;
    for (unsigned int i = 0; i < count; ++i)
    {
        buffer.WriteInt(((Task1491::Entry12*)data->triples)[i].first);
        buffer.hkOArchive_write64u(((Task1491::Entry12*)data->triples)[i].second, 0);
        buffer.hkOArchive_write64u(((Task1491::Entry12*)data->triples)[i].third, 0);
        if (!*sink->Get(&status))
        {
            buffer.FUN_00d60590();
            return -1;
        }
        bytes += 20;
    }
    buffer.hkOArchive_write32u(payloadBytes);
    if (!*sink->Get(&status))
    {
        buffer.FUN_00d60590();
        return -1;
    }
    sink->Put(payload, payloadBytes);
    if (!*sink->Get(&status))
    {
        buffer.FUN_00d60590();
        return -1;
    }
    buffer.FUN_00d60590();
    return bytes + payloadBytes + 4;
}


int SerializeData(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, const void* payload,
                  unsigned int payloadBytes, ByteSwap byteSwap, Data* data, Sink* sink)
{
    return _writeData(a1, a2, a3, a4, payload, payloadBytes, byteSwap, data, sink);
}

struct C68E30Allocator
{
    virtual ~C68E30Allocator() throw();
    virtual void unk04() throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
};

void __cdecl FUN_00c908c0(void* alloc, void* array, int numElements, int sizeElem);

struct hkBool
{
    char m_cBooleanValue;
    hkBool() throw()
    {}
    hkBool(bool b) throw() : m_cBooleanValue(b ? 1 : 0)
    {}
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
};

struct hkStreamReader
{
    virtual ~hkStreamReader() throw();
    virtual void unk04() throw();
    virtual void unk08() throw();
    virtual hkBool IsStreamValid() const throw();
    virtual int read(void* buf, int nbytes) throw();
};

struct Reloc
{
    int m_iSourceOffset;
    int toOffset;
};

struct Item24
{
    int field00;
    int field04;
    __int64 field08;
    __int64 field10;
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    __forceinline void ClearAndRelease(C68E30Allocator& alloc) throw()
    {
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc.ReleaseBlock(m_data, (cap & 0x3fffffff) * sizeof(T));
        }
    }

    __forceinline void SetSizeAndGrow(C68E30Allocator& alloc, int size) throw()
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < size)
        {
            int newCap = cap + cap;
            if (size >= newCap)
                newCap = size;
            FUN_00c908c0(&alloc, this, newCap, sizeof(T));
        }
        m_iElementCount = size;
    }

    __forceinline T& operator[](int index)
    {
        return m_data[index];
    }
};

// Reads a header, tag, relocation table, item list, and allocated buffer from a stream, applies relocations to the buffer, and returns the header value.
// @f3 0x00a8b770 (community match, verified in this file)
#include <windows.h>
extern DWORD DAT_010f3170;
struct ReadAllocator {
 void FUN_008f6d90(void*, int, int);
 void* FUN_008f6f60(int, int);
 void FUN_008f6f90(void*);
 template <typename T> __forceinline void freeArray(T* const& data, int count) { FUN_008f6d90(data, count*int(sizeof(T)), 0x17); }
};
void __cdecl FUN_00901e90(void*, int, int);
template <typename T> __forceinline void ReleaseRelocs(hkArray<T>& a) throw() {
 if((a.m_iCapacityState&0x80000000)==0) {
  int n=a.m_iCapacityState&0x3fffffff;
  ((ReadAllocator*)TlsGetValue(DAT_010f3170))->freeArray(a.m_data, n);
 }
}
template <typename T> __forceinline void GrowRelocs(hkArray<T>& a,int size) throw() {
 int cap=a.m_iCapacityState&0x3fffffff;
 if(cap<size) {int newCap=cap+cap; if(size>=newCap)newCap=size; FUN_00901e90(&a,newCap,sizeof(T));}
 a.m_iElementCount=size;
}
template <typename T> __forceinline void GrowItems(hkArray<T>& a,int size) throw() {
 int cap=a.m_iCapacityState&0x3fffffff;
 if(cap<size) {int size2=size; int newCap=cap+cap; int n=size; if(n<newCap)n=newCap; FUN_00901e90(&a,n,sizeof(T));}
 a.m_iElementCount=size;
}
// pdb: hkObjectSerialize::readObject | hkObjectSerialize.obj | fnv360_0822_retail, objrun, medium
// pdb params: s, data, dataSize, globalFixups, klassID
unsigned __int64 __cdecl ReadRelocatedData(hkStreamReader* stream, char** outBuffer, int* outAllocSize,
                                           hkArray<Item24>& outItems, void* tag)
{
    int numRelocs;
    int numItems;
    int i;
    unsigned __int64 header;

    stream->read(&header, 8);
    if (!stream->IsStreamValid())
        return 0;

    stream->read(tag, 8);
    if (!stream->IsStreamValid())
        return 0;

    hkArray<Reloc> relocs;
    stream->read(&numRelocs, 4);
    if (!stream->IsStreamValid())
    {
        ReleaseRelocs(relocs);
        return 0;
    }

    int count = numRelocs;
    GrowRelocs(relocs,count);
    for (i = 0; i < (unsigned int)numRelocs; ++i)
    {
        Reloc& r = relocs[i];
        stream->read(&r.m_iSourceOffset, 4);
        stream->read(&r.toOffset, 4);
        if (!stream->IsStreamValid())
        {
            ReleaseRelocs(relocs);
            return 0;
        }
    }

    stream->read(&numItems, 4);
    if (!stream->IsStreamValid())
    {
        ReleaseRelocs(relocs);
        return 0;
    }

    count = numItems;
    GrowItems(outItems,count);
    for (i = 0; i < (unsigned int)numItems; ++i)
    {
        char* item = (char*)&outItems[i];
        stream->read(item, 4);
        stream->read(item + 8, 8);
        stream->read(item + 16, 8);
        if (!stream->IsStreamValid())
        {
            ReleaseRelocs(relocs);
            return 0;
        }
    }

    stream->read(outAllocSize, 4);
    if (!stream->IsStreamValid())
    {
        ReleaseRelocs(relocs);
        return 0;
    }

    int iAllocationSize = *outAllocSize;
    ReadAllocator* alloc=(ReadAllocator*)TlsGetValue(DAT_010f3170);
    char* buffer = (char*)alloc->FUN_008f6f60(iAllocationSize, 0x35);
    stream->read(buffer, *outAllocSize);
    if (!stream->IsStreamValid())
    {
        ReadAllocator* freeAlloc=(ReadAllocator*)TlsGetValue(DAT_010f3170);
        freeAlloc->FUN_008f6f90(buffer);
        ReleaseRelocs(relocs);
        return 0;
    }

    for (i = 0; i < (unsigned int)numRelocs; ++i)
    {
        int m_iSourceOffset = relocs[i].m_iSourceOffset;
        if (m_iSourceOffset >= 0)
        {
            *(char**)(buffer + m_iSourceOffset) = buffer + relocs[i].toOffset;
        }
    }

    *outBuffer = buffer;
    unsigned __int64 ret = header;
    ReleaseRelocs(relocs);
    return ret;
}


struct ObjectWriteFlag
{
    char value;
    ObjectWriteFlag(bool b) : value(b)
    {}
    ObjectWriteFlag(const ObjectWriteFlag& b) : value(b.value)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
static __declspec(noinline) int _writeData(Data* fixups, Sink* output, unsigned int idLow, unsigned int idHigh,
                                             unsigned int classLow, unsigned int classHigh, const void* payload,
                                             unsigned int payloadSize, ObjectWriteFlag swap)
{
    bool ok;
    unsigned int total;
    unsigned int count;
    Buffer archive;
    ByteSwap endian;
    endian.value = swap;
    archive.FUN_00d60830(output, endian);
    archive.hkOArchive_write64u(idLow, idHigh);
    if (!*output->Get(&ok))
    {
        archive.FUN_00d60590();
        return -1;
    }
    archive.hkOArchive_write64u(classLow, classHigh);
    if (!*output->Get(&ok))
    {
        archive.FUN_00d60590();
        return -1;
    }
    count = fixups->pairCount;
    archive.hkOArchive_write32u(count);
    total = 20;
    for (unsigned int j = 0; j < count; ++j)
    {
        archive.WriteInt(fixups->pairs[j].first);
        archive.WriteInt(fixups->pairs[j].second);
        if (!*output->Get(&ok))
        {
            archive.FUN_00d60590();
            return -1;
        }
        total += 8;
    }
    count = fixups->tripleCount;
    archive.hkOArchive_write32u(count);
    total += 4;
    for (unsigned int j = 0; j < count; ++j)
    {
        archive.WriteInt(fixups->triples[j].first);
        archive.hkOArchive_write64u(fixups->triples[j].second, 0);
        archive.hkOArchive_write64u(fixups->triples[j].third, 0);
        if (!*output->Get(&ok))
        {
            archive.FUN_00d60590();
            return -1;
        }
        total += 20;
    }
    archive.hkOArchive_write32u(payloadSize);
    if (!*output->Get(&ok))
    {
        archive.FUN_00d60590();
        return -1;
    }
    output->Put(payload, payloadSize);
    if (!*output->Get(&ok))
    {
        archive.FUN_00d60590();
        return -1;
    }
    archive.FUN_00d60590();
    return total + payloadSize + 4;
}

struct ObjectWriteItem
{
    int m_00;
    int unk04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct ObjectWriteArrItem
{
    ObjectWriteItem* m_data;
    int m_iElementCount;
    int m_cap;
};

struct ObjectWriteInfo
{
    char unk00;
    char m_01;
};

extern char DAT_011b7b89;

// Writes an object record to a sink by serializing its fixups and payload via _writeData, returning the total bytes written.
// @f3 0x00a8bb00 (community match, verified in this file)
#include <windows.h>
struct NativeFixup {
    int offset;
    int objectId;
    int classId;
};
struct NativeFixupArray {
    void* data;
    int count;
    int capacity;
};
struct NativeWriteFixups {
    void* pairs;
    int pairCount;
    int pairCapacity;
    NativeFixup* triples;
    int tripleCount;
    int tripleCapacity;
    NativeFixupArray imports;
    NativeFixupArray exports;
    int extra;
    void FUN_009b2fd0();
};
struct NativeByteArray {
    union { char* data; NativeByteArray* nextFree; };
    int size;
    int capacity;
};
struct NativeArrayWriter {
    const void* vtable;
    unsigned int refState;
    NativeByteArray* buffer;
    int offset;
    int skipRelease;
    void FUN_00943bb0(NativeByteArray*, int);
};
struct NativeCopier {
    int unk00, unk04, unk08, unk0c;
    void FUN_00a4c8d0(ObjectWriteInfo*);
    void FUN_00a4c7a0(NativeArrayWriter*, int, unsigned int, NativeWriteFixups*);
    void FUN_00a4c9c0();
};
struct NativeThreadMemory {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    int cacheLimit;
    int unk38, unk3c, unk40, unk44;
    NativeByteArray* cacheHead;
    int cacheCount;
    void FUN_008f6d90(void*, int, int);
    void FUN_008f6890(int, void*, int);
};
extern char DAT_00e7a244, DAT_00dcc494;
extern unsigned long DAT_010f3170;
extern void __cdecl FUN_00901f10(void*, int);
// pdb: hkObjectSerialize::writeObject | hkObjectSerialize.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: s, destLayout, dataID, data, klass, globalFixups
int __cdecl FUN_00e0bd40(Sink* sink, ObjectWriteInfo* layout, unsigned int idLow,
                         unsigned int idHigh, int source, unsigned int size, ObjectWriteArrItem* output)
{
    const int nonOwningCapacity = static_cast<int>(0x80000000u);
    const int capacityMask = 0x3fffffff;
    const int streamMemoryClass = 0x17;
    NativeCopier copier;
    copier.FUN_00a4c8d0(layout);
    NativeByteArray bytes;
    bytes.data = 0;
    bytes.size = 0;
    bytes.capacity = nonOwningCapacity;
    NativeArrayWriter writer;
    writer.FUN_00943bb0(&bytes, 1);
    NativeWriteFixups fixups;
    fixups.pairs = 0;
    fixups.pairCount = 0;
    fixups.pairCapacity = nonOwningCapacity;
    fixups.triples = 0;
    fixups.tripleCount = 0;
    fixups.tripleCapacity = nonOwningCapacity;
    fixups.imports.data = 0;
    fixups.imports.count = 0;
    fixups.imports.capacity = nonOwningCapacity;
    fixups.exports.data = 0;
    fixups.exports.count = 0;
    fixups.exports.capacity = nonOwningCapacity;
    fixups.extra = 0;
    copier.FUN_00a4c7a0(&writer, source, size, &fixups);
    const int requested = output->m_iElementCount + fixups.tripleCount;
    const int capacity = output->m_cap & capacityMask;
    if (capacity < requested) {
        const int grown = capacity + capacity;
        FUN_00901e90(output, requested >= grown ? requested : grown, sizeof(ObjectWriteItem));
    }
    for (int i = 0; i < static_cast<int>(fixups.tripleCount); ++i) {
        if (output->m_iElementCount == (output->m_cap & capacityMask)) {
            FUN_00901f10(output, sizeof(ObjectWriteItem));
        }
        ObjectWriteItem& slot = output->m_data[output->m_iElementCount++];
        slot.m_00 = fixups.triples[i].offset;
        slot.m_08 = fixups.triples[i].objectId;
        slot.m_0c = 0;
        slot.m_10 = fixups.triples[i].classId;
        slot.m_14 = 0;
    }
    int written = _writeData((Data*)&fixups, sink, idLow, idHigh, size, 0, bytes.data, bytes.size, ObjectWriteFlag(layout->m_01 != DAT_011b7b89));
    fixups.FUN_009b2fd0();
    writer.vtable = &DAT_00e7a244;
    if (writer.skipRelease == 0) {
        NativeByteArray* header = writer.buffer;
        if (header) {
            if ((header->capacity & nonOwningCapacity) == 0)
                ((ReadAllocator*)::TlsGetValue(DAT_010f3170))->freeArray(header->data, header->capacity & capacityMask);
            NativeThreadMemory* memory = static_cast<NativeThreadMemory*>(::TlsGetValue(DAT_010f3170));
            if (static_cast<volatile NativeThreadMemory*>(memory)->cacheCount >= memory->cacheLimit) {
                memory->FUN_008f6890(2, header, streamMemoryClass);
            } else {
                NativeByteArray* head = memory->cacheHead;
                ++memory->cacheCount;
                header->nextFree = head;
                memory->cacheHead = header;
            }
        }
    }
    writer.vtable = &DAT_00dcc494;
    if ((bytes.capacity & nonOwningCapacity) == 0)
        ((ReadAllocator*)::TlsGetValue(DAT_010f3170))->freeArray(bytes.data, bytes.capacity & capacityMask);
    copier.FUN_00a4c9c0();
    return written;
}

