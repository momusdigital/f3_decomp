// fallout_shared/tesobjectrefr.cpp: XActor, Owner, Thing, Ref and more (15 functions)
#include "tesobjectrefr_decls.h"

// @fnv 0x0057acc0
void FUN_0057acc0(unsigned int index)
{
    g_011ca304.RemoveAt(index);
}

struct Actor;
struct ActorCause;
struct ActorPackageData;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSPrimitive;
struct BGSSaveFormBuffer;
struct BGSTalkingActivator;
struct BSExtraData;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BSOcclusionPlane;
struct BSPortal;
struct SoundPlaybackHandle;
struct BaseExtraList;
struct BipedAnim;
struct CellMopp;
struct CollisionData;
struct Crime;
struct TeleportableReference;
struct ExtraAction;
struct ExtraActorCause;
struct ExtraAmmo;
struct ExtraAnim;
struct ExtraAshPileReference;
struct ExtraAudioBuoyMarker;
struct ExtraAudioMarker;
struct ExtraCannotWearData;
struct ExtraDataList;
struct ExtraDismemberedLimbs;
struct ExtraFactionChanges;
struct ExtraFollower;
struct ExtraFollowerSwimBreadcrumbs;
struct ExtraLeveledItem;
struct ExtraLight;
struct ExtraLock;
struct ExtraMapMarker;
struct ExtraNavMeshPortal;
struct ExtraRefractionProperty;
struct ExtraSayToTopicInfo;
struct ExtraSayTopicInfoOnceADay;
struct ExtraStartingPosition;
struct ExtraTalkingActor;
struct ExtraTeleport;
struct PositionRotation;
struct ImpactSwap;
struct InventoryChanges;
struct MapMarkerData;
struct MenuTopic;
struct Point3Offset;
struct NiNode;
struct NiPoint3;
struct NiRenderedTexture;
struct PatrolReferenceData;
struct PatrolRefData;
struct LinkedReferencePair;
struct RadioReferenceData;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceFloatEntry;
struct RagDollData;
struct PointerFlagNode;
struct TopicInfoVisitRecord;
struct Script;
struct ScriptLocals;
struct SeenData;
struct TESActorBase;
struct TESAmmo;
struct TESClimate;
struct TESCombatStyle;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESModel;
struct TESNPC;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESPackage;
struct TESRegionList;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TrespassPackage;
struct WorldLocation;
struct WaterZone;
struct _D3DLOCKED_RECT;
struct bhkWorld;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};

struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
};

struct FUN_00439f90_shell : public TESObjectREFR
{
    bool FUN_00439f90();
};

class TESObjectSTAT;
extern TESObjectSTAT* DAT_011ca230;
extern TESObjectSTAT* DAT_011ca238;
TESObjectSTAT* __fastcall _FNV_GetObjectReference(TESObjectREFR*);

namespace fnv_0043fcd0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_0043fcd0_shell : public TESObjectREFR
{
    NiAVObject* FUN_0043fcd0();
};

template <typename T> struct BSStringT
{
    operator const char*() const;
};

struct TLS_Pad_0043fcd0
{
    char pad[0x260];
    NiAVObject* val260;
    FUN_0043fcd0_shell* val264;
};

__declspec(thread) TLS_Pad_0043fcd0 g_tls_0043fcd0;

}  // namespace fnv_0043fcd0

struct AnimIdle;
struct Animation;
struct AttachDistant3DTask;
struct BSFile;
struct BSFileEntry;
struct BackgroundCloneThread;
struct BipedAnim;
struct EffectSetting;
struct KFModel;
struct LoadedFile;
struct MagicItem;
struct Model;
struct NiAVObject;
struct NiControllerSequence;
struct NiNode;
struct QueuedFile;
struct QueuedReference;
struct QueuedTexture;
struct TESAnimGroup;
struct TESBoundObject;
struct TESModel;
struct TESNPC;
struct TESObjectCELL;
struct TESObjectTREE;
struct FileEntryList;
struct FileEntryListCollection;
struct ModelLoadData;
struct ModelLoader
{
    void LoadModelFileList(BSFile*, bool);
    bool QueueModelFilePath(BSFileEntry*, int, QueuedFile*);
    bool QueueModelFilePath(char*, int, QueuedFile*);
    void ProcessModelRequest(char*, FileEntryList*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, void*, int, QueuedFile*, int, bool, bool, bool, float);
    void ProcessModelRequest(char*, FileEntryList*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, void*, int, QueuedFile*, int);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, int, QueuedFile*, int);
    bool EnqueueFile(char*, int, QueuedFile*);
    void QueueMagicEffectModel(MagicItem*, EffectSetting*, int);
    void QueueReference(TESObjectREFR*, int, bool);
    void QueueBoundObjectModel(TESBoundObject*, void*, int, QueuedFile*, TESObjectREFR*);
    void QueueBoundObjectModel(TESBoundObject*, int, QueuedFile*, TESObjectREFR*);
    void QueueTESModel(TESModel*, int, QueuedFile*, TESObjectREFR*);
    void QueueModelWithOptions(TESModel*, int, QueuedFile*, TESObjectREFR*, bool, bool);
    void QueueModelList(void*, FileEntryListCollection*, int, QueuedFile*, char*);
    void QueueFileList(void*, int, QueuedFile*, char*);
    void QueueReplacementKFList(void*, Animation*, int, QueuedFile*, char*);
    void QueueHead(TESNPC*, void*, int, QueuedFile*);
    void QueueBipedAnimation(BipedAnim*, void*, int, QueuedFile*, int);
    KFModel* FindIdleKFModel(char*, AnimIdle*, int, TESObjectREFR*);
    void QueueTreeBillboard(char*, ModelLoadData*);
    void QueueFileLoad(char*, int, QueuedFile*, int);
    void EnqueueModelFile(char*, int, QueuedFile*, int);
    void QueueModelFile(TESModel*, int, QueuedFile*, int);
    void QueueAlternateModel(TESModel*, int, QueuedFile*, int);
    bool QueueFileFromArchive(BSFileEntry*, int, QueuedFile*);
    void QueueModelLoad(char*, bool, unsigned int);
    void ReleaseKF(char*, bool);
    void CancelReplacementKFList(Animation*);
    void CancelAnimIdle(AnimIdle*);
    void CancelReferenceFiles(TESObjectREFR*);
    void CancelReferencesForCell(TESObjectCELL*);
    bool IsReferenceQueued(TESObjectREFR*);
    TESModel* GetModelForBoundObject(TESBoundObject*, TESObjectREFR*);
    bool BoundObjectOrModelAlreadyQueued(TESObjectREFR*, TESModel*, int, bool);
    void UpdateQueuedReferencePriorities(TESObjectCELL*);
    void PauseBackgroundCloning();
    void ResumeBackgroundCloning();
    void QueueDistant3DTask(AttachDistant3DTask*);
    bool IsBackgroundCloningPaused();
    bool UpdateReferencesToQueue();
    bool SetLoadTexturesDegraded(bool);
    bool GetLoadTexturesDegraded();
    void UpgradeTextures(NiAVObject*);
    bool AddLoadedFileToMap(char*, LoadedFile*);
    void RemoveLoadedFileFromMap(char*);
    LoadedFile* GetLoadedFileFromMap(char*);
    void DebugMessage(char*, ...);
    void DisplayBackgroundLoadDebugText(int, int*, int*, bool);
    void DisplayDebugLoadingText();
    static void UpdateQueueCallback();
    static bool UpdateSecondaryQueueCallback();
    static void LoadQueuedPriorityCallback(float);
    static unsigned int GetExternalCountCallback();
    static void PauseCallback();
    static void ResumeCallback();
    void SetExiting();
    void AddBackgroundCloneReference(QueuedReference*);
    void RemoveReferenceFromMap(TESObjectREFR*);
    void RemoveAnimIdleFromMap(AnimIdle*);
    void RemoveReplacementKFListFromMap(Animation*);
    void RemoveHelmetFromMap(TESObjectREFR*);
    bool RegisterQueuedTexture(BSFileEntry*, QueuedTexture*);
    void RemoveQueuedTextureFromMap(BSFileEntry*);
    QueuedTexture* GetQueuedTextureFromMap(BSFileEntry*);
    bool HasQueuedTextures();
    unsigned int GetBackgroundCloningCount();
    unsigned int GetQueuedReferenceCount();
    unsigned int GetQueuedHelmetCount();
    bool AddModel(char*, Model*);
    bool AddKF(char*, KFModel*);
    NiNode* LoadFile(char*, int, bool, bool, bool, bool);
    KFModel* LoadKF(char*);
    void LoadPSA(char*, void*);
    bool FindModel(char*, void*);
    void* UpdateLoadingStatusCallback(char*, char*, void*);
    void* BuildNIFFileList(char*);
    void* GetModelFileList(char*, bool, bool, int);
    void* FindNIFFileListEntry(void*, void*);
    bool ProcessQueuedFile(TESObjectCELL*);
    KFModel* FindKFModel(char*);
    KFModel* FindKFModel(NiControllerSequence*);
    KFModel* FindKFModel(TESAnimGroup*);
    void CancelAllFiles();
    void SetLoadingEnabled(bool);
    void ReleaseFile(char*);
    void ReleaseKFFile(char*);
    void UpdateReferenceNode(TESObjectREFR*, NiNode*);
    void UpdateModelNode(NiNode*);
    bool QHasDelayedFree();
    static int GetArchiveTypeIndexForIOFileIndex(int);
    static int GetIOFileIndexForArchiveTypeIndex(int);
    void AddModelToMap(Model*, char*);
    void* __vecDelDtor(unsigned int);
    void* m_pLoadedModelMap;
    void* m_pLoadedKFModelMap;
    void* m_pQueuedReferenceMap;
    void* m_pQueuedReferenceUpdateMap;
    void* m_pQueuedAnimIdleMap;
    void* m_pQueuedReplacementKFListMap;
    void* m_pQueuedHelmetMap;
    void* m_pDistant3DTaskQueue;
    void* m_pQueuedTextureMap;
    void* m_pLoadedFileMap;
    BackgroundCloneThread* m_pBackgroundCloneThread;
    bool m_bLoadTexturesDegraded;
    char _pad_2d[3];
};
typedef char _sizecheck_ModelLoader[sizeof(ModelLoader) == 48 ? 1 : -1];

struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct TESForm;
struct BGSLoadGameSubBuffer
{
    void SetBuffer(char*);
    void ResetReadPosition();
    void RestoreAnimation(TESForm*);
    void ReadAnimationState(TESForm*);
    void LoadHavokData(TESForm*);
    void SaveAnimation(TESForm*);
    void SaveFormState(TESForm*);
    void SaveGame(BGSSaveGameBuffer*);
    void LoadGame(BGSLoadGameBuffer*);
    BGSLoadFormBuffer* CreateFormBuffer(TESForm*);
    void RenderCopyData(BGSSaveFormBuffer*);
    char* pBuffer;
};
typedef char _sizecheck_BGSLoadGameSubBuffer[sizeof(BGSLoadGameSubBuffer) == 4 ? 1 : -1];

struct TESObjectCELL;
struct TESWorldSpace;
struct PlayerTargetLocation
{
    TESWorldSpace* pWorld;
    TESObjectCELL* m_pCell;
    char Location[12];
    char Angle[12];
    bool m_bHasTargetLocation;
    char _pad_21[3];
    int* m_pIntegerData;
    long m_lValue;
    TESObjectREFR* m_pFirstReference;
    TESObjectREFR* m_pSecondMapReference;
};
typedef char _sizecheck_PLAYER_TARGET_LOC[sizeof(PlayerTargetLocation) == 52 ? 1 : -1];

struct _NiPoint3_pod
{
    float x, y, z;
};

void __fastcall _ref_006815c0(void* pThis);
extern _NiPoint3_pod _NiPoint3_ZERO;

namespace fnv_004a3e00 {
struct NiStream;
struct blob1
{
    char b[1];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

float __cdecl FUN_004a3e90(float);

struct bhkCharacterController
{
    float& GetVectorElement(int);
};

}  // namespace fnv_004a3e00

struct Actor;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct ExtraDataList;
struct InventoryIterator;
struct InventoryStackRecord;
struct IndexedPointerCollection;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESForm;
struct TESLevItem;
struct TESObject;
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

TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);

struct ReferenceIntersectionData
{
    void Endian();
    TESObjectREFR* m_pHitReference;
    char Intersect[12];
    char Normal[12];
};
typedef char _sizecheck_REF_DECAL_DATA[sizeof(ReferenceIntersectionData) == 28 ? 1 : -1];

void __fastcall _ref_006815c0(void* pThis);

namespace fnv_0055d420 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSImpactDataSet;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct CellRecord;
struct DialogueResponse;
struct DetectionParameters;
struct ExteriorData;
struct EffectItem;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanFloatQuery;
struct IDebugText;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct InventoryStackRecord;
struct LoadedCellData;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SeenData;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESClimate;
struct TESCombatStyle;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESImageSpace;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct _D3DLOCKED_RECT;
struct bhkCharacterController;
struct BhkPickData;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct bhkWorld;
struct bhkWorldM;
struct hkpRigidBody;
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
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
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

struct TESForm
{
    bool IsTemporary() const;
    void SetAltered(bool);
};
}  // namespace fnv_0055d420

class TESForm;
struct TESFullName
{
    static char const* __cdecl GetFullName(TESForm*);
};
struct TESFile
{
    char const* GetName();
};

struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct TESActorBase;
struct TESFaction;
struct TESForm;
struct TESLevItem;
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESActorBaseData : public BaseFormComponent
{
    virtual void CopyFromTemplateForm(TESActorBase*);
    virtual bool GetVATSmeleeDisabled();
    virtual bool GetNoVATSranged();
    virtual bool GetCanBePickpocketed();
    virtual bool GetIsGhost();
    virtual bool GetIsInvulnerable();
    virtual bool GetNoKnockdowns();
    virtual bool GetCanBeAllRaces();
    virtual bool GetNoHeadTracking();
    virtual bool GetNoPersuasion();
    virtual bool GetNoLeftArm();
    virtual bool GetNoRightArm();
    virtual bool GetNoHead();
    virtual bool GetNoShadow();
    virtual bool GetNoBloodSpray();
    virtual void SetNoBloodSpray(bool);
    virtual bool GetNoBloodDecal();
    virtual void SetNoBloodDecal(bool);
    virtual int GetBloodImpactMaterial();
    virtual void SetBloodImpactMaterial(int);
    virtual unsigned short GetFatigue();
    virtual float GetHealthRegeneration();
    virtual BGSVoiceType* GetVoiceType();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    bool QCopiedTemplate();
    void SetCopiedTemplate(bool);
    void SetTemplateUseFlag(int, bool);
    bool GetTemplateUseFlag(int);
    TESForm* QTemplateForm();
    void SetTemplateForm(TESForm*);
    unsigned short QTemplateUseFlags();
    void SetTemplateUseFlags(unsigned short);
    bool GetUsesLeveledTemplate();
    bool IsTemplateLeveled();
    void SetTemplateReference(TESObjectREFR*);
    static TESActorBase* GetTemplateForActorBase(TESActorBase*, TESActorBase*);
    static bool HasCircularTemplateHierarchy(TESActorBase*);
    static bool IsActorBaseInTemplateHierarchy(TESActorBase*, TESActorBase*);
    static TESForm* GetLeveledTemplateInHierarchy(TESActorBase*, unsigned short*);
    int* GetFlags();
    void SetFlags(int);
    bool GetFlagBit(int);
    void UpdateFlagBit(int, bool, bool);
    bool IsEssentialActor();
    void SetEssential(bool);
    bool GetRespawn();
    void SetRespawn(bool);
    bool GetRunsInLow();
    void UpdateRunsInLow(bool, bool);
    bool GetKnockedDowns();
    void SetKnockedDowns(bool);
    bool GetNotPushable();
    void SetNotPushable(bool);
    bool GetNoRotatingToHeadtrack();
    void SetNoRotatingToHeadtrack(bool);
    bool GetMatchesPCLevel();
    void SetMatchesPCLevel(bool);
    bool GetSummonable();
    void SetSummonable(bool);
    bool GetNoRumors();
    void SetNoRumors(bool);
    void SetNoVATSMelee(bool);
    void SetAllowPCDialogue(bool);
    void SetAllowPickPocket(bool);
    void SetIsGhost(bool);
    void SetInvulnerable(bool);
    void SetCantOpenDoors(bool);
    void SetCanBeAllRaces(bool);
    void SetAutoCalcServiceFlags(bool);
    unsigned short GetLevelExact();
    unsigned short GetLevel();
    void SetLevel(unsigned short);
    unsigned short GetCalcLevelMin();
    void SetCalcLevelMin(unsigned short);
    unsigned short GetCalcLevelMax();
    void SetCalcLevelMax(unsigned short);
    unsigned short GetBaseDisposition();
    void SetBaseDisposition(unsigned short);
    TESLevItem* GetDeathItem();
    void SetDeathItem(TESLevItem*);
    void SetFatigue(unsigned short);
    static int ConvertToInteger(float);
    static char* GetActorDisplayName(Actor*);
    void SetKarmaValue(float);
    void ModKarma(float);
    unsigned short GetBarterGold();
    void SetBarterGold(unsigned short);
    int GetFactionReaction(TESActorBase*, int*);
    int GetFactionRank(TESFaction*, bool);
    void SetFactionRank(TESFaction*, char);
    void ModFactionRank(TESFaction*, char, bool);
    bool GetGhostFlag();
    bool CanBeDetected();
    void* GetFactionList();
    unsigned short GetSpeedMult();
    void SetSpeedMult(unsigned short);
    void SetVoiceType(BGSVoiceType*);
    void AddFormChange(int);
    void RemoveFormChange(int);
    void AddFormChangeFlags(int);
    void ClearChangeFlags(int);
    int GetChangeFlags();
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void SetPCFactionFlags(int);
    bool HasFaction(TESFaction*);
    void RemoveAllFactions();
    void CopyFactionList(TESActorBaseData*);
    void* __vecDelDtor(unsigned int);
    char actorData[24];
    TESLevItem* m_pBaseTemplateForm;
    BGSVoiceType* m_kFactionList;
    TESForm* m_ppTemplateForms;
    int m_pDeathItem;
    char m_pVoiceType[8];
};
typedef char _sizecheck_TESActorBaseData[sizeof(TESActorBaseData) == 52 ? 1 : -1];

struct hkBool
{
    char m_cBooleanValue;
};
typedef char _sizecheck_hkBool[sizeof(hkBool) == 1 ? 1 : -1];
struct FUN_005609f0_shell : public hkBool
{
    bool FUN_005609f0();
};

namespace fnv_00560d80 {
struct PhysicsSimulationContext;
struct hkStatisticsCollector;
struct hkTransform;
struct hkVector4;
struct hkpEntity;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob8
{
    char b[8];
};

const hkVector4& __cdecl FUN_00458b20(void);

}  // namespace fnv_00560d80

template <class T> class BSSimpleList;
class BGSRagdoll;

class TESDataHandler
{
  public:
    BSSimpleList<BGSRagdoll*>* GetBGSRagdollList();
};

class bhkCharacterController
{
  public:
    float& GetVectorElement(int);
};
class Twin_0084d030
{
  public:
    float GetStoredFloatValue(void);
};
class RegionPoint
{
  public:
    float GetX(void);
};

struct TESBoundObjectX;
struct ScriptLocalsX
{
    TESBoundObjectX* GetLocalData();
};
struct ScriptX
{
    void GetLocalData();
};
struct S
{
    void FUN_00561690(int a);
};

struct Actor;
struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESForm;
struct TESObjectCELL;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadGame
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void LoadForm(TESForm*);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    void DeleteForm(TESForm*);
    void ChangeFormID(unsigned int, unsigned int);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    SaveLoadChangeHistory* GetHistory();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool SetThreadAllowChanges(bool);
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    bool GetAllowChanges();
    void SaveGame(SaveLoadFile*);
    bool LoadGame(SaveLoadFile*, bool);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};
typedef char _sizecheck_BGSSaveLoadGame[sizeof(BGSSaveLoadGame) == 588 ? 1 : -1];
struct FUN_005621d0_shell : public BGSSaveLoadGame
{
    bool FUN_005621d0();
};

namespace fnv_00562d00 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];

}  // namespace fnv_00562d00

namespace fnv_005636e0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

class NiNode;
class ExtraDataList;
class NiRTTI;

class Model
{
  public:
    NiNode* GetObject3D();
};

class BGSOpenCloseForm
{
  public:
    static bool __cdecl HasOpenCloseComponent(TESForm*);
};

class TaskQueueInterface
{
  public:
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

extern NiRTTI DAT_011f36ac;
extern float DAT_0102f510;

void* __cdecl DynamicCastByRTTI(void*, NiNode*);
template <typename T> unsigned int __cdecl BSStringLength(const T*);
int __cdecl _stricmp(const char*, const char*);

}  // namespace fnv_005636e0

namespace fnv_00564930 {

struct TESForm
{
    bool IsTemporary() const;
    void MarkForDeletion(bool);
    unsigned int _ref_0084e3a0();
};
struct TESDataHandler
{
    bool FUN_004226e0();
    bool FormIDExists(unsigned int);
};
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
    void HasFormChanges(TESForm*);
};
extern TESDataHandler* g_dataHandler;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
}  // namespace fnv_00564930

void* __fastcall _FNV_GetObjectReference(void* _this);
unsigned int __fastcall _FNV_GetFormType(void* _this);

unsigned int __fastcall FUN_0044ddc0(void*);

struct BSExtraData;
struct TESForm;

struct TESObjectREFR_Helper
{
    BSExtraData* GetExtraData(unsigned char) const;
};

unsigned int __fastcall _ref_0084e3a0(BSExtraData*);

class BSExtraData;
unsigned int __fastcall _ref_0084e3a0(BSExtraData* pExtra);

class BSExtraData;
unsigned int __fastcall _ref_0084e3a0(BSExtraData* pExtra);

struct FUN_00565090_shell : public TESObjectREFR
{
    BSExtraData* GetExtraData(unsigned char) const;
    bool FUN_00565090();
};

struct TESObjectREFR_Flags : public TESObjectREFR
{
    unsigned int GetFlags();
    void SetFlags(unsigned int);
};

namespace fnv_005653d0 {
struct BSFile;
struct FormRecordHeader;
struct TESFileGroup;
struct TESBitArrayFile;
struct TESForm;
struct TESObjectCELL;
struct _FILETIME;
struct _SYSTEMTIME;
struct _WIN32_FIND_DATAA;
struct TESFile
{
    bool CreateTES(char*, char*, int);
    bool CreateTES(int);
    bool OpenTESFile(char*, char*, int, bool);
    bool OpenTESFile(int, bool);
    bool CloseTESFile();
    bool DeleteTES();
    bool IsOpen();
    bool QDLC();
    void SetDLC(bool);
    int ReadTESInfo();
    int SaveTESInfo();
    int RewriteFormHeader();
    TESForm* BuildTESInfoForm();
    int GetFormCount();
    void ModFormCount(int);
    void SetFormCount(int);
    int GetFileLanguage();
    void SetFileLanguage(int);
    float GetFileVersion();
    void SetFileVersion(float);
    bool IsValidFileVersion();
    unsigned int GetFORMSize();
    char* GetPath();
    char* GetFilename();
    unsigned int GetFileSize();
    _WIN32_FIND_DATAA* GetFileData();
    void GetCreateTime(_SYSTEMTIME*);
    void GetLastWriteTime(_FILETIME*);
    void GetLastWriteTime(_SYSTEMTIME*);
    void* GetCreator();
    void* GetSummary();
    bool MastersChecked(void*);
    bool CheckMasterFiles(void*, bool);
    TESFile* GetMasterFile(unsigned int);
    char* GetMasterFileName(unsigned int);
    unsigned int GetMasterFileCount();
    unsigned int GetFileIndex(TESFile*);
    void ClearMasters();
    void AddMaster(char*);
    bool AddMasters(void*);
    void RemoveMaster(unsigned int);
    bool DependsOnMaster(char*);
    bool MastersChanged();
    bool CheckLODPlugins();
    void* GetMasterList();
    unsigned char GetFileCompileIndex();
    void SetCompileIndex(unsigned char);
    void AddToDataHandler();
    bool CurrentGroupMayContainForm(TESForm*);
    void GetAnimationSequence(FormRecordHeader*);
    void ClearGroupStack();
    void OpenGroup(FormRecordHeader*);
    void CloseGroup();
    bool IsFormInCurrentGroup(TESForm*);
    bool IsGroupOpen();
    void SetCurrentForm(TESForm*);
    void ResetCurrentForm();
    TESFileGroup* GetCurrentGroup();
    void* GetGroupList();
    void SetGroupMode(bool);
    void TESRewindChunk();
    bool NextForm(bool);
    bool HasNextForm();
    void RewindForm();
    int GetTESForm();
    unsigned int GetOffset();
    unsigned int GetOffsetChunk();
    bool SetOffset(unsigned int);
    bool SetOffsetChunk(unsigned int);
    int GetFormAtOffset(unsigned int);
    unsigned int CopyCurrentFormToBuffer(void*, unsigned int);
    int ReadCurrentForm();
    bool NextChunk();
    unsigned int GetChunkSize();
    bool GetChunkData(unsigned short*);
    bool GetChunkData(short*);
    bool GetChunkData(float*);
    bool GetChunkData(unsigned int*);
    bool GetChunkData(int*);
    bool GetChunkData(void*, unsigned int);
    void ClearCurrentChunk();
    bool HasMaster(char*);
    int WriteForm(TESForm*);
    int WriteFormContents(TESForm*);
    void LoadForm(TESForm*);
    int WriteChunkData(int, void*, unsigned int);
    unsigned int GetCurrentReadPosition();
    bool ForceSaveFormHeader(FormRecordHeader*, unsigned int);
    void SetMasterFile(bool);
    bool IsMasterFile();
    void SetOptimizedFile(bool);
    bool GetOptimizedFile();
    void SetChecked(bool);
    bool GetIsChecked();
    void SetAltered(bool);
    bool GetAltered();
    void SetActive(bool);
    bool GetActive();
    void SetLittleEndian(bool);
    bool GetLittleEndian();
    bool QEndian();
    void SetUnicode(bool);
    bool GetUnicode();
    bool GetHasGroups();
    void SetHasGroups(bool);
    float GetPercentage();
    void CopyToBackup();
    static void DeleteFileList(void*);
    TESFile* GetParentTESFile();
    TESFile* GetThreadSafeRootFile();
    void CopyThreadSafeParentAuxBuffer();
    void ClearAuxBuffer();
    void SetFile(BSFile*);
    BSFile* GetFile();
    int GetLastFileError();
    FormRecordHeader* GetFormData();
    unsigned int GetID();
    unsigned short GetFormVersion();
    bool TakeOwnership();
    static bool TakeFileOwnership(char*);
    static unsigned short GetFileFormVersion();
    void SetCached(bool);
    void SetCaching(bool);
    void ResetWithCachedFile();
    bool GetCached();
    bool GetCaching();
    unsigned int GetMasterCount();
    unsigned int GetFlags();
    unsigned int GetFNVVersionInfo();
    void InitEndian();
    bool IsCurrentFormCompressed();
    unsigned int GetDecompressedBufferSize();
    char* GetDecompressedBuffer();
    void ReleaseDecompressedBuffer();
    void ClearDecompressedBuffer();
    bool ReadFormHeader();
    bool ReadChunkHeader();
    void* GetMasterDataList();
    void ClearMasterLists();
    void ClearThreadSafeFiles();
    void SetThreadSafeParent(TESFile*);
    TESFile* GetFileForThread(unsigned int);
    int ReadFileBuffer(void*, unsigned int);
    void MoveToFilePosition(int);
    bool IsTempIDLoadable(unsigned int, unsigned int);
    void SetTempIDOwner(bool);
    bool GetTempIDOwner();
    static void SetTempIDOwnerForForm(unsigned int, TESFile*);
    static bool GetTempIDCanLoadFromFile(unsigned int, TESFile*);
    static TESFile* GetTempIDOwnerFile(unsigned int);
    void ClearTempIDOwner();
    void* __vecDelDtor(unsigned int);
    int m_eReturnCode;
    TESFile* m_pThreadSafeParent;
    void* m_pThreadSafeFileMap;
    BSFile* m_pSecondaryFile;
    BSFile* m_pFile;
    TESBitArrayFile* m_pBitArrayFile1;
    TESBitArrayFile* m_pBitArrayFile2;
    TESBitArrayFile* m_pBitArrayFile3;
    char m_acFilename[260];
    char m_acPath[260];
    char* m_pBuffer;
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiReadPosition;
    unsigned int m_uiBufferSize;
    TESObjectCELL* m_pCurrentCell;
    unsigned int m_uiFormCount;
    char m_kRecordInfo[24];
    int m_eChunkID;
    unsigned int m_uiChunkSize;
    unsigned int m_uiChunkOffset;
    unsigned int m_uiRecordSize;
    unsigned int m_uiRecordOffset;
    unsigned int m_uiCurrentOffset;
    char m_kChunkInfo[24];
    unsigned int m_uiChunkValue1;
    unsigned int m_uiChunkValue2;
    char m_kRecordList[8];
    bool m_bIsLoading;
    bool m_bIsSaving;
    bool m_bHasCurrentGroup;
    char _pad_29b[1];
    char m_kFindData[320];
    char m_kFileMetadata[12];
    unsigned int m_uiFileCount;
    char m_kFilenameList[8];
    char m_kFileSizeList[8];
    unsigned int m_uiTESFileCount;
    TESFile** m_ppTESFiles;
    char m_kLastWriteTime[8];
    unsigned char m_ucCompileIndex;
    char _pad_40d[3];
    char m_kCreator[8];
    char m_kSummary[8];
    char* m_pDecompressedFormBuffer;
    unsigned int m_uiAuxBufferSize;
    bool m_bIsMaster;
    bool m_bOptimizedFile;
    bool m_bIsDLC;
    char _pad_42b[1];
};
typedef char _sizecheck_TESFile[sizeof(TESFile) == 1068 ? 1 : -1];

struct TESDataHandler
{
    bool FUN_004516b0();
    bool FUN_004226e0();
};
extern TESDataHandler* g_dataHandler;

struct TESSaveLoadGame
{
    bool GetLoading();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

}  // namespace fnv_005653d0

unsigned int __fastcall FUN_0044ddc0(TESObjectREFR* pThis);

struct ScriptLocals;

class ExtraDataList
{
  public:
    ScriptLocals* GetScriptLocalData();
};

namespace fnv_00567770 {
struct TESForm;

class ExtraDataList
{
  public:
    TESForm* GetOwner();
};

ExtraDataList* __fastcall FUN_005d43c0(TESObjectREFR*);

}  // namespace fnv_00567770

namespace fnv_00567960 {
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct CHUNK;
struct TeleportableReference;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob8
{
    char b[8];
};
struct blob16
{
    char b[16];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

class ExtraDataList;

const ExtraDataList* __fastcall FUN_005d43c0(const TESObjectREFR* pThis);
TeleportableReference* __fastcall FUN_00568e50(TESObjectREFR* pThis);
const TESObjectREFR* __fastcall FUN_00559450(TeleportableReference* pThis);
TESObjectCELL* __fastcall FUN_008d6f30(TESObjectREFR* pThis);

}  // namespace fnv_00567960

namespace fnv_00567dd0 {
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESObjectCELL;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

struct ExtraDataList
{
    void FUN_00421c60();
};
}  // namespace fnv_00567dd0

namespace fnv_00567ec0 {
struct BGSEncounterZone
{
    char pad[0x2c];
    unsigned short iCalcedLevel;
    unsigned short GetCalculatedLevel(void);
};

}  // namespace fnv_00567ec0

void* __fastcall _FNV_GetObjectReference(const void* self);
int __fastcall _FNV_GetFormType(const void* self);

struct NiStream;
struct FurnitureMark
{
    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
    char Position[12];
    unsigned short m_usMarkerId;
    unsigned char m_ucFlags;
    char _pad_f[1];
};
typedef char _sizecheck_FurnitureMark[sizeof(FurnitureMark) == 16 ? 1 : -1];
struct FUN_00568650_shell : public FurnitureMark
{
    float FUN_00568650();
};

namespace fnv_00568ab0 {
struct NiStream;
struct FurnitureMark
{
    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
    char Position[12];
    unsigned short m_usMarkerId;
    unsigned char m_ucFlags;
    char _pad_f[1];
};
typedef char _sizecheck_FurnitureMark[sizeof(FurnitureMark) == 16 ? 1 : -1];

}  // namespace fnv_00568ab0

namespace fnv_00568bb0 {
struct Actor;
struct ActorCause;
struct ActorPackageData;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSPrimitive;
struct BGSSaveFormBuffer;
struct BGSTalkingActivator;
struct BSExtraData;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BSOcclusionPlane;
struct BSPortal;
struct SoundPlaybackHandle;
struct BaseExtraList;
struct BipedAnim;
struct CellMopp;
struct CollisionData;
struct Crime;
struct TeleportableReference;
struct ExtraAction;
struct ExtraActorCause;
struct ExtraAmmo;
struct ExtraAnim;
struct ExtraAshPileReference;
struct ExtraAudioBuoyMarker;
struct ExtraAudioMarker;
struct ExtraCannotWearData;
struct ExtraDataList;
struct ExtraDismemberedLimbs;
struct ExtraFactionChanges;
struct ExtraFollower;
struct ExtraFollowerSwimBreadcrumbs;
struct ExtraLeveledItem;
struct ExtraLight;
struct ExtraLock;
struct ExtraMapMarker;
struct ExtraNavMeshPortal;
struct ExtraRefractionProperty;
struct ExtraSayToTopicInfo;
struct ExtraSayTopicInfoOnceADay;
struct ExtraStartingPosition;
struct ExtraTalkingActor;
struct ExtraTeleport;
struct PositionRotation;
struct ImpactSwap;
struct InventoryChanges;
struct MapMarkerData;
struct MenuTopic;
struct Point3Offset;
struct NiNode;
struct NiPoint3;
struct NiRenderedTexture;
struct PatrolReferenceData;
struct PatrolRefData;
struct LinkedReferencePair;
struct RadioReferenceData;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceFloatEntry;
struct RagDollData;
struct PointerFlagNode;
struct TopicInfoVisitRecord;
struct Script;
struct ScriptLocals;
struct SeenData;
struct TESActorBase;
struct TESAmmo;
struct TESClimate;
struct TESCombatStyle;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESModel;
struct TESNPC;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESPackage;
struct TESRegionList;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TrespassPackage;
struct WorldLocation;
struct WaterZone;
struct _D3DLOCKED_RECT;
struct bhkWorld;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};

void __fastcall FUN_00411ec0(const ExtraDataList*, int, ExtraDataList*);

struct ExtraDataList_helper
{
    void FUN_00411ec0(ExtraDataList*) const;
};

struct TESObjectREFR_helper
{
    ExtraDataList_helper* GetExtra() const;
};

}  // namespace fnv_00568bb0

struct MapMarkerData;

class ExtraDataList;
ExtraDataList* __fastcall FUN_005d43c0(TESObjectREFR*);

struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct TESFile;
struct TESForm;
struct TESKey;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob16
{
    char b[16];
};
struct LockExtraData
{
    int GetLockLevel(TESObjectREFR*);
    void SetLockLevel(int);
    int GetLevel(TESObjectREFR*);
    bool IsLocked();
    void SetLocked(bool);
    bool MeetsMinimumLockLevel();
    static int ConvertLockLevel(int);
    static int EnumToNumericValue(int);
    void Endian();
    unsigned char m_uiLockState;
    char _pad_1[3];
    TESKey* pKey;
    char cFlags;
    char _pad_9[3];
    unsigned int m_uiLockDifficulty;
    unsigned int m_uiLockValue;
};
typedef char _sizecheck_REFR_LOCK[sizeof(LockExtraData) == 20 ? 1 : -1];
struct TeleportableReference
{
    TESObjectREFR* GetLinkedDoor();
    void* GetTeleportPosition();
    void* GetTeleportRotation();
    TESObjectCELL* GetTeleportCell();
    void GetTeleportCellMapName(void*);
    TESWorldSpace* GetTeleportWorldspace();
    struct blob16 GetTeleportDestinationPosition();
    TESForm* GetTeleportDestinationForm();
    bool GetNoAlarm();
    void SetNoAlarm(bool);
    void SetLinkedDoor(TESObjectREFR*);
    void SetTeleportPosition(void*);
    void SetTeleportRotation(void*);
    void SetLinkedDoorReference(TESObjectREFR*, bool);
    void Save();
    void Load(TESFile*);
    bool InitItem(TESForm*);
    void Copy(TeleportableReference*);
    bool Compare(TeleportableReference*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadGameBuffer*);
    void InitLoadGame();
    void FinishLoadGameTES();
    void* __vecDelDtor(unsigned int);
    TESObjectREFR* m_pLinkedDoorReference;
    char position[12];
    char rotation[12];
    unsigned char cFlags;
    char _pad_1d[3];
};
typedef char _sizecheck_DoorTeleportData[sizeof(TeleportableReference) == 32 ? 1 : -1];

template <typename T> struct BSStringT
{
    operator const char*() const;
};

struct ExtraRadioData;
struct TESObjectREFR_ext
{
    LockExtraData* GetMyLock();
    ExtraRadioData* GetExtraRadioData();
};

namespace fnv_005691f0 {
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct BSExtraData;
struct TeleportableReference;
struct ExtraLock;
struct LockExtraData;
struct TESFile;
struct TESForm;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob16
{
    char b[16];
};

template <class T> class BSStringT
{
  public:
    operator char const*() const;
};

struct ExtraRadioData;

struct TESObjectREFR_Helper
{
    BSExtraData* GetExtraData(unsigned char) const;
    ExtraRadioData* GetExtraRadioData();
};

}  // namespace fnv_005691f0

struct BSExtraData;
struct LockExtraData;

class ExtraLock
{
  public:
    void Lock();
};

ExtraLock* __fastcall FUN_005691f0(void*);
void __fastcall FUN_005789b0(void*);

namespace fnv_005692a0 {
struct BSExtraData;
struct LockExtraData;

class ExtraLock
{
  public:
    void Unlock();
};

ExtraLock* __fastcall FUN_005691f0(TESObjectREFR* pThis);
void __fastcall FUN_005789b0(TESObjectREFR* pThis);

}  // namespace fnv_005692a0

class ExtraDataList;
const ExtraDataList* __fastcall FUN_005d43c0(const TESObjectREFR*);

namespace fnv_0056a250 {

struct ExtraDataList
{
    float FUN_0041f020();
};
struct REFRExtraStandIn
{
    ExtraDataList* GetExtra() const;
};
}  // namespace fnv_0056a250

struct TESForm;
struct TESWorldSpace;
struct WorldLocation
{
    void Endian();
    TESForm* m_pWorldSpace;
    char m_kWorldPosition[12];
    float m_fRotation;
};
typedef char _sizecheck_WORLD_LOCATION[sizeof(WorldLocation) == 20 ? 1 : -1];

class ExtraDataList;

WorldLocation* __fastcall FUN_00418b70(const ExtraDataList* pExtra);
int __fastcall _FNV_GetFormType(TESForm* pForm);

namespace fnv_0056b0b0 {

class TESDataHandler
{
  public:
    bool FormIDExists(unsigned int);
};
class ExtraDataList;
extern TESDataHandler* g_dataHandler;

struct DummyForm56b0b0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~DummyForm56b0b0();
};

unsigned int __fastcall _ref_0084e3a0(DummyForm56b0b0*);
DummyForm56b0b0* __fastcall FUN_004216f0(const ExtraDataList*);

struct TESObjectREFR_GetExtra_Caller
{
    const ExtraDataList* GetExtra() const;
};

}  // namespace fnv_0056b0b0

struct RadioReferenceData
{
    void Copy(RadioReferenceData*);
    void Endian();
    float fRadius;
    int m_iIntegerValue;
    float m_fValueBeforeRadioReference;
    TESObjectREFR* m_pRadioReference;
};
typedef char _sizecheck_RADIO_DATA[sizeof(RadioReferenceData) == 16 ? 1 : -1];

class ExtraDataList;
RadioReferenceData* __fastcall FUN_004182e0(const ExtraDataList* pExtra);

namespace fnv_0056b190 {
struct RadioReferenceData
{
    void Copy(RadioReferenceData*);
    void Endian();
    float fRadius;
    int m_iIntegerValue;
    float m_fValueBeforeRadioReference;
    TESObjectREFR* m_pRadioReference;
};
typedef char _sizecheck_RADIO_DATA[sizeof(RadioReferenceData) == 16 ? 1 : -1];

class ExtraDataList;

struct TESObjectREFR_GetExtra_Caller
{
    const ExtraDataList* GetExtra() const;
};

RadioReferenceData* __fastcall FUN_004182e0(const ExtraDataList* pExtra);

}  // namespace fnv_0056b190

namespace fnv_0056b210 {
struct RadioReferenceData
{
    void Copy(RadioReferenceData*);
    void Endian();
    float fRadius;
    int m_iIntegerValue;
    float m_fValueBeforeRadioReference;
    TESObjectREFR* m_pRadioReference;
};
typedef char _sizecheck_RADIO_DATA[sizeof(RadioReferenceData) == 16 ? 1 : -1];

class ExtraDataList;
extern "C++"
{
    RadioReferenceData* __fastcall FUN_004182e0(const ExtraDataList*);
}

}  // namespace fnv_0056b210

struct NiMemObject
{
    static void operator delete(void*, unsigned int);
};

struct hkTransform;
struct HavokTransformData
{
    void setIdentity();
    hkTransform* ToHK(hkTransform*);
    HavokTransformData* FromHK(void*);
    char Rot[48];
    char Trans[16];
};
typedef char _sizecheck_bhkTransform[sizeof(HavokTransformData) == 64 ? 1 : -1];

void __fastcall FUN_004b4fc0(void*);

struct CFilter;
struct hkSerializableCinfo
{
    char _pad_0[1];
};
typedef char _sizecheck_hkSerializableCinfo[sizeof(hkSerializableCinfo) == 1 ? 1 : -1];
struct CollisionFilterConfiguration : public hkSerializableCinfo
{
    CFilter* GetCFilter();
    void* __vecDelDtor(unsigned int);
    char _pad_1[3];
    void* m_pCollisionShape;
    char m_cBroadPhaseType[1];
    char _pad_9[3];
    char m_kProperties[12];
};
typedef char _sizecheck_hkWorldObjectCinfo[sizeof(CollisionFilterConfiguration) == 24 ? 1 : -1];
struct PhantomCreationInfo : public CollisionFilterConfiguration
{
    void* __vecDelDtor(unsigned int);
};
typedef char _sizecheck_hkPhantomCinfo[sizeof(PhantomCreationInfo) == 24 ? 1 : -1];
struct ExtendedPhantomCreationInfo : public PhantomCreationInfo
{
    void* __vecDelDtor(unsigned int);
    char _pad_18[8];
    char m_kMotionTransform[64];
};
typedef char _sizecheck_hkShapePhantomCinfo[sizeof(ExtendedPhantomCreationInfo) == 96 ? 1 : -1];
struct DerivedPhantomCreationInfo : public ExtendedPhantomCreationInfo
{
    void* __vecDelDtor(unsigned int);
};
typedef char _sizecheck_hkSimpleShapePhantomCinfo[sizeof(DerivedPhantomCreationInfo) == 96 ? 1 : -1];

namespace fnv_0056fac0 {
int __fastcall _FNV_GetFormType(void*);
}  // namespace fnv_0056fac0

namespace fnv_0056fc30 {
struct V3
{
    float x, y, z;
};
struct NiExtraDataX
{
};
struct NiAVObjectX
{
    NiExtraDataX* GetExtraData(int name);
};
int FUN_0050ea90();
extern V3 g_011ca3d4;
extern V3 _NiPoint3_ZERO;
}  // namespace fnv_0056fc30

namespace fnv_00570f00 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESForm;
struct TESObjectCELL;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadGame
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void LoadForm(TESForm*);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    void DeleteForm(TESForm*);
    void ChangeFormID(unsigned int, unsigned int);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    SaveLoadChangeHistory* GetHistory();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool SetThreadAllowChanges(bool);
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    bool GetAllowChanges();
    void SaveGame(SaveLoadFile*);
    bool LoadGame(SaveLoadFile*, bool);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};
typedef char _sizecheck_BGSSaveLoadGame[sizeof(BGSSaveLoadGame) == 588 ? 1 : -1];

}  // namespace fnv_00570f00

namespace fnv_00571080 {
struct NiAVObject;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

class NiNode;
template <class T> class NiPointer
{
  public:
    NiPointer<T>& operator=(T*);
};

void __fastcall FUN_0057c180(TESObjectREFR*);
void __fastcall FUN_0057c300(TESObjectREFR*);

}  // namespace fnv_00571080

namespace fnv_00571530 {
struct NiAVObject;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];

}  // namespace fnv_00571530

struct ReferenceLightData;

class ExtraDataList;
ReferenceLightData* __fastcall FUN_00418250(const ExtraDataList* pExtra);

namespace fnv_anon_tesobjectrefr {}
using namespace fnv_anon_tesobjectrefr;
namespace fnv_anon_tesobjectrefr {
struct TESObjectREFR_GetExtra_Caller
{
    const ExtraDataList* GetExtra() const;
};
}

namespace fnv_005728c0 {
struct ReferenceLightData
{
    void* __vecDelDtor(unsigned int);
    char m_pMenuLight[4];
    float m_fLightRadius;
};
typedef char _sizecheck_REFR_LIGHT[sizeof(ReferenceLightData) == 8 ? 1 : -1];
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct NiLightX;
struct SSLight;
struct SSNode
{
    SSLight* GetShadowSceneLight(NiLightX*, bool);
};
struct NiAdditionalGeometryData
{
    static SSNode* GetShadowSceneNodeForIndex(int);
};
struct NameStr
{
    operator const char*() const;
};
struct Sub2
{
    bool _ref_008256d0();
};
struct ExtraStub
{
    NameStr* FUN_00418250();
    NameStr* FUN_00418280();
    Sub2* FUN_0041f810();
};
struct FormTypeStub
{
    int _FNV_GetFormType();
    bool FUN_0050dd90();
};
struct FormStub
{
    bool IsDeleted() const;
    bool GetDisabled();
    const ExtraStub* GetExtra() const;
    FormTypeStub* _FNV_GetObjectReference();
};
}  // namespace fnv_005728c0

namespace fnv_00572d30 {

class ExtraDataList
{
  public:
    bool FUN_0041b3a0(int) const;
};

struct TESObjectREFR_GetExtra_helper
{
    const ExtraDataList* GetExtra() const;
};

}  // namespace fnv_00572d30

struct FUN_00572d50_shell : public TESObjectREFR
{
    void FUN_00572d50(int);
};

struct ExtraDataList_helper
{
    void FUN_0041b440(int);
};

struct TESObjectREFR_helper
{
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48(unsigned int);
    virtual void v4c(unsigned int);
    bool FUN_00561d90();
    ExtraDataList_helper* FUN_005d43c0();
};

struct FUN_00572db0_shell : public TESObjectREFR
{
    void FUN_00572db0(int);
};

struct FUN_00572db0_Extra
{
    void FUN_0041b470(int);
};

struct FUN_00572db0_Helper
{
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48(unsigned int);
    virtual void v4c(unsigned int);

    bool FUN_00561d90();
    FUN_00572db0_Extra* GetExtra();
};

class ExtraDataList;

const ExtraDataList* __fastcall FUN_005d43c0(const TESObjectREFR* pThis);

struct TempShell_005737e0
{
    char pad[0x64c];
    bool val;
    bool Get()
    {
        return val;
    }
};

float __cdecl WrapAngle(float);

namespace fnv_00575d10 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
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

struct BSOcclusionPlane
{
    int GetCullResult() const;
};

struct TESObjectCELL
{
    bool IsInterior();
};

struct DoorCell
{
    TESWorldSpace* GetParentWorldSpace();
};

}  // namespace fnv_00575d10

namespace fnv_00575d70 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSTerrainManager;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct GlobalVariableForm;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESTerrainLODManager;
struct TESWaterForm;
struct TESWorldSpace;
struct PointerPairData;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
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
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];

struct BSOcclusionPlane
{
    int GetCullResult() const;
};

struct DoorCell
{
    TESWorldSpace* GetParentWorldSpace();
};

}  // namespace fnv_00575d70

namespace fnv_00576260 {
struct Actor;
struct ActorValueOwner;
struct AlchemyItem;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct ExtraDataList;
struct ExtraLeveledItem;
struct InventoryChanges;
struct InventoryIterator;
struct IndexedPointerCollection;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESForm;
struct TESLevItem;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectWEAP;
struct InventoryStackRecord
{
    void Copy(InventoryStackRecord*);
    void MergeEntryData(InventoryStackRecord*);
    void ClearEntryData();
    TESBoundObject* GetContainerObject();
    void* GetExtraDataList();
    float GetConditionPercent(bool);
    int GetItemUses();
    float GetItemCharge();
    TESForm* GetInventoryObject();
    float GetItemValue();
    int GetHotKey();
    void SetHotKey(int);
    AlchemyItem* GetPoison();
    void RemovePoison();
    bool IsWorn(bool);
    bool IsWornDefault(bool);
    int GetCount();
    Script* GetScript();
    ScriptLocals* GetScriptLocalData();
    ExtraLeveledItem* RemoveLeveledItemExtra();
    bool HasPerkEntry();
    int NumberLeveledExtra();
    bool HasApplicablePerkEntry();
    int NumberStolenData();
    void RemoveOriginalChanges();
    bool IsWornStolen();
    unsigned char GetWeaponCategory();
    void SetModSlot(unsigned char);
    unsigned char GetModEffect(unsigned char);
    bool SetEquipmentState(unsigned char);
    bool SetEquipmentState(unsigned char, float*);
    void RoundToNearestStep();
    void GetPayloadAddress();
    static float GetModifiedAttackDamage(TESObjectWEAP*, ActorValueOwner*, float);
    float GetModifiedAttackDamage(ActorValueOwner*, float, bool);
    float GetDamageResistance(ActorValueOwner*);
    float GetArmorDamageThreshold(ActorValueOwner*);
    int GetTypeforMenu();
    char* GetDisplayNameForReference(TESObjectREFR*);
    char* GetFullName();
    float GetValueforMenuCol1(bool, Actor*, bool);
    float GetValueforMenuCol2(bool, Actor*, bool);
    float GetValueforMenuCol3(bool, Actor*, bool);
    float GetValueforMenuCol4(bool, bool, Actor*, bool);
    char* GetValueforMenu(int, bool, bool, Actor*, bool);
    void SetItemHealth(float, InventoryChanges*, ExtraDataList*, bool);
    void SetItemUses(int);
    void SetItemCharge(float, InventoryChanges*, ExtraDataList*);
    void SetItemOwner(TESForm*);
    void SetPoison(AlchemyItem*);
    void SetEquippedState(bool, bool, bool);
    void SetCount(int);
    bool ShouldDisplayItem(Actor*, bool, int, bool, bool);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    int GetStatusFlags();
    char* GetStatusIcon(int);
    TESBoundObject* GetItemChangeObject();
    void SetItemChangeObject(TESBoundObject*);
    int GetCountWithExtras(bool);
    int GetTotalCount();
    int GetAmountDefaultExtra();
    int GetExtraDataCount();
    void* __vecDelDtor(unsigned int);
    void* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
};
typedef char _sizecheck_ItemChange[sizeof(InventoryStackRecord) == 12 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESContainer : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void ClearObjects();
    InventoryItemEntry* AddObject(ContainerChanges*);
    InventoryItemEntry* AddObject(TESObject*, int, ContainerItemExtra*);
    void AddDuplicateObject(InventoryItemEntry*);
    InventoryItemEntry* GetFirstContainerObject();
    void RemoveContainerObject(InventoryItemEntry*);
    void ReplaceObject(TESObject*, TESObject*);
    bool HasObjectOfType(TESObject*);
    float GetContainerWeight(bool);
    int GetObjectCount(TESObject*);
    char Compare(InventoryItemEntry*, InventoryItemEntry*);
    float GetClothingModifier();
    static bool IsValidContainerType(unsigned char);
    static bool IsValidContainerObject(TESObject*);
    void MergeContainer(TESContainer*);
    void MultiplyContainerCounts(int);
    void SetClothingModifier(float);
    void AddContentsFromReference(TESObjectREFR*, bool);
    void AddInventoryChangesToContainer(int, InventoryChanges*);
    TESAmmo* GetBestAmmoForActor(TESActorBase*);
    TESObjectWEAP* GetBestWeapon(TESActorBase*);
    TESObjectARMO* FindBestArmor(TESActorBase*, int);
    TESObjectCLOT* GetBestClothing(TESActorBase*, int);
    TESBoundObject* GetInventoryEntryData(int);
    void* GetObjectList();
    void* GetObjectListEnd();
    void* __vecDelDtor(unsigned int);
    char objectList[8];
};
typedef char _sizecheck_TESContainer[sizeof(TESContainer) == 12 ? 1 : -1];

struct InventoryChanges
{
    InventoryStackRecord* FUN_004d0650(TESBoundObject*, unsigned int);
};
struct ExtraDataList
{
    InventoryChanges* GetContainerChangeData();
};
struct REFRExtraStandIn
{
    ExtraDataList* GetExtra() const;
};
}  // namespace fnv_00576260

namespace fnv_00576330 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, char const*);
};

}  // namespace fnv_00576330

namespace fnv_00576390 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

NiAVObject* __fastcall FUN_0043fcd0(TESObjectREFR*);

struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, char const*);
};

}  // namespace fnv_00576390

namespace fnv_005763f0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

}  // namespace fnv_005763f0

namespace fnv_00576420 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

}  // namespace fnv_00576420

struct SF577;
struct TESForm
{
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
    SF577* GetSourceFiles();
};

struct Dummy_00577bd0
{
    void FUN_00ca9360(float*);
};

namespace fnv_00577c10 {
struct Lst;
struct TESForm
{
    Lst* GetSourceFiles();
};
struct Sub
{
    int FUN_00577bf0();
};
struct TESDataHandler
{
    TESForm* GetBGSRagdollList();
    int FUN_00577c10();
};
}  // namespace fnv_00577c10

class NiFixedString;
struct NiExtraData;

struct NiAVObject
{
    NiExtraData* GetExtraData(NiFixedString const&);
};

struct NiNode : NiAVObject
{
};

NiFixedString const& __cdecl FUN_00448a80(void);

namespace fnv_005789b0 {
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct TESFile;
struct TESForm;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob16
{
    char b[16];
};
struct TeleportableReference
{
    TESObjectREFR* GetLinkedDoor();
    void* GetTeleportPosition();
    void* GetTeleportRotation();
    TESObjectCELL* GetTeleportCell();
    void GetTeleportCellMapName(void*);
    TESWorldSpace* GetTeleportWorldspace();
    struct blob16 GetTeleportDestinationPosition();
    TESForm* GetTeleportDestinationForm();
    bool GetNoAlarm();
    void SetNoAlarm(bool);
    void SetLinkedDoor(TESObjectREFR*);
    void SetTeleportPosition(void*);
    void SetTeleportRotation(void*);
    void SetLinkedDoorReference(TESObjectREFR*, bool);
    void Save();
    void Load(TESFile*);
    bool InitItem(TESForm*);
    void Copy(TeleportableReference*);
    bool Compare(TeleportableReference*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadGameBuffer*);
    void InitLoadGame();
    void FinishLoadGameTES();
    void* __vecDelDtor(unsigned int);
    TESObjectREFR* m_pLinkedDoorReference;
    char position[12];
    char rotation[12];
    unsigned char cFlags;
    char _pad_1d[3];
};
typedef char _sizecheck_DoorTeleportData[sizeof(TeleportableReference) == 32 ? 1 : -1];

template <class T> struct BSStringT
{
    operator const T*() const;
};
struct LockExtraData;
struct ExtraRadioData;
}  // namespace fnv_005789b0

namespace fnv_0057a3c0 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct TESObjectREFR_Helper
{
    void* GetReferenceType();
    bool FUN_004523e0(int);
    void FUN_0057a410(void*, bool);
};

}  // namespace fnv_0057a3c0

struct BSExtraData
{
    virtual ~BSExtraData();  // polymorphic: its RTTI is used (rtti_fix.py)
    BSExtraData(unsigned char);
};

struct MemberAt8
{
    void FUN_0057c700(int, int);
};

struct FUN_0057a9d0
{
    FUN_0057a9d0();
    virtual ~FUN_0057a9d0();
};

struct FUN_0057a960 : FUN_0057a9d0
{
    int unk4;
    MemberAt8 unk8;

    FUN_0057a960();
    virtual ~FUN_0057a960();
};

namespace fnv_0057ace0 {
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct Script;
struct TESActorBase;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESQuest;
struct TESTopic;
struct TESTopicInfo;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

struct ExtraDataList
{
    void FUN_0042ec70(TESTopicInfo*);
};

struct TESObjectREFR_GetExtra_helper
{
    ExtraDataList* GetExtra() const;
};

}  // namespace fnv_0057ace0

namespace fnv_0057ad20 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESQuest;
struct TESTopic;
struct TESTopicInfo;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
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

class ExtraDataList
{
  public:
    void FUN_0042ee00(TESTopic* apTopic) const;
    ExtraDataList const* GetExtra() const;
};

}  // namespace fnv_0057ad20

namespace fnv_0057ad60 {

class ExtraDataList
{
  public:
    void FUN_0042eec0(unsigned int) const;
};

}  // namespace fnv_0057ad60

extern float const DAT_01015f5c;

float __cdecl FUN_004a3e90(float);

struct TESTopic;

class ExtraDataList;

namespace fnv_anon_tesobjectrefr {}
using namespace fnv_anon_tesobjectrefr;
namespace fnv_anon_tesobjectrefr {
}

namespace fnv_0057bd60 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SoundPlaybackHandle;
struct BaseProcess;
struct DialogueResponse;
struct MobileObject;
struct NiAVObject;
struct NiPoint3;
struct LocationDescriptor;
struct TESIdleForm;
struct TESObjectCELL;
struct TESPackage;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct bhkCharacterController;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

namespace fnv_anon_tesobjectrefr {}
using namespace fnv_anon_tesobjectrefr;
namespace fnv_anon_tesobjectrefr {
}

}  // namespace fnv_0057bd60

void* __cdecl operator new(unsigned int);
extern float const DAT_01015f5c;
float __fastcall FUN_005471e0(void*);
void* __fastcall FUN_0057c2a0(void*);

struct MobileObjectCellAccess
{
    bool FUN_004518e0() const;
};

struct BSOcclusionPlane
{
    int GetCullResult() const;
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer<T>& operator=(T*);
};

struct TempLoadedRefData
{
    int unk00;
    int unk04;
    float unk08;
    float unk0c;
    int unk10;
    NiPointer<NiNode> spNode14;
    NiPointer<NiNode> spNode18;
    TempLoadedRefData()
    {
        FUN_0057c2a0(this);
    }
};

struct GlobalObject_00633c90
{
    int m_val;
    GlobalObject_00633c90(int = 0);
    ~GlobalObject_00633c90();
};

struct FUN_0057c2a0
{
    char pad00[0x14];
    GlobalObject_00633c90 field14;
    GlobalObject_00633c90 field18;

    FUN_0057c2a0();
};

// Default-constructs the two GlobalObject_00633c90 members at offsets 0x14 and 0x18.
// @fnv 0x0057c2a0
FUN_0057c2a0::FUN_0057c2a0()
{}

struct NiNodeX;
struct NiPtrX
{
    int v;
    NiPtrX& operator=(NiNodeX* p);
};
struct Obj57
{
    char pad[0x14];
    NiPtrX a;
    NiPtrX b;
    void* FUN_0057c370(int f);
};
struct FUN_0057c300_cls
{
    char pad[0x64];
    Obj57* obj;
    void FUN_0057c300();
};

namespace fnv_006dcbb0 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTerrainManager;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FindTriangleForLocationFilter;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NavMeshPtr;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct GlobalVariableForm;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESTerrainLODManager;
struct TESWaterForm;
struct TESWorldSpace;
struct PointerPairData;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct PathingLocation
{
    virtual void SaveGame(BGSSaveGameBuffer*);
    virtual void LoadGame(BGSLoadGameBuffer*);
    void SetNavMeshInfo(void*);
    void SetLocation(void*);
    void SetLocationSimple(void*);
    void SetTriangleIndex(unsigned short);
    struct blob12 GetLocation();
    TESObjectCELL* GetContainingCell();
    TESWorldSpace* GetParentWorldspace();
    TESObjectCELL* GetCellSimple();
    TESWorldSpace* GetWorldspaceSimple();
    void* GetAssociatedNavMesh();
    bool IsOnNavMesh(void*);
    bool ResolveNavMesh(NavMeshPtr*);
    bool FindNavMeshTriangle(NavMeshPtr*, unsigned short*);
    unsigned short GetTriangle();
    bool HasValidTriangle();
    bool HasNavMesh();
    void* GetNavMeshInfo();
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
    bool IsPathingLocationValid();
    bool HasPathingLocation();
    bool QUnused();
    void SetUnused();
    void ClearUnused();
    bool QValid();
    void ResetLocation();
    void WriteDebugString(char*, int);
    bool IsDistanceBelowThreshold(float);
    bool IsCloseTo(void*, float);
    void SetLocationData(void*, TESObjectCELL*, TESWorldSpace*);
    bool QAllMeshesReachable();
    void SetAllMeshesReachable(int);
    bool GetAllMeshesReachable();
    void* __vecDelDtor(unsigned int);
    char Location[12];
    void* m_pLocationNavMesh;
    void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    char _pad_27[1];
};
typedef char _sizecheck_PathingLocation[sizeof(PathingLocation) == 40 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
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
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];

extern int DAT_0102583c;
void __fastcall _ref_006815c0(void* pThis);

}  // namespace fnv_006dcbb0

namespace fnv_0088b4e0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiColor;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESFormList;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
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

class Sky;
class TES
{
  public:
    Sky* GetLogDate();
};

int __fastcall FUN_00418250(const ExtraDataList*);

struct TESObjectREFR_Helper : public TESObjectREFR
{
    const ExtraDataList* GetExtra() const;
};

}  // namespace fnv_0088b4e0

struct ActorMover
{
    void ForceStopMoving(void);
};

namespace fnv_008be4f0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

extern double _gModifierZero;

}  // namespace fnv_008be4f0

struct Sky;

struct TES
{
    Sky* GetLogDate();
};

struct ExtraX
{
};
struct NiAVObjectX
{
    ExtraX* GetExtraData(int name);
};
int FUN_0050ea90();
struct Holder
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
    virtual void V5f4(void* e);
};
struct FUN_009335b0_cls
{
    char pad[0x68];
    Holder* holder;
    NiAVObjectX* FUN_0056b2d0(unsigned char a);
    void SetReferenceFlag(bool b);
    NiAVObjectX* FUN_009335b0(unsigned char a);
};

namespace fnv_00950b60 {
template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

const char* __fastcall FUN_0043fcd0(TESObjectREFR*);

}  // namespace fnv_00950b60

namespace fnv_0098ddd0 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct FurnitureMark
{
    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
    char Position[12];
    unsigned short m_usMarkerId;
    unsigned char m_ucFlags;
    char _pad_f[1];
};
typedef char _sizecheck_FurnitureMark[sizeof(FurnitureMark) == 16 ? 1 : -1];
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

}  // namespace fnv_0098ddd0

unsigned int __fastcall _FNV_GetFormType(void*);
bool __cdecl FUN_0040eb10(float, float, float);
struct ExtraL
{
    void FUN_00419700(void*);
    void SetExtraDataValue(int);
    void FUN_004198a0(int);
    void SetExtraHealth(float);
};

namespace fnv_0047a520 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct NFSHelper : public NiFixedString
{
    operator char const*() const;
};
}  // namespace fnv_0047a520

namespace fnv_0055d6d0 {
struct FUN_00565090_shell;
class TESObjectSTAT;
TESObjectSTAT* __fastcall _FNV_GetObjectReference(FUN_00565090_shell*);
struct FUN_00565090_shell
{
    bool FUN_00565090();
};
struct BSFadeNode
{
    int GetLODMultType() const;
};
struct BSFadeNode_Dummy;
void __fastcall FUN_00476ab0(BSFadeNode_Dummy*);
}  // namespace fnv_0055d6d0

class TESObjectSTAT;
TESObjectSTAT* __fastcall _FNV_GetObjectReference(TESObjectREFR*);
unsigned int __fastcall _FNV_GetFormType(void*);
struct ArrSI
{
    unsigned int GetFlags();
};

namespace fnv_005672c0 {
int __cdecl _stricmp(const char*, const char*);
unsigned int __fastcall _FNV_GetFormType(void*);
extern const char* DAT_01197b5c;
struct NiFixedString
{
    operator char const*() const;
};
struct NiAVObject
{
    NiFixedString& GetName();
};
}  // namespace fnv_005672c0

namespace fnv_00567f80 {
struct BSExtraData;
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
};
class TESObjectSTAT;
TESObjectSTAT* __fastcall _FNV_GetObjectReference(void*);
unsigned int __fastcall _FNV_GetFormType(void*);
struct XActor
{
    BaseExtraList* GetExtra() const;
};
}  // namespace fnv_00567f80

namespace fnv_00568fa0 {
struct NiPoint3
{
    float x, y, z;
};
extern NiPoint3 _NiPoint3_ZERO;
struct Fn568fa0;
struct Flt
{
    operator Fn568fa0*() const;
};
struct Fn568fa0
{
    Flt* GetExtraRadioData();
    NiPoint3 const& FUN_00568fa0();
};
}  // namespace fnv_00568fa0

struct NiAVObject;
struct NiObjectNET
{
    unsigned int GetNumChildren();
};

struct XExtraList;
struct XActor
{
    const XExtraList* GetExtra() const;
};

struct M3
{
    float a, b, c, d, e, f, g, h, i;
};
void __fastcall _ref_006815c0(void* pThis);

namespace fnv_0056fb10 {
struct NiPoint3;
struct P3
{
    float x, y, z;
};
struct ExtraX;
struct NiAVObjectX
{
    ExtraX* GetExtraData(int);
};
int FUN_0050ea90();
extern P3 _NiPoint3_ZERO;
}  // namespace fnv_0056fb10

namespace fnv_00572380 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

struct NiP3Sub : public NiPoint3
{
    NiPoint3 operator-(NiPoint3 const&) const;
};
}  // namespace fnv_00572380

namespace fnv_00572a50 {
struct ExtraDataList;
struct ReferenceLightData;
ReferenceLightData* __fastcall FUN_00418250(const ExtraDataList* pExtra);
struct NiAVObject;
struct XExtraList;
struct XActor
{
    const XExtraList* GetExtra() const;
};
struct Flt
{
    operator unsigned int() const;
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
namespace fnv_005728c0 {
struct NameStr;
struct ExtraStub
{
    NameStr* FUN_00418280();
};
}
struct NiAdditionalGeometryData
{
    static void* GetShadowSceneNodeForIndex(int);
};
}  // namespace fnv_00572a50

namespace fnv_006dcd70 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTerrainManager;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FindTriangleForLocationFilter;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NavMeshPtr;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct GlobalVariableForm;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESTerrainLODManager;
struct TESWaterForm;
struct TESWorldSpace;
struct PointerPairData;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct PathingLocation
{
    virtual void SaveGame(BGSSaveGameBuffer*);
    virtual void LoadGame(BGSLoadGameBuffer*);
    void SetNavMeshInfo(void*);
    void SetLocation(void*);
    void SetLocationSimple(void*);
    void SetTriangleIndex(unsigned short);
    struct blob12 GetLocation();
    TESObjectCELL* GetContainingCell();
    TESWorldSpace* GetParentWorldspace();
    TESObjectCELL* GetCellSimple();
    TESWorldSpace* GetWorldspaceSimple();
    void* GetAssociatedNavMesh();
    bool IsOnNavMesh(void*);
    bool ResolveNavMesh(NavMeshPtr*);
    bool FindNavMeshTriangle(NavMeshPtr*, unsigned short*);
    unsigned short GetTriangle();
    bool HasValidTriangle();
    bool HasNavMesh();
    void* GetNavMeshInfo();
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
    bool IsPathingLocationValid();
    bool HasPathingLocation();
    bool QUnused();
    void SetUnused();
    void ClearUnused();
    bool QValid();
    void ResetLocation();
    void WriteDebugString(char*, int);
    bool IsDistanceBelowThreshold(float);
    bool IsCloseTo(void*, float);
    void SetLocationData(void*, TESObjectCELL*, TESWorldSpace*);
    bool QAllMeshesReachable();
    void SetAllMeshesReachable(int);
    bool GetAllMeshesReachable();
    void* __vecDelDtor(unsigned int);
    char Location[12];
    void* m_pLocationNavMesh;
    void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    char _pad_27[1];
};
typedef char _sizecheck_PathingLocation[sizeof(PathingLocation) == 40 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
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
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];

struct RefHelper;
struct TESWorldSpace;
struct TESObjectCELL;
struct PC7d;
struct TES
{
    TESWorldSpace* GetHitSound();
};
struct RefHelper
{
    TESWorldSpace* GetParentWorldSpace();
};
struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct fnv_006dcbb0
{
    static int DAT_0102583c;
};
void __fastcall _ref_006815c0(void* pThis);
extern TES* g_TES;
extern PC7d* g_thePlayer;
}  // namespace fnv_006dcd70

namespace fnv_009624d0 {
struct ReferenceLightData;
struct ExtraDataList;
ReferenceLightData* __fastcall FUN_00418250(const ExtraDataList*);
struct XExtraList;
struct XActor
{
    const XExtraList* GetExtra() const;
};
struct NPH
{
    bool operator==(NPH const&) const;
};
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
}  // namespace fnv_009624d0

void __cdecl Deallocate(void*);
namespace p07 {
}

namespace fnv_00561d90 {

struct ShellH;
class TESForm;
class XActor
{
  public:
    ShellH* GetExtra() const;
};
struct FormChangeMask
{
    FormChangeMask(int);
    FormChangeMask(const FormChangeMask&);
    int iFlags;
};
class BGSSaveLoadGame
{
  public:
    bool HasFormChangeFlags(TESForm*, FormChangeMask);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
}  // namespace fnv_00561d90

extern int DAT_0126822c;
struct FUN_0056e370
{
    FUN_0056e370();
    virtual ~FUN_0056e370();
    void FUN_00c9f050(const void*);
    void FUN_0056e350();
};

struct FUN_0056e180
{
    FUN_0056e180();
    ~FUN_0056e180();
    char pad00[0x18];
};

namespace fnv_0056e550 {
extern int DAT_0126822c;
struct FUN_0056e370
{
    FUN_0056e370();
    virtual ~FUN_0056e370();
    void FUN_00c9f050(const void*);
    void FUN_0056e350();
};
}  // namespace fnv_0056e550

struct GO
{
    GO(int);
    void* m_pObject;
};
struct FUN_005726c0
{
    GO m_pMenuLight;
    float m_fLightRadius;
    FUN_005726c0();
};
// @f3 0x004471d0 (community match, verified in this file)
struct A1450MemoryManager { void Deallocate(void*); };
extern A1450MemoryManager DAT_011f6238;
struct Cls_004471d0 {
    char pad[0x420];
    void* ptr420;
    int unk424;
    void FUN_004471d0();
};
// pdb: TESFile::FreeDecompressedBuffer | TESFile.obj | fnv360_0822_retail, callee_sim, low
void Cls_004471d0::FUN_004471d0() {
    if (ptr420) {
        DAT_011f6238.Deallocate(ptr420);
        ptr420 = 0;
        unk424 = 0;
    }
}


namespace fnv_00575700 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct FUN_00575700_shell : public TESObjectREFR
{
    void FUN_00575700(struct blob12);
};

float __cdecl WrapAngle(float);
}  // namespace fnv_00575700

namespace fnv_0055a2f0 {
struct TESForm
{
    virtual void vf();
    char pad[0x14];
    TESForm();
    ~TESForm();
};

struct DoorTeleportLoadData
{
    int unk00;
    DoorTeleportLoadData();
};

struct SFTX
{
    void SetFormType(int);
};

struct TESChildCell
{
    virtual void UnkChildCell();
    TESChildCell();
};

struct ExtraDataList_helper
{
    ExtraDataList_helper();
    ~ExtraDataList_helper();
};

struct FUN_0055a2f0 : public TESForm, public TESChildCell
{
    void* m_pSoundForm;               // at 0x1c
    DoorTeleportLoadData m_teleport;  // at 0x20
    char pad_data[0x40 - 0x24];
    void* m_pOwningCell;             // at 0x40
    ExtraDataList_helper m_extra;  // at 0x44
    char pad_extra[0x64 - 0x44 - sizeof(ExtraDataList_helper)];
    void* m_pRenderData;  // at 0x64

    void FUN_0055ac90();
    FUN_0055a2f0();
};

// @fnv 0x0055a2f0
FUN_0055a2f0::FUN_0055a2f0()
{
    ((SFTX*)this)->SetFormType(0x3a);
    m_pRenderData = 0;
    FUN_0055ac90();
    m_teleport.unk00 = 0;
    m_pOwningCell = 0;
    m_pSoundForm = 0;
}
}  // namespace fnv_0055a2f0

int DAT_011dea24;
// @fnv 0x0055ac70
int FUN_0055ac70()
{
    return DAT_011dea24;
}

extern int DAT_011dea24;
// @fnv 0x0055ac80
void FUN_0055ac80()
{
    DAT_011dea24 = 0;
}

namespace fnv_00565580 {
struct NiAVObject;

struct Model
{
    void* GetObject3D();
};

struct Flt
{
    operator unsigned int() const;
};

struct TL
{
    Flt* GetNext(void*&);
};

struct TESRecipe
{
    TL* GetData();
};

struct NiObjectNET
{
    unsigned int GetNumChildren();
};

struct NiNode
{
    NiAVObject* GetAt(unsigned int);
};

}  // namespace fnv_00565580

namespace fnv_00569880 {
struct XActor
{
    void* GetExtra() const;
};

struct FUN_0041fbe0_shell
{
    void* FUN_0041fbe0();
};

}  // namespace fnv_00569880

namespace fnv_0056a8d0 {
extern int g_011c7d34;

struct NiObjectNET
{
    unsigned int GetNumChildren();
};

struct NiNode
{
    void* GetAt(unsigned int);
};

}  // namespace fnv_0056a8d0

namespace fnv_0056fba0 {
struct NiPoint3
{
    float x, y, z;
};

extern NiPoint3 g_011ca3d4;
extern NiPoint3 _NiPoint3_ZERO;

int FUN_0050ea90();

struct ExtraX;
struct NiAVObjectX
{
    ExtraX* GetExtraData(int);
};

}  // namespace fnv_0056fba0

struct NiFixedString;

namespace fnv_00572610 {
struct NP
{
    void* ptr;
    NP& operator=(void*);
};

struct FUN_005726c0 : public NP
{
    float fScale;
    FUN_005726c0();
};

struct XActor
{
    void* GetExtra() const;
};

}  // namespace fnv_00572610

namespace fnv_0057a770 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

struct FUN_0057a960
{
    char pad[0x18];
    FUN_0057a960();
};

struct ShellH;
struct XActor
{
    ShellH* GetExtra() const;
};

struct ExtraAnimNoteReceiver
{
    unsigned char pad[0xc];
    BSAnimNoteReceiver* m_pReceiver;
};

}  // namespace fnv_0057a770

struct FUN_0067b170
{
    char pad[0x11];
    char field_11;
    char pad2[0x20 - 0x12];
    FUN_0067b170();
};

struct TESPackage
{
    char pad[0x28];
    FUN_0067b170* field_28;
    int GetPackType();
    void FUN_00672aa0(char arg);
};

namespace fnv_0084e730 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct ReferencePlacementData;
struct TESForm;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadInitialDataPacket
{
    static int DetermineInitialDataType(unsigned int, int, struct blob4);
    static int DetermineInitialDataType(TESForm*, struct blob4);
    static unsigned int GetInitialDataTypeSize(int);
    static unsigned int GetInitialDataTypeDataSize(int);
    static bool IsInitialDataRefType(int);
    static bool IsInitialDataCellType(int);
    static unsigned int ReadInitialDataBlock(char*, int, void*);
    static unsigned int ReadInitialDataBlock(BGSLoadFormBuffer*, int, void*);
    static unsigned int ReadInitialDataBlock(SaveLoadFile*, int, void*);
    static int AddFormToChangesMap(BGSSaveFormBuffer*, TESForm*, struct blob4);
    static int LoadInitialDataForForm(BGSLoadFormBuffer*, TESForm*, struct blob4);
    static TESForm* CreateReference(unsigned int, ReferencePlacementData*, TESForm*);
    char _pad_0[1];
};
typedef char _sizecheck_BGSSaveLoadInitialData[sizeof(BGSSaveLoadInitialDataPacket) == 1 ? 1 : -1];
struct FormChangeMask
{
    bool ContainsAnyFlags(int);
    bool CheckFlagsExact(int);
    bool CheckFlagsExclusive(int);
    void SetFlags(int);
    void AddFlags(int);
    void RemoveFlags(int);
    struct blob4 GetDifference(int);
    static char* GetFullFlagName(int, unsigned int, bool);
    static char* GetShortFlagName(int, unsigned int);
    static bool IsFlagSetForType(int, unsigned int, unsigned int);
    bool HasFormChanged(TESForm*);
    static struct blob4 CombineFlags(struct blob4, struct blob4, unsigned int, bool);
    int iFlags;
};
typedef char _sizecheck_BGSChangeFlags[sizeof(FormChangeMask) == 4 ? 1 : -1];

struct DataHandler
{
    bool FormIDExists(unsigned int);
};

extern DataHandler* g_dataHandler;

}  // namespace fnv_0084e730

namespace fnv_00418220 {
struct BSExtraData;

struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
    int FUN_00418220();
};

}  // namespace fnv_00418220

namespace fnv_00561580 {
struct ScriptLocalsX
{
    void* GetLocalData(void);
};
struct ScriptX
{
    void GetLocalData(void);
};
struct hkpEntity
{
    void activate();
    void deactivate();
};

}  // namespace fnv_00561580

namespace fnv_005617c0 {
struct ScriptLocalsX
{
    void* GetLocalData();
};
struct ScriptX
{
    void GetLocalData();
};

}  // namespace fnv_005617c0

namespace fnv_00562020 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SoundPlaybackHandle;
struct BaseProcess;
struct DialogueResponse;
struct MobileObject;
struct NiAVObject;
struct NiPoint3;
struct LocationDescriptor;
struct TESIdleForm;
struct TESObjectCELL;
struct TESPackage;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct bhkCharacterController;
struct PhysicsSimulationContext;
struct hkStatisticsCollector;
struct hkVector4;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];

struct M3
{
    float a, b, c, d, e, f, g, h, i;
    M3();
};
struct CharCtl_S
{
    void FUN_005620e0(void*);
};
struct S_00931f80
{
    CharCtl_S* GetPhysicsCharacterController();
};
struct UpdData
{
    float t;
    char b0, b1, b2, b3, b4, b5, b6, b7;
    void NiUpdateData(float, bool, bool);
};
void __cdecl FUN_00c69f50(void*, int, int);

}  // namespace fnv_00562020

namespace fnv_005691b0 {
struct LockExtraData
{
    int GetLevel(TESObjectREFR* ref);
};

}  // namespace fnv_005691b0

namespace fnv_00569ac0 {

struct ShellH
{
    TESObjectREFR* FUN_00421e10(void);
};

struct XActor
{
    ShellH* GetExtra(void) const;
};

}  // namespace fnv_00569ac0

namespace fnv_00569b20 {
struct XActor
{
    void* GetExtra() const;
    void FUN_00569b20();
};

struct ShellH
{
    void FUN_0041e220();
};

}  // namespace fnv_00569b20

namespace fnv_0056b1d0 {
struct ExtraDataList;
struct RadioReferenceData
{
    int m_unk0;
    int m_unk4;
    float m_unk8;
};
RadioReferenceData* __fastcall FUN_004182e0(ExtraDataList const*);

struct XActor
{
    ExtraDataList* GetExtra(void) const;
    float FUN_0056b1d0();
};

}  // namespace fnv_0056b1d0

void __fastcall FUN_004b4fc0(void* p);

extern "C" void __cdecl __Dummy_00b6fef0(void* ptr, unsigned int size);

void __cdecl __Dummy_00b6fef0(void* obj, unsigned int size);

extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int flags);

extern "C" void __cdecl __Dummy_00b6fef0(void* obj, unsigned int size);

extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

namespace fnv_00572d10 {
struct S0041b470
{
    unsigned int FUN_0041b370();
};

struct XActor
{
    S0041b470* GetExtra() const;
    unsigned int FUN_00572d10();
};

}  // namespace fnv_00572d10

struct _dummy_4d9fa0
{
    void FUN_004d9fc0(bool, unsigned short);
    void FUN_00573f00(bool argument0);
};

struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void FUN_00576640(bool argument0);
};

namespace fnv_00576660 {
struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void FUN_00576660(bool value);
};

}  // namespace fnv_00576660

namespace fnv_005771d0 {
struct bhkShape;
}  // namespace fnv_005771d0

struct Flt
{
    operator unsigned int() const;
};

namespace fnv_005673c0 {
class ExtraDataList;
class Script;

class XActor
{
  public:
    ExtraDataList* GetExtra() const;
    Script* FUN_005673c0();
};

Script* __fastcall FUN_00418800(ExtraDataList*);

}  // namespace fnv_005673c0

extern "C" void* __cdecl _delete(void* ptr, unsigned int size);

struct bhkWorldObject
{
    void FUN_00c85790();
    void* FUN_0056d4c0(unsigned int flags);
};

struct FUN_0056e2a0
{
    void FUN_004b4fa0();
    FUN_0056e2a0();
};

// @fnv 0x0056e2a0
FUN_0056e2a0::FUN_0056e2a0()
{
    FUN_004b4fa0();
    (reinterpret_cast<FUN_0056e2a0*>(reinterpret_cast<char*>(this) + 0x10))->FUN_004b4fa0();
    (reinterpret_cast<FUN_0056e2a0*>(reinterpret_cast<char*>(this) + 0x20))->FUN_004b4fa0();
}

struct bhkAabbPhantom
{
    virtual ~bhkAabbPhantom();
    void FUN_00c9f530();
    void* FUN_0056e5e0(unsigned int flags);
    static void operator delete(void* ptr, unsigned int size);
};

namespace fnv_0056e740 {
extern void __cdecl _delete(void* p, unsigned int size);

struct bhkShape
{
    void FUN_00c84c50();
    void* FUN_0056e740(unsigned int flags);
};

}  // namespace fnv_0056e740

namespace fnv_00572750 {
class BSExtraData;

struct FUN_00418280_Class
{
    BSExtraData* FUN_00418280();
};

struct XActor
{
    FUN_00418280_Class* GetExtra() const;
    BSExtraData* FUN_00572750();
};

}  // namespace fnv_00572750

namespace fnv_00573ed0 {
struct _dummy_4d9fa0
{
    void FUN_004d9fc0(bool, unsigned short);
    void FUN_00573f00(bool);
    void FUN_00573ed0(bool value);
};

}  // namespace fnv_00573ed0

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};

namespace fnv_0055a3b0 {
struct ShellH
{
    void* FUN_00418220();
};
struct XActor
{
    ShellH* GetExtra() const;
};
}  // namespace fnv_0055a3b0

extern double _gModifierZero;

struct hkVector4
{
    float x, y, z, w;
};

namespace fnv_00569080 {
struct FUN_004184c0_shell
{
    void* FUN_004184c0();
};
struct ShellH
{
    FUN_004184c0_shell* FUN_004184c0();
};
struct XActor
{
    ShellH* GetExtra() const;
};
}  // namespace fnv_00569080

namespace fnv_0056a990 {
struct ShellH;
struct XActor
{
    ShellH* GetExtra() const;
};
}  // namespace fnv_0056a990

namespace fnv_0056c7f0 {
class Flt
{
  public:
    operator unsigned int() const;
};

struct Tile
{
    unsigned char pad[0x2c];
    Flt m_pRenderedNodeEntry;
    unsigned int FUN_0056c7f0();
};

}  // namespace fnv_0056c7f0

namespace fnv_0056f110 {
struct ScriptLocalsX
{
    void* GetLocalData();
};

}  // namespace fnv_0056f110

namespace fnv_0057b500 {
struct ShellH
{
    void FUN_0042f2d0();
};
struct XActor
{
    ShellH* GetExtra() const;
    void FUN_0057b500();
};
}  // namespace fnv_0057b500

struct FUN_0057b700_class
{
    int FUN_0057b730(int a);
    void FUN_0061ff30(int a);
    void FUN_0057b700(int a);
};

namespace fnv_006546e0 {
struct Flt
{
    operator unsigned int();
};

}  // namespace fnv_006546e0

namespace fnv_005627c0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];

struct FormChangeMask
{
    FormChangeMask();
    operator bool() const;
    unsigned int flags;
};
struct TESForm
{
    void Revert(unsigned int);
};
struct ShellH
{
    void FUN_0042d9e0(BGSLoadFormBuffer*);
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct FUN_00572db0_Helper
{
    bool FUN_00561d90();
};
struct FUN_00572db0_shell
{
    void FUN_00572db0(int);
};
struct FUN_00572d50_shell
{
    void FUN_00572d50(int);
};
struct TESObjectCELL
{
    bool IsOutdoorCell();
    void FUN_005455c0(TESObjectREFR*);
};
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct RefX
{
    bool FUN_00437b90();
};
struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct TES_s
{
    void* FUN_00458be0(int, int);
};
extern TES_s* g_TES;
struct Loader_S
{
    void FUN_00444850(TESObjectREFR*, void*, int);
};
extern Loader_S* g_modelLoader;

}  // namespace fnv_005627c0

namespace fnv_00563d80 {
struct NiControllerManager;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];

struct NiAVObject
{
    int iDummy;
};
struct NiNode : public NiAVObject
{
    void Update(const NiUpdateData& arData);
};
struct NiFixedStr
{
    operator const char*() const;
};
struct SeqObj
{
    NiFixedStr& GetName();
};
struct NiControllerSequence
{
    int GetState();
    float FUN_00759450();
    float FUN_00508100();
    void hkpSimulationIsland_markForWrite(float);
};
struct BSAnimGroupSequence : public NiControllerSequence
{
};
struct NiControllerManager
{
    unsigned int FUN_00495d00();
    BSAnimGroupSequence* FUN_00495d20(unsigned int);
    void DeactivateAllSequences(float);
    bool ActivateControllerSequence(NiControllerSequence*, int, bool, float, float, NiControllerSequence*);
    bool StopSequence(NiControllerSequence*, float);
};
struct TaskQueueInterface
{
    void QueueReferenceStateTask(bool);
};
struct UpdData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    void NiUpdateData(float, bool, bool);
};
void __cdecl FUN_00c6bd00(NiNode*, bool);
extern float DAT_0102f510;

}  // namespace fnv_00563d80

namespace fnv_00565870 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiColor;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectWEAP;
struct TESPackage;
struct TESQuest;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
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
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

struct ExtraSayToTopicInfo;
struct XScript
{
    bool Run(void*, void*, void*, bool);
};
struct XEDL
{
    void* GetScriptLocalData();
    ExtraSayToTopicInfo* FUN_0042ede0();
};
struct XActor
{
    XEDL* GetExtra() const;
};
struct XForm
{
    int _FNV_GetFormType();
};
struct XRef
{
    XForm* _FNV_GetObjectReference();
    bool IsDeleted() const;
};
XScript* __fastcall FUN_00418800(XEDL*);
void* __fastcall FUN_0055d310(void*);

}  // namespace fnv_00565870

namespace fnv_00568020 {
struct BSExtraData;

struct BSExtraData;
struct ExtraUsedMarkers
{
    char pad[0xc];
    unsigned int m_uiUsedMarkerFlags;
    ExtraUsedMarkers();
    void SetUsedMarker(unsigned int, bool);
};
struct FNVFormStub
{
    int _FNV_GetFormType();
};
struct FNVRefStub
{
    FNVFormStub* _FNV_GetObjectReference();
};
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* AddExtra(BSExtraData*);
    void _FUN_00410020(BSExtraData*, bool);
};
struct XActor
{
    BaseExtraList* GetExtra() const;
};

}  // namespace fnv_00568020

namespace fnv_00568150 {
struct BSExtraData;

struct ExtraReservedMarkers
{
    void* vt;
    void* next;
    unsigned char type;
    unsigned int m_uiReservedMarkers;
    ExtraReservedMarkers();
    void SetUsedMarker(unsigned int, bool);
};
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* AddExtra(BSExtraData*);
    void FUN_00410020(BSExtraData*, bool);
};
struct XActor
{
    BaseExtraList* GetExtra() const;
};

}  // namespace fnv_00568150

namespace fnv_005682c0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSExtraData;
struct BaseFormComponent;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};

struct BSExtraData;
struct ExtraUsedMarkers
{
    bool FUN_00432f80(unsigned int);
};
typedef ExtraUsedMarkers ExtraReservedMarkers;
struct TESFurniture
{
    bool IsMarkerEnabled(unsigned int);
    int _FNV_GetFormType();
};
struct FNVRefStub
{
    TESFurniture* _FNV_GetObjectReference();
};
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
};
struct XActor
{
    BaseExtraList* GetExtra() const;
};

}  // namespace fnv_005682c0

namespace fnv_00568cb0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

struct ExtraDataList
{
    float GetRadius();
};
struct XActor
{
    ExtraDataList* GetExtra() const;
};
bool __cdecl FUN_0040eb10(float, float, float);
extern double _gModifierZero;

}  // namespace fnv_00568cb0

namespace fnv_0056e270 {
struct FUN_0056e2a0
{
    char _pad[0x30];
    FUN_0056e2a0();
};
struct Mem4fa0
{
    void FUN_004b4fa0();
};
struct FUN_0056e270 : FUN_0056e2a0
{
    Mem4fa0 m30;
    FUN_0056e270();
};
// Constructs the base FUN_0056e2a0 and then calls FUN_004b4fa0 on the m30 member.
// @fnv 0x0056e270
FUN_0056e270::FUN_0056e270()
{
    m30.FUN_004b4fa0();
}
}  // namespace fnv_0056e270

namespace fnv_0056fa90 {
struct Holder
{
    char _p[0x24];
    float _a;
    float _b;
    float _c;
    void FUN_0056fa90(float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9);
};
}  // namespace fnv_0056fa90

namespace fnv_00572b00 {
struct NiPoint3
{
    float x, y, z;
};
struct ShellH
{
    NiPoint3 FUN_0041b080(void*);
};
struct XActor
{
    ShellH* GetExtra() const;
};
}  // namespace fnv_00572b00

namespace fnv_00572b30 {
struct XActor;
struct ShellH
{
    void __thiscall FUN_0041b0d0(int, XActor*);
};
struct XActor
{
    ShellH* GetExtra() const;
    int FUN_00572b30(int);
};
}  // namespace fnv_00572b30

namespace fnv_005764f0 {
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct NiAVObject;
struct NiNode
{
    void FUN_004902f0(bool);
};
struct TaskQueueInterface
{
    void FUN_00576640(bool);
};
struct ArrSI
{
    NiNode* GetFlags();
};
struct TESContainer
{
    static bool __cdecl IsValidContainerType(unsigned char);
};
struct FormOps
{
    int _FNV_GetFormType();
};
struct RefOps
{
    FormOps* _FNV_GetObjectReference();
};

}  // namespace fnv_005764f0

struct NiNode;
void __cdecl FUN_00c6bd00(NiNode*, bool);
struct Unknown
{
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual void f68() = 0;
    virtual void f69() = 0;
    virtual void f70() = 0;
    virtual void f71() = 0;
    virtual void f72() = 0;
    virtual void f73() = 0;
    virtual void f74() = 0;
    virtual void f75() = 0;
    virtual void f76() = 0;
    virtual void f77() = 0;
    virtual void f78() = 0;
    virtual void f79() = 0;
    virtual void f80() = 0;
    virtual void f81() = 0;
    virtual void f82() = 0;
    virtual void f83() = 0;
    virtual void f84() = 0;
    virtual void f85() = 0;
    virtual void f86() = 0;
    virtual void f87() = 0;
    virtual void f88() = 0;
    virtual void f89() = 0;
    virtual void f90() = 0;
    virtual void f91() = 0;
    virtual void f92() = 0;
    virtual void f93() = 0;
    virtual void f94() = 0;
    virtual void f95() = 0;
    virtual void f96() = 0;
    virtual void f97() = 0;
    virtual void f98() = 0;
    virtual void f99() = 0;
    virtual void f100() = 0;
    virtual void f101() = 0;
    virtual void f102() = 0;
    virtual void f103() = 0;
    virtual void f104() = 0;
    virtual void f105() = 0;
    virtual void f106() = 0;
    virtual void f107() = 0;
    virtual void f108() = 0;
    virtual void f109() = 0;
    virtual void f110() = 0;
    virtual void f111() = 0;
    virtual void f112() = 0;
    virtual void f113() = 0;
    virtual void f114() = 0;
    virtual void f115() = 0;
    virtual void f116() = 0;
    virtual NiNode* GetNode() = 0;
    void FUN_00578920(bool);
};

namespace fnv_0057ab70 {
struct BSMultiBoundNode;
struct RefV;
struct NodeV
{
    NodeV* GetDaysPassed();
};
struct BoundNodeV
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
    virtual void AttachChildInAvailableSlot(NodeV* child, bool firstAvail);
};
struct TESObjectCELL
{
    NodeV* GetDynamicNode();
    BoundNodeV* FUN_00545960(RefV* ref);
};
struct BSOcclusionPlane
{
    TESObjectCELL* GetCullResult() const;
};
struct RefV
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
    virtual NodeV* Get3D();
    void FUN_00569ae0(RefV* ref);
};
struct MapX
{
    void* GetFirstPos();
};
struct NiTMap
{
    void GetNext(void*& pos, RefV*& key, RefV*& val);
};

}  // namespace fnv_0057ab70

namespace fnv_0057b520 {
struct BSExtraData;
struct BSMultiBoundNode;
struct NiAVObject;
struct NiCamera;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct TESObjectCELL;
struct TESWaterForm;
struct TESWaterListener;
struct TESWorldSpace;
struct TargetEntry;
struct WaterZone;
struct bhkRigidBody;
struct hkVector4;
struct hkpEntity;
struct hkpRigidBody;
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};

struct ShellH;
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct WaterZone;
struct EffectSetting
{
    int GetEffectID();
};
extern int g_TES;
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
struct MapX
{
    void* GetFirstPos();
};
struct FUN_0057b700_class
{
    void FUN_0057b700(int);
};
TESObjectREFR* __fastcall _ref_0084e3a0(void*);
struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct ExtraDataList
{
    unsigned int GetRoomId();
};
struct bhkWorld;
struct TESWaterListener;
struct MobileObjectCellAccess
{
    bool FUN_004518e0() const;
};
struct MobileObject
{
    float GetRelevantWaterHeight() const;
};
struct CC_00931f80;
struct S_00931f80
{
    CC_00931f80* GetPhysicsCharacterController();
};
struct Actor;
struct bhkCharacterController;
void __fastcall FUN_0057b1d0(char*, float);

}  // namespace fnv_0057b520

namespace fnv_00560870 {
class NiRTTI;
class NiAVObject;
int FUN_00408b20(const char*, const char*);
class NiFixedStr
{
  public:
    operator const char*() const;
};
struct SeqObj
{
    NiFixedStr& GetName();
};
bool FUN_0043b300(const NiRTTI*, NiAVObject*);
struct ArrSI
{
    unsigned int GetFlags();
};
void* DynamicCastByRTTI(const void*, void*);
class bhkWorldObject;
struct bhkCollisionObject
{
    bhkWorldObject* FUN_006fa820();
};
extern const void* const DAT_011f9140;

}  // namespace fnv_00560870

namespace fnv_00562660 {
struct Actor;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct BaseProcess;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct DialogueResponse;
struct ExtraDataList;
struct InventoryChanges;
struct InventoryIterator;
struct InventoryStackRecord;
struct MobileObject;
struct NiAVObject;
struct NiPoint3;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESForm;
struct TESIdleForm;
struct TESLevItem;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct bhkCharacterController;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

namespace N {
struct TerrainManager_r562660
{
    void FUN_006fcfa0(TESObjectREFR*, int);
};
struct TESForm
{
    void Revert(unsigned int);
    bool IsConstantGlobal();
};
struct InventoryChanges
{
    bool CreateForReference();
    static InventoryChanges* __cdecl CreateForReference(TESObjectREFR*);
    void FUN_004d42f0(BGSLoadFormBuffer*);
};
struct ExtraDataList
{
    void InitLoadGame(BGSLoadFormBuffer*, TESForm*);
};
struct TESWorldSpace
{
    TerrainManager_r562660* GetWorldTerrainManager();
};
struct FormChangeMask
{
    unsigned int iFlags;
    FormChangeMask(unsigned int);
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};
}
struct FUN_0056aac0_t
{
    TESObjectREFR* GetEnableParent();
};
struct RefH
{
    bool GetDisabled();
};
struct S
{
    void FUN_00484af0(bool);
    N::TESForm* _FNV_GetObjectReference();
};
struct XActor
{
    N::ExtraDataList* GetExtra() const;
};
struct ActorS
{
    N::TESWorldSpace* GetParentWorldSpace();
};
}  // namespace fnv_00562660

namespace fnv_00568500 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct NiStream;
struct Script;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FurnitureMark
{
    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
    char Position[12];
    unsigned short m_usMarkerId;
    unsigned char m_ucFlags;
    char _pad_f[1];
};
typedef char _sizecheck_FurnitureMark[sizeof(FurnitureMark) == 16 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

struct TESFurniture;
struct NiNode;
struct Pt3
{
    float x, y, z;
};
struct M3
{
    float m[9];
    M3();
};
struct RecipeCraftingInfo
{
    float a, b, c;
};
struct TESRecipe
{
    RecipeCraftingInfo* GetData();
};
struct FUN_00568650_shell
{
    float FUN_00568650();
};
void* __fastcall _ref_006815c0(FurnitureMark*);
void* __fastcall _FNV_GetObjectReference(void*);
int __fastcall _FNV_GetFormType(void*);

}  // namespace fnv_00568500

namespace fnv_00574920 {
struct ExtraDataList
{
    void RemoveExtraDataType0x15();
};
struct DropList_t
{
    bool FUN_008256d0();
    TESObjectREFR** FUN_006815c0();
    void FUN_0063f7b0();
};
struct ShellH : ExtraDataList
{
    DropList_t* FUN_0041df90();
    void FUN_0041de40(TESObjectREFR*);
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct InventoryChanges
{
    static InventoryChanges* __cdecl CreateForReference(TESObjectREFR*);
    void FUN_004d17a0();
    void FUN_004d1440();
    void FUN_004d1610();
    void FUN_004d1960();
    bool FUN_0042cde0();
};
struct RefV
{
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
    virtual bool v100();
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
    virtual bool v160();
    bool FUN_00577de0();
    void FUN_00572270();
};

}  // namespace fnv_00574920

namespace fnv_00579160 {
struct ExtraDataList;
struct FUN_0042ede0_shell
{
    ExtraDataList* FUN_0042ede0();
};
struct XActor
{
    ExtraDataList* GetExtra() const;
};
struct TESTopicInfo
{
    void RunResultScript(int, XActor*);
};
struct SC_008c48d0
{
    static bool GetLocalData(void*, ExtraDataList*, unsigned int);
};
bool __fastcall FUN_00579200(const char*);

}  // namespace fnv_00579160

namespace fnv_0055d3b0 {
struct ShellH
{
    int FUN_004216f0();
    ShellH* GetFirstExtraData();
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct TESBoundObject
{
    void* _FNV_GetObjectReference();
};
}  // namespace fnv_0055d3b0

struct FUN_0055ebf0
{
    unsigned char m0;
    unsigned short m1;
    unsigned short m2;
    unsigned int m3;
    unsigned int m4;
    unsigned int m5;
    FUN_0055ebf0();
};

// Initializes all six members of the object to zero.
// @fnv 0x0055ebf0
FUN_0055ebf0::FUN_0055ebf0()
{
    m0 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    m5 = 0;
}

struct FUN_00562e70
{
    unsigned char b0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    FUN_00562e70();
};

// Initializes the object's byte and seven integer fields to zero.
// @fnv 0x00562e70
FUN_00562e70::FUN_00562e70()
{
    b0 = 0;
    a1 = 0;
    a2 = 0;
    a3 = 0;
    a4 = 0;
    a5 = 0;
    a6 = 0;
    a7 = 0;
}

namespace fnv_005649b0 {
struct ArrSI
{
    unsigned int GetFlags();
    bool FUN_005649b0();
};
struct FNV_GetObjectReference
{
    void* FUN_005649b0();
};
struct FNV_GetFormType
{
    unsigned int FUN_005649b0();
};
}  // namespace fnv_005649b0

namespace fnv_00564b00 {

struct ArrSI
{
    unsigned int GetFlags();
};

struct TESObjectREFR_Flags
{
    void SetFlags(unsigned int flags);
};

}  // namespace fnv_00564b00

namespace fnv_00564eb0 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct TESObjectREFR_Flags
{
    void SetFlags(unsigned int);
    void FUN_00564eb0(bool set);
};

}  // namespace fnv_00564eb0

namespace fnv_00567ad0 {
struct ExtraL
{
    void FUN_00419700(void*);
};
struct ShellH
{
    void FUN_00419700(void*);
};
struct Flt
{
    operator unsigned int();
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct RadioData : Flt
{
};
struct FUN_00567ad0 : TESObjectREFR
{
    void SetOwner(void* apOwner);
    ShellH* GetExtra() const;
    RadioData* GetExtraRadioData();
    // slot 0 is TESObjectREFR::~TESObjectREFR (made virtual by 71bb6ecefd)
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
    virtual void v048(unsigned int);
};

}  // namespace fnv_00567ad0

namespace fnv_00569000 {
struct Flt
{
    operator unsigned int();
};
struct TgtOps
{
    void* GetSourceFiles();
};
struct NiPoint3
{
    float x, y, z;
};
extern NiPoint3 _NiPoint3_ZERO;
struct TESObjectREFR_ext : TESObjectREFR
{
    void* GetExtraRadioData();
    void* FUN_00569000();
};
}  // namespace fnv_00569000

namespace fnv_005690a0 {
struct LockExtraData;
struct ShellH
{
    void FUN_00419050(LockExtraData*);
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct TESObjectREFR_ext
{
    LockExtraData* GetMyLock();
    LockExtraData* FUN_005690a0();
};
}  // namespace fnv_005690a0

namespace fnv_0056aa10 {
struct FUN_0056aac0_t
{
    TESObjectREFR* GetEnableParent();
};
struct XActor
{
    void* GetExtra() const;
};
}  // namespace fnv_0056aa10

namespace fnv_0056c810 {
struct GO
{
    int m_i;
    GO(int v);
    ~GO();
};
}  // namespace fnv_0056c810

namespace fnv_005726e0 {
struct NiAVObject
{
    void SetAppCulled(bool);
};
struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, const char*);
};
}  // namespace fnv_005726e0

namespace fnv_00572820 {
struct ReferenceLightData;
struct BSExtraData;
struct ShellH;
struct XActor
{
    ShellH* GetExtra() const;
};
struct Holder
{
    ReferenceLightData* FUN_00418250();
};
struct FUN_00418280_Class
{
    BSExtraData* FUN_00418280();
};

}  // namespace fnv_00572820

namespace fnv_005754a0 {
struct FUN_00740960_Class
{
    unsigned int FUN_00740960();
};
extern FUN_00740960_Class* g_dataHandler;
struct TESContainer;
struct TESObjectREFR;
struct InventoryChanges
{
    static InventoryChanges* __cdecl CreateForReference(TESObjectREFR*);
    void* FUN_004c94f0(int);
};
TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);
}  // namespace fnv_005754a0

bool __fastcall FUN_00579200(char const*);
class Character;
struct TESTopicInfo
{
    void AddTopicList();
    void RunResultScript(int, Character*);
};
struct FUN_0083c850
{
    int m0;
    int m4;
    int m8;
    TESTopicInfo* mInfo;
    int m10;
    int m14;
    int m18;
    void AppendTopicInfo(int);
};

namespace fnv_008cfa40 {
struct NiFixedString
{
    const char* m_sString;
    NiFixedString(const char* s) : m_sString(s)
    {}
    ~NiFixedString();
};
struct BSFadeNode
{
    NiFixedString m_sName;
    BSFadeNode(const char* name) : m_sName(name)
    {}
};
struct NiAVObject
{
    void SetName(const NiFixedString&);
};
struct FUN_009335b0_cls
{
    NiAVObject* FUN_009335b0(unsigned char);
    NiAVObject* FUN_008cfa40(unsigned char a);
};
}  // namespace fnv_008cfa40

namespace fnv_00578250 {
struct NiAVObject
{
    virtual ~NiAVObject();
    virtual void v1();
    virtual void v2();
    virtual NiAVObject* GetAsNiNode();
};
}  // namespace fnv_00578250

class PointerFlagNode;

namespace fnv_0055ac90 {
struct TESBoundObject;

struct FUN_004121b0_shell
{
    bool FUN_004121b0();
};

struct BGSSaveLoadGame : public FUN_004121b0_shell
{
};

struct FUN_0057c300_cls
{
    void FUN_0057c300();
};

void* memset(void* destination, int value, unsigned int count);

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

}  // namespace fnv_0055ac90

struct NiNode;
struct NiRTTI;
struct NiControllerManager;

struct Model
{
    NiNode* GetObject3D(void);
};

struct P09H
{
    Model* GetReferenceType(void);
};

extern NiRTTI DAT_011f36ac;
void* __cdecl _UseSaveGameBlocks(NiRTTI*, void*);

class NiFixedStr
{
  public:
    operator char const*();
};

class SeqObj
{
  public:
    NiFixedStr& GetName();
};

class FUN_004efb10_shell : public SeqObj
{
  public:
    unsigned short FUN_004efb10();
};

class Idle_008b2010 : public FUN_004efb10_shell
{
  public:
    Idle_008b2010* GetState();
};

class AnimationInterpolatorNode
{
  public:
    bool FUN_004f05a0();
    unsigned int FUN_00495d00();
    Idle_008b2010* FUN_00495d20(unsigned int index);
};

namespace fnv_005609b0 {
struct ScriptLocalsX
{
    void* GetLocalData(void);
};

struct FUN_005609f0_shell
{
    bool FUN_005609f0(void);
};

struct hkpEntity
{
    FUN_005609f0_shell* FUN_00c9bff0(unsigned char* flag);
};

struct bhkRigidBody
{
    bool FUN_005609b0();
};

}  // namespace fnv_005609b0

namespace fnv_00562140 {
struct FormChangeMask
{
    unsigned int value;

    operator bool() const;
};

struct FormChangeRecord
{
    void FUN_005621f0(unsigned int flags);
};

struct BGSLoadFormBuffer : FormChangeRecord
{
    FormChangeMask GetChangeFlags(unsigned int flags);
};

struct BGSSaveFormBuffer : BGSLoadFormBuffer
{
};

struct TESForm
{
    virtual void V00()
    {}
    virtual void V01()
    {}
    virtual void V02()
    {}
    virtual void V03()
    {}
    virtual void V04()
    {}
    virtual void V05()
    {}
    virtual void V06()
    {}
    virtual void V07()
    {}
    virtual void V08()
    {}
    virtual void V09()
    {}
    virtual void V10()
    {}
    virtual void V11()
    {}
    virtual void V12()
    {}
    virtual void V13()
    {}
    virtual void V14()
    {}
    virtual void V15()
    {}
    virtual void V16()
    {}
    virtual void V17()
    {}
    virtual void V18()
    {}
    virtual void V19()
    {}
    virtual void V20()
    {}
    virtual void V21()
    {}
    virtual void V22()
    {}
    virtual void V23()
    {}
    virtual void V24()
    {}
    virtual void V25()
    {}
    virtual void V26()
    {}
    virtual void V27()
    {}
    virtual void V28()
    {}
    virtual void V29()
    {}
    virtual void V30()
    {}
    virtual void V31()
    {}
    virtual void V32()
    {}
    virtual void V33()
    {}
    virtual void V34()
    {}
    virtual void V35()
    {}
    virtual void V36()
    {}
    virtual void V37()
    {}
    virtual void V38()
    {}
    virtual void V39()
    {}
    virtual void V40()
    {}
    virtual void V41()
    {}
    virtual void V42()
    {}
    virtual void V43()
    {}
    virtual void V44()
    {}
    virtual void V45()
    {}
    virtual void V46()
    {}
    virtual void V47()
    {}
    virtual void V48()
    {}
    virtual void V49()
    {}
    virtual void V50()
    {}
    virtual void V51()
    {}
    virtual void V52()
    {}
    virtual void V53()
    {}
    virtual void V54()
    {}
    virtual void V55()
    {}
    virtual void V56()
    {}
    virtual void V57()
    {}
    virtual void V58()
    {}
    virtual void V59()
    {}
    virtual void V60()
    {}
    virtual void V61()
    {}
    virtual void V62()
    {}
    virtual void V63()
    {}
    virtual unsigned char V64()
    {
        return 0;
    }

    void Revert(unsigned int flags);
};

struct P09H : TESForm
{
    int GetReferenceType();
};

struct FUN_005621d0_shell
{
    bool FUN_005621d0();
};

struct BGSSaveLoadGame : FUN_005621d0_shell
{
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

}  // namespace fnv_00562140

namespace fnv_00563650 {
struct NiRTTI
{
};

extern NiRTTI DAT_011f36ac;

struct NiNode
{
};

struct NiAVObject : public NiNode
{
};

struct Model
{
    NiNode* GetObject3D();
};

struct NiControllerManager : public Model
{
};

struct P09H
{
    int GetReferenceType();
};

struct XActor
{
    void* GetExtra() const;
};

struct BGSSaveGameBuffer
{
    void SaveGameString(char const* value, int flag);
};

struct BGSSaveFormBuffer : public BGSSaveGameBuffer
{
};

char* _UseSaveGameBlocks(NiRTTI* rtti, void* object);

}  // namespace fnv_00563650

namespace fnv_00563f30 {
struct BGSSaveFormBuffer;

struct FUN_004efc90_shell
{
    void FUN_004efc90(BGSSaveFormBuffer* buffer, float value);
};

struct NiFixedStr
{
    operator char const*();
};

struct SeqObj : public FUN_004efc90_shell
{
    NiFixedStr& GetName();
};

struct Idle_008b2010 : public SeqObj
{
    Idle_008b2010* GetState();
};

struct AnimationInterpolatorNode
{
    bool FUN_004f05a0();
    unsigned int FUN_00495d00();
    Idle_008b2010* FUN_00495d20(int index);
};

struct BGSSaveGameBuffer
{
    void SaveGameString(char const* value, int flag);
};

struct BGSSaveFormBuffer : public BGSSaveGameBuffer
{
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int value, unsigned int count);
};

float DAT_011c3c08;

}  // namespace fnv_00563f30

enum ENUM_FORM_ID
{
    ENUM_FORM_ID_DUMMY = 0
};

namespace fnv_00564f40 {
class BSExtraData
{
  public:
    virtual ~BSExtraData()
    {}
    unsigned char pad[0x10];
};

class BaseExtraList
{
  public:
    BSExtraData* AddExtra(BSExtraData* extra);
    void RemoveExtra(unsigned int type);
};

class MagicCaster
{
  public:
    void SetSelectedMagicItem(int spell);
};

int __fastcall _ref_0084e3a0(void* object);

class XActor : public TESObjectREFR
{
  public:
    BSExtraData* GetExtraData(unsigned char type) const;
    void* GetExtra() const;

    // slot 0 is TESObjectREFR::~TESObjectREFR (made virtual by 71bb6ecefd)
    virtual void VirtualMethod1()
    {}
    virtual void VirtualMethod2()
    {}
    virtual void VirtualMethod3()
    {}
    virtual void VirtualMethod4()
    {}
    virtual void VirtualMethod5()
    {}
    virtual void VirtualMethod6()
    {}
    virtual void VirtualMethod7()
    {}
    virtual void VirtualMethod8()
    {}
    virtual void VirtualMethod9()
    {}
    virtual void VirtualMethod10()
    {}
    virtual void VirtualMethod11()
    {}
    virtual void VirtualMethod12()
    {}
    virtual void VirtualMethod13()
    {}
    virtual void VirtualMethod14()
    {}
    virtual void VirtualMethod15()
    {}
    virtual void VirtualMethod16()
    {}
    virtual void VirtualMethod17()
    {}
    virtual void VirtualMethod18(unsigned int value)
    {}

    void FUN_00564f40(unsigned char value);
};

}  // namespace fnv_00564f40

namespace fnv_00565480 {
struct TESObjectCELL
{
    bool IsInterior();
};

struct ArrSI
{
    unsigned int GetFlags();
    void SetFlags(unsigned int flags);
};

struct FUN_00588030_shell
{
    void FUN_00588030(TESObjectREFR* object);
};

struct TESWorldSpace : public FUN_00588030_shell
{
    void AddPersistentReference(TESObjectREFR* object);
};

struct RefPersistsStandin
{
// @fnv 0x00565480
    virtual void FUN_00565480_v00()
    {}
    virtual void FUN_00565480_v01()
    {}
    virtual void FUN_00565480_v02()
    {}
    virtual void FUN_00565480_v03()
    {}
    virtual void FUN_00565480_v04()
    {}
    virtual void FUN_00565480_v05()
    {}
    virtual void FUN_00565480_v06()
    {}
    virtual void FUN_00565480_v07()
    {}
    virtual void FUN_00565480_v08()
    {}
    virtual void FUN_00565480_v09()
    {}
    virtual void FUN_00565480_v10()
    {}
    virtual void FUN_00565480_v11()
    {}
    virtual void FUN_00565480_v12()
    {}
    virtual void FUN_00565480_v13()
    {}
    virtual void FUN_00565480_v14()
    {}
    virtual void FUN_00565480_v15()
    {}
    virtual void FUN_00565480_v16()
    {}
    virtual void FUN_00565480_v17()
    {}
    virtual void FUN_00565480_v18(int)
    {}
    virtual void FUN_00565480_v19()
    {}
    virtual void FUN_00565480_v20()
    {}
    virtual void FUN_00565480_v21()
    {}
    virtual void FUN_00565480_v22()
    {}
    virtual void FUN_00565480_v23()
    {}
    virtual void FUN_00565480_v24()
    {}
    virtual void FUN_00565480_v25()
    {}
    virtual void FUN_00565480_v26()
    {}
    virtual void FUN_00565480_v27()
    {}
    virtual void FUN_00565480_v28()
    {}
    virtual void FUN_00565480_v29()
    {}
    virtual void FUN_00565480_v30()
    {}
    virtual void FUN_00565480_v31()
    {}
    virtual void FUN_00565480_v32()
    {}
    virtual void FUN_00565480_v33()
    {}
    virtual void FUN_00565480_v34()
    {}
    virtual void FUN_00565480_v35()
    {}
    virtual void FUN_00565480_v36()
    {}
    virtual void FUN_00565480_v37()
    {}
    virtual void FUN_00565480_v38()
    {}
    virtual void FUN_00565480_v39()
    {}
    virtual void FUN_00565480_v40()
    {}
    virtual void FUN_00565480_v41()
    {}
    virtual void FUN_00565480_v42()
    {}
    virtual void FUN_00565480_v43()
    {}
    virtual void FUN_00565480_v44()
    {}
    virtual void FUN_00565480_v45()
    {}
    virtual void FUN_00565480_v46()
    {}
    virtual void FUN_00565480_v47()
    {}
    virtual void FUN_00565480_v48()
    {}
    virtual void FUN_00565480_v49()
    {}
    virtual void FUN_00565480_v50(int)
    {}

    void FUN_00565480(bool abVal);
};

}  // namespace fnv_00565480

namespace fnv_005678a0 {
struct TESForm
{
};

struct TESFaction : public TESForm
{
    bool FUN_0047d7c0();
};

struct TESNPC : public TESForm
{
};

struct TESBoundObject : public TESForm
{
};

struct TESActorBaseData
{
    bool GetGhostFlag();
};

unsigned int __fastcall _FNV_GetFormType(TESForm* form);
TESBoundObject* __fastcall _FNV_GetObjectReference(void* self);

}  // namespace fnv_005678a0

namespace fnv_00567f40 {
struct Actor
{
};

struct ActorCause
{
};

class XActor
{
  public:
    void* GetExtra(void) const;
};

struct FUN_00567f40_class
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual ActorCause* f18(unsigned int value)
    {
        return 0;
    }

    ActorCause* FUN_00567f40(Actor* actor);
};

}  // namespace fnv_00567f40

namespace fnv_00568e70 {
struct ExtraRadioData
{
    unsigned char data[0x20];
};

struct FUN_0043a160
{
    unsigned char data[0x20];

    FUN_0043a160()
    {}
};

struct ExtraDataList
{
    ExtraRadioData* GetExtraRadioData();
    void FUN_00419120(ExtraRadioData* radioData);
};

struct XActor
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18(unsigned int value)
    {}

    void* GetExtra() const;
    ExtraRadioData* FUN_00568e70();
};

}  // namespace fnv_00568e70

namespace fnv_00569990 {
struct XActor
{
    void* GetExtra(void) const;
};

struct ExtraData
{
    void FUN_00422050(int value);
};

}  // namespace fnv_00569990

namespace fnv_00569ae0 {
struct FUN_00439f90_shell : public TESObjectREFR
{
    bool FUN_00439f90();
};

struct XActor
{
    void* GetExtra() const;
    void FUN_00569ae0(FUN_00439f90_shell* object);
};

}  // namespace fnv_00569ae0

namespace fnv_0056a470 {
class NiPoint3;

struct XActor
{
    void* GetExtra(void) const;
    void FUN_0056a470(TESObjectREFR* object, NiPoint3 const& point1, NiPoint3 const& point2);
};

}  // namespace fnv_0056a470

struct P3
{
    float x;
    float y;
    float z;

    void Set(float, float, float);
};

struct NiPoint3 : public P3
{
    void ComputeMagnitude();
};

struct ThreeByThreeMatrix
{
    float matrix[9];

    void _ref_006815c0();
    void FUN_004a0c90(float);
    NiPoint3 operator*(NiPoint3 const&) const;
};

struct RecipeCraftingInfo
{
    float field00;
    float field04;
    float field08;
};

struct TESRecipe
{
    RecipeCraftingInfo* GetData();
    NiPoint3* FUN_00572500(NiPoint3*, float);
};

float __cdecl WrapAngle(float);

namespace fnv_00572770 {
void FUN_00418f60();

struct GO
{
  public:
    unsigned char pad;
    float value;

    void operator=(void* value);
};

struct FUN_005726c0 : public GO
{
  public:
    FUN_005726c0();
};

struct ExtraData
{
  public:
    void FUN_00418f60();
};

struct XActor
{
  public:
    ExtraData* GetExtra(FUN_005726c0* object) const;
    void FUN_00572770(void* value);
};

}  // namespace fnv_00572770

namespace fnv_00573050 {
struct BGSBodyPart
{
    enum LIMB_ENUM
    {
        LIMB_HEAD = 0
    };
};

struct ExtraDismemberedLimbs
{
    void FUN_004305f0(int limb, bool removed);
};

struct ExtraDataList
{
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};

struct XActor
{
    void* GetExtra() const;
    void FUN_00573050(BGSBodyPart::LIMB_ENUM aeLimb, bool abRemoved);
};

}  // namespace fnv_00573050

namespace fnv_00573110 {
struct BGSBodyPart
{
    enum LIMB_ENUM
    {
        LIMB_ENUM_NONE = 0
    };
};

class Calendar
{
  public:
    int GetDaysPassed();
};

class ExtraDismemberedLimbs : public Calendar
{
};

class ExtraDataList
{
  public:
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};

class XActor
{
  public:
    void* GetExtra() const;
};

}  // namespace fnv_00573110

namespace fnv_00577c40 {
struct ScriptLocalsX
{
    void* GetLocalData();
    void FUN_00577c40(float value);
};

}  // namespace fnv_00577c40

namespace fnv_00577c70 {
class TgtOps
{
  public:
    void* GetSourceFiles();
};

typedef TgtOps BSSimpleList_Ragdoll;

class TESDataHandler
{
  public:
    BSSimpleList_Ragdoll* GetBGSRagdollList();
};

class Dummy_00577bd0 : public TESDataHandler
{
  public:
    void FUN_00ca9360(float* value);
    void FUN_00577c70(float value);
};

}  // namespace fnv_00577c70

namespace fnv_00578870 {
struct BSStr
{
    bool Set(char const* value, unsigned int length);
};

struct FNStub
{
    char* GetFullName();
};

struct TESObjectCELL
{
    unsigned char padding[0x18];
    FNStub fnStub;

    bool IsInterior();
};

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct TESWorldSpaceVirtualBase
{
    virtual void f000() = 0;
    virtual void f001() = 0;
    virtual void f002() = 0;
    virtual void f003() = 0;
    virtual void f004() = 0;
    virtual void f005() = 0;
    virtual void f006() = 0;
    virtual void f007() = 0;
    virtual void f008() = 0;
    virtual void f009() = 0;
    virtual void f010() = 0;
    virtual void f011() = 0;
    virtual void f012() = 0;
    virtual void f013() = 0;
    virtual void f014() = 0;
    virtual void f015() = 0;
    virtual void f016() = 0;
    virtual void f017() = 0;
    virtual void f018() = 0;
    virtual void f019() = 0;
    virtual void f020() = 0;
    virtual void f021() = 0;
    virtual void f022() = 0;
    virtual void f023() = 0;
    virtual void f024() = 0;
    virtual void f025() = 0;
    virtual void f026() = 0;
    virtual void f027() = 0;
    virtual void f028() = 0;
    virtual void f029() = 0;
    virtual void f030() = 0;
    virtual void f031() = 0;
    virtual void f032() = 0;
    virtual void f033() = 0;
    virtual void f034() = 0;
    virtual void f035() = 0;
    virtual void f036() = 0;
    virtual void f037() = 0;
    virtual void f038() = 0;
    virtual void f039() = 0;
    virtual void f040() = 0;
    virtual void f041() = 0;
    virtual void f042() = 0;
    virtual void f043() = 0;
    virtual void f044() = 0;
    virtual void f045() = 0;
    virtual void f046() = 0;
    virtual void f047() = 0;
    virtual void f048() = 0;
    virtual void f049() = 0;
    virtual void f050() = 0;
    virtual void f051() = 0;
    virtual void f052() = 0;
    virtual void f053() = 0;
    virtual void f054() = 0;
    virtual void f055() = 0;
    virtual void f056() = 0;
    virtual void f057() = 0;
    virtual void f058() = 0;
    virtual void f059() = 0;
    virtual void f060() = 0;
    virtual void f061() = 0;
    virtual void f062() = 0;
    virtual void f063() = 0;
    virtual void f064() = 0;
    virtual void f065() = 0;
    virtual void f066() = 0;
    virtual void f067() = 0;
    virtual void f068() = 0;
    virtual void f069() = 0;
    virtual void f070() = 0;
    virtual void f071() = 0;
    virtual void f072() = 0;
    virtual void f073() = 0;
    virtual void f074() = 0;
    virtual void f075() = 0;
    virtual void f076() = 0;
    virtual void f077() = 0;

    virtual void vfn_138(BSStr* name, NiPoint3 position) = 0;
};

struct TESWorldSpace : public TESWorldSpaceVirtualBase
{
};

struct BSOcclusionPlane
{
    int GetCullResult() const;
};

struct ActorS
{
    TESWorldSpace* GetParentWorldSpace();
};

}  // namespace fnv_00578870

struct ExtraAnimNoteReceiver
{
    void FUN_0057a8d0();
    void* FUN_0057a8a0(unsigned int flags);
};

namespace fnv_0057b790 {
struct TESObjectCELL;

class TES
{
  public:
    bool IsCellBuffered(TESObjectCELL* cell, bool force);
};

extern int g_TES;

}  // namespace fnv_0057b790

struct TESObjectCELL;
struct Pt3
{
    float x;
    float y;
    float z;
    Pt3();
};
struct RefX
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
    virtual Pt3* GetPos();
    RefX();
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
    TESObjectCELL* GetParentCell();
    void SetLocationOnReference(const Pt3&);
    void FUN_00575690(void*);
    void* GetAcousticSpace();
    void FUN_00567ad0(void*);
};
extern RefX* g_thePlayer;
struct TESObjectCELL
{
    void FUN_0054d090(Pt3*, Pt3*);
    void FUN_005512f0(RefX*);
    void AddReference(RefX*, bool);
    RefX* FUN_00551180(RefX* ref);
};

struct SaveLoadStub
{
    bool IsLoading();
};
extern SaveLoadStub* g_BGSSaveLoadGame;

struct ExtraStub
{
};
struct CellStub
{
};

struct ExtraListStub
{
    ExtraStub* GetExtraData(unsigned char type);
    void Remove(ExtraStub* extra, bool free);
    ExtraStub* AddExtra(ExtraStub* extra);
};

struct ExtraList44
{
    CellStub* GetContainingCell();
    void SetA(bool b);
    void SetB(bool b);
    void InitializeForCell(CellStub* c);
};

struct RefStub
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
    virtual void v00A();
    virtual void v00B();
    virtual void v00C();
    virtual void v00D();
    virtual void v00E();
    virtual void v00F();
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
    virtual void v01A();
    virtual void v01B();
    virtual void v01C();
    virtual void v01D();
    virtual void v01E();
    virtual void v01F();
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
    virtual void v02A();
    virtual void v02B();
    virtual void v02C();
    virtual void v02D();
    virtual void v02E();
    virtual void v02F();
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
    virtual void v03A();
    virtual void v03B();
    virtual void v03C();
    virtual void v03D();
    virtual void v03E();
    virtual void v03F();
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
    virtual void v04A();
    virtual void v04B();
    virtual void v04C();
    virtual void v04D();
    virtual void v04E();
    virtual void v04F();
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
    virtual void v05A();
    virtual void v05B();
    virtual void v05C();
    virtual void v05D();
    virtual void v05E();
    virtual void v05F();
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
    virtual void v06A();
    virtual void v06B();
    virtual void v06C();
    virtual void v06D();
    virtual void v06E();
    virtual void v06F();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void Update(int a, int b);
    virtual int hkClassMember_isNotOwner();
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
    ExtraList44 extraList;

    void Func56b0b0();
    void Func572a50(int a);
    void Func57b520(int a);
    ExtraListStub* GetExtraList();
    void FUN_0055ad20();
};

extern unsigned int kGroupFormType;

struct Loc5604
{
    int unk00;
    unsigned char flag04;
    int kind08;
    void* target0c;
    int unk10;
    int unk14;
    int unk18;
};

int FUN_00c68900(void* p, Loc5604* loc, void (*fn)());

void* FUN_00458b20();

namespace fnv_00561b40 {
struct RttiX;
struct FixStr
{
    operator const char*() const;
};
struct AvObj
{
    FixStr& GetName();
};
struct Mat33
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct Pt3
{
    float x, y, z;
    Pt3();
};
struct QuatX
{
    float w, x, y, z;
    QuatX();
    void FUN_00a6df40(const Mat33& m);
};
struct WorldObjX;
struct CtrlX
{
    void FUN_005610f0(Pt3* p);
    void FUN_00561150(QuatX* q);
    void FUN_005615d0(Pt3* p);
    void FUN_00561630(Pt3* p);
    void FUN_00561580(bool b);
};
struct RefX
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
    virtual void SetFlagsB0(int a, int b, int c);
    WorldObjX* FUN_006fa820();
    void FUN_004d9fa0(bool b);
    AvObj* Get3D();
};
struct SaveLoadX
{
    unsigned char FUN_008df040();
    void FUN_008579e0(void* buf, unsigned int size);
};
extern SaveLoadX* g_TESSaveLoadGame;
extern RttiX DAT_011f9140;
extern RttiX DAT_012681c0;
extern Pt3 NiPoint3_ZERO;
int FUN_00408b20(const char* a, const char* b);
bool FUN_0043b300(const RttiX* rtti, AvObj* obj);
CtrlX* FUN_00653270(const RttiX* rtti, WorldObjX* obj);

}  // namespace fnv_00561b40

struct WorldPoint
{
    float x, y, z;
    void FUN_006815c0();
};
struct ReferenceObject
{
    bool FUN_00425fd0();
};
struct SecondaryObject
{
    ReferenceObject* FUN_00587550(WorldPoint*);
};
struct SearchTable
{
    bool FUN_004511e0(ReferenceObject*, int);
};
extern SearchTable* DAT_011dea10;
void __cdecl FUN_00573800(void*, ReferenceObject*, SecondaryObject*);

struct SettingsHolder
{
    unsigned char flags;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* m_10;
    void* m_14;
    void* m_18;
};

struct CallbackDesc
{
    unsigned int unk00;
    unsigned char bFlag;
    unsigned int nValue;
    SettingsHolder* pOwner;
};

void* __cdecl FUN_004a8b00(void* p);
void __cdecl FUN_00c68900(void* p, CallbackDesc* pDesc, void (*pfn)());

namespace fnv_00562ed0 {
struct NiPt3X
{
    float x;
    float y;
    float z;
};
extern const NiPt3X NiPoint3_ZERO;

struct UpdDataX
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    unsigned char m_ucEntryType;
    int unk08;
    UpdDataX(float afTime, bool abUpdateControllers, bool abMultiThreaded);
};

struct NiNode;
struct NiCollisionObject;
struct CollisionObjectCountContext
{
    int iCount;
    bool bFlag;
    int iType;
    void* pData;
    int unk10;
    int unk14;
    int unk18;
};

struct AVObjX
{
    void Update(UpdDataX& arData);
};

void __cdecl FUN_00c9b670(AVObjX*, const NiPt3X*, bool, float, int);
void __cdecl FUN_00c68900(AVObjX*, CollisionObjectCountContext*,
                          void(__cdecl*)(NiCollisionObject*, CollisionObjectCountContext*));

struct BooleanIntegerAccessor
{
    void FUN_00864980(bool* apOut, int aiUnk);
    int FUN_00864a60();
};

struct BoneCountData
{
    unsigned char bFlag;
    int iCount1;
    int iCount2;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    BooleanIntegerAccessor* pSaveData;
    BoneCountData();
};

struct bhkCharController
{
    void bhkRagdollController_DisableRagdollAnim(bool);
};

struct RefX
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
    virtual const char* GetName76();
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
    virtual bool V139(bool);
    virtual bool V140();
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
    virtual bool V186();
    AVObjX* Get3DSimple();
    unsigned int GetRefID();
    void FUN_00562d20(BoneCountData* apData);
    void FUN_00562ed0(BooleanIntegerAccessor* apSaveData);
};

struct ActorX : RefX
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
    bhkCharController* pCharCtrl;
    bool FUN_00437bd0();
};

}  // namespace fnv_00562ed0

struct FUN_00564c60_cls
{
    void FUN_00564c60(unsigned char flag);
    void FUN_00403550(int flags);
};

void* __fastcall FUN_007af430(FUN_00564c60_cls* self);
int __fastcall FUN_00401170(void* p);
int __fastcall FUN_0044ddc0(FUN_00564c60_cls* self);

class TESObjectREFR569;

class Data569;

class ExtraDataList569
{
  public:
    Data569* GetData();
    void SetData(Data569* pkData);
};

class TESObjectREFR569
{
  public:
    bool IsValid();
    bool IsDeleted() const;
    ExtraDataList569* GetExtraData();
    Data569* FUN_00569920();
};

class Ref5699;

struct LinkedRefNode5699
{
    Ref5699** GetItem();
    LinkedRefNode5699* GetNext();
};

struct LinkedRefData5699
{
    int unk00;
    int unk04;
    LinkedRefNode5699 list;
};

struct XList5699
{
    bool HasLinkedRefSlot();
    Ref5699* GetLinkedRefChild();
    void SetLinkedRefChild(Ref5699* ref);
    LinkedRefData5699* GetLinkedRefData();
    void AddLinkedRefParent(Ref5699* ref);
};

class Ref5699
{
  public:
    bool IsLinkable();
    bool IsDeleted();
    XList5699* GetExtraList();
    Ref5699* FUN_005699b0();
};

struct FUN_00569cb0_Class;
struct NetworkStream
{
    bool FUN_0057c850(FUN_00569cb0_Class* obj, unsigned char* flag);
    void FUN_005594e0(FUN_00569cb0_Class* obj, unsigned char flag);
};
struct NodeEntry
{
    bool FUN_008256d0();
    FUN_00569cb0_Class** FUN_006815c0();
    NodeEntry* FUN_00726070();
};
struct NodeCollection
{
    NodeEntry* FUN_0041e500();
};
struct FUN_00569cb0_Class
{
    FUN_00569cb0_Class* FUN_00569b80();
    void FUN_00569be0(unsigned char flag);
    NodeCollection* FUN_005d43c0();
    void FUN_00569cb0(unsigned char flag, NetworkStream* stream);
};

class B56ACB0Ref;

class B56ACB0ExtraList
{
  public:
    void FUN_0041e000(B56ACB0Ref* pkRef);
    void FUN_0041de40(B56ACB0Ref* pkRef);
};

class B56ACB0Ref
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void NotifyFormIDChanged(unsigned int uiFlags);
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual void VFunc100();
    virtual void VFunc104();
    virtual void VFunc108();
    virtual void VFunc10C();
    virtual void VFunc110();
    virtual void VFunc114();
    virtual void VFunc118();
    virtual void VFunc11C();
    virtual void VFunc120();
    virtual void VFunc124();
    virtual void VFunc128();
    virtual void VFunc12C();
    virtual void VFunc130();
    virtual void VFunc134();
    virtual void VFunc138();
    virtual void VFunc13C();
    virtual void VFunc140();
    virtual void VFunc144();
    virtual void VFunc148();
    virtual void VFunc14C();
    virtual void VFunc150();
    virtual void VFunc154();
    virtual void VFunc158();
    virtual void VFunc15C();
    virtual bool IsDeleted();

    bool FUN_005653d0();
    B56ACB0ExtraList* GetExtraData();
};

class FUN_0056d500_cls
{
  public:
    void FUN_00c9d620();
    FUN_0056d500_cls* FUN_0056d500(int nFlag);
};

void __cdecl FUN_00aa1460(FUN_0056d500_cls* pSelf, int nValue);

struct ListHead
{
    void* item;
    void* next;
    ListHead();
};

struct ListTail
{
    void* item;
    ListTail();
    void FUN_005407b0(int value);
};

struct GuardedMember
{
    void* value;
    GuardedMember();
    ~GuardedMember();
};

struct FUN_0056e1e0
{
    ListHead head;
    ListTail tail;
    GuardedMember guarded;
    FUN_0056e1e0();
};

// @fnv 0x0056e1e0
FUN_0056e1e0::FUN_0056e1e0()
{
    head.item = 0;
    head.next = 0;
    tail.FUN_005407b0(1);
}

// FUN_0056e3e0: constructor-like member that calls the base routine with
// `this`, installs the class vtable pointer into the object and bumps a
// global counter, then returns itself.

// FUN_0056e460 : thiscall member (1 stack param), /Od.
// Calls a member helper on this, then when the flag param has bit 0 set it
// hands this plus size 0x18 to the cdecl helper, and returns this.

void __cdecl FUN_00aa1460(void* pObject, unsigned int uSize);

// FUN_0056e6c0: constructor-like member that calls the base routine with
// `this`, installs the class vtable pointer into the object, bumps a global
// counter and returns itself.

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct ActorController
{
    void FUN_00498910(int mode, int flags);
    void FUN_00496080(int mode, float amount);
    struct FloatController* FUN_00496940(float amount);
    void* FUN_005585e0();
    void FUN_00499080();
};
struct FloatController
{
    void FUN_0048fef0();
};

struct TESContainer;
TESContainer* __fastcall FUN_0055d310(TESObjectREFR* reference);
struct SelectedObject
{
};
struct ObjectProvider
{
};
extern "C" ObjectProvider* DAT_011c3f2c;
extern "C" SelectedObject* __fastcall FUN_00740960(ObjectProvider* provider);
extern "C" SelectedObject* __cdecl FUN_004bf220(TESObjectREFR* reference);

class SpawnedNode
{
  public:
    SpawnedNode();
    void Configure(unsigned int a, unsigned int b);
    void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
    unsigned char pad[0x80];
};

struct NodeView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NodeView* AsNode();
    unsigned int FUN_009ee040();
    void FUN_00450f90(bool);
    bool FUN_00456610();
    unsigned int FUN_0043b480();
    NodeView* FUN_0043b4a0(unsigned int);
};
struct AddonView
{
    bool FUN_00448bf0();
    void* FUN_0059e300(NodeView*);
};
struct HandlerView
{
    AddonView* FUN_004617e0(unsigned int);
};
extern HandlerView* g_dataHandler;
extern unsigned int DAT_01202de8;
bool FUN_0043b300(const void*, NodeView*);

namespace fnv_00578400 {
struct NiRTTI;
extern NiRTTI DAT_01202de8;

struct FUN_00453470_shell
{
    int FUN_00453470();
};

class _FakeNiNode
{
  public:
    virtual void unk04();
    virtual void unk08();
    virtual void unk0A();
    virtual _FakeNiNode* unk0C();
    unsigned int FUN_0043b480();
    _FakeNiNode* FUN_0043b4a0(unsigned int index);
};

bool __cdecl FUN_0043b300(NiRTTI const* rtti, _FakeNiNode* obj);

}  // namespace fnv_00578400

struct FUN_00578790_obj0
{
    int m_unk00;
    FUN_00578790_obj0* Lookup(void* p, int flag);
};
extern FUN_00578790_obj0 DAT_011e0e80;

struct AnimationAction
{
    void FUN_00475b20();
};
AnimationAction* __cdecl FUN_00475400(unsigned int action);

struct ExtraDataHeader
{
    virtual ~ExtraDataHeader();
    ExtraDataHeader* next;
    unsigned int type;
};

struct ExtraDataPayload
{
    virtual ~ExtraDataPayload();
};

struct FUN_0057a8d0 : ExtraDataHeader
{
    ExtraDataPayload* payload;
    virtual ~FUN_0057a8d0();
};

// Destructor that deletes the owned payload if it is non-null.
// @fnv 0x0057a8d0
FUN_0057a8d0::~FUN_0057a8d0()
{
    if (payload)
        delete payload;
}

void* __fastcall FUN_008d6f30(void* p);
float __fastcall FUN_005471e0(void* p);
void* __fastcall FUN_009306d0(void* p);
void __fastcall FUN_0057b1d0(void* pThis, float afHeight);
extern float const DAT_01015f5c;

namespace fnv_006751a0 {
struct Cell;
struct Pkg;
struct Proc;

struct Ref
{
    virtual void rv000();
    virtual void rv004();
    virtual void rv008();
    virtual void rv00c();
    virtual void rv010();
    virtual void rv014();
    virtual void rv018();
    virtual void rv01c();
    virtual void rv020();
    virtual void rv024();
    virtual void rv028();
    virtual void rv02c();
    virtual void rv030();
    virtual void rv034();
    virtual void rv038();
    virtual void rv03c();
    virtual void rv040();
    virtual void rv044();
    virtual void rv048();
    virtual void rv04c();
    virtual void rv050();
    virtual void rv054();
    virtual void rv058();
    virtual void rv05c();
    virtual void rv060();
    virtual void rv064();
    virtual void rv068();
    virtual void rv06c();
    virtual void rv070();
    virtual void rv074();
    virtual void rv078();
    virtual void rv07c();
    virtual void rv080();
    virtual void rv084();
    virtual void rv088();
    virtual void rv08c();
    virtual void rv090();
    virtual void rv094();
    virtual void rv098();
    virtual void rv09c();
    virtual void rv0a0();
    virtual void rv0a4();
    virtual void rv0a8();
    virtual void rv0ac();
    virtual void rv0b0();
    virtual void rv0b4();
    virtual void rv0b8();
    virtual void rv0bc();
    virtual void rv0c0();
    virtual void rv0c4();
    virtual void rv0c8();
    virtual void rv0cc();
    virtual void rv0d0();
    virtual void rv0d4();
    virtual void rv0d8();
    virtual void rv0dc();
    virtual void rv0e0();
    virtual void rv0e4();
    virtual void rv0e8();
    virtual void rv0ec();
    virtual void rv0f0();
    virtual void rv0f4();
    virtual void rv0f8();
    virtual void rv0fc();
    virtual void rv100();
    virtual void rv104();
    virtual void rv108();
    virtual void rv10c();
    virtual void rv110();
    virtual void rv114();
    virtual void rv118();
    virtual void rv11c();
    virtual void rv120();
    virtual void rv124();
    virtual void rv128();
    virtual void rv12c();
    virtual void rv130();
    virtual void rv134();
    virtual void rv138();
    virtual void rv13c();
    virtual void rv140();
    virtual void rv144();
    virtual void rv148();
    virtual void rv14c();
    virtual void rv150();
    virtual void rv154();
    virtual void rv158();
    virtual void rv15c();
    virtual void rv160();
    virtual void rv164();
    virtual void rv168();
    virtual void rv16c();
    virtual void rv170();
    virtual void rv174();
    virtual void rv178();
    virtual void rv17c();
    virtual void rv180();
    virtual void rv184();
    virtual void rv188();
    virtual void rv18c();
    virtual void rv190();
    virtual void rv194();
    virtual void rv198();
    virtual void rv19c();
    virtual void rv1a0();
    virtual void rv1a4();
    virtual void rv1a8();
    virtual void rv1ac();
    virtual void rv1b0();
    virtual void rv1b4();
    virtual void rv1b8();
    virtual void rv1bc();
    virtual void rv1c0();
    virtual void rv1c4();
    virtual void rv1c8();
    virtual void rv1cc();
    virtual void rv1d0();
    virtual void rv1d4();
    virtual void rv1d8();
    virtual void rv1dc();
    virtual void rv1e0();
    virtual void rv1e4();
    virtual void rv1e8();
    virtual void rv1ec();
    virtual void rv1f0();
    virtual void rv1f4();
    virtual void rv1f8();
    virtual void rv1fc();
    virtual void rv200();
    virtual void rv204();
    virtual void rv208();
    virtual void rv20c();
    virtual void rv210();
    virtual void rv214();
    virtual void rv218();
    virtual void rv21c();
    virtual void rv220();
    virtual void rv224();
    virtual void rv228();
    virtual void rv22c();
    virtual void rv230();
    virtual void rv234();
    virtual void rv238();
    virtual void rv23c();
    virtual void rv240();
    virtual void rv244();
    virtual void rv248();
    virtual void rv24c();
    virtual void rv250();
    virtual void rv254();
    virtual void rv258();
    virtual void rv25c();
    virtual void rv260();
    virtual void rv264();
    virtual void rv268();
    virtual void rv26c();
    virtual void rv270();
    virtual void rv274();
    virtual void rv278();
    virtual void rv27c();
    virtual void rv280();
    virtual void rv284();
    virtual void rv288();
    virtual void rv28c();
    virtual void rv290();
    virtual void rv294();
    virtual Cell* GetCell298();
    Cell* GetParentCell();
    Ref* GetLinkedRef();
    Proc* GetProcess();
    Cell* GetCell56ad80();
};

struct Proc
{
    virtual void pv000();
    virtual void pv004();
    virtual void pv008();
    virtual void pv00c();
    virtual void pv010();
    virtual void pv014();
    virtual void pv018();
    virtual void pv01c();
    virtual void pv020();
    virtual void pv024();
    virtual void pv028();
    virtual void pv02c();
    virtual void pv030();
    virtual void pv034();
    virtual void pv038();
    virtual void pv03c();
    virtual void pv040();
    virtual void pv044();
    virtual void pv048();
    virtual void pv04c();
    virtual void pv050();
    virtual void pv054();
    virtual void pv058();
    virtual void pv05c();
    virtual void pv060();
    virtual void pv064();
    virtual void pv068();
    virtual void pv06c();
    virtual void pv070();
    virtual void pv074();
    virtual void pv078();
    virtual void pv07c();
    virtual void pv080();
    virtual void pv084();
    virtual void pv088();
    virtual void pv08c();
    virtual void pv090();
    virtual void pv094();
    virtual void pv098();
    virtual void pv09c();
    virtual void pv0a0();
    virtual void pv0a4();
    virtual void pv0a8();
    virtual void pv0ac();
    virtual void pv0b0();
    virtual void pv0b4();
    virtual void pv0b8();
    virtual void pv0bc();
    virtual void pv0c0();
    virtual void pv0c4();
    virtual void pv0c8();
    virtual void pv0cc();
    virtual void pv0d0();
    virtual void pv0d4();
    virtual void pv0d8();
    virtual void pv0dc();
    virtual void pv0e0();
    virtual void pv0e4();
    virtual void pv0e8();
    virtual void pv0ec();
    virtual void pv0f0();
    virtual void pv0f4();
    virtual void pv0f8();
    virtual void pv0fc();
    virtual void pv100();
    virtual void pv104();
    virtual void pv108();
    virtual void pv10c();
    virtual void pv110();
    virtual void pv114();
    virtual void pv118();
    virtual void pv11c();
    virtual void pv120();
    virtual void pv124();
    virtual void pv128();
    virtual void pv12c();
    virtual void pv130();
    virtual void pv134();
    virtual void pv138();
    virtual void pv13c();
    virtual void pv140();
    virtual void pv144();
    virtual void pv148();
    virtual void pv14c();
    virtual void pv150();
    virtual void pv154();
    virtual void pv158();
    virtual void pv15c();
    virtual void pv160();
    virtual void pv164();
    virtual void pv168();
    virtual void pv16c();
    virtual void pv170();
    virtual void pv174();
    virtual void pv178();
    virtual void pv17c();
    virtual void pv180();
    virtual void pv184();
    virtual void pv188();
    virtual void pv18c();
    virtual void pv190();
    virtual void pv194();
    virtual void pv198();
    virtual void pv19c();
    virtual void pv1a0();
    virtual void pv1a4();
    virtual void pv1a8();
    virtual void pv1ac();
    virtual void pv1b0();
    virtual void pv1b4();
    virtual void pv1b8();
    virtual void pv1bc();
    virtual void pv1c0();
    virtual void pv1c4();
    virtual void pv1c8();
    virtual void pv1cc();
    virtual void pv1d0();
    virtual void pv1d4();
    virtual void pv1d8();
    virtual void pv1dc();
    virtual void pv1e0();
    virtual void pv1e4();
    virtual void pv1e8();
    virtual void pv1ec();
    virtual void pv1f0();
    virtual void pv1f4();
    virtual void pv1f8();
    virtual void pv1fc();
    virtual void pv200();
    virtual void pv204();
    virtual void pv208();
    virtual void pv20c();
    virtual void pv210();
    virtual void pv214();
    virtual void pv218();
    virtual void pv21c();
    virtual void pv220();
    virtual void pv224();
    virtual void pv228();
    virtual void pv22c();
    virtual void pv230();
    virtual void pv234();
    virtual void pv238();
    virtual void pv23c();
    virtual void pv240();
    virtual void pv244();
    virtual void pv248();
    virtual void pv24c();
    virtual void pv250();
    virtual void pv254();
    virtual void pv258();
    virtual void pv25c();
    virtual void pv260();
    virtual void pv264();
    virtual void pv268();
    virtual void pv26c();
    virtual void pv270();
    virtual void pv274();
    virtual void pv278();
    virtual Pkg* GetPackage27c();
    virtual void pv280();
    virtual void pv284();
    virtual void pv288();
    virtual void pv28c();
    virtual void pv290();
    virtual void pv294();
    virtual void pv298();
    virtual void pv29c();
    virtual void pv2a0();
    virtual void pv2a4();
    virtual void pv2a8();
    virtual void pv2ac();
    virtual void pv2b0();
    virtual void pv2b4();
    virtual void pv2b8();
    virtual void pv2bc();
    virtual void pv2c0();
    virtual void pv2c4();
    virtual void pv2c8();
    virtual void pv2cc();
    virtual void pv2d0();
    virtual void pv2d4();
    virtual void pv2d8();
    virtual void pv2dc();
    virtual void pv2e0();
    virtual void pv2e4();
    virtual void pv2e8();
    virtual void pv2ec();
    virtual void pv2f0();
    virtual void pv2f4();
    virtual void pv2f8();
    virtual void pv2fc();
    virtual void pv300();
    virtual void pv304();
    virtual void pv308();
    virtual void pv30c();
    virtual void pv310();
    virtual void pv314();
    virtual void pv318();
    virtual void pv31c();
    virtual void pv320();
    virtual void pv324();
    virtual void pv328();
    virtual void pv32c();
    virtual void pv330();
    virtual void pv334();
    virtual void pv338();
    virtual void pv33c();
    virtual void pv340();
    virtual void pv344();
    virtual void pv348();
    virtual void pv34c();
    virtual void pv350();
    virtual void pv354();
    virtual void pv358();
    virtual void pv35c();
    virtual void pv360();
    virtual void pv364();
    virtual void pv368();
    virtual void pv36c();
    virtual void pv370();
    virtual void pv374();
    virtual void pv378();
    virtual void pv37c();
    virtual void pv380();
    virtual void pv384();
    virtual void pv388();
    virtual void pv38c();
    virtual void pv390();
    virtual void pv394();
    virtual void pv398();
    virtual void pv39c();
    virtual void pv3a0();
    virtual void pv3a4();
    virtual void pv3a8();
    virtual void pv3ac();
    virtual void pv3b0();
    virtual void pv3b4();
    virtual void pv3b8();
    virtual void pv3bc();
    virtual void pv3c0();
    virtual void pv3c4();
    virtual void pv3c8();
    virtual void pv3cc();
    virtual void pv3d0();
    virtual void pv3d4();
    virtual void pv3d8();
    virtual void pv3dc();
    virtual void pv3e0();
    virtual void pv3e4();
    virtual void pv3e8();
    virtual void pv3ec();
    virtual void pv3f0();
    virtual void pv3f4();
    virtual void pv3f8();
    virtual void pv3fc();
    virtual void pv400();
    virtual void pv404();
    virtual void pv408();
    virtual void pv40c();
    virtual void pv410();
    virtual void pv414();
    virtual void pv418();
    virtual void pv41c();
    virtual void pv420();
    virtual void pv424();
    virtual void pv428();
    virtual void pv42c();
    virtual void pv430();
    virtual void pv434();
    virtual void pv438();
    virtual void pv43c();
    virtual void pv440();
    virtual void pv444();
    virtual void pv448();
    virtual void pv44c();
    virtual void pv450();
    virtual void pv454();
    virtual void pv458();
    virtual void pv45c();
    virtual void pv460();
    virtual void pv464();
    virtual void pv468();
    virtual void pv46c();
    virtual void pv470();
    virtual void pv474();
    virtual void pv478();
    virtual void pv47c();
    virtual void pv480();
    virtual void pv484();
    virtual void pv488();
    virtual void pv48c();
    virtual void pv490();
    virtual void pv494();
    virtual void pv498();
    virtual void pv49c();
    virtual void pv4a0();
    virtual void pv4a4();
    virtual void pv4a8();
    virtual void pv4ac();
    virtual void pv4b0();
    virtual void pv4b4();
    virtual void pv4b8();
    virtual void pv4bc();
    virtual void pv4c0();
    virtual void pv4c4();
    virtual void pv4c8();
    virtual void pv4cc();
    virtual void pv4d0();
    virtual void pv4d4();
    virtual void pv4d8();
    virtual void pv4dc();
    virtual void pv4e0();
    virtual void pv4e4();
    virtual void pv4e8();
    virtual void pv4ec();
    virtual void pv4f0();
    virtual void pv4f4();
    virtual void pv4f8();
    virtual void pv4fc();
    virtual void pv500();
    virtual void pv504();
    virtual void pv508();
    virtual void pv50c();
    virtual void pv510();
    virtual Ref* GetTarget514();
};

struct PkgLoc
{
    int GetLocType();
    Cell* GetLocationCellReference();
    Ref* GetLocRef();
};

extern Ref* g_thePlayer;

struct Pkg
{
    PkgLoc* GetLocation();
    int GetPackType();
    Cell* FUN_006751a0(Ref* ref);
};

}  // namespace fnv_006751a0

struct XPos
{
    float x, y, z;
};
struct XM3
{
    float a, b, c, d, e, f, g, h, i;
    XM3();
};
class NiFixedString;
struct XExtra;
struct XNode
{
    void FUN_00440460(const XPos*);
    void FUN_0043fa80(const XM3&);
    XExtra* GetExtraData(const NiFixedString&);
    void FUN_0056c7d0(void*);
    void FUN_00440490(float);
};
struct XPlayer
{
    bool FUN_0050d4a0();
};
struct XTile;
void __cdecl FUN_00c6bd00(XNode*, bool);
void __cdecl FUN_00577e20(XNode*);
const NiFixedString& __cdecl FUN_00448a80();
struct XRef;

struct XRef
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
    virtual int Get3D_116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual XPos* GetPos_125();

    bool IsDeleted();
    bool GetDisabled();
    XTile* FUN_004fd400();
    XPlayer* FUN_007af430();
    void FUN_00693ef0(bool);
    void FUN_00570f70(XNode*);
    bool FUN_00448a20();
    void FUN_005659f0();
    float GetScale();
    XM3 FUN_0056fa00();
    XNode* FUN_0081e570(int);
};

struct Node;

struct Mgr
{
    void FUN_004534f0(Node* p);
};
extern Mgr* DAT_011c3b3c;

struct Node
{
    bool FUN_00936fb0();
};

namespace fnv_009c6160 {
struct NiAVObject;
struct TESObjectCELL;
struct bhkCollisionObject;
struct NiPoint3;
struct bhkWorld
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
    virtual void AddObject(NiAVObject* apObj, bool a, bool b, int c, int d);
};
struct CharCtlX
{
    bhkWorld* GetWorld();
    void SetState(int);
    void SetHeight(float);
    void SetPosition(NiPoint3*);
    NiAVObject* GetNode();
    void SetNode(NiAVObject*);
};
struct bhkWorldObjectV
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
    virtual void* GetWorldPtr();
};
struct bhkCollisionObject
{
    bhkWorldObjectV* GetWorldObject();
};
struct RefX
{
  public:
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
    virtual NiAVObject* GetNiNode();
    CharCtlX* GetPhysicsCharacterController();
    bool hkClassMember_isNotOwner(int);
    NiAVObject* Get3DSimple();
    TESObjectCELL* GetParentCell();
    NiPoint3* GetPos();
    void FUN_009c6160(int unused);
};

}  // namespace fnv_009c6160

namespace fnv_0055a430 {
struct FUN_0055a430;
typedef FUN_0055a430 Cls;
struct Obj40
{
    void FUN_0054ca90(Cls*);
};
struct Obj905
{
    void FUN_00905330();
};
struct EL;
struct InnerObj
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
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void Call4cc(Cls*);
    InnerObj* FUN_008d8520();
};
struct N20
{
    N20* FUN_00726070();
    InnerObj** FUN_006815c0();
};
struct D38
{
    void FUN_0056aa10(int);
};
struct N38
{
    N38* FUN_00726070();
    D38** FUN_006815c0();
    bool FUN_008256d0();
};
struct N30
{
    N30* FUN_00726070();
    Cls** FUN_006815c0();
    bool FUN_008256d0();
};
struct D18
{
    void FUN_00569ba0(int);
};
struct N18
{
    N18* FUN_00726070();
    D18** FUN_006815c0();
    bool FUN_008256d0();
};
struct Holder1c
{
    Cls* f0;
};
struct N1c
{
    N1c* FUN_00726070();
    Holder1c** FUN_006815c0();
    bool FUN_008256d0();
};
struct N40
{
    N40* FUN_00726070();
    Holder1c** FUN_006815c0();
};
struct EL
{
    Cls* FUN_0041de00();
    Cls* FUN_0041e310();
    N30* FUN_0041df90();
    N18* FUN_0041e500();
    N1c* FUN_0041e780();
    N1c* FUN_0041eda0();
    N40* FUN_0041f170();
    void FUN_0041dda0(Cls*);
    void FUN_0041e0d0(Cls*);
    void FUN_0041e340(int);
    void FUN_0041f4c0(Cls*, int);
    void FUN_0041f650(Cls*, int);
    void FUN_0041e600(Cls*);
    void FUN_0041ef20(Cls*);
    void FUN_0041e960(Cls*);
    void FUN_0041de40(int);
};
EL* __fastcall FUN_005d43c0(Cls*);
struct Obj28
{
    Obj28* FUN_00586170();
    void FUN_006fcf30(Cls*);
};
struct Obj2c
{
    void FUN_005380d0(void*);
};
struct ObjCell
{
    Obj2c* FUN_004543c0();
};
struct Sub18
{
    void* FUN_00559450();
    void FUN_0066b0d0(int);
};
struct Sub64
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    Sub18 m18;
};
struct Obj6c
{
    void FUN_006c0c80();
    void FUN_006c1060();
};
void __cdecl FUN_0057acc0(unsigned int);
void __cdecl FUN_00868270(Cls*);
void __cdecl FUN_008d15b0(Cls*);
void __cdecl FUN_00705b30(Cls*);
void __cdecl FUN_00477410(Cls*);
Obj6c* __stdcall GetNavMeshObstacleManager(Cls*);
int __cdecl FUN_0055ac70();
void __cdecl FUN_005aa5d0(Cls*);
void __cdecl FUN_0055ac80();
Cls* __cdecl FUN_007038d0();
void __cdecl FUN_007038b0(int);
struct G43c
{
    void FUN_004538e0(int);
    void FUN_0082f1f0();
};
extern G43c DAT_011e043c;
extern int DAT_011ca28c;
struct TimeG
{
    int FUN_00825c00();
};
extern TimeG DAT_011f6394;
struct ProcL
{
    N20* FUN_0096e290();
    void FUN_00976680(Cls*);
    void FUN_0096f600(Cls*, int);
    void FUN_00975320(Cls*);
    void FUN_00978660(Cls*);
    void FUN_009749b0(Cls*);
};
extern ProcL DAT_011e0e80;
struct Player
{
    void FUN_00963d60(Cls*);
    void FUN_0055ac40(Cls*);
    void FUN_00962cd0(Cls*);
    void FUN_0055ac20();
    Cls* FUN_0089f4e0();
};
extern Player* DAT_011dea3c;
struct ObjA10
{
    Obj905* FUN_0055ac00(Cls**);
};
extern ObjA10* DAT_011dea10;
struct Obj45c
{
    bool FUN_008a81c0();
    void FUN_008a8150(int);
    void FUN_008623a0(Cls*);
};
extern Obj45c* DAT_011de45c;
struct DHand
{
    bool FUN_004226e0();
};
extern DHand* DAT_011c3f2c;
struct FUN_00483630
{
    virtual ~FUN_00483630();
    int b00;
    int b04;
    int b08;
    int b0c;
    int b10;
};
struct Base2
{
    virtual void vbase2();
    Obj40* FUN_00575dc0();
};
struct FUN_004103b0
{
    ~FUN_004103b0();
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
};
struct FUN_0055a430 : FUN_00483630, Base2
{
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    Obj40* m40;
    FUN_004103b0 m44;
    Sub64* m64;
    bool FUN_00568680();
    int FUN_00401170();
    Cls* FUN_00567790();
    void FUN_00567c50();
    Cls* FUN_007af430();
    bool FUN_00549580();
    Obj28* FUN_00575d70();
    ObjCell* FUN_008d6f30();
    bool FUN_004077c0();
    void FUN_00576760();
    Cls* FUN_0056a9f0();
    N38* FUN_0056ac90();
    bool FUN_00564d80();
    bool FUN_005725b0();
    bool FUN_0055abe0();
    bool FUN_00452370();
    Cls* FUN_00569b80();
    void FUN_00564930(int);
    void FUN_0055ad20();
    bool FUN_005653d0();
    bool FUN_00564bc0();

    ~FUN_0055a430();
};

Obj905* __stdcall FUN_004e3260(Cls**);
Obj905* __stdcall FUN_004ec7b0(Cls**);

// @fnv 0x0055a430
Cls::~FUN_0055a430()
{
    Cls* item;
    Cls* list2;
    Cls* head3;
    Obj40* p4c;
    Holder1c* elem_2;
    Cls* obj;
    N40* entry;
    Cls* data;
    N38* head;
    Cls* walk;
    N30* link3;
    Obj2c* it18;
    Obj28* p28;
    InnerObj* p10;
    N20* val;
    N1c* temp2;
    N18* iterX = 0;
    bool saved3;
    Cls* aTmp68;
    FUN_0057acc0((unsigned int)this);
    if (FUN_00568680())
    {
        DAT_011e043c.FUN_004538e0(0);
        DAT_011ca28c = DAT_011f6394.FUN_00825c00();
        for (val = DAT_011e0e80.FUN_0096e290(); val != 0; val = val->FUN_00726070())
        {
            p10 = *val->FUN_006815c0();
            if (p10 != 0)
            {
                if (p10->FUN_008d8520() != 0)
                {
                    p10->FUN_008d8520()->Call4cc(this);
                }
            }
        }
        DAT_011e043c.FUN_0082f1f0();
    }
    if (FUN_00401170() == 0x27)
    {
        DAT_011ca28c = DAT_011f6394.FUN_00825c00();
    }
    FUN_00868270(this);
    if (FUN_007af430() != 0)
    {
        if (FUN_007af430()->FUN_00549580())
        {
            p28 = FUN_00575d70();
            if (p28 != 0)
            {
                if (p28->FUN_00586170() != 0)
                {
                    p28->FUN_00586170()->FUN_006fcf30(this);
                }
            }
        }
    }
    if (m64 != 0)
    {
        it18 = FUN_008d6f30() != 0 ? FUN_008d6f30()->FUN_004543c0() : 0;
        if (it18 != 0)
        {
            it18->FUN_005380d0(m64->m18.FUN_00559450());
        }
        m64->m18.FUN_0066b0d0(0);
    }
    saved3 = DAT_011de45c->FUN_008a81c0();
    DAT_011de45c->FUN_008a8150(0);
    if (!FUN_004077c0())
    {
        FUN_00576760();
        FUN_008d15b0(this);
        DAT_011de45c->FUN_008623a0(this);
        if (!DAT_011c3f2c->FUN_004226e0())
        {
            data = FUN_0056a9f0();
            if (data != 0)
            {
                FUN_005d43c0(data)->FUN_0041dda0(this);
            }
            head = FUN_0056ac90();
            while (head != 0 && !head->FUN_008256d0())
            {
                (*head->FUN_006815c0())->FUN_0056aa10(0);
                head = FUN_0056ac90();
            }
        }
        walk = FUN_005d43c0(this)->FUN_0041de00();
        if (walk != 0)
        {
            FUN_005d43c0(walk)->FUN_0041e0d0(this);
        }
        link3 = FUN_005d43c0(this)->FUN_0041df90();
        while (link3 != 0 && !link3->FUN_008256d0())
        {
            FUN_005d43c0(*link3->FUN_006815c0())->FUN_0041de40(0);
            if ((*link3->FUN_006815c0())->FUN_00567790() == this)
            {
                (*link3->FUN_006815c0())->FUN_00567c50();
            }
            link3 = link3->FUN_00726070();
        }
        if (!DAT_011c3f2c->FUN_004226e0())
        {
            obj = FUN_005d43c0(this)->FUN_0041e310();
            if (obj != 0)
            {
                FUN_005d43c0(obj)->FUN_0041e340(0);
            }
            for (entry = FUN_005d43c0(this)->FUN_0041f170(); entry != 0 && *entry->FUN_006815c0() != 0;)
            {
                elem_2 = *entry->FUN_006815c0();
                entry = entry->FUN_00726070();
                FUN_005d43c0(elem_2->f0)->FUN_0041f4c0(this, 0);
                FUN_005d43c0(elem_2->f0)->FUN_0041f650(this, 0);
            }
            FUN_005aa5d0(this);
            head3 = this;
            FUN_004e3260(&head3)->FUN_00905330();
            list2 = this;
            FUN_004ec7b0(&list2)->FUN_00905330();
            if (FUN_00564d80())
            {
                switch (FUN_00401170())
                {
                case 0x3b:
                case 0x3c:
                    DAT_011dea3c->FUN_00963d60(this);
                    break;
                default:
                    DAT_011e0e80.FUN_00976680(this);
                    DAT_011dea3c->FUN_00963d60(this);
                    DAT_011e0e80.FUN_0096f600(this, 1);
                    DAT_011e0e80.FUN_00975320(this);
                    DAT_011e0e80.FUN_00978660(this);
                    break;
                }
            }
            if (!FUN_005725b0())
            {
                DAT_011e0e80.FUN_009749b0(this);
            }
        }
        if (FUN_0055abe0())
        {
            DAT_011dea3c->FUN_0055ac40(this);
        }
        if (!DAT_011c3f2c->FUN_004226e0())
        {
            if (FUN_00568680())
            {
                item = this;
                DAT_011dea10->FUN_0055ac00(&item)->FUN_00905330();
            }
        }
        if (FUN_00452370())
        {
            FUN_00477410(this);
        }
    }
    aTmp68 = FUN_00569b80();
    if (aTmp68 != 0)
    {
        FUN_005d43c0(aTmp68)->FUN_0041e600(this);
    }
    iterX = FUN_005d43c0(this)->FUN_0041e500();
    while (iterX != 0 && !iterX->FUN_008256d0())
    {
        (*iterX->FUN_006815c0())->FUN_00569ba0(0);
        iterX = iterX->FUN_00726070();
    }
    temp2 = FUN_005d43c0(this)->FUN_0041e780();
    while (temp2 != 0 && !temp2->FUN_008256d0())
    {
        FUN_005d43c0((*temp2->FUN_006815c0())->f0)->FUN_0041ef20(this);
        temp2 = temp2->FUN_00726070();
    }
    temp2 = FUN_005d43c0(this)->FUN_0041eda0();
    while (temp2 != 0 && !temp2->FUN_008256d0())
    {
        FUN_005d43c0((*temp2->FUN_006815c0())->f0)->FUN_0041e960(this);
        temp2 = temp2->FUN_00726070();
    }
    FUN_00564930(1);
    FUN_0055ad20();
    if (m40 != 0)
    {
        m40->FUN_0054ca90(this);
    }
    if (FUN_005653d0())
    {
        if (DAT_011c3f2c != 0)
        {
            if (!DAT_011c3f2c->FUN_004226e0())
            {
                p4c = Base2::FUN_00575dc0();
                if (p4c != 0)
                {
                    p4c->FUN_0054ca90(this);
                }
            }
        }
    }
    if (FUN_007af430() != 0)
    {
        if (FUN_00564bc0())
        {
            GetNavMeshObstacleManager(this)->FUN_006c0c80();
        }
    }
    if (FUN_007af430() != 0)
    {
        if (FUN_007af430()->FUN_00401170() == 0x1c)
        {
            GetNavMeshObstacleManager(this)->FUN_006c1060();
        }
    }
    FUN_00705b30(this);
    if ((Cls*)FUN_0055ac70() == this)
    {
        FUN_0055ac80();
    }
    if (!DAT_011c3f2c->FUN_004226e0())
    {
        if (FUN_007038d0() == this)
        {
            FUN_007038b0(0);
        }
        if (DAT_011dea3c != 0)
        {
            DAT_011dea3c->FUN_00962cd0(this);
        }
    }
    if (DAT_011dea3c->FUN_0089f4e0() == this)
    {
        DAT_011dea3c->FUN_0055ac20();
    }
    DAT_011de45c->FUN_008a8150(saved3);
}
}  // namespace fnv_0055a430

struct StrMem
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    StrMem();
    ~StrMem();
    operator const char*() const;
};
int sprintf(char*, const char*, ...);

struct InitReference;
struct InitVector
{
    float x, y, z;
    void FUN_00439180(float);
};
extern InitVector DAT_011f426c;
struct InitComponent
{
    bool FUN_0047cdb0();
    void FUN_0047ce10(InitReference*);
    bool FUN_0055e200();
    int FUN_00401170();
};
struct InitBase
{
    virtual void BaseSlot0();
    virtual void BaseSlot1();
    virtual void BaseSlot2();
    virtual void BaseSlot3();
    virtual void BaseSlot4();
    virtual void BaseSlot5();
    virtual void BaseSlot6();
    virtual void BaseSlot7();
    virtual void BaseSlot8();
    virtual void BaseSlot9();
    virtual void BaseSlot10();
    virtual void BaseSlot11();
    virtual void BaseSlot12();
    virtual void BaseSlot13();
    virtual void BaseSlot14();
    virtual void BaseSlot15();
    virtual void BaseSlot16();
    virtual void BaseSlot17();
    virtual void BaseSlot18();
    virtual void BaseSlot19();
    virtual void BaseSlot20();
    virtual void BaseSlot21();
    virtual void BaseSlot22();
    virtual void BaseSlot23();
    virtual void BaseSlot24();
    virtual void BaseSlot25();
    virtual void BaseSlot26();
    virtual void BaseSlot27();
    virtual void BaseSlot28();
    virtual void BaseSlot29();
    virtual void BaseSlot30();
    virtual void BaseSlot31();
    virtual void BaseSlot32();
    virtual void BaseSlot33();
    virtual void BaseSlot34();
    virtual void BaseSlot35();
    virtual void BaseSlot36();
    virtual void BaseSlot37();
    virtual void BaseSlot38();
    virtual void BaseSlot39();
    virtual void BaseSlot40();
    virtual void BaseSlot41();
    virtual void BaseSlot42();
    virtual void BaseSlot43();
    virtual void BaseSlot44();
    virtual void BaseSlot45();
    virtual void BaseSlot46();
    virtual void BaseSlot47();
    virtual void BaseSlot48();
    virtual void BaseSlot49();
    virtual void BaseSlot50();
    virtual void BaseSlot51();
    virtual void BaseSlot52();
    virtual void BaseSlot53();
    virtual void BaseSlot54();
    virtual void BaseSlot55();
    virtual void BaseSlot56();
    virtual void BaseSlot57();
    virtual void BaseSlot58();
    virtual void BaseSlot59();
    virtual void BaseSlot60();
    virtual void BaseSlot61();
    virtual void BaseSlot62();
    virtual void BaseSlot63();
    virtual void BaseSlot64();
    virtual void BaseSlot65();
    virtual void BaseSlot66();
    virtual void BaseSlot67();
    virtual void BaseSlot68();
    virtual void BaseSlot69();
    virtual void BaseSlot70();
    virtual void BaseSlot71();
    virtual void BaseSlot72();
    virtual void BaseSlot73();
    virtual void BaseSlot74();
    virtual void BaseSlot75();
    virtual const char* DebugName();
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    InitComponent component80;
    int FUN_00401170();
    bool FUN_00440d80();
    bool FUN_00440da0();
    bool FUN_00549580();
    const char* FUN_0084e3a0();
};
struct InitScaleExtra
{
    float x, y, z;
    InitScaleExtra();
    InitVector* FUN_006815c0();
    void FUN_0098ddd0(const InitVector&);
};
struct InitExtraList
{
    void FUN_00416be0(InitReference*);
    float FUN_0041b550();
    void FUN_00419970(float);
    short FUN_00418770();
    void FUN_00419ad0(int);
    void FUN_00421f30(InitScaleExtra*);
    void* FUN_00410220(int);
    void FUN_00410140(int);
    void FUN_0041aeb0();
};
struct InitCell
{
    void FUN_005878d0(InitReference*);
    struct InitPending* FUN_00586170(InitReference*, bool);
    const char* FUN_0084e3a0();
    virtual void CellSlot0();
    virtual void CellSlot1();
    virtual void CellSlot2();
    virtual void CellSlot3();
    virtual void CellSlot4();
    virtual void CellSlot5();
    virtual void CellSlot6();
    virtual void CellSlot7();
    virtual void CellSlot8();
    virtual void CellSlot9();
    virtual void CellSlot10();
    virtual void CellSlot11();
    virtual void CellSlot12();
    virtual void CellSlot13();
    virtual void CellSlot14();
    virtual void CellSlot15();
    virtual void CellSlot16();
    virtual void CellSlot17();
    virtual void CellSlot18();
    virtual void CellSlot19();
    virtual void CellSlot20();
    virtual void CellSlot21();
    virtual void CellSlot22();
    virtual void CellSlot23();
    virtual void CellSlot24();
    virtual void CellSlot25();
    virtual void CellSlot26();
    virtual void CellSlot27();
    virtual void CellSlot28();
    virtual void CellSlot29();
    virtual void CellSlot30();
    virtual void CellSlot31();
    virtual void CellSlot32();
    virtual void CellSlot33();
    virtual void CellSlot34();
    virtual void CellSlot35();
    virtual void CellSlot36();
    virtual void CellSlot37();
    virtual void CellSlot38();
    virtual void CellSlot39();
    virtual void CellSlot40();
    virtual void CellSlot41();
    virtual void CellSlot42();
    virtual void CellSlot43();
    virtual void CellSlot44();
    virtual void CellSlot45();
    virtual void CellSlot46();
    virtual void CellSlot47();
    virtual void CellSlot48();
    virtual void CellSlot49();
    virtual void CellSlot50();
    virtual void CellSlot51();
    virtual void CellSlot52();
    virtual void CellSlot53();
    virtual void CellSlot54();
    virtual void CellSlot55();
    virtual void CellSlot56();
    virtual void CellSlot57();
    virtual void CellSlot58();
    virtual void CellSlot59();
    virtual void CellSlot60();
    virtual void CellSlot61();
    virtual void CellSlot62();
    virtual void CellSlot63();
    virtual void CellSlot64();
    virtual void CellSlot65();
    virtual void CellSlot66();
    virtual void CellSlot67();
    virtual void CellSlot68();
    virtual void CellSlot69();
    virtual void CellSlot70();
    virtual void CellSlot71();
    virtual void CellSlot72();
    virtual void CellSlot73();
    virtual void CellSlot74();
    virtual void CellSlot75();
    virtual const char* DebugName();
};
struct InitActorBase
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    InitComponent data;
};
struct InitProcess
{
    void FUN_0055e1d0();
    bool FUN_00425fd0();
    const char* FUN_0084e3a0();
    int FUN_00544c30();
    int FUN_00544c60();
    virtual void ProcessSlot0();
    virtual void ProcessSlot1();
    virtual void ProcessSlot2();
    virtual void ProcessSlot3();
    virtual void ProcessSlot4();
    virtual void ProcessSlot5();
    virtual void ProcessSlot6();
    virtual void ProcessSlot7();
    virtual void ProcessSlot8();
    virtual void ProcessSlot9();
    virtual void ProcessSlot10();
    virtual void ProcessSlot11();
    virtual void ProcessSlot12();
    virtual void ProcessSlot13();
    virtual void ProcessSlot14();
    virtual void ProcessSlot15();
    virtual void ProcessSlot16();
    virtual void ProcessSlot17();
    virtual void ProcessSlot18();
    virtual void ProcessSlot19();
    virtual void ProcessSlot20();
    virtual void ProcessSlot21();
    virtual void ProcessSlot22();
    virtual void ProcessSlot23();
    virtual void ProcessSlot24();
    virtual void ProcessSlot25();
    virtual void ProcessSlot26();
    virtual void ProcessSlot27();
    virtual void ProcessSlot28();
    virtual void ProcessSlot29();
    virtual void ProcessSlot30();
    virtual void ProcessSlot31();
    virtual void ProcessSlot32();
    virtual void ProcessSlot33();
    virtual void ProcessSlot34();
    virtual void ProcessSlot35();
    virtual void ProcessSlot36();
    virtual void ProcessSlot37();
    virtual void ProcessSlot38();
    virtual void ProcessSlot39();
    virtual void ProcessSlot40();
    virtual void ProcessSlot41();
    virtual void ProcessSlot42();
    virtual void ProcessSlot43();
    virtual void ProcessSlot44();
    virtual void ProcessSlot45();
    virtual void ProcessSlot46();
    virtual void ProcessSlot47();
    virtual void ProcessSlot48();
    virtual void ProcessSlot49();
    virtual void ProcessSlot50();
    virtual void ProcessSlot51();
    virtual void ProcessSlot52();
    virtual void ProcessSlot53();
    virtual void ProcessSlot54();
    virtual void ProcessSlot55();
    virtual void ProcessSlot56();
    virtual void ProcessSlot57();
    virtual void ProcessSlot58();
    virtual void ProcessSlot59();
    virtual void ProcessSlot60();
    virtual void ProcessSlot61();
    virtual void ProcessSlot62();
    virtual void ProcessSlot63();
    virtual void ProcessSlot64();
    virtual void ProcessSlot65();
    virtual void ProcessSlot66();
    virtual void ProcessSlot67();
    virtual void ProcessSlot68();
    virtual void ProcessSlot69();
    virtual void ProcessSlot70();
    virtual void ProcessSlot71();
    virtual void ProcessSlot72();
    virtual void ProcessSlot73();
    virtual void ProcessSlot74();
    virtual void ProcessSlot75();
    virtual const char* DebugName();
};
struct InitReference
{
    virtual void RefSlot0();
    virtual void RefSlot1();
    virtual void RefSlot2();
    virtual void RefSlot3();
    virtual void RefSlot4();
    virtual void RefSlot5();
    virtual void RefSlot6();
    virtual void RefSlot7();
    virtual void RefSlot8();
    virtual void RefSlot9();
    virtual void RefSlot10();
    virtual void RefSlot11();
    virtual void RefSlot12();
    virtual void RefSlot13();
    virtual void RefSlot14();
    virtual void RefSlot15();
    virtual void RefSlot16();
    virtual void RefSlot17();
    virtual void RefSlot18();
    virtual void RefSlot19();
    virtual void RefSlot20();
    virtual void RefSlot21();
    virtual void RefSlot22();
    virtual void RefSlot23();
    virtual void RefSlot24();
    virtual void RefSlot25();
    virtual void RefSlot26();
    virtual void RefSlot27();
    virtual void RefSlot28();
    virtual void RefSlot29();
    virtual void RefSlot30();
    virtual void RefSlot31();
    virtual void RefSlot32();
    virtual void RefSlot33();
    virtual void RefSlot34();
    virtual void RefSlot35();
    virtual void RefSlot36();
    virtual void RefSlot37();
    virtual void RefSlot38();
    virtual void RefSlot39();
    virtual void RefSlot40();
    virtual void RefSlot41();
    virtual void RefSlot42();
    virtual void RefSlot43();
    virtual void RefSlot44();
    virtual void RefSlot45();
    virtual void RefSlot46();
    virtual void RefSlot47();
    virtual void RefSlot48();
    virtual void SetSpecial(bool);
    virtual void RefSlot50();
    virtual void RefSlot51();
    virtual void RefSlot52();
    virtual void RefSlot53();
    virtual void RefSlot54();
    virtual void RefSlot55();
    virtual void RefSlot56();
    virtual void RefSlot57();
    virtual void RefSlot58();
    virtual void RefSlot59();
    virtual void RefSlot60();
    virtual void RefSlot61();
    virtual void RefSlot62();
    virtual void RefSlot63();
    virtual bool IsActor();
    virtual void RefSlot65();
    virtual void RefSlot66();
    virtual void RefSlot67();
    virtual void RefSlot68();
    virtual void RefSlot69();
    virtual void RefSlot70();
    virtual void RefSlot71();
    virtual void RefSlot72();
    virtual void RefSlot73();
    virtual void RefSlot74();
    virtual void RefSlot75();
    virtual const char* DebugName();
    virtual void RefSlot77();
    virtual void RefSlot78();
    virtual void RefSlot79();
    virtual void RefSlot80();
    virtual void RefSlot81();
    virtual void RefSlot82();
    virtual void RefSlot83();
    virtual void RefSlot84();
    virtual void RefSlot85();
    virtual void RefSlot86();
    virtual void RefSlot87();
    virtual void RefSlot88();
    virtual void RefSlot89();
    virtual void RefSlot90();
    virtual void RefSlot91();
    virtual void RefSlot92();
    virtual void SetReferenceVector(InitVector);
    virtual void RefSlot94();
    virtual void RefSlot95();
    virtual void RefSlot96();
    virtual void RefSlot97();
    virtual void RefSlot98();
    virtual void RefSlot99();
    virtual void RefSlot100();
    virtual void RefSlot101();
    virtual void RefSlot102();
    virtual void RefSlot103();
    virtual void RefSlot104();
    virtual void RefSlot105();
    virtual void RefSlot106();
    virtual void RefSlot107();
    virtual void RefSlot108();
    virtual void RefSlot109();
    virtual void RefSlot110();
    virtual void RefSlot111();
    virtual void RefSlot112();
    virtual void RefSlot113();
    virtual void RefSlot114();
    virtual void RefSlot115();
    virtual void RefSlot116();
    virtual void RefSlot117();
    virtual void RefSlot118();
    virtual void RefSlot119();
    virtual void RefSlot120();
    virtual void RefSlot121();
    virtual void RefSlot122();
    virtual void RefSlot123();
    virtual void RefSlot124();
    virtual void RefSlot125();
    virtual void SetEssential(bool);
    virtual void RefSlot127();
    virtual void RefSlot128();
    virtual void RefSlot129();
    virtual void RefSlot130();
    virtual void RefSlot131();
    virtual void RefSlot132();
    virtual void RefSlot133();
    virtual bool IsNPC();
    virtual void RefSlot135();
    virtual void RefSlot136();
    virtual void RefSlot137();
    virtual void RefSlot138();
    virtual void RefSlot139();
    virtual void RefSlot140();
    virtual void RefSlot141();
    virtual void RefSlot142();
    virtual void RefSlot143();
    virtual void RefSlot144();
    virtual void RefSlot145();
    virtual void RefSlot146();
    virtual void RefSlot147();
    virtual void RefSlot148();
    virtual void RefSlot149();
    virtual void RefSlot150();
    virtual void RefSlot151();
    virtual void RefSlot152();
    virtual void RefSlot153();
    virtual void RefSlot154();
    virtual void RefSlot155();
    virtual void RefSlot156();
    virtual void RefSlot157();
    virtual void RefSlot158();
    virtual void RefSlot159();
    virtual void RefSlot160();
    virtual void RefSlot161();
    virtual void RefSlot162();
    virtual void RefSlot163();
    virtual bool ActorReady();
    virtual void RefSlot165();
    virtual void RefSlot166();
    virtual void RefSlot167();
    virtual void RefSlot168();
    virtual void RefSlot169();
    virtual void RefSlot170();
    virtual void RefSlot171();
    virtual void RefSlot172();
    virtual void RefSlot173();
    virtual void RefSlot174();
    virtual void RefSlot175();
    virtual void RefSlot176();
    virtual void RefSlot177();
    virtual void RefSlot178();
    virtual void RefSlot179();
    virtual void RefSlot180();
    virtual void RefSlot181();
    virtual void RefSlot182();
    virtual void RefSlot183();
    virtual void RefSlot184();
    virtual void RefSlot185();
    virtual void RefSlot186();
    virtual void RefSlot187();
    virtual void RefSlot188();
    virtual void RefSlot189();
    virtual void RefSlot190();
    virtual void RefSlot191();
    virtual void RefSlot192();
    virtual void RefSlot193();
    virtual void SetTemplateFlag(bool);
    virtual void RefSlot195();
    virtual void RefSlot196();
    virtual void RefSlot197();
    virtual void RefSlot198();
    virtual void RefSlot199();
    virtual void RefSlot200();
    virtual void RefSlot201();
    virtual void RefSlot202();
    virtual void RefSlot203();
    virtual void RefSlot204();
    virtual void RefSlot205();
    virtual void RefSlot206();
    virtual void RefSlot207();
    virtual void RefSlot208();
    virtual void RefSlot209();
    virtual void RefSlot210();
    virtual void RefSlot211();
    virtual void RefSlot212();
    virtual void RefSlot213();
    virtual void RefSlot214();
    virtual void RefSlot215();
    virtual bool HasActorState();
    virtual void RefSlot217();
    virtual void RefSlot218();
    virtual void RefSlot219();
    virtual void RefSlot220();
    virtual void RefSlot221();
    virtual void RefSlot222();
    virtual void RefSlot223();
    virtual void RefSlot224();
    virtual void RefSlot225();
    virtual void RefSlot226();
    virtual void RefSlot227();
    virtual void RefSlot228();
    virtual void RefSlot229();
    virtual void RefSlot230();
    virtual void RefSlot231();
    virtual void RefSlot232();
    virtual void RefSlot233();
    virtual void RefSlot234();
    virtual void RefSlot235();
    virtual void RefSlot236();
    virtual void RefSlot237();
    virtual void RefSlot238();
    virtual void RefSlot239();
    virtual void RefSlot240();
    virtual void RefSlot241();
    virtual void RefSlot242();
    virtual void RefSlot243();
    virtual void RefSlot244();
    virtual void RefSlot245();
    virtual void RefSlot246();
    virtual void RefSlot247();
    virtual void RefSlot248();
    virtual void RefSlot249();
    virtual void RefSlot250();
    virtual void RefSlot251();
    virtual void RefSlot252();
    virtual void RefSlot253();
    virtual void RefSlot254();
    virtual void RefSlot255();
    virtual void RefSlot256();
    virtual void RefSlot257();
    virtual void RefSlot258();
    virtual void RefSlot259();
    virtual void RefSlot260();
    virtual void RefSlot261();
    virtual void RefSlot262();
    virtual void RefSlot263();
    virtual void RefSlot264();
    virtual void RefSlot265();
    virtual void RefSlot266();
    virtual void RefSlot267();
    virtual void RefSlot268();
    virtual void RefSlot269();
    virtual void RefSlot270();
    virtual void RefSlot271();
    virtual void RefSlot272();
    virtual void RefSlot273();
    virtual void RefSlot274();
    virtual void RefSlot275();
    virtual void RefSlot276();
    virtual void RefSlot277();
    virtual void RefSlot278();
    virtual void RefSlot279();
    virtual void RefSlot280();
    virtual void RefSlot281();
    virtual void RefSlot282();
    virtual void InitializeActor();
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    InitBase* base;
    InitVector rotation;
    InitVector position;

    bool FUN_004013e0();
    InitBase* FUN_007af430();
    InitExtraList* FUN_005d43c0();
    bool FUN_00439f90();
    float FUN_00567400();
    InitScaleExtra* FUN_00569840();
    void FUN_00567490(float);
    InitCell* FUN_00575d70();
    bool FUN_005722c0(int);
    void FUN_008a1800(int);
    InitBase* FUN_00884350();
    InitActorBase* FUN_004181e0();
    bool FUN_0056afc0();
    bool FUN_00572c80();
    InitReference* FUN_0056a9f0();
    bool FUN_0056aa70();
    bool FUN_00440da0();
    void FUN_00484af0(bool);
    bool FUN_00564e60();
    InitProcess* FUN_008d6f30();
    void FUN_0056ac00();
    void FUN_004846a0(bool);
    void FUN_00484ab0(bool);
    const char* FUN_0084e3a0();
    unsigned FUN_00401280();
    void FUN_00565730();
    void FUN_0046a010(int);
    void FUN_0055d760();
};
void FUN_005b5e40(const char*, ...);
int FUN_00ec7595(double);
int FUN_00ec75b1(double);
struct InitModeManager
{
    bool FUN_004623f0(bool);
};
extern InitModeManager* DAT_011ddf38;
struct InitToggle
{
    bool FUN_0047c850();
    void FUN_004534f0(bool);
};
extern InitToggle* DAT_011de45c;
extern InitReference* DAT_011dea3c;
struct InitSelection
{
    void FUN_004d1440();
    void FUN_004d1610();
    void FUN_004d1960();
    bool FUN_0042cde0();
};
InitSelection* FUN_004bf220(InitReference*);
void* __fastcall FUN_0055d310(InitReference*);
struct InitPending
{
    void FUN_006fcfa0();
};

struct SaveChangeRecord
{
    unsigned int formID;
    unsigned char formType;
    unsigned char changeFlags[4];
};
struct SaveDebugForm
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
    virtual const char* Describe();
};
SaveDebugForm* __cdecl FUN_004839c0(unsigned int);
void __cdecl FUN_0040fbe0(const char*, ...);
struct TESSaveLoadGame
{
    bool FUN_00862110();
    unsigned char FUN_008df040();
    SaveChangeRecord* FUN_004fd3e0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
struct SaveInventory
{
    unsigned short FUN_004d3960();
};
struct SaveExtraList
{
    SaveInventory* FUN_00418520();
    unsigned short FUN_00422c40(unsigned int, void*);
};
struct SaveReference
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
    unsigned short FUN_00484bf0(unsigned int);
    SaveExtraList* FUN_005d43c0();
    unsigned short FUN_0055f880();
    unsigned short FUN_00560350(bool);
    unsigned short FUN_0055e730(unsigned int flags);
};

namespace fnv_0055e940 {
struct SavedChangeRecord
{
    unsigned int formId;
    unsigned char type;
    unsigned char changeFlags[4];
};
struct TESSaveLoadGame
{
    unsigned int FUN_00825c00();
    bool FUN_00862110();
    void FUN_008579b0(void*, int);
    unsigned char FUN_008df040();
    SavedChangeRecord* FUN_004fd3e0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
struct SaveExtras;
struct ScriptSaveData
{
    void FUN_004d3ab0();
};
struct SaveExtras
{
    ScriptSaveData* FUN_00418520();
    void FUN_004235e0(unsigned int, void*);
};
struct DiagnosticForm
{
    virtual void virtual_00();
    virtual void virtual_04();
    virtual void virtual_08();
    virtual void virtual_0c();
    virtual void virtual_10();
    virtual void virtual_14();
    virtual void virtual_18();
    virtual void virtual_1c();
    virtual void virtual_20();
    virtual void virtual_24();
    virtual void virtual_28();
    virtual void virtual_2c();
    virtual void virtual_30();
    virtual void virtual_34();
    virtual void virtual_38();
    virtual void virtual_3c();
    virtual void virtual_40();
    virtual void virtual_44();
    virtual void virtual_48();
    virtual void virtual_4c();
    virtual void virtual_50();
    virtual void virtual_54();
    virtual void virtual_58();
    virtual void virtual_5c();
    virtual void virtual_60();
    virtual void virtual_64();
    virtual void virtual_68();
    virtual void virtual_6c();
    virtual void virtual_70();
    virtual void virtual_74();
    virtual void virtual_78();
    virtual void virtual_7c();
    virtual void virtual_80();
    virtual void virtual_84();
    virtual void virtual_88();
    virtual void virtual_8c();
    virtual void virtual_90();
    virtual void virtual_94();
    virtual void virtual_98();
    virtual void virtual_9c();
    virtual void virtual_a0();
    virtual void virtual_a4();
    virtual void virtual_a8();
    virtual void virtual_ac();
    virtual void virtual_b0();
    virtual void virtual_b4();
    virtual void virtual_b8();
    virtual void virtual_bc();
    virtual void virtual_c0();
    virtual void virtual_c4();
    virtual void virtual_c8();
    virtual void virtual_cc();
    virtual void virtual_d0();
    virtual void virtual_d4();
    virtual void virtual_d8();
    virtual void virtual_dc();
    virtual void virtual_e0();
    virtual void virtual_e4();
    virtual void virtual_e8();
    virtual void virtual_ec();
    virtual void virtual_f0();
    virtual void virtual_f4();
    virtual void virtual_f8();
    virtual void virtual_fc();
    virtual void virtual_100();
    virtual void virtual_104();
    virtual void virtual_108();
    virtual void virtual_10c();
    virtual void virtual_110();
    virtual void virtual_114();
    virtual void virtual_118();
    virtual void virtual_11c();
    virtual void virtual_120();
    virtual void virtual_124();
    virtual void virtual_128();
    virtual void virtual_12c();
    virtual const char* GetDiagnosticName();
};
DiagnosticForm* FUN_004839c0(unsigned int);
void FUN_0040fbe0(const char*, ...);
void FNV_Warning(const char*, ...);
struct SaveReference
{
    virtual void virtual_00();
    virtual void virtual_04();
    virtual void virtual_08();
    virtual void virtual_0c();
    virtual void virtual_10();
    virtual void virtual_14();
    virtual void virtual_18();
    virtual void virtual_1c();
    virtual void virtual_20();
    virtual void virtual_24();
    virtual void virtual_28();
    virtual void virtual_2c();
    virtual void virtual_30();
    virtual void virtual_34();
    virtual void virtual_38();
    virtual void virtual_3c();
    virtual void virtual_40();
    virtual void virtual_44();
    virtual void virtual_48();
    virtual void virtual_4c();
    virtual void virtual_50();
    virtual void virtual_54();
    virtual void virtual_58();
    virtual void virtual_5c();
    virtual void virtual_60();
    virtual void virtual_64();
    virtual void virtual_68();
    virtual void virtual_6c();
    virtual void virtual_70();
    virtual void virtual_74();
    virtual void virtual_78();
    virtual void virtual_7c();
    virtual void virtual_80();
    virtual void virtual_84();
    virtual void virtual_88();
    virtual void virtual_8c();
    virtual void virtual_90();
    virtual void virtual_94();
    virtual void virtual_98();
    virtual void virtual_9c();
    virtual void virtual_a0();
    virtual void virtual_a4();
    virtual void virtual_a8();
    virtual void virtual_ac();
    virtual void virtual_b0();
    virtual void virtual_b4();
    virtual void virtual_b8();
    virtual void virtual_bc();
    virtual void virtual_c0();
    virtual void virtual_c4();
    virtual void virtual_c8();
    virtual void virtual_cc();
    virtual void virtual_d0();
    virtual void virtual_d4();
    virtual void virtual_d8();
    virtual void virtual_dc();
    virtual void virtual_e0();
    virtual void virtual_e4();
    virtual void virtual_e8();
    virtual void virtual_ec();
    virtual void virtual_f0();
    virtual void virtual_f4();
    virtual void virtual_f8();
    virtual void virtual_fc();
    virtual bool IsActor();
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
    float referenceScale;
    void FUN_00484c20(unsigned int);
    void FUN_00484ce0(const void*, int);
    SaveExtras* FUN_005d43c0();
    unsigned short FUN_0055f880();
    void FUN_0055f900();
    unsigned short FUN_00560350(FUN_0055ebf0*);
    void FUN_005604b0(FUN_0055ebf0*);
    void FUN_0055e940(unsigned int flags);
};
}  // namespace fnv_0055e940

namespace fnv_0055ec40 {
struct LoadRecord
{
    unsigned int id;
    unsigned char type;
    unsigned char flags0, flags1, flags2, flags3;
    unsigned char version;
};
struct LoadForm
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
    virtual const char* describe();
};
LoadForm* __cdecl FUN_004839c0(unsigned int);
struct LoadExtra
{
    void FUN_0041aeb0();
    void FUN_004269c0(unsigned int, void*);
    void FUN_00424960(unsigned int, unsigned int, void*);
    bool FUN_0041b3a0(int);
    void FUN_0041b470(int);
    void FUN_0041b440(int);
    void FUN_00422920();
};
struct LoadLight
{
    unsigned int a, b;
    float c;
};
struct LoadObject;
struct LoadManager
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    LoadRecord* FUN_004fd3c0();
    unsigned char FUN_008df040();
    unsigned int FUN_00825c00();
    bool FUN_0047c850();
    void FUN_0085f2b0(LoadObject*, unsigned short);
    void FUN_0085f5a0(LoadObject*, unsigned short);
    void FUN_00857bd0(unsigned short);
};
extern LoadManager* g_TESSaveLoadGame;
void __cdecl FNV_Warning(const char*, ...);
struct LoadAux
{
    void TESObjectCELL_AdjustCoordForNorthRotation();
};
LoadAux* __cdecl FUN_004bf220(LoadObject*);
extern const float DAT_01015f5c;
struct LoadObject
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
    virtual bool isActor();
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
    virtual void reset(int, bool);
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
    virtual bool actorState();
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
    float scale;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    LoadLight* light;
    void FUN_00484c50(unsigned int, unsigned int);
    void FUN_00484580(bool);
    LoadObject* FUN_0056a9f0();
    bool FUN_0056aa70();
    bool FUN_00440da0();
    bool FUN_00440d80();
    void FUN_00484af0(bool);
    void* FUN_0055d310();
    void FUN_00571b50();
    void FUN_004534f0(bool);
    void FUN_00483710();
    LoadExtra* FUN_005d43c0();
    void FUN_008adc50();
    void FUN_00484d00(void*, unsigned int);
    void FUN_00567490(float);
    void FUN_0055ec40(unsigned int flags, unsigned int more);
};
}  // namespace fnv_0055ec40

namespace fnv_0055f240 {

struct MyModelLoader : public ModelLoader
{
    bool FUN_00445750(void* ref);
    void FUN_00444850(void* ref, void* cellData);
};
extern MyModelLoader* g_modelLoader;

struct MyTES : public TES
{
    void* FUN_00458be0(void* cell, int, int);
};
extern MyTES* g_TES;

struct TESSaveLoadGame
{
    bool GetLoading();
    bool FUN_00632ce0();
    bool FUN_0055f5b0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

bool __fastcall FUN_00450ff0(void* cell);
bool __cdecl FUN_0047a490(void* form);

struct BGSOpenCloseForm
{
    static bool SetOpenState(void* ref, bool b1, bool b2);
};

}  // namespace fnv_0055f240

struct Reference
{

    void FUN_00a59c60(void* position);
};
struct Effect
{

    void hkpSimulationIsland_markForWrite(float magnitude);
    float FUN_00759450(int kind, int selector);
};
struct ResourceName;
struct EffectController
{
    Effect* FUN_0047a520(const ResourceName& name);
    void FUN_0048fef0(float value);
    void FUN_0047aa40(bool enabled);
    void FUN_0047aab0(Effect* effect, int a, int b, float c, float d, int e);
    Effect* FUN_00495d20(bool first);
};
struct ResourceName
{
    void* m_kStringBuffer;
    ResourceName(void* text);
    ~ResourceName();
};
struct Position
{
    float m_uiX, m_uiY, m_uiZ;
    void FUN_0043d410(float value);
};
struct DataHandle
{
};
struct PanelControl
{
    virtual void unusedSlot000();
    virtual void unusedSlot001();
    virtual void unusedSlot002();
    virtual void unusedSlot003();
    virtual void unusedSlot004();
    virtual void unusedSlot005();
    virtual void unusedSlot006();
    virtual void unusedSlot007();
    virtual void unusedSlot008();
    virtual void unusedSlot009();
    virtual void unusedSlot010();
    virtual void unusedSlot011();
    virtual void unusedSlot012();
    virtual void unusedSlot013();
    virtual void unusedSlot014();
    virtual void unusedSlot015();
    virtual void unusedSlot016();
    virtual void unusedSlot017();
    virtual void unusedSlot018();
    virtual void unusedSlot019();
    virtual void unusedSlot020();
    virtual void unusedSlot021();
    virtual void unusedSlot022();
    virtual void unusedSlot023();
    virtual void unusedSlot024();
    virtual void unusedSlot025();
    virtual void unusedSlot026();
    virtual void unusedSlot027();
    virtual void unusedSlot028();
    virtual void unusedSlot029();
    virtual void unusedSlot030();
    virtual void unusedSlot031();
    virtual void unusedSlot032();
    virtual void unusedSlot033();
    virtual void unusedSlot034();
    virtual void unusedSlot035();
    virtual void unusedSlot036();
    virtual void unusedSlot037();
    virtual void unusedSlot038();
    virtual void unusedSlot039();
    virtual void unusedSlot040();
    virtual void unusedSlot041();
    virtual void unusedSlot042();
    virtual void unusedSlot043();
    virtual void unusedSlot044();
    virtual void unusedSlot045();
    virtual void unusedSlot046();
    virtual void unusedSlot047();
    virtual void unusedSlot048();
    virtual void unusedSlot049();
    virtual void unusedSlot050();
    virtual void unusedSlot051();
    virtual void unusedSlot052();
    virtual void unusedSlot053();
    virtual void unusedSlot054();
    virtual void unusedSlot055();
    virtual void unusedSlot056();
    virtual void unusedSlot057();
    virtual void unusedSlot058();
    virtual void unusedSlot059();
    virtual void unusedSlot060();
    virtual void unusedSlot061();
    virtual void unusedSlot062();
    virtual void unusedSlot063();
    virtual void unusedSlot064();
    virtual void unusedSlot065();
    virtual void unusedSlot066();
    virtual void unusedSlot067();
    virtual void unusedSlot068();
    virtual void unusedSlot069();
    virtual void unusedSlot070();
    virtual void unusedSlot071();
    virtual void unusedSlot072();
    virtual void unusedSlot073();
    virtual void unusedSlot074();
    virtual void unusedSlot075();
    virtual void unusedSlot076();
    virtual void unusedSlot077();
    virtual void unusedSlot078();
    virtual void unusedSlot079();
    virtual void unusedSlot080();
    virtual void unusedSlot081();
    virtual void unusedSlot082();
    virtual void unusedSlot083();
    virtual void unusedSlot084();
    virtual void unusedSlot085();
    virtual void unusedSlot086();
    virtual void unusedSlot087();
    virtual void unusedSlot088();
    virtual void unusedSlot089();
    virtual void unusedSlot090();
    virtual void unusedSlot091();
    virtual void unusedSlot092();
    virtual void unusedSlot093();
    virtual void* GetActivationHandle(void* ref);
};
struct FNV_0055f970
{
    virtual void unusedSlot000();
    virtual void unusedSlot001();
    virtual void unusedSlot002();
    virtual void unusedSlot003();
    virtual void unusedSlot004();
    virtual void unusedSlot005();
    virtual void unusedSlot006();
    virtual void unusedSlot007();
    virtual void unusedSlot008();
    virtual void unusedSlot009();
    virtual void unusedSlot010();
    virtual void unusedSlot011();
    virtual void unusedSlot012();
    virtual void unusedSlot013();
    virtual void unusedSlot014();
    virtual void unusedSlot015();
    virtual void unusedSlot016();
    virtual void unusedSlot017();
    virtual void unusedSlot018();
    virtual void unusedSlot019();
    virtual void unusedSlot020();
    virtual void unusedSlot021();
    virtual void unusedSlot022();
    virtual void unusedSlot023();
    virtual void unusedSlot024();
    virtual void unusedSlot025();
    virtual void unusedSlot026();
    virtual void unusedSlot027();
    virtual void unusedSlot028();
    virtual void unusedSlot029();
    virtual void unusedSlot030();
    virtual void unusedSlot031();
    virtual void unusedSlot032();
    virtual void unusedSlot033();
    virtual void unusedSlot034();
    virtual void unusedSlot035();
    virtual void unusedSlot036();
    virtual void unusedSlot037();
    virtual void unusedSlot038();
    virtual void unusedSlot039();
    virtual void unusedSlot040();
    virtual void unusedSlot041();
    virtual void unusedSlot042();
    virtual void unusedSlot043();
    virtual void unusedSlot044();
    virtual void unusedSlot045();
    virtual void unusedSlot046();
    virtual void unusedSlot047();
    virtual void unusedSlot048();
    virtual void unusedSlot049();
    virtual void unusedSlot050();
    virtual void unusedSlot051();
    virtual void unusedSlot052();
    virtual void unusedSlot053();
    virtual void unusedSlot054();
    virtual void unusedSlot055();
    virtual void unusedSlot056();
    virtual void unusedSlot057();
    virtual void unusedSlot058();
    virtual void unusedSlot059();
    virtual void unusedSlot060();
    virtual void unusedSlot061();
    virtual void unusedSlot062();
    virtual void unusedSlot063();
    virtual void unusedSlot064();
    virtual void unusedSlot065();
    virtual void unusedSlot066();
    virtual void unusedSlot067();
    virtual void unusedSlot068();
    virtual void unusedSlot069();
    virtual void unusedSlot070();
    virtual void unusedSlot071();
    virtual void unusedSlot072();
    virtual void unusedSlot073();
    virtual void unusedSlot074();
    virtual void unusedSlot075();
    virtual void unusedSlot076();
    virtual void unusedSlot077();
    virtual void unusedSlot078();
    virtual void unusedSlot079();
    virtual void unusedSlot080();
    virtual void unusedSlot081();
    virtual void unusedSlot082();
    virtual void unusedSlot083();
    virtual void unusedSlot084();
    virtual void unusedSlot085();
    virtual void unusedSlot086();
    virtual void unusedSlot087();
    virtual void unusedSlot088();
    virtual void unusedSlot089();
    virtual void unusedSlot090();
    virtual void unusedSlot091();
    virtual void unusedSlot092();
    virtual void unusedSlot093();
    virtual void unusedSlot094();
    virtual void unusedSlot095();
    virtual void unusedSlot096();
    virtual void unusedSlot097();
    virtual void unusedSlot098();
    virtual void unusedSlot099();
    virtual void unusedSlot100();
    virtual void unusedSlot101();
    virtual void unusedSlot102();
    virtual void unusedSlot103();
    virtual void unusedSlot104();
    virtual void unusedSlot105();
    virtual void unusedSlot106();
    virtual void unusedSlot107();
    virtual void unusedSlot108();
    virtual void unusedSlot109();
    virtual void unusedSlot110();
    virtual void unusedSlot111();
    virtual void unusedSlot112();
    virtual void CloseInteraction();
    virtual void unusedSlot114();
    virtual void DispatchInteraction(void* handle, bool active);
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    PanelControl* m_20;

    void FUN_0055f970();
};
struct Registry
{
    int m_uiContentCount;
};

extern "C" void* DAT_01197b5c;
extern "C" void* DAT_011977d8;
extern "C" void* DAT_01197820;
extern "C" float DAT_0102f510;
bool __cdecl FUN_004b5bf0(Reference*);
EffectController* __cdecl FUN_00653270(Registry*, void*);

Reference* __fastcall FUN_0043fcd0(FNV_0055f970*);
void* __fastcall FUN_0043b230(Reference*);
void* __fastcall FUN_004228f0(DataHandle*);
int __fastcall FUN_008041a0(Effect*);

namespace fnv_0055fe70 {
struct TESSaveLoadGame
{
    unsigned short* ReserveCount();
    void FUN_008579b0(void* data, int size);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern float DAT_011c3c08;

}  // namespace fnv_0055fe70

namespace fnv_00560350 {
struct PacketCallback
{
    unsigned int user;
    unsigned char active;
    unsigned int value;
    FUN_0055ebf0* packet;
    unsigned int position;
    unsigned int limit;
    unsigned int state;
};
unsigned int __cdecl FUN_004a8b00(void*);
void __cdecl FUN_00c68900(void*, PacketCallback*, unsigned char*);

}  // namespace fnv_00560350

namespace fnv_00560530 {
struct RestoreRef;
struct Scene;
struct SavedState
{
    unsigned char flags;
    unsigned short count1, count2;
    RestoreRef* ref;
    Scene* scene;
    void* collision;
    SavedState();
};
struct UpdateState
{
    float time;
    bool a, b;
    unsigned int flags;
    UpdateState(float, bool, bool);
};
struct Scene
{
    void Update(UpdateState&);
};
struct Controller
{
    void Reset(bool);
};
struct AnimState
{
    void Set(int, float);
    void Refresh();
};
struct RestoreRef
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
    virtual bool slot64();
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
    virtual const char* slot76();
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
    virtual AnimState* slot121();
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
    virtual bool slot141();
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
    Controller* controller;
    void FUN_00560530(unsigned short);
    void Legacy(unsigned short);
    Scene* Get3D();
    void Read(void*, unsigned int);
    void Current(SavedState*);
    void Weapon(bool);
    unsigned int FormID();
};
struct Loader
{
    unsigned char Version();
    void Skip(unsigned int);
};
extern Loader* g_TESSaveLoadGame;
extern int NiPoint3_ZERO;
}  // namespace fnv_00560530

namespace fnv_00560e70 {
struct VecLoad
{
    float x, y, z;
    VecLoad();
    void Convert(const struct MatrixLoad&);
};
struct QuatLoad
{
    float x, y, z, w;
    QuatLoad();
    void Convert(const struct MatrixLoad&);
};
struct MatrixLoad
{
    float a, b, c, d, e, f, g, h, i;
};
struct NameLoad
{
    operator const char*() const;
};
struct NodeLoad
{
    NameLoad& GetName();
};
struct BodyLoad
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
    virtual void* active();
    void FUN_00561580(bool);
    void FUN_005610f0(const VecLoad*);
    void FUN_00561150(const QuatLoad*);
    void FUN_005615d0(const VecLoad*);
    void FUN_00561630(const VecLoad*);
};
struct StreamLoad
{
    void FUN_008579e0(void*, unsigned int);
};
extern StreamLoad* g_TESSaveLoadGame;
extern int DAT_011f9140, DAT_012681c0;
extern VecLoad NiPoint3_ZERO;
bool FUN_0043b300(const void*, NodeLoad*);
BodyLoad* FUN_00653270(const void*, BodyLoad*);
int FUN_00408b20(const char*, const char*);
}  // namespace fnv_00560e70

struct BGSSaveFormBuffer;

struct BGSChangeFlags_s
{
    unsigned int flags;
    BGSChangeFlags_s(const BGSChangeFlags_s& o);
    bool Test(unsigned int mask);
};

struct BGSSaveFormBuffer
{
    BGSChangeFlags_s GetChangeFlags();
    void SaveData(void* data, int size, int unk);
    unsigned int GetPos();
    unsigned int GetSize();
    void SetChunk(unsigned int size, unsigned int pos);
};

struct ExtraDataList_s
{
    void SaveGame(BGSSaveFormBuffer* buf);
    int GetSaveObj();
};

struct InvChanges_s
{
    void SaveGame(BGSSaveFormBuffer* buf);
};

struct SubObj_s
{
    void* ptr;
    SubObj_s(int v);
    operator void*() const;
    void Save(BGSSaveFormBuffer* buf);
};

struct Refr_s
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf3a();
    virtual void vf3b();
    virtual void vf3c();
    virtual void vf3d();
    virtual void vf3e();
    virtual void vf3f();
    virtual bool IsActor();
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
    float m_fObjectScale;
    void FUN_00562230(BGSSaveFormBuffer* buf);
    void SaveGameBase(BGSSaveFormBuffer* buf);
    void SaveSub(BGSSaveFormBuffer* buf);
    void* Get3DSimple();
};

ExtraDataList_s* __fastcall GetExtraList(Refr_s* ref);
InvChanges_s* GetOrAddInventoryChanges(Refr_s* ref);

namespace fnv_00562de0 {
struct TargetRef
{
    void FUN_00865e50(FUN_00562e70* pData, int aU, int aV);
    void FUN_00865f60(unsigned int z9);
};

struct CallbackDesc
{
    unsigned int unk00;
    unsigned char bFlag;
    unsigned int nValue;
    void* pOwner;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

void __cdecl FUN_00c68900(void* p, CallbackDesc* pDesc, void (*pfn)());

}  // namespace fnv_00562de0

class TESForm;

int __fastcall FNV_GetFormType(TESForm* pForm);

namespace fnv_005659f0 {
struct Actor79;
struct Node79;
struct Controller79;
struct Anim79;
struct Process79;
struct Item79;
struct Update79
{
    float time;
    int flags;
    bool extra;
    Update79(float, int, int);
};
struct Name79
{
    const char* text;
    Name79(const char*);
    ~Name79();
};
struct Flag79
{
    unsigned int value;
    Flag79(unsigned int);
    Flag79(const Flag79&);
};
struct Sequence79
{
    int FUN_0059bb30();
    void hkpSimulationIsland_markForWrite(float);
    float FUN_00759450();
};
struct Controller79
{
    bool FUN_00566910();
    Sequence79* FUN_0047a520(const Name79&);
    void FUN_0047aab0(Sequence79*, int, int, float, float, int);
    void FUN_0047aa40(int);
    void FUN_0048fef0(float);
    Sequence79* FUN_00495d20(int);
};
struct Node79
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node79* IsSceneNode();
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
    virtual void Update(const Update79&, int);
    Controller79* FUN_0043b230();
    void FUN_00a59c60(const Update79&);
    Node79* FUN_00a5c570(void*);
    void FUN_00566930(int);
};
struct ModelList79
{
    bool FUN_0047fd90();
    const char* FUN_00717e50(const char*);
};
struct Base79
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
    ModelList79 models;
    int FUN_00401170();
    bool FUN_004c0bf0();
    unsigned int FUN_0084e3a0();
    void FUN_005fbdd0(Node79*);
};
struct Biped79
{
    void FUN_004aae70();
};
struct Anim79
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
    Anim79();
    bool FUN_0048ffd0(void*, Node79*, Actor79*, int);
    void FUN_00490330(const char*);
    void FUN_00491180(Actor79*, float, float);
    Node79* FUN_005585e0();
    Controller79* FUN_00496940();
};
struct Process79
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
    virtual void SetItem(Item79*, void*, int);
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
    virtual void SetAnimation(Controller79*, Node79*);
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
    virtual void Equip(bool, Biped79*, void*, Actor79*);
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
    virtual void* State();
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
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void SetDrawn(Actor79*, int);
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual bool IsBusy(int);
    int FUN_0045cd60();
};
struct SavedAnim79
{
    int unk00, unk04, unk08, unk0c;
    float time;
};
struct Extra79
{
    SavedAnim79* FUN_00418200();
    void FUN_0041ae10();
};
struct Item79
{
    Base79* FUN_0044ddc0();
};
struct Inventory79
{
    Item79* FUN_004c8c10(int, int);
};
struct Equip79
{
    void FUN_0087b360(Base79*);
};
struct Game79
{
    bool FUN_0042ce10();
    unsigned char FUN_0084a6d0(Actor79*, Flag79);
};
extern Game79* DAT_011ddf38;
struct Actor79
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
    virtual void* Parent();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual Biped79* Biped();
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
    virtual bool WeaponDrawn();
    virtual bool IsDead();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Base79* base;
    Node79* FUN_0043fcd0();
    Anim79* FUN_00572e50(Anim79*);
    bool FUN_00440d80();
    const char* FUN_005715d0();
    void* FUN_008a1760();
    void FUN_005726e0(Node79*, int);
    void FUN_00484b90(unsigned int);
    Base79* FUN_007af430();
    bool FUN_00572d30(int);
    bool FUN_00561d90();
    void FUN_005710c0();
    void* FUN_00566970(void*);
    float FUN_00568ad0();
    Process79* FUN_008d8520();
    bool FUN_00566950();
    const char* FUN_0055d520();
    void FUN_00571760(Base79*);
    bool FUN_008a6970();
    Biped79* FUN_00950b00(int);
    void* FUN_00950a60(int);
    bool FUN_008a16d0();
    void* FUN_008b70d0();
    Extra79* FUN_005d43c0();
    void FUN_005659f0();
};
extern Actor79* DAT_011dea3c;
extern const char* DAT_011977d8;
extern const char* DAT_01197820;
extern float DAT_0102f510;
Controller79* FUN_00653270(void*, Controller79*);
bool FUN_0047a490(Base79*);
bool FUN_0047aec0(Actor79*, bool, int);
Inventory79* FUN_004bf220(Actor79*);
bool FUN_008c7aa0();
Equip79* __stdcall FUN_004537b0(Actor79*);
int FUN_00ec7750(const char*, const char*);
void FUN_00406d30(char*, unsigned int, const char*);
char* FUN_0040ab30(char*, int);
void __cdecl FUN_005b5e40(const char*, ...);
void* operator new(unsigned int);
void operator delete(void*);
}  // namespace fnv_005659f0

namespace fnv_00566970 {
struct AnimationSet62
{
};
struct Manager62
{
    AnimationSet62* FUN_00447330(const char*, int, int, int);
    AnimationSet62* FUN_00447300(const char*, const char*, AnimationSet62*);
    void FUN_00447850(void*, AnimationSet62*);
};
extern Manager62* DAT_011c3b3c;
extern int DAT_0118a838[];
int FUN_00406d30(char*, unsigned int, const char*);
char* FUN_0040ab30(char*, int);
int __cdecl FUN_00ec623a(char*, const char*, ...);
}  // namespace fnv_00566970

struct ExtraL;

struct FUN_00567c50_cls
{
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48(unsigned int flags);

    void FUN_00567c50();
};

void* __fastcall FUN_00568e50(FUN_00567c50_cls* pThis);
void* __fastcall FUN_00559450(void* pThis);

struct MarkerPoint
{
    float x, y, z;
    MarkerPoint operator-(const MarkerPoint&) const;
    float Length() const;
};

class TESBoundObject
{
  public:
    virtual void BaseVirtual();
};
class TESHealthForm
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual unsigned int GetHealth();
};

typedef int(__thiscall* FUN_005692d0_VSlot)(void* self, unsigned char value);

struct TESForm;

namespace fnv_00569670 {
struct NiRTTI;
extern NiPoint3 NiPoint3_ZERO;

struct XTransform
{
    NiPoint3 operator*(const NiPoint3& pt) const;
};

struct XObject
{
    int unk00;
};

struct XAVObject : XObject
{
    XTransform* GetWorldTransform();
};

struct XNode : XAVObject
{
    unsigned int GetArrayCount();
    XAVObject* GetAt(unsigned int index);
};

struct GlobalObject_00a7b610
{
    int unk00;
};
extern GlobalObject_00a7b610 g_011c7d34;

XObject* NiDynamicCast(const NiRTTI* rtti, XObject* obj);

}  // namespace fnv_00569670

struct FUN_00438170
{
    void* value;
    FUN_00438170(const char* value);
    ~FUN_00438170();
};

struct FNV_569BE0_Inner
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual int ProcessTemporary(const struct FUN_00438170& value);
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void ConsumeResult(int result);
};

class NiFixedString
{
  public:
    NiFixedString(const char*);
    ~NiFixedString();
    void* m_kHandle;
};

struct TargetPoint : public XPos
{
    TargetPoint operator-(const TargetPoint&) const;
    TargetPoint operator*(float) const;
};

struct TargetMatrix
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8;
    TargetMatrix FUN_004b45b0() const;
    TargetPoint FUN_004b4500(const TargetPoint*) const;
};

struct TargetNode;
struct TargetObj
{
    virtual void pad00();
    virtual void pad04();
    virtual void pad08();
    virtual TargetNode* GetAsNiNode();
    virtual void pad10();
    virtual void pad14();
    virtual void pad18();
    virtual void pad1c();
    virtual void pad20();
    virtual void pad24();
    virtual void pad28();
    virtual void pad2c();
    virtual void pad30();
    virtual void pad34();
    virtual void pad38();
    virtual void pad3c();
    virtual void pad40();
    virtual void pad44();
    virtual void pad48();
    virtual void pad4c();
    virtual void pad50();
    virtual void pad54();
    virtual void pad58();
    virtual void pad5c();
    virtual void pad60();
    virtual void pad64();
    virtual void pad68();
    virtual void pad6c();
    virtual void pad70();
    virtual void pad74();
    virtual void pad78();
    virtual void pad7c();
    virtual void pad80();
    virtual void pad84();
    virtual void pad88();
    virtual void pad8c();
    virtual void pad90();
    virtual void pad94();
    virtual void pad98();
    virtual TargetObj* GetObjectByName(const NiFixedString&);
    virtual void pada0();
    virtual void pada4();
    virtual void pada8();
    virtual void padac();
    virtual void padb0();
    virtual void padb4();
    virtual void padb8();
    virtual void padbc();
    virtual void padc0();
    virtual void padc4();
    virtual void padc8();
    virtual void padcc();
    virtual void padd0();
    virtual void padd4();
    virtual void padd8();
    virtual void AttachChildInAvailableSlot(TargetObj*, bool);
    virtual void pade0();
    virtual void pade4();
    virtual void InsertChild(TargetObj*);
};

struct NiUpdateData
{
    NiUpdateData(float, bool, bool);
    float f0;
    int i1;
    int i2;
};

struct TargetNode : public TargetObj
{
    TargetNode(unsigned short = 0);
    void* operator new(size_t);
    static void operator delete(void*, unsigned int);
    void SetName(const NiFixedString&);
    void RemoveAllChildren();
    void FUN_00a5a040();
    void Update(const NiUpdateData&);
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
    void* p6;
    void* p7;
    void* p8;
    void* p9;
    void* pa;
    void* pb;
    void* pc;
    void* pd;
    void* pe;
    void* pf;
    void* p10;
    void* p11;
    void* p12;
    void* p13;
    void* p14;
    void* p15;
    void* p16;
    void* p17;
    void* p18;
    void* p19;
    void* p1a;
    void* p1b;
    void* p1c;
    void* p1d;
    void* p1e;
    void* p1f;
    void* p20;
    void* p21;
    void* p22;
    void* p23;
    void* p24;
    void* p25;
    void* p26;
    void* p27;
    void* p28;
    void* p29;
};

struct TargetRef;

struct TargetRef : public XRef
{
    virtual TargetPoint* GetPos_125();
    TargetMatrix FUN_0056fa00();
    void FUN_00569df0(bool a2);
};

bool __fastcall FUN_008256d0(void* node);
void* __fastcall FUN_00726070(void* node);

extern Twin_0084d030 DAT_011f6394;

namespace BuildReferenceScene {
struct Node;
}
struct TESModel
{
    virtual void slot00();
};
struct TESModelTextureSwap : TESModel
{
    void FUN_0048afe0(BuildReferenceScene::Node*);
};
namespace BuildReferenceScene {
struct Reference;
struct Scene;
struct Node;
struct Base;
struct Extra;
struct Controller;
struct ReferenceListNode;
struct AttachedSceneProvider;
struct ScenePointer;
struct Vector
{
    float x, y, z;
    Vector();
    Vector(float, float, float);
    Vector FUN_00439ef0(const Vector&);
    void FUN_0063c8a0(const Vector&);
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix();
    void FUN_004a0c90(float);
    Vector FUN_004b4500(const Vector&);
};
struct Update
{
    float time;
    unsigned int flags;
    unsigned int unk08;
    Update(float, int, int);
};
struct WorldPosition
{
    Vector* FUN_006815c0();
};
struct Node
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual Node* Child();
};
struct Scene
{
    virtual void s0();
    virtual void s4();
    virtual void s8();
    virtual Node* AsNode();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9c();
    virtual void sa0();
    virtual void sa4();
    virtual void sa8();
    virtual void sac();
    virtual void sb0();
    virtual void sb4();
    virtual void sb8();
    virtual void UpdateBounds();
    void FUN_00450f90(int);
    void FUN_0040f6e0();
    void FUN_00476ab0();
    void FUN_00440460(const Vector&);
    void FUN_0043fa80(const Matrix&);
    void FUN_00a59c60(const Update&);
    WorldPosition* FUN_0043d450();
    void FUN_0056c7d0(Reference*);
    void FUN_00440490(float);
    void FUN_00a5a040();
};
struct ScenePointer
{
    Scene* value;
    ScenePointer(Scene*);
    ~ScenePointer();
    bool FUN_00822510(int);
    Scene* FUN_00559450();
    void FUN_0066b0d0(Scene*);
};
struct TransformSource
{
    virtual void s00();
    virtual void Prepare();
    virtual void SetTransform(const float*);
    Scene* FUN_0056c7f0();
    void FUN_00413f90(float*);
};
struct Toggle
{
    void FUN_00937090(int);
};
struct LoadedState
{
    Toggle* FUN_0059bb30();
};
struct Cell
{
    LoadedState* FUN_004543c0();
};
struct Globals
{
    bool FUN_0042ce10();
    void FUN_0045ce40();
    bool FUN_00451530();
    AttachedSceneProvider* FUN_0070ec90(Reference*);
};
extern Globals* DAT_011ddf38;
extern Globals* DAT_011dea10;
struct CastType
{
};
extern CastType DAT_011831c4, DAT_011831e8;
void* FUN_00ec43fb(void*, int, CastType*, CastType*, int);
struct Destructible
{
    void FUN_00477780(Base*);
    bool FUN_00476f50(Reference*, int);
};
struct EnableObject
{
    void FUN_00551480(int);
};
struct EnableData
{
    EnableObject* FUN_0043a2b0();
};
struct Body
{
    virtual void s00();
    virtual void s4();
    virtual void s8();
    virtual void sc();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9c();
    virtual void sa0();
    virtual void sa4();
    virtual void sa8();
    virtual void sac();
    virtual void sb0();
    virtual void sb4();
    virtual void sb8();
    virtual void sbc();
    virtual void sc0();
    virtual void sc4();
    virtual void sc8();
    virtual void scc();
    virtual void sd0();
    virtual void sd4();
    virtual void SetFlag(bool, int);
};
struct SequenceTime
{
    float FUN_005f3780();
};
struct Sequence
{
    float FUN_00508100();
    void hkpSimulationIsland_markForWrite(float);
    SequenceTime* FUN_0048f7f0(int);
};
struct Anim
{
    bool FUN_00494710(int);
    void FUN_004955c0(int, int, int, float, int);
    Sequence* FUN_00491040(int);
    void FUN_00491180(Reference*, float, float);
    void FUN_00493900(Reference*);
};
struct Physics
{
    void bhkRagdollController_DisableRagdollAnim(int);
};
struct Process
{
    virtual void s0();
    virtual void s4();
    virtual void s8();
    virtual void sc();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void Update();
    int FUN_0045cd60();
    void FUN_008da1a0(Reference*);
};
struct LightData
{
    int unk00, unk04, unk08;
    LightData();
    ~LightData();
    bool FUN_00ad8ce0();
    void FUN_00ad8f20(Scene*);
};
struct ReferenceListNode
{
    Reference* data;
    ReferenceListNode* next;
    Reference** FUN_006815c0();
    ReferenceListNode* FUN_00726070();
};
struct GeometryType
{
    int FUN_008d8520();
};
struct SceneArray
{
    int FUN_0049c680(Scene* const&, int);
    void FUN_004ed8c0(Scene* const&);
};
struct Geometry
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned char unk80, unk81, unk82, dirty;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    SceneArray scenes;
};
struct AttachedScene
{
    GeometryType* FUN_004030b0();
    Geometry* FUN_00a59d30(int);
};
struct AttachedSceneProvider
{
    AttachedScene* FUN_004e8030();
};
struct Manager
{
    void FUN_00b5eed0(Scene*);
};
Manager* FUN_00450b80(int);
struct ExtraLink
{
    int FUN_0057c6a0(const ScenePointer&, int);
    void FUN_0056c810(Scene*);
};
struct LinkPointer
{
    ExtraLink* FUN_0045c650();
    void FUN_0056c810(Scene*);
};
struct LinkedReference
{
    LinkPointer* FUN_005699b0();
};
struct ExtraAttachment
{
    void FUN_00437f90(Scene*);
};
struct Extra
{
    TransformSource* FUN_0041fbe0();
    float FUN_0041b6b0();
    void FUN_00422c20();
    void FUN_00422a40(Reference*);
    void FUN_00418890(LightData*);
    ReferenceListNode* FUN_0041f810();
    ReferenceListNode* FUN_0041f7e0();
    bool FUN_00420810();
    LinkedReference* FUN_004208b0();
};
struct Base
{
    virtual void s0();
    virtual void s4();
    virtual void s8();
    virtual void sc();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9c();
    virtual void sa0();
    virtual void sa4();
    virtual void sa8();
    virtual bool Special();
    virtual void sb0();
    virtual void sb4();
    virtual void sb8();
    virtual void sbc();
    virtual void sc0();
    virtual void sc4();
    virtual void sc8();
    virtual void scc();
    virtual void sd0();
    virtual void sd4();
    virtual void sd8();
    virtual void sdc();
    virtual void se0();
    virtual void se4();
    virtual void se8();
    virtual void sec();
    virtual void sf0();
    virtual void sf4();
    virtual void sf8();
    virtual void sfc();
    virtual void s100();
    virtual void s104();
    virtual void s108();
    virtual void s10c();
    virtual void s110();
    virtual void s114();
    virtual void s118();
    virtual void s11c();
    virtual void s120();
    virtual void s124();
    virtual void s128();
    virtual void s12c();
    virtual void s130();
    virtual void s134();
    virtual void s138();
    virtual void s13c();
    virtual void s140();
    virtual void s144();
    virtual void s148();
    virtual void s14c();
    virtual void s150();
    virtual void s154();
    virtual void s158();
    virtual void s15c();
    virtual void s160();
    virtual void s164();
    virtual void s168();
    virtual void s16c();
    virtual void s170();
    virtual void s174();
    virtual Scene* Create(Reference*);
    int FUN_00401170();
    void FUN_006056f0(Reference*);
    bool FUN_00452440();
};
extern Base* DAT_011ca240;
extern const double DAT_01012060, DAT_01017a40;
extern const char DAT_010300b0[], DAT_01019f08[];
struct Finalizer
{
    void FUN_006c0c30();
};
Finalizer* __stdcall GetNavMeshObstacleManager(Reference*);
struct Reference
{
    virtual void s0();
    virtual void s4();
    virtual void s8();
    virtual void sc();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void SetState(int);
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9c();
    virtual void sa0();
    virtual void sa4();
    virtual void sa8();
    virtual void sac();
    virtual void sb0();
    virtual void sb4();
    virtual bool FlagB8();
    virtual void sbc();
    virtual void sc0();
    virtual void sc4();
    virtual void sc8();
    virtual void scc();
    virtual void sd0();
    virtual void sd4();
    virtual void sd8();
    virtual void sdc();
    virtual void se0();
    virtual void se4();
    virtual void se8();
    virtual void sec();
    virtual void sf0();
    virtual void sf4();
    virtual void sf8();
    virtual void sfc();
    virtual bool IsActor();
    virtual void s104();
    virtual void s108();
    virtual void s10c();
    virtual void s110();
    virtual void s114();
    virtual void s118();
    virtual void s11c();
    virtual void s120();
    virtual void s124();
    virtual void s128();
    virtual void s12c();
    virtual const char* Name();
    virtual void s134();
    virtual void s138();
    virtual void s13c();
    virtual void s140();
    virtual void s144();
    virtual void s148();
    virtual void s14c();
    virtual bool Flag150();
    virtual void s154();
    virtual void s158();
    virtual bool Flag15C();
    virtual void s160();
    virtual void s164();
    virtual void s168();
    virtual void s16c();
    virtual void s170();
    virtual void s174();
    virtual void s178();
    virtual void s17c();
    virtual void s180();
    virtual void s184();
    virtual void s188();
    virtual void s18c();
    virtual void s190();
    virtual void s194();
    virtual void s198();
    virtual void s19c();
    virtual void s1a0();
    virtual void s1a4();
    virtual void s1a8();
    virtual void s1ac();
    virtual void s1b0();
    virtual void s1b4();
    virtual Body* GetBody(int);
    virtual void s1bc();
    virtual void s1c0();
    virtual void s1c4();
    virtual void s1c8();
    virtual void s1cc();
    virtual void* GetAttachment();
    virtual bool RandomPhase();
    virtual void s1d8();
    virtual void s1dc();
    virtual void s1e0();
    virtual Anim* ComputePositionAtTime();
    virtual void s1e8();
    virtual void s1ec();
    virtual void s1f0();
    virtual void s1f4();
    virtual void s1f8();
    virtual void s1fc();
    virtual void s200();
    virtual void s204();
    virtual void s208();
    virtual void s20c();
    virtual void s210();
    virtual void s214();
    virtual void s218();
    virtual void s21c();
    virtual void s220();
    virtual void s224();
    virtual void s228();
    virtual bool IsDead(int);
    virtual void s230();
    virtual void s234();
    virtual void s238();
    virtual void s23c();
    virtual void s240();
    virtual void s244();
    virtual void s248();
    virtual void s24c();
    virtual void s250();
    virtual void s254();
    virtual void s258();
    virtual void s25c();
    virtual void s260();
    virtual void s264();
    virtual void s268();
    virtual void s26c();
    virtual void s270();
    virtual void s274();
    virtual void s278();
    virtual void s27c();
    virtual void s280();
    virtual void s284();
    virtual void s288();
    virtual void s28c();
    virtual void s290();
    virtual void s294();
    virtual void s298();
    virtual void s29c();
    virtual void s2a0();
    virtual void s2a4();
    virtual void s2a8();
    virtual void s2ac();
    virtual void s2b0();
    virtual void s2b4();
    virtual void s2b8();
    virtual void s2bc();
    virtual void s2c0();
    virtual void s2c4();
    virtual void s2c8();
    virtual void s2cc();
    virtual void s2d0();
    virtual void s2d4();
    virtual void s2d8();
    virtual void s2dc();
    virtual void s2e0();
    virtual void s2e4();
    virtual void s2e8();
    virtual void s2ec();
    virtual void s2f0();
    virtual void s2f4();
    virtual void s2f8();
    virtual void s2fc();
    virtual void s300();
    virtual void s304();
    virtual void s308();
    virtual void s30c();
    virtual void s310();
    virtual void s314();
    virtual void s318();
    virtual void s31c();
    virtual void s320();
    virtual void s324();
    virtual void s328();
    virtual void s32c();
    virtual void s330();
    virtual void s334();
    virtual void s338();
    virtual void s33c();
    virtual void s340();
    virtual void s344();
    virtual void s348();
    virtual void s34c();
    virtual void s350();
    virtual void s354();
    virtual void s358();
    virtual void s35c();
    virtual void s360();
    virtual void s364();
    virtual void s368();
    virtual void s36c();
    virtual void s370();
    virtual void s374();
    virtual void s378();
    virtual void s37c();
    virtual void s380();
    virtual void s384();
    virtual void SetActorFlag(bool);
    virtual bool IsKnocked();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    Base* base;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    Vector position;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    Physics* physics;
    bool FUN_00440da0();
    bool FUN_00440d80();
    Base* FUN_007af430();
    Cell* FUN_008d6f30();
    void FUN_0057c180();
    Scene* FUN_0043fcd0();
    Extra* FUN_005d43c0();
    void FUN_0056c880(int, bool);
    void FUN_00570f70(Scene*);
    bool FUN_0056c760();
    void FUN_0056c780(int);
    bool FUN_00452370();
    bool FUN_00508d70();
    void FUN_0057a3c0(int);
    TESModel* FUN_00571630();
    bool FUN_008d4ab0(Scene*);
    bool FUN_00448a20();
    Matrix FUN_0056fa00();
    bool FUN_00564cd0();
    EnableData* FUN_00568e50();
    float FUN_00567400();
    void FUN_005659f0();
    void FUN_008b0bd0(Scene*);
    Process* FUN_008d8520();
    void FUN_008d4b60();
    bool FUN_005722c0(int);
    Vector* FUN_00430830();
    void FUN_00577330(int);
    void UpdateLightDescriptors(int);
    void FUN_00576d50(Scene*);
    bool FUN_00565050();
    bool FUN_00564f00();
    ScenePointer* FUN_005725f0();
    bool FUN_004077c0();
    Scene* FUN_00569920();
    bool FUN_0057bd80(Scene*);
    int FUN_0084e3a0();
    ExtraAttachment* FUN_00527080(int);
    Scene* FUN_0056b2d0(unsigned char);
};
Destructible* FUN_00475400(Base*);
void FUN_00577e20(Scene*);
void FUN_00578300(Scene*);
void FUN_005784f0(Node*, float);
void FUN_00c6bd00(Scene*, int);
void FUN_00c9b670(Scene*, Vector*, int, float, int);
bool FUN_0062c3c0(Reference*, Scene*);
void FUN_00406d00(char*, int, const char*, ...);
void FUN_005b5e40(const char*, ...);
void FUN_0055d6d0(Reference*, Scene*);

}

struct PhantomBase
{
    PhantomBase();
    virtual ~PhantomBase();
};

struct PhantomOwner
{
    struct FUN_0056e370 : public PhantomBase
    {
        FUN_0056e370();
        virtual ~FUN_0056e370();
        void FUN_0056e350();
    };
};

namespace fnv_0056fcb0 {
// FUN_0056fcb0 v7 - hoisted body-scope decls + nested-guard tail
struct XObj;
struct XExtra;
struct ListNode;
struct Xtra;

struct ArrObj
{
    XObj* arr[4];
};

struct Xtra
{
    int FUN_006629f0();
    XObj* FUN_0045c650(void* a1, GlobalObject_00633c90* a2);
    XObj* FUN_006ab360();
};

struct ListNode
{
    XObj** FUN_006815c0();
    ListNode* FUN_00726070();
};

struct XExtra
{
    ListNode* FUN_00420770();
    ListNode* FUN_0041f810();
    XObj* FUN_00420dd0();
    XObj* FUN_00420bc0(int a1);
    void FUN_00420da0(XObj* a1);
    XObj* FUN_00420ed0();
    XObj* FUN_00422120();
    XObj* FUN_00421e10();
    ArrObj* FUN_00420410();
    void FUN_0041f840(XObj* a1, int a2);
};

struct GObj
{
    void FUN_0045ce60();
    XObj* FUN_0070ec90();
};

extern GObj* DAT_011dea10;
extern XObj* DAT_011ca234;
extern XObj* DAT_011ca23c;

struct YObj
{
    void FUN_0057c730(void* a1);
};

struct Node38
{
    char pad[0x128];
    YObj sub;
};

struct XObj
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual void vtbl064();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual void vtbl100();
    virtual void vtbl101();
    virtual void vtbl102();
    virtual void vtbl103();
    virtual void vtbl104();
    virtual void vtbl105();
    virtual void vtbl106();
    virtual void vtbl107();
    virtual void vtbl108();
    virtual void vtbl109();
    virtual void vtbl110();
    virtual void vtbl111();
    virtual void vtbl112();
    virtual void vtbl113();
    virtual void vtbl114();
    virtual void vtbl115();
    virtual int Virt1d0();
    char pad40[0x3C];
    XObj* m_40;
    XObj* FUN_007af430();
    int FUN_00401170();
    void FUN_0057b520(int a1);
    Xtra* FUN_005699b0();
    XExtra* FUN_005d43c0();
    XObj* FUN_005725f0();
    int FUN_00559450();
    XObj* FUN_008d6f30();
    XObj* FUN_004543c0();
    XObj* FUN_0045cd60();
    void FUN_0061f890(XObj* a1, int a2);
    XObj* FUN_004e8030(XObj* a1);
    void FUN_004e52f0(XObj* a1);
    XObj* FUN_004030b0();
    int FUN_008d8520();
    Node38* FUN_00a59d30(int a1);
    void FUN_00545360(XObj* a1);
    void FUN_005454f0(XObj* a1);
    XObj* FUN_0059bb30();
    void FUN_00631370(XObj* a1, int a2, int a3);
    void FUN_005456e0(XObj* a1);
    void FUN_006312d0(XObj* a1);
    XObj* FUN_009d9f20();
    void FUN_00c5b060(XObj* a1);
    void FUN_00c39ad0(XObj* a1);
    void FUN_00c5aec0(XObj* a1);
    void FUN_00c5b190(XObj* a1);
    void FUN_0057c730(void* a1);
    void FUN_009707f0(int a1);
    void FUN_00420ba0(int a1);
    void FUN_0057c5d0();
    void FUN_0056fcb0();
};

}  // namespace fnv_0056fcb0

struct NiPoint3s
{
    float x;
    float y;
    float z;
};
struct WorldSpaceS;
struct CellS
{
    bool IsInteriorS();
    WorldSpaceS* GetWorldSpaceS();
};
struct RefS;
struct RefS
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
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
    virtual NiPoint3s* GetPosS();
    bool GetDisabledS();
    bool IsDeletedS();
    CellS* GetParentCellS();
    float GetDistanceS(NiPoint3s* pos);
    float FUN_005723b0(RefS* other, bool allowDisabled, bool ignoreCell);
};

class B5729E0Light;

class B5729E0ShadowSceneNode
{
  public:
    void FUN_00b5eed0(B5729E0Light* pkLight);
};

B5729E0ShadowSceneNode* __cdecl FUN_00450b80(unsigned int uiIndex);

namespace fnv_00572b60 {
struct Pt3
{
    float x;
    float y;
    float z;
    bool operator!=(const Pt3& other) const;
};

extern Pt3 NiPoint3_ZERO;

enum MEM_CONTEXT
{
    MC_0x31 = 0x31
};

struct AutoMemContext
{
    int unk00;
    AutoMemContext(MEM_CONTEXT ctx, bool b, const char* file, int line);
    ~AutoMemContext();
};

class TESObjectREFR572;

struct RefrUpdater
{
    float unk00;
    float unk04;
    float unk08;
    void ApplyPosition();
    void ApplyAngle();
};

class TESObjectREFR572
{
  public:
    virtual void Virtual000();
    virtual void Virtual001();
    virtual void Virtual002();
    virtual void Virtual003();
    virtual void Virtual004();
    virtual void Virtual005();
    virtual void Virtual006();
    virtual void Virtual007();
    virtual void Virtual008();
    virtual void Virtual009();
    virtual void Virtual00A();
    virtual void Virtual00B();
    virtual void Virtual00C();
    virtual void Virtual00D();
    virtual void Virtual00E();
    virtual void Virtual00F();
    virtual void Virtual010();
    virtual void Virtual011();
    virtual void Virtual012();
    virtual void Virtual013();
    virtual void Virtual014();
    virtual void Virtual015();
    virtual void Virtual016();
    virtual void Virtual017();
    virtual void Virtual018();
    virtual void Virtual019();
    virtual void Virtual01A();
    virtual void Virtual01B();
    virtual void Virtual01C();
    virtual void Virtual01D();
    virtual void Virtual01E();
    virtual void Virtual01F();
    virtual void Virtual020();
    virtual void Virtual021();
    virtual void Virtual022();
    virtual void Virtual023();
    virtual void Virtual024();
    virtual void Virtual025();
    virtual void Virtual026();
    virtual void Virtual027();
    virtual void Virtual028();
    virtual void Virtual029();
    virtual void Virtual02A();
    virtual void Virtual02B();
    virtual void Virtual02C();
    virtual void Virtual02D();
    virtual void Virtual02E();
    virtual void Virtual02F();
    virtual void Virtual030();
    virtual void Virtual031();
    virtual void Virtual032();
    virtual void Virtual033();
    virtual void Virtual034();
    virtual void Virtual035();
    virtual void Virtual036();
    virtual void Virtual037();
    virtual void Virtual038();
    virtual void Virtual039();
    virtual void Virtual03A();
    virtual void Virtual03B();
    virtual void Virtual03C();
    virtual void Virtual03D();
    virtual void Virtual03E();
    virtual void Virtual03F();
    virtual void Virtual040();
    virtual void Virtual041();
    virtual void Virtual042();
    virtual void Virtual043();
    virtual void Virtual044();
    virtual void Virtual045();
    virtual void Virtual046();
    virtual void Virtual047();
    virtual void Virtual048();
    virtual void Virtual049();
    virtual void Virtual04A();
    virtual void Virtual04B();
    virtual void Virtual04C();
    virtual void Virtual04D();
    virtual void Virtual04E();
    virtual void Virtual04F();
    virtual void Virtual050();
    virtual void Virtual051();
    virtual void Virtual052();
    virtual void Virtual053();
    virtual void Virtual054();
    virtual void Virtual055();
    virtual void Virtual056();
    virtual void Virtual057();
    virtual void Virtual058();
    virtual void Virtual059();
    virtual void Virtual05A();
    virtual void Virtual05B();
    virtual void Virtual05C();
    virtual void Virtual05D();
    virtual void Virtual05E();
    virtual void Virtual05F();
    virtual void Virtual060();
    virtual void Virtual061();
    virtual void Virtual062();
    virtual void Virtual063();
    virtual void Virtual064();
    virtual void Virtual065();
    virtual void Virtual066();
    virtual void Virtual067();
    virtual void Virtual068();
    virtual void Virtual069();
    virtual void Virtual06A();
    virtual void Virtual06B();
    virtual void Virtual06C();
    virtual void Virtual06D();
    virtual void Virtual06E();
    virtual void Virtual06F();
    virtual void Virtual070();
    virtual void Virtual071();
    virtual void Virtual072();
    virtual void Virtual073();
    virtual void Virtual074();
    virtual void Virtual075();
    virtual void Virtual076();
    virtual void Virtual077();
    virtual void Virtual078();
    virtual void Virtual079();
    virtual void Virtual07A();
    virtual void Virtual07B();
    virtual void Virtual07C();
    virtual const Pt3* GetPos();
    const Pt3& GetAngleOnReference() const;
    RefrUpdater MakeUpdater(TESObjectREFR572* ref, Pt3 pt);
    void FUN_00572b60(Pt3 pos);
};

}  // namespace fnv_00572b60

namespace fnv_00573170 {
struct ActRef;

struct ActForm
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual bool Activate(struct ActRef* apRef, struct ActRef* apActivator, bool abFlag, ActForm* apObject,
                          int aiCount);
    int GetFormType();
    const char* GetEditorName();
};

struct ActProcess
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38C();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39C();
    virtual void v3A0();
    virtual void v3A4();
    virtual void v3A8();
    virtual void v3AC();
    virtual void v3B0();
    virtual void v3B4();
    virtual void v3B8();
    virtual void v3BC();
    virtual void v3C0();
    virtual void v3C4();
    virtual void v3C8();
    virtual void v3CC();
    virtual void v3D0();
    virtual void v3D4();
    virtual void v3D8();
    virtual void v3DC();
    virtual void v3E0();
    virtual void v3E4();
    virtual void v3E8();
    virtual void v3EC();
    virtual void v3F0();
    virtual void v3F4();
    virtual void v3F8();
    virtual void v3FC();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40C();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41C();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42C();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43C();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44C();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45C();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46C();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47C();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48C();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49C();
    virtual void v4A0();
    virtual void v4A4();
    virtual void v4A8();
    virtual void v4AC();
    virtual void v4B0();
    virtual void v4B4();
    virtual void v4B8();
    virtual void v4BC();
    virtual void v4C0();
    virtual void v4C4();
    virtual void v4C8();
    virtual void v4CC();
    virtual void v4D0();
    virtual void v4D4();
    virtual void v4D8();
    virtual void v4DC();
    virtual void v4E0();
    virtual void v4E4();
    virtual void v4E8();
    virtual void v4EC();
    virtual void v4F0();
    virtual void v4F4();
    virtual void v4F8();
    virtual void v4FC();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50C();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51C();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52C();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53C();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54C();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55C();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56C();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57C();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58C();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59C();
    virtual void v5A0();
    virtual void v5A4();
    virtual void v5A8();
    virtual void v5AC();
    virtual void v5B0();
    virtual void v5B4();
    virtual void v5B8();
    virtual void v5BC();
    virtual void v5C0();
    virtual void v5C4();
    virtual void v5C8();
    virtual void v5CC();
    virtual void v5D0();
    virtual void v5D4();
    virtual void v5D8();
    virtual void v5DC();
    virtual void v5E0();
    virtual void v5E4();
    virtual void v5E8();
    virtual void v5EC();
    virtual void v5F0();
    virtual void v5F4();
    virtual void v5F8();
    virtual void v5FC();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60C();
    virtual int GetKnockedState();
    void* GetDetectionData();
};

struct ActCell
{
    bool IsInterior();
    void UpdateDoorEvent();
};

struct ActTeleport
{
    ActCell* GetDestinationCell();
};

struct ActExtraList
{
    ActRef* GetLinkedRef();
    bool HasLock();
    void* CanUnlock(ActRef* apActivator);
    void SetLastActivator(ActRef* apRef, ActRef* apActivator);
    void SetFlag(int aiFlag);
};

struct ActRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual bool IsInCombatOrSneaking(int aiUnk);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ActForm* pBaseForm;

    ActForm* GetBaseForm();
    ActExtraList* GetExtraList();
    ActProcess* GetCurrentProcess();
    bool IsPersistentLocked();
    const char* GetFullName();
    bool IsDisabledActivation();
    bool GetAction(int aiAction);
    void PerformAction(int aiAction);
    void RunActivateScript(ActRef* apActivator);
    void RunOnActivateBlock();
    ActTeleport* GetTeleportData();
    void HandleActivation(ActRef* apActivator);
    bool FUN_00573170(ActRef* apActivator, bool abFlag, ActForm* apObject, int aiCount);
};

extern "C" int __cdecl sprintf(char* apBuffer, const char* apFormat, ...);

}  // namespace fnv_00573170

namespace fnv_00573800 {
struct MoveRef;
struct MoveCell;
struct MoveWorld;
struct MoveProcess;
struct MoveController;
struct MovePoint
{
    float x, y, z;
};
struct MoveAnim
{
    bool active();
    void enable(bool);
};
struct MoveBody
{
    MoveAnim* name();
};
struct MoveExtra
{
    void clear();
    void* original();
    void set(MoveRef*);
};
struct MoveController
{
    void height(float);
    void position(MovePoint*);
};
struct MoveCell
{
    bool interior();
    void add(MoveRef*, bool);
    void remove(MoveRef*);
};
struct MoveWorld
{
    void remove(MoveRef*);
    void add(MoveRef*);
    MoveCell* cell(int, int);
};
struct MoveRef
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
    virtual void changed(int);
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
    virtual void clearFlag(int);
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual bool actor();
    virtual bool player();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void unused96();
    virtual void unused97();
    virtual void unused98();
    virtual void unused99();
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
    virtual void notify();
    virtual void load();
    virtual void unused114();
    virtual void unload(int, int);
    virtual MoveBody* body();
    virtual void unused117();
    virtual void unused118();
    virtual void unused119();
    virtual void unused120();
    virtual void unused121();
    virtual void unused122();
    virtual void unused123();
    virtual void unused124();
    virtual MovePoint* position();
    virtual void unused126();
    virtual void update(int);
    virtual void unused128();
    virtual void unused129();
    virtual void unused130();
    virtual void unused131();
    virtual void unused132();
    virtual void unused133();
    virtual void unused134();
    virtual void unused135();
    virtual void unused136();
    virtual void unused137();
    virtual void setCell(MoveCell*);
    virtual bool test(int);
    MoveController* controller();
    MoveWorld* world();
    MoveCell* cell();
    MoveExtra* extra();
    bool persistent();
    MoveProcess* process();
    int state();
    bool sleeping();
};
struct MoveProcess
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
    virtual void reset();
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
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void unused96();
    virtual void unused97();
    virtual void unused98();
    virtual void unused99();
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
    virtual void unused125();
    virtual void unused126();
    virtual void unused127();
    virtual void unused128();
    virtual void unused129();
    virtual void unused130();
    virtual void unused131();
    virtual void unused132();
    virtual void unused133();
    virtual void unused134();
    virtual void unused135();
    virtual void unused136();
    virtual void unused137();
    virtual void unused138();
    virtual void unused139();
    virtual void unused140();
    virtual void unused141();
    virtual void unused142();
    virtual void unused143();
    virtual void unused144();
    virtual void unused145();
    virtual void unused146();
    virtual void unused147();
    virtual void unused148();
    virtual void unused149();
    virtual void unused150();
    virtual void unused151();
    virtual void unused152();
    virtual void unused153();
    virtual void unused154();
    virtual void unused155();
    virtual void unused156();
    virtual void unused157();
    virtual void unused158();
    virtual void unused159();
    virtual void unused160();
    virtual void unused161();
    virtual void unused162();
    virtual void* ready();
    int level();
};
struct MoveTES
{
    bool attached(MoveCell*, bool);
};
extern MoveTES* g_TES;
struct MoveSave
{
    bool loading();
    bool save(MoveRef*);
};
extern MoveSave* g_TESSaveLoadGame;
extern MoveRef* _g_thePlayer;
}  // namespace fnv_00573800

namespace fnv_00574b30 {
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct RefOps;
struct ExtraOps;
struct EntryOps;
struct ListOps;
struct ScriptOps;
struct NodeOps
{
    ExtraOps** FUN_006815c0();
};
struct DataOps
{
    NodeOps* FUN_00559450();
};
struct FUN_004bc650 : DataOps
{
    int unk00, unk04, unk08;
    FUN_004bc650(void*);
};
struct FUN_00410360
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_00410360();
    void FUN_00419ad0(unsigned short);
    ScriptOps* FUN_00418800();
    void FUN_00419ed0(ScriptOps*);
    void FUN_00419f80(void*);
    void* FUN_00418830();
};
struct FUN_0055a2f0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual ~FUN_0055a2f0();
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
    void FUN_00484490();
};
struct ScriptOps
{
    void* FUN_005abf60();
    bool FUN_005ac1e0(FUN_0055a2f0*, void*, int, bool);
};
struct ExtraOps
{
    void FUN_0041c7f0(RefOps*);
};
struct EntryOps
{
    EntryOps* GetOrFallback(int);
    EntryOps* FUN_004fd400();
    bool FUN_004c0bf0();
    EntryOps* Script_IsInListFunction(RefOps*);
};
struct ListOps
{
    void FUN_004c3380(FUN_004bc650*, bool);
    void FUN_004c29a0(EntryOps*, FUN_00410360*, bool);
    void FUN_004c1c90(RefOps*, int, bool, bool);
};
struct RefOps
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
    virtual void v048(unsigned int);
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
    virtual bool v100();
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
    virtual bool v224();
    void* FUN_0055d310();
    bool FUN_00440da0();
    RefOps* FUN_008d6f30();
    bool FUN_005656d0();
    void FUN_00545560(RefOps*);
    void* FUN_007af430();
    ExtraOps* FUN_005d43c0();
    void* FUN_009d9f00();
    EntryOps* FUN_00476c90();
    bool FUN_005653d0();
    void FUN_00574b30(RefOps*, int, bool, bool);
};
extern RefOps* DAT_011dea3c;
void __cdecl FUN_005ac750(RefOps*, void*, int);
ListOps* __cdecl FUN_004bf220(RefOps*);
ScriptOps* __cdecl FUN_004826d0(EntryOps*);
}  // namespace fnv_00574b30

struct Unknown;

// Actor parent-cell change: update the water height for the new cell, notify the player hooks and the process.

class F5BB0Actor;

class F5BB0Cell
{
  public:
    bool IsInterior() const;
    float UpdateTESState();
};

struct F5BB0WaterData
{
    int unk00;
    int unk04;
    float m_fWaterValue;
};

class F5BB0ExtraDataList
{
  public:
    void* GetPersistentCell();
};

class F5BB0Process
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual void Unk0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual void Unk100();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11C();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Unk128();
    virtual void Unk12C();
    virtual void Unk130();
    virtual void Unk134();
    virtual void Unk138();
    virtual void Unk13C();
    virtual void Unk140();
    virtual void Unk144();
    virtual void Unk148();
    virtual void Unk14C();
    virtual void Unk150();
    virtual void Unk154();
    virtual void Unk158();
    virtual void Unk15C();
    virtual void Unk160();
    virtual void Unk164();
    virtual void Unk168();
    virtual void Unk16C();
    virtual void Unk170();
    virtual void Unk174();
    virtual void Unk178();
    virtual void Unk17C();
    virtual void Unk180();
    virtual void Unk184();
    virtual void Unk188();
    virtual void Unk18C();
    virtual void Unk190();
    virtual void Unk194();
    virtual void Unk198();
    virtual void Unk19C();
    virtual void Unk1A0();
    virtual void Unk1A4();
    virtual void Unk1A8();
    virtual void Unk1AC();
    virtual void Unk1B0();
    virtual void Unk1B4();
    virtual void Unk1B8();
    virtual void Unk1BC();
    virtual void Unk1C0();
    virtual void Unk1C4();
    virtual void Unk1C8();
    virtual void Unk1CC();
    virtual void Unk1D0();
    virtual void Unk1D4();
    virtual void Unk1D8();
    virtual void Unk1DC();
    virtual void Unk1E0();
    virtual void Unk1E4();
    virtual void Unk1E8();
    virtual void Unk1EC();
    virtual void Unk1F0();
    virtual void Unk1F4();
    virtual void Unk1F8();
    virtual void Unk1FC();
    virtual void Unk200();
    virtual void Unk204();
    virtual void Unk208();
    virtual void Unk20C();
    virtual void Unk210();
    virtual void Unk214();
    virtual void Unk218();
    virtual void Unk21C();
    virtual void Unk220();
    virtual void Unk224();
    virtual void Unk228();
    virtual void Unk22C();
    virtual void Unk230();
    virtual void Unk234();
    virtual void Unk238();
    virtual void Unk23C();
    virtual void Unk240();
    virtual void Unk244();
    virtual void Unk248();
    virtual void Unk24C();
    virtual void Unk250();
    virtual void Unk254();
    virtual void Unk258();
    virtual void Unk25C();
    virtual void Unk260();
    virtual void Unk264();
    virtual void Unk268();
    virtual void Unk26C();
    virtual void Unk270();
    virtual void Unk274();
    virtual void Unk278();
    virtual void Unk27C();
    virtual void Unk280();
    virtual void Unk284();
    virtual void Unk288();
    virtual void Unk28C();
    virtual void Unk290();
    virtual void Unk294();
    virtual void Unk298();
    virtual void Unk29C();
    virtual void Unk2A0();
    virtual void Unk2A4();
    virtual void Unk2A8();
    virtual void Unk2AC();
    virtual void Unk2B0();
    virtual void Unk2B4();
    virtual void Unk2B8();
    virtual void Unk2BC();
    virtual void Unk2C0();
    virtual void Unk2C4();
    virtual void Unk2C8();
    virtual void Unk2CC();
    virtual void Unk2D0();
    virtual void Unk2D4();
    virtual void Unk2D8();
    virtual void Unk2DC();
    virtual void Unk2E0();
    virtual void Unk2E4();
    virtual void Unk2E8();
    virtual void Unk2EC();
    virtual void Unk2F0();
    virtual void Unk2F4();
    virtual void Unk2F8();
    virtual void Unk2FC();
    virtual void Unk300();
    virtual void Unk304();
    virtual void Unk308();
    virtual void Unk30C();
    virtual void Unk310();
    virtual void Unk314();
    virtual void Unk318();
    virtual void Unk31C();
    virtual void Unk320();
    virtual void Unk324();
    virtual void Unk328();
    virtual void Unk32C();
    virtual void Unk330();
    virtual void Unk334();
    virtual void Unk338();
    virtual void Unk33C();
    virtual void Unk340();
    virtual void Unk344();
    virtual void Unk348();
    virtual void Unk34C();
    virtual void Unk350();
    virtual void Unk354();
    virtual void Unk358();
    virtual void Unk35C();
    virtual void Unk360();
    virtual void Unk364();
    virtual void Unk368();
    virtual void Unk36C();
    virtual void Unk370();
    virtual void Unk374();
    virtual void Unk378();
    virtual void Unk37C();
    virtual void Unk380();
    virtual void Unk384();
    virtual void Unk388();
    virtual void Unk38C();
    virtual void Unk390();
    virtual void Unk394();
    virtual void Unk398();
    virtual void Unk39C();
    virtual void Unk3A0();
    virtual void Unk3A4();
    virtual void Unk3A8();
    virtual void Unk3AC();
    virtual void Unk3B0();
    virtual void Unk3B4();
    virtual void Unk3B8();
    virtual void Unk3BC();
    virtual void Unk3C0();
    virtual void Unk3C4();
    virtual void Unk3C8();
    virtual void Unk3CC();
    virtual void Unk3D0();
    virtual void Unk3D4();
    virtual void Unk3D8();
    virtual void Unk3DC();
    virtual void Unk3E0();
    virtual void Unk3E4();
    virtual void Unk3E8();
    virtual void Unk3EC();
    virtual void Unk3F0();
    virtual void Unk3F4();
    virtual void Unk3F8();
    virtual void Unk3FC();
    virtual void Unk400();
    virtual void Unk404();
    virtual void Unk408();
    virtual void Unk40C();
    virtual void Unk410();
    virtual void Unk414();
    virtual void Unk418();
    virtual void Unk41C();
    virtual void Unk420();
    virtual void Unk424();
    virtual void Unk428();
    virtual void Unk42C();
    virtual void Unk430();
    virtual void Unk434();
    virtual void Unk438();
    virtual void Unk43C();
    virtual void Unk440();
    virtual void Unk444();
    virtual void Unk448();
    virtual void Unk44C();
    virtual void Unk450();
    virtual void Unk454();
    virtual void Unk458();
    virtual void Unk45C();
    virtual void Unk460();
    virtual void Unk464();
    virtual void Unk468();
    virtual void Unk46C();
    virtual void Unk470();
    virtual void Unk474();
    virtual void Unk478();
    virtual void Unk47C();
    virtual void Unk480();
    virtual void Unk484();
    virtual void Unk488();
    virtual void Unk48C();
    virtual void Unk490();
    virtual void Unk494();
    virtual void Unk498();
    virtual void Unk49C();
    virtual void Unk4A0();
    virtual void Unk4A4();
    virtual void Unk4A8();
    virtual void Unk4AC();
    virtual void Unk4B0();
    virtual void Unk4B4();
    virtual void Unk4B8();
    virtual void Unk4BC();
    virtual void Unk4C0();
    virtual void Unk4C4();
    virtual void Unk4C8();
    virtual void Unk4CC();
    virtual void Unk4D0();
    virtual void Unk4D4();
    virtual void Unk4D8();
    virtual void Unk4DC();
    virtual void Unk4E0();
    virtual void Unk4E4();
    virtual void Unk4E8();
    virtual void Unk4EC();
    virtual void Unk4F0();
    virtual void Unk4F4();
    virtual void Unk4F8();
    virtual void Unk4FC();
    virtual void Unk500();
    virtual void Unk504();
    virtual void Unk508();
    virtual void Unk50C();
    virtual void Unk510();
    virtual void Unk514();
    virtual void Unk518();
    virtual void Unk51C();
    virtual void Unk520();
    virtual void Unk524();
    virtual void Unk528();
    virtual void Unk52C();
    virtual void Unk530();
    virtual void Unk534();
    virtual void Unk538();
    virtual void Unk53C();
    virtual void Unk540();
    virtual void Unk544();
    virtual void Unk548();
    virtual void Unk54C();
    virtual void Unk550();
    virtual void Unk554();
    virtual void Unk558();
    virtual void Unk55C();
    virtual void Unk560();
    virtual void Unk564();
    virtual void Unk568();
    virtual void Unk56C();
    virtual void Unk570();
    virtual void Unk574();
    virtual void Unk578();
    virtual void Unk57C();
    virtual void Unk580();
    virtual void Unk584();
    virtual void Unk588();
    virtual void Unk58C();
    virtual void Unk590();
    virtual void Unk594();
    virtual void Unk598();
    virtual void Unk59C();
    virtual void Unk5A0();
    virtual void Unk5A4();
    virtual void Unk5A8();
    virtual void Unk5AC();
    virtual void Unk5B0();
    virtual void Unk5B4();
    virtual void Unk5B8();
    virtual void Unk5BC();
    virtual void Unk5C0();
    virtual void Unk5C4();
    virtual void Unk5C8();
    virtual void Unk5CC();
    virtual void Unk5D0();
    virtual void Unk5D4();
    virtual void Unk5D8();
    virtual void Unk5DC();
    virtual void Unk5E0();
    virtual void Unk5E4();
    virtual void Unk5E8();
    virtual void Unk5EC();
    virtual void Unk5F0();
    virtual void Unk5F4();
    virtual void Unk5F8();
    virtual void Unk5FC();
    virtual void Unk600();
    virtual void Unk604();
    virtual void Unk608();
    virtual void Unk60C();
    virtual void Unk610();
    virtual void Unk614();
    virtual void Unk618();
    virtual void Unk61C();
    virtual void Unk620();
    virtual void Unk624();
    virtual void Unk628();
    virtual void Unk62C();
    virtual void Unk630();
    virtual void Unk634();
    virtual void Unk638();
    virtual void Unk63C();
    virtual void Unk640();
    virtual void Unk644();
    virtual void Unk648();
    virtual void Unk64C();
    virtual void Unk650();
    virtual void Unk654();
    virtual void Unk658();
    virtual void Unk65C();
    virtual void Unk660();
    virtual void Unk664();
    virtual void Unk668();
    virtual void Unk66C();
    virtual void Unk670();
    virtual void Unk674();
    virtual void Unk678();
    virtual void Unk67C();
    virtual void Unk680();
    virtual void Unk684();
    virtual void Unk688();
    virtual void Unk68C();
    virtual void Unk690();
    virtual void Unk694();
    virtual void Unk698();
    virtual void Unk69C();
    virtual void Unk6A0();
    virtual void Unk6A4();
    virtual void Unk6A8();
    virtual void OnCellChanged(F5BB0Actor* pkActor);
};

class F5BB0Actor
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual void Unk0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual bool IsActor();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11C();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Unk128();
    virtual void Unk12C();
    virtual void Unk130();
    virtual void Unk134();
    virtual void Unk138();
    virtual void Unk13C();
    virtual void Unk140();
    virtual void Unk144();
    virtual void Unk148();
    virtual void Unk14C();
    virtual void Unk150();
    virtual void Unk154();
    virtual void Unk158();
    virtual void Unk15C();
    virtual void Unk160();
    virtual void Unk164();
    virtual void Unk168();
    virtual void Unk16C();
    virtual void Unk170();
    virtual void Unk174();
    virtual void Unk178();
    virtual void Unk17C();
    virtual void Unk180();
    virtual void Unk184();
    virtual void Unk188();
    virtual void Unk18C();
    virtual void Unk190();
    virtual void Unk194();
    virtual void Unk198();
    virtual void Unk19C();
    virtual void Unk1A0();
    virtual void Unk1A4();
    virtual void Unk1A8();
    virtual void Unk1AC();
    virtual void Unk1B0();
    virtual void Unk1B4();
    virtual void Unk1B8();
    virtual void Unk1BC();
    virtual void Unk1C0();
    virtual void Unk1C4();
    virtual void Unk1C8();
    virtual void Unk1CC();
    virtual void Unk1D0();
    virtual void Unk1D4();
    virtual void Unk1D8();
    virtual void Unk1DC();
    virtual void Unk1E0();
    virtual void Unk1E4();
    virtual void Unk1E8();
    virtual void Unk1EC();
    virtual void Unk1F0();
    virtual void Unk1F4();
    virtual void Unk1F8();
    virtual void Unk1FC();
    virtual void Unk200();
    virtual void Unk204();
    virtual void Unk208();
    virtual void Unk20C();
    virtual void Unk210();
    virtual void Unk214();
    virtual void Unk218();
    virtual void Unk21C();
    virtual void Unk220();
    virtual void Unk224();
    virtual void Unk228();
    virtual void Unk22C();
    virtual void Unk230();
    virtual void Unk234();
    virtual void Unk238();
    virtual void Unk23C();
    virtual void UpdateCellState();

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
    F5BB0Cell* m_pkParentCell;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    F5BB0WaterData* m_pkWaterData;

    F5BB0ExtraDataList* GetExtraData();
    F5BB0Process* GetProcess();
    void* GetMountedRef();
    void FUN_00575bb0(F5BB0Cell* pkCell);
};

void* __cdecl FUN_00475400(void* object);

class Shape577
{
  public:
    int m_iType;
};

class World577
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual Shape577* GetShape();
};

struct Vec577
{
    float x;
    float y;
    float z;
};

struct FUN_0041fbe0_shell
{
    BGSPrimitive* FUN_0041fbe0();
};

class Tile
{
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(Vec577* p);
    NiNode* FUN_0056c7f0();
};

struct Ref577
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
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
    virtual void* vf117();
};

extern TESObjectSTAT* DAT_011ca240;
const ExtraDataList* __fastcall FUN_005d43c0(const TESObjectREFR* pThis);

namespace fnv_00577450 {
struct Point577
{
    float x, y, z;
    Point577& FUN_006815c0();
    bool FUN_00439090(const Point577&);
};
struct Plane577
{
    Point577 normal;
    float radius;
    Point577& FUN_006815c0();
    float FUN_0084d030();
};
struct Update577
{
    float time;
    bool update, render, unk06, unk07;
    unsigned unk08;
    Update577(float, bool, bool);
};
struct Node577
{
    const Point577& FUN_0045bb80();
    void FUN_00440460(const Point577&);
    void FUN_0043fa80(const void*);
    void FUN_00a59c60(Update577&);
    Plane577& FUN_0043d450();
};
struct World577;
struct Cell577
{
    bool FUN_00425fd0();
    Node577* FUN_00456fc0(int);
    World577* FUN_00546fb0();
    void FUN_0054cfd0(Point577&, Point577&);
    Node577* FUN_005497a0();
    void FUN_005496b0(void*, Node577*);
};
struct Point2_577
{
    float x, y;
};
struct World577
{
    Point2_577 FUN_0053f440();
};
struct Form577
{
    int FUN_00401170();
};
struct Ref577
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
    virtual void Notify(int);
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
    virtual bool IsActor();
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
    virtual const char* GetName();
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
    virtual Point577 GetPosition();
    virtual void SetPosition(Point577);
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
    virtual Node577* GetNode();
    virtual void unk1d4();
    virtual void unk1d8();
    virtual void unk1dc();
    virtual void unk1e0();
    virtual void unk1e4();
    virtual void unk1e8();
    virtual void unk1ec();
    virtual void unk1f0();
    virtual const Point577& GetCoordinates();
    Cell577* FUN_008d6f30();
    Form577* FUN_007af430();
    bool FUN_00448a20();
    float FUN_0057b0a0();
    void FUN_00484a70(bool);
    void FUN_005729e0(int);
    void FUN_00575830(const Point577&);
    unsigned FUN_0084e3a0();
    void FUN_008ae640(bool);
    void FUN_00575700(Point577);
};
struct Toggle577
{
    bool FUN_004623f0(bool);
};
struct TES577
{
    int FUN_005f36f0();
    World577* FUN_004fd3e0();
};
struct CellLookup577
{
    Cell577* FUN_00461bc0(float, float, World577*, bool);
};
struct Scene577
{
    void FUN_00b5d9f0(Node577*, bool);
};
extern Toggle577* DAT_011ddf38;
extern TES577* DAT_011dea10;
extern CellLookup577* DAT_011c3f2c;
extern Point577 DAT_011f426c;
bool __cdecl FUN_0062c3c0(Ref577*, Node577*);
void __cdecl FUN_00578300(Node577*);
void __cdecl FUN_00c6bd00(Node577*, bool);
void __cdecl FUN_00573800(Ref577*, int, World577*);
bool __cdecl FUN_008c7aa0();
int __cdecl FUN_00ec7595(double);
int __cdecl FUN_00ec75b1(double);
void __cdecl FUN_005b5e40(const char*, ...);
Scene577* __cdecl FUN_00450b80(int);
}  // namespace fnv_00577450

namespace fnv_00578170 {
struct StkRTTI;
class GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_01202de8;

struct StkAddonNode
{
    bool FUN_00448bf0();
};

struct StkDataHandler
{
    StkAddonNode* FUN_004617e0(unsigned int index);
};
extern StkDataHandler* g_dataHandler;

bool __cdecl FUN_0043b300(const StkRTTI* rtti, NiNode* obj);
int __fastcall FUN_009ee040(char* pThis);

}  // namespace fnv_00578170

namespace fnv_00578300 {

struct FUN_00453470_shell
{
    int FUN_00453470();
};

struct _FakeNiNode
{
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int);
};

class GlobalObject_00a7b610
{
};

class DataHandler
{
  public:
    int FUN_004617e0(int);
};

extern GlobalObject_00a7b610 g_01202de8;
extern DataHandler* g_dataHandler;

bool __cdecl FUN_0043b300(const NiRTTI*, NiAVObject*);
int __fastcall FUN_009ee040(char*);

}  // namespace fnv_00578300

// Recursively applies a value to every time controller on an object, its property 5 and all its children.

class C5784F0Controller
{
  public:
    void SetValue(float fValue);
    C5784F0Controller* GetNext() const;
};

class C5784F0Node;

class C5784F0ObjectNET
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual C5784F0Node* IsSceneNode();
    C5784F0Controller* GetControllers();
};

class C5784F0Object : public C5784F0ObjectNET
{
  public:
    C5784F0ObjectNET* GetProperty(unsigned int uiType);
};

class C5784F0Node
{
  public:
    unsigned int GetArrayCount();
    C5784F0Object* GetAt(unsigned int uiIndex);
};

// Sound setup for a reference, including primitive-relative loop positioning.
struct LoopSoundData
{
    unsigned int frequency, flags, attenuation, volume, minimumDistance;
    unsigned int maximumDistance, startTime, stopTime, priority;
};
struct LoopSound
{
    LoopSoundData CopyBig();
    unsigned int FUN_0084e3a0();
};
struct LoopEffect
{
    LoopSound* FUN_00407840();
};
struct LoopForm
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
    virtual LoopEffect* GetLoopEffect();
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    LoopSound* loopSound;
    unsigned int FUN_00401170();
    bool FUN_00452440();
    bool FUN_004e32c0();
    LoopSound* FUN_004fd3c0();
    LoopSound* FUN_004fd3a0();
    LoopSound* FUN_004fb070();
    LoopSound* FUN_004036b0();
    LoopSound* FUN_008cdd90();
    LoopSound* FUN_009185e0();
    LoopSound* FUN_005f92d0(int);
};
struct GlobalObject_0041a250
{
    unsigned int id, state, flags;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    bool FUN_00ad8ce0();
    void FUN_00ad88f0();
    void FUN_00ad8d10();
    void FUN_00ad8da0(int);
    void FUN_00418900(const void*);
    void FUN_00ad8ba0(float, float, float);
};
struct LoopPrimitive
{
    NiPoint3 FUN_00413fc0();
};
struct LoopExtras
{
    LoopPrimitive* FUN_0041fbe0();
    void FUN_00418890(GlobalObject_0041a250*);
    void FUN_00410140(int);
    void FUN_0041a800(GlobalObject_0041a250*);
};
struct RefObj
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
    virtual NiPoint3* GetPosition();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual bool HasCreatureLoop();
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    LoopSound* baseSound;
    LoopForm* _FNV_GetObjectReference();
    bool FUN_00440da0();
    bool FUN_00477ba0();
    LoopExtras* FUN_005d43c0();
    M3 FUN_0056fa00();
    void* FUN_0043fcd0();
    void FUN_0057a3c0(bool);
    void FUN_00579ac0(bool enable);
};

struct Vec57
{
    float x, y, z;
    Vec57& operator*=(float);
};
struct Mat57
{
    void angles(float*, float*, float*, float*);
};
class BSMultiBoundShape
{
  public:
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
    virtual void center(const Vec57&);
    virtual void update();
};
class BSMultiBoundOBB : public BSMultiBoundShape
{
  public:
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
    BSMultiBoundOBB();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void rotation(const Mat57&);
    const Vec57& extent();
    void setExtent(const Vec57&);
};
extern Vec57 NiPoint3_ZERO;
namespace std {
}

namespace fnv_00571760 {
struct TESObjectWEAP;
struct BipedAnim;
struct Obj14;
struct LoaderShell;

struct Proc
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void* V82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void V115(bool b, void* bip, void* p, void* r);
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual void f175();
    virtual void f176();
    virtual void f177();
    virtual void f178();
    virtual void f179();
    virtual void f180();
    virtual void f181();
    virtual void f182();
    virtual void f183();
    virtual void f184();
    virtual void f185();
    virtual void f186();
    virtual void f187();
    virtual void f188();
    virtual void f189();
    virtual void f190();
    virtual void f191();
    virtual void f192();
    virtual void f193();
    virtual void f194();
    virtual void f195();
    virtual void f196();
    virtual void f197();
    virtual void f198();
    virtual void f199();
    virtual void f200();
    virtual void f201();
    virtual void f202();
    virtual void f203();
    virtual void f204();
    virtual void f205();
    virtual void f206();
    virtual void f207();
    virtual void f208();
    virtual void f209();
    virtual void f210();
    virtual void f211();
    virtual void f212();
    virtual void f213();
    virtual void f214();
    virtual void f215();
    virtual void f216();
    virtual void f217();
    virtual void f218();
    virtual void f219();
    virtual void f220();
    virtual void f221();
    virtual void f222();
    virtual void f223();
    virtual void f224();
    virtual void f225();
    virtual void f226();
    virtual void f227();
    virtual void f228();
    virtual void f229();
    virtual void f230();
    virtual void f231();
    virtual void f232();
    virtual void f233();
    virtual void f234();
    virtual void f235();
    virtual void f236();
    virtual void f237();
    virtual void f238();
    virtual void f239();
    virtual void f240();
    virtual void f241();
    virtual void f242();
    virtual void f243();
    virtual void f244();
    virtual void f245();
    virtual void f246();
    virtual void f247();
    virtual void f248();
    virtual void f249();
    virtual void f250();
    virtual void f251();
    virtual void f252();
    virtual void f253();
    virtual void f254();
    virtual void f255();
    virtual void f256();
    virtual void f257();
    virtual void f258();
    virtual void f259();
    virtual void f260();
    virtual void f261();
    virtual void f262();
    virtual void f263();
    virtual void f264();
    virtual void f265();
    virtual void f266();
    virtual void f267();
    virtual void f268();
    virtual void f269();
    virtual void f270();
    virtual void f271();
    virtual void f272();
    virtual void f273();
    virtual void f274();
    virtual void f275();
    virtual void f276();
    virtual bool V277();
    virtual void V278(void* r, int z);
    virtual void f279();
    virtual void f280();
    virtual void f281();
    virtual void V282(int a);
};

struct Actor
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual bool V64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void* V121();
    virtual void* V122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual bool V139(int a);
    void* Get3DSimple();
    const char* GetFullName();
    Proc* GetProcess();
    bool FUN_008a16d0();
    void FUN_008b0b00(int a);
    void FUN_008b0bd0(void* p);
    void FUN_008c4640();
    void FUN_00891190(int a);
    void* FUN_005715d0(int a, int b, int c);
    BipedAnim* GetBipedAnim(bool b);
    void FUN_00571760(TESObjectWEAP* wpn);
};

struct BipedAnim
{
    void FUN_004ab750(TESObjectWEAP* w, bool b);
};

struct Obj14
{
    bool FUN_004bd820();
    bool FUN_004bd8d0(int a, float* f);
};

struct TESObjectWEAP
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
    float f3c;
    bool GetHasScope();
    bool FUN_004ad030();
    char* FUN_00504e60();
    bool FUN_0046e8c0();
    int GetWeaponType() const;
};

struct SaveShell
{
    bool FUN_0042ce10();
};

struct LoaderShell
{
    int FUN_00447330(void* p);
};

class TESAnimGroup
{
  public:
    static unsigned short AnimGroup(int a, int b, int c, int d);
};

extern SaveShell* DAT_011ddf38;
extern Actor* DAT_011dea3c;
extern LoaderShell* DAT_011c3b3c;
extern int DAT_0118a838[];

int __cdecl FUN_00ec7750(const char* a, const char* b);
void __cdecl FUN_005b5e40(const char* s);

}  // namespace fnv_00571760

struct SubObj
{
    virtual void v0();
    virtual void v1();
    virtual float GetValue(int);
};

struct MagicItem : public TESForm
{
    char pad[0xc - sizeof(TESForm)];
    SubObj sub;
};

struct AlchemyItem : public TESForm
{
    char pad[0x3c - sizeof(TESForm)];
    SubObj sub;
};

// Reference remapping reconstructed from the complete target disassembly.
struct RemapRef;
struct RemapPoint
{
    float x, y, z;
    RemapPoint FUN_00439ef0(const RemapPoint&) const;
    RemapPoint FUN_00439e90(const RemapPoint&) const;
};
struct RemapList
{
    bool FUN_008256d0();
    void** FUN_006815c0();
    RemapList* FUN_00726070();
};
struct RemapExtra
{
    void FUN_0041dcd0(RemapRef*);
    void FUN_0041e530(RemapRef*);
    RemapRef* FUN_00420bc0(int);
    void FUN_00420a60(int, RemapRef*);
    RemapRef* FUN_00420130(int);
    void FUN_00420160(RemapRef*, int);
    RemapList* FUN_0041e780();
    void FUN_0041e7f0(RemapRef*);
    void ExtraAmmo_Compare(RemapRef*, float);
    void FUN_0041edd0(RemapRef*);
    bool FUN_0041eb60();
    void FUN_0041eba0(bool);
    RemapList* FUN_0041f050();
};
struct RemapNode
{
    void FUN_00537e90(RemapRef*);
    void FUN_006f4ed0(RemapPoint*);
    void SetVec(RemapPoint*);
    RemapPoint* FUN_00460140();
    RemapRef* FUN_00559450();
    RemapPoint* FUN_00717e50();
};
struct RemapMap
{
    bool FUN_00853130(void*, TESForm**);
};
struct RemapRef
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
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
    virtual RemapPoint* GetPos();
    RemapExtra* FUN_005d43c0();
    RemapRef* FUN_0056a9f0();
    void FUN_0056aa10(RemapRef*);
    bool FUN_0056aa70();
    void FUN_0056aa90(bool);
    RemapRef* FUN_00569b20();
    void FUN_00569b40(RemapRef*);
    RemapRef* FUN_00569b80();
    void FUN_00569ba0(RemapRef*);
    void FUN_0056a470(RemapRef*, RemapPoint*, RemapPoint*);
    RemapRef* FUN_0056a990();
    void FUN_0056a9b0(RemapRef*);
    RemapNode* FUN_00568e50();
    RemapNode* FUN_00568e70();
    void FUN_0055b9c0(RemapMap* map);
};

class ExtraTeleport : public BSExtraData
{
};

struct Ref;
struct CopyNode;
struct Extra;
struct Link;
struct CopyHolder;
struct Property;
struct Vec
{
    float x, y, z;
};
struct Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};

struct AttachedSceneProvider
{
    Ref* ref;
    int flags;
};
struct Link
{
    AttachedSceneProvider** FUN_006815c0();
    Link* FUN_00726070();
    bool FUN_008256d0();
};
struct CopyHolder
{
    Ref* FUN_00559450();
    void FUN_00537e90(Ref*);
};
struct Extra
{
    void FUN_0041dda0(Ref*);
    short FUN_00418770();
    void FUN_0041e600(Ref*);
    Link* FUN_0041e780();
    void FUN_0041ef20(Ref*);
    Link* FUN_0041f170();
    void FUN_0041f4c0(Ref*, bool);
    void FUN_0041f650(Ref*, bool);
    Link* FUN_0041f810();
    CopyHolder* FUN_00418250();
    void FUN_0041f840(Ref*, bool);
    void FUN_00411ec0(Extra*);
    void FUN_0041e530(Ref*);
    void FUN_0041edd0(Ref*);
    void FUN_0041ae70();
    void FUN_0041dcd0(Ref*);
};
struct PropertyList
{
    void FUN_0057c730(Ref* const&);
    void* FUN_0049c680(Ref* const&, void*);
    void FUN_004ed8c0(Ref* const&);
};
struct Property
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
    char unk080;
    char unk081;
    char unk082;
    bool dirty;
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
    PropertyList refs;
};
struct CopyNode
{
    void FUN_00440460(const Vec*);
    void FUN_0043fa80(const Matrix*);
    void FUN_00a59c60(NiUpdateData&);
    void FUN_00440490(float);
    CopyNode* FUN_009611e0();
    void FUN_00a5a040();
    CopyNode* FUN_004030b0();
    int FUN_008d8520();
    Property* FUN_00a59d30(int);
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
    virtual void attach(CopyNode*, bool);
};
struct Ref
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
    virtual bool special();
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
    virtual CopyNode* baseNode(Ref*, int);
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
    virtual CopyNode* loadNode(bool);
    virtual void SetCopyNodeReference(CopyNode*, bool);
    virtual CopyNode* node();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const Vec* position();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Ref* base;
    float rx, ry, rz, px, py, pz;
    bool FUN_004077c0();
    Ref* FUN_0056a9f0();
    Extra* FUN_005d43c0();
    bool FUN_005653d0();
    void FUN_00565480(bool);
    void FUN_004851b0(TESForm*);
    Ref* FUN_007af430();
    void* FUN_00891170();
    float FUN_00598040();
    int FUN_00401170();
    float FUN_00568cb0();
    int FUN_00569580();
    Matrix FUN_0056fa00();
    struct Cell* FUN_008d6f30();
    CopyHolder* FUN_00568e50();
    void FUN_00568f30();
    Ref* FUN_00569b80();
    void FUN_00569be0(Ref*);
    void FUN_00569df0(int);
    void FUN_00569cb0(bool, int);
    void FUN_0056a1e0(bool);
    void FUN_00567490(float);
    float FUN_00567400();
    bool FUN_00572d30(int);
    void FUN_0057ada0();
    CopyHolder* FUN_00568e70();
    void* FUN_00569140();
    void* FUN_00567770();
    void FUN_00567c50();
    void FUN_0055c3e0(TESForm*);
};
struct Cell
{
    void FUN_00548230(Ref*, bool);
    void FUN_0054ca90(Ref*);
};
struct WorldManager
{
    struct Scene* FUN_0070ec90();
    bool FUN_004511e0(Cell*, bool);
    void FUN_00451ef0(Ref*, Cell*, int, int);
};
extern WorldManager* g_TES;
struct Scene
{
    CopyNode* FUN_004e8030(AttachedSceneProvider*);
};
struct Shadow
{
    void FUN_00b5eed0(Ref*);
};
Shadow* FUN_00450b80(int);
void FUN_00c6bd00(CopyNode*, bool);
bool FUN_0040eb10(float, float, float);
extern float DAT_01017d00;
void FUN_0047aec0(Ref*, bool, bool);
void FNV_Warning(const char*);

namespace s55d310 {

struct Component
{
    int unk00;
};

struct WeaponBase
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
    int unk60;
};

struct Weapon : WeaponBase, Component
{
};

struct Form
{
    int FUN_00401170();
};

struct Owner
{
    Form* FUN_007af430();
    Component* FUN_0055d310();
};

}

namespace fnv_0055e5e0 {
extern unsigned int kGroupFormType;

struct ChangeGroupInfo
{
    unsigned int formType;
    int unk04;
    unsigned int unk08;
    int unk0C;
    int unk10;
};

struct ChangeRequest
{
    int unk00;
    int unk04;
    unsigned int unk08;
    int unk0C;
};

struct CellStub
{
    bool IsCellFlagA();
    unsigned int GetWorldKey();
    unsigned int GetCellKey();
};

struct ChildCellStub
{
    virtual CellStub* GetPersistentCell();
};

struct RefStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ChildCellStub childCell;
    bool IsRefFlagA();
    void FillGroupChangeInfo(ChangeGroupInfo* info, ChangeRequest* req);
};

}  // namespace fnv_0055e5e0

extern float DAT_01017d00;

extern float DAT_01017d00;

namespace fnv_00561860 {
struct NiPoint3
{
    float x, y, z;
};
struct NiCollisionObject;

struct NiUpdateData
{
    int u0;
    int u4;
    int u8;
    NiUpdateData(float, bool, bool);
};

struct NiAVObject
{
    void Update(const NiUpdateData&);
};

}  // namespace fnv_00561860

struct Vec3
{
    int a, b, c;
};

namespace fnv_005623d0 {
struct FlagsX
{
    unsigned u;
    FlagsX()
    {}
    bool FUN_004280f0();
};
struct SubX
{
    void FUN_00428150(void* p);
    void FUN_0041aeb0();
    bool FUN_0041b3a0(int i);
    void FUN_0041b470(int i);
    void FUN_0041b440(int i);
    float FUN_0041b6b0();
};
struct ChangeX
{
    FlagsX FUN_00428110(unsigned uiMask);
    void FUN_00864980(void* pData, int iSize);
};
struct HandlerX
{
    void FUN_004d4160(ChangeX* p);
};
struct MgrX
{
    void FUN_0084a810(int a, ChangeX* p, int b);
};
extern MgrX* DAT_011ddf38;
struct NameX
{
    void* FUN_00559450();
};
struct BaseX
{
    char pad[0x14];
    NameX kName;
};
struct FormX
{
    bool FUN_00476f50(void* p, int i);
};
struct RefX;
HandlerX* __cdecl FUN_004bf220(RefX* p);
FormX* __cdecl FUN_00475400(void* p);
void __cdecl FUN_0055d6d0(RefX* p, int i);
struct RefX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c(), v0a0(),
        v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc(), v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(),
        v0dc(), v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc();
    virtual bool v100();
    virtual void v104(), v108(), v10c(), v110(), v114(), v118(), v11c(), v120(), v124(), v128(), v12c(), v130(), v134(),
        v138(), v13c(), v140(), v144(), v148(), v14c(), v150(), v154(), v158(), v15c(), v160(), v164(), v168(), v16c(),
        v170(), v174(), v178(), v17c(), v180(), v184(), v188(), v18c(), v190(), v194(), v198(), v19c(), v1a0(), v1a4(),
        v1a8(), v1ac(), v1b0(), v1b4(), v1b8(), v1bc(), v1c0(), v1c4(), v1c8(), v1cc();
    virtual int v1d0();
    char pad4[0x38];
    float m3c;
    char pad40[0x24];
    BaseX* m64;
    void FUN_00484da0(ChangeX* p);
    void FUN_00484580(int i);
    void FUN_00567490(float f);
    SubX* FUN_005d43c0();
    bool FUN_00452370();
    void* FUN_007af430();
    void FUN_0057a3c0(int i);
    void ApplyChanges(ChangeX* pkChanges);
};
}  // namespace fnv_005623d0

namespace fnv_005629a0 {
struct ChangeFlags
{
    unsigned int value;
    bool FUN_004280f0(unsigned int mask);
};
struct LoadBuffer
{
    ChangeFlags FUN_0042ce30();
    bool FUN_00562d00();
};
struct Ref;
struct ExtraList
{
    float FUN_0041b6b0();
    void FUN_0042dae0(LoadBuffer*);
    void FUN_0042dd90(LoadBuffer*);
    bool FUN_0041b3a0(int);
    void FUN_0041b470(int);
    void FUN_0041b440(int);
};
struct ParentCell
{
    void FUN_00545670(Ref*);
};
struct NodePointer
{
    void* FUN_00559450();
};
struct LoadedData
{
    unsigned int unk00, unk04, unk08;
    float unk0c;
    unsigned int unk10;
    NodePointer node;
};
struct OpenClose
{
    bool FUN_00476f50(Ref*, bool);
};
OpenClose* FUN_00475400(void*);
void FUN_0047aec0(Ref*, bool, bool);
bool FUN_0062c3c0(Ref*, void*);
void FUN_0055d6d0(Ref*, void*);
struct Ref
{
    virtual void virtual_000();
    virtual void virtual_004();
    virtual void virtual_008();
    virtual void virtual_00c();
    virtual void virtual_010();
    virtual void virtual_014();
    virtual void virtual_018();
    virtual void virtual_01c();
    virtual void virtual_020();
    virtual void virtual_024();
    virtual void virtual_028();
    virtual void virtual_02c();
    virtual void virtual_030();
    virtual void virtual_034();
    virtual void virtual_038();
    virtual void virtual_03c();
    virtual void virtual_040();
    virtual void virtual_044();
    virtual void virtual_048();
    virtual void virtual_04c();
    virtual void virtual_050();
    virtual void virtual_054();
    virtual void virtual_058();
    virtual void virtual_05c();
    virtual void virtual_060();
    virtual void virtual_064();
    virtual void virtual_068();
    virtual void virtual_06c();
    virtual void virtual_070();
    virtual void virtual_074();
    virtual void virtual_078();
    virtual void virtual_07c();
    virtual void virtual_080();
    virtual void virtual_084();
    virtual void virtual_088();
    virtual void virtual_08c();
    virtual void virtual_090();
    virtual void virtual_094();
    virtual void virtual_098();
    virtual void virtual_09c();
    virtual void virtual_0a0();
    virtual void virtual_0a4();
    virtual void virtual_0a8();
    virtual void virtual_0ac();
    virtual void virtual_0b0();
    virtual void virtual_0b4();
    virtual void virtual_0b8();
    virtual void virtual_0bc();
    virtual void virtual_0c0();
    virtual void virtual_0c4();
    virtual void virtual_0c8();
    virtual void virtual_0cc();
    virtual void virtual_0d0();
    virtual void virtual_0d4();
    virtual void virtual_0d8();
    virtual void virtual_0dc();
    virtual void virtual_0e0();
    virtual void virtual_0e4();
    virtual void virtual_0e8();
    virtual void virtual_0ec();
    virtual void virtual_0f0();
    virtual void virtual_0f4();
    virtual void virtual_0f8();
    virtual void virtual_0fc();
    virtual bool IsActor();
    virtual void virtual_104();
    virtual void virtual_108();
    virtual void virtual_10c();
    virtual void virtual_110();
    virtual void virtual_114();
    virtual void virtual_118();
    virtual void virtual_11c();
    virtual void virtual_120();
    virtual void virtual_124();
    virtual void virtual_128();
    virtual void virtual_12c();
    virtual void virtual_130();
    virtual void virtual_134();
    virtual void virtual_138();
    virtual void virtual_13c();
    virtual void virtual_140();
    virtual void virtual_144();
    virtual void virtual_148();
    virtual void virtual_14c();
    virtual void virtual_150();
    virtual void virtual_154();
    virtual void virtual_158();
    virtual void virtual_15c();
    virtual void virtual_160();
    virtual void virtual_164();
    virtual void virtual_168();
    virtual void virtual_16c();
    virtual void virtual_170();
    virtual void virtual_174();
    virtual void virtual_178();
    virtual void virtual_17c();
    virtual void virtual_180();
    virtual void virtual_184();
    virtual void virtual_188();
    virtual void virtual_18c();
    virtual void virtual_190();
    virtual void virtual_194();
    virtual void virtual_198();
    virtual void virtual_19c();
    virtual void virtual_1a0();
    virtual void virtual_1a4();
    virtual void virtual_1a8();
    virtual void virtual_1ac();
    virtual void virtual_1b0();
    virtual void virtual_1b4();
    virtual void virtual_1b8();
    virtual void virtual_1bc();
    virtual void virtual_1c0();
    virtual void virtual_1c4();
    virtual void virtual_1c8();
    virtual void virtual_1cc();
    virtual void* GetNode();
    virtual void virtual_1d4();
    virtual void virtual_1d8();
    virtual void virtual_1dc();
    virtual void virtual_1e0();
    virtual void virtual_1e4();
    virtual void virtual_1e8();
    virtual void virtual_1ec();
    virtual void virtual_1f0();
    virtual void virtual_1f4();
    virtual void virtual_1f8();
    virtual void virtual_1fc();
    virtual void virtual_200();
    virtual void virtual_204();
    virtual void ResetState(bool);
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
    ParentCell* parentCell;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    LoadedData* loadedData;
    void FUN_005629a0(LoadBuffer* buffer);
    void FUN_004534f0(LoadBuffer*);
    void FUN_00484580(bool);
    ExtraList* FUN_005d43c0();
    bool FUN_00452370();
    void* FUN_007af430();
    void FUN_0057a3c0(bool);
    void ResetAnimation();
    void FUN_00574920(bool);
    bool FUN_00572d30(int);
    void FUN_00577330(void*);
};
}  // namespace fnv_005629a0

namespace fnv_00563890 {
struct NiAVObject;
struct Seq;
struct Mgr;
struct Ref;

class NiFixedString
{
  public:
    NiFixedString(const char* p);
    ~NiFixedString();
    int v;
};

struct NiUpdateData
{
    float t;
    bool f;
    bool c;
    int u;
    NiUpdateData(float, bool, bool);
};

struct NiRTTI
{
    int x;
};

struct ExtraData
{
    char* FUN_004228f0();
};

struct ShadowSceneNode
{
    void AddObject(NiAVObject* p);
};

struct G11DEA10
{
    bool FUN_004511e0(void* p, int n);
};

struct M40
{
    void FUN_00548880(Ref* p, int n);
};

struct Ref
{
    virtual void vd0();
    virtual void vd1();
    virtual void vd2();
    virtual void vd3();
    virtual void vd4();
    virtual void vd5();
    virtual void vd6();
    virtual void vd7();
    virtual void vd8();
    virtual void vd9();
    virtual void vd10();
    virtual void vd11();
    virtual void vd12();
    virtual void vd13();
    virtual void vd14();
    virtual void vd15();
    virtual void vd16();
    virtual void vd17();
    virtual void vd18();
    virtual void vd19();
    virtual void vd20();
    virtual void vd21();
    virtual void vd22();
    virtual void vd23();
    virtual void vd24();
    virtual void vd25();
    virtual void vd26();
    virtual void vd27();
    virtual void vd28();
    virtual void vd29();
    virtual void vd30();
    virtual void vd31();
    virtual void vd32();
    virtual void vd33();
    virtual void vd34();
    virtual void vd35();
    virtual void vd36();
    virtual void vd37();
    virtual void vd38();
    virtual void vd39();
    virtual void vd40();
    virtual void vd41();
    virtual void vd42();
    virtual void vd43();
    virtual void vd44();
    virtual void vd45();
    virtual void vd46();
    virtual void vd47();
    virtual void vd48();
    virtual void vd49();
    virtual void vd50();
    virtual void vd51();
    virtual void vd52();
    virtual void vd53();
    virtual void vd54();
    virtual void vd55();
    virtual void vd56();
    virtual void vd57();
    virtual void vd58();
    virtual void vd59();
    virtual void vd60();
    virtual void vd61();
    virtual void vd62();
    virtual void vd63();
    virtual void vd64();
    virtual void vd65();
    virtual void vd66();
    virtual void vd67();
    virtual void vd68();
    virtual void vd69();
    virtual void vd70();
    virtual void vd71();
    virtual void vd72();
    virtual void vd73();
    virtual void vd74();
    virtual void vd75();
    virtual void vd76();
    virtual void vd77();
    virtual void vd78();
    virtual void vd79();
    virtual void vd80();
    virtual void vd81();
    virtual void vd82();
    virtual void vd83();
    virtual void vd84();
    virtual void vd85();
    virtual void vd86();
    virtual void vd87();
    virtual void vd88();
    virtual void vd89();
    virtual void vd90();
    virtual void vd91();
    virtual void vd92();
    virtual void vd93();
    virtual void* vfn_178(Ref* p);
    virtual void vd95();
    virtual void vd96();
    virtual void vd97();
    virtual void vd98();
    virtual void vd99();
    virtual void vd100();
    virtual void vd101();
    virtual void vd102();
    virtual void vd103();
    virtual void vd104();
    virtual void vd105();
    virtual void vd106();
    virtual void vd107();
    virtual void vd108();
    virtual void vd109();
    virtual void vd110();
    virtual void vd111();
    virtual void vd112();
    virtual void vfn_1c4();
    virtual void vd114();
    virtual void vfn_1cc(void* p, int n);
    char pad0[0x1c];
    Ref* m20;
    char pad1[0x1c];
    M40* m40;
    NiAVObject* FUN_0043fcd0();
    ExtraData* FUN_005d43c0();
    void ResetAnimation();
};

struct NiAVObject
{
    NiAVObject* FUN_0043b230();
    void FUN_00a59c60(NiUpdateData const& d);
};

struct Seq
{
    int FUN_008041a0();
    void hkpSimulationIsland_markForWrite(float f);
    float FUN_009a9350();
};

struct Mgr
{
    Seq* FUN_0047a520(NiFixedString const& s);
    void FUN_0048fef0(float f);
    void FUN_0047aa40(bool b);
    void FUN_0047aab0(Seq* s, int a, int b, float f1, float f2, int c);
    unsigned int FUN_00495d00();
    Seq* FUN_00495d20(unsigned int i2);
};

int _stricmp(const char* a, const char* b);
NiAVObject* NiDynamicCast(NiRTTI const* t, NiAVObject* o);
bool FUN_004b5bf0(NiAVObject* o);
ShadowSceneNode* FUN_00450b80(unsigned int i2);

extern char* DAT_01197b5c;
extern char* DAT_011977d8;
extern char* DAT_01197820;
extern NiRTTI DAT_011f36ac;
extern float DAT_0102f510;
extern G11DEA10* DAT_011dea10;

}  // namespace fnv_00563890

namespace fnv_00564010 {
struct Buf;
struct NiAVObject;

struct NiUpdateData
{
    float m_fTime;
    bool m_bForce;
    bool m_bChildren;
    int m_iUnk;
    NiUpdateData(float, bool, bool);
};

struct NiAVObject
{
    void FUN_00a59c90(NiUpdateData&);
    void FUN_00a59c60(NiUpdateData&);
};

struct Buf
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
    unsigned int FUN_00864a60();
    char* FUN_008649a0(char*);
};

struct Mgr
{
    void FUN_0048fef0(float);
    void FUN_0047aa40(bool);
    unsigned int FUN_00495d00();
    void* FUN_00495d20(unsigned int);
    void FUN_0047aab0(void*, int, int, float, float, int);
};

struct Ref
{
    NiAVObject* FUN_0043fcd0();
};

struct NameList
{
    char* FUN_0043b1b0();
};

struct Pkg
{
    NameList* FUN_00413f40();
    int FUN_008041a0();
    void FUN_004efd10(Buf*, float);
    float FUN_00639aa0();
};

int FUN_00408b20(const char*, const char*);
bool FUN_004b5c80(NiAVObject*);
void FUN_00c6bd00(NiAVObject*, bool);

extern float DAT_011c3c08;

}  // namespace fnv_00564010

struct Other
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
    virtual bool vf();
};

struct Thing
{
    Other* FUN_007af430();
    bool FUN_00564bc0();
};

namespace fnv_005656d0 {
struct Obj
{
    bool FUN_004d0490();
};
struct Thing
{
    Obj* FUN_007af430();
    int FUN_0055d310();
    bool FUN_005656d0();
};
extern "C" int FUN_004826d0(void* obj);
extern "C" void* FUN_004bf220(void* self);
}  // namespace fnv_005656d0

namespace fnv_00567400 {
class FormObj
{
  public:
    int FUN_00401170();
    float FUN_00944300();
    float FUN_00567470();
};

class RefObj
{
  public:
    FormObj* FUN_007af430();
};

}  // namespace fnv_00567400

#include <stdlib.h>
namespace fnv_00567490 {
struct NiUpdateData
{
    float time;
    bool updateControllers, multithreaded, field06, field07, field08;
    NiUpdateData(float, bool, bool);
};
struct NiAVObject
{
    void FUN_00440490(float);
    void Update(const NiUpdateData&);
};
struct FormType
{
    int FUN_00401170();
};
struct Controller
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
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
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
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    float saved550, saved554;
    float FUN_00567730();
    float FUN_00567750();
};
struct AnimIdle;
struct FUN_00633c90
{
    AnimIdle* value;
    FUN_00633c90(int);
    FUN_00633c90(const FUN_00633c90&);
    ~FUN_00633c90();
};
struct Process
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot00a();
    virtual void slot00b();
    virtual void slot00c();
    virtual void slot00d();
    virtual void slot00e();
    virtual void slot00f();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot01a();
    virtual void slot01b();
    virtual void slot01c();
    virtual void slot01d();
    virtual void slot01e();
    virtual void slot01f();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot02a();
    virtual void slot02b();
    virtual void slot02c();
    virtual void slot02d();
    virtual void slot02e();
    virtual void slot02f();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot03a();
    virtual void slot03b();
    virtual void slot03c();
    virtual void slot03d();
    virtual void slot03e();
    virtual void slot03f();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot04a();
    virtual void slot04b();
    virtual void slot04c();
    virtual void slot04d();
    virtual void slot04e();
    virtual void slot04f();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot05a();
    virtual void slot05b();
    virtual void slot05c();
    virtual void slot05d();
    virtual void slot05e();
    virtual void slot05f();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot06a();
    virtual void slot06b();
    virtual void slot06c();
    virtual void slot06d();
    virtual void slot06e();
    virtual void slot06f();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot07a();
    virtual void slot07b();
    virtual void slot07c();
    virtual void slot07d();
    virtual void slot07e();
    virtual void slot07f();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot08a();
    virtual void slot08b();
    virtual void slot08c();
    virtual void slot08d();
    virtual void slot08e();
    virtual void slot08f();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot09a();
    virtual void slot09b();
    virtual void slot09c();
    virtual void slot09d();
    virtual void slot09e();
    virtual void slot09f();
    virtual void slot0a0();
    virtual void slot0a1();
    virtual void slot0a2();
    virtual void slot0a3();
    virtual void ResetIdle(FUN_00633c90);
};
struct ScaleReference
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void MarkChanged(unsigned int);
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool IsActor();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void UpdateController();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual NiAVObject* GetNode();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void RefreshPhysics();
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
    float m_fObjectScale;
    bool FUN_00444ed0();
    FormType* FUN_007af430();
    float FUN_00567400();
    NiAVObject* FUN_00950bb0(bool);
    Controller* FUN_009306d0();
    Process* FUN_008d8520();
    void FUN_00962450();
    void FUN_00567490(float scale);
};
extern ScaleReference* g_thePlayer;
int FUN_00406d00(char*, unsigned int, const char*, ...);

}  // namespace fnv_00567490

namespace s5679f0 {

struct Process
{
    int FUN_004186c0();
};

struct Actor
{
    Process* FUN_005d43c0();
};

template <class T> class NiPointer
{
  public:
    operator T*() const;

    T* m_pObject;
};

struct Faction
{
    int FUN_00567ab0();
};

struct Class
{
    int FUN_00546ac0();
};

Faction* FUN_00546a90();

struct Owner
{
    Process* FUN_005d43c0();
    NiPointer<Actor>* FUN_00568e50();
    Faction* FUN_00567d20();
    Class* FUN_008d6f30();
    int FUN_005679f0();
};

}

namespace fnv_00567e10 {
class PlayerCharacter
{
  public:
    unsigned short GetLevel();
};

extern PlayerCharacter* g_thePlayer;

void* FUN_00546a90();

}  // namespace fnv_00567e10

void* __fastcall _FNV_GetObjectReference(void*);

namespace s5693d0 {

struct Entry
{
    int FUN_00421b40();
};

struct Owner
{
    int FUN_007af430();
    Entry* FUN_005d43c0();
    int FUN_005693d0();
};

}

class TESForm;
void* __fastcall _FNV_GetObjectReference(void*);
unsigned int __fastcall _ref_0084e3a0(void*);

namespace s569840 {

struct Entry
{
    int FUN_00421f00();
};

struct Owner
{
    bool FUN_00439f90();
    Entry* FUN_005d43c0();
    int FUN_00569840();
};

}

namespace fnv_0056a4a0 {
struct PosX
{
    float x, y, z;
};
struct ColorX
{
    float r, g, b;
    ColorX(float r, float g, float b);
};
struct GeomX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090();
    virtual unsigned v94();
    virtual unsigned v98();
};
struct GeomPtr
{
    GeomX* p;
    GeomPtr(GeomX* q);
    ~GeomPtr();
    GeomX* FUN_00559450();
};
struct SubX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c();
    virtual void v90(int i, GeomPtr* sp);
};
struct LightDataX
{
    float FUN_006b9130();
    float FUN_006a7f50();
    float FUN_0084d030();
    float FUN_00488d50();
    unsigned FUN_007af430();
    float FUN_00621b00();
    float FUN_0047c860();
    bool FUN_004a41a0();
    bool FUN_004a4160();
    bool FUN_004a4120();
    float FUN_004a7bd0();
    bool FUN_004a4200();
};
struct LightX
{
    int pad[12];
    SubX kSub;
    bool FUN_0056a860();
    LightDataX* FUN_0056a880();
};
struct RefX
{
    LightX* FUN_007af430();
    float FUN_00567400();
};
struct EntryX
{
    RefX* m0;
    PosX m4;
    PosX m10;
};
struct IterX
{
    bool FUN_008256d0();
    EntryX** FUN_006815c0();
    IterX* FUN_00726070();
};
struct ListX
{
    IterX* FUN_0041f050();
};
struct DescX
{
    PosX kPos;
    PosX kWorldPosition;
    int pad18[4];
    int m28;
    int pad2c;
    LightX* pkLight;
    int pad34;
    float m38;
    float m3c;
    float m40;
    int pad44[2];
    float m4c;
    int pad50;
    float m54;
    float m58;
    int pad5c;
    ColorX kColor;
    int pad6c;
    unsigned char ucAlpha;
    bool b71;
    bool b72;
    bool b73;
    bool b74;
    bool b75;
    bool b76;
    bool b77;
    int pad78[2];
    DescX();
};
struct MgrX
{
    void FUN_004a3fe0(DescX* p, int i, int j);
};
struct ActorX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c(), v0a0(),
        v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc(), v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(),
        v0dc(), v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc(), v100(), v104(), v108(), v10c(), v110(),
        v114(), v118(), v11c(), v120(), v124(), v128(), v12c(), v130(), v134(), v138(), v13c(), v140(), v144(), v148(),
        v14c(), v150(), v154(), v158(), v15c(), v160(), v164(), v168(), v16c(), v170(), v174(), v178(), v17c(), v180(),
        v184(), v188(), v18c(), v190(), v194(), v198(), v19c(), v1a0(), v1a4(), v1a8(), v1ac(), v1b0(), v1b4(), v1b8(),
        v1bc(), v1c0(), v1c4(), v1c8(), v1cc();
    virtual int v1d0();
    void FUN_0056a8d0();
    ListX* FUN_005d43c0();
    MgrX* FUN_008d6f30();
    void UpdateLightDescriptors(int iArg);
};
}  // namespace fnv_0056a4a0

namespace fnv_0056ad80 {
struct Other
{
    int FUN_00401170();
};
struct Result
{
    Other* m_ptr;
};
struct Sub
{
    Result* FUN_00418b70();
};
struct Thing
{
    Sub* FUN_005d43c0();
    int FUN_0056ad80();
};
}  // namespace fnv_0056ad80

namespace fnv_0056add0 {
struct Extra
{
    int* FUN_00418b70();
};

struct Obj
{
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
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual void vF4();
    virtual void vF8();
    virtual void vFC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual int* vGet();
    Extra* FUN_005d43c0();
    int* FUN_0056add0();
};

}  // namespace fnv_0056add0

namespace s56ae10 {

struct Entry
{
    void FUN_0041ad00(int iArg0, int iArg1, int iArg2, float fArg3);
};

class Owner
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void SetFlag(int iFlag);

    Entry* FUN_005d43c0();
    void FUN_0056ae10(int iArg0, int iArg1, int iArg2, float fArg3);
};

}

#include <xmmintrin.h>
// Placeable water collision creation: box for cell water, copied shape otherwise.
struct __declspec(align(16)) WaterVector4
{
    __m128 value;
    WaterVector4();
};
struct __declspec(align(16)) WaterQuaternion
{
    __m128 value;
    WaterQuaternion();
    void Identity();
};
struct WaterHavokAllocation
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*);
};
struct WaterShape
{
    unsigned int Type();
};
struct WaterTransform : WaterHavokAllocation
{
    WaterTransform();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct WaterTransformedShape : WaterHavokAllocation
{
    WaterTransformedShape(WaterShape*, WaterTransform*);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};
struct __declspec(align(16)) WaterRigidBodyInfo
{
    unsigned int filter;
    WaterTransformedShape* shape;
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
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    WaterRigidBodyInfo();
    ~WaterRigidBodyInfo();
    void SetMotionType(int);
    void SetPosition(const WaterVector4&);
    void SetRotation(const WaterQuaternion&);
};
struct WaterGameAllocation
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct WaterNode;
struct WaterExtraData : WaterGameAllocation
{
    WaterExtraData();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void SetFlag(unsigned int, bool);
};
struct WaterFixedString;
struct WaterNode
{
    void GetRotation(WaterVector4&);
    WaterExtraData* GetExtra(const WaterFixedString&);
    bool AddExtra(WaterExtraData*);
};
struct WaterShapePointer
{
    operator WaterShape*() const;
};

namespace fnv_0056e180 {
struct FUN_0056e1e0
{
    int unk00;
    int unk04;
    FUN_0056e1e0();
    ~FUN_0056e1e0();
};

struct FUN_005407b0
{
    int unk00;
    FUN_005407b0(int iMode);
};

struct FUN_0056e180 : FUN_0056e1e0
{
    FUN_005407b0 m_kList;
    FUN_0056e180();
};

// @fnv 0x0056e180
FUN_0056e180::FUN_0056e180() : m_kList(2)
{}
}  // namespace fnv_0056e180

namespace s56eab0 {

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct __declspec(align(16)) FourFloatVector
{
    float m_fComponents[4];

    FourFloatVector();
};

struct __declspec(align(16)) Quaternion
{
    float m_fComponents[4];

    Quaternion();
};

struct Box
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk20;
};

struct UpdateParams
{
    UpdateParams(float fTime, int iArg0, int iArg1);

    float m_fTime;
    int m_iArg0;
    int m_iArg1;
};

struct HeapObject
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
};

struct Shape : HeapObject
{
    int unk00;
};

struct __declspec(align(16)) RigidBodyInfo
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
    int unkd8;
    unsigned char m_aucFlags[4];

    RigidBodyInfo();
    ~RigidBodyInfo();

    void FUN_0056f110(Shape* pkShape);
    void FUN_0056f0f0(unsigned int uiFilterInfo);
    void FUN_0056d360(int iQuality);
};

struct Motion : HeapObject
{
    Motion();

    void FUN_00519230(int iArg0, int iArg1);

    int unk000;
    int unk004;
    int unk008;
    int unk0c;
};

class NiNode;

class RigidBody : public HeapObject
{
  public:
    RigidBody(RigidBodyInfo& kInfo);

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
    virtual void SetPhysicsWorld(void* pvWorld);
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
    virtual void SetTranslation(FourFloatVector& kTranslation);
    virtual void SetRotation(Quaternion& kRotationBasis);

    void FUN_00c85c10(NiNode* pkNode, int iArg);

    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk18;
};

struct Controller : HeapObject
{
    Controller(NiNode* pkNode);

    void FUN_00c6b980(RigidBody* pkBody);

    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk10;
};

class NiNode
{
  public:
    void FUN_00440490(float fScale);
    void FUN_00a59c60(UpdateParams& kParams);
    void SetExtraDataName(Motion* pkMotion);
    void FUN_0056d230(FourFloatVector& kRotationBasis);
};

struct Package
{
    int FUN_00726070();
    NiPoint3 FUN_00413fc0();
};

struct LayerHolder
{
    unsigned int FUN_00559450();
};

struct Process
{
    Package* FUN_0041fbe0();
    LayerHolder* FUN_004211a0();
};

struct Cell
{
    void* FUN_004543c0();
};

float FUN_004a3e90(float fValue);

class Actor
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
    virtual NiNode* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual NiPoint3* GetPos();

    Process* FUN_005d43c0();
    Cell* FUN_008d6f30();
    void FUN_00567490(float fScale);
    Box FUN_0056fa00();
    void FUN_0056eab0();
};

}

namespace fnv_0056f700 {
class ObjRef
{
  public:
    int GetFormType();
};

class ExtraDataList;
class UpdData;
class Ref;

class ExtraDataList
{
  public:
    void* FUN_0041fbe0();
    void FUN_00422bc0(Ref*);
};

class UpdData
{
  public:
    int pad[3];
    void NiUpdateData(float, bool, bool);
};

extern "C" char DAT_011c3b3c;
extern "C" char DAT_011dea10;
extern "C" char DAT_011e0e80;
extern "C" char DAT_011ddf38;

bool __cdecl FUN_005ac750(Ref*, ExtraDataList*, unsigned int);

class Ref
{
  public:
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
    virtual bool v64();
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
    bool FUN_00444ed0();
    ObjRef* GetObjectReference();
    void* Get3DSimple();
    void Update(void*);
    bool FUN_005651e0();
    bool IsDeleted();
    bool GetDisabled();
    ExtraDataList* GetExtraData();
    void* GetTarget(int, int);
    void FUN_008b6ae0();
    void FUN_008a1a70();
    void FUN_008b65f0();
    void FUN_0056f700();
};

}  // namespace fnv_0056f700

class NiNode;
class NiAVObject;
class TESForm;

class PlayerCharacter
{
  public:
    NiNode* GetNode(bool);
};

class Calendar
{
  public:
    unsigned int GetDaysPassed(void);
};

namespace fnv_00570f70 {
struct FormX
{
    int FUN_00401170();
};
struct MgrX
{
    void FUN_006c0c30();
    void FUN_006c0c80();
    void FUN_006c1060();
};
MgrX* __stdcall GetNavMeshObstacleManager(void* p);
bool __cdecl FUN_008c7aa0();
struct AuxX
{
    void FUN_0087b2b0();
};
AuxX* __stdcall FUN_004537b0(void* p);
extern FormX* DAT_011ca238;
extern FormX* DAT_011ca23c;

}  // namespace fnv_00570f70

namespace fnv_00572c80 {
class TESDataHandler
{
  public:
    bool FUN_00469860(void* value);
};

extern TESDataHandler* g_dataHandler;

}  // namespace fnv_00572c80

namespace s572e10 {

struct Entry
{
    int FUN_0041b4b0();
};

struct Owner
{
    Entry* FUN_005d43c0(int iKey);
    int FUN_00572e10(int iKey);
};

}

struct FormStub;

struct ProcStub
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
    virtual void p009();
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
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
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
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
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
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p180();
    virtual void p181();
    virtual void p182();
    virtual void p183();
    virtual void p184();
    virtual void p185();
    virtual void p186();
    virtual void p187();
    virtual void p188();
    virtual void p189();
    virtual void p190();
    virtual void p191();
    virtual void p192();
    virtual void p193();
    virtual void p194();
    virtual void p195();
    virtual void p196();
    virtual void p197();
    virtual void p198();
    virtual void p199();
    virtual void p200();
    virtual void p201();
    virtual void p202();
    virtual void p203();
    virtual void p204();
    virtual void p205();
    virtual void p206();
    virtual void p207();
    virtual void p208();
    virtual void p209();
    virtual void p210();
    virtual void p211();
    virtual void p212();
    virtual void p213();
    virtual void p214();
    virtual void p215();
    virtual void p216();
    virtual void p217();
    virtual void p218();
    virtual void p219();
    virtual void p220();
    virtual void p221();
    virtual void p222();
    virtual void p223();
    virtual void p224();
    virtual void p225();
    virtual void p226();
    virtual void p227();
    virtual void p228();
    virtual void p229();
    virtual void p230();
    virtual void p231();
    virtual void p232();
    virtual void p233();
    virtual void p234();
    virtual void p235();
    virtual void p236();
    virtual void p237();
    virtual void p238();
    virtual void p239();
    virtual void p240();
    virtual void p241();
    virtual void p242();
    virtual void p243();
    virtual void p244();
    virtual void p245();
    virtual void p246();
    virtual void p247();
    virtual void p248();
    virtual void p249();
    virtual void p250();
    virtual void p251();
    virtual void p252();
    virtual void p253();
    virtual void p254();
    virtual void p255();
    virtual void p256();
    virtual void p257();
    virtual void p258();
    virtual void p259();
    virtual void p260();
    virtual void p261();
    virtual void p262();
    virtual void p263();
    virtual void p264();
    virtual void p265();
    virtual void p266();
    virtual void p267();
    virtual void p268();
    virtual void p269();
    virtual void p270();
    virtual void p271();
    virtual void p272();
    virtual void p273();
    virtual void p274();
    virtual void p275();
    virtual void p276();
    virtual void p277();
    virtual void p278();
    virtual void p279();
    virtual void p280();
    virtual void p281();
    virtual void p282();
    virtual void p283();
    virtual void p284();
    virtual void p285();
    virtual void p286();
    virtual void p287();
    virtual void p288();
    virtual void p289();
    virtual void p290();
    virtual void p291();
    virtual void p292();
    virtual void p293();
    virtual void p294();
    virtual void p295();
    virtual void p296();
    virtual void p297();
    virtual void p298();
    virtual void p299();
    virtual void p300();
    virtual void p301();
    virtual void p302();
    virtual void p303();
    virtual void p304();
    virtual void p305();
    virtual void p306();
    virtual void p307();
    virtual void p308();
    virtual void p309();
    virtual void p310();
    virtual void p311();
    virtual void p312();
    virtual void p313();
    virtual void p314();
    virtual void p315();
    virtual void p316();
    virtual void p317();
    virtual void p318();
    virtual void p319();
    virtual void p320();
    virtual void p321();
    virtual void p322();
    virtual void p323();
    virtual void p324();
    virtual void p325();
    virtual void p326();
    virtual void p327();
    virtual void p328();
    virtual void p329();
    virtual void p330();
    virtual void p331();
    virtual void p332();
    virtual void p333();
    virtual void p334();
    virtual void p335();
    virtual void p336();
    virtual void p337();
    virtual void p338();
    virtual void p339();
    virtual void p340();
    virtual void p341();
    virtual void p342();
    virtual void p343();
    virtual void p344();
    virtual void p345();
    virtual void p346();
    virtual void p347();
    virtual void p348();
    virtual void p349();
    virtual void p350();
    virtual void p351();
    virtual void p352();
    virtual void p353();
    virtual void p354();
    virtual void p355();
    virtual void p356();
    virtual void p357();
    virtual void p358();
    virtual void p359();
    virtual void p360();
    virtual void p361();
    virtual void p362();
    virtual void p363();
    virtual void p364();
    virtual void p365();
    virtual void p366();
    virtual void p367();
    virtual void p368();
    virtual void p369();
    virtual void p370();
    virtual void p371();
    virtual void p372();
    virtual void p373();
    virtual void p374();
    virtual void p375();
    virtual void p376();
    virtual void p377();
    virtual void p378();
    virtual void p379();
    virtual void p380();
    virtual void p381();
    virtual void p382();
    virtual void p383();
    virtual void p384();
    virtual void p385();
    virtual void p386();
    virtual void p387();
    virtual void p388();
    virtual void p389();
    virtual void p390();
    virtual void p391();
    virtual void p392();
    virtual void p393();
    virtual void p394();
    virtual void p395();
    virtual void p396();
    virtual void p397();
    virtual void p398();
    virtual void p399();
    virtual void p400();
    virtual void p401();
    virtual void p402();
    virtual void p403();
    virtual void p404();
    virtual void p405();
    virtual void p406();
    virtual void p407();
    virtual void p408();
    virtual void p409();
    virtual void p410();
    virtual void p411();
    virtual void p412();
    virtual void p413();
    virtual void p414();
    virtual void p415();
    virtual void p416();
    virtual void p417();
    virtual void p418();
    virtual void p419();
    virtual void p420();
    virtual void p421();
    virtual void p422();
    virtual void p423();
    virtual void p424();
    virtual void p425();
    virtual void p426();
    virtual void p427();
    virtual void p428();
    virtual void p429();
    virtual void p430();
    virtual void p431();
    virtual void p432();
    virtual void p433();
    virtual void p434();
    virtual void p435();
    virtual void p436();
    virtual void p437();
    virtual void p438();
    virtual void p439();
    virtual void p440();
    virtual void p441();
    virtual void p442();
    virtual void p443();
    virtual void p444();
    virtual void p445();
    virtual void p446();
    virtual void p447();
    virtual void p448();
    virtual void p449();
    virtual void p450();
    virtual void p451();
    virtual void p452();
    virtual void p453();
    virtual void p454();
    virtual void p455();
    virtual void p456();
    virtual void p457();
    virtual void p458();
    virtual void p459();
    virtual void p460();
    virtual void p461();
    virtual void p462();
    virtual void p463();
    virtual void p464();
    virtual void p465();
    virtual void p466();
    virtual void p467();
    virtual void p468();
    virtual void p469();
    virtual void p470();
    virtual void p471();
    virtual void p472();
    virtual void p473();
    virtual void p474();
    virtual void p475();
    virtual void p476();
    virtual void p477();
    virtual void p478();
    virtual void p479();
    virtual void p480();
    virtual void p481();
    virtual void p482();
    virtual void p483();
    virtual void p484();
    virtual void p485();
    virtual void p486();
    virtual void p487();
    virtual void p488();
    virtual void p489();
    virtual void p490();
    virtual void p491();
    virtual void p492();
    virtual void p493();
    virtual void p494();
    virtual void p495();
    virtual void p496();
    virtual void p497();
    virtual void p498();
    virtual void p499();
    virtual void p500();
    virtual void p501();
    virtual void p502();
    virtual void p503();
    virtual void p504();
    virtual void p505();
    virtual void p506();
    virtual void p507();
    virtual void p508();
    virtual void p509();
    virtual void p510();
    virtual void p511();
    virtual void p512();
    virtual void p513();
    virtual void p514();
    virtual void p515();
    virtual void p516();
    virtual void p517();
    virtual void p518();
    virtual void p519();
    virtual void SetTarget(FormStub* a);
    int GetLevel45cd60();
};

struct ActorStub;

struct RefrStub
{
    virtual void a000();
    virtual void a001();
    virtual void a002();
    virtual void a003();
    virtual void a004();
    virtual void a005();
    virtual void a006();
    virtual void a007();
    virtual void a008();
    virtual void a009();
    virtual void a010();
    virtual void a011();
    virtual void a012();
    virtual void a013();
    virtual void a014();
    virtual void a015();
    virtual void a016();
    virtual void a017();
    virtual void a018();
    virtual void v4c(int flag);
    virtual void b000();
    virtual void b001();
    virtual void b002();
    virtual void b003();
    virtual void b004();
    virtual void b005();
    virtual void b006();
    virtual void b007();
    virtual void b008();
    virtual void b009();
    virtual void b010();
    virtual void b011();
    virtual void b012();
    virtual void b013();
    virtual void b014();
    virtual void b015();
    virtual void b016();
    virtual void b017();
    virtual void b018();
    virtual void b019();
    virtual void b020();
    virtual void b021();
    virtual void b022();
    virtual void b023();
    virtual void b024();
    virtual void b025();
    virtual void b026();
    virtual void b027();
    virtual void b028();
    virtual void b029();
    virtual void b030();
    virtual void b031();
    virtual void b032();
    virtual void b033();
    virtual void b034();
    virtual void b035();
    virtual void b036();
    virtual void b037();
    virtual void b038();
    virtual void b039();
    virtual void b040();
    virtual void b041();
    virtual void b042();
    virtual bool IsActor();
    void Flag484b90(int flag);
    FormStub* FUN_00572e50(FormStub* a);
};

struct ActorStub : RefrStub
{
    ProcStub* GetProc8d8520();
    void Reset931920(int x);
};

namespace s5730d0 {

struct Package
{
    int FUN_0044edb0();
};

struct Process
{
    Package* FUN_0042e8c0();
};

struct Actor
{
    Process* FUN_005d43c0();
    int FUN_005730d0();
};

}

namespace fnv_00573f40 {
extern "C" char DAT_011ca27c, DAT_011ca280, DAT_011e0e80, DAT_011dea10, DAT_011c3b3c, DAT_011dea3c;
struct R;
struct P
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5(R*, bool);
    int FUN_0045cd60();
};
struct N
{
    void* FUN_00559450();
};
struct L
{
    bool FUN_008256d0();
    R** FUN_006815c0();
    L* FUN_00726070();
};
struct E
{
    R* FUN_0041e310();
    bool FUN_0041dc20();
    bool ExtraEncounterZone_Compare();
};
bool __fastcall ExtraEncounterZone_Compare(E*);
struct F
{
    int FUN_00401170();
};
struct C
{
    void FUN_00545590(R*);
    bool FUN_00450ff0();
};
struct S
{
    void FUN_00b5f080(void*);
};
S* __cdecl FUN_00450b80(unsigned);
struct FUN_00906dc0
{
    int pad[45];
    FUN_00906dc0();
};
struct R
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
    virtual void v50(bool);
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
    virtual bool v63();
    virtual bool v64();
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
    virtual void* v116();
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
    virtual void v130(bool);
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
    virtual void v151(float);
    virtual void v152();
    bool FUN_00440da0();
    void FUN_00484af0(int);
    C* FUN_008d6f30();
    E* FUN_005d43c0();
    F* FUN_007af430();
    P* FUN_008d8520();
    void FUN_00407800(FUN_00906dc0*);
    void FUN_00579ac0(bool);
    bool FUN_00440d80();
    bool FUN_00444ed0();
    N* FUN_005725f0();
    void FUN_008a6ce0(int, int);
    float FUN_0056b190();
    L* FUN_0056ac90();
    bool FUN_0056aa70();
    void FUN_00574400();
    void FUN_0056c780(bool);
    void FUN_00573f40();
};
}  // namespace fnv_00573f40

namespace fnv_005750a0 {
struct S;
struct Item
{
    int FUN_00401170();
};
struct Cell
{
    void FUN_00545590(S*);
};
struct Part
{
    bool FUN_00474a80();
};
struct Weapon
{
    char pad[164];
    Part part;
};
struct Entry
{
    Item* FUN_0044ddc0();
};
struct Process
{
    virtual void p0(), p1(), p2(), p3(), p4(), p5(), p6(), p7(), p8(), p9();
    virtual void p10(), p11(), p12(), p13(), p14(), p15(), p16(), p17(), p18(), p19();
    virtual void p20(), p21(), p22(), p23(), p24(), p25(), p26(), p27(), p28(), p29();
    virtual void p30(), p31(), p32(), p33(), p34(), p35(), p36(), p37(), p38(), p39();
    virtual void p40(), p41(), p42(), p43(), p44(), p45(), p46(), p47(), p48(), p49();
    virtual void p50(), p51(), p52(), p53(), p54(), p55(), p56(), p57(), p58(), p59();
    virtual void p60(), p61(), p62(), p63(), p64(), p65(), p66(), p67(), p68(), p69();
    virtual void p70(), p71(), p72(), p73(), p74(), p75(), p76(), p77(), p78(), p79();
    virtual void p80(), p81(), p82(), p83(), p84(), p85(), p86(), p87(), p88(), p89();
    virtual void p90(), p91(), p92(), p93(), p94();
    virtual void update(Item*, void*);
};
struct Inv
{
    int FUN_004c37d0(S*, Item*, bool, int, void*, bool, int, int, int, bool, bool, int);
};
extern "C" char DAT_011dea3c;
extern bool FUN_005ac750(S*, void*, int);
extern Inv* FUN_004bf220(S*);
struct S
{
    virtual void a0(), a1(), a2(), a3(), a4(), a5(), a6(), a7(), a8(), a9();
    virtual void a10(), a11(), a12(), a13(), a14(), a15(), a16(), a17(), a18(), a19();
    virtual void a20(), a21(), a22(), a23(), a24(), a25(), a26(), a27(), a28(), a29();
    virtual void a30(), a31(), a32(), a33(), a34(), a35(), a36(), a37(), a38(), a39();
    virtual void a40(), a41(), a42(), a43(), a44(), a45(), a46(), a47(), a48(), a49();
    virtual void a50(), a51(), a52(), a53(), a54(), a55(), a56(), a57(), a58(), a59();
    virtual void a60(), a61(), a62(), a63();
    virtual bool isactor();
    virtual void a65(), a66(), a67(), a68(), a69();
    virtual void a70(), a71(), a72(), a73(), a74(), a75(), a76(), a77(), a78(), a79();
    virtual void a80(), a81(), a82(), a83(), a84(), a85(), a86(), a87(), a88(), a89();
    virtual void a90(), a91(), a92(), a93(), a94(), a95(), a96(), a97(), a98(), a99();
    virtual void a100(), a101(), a102(), a103(), a104(), a105(), a106(), a107(), a108(), a109();
    virtual void a110(), a111(), a112(), a113(), a114(), a115(), a116(), a117(), a118(), a119();
    virtual void a120(), a121(), a122(), a123(), a124(), a125(), a126(), a127(), a128(), a129();
    virtual void a130(), a131(), a132(), a133(), a134(), a135(), a136(), a137(), a138();
    virtual bool dead(int);
    virtual void a140(), a141(), a142(), a143(), a144(), a145(), a146(), a147(), a148(), a149();
    virtual void a150(), a151(), a152(), a153(), a154(), a155(), a156(), a157(), a158(), a159();
    virtual void a160(), a161(), a162(), a163(), a164(), a165(), a166(), a167(), a168(), a169();
    virtual void a170(), a171(), a172(), a173(), a174(), a175(), a176(), a177(), a178(), a179();
    virtual void a180(), a181(), a182(), a183(), a184(), a185(), a186(), a187(), a188(), a189();
    virtual void a190(), a191(), a192(), a193(), a194(), a195(), a196(), a197(), a198(), a199();
    virtual void a200(), a201(), a202(), a203(), a204(), a205(), a206(), a207(), a208(), a209();
    virtual void a210(), a211(), a212(), a213(), a214(), a215();
    virtual bool check();
    virtual void a217(), a218(), a219();
    virtual void a220(), a221(), a222(), a223(), a224(), a225(), a226(), a227(), a228(), a229();
    virtual void a230(), a231(), a232(), a233(), a234(), a235(), a236(), a237(), a238();
    virtual Entry* entry(int);
    void* FUN_0055d310();
    Cell* FUN_008d6f30();
    bool FUN_005656d0();
    int FUN_00575610(Weapon*);
    void FUN_009691d0();
    Process* FUN_008d8520();
    bool FUN_00493bb0();
    bool FUN_00566950();
    void FUN_0088c830(Item*, int, void*, bool, bool, bool);
    void FUN_0088c650(Item*, int, void*, bool, bool, bool);
    int FUN_005750a0(Item*, void*, int, bool, bool, int, int, int, bool, bool);
};
}  // namespace fnv_005750a0

struct Obj4bf
{
    int FUN_004bfda0(int a, int b);
};
struct Thing575
{
    void* FUN_0055d310();
    bool FUN_00575400(int a);
};
Obj4bf* FUN_004bf220(Thing575* t);

namespace fnv_00575590 {
struct Global
{
    int FUN_00740960();
};
extern Global* DAT_011c3f2c;

struct Obj
{
    int FUN_004c8fd0(unsigned char value);
};

struct Thing
{
    int FUN_0055d310();
    int FUN_00575590(unsigned char flag, unsigned char value);
};

extern "C" void* FUN_004bf220(void* self);

}  // namespace fnv_00575590

namespace s575ca0 {

struct Package
{
    Package* FUN_0054ddd0();
};

struct Process
{
    Package* FUN_0041d460();
};

struct Owner
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
    Package* m_pkPackage;

    Process* FUN_005d43c0();
    Package* FUN_00575ca0();
};

}

class FUN_00575e30_cls;

class FUN_00575e30_mid
{
  public:
    BSExtraData* FUN_00410220();
    void FUN_0040ff60();
};
class FUN_00575e30_cls
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48(unsigned int);
    FUN_00575e30_mid* FUN_005d43c0(unsigned int a);
    FUN_00575e30_mid* FUN_005d43c0(void* a);
    void* FUN_00575e30();
};

namespace fnv_00577250 {
class PlayerCharacter
{
  public:
    float FUN_00577310();
};

extern PlayerCharacter* g_thePlayer;

class ItemData
{
  public:
    float FUN_004d0900(bool arg);
};

class ExtraList
{
  public:
    ItemData* FUN_00418520();
};

}  // namespace fnv_00577250

namespace s577de0 {

struct Info
{
    bool FUN_004d0360();
};

struct Owner;
Info* FUN_004bf220(Owner* pkOwner);

struct Owner
{
    void* FUN_0055d310();
    bool FUN_00577de0();
};

}

namespace fnv_00577e20 {
#include <string.h>

class NiFixedString
{
  public:
    bool IsNotEmpty() const;
    operator const char*() const;
};
struct TraversalNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual TraversalNode* AsNode();
    virtual XNode* AsGeometry();
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
    virtual void Attach(TraversalNode*, bool);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void Remove(unsigned int);
    unsigned int FUN_0043b480();
    TraversalNode* FUN_0043b4a0(unsigned int);
    NiFixedString& GetName();
    unsigned int FUN_009ee040();
    void FUN_004902f0(bool);
    void FUN_00576660(int);
};
bool FUN_0043b300(const void*, TraversalNode*);
void FUN_005784f0(TraversalNode*, float);
}  // namespace fnv_00577e20

namespace fnv_00578a30 {
class TESSaveLoadGame
{
  public:
    bool FUN_0047c850();
};
extern TESSaveLoadGame* DAT_011de45c;
struct Sub
{
    int FUN_004228f0();
    void MapMarkerData_SetTravelLoc(int arg);
};
struct Thing
{
    Sub* FUN_005d43c0();
    void FUN_00578a30(int arg);
};
}  // namespace fnv_00578a30

namespace fnv_00579280 {
class BoundForm
{
  public:
    unsigned int FUN_00401170();
    bool FUN_005093f0();
    bool FUN_00509420();
    bool FUN_0046f070();
};
class ActorData
{
  public:
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual bool IsEssential();
};
class ActorBaseData
{
  public:
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
    ActorData actorData;
};
class ReferenceView
{
  public:
    virtual void UnknownVirtual000();
    virtual void UnknownVirtual001();
    virtual void UnknownVirtual002();
    virtual void UnknownVirtual003();
    virtual void UnknownVirtual004();
    virtual void UnknownVirtual005();
    virtual void UnknownVirtual006();
    virtual void UnknownVirtual007();
    virtual void UnknownVirtual008();
    virtual void UnknownVirtual009();
    virtual void UnknownVirtual010();
    virtual void UnknownVirtual011();
    virtual void UnknownVirtual012();
    virtual void UnknownVirtual013();
    virtual void UnknownVirtual014();
    virtual void UnknownVirtual015();
    virtual void UnknownVirtual016();
    virtual void UnknownVirtual017();
    virtual void UnknownVirtual018();
    virtual void UnknownVirtual019();
    virtual void UnknownVirtual020();
    virtual void UnknownVirtual021();
    virtual void UnknownVirtual022();
    virtual void UnknownVirtual023();
    virtual void UnknownVirtual024();
    virtual void UnknownVirtual025();
    virtual void UnknownVirtual026();
    virtual void UnknownVirtual027();
    virtual void UnknownVirtual028();
    virtual void UnknownVirtual029();
    virtual void UnknownVirtual030();
    virtual void UnknownVirtual031();
    virtual void UnknownVirtual032();
    virtual void UnknownVirtual033();
    virtual void UnknownVirtual034();
    virtual void UnknownVirtual035();
    virtual void UnknownVirtual036();
    virtual void UnknownVirtual037();
    virtual void UnknownVirtual038();
    virtual void UnknownVirtual039();
    virtual void UnknownVirtual040();
    virtual void UnknownVirtual041();
    virtual void UnknownVirtual042();
    virtual void UnknownVirtual043();
    virtual void UnknownVirtual044();
    virtual void UnknownVirtual045();
    virtual void UnknownVirtual046();
    virtual void UnknownVirtual047();
    virtual void UnknownVirtual048();
    virtual void UnknownVirtual049();
    virtual void UnknownVirtual050();
    virtual void UnknownVirtual051();
    virtual void UnknownVirtual052();
    virtual void UnknownVirtual053();
    virtual void UnknownVirtual054();
    virtual void UnknownVirtual055();
    virtual void UnknownVirtual056();
    virtual void UnknownVirtual057();
    virtual void UnknownVirtual058();
    virtual void UnknownVirtual059();
    virtual void UnknownVirtual060();
    virtual void UnknownVirtual061();
    virtual void UnknownVirtual062();
    virtual void UnknownVirtual063();
    virtual bool IsActor();
    virtual void UnknownVirtual065();
    virtual void UnknownVirtual066();
    virtual void UnknownVirtual067();
    virtual void UnknownVirtual068();
    virtual void UnknownVirtual069();
    virtual void UnknownVirtual070();
    virtual void UnknownVirtual071();
    virtual void UnknownVirtual072();
    virtual void UnknownVirtual073();
    virtual void UnknownVirtual074();
    virtual void UnknownVirtual075();
    virtual void UnknownVirtual076();
    virtual void UnknownVirtual077();
    virtual void UnknownVirtual078();
    virtual void UnknownVirtual079();
    virtual void UnknownVirtual080();
    virtual void UnknownVirtual081();
    virtual void UnknownVirtual082();
    virtual void UnknownVirtual083();
    virtual void UnknownVirtual084();
    virtual void UnknownVirtual085();
    virtual void UnknownVirtual086();
    virtual void UnknownVirtual087();
    virtual void UnknownVirtual088();
    virtual void UnknownVirtual089();
    virtual void UnknownVirtual090();
    virtual void UnknownVirtual091();
    virtual void UnknownVirtual092();
    virtual void UnknownVirtual093();
    virtual void UnknownVirtual094();
    virtual void UnknownVirtual095();
    virtual void UnknownVirtual096();
    virtual void UnknownVirtual097();
    virtual void UnknownVirtual098();
    virtual void UnknownVirtual099();
    virtual void UnknownVirtual100();
    virtual void UnknownVirtual101();
    virtual void UnknownVirtual102();
    virtual void UnknownVirtual103();
    virtual void UnknownVirtual104();
    virtual void UnknownVirtual105();
    virtual void UnknownVirtual106();
    virtual void UnknownVirtual107();
    virtual void UnknownVirtual108();
    virtual void UnknownVirtual109();
    virtual void UnknownVirtual110();
    virtual void UnknownVirtual111();
    virtual void UnknownVirtual112();
    virtual void UnknownVirtual113();
    virtual void UnknownVirtual114();
    virtual void UnknownVirtual115();
    virtual void UnknownVirtual116();
    virtual void UnknownVirtual117();
    virtual void UnknownVirtual118();
    virtual void UnknownVirtual119();
    virtual void UnknownVirtual120();
    virtual void UnknownVirtual121();
    virtual void UnknownVirtual122();
    virtual void UnknownVirtual123();
    virtual void UnknownVirtual124();
    virtual void UnknownVirtual125();
    virtual void UnknownVirtual126();
    virtual void UnknownVirtual127();
    virtual void UnknownVirtual128();
    virtual void UnknownVirtual129();
    virtual void UnknownVirtual130();
    virtual void UnknownVirtual131();
    virtual void UnknownVirtual132();
    virtual void UnknownVirtual133();
    virtual void UnknownVirtual134();
    virtual void UnknownVirtual135();
    virtual void UnknownVirtual136();
    virtual void UnknownVirtual137();
    virtual void UnknownVirtual138();
    virtual bool IsDead(int flags);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    BoundForm* baseForm;
    bool FUN_00477ba0();
    BoundForm* FUN_007af430();
    const char* FUN_0055d520();
    int FUN_004f8960();
    bool FUN_00579670();
    bool FUN_0047c850();
    bool FUN_0087f3d0();
    bool FUN_004997b0();
    bool FUN_00566950();
    ActorBaseData* FUN_004181e0();
    int FUN_00579280();
};
extern ReferenceView* g_thePlayer;

}  // namespace fnv_00579280

void* __fastcall _FNV_GetObjectReference(void*);

class Actor
{
  public:
    bool FUN_00437b90(void);
};

void* __fastcall _FNV_GetObjectReference(void*);
bool __fastcall FUN_00477ba0(void*);

namespace fnv_0057ada0 {
struct Vec3
{
    float x;
    float y;
    float z;
    bool FUN_004390c0(const char* s);
};
struct Vec2
{
    float x;
    float y;
    Vec2* FUN_00452dc0(float a, float b);
};
struct TObject;
struct RetObj
{
    void FUN_00a59c60(TObject* p);
};
RetObj* FUN_00450b80(int a);
struct TObject
{
    float a;
    float b;
    float c;
    void FUN_0043d410(float f, int i1, int i2);
};
struct BObj
{
    void FUN_00416a30(Vec2* v);
    void FUN_004169f0(void* p);
    void FUN_00416a70(void* p);
};
struct DObj;
struct CObj
{
    DObj* FUN_006629f0();
};
struct EObj
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
    virtual int GetMode35();
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
    virtual void SetVec46(Vec3* v);
    void FUN_00439680(Vec3* v);
    void FUN_004396b0(void* p);
};
struct DObj
{
    EObj* FUN_0043b230();
    void FUN_004addc0(void* p);
};
struct MidObj
{
    Vec3* FUN_0045bb80();
    void* FUN_006a9540();
};
struct AObj
{
    virtual void av0();
    virtual void av1();
    virtual void av2();
    virtual void av3();
    virtual void av4();
    virtual void* GetVec5(Vec3* v);
    Vec3* FUN_00413fc0(Vec3* out);
    MidObj* FUN_0056c7f0();
};
struct XObj
{
    AObj* FUN_0041fbe0();
    BObj* FUN_00422120();
    BObj* FUN_00420dd0();
    CObj* FUN_00420ed0();
    DObj* FUN_00422020();
};
extern int DAT_011ca234;
extern int DAT_011ca23c;
extern int DAT_011ca238;
extern int DAT_011ca230;
extern const char DAT_011f426c[];

}  // namespace fnv_0057ada0

namespace fnv_0057b410 {
struct Other
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
    virtual bool vf();
};

struct Thing
{
    Other* FUN_007af430();
    bool FUN_0057b410();
};

}  // namespace fnv_0057b410

void* __fastcall _FNV_GetObjectReference(void*);

void* __fastcall _FNV_GetObjectReference(void*);
unsigned int __fastcall FUN_0044ddc0(void*);

namespace fnv_0057b7c0 {
// 0x0057b7c0  Actor dialogue helper  /MT /Od /Oy- /GS /EHsc /Gy
extern "C" int sprintf(char*, const char*, ...);
extern "C" void* DAT_011dea3c;

struct Set57
{
    int* Int();
    void FUN_0045ce80(int);
};
extern Set57 DAT_011cd378;

struct PL57
{
    void FUN_0096e570();
};
extern PL57 DAT_011e0e80;

struct P12
{
    int x, y, z;
};

struct S12
{
    int a;
    unsigned char b;
    int c;
    S12(int);
    S12(const S12&);
    ~S12();
};

struct Proc57;
struct DialogItem57;
struct Resp57;
struct Txt57;
struct Topic57;

struct Proc57
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
    virtual void v1dc(void*, int);
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
    virtual void d131();
    virtual void d132();
    virtual void d133();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void d141();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void* v248();
    virtual void v24c(int);
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual void d159();
    virtual void d160();
    virtual void d161();
    virtual void d162();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void v2a4(void*, void*, unsigned char, int, int, int);
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual void d175();
    virtual void d176();
    virtual void d177();
    virtual void d178();
    virtual void d179();
    virtual void d180();
    virtual void d181();
    virtual void d182();
    virtual void d183();
    virtual void d184();
    virtual void d185();
    virtual void d186();
    virtual void d187();
    virtual void d188();
    virtual void d189();
    virtual void d190();
    virtual void d191();
    virtual void d192();
    virtual void d193();
    virtual void d194();
    virtual bool v30c();
};

struct DialogItem57
{
    void FUN_0083c7b0();
    Resp57* GetCurrentItem();
    void FUN_0083c850(int);
    void* FUN_0084e3a0();
};

struct Resp57
{
    Txt57* FUN_006815c0();
};
struct Txt57
{
    const char* FUN_00559450();
};
struct Topic57
{
    DialogItem57* FUN_0061b320(void*, void*, void*, void*, bool);
};

bool FUN_00703150();
bool FUN_005ac750(void*, void*, unsigned int);
void FUN_00705210(const char*, S12, P12, void*, bool);

}  // namespace fnv_0057b7c0

namespace DialogueUpdate {

struct DlgPoint
{
    float x, y, z;
};

struct DlgTarget
{
    int iData[3];
    DlgTarget(const DlgTarget& arOther);
    ~DlgTarget();
};

struct DlgNode
{
    DlgNode* FUN_0083c820();
    DlgNode* FUN_006815c0();
    const char* FUN_00559450();
    void FUN_0083c850(int aiValue);
};

struct DlgFlag
{
    char pad00[0x80];
    unsigned char bPickResultFound;
};

struct DlgPackage
{
    int FUN_0041ca90();
    DlgNode* FUN_008cdd90();
    void* FUN_009ee040();
    void* FUN_008d80e0();
    DlgNode* FUN_005e3fc0();
    char pad00[0x90];
    float m_fPackageValue;
    DlgFlag* pFlag;
};

struct DlgTopic
{
    virtual void t000();
    virtual void t001();
    virtual void t002();
    virtual void t003();
    virtual void t004();
    virtual void t005();
    virtual void t006();
    virtual void t007();
    virtual void t008();
    virtual void t009();
    virtual void t00a();
    virtual void t00b();
    virtual void t00c();
    virtual void t00d();
    virtual void t00e();
    virtual void t00f();
    virtual void t010();
    virtual void t011();
    virtual void t012();
    virtual void t013();
    virtual void t014();
    virtual void t015();
    virtual void t016();
    virtual void t017();
    virtual void t018();
    virtual void t019();
    virtual void t01a();
    virtual void t01b();
    virtual void t01c();
    virtual void t01d();
    virtual void t01e();
    virtual void t01f();
    virtual void t020();
    virtual void t021();
    virtual void t022();
    virtual void t023();
    virtual void t024();
    virtual void t025();
    virtual void t026();
    virtual void t027();
    virtual void t028();
    virtual void t029();
    virtual void t02a();
    virtual void t02b();
    virtual void t02c();
    virtual void FUN_vtb4(float afTime, int a2, int a3, int a4, int a5, int a6);
    virtual void t02e();
    virtual void t02f();
    virtual void t030();
    virtual void t031();
    virtual void t032();
    virtual void t033();
    virtual void t034();
    virtual void t035();
    virtual void t036();
    virtual void t037();
    virtual void t038();
    virtual void t039();
    virtual void t03a();
    virtual void t03b();
    virtual void t03c();
    virtual void t03d();
    virtual void t03e();
    virtual void t03f();
    virtual void t040();
    virtual void t041();
    virtual void t042();
    virtual void t043();
    virtual void t044();
    virtual void FUN_vt114(int aiSound, float afVolume);
    virtual void t046();
    virtual void FUN_vt11c(int aiValue, int aiFlag);
};

struct DlgProcess
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
    virtual void p009();
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
    virtual void FUN_vt88(int aiValue);
    virtual void p023();
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
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p04a();
    virtual void p04b();
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
    virtual DlgPackage* GetCurrentPackage();
    virtual void p08c();
    virtual void p08d();
    virtual void p08e();
    virtual void p08f();
    virtual void p090();
    virtual void p091();
    virtual DlgNode* FUN_vt248();
    virtual void FUN_vt24c(int aiValue);
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
    virtual void p09f();
    virtual void p0a0();
    virtual void p0a1();
    virtual void p0a2();
    virtual void p0a3();
    virtual void p0a4();
    virtual void p0a5();
    virtual void p0a6();
    virtual void p0a7();
    virtual void p0a8();
    virtual void p0a9();
    virtual void p0aa();
    virtual void p0ab();
    virtual void p0ac();
    virtual void p0ad();
    virtual void p0ae();
    virtual void p0af();
    virtual void p0b0();
    virtual void p0b1();
    virtual void p0b2();
    virtual void p0b3();
    virtual void p0b4();
    virtual void p0b5();
    virtual void p0b6();
    virtual void p0b7();
    virtual void p0b8();
    virtual void p0b9();
    virtual void p0ba();
    virtual void p0bb();
    virtual void p0bc();
    virtual void p0bd();
    virtual void p0be();
    virtual void p0bf();
    virtual void p0c0();
    virtual void p0c1();
    virtual void p0c2();
    virtual bool FUN_vt30c();
    virtual void p0c4();
    virtual void p0c5();
    virtual void p0c6();
    virtual void p0c7();
    virtual void p0c8();
    virtual void p0c9();
    virtual void p0ca();
    virtual void p0cb();
    virtual void p0cc();
    virtual void p0cd();
    virtual void p0ce();
    virtual void p0cf();
    virtual void p0d0();
    virtual void p0d1();
    virtual void p0d2();
    virtual void p0d3();
    virtual void p0d4();
    virtual void p0d5();
    virtual void p0d6();
    virtual void p0d7();
    virtual void p0d8();
    virtual void p0d9();
    virtual void p0da();
    virtual void p0db();
    virtual void p0dc();
    virtual void p0dd();
    virtual void p0de();
    virtual void p0df();
    virtual void p0e0();
    virtual void p0e1();
    virtual void p0e2();
    virtual void p0e3();
    virtual void p0e4();
    virtual void p0e5();
    virtual void p0e6();
    virtual void p0e7();
    virtual void p0e8();
    virtual void p0e9();
    virtual void p0ea();
    virtual void p0eb();
    virtual void p0ec();
    virtual void p0ed();
    virtual void p0ee();
    virtual void p0ef();
    virtual void p0f0();
    virtual void p0f1();
    virtual void p0f2();
    virtual void p0f3();
    virtual void p0f4();
    virtual void p0f5();
    virtual void p0f6();
    virtual void p0f7();
    virtual void p0f8();
    virtual void p0f9();
    virtual void p0fa();
    virtual void p0fb();
    virtual void p0fc();
    virtual void p0fd();
    virtual void p0fe();
    virtual void p0ff();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p10a();
    virtual void p10b();
    virtual void p10c();
    virtual void p10d();
    virtual void p10e();
    virtual void p10f();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p11a();
    virtual void p11b();
    virtual void p11c();
    virtual void p11d();
    virtual void p11e();
    virtual void p11f();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual DlgTarget FUN_vt48c(int aiFlags);
};

struct DlgCheck;

struct DlgQuery
{
    int iData;
    DlgQuery();
    ~DlgQuery();
    DlgCheck* FUN_009369a0();
};

struct DlgConversation
{
    void FUN_0061e760(DlgQuery* apQuery);
    bool FUN_00579200();
    void FUN_0061f170(int aiValue, struct DlgActor* apActor);
};

struct DlgExtraList
{
    void FUN_0042edb0();
};

struct DlgActorValues
{
    virtual void v00();
    virtual void v01();
    virtual int GetActorValue(int aiIndex);
};

struct DlgActor
{
    virtual void a000();
    virtual void a001();
    virtual void a002();
    virtual void a003();
    virtual void a004();
    virtual void a005();
    virtual void a006();
    virtual void a007();
    virtual void a008();
    virtual void a009();
    virtual void a00a();
    virtual void a00b();
    virtual void a00c();
    virtual void a00d();
    virtual void a00e();
    virtual void a00f();
    virtual void a010();
    virtual void a011();
    virtual void a012();
    virtual void a013();
    virtual void a014();
    virtual void a015();
    virtual void a016();
    virtual void a017();
    virtual void a018();
    virtual void a019();
    virtual void a01a();
    virtual void a01b();
    virtual void a01c();
    virtual void a01d();
    virtual void a01e();
    virtual void a01f();
    virtual void a020();
    virtual void a021();
    virtual void a022();
    virtual void a023();
    virtual void a024();
    virtual void a025();
    virtual void a026();
    virtual void a027();
    virtual void a028();
    virtual void a029();
    virtual void a02a();
    virtual void a02b();
    virtual void a02c();
    virtual void a02d();
    virtual void a02e();
    virtual void a02f();
    virtual void a030();
    virtual void a031();
    virtual void a032();
    virtual void a033();
    virtual void a034();
    virtual void a035();
    virtual void a036();
    virtual void a037();
    virtual void a038();
    virtual void a039();
    virtual void a03a();
    virtual void a03b();
    virtual void a03c();
    virtual void a03d();
    virtual void a03e();
    virtual void a03f();
    virtual bool IsActor();
    virtual void a041();
    virtual void a042();
    virtual void a043();
    virtual void a044();
    virtual void a045();
    virtual void a046();
    virtual void a047();
    virtual void a048();
    virtual void a049();
    virtual void a04a();
    virtual void a04b();
    virtual void a04c();
    virtual void a04d();
    virtual void a04e();
    virtual void a04f();
    virtual void a050();
    virtual void a051();
    virtual void a052();
    virtual void a053();
    virtual void a054();
    virtual void a055();
    virtual void a056();
    virtual void a057();
    virtual void a058();
    virtual void a059();
    virtual void a05a();
    virtual void a05b();
    virtual void a05c();
    virtual void a05d();
    virtual void a05e();
    virtual void a05f();
    virtual void a060();
    virtual void a061();
    virtual void a062();
    virtual void a063();
    virtual void a064();
    virtual void a065();
    virtual void a066();
    virtual void a067();
    virtual void a068();
    virtual void a069();
    virtual void a06a();
    virtual void a06b();
    virtual void a06c();
    virtual void a06d();
    virtual DlgTopic* FUN_vt1b8(int aiFlags);
    virtual void a06f();
    virtual void a070();
    virtual void a071();
    virtual void a072();
    virtual void a073();
    virtual void a074();
    virtual void a075();
    virtual void a076();
    virtual void a077();
    virtual void a078();
    virtual void a079();
    virtual void a07a();
    virtual void a07b();
    virtual void a07c();
    virtual DlgPoint* GetPos();
    virtual void a07e();
    virtual void a07f();
    virtual void a080();
    virtual void a081();
    virtual void a082();
    virtual void a083();
    virtual void a084();
    virtual void a085();
    virtual void a086();
    virtual void a087();
    virtual void a088();
    virtual void a089();
    virtual void a08a();
    virtual void a08b();
    virtual void a08c();
    virtual void a08d();
    virtual void a08e();
    virtual void a08f();
    virtual void a090();
    virtual void a091();
    virtual void a092();
    virtual void a093();
    virtual void a094();
    virtual void a095();
    virtual void a096();
    virtual void a097();
    virtual void a098();
    virtual void a099();
    virtual void a09a();
    virtual void a09b();
    virtual void a09c();
    virtual void a09d();
    virtual void a09e();
    virtual void a09f();
    virtual void a0a0();
    virtual void a0a1();
    virtual void a0a2();
    virtual void a0a3();
    virtual void a0a4();
    virtual void a0a5();
    virtual void a0a6();
    virtual void a0a7();
    virtual void a0a8();
    virtual void a0a9();
    virtual void a0aa();
    virtual void a0ab();
    virtual void a0ac();
    virtual void a0ad();
    virtual void a0ae();
    virtual void a0af();
    virtual void a0b0();
    virtual void a0b1();
    virtual void a0b2();
    virtual void a0b3();
    virtual int FUN_vt2d0();
    virtual void a0b5();
    virtual int FUN_vt2d8();
    char pad04[0x74];
    float m_fFirstReferenceTimer;
    char pad7c[3];
    unsigned char bSpoken;
    unsigned char bWasPlaying;
    char pad81[3];
    char pProcessData;
    unsigned char bSaid;
    char pad86[0x1e];
    DlgActorValues kValues;
    char padA8[0x160];
    DlgPackage* pDialoguePackage;

    DlgConversation* FUN_00934430();
    void* FUN_0057bd40();
    DlgCheck* FUN_008dd860();
    void FUN_0057ad20(int aiValue);
    DlgExtraList* FUN_005d43c0();
    DlgProcess* FUN_008d8520();
    DlgPackage* FUN_009344a0();
    float FUN_005723b0(DlgActor* apTarget, int a2, int a3);
    bool FUN_008c1bc0();
    const char* FUN_0055d520();
    void FUN_00953ce0();
    bool FUN_004eaf60();
    void FUN_00967730(void* apTopic, void* apInfo, DlgPackage* apPackage);
    void FUN_00935f60();
};

struct DlgIntSetting
{
    int* FUN_0043d4d0();
};
extern DlgActor* DAT_011dea3c;
extern DlgIntSetting DAT_011cd378;

void __cdecl FUN_005ac750(void* apOwner, DlgExtraList* apExtra, int aiFlags);
bool FUN_00703150();
int __cdecl FUN_00ec623a(char* apBuffer, const char* apFormat, ...);
void __cdecl FUN_00705210(const char* apText, DlgTarget kTarget, DlgPoint kPos, DlgActor* apListener, int aiFlags);

static const char s_szSubtitleFormat[] = "'%s' :%s";

}

TESForm* __cdecl FUN_004839c0(void*);

namespace fnv_005710c0 {
struct ModelRef;
struct ModelForm;
struct ModelNode;
struct ModelLink;
struct FUN_004ad050;
struct FUN_00438170
{
    const char* text;
    FUN_00438170(const char*);
    ~FUN_00438170();
};
struct ModelNode
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
    virtual ModelNode* Find(const FUN_00438170&);
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
    virtual void Attach(ModelNode*, bool);
    ModelNode* FUN_009611e0();
    ModelNode* FUN_00a5d2c0(FUN_004ad050*);
};
struct ModelNames
{
    ModelLink* FUN_00717e50();
};
struct ModelLink
{
    bool FUN_008256d0();
    const char** FUN_006815c0();
    ModelLink* FUN_00726070();
};
struct ModelForm
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
    virtual bool Fallback();
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
    ModelNames names;
    unsigned int FUN_00401170();
    void FUN_00605d70(ModelRef*);
    void FUN_005fa0a0(ModelRef*);
};
struct ModelEquipment
{
    bool FUN_00441b00();
};
struct ModelState
{
    void FUN_00496280();
};
struct ModelRef
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
    virtual ModelState* GetState();
    virtual void* GetAnimation();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    ModelForm* base;
    ModelNode* FUN_0043fcd0();
    ModelEquipment* FUN_009344a0();
    const char* FUN_005715d0();
    float FUN_00567400();
    ModelNode* FUN_00571530(ModelNode*, void*);
    bool FUN_005710c0();
};
struct FUN_004ad050
{
    void* unk00;
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    FUN_004ad050(float);
    ~FUN_004ad050();
};
struct FUN_00633c90
{
    ModelNode* ptr;
    FUN_00633c90(int);
    ~FUN_00633c90();
    FUN_00633c90* FUN_0066b0d0(ModelNode*);
    ModelNode* FUN_00559450();
};
struct AttachModelLoader
{
    ModelNode* FUN_00447080(const char*, int, int, int, int, int);
};
struct ModelEnvironment
{
    ModelNode* FUN_00457ba0(ModelNode*, FUN_004ad050*);
};
extern AttachModelLoader* DAT_011c3b3c;
extern ModelEnvironment* DAT_011dea10;
void FUN_00406d30(char*, unsigned int, const char*);
char* FUN_0040ab30(char*, int);
bool FUN_004b5bf0(ModelNode*);

}  // namespace fnv_005710c0

enum MEM_CONTEXT
{
    MC_REFR = 0x31
};
class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pFile, int iLine);
    ~AutoMemContext();
    int iData;
};
class FUN_0055a2f0 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    FUN_0055a2f0();
    void* operator new(unsigned int);
};
class MobileObject : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84;
    MobileObject();
    void* operator new(unsigned int);
};
class Character : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C, unk160, unk164,
        unk168, unk16C, unk170, unk174, unk178, unk17C, unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C,
        unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4;
    Character(bool);
    void* operator new(unsigned int);
};
class FUN_008d4500 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C, unk160, unk164,
        unk168, unk16C, unk170, unk174, unk178, unk17C, unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C,
        unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    FUN_008d4500(bool);
    void* operator new(unsigned int);
};
class FUN_009b7a50 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    FUN_009b7a50(bool);
    void* operator new(unsigned int);
};
class FUN_009b3fa0 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150;
    FUN_009b3fa0(bool);
    void* operator new(unsigned int);
};
class FUN_00978fd0 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150;
    FUN_00978fd0(bool);
    void* operator new(unsigned int);
};
class FUN_009b3160 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154;
    FUN_009b3160(bool);
    void* operator new(unsigned int);
};
class FUN_009aaff0 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154;
    FUN_009aaff0(bool);
    void* operator new(unsigned int);
};

extern float DAT_011c3c08;

struct FUN_00857bd0 : public TESSaveLoadGame
{
    void Init(unsigned int value);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct NiControllerManager
{
    void FUN_0047aa40(bool value);
};

struct AnimationInterpolatorNode;
struct Idle_008b2010;
struct Idle_008b2010;
struct NiNode;

struct FUN_00413f40_shell
{
    struct BSFadeNode* FUN_00413f40();
};
struct BSFadeNode
{
    void* FUN_0043b1b0();
};

int __cdecl FUN_00408b20(const char* a, const char* b);
unsigned char __cdecl FUN_004b5c80(NiNode* node);
int __cdecl FUN_00406d30(char* dst, unsigned int size, const char* src);
void* __cdecl memset(void* dst, int val, unsigned int n);

struct xActorValueOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual bool CanBeCommanded();
};

struct xNpcData
{
    bool IsOwnerActive();
};

struct xFormX
{
    bool IsHidden();
    bool IsSecret();
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
    xNpcData m_kData;
};

__if_not_exists(TESForm::TESForm)
{
    class TESForm
    {
      public:
        virtual ~TESForm();
    };
}
__if_not_exists(TESBoundObject::TESBoundObject)
{
    class TESBoundObject : public TESForm
    {
      public:
        unsigned int ID();
    };
}

__if_not_exists(TESCreature::TESCreature)
{
    class TESCreature : public TESBoundObject
    {
      public:
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
        xActorValueOwner m_kAVOwner;
    };
}

struct xCell
{
    xFormX* GetOwner();
    bool IsInterior();
    unsigned char IsPublic();
    bool IsOwnedBy(void* pkActor);
};

struct xExtraOwner
{
    xCell* GetContainingCell();
};

struct xLock
{
    bool IsLocked();
};

struct xPlayerX;

struct xRefr
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
    virtual bool IsInCombat(int i);
    xLock* GetLockX();
    TESBoundObject* GetBaseX();
    bool CanBeUsedX(xPlayerX* pkActor, bool b);
    void* GetOwnerX();
    xExtraOwner* GetExtraOwner();
    bool FUN_00579690();
};

struct xPlayerX : xRefr
{
    bool IsSneakingX();
};

namespace fnv_0055f780 {
struct NiPoint3
{
    float x, y, z;
};

struct M3
{
    float m[9];
    M3();
};

struct UpdData
{
    int u0, u1, u2;
    void NiUpdateData(float, bool, bool);
};

struct NiNode
{
    void FUN_00440460(const NiPoint3&);
    void FUN_0043fa80(void*);
    void Update(const UpdData&);
};

struct TESContainer
{
};

struct InventoryChanges
{
    static InventoryChanges* GetOrAddInventoryChanges(TESObjectREFR*);
    void FUN_004d1960();
};

struct ExtraDataList
{
    void FUN_00426720(unsigned int, unsigned int, TESObjectREFR*);
};

TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);
void FUN_00c69f50(NiNode*, int, int);

}  // namespace fnv_0055f780

class NiAVObject_564a00;

class ShadowSceneNode_564a00
{
  public:
    void CallItemMethodByKey(NiAVObject_564a00* pkObject, bool bValue);
};

namespace RefrShadow_564a00 {
extern "C" ShadowSceneNode_564a00* FUN_00450b80(int iIndex);
}

namespace fnv_0088db20 {
class TESForm;
struct EqTypeDescriptor;
extern EqTypeDescriptor DAT_01183028;
extern "C" void* __cdecl FUN_00ec43fb(void* object, long displacement, const EqTypeDescriptor* sourceType,
                                      const EqTypeDescriptor* targetType, int isReference);

class EqExtraList
{
  public:
    bool FUN_00418b10();
    bool CheckExtraByType(int iFlag);
};
struct EqExtraNode
{
    EqExtraList** FUN_006815c0();
};
class EqEntry
{
  public:
    EqExtraNode* FUN_00559450();
    TESForm* FUN_0044ddc0();
    ~EqEntry();
};
struct EqEntryList
{
    EqEntry* FUN_004c8c10(int iSlot, int iFlag);
};
struct EqRefraction;
struct EqExtraData
{
    EqEntryList* FUN_00418520();
    EqRefraction* GetRefractionProperty();
};

class EqBiped
{
  public:
    TESForm* FUN_0088e0f0(int iSlot);
    void FUN_004aaff0(int iSlot, bool bA, int iB);
};

class EqActorView;
class EqProcess
{
  public:
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
    virtual EqEntry* GetLoadedForm();
    virtual EqEntry* GetAmmo();
    virtual void v0x54();
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
    virtual void v0fe();
    virtual void v0ff();
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
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void Unk_458(EqActorView* pkActor, int iValue);
};

class EqChanges
{
  public:
    void AddItemToInventory(TESForm* pkItem, int iCount, EqActorView* pkActor, EqExtraList* pkExtra, bool bA, bool bLock);
};
EqChanges* FUN_004bf220(EqActorView* pkActor);
struct EqSaveLoad
{
    bool FUN_0047c850();
};
extern EqSaveLoad* DAT_011de45c;
struct EqRefraction
{
    int unk00;
    int unk04;
    int unk08;
    float m_fValue;
};
class EqNPCHelper
{
  public:
    bool FUN_006061b0(EqActorView* pkActor, EqBiped* pkBiped, TESForm* pkItem);
};

class EqActorView
{
  public:
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
    virtual EqBiped* GetBipedAnim();
    virtual void v0x7b();
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
    virtual bool Unk_218();
    virtual void v0x87();
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
    virtual void Unk_384(int iA, float fB);
    virtual void v0xe2();
    virtual void v0e3();
    virtual int Unk_390();
    virtual void v0xe5();
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
    virtual void Unk_3ec(TESForm* pkItem, int iA, bool bB, int iC);
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
    EqProcess* m_pkProcess;  // +0x68

    EqBiped* FUN_00950b00(int iValue);
    EqExtraData* FUN_005d43c0();
    bool FUN_0088d7d0(TESForm* pkItem, int iCount, EqExtraList* pkExtra, bool bA, bool bB, bool bC);
    void FUN_008b0b00(int iValue);
    EqNPCHelper* FUN_007af430();
    bool FUN_008c51c0();
    bool FUN_0088db20(TESForm* pkItem, int iCount, EqExtraList* pkExtra, bool bLock);
};
extern EqActorView* DAT_011dea3c;

}  // namespace fnv_0088db20

namespace fnv_005790f0 {
class TESFormSlots
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
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
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
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
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
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
    virtual void Slot3A();
    virtual void Slot3B();
    virtual unsigned char Slot3C();
};

struct ExtraDataList;

struct ExtraSayToTopicInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char byte18;
};

struct FUN_0042ede0_shell
{
    ExtraSayToTopicInfo* __thiscall FUN_0042ede0();
};

TESFormSlots* __cdecl FUN_004839c0(unsigned int index);
ExtraDataList* __fastcall FUN_005d43c0(TESObjectREFR* refr);

}  // namespace fnv_005790f0

struct SaveOrderTypeDescriptor;
extern SaveOrderTypeDescriptor DAT_01183028;
extern SaveOrderTypeDescriptor DAT_011841cc;
class SaveOrderCell;
class SaveOrderForm
{
  public:
    virtual ~SaveOrderForm();
};
class SaveOrderCell : public SaveOrderForm
{
  public:
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
    virtual void v34();
    virtual void v38();
    virtual bool v3c(SaveOrderForm* p);
};

namespace fnv_0055d230 {
class TESForm;
struct EqTypeDescriptor;
extern EqTypeDescriptor DAT_01183028;
extern EqTypeDescriptor DAT_011841cc;
extern "C" void* __cdecl FUN_00ec43fb(void*, long, const EqTypeDescriptor*, const EqTypeDescriptor*, int);

}  // namespace fnv_0055d230

struct Sky;
struct TESWorldSpace;
struct TESContainer;

TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);

class TESForm;

struct ExtraRadioData;

struct RefH
{
    bool FUN_00568680();
};
TESForm* __fastcall FNV_GetObjectReference(TESObjectREFR*);
int __fastcall FNV_GetFormType(TESForm*);

struct DoorCell
{
    TESForm* GetOwner();
};

class TESBoundObject;
__if_not_exists(TESBoundObject::~TESBoundObject)
{
    class TESBoundObject
    {
      public:
        virtual ~TESBoundObject();
    };
}
struct TESHealthForm;
__if_not_exists(TESHealthForm::~TESHealthForm)
{
    struct TESHealthForm
    {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual unsigned int GetHealth();
    };
}
struct HealthExtraList
{
    void* FUN_00410220(unsigned char);
};
struct HealthReferenceEntry;
void* __fastcall FUN_007af430(HealthReferenceEntry*);
struct HealthReferenceEntry
{
    HealthExtraList* FUN_005d43c0();
    float FUN_00568ad0();
};

struct TESContainer;

TESContainer* __fastcall FUN_0055d310(TESObjectREFR* refr);

namespace fnv_00574fa0 {

void* __cdecl FUN_004826d0(TESBoundObject*);

namespace AddBoundItemData {
extern TESObjectREFR* DAT_011dea3c;
}

struct RefH
{
    bool GetDisabled();
};

enum CHALLENGE_TYPE
{
};

struct ChallengeManager
{
    static bool UpdateChallengeProgress(CHALLENGE_TYPE, int, TESBoundObject*, TESForm*, unsigned short, unsigned short,
                                        unsigned short);
};

struct SC_008c48d0
{
    static bool GetLocalData(void*, ExtraDataList*, unsigned int);
};

}  // namespace fnv_00574fa0

enum CHALLENGE_TYPE
{
};

struct ChallengeManager
{
    static bool __cdecl UpdateChallengeProgress(CHALLENGE_TYPE type, int value, TESForm* form1, TESForm* form2,
                                                unsigned short value1, unsigned short value2, unsigned short value3);
};

struct SC_008c48d0
{
    static bool __cdecl GetLocalData(void* object, ExtraDataList* extra, unsigned int flag);
};

TESObjectREFR* _g_thePlayer;

struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList_SV;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESGlobal;
struct TESImageSpace;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESFormList;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct FileEntryList;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;

struct NP
{
    NP& operator=(void*);
};

struct Helper_0061f890
{
    void FUN_0061f890(void* ref, int arg);
};

struct Proc_S
{
    Helper_0061f890* GetNext();
};

struct ExtraDataList_SV
{
    Proc_S* GetRoomId();
};

struct TESObjectSTAT;

struct ReferenceFloatEntry
{
    void Endian();
    TESObjectREFR* m_pFourthReference;
    float m_fDelay;
};

template <typename T> struct BSSimpleList;

struct TESObjectACTI;

extern double _gModifierZero;
extern TESObjectACTI* DAT_011ca27c;
extern TESObjectACTI* DAT_011ca280;

bool __fastcall _ref_008256d0(void*);

struct OwnershipTypeDescriptor;
extern "C" void* __cdecl FUN_00ec43fb(void*, long, const OwnershipTypeDescriptor*, const OwnershipTypeDescriptor*, int);
struct TESGlobal
{
    float GetValue();
};
