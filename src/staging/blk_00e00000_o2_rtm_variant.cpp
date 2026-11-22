// src/staging/blk_00e00000_o2_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e00000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/staging/blk_00e00000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern int DAT_010305a8;
extern int DAT_010c749c;
extern int DAT_010305a8;
extern int DAT_010cb5ac;
extern int DAT_010305a8;
extern int DAT_010ce4bc;
extern int DAT_010305a8;
extern int DAT_010ce25c;
extern int DAT_010305a8;
extern int DAT_010c70b4;
extern int DAT_010c9314;
extern int DAT_010c59f4;
extern int DAT_010c6cdc;
extern int DAT_010e81a4;
struct FUN_00e002d0_vt
{
    virtual void FUN_00e002d0(int);
};
void __cdecl FUN_00e002d0(FUN_00e002d0_vt* p);
extern int DAT_010c59f4;
extern int DAT_010e83b4;
extern int DAT_010305a8;
extern int DAT_010c6fd0;
extern int DAT_010cc41c;
extern int DAT_010e8824;
extern int DAT_010c63cc;
extern int DAT_010e8d8c;
extern int DAT_010305a8;
extern int DAT_010c6fd0;
extern int DAT_010d0e5c;
extern int DAT_010305a8;
extern int DAT_010c6fd0;
extern int DAT_010d102c;
extern int DAT_010305a8;
extern int DAT_010e901c;
extern int DAT_010305a8;
extern int DAT_010c6fd0;
extern int DAT_010e9300;
extern int DAT_010e9358;
extern int DAT_010e93ac;
typedef void(__thiscall* Fn)(void*, int);
extern int DAT_010e943c;
extern int DAT_010e9494;
struct FUN_00e017d0_vt
{
    virtual void FUN_00e017d0(int);
};
void __cdecl FUN_00e017d0(FUN_00e017d0_vt* p);
extern int DAT_010e9614;
extern int DAT_010e350c;
extern int DAT_010e96c8;
extern int DAT_010e977c;
extern int DAT_010e9b7c;
struct FUN_00e020e0_vt
{
    virtual int FUN_00e020e0(int);
};
int __cdecl FUN_00e020e0(FUN_00e020e0_vt* c);
typedef int(__thiscall* FUN_00e02340_fn)(void*, int);
extern int DAT_010e9e74;
extern int DAT_010e9f48;
extern int DAT_010e9fa4;
extern int DAT_010ea0a4;
typedef int(__thiscall* VFunc0)(void*, int);
extern int DAT_010ea10c;
extern int DAT_010ea154;
extern int DAT_010ea188;
extern int DAT_010ea1ac;
typedef void(__thiscall* vt)(void*, int);
extern int DAT_010c59f4;
extern int DAT_010c6dc4;
typedef void(__thiscall* VFn)(void*, int);
struct FUN_00e00e70_vt
{
    virtual int FUN_00e00e70(int);
};
int __cdecl FUN_00e00e70(FUN_00e00e70_vt* p);
typedef void(__thiscall* Fn0)(void*, int);
typedef int(__thiscall* Vfn)(void*, int);
typedef void(__thiscall* Fn)(void*, int);
typedef void(__thiscall* Fn)(void*, int);
typedef void(__thiscall* VFn)(void*, int);
typedef int(__thiscall* Vf0)(void*, int);
struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
// Forward a value to the owner object when the owner pointer is present.
struct CpuOpaque;
extern int DAT_010c6cdc;
extern int DAT_010e81a4;
// FUN_00e002e0 : a one-line function - getter
extern int DAT_010e83b4;
struct E00390FinishFlag
{
    int m_bFinishing;
};
class E00390Object
{
  public:
    E00390Object(E00390FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
struct S_00e003d0_Arr
{
    int* data;
    int size;
    unsigned cap;
    S_00e003d0_Arr() : data(0), size(0), cap(0x80000000)
    {}
};
extern int DAT_010c6dc4;
extern int DAT_010c749c;
struct S_00e00610_P
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
    S_00e00610_P(int flag)
    {
        if (flag != 0)
            unk0c = 0;
    }
};
struct S_00e00610_S
{
    virtual void unk00();
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk18;
    int unk1c;
};
struct S_00e00610_Mid : S_00e00610_P, S_00e00610_S
{
    virtual void unk00();
    S_00e00610_Mid(int flag) : S_00e00610_P(flag)
    {
        if (flag != 0)
        {
            unk0c = 7;
            S_00e00610_S::unk05 = 3;
        }
    }
};
// FUN_00e00690: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
extern int DAT_010c6fd0;
struct S_00e006d0_A
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0c;
    char unk10;
    __forceinline S_00e006d0_A(int flag)
    {
        if (flag)
            unk0c = 0;
    }
};
struct S_00e006d0_B : S_00e006d0_A
{
    virtual void v0();
    __forceinline S_00e006d0_B(int flag) : S_00e006d0_A(flag)
    {
        if (flag)
        {
            unk0c = 8;
            unk10 = 2;
        }
    }
};
extern int DAT_010cc41c;
struct CpuOpaque;
extern int DAT_010cb5ac;
struct CpuOpaque;
extern int DAT_010e8824;
struct S_00e00830_Allocator
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void ReturnMemory(void* p, int nbytes);
};
struct S_00e00830_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e00830_Allocator* m_pStreamAllocator;
    static S_00e00830_Router& FUN_00c85750();
    S_00e00830_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00e00830_Ref
{
    void* m_ptr;
    void FUN_00cb0c00() throw();
    ~S_00e00830_Ref() throw()
    {
        FUN_00cb0c00();
    }
};
struct S_00e00830_Target
{
    void FUN_00c905b0() throw();
};
struct S_00e00830_Ptr
{
    S_00e00830_Target* m_p;
    ~S_00e00830_Ptr() throw()
    {
        if (m_p)
            m_p->FUN_00c905b0();
        m_p = 0;
    }
};
template <typename T> struct S_00e00830_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void _clearAndDeallocate(S_00e00830_Allocator& alloc) throw()
    {
        T* p = m_data;
        int n = m_iElementCount;
        for (int i = 0; i < n; i++)
        {
            p[i].~T();
        }
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline ~S_00e00830_Array() throw()
    {
        _clearAndDeallocate(S_00e00830_Router::FUN_00c85750().heap());
    }
};
struct S_00e00830_Base
{
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00e00830_Base() throw()
    {}
};
// FUN_00e00940 : a one-line function - getter
// Resets an object to the "script terminal" class layout: it installs the
// secondary base vtable, the primary vtable and finally the derived vtable.
extern int DAT_010e88b4;
extern int DAT_010e88b4;
extern "C" struct FUN_00e009c0_vt
{
    virtual void m0(int);
};
// @fnv 0x00e009c0
struct CpuOpaque;
// FUN_00e00a30 : a one-line function - getter
class __declspec(novtable) BE00A80Base
{
  public:
    virtual ~BE00A80Base();

    int m_iRefCount;
};
extern int DAT_010ce4bc;
inline void* operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}
// FUN_00e00ba0: thiscall ctor-like (flag arg) storing a primary vtable at +0 and
// secondary vtables at +8, +0xc, +0x10, +0x14, then an optional int at +0x20.
struct CpuOpaque;
// FUN_00e00d20: cdecl, returns the address of a global object.
extern int DAT_010c63cc;
extern int DAT_010e8d8c;
extern int DAT_010d0e5c;
extern int DAT_010d102c;
// FUN_00e00f50: calls the first virtual (slot 0) of the object passed in the
// first stack argument, with a single 0 argument.
// FUN_00e00f70: forwards a value to a helper on the passed-in object
// when that object is present.
extern int DAT_010305a8;
extern int DAT_010c6fb0;
extern int DAT_010c6fb0;
extern int DAT_010d10c4;
extern int DAT_010d10c4;
extern int DAT_010e901c;
// FUN_00e01250: thiscall ctor (flag arg) storing secondary vtables at +8,+0xc,+0x10,+0x14
// from inline base ctors, then the primary vtable at +0, then the secondary vtables again,
// then an optional int at +0x20.
extern int DAT_010ce25c;
extern int DAT_010c70b4;
// FUN_00e01520 : a one-line function - getter
extern int DAT_010e9300;
extern int DAT_010e9358;
extern int DAT_010e93ac;
struct CpuOpaque;
extern int DAT_010e943c;
extern int DAT_010e9494;
// Stand-in for the object whose first virtual slot is invoked with the constant 0.
struct EffectSubObject
{
    int unk00;
    void __thiscall Release(int flags);
};
struct EffectHolder
{
    virtual void Virt();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    EffectSubObject m_18;
    EffectSubObject m_1c;
    EffectHolder()
    {}
};
extern int DAT_010e9614;
extern int DAT_010e350c;
struct CpuOpaque;
extern int DAT_010e96c8;
extern int DAT_010e977c;
// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is forwarded to a member function of that
// object (called with the object as 'this').
extern int DAT_010e9b7c;
// FUN_00e02120: cdecl, takes a pointer, calls virtual slot 0 with argument 0.
extern int DAT_010e9e74;
extern int DAT_010e9f48;
extern int DAT_010e9fa4;
// FUN_00e024b0 : a one-line function - getter
extern int DAT_010ea0a4;
extern int DAT_010ea10c;
extern int DAT_010ea154;
extern int DAT_010ea188;
extern int DAT_010ea1ac;
extern int DAT_010c9314;
int __cdecl ReadIntAtOffset(int index, int* data);
void __cdecl ReverseBytesInGroupsOfFour(unsigned char* p);
void __cdecl SwapHeaderBytesAndAdvance(unsigned char* pBuffer);
namespace std {
template <class T> inline void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
}
void __cdecl ReverseBytesInGroupsOfFour(unsigned char* p);
void __cdecl SwapQuadBytes(unsigned char* pData);
void __cdecl FUN_00e05eb0(unsigned char* pBuffer);
inline void E05F60Swap(char& a, char& b)
{
    char t = a;
    a = b;
    b = t;
}
inline void E05F60SwapBytes(void* pv, int iSize)
{
    char* pLo = static_cast<char*>(pv);
    char* pHi = pLo + iSize - 1;
    for (int j = 0; j < iSize / 2; j++)
        E05F60Swap(pLo[j], pHi[-j]);
}
struct E05F60Header
{
    unsigned short m_shorts[3];
    unsigned short unk06;
    unsigned int m_auiHeaderValues[3];
    unsigned int m_value0;
    unsigned int m_value1;
};
void __cdecl SwapHeaderEndianness(E05F60Header* pkHeader);
void __cdecl FUN_00e05fe0(unsigned char* pBuffer);
void __cdecl FUN_00e06010(unsigned char* pucBuffer);
// FUN_00e114f0: thiscall, 3 unused stack params, sets a flag byte at +0x100.
struct hkFinishLoadedObjectFlagE00
{
    int m_bFinishing;
};
template <class T> class hkSmallArrayE00
{
  public:
    hkSmallArrayE00() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000)
    {}

    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};
class hkMemberE00
{
  public:
    hkMemberE00(hkFinishLoadedObjectFlagE00 flag) throw();

    int unk00;
    int unk04;
    int unk08;
};
class hkBaseE00
{
  public:
    __forceinline hkBaseE00(hkFinishLoadedObjectFlagE00 flag) : m_kMemberDescriptor(flag)
    {}
    virtual ~hkBaseE00();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkSmallArrayE00<int> m_ppData;
    hkMemberE00 m_kMemberDescriptor;
};
class hkMidE00 : public hkBaseE00
{
  public:
    __forceinline hkMidE00(hkFinishLoadedObjectFlagE00 flag) : hkBaseE00(flag)
    {
        m_iType = -16;
    }
    virtual ~hkMidE00();

    int m_iType;
};
class hkDerivedE00 : public hkMidE00
{
  public:
    __forceinline hkDerivedE00(hkFinishLoadedObjectFlagE00 flag) : hkMidE00(flag)
    {}
    virtual ~hkDerivedE00();
};
char* __cdecl ReadPaddedString(char* base, int* piOffset);
class BE04D90Allocator;
class BE04D90PointerMap
{
  public:
    BE04D90PointerMap() : m_pPointerArray(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~BE04D90PointerMap() throw();

    void Init(BE04D90Allocator* pkAlloc, int iCapacity) throw();
    void ClearAndDeallocate(BE04D90Allocator* pkAlloc) throw();

    void* m_pPointerArray;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct Payload
{
    float x, y;
    union
    {
        float z;
        unsigned int zbits;
        struct
        {
            unsigned char z0, z1, z2, z3;
        };
    };
    unsigned int flags;
};
struct Input
{
    unsigned char type, selector, unk02, component;
    unsigned int unk04, unk08, unk0c;
    Payload a, b, c;
};
struct Entry
{
    unsigned int key;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38,
        unk3c, unk40, unk44, unk48, unk4c;
};
struct Context
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int unk02b4;
    unsigned int unk02b8;
    unsigned int unk02bc;
    unsigned int unk02c0;
    unsigned int unk02c4;
    unsigned int unk02c8;
    unsigned int unk02cc;
    unsigned int unk02d0;
    unsigned int unk02d4;
    unsigned int unk02d8;
    unsigned int unk02dc;
    unsigned int unk02e0;
    unsigned int unk02e4;
    unsigned int unk02e8;
    unsigned int unk02ec;
    unsigned int unk02f0;
    unsigned int unk02f4;
    unsigned int unk02f8;
    unsigned int unk02fc;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030c;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031c;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032c;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033c;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034c;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035c;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036c;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037c;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038c;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039c;
    unsigned int unk03a0;
    unsigned int unk03a4;
    unsigned int unk03a8;
    unsigned int unk03ac;
    unsigned int unk03b0;
    unsigned int unk03b4;
    unsigned int unk03b8;
    unsigned int unk03bc;
    unsigned int unk03c0;
    unsigned int unk03c4;
    unsigned int unk03c8;
    unsigned int unk03cc;
    unsigned int unk03d0;
    unsigned int unk03d4;
    unsigned int unk03d8;
    unsigned int unk03dc;
    unsigned int unk03e0;
    unsigned int unk03e4;
    unsigned int unk03e8;
    unsigned int unk03ec;
    unsigned int unk03f0;
    unsigned int unk03f4;
    unsigned int unk03f8;
    unsigned int unk03fc;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040c;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041c;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042c;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043c;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044c;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045c;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046c;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047c;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048c;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049c;
    unsigned int unk04a0;
    unsigned int unk04a4;
    unsigned int unk04a8;
    unsigned int unk04ac;
    unsigned int unk04b0;
    unsigned int unk04b4;
    unsigned int unk04b8;
    unsigned int unk04bc;
    unsigned int unk04c0;
    unsigned int unk04c4;
    unsigned int unk04c8;
    unsigned int unk04cc;
    unsigned int unk04d0;
    unsigned int unk04d4;
    unsigned int unk04d8;
    unsigned int unk04dc;
    unsigned int unk04e0;
    unsigned int unk04e4;
    unsigned int unk04e8;
    unsigned int unk04ec;
    unsigned int unk04f0;
    unsigned int unk04f4;
    unsigned int unk04f8;
    unsigned int unk04fc;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050c;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051c;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052c;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053c;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054c;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055c;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056c;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057c;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058c;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059c;
    unsigned int unk05a0;
    unsigned int unk05a4;
    unsigned int unk05a8;
    unsigned int unk05ac;
    unsigned int unk05b0;
    unsigned int unk05b4;
    unsigned int unk05b8;
    unsigned int unk05bc;
    unsigned int unk05c0;
    unsigned int unk05c4;
    unsigned int unk05c8;
    unsigned int unk05cc;
    unsigned int unk05d0;
    unsigned int unk05d4;
    unsigned int unk05d8;
    unsigned int unk05dc;
    unsigned int unk05e0;
    unsigned int unk05e4;
    unsigned int unk05e8;
    unsigned int unk05ec;
    unsigned int unk05f0;
    unsigned int unk05f4;
    unsigned int unk05f8;
    unsigned int unk05fc;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060c;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061c;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062c;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063c;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064c;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065c;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066c;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067c;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068c;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069c;
    unsigned int unk06a0;
    unsigned int unk06a4;
    unsigned int unk06a8;
    unsigned int unk06ac;
    unsigned int unk06b0;
    unsigned int unk06b4;
    unsigned int unk06b8;
    unsigned int unk06bc;
    unsigned int unk06c0;
    unsigned int unk06c4;
    unsigned int unk06c8;
    unsigned int unk06cc;
    unsigned int unk06d0;
    unsigned int unk06d4;
    unsigned int unk06d8;
    unsigned int unk06dc;
    unsigned int unk06e0;
    unsigned int unk06e4;
    unsigned int unk06e8;
    unsigned int unk06ec;
    unsigned int unk06f0;
    unsigned int unk06f4;
    unsigned int unk06f8;
    unsigned int unk06fc;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070c;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071c;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072c;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073c;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074c;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075c;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076c;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077c;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078c;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079c;
    unsigned int unk07a0;
    unsigned int unk07a4;
    unsigned int unk07a8;
    unsigned int unk07ac;
    unsigned int unk07b0;
    unsigned int unk07b4;
    unsigned int unk07b8;
    unsigned int unk07bc;
    unsigned int unk07c0;
    unsigned int unk07c4;
    unsigned int unk07c8;
    unsigned int unk07cc;
    unsigned int unk07d0;
    unsigned int unk07d4;
    unsigned int unk07d8;
    unsigned int unk07dc;
    unsigned int unk07e0;
    unsigned int unk07e4;
    unsigned int unk07e8;
    unsigned int unk07ec;
    unsigned int unk07f0;
    unsigned int unk07f4;
    unsigned int unk07f8;
    unsigned int unk07fc;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080c;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081c;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082c;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083c;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084c;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085c;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086c;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087c;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088c;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089c;
    unsigned int unk08a0;
    unsigned int unk08a4;
    unsigned int unk08a8;
    unsigned int unk08ac;
    unsigned int unk08b0;
    unsigned int unk08b4;
    unsigned int unk08b8;
    unsigned int unk08bc;
    unsigned int unk08c0;
    unsigned int unk08c4;
    unsigned int unk08c8;
    unsigned int unk08cc;
    unsigned int unk08d0;
    unsigned int unk08d4;
    unsigned int unk08d8;
    unsigned int unk08dc;
    unsigned int unk08e0;
    unsigned int unk08e4;
    unsigned int unk08e8;
    unsigned int unk08ec;
    unsigned int unk08f0;
    unsigned int unk08f4;
    unsigned int unk08f8;
    unsigned int unk08fc;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090c;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091c;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092c;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093c;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094c;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095c;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096c;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097c;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098c;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099c;
    unsigned int unk09a0;
    unsigned int unk09a4;
    unsigned int unk09a8;
    unsigned int unk09ac;
    unsigned int unk09b0;
    unsigned int unk09b4;
    unsigned int unk09b8;
    unsigned int unk09bc;
    unsigned int unk09c0;
    unsigned int unk09c4;
    unsigned int unk09c8;
    unsigned int unk09cc;
    unsigned int unk09d0;
    unsigned int unk09d4;
    unsigned int unk09d8;
    unsigned int unk09dc;
    unsigned int unk09e0;
    unsigned int unk09e4;
    unsigned int unk09e8;
    unsigned int unk09ec;
    unsigned int unk09f0;
    unsigned int unk09f4;
    unsigned int unk09f8;
    unsigned int unk09fc;
    unsigned int unk0a00;
    unsigned int unk0a04;
    unsigned int unk0a08;
    unsigned int unk0a0c;
    unsigned int unk0a10;
    unsigned int unk0a14;
    unsigned int unk0a18;
    unsigned int unk0a1c;
    unsigned int unk0a20;
    unsigned int unk0a24;
    unsigned int unk0a28;
    unsigned int unk0a2c;
    unsigned int unk0a30;
    unsigned int unk0a34;
    unsigned int unk0a38;
    unsigned int unk0a3c;
    unsigned int unk0a40;
    unsigned int unk0a44;
    unsigned int unk0a48;
    unsigned int unk0a4c;
    unsigned int unk0a50;
    unsigned int unk0a54;
    unsigned int unk0a58;
    unsigned int unk0a5c;
    unsigned int unk0a60;
    unsigned int unk0a64;
    unsigned int unk0a68;
    unsigned int unk0a6c;
    unsigned int unk0a70;
    unsigned int unk0a74;
    unsigned int unk0a78;
    unsigned int unk0a7c;
    unsigned int unk0a80;
    unsigned int unk0a84;
    unsigned int unk0a88;
    unsigned int unk0a8c;
    unsigned int unk0a90;
    unsigned int unk0a94;
    unsigned int unk0a98;
    unsigned int unk0a9c;
    unsigned int unk0aa0;
    unsigned int unk0aa4;
    unsigned int unk0aa8;
    unsigned int unk0aac;
    unsigned int unk0ab0;
    unsigned int unk0ab4;
    unsigned int unk0ab8;
    unsigned int unk0abc;
    unsigned int unk0ac0;
    unsigned int unk0ac4;
    unsigned int unk0ac8;
    unsigned int unk0acc;
    unsigned int unk0ad0;
    unsigned int unk0ad4;
    unsigned int unk0ad8;
    unsigned int unk0adc;
    unsigned int unk0ae0;
    unsigned int unk0ae4;
    unsigned int unk0ae8;
    unsigned int unk0aec;
    unsigned int unk0af0;
    unsigned int unk0af4;
    unsigned int unk0af8;
    unsigned int unk0afc;
    unsigned int unk0b00;
    unsigned int unk0b04;
    unsigned int unk0b08;
    unsigned int unk0b0c;
    unsigned int unk0b10;
    unsigned int unk0b14;
    unsigned int unk0b18;
    unsigned int unk0b1c;
    unsigned int unk0b20;
    unsigned int unk0b24;
    unsigned int unk0b28;
    unsigned int unk0b2c;
    unsigned int unk0b30;
    unsigned int unk0b34;
    unsigned int unk0b38;
    unsigned int unk0b3c;
    unsigned int unk0b40;
    unsigned int unk0b44;
    unsigned int unk0b48;
    unsigned int unk0b4c;
    unsigned int unk0b50;
    unsigned int unk0b54;
    unsigned int unk0b58;
    unsigned int unk0b5c;
    unsigned int unk0b60;
    unsigned int unk0b64;
    unsigned int unk0b68;
    unsigned int unk0b6c;
    unsigned int unk0b70;
    unsigned int unk0b74;
    unsigned int unk0b78;
    unsigned int unk0b7c;
    unsigned int unk0b80;
    unsigned int unk0b84;
    unsigned int unk0b88;
    unsigned int unk0b8c;
    unsigned int unk0b90;
    unsigned int unk0b94;
    unsigned int unk0b98;
    unsigned int unk0b9c;
    unsigned int unk0ba0;
    unsigned int unk0ba4;
    unsigned int unk0ba8;
    unsigned int unk0bac;
    unsigned int unk0bb0;
    unsigned int unk0bb4;
    unsigned int unk0bb8;
    unsigned int unk0bbc;
    unsigned int unk0bc0;
    unsigned int unk0bc4;
    unsigned int unk0bc8;
    unsigned int unk0bcc;
    unsigned int unk0bd0;
    unsigned int unk0bd4;
    unsigned int unk0bd8;
    unsigned int unk0bdc;
    unsigned int unk0be0;
    unsigned int unk0be4;
    unsigned int unk0be8;
    unsigned int unk0bec;
    unsigned int unk0bf0;
    unsigned int unk0bf4;
    unsigned int unk0bf8;
    unsigned int unk0bfc;
    unsigned int unk0c00;
    unsigned int unk0c04;
    unsigned int unk0c08;
    unsigned int unk0c0c;
    unsigned int unk0c10;
    unsigned int unk0c14;
    unsigned int unk0c18;
    unsigned int unk0c1c;
    unsigned int unk0c20;
    unsigned int unk0c24;
    unsigned int unk0c28;
    unsigned int unk0c2c;
    unsigned int unk0c30;
    unsigned int unk0c34;
    unsigned int unk0c38;
    unsigned int unk0c3c;
    unsigned int unk0c40;
    unsigned int unk0c44;
    unsigned int unk0c48;
    unsigned int unk0c4c;
    unsigned int unk0c50;
    unsigned int unk0c54;
    unsigned int unk0c58;
    unsigned int unk0c5c;
    unsigned int unk0c60;
    unsigned int unk0c64;
    unsigned int unk0c68;
    unsigned int unk0c6c;
    unsigned int unk0c70;
    unsigned int unk0c74;
    unsigned int unk0c78;
    unsigned int unk0c7c;
    unsigned int unk0c80;
    unsigned int unk0c84;
    unsigned int unk0c88;
    unsigned int unk0c8c;
    unsigned int unk0c90;
    unsigned int unk0c94;
    unsigned int unk0c98;
    unsigned int unk0c9c;
    unsigned int unk0ca0;
    unsigned int unk0ca4;
    unsigned int unk0ca8;
    unsigned int unk0cac;
    unsigned int unk0cb0;
    unsigned int unk0cb4;
    unsigned int unk0cb8;
    unsigned int unk0cbc;
    unsigned int unk0cc0;
    unsigned int unk0cc4;
    unsigned int unk0cc8;
    unsigned int unk0ccc;
    unsigned int unk0cd0;
    unsigned int unk0cd4;
    unsigned int unk0cd8;
    unsigned int unk0cdc;
    unsigned int unk0ce0;
    unsigned int unk0ce4;
    unsigned int unk0ce8;
    unsigned int unk0cec;
    unsigned int unk0cf0;
    unsigned int unk0cf4;
    unsigned int unk0cf8;
    unsigned int unk0cfc;
    unsigned int unk0d00;
    unsigned int unk0d04;
    unsigned int unk0d08;
    unsigned int unk0d0c;
    unsigned int unk0d10;
    unsigned int unk0d14;
    unsigned int unk0d18;
    unsigned int unk0d1c;
    unsigned int unk0d20;
    unsigned int unk0d24;
    unsigned int unk0d28;
    unsigned int unk0d2c;
    unsigned int unk0d30;
    unsigned int unk0d34;
    unsigned int unk0d38;
    unsigned int unk0d3c;
    unsigned int unk0d40;
    unsigned int unk0d44;
    unsigned int unk0d48;
    unsigned int unk0d4c;
    unsigned int unk0d50;
    unsigned int unk0d54;
    unsigned int unk0d58;
    unsigned int unk0d5c;
    unsigned int unk0d60;
    unsigned int unk0d64;
    unsigned int unk0d68;
    unsigned int unk0d6c;
    unsigned int unk0d70;
    unsigned int unk0d74;
    unsigned int unk0d78;
    unsigned int unk0d7c;
    unsigned int unk0d80;
    unsigned int unk0d84;
    unsigned int unk0d88;
    unsigned int unk0d8c;
    unsigned int unk0d90;
    unsigned int unk0d94;
    unsigned int unk0d98;
    unsigned int unk0d9c;
    unsigned int unk0da0;
    unsigned int unk0da4;
    unsigned int unk0da8;
    unsigned int unk0dac;
    unsigned int unk0db0;
    unsigned int unk0db4;
    unsigned int unk0db8;
    unsigned int unk0dbc;
    unsigned int unk0dc0;
    unsigned int unk0dc4;
    unsigned int unk0dc8;
    unsigned int unk0dcc;
    unsigned int unk0dd0;
    unsigned int unk0dd4;
    unsigned int unk0dd8;
    unsigned int unk0ddc;
    unsigned int unk0de0;
    unsigned int unk0de4;
    unsigned int unk0de8;
    unsigned int unk0dec;
    unsigned int unk0df0;
    unsigned int unk0df4;
    unsigned int unk0df8;
    unsigned int unk0dfc;
    unsigned int unk0e00;
    unsigned int unk0e04;
    unsigned int unk0e08;
    unsigned int unk0e0c;
    unsigned int unk0e10;
    unsigned int unk0e14;
    unsigned int unk0e18;
    unsigned int unk0e1c;
    unsigned int unk0e20;
    unsigned int unk0e24;
    unsigned int unk0e28;
    unsigned int unk0e2c;
    unsigned int unk0e30;
    unsigned int unk0e34;
    unsigned int unk0e38;
    unsigned int unk0e3c;
    unsigned int unk0e40;
    unsigned int unk0e44;
    unsigned int unk0e48;
    unsigned int unk0e4c;
    unsigned int unk0e50;
    unsigned int unk0e54;
    unsigned int unk0e58;
    unsigned int unk0e5c;
    unsigned int unk0e60;
    unsigned int unk0e64;
    unsigned int unk0e68;
    unsigned int unk0e6c;
    unsigned int unk0e70;
    unsigned int unk0e74;
    unsigned int unk0e78;
    unsigned int unk0e7c;
    unsigned int unk0e80;
    unsigned int unk0e84;
    unsigned int unk0e88;
    unsigned int unk0e8c;
    unsigned int unk0e90;
    unsigned int unk0e94;
    unsigned int unk0e98;
    unsigned int unk0e9c;
    unsigned int unk0ea0;
    unsigned int unk0ea4;
    unsigned int unk0ea8;
    unsigned int unk0eac;
    unsigned int unk0eb0;
    unsigned int unk0eb4;
    unsigned int unk0eb8;
    unsigned int unk0ebc;
    unsigned int unk0ec0;
    unsigned int unk0ec4;
    unsigned int unk0ec8;
    unsigned int unk0ecc;
    unsigned int unk0ed0;
    unsigned int unk0ed4;
    unsigned int unk0ed8;
    unsigned int unk0edc;
    unsigned int unk0ee0;
    unsigned int unk0ee4;
    unsigned int unk0ee8;
    unsigned int unk0eec;
    unsigned int unk0ef0;
    unsigned int unk0ef4;
    unsigned int unk0ef8;
    unsigned int unk0efc;
    unsigned int unk0f00;
    unsigned int unk0f04;
    unsigned int unk0f08;
    unsigned int unk0f0c;
    unsigned int unk0f10;
    unsigned int unk0f14;
    unsigned int unk0f18;
    unsigned int unk0f1c;
    unsigned int unk0f20;
    unsigned int unk0f24;
    unsigned int unk0f28;
    unsigned int unk0f2c;
    unsigned int unk0f30;
    unsigned int unk0f34;
    unsigned int unk0f38;
    unsigned int unk0f3c;
    unsigned int unk0f40;
    unsigned int unk0f44;
    unsigned int unk0f48;
    unsigned int unk0f4c;
    unsigned int unk0f50;
    unsigned int unk0f54;
    unsigned int unk0f58;
    unsigned int unk0f5c;
    unsigned int unk0f60;
    unsigned int unk0f64;
    unsigned int unk0f68;
    unsigned int unk0f6c;
    unsigned int unk0f70;
    unsigned int unk0f74;
    unsigned int unk0f78;
    unsigned int unk0f7c;
    unsigned int unk0f80;
    unsigned int unk0f84;
    unsigned int unk0f88;
    unsigned int unk0f8c;
    unsigned int unk0f90;
    unsigned int unk0f94;
    unsigned int unk0f98;
    unsigned int unk0f9c;
    unsigned int unk0fa0;
    unsigned int unk0fa4;
    unsigned int unk0fa8;
    unsigned int unk0fac;
    unsigned int unk0fb0;
    unsigned int unk0fb4;
    unsigned int unk0fb8;
    unsigned int unk0fbc;
    unsigned int unk0fc0;
    unsigned int unk0fc4;
    unsigned int unk0fc8;
    unsigned int unk0fcc;
    unsigned int unk0fd0;
    unsigned int unk0fd4;
    unsigned int unk0fd8;
    unsigned int unk0fdc;
    unsigned int unk0fe0;
    unsigned int unk0fe4;
    unsigned int unk0fe8;
    unsigned int unk0fec;
    unsigned int unk0ff0;
    unsigned int unk0ff4;
    unsigned int unk0ff8;
    unsigned int unk0ffc;
    unsigned int unk1000;
    unsigned int unk1004;
    unsigned int unk1008;
    unsigned int unk100c;
    unsigned int unk1010;
    unsigned int unk1014;
    unsigned int unk1018;
    unsigned int unk101c;
    unsigned int unk1020;
    unsigned int unk1024;
    unsigned int unk1028;
    unsigned int unk102c;
    unsigned int unk1030;
    unsigned int unk1034;
    unsigned int unk1038;
    unsigned int unk103c;
    unsigned int unk1040;
    unsigned int unk1044;
    unsigned int unk1048;
    unsigned int unk104c;
    unsigned int unk1050;
    unsigned int unk1054;
    unsigned int unk1058;
    unsigned int unk105c;
    unsigned int unk1060;
    unsigned int unk1064;
    unsigned int unk1068;
    unsigned int unk106c;
    unsigned int unk1070;
    unsigned int unk1074;
    unsigned int unk1078;
    unsigned int unk107c;
    unsigned int unk1080;
    unsigned int unk1084;
    unsigned int unk1088;
    unsigned int unk108c;
    unsigned int unk1090;
    unsigned int unk1094;
    unsigned int unk1098;
    unsigned int unk109c;
    unsigned int unk10a0;
    unsigned int unk10a4;
    unsigned int unk10a8;
    unsigned int unk10ac;
    unsigned int unk10b0;
    unsigned int unk10b4;
    unsigned int unk10b8;
    unsigned int unk10bc;
    unsigned int unk10c0;
    unsigned int unk10c4;
    unsigned int unk10c8;
    unsigned int unk10cc;
    unsigned int unk10d0;
    unsigned int unk10d4;
    unsigned int unk10d8;
    unsigned int unk10dc;
    unsigned int unk10e0;
    unsigned int unk10e4;
    unsigned int unk10e8;
    unsigned int unk10ec;
    unsigned int unk10f0;
    unsigned int unk10f4;
    unsigned int unk10f8;
    unsigned int unk10fc;
    unsigned int unk1100;
    unsigned int unk1104;
    unsigned int unk1108;
    unsigned int unk110c;
    unsigned int unk1110;
    unsigned int unk1114;
    unsigned int unk1118;
    unsigned int unk111c;
    unsigned int unk1120;
    unsigned int unk1124;
    unsigned int unk1128;
    unsigned int unk112c;
    unsigned int unk1130;
    unsigned int unk1134;
    unsigned int unk1138;
    unsigned int unk113c;
    unsigned int unk1140;
    unsigned int unk1144;
    unsigned int unk1148;
    unsigned int unk114c;
    unsigned int unk1150;
    unsigned int unk1154;
    unsigned int unk1158;
    unsigned int unk115c;
    unsigned int unk1160;
    unsigned int unk1164;
    unsigned int unk1168;
    unsigned int unk116c;
    unsigned int unk1170;
    unsigned int unk1174;
    unsigned int unk1178;
    unsigned int unk117c;
    unsigned int unk1180;
    unsigned int unk1184;
    unsigned int unk1188;
    unsigned int unk118c;
    unsigned int unk1190;
    unsigned int unk1194;
    unsigned int unk1198;
    unsigned int unk119c;
    unsigned int unk11a0;
    unsigned int unk11a4;
    unsigned int unk11a8;
    unsigned int unk11ac;
    unsigned int unk11b0;
    unsigned int unk11b4;
    unsigned int unk11b8;
    unsigned int unk11bc;
    unsigned int unk11c0;
    unsigned int unk11c4;
    unsigned int unk11c8;
    unsigned int unk11cc;
    unsigned int unk11d0;
    unsigned int unk11d4;
    unsigned int unk11d8;
    unsigned int unk11dc;
    unsigned int unk11e0;
    unsigned int unk11e4;
    unsigned int unk11e8;
    unsigned int unk11ec;
    unsigned int unk11f0;
    unsigned int unk11f4;
    unsigned int unk11f8;
    unsigned int unk11fc;
    unsigned int unk1200;
    unsigned int unk1204;
    unsigned int unk1208;
    unsigned int unk120c;
    unsigned int unk1210;
    unsigned int unk1214;
    unsigned int unk1218;
    unsigned int unk121c;
    unsigned int unk1220;
    unsigned int unk1224;
    unsigned int unk1228;
    unsigned int unk122c;
    unsigned int unk1230;
    unsigned int unk1234;
    unsigned int unk1238;
    unsigned int unk123c;
    unsigned int unk1240;
    unsigned int unk1244;
    unsigned int unk1248;
    unsigned int unk124c;
    unsigned int unk1250;
    unsigned int unk1254;
    unsigned int unk1258;
    unsigned int unk125c;
    unsigned int unk1260;
    unsigned int unk1264;
    unsigned int unk1268;
    unsigned int unk126c;
    unsigned int unk1270;
    unsigned int unk1274;
    unsigned int unk1278;
    unsigned int unk127c;
    unsigned int unk1280;
    unsigned int unk1284;
    unsigned int unk1288;
    unsigned int unk128c;
    unsigned int unk1290;
    unsigned int unk1294;
    unsigned int unk1298;
    unsigned int unk129c;
    unsigned int unk12a0;
    unsigned int unk12a4;
    unsigned int unk12a8;
    unsigned int unk12ac;
    unsigned int unk12b0;
    unsigned int unk12b4;
    unsigned int unk12b8;
    unsigned int unk12bc;
    unsigned int unk12c0;
    unsigned int unk12c4;
    unsigned int unk12c8;
    unsigned int unk12cc;
    unsigned int unk12d0;
    unsigned int unk12d4;
    unsigned int unk12d8;
    unsigned int unk12dc;
    unsigned int unk12e0;
    unsigned int unk12e4;
    unsigned int unk12e8;
    unsigned int unk12ec;
    unsigned int unk12f0;
    unsigned int unk12f4;
    unsigned int unk12f8;
    unsigned int unk12fc;
    unsigned int unk1300;
    unsigned int unk1304;
    unsigned int unk1308;
    unsigned int unk130c;
    unsigned int unk1310;
    unsigned int unk1314;
    unsigned int unk1318;
    unsigned int unk131c;
    unsigned int unk1320;
    unsigned int unk1324;
    unsigned int unk1328;
    unsigned int unk132c;
    unsigned int unk1330;
    unsigned int unk1334;
    unsigned int unk1338;
    unsigned int unk133c;
    unsigned int unk1340;
    unsigned int unk1344;
    unsigned int unk1348;
    unsigned int unk134c;
    unsigned int unk1350;
    unsigned int unk1354;
    unsigned int unk1358;
    unsigned int unk135c;
    unsigned int unk1360;
    unsigned int unk1364;
    unsigned int unk1368;
    unsigned int unk136c;
    unsigned int unk1370;
    unsigned int unk1374;
    unsigned int unk1378;
    unsigned int unk137c;
    unsigned int unk1380;
    unsigned int unk1384;
    unsigned int unk1388;
    unsigned int unk138c;
    unsigned int unk1390;
    unsigned int unk1394;
    unsigned int unk1398;
    unsigned int unk139c;
    unsigned int unk13a0;
    unsigned int unk13a4;
    unsigned int unk13a8;
    unsigned int unk13ac;
    unsigned int unk13b0;
    unsigned int unk13b4;
    unsigned int unk13b8;
    unsigned int unk13bc;
    unsigned int unk13c0;
    unsigned int unk13c4;
    unsigned int unk13c8;
    unsigned int unk13cc;
    unsigned int unk13d0;
    unsigned int unk13d4;
    unsigned int unk13d8;
    unsigned int unk13dc;
    unsigned int unk13e0;
    unsigned int unk13e4;
    unsigned int unk13e8;
    unsigned int unk13ec;
    unsigned int unk13f0;
    unsigned int unk13f4;
    unsigned int unk13f8;
    unsigned int unk13fc;
    unsigned int unk1400;
    unsigned int unk1404;
    unsigned int unk1408;
    unsigned int unk140c;
    unsigned int unk1410;
    unsigned int unk1414;
    unsigned int unk1418;
    unsigned int unk141c;
    unsigned int unk1420;
    unsigned int unk1424;
    unsigned int unk1428;
    unsigned int unk142c;
    unsigned int unk1430;
    unsigned int unk1434;
    unsigned int unk1438;
    unsigned int unk143c;
    unsigned int unk1440;
    unsigned int unk1444;
    unsigned int unk1448;
    unsigned int unk144c;
    unsigned int unk1450;
    unsigned int unk1454;
    unsigned int unk1458;
    unsigned int unk145c;
    unsigned int unk1460;
    unsigned int unk1464;
    unsigned int unk1468;
    unsigned int unk146c;
    unsigned int unk1470;
    unsigned int unk1474;
    unsigned int unk1478;
    unsigned int unk147c;
    unsigned int unk1480;
    unsigned int unk1484;
    unsigned int unk1488;
    unsigned int unk148c;
    unsigned int unk1490;
    unsigned int unk1494;
    unsigned int unk1498;
    unsigned int unk149c;
    unsigned int unk14a0;
    unsigned int unk14a4;
    unsigned int unk14a8;
    unsigned int unk14ac;
    unsigned int unk14b0;
    unsigned int unk14b4;
    unsigned int unk14b8;
    unsigned int unk14bc;
    unsigned int unk14c0;
    unsigned int unk14c4;
    unsigned int unk14c8;
    unsigned int unk14cc;
    unsigned int unk14d0;
    unsigned int unk14d4;
    unsigned int unk14d8;
    unsigned int unk14dc;
    unsigned int unk14e0;
    unsigned int unk14e4;
    unsigned int unk14e8;
    unsigned int unk14ec;
    unsigned int unk14f0;
    unsigned int unk14f4;
    unsigned int unk14f8;
    unsigned int unk14fc;
    unsigned int unk1500;
    unsigned int unk1504;
    unsigned int unk1508;
    unsigned int unk150c;
    unsigned int unk1510;
    unsigned int unk1514;
    unsigned int unk1518;
    unsigned int unk151c;
    unsigned int unk1520;
    unsigned int unk1524;
    unsigned int unk1528;
    unsigned int unk152c;
    unsigned int unk1530;
    unsigned int unk1534;
    unsigned int unk1538;
    unsigned int unk153c;
    unsigned int unk1540;
    unsigned int unk1544;
    unsigned int unk1548;
    unsigned int unk154c;
    unsigned int unk1550;
    unsigned int unk1554;
    unsigned int unk1558;
    unsigned int unk155c;
    unsigned int unk1560;
    unsigned int unk1564;
    unsigned int unk1568;
    unsigned int unk156c;
    unsigned int unk1570;
    unsigned int unk1574;
    unsigned int unk1578;
    unsigned int unk157c;
    unsigned int unk1580;
    unsigned int unk1584;
    unsigned int unk1588;
    unsigned int unk158c;
    unsigned int unk1590;
    unsigned int unk1594;
    unsigned int unk1598;
    unsigned int unk159c;
    unsigned int unk15a0;
    unsigned int unk15a4;
    unsigned int unk15a8;
    unsigned int unk15ac;
    unsigned int unk15b0;
    unsigned int unk15b4;
    unsigned int unk15b8;
    unsigned int unk15bc;
    unsigned int unk15c0;
    unsigned int unk15c4;
    unsigned int unk15c8;
    unsigned int unk15cc;
    unsigned int unk15d0;
    unsigned int unk15d4;
    unsigned int unk15d8;
    unsigned int unk15dc;
    unsigned int unk15e0;
    unsigned int unk15e4;
    unsigned int unk15e8;
    unsigned int unk15ec;
    unsigned int unk15f0;
    unsigned int unk15f4;
    unsigned int unk15f8;
    unsigned int unk15fc;
    unsigned int unk1600;
    unsigned int unk1604;
    unsigned int unk1608;
    unsigned int unk160c;
    unsigned int unk1610;
    unsigned int unk1614;
    unsigned int unk1618;
    unsigned int unk161c;
    unsigned int unk1620;
    unsigned int unk1624;
    unsigned int unk1628;
    unsigned int unk162c;
    unsigned int unk1630;
    unsigned int unk1634;
    unsigned int unk1638;
    unsigned int unk163c;
    unsigned int unk1640;
    unsigned int unk1644;
    unsigned int unk1648;
    unsigned int unk164c;
    unsigned int unk1650;
    unsigned int unk1654;
    unsigned int unk1658;
    unsigned int unk165c;
    unsigned int unk1660;
    unsigned int unk1664;
    unsigned int unk1668;
    unsigned int unk166c;
    unsigned int unk1670;
    unsigned int unk1674;
    unsigned int unk1678;
    unsigned int unk167c;
    unsigned int unk1680;
    unsigned int unk1684;
    unsigned int unk1688;
    unsigned int unk168c;
    unsigned int unk1690;
    unsigned int unk1694;
    unsigned int unk1698;
    unsigned int unk169c;
    unsigned int unk16a0;
    unsigned int unk16a4;
    unsigned int unk16a8;
    unsigned int unk16ac;
    unsigned int unk16b0;
    unsigned int unk16b4;
    unsigned int unk16b8;
    unsigned int unk16bc;
    unsigned int unk16c0;
    unsigned int unk16c4;
    unsigned int unk16c8;
    unsigned int unk16cc;
    unsigned int unk16d0;
    unsigned int unk16d4;
    unsigned int unk16d8;
    Entry entries[256];
};
void SwapHeaderBytesAndAdvance(Input*);
void SwapQuadBytes(Input*);
void FUN_00e05eb0(Input*);
void SwapHkHeaderE05E(Payload*);
void SwapHeaderEndianness(Payload*);
void FUN_00e05fe0(Payload*);
void FUN_00e06010(void*);
void ProcessListBlocks(Context**, void*);
void ProcessInput(Context** context, Input* input, void* argument, bool reverse, int* type, bool* changed);
struct ListEntryE061
{
    int unk;
    int uTmpnk;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    int m_1c;
};
struct FlagE061
{
    unsigned char m_00;
    unsigned char unkCur;
    unsigned char unkValue;
    unsigned char uNewnk;
};
struct BlockE061
{
    int m_00;
};
struct ListE061
{
    BlockE061** m_00;
    int m_04;
    int unk08;
    ListEntryE061** m_0c;
    int m_10;
};
void __cdecl ProcessInput(int a1, char* pos, ListEntryE061* cur, FlagE061 flag, int* consumed, bool* pbOut);
void __cdecl ProcessListBlocks(int a1, ListE061* list);
void ReverseBytesInGroupsOfFour(unsigned char* pucData);
struct S_e05_res
{
    char* __thiscall FUN_00d46d80(char* a, S_e05_res* b);
};
struct S_e05_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual S_e05_res* m4(int value);
};
struct S_e05_g
{
    S_e05_obj* volatile obj;
    int volatile arg;
    int volatile val;
    bool volatile out;
};
S_e05_g g_e05 = {0, 0, 0, 0};
inline void swap16E05E(void* pv)
{
    char* c = (char*)pv;
    char t = c[0];
    c[0] = c[1];
    c[1] = t;
}
inline void swapE05E(char& a, char& b)
{
    char t = a;
    a = b;
    b = t;
}
inline void swap32E05E(void* pv)
{
    char* c = (char*)pv;
    swapE05E(c[0], c[3]);
    swapE05E(c[1], c[2]);
}
struct hkEntryE05E
{
    unsigned short m_uiFilterValue;
    unsigned short m_auiShapeKeys;
};
struct hkHeaderE05E
{
    unsigned char unk00;
    unsigned char unk01;
    hkEntryE05E m_entries[7];
    unsigned char unk1E;
    unsigned char unk1F;
    unsigned char unk20;
    unsigned char m_iNumberOfEntries;
    unsigned char unk22;
    unsigned char unk23;
    int m_24;
    int unk28;
    int unk2c;
    int m_30[4];
};
void __cdecl SwapHkHeaderE05E(hkHeaderE05E* h);
template <int SIZE> __forceinline void memCpyOneAlignedE030(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}
struct hkMemoryRouterE030
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};
namespace hkRouterE030 {
extern "C" hkMemoryRouterE030& __cdecl FUN_00c85750();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);
template <class T> class hkArrayE030
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterE030& router = hkRouterE030::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedE030<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
    __forceinline T& AllocatePair()
    {
        hkMemoryRouterE030& router = hkRouterE030::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        for (int i = 0; i < 1; ++i)
            new (m_data + m_iElementCount + i) T;
        return m_data[m_iElementCount++];
    }
};
int __cdecl ReadIntAtOffset(const char* pcData, int* piPos);
int __cdecl ReadPaddedString(const char* pcData, int* piPos);
// sub ecx,8; jmp target  ==  MSVC adjustor thunk (second base of a multiple-inheritance override)
struct SpawnedPrimaryBase
{
    virtual void FUN_00e00980();
    int unk04;
};
struct SpawnedSecondaryBase
{
    virtual void FUN_00e00980();
};
struct SpawnedDerived : SpawnedPrimaryBase, SpawnedSecondaryBase
{
    SpawnedDerived();
// @fnv 0x00e00980
    virtual void FUN_00e00980();
};
SpawnedDerived::SpawnedDerived()
{}
extern "C" void _ReadWriteBarrier();
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);
struct ExportPlacement;
inline void* operator new(unsigned int, ExportPlacement* address)
{
    return address;
}
struct ExportHeap
{
    int unk00, unk04, unk08, unk0c;
    void* heap;
    static ExportHeap& __cdecl FUN_00c85750();
};
struct ExportAlloc
{
    __forceinline ExportHeap& get(void*) const
    {
        return ExportHeap::FUN_00c85750();
    }
};
template <class T> __forceinline void createExportObjects(T* first, int count)
{
    for (int remaining = 0; remaining < count; ++remaining)
        new (reinterpret_cast<ExportPlacement*>(first + remaining)) T;
}
template <class T> struct ExportStorage
{
    T* data;
    int size;
    int capacity;
    __forceinline int capacityValue() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline T& addWith(ExportHeap& router)
    {
        if (size == capacityValue())
            ResizeAudioStream(router.heap, this, sizeof(T));
        createExportObjects(data + size, 1);
        return data[size++];
    }
};
template <class T, class A> struct ExportList : ExportStorage<T>
{
    __forceinline T& add()
    {
        return this->addWith(A().get(this));
    }
};
struct Allocator;
class BSAudio
{
  public:
    int unk00, unk04, unk08, unk0c;
    Allocator* unk10;
    Allocator& heap()
    {
        return *unk10;
    }
};
struct PtrMap
{
    void* unk00;
    int unk04;
    int unk08;
    __forceinline void init()
    {
        unk00 = 0;
        unk04 = 0;
        unk08 = -1;
        EnsureCapacity(FUN_00c85750()->heap(), 0);
    }
    __forceinline void destroy()
    {
        ProcessArgument(FUN_00c85750()->heap());
        FUN_00a29680();
    }
    void EnsureCapacity(Allocator& allocator, int count);
    void FUN_00cb1870(Allocator& allocator, unsigned int key, unsigned int value);
    unsigned int LookupHashEntry(unsigned int key, unsigned int defaultValue);
    void FUN_00cb1fb0(unsigned int key);
    void ProcessArgument(Allocator& allocator);
    void FUN_00a29680();
    __forceinline void insert(unsigned int key, unsigned int value)
    {
        FUN_00cb1870(FUN_00c85750()->heap(), key, value);
    }
    __forceinline unsigned int FindValueForKey(unsigned int key, unsigned int def)
    {
        return LookupHashEntry(key, def);
    }
    __forceinline void remove(unsigned int key)
    {
        FUN_00cb1fb0(key);
    }
};
struct Vec4
{
    float x, y, z, w;
};
template <class T> struct ListItem
{
    T* m_next;
    T* m_pSecondNode;
    ListItem()
    {}
    ListItem(const ListItem&)
    {}
};
struct Vertex : ListItem<Vertex>
{
    int unk08;
    int unk0c;
    Vec4 m_vec10;
    Vec4 m_vec20;
    Vec4 m_vec30;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    Vertex(const Vertex& src)
        : ListItem<Vertex>(src), m_vec10(src.m_vec10), m_vec20(src.m_vec20), m_vec30(src.m_vec30), unk40(src.unk40),
          unk44(src.unk44)
    {}
};
struct Triangle;
struct TriangleTopologyEntry : ListItem<Triangle>
{
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    __forceinline Vertex*& vertex(int i)
    {
        return m_kVertices[i];
    }
    __forceinline unsigned int& link(int i)
    {
        return m_ppLinks[i];
    }
};
struct Triangle : TriangleTopologyEntry
{
    Vec4 m_vec20;
    int unk30, unk34, unk38, unk3c, unk40;
    int unk44;
    int unk48;
    int unk4c;
    Triangle(const Triangle& src)
        : TriangleTopologyEntry(src), m_vec20(src.m_vec20), unk30(src.unk30), unk34(src.unk34), unk38(src.unk38),
          unk3c(src.unk3c), unk40(src.unk40)
    {}
};
struct Topology
{
    static __forceinline unsigned int uid2ulong(void* t, unsigned int i)
    {
        return (*(const unsigned int*)&t) + (unsigned int)i;
    }
    template <class T> static __forceinline void ulong2uid(unsigned int uid, T*& t, unsigned int& i)
    {
        i = (unsigned int)(uid & 3);
        uid &= ~3;
        t = *(T**)&uid;
    }
    static __forceinline unsigned int packUid(void* t, unsigned int i)
    {
        return uid2ulong(t, i);
    }
    template <class T> static __forceinline void unpackUid(unsigned int uid, T*& t, unsigned int& i)
    {
        ulong2uid(uid, t, i);
    }
};
struct Edge
{
    Triangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;

    __forceinline Edge(Triangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    __forceinline Edge(const unsigned int& id)
    {
        Topology::unpackUid(id, m_pkTriangle, m_uiEdgeIndex);
    }
    __forceinline Triangle* triangle() const
    {
        return m_pkTriangle;
    }
    __forceinline Edge link() const
    {
        return Edge(m_pkTriangle->link(m_uiEdgeIndex));
    }
    __forceinline bool isValid() const
    {
        return triangle() != 0;
    }
    __forceinline bool isNaked() const
    {
        return !link().isValid();
    }
    __forceinline unsigned int uid() const
    {
        return Topology::packUid(m_pkTriangle, m_uiEdgeIndex);
    }
    __forceinline void bind(const Edge& edge) const
    {
        m_pkTriangle->link(m_uiEdgeIndex) = edge.uid();
        if (edge.isValid())
            edge.m_pkTriangle->link(edge.m_uiEdgeIndex) = uid();
    }
};
template <class T> struct PoolBlock
{
    T m_elements[32];
    T* m_free;
    int m_iAllocatedCount;
};
struct PoolBase
{
    void* FUN_00e23530();
};
template <class T> struct PoolList : PoolBase
{
    PoolBlock<T>** m_kBlocks;
    int m_iBlockCount;
    int unk08;
    T* m_pFirstNode;
    int m_iElementCount;
    int unk14;

    __forceinline void* allocateItem()
    {
        PoolBlock<T>* block = (m_iBlockCount && m_kBlocks[0]->m_free) ? m_kBlocks[0] : (PoolBlock<T>*)FUN_00e23530();
        T* element = block->m_free;
        block->m_free = *(T**)element;
        ++block->m_iAllocatedCount;
        return element;
    }
    __forceinline T* allocate(const T& value)
    {
        T* item = new (allocateItem()) T(value);
        item->m_pSecondNode = 0;
        item->m_next = m_pFirstNode;
        if (m_pFirstNode)
            m_pFirstNode->m_pSecondNode = item;
        m_iElementCount++;
        m_pFirstNode = item;
        return item;
    }
};
extern "C" void _ReadWriteBarrier();
struct ScalarQ
{
    __m128 value;
    ScalarQ(__m128 v) : value(v)
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
};
inline ScalarQ operator+(const ScalarQ& a, const ScalarQ& b)
{
    return _mm_add_ss(a.value, b.value);
}
struct VectorQ
{
    __m128 quad;
    float& operator()(int component)
    {
        return quad.m128_f32[component];
    }
    ScalarQ spatialDot(const VectorQ& other) const
    {
        __m128 product = _mm_mul_ps(quad, other.quad);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 85), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 170), xy);
    }
    ScalarQ componentAt(int component) const
    {
        _ReadWriteBarrier();
        switch (component)
        {
        case 0:
            return quad;
        case 1:
            return _mm_shuffle_ps(quad, quad, 85);
        case 2:
            return _mm_shuffle_ps(quad, quad, 170);
        case 3:
        default:
            return _mm_shuffle_ps(quad, quad, 255);
        }
    }
    ScalarQ distance(const VectorQ& plane) const
    {
        return spatialDot(plane) + plane.componentAt(3);
    }
};

struct SortItem
{
    int unk00;
    int unk04;
    int unk08;
    float fPriority;
};

struct SortedList
{
    int iCount;
    int unk04;
    SortItem** ppItems;

    void hkpMoppDefaultSplitter_hkpMoppMaxList_addElement(SortItem* apItem);
};

// @fnv 0x00e09670
// pdb: hkpMoppDefaultSplitter::hkpMoppMaxList::addElement | hkpMoppDefaultSplitter.obj | fnv360_0822_retail, call_gap_sim + bridge(call_seq|callee_sim) + skyrim(call_seq), high
void SortedList::hkpMoppDefaultSplitter_hkpMoppMaxList_addElement(SortItem* apItem)
{
    float fPriority = apItem->fPriority;
    int i;
    for (i = iCount - 1; i >= 0; i--)
    {
        if (!ppItems[i] || !(ppItems[i]->fPriority < fPriority))
            break;
        ppItems[i + 1] = ppItems[i];
    }
    ppItems[i + 1] = apItem;
    iCount++;
}
