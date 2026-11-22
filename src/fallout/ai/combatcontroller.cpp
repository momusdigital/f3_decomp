// fallout/ai/combatcontroller.cpp: CombatController, CombatPlanner, Owner, OuterObj and more (5 functions)
#include "f3_common.h"
#include "multi_bound_marker_data.h"

struct Actor;
struct BGSExplosion;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CoordinateTriple;
struct CombatController;
struct CombatCoverPointData;
struct CombatSaveGameData;
struct CombatReferenceEntry;
struct CombatAvoidanceSphere;
struct CombatSaveData;
struct TimeoutTimer;
struct CombatPathingType;
struct IDebugText;
struct PathingAvoidNodeArray;
struct PathingCoverLocation;
struct PathingLocation;
struct PathingRequestCoveredMove;
struct Projectile;
struct TESBoundObject;
struct TESForm;
struct TESObjectREFR;
struct TESObjectWEAP;
struct blob4
{
    char b[4];
};
struct CombatState
{
    void SetProcessLevelForIndex(int, int);
    void DoInitialUpdate();
    void Update();
    void UpdateImmediateData();
    void UpdateCombatStateData();
    void UpdateCombatBehaviorData();
    void UpdateCombatPermissions();
    void RefreshInventoryData();
    void DeleteInventoryData();
    bool CheckShouldUpdateDetection(Actor*, Actor*);
    void ChangeCombatTargetReference(TESObjectREFR*, bool);
    void CheckReferences();
    void ProjectileLaunched(Projectile*);
    void ReloadingWeapon(TESObjectWEAP*, bool);
    void PerformedMeleeAttack(Actor*);
    void DamagedByAttacker(Actor*, float);
    void GetInventoryItemCount(TESObjectREFR*);
    void OnInventoryItemChanged(TESObjectREFR*, TESBoundObject*, int, bool);
    void UsedCombatItem(TESBoundObject*);
    void Disarmed();
    void TargetChanged();
    void PlanUpdated();
    void ReachedDestination(void*, int);
    void DrawDebugText(IDebugText*, unsigned int);
    void SetInventoryDirty(bool);
    void SetBlocking(bool);
    bool GetBlockingState();
    void SetTargetSegmentInView(int);
    int GetTargetSegmentInView();
    void SetExplosiveProjectileBlocked(BGSExplosion*);
    BGSExplosion* GetExplosiveProjectileBlocked();
    TimeoutTimer* GetExplosiveProjectileBlockedTimer();
    bool GetHasCombatWeaponType(int);
    unsigned int GetHasCombatWeaponTypeBitfield();
    TESObjectWEAP* GetCombatWeapon(int);
    float GetCombatWeaponDPS(int);
    float GetMaxCombatWeaponDPS();
    float GetMaxModifiedCombatWeaponDPS();
    bool IsMeleePrimary();
    bool IsMeleeOnly();
    TESObjectWEAP* GetBestCombatWeapon();
    bool GetTargetBlocked();
    void SetTargetBlocked(bool);
    bool GetTargetFlushed();
    void SetTargetFlushed(bool);
    void SetLocationUnreachable(int);
    void ClearLocationUnreachable(int);
    bool GetLocationUnreachable(int);
    bool GetTargetUnreachable();
    void ClearTargetUnreachable();
    TimeoutTimer* GetTargetUnreachableTimer();
    bool GetTargetSpaceDifferent();
    int GetTargetDetectionLevel();
    struct blob4 GetLastTargetDetectedTimeStamp();
    bool GetHasBufferedDetection();
    bool GetTargetLost();
    struct blob4 GetLastTarget360LineOfSightTimeStamp();
    bool GetHasTarget360LineOfSight();
    bool GetHasTargetLineOfSight();
    bool GetHasBuffered360LineOfSight();
    bool GetInitializing();
    bool GetLastSeenTargetLocation(NiPoint3*);
    bool GetLastKnownTargetPosition(NiPoint3*);
    struct blob4 GetLastAttackTimeStamp();
    struct blob4 GetLastDamagedByAttackerTimeStamp();
    struct blob4 GetFiringStartedTimeStamp();
    void ClearFiringStartedTimeStamp();
    unsigned int GetCombatPermissions();
    bool GetPermission(unsigned int);
    TimeoutTimer* GetAttackDialogueTimer();
    TimeoutTimer* GetFireExplosiveDialogueTimer();
    TimeoutTimer* GetFleeDialogueTimer();
    CombatReferenceEntry* GetCombatItem(int);
    void SetCombatItem(int, TESObjectREFR*, TESBoundObject*);
    void ClearCombatItem(int);
    unsigned int GetHasCombatItemTypeBitfield();
    TESBoundObject* GetUsableCombatItem(int);
    TimeoutTimer* GetUsableCombatItemTimer(int);
    void SetCoverLocation(CombatCoverPointData*);
    void SetSecondaryCoverLocation(CombatCoverPointData*);
    CombatCoverPointData* GetCoverLocation();
    CombatCoverPointData* GetSecondaryCoverLocation();
    CombatSaveGameData* GetCoverSearchInfo();
    CombatSaveGameData* GetSecondaryCoverSearchInfo();
    void SetSecondaryCoverSearchInfo(CombatSaveGameData*);
    void SetSecondaryCoverLocationEnabled(bool);
    void ClearSecondaryCoverLocation(bool);
    void ClearCoverSearchInfo();
    void ClearSecondaryCoverSearchInfo();
    void UpdateCoverLocation();
    void UpdateCoverLocation(CombatCoverPointData*);
    bool TryReserveCoverLocation(CombatCoverPointData*);
    void UpdateSecondaryCoverLocation();
    void UpdateSecondaryCoverLocation(CombatCoverPointData*);
    void ReserveSecondaryCoverLocation();
    void UnreserveSecondaryCoverLocation();
    bool TryReserveSecondaryCoverLocation();
    bool CanReserveSecondaryCoverLocation(CombatCoverPointData*);
    void SetCombatLocation(CombatAvoidanceSphere*);
    CombatAvoidanceSphere* GetCombatLocation();
    void ClearCombatLocation();
    bool FindCombatLocation(int);
    bool FindBestCoverLocation(TESObjectWEAP*, CombatSaveGameData*, CombatCoverPointData*, CombatAvoidanceSphere*, int);
    bool EvaluateCoverLocation(PathingCoverLocation*, CombatAvoidanceSphere*, CombatPathingType*, NiPoint3*,
                               unsigned int, unsigned int, int, Actor*, Actor*, float, float, int*, float*, bool);
    static bool CheckTargetsCoverLOS(PathingLocation*, void*);
    bool CheckTargetsCoverLOS(PathingLocation*, Actor*);
    void ProcessCoverLOSResult(void*);
    static bool CheckCoverLOS(PathingLocation*, void*, bool);
    bool CheckCoverLOSResult(void*, void*, Actor*, bool);
    bool CheckTargetCoverLOS(void*, void*, void*, Actor*);
    static bool CheckCoveredMove(PathingRequestCoveredMove*, float, bool);
    bool CheckCoveredMove(CombatSaveGameData*, CombatCoverPointData*, CombatAvoidanceSphere*, int, void*, float,
                          PathingAvoidNodeArray*);
    void OnCoveredMoveComplete(PathingRequestCoveredMove*);
    bool EvaluateCoverPath(PathingCoverLocation*, void*, unsigned int, float, PathingAvoidNodeArray*);
    bool IsCombatLocationValid(CombatAvoidanceSphere*, unsigned int, unsigned int, float, float);
    bool FindOptimalLocation(float, float, float, float, CombatAvoidanceSphere*, bool);
    bool FindOptimalLocation(TESObjectWEAP*, CombatAvoidanceSphere*, bool);
    bool EvaluateCoverPoint(CombatCoverPointData*, CombatAvoidanceSphere*, int);
    bool FindBestCombatLocation(CombatAvoidanceSphere*, int);
    bool FindBetterWeapon();
    void ClearLastDodgeDirection();
    float GetThreatScore();
    float GetThreatRatio();
    bool FindGrenadeThrowSolution(CombatAvoidanceSphere*, bool*, TESObjectWEAP*);
    bool GetGrenadeThrowHighArc();
    void SetLocationTargetRef(TESObjectREFR*, int, float, float);
    void SetLocationTargetLocation(void*, int, float, float);
    CombatSaveData* GetLocationTarget();
    void ClearLocationTarget();
    bool CheckUseLocationTargetMaxDistance();
    float GetLocationTargetDistance();
    float GetLocationTargetNearTargetDistance();
    float GetLocationTargetCheckMovementDistance();
    float GetLocationTargetMinDistance();
    void UpdateCombatArea(bool);
    bool CheckMovement(void*, bool, bool);
    bool CheckMovement(void*, TESForm*, bool, bool);
    void SetThreatsConsideredTimeStamp(float);
    struct blob4 GetThreatsConsideredTimeStamp();
    void AddUnreachableCoverLocation(unsigned int);
    bool IsCoverLocationUnreachable(unsigned int);
    void MarkLocationUnreachable(void*);
    void RemoveUnreachableLocation(void*);
    bool IsLocationUnreachable(void*, float);
    unsigned int GetUnreachableLocationCount();
    CoordinateTriple* GetUnreachableLocation(unsigned int);
    bool IsDynamicCoverLost();
    unsigned char GetCurrentConfidence();
    float GetConfidenceModifier();
    void SetDynamicCoverLost(bool);
    float GetCombatStrength();
    float GetDamagePerSecond();
    void UpdateDamagePerSecond();
    void UpdateThreatRatio();
    void SetFleeState(unsigned char);
    unsigned char GetFleeState();
    bool CheckShouldFlee();
    unsigned int GetLastFleeDoor();
    struct blob4 GetLastFleeDoorTimeStamp();
    void SetLastFleeDoorTimeStamp(float);
    bool QueuePathCheck(int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    void* __vecDelDtor(unsigned int);
    bool m_bCombatItemSearchActive;
    char _pad_1[3];
    int m_iCombatItemSearchState;
    float m_fCombatItemSearchTimer;
    char m_kCombatTargetData[24];
    char m_kSixteenByteStateData[16];
    TESObjectWEAP* m_pCombatWeapon;
    unsigned int m_uiWeaponFormID;
    char m_kWeaponCombatData[28];
    float m_fCombatValue1;
    float m_fCombatValue2;
    float m_fCombatValue3;
    float m_fCombatValue4;
    float m_fCombatValue5;
    int m_iCombatMode;
    bool m_bCombatItemSearch;
    bool m_bWeaponSwitchPrevented;
    bool m_bCombatStateFlag1;
    char m_cCombatStateMode;
    bool m_bCombatStateFlag2;
    bool m_bCombatStateFlag3;
    bool m_bInitializing;
    bool m_bCombatStateFlag4;
    BGSExplosion* m_pCombatExplosion;
    int m_iExplosionState;
    float m_fCombatActionTimer;
    NiPoint3 m_kLocationTargetPosition;
    unsigned int m_uiTargetFormID;
    char m_kCombatDataEntry1[4];
    char m_kCombatDataEntry2[4];
    char m_kCombatDataEntry3[4];
    char m_kCombatDataEntry4[4];
    char m_kCombatDataEntry5[4];
    char m_kFirstStateEightByteData[8];
    char m_kSecondStateEightByteData[8];
    char m_kThirdStateEightByteData[8];
    char m_kCombatSaveDataHeader[4];
    CombatSaveData* pAssociatedObject;
    unsigned char m_ucSaveDataFlags;
    unsigned char m_ucSaveDataState;
    char _pad_ca[2];
    float m_fCombatValue6;
    float m_fClusterOffsetY;
    float m_fClusterOffsetX;
    unsigned char m_ucCoverPointState;
    char _pad_d9[3];
    unsigned int m_uiCoverPointFlags;
    char m_kCoverPointData[4];
    CombatCoverPointData* m_pCurrentCoverPoint;
    CombatCoverPointData* m_pAlternateCoverPoint;
    char m_kCoverSearchInfo[60];
    char m_kSecondaryCoverSearchInfo[60];
    char m_kFirstSixteenByteData[16];
    char m_kSecondSixteenByteData[16];
    char m_kAvoidanceData[4];
    char m_cAvoidanceState;
    char _pad_189[3];
    CombatAvoidanceSphere* m_pAvoidanceSphere;
    char m_kAvoidanceSphereData[20];
    char m_kControllerStateData[8];
    char m_kThirdSixteenByteData[16];
    unsigned int m_uiActorFormID;
    Actor* coordinate;
    CombatController* m_pCombatController;
    bool m_bCombatControllerActive;
    char _pad_1c9[3];
    char m_kFirstTrailingEightByteData[8];
    char m_kSecondTrailingEightByteData[8];
    char m_kThirdTrailingEightByteData[8];
    char m_kFourthTrailingEightByteData[8];
    char m_kFifthTrailingEightByteData[8];
    char m_kSixthTrailingEightByteData[8];
    char m_kSeventhTrailingEightByteData[8];
    char m_kEighthTrailingEightByteData[8];
    char m_kNinthTrailingEightByteData[8];
    char m_kTenthTrailingEightByteData[8];
    char m_kEleventhTrailingEightByteData[8];
    char m_kProcedureStateData[4];
    int m_iCombatProcedureType;
};
typedef char _sizecheck_CombatState[sizeof(CombatState) == 556 ? 1 : -1];

struct FUN_00980250_shell
{
    void __thiscall FUN_00980110(int);
    void __thiscall FUN_009801b0(int);
    void FUN_00980250();
};

struct FUN_00980700_shell
{
    int __thiscall FUN_00980700(int index);
};

extern "C" void __cdecl Deallocate(void*);

struct CombatController
{
    unsigned char m_aucStateByIndex[2];
    void FUN_00981720(unsigned char acIndex);
};

namespace fnv_0097d740 {
void Deallocate(void*);
struct CombatController
{
    void FUN_0097d770();
    void* FUN_0097d740(unsigned int);
};
}  // namespace fnv_0097d740

void __cdecl Deallocate(void*);

namespace fnv_0097d990 {
struct MobileObject
{
    unsigned int GetCurrentProcessLevel();
};
struct CombatController
{
    void FUN_0097f390();
    void FUN_0097d9d0();
    void FUN_0097d990();
};
}  // namespace fnv_0097d990

struct CombatPlanner
{
    void* FUN_0097e460(unsigned int flags);
    void FUN_0097e3e0();
};

void __cdecl Deallocate(void*);

void __cdecl Deallocate(void*);
struct Owner
{
    void FUN_00993f70();
    void* ReleaseIfFlagged(unsigned int);
};

struct TESEffectShader;

struct EffectSetting
{
    void SetEnchantEffectShader(TESEffectShader*);
};

namespace fnv_009807d0 {
struct Actor
{
    void StopMoving(void);
};

struct CombatController
{
    void StopActorMoving();
};

}  // namespace fnv_009807d0

struct FUN_00981300_shell
{
    bool FUN_00981300() const;
};

namespace fnv_00981900 {
struct Modifier
{
    char GetKey(void);
};

struct CombatController
{
    Modifier* m_pModifier;
    char GetModifierKey(void);
};

}  // namespace fnv_00981900

namespace fnv_00982310 {
struct BGSLoadFormBuffer;
struct CombatController
{
    void FUN_0097f390();
    void UpdatePointer();
    void FUN_0097d9d0();
    void UpdateActorValues();
    void FUN_00982310(BGSLoadFormBuffer* apLoadGameBuffer);
};
}  // namespace fnv_00982310

struct Calendar
{
    unsigned int GetDaysPassed();
};
struct TESWorldSpace;
extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;
bool __fastcall FUN_00995870(unsigned int);
void __fastcall FUN_00995890(unsigned int);
struct FUN_00995830_Class
{
    void FUN_00995830();
};
// @fnv 0x00995830
void FUN_00995830_Class::FUN_00995830()
{
    while (FUN_00995870(reinterpret_cast<Calendar*>(BGSSaveLoadGlobalDataWorldspacePtr)->GetDaysPassed()))
    {
        FUN_00995890(reinterpret_cast<Calendar*>(BGSSaveLoadGlobalDataWorldspacePtr)->GetDaysPassed());
    }
}

struct Actor;
struct ActorValueOwner;
struct AlchemyItem;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct InventoryIterator;
struct InventoryStackRecord;
struct IndexedPointerCollection;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESLevItem;
struct TESObject;
struct TESObjectREFR;
struct TESObjectWEAP;
struct InventoryChanges
{
    void ForceWeightRecalculation();
    static void KillTempRef();
    void AddItemToEntry(TESBoundObject*, int, Actor*, ExtraDataList*, InventoryStackRecord*);
    bool IsEmpty();
    void AddItem(TESBoundObject*, ExtraDataList*, int);
    void AddItem(TESObjectREFR*, int, bool, bool);
    void AddChangeEntry(InventoryStackRecord*, bool);
    void RemoveChangeItem(TESBoundObject*);
    TESObjectREFR* RemoveItem(TESObjectREFR*, TESBoundObject*, bool, int, ExtraDataList*, bool, TESObjectREFR*, void*,
                              void*, bool, bool, InventoryStackRecord*);
    void UpdateItemCount(int, bool, int);
    TESObjectREFR* DropItem(TESObjectREFR*, TESBoundObject*, int, TESObjectREFR*, void*, void*);
    void PutItemIntoContainer(TESBoundObject*, int, TESObjectREFR*, ExtraDataList*);
    void DamageItem(TESBoundObject*, float);
    void RepairBatch(TESBoundObject*, float);
    void AddOwnership(TESBoundObject*, TESForm*);
    void RemoveOwnership(TESBoundObject*);
    TESContainer* GetOriginalContainer();
    void RemoveBoundItem(TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool);
    bool RemoveInventoryItem(bool*, TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool, InventoryStackRecord*, bool*);
    void ResetInventoryChanges();
    bool RunScripts(TESObjectREFR*);
    void ResetInventoryState();
    void CleanUpBoundItems(Actor*);
    TESBoundObject* GetLeveledCalculatedBaseObject(TESLevItem*);
    void ModifyCharge(float);
    InventoryStackRecord* GetOrCreateInventoryEntry(TESBoundObject*, bool, unsigned int);
    static InventoryChanges* CreateForReference(TESObjectREFR*);
    ExtraDataList* GetExtraDataListForObject(TESBoundObject*, bool);
    bool WearingWeapon(TESBoundObject**);
    bool WearingAmmo(TESBoundObject**);
    bool WearingTorch(TESBoundObject**);
    InventoryStackRecord* WearingRing(bool);
    bool WearingVoiceModulateItem();
    bool HasItemOfType(unsigned int);
    bool FindItemInInventory(TESBoundObject*, int, int, int*, unsigned int, TESObjectREFR*);
    bool HasQuestObject();
    bool HasScript();
    TESBoundObject* GetObjectAtIndex(int, int*);
    TESBoundObject* GetBoundObjectByIndex(int, int*);
    InventoryStackRecord* GetPotion(void*);
    InventoryStackRecord* GetBestAmmoForActor(TESActorBase*, bool);
    TESAmmo* GetBestAmmoForWeapon(TESObjectWEAP*, bool*);
    InventoryStackRecord* GetBestWeapon(TESActorBase*, float*, int, bool);
    InventoryStackRecord* FindBestArmor(TESActorBase*, int, bool);
    void* GetListBestArmor(TESActorBase*);
    InventoryStackRecord* GetBestClothing(TESActorBase*, int, bool);
    InventoryStackRecord* GetBestLight(TESActorBase*, bool);
    InventoryStackRecord* GetInventoryEntryData(int, bool);
    InventoryStackRecord* GetEquippedItemForSlot(int);
    InventoryStackRecord** GetEntryPointerByIndices(int, int);
    void SetHotKeyItem(InventoryStackRecord*, ExtraDataList*, int);
    void SetInventoryEntryCount(InventoryStackRecord*, int);
    void RemoveAllObjectsWorn(bool, TESObjectREFR*);
    bool RechargeAll();
    void RemoveAllHealth();
    int GetCount(bool);
    InventoryStackRecord* GetInventoryEntryAtIndex(int);
    IndexedPointerCollection* GetFirstItem();
    InventoryStackRecord* GetEntryForListNode(IndexedPointerCollection*);
    void RemoveItemChangeEntry(TESBoundObject*, void*);
    void RefreshItemChange(TESBoundObject*, void*);
    void UpdateItemChangeEntry(TESBoundObject*, void*);
    int GetObjectCount(int);
    int GetObjectCount(TESBoundObject*);
    InventoryStackRecord* GetFirstInventoryEntry();
    int GetInventoryEntryCount();
    void TransferItemToReference(TESObjectREFR*, int, TESObjectREFR*);
    float RemoveAllTypedItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    float RemoveAllItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    void DuplicateAllItems(TESObjectREFR*, TESObjectREFR*);
    void MoveItemsOfType(TESObjectREFR*, TESObjectREFR*, TESForm*);
    void RemoveNonStolenItems(TESObjectREFR*, TESObjectREFR*);
    float GetInventoryWeight(bool);
    unsigned int GetTotalItemCount(bool, bool);
    void AddAmountToItemChange(TESBoundObject*, int);
    float GetArmorValueForActor(Actor*);
    void UpdateArmorWeight();
    void UpdateWeight();
    void RemoveDefaultLeveledItems();
    bool IsLevelItemInited(int);
    InventoryStackRecord* FindEntryForObject(TESBoundObject*, unsigned int);
    void SetItemsBacktoDefaultState();
    void CopyInventoryChanges(InventoryChanges*, TESObjectREFR*, bool);
    void ResetEntryList();
    void ResetCachedWeights();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    int GetExtraDataListIndexForItem(TESBoundObject*, ExtraDataList*);
    ExtraDataList* GetExtraDataListFromIndexForItem(TESBoundObject*, int);
    unsigned int FindItemEntryData(int*, void*, unsigned int);
    bool GetNextItem(InventoryIterator*, InventoryStackRecord**, unsigned int);
    TESObjectREFR* GetRef();
    static TESObjectREFR* GetTempRef();
    void RemoveExtraFromObject(TESObject*, ExtraDataList*);
    void DeleteExtraData(TESBoundObject*, ExtraDataList*);
    void* __vecDelDtor(unsigned int);
    void* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    char _pad_11[3];
};
typedef char _sizecheck_InventoryChanges[sizeof(InventoryChanges) == 20 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

struct TESContainer
{
    int GetObjectCount(TESObject*);
};
struct InventoryStackRecord
{
    int GetIndex();
};

struct CombatCoverPointData;
struct FUN_009d7c20_shell
{
    void FUN_009a0510(CombatCoverPointData*);
    void FUN_00980770();
};

struct CombatCoverPointData;

struct FUN_00981970_shell
{
    void* FUN_00980400(int);
    char FUN_00981970();
};

// @f3 0x00be75a0 (community match, verified in this file)
struct FUN_00c21d10_shell {
    void* FUN_00c21d10(int);
};

// pdb: TES::ClearBedChairList | TES.obj | fnv360_0822_debug, objrun_open, low
char FUN_00981970_shell::FUN_00981970() {
    char active = ((FUN_00c21d10_shell*)this)->FUN_00c21d10(0) != 0;
    *(char*)this = active;
    return active;
}


struct BSAudio
{
    void* GetAudioBackendData();
};
struct TESObjectWEAP;
struct Actor
{
    TESObjectWEAP* GetActiveWeapon();
};

struct ProxyA_97f3f0
{
    void* FUN_008a7f80();
};
struct ProxyB_97f3f0
{
    void SetAttacker(int);
};
struct Cls_0097f3f0
{
    char _pad0[0x9c];
    ProxyB_97f3f0* _p9c;
    char _pad1[0x1c];
    ProxyA_97f3f0* _pBC;
    char _pad2[0x34];
    void* _pF4;
    void FUN_0097f200();
    void UpdatePointer();
};

typedef int COMBAT_WEAPON_TYPE;

namespace fnv_0097f9c0 {
struct Actor
{
};
struct ActorCombatGroup
{
    void RemoveByTarget(Actor*);
};
struct PlayerCharacter : Actor
{
    void FUN_00967220(Actor*, int);
};
struct CombatController
{
    char _pad0[0x80];
    ActorCombatGroup* m_pCombatData;
    char _pad1[0x38];
    Actor* m_pkAttacker;
    void FUN_0097f9c0(Actor*);
};
}  // namespace fnv_0097f9c0

struct Dummy00981520
{
    unsigned char _pad0[0xC7];
    unsigned char fieldC7;
    int fieldC8;
    unsigned char _pad1[8];
    unsigned char fieldD4;
    void SetFieldC7(unsigned char);
    void FUN_009815f0(int);
};

namespace fnv_00981660 {
struct CombatController
{
    char _pad[0xc8];
    unsigned int m_uiCombatState;
    void FUN_009815f0(unsigned int);
    void ResetCombatState();
};

}  // namespace fnv_00981660

namespace fnv_00981690 {
struct CombatProcedure;
struct CombatController
{
    char pad1[0x84];
    CombatProcedure* m_pkCurrentProcedure;
    CombatProcedure* m_pkQueuedProcedure;
    unsigned int FUN_00981690(CombatProcedure* apCombatProcedure);
};

}  // namespace fnv_00981690

namespace fnv_009819f0 {
struct BGSSaveFormBuffer
{
    void SerializeFormData(void*, int);
    void SaveData(void*, int, int);
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct BSThread
{
    unsigned int GetThreadID();
};
struct CombatProcedure;
struct GridArray
{
    int GetCenterX() const;
};
struct CombatState
{
    void SaveToStream(BGSSaveFormBuffer*);
};
struct CombatPlan
{
    void SaveToBuffer(BGSSaveFormBuffer*);
};
struct CombatController
{
    char pad0[0x80];
    GridArray* m_pCombatData;   // 80
    CombatProcedure* pProc84;   // 84
    CombatProcedure* pProc88;   // 88
    char arr8c[0x10];           // 8c
    CombatState* m_pModifier;   // 9c
    CombatPlan* m_pCombatPlan;  // a0
    int pada4;
    BSThread* m_pCombatThread;  // a8
    int padac;
    int ib0;             // b0
    char sb4[8];         // b4
    void* m_pkAttacker;  // bc
    void* pTarget;       // c0
    char padc4;
    char cc5, cc6, cc7;  // c5..c7
    int ic8;             // c8
    char padcc[0xc];
    int id8, idc;  // d8 dc
    int pade0;
    char ce4;  // e4
    char pade5[0x40];
    char c125, c126;  // 125 126
    char pad127;
    char m_acStateData[2][12];           // 128
    unsigned char m_aucStateByIndex[2];  // 140
    char c142;
    char pad143;
    int i144, i148;
    void FUN_00982350(CombatProcedure** p, BGSSaveFormBuffer* buf);
    void FUN_009819f0(BGSSaveFormBuffer* apSaveGameBuffer);
};
}  // namespace fnv_009819f0

namespace fnv_0097ef50 {

struct Actor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void Virtual_348(float, int);

    void FUN_008b3230(float);
};

}  // namespace fnv_0097ef50

namespace fnv_0097f4d0 {
struct Actor
{
    bool CanStartCombat(bool);
};

struct Cls_0097f3f0
{
    void FUN_0097f200();
};

struct FUN_00980250_shell
{
    void FUN_00980250();
};

struct Class80
{
    void* SelectActor(void*);
};

class CombatController
{
  public:
    char pad0[0x80];
    Class80* field_80;
    char pad1[0xbc - 0x84];
    void* pActor;
    void* field_c0;

    void FUN_0097f9c0(void*);
    void FUN_00980830(void*);
    void DestroyOwnedObject();
    bool FUN_0097f4d0(void* arg);
};

}  // namespace fnv_0097f4d0

namespace fnv_0097f820 {
struct TESObjectREFR;
struct TESBoundObject;

struct CombatProcedure
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
    virtual void OnInventoryItemChanged(TESObjectREFR* apRef, TESBoundObject* apObject, int aiCount,
                                        bool abActivatedScriptOnly);
};

struct CombatState
{
    void FUN_0099a7d0(TESObjectREFR* apRef, TESBoundObject* apObject, int aiCount, bool abActivatedScriptOnly);
};

}  // namespace fnv_0097f820

namespace fnv_0097f930 {
struct Actor;
struct ActorCombatGroup
{
    void FUN_00986410(Actor*);
};

struct PlayerCharacter
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual ActorCombatGroup* GetCombatGroup();

    void FUN_00967220(Actor*, int);
};

extern void* BGSSaveLoadGlobalDataWorldspacePtr;

}  // namespace fnv_0097f930

namespace fnv_0097fb80 {
struct Owner
{
    ~Owner();
};

struct CombatPlanner
{
    int pad[2166];
    CombatPlanner();
    ~CombatPlanner();
    Owner* FUN_00994bd0(void*, int);
};

}  // namespace fnv_0097fb80

namespace fnv_0097feb0 {
class InventoryStackRecord;
class Animation;
class BSAnimGroupSequence;
class TESAnimGroup;

struct TESAnimGroup
{
    static bool __cdecl IsValidAnimationGroup(unsigned short);
};

struct BSAnimGroupSequence
{
    TESAnimGroup* GetAnimGroup() const;
};

class Actor
{
  public:
    unsigned short GetAnimGroup(ANIM_GROUP_ENUM, InventoryStackRecord*, bool, Animation*);

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
    virtual Animation* GetAnimation();
};

}  // namespace fnv_0097feb0

namespace fnv_00980110 {
class CombatController;

class CombatProcedure
{
  public:
    virtual ~CombatProcedure();
    virtual void Unk04();
    virtual void Unk08(CombatController*);
    virtual void Unk0c();
};

class CombatController
{
  public:
    char pad[0x84];
    CombatProcedure* m_pkCurrentProcedure;

    void FUN_00980110(CombatProcedure* apActionProcedure);
};

}  // namespace fnv_00980110

namespace fnv_009801b0 {
class CombatController;

class CombatProcedure
{
  public:
    virtual ~CombatProcedure();
    virtual void Unk04();
    virtual void Unk08(CombatController*);
    virtual void Unk0c();
};

class CombatController
{
  public:
    char pad[0x88];
    CombatProcedure* m_pkQueuedProcedure;

    void FUN_009801b0(CombatProcedure* apMovementProcedure);
};

}  // namespace fnv_009801b0

namespace fnv_00980270 {
struct ArrSI
{
    unsigned int GetFlags();
};

class CombatProcedure
{
  public:
    virtual ~CombatProcedure();
    virtual void d01();
    virtual void Unk08(void*);
    virtual void Unk0c();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual int GetType();
};

class CombatController
{
  public:
    char pad0[0x8c];

    void FUN_00980270(CombatProcedure* apBackgroundProcedure);
};

}  // namespace fnv_00980270

struct ArrSI
{
    unsigned int GetFlags();
};

struct Item
{
    virtual ~Item();
    virtual void v1();
    virtual void v2();
    virtual void Func_0c();
};

namespace fnv_00980a30 {
struct C99
{
    void FUN_0099a420(int, int);
};

class CombatProcedure
{
  public:
    virtual ~CombatProcedure();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0c();
    virtual void Unk10(int);
};

class CombatController
{
  public:
    char pad0[0x84];
    CombatProcedure* m_pkCurrentProcedure;
    CombatProcedure* m_pkQueuedProcedure;
    char pad1[0x9c - 0x8c];
    C99* field_9c;
    char pad2[0xc0 - 0xa0];
    int field_c0;

    void FUN_0097f4d0(int);
    void FUN_00980a30(int arg);
};

}  // namespace fnv_00980a30

namespace fnv_00981380 {
class TESPackage;
struct TES
{
    void* GetLogDate();
};

struct ActorMover
{
    void SetupPackageTarget(TESPackage*);
};

struct FUN_00981300_shell
{
    bool FUN_00981300() const;
};

struct AIProcess
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d0a();
    virtual void d0b();
    virtual void d0c();
    virtual void d0d();
    virtual void d0e();
    virtual void d0f();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d1a();
    virtual void d1b();
    virtual void d1c();
    virtual void d1d();
    virtual void d1e();
    virtual void d1f();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d2a();
    virtual void d2b();
    virtual void d2c();
    virtual bool MethodB4(TES*, TESPackage**);
};

class CombatController
{
  public:
    char pad[0xbc];
    TES* pActor;

    void FUN_00981380();
};

}  // namespace fnv_00981380

namespace fnv_00981450 {
struct PathingSolution
{
    unsigned int GetVirtualNodeCount();
};

struct TES
{
    void* GetLogDate();
};

struct FUN_00981300_shell
{
    bool FUN_00981300() const;
};

struct AIProcess
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
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual int vfunc_20c();
};

class CombatController
{
  public:
    char pad0[0x80];
    PathingSolution* field_80;
    char pad1[0xbc - 0x84];
    TES* pActor;
    void* field_c0;
    char pad2[0x125 - 0xc4];
    bool byte_125;
    bool byte_126;

    bool FUN_00981450();
};

}  // namespace fnv_00981450

namespace fnv_00981570 {

struct Actor
{
    void FUN_00884f80();
};

struct Dummy00981520
{
    void FUN_009815f0(int);
};

}  // namespace fnv_00981570

namespace fnv_009948f0 {
struct BSThread
{
    unsigned int GetThreadID();
};

struct GameTimerRecord
{
    unsigned int GetTime() const;
};

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};

struct Item
{
    BSThread* thread;
    char pad[8];
    int field_c;
};

}  // namespace fnv_009948f0

namespace fnv_009805b0 {
class BSAudio
{
  public:
    int GetAudioBackendData(void);
};

class GameTimerRecord
{
  public:
    unsigned int GetTime(void) const;
};

struct FUN_00980700_shell
{
    int FUN_00980700(int);
    void* GetEntryAt(unsigned int);
    void FUN_00980740(int);
};

struct FUN_009d7c20_shell
{
    void FUN_00980770(void);
};

}  // namespace fnv_009805b0

struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};

struct CombatProcedure
{
    virtual void FUN_009823c0_vt0();
    virtual void FUN_009823c0_vt1();
    virtual void FUN_009823c0_vt2(void*);
    virtual void FUN_009823c0_vt3();
    virtual void FUN_009823c0_vt4();
    virtual void FUN_009823c0_vt5();
    virtual void FUN_009823c0_vt6();
    virtual void FUN_009823c0_vt7();
    virtual void FUN_009823c0_vt8();
    virtual void FUN_009823c0_vt9();
    virtual void FUN_009823c0_vt10();
    virtual void FUN_009823c0_vt11();
    virtual void FUN_009823c0_vt12();
    virtual void FUN_009823c0_vt13();
    virtual void FUN_009823c0_vt14();
    virtual void FUN_009823c0_vt15(void*);
    virtual void FUN_009823c0_vt16();
    virtual void FUN_009823c0_vt17();
    virtual void FUN_009823c0_vt18();
    virtual void FUN_009823c0_vt19();
};

struct SaveLoadStub
{
    bool FUN_0042ce10();
    bool GetInitingForms() const;
};
struct DataHandlerStub
{
    bool FUN_004226e0();
};
struct SaveLoadGameStub
{
    bool FUN_0047c850();
};
extern SaveLoadStub* g_BGSSaveLoadGame;
extern DataHandlerStub* g_dataHandler;
extern SaveLoadGameStub* g_TESSaveLoadGame;
extern int g_iCombatControllerCount;

struct ActorStub
{
    void FUN_008b3d30();
    void SetActiveState(int, int, int);
    bool FUN_00894d60();
    bool FUN_00894cc0(bool);
};
struct CombatGroupStub
{
    void FUN_009869a0(void*);
};
struct CombatStateStub2
{
    ~CombatStateStub2();
};
struct PackageBase
{
    virtual ~PackageBase();
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
};
struct ArrStub
{
    void* vt;
    void* buf;
    unsigned int size;
    unsigned int reserved;
    ~ArrStub();
};
struct RefPtrStub
{
    void* obj;
    ~RefPtrStub();
};

struct FUN_0097d770 : PackageBase
{
    CombatGroupStub* unk80;
    int unk84;
    int unk88;
    ArrStub arr8C;
    CombatStateStub2* unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    void* unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    RefPtrStub ptrE8;
    RefPtrStub ptrEC;
    int unkF0;
    int unkF4;
    bool bF8;

    virtual ~FUN_0097d770();
    void FUN_00980830(int);
    void FUN_009801b0(int);
    void FUN_00980110(int);
    ActorStub* GetFieldBC();
    void FUN_00980360();
    void DestroyOwnedObject();
    void FUN_004534f0(int);
};

// @fnv 0x0097d770
FUN_0097d770::~FUN_0097d770()
{
    bF8 = true;
    if (g_BGSSaveLoadGame->FUN_0042ce10() && !g_BGSSaveLoadGame->GetInitingForms())
    {
        unk80 = 0;
    }
    if (!g_dataHandler->FUN_004226e0())
    {
        FUN_00980830(0);
        FUN_009801b0(0);
        GetFieldBC()->FUN_008b3d30();
        GetFieldBC()->SetActiveState(0, 0, 0);
        FUN_00980110(0);
    }
    FUN_00980360();
    DestroyOwnedObject();
    if (unk80)
    {
        unk80->FUN_009869a0(unkBC);
    }
    delete unk9C;
    FUN_004534f0(1);
    if (!g_TESSaveLoadGame->FUN_0047c850() && GetFieldBC() && GetFieldBC()->FUN_00894d60())
    {
        GetFieldBC()->FUN_00894cc0(false);
    }
    if (--g_iCombatControllerCount < 0)
    {
        g_iCombatControllerCount = 0;
    }
}

class FUN_0097d9d0_cls;

class Sub0097d9d0
{
  public:
    float Query008853a0();
    float Query008854d0(int flag);
    unsigned char Query008eea60();
    class Target0097d9d0* Query004181e0();
};

class Target0097d9d0
{
  public:
    bool Query005f0c80();
};

class FUN_0097d9d0_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C,
        unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8;
    Sub0097d9d0* m_pSub;
    int unkC0, unkC4, unkC8;
    float m_cc;
    float m_d0;
    unsigned char m_d4;
    unsigned char m_d5;

    void FUN_0097d9d0();
};

struct VtableOwner;
struct Selection
{
    bool __thiscall Lookup();
};
struct Container
{
    Selection* __thiscall FUN_00497280(unsigned short handle, unsigned int* output);
};
typedef Container*(__thiscall* GetContainerMethod)(VtableOwner*);
struct VtableOwner
{
    void** vtable;
    unsigned short __thiscall FUN_00897910(unsigned int mode, int value, bool empty, int reserved);
};

class SpawnedObject;
class FUN_00980400_list
{
  public:
    unsigned int GetSize();
    SpawnedObject** GetAt(unsigned int index);
};
class SpawnedObject
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual int v34();
};
class FUN_00980400_cls
{
  public:
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5C;
    int m_unk60;
    int m_unk64;
    int m_unk68;
    int m_unk6C;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    int m_unk7C;
    int m_unk80;
    int m_unk84;
    int m_unk88;
    FUN_00980400_list m_kNode;
    SpawnedObject* FUN_00980400(int target);
};
// Scans the list for the first SpawnedObject whose v34() equals target and returns it, otherwise returns 0.
// @fnv 0x00980400
SpawnedObject* FUN_00980400_cls::FUN_00980400(int target)
{
    for (unsigned int i = 0; i < m_kNode.GetSize(); i++)
    {
        SpawnedObject* obj = *m_kNode.GetAt(i);
        if (obj->v34() == target)
        {
            return obj;
        }
    }
    return 0;
}

// Combat controller update, reconstructed from the assigned image.
struct CombatUpdater;
struct UpdateAction
{
    virtual ~UpdateAction();
    virtual void Update();
    virtual void Slot08();
    virtual void Stop();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2c();
    virtual void Slot30();
    bool IsField8One();
    bool FUN_00666f00();
};
struct UpdateProcess
{
    virtual void Slot000();
    virtual void Slot004();
    virtual void Slot008();
    virtual void Slot00c();
    virtual void Slot010();
    virtual void Slot014();
    virtual void Slot018();
    virtual void Slot01c();
    virtual void Slot020();
    virtual void Slot024();
    virtual void Slot028();
    virtual void Slot02c();
    virtual void Slot030();
    virtual void Slot034();
    virtual void Slot038();
    virtual void Slot03c();
    virtual void Slot040();
    virtual void Slot044();
    virtual void Slot048();
    virtual void Slot04c();
    virtual void Slot050();
    virtual void Slot054();
    virtual void Slot058();
    virtual void Slot05c();
    virtual void Slot060();
    virtual void Slot064();
    virtual void Slot068();
    virtual void Slot06c();
    virtual void Slot070();
    virtual void Slot074();
    virtual void Slot078();
    virtual void Slot07c();
    virtual void Slot080();
    virtual void Slot084();
    virtual void Slot088();
    virtual void Slot08c();
    virtual void Slot090();
    virtual void Slot094();
    virtual void Slot098();
    virtual void Slot09c();
    virtual void Slot0a0();
    virtual void Slot0a4();
    virtual void Slot0a8();
    virtual void Slot0ac();
    virtual void Slot0b0();
    virtual void Slot0b4();
    virtual void Slot0b8();
    virtual void Slot0bc();
    virtual void Slot0c0();
    virtual void Slot0c4();
    virtual void Slot0c8();
    virtual void Slot0cc();
    virtual void Slot0d0();
    virtual void Slot0d4();
    virtual void Slot0d8();
    virtual void Slot0dc();
    virtual void Slot0e0();
    virtual void Slot0e4();
    virtual void Slot0e8();
    virtual void Slot0ec();
    virtual void Slot0f0();
    virtual void Slot0f4();
    virtual void Slot0f8();
    virtual void Slot0fc();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10c();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11c();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12c();
    virtual void Slot130();
    virtual void Slot134();
    virtual void Slot138();
    virtual void Slot13c();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14c();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15c();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16c();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17c();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18c();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19c();
    virtual void Slot1a0();
    virtual void Slot1a4();
    virtual void Slot1a8();
    virtual void Slot1ac();
    virtual void Slot1b0();
    virtual void Slot1b4();
    virtual void Slot1b8();
    virtual void Slot1bc();
    virtual void Slot1c0();
    virtual void Slot1c4();
    virtual void Slot1c8();
    virtual void Slot1cc();
    virtual void Slot1d0();
    virtual void Slot1d4();
    virtual void Slot1d8();
    virtual void Slot1dc();
    virtual void Slot1e0();
    virtual void Slot1e4();
    virtual void Slot1e8();
    virtual void Slot1ec();
    virtual void Slot1f0();
    virtual void Slot1f4();
    virtual void Slot1f8();
    virtual void Slot1fc();
    virtual void Slot200();
    virtual void Slot204();
    virtual void Slot208();
    virtual void Slot20c();
    virtual void Slot210();
    virtual void Slot214();
    virtual void Slot218();
    virtual void Slot21c();
    virtual void Slot220();
    virtual void Slot224();
    virtual void Slot228();
    virtual void Slot22c();
    virtual void Slot230();
    virtual void Slot234();
    virtual void Slot238();
    virtual void Slot23c();
    virtual void Slot240();
    virtual void Slot244();
    virtual void Slot248();
    virtual void Slot24c();
    virtual void Slot250();
    virtual void Slot254();
    virtual void Slot258();
    virtual void Slot25c();
    virtual void Slot260();
    virtual void Slot264();
    virtual void Slot268();
    virtual void Slot26c();
    virtual void Slot270();
    virtual void Slot274();
    virtual void Slot278();
    virtual void Slot27c();
    virtual void Slot280();
    virtual void Slot284();
    virtual void Slot288();
    virtual void Slot28c();
    virtual void Slot290();
    virtual void Slot294();
    virtual void Slot298();
    virtual void Slot29c();
    virtual void Slot2a0();
    virtual void Slot2a4();
    virtual void Slot2a8();
    virtual void Slot2ac();
    virtual void Slot2b0();
    virtual void Slot2b4();
    virtual void Slot2b8();
    virtual void Slot2bc();
    virtual void Slot2c0();
    virtual void Slot2c4();
    virtual void Slot2c8();
    virtual void Slot2cc();
    virtual void Slot2d0();
    virtual void Slot2d4();
    virtual void Slot2d8();
    virtual void Slot2dc();
    virtual void Slot2e0();
    virtual void Slot2e4();
    virtual void Slot2e8();
    virtual void Slot2ec();
    virtual void Slot2f0();
    virtual void Slot2f4();
    virtual void Slot2f8();
    virtual void Slot2fc();
    virtual void Slot300();
    virtual void Slot304();
    virtual void Slot308();
    virtual void Slot30c();
    virtual void Slot310();
    virtual void Slot314();
    virtual void Slot318();
    virtual void Slot31c();
    virtual void Slot320();
    virtual void Slot324();
    virtual void Slot328();
    virtual void Slot32c();
    virtual void Slot330();
    virtual void Slot334();
    virtual void Slot338();
    virtual void Slot33c();
    virtual void Slot340();
    virtual void Slot344();
    virtual void Slot348();
    virtual void Slot34c();
    virtual void Slot350();
    virtual void Slot354();
    virtual void Slot358();
    virtual void Slot35c();
    virtual void Slot360();
    virtual void Slot364();
    virtual void Slot368();
    virtual void Slot36c();
    virtual void Slot370();
    virtual void Slot374();
    virtual void Slot378();
    virtual void Slot37c();
    virtual void Slot380();
    virtual void Slot384();
    virtual void Slot388();
    virtual void Slot38c();
    virtual void Slot390();
    virtual void Slot394();
    virtual void Slot398();
    virtual void Slot39c();
    virtual void Slot3a0();
    virtual void Slot3a4();
    virtual void Slot3a8();
    virtual void Slot3ac();
    virtual void Slot3b0();
    virtual void Slot3b4();
    virtual void Slot3b8();
    virtual void Slot3bc();
    virtual void Slot3c0();
    virtual void Slot3c4();
    virtual void Slot3c8();
    virtual void Slot3cc();
    virtual void Slot3d0();
    virtual void Slot3d4();
    virtual void Slot3d8();
    virtual void Slot3dc();
    virtual void Slot3e0();
    virtual void Slot3e4();
    virtual void Slot3e8();
    virtual void Slot3ec();
    virtual void Slot3f0();
    virtual void Slot3f4();
    virtual void Slot3f8();
    virtual void Slot3fc();
    virtual void Slot400();
    virtual void Slot404();
    virtual void Slot408();
    virtual void Slot40c();
    virtual void Slot410();
    virtual void Slot414();
    virtual void Slot418();
    virtual void Slot41c();
    virtual void Slot420();
    virtual void Slot424();
    virtual void Slot428();
    virtual void Slot42c();
    virtual void Slot430();
    virtual void Slot434();
    virtual void Slot438();
    virtual void Slot43c();
    virtual void Slot440();
    virtual void Slot444();
    virtual void Slot448();
    virtual void Slot44c();
    virtual void Slot450();
    virtual void Slot454();
    virtual void Slot458();
    virtual void Slot45c();
    virtual void Slot460();
    virtual void Slot464();
    virtual void Slot468();
    virtual void Slot46c();
    virtual void Slot470();
    virtual void Slot474();
    virtual void Slot478();
    virtual void Slot47c();
    virtual void Slot480();
    virtual void Slot484();
    virtual void Slot488();
    virtual void Slot48c();
    virtual void Slot490();
    virtual void Slot494();
    virtual void Slot498();
    virtual void Slot49c();
    virtual void Slot4a0();
    virtual void Slot4a4();
    virtual void Slot4a8();
    virtual void Slot4ac();
    virtual void Slot4b0();
    virtual void Slot4b4();
    virtual void Slot4b8();
    virtual void Slot4bc();
    virtual void Slot4c0();
    virtual void Slot4c4();
    virtual void Slot4c8();
    virtual void Slot4cc();
    virtual void Slot4d0();
    virtual void Slot4d4();
    virtual void Slot4d8();
    virtual void Slot4dc();
    virtual void Slot4e0();
    virtual void Slot4e4();
    virtual void Slot4e8();
    virtual void Slot4ec();
    virtual void Slot4f0();
    virtual void Slot4f4();
    virtual void Slot4f8();
    virtual void Slot4fc();
    virtual void Slot500();
    virtual void Slot504();
    virtual void Slot508();
    virtual void Slot50c();
    virtual void Slot510();
    virtual void Slot514();
    virtual void Slot518();
    virtual void Slot51c();
    virtual void Slot520();
    virtual void Slot524();
    virtual void Slot528();
    virtual void Slot52c();
    virtual void Slot530();
    virtual void Slot534();
    virtual void Slot538();
    virtual void Slot53c();
    virtual void Slot540();
    virtual void Slot544();
    virtual void Slot548();
    virtual void Slot54c();
    virtual void Slot550();
    virtual void Slot554();
    virtual void Slot558();
    virtual void Slot55c();
    virtual void Slot560();
    virtual void Slot564();
    virtual void Slot568();
    virtual void Slot56c();
    virtual void Slot570();
    virtual void Slot574();
    virtual void Slot578();
    virtual void Slot57c();
    virtual void Slot580();
    virtual void Slot584();
    virtual void Slot588();
    virtual void Slot58c();
    virtual void Slot590();
    virtual void Slot594();
    virtual void Slot598();
    virtual void Slot59c();
    virtual void Slot5a0();
    virtual void Slot5a4();
    virtual void Slot5a8();
    virtual void Slot5ac();
    virtual void Slot5b0();
    virtual void Slot5b4();
    virtual void Slot5b8();
    virtual void Slot5bc();
    virtual void Slot5c0();
    virtual void Slot5c4();
    virtual void Slot5c8();
    virtual void Slot5cc();
    virtual void Slot5d0();
    virtual void Slot5d4();
    virtual void Slot5d8();
    virtual void Slot5dc();
    virtual void Slot5e0();
    virtual void Slot5e4();
    virtual void Slot5e8();
    virtual void Slot5ec();
    virtual void Slot5f0();
    virtual void Slot5f4();
    virtual void Slot5f8();
    virtual void Slot5fc();
    virtual void Slot600();
    virtual void Slot604();
    virtual void Slot608();
    virtual void Slot60c();
    virtual int GetState();
};
struct UpdateActor
{
    virtual void Slot000();
    virtual void Slot004();
    virtual void Slot008();
    virtual void Slot00c();
    virtual void Slot010();
    virtual void Slot014();
    virtual void Slot018();
    virtual void Slot01c();
    virtual void Slot020();
    virtual void Slot024();
    virtual void Slot028();
    virtual void Slot02c();
    virtual void Slot030();
    virtual void Slot034();
    virtual void Slot038();
    virtual void Slot03c();
    virtual void Slot040();
    virtual void Slot044();
    virtual void Slot048();
    virtual void Slot04c();
    virtual void Slot050();
    virtual void Slot054();
    virtual void Slot058();
    virtual void Slot05c();
    virtual void Slot060();
    virtual void Slot064();
    virtual void Slot068();
    virtual void Slot06c();
    virtual void Slot070();
    virtual void Slot074();
    virtual void Slot078();
    virtual void Slot07c();
    virtual void Slot080();
    virtual void Slot084();
    virtual void Slot088();
    virtual void Slot08c();
    virtual void Slot090();
    virtual void Slot094();
    virtual void Slot098();
    virtual void Slot09c();
    virtual void Slot0a0();
    virtual void Slot0a4();
    virtual void Slot0a8();
    virtual void Slot0ac();
    virtual void Slot0b0();
    virtual void Slot0b4();
    virtual void Slot0b8();
    virtual void Slot0bc();
    virtual void Slot0c0();
    virtual void Slot0c4();
    virtual void Slot0c8();
    virtual void Slot0cc();
    virtual void Slot0d0();
    virtual void Slot0d4();
    virtual void Slot0d8();
    virtual void Slot0dc();
    virtual void Slot0e0();
    virtual void Slot0e4();
    virtual void Slot0e8();
    virtual void Slot0ec();
    virtual void Slot0f0();
    virtual void Slot0f4();
    virtual void Slot0f8();
    virtual void Slot0fc();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10c();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11c();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12c();
    virtual void Slot130();
    virtual void Slot134();
    virtual void Slot138();
    virtual void Slot13c();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14c();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15c();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16c();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17c();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18c();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19c();
    virtual void Slot1a0();
    virtual void Slot1a4();
    virtual void Slot1a8();
    virtual void Slot1ac();
    virtual void Slot1b0();
    virtual void Slot1b4();
    virtual void Slot1b8();
    virtual void Slot1bc();
    virtual void Slot1c0();
    virtual void Slot1c4();
    virtual void Slot1c8();
    virtual void Slot1cc();
    virtual int HasTarget();
    virtual void Slot1d4();
    virtual void Slot1d8();
    virtual void Slot1dc();
    virtual void Slot1e0();
    virtual UpdateActor* GetTarget();
    virtual void Slot1e8();
    virtual void Slot1ec();
    virtual void Slot1f0();
    virtual void Slot1f4();
    virtual void Slot1f8();
    virtual void Slot1fc();
    virtual void Slot200();
    virtual void Slot204();
    virtual void Slot208();
    virtual void Slot20c();
    virtual void Slot210();
    virtual int IsDisabled();
    virtual void Slot218();
    virtual void Slot21c();
    virtual void Slot220();
    virtual void Slot224();
    virtual void Slot228();
    virtual bool IsInvalid(int);
    virtual bool IsRestrained();
    virtual bool IsUnconscious();
    virtual void Slot238();
    virtual void Slot23c();
    virtual void Slot240();
    virtual void Slot244();
    virtual void Slot248();
    virtual void Slot24c();
    virtual void Slot250();
    virtual void Slot254();
    virtual void Slot258();
    virtual void Slot25c();
    virtual void Slot260();
    virtual void Slot264();
    virtual void Slot268();
    virtual void Slot26c();
    virtual void Slot270();
    virtual void Slot274();
    virtual void Slot278();
    virtual void Slot27c();
    virtual void Slot280();
    virtual void Slot284();
    virtual void Slot288();
    virtual void Slot28c();
    virtual void Slot290();
    virtual void Slot294();
    virtual void Slot298();
    virtual void Slot29c();
    virtual void Slot2a0();
    virtual void Slot2a4();
    virtual void Slot2a8();
    virtual void Slot2ac();
    virtual void Slot2b0();
    virtual void Slot2b4();
    virtual void Slot2b8();
    virtual void Slot2bc();
    virtual void Slot2c0();
    virtual void Slot2c4();
    virtual void Slot2c8();
    virtual void Slot2cc();
    virtual void Slot2d0();
    virtual void Slot2d4();
    virtual void Slot2d8();
    virtual void Slot2dc();
    virtual void Slot2e0();
    virtual void Slot2e4();
    virtual bool IsDead();
    virtual void Slot2ec();
    virtual void Slot2f0();
    virtual void Slot2f4();
    virtual void Slot2f8();
    virtual void Slot2fc();
    virtual void Slot300();
    virtual void Slot304();
    virtual void Slot308();
    virtual void Slot30c();
    virtual void Slot310();
    virtual void Slot314();
    virtual void Slot318();
    virtual void Slot31c();
    virtual void Slot320();
    virtual void Slot324();
    virtual void Slot328();
    virtual void Slot32c();
    virtual void Slot330();
    virtual void Slot334();
    virtual void Slot338();
    virtual void Slot33c();
    virtual void Slot340();
    virtual void Slot344();
    virtual void Slot348();
    virtual void Slot34c();
    virtual void Slot350();
    virtual void Slot354();
    virtual void Slot358();
    virtual void Slot35c();
    virtual void Slot360();
    virtual void Slot364();
    virtual void Slot368();
    virtual void Slot36c();
    virtual void Slot370();
    virtual void Slot374();
    virtual void Slot378();
    virtual void Slot37c();
    virtual void Slot380();
    virtual void Slot384();
    virtual void Slot388();
    virtual void Slot38c();
    virtual void Slot390();
    virtual void Slot394();
    virtual void Slot398();
    virtual void Slot39c();
    virtual void Slot3a0();
    virtual void Slot3a4();
    virtual void Slot3a8();
    virtual void Slot3ac();
    virtual void Slot3b0();
    virtual void Slot3b4();
    virtual void Slot3b8();
    virtual void Slot3bc();
    virtual void Slot3c0();
    virtual void Slot3c4();
    virtual void Slot3c8();
    virtual void Slot3cc();
    virtual void Slot3d0();
    virtual void Slot3d4();
    virtual void Slot3d8();
    virtual void Slot3dc();
    virtual void Slot3e0();
    virtual short GetType();
    virtual void Slot3e8();
    virtual void Slot3ec();
    virtual void Slot3f0();
    virtual void Slot3f4();
    virtual void Slot3f8();
    virtual void Slot3fc();
    virtual void Slot400();
    virtual void Slot404();
    virtual void Slot408();
    virtual void Slot40c();
    virtual void Slot410();
    virtual void Slot414();
    virtual void Slot418();
    virtual void Slot41c();
    virtual void Slot420();
    virtual void Slot424();
    virtual void Slot428();
    virtual void Slot42c();
    virtual void Slot430();
    virtual void RejectAction(UpdateActor*);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    UpdateActor* baseForm;
    UpdateProcess* FUN_008d8520();
    bool FUN_00440da0();
    bool FUN_00440d80();
    bool FUN_00493830();
    bool FUN_008a7a40();
    bool FUN_00493bb0();
    void SetActiveState(bool, int, bool);
};
struct DurationTracker
{
    unsigned int time;
    unsigned int duration;
    bool FUN_008d7f80();
    void FUN_008d7f40(float);
};
struct UpdatePlan
{
    bool FUN_0097e490();
    unsigned int FUN_0084e3a0();
    void AdvanceActions(CombatUpdater*);
};
struct UpdateGroup
{
    void FUN_009891d0(CombatUpdater*, unsigned int);
    int SelectActor(void*);
};
struct UpdateState
{
    void FUN_00997cb0();
    bool GetByteAtOffset();
    void UpdateStageHolders();
};
struct UpdateActionArray
{
    void* vtable;
    UpdateAction** data;
    unsigned int size;
    unsigned int capacity;
    unsigned int FUN_0044ddc0();
    UpdateAction*& FUN_006a7ad0(unsigned int);
    void FUN_009a4320(unsigned int, unsigned int);
};
// Base constructor clears 2039 pointer-sized search buckets (0x1fdc bytes).
struct CombatUpdater
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    UpdateGroup* group;
    UpdateAction* action84;
    UpdateAction* action88;
    UpdateActionArray actions;
    UpdateState* state;
    UpdatePlan* plan;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int planID;
    unsigned int unk0b0;
    DurationTracker timer;
    void* data;
    unsigned int unk0c0;
    unsigned short unk0c4;
    signed char mode;
    unsigned char unk0c7;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned char initialized;
    unsigned char unk0e5;
    unsigned short unk0e6;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned char flag124;
    unsigned char flag125;
    unsigned char updating126;
    unsigned char flag127;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    UpdateActor* GetFieldBC();
    UpdateActor* FUN_004030b0();
    bool FUN_00981450();
    void FUN_0097d990();
    void FUN_0097f390();
    bool FUN_00980470();
    void InitFromArg(UpdateAction*);
    bool FUN_009804d0();
    void DestroyOwnedObject();
    void FUN_00980360();
    void FUN_00980830(int);
    void RemoveTopic();
    void FUN_00980250();
    void UpdateMoveTarget();
    void FUN_0097da50();
};

struct CSActor;

struct CSProcess
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
    virtual float GetAmount(CSActor* apActor, CSActor* apTarget);
};

struct CSActor
{
    CSProcess* GetProcess();
    bool CheckA(CSActor* apActor, int aiFlag, int* apOut, int aiExtra);
};

struct Target80830;
struct Related80830
{
    void DecrementField4A(void*);
    void FUN_009874b0(void*);
    int GetFieldD0();
    int GetResultForArg(void*);
};
struct State80830
{
    bool GetByteAtOffset();
    void FUN_00997cf0();
};
struct Actor80830
{
    virtual void unk000();
    virtual void unk004();
    virtual void unk008();
    virtual void unk00c();
    virtual void unk010();
    virtual void unk014();
    virtual void unk018();
    virtual void unk01c();
    virtual void unk020();
    virtual void unk024();
    virtual void unk028();
    virtual void unk02c();
    virtual void unk030();
    virtual void unk034();
    virtual void unk038();
    virtual void unk03c();
    virtual void unk040();
    virtual void unk044();
    virtual void unk048();
    virtual void unk04c();
    virtual void unk050();
    virtual void unk054();
    virtual void unk058();
    virtual void unk05c();
    virtual void unk060();
    virtual void unk064();
    virtual void unk068();
    virtual void unk06c();
    virtual void unk070();
    virtual void unk074();
    virtual void unk078();
    virtual void unk07c();
    virtual void unk080();
    virtual void unk084();
    virtual void unk088();
    virtual void unk08c();
    virtual void unk090();
    virtual void unk094();
    virtual void unk098();
    virtual void unk09c();
    virtual void unk0a0();
    virtual void unk0a4();
    virtual void unk0a8();
    virtual void unk0ac();
    virtual void unk0b0();
    virtual void unk0b4();
    virtual void unk0b8();
    virtual void unk0bc();
    virtual void unk0c0();
    virtual void unk0c4();
    virtual void unk0c8();
    virtual void unk0cc();
    virtual void unk0d0();
    virtual void unk0d4();
    virtual void unk0d8();
    virtual void unk0dc();
    virtual void unk0e0();
    virtual void unk0e4();
    virtual void unk0e8();
    virtual void unk0ec();
    virtual void unk0f0();
    virtual void unk0f4();
    virtual void unk0f8();
    virtual void unk0fc();
    virtual void unk100();
    virtual void unk104();
    virtual void unk108();
    virtual void unk10c();
    virtual void unk110();
    virtual void unk114();
    virtual void unk118();
    virtual void unk11c();
    virtual void unk120();
    virtual void unk124();
    virtual void unk128();
    virtual void unk12c();
    virtual void unk130();
    virtual void unk134();
    virtual void unk138();
    virtual void unk13c();
    virtual void unk140();
    virtual void unk144();
    virtual void unk148();
    virtual void unk14c();
    virtual void unk150();
    virtual void unk154();
    virtual void unk158();
    virtual void unk15c();
    virtual void unk160();
    virtual void unk164();
    virtual void unk168();
    virtual void unk16c();
    virtual void unk170();
    virtual void unk174();
    virtual void unk178();
    virtual void unk17c();
    virtual void unk180();
    virtual void unk184();
    virtual void unk188();
    virtual void unk18c();
    virtual void unk190();
    virtual void unk194();
    virtual void unk198();
    virtual void unk19c();
    virtual void unk1a0();
    virtual void unk1a4();
    virtual void unk1a8();
    virtual void unk1ac();
    virtual void unk1b0();
    virtual void unk1b4();
    virtual void unk1b8();
    virtual void unk1bc();
    virtual void unk1c0();
    virtual void unk1c4();
    virtual void unk1c8();
    virtual void unk1cc();
    virtual void unk1d0();
    virtual void unk1d4();
    virtual void unk1d8();
    virtual void unk1dc();
    virtual void unk1e0();
    virtual void unk1e4();
    virtual void unk1e8();
    virtual void unk1ec();
    virtual void unk1f0();
    virtual void unk1f4();
    virtual void unk1f8();
    virtual void unk1fc();
    virtual void unk200();
    virtual void unk204();
    virtual void unk208();
    virtual void unk20c();
    virtual void unk210();
    virtual void unk214();
    virtual void unk218();
    virtual void unk21c();
    virtual void unk220();
    virtual void unk224();
    virtual void unk228();
    virtual bool Check(bool);
    void* FUN_005d43c0();
    int FUN_00931850();
};
struct Target80830
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
    Related80830* unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    State80830* unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    Actor80830* unkbc;
    void* unkc0;
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
    bool unkf8;
    int GetFieldBC();
    void FUN_0097f8c0();
    void FUN_00980830(void* target);
};

struct Ref
{
    void* GetNext();
};
struct Point
{
    float x, y, z;
};
struct Location
{
    Point pos;
    void* space;
    Location(Point const&, void*);
};
struct Target
{
    unsigned char* Type();
    void Clear();
    void SetMode(int);
    void AssignReference(Ref*, int, float, float);
    void SetLocation(Location*, int, float, float);
    void SetOther(int, Ref*, void*);
};
struct Setting
{
    float* Float();
};
extern Setting originalRuntimeFloatSetting415, originalRuntimeFloatSetting416, originalRuntimeFloatSetting417,
    originalRuntimeFloatSetting418, originalRuntimeFloatSetting419, originalRuntimeFloatSetting420,
    originalRuntimeFloatSetting421, originalRuntimeFloatSetting422;

namespace fnv_00981d00 {
struct LoadBufferStand
{
    virtual unsigned char Version();
    void FUN_008648e0(void*);
    void FUN_00864980(void*, unsigned int);
    unsigned int FUN_00864a60();
};
struct StateStand
{
    void FUN_009a2040(LoadBufferStand*);
};
struct ProcedureStand;
struct ProcArrayStand
{
    int unk00, unk04, unk08, unk0C;
    void FUN_006f2290(unsigned int, bool);
    ProcedureStand*& FUN_006a7ad0(unsigned int);
};
struct CombatStand;
struct FUN_00993d60
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    FUN_00993d60(CombatStand*);
    void ReadFromStream(LoadBufferStand*);
    void* FUN_0084e3a0();
};
struct TimerStand
{
    float unk00, unk04;
    void FUN_009a5f20(LoadBufferStand*);
};
struct PointStand
{
    float x, y, z;
};
struct CombatStand
{
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
    void* unk80;
    ProcedureStand* unk84;
    ProcedureStand* unk88;
    ProcArrayStand unk8C;
    StateStand* unk9C;
    FUN_00993d60* unkA0;
    int unkA4;
    void* unkA8;
    void* unkAC;
    int unkB0;
    TimerStand unkB4;
    void* unkBC;
    void* unkC0;
    unsigned char unkC4, unkC5, unkC6, unkC7;
    unsigned int unkC8;
    float unkCC, unkD0;
    unsigned int unkD4;
    float unkD8, unkDC;
    int unkE0;
    unsigned char unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    unsigned char unk124, unk125, unk126, unk127;
    PointStand unk128[2];
    unsigned char unk140[2];
    unsigned char unk142;
    int unk144, unk148;
    void LoadPackage(LoadBufferStand*);
    void LoadCombatProcedure(ProcedureStand**, LoadBufferStand*);
    void hkpMultiThreadedSimulation_MtEntityEntityBroadPhaseListener_removeCollisionPair(LoadBufferStand*);
};
}  // namespace fnv_00981d00

struct QuantityData
{
    void SetQuantity(unsigned int);
};

struct ScrapHeapBuffer
{
    char pad[0x10];
    ScrapHeapBuffer();
    ~ScrapHeapBuffer();
};

struct FUN_009aa470_Class
{
    char pad[0x5c];
    void* FUN_009aa470();
    FUN_009aa470_Class()
    {
        FUN_009aa470();
    }
};

struct FUN_009958b0_Class : public QuantityData
{
    FUN_009958b0_Class* FUN_009958b0();
    ~FUN_009958b0_Class();
    FUN_009958b0_Class()
    {
        FUN_009958b0();
    }
};

struct FUN_009825e0_class
{
    virtual void v0();
    void FUN_00982530();
    ~FUN_009825e0_class()
    {
        FUN_00982530();
    }
};

struct Member20c8
{
    void FUN_00995910();
    ~Member20c8()
    {
        FUN_00995910();
    }
};

struct FUN_0097e3e0 : public FUN_009825e0_class
{
    char pad_04[0x20b4];
    ScrapHeapBuffer m_pStreamAllocator;
    Member20c8 m_20c8;

    virtual ~FUN_0097e3e0();
};

// @fnv 0x0097e3e0
FUN_0097e3e0::~FUN_0097e3e0()
{
    ((FUN_00995830_Class*)this)->FUN_00995830();
}

class TESForm
{
  public:
    virtual ~TESForm();
};

namespace fnv_00994bd0 {
struct Context;
struct Item
{
};
struct Owner
{
    Item* FUN_00726070();
    void* FUN_00559450(Item*);
};
struct Node
{
    Owner** FUN_006815c0();
    Node* FUN_0062d990();
};
struct Goal
{
    virtual bool Test(Context*);
    virtual void End(void*, Context*);
    Node* GetOffsetC();
};
struct Entry
{
    void* unk00;
    void* unk04;
    Entry(void*);
    static void* operator new(unsigned, void*);
    static void operator delete(void*, void*);
};
struct Context
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void UpdateWorldState(void*);
    void ResetState(Context*);
    Item* GetCombatGoal(Item*);
    bool FUN_009aadc0(void*);
    void AppendPair(Entry*, Context*);
};
struct Allocator
{
    void* FUN_00aa54a0(unsigned, unsigned);
};
struct Input
{
    void FUN_00994ef0(void*);
};
struct Target
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15C;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16C;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17C;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18C;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19C;
    void* unk1A0;
    void* unk1A4;
    void* unk1A8;
    void* unk1AC;
    void* unk1B0;
    void* unk1B4;
    void* unk1B8;
    void* unk1BC;
    void* unk1C0;
    void* unk1C4;
    void* unk1C8;
    void* unk1CC;
    void* unk1D0;
    void* unk1D4;
    void* unk1D8;
    void* unk1DC;
    void* unk1E0;
    void* unk1E4;
    void* unk1E8;
    void* unk1EC;
    void* unk1F0;
    void* unk1F4;
    void* unk1F8;
    void* unk1FC;
    void* unk200;
    void* unk204;
    void* unk208;
    void* unk20C;
    void* unk210;
    void* unk214;
    void* unk218;
    void* unk21C;
    void* unk220;
    void* unk224;
    void* unk228;
    void* unk22C;
    void* unk230;
    void* unk234;
    void* unk238;
    void* unk23C;
    void* unk240;
    void* unk244;
    void* unk248;
    void* unk24C;
    void* unk250;
    void* unk254;
    void* unk258;
    void* unk25C;
    void* unk260;
    void* unk264;
    void* unk268;
    void* unk26C;
    void* unk270;
    void* unk274;
    void* unk278;
    void* unk27C;
    void* unk280;
    void* unk284;
    void* unk288;
    void* unk28C;
    void* unk290;
    void* unk294;
    void* unk298;
    void* unk29C;
    void* unk2A0;
    void* unk2A4;
    void* unk2A8;
    void* unk2AC;
    void* unk2B0;
    void* unk2B4;
    void* unk2B8;
    void* unk2BC;
    void* unk2C0;
    void* unk2C4;
    void* unk2C8;
    void* unk2CC;
    void* unk2D0;
    void* unk2D4;
    void* unk2D8;
    void* unk2DC;
    void* unk2E0;
    void* unk2E4;
    void* unk2E8;
    void* unk2EC;
    void* unk2F0;
    void* unk2F4;
    void* unk2F8;
    void* unk2FC;
    void* unk300;
    void* unk304;
    void* unk308;
    void* unk30C;
    void* unk310;
    void* unk314;
    void* unk318;
    void* unk31C;
    void* unk320;
    void* unk324;
    void* unk328;
    void* unk32C;
    void* unk330;
    void* unk334;
    void* unk338;
    void* unk33C;
    void* unk340;
    void* unk344;
    void* unk348;
    void* unk34C;
    void* unk350;
    void* unk354;
    void* unk358;
    void* unk35C;
    void* unk360;
    void* unk364;
    void* unk368;
    void* unk36C;
    void* unk370;
    void* unk374;
    void* unk378;
    void* unk37C;
    void* unk380;
    void* unk384;
    void* unk388;
    void* unk38C;
    void* unk390;
    void* unk394;
    void* unk398;
    void* unk39C;
    void* unk3A0;
    void* unk3A4;
    void* unk3A8;
    void* unk3AC;
    void* unk3B0;
    void* unk3B4;
    void* unk3B8;
    void* unk3BC;
    void* unk3C0;
    void* unk3C4;
    void* unk3C8;
    void* unk3CC;
    void* unk3D0;
    void* unk3D4;
    void* unk3D8;
    void* unk3DC;
    void* unk3E0;
    void* unk3E4;
    void* unk3E8;
    void* unk3EC;
    void* unk3F0;
    void* unk3F4;
    void* unk3F8;
    void* unk3FC;
    void* unk400;
    void* unk404;
    void* unk408;
    void* unk40C;
    void* unk410;
    void* unk414;
    void* unk418;
    void* unk41C;
    void* unk420;
    void* unk424;
    void* unk428;
    void* unk42C;
    void* unk430;
    void* unk434;
    void* unk438;
    void* unk43C;
    void* unk440;
    void* unk444;
    void* unk448;
    void* unk44C;
    void* unk450;
    void* unk454;
    void* unk458;
    void* unk45C;
    void* unk460;
    void* unk464;
    void* unk468;
    void* unk46C;
    void* unk470;
    void* unk474;
    void* unk478;
    void* unk47C;
    void* unk480;
    void* unk484;
    void* unk488;
    void* unk48C;
    void* unk490;
    void* unk494;
    void* unk498;
    void* unk49C;
    void* unk4A0;
    void* unk4A4;
    void* unk4A8;
    void* unk4AC;
    void* unk4B0;
    void* unk4B4;
    void* unk4B8;
    void* unk4BC;
    void* unk4C0;
    void* unk4C4;
    void* unk4C8;
    void* unk4CC;
    void* unk4D0;
    void* unk4D4;
    void* unk4D8;
    void* unk4DC;
    void* unk4E0;
    void* unk4E4;
    void* unk4E8;
    void* unk4EC;
    void* unk4F0;
    void* unk4F4;
    void* unk4F8;
    void* unk4FC;
    void* unk500;
    void* unk504;
    void* unk508;
    void* unk50C;
    void* unk510;
    void* unk514;
    void* unk518;
    void* unk51C;
    void* unk520;
    void* unk524;
    void* unk528;
    void* unk52C;
    void* unk530;
    void* unk534;
    void* unk538;
    void* unk53C;
    void* unk540;
    void* unk544;
    void* unk548;
    void* unk54C;
    void* unk550;
    void* unk554;
    void* unk558;
    void* unk55C;
    void* unk560;
    void* unk564;
    void* unk568;
    void* unk56C;
    void* unk570;
    void* unk574;
    void* unk578;
    void* unk57C;
    void* unk580;
    void* unk584;
    void* unk588;
    void* unk58C;
    void* unk590;
    void* unk594;
    void* unk598;
    void* unk59C;
    void* unk5A0;
    void* unk5A4;
    void* unk5A8;
    void* unk5AC;
    void* unk5B0;
    void* unk5B4;
    void* unk5B8;
    void* unk5BC;
    void* unk5C0;
    void* unk5C4;
    void* unk5C8;
    void* unk5CC;
    void* unk5D0;
    void* unk5D4;
    void* unk5D8;
    void* unk5DC;
    void* unk5E0;
    void* unk5E4;
    void* unk5E8;
    void* unk5EC;
    void* unk5F0;
    void* unk5F4;
    void* unk5F8;
    void* unk5FC;
    void* unk600;
    void* unk604;
    void* unk608;
    void* unk60C;
    void* unk610;
    void* unk614;
    void* unk618;
    void* unk61C;
    void* unk620;
    void* unk624;
    void* unk628;
    void* unk62C;
    void* unk630;
    void* unk634;
    void* unk638;
    void* unk63C;
    void* unk640;
    void* unk644;
    void* unk648;
    void* unk64C;
    void* unk650;
    void* unk654;
    void* unk658;
    void* unk65C;
    void* unk660;
    void* unk664;
    void* unk668;
    void* unk66C;
    void* unk670;
    void* unk674;
    void* unk678;
    void* unk67C;
    void* unk680;
    void* unk684;
    void* unk688;
    void* unk68C;
    void* unk690;
    void* unk694;
    void* unk698;
    void* unk69C;
    void* unk6A0;
    void* unk6A4;
    void* unk6A8;
    void* unk6AC;
    void* unk6B0;
    void* unk6B4;
    void* unk6B8;
    void* unk6BC;
    void* unk6C0;
    void* unk6C4;
    void* unk6C8;
    void* unk6CC;
    void* unk6D0;
    void* unk6D4;
    void* unk6D8;
    void* unk6DC;
    void* unk6E0;
    void* unk6E4;
    void* unk6E8;
    void* unk6EC;
    void* unk6F0;
    void* unk6F4;
    void* unk6F8;
    void* unk6FC;
    void* unk700;
    void* unk704;
    void* unk708;
    void* unk70C;
    void* unk710;
    void* unk714;
    void* unk718;
    void* unk71C;
    void* unk720;
    void* unk724;
    void* unk728;
    void* unk72C;
    void* unk730;
    void* unk734;
    void* unk738;
    void* unk73C;
    void* unk740;
    void* unk744;
    void* unk748;
    void* unk74C;
    void* unk750;
    void* unk754;
    void* unk758;
    void* unk75C;
    void* unk760;
    void* unk764;
    void* unk768;
    void* unk76C;
    void* unk770;
    void* unk774;
    void* unk778;
    void* unk77C;
    void* unk780;
    void* unk784;
    void* unk788;
    void* unk78C;
    void* unk790;
    void* unk794;
    void* unk798;
    void* unk79C;
    void* unk7A0;
    void* unk7A4;
    void* unk7A8;
    void* unk7AC;
    void* unk7B0;
    void* unk7B4;
    void* unk7B8;
    void* unk7BC;
    void* unk7C0;
    void* unk7C4;
    void* unk7C8;
    void* unk7CC;
    void* unk7D0;
    void* unk7D4;
    void* unk7D8;
    void* unk7DC;
    void* unk7E0;
    void* unk7E4;
    void* unk7E8;
    void* unk7EC;
    void* unk7F0;
    void* unk7F4;
    void* unk7F8;
    void* unk7FC;
    void* unk800;
    void* unk804;
    void* unk808;
    void* unk80C;
    void* unk810;
    void* unk814;
    void* unk818;
    void* unk81C;
    void* unk820;
    void* unk824;
    void* unk828;
    void* unk82C;
    void* unk830;
    void* unk834;
    void* unk838;
    void* unk83C;
    void* unk840;
    void* unk844;
    void* unk848;
    void* unk84C;
    void* unk850;
    void* unk854;
    void* unk858;
    void* unk85C;
    void* unk860;
    void* unk864;
    void* unk868;
    void* unk86C;
    void* unk870;
    void* unk874;
    void* unk878;
    void* unk87C;
    void* unk880;
    void* unk884;
    void* unk888;
    void* unk88C;
    void* unk890;
    void* unk894;
    void* unk898;
    void* unk89C;
    void* unk8A0;
    void* unk8A4;
    void* unk8A8;
    void* unk8AC;
    void* unk8B0;
    void* unk8B4;
    void* unk8B8;
    void* unk8BC;
    void* unk8C0;
    void* unk8C4;
    void* unk8C8;
    void* unk8CC;
    void* unk8D0;
    void* unk8D4;
    void* unk8D8;
    void* unk8DC;
    void* unk8E0;
    void* unk8E4;
    void* unk8E8;
    void* unk8EC;
    void* unk8F0;
    void* unk8F4;
    void* unk8F8;
    void* unk8FC;
    void* unk900;
    void* unk904;
    void* unk908;
    void* unk90C;
    void* unk910;
    void* unk914;
    void* unk918;
    void* unk91C;
    void* unk920;
    void* unk924;
    void* unk928;
    void* unk92C;
    void* unk930;
    void* unk934;
    void* unk938;
    void* unk93C;
    void* unk940;
    void* unk944;
    void* unk948;
    void* unk94C;
    void* unk950;
    void* unk954;
    void* unk958;
    void* unk95C;
    void* unk960;
    void* unk964;
    void* unk968;
    void* unk96C;
    void* unk970;
    void* unk974;
    void* unk978;
    void* unk97C;
    void* unk980;
    void* unk984;
    void* unk988;
    void* unk98C;
    void* unk990;
    void* unk994;
    void* unk998;
    void* unk99C;
    void* unk9A0;
    void* unk9A4;
    void* unk9A8;
    void* unk9AC;
    void* unk9B0;
    void* unk9B4;
    void* unk9B8;
    void* unk9BC;
    void* unk9C0;
    void* unk9C4;
    void* unk9C8;
    void* unk9CC;
    void* unk9D0;
    void* unk9D4;
    void* unk9D8;
    void* unk9DC;
    void* unk9E0;
    void* unk9E4;
    void* unk9E8;
    void* unk9EC;
    void* unk9F0;
    void* unk9F4;
    void* unk9F8;
    void* unk9FC;
    void* unkA00;
    void* unkA04;
    void* unkA08;
    void* unkA0C;
    void* unkA10;
    void* unkA14;
    void* unkA18;
    void* unkA1C;
    void* unkA20;
    void* unkA24;
    void* unkA28;
    void* unkA2C;
    void* unkA30;
    void* unkA34;
    void* unkA38;
    void* unkA3C;
    void* unkA40;
    void* unkA44;
    void* unkA48;
    void* unkA4C;
    void* unkA50;
    void* unkA54;
    void* unkA58;
    void* unkA5C;
    void* unkA60;
    void* unkA64;
    void* unkA68;
    void* unkA6C;
    void* unkA70;
    void* unkA74;
    void* unkA78;
    void* unkA7C;
    void* unkA80;
    void* unkA84;
    void* unkA88;
    void* unkA8C;
    void* unkA90;
    void* unkA94;
    void* unkA98;
    void* unkA9C;
    void* unkAA0;
    void* unkAA4;
    void* unkAA8;
    void* unkAAC;
    void* unkAB0;
    void* unkAB4;
    void* unkAB8;
    void* unkABC;
    void* unkAC0;
    void* unkAC4;
    void* unkAC8;
    void* unkACC;
    void* unkAD0;
    void* unkAD4;
    void* unkAD8;
    void* unkADC;
    void* unkAE0;
    void* unkAE4;
    void* unkAE8;
    void* unkAEC;
    void* unkAF0;
    void* unkAF4;
    void* unkAF8;
    void* unkAFC;
    void* unkB00;
    void* unkB04;
    void* unkB08;
    void* unkB0C;
    void* unkB10;
    void* unkB14;
    void* unkB18;
    void* unkB1C;
    void* unkB20;
    void* unkB24;
    void* unkB28;
    void* unkB2C;
    void* unkB30;
    void* unkB34;
    void* unkB38;
    void* unkB3C;
    void* unkB40;
    void* unkB44;
    void* unkB48;
    void* unkB4C;
    void* unkB50;
    void* unkB54;
    void* unkB58;
    void* unkB5C;
    void* unkB60;
    void* unkB64;
    void* unkB68;
    void* unkB6C;
    void* unkB70;
    void* unkB74;
    void* unkB78;
    void* unkB7C;
    void* unkB80;
    void* unkB84;
    void* unkB88;
    void* unkB8C;
    void* unkB90;
    void* unkB94;
    void* unkB98;
    void* unkB9C;
    void* unkBA0;
    void* unkBA4;
    void* unkBA8;
    void* unkBAC;
    void* unkBB0;
    void* unkBB4;
    void* unkBB8;
    void* unkBBC;
    void* unkBC0;
    void* unkBC4;
    void* unkBC8;
    void* unkBCC;
    void* unkBD0;
    void* unkBD4;
    void* unkBD8;
    void* unkBDC;
    void* unkBE0;
    void* unkBE4;
    void* unkBE8;
    void* unkBEC;
    void* unkBF0;
    void* unkBF4;
    void* unkBF8;
    void* unkBFC;
    void* unkC00;
    void* unkC04;
    void* unkC08;
    void* unkC0C;
    void* unkC10;
    void* unkC14;
    void* unkC18;
    void* unkC1C;
    void* unkC20;
    void* unkC24;
    void* unkC28;
    void* unkC2C;
    void* unkC30;
    void* unkC34;
    void* unkC38;
    void* unkC3C;
    void* unkC40;
    void* unkC44;
    void* unkC48;
    void* unkC4C;
    void* unkC50;
    void* unkC54;
    void* unkC58;
    void* unkC5C;
    void* unkC60;
    void* unkC64;
    void* unkC68;
    void* unkC6C;
    void* unkC70;
    void* unkC74;
    void* unkC78;
    void* unkC7C;
    void* unkC80;
    void* unkC84;
    void* unkC88;
    void* unkC8C;
    void* unkC90;
    void* unkC94;
    void* unkC98;
    void* unkC9C;
    void* unkCA0;
    void* unkCA4;
    void* unkCA8;
    void* unkCAC;
    void* unkCB0;
    void* unkCB4;
    void* unkCB8;
    void* unkCBC;
    void* unkCC0;
    void* unkCC4;
    void* unkCC8;
    void* unkCCC;
    void* unkCD0;
    void* unkCD4;
    void* unkCD8;
    void* unkCDC;
    void* unkCE0;
    void* unkCE4;
    void* unkCE8;
    void* unkCEC;
    void* unkCF0;
    void* unkCF4;
    void* unkCF8;
    void* unkCFC;
    void* unkD00;
    void* unkD04;
    void* unkD08;
    void* unkD0C;
    void* unkD10;
    void* unkD14;
    void* unkD18;
    void* unkD1C;
    void* unkD20;
    void* unkD24;
    void* unkD28;
    void* unkD2C;
    void* unkD30;
    void* unkD34;
    void* unkD38;
    void* unkD3C;
    void* unkD40;
    void* unkD44;
    void* unkD48;
    void* unkD4C;
    void* unkD50;
    void* unkD54;
    void* unkD58;
    void* unkD5C;
    void* unkD60;
    void* unkD64;
    void* unkD68;
    void* unkD6C;
    void* unkD70;
    void* unkD74;
    void* unkD78;
    void* unkD7C;
    void* unkD80;
    void* unkD84;
    void* unkD88;
    void* unkD8C;
    void* unkD90;
    void* unkD94;
    void* unkD98;
    void* unkD9C;
    void* unkDA0;
    void* unkDA4;
    void* unkDA8;
    void* unkDAC;
    void* unkDB0;
    void* unkDB4;
    void* unkDB8;
    void* unkDBC;
    void* unkDC0;
    void* unkDC4;
    void* unkDC8;
    void* unkDCC;
    void* unkDD0;
    void* unkDD4;
    void* unkDD8;
    void* unkDDC;
    void* unkDE0;
    void* unkDE4;
    void* unkDE8;
    void* unkDEC;
    void* unkDF0;
    void* unkDF4;
    void* unkDF8;
    void* unkDFC;
    void* unkE00;
    void* unkE04;
    void* unkE08;
    void* unkE0C;
    void* unkE10;
    void* unkE14;
    void* unkE18;
    void* unkE1C;
    void* unkE20;
    void* unkE24;
    void* unkE28;
    void* unkE2C;
    void* unkE30;
    void* unkE34;
    void* unkE38;
    void* unkE3C;
    void* unkE40;
    void* unkE44;
    void* unkE48;
    void* unkE4C;
    void* unkE50;
    void* unkE54;
    void* unkE58;
    void* unkE5C;
    void* unkE60;
    void* unkE64;
    void* unkE68;
    void* unkE6C;
    void* unkE70;
    void* unkE74;
    void* unkE78;
    void* unkE7C;
    void* unkE80;
    void* unkE84;
    void* unkE88;
    void* unkE8C;
    void* unkE90;
    void* unkE94;
    void* unkE98;
    void* unkE9C;
    void* unkEA0;
    void* unkEA4;
    void* unkEA8;
    void* unkEAC;
    void* unkEB0;
    void* unkEB4;
    void* unkEB8;
    void* unkEBC;
    void* unkEC0;
    void* unkEC4;
    void* unkEC8;
    void* unkECC;
    void* unkED0;
    void* unkED4;
    void* unkED8;
    void* unkEDC;
    void* unkEE0;
    void* unkEE4;
    void* unkEE8;
    void* unkEEC;
    void* unkEF0;
    void* unkEF4;
    void* unkEF8;
    void* unkEFC;
    void* unkF00;
    void* unkF04;
    void* unkF08;
    void* unkF0C;
    void* unkF10;
    void* unkF14;
    void* unkF18;
    void* unkF1C;
    void* unkF20;
    void* unkF24;
    void* unkF28;
    void* unkF2C;
    void* unkF30;
    void* unkF34;
    void* unkF38;
    void* unkF3C;
    void* unkF40;
    void* unkF44;
    void* unkF48;
    void* unkF4C;
    void* unkF50;
    void* unkF54;
    void* unkF58;
    void* unkF5C;
    void* unkF60;
    void* unkF64;
    void* unkF68;
    void* unkF6C;
    void* unkF70;
    void* unkF74;
    void* unkF78;
    void* unkF7C;
    void* unkF80;
    void* unkF84;
    void* unkF88;
    void* unkF8C;
    void* unkF90;
    void* unkF94;
    void* unkF98;
    void* unkF9C;
    void* unkFA0;
    void* unkFA4;
    void* unkFA8;
    void* unkFAC;
    void* unkFB0;
    void* unkFB4;
    void* unkFB8;
    void* unkFBC;
    void* unkFC0;
    void* unkFC4;
    void* unkFC8;
    void* unkFCC;
    void* unkFD0;
    void* unkFD4;
    void* unkFD8;
    void* unkFDC;
    void* unkFE0;
    void* unkFE4;
    void* unkFE8;
    void* unkFEC;
    void* unkFF0;
    void* unkFF4;
    void* unkFF8;
    void* unkFFC;
    void* unk1000;
    void* unk1004;
    void* unk1008;
    void* unk100C;
    void* unk1010;
    void* unk1014;
    void* unk1018;
    void* unk101C;
    void* unk1020;
    void* unk1024;
    void* unk1028;
    void* unk102C;
    void* unk1030;
    void* unk1034;
    void* unk1038;
    void* unk103C;
    void* unk1040;
    void* unk1044;
    void* unk1048;
    void* unk104C;
    void* unk1050;
    void* unk1054;
    void* unk1058;
    void* unk105C;
    void* unk1060;
    void* unk1064;
    void* unk1068;
    void* unk106C;
    void* unk1070;
    void* unk1074;
    void* unk1078;
    void* unk107C;
    void* unk1080;
    void* unk1084;
    void* unk1088;
    void* unk108C;
    void* unk1090;
    void* unk1094;
    void* unk1098;
    void* unk109C;
    void* unk10A0;
    void* unk10A4;
    void* unk10A8;
    void* unk10AC;
    void* unk10B0;
    void* unk10B4;
    void* unk10B8;
    void* unk10BC;
    void* unk10C0;
    void* unk10C4;
    void* unk10C8;
    void* unk10CC;
    void* unk10D0;
    void* unk10D4;
    void* unk10D8;
    void* unk10DC;
    void* unk10E0;
    void* unk10E4;
    void* unk10E8;
    void* unk10EC;
    void* unk10F0;
    void* unk10F4;
    void* unk10F8;
    void* unk10FC;
    void* unk1100;
    void* unk1104;
    void* unk1108;
    void* unk110C;
    void* unk1110;
    void* unk1114;
    void* unk1118;
    void* unk111C;
    void* unk1120;
    void* unk1124;
    void* unk1128;
    void* unk112C;
    void* unk1130;
    void* unk1134;
    void* unk1138;
    void* unk113C;
    void* unk1140;
    void* unk1144;
    void* unk1148;
    void* unk114C;
    void* unk1150;
    void* unk1154;
    void* unk1158;
    void* unk115C;
    void* unk1160;
    void* unk1164;
    void* unk1168;
    void* unk116C;
    void* unk1170;
    void* unk1174;
    void* unk1178;
    void* unk117C;
    void* unk1180;
    void* unk1184;
    void* unk1188;
    void* unk118C;
    void* unk1190;
    void* unk1194;
    void* unk1198;
    void* unk119C;
    void* unk11A0;
    void* unk11A4;
    void* unk11A8;
    void* unk11AC;
    void* unk11B0;
    void* unk11B4;
    void* unk11B8;
    void* unk11BC;
    void* unk11C0;
    void* unk11C4;
    void* unk11C8;
    void* unk11CC;
    void* unk11D0;
    void* unk11D4;
    void* unk11D8;
    void* unk11DC;
    void* unk11E0;
    void* unk11E4;
    void* unk11E8;
    void* unk11EC;
    void* unk11F0;
    void* unk11F4;
    void* unk11F8;
    void* unk11FC;
    void* unk1200;
    void* unk1204;
    void* unk1208;
    void* unk120C;
    void* unk1210;
    void* unk1214;
    void* unk1218;
    void* unk121C;
    void* unk1220;
    void* unk1224;
    void* unk1228;
    void* unk122C;
    void* unk1230;
    void* unk1234;
    void* unk1238;
    void* unk123C;
    void* unk1240;
    void* unk1244;
    void* unk1248;
    void* unk124C;
    void* unk1250;
    void* unk1254;
    void* unk1258;
    void* unk125C;
    void* unk1260;
    void* unk1264;
    void* unk1268;
    void* unk126C;
    void* unk1270;
    void* unk1274;
    void* unk1278;
    void* unk127C;
    void* unk1280;
    void* unk1284;
    void* unk1288;
    void* unk128C;
    void* unk1290;
    void* unk1294;
    void* unk1298;
    void* unk129C;
    void* unk12A0;
    void* unk12A4;
    void* unk12A8;
    void* unk12AC;
    void* unk12B0;
    void* unk12B4;
    void* unk12B8;
    void* unk12BC;
    void* unk12C0;
    void* unk12C4;
    void* unk12C8;
    void* unk12CC;
    void* unk12D0;
    void* unk12D4;
    void* unk12D8;
    void* unk12DC;
    void* unk12E0;
    void* unk12E4;
    void* unk12E8;
    void* unk12EC;
    void* unk12F0;
    void* unk12F4;
    void* unk12F8;
    void* unk12FC;
    void* unk1300;
    void* unk1304;
    void* unk1308;
    void* unk130C;
    void* unk1310;
    void* unk1314;
    void* unk1318;
    void* unk131C;
    void* unk1320;
    void* unk1324;
    void* unk1328;
    void* unk132C;
    void* unk1330;
    void* unk1334;
    void* unk1338;
    void* unk133C;
    void* unk1340;
    void* unk1344;
    void* unk1348;
    void* unk134C;
    void* unk1350;
    void* unk1354;
    void* unk1358;
    void* unk135C;
    void* unk1360;
    void* unk1364;
    void* unk1368;
    void* unk136C;
    void* unk1370;
    void* unk1374;
    void* unk1378;
    void* unk137C;
    void* unk1380;
    void* unk1384;
    void* unk1388;
    void* unk138C;
    void* unk1390;
    void* unk1394;
    void* unk1398;
    void* unk139C;
    void* unk13A0;
    void* unk13A4;
    void* unk13A8;
    void* unk13AC;
    void* unk13B0;
    void* unk13B4;
    void* unk13B8;
    void* unk13BC;
    void* unk13C0;
    void* unk13C4;
    void* unk13C8;
    void* unk13CC;
    void* unk13D0;
    void* unk13D4;
    void* unk13D8;
    void* unk13DC;
    void* unk13E0;
    void* unk13E4;
    void* unk13E8;
    void* unk13EC;
    void* unk13F0;
    void* unk13F4;
    void* unk13F8;
    void* unk13FC;
    void* unk1400;
    void* unk1404;
    void* unk1408;
    void* unk140C;
    void* unk1410;
    void* unk1414;
    void* unk1418;
    void* unk141C;
    void* unk1420;
    void* unk1424;
    void* unk1428;
    void* unk142C;
    void* unk1430;
    void* unk1434;
    void* unk1438;
    void* unk143C;
    void* unk1440;
    void* unk1444;
    void* unk1448;
    void* unk144C;
    void* unk1450;
    void* unk1454;
    void* unk1458;
    void* unk145C;
    void* unk1460;
    void* unk1464;
    void* unk1468;
    void* unk146C;
    void* unk1470;
    void* unk1474;
    void* unk1478;
    void* unk147C;
    void* unk1480;
    void* unk1484;
    void* unk1488;
    void* unk148C;
    void* unk1490;
    void* unk1494;
    void* unk1498;
    void* unk149C;
    void* unk14A0;
    void* unk14A4;
    void* unk14A8;
    void* unk14AC;
    void* unk14B0;
    void* unk14B4;
    void* unk14B8;
    void* unk14BC;
    void* unk14C0;
    void* unk14C4;
    void* unk14C8;
    void* unk14CC;
    void* unk14D0;
    void* unk14D4;
    void* unk14D8;
    void* unk14DC;
    void* unk14E0;
    void* unk14E4;
    void* unk14E8;
    void* unk14EC;
    void* unk14F0;
    void* unk14F4;
    void* unk14F8;
    void* unk14FC;
    void* unk1500;
    void* unk1504;
    void* unk1508;
    void* unk150C;
    void* unk1510;
    void* unk1514;
    void* unk1518;
    void* unk151C;
    void* unk1520;
    void* unk1524;
    void* unk1528;
    void* unk152C;
    void* unk1530;
    void* unk1534;
    void* unk1538;
    void* unk153C;
    void* unk1540;
    void* unk1544;
    void* unk1548;
    void* unk154C;
    void* unk1550;
    void* unk1554;
    void* unk1558;
    void* unk155C;
    void* unk1560;
    void* unk1564;
    void* unk1568;
    void* unk156C;
    void* unk1570;
    void* unk1574;
    void* unk1578;
    void* unk157C;
    void* unk1580;
    void* unk1584;
    void* unk1588;
    void* unk158C;
    void* unk1590;
    void* unk1594;
    void* unk1598;
    void* unk159C;
    void* unk15A0;
    void* unk15A4;
    void* unk15A8;
    void* unk15AC;
    void* unk15B0;
    void* unk15B4;
    void* unk15B8;
    void* unk15BC;
    void* unk15C0;
    void* unk15C4;
    void* unk15C8;
    void* unk15CC;
    void* unk15D0;
    void* unk15D4;
    void* unk15D8;
    void* unk15DC;
    void* unk15E0;
    void* unk15E4;
    void* unk15E8;
    void* unk15EC;
    void* unk15F0;
    void* unk15F4;
    void* unk15F8;
    void* unk15FC;
    void* unk1600;
    void* unk1604;
    void* unk1608;
    void* unk160C;
    void* unk1610;
    void* unk1614;
    void* unk1618;
    void* unk161C;
    void* unk1620;
    void* unk1624;
    void* unk1628;
    void* unk162C;
    void* unk1630;
    void* unk1634;
    void* unk1638;
    void* unk163C;
    void* unk1640;
    void* unk1644;
    void* unk1648;
    void* unk164C;
    void* unk1650;
    void* unk1654;
    void* unk1658;
    void* unk165C;
    void* unk1660;
    void* unk1664;
    void* unk1668;
    void* unk166C;
    void* unk1670;
    void* unk1674;
    void* unk1678;
    void* unk167C;
    void* unk1680;
    void* unk1684;
    void* unk1688;
    void* unk168C;
    void* unk1690;
    void* unk1694;
    void* unk1698;
    void* unk169C;
    void* unk16A0;
    void* unk16A4;
    void* unk16A8;
    void* unk16AC;
    void* unk16B0;
    void* unk16B4;
    void* unk16B8;
    void* unk16BC;
    void* unk16C0;
    void* unk16C4;
    void* unk16C8;
    void* unk16CC;
    void* unk16D0;
    void* unk16D4;
    void* unk16D8;
    void* unk16DC;
    void* unk16E0;
    void* unk16E4;
    void* unk16E8;
    void* unk16EC;
    void* unk16F0;
    void* unk16F4;
    void* unk16F8;
    void* unk16FC;
    void* unk1700;
    void* unk1704;
    void* unk1708;
    void* unk170C;
    void* unk1710;
    void* unk1714;
    void* unk1718;
    void* unk171C;
    void* unk1720;
    void* unk1724;
    void* unk1728;
    void* unk172C;
    void* unk1730;
    void* unk1734;
    void* unk1738;
    void* unk173C;
    void* unk1740;
    void* unk1744;
    void* unk1748;
    void* unk174C;
    void* unk1750;
    void* unk1754;
    void* unk1758;
    void* unk175C;
    void* unk1760;
    void* unk1764;
    void* unk1768;
    void* unk176C;
    void* unk1770;
    void* unk1774;
    void* unk1778;
    void* unk177C;
    void* unk1780;
    void* unk1784;
    void* unk1788;
    void* unk178C;
    void* unk1790;
    void* unk1794;
    void* unk1798;
    void* unk179C;
    void* unk17A0;
    void* unk17A4;
    void* unk17A8;
    void* unk17AC;
    void* unk17B0;
    void* unk17B4;
    void* unk17B8;
    void* unk17BC;
    void* unk17C0;
    void* unk17C4;
    void* unk17C8;
    void* unk17CC;
    void* unk17D0;
    void* unk17D4;
    void* unk17D8;
    void* unk17DC;
    void* unk17E0;
    void* unk17E4;
    void* unk17E8;
    void* unk17EC;
    void* unk17F0;
    void* unk17F4;
    void* unk17F8;
    void* unk17FC;
    void* unk1800;
    void* unk1804;
    void* unk1808;
    void* unk180C;
    void* unk1810;
    void* unk1814;
    void* unk1818;
    void* unk181C;
    void* unk1820;
    void* unk1824;
    void* unk1828;
    void* unk182C;
    void* unk1830;
    void* unk1834;
    void* unk1838;
    void* unk183C;
    void* unk1840;
    void* unk1844;
    void* unk1848;
    void* unk184C;
    void* unk1850;
    void* unk1854;
    void* unk1858;
    void* unk185C;
    void* unk1860;
    void* unk1864;
    void* unk1868;
    void* unk186C;
    void* unk1870;
    void* unk1874;
    void* unk1878;
    void* unk187C;
    void* unk1880;
    void* unk1884;
    void* unk1888;
    void* unk188C;
    void* unk1890;
    void* unk1894;
    void* unk1898;
    void* unk189C;
    void* unk18A0;
    void* unk18A4;
    void* unk18A8;
    void* unk18AC;
    void* unk18B0;
    void* unk18B4;
    void* unk18B8;
    void* unk18BC;
    void* unk18C0;
    void* unk18C4;
    void* unk18C8;
    void* unk18CC;
    void* unk18D0;
    void* unk18D4;
    void* unk18D8;
    void* unk18DC;
    void* unk18E0;
    void* unk18E4;
    void* unk18E8;
    void* unk18EC;
    void* unk18F0;
    void* unk18F4;
    void* unk18F8;
    void* unk18FC;
    void* unk1900;
    void* unk1904;
    void* unk1908;
    void* unk190C;
    void* unk1910;
    void* unk1914;
    void* unk1918;
    void* unk191C;
    void* unk1920;
    void* unk1924;
    void* unk1928;
    void* unk192C;
    void* unk1930;
    void* unk1934;
    void* unk1938;
    void* unk193C;
    void* unk1940;
    void* unk1944;
    void* unk1948;
    void* unk194C;
    void* unk1950;
    void* unk1954;
    void* unk1958;
    void* unk195C;
    void* unk1960;
    void* unk1964;
    void* unk1968;
    void* unk196C;
    void* unk1970;
    void* unk1974;
    void* unk1978;
    void* unk197C;
    void* unk1980;
    void* unk1984;
    void* unk1988;
    void* unk198C;
    void* unk1990;
    void* unk1994;
    void* unk1998;
    void* unk199C;
    void* unk19A0;
    void* unk19A4;
    void* unk19A8;
    void* unk19AC;
    void* unk19B0;
    void* unk19B4;
    void* unk19B8;
    void* unk19BC;
    void* unk19C0;
    void* unk19C4;
    void* unk19C8;
    void* unk19CC;
    void* unk19D0;
    void* unk19D4;
    void* unk19D8;
    void* unk19DC;
    void* unk19E0;
    void* unk19E4;
    void* unk19E8;
    void* unk19EC;
    void* unk19F0;
    void* unk19F4;
    void* unk19F8;
    void* unk19FC;
    void* unk1A00;
    void* unk1A04;
    void* unk1A08;
    void* unk1A0C;
    void* unk1A10;
    void* unk1A14;
    void* unk1A18;
    void* unk1A1C;
    void* unk1A20;
    void* unk1A24;
    void* unk1A28;
    void* unk1A2C;
    void* unk1A30;
    void* unk1A34;
    void* unk1A38;
    void* unk1A3C;
    void* unk1A40;
    void* unk1A44;
    void* unk1A48;
    void* unk1A4C;
    void* unk1A50;
    void* unk1A54;
    void* unk1A58;
    void* unk1A5C;
    void* unk1A60;
    void* unk1A64;
    void* unk1A68;
    void* unk1A6C;
    void* unk1A70;
    void* unk1A74;
    void* unk1A78;
    void* unk1A7C;
    void* unk1A80;
    void* unk1A84;
    void* unk1A88;
    void* unk1A8C;
    void* unk1A90;
    void* unk1A94;
    void* unk1A98;
    void* unk1A9C;
    void* unk1AA0;
    void* unk1AA4;
    void* unk1AA8;
    void* unk1AAC;
    void* unk1AB0;
    void* unk1AB4;
    void* unk1AB8;
    void* unk1ABC;
    void* unk1AC0;
    void* unk1AC4;
    void* unk1AC8;
    void* unk1ACC;
    void* unk1AD0;
    void* unk1AD4;
    void* unk1AD8;
    void* unk1ADC;
    void* unk1AE0;
    void* unk1AE4;
    void* unk1AE8;
    void* unk1AEC;
    void* unk1AF0;
    void* unk1AF4;
    void* unk1AF8;
    void* unk1AFC;
    void* unk1B00;
    void* unk1B04;
    void* unk1B08;
    void* unk1B0C;
    void* unk1B10;
    void* unk1B14;
    void* unk1B18;
    void* unk1B1C;
    void* unk1B20;
    void* unk1B24;
    void* unk1B28;
    void* unk1B2C;
    void* unk1B30;
    void* unk1B34;
    void* unk1B38;
    void* unk1B3C;
    void* unk1B40;
    void* unk1B44;
    void* unk1B48;
    void* unk1B4C;
    void* unk1B50;
    void* unk1B54;
    void* unk1B58;
    void* unk1B5C;
    void* unk1B60;
    void* unk1B64;
    void* unk1B68;
    void* unk1B6C;
    void* unk1B70;
    void* unk1B74;
    void* unk1B78;
    void* unk1B7C;
    void* unk1B80;
    void* unk1B84;
    void* unk1B88;
    void* unk1B8C;
    void* unk1B90;
    void* unk1B94;
    void* unk1B98;
    void* unk1B9C;
    void* unk1BA0;
    void* unk1BA4;
    void* unk1BA8;
    void* unk1BAC;
    void* unk1BB0;
    void* unk1BB4;
    void* unk1BB8;
    void* unk1BBC;
    void* unk1BC0;
    void* unk1BC4;
    void* unk1BC8;
    void* unk1BCC;
    void* unk1BD0;
    void* unk1BD4;
    void* unk1BD8;
    void* unk1BDC;
    void* unk1BE0;
    void* unk1BE4;
    void* unk1BE8;
    void* unk1BEC;
    void* unk1BF0;
    void* unk1BF4;
    void* unk1BF8;
    void* unk1BFC;
    void* unk1C00;
    void* unk1C04;
    void* unk1C08;
    void* unk1C0C;
    void* unk1C10;
    void* unk1C14;
    void* unk1C18;
    void* unk1C1C;
    void* unk1C20;
    void* unk1C24;
    void* unk1C28;
    void* unk1C2C;
    void* unk1C30;
    void* unk1C34;
    void* unk1C38;
    void* unk1C3C;
    void* unk1C40;
    void* unk1C44;
    void* unk1C48;
    void* unk1C4C;
    void* unk1C50;
    void* unk1C54;
    void* unk1C58;
    void* unk1C5C;
    void* unk1C60;
    void* unk1C64;
    void* unk1C68;
    void* unk1C6C;
    void* unk1C70;
    void* unk1C74;
    void* unk1C78;
    void* unk1C7C;
    void* unk1C80;
    void* unk1C84;
    void* unk1C88;
    void* unk1C8C;
    void* unk1C90;
    void* unk1C94;
    void* unk1C98;
    void* unk1C9C;
    void* unk1CA0;
    void* unk1CA4;
    void* unk1CA8;
    void* unk1CAC;
    void* unk1CB0;
    void* unk1CB4;
    void* unk1CB8;
    void* unk1CBC;
    void* unk1CC0;
    void* unk1CC4;
    void* unk1CC8;
    void* unk1CCC;
    void* unk1CD0;
    void* unk1CD4;
    void* unk1CD8;
    void* unk1CDC;
    void* unk1CE0;
    void* unk1CE4;
    void* unk1CE8;
    void* unk1CEC;
    void* unk1CF0;
    void* unk1CF4;
    void* unk1CF8;
    void* unk1CFC;
    void* unk1D00;
    void* unk1D04;
    void* unk1D08;
    void* unk1D0C;
    void* unk1D10;
    void* unk1D14;
    void* unk1D18;
    void* unk1D1C;
    void* unk1D20;
    void* unk1D24;
    void* unk1D28;
    void* unk1D2C;
    void* unk1D30;
    void* unk1D34;
    void* unk1D38;
    void* unk1D3C;
    void* unk1D40;
    void* unk1D44;
    void* unk1D48;
    void* unk1D4C;
    void* unk1D50;
    void* unk1D54;
    void* unk1D58;
    void* unk1D5C;
    void* unk1D60;
    void* unk1D64;
    void* unk1D68;
    void* unk1D6C;
    void* unk1D70;
    void* unk1D74;
    void* unk1D78;
    void* unk1D7C;
    void* unk1D80;
    void* unk1D84;
    void* unk1D88;
    void* unk1D8C;
    void* unk1D90;
    void* unk1D94;
    void* unk1D98;
    void* unk1D9C;
    void* unk1DA0;
    void* unk1DA4;
    void* unk1DA8;
    void* unk1DAC;
    void* unk1DB0;
    void* unk1DB4;
    void* unk1DB8;
    void* unk1DBC;
    void* unk1DC0;
    void* unk1DC4;
    void* unk1DC8;
    void* unk1DCC;
    void* unk1DD0;
    void* unk1DD4;
    void* unk1DD8;
    void* unk1DDC;
    void* unk1DE0;
    void* unk1DE4;
    void* unk1DE8;
    void* unk1DEC;
    void* unk1DF0;
    void* unk1DF4;
    void* unk1DF8;
    void* unk1DFC;
    void* unk1E00;
    void* unk1E04;
    void* unk1E08;
    void* unk1E0C;
    void* unk1E10;
    void* unk1E14;
    void* unk1E18;
    void* unk1E1C;
    void* unk1E20;
    void* unk1E24;
    void* unk1E28;
    void* unk1E2C;
    void* unk1E30;
    void* unk1E34;
    void* unk1E38;
    void* unk1E3C;
    void* unk1E40;
    void* unk1E44;
    void* unk1E48;
    void* unk1E4C;
    void* unk1E50;
    void* unk1E54;
    void* unk1E58;
    void* unk1E5C;
    void* unk1E60;
    void* unk1E64;
    void* unk1E68;
    void* unk1E6C;
    void* unk1E70;
    void* unk1E74;
    void* unk1E78;
    void* unk1E7C;
    void* unk1E80;
    void* unk1E84;
    void* unk1E88;
    void* unk1E8C;
    void* unk1E90;
    void* unk1E94;
    void* unk1E98;
    void* unk1E9C;
    void* unk1EA0;
    void* unk1EA4;
    void* unk1EA8;
    void* unk1EAC;
    void* unk1EB0;
    void* unk1EB4;
    void* unk1EB8;
    void* unk1EBC;
    void* unk1EC0;
    void* unk1EC4;
    void* unk1EC8;
    void* unk1ECC;
    void* unk1ED0;
    void* unk1ED4;
    void* unk1ED8;
    void* unk1EDC;
    void* unk1EE0;
    void* unk1EE4;
    void* unk1EE8;
    void* unk1EEC;
    void* unk1EF0;
    void* unk1EF4;
    void* unk1EF8;
    void* unk1EFC;
    void* unk1F00;
    void* unk1F04;
    void* unk1F08;
    void* unk1F0C;
    void* unk1F10;
    void* unk1F14;
    void* unk1F18;
    void* unk1F1C;
    void* unk1F20;
    void* unk1F24;
    void* unk1F28;
    void* unk1F2C;
    void* unk1F30;
    void* unk1F34;
    void* unk1F38;
    void* unk1F3C;
    void* unk1F40;
    void* unk1F44;
    void* unk1F48;
    void* unk1F4C;
    void* unk1F50;
    void* unk1F54;
    void* unk1F58;
    void* unk1F5C;
    void* unk1F60;
    void* unk1F64;
    void* unk1F68;
    void* unk1F6C;
    void* unk1F70;
    void* unk1F74;
    void* unk1F78;
    void* unk1F7C;
    void* unk1F80;
    void* unk1F84;
    void* unk1F88;
    void* unk1F8C;
    void* unk1F90;
    void* unk1F94;
    void* unk1F98;
    void* unk1F9C;
    void* unk1FA0;
    void* unk1FA4;
    void* unk1FA8;
    void* unk1FAC;
    void* unk1FB0;
    void* unk1FB4;
    void* unk1FB8;
    void* unk1FBC;
    void* unk1FC0;
    void* unk1FC4;
    void* unk1FC8;
    void* unk1FCC;
    void* unk1FD0;
    void* unk1FD4;
    void* unk1FD8;
    void* unk1FDC;
    void* unk1FE0;
    void* unk1FE4;
    void* unk1FE8;
    void* unk1FEC;
    void* unk1FF0;
    void* unk1FF4;
    void* unk1FF8;
    void* unk1FFC;
    void* unk2000;
    void* unk2004;
    void* unk2008;
    void* unk200C;
    void* unk2010;
    void* unk2014;
    void* unk2018;
    void* unk201C;
    void* unk2020;
    void* unk2024;
    void* unk2028;
    void* unk202C;
    void* unk2030;
    void* unk2034;
    void* unk2038;
    void* unk203C;
    void* unk2040;
    void* unk2044;
    void* unk2048;
    void* unk204C;
    void* unk2050;
    void* unk2054;
    Input* input;
    Context context;
    void* BuildResultForInput(Input*, Goal*, Context*, bool);
    void* FUN_00994bd0(Input*, bool);
};
}  // namespace fnv_00994bd0
