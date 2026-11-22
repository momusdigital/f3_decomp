// fallout_shared/bgsdehydration.cpp: BGSDehydrationStage, BGSHungerStage, WaitableObject, TESForm and more (11 functions)
#include "f3_common.h"
#include "bgsdehydration_decls.h"
#include "bgsdehydration_types_BGSDehydrationStage.h"
#include "bgsdehydration_types_BGSHungerStage.h"
#define IsFormInitialized GetInitialized
#include <malloc.h>

class SpellItem : public TESForm
{
};
void __cdecl operator delete(void* pointer);

// Constructs a BGSDehydrationStage and sets its form type to 0x6e.
// @fnv 0x005a7160
BGSDehydrationStage::BGSDehydrationStage()
{
    SetFormType((ENUM_FORM_ID)0x6e);
}

// Scans stages up to DAT_011c3180 and returns the first stage whose GetMaxLevel() is <= level, or null.
// @fnv 0x004018b0
// @fnv 0x00401a10
BGSHungerStage::BGSHungerStage()
{
    SetFormType((ENUM_FORM_ID)0x77);
    ResetFormData();
}

// Returns the dehydration stage at index if index is below DAT_011c3180, otherwise returns null.
// @fnv 0x00401930
// Waits on the references handle and calls vfn_0004 when the wait succeeds without timeout.
// @fnv 0x00401970
// @fnv 0x004019d0
// @fnv 0x004013e0
// @fnv 0x004019f0
HungerStageData::HungerStageData()
{
    Reinitialize();
}
// @fnv 0x004019b0

struct Actor;
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CellMopp;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct InventoryChanges;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESBoundObject;
struct TESFaction;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
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

struct TESObjectLIGH
{
    bool FUN_0046f070();
    bool InvokeAction(unsigned int, unsigned int, bool, unsigned int, unsigned int);
    bool FUN_0050e4b0(unsigned int, unsigned int, bool, unsigned int, unsigned int);
};

struct TESObjectREFR
{
    virtual ~TESObjectREFR()
    {}
};
struct Actor : TESObjectREFR
{
};

namespace fnv_00551740 {
struct Actor;
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CellMopp;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct InventoryChanges;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct TESActorBase;
struct TESGlobal;
struct TESObject;
struct TESObjectCELL;
struct TESObjectREFR;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];

struct TESObjectCELL
{
    bool IsInterior();
    char* FUN_00451cb0();
};
}  // namespace fnv_00551740

struct Flt
{
    operator unsigned int() const;
};

namespace fnv_005fe0f0 {
struct TESIdleForm;
struct TESModel;
struct TESObjectREFR;

struct Flt
{
    operator unsigned int() const;
};
}  // namespace fnv_005fe0f0

namespace fnv_00618660 {
struct Actor;
struct DialogueTopicData;
struct DialogueItem;
struct FormRecordHeader;
struct QuestDialogueInfo;
struct TESObjectREFR;
struct TESQuest;
struct TESTopicInfo;
struct TopicInfoArray;
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct TESTopic : public TESForm, public TESFullName
{
    virtual void __vslot_10();
    static void BadQuestInfo(QuestDialogueInfo*);
    virtual bool Save(TESFile*);
    virtual void Save();
    virtual bool ReadTopicData(TESFile*);
    virtual bool Load(TESFile*);
    virtual void InitItem();
    virtual void ResetFormData();
    virtual bool CopyTopicData(FormRecordHeader*);
    virtual bool CopyTopicData(TESForm*);
    DialogueTopicData* GetData();
    int GetDialogueType();
    float GetPriority();
    void SetPriority(float);
    bool IsRemappedRumors();
    void SetRemappedRumors(bool);
    bool IsTopLevel();
    void SetTopLevel(bool);
    int GetDummyNodeState();
    void SetDummyNodeState(int);
    bool IsPersuasion();
    bool IsNonMenuTopic();
    void* GetQuestInfoList();
    TopicInfoArray* GetInfoArray(TESQuest*);
    TESTopicInfo* GetInfoByID(TESQuest*, unsigned int, bool);
    TESTopicInfo* GetInfoByID(unsigned int, bool);
    static TESTopicInfo* GetInfoByIndex(QuestDialogueInfo*, unsigned int);
    TESTopicInfo* GetInfoByIndex(TESQuest*, unsigned int);
    TESQuest* GetParentQuest(TESTopicInfo*);
    QuestDialogueInfo* GetQuestInfoForInfo(TESTopicInfo*);
    void* GetDummyPrompt();
    void SetDummyPrompt(char*);
    bool HasDummyPrompt();
    void RemoveQuestInfo(TESQuest*);
    static void RemoveQuestFromAllTopics(TESQuest*);
    bool HasQuest(void*, bool);
    bool HasQuest(TESQuest*, bool);
    static void CompactTopicInfos(TopicInfoArray*);
    void CompactTopicInfos(TESQuest*);
    bool InsertInfoAfter(TESQuest*, TESTopicInfo*, unsigned int);
    QuestDialogueInfo* GetQuestInfoForQuest(TESQuest*, bool);
    bool AddInfoToEnd(TESQuest*, TESTopicInfo*);
    TESTopicInfo* CreateInfoAtIndex(TESQuest*, int);
    static void AddDefaultTopics();
    static void RemoveDefaultTopics();
    static TESTopic* GetAudioBackendData(int, int);
    static TESTopic* GetTopicFromInfo(TESTopicInfo*);
    static void AlterOwner(TESTopicInfo*);
    static void UpdateTopic(TESTopic*, void*, bool);
    static bool CompareTopics(TESTopic*, TESTopic*, bool);
    static void ReorderTopics(bool, void*);
    bool SortQuests();
    static bool IsQuestValidForTopics(TESQuest*);
    virtual bool IsParentForm();
    virtual bool IsFormType(unsigned char);
    static bool IsFormTypeDialogueChild(unsigned char);
    static unsigned int GetDialogueTopicFlags(TESObjectREFR*, TESObjectREFR*, void*, TESTopic*);
    DialogueItem* CreateDialogueItem(TESObjectREFR*, TESObjectREFR*, TESTopic*, void*, bool);
    static TESTopicInfo* FindMatchingTopicInfo(void*, bool*, TESObjectREFR*, TESObjectREFR*, bool, TESTopic*, void*);
    TESTopicInfo* FindMatchingTopicInfo(bool*, TESObjectREFR*, TESObjectREFR*, bool, TESTopic*, void*);
    TESTopicInfo* FindMatchingTopicInfo(bool*, TESObjectREFR*, TESObjectREFR*);
    TESTopicInfo* FindMatchingTopicInfo(TESObjectREFR*, TESObjectREFR*);
    static TESTopicInfo* FindFollowupTopicInfo(TESTopicInfo*, bool*, TESObjectREFR*, TESObjectREFR*, bool, void*);
    static void ResetAllTopics();
    void ResetTopics();
    int GetJournalIndex();
    void SetJournalIndex(int);
    bool AddJournalEntry(int, Actor*);
    static void SetShowConversationStats(bool);
    static bool GetShowConversationStats();
    char m_Data[2];
    char _pad_26[2];
    float m_fTopicParamB;
    char m_kQuestInfoList[8];
    char m_kDummyPrompt[8];
    int m_iTopicFlags;
};
typedef char _sizecheck_TESTopic[sizeof(TESTopic) == 64 ? 1 : -1];

struct Flt
{
    operator unsigned int() const;
};
}  // namespace fnv_00618660

struct DH
{
    bool FUN_004226e0();
};

DH* g_dataHandler;

class FUN_00401150_cls
{
  public:
    void FUN_00401170();
    void FUN_00401150();
};

// @f3 0x0041ce60 (community match, verified in this file)
struct FUN_0086ba60_cls
{
    void FUN_0086ba60(void* p);
};
extern FUN_0086ba60_cls DAT_01090a78;
extern int DAT_00db582c;
extern int DAT_00db5760;

// pdb: ExtraLock::~ExtraLock | ExtraDataObjects.obj | fnv360_0822_retail, call_seq, high
void FUN_00401150_cls::FUN_00401150()
{
    void* p = *(void**)((char*)this + 0xc);
    *(int*)this = (int)&DAT_00db582c;
    DAT_01090a78.FUN_0086ba60(p);
    *(int*)this = (int)&DAT_00db5760;
}


class TESFaction : public TESForm
{
  public:
    bool IsHiddenFlagSet();
};

template <class T> class SettingT
{
  public:
    float* Float();
};

struct ActivationRef;
struct ActivationPosition
{
    float x;
    float y;
    float z;
};
struct ActivationAction
{
    void FUN_00496080(float);
};
struct ActivationProcess
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual bool CanActivate(ActivationRef*, int, int, int, int, int);
};
struct ActivationRef
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual bool IsActor();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual bool Activate(ActivationRef*, ActivationRef*, bool, int, int);
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual ActivationRef* GetActivationForm();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual void Slot94();
    virtual void Slot95();
    virtual void Slot96();
    virtual void Slot97();
    virtual void Slot98();
    virtual void Slot99();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual void Slot116();
    virtual void Slot117();
    virtual void Slot118();
    virtual void Slot119();
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual const ActivationPosition& Position();
    virtual void Slot126();
    virtual void Slot127();
    virtual void Slot128();
    virtual void Slot129();
    virtual void Slot130();
    virtual void Slot131();
    virtual void Slot132();
    virtual void Slot133();
    virtual bool IsForced();
    virtual void Slot135();
    virtual void Slot136();
    virtual void Slot137();
    virtual void Slot138();
    virtual void Slot139();
    virtual void Slot140();
    virtual void Slot141();
    virtual void Slot142();
    virtual void Slot143();
    virtual void Slot144();
    virtual void Slot145();
    virtual void Slot146();
    virtual void Slot147();
    virtual void Slot148();
    virtual void Slot149();
    virtual void Slot150();
    virtual void Slot151();
    virtual void Slot152();
    virtual void Slot153();
    virtual void Slot154();
    virtual void Slot155();
    virtual void Slot156();
    virtual void Slot157();
    virtual void Slot158();
    virtual void Slot159();
    virtual void Slot160();
    virtual void Slot161();
    virtual void Slot162();
    virtual void Slot163();
    virtual void Slot164();
    virtual void Slot165();
    virtual void Slot166();
    virtual void Slot167();
    virtual void Slot168();
    virtual void Slot169();
    virtual void Slot170();
    virtual void Slot171();
    virtual void Slot172();
    virtual void Slot173();
    virtual void Slot174();
    virtual void Slot175();
    virtual void Slot176();
    virtual void Slot177();
    virtual void Slot178();
    virtual void Slot179();
    virtual void Slot180();
    virtual void Slot181();
    virtual void Slot182();
    virtual void Slot183();
    virtual void Slot184();
    virtual void Slot185();
    virtual void Slot186();
    virtual void Slot187();
    virtual void Slot188();
    virtual void Slot189();
    virtual void Slot190();
    virtual void Slot191();
    virtual void Slot192();
    virtual void Slot193();
    virtual void Slot194();
    virtual void Slot195();
    virtual void Slot196();
    virtual void Slot197();
    virtual void Slot198();
    virtual void Slot199();
    virtual void Slot200();
    virtual void Slot201();
    virtual void Slot202();
    virtual void Slot203();
    virtual void Slot204();
    virtual void Slot205();
    virtual void Slot206();
    virtual void Slot207();
    virtual void Slot208();
    virtual void Slot209();
    virtual void Slot210();
    virtual void Slot211();
    virtual void Slot212();
    virtual void Slot213();
    virtual void Slot214();
    virtual void Slot215();
    virtual void Slot216();
    virtual void Slot217();
    virtual void Slot218();
    virtual void Slot219();
    virtual void Slot220();
    virtual void Slot221();
    virtual void Slot222();
    virtual void Slot223();
    virtual float GroundOffset();
    float FUN_008be940();
    ActivationProcess* FUN_008d8520();
    void SetByteAt79a(bool);
    ActivationAction* FUN_00950a60(int, int);
    bool ActivateWithActorCheck(ActivationRef*, ActivationRef*, bool, int, int);
};
extern ActivationRef* DAT_011dea3c;
void FUN_00600900(ActivationRef*);
void FUN_00600940(int);
void FUN_00600920(int);

struct PackageLike
{
    int GetPackType();
};

struct ExtraHolder
{
    int unk00;
    int unk04;
    int unk08;
    struct ActorLike* unk0C;
};

struct ExtraListLike
{
    ExtraHolder* GetHolder();
    void Attach(void* apOwner, struct RefLike* apRef);
};

struct RefLike
{
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void SetFlag(unsigned int auiFlag);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual bool IsActor();
    virtual bool IsBaseForm();
    ExtraListLike* GetExtraList();
    RefLike* GetBaseForm();
};

struct ActorLike : RefLike
{
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
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
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void StartConversation(RefLike* apTarget, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
    PackageLike* GetCurrentPackage();
};

extern float DAT_010162c0;

bool QueueUIMessage(const char* apText, int aiIcon, const char* apSound, const char* apUnk, float afTime, bool abUnk);
void FUN_00709470(int a1, int a2, int a3, int a4, int a5, int a6);

namespace fnv_00508a40 {
class Script
{
  public:
    ScriptLocals* FUN_005abf60();
    bool FUN_005ac1e0(TESObjectREFR*, ScriptLocals*, TESObjectREFR*, bool);
};
struct ExtraDataList
{
    int head;
    int tail;
    int flags;
    int presence;
    int data10;
    int data14;
    int data18;
    int data1c;
    ExtraDataList();
    void FUN_00419ad0(unsigned short);
    Script* FUN_00418800();
    void FUN_00419ed0(Script*);
    void FUN_00419f80(ScriptLocals*);
    ScriptLocals* FUN_00418830();
};
struct FUN_0055a2f0 : TESObjectREFR
{
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
    FUN_0055a2f0();
};
struct NameComponent
{
    const char* FUN_00408da0();
};
struct Topic : TESForm
{
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    NameComponent name;
};
struct TopicInfo
{
    bool FUN_00508d70();
    void FUN_00484580(bool);
};
struct Script* FUN_004826d0(Topic*);
unsigned int DialogueRandom();
struct CalendarView
{
    int FUN_00867ca0();
};
extern "C" CalendarView DAT_011de7b8;
struct SettingView
{
    const char* FUN_00403df0();
};
extern "C" SettingView DAT_011c856c;
extern "C" SettingView DAT_011c8590;
extern "C" Actor* DAT_011dea3c;
struct ActorActions : Actor
{
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void slot3d();
    virtual void slot3e();
    virtual void slot3f();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot4a();
    virtual void slot4b();
    virtual void slot4c();
    virtual void slot4d();
    virtual void slot4e();
    virtual void slot4f();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot5a();
    virtual void slot5b();
    virtual void slot5c();
    virtual void slot5d();
    virtual void slot5e();
    virtual void slot5f();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void AddTopic(Topic*, ExtraDataList*, bool);
    void FUN_00574fa0(Topic*, int, bool);
};
struct GlobalObject_0041a250
{
    unsigned int id;
    unsigned int state;
    unsigned int message;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    void FUN_00418900(const GlobalObject_0041a250&);
    bool FUN_00ad8830(bool);
};
struct BSAudio
{
    static BSAudio* FUN_00453a70();
    GlobalObject_0041a250 FUN_00ad7550(const char*, unsigned int);
};
int FUN_00406f60(BSStringT<char>*, const char*, ...);
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
void FUN_00706f30(int);
struct Action
{
    int state;
    bool TryAddTopic(TopicInfo*, TESObjectREFR*, int, int, int);
};
struct Prefix
{
    int unk00;
    int unk04;
    int unk08;
};
struct TopicAction : Prefix
{
    Action action;
    Topic* FUN_00726070();
    unsigned char FUN_00508d90(int);
};
// Checks the TopicInfo and actor, rolls a dialogue chance, adds the topic to the actor and queues a message when the actor is the player.
// @fnv 0x00508a40
bool Action::TryAddTopic(TopicInfo* pTopicInfo, TESObjectREFR* reference, int arg3, int arg4, int arg5)
{
    Actor* actor = dynamic_cast<Actor*>(reference);
    if (pTopicInfo && actor)
    {
        bool success = false;
        if (!pTopicInfo->FUN_00508d70() &&
            reinterpret_cast<TopicAction*>(reinterpret_cast<char*>(this) - offsetof(TopicAction, action))
                ->FUN_00726070())
        {
            unsigned char chance =
                reinterpret_cast<TopicAction*>(reinterpret_cast<char*>(this) - offsetof(TopicAction, action))
                    ->FUN_00508d90(DAT_011de7b8.FUN_00867ca0());
            if (chance > 0 && DialogueRandom() % 100 < chance)
                success = true;
        }
        if (success)
        {
            Topic* script =
                reinterpret_cast<TopicAction*>(reinterpret_cast<char*>(this) - offsetof(TopicAction, action))
                    ->FUN_00726070();
            Script* pScript = FUN_004826d0(script);
            if (pScript)
            {
                ExtraDataList* extra = 0;
                extra = new ExtraDataList;
                extra->FUN_00419ad0(1);
                if (extra && !extra->FUN_00418800())
                {
                    extra->FUN_00419ed0(pScript);
                    extra->FUN_00419f80(extra->FUN_00418800()->FUN_005abf60());
                    TESObjectREFR* temporary = new FUN_0055a2f0;
                    pScript->FUN_005ac1e0(temporary, extra->FUN_00418830(), 0, false);
                }
                reinterpret_cast<ActorActions*>(actor)->AddTopic(script, extra, true);
            }
            else
            {
                reinterpret_cast<ActorActions*>(actor)->FUN_00574fa0(script, 0, true);
            }
            if (actor == DAT_011dea3c)
            {
                BSStringT<char> sound;
                FUN_00406f60(&sound, DAT_011c856c.FUN_00403df0(), script->name.FUN_00408da0());
                QueueUIMessage(sound.String(), 0, 0, 0, 2.0f, false);
                GlobalObject_0041a250 message;
                message.FUN_00418900(BSAudio::FUN_00453a70()->FUN_00ad7550("ITMPickupOrganic", 0x120));
                message.FUN_00ad8830(false);
            }
        }
        else if (actor == DAT_011dea3c)
        {
            QueueUIMessage(DAT_011c8590.FUN_00403df0(), 0, 0, 0, 2.0f, false);
            FUN_00706f30(29);
        }
        pTopicInfo->FUN_00484580(true);
    }
    return true;
}
}  // namespace fnv_00508a40

struct GlobalObject_0040c150
{
    const char* FUN_00403df0();
};
extern GlobalObject_0040c150 g_011d2898, g_011d20ac, g_011d421c, g_011d384c, g_011d252c, g_011d1e0c;
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);

namespace fnv_00516dc0 {
struct ActivateActor;
struct ActivateReference;
struct LockScript
{
    int FUN_004309e0(ActivateReference*);
    bool FUN_00430ae0();
};
struct ActivateExtra
{
    int unk00, unk04, unk08;
    LockScript* script;
    void FUN_00517360();
};
struct KeyName
{
    const char* FUN_00408da0();
};
struct ActivateKey
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

    KeyName name;
};
struct ActivateLock
{
    int unk00;
    ActivateKey* key;
    bool FUN_005021a0();
};
struct ActivateAnimation
{
    void FUN_00498910(int, int);
};
struct ActivatePoint
{
    float x, y, z;
};
struct ActivateReference
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void Activate(int, int, int, int, int, ActivateActor*, int, int, int, int);
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void* GetScene();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual ActivatePoint* GetPosition();
    bool FUN_005785e0(ActivateActor*, bool);
    ActivateLock* FUN_00569160();
    ActivateExtra* FUN_005691f0();
    void FUN_005789b0();
    void FUN_00573170(ActivateActor*, int, int, int);
    void* FUN_00567790();
};
struct ActivateActorAction
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void Action(ActivateActor*, int, int, int, int, int);
};
struct ActivateActor
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual ActivateAnimation* GetAnimation();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual bool IsActor();
    bool FUN_00891db0(ActivateKey*, int, int, int, int*);
    ActivateActorAction* FUN_008d8520();
    void FUN_008bfa40(ActivateReference*, int, int, int, int);
};
struct BSSoundHandleEx
{
    int unk00, unk04, unk08;
    ~BSSoundHandleEx();
    bool Play(bool);
    bool FUN_00ad8b60(float, float, float);
};
struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
    BSSoundHandleEx FUN_00ad73b0(unsigned int, unsigned int);
};
BSAudio* FUN_00453a70();
struct ActivateMessage
{
    const char* FUN_00403df0();
};
extern ActivateMessage DAT_011d5110, DAT_011d276c;
extern ActivateActor* DAT_011dea3c;
extern char DAT_0102b13c[], DAT_0102b108[], DAT_0102b0d0[];
extern float DAT_010162c0;
void DispatchMessageToSink(const char*, int, const char*, int, float, int);
void FUN_005e58f0(int, ActivateActor*, float*);
void FUN_00600900(ActivateKey*);
void FUN_00600940(int);
void FUN_00600920(int);
int GridCellArray_Set(ActivateReference*);
void FUN_0047a560(ActivateReference*, ActivateActor*, int);

}  // namespace fnv_00516dc0

template <int N> struct SlotTag
{
};
template <int N> struct VSlots : VSlots<N - 1>
{
    virtual void unused(SlotTag<N>*);
};
template <> struct VSlots<0>
{
};
void FUN_0047a560(ActivationRef*, ActivationRef*, int);
int GridCellArray_Set(ActivationRef*);

struct TESBoundObject
{
    virtual void vfn00();
};
struct TESPackage
{
    virtual void vfn00();
};

struct AAPoint
{
    float x, y, z;
};
class AAActor;
struct AAFaction
{
    bool FUN_0097fa10(AAActor* pkActorVal);
};
struct AAIdle
{
    unsigned char unk00[14];
    unsigned char m_ucType;
};  // +0x0e
struct AAEntry
{
    int FUN_0041ca90();
    bool FUN_00670f90();
};
struct AAPackageNode
{
    void* FUN_00726070();
};
struct AAPackageData
{
    int FUN_0041ca90();
    AAPackageNode* FUN_0041d8a0();
};
struct AAInventory
{
    AAEntry* FUN_0041cb10();
    int FUN_0041cb70(int iA, int iB, int iC);
    void FUN_0041c930(AAEntry* pkEntryCur, int iA, int iCount);
};

class AAProcess
{
  public:
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
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual bool IsArrested();
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
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
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
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
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
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual AAPackageData* GetPackageData();
    virtual void v280();
    virtual void v284();
    virtual void SetConversationState(AAActor* pkActorVal, int iState);
    virtual void v28c();
    virtual void v290();
    virtual void StopIdle(AAActor* pkActorVal);
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void SetDialogueActor(AAActor* pkSpeaker, AAActor* pkTarget, int iA, int iB, int iC, int iD, int iE, int iF,
                                  int iG, int iH, int iI, int iJ, int iK);
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual bool CanTalkTo(AAActor* pkActorVal);
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual int GetMovementState();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual AAIdle* GetCurrentIdle();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual int StopIdleAnimation();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void GiveItem(AAActor* pkActorVal, AAEntry* pkEntryCur);
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual int GetQueuedFurniture();
};

struct AAAnimData
{
    void FUN_00815b00();
};
struct AAValueHolder
{
    int unk00[12];
    struct AAValues
    {
        virtual void v000();
        virtual void v004();
        virtual void v008();
        virtual void v00c();
        virtual void v010();
        virtual void v014();
        virtual void v018();
        virtual bool IsEssential();
    } m_kValues;
};  // +0x30

class AAActor
{
  public:
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
    virtual void SetFlag(unsigned int uiFlag);
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
    virtual void v100();
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
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void ActivateItem(TESBoundObject* pkObject, int iA, int iCount, int iB, int iC, AAActor* pkActivator,
                              int iD, int iE, int iF, int iG);
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
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const AAPoint& GetPos();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual int GetSitSleepState();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool IsDead(int iFlag);
    virtual bool IsIncapacitated();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual bool StartConversation(AAActor* pkTarget, int iA, int iB, int iC, int iD, int iE, int iF, int iG, int iH);
    virtual void v284();
    virtual void v288();
    virtual void TakeItem(AAEntry* pkEntryCur, bool bFlag);
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual AAActor* GetCurrentTalkTarget();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual bool IsInCombat();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual AAFaction* GetCrimeFaction();
    int unk[33];
    AAAnimData m_kAnim;  // +0x88

    AAProcess* FUN_008d8520();
    AAInventory* FUN_005d43c0();
    bool FUN_00437bd0();
    int FUN_004f8960();
    const char* FUN_0055d520();
    bool FUN_008a6650(int iFlag);
    bool FUN_00894d60();
    bool IsHostileTo(AAActor* pkTarget, int iA, int* piTopic, int iB);
    bool FUN_0087f3d0();
    AAValueHolder* FUN_004181e0();
    bool FUN_00493bb0();
    bool FUN_004997b0();
    bool FUN_00566950();
    bool FUN_008ace90();
    bool FUN_00898ff0();
    void StartDialog(void* pkSceneVal, int iA, int iB);
    bool FUN_008b3bb0();
    void FUN_008a8e50();
    void FUN_008a7a90();
    TESPackage* FUN_009344a0();
    void FUN_008bb520(AAPoint kPos, int iFlag);
    bool FUN_009336c0();
};

struct AAMenuMode
{
    bool FUN_00867d60();
};
struct AASound
{
    void FUN_00ad8780(int iFlag);
};

extern AAMenuMode DAT_011de7b8;

AASound* FUN_00453a70();
void DispatchMessageToSink(const char* pcText, int iA, const char* pcIcon, const char* pcSound, float fTime, int iB);
void FUN_00709470(int iType, void* pkTarget, int iA, int iB, int iC, int iD);

static const char s_szNameFormat[] = "%s %s";
static const char s_szSadIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds";
static const char s_szSurprisedIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds";

struct S_005805c0_Object;

struct S_005805c0_Arg
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual void v050() = 0;
    virtual void v051() = 0;
    virtual void v052() = 0;
    virtual void v053() = 0;
    virtual void v054() = 0;
    virtual void v055() = 0;
    virtual void v056() = 0;
    virtual void v057() = 0;
    virtual void v058() = 0;
    virtual void v059() = 0;
    virtual void v060() = 0;
    virtual void v061() = 0;
    virtual void v062() = 0;
    virtual void v063() = 0;
    virtual bool v100() = 0;
    virtual void v101() = 0;
    virtual void v066() = 0;
    virtual void v067() = 0;
    virtual void v068() = 0;
    virtual void v069() = 0;
    virtual void v070() = 0;
    virtual void v071() = 0;
    virtual void v072() = 0;
    virtual void v073() = 0;
    virtual void v074() = 0;
    virtual void v075() = 0;
    virtual void v076() = 0;
    virtual void v077() = 0;
    virtual void v078() = 0;
    virtual void v079() = 0;
    virtual void v080() = 0;
    virtual void v081() = 0;
    virtual void v082() = 0;
    virtual void v083() = 0;
    virtual void v084() = 0;
    virtual void v085() = 0;
    virtual void v086() = 0;
    virtual void v087() = 0;
    virtual void v088() = 0;
    virtual void v089() = 0;
    virtual void v090() = 0;
    virtual void v091() = 0;
    virtual void v092() = 0;
    virtual void v093() = 0;
    virtual void v094() = 0;
    virtual void v095() = 0;
    virtual void v096() = 0;
    virtual void v097() = 0;
    virtual void v098() = 0;
    virtual void v099() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual S_005805c0_Object* v198() = 0;
};

struct S_005805c0_Object
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003(StageRecordData* stageData, int value08, int value0c, float value10, int value14) = 0;
};

void __cdecl FUN_005e58f0(int value, S_005805c0_Arg* object, float* amount);
