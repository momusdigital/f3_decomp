#include "f3_common.h"
// src/staging/blk_00820000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern "C" void* DAT_0107cb6c;

void __fastcall FUN_0082f1b0(void*);

struct RecursiveLock
{
    void Leave();
};

namespace fnv_0082f240 {
extern int DAT_0107cb6c;

}  // namespace fnv_0082f240

void __fastcall FUN_0082f1b0(void*);

namespace fnv_0082f550 {
struct RecursiveLock
{
    void Leave();
};

}  // namespace fnv_0082f550

struct BGSLoadFormBuffer
{
    bool ReadFormIdentifier(void*);
};

extern int DAT_011dd87c[];

namespace fnv_008374e0 {
extern int DAT_011dd87c;

}  // namespace fnv_008374e0

struct S7010
{
    unsigned int Length();
};

namespace fnv_0083e0a0 {
struct S7010
{
    unsigned int Length();
};
}  // namespace fnv_0083e0a0

extern "C" void* __cdecl _NiFreeAlias(void*);

namespace fnv_0083b710 {
extern "C" void __cdecl _NiFreeAlias(void*);
extern void* DAT_0107d9e4;

}  // namespace fnv_0083b710

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);

void __cdecl Deallocate(void*);

extern int DAT_0107cd54;
extern int DAT_0107cd6c;
extern int DAT_0107cdac;

namespace fnv_0083b640 {
extern "C" void* _NiMalloc(unsigned int size);
void* memset(void* dest, int c, unsigned int count);
extern "C" void* DAT_0107d9e4;
}  // namespace fnv_0083b640

void __cdecl Deallocate(void*);

struct SoundPlaybackHandle
{
    int x;
    int y;
    int z;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
};

void __cdecl Deallocate(void*);

struct TESForm
{
    virtual ~TESForm();
};
struct TESObjectREFR : TESForm
{
    virtual ~TESObjectREFR();
};

struct SoundDataDummy
{
    char pad[28];
    int a;
    int b;
};
struct TESSound
{
    SoundDataDummy CopyBig();
};

struct BSAudio
{
    static BSAudio* __cdecl GetSingleton();
    unsigned int GetSynchTime();
};
struct EffectSetting
{
    void* GetBoltSound();
};
struct TESObject
{
    unsigned int GetNext();
};
struct SndX
{
    int a, b, c;
    void Stop();
    void PausePlayback();
};
struct SndItem
{
    TESObject* obj;
    SndX first;
    SndX second;
    bool active;
};
struct ContNode
{
    SndItem** ref_006815c0();
};
bool __fastcall FUN_008256d0(ContNode*);
ContNode* __fastcall FUN_00726070(ContNode*);

void* __cdecl operator new(unsigned int);
struct TESTopic : TESForm
{
    virtual ~TESTopic();
};
struct TESTopicInfo : TESForm
{
    virtual ~TESTopicInfo();
};
struct TESQuest : TESForm
{
    virtual ~TESQuest();
};

struct SL
{
    SL();
    int alignment;
};

struct BCaster_S
{
    void* vtable;
    void* field_04;
    void* field_08;

    BCaster_S();
    ~BCaster_S();
};

struct MagicCaster;
struct MagicItem;
struct EffectItem;
struct ActiveEffect
{
    void* vtbl;
    ActiveEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);
};
struct FUN_008260b0 : ActiveEffect
{
    FUN_008260b0(MagicCaster* caster, MagicItem* item, EffectItem* effect);
};

namespace fnv_00826260 {
struct FUN_008260b0
{
    unsigned char m_auiShapeKeys[0x48];
    FUN_008260b0(void*, void*, void*);
};

}  // namespace fnv_00826260

struct FUN_0082cf80
{
    unsigned char m_data[0x48];
    __fastcall FUN_0082cf80(int, int, int);
};

void __cdecl Deallocate(void*);

typedef void(__stdcall* FUN_00831eb0_callback)(void*, int, int);

struct BSStr
{
    bool Set(char const* value, unsigned int length);
};

struct TESIdleForm : TESForm
{
    virtual ~TESIdleForm()
    {}
};

TESForm* __cdecl _ref_004839c0(unsigned int formID);

namespace fnv_0083da50 {
struct BSStr
{
    bool Set(char const*, unsigned int);
    unsigned char m_data[9];

    BSStr();
    ~BSStr();
};

struct SL
{
    int m_iWordAt00;
    int m_iWordAt04;

    SL();
    ~SL();
};

BSStr::BSStr()
{}

BSStr::~BSStr()
{}

}  // namespace fnv_0083da50

struct Str6a70
{
    Str6a70& __thiscall operator=(char const*);
};

TESForm* __cdecl _ref_004839c0(unsigned int formID);

// FUN_00822440 - 0x00822440, 99 bytes.
//
// The constructor of the game class that owns
//   +0x00  BSSimpleArray<void*, 0xEAA>   (vftable 0x0107b84c, ctor 0x00822600,
//                                          dtor 0x00822630)
//   +0x10  BSSimpleArray<int, 0xEAA>     (vftable 0x01016024, ctor 0x00438660,
//                                          dtor 0x00438690)
//   +0x20  int                           (zeroed by the constructor)
//
// The class itself is NOT polymorphic: the original's constructor never writes
// a vftable pointer of its own, the vtable at +0x00 comes from the
// BSSimpleArray<void*> MEMBER constructor at 0x00822600.  The matching
// destructor is 0x008224b0; it destroys the members in reverse order
// (0x00438690 at +0x10 first, then 0x00822630 at +0x00).
//
// The original's code:
//   push ebp / mov ebp,esp / push -1 / push __ehhandler$ / mov eax,fs:[0] /
//   push eax / push ecx / mov eax,[__security_cookie] / xor eax,ebp /
//   push eax / lea eax,[ebp-0xc] / mov fs:[0],eax
//   mov  [ebp-0x10],ecx                 ; the /Od home slot of `this`
//   mov  ecx,[ebp-0x10] / call 0x822600 ; BSSimpleArray<void*> ctor
//   mov  dword ptr [ebp-4],0           ; EH state variable
//   mov  ecx,[ebp-0x10] / add ecx,0x10 / call 0x438660 ; BSSimpleArray<int> ctor
//   mov  eax,[ebp-0x10] / mov dword ptr [eax+0x20],0
//   mov  dword ptr [ebp-4],-1          ; EH state variable
//   mov  eax,[ebp-0x10] / mov ecx,[ebp-0xc] / mov fs:[0],ecx /
//   pop ecx / mov esp,ebp / pop ebp / ret
//
// The class name has to carry the FUN_00822440 tag (the constructor's mangled
// name is the only symbol the checker can find), so the destructor is DECLARED
// but never defined: an undefined destructor is never emitted into the object
// file, which keeps exactly ONE defined function symbol carrying the tag.

struct SecondaryBase_b5774
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    ~SecondaryBase_b5774();
};

// FUN_0082f6c0 @ 0x0082f6c0 (size 150)
// Base-object destructor of a thread-like class: clears the "running" flag bit,
// signals the object at +0x34, waits for the worker thread to leave, closes its
// handle, then runs the base class destructor.

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

// PlayWeaponSound v2 (worker11): pack types reused; extra callees via shell classes
struct NiPoint3
{
    float x, y, z;
    NiPoint3();
};
struct Vec3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& rhs) const;
};
struct AudioPlaybackHandle;
struct AudioPlaybackHandle
{
    int f00, f04, f08;
    ~AudioPlaybackHandle();
};
void* __cdecl FUN_00453a70();

namespace fnv_0083d130 {
struct S_0083d130_Str
{
    const char* __thiscall FUN_00559450();
};
struct S_0083d130_Obj
{
    S_0083d130_Str* ref_006815c0();
    S_0083d130_Str* __thiscall FUN_00460140();
};
struct S_0083d130_Node
{
    S_0083d130_Obj** ref_006815c0();
};
struct S_0083d130_Mgr
{
    void __thiscall FUN_00ad8100(const char* s, unsigned int a, int b);
};
S_0083d130_Mgr* __cdecl FUN_00453a70();
bool __fastcall FUN_008256d0(S_0083d130_Node*);
S_0083d130_Node* __fastcall FUN_00726070(S_0083d130_Node*);

}  // namespace fnv_0083d130

// Minimal declarations for the process list and its polymorphic entries.
class MobileObject
{
  public:
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual bool IsActor();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual bool IsMagicProjectile();
};
class Actor : public MobileObject
{
  public:
    void FUN_008c4f10(BCaster_S* caster);
};

namespace fnv_0082cf80 {
class C82CF80MagicCaster;
class C82CF80MagicItem;
class C82CF80EffectItem;

class C82CF80ActiveEffect
{
  public:
    C82CF80ActiveEffect(C82CF80MagicCaster* pkCaster, C82CF80MagicItem* pkItem, C82CF80EffectItem* pkEffect);
    virtual ~C82CF80ActiveEffect();
};

class FUN_0082cf80 : public C82CF80ActiveEffect
{
  public:
    FUN_0082cf80(C82CF80MagicCaster* pkCaster, C82CF80MagicItem* pkItem, C82CF80EffectItem* pkEffect);
    virtual ~FUN_0082cf80();
};

}  // namespace fnv_0082cf80

struct SoundFormData
{
    unsigned char ucMinAtten;
    unsigned char ucMaxAtten;
    unsigned char ucStaticAtten;
    unsigned char ucPad03;
    unsigned int uiFlags;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct SoundForm
{
    unsigned short FUN_0082d680();
    unsigned char GetByteAtOffset44();
    unsigned char GetField45();
    unsigned char GetHighByteOfField4E();
    unsigned char FUN_0082d700();
    unsigned short GetShortAt(int aiIndex);
    unsigned short GetShortAtOffset5A();
    unsigned char FUN_0082d720();
    SoundFormData GetData();
};

struct AudGuid
{
    unsigned long d0;
    unsigned long d1;
    unsigned long d2;
    unsigned long d3;
};

extern "C" __declspec(dllimport) long __stdcall CoInitializeEx(void* reserved, unsigned long flags);
extern "C" __declspec(dllimport) long __stdcall CoCreateInstance(const AudGuid& clsid, void* outer, unsigned long ctx,
                                                                 const AudGuid& iid, void** out);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* handle, unsigned long ms);

struct SoundForm;

extern int DAT_0107cdac;
extern int DAT_0107cd6c;
extern int DAT_0107cd54;

// FUN_00831fe0: __cdecl adjustor thunk (sub dword ptr [esp+4],4; jmp target).
// A __cdecl virtual member passes "this" as the first stack argument, so the
// multiple-inheritance adjustor thunk subtracts the secondary-base offset from
// that stack slot instead of from ecx. Primary base is 4 bytes (vptr only);
// the secondary base subobject sits at +4 inside Derived.
struct PrimaryBase_00831fe0
{
    virtual void __cdecl FUN_00831fe0();
};

struct SecondaryBase_00831fe0
{
    virtual void __cdecl FUN_00831fe0();
};

struct Derived_00831fe0 : PrimaryBase_00831fe0, SecondaryBase_00831fe0
{
    Derived_00831fe0();
// @fnv 0x00831fe0
    virtual void __cdecl FUN_00831fe0();
};

Derived_00831fe0::Derived_00831fe0()
{}

namespace fnv_0082f1b0 {
#include <windows.h>

}  // namespace fnv_0082f1b0

// FUN_0082b370 - constructor of the argument holder object: runs the base
// constructor (FUN_00803d30), installs its own vtable and clears the flag byte
// at +0x48.
