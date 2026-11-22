// TESForm: the base of every record in a plugin file.
// Names: FNV360_PDB (TESForm, 0822 retail; members from its fields, virtuals from its vtable). Vtable: 78 slots,
// checked against F3_EXE's TESForm vtable 0x00dbd194 (78 slots); every linked non-stub slot agrees.
// VC8 lays overloaded virtuals out in reverse declaration order: each overload pair is declared last slot first.
#ifndef FNV_TESFORM_H
#define FNV_TESFORM_H
#include "layout_support.h"
#include "BaseFormComponent.h"
class BGSLoadFormBuffer;
template <class K, class V> class NiTPointerMap;
class BGSSaveFormBuffer;
class NiColor;
class TESBoundObject;
class TESFile;
class TESObjectREFR;
struct FORM;
struct FORM_GROUP;
#pragma pack(push, 4)
class TESForm : public BaseFormComponent
{
  public:
    unsigned char cFormType;               // +0x4, ENUM_FORM_ID
    unsigned int iFormFlags;               // +0x8
    unsigned int iFormID;                  // +0xC
    BSSimpleList<TESFile*> pSourceFiles;   // +0x10, the files that define or override the form

    // BaseFormComponent
    virtual void InitializeDataComponent();                                                  // 0
    virtual void ClearDataComponent();                                                       // 1
    virtual void CopyComponent(BaseFormComponent* apCopyFC);                                 // 2
    virtual bool CompareComponent(BaseFormComponent* apCompareFC);                           // 3
    // TESForm
    virtual ~TESForm();                                                                    // 4
    virtual void InitializeData();                                                         // 5
    virtual void ClearData();                                                              // 6
    virtual bool ProcessBeforeSave();                                                      // 7
    virtual bool Load(TESFile* apFile);                                                    // 8
    virtual bool LoadPartial(TESFile* apFile);                                             // 9
    virtual void Save();                                                                   // 11
    virtual bool Save(TESFile* apFile);                                                    // 10
    virtual bool LoadEdit(TESFile* apFile);                                                // 12
    virtual bool SaveEdit(TESFile* apFile);                                                // 13
    virtual bool SavesBefore(TESForm* apForm);                                             // 15
    virtual bool SavesBefore(FORM* apGroupFORM);                                           // 14
    virtual TESForm* CreateDuplicateForm(bool abCreateEditorID, NiTPointerMap<TESForm*,TESForm*>* apCopyMap); // 16
    virtual void PostDuplicateProcess(NiTPointerMap<TESForm*,TESForm*>* apCopyMap);        // 17
    virtual void AddChange(int aiChangeFlags);                                             // 18
    virtual void RemoveChange(int aiChangeFlags);                                          // 19
    virtual unsigned short GetSaveSize(unsigned int aiFlags);                              // 20
    virtual void SaveGame(unsigned int aiFlags);                                           // 22
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);                            // 21
    virtual void LoadGame(unsigned int aiFlags, unsigned int aiCurrentFlags);              // 24
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);                            // 23
    virtual void InitLoadGame(unsigned int, unsigned int);                                 // 26
    virtual void InitLoadGame(BGSLoadFormBuffer*);                                         // 25
    virtual void FinishInitLoadGame(unsigned int aiFlags, unsigned int aiOldFlags);        // 27
    virtual void Revert(unsigned int);                                                     // 29
    virtual void Revert(BGSLoadFormBuffer*);                                               // 28
    virtual void LoadQueuedFormData(unsigned short aiSize);                                // 30
    virtual bool FindInFileFast(TESFile* apFile);                                          // 31
    virtual void CheckSaveGame(BGSSaveFormBuffer* apSaveGameBuffer);                       // 32
    virtual void FinishLoadGame(BGSLoadFormBuffer* apLoadGameBuffer);                      // 33
    virtual void InitItem();                                                               // 34
    virtual ENUM_FORM_ID GetSavedFormType();                                               // 35
    virtual void GetFormDetailedString(BSStringT<char>& aString);                          // 36
    virtual bool GetQuestObject() const;                                                   // 37
    virtual bool GetHasSpokenFlag() const;                                                 // 38
    virtual bool GetHavokDeath() const;                                                    // 39
    virtual bool GetRandomAnim() const;                                                    // 40
    virtual bool GetNeedtoChangeProcess() const;                                           // 41
    virtual bool GetDangerous() const;                                                     // 42
    virtual bool GetHasPLSpecTex() const;                                                  // 43
    virtual bool GetObstacle() const;                                                      // 44
    virtual bool GetContinuousBroadcast() const;                                           // 45
    virtual bool GetOnLocalMap();                                                          // 46
    virtual void SetOnLocalMap(bool abVal);                                                // 47
    virtual NiColor* GetEmittanceColor();                                                  // 48
    virtual void SetDelete(bool abDeleted);                                                // 49
    virtual void SetAltered(bool abAltered);                                               // 50
    virtual void SetQuestObject(bool abQuest);                                             // 51
    virtual void SetHasSpokenFlag(bool abSpoke);                                           // 52
    virtual void SetHavokDeath(bool abDeath);                                              // 53
    virtual void SetNeedToChangeProcess(bool abChange);                                    // 54
    virtual void SaveObjectBound();                                                        // 55
    virtual void LoadObjectBound(TESFile* apFile);                                         // 56
    virtual bool IsBoundObject();                                                          // 57
    virtual bool IsObject();                                                               // 58
    virtual bool IsMagicItem();                                                            // 59
    virtual bool IsReference();                                                            // 60
    virtual bool IsArmorAddon();                                                           // 61
    virtual bool IsActorBase();                                                            // 62
    virtual bool IsMobileObject();                                                         // 63
    virtual bool IsActor();                                                                // 64
    virtual unsigned int GetRefCount();                                                    // 65
    virtual void Copy(TESForm* apCopy);                                                    // 66
    virtual bool Compare(TESForm* apCopy);                                                 // 67
    virtual bool BelongsInGroup(FORM* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly); // 68
    virtual void CreateGroupData(FORM* apOutGroupFORM, FORM_GROUP* apParentGroup);         // 69
    virtual bool IsParentForm();                                                           // 70
    virtual bool IsParentFormTree();                                                       // 71
    virtual bool IsFormTypeChild(unsigned char aeType);                                    // 72
    virtual bool Activate(TESObjectREFR* apItemActivated, TESObjectREFR* apActionRef, bool abIdFlag, TESBoundObject* apObjectToGet, int aiCount); // 73
    virtual void SetFormID(unsigned int aiID, bool abUpdateFile);                          // 74
    virtual char* GetObjectTypeName();                                                     // 75
    virtual const char* GetFormEditorID();                                                 // 76
    virtual bool SetFormEditorID(const char* apEditorID);                                  // 77

    TESForm();
    TESFile* GetFile(int fileIndex);
    BSSimpleList<TESFile*>* GetSourceFiles();
    bool IsDeleted() const;
    unsigned int GetFormID();
    bool IsTemporary() const;
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
    bool GetDeleted() const;
    bool GetDisabled() const;
    bool IsStillLoading() const;
    static TESForm* GetFormByID(unsigned int formID);
    bool IsFormInitialized() const;
    bool GetInitialized() const;
    unsigned int GetDataSizeAdjustment();
    void ReadTypedData(TESFile* file, void* data, unsigned short size);
    void SetFormType(ENUM_FORM_ID type);
    void LoadRecordHeader(TESFile* file);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESForm) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESForm, cFormType) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESForm, iFormFlags) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESForm, iFormID) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESForm, pSourceFiles) == 0x10);
#endif
