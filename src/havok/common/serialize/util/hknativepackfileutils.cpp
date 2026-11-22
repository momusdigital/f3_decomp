#include "f3_common.h"
// src/havok/common/serialize/util/hknativepackfileutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hknativepackfileutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dc0ed0_class
{
    void FUN_00dc0ed0(int a, int b);
};

// @f3 0x00594950 (community match, verified in this file)
void __cdecl FUN_00594470(int first, int second, FUN_00dc0ed0_class* object, int repeated);
void FUN_00dc0ed0_class::FUN_00dc0ed0(int first, volatile int second) {
    FUN_00594470(first, second, this, second);
}


void __cdecl FUN_00dc0de0(void*, void*);

struct S_00dc0de0_Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int nbytes);
};

struct S_00dc0de0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dc0de0_Allocator* m_pStreamAllocator;
    S_00dc0de0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00dc0de0_Router* FUN_00c85750();

struct S_00dc0de0_Value
{
    int unk00;
    int unk04;
    void (*m_callback)(unsigned int key);
};

struct S_00dc0de0_Pair
{
    unsigned int key;
    S_00dc0de0_Value* val;
};

struct S_00dc0de0_Map
{
    S_00dc0de0_Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; i++)
            if (m_kPrimitiveElement[i].key != (unsigned int)-1)
                break;
        return i;
    }
    int getNext(int it) const
    {
        int i;
        for (i = it + 1; i <= m_iPairCount; i++)
            if (m_kPrimitiveElement[i].key != (unsigned int)-1)
                break;
        return i;
    }
    bool isValid(int it) const
    {
        return it <= m_iPairCount;
    }
    unsigned int GetIteratorKey(int it) const
    {
        return m_kPrimitiveElement[it].key;
    }
    S_00dc0de0_Value* getValue(int it) const
    {
        return m_kPrimitiveElement[it].val;
    }
    void ClearAndRelease(S_00dc0de0_Allocator& alloc);
    void FUN_00a29680();
};

struct S_00dc0de0_Elem
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
};

struct S_00dc0de0_Array
{
    S_00dc0de0_Elem* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(S_00dc0de0_Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(S_00dc0de0_Elem));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

extern char DAT_010d6ab4[];

// @fnv 0x00dc0eb0
void* __cdecl FUN_00dc0eb0()
{
    return DAT_010d6ab4;
}

extern "C" void __cdecl FUN_00c908c0(void*, void*, int, int) throw();
extern "C" void* DAT_010d6a94;

struct S_00dc0cd0_Alloc
{
    virtual void* unk00() throw();
    virtual void* AllocateMemoryBlock(int size) throw();
    virtual void ReleaseBlock(void* p, int size) throw();
    virtual void* AllocateBufferWithSize(int& req, int size) throw();
    virtual void ReturnMemory(void* p, int size) throw();
};

struct S_00dc0cd0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00dc0cd0_Alloc* m_pStreamAllocator;

    S_00dc0cd0_Alloc& heap() throw()
    {
        return *m_pStreamAllocator;
    }
    static S_00dc0cd0_Router& GetMonitorStream() throw()
    {
        return *(S_00dc0cd0_Router*)FUN_00c85750();
    }
};

struct S_00dc0cd0_Map
{
    void* LookupHashEntry(void* key, int defVal) throw();
};

struct S_00dc0cd0_Base0
{
    int unk00;
    int unk04;
};

struct S_00dc0cd0_Data : public S_00dc0cd0_Base0, public S_00dc0cd0_Map
{
};

struct S_00dc0cd0_MemberArray
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void init() throw()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }

    void SwapThreeInts(void* other) throw();
};

struct S_00dc0cd0_Array
{
    S_00dc0cd0_Data* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00dc0cd0_Array() throw()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }

    void GrowArrayCapacity(S_00dc0cd0_Alloc& alloc, int n) throw()
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int newCap = 2 * cap;
            if (n >= newCap)
                newCap = n;
            FUN_00c908c0(&alloc, this, newCap, 1);
        }
    }

    void _setSize(S_00dc0cd0_Alloc& alloc, int n) throw()
    {
        if ((m_iCapacityState & 0x3fffffff) < n)
        {
            GrowArrayCapacity(alloc, n);
        }
        m_iElementCount = n;
    }

    void SetSizeAndGrow(int n) throw()
    {
        _setSize(S_00dc0cd0_Router::GetMonitorStream().heap(), n);
    }

    ~S_00dc0cd0_Array() throw()
    {
        S_00dc0cd0_Alloc& alloc = S_00dc0cd0_Router::GetMonitorStream().heap();
        m_iElementCount = 0;
        int cap = m_iCapacityState;
        if ((cap & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, cap & 0x3fffffff);
        }
    }
};

namespace fnv_00dc0f20 {
extern int DAT_010d6a94;

void __cdecl FUN_00dc0de0(void*, void*);

}  // namespace fnv_00dc0f20

void __cdecl FUN_00cb1280(void* p, int a, int b);

struct hkPackfileHeader
{
    unsigned int m_magic0;
    unsigned int m_magic1;
    int m_uiUserTag;
    int m_iFileVersion;
    unsigned char m_layoutRules_0;
    unsigned char m_layoutRules_1;
    unsigned char m_layoutRules_2;
    unsigned char m_layoutRules_3;
    int m_iNumSections;
    int m_iContentsSectionIndex;
    int m_iContentsSectionOffset;
    int m_iContentsClassNameSectionIndex;
    int m_iContentsClassNameSectionOffset;
    unsigned char m_contentsVersion_0;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    int m_flags;
    int unk3c;

    hkPackfileHeader()
    {
        FUN_00cb1280(this, -1, sizeof(*this));
        m_magic0 = 0x57e0e057;
        m_magic1 = 0x10c0c010;
        m_contentsVersion_0 = 0;
    }
};

struct hkPackfileSectionHeaderN
{
    char m_acSectionTag[19];
    char m_cNullByte;
    int m_iAbsoluteDataStart;
    int m_iLocalFixupsOffset;
    int m_iGlobalFixupsOffset;
    int m_iVirtualFixupsOffset;
    int m_iExportsOffset;
    int m_iImportsOffset;
    int m_iEndOffset;
};

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

struct hkSectionArrayN
{
    hkPackfileSectionHeaderN* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkSectionArrayN(hkPackfileSectionHeaderN* p, int size, int capacity) throw()
        : m_data(p), m_iElementCount(size), m_iCapacityState(capacity | 0x80000000)
    {}
    hkPackfileSectionHeaderN& operator[](int i)
    {
        return m_data[i];
    }
};

struct hkLoadedObjectTrackerN
{
    int m_00;
    int m_04;
    int m_08;

    hkLoadedObjectTrackerN(void* buffer, int bufferSize) throw();
    void add(void* allocator, void* obj, const void* typeInfo) throw();
};

struct hkNativeHeaderN
{
    unsigned int m_kMagic;
    int m_iContentsVersion;
    hkLoadedObjectTrackerN m_pTracker;
    hkSectionArrayN m_sections;

    void* getSectionPointer(int sectionIndex, int offset)
    {
        return m_sections[sectionIndex].m_iLocalFixupsOffset != 0
                   ? (char*)this + m_sections[sectionIndex].m_iAbsoluteDataStart + offset
                   : 0;
    }
};

struct Entry_dc07b0
{
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
    int unk2C;
};

struct Table_dc07b0
{
    Entry_dc07b0* entries;
};

volatile int g_idx_dc07b0;
volatile int g_a_dc07b0;
volatile int g_b_dc07b0;
Table_dc07b0* volatile g_t_dc07b0;
volatile int g_out_dc07b0;

struct hkPackfileSectionHeader
{
    char m_acSectionTag[19];
    char m_cNullByte;
    int m_iAbsoluteDataStart;
    int m_iLocalFixupsOffset;
    int m_iGlobalFixupsOffset;
    int m_iVirtualFixupsOffset;
    int m_iExportsOffset;
    int m_iImportsOffset;
    int m_iEndOffset;

    int getDataSize() const
    {
        return m_iLocalFixupsOffset;
    }
    int getVirtualFixupsSize() const
    {
        return m_iExportsOffset - m_iVirtualFixupsOffset;
    }
    int getExportsSize() const
    {
        return m_iImportsOffset - m_iExportsOffset;
    }
    int getImportsSize() const
    {
        return m_iEndOffset - m_iImportsOffset;
    }
};

namespace fnv_00dc0f80 {
struct Allocator
{
    virtual void slot0();
    virtual void slot1();
    virtual void Free(void*, unsigned);
};
struct Manager
{
    unsigned flags, state, count, capacity;
    Allocator* allocator;
};
Manager* FUN_00c85750();
struct FUN_00dc0f80
{
    unsigned short allocationSize;
    FUN_00dc0f80();
    virtual ~FUN_00dc0f80();
    void operator delete(void* ptr)
    {
        Manager* manager = FUN_00c85750();
        manager->allocator->Free(ptr, static_cast<FUN_00dc0f80*>(ptr)->allocationSize);
    }
};
// @fnv 0x00dc0f80
FUN_00dc0f80::FUN_00dc0f80()
{}
}  // namespace fnv_00dc0f80

// @f3 0x00a80110 (community match, verified in this file)
namespace f3m_00a80110 {

struct ValA8 { int u0, u4; void (__cdecl *cb)(void*); };
struct MapA8 {
    void** m_elem; int m_numElems; int m_hashMod;
    int getIterator() const { int i; for (i = 0; i <= m_hashMod; ++i) if (m_elem[i] != (void*)-1) break; return i; }
    int isValid(int it) const { return it <= m_hashMod; }
    void* getKey(int it) const { return m_elem[it]; }
    ValA8* getValue(int it) const { return (ValA8*)m_elem[it + m_hashMod + 1]; }
    int getNext(int it) const { int i; for (i = it + 1; i <= m_hashMod; ++i) if (m_elem[i] != (void*)-1) break; return i; }
};
struct ObjA8 { int u0, u4, u8, uc; MapA8 m_map; void FUN_00a80110(); };
void __fastcall FUN_00922680(MapA8*);
// pdb: hkpToiCountViewer::reset | hkpToiCountViewer.obj | fnv360_0822_debug, caller_sim, low, conflict (skyrim: hkPackfileData::callDestructors)
void ObjA8::FUN_00a80110() {
    int i = m_map.getIterator();
    while (m_map.isValid(i)) {
        ValA8* v = m_map.getValue(i);
        void (__cdecl *cb)(void*) = v->cb;
        if (cb) cb(m_map.getKey(i));
        i = m_map.getNext(i);
    }
    FUN_00922680(&m_map);
}
}   // namespace f3m_00a80110
