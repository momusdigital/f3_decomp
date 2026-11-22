// fallout/ai/baseprocess.cpp: BaseProcess, SavedProcess, Target8d (1 function)
#include "f3_common.h"
#include "baseprocess_worker.h"

static const int kCalculateMoveModeValue1 = 257;

class TESSound
{
  public:
    unsigned int Deallocate(void);
};

struct MobileObject;
struct TESIdleForm;

struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BSExtraData;
struct BSFile;
struct SoundPlaybackHandle;
struct BipedAnim;
struct CombatGroupCollection;
struct ChangeData;
struct ChangesMap;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct CellReferenceChangeData;
struct DialogueResponse;
struct ExteriorCellNewReferencesMap;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct CellChangesMap;
struct InteriorCellNewReferencesMap;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct FormRecordMetadata;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicTarget;
struct MobileObject;
struct WorldReferenceObject;
struct NiControllerSequence;
struct NiFixedString;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiTexture;
struct NumericIDBufferMap;
struct PlacedObjectInfo;
struct PathingLocation;
struct SaveGameRecord;
struct FormIDEntry;
struct SaveGameFile;
struct EmptyClass;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESObject;
struct TESObjectREFR;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct _FILETIME;
struct _SYSTEMTIME;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct blob12
{
    char b[12];
};
struct TESSaveLoadGame
{
    void NotifyFormIDChanged(TESForm*, unsigned int);
    void SetFormFlags(TESForm*, unsigned int);
    void ClearFormChangeFlags(TESForm*, unsigned int);
    void HasFormChanges(TESForm*, bool);
    unsigned int GetChangeFlags(TESForm*, bool);
    void AllowChanges(bool);
    bool GetAllowChanges();
    unsigned int GetFileSize();
    bool SaveGame(BSFile*, char*, bool);
    bool LoadGame(BSFile*, char*, bool);
    void SaveGameHeader(BSFile*);
    void SaveGameHeader(BSFile*, char*);
    void ConvertArrayByteOrder(double*, unsigned int);
    void ConvertArrayByteOrder(NiPoint3*, unsigned int);
    void ConvertArrayByteOrder(float*, unsigned int);
    void ConvertArrayByteOrder(unsigned long*, unsigned int);
    void ConvertArrayByteOrder(long*, unsigned int);
    void ConvertArrayByteOrder(unsigned int*, unsigned int);
    void ConvertArrayByteOrder(int*, unsigned int);
    void ConvertArrayByteOrder(unsigned short*, unsigned int);
    void ConvertArrayByteOrder(short*, unsigned int);
    void ConvertArrayByteOrder(void*, unsigned int);
    void ConvertTypedArrayByteOrder(double*, unsigned int);
    void ConvertTypedArrayByteOrder(NiPoint3*, unsigned int);
    void ConvertTypedArrayByteOrder(float*, unsigned int);
    void ConvertTypedArrayByteOrder(unsigned long*, unsigned int);
    void ConvertTypedArrayByteOrder(long*, unsigned int);
    void ConvertTypedArrayByteOrder(unsigned int*, unsigned int);
    void ConvertTypedArrayByteOrder(int*, unsigned int);
    void ConvertTypedArrayByteOrder(unsigned short*, unsigned int);
    void ConvertTypedArrayByteOrder(short*, unsigned int);
    void ConvertTypedArrayByteOrder(void*, unsigned int);
    void SwapUnsignedIntByteOrder(unsigned int*, unsigned int);
    bool ValidateFormIDArray(unsigned int*, unsigned int);
    unsigned short GetFileNameSaveSize(char*);
    void SaveFileName(char*);
    char* ReadFileName(char*);
    unsigned int EndianConvert(unsigned int);
    int EndianConvert(int);
    unsigned short EndianConvert(unsigned short);
    short EndianConvert(short);
    unsigned char EndianConvert(unsigned char);
    char EndianConvert(char);
    void LoadDataBlock(void*, unsigned int, unsigned int);
    void SaveDataBlock(void*, unsigned int, unsigned int);
    void WriteFile(BSFile*, NiPoint3*, unsigned int);
    void WriteFile(BSFile*, float*, unsigned int);
    void WriteFile(BSFile*, unsigned long*, unsigned int);
    void WriteFile(BSFile*, long*, unsigned int);
    void WriteFile(BSFile*, unsigned int*, unsigned int);
    void WriteFile(BSFile*, int*, unsigned int);
    void WriteFile(BSFile*, unsigned short*, unsigned int);
    void WriteFile(BSFile*, short*, unsigned int);
    unsigned int WriteFile(BSFile*, void*, unsigned int);
    void ReadFile(BSFile*, NiPoint3*, unsigned int);
    void ReadFile(BSFile*, float*, unsigned int);
    void ReadFile(BSFile*, unsigned long*, unsigned int);
    void ReadFile(BSFile*, long*, unsigned int);
    void ReadFile(BSFile*, unsigned int*, unsigned int);
    void ReadFile(BSFile*, int*, unsigned int);
    void ReadFile(BSFile*, unsigned short*, unsigned int);
    void ReadFile(BSFile*, short*, unsigned int);
    unsigned int ReadFile(BSFile*, void*, unsigned int);
    void WriteFileEndian(BSFile*, void*, unsigned int, unsigned int);
    void ReadFileEndian(BSFile*, void*, unsigned int, unsigned int);
    void AdvanceBuffer(unsigned int);
    bool GetLoading();
    bool GetIniting();
    bool GetConstructingObject();
    bool GetInitObject();
    bool GetPositioning();
    bool GetTemporarilyMovingRef();
    bool GetRevertingCurrentChanges();
    bool GetLoadingTempRefs();
    bool GetDeferInitForms();
    bool GetSimulatedMode();
    bool GetSkyLoading();
    bool GetSaveGameLoading();
    bool GetReconstructingObjects();
    bool GetFadingInFromSaveGame();
    bool GetLoadingGlobalData();
    bool GetAutosaveWhenFadedIn();
    bool GetBusy();
    bool GetLoadingCreatedBaseObjects();
    bool GetPositioningPlayerCharacter();
    void SetLoading(bool);
    void SetIniting(bool);
    void SetConstructingObject(bool);
    void SetInitObject(bool);
    void SetPositioning(bool);
    void SetTemporarilyMovingRef(bool);
    void SetRevertingCurrentChanges(bool);
    void SetLoadingTempRefs(bool);
    void SetDeferInitForms(bool);
    void SetSimulatedMode(bool);
    void SetSkyLoading(bool);
    void SetSaveGameLoading(bool);
    void SetReconstructingObjects(bool);
    void SetFadingInFromSaveGame(bool);
    void SetLoadingGlobalData(bool);
    void SetAutosaveWhenFadedIn(bool);
    void SetBusy(bool);
    void SetLoadingCreatedBaseObjects(bool);
    void SetPositioningPlayerCharacter(bool);
    void* GetBufferPointer();
    void SetBufferPointer(void*);
    bool LoadForm(TESForm*);
    bool SetFormLoaded(TESForm*);
    bool FormReconstructionMap(TESObjectCELL*);
    void LoadCellChanges(void*, CellChangesMap*, bool);
    TESPackage* CreatePackageForType(unsigned int, unsigned char);
    void ClearFormID(unsigned int);
    bool HasReferenceMoved(TESObjectCELL*, TESObjectREFR*, unsigned int);
    bool GetRevertBefore();
    bool GetRevertAfter();
    unsigned int ComputeArmorHash(Actor*);
    unsigned int ConvertNumericID(unsigned int);
    unsigned int ReverseConvertNumericID(unsigned int);
    void SerializeFormToBuffer(char*, TESForm*, unsigned int, unsigned char, bool);
    static void DrawDebugText(TESObjectREFR*, int, int*, int*);
    void QueueRemoveChange(unsigned int);
    void QueueRemoveReferenceChange(TESObjectREFR*, unsigned short);
    void QueueAttachedAnimationLoad(TESObjectREFR*, unsigned short);
    void QueueCharControllerLoad(TESObjectREFR*, unsigned short);
    void QueueHavokDataLoad(TESObjectREFR*, unsigned short);
    void Autosave();
    void Autoload();
    void Quicksave();
    bool Quickload();
    void GetSaveGameDisplayData(BSFile*, unsigned int*, char*, char*, char*);
    NiTexture* GetSaveGameDataOLD(BSFile*, unsigned int*, char*, char*, char*, char*, char*, char*, int*, bool);
    NiTexture* GetSaveGameData(BSFile*, unsigned int, unsigned int*, char*, unsigned short*, char*, float*,
                               _SYSTEMTIME*, unsigned int*, int*);
    void ReadSaveGameMetadata(BSFile*, unsigned int*, char*, char*, _FILETIME*, char*);
    void GenerateSaveGameDataOLD(char*, char*, char*);
    void* GetSaveGameList();
    void BuildSaveGameList();
    void DeleteSaveGameList();
    void LoadQueuedData(bool);
    bool IsFormIDInChangesMap(unsigned int);
    unsigned int GetMappedFormID(unsigned int, int, int);
    bool HasQueuedChanges();
    void RegisterCreatedBaseObject(TESForm*);
    void RemoveCreatedBaseObject(unsigned int);
    void RemoveCreatedBaseObject(TESForm*);
    unsigned int GetFormIDFromArray(unsigned int);
    unsigned int GetNumericIDFromArray(unsigned int);
    unsigned short AddWorldSpaceIDToArray(unsigned int);
    unsigned int GetWorldSpaceIDFromArray(unsigned short);
    void UpdateLoadingSequence();
    unsigned int PurgeSavedDataForCell(TESObjectCELL*);
    unsigned int PurgeSavedDataForWorld(TESWorldSpace*);
    unsigned int PurgeSavedDataForLocation(unsigned int, bool);
    bool GetInitArrayExists();
    unsigned char GetCurrentVersion();
    void SetCurrentVersion(unsigned char);
    void ResetVersions();
    void ResetCurrentVersion();
    void TestAllCells(unsigned int);
    void SaveQueuedHavokData(TESObjectREFR*);
    void SaveQueuedAttachedAnimation(TESObjectREFR*);
    void ApplyFormChanges(bool);
    void RevertForm(TESForm*, ChangeData*);
    void PerformDeferredDeletions();
    void PerformDeferredInitActorPackages();
    void RevertGlobalData();
    void SetUseNumericIDArray(bool);
    bool GetUseNumericIDArray();
    bool DynamicCastByRTTI();
    void QueueFormForFinalization(TESForm*);
    void FinalizeQueuedForms();
    void FinalizeForm(TESForm*);
    FormRecordMetadata* GetCurrentlyLoadingFormHeader();
    FormIDEntry* GetCurrentlySavingFormHeader();
    void* CreateQueuedBuffer(unsigned short);
    void SafetyCheckReferencePositionAndAngle(TESObjectREFR*);
    bool IsInvalidPoint(NiPoint3*);
    _FILETIME* GetMostRecentSaveGame();
    void DeleteForm(TESForm*);
    void AddFormToInitFormArray(TESForm*);
    unsigned int GetNeedToConvertPCSaveGames();
    bool ConvertPCSaveGames();
    void RemoveFormFromInitFormArray(TESForm*);
    void CleanUpExpiredData();
    void TestSaveCreatedBaseObjects();
    void ClearNextSaveNumber();
    void AddInitItem(TESForm*);
    bool GetReconstructedAllObjects();
    void CleanupMaps();
    ChangeData* GetChanges(TESForm*);
    unsigned int ContainsAnyFlags(TESForm*, unsigned int);
    void LoadAnimationForReference(TESObjectREFR*, unsigned int, void*);
    void LoadAttachedAnimationForReference(TESObjectREFR*, void*);
    void LoadHavokDataForReference(TESObjectREFR*, void*);
    unsigned short GetQueuedBufferSaveSize(void*);
    BSFile* PrepForLoadSave(BSFile*, char*, int);
    void CleanupLoadSave(BSFile*, int);
    unsigned int LoadHeader(BSFile*, bool);
    void SaveHeader(BSFile*, char*);
    void SaveGlobalData(BSFile*);
    void LoadGlobalData(BSFile*);
    void SerializeChangeData(BSFile*);
    void LoadChangeData(BSFile*);
    void FreeChangeData(void*);
    void WriteCreatedBaseObjects(BSFile*);
    void LoadCreatedBaseObjects(BSFile*);
    void DeleteCreatedBaseObjects();
    void PrepareLoadGame(BSFile*);
    bool IsValidSaveGame(BSFile*);
    void LoadChangeFormData(BSFile*);
    void LoadNumericIDArrays(BSFile*);
    void LoadFormRecords(BSFile*);
    void LoadFinalData(BSFile*);
    void LoadAnimations();
    void LoadAttachedAnimations();
    void LoadCharControllers();
    void LoadHavokData();
    void QueueBufferLoad(NumericIDBufferMap*, unsigned int, unsigned short);
    void CleanupCurrentGameState();
    void StartLoadingSequence();
    void EndLoadingSequence();
    unsigned int GetOrCreateFormID(TESForm*, unsigned int);
    void CreateChangedReference(unsigned int);
    TESForm* CreateReference(unsigned int, CellReferenceChangeData*);
    TESForm* CreateReferenceFromFile(unsigned int, WorldReferenceObject*);
    unsigned short AddFormIDToArray(TESForm*, unsigned int);
    void LoadInitialDataForForm(TESForm*, unsigned int);
    void AddFormToChangesMap(TESForm*, unsigned int);
    void* CreateBuffer(unsigned int);
    void SaveBuffer(BSFile*, void*, unsigned int);
    void LoadBuffer(BSFile*, void*, unsigned int);
    void DisposeBuffer(void*);
    void FinishLoad();
    bool ResetReferencePosition(TESObjectREFR*, bool);
    int ResetObject(TESForm*, unsigned int, unsigned int);
    bool InitObject(TESForm*, unsigned int, bool);
    void SetRevertState(int);
    static int SaveGameCompare(SaveGameFile*, SaveGameFile*);
    void GenerateSaveGameFileName(char*);
    void StripIllegalCharacters(char*);
    SaveGameRecord* GetRevertStateInfo(TESForm*);
    void ProcessRevertStateInfo(TESForm*, SaveGameRecord*);
    void SetCurrentlyLoadingFormHeader(FormRecordMetadata*);
    void SetCurrentlySavingFormHeader(FormIDEntry*);
    void ReInitForcedChanges(TESForm*, unsigned int);
    void SaveMostRecentSaveGame(BSFile*);
    void LoadMostRecentSaveGame();
    unsigned int CalculateNextSaveNumber();
    unsigned int GetNextSaveNumber();
    void SetReconstructedAllObjects(bool);
    void ReconstructAllObjects();
    bool CheckShouldReconstructAllObjects(struct blob12, TESObjectCELL*, TESWorldSpace*);
    void DisplayCorruptSaveGameMessage(BSFile*);
    void* __vecDelDtor(unsigned int);
    ChangesMap* m_pChangesMap;
    ChangesMap* m_pAlternateChangesMap;
    InteriorCellNewReferencesMap* m_pInteriorCellNewReferencesMap;
    ExteriorCellNewReferencesMap* m_pExteriorCellNewReferencesMap1;
    ExteriorCellNewReferencesMap* m_pExteriorCellNewReferencesMap2;
    void* m_pBuffer;
    unsigned int m_uiBufferSize;
    bool m_bLoading;
    char _pad_1d[3];
    void* m_pSaveGameFile;
    char m_acBuffer1[8];
    char m_acBuffer2[8];
    char m_acBuffer3[8];
    char m_acBuffer4[8];
    EmptyClass* m_pSaveGameEntry;
    int m_iEntryCount;
    unsigned char m_ucSaveVersion;
    char _pad_4d[3];
    unsigned char* m_pNumericIDBuffer;
    unsigned int m_uiDataBufferSize;
    NumericIDBufferMap* m_pNumericIDBufferMap1;
    NumericIDBufferMap* m_pNumericIDBufferMap2;
    NumericIDBufferMap* m_pNumericIDBufferMap3;
    NumericIDBufferMap* m_pNumericIDBufferMap4;
    char m_acNumericIDData[8];
    void* m_pNumericIDBufferData;
    unsigned char m_ucSaveFlags;
    unsigned char m_ucLoadFlags;
    char _pad_76[2];
    void* m_pLoadingFormRecordHeader;
    void* m_pSavingFormIDEntry;
    unsigned char m_ucCurrentFormRecordType;
    bool m_bCurrentFormHeaderActive;
    char _pad_82[2];
    FormRecordMetadata* m_pCurrentLoadingFormHeader;
    FormIDEntry* m_pCurrentSavingFormHeader;
    unsigned int m_uiNextFormID;
    unsigned int m_uiSaveNumber;
    unsigned int m_uiFormRecordCount;
    char m_acSaveGameSignature[16];
    unsigned int m_uiCurrentFormRecordCount;
    bool m_bSaveGameLoaded;
    bool m_bSaveGameCorrupt;
    bool m_bHasPendingChanges;
    bool m_bNeedsReferenceReconstruction;
    void* m_pSaveGameListData;
    char m_acSaveGamePath[272];
    _FILETIME* m_pMostRecentSaveTime;
};
typedef char _sizecheck_TESSaveLoadGame[sizeof(TESSaveLoadGame) == 456 ? 1 : -1];
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

extern const NiPoint3 _NiPoint3_ZERO;

namespace fnv_008d02a0 {
struct NiPoint3
{
    float x, y, z;
};
extern const NiPoint3 _NiPoint3_ZERO;
struct Actor;
}  // namespace fnv_008d02a0

namespace fnv_008d0310 {
struct NiPoint3
{
    float x, y, z;
};
extern const NiPoint3 _NiPoint3_ZERO;
struct Actor;
}  // namespace fnv_008d0310

struct FUN_008d04d0_s
{
    void FUN_008d04d0();
};
// @f3 0x0050a730 (community match, verified in this file)
struct GlobalObject_0045cfe0
{
    ~GlobalObject_0045cfe0();
    void* p;
};

struct FUN_008d04d0_self
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    GlobalObject_0045cfe0 go18;
    int unk1C;
    int unk20;
};

// pdb: BGSListForm::ClearData | BGSListForm.obj | fnv360_0822_retail, vtable, medium
void FUN_008d04d0_s::FUN_008d04d0()
{
    FUN_008d04d0_self* self = reinterpret_cast<FUN_008d04d0_self*>(this);
    self->go18.~GlobalObject_0045cfe0();
    self->unk20 = 0;
}


struct ActorCombatGroup;

struct SoundPlaybackHandle
{
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    int a;
};

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};

namespace fnv_008d0900 {
struct MobileObject
{
};

struct FormIDEntry
{
    unsigned int iFormID;
    unsigned char pad;
    unsigned char iFlags[4];
};

struct TESForm
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual void v64()
    {}
    virtual void v65()
    {}
    virtual void v66()
    {}
    virtual void v67()
    {}
    virtual void v68()
    {}
    virtual void v69()
    {}
    virtual void v70()
    {}
    virtual void v71()
    {}
    virtual void v72()
    {}
    virtual void v73()
    {}
    virtual void v74()
    {}
    virtual void v75()
    {}

    virtual const char* GetName()
    {
        return 0;
    }
};

struct TESSaveLoadGame
{
    bool FUN_00862110();
    void* GetHitSound();
};

typedef TESSaveLoadGame SaveManager;

extern SaveManager* DAT_011de45c;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

extern GlobalObject_0045cf30 g_011de4e8;

}  // namespace fnv_008d0900

class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
extern const char DAT_010865e0[];
TESForm* __cdecl FUN_004839c0(unsigned int);

namespace fnv_008d0bc0 {
extern "C" char DAT_011de45c;
extern "C" char DAT_010865e0;
struct Object8d
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
    virtual const char* name();
};
Object8d* __cdecl FUN_004839c0(unsigned);
}  // namespace fnv_008d0bc0
