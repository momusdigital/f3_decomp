#include "f3_common.h"
// src/staging/blk_00e80000_o2_noehsc_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/staging/blk_00e80000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern "C" void __cdecl operator delete(void* p, unsigned int size);
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
extern int DAT_010f0e50;
extern "C" void __cdecl NiFree(void*);
void __cdecl NiFree(void*);
extern "C" void __cdecl operator delete(void* p, unsigned int size);
extern int DAT_0126fa58;
void __cdecl _NiFree(void* p);
extern int DAT_010efdd8;
extern int DAT_010efdf8;
extern int DAT_010efdd8;
void __cdecl _NiFree(void* p);
void __cdecl _NiFree(void* p);
extern int DAT_010efe54;
extern MemoryManager _g_memoryManager;
extern int DAT_010efe54;
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void*);
extern "C" void __cdecl operator delete(void*, unsigned int);
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void* p);
extern int DAT_010f0df0;
extern int DAT_010f0e10;
void __cdecl _NiFree(void* p);
void _NiFree(void* p);
extern int DAT_010f0df0;
extern "C" void __cdecl NiFree(void*);
extern int DAT_010f0df0;
extern int DAT_010f0e10;
extern MemoryManager _g_memoryManager;
void __cdecl NiFree(void* p);
extern int DAT_010f0e50;
extern MemoryManager g_memoryManager;
void __cdecl _NiFree(void* p);
struct NiTMapBase
{
    bool __thiscall RemoveAt(const char* name);
};
struct Program
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual const char* v50();

    void* m_auiShapeKeys[5];
    NiTMapBase* m_map;
};
Program* DAT_0126fa10;
void __cdecl _NiFree(void* p);
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void*);
extern "C" void __cdecl operator delete(void* p, unsigned int size);
extern int DAT_0126fa58;
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};
extern MemoryManager _g_memoryManager;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern const char* g_pcNullStringE81;
class NiFixedStringE81
{
  public:
    ~NiFixedStringE81() throw()
    {
        if (m_kHandle != g_pcNullStringE81)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }

    const char* m_kHandle;
};
class NiRefObjectE81
{
  public:
    virtual ~NiRefObjectE81() throw()
    {
        InterlockedDecrement(&ms_lObjectCount);
    }

    unsigned int m_uiRefCount;

    static long ms_lObjectCount;
};
struct E87B60AlphaProperty
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_uiObjectFlags;
    unsigned char m_ucAlphaThreshold;

    bool GetAlphaBlending() const
    {
        return (m_uiObjectFlags & 1) != 0;
    }
    unsigned int GetSrcBlendMode() const
    {
        return (m_uiObjectFlags >> 1) & 0xf;
    }
    unsigned int GetDestBlendMode() const
    {
        return (m_uiObjectFlags >> 5) & 0xf;
    }
    bool GetAlphaTesting() const
    {
        return ((unsigned short)(m_uiObjectFlags >> 9) & 1) != 0;
    }
    unsigned int GetTestMode() const
    {
        return (m_uiObjectFlags >> 10) & 7;
    }
    unsigned char GetTestRef() const
    {
        return m_ucAlphaThreshold;
    }
};
class FUN_00e87c30_cls;
class FUN_00e87c30_arg
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned char unk18;
};
class FUN_00e87c30_cls
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a(int a, unsigned int b, int c, int d);

    void FUN_00e87c30(FUN_00e87c30_arg* a1);
};
extern unsigned int DAT_011bf558;
extern unsigned short DAT_0126f958[];
extern unsigned short DAT_0126f92c[];
// Decompiled: dispatch a table value to a virtual slot on this.
struct FUN_00e88780_D3DObject
{
    void* m_ppVirtualMethodTable;
};
typedef void(__stdcall* FUN_00e88780_D3DCall)(FUN_00e88780_D3DObject* pObject, int index, int value);
typedef void(__stdcall* FUN_00e88830_Slot)(void* self, int code, int value);
extern unsigned short DAT_0126f958[];
// 256-byte span of not-yet-identified fields.
// NiDX9RenderState::GetSamplerState
typedef void(__stdcall* FUN_00e88a20_Slot)(void* self, int code, int value);
// NiD3DGeometryGroupManager
//   RTTI name  : .?AVNiD3DGeometryGroupManager@@   (vftable @ 0x010ef718)
//   Layout from the constructor at 0x00e88eb0 (the object is 0x1c bytes big):
//     +0x00  vftable pointer
//     +0x04  dword      +0x08  dword      +0x0c  dword
//     +0x10  dword      +0x14  dword      +0x18  byte flag
//   The single caller (0x00e73547) pushes a 0/1 byte and calls this setter.
extern unsigned short DAT_0126f92c[];
extern unsigned int DAT_011bf558;
extern "C" void __cdecl FUN_00aa10f0(void*);
extern volatile long DAT_011f4400;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct FUN_00e89ae0_obj;
typedef int(__stdcall* FUN_00e89ae0_vfn)(FUN_00e89ae0_obj*, int, int, int);
struct FUN_00e89ae0_obj
{
    void** vtbl;
};
struct Key
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int mark;
};
struct Value
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int index;
};
struct Item
{
    Item* next;
    Key* key;
    Value* value;
};
struct PoolNode
{
    PoolNode* next;
    PoolNode* prev;
    void* data;
};
struct Com
{
    virtual void __stdcall f0();
    virtual void __stdcall f1();
    virtual void __stdcall Release();
};
struct Target
{
    virtual void f0();
    virtual unsigned int Hash(Key*);
    unsigned int bucketCount;
    Item** buckets;
    unsigned int count;
    PoolNode* head;
    PoolNode* tail;
    unsigned int listCount;
    Com* object;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    unsigned int bits[8];
    void ClearBit(unsigned int index)
    {
        unsigned int word = index >> 5;
        unsigned int mask = 1 << (index & 31);
        bits[word] &= ~mask;
    }
    Item* FUN_00ee8ac0();
    void FUN_00e8b630();
};
extern int DAT_010efdd8;
extern int DAT_010efdf8;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* p);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* cs);
void* __cdecl NiMemset(void* dst, int val, unsigned int size);
void* __cdecl NiMalloc(unsigned int size);
extern volatile long DAT_011f4400;
struct RefObjStub
{
    unsigned int m_uiRefCount;
    RefObjStub()
    {
        m_uiRefCount = 0;
        InterlockedIncrement(&DAT_011f4400);
    }
    virtual void DeleteThis();
};
struct MapBaseStub
{
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    MapBaseStub(unsigned int hashSize)
    {
        m_uiHashSize = hashSize;
        m_uiCount = 0;
        unsigned int size = sizeof(void*) * m_uiHashSize;
        m_ppkHashTable = (void**)NiMalloc(size);
        NiMemset(m_ppkHashTable, 0, sizeof(void*) * m_uiHashSize);
    }
    virtual void MapV0();
    void RemoveAll();
};
struct MapStub : MapBaseStub
{
    MapStub(unsigned int hashSize = 37) : MapBaseStub(hashSize)
    {}
    virtual void MapV1();
};
extern "C" char* DAT_0109b220;
extern "C" void(__stdcall* DAT_00fdf1c0)(void*);
extern "C" void(__stdcall* DAT_00fdf1c4)(void*);
struct ListNode_b5254
{
    ListNode_b5254* m_00;
    ListNode_b5254* m_04;
    unsigned int m_08;
};
static inline unsigned int& NextKey_b5254(ListNode_b5254*& pos)
{
    unsigned int& e = pos->m_08;
    pos = pos->m_00;
    return e;
}
extern "C" void __cdecl operator delete(void* p, unsigned int size);
typedef bool(__cdecl* FNV_CondFn_e9c8c0)(float, void*, unsigned int, void*, unsigned int);
class FUN_00e9c8c0_obj
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual unsigned int GetIndex();
};
bool __cdecl CallConditionFunction(float f, FUN_00e9c8c0_obj* a, unsigned int b, FUN_00e9c8c0_obj* c, unsigned int d);
typedef int(__cdecl* FUN_00e9c950_handler)(float, void*, int, void*, int, int, int, int, int, int);
class FUN_00e9c950_cls_key
{
  public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual int Slot3();
};
int DispatchPairHandler(float a1, FUN_00e9c950_cls_key* a2, int a3, FUN_00e9c950_cls_key* a4, int a5, int a6, int a7,
                        int a8, int a9, int a10);
struct DispatchObj_b4010
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};
typedef void(__cdecl* DispatchFn_b4010)(float, DispatchObj_b4010*, int, int, int, int, int);
struct FUN_00e9e840_Class
{
    virtual int m_virtual00(int value);
    virtual int m_virtual01(int value);
    virtual int m_virtual02(int value);
    virtual int m_virtual03(int value);
    virtual int m_virtual04(int value);
    virtual int m_virtual05(int value);
    virtual int m_virtual06(int value);
    virtual int m_virtual07(int value);
    virtual bool m_virtual08(int value);
    virtual bool m_virtual09(int value);

    bool __thiscall FUN_00e9e840(int value);
};
inline int FUN_00e9e840_Class::m_virtual01(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual02(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual03(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual04(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual05(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual06(int value)
{
    return value;
}
inline int FUN_00e9e840_Class::m_virtual07(int value)
{
    return value;
}
inline bool FUN_00e9e840_Class::m_virtual08(int value)
{
    return value != 0;
}
inline bool FUN_00e9e840_Class::m_virtual09(int value)
{
    return value != 0;
}
bool __cdecl CallConditionFunction(float a1, void* a2, unsigned int a3, void* a4, unsigned int a5);
bool __cdecl DispatchPairHandler(float f, void* item, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
// Candidate for FindMatchingPair (167 bytes)
//
// Searches two fixed-size index tables for a pair of entries that satisfy a
// comparison predicate.  On success the index of the outer table entry and of
// the inner table entry are stored back into the two table descriptors and the
// function reports true; otherwise it reports false.
static int to_int(float f)
{
    float t = f;
    return *(int*)&t;
}
// Grow the object pool: allocate a block of N entries and push every entry onto the free set.
class E94B0MemoryManager
{
  public:
    void* Allocate(unsigned int uiSize);
};
extern E94B0MemoryManager g_kE94B0MemoryManager;
struct E94B0Entry
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
};
E94B0Entry* __cdecl E94B0AllocEntries(unsigned int ItemUpdateArray) throw();
struct E94B0Block
{
    E94B0Block(unsigned int ItemUpdateArray) throw() : m_uiCount(ItemUpdateArray), m_pkNext(0)
    {
        if (ItemUpdateArray > 0)
            m_pkEntryArray = E94B0AllocEntries(ItemUpdateArray);
        else
            m_pkEntryArray = 0;
    }

    static void* operator new(unsigned int uiSize)
    {
        return g_kE94B0MemoryManager.Allocate(uiSize);
    }

    E94B0Entry* GetAt(unsigned int uiIndex)
    {
        if (uiIndex >= m_uiCount)
            return 0;
        return &m_pkEntryArray[uiIndex];
    }

    E94B0Entry* m_pkEntryArray;
    unsigned int m_uiCount;
    E94B0Block* m_pkNext;
};
class E94B0Pool
{
  public:
    E94B0Entry** m_ppkFree;
    unsigned int m_uiAllocated;
    unsigned int m_uiFree;
    E94B0Block* m_pkBlocks;

    void Realloc(unsigned int uiNewSize);

    void AddFree(E94B0Entry* pkEntry)
    {
        if (m_uiFree == m_uiAllocated)
            Realloc(m_uiAllocated > 0 ? 2 * m_uiAllocated : 1);
        m_ppkFree[m_uiFree] = pkEntry;
        m_uiFree++;
    }

    void AddBlock(unsigned int ItemUpdateArray);
};
extern "C" void __cdecl FUN_00aa10f0(void* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plValue);
extern char* DAT_0109b220;
struct StringTable
{
    static void IncRefCount(char* pcHandle)
    {
        if (pcHandle != DAT_0109b220)
            InterlockedIncrement((long volatile*)(pcHandle - 8));
    }
    static void DecRefCount(char* pcHandle)
    {
        if (pcHandle != DAT_0109b220)
            InterlockedDecrement((long volatile*)(pcHandle - 8));
    }
};
class FixedStr
{
  public:
    FixedStr& operator=(const FixedStr& kString)
    {
        if (m_kHandle != kString.m_kHandle)
        {
            char* pcHandle = kString.m_kHandle;
            StringTable::IncRefCount(pcHandle);
            StringTable::DecRefCount(m_kHandle);
            m_kHandle = pcHandle;
        }
        return *this;
    }
    char* m_kHandle;
};
// array new
// array delete
struct Ref_e98cb0
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
};
struct Ptr_e98cb0
{
    Ref_e98cb0* m_p;
    void Release()
    {
        Ref_e98cb0* r = m_p;
        if (r && InterlockedDecrement(&r->m_uiRefCount) == 0)
            r->DeleteThis();
    }
    void Clear()
    {
        Ref_e98cb0* r = m_p;
        if (r)
        {
            if (InterlockedDecrement(&r->m_uiRefCount) == 0)
                r->DeleteThis();
            m_p = 0;
        }
    }
};

extern "C" void* __cdecl FUN_00aa1420(unsigned int size);

struct SNAEntryElem
{
    unsigned char m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    unsigned char m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    unsigned char m_a8;
    int m_ac;
    int m_b0;
    unsigned char m_b4;

    SNAEntryElem() throw();
    ~SNAEntryElem()
    {}

    static void* operator new[](unsigned int size) throw()
    {
        return FUN_00aa1420(size);
    }
};

// @fnv 0x00e89460
// pdb: NiTMallocInterface<NiD3DPass *>::Allocate | NiD3DPass.obj | fnv360_0822_debug, objopen_prop, low, conflict (bridge: NiTNewInterface<NiGeomMorpherUpdateTask>::Allocate)
// pdb params: uiNumElements
SNAEntryElem* FUN_00e89460(unsigned int count)
{
    return new SNAEntryElem[count];
}
