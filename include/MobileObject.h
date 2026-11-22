// MobileObject: a reference that moves and is driven by an AI process (the base of Actor).
// Names: FNV360_PDB (MobileObject, 0822 retail; members from its fields, virtuals from its vtable). Vtable: 193 slots,
// checked against F3_EXE's MobileObject vtable (193 slots; every linked non-stub slot agrees). Overload pairs are
// declared last slot first, as VC8 lays them out.
#ifndef FNV_MOBILEOBJECT_H
#define FNV_MOBILEOBJECT_H
#include "f3_common.h"
#include "layout_support.h"
#include "TESObjectREFR.h"
class BGSLoadFormBuffer;
class DialogueResponse;
class PackageLocation;
class SoundPlaybackHandle;
class TESIdleForm;
class TESPackage;
class bhkCharacterController;
#pragma pack(push, 4)
class MobileObject : public TESObjectREFR
{
  public:
    BaseProcess* pCurrentProcess;           // +0x68
    TESObjectREFR* pTalkingActivator;       // +0x6C
    MobileObject* pDialogueItemTarget;      // +0x70
    float fUpdateTargetTimer;               // +0x74
    float fSayToFailVoiceTimer;             // +0x78
    bool bSpeakingDone;                     // +0x7C
    bool bTalkingToPlayer;                  // +0x7D
    bool bIgnoreChangeAnimationCall;        // +0x7E
    bool bSoundFileDone;                    // +0x7F
    bool bVoiceFileDone;                    // +0x80
    bool bTalkingActivator;                 // +0x81
    bool bInTempChangeList;                 // +0x82
    bool bDoNotRunSayToCallBack;            // +0x83
    char cSoundCallBackSet;                 // +0x84
    bool bSoundCallBackSuccess;             // +0x85
    bool bUseEmotion;                       // +0x86
    bool bRunsInLow;                        // +0x87

    // TESForm, TESObjectREFR
    virtual ~MobileObject();                                                               // 4  (TESForm)
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
    virtual void FinishLoadGame(BGSLoadFormBuffer*);                                       // 33  (TESForm)
    virtual void SetDelete(bool);                                                          // 49  (TESForm)
    virtual bool IsMobileObject();                                                         // 63  (TESForm)
    virtual void UpdateSoundCallBack();                                                    // 80  (TESObjectREFR)
    virtual bool DetachHavok();                                                            // 112  (TESObjectREFR)
    virtual void InitHavok();                                                              // 113  (TESObjectREFR)
    virtual NiAVObject* Load3D(bool);                                                      // 114  (TESObjectREFR)
    virtual NiPoint3 GetBoundMin();                                                        // 118  (TESObjectREFR)
    virtual NiPoint3 GetBoundMax();                                                        // 119  (TESObjectREFR)
    virtual void SetRunsInLow(bool);                                                       // 126  (TESObjectREFR)
    virtual void MoveHavok(bool);                                                          // 127  (TESObjectREFR)
    virtual void SetParentCell(TESObjectCELL*);                                            // 138  (TESObjectREFR)
    virtual bool IsKnockedOut();                                                           // 140  (TESObjectREFR)
    // MobileObject
    virtual bool MovetoHigh();                                                             // 144
    virtual bool MovetoLow();                                                              // 145
    virtual bool MovetoMiddleLow();                                                        // 146
    virtual bool MovetoMiddleHigh();                                                       // 147
    virtual bhkCharacterController* Move(float afDeltaTime, NiPoint3& arDeltaMove, unsigned int aiMoveDir); // 148
    virtual bhkCharacterController* Jump();                                                // 149
    virtual void SetAvoidanceDisabled(bool abTF);                                          // 150
    virtual void Process(float afDelta);                                                   // 151
    virtual bool ChangeProcessLevel();                                                     // 152
    virtual void UpdateInDialogue(float afDelta, DialogueResponse* pResponse, bool abChangeAnimationEndVoice); // 153
    virtual void UpdateAnimation(float afDelta);                                           // 154
    virtual bool GetEVPBuffered();                                                         // 155
    virtual void EvaluatePackage();                                                        // 156
    virtual bool IsInCombat(bool abSearching);                                             // 157
    virtual void SetDialoguewithPlayer(bool abFlag);                                       // 158
    virtual bool InitiateDialogue(MobileObject* apTarget, PackageLocation* pPackLoc, PackageLocation* pPackSecondLoc, bool bHeadTrack, bool bMove, bool bflag, TESTopic* pTopic, bool abTargetContinueMoving, bool abTargetMoveTowardStarter); // 160
    virtual bool InitiateDialogue(TESPackage* pDialoguePackage);                           // 159
    virtual float SpeakSoundFunction(const char* apSoundFile, BSSoundHandle& aSoundHand, DIALOGUE_EMOTION aeEmotiontype, unsigned int aiEmotionValue, int aiStringLength, TESIdleForm* apResponseSpeakerIdle, TESIdleForm* apResponseListenerIdle, TESObjectREFR* apTarget, bool abSetEmotion, bool ab2D, bool abQueue, bool abLip, bool abUseIdleManager); // 161
    virtual void EndDialogue();                                                            // 162
    virtual void SetRunOnceExtraPackage(TESPackage* apPack, char acDay);                   // 163
    virtual bool HasEditorLocation();                                                      // 164
    virtual TESWorldSpace* GetEditorLocationWorld();                                       // 165
    virtual TESObjectCELL* GetEditorLocationInteriorCell();                                // 166
    virtual NiPoint3 GetEditorLocationCoord();                                             // 167
    virtual bool DetachCharController();                                                   // 168
    virtual bool RemoveCharController();                                                   // 169
    virtual void SetPosition(const NiPoint3& arPos);                                       // 170
    virtual void GetLinearVelocity(NiPoint3& arVel);                                       // 171
    virtual void EvaluateDetection(float ftime);                                           // 172
    virtual float GetDetectionTimer();                                                     // 173
    virtual void ReduceDetectionTimer();                                                   // 174
    virtual float GetHeading(bool abIgnoreImmobile);                                       // 175
    virtual void SetHeading(float afAngle);                                                // 177
    virtual void SetHeading(TESObjectREFR* apTargetReference);                             // 176
    virtual TESObjectREFR* GetCurrentTarget();                                             // 178
    virtual bool IsAtPoint(const NiPoint3& aPoint, float afRadius, bool abExpandRadius, bool abAlwaysTestHeight); // 179
    virtual int GetSpeakingEmotion();                                                      // 180
    virtual void SetSpeakingEmotion(int aiEmotion);                                        // 181
    virtual int GetSpeakingEmotionValue();                                                 // 182
    virtual void SetSpeakingEmotionValue(int aiEmotionValue);                              // 183
    virtual void SetSize(float afRadius);                                                  // 184
    virtual float GetAcrobatics();                                                         // 185
    virtual bool IsDying();                                                                // 186
    virtual bool IsTransient();                                                            // 187
    virtual void SetDisplayGeometry(bool abTF);                                            // 188
    virtual void PutCreatedPackage(TESPackage* apPack, bool abTempPack, bool abIsaCreatedPackage); // 189
    virtual void Update(float afDelta);                                                    // 190
    virtual void CleanUpPointersOnDisable();                                               // 191
    virtual MobileObject* SetUpTalkingActivatorActor(MobileObject* apTarget, MobileObject*& aptalkingactivator); // 192
// types: BGSLoadFormBuffer BGSSaveFormBuffer BSSoundHandle DIALOGUE_EMOTION DialogueResponse MobileObject NiAVObject NiPoint3 PackageLocation TESIdleForm TESObjectCELL TESObjectREFR TESPackage TESTopic TESWorldSpace bhkCharacterController

    bool HasSaidTopicInfo(TESTopicInfo* info);
    bhkCharacterController* GetPhysicsCharacterController();
    bool IsActorDead();
    bool GetCharControllerFlag() const;
    SoundPlaybackHandle PlaySoundByEditorName(const char* editorName, bool loop, unsigned int flags, bool unused);
    void AdvanceMovement(float delta);
    float GetLooking() const;
    bool IsInDialogueWithPlayer() const;
    void ProcessAnimation();
    TESPackage* GetCurrentPackage() const;
    bool IsCombatStateActive() const;
    void SetChaseMode(bool chase);
    bool IsTalkingActivator() const;
    BaseProcess* GetCurrentAIProcess() const;
    PROCESS_TYPE GetProcessTier() const;
    PROCESS_TYPE GetCurrentProcessLevel();
    float GetActorHeight() const;
    const char* GetFullName();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MobileObject) == 0x88);
FNV_STATIC_ASSERT(offsetof(MobileObject, pCurrentProcess) == 0x68);
FNV_STATIC_ASSERT(offsetof(MobileObject, fUpdateTargetTimer) == 0x74);
FNV_STATIC_ASSERT(offsetof(MobileObject, bSpeakingDone) == 0x7C);
FNV_STATIC_ASSERT(offsetof(MobileObject, cSoundCallBackSet) == 0x84);
FNV_STATIC_ASSERT(offsetof(MobileObject, bRunsInLow) == 0x87);
#endif
