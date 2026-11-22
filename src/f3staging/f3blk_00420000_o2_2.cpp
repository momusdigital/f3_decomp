#include <windows.h>
#include <new>
#include <new>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_00420000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004247a0 (community match, verified in this file)
namespace f3m_004247a0 {


struct TaskSemaphore
{
    volatile long count;
    HANDLE handle;
    void Signal()
    {
        if (!count)
        {
            ReleaseSemaphore(handle, 1, 0);
            InterlockedIncrement(&count);
        }
    }
    void Wait()
    {
        WaitForSingleObject(handle, INFINITE);
        InterlockedDecrement(&count);
    }
};
struct TaskBarrier
{
    int unk00;
    int unk04;
    DWORD ownerThread;
    TaskSemaphore requested;
    int unk14;
    TaskSemaphore completed;
};
struct TaskSingleton
{
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24;
    TaskBarrier* barrier;
};
extern TaskSingleton* DAT_0106ca70;

// pdb: ModelLoader::PauseCallback | ModelLoader.obj | fnv360_0822_retail, objrun, medium
void FUN_004247a0()
{
    TaskBarrier* barrier = DAT_0106ca70->barrier;
    DWORD owner = barrier->ownerThread;
    if (owner != GetCurrentThreadId())
    {
        barrier->requested.Signal();
        barrier->completed.Wait();
    }
}
}   // namespace f3m_004247a0

// @f3 0x0042c010 (community match, verified in this file)
#include <windows.h>
namespace f3m_0042c010 {

class HelmetPartData
{
  public:
    virtual ~HelmetPartData();
    unsigned int unk04;
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((LONG*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((LONG*)&m_uiRefCount))
            delete this;
    }
};

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((LONG*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((LONG*)&m_uiRefCount))
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};

class HelmetActorData
{
  public:
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
};

class QueuedHelmetBase
{
  public:
    QueuedHelmetBase(void* owner);
    virtual ~QueuedHelmetBase();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
};

class QueuedHelmet : public QueuedHelmetBase
{
  public:
    QueuedHelmet(HelmetActorData* actor, void* owner, unsigned int unused);
    virtual ~QueuedHelmet();
    HelmetActorData* m_actor;
    NiPointer<HelmetPartData> m_parts[20];
    NiPointer<NiRefObject> m_nodesA[20];
    NiPointer<NiRefObject> m_nodesB[20];
    unsigned int unk11C;
    bool unk120;
};

// pdb: QueuedHelmet::QueuedHelmet | ModelLoader.obj | fnv360_0822_retail, uvref, medium
// pdb params: apBipedAnim, aePriority, aeBipedObject
QueuedHelmet::QueuedHelmet(HelmetActorData* actor, void* owner, unsigned int unused)
    : QueuedHelmetBase(owner), m_actor(actor)
{
    unk120 = false;
    unk11C = m_actor->unk2B0;
}
}   // namespace f3m_0042c010

// @f3 0x004260d0 (community match, verified in this file)
#include <windows.h>
namespace f3m_004260d0 {

class FUN_004260d0_Class {
public:
    void __thiscall FUN_004260d0();
    void __thiscall FUN_00aa53c0();
};

void FUN_004260d0_Class::FUN_004260d0() {
    LONG** ppTarget = *(LONG***)((char*)this + 0x30);

    if (ppTarget != NULL) {
        InterlockedDecrement((volatile LONG*)(ppTarget + 3));
    }

    this->FUN_00aa53c0();
}
}   // namespace f3m_004260d0

// @f3 0x00429340 (community match, verified in this file)
namespace f3m_00429340 {


class MemoryManager9340
{
  public:
    void* Allocate(unsigned int size);
    void Deallocate(void* mem);
};
extern MemoryManager9340 g_memoryManager9340;

class QueuedFileBase9340
{
  public:
    QueuedFileBase9340(void* owner);
    virtual ~QueuedFileBase9340();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Run();

    static void* operator new(unsigned int size)
    {
        return g_memoryManager9340.Allocate(size);
    }
    static void operator delete(void* mem)
    {
        g_memoryManager9340.Deallocate(mem);
    }

    void IncRefCount()
    {
        InterlockedIncrement((LONG*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((LONG*)&m_uiRefCount))
            delete this;
    }

    unsigned int unk04;
    unsigned int m_uiRefCount;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
};

class QueuedMagicItem : public QueuedFileBase9340
{
  public:
    QueuedMagicItem(void* item, void* target, void* owner)
        : QueuedFileBase9340(owner), m_item(item), m_target(target)
    {
    }
    virtual ~QueuedMagicItem();
    void* m_item;
    void* m_target;
};

// pdb: ModelLoader::QueueMagicItem | ModelLoader.obj | fnv360_0822_retail, uvref, low
// pdb params: apMagicItem, apAVEffectSetting, aePriority
void __stdcall FUN_00429340(void* item, void* target, void* owner)
{
    if (item && target) {
        NiPointer<QueuedMagicItem> task = new QueuedMagicItem(item, target, owner);
        task->Run();
    }
}
}   // namespace f3m_00429340

// @f3 0x00434130 (community match, verified in this file)
namespace f3m_00434130 {
struct FUN_00434130_Arg
{
    int unk00;
    unsigned char unk04;
};

// pdb: TESObjectWEAP::GetProjectile | TESObjectWEAP.obj | fnv360_0822_debug, call_gap, low, conflict (bridge: TES::GetLODMult)
// pdb params: apWeaponHolder
int __cdecl FUN_00434130(FUN_00434130_Arg* arg)
{
    switch (arg->unk04)
    {
    case 42:
    case 43:
        return 3;
    case 24:
    case 25:
    case 26:
    case 29:
    case 31:
    case 40:
    case 41:
    case 46:
    case 47:
    case 50:
        return 2;
    default:
        return 1;
    }
}
}   // namespace f3m_00434130

// @f3 0x004225a0 (community match, verified in this file)
#include <new>
extern float DAT_0108cba0;
extern const float DAT_00f5e548;
namespace f3m_004225a0 {


namespace f3m_004225a0 {

struct Sample {
    float time;
    Sample() : time(0.0f) {}
    Sample(float t) : time(t) {}
};

class SampleArray {
public:
    int unk00;
    Sample* data;
    int size;
    int FUN_005e5350();

    void Add(const Sample& sample)
    {
        int index = FUN_005e5350();
        new (&data[index]) Sample();
        data[index] = sample;
    }
};

class Sampler {
public:
    int unk00; int unk04; int unk08;
    SampleArray samples;

    void FUN_00421010();
    void FUN_004225a0();
};

}

using namespace f3m_004225a0;

// pdb: ExtraFriendHits::AddHit | ExtraDataObjects.obj | fnv360_0721_beta, call_seq, medium
void Sampler::FUN_004225a0()
{
    FUN_00421010();
    if (samples.size > 0) {
        Sample last = samples.data[samples.size - 1];
        float elapsed = DAT_0108cba0 - last.time;
        if (elapsed < DAT_00f5e548)
            return;
    }
    samples.Add(Sample(DAT_0108cba0));
}
}   // namespace f3m_004225a0

// @f3 0x0042eff0 (community match, verified in this file)
#include <string>
namespace f3m_0042eff0 {

struct StringAssignFO3 : std::string {
    StringAssignFO3& FUN_0042eff0(const StringAssignFO3& right, size_type offset, size_type count);
};

// pdb: std::basic_string<char,std::char_traits<char>,std::allocator<char> >::assign | TESObject.obj | fnv360_0721_retail, call_seq, low
// pdb params: _Right, _Roff, _Count
StringAssignFO3& StringAssignFO3::FUN_0042eff0(const StringAssignFO3& right, size_type offset, size_type count)
{
    if (right.size() < offset)
        std::_String_base::_Xran();
    size_type number = right.size() - offset;
    if (count < number)
        number = count;
    if (this == &right)
        erase(offset + number), erase(0, offset);
    else if (_Grow(number))
    {
        std::_Traits_helper::copy_s<std::char_traits<char> >(_Myptr(), _Myres, right._Myptr() + offset, number);
        _Eos(number);
    }
    return *this;
}
}   // namespace f3m_0042eff0

// @f3 0x00431220 (community match, verified in this file)
#include <exception>
#include <string>
namespace f3m_00431220 {

class LogicErrorCopy : public std::exception
{
public:
    LogicErrorCopy(const LogicErrorCopy& other);
    virtual ~LogicErrorCopy() throw() {}
    virtual const char* what() const throw() { return message.c_str(); }
private:
    std::string message;
};

// pdb: std::logic_error::logic_error | FanFgFile.obj | tesv_win, caller_sim, low
LogicErrorCopy::LogicErrorCopy(const LogicErrorCopy& other)
    : std::exception(other), message(other.message)
{
}

}   // namespace f3m_00431220

// @f3 0x00424af0 (community match, verified in this file)
namespace f3m_00424af0 {

namespace task1450 {
struct Heap {void* FUN_0086b930(unsigned int);};
extern Heap DAT_01090a78;
// pdb: std::allocator<float>::allocate | TESNPC.obj | fnv360_0822_retail, call_seq, medium
// pdb params: _Count
void* FUN_00424af0(unsigned int count){
 if(count<=0){count=0;}
 else if((unsigned int)-1/count<4){const char* msg=0;throw std::bad_alloc(msg);}
 return DAT_01090a78.FUN_0086b930(count*4);
}
}
}   // namespace f3m_00424af0

// @f3 0x0042b280 (community match, verified in this file)
namespace f3m_0042b280 {

struct HeapX { void* alloc(unsigned); };
extern HeapX heap_x;
extern __declspec(thread) int tls_x;
struct Guard {
    int old;
    Guard() : old(tls_x) { tls_x = 6; }
    ~Guard() { tls_x = old; }
};
struct FUN_0059acc0 {
    int value;
    FUN_0059acc0();
    static void* operator new[](unsigned n) { return heap_x.alloc(n); }
};
struct Extra {
    int a, b, c, d;
    Extra(unsigned);
    static void* operator new(unsigned n) { return heap_x.alloc(n); }
};
struct Word {
    int a;
    static void* operator new[](unsigned n) { return heap_x.alloc(n); }
};
struct Base { virtual ~Base(); };
struct Owner : Base {
    virtual ~Owner();
    void* data;
    unsigned count;
    FUN_0059acc0* items;
    int value;
    Extra* extra;
    int zero;
    Owner(unsigned, unsigned, int);
};
// pdb: LockFreeMap<char const *,Model *>::LockFreeMap<char const *,Model *> | ModelLoader.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiMaxThreads, aiNumBuckets, aiDeleteBatchSize
Owner::Owner(unsigned n, unsigned m, int v) {
    Guard guard;
    zero = 0;
    count = m;
    items = new FUN_0059acc0[m];
    data = new Word[n * 3];
    value = v;
    extra = new Extra(n);
}
}   // namespace f3m_0042b280



// @f3 0x004274a0 (community match, verified in this file)
namespace f3m_004274a0 {
namespace f3m_004274a0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct Obj {
    virtual ~Obj();
    long unk04;
    volatile long refs;
    void DecRef(){if(InterlockedDecrement(&refs)==0)delete this;}
};
struct C {
    Obj* m;
    void FUN_004274a0();
};
// pdb: std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >::_Myptr | BipedAnim.obj | tesv_win, objrun_open, low
void C::FUN_004274a0()
{
    if(m)m->DecRef();
}
}
}   // namespace f3m_004274a0

// @f3 0x0043ac20 (community match, verified in this file)
namespace f3m_0043ac20 {
extern const char DAT_00db8e9c[];
extern const char DAT_00db8ea0[];
extern const char DAT_00db8d80[];
extern const char DAT_00db8da8[];
extern const char DAT_00db8e04[];
extern const char DAT_00db8ea8[];
extern const char DAT_00db8ee0[];
extern const char DAT_00db8f24[];
extern const char DAT_00db8f30[];
extern const char DAT_00db8f78[];
extern const char DAT_00db8e30[];
extern const double DAT_00db7de0;

extern UINT (__stdcall* const DAT_00d9b274)(UINT, LPINPUT, int);
struct Heap2173 {void* FUN_0086b930(unsigned int);void FUN_0086ba60(void*);};extern Heap2173 DAT_01090a78;
struct BatchPoint
{
    float x, y, z;
    BatchPoint() {}
    BatchPoint(float a,float b,float c):x(a),y(b),z(c){}
    void Reset();
};
struct BatchString
{
    char* data;
    unsigned short length, capacity;
    BatchString():data(0),length(0),capacity(0){}
    ~BatchString(){if(data) DAT_01090a78.FUN_0086ba60(data);data=0;capacity=0;length=0;}
    operator const char*() const {return data;}
};
struct BatchSettings
{
    bool flag0, flag1, flag2, flag3, flag4, flag5;
    char unk06, unk07;
    int savedPriority;
};
struct BatchPortalList {
int value; bool Empty(){return value==0;}
};
struct BatchPortal {
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
BatchPortalList list;BatchPortalList* GetList(){return &list;}
};
struct BatchRegionList {
void* value;BatchRegionList* next;bool Contains(void*& p){for(BatchRegionList* n=this;n;n=n->next)if(n->value==p)return true;return false;}
};
struct BatchRegions
{
    int unk00;
    BatchRegionList list;
};
struct BatchTerrain {
void TESObjectLAND_GetLandHeight(BatchPoint*,float*);
};
struct BatchWorld;
struct BatchCell
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void FunctionAtSlot4();
    virtual void FunctionAtSlot5();
    virtual void FunctionAtSlot6();
    virtual void VirtualFunction7();
    virtual void VirtualFunction8();
    virtual void VirtualFunction9();
    virtual void VirtualFunction10();
    virtual void ReplaceImpactData();
    virtual void reserved12();
    virtual void VirtualFunction13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void VirtualFunction22();
    virtual void VirtualFunction23();
    virtual void VirtualFunction24();
    virtual void VirtualFunction25();
    virtual void VirtualFunction26();
    virtual void VirtualFunction27();
    virtual void VirtualFunction28();
    virtual void VirtualFunction29();
    virtual void reserved30();
    virtual void reserved31();
    virtual void reserved32();
    virtual void reserved33();
    virtual void reserved34();
    virtual void reserved35();
    virtual void reserved36();
    virtual void reserved37();
    virtual void reserved38();
    virtual void reserved39();
    virtual void reserved40();
    virtual void reserved41();
    virtual void reserved42();
    virtual void reserved43();
    virtual void reserved44();
    virtual void reserved45();
    virtual void reserved46();
    virtual void reserved47();
    virtual void reserved48();
    virtual void reserved49();
    virtual void reserved50();
    virtual void reserved51();
    virtual void reserved52();
    virtual void reserved53();
    virtual void reserved54();
    virtual void reserved55();
    virtual void reserved56();
    virtual void reserved57();
    virtual void reserved58();
    virtual void reserved59();
    virtual void reserved60();
    virtual void reserved61();
    virtual void reserved62();
    virtual void reserved63();
    virtual void reserved64();
    virtual void reserved65();
    virtual void reserved66();
    virtual void reserved67();
    virtual void reserved68();
    virtual void reserved69();
    virtual void reserved70();
    virtual void reserved71();
    virtual void reserved72();
    virtual void reserved73();
    virtual void reserved74();
    virtual void reserved75();
    virtual const char* Name();
int unk004;
unsigned int formFlags;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
unsigned char cellFlags;char unk25,unk26,unk27;
bool Deleted(){return (formFlags>>5)&1;}
    int FUN_004d62c0();
    BatchRegions* FUN_004d35f0(bool);
    bool Interior(){return cellFlags&1;}
    int TESObjectCELL_GetDataX();
    int TESObjectCELL_GetDataY();
    void FUN_004df450();
    void FUN_004e1a70(BatchPoint*, BatchPoint*);
    BatchTerrain* TESObjectCELL_GetLand();
    BatchWorld* FUN_004d3780();
    BatchPortal* FUN_004d5110();
    int FUN_004d6190();
};
struct BatchWorld {
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
float minX,minY,maxX,maxY;
float GetMinX(){return minX;}float GetMinY(){return minY;}float GetMaxX(){return maxX;}float GetMaxWorldY(){return maxY;}
BatchCell* FUN_00503ea0(int,int);
};
struct BatchWorldNode {
BatchWorld* world;BatchWorldNode* next;BatchWorld** Data(){return &world;}BatchWorldNode* Next(){return next;}
};
struct BatchHandler
{
    void FUN_00441720(bool);
    void FUN_0043e5c0();
int unk000;
int unk004;
int unk008;
BatchWorldNode worlds;BatchWorldNode* Worlds(){return &worlds;}
    void FUN_0043ec60();
    unsigned int FUN_0043c5f0();
    BatchCell* FUN_0043ec40(unsigned int);
};
extern BatchPoint DAT_0108ec68;
struct BatchDestination
{
    BatchWorld* world;
    BatchCell* cell;
    BatchPoint position;
    BatchPoint angle;
    bool enabled;
    char unk21, unk22, unk23;
    int unk24, unk28, unk2c, unk30;
    BatchDestination():world(0),cell(0),position(DAT_0108ec68),angle(DAT_0108ec68),enabled(false),unk24(0),unk28(0),unk2c(0),unk30(0){}
static void* operator new(unsigned int n){return DAT_01090a78.FUN_0086b930(n);}
};
struct BatchPlayer
{
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
BatchPoint angle;const BatchPoint& Angle(){return angle;}
    BatchWorld* FUN_004e8880();
    void FUN_007882f0(BatchDestination*);
    void FUN_00786560();
};
struct BatchIO
{
    void FUN_00aa4b30(int);void Wait(){FUN_00aa4b30(5);}
};
struct BatchCalendar
{
    void FUN_006e28b0(float);
};
struct BatchSave
{
    void FUN_006e02f0(int);
};
struct BatchProcess
{
    unsigned int FUN_0078c0b0();
};
struct BatchMemory {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
unsigned int size;int unk28;BatchMemory* next;unsigned int Size(){return size;}BatchMemory* Next(){return next;}
};
extern BatchHandler* DAT_0106cdcc;
struct RefreshGrid {virtual void v0();virtual void v4();virtual void Clear();};
struct RefreshRef {virtual void v0();virtual void Destroy();volatile long count;void DecRef(){if(InterlockedDecrement(&count)==0)Destroy();}};
struct RefreshList {void FUN_006c8220();};
extern RefreshRef* DAT_0116f3d8;extern bool DAT_00f4c96c;
struct BatchTES
{
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
    char unk50;
    bool active;
    char unk52, unk53;
    void(__cdecl* callback)(BatchCell*, void*);
    void* callbackArg;
    void* region;
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
    BatchWorld* currentWorld;
    void SetCategory(void(__cdecl* p)()){callback=reinterpret_cast<void(__cdecl*)(BatchCell*,void*)>(p);}
    void TES_SetWorldSpace(BatchWorld*);
    void FUN_00434ff0(BatchCell*);
    void FUN_0043a040(BatchCell*, BatchPoint*);
    BatchCell* IsCellInterior(){return reinterpret_cast<BatchCell*>(unk34);}
    void FUN_0043a670(BatchPoint*);
    void FUN_004399f0(BatchPoint*, bool);
    void FUN_00435070(bool,bool);void TES_FreeInteriorBuffer(bool);
    __forceinline void Refresh(bool a,bool b){reinterpret_cast<RefreshList*>(reinterpret_cast<char*>(this)+0x8c)->FUN_006c8220();if(unk34 && DAT_0106cdcc){reinterpret_cast<RefreshGrid*>(unk08)->Clear();if(DAT_0116f3d8){DAT_0116f3d8->DecRef();DAT_0116f3d8=0;}DAT_00f4c96c=true;}FUN_00435070(a,b);TES_FreeInteriorBuffer(true);*reinterpret_cast<bool*>(reinterpret_cast<char*>(this)+0xb4)=true;}
    void FUN_0043ac20(int mode);
};
static bool DAT_0106cda8;
static bool DAT_0106cd98;
extern bool DAT_00f4943c;
static int DAT_0106cda4;
extern int DAT_00f49440;
static int DAT_0106cd90;
static int DAT_0106cd8c;
static int DAT_0106cd88;
static unsigned int DAT_0106cd94;
static unsigned int DAT_0106cd9c;
static BatchWorldNode* DAT_0106cda0;
extern const char* DAT_00f49444;
extern BatchHandler* DAT_0106cdcc;
extern BatchPlayer* DAT_0107a104;
extern BatchIO* DAT_0116d138;
extern BatchTES* DAT_0107a0d8;
extern BatchSave* DAT_01079ca4;
extern BatchCalendar DAT_01079f68;
extern BatchProcess DAT_0107c0a0;
extern BatchPoint DAT_0108ec68;
void __cdecl TESObjectCELL_RenderTestCell();
extern long DAT_0116d6bc;inline void BatchActive(bool b){if(b)InterlockedIncrement(&DAT_0116d6bc);else InterlockedDecrement(&DAT_0116d6bc);if(DAT_0116d6bc<0)DAT_0116d6bc=0;}
int __cdecl BSSystemFile_DeleteFileA(const char*);
int __cdecl FUN_00887da0(const char*, ...);
int __cdecl FUN_00c020cb(const char*, const char*, unsigned int);
int __cdecl FUN_00c02127();
inline int BatchNameTest(const char* name){return FUN_00c020cb(name, DAT_00db8f24, 4);}
void __cdecl FUN_006ef0a0(char*, bool, bool);
void __cdecl FUN_006ef040();
void __cdecl FUN_006ef100(unsigned char*);
void __cdecl FUN_0046fbd0(float*, float*, bool, bool);
void __cdecl FUN_0046f720(float, BatchString*, int);
extern BatchMemory* DAT_0108ee00;inline BatchMemory* BatchMemoryHead(){return DAT_0108ee00;}
// pdb: TES::TestAllCells | TES.obj | fnv360_0822_retail, ustr, medium
// pdb params: aiControl
void BatchTES::FUN_0043ac20(int mode)
{
    if (mode == 4 || mode == 5 || mode == 9)
        DAT_0106cda8 = true;
    switch (mode) {
    case 6:
    case 7:
        mode -= 5;
        DAT_0106cda8 = true;
        SetCategory(TESObjectCELL_RenderTestCell);
        break;
    }
    switch (mode)
    {
    default:
        DAT_0106cda4 = mode;
        active = true;
        BatchActive(true);
        BSSystemFile_DeleteFileA(DAT_00f49444);
        if (!DAT_0106cda8)
        {
            FUN_00887da0(DAT_00db8f78);
            DAT_0106cdcc->FUN_00441720(false);
            FUN_00887da0(DAT_00db8f30);
            DAT_0106cdcc->FUN_0043e5c0();
            DAT_0106cda8 = true;
        }
        if ((mode == 1 || mode == 4 || mode == 5 || mode == 9) && !DAT_0106cda0 && !DAT_0106cd9c)
        {
            DAT_0106cda0 = DAT_0106cdcc->Worlds();
            DAT_0106cd98 = true;
            DAT_0106cdcc->FUN_0043ec60();
            DAT_0106cd9c = DAT_0106cdcc->FUN_0043c5f0();
            DAT_0106cd94 = 0;
        }
        else if (mode == 3)
        {
            if (!DAT_0106cda0 || *DAT_0106cda0->Data() != currentWorld)
            {
                DAT_0106cda0 = DAT_0106cdcc->Worlds();
                while (DAT_0106cda0)
                {
                    BatchWorld* world = *DAT_0106cda0->Data();
                    if (world && world == currentWorld)
                        break;
                    DAT_0106cda0 = DAT_0106cda0->Next();
                }
            }
            if (DAT_0106cda0)
            {
                DAT_0106cd98 = true;
                DAT_0106cdcc->FUN_0043ec60();
                DAT_0106cd9c = DAT_0106cdcc->FUN_0043c5f0();
                DAT_0106cd94 = 0;
            }
        }
        else if (mode == 2)
        {
            if (DAT_0106cda0)
            {
                DAT_0106cda0 = 0;
                DAT_0106cd98 = false;
            }
            if (!DAT_0106cd9c)
            {
                DAT_0106cdcc->FUN_0043ec60();
                DAT_0106cd9c = DAT_0106cdcc->FUN_0043c5f0();
                DAT_0106cd94 = 0;
            }
        }
        break;
    case -1:
        active = false;
        BatchActive(false);
        region = 0;
        break;
    case 0:
        break;
    }
    bool again = true;
    while (again)
    {
        again = false;
        if (active)
        {
            if (mode == 9)
                again = true;
            BatchCell* cell = 0;
            int start = FUN_00c02127();
            INPUT input;
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_MOVE;
            input.mi.time = 0;
            input.mi.dy = 0;
            input.mi.mouseData = 0;
            input.mi.dwExtraInfo = 0;
            if (DAT_00f49440 > 0)
                input.mi.dx = 2;
            else
                input.mi.dx = -1;
            DAT_00d9b274(1, &input, sizeof(INPUT));
            DAT_00f49440 = -DAT_00f49440;
            if (DAT_0106cd98)
            {
                if (DAT_0106cda0)
                {
                    BatchWorld* world = *DAT_0106cda0->Data();
                    while (world && !BatchNameTest(((BatchCell*)world)->Name()))
                    {
                        DAT_0106cda0 = DAT_0106cda0->Next();
                        if (DAT_0106cda0)
                            world = *DAT_0106cda0->Data();
                        else
                            world = 0;
                    }
                    if (world)
                    {
                        TES_SetWorldSpace(world);
                        DAT_0106cd90 = ((int)currentWorld->GetMinX()) >> 12;
                        DAT_0106cd8c = ((int)currentWorld->GetMinY()) >> 12;
                        int maxX = ((int)currentWorld->GetMaxX()) >> 12;
                        int maxY = ((int)currentWorld->GetMaxWorldY()) >> 12;
                        FUN_00887da0(DAT_00db8ee0,
                                   ((BatchCell*)currentWorld)->Name(), DAT_0106cd90, DAT_0106cd8c, maxX, maxY);
                    }
                }
                DAT_0106cd98 = false;
            }
            bool found = false;
            bool done = false;
            while (!found && !DAT_0106cd98 && !done)
            {
                if (DAT_0106cda0)
                {
                    cell = currentWorld->FUN_00503ea0(DAT_0106cd90, DAT_0106cd8c);
                    if (cell)
                        FUN_00434ff0(cell);
                    DAT_0106cd8c++;
                    if (DAT_0106cd8c > (((int)currentWorld->GetMaxWorldY()) >> 12))
                    {
                        DAT_0106cd8c = ((int)currentWorld->GetMinY()) >> 12;
                        DAT_0106cd90++;
                        if (DAT_0106cd90 > (((int)currentWorld->GetMaxX()) >> 12))
                        {
                            DAT_0106cda0 = DAT_0106cda0->Next();
                            if (DAT_0106cda0)
                                DAT_0106cd98 = true;
                        }
                    }
                }
                else
                {
                    unsigned int index = DAT_0106cd94;
                    if (!index)
                        FUN_00887da0(DAT_00db8ea8);
                    cell = DAT_0106cdcc->FUN_0043ec40(index);
                    DAT_0106cd94++;
                    while (cell && !BatchNameTest(cell->Name()))
                    {
                        cell = DAT_0106cdcc->FUN_0043ec40(DAT_0106cd94);
                        DAT_0106cd94++;
                    }
                    if (!cell)
                        done = true;
                }
                if (cell && !cell->Deleted() && cell->FUN_004d62c0())
                    found = true;
            }
            if (cell && found)
            {
                BatchRegions* regions = cell->FUN_004d35f0(true);
                if (region)
                {
                    if (!regions || !regions->list.Contains(region))
                        found = false;
                }
            }
            else if (DAT_0106cd98)
            {
                if (DAT_0107a104->FUN_004e8880() != currentWorld)
                    again = true;
            }
            if (found)
            {
                DAT_01079f68.FUN_006e28b0(10.0f);
                BatchPoint position4 = DAT_0108ec68;
                if (!cell->Interior()) {
                    float x = static_cast<float>((cell->TESObjectCELL_GetDataX() << 12) + DAT_00db7de0);
                    float y = static_cast<float>((cell->TESObjectCELL_GetDataY() << 12) + DAT_00db7de0);
                    BatchPoint exterior(x, y, 0.0f);
                    position4 = exterior;
                }
                if (cell->Interior())
                {
                    cell->FUN_004df450();
                    BatchPoint rotation;
                    cell->FUN_004e1a70(&position4, &rotation);
                    FUN_0043a040(cell, &position4);
                }
                else if (IsCellInterior())
                {
                    FUN_0043a670(&position4);
                    float height;
                    cell->TESObjectCELL_GetLand()->TESObjectLAND_GetLandHeight(&position4,&height);
                    if (height >= 0.0)
                        position4.z = height;
                }
                else
                {
                    FUN_004399f0(&position4, false);
                    float height;
                    cell->TESObjectCELL_GetLand()->TESObjectLAND_GetLandHeight(&position4,&height);
                    if (height >= 0.0)
                        position4.z = height;
                }
                BatchDestination* destination5 = new BatchDestination;
                destination5->position = position4;
                destination5->angle = DAT_0107a104->Angle();
                destination5->enabled = true;
                if (cell->Interior())
                    destination5->cell = cell;
                else
                    destination5->world = cell->FUN_004d3780();
                DAT_0107a104->FUN_007882f0(destination5);
                DAT_0107a104->FUN_00786560();
                DAT_0116d138->Wait();
                int finish3 = FUN_00c02127();
                float elapsed = (finish3 - start) / 1000.0;
                BatchSettings settings8;
                FUN_006ef0a0((char*)&settings8, true, true);
                DAT_0107a0d8->Refresh(true, false);
                FUN_006ef040();
                FUN_006ef100((unsigned char*)&settings8);
                if (DAT_00f4943c)
                {
                    float textureCount9 = 0.0f;
                    float modelCountTmp = 0.0f;
                    BatchString modelString2;
                    FUN_0046fbd0(&textureCount9, &modelCountTmp, true, true);
                    FUN_0046f720(modelCountTmp, &modelString2, 0);
                    bool portalsVal = false;
                    BatchPortal* graphTmp = cell->FUN_004d5110();
                    if (graphTmp && !graphTmp->GetList()->Empty())
                        portalsVal = true;
                    unsigned int memory2 = 0;
                    BatchMemory* entry30 = BatchMemoryHead();
                    while (entry30)
                    {
                        if (entry30->Size())
                            memory2 += FUN_00887da0(reinterpret_cast<const char*>(entry30));
                        entry30 = entry30->Next();
                    }
                    memory2 >>= 20;
                    unsigned int actors3 = DAT_0107c0a0.FUN_0078c0b0();
                    if (cell->Interior())
                    {
                        FUN_00887da0(
                            DAT_00db8e30,
                            cell->Name(), (const char*)modelString2, textureCount9, elapsed, cell->FUN_004d6190(),
                            portalsVal ? DAT_00db8ea0 : DAT_00db8e9c, memory2, actors3);
                        FUN_00887da0(DAT_00f49444, DAT_00db8e04, cell->Name(),
                                       (const char*)modelString2, textureCount9, elapsed, cell->FUN_004d6190(),
                                       portalsVal ? DAT_00db8ea0 : DAT_00db8e9c, memory2, actors3);
                    }
                    else
                    {
                        DAT_0106cd88++;
                        FUN_00887da0(
                            DAT_00db8da8,
                            cell->Name(), cell->TESObjectCELL_GetDataX(), cell->TESObjectCELL_GetDataY(), (const char*)modelString2, textureCount9,
                            elapsed, portalsVal ? DAT_00db8ea0 : DAT_00db8e9c, memory2, actors3);
                        FUN_00887da0(DAT_00f49444, DAT_00db8d80, cell->Name(),
                                       cell->TESObjectCELL_GetDataX(), cell->TESObjectCELL_GetDataY(), (const char*)modelString2, textureCount9, elapsed,
                                       portalsVal ? DAT_00db8ea0 : DAT_00db8e9c, memory2, actors3);
                    }
                }
                if (callback)
                    callback(cell, callbackArg);
                if (DAT_0106cda4 == 4 || DAT_0106cda4 == 5)
                    DAT_01079ca4->FUN_006e02f0(DAT_0106cda4);
            }
            if (DAT_0106cd94 >= DAT_0106cd9c)
            {
                DAT_0106cd9c = 0;
                active = false;
                BatchActive(false);
                region = 0;
            }
        }
    }
}

}   // namespace f3m_0043ac20

// @f3 0x00427200 (community match, verified in this file)
namespace f3m_00427200 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);

namespace f3m_00427200 {
struct Entry {
    int unk00;
    long refCount;
    void IncRef() { InterlockedIncrement(&refCount); }
    void DecRef() { InterlockedDecrement(&refCount); }
};

struct EntryPtr {
    Entry* object;
    EntryPtr& operator=(Entry* other)
    {
        if (object != other) {
            if (object)
                object->DecRef();
            object = other;
            if (object)
                object->IncRef();
        }
        return *this;
    }
};

struct EntryMap {
    virtual void v00();
    virtual void v04();
    virtual bool Lookup(const char* key, Entry** found);
};
}
using namespace f3m_00427200;

struct FUN_00427200_cls {
    EntryMap* map;
    bool FUN_00427200(const char* path, EntryPtr* out);
};

// pdb: ModelLoader::FindModel | ModelLoader.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apFilename, aspOutModel
bool FUN_00427200_cls::FUN_00427200(const char* path, EntryPtr* out)
{
    *out = 0;
    Entry* found = 0;
    if (map->Lookup(path, &found)) {
        *out = found;
        return true;
    }
    return false;
}
}   // namespace f3m_00427200

// @f3 0x0042ba60 (community match, verified in this file)
namespace f3m_0042ba60 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
namespace f3m_0042ba60 {
struct ThreadData {
    char unk000[0x298];
    int heapContext;
};
extern __declspec(thread) ThreadData g_threadData42ba60;
struct HeapContextGuard {
    int saved;
    HeapContextGuard(int context)
    {
        saved = g_threadData42ba60.heapContext;
        g_threadData42ba60.heapContext = context;
    }
    ~HeapContextGuard() { g_threadData42ba60.heapContext = saved; }
};
struct Ref {
    virtual ~Ref();
    int unk04;
    long refs;
    void DecRef() {
        if (InterlockedDecrement(&refs) == 0)
            delete this;
    }
};
struct Holder {
    Ref* p;
    Holder(Ref* x) : p(x) {
        if (p)
            InterlockedIncrement(&p->refs);
    }
    Holder& operator=(const Holder& other) {
        if (p != other.p) {
            if (p)
                p->DecRef();
            p = other.p;
            if (p)
                InterlockedIncrement(&p->refs);
        }
        return *this;
    }
};
struct AllocationHeap {
    void* FUN_0086b930(unsigned int);
};
extern AllocationHeap DAT_01090a78;
struct QueueNode {
    QueueNode* next;
    Holder value;
    QueueNode() : next(0), value(0) {}
    static void* operator new(unsigned int size) {
        return DAT_01090a78.FUN_0086b930(size);
    }
};
struct QueueState {
    virtual void Unk00();
    virtual void Unk04();
    virtual void Notify();
    int unk04;
    QueueNode* tail;
};
struct Thing {
    QueueState* state;
    QueueNode** hazard;
    void FUN_0042ba60(const Holder&);
};

// pdb: LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueInterface::Push | ModelLoader.obj | fnv360_0822_retail, call_gap, low
// pdb params: arData
void Thing::FUN_0042ba60(const Holder& value)
{
    HeapContextGuard context(6);
    QueueNode* volatile tail = 0;
    QueueNode* node = new QueueNode;
    node->value = value;
    for (;;) {
        tail = state->tail;
        *hazard = tail;
        if (tail != state->tail)
            continue;
        QueueNode* next = tail->next;
        if (tail != state->tail)
            continue;
        QueueNode* current = tail;
        if (next) {
            InterlockedCompareExchange((volatile long*)&state->tail, (long)next, (long)current);
            continue;
        }
        if (InterlockedCompareExchange((volatile long*)&current->next, (long)node, 0) == 0)
            break;
    }
    state->Notify();
    QueueNode* last = tail;
    InterlockedCompareExchange((volatile long*)&state->tail, (long)node, (long)last);
    *hazard = 0;
}
}
}   // namespace f3m_0042ba60
