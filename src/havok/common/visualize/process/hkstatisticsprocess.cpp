#include "f3_common.h"
// src/havok/common/visualize/process/hkstatisticsprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/process/hkstatisticsprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiCapacity) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct ArrayMember
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~ArrayMember() throw()
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->FreeArray(m_pData, uCapacity & 0x3fffffff);
        m_pData = 0;
        m_uCapacity = 0x80000000;
    }
};

struct PtrArrayMember
{
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~PtrArrayMember() throw()
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->FreeArray(m_ppData, (uCapacity & 0x3fffffff) * 4);
        m_ppData = 0;
        m_uCapacity = 0x80000000;
    }
};

struct FirstBase
{
    virtual void a00();
    int m_i04;

    virtual ~FirstBase() throw()
    {}
};

struct SecondBase
{
    virtual void b00();

    virtual ~SecondBase() throw()
    {}
};

extern int DAT_01269cd8;

// @fnv 0x00ddc820
// pdb: hkpShapeDisplayViewer::getProcessTag | hkpShapeDisplayViewer.obj | fnv360_0822_retail, vtable, medium
int FUN_00ddc820()
{
    return DAT_01269cd8;
}

#include <windows.h>
struct TlsBuf
{
    int* m_pCurrent;
    int* m_pRecordEnd;
};
struct Allocator
{
    virtual void a0();
    virtual void a1();
    virtual void a2(void* p, int bytes);
    virtual void* Alloc(int* pBytes);
    virtual void Free(void* p, int bytes);
};
struct Singleton
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Allocator* m_10;
};
__forceinline Singleton* GetSingleton()
{
    return reinterpret_cast<Singleton*>(FUN_00c85750());
}
void __cdecl ResizeAudioStream(Allocator* ctx, void* pVec, int elem);
void __cdecl FUN_00c908c0(Allocator* ctx, void* pVec, int sz, int elem);
struct SrcArr
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};
struct Entry
{
    int m_00;
    int m_04;
    SrcArr m_08;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    SrcArr m_2c;
};
struct Pair
{
    int m_00;
    int m_04;
};
struct ObjA
{
    Pair* m_pData;
    int m_04;
    int m_iArrayLength;
    void EnsureCapacity(Allocator* ctx, int zero);
    void ProcessArgument(Allocator* ctx);
    void FUN_00a29680();
    __forceinline int first() const
    {
        int i;
        for (i = 0; i <= m_iArrayLength; ++i)
            if (m_pData[i].m_00 != -1)
                break;
        return i;
    }
    __forceinline int next(int previous) const
    {
        int i;
        for (i = previous + 1; i <= m_iArrayLength; ++i)
            if (m_pData[i].m_00 != -1)
                break;
        return i;
    }
    __forceinline bool valid(int i) const
    {
        return i <= m_iArrayLength;
    }
};
struct Sub8
{
    int m_00;
    int m_04;
    void FUN_00cb0c10(int a);
};
struct Elem16
{
    long long m_00;
    Sub8 m_08;
    void FUN_00e0bf20();
};
struct Vec3
{
    Elem16* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void FUN_00e0f6e0();
    void FUN_00ddc870();
    __forceinline Elem16& expand(Allocator& allocator)
    {
        if (m_iArrayLength == (m_iCapacity & 0x3fffffff))
            ResizeAudioStream(&allocator, this, 0x10);
        Elem16* item = m_pData + m_iArrayLength;
        if (item != 0)
            item->FUN_00e0bf20();
        return m_pData[m_iArrayLength++];
    }
};
struct CharVec
{
    char* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};
__forceinline void ReserveChars(Allocator& allocator, CharVec* array, int count)
{
    int cap = array->m_iCapacity & 0x3fffffff;
    if (cap < count)
    {
        int grown = cap + cap;
        FUN_00c908c0(&allocator, array, count < grown ? grown : count, 1);
    }
}
struct Elem12
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
struct Vec4
{
    Elem12* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};
struct MiniStr
{
    char* m_00;
    void FUN_00dc1680(void* p);
};
struct SObj
{
    void* m_00;
    short m_04;
    short m_06;
    CharVec* m_08;
    int m_0c;
    int m_10;
};
void __cdecl FUN_00e0bd40(SObj* s, MiniStr* ms, int a, int b, Vec3* v3, void* g, Vec4* v4);
struct Stream
{
    void hkOArchive_write32u(int total);
    void hkOArchive_write8u(int a);
    void WriteInt(int a);
    void FUN_00d607b0(int a, int b);
};
struct ThisCls
{
    int m_00;
    int m_04;
    int m_08;
    Stream* m_0c;
    int m_10;
    int m_14;
    Entry** m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    CharVec m_30;
    Stream* m_0c_ptr()
    {
        return (Stream*)m_0c;
    }
    void WriteToStream(int arg);
};
// When sum is positive, writes m_24 data, m_30 text, and ranges derived from m_18 to m_0c, then frees local buffers.
// @f3 0x00a63f10 (community match, verified in this file)
namespace N63f10 {

extern unsigned long DAT_010f3170;
extern unsigned long DAT_0116913c;

struct hkFreeElem
{
    hkFreeElem* m_next;
};

struct hkFreeList
{
    hkFreeElem* m_head;
    int m_numElem;

    __forceinline void put(void* p)
    {
        m_numElem++;
        hkFreeElem* n = static_cast<hkFreeElem*>(p);
        n->m_next = m_head;
        m_head = n;
    }
};

struct hkThreadMemory
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
    int m_maxNumElemsOnFreeList;
    hkFreeList m_free_list[8];

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)TlsGetValue(DAT_010f3170);
    }
    void* allocateChunk(int nbytes, int cl) throw();
    void deallocateChunk(void* p, int nbytes, int cl) throw();
    void onRowFull(int row, void* p, int cl) throw();

    static __forceinline int constSizeToRow(int nbytes)
    {
        return (nbytes + 7) >> 3;
    }
    __forceinline void deallocateChunkConstSize(void* p, int nbytes, int cl)
    {
        int row = constSizeToRow(nbytes);
        if (m_free_list[row].m_numElem >= m_maxNumElemsOnFreeList)
        {
            onRowFull(row, p, cl);
        }
        else
        {
            m_free_list[row].put(p);
        }
    }
};

void __cdecl hkArray_reserve(void* arr, int n, int sizeElem) throw();
void __cdecl hkArray_reserveMore(void* arr, int sizeElem) throw();

template <class T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline ~hkArray()
    {
        releaseMemory();
    }
    __forceinline void releaseMemory()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0)
        {
            int n = getCapacity();
            hkThreadMemory::getInstance().deallocateChunk(m_data, n * sizeof(T), 0x17);
        }
    }
    __forceinline int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    __forceinline int getSize() const { return m_size; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline static void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; ++i)
            dst[i] = src[i];
    }
    __forceinline hkArray& operator=(const hkArray& a)
    {
        if (getCapacity() < a.m_size)
        {
            if ((m_capacityAndFlags & 0x80000000) == 0)
                hkThreadMemory::getInstance().deallocateChunk(m_data, getCapacity() * sizeof(T), 0x17);
            m_data = (T*)hkThreadMemory::getInstance().allocateChunk(a.m_size * sizeof(T), 0x17);
            m_capacityAndFlags = a.m_size | (m_capacityAndFlags & 0x40000000);
        }
        m_size = a.m_size;
        copy(m_data, a.m_data, m_size);
        return *this;
    }
    __forceinline void reserve(int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            hkArray_reserve(this, newSize, sizeof(T));
        }
    }
    __forceinline void setSize(int n)
    {
        reserve(n);
        m_size = n;
    }
    __forceinline T& expandOne()
    {
        if (m_size == getCapacity())
            hkArray_reserveMore(this, sizeof(T));
        return m_data[m_size++];
    }
    __forceinline void pushBack(const T& e)
    {
        if (m_size == getCapacity())
            hkArray_reserveMore(this, sizeof(T));
        m_data[m_size++] = e;
    }
    __forceinline static void operator delete(void* p)
    {
        hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkArray), 0x17);
    }
};

struct hkPointerMap
{
    int* m_elem;
    int m_numElems;
    int m_hashMod;

    hkPointerMap() throw();
    ~hkPointerMap() throw();

    __forceinline int getIterator() const
    {
        int i;
        for (i = 0; i <= m_hashMod; ++i)
            if (m_elem[i] != -1)
                break;
        return i;
    }
    __forceinline int getNext(int it) const
    {
        int i;
        for (i = it + 1; i <= m_hashMod; ++i)
            if (m_elem[i] != -1)
                break;
        return i;
    }
    __forceinline bool isValid(int it) const { return it <= m_hashMod; }
    __forceinline int getKey(int it) const { return m_elem[it]; }
    __forceinline int getValue(int it) const { return m_elem[m_hashMod + 1 + it]; }
};

struct StatEntry
{
    int unk00;
    int unk04;
    hkArray<int> m_starts;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    hkArray<int> m_ends;
};

struct StatRecord
{
    __int64 m_id;
    int m_value;
    int unk0c;
};

struct StatInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct hkBaseObject
{
    virtual ~hkBaseObject() {}
};

struct hkReferencedObject : hkBaseObject
{
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    __forceinline hkReferencedObject() { m_referenceCount = 1; }
    virtual ~hkReferencedObject() {}
};

struct hkStreamWriter : hkReferencedObject
{
    virtual ~hkStreamWriter() {}
    virtual int isOk() const throw();
    virtual int write(const void* buf, int nbytes) throw();
};

struct hkArrayStreamWriter : hkStreamWriter
{
    hkArray<char>* m_arr;
    int m_offset;
    int m_ownerShip;

    __forceinline hkArrayStreamWriter(hkArray<char>* arr, int o) : m_arr(arr), m_offset(arr->getSize()), m_ownerShip(o)
    {
        nullTerminate();
    }
    __forceinline void nullTerminate()
    {
        m_arr->reserve(m_arr->getSize() + 1);
        m_arr->m_data[m_arr->getSize()] = 0;
    }
    virtual ~hkArrayStreamWriter()
    {
        if (m_ownerShip == 0)
            delete m_arr;
    }
    virtual int isOk() const throw();
    virtual int write(const void* buf, int nbytes) throw();
};

struct LayoutRules
{
    int m_rules;
    LayoutRules(const LayoutRules& o) throw();
};
extern const LayoutRules DAT_00e7e644;
extern char DAT_0116ce90;

void __cdecl ProcessRange(int start, int end, hkPointerMap* map) throw();
void __cdecl SaveStatistics(hkStreamWriter* w, LayoutRules* rules, int a, int b, hkArray<StatRecord>* records,
    void* cls, hkArray<StatInfo>* infos) throw();

struct OArchive
{
    void writeSize(int n) throw();
    void write8(unsigned char v) throw();
    void write32(int v) throw();
    void writeRaw(const void* p, int n) throw();
};

}

using namespace N63f10;

// pdb: hkStatisticsProcess::step | hkStatisticsProcess.obj | fnv360_0822_retail, vtable, medium
// pdb params: frameTimeInMs
void ThisCls::WriteToStream(int aiUnused)
{
    if (m_0c == 0)
        return;
    hkArray<StatInfo> infos;
    hkArray<int> starts;
    hkArray<int> ends;
    for (int i = 0; i < m_1c; i++)
    {
        if (((StatEntry*)m_18[i])->m_starts.getSize() > 0)
        {
            starts = ((StatEntry*)m_18[i])->m_starts;
            ends = ((StatEntry*)m_18[i])->m_ends;
            break;
        }
    }
    if (starts.getSize() == 0)
    {
        TlsBuf* stream = (TlsBuf*)TlsGetValue(DAT_0116913c);
        int start = (int)stream->m_pCurrent;
        int end = (int)stream->m_pRecordEnd;
        starts.pushBack(start);
        ends.pushBack(end);
    }
    hkArray<char>* text = (hkArray<char>*)&m_30;
    text->setSize(0);
    int total = 0;
    {
        hkPointerMap map;
        hkArray<StatRecord> records;
        for (int i = 0; i < starts.getSize(); i++)
        {
            ProcessRange(starts[i], ends[i], &map);
            total += ends[i] - starts[i];
        }
        for (int it = map.getIterator(); map.isValid(it); it = map.getNext(it))
        {
            StatRecord& r = records.expandOne();
            r.m_id = map.getKey(it);
            r.m_value = map.getValue(it);
        }
        hkArrayStreamWriter writer(text, 1);
        LayoutRules rules(DAT_00e7e644);
        SaveStatistics(&writer, &rules, 1, 0, &records, &DAT_0116ce90, &infos);
    }
    if (total < 1)
        return;
    OArchive* out = (OArchive*)m_0c;
    int numRanges = starts.getSize();
    int dataLen = m_28;
    int textLen = m_30.m_iArrayLength;
    out->writeSize(textLen + numRanges * 4 + dataLen + total + 0xd);
    ((OArchive*)m_0c)->write8(10);
    ((OArchive*)m_0c)->write32(dataLen);
    if (dataLen > 0)
        ((OArchive*)m_0c)->writeRaw((const void*)m_24, dataLen);
    ((OArchive*)m_0c)->write32(textLen);
    if (textLen > 0)
        ((OArchive*)m_0c)->writeRaw(text->m_data, textLen);
    ((OArchive*)m_0c)->write32(numRanges);
    for (int i = 0; i < numRanges; i++)
    {
        int len = ends[i] - starts[i];
        ((OArchive*)m_0c)->write32(len);
        if (len > 0)
            ((OArchive*)m_0c)->writeRaw((const void*)starts[i], len);
    }
}


// sub ecx,8; jmp FUN_00ddc840 == MSVC adjustor thunk for the secondary base's slot.
struct PrimaryBase
{
    virtual void FUN_00ddc830();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00ddc830();
};

struct AdjustDerived : PrimaryBase, SecondaryBase
{
    AdjustDerived();
// @fnv 0x00ddc830
    virtual void FUN_00ddc830();
};

AdjustDerived::AdjustDerived()
{}

namespace fnv_00ddc840 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
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

struct FUN_00ddc840
{
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00ddc840();
    virtual ~FUN_00ddc840();
    static void operator delete(void* apMemory)
    {
        AudioHolder* pHolder = FUN_00c85750();
        unsigned int uiSize = ((FUN_00ddc840*)apMemory)->m_u04;
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, uiSize);
    }
};

// Initialises m_u04 and m_u06 to zero.
// @fnv 0x00ddc840
FUN_00ddc840::FUN_00ddc840()
{
    m_u04 = 0;
    m_u06 = 0;
}
}  // namespace fnv_00ddc840

struct Sbf00_Sub
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    void InitHeading();
};
struct Sbf00_Ctx
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Sbf00_Sub m_kSub;
    float m_f24;
    float m_f28;
    int unk2c;
    int unk30;
    int unk34;
    void FUN_00cc06f0(ArrayMember* apArr, int a2);
    void FUN_00cc0780();
};
struct Sbf00_Name
{
    int unk00;
    int unk04;
    void FUN_00dc1680(void* apStr);
};
struct Sbf00_Arr24
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;
    void Free()
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->FreeArray(m_pData, (uCapacity & 0x3fffffff) * 24);
    }
};
extern int DAT_010d1508;
extern int DAT_010d7e48;
extern int DAT_010d7e28;
void __cdecl FUN_00e0bd40(Sbf00_Ctx* a1, Sbf00_Name* a2, int a3, int a4, Sbf00_Sub* a5, void* a6, Sbf00_Arr24* a7);
struct SbfRef
{
    void* m_pVtbl;
    unsigned short unk04;
    unsigned short m_uRefCount;
    SbfRef() : m_uRefCount(1)
    {}
};
struct SbfProc
{
    void* m_pVtbl;
    unsigned char m_bFlag;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SbfProc() : m_pVtbl(&DAT_010d1508), m_bFlag(1)
    {}
};
struct SbfBases : SbfRef, SbfProc
{
    SbfBases()
    {
        SbfRef::m_pVtbl = &DAT_010d7e48;
        SbfProc::m_pVtbl = &DAT_010d7e28;
    }
};
struct SbfPtrs
{
    void** m_ppData;
    int m_iArrayLength;
    unsigned m_uCapacity;
    SbfPtrs() : m_ppData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {}
};
struct SbfBytes
{
    void* m_pData;
    int m_iArrayLength;
    unsigned m_uCapacity;
    SbfBytes() : m_pData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {}
};

namespace fnv_00ddc870 {
struct FixedAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* p, unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FixedAllocator* m_pAllocator;
};

AllocHolder* FUN_00c85750();

}  // namespace fnv_00ddc870
