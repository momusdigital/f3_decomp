// staging/blk_00ca0000_o2_rtm_variant.cpp: hkQuaternion, AryType, RayCaster_rc1c, VelocityController and more (7 functions)
#include <xmmintrin.h>
// src/staging/blk_00ca0000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00ca0000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

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
struct S_00ca9940_Child
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual unsigned int vfn_20();
};
struct S_00ca9940_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00ca9940_Child* m_pChildObject;
};
void __cdecl FUN_00cc96b0(float f, S_00ca9940_Child* c);
void __cdecl FUN_00cbd9e0(float f, S_00ca9940_Child* c);
void __cdecl FUN_00ca9940(float afValue, S_00ca9940_Obj* pObj);
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
struct FUN_00cb9a90 : S_cb9a90_C
{
    void FUN_00cab0e0(int a, int b, float c);
    FUN_00cb9a90(int a, int b, float c);
    virtual ~FUN_00cb9a90();
};
class GlobalObjectO2_00a7b610;
struct CB9B80Header
{
    int unk00;
};
struct CB9B80BaseInfo
{
    int unk00;
};
struct CB9B80Info : CB9B80Header, CB9B80BaseInfo
{
};
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
class FUN_00cb9b80 : public CB9B80WorldObject
{
  public:
    FUN_00cb9b80(CB9B80Info* pkInfo);
    virtual ~FUN_00cb9b80();

    void Init(CB9B80BaseInfo* pkInfo);

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
void* __cdecl FUN_00a5b690(int flag);
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
extern float DAT_0104da48;
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
struct FUN_00cb9a10 : SpawnMidBase
{
    FUN_00cb9a10(char* source);
    void SpawnAndAttach(char* source);
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

namespace fnv_00ca0b70 {
struct World;

struct WorldObject
{
    int unk00;
    int unk04;
    World* m_pOwningWorld;
};

struct Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char m_iOwnerOffset;
    WorldObject* getOwner() const
    {
        return (WorldObject*)((char*)this + m_iOwnerOffset);
    }
};

struct __declspec(align(16)) LocalEvent
{
    __m128 m_vComponents;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_a1;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    Collidable* m_a2;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

struct TargetClass
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(LocalEvent& event);
};

struct Mgr
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
    TargetClass* m_target;
};

struct World
{
    int unk000[0xd4];
    Mgr* m_pManager;
};

}  // namespace fnv_00ca0b70

#include <xmmintrin.h>

extern __m128 DAT_010ec7f0;

struct RayScalar_rc1c
{
    __m128 value;
    RayScalar_rc1c(float x)
    {
        value = _mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};

struct hkVector4_rc1c
{
    __m128 m_vComponents;
    hkVector4_rc1c()
    {}
    __forceinline void operator=(const hkVector4_rc1c& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline hkVector4_rc1c(const hkVector4_rc1c& v) : m_vComponents(v.m_vComponents)
    {}
    void setInterpolate4(const hkVector4_rc1c& a, const hkVector4_rc1c& b, const RayScalar_rc1c& t)
    {
        __m128 tt = t.broadcast();
        __m128 s = _mm_sub_ps(DAT_010ec7f0, tt);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, a.m_vComponents), _mm_mul_ps(tt, b.m_vComponents));
    }
};

struct hkpCollidable_rc1c
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    char unk11;
    short unk12;
    int unk14;
    unsigned char m_type;
    char unk19;
    short unk1a;
    unsigned int m_uiCollisionFilterData;
    int getType() const
    {
        return m_type;
    }
    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};

struct hkpWorldObject_rc1c
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkpCollidable_rc1c m_kCollidable;
    unsigned int GetFilterInfoForKey() const
    {
        return m_kCollidable.m_uiCollisionFilterData;
    }
};

struct hkpWorldRayCastOutput_rc1c
{
    hkVector4_rc1c m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
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
    const hkpCollidable_rc1c* m_pRootCollidable;
    int unk54;
    int unk58;
    int unk5c;
    __forceinline hkpWorldRayCastOutput_rc1c(const hkpWorldRayCastOutput_rc1c& o)
    {
        m_vHitNormal = o.m_vHitNormal;
        m_fHitFraction = o.m_fHitFraction;
        m_iExtraInfo = o.m_iExtraInfo;
        unk18 = o.unk18;
        unk1c = o.unk1c;
        unk20 = o.unk20;
        unk24 = o.unk24;
        unk28 = o.unk28;
        unk2c = o.unk2c;
        unk30 = o.unk30;
        unk34 = o.unk34;
        unk38 = o.unk38;
        unk3c = o.unk3c;
        unk40 = o.unk40;
        unk44 = o.unk44;
        unk48 = o.unk48;
        unk4c = o.unk4c;
        m_pRootCollidable = o.m_pRootCollidable;
        unk54 = o.unk54;
        unk58 = o.unk58;
        unk5c = o.unk5c;
    }
};

struct hkpWorldRayCastInput_rc1c
{
    hkVector4_rc1c m_vFrom;
    hkVector4_rc1c m_vTo;
    bool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
    hkpWorldRayCastInput_rc1c() : m_bEnableShapeCollectionFilter(false), m_uiFilterInfo(0)
    {}
};

struct hkpRayHitCollector_rc1c
{
    float m_fEarlyOutHitFraction;
    virtual ~hkpRayHitCollector_rc1c();
};

struct hkpWorldRayCastOutputArray_rc1c
{
    hkpWorldRayCastOutput_rc1c* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkpWorldRayCastOutput_rc1c m_kStorage[8];
};

struct hkpAllRayHitCollector_rc1c : public hkpRayHitCollector_rc1c
{
    hkpWorldRayCastOutputArray_rc1c m_kHits;
    hkpAllRayHitCollector_rc1c();
    virtual ~hkpAllRayHitCollector_rc1c();
    void reset()
    {
        m_fEarlyOutHitFraction = 1.0f;
        m_kHits.m_iElementCount = 0;
    }
};

struct RayFilter_rc1c
{
    unsigned int bits;
    RayFilter_rc1c(unsigned int x) : bits(x)
    {}
    void AddObjectReference(unsigned int x)
    {
        bits &= 0xffff;
        bits |= x << 16;
    }
    void setLayer(unsigned int x)
    {
        bits &= ~0x7fu;
        bits |= x;
    }
    bool bip() const
    {
        unsigned int layer = bits & 0x7f;
        return layer == 8 || layer == 29;
    }
    operator unsigned int() const
    {
        return bits;
    }
};

struct Ca35Owner;
struct Ca35Record
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int unk08;
};
struct Ca35Entry
{
    unsigned short m_00;
    unsigned short unk02;
    unsigned int unk04;
};
struct Ca35Table
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int unk0c;
    unsigned int unk10;
    Ca35Entry* m_14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Ca35Record* m_24;
};
struct Ca35Owner
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
    Ca35Table* m_74;
    unsigned int FUN_00ca35d0(unsigned int a1);
};
// @fnv 0x00ca35d0
// pdb: hkpTriangleShape::setWeldingType | hkPackedNiTriStripsShape.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: type
unsigned int Ca35Owner::FUN_00ca35d0(unsigned int a1)
{
    unsigned int type = a1 >> 24;
    unsigned int v = (a1 & 0xffffff) + 1;
    if (v >= m_74->m_08)
    {
        return 0xffffffff;
    }
    unsigned int sum = 0;
    for (int i = 0; i <= (int)type; ++i)
        sum += m_74->m_24[i].m_04;
    unsigned int w = m_74->m_14[v].m_00;
    if (w >= sum)
        ++type;
    return (v & 0xffffff) | (type << 24);
}

typedef union __declspec(intrin_type) _CRT_ALIGN(16) S00ca4120_Q
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
} S00ca4120_Q;
extern "C"
{
    ::__m128 _mm_min_ps(::__m128, ::__m128);
    ::__m128 _mm_max_ps(::__m128, ::__m128);
    ::__m128 _mm_mul_ps(::__m128, ::__m128);
    ::__m128 _mm_setr_ps(float, float, float, float);
}
extern float DAT_012682c8;
extern const float DAT_01011d78;
extern float DAT_0104da48;
struct S00ca4120_Vec
{
    S00ca4120_Q q;
    void set(float a, float b, float c, float d)
    {
        q.m128_f32[0] = a;
        q.m128_f32[1] = b;
        q.m128_f32[2] = c;
        q.m128_f32[3] = d;
    }
    void setMin4(const S00ca4120_Vec& a, const S00ca4120_Vec& b)
    {
        *(::__m128*)&q = (_mm_min_ps)(*(::__m128*)&a.q, *(::__m128*)&b.q);
    }
    void setMax4(const S00ca4120_Vec& a, const S00ca4120_Vec& b)
    {
        *(::__m128*)&q = (_mm_max_ps)(*(::__m128*)&a.q, *(::__m128*)&b.q);
    }
    void mul4(const S00ca4120_Vec& a)
    {
        *(::__m128*)&q = (_mm_mul_ps)(*(::__m128*)&q, *(::__m128*)&a.q);
    }
    void FUN_00c7f640(const struct S00ca4120_Xf* t, const S00ca4120_Vec* v);
};
struct S00ca4120_Xf
{
    S00ca4120_Vec c0, c1, c2, c3;
};

#include <xmmintrin.h>

struct VelocityBody
{
    void FUN_00631100(float amount, const __m128* velocity);
};

struct VelocityHolder
{
    int unk00;
    int unk04;
    VelocityBody* body;
};

struct VelocityProperty
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    VelocityHolder* holder;
    int unk14;
    float fraction;
};

struct DynCastHelper
{
    VelocityProperty* DynamicCast(const GlobalObjectO2_00a7b610* type);
};

struct VelocityNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DynCastHelper* property;
};

struct VelocityController
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
    VelocityNode* node;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    __m128 velocity;
    float amount;
    void FUN_00cb9290();
};

// @f3 0x0092b950 (community match, verified in this file)
extern "C" VelocityProperty* __cdecl FUN_007235f0(VelocityNode* node);

struct __declspec(align(16)) Vec4f
{
    float x;
    float y;
    float z;
    float w;
};

struct VelocityBodyCaller
{
    void FUN_00571d10(float amount, const __m128* velocity);
};

// pdb: bhkForceController::ApplyForce | bhkForceController.obj | fnv360_0822_retail, objrun, medium
void VelocityController::FUN_00cb9290()
{
    if (node)
    {
        VelocityProperty* prop = FUN_007235f0(node);
        if (prop && prop->fraction < 1.0f)
        {
            VelocityHolder* holder = prop->holder;
            if (holder)
            {
                VelocityBody* body = holder->body;
                if (body)
                {
                    Vec4f scaled;
                    scaled.x = velocity.m128_f32[0];
                    scaled.y = velocity.m128_f32[1];
                    scaled.z = velocity.m128_f32[2];
                    scaled.w = velocity.m128_f32[3];
                    scaled.x *= 100.0;
                    scaled.y *= 100.0;
                    scaled.z *= 100.0;
                    scaled.w *= 100.0;
                    ((VelocityBodyCaller*)body)->FUN_00571d10(amount, (const __m128*)&scaled);
                }
            }
        }
    }
}


#include <xmmintrin.h>
class NiRTTI;
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012683f4;
extern GlobalObjectO2_00a7b610 g_012043f8;
extern float DAT_01015f5c;
extern float DAT_011b1d3c;
void __fastcall FUN_00a6d220(void* p);
struct MemoryManagerAllocHelper : MemoryManager
{
    void* Allocate(unsigned int size);
};
class NiTimeController;
class NiObject
{
  public:
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
    NiObject* DynamicCast(const void* pTypeID);
};
class NiAVObject
{
  public:
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* unk1c;
    NiTimeController* GetController(const NiRTTI* pRTTI);
};
extern int DAT_010c8a2c;
union Mem128
{
    __m128 v;
    struct
    {
        float x;
        float y;
        float z;
        float w;
    } components;
};
class NiTimeController;
struct NTCVtable
{
    virtual ~NTCVtable();
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void vf35(float v);
    virtual void v36();
    virtual void v37();
    virtual void vf38(NiAVObject* pObj);
};
struct NTCVt
{
    void* m_vtbl;
    int unk04;
    unsigned short flags08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Mem128 m_40;
    float m_50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    void* operator new(unsigned int size) throw();
    void operator delete(void*)
    {}
    NTCVt();
};
void* NTCVt::operator new(unsigned int size) throw()
{
    char* p = (char*)((MemoryManagerAllocHelper*)&_g_memoryManager)->Allocate(size);
    unsigned char adj = (unsigned char)(0x10 - ((unsigned char)(unsigned int)p & 0xf));
    p += adj;
    p[-1] = (char)adj;
    return p;
}

NTCVt::NTCVt()
{
    FUN_00a6d220(this);
    m_vtbl = (void*)&DAT_010c8a2c;
    m_40.v = DAT_01267e30;
    m_50 = 0.0f;
}

// @f3 0x0092b9f0 (community match, verified in this file)
extern int DAT_010f33dc;
extern float flt_00f7b22c;
extern double dbl_00dbe5e0;
extern float flt_00dbe620;
extern float flt_00db7260;

struct NTCVtNew : NTCVt
{
    NTCVtNew();
};

NiObject* __cdecl FUN_00424fe0(NiAVObject* pObj);

// The physics wrapper of the object. The pointer to the physics body at +8 is read as a volatile member: that keeps
// the body pointer in a register of its own (edi, after the wrapper pointer dies) instead of a scratch register.
struct Aux1Ctl
{
    void* unk00;
    int unk04;
    void* volatile unk08;
    float FUN_0056f860();
};

// Four floats aligned to 16 bytes, with the scalar (x87) forms of the vector helpers.
struct __declspec(align(16)) HVec
{
    float x, y, z, w;
    HVec() {}
    HVec(const HVec& v) { *this = v; }
    void operator=(const HVec& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    void add4(const HVec& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    void setMul4(float rs, const HVec& a) { float r = rs; x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
    void mul4(float rs) { float s = rs; x *= s; y *= s; z *= s; w *= s; }
};

struct Aux2Body
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180;
    float f184;
};

// pdb: bhkForceController::TestForce | bhkForceController.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject, arForce, apSpot
void __cdecl FUN_00cb9320(NiAVObject* a1, const void* a2, NiAVObject* a3)
{
    NiAVObject* pObj = a3;
    if (!pObj)
        pObj = a1;
    NTCVt* pCtrl = (NTCVt*)pObj->GetController((const NiRTTI*)&DAT_010f33dc);
    if (!pCtrl)
    {
        pCtrl = (NTCVt*)new NTCVtNew();
        ((NTCVtable*)pCtrl)->vf38(pObj);
    }
    NiObject* pUnk = FUN_00424fe0(pObj);
    HVec v(*(const HVec*)a2);
    if (pUnk && pUnk->unk10)
    {
        Aux1Ctl* pAux = (Aux1Ctl*)pUnk->unk10;
        float scale = pAux->FUN_0056f860();
        scale = flt_00f7b22c * scale;
        v.mul4(scale);
        Aux2Body* pBody = (Aux2Body*)pAux->unk08;
        float bias = (float)(pBody->f184 * dbl_00dbe5e0);
        HVec t;
        t.setMul4(bias, v);
        v.add4(t);
    }
    *(HVec*)&pCtrl->m_40 = v;
    pCtrl->unk14 = 0.0f;
    pCtrl->unk18 = flt_00dbe620;
    pCtrl->flags08 = (unsigned short)((pCtrl->flags08 & 0xfff5) | 5);
    pCtrl->unk10 = 0.0f;
    pCtrl->unk0c = 1.0f;
    ((NTCVtable*)pCtrl)->vf35(flt_00db7260);
}


#include <xmmintrin.h>

class CBD9E0V4
{
  public:
    __m128 m_vComponents;
    void mul(float s)
    {
        __m128 scalar = _mm_load_ss(&s);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), m_vComponents);
    }
};

namespace TriStripIntrinsics {
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_load_ps(float const*);
}

static float DAT_012682c8;

union S00ca45b0_Vec
{
    __m128 m_vComponents;
    char m_bytes[16];
    void set(float x, float y, float z, float w)
    {
        float* f = m_vComponents.m128_f32;
        f[0] = x;
        f[1] = y;
        f[2] = z;
        f[3] = w;
    }
    void operator=(const S00ca45b0_Vec& o)
    {
        m_vComponents = o.m_vComponents;
    }
    void mul4(const S00ca45b0_Vec& o)
    {
        m_vComponents =
            TriStripIntrinsics::_mm_mul_ps(TriStripIntrinsics::_mm_load_ps(m_vComponents.m128_f32), o.m_vComponents);
    }
};

namespace PointBoundsSse {
extern "C" __m128 _mm_load_ps1(float const* p);
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
}

extern float DAT_0104da48;

struct BoundVector
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct PointBounds
{
    BoundVector min;
    BoundVector max;
};
struct PointArrayArg
{
    BoundVector** p;
    PointArrayArg(BoundVector** v) : p(v)
    {}
};
struct BoundsArg
{
    PointBounds* p;
    BoundsArg(PointBounds* v) : p(v)
    {}
};

namespace StripsBoundsIntrinsics {
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_load_ps1(const float*);
    void _mm_store_ss(float*, __m128);
}
}

union StripsBoundsQuad
{
    __m128 simd;
    float lanes[4];
    signed char bytes[16];
};

struct StripsBoundsTransform;
class StripsBoundsVector
{
  public:
    StripsBoundsQuad m_vComponents;
    void add(const StripsBoundsQuad& r)
    {
        m_vComponents.simd = StripsBoundsIntrinsics::_mm_add_ps(m_vComponents.simd, r.simd);
    }
    float getX() const
    {
        float x;
        StripsBoundsIntrinsics::_mm_store_ss(&x, m_vComponents.simd);
        return x;
    }
    void FUN_00c7f640(const StripsBoundsTransform& t, const StripsBoundsVector& v);
};
extern float DAT_012682c8;

namespace PackedDisplayIntrinsics {
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
}

class NiFixedString
{
  public:
    char* m_kHandle;
    __forceinline NiFixedString(const char* s)
    {
        m_kHandle = (char*)FUN_00a5b690((int)s);
    }
    __forceinline ~NiFixedString()
    {
        if (m_kHandle != DAT_0109b220)
            DAT_00fdf1c4(m_kHandle - 8);
    }
};

static float DAT_011b1864 = 6.9991255f;
extern int DAT_0109b2d4;

union __declspec(align(16)) DisplayVector
{
    __m128 simd;
    float lanes[4];
    unsigned char byteLanes[16];
};

struct S00ca5da0_ArrayAllocation
{
    static __forceinline void* operator new[](unsigned int size)
    {
        return ((MemoryManager_t*)&DAT_011f6238)->FUN_00aa3e40(size);
    }
    static __forceinline void operator delete[](void*)
    {}
};

struct S00ca5da0_Vec3 : S00ca5da0_ArrayAllocation
{
    float x, y, z;
};

struct S00ca5da0_Entry
{
    unsigned short f0;
    unsigned short f1;
    unsigned short f2;
    unsigned short f6;
};

struct S00ca5da0_Part
{
    int unk00;
    unsigned int count;
    int unk08;
};

struct S00ca5da0_Geom
{
    int unk00;
    int unk04;
    unsigned int m_08;
    int unk0c;
    unsigned short m_10;
    unsigned short unk12;
    S00ca5da0_Entry* m_14;
    S00ca5da0_Vec3* m_18;
    int unk1c;
    int unk20;
    S00ca5da0_Part* m_24;
};

struct S00ca5da0_Data
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
    struct S00ca5da0_Geom* m_84;
};

struct S00ca5da0_Arr
{
    void* m_vtbl;
    unsigned short* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __declspec(noalias) void FUN_00a5b790(unsigned int size);
    __forceinline S00ca5da0_Arr(unsigned int maxSize = 0, unsigned int growBy = 1)
    {

        m_usMaxSize = (unsigned short)maxSize;
        m_usGrowBy = (unsigned short)growBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
        m_vtbl = &DAT_0109b2d4;
    }
    __forceinline ~S00ca5da0_Arr()
    {
        FUN_00aa10f0(m_pBase);
    }
    __forceinline void SetAt(unsigned int idx, const unsigned short& v)
    {
        if (idx >= m_usSize)
        {
            m_usSize = (unsigned short)(idx + 1);
            if (v != 0)
                m_usESize++;
        }
        else
        {
            if (v != 0)
            {
                if (m_pBase[idx] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[idx] != 0)
                    m_usESize--;
            }
        }
        m_pBase[idx] = v;
    }
    __forceinline unsigned int SetAtGrow(unsigned int idx, const unsigned short& v)
    {
        if (idx >= m_usMaxSize)
            FUN_00a5b790(idx + m_usGrowBy);
        SetAt(idx, v);
        return idx;
    }
    __forceinline unsigned int Add(const unsigned short& v)
    {
        return SetAtGrow(m_usSize, v);
    }
    __forceinline void RemoveAll()
    {
        for (unsigned short q = 0; q < m_usSize; q++)
            m_pBase[q] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
};

struct S00ca5da0_Mesh
{
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        FUN_00aa10f0(p);
    }
    S00ca5da0_Mesh();
    void FUN_00a66b30(unsigned short count, S00ca5da0_Vec3* verts, int a, int b, int c, int d, int e);
    void FUN_00a7b700(unsigned short count, unsigned short* tris);
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
};

struct S00ca5da0_Prop
{
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        FUN_00aa10f0(p);
    }
    S00ca5da0_Prop();
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

    int m_28;
    int m_2c;
    int m_30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;

    int m_44;
    int unk48;
};

struct S00ca5da0_Shape
{
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        FUN_00aa10f0(p);
    }
    S00ca5da0_Shape(S00ca5da0_Mesh* mesh);
    void AssignFixedString(const NiFixedString& name);
    void FUN_00439410(S00ca5da0_Prop* prop);
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

    float m_64;
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
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
};

struct S00ca5da0_Pt
{
    int x, y, z;
};

struct S00ca5da0_Node
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(S00ca5da0_Shape* child, int one);
};

struct S00ca5da0_Builder
{
    int unk00;
    int unk04;
    S00ca5da0_Data* m_08;
    void FUN_00ca5da0(S00ca5da0_Node* parent, S00ca5da0_Pt* pt);
};
double __fastcall GetField24Float(S00ca5da0_Builder* self);

extern const char DAT_010c9288[];
extern const char DAT_010c41f8[];
extern unsigned long DAT_0126835c;
extern void*(__stdcall* DAT_00fdf044)(unsigned long);
extern "C" void _ReadWriteBarrier(void);

struct S00cbfaa0_Entry
{
    const char* name;
    unsigned int time;
    unsigned int unk08;
};

struct S00cbfaa0_Stream
{
    int unk00;
    S00cbfaa0_Entry* m_cur;
    int unk08;
    S00cbfaa0_Entry* m_kRayEnd;
};

struct __declspec(align(16)) SinglePointVector
{
    float x, y, z, w;
};

struct S00cbfaa0_Src
{
    SinglePointVector q00;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned char m_20;
};

struct S00cbfaa0_Dst
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct S00cbfaa0_Rec
{
    SinglePointVector vec;
    int m_10;
    const void* m_14;
    int m_18;
    int m_1c;
};

struct S00cbfaa0_Base
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23(S00cbfaa0_Rec* r, struct S00cbfaa0_Obj* o, int z);
};

struct S00cbfaa0_Obj
{
    int unk00;
    S00cbfaa0_Src* m_04;
    void* m_08;
    int m_0c;
    int m_10;
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
    void* m_44;
    void hkpWorldRayCaster_castRaysFromSinglePoint(S00cbfaa0_Base* a0, S00cbfaa0_Src* a1, int a2, S00cbfaa0_Dst* a3, int a4, int a5, int a6);
};

// @f3 0x00943080 (community match, verified in this file)
struct S00cbfaa0_Slot21
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21(S00cbfaa0_Rec* r, S00cbfaa0_Obj* o, int z);
};

// pdb: hkpWorldRayCaster::castRaysFromSinglePoint | hkpWorldRayCaster.obj | fnv360_0822_retail, ustr + skyrim(ustr), high
void S00cbfaa0_Obj::hkpWorldRayCaster_castRaysFromSinglePoint(S00cbfaa0_Base* a0, S00cbfaa0_Src* a1, int a2, S00cbfaa0_Dst* a3, int a4, int a5,
                                 int a6)
{
    volatile unsigned int ts;
    void*(__stdcall * getStream)(unsigned long) = DAT_00fdf044;
    S00cbfaa0_Stream* st = (S00cbfaa0_Stream*)getStream(DAT_0126835c);
    S00cbfaa0_Entry* cur = st->m_cur;
    if (cur < st->m_kRayEnd)
    {
        cur->name = DAT_010c9288;
        _ReadWriteBarrier();
        ts = (unsigned int)__rdtsc();
        cur->time = ts;
        cur = cur + 1;
        st->m_cur = cur;
    }

    m_04 = a1;
    m_08 = a3 ? &a3->unk14 : 0;
    m_0c = a5;
    m_10 = a6;
    if (a1->m_20)
    {
        m_44 = a3 ? &a3->unk10 : 0;
    }
    else
    {
        m_44 = 0;
    }

    S00cbfaa0_Rec r;
    r.vec.x = a1->q00.x;
    r.vec.y = a1->q00.y;
    r.vec.z = a1->q00.z;
    r.vec.w = a1->q00.w;
    r.m_1c = a4;
    r.m_14 = &a1->unk10;
    r.m_10 = a2;
    r.m_18 = 0x30;
    ((S00cbfaa0_Slot21*)a0)->vf21(&r, this, 0);

    st = (S00cbfaa0_Stream*)getStream(DAT_0126835c);
    cur = st->m_cur;
    if (cur < st->m_kRayEnd)
    {
        cur->name = DAT_010c41f8;
        _ReadWriteBarrier();
        ts = (unsigned int)__rdtsc();
        cur->time = ts;
        cur = cur + 1;
        st->m_cur = cur;
    }
}


#include <xmmintrin.h>
namespace fnv_00ca1410 {
extern "C"
{
    ::__m128(_mm_load_ss)(const float*);
    void(_mm_store_ss)(float*, ::__m128);
    ::__m128(_mm_shuffle_ps)(::__m128, ::__m128, int);
    ::__m128(_mm_setr_ps)(float, float, float, float);
    ::__m128(_mm_sub_ps)(::__m128, ::__m128);
    ::__m128(_mm_mul_ps)(::__m128, ::__m128);
    ::__m128(_mm_add_ps)(::__m128, ::__m128);
    ::__m128(_mm_add_ss)(::__m128, ::__m128);
    ::__m128(_mm_sqrt_ss)(::__m128);
    ::__m128(_mm_set_ss)(float);
    ::__m128(_mm_cmpeq_ss)(::__m128, ::__m128);
    ::__m128(_mm_rsqrt_ss)(::__m128);
    ::__m128(_mm_mul_ss)(::__m128, ::__m128);
    ::__m128(_mm_sub_ss)(::__m128, ::__m128);
    ::__m128(_mm_andnot_ps)(::__m128, ::__m128);
}
extern const float DAT_0104da4c = 1.1920928955078125e-7f;
extern const float DAT_01011d78 = 0.0f;
extern const float DAT_01012068 = 1.0f;
extern void __cdecl FUN_00c908c0(FNVTaskAllocator&, void*, int, int);
template <class T> struct ArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline ArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline T* begin()
    {
        return data;
    }
    __forceinline T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline void grow(FNVTaskAllocator& heap, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int doubled = 2 * cap;
            int wanted = n < doubled ? doubled : n;
            FUN_00c908c0(heap, this, wanted, sizeof(T));
        }
    }
    __forceinline void reserveExact(FNVTaskAllocator& heap, int n)
    {
        if (getCapacity() < n)
            FUN_00c908c0(heap, this, n, sizeof(T));
    }
    __forceinline void SetSizeAndGrow(FNVTaskAllocator& heap, int n)
    {
        grow(heap, n);
        size = n;
    }
    __forceinline void setSizeZero(FNVTaskAllocator& heap, int n)
    {
        grow(heap, n);
        int remaining = n - size;
        T* out = data + size;
        for (int k = 0; k < remaining; ++k)
            *out++ = 0;
        size = n;
    }
};
struct RouterView : FNVTaskMemoryRouter
{
    FNVTaskAllocator& heap()
    {
        return *allocator;
    }
    static RouterView& current()
    {
        return *static_cast<RouterView*>(::FUN_00c85750());
    }
};
struct HeapChoice
{
    FNVTaskAllocator& get(const void*)
    {
        return RouterView::current().heap();
    }
};
template <class T> struct WorkArray : ArrayBase<T>
{
    ~WorkArray();
    __forceinline void reserve(int n)
    {
        reserveExact(HeapChoice().get(this), n);
    }
    __forceinline void resize(int n)
    {
        SetSizeAndGrow(HeapChoice().get(this), n);
    }
    __forceinline void resizeZero(int n)
    {
        setSizeZero(HeapChoice().get(this), n);
    }
};
struct SkeletonBone;
struct Transform;
struct Skeleton
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    ArrayBase<SkeletonBone> bones;
    ArrayBase<Transform> reference;
    ArrayBase<char*> slots;
};
struct ScalarValue
{
    ::__m128 q;
    ScalarValue()
    {}
    ScalarValue(const ::__m128& v) : q(v)
    {}
    ScalarValue(float f)
    {
        q = (_mm_load_ss)(&f);
    }
    operator float() const
    {
        float f;
        (_mm_store_ss)(&f, q);
        return f;
    }
    __forceinline ::__m128 splat() const
    {
        return (_mm_shuffle_ps)(q, q, 0);
    }
};
union VectorQuad
{
    ::__m128 simd;
    float lanes[4];
    signed char bytes[16];
};
struct VectorValue
{
    VectorQuad q;
    VectorValue()
    {}
    VectorValue(float x, float y, float z, float w)
    {
        q.simd = (_mm_setr_ps)(x, y, z, w);
    }
    VectorValue(const VectorValue& v)
    {
        q.simd = v.q.simd;
    }
    VectorValue(const ::__m128& v)
    {
        q.simd = v;
    }
    operator ::__m128() const
    {
        return q.simd;
    }
    void operator=(const ::__m128& v)
    {
        q.simd = v;
    }
    void operator=(const VectorValue& v)
    {
        q.simd = v.q.simd;
    }
    __forceinline void difference(const VectorValue& a, const VectorValue& b)
    {
        q.simd = (_mm_sub_ps)(a.q.simd, b.q.simd);
    }
    __forceinline void cross(const VectorValue& a, const VectorValue& b)
    {
        ::__m128 lhs =
            (_mm_mul_ps)((_mm_shuffle_ps)(a.q.simd, a.q.simd, 0xc9), (_mm_shuffle_ps)(b.q.simd, b.q.simd, 0xd2));
        ::__m128 rhs =
            (_mm_mul_ps)((_mm_shuffle_ps)(a.q.simd, a.q.simd, 0xd2), (_mm_shuffle_ps)(b.q.simd, b.q.simd, 0xc9));
        q.simd = (_mm_sub_ps)(lhs, rhs);
    }
    __forceinline void add(const VectorValue& a)
    {
        q.simd = (_mm_add_ps)(q.simd, a.q.simd);
    }
    __forceinline ScalarValue dot(const VectorValue& a) const
    {
        ::__m128 products = (_mm_mul_ps)(q.simd, a.q.simd);
        ::__m128 xy = (_mm_add_ss)((_mm_shuffle_ps)(products, products, 0x55), products);
        return (_mm_add_ss)((_mm_shuffle_ps)(products, products, 0xaa), xy);
    }
    __forceinline ScalarValue length() const
    {
        return (_mm_sqrt_ss)(dot(*this).q);
    }
    __forceinline ScalarValue inverseLength() const
    {
        ::__m128 half = (_mm_set_ss)(0.5f);
        ::__m128 three = (_mm_set_ss)(3.0f);
        ::__m128 zero = (_mm_set_ss)(0.0f);
        ::__m128 squared = dot(*this).q;
        ::__m128 isZero = (_mm_cmpeq_ss)(squared, zero);
        ::__m128 estimate = (_mm_rsqrt_ss)(squared);
        ::__m128 result = (_mm_mul_ss)((_mm_mul_ss)(half, estimate),
                                       (_mm_sub_ss)(three, (_mm_mul_ss)((_mm_mul_ss)(squared, estimate), estimate)));
        return (_mm_andnot_ps)(isZero, result);
    }
    __forceinline void normalize()
    {
        q.simd = (_mm_mul_ps)(inverseLength().splat(), q.simd);
    }
    __forceinline void scale(const ScalarValue& a, const VectorValue& b)
    {
        q.simd = (_mm_mul_ps)(a.splat(), b.q.simd);
    }
};
struct Contact
{
    short bone;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    VectorValue point, direction;
};
struct Transform
{
    VectorValue position, rotation, scale;
};
struct FUN_00c7c030
{
    Skeleton* skeleton;
    WorkArray<Transform> localFUN_00c7c030, modelFUN_00c7c030;
    WorkArray<int> flags;
    bool modelSync, localSync;
    WorkArray<float> floats;
    __forceinline FUN_00c7c030(Skeleton* s) : skeleton(s), modelSync(false), localSync(false)
    {
        int n = skeleton->bones.GetLogicalSize();
        modelFUN_00c7c030.resize(n);
        localFUN_00c7c030.resize(n);
        flags.resize(n);
        const int paddedCount = (skeleton->slots.GetLogicalSize() + 3) & ~3;
        floats.reserve(paddedCount);
        floats.resizeZero(skeleton->slots.GetLogicalSize());
    }
    ~FUN_00c7c030();
    ArrayBase<Transform>& FUN_00cd9fe0();
};
struct BodyHeader
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
    virtual void apply(const VectorValue*, const VectorValue*);
    unsigned int unk04;
    unsigned char type;
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
};
struct Body : BodyHeader
{
    VectorValue position;
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
    VectorValue linearVelocity;
    VectorValue angularVelocity;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    float hkpMotion_getMass();
    __forceinline void pointVelocity(const VectorValue& point, VectorValue& result) const
    {
        VectorValue offset;
        offset.difference(point, position);
        result.cross(angularVelocity, offset);
        result.add(linearVelocity);
    }
};
struct Properties
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int flags;
};
struct Meta
{
    unsigned int unk00, unk04, unk08, unk0c;
    Properties props;
};
struct Wrapper
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
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void refresh();
    unsigned int unk04;
    Meta* meta;
    void FUN_00a29680();
    inline Properties* getProps()
    {
        return meta ? &meta->props : 0;
    }
    inline unsigned int GetPropertyFlags()
    {
        Properties* p = getProps();
        return p ? p->flags : 0;
    }
    inline void setFlags(unsigned int value)
    {
        Meta* m = meta;
        if (m)
        {
            FUN_00a29680();
            Properties* props = &m->props;
            FUN_00a29680();
            if (props)
                props->flags = value;
        }
    }
    inline void changeFlag(bool set)
    {
        unsigned int f = GetPropertyFlags();
        if (((unsigned char)(f >> 14) & 1) != set)
        {
            setFlags(set ? f | 0x4000 : f & ~0x4000);
            refresh();
        }
    }
};
struct World
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
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    void* context;
};
struct Bone
{
    unsigned int unk00;
    unsigned int unk04;
    World* world;
    Wrapper* wrapper;
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
    Body body;
    void FUN_00c9c1d0();
};
struct Rig
{
    unsigned int unk00;
    unsigned int unk04;
    ArrayBase<Bone*> bones;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    ArrayBase<int> boneMap;
    Skeleton* skeleton;
    void FUN_00ce18d0(Transform*);
    inline Skeleton* getSkeleton() const
    {
        return skeleton;
    }
    inline int getNumBones() const
    {
        return getSkeleton()->bones.GetLogicalSize();
    }
    inline const ArrayBase<Bone*>& getBodies() const
    {
        return bones;
    }
    inline Bone* getBone(int n)
    {
        int index = boneMap[n];
        return index >= 0 ? bones[index] : 0;
    }
    inline World* getWorld()
    {
        Bone* root = bones[0];
        return root ? root->world : 0;
    }
};
struct ByteBoolean
{
    unsigned char value;
    operator bool() const
    {
        return value != 0;
    }
};
struct Controller
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    WorkArray<int> states;
    inline const ArrayBase<int>& getStates() const
    {
        return states;
    }
    void ResetEntries();
    ByteBoolean FUN_00d1fb00(FUN_00c7c030&, WorkArray<Contact>&);
};
struct Observer
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
    virtual World* getWorld();
    virtual void v98();
    virtual void setWorld(void*);
};
struct Entry
{
    unsigned int unk00;
    Rig* rig;
    unsigned int unk08;
    Observer* observer;
    Controller* controller;
    WorkArray<Contact> contacts;
    bool active;
};
struct EntryListNode
{
    unsigned int capacity;
    Entry** data;
    unsigned int size;
    inline unsigned int GetLogicalSize() const
    {
        return size;
    }
    __forceinline Entry*& operator[](unsigned int i)
    {
        return data[i];
    }
};

}  // namespace fnv_00ca1410

template <class T, unsigned Growth> __forceinline T& GetAtSV(BSSimpleArray<T, Growth>& a, int index)
{
    return a.pBuffer[index];
}
union RagdollScalarVector
{
    ::__m128 simd;
    struct
    {
        float x, y, z, w;
    } scalar;
    signed char bytes[16];
};
struct ScalarValue
{
    float value;
    ScalarValue(float x)
    {
        RagdollScalarVector copy;
        *reinterpret_cast<float*>(&copy.bytes[0]) = x;
        value = copy.scalar.x;
    }
};

namespace RagdollConstruction {
struct FUN_00cb9a90 : S_cb9a90_C
{
    FUN_00cb9a90(int, int, float);
    static __forceinline void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
struct FUN_00cb9a10 : SpawnMidBase
{
    FUN_00cb9a10(char*);
    static __forceinline void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
struct FUN_00cb9b80 : CB9B80WorldObject
{
    FUN_00cb9b80(CB9B80Info*);
    static __forceinline void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
}
extern "C" void _ReadWriteBarrier();
struct CopyMap
{
    virtual ~CopyMap();
};
struct Init
{
    CopyMap* clones;
    CopyMap* processed;
    int copyType;
    char append;
    Init(unsigned int);
    __forceinline ~Init()
    {
        delete clones;
        delete processed;
    }
};
struct ScaleShapeData
{
    int unk00;
    void FUN_00c905b0();
};
struct IntegerBlock18
{
    __forceinline int GetC() const
    {
        return unk0c;
    }
    __forceinline int GetD() const
    {
        return unk10;
    }
    __forceinline void SetC(int v)
    {
        unk0c = v;
    }
    __forceinline void SetD(int v)
    {
        unk10 = v;
    }
    __forceinline ScaleShapeData* GetShape() const
    {
        return shape;
    }
    int unk00;
    ScaleShapeData* shape;
    int unk08;
    int unk0c;
    int unk10;
    void SetChildObject(ScaleShapeData*);
};
struct ViewPart
{
    int part;
};
struct ShapeRef
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual void v98();
    virtual void SetContext(void*);
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual ViewPart* GetView(char*);
    volatile long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    ScaleShapeData* data;
    int unk0c;
};
struct FUN_00cb9b30 : ShapeRef
{
    FUN_00cb9b30(IntegerBlock18*);
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        _delete(p, 0x10);
    }
};
struct FUN_009ba410 : ShapeRef
{
    FUN_009ba410(IntegerBlock18*);
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        _delete(p, 0x10);
    }
};
struct FUN_00c88380 : ShapeRef
{
    FUN_00c88380(IntegerBlock18*);
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        _delete(p, 0x10);
    }
};

struct ShapeLink
{
    ShapeLink* next;
    ShapeLink* prev;
    ShapeRef* object;
};
struct Body;
struct Motion
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetMass(float);
};
struct Body
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetShape(ScaleShapeData*);
    int unk04;
    int unk08;
    int unk0c;
    ShapeLink* shapeHead;
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
    float damping90;
    float damping94;
    Motion* FUN_00ca86c0();
    void FUN_00ca88c0(float);
};
struct BodyOwner
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
    virtual void* GetContextOwner();
    int unk04;
    Body* body;
    int unk0c;
    int unk10;
    NiPointer<ShapeRef> shape;
    __declspec(noinline) void FUN_00a29680();
    __forceinline ShapeRef* GetShape(Body* current)
    {
        if (current)
        {
            FUN_00a29680();
            ShapeLink** head = &current->shapeHead;
            FUN_00a29680();
            if (head && *head)
                return (*head)->object;
        }
        return 0;
    }
    __forceinline void SetMass(const ScalarValue& mass)
    {
        Motion* motion = body ? body->FUN_00ca86c0() : 0;
        if (motion)
            motion->SetMass(mass.value);
        else if (body)
            body->FUN_00ca88c0(mass.value);
    }
    __forceinline void SetAngularDamping(const ScalarValue& a)
    {
        body->damping90 = a.value;
    }
    __forceinline void SetLinearDamping(const ScalarValue& a)
    {
        body->damping94 = a.value;
    }
};
struct CastBody
{
    int unk00, unk04, unk08, unk0c;
    BodyOwner* owner;
};
struct CastObject
{
    CastBody* FUN_00653290(const void*);
};
struct SceneObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    CastObject* collision;
};
struct CloneProcess : Init
{
    float scaleX, scaleY, scaleZ;
    __forceinline CloneProcess(unsigned n) : Init(n)
    {
        scaleX = scaleY = scaleZ = 1.0f;
    }
};
extern "C" void __cdecl FUN_00ca9940(float, ScaleShapeData*);
extern "C" void __cdecl FUN_00cc96b0(float, ScaleShapeData*);
struct ShapeUpdater
{
    int unk00, unk04, unk08;
    BSSimpleArray<IntegerBlock18*, 1024> shapes;
    BSSimpleArray<unsigned, 1024> kinds;
    float mass, linearDamping, angularDamping, radius;
    int material;
    __forceinline int GetMaterial() const
    {
        return material;
    }
    __forceinline IntegerBlock18* GetInfo(unsigned i)
    {
        return GetAtSV(shapes, i);
    }
    __forceinline unsigned GetKind(unsigned i)
    {
        return GetAtSV(kinds, i);
    }
    void FUN_00cba6f0(SceneObject*, float);
};
static __forceinline NiPointer<ShapeRef>& AssignSV(NiPointer<ShapeRef>& self, const NiPointer<ShapeRef>& other)
{
    if (self.m_pObject != other.m_pObject)
    {
        if (self.m_pObject)
            self.m_pObject->DecRefCount();
        self.m_pObject = other.m_pObject;
        if (self.m_pObject)
            self.m_pObject->IncRefCount();
    }
    return self;
}
struct ScaledShapeData : ScaleShapeData
{
};
void __cdecl FUN_00cbd9e0(float, ScaledShapeData*);
struct CapsuleData : ScaleShapeData
{
};
void __cdecl FUN_00cbd9e0(float, CapsuleData*);
struct ScriptProgram : ScaleShapeData
{
};
void __cdecl FUN_00cbd9e0(float, ScriptProgram*);
// @f3 0x0092ce00 (community match, verified in this file)
extern const float g_zeroVec_0092ce00;

namespace fn_0092ce00 {

struct ContextOwnerLocal;
struct MotionLocal;
struct ShapeLinkLocal;
struct ScaleShapeLocal
{
    int m_f00;
};
struct ScaledShapeLocal : ScaleShapeLocal
{
};
struct CapsuleLocal : ScaleShapeLocal
{
};
struct ScriptProgramLocal : ScaleShapeLocal
{
};

struct CopyMapLocal
{
    virtual ~CopyMapLocal();
};

struct FUN_00471430
{
    CopyMapLocal* clones;
    CopyMapLocal* processed;
    int copyType;
    char append;
    FUN_00471430(unsigned int);
    __forceinline ~FUN_00471430()
    {
        delete clones;
        delete processed;
    }
};

struct CloneProcessLocal : FUN_00471430
{
    float scaleX, scaleY, scaleZ;
    __forceinline CloneProcessLocal(unsigned int n) : FUN_00471430(n)
    {
        scaleX = scaleY = scaleZ = 1.0f;
    }
};

struct ShapeBlock18
{
    __forceinline void SetC(int v)
    {
        m_f0c = v;
    }
    __forceinline void SetD(int v)
    {
        m_f10 = v;
    }
    __forceinline ScaleShapeLocal* GetShape() const
    {
        return m_pShape;
    }
    int m_f00;
    ScaleShapeLocal* m_pShape;
    int m_f08;
    int m_f0c;
    int m_f10;
    void FUN_008fbbb0(ScaleShapeLocal*);
};

struct ViewPrefixLocal
{
    int prefix;
};

struct ViewPartLocal
{
    int part;
};

struct ShapeViewLocal : ViewPrefixLocal, ViewPartLocal
{
    int m_f04;
    int m_f08;
    int m_f0c;
};

extern "C" void* __cdecl FUN_0089eb90(unsigned int);

struct ShapeRefLocal
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual ContextOwnerLocal* GetContextOwner();
    virtual void SetContext(void*);
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual ViewPartLocal* GetView(char*);
    long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    ScaleShapeLocal* data;
    int m_f0c;
    static __forceinline void* operator new(unsigned int size)
    {
        return FUN_0089eb90(size);
    }
    static void operator delete(void* p, unsigned int size);
};

struct MaterialShapeLocal : ShapeRefLocal
{
    int material;
};

struct ShapeLinkLocal
{
    ShapeLinkLocal* next;
    ShapeLinkLocal* prev;
    ShapeRefLocal* object;
};

struct MotionLocal
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetMass(float);
};

struct BodyLocal
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetShape(ScaleShapeLocal*);
    int m_f04;
    int m_f08;
    int m_f0c;
    ShapeLinkLocal* shapeHead;
    int m_f14;
    int m_f18;
    int m_f1c;
    int m_f20;
    int m_f24;
    int m_f28;
    int m_f2c;
    int m_f30;
    int m_f34;
    int m_f38;
    int m_f3c;
    int m_f40;
    int m_f44;
    int m_f48;
    int m_f4c;
    int m_f50;
    int m_f54;
    int m_f58;
    int m_f5c;
    int m_f60;
    int m_f64;
    int m_f68;
    int m_f6c;
    int m_f70;
    int m_f74;
    int m_f78;
    int m_f7c;
    int m_f80;
    float friction;
    float restitution;
    MotionLocal* hkpRigidBody_getStoredDynamicMotion();
    void FUN_0090c710(float);
};

template <class T> class ShapePtrLocal
{
public:
    T* m_pObject;
    ShapePtrLocal(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~ShapePtrLocal()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
};

static __forceinline ShapePtrLocal<ShapeRefLocal>& AssignShapePtr(
    ShapePtrLocal<ShapeRefLocal>& self,
    const ShapePtrLocal<ShapeRefLocal>& other)
{
    if (self.m_pObject != other.m_pObject)
    {
        if (self.m_pObject)
            self.m_pObject->DecRefCount();
        self.m_pObject = other.m_pObject;
        if (self.m_pObject)
            self.m_pObject->IncRefCount();
    }
    return self;
}

struct BodyOwnerLocal
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
    virtual void* GetContextOwner();
    int m_f04;
    BodyLocal* body;
    int m_f0c;
    int m_f10;
    ShapePtrLocal<ShapeRefLocal> shape;

    __forceinline ShapeRefLocal* GetShape(BodyLocal* current)
    {
        if (current)
        {
            ShapeLinkLocal** head = &current->shapeHead;
            if (head && *head)
                return (*head)->object;
        }
        return 0;
    }
    __forceinline void SetMass(float mass)
    {
        MotionLocal* motion = body ? body->hkpRigidBody_getStoredDynamicMotion() : 0;
        if (motion)
            motion->SetMass(mass);
        else if (body)
            body->FUN_0090c710(mass);
    }
};

struct CastBodyLocal
{
    int m_f00, m_f04, m_f08, m_f0c;
    BodyOwnerLocal* owner;
};

struct TransformLayout
{
    int m_f00, m_f04, m_f08, m_f0c, m_f10, m_f14, m_f18, m_f1c;
    float source;
    int m_f24, m_f28, m_f2c;
    float target;
};

struct ContextOwnerLocal
{
    int m_f000, m_f004, m_f008, m_f00c;
    int m_f010, m_f014, m_f018, m_f01c;
    int m_f020, m_f024, m_f028, m_f02c;
    int m_f030, m_f034, m_f038, m_f03c;
    int m_f040, m_f044, m_f048, m_f04c;
    int m_f050, m_f054, m_f058, m_f05c;
    int m_f060, m_f064, m_f068, m_f06c;
    int m_f070, m_f074, m_f078, m_f07c;
    int m_f080, m_f084, m_f088, m_f08c;
    int m_f090, m_f094, m_f098, m_f09c;
    int m_f0a0, m_f0a4, m_f0a8, m_f0ac;
    int m_f0b0, m_f0b4, m_f0b8, m_f0bc;
    int m_f0c0, m_f0c4, m_f0c8, m_f0cc;
    int m_f0d0, m_f0d4, m_f0d8, m_f0dc;
    int m_f0e0, m_f0e4, m_f0e8, m_f0ec;
    int m_f0f0, m_f0f4, m_f0f8, m_f0fc;
    int m_f100, m_f104, m_f108, m_f10c;
    int m_f110, m_f114, m_f118, m_f11c;
    int m_f120, m_f124, m_f128, m_f12c;
    int m_f130, m_f134, m_f138, m_f13c;
    int m_f140, m_f144, m_f148, m_f14c;
    int m_f150, m_f154, m_f158, m_f15c;
    int m_f160, m_f164, m_f168, m_f16c;
    int m_f170, m_f174, m_f178, m_f17c;
    int m_f180, m_f184, m_f188, m_f18c;
    int m_f190, m_f194, m_f198, m_f19c;
    int m_f1a0, m_f1a4, m_f1a8, m_f1ac;
    int m_f1b0, m_f1b4, m_f1b8, m_f1bc;
    int m_f1c0, m_f1c4, m_f1c8, m_f1cc;
    int m_f1d0, m_f1d4, m_f1d8, m_f1dc;
    int m_f1e0, m_f1e4, m_f1e8, m_f1ec;
    int m_f1f0, m_f1f4, m_f1f8, m_f1fc;
    int m_f200, m_f204, m_f208, m_f20c;
    int m_f210, m_f214, m_f218, m_f21c;
    int m_f220, m_f224, m_f228, m_f22c;
    int m_f230, m_f234, m_f238, m_f23c;
    int m_f240, m_f244, m_f248, m_f24c;
    int m_f250, m_f254, m_f258, m_f25c;
    int m_f260, m_f264, m_f268, m_f26c;
    int m_f270, m_f274, m_f278, m_f27c;
    int m_f280, m_f284, m_f288, m_f28c;
    int m_f290, m_f294, m_f298, m_f29c;
    int m_f2a0, m_f2a4, m_f2a8, m_f2ac;
    int m_f2b0, m_f2b4, m_f2b8, m_f2bc;
    int m_f2c0, m_f2c4, m_f2c8, m_f2cc;
    int m_f2d0, m_f2d4, m_f2d8, m_f2dc;
    int m_f2e0, m_f2e4, m_f2e8, m_f2ec;
    int m_f2f0, m_f2f4, m_f2f8, m_f2fc;
    int m_f300, m_f304, m_f308, m_f30c;
    int m_iContext310;
};

struct ClonedShapeLocal
{
    virtual ~ClonedShapeLocal();
    unsigned short m_memSizeAndFlags;
    mutable short m_referenceCount;
    __forceinline void removeReference() const
    {
        if (m_memSizeAndFlags != 0)
        {
            --m_referenceCount;
            if (m_referenceCount == 0)
                delete this;
        }
    }
};

struct __declspec(align(16)) AlignedVec4Local
{
    float x, y, z, w;
};

template <class T> struct SimpleArrLocal
{
    void** m_ppVtbl;
    T* pBuffer;
    unsigned int iSize;
    unsigned int uiStorage;
};

template <class T> __forceinline T& GetAtLocal(SimpleArrLocal<T>& a, int index)
{
    return a.pBuffer[index];
}

struct UpdaterLayout
{
    int m_f00, m_f04, m_f08;
    SimpleArrLocal<ShapeBlock18*> shapes;
    SimpleArrLocal<unsigned int> kinds;
    float mass, linearDamping, angularDamping, radius;
    int material;
    __forceinline int GetMaterial() const
    {
        return material;
    }
};

extern "C" ClonedShapeLocal* __cdecl FUN_0097a980(ScaleShapeLocal*, CloneProcessLocal*);
extern "C" CastBodyLocal* __cdecl FUN_00424fe0(void*);
extern "C" void __cdecl FUN_0091b810(float, ScaleShapeLocal*);
extern "C" void __cdecl FUN_0094cda0(float, ScaleShapeLocal*);
void __cdecl FUN_00930d80(float, ScaledShapeLocal*);
void __cdecl FUN_00930d80(float, CapsuleLocal*);
void __cdecl FUN_00930d80(float, ScriptProgramLocal*);

struct FUN_0092c740 : ShapeRefLocal
{
    FUN_0092c740(ShapeBlock18*);
};
struct FUN_0092c650 : ShapeRefLocal
{
    FUN_0092c650(ShapeBlock18*);
};
struct FUN_007c43d0 : ShapeRefLocal
{
    FUN_007c43d0(ShapeBlock18*);
};
struct FUN_008fa290 : ShapeRefLocal
{
    FUN_008fa290(ShapeBlock18*);
};
struct FUN_0092c7c0 : ShapeRefLocal
{
    FUN_0092c7c0(ShapeBlock18*);
};
struct FUN_0092c6a0 : MaterialShapeLocal
{
    FUN_0092c6a0(int, int, float);
};

} // namespace fn_0092ce00

// pdb: bhkRagdollTemplateData::ReplaceRagdollData | bhkRagdollTemplate.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObj, afScale
void ShapeUpdater::FUN_00cba6f0(SceneObject* object, float scale)
{
    using namespace fn_0092ce00;
    UpdaterLayout* self = reinterpret_cast<UpdaterLayout*>(this);
    CastBodyLocal* cast = FUN_00424fe0(object);
    if (!cast)
        return;
    BodyOwnerLocal* owner = cast->owner;
    if (!owner)
        return;
    BodyLocal* body = owner->body;
    if (!body)
        return;
    owner->SetMass(self->mass);
    BodyLocal* current = owner->body;
    {
        float value = self->angularDamping;
        float* friction = &current->friction;
        *friction = value;
    }
    {
        float value = self->linearDamping;
        float* restitution = &current->restitution;
        *restitution = value;
    }
    MaterialShapeLocal* old = (MaterialShapeLocal*)owner->GetShape(current);
    old->material = self->GetMaterial();
    AlignedVec4Local vertex0 =
        old->data ? *(const AlignedVec4Local*)&((TransformLayout*)old->data)->source
                  : *(const AlignedVec4Local*)&g_zeroVec_0092ce00;
    AlignedVec4Local vertex1 =
        old->data ? *(const AlignedVec4Local*)&((TransformLayout*)old->data)->target
                  : *(const AlignedVec4Local*)&g_zeroVec_0092ce00;
    FUN_0092c6a0* replacement = new FUN_0092c6a0(
        int(old->data ? &((TransformLayout*)old->data)->source : &g_zeroVec_0092ce00),
        int(old->data ? &((TransformLayout*)old->data)->target : &g_zeroVec_0092ce00),
        self->radius * scale);
    replacement->IncRefCount();
    replacement->material = self->GetMaterial();
    ScaleShapeLocal* scaledData = replacement->data;
    body->SetShape(scaledData);
    old->DecRefCount();
    for (unsigned int i = 0; i < self->shapes.iSize; ++i)
    {
        ShapeRefLocal* shape = owner->shape;
        if (shape)
        {
            char viewFlag;
            ShapeViewLocal* view = static_cast<ShapeViewLocal*>(shape->GetView(&viewFlag));
            ContextOwnerLocal* contextOwner = shape->GetContextOwner();
            void* context = contextOwner ? (void*)contextOwner->m_iContext310 : 0;
            ShapeBlock18* source = (ShapeBlock18*)view;
            GetAtLocal(self->shapes, i)->SetC(source->m_f0c);
            GetAtLocal(self->shapes, i)->SetD(source->m_f10);
            ShapeRefLocal* result = 0;
            CloneProcessLocal clone(0x101);
            switch (GetAtLocal(self->kinds, i))
            {
            case 13:
                FUN_0091b810(scale, GetAtLocal(self->shapes, i)->GetShape());
                result = new FUN_0092c740(GetAtLocal(self->shapes, i));
                if (scale != 0.0f)
                {
                    ClonedShapeLocal* copy = FUN_0097a980(GetAtLocal(self->shapes, i)->GetShape(), &clone);
                    if (copy)
                    {
                        GetAtLocal(self->shapes, i)->FUN_008fbbb0((ScaleShapeLocal*)copy);
                        copy->removeReference();
                    }
                }
                FUN_0091b810(1.0f / scale, GetAtLocal(self->shapes, i)->GetShape());
                break;
            case 0:
                FUN_0094cda0(scale, GetAtLocal(self->shapes, i)->GetShape());
                result = new FUN_0092c650(GetAtLocal(self->shapes, i));
                if (scale != 0.0f)
                {
                    ClonedShapeLocal* copy = FUN_0097a980(GetAtLocal(self->shapes, i)->GetShape(), &clone);
                    if (copy)
                    {
                        GetAtLocal(self->shapes, i)->FUN_008fbbb0((ScaleShapeLocal*)copy);
                        copy->removeReference();
                    }
                }
                FUN_0094cda0(1.0f / scale, GetAtLocal(self->shapes, i)->GetShape());
                break;
            case 1:
                FUN_00930d80(scale, (ScaledShapeLocal*)GetAtLocal(self->shapes, i)->GetShape());
                result = new FUN_007c43d0(GetAtLocal(self->shapes, i));
                if (scale != 0.0f)
                {
                    ClonedShapeLocal* copy = FUN_0097a980(GetAtLocal(self->shapes, i)->GetShape(), &clone);
                    if (copy)
                    {
                        GetAtLocal(self->shapes, i)->FUN_008fbbb0((ScaleShapeLocal*)copy);
                        copy->removeReference();
                    }
                }
                FUN_00930d80(1.0f / scale, (ScaledShapeLocal*)GetAtLocal(self->shapes, i)->GetShape());
                break;
            case 2:
                FUN_00930d80(scale, (CapsuleLocal*)GetAtLocal(self->shapes, i)->GetShape());
                result = new FUN_008fa290(GetAtLocal(self->shapes, i));
                if (scale != 0.0f)
                {
                    ClonedShapeLocal* copy = FUN_0097a980(GetAtLocal(self->shapes, i)->GetShape(), &clone);
                    if (copy)
                    {
                        GetAtLocal(self->shapes, i)->FUN_008fbbb0((ScaleShapeLocal*)copy);
                        copy->removeReference();
                    }
                }
                FUN_00930d80(1.0f / scale, (CapsuleLocal*)GetAtLocal(self->shapes, i)->GetShape());
                break;
            case 7:
                FUN_00930d80(scale, (ScriptProgramLocal*)GetAtLocal(self->shapes, i)->GetShape());
                result = new FUN_0092c7c0(GetAtLocal(self->shapes, i));
                if (scale != 0.0f)
                {
                    ClonedShapeLocal* copy = FUN_0097a980(GetAtLocal(self->shapes, i)->GetShape(), &clone);
                    if (copy)
                    {
                        GetAtLocal(self->shapes, i)->FUN_008fbbb0((ScaleShapeLocal*)copy);
                        copy->removeReference();
                    }
                }
                FUN_00930d80(1.0f / scale, (ScriptProgramLocal*)GetAtLocal(self->shapes, i)->GetShape());
                break;
            }
            {
                ShapePtrLocal<ShapeRefLocal> ref(result);
                if (ref)
                    AssignShapePtr(owner->shape, ref);
            }
            result->SetContext(context);
        }
    }
}


namespace quaternion_simd {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    } lanes;
};
extern "C"
{
    quaternion_simd::__m128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, quaternion_simd::__m128);
    quaternion_simd::__m128 _mm_mul_ps(quaternion_simd::__m128, quaternion_simd::__m128);
    quaternion_simd::__m128 _mm_mul_ss(quaternion_simd::__m128, quaternion_simd::__m128);
    quaternion_simd::__m128 _mm_add_ss(quaternion_simd::__m128, quaternion_simd::__m128);
    quaternion_simd::__m128 _mm_xor_ps(quaternion_simd::__m128, quaternion_simd::__m128);
    quaternion_simd::__m128 _mm_shuffle_ps(quaternion_simd::__m128, quaternion_simd::__m128, int);
    quaternion_simd::__m128 _mm_sub_ps(quaternion_simd::__m128, quaternion_simd::__m128);
    quaternion_simd::__m128 _mm_add_ps(quaternion_simd::__m128, quaternion_simd::__m128);
    quaternion_simd::__m128 _mm_unpackhi_ps(quaternion_simd::__m128, quaternion_simd::__m128);
}
}

extern unsigned int DAT_010c4c00;

struct FNV_ALIGN(16) VectorComponentValue
{
    float realX, realY, realZ, realW;
    quaternion_simd::__m128 getRealQuad() const
    {
        return *(const quaternion_simd::__m128*)this;
    }
    VectorComponentValue(quaternion_simd::__m128 q)
    {
        *(quaternion_simd::__m128*)this = q;
    }
    VectorComponentValue(const float& f)
    {
        *(quaternion_simd::__m128*)this = quaternion_simd::_mm_load_ss(&f);
    }
    operator float() const
    {
        float f;
        quaternion_simd::_mm_store_ss(&f, getRealQuad());
        return f;
    }
};
inline VectorComponentValue operator*(const VectorComponentValue& a, const VectorComponentValue& b)
{
    return VectorComponentValue(quaternion_simd::_mm_mul_ss(a.getRealQuad(), b.getRealQuad()));
}
struct FNV_ALIGN(16) hkVector4
{
    float x, y, z, w;
    quaternion_simd::__m128 getQuad() const
    {
        return *(quaternion_simd::__m128*)this;
    }
    void setQuad(quaternion_simd::__m128 q)
    {
        *(quaternion_simd::__m128*)this = q;
    }
    VectorComponentValue dot3(const hkVector4& a) const
    {
        quaternion_simd::__m128 mul = quaternion_simd::_mm_mul_ps(getQuad(), a.getQuad());
        quaternion_simd::__m128 shuf1 = quaternion_simd::_mm_shuffle_ps(mul, mul, 0x55);
        quaternion_simd::__m128 add1 = quaternion_simd::_mm_add_ss(shuf1, mul);
        quaternion_simd::__m128 shuf2 = quaternion_simd::_mm_shuffle_ps(mul, mul, 0xaa);
        return quaternion_simd::_mm_add_ss(shuf2, add1);
    }
};

struct FNV_ALIGN(16) hkQuaternion
{
    hkVector4 m_vec;
    hkQuaternion& operator=(const hkQuaternion& other)
    {
        m_vec.setQuad(other.m_vec.getQuad());
        return *this;
    }
    void FUN_00cb2a50(const hkVector4& axis);
    void FUN_00c66320(const hkQuaternion& q1, const hkQuaternion& q2);
    float GetAngle();
    void SetConjugate(const hkQuaternion& q)
    {
        m_vec.setQuad(quaternion_simd::_mm_xor_ps(q.m_vec.getQuad(), *(quaternion_simd::__m128*)&DAT_010c4c00));
    }
    void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1)
    {
        hkQuaternion inv0;
        inv0.SetConjugate(q0);
        FUN_00c66320(inv0, q1);
    }
    float getReal() const
    {
        return m_vec.w;
    }
    const hkVector4& getImag() const
    {
        return m_vec;
    }
    void FUN_00cb2ca0(const hkVector4& axis, hkQuaternion& restOut, float& angleOut) const;
};

__declspec(noinline) void copyQuaternionVector(hkVector4* out, const hkVector4* in)
{
    out->setQuad(in->getQuad());
}
__declspec(noinline) void hkQuaternion::FUN_00c66320(const hkQuaternion& a, const hkQuaternion& b)
{
    quaternion_simd::__m128 u = a.m_vec.getQuad(), v = b.m_vec.getQuad();
    quaternion_simd::__m128 cross =
        quaternion_simd::_mm_sub_ps(quaternion_simd::_mm_mul_ps(quaternion_simd::_mm_shuffle_ps(u, u, 0xc9),
                                                                quaternion_simd::_mm_shuffle_ps(v, v, 0xd2)),
                                    quaternion_simd::_mm_mul_ps(quaternion_simd::_mm_shuffle_ps(u, u, 0xd2),
                                                                quaternion_simd::_mm_shuffle_ps(v, v, 0xc9)));
    quaternion_simd::__m128 uw = quaternion_simd::_mm_shuffle_ps(u, u, 0xff),
                            vw = quaternion_simd::_mm_shuffle_ps(v, v, 0xff);
    quaternion_simd::__m128 xyz = quaternion_simd::_mm_add_ps(quaternion_simd::_mm_mul_ps(uw, v), cross);
    xyz = quaternion_simd::_mm_add_ps(quaternion_simd::_mm_mul_ps(vw, u), xyz);
    quaternion_simd::__m128 product = quaternion_simd::_mm_mul_ps(u, v);
    quaternion_simd::__m128 yz =
        quaternion_simd::_mm_add_ss(quaternion_simd::_mm_shuffle_ps(product, product, 0x55), product);
    quaternion_simd::__m128 dot =
        quaternion_simd::_mm_add_ss(quaternion_simd::_mm_shuffle_ps(product, product, 0xaa), yz);
    dot = quaternion_simd::_mm_shuffle_ps(dot, dot, 0);
    quaternion_simd::__m128 real = quaternion_simd::_mm_sub_ps(product, dot);
    hkVector4 result;
    result.setQuad(quaternion_simd::_mm_shuffle_ps(xyz, quaternion_simd::_mm_unpackhi_ps(xyz, real), 0xc4));
    copyQuaternionVector(&m_vec, &result);
}

// @f3 0x00924a70 (community match, verified in this file)
void hkQuaternion::FUN_00cb2ca0(const hkVector4& axis, hkQuaternion& restOut, float& angleOut) const
{
    restOut.m_vec.x = m_vec.x;
    restOut.m_vec.y = m_vec.y;
    restOut.m_vec.z = m_vec.z;
    restOut.m_vec.w = m_vec.w;
    restOut.FUN_00cb2a50(axis);
    hkQuaternion conj;
    conj.m_vec.x = -restOut.m_vec.x;
    conj.m_vec.y = -restOut.m_vec.y;
    conj.m_vec.z = -restOut.m_vec.z;
    conj.m_vec.w = restOut.m_vec.w;
    hkQuaternion r;
    r.FUN_00c66320(conj, *this);
    float angle = r.GetAngle();
    angleOut = angle;
    float dot = axis.y * r.m_vec.y + axis.x * r.m_vec.x + axis.z * r.m_vec.z;
    if (dot * r.m_vec.w < 0.0)
        angleOut = -angle;
}


#include <xmmintrin.h>
namespace fnv_00cb94a0 {
#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier();
extern float DAT_011b1d3c;
extern float DAT_01015f5c;
extern void* DAT_010c8a2c;
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012683f4;
extern GlobalObjectO2_00a7b610 g_012043f8;
extern void __fastcall FUN_00a6d220(void* p);
struct ChildInner
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
    float unk194;
};
struct ChildObj
{
    int unk00;
    int unk04;
    ChildInner* unk08;
};
struct DynCastHelper
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ChildObj* unk10;
    DynCastHelper* FUN_00653290(const GlobalObjectO2_00a7b610* type);
};
struct MyRTTI;
class bhkForceController;
struct MyHost
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DynCastHelper* unk1c;
    bhkForceController* FUN_00a5c570(const MyRTTI* rtti) const;
};
class NiTimeController
{
  public:
    virtual ~NiTimeController();
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
    virtual void V35(float);
    virtual void V36();
    virtual void V37();
    virtual void V38(MyHost*);
    virtual void V39();
    virtual void V40();
    virtual float V41(float);
    long refs04;
    unsigned short unk08, unk0a;
    float unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    MyHost* target2c;
    NiTimeController* next30;
    NiTimeController();
};
class bhkForceController : public NiTimeController
{
  public:
    __m128 unk40;
    float unk50;
    static void operator delete(void*);
    static void* operator new(unsigned int size)
    {
        unsigned char* raw = (unsigned char*)((Pool_ca57*)&DAT_011f6238)->FUN_00aa3e40(size + 16);
        unsigned char lo = (unsigned char)raw;
        unsigned char pad = 16 - (lo & 15);
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
    bhkForceController() : unk40(*(__m128*)&DAT_01267e30), unk50(0.0f)
    {}
    __forceinline void Configure(float duration)
    {
        unk14 = 0.0f;
        unsigned short flags = unk08;
        unk18 = duration;
        flags = (flags & 0xFFF5) | 5;
        unk10 = 0.0f;
        *(volatile unsigned short*)&unk08 = flags;
        unk0c = 1.0f;
    }
};
}  // namespace fnv_00cb94a0

// @f3 0x00931b40 (community match, verified in this file)
namespace f3m_00931b40 {
struct S00931b40_Owner;

struct S00931b40_Target
{
    void FUN_008d5730(S00931b40_Owner* pkOwner, void* pkData);
};

void* FUN_00921850(int a, int b, int c, int d);

struct S00931b40_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    bool m_bDisabled;

    bool FUN_008f9b20(S00931b40_Target* pkTarget);
    bool FUN_00931b40(S00931b40_Target* pkTarget);
};

// pdb: bhkCollisionBox::Add | bhkCollisionBox.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apWorld
bool S00931b40_Owner::FUN_00931b40(S00931b40_Target* pkTarget)
{
    bool bResult = false;
    if (!m_bDisabled)
    {
        bResult = FUN_008f9b20(pkTarget);
        if (bResult)
            pkTarget->FUN_008d5730(this, FUN_00921850(0x1e, 0x82, 0, 0x14));
    }
    return bResult;
}
}   // namespace f3m_00931b40

// @f3 0x00931b80 (community match, verified in this file)
#include <string.h>
// --- stand-ins for FUN_00931b80 (0x00931b80, 277 bytes) ---

struct Col3
{
    float fR;
    float fG;
    float fB;
};

struct __declspec(align(16)) Col529
{
    float fR;
    float fG;
    float fB;
};

struct __declspec(align(16)) ColA529
{
    float fR;
    float fG;
    float fB;
    float fA;
};

struct Dest529
{
    int m_aui00;
    int m_aui04;
    int m_aui08;
    int m_aui0c;
    float m_fAlpha10;
};

struct Elem16529
{
    Dest529* m_pObj;
    int m_aui04;
    int m_aui08;
    int m_aui0c;
};

struct Src20529
{
    int m_aui00;
    int m_aui04;
    int m_aui08;
    int m_aui0c;
    int m_aui10;
    int m_aui14;
    int m_aui18;
    int m_aui1c;
    ColA529* m_pColor20;
};

struct Holder424529
{
    Src20529* FUN_008f9c90(int);
};

struct Fwd08529
{
    Col529* FUN_0091dd60();
};

struct Node18529
{
    int m_aui000;
    int m_aui004;
    Fwd08529* m_p08;
    int m_aui00c;
    int m_aui010;
    int m_aui014;
    int m_aui018;
    int m_aui01c;
    int m_aui020;
    int m_aui024;
    int m_aui028;
    int m_aui02c;
    int m_aui030;
    int m_aui034;
    int m_aui038;
    int m_aui03c;
    int m_aui040;
    int m_aui044;
    int m_aui048;
    int m_aui04c;
    int m_aui050;
    int m_aui054;
    int m_aui058;
    int m_aui05c;
    int m_aui060;
    int m_aui064;
    int m_aui068;
    int m_aui06c;
    int m_aui070;
    int m_aui074;
    int m_aui078;
    int m_aui07c;
    int m_aui080;
    int m_aui084;
    int m_aui088;
    int m_aui08c;
    int m_aui090;
    int m_aui094;
    int m_aui098;
    int m_aui09c;
    int m_aui0a0;
    int m_aui0a4;
    int m_aui0a8;
    int m_aui0ac;
    int m_aui0b0;
    int m_aui0b4;
    int m_aui0b8;
    int m_aui0bc;
    int m_aui0c0;
    int m_aui0c4;
    int m_aui0c8;
    int m_aui0cc;
    int m_aui0d0;
    int m_aui0d4;
    int m_aui0d8;
    int m_aui0dc;
    int m_aui0e0;
    int m_aui0e4;
    int m_aui0e8;
    int m_aui0ec;
    int m_aui0f0;
    int m_aui0f4;
    int m_aui0f8;
    int m_aui0fc;
    int m_aui100;
    int m_aui104;
    int m_aui108;
    int m_aui10c;
    int m_aui110;
    int m_aui114;
    int m_aui118;
    int m_aui11c;
    int m_aui120;
    int m_aui124;
    int m_aui128;
    int m_aui12c;
    int m_aui130;
    int m_aui134;
    int m_aui138;
    int m_aui13c;
    int m_aui140;
    int m_aui144;
    int m_aui148;
    int m_aui14c;
    int m_aui150;
    int m_aui154;
    int m_aui158;
    int m_aui15c;
    int m_aui160;
    int m_aui164;
    int m_aui168;
    int m_aui16c;
    int m_aui170;
    int m_aui174;
    int m_aui178;
    int m_aui17c;
    int m_aui180;
    int m_aui184;
    int m_aui188;
    int m_aui18c;
    int m_aui190;
    int m_aui194;
    int m_aui198;
    int m_aui19c;
    int m_aui1a0;
    int m_aui1a4;
    int m_aui1a8;
    int m_aui1ac;
    int m_aui1b0;
    int m_aui1b4;
    int m_aui1b8;
    int m_aui1bc;
    int m_aui1c0;
    int m_aui1c4;
    int m_aui1c8;
    int m_aui1cc;
    int m_aui1d0;
    int m_aui1d4;
    int m_aui1d8;
    int m_aui1dc;
    int m_aui1e0;
    int m_aui1e4;
    int m_aui1e8;
    int m_aui1ec;
    int m_aui1f0;
    int m_aui1f4;
    int m_aui1f8;
    int m_aui1fc;
    int m_aui200;
    int m_aui204;
    int m_aui208;
    int m_aui20c;
    int m_aui210;
    int m_aui214;
    int m_aui218;
    int m_aui21c;
    int m_aui220;
    int m_aui224;
    int m_aui228;
    int m_aui22c;
    int m_aui230;
    int m_aui234;
    int m_aui238;
    int m_aui23c;
    int m_aui240;
    int m_aui244;
    int m_aui248;
    int m_aui24c;
    int m_aui250;
    int m_aui254;
    int m_aui258;
    int m_aui25c;
    int m_aui260;
    int m_aui264;
    int m_aui268;
    int m_aui26c;
    int m_aui270;
    int m_aui274;
    int m_aui278;
    int m_aui27c;
    int m_aui280;
    int m_aui284;
    int m_aui288;
    int m_aui28c;
    int m_aui290;
    int m_aui294;
    int m_aui298;
    int m_aui29c;
    int m_aui2a0;
    int m_aui2a4;
    int m_aui2a8;
    int m_aui2ac;
    int m_aui2b0;
    int m_aui2b4;
    int m_aui2b8;
    int m_aui2bc;
    int m_aui2c0;
    int m_aui2c4;
    int m_aui2c8;
    int m_aui2cc;
    int m_aui2d0;
    int m_aui2d4;
    int m_aui2d8;
    int m_aui2dc;
    int m_aui2e0;
    int m_aui2e4;
    int m_aui2e8;
    int m_aui2ec;
    int m_aui2f0;
    int m_aui2f4;
    int m_aui2f8;
    int m_aui2fc;
    int m_aui300;
    int m_aui304;
    int m_aui308;
    int m_aui30c;
    int m_aui310;
    int m_aui314;
    int m_aui318;
    int m_aui31c;
    int m_aui320;
    int m_aui324;
    int m_aui328;
    int m_aui32c;
    int m_aui330;
    int m_aui334;
    int m_aui338;
    int m_aui33c;
    int m_aui340;
    int m_aui344;
    int m_aui348;
    int m_aui34c;
    int m_aui350;
    int m_aui354;
    int m_aui358;
    int m_aui35c;
    int m_aui360;
    int m_aui364;
    int m_aui368;
    int m_aui36c;
    int m_aui370;
    int m_aui374;
    int m_aui378;
    int m_aui37c;
    int m_aui380;
    int m_aui384;
    int m_aui388;
    int m_aui38c;
    int m_aui390;
    int m_aui394;
    int m_aui398;
    int m_aui39c;
    int m_aui3a0;
    int m_aui3a4;
    int m_aui3a8;
    int m_aui3ac;
    int m_aui3b0;
    int m_aui3b4;
    int m_aui3b8;
    int m_aui3bc;
    int m_aui3c0;
    int m_aui3c4;
    int m_aui3c8;
    int m_aui3cc;
    int m_aui3d0;
    int m_aui3d4;
    int m_aui3d8;
    int m_aui3dc;
    int m_aui3e0;
    int m_aui3e4;
    int m_aui3e8;
    int m_aui3ec;
    int m_aui3f0;
    int m_aui3f4;
    int m_aui3f8;
    int m_aui3fc;
    int m_aui400;
    int m_aui404;
    int m_aui408;
    int m_aui40c;
    int m_aui410;
    int m_aui414;
    int m_aui418;
    int m_aui41c;
    int m_aui420;
    Holder424529* m_pHolder424;
};

struct This529
{
    int m_aui00;
    int m_aui04;
    Elem16529* m_pElem08;
    int m_aui0c;
    int m_aui10;
    int m_aui14;
    Node18529* m_pNode18;
    void FUN_00569b80(Col529* pColor);
    void FUN_00931b80();
};

// pdb: bhkCollisionBox::Update | bhkCollisionBox.obj | fnv360_0822_retail, caller_sim, low
void This529::FUN_00931b80()
{
    extern unsigned char DAT_010f342c;
    extern ColA529 DAT_0108edc8;
    extern Col529 DAT_01092a50;
    extern double DAT_00db88e8;
    extern double DAT_00dbe7c0;

    if (DAT_010f342c != 0)
        return;

    Node18529* pNode = m_pNode18;
    if (pNode == 0)
        return;

    Col529 kColor;
    float fAlpha;
    Holder424529* pHolder = pNode->m_pHolder424;
    Src20529* pSrc = 0;
    if (pHolder != 0 && (pSrc = pHolder->FUN_008f9c90(0)) != 0)
    {
        ColA529* __restrict pColA = pSrc->m_pColor20;
        if (pColA == 0)
            pColA = &DAT_0108edc8;
        ColA529 kTmpA = *pColA;
        memcpy(&kColor, &kTmpA, sizeof(Col3));
        fAlpha = kTmpA.fA;
    }
    else
    {
        Node18529* pNode2 = m_pNode18;
        Col529* pCol;
        if (pNode2 != 0 && pNode2->m_p08 != 0)
            pCol = pNode2->m_p08->FUN_0091dd60();
        else
            pCol = &DAT_01092a50;
        ColA529 kTmpB;
        kColor.fR = pCol->fR;
        kColor.fG = pCol->fG;
        kColor.fB = pCol->fB;
        kTmpB.fR = kColor.fR * DAT_00db88e8;
        kTmpB.fG = kColor.fG * DAT_00db88e8;
        kTmpB.fB = kColor.fB * DAT_00db88e8;
        memcpy(&kColor, &kTmpB, sizeof(Col3));
        fAlpha = 1.0f;
    }

    Elem16529* pElem = m_pElem08 ? m_pElem08 + 1 : 0;
    Dest529* pDest = pElem ? pElem->m_pObj : 0;

    if (!(fAlpha > 0.0f))
        fAlpha = 1.0f;

    pDest->m_fAlpha10 = fAlpha * DAT_00dbe7c0;

    FUN_00569b80(&kColor);
}
