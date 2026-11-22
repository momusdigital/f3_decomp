// TESObjectREFR: a placed instance of a base object in a cell.
// Names: FNV360_PDB (TESObjectREFR, 0822 retail; members from its fields, virtuals from its vtable). Vtable: 144
// slots, checked against F3_EXE's TESObjectREFR vtable 0x00dcee7c (144 slots; every linked non-stub slot agrees);
// TESChildCell's vtable at +0x18 is 0x00dcee70. Overload pairs are declared last slot first, as VC8 lays them out.
#ifndef FNV_TESOBJECTREFR_H
#define FNV_TESOBJECTREFR_H
#include "layout_support.h"
#include "ExtraDataList.h"
#include "PlacedObjectInfo.h"
#include "TESChildCell.h"
#include "TESForm.h"
class Actor;
class ActorCause;
class Animation;
class BGSLoadFormBuffer;
class BSAnimNoteReceiver;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSSoundHandle;
class BipedAnim;
class MagicCaster;
class MagicTarget;
class NiAVObject;
class NiNode;
class NiPoint3;
class TESActorBase;
class TESTopic;
class TESWorldSpace;
class TargetEntry;
class TrapEntry;
#pragma pack(push, 4)
class TESObjectREFR : public TESForm, public TESChildCell
{
  public:
    TESSound* pRandomSound;     // +0x1C
    PlacedObjectInfo data;      // +0x20, OBJ_REFR: base form, angle, location
    float fRefScale;            // +0x3C
    TESObjectCELL* pParentCell; // +0x40
    ExtraDataList m_Extra;      // +0x44
    CellDataNode* pLoadedData;  // +0x64, LOADED_REF_DATA

    // TESForm
    virtual ~TESObjectREFR();                                                              // 4  (TESForm)
    virtual void InitializeData();                                                         // 5  (TESForm)
    virtual void ClearData();                                                              // 6  (TESForm)
    virtual bool Load(TESFile*);                                                           // 8  (TESForm)
    virtual void Save();                                                                   // 11  (TESForm)
    virtual bool SavesBefore(TESForm*);                                                    // 15  (TESForm)
    virtual bool SavesBefore(FORM*);                                                       // 14  (TESForm)
    virtual TESForm* CreateDuplicateForm(bool, NiTPointerMap<TESForm*,TESForm*>*);         // 16  (TESForm)
    virtual void PostDuplicateProcess(NiTPointerMap<TESForm*,TESForm*>*);                  // 17  (TESForm)
    virtual unsigned short GetSaveSize(unsigned int);                                      // 20  (TESForm)
    virtual void SaveGame(unsigned int);                                                   // 22  (TESForm)
    virtual void SaveGame(BGSSaveFormBuffer*);                                             // 21  (TESForm)
    virtual void LoadGame(unsigned int, unsigned int);                                     // 24  (TESForm)
    virtual void LoadGame(BGSLoadFormBuffer*);                                             // 23  (TESForm)
    virtual void InitLoadGame(unsigned int, unsigned int);                                 // 26  (TESForm)
    virtual void InitLoadGame(BGSLoadFormBuffer*);                                         // 25  (TESForm)
    virtual void FinishInitLoadGame(unsigned int, unsigned int);                           // 27  (TESForm)
    virtual void Revert(unsigned int);                                                     // 29  (TESForm)
    virtual void Revert(BGSLoadFormBuffer*);                                               // 28  (TESForm)
    virtual void CheckSaveGame(BGSSaveFormBuffer*);                                        // 32  (TESForm)
    virtual void FinishLoadGame(BGSLoadFormBuffer*);                                       // 33  (TESForm)
    virtual void InitItem();                                                               // 34  (TESForm)
    virtual ENUM_FORM_ID GetSavedFormType();                                               // 35  (TESForm)
    virtual void GetFormDetailedString(BSStringT<char>&);                                  // 36  (TESForm)
    virtual bool GetOnLocalMap();                                                          // 46  (TESForm)
    virtual void SetOnLocalMap(bool);                                                      // 47  (TESForm)
    virtual void SetDelete(bool);                                                          // 49  (TESForm)
    virtual void SetAltered(bool);                                                         // 50  (TESForm)
    virtual void SetQuestObject(bool);                                                     // 51  (TESForm)
    virtual bool IsReference();                                                            // 60  (TESForm)
    virtual void Copy(TESForm*);                                                           // 66  (TESForm)
    virtual bool Compare(TESForm*);                                                        // 67  (TESForm)
    virtual bool BelongsInGroup(FORM*, bool, bool);                                        // 68  (TESForm)
    virtual void CreateGroupData(FORM*, FORM_GROUP*);                                      // 69  (TESForm)
    virtual const char* GetFormEditorID();                                                 // 76  (TESForm)
    // TESChildCell
    virtual TESObjectCELL* GetSaveParentCell();
    // TESObjectREFR
    virtual bool GetEditorLocation(NiPoint3& arOriginalLocation, NiPoint3& arOriginalAngle, TESForm*& arpLocationForm, TESForm* apLocationForm); // 78
    virtual BSSoundHandle VoiceSoundFunction(TESTopic* apTopic, Actor* apTarget, bool abPlayerhead, bool abAlwaysPlay, bool abForceCorrectDuration, bool abSayTo); // 79
    virtual void UpdateSoundCallBack();                                                    // 80
    virtual void DamageObject(float afDamage, bool abSelfDamage);                          // 81
    virtual bool GetCastShadows();                                                         // 82
    virtual void SetCastShadows(bool abVal);                                               // 83
    virtual bool GetMotionBlur();                                                          // 84
    virtual void SetMotionBlur(bool abVal);                                                // 85
    virtual bool GetDangerous();                                                           // 86
    virtual bool GetObstacle();                                                            // 87
    virtual bool GetQuestObject();                                                         // 88
    virtual void SetActorCause(ActorCause* apActorCause);                                  // 89
    virtual ActorCause* GetActorCause();                                                   // 90
    virtual NiPoint3 GetStartingAngle();                                                   // 91
    virtual NiPoint3 GetStartingLocation();                                                // 92
    virtual void SetStartingPosition(NiPoint3 aposition);                                  // 93
    virtual void UpdateRefLight();                                                         // 94
    virtual TESObjectREFR* RemoveItem(TESBoundObject* apObject, ExtraDataList* apExtra, int aiNumber, bool abStealing, bool abDropWorld, TESObjectREFR* apContainerObj, const NiPoint3* apPoint, const NiPoint3* apRotate, bool abDelete, bool abPreferStolen); // 95
    virtual void RemoveItemType(ENUM_FORM_ID aeType, bool abStealing, int aiNumber);       // 96
    virtual bool AddWornItem(TESBoundObject* apObject, int aiNumber, ExtraDataList* apExtra, bool abForceEquip); // 97
    virtual bool RemoveWornItem(TESBoundObject* apObject, int aiNumber, ExtraDataList* apExtra); // 98
    virtual void DoTrap(TrapEntry* apTrap, TargetEntry* apTarget);                         // 99
    virtual void AddObjecttoContainer(TESBoundObject* apObj, ExtraDataList* apExtra, int aicount); // 100
    virtual NiPoint3 GetLookingAtLocation();                                               // 101
    virtual MagicCaster* GetMagicCaster();                                                 // 102
    virtual MagicTarget* GetMagicTarget();                                                 // 103
    virtual bool IsChild(bool abIgnoreHeight);                                             // 104
    virtual TESActorBase* GetTemplateActorBase();                                          // 105
    virtual void SetTemplateActorBase(TESActorBase* apTemplate);                           // 106
    virtual BSFaceGenNiNode* GetFaceNodeBiped(NiNode* apHeadNode);                         // 107
    virtual BSFaceGenNiNode* GetFaceNodeSkinned(NiNode* apHeadNode);                       // 108
    virtual BSFaceGenNiNode* GetFaceNode(NiNode* apHeadNode);                              // 109
    virtual BSFaceGenAnimationData* GetFaceAnimationData(NiNode* apHeadNode);              // 110
    virtual bool ClampToGround();                                                          // 111
    virtual bool DetachHavok();                                                            // 112
    virtual void InitHavok();                                                              // 113
    virtual NiAVObject* Load3D(bool abBackgroundLoading);                                  // 114
    virtual void Set3D(NiAVObject* apObject, bool abTestProcessLevel);                     // 115
    virtual NiAVObject* Get3D();                                                           // 116
    virtual bool GetRandomAnim();                                                          // 117
    virtual NiPoint3 GetBoundMin();                                                        // 118
    virtual NiPoint3 GetBoundMax();                                                        // 119
    virtual void UpdateAnimation();                                                        // 120
    virtual Animation* GetAnimation();                                                     // 121
    virtual BipedAnim* GetBiped();                                                         // 122
    virtual BipedAnim* GetCurrentBiped();                                                  // 123
    virtual void SetBiped(BipedAnim* apBiped);                                             // 124
    virtual const NiPoint3& GetLocationOnReference();                                      // 125
    virtual void SetRunsInLow(bool abFlag);                                                // 126
    virtual void MoveHavok(bool abForceRec);                                               // 127
    virtual void SetActionComplete(bool bValue);                                           // 128
    virtual void SetMovementComplete(bool abValue);                                        // 129
    virtual void ResetInventory(bool abLeveledOnly);                                       // 130
    virtual NiAVObject* GetFireNode();                                                     // 131
    virtual void SetFireNode(NiAVObject* apFireNode);                                      // 132
    virtual SIT_SLEEP_STATE GetSitSleepState();                                            // 133
    virtual bool IsNpc();                                                                  // 134
    virtual bool IsCreature();                                                             // 135
    virtual bool IsExplosion();                                                            // 136
    virtual bool IsProjectile();                                                           // 137
    virtual void SetParentCell(TESObjectCELL* apCell);                                     // 138
    virtual bool IsDead(bool bNotEssential);                                               // 139
    virtual bool IsKnockedOut();                                                           // 140
    virtual bool IsParalyzed();                                                            // 141
    virtual BSAnimNoteReceiver* CreateAnimNoteReceiver();                                  // 142
    virtual BSAnimNoteReceiver* GetAnimNoteReceiever();                                    // 143
// types: Actor ActorCause Animation BGSLoadFormBuffer BGSSaveFormBuffer BSAnimNoteReceiver BSFaceGenAnimationData BSFaceGenNiNode BSSoundHandle BSStringT BipedAnim ENUM_FORM_ID ExtraDataList FORM FORM_GROUP MagicCaster MagicTarget NiAVObject NiNode NiPoint3 NiTPointerMap SIT_SLEEP_STATE TESActorBase TESBoundObject TESFile TESForm TESObjectCELL TESObjectREFR TESTopic TargetEntry TrapEntry

    enum
    {
        CHANGE_SCRIPT_VARIABLES = 0x80000000u
    };
    ScriptLocals* GetReferenceLocals();
    TESObjectCELL* GetParentCell();
    TESBoundObject* GetObjectReference();
    ExtraDataList* GetExtraData();
    const NiPoint3& GetAngleOnReference() const;
    TESWorldSpace* GetParentWorldSpace() const;
    void RelocateTo(TESWorldSpace* worldSpace, TESObjectCELL* cell, const NiPoint3& location, float angle);
    bool IsLimbMissing(int limb);
    TESObjectREFR* GetLinkedRef();
    NiAVObject* Get3DSimple();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObjectREFR) == 0x68);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, pRandomSound) == 0x1C);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, data) == 0x20);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, fRefScale) == 0x3C);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, pParentCell) == 0x40);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, m_Extra) == 0x44);
FNV_STATIC_ASSERT(offsetof(TESObjectREFR, pLoadedData) == 0x64);
#endif
