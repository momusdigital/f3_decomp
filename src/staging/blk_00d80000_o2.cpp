// staging/blk_00d80000_o2.cpp: IdxStand_, ObjD9A4, MonitorBuffer (57 functions)
#include <stdlib.h>
#include "f3_common.h"
// src/staging/blk_00d80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern int DAT_010cc4f4;

struct FUN_00d85300_Stub {
    void FUN_00d85300(int*);
};
struct FUN_00d85a20_Stub : FUN_00d85300_Stub {
    int* CopyStateFrom(int* p);
};
// @f3 0x006d3080 (community match, verified in this file)
struct FUN_006d6cd0_src
{
    void* FUN_006d6cd0();
};

struct FUN_006d3080_Tri
{
    int a;
    int b;
    int c;
};

// pdb: ReferenceInitialData::Initialize | BGSSaveLoadInitialData.obj | fnv360_0822_retail, objrun_open, low
// pdb params: apReferenceLocationInitialData
int* FUN_00d85a20_Stub::CopyStateFrom(int* p)
{
    char* s = (char*)p;
    *(void**)((char*)this + 0x00) = ((FUN_006d6cd0_src*)p)->FUN_006d6cd0();
    *(int*)((char*)this + 0x04) = 0;
    *(int*)((char*)this + 0x08) = 0;
    *(int*)((char*)this + 0x0c) = 0;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x14) = *(int*)(s + 0x03);
    *(int*)((char*)this + 0x18) = *(int*)(s + 0x07);
    *(int*)((char*)this + 0x1c) = *(int*)(s + 0x0b);
    FUN_006d3080_Tri* t = (FUN_006d3080_Tri*)(s + 0x0f);
    *reinterpret_cast<FUN_006d3080_Tri*>((char*)this+0x20)=*t;
    int last=reinterpret_cast<FUN_006d3080_Tri*>((char*)this+0x20)->c;
    *((char*)this + 0x2c) = 0;
    return (int*)last;
}


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

namespace fnv_00d853a0 {
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

}  // namespace fnv_00d853a0

namespace fnv_00d853f0 {
struct MemAllocD853 {
    virtual void v0();
    virtual void* Alloc(unsigned int uiSize);
};
struct SingD853 {
    char pad000[0x10];
    MemAllocD853* m_pAllocationContext;
};
extern "C" SingD853* __cdecl FUN_00c85750();
extern "C" void* __cdecl FUN_00cb1260(void* pDst, const void* pSrc, unsigned int ItemUpdateArray);

}  // namespace fnv_00d853f0

namespace fnv_00d85440 {
struct D85440Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct D85440MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D85440Allocator* m_pStreamAllocator;

    D85440Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D85440MemoryRouter& __cdecl FUN_00c85750();

class D85440ReferencedObject {
public:
    static void* operator new(unsigned int nbytes)
    {
        D85440ReferencedObject* b = static_cast<D85440ReferencedObject*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);

    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

}  // namespace fnv_00d85440

namespace fnv_00d85490 {
extern int DAT_010cc4f4;

extern void* __cdecl FUN_00c85750();
extern void __cdecl FUN_00cb1260(void* destination, const void* source, unsigned int size);

}  // namespace fnv_00d85490

namespace fnv_00d854e0 {
// CloneStub @ 0x00d854e0, size 68, __cdecl (caller pops), /MT /O2 /GS /EHsc /Gy
//
// Reconstructed behavior:
//   A* a          = FUN_00c85750();              // cdecl, no args
//   C* obj        = a->unk10->Create(0x140);     // virtual slot +4, __thiscall
//   obj->unk04    = 0x140;                       // u16 field at +4
//   D* result     = obj->FUN_00cdf2f0();         // __thiscall, no stack args
//   FUN_00cb1260(&result->unk10, &src->unk10, 0x130);  // cdecl, 3 args
//   return result;

struct C_Stub;
struct D_Stub;

// polymorphic stand-in reached through A_Stub::unk10; Create sits in vtable slot +4
struct B_Stub {
    virtual void* virt0();
    virtual C_Stub* Create(int size);
};

struct A_Stub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    B_Stub* unk10;
};

struct C_Stub {
    int unk00;
    unsigned short unk04;
    D_Stub* FUN_00cdf2f0();   // game function at 0x00cdf2f0 (__thiscall member)
};

struct D_Stub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

A_Stub* __cdecl FUN_00c85750();
void __cdecl FUN_00cb1260(void* dst, const void* src, unsigned int size);

}  // namespace fnv_00d854e0

namespace fnv_00d85530 {
struct SpawnedAllocator {
    virtual void v00();
    virtual void* Alloc(unsigned int size);
};

struct SpawnedHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnedAllocator* m_pAllocator;
};

struct SpawnedObject {
    int unk00;
    unsigned short m_usSize;
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

    SpawnedObject* Ctor();
};

struct SpawnedSource {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

SpawnedHolder* __cdecl FUN_00c85750();
void* __cdecl FUN_00cb1260(void* dst, const void* src, unsigned int size);

// Allocates a 0x50-byte SpawnedObject from the holder's allocator, sets its size, constructs it, and copies 0x38 bytes from pSrc+0x10 into unk10.
// @fnv 0x00d85530
SpawnedObject* __cdecl FUN_00d85530(SpawnedSource* pSrc)
{
    SpawnedHolder* pHolder = FUN_00c85750();
    SpawnedAllocator* pAllocator = pHolder->m_pAllocator;
    SpawnedObject* pObj = (SpawnedObject*)pAllocator->Alloc(0x50);
    pObj->m_usSize = 0x50;
    pObj = pObj->Ctor();
    FUN_00cb1260(&pObj->unk10, (char*)pSrc + 0x10, 0x38);
    return pObj;
}
}  // namespace fnv_00d85530

namespace fnv_00d85570 {
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

}  // namespace fnv_00d85570

namespace fnv_00d855c0 {
struct FUN_00d855c0_Factory {
    virtual void FUN_00d85300_Unused() = 0;
    virtual void* FUN_00d85300(int size);
};

struct FUN_00d855c0_Manager {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d855c0_Factory* unk10;
};

extern "C" FUN_00d855c0_Manager* FUN_00c85750();
extern "C" void* __fastcall FUN_00d84bd0(void* object);
extern "C" void* FUN_00cb1260(void* destination, const void* source, unsigned int size);

}  // namespace fnv_00d855c0

namespace fnv_00d85610 {
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

}  // namespace fnv_00d85610

namespace fnv_00d856b0 {
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

}  // namespace fnv_00d856b0

struct S_00d85af0_Base {
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
    void FUN_00d85300(const S_00d85af0_Base* o);
};
struct S_00d85af0_V3 { float x, y, z; };
struct S_00d85af0_Cls : S_00d85af0_Base {
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    S_00d85af0_V3 unkb4;
    S_00d85af0_Cls* AssignFrom(const S_00d85af0_Cls* o);
};
// @f3 0x00601ed0 (community match, verified in this file)
struct S_00d85af0_T3 { int a, b, c; };

struct S_00d85af0_Real : S_00d85af0_Base {
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
    float unkbc;
    float unkc0;
    float unkc4;
    int unkc8;
    unsigned char unkcc;
    unsigned char unkcd;
    unsigned char unkce;
    unsigned char unkcf;
    unsigned char unkd0;
    unsigned char unkd1;
    unsigned char unkd2;
    unsigned char unkd3;
    S_00d85af0_T3 unkd4;
    void FUN_00601080(const S_00d85af0_Real* o) const;
    S_00d85af0_T3& D4() { return unkd4; }
    const S_00d85af0_T3& D4c() const { return unkd4; }
};

// pdb: PathingRequestCover::CopyTo | PathingRequestCover.obj | fnv360_0822_retail, vtable, medium
// pdb params: apDest
S_00d85af0_Cls* S_00d85af0_Cls::AssignFrom(const S_00d85af0_Cls* o)
{
    S_00d85af0_Real* src = (S_00d85af0_Real*)this;
    S_00d85af0_Real* dst = (S_00d85af0_Real*)o;
    src->FUN_00601080(dst);
    dst->unkb0 = src->unkb0;
    dst->unkb4 = src->unkb4;
    dst->unkb8 = src->unkb8;
    dst->unkc0 = src->unkc0;
    dst->unkbc = src->unkbc;
    dst->unkc4 = src->unkc4;
    dst->unkc8 = src->unkc8;
    dst->unkcd = src->unkcd;
    dst->unkce = src->unkce;
    dst->unkcf = src->unkcf;
    dst->unkd0 = src->unkd0;
    dst->unkd1 = src->unkd1;
    dst->D4() = src->D4c();
    if (false) return 0;
}


struct CpuOpaque;
extern CpuOpaque DAT_01269514;
// @fnv 0x00d9f6c0
CpuOpaque* __cdecl FUN_00d9f6c0()
{
    return &DAT_01269514;
}

extern int DAT_010cc4f4;

// @fnv 0x00d9f6e0
// pdb: getVtablehkpSerializedDisplayMarkerList | hkpSerializedDisplayMarkerListClass.obj | fnv360_0822_retail, objrun_open, low
unsigned int __cdecl FUN_00d9f6e0() {
    return reinterpret_cast<unsigned int>(&DAT_010cc4f4);
}

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

int __cdecl hkString_strNcmp(const char*, const char*, unsigned int);
const char* __cdecl BSTreadTransfInterpolator_IsEqual(const char*, int);
const char* __cdecl BSBlendTreadTransfInterpolator_IsEqual(const char*, int);

struct TypeEntry {
    const char* name;
    int unk04;
    int unk08;
};
extern TypeEntry DAT_011b6ab4[];
extern TypeEntry DAT_011b6c4c[];

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

// Matches typeName against known type prefixes and a type table, returning the corresponding type code or 0.
// @fnv 0x00d86c00
int __cdecl GetTypeCode(const char* typeName) {
    if (hkString_strNcmp(typeName, "enum ", 5) == 0)
        return 0x18;
    if (hkString_strNcmp(typeName, "flags ", 6) == 0)
        return 0x1f;
    if (hkString_strNcmp(typeName, "hkArray<", 8) == 0)
        return 0x16;
    if (hkString_strNcmp(typeName, "hkSimpleArray<", 14) == 0)
        return 0x1a;
    if (hkString_strNcmp(typeName, "char*", 5) == 0)
        return 0x1d;
    if (hkString_strNcmp(typeName, "hkStringPtr", 11) == 0)
        return 0x21;

    const char* star = BSTreadTransfInterpolator_IsEqual(typeName, '*');
    if (star != 0 && star[1] == '\0')
        return 0x14;

    StringBuf buf;
    buf.FUN_00d61a50(typeName);

    const char* bracket = BSBlendTreadTransfInterpolator_IsEqual(typeName, '[');
    if (bracket != 0) {
        buf.FUN_00d61fc0(0, bracket - typeName);
    }

    int i = 0;
    TypeEntry* pEntry = DAT_011b6ab4;
    do {
        if (buf.FUN_00d616e0(pEntry->name)) {
            buf.FUN_00cbbd40();
            return i;
        }
        ++pEntry;
        ++i;
    } while ((int)pEntry < (int)DAT_011b6c4c);

    buf.FUN_00cbbd40();
    return 0;
}

struct B { char pad[0x12]; unsigned short w12; };
struct S {
    unsigned int m0;
    B* m4;
    void SetValueAndPtr(unsigned int a, B* b);
};
// @fnv 0x00d87130
// pdb: hkClassMemberAccessor::connect | hkClassMemberAccessor.obj | tesv_win, objrun_prop, low
void S::SetValueAndPtr(unsigned int uiValue, B* b) {
m0 = uiValue + b->w12; m4 = b;
}

struct D871A0Buffer {
    void append(const void* p, int a, int b);
};
struct FUN_00d871c0_class {
    FUN_00d871c0_class* Append(FUN_00d871c0_class* a, int b, const void* p);
};
// @fnv 0x00d871c0
// pdb: hkClassMemberAccessor::hkClassMemberAccessor | hkClassMemberAccessor.obj | tesv_win, hash, low
FUN_00d871c0_class* FUN_00d871c0_class::Append(FUN_00d871c0_class* apData, int b, const void* p)
{
    ((D871A0Buffer*)this)->append(apData, b, (int)p);
    return this;
}

struct TargetClass {
    void* Append(int a, int b, int c);
};

struct MemberClass {
    int FUN_00d86910();
};

struct FUN_00d87380_Class {
    int unk00;
    MemberClass* unk04;

    TargetClass* CallTargetMethod(TargetClass* target, int arg2);
};

// Calls Append on target with this->unk00, the result of this->unk04->FUN_00d86910(), and arg2, then returns target.
// @fnv 0x00d87380
// pdb: hkClassMemberAccessor::member | hkClassMemberAccessor.obj | tesv_win, hash, low
TargetClass* FUN_00d87380_Class::CallTargetMethod(TargetClass* target, int aiArg) {
    target->Append(this->unk00, this->unk04->FUN_00d86910(), aiArg);
    return target;
}

class hkSetD874 {
public:
    int* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FUN_00d87410() const;
};

// @fnv 0x00d87410
// pdb: hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getIterator | hkStringMap.obj | fnv360_0822_retail, call_seq, high
int hkSetD874::FUN_00d87410() const
{
    int i;
    for (i = 0; i <= m_iPairCount; i++)
    {
        if (m_kPrimitiveElement[i] != -1)
            break;
    }
    return i;
}

struct FUN_00d87910_cls {
    int m_00;

    FUN_00d87910_cls* FUN_00d87910();
};

// @fnv 0x00d87910
// pdb: hkThread::hkThread | hkWin32Thread.obj | tesv_win, call_seq, medium
FUN_00d87910_cls* FUN_00d87910_cls::FUN_00d87910()
{
    m_00 = 0;
    return this;
}

extern "C" unsigned int (__stdcall *DAT_00fdf1d0)();

// @fnv 0x00d87a40
// pdb: hkThread::getMyThreadId | hkWin32Thread.obj | tesv_win, objrun, medium
unsigned __int64 __cdecl FUN_00d87a40()
{
    return DAT_00fdf1d0();
}

void __cdecl FUN_00d87920();

// @fnv 0x00d87a70
void __cdecl FUN_00d87a70()
{
    FUN_00d87920();
}

class FUN_00d88050 {
public:
    FUN_00d88050();

    bool m_bModifierActive;
    int m_iValue;
    bool m_bValueAt0C;
};

// @fnv 0x00d88050
FUN_00d88050::FUN_00d88050()
{
    m_iValue = 0;
    m_bModifierActive = false;
    m_bValueAt0C = false;
}

extern void* DAT_012691fc;

struct FUN_00d880f0_Class {
    int unk00;
    int unk04;
    unsigned char unk08;

    void FUN_00d880f0(unsigned char val);
};

// @fnv 0x00d880f0
// pdb: ModifierList::SetZeroValuesAllowed | ModifierList.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: NiRenderTargetGroup::SetResolveDepthBufferMode)
// pdb params: abZeroValuesAllowed
void FUN_00d880f0_Class::FUN_00d880f0(unsigned char val) {
    unk08 = val;
}

struct DispatchTarget {
    virtual void Event0();
    virtual void Event1();
    virtual void Event2();
    virtual void Event3();
    virtual void Event4();
    virtual void Event5();
    virtual void Event6();
    virtual void Dispatch(int argument);
};
// @fnv 0x00d921e0
// pdb: hkAgent3Bridge::updateFilter | hkpAgent3Bridge.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: hkAgent3Bridge::destroy)
// pdb params: entry, agentData, bodyA, bodyB, input, mgr, constraintOwner
void __cdecl InvokeDispatch(void* context, DispatchTarget** target, void* reserved, int argument) {
    (*target)->Dispatch(argument);
}

class hkTargetD922B {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void process(void* a, void* b, void* c, void* d);
};

// Calls process on the target object pointed to by ppkTarget, forwarding a, b, c and d.
// @fnv 0x00d92200
// pdb: hkAgent3Bridge::updateFilter | hkpAgent3Bridge.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: entry, agentData, bodyA, bodyB, input, mgr, constraintOwner
void __cdecl FUN_00d92200(void* pvContext, hkTargetD922B** ppkTarget, void* a, void* b, void* c, void* pvUnused, void* d)
{
    (*ppkTarget)->process(a, b, c, d);
}

class FUN_00d92250_obj {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9(int iValue);
};

struct FUN_00d92250_holder {
    FUN_00d92250_obj* m_object;
};

// @fnv 0x00d92250
// pdb: hkAgent3Bridge::invalidateTim | hkpAgent3Bridge.obj | fnv360_0822_retail, objrun, high
// pdb params: entry, agentData, input
// pdb: hkAgent3Bridge::invalidateTim | hkpAgent3Bridge.obj | fnv360_0822_retail, objrun, high (was: CallObjectVirtual)
void __cdecl hkAgent3Bridge_invalidateTim(void* pvUnused, FUN_00d92250_holder* pkHolder, int iValue)
{
    pkHolder->m_object->V9(iValue);
}

struct FUN_00d92270_Dispatch
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual int v10(float a, float b, int c) = 0;
};

// Calls virtual method v10 on the object pointed to by a2 with a3, a4 and a5, returning its result.
// @fnv 0x00d92270
// pdb: hkAgent3Bridge::warpTime | hkpAgent3Bridge.obj | fnv360_0822_retail, objrun, high
// pdb params: entry, agentData, oldTime, newTime, input
// pdb: hkAgent3Bridge::warpTime | hkpAgent3Bridge.obj | fnv360_0822_retail, objrun, high (was: DispatchVirtualCall)
int hkAgent3Bridge_warpTime(int aiUnused, FUN_00d92270_Dispatch** a2, float afArg1, float afArg2, int aiArg3)
{
    return (*a2)->v10(afArg1, afArg2, aiArg3);
}

class hkTargetD92A {
public:
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
    virtual void process(void* pvData);
};

// @fnv 0x00d922a0
void __cdecl FUN_00d922a0(void* pvContext, hkTargetD92A** ppkTarget, void* pvData)
{
    (*ppkTarget)->process(pvData);
}

class hkTargetD922 {
public:
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
    virtual void process(void* pvData);
};

// @fnv 0x00d922c0
void __cdecl FUN_00d922c0(void* pvContext, hkTargetD922** ppkTarget, void* pvData)
{
    (*ppkTarget)->process(pvData);
}

struct FUN_00d922e0_Iface {
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
    virtual void* unk34(int arg);
};

// @fnv 0x00d922e0
// pdb: hkAgent3Bridge::createZombie | hkpAgent3Bridge.obj | fnv360_0822_retail, objrun, high
// pdb params: entry, agentData, idTobecomeZombie
// pdb: hkAgent3Bridge::createZombie | hkpAgent3Bridge.obj | fnv360_0822_retail, objrun, high (was: CallIfaceMethod)
void* __cdecl hkAgent3Bridge_createZombie(int unused, FUN_00d922e0_Iface** p, int arg) {
    return (*p)->unk34(arg);
}

struct FUN_00d92380_obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b, int c, int d);
};
struct FUN_00d92380_vec {
    int a0;
    int a4;
    int a8;
    int ac;
};
struct FUN_00d92380_holder {
    FUN_00d92380_obj* m0;
    int m4;
    int m8;
    int mc;
    int m10;
};
// Calls the virtual method v6 on h->m0 with v->a0, v->a4, v->ac and arg, then returns the address of h->m10.
// @f3 0x00a260a0 (community match, verified in this file)
// pdb: hkAgent3Bridge::process | hkpAgent3Bridge.obj | fnv360_0822_retail, objrun, high
// pdb params: input, entry, agentData, separatingNormalOut, result
// pdb: hkAgent3Bridge::process | hkpAgent3Bridge.obj | fnv360_0822_retail, objrun, high (was: CallVirtualWithVectorArgs)
int* __cdecl hkAgent3Bridge_process(FUN_00d92380_vec* pVec, int u1, FUN_00d92380_holder* pHolder, int u2, int arg)
{
    pHolder->m0->v6(pVec->a0, pVec->a4, pVec->a8, arg);
    return &pHolder->m10;
}


struct FUN_00d93310_cls {
    int m_00;
    int m_04;
    int m_08;

    FUN_00d93310_cls* FUN_00d93310();
};

// @fnv 0x00d93310
// pdb: hkpFixedSizePhysicsCommandQueue<512>::hkpFixedSizePhysicsCommandQueue<512> | hkpCpuAgentSectorJob.obj | tesv_win, call_gap_sim, low
FUN_00d93310_cls* FUN_00d93310_cls::FUN_00d93310()
{
    m_00 = 0x10;
    m_04 = 0;
    m_08 = 0x100;
    return this;
}

extern "C" {
    unsigned __int64 __rdtsc(void);
    void _ReadWriteBarrier(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);
    extern unsigned int DAT_0126835c;
}

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

struct Arg1 {
    void ProcessCallback(Arg2* a1, Arg2* a2, int a3);
};

// Writes profiling markers to the TLS stream, calls FUN_00d89f80 on the sub-object, stores the result flag in a3->unk2c, then calls a2->ProcessCallback(a3, a3, 0).
// @f3 0x00a236b0 (community match, verified in this file)
namespace f3m_00a236b0 {
struct QSub {
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
    int unk1a0;
};
struct QArg0 {
    QSub* m_pSub;
    int unk04;
    int unk08;
};
struct QArg2 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18;
    char unk1c;
};
struct QArg1 {
    void FUN_00a21830(int a0, QArg2* a1, QArg2* a2, int a3, int a4);
};
struct QCursor {
    int unk00;
    char* m_cur;
    int unk08;
    char* m_kRayEnd;
};
extern "C" void __cdecl FUN_00a0d700(void* p, int a2, int a3, int a4, bool* pb);
}

// pdb: hkCpuSolveIntegrateVelocitiesJob | hkpCpuSolveConstraintsJobs.obj | fnv360_0822_retail, ustr, high
// pdb params: tl, jobQueue, jobInOut
// pdb: hkCpuSolveIntegrateVelocitiesJob | hkpCpuSolveConstraintsJobs.obj | fnv360_0822_retail, ustr, high (was: LogIntegrateVelocity)
void hkCpuSolveIntegrateVelocitiesJob(Arg0* arg0, Arg1* arg1, Arg2* arg2)
{
    using namespace f3m_00a236b0;
    QArg0* a1 = reinterpret_cast<QArg0*>(arg0);
    QArg1* a2 = reinterpret_cast<QArg1*>(arg1);
    QArg2* a3 = reinterpret_cast<QArg2*>(arg2);
    QCursor* stream = (QCursor*)TlsGetValue(DAT_0126835c);
    char* cur = stream->m_cur;
    if (cur < stream->m_kRayEnd) {
        *(const char* volatile*)cur = "LtIntegrate";
        *(const char* volatile*)(cur + 0xc) = "StIntVel";
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = t;
        cur += 0x10;
        stream->m_cur = cur;
    }

    bool b = false;
    FUN_00a0d700(&a1->m_pSub->unk1a0, a3->unk18, a3->unk10, a3->unk14, &b);
    a3->unk1c = b;

    QCursor* stream2 = (QCursor*)TlsGetValue(DAT_0126835c);
    char* cur2 = stream2->m_cur;
    if (cur2 < stream2->m_kRayEnd) {
        *(const char* volatile*)cur2 = "lt";
        _ReadWriteBarrier();
        volatile unsigned int t2 = (unsigned int)__rdtsc();
        *(unsigned int*)(cur2 + 4) = t2;
        cur2 += 0xc;
        stream2->m_cur = cur2;
    }

    a2->FUN_00a21830(a1->unk08, a3, a3, 0, 0);
}


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

struct FUN_00d98390 {
    unsigned int unk00;
    float unk04;
    float unk08;
    float unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20;
    unsigned short unk24;
    unsigned char unk26;

    FUN_00d98390();
};

// Default-constructs the four hkRecordD983 entries, each initialising m_00 to 1.0f and m_04, m_10 to -1 and m_30 to 0.
// @f3 0x005fc3f0 (community match, verified in this file)
// Constructor of the pack's own record FUN_00d98390. The pack declares the class and this constructor,
// so nothing is declared or redefined at file level here. unk00 holds the address of the class's
// function table (DAT_00dc4dc0).
// pdb: BSSimpleArray<PathingLocation,1024>::_FillMemory | NavMeshSearchMultipleGoals.obj | fnv360_0822_debug, call_seq, low
// pdb params: apAddress, aiCount
FUN_00d98390::FUN_00d98390()
{
    extern char DAT_00dc4dc0;

    unk04 = 3.402823466e38f;
    unk08 = 3.402823466e38f;
    unk00 = reinterpret_cast<unsigned int>(&DAT_00dc4dc0);
    unk0C = 3.402823466e38f;
    unk18 = 0;
    unk1C = 0;
    unk24 = 0xffff;
    unk20 = 0xdeaddead;
    unk10 = 0;
    unk14 = 0;
    unk26 = 0;
}


void __cdecl FUN_00d98630(void*, void*, void*, void*);

// Calls FUN_00d98630 with the four arguments and returns a1.
// @fnv 0x00d99540
// pdb: std::char_traits<char>::_Move_s | BipedAnim.obj | tesv_win, caller_sim, low
void* __cdecl FUN_00d99540(void* a1, void* a2, void* a3, void* a4)
{
    FUN_00d98630(a1, a2, a3, a4);
    return a1;
}

struct FNV_00d99f50_Result {
    unsigned char flag;
    FNV_00d99f50_Result() {}
    ~FNV_00d99f50_Result() {}
};

struct FnvCpu_FUN_00d9f6b0_CpuInterface {
    virtual void Invoke(int value);
};
// @fnv 0x00d9f6b0
// pdb: cleanupLoadedObjecthkpSerializedDisplayRbTransforms | hkpSerializedDisplayRbTransformsClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00d9f6b0(FnvCpu_FUN_00d9f6b0_CpuInterface* object)
{
    object->Invoke(0);
}

extern char DAT_0102e388;
struct FUN_00d9fb30_Stub {
    void FUN_00d9fb30();
};
// @fnv 0x00d9fb30
// pdb: BGSRepairItemList::~BGSRepairItemList | BGSRepairItemList.obj | fnv360_0822_retail, call_gap, low
void FUN_00d9fb30_Stub::FUN_00d9fb30()
{
    *(int*)this = (int)&DAT_0102e388;
}

// @fnv 0x00d9fb40
// pdb: hkaPose::checkInternalFlagIsClear | hkaPose.obj | fnv360_0822_retail, objrun_open, low
// pdb params: flag
void __stdcall FUN_00d9fb40(unsigned char* output, int unused1)
{
    *output = 1;
}

// @fnv 0x00d9fca0
// pdb: hkpCollisionAgent::createZombie | hkpCollisionAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpCollisionAgent_createZombie(int) {
}

// @fnv 0x00d9fcb0
// pdb: hkpContinuousSimulation::assertThereIsNoCollisionInformationForEntities | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable_prefix + bridge(vtable_prefix|vtable), high
void __stdcall hkpContinuousSimulation_assertThereIsNoCollisionInformationForEntities(int, int, int) {
}

// @fnv 0x00d9fcc0
// pdb: hkpMeshShape::assertSubpartValidity | hkpMeshShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: part
void __stdcall FUN_00d9fcc0(int) {
}

// @fnv 0x00d9fcd0
void __stdcall FUN_00d9fcd0(int) {
}

// @fnv 0x00d9fce0
// pdb: hkpDisableEntityCollisionFilter::entityDeletedCallback | hkpDisableEntityCollisionFilter.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void __stdcall hkpDisableEntityCollisionFilter_entityDeletedCallback(int) {
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

extern unsigned int DAT_0126835c;
typedef void* (__stdcall* D85TlsFn)(unsigned long);
extern D85TlsFn DAT_00fdf044;

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

struct NiStreamD861 {
    char unk000[0x24c];
    NiBinaryStreamD861* m_pBackingStream;
};

template <class T>
inline void NiStreamSaveBinaryD861(NiBinaryStreamD861& kStream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}

struct DataD861 {
    int unk00[3];
    unsigned int m_0c;
    unsigned int m_10;
};

// Writes the m_0c and m_10 fields of pkData to the stream's backing binary stream via NiStreamSaveBinaryD861.
// @fnv 0x00d86100
// pdb: bhkLimitedForceConstraintMotor::LoadBinary | bhkLimitedForceConstraintMotor.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: arStream, arMotor
void __cdecl FUN_00d86100(NiStreamD861& kStream, DataD861* pkData)
{
    NiStreamSaveBinaryD861(*kStream.m_pBackingStream, pkData->m_0c);
    NiStreamSaveBinaryD861(*kStream.m_pBackingStream, pkData->m_10);
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

struct NiStreamD8616 {
    char unk000[0x24c];
    NiBinaryStreamD8616* m_pBackingStream;
    NiBinaryStreamD8616* m_pUnderlyingStream;
};

template <class T>
inline void NiStreamLoadBinaryD8616(NiBinaryStreamD8616& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&value, sizeof(T), &uiSize, 1);
}

struct DataD8616 {
    int unk00[3];
    unsigned int m_0c;
    unsigned int m_10;
};

// Reads two unsigned int fields from the stream into pkData->m_0c and pkData->m_10.
// @fnv 0x00d86160
// pdb: bhkLimitedForceConstraintMotor::SaveBinary | bhkLimitedForceConstraintMotor.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: arStream, arMotor
void __cdecl FUN_00d86160(NiStreamD8616& kStream, DataD8616* pkData)
{
    NiStreamLoadBinaryD8616(*kStream.m_pUnderlyingStream, pkData->m_0c);
    NiStreamLoadBinaryD8616(*kStream.m_pUnderlyingStream, pkData->m_10);
}

extern int DAT_010d3838;
struct FUN_00d86220_Class {
    unsigned int m_vptr;
    unsigned short m_word04;
    unsigned short m_word06;
    volatile unsigned char m_byte08;
    volatile float m_float0C;
    float m_float10;
    float m_float14;
    float m_float18;
    FUN_00d86220_Class();
};
// Initializes the object's vtable pointer, sets m_word06 to 1, m_byte08 to 3, m_float0C to -1000000.0f, m_float10 to 1000000.0f, and m_float14/m_float18 to 0.0f.
// @fnv 0x00d86220
// pdb: hkpSpringDamperConstraintMotor::hkpSpringDamperConstraintMotor | hkpSpringDamperConstraintMotor.obj | tesv_win, objrun_open, low
FUN_00d86220_Class::FUN_00d86220_Class()
{
    m_word06 = 1;
    m_byte08 = 0;
    m_float0C = -1000000.0f;
    m_float10 = 1000000.0f;
    m_vptr = (unsigned int)&DAT_010d3838;
    m_byte08 = 3;
    m_float14 = 0.0f;
    m_float18 = 0.0f;
}

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

class hkBitFieldD867 {
public:
    unsigned int* m_auiBitFieldWords;
    int m_numWords;
    int m_iCapacityState;
    int m_iNumBits;

    void FUN_00d867e0(int value);
};

// Sets or clears the bits in the last word of the bit field that extend beyond m_iNumBits based on value.
// @f3 0x009b20f0 (community match, verified in this file)
void hkBitFieldD867::FUN_00d867e0(int value)
{
    int lastWordIndex = ((m_iCapacityState & 0x7fffffff) - 1) >> 5;
    unsigned int* lastWord = &m_auiBitFieldWords[lastWordIndex];
    int numBitsInLastWord = (m_iCapacityState & 0x7fffffff) - (lastWordIndex << 5);
    if (numBitsInLastWord < 32) {
        unsigned int mask = 0xffffffff << numBitsInLastWord;
        if (!value) {
            *lastWord &= ~mask;
        } else {
            *lastWord |= mask;
        }
    }
}


struct S_00d87a60 {
    int m_uiFilterValue;
    int GetValue();
};

// @fnv 0x00d87a60
// pdb: hkClass::getName | hkClass.obj | fnv360_0822_retail, call_seq, high
int S_00d87a60::GetValue() {
    return m_uiFilterValue;
}

extern void* DAT_012691fc;
// @fnv 0x00d880a0
// pdb: hkpSweptTransformDisplayViewer::getProcessTag | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, vtable, medium
void* __cdecl FUN_00d880a0()
{
    return DAT_012691fc;
}

namespace fnv_00d88150 {
class hkMemoryAllocatorD881 {
public:
    virtual ~hkMemoryAllocatorD881() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD881 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD881* m_pStreamAllocator;

    hkMemoryAllocatorD881& heap() { return *m_pStreamAllocator; }
};

namespace hkRouterD881 {
    extern "C" hkMemoryRouterD881& __cdecl FUN_00c85750() throw();
}

class FUN_00d88050 {
public:
    char unk00[0x3c];

    FUN_00d88050() throw();
    ~FUN_00d88050() throw() {}

    static void* operator new(unsigned int nbytes) { return hkRouterD881::FUN_00c85750().heap().AllocateMemoryBlock(0x3c); }
    static void operator delete(void* p) { hkRouterD881::FUN_00c85750().heap().ReleaseBlock(p, 0x3c); }
};

namespace hkGlobalsD881 {
    extern FUN_00d88050* DAT_012691fc;
}
using hkGlobalsD881::DAT_012691fc;

}  // namespace fnv_00d88150

static unsigned char* S00d96870_outp;

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_sub_ps(__m128, __m128);

typedef void (__cdecl *FUN_00d9a410_Callback)(int*, int*, void*, int, int);

struct ArgD9A4 {
    int unk00, unk04, unk08, unk0C;
};

struct InnerD9A4 {
    int unk00;
    float m_fValue;
};

class PrimaryD9A4 {
public:
    virtual ~PrimaryD9A4();
};

class SecondaryD9A4 {
public:
    virtual float FUN_00d9a480(ArgD9A4* pkArg) = 0;
};

class ObjD9A4 : public PrimaryD9A4, public SecondaryD9A4 {
public:
    int unk08;
    int unk0C;
    InnerD9A4* m_pkInner;

    void InvokeCallback(int iValue);
    virtual float FUN_00d9a480(ArgD9A4* pkArg);
};

// @f3 0x007273e0 (community match, verified in this file)
struct StubD9A4Obj08 {
    void FUN_007ee180(ArgD9A4* pkArg);
};

struct StubD9A4Vt {
    virtual void v0();
    virtual float v1(ArgD9A4* pkArg);
};

// pdb: BaseProcess::HandleDeletedReference | BaseProcess.obj | fnv360_0822_retail, objrun, medium
// pdb params: apRef
float ObjD9A4::FUN_00d9a480(ArgD9A4* pkArg)
{
    reinterpret_cast<StubD9A4Obj08*>(&unk08)->FUN_007ee180(pkArg);
    StubD9A4Vt* pkVt = reinterpret_cast<StubD9A4Vt*>(unk0C);
    if (pkVt)
        return pkVt->v1(pkArg);
}


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

// Returns true if the shape's GetType() is one of 0, 1, 2, 6, 7, 8, 9, 12, 13, 14 or 15, otherwise false.
// @f3 0x007bb030 (community match, verified in this file)
extern const char* DAT_00f70708[];
extern const char* DAT_00f4ebd4[];
extern const char* DAT_00f70770[];
namespace f3m_007bb030 {
// Returns the display name of a setting value: three kinds of setting take the name from a name table
// by index, every other kind is shown as "True" or "False".

const char* FUN_007bb030(int kind, int value)
{
    switch (kind)
    {
    case 1:
    case 2:
    case 13:
        return DAT_00f70708[value];
    case 10:
    case 11:
    case 12:
        return DAT_00f4ebd4[value];
    case 18:
        return DAT_00f70770[value];
    default:
        return value ? "True" : "False";
    }
}
}   // namespace f3m_007bb030


}

extern char DAT_01267e30;

extern unsigned int DAT_0126835c;
typedef void* (__stdcall* D90TlsFn)(unsigned long);
extern D90TlsFn DAT_00fdf044;

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
int __cdecl hkString_strLen(const char*) throw();
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

// Parses a type-code string by matching known prefixes or extracting a bracketed substring, then returns its type code.
// @f3 0x0093e240 (community match, verified in this file)
extern unsigned long DAT_010f3170;

namespace anon_0093e240 {} using namespace anon_0093e240; namespace anon_0093e240 {
struct HkMemRouter93e240 {
    void FUN_008f6d90(void* memory, int bytes, int category) throw();
};
}

extern HkMemRouter93e240* (__stdcall* const DAT_00d9b080)(unsigned long);
void __cdecl FUN_00901e90(void* array, int capacity, int elementSize) throw();
int __cdecl FUN_009232f0(const char* a, const char* b, int n) throw();
int __cdecl FUN_009233f0(const char* s) throw();
int __cdecl hkString_atoi(const char* s) throw();
const char* __cdecl FUN_00923460(const char* s, int c) throw();
void __cdecl FUN_009234e0(void* dst, const void* src, int n) throw();

namespace anon_0093e240 {} using namespace anon_0093e240; namespace anon_0093e240 {
struct HkCharArray93e240 {
    char* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline HkCharArray93e240() throw() : m_data(0), m_size(0), m_capacityAndFlags(int(0x80000000u)) {}

    __forceinline int getCapacity() const throw() { return m_capacityAndFlags & 0x3fffffff; }

    __forceinline ~HkCharArray93e240() throw() {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int cap = getCapacity();
            HkMemRouter93e240* router = DAT_00d9b080(DAT_010f3170);
            router->FUN_008f6d90(m_data, cap, 0x17);
        }
    }

    __forceinline void setSizeUnchecked(int n) throw() {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, 1);
        }
        m_size = n;
    }
};

struct HkString93e240 {
    HkCharArray93e240 m_string;

    __forceinline HkString93e240(const char* s, int len) throw() {
        m_string.setSizeUnchecked(len + 1);
        FUN_009234e0(m_string.m_data, s, len);
        m_string.m_data[len] = 0;
    }

    __forceinline ~HkString93e240() throw() {}

    __forceinline const char* cString() const throw() { return m_string.m_data; }
};
}

// pdb: hkClassMember::getSubtypeOf | hkClassMember.obj | fnv360_0822_retail, ustr_rel, high
// pdb params: name
// pdb: hkClassMember::getSubtypeOf | hkClassMember.obj | fnv360_0822_retail, ustr_rel, high (was: GetTypeCodeFromString)
int __cdecl hkClassMember_getSubtypeOf(const char* name) throw()
{
    if (FUN_009232f0(name, "hkArray<", 8) == 0) {
        HkString93e240 inner(name + 8, FUN_009233f0(name + 8) - 1);
        return GetTypeCode(inner.cString());
    }
    if (FUN_009232f0(name, "hkSimpleArray<", 14) == 0) {
        HkString93e240 inner(name + 14, FUN_009233f0(name + 14) - 1);
        return GetTypeCode(inner.cString());
    }
    const char* openBracket = FUN_00923460(name, '[');
    if (openBracket) {
        int length = int(FUN_00923460(name, ']') - openBracket) - 1;
        HkString93e240 inner(openBracket + 1, length);
        return hkString_atoi(inner.cString());
    }
    return 0;
}


struct FUN_00d87180_cls : S {
    FUN_00d87180_cls* FUN_00d87180(unsigned int a, B* b);
};

// @fnv 0x00d87180
// pdb: hkClassMemberAccessor::hkClassMemberAccessor | hkClassMemberAccessor.obj | fnv360_0822_debug, objrun_open, low
// pdb params: obj, mem
FUN_00d87180_cls* FUN_00d87180_cls::FUN_00d87180(unsigned int auiValue, B* apPtr)
{
    void (S::*call)(unsigned int, B*) = &S::SetValueAndPtr;
    (static_cast<S*>(this)->*call)(auiValue, apPtr);
    return this;
}

class OwnerD87A {
public:
    unsigned __int64 GetCurrentValue() const;
    int unk00;
    int unk04;
    unsigned __int64 m_uiCurrentValue;
};

// @fnv 0x00d87a50
// pdb: hkThread::getChildThreadId | hkWin32Thread.obj | tesv_win, objrun, medium
unsigned __int64 OwnerD87A::GetCurrentValue() const
{
    return m_uiCurrentValue;
}

struct hkStepInfoD881;
struct hkpSolverInfoD881;
struct hkpConstraintQueryInD881;
struct BufferStateD881 {
    char* m_pRayStart;
    char* m_kRayEnd;
    char* m_pTileTemplate;
    char* m_pValues;
};
struct hkpConstraintSolverResourcesD881 {
    hkStepInfoD881* m_pStepInfo;
    hkpSolverInfoD881* m_pSolverInfo;
    hkpConstraintQueryInD881* m_pConstraintQueryIn;
    char* m_pVelocityAccumulatorA;
    char* m_pVelocityAccumulatorB;
    char* m_pVelocityAccumulatorC;
    char* m_pBufferA;
    char* m_pBufferB;
    BufferStateD881 m_akBufferStates[3];
};

static inline char* alignDownD881(char* p) { return (char*)((unsigned int)p & ~15); }

// Stores step, solver, and query pointers, then carves the aligned buffer into velocity accumulators and three buffer states with computed ray start/end offsets.
// @fnv 0x00d881d0
// pdb: hkpConstraintSolverSetup::initializeSolverState | hkpConstraintSolverSetup.obj | fnv360_0822_retail, objopen_prop, low, conflict (bridge: hkpSolverInfo::operator=)
// pdb params: stepInfo, solverInfo, constraintQueryIn, buffer, bufferSize, s
void __cdecl InitializeConstraintSolverResources(hkStepInfoD881* pkStepInfo, hkpSolverInfoD881* pkSolverInfo, hkpConstraintQueryInD881* pkQueryIn, char* pcBuffer, int iBufferSize, hkpConstraintSolverResourcesD881* pkOut)
{
    pkOut->m_pStepInfo = pkStepInfo;
    pkOut->m_pSolverInfo = pkSolverInfo;
    pkOut->m_pConstraintQueryIn = pkQueryIn;

    iBufferSize -= iBufferSize % 16;
    const float fFactorA = -0.6f;
    const float fFactorB = -(1.0f + fFactorA);

    char* p = (char*)(((unsigned int)pcBuffer + 15) & ~15);
    pkOut->m_pVelocityAccumulatorA = p;
    p = alignDownD881(p + iBufferSize * 10 / 64);
    pkOut->m_pVelocityAccumulatorB = p;
    pkOut->m_pBufferA = p;
    p = alignDownD881(p + iBufferSize * 4 / 64);
    pkOut->m_akBufferStates[0].m_pRayStart = p;
    pkOut->m_pBufferB = p;

    float fSize = (float)(iBufferSize * 40);
    p = alignDownD881(p - (unsigned int)(fSize * fFactorA / 64.0));
    pkOut->m_akBufferStates[1].m_pRayStart = p;
    pkOut->m_akBufferStates[0].m_kRayEnd = p;

    p = alignDownD881(p - (unsigned int)(fSize * fFactorB / 64.0));
    pkOut->m_akBufferStates[2].m_kRayEnd = pcBuffer + iBufferSize;
    pkOut->m_pVelocityAccumulatorC = pkOut->m_pVelocityAccumulatorA;
    pkOut->m_akBufferStates[1].m_kRayEnd = p;
    pkOut->m_akBufferStates[2].m_pRayStart = p;
    pkOut->m_akBufferStates[0].m_pTileTemplate = pkOut->m_akBufferStates[0].m_pRayStart;
    pkOut->m_akBufferStates[0].m_pValues = pkOut->m_akBufferStates[0].m_pRayStart;
    pkOut->m_akBufferStates[2].m_pTileTemplate = pkOut->m_akBufferStates[2].m_pRayStart;
    pkOut->m_akBufferStates[2].m_pValues = pkOut->m_akBufferStates[2].m_pRayStart;
    pkOut->m_akBufferStates[1].m_pTileTemplate = pkOut->m_akBufferStates[1].m_pRayStart;
    pkOut->m_akBufferStates[1].m_pValues = pkOut->m_akBufferStates[1].m_pRayStart;
}

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

struct S00d944d0_Stream {
    int unk00;
    char* m_cur;
    int unk08;
    char* m_kRayEnd;
};

// hkMonitorStream::TimerCommand and TimerBeginListCommand (class and member names: FNV360_PDB)
struct S00d944d0_Ent12 {
    char* m_commandAndMonitor;
    unsigned int m_time0;
    unsigned int m_time1;
    // RULE-EXCEPTION: R18, Havok's IA32 setTime reads the TSC with inline asm: retail stores eax to a stack local and reloads it, which __rdtsc() does not emit
    __forceinline void setTime() { unsigned int ticks; __asm { rdtsc
        mov dword ptr[ticks], eax } m_time0 = ticks; }
};

struct S00d944d0_Ent16 : S00d944d0_Ent12 {
    char* m_nameOfFirstSplit;
};

struct S00d944d0_Sub {
    int unk00;
};

struct S00d944d0_Obj {
    S00d944d0_Sub* m_sub;
};

struct S00d944d0_Arg2 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_20;
    int m_24;
};

struct S00d944d0_Arg1 {
    void ProcessCallback(S00d944d0_Arg2* a1, S00d944d0_Arg2* a2, int a3);
};

// Records two timing entries (LtIntegrate, lt) in the TLS stream, calls FUN_00d89ed0, then invokes a2->ProcessCallback(a3, a3, 0).
// @f3 0x00a234f0 (community match, verified in this file)
namespace timer3182 { extern char DAT_00e7d35c[]; extern char DAT_00e855cc[]; extern char DAT_00e0811c[]; }
extern "C" {
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);
}
extern unsigned int DAT_0126835c;

void __cdecl FUN_00a0d5e0(void*, int, int);
struct DummyCallee {
    void __thiscall FUN_00a21830(int, void*, void*, int, int);
};

void __cdecl FUN_00d944d0(S00d944d0_Obj* apObj, S00d944d0_Arg1* a2, S00d944d0_Arg2* a3) {
    S00d944d0_Stream* stream = (S00d944d0_Stream*)TlsGetValue(DAT_0126835c);
    if (stream->m_cur < stream->m_kRayEnd) {
        S00d944d0_Ent16* ent = (S00d944d0_Ent16*)stream->m_cur;
        ent->m_commandAndMonitor = timer3182::DAT_00e7d35c;
        ent->m_nameOfFirstSplit = timer3182::DAT_00e855cc;
        ent->setTime();
        stream->m_cur = (char*)(ent + 1);
    }

    char* p = (char*)apObj->m_sub;
    FUN_00a0d5e0(p + 0x1a0, a3->unk10, a3->unk14);

    stream = (S00d944d0_Stream*)TlsGetValue(DAT_0126835c);
    if (stream->m_cur < stream->m_kRayEnd) {
        S00d944d0_Ent12* ent2 = (S00d944d0_Ent12*)stream->m_cur;
        ent2->m_commandAndMonitor = timer3182::DAT_00e0811c;
        ent2->setTime();
        stream->m_cur = (char*)(ent2 + 1);
    }

    int arg0 = *(int*)((char*)apObj + 8);
    ((DummyCallee*)a2)->FUN_00a21830(arg0, a3, a3, 0, 0);
}


namespace fnv_00d94570 {
extern unsigned int DAT_0126835c;
extern char str_010cc5c4;
extern char DAT_01076f38;

struct __declspec(align(16)) Fnv94570_Quad {
    int v0;
    int v1;
    int v2;
    int v3;
};

}  // namespace fnv_00d94570

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

struct d94eb0_cls { unsigned char b; };
extern "C" d94eb0_cls* d94eb0_target(void);
// @fnv 0x00d94eb0
// pdb: canSolveOnSingleProcessor | hkpCpuIntegrateJob.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void FUN_00d94eb0(d94eb0_cls* dst)
{
    *(unsigned char*)dst = 0;
}
void d94eb0_caller(void) { FUN_00d94eb0(d94eb0_target()); }

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

namespace fnv_00d969e0 {
struct State;
struct M20;
struct Sub;

struct Ev {
    unsigned char type;
    unsigned char b01;
    unsigned char b02;
    unsigned char unk03;
    unsigned short w04;
    short w06;
    int unk08;
    int unk0c;
    unsigned short w10;
    unsigned short unk12;
    int m_14;
    State* m_18;
    int m_1c;
    union { M20* m_20; unsigned short w20; };
    int m_24;
    union { int m_28; M20* ptr28; };
    union { Sub* m_2c; int i2c; unsigned char b2c; };
    int m_30;
    union { int m_34; struct { unsigned short w34; unsigned short w36; }; };
    int m_38;
    union { int m_3c; unsigned char b3c; };
};

struct Ev30 {
    unsigned char type;
    unsigned char b01;
    unsigned char b02;
    unsigned char unk03;
    unsigned short w04;
    short w06;
    int unk08;
    int unk0c;
    unsigned short w10;
    unsigned short unk12;
    int m_14;
    State* m_18;
    int m_1c;
    M20* m_20;
    int m_24;
    int m_28;
    Sub* m_2c;
};


struct Ev20 {
    unsigned char type;
    unsigned char b01;
    unsigned char b02;
    unsigned char unk03;
    unsigned short w04;
    short w06;
    int unk08;
    int unk0c;
    unsigned short w10;
    unsigned short unk12;
    int m_14;
    State* m_18;
    int m_1c;
};

struct Node {
    int m_00;
    int m_04;
};

struct M20 {
    int unk00;
    int m_04;
    int unk08;
    Node* m_0c;
};

struct Sub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short unk1c;
    unsigned short m_1e;
    int m_20;
};

struct State {
    int ref;
    int m_04;
    int m_08;
    int unk0c;
    int unk10;
    int m_14;
    int m_18;
    int unk1c;
    unsigned char m_20;
    unsigned char m_21;
    unsigned short unk22;
    Node* m_24;
    int unk28;
    int unk2c;
    int m_30;
    int m_34;
    unsigned short m_38;
    unsigned short m_3a;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int unk4c;
    int unk50;
    unsigned short m_54;
    unsigned short unk56;
    unsigned char m_58;
    unsigned char m_59;
    unsigned short unk5a;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int m_6c;
    int unk70;
    int m_74;
    int m_78;
    unsigned short m_7c;
    unsigned short unk7e;
};

struct Ev20;

static __forceinline void InitEv(Ev* e, Ev* ev, unsigned char type, unsigned char flag, unsigned short size)
{
    e->type = type;
    e->b01 = 0;
    e->b02 = flag;
    _ReadWriteBarrier();
    e->w04 = size;
    e->w06 = -1;
    e->w10 = ev->w10;
    e->m_14 = ev->m_14;
    e->m_18 = ev->m_18;
    e->m_1c = ev->m_1c;
}

inline void* __cdecl operator new(unsigned int, void* p) throw() { return p; }
inline void __cdecl operator delete(void*,void*) throw() {}
struct Placed2 : Ev { __forceinline Placed2(Ev* ev, State* s) {
                    InitEv(this, ev, 8, 1, 0x30);
                    *(Ev30*)this = *(Ev30*)ev;
                    this->i2c = ev->m_2c->m_20;
                
} };
struct EmptyScope { EmptyScope() { _ReadWriteBarrier(); } ~EmptyScope() { _ReadWriteBarrier(); } };
struct Stage0 : Ev { __forceinline Stage0(Ev* ev, State* s){
                    InitEv(this, ev, 6, 1, 0x40);
                    this->m_20 = (M20*)s->m_14;
                    this->m_28 = s->m_30 - (int)this->m_20;
                    this->i2c = s->m_3c - (int)this->m_20; _ReadWriteBarrier();
                    this->m_30 = s->m_40 - (int)this->m_20;
                    this->m_24 = s->m_18;
                    this->m_34 = s->m_44;
                    this->m_38 = s->m_48;
                
} };
struct Stage1 : Ev { __forceinline Stage1(Ev* ev, State* s){
                    InitEv(this, ev, 7, 1, 0x30);
                    this->m_20 = (M20*)s->m_30;
                    this->m_24 = s->m_34;
                
} };
}  // namespace fnv_00d969e0

extern double DAT_01035718;
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);

__forceinline unsigned int roundLane(const float& value)
{
    float copy = value;
    return fnv_FloatToInt(copy);
}

// @f3 0x00a0a010 (community match, verified in this file)
extern float FUN_00db8ea4;
extern float FUN_00e0613c;
extern double FUN_00db7de8;
extern double FUN_00dd2790;
extern float FUN_01092a50[4];
struct __declspec(align(16)) FourChannels { float x,y,z,w; };
struct FourIntegers { int x,y,z,w; };
// pdb: hkVector4Util::getFloatToInt32FloorCorrection | hkVector4Util.obj | tesv_win, objrun_open, low
float FUN_00d974f0()
{
    float high = FUN_00db8ea4;
    float low = FUN_00e0613c;
    int count = 23;
    for (;;)
    {
        float f = (float)((low + high) * FUN_00db7de8);
        FourChannels p;
        p.x = FUN_01092a50[0] + f;
        p.y = FUN_01092a50[1] + f;
        p.z = FUN_01092a50[2] + f;
        p.w = FUN_01092a50[3] + f;
        p.x = (volatile float&)p.x;
        p.y = (volatile float&)p.y;
        p.z = (volatile float&)p.z;
        p.w = (volatile float&)p.w;
        FourIntegers ints;
        ints.x = roundLane(p.x);
        ints.y = roundLane(p.y);
        ints.z = roundLane(p.z);
        ints.w = roundLane(p.w);
        if ((unsigned)ints.x < 11u)
        {
            high = f;
            if (--count == 0) break;
            continue;
        }
        low = f;
        if (--count == 0) break;
    }
    return (float)((low + high) * FUN_00db7de8 - FUN_00dd2790);
}


extern const __m128 DAT_011b6de0;

#include <stdarg.h>
namespace fnv_00d87aa0 {
extern const char DAT_010d3cb4[];
int __cdecl FUN_00cb0fa0(int a, int b);
extern "C" int __cdecl hkString_strLen(const char* s);
int __cdecl FUN_00cb0f80(char* buf, const char* fmt, ...);
int __cdecl FUN_00cb0f50(char* buf, int size, const char* fmt, va_list args);
struct FUN_00cc0470_Stream { void hkOstream_write(const char* s, int n); };
struct D87aa0Name { char m_name[32]; };
struct D87aa0Reporter {
    int unk;
    int unkCur;
    FUN_00cc0470_Stream* m_stream;
    int m_uiItemCount;
    D87aa0Name* m_filters;
    int m_numFilters;
};

// @fnv 0x00d87aa0
void __cdecl FUN_00d87aa0(D87aa0Reporter* apReporter, const char* id, const char* fmt, ...)
{
    for (int i = 0; i < apReporter->m_numFilters; i++) {
        D87aa0Name& e = apReporter->m_filters[i];
        if (FUN_00cb0fa0((int)e.m_name, (int)id) == 0)
            return;
    }
    int n = ++apReporter->m_uiItemCount;
    if (n == 0x803)
        apReporter->m_uiItemCount = n;
    if (apReporter->m_stream) {
        int buf[0x100];
        va_list args;
        va_start(args, fmt);
        if (*fmt == '#') {
            FUN_00cb0f80((char*)buf, DAT_010d3cb4, n);
            apReporter->m_stream->hkOstream_write((char*)buf, hkString_strLen((char*)buf));
            FUN_00cb0f50((char*)buf, 0x400, fmt + 1, args);
        } else {
            FUN_00cb0f50((char*)buf, 0x400, fmt, args);
        }
        apReporter->m_stream->hkOstream_write((char*)buf, hkString_strLen((char*)buf));
    }
}
}  // namespace fnv_00d87aa0

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

struct HasFlag_d86 {
    char pad[0x10];
    unsigned short m_flags;
    hkBool_d86 hkClassMember_isNotOwner() const;
};

// @fnv 0x00d86a70
// pdb: hkClassMember::isNotOwner | hkClassMember.obj | fnv360_0822_retail, objrun, high
// pdb: hkClassMember::isNotOwner | hkClassMember.obj | fnv360_0822_retail, objrun, high (was: HasFlag)
hkBool_d86 HasFlag_d86::hkClassMember_isNotOwner() const
{
    return (m_flags & 0x200) == 0x200;
}

struct D94Rec16 {
    const char* name;
    unsigned int start;
    unsigned int unk08;
    const char* name2;
};
struct D94Rec12 {
    const char* name;
    unsigned int start;
    unsigned int unk08;
};
struct D94Tls {
    int unk00;
    D94Rec16* pCur;
    int unk08;
    D94Rec16* pEnd;
};
extern unsigned int DAT_0126835c;
typedef void* (__stdcall *D94TlsGetFn)(unsigned long);
extern D94TlsGetFn DAT_00fdf044;
struct D94Sub {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int m30;
};
struct D94Body {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    D94Sub* m18;
    int u1c;
    int* p20;
    unsigned short us24;
    unsigned short us26;
};
struct D94Obj {
    int ProcessCallback(D94Body* a, D94Body* b, int c);
};
// Records two timing markers in a TLS buffer, calls FUN_00d29830 with a3 fields, then returns a2->ProcessCallback(a3, a3, 0).
// @f3 0x00a23da0 (community match, verified in this file)
struct D94BodyF3 {
    int u00;
    int u04;
    D94Sub* m08;
    int u0c;
    int* p10;
    unsigned short us14;
    unsigned short us16;
};
struct D94ObjF3 {
    int FUN_00a21830(int a, D94Body* b, D94Body* c, char* d, int e);
};
void __cdecl hkRigidMotionUtilApplyForcesAndBuildAccumulators(char* p, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
int __cdecl FUN_00d94df0(char* a1, D94Obj* a2, D94Body* a3)
{
    D94TlsGetFn fn = (D94TlsGetFn)TlsGetValue;
    D94Tls* tp = (D94Tls*)fn(DAT_0126835c);
    D94Rec16* cur = tp->pCur;
    if (cur < tp->pEnd) {
        cur->name = "LtIntegrate";
        cur->name2 = "StBuildAccumulators";
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        cur->start = t;
        cur++;
        tp->pCur = cur;
    }
    D94BodyF3* b = (D94BodyF3*)a3;
    hkRigidMotionUtilApplyForcesAndBuildAccumulators(a1 + 0x60, (unsigned int)(b->p10 + b->us14), b->us16, 0xd0, ((b->us14 + 1) << 7) + b->m08->m30);
    D94Tls* tp2 = (D94Tls*)fn(DAT_0126835c);
    D94Rec12* r = (D94Rec12*)tp2->pCur;
    if (r < (D94Rec12*)tp2->pEnd) {
        r->name = "lt";
        _ReadWriteBarrier();
        volatile unsigned int t2 = (unsigned int)__rdtsc();
        r->start = t2;
        r++;
        tp2->pCur = (D94Rec16*)r;
    }
    return ((D94ObjF3*)a2)->FUN_00a21830(*(int*)(a1 + 8), a3, a3, a1, 0);
}


#include <string.h>

static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do {
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        s += 4; d += 4;
    } while (--numQuads > 0);
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
// @fnv 0x00d98630
D986Result __cdecl FUN_00d98630(const __m128* src, const __m128* dst, int mask)
{
    D986Result result(true);
    __m128 zero = _mm_setzero_ps();
    for (int i=0; i<3; ++i) {
        __m128 d = _mm_sub_ps(dst[i], src[i]);
        bool hit = ((_mm_movemask_ps(_mm_cmplt_ps(d,zero)) & mask) == mask)
            || ((_mm_movemask_ps(_mm_cmpeq_ps(d,zero)) & mask) == mask)
            || ((_mm_movemask_ps(_mm_cmplt_ps(zero,d)) & mask) == mask);
        result = result && hit;
    }
    return result;
}

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
// Copies src into dst in 16-byte blocks, then returns popPart(src, dst), which advances src by its type and sets dst->field14.
// @f3 0x00a25250 (community match, verified in this file)
struct PopLink {
    PopLink* next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char flag1c;
};
struct PopTable {
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
struct PopCtx {
    int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;
    PopTable* holder;
};
struct PopRec {
    unsigned short type;
    unsigned short word02;
    int field04;
    int unk08;
    int unk0c;
    union {
        int count10;
        unsigned int offset10;
        PopLink* node10;
    };
    union {
        unsigned int limit14;
        struct {
            unsigned short word14;
            unsigned short word16;
        };
    };
    unsigned short word18;
    unsigned short word1a;
    PopLink* node1c;
    int unk20;
    unsigned short word24;
    unsigned short word26;
    int unk28;
    int unk2c;
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

    int FUN_00a7cd60(int** slot, PopRec* dst);
};

// pdb: hkpJobQueueUtils::popIntegrateJob | hkpDynamicsJobQueueUtils.obj | tesv_win, objrun_open, low
int __cdecl PopPart(int callbackCtx, int callbackIndex, D96600Blob* a, D96600Blob* b)
{
    PopRec* src = (PopRec*)a;
    PopRec* dst = (PopRec*)b;
    memCpy16NonEmpty(dst, src, sizeof(PopRec) / 16);
    PopTable* holder = ((PopCtx*)callbackCtx)->holder;
    int** slot = &holder->table;
    dst->field04 = holder->table[dst->word02];

    int r;
    switch (src->type) {
    case 0: {
        int n = src->count10;
        if (n <= 1)
            { r = 0; break; }
        src->word02++;
        src->count10 = n - 1;
        dst->count10 = 1;
        { r = 1; break; }
    }
    case 1: {
        unsigned short step = 0x80;
        if (src->word16 <= step)
            { r = 0; break; }
        src->word16 = (unsigned short)(src->word16 - step);
        src->word14 = (unsigned short)(src->word14 + step);
        dst->word16 = step;
        { r = 1; break; }
    }
    case 4:
        if (src->node10->next == 0)
            { r = 0; break; }
        src->node10 = src->node10->next;
        { r = 1; break; }
    case 12:
        { r = src->FUN_00a7cd60(slot, dst); break; }
    case 11: {
        unsigned short step = 0x80;
        if (src->word24 > step) {
            src->word24 = (unsigned short)(src->word24 - step);
            src->word26 = (unsigned short)(src->word26 + step);
            dst->word24 = step;
            { r = 1; break; }
        }
        if (src->count10 == 0)
            { r = 0; break; }
        src->type = 0x0a;
        { r = 1; break; }
    }
    case 7:
    case 9: {
        unsigned int next = src->offset10 + 0x4000;
        if (next >= src->limit14)
            { r = 0; break; }
        src->offset10 = next;
        dst->limit14 = next;
        { r = 1; break; }
    }
    case 8:
        if (src->node1c->flag1c != 0)
            { r = 0; break; }
        src->node1c = src->node1c->next;
        { r = 1; break; }
    case 10:
        if (src->node10->next == 0)
            { r = 0; break; }
        src->node10 = src->node10->next;
        { r = 1; break; }
    case 3:
    case 6:
    case 14:
        *dst = *src;
        r = 0; break;
    case 13: {
        unsigned short a = src->word18;
        unsigned short c = src->word1a;
        if (a <= c) { r = 0; break; }
        src->word14++;
        src->word18 = (unsigned short)(a - c);
        src->unk30 += c;
        dst->word18 = c;
        dst->word34 = 0x200;
        { r = 1; break; }
    }
    case 15: {
        unsigned short a = src->word18;
        unsigned short c = src->word1a;
        if (a <= c) { r = 0; break; }
        src->word14++;
        src->word18 = (unsigned short)(a - c);
        dst->word18 = c;
        { r = 1; break; }
    }
    default:
        { r = 0; break; }
    }
    return r;
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
__m128i _mm_setzero_si128();
__m128i _mm_unpacklo_epi16(__m128i, __m128i);
__m128i _mm_unpackhi_epi16(__m128i, __m128i);
__m128i _mm_srli_epi32(__m128i, int);
__m128i _mm_slli_epi32(__m128i, int);
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
struct __declspec(align(16)) QuantizedBounds {
    unsigned short minX, minY, minZ, idLow;
    unsigned short maxX, maxY, maxZ, idHigh;
};
extern const double DAT_010217d0;
extern const __m128 DAT_011b6de0;
extern const float DAT_010cd644 = 1.0000000272564224e16f;
extern const float DAT_0104e148 = -3.402820018375656e38f;
extern const float DAT_0104da48 = 3.402820018375656e38f;

template<class T> struct TreeRef { T* p; TreeRef(T* q):p(q){} operator T*()const{return p;} T* operator->()const{return p;} };

struct BoundPair { __m128 minimum, maximum; void set(float a, float b) { minimum = _mm_set_ps1(a); maximum = _mm_set_ps1(b); } };

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

namespace fnv_00d86050 {
extern unsigned int DAT_0126835c;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

}  // namespace fnv_00d86050

namespace fnv_00d87a10 {
#include <windows.h>


class FUN_00d87a10_Obj {
public:
    int unk00;
    int FUN_00d87a10();
};

// Returns 2 if the thread handle is null, otherwise queries the thread exit code and returns 1 if it equals 0x103, else 0.
// @fnv 0x00d87a10
// pdb: hkThread::getStatus | hkWin32Thread.obj | tesv_win, hash, low
int FUN_00d87a10_Obj::FUN_00d87a10() {
    if (unk00 == 0)
        return 2;

    DWORD exitCode;
    GetExitCodeThread(reinterpret_cast<HANDLE>(static_cast<int>(unk00)), &exitCode);
    return exitCode == 0x103;
}
}  // namespace fnv_00d87a10

namespace fnv_00d94340 {
#include <intrin.h>


extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_0126835c;

}  // namespace fnv_00d94340

extern double DAT_01035718;

union F128U
{
    __m128 v;
    unsigned u[4];
};

static const F128U V4C = { { 196608.0f, 196608.0f, 196608.0f, 196608.0f } };

extern "C" void _mm_store_ps(float* p, __m128 a);

extern int DAT_010d37e4;

struct FUN_00d84bd0
{
    unsigned int m_00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile unsigned int m_08;
    unsigned int unk0c;
    volatile unsigned short m_10;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    volatile float m_20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    volatile float m_34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    volatile float m_48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    volatile float m_60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    volatile float m_74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    volatile float m_88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    volatile unsigned short m_a0;
    volatile unsigned char m_a2;

    FUN_00d84bd0();
};

// Stores &DAT_010d37e4 at offset 0, sets m_06=1, m_10=2, m_a0=7, sets m_20/m_34/m_48 and m_60/m_74/m_88 to 1.0f, and zeroes the other 16-byte blocks.
// @fnv 0x00d84bd0
FUN_00d84bd0::FUN_00d84bd0()
{
    *(int**)this = &DAT_010d37e4;
    m_06 = 1;
    m_08 = 0;
    m_10 = 2;
    m_a0 = 7;
    _mm_store_ps((float*)((char*)this + 0x20), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x30), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x40), _mm_setzero_ps());
    m_20 = 1.0f;
    m_34 = 1.0f;
    m_48 = 1.0f;
    _mm_store_ps((float*)((char*)this + 0x50), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x60), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x70), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x80), _mm_setzero_ps());
    m_60 = 1.0f;
    m_74 = 1.0f;
    m_88 = 1.0f;
    _mm_store_ps((float*)((char*)this + 0x90), _mm_setzero_ps());
    m_a2 = 0;
}

extern "C" {
__m128 _mm_add_ss(__m128,__m128);
__m128 _mm_shuffle_ps(__m128,__m128,int);
__m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_rsqrt_ss(__m128);
__m128 _mm_mul_ss(__m128,__m128);
__m128 _mm_cmpeq_ss(__m128,__m128);
__m128 _mm_andnot_ps(__m128,__m128);
__m128 _mm_sub_ss(__m128,__m128);
__m128 _mm_or_ps(__m128,__m128);
__m128 _mm_and_ps(__m128,__m128);
__m128 _mm_setzero_ps();
__m128 _mm_load_ss(const float*);
__m128 _mm_set_ps1(float);
__m128 _mm_cmpeq_ps(__m128,__m128);
__m128 _mm_unpackhi_ps(__m128,__m128);
__m128 _mm_rcp_ps(__m128);
__m128 _mm_add_ps(__m128,__m128);
__m128 _mm_cmple_ps(__m128,__m128);
__m128 _mm_cmplt_ps(__m128,__m128);
__m128 _mm_min_ps(__m128,__m128);
__m128 _mm_max_ps(__m128,__m128);
int _mm_movemask_ps(__m128);
}
extern "C" {
__m128i _mm_setzero_si128();
__m128i _mm_unpacklo_epi16(__m128i, __m128i);
__m128i _mm_unpackhi_epi16(__m128i, __m128i);
__m128i _mm_slli_epi32(__m128i, int);
__m128i _mm_srli_epi32(__m128i, int);
__m128 _mm_cvtepi32_ps(__m128i);
}

// Storage remains POD so that the aligned scratch vectors do not require /GS.
struct __declspec(align(16)) RayVector {
    union {
        __m128 simd;
        struct { float x, y, z, w; };
        float components[4];
    };
    __forceinline __m128 get() const { return simd; }
    __forceinline void set(__m128 v) { simd = v; }
    __forceinline const float& operator[](unsigned i) const { return components[i]; }
};
struct RayMask {
    __m128 simd;
    RayMask() {}
    RayMask(__m128 v) : simd(v) {}
    __forceinline __m128 get() const { return simd; }
    __forceinline void set(__m128 v) {simd=v;}
};
struct __declspec(align(16)) PackedVector { unsigned x,y,z,w; };
struct RayCollector {
    virtual void unused();
    virtual FNV_00d99f50_Result report(unsigned key);
    virtual FNV_00d99f50_Result finish();
    virtual float fraction();
};
struct VectorRef { unsigned address; const RayVector* get() const { return reinterpret_cast<const RayVector*>(address); } const RayVector* operator->() const { return get(); } };
struct CollectorRef { RayCollector* p; RayCollector* operator->() const { return p; } };
struct OutputRef { unsigned address; void* get() const { return reinterpret_cast<void*>(address); } };
extern const float DAT_01011d78, DAT_01017718, DAT_01016248;
extern const float DAT_010d4080, DAT_010cd644, DAT_0104e148, DAT_0104da48;
extern const double DAT_010217d0, DAT_01032980;

__forceinline __m128 broadcast(double f) { RayVector v; v.x=(float)f; v.y=(float)f; v.z=(float)f; v.w=(float)f; return v.get(); }

namespace RayTraversal {

}
