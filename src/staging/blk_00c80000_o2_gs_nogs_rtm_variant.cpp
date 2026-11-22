// src/staging/blk_00c80000_o2_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00c80000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/staging/blk_00c80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern int DAT_010c53dc;
extern int DAT_01267e60;
void* __cdecl FUN_00c81c50(void*);
struct NiStream;
struct NiObject
{
    virtual void LinkObject(NiStream&);
};
extern "C" void __cdecl operator delete(void*, unsigned int);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern void(__stdcall* DAT_010c53bc)(int*);
struct NiPoint3
{
    float x, y, z;
};
int __stdcall FUN_00c84ec0(void* apObject);
__forceinline int Sign_00c9a070(float f)
{
    return f < 0.0f ? -1 : 1;
}
struct Range_00c9a070
{
    float fHi;
    float fLo;
    Range_00c9a070(float h, float l) : fHi(h), fLo(l)
    {}
};
__forceinline void Adjust_00c9a070(float& out, float v, float fHi, float fLo)
{
    Range_00c9a070 r(fHi, fLo);
    float s = (float)Sign_00c9a070(v);
    float t = v + (r.fHi - r.fLo) * s;
    if (t * s > 0.0f)
        out -= t;
}
extern int DAT_010c6b04;
extern "C" void __cdecl NiFree(void*);
struct FUN_00c9aeb0_t
{
    char m_data[0x5c];
    FUN_00c9aeb0_t();
    ~FUN_00c9aeb0_t();
    static void* operator new(unsigned int);
};
extern void(__stdcall* DAT_0126820c_enter)(int*);
extern void(__stdcall* DAT_0126820c_leave)(int*);
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};
struct FUN_00c6b910 : A51BF0Base
{
    FUN_00c6b910();
};
struct bhkBlendCollisionObject : FUN_00c6b910
{
    void* m_vtbl;
    unsigned char m_pad_04[8];
    unsigned short m_flags;
    unsigned char m_pad_0e[6];
    unsigned char m_flag14;
    unsigned char m_pad_15[3];
    float m_f18;
    float m_f1c;
    int m_i20;
    int m_i24;
    int m_i28;

    void __thiscall FUN_00c657f0(void* p, int value);

    bhkBlendCollisionObject()
    {
        m_vtbl = &DAT_010c53dc;
        ++DAT_01267e60;
        m_f18 = 0.0f;
        m_flags &= 0xfeff;
        m_f1c = 1.0f;
        m_i20 = 8;
        m_i24 = 0;
        m_i28 = 0;
        m_flag14 = 0;
    }

    bhkBlendCollisionObject* FUN_00c81670(int value);
};
struct NiGlobalStringTable
{
    static char* __cdecl AddString(char const* str);
};
extern char* _EmptyFS;
struct StringHolder
{
    char* p;

    StringHolder(char const* str) : p(NiGlobalStringTable::AddString(str))
    {}

    ~StringHolder()
    {
        if (p != _EmptyFS)
        {
            InterlockedDecrement(reinterpret_cast<long*>(p - 8));
        }
    }
};
void(__stdcall* DAT_0126813c_leave)(void*);
extern __declspec(thread) unsigned int memoryCategory;
struct ScopedMemoryCategory
{
    unsigned int previous;
    ScopedMemoryCategory() : previous(memoryCategory)
    {
        memoryCategory = 16;
    }
    ~ScopedMemoryCategory()
    {
        memoryCategory = previous;
    }
};
struct ArenaAllocator
{
    virtual void Reserved();
    virtual char* Allocate(unsigned int bytes);
};
struct ArenaMemoryManager : MemoryManager
{
    void* Allocate(unsigned int bytes);
};
struct TemporaryArena
{
    char* start;
    char* cursor;
    char* end;
    ArenaAllocator* current;
    ArenaAllocator* allocator;
    unsigned int unk14;
    ArenaAllocator* saved;
    unsigned int unk1C;
    unsigned int unk20;
    TemporaryArena();
    static void* operator new(unsigned int bytes)
    {
        return static_cast<ArenaMemoryManager*>(&g_memoryManager)->Allocate(bytes);
    }
};
struct ArenaRegistrationFlag
{
    unsigned int value;
    ArenaRegistrationFlag() : value(1)
    {}
    ArenaRegistrationFlag(const ArenaRegistrationFlag& other) : value(other.value)
    {}
};
extern "C" __declspec(dllimport) void __stdcall ArenaEnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall ArenaLeaveCriticalSection(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
struct SpawnedAllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};
struct SpawnedPtrArray
{
    void** m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiCapacity;
};
extern "C" void _ReadWriteBarrier(void);
SpawnedAllocHolder* FUN_00c85750();
void ResizeAudioStream(void* allocator, SpawnedPtrArray* arr, unsigned int growBy);
inline void* __cdecl operator new(unsigned int, void* placement)
{
    return placement;
}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
struct NiAllocator
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};
extern NiAllocator DAT_011f6238;
struct RefObject
{
    int unk00;
    volatile long referenceCount;
};
struct RefNode
{
    RefObject* item;
    RefNode* next;
    __forceinline RefNode(RefObject* p)
    {
        item = p;
        if (p)
            InterlockedIncrement(&p->referenceCount);
        next = 0;
    }
};
// bhkWorld_GetRTTI : a one-line function - getter
class C815B0Base
{
  public:
    bool IsEqual(C815B0Base* pkOther);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class C815B0Constraint : public C815B0Base
{
  public:
    float m_fMinAngle;
    float m_fMaxAngle;

    bool FUN_00c815b0(C815B0Constraint* pkOther);
};
extern int DAT_010c53dc;
extern int DAT_01267e60;
struct TreeResult_cls
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual TreeResult_cls* v0f();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int m_24;
};
struct TreeHost_cls
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
    TreeResult_cls* __thiscall FindResult(unsigned int* rtti);
};
struct TreeNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual TreeNode_cls* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    TreeHost_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    TreeNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
extern unsigned int DAT_012043f8;
extern unsigned __int64 selected_target_masks[];
struct NiColor
{
    float r, g, b;
    NiColor()
    {}
    NiColor(float fR, float fG, float fB) : r(fR), g(fG), b(fB)
    {}
};
void __cdecl GetLayerColor(unsigned int layer, NiColor& rColor);
extern "C" unsigned char __cdecl FUN_00c84740(void* pA, void* pB);
unsigned char __cdecl FUN_00c84740(int a1, int a2);
// FUN_00c84930: stdcall 3-arg wrapper.
//   a2->m_24 and a3->m_1c are passed to the cdecl helper FUN_00c84740,
//   the resulting byte is written through the first (out) parameter, which is returned.
unsigned char __cdecl FUN_00c84740(int a1, int a2);
// Target class of the first virtual call
struct NiStream;
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
class RefLeaf_t
{
  public:
    virtual void unk00();
    virtual void unk04();
    unsigned int m_04;
};
struct Inner_t;
struct Inner_t
{
    int unk00;
    int unk04;
    RefLeaf_t* m_08;
};
// bhkSerializable_PostInit: thiscall, 18 bytes. Self virtual call at slot 0xa4 (index 41) tail-jumped with constant 1 in the stack arg.
class C87710BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(C87710BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
class BC87850BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BC87850BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BC87850BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

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
class BC87850Stream
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
    BC87850BinaryStream* m_pUnderlyingStream;
    BC87850BinaryStream* m_pBackingStream;
};
template <class T>
inline void BC87850BinaryStreamSave(BC87850BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BC87850SaveBinary(BC87850Stream& kStream, const T& value)
{
    BC87850BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
// Constructor of a two-level Havok wrapper: attach the given Havok object (through its referenced-object base).
extern int g_iC88380RefObjectCount;
class C88380ReferencedObject
{
  public:
    int m_iMemSizeAndFlags;
};
class C88380Root
{
  public:
    C88380Root();
    virtual ~C88380Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};
class C88380Holder : public C88380Root
{
  public:
    C88380Holder() : m_pkHavokObject(0)
    {}
    virtual ~C88380Holder();
    void* m_pkHavokObject;
};
class C88380RefObject : public C88380Holder
{
  public:
    C88380RefObject()
    {
        ++g_iC88380RefObjectCount;
    }
    virtual ~C88380RefObject();
    void SetReferencedObject(C88380ReferencedObject* pkObject);
};
struct ThreadTlsBlock
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) ThreadTlsBlock g_tls;
struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        g_tls.m_2b4 = m_saved;
    }
};
struct S_00c89810_ResultInner
{
    void* unk0;
    void* unk4;
    int unk8;
};
struct S_00c89810_Result
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2(int value)
    {}

    S_00c89810_ResultInner* m_p4;
};
struct S_00c89810_Owner
{
    virtual void d00()
    {}
    virtual void d01()
    {}
    virtual void d02()
    {}
    virtual void d03()
    {}
    virtual void d04()
    {}
    virtual void d05()
    {}
    virtual void d06()
    {}
    virtual void d07()
    {}
    virtual void d08()
    {}
    virtual void d09()
    {}
    virtual void d0a()
    {}
    virtual void d0b()
    {}
    virtual void d0c()
    {}
    virtual void d0d()
    {}
    virtual void d0e()
    {}
    virtual void d0f()
    {}
    virtual void d10()
    {}
    virtual void d11()
    {}
    virtual void d12()
    {}
    virtual void d13()
    {}
    virtual void d14()
    {}
    virtual void d15()
    {}
    virtual void d16()
    {}
    virtual void d17()
    {}
    virtual void d18()
    {}
    virtual void d19()
    {}
    virtual void d1a()
    {}
    virtual void d1b()
    {}
    virtual void d1c()
    {}
    virtual void d1d()
    {}
    virtual void d1e()
    {}
    virtual void d1f()
    {}
    virtual void d20()
    {}
    virtual void d21()
    {}
    virtual void d22()
    {}
    virtual void d23()
    {}
    virtual void d24()
    {}
    virtual void d25()
    {}
    virtual void d26()
    {}
    virtual void d27()
    {}
    virtual void d28()
    {}
    virtual void d29()
    {}

    virtual void mA8()
    {}
    virtual void mA9()
    {}
    virtual void mAA()
    {}
    virtual void* mB4(char* value)
    {
        return 0;
    }

    void SetValueAndReset(int value);
};
struct RefTarget
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03(int a)
    {}
};
struct FUN_00c89920_cls
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
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual unsigned char* GetRef(unsigned char* flag);
    void InvokeRefTarget(int a);
};
struct S_00c89a30_Obj;
struct S_00c89a30_Owner;
struct S_00c89a30_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual int v37();
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
    virtual void v53(S_00c89a30_Obj* o, int f);
    int unk04;
    S_00c89a30_Owner* unk08;
    void FUN_00c6b320(S_00c89a30_Owner* owner);
    bool FUN_00c89a30(S_00c89a30_Obj* other);
};
extern __declspec(thread) int DAT_tls_field;
struct TlsGuard
{
    int old;
    TlsGuard() : old(DAT_tls_field)
    {
        DAT_tls_field = 16;
    }
    ~TlsGuard()
    {
        DAT_tls_field = old;
    }
};
struct S_00c8a280_Bin
{
    void* __vf;
    unsigned int m_uiPos;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(S_00c8a280_Bin*, const void*, unsigned int, unsigned int*, unsigned int);
};
inline void S_00c8a280_Save(S_00c8a280_Bin* b, const void* buf, unsigned int bytes)
{
    unsigned int comp = bytes;
    unsigned int n = b->m_pfnWrite(b, buf, bytes, &comp, 1);
    b->m_uiPos += n;
}
class C8A4B0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C8A4B0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(C8A4B0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
class C8A4B0Object;
class C8A4B0Stream
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(C8A4B0Object* pkObject);

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
    C8A4B0BinaryStream* m_pBackingStream;
};
template <class T>
inline void C8A4B0BinaryStreamSave(C8A4B0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void C8A4B0SaveBinary(C8A4B0Stream& kStream, const T& value)
{
    C8A4B0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
struct FUN_00c8a7a0_cls;
struct FUN_00c8a7a0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void* v2D(unsigned int* out);
    void Init(unsigned int a);
    void FUN_00c8a7a0(unsigned int a1);
};
// Result block filled in by WriteScriptTargetInfo.
// Object reached through the member pointer of the owner.
extern int DAT_012681a0;
struct FUN_00c8b000_Node
{
    int m_00;
    void* m_04;
    void* m_08;
};
struct FUN_00c8b000_Item;
struct FUN_00c8b000_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual FUN_00c8b000_Node* v18(int a);
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
    virtual bool v52(int a);
};
struct FUN_00c8b000_Item
{
    int m_00;
    int m_04;
    FUN_00c8b000_Obj* m_08;
};
// HandleAllEntries — walks the entry array of the list object held at this+0x08
// and forwards the parameter to each entry's handler-object virtual
// (vtable slot 21), then calls the member routine FUN_00aa0ad0 on this.
//
// Count source: vtable slot 1 of the sub-object embedded at list+0x10, with
// the owner chain (this, list) null-checked; the entry walk re-checks the
// chain on every iteration and skips null slots / null handler objects.
//
// Target: __thiscall (this in ecx), callee pops 4 bytes (1 stack parameter),
// size 109, /MT /O2 /GS /EHsc /Gy.
// Sub-object embedded at list+0x10; its vtable slot 1 returns the entry
// count as an unsigned value.
// Handler object; vtable slot 21 (+0x54) is invoked with the parameter.
struct Handler00;
// Entry object referenced by a slot; field +0x08 points at the handler
// object that receives the per-entry virtual call.
struct Entry00;
// One 16-byte slot of the entry array at list+0x18; only the first dword
// (a pointer to the entry object) is read here.
struct Entry00
{
    int unk00;
    int unk04;
    Handler00* unk08;  // +0x08
};
struct Handler00
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void Handle(void* param);  // vtable +0x54
};
// The list object held at this+0x08: embedded polymorphic sub-object at
// +0x10, spare dword at +0x14, entry array base at +0x18.
// Owning class of the target member.
typedef void(__stdcall* DecCallback)(void* arg);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(thread) int g_memoryContext;
struct MemoryContextScope
{
    int previousContext;
    MemoryContextScope()
    {
        previousContext = g_memoryContext;
        g_memoryContext = 16;
    }
    ~MemoryContextScope()
    {
        g_memoryContext = previousContext;
    }
};
extern __declspec(thread) int tls_iMemContext;
struct MemContextScope
{
    int iOld;
    MemContextScope(int iNew)
    {
        iOld = tls_iMemContext;
        tls_iMemContext = iNew;
    }
    ~MemContextScope()
    {
        tls_iMemContext = iOld;
    }
};
char* __cdecl CreateDebugString(const char* pcName);
char* __cdecl CreateDebugString(const char* pcName, int iValue);
struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    unsigned int Add(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};
struct hkpShapeContainerStub
{
    virtual ~hkpShapeContainerStub();
    virtual int GetNumChildShapes();
};
struct hkpListShapeStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkpShapeContainerStub kContainer;
};
struct bhkShapeCollectionBase
{
    void GetViewerStrings_base(ViewerStrings* pkStrings);
};
struct bhkListShapeStub : bhkShapeCollectionBase
{
    int unk00;
    int unk04;
    hkpListShapeStub* m_pHavokObject;

    void FUN_00c8bcd0(ViewerStrings* pkStrings);
};
static inline hkpListShapeStub* GetHkListShape(bhkListShapeStub* p)
{
    return p ? p->m_pHavokObject : 0;
}
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);
struct SwapMatrix_c8ce70
{
    unsigned long m00;
    unsigned long m04;
    unsigned long m08;
    unsigned long m0c;
    unsigned long m10;
    unsigned long m14;
    unsigned long m18;
    unsigned long m1c;
    unsigned long m20;
    unsigned long m24;
    unsigned long m28;
    unsigned long m2c;
};
inline void Swap32_c8ce70(void* p)
{
    unsigned long* q = (unsigned long*)p;
    *q = _byteswap_ulong(*q);
}
inline void Swap16_c8ce70(void* p)
{
    unsigned short* q = (unsigned short*)p;
    *q = _byteswap_ushort(*q);
}
void __cdecl SwapEndianBlocks(SwapMatrix_c8ce70* m);
class C90830ReferencedObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    C90830ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual ~C90830ReferencedObject()
    {}
};
struct C90830Stream
{
    int m_iHandle;
    unsigned short m_usFlags;

    C90830Stream() : m_iHandle(-15), m_usFlags(0x8000)
    {}
    void ResetThreadCheck() throw();
};
extern int DAT_012681c0;
void* NiMalloc(unsigned int size);
void NiFree(void* p);
struct Elem_c9ac00
{
    float a;
    float b;
    float c;
    Elem_c9ac00()
    {}
    Elem_c9ac00(int i)
    {
        float f = (float)(i / 100.0);
        a = -1.0f;
        b = f;
        c = f;
    }
    Elem_c9ac00& operator=(const Elem_c9ac00& o)
    {
        a = o.a;
        b = o.b;
        c = o.c;
        return *this;
    }
    bool operator!=(const Elem_c9ac00& o) const
    {
        return a != o.a || b != o.b || c != o.c;
    }
};
struct LargeArray_c9ac00
{
    void** m_ppVirtualMethodTable;
    Elem_c9ac00* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Resize(unsigned int uiMaxSize);
};
// FUN_00c9add0 : a one-line function - getter
struct S_00c9af40_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(S_00c9af40_BinStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(S_00c9af40_BinStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};
struct S_00c9af40_Point
{
    float x, y, z;
    S_00c9af40_Point()
    {}
    S_00c9af40_Point(const S_00c9af40_Point& o) : x(o.x), y(o.y), z(o.z)
    {}
};
template <class T> inline void WriteBinaryArray(S_00c9af40_BinStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kStream.Write(pkValue, uiNumEls * sizeof(T), &uiSize, 1);
}
inline void SwapFloat(float& f)
{
    unsigned int u = *(unsigned int*)&f;
    *(unsigned int*)&f = _byteswap_ulong(u);
}
inline void SwapPoint(S_00c9af40_Point& p)
{
    SwapFloat(p.y);
    SwapFloat(p.x);
    SwapFloat(p.z);
}
extern __declspec(thread) int g_iC9B970MemContext;
class C9B970MemContext
{
  public:
    C9B970MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iC9B970MemContext;
        g_iC9B970MemContext = aiMemoryContext;
    }
    ~C9B970MemContext()
    {
        g_iC9B970MemContext = m_iPrevious;
    }

    int m_iPrevious;
};
void __cdecl CollectTreeResultValues(TreeNode_cls* node, SpawnedPtrArray* arr);
// Give the object an emissive material of the given color, notify listeners, then update it through the owner.
struct C11F0Color
{
    float r;
    float g;
    float b;
};
class C11F0Object;
extern void(__cdecl* g_pfnC11F0EmissiveChanged)(C11F0Object* pkObject, C11F0Color* pkColor);
class C11F0Material
{
  public:
    C11F0Material();
    virtual ~C11F0Material();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    void SetEmittance(const C11F0Color& kColor)
    {
        m_kEmissive = kColor;
        m_uiRevisionID++;
    }

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    C11F0Color m_kEmissive;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned int m_uiRevisionID;
    int unk48;
};
class C11F0Object
{
  public:
    void AttachProperty(C11F0Material* pkProperty);
};
class C11F0Owner
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual void UnkB4();
    virtual void UnkB8();
    virtual void UnkBC();
    virtual void UnkC0();
    virtual void UnkC4();
    virtual void UnkC8();
    virtual void UnkCC();
    virtual void UnkD0();
    virtual void UnkD4();
    virtual void UnkD8();
    virtual void UpdateObject(C11F0Object* pkObject, bool bForce);
};
void AttachEmissiveMaterial(C11F0Object* pkObject, C11F0Owner* pkOwner, int m_uiSoundID, C11F0Color* pkColor);
typedef int(__cdecl* NiBinaryStream_fn)(void* s, void* buf, unsigned int n, int* out, int flag);
struct NiBinaryStream
{
    void* m_00;
    unsigned int m_04;
    NiBinaryStream_fn m_08;

    unsigned int BinaryRead(void* p, unsigned int n, int* sizes, unsigned int count)
    {
        unsigned int read = m_08(this, p, n, sizes, count);
        m_04 += read;
        return read;
    }
};
struct NiStream
{
    int m_00;
    unsigned int m_04;
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    NiBinaryStream* m_24c;
};
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    int uiSize = sizeof(T);
    kIstr->BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream* kStream, T& value)
{
    NiBinaryStreamLoad(kStream->m_24c, &value);
}
char* __cdecl CreateDebugString(const char* pcName, float fValue);
char* __cdecl CreateDebugString(const char* pcName, bool bValue);
char* __cdecl CreateDebugString(const char* pcName, const char* pcValue);
__forceinline bool GetFlagBit8(unsigned short f)
{
    return (f >> 8) & 1;
}
__forceinline bool GetFlagBit9(unsigned short f)
{
    return (f >> 9) & 1;
}
extern unsigned char __cdecl FUN_00c84740(void* object, unsigned int value);
struct HavokFilterInfo
{
    unsigned int m_uFilterInfo;

    unsigned short GetGroup() const
    {
        return (unsigned short)(m_uFilterInfo >> 16);
    }
    unsigned int GetLayer() const
    {
        return m_uFilterInfo & 0x7F;
    }
    bool GetLink() const
    {
        return (m_uFilterInfo >> 15) & 1;
    }
    unsigned int GetPart() const
    {
        return (m_uFilterInfo >> 8) & 0x1F;
    }
    bool GetNoCol() const
    {
        return (m_uFilterInfo >> 14) & 1;
    }
    bool GetScaled() const
    {
        return (m_uFilterInfo >> 13) & 1;
    }

    void AppendToViewerStrings(ViewerStrings* pkStrings);
};
static __forceinline void AddString(ViewerStrings* pkStrings, char* pcString)
{
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pcString);
}
struct NiFixedStrX
{
    char* m_str;
    NiFixedStrX(const char* str)
    {
        m_str = NiGlobalStringTable::AddString(str);
    }
    __forceinline ~NiFixedStrX()
    {
        if (m_str != _EmptyFS)
            InterlockedDecrement((long*)(m_str - 8));
    }
};
struct NiNodeX
{
    int unk00;
    int unk04;
    char* m_name;
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
    NiNodeX(unsigned short count);
    void SetName(const NiFixedStrX& name);
    static void* operator new(unsigned int size);
};
void __cdecl GetLayerColor(int shape, NiPoint3* out);
extern __declspec(thread) int g_iC88760AllocTag;
struct BC88760AllocTagScope
{
    int m_iSaved;

    BC88760AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC88760AllocTag;
        g_iC88760AllocTag = aiAllocationTag;
    }
    ~BC88760AllocTagScope()
    {
        g_iC88760AllocTag = m_iSaved;
    }
};
class BC88760CloningProcess;
class BC88760Base
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BC88760Base();
    virtual ~BC88760Base();

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
};
class BC88760Derived : public BC88760Base
{
  public:
    BC88760Derived()
    {}
    virtual ~BC88760Derived();

    void CopyMemberData(BC88760Derived* pkDest, BC88760CloningProcess& kCloning);
    BC88760Derived* FUN_00c88760(BC88760CloningProcess& kCloning);
};
class NiNode;
class NiAVObject;
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char* pcString) : m_kHandle(NiGlobalStringTable::AddString(pcString))
    {}
    ~NiFixedString()
    {
        if (m_kHandle != _EmptyFS)
            InterlockedDecrement(reinterpret_cast<long*>(m_kHandle - 8));
    }
};
class NiUpdateData
{
  public:
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    bool m_bUpdateGeomorphs;
    bool m_bUpdateShadowSceneNode;
    bool m_bUnk8;
    NiUpdateData()
        : m_fTime(0.0f), m_bUpdate(false), m_bIsMultiThreaded(false), m_bUpdateGeomorphs(false),
          m_bUpdateShadowSceneNode(false), m_bUnk8(false)
    {}
};
struct FUN_00c88810_Collision
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
};
class NiAVObject
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode* IsSceneNode();
    char pad04[0x14];
    NiNode* m_pParentNode;
    FUN_00c88810_Collision* m_spCollisionObject;
    void Update(const NiUpdateData& kUpdateData);
};
class NiNode : public NiAVObject
{
  public:
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual NiAVObject* GetObjectByName(const NiFixedString& kName);
    char pad20[0x9c - 0x20];
    NiTObjectArray<NiAVObject*> m_kChildList;
};
// LinkObject: resolve the two linked bodies and store their Havok entities in the constraint data.
extern void* __cdecl FUN_00aa13e0(unsigned int size);
extern int DAT_01030bf4;
extern int DAT_010c44e4;
extern int DAT_010c485c;
extern int DAT_012680f8;
extern int DAT_012686d0;
extern int DAT_012681a0;
struct Base_00c8ae60
{
    int* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void FUN_00c87c30();
    Base_00c8ae60()
    {
        FUN_00c87c30();
    }
};
struct Object_00c8ae60 : Base_00c8ae60
{
    static void* operator new(unsigned int bytes)
    {
        return FUN_00aa13e0(bytes);
    }
    Object_00c8ae60()
    {
        vtable = &DAT_01030bf4;
        unk0c = 0;
        unk10 = 0;
        ++DAT_012680f8;
        vtable = &DAT_010c44e4;
        ++DAT_012686d0;
        vtable = &DAT_010c485c;
        ++DAT_012681a0;
    }
};
// Forward a call to every child wrapper of this group's Havok object.
class C8B4D0Wrapper
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Apply(int iArg1, int iArg2);
};
struct C8B4D0Child
{
    int unk00;
    int unk04;
    C8B4D0Wrapper* m_pkWrapper;
};
struct C8B4D0Slot
{
    C8B4D0Child* m_pkChild;
    int unk04;
    int unk08;
    int unk0C;
};
class C8B4D0Counter
{
  public:
    virtual void Unk_00();
    virtual int GetCount();
};
struct C8B4D0HavokGroup
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8B4D0Counter m_kCounter;
    int unk14;
    C8B4D0Slot* m_pkSlots;
};
class C8B4D0Group
{
  public:
    int unk00;
    int unk04;
    C8B4D0HavokGroup* m_pkHavok;

    C8B4D0HavokGroup* GetHavok()
    {
        return this ? m_pkHavok : 0;
    }
    int GetChildCount()
    {
        C8B4D0HavokGroup* pkHavok = GetHavok();
        return pkHavok ? pkHavok->m_kCounter.GetCount() : 0;
    }
    C8B4D0Child* GetChild(int i)
    {
        C8B4D0HavokGroup* pkHavok = GetHavok();
        return pkHavok ? pkHavok->m_pkSlots[i].m_pkChild : 0;
    }

    void ApplyToChildren(int iArg1, int iArg2);
};
SpawnedAllocHolder* FUN_00c85750();
struct C8B8A0Alloc;
struct C8B8A0Array;
void FUN_00c908c0(C8B8A0Alloc* allocator, C8B8A0Array* arr, int capacity, int elemSize);
struct C8B8A0Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(C8B8A0Alloc& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(int));
        }
    }
    void _setSize(C8B8A0Alloc& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        SpawnedAllocHolder* router = FUN_00c85750();
        C8B8A0Alloc* allocator = (C8B8A0Alloc*)router->m_pAllocator;
        _setSize(*allocator, n);
    }
    void clear()
    {
        m_iElementCount = 0;
    }
};
extern __declspec(thread) int g_C8B9E0AllocTag;
struct C8B9E0AllocTagScope
{
    int m_iSaved;

    C8B9E0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_C8B9E0AllocTag;
        g_C8B9E0AllocTag = aiAllocationTag;
    }
    ~C8B9E0AllocTagScope()
    {
        g_C8B9E0AllocTag = m_iSaved;
    }
};
class C8B9E0Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
extern C8B9E0Heap g_kC8B9E0Heap;
template <class T> class C8B9E0Array
{
  public:
    C8B9E0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class C8B9E0Listener
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return g_kC8B9E0Heap.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    C8B9E0Listener() : m_pkOwnerManager(0)
    {}

    void* m_pkOwnerManager;
    C8B9E0Array<void*> m_kAdded;
    C8B9E0Array<void*> m_kRemoved;
};
struct ListAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* data, int bytes);
};
struct ShapeArray
{
    FUN_00c8b000_Item** data;
    int size;
    int capacity;
    ShapeArray() : data(0), size(0), capacity(0x80000000)
    {}
    ~ShapeArray()
    {
        SpawnedAllocHolder* holder = FUN_00c85750();
        ListAllocator* alloc = (ListAllocator*)holder->m_pAllocator;
        size = 0;
        if (!(capacity & 0x80000000))
        {
            alloc->Free(data, (capacity & 0x3fffffff) * 4);
        }
        data = 0;
        capacity = 0x80000000;
    }
    void swap(ShapeArray& other)
    {
        FUN_00c8b000_Item** oldData = data;
        data = other.data;
        other.data = oldData;
        int oldSize = size;
        size = other.size;
        other.size = oldSize;
        int oldCapacity = capacity;
        capacity = other.capacity;
        other.capacity = oldCapacity;
    }
};
unsigned int* __cdecl SwapEndianBlocks(unsigned int* auiData);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern __declspec(thread) int g_iAllocTagC9A;
struct AllocTagScopeC9A
{
    int m_iSaved;

    AllocTagScopeC9A(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagC9A;
        g_iAllocTagC9A = aiAllocationTag;
    }
    ~AllocTagScopeC9A()
    {
        g_iAllocTagC9A = m_iSaved;
    }
};
class ObstacleDataC9A
{
  public:
    virtual ~ObstacleDataC9A();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerC9A
{
  public:
    NiPointerC9A(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerC9A()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};
void __cdecl FreeNodeC9A(void* pvNode);
template <class T> class BSSimpleListC9A
{
  public:
    __declspec(noinline) void Remove(const T& kItem)
    {
        for (BSSimpleListC9A* pkNode = this; pkNode->m_pkNext; pkNode = pkNode->m_pkNext)
        {
            BSSimpleListC9A* pkNext = pkNode->m_pkNext;
            if (pkNext->m_item.m_pObject == kItem.m_pObject)
            {
                pkNode->m_pkNext = pkNext->m_pkNext;
                FreeNodeC9A(pkNext);
                return;
            }
        }
    }

    T m_item;
    BSSimpleListC9A* m_pkNext;
};
struct FUN_00c9a6c0
{
    float time, value1, value2;
    FUN_00c9a6c0();
};
struct TargetFlags
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int flags;
};
struct TargetBody
{
    int unk00, unk04, unk08, unk0c;
    TargetFlags flags;
};
struct TargetLink
{
    int unk00, unk04;
    TargetBody* body;
    unsigned int GetFlags() const
    {
        TargetFlags* info = body ? &body->flags : 0;
        return info ? info->flags : 0;
    }
};
struct TargetExtra
{
    int unk00, unk04, unk08, unk0c;
    TargetLink* link;
    int unk14;
    float start, end;
    float GetStart() const
    {
        return start;
    }
    float GetEnd() const
    {
        return end;
    }
};
struct ExtraList
{
    TargetExtra* FUN_00653290(int* type);
};
struct TargetController
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v35(float time);
    int unk04;
    unsigned short flags;
    unsigned short unk0a;
    float frequency, phase, start, end;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    LargeArray_c9ac00 keys;
    int unk50, unk54;
    unsigned int mode;
    void Reset();
    void FUN_00c9b1a0(FUN_00c9a6c0* key);
};
struct SceneNode;
struct SceneObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SceneNode* AsNode();
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    ExtraList* extras;
    TargetController* FUN_00a5c570(int* type);
};
struct SceneNode : SceneObject
{
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
    SceneObject** children;
    unsigned short capacity, childCount;
};
extern int DAT_01267e64;
struct Node253;
struct HavokObject253
{
    int unk00, unk04, unk08;
    Node253* owner;
};
struct Node253
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual Node253* Clone(void* process);
    int references;
    HavokObject253* object;
};
struct Param5380d0;
struct This5380d0
{
    bool FUN_005380d0(Param5380d0*);
};
void EnableConstraintsAndZeroArrays(void*, void*);
struct ControllerRTTI
{
    const char* name;
    const ControllerRTTI* base;
};
struct ControllerOwner
{
    unsigned int unkCur;
    unsigned int unkValue;
    unsigned int uNewnk;
    unsigned int unk00C;
    unsigned int uTmpnk;
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
    unsigned int unk0D8;
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
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    This5380d0* manager;
};
struct ControllerObject
{
    virtual void slot();
    virtual void slotCur();
    virtual void slotValue();
    virtual void sNewlot();
    virtual void sTmplot();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual unsigned int GetType();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual ControllerOwner* GetOwner();
};
struct ControllerLink
{
    unsigned int unk, unk04;
    void* active;
    ControllerObject* object;
    void Process()
    {
        EnableConstraintsAndZeroArrays(this, active);
    }
    bool IsActive() const
    {
        return active != 0;
    }
    void Update()
    {
        if (IsActive())
            Process();
    }
    void ProcessIfActive()
    {
        if (active)
            EnableConstraintsAndZeroArrays(this, active);
    }
};
struct ControllerFallback
{
    ControllerObject* object;
};
struct IdleController
{
    virtual void slot();
    virtual void DeleteThis();
    virtual const ControllerRTTI* GetRTTI();
    virtual void sNewlot();
    virtual void sTmplot();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void HandleControllerData(This5380d0*);
    virtual void slot28();
    virtual void slot29();
    virtual void slot2A();
    virtual void slot2B();
    virtual void slot2C();
    virtual void slot2D();
    virtual void slot2E();
    virtual void slot2F();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual ControllerLink* GetLink();
    long refs;
    ControllerLink* link;
    ControllerFallback* fallback;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
    bool IsKindOfType(const ControllerRTTI* wanted)
    {
        const ControllerRTTI* type = GetRTTI();
        while (type)
        {
            if (type == wanted)
                return true;
            type = type->base;
        }
        return false;
    }
    void ProcessActive()
    {
        if (link->active)
            link->Process();
    }
    ControllerObject* GetObject()
    {
        return link ? link->object : (fallback ? fallback->object : 0);
    }
};
struct ControllerPtr
{
    IdleController* m_pObject;
    __forceinline ControllerPtr(IdleController* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~ControllerPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ControllerPtr& operator=(const ControllerPtr& other);
};
struct C817D0TlsBlock
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
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int m_2c0;
};
__declspec(thread) C817D0TlsBlock g_c817d0Tls;
// Fallout: New Vegas — FUN_00c85620
// __cdecl aligned-allocation helper: requests an over-sized block from the
// heap object's virtual allocator, aligns the returned pointer up to the
// requested alignment, and stores a small header immediately below the
// aligned pointer: {owner, end, offset-to-raw}.
extern __declspec(thread) int DAT_tls_field;
struct MemoryContextGuard
{
    int previous;
    MemoryContextGuard() : previous(DAT_tls_field)
    {
        DAT_tls_field = 16;
    }
    ~MemoryContextGuard()
    {
        DAT_tls_field = previous;
    }
};
extern "C" void __cdecl operator delete(void*, unsigned int);
struct Elem_c891
{
    int unk00;
    int unk04;
    Elem_c891* unk08;
    Elem_c891* getE() const
    {
        return unk08;
    }
};
struct Heap_c891
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int bytes);
};
struct Arr_c891
{
    Elem_c891** m_data;
    int m_iElementCount;
    int m_cap;
    Arr_c891() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    Elem_c891*& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    ~Arr_c891()
    {
        SpawnedAllocHolder* r = FUN_00c85750();
        Heap_c891* heap = (Heap_c891*)r->m_pAllocator;
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            heap->ReturnMemory(m_data, (m_cap & 0x3fffffff) * 4);
    }
};
void __cdecl CollectTreeResultValues(int, Arr_c891*);
struct AttachObject;
struct AttachData;
struct AttachObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual AttachData* GetData();
    virtual void v38();
    virtual void Add(AttachObject*);
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
    virtual void Set(AttachObject*);
    virtual AttachObject* GetTarget();
    virtual AttachData* GetConstraint();
    int unk04;
    AttachData* owner;
    int unk0c;
    unsigned int flags;
    int unk14;
    unsigned int count;
    int unk1c;
    int unk20;
    AttachData* data24;
    int unk28;
    unsigned int id;
    void FUN_00a29680();
    bool AddOrRemoveConstraint(AttachObject* body, bool add);
};
struct AttachData
{
    unsigned char HasObjectOfType()
    {
        return object08 != 0;
    }
    int unk00;
    int unk04;
    AttachObject* object08;
    AttachObject* object0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    AttachObject* object24;
    int unk28;
    unsigned int id;
};
struct DiagFlag
{
    bool enabled;
    DiagFlag(bool value) : enabled(value)
    {}
    DiagFlag(const DiagFlag& other) : enabled(other.enabled)
    {}
};
struct Alloc8b_c8b090
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int size);
    virtual void ReleaseBlock(void* p, int size);
};
extern __declspec(thread) int g_hkTlsScopeValue;
struct TlsScope_c8b090
{
    int m_old;
    TlsScope_c8b090(int v)
    {
        m_old = g_hkTlsScopeValue;
        g_hkTlsScopeValue = v;
    }
    ~TlsScope_c8b090()
    {
        g_hkTlsScopeValue = m_old;
    }
};
struct hkRefObj_c8b090
{
    virtual void vf0();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(unsigned int size)
    {
        SpawnedAllocHolder* holder = FUN_00c85750();
        Alloc8b_c8b090* alloc = (Alloc8b_c8b090*)holder->m_pAllocator;
        hkRefObj_c8b090* b = (hkRefObj_c8b090*)alloc->AllocateMemoryBlock(static_cast<int>(size));
        b->m_usMemSizeAndFlags = (unsigned short)size;
        return b;
    }
    static void operator delete(void* p, unsigned int size)
    {
        SpawnedAllocHolder* holder = FUN_00c85750();
        Alloc8b_c8b090* alloc = (Alloc8b_c8b090*)holder->m_pAllocator;
        alloc->ReleaseBlock(p, static_cast<int>(size));
    }
    void removeReference();
};
struct C8B540Selected;
class C8B540Selected
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual int GetResult(int iArg);
};
bool __cdecl FUN_00c815b0(C815B0Constraint* pkOther);
struct C90160Matrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};
extern const C90160Matrix DAT_011a9448;
class C90160Derived : public BC88760Base
{
  public:
    C90160Matrix matrix;
    C90160Derived() : matrix(DAT_011a9448)
    {}
    virtual ~C90160Derived();

    void FUN_00c81580(C90160Derived* destination, BC88760CloningProcess& cloning);
    C90160Derived* FUN_00c90160(BC88760CloningProcess& cloning);
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
class RefObject0AA0
{
  public:
    virtual ~RefObject0AA0();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    long m_uiRefCount;
};
template <class T> class NiPointer0AA0
{
  public:
    NiPointer0AA0(const NiPointer0AA0& ptr)
    {
        m_pObject = ptr.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointer0AA0& operator=(const NiPointer0AA0& ptr);
    operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
struct MemoryManager0AA0
{
    void* Allocate(unsigned int uiSize);
};
extern MemoryManager0AA0 g_kMemoryManager0AA0;
class ListNode0AA0
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return g_kMemoryManager0AA0.Allocate(uiSize);
    }
    ListNode0AA0(const NiPointer0AA0<RefObject0AA0>& spRetainedObject) : m_pReferencedObject(spRetainedObject)
    {
        m_pkNext = 0;
    }
    void FUN_00c80aa0(const NiPointer0AA0<RefObject0AA0>& spRetainedObject);

    NiPointer0AA0<RefObject0AA0> m_pReferencedObject;
    ListNode0AA0* m_pkNext;
};
struct MeshMemoryScope
{
    int saved;
    MeshMemoryScope()
    {
        saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 16;
    }
    ~MeshMemoryScope()
    {
        g_tlsBlock.m_2b4 = saved;
    }
};
inline void* __cdecl operator new[](unsigned int size)
{
    return DAT_011f6238.FUN_00aa3e40(size);
}
struct GeometryData
{
    void NiGeometryData_CreateNormals(bool);
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
class NiTriShape : public NiMemObject
{
  public:
    NiTriShape(unsigned short, NiPoint3*, NiPoint3*, void*, void*, unsigned short, unsigned int, unsigned short,
               unsigned short*);
    void SetName(const NiFixedString&);
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
    GeometryData* unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
};
void __cdecl AttachEmissiveMaterial(NiTriShape*, unsigned int, unsigned int, unsigned int);
struct PropertyValue
{
    int value;
    unsigned int extra;
};
struct PropertyEntry
{
    void* key;
    unsigned int flags;
    PropertyValue data;
};
struct PropertyStore
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    PropertyEntry* entries;
    int count;
    PropertyValue FindEntry(void* key, int flags);
};
struct PropertyOwner
{
    unsigned int unknown00, unknown04;
    PropertyStore* store;
    int ReadProperty(void* key);
    int FUN_00c85c80(void* key);
};
__forceinline int PropertyOwner::ReadProperty(void* key)
{
    PropertyStore* object = store;
    int result = 0;
    if (object)
        result = object->FindEntry(key, 0).value;
    return result;
}
struct NiPlane
{
    int unk00;
    int unk04;
    int unk08;

    bool operator==(const NiPlane& other) const;
};
class C8AAResult
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
};
class C8AASub
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    C8AAResult* m_18;
    C8AAResult* m_1c;
};
class C8AAHost
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    C8AASub* m_08;
    C8AAResult* GetA()
    {
        C8AAResult* r;
        if (this && m_08)
            r = m_08->m_18;
        else
            r = 0;
        return r;
    }
    C8AAResult* GetOther()
    {
        C8AAResult* r;
        if (this && m_08)
            r = m_08->m_1c;
        else
            r = 0;
        return r;
    }
    int GetResultValue(char c);
};
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);
SpawnedAllocHolder* FUN_00c85750() throw();
struct C99F10Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiBytes) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiBytes) throw();
};
struct C99F10Array
{
    void** m_ppData;
    int m_uiLogicalSize;
    int m_iCapacity;
    ~C99F10Array() throw()
    {
        SpawnedAllocHolder* pHolder = FUN_00c85750();
        C99F10Allocator* pAlloc = (C99F10Allocator*)pHolder->m_pAllocator;
        m_uiLogicalSize = 0;
        if (!(m_iCapacity & 0x80000000))
        {
            pAlloc->FreeArray(m_ppData, (m_iCapacity & 0x3fffffff) * 4);
        }
        m_ppData = 0;
        m_iCapacity = 0x80000000;
    }
};
struct C99F10Base
{
    virtual ~C99F10Base() throw()
    {}
    int unk04;
};
struct DispatchObject;
typedef int(__thiscall* DispatchAction)(DispatchObject*, void*);
struct DispatchObject
{
    void** vtable;
    void* unk04;
    DispatchObject* unk08;
    int type;
    int Dispatch(void* argument)
    {
        return reinterpret_cast<DispatchAction>(vtable[0x38])(this, argument);
    }
};
typedef void*(__thiscall* GetTarget)(DispatchObject*);
// FUN_00c80090: cdecl, one pointer arg; probes nested object chain.
class ProbeX;
class ProbeY;
class ProbeZ;
class ProbeE;
class ProbeD;
class ProbeC;
class ProbeObj;
extern int DAT_012681c0;
struct PackedPropertyByte
{
    unsigned char value;
    PackedPropertyByte()
    {}
    inline bool operator!=(int rhs) const
    {
        return value != rhs;
    }
};
class ProbeZ
{
  public:
    PackedPropertyByte FUN_00c9bff0() const;
};
class ProbeX
{
  public:
    ProbeY* FUN_00653290(const void* type);
};
class ProbeY
{
  public:
    int unk00;
    int unk04;
    ProbeZ* m_08;
};
struct SelectedBits
{
    unsigned int bits;
    inline operator bool() const
    {
        return bits != 0;
    }
};
class ProbeE
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0c;
    inline SelectedBits SelectedFlag() const
    {
        SelectedBits result = {m_0c & 2};
        return result;
    }
};
class ProbeD
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ProbeX* m_10;
};
class ProbeC
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
    virtual ProbeD* GetD();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ProbeC* m_1c;
};
class ProbeObj
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ProbeC* m_1c;
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
    ProbeC** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
    inline unsigned int ChildCount() const
    {
        return m_a6;
    }
    inline ProbeC* FirstChild() const
    {
        return ChildCount() <= 0 ? 0 : *m_a0;
    }
};
static inline bool CheckBody(ProbeD* body, ProbeObj*& obj)
{
    ProbeX* object = body->m_10;
    if (object)
    {
        ProbeY* rigid = object->FUN_00653290(&DAT_012681c0);
        if (rigid && rigid->m_08)
            return rigid->m_08->FUN_00c9bff0() != 0;
    }
    return false;
}
struct WalkBits_c804
{
    union
    {
        unsigned int raw;
        struct
        {
            unsigned int lo : 7;
            unsigned int hi : 25;
        };
    };
    WalkBits_c804()
    {}
    WalkBits_c804(unsigned int r) : raw(r)
    {}
    void SetLo(unsigned int f)
    {
        lo = f;
    }
};
extern unsigned int DAT_012043f8;
// FUN_00c81890 (unit_a1df186ed60f.cpp) - 95B, /MT /O2 /GS /EHsc /Gy
// v4: extern __declspec(thread) int DAT_tls_0x2c0 (probe-exact a1+64 8b 0d+8b 14 81+8b 82 c0020000);
//     uchar bitfield f6/f0 (probe-exact mov cl/shr/test forms); m_bits word AND per v3 match
extern __declspec(thread) int DAT_tls_0x2c0;
// TLS slot +0x2C0 (module index 0x126fd98)
// ?UpdateWorldLoc@NiAVObject@@QAEXXZ
typedef int(__thiscall* FN_00c81890_VT)(void*);
union U_00c81890
{
    unsigned short m_bits;  // +0xC word member
    struct
    {
        unsigned char f0 : 1;
        unsigned char : 5;
        unsigned char f6 : 1;
        unsigned char : 1;
    } bf;
};
struct E_T
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
    virtual int va4();
    void* m_p4;
    void* m_p8;
    U_00c81890 u_c;

    bool GetBit(int n) const
    {
        return (u_c.m_bits >> n) & 1;
    }
    void ClearBit(int n)
    {
        u_c.m_bits &= ~(1 << n);
    }
    int __thiscall FUN_00c81890();
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct FUN_00cca4e0
{
    void* m_00;
    void* m_04;
    void* m_08;
    int m_0c;
    int m_10;
    FUN_00cca4e0(void* value);
    static void* operator new(unsigned int bytes)
    {
        return FUN_00aa13e0(bytes);
    }
};
struct S00c859e0_holder
{
    void* m_00;
    void* m_04;
};
typedef S00c859e0_holder*(__thiscall* S00c859e0_slot45)(void*, unsigned int*);
extern __declspec(thread) unsigned int t_uiMemContextC877;
inline unsigned int GetMemContextC877()
{
    return t_uiMemContextC877;
}
inline void SetMemContextC877(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextC877 = m_uiGeometryShaderFlags;
}
class AutoMemContextC877
{
  public:
    AutoMemContextC877(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC877();
        SetMemContextC877(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC877()
    {
        SetMemContextC877(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};
struct C89AC0_Owner;
struct C89AC0_Child
{
    int unk00;
    int unk04;
    C89AC0_Owner* m_pSharedOwner;
    void FUN_00c905b0();
    void FUN_00c90510();
};
struct C89AC0_Owner
{
    int unk00;
    C89AC0_Child* m_pChildObject;
    void SetChildObject(C89AC0_Child* child);
};
struct ThreadData674
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
    unsigned int unk0D8;
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
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int context;
};
extern __declspec(thread) ThreadData674 g_threadData;
struct Context674
{
    unsigned int previous;
    Context674()
    {
        previous = g_threadData.context;
        g_threadData.context = 16;
    }
    ~Context674()
    {
        g_threadData.context = previous;
    }
};
struct Input674
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(Input674*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes)
    {
        unsigned int size = bytes;
        position += read(this, data, bytes, &size, 1);
    }
};
struct Stream674
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
    Input674* input;
    Input674* Input()
    {
        return input;
    }
};
struct Heap674
{
    virtual void v0();
    virtual void* Allocate(unsigned int);
};
struct Base674
{
    virtual ~Base674();
    unsigned short size;
    unsigned short flags;
    static void* operator new(unsigned int size)
    {
        SpawnedAllocHolder* r = FUN_00c85750();
        Heap674* heap = (Heap674*)r->m_pAllocator;
        Base674* b = (Base674*)heap->Allocate(size);
        b->size = (unsigned short)size;
        return b;
    }
    static void operator delete(void* memory);
};
extern "C" void _ReadWriteBarrier(void);
struct AllocLocal;
inline void DeallocateLocal(AllocLocal* a, void* p, int const& n);
struct TypeInfoLocal
{
    const char* name;
    TypeInfoLocal* base;
};
extern TypeInfoLocal g_012682e8, g_012682dc, g_012686a0, g_01268264;
struct ShapeLocal
{
    virtual void v0();
    virtual void v1();
    virtual TypeInfoLocal* GetType();
    int reference;
    ShapeLocal* object;
    ShapeLocal* FUN_00653290(const TypeInfoLocal*);
    bool IsType(const TypeInfoLocal* type)
    {
        const TypeInfoLocal* current = GetType();
        while (current)
        {
            if (current == type)
                return true;
            current = current->base;
        }
        return false;
    }
};
struct WrapperLocal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    static void* operator new(unsigned int);
    WrapperLocal(ShapeLocal*);
};
struct AllocLocal;
struct AllocLocal
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*, int);
    void Clear(SpawnedPtrArray& arr)
    {
        int cap = arr.m_uiCapacity;
        arr.m_uiCount = 0;
        if (!(cap & 0x80000000))
        {
            void* p = arr.m_pData;
            DeallocateLocal(this, p, cap & 0x3fffffff);
        }
        arr.m_pData = 0;
        arr.m_uiCapacity = 0x80000000;
    }
};
inline void DeallocateLocal(AllocLocal* a, void* p, int const& n)
{
    a->Free(p, n * 4);
}
void FUN_00c908c0(void*, SpawnedPtrArray*, int, int);
template <class T> inline void ConstructLocal(T* dest, int n, const T& value)
{
    for (int k = 0; k < n; ++k)
        dest[k] = value;
}
struct ArrayLocal : SpawnedPtrArray
{
    void Clear(AllocLocal& allocator)
    {
        m_uiCount = 0;
        if ((int)m_uiCapacity >= 0)
            allocator.Free(m_pData, (m_uiCapacity & 0x3fffffff) * 4);
        m_pData = 0;
        m_uiCapacity = 0x80000000;
    }
    void Reserve(void* allocator, int count)
    {
        int capacity = m_uiCapacity & 0x3fffffff;
        if (capacity < count)
        {
            int desired = capacity * 2;
            if (count >= desired)
                desired = count;
            FUN_00c908c0(allocator, this, desired, 4);
        }
    }
    void Append(SpawnedAllocHolder* holder, ShapeLocal* raw)
    {
        if (m_uiCount == (m_uiCapacity & 0x3fffffff))
            ResizeAudioStream(holder->m_pAllocator, this, 4);
        ConstructLocal(m_pData + m_uiCount, 1, (void*)raw);
        ++m_uiCount;
    }
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct S00c90090_Obj
{
    virtual void S00c90090_v0();
    virtual void S00c90090_v1();
    int m_ref;
};
struct S00c90090_Ptr
{
    S00c90090_Obj* p;
    S00c90090_Ptr(S00c90090_Obj* q) : p(q)
    {
        if (p)
            InterlockedIncrement((long volatile*)&p->m_ref);
    }
    ~S00c90090_Ptr()
    {
        if (p)
        {
            if (!InterlockedDecrement((long volatile*)&p->m_ref))
                p->S00c90090_v1();
        }
    }
};
struct S00c90090_Self
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C(int i);
    int m_p4;
    int m_p8;
    int m_pc;
    S00c90090_Obj* m_p10;
    int m_p14;
    float m_f18;
    float m_f1c;
    int m_p20;
    int m_p24;
    float GetF1C() const
    {
        return m_f1c;
    }
    void SetF1C(float f)
    {
        m_f1c = f;
    }
    float GetF18() const
    {
        return m_f18;
    }
    void SetF18(float f)
    {
        m_f18 = f;
    }
    void FUN_00c90090(S00c90090_Self* src);
};
struct SpawnedAllocHolder;
SpawnedAllocHolder* __cdecl FUN_00c85750();
extern "C" double clobber_c929e0(double);
static __declspec(noinline) void FUN_00c927c0(void* p, void* q)
{
    volatile int sink = 0;
    char* s = (char*)FUN_00c85750();
    if (p)
        sink = 1;
    if (q)
        sink = 2;
    clobber_c929e0(1.0);
    sink += s[0];
    if (p)
        sink = 3;
    if (q)
        sink = 4;
    if (p)
        sink = 5;
}
static __declspec(noinline) void InvokeOnAllOwners(void* a, void* b)
{
    volatile int sink = 0;
    if (a)
        sink = 1;
    clobber_c929e0(2.0);
    if (a)
        sink = 2;
    if (b)
        sink = 3;
}
struct RefObjectC9
{
    virtual void Unknown();
    virtual void Destroy();
    volatile long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            Destroy();
    }
};
struct SmartC9
{
    RefObjectC9* pointer;
    SmartC9(RefObjectC9* p = 0) : pointer(p)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    SmartC9(const SmartC9& other) : pointer(other.pointer)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    ~SmartC9()
    {
        if (pointer)
            pointer->DecRefCount();
    }
    SmartC9& operator=(const SmartC9& other)
    {
        if (pointer != other.pointer)
        {
            if (pointer)
                pointer->DecRefCount();
            pointer = other.pointer;
            if (pointer)
                pointer->IncRefCount();
        }
        return *this;
    }
};
struct ListC9
{
    SmartC9 item;
    ListC9* next;
    ListC9(const SmartC9& p) : item(p), next(0)
    {}
    __declspec(noinline) void FUN_00631540(const SmartC9& p)
    {
        if (!p.pointer)
            return;
        if (item.pointer)
        {
            ListC9* node = new ListC9(item);
            node->next = next;
            next = node;
        }
        item = p;
    }
};
struct C9A6E0Entry
{
    float fA;
    float fB;
    float fC;
    void Set(float a, float b, float c)
    {
        fA = a;
        fB = b;
        fC = c;
    }
    void Set3(float a, float p)
    {
        float z = (float)(p / 100.0);
        fA = a;
        fB = z;
        fC = z;
    }
};
static inline float Pct(float f)
{
    return (float)(f / 100.0);
}
static inline float Pct2(int f)
{
    return (float)(f / 100.0);
}
extern __declspec(thread) int DAT_012722b4;
struct TlsGuardS00c9_t
{
    int m_saved;

    TlsGuardS00c9_t()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }

    ~TlsGuardS00c9_t()
    {
        DAT_012722b4 = m_saved;
    }
};
#include <stdlib.h>
extern unsigned __int64 selected_target_masks[];
extern unsigned int DAT_01268078[];
__forceinline bool Mask135(unsigned int a, unsigned int b)
{
    return (DAT_01268078[(a >> 8) & 31] & (1 << ((b >> 8) & 31))) != 0;
}
bool FUN_00c84740(unsigned int a, unsigned int b);
// @fnv 0x00c85d20
struct MemoryCategoryScope_00c89dd0
{
    int previous;
    MemoryCategoryScope_00c89dd0(int* block) : previous(block[0x2b4 / 4])
    {
        block[0x2b4 / 4] = 16;
    }
    ~MemoryCategoryScope_00c89dd0()
    {
        previous = 0;
    }
};
struct PendingAllocation_00c89dd0
{
    void* pointer;
    PendingAllocation_00c89dd0(void* value) : pointer(value)
    {}
    ~PendingAllocation_00c89dd0()
    {
        pointer = 0;
    }
};
SpawnedAllocHolder* FUN_00c85750();
#include <string.h>
extern char DAT_010c6b0c[];
void* __cdecl NiMalloc(unsigned int size);
struct NiTLargeArrayStub
{
    void* m_vtbl;
    void** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;

    NiTLargeArrayStub(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_vtbl = &DAT_010c6b04;
        m_uiMaxSize = uiMaxSize;
        m_uiGrowBy = uiGrowBy;
        m_uiSize = 0;
        m_uiESize = 0;
        if (m_uiMaxSize > 0)
            m_pBase = (void**)NiMalloc(sizeof(void*) * m_uiMaxSize);
        else
            m_pBase = 0;
    }
};
struct NiTLargePrimitiveArrayStub : NiTLargeArrayStub
{
    NiTLargePrimitiveArrayStub(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : NiTLargeArrayStub(uiMaxSize, uiGrowBy)
    {
        m_vtbl = DAT_010c6b0c;
    }
    ~NiTLargePrimitiveArrayStub();
};
extern int DAT_011f4428;
struct S00c81c50_Obj;
struct S00c81c50_Arr
{
    S00c81c50_Obj** data;
    unsigned short cap;
    unsigned short size;
    unsigned short esize;
    unsigned short grow;
    unsigned short GetSize() const
    {
        return size;
    }
    S00c81c50_Obj* GetAt(unsigned int i) const
    {
        return data[i];
    }
};
struct S00c81c50_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S00c81c50_Obj* IsSceneNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S00c81c50_Obj* collision;
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
    S00c81c50_Arr children;

    S00c81c50_Obj* FUN_00653290(int* rtti);

    __forceinline S00c81c50_Obj* GetCollision()
    {
        S00c81c50_Obj* c = collision;
        if (!c)
            return 0;
        return c->FUN_00653290(&DAT_01267e64);
    }
    __forceinline S00c81c50_Obj* FirstNode()
    {
        S00c81c50_Obj* c = children.size > 0 ? children.data[0] : 0;
        if (!c)
            return 0;
        return c->FUN_00653290(&DAT_011f4428);
    }
};
struct S00c81c50_Ptr
{
    S00c81c50_Obj* m_p;
    S00c81c50_Ptr(S00c81c50_Obj* p) : m_p(p)
    {}
    S00c81c50_Ptr& operator=(S00c81c50_Obj* p)
    {
        m_p = p;
        return *this;
    }
    operator S00c81c50_Obj*() const
    {
        return m_p;
    }
};
void* __cdecl FUN_00c81c50(S00c81c50_Obj* pkNode);
extern __declspec(thread) int g_tlsMemContext;
struct S00c89ec0_Scope
{
    int saved;
    S00c89ec0_Scope()
    {
        saved = g_tlsMemContext;
        g_tlsMemContext = 0x10;
    }
    ~S00c89ec0_Scope()
    {
        g_tlsMemContext = saved;
    }
};
struct S00c89ec0_Res
{
    bool FUN_00c68d50(int key);
};
struct S00c89ec0_Owner
{
    int unk00;
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
    S00c89ec0_Res* unk350;
    S00c89ec0_Res* GetRes()
    {
        return unk350;
    }
};
__declspec(noinline) int __stdcall FUN_00c84ec0(void* apObject);
struct ShareChildShape
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
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
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual bool V52(int a1);
};
struct ShareChildObject
{
    int unk0;
    int unk4;
    ShareChildShape* shape;
};
struct ShareChildEntry
{
    ShareChildObject* pObj;
    int unk4;
    int unk8;
    int unkC;
};
struct ShareListData : hkpListShapeStub
{
    int unk14;
    ShareChildEntry* arr;
};
class ListShapeSharingView : public bhkListShapeStub
{
  public:
    __forceinline ShareListData* GetNode()
    {
        return this != 0 ? (ShareListData*)m_pHavokObject : 0;
    }

    unsigned char FUN_00c8b440(int a1);
};

#include <xmmintrin.h>

inline float multiplyValue(float a, float b)
{
    return a * b;
}
inline void multiplyRef(float& a, float b)
{
    a *= b;
}
class ScaleOwner
{
  public:
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

    float unk70;
    float unk74;
    float unk78;
    float unk7C;
    float unk80;
    float unk84;
    float unk88;
    float unk8C;
    float unk90;
    float unk94;
    float unk98;
    float unk9C;

    ::__m128 unkA0;
    float unkB0;

    void bhkRigidBodyCinfo_Scale(float scale);
};

// @f3 0x008fe5c0 (community match, verified in this file)
struct __declspec(align(16)) ScaleVector { float x,y,z,w; __forceinline void Set(float value){x=y=z=w=value;} };
// pdb: bhkRigidBodyCinfo::Scale | bhkRigidBody.obj | fnv360_0822_retail, objrun + bridge(call_gap|call_dedup), high
void ScaleOwner::bhkRigidBodyCinfo_Scale(float scale)
{
    ScaleVector cubic;
    cubic.Set(scale * scale * scale);

    float* a0 = (float*)&unkA0;
    a0[0] *= scale;
    a0[1] *= scale;
    multiplyRef(a0[2],scale);
    a0[3] *= scale;

    float* current = &unk80;
    int count = 3;

    do
    {
        current[-4] *= cubic.w;
        current[0] *= cubic.w;
        current[4] *= cubic.w;
        ++current;
    } while (--count != 0);

    unkB0 *= scale;
}

