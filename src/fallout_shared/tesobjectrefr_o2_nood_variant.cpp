#include "f3_common.h"
// src/fallout_shared/tesobjectrefr_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/fallout_shared/tesobjectrefr.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "tesobjectrefr_decls.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
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
};

extern "C" __declspec(thread) int tls_state;

struct MemContextGuard
{
    int m_iOld;
    MemContextGuard(int aiMemoryContext)
    {
        m_iOld = tls_state;
        tls_state = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        tls_state = m_iOld;
    }
};

template <class T> class NiTMallocInterface
{
};

template <class T, class TAlloc> class NiTPrimitiveArray
{
  public:
    virtual ~NiTPrimitiveArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, T& element);
    unsigned int SetAtGrow(unsigned int uiIndex, T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(T element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > NiViewerStringsArray;

class GlobalObjectO2_00a7b610
{
  public:
    const char* m_pcName;
    const GlobalObjectO2_00a7b610* m_pBaseRTTI;
    const char* GetName() const
    {
        return m_pcName;
    }
};

struct NiPoint3
{
    float x, y, z;
    char* FUN_00a59af0(const char* pcPrefix);
};

struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    char* ToString(const char* pcPrefix);
};

struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};

struct hkVector4
{
    __m128 m_vComponents;
};
struct hkRotation
{
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
};

void FUN_00624b10(ThreeByThreeMatrix* pkOut, const hkRotation* pkIn);
void FUN_00458620(NiPoint3* pkOut, const hkVector4* pkIn);

namespace fnv_00cb3650 {
struct FUN_00a5ecb0;
typedef FUN_00a5ecb0 Body;
struct InitArgs
{
    float time;
    char flag0, flag1, flag2, flag3, flag4;
};
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
};
struct NiPoint3
{
    float x, y, z;
};
struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    signed char m128_i8[16];
    unsigned char m128_u8[16];
    int m128_i32[4];
} __m128;
typedef __m128 Vec4;
extern volatile unsigned int DAT_0126fd98;
struct StringHeader
{
    volatile long refs;
    unsigned int length;
};
extern StringHeader* DAT_0109b220;
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
StringHeader* __cdecl FUN_00a5b690(const char*);
void __cdecl FUN_00624b10(void*, void*);
void __cdecl FUN_00458620(void*, void*);

struct FixedString
{
    StringHeader* value;
    FixedString(const char* s) : value(FUN_00a5b690(s))
    {}
    ~FixedString()
    {
        if (value != DAT_0109b220)
            InterlockedDecrement(&(value - 1)->refs);
    }
};
extern "C" __declspec(thread) int tls_memContext;
struct TlsScope
{
    int m_iSaved;
    TlsScope(int c)
    {
        m_iSaved = tls_memContext;
        tls_memContext = c;
    }
    ~TlsScope()
    {
        tls_memContext = m_iSaved;
    }
};
struct BSFadeNode
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
    unsigned int unk00;
};
struct FUN_00a5ecb0 : BSFadeNode
{
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
    ThreeByThreeMatrix f34;
    NiPoint3 position;
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
    FUN_00a5ecb0(int);
    void FUN_00a59c60(InitArgs&);
    void AssignFixedString(const FixedString&);
};

static __forceinline Body* NewNode()
{
    return new Body(0);
}
static __forceinline void SetNameStr(Body* b, const char* s)
{
    b->AssignFixedString(FixedString(s));
}
}  // namespace fnv_00cb3650

struct Arg_00c9f830
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    __m128 unk20;
    __m128 unk30;
};

struct Obj_00c9f830
{
    void FillOutputFromState(Arg_00c9f830* value);
    void FUN_006288c0(__m128* value);
    void FUN_00c9f830(Arg_00c9f830* value);
};

// @f3 0x0090e280 (community match, verified in this file)
struct FUN_008f9940_Stand {
    void FUN_008f9940(Arg_00c9f830* value);
};

struct FUN_0056cb70_Stand {
    void FUN_0056cb70(__m128* value);
};

struct FUN_00c9f830_Pair {
    __m128 v0;
    __m128 v1;
};

// pdb: bhkAabbPhantom::CopyCinfo | bhkAabbPhantom.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arInfo
void Obj_00c9f830::FUN_00c9f830(Arg_00c9f830* arg)
{
    reinterpret_cast<FUN_008f9940_Stand*>(this)->FUN_008f9940(arg);

    FUN_00c9f830_Pair tmp;
    reinterpret_cast<FUN_0056cb70_Stand*>(this)->FUN_0056cb70((__m128*)&tmp);

    float* src = (float*)&tmp;
    float* dst = (float*)&arg->unk20;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
}


struct Sub
{
    unsigned int m_00;
};
struct Arg;

struct Arg
{
    void FUN_00c74ac0(__m128* out, Sub* sub);
};

struct S00cb3250_Query
{
    S00cb3250_Query(int iArg, void* pOwner);  // FUN_00c66320
    __m128 m_vComponents;
};

class S00cb3250_Object
{
  public:
    void FUN_00c8d1a0(S00cb3250_Query* pQuery);
    void bhkRigidBodyT_SetRotation(int iArg);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int m_kOwner;
};

// @f3 0x00925880 (community match, verified in this file)
// pdb: bhkRigidBodyT::SetRotation | bhkRigidBodyT.obj | fnv360_0822_retail, objrun + skyrim(objrun_open), high
void S00cb3250_Object::bhkRigidBodyT_SetRotation(int iArg)
{
    S00cb3250_Query kQuery(iArg, &m_kOwner);
    FUN_00c8d1a0(&kQuery);
}


extern unsigned long DAT_0126fd98;

struct F9_Alloc
{
    virtual void slot0();
    virtual void* alloc(int bytes);
};
struct F9_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    F9_Alloc* m_pStreamAllocator;
    F9_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
F9_Router* __cdecl FUN_00c85750();

struct F9_Ctx
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
    int unk2b4;
};

extern __declspec(thread) F9_Ctx F9_tls;

struct F9_Scope
{
    int saved;
    F9_Scope()
    {
        saved = F9_tls.unk2b4;
        F9_tls.unk2b4 = 0x10;
    }
    ~F9_Scope()
    {
        F9_tls.unk2b4 = saved;
    }
};

struct F9_Mat
{
    __m128 c0;
    __m128 c1;
    __m128 c2;
    __m128 c3;
    void FUN_00cb2fc0();
};

struct F9_Obj
{
    int unk00;
    short unk04;
    short unk06;
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
    F9_Obj(int a, const F9_Mat* m, int b);
    void FUN_00c905b0();
    static void* operator new(unsigned int n)
    {
        F9_Alloc& h = FUN_00c85750()->heap();
        void* p = h.alloc((int)n);
        ((F9_Obj*)p)->unk04 = (short)n;
        return p;
    }
    static void operator delete(void*)
    {}
};

class NiGlobalStringTable
{
  public:
    static char* AddString(const char* pcString);
};

class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char* pcString)
    {
        m_kHandle = NiGlobalStringTable::AddString(pcString);
    }
    ~NiFixedString();
};

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_setzero_ps();

extern "C" __m128 _mm_setzero_ps(void);

struct C9FA20_TlsBlock
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
    unsigned int m_2b4;
};
extern __declspec(thread) C9FA20_TlsBlock g_c9fa20Tls;
struct C9FA20_TlsGuard
{
    unsigned int m_saved;
    C9FA20_TlsGuard()
    {
        m_saved = g_c9fa20Tls.m_2b4;
        g_c9fa20Tls.m_2b4 = 0x10;
    }
    ~C9FA20_TlsGuard()
    {
        g_c9fa20Tls.m_2b4 = m_saved;
    }
};
struct C9FA20_Alloc
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};
extern C9FA20_Alloc DAT_011f6238;
struct C9FA20_Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    C9FA20_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct C9FA20_Data
{
    int unk00;
    int unk04;
    unsigned char m_08;
    C9FA20_Array m_ppData;
    int unk18;
    int unk1C;
    __m128 m_20;
    __m128 m_30;

    static __forceinline void* operator new(unsigned int size)
    {
        unsigned char* p = static_cast<unsigned char*>(DAT_011f6238.FUN_00aa3e40(size + 0x10));
        unsigned char offset = (unsigned char)(0x10 - ((unsigned int)p & 0xf));
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void*)
    {}
    C9FA20_Data()
    {
        unk00 = 0;
        unk04 = 0;
        m_08 = 2;
        m_20 = _mm_setzero_ps();
        m_30 = _mm_setzero_ps();
    }
};

namespace N {
union __declspec(intrin_type) __declspec(align(16)) __m128
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
};
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_sub_ps(__m128, __m128);
}
}

extern const N::__m128 DAT_010c71e0;

class hkQuaternionDAD;

class __declspec(align(16)) hkVector4DAD
{
  public:
    __forceinline void SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction);
    inline hkVector4DAD& operator=(const hkVector4DAD& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void setAdd4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = N::_mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = N::_mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = N::_mm_add_ps(m_vComponents, N::_mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setCross(const hkVector4DAD& v1, const hkVector4DAD& v2)
    {
        const N::__m128 cross0 = N::_mm_mul_ps(N::_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                               N::_mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const N::__m128 cross1 = N::_mm_mul_ps(N::_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                               N::_mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = N::_mm_sub_ps(cross0, cross1);
    }
    __forceinline void setBroadcast3(const hkVector4DAD& v)
    {
        m_vComponents = N::_mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline N::__m128 dot3(const hkVector4DAD& v) const
    {
        const N::__m128 x2 = N::_mm_mul_ps(m_vComponents, v.m_vComponents);
        const N::__m128 sum = N::_mm_add_ss(N::_mm_shuffle_ps(x2, x2, 0x55), x2);
        return N::_mm_add_ss(N::_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    N::__m128 m_vComponents;
};

class hkQuaternionDAD
{
  public:
    void FUN_00c66320(const hkQuaternionDAD& q0, const hkQuaternionDAD& q1);  // SetProduct
    void FUN_005611c0();                                                      // normalize
    const hkVector4DAD& getImag() const
    {
        return m_vec;
    }

    hkVector4DAD m_vec;
};

__forceinline void hkVector4DAD::SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction)
{
    hkVector4DAD qreal;
    qreal.setBroadcast3(quat.m_vec);
    hkVector4DAD q2minus1;
    q2minus1.m_vComponents = N::_mm_add_ps(N::_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);
    hkVector4DAD ret;
    ret.setMul4(q2minus1, direction);
    hkVector4DAD imagDotDir;
    imagDotDir.m_vComponents = quat.getImag().dot3(direction);
    imagDotDir.m_vComponents = N::_mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4DAD imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

namespace center_of_mass {
extern "C" __m128 _mm_sub_ps(__m128, __m128);

class OffsetVector : public hkVector4
{
  public:
    void FUN_00c7f750(const hkRotation& rotation, const hkVector4& direction);
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
};

}

namespace position_cb3 {
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_rcp_ps(__m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;

class hkQuaternionCB3;

class hkVector4CB3
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4CB3& operator=(const hkVector4CB3& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4CB3& a, const hkVector4CB3& b)
    {
        m_vComponents = position_cb3::_mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4CB3& a)
    {
        m_vComponents = position_cb3::_mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4CB3& a, const hkVector4CB3& b)
    {
        m_vComponents = position_cb3::_mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4CB3& a, const hkVector4CB3& b)
    {
        m_vComponents =
            position_cb3::_mm_add_ps(m_vComponents, position_cb3::_mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4CB3& b)
    {
        m_vComponents = position_cb3::_mm_add_ps(
            m_vComponents, position_cb3::_mm_mul_ps(position_cb3::_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4CB3& a)
    {
        m_vComponents = position_cb3::_mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4CB3& v1, const hkVector4CB3& v2)
    {
        __m128 cross0 =
            position_cb3::_mm_mul_ps(position_cb3::_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xC9),
                                     position_cb3::_mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xD2));
        __m128 cross1 =
            position_cb3::_mm_mul_ps(position_cb3::_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xD2),
                                     position_cb3::_mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xC9));
        m_vComponents = position_cb3::_mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4CB3& v) const
    {
        __m128 x2 = position_cb3::_mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = position_cb3::_mm_add_ss(position_cb3::_mm_shuffle_ps(x2, x2, 0x55), x2);
        return position_cb3::_mm_add_ss(position_cb3::_mm_shuffle_ps(x2, x2, 0xAA), sum);
    }
    __forceinline void setReciprocal4(const hkVector4CB3& v)
    {
        __m128 r = position_cb3::_mm_rcp_ps(v.m_vComponents);
        __m128 rr = position_cb3::_mm_mul_ps(position_cb3::_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = position_cb3::_mm_sub_ps(position_cb3::_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionCB3& q, const hkVector4CB3& dir);
    void setRotatedInverseDir(const hkQuaternionCB3& q, const hkVector4CB3& dir);
};

class hkQuaternionCB3
{
  public:
    hkVector4CB3 m_vec;

    __forceinline void SetConjugate(const hkQuaternionCB3& q)
    {
        m_vec.m_vComponents = position_cb3::_mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionCB3& q0, const hkQuaternionCB3& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = position_cb3::_mm_sub_ps(position_cb3::_mm_mul_ps(position_cb3::_mm_shuffle_ps(b, b, 0xD2),
                                                                         position_cb3::_mm_shuffle_ps(a, a, 0xC9)),
                                                position_cb3::_mm_mul_ps(position_cb3::_mm_shuffle_ps(b, b, 0xC9),
                                                                         position_cb3::_mm_shuffle_ps(a, a, 0xD2)));
        __m128 aw = position_cb3::_mm_shuffle_ps(a, a, 0xFF);
        __m128 bw = position_cb3::_mm_shuffle_ps(b, b, 0xFF);
        __m128 imag = position_cb3::_mm_add_ps(position_cb3::_mm_mul_ps(bw, a),
                                               position_cb3::_mm_add_ps(position_cb3::_mm_mul_ps(aw, b), cross));
        __m128 prod = position_cb3::_mm_mul_ps(b, a);
        __m128 dot =
            position_cb3::_mm_add_ss(position_cb3::_mm_shuffle_ps(prod, prod, 0xAA),
                                     position_cb3::_mm_add_ss(position_cb3::_mm_shuffle_ps(prod, prod, 0x55), prod));
        __m128 real = position_cb3::_mm_sub_ps(prod, position_cb3::_mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = position_cb3::_mm_shuffle_ps(imag, position_cb3::_mm_unpackhi_ps(imag, real), 0xC4);
    }
};

__forceinline void hkVector4CB3::setRotatedInverseDir(const hkQuaternionCB3& quat, const hkVector4CB3& direction)
{
    hkVector4CB3 qreal;
    qreal.m_vComponents = position_cb3::_mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, 0xFF);
    hkVector4CB3 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = position_cb3::_mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4CB3 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CB3 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

}
