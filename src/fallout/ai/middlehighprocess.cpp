// fallout/ai/middlehighprocess.cpp: MiddleHighProcess, FurnitureProcess, MiddleHighProcessStandIn, ActorPackage_GetTarget_Helper and more (1 function)
#include "f3_common.h"
#include "middlehighprocess_decls.h"

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESForm;
struct TESObjectREFR;
struct PackageTargetRecord
{
    int GetTargetKind();
    TESForm* GetTargetForm();
    int GetTargetObjectType();
    int GetTargValue();
    float GetTargAcquireRadius();
    void SetTargetKind(int);
    void SetTargetObjectReference(TESObjectREFR*);
    void SetTargObject(TESForm*);
    void SetTargObjectType(int);
    void SetTargValue(int);
    void SetTargAcquireRadius(float);
    bool GetIsValidTarget(TESForm*);
    void Copy(PackageTargetRecord*);
    bool Compare(PackageTargetRecord*);
    void Save(int);
    void InitItem(TESForm*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    TESObjectREFR* GetReferenceTarget();
    void* __vecDelDtor(unsigned int);
    unsigned char m_uiTargetType;
    char _pad_1[3];
    int eObjType;
    int iValue;
    float m_fTargetValue;
};
typedef char _sizecheck_PackageTarget[sizeof(PackageTargetRecord) == 16 ? 1 : -1];

struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
struct DH
{
    bool FUN_004226e0();
};
struct TESObjectREFRHelper
{
    void SetMarkerState(unsigned char a, bool b);
    void SetMarkerState(int a, bool b);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern DH* g_dataHandler;

void __fastcall FUN_00483710(void*);
void __fastcall FUN_00914b40(void*);

struct Actor;
struct ActorCause;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct DialogueResponse;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

namespace fnv_0091e830 {
struct Actor;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct GuardActorPackageData;
struct HighProcess;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiControllerManager;
struct NiNode;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct TESActorBase;
struct TESBoundObject;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct bhkSimpleShapePhantom;
struct blob12
{
    char b[12];
};

extern NiNode* DAT_011e0410;
struct PlayerCharacter;
extern PlayerCharacter* pPlayer;

struct NiFixedString
{
    char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};

struct NiAVObjectPalette
{
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
    virtual NiNode* FindAVObject(const NiFixedString& kName);
};

struct NiControllerManager
{
    NiAVObjectPalette* GetStringAtOffset();
};

struct Animation
{
    NiControllerManager* FUN_00496940();
    NiNode* GetControllerSequence();
};

struct PlayerCharacter
{
    Animation* GetAnimation(bool);
};

struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, const char*);
};

}  // namespace fnv_0091e830

namespace fnv_0091e9f0 {
struct Actor;
struct ActorValueStore;
struct ActorValueOwner;
struct AlchemyItem;
struct AnimIdle;
struct Animation;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct ExtraDataList;
struct ExtraLeveledItem;
struct GuardActorPackageData;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiNode;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESBoundObject;
struct TESForm;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct bhkSimpleShapePhantom;
struct blob12
{
    char b[12];
};

struct InventoryStackRecord
{
    ~InventoryStackRecord();
};

}  // namespace fnv_0091e9f0

namespace fnv_0091eb20 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSIdleCollection;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct DurationData;
struct PackageTargetRecord;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESContainer;
struct TESEscortPackageData;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESPackageData;
struct TESPatrolPackageData;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESUseWeaponPackageData;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

struct TESForm
{
    bool IsDeleted() const;
};

struct TESObjectREFR : public TESForm
{
};

struct PackageTargetRecord
{
    TESObjectREFR* GetReferenceTarget();
};

struct TESPackage
{
    PackageTargetRecord* GetTarget();
};

}  // namespace fnv_0091eb20

namespace fnv_0091ebb0 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSIdleCollection;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct DurationData;
struct PackageTargetRecord;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESContainer;
struct TESEscortPackageData;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESPackageData;
struct TESPatrolPackageData;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESUseWeaponPackageData;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

struct TESPackage
{
    TESObjectREFR* GetResolvedTargetReference(MobileObject*);
};

}  // namespace fnv_0091ebb0

namespace fnv_0091ec20 {
struct Actor;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct GuardActorPackageData;
struct HighProcess;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiNode;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct TESActorBase;
struct TESBoundObject;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct bhkSimpleShapePhantom;
struct blob12
{
    char b[12];
};

}  // namespace fnv_0091ec20

namespace fnv_0091ec70 {
struct Actor;
struct ActorPackageData;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct GuardActorPackageData;
struct HighProcess;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiNode;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct TESActorBase;
struct TESBoundObject;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct bhkSimpleShapePhantom;
struct blob12
{
    char b[12];
};

}  // namespace fnv_0091ec70

namespace fnv_0091ecb0 {
struct Actor;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct GuardActorPackageData;
struct HighProcess;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiNode;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct TESActorBase;
struct TESBoundObject;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct bhkSimpleShapePhantom;
struct blob12
{
    char b[12];
};

}  // namespace fnv_0091ecb0

namespace fnv_0091ee70 {
struct Actor;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct GuardActorPackageData;
struct HighProcess;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiNode;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct TESActorBase;
struct TESBoundObject;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct bhkSimpleShapePhantom;
struct blob12
{
    char b[12];
};

struct ActorPackage_Clear
{
    void Clear()
    {
        ((void(__thiscall*)(ActorPackage_Clear*))0)(this);
    }
};

}  // namespace fnv_0091ee70

namespace fnv_0091eec0 {
struct Actor;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct GuardActorPackageData;
struct HighProcess;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiNode;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct TESActorBase;
struct TESBoundObject;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct bhkSimpleShapePhantom;
struct blob12
{
    char b[12];
};

}  // namespace fnv_0091eec0

namespace fnv_0091ef10 {
struct Actor;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct BGSIdleCollection;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct BaseFormComponent;
struct CHUNK;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct HighProcess;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiColor;
struct NiNode;
struct LocationDescriptor;
struct DurationData;
struct PackageTargetRecord;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct Script;
struct TESActorBase;
struct TESBoundObject;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESEscortPackageData;
struct TESFile;
struct TESForm;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESPackageData;
struct TESPatrolPackageData;
struct TESTopic;
struct TESUseWeaponPackageData;
struct TESWorldSpace;
struct bhkSimpleShapePhantom;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};

int __cdecl FUN_0096a820(int);

struct Calendar
{
    unsigned int GetDaysPassed(void);
};

}  // namespace fnv_0091ef10

struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct FindData;
struct KFModel;
struct NiAVObject;
struct NiControllerManager;
struct NiControllerSequence;
struct NiNode;
struct TESAnimGroup;
struct TESIdleForm;
struct TESObjectREFR;
struct Animation
{
    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    NiNode* GetAnimNode();
    NiNode* GetAccumRoot();
    void* GetAnimSequenceMap();
    float GetSmallestHavokBlendValue(NiNode*);
    NiControllerManager* GetControllerManager();
    void RemoveObject(NiAVObject*);
    float GetTime();
    float GetTime(NiControllerSequence*);
    void SetTime(float);
    static void SetLipTime(float, NiControllerManager*, NiControllerSequence*);
    void SetLipTime(float);
    bool Init(void*, NiNode*, TESObjectREFR*, bool);
    void SetAnimationName(void*, char*);
    void SetAnimationOwner(void*);
    void QueueReloadAnim(unsigned short);
    bool ReloadAnimQueued();
    bool AddAnimation(KFModel*, bool);
    bool IsAnimationLoaded();
    void SetReloadState(bool);
    void BlendOut(int, bool);
    static float GetDuration(NiControllerSequence*);
    static float GetDuration(NiNode*, float*, float*);
    float GetDuration();
    void SetLookingDir(float);
    void SkipUpdate(int);
    void Update(TESObjectREFR*, float, float);
    void UpdateMovement(TESObjectREFR*);
    void UpdateActorAnimation(TESObjectREFR*);
    bool UpdateQueuedScenegraph();
    bool GetMovementDelta(NiPoint3*, TESObjectREFR*, bool, bool);
    void ClearDelta();
    bool IsGroupQueued(unsigned short);
    void ClearGroup(int, float);
    unsigned short GetQueuedGroup(int);
    void ClearBlendInterps();
    static void ClearBlendInterpsCallback(NiAVObject*);
    void SetAnimationGroup(TESAnimGroup*);
    short GetGroupSection(unsigned short);
    void UpdateBipOnly(float, NiPoint3*, bool);
    void RefreshAnimation();
    void SetMoveSpeed(float);
    float GetMoveSpeed();
    void SetAttackSpeed(float);
    float GetAttackSpeedModifier();
    void AddGroup(TESAnimGroup*);
    BSAnimGroupSequence* PlayGroup(BSAnimGroupSequence*, int, int, int);
    BSAnimGroupSequence* PlayGroup(unsigned short, int, int, int);
    BSAnimGroupSequence* SyncSequences(BSAnimGroupSequence*, unsigned short);
    unsigned short PickBestAnimation(unsigned short, bool);
    bool ShouldBeMoving();
    BSAnimGroupSequence* GetCurrentSequence(int);
    unsigned short GetGroup(int);
    int GetGroupAction(int);
    BSAnimGroupSequence* GetFirstActiveSequence();
    BSAnimGroupSequence* GetNextActiveSequence(BSAnimGroupSequence*);
    void SetCurrentSequence(int, BSAnimGroupSequence*);
    void VerifyUniqueControllerPriorities(NiNode*);
    static bool StripAllBSKeyframeControllers(NiAVObject*);
    bool SwapSequences(int);
    char GetNextNoteKey(float*);
    int FindNoteKey(int, char*, float*);
    char FindNextNoteKey(int, char*, float*);
    void ForceSection(int, unsigned short, int, float, char);
    void ClearForcedSection();
    TESAnimGroup* GetAnimGroupByID(unsigned short);
    bool AreAnimationsLoaded();
    unsigned int GetAnimsLoadingCount();
    void QueueReplacementAnimation(KFModel*);
    void SetLoopCount(int, int);
    void SpecialIdleQueue(TESIdleForm*, int);
    void PlaySpecialIdle(TESIdleForm*, Actor*, int, int);
    bool SpecialIdleReplace();
    void SpecialIdleReplace(TESIdleForm*, Actor*, int);
    bool CanReplaceSpecialIdle();
    bool CanReplaceSpecialIdle(Actor*);
    bool IsSpecialIdlePlaying();
    bool IsSpecialIdlePlaying(TESIdleForm*);
    bool IsSpecialIdlePlaying(BSAnimGroupSequence*);
    bool SpecialIdleLoaded();
    bool IsSpecialIdleReady();
    bool IsSequenceActive();
    void SpecialIdleFree(bool, bool);
    BSAnimGroupSequence* GetPlayingSequence();
    void ShutdownAllAnimIdles();
    static NiNode* FindKeyframeNode(NiNode*);
    static bool RemoveKeyframeControllers(NiAVObject*);
    char GetSkipNextBlend();
    void SkipNextBlend();
    void SetHavokChaseBone(NiAVObject*);
    TESIdleForm* GetSpecialIdleForm();
    BSAnimGroupSequence* GetSpecialIdleSequence();
    unsigned short GetSaveSize(TESObjectREFR*);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(TESObjectREFR*);
    void Revert(BGSLoadFormBuffer*);
    void Revert(TESObjectREFR*);
    static unsigned short GetAnimationID(TESObjectREFR*, Animation*);
    static void SaveAnimation(TESObjectREFR*, Animation*);
    static void RestoreAnimation(TESObjectREFR*, Animation*);
    static void ResetCloneCount();
    void ClearAccumRootTranslate();
    void SetGlobalTimeMultiplier(float);
    float GetGlobalTimeMultiplier();
    void SetReloadModifier(float);
    void SetEquipModifier(float);
    float GetReloadModifier();
    float GetEquipModifier();
    BSAnimGroupSequence* GetAnimationSequence(BSAnimGroupSequence*, unsigned short, int);
    BSAnimGroupSequence* GetAnimationSequence(unsigned short, int);
    void AssignControllerManager(void*);
    static void FindHighestPriorityCallback(NiAVObject*, FindData*);
    BSAnimGroupSequence* GetHighestPriority(NiAVObject*);
    bool GetMoved();
    void SetMoved(bool);
    bool GetDelayUpdateScenegraph();
    void SetDelayUpdateScenegraph(bool);
    void* __vecDelDtor(unsigned int);
    unsigned char m_uiObjectFlags;
    char _pad_1[3];
    TESObjectREFR* m_pAttachedReference;
    char m_acHeaderData[4];
    NiNode* m_pObjectNode;
    NiPoint3 m_kNodeTranslation;
    NiPoint3 m_kRootTranslation;
    char m_acNodeName[32];
    float m_fAnimationAmount;
    char group[16];
    char action[32];
    char m_acTargetName[32];
    char usReloadGroup[16];
    char m_acAnimationName[32];
    char m_cState;
    bool m_bIsPlaying;
    char _pad_ce[2];
    float time;
    float m_fTimeOffset;
    char m_acReservedBytes[4];
    void* m_pOwnerReference;
    char m_pChildTile[32];
    BSAnimGroupSequence* m_pCurrentSequence;
    char kfModelList[8];
    float m_fMovementRate;
    float m_fCombatAnimationRate;
    float m_fEquipAnimationRate;
    float m_fReloadAnimationRate;
    float m_fAnimationTimeScale;
    char m_cSkipNextBlend;
    char _pad_121[1];
    unsigned short m_usQueuedGroup;
    char LocalInput[4];
    char LocalStateValue[4];
    char LocalOutput[8];
    char m_acTrailingData[8];
};
typedef char _sizecheck_Animation[sizeof(Animation) == 316 ? 1 : -1];

void* __cdecl memset(void*, int, unsigned int);

namespace fnv_00920fd0 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

struct TESObject
{
    TESObject* GetNext(void);
};

struct TESFurniture
{
    static bool __cdecl IsFurnitureSleepMarker(unsigned int);
    static bool __cdecl IsFurnitureSitMarker(unsigned int);
};

}  // namespace fnv_00920fd0

namespace fnv_00921080 {
struct Actor;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct GuardActorPackageData;
struct HighProcess;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiNode;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct TESActorBase;
struct TESBoundObject;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct bhkSimpleShapePhantom;
struct blob12
{
    char b[12];
};

NiAVObject* __cdecl FUN_00c54400(NiNode*);

}  // namespace fnv_00921080

namespace fnv_00929280 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

}  // namespace fnv_00929280

namespace fnv_0092b830 {
struct Actor;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct BGSBodyPart;
struct BGSBodyPartData;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct BaseFormComponent;
struct CHUNK;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct HighProcess;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiColor;
struct NiNode;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct QueuedFile;
struct TESActorBase;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESIdleForm;
struct TESModel;
struct TESModelTextureSwap;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct FileEntryList;
struct TESTopic;
struct bhkSimpleShapePhantom;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};

class ThreeByThreeMatrix;

class NiAVObject
{
  public:
    ThreeByThreeMatrix const& GetRotate(void) const;
};

class BGSBodyPart
{
  public:
    int GetLimb(void);
};

class Model
{
  public:
    NiNode* GetObject3D(void);
};

class SceneObjectLookup
{
  public:
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, char const*);
};

struct BGSBodyPartData
{
    BGSBodyPart* GetValueByIndex(int limb);
};

}  // namespace fnv_0092b830

namespace fnv_0092bf80 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSIdleCollection;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct DurationData;
struct PackageTargetRecord;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESContainer;
struct TESEscortPackageData;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESPackageData;
struct TESPatrolPackageData;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESUseWeaponPackageData;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

extern int* DAT_011a3ff0[];

struct Calendar
{
    unsigned int GetDaysPassed();
};

}  // namespace fnv_0092bf80

namespace fnv_0092c680 {
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
struct DH
{
    bool FUN_004226e0();
};
struct TESObjectREFRHelper
{
    void SetMarkerState(unsigned char a, bool b);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern DH* g_dataHandler;
}  // namespace fnv_0092c680

namespace fnv_00915ae0 {
struct Actor;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct ActorCombatGroup;
struct Crime;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct ExtraDataList;
struct GuardActorPackageData;
struct HighProcess;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct MobileObject;
struct DetectionEventData;
struct MuzzleFlash;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiNode;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct TESActorBase;
struct TESBoundObject;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct bhkSimpleShapePhantom;
struct blob12
{
    char b[12];
};

struct Flt
{
    operator unsigned int() const;
};
struct PaddedFloatRecord
{
    ~PaddedFloatRecord();
    char pad[0x14];
    Flt flt;
};
struct QueuedItemList
{
    ~QueuedItemList();
    PaddedFloatRecord** _ref_006815c0();
    void _ref_0063f7b0();
};
struct IOManager
{
    void RunQueuedTask(unsigned int, int);
};
extern IOManager* DAT_01202d98;
}  // namespace fnv_00915ae0

namespace fnv_009287e0 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

struct Animation
{
    void SpecialIdleFree(bool, bool);
};
extern Actor* g_thePlayer;
}  // namespace fnv_009287e0

struct MemoryManager
{
    void* Allocate(unsigned int);
};

struct QueuedItemList
{
    PaddedFloatRecord** _ref_006815c0();
    QueuedItemList* _ref_00726070();
};

namespace fnv_00915e50 {
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct TESObjectREFRHelper
{
    void SetMarkerState(unsigned char acIndex, bool abReserved);
};

}  // namespace fnv_00915e50

namespace fnv_0092c120 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

struct Flt
{
    void* m_pObject;
    operator unsigned int() const;
};
struct FUN_00914ab0
{
    float m_fPackageValue;
    int m_iLimbIndex;
    Flt spLimbNode;
    Flt spParentNode;
    bool bExplode;
    ~FUN_00914ab0();
};
struct HideLimbNodeList
{
    bool _ref_008256d0();
    struct FUN_00914ab0** _ref_006815c0();
    HideLimbNodeList* _ref_00726070();
    void _ref_00905330(struct FUN_00914ab0* const& apItem);
    void _ref_0063f7b0();
};
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};
struct Setting_S
{
    float* Float();
};

}  // namespace fnv_0092c120

struct FUN_009b4d90
{
    void* pSource;
    void* pTarget;
    void* pProjectile;
    unsigned int eWeaponAV;
    int iHitLocation;
    float m_fDamage;
    float fWeaponBaseDamage;
    float m_fHealthDamage;
    float fLimbDamage;
    float fBlockDTMod;
    float m_fSneakAttackMultiplier;
    float fWeaponDamage;
    void* pWeapon;
    float fHealthPercent;
    NiPoint3 ImpactPos;
    NiPoint3 ImpactAngle;
    bool bFlag50;
    void* pExtra;
    unsigned int uiFlags;
    float m_fDamageMultiplier;
    int iUnk60;
    FUN_009b4d90();
    void FUN_009b4ec0(FUN_009b4d90* apData);
};

namespace fnv_0092c4a0 {
struct FUN_009b4d90
{
    void* pSource;
    void* pTarget;
    void* pProjectile;
    unsigned int eWeaponAV;
    int iHitLocation;
    float m_fDamage;
    float fWeaponBaseDamage;
    float m_fHealthDamage;
    float fLimbDamage;
    float fBlockDTMod;
    float m_fSneakAttackMultiplier;
    float fWeaponDamage;
    void* pWeapon;
    float fHealthPercent;
    NiPoint3 ImpactPos;
    NiPoint3 ImpactAngle;
    bool bFlag50;
    void* pExtra;
    unsigned int uiFlags;
    float m_fDamageMultiplier;
    int iUnk60;
    FUN_009b4d90();
    void FUN_009b4dc0();
};

}  // namespace fnv_0092c4a0

namespace fnv_0092c5e0 {
struct FUN_009b4d90
{
    void* pSource;
    void* pTarget;
    void* pProjectile;
    unsigned int eWeaponAV;
    int iHitLocation;
    float m_fDamage;
    float fWeaponBaseDamage;
    float m_fHealthDamage;
    float fLimbDamage;
    float fBlockDTMod;
    float m_fSneakAttackMultiplier;
    float fWeaponDamage;
    void* pWeapon;
    float fHealthPercent;
    NiPoint3 ImpactPos;
    NiPoint3 ImpactAngle;
    bool bFlag50;
    void* pExtra;
    unsigned int uiFlags;
    float m_fDamageMultiplier;
    int iUnk60;
    FUN_009b4d90();
    void FUN_009b4dc0();
};

}  // namespace fnv_0092c5e0

void _Deallocate(void*);

void __cdecl _Deallocate(void*);

struct GO
{
    int x;
    ~GO();
};
extern int _data_011c16bc;

struct Thunk0091f100
{
    void FUN_0091f100(class Actor* apActor);
};

struct MiddleHighProcessStandIn
{
    char _pad[0x12C];
    void* m_pActorNode;
    void* FUN_00922b20(void* apBiped);
};

struct LipSyncAnimation
{
    ~LipSyncAnimation();
};

namespace fnv_0091efe0 {
struct PackageTargetRecord
{
    int GetTargetKind();
    TESForm* GetTargetForm();
    int GetTargetObjectType();
};
struct TESPackage
{
    PackageTargetRecord* GetTarget();
};
struct TESObject
{
    unsigned int GetNext();
};
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};

}  // namespace fnv_0091efe0

namespace fnv_00921120 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct PerkEntryConditionSet;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESModelTextureSwap;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct FileEntryList;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

struct TESIdleForm
{
    int GetFlagsMasked();
};
struct Animation
{
    void FUN_00498030(TESIdleForm*, Actor*, int);
};
struct IdleAnimationManager
{
    TESIdleForm* FindIdleFormForObject(TESObjectREFR*, TESObjectREFR*);
};
struct PlayerCharacter
{
    bool FUN_004eaf60();
    void FUN_005c4210(unsigned char);
    Animation* GetAnimation(bool);
};
extern IdleAnimationManager* DAT_011cb6a0;
extern PlayerCharacter* g_thePlayer;

}  // namespace fnv_00921120

namespace fnv_00922960 {
struct TESFurniture
{
    bool GetCanSitOn();
    bool GetCanSleepOn();
};
struct TESObject
{
    unsigned int GetNext();
};
struct TESObjectREFRHelper
{
    bool IsReferenceActive(bool);
    TESForm* GetOwner();
    bool CanBeUsed(Actor*, bool);
};
struct LH
{
    bool IsInList(Actor*&);
};
struct G2
{
    void AddHead(int*);
};

}  // namespace fnv_00922960

struct Calendar
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual bool V4F(Actor* actor, int a, float f, int b);
    unsigned int GetDaysPassed();
};
extern int* DAT_011a3ff0[];

struct TESObjectWEAP
{
    int GetWeaponType();
};
struct Crime
{
    TESObjectREFR* GetTarget();
};

namespace fnv_0091ecf0 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSIdleCollection;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct DurationData;
struct PackageTargetRecord;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESContainer;
struct TESEscortPackageData;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESPackageData;
struct TESPatrolPackageData;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESUseWeaponPackageData;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

struct Calendar
{
    unsigned int GetDaysPassed();
};
int __cdecl FUN_0096a820(int);
extern int* DAT_011a3ff0[];

}  // namespace fnv_0091ecf0

namespace fnv_00923020 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

enum ANIM_GROUP_WEAPON_ENUM
{
    ANIM_GROUP_WEAPON_NONE = 0
};
struct TESObjectWEAP
{
    int GetWeaponType() const;
};
struct FUN_00493830_shell
{
    bool FUN_00493830();
};
struct Animation
{
    bool IsGroupQueued(unsigned short);
    NiControllerManager* FUN_00496940();
    void FUN_00490400(BSSimpleList<char const*>*);
};
struct TESAnimGroup
{
    static unsigned short __cdecl AnimGroup(int, ANIM_GROUP_WEAPON_ENUM, int, bool);
};
struct ModelLoader
{
    BSSimpleList<char const*>* GetModelFileList(char const*, bool, bool, int);
};
extern ModelLoader* g_modelLoader;
extern ANIM_GROUP_WEAPON_ENUM DAT_0118a838[];

}  // namespace fnv_00923020

namespace fnv_00923960 {
struct Actor;
struct ActorCause;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct DialogueResponse;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FindData;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESAnimGroup;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct Animation
{
    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    NiNode* GetAnimNode();
    NiNode* GetAccumRoot();
    void* GetAnimSequenceMap();
    float GetSmallestHavokBlendValue(NiNode*);
    NiControllerManager* GetControllerManager();
    void RemoveObject(NiAVObject*);
    float GetTime();
    float GetTime(NiControllerSequence*);
    void SetTime(float);
    static void SetLipTime(float, NiControllerManager*, NiControllerSequence*);
    void SetLipTime(float);
    bool Init(void*, NiNode*, TESObjectREFR*, bool);
    void SetAnimationName(void*, char*);
    void SetAnimationOwner(void*);
    void QueueReloadAnim(unsigned short);
    bool ReloadAnimQueued();
    bool AddAnimation(KFModel*, bool);
    bool IsAnimationLoaded();
    void SetReloadState(bool);
    void BlendOut(int, bool);
    static float GetDuration(NiControllerSequence*);
    static float GetDuration(NiNode*, float*, float*);
    float GetDuration();
    void SetLookingDir(float);
    void SkipUpdate(int);
    void Update(TESObjectREFR*, float, float);
    void UpdateMovement(TESObjectREFR*);
    void UpdateActorAnimation(TESObjectREFR*);
    bool UpdateQueuedScenegraph();
    bool GetMovementDelta(NiPoint3*, TESObjectREFR*, bool, bool);
    void ClearDelta();
    bool IsGroupQueued(unsigned short);
    void ClearGroup(int, float);
    unsigned short GetQueuedGroup(int);
    void ClearBlendInterps();
    static void ClearBlendInterpsCallback(NiAVObject*);
    void SetAnimationGroup(TESAnimGroup*);
    short GetGroupSection(unsigned short);
    void UpdateBipOnly(float, NiPoint3*, bool);
    void RefreshAnimation();
    void SetMoveSpeed(float);
    float GetMoveSpeed();
    void SetAttackSpeed(float);
    float GetAttackSpeedModifier();
    void AddGroup(TESAnimGroup*);
    BSAnimGroupSequence* PlayGroup(BSAnimGroupSequence*, int, int, int);
    BSAnimGroupSequence* PlayGroup(unsigned short, int, int, int);
    BSAnimGroupSequence* SyncSequences(BSAnimGroupSequence*, unsigned short);
    unsigned short PickBestAnimation(unsigned short, bool);
    bool ShouldBeMoving();
    BSAnimGroupSequence* GetCurrentSequence(int);
    unsigned short GetGroup(int);
    int GetGroupAction(int);
    BSAnimGroupSequence* GetFirstActiveSequence();
    BSAnimGroupSequence* GetNextActiveSequence(BSAnimGroupSequence*);
    void SetCurrentSequence(int, BSAnimGroupSequence*);
    void VerifyUniqueControllerPriorities(NiNode*);
    static bool StripAllBSKeyframeControllers(NiAVObject*);
    bool SwapSequences(int);
    char GetNextNoteKey(float*);
    int FindNoteKey(int, char*, float*);
    char FindNextNoteKey(int, char*, float*);
    void ForceSection(int, unsigned short, int, float, char);
    void ClearForcedSection();
    TESAnimGroup* GetAnimGroupByID(unsigned short);
    bool AreAnimationsLoaded();
    unsigned int GetAnimsLoadingCount();
    void QueueReplacementAnimation(KFModel*);
    void SetLoopCount(int, int);
    void SpecialIdleQueue(TESIdleForm*, int);
    void PlaySpecialIdle(TESIdleForm*, Actor*, int, int);
    bool SpecialIdleReplace();
    void SpecialIdleReplace(TESIdleForm*, Actor*, int);
    bool CanReplaceSpecialIdle();
    bool CanReplaceSpecialIdle(Actor*);
    bool IsSpecialIdlePlaying();
    bool IsSpecialIdlePlaying(TESIdleForm*);
    bool IsSpecialIdlePlaying(BSAnimGroupSequence*);
    bool SpecialIdleLoaded();
    bool IsSpecialIdleReady();
    bool IsSequenceActive();
    void SpecialIdleFree(bool, bool);
    BSAnimGroupSequence* GetPlayingSequence();
    void ShutdownAllAnimIdles();
    static NiNode* FindKeyframeNode(NiNode*);
    static bool RemoveKeyframeControllers(NiAVObject*);
    char GetSkipNextBlend();
    void SkipNextBlend();
    void SetHavokChaseBone(NiAVObject*);
    TESIdleForm* GetSpecialIdleForm();
    BSAnimGroupSequence* GetSpecialIdleSequence();
    unsigned short GetSaveSize(TESObjectREFR*);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(TESObjectREFR*);
    void Revert(BGSLoadFormBuffer*);
    void Revert(TESObjectREFR*);
    static unsigned short GetAnimationID(TESObjectREFR*, Animation*);
    static void SaveAnimation(TESObjectREFR*, Animation*);
    static void RestoreAnimation(TESObjectREFR*, Animation*);
    static void ResetCloneCount();
    void ClearAccumRootTranslate();
    void SetGlobalTimeMultiplier(float);
    float GetGlobalTimeMultiplier();
    void SetReloadModifier(float);
    void SetEquipModifier(float);
    float GetReloadModifier();
    float GetEquipModifier();
    BSAnimGroupSequence* GetAnimationSequence(BSAnimGroupSequence*, unsigned short, int);
    BSAnimGroupSequence* GetAnimationSequence(unsigned short, int);
    void AssignControllerManager(void*);
    static void FindHighestPriorityCallback(NiAVObject*, FindData*);
    BSAnimGroupSequence* GetHighestPriority(NiAVObject*);
    bool GetMoved();
    void SetMoved(bool);
    bool GetDelayUpdateScenegraph();
    void SetDelayUpdateScenegraph(bool);
    void* __vecDelDtor(unsigned int);
    unsigned char m_uiObjectFlags;
    char _pad_1[3];
    TESObjectREFR* m_pAttachedReference;
    char m_acHeaderData[4];
    NiNode* m_pObjectNode;
    NiPoint3 m_kNodeTranslation;
    NiPoint3 m_kRootTranslation;
    char m_acNodeName[32];
    float m_fAnimationAmount;
    char group[16];
    char action[32];
    char m_acTargetName[32];
    char usReloadGroup[16];
    char m_acAnimationName[32];
    char m_cState;
    bool m_bIsPlaying;
    char _pad_ce[2];
    float time;
    float m_fTimeOffset;
    char m_acReservedBytes[4];
    void* m_pOwnerReference;
    char m_pChildTile[32];
    BSAnimGroupSequence* m_pCurrentSequence;
    char kfModelList[8];
    float m_fMovementRate;
    float m_fCombatAnimationRate;
    float m_fEquipAnimationRate;
    float m_fReloadAnimationRate;
    float m_fAnimationTimeScale;
    char m_cSkipNextBlend;
    char _pad_121[1];
    unsigned short m_usQueuedGroup;
    char LocalInput[4];
    char LocalStateValue[4];
    char LocalOutput[8];
    char m_acTrailingData[8];
};
typedef char _sizecheck_Animation[sizeof(Animation) == 316 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];

NiAVObject* __cdecl FUN_004aae30(NiAVObject*, char const*);
struct NiFixedStr
{
    operator char const*() const;
};
struct Flt
{
    operator unsigned int();
};
void FNV_Warning(const char*, ...);
extern int DAT_011977e4[][9];

}  // namespace fnv_00923960

namespace fnv_0092c0c0 {
struct GO
{
    int a;
    GO(int);
    ~GO();
};
}  // namespace fnv_0092c0c0

namespace fnv_0092c540 {
struct FUN_009b4d90
{
    char m_data[0x64];
    FUN_009b4d90();
    ~FUN_009b4d90();
    void FUN_009b4ec0(FUN_009b4d90* apData);
};

}  // namespace fnv_0092c540

namespace fnv_009293b0 {
void* __cdecl operator new(unsigned int);

extern unsigned int _data_011c16bc;

struct G2
{
    void AddHead(int*);
};

struct LH
{
    bool IsInList(int&);
};

}  // namespace fnv_009293b0

namespace fnv_00929d40 {
class Crime
{
  public:
    TESObjectREFR* GetTarget();
};

class InventoryStackRecord : public Crime
{
  public:
    bool SetEquipmentState(int);
};

class TESObjectWEAP : public TESObjectREFR
{
  public:
    bool GetIsAutomaticWeapon();
};

class TESCreature
{
  public:
    float FUN_00821640();
};

struct MiddleHighProcessStandIn
{
    char pad0000[0x114];
    InventoryStackRecord* pWeapon;
    InventoryStackRecord* pAmmo;
    char pad011c[0x1d4 - 0x11c];
    float fShotsPerSecond;

  public:
    void UpdateShotsPerSecond(bool);
};

}  // namespace fnv_00929d40

struct FUN_0096a2d0
{
    FUN_0096a2d0();
    ~FUN_0096a2d0();
    int m_00;
    int m_04;
};
struct FUN_006815c0
{
    FUN_006815c0();
    int f_00;
    int f_04;
    int f_08;
    int f_0c;
    int f_10;
    unsigned char f_14;
    unsigned char f_15;
    unsigned char f_16;
    unsigned char f_17;
    int f_18;
    int f_1c;
};
extern float DAT_01012054;
void* __cdecl memset(void*, int, unsigned int);

namespace fnv_00914c60 {
struct QSub
{
    int m_00;
    QSub& FUN_0092c820(const QSub&);
};
struct FUN_009139b0
{
    int m_00;
    int m_04;
    int m_08;
    unsigned char m_0c;
    unsigned char m_0d;
    unsigned char m_0e;
    unsigned char m_0f;
    unsigned char m_10;
    unsigned char m_11;
    unsigned short m_12;
    QSub m_14;
    FUN_009139b0();
};
struct FUN_0096a2d0
{
    void* m_item;
    FUN_0096a2d0* m_next;
    FUN_0096a2d0();
    void FUN_005ae3d0(FUN_009139b0**);
};
struct AEItem
{
    virtual void v0();
    virtual int v4();
};
struct AENode
{
    AEItem** FUN_006815c0();
    bool FUN_008256d0();
    AENode* FUN_00726070();
};
struct AENode;
struct AEItem;

}  // namespace fnv_00914c60

class TESBoundObject
{
  public:
    virtual void Unused();
};
class TESNPC
{
  public:
    void FUN_006047c0(Actor*, bool, bool, bool, bool);
};
class TESCreature
{
  public:
    void FUN_005f9e00(Actor*, bool, bool, bool);
};
class TESPackage
{
  public:
    int FUN_0041ca90();
    bool FUN_00441b00();
};

extern "C" Actor* DAT_011dea3c;

struct ControllerCalls
{
    bool FUN_0097fa10();
};
extern Actor* DAT_011dea3c;
extern float DAT_01012054;

typedef bool(__thiscall* PackageFilter)(TESPackage*, Actor*, Actor*, int, float, int);
typedef ControllerCalls*(__thiscall* ControllerForTarget)(Actor*, Actor*);
typedef void(__thiscall* ImmediateAction)(Actor*, Actor*, int, int, int, int, int, float, float);
typedef void(__thiscall* ProcessAction)(Actor*, Actor*, int, bool, bool, bool, int, bool, int);

extern float DAT_01012054;

struct TargetProcess : MiddleHighProcess
{
    virtual void unkSlot493();
    virtual void unkSlot494();
    virtual void unkSlot495();
    virtual void unkSlot496();
    virtual void unkSlot497();
    virtual void unkSlot498();
    virtual void unkSlot499();
    virtual void unkSlot500();
    virtual void unkSlot501();
    virtual void unkSlot502();
    virtual void unkSlot503();
    virtual void unkSlot504();
    virtual void unkSlot505();
    virtual void unkSlot506();
    virtual void unkSlot507();
    virtual void unkSlot508();
    virtual void unkSlot509();
    virtual void unkSlot510();
    virtual void unkSlot511();
    virtual void unkSlot512();
    virtual void unkSlot513();
    virtual void unkSlot514();
    virtual void unkSlot515();
    virtual TESObjectREFR* ResolveTarget(Actor*, TESPackage*);
    bool FUN_0091aca0(Actor* actor);
};

struct InventoryItemLookup
{
    void** FUN_006815c0();
};
struct InventoryLookup
{
    InventoryItemLookup* FUN_00559450();
    void* FUN_0044ddc0(void* item, bool enabled);
};

// StopActorMoving  (image 0x0091efc0, 27 bytes)
//
// The image's call target 0x008b3ab0 is Actor::StopMoving(); it is reached as
// a this-call on the argument, so the argument is an actor pointer and the
// member never touches its own `this`.
//
//   0091efc0  push ebp
//   0091efc1  mov  ebp, esp
//   0091efc3  push ecx                 ; /Od homing slot for `this`
//   0091efc4  mov  dword ptr [ebp-4], ecx
//   0091efc7  cmp  dword ptr [ebp+8], 0
//   0091efcb  je   0x0091efd5
//   0091efcd  mov  ecx, dword ptr [ebp+8]
//   0091efd0  call 0x008b3ab0           ; actor->StopMoving()
//   0091efd5  mov  esp, ebp
//   0091efd7  pop  ebp
//   0091efd8  ret  4

// Stand-in for the actor the argument points at.
struct Actor0091efc0
{
    void StopMoving();
};

// Stand-in for the class that owns StopActorMoving.
struct FUN_0091efc0_owner
{
    void StopActorMoving(Actor0091efc0* apActor);
};

// @f3 0x0076e070 (community match, verified in this file)
struct OwnerSelf709
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    unsigned char unk708;
    unsigned char unk709;
    void FUN_0070aeb0();
    void FUN_00729880();
};

// pdb: PlayerCharacter::SetPCYoung | PlayerCharacter.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: abVal
void FUN_0091efc0_owner::StopActorMoving(Actor0091efc0* apActor)
{
    OwnerSelf709* self = (OwnerSelf709*)this;
    unsigned char flag = (unsigned char)apActor;
    if (self->unk709 != flag)
    {
        self->unk709 = flag;
        self->FUN_0070aeb0();
        self->FUN_00729880();
    }
}


class B91FD90Package;

class B91FD90Actor
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual void vfn27C();
    virtual void vfn280();
    virtual void vfn284();
    virtual void ResetCombat();

    void* GetProcessTarget();
};

class B91FD90Package
{
  public:
    B91FD90Actor* FUN_008d80e0();
    B91FD90Actor* FUN_009ee040();
    void FUN_009ee0a0(int iState);

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
    float m_fTimer;
};

struct SSActor
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V0A();
    virtual void V0B();
    virtual void V0C();
    virtual void V0D();
    virtual void V0E();
    virtual void V0F();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V1A();
    virtual void V1B();
    virtual void V1C();
    virtual void V1D();
    virtual void V1E();
    virtual void V1F();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V2A();
    virtual void V2B();
    virtual void V2C();
    virtual void V2D();
    virtual void V2E();
    virtual void V2F();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V3A();
    virtual void V3B();
    virtual void V3C();
    virtual void V3D();
    virtual void V3E();
    virtual void V3F();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V4A();
    virtual void V4B();
    virtual void V4C();
    virtual void V4D();
    virtual void V4E();
    virtual void V4F();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual void V56();
    virtual void V57();
    virtual void V58();
    virtual void V59();
    virtual void V5A();
    virtual void V5B();
    virtual void V5C();
    virtual void V5D();
    virtual void V5E();
    virtual void V5F();
    virtual void V60();
    virtual void V61();
    virtual void V62();
    virtual void V63();
    virtual void V64();
    virtual void V65();
    virtual void V66();
    virtual void V67();
    virtual void V68();
    virtual void V69();
    virtual void V6A();
    virtual void V6B();
    virtual void V6C();
    virtual void V6D();
    virtual void V6E();
    virtual void V6F();
    virtual void V70();
    virtual void V71();
    virtual void V72();
    virtual void V73();
    virtual NiAVObject* GetNiNode();
    virtual void V75();
    virtual void V76();
    virtual void V77();
    virtual void V78();
    virtual void V79();
    virtual void V7A();
    virtual void V7B();
    virtual void V7C();
    virtual void V7D();
    virtual void V7E();
    virtual void V7F();
    virtual void V80();
    virtual void V81();
    virtual void V82();
    virtual void V83();
    virtual void V84();
    virtual void V85();
    virtual void V86();
    virtual void V87();
    virtual void V88();
    virtual void V89();
    virtual void V8A();
    virtual void V8B();
    virtual void V8C();
    virtual void V8D();
    virtual void V8E();
    virtual void V8F();
    virtual void V90();
    virtual void V91();
    virtual void V92();
    virtual void V93();
    virtual void V94();
    virtual void V95();
    virtual void V96();
    virtual void V97();
    virtual void V98();
    virtual void V99();
    virtual void V9A();
    virtual void V9B();
    virtual void V9C();
    virtual void V9D();
    virtual void V9E();
    virtual void V9F();
    virtual void VA0();
    virtual void VA1();
    virtual void VA2();
    virtual void VA3();
    virtual void VA4();
    virtual void VA5();
    virtual void VA6();
    virtual void VA7();
    virtual void VA8();
    virtual void VA9();
    virtual void VAA();
    virtual void VAB();
    virtual void VAC();
    virtual void VAD();
    virtual void VAE();
    virtual void VAF();
    virtual void VB0();
    virtual void VB1();
    virtual void VB2();
    virtual void VB3();
    virtual void VB4();
    virtual void VB5();
    virtual void VB6();
    virtual void VB7();
    virtual void SetLookingTarget(float);
    float GetLooking() const;
    void ClampLookAngle(float);
    char* FUN_009306d0();
    void FUN_00931fb0(bool);
    void SetCurrentSitSleepState(int state);
};
bool FUN_008c7aa0();
void FUN_00c69fc0(NiAVObject* node, bool a, bool b, bool c);
extern SSActor* g_thePlayer;

struct FUN_00921250_Item;
struct FUN_00921250_Node;
struct FUN_00921250_Node
{
    int GetFlagsMasked();
};
struct FUN_00921250_Item
{
    void FUN_00498030(void* a, void* b, int c);
};

struct CvPoint3
{
    float x;
    float y;
    float z;
};

struct CvInfo
{
    CvPoint3* GetPosA();
    CvPoint3* GetPosB();
};

struct CvList;

struct CvItem
{
    float Evaluate(CvPoint3 pos, CvList* other);
    CvInfo* GetInfo();
};

struct CvList
{
    CvItem* GetFirst(int* iter);
    CvItem* GetNext(int* iter);
};

struct RefListClear
{
    void FUN_00470470();
};

struct Mgr
{
    void Run(unsigned int id, NiPoint3* pos, float f, NiPoint3* p2, float g, void* cb, Actor* a);
};
extern Mgr* DAT_011c3f2c;

struct Sched
{
    int Kind();
    int GetA();
    int GetB();
    int GetC();
    bool Chk();
};
struct RefX
{
    Sched* F672dd0();
    Sched* F55b980();
    bool F6728a0(Actor*, float*);
};

struct RecordVector
{
    float x, y, z;
    void FUN_006815c0();
};
struct RecordData
{
    void FUN_00812b00(RecordVector*);
    void FUN_0066ca00(RecordVector*);
};
struct SaveBuffer
{
    void FUN_008579b0(const void* data, unsigned int count);
    unsigned char FUN_008df040();
};
extern SaveBuffer* DAT_011de45c;
struct SaveGameRecordWriter
{
    void SaveActorRecord(void* actor);
};
typedef RecordData*(__thiscall* GetRecordFunction)(SaveGameRecordWriter*);
typedef bool(__thiscall* GetStateFunction)(void*, int);
typedef bool(__thiscall* GetSwitchFunction)(void*);

namespace fnv_009278d0 {
struct ResolveBuffer;
struct RefStub;
struct ResolveBuffer
{
    virtual unsigned char v0();
    virtual void v4();
    virtual void v8();
    virtual RefStub* vc();
};
struct FormInfo
{
    int FUN_00401170();
};
struct RefStub
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual bool v22c(int);
    FormInfo* FUN_007af430();
    int FUN_008d6f30();
    void FUN_005098c0();
    void FUN_00568150(int, bool);
};
class FUN_00915790
{
  public:
    void* object;
    ~FUN_00915790();
    void FUN_00913fb0(ResolveBuffer*);
};
struct RefList
{
    int item;
    RefList* next;
    bool FUN_008256d0();
    RefStub*& FUN_006815c0();
    void FUN_00726c60(RefStub**);
    void FUN_00905330(RefStub**);
    RefList* FUN_00726070();
    void FUN_0063f7b0();
};
struct EntryListNode
{
    FUN_00915790* item;
    EntryListNode* next;
    bool FUN_008256d0();
    FUN_00915790*& FUN_006815c0();
    void FUN_00905330(FUN_00915790**);
    EntryListNode* FUN_00726070();
    void FUN_0063f7b0();
};
struct Member
{
    void FUN_008c6970(ResolveBuffer*);
};
TESForm* __cdecl FUN_004839c0(unsigned int);
void* __cdecl BaseExtraList_RemoveAll(void*);
void* __cdecl FUN_00825550(void*);
extern RefStub* DAT_011dea3c;
struct Target
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84(RefStub*);
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
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
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
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
    virtual void v52c();
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
    virtual void v5a0();
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
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void v6e4(RefStub*);
    virtual void v6e8();
    virtual void v6ec();
    virtual void v6f0();
    virtual void v6f4();
    virtual void v6f8();
    virtual void v6fc();
    virtual void v700();
    virtual void v704();
    virtual void v708();
    virtual void v70c();
    virtual void v710();
    virtual void v714();
    virtual void v718();
    virtual void v71c();
    virtual void v720();
    virtual void v724();
    virtual void v728();
    virtual void v72c();
    virtual void v730();
    virtual void v734();
    virtual void v738();
    virtual void v73c();
    virtual void v740();
    virtual void v744();
    virtual void v748();
    virtual void v74c();
    virtual void v750();
    virtual void v754();
    virtual void v758();
    virtual void v75c();
    virtual void v760();
    virtual void v764();
    virtual void v768();
    virtual void v76c();
    virtual void v770();
    virtual void v774();
    virtual void v778();
    virtual void v77c();
    virtual void v780();
    virtual void v784();
    virtual void v788();
    virtual void v78c();
    virtual void v790();
    virtual void v794();
    virtual void v798();
    virtual void v79c();
    virtual void v7a0();
    virtual void v7a4();
    virtual void v7a8(RefStub*);
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
    RefStub* unk40;
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
    RefList unkc8;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    Member unke4;
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
    unsigned char unk13c, unk13d, unk13e, unk13f;
    RefStub* unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    Actor* unk158;
    int unk15c;
    void* unk160;
    void* unk164;
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
    void* unk1bc;
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
    EntryListNode* unk230;
    void FUN_00910820(ResolveBuffer*);
    void UpdateWeaponTypeFlags();
    void ResolveReferences(ResolveBuffer*);
};
}  // namespace fnv_009278d0

struct FUN_00914ab0
{
    ~FUN_00914ab0();
};

namespace fnv_0092ae20 {
struct Pt3Y
{
    float x;
    float y;
    float z;
};
struct FormX;
struct RefX
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual void r64();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual void r76();
    virtual void r77();
    virtual void r78();
    virtual void r79();
    virtual void r80();
    virtual void r81();
    virtual void r82();
    virtual void r83();
    virtual void r84();
    virtual void r85();
    virtual void r86();
    virtual void r87();
    virtual void r88();
    virtual void r89();
    virtual void r90();
    virtual void r91();
    virtual void r92();
    virtual void r93();
    virtual void r94();
    virtual void r95();
    virtual void r96();
    virtual void r97();
    virtual void r98();
    virtual void r99();
    virtual void r100();
    virtual void r101();
    virtual void r102();
    virtual void r103();
    virtual void r104();
    virtual void r105();
    virtual void r106();
    virtual void r107();
    virtual void r108();
    virtual void r109();
    virtual void r110();
    virtual void r111();
    virtual void r112();
    virtual void r113();
    virtual void r114();
    virtual void r115();
    virtual void r116();
    virtual void r117();
    virtual void r118();
    virtual void r119();
    virtual void r120();
    virtual void r121();
    virtual void r122();
    virtual void r123();
    virtual void r124();
    virtual int V1F4();
    FormX* GetBaseObject();
    int GetCull();
    const Pt3Y& GetAngle() const;
};
struct FormX
{
    int GetFormType();
};
struct ActorY;
struct PathReq
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
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    PathReq();
    ~PathReq();
    void SetFlag(bool);
    void SetAngle(float);
};
struct ActorY
{
    void PathToLocation(PathReq*, int, int, void*, float, int);
    void SetPathingRequestAvoidNodes(PathReq*);
    bool FUN_008b3bb0();
};
void* __fastcall FUN_00575d70(RefX*);
float __cdecl FUN_006e25d0();
float __cdecl FUN_00404010(float, float);
extern FormX* DAT_011ca248;

}  // namespace fnv_0092ae20

template <> NiPointer<NiNode>& NiPointer<NiNode>::operator=(NiNode*);

class MiddleHighProcess__DeferredHideLimb
{
  public:
    float fTime;
    int iLimbIndex;
    NiPointer<NiNode> spLimbNode;
    NiPointer<NiNode> spReplacementNode;
    bool m_bHideLimb;
    MiddleHighProcess__DeferredHideLimb();
};

struct FUN_00493830_shell
{
    bool FUN_00493830();
};

#include <stdio.h>

class PathingLocation
{
  public:
    PathingLocation(const NiPoint3&, TESObjectCELL*);
    ~PathingLocation();
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
};
Actor* FUN_00703180();

extern int DAT_0118a838[];
unsigned short FUN_005f2370(int a, int b, int c, int d);

struct ObjB913
{
    int FUN_00496940();
    bool FUN_00494710(unsigned short a);
};

struct Proc
{
    virtual void vfn_000();
    virtual void vfn_001();
    virtual void vfn_002();
    virtual void vfn_003();
    virtual void vfn_004();
    virtual void vfn_005();
    virtual void vfn_006();
    virtual void vfn_007();
    virtual void vfn_008();
    virtual void vfn_009();
    virtual void vfn_010();
    virtual void vfn_011();
    virtual void vfn_012();
    virtual void vfn_013();
    virtual void vfn_014();
    virtual void vfn_015();
    virtual void vfn_016();
    virtual void vfn_017();
    virtual void vfn_018();
    virtual void vfn_019();
    virtual void vfn_020();
    virtual void vfn_021();
    virtual void vfn_022();
    virtual void vfn_023();
    virtual void vfn_024();
    virtual void vfn_025();
    virtual void vfn_026();
    virtual void vfn_027();
    virtual void vfn_028();
    virtual void vfn_029();
    virtual void vfn_030();
    virtual void vfn_031();
    virtual void vfn_032();
    virtual void vfn_033();
    virtual void vfn_034();
    virtual void vfn_035();
    virtual void vfn_036();
    virtual void vfn_037();
    virtual void vfn_038();
    virtual void vfn_039();
    virtual void vfn_040();
    virtual void vfn_041();
    virtual void vfn_042();
    virtual void vfn_043();
    virtual void vfn_044();
    virtual void vfn_045();
    virtual void vfn_046();
    virtual void vfn_047();
    virtual void vfn_048();
    virtual void vfn_049();
    virtual void vfn_050();
    virtual void vfn_051();
    virtual void vfn_052();
    virtual void vfn_053();
    virtual void vfn_054();
    virtual void vfn_055();
    virtual void vfn_056();
    virtual void vfn_057();
    virtual void vfn_058();
    virtual void vfn_059();
    virtual void vfn_060();
    virtual void vfn_061();
    virtual void vfn_062();
    virtual void vfn_063();
    virtual void vfn_064();
    virtual void vfn_065();
    virtual void vfn_066();
    virtual void vfn_067();
    virtual void vfn_068();
    virtual void vfn_069();
    virtual void vfn_070();
    virtual void vfn_071();
    virtual void vfn_072();
    virtual void vfn_073();
    virtual void vfn_074();
    virtual void vfn_075();
    virtual void vfn_076();
    virtual void vfn_077();
    virtual void vfn_078();
    virtual void vfn_079();
    virtual void vfn_080();
    virtual void vfn_081();
    virtual void vfn_082();
    virtual void vfn_083();
    virtual void vfn_084();
    virtual void vfn_085();
    virtual void vfn_086();
    virtual void vfn_087();
    virtual void vfn_088();
    virtual void vfn_089();
    virtual void vfn_090();
    virtual void vfn_091();
    virtual void vfn_092();
    virtual void vfn_093();
    virtual void vfn_094();
    virtual void vfn_095();
    virtual void vfn_096();
    virtual void vfn_097();
    virtual void vfn_098();
    virtual void vfn_099();
    virtual void vfn_100();
    virtual void vfn_101();
    virtual void vfn_102();
    virtual void vfn_103();
    virtual void vfn_104();
    virtual void vfn_105();
    virtual void vfn_106();
    virtual void vfn_107();
    virtual void vfn_108();
    virtual void vfn_109();
    virtual ObjB913* vfn_110();
    virtual void vfn_111();
    virtual void vfn_112();
    virtual void vfn_113();
    virtual void vfn_114();
    virtual void vfn_115();
    virtual void vfn_116();
    virtual void vfn_117();
    virtual void vfn_118();
    virtual void vfn_119();
    virtual void vfn_120();
    virtual void vfn_121();
    virtual void vfn_122();
    virtual void vfn_123();
    virtual void vfn_124();
    virtual void vfn_125();
    virtual void vfn_126();
    virtual void vfn_127();
    virtual void vfn_128();
    virtual void vfn_129();
    virtual void vfn_130();
    virtual void vfn_131();
    virtual void vfn_132();
    virtual void vfn_133();
    virtual void vfn_134();
    virtual bool vfn_135();
    int FUN_00401170();
    Proc* FUN_008d8520();
    int FUN_00446390();
    void* FUN_005715d0(int a, int b, int c);
};

template <class T> struct List96
{
    T* value;
    List96* next;
    ~List96();
    T*& FUN_006815c0();
    List96* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00470470();
    void FUN_0063f7b0();
};

struct QueueTask
{
    bool FUN_0043caa0();
};
struct TaskPointer
{
    QueueTask* pointer;
    QueueTask* FUN_00559450();
};
struct QueueObject
{
    int FUN_00401170();
    void FUN_004f15a0(int);
};
class PaddedFloatRecord
{
  public:
    QueueObject* object;
    ExtraDataList* extra;
    int count;
    bool equip;
    bool equipFlag1;
    bool equipFlag2;
    bool flag3;
    bool unequipFlag1;
    bool unequipFlag2;
    TaskPointer task;
    ~PaddedFloatRecord();
};
struct QueueModelLoader
{
    void* FUN_00447330(const char*, bool, bool, bool);
};
extern QueueModelLoader* g_modelLoader;
unsigned short __cdecl FUN_005f2370(int, int, int, bool);

struct PendingResourceManager
{
    void RunQueuedTask(InventoryItemLookup* item, unsigned int unused);
};
extern PendingResourceManager* DAT_01202d98;

struct P114Settings
{
    float* FUN_00403e20();
};
struct P114Clock
{
    float FUN_00867da0();
};
struct P114Global
{
    float FUN_00526ac0();
};
extern P114Settings DAT_011cdbac;
extern P114Settings DAT_011cd82c;
extern P114Clock DAT_011de7b8;
extern TESBoundObject* DAT_011ca244;
extern TESBoundObject* DAT_011ca248;
P114Global* __cdecl FUN_004839c0(unsigned int);

struct Target;
struct Node
{
    bool empty();
    int size();
    Target** value();
    Node* next();
    void remove(Target* const&);
    void clear();
    int data;
    Node* link;
};
struct Target
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
    virtual void slot121();
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
    virtual int state();
    virtual bool active();
    void* owner();
};
struct Gate
{
    bool ready();
    void reset();
};
extern Gate g_011e043c;
struct Process
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
    virtual void update(Target*, int, int, int, int, int);
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
    virtual void finish(int);
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void setTarget(Target*);
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
    virtual void slot121();
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
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void slot288();
    virtual void slot289();
    virtual void slot290();
    virtual void slot291();
    virtual void slot292();
    virtual void slot293();
    virtual void slot294();
    virtual void slot295();
    virtual void slot296();
    virtual void slot297();
    virtual void slot298();
    virtual void slot299();
    virtual void slot300();
    virtual void slot301();
    virtual void slot302();
    virtual void slot303();
    virtual void slot304();
    virtual void slot305();
    virtual void slot306();
    virtual void slot307();
    virtual void slot308();
    virtual void slot309();
    virtual void slot310();
    virtual void slot311();
    virtual void slot312();
    virtual void slot313();
    virtual void slot314();
    virtual void slot315();
    virtual void slot316();
    virtual void slot317();
    virtual void slot318();
    virtual void slot319();
    virtual void slot320();
    virtual void slot321();
    virtual void slot322();
    virtual void slot323();
    virtual void slot324();
    virtual void slot325();
    virtual void slot326();
    virtual void slot327();
    virtual void slot328();
    virtual void slot329();
    virtual void slot330();
    virtual void slot331();
    virtual void slot332();
    virtual void slot333();
    virtual void slot334();
    virtual void slot335();
    virtual void slot336();
    virtual void slot337();
    virtual void slot338();
    virtual void slot339();
    virtual void slot340();
    virtual void slot341();
    virtual void slot342();
    virtual void slot343();
    virtual void slot344();
    virtual void slot345();
    virtual void slot346();
    virtual void slot347();
    virtual void slot348();
    virtual void slot349();
    virtual void slot350();
    virtual void slot351();
    virtual void slot352();
    virtual void slot353();
    virtual void slot354();
    virtual void slot355();
    virtual void slot356();
    virtual void slot357();
    virtual void slot358();
    virtual void slot359();
    virtual void slot360();
    virtual void slot361();
    virtual void slot362();
    virtual void slot363();
    virtual void slot364();
    virtual void slot365();
    virtual void slot366();
    virtual void slot367();
    virtual void slot368();
    virtual void slot369();
    virtual void slot370();
    virtual void slot371();
    virtual void slot372();
    virtual void slot373();
    virtual void slot374();
    virtual void slot375();
    virtual void slot376();
    virtual void slot377();
    virtual void slot378();
    virtual void slot379();
    virtual void slot380();
    virtual void slot381();
    virtual void slot382();
    virtual void slot383();
    virtual void slot384();
    virtual void slot385();
    virtual void slot386();
    virtual void slot387();
    virtual void slot388();
    virtual void slot389();
    virtual void slot390();
    virtual void slot391();
    virtual void slot392();
    virtual void slot393();
    virtual void slot394();
    virtual void slot395();
    virtual void slot396();
    virtual void slot397();
    virtual void slot398();
    virtual void slot399();
    virtual void slot400();
    virtual void slot401();
    virtual void slot402();
    virtual void slot403();
    virtual void slot404();
    virtual void slot405();
    virtual void slot406();
    virtual void slot407();
    virtual void slot408();
    virtual void slot409();
    virtual void slot410();
    virtual void slot411();
    virtual void slot412();
    virtual void slot413();
    virtual void slot414();
    virtual void slot415();
    virtual void slot416();
    virtual void slot417();
    virtual void slot418();
    virtual void slot419();
    virtual void slot420();
    virtual void slot421();
    virtual void slot422();
    virtual void slot423();
    virtual void slot424();
    virtual void slot425();
    virtual void slot426();
    virtual void slot427();
    virtual void slot428();
    virtual void slot429();
    virtual void slot430();
    virtual void slot431();
    virtual void slot432();
    virtual void slot433();
    virtual void slot434();
    virtual void slot435();
    virtual void slot436();
    virtual void slot437();
    virtual void slot438();
    virtual void slot439();
    virtual void slot440();
    virtual void slot441();
    virtual void slot442();
    virtual void slot443();
    virtual void slot444();
    virtual void slot445();
    virtual void slot446();
    virtual void slot447();
    virtual void slot448();
    virtual void slot449();
    virtual void slot450();
    virtual void slot451();
    virtual void slot452();
    virtual void slot453();
    virtual void slot454();
    virtual void slot455();
    virtual void slot456();
    virtual void slot457();
    virtual void slot458();
    virtual void slot459();
    virtual void slot460();
    virtual void slot461();
    virtual void slot462();
    virtual void slot463();
    virtual void slot464();
    virtual void slot465();
    virtual void slot466();
    virtual void slot467();
    virtual void slot468();
    virtual void slot469();
    virtual void slot470();
    virtual void slot471();
    virtual void slot472();
    virtual void slot473();
    virtual void slot474();
    virtual void slot475();
    virtual void slot476();
    virtual void slot477();
    virtual void slot478();
    virtual void slot479();
    virtual void slot480();
    virtual void slot481();
    virtual void slot482();
    virtual void slot483();
    virtual void slot484();
    virtual void slot485();
    virtual void slot486();
    virtual void slot487();
    virtual void slot488();
    virtual void slot489();
    virtual void slot490();
    virtual void slot491();
    virtual void slot492();
    virtual void slot493();
    virtual void slot494();
    virtual void slot495();
    virtual void slot496();
    virtual void slot497();
    virtual void act(Target*, int);
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
    Node list;
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
    Target* selected;
    void prepare(Target*, int, int);
    void changed();
    bool completed(Target*);
    void UpdateTargetSelection(Target* actor);
};

namespace fnv_00917a70 {
struct FurnitureActorAccess : Actor
{
    InventoryLookup* FUN_00891d30();
    void FUN_008c1de0(void*);
    unsigned int GetVtbl20Result();
    void FUN_00884f80();
    void ForwardToVtSlot(unsigned int);
};
struct GlobalObject_0044fae0
{
    bool FUN_0044b130();
    void FUN_0082f1f0();
};
extern GlobalObject_0044fae0 g_011e043c;
struct FurnitureProcess : MiddleHighProcess
{
    virtual void Slot493();
    virtual void Slot494();
    virtual void Slot495();
    virtual void Slot496();
    virtual void Slot497();
    virtual void UseFurniture(Actor*, bool);
    void FUN_00922670(Actor*, bool, int);
    void FUN_0092c680();
    void FUN_00917a70(FurnitureActorAccess* actor, int elapsed);
};
}  // namespace fnv_00917a70

class MagicItem
{
  public:
    virtual ~MagicItem();
};
struct P3
{
    float x;
    float y;
    float z;
};
struct FormCls
{
    virtual void u0000();
    int FUN_00401170();
};
struct OwnerForm : public FormCls
{
};
struct CellCls
{
    bool FUN_00425fd0();
};
struct ItemCls
{
    virtual void u0000();
    virtual void u0001();
    virtual void u0002();
    virtual void u0003();
    virtual void u0004();
    virtual void u0005();
    virtual void u0006();
    virtual void u0007();
    virtual void u0008();
    virtual void u0009();
    virtual void u000a();
    virtual void u000b();
    virtual void u000c();
    virtual void u000d();
    virtual void u000e();
    virtual void u000f();
    virtual void u0010();
    virtual void u0011();
    virtual void u0012();
    virtual void u0013();
    virtual void u0014();
    virtual void u0015();
    virtual void u0016();
    virtual void u0017();
    virtual void u0018();
    virtual void u0019();
    virtual void u001a();
    virtual void u001b();
    virtual void u001c();
    virtual void u001d();
    virtual void u001e();
    virtual void u001f();
    virtual void u0020();
    virtual void u0021();
    virtual void u0022();
    virtual void u0023();
    virtual void u0024();
    virtual void u0025();
    virtual void u0026();
    virtual void u0027();
    virtual void u0028();
    virtual void u0029();
    virtual void u002a();
    virtual void u002b();
    virtual void u002c();
    virtual void u002d();
    virtual void u002e();
    virtual void u002f();
    virtual void u0030();
    virtual void u0031();
    virtual void u0032();
    virtual void u0033();
    virtual void u0034();
    virtual void u0035();
    virtual void u0036();
    virtual void u0037();
    virtual void u0038();
    virtual void u0039();
    virtual void u003a();
    virtual void u003b();
    virtual void u003c();
    virtual void u003d();
    virtual void u003e();
    virtual void u003f();
    virtual bool V100();
    void* f00;
    OwnerForm* FUN_00567790();
    int FUN_005682c0(int a);
};
struct TESIdleForm
{
    void* FUN_0067f390();
};
struct Script
{
    TESIdleForm* GetText();
};
struct ObjC
{
    void* FUN_0067f390();
};
struct P0
{
    virtual void u0000();
    virtual void u0001();
    virtual void u0002();
    virtual void u0003();
    virtual void u0004();
    virtual void u0005();
    virtual void u0006();
    virtual void u0007();
    virtual void u0008();
    virtual void u0009();
    virtual void u000a();
    virtual void u000b();
    virtual void u000c();
    virtual void u000d();
    virtual void u000e();
    virtual void u000f();
    virtual void u0010();
    virtual void u0011();
    virtual void u0012();
    virtual void u0013();
    virtual void u0014();
    virtual void u0015();
    virtual void u0016();
    virtual void u0017();
    virtual void u0018();
    virtual void u0019();
    virtual void u001a();
    virtual void u001b();
    virtual void u001c();
    virtual void u001d();
    virtual void u001e();
    virtual void u001f();
    virtual void u0020();
    virtual void u0021();
    virtual void u0022();
    virtual void u0023();
    virtual void u0024();
    virtual void u0025();
    virtual void u0026();
    virtual void u0027();
    virtual void u0028();
    virtual void u0029();
    virtual void u002a();
    virtual void u002b();
    virtual void u002c();
    virtual void u002d();
    virtual void u002e();
    virtual void u002f();
    virtual void u0030();
    virtual void u0031();
    virtual void u0032();
    virtual void u0033();
    virtual void u0034();
    virtual void u0035();
    virtual void u0036();
    virtual void u0037();
    virtual void u0038();
    virtual void u0039();
    virtual void u003a();
    virtual void u003b();
    virtual void u003c();
    virtual void u003d();
    virtual void u003e();
    virtual void u003f();
    virtual void u0040();
    virtual void u0041();
    virtual void u0042();
    virtual void u0043();
    virtual void u0044();
    virtual void u0045();
    virtual void u0046();
    virtual void u0047();
    virtual void u0048();
    virtual void u0049();
    virtual void u004a();
    virtual void u004b();
    virtual void u004c();
    virtual void u004d();
    virtual void u004e();
    virtual void u004f();
    virtual void u0050();
    virtual void u0051();
    virtual void u0052();
    virtual void u0053();
    virtual void u0054();
    virtual void u0055();
    virtual void u0056();
    virtual void u0057();
    virtual void u0058();
    virtual void u0059();
    virtual void u005a();
    virtual void u005b();
    virtual void u005c();
    virtual void u005d();
    virtual void u005e();
    virtual void u005f();
    virtual void u0060();
    virtual void u0061();
    virtual void u0062();
    virtual void u0063();
    virtual void u0064();
    virtual void u0065();
    virtual void u0066();
    virtual void u0067();
    virtual void u0068();
    virtual void u0069();
    virtual void u006a();
    virtual void u006b();
    virtual void u006c();
    virtual void u006d();
    virtual void u006e();
    virtual void u006f();
    virtual void u0070();
    virtual void u0071();
    virtual void u0072();
    virtual void u0073();
    virtual void u0074();
    virtual void u0075();
    virtual void u0076();
    virtual void u0077();
    virtual void u0078();
    virtual void u0079();
    virtual void u007a();
    virtual void u007b();
    virtual void u007c();
    virtual void* V1f4();
    virtual void u007e();
    virtual void u007f();
    virtual void u0080();
    virtual void u0081();
    virtual void u0082();
    virtual void u0083();
    virtual void u0084();
    virtual void u0085();
    virtual void u0086();
    virtual void u0087();
    virtual void u0088();
    virtual void u0089();
    virtual void u008a();
    virtual bool V22c(int);
    void* FUN_00569b80_asP0();
    P0* FUN_00569b80();
    CellCls* FUN_008d6f30();
    void FUN_004534f0(unsigned int a);
    bool FUN_00493bb0();
};
struct Pkg
{
    int FUN_0041ca90();
    ObjC* FUN_0055b980();
    bool FUN_00674d40();
    void FUN_00674e70(void* o, int a);
    void* FUN_00672f20();
    unsigned int FUN_006758a0(P0* a);
    void* FUN_006757e0(P0* a);
    P3 FUN_00675830(P0* a);
    int FUN_00672930();
    bool FUN_00678d00();
};
struct GCls
{
    ItemCls* FUN_00970a20(void* a, int b);
};

extern GCls DAT_011e0e80;

extern int DAT_01183028;
bool __fastcall FUN_00425fd0(TESObjectCELL* c);
void* __cdecl FUN_00ec43fb(void* a1, int a2, void* a3, void* a4, int a5);
struct FUN_00678d00_shell
{
    bool FUN_00678d00();
};
struct FUN_00905330
{
    void Remove(void* p);
};
struct MobileObject;

namespace fnv_0091bc60 {
struct PackageActor;
struct PackageTargetRef
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
    virtual bool IsActor();
    bool FUN_00568680();
    bool FUN_00440d80();
};
struct LocationDescriptor
{
    PackageTargetRef* FUN_0067f390();
};
struct PackageList
{
    int FUN_00726070();
};
struct RunningPackage
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
    virtual bool Evaluate(PackageActor*, int, float, int);
    virtual void slot80();
    virtual bool Complete(PackageActor*, int);
    int FUN_009611e0();
    int FUN_0041ca90();
    bool FUN_008a6290();
    LocationDescriptor* FUN_0055b980();
    bool FUN_00670f90();
    PackageList* FUN_0041d8a0();
};
struct PackageAction
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
    virtual void Finish();
    int FUN_0045cd60();
};
struct PackageActor
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
    virtual void slot121();
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
    virtual int IsInCombat();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void SetPackage(RunningPackage*, bool);
    bool FUN_005653d0();
    RunningPackage* FUN_009344a0();
    PackageAction* FUN_008d8520();
    int FUN_00931850();
    bool FUN_008b3bb0();
    bool FUN_008b3bf0();
};
extern int* DAT_011a3ff0[];
extern PackageTargetRef* DAT_011dea3c;
extern float DAT_01012054, DAT_01084838;
struct PackageGameState
{
    bool FUN_00867d60();
};
extern PackageGameState DAT_011de7b8;

}  // namespace fnv_0091bc60

struct PackageTargetAccess
{
    int FUN_00678ca0();
};
struct PackageAccess : TESForm
{
    virtual void PackageSlot78();
    virtual bool IsEffectValid(Actor*, int, float, int);
    bool FUN_008a6290();
    void SetFlag10000(bool);
    float GetPackageResult(Actor*, bool);
    int FUN_0041ca90();
    PackageTargetAccess* FUN_0055b980();
    bool FUN_00674d40();
};
struct SettingIntAccess
{
    int* FUN_0043d4d0();
};
struct SettingFloatAccess
{
    float* FUN_00403e20();
};
extern SettingIntAccess DAT_011cdad0;
extern SettingFloatAccess DAT_011cd950;

struct ProcedureSetting
{
    float* FUN_00403e20();
};
extern const float DAT_01084838;
struct ProcedureProcess
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
    virtual void Update();
};
struct ProcedureActor
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
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
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
    virtual void Slot125();
    virtual void Slot126();
    virtual void Slot127();
    virtual void Slot128();
    virtual void Slot129();
    virtual void Slot130();
    virtual void Slot131();
    virtual void Slot132();
    virtual void Slot133();
    virtual void Slot134();
    virtual void Slot135();
    virtual void Slot136();
    virtual void Slot137();
    virtual void Slot138();
    virtual bool IsBusy(int);
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
    virtual void Slot224();
    virtual void Slot225();
    virtual void Slot226();
    virtual void Slot227();
    virtual void Slot228();
    virtual void Slot229();
    virtual void Slot230();
    virtual void Slot231();
    virtual void Slot232();
    virtual void Slot233();
    virtual void Slot234();
    virtual void Slot235();
    virtual void Slot236();
    virtual void Slot237();
    virtual void Slot238();
    virtual void Slot239();
    virtual void Slot240();
    virtual void Slot241();
    virtual void Slot242();
    virtual void Slot243();
    virtual void Slot244();
    virtual void Slot245();
    virtual void Slot246();
    virtual void Slot247();
    virtual void Slot248();
    virtual void Slot249();
    virtual void Slot250();
    virtual void Slot251();
    virtual void Slot252();
    virtual void Slot253();
    virtual void Slot254();
    virtual void Slot255();
    virtual void Slot256();
    virtual void Slot257();
    virtual void Slot258();
    virtual void Slot259();
    virtual void Slot260();
    virtual void Slot261();
    virtual void Slot262();
    virtual void Slot263();
    virtual void Slot264();
    virtual void Slot265();
    virtual void Slot266();
    virtual void Slot267();
    virtual void Slot268();
    virtual void ResetTargetPointer(Actor*);
    virtual void Advance();
    void FUN_00881680(int);
    float FUN_005723b0(Actor*, int, int);
    ProcedureProcess* FUN_008d8520();
};

struct CrimeEntry;
struct CrimeEntry
{
    TESObjectREFR* Reference();
    bool Done();
    int Kind();
};

struct PackageTargetView
{
    int FUN_00680080();
    void* FUN_00680020();
};
struct PackageView
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
    virtual bool Test(Actor*, int, float, int);
    PackageTargetView* FUN_00671d10();
    int FUN_00672930();
    int FUN_0041ca90();
    int FUN_009611e0();
};

namespace fnv_0091f6c0 {
/* First reconstruction for ProcessActorInteraction from packet disassembly (2026-10-23).
 * Ghidra's draft is unverified; all invoked entrypoints remain symbolic.
 */
struct Proc;
struct Actor;
struct Component;
struct Task;
struct Vec3
{
    float x, y, z;
    void FUN_00439ef0();
    float FUN_00457990();
};
struct TaskObject
{
    virtual void unused000();
    virtual void unused001();
    virtual void unused002();
    virtual void unused003();
    virtual void unused004();
    virtual void unused005();
    virtual void unused006();
    virtual void unused007();
    virtual void unused008();
    virtual void unused009();
    virtual void unused010();
    virtual void unused011();
    virtual void unused012();
    virtual void unused013();
    virtual void unused014();
    virtual void unused015();
    virtual void unused016();
    virtual void unused017();
    virtual void unused018();
    virtual void unused019();
    virtual void unused020();
    virtual void unused021();
    virtual void unused022();
    virtual void unused023();
    virtual void unused024();
    virtual void unused025();
    virtual void unused026();
    virtual void unused027();
    virtual void unused028();
    virtual void unused029();
    virtual void unused030();
    virtual void unused031();
    virtual void unused032();
    virtual void unused033();
    virtual void unused034();
    virtual void unused035();
    virtual void unused036();
    virtual void unused037();
    virtual void unused038();
    virtual void unused039();
    virtual void unused040();
    virtual void unused041();
    virtual void unused042();
    virtual void unused043();
    virtual void unused044();
    virtual void unused045();
    virtual void unused046();
    virtual void unused047();
    virtual void unused048();
    virtual void unused049();
    virtual void unused050();
    virtual void unused051();
    virtual void unused052();
    virtual void unused053();
    virtual void unused054();
    virtual void unused055();
    virtual void unused056();
    virtual void unused057();
    virtual void unused058();
    virtual void unused059();
    virtual void unused060();
    virtual void unused061();
    virtual void unused062();
    virtual void unused063();
    virtual unsigned char Ready();
    int FUN_007af430();
    TESForm* FUN_00567790();
    void FUN_00573170(Actor*, int, int, int);
};
struct Task
{
    TaskObject* owner;
    int formId;
    int unk08;
    int multiplier;
    int unk10;
    void* extra;
    int FUN_007b3fa0(int);
};
struct Component
{
    virtual void unused000();
    virtual void unused001();
    virtual void unused002();
    virtual void unused003();
    virtual void unused004();
    virtual void unused005();
    virtual void unused006();
    virtual void unused007();
    virtual void unused008();
    virtual void unused009();
    virtual void unused010();
    virtual void unused011();
    virtual void unused012();
    virtual void unused013();
    virtual void unused014();
    virtual void unused015();
    virtual void unused016();
    virtual void unused017();
    virtual void unused018();
    virtual void unused019();
    virtual void unused020();
    virtual void unused021();
    virtual void unused022();
    virtual void unused023();
    virtual void unused024();
    virtual void unused025();
    virtual void unused026();
    virtual void unused027();
    virtual void unused028();
    virtual void unused029();
    virtual void unused030();
    virtual void unused031();
    virtual void unused032();
    virtual void unused033();
    virtual void unused034();
    virtual void unused035();
    virtual void unused036();
    virtual void unused037();
    virtual void unused038();
    virtual void unused039();
    virtual void unused040();
    virtual void unused041();
    virtual void unused042();
    virtual void unused043();
    virtual void unused044();
    virtual void unused045();
    virtual void unused046();
    virtual void unused047();
    virtual void unused048();
    virtual void unused049();
    virtual void unused050();
    virtual void unused051();
    virtual void unused052();
    virtual void unused053();
    virtual void unused054();
    virtual void unused055();
    virtual void unused056();
    virtual void unused057();
    virtual void unused058();
    virtual void unused059();
    virtual void unused060();
    virtual void unused061();
    virtual void unused062();
    virtual void unused063();
    virtual void unused064();
    virtual void unused065();
    virtual void unused066();
    virtual void unused067();
    virtual void unused068();
    virtual void unused069();
    virtual void unused070();
    virtual void unused071();
    virtual void unused072();
    virtual void unused073();
    virtual void unused074();
    virtual void unused075();
    virtual void unused076();
    virtual void unused077();
    virtual void unused078();
    virtual void unused079();
    virtual void unused080();
    virtual void unused081();
    virtual void unused082();
    virtual void unused083();
    virtual void unused084();
    virtual void unused085();
    virtual void unused086();
    virtual void unused087();
    virtual void unused088();
    virtual void unused089();
    virtual void unused090();
    virtual void unused091();
    virtual void unused092();
    virtual void unused093();
    virtual void unused094();
    virtual void Work(int, int, int, int, int, Actor*, int, int, int, int);
    virtual void unused096();
    virtual void unused097();
    virtual void unused098();
    virtual void unused099();
    virtual void unused100();
    virtual void unused101();
    virtual void unused102();
    virtual void unused103();
    virtual void unused104();
    virtual void unused105();
    virtual void unused106();
    virtual void unused107();
    virtual void unused108();
    virtual void unused109();
    virtual void unused110();
    virtual void unused111();
    virtual void unused112();
    virtual void unused113();
    virtual void unused114();
    virtual void unused115();
    virtual void unused116();
    virtual void unused117();
    virtual void unused118();
    virtual void unused119();
    virtual void unused120();
    virtual void unused121();
    virtual void unused122();
    virtual void unused123();
    virtual void unused124();
    virtual Vec3* Position();
    bool FUN_00440d80();
    bool FUN_00440da0();
    int FUN_00568e50();
    Vec3* FUN_00568fa0(void*, const Vec3*);
    Vec3* Relative(int, int);
    int FUN_00575d70();
    int FUN_008d6f30();
};
struct Timer
{
    float FUN_00526ac0();
};
struct GlobalSettings
{
    float FUN_00867da0();
    void* FUN_00970a20(TESNPC*, int);
};
extern GlobalSettings DAT_011de7b8;
extern GlobalSettings DAT_011e0e80;
extern double DAT_010356d8;
extern double DAT_01012640;
extern int DAT_01183028;

extern "C" Timer* __cdecl FUN_004839c0(int);
extern "C" void __cdecl FUN_005ac750(void*, void*, int);
extern "C" int __cdecl FUN_00ec43fb(int, int, void*, void*, int);

struct Proc
{
    void** vtable;
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
    struct Component* component40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    struct Task* task64;
    bool FUN_00915ef0(Actor*);
    float FUN_007df1f0();
    void ProcessActorInteraction(Actor*);
};
typedef int(__thiscall* GetMode)(Proc*);
typedef void(__thiscall* ProcessActor)(Proc*, Actor*);
typedef void(__thiscall* ProcessActorFlag)(Proc*, Actor*, int);
typedef void(__thiscall* ProcessTask)(Proc*, void*);
typedef Actor*(__thiscall* GetActor)(Proc*);
typedef unsigned char(__thiscall* CheckActor)(Actor*, Actor*, int);
typedef Vec3*(__thiscall* GetComponentVector)(Component*);
typedef bool(__thiscall* Transfer)(Proc*, Actor*, Vec3, int, int);
typedef bool(__thiscall* TransferShort)(Proc*, Actor*, Vec3);
typedef void(__thiscall* ActorDoWork)(Component*, int, int, int, int, int, Actor*, int, int, int, int);
typedef unsigned char(__thiscall* TaskReady)(TaskObject*);

}  // namespace fnv_0091f6c0

namespace fnv_0091fb30 {
struct PackageAccess : TESForm
{
    virtual void Slot138();
    virtual bool IsEffectValid(TESObjectREFR*, int, float, bool);
    virtual bool CheckActor(TESObjectREFR*, Actor*, int, float, bool);
    TESObjectREFR* FUN_008d80e0();
    TESObjectREFR* FUN_009ee040();
    bool GetByteAtBD();
    int FUN_00672dd0();
    bool FUN_006727b0();
};
}  // namespace fnv_0091fb30

namespace fnv_00920150 {
struct ActorStand;
struct Node;
struct Process;
class B006815c0
{
  public:
    float x, y, z;
    B006815c0();
    B006815c0 FUN_004a0bd0() const;
    B006815c0 FUN_0053d280(float) const;
    B006815c0 FUN_00439ef0(B006815c0&);
    void FUN_00439180(float);
};
struct Active
{
    void UpdateRagDoll(int);
    void FUN_00450f90(int);
};
struct Node
{
    Node* FUN_0045bc00(int);
    B006815c0& FUN_0045bb80();
    Active* FUN_0043b4a0(int);
};
struct Anim
{
    void FUN_00c7ba10(int);
    void FUN_00c7d810();
    void bhkRagdollController_DisableRagdollAnim(int);
    void FUN_00c7a8d0();
};
struct Magic
{
    void FUN_00815b00();
};
struct Item
{
    int FUN_008041a0();
};
struct List
{
    int value;
    int FUN_00559450();
};
struct AnimState
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void v12();
    virtual void v16();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v32();
    virtual void v36();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v52();
    virtual void v56();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v72();
    virtual void v76();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v92();
    virtual void v96();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v112();
    virtual void v116();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v132();
    virtual void v136();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v152();
    virtual void v156();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v172();
    virtual void v176();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v192();
    virtual void v196();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v212();
    virtual void v216(int, int);
};
struct Process
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
    List unk124, unk128;
    void FUN_00496080(int, float);
    void FUN_00496280();
    void GetMovement(B006815c0*, ActorStand*, int, int);
    Node* FUN_0084e3a0();
    void FUN_00497ca0(void*, int);
    bool FUN_004981f0();
    Item* FUN_00491040(int);
    void FUN_00498910(int, int);
    bool FUN_00498230(ActorStand*);
    bool FUN_004985f0();
};
struct ActorStand
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48(int);
    virtual void v4c(int);
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual Process* v1e4();
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
    virtual int v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual bool v234();
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
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
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
    virtual void v2c4(float);
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
    Magic unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    Anim* unkac;
    Process* FUN_00950a60(int);
    bool FUN_008845a0();
    float FUN_00893500();
    int FUN_004f8960();
    void FUN_0088d640();
    Node* FUN_0043fcd0(int);
    Node* FUN_0043fcd0();
    bool FUN_00566950();
    void GetWeaponObject();
    void FUN_00934250();
    bool FUN_008bbc10();
    void SetActiveState(int, int, int);
    AnimState* FUN_008adcb0();
    const char* FUN_0055d520();
    bool FUN_008a8300(float);
    bool FUN_005a2030();
    Node* FUN_00571530(Node*, const char*);
    Active* FUN_005d43c0();
};
struct Manager
{
    void* FUN_00600950(ActorStand*, int);
};
extern Manager* DAT_011cb6a0;
struct Clock
{
    float FUN_00867da0();
    float FUN_00867950();
};
extern Clock DAT_011de7b8;
struct Timer
{
    float FUN_0084d030();
};
extern Timer DAT_011f6394;
extern Node* DAT_011e0410;
void __cdecl bhkWorld_SetMotion(Node*, int, int, int, int);
void __cdecl bhkRigidBody_SetFixed(Node*, int);
void __cdecl bhkRigidBody_SetFixed(Node*, int, int);
void __cdecl FUN_005b5e40(const char*, ...);
void __cdecl FUN_00c9bdf0(Node*, float);
struct Flag
{
    bool FUN_008a5170();
};
struct Info
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
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    Flag unk410;
};
struct Target
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual Info* v28c();
    virtual void v290();
    virtual void v294(ActorStand*);
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
    virtual void v420(ActorStand*);
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
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
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
    virtual void v52c();
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
    virtual void v5a0();
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
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
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
    bool unk124, unk125, unk126, unk127;
    int unk128;
    Node* unk12c;
    int unk130;
    int unk134;
    int unk138;
    signed char unk13c;
    bool HasCachedFlag(int);
    float FUN_007df1f0();
    void UpdateKnockedDownState(ActorStand* actor);
};
}  // namespace fnv_00920150

namespace fnv_00920b80 {
struct Face920b80
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
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual void f40();
    virtual void f44();
    virtual void f48();
    virtual void f4c();
    virtual void f50();
    virtual void f54();
    virtual void f58();
    virtual void f5c();
    virtual void f60();
    virtual void f64();
    virtual void f68();
    virtual void f6c();
    virtual void f70();
    virtual void f74();
    virtual void f78();
    virtual void f7c();
    virtual void f80();
    virtual void f84();
    virtual void f88();
    virtual void f8c();
    virtual void f90();
    virtual void f94();
    virtual void f98();
    virtual void f9c();
    virtual void fa0();
    virtual void fa4();
    virtual void fa8();
    virtual void fac();
    virtual void fb0();
    virtual void fb4();
    virtual void fb8();
    virtual void fbc();
    virtual void fc0();
    virtual void fc4();
    virtual void fc8();
    virtual void fcc();
    virtual void fd0();
    virtual void fd4();
    virtual void SetupBlink(int, int);
};

struct Extra920b80
{
    void UpdateRagDoll();
};

struct Node920b80
{
    void* FUN_0045bc00(bool);
    Node920b80* FUN_0043b4a0(unsigned int);
    void FUN_00450f90(bool);
};

struct Actor920b80
{
    virtual void a000();
    virtual void a004();
    virtual void a008();
    virtual void a00c();
    virtual void a010();
    virtual void a014();
    virtual void a018();
    virtual void a01c();
    virtual void a020();
    virtual void a024();
    virtual void a028();
    virtual void a02c();
    virtual void a030();
    virtual void a034();
    virtual void a038();
    virtual void a03c();
    virtual void a040();
    virtual void a044();
    virtual void a048();
    virtual void Reset3D(int);
    virtual void a050();
    virtual void a054();
    virtual void a058();
    virtual void a05c();
    virtual void a060();
    virtual void a064();
    virtual void a068();
    virtual void a06c();
    virtual void a070();
    virtual void a074();
    virtual void a078();
    virtual void a07c();
    virtual void a080();
    virtual void a084();
    virtual void a088();
    virtual void a08c();
    virtual void a090();
    virtual void a094();
    virtual void a098();
    virtual void a09c();
    virtual void a0a0();
    virtual void a0a4();
    virtual void a0a8();
    virtual void a0ac();
    virtual void a0b0();
    virtual void a0b4();
    virtual void a0b8();
    virtual void a0bc();
    virtual void a0c0();
    virtual void a0c4();
    virtual void a0c8();
    virtual void a0cc();
    virtual void a0d0();
    virtual void a0d4();
    virtual void a0d8();
    virtual void a0dc();
    virtual void a0e0();
    virtual void a0e4();
    virtual void a0e8();
    virtual void a0ec();
    virtual void a0f0();
    virtual void a0f4();
    virtual void a0f8();
    virtual void a0fc();
    virtual void a100();
    virtual void a104();
    virtual void a108();
    virtual void a10c();
    virtual void a110();
    virtual void a114();
    virtual void a118();
    virtual void a11c();
    virtual void a120();
    virtual void a124();
    virtual void a128();
    virtual void a12c();
    virtual void a130();
    virtual void a134();
    virtual void a138();
    virtual void a13c();
    virtual void a140();
    virtual void a144();
    virtual void a148();
    virtual void a14c();
    virtual void a150();
    virtual void a154();
    virtual void a158();
    virtual void a15c();
    virtual void a160();
    virtual void a164();
    virtual void a168();
    virtual void a16c();
    virtual void a170();
    virtual void a174();
    virtual void a178();
    virtual void a17c();
    virtual void a180();
    virtual void a184();
    virtual void a188();
    virtual void a18c();
    virtual void a190();
    virtual void a194();
    virtual void a198();
    virtual void a19c();
    virtual void a1a0();
    virtual void a1a4();
    virtual void a1a8();
    virtual void a1ac();
    virtual void a1b0();
    virtual void a1b4();
    virtual void a1b8();
    virtual void a1bc();
    virtual void a1c0();
    virtual void a1c4();
    virtual void a1c8();
    virtual void a1cc();
    virtual void a1d0();
    virtual void a1d4();
    virtual void a1d8();
    virtual void a1dc();
    virtual void a1e0();
    virtual void a1e4();
    virtual void a1e8();
    virtual void a1ec();
    virtual void a1f0();
    virtual void a1f4();
    virtual void a1f8();
    virtual void a1fc();
    virtual void a200();
    virtual void a204();
    virtual void a208();
    virtual void a20c();
    virtual void a210();
    virtual void a214();
    virtual void a218();
    virtual void a21c();
    virtual void a220();
    virtual void a224();
    virtual void a228();
    virtual void a22c();
    virtual void a230();
    virtual bool IsDead141();
    float GetFatigue();
    Node920b80* Get3DSimple();
    Extra920b80* FUN_005d43c0(bool);
    Face920b80* FUN_008adcb0();
};

void __cdecl bhkRigidBody_SetFixed(Node920b80*, bool, bool);
void __cdecl FUN_00c9bdf0(Node920b80*, float);
extern Actor920b80* g_thePlayer;

}  // namespace fnv_00920b80

struct P130Anim;
struct P130Ref;
struct P130Node;
struct P130Actor;
struct P130Ref
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
    virtual const char* GetTextValue();
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
    virtual int GetNumericValue();
    bool FUN_00567f80(int, bool);
    void FUN_00568020(int, bool);
    void FUN_00568150(int, bool);
    struct P130Marker* FUN_007af430();
};
struct P130Seq
{
    int FUN_008041a0();
};
struct P130Anim : Animation
{
    bool FUN_00498f80();
    bool IsFlaggedAsTwo();
    void FUN_00498910(bool, bool);
    void FUN_00497ca0(P130Node*, int);
    void CopyGlobalPosition();
    bool FUN_004981f0();
    P130Seq* FUN_00491040(int);
    void FUN_00498230(P130Actor*);
    bool FUN_004985f0();
    void FUN_004974a0();
    void FUN_004994f0(int, bool);
    int FUN_00921e30();
};
struct P130Node
{
    int GetFlagsMasked();
};
struct P130Service
{
    P130Node* FUN_00600950(P130Actor*, TESObjectREFR*);
};
extern P130Service* DAT_011cb6a0;
extern int* DAT_011a3ff0[];
struct P130Controller
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
    virtual void SetState(bool, bool);
};
struct P130Actor
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
    virtual P130Anim* GetAnimation();
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
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void SetMarker(NiPoint3*);
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void SetFurnitureHeading(float);
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual bool IsPlayer();
    virtual void v217();
    virtual void v218();
    virtual bool IsDead();
    void FUN_008a6840(int);
    int FUN_008a7570();
    bool HasAnyFlag();
    bool FUN_004997b0();
    void FUN_00884f80();
    void ForwardToVtSlot(int);
    void FUN_008b3ab0();
    void FUN_00895110(float, float);
    void FUN_00931fb0(bool);
    void FUN_008a73e0(int, bool);
    void FUN_00931d30(float);
    P130Controller* FUN_008adcb0();
    void FUN_0088d640();
};
struct P130Marker
{
    int FUN_005094b0();
    float GetFurnitureHeading(int);
    NiPoint3* FUN_006815c0();
    float FUN_00568650();
    void FUN_00c54550(float);
    void FUN_00568ab0(int);
    void FUN_0098ddd0(const NiPoint3*);
};
class HighProcess : public MiddleHighProcess
{
};
void FNV_Warning(const char*, ...);

namespace fnv_00921e80 {
struct AnimAccess;
struct FaceAccess;
struct BaseAccess;
struct RefAccess;
struct SeqAccess
{
    int state();
};
struct IdleAccess
{
    int kind();
};
struct ControllerAccess
{
    void update(void*);
};
struct AnimAccess
{
    void stop(int, int);
    bool playing();
    void reset();
    void blend(int, float);
    void idle(IdleAccess*, int);
    bool ready();
    SeqAccess* sequence(int);
    bool finished();
    void update(RefAccess*);
};
struct MarkerAccess
{
    unsigned int id();
};
struct BaseAccess
{
    float angle(unsigned int);
};
struct ManagerAccess
{
    IdleAccess* find(RefAccess*, RefAccess*);
};
extern ManagerAccess* DAT_011cb6a0;
bool IsFurnitureSleepMarker(unsigned int);
struct FaceAccess
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
    virtual void clear(int, int);
};
struct RefAccess
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
    virtual const char* name();
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
    virtual AnimAccess* animation();
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
    virtual bool npc();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void action(Actor*, int, int, int, int, int, int, int, int);
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual float heading(int);
    virtual void slot176();
    virtual void setHeading(float);
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual bool player();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void damage(int, float, int);
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();

    BaseAccess* base();
    FaceAccess* face();
    void release(unsigned char, int);
    void turn(float);
    void flag(bool);
    float fatigue();
    void pick(float, float);
    void* topic();
};
struct FurnitureProcess
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
    virtual void clearFurniture(RefAccess*);
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
    virtual void slot121();
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
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual TESPackage* package();
    virtual void slot160();
    virtual void slot161();
    virtual void end(RefAccess*, int);
    virtual ControllerAccess* controller();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void slot288();
    virtual void slot289();
    virtual void slot290();
    virtual void slot291();
    virtual void slot292();
    virtual void slot293();
    virtual void slot294();
    virtual void slot295();
    virtual void slot296();
    virtual void slot297();
    virtual void slot298();
    virtual void slot299();
    virtual void slot300();
    virtual void slot301();
    virtual void slot302();
    virtual void slot303();
    virtual void state(RefAccess*, int, RefAccess*, unsigned char);
    virtual unsigned int markerID();
    virtual RefAccess* furniture();
    virtual void slot307();
    virtual unsigned int index();
    virtual void slot309();
    virtual void slot310();
    virtual void slot311();
    virtual void slot312();
    virtual void slot313();
    virtual void slot314();
    virtual void slot315();
    virtual void slot316();
    virtual void slot317();
    virtual void slot318();
    virtual void slot319();
    virtual void slot320();
    virtual void slot321();
    virtual void slot322();
    virtual void slot323();
    virtual void slot324();
    virtual void slot325();
    virtual void slot326();
    virtual void slot327();
    virtual void slot328();
    virtual void slot329();
    virtual void slot330();
    virtual void slot331();
    virtual void slot332();
    virtual void slot333();
    virtual void slot334();
    virtual void slot335();
    virtual void slot336();
    virtual void slot337();
    virtual void slot338();
    virtual void slot339();
    virtual void slot340();
    virtual void slot341();
    virtual void slot342();
    virtual void slot343();
    virtual void slot344();
    virtual void slot345();
    virtual void slot346();
    virtual void slot347();
    virtual void slot348();
    virtual void slot349();
    virtual void slot350();
    virtual void slot351();
    virtual void slot352();
    virtual void slot353();
    virtual void slot354();
    virtual void slot355();
    virtual void slot356();
    virtual void slot357();
    virtual void slot358();
    virtual void slot359();
    virtual void slot360();
    virtual void slot361();
    virtual void slot362();
    virtual void slot363();
    virtual void slot364();
    virtual void slot365();
    virtual void slot366();
    virtual void slot367();
    virtual void slot368();
    virtual void slot369();
    virtual void slot370();
    virtual void slot371();
    virtual void slot372();
    virtual void slot373();
    virtual void slot374();
    virtual void slot375();
    virtual void slot376();
    virtual void slot377();
    virtual void slot378();
    virtual void slot379();
    virtual void slot380();
    virtual void slot381();
    virtual void slot382();
    virtual void slot383();
    virtual void slot384();
    virtual bool notify();
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
    unsigned char knock;
    unsigned char sitState;
    unsigned char unk13e;
    unsigned char unk13f;
    RefAccess* currentFurniture;
    unsigned char furnitureIndex;
    unsigned char unk145;
    unsigned char unk146;
    unsigned char unk147;
    MarkerAccess marker;
    bool FUN_00921e80(RefAccess* actor);
};

}  // namespace fnv_00921e80

namespace fnv_009231d0 {
struct EquipActor;
struct EquipEntry;
struct EquipNode;
struct EquipAnim;
struct EquipDescriptor;
struct EquipWeapon;
struct EquipProcess;
struct EquipNode
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
    virtual void SetVisible(int);
    EquipNode* FUN_0045bc00(int);
    void FUN_00450f90(bool);
};
struct EquipRef
{
    EquipNode* FUN_00559450();
};
struct EquipSoundData
{
    int flags;
    const char* name;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
struct EquipDescriptor
{
    const char* FUN_00511840();
    EquipSoundData CopyBig();
};
struct EquipWeapon
{
    bool FUN_0046e8c0();
    unsigned int GetByteAtOffset101();
    EquipDescriptor* FUN_00522500();
};
struct EquipEntry
{
    EquipWeapon* FUN_0044ddc0();
};
struct EquipLink
{
    void* FUN_00726070();
};
struct EquipSequence
{
    EquipSequence* FUN_0048f7f0();
    int FUN_005f2420();
};
struct EquipAnim
{
    int FUN_0084e3a0();
    unsigned short FUN_004301b0(int);
    void FUN_00494740(unsigned short);
    EquipSequence* FUN_00491040(int);
    void FUN_004994f0(int, int);
};
struct FUN_0041a250
{
    unsigned int id, flags;
    void* data;
    FUN_0041a250();
    ~FUN_0041a250();
    void FUN_004189c0(FUN_0041a250*);
    bool FUN_00ad8ce0();
    void FUN_00418900(const FUN_0041a250&);
    void FUN_004f15a0(int);
    void FUN_00ad8f20(EquipNode*);
    void SetPositionFromArray(void*);
    bool FUN_00ad8930();
    void FUN_00ad8830(int);
    void FUN_00ad88f0();
    void FUN_0041a3e0(const FUN_0041a250&);
};
struct EquipAudio
{
    FUN_0041a250 FUN_00ad7480(const char*, unsigned int, EquipDescriptor*);
};
struct EquipActor
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
    virtual EquipNode* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void* GetPosition();
    void FUN_0088c790(EquipWeapon*, int, int, int, int, int);
    unsigned short FUN_00897910(unsigned int, EquipEntry*, bool, EquipAnim*, int, int, int);
    EquipAnim* FUN_00950a60(int);
    void GetWeaponObject();
    FUN_0041a250* FUN_005d43c0();
    bool Script_IsCurrentFurnitureObj();
    void FUN_00884f80();
};
struct EquipProcess
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
    virtual EquipEntry* GetAmmo();
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
    virtual EquipNode* GetModelFilePath(EquipRef*);
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
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual bool IsBusy();
    virtual void v276();
    virtual bool IsChanging();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void SetFlags(unsigned int);
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
    int unkd4;
    int unkd8;
    int unkdc;
    unsigned short unke0;
    bool pending, drawn;
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
    EquipEntry* entry;
    EquipLink* link;
    void FUN_00483710();
    void UpdateWeaponDrawnAnimation(bool, EquipRef*, EquipAnim*, EquipActor*);
    void UpdateEquipVisuals(bool, EquipRef*, EquipAnim*, EquipActor*);
};
struct EquipState
{
    bool FUN_0047c850();
};
extern EquipActor* DAT_011dea3c;
extern EquipState* DAT_011de45c;
EquipNode* FUN_004aae30(EquipNode*, const char*);
EquipAudio* FUN_00453a70();
}  // namespace fnv_009231d0

struct ItemChangeStub;
struct EquipListStub
{
    ItemChangeStub* FindItem(int aiType, int aiUnk);
};
struct ExtraListStub
{
    EquipListStub* GetEquipList();
};
struct ItemChangeStub
{
    TESForm* GetObject();
};
struct RefStub
{
    ExtraListStub* GetExtraList();
    void ResetWeaponModel();
    void SetWeaponForm(TESForm* apForm);
    void Update3DParts();
    void SetAmmoForm(TESForm* apForm);
};

namespace fnv_00924560 {
struct Named86
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
    virtual const char* Name();
};
Named86* FUN_004839c0(unsigned int);
void __cdecl FUN_0040fbe0(const char*, ...);
void __cdecl FUN_005b5e40(const char*, ...);
}  // namespace fnv_00924560

namespace fnv_00925490 {

struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

TESForm* FUN_004839c0(unsigned int);
MagicItem* BaseExtraList_RemoveAll(unsigned int);
MagicTarget* FUN_00825550(unsigned int);

}  // namespace fnv_00925490

struct ResetLoader
{
    bool IsLoading();
};
extern ResetLoader* g_TESSaveLoadGame;

struct SaveBuffer58;
struct Flag58
{
    unsigned int bits;
    bool FUN_004280f0();
};
struct SaveBuffer58
{
    virtual void v0();
    virtual void v1();
    virtual unsigned int v2();
    void FUN_00865e50(void*, unsigned int, int);
    void FUN_00865df0(void*, int);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(unsigned int, unsigned int);
    Flag58 FUN_00428110(unsigned int);
    unsigned int FUN_0084e3a0();
    void FUN_00865db0(unsigned int, int);
};

struct P124Point
{
    float x, y, z;
    P124Point();
    P124Point operator+(const P124Point&) const;
};
struct P124Matrix
{
    P124Matrix();
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_004a0c90(float);
    P124Point FUN_004b4500(const P124Point*);
};
struct P124Marker
{
    P124Point position;
    unsigned short heading;
    unsigned char number, flags;
    P124Point& FUN_006815c0();
    unsigned int FUN_005094b0();
    float FUN_00568650();
    void FUN_00568ab0(unsigned int);
    void FUN_0098ddd0(P124Point*);
    void FUN_00c54550(float);
};
struct P124Model
{
    P124Marker& FUN_005094d0(unsigned int);
};
P124Model* FUN_00c54400(NiNode*);
void FUN_00a582f0(const P124Matrix*, P124Point*, bool, P124Point*, P124Point*);

struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
float FUN_00404010(float, float);

namespace fnv_00929960 {
struct ActV;
struct PkgObj;
struct TargObj;
struct CellObj;
struct ListObj;

struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
extern double DAT_01012060;
extern float DAT_01012054;

struct ExtraObj
{
    PkgObj* FUN_0041cb10();
};
struct TargObj
{
    bool FUN_004985f0();
};
struct PkgObj
{
    int FUN_0041ca90();
    CellObj* FUN_005f36f0();
    int FUN_00546930();
};
struct ListObj
{
    int o00;
    int o04;
    int o08;
    int o0c;
    ListObj(int cap);
    ~ListObj();
    int* FUN_00877a30(int idx);
};
struct CellObj
{
    int FUN_00479e80();
    int FUN_0047a030(ActV* a, int b, ListObj* c);
    bool FUN_00929d20();
};
struct ActV
{
    virtual void vt000();
    virtual void vt001();
    virtual void vt002();
    virtual void vt003();
    virtual void vt004();
    virtual void vt005();
    virtual void vt006();
    virtual void vt007();
    virtual void vt008();
    virtual void vt009();
    virtual void vt010();
    virtual void vt011();
    virtual void vt012();
    virtual void vt013();
    virtual void vt014();
    virtual void vt015();
    virtual void vt016();
    virtual void vt017();
    virtual void vt018();
    virtual void vt019();
    virtual void vt020();
    virtual void vt021();
    virtual void vt022();
    virtual void vt023();
    virtual void vt024();
    virtual void vt025();
    virtual void vt026();
    virtual void vt027();
    virtual void vt028();
    virtual void vt029();
    virtual void vt030();
    virtual void vt031();
    virtual void vt032();
    virtual void vt033();
    virtual void vt034();
    virtual void vt035();
    virtual void vt036();
    virtual void vt037();
    virtual void vt038();
    virtual void vt039();
    virtual void vt040();
    virtual void vt041();
    virtual void vt042();
    virtual void vt043();
    virtual void vt044();
    virtual void vt045();
    virtual void vt046();
    virtual void vt047();
    virtual void vt048();
    virtual void vt049();
    virtual void vt050();
    virtual void vt051();
    virtual void vt052();
    virtual void vt053();
    virtual void vt054();
    virtual void vt055();
    virtual void vt056();
    virtual void vt057();
    virtual void vt058();
    virtual void vt059();
    virtual void vt060();
    virtual void vt061();
    virtual void vt062();
    virtual void vt063();
    virtual void vt064();
    virtual void vt065();
    virtual void vt066();
    virtual void vt067();
    virtual void vt068();
    virtual void vt069();
    virtual void vt070();
    virtual void vt071();
    virtual void vt072();
    virtual void vt073();
    virtual void vt074();
    virtual void vt075();
    virtual void vt076();
    virtual void vt077();
    virtual void vt078();
    virtual void vt079();
    virtual void vt080();
    virtual void vt081();
    virtual void vt082();
    virtual void vt083();
    virtual void vt084();
    virtual void vt085();
    virtual void vt086();
    virtual void vt087();
    virtual void vt088();
    virtual void vt089();
    virtual void vt090();
    virtual void vt091();
    virtual void vt092();
    virtual void vt093();
    virtual void vt094();
    virtual void vt095();
    virtual void vt096();
    virtual void vt097();
    virtual void vt098();
    virtual void vt099();
    virtual void vt100();
    virtual void vt101();
    virtual void vt102();
    virtual void vt103();
    virtual void vt104();
    virtual void vt105();
    virtual void vt106();
    virtual void vt107();
    virtual void vt108();
    virtual void vt109();
    virtual void vt110();
    virtual void vt111();
    virtual void vt112();
    virtual void vt113();
    virtual void vt114();
    virtual void vt115();
    virtual void vt116();
    virtual void vt117();
    virtual void vt118();
    virtual void vt119();
    virtual void vt120();
    virtual TargObj* vt121();
    virtual void vt122();
    virtual void vt123();
    virtual void vt124();
    virtual void vt125();
    virtual void vt126();
    virtual void vt127();
    virtual void vt128();
    virtual void vt129();
    virtual void vt130();
    virtual void vt131();
    virtual void vt132();
    virtual void vt133();
    virtual void vt134();
    virtual void vt135();
    virtual void vt136();
    virtual void vt137();
    virtual void vt138();
    virtual void vt139();
    virtual void vt140();
    virtual bool vt141();
    ExtraObj* FUN_005d43c0();
};

}  // namespace fnv_00929960

struct Actor9;
struct ObjA9;
struct ObjB9;
struct ObjC9;
struct ObjPkg9;
struct Obj309;
class TESObjectCELL;
bool __fastcall FUN_00425fd0(TESObjectCELL*);
class TESActorBase;
struct TESTopicInfo
{
    TESActorBase* GetSpeaker();
};

struct RequestLocation9
{
    void* vtable;
    NiPoint3 position;
    void* field10;
    void* field14;
    void* field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
};
struct PathingRequest
{
    virtual ~PathingRequest();
    unsigned int refCount;
    unsigned int field08;
    RequestLocation9 start;
    RequestLocation9 destination;
    NiPoint3 direction;
    float field68, field6c, field70, radius, field78;
    NiPoint3 field7c;
    float field88, field8c, field90;
    void* field94;
    bool field98, field99, field9a, field9b, field9c, field9d, field9e, field9f;
    bool fielda0, fielda1, fielda2, fielda3, fielda4;
    unsigned int fielda8;
    bool fieldac;
    PathingRequest();
    void SetUseSoft(bool);
};
struct Obj309
{
    unsigned int FUN_00441110();
    ObjC9* FUN_006dd4f0();
    NiPoint3 FUN_005c3420();
};
struct ObjC9 : TESObjectREFR
{
    void* FUN_00575d70();
    ObjC9* FUN_008d6f30();
    float FUN_005723b0(void*, int, int);
    bool FUN_00425fd0();
};
struct ObjPkg9
{
    unsigned int FUN_00676280(Actor9*);
};
struct ObjB9
{
    unsigned int FUN_00676280(Actor9*);
    int FUN_0055b980();
    void* FUN_00675a50(Actor9*);
    void* FUN_00675c20(Actor9*);
    NiPoint3 FUN_00675de0(Actor9*);
};
struct ObjA9
{
    void* m_00;
    int m_04;
    bool FUN_009f56b0(Actor9*, float);
    void* FUN_00639b40();
    ObjC9* FUN_0044edb0();
    void ClearTargetReferences(Actor9*, ObjB9*);
    void SelectSandboxActivity(Actor9*, ObjB9*);
    bool FUN_009f4300(Actor9*, int);
    bool FUN_009f43c0(Actor9*);
    bool FUN_009f3c10();
    void FUN_009f3af0(Actor9*, int);
    unsigned int FUN_0044ddc0();
};
struct Actor9 : Actor
{
    bool FUN_008b3bd0();
    void PathToLocation(PathingRequest*, NiPoint3 const&, void*, void*, float, int);
    void SetPathingRequestAvoidNodes(PathingRequest*);
    void FUN_008b3d30();
};
ObjC9* FUN_0044edb0(ObjA9*);
float __cdecl FUN_00404010(float, float);
float __cdecl FUN_006e25d0();
extern float DAT_01012054;
extern double DAT_01012060;

struct SleepController
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual bool IsActive();
    virtual void SetActive(bool, bool);
};
struct FurnitureActorAccess
{
    SleepController* FUN_008adcb0();
};
struct FurnitureProcess : MiddleHighProcess
{
    virtual void unused493();
    virtual void unused494();
    virtual void unused495();
    virtual void unused496();
    virtual void unused497();
    virtual void BeginFurniture(Actor*, int);
    void FUN_0092c680();
    bool TryUseFurniture(Actor* actor, TESObjectREFR* furniture);
};

namespace fnv_0092ac10 {
struct Time
{
    float FUN_00867da0();
};

extern Time DAT_011de7b8;

}  // namespace fnv_0092ac10

struct B570TimeCalls
{
    float FUN_0084d030();
};
extern B570TimeCalls DAT_011f6394;
extern TESBoundObject* DAT_011ca248;
float FUN_006e25d0();
float FUN_00404010(float, float);

struct WeaponObjStub
{
    bool IsWeaponFlag();
    int GetWeaponSkillIndex();
};

struct InventoryStackRecord
{
    WeaponObjStub* GetWeaponObj();
    float GetWeaponConditionHealth(bool abBase);
};

struct ArmorForm : TESForm
{
    int FUN_00401170();
};
struct TESBipedModelForm
{
    bool FUN_00480d30();
    bool IsPowerArmor();
    bool FUN_00480af0(int, bool, bool);
    bool GetIsHeavyArmor() const;
};
struct TESObjectARMO : ArmorForm
{
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
    TESBipedModelForm bipedModel;
};
struct InventoryItem
{
    ArmorForm* GetObject();
    bool FUN_004bddd0(bool);
};
class InventoryChanges
{
  public:
    BSSimpleList<InventoryItem*>* items;
    static InventoryChanges* GetOrAddInventoryChanges(TESObjectREFR*);
};

namespace fnv_00924220 {
struct SaveLoadEntry
{
    unsigned int formID;
};

class TESSaveLoadGame
{
  public:
    bool FUN_00862110();
    unsigned char FUN_008df040();
    SaveLoadEntry* FUN_004fd3e0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

TESForm* __cdecl FUN_004839c0(unsigned int);
void __cdecl FUN_0040fbe0(const char*, ...);

}  // namespace fnv_00924220

namespace fnv_00924b90 {

class FUN_008579e0_shell
{
  public:
    void FUN_008579e0(void* dst, unsigned int size);
};

class TESSaveLoadGame : public FUN_008579e0_shell
{
  public:
    bool FUN_00862110();
    void* FUN_004fd3c0();
    unsigned char FUN_008df040();
    unsigned int FUN_00825c00();
    void FUN_00857aa0(unsigned int* dst, int size);
    void FUN_00857bd0(unsigned int size);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

class PlayerCharacter
{
  public:
    bool FUN_004eaf60();
};
extern PlayerCharacter* _g_thePlayer;

class NiAVObject
{
  public:
    NiAVObject* FUN_0045bc00(int);
};

struct TESObjectREFRExt : TESObjectREFR
{
    NiAVObject* Get3DSimple();
};

extern void FNV_Warning(const char* fmt, ...);
extern TESForm* FUN_004839c0(unsigned int formID);

class TargetProcess : public MiddleHighProcess
{
  public:
    void FUN_0092e730(unsigned int, unsigned int, MobileObject*);
    void LoadFromSave(unsigned int a1, unsigned int a2, MobileObject* a3);
};

}  // namespace fnv_00924b90

namespace fnv_0092b030 {
// 0x0092b030  unit_250b7e0d4394.cpp  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, 2 stack args (ret 8).
extern "C" char DAT_011ca248;

struct Pos92
{
    float x;
    float y;
    float z;
    Pos92 operator-(const Pos92& bb5) const;
    float Length() const;
};
struct Ref92;
struct Pkg92;
struct Cell92;
struct Memb92
{
    float FUN_009dcbf0();
};
struct Extra92
{
    void* FUN_0041fe90();
};

float FUN_00404010(float a, float b);
float FUN_006e25d0();

struct Ref92
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual void r64();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual void r76();
    virtual void r77();
    virtual void r78();
    virtual void r79();
    virtual void r80();
    virtual void r81();
    virtual void r82();
    virtual void r83();
    virtual void r84();
    virtual void r85();
    virtual void r86();
    virtual void r87();
    virtual void r88();
    virtual void r89();
    virtual void r90();
    virtual void r91();
    virtual void r92();
    virtual void r93();
    virtual void r94();
    virtual void r95();
    virtual void r96();
    virtual void r97();
    virtual void r98();
    virtual void r99();
    virtual void r100();
    virtual void r101();
    virtual void r102();
    virtual void r103();
    virtual void r104();
    virtual void r105();
    virtual void r106();
    virtual void r107();
    virtual void r108();
    virtual void r109();
    virtual void r110();
    virtual void r111();
    virtual void r112();
    virtual void r113();
    virtual void r114();
    virtual void r115();
    virtual void r116();
    virtual void r117();
    virtual void r118();
    virtual void r119();
    virtual void r120();
    virtual void r121();
    virtual void r122();
    virtual void r123();
    virtual void r124();
    virtual Pos92* v1f4();
    char pad194[0x190 - 4];
    Memb92* pMemb;
    bool FUN_008b3b90();
    bool FUN_008b3bb0();
    float FUN_005723b0(void* a, int b, int c);
    Ref92* FUN_007af430();
    int FUN_00401170();
    Extra92* GetExtraData();
};

struct Pkg92
{
    bool FUN_0067a480();
    float FUN_00678670(void* a, int b);
    Cell92* GetPrevPath();
    unsigned FUN_00676280(void* a);
};
struct Cell92
{
    int GetByte5();
};

}  // namespace fnv_0092b030

namespace ProcessActivate {

struct ActCalendar
{
    float FUN_00867da0();
};
extern ActCalendar DAT_011de7b8;

struct ActGlobal
{
    float FUN_00526ac0();
};

extern void* DAT_011ca248;
extern void* DAT_011ca244;
ActGlobal* __cdecl FUN_004839c0(unsigned int auiFormID);

}

namespace fnv_00918ee0 {
// 0x00918ee0  MiddleHighProcess::UpdateActorPackage  /MT /Od /Oy- /GS /EHsc /Gy

class TESObjectCELL;
class TESWorldSpace;

struct Pt
{
    float x;
    float y;
    float z;
    Pt operator-(const Pt& r) const;
    float Length() const;
};

union SETTING_VALUE
{
    int i;
    float f;
};
struct Setting_S
{
    float f;
};

struct SettingInt
{
    SETTING_VALUE* FUN_0043d4d0();
};
struct FloatSetting
{
    Setting_S* FUN_00403e20();
};
struct HourObj
{
    float FUN_00867da0();
};

struct Pkg
{
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual void d064();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual bool v13c(Actor* a, int b, float c, int d);
    bool FUN_008a6290();
    void SetFlag10000(bool b);
    int FUN_0041ca90();
    void* FUN_0055b980();
    float GetPackageResult(Actor* a, bool b);
    bool FUN_00674d40();
};

struct V1f4
{
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual void d064();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual Pt* v1f4();
};

extern "C" Actor* g_thePlayer;
extern "C" SettingInt DAT_011cdad0;
extern "C" FloatSetting DAT_011cd950;
extern "C" HourObj DAT_011de7b8;
extern "C" float DAT_01012054;
extern "C" double DAT_01012640;
extern "C" double DAT_010356d8;
void* FUN_004839c0(int a);

}  // namespace fnv_00918ee0

template <int N> struct Slots : Slots<N - 1>
{
    virtual void slot(Slots<N>*);
};
template <> struct Slots<0>
{
    virtual void slot(Slots<0>*);
};
struct Ref91;
struct Point91;
struct Point91
{
    float off00, off04, off08;
    Point91();
    Point91 operator-(const Point91&) const;
    void unitize();
    Point91* scale(float);
};
__declspec(align(16)) struct Aligned91
{
    char off00[16];
    Aligned91();
};
struct Body91
{
    void position(Point91*);
    void impulse(Point91*, float);
};
struct Ragdoll91
{
    void a(int);
    void b(int);
};
struct Filter91
{
    int value();
};
struct Pen91
{
    void apply(NiNode*, int);
};
struct Ref91
{
    char off000[0xac];
    Ragdoll91* off0ac;
    Pen91* off0b0;
    bool valid();
    Body91* body();
    void prepare();
    NiNode* node();
    Filter91* filter(int*);
    void* weapon();
};
struct SettingValue91
{
    float off00;
};
struct Setting91
{
    SettingValue91* Float();
};
extern Setting91 settingA91, settingB91, settingC91;
extern bool FUN_008c7aa0();
extern void bhkWorld_SetMotion(NiNode*, int, bool, bool, bool);

namespace fnv_00926690 {
namespace load926 {
struct Vec3
{
    float x;
    float y;
    float z;
    Vec3();
};
struct Vector4f
{
    int a;
    int b;
    int c;
    int d;
};
struct SaveGame
{
    void FUN_008579e0(void* data, int size);
    unsigned char FUN_008df040();
};
struct Sub410
{
    void FUN_006296b0(int a);
    void FUN_00629670(int flags, int a);
};
struct Proc
{
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
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    Sub410 m410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    Vector4f m4f0;
    Vector4f m500;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int m520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int m540;
    float m544;
    int m548;
    int m54c;
    int m550;
    int unk554;
    int m558;
    void FUN_008e2680(int state);
    void FUN_005620e0(Vec3* pos);
    void FUN_00926980(Vec3* v);
    bool FUN_0088b0c0();
    bool FUN_009269f0();
};
}
using namespace load926;
extern SaveGame* DAT_011de45c;

}  // namespace fnv_00926690

namespace proc92a {
}
using namespace proc92a;

namespace s44b130 {

}

struct xNode;
struct xLog;
struct xActor;
struct xBuf;

struct xChangeFlags
{
    unsigned int uiFlags;
    xChangeFlags(unsigned int f);
    operator bool() const;
};

struct xExtraData
{
    void* GetItem(int a, int b);
};

struct xExtra
{
    xExtraData* GetData();
};

struct xNpc
{
    void Refresh(xActor* a, int b, int c, int d);
};

struct xBuf
{
    virtual unsigned char GetVersion();
    virtual void v004();
    virtual void v008();
    virtual xActor* GetForm();
    void Read(void* p, int n);
    void ReadRef(void* p);
    unsigned int ReadFormID();
    unsigned int ReadCount();
    xChangeFlags GetChangeFlags(unsigned int mask);
};

struct xActor
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
    virtual xNode* Get3D();
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
    virtual bool IsPlayerTeammate();
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
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
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
    virtual void Equip(void* a, int b, bool c);
    void SetFurnitureState(unsigned char c);
    xExtra* GetExtra();
    const char* GetFullName();
    void SetItem(void* p);
    xLog* GetLog();
    xNpc* GetBase();
    void* ComputePositionAtTime(xActor* a);
    bool CheckAnim(int a, void* b);
    void Reset3D();
};

struct xLog
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
    virtual void Log168(int a);
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
    virtual void Log1cc(bool b);
};

struct MatchQueue_9294b0
{
    void Drop(ArrowProjectile*);
};
namespace ArrowDrop_9294b0 {
extern "C" MatchQueue_9294b0 DAT_011e0e80;
}

namespace fnv_00919f60 {

struct RefListClear
{
    void FUN_00470470();
};

extern Actor* DAT_011dea3c;

__if_not_exists(TargetDoorController::~TargetDoorController)
{
    class TargetDoorController
    {
      public:
        ~TargetDoorController();
    };
}

enum ProcedurePackageType
{
    ProcedurePackageTypeInvalid = -1
};

struct PackageProcedureAccess
{

    int FUN_009611e0();

    bool FUN_008a6290();

    ProcedurePackageType FUN_0041ca90();

    struct ProcedureTarget* FUN_00671d10();

    struct ProcedureDuration* FUN_0041d8a0();

    struct ProcedureLocation* FUN_00675920();

    bool FUN_00674d40();

    bool FUN_00678610();

    bool FUN_00670f90();

    void SetFlag10000(int);
};

struct ProcedureTarget
{
    int FUN_0044ddc0();
};

struct ProcedureDuration
{
    int FUN_00726070();
};

struct ProcedureLocation
{
    bool FUN_004f1540();
};

struct ProcedureCell
{
    bool FUN_00450fb0();
    bool FUN_00425fd0();
};

struct ProcedureActor : Actor
{

    ProcedureCell* FUN_008d6f30();

    BaseProcess* FUN_008d8520();

    bool FUN_008b3bb0();

    bool FUN_008b3bf0();

    void FUN_008a8f60();

    TESPackage* FUN_009344a0();

    float FUN_005723b0(TESObjectREFR*, int, int);

    void* FUN_005d43c0();
};

struct ProcedureSetting
{
    float* FUN_00403e20();
    int* FUN_0043d4d0();
};

struct ProcedureManager
{
    bool FUN_00867d60();
};

extern ProcedureSetting DAT_011cdbac, DAT_011cd82c, DAT_011cdad0;

extern ProcedureManager DAT_011de7b8;

extern int* DAT_011a3ff0[];

void FUN_00703180();

void FUN_005ac750(TESPackage*, void*, int);

struct ProcedureProcess : MiddleHighProcess
{

    virtual void Procedure7B4(Actor*);

    virtual void ReservedSlot494();

    virtual void Procedure7BC(Actor*, bool);

    virtual void ReservedSlot496();

    virtual void Procedure7C4(Actor*);

    virtual void Procedure7C8(Actor*, bool);

    virtual void Procedure7CC(Actor*);

    virtual void Procedure7D0(Actor*);

    virtual void Procedure7D4(Actor*);

    virtual void Procedure7D8(Actor*);

    virtual void Procedure7DC(Actor*);

    virtual void Procedure7E0(Actor*);

    virtual void Procedure7E4(Actor*);

    virtual void Procedure7E8(Actor*);

    virtual void ReservedSlot507();

    virtual void ReservedSlot508();

    virtual void ReservedSlot509();

    virtual void ReservedSlot510();

    virtual void Procedure7FC(Actor*);

    virtual void Procedure800(Actor*);

    virtual void ReservedSlot513();

    virtual void Procedure808(Actor*);

    virtual void ReservedSlot515();

    virtual void ReservedSlot516();

    virtual void ReservedSlot517();

    virtual void ReservedSlot518();

    virtual void ReservedSlot519();

    virtual void ReservedSlot520();

    virtual void ReservedSlot521();

    virtual void ReservedSlot522();

    virtual void Procedure82C();

    virtual void ReservedSlot524();

    virtual void ReservedSlot525();

    virtual void ReservedSlot526();

    virtual void Procedure83C(Actor*);

    virtual void Procedure840(Actor*);

    virtual void ReservedSlot529();

    virtual void Procedure848(Actor*, bool, bool);

    void FUN_00919f60(ProcedureActor* object);
};

}  // namespace fnv_00919f60

extern int DAT_0118a838[];
extern int DAT_011e0410;
class SoundAccess
{
  public:
    const char* FUN_00511840();
};
class AnimAccess
{
  public:
    NiNode* FUN_005585e0();
    NiControllerManager* FUN_00496940();
};
class AudioAccess
{
  public:
    void FUN_00ad8100(const char*, unsigned int, SoundAccess*);
};
AudioAccess* FUN_00453a70();

namespace fnv_00928d90 {
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
};
class FUN_0081f580 : public NiMemObject
{
  public:
    virtual ~FUN_0081f580();
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
    virtual bool Update();
    FUN_0081f580(Actor*, TESEffectShader*, float);
    void FUN_00929260(unsigned char);
    void FUN_00929240(float);
    TESEffectShader* FUN_00671d10();
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
};
struct ShaderManager
{
    FUN_0081f580* FUN_00974cb0(Actor*);
    FUN_0081f580* FUN_00974db0(Actor*, TESEffectShader*);
    void FUN_00973fd0(FUN_0081f580*);
};
extern ShaderManager DAT_011e0e80;
class PlayerCharacter : public Actor
{
  public:
    int FUN_00490f80();
    FUN_0081f580* GetField6A4();
    void FUN_00929220(FUN_0081f580*);
};
extern PlayerCharacter* pPlayer;
}  // namespace fnv_00928d90

namespace fnv_0092bd00 {
struct Actor;
struct ActorCause;
struct ActorValueStore;
struct ActorValueOwner;
struct AlchemyItem;
struct AnimIdle;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimGroupSequence;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct ActorCombatGroup;
struct Crime;
struct GameFormRecord;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLeveledItem;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct GuardActorPackageData;
struct HWND__;
struct BooleanIntegerAccessor;
struct HighProcess;
struct InventoryChanges;
struct InventoryStackRecord;
struct KFModel;
struct CellDataNode;
struct LipSyncAnimation;
struct MapMarkerData;
struct MobileObject;
struct DetectionEventData;
struct Point3Offset;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

class QueuedFile
{
  public:
    bool FUN_0043caa0();
};
class NiNode;
class Model
{
  public:
    void IncRefCount();
    void DecRefCount();
    NiNode* GetObject3D();
};
class ProjectileCloneLoader
{
  public:
    void FUN_004472a0(const char*, NiPointer<Model>*);
};
__if_not_exists(g_modelLoader)
{
    extern ProjectileCloneLoader* g_modelLoader;
}
class InventoryStackRecord
{
  public:
    void* FUN_0044ddc0();
};
class ActorSupportClass
{
  public:
    NiNode* node;
    int count;
    int used;
    ActorSupportClass(NiNode*, int);
};

}  // namespace fnv_0092bd00

class NiUpdateData
{
  public:
    float fTime;
    unsigned int unk4;
    unsigned int unk8;
    NiUpdateData(float, bool, bool);
};

class NiAVObject
{
  public:
    virtual ~NiAVObject();
    void Update(const NiUpdateData&);
};

class NiNode : public NiAVObject
{
};

class S_006815c0
{
  public:
    void* _ref_006815c0();
};

class ThreeByThreeMatrix : public S_006815c0
{
  public:
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    void FUN_004a0c90(float);
    NiPoint3 FUN_004b4500(const NiPoint3*) const;
};

using ::TESBoundObject;
__if_not_exists(TESBoundObject::TESBoundObject)
{
    class TESBoundObject : public TESForm
    {
    };
}

class TESFurniture : public TESBoundObject
{
  public:
    NiPoint3 FUN_00509920(unsigned int, float);
    float GetFurnitureHeading(unsigned int);
};

struct TESObjectREFRExt : public TESObjectREFR
{
    NiAVObject* Get3DSimple();
    void FUN_00568020(unsigned int, bool);
    ThreeByThreeMatrix FUN_0056fa00();
    ::NiNode* GetNiNode();
    NiPoint3* GetPos() const;
};

class bhkCharacterController
{
  public:
    void FUN_005620e0(void*);
};

class PlayerCharacter : public Actor
{
  public:
    Animation* GetAnimation(bool);
    BipedAnim* GetBipedAnim(bool);
    NiNode* GetNode(bool);
    bool FUN_004eaf60();
    void FUN_00950110(bool);
    void FUN_005098c0();
};

extern PlayerCharacter* _g_thePlayer;

class FinishLoadSaveGameView
{
  public:
    void AddFormToList(MobileObject*);
};

namespace FinishLoadGlobals {
extern FinishLoadSaveGameView* DAT_011de45c;
}

class ActorStandIn : public Actor
{
  public:
    void FUN_00931d30(float);
    float GetScale();
    bhkCharacterController* GetPhysicsCharacterController();
};

namespace FinishLoadCalls {
NiAVObject* FUN_00c54400(::NiNode*);
}
void FUN_00a582f0(const ThreeByThreeMatrix&, NiPoint3*, int, const NiPoint3*, const NiPoint3*);
void FUN_00c69fc0(NiAVObject*, bool, bool, bool);
void bhkWorld_SetMotion(NiAVObject*, bool, bool, bool, bool);

namespace fnv_00928510 {
using ::Actor;
using ::MiddleHighProcess;
using ::NiNode;
using ::SIT_SLEEP_STATE;
using ::TESObjectREFR;

class Animation;
struct NiAVObject;
namespace FurnitureDecls {
extern "C" NiAVObject* __cdecl FUN_00c54400(NiNode*);
}

struct ActorStandIn
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
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void SetLookingTarget(float);
};

class PlayerCharacter : public Actor
{
  public:
    bool FUN_004eaf60();
    Animation* GetAnimation(bool);
    void FUN_005c4210(bool);
};

extern PlayerCharacter* g_thePlayer;

class TESIdleForm
{
  public:
    int GetFlagsMasked();
};

class Animation
{
  public:
    void FUN_00498030(TESIdleForm*, Actor*, int);
};

struct TIM_008b2010
{
    TESIdleForm* FUN_00600950(Actor*, TESObjectREFR*);
};
extern TIM_008b2010* DAT_011cb6a0;

struct Helper_00629670
{
    void FUN_00629670(int, bool);
};

class bhkCharacterController
{
  public:
    int unk_0000;
    int unk_0004;
    int unk_0008;
    int unk_000c;
    int unk_0010;
    int unk_0014;
    int unk_0018;
    int unk_001c;
    int unk_0020;
    int unk_0024;
    int unk_0028;
    int unk_002c;
    int unk_0030;
    int unk_0034;
    int unk_0038;
    int unk_003c;
    int unk_0040;
    int unk_0044;
    int unk_0048;
    int unk_004c;
    int unk_0050;
    int unk_0054;
    int unk_0058;
    int unk_005c;
    int unk_0060;
    int unk_0064;
    int unk_0068;
    int unk_006c;
    int unk_0070;
    int unk_0074;
    int unk_0078;
    int unk_007c;
    int unk_0080;
    int unk_0084;
    int unk_0088;
    int unk_008c;
    int unk_0090;
    int unk_0094;
    int unk_0098;
    int unk_009c;
    int unk_00a0;
    int unk_00a4;
    int unk_00a8;
    int unk_00ac;
    int unk_00b0;
    int unk_00b4;
    int unk_00b8;
    int unk_00bc;
    int unk_00c0;
    int unk_00c4;
    int unk_00c8;
    int unk_00cc;
    int unk_00d0;
    int unk_00d4;
    int unk_00d8;
    int unk_00dc;
    int unk_00e0;
    int unk_00e4;
    int unk_00e8;
    int unk_00ec;
    int unk_00f0;
    int unk_00f4;
    int unk_00f8;
    int unk_00fc;
    int unk_0100;
    int unk_0104;
    int unk_0108;
    int unk_010c;
    int unk_0110;
    int unk_0114;
    int unk_0118;
    int unk_011c;
    int unk_0120;
    int unk_0124;
    int unk_0128;
    int unk_012c;
    int unk_0130;
    int unk_0134;
    int unk_0138;
    int unk_013c;
    int unk_0140;
    int unk_0144;
    int unk_0148;
    int unk_014c;
    int unk_0150;
    int unk_0154;
    int unk_0158;
    int unk_015c;
    int unk_0160;
    int unk_0164;
    int unk_0168;
    int unk_016c;
    int unk_0170;
    int unk_0174;
    int unk_0178;
    int unk_017c;
    int unk_0180;
    int unk_0184;
    int unk_0188;
    int unk_018c;
    int unk_0190;
    int unk_0194;
    int unk_0198;
    int unk_019c;
    int unk_01a0;
    int unk_01a4;
    int unk_01a8;
    int unk_01ac;
    int unk_01b0;
    int unk_01b4;
    int unk_01b8;
    int unk_01bc;
    int unk_01c0;
    int unk_01c4;
    int unk_01c8;
    int unk_01cc;
    int unk_01d0;
    int unk_01d4;
    int unk_01d8;
    int unk_01dc;
    int unk_01e0;
    int unk_01e4;
    int unk_01e8;
    int unk_01ec;
    int unk_01f0;
    int unk_01f4;
    int unk_01f8;
    int unk_01fc;
    int unk_0200;
    int unk_0204;
    int unk_0208;
    int unk_020c;
    int unk_0210;
    int unk_0214;
    int unk_0218;
    int unk_021c;
    int unk_0220;
    int unk_0224;
    int unk_0228;
    int unk_022c;
    int unk_0230;
    int unk_0234;
    int unk_0238;
    int unk_023c;
    int unk_0240;
    int unk_0244;
    int unk_0248;
    int unk_024c;
    int unk_0250;
    int unk_0254;
    int unk_0258;
    int unk_025c;
    int unk_0260;
    int unk_0264;
    int unk_0268;
    int unk_026c;
    int unk_0270;
    int unk_0274;
    int unk_0278;
    int unk_027c;
    int unk_0280;
    int unk_0284;
    int unk_0288;
    int unk_028c;
    int unk_0290;
    int unk_0294;
    int unk_0298;
    int unk_029c;
    int unk_02a0;
    int unk_02a4;
    int unk_02a8;
    int unk_02ac;
    int unk_02b0;
    int unk_02b4;
    int unk_02b8;
    int unk_02bc;
    int unk_02c0;
    int unk_02c4;
    int unk_02c8;
    int unk_02cc;
    int unk_02d0;
    int unk_02d4;
    int unk_02d8;
    int unk_02dc;
    int unk_02e0;
    int unk_02e4;
    int unk_02e8;
    int unk_02ec;
    int unk_02f0;
    int unk_02f4;
    int unk_02f8;
    int unk_02fc;
    int unk_0300;
    int unk_0304;
    int unk_0308;
    int unk_030c;
    int unk_0310;
    int unk_0314;
    int unk_0318;
    int unk_031c;
    int unk_0320;
    int unk_0324;
    int unk_0328;
    int unk_032c;
    int unk_0330;
    int unk_0334;
    int unk_0338;
    int unk_033c;
    int unk_0340;
    int unk_0344;
    int unk_0348;
    int unk_034c;
    int unk_0350;
    int unk_0354;
    int unk_0358;
    int unk_035c;
    int unk_0360;
    int unk_0364;
    int unk_0368;
    int unk_036c;
    int unk_0370;
    int unk_0374;
    int unk_0378;
    int unk_037c;
    int unk_0380;
    int unk_0384;
    int unk_0388;
    int unk_038c;
    int unk_0390;
    int unk_0394;
    int unk_0398;
    int unk_039c;
    int unk_03a0;
    int unk_03a4;
    int unk_03a8;
    int unk_03ac;
    int unk_03b0;
    int unk_03b4;
    int unk_03b8;
    int unk_03bc;
    int unk_03c0;
    int unk_03c4;
    int unk_03c8;
    int unk_03cc;
    int unk_03d0;
    int unk_03d4;
    int unk_03d8;
    int unk_03dc;
    int unk_03e0;
    int unk_03e4;
    int unk_03e8;
    int unk_03ec;
    int unk_03f0;
    int unk_03f4;
    int unk_03f8;
    int unk_03fc;
    int unk_0400;
    int unk_0404;
    int unk_0408;
    int unk_040c;
    Helper_00629670 sub410;
};

}

class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeContext, bool abPush, const char* apFile, int aiLine);
    ~AutoMemContext();
    int iPrevContext;
};

namespace fnv_00919320 {
__if_not_exists(TESBoundObject::TESBoundObject)
{
    class TESBoundObject
    {
      public:
        virtual void Type();
    };
}
__if_not_exists(TESFurniture::TESFurniture)
{
    class TESFurniture : public TESBoundObject
    {
    };
}
struct Actor70;
struct Object70;
struct Package70;
struct Anim70;

struct Vec70
{
    float x, y, z;
    Vec70 FUN_00439ef0(const Vec70&);
    Vec70* FUN_00439e90(const Vec70&);
    float FUN_00457990();
};

struct Object70
{
    bool FUN_00568680();
    bool FUN_00567f80(unsigned char, int);
    void* FUN_007af430();
    float FUN_00568650();
    int FUN_005094b0();
    void FUN_00568020(unsigned char, int);
    Vec70 Rotation();
    Vec70* FUN_00430830();
    bool FUN_005686b0(Vec70*, int, int, Vec70*, int*, int);
};

struct Target70
{
    Object70* FUN_0067f390();
    int FUN_00678ca0();
};

struct Anim70
{
    int FUN_0044ddc0(int, int, int, int, int);
};

struct Package70
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

    virtual bool CanReach(Actor70*, int, float, int);

    void* FUN_00675a50(Actor70*);
    void* FUN_00675c20(Actor70*);
    Vec70 FUN_00675de0(Actor70*);
    float FUN_00678670(Actor70*, int);
    Target70* FUN_0055b980();
    int FUN_0041ca90();
    bool FUN_00670f40();
    bool FUN_00670f60();
    bool FUN_00441b00();
    bool FUN_0067efd0();
    int FUN_009611e0();
};

struct Actor70
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

    virtual void Reset(Actor70*);

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

    virtual void SetState(Actor70*, int);

    virtual void v50();

    virtual void v51();

    virtual void v52();

    virtual void v53();

    virtual void Movement(int, int);

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

    virtual Anim70* Anim();

    virtual void v83();

    virtual void v84();

    virtual void v85();

    virtual void v86();

    virtual void v87();

    virtual void v88();

    virtual void v89();

    virtual void v90();

    virtual Vec70 PositionValue();

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

    virtual bool Started();

    virtual void SetStarted(int);

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

    virtual Vec70& Position();

    virtual void v126();

    virtual void v127();

    virtual void v128();

    virtual void v129();

    virtual void v130();

    virtual int OverrideMode();

    virtual void v132();

    virtual int SitState();

    virtual void v134();

    virtual void v135();

    virtual void v136();

    virtual void v137();

    virtual void v138();

    virtual void v139();

    virtual void v140();

    virtual void v141();

    virtual void v142();

    virtual void v143();

    virtual void v144();

    virtual void v145();

    virtual void v146();

    virtual void v147();

    virtual void v148();

    virtual void v149();

    virtual void v150();

    virtual void v151();

    virtual void v152();

    virtual void v153();

    virtual void v154();

    virtual void v155();

    virtual void v156();

    virtual void v157();

    virtual void v158();

    virtual Package70* Package();

    virtual void v160();

    virtual void SetCount(int);

    virtual void Finish(Actor70*, int);

    virtual void v163();

    virtual void v164();

    virtual void Update(Actor70*);

    virtual void v166();

    virtual void v167();

    virtual void v168();

    virtual void v169();

    virtual void SetRotation(Vec70*);

    virtual void v171();

    virtual void v172();

    virtual void v173();

    virtual void v174();

    virtual void v175();

    virtual void v176();

    virtual void SetHeight(float);

    virtual void v178();

    virtual void v179();

    virtual void v180();

    virtual void v181();

    virtual void v182();

    virtual void v183();

    virtual void v184();

    virtual void v185();

    virtual void v186();

    virtual void v187();

    virtual void v188();

    virtual void v189();

    virtual void v190();

    virtual void v191();

    virtual void v192();

    virtual void v193();

    virtual void v194();

    virtual void v195();

    virtual void v196();

    virtual void v197();

    virtual void v198();

    virtual void v199();

    virtual void v200();

    virtual void v201();

    virtual void v202();

    virtual void v203();

    virtual void v204();

    virtual void v205();

    virtual void v206();

    virtual void v207();

    virtual void v208();

    virtual void v209();

    virtual void v210();

    virtual void v211();

    virtual void v212();

    virtual void v213();

    virtual void v214();

    virtual void v215();

    virtual void v216();

    virtual void v217();

    virtual void v218();

    virtual void v219();

    virtual void v220();

    virtual void v221();

    virtual void v222();

    virtual void v223();

    virtual void v224();

    virtual void v225();

    virtual void v226();

    virtual void v227();

    virtual void v228();

    virtual void v229();

    virtual void v230();

    virtual void v231();

    virtual void v232();

    virtual void v233();

    virtual void v234();

    virtual void v235();

    virtual void v236();

    virtual void v237();

    virtual void v238();

    virtual void v239();

    virtual void v240();

    virtual void v241();

    virtual void v242();

    virtual void v243();

    virtual void v244();

    virtual void v245();

    virtual void v246();

    virtual void v247();

    virtual void v248();

    virtual void v249();

    virtual void v250();

    virtual void v251();

    virtual void v252();

    virtual void v253();

    virtual void v254();

    virtual void v255();

    virtual void v256();

    virtual void v257();

    virtual void v258();

    virtual void v259();

    virtual void v260();

    virtual void v261();

    virtual void Stand();

    virtual void v263();

    virtual void v264();

    virtual void v265();

    virtual void v266();

    virtual void v267();

    virtual void v268();

    virtual void v269();

    virtual void v270();

    virtual void v271();

    virtual void v272();

    virtual void v273();

    virtual void v274();

    virtual void v275();

    virtual void v276();

    virtual void v277();

    virtual void v278();

    virtual void v279();

    virtual void v280();

    virtual void v281();

    virtual void v282();

    virtual void v283();

    virtual void v284();

    virtual void v285();

    virtual void v286();

    virtual void v287();

    virtual void v288();

    virtual void v289();

    virtual void v290();

    virtual void v291();

    virtual void v292();

    virtual void v293();

    virtual void v294();

    virtual void v295();

    virtual void v296();

    virtual void v297();

    virtual void v298();

    virtual void v299();

    virtual void v300();

    virtual void v301();

    virtual void v302();

    virtual void v303();

    virtual void FurnitureState(Actor70*, int, Object70*, unsigned char);

    virtual void v305();

    virtual void v306();

    virtual void v307();

    virtual void v308();

    virtual Object70* Furniture();

    virtual bool IsReady(Actor70*);

    virtual void v311();

    virtual void v312();

    virtual void v313();

    virtual void v314();

    virtual void v315();

    virtual void v316();

    virtual void v317();

    virtual void v318();

    virtual void v319();

    virtual void v320();

    virtual void v321();

    virtual void v322();

    virtual void v323();

    virtual void v324();

    virtual void v325();

    virtual void v326();

    virtual void v327();

    virtual void v328();

    virtual void v329();

    virtual void v330();

    virtual void v331();

    virtual void v332();

    virtual void v333();

    virtual void v334();

    virtual void v335();

    virtual void v336();

    virtual void v337();

    virtual void v338();

    virtual void v339();

    virtual void v340();

    virtual void v341();

    virtual void v342();

    virtual void v343();

    virtual void v344();

    virtual void v345();

    virtual void v346();

    virtual void v347();

    virtual void v348();

    virtual void v349();

    virtual void v350();

    virtual void v351();

    virtual void v352();

    virtual void v353();

    virtual void v354();

    virtual void v355();

    virtual void v356();

    virtual void v357();

    virtual void v358();

    virtual void v359();

    virtual void v360();

    virtual void v361();

    virtual void v362();

    virtual void v363();

    virtual void v364();

    virtual void v365();

    virtual void v366();

    virtual void v367();

    virtual void v368();

    virtual void v369();

    virtual void v370();

    virtual void v371();

    virtual void v372();

    virtual void v373();

    virtual void v374();

    virtual void v375();

    virtual void v376();

    virtual void v377();

    virtual void v378();

    virtual void v379();

    virtual void v380();

    virtual void v381();

    virtual void v382();

    virtual void v383();

    virtual void v384();

    virtual void v385();

    virtual void v386();

    virtual void v387();

    virtual void v388();

    virtual void v389();

    virtual void v390();

    virtual void v391();

    virtual void v392();

    virtual void v393();

    virtual void v394();

    virtual void v395();

    virtual void v396();

    virtual void v397();

    virtual void v398();

    virtual void v399();

    virtual void v400();

    virtual void v401();

    virtual void v402();

    virtual void v403();

    virtual void v404();

    virtual void v405();

    virtual void v406();

    virtual void v407();

    virtual void v408();

    virtual void v409();

    virtual void v410();

    virtual void v411();

    virtual void v412();

    virtual void v413();

    virtual void v414();

    virtual void v415();

    virtual void v416();

    virtual void v417();

    virtual void v418();

    virtual void v419();

    virtual void v420();

    virtual void v421();

    virtual void v422();

    virtual void v423();

    virtual void v424();

    virtual void v425();

    virtual void v426();

    virtual void v427();

    virtual void v428();

    virtual void v429();

    virtual void v430();

    virtual void v431();

    virtual void v432();

    virtual void v433();

    virtual void v434();

    virtual void v435();

    virtual void v436();

    virtual void v437();

    virtual void v438();

    virtual void v439();

    virtual void v440();

    virtual void v441();

    virtual void v442();

    virtual void v443();

    virtual void v444();

    virtual void v445();

    virtual void v446();

    virtual void v447();

    virtual void v448();

    virtual void v449();

    virtual void v450();

    virtual void v451();

    virtual void v452();

    virtual void v453();

    virtual void v454();

    virtual void v455();

    virtual void v456();

    virtual void v457();

    virtual void v458();

    virtual void v459();

    virtual void v460();

    virtual void v461();

    virtual void v462();

    virtual void v463();

    virtual void v464();

    virtual void v465();

    virtual void v466();

    virtual void v467();

    virtual void v468();

    virtual void v469();

    virtual void v470();

    virtual void v471();

    virtual void v472();

    virtual void v473();

    virtual void v474();

    virtual void v475();

    virtual void v476();

    virtual void v477();

    virtual void v478();

    virtual void v479();

    virtual void v480();

    virtual void v481();

    virtual void v482();

    virtual void v483();

    virtual void v484();

    virtual void v485();

    virtual void v486();

    virtual void v487();

    virtual void v488();

    virtual void v489();

    virtual void v490();

    virtual void v491();

    virtual void v492();

    virtual void v493();

    virtual void v494();

    virtual void v495();

    virtual void v496();

    virtual void v497();

    virtual void v498();

    virtual void v499();

    virtual void v500();

    virtual void v501();

    virtual void v502();

    virtual void v503();

    virtual void v504();

    virtual void v505();

    virtual void v506();

    virtual void v507();

    virtual void v508();

    virtual void v509();

    virtual void v510();

    virtual void v511();

    virtual void v512();

    virtual void v513();

    virtual void v514();

    virtual void v515();

    virtual void v516();

    virtual void v517();

    virtual void v518();

    virtual void v519();

    virtual void v520();

    virtual bool Move(Actor70*, Vec70, void*, void*);

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

    Object70* object;

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

    Vec70 position;

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

    Object70* furniture;

    unsigned char marker;
    char unk145;
    short unk146;

    Vec70 target;

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

    char unk188;
    bool triggered;
    short unk18a;

    bool FUN_008b3bb0();
    void FUN_008b39f0(int);
    bool FUN_00915ef0(Actor70*);
    float FUN_00572380(const Vec70&);
    void FUN_0092c680();
    void* FUN_008d6f30();
    void* FUN_00575d70();
    void FUN_0088c790(int);
    bool FUN_0094df60();
    float FUN_00567400();
    void FUN_00931d30(float);
    Actor70* FUN_008d8520();
    Actor70* FUN_008adcb0();
    void UpdateFurnitureAlignment(Actor70*);
    void FUN_00919320(Actor70*, bool, bool, int, int);
};

extern Actor70* DAT_011dea3c;
extern void* DAT_011ca248;
extern int DAT_0118a220, DAT_01183108, DAT_011846d4, DAT_011841cc;

void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);

struct Manager70
{
    void FUN_0046f280(void*, Vec70&, float, Vec70&, float, void (*)(), Actor70*);
};
extern Manager70* DAT_011c3f2c;

struct Setting70
{
    float* FUN_00403e20();
};
extern Setting70 DAT_011cd950;

int FUN_0096a820(int);

}  // namespace fnv_00919320

namespace queued_item_load913 {

using ::TESBoundObject;
using ::TESForm;

}

void __fastcall FUN_00914b40(void*);
__if_not_exists(FUN_00678d00_shell::FUN_00678d00)
{
    struct FUN_00678d00_shell
    {
        bool FUN_00678d00();
    };
}

using ::ActorPackageData;
using ::TESObjectREFR;
using ::MiddleHighProcess;

namespace DeletedPackageDetail {

class PackageView
{
  public:
    void FUN_008c5ec0(::TESObjectREFR*);
};

}

namespace queued_item_save913 {

using ::Actor;
using ::TESObjectREFR;
using ::ExtraDataList;
using ::InventoryChanges;

struct SaveFormIDHelper
{
    virtual void Slot00();
    virtual void Slot04();
    virtual Actor* GetActor();

    void FUN_00865df0(void* formID, int flag);
};

struct SaveBufferView : public SaveFormIDHelper
{
    void FUN_00865e50(void* data, int size, int count);
};

struct PaddedFloatRecord
{
    void* pObject;
    ExtraDataList* pExtra;
    int m_iCountChange;
    unsigned char byte0C;
    unsigned char byte0D;
    unsigned char byte0E;
    unsigned char byte0F;
    unsigned char byte10;
    unsigned char byte11;

    void FUN_00913d60(SaveBufferView* apSaveGameBuffer);
};

}

namespace PackageEvaluationDetail {
using ::Actor;
using ::LowProcess;
using ::MiddleHighProcess;
using ::TESBoundObject;
using ::TESNPC;
using ::TESCreature;
using ::TESPackage;

class TargetDoorController
{

  public:
    ~TargetDoorController();

    static void operator delete(void*);
};

class PackageClockView
{

  public:
    float FUN_00867da0();
};

extern "C" PackageClockView DAT_011de7b8;

}

using ::TESBoundObject;
using ::TESNPC;
using ::TESCreature;

namespace ProcessUseItem {

struct UsePoint
{
    float x, y, z;
    UsePoint();
    UsePoint FUN_00439ef0(const UsePoint& arOther) const;
    float FUN_00457990() const;
};

struct UseProcess;
struct UsePackage;

struct UseCell
{
    bool FUN_00425fd0();
};

struct UseRef
{
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual UsePoint* GetPos();
    virtual void r07e();
    virtual void r07f();
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual bool FUN_vt218();
    virtual void r087();
    virtual void r088();
    virtual void r089();
    virtual void r08a();
    virtual void r08b();
    virtual void r08c();
    virtual void r08d();
    virtual void r08e();
    virtual void r08f();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r09a();
    virtual void r09b();
    virtual void r09c();
    virtual void r09d();
    virtual void r09e();
    virtual void r09f();
    virtual void r0a0();
    virtual void r0a1();
    virtual void r0a2();
    virtual void r0a3();
    virtual void r0a4();
    virtual void r0a5();
    virtual void r0a6();
    virtual void r0a7();
    virtual void r0a8();
    virtual void r0a9();
    virtual void r0aa();
    virtual void r0ab();
    virtual void r0ac();
    virtual void r0ad();
    virtual void r0ae();
    virtual void r0af();
    virtual void r0b0();
    virtual void r0b1();
    virtual void r0b2();
    virtual void r0b3();
    virtual void r0b4();
    virtual void r0b5();
    virtual void r0b6();
    virtual void r0b7();
    virtual void r0b8();
    virtual void r0b9();
    virtual void r0ba();
    virtual void r0bb();
    virtual void r0bc();
    virtual void r0bd();
    virtual void r0be();
    virtual void r0bf();
    virtual void r0c0();
    virtual void r0c1();
    virtual void r0c2();
    virtual void r0c3();
    virtual void r0c4();
    virtual void r0c5();
    virtual void r0c6();
    virtual void r0c7();
    virtual void r0c8();
    virtual void r0c9();
    virtual void r0ca();
    virtual void r0cb();
    virtual void r0cc();
    virtual void r0cd();
    virtual void r0ce();
    virtual void r0cf();
    virtual void r0d0();
    virtual void r0d1();
    virtual void r0d2();
    virtual void r0d3();
    virtual void r0d4();
    virtual void r0d5();
    virtual void r0d6();
    virtual void r0d7();
    virtual void r0d8();
    virtual void r0d9();
    virtual void r0da();
    virtual void r0db();
    virtual void r0dc();
    virtual void r0dd();
    virtual void r0de();
    virtual void r0df();
    virtual void r0e0();
    virtual void r0e1();
    virtual void r0e2();
    virtual void r0e3();
    virtual void r0e4();
    virtual void r0e5();
    virtual void r0e6();
    virtual void r0e7();
    virtual void r0e8();
    virtual void r0e9();
    virtual void r0ea();
    virtual void r0eb();
    virtual void r0ec();
    virtual void r0ed();
    virtual void r0ee();
    virtual void r0ef();
    virtual void r0f0();
    virtual void r0f1();
    virtual void r0f2();
    virtual void FUN_vt3cc(void* apItem);
    void* FUN_0084e3a0();
    struct UseEntry* FUN_008a2d40();
    bool FUN_00575450(void* apOwner);
    struct UseEntry* FUN_00576260(void* apItem, int aiCount);
    bool FUN_008b3bb0();
    UseCell* FUN_008d6f30();
    void FUN_00892e90(void* apItem);
    TESBoundObject* FUN_007af430();
    float FUN_005723b0(UseRef* apRef, int a2, int a3);
    UseProcess* FUN_008d8520();
    void FUN_0087faa0();
    int FUN_0055d310();
};

struct UseExtraList
{
    UseRef* FUN_0041c8d0();
};

struct UseExtraNode
{
    UseExtraList** FUN_006815c0();
};

struct UseEntry
{
    UseExtraNode* FUN_00559450();
    void* FUN_0044ddc0(UseExtraList* apXData, UseRef* apLocation, int aiCount, void* apOwner);
    void* FUN_0044ddc0(UseExtraList* apXData, int aiCount, UsePoint* apPos, int aiFlags);
    ~UseEntry();
};

struct UsePackageTarget
{
    UseRef* FUN_0067f390();
};

struct UsePackageLocation
{
    int FUN_00680020();
    int FUN_00680080();
    int FUN_0044ddc0();
};

struct UsePackage
{
    virtual void k000();
    virtual void k001();
    virtual void k002();
    virtual void k003();
    virtual void k004();
    virtual void k005();
    virtual void k006();
    virtual void k007();
    virtual void k008();
    virtual void k009();
    virtual void k00a();
    virtual void k00b();
    virtual void k00c();
    virtual void k00d();
    virtual void k00e();
    virtual void k00f();
    virtual void k010();
    virtual void k011();
    virtual void k012();
    virtual void k013();
    virtual void k014();
    virtual void k015();
    virtual void k016();
    virtual void k017();
    virtual void k018();
    virtual void k019();
    virtual void k01a();
    virtual void k01b();
    virtual void k01c();
    virtual void k01d();
    virtual void k01e();
    virtual void k01f();
    virtual void k020();
    virtual void k021();
    virtual void k022();
    virtual void k023();
    virtual void k024();
    virtual void k025();
    virtual void k026();
    virtual void k027();
    virtual void k028();
    virtual void k029();
    virtual void k02a();
    virtual void k02b();
    virtual void k02c();
    virtual void k02d();
    virtual void k02e();
    virtual void k02f();
    virtual void k030();
    virtual void k031();
    virtual void k032();
    virtual void k033();
    virtual void k034();
    virtual void k035();
    virtual void k036();
    virtual void k037();
    virtual void k038();
    virtual void k039();
    virtual void k03a();
    virtual void k03b();
    virtual void k03c();
    virtual void k03d();
    virtual void k03e();
    virtual void k03f();
    virtual void k040();
    virtual void k041();
    virtual void k042();
    virtual void k043();
    virtual void k044();
    virtual void k045();
    virtual void k046();
    virtual void k047();
    virtual void k048();
    virtual void k049();
    virtual void k04a();
    virtual void k04b();
    virtual void k04c();
    virtual void k04d();
    virtual void k04e();
    virtual bool IsPackageRunningForActor(UseRef* apActor, int a2, float afTime, bool abFlag);
    UsePackageTarget* FUN_0055b980();
    UsePackageLocation* FUN_00671d10();
    int FUN_00672930();
    int FUN_0041ca90();
    bool FUN_00674d40();
    float GetPackageResult(UseRef* apActor, bool abFlag);
    bool FUN_00441b00();
};

struct UseAcquire
{
    UseRef* pObject;
    void* pItem;
    ~UseAcquire();
};

struct UseAcquireList
{
    void* pHead;
    void* pNext;
    bool FUN_008256d0();
    UseAcquire** FUN_006815c0();
    void FUN_00905330(UseAcquire** appItem);
};

struct UseSetting
{
    float* FUN_00403e20();
};
extern UseSetting DAT_011cdbac;
extern UseSetting DAT_011cd82c;
extern UseRef* DAT_011dea3c;
extern void* DAT_011ca244;
extern void* DAT_011ca248;

struct UseProcess
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void FUN_vt24(UseRef* apActor, int aiValue);
    virtual void p00a();
    virtual void p00b();
    virtual void p00c();
    virtual void p00d();
    virtual void p00e();
    virtual void p00f();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p01a();
    virtual void p01b();
    virtual void p01c();
    virtual void p01d();
    virtual void p01e();
    virtual void p01f();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual bool FindPackageTarget(UseRef* apActor);
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p02a();
    virtual void p02b();
    virtual void p02c();
    virtual void p02d();
    virtual void p02e();
    virtual void p02f();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p03a();
    virtual void p03b();
    virtual void p03c();
    virtual void p03d();
    virtual void p03e();
    virtual void p03f();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void FUN_vt118(int aiValue);
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p04a();
    virtual void FUN_vt12c(UseRef* apRef);
    virtual void p04c();
    virtual void p04d();
    virtual void p04e();
    virtual void p04f();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p05a();
    virtual void p05b();
    virtual void p05c();
    virtual void p05d();
    virtual void p05e();
    virtual void p05f();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p06a();
    virtual void p06b();
    virtual void p06c();
    virtual void p06d();
    virtual void p06e();
    virtual void p06f();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p07a();
    virtual void p07b();
    virtual void p07c();
    virtual void p07d();
    virtual void p07e();
    virtual void p07f();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p08a();
    virtual UsePackage* GetCurrentPackage();
    virtual void p08c();
    virtual void FUN_vt234();
    virtual void p08e();
    virtual void p08f();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p09a();
    virtual void p09b();
    virtual void p09c();
    virtual void p09d();
    virtual void p09e();
    virtual UsePackage* FUN_vt27c();
    virtual void p0a0();
    virtual void FUN_vt284(int aiValue);
    virtual void SetProcessTarget(UseRef* apActor, int aiIndex);
    virtual void p0a3();
    virtual void p0a4();
    virtual void FUN_vt294(UseRef* apActor);
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
    UseRef* pTarget;
    UseRef* m_pReference40;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    UseAcquireList kAcquireList;
    UseAcquire* m_pDetectionData60;

    bool FUN_0091c810(UseRef* apActor);
};

}
