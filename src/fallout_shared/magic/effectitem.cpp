// fallout_shared/magic/effectitem.cpp: EffectItem, EffectItemList, ScriptEffect, Setting and more (2 functions)
#include "f3_common.h"
#include "effectitem_decls.h"

// @f3 0x006f7fa0 (community match, verified in this file)
struct FUN_0045e360_cls
{
    bool FUN_0045e360();
};
struct FUN_006f7fa0_obj
{
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00c();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01c();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02c();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03c();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04c();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05c();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06c();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07c();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08c();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09c();
    virtual void vfn0a0();
    virtual void vfn0a4();
    virtual void vfn0a8();
    virtual void vfn0ac();
    virtual void vfn0b0();
    virtual void vfn0b4();
    virtual void vfn0b8();
    virtual void vfn0bc();
    virtual void vfn0c0();
    virtual void vfn0c4();
    virtual void vfn0c8();
    virtual void vfn0cc();
    virtual void vfn0d0();
    virtual void vfn0d4();
    virtual void vfn0d8();
    virtual void vfn0dc();
    virtual void vfn0e0();
    virtual void vfn0e4();
    virtual void vfn0e8();
    virtual void vfn0ec();
    virtual void vfn0f0();
    virtual void vfn0f4();
    virtual void vfn0f8();
    virtual void vfn0fc();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10c();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11c();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12c();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13c();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14c();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15c();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16c();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17c();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18c();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19c();
    virtual void vfn1a0();
    virtual void vfn1a4();
    virtual void vfn1a8();
    virtual void vfn1ac();
    virtual void vfn1b0();
    virtual void vfn1b4();
    virtual void vfn1b8();
    virtual void vfn1bc();
    virtual void vfn1c0();
    virtual void vfn1c4();
    virtual void vfn1c8();
    virtual void vfn1cc();
    virtual void vfn1d0();
    virtual void vfn1d4();
    virtual void vfn1d8();
    virtual void vfn1dc();
    virtual void vfn1e0();
    virtual FUN_0045e360_cls* vfn1e4(int aValue);
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
    unsigned char unk0e4;
    unsigned char unk0e5;
};

// pdb: Actor::FlushReloadTargetQueque | Actor.obj | fnv360_0822_retail, call_gap, low
bool EffectItem::IsHostile()
{
    FUN_006f7fa0_obj* pObject = (FUN_006f7fa0_obj*)this;
    int iValue = pObject->unk0e5;
    bool bResult = pObject->vfn1e4(iValue)->FUN_0045e360();
    pObject->unk0e5 = 0;
    return bResult;
}


// Constructs a ScriptEffect from caster, item and effect, initializing the base ActiveEffect and storing the effect's script with unknown set to 0.
// @fnv 0x00827740
ScriptEffect::ScriptEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect)
    : ActiveEffect(caster, item, effect)
{
    script = effect->GetScript();
    unknown = 0;
}

struct MagicEffectSystem
{
    static bool __cdecl IsFlagSet(int, unsigned int);
};

struct Actor;
struct MagicCaster;
struct MagicItem;
struct TESObjectCELL;
struct TESObjectREFR;
struct blob12
{
    char b[12];
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
typedef char _sizecheck_CachedValuesOwner[sizeof(CachedValuesOwner) == 4 ? 1 : -1];

namespace fnv_004045e0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESObjectREFR;

__pragma(comment(
    linker, "/alternatename:?EffectSetting_GetArchetype@@YIHPAUEffectSetting@@@Z=?GetArchetype@EffectSetting@@QAEHXZ"))
    __pragma(comment(
        linker,
        "/alternatename:?EffectSetting_GetArchetype@@YIHAAVEffectSetting@@@Z=?GetArchetype@EffectSetting@@QAEHXZ"))

        class MagicEffectSystem
{
  public:
    struct _Type
    {
        enum Type
        {
        };
    };
    static bool __cdecl IsFlagSet(_Type::Type, unsigned int);
};

}  // namespace fnv_004045e0

struct S4eb0
{
    int a;
    unsigned int b;
    int c;
    void FUN_00404f00(int, bool, char*, int);
    S4eb0* FUN_00404eb0(int, bool, char*, int);
};

struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];

void __cdecl FUN_00404f30(int);

namespace fnv_00404f70 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];

void __cdecl FUN_00404f30(int);

}  // namespace fnv_00404f70

namespace fnv_005f5f80 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESObjectREFR;
struct blob12
{
    char b[12];
};

}  // namespace fnv_005f5f80

extern "C" int __tls_index;

__declspec(thread) int DAT_tls_field = 0x3b;

struct MagicCaster;

namespace fnv_00404f30 {
extern "C" unsigned int __tls_index;

__declspec(thread) int tlsVar[0x2b4 / 4 + 1];

}  // namespace fnv_00404f30

struct Setting
{
    void FUN_00404950();
    void* FUN_004049a0(unsigned int);
};
void __cdecl _Deallocate(void*);

void _Deallocate(void*);

namespace fnv_00404fd0 {

template <class T> struct NiTPrimitiveArray
{
};

struct Setting
{
    void FUN_00c33280(NiTPrimitiveArray<char*>*);
};

template <class T> struct SettingCollectionMap
{
    unsigned int FUN_00404fd0(NiTPrimitiveArray<char*>*);
};

int _data_011c16bc;

}  // namespace fnv_00404fd0

extern float DAT_01012054;

namespace fnv_00404560 {
extern const float DAT_01012054;

}  // namespace fnv_00404560

extern "C" void __fastcall FUN_00404ee0(S4eb0*);
struct ScopedContext
{
    int previousContext;
    __forceinline ScopedContext(int context, bool temporary, char* file, int line)
    {
        reinterpret_cast<S4eb0*>(this)->FUN_00404eb0(context, temporary, file, line);
    }
    __forceinline ~ScopedContext()
    {
        FUN_00404ee0(reinterpret_cast<S4eb0*>(this));
    }
};
