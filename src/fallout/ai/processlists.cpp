// fallout/ai/processlists.cpp: ProcessLists, ProcessListsEx, TESObjectREFR, BGSProjectile and more (1 function)
#include "f3_common.h"
#include "processlists_private/processlists_ProcessLists.h"
#include "processlists_private/processlists_Actor.h"
#include "processlists_private/processlists_BGSTalkingActivator.h"
#include "processlists_private/processlists_BGSProjectile.h"
#include "processlists_private/processlists_Projectile.h"
#include "processlists_private/processlists_Explosion.h"
#include "processlists_private/processlists_BaseProcess.h"
#include "processlists_private/processlists_PlayerCharacter.h"
#include "processlists_private/processlists_types_TESPackage.h"
#include "processlists_private/processlists_BSTempEffect.h"
#include "processlists_private/processlists_GarbageCollector.h"
#include "processlists_private/processlists_dead_animation_actorbase.h"
#include "processlists_private/processlists_decls.h"

#pragma optimize("gty", on)
// @f3 0x008d6240 (community match, verified in this file)
extern void __cdecl FUN_008d4c10();
// pdb: bhkWorld::StopBatchingRemovals | bhkWorld.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: bhkWorld::ProcessBatchAdds)
// pdb params: abAllowPartial
void bhkWorld::SetWorldActive(bool arg)
{
    if (*(unsigned int*)&m_pObjectAt24 > 0u)
    {
        if (--*(unsigned int*)&m_pObjectAt24 == 0)
        {
            FUN_008d4c10();
            ReleaseBodies();
            ClearReferences();
            if (arg)
                FlushEntries();
            else
                ClearEntries();
        }
    }
    else if (*(unsigned int*)&_pdbpad_54[4] > 0u && !arg)
    {
        ClearEntries();
    }
}

#pragma optimize("", off)

struct FUN_0096e570_shell : public ProcessLists
{
    void FUN_0096e570();
};

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011cde2c;
int __cdecl FUN_00970ee0(Actor*, Actor*);

void __cdecl FUN_008661e0(void*, unsigned int, const void*, unsigned int);

struct TESFormList
{
    bool _ref_008256d0();
    MobileObject** _ref_006815c0();
    void _ref_00905330(MobileObject**);
    TESFormList* GetFirst();
};

struct NiAVObject;
struct TESObjectLIGH;
struct TESObjectWEAP;
struct MuzzleFlash
{
    void Init(TESObjectREFR*);
    void Update(float, TESObjectREFR*);
    void SetParentRef(TESObjectREFR*);
    void Enable();
    void AttachLight();
    void UpdateMagicCaster();
    void DisableMuzzleFlash();
    bool GetEnabled();
    NiAVObject* FindAVObject();
    BGSProjectile* GetProjectileData();
    TESObjectWEAP* GetWeaponSource();
    TESModel* GetMuzzleFlashModel();
    TESObjectLIGH* GetMuzzleFlashLight();
    TESObjectREFR* GetParentRef();
    void SetDurationTimer(float);
    static void TriggerMuzzleFlash(TESObjectREFR*, Projectile*);
    void* __vecDelDtor(unsigned int);
    bool bEnabled;
    bool bMPSEnabled;
    bool bUpdateLight;
    char _pad_3[1];
    float m_fDurationTimer;
    float m_fFlashDuration;
    char pChild[4];
    char m_pMenuLight[4];
    BGSProjectile* pProjectile;
    TESObjectWEAP* m_pFiringWeapon;
    TESObjectREFR* m_pParentRef;
};
typedef char _sizecheck_MuzzleFlash[sizeof(MuzzleFlash) == 32 ? 1 : -1];

class NavMeshInfo;
template <> class BSSimpleArray<NavMeshInfo*, 1024>
{
  public:
    void FUN_006b3eb0(unsigned int, bool);
};

struct _LARGE_INTEGER
{
    long HighPart;
    unsigned long LowPart;
};
typedef char _sizecheck__LARGE_INTEGER[sizeof(_LARGE_INTEGER) == 8 ? 1 : -1];

struct MobileObjectExt
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void Update(float afDelta);
    void SetCurrentProcess(BaseProcess* apProcess);
    void FUN_00565870();
};

class LowProcess
{
  public:
    float FUN_007df1f0();
    void ResetPackageState();
};

class Calendar
{
  public:
    float GetGameTime();
};

__declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* apCount);
int __fastcall FUN_004f8960(void* apActor);

extern Calendar g_calendar;
extern bool DAT_011e0e34;
extern const double _gModifierZero;

namespace fnv_0096bcd0 {
namespace lc1 {
struct AutoMemContext
{
    AutoMemContext(int aeContext, bool abFlag, const char* apFile, int aiLine);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}
struct ExtraFollower
{
    void* pVtbl;
    unsigned char m_ucExtraDataType;
    BSExtraData* pNext;
    BSSimpleList<Actor*>* pFollowers;
};
struct Calendar
{
    float GetGameTime();
};
struct TimeGlobal
{
    float GetStoredFloatValue();
};
extern Calendar g_calendar;
extern TimeGlobal g_timeGlobal;
extern PlayerCharacter* g_thePlayer;
extern bool DAT_011e0e34;

}  // namespace fnv_0096bcd0

namespace fnv_00977cb0 {

struct Setting_S
{
    float* Float();
};
struct Ref_S
{
    float GetDistanceToReference(void*, bool, bool);
};
struct ProcStub
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
    virtual bool IsInDialogue();
};
struct PC7d
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
    virtual Actor* GetDialogueTarget();
};
extern double _gModifierZero;
extern PC7d* g_thePlayer;

}  // namespace fnv_00977cb0

namespace fnv_008661e0 {

}  // namespace fnv_008661e0

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
struct IndexedTaskData
{
    static void TaskFunc(void*);
    int* m_pIntegerData;
    void* pData;
    unsigned int iSize;
    unsigned int iIndex;
};
typedef char _sizecheck_BSParallelArrayTask[sizeof(IndexedTaskData) == 16 ? 1 : -1];

template <class T, unsigned int N> class BSScrapArray
{
  public:
    BSScrapArray();
    virtual ~BSScrapArray();
    unsigned int Add(T& item);
    unsigned int GetTarget();
    T* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    unsigned int uiGrowSize;
};
struct ShadowSceneNode
{
    void RemoveSceneObject(NiAVObject*, bool);
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* GetShadowSceneNodeForIndex(int);
};
struct AnimUpdateHelper
{
    bool FUN_00493930();
};

struct BSFadeNode
{
    bool FUN_00552470() const;
};

namespace fnv_009724e0 {
class TESFormList
{
  public:
    MobileObject** _ref_006815c0();
    TESFormList* GetFirst();
};
struct TESResponse
{
    int GetNext();
};

}  // namespace fnv_009724e0

namespace fnv_00974af0 {
class TESFormList
{
  public:
    NiPointer<BSTempEffect>* _ref_006815c0();
    TESFormList* GetFirst();
};
struct MagicHitEffect
{
    char* GetData();
    void SetByteAt24(unsigned char);
};

}  // namespace fnv_00974af0

namespace fnv_00977660 {

struct Setting_S
{
    float* Float();
};
struct Ref_S
{
    float GetDistanceToReference(void*, bool, bool);
};
struct FUN_0096e570_shell
{
    void FUN_0096e570();
};

}  // namespace fnv_00977660

namespace fnv_0096cb20 {
struct AnimUpdateHelper
{
    bool FUN_00493930();
};
}  // namespace fnv_0096cb20

namespace fnv_0096c860 {
struct NiAdditionalGeometryData
{
    static NiAVObject* GetShadowSceneNodeForIndex(int);
};
struct ShadowSceneNode
{
    void RemoveSceneObject(NiAVObject*, bool);
};
}  // namespace fnv_0096c860

struct Flt
{
    operator unsigned int();
};
struct MiddleHighProcess
{
    void FUN_00929260(unsigned char);
};
struct BSTempEffectGeometryDecal
{
    NiPointer<BSTempEffect> operator*();
    void FUN_00929260(unsigned char);
};

namespace fnv_00978550 {

class MobileObjectExt : public MobileObject
{
  public:
    void FUN_00565870();
};

}  // namespace fnv_00978550

namespace fnv_00971fd0 {
struct CTSHelper
{
    CTSHelper();
    float GetElapsedTime();
    int m_iPackageData;
};
struct TESFormList
{
    void* GetFirst();
};
struct TESTopicInfoData;
struct TESTopicInfo
{
    TESTopicInfoData* GetConversationData();
    CTSHelper FUN_008bcc60();
};
struct FUN_009722e0_shell
{
    bool IsActorInOtherList(void* apRef, TESTopicInfo* apInfo);
};
struct List_009e03e0
{
    ~List_009e03e0();
    void* pItem;
    void* pNext;
};
struct SL : List_009e03e0
{
    SL();
};
struct G2
{
    void AddHead(int*);
};

}  // namespace fnv_00971fd0

namespace fnv_0096e3c0 {
struct CloningProcess;
struct NiStream;

struct SettingInt
{
    int* Int();
};
extern SettingInt g_011cde2c;
void __cdecl FUN_008661e0(void*, unsigned int, const void*, unsigned int);

}  // namespace fnv_0096e3c0

namespace fnv_00972570 {
struct TESFormList
{
    TESFormList* GetFirst();
};

Crime** __fastcall _ref_006815c0(void*);

}  // namespace fnv_00972570

namespace fnv_00974a50 {
struct Flt
{
    operator unsigned int();
};

Flt* __fastcall _ref_006815c0(void*);

struct MagicHitEffect
{
    void SetByteAt24(unsigned int);
};

struct TESFormList
{
    TESFormList* GetFirst();
};

class MagicShaderHitEffect;

}  // namespace fnv_00974a50

namespace fnv_00977130 {
struct ActorPackageData;
struct AnimIdle;
struct Animation;
struct ArrowProjectile;
struct BGSBodyPartData;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct BSBound;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSShaderPPLightingProperty;
struct BipedAnim;
struct ActorCombatGroup;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct FurnitureMark;
struct HighProcess;
struct BooleanFloatQuery;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct LowProcess;
struct MagicItem;
struct MiddleHighProcess;
struct MiddleLowProcess;
struct MuzzleFlash;
struct NiAVObject;
struct NiControllerManager;
struct NiNode;
struct TargetDoorController;
struct PackageTargetRecord;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct SpellItem;
struct TESEffectShader;
struct TESFaction;
struct TESIdleForm;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESWorldSpace;
struct bhkCharacterController;
struct bhkSimpleShapePhantom;

bool FUN_00525420();
extern double _gModifierZero;
struct Setting_S
{
    float* Float();
};
struct GlobalObject2_0040c150
{
    int* Int();
};
struct TESResponse
{
    int GetNext();
};
struct HighProcess
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210();
    virtual void V211();
    virtual void V212();
    virtual void V213();
    virtual void V214();
    virtual void V215();
    virtual void V216();
    virtual void V217();
    virtual void V218();
    virtual void V219();
    virtual void V220();
    virtual void V221();
    virtual void V222();
    virtual void V223();
    virtual void V224();
    virtual void V225();
    virtual void V226();
    virtual void V227();
    virtual void V228();
    virtual void V229();
    virtual void V230();
    virtual void V231();
    virtual void V232();
    virtual void V233();
    virtual void V234();
    virtual void V235();
    virtual void V236();
    virtual void V237();
    virtual void V238();
    virtual void V239();
    virtual void V240();
    virtual void V241();
    virtual void V242();
    virtual void V243();
    virtual void V244();
    virtual void V245();
    virtual void V246();
    virtual void V247();
    virtual void V248();
    virtual void V249();
    virtual void V250();
    virtual void V251();
    virtual void V252();
    virtual void V253();
    virtual void V254();
    virtual void V255();
    virtual void V256();
    virtual void V257();
    virtual void V258();
    virtual void V259();
    virtual void V260();
    virtual void V261();
    virtual void V262();
    virtual void V263();
    virtual void V264();
    virtual void V265();
    virtual void V266();
    virtual void V267();
    virtual void V268();
    virtual void V269();
    virtual void V270();
    virtual void V271();
    virtual void V272();
    virtual void V273();
    virtual void V274();
    virtual void V275();
    virtual void V276();
    virtual void V277();
    virtual void V278();
    virtual void V279();
    virtual void V280();
    virtual void V281();
    virtual void V282();
    virtual void V283();
    virtual void V284();
    virtual void V285();
    virtual void V286();
    virtual void V287();
    virtual void V288();
    virtual void V289();
    virtual void V290();
    virtual void V291();
    virtual void V292();
    virtual void V293();
    virtual void V294();
    virtual void V295();
    virtual void V296();
    virtual void V297();
    virtual void V298();
    virtual void V299();
    virtual float GetDeadTimer();
    virtual void V301();
    virtual void V302();
    virtual void V303();
    virtual void V304();
    virtual void V305();
    virtual void V306();
    virtual void V307();
    virtual void V308();
    virtual void V309();
    virtual void V310();
    virtual void V311();
    virtual void V312();
    virtual void V313();
    virtual void V314();
    virtual void V315();
    virtual void V316();
    virtual void V317();
    virtual void V318();
    virtual void V319();
    virtual void V320();
    virtual void V321();
    virtual void V322();
    virtual void V323();
    virtual void V324();
    virtual void V325();
    virtual void V326();
    virtual void V327();
    virtual void V328();
    virtual void V329();
    virtual void V330();
    virtual void V331();
    virtual void V332();
    virtual void V333();
    virtual void V334();
    virtual void V335();
    virtual void V336();
    virtual void V337();
    virtual void V338();
    virtual void V339();
    virtual void V340();
    virtual void V341();
    virtual void V342();
    virtual void V343();
    virtual void V344();
    virtual void V345();
    virtual void V346();
    virtual void V347();
    virtual void V348();
    virtual void V349();
    virtual void V350();
    virtual void V351();
    virtual void V352();
    virtual void V353();
    virtual void V354();
    virtual void V355();
    virtual void V356();
    virtual void V357();
    virtual void V358();
    virtual void V359();
    virtual void V360();
    virtual void V361();
    virtual void V362();
    virtual void V363();
    virtual void V364();
    virtual void V365();
    virtual void V366();
    virtual void V367();
    virtual void V368();
    virtual void V369();
    virtual void V370();
    virtual void V371();
    virtual void V372();
    virtual void V373();
    virtual void V374();
    virtual void V375();
    virtual void V376();
    virtual void V377();
    virtual void V378();
    virtual void V379();
    virtual void V380();
    virtual void V381();
    virtual void V382();
    virtual void V383();
    virtual void V384();
    virtual void V385();
    virtual void V386();
    virtual void V387();
    virtual int IsInDialogue();
    void FUN_008feb60(Actor*);
};

}  // namespace fnv_00977130

namespace fnv_00974b80 {
struct TESFormList
{
    void* GetFirst();
};
struct GO
{
    operator unsigned int();
};
struct MagicHitEffect
{
    void SetByteAt24(unsigned int);
};
}  // namespace fnv_00974b80

struct Modifier
{
    unsigned char GetKey();
};

namespace fnv_009721f0 {

struct MemoryManager
{
    static void* __cdecl Allocate(unsigned int);
};

struct TESFormList
{
    void* GetFirst();
};

struct G2
{
    void __thiscall AddHead(int* value);
};

struct SL
{
    int field0;
    int field4;

    SL();
};

}  // namespace fnv_009721f0

namespace fnv_009754f0 {
struct SaveManager;
struct GameTimerRecord
{
    unsigned int* GetTime() const;
};

struct TESSaveLoadGame
{
    void FUN_008579b0(void* data, int type);
};

struct TESFormList
{
    void* GetFirst();
};

extern SaveManager* DAT_011de45c;

}  // namespace fnv_009754f0

bool FUN_009336c0(MobileObject* pCurrentObject);

struct FUN_009336c0_shell
{
    bool FUN_009336c0() const;
};

PlayerCharacter* _g_thePlayer;

struct FUN_00978420_actor_base
{
    virtual void M0()
    {}
    virtual void M1()
    {}
    virtual void M2()
    {}
    virtual void M3()
    {}
    virtual void M4()
    {}
    virtual void M5()
    {}
    virtual void M6()
    {}
    virtual void M7()
    {}
    virtual void M8()
    {}
    virtual void M9()
    {}
    virtual void M10()
    {}
    virtual void M11()
    {}
    virtual void M12()
    {}
    virtual void M13()
    {}
    virtual void M14()
    {}
    virtual void M15()
    {}
    virtual void M16()
    {}
    virtual void M17()
    {}
    virtual void M18()
    {}
    virtual void M19()
    {}
    virtual void M20()
    {}
    virtual void M21()
    {}
    virtual void M22()
    {}
    virtual void M23()
    {}
    virtual void M24()
    {}
    virtual void M25()
    {}
    virtual void M26()
    {}
    virtual void M27()
    {}
    virtual void M28()
    {}
    virtual void M29()
    {}
    virtual void M30()
    {}
    virtual void M31()
    {}
    virtual void M32()
    {}
    virtual void M33()
    {}
    virtual void M34()
    {}
    virtual void M35()
    {}
    virtual void M36()
    {}
    virtual void M37()
    {}
    virtual void M38()
    {}
    virtual void M39()
    {}
    virtual void M40()
    {}
    virtual void M41()
    {}
    virtual void M42()
    {}
    virtual void M43()
    {}
    virtual void M44()
    {}
    virtual void M45()
    {}
    virtual void M46()
    {}
    virtual void M47()
    {}
    virtual void M48()
    {}
    virtual void M49()
    {}
    virtual void M50()
    {}
    virtual void M51()
    {}
    virtual void M52()
    {}
    virtual void M53()
    {}
    virtual void M54()
    {}
    virtual void M55()
    {}
    virtual void M56()
    {}
    virtual void M57()
    {}
    virtual void M58()
    {}
    virtual void M59()
    {}
    virtual void M60()
    {}
    virtual void M61()
    {}
    virtual void M62()
    {}
    virtual void M63()
    {}
    virtual void M64()
    {}
    virtual void M65()
    {}
    virtual void M66()
    {}
    virtual void M67()
    {}
    virtual void M68()
    {}
    virtual void M69()
    {}
    virtual void M70()
    {}
    virtual void M71()
    {}
    virtual void M72()
    {}
    virtual void M73()
    {}
    virtual void M74()
    {}
    virtual void M75()
    {}
    virtual void M76()
    {}
    virtual void M77()
    {}
    virtual void M78()
    {}
    virtual void M79()
    {}
    virtual void M80()
    {}
    virtual void M81()
    {}
    virtual void M82()
    {}
    virtual void M83()
    {}
    virtual void M84()
    {}
    virtual void M85()
    {}
    virtual void M86()
    {}
    virtual void M87()
    {}
    virtual void M88()
    {}
    virtual void M89()
    {}
    virtual void M90()
    {}
    virtual void M91()
    {}
    virtual void M92()
    {}
    virtual void M93()
    {}
    virtual void M94()
    {}
    virtual void M95()
    {}
    virtual void M96()
    {}
    virtual void M97()
    {}
    virtual void M98()
    {}
    virtual void M99()
    {}
    virtual void M100()
    {}
    virtual void M101()
    {}
    virtual void M102()
    {}
    virtual void M103()
    {}
    virtual void M104()
    {}
    virtual void M105()
    {}
    virtual void M106()
    {}
    virtual void M107()
    {}
    virtual void M108()
    {}
    virtual void M109()
    {}
    virtual void M110()
    {}
    virtual void M111()
    {}
    virtual void M112()
    {}
    virtual void M113()
    {}
    virtual void M114()
    {}
    virtual void M115()
    {}
    virtual void M116()
    {}
    virtual void M117()
    {}
    virtual void M118()
    {}
    virtual void M119()
    {}
    virtual void M120()
    {}
    virtual void M121()
    {}
    virtual void M122()
    {}
    virtual void M123()
    {}
    virtual void M124()
    {}
    virtual void M125()
    {}
    virtual void M126()
    {}
    virtual void M127()
    {}
    virtual void M128()
    {}
    virtual void M129()
    {}
    virtual void M130()
    {}
    virtual void M131()
    {}
    virtual void M132()
    {}
    virtual void M133()
    {}
    virtual void M134()
    {}
    virtual void M135()
    {}
    virtual void M136()
    {}
    virtual void M137()
    {}
    virtual void M138()
    {}
    virtual void M139()
    {}
    virtual void M140()
    {}
    virtual void M141()
    {}
    virtual void M142()
    {}
    virtual void M143()
    {}
    virtual void M144()
    {}
    virtual void M145()
    {}
    virtual void M146()
    {}
    virtual void M147()
    {}
    virtual void M148()
    {}
    virtual void M149()
    {}
    virtual void M150()
    {}
    virtual void M151()
    {}
    virtual void M152()
    {}
    virtual void M153()
    {}
};

struct FUN_00978420_actor : public FUN_00978420_actor_base
{
    virtual void M154(float f)
    {}
};

class ProcessLoopObject;

class ProcessLoopObject
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
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual unsigned char v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
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
    virtual unsigned int v116();
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
    virtual void v154(float f);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned char m_bc;
    void* Get8D6F30();
    unsigned char Get440D80();
    unsigned char Get440DA0();
};

struct Settings970d50
{
    float FUN_00867da0();
    int FUN_00867c60();
    int FUN_00867d20();
    bool FUN_00867d60();
};
extern Settings970d50 DAT_011de7b8;

extern void* DAT_011dea3c;

class ContNode;

ContNode* __fastcall FUN_00726070(ContNode* node);

struct S973_Process
{
    void* IsReady973();
};

struct S973_Base;

struct S973_Ref;

struct S973_Faction
{
    bool Contains973(S973_Ref* apObj);
};

struct S973_Actor
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
    virtual bool IsValid973();
    S973_Base* GetBase973();
    S973_Process* GetProc973();
};

struct S973_Base
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    S973_Faction factions;
};

struct S973_Ref
{
    bool CanUse973(S973_Actor* apActor, bool abFlag);
    S973_Ref* GetObj973();
};

struct ObjV
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
    virtual void Fn();
    int FUN_00441110();
    void SetByteAt24(bool);
};
bool __cdecl FUN_0043b300(const void*, ObjV*);

struct ShaderHitTargetForm
{
    virtual void v00();
    virtual int GetKind();
};
struct ShaderHitTarget
{
    ShaderHitTargetForm* GetForm();
};
class MagicShaderHitEffect : public BSTempEffect
{
  public:
    virtual void v31();
    ShaderHitTarget* GetHitTarget();
    float GetTimeLeft();
    void Finish();
};

struct ProcessListsEx : public ProcessLists
{
    bool FUN_00974e90(int aiKind, int aTarget);
};

struct TESSaveLoadGame
{
    unsigned short* GetSaveCountPtr();
    void SaveData(void* data, int size);
};

namespace fnv_00976680 {
struct Obj;
struct Obj
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
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
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual bool v100();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual Obj* v128();
    virtual void v12c(int a);
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual int v198();
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
    virtual Obj* v20c();
    virtual void d132();
    virtual void v214();
    virtual void d134();
    virtual void d135();
    virtual bool v220();
    virtual bool v224();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void v234();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
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
    virtual Obj* v27c();
    virtual void d160();
    virtual void d161();
    virtual void v288();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void d169();
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual void d175();
    virtual void d176();
    virtual void v2c4(Obj* a, int b);
    virtual Obj* v2c8();
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
    virtual void d195();
    virtual void v310(int a);
    virtual void d197();
    virtual void d198();
    virtual void d199();
    virtual void d200();
    virtual void d201();
    virtual void d202();
    virtual void d203();
    virtual void d204();
    virtual void d205();
    virtual void d206();
    virtual void d207();
    virtual void d208();
    virtual void d209();
    virtual void d210();
    virtual void d211();
    virtual void d212();
    virtual void d213();
    virtual void d214();
    virtual void d215();
    virtual void d216();
    virtual void d217();
    virtual void d218();
    virtual void d219();
    virtual void d220();
    virtual void d221();
    virtual void d222();
    virtual void d223();
    virtual void d224();
    virtual void d225();
    virtual void d226();
    virtual void d227();
    virtual void d228();
    virtual void d229();
    virtual void d230();
    virtual void d231();
    virtual void d232();
    virtual void d233();
    virtual void d234();
    virtual void d235();
    virtual void d236();
    virtual void d237();
    virtual void d238();
    virtual void d239();
    virtual void d240();
    virtual void d241();
    virtual void d242();
    virtual void d243();
    virtual void d244();
    virtual void d245();
    virtual void d246();
    virtual void d247();
    virtual void d248();
    virtual void d249();
    virtual void d250();
    virtual void d251();
    virtual void d252();
    virtual void d253();
    virtual void d254();
    virtual void d255();
    virtual void d256();
    virtual void d257();
    virtual void d258();
    virtual void d259();
    virtual void d260();
    virtual void d261();
    virtual void d262();
    virtual void d263();
    virtual void d264();
    virtual void d265();
    virtual Obj* v428();
    virtual void d267();
    virtual void d268();
    virtual void d269();
    virtual void d270();
    virtual void d271();
    virtual void d272();
    virtual void d273();
    virtual void d274();
    virtual void d275();
    virtual void d276();
    virtual void d277();
    virtual void d278();
    virtual void d279();
    virtual void d280();
    virtual void d281();
    virtual void d282();
    virtual void d283();
    virtual void d284();
    virtual void d285();
    virtual void d286();
    virtual void v47c(Obj* a);
    virtual void d288();
    virtual void d289();
    virtual void d290();
    virtual void d291();
    virtual void d292();
    virtual void d293();
    virtual void d294();
    virtual void d295();
    virtual void v4a0();
    virtual void d297();
    virtual void d298();
    virtual void d299();
    virtual void d300();
    virtual void d301();
    virtual void d302();
    virtual void d303();
    virtual void d304();
    virtual void d305();
    virtual void d306();
    virtual void d307();
    virtual void d308();
    virtual void d309();
    virtual void d310();
    virtual void d311();
    virtual void d312();
    virtual void d313();
    virtual void d314();
    virtual void d315();
    virtual void d316();
    virtual void d317();
    virtual void d318();
    virtual void d319();
    virtual void d320();
    virtual void d321();
    virtual void d322();
    virtual void d323();
    virtual void d324();
    virtual void d325();
    virtual void d326();
    virtual void d327();
    virtual void d328();
    virtual void d329();
    virtual void d330();
    virtual void d331();
    virtual void d332();
    virtual void d333();
    virtual void d334();
    virtual void d335();
    virtual void d336();
    virtual void d337();
    virtual void d338();
    virtual void d339();
    virtual void d340();
    virtual void d341();
    virtual void d342();
    virtual void d343();
    virtual void d344();
    virtual void d345();
    virtual void d346();
    virtual void d347();
    virtual void d348();
    virtual void d349();
    virtual void d350();
    virtual void d351();
    virtual void d352();
    virtual void d353();
    virtual void d354();
    virtual void d355();
    virtual void d356();
    virtual void d357();
    virtual void d358();
    virtual void d359();
    virtual void d360();
    virtual void d361();
    virtual void d362();
    virtual void d363();
    virtual void d364();
    virtual void d365();
    virtual void d366();
    virtual void d367();
    virtual void d368();
    virtual void d369();
    virtual void d370();
    virtual void d371();
    virtual void d372();
    virtual void d373();
    virtual void d374();
    virtual void d375();
    virtual void d376();
    virtual void d377();
    virtual void d378();
    virtual void d379();
    virtual void d380();
    virtual void d381();
    virtual void d382();
    virtual void d383();
    virtual void d384();
    virtual void d385();
    virtual void d386();
    virtual void d387();
    virtual void d388();
    virtual void d389();
    virtual void d390();
    virtual void d391();
    virtual void d392();
    virtual void d393();
    virtual void d394();
    virtual void d395();
    virtual void d396();
    virtual void d397();
    virtual void d398();
    virtual void d399();
    virtual void d400();
    virtual void d401();
    virtual void d402();
    virtual void d403();
    virtual void d404();
    virtual void d405();
    virtual void d406();
    virtual void d407();
    virtual void d408();
    virtual void v664(Obj* a);
    virtual void d410();
    virtual void d411();
    virtual void d412();
    virtual void d413();
    virtual void d414();
    virtual void d415();
    virtual void d416();
    virtual void d417();
    virtual void d418();
    virtual void d419();
    virtual void d420();
    virtual void d421();
    virtual void d422();
    virtual void d423();
    virtual void d424();
    virtual void d425();
    virtual void d426();
    virtual void d427();
    virtual void d428();
    virtual void d429();
    virtual void d430();
    virtual void d431();
    virtual void d432();
    virtual void d433();
    virtual void d434();
    virtual void d435();
    virtual void d436();
    virtual void d437();
    virtual void d438();
    virtual void d439();
    virtual void d440();
    virtual void d441();
    virtual void d442();
    virtual void d443();
    virtual void d444();
    virtual void d445();
    virtual void d446();
    virtual void d447();
    virtual void d448();
    virtual void d449();
    virtual void d450();
    virtual void d451();
    virtual void d452();
    virtual void d453();
    virtual void d454();
    virtual void d455();
    virtual void d456();
    virtual void d457();
    virtual void d458();
    virtual void d459();
    virtual void d460();
    virtual void d461();
    virtual void d462();
    virtual void d463();
    virtual void d464();
    virtual void d465();
    virtual void d466();
    virtual void d467();
    virtual void d468();
    virtual void d469();
    virtual void d470();
    virtual void d471();
    virtual void d472();
    virtual void d473();
    virtual void d474();
    virtual void d475();
    virtual void d476();
    virtual void d477();
    virtual void d478();
    virtual void d479();
    virtual void d480();
    virtual void d481();
    virtual void d482();
    virtual void d483();
    virtual void d484();
    virtual void d485();
    virtual void d486();
    virtual void d487();
    virtual void d488();
    virtual void d489();
    virtual void d490();
    virtual void d491();
    virtual void v7b0(Obj* a);
    int u04;
    int u08;
    Obj* f0c;
    int u10;
    Obj* f14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    int ub8;
    int ubc;
    Obj* fc0;
    Obj* FUN_005d43c0();
    Obj* FUN_00422700();
    void FUN_00905330(void* a);
    Obj* FUN_008d8520();
    Obj* FUN_004fd380();
    void FUN_0057bd60(int a);
    bool FUN_00576d30();
    Obj* FUN_00881510();
    bool FUN_00674d40();
    int FUN_0041ca90();
    Obj* FUN_00671d10();
    Obj* FUN_00680020();
    void FUN_00672fc0(int a);
    Obj* FUN_00676140(Obj* a);
    void FUN_00671d30(int a);
    Obj* FUN_00881650();
    bool FUN_009336c0();
    Obj* FUN_009344a0();
    void FUN_00881680(int a);
    void FUN_008c4f10(int a);
    Obj* FUN_00410220(unsigned char a);
    bool FUN_008a6650(int a);
    Obj* FUN_005e3fc0();
    void FUN_00994ef0(int a);
    void FUN_008a6730(Obj* a);
    bool FUN_00493bb0();
    void FUN_0097f9c0(Obj* a);
    Obj* FUN_00422690(Obj* a);
    void FUN_00881620(int a);
    void FUN_009c4c80(Obj* a);
    bool FUN_00440da0();
    void FUN_009b28a0(Obj* a);
    void ProcessCombatTarget(Obj* a);
};
extern Obj* DAT_011dea3c;

}  // namespace fnv_00976680

struct ProcStub
{
    virtual void P_v000();
    virtual void P_v001();
    virtual void P_v002();
    virtual void P_v003();
    virtual void P_v004();
    virtual void P_v005();
    virtual void P_v006();
    virtual void P_v007();
    virtual void P_v008();
    virtual void P_v009();
    virtual void P_v010();
    virtual void P_v011();
    virtual void P_v012();
    virtual void P_v013();
    virtual void P_v014();
    virtual void P_v015();
    virtual void P_v016();
    virtual void P_v017();
    virtual void P_v018();
    virtual void P_v019();
    virtual void P_v020();
    virtual void P_v021();
    virtual void P_v022();
    virtual void P_v023();
    virtual void P_v024();
    virtual void P_v025();
    virtual void P_v026();
    virtual void P_v027();
    virtual void P_v028();
    virtual void P_v029();
    virtual void P_v030();
    virtual void P_v031();
    virtual void P_v032();
    virtual void P_v033();
    virtual void P_v034();
    virtual void P_v035();
    virtual void P_v036();
    virtual void P_v037();
    virtual void P_v038();
    virtual void P_v039();
    virtual void P_v040();
    virtual void P_v041();
    virtual void P_v042();
    virtual void P_v043();
    virtual void P_v044();
    virtual void P_v045();
    virtual void P_v046();
    virtual void P_v047();
    virtual void P_v048();
    virtual void P_v049();
    virtual void P_v050();
    virtual void P_v051();
    virtual void P_v052();
    virtual void P_v053();
    virtual void P_v054();
    virtual void P_v055();
    virtual void P_v056();
    virtual void P_v057();
    virtual void P_v058();
    virtual void P_v059();
    virtual void P_v060();
    virtual void P_v061();
    virtual void P_v062();
    virtual void P_v063();
    virtual void P_v064();
    virtual void Upd104();
    virtual void P_v066();
    virtual void P_v067();
    virtual void P_v068();
    virtual void P_v069();
    virtual void P_v070();
    virtual void P_v071();
    virtual void P_v072();
    virtual void P_v073();
    virtual void P_v074();
    virtual void P_v075();
    virtual void P_v076();
    virtual void P_v077();
    virtual void P_v078();
    virtual void P_v079();
    virtual void P_v080();
    virtual void P_v081();
    virtual void P_v082();
    virtual void P_v083();
    virtual void P_v084();
    virtual void P_v085();
    virtual void P_v086();
    virtual void P_v087();
    virtual void P_v088();
    virtual void P_v089();
    virtual void P_v090();
    virtual void P_v091();
    virtual void Add170(void* a);
    virtual void P_v093();
    virtual void P_v094();
    virtual void P_v095();
    virtual void P_v096();
    virtual void P_v097();
    virtual void P_v098();
    virtual void P_v099();
    virtual void P_v100();
    virtual void P_v101();
    virtual void P_v102();
    virtual void P_v103();
    virtual void P_v104();
    virtual void P_v105();
    virtual void P_v106();
    virtual void P_v107();
    virtual void P_v108();
    virtual void P_v109();
    virtual void P_v110();
    virtual void P_v111();
    virtual void P_v112();
    virtual void P_v113();
    virtual void P_v114();
    virtual void P_v115();
    virtual void P_v116();
    virtual void P_v117();
    virtual void Add1d8(void* a);
    virtual void P_v119();
    virtual void P_v120();
    virtual void P_v121();
    virtual void P_v122();
    virtual void P_v123();
    virtual void P_v124();
    virtual void P_v125();
    virtual void P_v126();
    virtual void P_v127();
    virtual void P_v128();
    virtual void P_v129();
    virtual void P_v130();
    virtual void P_v131();
    virtual void P_v132();
    virtual void P_v133();
    virtual void P_v134();
    virtual void P_v135();
    virtual void P_v136();
    virtual void P_v137();
    virtual void P_v138();
    virtual void P_v139();
    virtual void P_v140();
    virtual void P_v141();
    virtual void P_v142();
    virtual void P_v143();
    virtual void P_v144();
    virtual void P_v145();
    virtual void P_v146();
    virtual void P_v147();
    virtual void P_v148();
    virtual void P_v149();
    virtual void P_v150();
    virtual void P_v151();
    virtual void P_v152();
    virtual void P_v153();
    virtual void P_v154();
    virtual void P_v155();
    virtual void P_v156();
    virtual void P_v157();
    virtual void P_v158();
    virtual void P_v159();
    virtual void P_v160();
    virtual void P_v161();
    virtual void P_v162();
    virtual void P_v163();
    virtual void P_v164();
    virtual void P_v165();
    virtual void P_v166();
    virtual void P_v167();
    virtual void P_v168();
    virtual void P_v169();
    virtual void P_v170();
    virtual void P_v171();
    virtual void P_v172();
    virtual void P_v173();
    virtual void P_v174();
    virtual void P_v175();
    virtual void P_v176();
    virtual void P_v177();
    virtual void P_v178();
    virtual void P_v179();
    virtual void P_v180();
    virtual void P_v181();
    virtual void P_v182();
    virtual void P_v183();
    virtual void P_v184();
    virtual void P_v185();
    virtual void P_v186();
    virtual void P_v187();
    virtual void P_v188();
    virtual void P_v189();
    virtual void P_v190();
    virtual void P_v191();
    virtual void P_v192();
    virtual void P_v193();
    virtual void P_v194();
    virtual void P_v195();
    virtual void P_v196();
    virtual void P_v197();
    virtual void P_v198();
    virtual void P_v199();
    virtual void P_v200();
    virtual void P_v201();
    virtual void P_v202();
    virtual void P_v203();
    virtual void P_v204();
    virtual void P_v205();
    virtual void P_v206();
    virtual void P_v207();
    virtual void P_v208();
    virtual void P_v209();
    virtual void P_v210();
    virtual void P_v211();
    virtual void P_v212();
    virtual void P_v213();
    virtual void P_v214();
    virtual void P_v215();
    virtual void P_v216();
    virtual void P_v217();
    virtual void P_v218();
    virtual void P_v219();
    virtual void P_v220();
    virtual void P_v221();
    virtual void P_v222();
    virtual void P_v223();
    virtual void P_v224();
    virtual void P_v225();
    virtual void P_v226();
    virtual void P_v227();
    virtual void P_v228();
    virtual void P_v229();
    virtual void P_v230();
    virtual void P_v231();
    virtual void P_v232();
    virtual void P_v233();
    virtual void P_v234();
    virtual void P_v235();
    virtual void P_v236();
    virtual void P_v237();
    virtual void P_v238();
    virtual void P_v239();
    virtual void P_v240();
    virtual void P_v241();
    virtual void P_v242();
    virtual void P_v243();
    virtual void P_v244();
    virtual void P_v245();
    virtual void P_v246();
    virtual void P_v247();
    virtual void P_v248();
    virtual void P_v249();
    virtual void P_v250();
    virtual void P_v251();
    virtual void P_v252();
    virtual void P_v253();
    virtual void P_v254();
    virtual void P_v255();
    virtual void P_v256();
    virtual void P_v257();
    virtual void P_v258();
    virtual void P_v259();
    virtual void P_v260();
    virtual void P_v261();
    virtual void P_v262();
    virtual void P_v263();
    virtual void P_v264();
    virtual void P_v265();
    virtual void P_v266();
    virtual void P_v267();
    virtual void P_v268();
    virtual void P_v269();
    virtual void P_v270();
    virtual void P_v271();
    virtual void P_v272();
    virtual void P_v273();
    virtual void P_v274();
    virtual void P_v275();
    virtual void P_v276();
    virtual void P_v277();
    virtual void P_v278();
    virtual void P_v279();
    virtual void P_v280();
    virtual void P_v281();
    virtual void P_v282();
    virtual void P_v283();
    virtual void P_v284();
    virtual void P_v285();
    virtual void P_v286();
    virtual void P_v287();
    virtual void P_v288();
    virtual void P_v289();
    virtual void P_v290();
    virtual void P_v291();
    virtual void P_v292();
    virtual void P_v293();
    virtual void P_v294();
    virtual void P_v295();
    virtual void P_v296();
    virtual void P_v297();
    virtual void P_v298();
    virtual void P_v299();
    virtual void P_v300();
    virtual void P_v301();
    virtual void P_v302();
    virtual void P_v303();
    virtual void P_v304();
    virtual void P_v305();
    virtual void P_v306();
    virtual void P_v307();
    virtual void P_v308();
    virtual void P_v309();
    virtual void P_v310();
    virtual void P_v311();
    virtual void P_v312();
    virtual void P_v313();
    virtual void P_v314();
    virtual void P_v315();
    virtual void P_v316();
    virtual void P_v317();
    virtual void P_v318();
    virtual void P_v319();
    virtual void Add500(void* a, int b);
};
struct BodyStub;
struct BodyStub
{
    void Fca2ad0(int a);
    void Fca1410();
};

namespace fnv_009eb500 {
struct SingletonData
{
    unsigned int FUN_009eb620();
};
struct RandomData
{
    int FUN_00867d20();
    signed char FUN_00867d60();
    int FUN_00867c60();
};
extern "C" SingletonData DAT_011e0e80;
extern "C" RandomData DAT_011de7b8;
}  // namespace fnv_009eb500

// FUN_00c44c90: TaskQueueParallelManager wrapper that forwards a callback
// and one argument to the task queue base class.
typedef void(__cdecl* FUN_00c44d90_t)(void);

struct SoundHandleStub
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    SoundHandleStub();
    ~SoundHandleStub();
    SoundHandleStub& operator=(const SoundHandleStub& rhs);
    bool IsPlaying();
    bool Play(bool abUnk);
};

struct Proc96
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
    virtual void p79();
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void p96();
    virtual void p97();
    virtual void p98();
    virtual void p99();
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
    virtual bool ready();
    float FUN_007df1f0();
};
struct Obj96
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
    virtual bool isActor();
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
    virtual void update(float);
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
    virtual bool destroyed();
    bool FUN_00576d30();
    bool FUN_00440da0();
    bool FUN_00440d80();
    int FUN_00931850();
    Proc96* FUN_008d8520();
    void FUN_0092f190();
    void FUN_00565870();
    int FUN_004f8960();
    void FUN_00407800(int);
};
struct Array96
{
    unsigned int FUN_005de0f0(int);
    unsigned int FUN_005be5c0(int);
    MobileObject* FUN_00968670(unsigned int);
    void FUN_0096aaf0(MobileObject*, int);
};

struct ActorEntity;
struct DetectProcess
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
    virtual bool Check(ActorEntity*);
};
struct DetectComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual bool Check();
};
struct DetectMisc
{
    bool FUN_00705cf0();
};
struct DetectBase
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    DetectComponent component;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    DetectMisc misc;
};
struct ActorEntity
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
    virtual int Active();
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
    virtual bool State(int);
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
    virtual void SetTimer(float);
    virtual float Timer();
    virtual void Reset();
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    int fielda0;
    int fielda4;
    int fielda8;
    int fieldac;
    int fieldb0;
    int fieldb4;
    int fieldb8;
    unsigned char enabled;
    float FUN_005723b0(ActorEntity*, int, int);
    bool FUN_00437bd0();
    DetectBase* Base();
    DetectProcess* Process();
    unsigned char FUN_00493bb0();
    int FUN_008a0d10(int, ActorEntity*, bool*, unsigned char, int, int, bool*);
    bool IsHostileTo(ActorEntity*, int, int*, int);
    bool FUN_008bc700(ActorEntity*);
    bool FUN_008a78f0(int);
    void FUN_008c8bb0(int);
    void FUN_00966f20(ActorEntity*, bool, int);
    void FUN_00967350(ActorEntity*);
};
struct DetectArray
{
    unsigned int Count(int);
    unsigned int Head(int);
    ActorEntity* Item(unsigned int);
};
struct DetectTime
{
    float Delta();
};
extern DetectTime DAT_011f6394;
struct DetectLoad
{
    bool FUN_0047c850();
};
extern DetectLoad* DAT_011de45c;
struct DetectSetting
{
    float* Value();
};
extern DetectSetting DAT_011ccf94, DAT_011d13c8;
struct DetectionLists
{
    int field00;
    DetectArray actors;
    void FUN_0096e3c0(ActorEntity*);
    void UpdateDetection();
};
extern DetectionLists DAT_011e0e80;

namespace fnv_0096d810 {

class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeContext, bool abPush, const char* apFile, int aiLine);
    ~AutoMemContext();
    int aiMemoryContext;
};

struct FUN_0084d030_timer
{
    float FUN_0084d030();
};
extern FUN_0084d030_timer DAT_011f6394;

unsigned char __cdecl FUN_00525420();
int& __fastcall FUN_0043d4d0(int* apValue);

}  // namespace fnv_0096d810

namespace fnv_0096db30 {
struct Obj96;
struct Proc96
{
    float FUN_007df1f0();
    void UpdateSelectionTimer(Obj96*);
};
struct Obj96
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
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
    virtual void V60();
    virtual void V61();
    virtual void V62();
    virtual void V63();
    virtual bool V64();
    virtual void V65();
    virtual void V66();
    virtual void V67();
    virtual void V68();
    virtual void V69();
    virtual void V70();
    virtual void V71();
    virtual void V72();
    virtual void V73();
    virtual void V74();
    virtual void V75();
    virtual void V76();
    virtual void V77();
    virtual void V78();
    virtual void V79();
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
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual bool V136();
    virtual bool V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210(float, bool);
    bool FUN_00576d30();
    Proc96* FUN_008d8520();
};
struct Array96
{
    unsigned int FUN_005de0f0(int);
    unsigned int FUN_005be5c0(int);
    Obj96* FUN_00968670(unsigned int);
};
struct Global96
{
    Array96* FUN_00717e50();
};
extern Global96 DAT_011e0e80;
struct TimeGlobal
{
    unsigned int GetTimeStamp();
};
extern TimeGlobal g_timeGlobal;
struct Target96
{
    void FUN_0096db30(float delta, bool flag, int level);
};
}  // namespace fnv_0096db30

struct Controller96
{
    unsigned int FUN_0084e3a0();
};
struct Actor96
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
    virtual Controller96* GetController();
    BaseProcess* FUN_008d8520();
};
struct EntryArray96
{
    unsigned int FUN_0055b980();
    Actor96* FUN_00968670(unsigned int);
};
struct FUN_0096a2d0
{
    Actor96* data;
    FUN_0096a2d0* next;
    FUN_0096a2d0();
    void FUN_005ae3d0(Actor* const&);
};
struct Target96
{
    int unk00;
    EntryArray96 entries;
    FUN_0096a2d0* FUN_0096f450(unsigned int, Actor96*);
};

namespace fnv_0096f600 {
struct ExtraFollower
{
    int f0;
    int f4;
    int f8;
    BSSimpleList<TESObjectREFR*>* pNext;
};
struct EffectSetting
{
    void SetLight(TESObjectLIGH*);
};
struct TopicInfoArray
{
    unsigned int FUN_005be5c0(int);
    Actor* FUN_00968670(unsigned int);
};
struct FUN_0041ca90
{
    int get();
};
struct FUN_009336c0_shell
{
    bool FUN_009336c0();
};

}  // namespace fnv_0096f600

namespace fnv_009715c0 {
struct Mob9715
{
    virtual void m0();
};
struct Obj9715;
struct X9715
{
    bool FUN_00425fd0();
};
struct W9715
{
    X9715* FUN_008d6f30();
    int FUN_00575d70();
};
struct Z9715
{
    W9715* FUN_00559450();
};
struct Proc9715
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
    virtual void EnterCombatV(Obj9715*, Obj9715*, bool, bool, void*, bool, bool, bool, bool, bool, bool, bool, void*);
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
    virtual int GetNumV();
    virtual void ModNumV(int);
};
struct Obj9715 : Mob9715
{
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
    virtual bool IsActorV();
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
    virtual bool V193();
    X9715* FUN_008d6f30();
    int FUN_00575d70();
    bool FUN_00493bb0();
    float FUN_005723b0(void*, int, int);
    Proc9715* FUN_008d8520();
    Z9715* FUN_00568e50();
};
extern Obj9715* DAT_011dea3c;
extern float DAT_01016970;
}  // namespace fnv_009715c0

struct FUN_009722e0_member
{
    BSSimpleList<Actor*>* GetActorList();
};

struct FUN_009722e0_shell
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
    BSSimpleList<FUN_009722e0_member*>* pList50;
    BSSimpleList<FUN_009722e0_member*>* pList54;
    bool IsActorInOtherList(Actor* pActor, FUN_009722e0_member* apBoundObject);
};

namespace fnv_00972aa0 {
struct S_972aa0_Actor
{
    void FUN_0047eb90(int a);
};
struct S_972aa0_ActorNode
{
    bool FUN_008256d0();
    S_972aa0_Actor** FUN_006815c0();
    S_972aa0_ActorNode* FUN_00726070();
};
struct S_972aa0_Crime
{
    unsigned int FUN_0084e3a0();
    S_972aa0_ActorNode* GetField38();
};
struct S_972aa0_Lists
{
    bool IsActorInOtherList(S_972aa0_Actor* actor, S_972aa0_Crime* crime);
};
extern S_972aa0_Lists DAT_011e0e80;

}  // namespace fnv_00972aa0

class ArrowProjectile : public Projectile
{
};

// Remove (and delete) every list entry whose level equals the given level.

namespace fnv_009723f0 {

class ProcessListsEx : public ProcessLists
{
  public:
    void UpdateCrimeLists();
};

}  // namespace fnv_009723f0

namespace fnv_0096dcb0 {
extern "C" char DAT_011dea3c;
extern "C" char DAT_011de7b8;
struct State96
{
    int FUN_0041ca90();
};
struct Actor96;
struct Slots64
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
};
struct ProcOwner96 : Slots64
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual Actor96* owner();
};
struct Proc96 : ProcOwner96
{
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c50();
    virtual void c51();
    virtual void c52();
    virtual void c53();
    virtual void c54();
    virtual void c55();
    virtual void c56();
    virtual void c57();
    virtual void c58();
    virtual void c59();
    virtual void c60();
    virtual void c61();
    virtual void c62();
    virtual void c63();
    virtual State96* state();
    float FUN_007df1f0();
};
struct ActorValid96 : Slots64
{
    virtual bool valid();
};
struct Actor96 : ActorValid96
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void b46();
    virtual void b47();
    virtual void b48();
    virtual void b49();
    virtual void b50();
    virtual void b51();
    virtual void b52();
    virtual void b53();
    virtual void b54();
    virtual void b55();
    virtual void b56();
    virtual void b57();
    virtual void b58();
    virtual void b59();
    virtual void b60();
    virtual void b61();
    virtual void b62();
    virtual void b63();
    virtual void b64();
    virtual void b65();
    virtual void b66();
    virtual void b67();
    virtual void b68();
    virtual void b69();
    virtual void b70();
    virtual void b71();
    virtual void b72();
    virtual void b73();
    virtual void b74();
    virtual void b75();
    virtual void b76();
    virtual void b77();
    virtual void b78();
    virtual void b79();
    virtual void b80();
    virtual void b81();
    virtual void b82();
    virtual void b83();
    virtual void b84();
    virtual void b85();
    virtual void update(float);
    Proc96* FUN_008d8520();
    bool FUN_00440d80();
    bool FUN_00440da0();
    bool FUN_00493bb0();
    bool FUN_008842c0();
};
struct FUN_0096a2d0
{
    char data[8];
    FUN_0096a2d0();
    ~FUN_0096a2d0();
    Actor96** FUN_006815c0();
    FUN_0096a2d0* FUN_00726070();
    void FUN_005ae3d0(Actor96**);
    void FUN_0063f7b0();
    void FUN_00470470();
    void* FUN_004702f0(unsigned);
};
}  // namespace fnv_0096dcb0

template <int N> struct Slot970
{
};
template <int N> struct ProcessSlots970 : ProcessSlots970<N - 1>
{
    virtual void pad(Slot970<N>*);
};
template <> struct ProcessSlots970<0>
{
};
template <> struct ProcessSlots970<211> : ProcessSlots970<210>
{
    virtual void SetCount(int);
};
template <int N> struct ActorSlots970 : ActorSlots970<N - 1>
{
    virtual void pad(Slot970<N>*);
};
template <> struct ActorSlots970<0>
{
};
template <> struct ActorSlots970<65> : ActorSlots970<64>
{
    virtual bool IsActor();
};
template <> struct ActorSlots970<140> : ActorSlots970<139>
{
    virtual bool Check(int);
};

struct CombatActor;
struct FactionView;
struct ProcessView
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
    virtual void Reset(bool);
};
struct TargetData
{
    CombatActor* Target();
};
struct PackageView
{
    TargetData* Data();
};
struct FactionView
{
    bool Enemy() const;
    void SetEnemy(bool);
};
struct FactionChanges
{
    int unk00;
    int unk04;
    int unk08;
    void* list;
};
struct ExtraView
{
    void Clear(CombatActor*);
    FactionChanges* Changes();
};
struct BaseFactionView
{
    void* List();
};
struct ActorBaseView
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
    BaseFactionView factions;
};
struct CombatActor
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
    virtual bool HasFactions();
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
    virtual void StopTarget(CombatActor*);
    bool HasTarget(CombatActor*);
    bool HasPackage();
    PackageView* Package();
    void Stop(int);
    ProcessView* Process();
    void Reset();
    ExtraView* Extra();
    ActorBaseView* Base();
    unsigned Gather(FactionView**, unsigned, void*, void*);
};

namespace fnv_00973710 {
struct ActorX;
struct Process;
struct Combat
{
    ActorX* FUN_004030b0();
    bool FUN_009818b0();
};
struct Process
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
    virtual int detect(ActorX*, int);
};
struct ActorX
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
    virtual bool isActorXor();
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
    virtual bool isDead(int);
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
    virtual Combat* combat();
    bool IsPlayerTeammate();
    bool GetDisabled();
    bool FUN_00437bd0();
    void SetByteAt66c(char);
    unsigned char GetByteAtOffset();
    float FUN_005723b0(ActorX*, int, int);
    bool FUN_00493bb0();
    bool FUN_008a61b0();
    ActorX* FUN_00881650();
    Process* FUN_008d8520();
    bool IsHostileTo(ActorX*, int, float*, int);
    void FUN_008c8bb0(int);
};
typedef BSSimpleList<Actor*> List;
struct Setting
{
    int* FUN_0043d4d0();
};
extern ActorX* _g_thePlayer;
}  // namespace fnv_00973710

namespace fnv_00970810 {

extern "C" char DAT_011e0e80;

}  // namespace fnv_00970810

extern float DAT_01016970;
void FUN_00970ee0();

namespace fnv_0096eb40 {
struct Pkg;
struct Ref;
struct Proc;
struct Proc
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
    virtual Pkg* GetPkg();
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
    virtual bool Is360();
    virtual void Set364(int);
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
    virtual float Get69c();
    int f45cd60();
};
struct Ref
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual ~Ref();
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
    virtual void HandleInteger(int);
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual bool IsA();
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
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual bool Is160();
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
    virtual bool Is224();
    virtual void v228();
    virtual bool Is22c(int);
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
    virtual void Do260();
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
    virtual void Do324(int, int, int);
};

struct Pkg
{
    int f41ca90();
};
struct Inv;
struct Node;
struct Inv
{
    Node* f41df90();
    void f41de40(int);
    void f41dfd0();
};
struct Node
{
    Ref** Item();
    Node* Next();
    bool f8256d0();
    void f63f7b0();
};
struct Lock
{
    void Enter(int);
    void Leave();
    bool TryEnter();
};

}  // namespace fnv_0096eb40
