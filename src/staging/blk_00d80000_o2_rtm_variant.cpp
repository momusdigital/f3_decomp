// src/staging/blk_00d80000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d80000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include <stdlib.h>
#include "f3_common.h"
// src/staging/blk_00d80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern int DAT_010cc4f4;
extern char DAT_01267e30;
struct AllocIface {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};
AllocHolder* __cdecl FUN_00c85750() throw();
void __cdecl FUN_00cb1260(void* dst, const void* src, unsigned int size);
extern int DAT_010cc4f4;
// Havok object clone: allocate a default instance and copy the payload (everything after the header).
struct D85660Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct D85660MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D85660Allocator* m_pStreamAllocator;

    D85660Allocator& heap() { return *m_pStreamAllocator; }
};
extern "C" D85660MemoryRouter& __cdecl D85660GetMemoryRouter() throw();
class D85660Object {
public:
    D85660Object() throw();
    virtual ~D85660Object();

    static void* operator new(unsigned int nbytes) throw()
    {
        D85660Object* p = static_cast<D85660Object*>(D85660GetMemoryRouter().heap().AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int m_iData010;
    int m_iData014;
    int m_iData018;
    int m_iData01C;
    int m_iData020;
    int m_iData024;
    int m_iData028;
    int m_iData02C;
    int m_iData030;
    int m_iData034;
    int m_iData038;
    int m_iData03C;
    int m_iData040;
    int m_iData044;
    int m_iData048;
    int m_iData04C;
    int m_iData050;
    int m_iData054;
    int m_iData058;
    int m_iData05C;
    int m_iData060;
    int m_iData064;
    int m_iData068;
    int m_iData06C;
    int m_iData070;
    int m_iData074;
    int m_iData078;
    int m_iData07C;
    int m_iData080;
    int m_iData084;
    int m_iData088;
    int m_iData08C;
    int m_iData090;
    int m_iData094;
    int m_iData098;
    int m_iData09C;
};
extern int DAT_010d3838;
struct NiBinaryStream {
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    template <typename T>
    __forceinline void Read(T& val) throw() {
        unsigned int uiComponentSize = sizeof(T);
        m_uiStreamFlags += m_pfnRead(this, &val, sizeof(T), &uiComponentSize, 1);
    }
};
struct NiStream {
    int s_000, s_001, s_002, s_003, s_004, s_005, s_006, s_007, s_008, s_009, s_010, s_011, s_012, s_013, s_014, s_015, s_016, s_017, s_018, s_019, s_020, s_021, s_022, s_023, s_024, s_025, s_026, s_027, s_028, s_029, s_030, s_031, s_032, s_033, s_034, s_035, s_036, s_037, s_038, s_039, s_040, s_041, s_042, s_043, s_044, s_045, s_046, s_047, s_048, s_049, s_050, s_051, s_052, s_053, s_054, s_055, s_056, s_057, s_058, s_059, s_060, s_061, s_062, s_063, s_064, s_065, s_066, s_067, s_068, s_069, s_070, s_071, s_072, s_073, s_074, s_075, s_076, s_077, s_078, s_079, s_080, s_081, s_082, s_083, s_084, s_085, s_086, s_087, s_088, s_089, s_090, s_091, s_092, s_093, s_094, s_095, s_096, s_097, s_098, s_099, s_100, s_101, s_102, s_103, s_104, s_105, s_106, s_107, s_108, s_109, s_110, s_111, s_112, s_113, s_114, s_115, s_116, s_117, s_118, s_119, s_120, s_121, s_122, s_123, s_124, s_125, s_126, s_127, s_128, s_129, s_130, s_131, s_132, s_133, s_134, s_135, s_136, s_137, s_138, s_139, s_140, s_141, s_142, s_143, s_144, s_145, s_146;
    NiBinaryStream* m_pkIStream;

    template <typename T>
    __forceinline void BinaryRead(T& val) throw() {
        m_pkIStream->Read(val);
    }
};
struct BinaryReader {
    void* vtable;
    unsigned int currentPosition;
    unsigned int reserved08;
    unsigned int (__cdecl *Read)(BinaryReader* stream, void* dst, unsigned int bytes, unsigned int* componentBytes, unsigned int components);

    unsigned int BinaryRead(void* destination, unsigned int bytes)
    {
        unsigned int componentSize = bytes;
        unsigned int readBytes = Read(this,destination,bytes,&componentSize,1);
        currentPosition += readBytes;
        return readBytes;
    }
};
inline int countBitsSetD866(unsigned int n)
{
    n = ((n >> 1) & 0x55555555) + (n & 0x55555555);
    n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
    n = ((n >> 4) & 0x0f0f0f0f) + (n & 0x0f0f0f0f);
    n = ((n >> 8) & 0x000f000f) + (n & 0x000f000f);
    return (n & 0xff) + (n >> 16);
}
int __cdecl hkString_strNcmp(const char*, const char*, unsigned int);
const char* __cdecl BSBlendTreadTransfInterpolator_IsEqual(const char*, int);
struct TypeEntry {
    const char* name;
    int unk04;
    int unk08;
};
extern TypeEntry DAT_011b6ab4[];
struct StringBuf {
    char* m_kStringBuffer;
    int m_fRestLength;
    int m_iCapacityState;
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

    void FUN_00d61a50(const char* s);
    void FUN_00d61fc0(int from, int len);
    int FUN_00d616e0(const char* other);
    void FUN_00cbbd40();
};
int __cdecl GetTypeCode(const char* typeName);
extern "C" unsigned int (__stdcall *DAT_00fdf1d0)();
extern void* DAT_012691fc;
extern "C" {
    unsigned __int64 __rdtsc(void);
    void _ReadWriteBarrier(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);
    extern unsigned int DAT_0126835c;
}
struct StringCursor {
    int unk00;
    char* m_cur;
    int unk08;
    char* m_kRayEnd;
};
struct TargetObj {
    int dummy;
};
struct SubObj {
    int unk_000; int unk_004; int unk_008; int unk_00c; int unk_010; int unk_014; int unk_018; int unk_01c;
    int unk_020; int unk_024; int unk_028; int unk_02c; int unk_030; int unk_034; int unk_038; int unk_03c;
    int unk_040; int unk_044; int unk_048; int unk_04c; int unk_050; int unk_054; int unk_058; int unk_05c;
    int unk_060; int unk_064; int unk_068; int unk_06c; int unk_070; int unk_074; int unk_078; int unk_07c;
    int unk_080; int unk_084; int unk_088; int unk_08c; int unk_090; int unk_094; int unk_098; int unk_09c;
    int unk_0a0; int unk_0a4; int unk_0a8; int unk_0ac; int unk_0b0; int unk_0b4; int unk_0b8; int unk_0bc;
    int unk_0c0; int unk_0c4; int unk_0c8; int unk_0cc; int unk_0d0; int unk_0d4; int unk_0d8; int unk_0dc;
    int unk_0e0; int unk_0e4; int unk_0e8; int unk_0ec; int unk_0f0; int unk_0f4; int unk_0f8; int unk_0fc;
    int unk_100; int unk_104; int unk_108; int unk_10c; int unk_110; int unk_114; int unk_118; int unk_11c;
    int unk_120; int unk_124; int unk_128; int unk_12c; int unk_130; int unk_134; int unk_138; int unk_13c;
    int unk_140; int unk_144; int unk_148; int unk_14c; int unk_150; int unk_154; int unk_158; int unk_15c;
    int unk_160; int unk_164; int unk_168; int unk_16c; int unk_170; int unk_174; int unk_178; int unk_17c;
    int unk_180; int unk_184; int unk_188; int unk_18c; int unk_190; int unk_194; int unk_198; int unk_19c;
    int unk_1a0; int unk_1a4; int unk_1a8; int unk_1ac; int unk_1b0; int unk_1b4; int unk_1b8; int unk_1bc;
    int unk_1c0; int unk_1c4; int unk_1c8; int unk_1cc; int unk_1d0; int unk_1d4; int unk_1d8; int unk_1dc;
    TargetObj unk1e0;
};
struct Arg0 {
    SubObj* m_pSub;
};
struct Arg2 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20;
    int unk24;
    int unk28;
    char unk2c;
};
void __cdecl FUN_00d61d00(unsigned int* result, char* text, double d0,
                          int value0, double d1, int value1, double d2);
void __cdecl FUN_00d61d00(...);
struct hkRecordD983 {
    float m_00;
    int m_04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;

    hkRecordD983()
    {
        m_00 = 1.0f;
        m_04 = -1;
        m_30 = 0;
        m_10 = -1;
    }
};
void __cdecl FUN_00d98630(void*, void*, void*, void*);
struct FNV_00d99f50_Result {
    unsigned char flag;
    FNV_00d99f50_Result() {}
    ~FNV_00d99f50_Result() {}
};
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
extern unsigned int DAT_0126835c;
typedef void* (__stdcall* D85TlsFn)(unsigned long);
extern D85TlsFn DAT_00fdf044;
struct D85Ctn {
    void** entries;
    unsigned short count;
};
static __declspec(noinline) D85Ctn* FUN_00d85d40(D85Ctn* c) {
    for (int i = c->count - 1; i >= 0; --i) {
        if (c->entries[i] != 0) continue;
        c->count -= 1;
        unsigned int cnt = c->count;
        if (i < (int)cnt) {
            for (int j = i; j < (int)cnt; ++j)
                c->entries[j] = c->entries[j + 1];
        }
    }
    return c;
}
struct NiBinaryStreamD861 {
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStreamD861* pkStream, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
template <class T>
inline void NiStreamSaveBinaryD861(NiBinaryStreamD861& kStream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}
struct NiBinaryStreamD8616 {
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStreamD8616* pkStream, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamD8616* pkStream, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T>
inline void NiStreamLoadBinaryD8616(NiBinaryStreamD8616& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&value, sizeof(T), &uiSize, 1);
}
extern int DAT_010d3838;
extern __declspec(thread) unsigned int tlsArr[0xb0];
class AutoMemContext {
public:
    unsigned int m_saved;

    AutoMemContext()
    {
        m_saved = tlsArr[0xaf];
        tlsArr[0xaf] = 0x10;
    }
    ~AutoMemContext() { tlsArr[0xaf] = m_saved; }
};
void __cdecl FUN_00c9eae0(void* p);
struct FUN_00dee750 {
    void* m_vptr;
    unsigned short m_usMemorySizeAndFlags;
    short m_sReferenceCount;
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
    int unkac;

    static void* operator new(unsigned int sz)
    {
        AllocHolder* holder = FUN_00c85750();
        AllocIface* alloc = holder->m_pAllocator;
        void* p = alloc->Alloc(sz);
        ((FUN_00dee750*)p)->m_usMemorySizeAndFlags = (unsigned short)sz;
        return p;
    }
    static void operator delete(void* p) { FUN_00c9eae0(p); }

    FUN_00dee750();
};
extern void* DAT_012691fc;
static unsigned char* S00d96870_outp;
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
void __cdecl IntersectTree(int a1, int a2, int a3, float* a4, int* a5,
                          int a6, int a7, float a8, float a9, float a10, int a11);
typedef void (__cdecl *FUN_00d9a410_Callback)(int*, int*, void*, int, int);
struct __declspec(align(16)) FUN_00d9a4e0_Obj {
    __m128 unk00;
    __m128 unk10;
    int unk20;
    unsigned short unk24;
    unsigned short unk26;
    FUN_00d9a4e0_Obj* CopyFrom(const FUN_00d9a4e0_Obj* o);
};
namespace sd84c50 {

class Shape {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned int GetType() const;
};

struct BoolResult {
    bool m_bValue;

    BoolResult(bool bValue) : m_bValue(bValue) {}
};

}
extern char DAT_01267e30;
// pivot vector lives first in each 0x40-byte atom
// view of the derived-class atom chain at data+0x50
// hkpConstraintData stand-in (base class stays 4-aligned)
extern unsigned int DAT_0126835c;
typedef void* (__stdcall* D90TlsFn)(unsigned long);
extern D90TlsFn DAT_00fdf044;
struct D90Ctn {
    void** entries;
    unsigned short count;
};
static __declspec(noinline) D90Ctn* FUN_00d85d40(D90Ctn* c) {
    for (int i = c->count - 1; i >= 0; --i) {
        if (c->entries[i] != 0) continue;
        c->count -= 1;
        unsigned int cnt = c->count;
        if (i < (int)cnt) {
            for (int j = i; j < (int)cnt; ++j)
                c->entries[j] = c->entries[j + 1];
        }
    }
    return c;
}
struct hkTimerCommand {
    const char* m_pCommandName;
    unsigned int m_ticks;
    unsigned int m_auiShapeKeys;
};
static __forceinline void hkTimer(const char* name, volatile unsigned int& t)
{
    StringCursor* s = (StringCursor*)TlsGetValue(DAT_0126835c);
    if (s->m_cur < s->m_kRayEnd) {
        hkTimerCommand* c = (hkTimerCommand*)s->m_cur;
        c->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        c->m_ticks = t;
        s->m_cur = (char*)(c + 1);
    }
}
template <class T>
struct ResizableArray {
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        for (int i = index; i < m_iElementCount; i++) {
            m_data[i] = m_data[i + 1];
        }
    }
};
struct hkpConstraintInstance;
struct hkpConstraintListener {
    virtual ~hkpConstraintListener();
    virtual void ConstraintAddedCallback(hkpConstraintInstance* constraint);
    virtual void ConstraintRemovedCallback(hkpConstraintInstance* constraint);
};
struct hkpConstraintInstance {
    char pad[0x20];
    ResizableArray<hkpConstraintListener*> m_kListeners;
};
static void FUN_00d85d40(ResizableArray<hkpConstraintListener*>& cleanupArray)
{
    for (int i = cleanupArray.GetLogicalSize() - 1; i >= 0; i--) {
        if (cleanupArray[i] == 0) {
            cleanupArray.removeAtAndCopy(i);
        }
    }
}
void __cdecl FUN_00c908c0(AllocIface& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
template <class T>
class hkArrayD868 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void reserve(AllocIface& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n) {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n, const T& fill)
    {
        AllocIface* a; AllocHolder* h; h = FUN_00c85750(); a=h->m_pAllocator; reserve(*a,n);
        int i = n - m_iElementCount;
        T* p = m_data + m_iElementCount;
        while (i-- > 0)
            *p++ = fill;
        m_iElementCount = n;
    }
};
int __cdecl hkString_strNcmp(const char*, const char*, int) throw();
const char* __cdecl BSBlendTreadTransfInterpolator_IsEqual(const char*, int) throw();
int __cdecl GetTypeCode(const char*) throw();
struct HkTempAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void ReturnMemory(void*, int) throw();
};
struct HkBytes16 {
    int a;
    int b;
    int c;
    int d;
};
struct HkBytes64 {
    HkBytes16 a;
    HkBytes16 b;
    HkBytes16 c;
    HkBytes16 d;
};
struct HkBytes128 {
    HkBytes64 a;
    HkBytes64 b;
};
struct HkInplaceChars {
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    HkBytes128 m_kStorage;
};
struct FUN_00d61b10 {
    HkInplaceChars m_kStringBuffer;

    FUN_00d61b10(const char*, int) throw();
    ~FUN_00d61b10() throw() {
        AllocHolder* router = FUN_00c85750();
        int cap = m_kStringBuffer.m_iCapacityState;
        HkTempAllocator* allocator = reinterpret_cast<HkTempAllocator*>(router->unk0c);
        m_kStringBuffer.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            allocator->ReturnMemory(m_kStringBuffer.m_data, cap & 0x3fffffff);
        m_kStringBuffer.m_iCapacityState = int(0x80000000u);
        m_kStringBuffer.m_data = 0;
    }
};
static inline char* alignDownD881(char* p) { return (char*)((unsigned int)p & ~15); }
class hkpShapeD923 {
public:
    virtual ~hkpShapeD923();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
};
struct hkpCdBodyD923 {
    const hkpShapeD923* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyD923* m_parent;
};
class hkpContactMgrD923;
class hkpCollisionAgentD923;
struct hkpCollisionInputD923;
typedef hkpCollisionAgentD923* (__cdecl *CreateFuncD923)(
    const hkpCdBodyD923&, const hkpCdBodyD923&,
    const hkpCollisionInputD923&, hkpContactMgrD923*);
struct AgentFuncsD923 {
    CreateFuncD923 m_pCreateFunc;
    void* m_pQueryPenetrationsFunc;
    void* m_pGetPenetrationsFunc;
    void* m_pLinearCastFunc;
    void* m_bIsFlipped;
};
struct hkpCollisionDispatcherD923 {
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
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    AgentFuncsD923 m_agent2Funcs[1];
    CreateFuncD923 findCreateFunc(const hkpCdBodyD923& bodyA, const hkpCdBodyD923& bodyB, const hkpCollisionInputD923& input) const;
};
struct hkpCollisionInputD923 {
    hkpCollisionDispatcherD923* m_pCollisionDispatcher;
    int unk04, unk08, unk0C, unk10;
    int m_bCreatePredictiveAgents;
};
inline CreateFuncD923 hkpCollisionDispatcherD923::findCreateFunc(const hkpCdBodyD923& bodyA, const hkpCdBodyD923& bodyB, const hkpCollisionInputD923& input) const
{
    int typeA = bodyA.m_pCollisionShape->m_type;
    int typeB = bodyB.m_pCollisionShape->m_type;
    const unsigned char* table = input.m_bCreatePredictiveAgents ? &m_agent3TypeMap[0][0] : &m_agent2TypeMap[0][0];
    unsigned char agentType = table[typeA * 32 + typeB];
    return m_agent2Funcs[agentType].m_pCreateFunc;
}
struct CleanupObject {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;
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
    void* unk50;
    unsigned short unk54;
    unsigned short unk56;
    unsigned short unk58;
    unsigned short unk5A;
    void* unk5C;
    int unk60;
    int unk64;
    void* unk68;
    int unk6C;
    int unk70;
    int unk74;
    void* unk78;

};
CleanupObject* volatile cleanupInput;
extern "C" void _ReadWriteBarrier(void);
extern "C" {
    unsigned __int64 __rdtsc(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);
}
extern unsigned int DAT_0126835c;
extern "C" char str_010cc5c4[];
extern char DAT_01076f38[];
struct StructB {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
};
struct LocalFlag { unsigned char value; };
void __cdecl FUN_00d72190(short* a1, StructB* a2, LocalFlag a3, int** a4);
void __cdecl FUN_00d6f460(short* a1, unsigned short a2, StructB* a3, int** a4);
template <typename ENUM, typename STORAGE> struct hkEnum {
    STORAGE m_kStorage;
    __forceinline hkEnum(ENUM e) { m_kStorage = static_cast<STORAGE>(e); }
};
enum JobCategory { HK_JOB_TYPE_DYNAMICS = 0 };
enum JobSpuType { HK_JOB_SPU_TYPE_INVALID, HK_JOB_SPU_TYPE_ENABLED, HK_JOB_SPU_TYPE_DISABLED };
struct JobDescriptor {
    unsigned char m_ucSubType;
    hkEnum<JobCategory, unsigned char> m_eJobType;
    hkEnum<JobSpuType, unsigned char> m_eSpuType;
    unsigned char unk03;
    unsigned short m_iElementCount;
    short m_iAffinity;
    __forceinline JobDescriptor(JobCategory jobType, unsigned int subType, unsigned short size, JobSpuType spuType)
        : m_ucSubType((unsigned char)subType), m_eJobType(jobType), m_eSpuType(spuType), m_iElementCount(size), m_iAffinity(-1) {}
};
struct hkpTaskHeader {
    int unk00;
    int m_iJobId;
};
struct DynamicsJob : public JobDescriptor {
    int unk08;
    int unk0c;
    unsigned short m_usValueAtOffset10;
    int m_taskHeader14;
    int m_mtThreadStructure18;
    int m_unk1c;
    hkpTaskHeader* m_kHeader;
    __forceinline DynamicsJob(unsigned int subType, unsigned short size, const DynamicsJob& src)
        : JobDescriptor(HK_JOB_TYPE_DYNAMICS, subType, size, HK_JOB_SPU_TYPE_DISABLED)
    {
        m_usValueAtOffset10 = src.m_usValueAtOffset10;
        m_taskHeader14 = src.m_taskHeader14;
        m_mtThreadStructure18 = src.m_mtThreadStructure18;
        m_unk1c = src.m_unk1c;
    }
};
struct DynamicsJobSubtype14 : public DynamicsJob {
    __forceinline DynamicsJobSubtype14(const DynamicsJob& job)
        : DynamicsJob(14, 0x30, job)
    {
        m_usValueAtOffset10 = job.m_usValueAtOffset10;
        m_kHeader = job.m_kHeader;
    }
};
inline void* operator new(unsigned int, void* where) throw() { return where; }
struct __declspec(align(16)) S00d96970_Local {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned short unk04;
    short unk06;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};
extern double DAT_01035718;
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
__forceinline unsigned int roundLane(const float& value)
{
    float copy = value;
    return fnv_FloatToInt(copy);
}
extern const __m128 DAT_011b6de0;
struct ListenerArray {
    void** m_ppItems;
    unsigned short m_wCount;
};
static void FUN_00d85d40(ListenerArray* pArr);
#include <stdarg.h>
namespace sd85040 {

struct __declspec(align(16)) FourFloatVector {
    __m128 m_vComponents;
};

struct __declspec(align(16)) Transform {
    FourFloatVector m_aRotation[3];
    FourFloatVector m_kTranslation;

    void FUN_00c6cd60(const Transform& kOther);
};

class Shape {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType() const;
};

}
struct hkBool_d86 {
    char m_cBooleanValue;
    hkBool_d86(bool b) { m_cBooleanValue = (char)b; }
};
extern unsigned int DAT_0126835c;
typedef void* (__stdcall *D94TlsGetFn)(unsigned long);
extern D94TlsGetFn DAT_00fdf044;
#include <string.h>
struct S00d967a0_Obj {
    void** vptr;
};
struct S00d967a0_Rec {
    unsigned char m00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned short m10;
    unsigned short unk12;
    int m14;
    unsigned int unk18;
    S00d967a0_Obj* m1C;
    unsigned int unk20;
    unsigned short m24;
    unsigned short unk26;
    unsigned short m28;
    unsigned short m2A;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    int m40;
    unsigned short m44;
};
static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do {
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        s += 4; d += 4;
    } while (--numQuads > 0);
}
static __forceinline int split13(S00d967a0_Rec* src, S00d967a0_Rec* dst)
{
    unsigned short a = src->m28;
    unsigned short c = src->m2A;
    if (a <= c) return 0;
    src->m24++;
    src->m28 = (unsigned short)(a - c);
    src->m40 += c;
    dst->m44 = 0x200;
    dst->m28 = c;
    return 1;
}
static __forceinline int split15(S00d967a0_Rec* src, S00d967a0_Rec* dst)
{
    unsigned short a = src->m28;
    unsigned short c = src->m2A;
    if (a <= c) return 0;
    src->m28 = (unsigned short)(a - c);
    src->m24++;
    dst->m28 = c;
    return 1;
}
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_cmplt_ps(__m128, __m128);
extern "C" __m128 _mm_cmpeq_ps(__m128, __m128);
extern "C" int _mm_movemask_ps(__m128);
struct D986Result {
    char value;
    D986Result(bool b) : value(b) {}
    operator bool() const { return value != 0; }
};
D986Result __cdecl FUN_00d98630(const __m128* src, const __m128* dst, int mask);
// Real body is 0xd96600..0xd9679f (0x1A0). 0xd967a0 is a second function the claim swallowed.
struct D96600Link {
    D96600Link* next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char flag1c;
};
struct D96600Table {
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
    int* table;
};
struct D96600Blob {
    unsigned char type;
    unsigned char unk01;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short word10;
    unsigned short unk12;
    int field14;
    D96600Link* unk18;
    D96600Table** ppHolder;
    union {
        int count20;
        unsigned int offset20;
        D96600Link* node20;
    };
    union {
        unsigned int limit24;
        struct {
            unsigned short word24;
            unsigned short word26;
        };
    };
    int unk28;
    D96600Link* node2c;
    int unk30;
    unsigned short word34;
    unsigned short word36;
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

    int FUN_00df2640(int** slot, D96600Blob* dst);
};
static __forceinline int popPart(D96600Blob* src, D96600Blob* dst)
{
    D96600Table* holder = *src->ppHolder;
    int** slot = &holder->table;
    dst->field14 = holder->table[dst->word10];

    switch (src->type) {
    case 0: {
        int n = src->count20;
        if (n <= 1)
            return 0;
        src->word10++;
        src->count20 = n - 1;
        dst->count20 = 1;
        return 1;
    }
    case 1: {
        unsigned short step = 0x80;
        if (src->word26 <= step)
            return 0;
        src->word26 = (unsigned short)(src->word26 - step);
        src->word24 = (unsigned short)(src->word24 + step);
        dst->word26 = step;
        return step - 0x7f;
    }
    case 4:
    case 10:
        if (src->node20->next == 0)
            return 0;
        src->node20 = src->node20->next;
        return 1;
    case 12:
        return src->FUN_00df2640(slot, dst);
    case 11: {
        unsigned short step = 0x80;
        if (src->word34 > step) {
            src->word34 = (unsigned short)(src->word34 - step);
            src->word36 = (unsigned short)(src->word36 + step);
            dst->word34 = step;
            return step - 0x7f;
        }
        if (src->count20 == 0)
            return 0;
        src->type = 0x0a;
        return 1;
    }
    case 7:
    case 9: {
        unsigned int next = src->offset20 + 0x4000;
        if (next >= src->limit24)
            return 0;
        src->offset20 = next;
        dst->limit24 = next;
        return 1;
    }
    case 8:
        if (src->node2c->flag1c != 0)
            return 0;
        src->node2c = src->node2c->next;
        return 1;
    case 3:
    case 6:
    case 14:
        *dst = *src;
        return 0;
    case 2:
    case 5:
    case 13:
        return 0;
    default:
        return 0;
    }

}
union __declspec(intrin_type) __declspec(align(16)) __m128i { unsigned __int64 q[2]; };
extern "C" {
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_and_ps(__m128, __m128);
__m128 _mm_andnot_ps(__m128, __m128);
__m128 _mm_or_ps(__m128, __m128);
__m128 _mm_cmpeq_ps(__m128, __m128);
__m128 _mm_cmplt_ps(__m128, __m128);
__m128 _mm_cmple_ps(__m128, __m128);
__m128 _mm_min_ps(__m128, __m128);
__m128 _mm_max_ps(__m128, __m128);
__m128 _mm_shuffle_ps(__m128, __m128, int);
__m128 _mm_unpackhi_ps(__m128, __m128);
__m128 _mm_rcp_ps(__m128);
__m128 _mm_setzero_ps();

__m128 _mm_load_ss(const float*);
__m128 _mm_set_ps1(float);
int _mm_movemask_ps(__m128);
__m128i _mm_unpacklo_epi16(__m128i, __m128i);
__m128i _mm_unpackhi_epi16(__m128i, __m128i);
__m128 _mm_cvtepi32_ps(__m128i);
}
__forceinline __m128 TreeSplat(float value) {
    __m128 scalar = _mm_load_ss(&value);
    return _mm_shuffle_ps(scalar, scalar, 0);
}
struct __declspec(align(16)) TreeVector {
    float x, y, z, w;
    __m128 simdValue() const { return *reinterpret_cast<const __m128*>(this); }
    float operator[](unsigned int axis) const { return (&x)[axis]; }
};
struct TreeNode {
    int flags;
    unsigned int bounds;
};
struct __declspec(align(16)) QuantizedBounds {
    unsigned short minX, minY, minZ, idLow;
    unsigned short maxX, maxY, maxZ, idHigh;
};
struct TreeCollector {
    virtual void unused();
    virtual void AddHit(unsigned char* state, unsigned int id);
    virtual void begin(unsigned char* state);
    virtual float earlyOut();
};
extern const __m128 DAT_011b6de0;
extern const float DAT_010cd644 = 1.0000000272564224e16f;
extern const float DAT_0104e148 = -3.402820018375656e38f;
extern const float DAT_0104da48 = 3.402820018375656e38f;
template<class T> struct TreeRef { T* p; TreeRef(T* q):p(q){} operator T*()const{return p;} T* operator->()const{return p;} };
__forceinline const QuantizedBounds* projectAt(const TreeNode& node, const QuantizedBounds* leaves, unsigned int index) { return leaves + (node.flags & 0x7fffffff) + index; }
struct BoundPair { __m128 minimum, maximum; void set(float a, float b) { minimum = _mm_set_ps1(a); maximum = _mm_set_ps1(b); } };
void __cdecl IntersectTree(void* tree, const TreeNode* node, const QuantizedBounds* leaves, const TreeVector* scale, const TreeVector* offset, const TreeVector* origin, const TreeVector* direction, float intervalMin, float intervalMax, float fractionScale, TreeCollector* collector);
extern char str_010cc5c4[];
extern char DAT_01076f38[];
struct S00d94a80_Ctx {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};
struct __declspec(align(16)) S00d94a80_Local {
    S00d94a80_Ctx head;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    char* unk94;
};
void __cdecl FUN_00d6f460(char* atom, int count, S00d94a80_Local* ctx, int** cursor);
struct S00d94a80_Bool {
    bool m_cBooleanValue;
    S00d94a80_Bool(bool v) { m_cBooleanValue = v; }
};
void __cdecl FUN_00d72190(char* atom, S00d94a80_Local* ctx, S00d94a80_Bool bCopy, int** cursor);
inline S00d94a80_Bool S00d94a80_True() { S00d94a80_Bool r(true); return r; }
struct S00d94a80_A0 {
    SubObj* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    S00d94a80_Ctx m_ctx;
};
struct S00d94a80_Rec {
    char* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned short unk14;
    unsigned short unk16;
    unsigned short unk18;
    unsigned short unk1a;
};
struct S00d94a80_Desc {
    int unk00;
    int unk04;
    char* end;
    int* c0;
    char* mon;
    int count;
    S00d94a80_Rec records[1];
};
struct S00d94a80_A2 {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    S00d94a80_Desc* unk20;
    int unk24;
    unsigned char unk28;
};
struct ArgHandle {
    Arg2* p;
    ArgHandle(Arg2* q):p(q) {}
};
struct S00d94a80_TimerCmd {
    const char* m_name;
    unsigned int m_uiStartTicks;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_uiStartTicks = ticks;
    }
};
static __forceinline void S00d94a80_Process(Arg0* a1, Arg2* p)
{
    S00d94a80_Desc* desc = ((S00d94a80_A2*)p)->unk20;
    S00d94a80_Local base;
    base.head = ((S00d94a80_A0*)a1)->m_ctx;
    S00d94a80_Rec* rec = desc->records;
    char* mon = desc->mon;
    int count = desc->count;
    char* end = desc->end;
    int* c0 = desc->c0;
    base.unk94 = mon;
    bool flag = ((S00d94a80_A2*)p)->unk28 != 0 && desc->unk00 != 0;
    _ReadWriteBarrier();

    
    int* cursor = c0;
    if (count > 0) {
    int remaining = count;
    do {
        S00d94a80_Rec* r = rec++;
        base.head.unk38 = r->unk0c;
        base.head.unk3c = r->unk10;
        base.head.unk30 = (unsigned int)(end + r->unk18 * 128);
        base.head.unk34 = (unsigned int)(end + r->unk1a * 128);
        base.head.unk6c = r->unk18;
        base.head.unk70 = r->unk1a;
        base.head.unk60 = r->unk04;
        base.head.unk64 = r->unk08;
        base.head.unk74 = r->unk08;
        unsigned int w14 = r->unk14;
        char* atom = r->unk00;
        if (*(unsigned short*)atom == 0x16) {
            S00d94a80_Bool b(true);
            FUN_00d72190(atom, &base, b, &cursor);
        } else {
            FUN_00d6f460(atom, w14, &base, &cursor);
        }
    } while (--remaining);
    }

    int* c = cursor;
    if (!flag) {
        *c = 0;
    } else {
        int remain = (int)(base.unk94 - (char*)c);
        if (remain > 0) {
            *(float*)c += 1.1920928955078125e-07;
            c[1] = remain;
            *(unsigned char*)c = 2;
        }
    }

}
extern double DAT_01035718;
union F128U
{
    __m128 v;
    unsigned u[4];
};
static const F128U V4C = { { 196608.0f, 196608.0f, 196608.0f, 196608.0f } };

struct TypeNameD86 {
    const char* FUN_00d46d40();
};
extern "C" char str_010d3b50[], str_010d3a88[], str_010d3b48[], str_010d3b40[], str_010d3b34[], str_010d3b28[], str_010d3b18[], str_010d3b10[], str_010d3b00[], str_010d3af0[], str_010d3ae0[], str_010d3ad0[], str_010d3abc[], str_010d3a74[];
struct TextD86 : StringBuf {
    void InitBuffer() throw();
    void FUN_00d61c10(const char*) throw();
};
extern "C" void __cdecl FUN_00d61d00(TextD86*, const char*, ...);
static __declspec(noinline) unsigned char FUN_00d868b0(int t) {
    return (t >= 0 && (t < 20 || t == 28 || t == 30 || t == 29 || t == 32 || t == 33)) ? 1 : 0;
}
struct MemberD86 {
    int unk00;
    TypeNameD86* classType;
    const char** enumType;
    unsigned char type;
    unsigned char subType;
    short extent;
    __declspec(noinline) int FUN_00d86b30() { return subType; }
};
// @f3 0x0093dc30 (community match, verified in this file)
extern "C" unsigned int __cdecl FUN_009233f0(const char*);
extern "C" char str_00e797fc[],str_00e797f4[],str_00e797ec[],str_00e797e4[],str_00e797d8[],str_00e797cc[],str_00e797bc[],str_00e797b4[],str_00e797a4[],str_00e79744[],str_00e79794[],str_00e79784[],str_00e79770[];
extern unsigned int DAT_010f3170;
extern "C" char str_00e79808[],str_00e79754[];
struct Alloc93 {
 char* FUN_008f6d30(int,int);
 void FUN_008f6d90(void*,int,int);
};
struct Text93 {
 char* m_kStringBuffer;
 int m_fRestLength;
 int m_iCapacityState;
 void InitBuffer() throw() {
  Alloc93* alloc=(Alloc93*)TlsGetValue(DAT_010f3170);
  m_kStringBuffer=alloc->FUN_008f6d30(1,23);
  m_fRestLength=1; m_iCapacityState=1; *m_kStringBuffer=0;
 }
 __forceinline void SetLength(int n);
 __forceinline void FUN_00d61c10(const char* s) throw();
};
extern "C" void __cdecl FUN_00901e90(Text93*,int,int);
__forceinline void Text93::SetLength(int n) {
 int cap=m_iCapacityState & 0x3fffffff;
 if(cap<n) FUN_00901e90(this,n<2*cap?2*cap:n,1);
 m_fRestLength=n;
}
__forceinline void Text93::FUN_00d61c10(const char* s) throw() {
 if (s && *s) {
  const int n=FUN_009233f0(s);
  SetLength(n+1);
  FUN_00cb1260(m_kStringBuffer,s,n+1);
 } else {
  int cap=m_iCapacityState & 0x3fffffff;
  if(cap<1) FUN_00901e90(this,2*cap>1?2*cap:1,1);
  m_fRestLength=1; *m_kStringBuffer=0;
 }
}


extern "C" void __cdecl FUN_009236d0(Text93*,const char*,...);
extern "C" void __cdecl FUN_009233d0(char*,const char*,int);
static __declspec(noinline) void FormatPrimitive93(int t, Text93* text, int extent) {
 if (!extent) text->FUN_00d61c10(DAT_011b6ab4[t].name);
 else FUN_009236d0(text,str_010d3a74,DAT_011b6ab4[t].name,extent);
}
// pdb: hkClassMember::getTypeName | hkClassMember.obj | fnv360_0822_retail, ustr, high
// pdb params: buf, bufLen
extern "C" int __fastcall FUN_00d86ec0(MemberD86* self, void*, char* output, int capacity) {
    TypeNameD86* cls = self->classType;
    int t = self->type;
    const char* className = cls ? cls->FUN_00d46d40() : str_00e79808;
    const char* enumName = self->enumType ? *self->enumType : str_00e79808;
    Text93 text;
    text.InitBuffer();
    if (!(t < 20 || t == 27 || t == 29)) {
    if (t == 20) {
        if (self->classType) FUN_009236d0(&text, str_00e797fc, self->classType->FUN_00d46d40());
        else if (self->subType == 2) text.FUN_00d61c10(str_00e797f4);
        else text.FUN_00d61c10("void*");
    } else if (t == 22 || t == 26) {
        int st = self->FUN_00d86b30();
        const char* container = t == 22 ? str_00e797b4 : str_00e797a4;
        if (st < 20 || st == 29) FUN_009236d0(&text, str_00e79744, container, DAT_011b6ab4[st].name);
        else if (st == 20) {
            if (self->classType) FUN_009236d0(&text, str_00e79794, container, className);
            else FUN_009236d0(&text, str_00e79784, container);
        } else if (st == 25) FUN_009236d0(&text, str_00e79770, container, className);
        else if (st == 28) FUN_009236d0(&text, str_00e79754, container);
    } else if (t == 24) FUN_009236d0(&text, str_00e797e4, enumName);
    else if (t == 31) FUN_009236d0(&text, str_00e797d8, enumName);
    else if (t == 25) {
        if (!self->extent) FUN_009236d0(&text, str_00e797cc, className);
        else FUN_009236d0(&text, str_00e797bc, className, self->extent);
    }
    } else {
    FormatPrimitive93(t, &text, self->extent);
    }
    FUN_009233d0(output, text.m_kStringBuffer, capacity);
    int result = text.m_fRestLength - 1;
    if ((text.m_iCapacityState & 0x80000000) == 0) {
        int bytes=text.m_iCapacityState & 0x3fffffff;
        Alloc93* alloc=(Alloc93*)TlsGetValue(DAT_010f3170);
        alloc->FUN_008f6d90(text.m_kStringBuffer,bytes,23);
    }
    return result;
}volatile int type93,extent93;
Text93* volatile text93;

volatile int d86_type;
TextD86* volatile d86_text;
volatile int d86_extent;
