#include "f3_common.h"
// src/staging/blk_00cc0000_o2_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00ccc440: the skeleton of src/staging/blk_00cc0000_o2.cpp
// with declarations corrected to what the original code does (unit: struct MM { void Deallocate(void*); }; -> struct MM { void Deallocate(void*); void* Allocate(unsigned ). Move the function to its real unit once
// that unit declares it this way.

// src/staging/blk_00cc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern "C" void* DAT_010c9314;
extern "C" void __cdecl _delete(void* p, int flags);
struct NiStream
{
    unsigned int ReadUnsignedInteger();
};
struct NiExtraData
{
    void LoadBinary(NiStream&);
};
struct NiStream;
extern "C" void NiFreeAlias(void*);
void __cdecl operator delete(void* p, unsigned int size);
void __cdecl operator delete(void* p, unsigned int size);
struct MemoryManager
{
    void Deallocate(void*);
};
struct MM
{
    void Deallocate(void*);
    void* Allocate(unsigned int size);
};
extern MM g_memoryManager;
void __cdecl FUN_00cc8ce0();
void __cdecl operator delete(void* p, unsigned int size);
extern "C" void __cdecl _delete(void*, int);
extern "C" void __cdecl bhkConstraintChain();
void __cdecl _delete(void*, unsigned int);
void __cdecl operator delete(void* p, unsigned int size);
void __cdecl operator delete(void* p, unsigned int size);
extern "C" void __cdecl _delete(void*, int);
void __cdecl NiFreeAlias(void* p);
extern MM g_memoryManager;
extern int DAT_0126860c;
extern "C" void __cdecl bhkConstraintChain();
extern "C" void __cdecl _delete(void*, int);
extern int DAT_010ca4dc;
extern int DAT_0126866c;
void __stdcall SetContactNormal(int a, int b);
void __stdcall SetContactNormal(int a, int b);
struct bhkLimitedHingeVector
{
    void __thiscall FUN_004b4db0(const float*);
};
struct MyObj
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
};
struct OutS
{
    bhkLimitedHingeVector m_kPointA;
    bhkLimitedHingeVector m_kPointB;
    bhkLimitedHingeVector m_iThirdValue;
};
void __fastcall bhkConvexShape_CopyCinfo(MyObj* self, int, OutS* out);
struct FUN_00cce990
{
    void* m_p;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cce990();
    static void* __cdecl operator new(unsigned int size);
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int size);
};
extern int DAT_0102016c;
extern int DAT_010c5ef4;
extern int DAT_010c955c;
extern int DAT_01268154;
extern int DAT_01268194;
extern int DAT_012685ac;
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};
struct S_00cb79d0_Base
{
    void* m_pVtable;
    unsigned int m_uiField1;
    unsigned int m_uiField2;
    S_00cb79d0_Base();
};
struct DerivedStandin : A51BF0Base, S_00cb79d0_Base
{
    unsigned int m_uiField3;

    DerivedStandin() : S_00cb79d0_Base()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0102016c);
        m_uiField3 = 0;
        DAT_01268154 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c5ef4);
        DAT_01268194 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c955c);
        DAT_012685ac += count;
    }
};
extern int DAT_010c9af0;
struct NiPoint3
{
    float x;
    float y;
    float z;

    char* __thiscall FUN_00a59af0(char const* name);
};
typedef NiPoint3 NiPoint3_local;
struct hkVector4
{
    float x;
    float y;
    float z;
    float w;
};
struct StrArr
{
    void* m_pVtable;
    void* m_pData;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    unsigned char m_pad000C;
    unsigned short m_usIncrement;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};
extern int DAT_010c9d60;
extern "C" void __cdecl _delete(void* p, int flags);
extern "C" void __cdecl _delete(void* p, int flags);
class CC1AD0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CC1AD0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CC1AD0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
class CC1AD0Object;
class CC1AD0Stream
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
    virtual void SaveLinkID(CC1AD0Object* pkObject);

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
    CC1AD0BinaryStream* m_pBackingStream;
};
template <class T>
inline void CC1AD0BinaryStreamSave(CC1AD0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void CC1AD0SaveBinary(CC1AD0Stream& kStream, const T& value)
{
    CC1AD0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct ArrayRefObject
{
    virtual void vf0();
    virtual void DeleteThis();
    long volatile refs;
    void DecRef()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
    void AcquireReference()
    {
        InterlockedIncrement(&refs);
    }
};
struct RefBool
{
    bool value;
    RefBool(bool v) : value(v)
    {}
    operator bool() const
    {
        return value;
    }
};
struct ArrayRefPtr
{
    ArrayRefObject* ptr;
    ArrayRefPtr() : ptr(0)
    {}
    ~ArrayRefPtr()
    {
        if (ptr)
            ptr->DecRef();
    }
    RefBool operator!=(ArrayRefObject* other) const
    {
        return ptr != other;
    }
    ArrayRefPtr& operator=(const ArrayRefPtr& rhs)
    {
        if (ptr != rhs.ptr)
        {
            if (ptr)
                ptr->DecRef();
            ptr = rhs.ptr;
            if (ptr)
                ptr->AcquireReference();
        }
        return *this;
    }
};
void __cdecl FUN_00aa10f0(void*);
struct FUN_00cc1e40_tls
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
extern __declspec(thread) FUN_00cc1e40_tls g_tls_00cc1e40;
struct TlsFlagGuard_00cc1e40
{
    unsigned int m_saved;
    TlsFlagGuard_00cc1e40()
    {
        m_saved = g_tls_00cc1e40.m_2b4;
        g_tls_00cc1e40.m_2b4 = 0x10;
    }
    ~TlsFlagGuard_00cc1e40()
    {
        g_tls_00cc1e40.m_2b4 = m_saved;
    }
};
void __cdecl FUN_00aa10f0(void* apMemory);
struct Member_00cc1e40
{
    virtual void unk00();
    void* m_04;
    void Destroy();
    ~Member_00cc1e40()
    {
        void* p = m_04;
        FUN_00aa10f0(p);
    }
};
struct FUN_00cc1d80_object
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    FUN_00cc1d80_object();
    static void* __cdecl operator new(unsigned int bytes);
    void __thiscall AssignFixedString(void* value);
};
extern __declspec(thread) int g_iCC1F80AllocTag;
struct BCC1F80AllocTagScope
{
    int m_iSaved;

    BCC1F80AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC1F80AllocTag;
        g_iCC1F80AllocTag = aiAllocationTag;
    }
    ~BCC1F80AllocTagScope()
    {
        g_iCC1F80AllocTag = m_iSaved;
    }
};
class BCC1F80StringArray
{
  public:
    virtual ~BCC1F80StringArray();
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
extern "C" __declspec(thread) unsigned int g_tlsMode;
struct ThreadModeGuard
{
    unsigned int previous;
    ThreadModeGuard() : previous(g_tlsMode)
    {
        g_tlsMode = 16;
    }
    ~ThreadModeGuard()
    {
        g_tlsMode = previous;
    }
};
void* FUN_00aa13e0(unsigned int size);
struct ThreadHeapState
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};
extern __declspec(thread) ThreadHeapState g_threadHeapState;
struct TlsHeapGuard
{
    unsigned int saved;
    TlsHeapGuard()
    {
        saved = g_threadHeapState.m_2b4;
        g_threadHeapState.m_2b4 = 0x10;
    }
    ~TlsHeapGuard()
    {
        g_threadHeapState.m_2b4 = saved;
    }
};
class SpawnedThing
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
    static void* operator new(unsigned int size);
    SpawnedThing();
};
void* SpawnedThing::operator new(unsigned int size)
{
    return FUN_00aa13e0(size);
}
void* __cdecl FUN_00aa13e0(unsigned int size);
struct RefObject24_b9018
{
    char m00[0x18];
    RefObject24_b9018();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
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
    int m_2b4;
};
extern __declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t(int saved)
    {
        m_saved = saved;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
void FUN_00c876f0();
void FUN_00c87700();
class SpawnedObject_t
{
  public:
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    void* operator new(unsigned int size);
    SpawnedObject_t();
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
class FUN_00cc2a00_alloc
{
  public:
    unsigned char* Alloc(unsigned int size);
};
extern FUN_00cc2a00_alloc DAT_011f6238;
struct Col4
{
    float r, g, b, a;
    Col4& operator*=(float s)
    {
        r *= s;
        g *= s;
        b *= s;
        a *= s;
        return *this;
    }
};
struct S_00cc2d20_result
{
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    Col4 m_kPointA;
    Col4 m_kPointB;
};
struct S_00cc2d20_argument
{
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    float m_f10;
};
struct S_00cc2d20_class
{
    virtual void* v00(char*)
    {
        return 0;
    }
    virtual void* v01(char*)
    {
        return 0;
    }
    virtual void* v02(char*)
    {
        return 0;
    }
    virtual void* v03(char*)
    {
        return 0;
    }
    virtual void* v04(char*)
    {
        return 0;
    }
    virtual void* v05(char*)
    {
        return 0;
    }
    virtual void* v06(char*)
    {
        return 0;
    }
    virtual void* v07(char*)
    {
        return 0;
    }
    virtual void* v08(char*)
    {
        return 0;
    }
    virtual void* v09(char*)
    {
        return 0;
    }
    virtual void* v10(char*)
    {
        return 0;
    }
    virtual void* v11(char*)
    {
        return 0;
    }
    virtual void* v12(char*)
    {
        return 0;
    }
    virtual void* v13(char*)
    {
        return 0;
    }
    virtual void* v14(char*)
    {
        return 0;
    }
    virtual void* v15(char*)
    {
        return 0;
    }
    virtual void* v16(char*)
    {
        return 0;
    }
    virtual void* v17(char*)
    {
        return 0;
    }
    virtual void* v18(char*)
    {
        return 0;
    }
    virtual void* v19(char*)
    {
        return 0;
    }
    virtual void* v20(char*)
    {
        return 0;
    }
    virtual void* v21(char*)
    {
        return 0;
    }
    virtual void* v22(char*)
    {
        return 0;
    }
    virtual void* v23(char*)
    {
        return 0;
    }
    virtual void* v24(char*)
    {
        return 0;
    }
    virtual void* v25(char*)
    {
        return 0;
    }
    virtual void* v26(char*)
    {
        return 0;
    }
    virtual void* v27(char*)
    {
        return 0;
    }
    virtual void* v28(char*)
    {
        return 0;
    }
    virtual void* v29(char*)
    {
        return 0;
    }
    virtual void* v30(char*)
    {
        return 0;
    }
    virtual void* v31(char*)
    {
        return 0;
    }
    virtual void* v32(char*)
    {
        return 0;
    }
    virtual void* v33(char*)
    {
        return 0;
    }
    virtual void* v34(char*)
    {
        return 0;
    }
    virtual void* v35(char*)
    {
        return 0;
    }
    virtual void* v36(char*)
    {
        return 0;
    }
    virtual void* v37(char*)
    {
        return 0;
    }
    virtual void* v38(char*)
    {
        return 0;
    }
    virtual void* v39(char*)
    {
        return 0;
    }
    virtual void* v40(char*)
    {
        return 0;
    }
    virtual void* v41(char*)
    {
        return 0;
    }
    virtual void* v42(char*)
    {
        return 0;
    }
    virtual void* v43(char*)
    {
        return 0;
    }
    virtual void* v44(char*)
    {
        return 0;
    }
    virtual S_00cc2d20_result* v45(char*)
    {
        return 0;
    }

    void __thiscall ClonePhysicsData(void* arg1, void* arg2);
    void __thiscall FUN_00cc2d20(void* arg1, S_00cc2d20_argument* arg2);
};
typedef unsigned int CC2F90size_t;
struct CC2F90MemoryManager
{
    void* Allocate(unsigned int uiSize);
};
extern CC2F90MemoryManager g_CC2F90MemoryManager;
extern __declspec(thread) int g_CC2F90AllocTag;
struct CC2F90AllocTagScope
{
    int m_iSaved;

    CC2F90AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CC2F90AllocTag;
        g_CC2F90AllocTag = aiAllocationTag;
    }
    ~CC2F90AllocTagScope()
    {
        g_CC2F90AllocTag = m_iSaved;
    }
};
inline void* CC2F90AlignedAlloc(unsigned int uiSize)
{
    char* pcMem = (char*)g_CC2F90MemoryManager.Allocate(uiSize);
    unsigned char ucOffset = (unsigned char)(16 - ((unsigned char)(unsigned int)pcMem & 0xf));
    pcMem += ucOffset;
    pcMem[-1] = ucOffset;
    return pcMem;
}
struct CC2F90Child
{
    CC2F90Child();

    static void* operator new(CC2F90size_t, void* pvMem)
    {
        return pvMem;
    }
};
extern int DAT_012685b8;
void __cdecl FUN_00aa1460(void* p, unsigned int size);
extern float DAT_01267e30;
struct CC3320Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_afPivot[4];
    float m_fMinimum;
    float m_fMaximum;
};
struct CC3320Vector
{
    void FUN_004b4db0(const float* pfValues);
};
struct CC3320Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC3320Vector m_kPivot;
    int unk14;
    int unk18;
    int unk1C;
    float m_fMinimum;
    float m_fMaximum;
    bool m_bStreamFlag;
};
class CC3320Base
{
  public:
    void GetInfo(CC3320Info* pkInfo);
};
class CC3320Constraint : public CC3320Base
{
  public:
    int unk00;
    int unk04;
    CC3320Data* m_pUserData;

    static const float* GetPivot(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_afPivot : &DAT_01267e30;
    }
    static float GetMax(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_fMaximum : 0.0f;
    }
    static float GetMin(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_fMinimum : 0.0f;
    }

    void FUN_00cc3320(CC3320Info* pkInfo);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct PacketReader
{
    void __thiscall FUN_00c868b0(void* context);
    void __thiscall ReadPacketWithByteSwap(void* context);
};
typedef unsigned int*(__thiscall* GetPacketBlock)(PacketReader*, unsigned char*);
extern int DAT_012685c4;
extern int DAT_010c970c;
extern int DAT_012685c4;
struct DerivedStandin2 : A51BF0Base, S_00cb79d0_Base
{
    unsigned int m_uiField3;

    DerivedStandin2() : S_00cb79d0_Base()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0102016c);
        m_uiField3 = 0;
        DAT_01268154 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c5ef4);
        DAT_01268194 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c970c);
        DAT_012685c4 += count;
    }
};
inline void CC4400Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}
extern int g_ctorCountA;
extern int g_ctorCountD;
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
    ChainA_cls()
    {
        m_0c = 0;
        g_ctorCountA += 1;
    }
};
struct SpawnedObject : public ChainA_cls
{
    virtual void unkD2();
    SpawnedObject()
    {
        g_ctorCountD += 1;
    }
};
struct S_00cc4b90_Tls
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
    int ctx;
};
__declspec(thread) S_00cc4b90_Tls DAT_tls;
struct S_00cc4b90_Ctx
{
    int saved;
    __forceinline S_00cc4b90_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00cc4b90_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};
struct S_00cc4b90_Alloc
{
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00cc4b90_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00cc4b90_Alloc* unk10;
    S_00cc4b90_Alloc& heap()
    {
        return *unk10;
    }
};
S_00cc4b90_Router* FUN_00c85750() throw();
extern float DAT_01017b78;
struct S_00cc4b90_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00cc4b90_RefObj();
    void* operator new(unsigned int n)
    {
        S_00cc4b90_RefObj* b = static_cast<S_00cc4b90_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*)
    {}
};
struct S_00cc4b90_Base : S_00cc4b90_RefObj
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00cc4b90_Base(int a);
};
struct __declspec(novtable) S_00cc4b90_Mid : S_00cc4b90_Base
{
    float f20;
    S_00cc4b90_Mid() : S_00cc4b90_Base(0), f20(DAT_01017b78)
    {}
};
struct S_00cc4b90_Obj : S_00cc4b90_Mid
{
    unsigned char b24;
    unsigned char b25;
    S_00cc4b90_Obj()
    {
        b24 = 0;
        b25 = 0;
    }
};
struct FUN_00cc4e90_stream;
typedef unsigned int(__cdecl* FUN_00cc4e90_readfn)(FUN_00cc4e90_stream* s, void* dst, unsigned int size,
                                                   unsigned int* outCount, unsigned int count);
struct FUN_00cc4e90_stream
{
    int unk00;
    unsigned int m_04;
    int unk08;
    FUN_00cc4e90_readfn m_0c;
};
struct BinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_vContactPosition;
    void* m_pOwnerObject;
    int(__cdecl* m_write)(BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* data, unsigned int count)
    {
        unsigned int actualCount = count;
        m_vContactPosition += m_write(this, data, count, &actualCount, 1);
    }
};
struct StreamContext
{
    BinaryStream* OutputStream()
    {
        return *reinterpret_cast<BinaryStream**>(reinterpret_cast<unsigned char*>(this) + 0x250);
    }
};
extern int DAT_012685f4;
extern int DAT_0108febc;
extern int DAT_010c52bc;
extern int DAT_01268188;
extern int DAT_012685f4;
struct CC5930_Base
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiData08;
    CC5930_Base();
    static void* __cdecl operator new(unsigned int size);
};
struct CC5930_Obj : CC5930_Base
{
    unsigned int m_uiData0C;

    CC5930_Obj()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0108febc);
        m_uiData0C = 0;
        DAT_01268188 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c52bc);
        DAT_012685f4 += count;
    }
};
struct CC5D40BinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(CC5D40BinaryStream* pkStream, void* pvBuffer, unsigned int uiSize, unsigned int* puiSizes,
                              unsigned int ItemUpdateArray);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};
class CC5D40Stream
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
    CC5D40BinaryStream* m_pUnderlyingStream;
};
template <class T> inline void CC5D40BinaryStreamLoad(CC5D40BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void CC5D40LoadBinary(CC5D40Stream& kStream, T& value)
{
    CC5D40BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
class CC5DD0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CC5DD0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CC5DD0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
class CC5DD0Object;
class CC5DD0Stream
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
    virtual void SaveLinkID(CC5DD0Object* pkObject);

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
    CC5DD0BinaryStream* m_pBackingStream;
};
template <class T>
inline void CC5DD0BinaryStreamSave(CC5DD0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void CC5DD0SaveBinary(CC5DD0Stream& kStream, const T& value)
{
    CC5DD0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
// FUN_00cc74d0 : a one-line function - getter
// FUN_00cc75b0: thiscall, one stack arg (int a1).
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct NiBinaryStreamSI
{
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamSI* pThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, 0, 0);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
template <class T> inline void NiStreamLoadBinarySI(NiBinaryStreamSI& kBinStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.BinaryRead(&value, uiSize, &uiSize, 1);
}
struct hkVector4SI
{
    float x;
    float y;
    float z;
    float w;
};
struct hkRotationSI
{
    hkVector4SI m_kColumn0;
    hkVector4SI m_kColumn1;
    hkVector4SI m_kColumn2;
};
struct hkTransformSI
{
    hkRotationSI m_rotation;
    hkVector4SI m_vTranslation;
};
void __cdecl SwapRotHelper(hkTransformSI* pkTransform);
inline void Swap32SI(void* p)
{
    *(unsigned int*)p = _byteswap_ulong(*(unsigned int*)p);
}
inline void SwapVector4SI(hkVector4SI* v)
{
    Swap32SI(&v->x);
    Swap32SI(&v->y);
    Swap32SI(&v->z);
    Swap32SI(&v->w);
}
inline void SwapTransformSI(hkTransformSI* t)
{
    SwapVector4SI(&t->m_vTranslation);
    SwapRotHelper(t);
}
extern int DAT_01268624;
struct CpuOpaque;
extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
struct __declspec(novtable) S_00cc7dc0_Root
{
    unsigned int unk04;
    unsigned int unk08;
    int unk0c;
    S_00cc7dc0_Root()
    {
        Initialize();
        unk0c = 0;
    }
    virtual ~S_00cc7dc0_Root();
    void Initialize();
};
struct S_00cc7dc0_A : S_00cc7dc0_Root
{
    S_00cc7dc0_A()
    {
        DAT_01268188++;
    }
    virtual ~S_00cc7dc0_A();
};
struct S_00cc7dc0_B : S_00cc7dc0_A
{
    S_00cc7dc0_B()
    {
        DAT_01268f74++;
    }
    virtual ~S_00cc7dc0_B();
};
extern __declspec(thread) int g_iCC8770AllocTag;
struct BCC8770AllocTagScope
{
    int m_iSaved;

    BCC8770AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC8770AllocTag;
        g_iCC8770AllocTag = aiAllocationTag;
    }
    ~BCC8770AllocTagScope()
    {
        g_iCC8770AllocTag = m_iSaved;
    }
};
class BCC8770RefObject
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BCC8770RefObject();
    virtual ~BCC8770RefObject();

    int unk04;
    int unk08;
};
class BCC8770Shape : public BCC8770RefObject
{
  public:
    BCC8770Shape() : m_pkShape(0)
    {
        ms_uiInstances++;
    }
    virtual ~BCC8770Shape();

    void* m_pkShape;

    static unsigned int ms_uiInstances;
};
class BCC8770DerivedShape : public BCC8770Shape
{
  public:
    BCC8770DerivedShape()
    {
        ms_uiInstances++;
    }
    virtual ~BCC8770DerivedShape();

    static unsigned int ms_uiInstances;
};
extern __declspec(thread) int g_tlsMemContext;
struct SerializationMemoryContext
{
    int previous;
    SerializationMemoryContext() : previous(g_tlsMemContext)
    {
        g_tlsMemContext = 16;
    }
    ~SerializationMemoryContext()
    {
        g_tlsMemContext = previous;
    }
};
inline void AppendConstraintString(StrArr* strings, char* text)
{
    unsigned int index = strings->m_usElementCount;
    if (index >= strings->m_usSize)
    {
        strings->SetSize(index + strings->m_usIncrement);
    }
    strings->SetAt(index, text);
}
struct S_cc8ce0_Base
{
    virtual ~S_cc8ce0_Base();
    void FUN_00c876a0();
};
struct FUN_00cc8ce0 : S_cc8ce0_Base
{
    ~FUN_00cc8ce0();
};
struct NiBinaryStreamStandIn
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStreamStandIn* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    template <class T> unsigned int Write(const T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, sizeof(T), &uiSize, 1);
    }
    template <class T> unsigned int Write(const T* pArray, unsigned int ItemUpdateArray)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pArray, sizeof(T) * ItemUpdateArray, &uiSize, 1);
    }
};
struct NiStreamImpl
{
    char pad[0x250];
    NiBinaryStreamStandIn* m_pBackingStream;
};
template <class T> inline void SerializeValue(NiStreamImpl& stream, const T& value)
{
    stream.m_pBackingStream->Write(&value);
}
void __cdecl FUN_00cf0cf0(NiStreamImpl& stream, void* pValue);
extern __declspec(thread) int g_iCC90D0MemContext;
class CC90D0MemContext
{
  public:
    CC90D0MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCC90D0MemContext;
        g_iCC90D0MemContext = aiMemoryContext;
    }
    ~CC90D0MemContext()
    {
        g_iCC90D0MemContext = m_iPrevious;
    }

    int m_iPrevious;
};
void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();
class CC90D0RefObject
{
  public:
    CC90D0RefObject();
    virtual ~CC90D0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CC90D0Level1 : public CC90D0RefObject
{
  public:
    CC90D0Level1() : m_pPointer(0)
    {
        ++ms_uiInstances;
    }
    virtual ~CC90D0Level1();

    void* m_pPointer;

    static unsigned int ms_uiInstances;
};
class CC90D0Level2 : public CC90D0Level1
{
  public:
    CC90D0Level2()
    {
        ++ms_uiInstances;
    }
    virtual ~CC90D0Level2();

    static unsigned int ms_uiInstances;
};
class CC90D0Level3 : public CC90D0Level2
{
  public:
    CC90D0Level3()
    {
        ++ms_uiInstances;
    }
    virtual ~CC90D0Level3();

    static unsigned int ms_uiInstances;
};
extern int DAT_01268648;
extern int DAT_0108febc;
extern int DAT_010c8b0c;
extern int DAT_01268188;
extern int DAT_01268648;
struct PhysicsAllocator
{
    static void* __cdecl operator new(unsigned int size);
};
struct PhysicsReference
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    PhysicsReference();
};
struct PhysicsObject : PhysicsAllocator, PhysicsReference
{
    unsigned int m_uiData;

    PhysicsObject() : PhysicsReference()
    {
        unsigned int count = 1;
        m_pVtable = &DAT_0108febc;
        m_uiData = 0;
        DAT_01268188 += count;
        m_pVtable = &DAT_010c8b0c;
        DAT_01268648 += count;
    }
};
extern __declspec(thread) int g_iCC9940AllocTag;
struct CC9940AllocTagScope
{
    int m_iSaved;

    CC9940AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC9940AllocTag;
        g_iCC9940AllocTag = aiAllocationTag;
    }
    ~CC9940AllocTagScope()
    {
        g_iCC9940AllocTag = m_iSaved;
    }
};
extern int g_iCC9940RefObjectCount;
extern int g_iCC9940WrapperCount;
class CC9940Root
{
  public:
    CC9940Root();
    virtual ~CC9940Root();
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};
class CC9940Holder : public CC9940Root
{
  public:
    CC9940Holder() : m_pkHavokObject(0)
    {}
    virtual ~CC9940Holder();
    void* m_pkHavokObject;
};
class CC9940RefObject : public CC9940Holder
{
  public:
    CC9940RefObject()
    {
        ++g_iCC9940RefObjectCount;
    }
    virtual ~CC9940RefObject();
};
class CC9940Wrapper : public CC9940RefObject
{
  public:
    CC9940Wrapper()
    {
        ++g_iCC9940WrapperCount;
    }
    virtual ~CC9940Wrapper();

    void CopyMemberData(CC9940Wrapper* pkDest, int iCloning);
    CC9940Wrapper* FUN_00cc9940(int iCloning);
};
class BCC9B80BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCC9B80BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BCC9B80Stream
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
    BCC9B80BinaryStream* m_pUnderlyingStream;
};
template <class T> inline void BCC9B80BinaryStreamLoad(BCC9B80BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BCC9B80LoadBinary(BCC9B80Stream& kStream, T& value)
{
    BCC9B80BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
struct S_00cc9df0_Val
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_f;
};
struct S_00cc9df0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S_00cc9df0_Val* m_kPointA;
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
    S_00cc9df0_Val* m_kPointB;
};
struct S_00cc9df0_Out
{
    int unk00;
    int unk04;
    S_00cc9df0_Val* m_v;
    float m_fValue;
};
struct S_00cc9df0_Cls;
inline S_00cc9df0_Val* GetA(S_00cc9df0_Data* d)
{
    return d ? d->m_kPointA : 0;
}
inline S_00cc9df0_Val* GetB(S_00cc9df0_Data* d)
{
    return d ? d->m_kPointB : 0;
}
struct S_00cc9df0_Cls
{
    int unk00;
    int unk04;
    S_00cc9df0_Data* m_iFourthElementInteger;
    void bhkBvTreeShape_CopyCinfo(S_00cc9df0_Out* out);
    void SetRatioFromValues(S_00cc9df0_Out* out);
};
inline S_00cc9df0_Data* GetD(S_00cc9df0_Cls* c)
{
    return c ? c->m_iFourthElementInteger : 0;
}
// Apply a scale: multiply the Havok shape's radius by the scale, refresh the shape, then the base handles the rest.
struct Owner_Target
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};
class FUN_00cca0e0_cls
{
  public:
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
    virtual Owner_Target* v45(unsigned int* p);
    void FUN_00ca4ec0(unsigned int a);
    void FUN_00cca0e0(unsigned int param);
};
extern __declspec(thread) int g_iCCA1B0MemContext;
class CCA1B0MemContext
{
  public:
    CCA1B0MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCCA1B0MemContext;
        g_iCCA1B0MemContext = aiMemoryContext;
    }
    ~CCA1B0MemContext()
    {
        g_iCCA1B0MemContext = m_iPrevious;
    }

    int m_iPrevious;
};
void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();
class CCA1B0RefObject
{
  public:
    CCA1B0RefObject();
    virtual ~CCA1B0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CCA1B0Level1 : public CCA1B0RefObject
{
  public:
    CCA1B0Level1() : m_pkFirst(0), m_pkSecond(0)
    {
        ++ms_uiInstances;
    }
    virtual ~CCA1B0Level1();

    void* m_pkFirst;
    void* m_pkSecond;

    static unsigned int ms_uiInstances;
};
class CCA1B0Level2 : public CCA1B0Level1
{
  public:
    CCA1B0Level2()
    {
        ++ms_uiInstances;
    }
    virtual ~CCA1B0Level2();

    static unsigned int ms_uiInstances;
};
class CCA1B0Level3 : public CCA1B0Level2
{
  public:
    CCA1B0Level3()
    {
        ++ms_uiInstances;
    }
    virtual ~CCA1B0Level3();

    static unsigned int ms_uiInstances;
};
class CCAA80Object
{
  public:
    CCAA80Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
extern "C" void _ReadWriteBarrier(void);
struct FUN_00ccab60_arg
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
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
};
struct FUN_00ccab60_rec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    unsigned int m1C;
    unsigned int m20;
    unsigned int m24;
    unsigned int m28;
    unsigned int m2C;
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};
struct FUN_00ccab60_cls
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
    virtual FUN_00ccab60_rec* GetRec(FUN_00ccab60_arg*& a);
    void FUN_00c9fbc0(FUN_00ccab60_arg* a);
    void ProcessRecord(FUN_00ccab60_arg* a1);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long value);
extern __declspec(thread) int g_iCCB080AllocTag;
struct BCCB080AllocTagScope
{
    int m_iSaved;

    BCCB080AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCB080AllocTag;
        g_iCCB080AllocTag = aiAllocationTag;
    }
    ~BCCB080AllocTagScope()
    {
        g_iCCB080AllocTag = m_iSaved;
    }
};
class BCCB080StringArray
{
  public:
    virtual ~BCCB080StringArray();
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
extern int DAT_01030bf4;
extern int DAT_010ca5c4;
extern int DAT_010ca4dc;
extern int DAT_012680f8;
extern int DAT_01268f8c;
extern int DAT_0126866c;
struct AllocationBase
{
    static void* __cdecl operator new(unsigned int size);
};
struct S_00c87c30_Base
{
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    S_00c87c30_Base();
};
struct TargetObject : AllocationBase, S_00c87c30_Base
{
    TargetObject() : S_00c87c30_Base()
    {
        m_pVtable = &DAT_01030bf4;
        unsigned int count = 1;
        m_uiData1 = 0;
        m_uiData2 = 0;
        DAT_012680f8 += count;
        m_pVtable = &DAT_010ca5c4;
        DAT_01268f8c += count;
        m_pVtable = &DAT_010ca4dc;
        DAT_0126866c += count;
    }
};
inline void CCB350Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}
typedef unsigned int CCB730size_t;
struct CCB730MemoryManager
{
    void* Allocate(unsigned int uiSize);
};
extern CCB730MemoryManager g_CCB730MemoryManager;
extern __declspec(thread) int g_CCB730AllocTag;
struct CCB730AllocTagScope
{
    int m_iSaved;

    CCB730AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CCB730AllocTag;
        g_CCB730AllocTag = aiAllocationTag;
    }
    ~CCB730AllocTagScope()
    {
        g_CCB730AllocTag = m_iSaved;
    }
};
inline void* CCB730AlignedAlloc(unsigned int uiSize)
{
    char* pcMem = (char*)g_CCB730MemoryManager.Allocate(uiSize);
    unsigned char ucOffset = (unsigned char)(16 - ((unsigned char)(unsigned int)pcMem & 0xf));
    pcMem += ucOffset;
    pcMem[-1] = ucOffset;
    return pcMem;
}
struct CCB730Child
{
    CCB730Child() throw()
        : m_pkOwnerManager(0), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1C(0.0f), m_f20(0.0f), m_f24(0.0f),
          m_f28(0.0f), m_f2C(0.0f), m_f30(0.0f), m_f34(0.0f), m_f38(0.0f), m_f3C(0.0f)
    {}

    void* m_pkOwnerManager;
    int unk04;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;

    static void* operator new(CCB730size_t, void* pvMem)
    {
        return pvMem;
    }
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct FunObjBase_b9645
{
    FunObjBase_b9645();
    virtual void unk00();
    unsigned int m_04;
    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};
struct FunObj_b9645 : public FunObjBase_b9645
{
    virtual void unk10();
    unsigned int m_08;
    unsigned int m_0c;
    FunObj_b9645()
    {
        m_08 = 0;
        m_0c = 0;
    }
};
// Decompilation candidate for FUN_00ccba30 (0x00ccba30, 32 bytes).
//
// Shape: a member function that (1) forwards its single argument to a virtual
// slot of an object held at offset 0x14 of itself and (2) hands the same
// argument to its own member helper FUN_00aa0ad0.
// GetValueForArg: thiscall, 37 bytes, 1 stack argument.
// Returns 0x24 when the argument is -1, otherwise it asks the object held in
// the member pointer at this+8 for a record and returns that record's +4 field.
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
struct RefObjCC
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
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
template <class T> struct NiPtrCC
{
    T* m_pObject;
    NiPtrCC(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPtrCC();
    NiPtrCC& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct FNVRefObj;
struct FNVRefVTable
{
    void(__thiscall* m_method00)(FNVRefObj*);
    void(__thiscall* m_release)(FNVRefObj*);
};
struct FNVRefObj
{
    FNVRefVTable* m_ppVirtualMethodTable;
    volatile long m_refcount;
};
struct FNVHolder
{
    void* m_ppVirtualMethodTable;
    FNVRefObj* m_object;
};
struct FNVParam
{
    FNVRefObj* __thiscall FUN_00a63430();
};
struct FNVTarget
{
    void* m_ppVirtualMethodTable;
    void __thiscall FUN_00c84cc0(FNVParam*);
    void __thiscall AssignRefObject(FNVParam*);
};
typedef FNVHolder*(__thiscall* FNVQuery)(FNVTarget*, bool*);
struct S_00ccc620_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    int unk08;
    unsigned int(__cdecl* m_pfnWrite)(S_00ccc620_BinStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};
template <class T> inline void WriteBinaryArray(S_00ccc620_BinStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    unsigned int uiBytes = uiNumEls * sizeof(T);
    kStream.Write(pkValue, uiBytes, &uiSize, 1);
}
class CCCF00BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CCCF00BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CCCF00BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n)
    {
        unsigned int size = n;
        return BinaryWrite(p, n, &size, 1);
    }
};
// bhkBallSocketConstraintChain_GetRTTI : a one-line function - getter
extern void* __cdecl FUN_00aa13e0(unsigned int size);
struct FUN_00ccd100
{
    void* vtable;
    unsigned int refCount;
    unsigned int flags;
    unsigned int dataA;
    unsigned int dataB;
    FUN_00ccd100();
    static void* __cdecl operator new(unsigned int bytes)
    {
        return FUN_00aa13e0(bytes);
    }
};
extern "C" void _ReadWriteBarrier(void);
struct S_00ccd330_Arg
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
    unsigned char unk1E4;
    unsigned char m1E5;
};
struct S_00ccd330_Data
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
};
struct S_00ccd330_Foo
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
    virtual S_00ccd330_Data* FUN_v45(void** value);
    S_00ccd330_Data* m_pData;
    void __thiscall FUN_00c9fbc0(S_00ccd330_Arg* a1);
    void FUN_00ccd330(S_00ccd330_Arg* a1);
};
struct FUN_00ccd3a0_arg
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
    unsigned int unk1E0;
    unsigned char m_1e4;
};
// Constructor of a four-level Havok wrapper class: each level bumps its own live-instance counter.
extern int g_iCDC40LevelACount;
extern int g_iCDC40LevelBCount;
extern int g_iCDC40LevelCCount;
class CDC40Root
{
  public:
    CDC40Root();
    virtual ~CDC40Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};
class CDC40Holder : public CDC40Root
{
  public:
    CDC40Holder() : m_pkHavokObject(0), m_uiData(0)
    {}
    virtual ~CDC40Holder();
    void* m_pkHavokObject;
    unsigned int m_uiData;
};
class CDC40LevelA : public CDC40Holder
{
  public:
    CDC40LevelA()
    {
        ++g_iCDC40LevelACount;
    }
    virtual ~CDC40LevelA();
};
class CDC40LevelB : public CDC40LevelA
{
  public:
    CDC40LevelB()
    {
        ++g_iCDC40LevelBCount;
    }
    virtual ~CDC40LevelB();
};
class CDC40LevelC : public CDC40LevelB
{
  public:
    CDC40LevelC()
    {
        ++g_iCDC40LevelCCount;
    }
    virtual ~CDC40LevelC();
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct RefObject20_b9084
{
    char m00[0x14];
    RefObject20_b9084();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
extern float DAT_010c72bc;
extern __declspec(thread) int g_iCCE110AllocTag;
struct BCCE110AllocTagScope
{
    int m_iSaved;

    BCCE110AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCE110AllocTag;
        g_iCCE110AllocTag = aiAllocationTag;
    }
    ~BCCE110AllocTagScope()
    {
        g_iCCE110AllocTag = m_iSaved;
    }
};
class BCCE110StringArray
{
  public:
    virtual ~BCCE110StringArray();
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
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);
extern __declspec(thread) int gThreadAllocState;
struct ScopedThreadSetting
{
    int prior;
    ScopedThreadSetting() : prior(gThreadAllocState)
    {
        gThreadAllocState = 16;
    }
    ~ScopedThreadSetting()
    {
        gThreadAllocState = prior;
    }
};
struct TaskTls
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
    int context;
};
__declspec(thread) TaskTls g_taskTls;
struct AutoMemContext
{
    int old;
    AutoMemContext(int value)
    {
        old = g_taskTls.context;
        g_taskTls.context = value;
    }
    ~AutoMemContext()
    {
        g_taskTls.context = old;
    }
};
struct ThreeByThreeMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    char* ToString(const char*);
};
struct Transform403
{
    hkVector4 row0, row1, row2, translation;
};
struct Output403
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
    virtual void Output(StrArr*);
};
struct Link403
{
    int unk00, unk04;
    Output403* target;
};
struct Data403
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Link403* link;
    int unk1c;
    Transform403 transform;
};
extern Transform403 DAT_01268370;
extern const char g_010c6050[], g_010c604c[];
char* __cdecl FUN_00a7d330(const char*);
struct StringArray403 : StrArr
{
    void Add(char* value)
    {
        unsigned int index = m_usElementCount;
        if (index >= m_usSize)
            SetSize(index + m_usIncrement);
        SetAt(index, value);
    }
};
struct Holder403
{
    int unk00, unk04;
    Data403* data;
    void FUN_00c9fc50(StrArr*);
    const Transform403& GetTransform() const
    {
        if (this && data)
            return data->transform;
        return DAT_01268370;
    }
    void AppendTransformStrings(StringArray403*);
};
// FUN_00ccf560 - a virtual forwarder.
//
// The object pointer arrives in ECX (a __thiscall member).  The function reads
// the object's vtable pointer and tail-jumps to the virtual that lives at
// vtable offset 0xbc, forwarding its own 4-byte stack argument IN PLACE.
//
// Forwarding the argument in place is what keeps the frame frameless and puts
// the jump target in EAX (a forward with no forwarded argument would use EDX).
//
// The 47 dummy virtuals only place the forwarded virtual at vtable offset 0xbc:
// the first virtual of a class sits at vptr+0, so offset 0xbc is the 48th slot.
// FUN_00ccf810: thiscall, 21 bytes, 2 stack args.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x38] / jmp eax / end: ret 8
// Forwards the two stack arguments to virtual slot 0x38 of the object
// pointed to by the member at this+8.
struct Link
{
    void* m_type;
    unsigned int m_flags;
    void* m_object;
};
struct RefObject
{
    void** m_ppVirtualMethodTable;
    unsigned int m_flags;
    Link* m_link;
};
struct LinkCollection
{
    unsigned int m_type;
    unsigned int m_flags;
    unsigned int m_pRayCursor;
    unsigned int m_generation;
    Link** m_ppLinks;
    int m_uiItemCount;
};
struct Owner
{
    void** m_ppVirtualMethodTable;
    void __thiscall bhkShape_CopyMembers(void* item, void* key);
    void __thiscall FUN_00ccf900(void* item, void* key);
};
typedef LinkCollection*(__thiscall* AcquireLinks)(Owner*, unsigned char*);
typedef bool(__thiscall* CheckRef)(RefObject*, void*);
typedef RefObject*(__thiscall* FindRef)(RefObject*, void*);
class CCFA00RefObject
{
  public:
    virtual ~CCFA00RefObject();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
};
struct ObjC;
struct ObjD
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
    virtual void v53(int p1, int p2);
};
struct ObjC
{
    unsigned int unk00;
    unsigned int unk04;
    ObjD* m_08;
};
extern void __cdecl FUN_00c908c0(void* allocator, void* array, int newCapacity, int elementSize);
extern float DAT_01013970;
struct SpawnedObjectBase
{
    unsigned short m_unk00;
    unsigned short m_unk02;
    float m_unk04;

    SpawnedObjectBase()
    {
        m_unk04 = DAT_01013970;
        m_unk02 = 1;
    }
};
struct hkMemoryAllocator;
struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
NineIntegerRecord& __cdecl GetMemoryRouter();
struct HavokArrayUtilities
{
    static void __cdecl GrowArrayCapacity(hkMemoryAllocator& alloc, void* array, int capacity, int elemSize);
};
struct RouterHeapAllocatorProvider
{
    hkMemoryAllocator& get()
    {
        return GetMemoryRouter().heap();
    }
};
template <class T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = cap * 2;
            int newSize = n < cap2 ? cap2 : n;
            HavokArrayUtilities::GrowArrayCapacity(alloc, this, newSize, sizeof(T));
        }
    }

    void _setSize(hkMemoryAllocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }

    void _setSize(hkMemoryAllocator& alloc, int n, T fill)
    {
        GrowArrayCapacity(alloc, n);
        int num = n - m_iElementCount;
        T* p = m_data + m_iElementCount;
        for (int i = 0; i < num; i++)
        {
            p[i] = fill;
        }
        m_iElementCount = n;
    }

    void _reserveExactly(hkMemoryAllocator& alloc, int n)
    {
        if (getCapacity() < n)
        {
            HavokArrayUtilities::GrowArrayCapacity(alloc, this, n, sizeof(T));
        }
    }

    void SetSizeAndGrow(int n)
    {
        _setSize(RouterHeapAllocatorProvider().get(), n);
    }
    void SetSizeAndGrow(int n, T fill)
    {
        _setSize(RouterHeapAllocatorProvider().get(), n, fill);
    }
    void reserveExactly(int n)
    {
        _reserveExactly(RouterHeapAllocatorProvider().get(), n);
    }
};
struct S_00cdb2f0_Arr
{
    int* data;
    int size;
    unsigned int cap;
    S_00cdb2f0_Arr() : data(0), size(0), cap(0x80000000)
    {}
};
class RefObj
{
  public:
    RefObj()
    {
        m_sReferenceCount = 1;
    }
    virtual void v0();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
class RangeBase : public RefObj
{
  public:
    RangeBase()
    {
        m_bEnableState = false;
    }
    virtual void v0();
    struct HkBool
    {
        char m_cBooleanValue;
        HkBool()
        {}
        HkBool(bool b)
        {
            m_cBooleanValue = (char)b;
        }
        HkBool& operator=(bool b)
        {
            m_cBooleanValue = (char)b;
            return *this;
        }
    } m_bEnableState;
};
struct CDF760FinishFlag
{
    int m_bFinishing;
};
struct CDF760Member
{
    int unk00;
    int unk04;
    void* m_pvOwner;

    void FUN_00d21ce0(void* pvOwner);

    CDF760Member(CDF760FinishFlag flag)
    {
        if (flag.m_bFinishing)
            FUN_00d21ce0(m_pvOwner);
    }
};
extern __declspec(thread) int g_iCC2950AllocTag;
struct BCC2950AllocTagScope
{
    int m_iSaved;

    BCC2950AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC2950AllocTag;
        g_iCC2950AllocTag = aiAllocationTag;
    }
    ~BCC2950AllocTagScope()
    {
        g_iCC2950AllocTag = m_iSaved;
    }
};
class BCC2950StringArray
{
  public:
    virtual ~BCC2950StringArray();
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
inline void CC2E50Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}
struct CC2E50Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned long m_ul10;
    unsigned long m_ul14;
    unsigned long m_ul18;
    unsigned long m_ul1C;
    unsigned long m_ul20;
    unsigned long m_ul24;
    unsigned long m_ul28;
    unsigned long m_ul2C;
    unsigned long m_ul30;
    unsigned long m_ul34;
    unsigned long m_ul38;
};
__forceinline void CC2E50SwapData(CC2E50Data* pkData)
{
    CC2E50Swap(pkData->m_ul10);
    CC2E50Swap(pkData->m_ul14);
    CC2E50Swap(pkData->m_ul18);
    CC2E50Swap(pkData->m_ul1C);
    CC2E50Swap(pkData->m_ul20);
    CC2E50Swap(pkData->m_ul24);
    CC2E50Swap(pkData->m_ul28);
    CC2E50Swap(pkData->m_ul2C);
    CC2E50Swap(pkData->m_ul30);
    CC2E50Swap(pkData->m_ul34);
    CC2E50Swap(pkData->m_ul38);
}
struct CC3840Data
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
    float m_fSpinRate;
    float m_fGain;
};
class CC3840Base
{
  public:
    void CollectBaseNames(BCC1F80StringArray* pkArray);
};
class CC3840Node : public CC3840Base
{
  public:
    int unk00;
    int unk04;
    CC3840Data* m_pUserData;

    static float GetSpinRate(CC3840Node* p)
    {
        return (p && p->m_pUserData) ? p->m_pUserData->m_fSpinRate : 0.0f;
    }
    static float GetGain(CC3840Node* p)
    {
        return (p && p->m_pUserData) ? p->m_pUserData->m_fGain : 0.0f;
    }
    void FUN_00cc3840(BCC1F80StringArray* pkArray);
};
struct BinaryInput
{
    int unk00;
    unsigned int position;
    unsigned int(__cdecl* reader)(BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* dst, unsigned int size)
    {
        unsigned int componentSize = size;
        position += reader(this, dst, size, &componentSize, 1);
    }
};
// Lazily create the Havok helper object; report the object size.
extern __declspec(thread) int g_iCC5AE0AllocTag;
struct CC5AE0AllocTagScope
{
    int m_iSaved;

    CC5AE0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC5AE0AllocTag;
        g_iCC5AE0AllocTag = aiAllocationTag;
    }
    ~CC5AE0AllocTagScope()
    {
        g_iCC5AE0AllocTag = m_iSaved;
    }
};
struct CC5AE0Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct CC5AE0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC5AE0Allocator* m_pStreamAllocator;

    CC5AE0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" CC5AE0MemoryRouter& __cdecl CC5AE0GetMemoryRouter();
class CC5AE0Helper
{
  public:
    CC5AE0Helper();
    virtual ~CC5AE0Helper();

    static void* operator new(unsigned int nbytes)
    {
        CC5AE0Helper* p = static_cast<CC5AE0Helper*>(CC5AE0GetMemoryRouter().heap().AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        CC5AE0GetMemoryRouter().heap().ReleaseBlock(p, nbytes);
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
};
struct CC61F0BinaryStream
{
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CC61F0BinaryStream* pThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, 0, 0);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
template <class T> inline void CC61F0LoadBinary(CC61F0BinaryStream& kBinStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.BinaryRead(&value, uiSize, &uiSize, 1);
}
struct CC63E0_Stream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_vContactPosition;
    void* m_pOwnerObject;
    unsigned int(__cdecl* m_write)(CC63E0_Stream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* data, unsigned int count)
    {
        unsigned int actualCount = count;
        m_vContactPosition += m_write(this, data, count, &actualCount, 1);
    }
};
struct __declspec(novtable) ReferenceRoot78
{
    unsigned int unk04;
    unsigned int unk08;
    static void* __cdecl operator new(unsigned int size);
    static void __cdecl operator delete(void*);
    virtual ~ReferenceRoot78();
    void Initialize();
    ReferenceRoot78()
    {
        Initialize();
    }
};
struct ConstraintBase78 : ReferenceRoot78
{
    unsigned int data;
    ConstraintBase78()
    {
        data = 0;
        ++DAT_01268188;
    }
    virtual ~ConstraintBase78();
};
struct Constraint78 : ConstraintBase78
{
    Constraint78()
    {
        ++DAT_0126860c;
    }
    virtual ~Constraint78();
};
// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.
extern __declspec(thread) int g_iCC69D0AllocTag;
struct CC69D0AllocTagScope
{
    int m_iSaved;

    CC69D0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC69D0AllocTag;
        g_iCC69D0AllocTag = aiAllocationTag;
    }
    ~CC69D0AllocTagScope()
    {
        g_iCC69D0AllocTag = m_iSaved;
    }
};
class CC69D0RefObject
{
  public:
    CC69D0RefObject();
    virtual ~CC69D0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CC69D0Shape : public CC69D0RefObject
{
  public:
    CC69D0Shape() : m_pUserData(0)
    {
        ++ms_iCount;
    }
    virtual ~CC69D0Shape();

    void* m_pUserData;

    static int ms_iCount;
};
class CC69D0ListShape : public CC69D0Shape
{
  public:
    CC69D0ListShape()
    {
        ++ms_iCount;
    }
    virtual ~CC69D0ListShape();

    static int ms_iCount;
};
extern int DAT_010c8ce4;
struct Child_00cc6ab0
{
    void* m_pVtable;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }

    Child_00cc6ab0() : m_08(1), m_0c(0), m_10(0)
    {
        m_pVtable = &DAT_010c8ce4;
        m_04 = 0;
    }
};
static __forceinline Child_00cc6ab0* Make_00cc6ab0(Child_00cc6ab0* obj)
{
    Child_00cc6ab0* p = (Child_00cc6ab0*)((char*)obj + 4);
    new (obj) Child_00cc6ab0();
    return p;
}
struct CC77E0Allocator
{
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct CC77E0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC77E0Allocator* m_pStreamAllocator;

    CC77E0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" CC77E0MemoryRouter& __cdecl hkMemoryRouterCC77();
extern __declspec(thread) int g_CC77E0AllocTag;
struct CC77E0AllocTagScope
{
    int m_iSaved;

    CC77E0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CC77E0AllocTag;
        g_CC77E0AllocTag = aiAllocationTag;
    }
    ~CC77E0AllocTagScope()
    {
        g_CC77E0AllocTag = m_iSaved;
    }
};
class CC77E0Child
{
  public:
    CC77E0Child();
    virtual ~CC77E0Child();

    static void* operator new(unsigned int uiSize)
    {
        void* p = hkMemoryRouterCC77().heap().AllocateMemoryBlock(uiSize);
        static_cast<CC77E0Child*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    int unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    int unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    int unkC8, unkCC;
};
struct NiBinaryStream
{
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                               unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                       unsigned int uiNumComponents)
    {
        unsigned int uiWritten = m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiWritten;
        return uiWritten;
    }
};
struct NiStreamView
{
    char pad[0x250];
    NiBinaryStream* m_pBackingStream;
};
template <class T> inline void WriteBinaryArray(NiBinaryStream& kBinStream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.Write(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void SerializeValue(NiStreamView& kStream, const T& kValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &kValue, 1);
}
extern __declspec(thread) int g_iCC7F30AllocTag;
struct BCC7F30AllocTagScope
{
    int m_iSaved;

    BCC7F30AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC7F30AllocTag;
        g_iCC7F30AllocTag = aiAllocationTag;
    }
    ~BCC7F30AllocTagScope()
    {
        g_iCC7F30AllocTag = m_iSaved;
    }
};
class BCC7F30Allocator
{
  public:
    virtual void VFunc00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* pvMem, int iNumBytes);
};
class BCC7F30Router
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BCC7F30Allocator* m_pkHeap;

    BCC7F30Allocator& heap()
    {
        return *m_pkHeap;
    }
};
BCC7F30Router* BCC7F30GetRouter();
class BCC7F30ReferencedObject
{
  public:
    void* operator new(unsigned int uiNumBytes)
    {
        BCC7F30ReferencedObject* pkObject =
            static_cast<BCC7F30ReferencedObject*>(BCC7F30GetRouter()->heap().AllocateMemoryBlock(uiNumBytes));
        pkObject->m_usMemSizeAndFlags = (unsigned short)uiNumBytes;
        return pkObject;
    }
    void operator delete(void* pvMem)
    {
        BCC7F30ReferencedObject* pkObject = static_cast<BCC7F30ReferencedObject*>(pvMem);
        BCC7F30GetRouter()->heap().ReleaseBlock(pvMem, pkObject->m_usMemSizeAndFlags);
    }

    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class BCC8950BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCC8950BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BCC8950Stream
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
    BCC8950BinaryStream* m_pUnderlyingStream;
};
template <class T> inline void BCC8950BinaryStreamLoad(BCC8950BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BCC8950LoadBinary(BCC8950Stream& kStream, T& value)
{
    BCC8950BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
// Lazily create the Havok helper object; report the object size.
extern __declspec(thread) int g_iCC9890AllocTag;
struct CC9890AllocTagScope
{
    int m_iSaved;

    CC9890AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC9890AllocTag;
        g_iCC9890AllocTag = aiAllocationTag;
    }
    ~CC9890AllocTagScope()
    {
        g_iCC9890AllocTag = m_iSaved;
    }
};
struct CC9890Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct CC9890MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC9890Allocator* m_pStreamAllocator;

    CC9890Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" CC9890MemoryRouter& __cdecl CC9890GetMemoryRouter();
class CC9890Helper
{
  public:
    CC9890Helper();
    virtual ~CC9890Helper();

    static void* operator new(unsigned int nbytes)
    {
        CC9890Helper* p = static_cast<CC9890Helper*>(CC9890GetMemoryRouter().heap().AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        CC9890GetMemoryRouter().heap().ReleaseBlock(p, nbytes);
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
};
struct CcaArg
{
    int unkCur;
    int unkValue;
    int uNewnk;
    int unk00C;
    int uTmpnk;
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
    unsigned char m_b1e4;
};
struct CcaRes
{
    int unk;
    int unk04;
    void* m_08;
    unsigned int m_0c;
};
struct CcaOwner
{
    virtual ~CcaOwner()
    {}
    virtual void vf();
    virtual void vfCur();
    virtual void vfValue();
    virtual void vNewf();
    virtual void vTmpf();
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
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41(int a);
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual CcaRes* vf45(int& out);
    void FUN_00ca4f80(CcaArg* a);
};
__declspec(thread) unsigned int DAT_0126fd98;
struct FUN_00cca450_param_item
{
    void* unk00;
    void* unk04;
    struct FUN_00cca450_hook* unk08;
};
struct FUN_00cca450_hook
{
    void __thiscall FUN_00c905b0();
};
typedef unsigned int CCADB0size_t;
struct CCADB0MemoryManager
{
    void* Allocate(unsigned int uiSize);
};
extern CCADB0MemoryManager g_CCADB0MemoryManager;
extern __declspec(thread) int g_CCADB0AllocTag;
struct CCADB0AllocTagScope
{
    int m_iSaved;

    CCADB0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CCADB0AllocTag;
        g_CCADB0AllocTag = aiAllocationTag;
    }
    ~CCADB0AllocTagScope()
    {
        g_CCADB0AllocTag = m_iSaved;
    }
};
extern const float g_fCCADB0DefaultScale;
struct CCADB0Child
{
    CCADB0Child() throw()
        : m_pkOwnerManager(0), m_fScale(g_fCCADB0DefaultScale), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1C(0.0f),
          m_f20(0.0f), m_f24(0.0f), m_f28(0.0f), m_f2C(0.0f), m_f30(0.0f), m_f34(0.0f), m_f38(0.0f), m_f3C(0.0f)
    {}

    void* m_pkOwnerManager;
    float m_fScale;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;

    static void* operator new(CCADB0size_t uiSize) throw()
    {
        return g_CCADB0MemoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem)
    {}
};
extern int DAT_012686d0;
extern int DAT_01268678;
extern int DAT_010c44e4;
extern int DAT_010ca744;
struct BccObj : S_00c87c30_Base
{
    unsigned int m_14;
    BccObj() : S_00c87c30_Base()
    {
        m_pVtable = &DAT_01030bf4;
        unsigned int* q = &m_uiData1;
        q[0] = 0;
        q[1] = 0;
        DAT_012680f8 += 1;
        m_pVtable = &DAT_010c44e4;
        DAT_012686d0 += 1;
        m_pVtable = &DAT_010ca744;
        m_14 = 0;
        DAT_01268678 += 1;
    }
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {}
};
// SaveBinary of an element array: the count, then each element saves itself.
class CCC920BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CCC920BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CCC920BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n, unsigned int uiComponentSize)
    {
        unsigned int size = uiComponentSize;
        return BinaryWrite(p, n, &size, 1);
    }
};
class CCC920Stream
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
    CCC920BinaryStream* m_pBackingStream;
};
template <class T>
inline void CCC920BinaryStreamSave(CCC920BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void CCC920SaveBinary(CCC920Stream& kStream, const T& value)
{
    CCC920BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
template <class T> inline void CCC920SaveBinary(CCC920Stream& kStream, const T* pValues, unsigned int ItemUpdateArray)
{
    CCC920BinaryStreamSave(*kStream.m_pBackingStream, pValues, ItemUpdateArray);
}
extern __declspec(thread) int g_iCCDE60MemContext;
class CCDE60MemContext
{
  public:
    CCDE60MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCCDE60MemContext;
        g_iCCDE60MemContext = aiMemoryContext;
    }
    ~CCDE60MemContext()
    {
        g_iCCDE60MemContext = m_iPrevious;
    }

    int m_iPrevious;
};
void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();
class CCDE60Object
{
  public:
    CCDE60Object();
    virtual ~CCDE60Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
class AllocatorCCD
{
  public:
    virtual void vfn00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};
struct MemoryCCD
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocatorCCD* m_pHeapAllocator;

    AllocatorCCD& heap()
    {
        return *m_pHeapAllocator;
    }
};
MemoryCCD* __cdecl GetMemoryCCD();
extern __declspec(thread) int g_iAllocTagCCD;
struct AllocTagScopeCCD
{
    int m_iSaved;

    AllocTagScopeCCD(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagCCD;
        g_iAllocTagCCD = aiAllocationTag;
    }
    ~AllocTagScopeCCD()
    {
        g_iAllocTagCCD = m_iSaved;
    }
};
class ReferencedObjectCCD
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        ReferencedObjectCCD* pkObject =
            static_cast<ReferencedObjectCCD*>(GetMemoryCCD()->heap().AllocateMemoryBlock(uiSize));
        pkObject->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return pkObject;
    }
    static void operator delete(void* pvMem);

    virtual ~ReferencedObjectCCD();

    void removeReference();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct CE340Allocator
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct CE340Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CE340Allocator* m_pStreamAllocator;
    CE340Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
CE340Router* CE340GetRouter() throw();
struct CE340Vec4
{
    float x, y, z, w;
};
template <class T> struct CE340Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    CE340Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~CE340Array()
    {
        _clearAndDeallocate(CE340GetRouter()->heap());
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void _clearAndDeallocate(CE340Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReleaseBlock(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void swap(CE340Array& a)
    {
        T* d = m_data;
        m_data = a.m_data;
        a.m_data = d;
        int s = m_iElementCount;
        m_iElementCount = a.m_iElementCount;
        a.m_iElementCount = s;
        int c = m_iCapacityState;
        m_iCapacityState = a.m_iCapacityState;
        a.m_iCapacityState = c;
    }
};
struct CE340Data
{
    int unk00;
    int unk04;
    CE340Array<CE340Vec4> m_arr08;
    CE340Array<CE340Vec4> m_arr14;
};
typedef FUN_00ccd3a0_arg CE340Stream;
void __cdecl FUN_00cf0930(CE340Data* data, void* ctx, CE340Array<CE340Vec4>* arr);
void __cdecl FUN_00cf0cf0(CE340Stream* stream, void* value);
// Release the cached Havok data when requested.
extern __declspec(thread) int g_iCCE860AllocTag;
struct CCE860AllocTagScope
{
    int m_iSaved;

    CCE860AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCE860AllocTag;
        g_iCCE860AllocTag = aiAllocationTag;
    }
    ~CCE860AllocTagScope()
    {
        g_iCCE860AllocTag = m_iSaved;
    }
};
class CCE860MemoryManager
{
  public:
    void Deallocate(void* pvMem);
};
extern CCE860MemoryManager g_kCCE860MemoryManager;
inline void __cdecl operator delete(void* pvMem)
{
    g_kCCE860MemoryManager.Deallocate(pvMem);
}
class ArgCCE;
class TargetCCE
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7C();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8C();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9C();
    virtual void vfnA0();
    virtual void vfnA4();
    virtual void vfnA8();
    virtual void vfnAC();
    virtual void vfnB0();
    virtual void vfnB4();
    virtual void vfnB8();
    virtual void vfnBC();
    virtual void vfnC0();
    virtual void vfnC4();
    virtual void vfnC8();
    virtual void vfnCC();
    virtual bool Process(ArgCCE* pkArg);
};
struct LinkCCE
{
    int unk00;
    int unk04;
    TargetCCE* m_pkTarget;
};
struct BodyCCE
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    LinkCCE* m_pkLink;
};
class BaseCCE
{
  public:
    bool Process(ArgCCE* pkArg);

    void* m_ppVirtualMethodTable;
    int unk04;
    BodyCCE* m_pkBody;
};
inline TargetCCE* GetTargetCCE(BaseCCE* pkObject)
{
    if (pkObject && pkObject->m_pkBody && pkObject->m_pkBody->m_pkLink)
        return pkObject->m_pkBody->m_pkLink->m_pkTarget;
    return 0;
}
__declspec(thread) unsigned int currentAllocationContext = 0x3b;
struct ThreadContextGuard
{
    unsigned int oldValue;
    ThreadContextGuard() : oldValue(currentAllocationContext)
    {
        currentAllocationContext = 0x10;
    }
    ~ThreadContextGuard()
    {
        currentAllocationContext = oldValue;
    }
};
extern float DAT_010c72bc;
extern MM g_memoryManager;
class BCCFA50Arg;
class BCCFA50Shape
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
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void VFuncA0();
    virtual void VFuncA4();
    virtual void VFuncA8();
    virtual void VFuncAC();
    virtual void VFuncB0();
    virtual void VFuncB4();
    virtual void VFuncB8();
    virtual void VFuncBC();
    virtual void VFuncC0();
    virtual void VFuncC4();
    virtual void VFuncC8();
    virtual void VFuncCC();
    virtual bool Process(BCCFA50Arg* pkArg);
};
struct BCCFA50Child
{
    int unk00;
    int unk04;
    BCCFA50Shape* m_pkShape;
};
class BCCFA50Counter
{
  public:
    virtual void VFunc00();
    virtual int GetCount();
};
struct BCCFA50HavokList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    BCCFA50Counter m_kCounter;
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
    BCCFA50Child** m_ppkChildren;
};
class BCCFA50Wrapper
{
  public:
    bool BaseProcess(BCCFA50Arg* pkArg);
    __forceinline BCCFA50HavokList* GetList()
    {
        return this ? m_pkList : 0;
    }
    bool ProcessChildren(BCCFA50Arg* pkArg);

    int unk00;
    int unk04;
    BCCFA50HavokList* m_pkList;
};
// Returns the lazily created settings block, creating it under the Havok allocation tag and registering it when owned.
extern __declspec(thread) int g_iCCFFD0AllocTag;
struct CCFFD0AllocTagScope
{
    int m_iSaved;

    CCFFD0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCFFD0AllocTag;
        g_iCCFFD0AllocTag = aiAllocationTag;
    }
    ~CCFFD0AllocTagScope()
    {
        g_iCCFFD0AllocTag = m_iSaved;
    }
};
extern float g_fCCFFD0DefaultScale;
class CCFFD0Settings
{
  public:
    CCFFD0Settings()
    {
        m_pUserData = 0;
        m_fScale = g_fCCFFD0DefaultScale;
        m_pEntries = 0;
        m_iEntryCount = 0;
        m_iCapacityAndFlags = 0x80000000;
    }

    static void* operator new(unsigned int uiSize, void* pvMem) throw()
    {
        return pvMem;
    }

    void* m_pUserData;
    float m_fScale;
    int unk08;
    int unk0C;
    void* m_pEntries;
    int m_iEntryCount;
    int m_iCapacityAndFlags;
};
struct hkMemoryAllocStub
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void deallocateChunk(void* p, int nbytes);
};
template <class T> struct hkArrayRaw
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <class T> struct hkArrayStub
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayStub() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayStub()
    {
        hkMemoryAllocStub* mem = reinterpret_cast<hkMemoryAllocStub*>(FUN_00c85750()->unk10);
        if ((m_iCapacityState & 0x80000000) == 0)
            mem->deallocateChunk(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    hkArrayStub(const hkArrayRaw<T>& r) : m_data(r.m_data), m_iElementCount(r.m_iElementCount), m_iCapacityState(r.m_iCapacityState)
    {}
    __forceinline hkArrayRaw<T> release()
    {
        int s = m_iElementCount;
        T* d = m_data;
        m_data = 0;
        m_iElementCount = 0;
        int c = m_iCapacityState;
        m_iCapacityState = 0x80000000;
        hkArrayRaw<T> r;
        r.m_data = d;
        r.m_iElementCount = s;
        r.m_iCapacityState = c;
        return r;
    }
    void swap(hkArrayStub& a)
    {
        int s = a.m_iElementCount;
        T* d = a.m_data;
        a.m_data = m_data;
        a.m_iElementCount = m_iElementCount;
        m_data = d;
        m_iElementCount = s;
        int c = a.m_iCapacityState;
        a.m_iCapacityState = m_iCapacityState;
        m_iCapacityState = c;
    }
};
struct NiBinaryStreamStub
{
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(NiBinaryStreamStub* stream, const void* buffer, unsigned int bytes,
                               unsigned int* componentSizes, unsigned int numComponents);

    void BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, buffer, bytes, componentSizes, numComponents);
    }
};
template <class T> inline void SaveBinaryValue(NiBinaryStreamStub* stream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    stream->BinaryWrite(&value, sizeof(T), &uiSize, 1);
}
struct LinkedObjStub
{
    int unk00;
    int unk04;
    void* m_pLinked;
};
struct SaveStreamStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void SaveLinkID(void* obj);
};
struct SaveStreamFields : SaveStreamStub
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
    unsigned char m_bUnk1E4;
    unsigned char unk1E5;
    unsigned short unk1E6;
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
    NiBinaryStreamStub* m_pOstr;
};
struct CountedSub
{
    virtual void v00();
    virtual int GetCount();
};
struct CountedOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    CountedSub m_sub;
};
struct SavedData
{
    int unk00;
    int unk04;
    char m_cUnk08;
    int m_iUnk0C;
    hkArrayStub<LinkedObjStub*> m_ppData;
};
void FUN_00cf0930(SavedData* data, void* source, hkArrayStub<LinkedObjStub*>* out);
struct bhkSaveOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void* GetSource();
    virtual void vAC();
    virtual void vB0();
    virtual SavedData* GetData(bool* pbOut);

    int unk04;
    CountedOwner* m_pSharedOwner;

    int GetCount()
    {
        CountedOwner* owner = m_pSharedOwner;
        return owner ? owner->m_sub.GetCount() : 0;
    }
    void FUN_00c9fc00(SaveStreamFields* stream);
    void SaveLinkedObjects(SaveStreamFields* stream);
};
extern int DAT_0102016c;
extern int DAT_0102009c;
extern int DAT_010c9634;
extern int DAT_01268154;
extern int DAT_01268118;
extern int DAT_012685b8;
struct C200125Base
{
    void FUN_00c87c30();
};
struct C200125Object : C200125Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }

    C200125Object()
    {
        unsigned int count = 1;
        FUN_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_0102009c;
        DAT_01268118 += count;
        m_pVtable = &DAT_010c9634;
        DAT_012685b8 += count;
    }
};
struct SaveStream;
typedef unsigned int(__cdecl* SaveStreamWriteFn)(SaveStream*, const void*, unsigned int, unsigned int*, unsigned int);
struct SaveStream
{
    void* unk00;
    unsigned int m_04;
    void* unk08;
    SaveStreamWriteFn m_0c;
    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int num)
    {
        unsigned int r = m_0c(this, p, n, sizes, num);
        m_04 += r;
        return r;
    }
    unsigned int Write(const void* p, unsigned int n)
    {
        unsigned int cnt = n;
        return BinaryWrite(p, n, &cnt, 1);
    }
};
struct SaveCtx
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
    SaveStream* m_pBinaryStream;
};
static inline void CC8A10Write(SaveCtx* c, void* p, unsigned int n)
{
    c->m_pBinaryStream->Write(p, n);
}
// bhk wrapper LoadBinary: load the parent part, then fix up the Havok cinfo block when the
// stream's endianness differs (translation swapped inline, rotation through the shared helper).
struct TransformDataX
{
    unsigned int m_rotation00, m_rotation04, m_rotation08, m_rotation0c;
    unsigned int m_rotation10, m_rotation14, m_rotation18, m_rotation1c;
    unsigned int m_rotation20, m_rotation24, m_rotation28, m_rotation2c;
    unsigned int m_uiX, m_uiY, m_uiZ, m_w;
};
void __cdecl FUN_00c8c020(TransformDataX* pkRotation);
static inline void SwapDword(unsigned int& v)
{
    v = _byteswap_ulong(v);
}
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
namespace cce {
struct Block
{
    char pad[0x30];
    unsigned long m_kPointA;
    unsigned long m_kPointB;
    unsigned long m_iThirdValue;
    unsigned long m_iFourthElementInteger;
};
void __cdecl FUN_00c8c020(Block* b);
struct Hdr
{
    char pad[0x10];
    Block m_kBlock;
};
struct Info
{
    int unk;
    int unkCur;
    void* m_pName;
};
struct Meta
{
    char pad[0x18];
    Info* m_pObjectInfo;
};
struct Writer
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
    virtual void SetName(void* p);
    char pad[0x1e4 - 4];
    unsigned char m_ucMode;
};
struct Obj
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
    virtual void va();
    virtual void vaCur();
    virtual void vaValue();
    virtual void vac();
    virtual void vb();
    virtual Hdr* GetHeader(int* pSize);
    int unkCur;
    Meta* m_pMeta;
    void FUN_00c9fc00(Writer* w);
    void FUN_00ccec00(Writer* w);
};
}

struct HavokElementArray
{
    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapFlags;
    void Init()
    {
        m_pData = 0;
        m_uiLogicalSize = 0;
        m_iCapFlags = (int)0x80000000;
    }
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
extern const float runtimeFloatSettingDefault92;
extern const float runtimeFloatSettingDefault506;
extern const float g_011db1d4_arg1;
struct Defaults
{
    float strength, damping, gain, recovery, maxVelocity, u14, u18, u1c, u20, u24, u28, u2c;
    Defaults()
        : strength(.17f), damping(0), gain(1), recovery(.6f), maxVelocity(.05f), u14(runtimeFloatSettingDefault92),
          u18(runtimeFloatSettingDefault506), u1c(.1f), u20(.3f), u24(.3f), u28(g_011db1d4_arg1), u2c(.1f)
    {}
    Defaults(int)
    {}
    Defaults* FUN_00cdb360();
};
template <class T> struct Array
{
    T* data;
    int size;
    int capacity;
    Array() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline void reserve(S_00cc4b90_Alloc& alloc, int n)
    {
        int c = capacity & 0x3fffffff;
        if (c < n)
        {
            int doubled = c * 2;
            FUN_00c908c0(&alloc, this, n < doubled ? doubled : n, sizeof(T));
        }
    }
    __forceinline void resizeUninitialized(int n)
    {
        reserve(FUN_00c85750()->heap(), n);
        size = n;
    }
    __forceinline void resize(int n)
    {
        reserve(FUN_00c85750()->heap(), n);
        int delta = n - size;
        T* start = data + size;
        for (int i = 0; i < delta; i++)
            new (start + i) T;
        size = n;
    }
    __forceinline void resize(int n, T value)
    {
        reserve(FUN_00c85750()->heap(), n);
        int delta = n - size;
        T* start = data + size;
        for (int i = 0; i < delta; i++)
            start[i] = value;
        size = n;
    }
};
extern "C" int __cdecl hkString_strLen(const char* s);
struct hkStreamWriter
{
    virtual void unk00() = 0;
    virtual void unk04() = 0;
    virtual void unk08() = 0;
    virtual void unk0c() = 0;
    virtual int write(const void* buf, int len) = 0;
};
static __declspec(noinline) void FUN_00cc0080(hkStreamWriter* writer, const char* str)
{
    if (str)
    {
        writer->write(str, hkString_strLen(str));
    }
    else
    {
        writer->write("(null)", 6);
    }
}
extern "C" void* DAT_010c9314;
struct CpuOpaque;
struct Stream
{
    int unk0;
    int total;
    int unk8;
    int (*io)(Stream* s, void* buf, int size, int* out, int n);
    void Rd(void* p)
    {
        int sz = 4;
        total += io(this, p, 4, &sz, 1);
    }
};
struct Item
{
    unsigned int count;
    char** data;
};
struct Loader
{
    char pad[0x250];
    Stream* stream;
    void Read(unsigned int* p);
    void NiStream_SaveFixedString(unsigned int* p);
};
static inline void ReadU(Loader* l, void* p)
{
    l->stream->Rd(p);
}
struct Obj
{
    int unk0, unk4;
    unsigned int count1;
    unsigned int* arr1;
    unsigned int count2;
    Item** arr2;
    void ReadFromStream(Loader* l);
};
struct RefObjC
{
    virtual ~RefObjC();
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
template <class T> struct LargeArrayC
{
    virtual ~LargeArrayC();
    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void SetSize(unsigned int uiMaxSize);
    __declspec(noinline) void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_uiSize)
        {
            m_uiSize = uiIndex + 1;
            if (element.m_pObject)
                m_uiESize++;
        }
        else
        {
            if (element.m_pObject)
            {
                if (!m_pBase[uiIndex].m_pObject)
                    m_uiESize++;
            }
            else
            {
                if (m_pBase[uiIndex].m_pObject)
                    m_uiESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_uiMaxSize)
            SetSize(uiIndex + m_uiGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const T& element)
    {
        return SetAtGrow(m_uiSize, element);
    }
};
struct S_54d0_Poly
{
    void* m_pVtable;
};
struct S_54d0_Child
{
    void* m_pUnk00;

    S_54d0_Child()
    {}
};
struct S_54d0_Heap
{
    void* Allocate(unsigned int uiSize);
};
extern S_54d0_Heap g_54d0Heap;
extern int DAT_010c9af0;
struct S_54d0_Node : S_54d0_Poly, S_54d0_Child
{
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;

    static void* operator new(unsigned int uiSize)
    {
        return g_54d0Heap.Allocate(uiSize);
    }

    S_54d0_Node()
    {
        S_54d0_Child* pkSelf = this;
        m_uiRefCount = 1;
        m_uiValue1 = 0;
        m_uiData1 = 0;
        m_pVtable = (void*)&DAT_010c9af0;
        pkSelf->m_pUnk00 = 0;
    }
};
struct CC7970_Allocator
{
    void* __thiscall FUN_00aa3e40(unsigned int);
};
struct CC7970_RefData
{
    unsigned int m_uiFilterValue;
};
struct CC7970_RefObject
{
    void* m_pVtable;
    CC7970_RefData m_data;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiReserved;
};
static __forceinline CC7970_RefData* CC7970_CreateReference()
{
    CC7970_RefObject* object = reinterpret_cast<CC7970_RefObject*>(
        reinterpret_cast<CC7970_Allocator*>(&DAT_011f6238)->FUN_00aa3e40(sizeof(CC7970_RefObject)));
    if (object)
    {
        CC7970_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010c9d60;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
void* FUN_00aa13e0(unsigned int);
void FUN_00aa1460(void*, unsigned int);
extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
// Constructor stand-in for the twelve-byte bhkRefObject base.
struct FUN_00c87c30
{
    virtual ~FUN_00c87c30();
    unsigned int references;
    void* handle;
    FUN_00c87c30();
};
// The pack's bhkConstraint shell omits its base and data member.
// This stand-in models the actual sixteen-byte constraint layout.
class Constraint348 : public FUN_00c87c30
{
  public:
    void* constraint;
    Constraint348() : constraint(0)
    {
        ++DAT_01268188;
    }
    virtual ~Constraint348();
};
class bhkGenericConstraint : public Constraint348
{
  public:
    bhkGenericConstraint()
    {
        ++DAT_01268f74;
    }
    virtual ~bhkGenericConstraint();
};
class bhkFixedConstraint : public bhkGenericConstraint
{
  public:
    bhkFixedConstraint()
    {
        ++DAT_01268624;
    }
    virtual ~bhkFixedConstraint();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* pointer, unsigned int size)
    {
        FUN_00aa1460(pointer, size);
    }
};
// Forward declaration of the target function
void __cdecl FUN_00c908c0(void* alloc, void* arr, int cap, int elemSize);
struct FE50Iter
{
    virtual void v00();
    virtual unsigned int GetCount();
    virtual void* GetFirst();
    virtual void* GetNext(void* it);
};
struct FE50Hk
{
    char pad00[0x14];
    FE50Iter m_kIter;
    float m18;
    char pad1c[0x28];
    void** m44;
    bool FUN_00d5e0c0();
};
struct FE50Out
{
    int m0, m4;
    unsigned char m8;
    float mc;
    Array<void*> m10;
};
struct FE50Wrap
{
    int m0, m4;
    FE50Hk* m8;
    void bhkConvexShape_CopyCinfo(FE50Out* out);
    float GetF()
    {
        if (this && m8)
            return m8->m18;
        return 0.0f;
    }
    int GetB()
    {
        if (this && m8)
            return m8->FUN_00d5e0c0();
        return 0;
    }
    unsigned int GetCount()
    {
        FE50Hk* p;
        if (this && (p = m8) != 0)
            return p->m_kIter.GetCount();
        if (0)
            return m8->m_kIter.GetCount();
        return 0;
    }
    void* GetFirst()
    {
        FE50Hk* p;
        if (this && (p = m8) != 0)
            return p->m_kIter.GetFirst();
        if (0)
            return m8->m_kIter.GetFirst();
        return 0;
    }
    void* GetNext(void* it)
    {
        FE50Hk* p;
        if (this && (p = m8) != 0)
            return p->m_kIter.GetNext(it);
        if (0)
            return m8->m_kIter.GetNext(it);
        return 0;
    }
    void* GetAt(unsigned int i)
    {
        if (this && m8)
            return m8->m44[i];
        return 0;
    }
    void FillOutput(FE50Out* out);
};
struct AGBinStream
{
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(AGBinStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void AGLoadBinary(AGBinStream& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&value, uiSize, &uiSize, 1);
}
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* pkSection);
extern void(__stdcall* DAT_00fdf100)(int*);
struct hkMemoryAllocator
{
    virtual void vfn0() throw() = 0;
    virtual void vfn1() throw() = 0;
    virtual void vfn2() throw() = 0;
    virtual void vfn3() throw() = 0;
    virtual void ReleaseBlock(void* p, int numBytes) throw() = 0;
};
void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize) throw();
void __cdecl FUN_00c908c0(void* allocator, void* array, int newCapacity, int elementSize) throw();
template <typename T> inline void ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <typename T> struct MyArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    enum
    {
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline MyArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}

    __forceinline int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator* alloc, int n) throw()
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = cap * 2;
            int newCap = n < cap2 ? cap2 : n;
            FUN_00c908c0(alloc, this, newCap, sizeof(T));
        }
    }

    __forceinline void SetSizeAndGrow(int n, T fill) throw()
    {
        NineIntegerRecord* router = (NineIntegerRecord*)FUN_00c85750();
        GrowArrayCapacity(router->m_pStreamAllocator, n);
        ConstructWithCopy<T>(m_data + m_iElementCount, n - m_iElementCount, fill);
        m_iElementCount = n;
    }

    __forceinline void AddBack(const T& val) throw()
    {
        NineIntegerRecord* router = (NineIntegerRecord*)FUN_00c85750();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        }
        ConstructWithCopy<T>(m_data + m_iElementCount, 1, val);
        m_iElementCount++;
    }

    __forceinline ~MyArray() throw()
    {
        NineIntegerRecord* router = (NineIntegerRecord*)FUN_00c85750();
        hkMemoryAllocator* alloc = router->m_pStreamAllocator;
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        {
            alloc->ReleaseBlock(m_data, m_iCapacityState & 0x3fffffff);
        }
    }
};
template <typename T> struct MyLocalArray : public MyArray<T>
{
    void* m_initialStack;

    __forceinline MyLocalArray(int capacity) throw()
    {
        NineIntegerRecord* router = (NineIntegerRecord*)FUN_00c85750();
        int numBytes = capacity * sizeof(T);
        int aligned = (numBytes + 0x7f) & ~0x7f;
        void* p = (void*)router->unk00;
        router->unk00 = (int)((char*)p + aligned);
        this->m_iCapacityState = capacity | MyArray<T>::DONT_DEALLOCATE_FLAG;
        this->m_data = (T*)p;
        this->m_initialStack = p;
    }

    __forceinline ~MyLocalArray() throw()
    {
        void* p = m_initialStack;
        if (p == this->m_data)
        {
            this->m_iElementCount = 0;
        }
        ((NineIntegerRecord*)FUN_00c85750())->unk00 = (int)p;
    }
};

inline void* __cdecl operator new[](unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
struct MeshMetadata654
{
    unsigned int a, b;
    static void* operator new(unsigned int size)
    {
        char* p = (char*)g_memoryManager.Allocate(size + 16);
        unsigned char offset = (unsigned char)(16 - ((unsigned char)(unsigned int)p & 15));
        p += offset;
        p[-1] = offset;
        return p;
    }
    MeshMetadata654(unsigned int x, unsigned int y)
    {
        b = y;
        a = x;
    }
};
struct Mesh654
{
    unsigned int vertexCount;
    float* vertices;
    unsigned int triangleCount;
    unsigned short* triangles;
    MeshMetadata654* metadata;
    void FUN_00ccc440(BCC9B80Stream&);
};
// @f3 0x0094f6d0 (community match, verified in this file)
void Mesh654::FUN_00ccc440(BCC9B80Stream& stream)
{
    BCC9B80LoadBinary(stream, vertexCount);
    vertices = new float[vertexCount * 3];
    BCC9B80BinaryStreamLoad(*stream.m_pUnderlyingStream, vertices, vertexCount * 3);
    BCC9B80LoadBinary(stream, triangleCount);
    triangles = new unsigned short[triangleCount * 3];
    BCC9B80BinaryStreamLoad(*stream.m_pUnderlyingStream, triangles, triangleCount * 3);
    unsigned int a, b;
    BCC9B80LoadBinary(stream, b);
    BCC9B80LoadBinary(stream, a);
    metadata = new MeshMetadata654(b, a);
}

