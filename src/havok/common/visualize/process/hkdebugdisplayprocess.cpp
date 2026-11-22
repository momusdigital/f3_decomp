#include "f3_common.h"
// src/havok/common/visualize/process/hkdebugdisplayprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/process/hkdebugdisplayprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern volatile int DAT_01269cdc;
struct Target
{
    void* volatile vptr;
};
typedef void(__thiscall* VirtualTarget)(Target*, int, int, int, int, int);

struct Owner
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void forward(unsigned int, unsigned int, unsigned int, float, float, float, unsigned int);
};
struct Interface
{
    void ForwardToOwner(unsigned int, unsigned int, unsigned int, float, float, float, unsigned int);
};
// Retrieves the Owner pointer stored 8 bytes before this Interface and forwards all seven arguments to its forward method.
// @fnv 0x00ddc9c0
// pdb: hkDebugDisplayProcess::updateCamera | hkDebugDisplayProcess.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: from, to, up, nearPlane, farPlane, fov, name
void Interface::ForwardToOwner(unsigned int a, unsigned int b, unsigned int c, float d, float e, float f,
                               unsigned int g)
{
    Owner* owner = *(Owner**)((char*)this - 8);
    owner->forward(a, b, c, d, e, f, g);
}

namespace fnv_00ddca90 {
struct Target
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual int invoke(int, int, int, int, int);
};
}  // namespace fnv_00ddca90

extern char DAT_010d7ed0;
extern char DAT_010d7eb0;
extern char DAT_010d7e5c;
extern char DAT_010d7cfc;
extern char DAT_010d1508;
class ProcessManager
{
  public:
    void RemoveListener(void* process);
};
extern ProcessManager* DAT_012681e0;
class Process
{
  public:
    void* vftable;
    int unk04;
    void* baseVftable;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* listenerVftable;
    void FUN_00ddcb50();
};
// @f3 0x00a64750 (community match, verified in this file)
extern char DAT_00e86e68;
extern char DAT_00e86e48;
extern char DAT_00e86dfc;
extern char FUN_00e86cac;
extern char FUN_00e808e0;
extern char FUN_00dcc494;
extern ProcessManager* DAT_010f323c;

// pdb: hkDebugDisplayProcess::~hkDebugDisplayProcess | hkDebugDisplayProcess.obj | fnv360_0822_retail, call_seq, medium
void Process::FUN_00ddcb50()
{
    vftable = &DAT_00e86e68;
    baseVftable = &DAT_00e86e48;
    listenerVftable = &DAT_00e86dfc;
    DAT_010f323c->RemoveListener(&listenerVftable);
    *(void* volatile*)&listenerVftable = &FUN_00e86cac;
    *(void* volatile*)&baseVftable = &FUN_00e808e0;
    *(void* volatile*)&vftable = &FUN_00dcc494;
}


struct S_00ddcb90_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};

struct S_00ddcb90_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddcb90_Allocator* m_pStreamAllocator;
    S_00ddcb90_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00ddcb90_Router* FUN_00c85750();

struct S_00ddcb90_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00ddcb90_RefObj() throw()
    {}
    void* operator new(unsigned int nbytes)
    {
        S_00ddcb90_RefObj* b = static_cast<S_00ddcb90_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*)
    {}
};

namespace fnv_00ddcbe0 {
extern int DAT_01269cdc;
// @fnv 0x00ddcbe0
// pdb: hkpPhantomDisplayViewer::getProcessTag | hkpPhantomDisplayViewer.obj | fnv360_0822_retail, vtable, medium
int FUN_00ddcbe0()
{
    return DAT_01269cdc;
}
}  // namespace fnv_00ddcbe0

namespace fnv_00ddcc10 {
struct Process;
struct Allocator
{
    virtual void First();
    virtual void Second();
    virtual void Release(Process*, unsigned short);
};
struct ProcessServices
{
    int a, b, c, d;
    Allocator* allocator;
};
ProcessServices* __cdecl FUN_00c85750();
struct Process
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    void FUN_00ddcb50();
    Process* FUN_00ddcc10(unsigned char flags);
};
}  // namespace fnv_00ddcc10

extern unsigned int g_01269cdc;

struct TargetIface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int vslot3(int a, int b, unsigned int c);
};

struct OwnerHolder
{
    TargetIface* m_target;
    unsigned int unk04;
};

class S_00ddc960_cls
{
  public:
    int ForwardToTarget(int a, int b, unsigned int c);
    unsigned int unk00;
    unsigned int unk04;
};

// @fnv 0x00ddc960
// pdb: hkDebugDisplayProcess::setGeometryColor | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: color, id, tag
int S_00ddc960_cls::ForwardToTarget(int aiArg1, int aiArg2, unsigned int c)
{
    OwnerHolder* h = (OwnerHolder*)((char*)this - 8);
    return h->m_target->vslot3(aiArg1, aiArg2, g_01269cdc);
}

// ForwardToDelegate - a forwarding member of a secondary base.
//
// The original code is exactly:
//     00ddca50  8b 49 f8           mov ecx, dword ptr [ecx - 8]
//     00ddca53  8b 01              mov eax, dword ptr [ecx]
//     00ddca55  8b 15 dc 9c 26 01  mov edx, dword ptr [0x1269cdc]
//     00ddca5b  89 54 24 18        mov dword ptr [esp + 18h], edx
//     00ddca5f  8b 40 28           mov eax, dword ptr [eax + 28h]
//     00ddca62  ff e0              jmp eax
//
// so the member is
//     Sink* ForwardToDelegate(int, int, int, int, int, int)
// and it does nothing but forward its arguments to the eleventh virtual of
// the delegate object, with the last argument replaced by the value of the
// global at 0x1269cdc:
//
//   * [ecx-8] is the delegate pointer, which lives in the primary base of
//     the object; this member belongs to a *secondary* base, so its 'this'
//     pointer points eight bytes past the start of the object;
//   * the delegate's first word is its vtable pointer and the target is
//     the virtual in slot 0x28 (the eleventh one);
//   * the value of the global is written into the outgoing sixth argument
//     slot and the call is then a tail call (jmp), so the callee sees the
//     global instead of the original sixth argument.
//
// The forwarder returns what the delegate returns, which is what makes the
// call a tail jump.

// The global the sixth argument is replaced with (uninitialised, so it
// lives in .bss just like the original one at 0x1269cdc).
int g_1269cdc;

// FUN_00ddcad0: thiscall forwarder. The owner pointer lives 8 bytes before this;
// the single stack argument is forwarded to the owner's vtable slot 0x40 via a tail jump.

struct S_00ddc8e0_Owner
{
    virtual void v0();
    virtual int v1(int a, int b, int c, int d);
};
struct S_00ddc8e0_Cls
{
    int unk00;
    int unk04;
    int ForwardToOwnerVirtual(int a, int b, int c, int d);
};
// @fnv 0x00ddc8e0
// pdb: hkDebugDisplayProcess::addGeometry | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: geometries, transform, id, tag, shapeIdHint
int S_00ddc8e0_Cls::ForwardToOwnerVirtual(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    S_00ddc8e0_Owner* pOwner = *(S_00ddc8e0_Owner**)((char*)this - 8);
    return pOwner->v1(aiArg1, aiArg2, aiArg3, DAT_01269cdc);
}

struct SinkDDCA
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual SinkDDCA* f8(int, int, int, int);
};

struct ForwarderDDCA;

struct ForwarderBaseDDCA
{
    SinkDDCA* m_delegate;
    int unk04;
};

struct ForwarderInterfaceDDCA
{
    SinkDDCA* FUN_00ddca10(int a, int b, int c, int d);
};

struct ForwarderDDCA : public ForwarderBaseDDCA, public ForwarderInterfaceDDCA
{
};

// @fnv 0x00ddca10
// pdb: hkDebugDisplayProcess::displayLine | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: start, end, color, id, tag
SinkDDCA* ForwarderInterfaceDDCA::FUN_00ddca10(int aArg1, int aArg2, int aArg3, int aArg4)
{
    SinkDDCA* pkDelegate =
        reinterpret_cast<ForwarderBaseDDCA*>(reinterpret_cast<char*>(this) - sizeof(ForwarderBaseDDCA))->m_delegate;
    return pkDelegate->f8(aArg1, aArg2, aArg3, DAT_01269cdc);
}

// FUN_00ddcbf0: MSVC adjustor thunk for a secondary base at offset 0x20.
// Derived overrides a virtual that both bases declare; the second base's vtable slot
// is a thunk that moves `this` back by sizeof(PrimaryBase) and jumps to the override.

struct PrimaryBase
{
    virtual void FUN_00ddcbf0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct SecondaryBase
{
    virtual void FUN_00ddcbf0();
};

struct SpawnedObject : PrimaryBase, SecondaryBase
{
    SpawnedObject();
// @fnv 0x00ddcbf0
    virtual void FUN_00ddcbf0();
};

SpawnedObject::SpawnedObject()
{}

namespace fnv_00ddcc00 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00ddcc00();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00ddcc00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ddcc00
    virtual void FUN_00ddcc00();
};

Derived::Derived()
{}
}  // namespace fnv_00ddcc00

namespace fnv_00ddc900 {
extern unsigned int DAT_01269cdc;

class FNVTarget
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08(int a, int b, int c, unsigned int d);
};

struct FNVHolder
{
    FNVTarget* m_target;
};

class FUN_00ddc900_cls
{
  public:
    void FUN_00ddc900(int a, int b, int c, unsigned int d);
};

// @fnv 0x00ddc900
// pdb: hkDebugDisplayProcess::addGeometryInstance | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: instID, transform, id, tag, shapeIdHint
void FUN_00ddc900_cls::FUN_00ddc900(int a, int b, int c, unsigned int d)
{
    FNVHolder* h = (FNVHolder*)((char*)this - 8);
    FNVTarget* t = h->m_target;
    void* vp = *(void**)t;
    unsigned int dat = DAT_01269cdc;
    *(unsigned int volatile*)&d = dat;
    typedef void(__thiscall * SlotFn)(FNVTarget*, int, int, int, unsigned int);
    SlotFn fn = (SlotFn) * (void* volatile*)((char*)vp + 0x8);
    fn(t, a, b, c, d);
}
}  // namespace fnv_00ddc900

namespace fnv_00ddc940 {
extern unsigned int DAT_01269cdc;

class FNVTarget
{
  public:
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
    virtual void v38(int a, int b, int c, unsigned int d);
};

struct FNVHolder
{
    FNVTarget* m_target;
};

}  // namespace fnv_00ddc940

namespace fnv_00ddc980 {
extern unsigned int DAT_01269cdc;

class FNVTarget
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(int a, int b, int c);
};

struct FNVHolder
{
    FNVTarget* m_target;
};

class FUN_00ddc980_cls
{
  public:
    void FUN_00ddc980(int a, int b, int c);
};

// @fnv 0x00ddc980
// pdb: hkDebugDisplayProcess::updateGeometry | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: transform, id, tag
void FUN_00ddc980_cls::FUN_00ddc980(int aArg1, int aArg2, int aArg3)
{
    FNVHolder* h = (FNVHolder*)((char*)this - 8);
    FNVTarget* t = h->m_target;
    void* vp = *(void**)t;
    unsigned int dat = DAT_01269cdc;
    *(unsigned int volatile*)&aArg3 = dat;
    typedef void(__thiscall * SlotFn)(FNVTarget*, int, int, int);
    SlotFn fn = (SlotFn) * (void* volatile*)((char*)vp + 0x10);
    fn(t, aArg1, aArg2, aArg3);
}
}  // namespace fnv_00ddc980

namespace fnv_00ddc9a0 {
extern unsigned int DAT_01269cdc;
class FNVTarget
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14(int a, unsigned int b);
};
class FUN_00ddc9a0_cls
{
  public:
    void FUN_00ddc9a0(int a, unsigned int b);
};
// @fnv 0x00ddc9a0
// pdb: hkDebugDisplayProcess::removeGeometry | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: id, tag, shapeIdHint
void FUN_00ddc9a0_cls::FUN_00ddc9a0(int aiArg, unsigned int auiParam)
{
    FNVTarget* t = *(FNVTarget**)((char*)this - 8);
    void** pVTable = *(void***)t;
    *(volatile unsigned int*)&auiParam = DAT_01269cdc;
    void* volatile* slot = (void* volatile*)&pVTable[5];
    ((void(__thiscall*)(FNVTarget*, int, unsigned int)) * slot)(t, aiArg, auiParam);
}
}  // namespace fnv_00ddc9a0

namespace fnv_00ddca30 {
// Thiscall container-of forwarder: the holder pointer lives at this-8, the global
// DAT_01269cdc is written over the 5th stack argument, and the call is tail-jumped
// through vtable slot +0x24 of the target object.
extern unsigned int DAT_01269cdc;

class FNVTarget
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24(int a, int b, int c, int d, unsigned int e);
};

struct FNVHolder
{
    FNVTarget* m_target;
};

class FUN_00ddca30_cls
{
  public:
    void FUN_00ddca30(int a, int b, int c, int d, unsigned int e);
};

// @fnv 0x00ddca30
// pdb: hkDebugDisplayProcess::displayTriangle | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: a, b, c, color, id, tag
void FUN_00ddca30_cls::FUN_00ddca30(int aiArg1, int aiArg2, int aiArg3, int aiArg4, unsigned int auArg5)
{
    FNVHolder* h = (FNVHolder*)((char*)this - 8);
    FNVTarget* t = h->m_target;
    void* vp = *(void**)t;
    unsigned int dat = DAT_01269cdc;
    *(unsigned int volatile*)&auArg5 = dat;
    typedef void(__thiscall * SlotFn)(FNVTarget*, int, int, int, int, unsigned int);
    SlotFn fn = (SlotFn) * (void* volatile*)((char*)vp + 0x24);
    fn(t, aiArg1, aiArg2, aiArg3, aiArg4, auArg5);
}
}  // namespace fnv_00ddca30

namespace fnv_00ddcaf0 {
extern char DAT_010d1508[];
extern char DAT_010d7cfc[];
extern char DAT_010d7ed0[];
extern char DAT_010d7eb0[];
extern char DAT_010d7e5c[];
extern char DAT_01269cdc[];
extern char DAT_012681e0[];

class GlobalDispatcher
{
  public:
    void Dispatch(void* arg);
};

class FUN_00ddcaf0_cls
{
  public:
    void* m_vtbl;
    unsigned char unk04[2];
    unsigned short m_06;
    void* m_08;
    unsigned char m_0c;
    unsigned char unk0d[0x13];
    void* m_20;

    void Helper();
    FUN_00ddcaf0_cls* FUN_00ddcaf0();
};

// Initializes m_06, m_0c, m_08, m_20, and m_vtbl, calls Helper if DAT_01269cdc is zero, then dispatches m_20 via GlobalDispatcher.
// @fnv 0x00ddcaf0
// pdb: hkDebugDisplayProcess::hkDebugDisplayProcess | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_prop, medium
FUN_00ddcaf0_cls* FUN_00ddcaf0_cls::FUN_00ddcaf0()
{
    unsigned char flag = 1;
    m_06 = 1;
    unsigned char* pFlag = (unsigned char*)&m_0c;
    *(void* volatile*)&m_08 = DAT_010d1508;
    *(volatile unsigned char*)pFlag = flag;
    *(void* volatile*)&m_20 = DAT_010d7cfc;
    m_vtbl = DAT_010d7ed0;
    m_08 = DAT_010d7eb0;
    *(void* volatile*)&m_20 = DAT_010d7e5c;
    if (*(int*)DAT_01269cdc == 0)
    {
        Helper();
    }
    ((GlobalDispatcher*)*(void**)DAT_012681e0)->Dispatch(&m_20);
    return this;
}
}  // namespace fnv_00ddcaf0

namespace fnv_00ddcbc0 {

extern "C" void* DAT_01269cdc;

}  // namespace fnv_00ddcbc0

template <class T> class HavokElementArray;

struct TextReceiver : TargetIface
{
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual int displayText(const char* text, int color, int id, int tag);
};

struct TextEntry
{
    void* vftable;
    int FUN_00ddca70(const char* text, int color, int id, int tag);
};

struct TextForwarder : OwnerHolder, TextEntry
{
};

// @fnv 0x00ddca70
// pdb: hkDebugDisplayProcess::display3dText | hkDebugDisplayProcess.obj | fnv360_0822_retail, objrun_open, low
// pdb params: text, pos, color, id, tag
int TextEntry::FUN_00ddca70(const char* text, int color, int id, int tag)
{
    __assume(this != 0);
    TextForwarder& owner = static_cast<TextForwarder&>(*this);
    TextReceiver* receiver = static_cast<TextReceiver*>(owner.m_target);
    return receiver->displayText(text, color, id, g_01269cdc);
}
