// src/staging/blk_00e80000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e80000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/staging/blk_00e80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern "C" void __cdecl operator delete(void* p, unsigned int size);
extern int DAT_010efc34;
struct NiTMapBaseStub { void RemoveAll(); };
void FUN_00e933d0();
struct MemoryManager { void __thiscall Deallocate(void*); };
extern MemoryManager g_memoryManager;
struct FUN_00e95b80_Class {
    void __thiscall FUN_00e95b80();
};
struct BSFadeNode {
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00e98640_Class {
    void __thiscall FUN_00e98640();
};
extern "C" void __cdecl FUN_00aa1490(void*, unsigned int);
struct ShaderNode {
    virtual void Release(int);
};
struct NiD3DShaderProgramCreator { virtual ~NiD3DShaderProgramCreator(); };
struct FUN_00e91b90_Class : NiD3DShaderProgramCreator {
    virtual ~FUN_00e91b90_Class();
    int m_auiShapeKeys[3];
};
extern FUN_00e91b90_Class* DAT_0126fa54;
extern int DAT_010f0e50;
extern "C" void __cdecl NiFree(void*);
void __cdecl NiFree(void*);
extern "C" void __cdecl operator delete(void* p, unsigned int size);
extern int DAT_0126fa58;
void __cdecl FreeNodeList();
extern int DAT_0126fa50;
unsigned int __fastcall FUN_00e8a240(char* self, int);
void __cdecl _NiFree(void* p);
extern int DAT_010efdd8;
extern int DAT_010efdf8;
extern int DAT_010efdd8;
void __cdecl _NiFree(void* p);
void __cdecl _NiFree(void* p);
extern int DAT_010efe54;
extern MemoryManager _g_memoryManager;
extern int DAT_010efe54;
extern int DAT_010efe74;
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void*);
extern "C" void __cdecl operator delete(void*, unsigned int);
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void* p);
void __cdecl FUN_00e91c80();
void FUN_00e92080();
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
struct NiTMapBase {
    bool __thiscall RemoveAt(const char* name);
};
struct Program {
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
extern int DAT_0126fa30;
void __cdecl _NiFree(void* p);
extern MemoryManager _g_memoryManager;
void __cdecl _NiFree(void*);
extern "C" void __cdecl operator delete(void* p, unsigned int size);
extern int DAT_0126fa58;
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int);
};
void AllocateNodeList();
extern MemoryManager _g_memoryManager;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern const char* g_pcNullStringE81;
class NiFixedStringE81 {
public:
    ~NiFixedStringE81() throw()
    {
        if (m_kHandle != g_pcNullStringE81)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }

    const char* m_kHandle;
};
class NiRefObjectE81 {
public:
    virtual ~NiRefObjectE81() throw() { InterlockedDecrement(&ms_lObjectCount); }

    unsigned int m_uiRefCount;

    static long ms_lObjectCount;
};
struct E87B60AlphaProperty {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_uiObjectFlags;
    unsigned char m_ucAlphaThreshold;

    bool GetAlphaBlending() const { return (m_uiObjectFlags & 1) != 0; }
    unsigned int GetSrcBlendMode() const { return (m_uiObjectFlags >> 1) & 0xf; }
    unsigned int GetDestBlendMode() const { return (m_uiObjectFlags >> 5) & 0xf; }
    bool GetAlphaTesting() const { return ((unsigned short)(m_uiObjectFlags >> 9) & 1) != 0; }
    unsigned int GetTestMode() const { return (m_uiObjectFlags >> 10) & 7; }
    unsigned char GetTestRef() const { return m_ucAlphaThreshold; }
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
extern unsigned int DAT_011bf560;
extern unsigned short DAT_0126f958[];
extern unsigned short DAT_0126f92c[];
// Decompiled: dispatch a table value to a virtual slot on this.
struct FUN_00e88780_D3DObject {
    void* m_ppVirtualMethodTable;
};
typedef void (__stdcall *FUN_00e88780_D3DCall)(
    FUN_00e88780_D3DObject* pObject,
    int index,
    int value
);
typedef void (__stdcall *FUN_00e88830_Slot)(void* self, int code, int value);
extern unsigned short DAT_0126f958[];
// 256-byte span of not-yet-identified fields.
// NiDX9RenderState::GetSamplerState
typedef void (__stdcall *FUN_00e88a20_Slot)(void* self, int code, int value);
// NiD3DGeometryGroupManager
//   RTTI name  : .?AVNiD3DGeometryGroupManager@@   (vftable @ 0x010ef718)
//   Layout from the constructor at 0x00e88eb0 (the object is 0x1c bytes big):
//     +0x00  vftable pointer
//     +0x04  dword      +0x08  dword      +0x0c  dword
//     +0x10  dword      +0x14  dword      +0x18  byte flag
//   The single caller (0x00e73547) pushes a 0/1 byte and calls this setter.
extern unsigned short DAT_0126f92c[];
extern unsigned short DAT_0126f948[8];
extern unsigned int DAT_011bf558;
extern "C" void __cdecl FUN_00aa10f0(void*);
extern int DAT_0101dce4;
extern volatile long DAT_011f4400;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct FUN_00e89ae0_obj;
typedef int (__stdcall *FUN_00e89ae0_vfn)(FUN_00e89ae0_obj*, int, int, int);
struct FUN_00e89ae0_obj { void** vtbl; };
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);
extern "C" void __cdecl FUN_00a29680(const char* fmt, unsigned int i, void* s);
struct Key {
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
struct Value {
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
struct Item { Item* next; Key* key; Value* value; };
struct PoolNode { PoolNode* next; PoolNode* prev; void* data; };
struct LockObj { unsigned int value; void FUN_0040fbf0(char*); };
extern LockObj DAT_011c5f80;
extern unsigned int DAT_011c5f84;
extern PoolNode* DAT_011c5f58;
struct Com { virtual void __stdcall f0(); virtual void __stdcall f1(); virtual void __stdcall Release(); };
struct Target {
 virtual void f0();
 virtual unsigned int Hash(Key*);
 unsigned int bucketCount;
 Item** buckets;
 unsigned int count;
 PoolNode* head;
 PoolNode* tail;
 unsigned int listCount;
 Com* object;
 unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38;
 unsigned int bits[8];
 void ClearBit(unsigned int index) { unsigned int word=index>>5; unsigned int mask=1<<(index&31); bits[word]&=~mask; }
 Item* FUN_00ee8ac0();
 void FUN_00e8b630();
};
extern int DAT_010efdd8;
extern int DAT_010efdf8;
extern "C" void* __cdecl FUN_00aa1070(unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* p);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* cs);
void* __cdecl NiMemset(void* dst, int val, unsigned int size);
void* __cdecl NiMalloc(unsigned int size);
extern volatile long DAT_011f4400;
struct ComStub {
    virtual long __stdcall QueryInterface(void* riid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct RefObjStub {
    unsigned int m_uiRefCount;
    RefObjStub() { m_uiRefCount = 0; InterlockedIncrement(&DAT_011f4400); }
    virtual void DeleteThis();
};
struct MapBaseStub {
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
struct MapStub : MapBaseStub {
    MapStub(unsigned int hashSize = 37) : MapBaseStub(hashSize) {}
    virtual void MapV1();
};
struct CritSecStub {
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};
extern "C" char* DAT_0109b220;
extern "C" void (__stdcall* DAT_00fdf1c0)(void*);
extern "C" void (__stdcall* DAT_00fdf1c4)(void*);
struct ListNode_b5254 {
    ListNode_b5254* m_00;
    ListNode_b5254* m_04;
    unsigned int m_08;
};
static inline unsigned int& NextKey_b5254(ListNode_b5254*& pos) {
    unsigned int& e = pos->m_08;
    pos = pos->m_00;
    return e;
}
extern "C" void __cdecl operator delete(void* p, unsigned int size);
typedef bool (__cdecl *FNV_CondFn_e9c8c0)(float, void*, unsigned int, void*, unsigned int);
class FUN_00e9c8c0_obj {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual unsigned int GetIndex();
};
bool __cdecl CallConditionFunction(float afValue, FUN_00e9c8c0_obj* apFirst, unsigned int auiFirstArg, FUN_00e9c8c0_obj* apSecond, unsigned int auiSecondArg);
typedef int (__cdecl *FUN_00e9c950_handler)(float, void*, int, void*, int, int, int, int, int, int);
class FUN_00e9c950_cls_key
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual int Slot3();
};
int DispatchPairHandler(float afValue, FUN_00e9c950_cls_key* pFirst, int aiFirstArg, FUN_00e9c950_cls_key* pSecond, int aiSecondArg, int aiArg6, int aiArg7, int aiArg8, int aiArg9, int aiArg10);
struct DispatchObj_b4010 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};
typedef void (__cdecl *DispatchFn_b4010)(float, DispatchObj_b4010*, int, int, int, int, int);
void __cdecl DispatchByVirtualIndex(float afValue, DispatchObj_b4010* apObj, int aiArg2, int aiArg3, int aiArg4, int aiArg5, int aiArg6);
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
static int to_int(float f) { float t = f; return *(int*)&t; }
// Grow the object pool: allocate a block of N entries and push every entry onto the free set.
class E94B0MemoryManager {
public:
    void* Allocate(unsigned int uiSize);
};
extern E94B0MemoryManager g_kE94B0MemoryManager;
struct E94B0Entry {
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
struct E94B0Block {
    E94B0Block(unsigned int ItemUpdateArray) throw() : m_uiCount(ItemUpdateArray), m_pkNext(0)
    {
        if (ItemUpdateArray > 0)
            m_pkEntryArray = E94B0AllocEntries(ItemUpdateArray);
        else
            m_pkEntryArray = 0;
    }

    static void* operator new(unsigned int uiSize) { return g_kE94B0MemoryManager.Allocate(uiSize); }

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
class E94B0Pool {
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
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" void __cdecl FUN_00aa10f0(void* p);
void FUN_00e89740();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plValue);
extern char* DAT_0109b220;
struct StringTable {
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
class FixedStr {
public:
    FixedStr& operator=(const FixedStr& kString)
    {
        if (m_kHandle != kString.m_kHandle) {
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
struct Ref_e98cb0 {
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
};
struct Ptr_e98cb0 {
    Ref_e98cb0* m_p;
    void Release() { Ref_e98cb0* r = m_p; if (r && InterlockedDecrement(&r->m_uiRefCount) == 0) r->DeleteThis(); }
    void Clear() {
        Ref_e98cb0* r = m_p;
        if (r) {
            if (InterlockedDecrement(&r->m_uiRefCount) == 0) r->DeleteThis();
            m_p = 0;
        }
    }
};
struct NiColor3 {
    float m_r;
    float m_g;
    float m_kPointB;
    __forceinline NiColor3() : m_r(0.0f), m_g(0.0f), m_kPointB(0.0f) {}
};
class NiMemObject {
public:
    static void* operator new(unsigned int size) throw();
    static void* operator new(unsigned int, void* p) { return p; }
};
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern volatile long DAT_011f4400;
class NiRefObject : public NiMemObject {
public:
    NiRefObject() throw() {
        m_uiRefCount = 0;
        InterlockedIncrement(&DAT_011f4400);
    }
    virtual void V0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
class NiProperty : public NiRefObject {
public:
    NiProperty() throw();
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
class NiAlphaProperty : public NiProperty {
public:
    NiAlphaProperty() throw() {
        m_usAlphaArg = 0xec;
        m_ucAlphaArg2 = 0;
    }
    unsigned short m_usAlphaArg;
    unsigned char m_ucAlphaArg2;
    unsigned char m_ucPad1b;
};
struct SubObjF8 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    void __thiscall FUN_00e68810() throw();
    SubObjF8() {
        FUN_00e68810();
    }
};
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern unsigned short DAT_0126f92c[];
extern unsigned short DAT_0126f948[8];
extern unsigned short DAT_0126f958[];
struct Item9ea;
bool DispatchByVirtualIndex(float fTime, Item9ea* pkItem, void* p2, void* p3, void* p4, void* p5, void* p6);
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
struct ColorWithAlpha { float r,g,b,a; ColorWithAlpha(float red,float green,float blue):r(red),g(green),b(blue) {} void addScaled(const ColorWithAlpha& source,float factor) { r+=source.r*factor;g+=source.g*factor;b+=source.b*factor; } };
struct ActiveLight;
struct SceneLight {
 unsigned int field00;
 unsigned int field04;
 unsigned int field08;
 unsigned int field0c;
 unsigned int field10;
 unsigned int field14;
 unsigned int field18;
 unsigned int field1c;
 unsigned int field20;
 unsigned int field24;
 unsigned int field28;
 unsigned int field2c;
 unsigned int field30;
 unsigned int field34;
 unsigned int field38;
 unsigned int field3c;
 unsigned int field40;
 unsigned int field44;
 unsigned int field48;
 unsigned int field4c;
 unsigned int field50;
 unsigned int field54;
 unsigned int field58;
 unsigned int field5c;
 unsigned int field60;
 unsigned int field64;
 unsigned int field68;
 unsigned int field6c;
 unsigned int field70;
 unsigned int field74;
 unsigned int field78;
 unsigned int field7c;
 unsigned int field80;
 unsigned int field84;
 unsigned int field88;
 unsigned int field8c;
 unsigned int field90;
 unsigned int field94;
 unsigned int field98;
 unsigned char enabled; unsigned char direct; unsigned short field9e;
 unsigned int fielda0;
 unsigned int fielda4;
 unsigned int fielda8;
 unsigned int fieldac;
 unsigned int fieldb0;
 unsigned int fieldb4;
 unsigned int fieldb8;
 unsigned int fieldbc;
 unsigned int fieldc0;
 float intensity;
 float red;
 float green;
 float blue;
 unsigned int fieldd4;
 unsigned int fieldd8;
 unsigned int fielddc;
 unsigned int fielde0;
 unsigned int fielde4;
 unsigned int fielde8;
 ActiveLight* active;
};
struct ActiveLight {
 unsigned int field00;
 unsigned int field04;
 unsigned int field08;
 unsigned int field0c;
 unsigned int field10;
 unsigned int field14;
 unsigned int field18;
 unsigned int field1c;
 unsigned int field20;
 unsigned int field24;
 unsigned int field28;
 unsigned int field2c;
 unsigned int field30;
 unsigned int field34;
 unsigned int field38;
 unsigned int field3c;
 unsigned int field40;
 unsigned int field44;
 unsigned int field48;
 unsigned int field4c;
 unsigned int field50;
 unsigned int field54;
 unsigned int field58;
 unsigned int field5c;
 unsigned int field60;
 unsigned int field64;
 unsigned int field68;
 unsigned int field6c;
 bool stale; bool applied; unsigned short field72;
 bool UpdateFromSource(SceneLight*);
 ActiveLight* Init(SceneLight*, unsigned int);
};
inline SceneLight*& nextLight(PoolNode*& node) { SceneLight*& item=(SceneLight*&)node->data; node=node->next; return item; }
struct ShadowSceneLightList { PoolNode* head; PoolNode* tail; unsigned int count; void* InsertHead(SceneLight* const*); SceneLight* FUN_004edf00();
 __forceinline void recycle(PoolNode* node) { node->data=0; DAT_011c5f80.FUN_0040fbf0(0); node->prev=0; node->next=DAT_011c5f58; --DAT_011c5f84; DAT_011c5f58=node; if (!DAT_011c5f84) DAT_011c5f80.value=0; }
 __forceinline SceneLight* remove(PoolNode*& node) { if(node==head) { PoolNode* old=head; head=old->next; if(head) head->prev=0; else tail=0; SceneLight* element=(SceneLight*)old->data; recycle(old); --count; return element; } else if(node==tail) { return FUN_004edf00(); } else { PoolNode* prev=node->prev; PoolNode* next=node->next; if(prev)prev->next=next; if(next)next->prev=prev; SceneLight* element=(SceneLight*)node->data; recycle(node); --count; return element; } }
};
struct S00e8f190_Iface { void** vtable; };
typedef int (__thiscall *S00e8f190_Query)(void* vt, S00e8f190_Iface* object, int a, int b, int c, int d, S00e8f190_Iface** result, int zero);
typedef void (__fastcall *S00e8f190_Release)(void* flag, void* vt, S00e8f190_Iface* object, void* flag2);
extern "C" const char str_010f0184[];
extern unsigned int DAT_011bf560;
extern unsigned int DAT_011bf558;
struct Stage321 {
    int m_00;
    unsigned int m_04;
    int m_08;
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
    int m_60;

    void ReturnToPool() throw();
    void AcquireReference() { ++m_60; }
    void DecRef() { if (--m_60 == 0) ReturnToPool(); }
};
struct StagePtr {
    Stage321* m_p;
    StagePtr(Stage321* o) : m_p(o) { if (m_p) m_p->AcquireReference(); }
};
struct StageArray {
    void* m_vtbl;
    StagePtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00e7fd20(unsigned int size) throw();
    void Set(unsigned int index, const StagePtr& obj) throw();
    void SetAtGrow(unsigned int index, const StagePtr& obj) {
        if (index >= m_usMaxSize)
            FUN_00e7fd20(index + m_usGrowBy);
        Set(index, obj);
    }
};
typedef unsigned int UINT;
typedef unsigned long DWORD;
void __cdecl FUN_00aa1460(void* pvMem, unsigned int uiSize);
class BSSpinLockE8B {
public:
    void Lock(int iSpin);
    unsigned int m_uiOwningThread;
    unsigned int m_uiLockCount;

    void Unlock()
    {
        if (--m_uiLockCount == 0)
            m_uiOwningThread = 0;
    }
};
struct NiTListItemE8B {
    NiTListItemE8B* m_pkNext;
    NiTListItemE8B* m_pkPrev;
    void* m_element;
};
extern BSSpinLockE8B g_kListPoolLockE8B;
extern NiTListItemE8B* g_pkListFreeMemE8B;
class NiTPointerListE8B {
public:
    NiTListItemE8B* m_pkHead;
    NiTListItemE8B* m_pkTail;
    unsigned int m_uiCount;

    void* RemoveHead();
    void* RemoveTail();

    void* const& GetNext(NiTListItemE8B*& kPos) const
    {
        void* const& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }

    NiTListItemE8B* FindPos(void* element) const
    {
        NiTListItemE8B* kPos = m_pkHead;
        while (kPos) {
            NiTListItemE8B* kPrevPos = kPos;
            if (element == GetNext(kPos))
                return kPrevPos;
        }
        return 0;
    }

    void DeleteItem(NiTListItemE8B* pkItem)
    {
        g_kListPoolLockE8B.Lock(0);
        pkItem->m_pkPrev = 0;
        pkItem->m_pkNext = g_pkListFreeMemE8B;
        g_pkListFreeMemE8B = pkItem;
        g_kListPoolLockE8B.Unlock();
    }

    void RemovePos(NiTListItemE8B* pkNode)
    {
        if (pkNode == m_pkHead) {
            RemoveHead();
            return;
        }
        if (pkNode == m_pkTail) {
            RemoveTail();
            return;
        }
        NiTListItemE8B* pkPrev = pkNode->m_pkPrev;
        NiTListItemE8B* pkNext = pkNode->m_pkNext;
        if (pkPrev)
            pkPrev->m_pkNext = pkNext;
        if (pkNext)
            pkNext->m_pkPrev = pkPrev;
        pkNode->m_element = 0;
        DeleteItem(pkNode);
        m_uiCount--;
    }

    void Remove(void* element)
    {
        NiTListItemE8B* pkPos = FindPos(element);
        if (pkPos)
            RemovePos(pkPos);
    }
};
class ControllerE8B {
public:
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
    void* m_pvHandle;
    unsigned char unk70;
    bool m_bModifierActive;
    unsigned short unk72;
};
class KeyObjectE8B {
public:
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
    void* m_pvMapEntry;
};
class OwnerE8B {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9c();
    virtual void unka0();
    virtual void unka4();
    virtual void unka8();
    virtual void unkac();
    virtual void unkb0();
    virtual void unkb4();
    virtual void unkb8();
    virtual void unkbc();
    virtual void unkc0();
    virtual void unkc4();
    virtual void unkc8();
    virtual void unkcc();
    virtual void unkd0();
    virtual void __stdcall ReleaseHandle(void* pvHandle, int iFlags);
};
struct NiTMapItemE8B {
    NiTMapItemE8B* m_pkNext;
    KeyObjectE8B* m_key;
    ControllerE8B* m_val;
};
class ControllerMapE8B {
public:
    virtual ~ControllerMapE8B();
    virtual unsigned int KeyToHashIndex(KeyObjectE8B* key) const;

    unsigned int m_uiHashSize;
    NiTMapItemE8B** m_ppkHashTable;
    unsigned int m_uiCount;
    NiTPointerListE8B m_kKeys;
    OwnerE8B* m_pkOwnerManager;

    NiTMapItemE8B* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    void GetNext(NiTMapItemE8B*& pos, KeyObjectE8B*& key, ControllerE8B*& val) const
    {
        NiTMapItemE8B* pkItem = pos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext) {
            pos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (++i; i < m_uiHashSize; i++) {
            pkItem = m_ppkHashTable[i];
            if (pkItem) {
                pos = pkItem;
                return;
            }
        }
        pos = 0;
    }

    void FUN_00e91fd0(KeyObjectE8B* key);
    void FUN_00e8be20();
};
struct VBDesc {
    int iFormat;
    int iType;
    int iUsage;
    int iPool;
    unsigned int uiSize;
    unsigned int uiFVF;
};
struct VertexBuffer;
struct VertexBufferVtbl {
    void* s00; void* s04; void* s08; void* s0c;
    void* s10; void* s14; void* s18; void* s1c;
    void* s20; void* s24; void* s28; void* s2c;
    long (__stdcall *Unlock)(VertexBuffer* self);
    long (__stdcall *GetDesc)(VertexBuffer* self, VBDesc* desc);
};
struct VertexBuffer {
    VertexBufferVtbl* vtbl;
};
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
enum { S00e8f360_FMT16 = 101, S00e8f360_RTIB = 7 };
extern const char str_010f0184[];
typedef void (__cdecl *S00e8f360_LogFn)(const char*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
struct Resource8F6D0 {
    virtual long __stdcall QueryInterface(void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct Chip8F6D0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Resource8F6D0* m_pkResource;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    ~Chip8F6D0();
    static void operator delete(void* pvMem, unsigned int uiSize);
};
struct Entry8F6D0 {
    int unk00;
    int unk04;
    Chip8F6D0* m_apChips[5];
    static void operator delete(void* pvMem, unsigned int uiSize);
};
struct Item8F6D0 {
    Item8F6D0* m_pkNext;
    unsigned int m_key;
    Entry8F6D0* m_val;
};
struct Map8F6D0 {
    virtual ~Map8F6D0();
    unsigned int m_uiHashSize;
    Item8F6D0** m_ppkHashTable;
    unsigned int m_uiCount;

    Item8F6D0* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    __declspec(noalias) void GetNext(Item8F6D0*& pos, unsigned int& key, Entry8F6D0*& val) const;
    void RemoveAll();
};
#include <string.h>
extern "C" void* __cdecl FUN_00aa1070(unsigned int length);
struct RefBaseE989 {
    unsigned int m_uiRefCount;
    RefBaseE989() : m_uiRefCount(0) {}
    virtual ~RefBaseE989() { InterlockedDecrement(&DAT_011f4400); }
};
struct FUN_00e9ca50_Object {
    virtual void FUN_00e9ca50_Virtual0();
    virtual void FUN_00e9ca50_Virtual1();
    virtual void FUN_00e9ca50_Virtual2();
    virtual int FUN_00e9ca50_GetIndex();
};
typedef void (__cdecl *FUN_00e9ca50_Entry)(
    float,
    FUN_00e9ca50_Object *,
    int,
    int,
    int,
    int,
    int,
    int,
    int,
    int,
    int,
    int);
struct FUN_00e9ec90 {
    void* m_pData;
    virtual ~FUN_00e9ec90();
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }
};
static const void* kNull = 0;
extern "C" void* __cdecl memset(void*, int, unsigned int);
void* FUN_00aa13e0(unsigned int size);
struct S00e8fa80_Node {
    volatile unsigned int key;
    unsigned char flag;
    void* buffers[5];
    void Initialize() {
        key = 0; flag = 0;
        memset(buffers, 0, sizeof(buffers));
    }
};
void* FUN_00aa13e0(unsigned int size);
struct BlockLink {unsigned int next; unsigned int prev; BlockLink() : next(0), prev(0) {} };
extern int DAT_0126fa58;
void AllocateNodeList();
// Creates and uploads a cube texture resource.
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct TextureSurface;
struct DeviceResource;
struct ResourceConfig;
struct TextureInput;
struct TextureDescription {
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
};
struct ResourceOwner {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    DeviceResource* resource;
};
struct ResourceConfig {
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
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    bool mipmaps; unsigned char unk6f5; unsigned short unk6f6;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    TextureDescription* renderTargets[22];
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int defaultTarget;
};
struct DirectResource {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    TextureDescription description;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int* width;
    unsigned int* height;
    unsigned int* sizes;
    unsigned int unk070;
    unsigned int levels;
    unsigned int unk078;
    unsigned int faces;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    void* source;

    const TextureDescription& GetDescription() const { return description; }
    unsigned int GetWidth(unsigned int level = 0) const { return width[level]; }
    unsigned int GetHeight(unsigned int level = 0) const { return height[level]; }
    unsigned int GetLevels() const { return levels; }
    unsigned int GetFaces() const { return faces; }
    unsigned int GetSize() const { return sizes[GetLevels()] * GetFaces(); }
    void* GetPalette() const { return source; }
};
struct TextureSurface {
    virtual void v0();
    virtual unsigned long Release();
    volatile long references;
    void IncRefCount() { InterlockedIncrement(&references); }
    void DecRefCount() { if (!InterlockedDecrement(&references)) Release(); }
    TextureDescription description;
    void* source;
    unsigned int unk050;
    unsigned int* width;
    unsigned int* height;
    unsigned int* sizes;
    unsigned int levels;
    unsigned int unk064;
    unsigned int flags;
    unsigned int faces;

    const TextureDescription& GetDescription() const { return description; }
    unsigned int GetWidth(unsigned int level = 0) const { return width[level]; }
    unsigned int GetHeight(unsigned int level = 0) const { return height[level]; }
    unsigned int GetLevels() const { return levels; }
    unsigned int GetFaces() const { return faces; }
    unsigned int GetSize() const { return sizes[GetLevels()] * GetFaces(); }
    void* GetPalette() const { return source; }
    unsigned int GetFlags() const { return flags; }
};
struct TextureInput {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    struct InputDescription { unsigned int unk00, unk04, mode, unk0c, unk10, unk14, unk18; } description;
    void* resourceId;
    DirectResource* direct;
    TextureSurface* surface;
    const InputDescription& GetPreferences() const { return description; }
    DirectResource* GetDirect() const { return direct; }
    TextureSurface* GetSurface() const { return surface; }
    void* GetFilename() const { return resourceId; }
};
struct DeviceResource {
    virtual void Delete(unsigned int);
    unsigned int unk004;
    ResourceOwner* owner;
    unsigned int width;
    unsigned int height;
    TextureDescription description;
    unsigned int unk058;
    unsigned int unk05c;
    ResourceConfig* config;
    void* texture;
    unsigned int levels;
    bool fallback; bool mipmaps; unsigned short unk06e;
    unsigned int bytes;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int flags;

    void SetDescription(const TextureDescription& other) { description = other; }
    void SetDimensions(unsigned int x, unsigned int y) { width = x; height = y; }
    void FUN_00e687a0(TextureInput*, ResourceConfig*);
    bool SetProgram(void*);
    TextureDescription* FUN_00e8a300(TextureDescription*, void*, TextureDescription**);
    bool FUN_00e8aa70();
    void FUN_00e8ab70(DirectResource*, unsigned int);
    void FUN_00e8aaf0(TextureSurface*, unsigned int);
};
struct PlainResource58 {
    void* vtable;
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
    unsigned int flags;

    void FUN_00e687a0(TextureInput*, ResourceConfig*);
    PlainResource58(TextureInput* input, ResourceConfig* config) {
        FUN_00e687a0(input, config);
        vtable = &DAT_010efc34;
        flags = 0;
    }
};
enum AdapterDeviceType { AdapterDeviceDefault = 0 };
enum AdapterFormat { AdapterFormatUnknown = 0 };
struct CreationContext {
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
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int width;
    AdapterDeviceType deviceType;
    unsigned int unk5cc;
    AdapterFormat adapterFormat;

    void GetCreationInfo(unsigned int& w, AdapterDeviceType& h, AdapterFormat& f) {
        w = width;
        h = deviceType;
        f = adapterFormat;
    }
};
extern void* __cdecl FUN_00aa13e0(unsigned int);
extern void __cdecl FUN_00a29680(const void*, ...);
extern char DAT_010efd88, DAT_010ed4dc;
extern unsigned int DAT_0126f9bc, DAT_0126f9c0;
inline bool IsPowerOfTwo(unsigned int value) {
    if (value == 0) return false;
    return (value & (value - 1)) == 0;
}
struct ShaderComponent093 {
    int type;
    int format;
    char width;
    char flag;
    short unk0a;
};
struct ShaderRequest093 {
    unsigned int FUN_00e8a240();
    int unknown00;
    unsigned int kind;
    int disabled;
    int unk0c;
    int unk10;
    ShaderComponent093 components[4];
};
struct ShaderTraits093 { int kind; int ordering; };
struct ShaderChoices093 {
    void* choice00;
    void* choice04;
    void* choice08;
    void* choice0c;
    void* choice10;
    void* choice14;
    void* choice18;
    void* choice1c;
    void* choice20;
    void* choice24;
    void* choice28;
    void* choice2c;
    void* choice30;
    void* choice34;
    void* choice38;
    void* choice3c;
    void* choice40;
    void* choice44;
    void* choice48;
    void* choice4c;
    void* choice50;
    void* choice54;
};
void* __stdcall FUN_00e8a300(ShaderRequest093* request, ShaderTraits093* traits, ShaderChoices093* choices);
extern "C" bool __stdcall SetProgram(void* a);
extern int DAT_0101dce4;
extern "C" void __cdecl NiFree(void*);
extern "C" void __cdecl FUN_00aa1490(void*, unsigned int);

struct Item_cd60 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    ComStub* m_pkHolder;
    int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38;
    void __thiscall FUN_00e95b80();
};

struct Entry_cd60 {
    int unk00;
    int unk04;
    void* items[5];
};

struct Map_cd60 : MapBaseStub {
    __declspec(noalias) void __thiscall AdvanceToNextEntry(void** pos, unsigned int* key, void** value);

    __forceinline void* __thiscall GetFirst()
    {
        for (unsigned int i = 0; i < m_uiHashSize; ++i)
            if (m_ppkHashTable[i] != 0)
                return m_ppkHashTable[i];
        return 0;
    }
};

struct This_cd60 {
    int unk00;
    int unk04;
    int unk08;
    Map_cd60 map;
    void __thiscall FUN_00e8cd60();
};

// @fnv 0x00e8cd60
// pdb: NiDX9VertexBufferManager::DestroyDefaultBuffers | NiDX9VBManager.obj | tesv_win, call_gap_sim, low
void This_cd60::FUN_00e8cd60()
{
    Map_cd60* map = &this->map;
    {
        void* current = map->GetFirst();
        unsigned int key;
        void* value;

        while (current != 0) {
            map->AdvanceToNextEntry(&current, &key, &value);

            if (value != 0) {
                Entry_cd60* entry = (Entry_cd60*)value;
                void** pp = entry->items;
                for (int n = 5; n != 0; --n) {
                    Item_cd60* item = (Item_cd60*)*pp;
                    if (item != 0) {
                        ComStub* holder = item->m_pkHolder;
                        if (holder != 0)
                            holder->Release();
                        ((FUN_00e95b80_Class*)item)->FUN_00e95b80();
                        operator delete(item, 0x3c);
                    }
                    ++pp;
                }
                operator delete(entry, 0x1c);
            }
        }

    }
    map->RemoveAll();
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);

struct ShaderEntry093 : FUN_00e95b80_Class {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    ComStub* resource;
    int unk24, unk28, unk2c, unk30, unk34, unk38;
};
struct ShaderRecord093 {
    unsigned int unk00, unk04;
    ShaderEntry093* entries[5];
};
struct TargetShaderNode093 {
    TargetShaderNode093* next;
    unsigned int key;
    ShaderRecord093* value;
};
struct ShaderMapHeader093 { void* vtable; };
struct ShaderMap093 {
    virtual void Slot0();
    virtual unsigned int Hash(unsigned int key);
    void RemoveAll() { ((NiTMapBaseStub*)this)->RemoveAll(); }
    void Dispose() {
        ((ShaderMapHeader093*)this)->vtable = &DAT_010efe74;
        RemoveAll();
        ((ShaderMapHeader093*)this)->vtable = &DAT_010efe54;
        RemoveAll();
        FUN_00aa10f0(buckets);
    }
    unsigned int bucketCount;
    TargetShaderNode093** buckets;
    unsigned int count;
    TargetShaderNode093* First() {
        for (unsigned int i = 0; i < bucketCount; ++i)
            if (buckets[i]) return buckets[i];
        return 0;
    }
    void Next(TargetShaderNode093*& pos, unsigned int& key, ShaderRecord093*& value) {
        TargetShaderNode093* current = pos;
        value = current->value;
        if (current->next) { pos = current->next; return; }
        for (unsigned int i = Hash(current->key) + 1; i < bucketCount; ++i)
            {
                TargetShaderNode093* next = buckets[i];
                if (next) { pos = next; return; }
            }
        pos = 0;
    }
};

struct ShaderManagerRelease093 { void FUN_00e8ceb0(); };

// @f3 0x00885e80 (community match, verified in this file)
extern const char DAT_00e2a170, DAT_00e2a114, DAT_00e2a0f4, DAT_00db7764;
namespace f3m_00885e80 {
extern volatile long DAT_0108ed80;
void __cdecl FUN_0089e890(void* memory) throw();
void __cdecl FUN_0089ec10(void* memory, unsigned int bytes) throw();

class NativeBufferCom
{
public:
    virtual long __stdcall QueryInterface(void*, void**) throw();
    virtual unsigned long __stdcall AddRef() throw();
    virtual unsigned long __stdcall Release() throw();
};

class NativeVertexBufferEntry
{
public:
    void FUN_0088d340() throw();
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    NativeBufferCom* resource;
    unsigned int unk24, unk28, unk2C, unk30, unk34, unk38;
};
struct NativeVertexBufferRecord
{
    unsigned int unk00, unk04;
    NativeVertexBufferEntry* entries[5];
};
struct NativeVertexBufferNode
{
    NativeVertexBufferNode* next;
    unsigned int key;
    NativeVertexBufferRecord* value;
};
struct NativeVertexBufferVtable { const void* table; };

class NativeVertexBufferMapBase
{
public:
    virtual void Slot0();
    __forceinline void ReleaseBase() throw()
    {
        reinterpret_cast<NativeVertexBufferVtable*>(this)->table = &::DAT_00e2a0f4;
        FUN_006bd950();
        FUN_0089e890(buckets);
    }

    virtual unsigned int Hash(unsigned int key) throw();
    void FUN_006bd950() throw();

    unsigned int bucketCount;
    NativeVertexBufferNode** buckets;
    unsigned int count;

    __forceinline NativeVertexBufferNode* First() const
    {
        for (unsigned int index = 0; index < bucketCount; ++index)
        {
            if (buckets[index])
                return buckets[index];
        }
        return 0;
    }

    __forceinline void Next(NativeVertexBufferNode*& position, NativeVertexBufferRecord*& record)
    {
        NativeVertexBufferNode* current = position;
        record = current->value;
        if (current->next)
        {
            position = current->next;
            return;
        }

        for (unsigned int index = Hash(current->key) + 1; index < bucketCount; ++index)
        {
            NativeVertexBufferNode* next = buckets[index];
            if (next)
            {
                position = next;
                return;
            }
        }
        position = 0;
    }
};

class NativeVertexBufferMap : public NativeVertexBufferMapBase
{
public:
    __forceinline void Dispose() throw()
    {
        reinterpret_cast<NativeVertexBufferVtable*>(this)->table = &::DAT_00e2a114;
        FUN_006bd950();
        ReleaseBase();
    }
};
class NativeVertexBufferRef
{
public:
    virtual void Slot0();
    __forceinline void ReleaseRefBase() throw()
    {
        reinterpret_cast<NativeVertexBufferVtable*>(this)->table = &::DAT_00db7764;
        InterlockedDecrement(&DAT_0108ed80);
    }
    unsigned int referenceCount;
};

class NiDX9VertexBufferManager : public NativeVertexBufferRef
{
public:
    __forceinline void ShutDown() throw()
    {
        reinterpret_cast<NativeVertexBufferVtable*>(this)->table = &::DAT_00e2a170;
        ReleaseRecords();

        first.FUN_006bd950();
        second.FUN_006bd950();
        third.FUN_006bd950();
        device->Release();
        device = 0;
        FUN_0089e890(allocation);
        DeleteCriticalSection(&lock);
        third.Dispose();
        second.Dispose();
        first.Dispose();
        ReleaseRefBase();
    }

    __forceinline void ReleaseRecords() throw()
    {
        NativeVertexBufferMap* map;
        for (unsigned int group = 0; group < 3; ++group)
        {
            switch (group)
            {
                case 0: map = &first; break;
                case 1: map = &second; break;
                case 2: map = &third; break;
            }

            NativeVertexBufferNode* position = map->First();
            while (position)
            {
                NativeVertexBufferRecord* record;
                map->Next(position, record);
                if (record)
                {
                    for (unsigned int index = 0; index < 5; ++index)
                    {
                        NativeVertexBufferEntry* entry = record->entries[index];
                        if (entry)
                        {
                            if (entry->resource)
                                entry->resource->Release();
                            entry->FUN_0088d340();
                            FUN_0089ec10(entry, sizeof(NativeVertexBufferEntry));
                        }
                    }
                    FUN_0089ec10(record, sizeof(NativeVertexBufferRecord));
                }
            }
        }

    }

    NativeBufferCom* device;
    NativeVertexBufferMap first, second, third;
    unsigned int unk3C;
    void* allocation;
    unsigned int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    CritSecStub lock;
};

}
// pdb: NiDX9VertexBufferManager::~NiDX9VertexBufferManager | NiDX9VBManager.obj | tesv_win, objrun, medium
void ShaderManagerRelease093::FUN_00e8ceb0()
{
    reinterpret_cast<f3m_00885e80::NiDX9VertexBufferManager*>(this)->ShutDown();
}


extern "C" void __cdecl NiDX9Renderer__SDMShutdown();
extern "C" void __cdecl DestroyBucketTable();
extern "C" void __cdecl DestroyGlobalQueues();
extern "C" void __cdecl FUN_00e80630();
extern "C" void __cdecl ResetGlobalString();
void __cdecl FUN_00e89740();
void __cdecl FUN_00e92080();
extern "C" void __cdecl FUN_00e93260(void*);
extern "C" void __cdecl FUN_00e93f50(void*);
extern unsigned char DAT_0126fa00;
extern NiD3DShaderProgramCreator* DAT_0126fa3c;

// @fnv 0x00e91c80
void __cdecl FUN_00e91c80()
{
    if (DAT_0126fa00)
    {
        DAT_0126fa00 = 0;
        ResetGlobalString();
        void* p = DAT_0126fa3c;
        if (p)
        {
            FUN_00e93260(p);
            if (DAT_0126fa3c)
                ((ShaderNode*)DAT_0126fa3c)->Release(1);
        }
        DAT_0126fa3c = 0;
        p = DAT_0126fa54;
        if (p)
        {
            FUN_00e93260(p);
            if (DAT_0126fa54)
                ((ShaderNode*)DAT_0126fa54)->Release(1);
        }
        DAT_0126fa54 = 0;
        p = (void*)DAT_0126fa50;
        if (p)
        {
            FUN_00e93260(p);
            if (DAT_0126fa50)
                ((ShaderNode*)DAT_0126fa50)->Release(1);
        }
        DAT_0126fa50 = 0;
        FUN_00e93f50(0);
        FUN_00e933d0();
        FUN_00e92080();
        DestroyBucketTable();
        FUN_00e80630();
        DestroyGlobalQueues();
        FUN_00e89740();
        NiDX9Renderer__SDMShutdown();
    }
}

// @fnv 0x00e94290
// pdb: NiVBSet::DeleteBlocks | NiVBSet.obj | fnv360_0822_retail, objrun_prop, low
void __cdecl FUN_00e94290()
{
    FreeNodeList();
    FUN_00e98640_Class* node = reinterpret_cast<FUN_00e98640_Class*>(DAT_0126fa30);
    if (node)
    {
        FUN_00e98640_Class* next;
        do
        {
            next = reinterpret_cast<FUN_00e98640_Class*>(
                reinterpret_cast<int*>(node)[0x3c / 4]);
            node->FUN_00e98640();
            operator delete(node, 0x44);
            node = next;
        } while (node);
    }
    DAT_0126fa30 = 0;
}
