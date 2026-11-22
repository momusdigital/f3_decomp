#include "f3_common.h"
// src/staging/blk_00a20000_o2_noehsc_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/staging/blk_00a20000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00a20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern "C" void __cdecl ReadBlockEntries(void*, void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern "C" void __cdecl SaveKey(int, int);
struct P03MM
{
    void* Allocate(unsigned int);
};
void* _memmove(void* d, const void* s, unsigned int n);
struct Vec3S
{
    float x, y, z;
};
struct Vec3R : Vec3S
{
    Vec3R()
    {}
};
struct TCBKeyS
{
    float time;
    Vec3S pos;
    Vec3S in;
    Vec3S out;
    float extra[6];
    ~TCBKeyS()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);
Vec3R GetKeyPosAtTime(float t, TCBKeyS* keys, int type, unsigned int count, unsigned int stride);
void FUN_00a420e0(float p0, float t0, float* tan0, float p1, float t1, float* tan1, float t, float p, float* a,
                  float* b);
void ComputeTCBKeyTangents(TCBKeyS* keys, unsigned int count, unsigned int stride);
void __cdecl IsLightEqual();
void __cdecl FUN_00a2af70();
void __cdecl ComputeInterpolatedPosition();
void __cdecl FUN_00a2b130();
void __cdecl NiTCBPosKey_Insert();
typedef int(__stdcall* FnInterlockedDecrement)(void*);
struct NiStream
{
    void* GetLoadedObject();
};
void BezKeyEqual();
void EvaluateCubicKey();
void FUN_00a27d60();
struct Helper
{
    unsigned int a;
    char b;
};
bool AreFloatsEqual(const Helper* x, const Helper* y);
bool FUN_00a291a0(const Helper* a, const Helper* b);
struct SStream;
struct SObj;
void __cdecl WriteFloatToStream(SStream*, SObj*);
struct FloatRecord_b5532
{
    int unk00;
    float m_04;
};
bool AreFloatsEqual(FloatRecord_b5532* a, FloatRecord_b5532* b);
typedef void(__thiscall* Fn_00a26fa0_cb)(void*);
struct TempArrayElement
{
    void* a;
    void* b;
    void* c;
    void* d;
    ~TempArrayElement()
    {}
    static void* operator new[](unsigned int size)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(size);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
extern MemoryManager g_memoryManager;
void* _memmove(void* d, const void* s, unsigned int n);
struct TCBKeyS;
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);
struct BezFloatKey
{
    float time;
    float value;
    float inTan;
    float outTan;
    ~BezFloatKey()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
void FUN_00a420e0(float p0, float t0, float* tan0, float p1, float t1, float* tan1, float t, float p, float* a,
                  float* b);
class A27250Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
struct A27250BinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(A27250BinaryStream* pkStream, void* pvBuffer, unsigned int uiSize, unsigned int* puiSizes,
                              unsigned int ItemUpdateArray);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};
class A27250Stream
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
    A27250BinaryStream* m_pUnderlyingStream;
};
template <class T> inline void A27250BinaryStreamLoad(A27250BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void A27250LoadBinary(A27250Stream& kStream, T& value)
{
    A27250BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
class A27250FloatKey
{
  public:
    ~A27250FloatKey();

    static void* operator new[](unsigned int uiSize)
    {
        return reinterpret_cast<A27250Heap&>(g_memoryManager).Allocate(uiSize);
    }

    void LoadBinary(A27250Stream& kStream);

    float m_fTime;
    float m_fValue;
    float m_fForwardTangent;
    float m_fBackwardTangent;
};
// ApplyAnimToTarget: forwards two arguments to NiAnimationKey_SaveBinary, then calls the
// member at +4 of the second argument with the first argument.
struct AnimNode
{
    void Apply(int n);
};
struct AnimTarget
{
    int unk00;
    AnimNode m_node;
};
void __cdecl NiAnimationKey_SaveBinary(int a, void* b);
void __cdecl ApplyAnimToTarget(int a, AnimTarget* b);
struct A27BD0Point3
{
    float x;
    float y;
    float z;

    bool IsEqual(const A27BD0Point3& kOther) const;
};
struct A27BD0Key
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct A27BD0BezKey : A27BD0Key
{
    float m_fValue;
    float m_fInTangent;
    float m_fOutTangent;
    A27BD0Point3 m_kTCB;
};
bool BezKeyEqual(const A27BD0BezKey& kA, const A27BD0BezKey& kB);
struct DynamicMemoryAllocator
{
    void* Allocate(unsigned int auiSize);
    void Free(void* apPtr);
};
extern "C" DynamicMemoryAllocator DAT_011f6238;
struct Elem64
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

    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Allocate(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
    ~Elem64()
    {}
};
class A27C80Point3
{
  public:
    float x, y, z;

    A27C80Point3()
    {}
    A27C80Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    A27C80Point3 operator+(const A27C80Point3& pt) const
    {
        return A27C80Point3(x + pt.x, y + pt.y, z + pt.z);
    }
    A27C80Point3 operator*(float fScalar) const
    {
        return A27C80Point3(x * fScalar, y * fScalar, z * fScalar);
    }
};
struct A27C80CubicKey
{
    float m_fTime;
    A27C80Point3 m_kValue;
    A27C80Point3 m_kTangent;
    A27C80Point3 m_kB;
    A27C80Point3 m_kC;
    A27C80Point3 m_kCubicCoefficient;
};
void EvaluateCubicKey(float fTime, const A27C80CubicKey& kKey, unsigned int uiUnused, A27C80Point3& kResult);
extern double DAT_01021928;
extern double DAT_01011590;
void __cdecl FUN_00a27d60(float t, TCBKeyS* key, unsigned int type, Vec3S* result);
class A281E0Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
class A281E0Stream;
struct A281E0Point3
{
    float x;
    float y;
    float z;

    void LoadBinary(A281E0Stream& kStream);
};
class A281E0BezPosKey
{
  public:
    ~A281E0BezPosKey();

    static void* operator new[](unsigned int uiSize)
    {
        return reinterpret_cast<A281E0Heap&>(g_memoryManager).Allocate(uiSize);
    }

    void LoadBinary(A281E0Stream& kStream);

    float m_fTime;
    A281E0Point3 m_kPos;
    A281E0Point3 m_kInTan;
    A281E0Point3 m_kOutTan;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};
class NiStream;
class NiColorSaveHelper
{
  public:
    float r;
    float g;
    float b;

    void SaveBinary(NiStream& kStream);
};
struct A28260Key
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NiColorSaveHelper m_kColor0;
    NiColorSaveHelper m_kColor1;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};
void __cdecl ApplyAnimToTarget(NiStream& kStream, A28260Key* pkKey);
void __cdecl NiAnimationKey_SaveBinary(void* a, void* b);
void __cdecl FUN_00a28720(void* a, void* b);
struct FUN_00a289b0_Vec4
{
    unsigned int a, b, c, d;
};
FUN_00a289b0_Vec4* __cdecl SampleKeyedVec4(FUN_00a289b0_Vec4* out, float t, char* keys, void* arg4, unsigned int count,
                                           unsigned char stride);
struct Sub_a28
{
    int unk00;
    bool FUN_00a92660(Sub_a28* other);
};
struct Obj_a28
{
    int unk00;
    Sub_a28 m_kSub;
};
bool __cdecl AreFloatsEqual(Obj_a28* a, Obj_a28* b);
bool __cdecl FUN_00a28a80(Obj_a28* a, Obj_a28* b);
// Reconstruction of NiBezRotKey_FillDerivedVals.
//
// The object is a fixed-size array of 36-byte key records:
//   +0x00  quaternion q0   (16 bytes)
//   +0x10  quaternion q1   (16 bytes)
//   +0x20  float           ( 4 bytes)
// The key array itself starts at obj+0x04 (obj+0x00 is a scalar header).
struct FNVQuat
{
    float x;
    float y;
    float z;
    float w;
};
struct FNVKey
{
    FNVQuat q0;
    FNVQuat q1;
    float e;
};
struct FNVAnim
{
    float f00;
    FNVKey keys[64];
};
extern void __cdecl FUN_00a28ab0(FNVAnim* obj, unsigned int count, unsigned int flag);
void __cdecl NiBezRotKey_FillDerivedVals(FNVAnim* obj, unsigned int count, unsigned int flag);
// The game class NiBound - a 16-byte bound (three position floats and a radius).
class NiBound
{
  public:
    float x, y, z, r;
    bool FUN_00a92660(const NiBound& other);
};
// UHelper layout as read off the image: a float at +0, then two 16-byte
// NiBound sub-objects at +4 and at +0x14.
struct UHelper
{
    float unk00;
    NiBound unk04;
    NiBound unk14;
};
// The primary comparison: the float at +0 and the NiBound sub-object at +4.
bool FUN_00a28a80(UHelper* a, UHelper* b);
typedef void(__cdecl* A291F0Func)();
void __cdecl FUN_00a291a0();
extern A291F0Func g_akA291F0FillDerived[6][6];
extern A291F0Func g_akA291F0CurveA[6][6];
extern A291F0Func g_akA291F0CurveB[6][6];
extern A291F0Func g_akA291F0CurveC[6][6];
extern A291F0Func g_akA291F0Insert[6][6];
extern A291F0Func g_akA291F0Interp[6][6];
extern A291F0Func g_akA291F0Cubic[6][6];
struct FUN_00a29550_stream;
typedef int(__cdecl* FUN_00a29550_fn)(FUN_00a29550_stream*, int, int, int*, int);
struct FUN_00a29550_stream
{
    unsigned int unk00;
    int m_04;
    unsigned int unk08;
    FUN_00a29550_fn m_0c;
};
struct Inner
{
    void NiColorA_SaveBinary(void* target);
};
struct Outer
{
    int unk00;
    Inner inner04;
};
void __cdecl NiAnimationKey_SaveBinary(void* target, Outer* source);
// Reconstruction of NiEulerRotKey_Insert (0x00a29e40, 189 bytes).
//
// The original does two things:
//
//  1) If the caller's "already initialised" flag is still zero it lazily
//     allocates one element of the game's FUN_00a29a70 object through the
//     global memory manager and hands the pointer back to the caller.
//     The allocation is the game's array-new support: the memory manager
//     returns 0x4c bytes (the 0x48 byte element plus a 4 byte element count
//     that is stored in front of the element) and the vector constructor
//     iterator then runs the element constructor on it.
//     The iterator is the non-EH four argument one (it pops its own
//     arguments), which is why the expansion is written out here instead of
//     using a `new[]` expression: with /EHsc the compiler would emit the
//     five argument EH flavour plus an exception handling frame.
//
//  2) It then walks the three parallel three-element groups of the object
//     (int at +0x14, int at +0x20, int at +0x30, int at +0x3c), and for every
//     group with a non-zero count it calls the handler taken from the table
//     at 0x011f3810 with (time, &value, &count), then writes the (possibly
//     modified) values back and clears the fourth group.
typedef bool(__cdecl* FNV_CbFn)(float, int*, int*);
// The game's vector constructor iterator: it calls the element constructor
// (a plain function pointer, the object pointer travels in ECX) once per
// element.  It pops its own four arguments.
// The element constructor of the allocated object.
class A29F00BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A29F00BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class A29F00Stream
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
    A29F00BinaryStream* m_pUnderlyingStream;
};
template <class T> inline void A29F00BinaryStreamLoad(A29F00BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void A29F00LoadBinary(A29F00Stream& kStream, T& value)
{
    A29F00BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
typedef void*(__cdecl* A29F00LoadFunc)(A29F00Stream& kStream, unsigned int uiNumKeys);
struct A29FE0Stream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    int unk08;
    unsigned int (*m_pfnRead)(A29FE0Stream* pkStream, void* pvBuffer, unsigned int uiSize, unsigned int* puiSizes,
                              unsigned int ItemUpdateArray);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
    unsigned int Read(void* p, unsigned int n)
    {
        unsigned int size = n;
        return BinaryRead(p, n, &size, 1);
    }
};
struct A29FE0Context
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
    A29FE0Stream* m_pDataStream;
};
struct A29FE0Block
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_auiCount[3];
    unsigned int m_auiType[3];
    int unk2C;
    void* m_apvData[3];
};
typedef void (*A29FE0LoadFunc)(A29FE0Context* pkContext, void* pvData, unsigned int ItemUpdateArray);
void ReadBlockEntries(A29FE0Context* pkContext, A29FE0Block* pkBlock);
struct Quaternion
{
    float x;
    float y;
    float z;
    float w;
    Quaternion& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }
    Quaternion operator+(const Quaternion& other) const
    {
        Quaternion result = *this;
        result.x += other.x;
        result.y += other.y;
        result.z += other.z;
        result.w += other.w;
        return result;
    }
};
class A2A890Point3
{
  public:
    float x, y, z;

    A2A890Point3()
    {}
    A2A890Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    A2A890Point3 operator-(const A2A890Point3& pt) const
    {
        return A2A890Point3(x - pt.x, y - pt.y, z - pt.z);
    }
};
struct VertexRecord
{
    int x, y, z, w;
    ~VertexRecord()
    {}
    void FUN_00a27430(int);
    static void* operator new[](unsigned int size)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(size);
    }
};
// MemoryManager, P03MM, Vec3S, Vec3R come from the pack header.
extern MemoryManager g_memoryManager;
void* _memmove(void* d, const void* s, unsigned int n);
struct TCBKeyS;
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);
Vec3R GetKeyPosAtTime(float t, TCBKeyS* keys, int type, unsigned int count, unsigned int stride);
// Linear position key: time + position (16 bytes).
struct AnimKeyBase
{
    float time;
    ~AnimKeyBase() throw()
    {}
};
struct LinPosKey : AnimKeyBase
{
    Vec3S pos;
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
// Structural equality of two light-like objects: base equality, three scalar terms, four vectors.
struct A2AE90Point3
{
    float x;
    float y;
    float z;
    bool IsEqual(const A2AE90Point3& kOther) const;
};
struct A2AE90Light
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fDimmer;
    float m_fFirstLightParameter;
    float m_fSecondLightParameter;
    A2AE90Point3 m_kAmbient;
    A2AE90Point3 m_kDiffuse;
    A2AE90Point3 m_kSpecular;
    A2AE90Point3 m_kLightVector;
};
bool __cdecl IsLightEqual(A2AE90Light* pkA, A2AE90Light* pkB);
// FNV candidate v2: AllocateBezierKeys (0x00a2af30, 61 bytes)
// return new BezierKeyS[count]; with sizeof(element)=76 (0x4c), non-trivial dtor -> 4-byte cookie,
// class-specific operator new[] inlining to ((P03MM*)&g_memoryManager)->Allocate(n).
// Packet TU already provides MemoryManager/Vec3S/P03MM/g_memoryManager/TCBKeyS(64B);
// element type must be 76 bytes, so it is a distinct type, not the packet's TCBKeyS.
struct BezierKeyS
{
    float time;
    Vec3S pos;
    Vec3S in;
    Vec3S out;
    float extra[9];
    ~BezierKeyS()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct S_00a2af70_V
{
    float x, y, z;
};
struct S_00a2af70_P
{
    int unk00;
    S_00a2af70_V c1;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    S_00a2af70_V c2;
    S_00a2af70_V c3;
    S_00a2af70_V c4;
};
static __forceinline S_00a2af70_V Scale(const S_00a2af70_V& v, float t)
{
    S_00a2af70_V r;
    r.x = v.x * t;
    r.y = v.y * t;
    r.z = v.z * t;
    return r;
}
static __forceinline S_00a2af70_V Add(const S_00a2af70_V& a, const S_00a2af70_V& b)
{
    S_00a2af70_V r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}
void __cdecl FUN_00a2af70(float t, S_00a2af70_P* p, int unused, S_00a2af70_V* out);
struct S_00a2b050_V3
{
    float x, y, z;
    S_00a2b050_V3()
    {}
    S_00a2b050_V3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    S_00a2b050_V3 operator+(const S_00a2b050_V3& o) const
    {
        return S_00a2b050_V3(x + o.x, y + o.y, z + o.z);
    }
    S_00a2b050_V3 operator*(float s) const
    {
        return S_00a2b050_V3(x * s, y * s, z * s);
    }
};
struct S_00a2b050_Obj
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
    S_00a2b050_V3 pos;
    S_00a2b050_V3 velA;
    S_00a2b050_V3 velB;
};
S_00a2b050_V3* __cdecl ComputeInterpolatedPosition(float t, S_00a2b050_Obj* o, int unused, S_00a2b050_V3* out);
extern "C" double DAT_01011590;
struct Vector3
{
    float x, y, z;
    Vector3 operator*(double multiplier) const
    {
        Vector3 scaled;
        scaled.x = float(x * multiplier);
        scaled.y = float(y * multiplier);
        scaled.z = float(z * multiplier);
        return scaled;
    }
    Vector3 operator*(float multiplier) const
    {
        Vector3 scaled;
        scaled.x = x * multiplier;
        scaled.y = y * multiplier;
        scaled.z = z * multiplier;
        return scaled;
    }
    Vector3 operator+(const Vector3& right) const
    {
        Vector3 sum;
        sum.x = x + right.x;
        sum.y = y + right.y;
        sum.z = z + right.z;
        return sum;
    }
};
void __cdecl FUN_00a2b130(float amount, const float* transform, unsigned int unused, Vector3* result);
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

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
    template <class T> unsigned int Read(T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryRead(pValue, sizeof(T), &uiSize, 1);
    }
};
struct NiStreamImpl
{
    char pad[0x24c];
    NiBinaryStreamStandIn* m_pUnderlyingStream;
};
template <class T> inline void ReadBinaryValue(NiStreamImpl& stream, T& value)
{
    stream.m_pUnderlyingStream->Read(&value);
}
class BA2BA10BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BA2BA10BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BA2BA10BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

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
class BA2BA10Stream
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
    BA2BA10BinaryStream* m_pUnderlyingStream;
    BA2BA10BinaryStream* m_pBackingStream;
};
template <class T>
inline void BA2BA10BinaryStreamSave(BA2BA10BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BA2BA10SaveBinary(BA2BA10Stream& kStream, const T& value)
{
    BA2BA10BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
struct BA2BA10Key
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};
void __cdecl ApplyAnimToTarget(BA2BA10Stream& kStream, BA2BA10Key* pkKey);
void __cdecl SaveKey(BA2BA10Stream& kStream, BA2BA10Key* pkKey);
struct TQuat
{
    float w, x, y, z;
    TQuat()
    {}
    TQuat Mul(const TQuat& q) const;
    TQuat operator+(const TQuat& q) const;
    TQuat operator-(const TQuat& q) const;
    static TQuat Log(const TQuat& q);
    static TQuat Exp(const TQuat& q);
};
TQuat operator*(float s, const TQuat& q);
struct Quad64
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
    void ComputeTangents(void* a, void* b);
};
void __cdecl FUN_00a28ab0(void* a, unsigned int count, void* c);
void __cdecl FUN_00a2c130(Quad64* base, unsigned int count, void* c);
struct S_a2c300_Istr
{
    int unk0;
    int unk4;
    unsigned(__cdecl* unk8)(S_a2c300_Istr*, void*, unsigned, unsigned*, unsigned);
};
struct S_a2c300_Stream
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_a2c300_Istr* unk24c;
};
__forceinline void S_a2c300_SaveI(S_a2c300_Istr* i, void* src, unsigned bytes)
{
    unsigned sz = bytes;
    i->unk4 += i->unk8(i, src, bytes, &sz, 1);
}
__forceinline void S_a2c300_Save(S_a2c300_Stream* s, void* src, unsigned bytes)
{
    S_a2c300_SaveI(s->unk24c, src, bytes);
}
struct S_a2c390_Istr
{
    int unk0;
    int unk4;
    int unk8;
    unsigned(__cdecl* unkc)(S_a2c390_Istr*, void*, unsigned, unsigned*, unsigned);
};
struct S_a2c390_Stream
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_a2c390_Istr* unk250;
};
void __cdecl FUN_00a28720(S_a2c390_Stream* s, void* obj);
inline void S_a2c390_BinLoad(S_a2c390_Istr* i, void* dst, unsigned bytes)
{
    unsigned comp = bytes;
    i->unk4 += i->unkc(i, dst, bytes, &comp, 1);
}
template <class T> inline void S_a2c390_Load(S_a2c390_Stream* s, T& v)
{
    S_a2c390_BinLoad(s->unk250, &v, sizeof(T));
}
struct S_a2c390_Obj
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
void __cdecl LoadObjFields(S_a2c390_Stream* s, S_a2c390_Obj* o);
extern "C" void __cdecl LoadObjFields(void* ctx, void* entry);
extern "C" float __cdecl func_0x00a42070(float input, float leftStart, float leftExtent, float rightStart,
                                         float rightEnd);
struct Key
{
    float t;
    float v;
    float a;
    float b;
    float c;
    float d;
    float e;
};
__declspec(noinline) void __cdecl FUN_00a2c6a0(Key* k, float a, float b, float c, float d)
{
    k->a = a * c;
    k->b = b * d;
}
void __cdecl FUN_00a2c7a0(Key* keys, unsigned int count);
typedef int(__cdecl* S_00a2c9d0_ReadFn)(void* stream, void* buffer, unsigned int size, unsigned int* pCount,
                                        unsigned int count);
struct S_00a2c9d0_Stream
{
    int unk00;
    int m_total;
    S_00a2c9d0_ReadFn m_pfnRead;
    void Read(void* buf, unsigned int size)
    {
        unsigned int n = size;
        m_total += m_pfnRead(this, buf, size, &n, 1);
    }
};
struct NiBinaryStreamW
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    char _08[4];
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStreamW* pkThis, const void* pvBuffer, unsigned int uiBytes,
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
};
struct NiStreamStandInW
{
    char _000[0x250];
    NiBinaryStreamW* m_pBackingStream;
};
struct FUN_00a2ca60_Obj
{
    char _00[8];
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
};
void __cdecl WriteFloatToStream(NiStreamStandInW* pkStream, FUN_00a2ca60_Obj* pkObj);
void __cdecl FUN_00a2ca60(NiStreamStandInW* pkStream, FUN_00a2ca60_Obj* pkObj);
struct KeyframeElement
{
    float time;
    float value;
    float inTangent;
    float outTangent;
    float tension;
    float continuity;
    float bias;
    ~KeyframeElement();
    void NiTCBFloatKey_LoadBinary(void* context);
    static void* operator new[](unsigned int bytes)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(bytes);
    }
};
extern "C" void __cdecl FUN_00a2ca60(void* a1, void* a2);
struct Arr8
{
    float f;
    char c;
    ~Arr8()
    {}
    __forceinline static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    __forceinline static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
struct ObjA00a2;
struct ObjA00a2
{
    long m_uiRefCount;
    virtual void v00();
    virtual void DeleteThis();
};
// Target object whose virtual slot 0xE0 (slot 56) is invoked for every entry.
static double DAT_010241b0 = -3.4028234663852886e+38;
static float DAT_01096b8c = -3.4028234663852886e+38f;
struct S_00a385d0_V3
{
    float x, y, z;
    S_00a385d0_V3 Neg() const
    {
        S_00a385d0_V3 r;
        r.x = -x;
        r.y = -y;
        r.z = -z;
        return r;
    }
};
// FUN_00a3a730 : __thiscall, 27 bytes
//   mov edx, [esp+8]
//   mov eax, [ecx]
//   mov eax, [eax+0xa0]
//   push 1
//   push edx
//   mov edx, [esp+0xc]
//   push edx
//   push 0
//   call eax
//   ret 8
// Forwards two arguments to the virtual slot 0xa0 of this object.
class NiMemObject
{
  public:
    static void* operator new(unsigned int size);
};
class NiKeyBasedInterpolator : public NiMemObject
{
  public:
    virtual ~NiKeyBasedInterpolator();
    unsigned int unk04;
    float unk08;
    NiKeyBasedInterpolator();
};
extern float DAT_0109a918;
class NiFloatInterpolator : public NiKeyBasedInterpolator
{
  public:
    float value;
    void* data;
    unsigned int lastIndex;
    NiFloatInterpolator() : NiKeyBasedInterpolator()
    {
        value = DAT_0109a918;
        data = 0;
        lastIndex = 0;
    }
};
inline void* __cdecl operator new(unsigned int, void* memory) throw()
{
    return memory;
}
int __cdecl AreFloatsEqual(const float* pfA, const float* pfB);
// AccumulateAnimSink: dispatch a request to the animation sink found at +0x24c
// of the object passed in, and accumulate the returned count.
struct FUN_00a3da50_Anim
{
    int m_unk00;
    int m_iArrayLength;
    int m_unk08;
    int(__cdecl* m_pfn)(FUN_00a3da50_Anim* pAnim, int iIndex, int iMode, int* pOut, int iFlag);
};
struct FUN_00a3da50_Owner
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5C;
    int m_unk60;
    int m_unk64;
    int m_unk68;
    int m_unk6C;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    int m_unk7C;
    int m_unk80;
    int m_unk84;
    int m_unk88;
    int m_unk8C;
    int m_unk90;
    int m_unk94;
    int m_unk98;
    int m_unk9C;
    int m_unkA0;
    int m_unkA4;
    int m_unkA8;
    int m_unkAC;
    int m_unkB0;
    int m_unkB4;
    int m_unkB8;
    int m_unkBC;
    int m_unkC0;
    int m_unkC4;
    int m_unkC8;
    int m_unkCC;
    int m_unkD0;
    int m_unkD4;
    int m_unkD8;
    int m_unkDC;
    int m_unkE0;
    int m_unkE4;
    int m_unkE8;
    int m_unkEC;
    int m_unkF0;
    int m_unkF4;
    int m_unkF8;
    int m_unkFC;
    int m_unk100;
    int m_unk104;
    int m_unk108;
    int m_unk10C;
    int m_unk110;
    int m_unk114;
    int m_unk118;
    int m_unk11C;
    int m_unk120;
    int m_unk124;
    int m_unk128;
    int m_unk12C;
    int m_unk130;
    int m_unk134;
    int m_unk138;
    int m_unk13C;
    int m_unk140;
    int m_unk144;
    int m_unk148;
    int m_unk14C;
    int m_unk150;
    int m_unk154;
    int m_unk158;
    int m_unk15C;
    int m_unk160;
    int m_unk164;
    int m_unk168;
    int m_unk16C;
    int m_unk170;
    int m_unk174;
    int m_unk178;
    int m_unk17C;
    int m_unk180;
    int m_unk184;
    int m_unk188;
    int m_unk18C;
    int m_unk190;
    int m_unk194;
    int m_unk198;
    int m_unk19C;
    int m_unk1A0;
    int m_unk1A4;
    int m_unk1A8;
    int m_unk1AC;
    int m_unk1B0;
    int m_unk1B4;
    int m_unk1B8;
    int m_unk1BC;
    int m_unk1C0;
    int m_unk1C4;
    int m_unk1C8;
    int m_unk1CC;
    int m_unk1D0;
    int m_unk1D4;
    int m_unk1D8;
    int m_unk1DC;
    int m_unk1E0;
    int m_unk1E4;
    int m_unk1E8;
    int m_unk1EC;
    int m_unk1F0;
    int m_unk1F4;
    int m_unk1F8;
    int m_unk1FC;
    int m_unk200;
    int m_unk204;
    int m_unk208;
    int m_unk20C;
    int m_unk210;
    int m_unk214;
    int m_unk218;
    int m_unk21C;
    int m_unk220;
    int m_unk224;
    int m_unk228;
    int m_unk22C;
    int m_unk230;
    int m_unk234;
    int m_unk238;
    int m_unk23C;
    int m_unk240;
    int m_unk244;
    int m_unk248;
    int m_unk24C;
    FUN_00a3da50_Anim* m_pAnim;
};
int __cdecl NiAnimationKey_SaveBinary(FUN_00a3da50_Owner* pOwner, int iIndex);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct S_a3dd40_Obj
{
    virtual ~S_a3dd40_Obj();
    virtual void DeleteThis() throw();
    volatile long m_uiRefCount;
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
struct S_a3dd40_Ptr
{
    S_a3dd40_Obj* m_p;
    S_a3dd40_Ptr& operator=(S_a3dd40_Obj* p)
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = p;
        }
        return *this;
    }
    ~S_a3dd40_Ptr() throw()
    {
        if (m_p)
            m_p->DecRefCount();
    }
};
extern "C" float __cdecl func_0x00a42070(float input, float leftStart, float leftExtent, float rightStart,
                                         float rightEnd);
struct FloatKey
{
    float time;
    float value;
    ~FloatKey() throw()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
};
float __cdecl GetValueAtTime(float t, TCBKeyS* keys, int type, unsigned int count, unsigned int stride);
struct BezPosKey
{
    float time;
    Vec3S pos;
    Vec3S in;
    Vec3S out;
    Vec3S unk28;
    Vec3S unk34;
    Vec3S unk40;
    ~BezPosKey()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
bool NiTCBPosKey_Insert(float t, BezPosKey** pKeys, unsigned int* pCount);
class NiAnimationKeyA3D
{
  public:
    float GetTime() const
    {
        return m_fTime;
    }

    NiAnimationKeyA3D* GetKeyPointerByIndex(unsigned int uiIndex, unsigned char ucKeySize)
    {
        return (NiAnimationKeyA3D*)((char*)this + uiIndex * ucKeySize);
    }

    static bool FindKeyIndex(float fTime, NiAnimationKeyA3D* pkKeys, unsigned int uiNumKeys, unsigned int& uiIndex,
                             unsigned char ucKeySize);

    float m_fTime;
};
extern "C" double DAT_01011590;
extern "C" double DAT_01021928;
void ComputeTCBKeyTangents(TCBKeyS* keys, unsigned int count, unsigned int stride);

struct Elem48
{
    int unk00;
    float m04, m08, m0C, m10;
    float m14, m18, m1C;
    float m20, m24, m28;
    unsigned char m2C, m2D, m2E, unk2F;
    float m30, m34, m38;
    float m3C, m40, m44;
    Elem48() throw();
    ~Elem48() throw();
    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Allocate(aSize);
    }
};

// @fnv 0x00a29db0
// pdb: NiEulerRotKey::FillDerivedVals | NiEulerRotKey.obj | tesv_win, objrun, medium
Elem48* __cdecl FUN_00a29db0(unsigned int count)
{
    return new Elem48[count];
}

struct Elem20
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;

    Elem20();
    ~Elem20()
    {}
    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Allocate(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
};
// @fnv 0x00a2ab40
void* FUN_00a2ab40(unsigned int count)
{
    return new Elem20[count];
}

struct A2ABC0Stream;
struct A2ABC0Key
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;

    A2ABC0Key();
    ~A2ABC0Key()
    {}
    void FUN_00a29640(A2ABC0Stream* s);
    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Allocate(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
};
// @fnv 0x00a2abc0
void* FUN_00a2abc0(A2ABC0Stream* s, unsigned int count)
{
    A2ABC0Key* p = new A2ABC0Key[count];
    for (unsigned int i = 0; i < count; i++)
        p[i].FUN_00a29640(s);
    return p;
}

struct BoolKeyS
{
    float time;
    bool value;
    ~BoolKeyS() throw()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
bool GenInterpBool(float t, BoolKeyS* keys, int type, unsigned int count, unsigned int stride);

// @fnv 0x00a2ccd0
// pdb: NiStepBoolKey::Insert | NiStepBoolKey.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: fTime, pkKeys, uiNumKeys
bool FUN_00a2ccd0(float fTime, BoolKeyS*& pkKeys, unsigned int& uiNumKeys)
{
    unsigned int uiIndex;
    BoolKeyS* pkOldKeys = pkKeys;
    if (FindKeyIndex(fTime, (TCBKeyS*)pkOldKeys, uiNumKeys, &uiIndex, sizeof(BoolKeyS)))
    {
        BoolKeyS* pkNewKeys = new BoolKeyS[uiNumKeys + 1];
        _memmove(pkNewKeys, pkOldKeys, uiIndex * sizeof(BoolKeyS));
        if (uiNumKeys > uiIndex)
            _memmove(&pkNewKeys[uiIndex + 1], &pkOldKeys[uiIndex], (uiNumKeys - uiIndex) * sizeof(BoolKeyS));
        bool bValue = GenInterpBool(fTime, pkOldKeys, 5, uiNumKeys, sizeof(BoolKeyS));
        BoolKeyS* pkKey = &pkNewKeys[uiIndex];
        pkKey->time = fTime;
        pkKey->value = bValue;
        uiNumKeys++;
        delete[] pkOldKeys;
        pkKeys = pkNewKeys;
        return true;
    }
    return false;
}

struct A28F00Elem
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

    A28F00Elem();
    ~A28F00Elem()
    {}
    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Allocate(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
};

// @fnv 0x00a28f00
// pdb: NiBezRotKey::CreateArray | NiBezRotKey.obj | tesv_win, objrun_open, low
A28F00Elem* __cdecl FUN_00a28f00(unsigned int ItemUpdateArray)
{
    return new A28F00Elem[ItemUpdateArray];
}

extern MemoryManager g_memoryManager;

void* _memmove(void* d, const void* s, unsigned int n);
struct TCBKeyS;
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);

FUN_00a289b0_Vec4* __cdecl SampleKeyedVec4(FUN_00a289b0_Vec4* out, float t, char* keys, void* arg4, unsigned int count,
                                           unsigned char stride);
struct FNVAnim;
void __cdecl NiBezRotKey_FillDerivedVals(FNVAnim* obj, unsigned int count, unsigned int flag);

struct QuatS
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    QuatS()
    {}
    QuatS(float w, float x, float y, float z) throw();
};

struct TCBRotKeyS
{
    float m_fTime;
    QuatS m_kQuat;
    float m_fValueX;
    float m_fValueY;
    float m_fValueZ;
    float unk20;
    TCBRotKeyS() : m_kQuat(0.0f, 0.0f, 0.0f, 0.0f)
    {}
    ~TCBRotKeyS()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
typedef TCBRotKeyS RotKeyS;
// @fnv 0x00a28f50
// pdb: NiBezRotKey::Insert | NiBezRotKey.obj | tesv_win, caller_sim, low
bool FUN_00a28f50(float t, RotKeyS*& pkKeys, unsigned int& uiNumKeys)
{
    TCBRotKeyS* pkOld = (TCBRotKeyS*)pkKeys;
    unsigned int uiInsertAt;
    if (FindKeyIndex(t, (TCBKeyS*)pkOld, uiNumKeys, &uiInsertAt, sizeof(TCBRotKeyS)))
    {
        TCBRotKeyS* pkNewKeys = new TCBRotKeyS[uiNumKeys + 1];
        _memmove(pkNewKeys, pkOld, uiInsertAt * sizeof(TCBRotKeyS));
        if (uiNumKeys > uiInsertAt)
            _memmove(&pkNewKeys[uiInsertAt + 1], &pkOld[uiInsertAt], (uiNumKeys - uiInsertAt) * sizeof(TCBRotKeyS));

        QuatS kQuat;
        SampleKeyedVec4((FUN_00a289b0_Vec4*)&kQuat, t, (char*)pkOld, (void*)2, uiNumKeys, sizeof(TCBRotKeyS));
        TCBRotKeyS* pkNewKey = &pkNewKeys[uiInsertAt];
        pkNewKey->m_fTime = t;
        pkNewKey->m_kQuat = kQuat;
        uiNumKeys++;
        delete[] pkOld;
        pkKeys = pkNewKeys;
        NiBezRotKey_FillDerivedVals((FNVAnim*)pkNewKeys, uiNumKeys, sizeof(TCBRotKeyS));
        return true;
    }
    return false;
}

struct A290A0Stream;
struct A290A0Key
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
    A290A0Key();
    ~A290A0Key();
    void __thiscall FUN_00a29640(A290A0Stream* pkStream);
    static void* operator new[](unsigned int uiSize)
    {
        return DAT_011f6238.Allocate(uiSize);
    }
};

// @fnv 0x00a290a0
// pdb: NiBezRotKey::CreateFromStream | NiBezRotKey.obj | tesv_win, objrun_open, low
A290A0Key* __cdecl FUN_00a290a0(A290A0Stream* pkStream, unsigned int ItemUpdateArray)
{
    A290A0Key* pkKeys = new A290A0Key[ItemUpdateArray];
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        pkKeys[i].FUN_00a29640(pkStream);
    }
    return pkKeys;
}

struct RotKeyQuat
{
    float w;
    float x;
    float y;
    float z;
};

struct TimedRotationKey : AnimKeyBase
{
    RotKeyQuat m_kRotationValue;
    TimedRotationKey();
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

void NiColorKey_GenInterpDefault(RotKeyQuat* pkResult, float fTime, TimedRotationKey* pkKeys, int eType, unsigned int uiNumKeys,
                  unsigned int uiKeySize);

// @fnv 0x00a2a390
bool FUN_00a2a390(float fTime, TimedRotationKey*& pkKeys, unsigned int& uiNumKeys)
{
    TimedRotationKey* pkOld = pkKeys;
    unsigned int uiIndex;
    if (FindKeyIndex(fTime, (TCBKeyS*)pkOld, uiNumKeys, &uiIndex, sizeof(TimedRotationKey)))
    {
        TimedRotationKey* pkNew = new TimedRotationKey[uiNumKeys + 1];
        _memmove(pkNew, pkOld, uiIndex * sizeof(TimedRotationKey));
        if (uiNumKeys > uiIndex)
            _memmove(&pkNew[uiIndex + 1], &pkOld[uiIndex], (uiNumKeys - uiIndex) * sizeof(TimedRotationKey));

        RotKeyQuat kQuat;
        NiColorKey_GenInterpDefault(&kQuat, fTime, pkOld, 1, uiNumKeys, sizeof(TimedRotationKey));
        TimedRotationKey* pkKey = &pkNew[uiIndex];
        pkKey->time = fTime;
        pkKey->m_kRotationValue = kQuat;
        uiNumKeys++;

        delete[] pkOld;
        pkKeys = pkNew;
        return true;
    }
    return false;
}

struct ColorKeyValue
{
    float r;
    float g;
    float b;
    float a;
};
struct ColorKey
{
    float m_fTime;
    ColorKeyValue m_kValue;
    ColorKey();  // FUN_00a2bdb0
    ~ColorKey()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
ColorKeyValue* __cdecl SampleKeyedVec4(ColorKeyValue* pkOut, float fTime, ColorKey* pkKeys, int iType,
                                       unsigned int ItemUpdateArray, unsigned char ucStride);
void __cdecl FUN_00a28ab0(ColorKey* pkKeys, unsigned int ItemUpdateArray, unsigned int uiStride);

// @fnv 0x00a2ac30
bool FUN_00a2ac30(float fTime, ColorKey** ppkKeys, unsigned int* puiNumKeys)
{
    ColorKey* pkKeys = *ppkKeys;
    unsigned int uiIndex;
    if (FindKeyIndex(fTime, (TCBKeyS*)pkKeys, *puiNumKeys, &uiIndex, sizeof(ColorKey)))
    {
        ColorKey* pkNew = new ColorKey[*puiNumKeys + 1];
        _memmove(pkNew, pkKeys, uiIndex * sizeof(ColorKey));
        if (*puiNumKeys > uiIndex)
            _memmove(&pkNew[uiIndex + 1], &pkKeys[uiIndex], (*puiNumKeys - uiIndex) * sizeof(ColorKey));
        ColorKeyValue kValue;
        SampleKeyedVec4(&kValue, fTime, pkKeys, 1, *puiNumKeys, sizeof(ColorKey));
        ColorKey& kKey = pkNew[uiIndex];
        kKey.m_fTime = fTime;
        kKey.m_kValue = kValue;
        ++*puiNumKeys;
        delete[] pkKeys;
        *ppkKeys = pkNew;
        FUN_00a28ab0(pkNew, *puiNumKeys, sizeof(ColorKey));
        return true;
    }
    return false;
}

struct QuatA
{
    float w, x, y, z;
    QuatA()
    {}
    void Set(float, float, float, float);
};
struct FUN_00a2bdb0
{
    float time;
    QuatA value;
    float tension, continuity, bias;
    QuatA a;
    QuatA b;
    FUN_00a2bdb0()
    {
        value.Set(0.0f, 0.0f, 0.0f, 0.0f);
    }
    ~FUN_00a2bdb0()
    {}
    static void* operator new[](unsigned n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned)
    {
        g_memoryManager.Deallocate(p);
    }
};
QuatA __cdecl SampleKeyedVec4(float, FUN_00a2bdb0*, int, unsigned, unsigned);
void __cdecl FUN_00a2c130(FUN_00a2bdb0*, unsigned, unsigned);
// @fnv 0x00a2c1b0
// pdb: NiTCBRotKey::Insert | NiTCBRotKey.obj | fnv360_0822_retail, objrun, medium
// pdb params: fTime, pkKeys, uiNumKeys
bool __cdecl FUN_00a2c1b0(float time, FUN_00a2bdb0** keys, unsigned* count)
{
    FUN_00a2bdb0* oldKeys = *keys;
    unsigned index;
    if (FindKeyIndex(time, (TCBKeyS*)oldKeys, *count, &index, 64))
    {
        FUN_00a2bdb0* newKeys = new FUN_00a2bdb0[*count + 1];
        _memmove(newKeys, oldKeys, index * sizeof(FUN_00a2bdb0));
        if (*count > index)
            _memmove(newKeys + index + 1, oldKeys + index, (*count - index) * sizeof(FUN_00a2bdb0));
        QuatA value = SampleKeyedVec4(time, oldKeys, 3, *count, 64);
        FUN_00a2bdb0& key = newKeys[index];
        key.time = time;
        key.value = value;
        key.bias = key.continuity = key.tension = 0.0f;
        ++*count;
        delete[] oldKeys;
        *keys = newKeys;
        FUN_00a2c130(newKeys, *count, 64);
        return true;
    }
    return false;
}

namespace fnv_00a2c420 {
namespace na2c {
struct Alloc
{
    void* FUN_00aa3e40(unsigned int size);
};
}
struct FUN_00a2bdb0
{
    int d[16];
    FUN_00a2bdb0() throw();
    ~FUN_00a2bdb0() throw()
    {}
    static void* operator new[](unsigned int aSize)
    {
        return ((na2c::Alloc*)&DAT_011f6238)->FUN_00aa3e40(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
    void NiTCBRotKey_LoadBinary(S_a2c300_Stream* s);
};

// @fnv 0x00a2c420
// pdb: NiTCBRotKey::CreateFromStream | NiTCBRotKey.obj | tesv_win, caller_sim, low
FUN_00a2bdb0* __cdecl FUN_00a2c420(S_a2c300_Stream* s, unsigned int count)
{
    FUN_00a2bdb0* arr = new FUN_00a2bdb0[count];
    for (unsigned int i = 0; i < count; i++)
        arr[i].NiTCBRotKey_LoadBinary(s);
    return arr;
}
}  // namespace fnv_00a2c420

struct ScalarKeyA2
{
    float time, value, tension, bias, continuity, inTangent, outTangent;
    ~ScalarKeyA2() throw()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
bool FindKeyIndex(float, ScalarKeyA2*, unsigned int, unsigned int*, unsigned int);
float GetValueAtTime(float, ScalarKeyA2*, int, unsigned int, unsigned int);
void FUN_00a2c7a0(ScalarKeyA2*, unsigned int, unsigned int);
// @fnv 0x00a2c890
// pdb: NiTCBFloatKey::Insert | NiTCBFloatKey.obj | fnv360_0721_beta, objopen_prop + bridge(caller_sim|objopen_prop) + skyrim(caller_sim), high
bool NiTCBFloatKey_Insert(float time, ScalarKeyA2** keys, unsigned int* count)
{
    ScalarKeyA2* old = *keys;
    unsigned int index;
    if (FindKeyIndex(time, old, *count, &index, 28))
    {
        ScalarKeyA2* result = new ScalarKeyA2[*count + 1];
        _memmove(result, old, index * sizeof(ScalarKeyA2));
        if (*count > index)
            _memmove(result + index + 1, old + index, (*count - index) * sizeof(ScalarKeyA2));
        float value = GetValueAtTime(time, old, 3, *count, 28);
        ScalarKeyA2& key = result[index];
        key.time = time;
        key.value = value;
        key.continuity = key.bias = key.tension = 0.0f;
        ++*count;
        delete[] old;
        *keys = result;
        FUN_00a2c7a0(result, *count, 28);
        return true;
    }
    return false;
}

struct A2CF60Elem
{
    float unk00;
    float x;
    float y;
    float z;
    float w;

    A2CF60Elem();
    ~A2CF60Elem()
    {}
    void FUN_00a29640(void* apStream);

    static void* operator new[](unsigned int auiSize)
    {
        return DAT_011f6238.Allocate(auiSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
};

namespace fnv_00a2d000 {
struct QuatS
{
    float w, x, y, z;
};
struct QuatR : QuatS
{
    QuatR()
    {}
};

struct QuatKey
{
    float time;
    QuatS q;
    QuatKey()
    {
        q.w = 0.0f;
        q.x = 0.0f;
        q.y = 0.0f;
        q.z = 0.0f;
    }
    ~QuatKey()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};

QuatR NiColorKey_GenInterpDefault(float t, QuatKey* keys, int type, unsigned int count, unsigned int stride);

// @fnv 0x00a2d000
bool FUN_00a2d000(float t, QuatKey** pKeys, unsigned int* pCount)
{
    QuatKey* keys = *pKeys;
    unsigned int idx;
    if (FindKeyIndex(t, (TCBKeyS*)keys, *pCount, &idx, sizeof(QuatKey)))
    {
        unsigned int count = *pCount + 1;
        QuatKey* newKeys = new QuatKey[count];
        _memmove(newKeys, keys, idx * sizeof(QuatKey));
        if (*pCount > idx)
            _memmove(&newKeys[idx + 1], &keys[idx], (*pCount - idx) * sizeof(QuatKey));
        QuatR q = NiColorKey_GenInterpDefault(t, keys, 5, *pCount, sizeof(QuatKey));
        QuatKey& key = newKeys[idx];
        key.time = t;
        key.q = q;
        ++*pCount;
        delete[] keys;
        *pKeys = newKeys;
        return true;
    }
    return false;
}
}  // namespace fnv_00a2d000

struct A2D6C0Quaternion
{
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;

    A2D6C0Quaternion()
    {}
};

struct A2D6C0RotKey
{
    float m_fTime;
    A2D6C0Quaternion m_kRotationValue;

    A2D6C0RotKey();
    ~A2D6C0RotKey()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};

A2D6C0Quaternion __cdecl SampleKeyedVec4(float fTime, A2D6C0RotKey* pkKeys, int eType, unsigned int uiNumKeys,
                                         unsigned int uiKeySize);
void __cdecl FUN_00a28ab0(A2D6C0RotKey* pkKeys, unsigned int uiNumKeys, unsigned int uiKeySize);

// @fnv 0x00a2d6c0
bool __cdecl FUN_00a2d6c0(float fTime, A2D6C0RotKey*& pkKeys, unsigned int& uiNumKeys)
{
    A2D6C0RotKey* pkOld = pkKeys;
    unsigned int uiInsert;
    if (FindKeyIndex(fTime, (TCBKeyS*)pkOld, uiNumKeys, &uiInsert, sizeof(A2D6C0RotKey)))
    {
        A2D6C0RotKey* pkNew;
        pkNew = new A2D6C0RotKey[uiNumKeys + 1];
        _memmove(pkNew, pkOld, uiInsert * sizeof(A2D6C0RotKey));
        if (uiNumKeys > uiInsert)
            _memmove(&pkNew[uiInsert + 1], &pkOld[uiInsert], (uiNumKeys - uiInsert) * sizeof(A2D6C0RotKey));
        A2D6C0Quaternion kQuat = SampleKeyedVec4(fTime, pkOld, 5, uiNumKeys, sizeof(A2D6C0RotKey));
        A2D6C0RotKey* pkKey = &pkNew[uiInsert];
        pkKey->m_fTime = fTime;
        pkKey->m_kRotationValue = kQuat;
        uiNumKeys++;
        delete[] pkOld;
        pkKeys = pkNew;
        FUN_00a28ab0(pkNew, uiNumKeys, sizeof(A2D6C0RotKey));
        return true;
    }
    return false;
}

class SeqE2E7
{
  public:
    virtual ~SeqE2E7();
    virtual void DeleteThis();
    long m_uiRefCount;
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
    void* m_pkOwnerManager;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    void ReleaseItems();
};

template <class T> class NiTObjectArrayE2E7
{
  public:
    virtual ~NiTObjectArrayE2E7();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    unsigned int GetSize() const
    {
        return m_usSize;
    }
    T& GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
    __declspec(noalias) T FUN_00a47540(unsigned int uiIndex);  // RemoveAtAndFill
};

template <class T> class NiTPrimitiveSetE2E7
{
  public:
    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;

    unsigned int GetSize() const
    {
        return m_uiAllocatedCapacity;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
    void RemoveAt(unsigned int uiIndex)
    {
        m_pBase[uiIndex] = m_pBase[--m_uiAllocatedCapacity];
    }
};

typedef void* NiTMapIteratorE2E7;

template <class TKEY, class TVAL> class NiTMapE2E7
{
  public:
    virtual ~NiTMapE2E7();
    virtual unsigned int KeyToHashIndex(TKEY key) const;

    unsigned int m_uiHashSize;
    NiTMapItem<TKEY, TVAL>** m_ppkHashTable;
    unsigned int m_uiCount;

    NiTMapIteratorE2E7 GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    void GetNext(NiTMapIteratorE2E7& pos, TKEY& key, TVAL& val) const
    {
        NiTMapItem<TKEY, TVAL>* pkItem = (NiTMapItem<TKEY, TVAL>*)pos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext)
        {
            pos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (++i; i < m_uiHashSize; i++)
        {
            pkItem = m_ppkHashTable[i];
            if (pkItem)
            {
                pos = pkItem;
                return;
            }
        }
        pos = 0;
    }

    bool FUN_00e91fd0(TKEY key);  // RemoveAt
};

class SeqMgrE2E7
{
  public:
    virtual ~SeqMgrE2E7();
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
    NiTObjectArrayE2E7<NiPointer<SeqE2E7> > m_kSequences;
    NiTPrimitiveSetE2E7<SeqE2E7*> m_kPlayingSequences;
    NiTMapE2E7<const char*, SeqE2E7*> m_kPointerMap;

    void FUN_00a2e7d0(SeqE2E7* pkSequence, NiPointer<SeqE2E7>& spOut);
};

// @fnv 0x00a2e7d0
// pdb: NiControllerManager::RemoveSequence | NiControllerManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pkSequence, aspControllerSequence
void SeqMgrE2E7::FUN_00a2e7d0(SeqE2E7* pkSequence, NiPointer<SeqE2E7>& spOut)
{
    for (unsigned int ui = 0; ui < m_kSequences.GetSize(); ui++)
    {
        NiPointer<SeqE2E7> pListSequence = m_kSequences.GetAt(ui);
        if (pListSequence == pkSequence)
        {
            m_kSequences.FUN_00a47540(ui);

            NiTMapIteratorE2E7 kIter = m_kPointerMap.GetFirstPos();
            while (kIter)
            {
                const char* pcName;
                SeqE2E7* pkSeq;
                m_kPointerMap.GetNext(kIter, pcName, pkSeq);
                if (pkSeq == pkSequence)
                {
                    m_kPointerMap.FUN_00e91fd0(pcName);
                    break;
                }
            }

            for (unsigned int uj = 0; uj < m_kPlayingSequences.GetSize(); uj++)
            {
                if (m_kPlayingSequences.GetAt(uj) == pkSequence)
                    m_kPlayingSequences.RemoveAt(uj);
            }

            pListSequence->ReleaseItems();
            pListSequence->m_pkOwnerManager = 0;
            spOut = pListSequence;
            return;
        }
    }
    spOut = 0;
}
