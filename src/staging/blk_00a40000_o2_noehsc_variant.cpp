#include "f3_common.h"
// src/staging/blk_00a40000_o2_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/staging/blk_00a40000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00a40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern "C" void __fastcall FUN_00a36890(void*);
void __fastcall FUN_00a36890(void*);
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
void __fastcall FUN_00a36890(void*);
struct NiObject
{
    void CopyMembersStream(unsigned int, void*);
};
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
void __cdecl _delete(void*, unsigned int);
extern "C" void NiFree(void*);
extern MemoryManager g_memoryManager;
void __cdecl NiFree(void*);
void __cdecl FUN_00a57500(NiFixedString*);
void __cdecl FUN_00a76960(void*, void*);
struct NiFixedString
{
    const char* m_kHandle;
};
void __cdecl FUN_00a57500(NiFixedString* k);
struct A51BF0Base
{
    static void* operator new(unsigned int);
};
struct CRITICAL_SECTION_STUB
{
    int a;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION_STUB*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION_STUB*);
struct S_00a42290_Mem
{
    static void* operator new(unsigned int);
};
struct FUN_00a5d3a0 : S_00a42290_Mem
{
    int unk04;
    FUN_00a5d3a0() throw();
    virtual ~FUN_00a5d3a0() throw();
};
struct S_00a42290_Q : FUN_00a5d3a0
{
    int unk08;
    int unk0c;
    int unk10;
    bool unk14;
    S_00a42290_Q() throw() : unk08(0), unk0c(0), unk10(0), unk14(false)
    {}
    virtual ~S_00a42290_Q() throw()
    {}
    void NiFloatData_SetAnim(void* a, unsigned int b, int c);
};
class A42380RefObject
{
  public:
    virtual ~A42380RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};
struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};
struct StubNiObject
{
    virtual void Slot00();
    virtual void Slot01();
    virtual const NiRTTI* GetRTTI() const;
    virtual void* IsSceneNode();
};
struct StubController : StubNiObject
{
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
    StubController* m_pkNext;
};
struct StubAVObject;
struct StubChildArray
{
    void* m_pVTable;
    StubAVObject** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};
struct StubAVObject : StubNiObject
{
    int unk04;
    int unk08;
    StubController* m_pControllers;
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
    StubChildArray m_kChildList;
};
static inline bool IsKindOfRTTI(const NiRTTI* pkTarget, const StubNiObject* pkObj)
{
    for (const NiRTTI* r = pkObj->GetRTTI(); r; r = r->m_pBaseRTTI)
        if (r == pkTarget)
            return true;
    return false;
}
void __cdecl ConvertLegacyController(StubController* p);
void __cdecl FUN_00a42b70(void* pArg, StubAVObject* pkObject);
void __cdecl FUN_00a42b70(void* a1, void* a2);
extern "C" void _NiFreeAlias(void*);
extern "C" void __cdecl ReleaseObjectArray(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefItem
{
    virtual void unused() throw();
    virtual void Release() throw();
    volatile long count;
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&count))
            Release();
    }
};
struct SP
{
    RefItem* value;
    ~SP() throw()
    {
        if (value)
            value->DecRefCount();
    }
    SP& operator=(RefItem* p) throw()
    {
        if (value)
        {
            value->DecRefCount();
            value = 0;
        }
        return *this;
    }
};
struct RawArray
{
    virtual ~RawArray() throw()
    {
        _NiFreeAlias(data);
    }
    void** data;
    unsigned short maxSize, size, used, grow;
    void* RemoveAt(unsigned i) throw()
    {
        if (i >= size)
            return 0;
        void* p = data[i];
        data[i] = 0;
        if (p)
            --used;
        if (i == (unsigned short)(size - 1))
            --size;
        return p;
    }
};
struct RefArray
{
    virtual ~RefArray() throw()
    {
        ReleaseObjectArray(data);
    }
    SP* data;
    unsigned short maxSize, size, used, grow;
    SP FUN_00a47540(unsigned) throw();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefObject
{
    virtual void GetRTTI();
    virtual void DeleteThis();
    volatile long referenceCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            DeleteThis();
    }
};
struct RefPointer
{
    RefObject* object;
    void Clear()
    {
        if (object)
        {
            object->DecRefCount();
            object = 0;
        }
    }
    void Release()
    {
        if (object)
            object->DecRefCount();
    }
};
void __cdecl FUN_00aa10f0(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class NiRefObject572
{
  public:
    virtual ~NiRefObject572() throw();
    virtual void DeleteThis() throw();

    void DecRefCount() throw()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointer572
{
  public:
    ~NiPointer572() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};
extern const char* g_pcNullString572;
class NiFixedString572
{
  public:
    ~NiFixedString572() throw()
    {
        if (m_kHandle != g_pcNullString572)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }

    const char* m_kHandle;
};
extern void __cdecl FUN_00aa10f0(char* psz);
struct Ent
{
    void* m_f0;
    char* m_str;
    int m_unk8;
    int m_unkC;
};
inline char* GetStr(Ent* e)
{
    return e->m_str;
}
struct CSImpl
{
    void* m_iFourthElementInteger[6];
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CSImpl* pcs);
__declspec(dllimport) void __stdcall InitializeCriticalSection(void* pkSection);
extern int g_iA5B530Default;
struct A5B530Entry
{
    int* m_piSource;
    int m_iValue;
    short m_sA;
    short m_sB;
    short m_sC;
    short m_sCount;

    A5B530Entry()
    {
        m_sA = 0;
        m_sCount = 1;
        m_sB = 0;
        m_sC = 0;
        m_iValue = 0;
        m_piSource = &g_iA5B530Default;
    }
};
class A5B660Heap
{
  public:
    void Deallocate(void* pvMem);
};
class A5B660StringTable
{
  public:
    ~A5B660StringTable();

    static void operator delete(void* pvMem)
    {
        reinterpret_cast<A5B660Heap&>(g_memoryManager).Deallocate(pvMem);
    }

    static A5B660StringTable* ms_pStringTable;

    static void FUN_00a5b660();
};
// NiRefObject
extern void* __cdecl FUN_00aa13e0(unsigned int);
// Constructor of a derived object: base ctor call, then a 16-bit field and the vtable pointer.
extern int DAT_0109b220;
// Destructor of an owning pointer array: remove and free every element, then the base frees the storage.
class A1450MemoryManager
{
  public:
    void Deallocate(void* pvMem) throw();
};
extern A1450MemoryManager g_kA1450MemoryManager;
void __cdecl A1450NiFree(void* pvMem);
struct A1450Element
{
    int unk00;

    static void operator delete(void* pvMem)
    {
        g_kA1450MemoryManager.Deallocate(pvMem);
    }
};
class A1450Array
{
  public:
    virtual ~A1450Array()
    {
        A1450NiFree(m_pBase);
    }

    A1450Element* RemoveEnd()
    {
        if (m_usSize == 0)
            return 0;
        m_usSize--;
        A1450Element* pkElement = m_pBase[m_usSize];
        m_pBase[m_usSize] = 0;
        if (pkElement)
            m_usESize--;
        return pkElement;
    }

    A1450Element** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ConvertedController;
struct ControllerInterpolator;
struct ControllerHost
{
    ConvertedController* FUN_00a5c570(const NiRTTI*);
    void FUN_00a5c000(ConvertedController*);
    void FUN_00a5c480(StubController*);
};
struct ControllerFields
{
    virtual void Slot00();
    virtual void DeleteThis() throw();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void SetTarget(ControllerHost*);
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Update();
    virtual void Slot48();
    virtual void* GetInterpolator(unsigned int);
    virtual void SetInterpolator(ControllerInterpolator*, unsigned int);
    unsigned int refCount;
    int unk08;
    unsigned short flags;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    float startTime;
    float stopTime;
    void IncRefCount() throw()
    {
        InterlockedIncrement((volatile long*)&refCount);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement((volatile long*)&refCount))
            DeleteThis();
    }
};
struct ConvertedController : ControllerFields
{
    NiPointer<ConvertedController> next;
    ConvertedController* FUN_00a36560();
};
struct ControllerInterpolator : ControllerFields
{
    unsigned short cycle;
    unsigned short unk32;
    int unk34;
    int data;
    ControllerInterpolator* FUN_00a3f060(void*, void*);
    void UpdateIfFlagged();
    void SetFlag1(bool value)
    {
        if (value)
            flags |= 2;
        else
            flags &= (unsigned short)~2;
    }
    void SetFlag2(bool value)
    {
        if (value)
            flags |= 4;
        else
            flags &= (unsigned short)~4;
    }
    void SetFlag3(bool value)
    {
        if (value)
            flags |= 8;
        else
            flags &= (unsigned short)~8;
    }
    void SetFlag5(bool value)
    {
        if (value)
            flags |= 32;
        else
            flags &= (unsigned short)~32;
    }
    void SetFlag6(bool value)
    {
        if (value)
            flags |= 64;
        else
            flags &= (unsigned short)~64;
    }
    void SetFlag4(bool value)
    {
        if (value)
            flags |= 16;
        else
            flags &= (unsigned short)~16;
        if (value)
            UpdateIfFlagged();
    }
};
struct LegacyController : StubController
{
    unsigned short flags;
    unsigned short unk36;
    int unk38;
    int unk3c;
    void* firstData;
    void* secondData;
    int unk48;
    int unk4c;
    float startTime;
    float stopTime;
    unsigned short cycle;
    unsigned short unk5a;
    int unk5c;
    int data;
    bool Flag1() const
    {
        return (flags >> 1) & 1;
    }
    bool Flag2() const
    {
        return (flags >> 2) & 1;
    }
    bool Flag3() const
    {
        return (flags >> 3) & 1;
    }
    bool Flag4() const
    {
        return (flags >> 4) & 1;
    }
    bool Flag5() const
    {
        return (flags >> 5) & 1;
    }
    bool Flag6() const
    {
        return (flags >> 6) & 1;
    }
};
void __cdecl ConvertLegacyController(StubController* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RTT
{
    const char* name;
    const RTT* base;
};
extern RTT g_011f3f38, g_011f3f28, g_011f4a38, g_011f36ec;
struct Obj
{
    virtual void slot0() throw();
    virtual void DeleteThis() throw();
    virtual const RTT* GetType() const throw();
    volatile long refs;
    const char* name;
    Obj* controller;
    Obj** extras;
    unsigned short count;
    unsigned short capacity;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Obj* next;
    Obj* Cast(const RTT*) throw();
    bool FUN_00a5bf50(unsigned short) throw();
    void NiObjectNET_RemoveAllExtraData() throw();
    void Inc() throw()
    {
        InterlockedIncrement(&refs);
    }
    void Dec() throw()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
inline bool IsKind(const RTT* type, const Obj* object) throw()
{
    for (const RTT* r = object->GetType(); r; r = r->base)
        if (r == type)
            return true;
    return false;
}
inline Obj* CastInline(const RTT* type, Obj* object) throw()
{
    if (!object)
        return 0;
    return (int)IsKind(type, object) ? object : 0;
}
struct Ptr
{
    Obj* p;
    Ptr(Obj* q) throw() : p(q)
    {
        if (p)
            p->Inc();
    }
    ~Ptr() throw()
    {
        if (p)
            p->Dec();
    }
    void operator=(Obj* q) throw()
    {
        if (p != q)
        {
            if (p)
                p->Dec();
            p = q;
            if (p)
                p->Inc();
        }
    }
};
struct Result
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
    static void* operator new(unsigned int) throw();
    Result(const char*, int, int) throw();
    void FUN_00a47420(Obj*) throw();
    void AddSeq(void*, Obj*) throw();
};
struct Stream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    Obj** objects;
    unsigned int unk224;
    unsigned int size;
};
Result* __cdecl CreateResultFromStreamObject(Stream* stream, unsigned int index, const char* name);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiGPUProgram
{
  public:
    virtual void f0() throw();
    virtual void DeleteThis() throw();
    volatile long refs;
    void SetString(void*) throw();
    void IncRefCount() throw()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
template <> class NiPointer<NiGPUProgram>
{
  public:
    NiGPUProgram* ptr;
    NiPointer() : ptr(0)
    {}
    bool operator==(NiGPUProgram* other) const
    {
        return ptr == other;
    }
    __forceinline ~NiPointer() throw()
    {
        if (ptr)
            ptr->DecRefCount();
    }
    NiPointer& operator=(NiGPUProgram* p) throw()
    {
        if (ptr != p)
        {
            if (ptr)
                ptr->DecRefCount();
            ptr = p;
            if (ptr)
                ptr->IncRefCount();
        }
        return *this;
    }
    __declspec(noinline) NiPointer& operator=(NiPointer const& other) throw()
    {
        if (ptr != other.ptr)
        {
            if (ptr)
                ptr->DecRefCount();
            ptr = other.ptr;
            if (ptr)
                ptr->IncRefCount();
        }
        return *this;
    }
};
struct DynCastHelper
{
    NiObject* DynamicCast(const void*) throw();
};
struct BinaryDataRecord
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int version;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int unk1E0;
    unsigned int unk1E4;
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
    DynCastHelper** objects;
    unsigned int unk224;
    unsigned int count;
};
NiGPUProgram* CreateResultFromStreamObject(BinaryDataRecord*, unsigned int, void*) throw();
void __cdecl NiFreeA4D(void* pvMem) throw();
struct NiTMapItemA4D
{
    NiTMapItemA4D* m_pkNext;
    const char* m_key;
    void* m_val;
};
class NiTMapBaseA4D
{
  public:
    virtual ~NiTMapBaseA4D() throw()
    {
        RemoveAll();
        NiFreeA4D(m_ppkHashTable);
    }

    void RemoveAll() throw();

    unsigned int m_uiHashSize;
    NiTMapItemA4D** m_ppkHashTable;
    unsigned int m_uiCount;
};
class NiTMapA4D : public NiTMapBaseA4D
{
  public:
    virtual ~NiTMapA4D() throw()
    {
        RemoveAll();
    }
};
namespace a47 {
struct Obj
{
    virtual void v00() throw();
    virtual void DeleteThis() throw();
    volatile long m_lRef;
    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_lRef);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&m_lRef))
            DeleteThis();
    }
};
struct Ptr
{
    Obj* m_p;
    Ptr(Obj* p = 0) throw() : m_p(p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    Ptr(const Ptr& o) throw() : m_p(o.m_p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    ~Ptr() throw()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    Ptr& operator=(Obj* p) throw()
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
    operator Obj*() const throw()
    {
        return m_p;
    }
    bool operator!=(const Ptr& o) const throw()
    {
        return m_p != o.m_p;
    }
    bool operator!=(Obj* p) const throw()
    {
        return m_p != p;
    }
    Ptr& operator=(const Ptr& o) throw()
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
}

struct NiBinaryStream
{
    void* m_pStorage;
    unsigned int m_uiPosition;
    unsigned int(__cdecl* m_pRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadGroupId(unsigned int* id)
    {
        unsigned int length = 4;
        m_uiPosition += m_pRead(this, id, 4, &length, 1);
    }
};
struct BGSCameraPath
{
};
template <class T> class NiTMallocInterface;
template <class T, class Alloc> class NiTArray;
template <> class NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >
{
  public:
    virtual ~NiTArray();
    BGSCameraPath** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetAt(unsigned int, BGSCameraPath**);
};
template <class T, class Allocator> class NiTPrimitiveArray;
template <> class NiTPrimitiveArray<char*, NiTMallocInterface<char*> >
{
  public:
    virtual ~NiTPrimitiveArray();
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*) throw();
class NiRefObjectAAC0
{
  public:
    virtual ~NiRefObjectAAC0() throw();
    virtual void DeleteThis() throw();
    virtual void Slot2() throw();
    virtual void Slot3() throw();
    virtual void Slot4() throw();
    virtual void Slot5() throw();
    virtual void Slot6() throw();
    virtual void Slot7() throw();
    virtual void Slot8() throw();
    virtual void Slot9() throw();
    virtual void Slot10() throw();
    virtual void Slot11() throw();
    virtual void Slot12() throw();
    virtual void Slot13() throw();
    virtual void Slot14() throw();
    virtual void Slot15() throw();
    virtual void Slot16() throw();
    virtual void Slot17() throw();
    virtual void Slot18() throw();
    virtual void Slot19() throw();
    virtual void Slot20() throw();
    virtual void Slot21() throw();
    virtual void Slot22() throw();
    virtual void Slot23() throw();
    virtual void Slot24() throw();
    virtual void Slot25() throw();
    virtual void Slot26() throw();
    virtual void Slot27() throw();
    virtual void Slot28() throw();
    virtual void Slot29() throw();
    virtual void Slot30() throw();
    virtual void Slot31() throw();
    virtual void Slot32() throw();
    virtual void Slot33() throw();
    virtual void Slot34() throw();
    virtual int Type() throw();
    unsigned int m_uiRefCount;
    void IncRefCount() throw()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class AnimIdle : public NiRefObjectAAC0
{
};
template <> class NiPointer<AnimIdle>
{
  public:
    AnimIdle* m_pObject;
    NiPointer<AnimIdle>& operator=(AnimIdle* object) throw()
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiPointer<AnimIdle>& operator=(const NiPointer<AnimIdle>& other) throw();
};
void __cdecl _delete(void*, unsigned int);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* Addend);
extern void* __cdecl FUN_00aa13e0(unsigned int size);
extern void __cdecl FUN_00a57500(void* fixed);
extern void __cdecl FUN_00a76960(void* fixed, void* out);
extern int DAT_0109b220;
extern void(__stdcall* DAT_00fdf1c0)(void*);
extern void(__stdcall* DAT_00fdf1c4)(void*);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void __cdecl NiFreeD510(void* pvMem);

class NiObjectD510
{
  public:
    virtual ~NiObjectD510();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    void NiObject_CreateDeepCopy(class NiPointerD510& spCopy);
    long m_uiRefCount;
};

class NiPointerD510
{
  public:
    NiPointerD510(NiObjectD510* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerD510()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerD510& operator=(const NiPointerD510& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiObjectD510* m_pObject;
};

class NiStreamD510
{
  public:
    NiStreamD510();
    ~NiStreamD510();
    bool InsertObject(NiObjectD510* pkObject);
    bool Save(char*& pcBuffer, int& iBufferSize);
    bool Load(char* pcBuffer, int iBufferSize);
    NiObjectD510* GetObjectAt(unsigned int i) const
    {
        return m_ppkTopObjects[i];
    }
    int unk000;
    char m_acInputFilePath[0x104];
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
    void* m_pTopObjectsVTable;
    NiObjectD510** m_ppkTopObjects;
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
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
};

// @fnv 0x00a5d510
// pdb: NiObject::CreateDeepCopy | NiObject.obj | fnv360_0822_retail, call_seq + bridge(call_dedup|call_gap_sim) + skyrim(caller_sim), high
void NiObjectD510::NiObject_CreateDeepCopy(NiPointerD510& spCopy)
{
    NiStreamD510 kStream;
    kStream.InsertObject(this);
    char* pcBuffer = 0;
    int iBufferSize = 0;
    kStream.Save(pcBuffer, iBufferSize);
    kStream.Load(pcBuffer, iBufferSize);
    NiPointerD510 spRetainedObject = kStream.GetObjectAt(0);
    NiFreeD510(pcBuffer);
    spCopy = spRetainedObject;
}
