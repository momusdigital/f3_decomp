#include "f3_common.h"
// src/staging/blk_009a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_0099a9a0_shell
{
    void FUN_009a03d0(int);
};

namespace fnv_009a03a0 {
struct FUN_0099a9a0_shell
{
    void ReleaseStageHolder(int);
};

}  // namespace fnv_009a03a0

struct AX
{
    void FUN_006b3eb0(unsigned int a, unsigned int b);
    AX* FUN_009a3750(unsigned int a, unsigned int b);
};

extern "C" void* DAT_0108e0a4;

namespace fnv_009a3810 {
extern int DAT_0108e0a4;

struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_009a3810();
};

}  // namespace fnv_009a3810

struct CombatTargetTimestamp;

extern int DAT_0108e258;

namespace fnv_009a42f0 {
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_009a42f0(unsigned int a, unsigned int b);
};
}  // namespace fnv_009a42f0

struct GO
{
    void* operator=(void*);
};

extern "C" void NiFreeAlias(void*);

extern void* DAT_0108e328;

void __cdecl NiFreeAlias(void* p);

struct GlobalObject_00869f00
{
};
void __cdecl operator delete(void*);

extern "C" void Deallocate(void* p);

void __cdecl Deallocate(void*);

void __cdecl Deallocate(void* p);

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int value, unsigned int count);

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct CombatTargetTimestamp
{
    void SaveTimeStamp(BGSSaveFormBuffer*);
};

extern "C" void __cdecl Deallocate(void*);

extern void* DAT_0108e328;
void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);

struct CombatWorldStateListNode
{
    CombatWorldStateListNode* GetNext();
    CombatWorldStateListNode* operator->();
};

struct hkpRigidBody
{
    void SetCollisionShape(void* p);
};
struct ScriptLocalsX
{
    hkpRigidBody* GetLocalData();
};
struct ScriptX
{
    void GetLocalData();
};

namespace fnv_009b0cf0 {
struct ScriptLocalsX
{
    void* __thiscall GetLocalData();
};
struct ScriptX
{
    void __thiscall GetLocalData();
};
}  // namespace fnv_009b0cf0

struct NiAVObject;
struct ExtraDataList
{
    void Set3DObject(NiAVObject*);
};
struct Flt
{
    operator unsigned int();
};

namespace fnv_009b3130 {
void* __cdecl Deallocate(void* p);
}  // namespace fnv_009b3130

namespace fnv_009bb7f0 {
struct NiAVObject;
struct NiLight;
struct TESObjectLIGH
{
    NiLight* CreateLight(TESObjectREFR*, NiAVObject*, bool);
};
struct Flt
{
    operator unsigned int();
};
}  // namespace fnv_009bb7f0

struct Projectile
{
    Projectile(bool b);
    ~Projectile();
    void SetFormType(int type);
};

namespace fnv_009b5650 {
struct TESObjectREFR
{
    float GetScale();
};
struct Obj
{
    float GetFieldDC();
};
struct BooleanFloatQuery
{
    void* a;
    void* b;
    void* p_08;
    float p_14;
    float p_18;
    int p_30;
    float p_34;
    void ApplyCriticalHit();
    void FUN_009b5a30(bool);
    void FUN_009b6620(void*);
    void ApplyDamageEffects();
};
}  // namespace fnv_009b5650

struct NiLight;

struct NiPoint3
{
    float x, y, z;
};

struct TESObjectLIGH
{
    void* CreateLight(void* a, void* b, bool c);
};
struct EffectSetting
{
    EffectSetting* GetCastSound() const;
};

struct FUN_009a39f0_class
{
    virtual void FUN_009a39f0_virtual0();
    virtual int FUN_009a39f0_virtual1(unsigned int size);

    int m4;
    int m8;
    int mc;

    void __thiscall ConstructObjects(int a, int b);
    void __thiscall FUN_009a39f0(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x009a39f0
inline void FUN_009a39f0_class::FUN_009a39f0_virtual0()
{}

inline int FUN_009a39f0_class::FUN_009a39f0_virtual1(unsigned int size)
{
    return 0;
}

struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};

void __cdecl Deallocate(void*);

extern float DAT_011f1c00;
struct bhkCharacterController
{
    float& GetVectorElement(int);
};

struct FUN_009ab970_Class
{
    char m0[0xd30];
    struct NiPoint3
    {
        float x, y, z;
    };
    NiPoint3& FUN_009ab970(NiPoint3& akDest);
};

struct TESWorldSpace
{
    void* GetWorldTerrainManager();
};

struct MemoryManager
{
    int x;
};

typedef unsigned char ByteTag;

namespace fnv_009b3100 {
struct bhkCharacterController
{
    float& GetVectorElement(int a);
};
}  // namespace fnv_009b3100

extern const double DAT_01012060;

void* __cdecl operator new(unsigned int count, void* place);
void __cdecl operator delete(void* ptr, void* place);

class Obj;

class Iface
{
  public:
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(Obj* p);
};

class Obj
{
  public:
    Iface* Lookup();
};

class Base
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Base();
};

struct CombatOwner;
struct CombatOwnerManager
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6C();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7C();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8C();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9C();
    virtual void unkA0();
    virtual void unkA4();
    virtual void unkA8();
    virtual void unkAC();
    virtual void unkB0();
    virtual void unkB4();
    virtual void unkB8();
    virtual void unkBC();
    virtual void unkC0();
    virtual void unkC4();
    virtual void unkC8();
    virtual void unkCC();
    virtual void unkD0();
    virtual void unkD4();
    virtual void unkD8();
    virtual void unkDC();
    virtual void unkE0();
    virtual void unkE4();
    virtual void Remove(CombatOwner*);
};
struct CombatOwner
{
    CombatOwnerManager* FUN_009611e0();
};
struct CombatOwnerPtr
{
    CombatOwner* object;
    operator CombatOwner*() const;
    CombatOwner* operator->() const;
    ~CombatOwnerPtr();
};

struct Point9a
{
    float x, y, z;
    float FUN_00457910();
    Point9a operator*(float) const;
    Point9a operator+(const Point9a&) const;
    Point9a& operator+=(const Point9a&);
};
struct Setting9a
{
    float* Float();
};
extern Setting9a DAT_011cf48c, DAT_011cef98, DAT_011ce990;
float FUN_00404010(float, float);

extern float DAT_011f1c00;

typedef unsigned char(__thiscall* VCheckFn)(void*);

// GetKeywordName (0x009aa120, 23 bytes, /MT /Od /Oy- /GS /EHsc /Gy)
//
// The original is a tiny thiscall accessor on a keyword/flag holder object:
//
//   mov eax, [ebp-4]          ; the spilled 'this'
//   mov ecx, [eax]            ; this->m_uiEdgeIndex  (first dword of the object)
//   mov eax, [ecx*8 + table]  ; table[m_uiEdgeIndex].m_name  (8-byte entries)
//
// records (the script keyword names), and the accessor hands back the name
// pointer of the record selected by the index stored in the object.

template <class T> class PathingRef9AB
{
  public:
    PathingRef9AB(T* pObject = 0);
    ~PathingRef9AB();
    void Reset(T* pObject);

    T* m_pObject;
};

class TESForm
{
  public:
    virtual ~TESForm();
};
TESForm* __cdecl FUN_004839c0(unsigned int);

template <> class SettingT<GameSettingCollection>
{
  public:
    float& Float();
};

struct SoundHandleX
{
    int unk00;
    int unk04;
    int unk08;
    ~SoundHandleX();
    SoundHandleX& operator=(const SoundHandleX& other);
};

struct PPoint3
{
    float x, y, z;
    PPoint3();
    PPoint3& operator*=(float f);
};

class GameObject
{
  public:
    void** vtable;
    bool __thiscall FUN_00444d00(unsigned int flags);
    void __thiscall FUN_009bec10(float value);
};

typedef void(__thiscall* VirtualCall)(GameObject*, float);

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);

extern int DAT_0108e258;

struct Pt_009a4710
{
    float x, y, z;
    float FUN_00457910();
    float FUN_004a7290() const;
    float DotProduct(const Pt_009a4710& other) const;
    Pt_009a4710 operator*(float scale) const;
    Pt_009a4710 operator+(const Pt_009a4710& other) const;
    Pt_009a4710 operator-(const Pt_009a4710& other) const;
};
extern float DAT_0108e2b0;

struct AvoidanceEntry
{
    Point9a position;
    Point9a direction;
    float radius;
    float distance;
    int type;
};
class PathingAvoidNodeArray
{
  public:
    void* vtable;
    AvoidanceEntry* entries;
    unsigned int count;
    unsigned int capacity;
    void* allocatorVtable;
    unsigned int allocatorState;
    static void* operator new(unsigned int);
    PathingAvoidNodeArray();
    unsigned int AppendNode(const AvoidanceEntry&);
};

struct FUN_006815c0
{
    int unk00;
    int unk04;
    int unk08;
    FUN_006815c0();
};

// Return the current response's voice file path (or the default path), toggling the dialogue lock around it.

struct TargetRef;
struct TargetExtra;
struct TargetRef
{
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void Mark(int);
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual bool NeedsExtra();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual TargetRef* GetLoadedForm();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void SetExtra(TargetExtra*);
    virtual TargetExtra* GetExtra();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual bool IsProjectile();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void Update();
    TargetRef* FUN_00874480();
    unsigned int FUN_00476c90();
    TargetRef* FUN_008d8520();
    unsigned int FUN_0044ddc0();
    float FUN_00644930();
    void FUN_00407880(float);
    TargetRef* GetFieldC8();
    void FUN_0056c7d0(TargetRef*);
    bool FUN_00572c80();
};
struct TargetExtra
{
};
extern TargetRef* DAT_011dea3c;
void __cdecl FUN_005e58f0(int, TargetRef*, ...);
void* __cdecl operator new(unsigned int);

struct MatchPoint
{
    float x, y, z;
    MatchPoint operator-(const MatchPoint&) const;
    float Length() const;
};

class List9AF
{
  public:
    void* GetFirst();
};

class Owner9AF
{
  public:
    List9AF* GetList();
    void* GetFirstListItem();
};

// Retrieves the list via GetList and returns its first element from GetFirst.
// @f3 0x006f0c90 (community match, verified in this file)
struct Owner9AFFields
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);

// pdb: TaskQueueInterface::ProcessQueue | TaskQueueInterface.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: SeenData::SaveGame)
void* Owner9AF::GetFirstListItem()
{
    Owner9AFFields* self = (Owner9AFFields*)this;
    self->unk08 = self->unk04;
    self->unk0c = (unsigned int)GetCurrentThreadId();
    List9AF* list = (List9AF*)self->unk00;
    void* first = list->GetFirst();
    self->unk0c = 0;
    return first;
}


struct List9af
{
    int GetSize();
    void*& GetAt(unsigned int idx);
};
struct Owner9af
{
    List9af* GetList();
};
struct PathPtr
{
    operator Owner9af*() const;
};

namespace fnv_009b00a0 {
struct Obj082;
struct List082;
struct Entry082
{
    Obj082* object;
    unsigned char unk04;
    unsigned char update;
    unsigned char skip;
};
struct List082
{
    bool FUN_008256d0();
    Entry082** FUN_006815c0();
    List082* FUN_00726070();
};
struct Vector082
{
    float x, y, z;
    Vector082 FUN_00439ef0(const Vector082*);
    float FUN_00457990();
    void FUN_0043d410(float, int, int);
};
struct Pair082
{
    float x, y;
    Pair082(float, float);
};
struct Curve082
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Apply(void*, int, void*, float, int);
};
struct Effect082
{
    int unk00, unk04, unk08;
    Curve082 curve;
};
struct Hit082
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    void FUN_009b4d90();
};
struct Obj082
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void Damage(float, int);
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void Update(Obj082*);
    virtual Obj082* GetSource();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual Obj082* GetNode();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual Vector082* Position();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool State(int);
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
    List082 hits;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    Obj082* impactSource;
    int unkcc;
    int unkd0;
    unsigned short unkD4;
    unsigned char processing;
    unsigned char unkD7;
    int unkd8;
    Effect082* effect;
    bool FUN_00477ba0();
    bool FUN_00440da0();
    float FUN_00644930();
    float FUN_008d01e0();
    Obj082* FUN_004181e0();
    Obj082* GetFieldC8();
    Obj082* GetFieldE0();
    float GetCachedValue();
    int FUN_00559450();
    int FUN_005d43c0();
    void CallProcessAt778();
    void SetEffectValue(int, float, int);
    bool FUN_009b1810(Vector082, Obj082*);
    void FUN_0089a760(Hit082*, int);
    void InitFromPoints(const Pair082&, const Pair082&, const Pair082&);
    bool HasAnyFlags(int);
    void FUN_009b0d70(Obj082*, float);
    Obj082* FUN_00950bb0(int);
    void FUN_00a59c60(Vector082*);
    void ProcessHits();
};
struct Setting082
{
    float* FUN_00403e20();
};
extern Obj082* DAT_011dea3c;
extern Setting082 DAT_011d0030, DAT_011d0490, DAT_011cfea0, DAT_011d0edc, DAT_011d0d38, DAT_011d00d8, DAT_011d05e0;
}  // namespace fnv_009b00a0

namespace fnv_009b2cb0 {

}  // namespace fnv_009b2cb0

struct WeaponHit
{
    int FormType();
    bool IsSpecial();
    int WeaponKind();
    unsigned char AmmoPerShot();
    bool Automatic();
    float DamageMult();
    bool IsMelee();
};
struct ValuesHit
{
    int Value(int);
    float FloatValue(int);
};
struct AnimHit
{
    unsigned short Group(int);
};
struct ActorHit
{
    virtual void virtual000();
    virtual void virtual004();
    virtual void virtual008();
    virtual void virtual00c();
    virtual void virtual010();
    virtual void virtual014();
    virtual void virtual018();
    virtual void virtual01c();
    virtual void virtual020();
    virtual void virtual024();
    virtual void virtual028();
    virtual void virtual02c();
    virtual void virtual030();
    virtual void virtual034();
    virtual void virtual038();
    virtual void virtual03c();
    virtual void virtual040();
    virtual void virtual044();
    virtual void virtual048();
    virtual void virtual04c();
    virtual void virtual050();
    virtual void virtual054();
    virtual void virtual058();
    virtual void virtual05c();
    virtual void virtual060();
    virtual void virtual064();
    virtual void virtual068();
    virtual void virtual06c();
    virtual void virtual070();
    virtual void virtual074();
    virtual void virtual078();
    virtual void virtual07c();
    virtual void virtual080();
    virtual void virtual084();
    virtual void virtual088();
    virtual void virtual08c();
    virtual void virtual090();
    virtual void virtual094();
    virtual void virtual098();
    virtual void virtual09c();
    virtual void virtual0a0();
    virtual void virtual0a4();
    virtual void virtual0a8();
    virtual void virtual0ac();
    virtual void virtual0b0();
    virtual void virtual0b4();
    virtual void virtual0b8();
    virtual void virtual0bc();
    virtual void virtual0c0();
    virtual void virtual0c4();
    virtual void virtual0c8();
    virtual void virtual0cc();
    virtual void virtual0d0();
    virtual void virtual0d4();
    virtual void virtual0d8();
    virtual void virtual0dc();
    virtual void virtual0e0();
    virtual void virtual0e4();
    virtual void virtual0e8();
    virtual void virtual0ec();
    virtual void virtual0f0();
    virtual void virtual0f4();
    virtual void virtual0f8();
    virtual void virtual0fc();
    virtual void virtual100();
    virtual void virtual104();
    virtual void virtual108();
    virtual void virtual10c();
    virtual void virtual110();
    virtual void virtual114();
    virtual void virtual118();
    virtual void virtual11c();
    virtual void virtual120();
    virtual void virtual124();
    virtual void virtual128();
    virtual void virtual12c();
    virtual void virtual130();
    virtual void virtual134();
    virtual void virtual138();
    virtual void virtual13c();
    virtual void virtual140();
    virtual void virtual144();
    virtual void virtual148();
    virtual void virtual14c();
    virtual void virtual150();
    virtual void virtual154();
    virtual void virtual158();
    virtual void virtual15c();
    virtual void virtual160();
    virtual void virtual164();
    virtual void virtual168();
    virtual void virtual16c();
    virtual void virtual170();
    virtual void virtual174();
    virtual void virtual178();
    virtual void virtual17c();
    virtual void virtual180();
    virtual void virtual184();
    virtual void virtual188();
    virtual void virtual18c();
    virtual void virtual190();
    virtual void virtual194();
    virtual void virtual198();
    virtual void virtual19c();
    virtual void virtual1a0();
    virtual void virtual1a4();
    virtual void virtual1a8();
    virtual void virtual1ac();
    virtual void virtual1b0();
    virtual void virtual1b4();
    virtual void virtual1b8();
    virtual void virtual1bc();
    virtual void virtual1c0();
    virtual void virtual1c4();
    virtual void virtual1c8();
    virtual void virtual1cc();
    virtual void virtual1d0();
    virtual void virtual1d4();
    virtual void virtual1d8();
    virtual void virtual1dc();
    virtual void virtual1e0();
    virtual AnimHit* Anim();
    virtual void virtual1e8();
    virtual void virtual1ec();
    virtual void virtual1f0();
    virtual void virtual1f4();
    virtual void virtual1f8();
    virtual void virtual1fc();
    virtual void virtual200();
    virtual void virtual204();
    virtual void virtual208();
    virtual void virtual20c();
    virtual void virtual210();
    virtual void virtual214();
    virtual void virtual218();
    virtual bool Creature();
    virtual void virtual220();
    virtual void virtual224();
    virtual void virtual228();
    virtual void virtual22c();
    virtual bool TargetFlag();
    virtual void virtual234();
    virtual void virtual238();
    virtual void virtual23c();
    virtual void virtual240();
    virtual void virtual244();
    virtual void virtual248();
    virtual void virtual24c();
    virtual void virtual250();
    virtual void virtual254();
    virtual void virtual258();
    virtual void virtual25c();
    virtual void virtual260();
    virtual void virtual264();
    virtual void virtual268();
    virtual void virtual26c();
    virtual void virtual270();
    virtual void virtual274();
    virtual void virtual278();
    virtual void virtual27c();
    virtual void virtual280();
    virtual void virtual284();
    virtual void virtual288();
    virtual void virtual28c();
    virtual void virtual290();
    virtual void virtual294();
    virtual void virtual298();
    virtual void virtual29c();
    virtual void virtual2a0();
    virtual void virtual2a4();
    virtual void virtual2a8();
    virtual void virtual2ac();
    virtual void virtual2b0();
    virtual void virtual2b4();
    virtual void virtual2b8();
    virtual void virtual2bc();
    virtual void virtual2c0();
    virtual void virtual2c4();
    virtual void virtual2c8();
    virtual void virtual2cc();
    virtual void virtual2d0();
    virtual void virtual2d4();
    virtual void virtual2d8();
    virtual void virtual2dc();
    virtual void virtual2e0();
    virtual void virtual2e4();
    virtual void virtual2e8();
    virtual void virtual2ec();
    virtual void virtual2f0();
    virtual void virtual2f4();
    virtual void virtual2f8();
    virtual void virtual2fc();
    virtual void virtual300();
    virtual void virtual304();
    virtual void virtual308();
    virtual void virtual30c();
    virtual void virtual310();
    virtual void virtual314();
    virtual void virtual318();
    virtual void virtual31c();
    virtual void virtual320();
    virtual void virtual324();
    virtual void virtual328();
    virtual void virtual32c();
    virtual void virtual330();
    virtual void virtual334();
    virtual void virtual338();
    virtual void virtual33c();
    virtual void virtual340();
    virtual void virtual344();
    virtual void virtual348();
    virtual void virtual34c();
    virtual void virtual350();
    virtual void virtual354();
    virtual void virtual358();
    virtual void virtual35c();
    virtual bool SpecialActor();
    virtual void virtual364();
    virtual void virtual368();
    virtual void virtual36c();
    virtual void virtual370();
    virtual void virtual374();
    virtual void virtual378();
    virtual void virtual37c();
    virtual void virtual380();
    virtual void virtual384();
    virtual void virtual388();
    virtual void virtual38c();
    virtual void virtual390();
    virtual void virtual394();
    virtual void virtual398();
    virtual void virtual39c();
    virtual void virtual3a0();
    virtual void virtual3a4();
    virtual void virtual3a8();
    virtual void virtual3ac();
    virtual void virtual3b0();
    virtual void virtual3b4();
    virtual void virtual3b8();
    virtual void virtual3bc();
    virtual void virtual3c0();
    virtual void virtual3c4();
    virtual void virtual3c8();
    virtual void virtual3cc();
    virtual void virtual3d0();
    virtual void virtual3d4();
    virtual void virtual3d8();
    virtual void virtual3dc();
    virtual void virtual3e0();
    virtual void virtual3e4();
    virtual void virtual3e8();
    virtual void virtual3ec();
    virtual void virtual3f0();
    virtual void virtual3f4();
    virtual void virtual3f8();
    virtual void virtual3fc();
    virtual void virtual400();
    virtual void virtual404();
    virtual void virtual408();
    virtual void virtual40c();
    virtual void virtual410();
    virtual void virtual414();
    virtual void virtual418();
    virtual void virtual41c();
    virtual void virtual420();
    virtual void virtual424();
    virtual void virtual428();
    virtual void virtual42c();
    virtual void virtual430();
    virtual void virtual434();
    virtual void virtual438();
    virtual void virtual43c();
    virtual void virtual440();
    virtual int CreatureDamage();
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
    ValuesHit values;
    bool Sneaking();
    float Scale();
    bool Teammate();
};
struct ExtraHit
{
    int type;
    bool active;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char count;
};
struct BooleanFloatQuery
{
    ActorHit* actor;
    ActorHit* target;
    int unk08;
    int kind;
    int unk10;
    float damage;
    int unk18;
    float secondary;
    int unk20;
    int unk24;
    int unk28;
    float special;
    WeaponHit* weapon;
    float condition;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    ExtraHit* extra;
    bool Flag(unsigned int);
    void Multiply(float);
    void Finish();
    void Update(int);
    void Finalize(int);
    void Complete();
};
struct SettingHit
{
    float* Float();
};
extern SettingHit DAT_011cf5d0, DAT_011d0424, DAT_011d12d8, DAT_011d07b4;

struct Pt9b : public NiPoint3
{
    Pt9b operator-(const NiPoint3& rhs) const;
    Pt9b& operator+=(const NiPoint3& rhs);
};

Pt9b __cdecl operator*(float f, const Pt9b& pt);

struct CTStamp
{
    int m_uiCommandId;
    CTStamp();
    CTStamp(float afValue);
};
struct CTList
{
    int unk00;
    int unk04;
    int unk08;
    CTList(int value);
    ~CTList();
};
struct CTPoint
{
    float x, y, z;
    CTPoint();
};

extern float DAT_0108e2b0;
struct TimeoutTimer
{
    int unk00;
    float unk04;
    CTStamp unk08;
    CTStamp unk0c;
    float unk10;
    CTList unk14;
    CTPoint unk20;
    CTStamp unk2c;
    TimeoutTimer(int a1, float a2, float a3, float a4, float a5);
    void FUN_009a4690(int a1, float a2, float a3, float a4, float a5, bool a6);
};

class AnimIdle
{
  public:
    void IncRefCount();
    void DecRefCount();
};

namespace FUN_004f15a0 {
class TESForm
{
  public:
    virtual ~TESForm();
    void SetFormType(ENUM_FORM_ID eType);
    int unk04, unk08, unk0C, unk10, unk14;
};
}

namespace hk9AAF {
class TESChildCell
{
  public:
    virtual void vfn_00();
};
}

namespace hkpHeightFieldAgent_createHeightFieldAAgent {
class Projectile : public FUN_004f15a0::TESForm, public hk9AAF::TESChildCell
{
  public:
    Projectile(bool bTempRef);
    virtual ~Projectile();
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48;
    int unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78;
    int unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    int unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8;
    int unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC, unk100, unk104, unk108;
    int unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C, unk130, unk134, unk138;
    int unk13C, unk140, unk144, unk148, unk14C;
};
}

namespace FUN_009aaff0 {
class ContinuousBeamProjectile : public hkpHeightFieldAgent_createHeightFieldAAgent::Projectile
{
  public:
    ContinuousBeamProjectile(bool bTempRef);
    virtual ~ContinuousBeamProjectile();

    NiPointer<AnimIdle> m_spUnk150;
};

}

namespace fnv_009b5a30 {
struct HitActor;
struct HitWeapon;
struct HitSetting
{
    const float* FUN_00403e20();
};
extern HitSetting DAT_011ced4c, DAT_011d1020, DAT_011d0be4, DAT_011cf0fc, DAT_011ce9f0;
struct HitAmmo
{
    int FUN_00923000();
};
struct HitEntry
{
    HitWeapon* FUN_0044ddc0();
    bool HasEffect(int);
};
struct HitProcess
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual HitEntry* Weapon();
};
struct HitValues
{
    virtual void v0();
    virtual void v1();
    virtual int Base(int);
    virtual float Current(int);
    float FUN_0066ef50(int);
};
struct HitMagic
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Invulnerable();
    int unk04, unk08, unk0c;
};
struct HitActor
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool Dead(int);
    virtual void v140();
    virtual bool Creature();
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
    HitMagic magic;
    HitValues values;
    bool FUN_00566950();
    bool FUN_00894d60();
    HitProcess* FUN_008d8520();
    void SetFieldE28(float);
    bool FUN_008a16d0();
};
struct HitClip
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned short Count();
};
struct HitWeapon
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
    HitClip clip;
    HitAmmo* Script_IsInListFunction(HitActor*);
    bool FUN_006450c0();
    int FUN_00446390();
    unsigned char FUN_00525b20(int, int, HitActor*);
    bool FUN_00524b40();
    int FUN_009b6600();
};
extern HitActor* DAT_011dea3c;
extern const double DAT_01017a40, DAT_0103c7c8, DAT_01012060, DAT_01012070;
double FUN_00404010(float, float);
HitWeapon* FUN_004839c0(int);
void FUN_005e58f0(int, HitActor*, HitWeapon*, HitActor*, float*);
void FUN_005e58f0(int, HitActor*, HitActor*, HitWeapon*, float*);
}  // namespace fnv_009b5a30
