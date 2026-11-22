#include "f3_common.h"
// src/staging/blk_00c40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00c42b60_class {
    int __thiscall FUN_00c42b80();
    int a;
    int b;
    void FUN_00c42b60();
};

void __cdecl EnsureArenaAllocated(void*);

struct NiStream;

struct NiAVObject;
struct NiBinaryExtraData {
    void FUN_00a9af00(NiAVObject* a);
    void FUN_00c430f0(NiAVObject* a);
};

namespace fnv_00c43110 {
struct NiBinaryExtraData {
    bool FUN_00a89ae0(void* arg);
    bool FUN_00c43110(void* arg);
};
}  // namespace fnv_00c43110

struct NiFixedString;
struct NiAVObject { void SetName(const NiFixedString&); void FUN_00c43470(); };

struct NiNode {
    void __thiscall ReadChildListFromStream(void*);
};

struct FUN_00c44cb0_class {
    void* m0;
    void* m1;
    void* m2;
    void __thiscall CallStoredCallback(void*, void*);
};

// @f3 0x0063d470 (community match, verified in this file)
int __cdecl FUN_00beb8c0(void* a, int b);
void FUN_00c44cb0_class::CallStoredCallback(void* a, void* b)
{
    *(void**)((char*)this + 0xc) = a;
    *(void**)((char*)this + 0x18) = b;
    *(int*)((char*)this + 0x14) = FUN_00beb8c0(a, 0xe04940);
}


void __cdecl FUN_00a5e930(void*);

struct NiStream;

struct FUN_00c452c0_class {
    unsigned char FUN_00c452c0(NiStream*);
};

struct NiStream;
struct NiPSysModifier {
    void LinkObject(NiStream&);
    void FUN_00c467f0(NiStream& stream);
};

namespace fnv_00c46ca0 {
struct NiStream {
    void ResetStreamState();
};

struct NiNode {
    void LoadBinary(NiStream& stream);
    void FUN_00c46ca0(NiStream& stream);
};

}  // namespace fnv_00c46ca0

struct P03MM { void* Allocate(unsigned int); void* AllocateScaled(unsigned int count); };
extern P03MM g_memoryManager;

namespace fnv_00c4a890 {
struct MemoryManager { void Deallocate(void*); };
extern MemoryManager g_memoryManager;
}  // namespace fnv_00c4a890

namespace fnv_00c4a900 {
struct P03MM {
    void* Allocate(unsigned int);
    void* FUN_00c4a900(unsigned int a);
};
extern P03MM g_memoryManager;

}  // namespace fnv_00c4a900

namespace fnv_00c4a930 {
struct MemoryManager { void* Reallocate(void* p, unsigned int size); };
extern MemoryManager g_memoryManager;

}  // namespace fnv_00c4a930

struct FUN_00c452a0_class {
    void FUN_00c452a0(int a);
};

extern "C" void* g_01202e7c;

namespace fnv_00c4adc0 {

struct FUN_00c452a0_class {
    void __thiscall FUN_00c452a0(int);
};

}  // namespace fnv_00c4adc0

namespace fnv_00c4b040 {
struct FUN_00c452c0_class {
    unsigned char FUN_00c452c0(int);
    char IsNonZero(int a);
};

}  // namespace fnv_00c4b040

struct GlobalObject_00a7b610;

struct NiNode;

struct BaseT {
    ~BaseT();
};

struct FUN_00c516d0 : BaseT {
    void DoIt();
};

struct NiStream;
struct NiExtraData {
    void LinkObject(NiStream&);
};

extern "C" void* g_012031e8;

struct NiStream;

struct NiStream;

extern int g_01203340;

extern int DAT_010c2e7c;

extern int DAT_010c2e7c;

struct StrArr;

struct GlobalObject_00a7b610 {
    GlobalObject_00a7b610* __thiscall GetGlobalInstance();
};

namespace fnv_00c5f570 {
extern int DAT_010c31a4;

struct NiNode {
    NiNode(unsigned short);
};

struct FUN_00c5f570 : NiNode {
    FUN_00c5f570();
};

// @fnv 0x00c5f570
FUN_00c5f570::FUN_00c5f570() : NiNode(0)
{
    *reinterpret_cast<int**>(this) = &DAT_010c31a4;
}
}  // namespace fnv_00c5f570

extern int DAT_010c31a4;
struct FUN_00c5faa0 {
    void FUN_00a5e930();
};

extern void* DAT_010c32c4;
struct NiPSysPositionModifier { NiPSysPositionModifier(); };
struct FUN_00c5fd30 : NiPSysPositionModifier {
    FUN_00c5fd30();
};
NiPSysPositionModifier::NiPSysPositionModifier() {}
// @fnv 0x00c5fd30
FUN_00c5fd30::FUN_00c5fd30()
{
    *(void**)this = &DAT_010c32c4;
}

namespace fnv_00c5fec0 {
struct CloningProcess { };
struct NiPSysModifier {
    void CopyMemberData(NiPSysModifier*, CloningProcess&);
    void __thiscall FUN_00c5fec0(NiPSysModifier* apDest, CloningProcess& apProcess);
};
}  // namespace fnv_00c5fec0

namespace fnv_00c5ff90 {
struct NiStream;

struct NiPSysModifier {
    virtual void LinkObject(NiStream&);
};

}  // namespace fnv_00c5ff90

extern int DAT_010c30b8;

struct MemoryManager { void Deallocate(void*); };

namespace fnv_00c40960 {
struct MemoryManager { void Deallocate(void*); };
}  // namespace fnv_00c40960

namespace fnv_00c409b0 {
struct MemoryManager {
    void Deallocate(void*);
};
}  // namespace fnv_00c409b0

namespace fnv_00c40a70 {
struct MemoryManager { void Deallocate(void*); };
}  // namespace fnv_00c40a70

namespace fnv_00c40b40 {
struct MemoryManager {
    void Deallocate(void*);
};
}  // namespace fnv_00c40b40

void __cdecl FUN_00c43070(void*);
struct FUN_00c43620_Class {
    void __thiscall FUN_00c43070();
    void* __thiscall FUN_00c43620(unsigned int flags);
    static void __cdecl operator delete(void* p, unsigned int size);
};

void __cdecl EnsureArenaAllocated(void*);

namespace fnv_00c44df0 {
struct MemoryManager { void Deallocate(void*); };
extern MemoryManager _g_memoryManager;
}  // namespace fnv_00c44df0

struct NiPSysModifier;
struct CloningProcess;

namespace fnv_00c4a990 {
struct MemoryManager {
    void Deallocate(void*);
};
extern P03MM g_memoryManager;
void __cdecl FUN_00c4a8e0(void*);
}  // namespace fnv_00c4a990

extern "C" void* g_01202e7c;
extern "C" void* __cdecl FUN_00a7d330(void*);

void __cdecl FNV_Warning(const char* fmt, ...);

void __cdecl operator delete(void* ptr, unsigned int size);

namespace fnv_00c54d70 {
struct MemoryManager { void Deallocate(void*); };
extern MemoryManager _g_memoryManager;
}  // namespace fnv_00c54d70

struct NiStream;

struct FUN_00c55330_class {
    void* __thiscall FUN_00c55330(unsigned int flags);
    void operator delete(void* p, unsigned int size);
};

namespace fnv_00c5bae0 {
extern "C" void __cdecl operator delete(void*, unsigned int);

}  // namespace fnv_00c5bae0

extern int DAT_010c2d54;

extern int DAT_010c2d54;

struct NiStream;

namespace fnv_00c5ce10 {
extern "C" void __cdecl operator delete(void*, unsigned int);
}  // namespace fnv_00c5ce10

extern "C" unsigned char DAT_01204364;

extern unsigned char DAT_01204364;

void __cdecl operator delete(void* p, unsigned int size);

namespace fnv_00c5eca0 {
extern int DAT_010c30b8;
extern "C" void __cdecl NiFree(void*);
struct MemoryManager {
    void __thiscall Deallocate(void*);
};
}  // namespace fnv_00c5eca0

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00c5fc20_class {
    void* __thiscall FUN_00c5fc20(unsigned int flags);
    void __cdecl operator delete(void* p, unsigned int size);
    void __thiscall FUN_00c5faa0();
};

struct NiObject {
    char pad[0xb0];
    int p;
    unsigned char flag;
};

struct FUN_00c4a9c0_class {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08(void*);
    void* m_p;
    unsigned int m_uiItemCount;
    int m_auiShapeKeys;
    void __thiscall ReleaseBuffer(unsigned char a);
};
// @fnv 0x00c4a9c0
void __thiscall FUN_00c4a9c0_class::ReleaseBuffer(unsigned char a)
{
    if (m_p) {
        for (int i = 0; i < m_uiItemCount; ++i) {
        }
        if (a) {
            vfn_08(m_p);
            m_p = 0;
            m_p = 0;
            m_auiShapeKeys = 0;
        }
        m_uiItemCount = 0;
    }
}

extern int DAT_010c1b2c;
struct FUN_00c5f570_Class {
    void __thiscall FUN_00c5f570();
};
struct FUN_00c450d0 : FUN_00c5f570_Class {
    int vtbl;
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char ba;
    unsigned char bb;
    unsigned char bc;
    unsigned char bd;
    unsigned char be;
    unsigned char bf;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    unsigned char c4;
    unsigned char c5;
    unsigned char c6;
    unsigned char c7;
    unsigned char c8;
    unsigned char c9;
    unsigned char ca;
    unsigned char cb;
    unsigned char cc;
    unsigned char cd;
    unsigned char ce;
    unsigned char cf;
    unsigned char d0;
    unsigned char d1;
    unsigned char d2;
    unsigned char d3;
    unsigned char d4;
    unsigned char d5;
    unsigned char d6;
    unsigned char d7;
    unsigned char d8;
    unsigned char d9;
    unsigned char da;
    unsigned char db;
    unsigned char dc;
    unsigned char dd;
    unsigned char de;
    unsigned char df;
    unsigned char e0;
    unsigned char e1;
    unsigned char e2;
    unsigned char e3;
    unsigned char e4;
    unsigned char e5;
    unsigned char e6;
    unsigned char e7;
    unsigned char e8;
    unsigned char e9;
    unsigned char ea;
    unsigned char eb;
    unsigned char ec;
    unsigned char ed;
    unsigned char ee;
    unsigned char ef;
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    unsigned char a0;
    unsigned char a1;
    unsigned char a2;
    unsigned char a3;
    unsigned char a4;
    unsigned char a5;
    unsigned char a6;
    unsigned char a7;
    unsigned char a8;
    unsigned char a9;
    unsigned char aa;
    unsigned char ab;
    unsigned char ac;
    unsigned char ad;
    unsigned char ae;
    unsigned char af;
    FUN_00c450d0();
};
// Calls the base constructor, installs the vtable, and initialises the bytes at offsets 0xac-0xaf to 1, 0, 0, 0xff.
// @fnv 0x00c450d0
FUN_00c450d0::FUN_00c450d0()
{
    FUN_00c5f570_Class::FUN_00c5f570();
    vtbl = (int)&DAT_010c1b2c;
    *(unsigned char*)((char*)this + 0xae) = 0;
    *(unsigned char*)((char*)this + 0xaf) = 0xff;
    *(unsigned char*)((char*)this + 0xad) = 0;
    *(unsigned char*)((char*)this + 0xac) = 1;
}

struct FUN_00c465a0_class {
    void* operator new(unsigned int);
    FUN_00c465a0_class();
    char pad[0x1c];
};

struct FUN_00c465a0 {
    char* p;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    FUN_00c465a0();
    ~FUN_00c465a0();
    static void* operator new(unsigned int);
};

struct CloningProcess;
struct NiBinaryExtraData;

struct NiObject;
struct NiStream {
    NiObject* DeserializeObject();
};

char* __cdecl FUN_00a7d330(char const*);

int __cdecl FUN_00c33090(int);

extern "C" __declspec(dllimport) void __stdcall FreeLibrary(void*);
extern "C" __declspec(dllimport) void __stdcall DeleteObject(void*);

extern int DAT_010c195c;

struct FUN_00c43660 : FUN_00c5f570_Class {
    char pad[0xb0];
    int f1;
    int f2;
    FUN_00c43660();
};
// @fnv 0x00c43660
FUN_00c43660::FUN_00c43660()
{
    FUN_00c5f570();
    *(int*)this = (int)&DAT_010c195c;
    f1 = 0;
    f2 = 0;
}

void __cdecl FUN_00a643b0(NiStream& stream, unsigned int& value);

struct A51BF0Base {
    char pad[0xb4];

    static void* __cdecl operator new(unsigned int size);
    A51BF0Base();

    void __thiscall FUN_00c46c30(A51BF0Base* copy, int a);
    A51BF0Base* __thiscall FUN_00c46ba0(int a);
};

struct GO {
    void operator=(void*);
};

unsigned int __cdecl _FUN_00a7d330(int a);

template <class T>
class NiTPrimitiveArray {
public:
    unsigned int AddFirstEmpty(const T& value);
};

unsigned int __cdecl _FUN_00a7d330(void*);

void NiFree(void* ptr);

namespace fnv_00c4e160 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int);
};

}  // namespace fnv_00c4e160

namespace fnv_00c513f0 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c5da70 : public A51BF0Base {
    char pad[0xdc];

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
    virtual void v55(int, int);

    void FUN_00c5de70();

    FUN_00c5da70();
};

unsigned char __cdecl FUN_00c50f90(int, int);

}  // namespace fnv_00c513f0

namespace fnv_00c514c0 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

int _data_011c16bc;

struct FUN_00c503d0 : public A51BF0Base {
    char pad[0xb8];
    FUN_00c503d0();
};

}  // namespace fnv_00c514c0

struct FUN_00c5d260_view {
    void __thiscall Destruct();
    static void __cdecl operator delete(void* p, unsigned int sz);
};

namespace fnv_00c5e4d0 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c5da70 : public NiNode, public A51BF0Base {
    char pad[0xdf];

    FUN_00c5da70();
};

}  // namespace fnv_00c5e4d0

namespace fnv_00c5e5a0 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int);
};

}  // namespace fnv_00c5e5a0

namespace fnv_00c5ee00 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

}  // namespace fnv_00c5ee00

extern "C" void (__stdcall *FUN_00fdf1c0)(void*);

struct FUN_00c42b60_class;
extern "C" char DAT_011f6238;
typedef void (__stdcall *S_00c422d0_IAT_Fn)(void*);

void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedObject_b9874 {
    char m00[0x10];
    SpawnedObject_b9874();
    void Init(int* arg);
    static void* operator new(unsigned int size) { return FUN_00aa13e0(size); }
};

struct S_00c437c0_Obj {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    static void* operator new(unsigned int);
    S_00c437c0_Obj();
};

void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedObject_b9504 : FUN_00c43660 {
    static void* operator new(unsigned int size) throw() { return FUN_00aa13e0(size); }
};

// CopyStringBeforeColon
// Copies the leading part of a path (up to the first ':') into a caller buffer.

class NiStream;

void FUN_00a643b0(NiStream& kStream, bool& m_bHeaderParsed);

extern "C" __declspec(dllimport) int __stdcall fnv_Import_TryEnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall fnv_Import_LeaveCriticalSection(void* cs);

class GameLockB {
public:
    void FUN_00c46080();
};

extern GameLockB DAT_01202e20;

namespace fnv_00c45a80 {
// TruncateStringToMaxLength: clamps the maximum length of the global fixed string object
// DAT_01202e20 down to 100 characters when it has grown past that limit.

struct FUN_00c45a80_cls
{
    unsigned int m_uiUnknown;    // +0x00
    char*        m_pString;      // +0x04
    unsigned short m_usLength;   // +0x08
    unsigned short m_usMaxLength;// +0x0a
    void __thiscall FUN_00c45b20(int aMaxLength);
};

extern FUN_00c45a80_cls DAT_01202e20;
extern unsigned short DAT_01202e2a;

}  // namespace fnv_00c45a80

namespace fnv_00c45ae0 {
extern "C" unsigned short DAT_01202e2a;

struct FUN_00c45b20_Class {
    void __thiscall FUN_00c45b20(unsigned int value);
};

extern "C" FUN_00c45b20_Class DAT_01202e20;

}  // namespace fnv_00c45ae0

// AppendElement @ 0x00c45e00 (75 bytes) - __thiscall member, 1 stack parameter (ret 4).
// Add(element) of an NiTArray-style growable array:
//   +0x00 vtable, +0x04 m_pBase, +0x08 m_usMaxSize (u16),
//   +0x0A m_usSize (u16), +0x0C m_usESize (u16), +0x0E m_usGrowBy (u16).
// index = m_usSize; if (index >= m_usMaxSize) grow via FUN_00c45b20
// (m_usGrowBy + index); store element at index via SetSlot; return index.

namespace fnv_00c46420 {

struct S_00aa4060_Class
{
    void FUN_00aa4060(void*);
};

extern S_00aa4060_Class DAT_011f6238;

extern "C" void __stdcall FUN_00ec5fce(
    void* object,
    int elementSize,
    int count,
    void (__cdecl *callback)()
);

}  // namespace fnv_00c46420

namespace fnv_00c464c0 {
extern int DAT_010c1c5c;

class AudioPool {
public:
    void FUN_00aa4060(void* apMemory);
};
extern AudioPool DAT_011f6238;

}  // namespace fnv_00c464c0

extern int DAT_010c1c5c;

void* __cdecl FUN_00aa13e0(unsigned int size);

struct NewObject_b9649 {
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
    NewObject_b9649();
    static void* operator new(unsigned int size) { return FUN_00aa13e0(size); }
};

// Stand-in model of CheckProcStateAndPlane (0x00c47150, 252 bytes) - an /Od member function.
//
// The original is:
//   bool CheckProcStateAndPlane(Vec3 pt, Proc* proc, Plane* plane)
//   {
//       if (proc->unk90 == 3 || proc->unk90 == 1) return true;
//       if (plane) {
//           obj.FUN_0045c620();                  // 0x0045c620
//           plane->FUN_00c33870(pt, &obj);      // 0x00c33870
//           Target* t = this->unkAC->unk0c;
//           if (t->v40(&obj)) {                 // vtable slot 0xA0
//               Target* u = this->unkAC->unk0c;
//               u->unk08 = 2;
//               return false;
//           }
//       }
//       return true;
//   }
//
// The local NAMES below are not arbitrary: under /Od the frame slot of every local is
// decided by the 16-bucket hash of its name, so the names are chosen to put each local on
// the frame slot the original uses (see attempts.txt).  The three dead int locals exist
// only to reserve the four unused 4-byte slots that the original's frame shows.

struct FNV_Vec3 {
    float x;
    float y;
    float z;
};

struct FNV_Proc {
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
};

struct FNV_Local {
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
    void FUN_0045c620();
};

struct FNV_Target {
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
    virtual bool v40(FNV_Local* pObj);
    int unk04;
    int unk08;
};

struct FNV_Holder {
    int unk00;
    int unk04;
    int unk08;
    FNV_Target* unk0c;
};

struct FNV_Plane {
    void FUN_00c33870(FNV_Vec3 pt, FNV_Local* pObj);
};

struct FNV_Owner {
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
    FNV_Holder* unkAC;
    bool CheckProcStateAndPlane(FNV_Vec3 pt, FNV_Proc* proc, FNV_Plane* plane);
};

// @fnv 0x00c47150
bool FNV_Owner::CheckProcStateAndPlane(FNV_Vec3 vecPoint, FNV_Proc* proc, FNV_Plane* plane)
{
    int F;                       // dead local, frame filler only
    int C;                       // dead local, frame filler only
    int EG;                      // dead local, frame filler only
    FNV_Local B;                 // the 0x64-byte object at [ebp-0x70]

    FNV_Proc* J = proc;          // the copied pointer, [ebp-4]
    int K;                       // the first state,  [ebp-0x74]
    int b;                       // the second state, [ebp-0x78]
    if ((K = J->unk90) == 3 || (b = J->unk90) == 1) return true;
    if (plane) {
        B.FUN_0045c620();        // the object's initialiser, 0x0045c620
        plane->FUN_00c33870(vecPoint, &B);
        FNV_Holder* A = this->unkAC;             // [ebp-0x84]
        FNV_Target* volatile c = A->unk0c;      // [ebp-0x88]
        if (c->v40(&B)) {
            FNV_Holder* I = this->unkAC;         // [ebp-0x8c]
            FNV_Target* L = I->unk0c;            // [ebp-0x90]
            L->unk08 = 2;
            return false;
        }
    }
    return true;
}

namespace fnv_00c49100 {
struct FUN_00aa42e0_holder;

extern unsigned char DAT_011f6238;

struct FUN_00aa42e0_holder
{
    void Store(int* arg);
};

}  // namespace fnv_00c49100

class NiPoint3 { public: float x,y,z; };

struct FUN_00c4a6e0_cls
{
    int unk00;
    bool ProcessEntries(struct CallerObj_b3918* a1, struct EntrySet_b3918* a2);
};

struct CallerObj_b3918
{
    int ClassifySphereAgainstPlane(void* p);
};

struct EntrySet_b3918
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
    unsigned int m_60;
};

namespace fnv_00c4a8b0 {
struct ParticleAllocator {
    void* Reallocate(void* memory, unsigned int bytes);
};
extern ParticleAllocator DAT_011f6238;

}  // namespace fnv_00c4a8b0

struct FUN_00c4a8e0
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual ~FUN_00c4a8e0();
};

// Destructor that calls ReleaseBuffer with argument 1 on this object.
// @fnv 0x00c4a8e0
FUN_00c4a8e0::~FUN_00c4a8e0()
{
    int unk04;
    ((FUN_00c4a9c0_class*)this)->ReleaseBuffer(1);
}

extern unsigned char DAT_012030a4;

// Candidate v2 for FUN_00c4edb0 (zai_04).
// Same guard logic; callee hypothesis: virtual __stdcall member taking one int,
// called as m_p->vfn(1). MSVC passes this as the first __stdcall stack argument
// (push 1 then push m_p), vtable slot 6 (+0x18), no ecx requirement at call.

extern unsigned char DAT_012030a4;

namespace fnv_00c503d0 {
struct FUN_00a5ecb0 {
 virtual void v0();
 ~FUN_00a5ecb0();
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
 FUN_00a5ecb0(unsigned int);
};
struct WorkerMemory { void* Allocate(unsigned int); };
extern WorkerMemory DAT_011f6238;
struct WorkerTask { unsigned int value; };
struct FUN_00c503d0 : FUN_00a5ecb0 {
    unsigned int* data;
    unsigned int count;
    WorkerTask* task;
    FUN_00c503d0();
};
}  // namespace fnv_00c503d0

extern "C" void __cdecl FUN_005b5e40(void*, int);

struct NiRTTI { const char* m_pcName; const NiRTTI* m_pBaseRTTI; };

void __cdecl FNV_Warning(const char* fmt, ...);

struct NiNodeStub;

struct NiAVObjectStub {
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNodeStub* IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual int IsParticleSystem();
    int unk04;
    const char* m_pcName;
};

struct NiNodeStub : NiAVObjectStub {
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
    NiAVObjectStub** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};

namespace fnv_00c515d0 {
struct FNVHeap {
    void FUN_00aa4060(void* allocation);
};
extern FNVHeap DAT_011f6238;
extern "C" void __cdecl FUN_00c516d0();
extern "C" void __stdcall FUN_00ec5fce(void* objects, unsigned int objectSize, unsigned int count, void (__cdecl *destructor)());

}  // namespace fnv_00c515d0

// Stand-in model of the destructor at 0x00c53fa0 (an /Od member function of a
// polymorphic class with a non-trivial base).
//
// The original is:
//   push ebp / mov ebp,esp / push -1 / push <eh handler> / mov eax,fs:[0] / push eax
//   sub esp,0x10 / <security cookie> / lea eax,[ebp-0xc] / mov fs:[0],eax
//   mov dword ptr [ebp-0x1c], ecx      ; the 'this' home
//   mov eax,dword ptr [ebp-0x1c]
//   mov dword ptr [eax], 0x10c2a94     ; the class' own vftable
//   mov dword ptr [ebp - 4], 0         ; EH state 0
//   mov ecx,dword ptr [ebp-0x1c] / add ecx,0xc / mov dword ptr [ebp-0x18],ecx
//   mov edx,dword ptr [ebp-0x18] / mov dword ptr [edx], 0x10c2b2c
//   mov eax,dword ptr [ebp-0x18] / mov ecx,dword ptr [eax+4]
//   mov dword ptr [ebp-0x14], ecx
//   mov edx,dword ptr [ebp-0x14] / mov dword ptr [ebp-0x10], edx
//   mov eax,dword ptr [ebp-0x10] / push eax
//   mov ecx, 0x11f6238 / call 0xaa4060   ; g_memoryManager.Deallocate(...)
//   mov dword ptr [ebp - 4], -1        ; EH state -1
//   mov ecx,dword ptr [ebp-0x1c] / call 0xa7b300   ; the base destructor

// Constructor: member routine that installs the class vtable pointer into
// the object, clears the flag member at +0x5c and then hands the object to
// the shared cleanup routine (FUN_00c1c300).
extern int DAT_010c2d54;

struct FUN_00c5c400 {
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
    unsigned int m_0x5c;
    unsigned int m_0x60;
    static void* __cdecl operator new(unsigned int size);
    FUN_00c5c400();
};

class BC5CBB0Object {
public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
};

struct EmitterObjectStub {
    void* m_ppVirtualMethodTable;
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
    EmitterObjectStub();
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
};

struct FUN_00c5d0a0_cls;
struct FUN_00c5d0a0_Vec4 { int x; int y; int z; int w; };
struct FUN_00c5d0a0_cls {
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
    FUN_00c5d0a0_Vec4 m_c4;
    void Helper(FUN_00c5d0a0_cls* other, int b);
    void CopyVec4AndHelper(FUN_00c5d0a0_cls* a1, int a2);
};

typedef void* HKEY_t;
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(HKEY_t hKey, const char* lpValueName, unsigned long Reserved,
                                         unsigned long dwType, const unsigned char* lpData, unsigned long cbData);
int __cdecl FUN_00c33090(int);
extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);

typedef struct HKEY__* HKEY;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(HKEY hKey, const char* lpValueName, DWORD* lpReserved, DWORD* lpType, BYTE* lpData, DWORD* lpcbData);

extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);

struct Setting {
    int unk00;
    int value;
    const char* name;
    unsigned int GetFormatSize();
    Setting& FUN_00c33170(const char* str);
};

extern int g_01203340;

struct FUN_00c5e010_Node {
    virtual void vf00();
    virtual void vf04();
    virtual int vf08();

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
    FUN_00c5e010_Node* next;
};

// @fnv 0x00c5e010
inline void FUN_00c5e010_Node::vf00() {}
inline void FUN_00c5e010_Node::vf04() {}
inline int FUN_00c5e010_Node::vf08() { return 0; }

struct FUN_007530a0 {
    virtual ~FUN_007530a0() {}
};

struct FUN_00a7b300 {
    virtual ~FUN_00a7b300() {}
};

struct BSShaderAccumulator {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    static void* __cdecl operator new(unsigned int size);
    BSShaderAccumulator();
};

void __cdecl FUN_00a26df0(int a, int* out);

class NiMemObject {
public:
    static void* __cdecl operator new(unsigned int size);
};

extern "C" char DAT_011f6238;

extern void* DAT_010c32c4;

void* __cdecl FUN_00aa13e0(unsigned int);
struct PositionModifierInstance {
    FUN_00c5fd30 modifier;
    void* name;
    unsigned int order;
    void* target;
    bool active;
    float lastTime;
    void* next;
    static __forceinline void* operator new(unsigned int amount) {
        return FUN_00aa13e0(amount);
    }
};

struct MyStream;
void FUN_00a26df0(MyStream* stream, void* value);

namespace fnv_00c41610 {
#include <windows.h>


}  // namespace fnv_00c41610

char* __cdecl FUN_00a7d370(const char* name, bool value);

class BC45120CloningProcess;

class BC45120Object {
public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BC45120Object();
    virtual ~BC45120Object();

    void CopyMemberData(BC45120Object* pkDest, BC45120CloningProcess& kCloning);
    BC45120Object* Clone(BC45120CloningProcess& kCloning);

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
};

struct Entry { int type; int a; int b; };
struct Target {
 int unk00, unk04, unk08, unk0c, unk10, unk14;
 Entry* data;
 int unk1c, unk20, unk24;
 int count;
 void CompactEntries();
};

namespace fnv_00c5e350 {
struct Target {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4;
    unsigned short count_b8, unkba;
    int unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8;
    float elapsed_dc;
    void FUN_00c5e080();
    unsigned char FUN_00c5eb90();
    void FUN_00a5dd70(float* time, int arg);
    void UpdateTimed(float* time, int arg);
};
}  // namespace fnv_00c5e350

// Refresh every key whose time lags the given time by more than the controller's threshold.

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* dest, long exchange, long comparand);

struct RefObj {
    int unk00;
    int unk04;
    volatile long m_iObjectReferenceCount;
};

struct RefPtr {
    RefObj* m_pObject;
};

struct NodeKey {
    int a;
    int b;
};

struct NodeFlags {
    unsigned int m_uiValue1;
};

struct Node {
    NodeKey m_key;
    RefPtr m_pReferencedObject;
    NodeFlags m_flags;
};

struct C45440_Obj : FUN_00c450d0 {
    int u64;
    int u68;
    int u6C;
    int u70;
    int u74;
    int u78;
    int u7C;
    int u80;
    int u84;
    int u88;
    int u8C;
    int u90;
    int u94;
    int u98;
    int u9C;
    int uA0;
    int uA4;
    int uA8;
    int uAC;
    static void* __cdecl operator new(unsigned int size);
};

struct BSFaceGenMorphData { static void* operator new(unsigned int); static void operator delete(void*); };
namespace c30 {
struct FUN_00c5fd30 : BSFaceGenMorphData { FUN_00c5fd30(); int m[7]; };
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);

struct FUN_00c47b50Vec3;

struct FUN_00c47b50Transform { float v0; float v1; float v2; float v3; float v4; float v5; };

struct FUN_00c47b50Vec3 {

    float x; float y; float z;

    void FUN_00a699d0(FUN_00c47b50Vec3*, FUN_00c47b50Vec3*, FUN_00c47b50Transform*);

    float DotProduct(FUN_00c47b50Vec3*);

};

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

// FUN_00c43d00: builds the INISettings list snapshot ("INISettings" name + AddFirstEmpty,
// then count via TESActorBaseData_SetKarma and "Total INISettings" message + AddFirstEmpty).
// SinkSave is a stand-in for the TU's local aggregate frame reservation.

extern "C" __declspec(dllimport) int __stdcall WritePrivateProfileStringA(const char*, const char*, const char*, const char*);

char* __cdecl FUN_00a7d370(const char* s, bool v);

struct StrArr;

char* __cdecl FUN_00a7d330(char const* name);

struct GraphHeap {
    void* Allocate(unsigned int, unsigned int);
    void Deallocate(void*);
};
struct GraphMemory { GraphHeap* FUN_00aa42e0(); };
extern GraphMemory _g_memoryManager;
void __cdecl FUN_005b5e40(const char*);

extern int DAT_010c1e88;

extern int DAT_010c1e88;

class FUN_00c511f0_cls {
public:
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};

bool FUN_00c50f90(FUN_00c511f0_cls* a, FUN_00c511f0_cls* b);

// 0x00c52020  1072 bytes  /MT /Od /Oy- /GS /EHsc /Gy   -- byte-identical reconstruction
// thiscall (ret 0x10): (float fov, unsigned char flag, C52020Obj* obj, unsigned char arg4)
// called from 0xc51d67 as FUN_00c52020(*pSetting, 1, 0, 0).
//
// Frame 0xcc + push esi.  Named band -0x04..-0x88 (bucket-sorted: descending name-hash
// bucket, ties by reverse declaration order), expression temps -0x8c..-0xcc in code order.
// Slot roles are annotated on the declarations below; aFlag is the 0x18-byte hole at
// -0x6c that nothing ever reads, and the two setting divides use a two-member record
// read because only a "computed" right operand makes MSVC9 /Od emit
// `mov edx,[p] / fld [edx] / fdivr [ebp+8]` instead of the mirrored
// `fld [ebp+8] / mov edx,[p] / fdiv [edx]`.
struct C52020Dev;

struct NiFrustum {
    NiFrustum(bool);
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};

struct NiUpdateData {
    float m_fTime;
    bool m_b0;
    bool m_b1;
    bool m_b2;
    bool m_b3;
    bool m_b4;
};

struct C52020Res {
    char pad0[8];
    unsigned int m_08;
    unsigned int m_0c;
};

struct C52020Obj;

struct C52020Dev {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual C52020Res* vfn_b0(int);
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual C52020Dev* vfn_c8();
    virtual C52020Dev* vfn_cc();
    unsigned int FUN_004dee70();
    unsigned int FUN_004dee10();
};

struct C52020Obj {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual float vfn_100();
    char pad0[0xa8];
    C52020Obj* m_ac;
    char pad1[8];
    unsigned char m_b8;
    char pad2[3];
    float m_bc;
    char pad3[0x3c];
    float m_fc;
    float m_100;
    float m_104;
    float m_108;
    float m_10c;
    float m_110;
    void FUN_00a6faf0(NiFrustum* apFrustum);
    void Update(const NiUpdateData& kData);
    void FUN_00c52020(float m_fFirstFloat, unsigned char ucFlag, C52020Obj* pObj, unsigned char ucArg4);
};

extern "C" void* g_012031e8;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern void* DAT_01203328;

typedef NiTListItem<NiPointer<NiProperty> > SpawnNode;
typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> > SpawnList;

struct SpawnedObject {
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
    SpawnList m_50;
    SpawnList m_5c;
    void FUN_00c5b5f0(void* value);
    void FUN_00c5b740(void* value);
    void FUN_00c5b8d0();
};

struct LoopPadA { unsigned int a; unsigned int b; unsigned int c; unsigned int d; };
struct LoopPadB { unsigned int a; unsigned int b; unsigned int c; unsigned int d; unsigned int e; unsigned int f; unsigned int g; };

// Under a critical section, calls FUN_00c5b5f0 on each element of m_50 and FUN_00c5b740 on each of m_5c, removing all entries from each list afterward.
// @fnv 0x00c5b8d0
void SpawnedObject::FUN_00c5b8d0()
{
    EnterCriticalSection(&DAT_01203328);
    void* value;
    SpawnNode* node;
    {
        SpawnNode* head = m_50.m_pkHead;
        node = head;
        value = 0;
        while (node != 0) {
            NiPointer<NiProperty>* ref = &node->m_element;
            LoopPadA tmp;
            node = node->m_pkNext;
            value = ref->m_pObject;
            if (value != 0) {
                FUN_00c5b5f0(value);
            }
        }
    }
    m_50.RemoveAll();
    {
        SpawnNode* head = m_5c.m_pkHead;
        node = head;
        value = 0;
        while (node != 0) {
            NiPointer<NiProperty>* ref = &node->m_element;
            LoopPadB tmp;
            node = node->m_pkNext;
            value = ref->m_pObject;
            if (value != 0) {
                FUN_00c5b740(value);
            }
        }
    }
    m_5c.RemoveAll();
    LeaveCriticalSection(&DAT_01203328);
}

struct NiPoint3;
enum NiGeometryDataFlags { NI_GEOM_DATA_DEFAULT = 0 };

namespace fnv_00c4b500 {
#include <windows.h>

struct Node;
struct NodeV { void* v0; void* v1; void* v2; Node* (__thiscall *GetNode)(Node*); };
struct Node {
    NodeV* vt;
    char unk04[0x2C];
    unsigned int flags;
    char unk34[0x6C];
    Node** children;
    char unkA4[2];
    unsigned short count;
};
}  // namespace fnv_00c4b500

// for each of one listed worker, release its semaphore and bump its counter.
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount, long* lpPreviousCount);

extern "C" __declspec(dllimport) void __stdcall DebugBreak();

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(HKEY);

extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void*);

extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(
    HKEY, const char*, DWORD, char*, DWORD, DWORD, void*, HKEY*, DWORD*);
extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(
    HKEY, const char*, DWORD, DWORD, HKEY*);
