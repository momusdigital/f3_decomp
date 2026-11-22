// src/staging/blk_00ca0000_o2_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00ca0000_o2.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// SSE_DECLARATIONS_DEFER_TO_SDK
#include <windows.h>
// src/staging/blk_00ca0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
void __cdecl _delete(void* p, int);
extern "C" void NiFreeAlias(void*);
struct FUN_00ca5310_class
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_p;
};
float __fastcall GetField24Float(struct FUN_00ca5310_class* pClass);
void __cdecl _delete(void* p, unsigned int size);
extern "C" int __cdecl hkString_strLen(int);
extern "C" void __cdecl operator delete(void*, unsigned int);
extern int DAT_010c7310;
void __cdecl FUN_00ca4490();
struct MemoryManager
{
    void __thiscall Deallocate(void* p);
};
extern MemoryManager _g_memoryManager;
struct bhkRefObject
{
    int __thiscall Initialize();
};
extern int DAT_01030bf4;
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_01268324;
extern void(__cdecl* DAT_010c8d08)(void*);
extern int(__stdcall* DAT_00fdf1c4)(void*);
extern void(__stdcall* DAT_00fdf1c0)(void*);
extern int DAT_010c44e4;
extern int DAT_010c761c;
extern int DAT_012682d8;
extern int DAT_012686d0;
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};
struct S_00cb79d0_Base : public A51BF0Base
{
    void* m_vptr;
    char m_iWordAt04[8];
    int m_iThirdValue;
    int m_10;

    S_00cb79d0_Base();
};
struct bhkPackedNiTriStripsShape : public S_00cb79d0_Base
{
    bhkPackedNiTriStripsShape()
    {
        int count = 1;
        m_vptr = &DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        DAT_012680f8 += count;
        m_vptr = &DAT_010c44e4;
        DAT_012686d0 += count;
        m_vptr = &DAT_010c761c;
        DAT_012682d8 += count;
    }
};
struct NiStream
{
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
    virtual void v54(NiStream*);
};
void __cdecl _delete(void* p, int size);
struct NiStream;
extern void(__stdcall* DAT_010c8d1c)(void*);
void __cdecl FUN_00cba1d0();
extern int DAT_010c7310;
extern void(__stdcall* DAT_010c7318)(void*);
extern MemoryManager _g_memoryManager;
struct Flag18
{
    unsigned char m_v;
    Flag18()
    {
        m_v = 0;
    }
    ~Flag18();
};
struct GuardBase04
{
    GuardBase04()
    {}
    ~GuardBase04();
};
// BSSimpleArray-style container of pointer-sized elements.
class CA0E60Array
{
  public:
    void** m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;

    virtual ~CA0E60Array();
    virtual void** Allocate(unsigned int ItemUpdateArray);
    virtual void Free(void** pBuffer);

    void FUN_00cb9ce0(unsigned int uiNewAlloc, unsigned int uiCopyCount);

    __forceinline void SetSize(unsigned int uiSize)
    {
        if (uiSize == 0)
        {
            if (m_pBuffer)
            {
                Free(m_pBuffer);
                m_pBuffer = 0;
                m_uiCapacity = 0;
                m_uiSize = 0;
            }
        }
        else if (uiSize > m_uiCapacity)
        {
            if (m_uiCapacity == 0)
                m_pBuffer = Allocate(uiSize);
            else
                FUN_00cb9ce0(uiSize, m_uiSize);
            m_uiCapacity = uiSize;
            m_uiSize = uiSize;
        }
        else if (uiSize < m_uiSize)
        {
            m_uiSize = uiSize;
            if (uiSize <= m_uiCapacity >> 2)
            {
                FUN_00cb9ce0(uiSize, uiSize);
                m_uiCapacity = uiSize;
            }
        }
        else
        {
            m_uiSize = uiSize;
        }
    }

    void CopyTo(CA0E60Array& kDest) const;
};
struct CA1080_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};
struct CA1080_Holder
{
    int unk00;
    int unk04;
    int unk08;
    CA1080_Shape* shape;
};
struct CA1080_Entry
{
    CA1080_Holder* holder;
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
struct CA1080_Node
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    CA1080_Entry* entries;
    unsigned short entryCount;
    unsigned short unkb2;
    CA1080_Holder** holders;
    int holderCount;
};
struct CA1080_NodeList
{
    CA1080_Node** data;
    int count;
    CA1080_Node* GetAt(int i) const
    {
        return data[i];
    }
};
struct CA1080_PtrArray
{
    virtual void v00();
    virtual void** Allocate(unsigned int count);
    virtual void v08();
    virtual void** Reallocate(void** data, unsigned int count);

    void** data;
    unsigned int size;
    unsigned int capacity;

    void Add(void* item)
    {
        if (size == capacity)
        {
            if (capacity == 0)
            {
                data = Allocate(4);
                capacity = 4;
            }
            else
            {
                unsigned int newCap = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                if (data)
                {
                    data = Reallocate(data, newCap);
                }
                else
                {
                    data = Allocate(newCap);
                    capacity = newCap;
                }
                capacity = newCap;
            }
        }
        size++;
        data[size - 1] = item;
    }
};
struct FNVTaskAllocator
{
    virtual void fn00();
    virtual void fn04();
    virtual void fn08();
    virtual void fn0c();
    virtual void Free(void* memory, unsigned int byteCount);
};
struct FNVTaskMemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FNVTaskAllocator* allocator;
};
extern "C" FNVTaskMemoryRouter* __cdecl FUN_00c85750();
extern __declspec(thread) int g_iCA2020AllocTag;
struct CA2020AllocTagScope
{
    int m_iSaved;

    CA2020AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA2020AllocTag;
        g_iCA2020AllocTag = aiAllocationTag;
    }
    ~CA2020AllocTagScope()
    {
        g_iCA2020AllocTag = m_iSaved;
    }
};
extern MemoryManager _g_memoryManager;
void __cdecl FUN_00aa10f0(void*);
struct PrimaryPart
{
    virtual ~PrimaryPart()
    {}
    unsigned int unknown_04, unknown_08, unknown_0c;
};
struct SecondaryPart
{
    virtual ~SecondaryPart()
    {}
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
};
struct CombinedBase : PrimaryPart, SecondaryPart
{
    virtual ~CombinedBase()
    {}
};
struct ResourceMember
{
    virtual ~ResourceMember()
    {
        FUN_00aa10f0(data);
    }
    void* data;
};
struct FUN_00ca4490 : CombinedBase
{
    ResourceMember resource;
    virtual ~FUN_00ca4490();
};
struct S_00ca49a0_Obj
{
    long m_refs;
    virtual void vfn0();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_refs))
            DeleteThis();
    }
};
struct S_00ca49a0_Ptr
{
    S_00ca49a0_Obj* m_p;
    S_00ca49a0_Ptr(S_00ca49a0_Obj* p = 0)
    {
        m_p = p;
        if (m_p)
            m_p->IncRefCount();
    }
    S_00ca49a0_Ptr(const S_00ca49a0_Ptr& o)
    {
        m_p = o.m_p;
        if (m_p)
            m_p->IncRefCount();
    }
    ~S_00ca49a0_Ptr()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    S_00ca49a0_Ptr& operator=(const S_00ca49a0_Ptr& o)
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};
struct S_00ca49a0_Elem
{
    S_00ca49a0_Ptr obj;
    int unk04;
    S_00ca49a0_Elem(int v = 0) : obj(0)
    {
        unk04 = v;
    }
    bool operator==(const S_00ca49a0_Elem& o) const
    {
        return obj.m_p == o.obj.m_p && unk04 == o.unk04;
    }
    bool operator!=(const S_00ca49a0_Elem& o) const
    {
        return !(*this == o);
    }
};
struct RefEntryObject
{
    virtual void Unknown();
    virtual void Release();
    volatile long referenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
};
struct RecordEntry
{
    NiPointer<RefEntryObject> object;
    unsigned int value;
    RecordEntry() : object(), value(0)
    {}
};
class FUN_00ca4d20_cls;
class FNVSub3Blob
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVSub4
{
  public:
    void Attach(void* p);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVEntry
{
  public:
    unsigned int unk00;
    unsigned int unk04;
};
class FNVSub2
{
  public:
    void Reset();
    void Grow(void* p);
    void Store(unsigned int index, FNVEntry* entry);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int unk10;
    void* m_14;
};
class FNVArg
{
  public:
    unsigned int unk00;
    float m_04;
    FNVSub2 m_08;
    FNVSub4 m_20;
};
class FUN_00ca4d20_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    FNVSub3Blob m_80;
    float m_90;
    unsigned int unk94;
    FNVEntry* m_98;
    unsigned int unk9c;
    int m_a0;
    void CopyEntriesToArg(FNVArg* a1);
};
extern int DAT_012682d8;
struct FUN_00cd2de0
{
    virtual ~FUN_00cd2de0();
};
extern int DAT_012682dc;
struct S_00ca59d0_Bin
{
    int unk00;
    unsigned int unk04;
    unsigned int(__cdecl* unk08)(S_00ca59d0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* unk0C)(S_00ca59d0_Bin*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* buf, unsigned int bytes, unsigned int* compSize, unsigned int n)
    {
        unk04 += unk0C(this, buf, bytes, compSize, n);
    }
};
template <class T> inline void S_00ca59d0_Save(S_00ca59d0_Bin& bin, const T* p, unsigned int n)
{
    unsigned int uiSize = sizeof(T);
    bin.Write(p, n * sizeof(T), &uiSize, 1);
}
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};
__declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
struct PoolFree_t
{
    void Free(void* p);
};
extern PoolFree_t DAT_011f6238;
// FUN_00ca6600 : a one-line function - getter
extern int DAT_012680f8;
extern int DAT_012686d0;
extern int DAT_012682e4;
void* __cdecl FUN_00aa13e0(unsigned int size);
struct OwnerBase
{
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};
struct ChainA_cls : public OwnerBase
{
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls()
    {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};
struct ChainB_cls : public ChainA_cls
{
    virtual void unkB1();
    ChainB_cls()
    {
        DAT_012686d0 += 1;
    }
};
struct SpawnedObject : public ChainB_cls
{
    virtual void unkD2();
    SpawnedObject()
    {
        DAT_012682e4 += 1;
    }
};
struct S_00ca6810_Callable
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54(int arg);
};
struct S_00ca6810_Entry
{
    S_00ca6810_Callable* callable;
    int unk04;
};
struct S_00ca6810_Inner
{
    void* unk00;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    S_00ca6810_Entry* unk98;
    int unk9c;
    int unkA0;
};
extern S_00ca6810_Callable* DAT_012682f0;
struct S_00ca6810_Class
{
    void* unk00;
    int unk04;
    S_00ca6810_Inner* unk08;

    void __thiscall FUN_00aa0ad0(int arg);
    void __thiscall FUN_00ca6810(int arg);
};
struct S_00ca6880_Node
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
};
struct S_00ca6880_Class
{
    int unk00;
    int unk04;
    S_00ca6880_Node* unk08;
    char __thiscall FUN_00c84dc0(S_00ca6880_Class* arg);
    char __thiscall IsEquivalent(S_00ca6880_Class* arg);
};
static inline int Val(S_00ca6880_Class* o)
{
    if (o && o->unk08)
        return o->unk08->unka0;
    return 0;
}
extern __declspec(thread) int g_threadAllocationContext;
extern int DAT_010c771c;
extern int DAT_012682e4;
struct AllocationContextGuard
{
    int previous;
    AllocationContextGuard()
    {
        previous = g_threadAllocationContext;
        g_threadAllocationContext = 16;
    }
    ~AllocationContextGuard()
    {
        g_threadAllocationContext = previous;
    }
};
struct FNVShape : S_00cb79d0_Base
{
    FNVShape()
    {
        m_vptr = &DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        ++DAT_012680f8;
        m_vptr = &DAT_010c44e4;
        ++DAT_012686d0;
        m_vptr = &DAT_010c771c;
        ++DAT_012682e4;
    }
};
struct S_00ca7310_Arr
{
    int* m_data;
    int m_iElementCount;
    unsigned int m_pRayCursor;
    S_00ca7310_Arr() : m_data(0), m_iElementCount(0), m_pRayCursor(0x80000000)
    {}
};
struct S_00ca7310_Root
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00ca7310_Root()
    {
        unk00 = 0;
    }
};
struct S_00ca7310_Vec
{
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    S_00ca7310_Vec()
    {
        unk10 = 0.0f;
        unk14 = 0.0f;
        unk18 = 0.0f;
        unk1C = 0.0f;
    }
};
extern int DAT_0126830c;
struct FUN_00ca9aa0;
struct State
{
    unsigned int value;
    State() : value(0)
    {}
};
struct BaseOwner
{
    virtual void Act();
    unsigned short unk04;
    unsigned short unk06;
    State unk08;
    BaseOwner() : unk06(1), unk08()
    {}
};
struct InternalPart
{
    unsigned short mode;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    InternalPart() : mode(1)
    {}
    ~InternalPart();
};
void __fastcall FUN_00d21ce0(InternalPart* part, unsigned int command, FUN_00ca9aa0* parent);
struct FUN_00ca9aa0 : BaseOwner
{
    virtual void Act();
    unsigned int unk0c;
    InternalPart part;
    float value;
    FUN_00ca9aa0();
};
class BCA9D50BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCA9D50BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCA9D50BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BCA9D50Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned int m_uiFileVersion;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BCA9D50BinaryStream* m_pUnderlyingStream;
    BCA9D50BinaryStream* m_pBackingStream;
};
template <class T>
inline void BCA9D50BinaryStreamSave(BCA9D50BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BCA9D50SaveBinary(BCA9D50Stream& kStream, const T& value)
{
    BCA9D50BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
void* __cdecl FUN_00aa13e0(unsigned int size);
struct SpawnedObject20_b9537
{
    char m00[0x14];
    SpawnedObject20_b9537();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
unsigned int __cdecl PackBytesBigEndian(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
// Rect-like record used by InitRect and its helper.
static __declspec(noinline) char CB1030ToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c - 'A' + 'a');
    return c;
}
// Exported elsewhere through a function pointer, which keeps the helper's cdecl stack arguments.
char(__cdecl* g_pfnCB1030ToLower)(char) = CB1030ToLower;
// FUN_00cb75d0 : default constructor of the object whose first member holds
// the class table pointer.  The constructor clears three trailing dword
// members, sets a byte flag to 1 and installs the table pointer last.
static float DAT_010c8ae4 = 0.016f;
struct S_00cb9770_Foo
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual float V41(float value);

    int unk04;
    unsigned short unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    float unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    float unk50;

    void __thiscall FUN_00cb9290();
    bool GetActive()
    {
        return ((this->unk08 >> 3) & 1) != 0;
    }
    void __thiscall UpdateActiveState(float* param);
};
extern int DAT_01268188;
extern int DAT_0108febc;
struct FUN_00c87c30
{
    void* vtable;
    int unk04;
    int unk08;
    FUN_00c87c30();
};
struct InitializedField
{
    int value;
    InitializedField() : value(0)
    {}
    ~InitializedField();
};
extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_01268250;
extern int DAT_01268324;
struct S_cb9a90_Base
{
    int unk04;
    int unk08;
    S_cb9a90_Base();
    virtual ~S_cb9a90_Base();
};
struct S_cb9a90_A : S_cb9a90_Base
{
    int unk0c;
    int unk10;
    S_cb9a90_A()
    {
        unk0c = 0;
        unk10 = 0;
        DAT_012680f8++;
    }
};
struct S_cb9a90_B : S_cb9a90_A
{
    S_cb9a90_B()
    {
        DAT_01268274++;
    }
};
struct S_cb9a90_C : S_cb9a90_B
{
    S_cb9a90_C()
    {
        DAT_01268250++;
    }
};
class GlobalObjectO2_00a7b610;
class CB9B80RefObject
{
  public:
    CB9B80RefObject();
    virtual ~CB9B80RefObject();

    int unk04;
    int unk08;
};
class CB9B80SerializableObject : public CB9B80RefObject
{
  public:
    CB9B80SerializableObject() : m_pkWorld(0)
    {}

    void* m_pkWorld;
};
class CB9B80WorldObject : public CB9B80SerializableObject
{
  public:
    CB9B80WorldObject()
    {
        ++ms_uiCount;
    }
    virtual ~CB9B80WorldObject();

    static unsigned int ms_uiCount;
};
struct CpuOpaque;
class BCB9F60BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCB9F60BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCB9F60BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BCB9F60Stream
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void SaveLinkID(void* pkObject);

  public:
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned int m_uiFileVersion;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BCB9F60BinaryStream* m_pUnderlyingStream;
    BCB9F60BinaryStream* m_pBackingStream;
};
template <class T>
inline void BCB9F60BinaryStreamSave(BCB9F60BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BCB9F60SaveBinary(BCB9F60Stream& kStream, const T& value)
{
    BCB9F60BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
// Releases the resource held by the object and resets it to its empty state.
typedef void(__stdcall* FreeFn)(void*);
class FUN_00cba0d0_cls
{
  public:
    virtual void v0();
    virtual void v1();
    long m_04;
};
void __stdcall ReleaseItems(FUN_00cba0d0_cls** items, unsigned int count);
extern void* DAT_0109b220;
extern int(__stdcall* DAT_00fdf1c4)(void*);
class CSlot08
{
  public:
    void* p;
    CSlot08(void* v)
    {
        p = v;
    }
    ~CSlot08();
};
class CSubA
{
  public:
    virtual void unkA00();
    unsigned int unkA04;
    unsigned int unkA08;
    unsigned int unkA0c;
    CSubA()
    {
        unkA04 = 0;
        unkA08 = 0;
        unkA0c = 0;
    }
    ~CSubA();
};
class CSubB
{
  public:
    virtual void unkB00();
    unsigned int unkB04;
    unsigned int unkB08;
    unsigned int unkB0c;
    CSubB()
    {
        unkB04 = 0;
        unkB08 = 0;
        unkB0c = 0;
    }
    ~CSubB();
};
// FUN_00cbd960 registers the 0x00cbd7a0 comparison helper in the global
// callback slot at 0x01268430, which is later called indirectly with two
// arguments (see the indirect call through 0x01268430).
extern void(__cdecl* DAT_01268430)(void*, void*);
void __cdecl InsertIntoContext(void* pList, void* pContext);
extern "C" void _ReadWriteBarrier(void);
void* __cdecl PackBytesBigEndian(int, int, int, int);
// Release the per-body lists: destroy every inner array, then free the outer array.
struct CBF490Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
struct CBF490MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CBF490Allocator* m_pStreamAllocator;

    CBF490Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" CBF490MemoryRouter& __cdecl CBF490GetMemoryRouter() throw();
template <class T> inline void CBF490Deallocate(CBF490Allocator& alloc, T* p, int numElem)
{
    alloc.ReturnMemory(p, numElem * sizeof(T));
}
template <class T> __forceinline void CBF490Destruct(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}
template <class T> struct CBF490Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~CBF490Array() throw()
    {
        CBF490Allocator& alloc = CBF490GetMemoryRouter().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    __forceinline void ClearAndRelease() throw()
    {
        CBF490Allocator& alloc = CBF490GetMemoryRouter().heap();
        CBF490Destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            CBF490Deallocate(alloc, m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
class hkBool
{
  public:
    hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }

    char m_cBooleanValue;
};
struct TypedObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetKind();
};
struct PropHolder
{
    int unk00;
    int unk04;
    int unk08;
    TypedObj* pObj;
};
struct PassEntry
{
    PropHolder* pHolder;
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
struct ShaderData
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    PassEntry* pPasses;
    unsigned short usPassCount;
    unsigned short unkb2;
    PropHolder** ppExtra;
    int iExtraCount;
};
struct ShaderProp
{
    int unk00;
    int unk04;
    ShaderData* pData;
};
struct CastResult
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ShaderProp* pShader;
};
struct RttiObject
{
    CastResult* DynamicCast(const void* type);
};
struct GeomNode;
struct ChildNode
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    GeomNode** ppChildren;
    unsigned short unka4;
    unsigned short usChildCount;
};
struct GeomNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ChildNode* GetAsNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    RttiObject* pProp;
};
struct GeomArray
{
    virtual void v00();
    virtual GeomNode** Allocate(unsigned int count);
    GeomNode** pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    void Grow(unsigned int newCap, unsigned int size);

    __forceinline void Add(GeomNode* p)
    {
        if (uiSize == uiCapacity)
        {
            if (uiCapacity == 0)
            {
                pData = Allocate(4);
                uiCapacity = 4;
            }
            else
            {
                unsigned int newCap = uiCapacity > 0x400 ? uiCapacity + 0x400 : uiCapacity * 2;
                Grow(newCap, uiSize);
                uiCapacity = newCap;
            }
        }
        pData[++uiSize - 1] = p;
    }
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class NiRefObjectCA3
{
  public:
    virtual ~NiRefObjectCA3();
    virtual void DeleteThis();

    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerCA3
{
  public:
    ~NiPointerCA3()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerCA3& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
        }
        return *this;
    }

    T* m_pObject;
};
class PrimaryCA3
{
  public:
    virtual ~PrimaryCA3()
    {}

    int unk04, unk08, unk0C;
};
class SecondaryCA3
{
  public:
    virtual ~SecondaryCA3()
    {}
};
class BaseCA3 : public PrimaryCA3, public SecondaryCA3
{
  public:
    virtual ~BaseCA3()
    {}

    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    int unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70;
    int unk74, unk78, unk7C, unk80;
};
// The pack prelude keeps only the declaration of this file-static helper (used by a
// neighbouring function's function-pointer table); provide its body so the unit links.
struct RefCounted
{
    virtual ~RefCounted();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct PtrEntry
{
    NiPointer<RefCounted> m_pReferencedObject;
    int m_iValue;
    PtrEntry() : m_pReferencedObject(0), m_iValue(0)
    {}
    bool operator==(const PtrEntry& other) const
    {
        return m_pReferencedObject == other.m_pReferencedObject && m_iValue == other.m_iValue;
    }
    bool operator!=(const PtrEntry& other) const
    {
        return !(*this == other);
    }
};
// Prelude helper whose body the unit prelude omits.
// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.
extern __declspec(thread) int g_iCA56B0AllocTag;
struct CA56B0AllocTagScope
{
    int m_iSaved;

    CA56B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA56B0AllocTag;
        g_iCA56B0AllocTag = aiAllocationTag;
    }
    ~CA56B0AllocTagScope()
    {
        g_iCA56B0AllocTag = m_iSaved;
    }
};
class CA56B0RefObject
{
  public:
    CA56B0RefObject();
    virtual ~CA56B0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CA56B0Shape : public CA56B0RefObject
{
  public:
    CA56B0Shape() : m_pUserData(0), m_pkExtra(0)
    {
        ++ms_iCount;
    }
    virtual ~CA56B0Shape();

    void* m_pUserData;
    void* m_pkExtra;

    static int ms_iCount;
};
class CA56B0MidShape : public CA56B0Shape
{
  public:
    CA56B0MidShape()
    {
        ++ms_iCount;
    }
    virtual ~CA56B0MidShape();

    static int ms_iCount;
};
class CA56B0ListShape : public CA56B0MidShape
{
  public:
    CA56B0ListShape()
    {
        ++ms_iCount;
    }
    virtual ~CA56B0ListShape();

    static int ms_iCount;
};
struct ReadBin
{
    int unk00;
    unsigned int position;
    unsigned int(__cdecl* read)(ReadBin*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        position += read(this, data, bytes, sizes, n);
    }
};
template <class T> inline void Load(ReadBin& bin, T* data, unsigned int n)
{
    unsigned int size = sizeof(T);
    bin.Read(data, n * sizeof(T), &size, 1);
}
extern __declspec(thread) int g_CA6E60AllocTag;
struct CA6E60AllocTagScope
{
    int m_iSaved;

    CA6E60AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CA6E60AllocTag;
        g_CA6E60AllocTag = aiAllocationTag;
    }
    ~CA6E60AllocTagScope()
    {
        g_CA6E60AllocTag = m_iSaved;
    }
};
class CA6E60Buffer
{
  public:
    virtual ~CA6E60Buffer()
    {
        NiFreeAlias(m_pResource);
    }

    void* m_pResource;
};
class CA6E60Data
{
  public:
    static void operator delete(void* pvMem)
    {
        unsigned char ucOffset = static_cast<unsigned char*>(pvMem)[-1];
        _g_memoryManager.Deallocate(static_cast<char*>(pvMem) - ucOffset);
    }

    int unk00;
    int unk04;
    CA6E60Buffer m_kBuffer;
};
struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
    void AppendReference(char*& value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        SetAt(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
        {
            m_usESize += (unsigned short)-1;
        }
        m_pBase[index] = value;
    }
};
char* __cdecl FUN_00a7d330(char*);
char* __cdecl FUN_00a7d510(const char*, unsigned int);
char* __cdecl FUN_00a7d4d0(const char*, int);
struct DiagnosticShape : S_00ca6810_Class
{
    void FUN_00cd2fd0(StrArr* output);
    void AppendSubpartDiagnostics(StrArr* output);
    unsigned int Count() const
    {
        return this && unk08 ? (unsigned int)unk08->unkA0 : 0;
    }
    S_00ca6810_Entry& Part(unsigned int index) const
    {
        if (this && unk08)
            return unk08->unk98[index];
        return *reinterpret_cast<S_00ca6810_Entry*>(&DAT_012682f0);
    }
};
struct LockFlag_t
{
    bool m_kPointB;
    LockFlag_t(bool b) : m_kPointB(b)
    {}
    LockFlag_t(const LockFlag_t& o) : m_kPointB(o.m_kPointB)
    {}
};
struct CAC300Allocator
{
    virtual void fn00();
    virtual void* Alloc(unsigned int size);
};
struct hkReferencedObject
{
    void* vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
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
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;

    hkReferencedObject(int arg);
    void removeReference();

    static void* operator new(unsigned int size)
    {
        FNVTaskMemoryRouter* router = FUN_00c85750();
        hkReferencedObject* p = (hkReferencedObject*)((CAC300Allocator*)router->allocator)->Alloc(size);
        p->m_usMemSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
};
// Prelude helper whose body the unit prelude omits.
// Factory: create a new 0x40-byte object.
class BA2D0Object
{
  public:
    BA2D0Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

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
};
// Prelude helper whose body the unit prelude omits.
// NiTMap destructor: remove all entries, then the base map frees its hash table.
void __cdecl CBC740NiFree(void* pvMem);
class CBC740MapBase
{
  public:
    virtual ~CBC740MapBase()
    {
        RemoveAll();
        CBC740NiFree(m_ppkHashTable);
    }
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
extern __declspec(thread) int g_iCBEA40AllocTag;
struct BCBEA40AllocTagScope
{
    int m_iSaved;

    BCBEA40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCBEA40AllocTag;
        g_iCBEA40AllocTag = aiAllocationTag;
    }
    ~BCBEA40AllocTagScope()
    {
        g_iCBEA40AllocTag = m_iSaved;
    }
};
class BCBEA40StringArray
{
  public:
    virtual ~BCBEA40StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
char* __cdecl FUN_00a7d330(const char* pcString);
// Registers a batch of classes with the registry while it is temporarily locked.
class CBFC10Bool
{
  public:
    CBFC10Bool(bool b)
    {
        m_cBool = (char)b;
    }
    char m_cBool;
};
struct SArr046
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int size);
    void FUN_0096ae90(unsigned int index, char*& value);
    void AppendReference(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        FUN_0096ae90(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
        {
            m_usESize += (unsigned short)-1;
        }
        m_pBase[index] = value;
    }
};
extern int DAT_012682dc;
char* __cdecl FUN_00a7d330(char* a);
char* __cdecl FUN_00a7d510(const char* s, unsigned int n);
char* __cdecl FUN_00a7d4d0(const char* s, int n);
typedef int(__cdecl* FUN_00cb9d80_read_fn)(void* stream, void* data, unsigned int size, void* result, int flag);
struct StandInBinaryStream
{
    int m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(StandInBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void BinaryStreamLoad(StandInBinaryStream& kIs, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kIs.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}
struct StandInStream : public NiStream
{
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    StandInBinaryStream* m_pkIStream;

    void NiStream_LoadFixedString(void* pLinkID);
};
template <class T> inline void StreamRead(StandInStream& kStream, T& val)
{
    BinaryStreamLoad(*kStream.m_pkIStream, &val, 1);
}
struct MemoryManager_t
{
    void* FUN_00aa3e40(unsigned int size);
};
struct BaseCinfo
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;

    __forceinline void* operator new(size_t size) throw()
    {
        return ((MemoryManager_t*)&DAT_011f6238)->FUN_00aa3e40(size);
    }
    __forceinline void operator delete(void*)
    {}

    __forceinline BaseCinfo() : m_iWordAt04(0), m_8(1), m_iThirdValue(0), m_10(0)
    {}

    virtual void v00();
    virtual void v04();
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_13 : public BaseCinfo
{
    __forceinline Cinfo_13()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_0 : public BaseCinfo
{
    __forceinline Cinfo_0()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_1 : public BaseCinfo
{
    __forceinline Cinfo_1()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_2 : public BaseCinfo
{
    __forceinline Cinfo_2()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_7 : public BaseCinfo
{
    __forceinline Cinfo_7()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct WalkPlacement
{
};
inline void* operator new(unsigned int, WalkPlacement, void* p)
{
    return p;
}
struct WalkRTTI
{
    const char* name;
    WalkRTTI* parent;
};
extern WalkRTTI DAT_01267b70, DAT_0126817c;
extern int DAT_0126818c;
struct WalkObject
{
    virtual void v0();
    virtual void v4();
    virtual WalkRTTI* GetRTTI();
    int ref;
    struct WalkBody* body;
    struct WalkType* fallback;
    WalkObject* FUN_00653290(const WalkRTTI*);
    __forceinline WalkObject* AsItem()
    {
        if (!this)
            return 0;
        return IsKind(&DAT_0126818c) ? this : 0;
    }
    bool IsKind(const void* type)
    {
        for (WalkRTTI* r = GetRTTI(); r; r = r->parent)
            if (r == type)
                return true;
        return false;
    }
};
inline WalkObject* KindCast(WalkObject* item)
{
    if (!item)
        return 0;
    return item->IsKind(&DAT_0126818c) ? item : 0;
}
struct WalkType
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};
struct WalkBody
{
    int unk, unkCur, unkValue;
    WalkType* type;
};
struct WalkLink
{
    WalkObject* item;
    WalkLink* next;
    WalkObject* GetItem()
    {
        return item;
    }
    WalkLink* Next()
    {
        return next;
    }
};
class NiAVObject;
class NiRTTI;
class GarbageCollectorObjectPtr
{
  public:
    WalkObject* object;
    int high;
};
GarbageCollectorObjectPtr* __cdecl FUN_00c85ef0(GarbageCollectorObjectPtr*, NiAVObject*, const NiRTTI*);
struct WalkAlloc
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void Free(void*, int) throw();
};
struct WalkRouter
{
    int unk, unkCur, unkValue, unk0c;
    WalkAlloc* heap;
    WalkAlloc& Heap()
    {
        return *heap;
    }
};
void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> __forceinline void WalkDestruct(T* ptr, int count)
{
    for (int i = 0; i < count; ++i)
        ptr[i].~T();
}
template <class T> inline void WalkDeallocate(WalkAlloc& alloc, T* ptr, int count)
{
    alloc.Free(ptr, count * int(sizeof(T)));
}
struct WalkArray
{
    void** data;
    int size;
    int capacity;
    WalkArray() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~WalkArray()
    {
        WalkAlloc& alloc = ((WalkRouter*)FUN_00c85750())->Heap();
        ClearAndRelease(alloc);
    }
    void ClearAndRelease(WalkAlloc& alloc)
    {
        WalkDestruct(data, size);
        size = 0;
        if ((capacity & 0x80000000) == 0)
            WalkDeallocate(alloc, data, capacity & 0x3fffffff);
        data = 0;
        capacity = 0x80000000;
    }

    __forceinline void Add(void* const& value)
    {
        FNVTaskAllocator* alloc = FUN_00c85750()->allocator;
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(alloc, this, 4);
        *new (WalkPlacement(), &data[size]) void* = value;
        ++size;
    }
};
inline WalkObject* GetRoot(void* obj)
{
    GarbageCollectorObjectPtr temp;
    return FUN_00c85ef0(&temp, (NiAVObject*)obj, (const NiRTTI*)&DAT_01267b70)->object;
}
struct TlsBlock_ca57
{
    unsigned int m_2b4;
};
extern __declspec(thread) TlsBlock_ca57 g_tls;
struct TlsFlagGuard_ca57
{
    unsigned int m_saved;
    TlsFlagGuard_ca57()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 16;
    }
    ~TlsFlagGuard_ca57()
    {
        g_tls.m_2b4 = m_saved;
    }
};
class Pool_ca57
{
  public:
    void* __thiscall FUN_00aa3e40(unsigned int);
};
class Node_ca57
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    Node_ca57();
    static void operator delete(void*) throw()
    {}
    void* operator new(unsigned int size) throw()
    {
        unsigned char* raw = (unsigned char*)((Pool_ca57*)&DAT_011f6238)->FUN_00aa3e40(size);
        unsigned char lo = (unsigned char)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
};
struct FNVHeapAllocator : FNVTaskAllocator
{
    template <typename T> void _bufFree(void* p, int numElem)
    {
        Free(p, numElem * sizeof(T));
    }
};
struct FNVHeapRouter : FNVTaskMemoryRouter
{
    FNVHeapAllocator& heap()
    {
        return *(FNVHeapAllocator*)allocator;
    }
};
template <typename T> struct FNVArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(FNVHeapAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~FNVArray()
    {
        _clearAndDeallocate(((FNVHeapRouter*)FUN_00c85750())->heap());
    }
};
struct RNG_cabbd0
{
    int unk00;
    unsigned int m_uiState;

    unsigned int Next()
    {
        m_uiState = m_uiState * 1664525 + 1013904223;
        return m_uiState;
    }
};
unsigned int __cdecl FUN_00cabbd0(RNG_cabbd0* rng);
struct CpuOpaque;
extern "C" void __cdecl FUN_00aa1460(void* self, int size);
struct FUN_00d2acf0
{
    void* vtable;
    unsigned short memorySizeAndFlags;
    unsigned short referenceCount;
    unsigned int unk08, unk0C, unk10, unk14;
    unsigned int unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34;
    unsigned int unk38, unk3C, unk40, unk44;
    unsigned int unk48, unk4C, unk50, unk54;
    unsigned int unk58, unk5C;

    FUN_00d2acf0(void* source, void* start, void* end, float nearValue, float farValue, int flags);
    void FUN_00c905b0();

    static void* operator new(unsigned int bytes)
    {
        FNVTaskMemoryRouter* router = FUN_00c85750();
        FUN_00d2acf0* object = (FUN_00d2acf0*)((CAC300Allocator*)router->allocator)->Alloc(bytes);
        object->memorySizeAndFlags = (unsigned short)bytes;
        return object;
    }
    static void operator delete(void* object);
};
char* __cdecl FUN_00a7d330(GlobalObjectO2_00a7b610* p);
struct CpuOpaque;
class GlobalObjectO2_00a7b610;
void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct HeapAllocator
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern HeapAllocator g_heapAllocator;
struct RefStub
{
    void IncRefCount();
    void DecRefCount();
};
struct RefHolder
{
    RefStub* object;
    RefHolder()
    {}
    ~RefHolder()
    {
        if (object)
            object->DecRefCount();
    }
};
struct ThreadLocalData
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int heapIndex;
};
extern __declspec(thread) ThreadLocalData g_threadLocalData;
struct HeapIndexGuard
{
    int saved;
    HeapIndexGuard(int index)
    {
        saved = g_threadLocalData.heapIndex;
        g_threadLocalData.heapIndex = index;
    }
    ~HeapIndexGuard()
    {
        g_threadLocalData.heapIndex = saved;
    }
};
extern int DAT_010c7600;
struct ShapePrefix
{
    int unk00;
    float unk04;
    ShapePrefix() : unk00(0), unk04(0.0f)
    {}
};
struct ShapeStrips
{
    void* vtbl;
    void* pBase;
    unsigned int maxSize;
    unsigned int size;
    unsigned int eSize;
    unsigned int growBy;

    ShapeStrips(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        maxSize = uiMaxSize;
        growBy = uiGrowBy;
        size = 0;
        eSize = 0;
        if (uiMaxSize > 0)
            pBase = g_heapAllocator.Allocate(uiMaxSize);
        else
            pBase = 0;
        vtbl = &DAT_010c7600;
    }
};
struct ShapeVector
{
    float x;
    float y;
    float z;
    float w;
    ShapeVector()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
};
struct ShapeData : ShapePrefix
{
    ShapeStrips strips;
    ShapeVector scale;

    static void* operator new(unsigned int size)
    {
        char* p = (char*)g_heapAllocator.Allocate(size + 16);
        unsigned char off = (unsigned char)(16 - ((unsigned char)(unsigned int)p & 15));
        p += off;
        p[-1] = off;
        return p;
    }
    static void operator delete(void* p)
    {
        if (p)
        {
            unsigned char off = ((unsigned char*)p)[-1];
            g_heapAllocator.Deallocate((char*)p - off);
        }
    }

    ShapeData()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
    void SetScale()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
};
struct NiPoint3
{
    float x;
    float y;
    float z;
};
extern int DAT_0108febc;
extern int DAT_010c81ac;
extern int DAT_01268188;
extern int DAT_0126830c;
extern __declspec(thread) int tls_memContext;
void* __cdecl FUN_00aa13e0(unsigned int size);
void __cdecl _delete(void* p, int size);
struct ScopedMemContext_ca9e60
{
    int m_iOld;
    ScopedMemContext_ca9e60(int context)
    {
        m_iOld = tls_memContext;
        tls_memContext = context;
    }
    ~ScopedMemContext_ca9e60()
    {
        tls_memContext = m_iOld;
    }
};
struct Holder_ca9e60
{
    void* p;
    Holder_ca9e60(void* q) : p(q)
    {}
    ~Holder_ca9e60()
    {
        if (p)
            _delete(p, 0x10);
    }
};
unsigned int __cdecl FUN_00cabbd0(int*);
struct RefCountedCAC4B0
{
    int unk00;
    long m_iRefCount;
};
struct ShapeHolderCAC4B0
{
    int unk00;
    int unk04;
    int unk08;
    RefCountedCAC4B0* m_pkShape;
};
struct WorldObjectCAC4B0
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    void* m_pkUserData;
    ShapeHolderCAC4B0* hkpCharacterProxy_getShapePhantom();
};
void __cdecl FUN_00cac410();
struct RefObjectCAC4B0
{
    void UpdateReference(bool bAdd);
    int unk00;
    int unk04;
    WorldObjectCAC4B0* m_pkHavokObject;
    WorldObjectCAC4B0* GetHavokObject()
    {
        return this ? m_pkHavokObject : 0;
    }
};
extern __declspec(thread) unsigned int t_uiMemContextC5E0;
inline unsigned int GetMemContextC5E0()
{
    return t_uiMemContextC5E0;
}
inline void SetMemContextC5E0(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextC5E0 = m_uiGeometryShaderFlags;
}
class AutoMemContextC5E0
{
  public:
    AutoMemContextC5E0(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC5E0();
        SetMemContextC5E0(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC5E0()
    {
        SetMemContextC5E0(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};
class hkMemoryAllocatorC5E0
{
  public:
    virtual ~hkMemoryAllocatorC5E0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct hkMemoryRouterC5E0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorC5E0& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocatorC5E0* m_pStreamAllocator;
};
// FUN_00cb0aa0: allocator-backed string dup. Takes the source string in the
// caller's edi (private convention derived for this static noinline helper):
// length via hkString_strLen (+1 for the NUL), block allocated through the task
// memory router's allocator, contents filled by FUN_00cb1090.
struct FNVTaskMemoryRouter;
extern "C" int __cdecl hkString_strLen(int);
extern "C" FNVTaskMemoryRouter* __cdecl FUN_00c85750();
extern "C" void* __cdecl AllocateWithHeader(void* allocator, unsigned int count);
extern int DAT_0102009c;
extern int DAT_0102016c;
extern int DAT_010c8914;
extern int DAT_01268118;
extern int DAT_01268154;
struct S00cb84f0_Obj : FUN_00c87c30
{
    int unk0c;
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    S00cb84f0_Obj()
    {
        *(void**)this = (void*)&DAT_0102016c;
        unk0c = 0;
        DAT_01268154 += 1;
        *(void**)this = (void*)&DAT_0102009c;
        DAT_01268118 += 1;
        *(void**)this = (void*)&DAT_010c8914;
    }
};
struct ArrayCBAF90
{
    virtual __forceinline ~ArrayCBAF90()
    {
        RemoveAll();
    }
    virtual void v04();
    virtual void Deallocate(void* pvBase);
    void ReleaseItems(void* pvBase, unsigned int ItemUpdateArray);
    __forceinline void RemoveAll()
    {
        if (m_pBase)
        {
            ReleaseItems(m_pBase, m_uiSize);
            Deallocate(m_pBase);
            m_pBase = 0;
            m_uiAllocated = 0;
            m_uiSize = 0;
        }
    }
    void* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiAllocated;
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct FUN_00cbaf20_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    FUN_00cbaf20_class();
    void AssignFixedString(const NiFixedString& name);
};
extern int(__stdcall* DAT_00fdf1d0)();
#include <math.h>
extern __declspec(thread) unsigned int t_uiMemContextC520;
inline unsigned int GetMemContextC520()
{
    return t_uiMemContextC520;
}
inline void SetMemContextC520(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextC520 = m_uiGeometryShaderFlags;
}
class AutoMemContextC520
{
  public:
    AutoMemContextC520(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC520();
        SetMemContextC520(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC520()
    {
        SetMemContextC520(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};
class hkMemoryAllocatorC520
{
  public:
    virtual ~hkMemoryAllocatorC520();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct hkMemoryRouterC520
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorC520& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocatorC520* m_pStreamAllocator;
};
hkMemoryRouterC520* __cdecl GetMemoryRouterC520();
class BufferC520
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return GetMemoryRouterC520()->heap().AllocateMemoryBlock(uiSize);
    }
    BufferC520() throw()
    {
        Init();
    }
    void Init() throw();
    int m_aiData0;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};
#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
#endif
extern const __m128 DAT_01267e30;
extern float DAT_01016248;
extern float DAT_0101e2bc;
extern __declspec(thread) int DAT_012722b4;
struct S00cb87e0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 v10;
    __m128 v20;
    volatile float f30;
    float f34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    __forceinline S00cb87e0_Node()
    {
        f30 = DAT_01016248;
        unk00 = 0;
        unk04 = 0;
        v10 = DAT_01267e30;
        v20 = DAT_01267e30;
        f34 = DAT_0101e2bc;
    }
    void* operator new(unsigned int size) throw()
    {
        unsigned char* raw = (unsigned char*)((MemoryManager_t*)&DAT_011f6238)->FUN_00aa3e40(size);
        unsigned char lo = (unsigned char)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
    void operator delete(void*) throw()
    {}
};
struct S00cb87e0_Guard
{
    int m_saved;
    S00cb87e0_Guard()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00cb87e0_Guard()
    {
        DAT_012722b4 = m_saved;
    }
};
extern int DAT_010c81ac;
struct SpawnMidBase : FUN_00c87c30
{
    InitializedField unk0c;
    SpawnMidBase()
    {
        vtable = &DAT_0108febc;
        ++DAT_01268188;
    }
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
class CbaItem
{
  public:
    virtual ~CbaItem();
};
// Gamebryo-style array whose storage is released through its own virtual Free.
template <class T> class CbaArray
{
  public:
    virtual ~CbaArray()
    {
        RemoveAll();
    }
    virtual void* Allocate(unsigned int ItemUpdateArray);
    virtual void Free(void* pvMem);

    void RemoveAll()
    {
        if (m_pBase)
        {
            Free(m_pBase);
            m_pBase = 0;
            m_uiMaxSize = 0;
            m_uiSize = 0;
        }
    }

    unsigned int GetSize() const
    {
        return m_uiSize;
    }
    T& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
    T* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
};
class CbaString
{
  public:
    ~CbaString()
    {
        if (m_pcString != DAT_0109b220)
            InterlockedDecrement((long*)((char*)m_pcString - 8));
    }
    void* m_pcString;
};
class CbaBase
{
  public:
    virtual ~CbaBase();  // FUN_00a5d3d0
    unsigned int unk04;
};
class FUN_00cba1d0 : public CbaBase
{
  public:
    virtual ~FUN_00cba1d0();

    CbaString m_kName;
    CbaArray<CbaItem*> m_kUnsortedGeometryList;
    CbaArray<void*> m_kOther;
};
static void CB920SetTag(int aiAllocationTag)
{
    g_tlsBlock.m_2b4 = aiAllocationTag;
}
struct CB920Guard
{
    int m_saved;

    CB920Guard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    void Leave()
    {
        CB920SetTag(m_saved);
    }

    ~CB920Guard()
    {
        Leave();
    }
};
void __cdecl InsertIntoContext(void* pList, void* pContext);
extern int DAT_010c771c;
struct ScopeHost_cls
{
    void* m_vptr;
    void FUN_00c876a0();
    void FUN_00cd2de0();
    void FUN_00ca6590();
};
struct OwnerGuard_cls
{
    ScopeHost_cls* m_pOwnerObject;
    OwnerGuard_cls(ScopeHost_cls* owner)
    {
        m_pOwnerObject = owner;
        owner->m_vptr = &DAT_010c771c;
    }
    ~OwnerGuard_cls()
    {
        m_pOwnerObject->FUN_00cd2de0();
    }
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
// Adjustor thunk for FUN_00cabf40: sub ecx,0xc; jmp FUN_00cac120.
// Primary base sized 12 (vptr + 8 pad) so the secondary->primary
// this adjustment is exactly 0xc.
struct Prim_00cabf40
{
    virtual void FUN_00cabf40();
    int m04;
    int m08;
};
struct Sec_00cabf40
{
    virtual void FUN_00cabf40();
};
struct TO_00cabf40 : Prim_00cabf40, Sec_00cabf40
{
// @fnv 0x00cabf40
    virtual void FUN_00cabf40();
};
// Forces vtable emission: the override lands in both the primary and the
// secondary vftable, so VC9 emits [thunk]:TO_00cabf40::FUN_00cabf40
// 'adjustor{12}' = sub ecx,0xc ; jmp TO_00cabf40::FUN_00cabf40.
static TO_00cabf40 g_thunk_00cabf40;
struct CAC410_TLSState
{
    char m_ucUnknownByte[0x2B4];
    int m_uiFilterValue;
};
__declspec(thread) CAC410_TLSState g_CAC410_TLSState;
struct CAC410_ScopedValue
{
    int m_oldValue;

    CAC410_ScopedValue() : m_oldValue(g_CAC410_TLSState.m_uiFilterValue)
    {
        g_CAC410_TLSState.m_uiFilterValue = 0x10;
    }

    ~CAC410_ScopedValue()
    {
        g_CAC410_TLSState.m_uiFilterValue = m_oldValue;
    }
};
void __fastcall FUN_00cac410(void* pThis);
extern int DAT_01268358;
struct CB0StringPtr
{
    int m_pcText;
    CB0StringPtr(const CB0StringPtr& other);
    const char* cString() const
    {
        return (const char*)(m_pcText & ~1);
    }
};
struct CB0SelfRef
{
    CB0StringPtr* p;
};
static void FUN_00cb0b10(CB0SelfRef selfRef, const char* s, int len);
struct S00cb8590_Out
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
};
struct S00cb8590_Obj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk1e0;
    unsigned char unk1e4;
    unsigned char unk1e5;
};
struct S00cb8590_cls
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v0a()
    {}
    virtual void v0b()
    {}
    virtual void v0c()
    {}
    virtual void v0d()
    {}
    virtual void v0e()
    {}
    virtual void v0f()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v1a()
    {}
    virtual void v1b()
    {}
    virtual void v1c()
    {}
    virtual void v1d()
    {}
    virtual void v1e()
    {}
    virtual void v1f()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v2a()
    {}
    virtual void v2b()
    {}
    virtual void v2c()
    {}
    virtual S00cb8590_Out* vfn2d(S00cb8590_Obj** pp)
    {
        return 0;
    }
    void FUN_00cb8590(int a0);
};
static __forceinline void S00cb8590_swapAll(S00cb8590_Out* p)
{
    p->unk10 = _byteswap_ulong(p->unk10);
    _ReadWriteBarrier();
    p->unk14 = _byteswap_ulong(p->unk14);
    _ReadWriteBarrier();
    p->unk18 = _byteswap_ulong(p->unk18);
    _ReadWriteBarrier();
    p->unk1c = _byteswap_ulong(p->unk1c);
    _ReadWriteBarrier();
    p->unk20 = _byteswap_ulong(p->unk20);
    _ReadWriteBarrier();
    p->unk24 = _byteswap_ulong(p->unk24);
    _ReadWriteBarrier();
    p->unk28 = _byteswap_ulong(p->unk28);
    _ReadWriteBarrier();
    p->unk2c = _byteswap_ulong(p->unk2c);
    _ReadWriteBarrier();
    p->unk30 = _byteswap_ulong(p->unk30);
    _ReadWriteBarrier();
    p->unk34 = _byteswap_ulong(p->unk34);
    _ReadWriteBarrier();
}
struct FUN_00c868b0_Obj
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
};
struct FUN_00cb8610_Class
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C()
    {}
    virtual void vf40()
    {}
    virtual void vf44()
    {}
    virtual void vf48()
    {}
    virtual void vf4C()
    {}
    virtual void vf50()
    {}
    virtual void vf54()
    {}

    virtual void FUN_00cb8610(void* arg);

    virtual void vf58()
    {}
    virtual void vf5C()
    {}
    virtual void vf60()
    {}
    virtual void vf64()
    {}
    virtual void vf68()
    {}
    virtual void vf6C()
    {}
    virtual void vf70()
    {}
    virtual void vf74()
    {}
    virtual void vf78()
    {}
    virtual void vf7C()
    {}
    virtual void vf80()
    {}
    virtual void vf84()
    {}
    virtual void vf88()
    {}
    virtual void vf8C()
    {}
    virtual void vf90()
    {}
    virtual void vf94()
    {}
    virtual void vf98()
    {}
    virtual void vf9C()
    {}
    virtual void vfA0()
    {}
    virtual void vfA4()
    {}
    virtual void vfA8()
    {}
    virtual void vfAC()
    {}

    virtual FUN_00c868b0_Obj* vfB4(unsigned char* value);

    void FUN_00c868b0(void* arg);
};
// bhkRagdollTemplate::bhkRagdollTemplate @ 0xcbaf20 (84 bytes)
// ctor: NiExtraData base ctor (0xa7b2e0), derived vftable (0x10c8dcc), then member
// BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024> (vftable 0x10c8d28 + three
// zero stores) constructed inline; returns this.
// The original carries a dead /GS+EH unwind-only registration frame (FuncInfo
// optimizer folded away, and the c1 EH scope (unwind funclet destroys the base
// subobject) survived as stale weight.
// base NiExtraData: named after its ctor's address so the implicit base-ctor
// call binds to 0xa7b2e0
struct SearchNodeCB
{
    int unk00;
    unsigned int id;
    int unk08;
    SearchNodeCB* parent;
};
struct InputCB
{
    __m128 point;
    float x;
    float y;
    float z;
    float score;
    SearchNodeCB* first;
    SearchNodeCB* second;
};
struct OutputCB
{
    __m128 point;
    float x;
    float y;
    float z;
    float score;
    SearchNodeCB* firstRoot;
    unsigned int firstId;
    int unk28_0;
    int unk28_1;
    int unk28_2;
    int unk28_3;
    int unk28_4;
    int unk28_5;
    int unk28_6;
    int unk28_7;
    SearchNodeCB* secondRoot;
    unsigned int secondId;
    unsigned int secondPath[8];
};
struct ContextCB
{
    int unk00;
    float limit;
    OutputCB* begin;
    OutputCB* next;
    int capacity;
    int size;
};
static __declspec(noinline) void CopyCB(OutputCB* dest, const InputCB* src)
{
    dest->point = src->point;
    *(__m128*)&dest->x = *(__m128 const*)&src->x;
    SearchNodeCB* c = src->first;
    while (c->parent)
        c = c->parent;
    dest->firstRoot = c;
    c = src->second;
    while (c->parent)
        c = c->parent;
    dest->secondRoot = c;
    dest->firstId = src->first->id;
    dest->secondId = src->second->id;
    SearchNodeCB* h = src->second;
    int count = 0;
    SearchNodeCB* n = h->parent;
    while (n)
    {
        n = n->parent;
        ++count;
    }
    dest->secondPath[count] = 0xffffffff;
    int i = count - 1;
    while (i >= 0)
    {
        dest->secondPath[i] = h->id;
        h = h->parent;
        --i;
    }
}
void __cdecl InsertIntoContext(const InputCB* input, ContextCB* context);
struct FUN_00cbda30_io;
struct FUN_00cbda30_io
{
    unsigned int unk00;
    unsigned int m04;
    unsigned int(__cdecl* m08)(FUN_00cbda30_io*, void*, unsigned int, unsigned int, unsigned int);
};
struct FUN_00cbda30_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
    char unk1E6;
    char unk1E7;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    FUN_00cbda30_io* m24C;
};
struct FUN_00cbda30_rec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};
struct FUN_00cbda30_cls
{
    virtual void v00()
    {}
    FUN_00cbda30_rec* m04;
    void FUN_00c8a230(FUN_00cbda30_arg* a);
    void ReadRecord(FUN_00cbda30_arg* a1);
};
void SwapEndianBlocks(void* p);
extern "C" void _ReadWriteBarrier(void);
unsigned int* __cdecl SwapEndianBlocks(unsigned int* arg);
struct CA3F10MemMgr
{
    void* Allocate(unsigned int size);
};
extern CA3F10MemMgr g_kCA3F10MemMgr;
struct CA3F10BinaryStream
{
    void* unk00;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(CA3F10BinaryStream* pkStream, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
template <class T> inline unsigned int CA3F10LoadBinary(CA3F10BinaryStream& kStream, T& val)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryRead(&val, sizeof(T), &uiSize, 1);
}
struct CA3F10Triangle
{
    unsigned int uiVerts01;
    unsigned int uiVert2Welding;
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};
struct CA3F10Vertex
{
    float x;
    float y;
    float z;
    CA3F10Vertex()
    {}
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};
struct CA3F10Normal
{
    float x;
    float y;
    float z;
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};
struct Alloc9bd0
{
    virtual void R();
    virtual void* Allocate(unsigned int);
};
extern "C" int DAT_010c82ec;
struct Rec9bd0;
struct Router9bd0
{
    int a[4];
    Alloc9bd0* allocator;
    Alloc9bd0& heap()
    {
        return *allocator;
    }
};
struct Sub9bd0
{
    int v;
    void FUN_00d21ce0(Rec9bd0*);
};
struct Item9bd0
{
    void FUN_00c905b0();
};
struct Rec9bd0
{
    void* vt;
    unsigned short cap, fl;
    int pad[2];
    Sub9bd0 sub;
    int pad2[2];
    float score;
    void FUN_00ca9b40(Item9bd0*);
    void FUN_00ca9aa0();
    static void* operator new(unsigned int size)
    {
        Rec9bd0* m = (Rec9bd0*)((Router9bd0*)FUN_00c85750())->heap().Allocate(size);
        m->cap = (unsigned short)size;
        return m;
    }
    static void operator delete(void*);
    Rec9bd0()
    {
        FUN_00ca9aa0();
        vt = &DAT_010c82ec;
    }
};
extern "C" void _ReadWriteBarrier();
// 0x00cabcd0  340 B  /MT /O2 /GS /EHsc /Gy  - HSV ramp helper.
static inline float hkFloor(float x)
{
    return (float)floor((double)x);
}
static __declspec(noinline) void S00cabcd0_HSV(float* b, float h, float s, float v, float* g, float* r)
{
    float* const* pb = &b;
    volatile float* vp = b;
    (void)vp;
    (void)pb;
    int i;
    float f, p, q, t;
    if (s == 0.0f)
    {
        *r = *g = *b = v;
        return;
    }
    if (h == 1.0f)
    {
        i = 5;
        h = 6.0f;
    }
    else
    {
        h = h * 6.0;
        i = (int)hkFloor(h);
    }
    f = h - i;
    p = v * (1.0f - s);
    q = v * (1.0f - s * f);
    t = v * (1.0f - s * (1.0f - f));
    switch (i)
    {
    case 0:
        *r = v;
        *g = t;
        *b = p;
        break;
    case 1:
        *r = q;
        *g = v;
        *b = p;
        break;
    case 2:
        *r = p;
        *g = v;
        *b = t;
        break;
    case 3:
        *r = p;
        *g = q;
        *b = v;
        break;
    case 4:
        *r = t;
        *g = p;
        *b = v;
        break;
    default:
        *r = v;
        *g = p;
        *b = q;
        break;
    }
}
extern "C" void _ReadWriteBarrier();
extern "C" void __cdecl CopyIfNonEmpty(void*, int, int);
extern int DAT_01268358;
static __declspec(noinline) void* FUN_00cb0ad0(char* s, int maxLen)
{
    int len = hkString_strLen((int)s);
    if (len > maxLen)
        len = maxLen;
    char* p = (char*)AllocateWithHeader(FUN_00c85750()->allocator, len + 1);
    CopyIfNonEmpty(p, (int)s, len);
    p[len] = 0;
    return p;
}
struct StringSlot
{
    unsigned int* volatile p;
};
static void FUN_00cb0b10(StringSlot slotRef, char* s, int len);
struct S_ca4520_Entry
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    unsigned short count;
    unsigned short unk46;
    unsigned short* runs;
    unsigned short* lists;
    unsigned short GetCount() const
    {
        return count;
    }
    unsigned short* GetLengths() const
    {
        return runs;
    }
    unsigned short GetVertices() const
    {
        return (unsigned short)unk08;
    }
    unsigned short* FUN_00a75f10();
};
struct S_ca4520_Slot
{
    NiPointer<S_ca4520_Entry> entry;
    int unk04;
};
struct S_ca4520
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    S_ca4520_Slot* slots;
    S_ca4520_Slot& GetPart(unsigned int n) const
    {
        return slots[n];
    }
    S_ca4520_Entry* GetData(unsigned int n) const
    {
        return GetPart(n).entry;
    }
    bool IsDegenerate(unsigned int key) const;
};
static volatile int g_helperSink;
__declspec(noinline) static int FUN_00cb0b10(int a, int b, int c)
{
    g_helperSink = a + b + c;
    return g_helperSink;
}
struct SelfRef
{
    void* p;
};
static int g_sink;
static __declspec(noinline) void FUN_00cb0b10(SelfRef self, const char* s, int len)
{
    g_sink = (int)s + len;
    *(int*)self.p = g_sink;
}
template <typename KEY> struct MapOps
{
    static __forceinline unsigned hash(KEY key, unsigned mod)
    {
        return unsigned((unsigned long)(key) >> 4) * 2654435761U & mod;
    }
    static __forceinline int isValid(KEY key)
    {
        return key != KEY(-1);
    }
    static __forceinline int equal(KEY key0, KEY key1)
    {
        return key0 == key1;
    }
};
struct ProbeMap64
{
    struct Pair
    {
        unsigned __int64 key;
        unsigned __int64 val;
    };
    typedef MapOps<unsigned __int64> OPS;

    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FUN_00cb1c60(unsigned __int64 key);
};
extern int DAT_010c7600;
struct ExtraArray
{
    ~ExtraArray()
    {
        FUN_00aa10f0(m_pBase);
    }
    int unk00;
    S_00ca49a0_Elem* m_pBase;
    unsigned int unk08, m_uiESize, m_uiCount, growBy;
    ExtraArray(unsigned int n = 0, unsigned int g = 1)
    {
        unk08 = n;
        growBy = g;
        m_uiESize = 0;
        m_uiCount = 0;
        m_pBase = 0;
        unk00 = (int)&DAT_010c7600;
    }
    __declspec(noinline) void Resize(unsigned int capacity)
    {
        if (capacity == unk08)
            return;
        if (capacity < m_uiESize)
        {
            for (unsigned int i = capacity; i < m_uiESize; ++i)
            {
                if (m_pBase[i] != S_00ca49a0_Elem(0))
                {
                    m_pBase[i] = S_00ca49a0_Elem(0);
                    --m_uiCount;
                }
            }
            m_uiESize = capacity;
        }
        S_00ca49a0_Elem* old = m_pBase;
        unk08 = capacity;
        if (capacity)
        {
            m_pBase = (S_00ca49a0_Elem*)FUN_00aa13e0(capacity * sizeof(S_00ca49a0_Elem));
            for (unsigned int i = 0; i < m_uiESize; ++i)
                m_pBase[i] = old[i];
            for (unsigned int i = m_uiESize; i < unk08; ++i)
                m_pBase[i] = S_00ca49a0_Elem(0);
        }
        else
            m_pBase = 0;
        FUN_00aa10f0(old);
    }
    void ClearRecords();
    __declspec(noinline) void FUN_00ca49a0(unsigned int i, const S_00ca49a0_Elem& e)
    {
        if (i >= m_uiESize)
        {
            m_uiESize = i + 1;
            if (e != S_00ca49a0_Elem(0))
                ++m_uiCount;
        }
        else if (m_pBase[i] == S_00ca49a0_Elem(0))
        {
            if (e != S_00ca49a0_Elem(0))
                ++m_uiCount;
        }
        else
        {
            if (e == S_00ca49a0_Elem(0))
                --m_uiCount;
        }
        m_pBase[i] = e;
    }
    const S_00ca49a0_Elem& GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    unsigned int Add(const S_00ca49a0_Elem& e)
    {
        return SetAtGrow(m_uiESize, e);
    }
    unsigned int SetAtGrow(unsigned int i, const S_00ca49a0_Elem& e)
    {
        if (i >= unk08)
            Resize(i + growBy);
        FUN_00ca49a0(i, e);
        return i;
    }
};
struct SavedExtraArray : ExtraArray
{
    SavedExtraArray() : ExtraArray()
    {}
};
struct SerializedExtraBody
{
    unsigned int unk00;
    float scale;
    ExtraArray entries;
    unsigned int value20, value24, value28, value2c;
    static void Swap4(void* p)
    {
        *(unsigned int*)p = _byteswap_ulong(*(unsigned int*)p);
    }
    void Swap()
    {
        Swap4(&scale);
        Swap4(&value20);
        Swap4(&value24);
        Swap4(&value28);
        Swap4(&value2c);
    }
};
inline void SaveR(S_00ca59d0_Bin& bin, const unsigned int* p)
{
    unsigned int uiSize = 4;
    unsigned int written = bin.unk0C(&bin, p, 4, &uiSize, 1);
    bin.unk04 += written;
}
inline void SaveRV(S_00ca59d0_Bin& bin, unsigned int value)
{
    SaveR(bin, &value);
}
extern int DAT_0102009c;
extern int DAT_01268154;
extern int DAT_01268118;
struct cb86f0_obj : bhkRefObject
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;

    cb86f0_obj()
    {
        Initialize();
        vtable = (void*)0x102016c;
        const int inc = 1;
        unk0c = 0;
        DAT_01268154 += inc;
        vtable = (void*)&DAT_0102009c;
        DAT_01268118 += inc;
        vtable = (void*)0x10c8914;
    }

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
struct S_ca5870_Alloc
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
struct S_ca5870_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_ca5870_Alloc* m_10;
};
struct S_ca5870_Obj
{
    S_ca5870_Obj(void* arg);
    int unk00;
    unsigned short m_04;
    unsigned short unk06;
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
    void FUN_00c905b0();

    static void* operator new(unsigned int size) throw()
    {
        S_ca5870_Holder* h = (S_ca5870_Holder*)FUN_00c85750();
        void* p = h->m_10->Alloc(size);
        ((S_ca5870_Obj*)p)->m_04 = (unsigned short)size;
        return p;
    }
};
extern "C" void __cdecl _ReadWriteBarrier(void);
template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& val)
    {
        FNVTaskMemoryRouter* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(router->allocator, this, sizeof(T));
        }
        T* slot = m_data + m_iElementCount;
        _ReadWriteBarrier();
        *slot = val;
        m_iElementCount++;
    }
};

union __declspec(align(16)) AcousticVector
{
    float lanes[4];
    signed char bytes[16];
};
struct hkpWorld
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    void* m_ulUserData;
    void* getUserData() const
    {
        return m_ulUserData;
    }
};
struct hkpWorldObject
{
    void* vt;
    int refc;
    hkpWorld* m_pOwningWorld;
    hkpWorld* getWorld() const
    {
        return m_pOwningWorld;
    }
};
struct hkpCollidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    void* getOwner() const
    {
        return (void*)((char*)this + m_iOwnerOffset);
    }
};
struct ContactCallback
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int* out);
};
struct bhkWorld
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
    ContactCallback* m28;
};
inline hkpWorldObject* GetWorldObject(const hkpCollidable* c)
{
    return (hkpWorldObject*)c->getOwner();
}
inline bhkWorld* GetOwningWorld(hkpWorld* w)
{
    return w ? (bhkWorld*)w->getUserData() : 0;
}
inline bhkWorld* GetOwningWorld(const hkpCollidable* c)
{
    return GetOwningWorld(GetWorldObject(c)->getWorld());
}
// @f3 0x0090ef70 (community match, verified in this file)
struct CallbackX
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int* out);
};
struct __declspec(align(16)) Vec16X
{
    int q0;
    int q1;
    int q2;
    int q3;
};
struct RecX
{
    Vec16X v00;
    Vec16X v10;
    void* a20;
    int u24;
    hkpCollidable* p28;
    int u2c;
    Vec16X v30;
};
struct BhkWorldX
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
    CallbackX* m30;
};
struct HkWorldX
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    void* m_ud310;
    void* getUserData() const
    {
        return m_ud310;
    }
};
inline bhkWorld* GetOwningWorldX(hkpWorld* w)
{
    return w ? (bhkWorld*)((HkWorldX*)w)->getUserData() : 0;
}
inline bhkWorld* GetOwningWorldX(hkpCollidable* c)
{
    return GetOwningWorldX(GetWorldObject(c)->getWorld());
}
// pdb: hkPackedNiTriStripsShape::getCollisionFilterInfo | hkPackedNiTriStripsShape.obj | fnv360_0822_debug, objrun_open, low
// pdb params: aKey
extern "C" void __stdcall FUN_00ca0bd0(void* a, hkpCollidable* p)
{
    RecX r;
    r.a20 = a;
    r.p28 = p;
    bhkWorld* o = GetOwningWorldX(p);
    if (o)
    {
        ((BhkWorldX*)o)->m30->v07((int*)&r);
    }
}

