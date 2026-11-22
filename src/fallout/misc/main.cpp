// fallout/misc/main.cpp: Interface, SomeClass, BSFadeNodeCuller, Mover and more (3 functions)
#include "main.h"

struct Node
{
    char pad[8];
    int v;
};

struct BGSAddonNode;
struct Arr86
{
    void SetAt(unsigned int, BGSAddonNode*&);
};
struct Idx86
{
    unsigned int FUN_00877a50(unsigned int&);
};

namespace fnv_0086bbd0 {
struct BGSAddonNode;
struct Arr86
{
    void SetAt(unsigned int, BGSAddonNode*&);
};
struct Idx86
{
    unsigned int FUN_00877a50(unsigned int&);
};
}  // namespace fnv_0086bbd0

class BGSLoadGameBuffer;

class Interface
{
  public:
    static void __cdecl PrintDebugMessage(BGSLoadGameBuffer*);
};

class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

class GlobalObject_0045cf30
{
};

namespace fnv_0086d490 {
struct NiPoint3_local
{
    int x, y, z;
};

class TESObjectREFR
{
  public:
    void SetReferencePosition(NiPoint3_local aPoint);
};

}  // namespace fnv_0086d490

int __cdecl FUN_004da670(int, int);
int __cdecl sprintf(char*, const char*, ...);
__declspec(dllimport) int __stdcall MessageBoxA(void*, const char*, const char*, unsigned int);
__declspec(dllimport) void __stdcall ExitProcess(unsigned int);

// Calls FUN_004da670 with pThis[2] and pThis[3]; on failure formats an error message with FUN_0086d580, shows a MessageBoxA and calls ExitProcess(0).
// @f3 0x006e4240 (community match, verified in this file)
extern char DAT_0106f500[];
int __cdecl FUN_00490420(int, int);

// pdb: Main_InitArchive | Main.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: Main::InitRenderer)
void __fastcall FUN_0086d500(int* pThis)
{
    char buf[512];
    if (!FUN_00490420(pThis[2], pThis[3]))
    {
        sprintf(buf, "Failed to initialize renderer.\n%s", DAT_0106f500);
        MessageBoxA((void*)0, buf, "Fallout", 0);
        ExitProcess(0);
    }
}


class NiGeometryData;

class NiScreenElementsData
{
  public:
    bool FUN_00a87ae0(int, int, int);
};

class NiGeometry
{
  public:
    NiGeometryData* FUN_005495f0(void);
};

namespace fnv_0086e420 {
struct NiGeometryData;
struct NiGeometry
{
    NiGeometryData* FUN_005495f0();
};
struct NiScreenElementsData
{
    bool SetRectangleBounds(int, float, float, float, float);
};
}  // namespace fnv_0086e420

namespace fnv_0086e460 {
struct NiScreenElementsData
{
    bool SetRectangleBounds(int, unsigned short, float, float, float, float);
};
struct NiGeometry
{
    NiScreenElementsData* FUN_005495f0();
};
}  // namespace fnv_0086e460

namespace fnv_0086e4b0 {
class NiGeometryData;

class NiGeometry
{
  public:
    NiGeometryData* FUN_005495f0();
};

class NiScreenElementsData
{
  public:
    void FUN_00a87900();
};

}  // namespace fnv_0086e4b0

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

namespace fnv_0086e540 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

}  // namespace fnv_0086e540

namespace fnv_0086e560 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

}  // namespace fnv_0086e560

namespace fnv_0086e580 {
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};

}  // namespace fnv_0086e580

namespace fnv_0086e5a0 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

}  // namespace fnv_0086e5a0

namespace fnv_0086e5c0 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

}  // namespace fnv_0086e5c0

namespace fnv_0086e5e0 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

}  // namespace fnv_0086e5e0

namespace fnv_0086e600 {
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};

}  // namespace fnv_0086e600

extern NiPointer<NiNode> g_011d86bc;

class StartMenu
{
  public:
    enum Flag
    {
    };
    bool IsFlagSet(Flag);
};

namespace fnv_0086f260 {
struct TG
{
};
struct BGSLoadFormBuffer
{
    void FUN_008a8150(unsigned char);
};
struct GameTimerRecord
{
    void Update();
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct TESObjectREFR
{
    unsigned int GetFlags();
};
extern TG g_timeGlobal;
extern bool DAT_011dea2b;
extern float DAT_011dea30;
extern TESObjectREFR DAT_011f2250;
bool __cdecl FUN_00525420();
}  // namespace fnv_0086f260

extern float(__cdecl* DAT_011f91f0)(int);

namespace fnv_0086f390 {

struct PlayerCharacter
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
    virtual bool V8B(int);
    static bool UpdatePlayerStatus();
    bool FUN_007d1360();
};
struct TESObjectREFR
{
    unsigned int GetFlags();
};
struct TimeGlobal
{
    float GetSecondsPassed();
};
struct Interface
{
    enum enumMenus
    {
        MENU_DUMMY
    };
    static bool IsMenuActive(enumMenus, unsigned int);
};
struct HotkeyWheelDisplay
{
    void FUN_00a23010();
    void FUN_00a257c0(float);
    void FUN_00a253d0();
};
extern PlayerCharacter* pPlayer;
extern TESObjectREFR DAT_011f2250;
extern TimeGlobal g_timeGlobal;
HotkeyWheelDisplay* __cdecl FUN_007fdf30();
bool __cdecl FUN_00709bc0();
}  // namespace fnv_0086f390

class BSAudio
{
  public:
    static BSAudio* __cdecl GetSingleton();
    void Update(bool);
};

class TES;
extern TES* g_TES;

struct GlobalObject2_0040c150
{
    int* Int(void);
};

extern GlobalObject2_0040c150 g_011c3ea4;
extern bool DAT_011dea2b;
extern bool DAT_011dea2d;
extern bool DAT_011dea2e;
extern PlayerCharacter* pPlayer;
extern int DAT_011e0e80;
extern int DAT_011e0fe0;
extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;

void __fastcall FUN_0096eb40(void* pThis);

void __cdecl FUN_007027e0();
void __cdecl FUN_00702810();
void __cdecl FUN_00702840();

namespace fnv_008705d0 {
struct GlobalObject2_0040c150
{
    int* Int();
};

extern GlobalObject2_0040c150 g_011c3ea4;

void __cdecl FUN_00552570();

}  // namespace fnv_008705d0

namespace fnv_00870610 {

class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

class TaskQueueInterface
{
  public:
    static TaskQueueInterface* __cdecl GetSingleton(void);
    void ProcessTaskQueue(void);
};

extern GlobalObject2_0040c150 g_011c3ea4;

void* __cdecl FUN_004b7210(void);
void __stdcall FUN_00870680(void*);

}  // namespace fnv_00870610

void __cdecl FUN_00706320(int);

// If the byte at offset 0x4cc is set, calls FUN_00706320(0) and clears that byte.
// @f3 0x00bb6d80 (community match, verified in this file)
void operator delete(void* p);

struct Obj
{
    int unk00;
};

struct Holder
{
    int unk00;
    Obj* obj04;
    int unk08;
    int unk0c;
};

FNV_STATIC_ASSERT(offsetof(Holder, obj04) == 4);
FNV_STATIC_ASSERT(offsetof(Holder, unk08) == 8);
FNV_STATIC_ASSERT(offsetof(Holder, unk0c) == 0xc);

void __stdcall FUN_00870680(void* param_1)
{
    Holder* p = (Holder*)param_1;
    if (p->obj04)
    {
        delete p->obj04;
    }
    p->obj04 = 0;
    p->unk08 = 0;
    p->unk0c = 0;
}


namespace fnv_008706b0 {
struct BSRenderedTexture;

struct P3
{
    float x, y, z;
};
struct ShadowSceneNode
{
    bool FUN_00870770();
    void FUN_00870790(P3);
};
struct NiNode
{
    const P3& FUN_0045bb80() const;
};
struct BSFaceGenAnimationData : public NiNode
{
};
struct BSFaceGenNiNode
{
    BSFaceGenAnimationData* GetAnimationData();
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* GetShadowSceneNodeForIndex(int);
};
struct Interface
{
    enum enumMenus
    {
        MENU_DUMMY
    };
    static bool IsMenuActive(enumMenus, unsigned int);
};
BSFaceGenNiNode* __cdecl FUN_0045c670();
}  // namespace fnv_008706b0

struct NiStream;
struct blob12
{
    char b[12];
};

struct NiNode871
{
    unsigned int FUN_00453470();
};
struct GO871
{
    operator NiNode871*() const;
};
extern GO871 g_011c7810;

namespace fnv_00871a10 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

}  // namespace fnv_00871a10

namespace fnv_00871c90 {
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};
struct HotkeyWheelDisplay
{
    void FUN_00a23010();
};
struct GameTimerRecord
{
    void Enable();
};
struct GlobalObject_0045cf30
{
};
struct TimeGlobal
{
};
extern GlobalObject_0045cf30 g_011deed8;
extern TimeGlobal g_timeGlobal;
HotkeyWheelDisplay* FUN_007fdf30();
void __fastcall FUN_00a253d0(HotkeyWheelDisplay*);
}  // namespace fnv_00871c90

struct O872
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
    virtual int vf();
};
struct H872
{
    int pad;
    operator O872*() const;
};
struct S872
{
    char p[0x30];
    H872 h[1];
    int FUN_00872370(unsigned int i);
};

namespace fnv_008723d0 {
struct O872
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
    virtual int vf();
};
struct H872
{
    int pad;
    operator O872*() const;
};
struct S872
{
    char p[0x30];
    H872 h[1];
    int FUN_008723d0(unsigned int i);
};
}  // namespace fnv_008723d0

namespace fnv_00874ac0 {

struct StrG
{
    operator const char*() const;
};
extern StrG g_011deb38;
enum BSRENDERSTATE_LOCK
{
    BSRS_LOCK_DUMMY
};
struct BSRenderStateManager
{
    static void SetColorWriteMask(unsigned int, BSRENDERSTATE_LOCK);
};
struct BSRenderedTexture
{
    static void EndAllAndResetRendererState();
};
struct KFModel
{
    void* GetControllerSequence();
    void FUN_00800f30(const char*, int, int, int, int, int);
};
struct ShadowLightData : public KFModel
{
};
struct Interface
{
    static ShadowLightData* GetVATSEffect();
};
void __cdecl FUN_004eced0(int);
}  // namespace fnv_00874ac0

struct BSRenderedTexture;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct RgbaColor;
struct NiPoint2;
struct NiScreenElements;
struct NiTexture;
struct GraphicsRenderer;
struct blob16
{
    char b[16];
};
struct ImageSpaceManager
{
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ImageSpaceEffect* GetEffect(int);
    void AddEffect(int, ImageSpaceEffect*);
    bool IsEffectActive(int);
    void SetupEffects();
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*,
                      bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void BeginParamModifiers();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(RgbaColor*);
    void ApplyTintColorParamModifierWeather(RgbaColor*);
    void SetFadeColorParamModifier(RgbaColor*);
    void ApplyFadeColorParamModifierWeather(RgbaColor*);
    void SetBlurRadiusParamModifier(float);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(struct blob16);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    BSRenderedTexture* GetDepthRenderedTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void InitGeometry();
    void ShutdownEffects();
    void ShutdownGeometry();
    void PrepareEndOfFrameEffects();
    void* __vecDelDtor(unsigned int);
    BSRenderedTexture* m_pCurrentRenderedTexture;
    char pEffectList[16];
    char m_kBlendedParameterData[152];
    void* m_pCurrentModifierParameterData;
    void* m_pPreviousModifierParameterData;
    char m_kModifierParameterData[304];
    bool m_bEndOfFrameEffectsEnabled;
    char _pad_1e5[3];
    int m_iEndOfFrameEffectCount;
    int m_eEndOfFrameEffect;
    char m_pMenuBackgroundScreenGeometry[4];
    char m_pMenuBackgroundScreenElementsData[4];
    char m_pMenuBackgroundScreenElements[4];
    bool m_bPartialRenderEnabled;
    char _pad_1fd[3];
    char m_pPartialRenderScreenElements[4];
    char m_kDepthTexture[16];
    char m_kModifierColor[16];
    char m_kPartialRenderColor[16];
    float m_fPartialRenderBlend;
    char m_kAccumulatedColor[16];
    char m_kWeatherFadeColor[16];
    float m_fFadeColorAlpha;
    float m_fDoubleVisionStrength;
    float m_fWeatherBlurRadius;
    float m_fWeatherDoubleVisionStrength;
    float m_fAdditionalImageSpaceValue;
    float m_fRadialBlurStrength;
    float m_fRadialBlurRampUp;
    float m_fRadialBlurStart;
    float m_fRadialBlurRampDown;
    float m_fRadialBlurDownStart;
    float m_fWeatherRadialBlurStrength;
    float m_fWeatherRadialBlurRampUp;
    float m_fWeatherRadialBlurStart;
    float m_fWeatherRadialBlurRampDown;
    float m_fWeatherRadialBlurDownStart;
    char m_kRadialBlurCenter[8];
    char m_kWeatherRadialBlurCenter[8];
    float m_fDepthOfFieldStrength;
    float m_fDepthOfFieldMaskConstant;
    float m_fDepthOfFieldDistance;
    float m_fDepthOfFieldRange;
    float m_fDepthOfFieldEffectStrength;
    float m_fDepthOfFieldEffectDistance;
    float m_fDepthOfFieldEffectRange;
    float m_fDepthOfFieldMaskValue;
    int m_eDepthOfFieldMode;
    int m_eDepthOfFieldTargetMode;
    bool m_bDepthOfFieldUsesObject;
    bool m_bMenuBackgroundBlendEnabled;
    char _pad_2ce[2];
    float m_fBlurRadius;
    float m_fRadialBlurTransition;
    float m_fRadialBlurStartValue;
    float m_fRadialBlurDistance;
    float m_fRadialBlurRange;
    char m_kRadialBlurOrigin[8];
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
};
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];

struct NiRenderTargetGroup;
struct BSRenderedTexture
{
    NiRenderTargetGroup* GetGroup(void);
};

ImageSpaceManager* __cdecl FUN_004e3270(void);
void* __cdecl FUN_004a0e90(void);
void __cdecl FUN_00b6b8d0(unsigned int, NiRenderTargetGroup*);

namespace fnv_00874b90 {
struct BSRenderedTexture;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct RgbaColor;
struct NiPoint2;
struct NiScreenElements;
struct NiTexture;
struct GraphicsRenderer;
struct blob16
{
    char b[16];
};
struct ImageSpaceManager
{
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ImageSpaceEffect* GetEffect(int);
    void AddEffect(int, ImageSpaceEffect*);
    bool IsEffectActive(int);
    void SetupEffects();
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*,
                      bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void BeginParamModifiers();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(RgbaColor*);
    void ApplyTintColorParamModifierWeather(RgbaColor*);
    void SetFadeColorParamModifier(RgbaColor*);
    void ApplyFadeColorParamModifierWeather(RgbaColor*);
    void SetBlurRadiusParamModifier(float);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(struct blob16);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    BSRenderedTexture* GetDepthRenderedTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void InitGeometry();
    void ShutdownEffects();
    void ShutdownGeometry();
    void PrepareEndOfFrameEffects();
    void* __vecDelDtor(unsigned int);
    BSRenderedTexture* m_pCurrentRenderedTexture;
    char pEffectList[16];
    char m_kBlendedParameterData[152];
    void* m_pCurrentModifierParameterData;
    void* m_pPreviousModifierParameterData;
    char m_kModifierParameterData[304];
    bool m_bEndOfFrameEffectsEnabled;
    char _pad_1e5[3];
    int m_iEndOfFrameEffectCount;
    int m_eEndOfFrameEffect;
    char m_pMenuBackgroundScreenGeometry[4];
    char m_pMenuBackgroundScreenElementsData[4];
    char m_pMenuBackgroundScreenElements[4];
    bool m_bPartialRenderEnabled;
    char _pad_1fd[3];
    char m_pPartialRenderScreenElements[4];
    char m_kDepthTexture[16];
    char m_kModifierColor[16];
    char m_kPartialRenderColor[16];
    float m_fPartialRenderBlend;
    char m_kAccumulatedColor[16];
    char m_kWeatherFadeColor[16];
    float m_fFadeColorAlpha;
    float m_fDoubleVisionStrength;
    float m_fWeatherBlurRadius;
    float m_fWeatherDoubleVisionStrength;
    float m_fAdditionalImageSpaceValue;
    float m_fRadialBlurStrength;
    float m_fRadialBlurRampUp;
    float m_fRadialBlurStart;
    float m_fRadialBlurRampDown;
    float m_fRadialBlurDownStart;
    float m_fWeatherRadialBlurStrength;
    float m_fWeatherRadialBlurRampUp;
    float m_fWeatherRadialBlurStart;
    float m_fWeatherRadialBlurRampDown;
    float m_fWeatherRadialBlurDownStart;
    char m_kRadialBlurCenter[8];
    char m_kWeatherRadialBlurCenter[8];
    float m_fDepthOfFieldStrength;
    float m_fDepthOfFieldMaskConstant;
    float m_fDepthOfFieldDistance;
    float m_fDepthOfFieldRange;
    float m_fDepthOfFieldEffectStrength;
    float m_fDepthOfFieldEffectDistance;
    float m_fDepthOfFieldEffectRange;
    float m_fDepthOfFieldMaskValue;
    int m_eDepthOfFieldMode;
    int m_eDepthOfFieldTargetMode;
    bool m_bDepthOfFieldUsesObject;
    bool m_bMenuBackgroundBlendEnabled;
    char _pad_2ce[2];
    float m_fBlurRadius;
    float m_fRadialBlurTransition;
    float m_fRadialBlurStartValue;
    float m_fRadialBlurDistance;
    float m_fRadialBlurRange;
    char m_kRadialBlurOrigin[8];
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
};
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];

struct StrG
{
    operator const char*() const;
};
extern StrG g_011ded3c;
enum BSRENDERSTATE_LOCK
{
    BSRS_LOCK_DUMMY
};
struct BSRenderStateManager
{
    static void SetDepthBufferEnabled(bool, BSRENDERSTATE_LOCK);
    static void SetColorWriteMask(unsigned int, BSRENDERSTATE_LOCK);
};
void __cdecl FUN_004eced0(int);
}  // namespace fnv_00874b90

struct _Fake_FUN_008750e0
{
    char pad[0x1e4];
    NiPoint3 kIntersectionOffset;
    void FUN_008750e0(NiPoint3 a_kOffset);
};

namespace fnv_00876d20 {
class StartMenu
{
  public:
    char const* GetMenuTitle(void);
};

class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

}  // namespace fnv_00876d20

namespace fnv_00877430 {

struct StrG
{
    operator const char*() const;
};
extern StrG g_011ded3c;
extern bool DAT_011dea29;
struct BSRenderedTexture;
struct BSTextureManager
{
    void AddRenderedTexture();
};
struct ImageSpaceManager
{
    static ImageSpaceManager* FUN_004e3270();
    void FUN_007123f0(float);
    void FUN_007123a0(int);
};
BSTextureManager* __stdcall FUN_004a0ea0(const char*);
}  // namespace fnv_00877430

struct Controls;

Controls* __cdecl FUN_007fdf30();

namespace fnv_0086fbe0 {
struct TES
{
    int FindCellAtPosition(NiPoint3 const*, bool);
    TESWorldSpace* GetHitSound();
    bool FUN_00451530();
};
struct PC7d;
extern PC7d* g_thePlayer;
extern TES* g_TES;
extern bool DAT_011dea2b;
}  // namespace fnv_0086fbe0

struct Flt
{
    operator unsigned int() const;
};
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};

namespace fnv_008749b0 {
struct NiRenderer;
struct BSRenderedTexture;
struct BSTextureManager
{
    BSRenderedTexture* CreateRenderTargetTexture(NiRenderer*, int, unsigned int, BSRenderedTexture*, unsigned int);
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct Flt
{
    operator unsigned int() const;
};
struct KFModel
{
    void* GetControllerSequence();
};
struct VATSEffect
{
    bool FUN_00874aa0();
    void FUN_00800f30(unsigned int, int, int, int, int, int);
};
struct Interface
{
    static VATSEffect* __cdecl GetVATSEffect();
};
NiRenderer* __cdecl FUN_0043c4b0();
BSTextureManager* __stdcall FUN_004a0ea0();
extern NP_0081c630 g_011deb38;

}  // namespace fnv_008749b0

struct Arr
{
    unsigned int GetSize(void);
    unsigned int* GetAt(int);
};

struct SomeClass
{
    int m_ucUnknownByte[0xad4 / 4];
    Arr m_aiIndexedValues;
    int FUN_0086bb70(unsigned int value);
};

void* DAT_011f6e08;

extern double(__cdecl* DAT_011f9134)(void*);

struct GlobalObject_00633c90
{
    GlobalObject_00633c90& operator=(void*);
};

extern NiPointer<NiNode> g_011d86bc;

// Clears the three global objects by assigning null to g_011d86bc, g_011d86a8 and g_011d8690.
// @f3 0x006e12f0 (community match, verified in this file)
struct Receiver799 { void FUN_006e1120(int index); };
// pdb: BGSSaveLoadQueuedSubBufferMap::LoadAllQueuedSubBuffers | BGSLoadGameSubBuffer.obj | fnv360_0822_retail, call_gap, low
void __fastcall FUN_0086beb0(void* self)
{
    Receiver799* receiver = static_cast<Receiver799*>(self);
    receiver->FUN_006e1120(0);
    receiver->FUN_006e1120(1);
    receiver->FUN_006e1120(2);
}


struct FUN_0086bf40
{
    void __thiscall FUN_0086c880();
    void* __thiscall DeleteThis(unsigned int flags);
};

extern int DAT_011dea18;

namespace fnv_0086d580 {

}  // namespace fnv_0086d580

class NiAVObject;
extern unsigned int(__cdecl* DAT_011f91ec)(NiAVObject*);

namespace fnv_0086efe0 {
struct TESWorldSpace
{
    enum PARENT_USE_FLAG
    {
        USE_LAND = 1
    };
    TESWorldSpace* GetParentWorld(PARENT_USE_FLAG flag);
};
struct TES
{
    TESWorldSpace* GetParentWorldSpace();
};
struct ActorS
{
    TESObjectCELL* GetParentCell();
};
struct PC7d : ActorS
{
};
extern TES* g_TES;
extern PC7d* g_thePlayer;
bool __cdecl FUN_00525420();

}  // namespace fnv_0086efe0

class BGSAcousticSpace;

namespace fnv_0086fc60 {
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

extern bool DAT_011dea2b;
extern bool DAT_011dea2c;
extern bool DAT_011dea2d;
extern float DAT_011dea30;
struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011c3ea4;
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
extern Twin_0084d030 g_timeGlobal;
struct ProcessListsH
{
    void FUN_009746c0(float afTimeDelta);
    void FUN_00974420(float afTimeDelta);
};
extern ProcessListsH DAT_011e0e80;
class TES
{
  public:
    void FUN_00453550(float afTimeDelta);
    void FUN_004537c0();
};
extern TES* g_TES;
}  // namespace fnv_0086fc60

struct HWND__;
extern "C" __declspec(dllimport) HWND__* __stdcall GetForegroundWindow();
struct Controls
{
    int FUN_00711e00();
};
Controls* __cdecl FUN_007fdf30();
int __cdecl FUN_004dc1f0();
int __cdecl FUN_004dc200();

namespace fnv_008727d0 {

struct BSFaceGenAnimationData;
struct ShadowSceneNode
{
    bool FUN_005f9ad0();
    void SetCreatureType(unsigned char);
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* GetShadowSceneNodeForIndex(int);
};
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};
struct WaterZoneManager
{
    int m_uiPathPointIndex;
    void FUN_004e1bc0(BSFaceGenAnimationData* data, ShadowSceneNode* scene);
    static void FUN_00872930(int index);
};
struct TES
{
    TESObjectCELL* IsCellInterior();
    WaterZoneManager* GetActorScale();
};
struct FUN_004e2120_s
{
    void f(bool);
};
struct FUN_004e2190_shell
{
    FUN_004e2120_s* FUN_004e2190();
};
struct MTRenderingSystem_Helper
{
    void FUN_00ba30f0(int, int);
    void FUN_00ba3130(int, int);
};
BSFaceGenAnimationData* __cdecl FUN_00524c90();
extern ProcessLists g_011c7adc;
extern FUN_004e2190_shell* g_osGlobals;
extern TES* g_TES;

}  // namespace fnv_008727d0

struct GlobalObjectO2_00a7b610
{
};

class BSFadeNodeCuller
{
  public:
    GlobalObjectO2_00a7b610* FUN_00872ef0();
};

namespace fnv_00872f00 {
struct BSFadeNodeCuller
{
    void __thiscall FUN_00872f30();
    void* __thiscall FUN_00872f00(unsigned int flags);
};

void __cdecl _Deallocate(void*);

}  // namespace fnv_00872f00

namespace fnv_00874690 {
class GlobalObject_00633c90
{
  public:
    void* operator->() const;
};

GlobalObject_00633c90 g_011c7840;

}  // namespace fnv_00874690

namespace fnv_008746b0 {
struct GlobalObject_00633c90
{
    operator unsigned int() const;
    int* operator->() const;
};

}  // namespace fnv_008746b0

struct BSTextureManager
{
    enum RenderTargetType
    {
    };
};

struct BSRenderedTexture;

struct ImageSpaceTexture
{
    void CreateRenderTargetTexture(BSTextureManager::RenderTargetType);
    BSRenderedTexture* GetRenderedTexture() const;
    void FUN_008748d0();
};

struct AutoMemHelper
{
    AutoMemHelper(int context, bool push, const char* file, int line);
    ~AutoMemHelper();
    int iOldContext;
};
struct BSRenderedTexture;
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct BSShaderAccumulator
{
    void FUN_00b64570(void* camera, BSRenderedTexture* texture);
};
BSFaceGenNiNode* __cdecl FUN_0045c670();

namespace fnv_0086bb20 {
struct GlobalObject_00869b10
{
    void RemoveAt(unsigned int);
};

struct SomeClass
{
    int FUN_0086bb70(unsigned int);
    bool FUN_0086bb20(unsigned int index);
};

}  // namespace fnv_0086bb20

struct TESGrass
{
    unsigned char GetMinimumSlopeDegrees(void);
};

namespace fnv_008746a0 {
struct Flt
{
    operator unsigned int(void);
};

extern Flt g_011c7810;

}  // namespace fnv_008746a0

struct FUN_008776e0
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    void SetFlags();
};

struct SoundPlaybackHandle
{
    bool StopWithFade(unsigned int);
    bool FUN_00877700();
};

namespace fnv_00875bd0 {
struct Flt
{
    operator unsigned int();
};

}  // namespace fnv_00875bd0

namespace fnv_00876830 {
struct BSRenderedTexture
{
    static void __cdecl EndAllAndResetRendererState();
    void __thiscall FUN_00876830(int, int);
};

}  // namespace fnv_00876830

extern "C" void __cdecl _Deallocate(void*);

extern "C" void __cdecl Deallocate(void*);

extern "C" void __cdecl _Deallocate(void*);
void __cdecl FUN_00700650();
struct FUN_0086bf10
{
    void __thiscall FUN_00700650();
    void* __thiscall DeleteThis(unsigned int flags);
};

namespace fnv_0086f6a0 {
struct ActiveEffect;
struct Actor;
struct AlchemyItem;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSRenderedTexture;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct BaseProcess;
struct BipedAnim;
struct DialogueResponse;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiTexture;
struct PlacedObjectInfo;
struct Script;
struct ScriptLocals;
struct ShadowSceneNode;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct Tile;
struct bhkCharacterController;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};

template <int N> struct FUN_0086f6a0_vs : FUN_0086f6a0_vs<N - 1>
{
    virtual void vf(int (*)[N + 1]);
};
template <> struct FUN_0086f6a0_vs<0>
{
    virtual void vf0();
};
struct FOPipboyManager
{
    void FUN_007fa990();
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
struct GlobalObject2_0040c150;
struct TaskQueueInterface
{
    static TaskQueueInterface* GetInstance();
    static void ThreadProcessSecondaryInput();
    static void ThreadProcessInput(unsigned int);
    void FUN_0087a790();
};
struct Interface
{
    static bool IsConsoleActive();
    static FOPipboyManager* GetPipboyManagerInstance();
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct ProcessLists
{
    void UpdateMagicTempEffects(float);
    void FUN_0096c860();
    void FUN_009781d0(float);
};
struct FUN_00991600_t
{
    void FUN_00991600(bool);
};
struct GameTimerRecord;
void FUN_00552570();
extern GlobalObject_0045cfe0 g_011c3ea4;
extern bool DAT_011dea2b;
extern bool DAT_011dea2d;
extern ProcessLists DAT_011e0e80;
extern FUN_00991600_t* BGSSaveLoadGlobalDataWorldspacePtr;
extern GameTimerRecord g_timeGlobal;

}  // namespace fnv_0086f6a0

namespace fnv_0086fd90 {

struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct GameTimerRecord : Twin_0084d030
{
};
extern GameTimerRecord g_timeGlobal;
struct ImageSpaceManager
{
    void BeginParamModifiers();
    void FUN_00b8b500();
    void ImageSpaceManager_ResetWeatherData();
    void FUN_00b8ccb0();
    void FUN_00b8d020();
    void ImageSpaceManager_ApplyCurrentParameterData(bool);
};
ImageSpaceManager* __cdecl FUN_004e3270();
struct ISMI_0086fd90
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
    virtual void v12();
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
    virtual bool IsExpired();
    virtual void Update();
    int iPad4;
    bool bActive;
};
struct Flt
{
    operator unsigned int();
};
struct GO
{
    GO(ISMI_0086fd90*);
    ~GO();
    void* p;
};
struct ISMList_0086fd90
{
    Flt& FUN_006815c0();
    ISMList_0086fd90* GetNext();
    void Remove(const GO&);
};
struct TES
{
    ISMList_0086fd90* FUN_0043b5d0();
};
extern TES* g_TES;
}  // namespace fnv_0086fd90

namespace fnv_008746d0 {
struct BSRenderedTexture;
struct NiStream;
struct RgbaColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, RgbaColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, RgbaColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
    float a;
};
typedef char _sizecheck_NiColorA[sizeof(RgbaColor) == 16 ? 1 : -1];

struct NiNode;
struct NiRenderTargetGroup;
struct NiColor;
struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float, float, float, float);
    float r, g, b, a;
};
struct NiAVObject
{
    bool FUN_00456610();
    void SetAppCulled(bool);
};
struct BSRenderedTexture
{
    NiRenderTargetGroup* GetGroup();
    static void EndAllAndResetRendererState();
};
struct ImageSpaceTexture
{
    BSRenderedTexture* FUN_008748d0();
};
struct S4
{
    ImageSpaceTexture* FUN_004ebbc0(int);
};
struct FUN_004a0fd0_shell
{
    void FUN_004a0fd0(unsigned int);
};
struct MiddleLowProcess
{
    FUN_004a0fd0_shell* GetProcessInteger();
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct SceneGraph_008746d0
{
    void FUN_00c52020(float, int, int, int);
};
struct PC_00605d70
{
    NiNode* GetNode(bool);
};
struct Flt
{
    operator unsigned int();
};
struct BSShaderManager
{
    static void SetFOV(float);
};
struct BSRenderStateManager
{
    static void SetColorWriteMask(unsigned int, unsigned int);
};
struct Renderer_008746d0
{
    virtual void rv00();
    virtual void rv01();
    virtual void rv02();
    virtual void rv03();
    virtual void rv04();
    virtual void rv05();
    virtual void rv06();
    virtual void rv07();
    virtual void rv08();
    virtual void rv09();
    virtual void rv10();
    virtual void rv11();
    virtual void rv12();
    virtual void rv13();
    virtual void rv14();
    virtual void rv15();
    virtual void rv16();
    virtual void rv17();
    virtual void rv18();
    virtual void rv19();
    virtual void rv20();
    virtual void rv21();
    virtual void rv22();
    virtual void rv23();
    virtual void rv24();
    virtual void rv25();
    virtual void rv26();
    virtual void rv27();
    virtual void rv28();
    virtual void rv29();
    virtual void rv30();
    virtual void rv31();
    virtual void rv32();
    virtual void rv33();
    virtual void rv34();
    virtual void rv35();
    virtual void rv36();
    virtual void rv37();
    virtual void rv38();
    virtual void rv39();
    virtual void rv40();
    virtual void rv41();
    virtual void rv42();
    virtual void SetBackgroundColor(ImageSpaceEffectParam*);
    virtual void SetBackgroundColorRGB(NiColor*);
    virtual void GetBackgroundColor(ImageSpaceEffectParam*);
};
S4* __cdecl FUN_004e3270();
Renderer_008746d0* __cdecl FUN_004a0e90();
SceneGraph_008746d0* __cdecl FUN_0045c670();
void __cdecl FUN_00b6b8d0(unsigned int, NiRenderTargetGroup*);
void __cdecl FUN_00b6bee0(void*, NiAVObject*, FUN_004a0fd0_shell*);
void __cdecl FUN_004eced0(unsigned int);
float __fastcall FUN_00874900(PC_00605d70*);
float __fastcall FUN_00710ab0(PC_00605d70*);
}  // namespace fnv_008746d0

namespace fnv_00875e40 {
class NiCamera;
class BSRenderedTexture;
struct AutoMemHelper
{
    int m;
    AutoMemHelper(int id, bool b, const char* file, int line);
    ~AutoMemHelper();
};
struct ArrSI
{
    unsigned int GetFlags();
};
extern ArrSI DAT_011f2250;
unsigned int __cdecl FUN_0045c670(void);
struct BSFaceGenNiNode
{
    void* GetAnimationData();
    void FUN_00c52020(float f, int a, void* b, int c);
};
struct FUN_00710ab0_Class;
float __fastcall FUN_00710ab0(FUN_00710ab0_Class* p);
float __fastcall FUN_00874900(const char* p);
struct BSShaderManager
{
    static void __cdecl SetFOV(float fov);
};
struct BSShaderAccumulator
{
    void SetupDepth(NiCamera* a, NiCamera* b, BSRenderedTexture* c);
};

}  // namespace fnv_00875e40

namespace fnv_00875fa0 {
unsigned int __cdecl FUN_0045c670(void);
struct BSFaceGenNiNode
{
    void* GetAnimationData(void);
};
}  // namespace fnv_00875fa0

namespace fnv_00876850 {
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct NiCamera;
struct RgbaColor;
struct NiNode;
struct NiPoint2;
struct NiScreenElements;
struct NiTexture;
struct GraphicsRenderer;
struct Sky;
struct blob4
{
    char b[4];
};
struct blob16
{
    char b[16];
};
struct ImageSpaceManager
{
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ImageSpaceEffect* GetEffect(int);
    void AddEffect(int, ImageSpaceEffect*);
    bool IsEffectActive(int);
    void SetupEffects();
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*,
                      bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void BeginParamModifiers();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(RgbaColor*);
    void ApplyTintColorParamModifierWeather(RgbaColor*);
    void SetFadeColorParamModifier(RgbaColor*);
    void ApplyFadeColorParamModifierWeather(RgbaColor*);
    void SetBlurRadiusParamModifier(float);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(struct blob16);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    BSRenderedTexture* GetDepthRenderedTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void InitGeometry();
    void ShutdownEffects();
    void ShutdownGeometry();
    void PrepareEndOfFrameEffects();
    void* __vecDelDtor(unsigned int);
    BSRenderedTexture* m_pCurrentRenderedTexture;
    char pEffectList[16];
    char m_kBlendedParameterData[152];
    void* m_pCurrentModifierParameterData;
    void* m_pPreviousModifierParameterData;
    char m_kModifierParameterData[304];
    bool m_bEndOfFrameEffectsEnabled;
    char _pad_1e5[3];
    int m_iEndOfFrameEffectCount;
    int m_eEndOfFrameEffect;
    char m_pMenuBackgroundScreenGeometry[4];
    char m_pMenuBackgroundScreenElementsData[4];
    char m_pMenuBackgroundScreenElements[4];
    bool m_bPartialRenderEnabled;
    char _pad_1fd[3];
    char m_pPartialRenderScreenElements[4];
    char m_kDepthTexture[16];
    char m_kModifierColor[16];
    char m_kPartialRenderColor[16];
    float m_fPartialRenderBlend;
    char m_kAccumulatedColor[16];
    char m_kWeatherFadeColor[16];
    float m_fFadeColorAlpha;
    float m_fDoubleVisionStrength;
    float m_fWeatherBlurRadius;
    float m_fWeatherDoubleVisionStrength;
    float m_fAdditionalImageSpaceValue;
    float m_fRadialBlurStrength;
    float m_fRadialBlurRampUp;
    float m_fRadialBlurStart;
    float m_fRadialBlurRampDown;
    float m_fRadialBlurDownStart;
    float m_fWeatherRadialBlurStrength;
    float m_fWeatherRadialBlurRampUp;
    float m_fWeatherRadialBlurStart;
    float m_fWeatherRadialBlurRampDown;
    float m_fWeatherRadialBlurDownStart;
    char m_kRadialBlurCenter[8];
    char m_kWeatherRadialBlurCenter[8];
    float m_fDepthOfFieldStrength;
    float m_fDepthOfFieldMaskConstant;
    float m_fDepthOfFieldDistance;
    float m_fDepthOfFieldRange;
    float m_fDepthOfFieldEffectStrength;
    float m_fDepthOfFieldEffectDistance;
    float m_fDepthOfFieldEffectRange;
    float m_fDepthOfFieldMaskValue;
    int m_eDepthOfFieldMode;
    int m_eDepthOfFieldTargetMode;
    bool m_bDepthOfFieldUsesObject;
    bool m_bMenuBackgroundBlendEnabled;
    char _pad_2ce[2];
    float m_fBlurRadius;
    float m_fRadialBlurTransition;
    float m_fRadialBlurStartValue;
    float m_fRadialBlurDistance;
    float m_fRadialBlurRange;
    char m_kRadialBlurOrigin[8];
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
};
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];

struct Flt
{
    operator unsigned int();
};
unsigned int __cdecl FUN_0045c670();
void* __cdecl FUN_004a0e90();
struct BSTextureManager
{
    void AddRenderedTexture(BSRenderedTexture*);
};
BSTextureManager* __stdcall FUN_004a0ea0();
struct S5;
struct S4
{
    S5* FUN_004ebbc0(int);
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct GO
{
    void operator=(void*);
};
struct MiddleLowProcess
{
    int GetProcessInteger();
};
struct ArrSI
{
    unsigned int GetFlags();
};
int __cdecl FUN_00683a60();
void __cdecl FUN_00bad4a0();

}  // namespace fnv_00876850

namespace fnv_00877260 {
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

class GridCell;
class NiNode;
class IOManager;
class TESObjectREFR;
class ThreeByThreeMatrix
{
  public:
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
class NiAVObject
{
  public:
    void UpdateSceneObject();
    void SetLocalRotation(const ThreeByThreeMatrix& kRot);
};
class NiNode
{
  public:
    void Update(const NiUpdateData& kData);
};
struct NiNode_00558310;
NiAVObject* __fastcall FUN_00558310(NiNode_00558310*);
unsigned int __cdecl FUN_0045c670();
class TES
{
  public:
    GridCell* FUN_00457050(int, int);
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
extern int g_TES;
extern IOManager* DAT_01202d98;
class AutoMemHelper
{
  public:
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
    int iOld;
};
struct PC_00605d70
{
    NiNode* GetNode(bool);
};
class NiAdditionalGeometryData
{
  public:
    static NiAVObject* __cdecl GetShadowSceneNodeForIndex(int);
};

}  // namespace fnv_00877260

struct GlobalObject_00869b10
{
    void RemoveAt(unsigned int);
};

namespace fnv_0086bc60 {
struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};

}  // namespace fnv_0086bc60

namespace fnv_00872940 {
struct S148c0
{
};

struct ImageSpaceManager
{
};

struct BSRenderedTexture
{
};

struct Interface
{
  public:
    enum enumMenus
    {
        MENU_ID_0x3f6 = 0x3f6,
        MENU_ID_0x41e = 0x41e,
        MENU_ID_0x424 = 0x424,
        MENU_ID_0x432 = 0x432,
        MENU_ID_0x438 = 0x438,
        MENU_ID_0x439 = 0x439,
        MENU_ID_0x43a = 0x43a,
        MENU_ID_0x43b = 0x43b
    };

    static bool __cdecl IsMenuActive(enumMenus menuID, unsigned int parameter);
};

S148c0* __cdecl FUN_0043c4b0(void);
ImageSpaceManager* __cdecl FUN_004e3270(void);
bool __cdecl FUN_004dc310(void);
unsigned char __cdecl FUN_008709f0(void);

}  // namespace fnv_00872940

extern "C" __declspec(dllimport) void __stdcall DebugBreak();

struct ScaleSource
{
    NiPoint3 GetScale3() const;
};

NiPoint3* __fastcall FUN_0045bb80(ScaleSource* pObj);

typedef unsigned int DWORD;

typedef unsigned short WORD245;
typedef unsigned long DWORD245;

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(unsigned long, unsigned long);

class Menu
{
  public:
    virtual ~Menu();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual unsigned int GetID();
};
class TileList
{
  public:
    void* GetHeadPos() const;
    Tile*& GetNext(void*&);
    Tile* Remove(Tile*&);
};
class Tile
{
  public:
    virtual ~Tile();
    TileList children;
    Menu* GetMenu();
};
class InterfaceManager
{
  public:
    Tile* FUN_00586150();
};
InterfaceManager* __cdecl FUN_004b7210();
bool __cdecl IsStartMenuFlag1Set();

struct Device86
{
    virtual int __stdcall QueryInterface(void*, void*);
    virtual int __stdcall AddRef();
    virtual int __stdcall Release();
    virtual int __stdcall TestCooperativeLevel();
};
struct Receiver86
{
    Receiver86* FUN_00afdc60(const char*, int, int);
    Receiver86* FUN_0086c160(unsigned int, unsigned int);
    Receiver86* FUN_007005d0();

    void FUN_0066b0d0(int);
    void FUN_00b6da10(int);
    void FUN_00448420();
    void FUN_008c73a0();
    Receiver86* FUN_008d8520();
    void FUN_0086be30();
    void FUN_006c0900();
    void* FUN_0086bee0(unsigned int);
    void* FUN_0086bf10(unsigned int);
    void* FUN_0086bf40(unsigned int);
    void FUN_006eb980();
    void* FUN_00717e50();
    void FUN_005e01b0(void*);
    void FUN_0086bb20(void*);
    void FUN_0086bc10(void*);
    int FUN_00aa47c0(void*, int);

    void FUN_0086bda0();
    Receiver86* FUN_00460140();
    int* FUN_006815c0();
    void FUN_00458200(int);
    void ClearIdleAnims();
    void FUN_008a8150(int);
    void FUN_00970d50();
    void FUN_004614e0();
    void FUN_007d6bd0(int);
    void FUN_00483710();
    void FUN_004f15a0(int);
    int FUN_008d6f30();
    void FUN_004650a0(int);
    void FUN_00ec1800();
    void FUN_00456520();
    int FUN_0044ddc0();
    unsigned char FUN_00451530();
    int FUN_00559450();
    Device86* FUN_004dc020();
    void FUN_0086ba10();
    void FUN_0086ba90();
    void FUN_0086e650();
    void FUN_00ad8740();
    void FUN_00ad8700();
    void FUN_00ad7740(int);
    unsigned int FUN_0044edb0();
    Receiver86* FUN_004e2190();
    void FUN_00b63620();
    void FUN_004a4340();
    void FUN_008026b0();
    bool FUN_005dc960();
    unsigned char FUN_00678ce0();
    void FUN_008774a0(int);

    void FUN_00b012f0(const char*, const char*);
    void FUN_004a0370();
    void FUN_0086bbd0(void*, int);
    void FUN_0086bae0(void*, int);
    void FUN_004a03c0();
    void FUN_00ec16d0(const char*, int, int, int, int, float);
    void FUN_0086cf20(Receiver86*);
    int FUN_006629f0();
    void FUN_006eb8c0();
    void FUN_006c07d0();
    void FUN_008c7290();
    void FUN_0086d500();
    void FUN_0086d590();
    void FUN_00871c90(int);

    Receiver86* FUN_008526c0();
    void FUN_004fb090(void*);
    void FUN_006ecd40(int(__cdecl*)(...));
    void FUN_006ff880(int);
    void FUN_005e0200(const void*);
};
struct Setting86
{
    unsigned char* FUN_00408d60() throw();
    int* Int() throw();
    const char* FUN_00403df0() throw();
};
extern Setting86 g_011dec88, g_011dee20, g_011ded74;
extern Setting86 g_011dee78, g_011ded2c, g_011dece4, g_011dee6c, g_011de72c, g_011d73e4;
extern Receiver86* DAT_0126fac4;
void* __cdecl operator new(unsigned int);
extern Receiver86* g_dataHandler;
extern Receiver86* g_BGSSaveLoadGame;
extern Setting86 g_011deed8;
extern Receiver86 g_011ded3c, g_011dec64, g_011deb38;
typedef int(__cdecl* code)(...);

int __cdecl FUN_00408d60(...);
Receiver86* __cdecl FUN_00af2640();
int __cdecl FUN_004fb090(...);
int __cdecl FUN_008526c0(...);
int __cdecl FUN_006ecd40(...);

Receiver86* __cdecl FUN_006ff580();
int __cdecl FUN_006ff880(...);
int __cdecl FUN_005e0200(...);
int __cdecl FUN_00403df0(...);
int __cdecl FUN_00b012f0(...);

int __cdecl FUN_0040fbe0(...);
int __cdecl FUN_0086bda0(...);

int __cdecl FUN_0086d500(...);
Receiver86* __cdecl FUN_0043c4b0();
int __cdecl FUN_004a0370(...);
int __cdecl FUN_0086bbd0(...);
int __cdecl FUN_0086bae0(...);
int __cdecl FUN_0086d590(...);
int __cdecl FUN_00871c90(...);
int __cdecl FUN_004a03c0(...);
int __cdecl FUN_00ec16d0(...);
int __cdecl FUN_0086cf20(...);
int __cdecl FUN_006629f0(...);
Receiver86* __cdecl FUN_00713d80();
int __cdecl FUN_008c7290(...);
Receiver86* __cdecl GetPathManager();
int __cdecl FUN_006eb8c0(...);
Receiver86* __cdecl GetNavMeshObstacleManager();
int __cdecl FUN_006c07d0(...);
int __cdecl FUN_00460140(...);
int __cdecl FUN_006815c0(...);
int __cdecl FUN_00458200(...);
int __cdecl ClearIdleAnims(...);
int __cdecl FUN_008a8150(...);
int __cdecl FUN_00970d50(...);
int __cdecl FUN_004614e0(...);
int __cdecl FUN_007d6bd0(...);
int __cdecl FUN_00483710(...);
int __cdecl FUN_004f15a0(...);
int __cdecl FUN_008d6f30(...);
int __cdecl FUN_004650a0(...);
int __cdecl FUN_007053f0(...);
int __cdecl FUN_00ec1800(...);
int __cdecl FUN_00456520(...);
int __cdecl FUN_0044ddc0(...);
int __cdecl FUN_00451530(...);
int __cdecl FUN_00559450(...);
int __cdecl FUN_004dc020(...);
int __cdecl FUN_0086ba10(...);
int __cdecl FUN_0086ba90(...);
int __cdecl FUN_0086e650(...);
Receiver86* __cdecl FUN_00453a70();
int __cdecl FUN_00ad8740(...);
int __cdecl FUN_00ad7740(...);
unsigned char __cdecl FUN_00446e10();
int __cdecl FUN_0044edb0(...);
int __cdecl FUN_0078cfc0(...);
int __cdecl FUN_00ad8700(...);
int __cdecl FUN_004e2190(...);
int __cdecl FUN_00b63620(...);
Receiver86* __cdecl FUN_0049fef0();
int __cdecl FUN_004a4340(...);
Receiver86* __cdecl FUN_00705910();
int __cdecl FUN_008026b0(...);
int __cdecl FUN_005dc960(...);
int __cdecl FUN_00678ce0(...);
int __cdecl FUN_008774a0(...);
int __cdecl FUN_00706320(...);
Receiver86* __cdecl FUN_004a0ea0();
int __cdecl FUN_00b6da10(...);
int __cdecl FUN_0066b0d0(...);
int __cdecl FUN_00683a60(...);
int __cdecl FUN_00448420(...);
int __cdecl FUN_008c73a0(...);
int __cdecl FUN_008d8520(...);
int __cdecl FUN_0086be30(...);
int __cdecl FUN_006c0900(...);
int __cdecl FUN_0086bee0(...);
int __cdecl FUN_006eb980(...);
int __cdecl FUN_0086bf10(...);
int __cdecl FUN_0086bf40(...);
int __cdecl FUN_00717e50(...);
int __cdecl FUN_005e01b0(...);
int __cdecl FUN_0086bb20(...);
int __cdecl FUN_0086bc10(...);
int __cdecl FUN_00aa47c0(...);

extern unsigned int _DAT_011dea10;

__declspec(dllimport) unsigned int __stdcall CreateMutexA(int, int, const void*);
__declspec(dllimport) unsigned int __stdcall GetLastError();
__declspec(dllimport) int __stdcall MessageBoxA(int, const void*, const void*, int);
__declspec(dllimport) int __stdcall GetSystemMetrics(int);
__declspec(dllimport) void __stdcall GetSystemInfo(void*);
__declspec(dllimport) int __stdcall FindWindowA(const char*, int);
__declspec(dllimport) int __stdcall GetCommandLineW();
__declspec(dllimport) int __stdcall CommandLineToArgvW(int, int*);
__declspec(dllimport) int __stdcall LocalFree(void*);
__declspec(dllimport) int __stdcall ShellExecuteA(int, int, const void*, int, int, int);
__declspec(dllimport) int __stdcall LoadIconA(int, int);
__declspec(dllimport) int __stdcall GetStockObject(int);
__declspec(dllimport) int __stdcall RegisterClassA(void*);
__declspec(dllimport) int __stdcall AdjustWindowRect(void*, int, int);
__declspec(dllimport) int __stdcall CreateWindowExA(int, const char*, const char*, int, int, int, int, int, int, int,
                                                    int, int);
__declspec(dllimport) int __stdcall PeekMessageA(void*, int, int, int, int);
__declspec(dllimport) int __stdcall TranslateMessage(void*);
__declspec(dllimport) int __stdcall DispatchMessageA(void*);

__declspec(dllimport) void __stdcall Sleep(int);
__declspec(dllimport) int __stdcall GetWindowLongA(int, int);
__declspec(dllimport) int __stdcall AdjustWindowRectEx(void*, int, int, int);
__declspec(dllimport) int __stdcall SetWindowPos(int, int, int, int, int, int, int);
__declspec(dllimport) int __stdcall GetCurrentThreadId();
__declspec(dllimport) int __stdcall SetForegroundWindow(int);

struct UpdateInfo
{
    float time;
    int flags;
    int unk08;
    UpdateInfo(float, bool, bool);
};
struct ScenePart
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual ScenePart* AsNode();
    ScenePart* Child(unsigned int);
    void Link();
    void Reset();
    void Update(UpdateInfo&);
};
struct SkyInit
{
    static SkyInit* GetInstance();
    ScenePart* Attach(ScenePart*);
};
extern SkyInit* DAT_011dea20;
extern int DAT_011dea1c;
struct InitSetting
{
    const char* String();
    int Value();
    int* Int();
    bool* Bool();
};
extern InitSetting g_011c7adc;
const char* PrepareScriptMessage(const char*, bool);

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int);
namespace FrameUpdate {
struct Service;
struct Values
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct Service
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void Update();
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
    virtual void Advance(float);
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
    virtual void* Position();
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
    Values values;
    void FUN_006ff860();
    bool FUN_00701450(bool);
    void FUN_00851d90();
    void FUN_00c3dbf0();
    void FUN_00457d70(int, int, int);
    void FUN_00b6dd00(Service*, bool);
    void FUN_007011d0(bool);
    bool FUN_00451530();
    bool FUN_0086ef70();
    void FUN_004556d0(int);
    Service* FUN_00559450();
    float FUN_0084d030();
    void FUN_00867a40(float);
    int* FUN_0043d4d0();
    void FUN_00455640();
    void FUN_0040fbf0(int);
    void FUN_00978550();
    void FUN_009777a0();
    void FUN_0096eb40();
    void FUN_0096e9b0();
    void FUN_008d0600(float, int);
    void FUN_0040fba0();
    void FUN_00878080(bool);
    void FUN_0049fff0();
    void FUN_00712e60(void*);
    int FUN_0044ddc0();
    float FUN_00710ab0();
    void FUN_00c52020(float, int, int, bool);
    void* FUN_006629f0();
    void FUN_0045bc80(bool, bool);
    void FUN_00b5ac90(void*);
    void FUN_0045b070(void*);
    void FUN_008c78c0();
    void FUN_008ca070();
    void FUN_006ebc50();
    void FUN_006a61b0();
    bool* FUN_00408d60();
    void FUN_006c3640();
    void FUN_00991500(bool);
    void FUN_008c7990();
    void FUN_008ca300();
    bool FUN_00950090();
    signed char FUN_00424940();
    void* FUN_008d6f30();
};
Service* __cdecl FUN_00af2640();
bool __cdecl FUN_00702360();
bool __cdecl FUN_00709bc0();
void* __cdecl FUN_00707ad0();
void* __cdecl FUN_00705990();
Service* __cdecl FUN_004b7210();
Service* __cdecl FUN_006ff580();
bool __cdecl FUN_0070edf0();
Service* __cdecl FUN_00524c90();
Service* __cdecl FUN_004a0ea0();
int __cdecl FUN_00683a60();
Service* __cdecl FUN_0049fef0();
Service* __cdecl FUN_0045c670();
Service* __cdecl FUN_00713d80();
Service* __cdecl GetPathManager();
Service* __cdecl GetNavMeshObstacleManager();
void __cdecl FUN_0078cfc0();
void __cdecl FUN_007058e0();
void __cdecl FUN_00a29680();
void __cdecl FUN_00b54000(float);
Service* __cdecl FUN_00450b80(int);
void __cdecl FUN_008c80e0(bool);
extern Service* DAT_011d8804;
extern Service* DAT_011dea3c;
extern Service* DAT_01202d98;
extern Service* DAT_011dea10;
extern Service DAT_011deb7c;
extern Service DAT_011f6394;
extern Service DAT_011c3ea4;
extern Service DAT_011e0e80;
extern Service DAT_011f2250;
extern Service DAT_011e0fe0;
extern bool DAT_011dea2b;
extern bool DAT_011dea2c;
extern bool DAT_011dea2d;
extern bool DAT_011dea2e;
extern float DAT_011a3010, DAT_011deef8;
extern int DAT_011a2fe0, DAT_011df674;
extern char DAT_011ad840;
}

namespace fnv_008707c0 {
typedef ImageSpaceManager ISMgr;
struct Rend;
struct RootNode;
struct AnimData;
struct StrObj
{
    operator const char*() const;
};

struct MTHelper
{
    void FUN_00ba30f0(int a, int b);
    void FUN_00ba3130(int a, int b);
};
MTHelper* __cdecl FUN_004ea970();

struct RMenu
{
    RootNode* FUN_007fa950();
};
RMenu* __cdecl FUN_00707ad0();
Rend* __cdecl FUN_0043c4b0();
bool __cdecl FUN_004dc310();
bool __cdecl FUN_00705a00();
unsigned char __cdecl FUN_008709f0();
void __cdecl FUN_008c80e0(int);

struct FNode
{
    void FUN_004a0fd0(const char* s);
    void FUN_0041fd00(AnimData* a);
};
AnimData* __cdecl FUN_00524c90();
struct SSN
{
    void FUN_00b5e870(FNode* n);
};
SSN* __cdecl FUN_00450b80(int);

}  // namespace fnv_008707c0

struct ShadowActor;
struct ShadowNode;
struct ShadowView;
struct ShadowMap;
struct ShadowVector
{
    float x, y, z;
};
struct ShadowBound
{
    float x, y, z, radius;
    float FUN_0084d030();
};
struct ShadowUpdate
{
    float time;
    int flags, frame;
    ShadowUpdate(float, bool, bool);
};
struct ShadowExtra
{
    const ShadowVector& FUN_00500940();
};
struct ShadowTransform
{
    void* FUN_0045bbe0();
};
struct ShadowNode
{
    int FUN_009611e0();
    ShadowExtra* FUN_00a5bdd0(int);
    ShadowBound* FUN_0043d450();
    bool FUN_00456610();
    void FUN_00450f90(bool);
    const ShadowVector& FUN_0045bb80();
    void FUN_00a59c60(ShadowUpdate*);
};
struct ShadowView
{
    void FUN_0041fd00(ShadowTransform*);
    void FUN_00a694a0(void*);
};
struct ShadowMap
{
    ShadowNode* FUN_004e6540();
    ShadowNode* FUN_005bf820();
    bool FUN_004e6580();
    void FUN_00b9bb10(float, bool);
    void UpdateOutputLight(int, ShadowVector);
    void FUN_00b9e970(ShadowView*);
    unsigned short FUN_004e6560();
    float GetFirstLightParameter();
    void UpdateShadow(ShadowView*, int);
    void FUN_00b9fba0();
    void FUN_00ba0110(ShadowNode*);
    void FUN_00ba02b0();
};
struct ShadowSystem
{
    void FUN_00b5b1f0();
    void FUN_00b5b060();
    void FUN_00b5c3c0();
    void* FUN_00b5cbd0(ShadowNode*);
    void ShadowSceneNode_SortShadowLights(void*);
    ShadowMap* FUN_00b5afc0();
    ShadowMap* FUN_00b5b010();
    void* FUN_00454b30();
    void FUN_00b5d300(ShadowMap*);
    void FUN_00b5b880(ShadowView*);
};
struct ShadowRenderer
{
    void ResizeActivePool();
};
struct ShadowTarget
{
    void FUN_00ba30f0();
    void FUN_00ba3130();
};
struct ShadowEnvironment
{
    int FUN_005f36f0();
};
struct ShadowIntSetting
{
    int* FUN_0043d4d0();
};
struct ShadowBoolSetting
{
    bool* FUN_00408d60();
};
extern ShadowEnvironment* DAT_011dea10;
extern ShadowActor* DAT_011dea3c;
extern ShadowIntSetting DAT_011c72d8, DAT_011c72e4;
extern ShadowBoolSetting DAT_011c71dc, DAT_011c7664;
extern const ShadowVector DAT_011f426c;
const double DAT_01021928 = 3.0;
const double DAT_01082cb0 = 0.05;
bool FUN_00525420();
ShadowSystem* FUN_00450b80(int);
void* __stdcall FUN_0043c4b0(int);
ShadowRenderer* __stdcall FUN_004a0ea0(void*);
ShadowTarget* __stdcall FUN_004ea970(int, int);
struct ShadowActor
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9C();
    virtual void SlotA0();
    virtual void SlotA4();
    virtual void SlotA8();
    virtual void SlotAC();
    virtual void SlotB0();
    virtual void SlotB4();
    virtual void SlotB8();
    virtual void SlotBC();
    virtual void SlotC0();
    virtual void SlotC4();
    virtual void SlotC8();
    virtual void SlotCC();
    virtual void SlotD0();
    virtual void SlotD4();
    virtual void SlotD8();
    virtual void SlotDC();
    virtual void SlotE0();
    virtual void SlotE4();
    virtual void SlotE8();
    virtual void SlotEC();
    virtual void SlotF0();
    virtual void SlotF4();
    virtual void SlotF8();
    virtual void SlotFC();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10C();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11C();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12C();
    virtual void Slot130();
    virtual void Slot134();
    virtual void Slot138();
    virtual void Slot13C();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14C();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15C();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16C();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17C();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18C();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19C();
    virtual void Slot1A0();
    virtual void Slot1A4();
    virtual void Slot1A8();
    virtual void Slot1AC();
    virtual void Slot1B0();
    virtual void Slot1B4();
    virtual void Slot1B8();
    virtual void Slot1BC();
    virtual void Slot1C0();
    virtual void Slot1C4();
    virtual void Slot1C8();
    virtual void Slot1CC();
    virtual ShadowNode* Get3D();
    virtual void Slot1D4();
    virtual void Slot1D8();
    virtual void Slot1DC();
    virtual void Slot1E0();
    virtual void Slot1E4();
    virtual void Slot1E8();
    virtual void Slot1EC();
    virtual void Slot1F0();
    virtual void Slot1F4();
    virtual void Slot1F8();
    virtual void Slot1FC();
    virtual void Slot200();
    virtual void Slot204();
    virtual void Slot208();
    virtual void Slot20C();
    virtual void Slot210();
    virtual int GetState();
    bool FUN_004eaf60();
    bool FUN_00950090();
    bool FUN_008c51c0();
    ShadowNode* FUN_00950bb0(int);
    bool FUN_0087f200();
};

namespace fnv_00871a50 {
extern bool __cdecl FUN_00702360();
extern bool __cdecl FUN_007079b0();
extern bool __cdecl FUN_00705a00();
extern void __cdecl FUN_007058e0();
extern bool __cdecl FUN_00702680(unsigned int, int);
struct RenderFlag
{
    bool* FUN_00408d60();
};
extern RenderFlag DAT_011db2cc, DAT_011d8ba0;
struct RenderNode
{
    void FUN_007fae70(int);
    bool FUN_00456610();
    void FUN_00450f90(bool);
};
extern RenderNode* __cdecl FUN_00705990();
struct UiRenderer
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void Draw(RenderNode*, bool, int);
};
extern UiRenderer* __cdecl FUN_00707ad0();
struct RenderHolder
{
    RenderNode* FUN_00559450();
    void FUN_0066b0d0(RenderNode*);
};
extern RenderHolder DAT_011dec64;
struct RenderTextureSource
{
    RenderNode* FUN_00b6e110();
};
extern RenderTextureSource* __stdcall FUN_004a0ea0(void*, int, int, int, int);
extern void* __cdecl FUN_0043c4b0();
extern const char DAT_010829c4[];
}  // namespace fnv_00871a50

namespace fnv_00871dc0 {
struct RenderSurface
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
    virtual unsigned int Width(unsigned int);
    virtual unsigned int Height(unsigned int);
};
struct NiRenderer
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
    virtual RenderSurface* Target();
    void FUN_004a0370();
    void FUN_004a03c0();
};
NiRenderer* FUN_0043c4b0();
struct MTRenderer
{
    void FUN_00ba2f30();
    void FUN_00ba2fa0();
    void FUN_00ba30f0(int, int);
    void FUN_00ba3130(int, int);
};
MTRenderer* FUN_004ea970();
struct MenuTarget
{
    unsigned int FUN_00872370(unsigned int);
    unsigned int FUN_008723d0(unsigned int);
};
struct MenuTargetPointer
{
    MenuTarget* value;
    MenuTarget* Get() const;
    void operator=(MenuTarget*);
};
extern MenuTargetPointer g_011ded3c;
struct TextureMgr
{
    void FUN_00b6da10(MenuTarget*);
    MenuTarget* FUN_00b6e110(NiRenderer*, int, int, int, int);
};
TextureMgr* __stdcall FUN_004a0ea0();
extern bool DAT_011f9426;
extern bool DAT_011dea29;
struct Rect
{
    float left, right, top, bottom;
    Rect(float, float, float, float);
};
struct Camera
{
    void FUN_00712e60(const Rect&);
};
Camera* FUN_00524c90();
extern Rect DAT_011ad840;
struct Modifier;
struct InterfaceManager
{
    Modifier* FUN_00718ab0();
};
InterfaceManager* FUN_004b7210();
bool FUN_00705a00();
bool FUN_00702680(int, unsigned int);
bool IsStartMenuFlag1Set();
struct RenderMenu
{
    void* FUN_008b6200();
    void* GetMenuRoot();
};
RenderMenu* FUN_00707ad0();
struct BSCullingProcess
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
    BSCullingProcess(void*);
    ~BSCullingProcess();
    void FUN_0041fd00(void*);
    void FUN_004a0fd0(MenuTarget*);
};
struct SceneObject
{
    void FUN_004a1020(void*);
};
void* FUN_00450b80(int);
void FUN_00b6bee0(void*, void*, BSCullingProcess*);
void FUN_00b6c0d0(void*, MenuTarget*, int);
}  // namespace fnv_00871dc0

extern const char str_010829c4[];

struct NiRenderTargetGroup;
struct BSRenderedTexture;
extern BSRenderedTexture* DAT_011f9438;

struct P1
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual NiRenderTargetGroup* GetRenderGroup();
    unsigned int FUN_004dee10();
    unsigned int FUN_004dee70();
};

struct Mgr
{
    BSRenderedTexture* FUN_00b6e110();
};
Mgr* __stdcall FUN_004a0ea0(P1* a, int b, int c, int d, int e);

unsigned char FUN_008709f0();
void __cdecl FUN_00b6b8d0(unsigned int id, NiRenderTargetGroup* ausAnimationGroup);

struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float a, float b, float c, float d);
    float m_kPointA;
    float m_kPointB;
    float m_iThirdValue;
    float m_iFourthElementInteger;
};
struct _Rect16_00712e60
{
    float m_kPointA;
    float m_kPointB;
    float m_iThirdValue;
    float m_iFourthElementInteger;
};
struct _Cam_00712e60
{
    void FUN_00712e60(const _Rect16_00712e60& r);
};
_Cam_00712e60* __cdecl FUN_00524c90();

namespace fnv_00874c10 {
struct BSFaceGenNiNode;
BSFaceGenNiNode* __cdecl FUN_0045c670();

struct BSFaceGenAnimationData
{
    void FUN_00712e60(void*);
};
BSFaceGenAnimationData* __cdecl FUN_00524c90();

struct NiUpdateData
{
    float fTime;
    int b1;
    int b2;
    NiUpdateData(float time, int m_bUpdateEnabled, int bUpdateGeom);
};

struct NiPoint3WithNeg : public NiPoint3
{
    NiPoint3 FUN_004a0bd0() const;
};

struct NiNode
{
    void FUN_00450f90(bool);
    bool FUN_00456610();
    NiPoint3WithNeg* FUN_0045bb80();
    NiPoint3* FUN_0043c490();
    void FUN_00440460(const NiPoint3*);
    void Update(NiUpdateData*);
    void FUN_00546780(bool);
};

struct AudioGlobalHelper
{
    bool FUN_005bb4d0();
};
extern AudioGlobalHelper* DAT_011dea0c;

struct CameraHelper
{
    NiPoint3* FUN_0045bb80();
};
extern CameraHelper* DAT_011e07d0;

struct VATSHelper
{
    bool FUN_00525430();
};
extern VATSHelper DAT_011f2250;

struct BGSBodyPart
{
    NiPoint3* FUN_0045bb80();
    void FUN_004f00e0(const NiPoint3&);
};

struct FORenderedMenu
{
    BGSBodyPart* FUN_006838b0();
};
FORenderedMenu* __cdecl FUN_00705990();
FORenderedMenu* __cdecl FUN_00707ad0();

struct MTRenderingSystem_Helper
{
    void FUN_00ba30f0(int, int);
    void FUN_00ba3390(void*, int, void*, int, int, void*, int, int, int);
};
MTRenderingSystem_Helper* __cdecl FUN_004ea970();

template <class T> struct TargetPointer
{
    T* m_pObject;
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
};

struct NiRenderer
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual int v50();
    virtual int v51();
};
NiRenderer* __cdecl FUN_0043c4b0();

void* __cdecl FUN_00450b80(int);

extern const char str_010829c4[];
extern unsigned char DAT_011f9426;
extern int DAT_011ad840;
extern unsigned char DAT_011de9d1;

}  // namespace fnv_00874c10

namespace SetRenderCamera {
struct Scene;
struct Context;
struct Pointer;
struct List;
struct Vec
{
    float x, y, z;
    Vec(float, float, float);
    Vec FUN_00439ef0(const Vec&);
    Vec FUN_00439e90(const Vec&);
};
struct Rect
{
    float left, right, top, bottom;
    Rect(float, float, float, float);
};
struct Update
{
    float time;
    unsigned int flags, other;
    Update(float, int, int);
};
struct VecRef
{
    Vec* FUN_0043c490();
};
struct Scene
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual Scene* Node();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual bool Active();
    virtual void slotc4();
    virtual void* Secondary();
    virtual void* Primary();
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
    unsigned short unk38;
    unsigned char visible, unk3b;
    void FUN_00450f90(bool);
    void FUN_007148c0(int, int);
    void FUN_00712e60(const Rect&);
    void FUN_00a6faf0(void*);
    void FUN_007fae70(int);
    Scene* FUN_007fa950();
    Scene* FUN_00875bd0(int);
    Scene* FUN_00a59d30(void*);
    void FUN_0049ed90(int);
    Vec* FUN_0045bb80();
    void* FUN_0045bbe0();
    void FUN_004f00e0(const Vec&);
    void FUN_00936aa0(bool);
    void FUN_00a29680();
    void* FUN_00b6b260();
    void FUN_00b64570(Scene*, Scene*);
    void FUN_00a59c60(const Update&);
    void FUN_00546780(int);
    VecRef* FUN_009611e0();
    void FUN_00870790(Vec);
    void FUN_008750e0(Vec);
    Scene* FUN_0043b230();
    bool FUN_00456610();
    void FUN_006426a0(int, Scene*, Scene*);
    Context* FUN_008d80e0();
    Scene* FUN_006629f0();
    void FUN_00c52020(float, int, int, int);
    void FUN_00ba3130(int, int);
};
struct Output : Scene
{
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
    Output(int, int, int);
    static __forceinline void* operator new(unsigned int);
    static __forceinline void operator delete(void*)
    {}
};
void* FUN_00aa13e0(unsigned int);
__forceinline void* Output::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
struct Pointer
{
    Scene* value;
    Pointer(Scene*);
    Pointer(const Pointer&);
    ~Pointer();
    Scene* FUN_00559450();
    void FUN_0066b0d0(Scene*);
};
struct Context
{
    void FUN_00c4f270(int);
    void FUN_004a0fd0(Scene*);
    void FUN_00c4f2d0();
};
struct List
{
    bool FUN_004a4460();
    Pointer* FUN_006815c0();
    List* FUN_00726070();
};
struct ListRef
{
    List* FUN_0043c490();
};
struct Mode
{
    bool FUN_00525430();
    int FUN_0044ddc0();
};
struct Player
{
    Scene* FUN_00950bb0(int);
    float FUN_00874900();
    float FUN_00710ab0();
    bool FUN_008c51c0();
    Scene* FUN_007721a0();
    bool FUN_008a8870();
};
extern Player* DAT_011dea3c;
extern bool DAT_011f9426, DAT_011de9d1;
extern Rect DAT_011ad840;
extern const char DAT_010829c4[];
extern Scene* DAT_011f9438;
extern ListRef DAT_011e0e80;
extern Mode DAT_011f2250;
extern Scene* DAT_011e07d0;
extern Vec DAT_011f426c;
extern Pointer DAT_011deb7c;
Scene* FUN_0045c670();
Scene* FUN_004ea970();
Scene* FUN_0043c4b0();
void FUN_00b54000(float);
Scene* FUN_00707ad0();
Scene* FUN_00705990();
bool FUN_007079b0();
bool FUN_00705a00();
void* FUN_0040df90();
void FUN_00b6bee0(Scene*, Scene*, Context*);
void FUN_00b6c0d0(Scene*, Scene*, int);
void FUN_00b98380(int, int);
void FUN_004eced0(int);
bool FUN_005b9b00();
void FUN_00b6b790();
void FUN_00b6b8d0(int, void*);
Scene* FUN_00524c90();
Scene* FUN_00450b80(int);
struct Main
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
    unsigned int unk80;
    unsigned int unk84;
    Pointer texture, surface;
    unsigned int unk90, unk94, unk98, unk9c;
    Pointer camera;
    void FUN_00874b50(Scene*, int, int);
    void FUN_00875110(Scene*, Scene*, Scene*, Scene*);
};
}

namespace fnv_00875fd0 {
struct SaveGameRenderState
{
    bool FUN_0042ce10();
    bool FUN_005621d0();
};
extern SaveGameRenderState* g_BGSSaveLoadGame;
bool __cdecl FUN_00705a00();
bool __cdecl FUN_00702360();
void __cdecl FUN_00b6b790();
bool __cdecl FUN_007079b0();
struct RenderEffectManager
{
    void FUN_00801a60(void*, BSShaderAccumulator*, int, unsigned char);
    void FUN_008019d0();
};
RenderEffectManager* __cdecl FUN_00705910();
extern bool DAT_011dea29;
struct RenderedMenu
{
    virtual void UnkVirtual0();
    virtual void UnkVirtual1();
    virtual void UnkVirtual2();
    virtual void UnkVirtual3();
    virtual void UnkVirtual4();
    virtual void UnkVirtual5();
    virtual void UnkVirtual6();
    virtual void UnkVirtual7();
    virtual void UnkVirtual8();
    virtual void UnkVirtual9();
    virtual void UnkVirtual10();
    virtual float GetRenderScale();
};
RenderedMenu* __cdecl FUN_00707ad0();
struct TextureReturnManager
{
    void FUN_00b6da10(BSShaderAccumulator*);
};
TextureReturnManager* __stdcall FUN_004a0ea0();
struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float, float, float, float);
    float left;
    float right;
    float top;
    float bottom;
};
struct ViewportCamera
{
    void FUN_00712e60(const ImageSpaceEffectParam&);
};
ViewportCamera* __cdecl FUN_00524c90();

}  // namespace fnv_00875fd0

namespace fnv_008761e0 {
struct V876
{
    float x, y, z;
    void FUN_0043d410(float, int, int);
};
struct T876
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    V876 pos;
    float scale;
    void FUN_00476a80();
    void FUN_00a86bf0();
};
struct R876
{
    float l, r, t, b;
};
struct Camera876
{
    bool FUN_00876810();
    T876* FUN_006a9540();
    void FUN_00440460(V876*);
    void FUN_00a59c60(V876*);
    void FUN_00546780(bool);
    Camera876* FUN_009611e0();
    Camera876* FUN_006629f0();
    Camera876* FUN_008b6200();
    Camera876* FUN_005585e0();
    R876* FUN_004a0d10();
    void FUN_00712e60(R876*);
    Camera876* FUN_0045bb80();
    V876* FUN_004a0bd0(V876*);
    void FUN_004fb0b0(bool);
    void FUN_0041fd00(Camera876*);
    void FUN_004a0fd0(void*);
    void FUN_004a1020(void*);
    void FUN_00b63b90(int);
    void FUN_0049ed90(bool);
    void FUN_00439340(int);
    void FUN_00439390(int);
    Camera876* FUN_00a59d30(void*);
    void FUN_00a5a040();
    Camera876* FUN_007fa950();
    void FUN_007fae70(void*);
    Camera876* FUN_00559450();
    void* FUN_004bc320(int);
};
struct Global876
{
    bool FUN_00967ae0();
    bool FUN_008c51c0();
};
struct Mode876
{
    bool FUN_007f8720(bool, bool, float*, float*, int*);
    Camera876* FUN_00875bd0(int);
};
extern Global876* DAT_011dea3c;
extern Camera876* DAT_011e07d0;
extern Camera876 g_011dec64;
extern V876 DAT_011f426c;
extern bool DAT_011f9426;
extern R876 DAT_011ad840;
Camera876* FUN_00707ad0();
Mode876* FUN_00705990();
bool FUN_00705a00();
void FUN_00b98380(int, int);
void FUN_00b97e30(int, int);
void FUN_00b6bee0(Camera876*, Camera876*, Camera876*);
void FUN_00b6c0d0(Camera876*, Camera876*, int);
void FUN_004eced0(int);
void* FUN_0040df90();
void FUN_00714a60(int);
_Fake_FUN_008750e0* FUN_00450b80(int);
struct Virtual876
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
    virtual int width();
    virtual int height();
};
Virtual876* FUN_0043c4b0();
}  // namespace fnv_008761e0

struct SLWorldSpace;

struct SLCell
{
    bool IsInterior();
    SLWorldSpace* GetParentWorldSpace();
    int GetPosX();
    int GetPosY();
};

struct SLWorldSpace
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
    virtual const char* GetEditorID();

    SLCell* GetCellAtCoords(int aiX, int aiY);
};

const char* __cdecl PrepareScriptMessage(const char* apString, bool abFlag);

namespace fnv_008774a0 {
struct FUN_009611e0_ctrl
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
    virtual void v058(void* apNode);
};

struct FUN_008774a0_node
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual FUN_008774a0_node* v003();
    FUN_009611e0_ctrl* FUN_009611e0();
};

struct FUN_0054ca90_cell
{
    void FUN_0054ca90(void* apRef);
};

struct FUN_008774a0_player
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
    virtual void v064();
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
    virtual void v115(int a1, int a2);
    void FUN_00877700();
    FUN_0054ca90_cell* FUN_008d6f30();
    FUN_008774a0_node* FUN_00950bb0(bool abFirstPerson);
};

struct FUN_004539a0_tes
{
    void FUN_004539a0(int a1, int a2);
    void FUN_007037c0(int aiValue);
    void FUN_0061cc40(int aiValue);
    void FUN_0045ac80();
};

struct FUN_00ad8780_audio
{
    void FUN_00ad8780(int aiValue);
};
struct FUN_006c09f0_mgr
{
    void FUN_006c09f0();
};
struct FUN_00b631d0_obj
{
    void FUN_00b631d0();
};

FUN_00ad8780_audio* FUN_00453a70();
FUN_006c09f0_mgr* GetNavMeshObstacleManager();
FUN_00b631d0_obj* FUN_00b4f5c0();
void __cdecl FUN_0040fbe0();
void FUN_00706320(int aiValue);
void __cdecl FUN_007053f0();

extern FUN_008774a0_player* DAT_011dea3c;
extern FUN_004539a0_tes* DAT_011dea10;

struct FUN_008774a0_shell
{
    bool FUN_004f1540();
    void FUN_004f15a0(int aiValue);
    void FUN_008776e0();
    void FUN_008774a0(bool abFlag);
};

extern FUN_008774a0_shell* DAT_011dea0c;

}  // namespace fnv_008774a0

namespace fnv_00873200 {
// Scene traversal, visibility batching, and the main and auxiliary render passes.
// Local-name suffixes preserve the VC++ 2008 stack-slot allocation.

struct ViewNode;
struct ViewGeometry;
struct ViewList;
struct ViewHandle
{
    ViewNode* value;
    ViewNode* FUN_00559450();
};
struct ViewList
{
    void* FUN_00559450();
    ViewHandle* FUN_0057cbe0(void** position);
    bool FUN_0076b610();
};
struct ViewNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ViewNode* AsNode();
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
    virtual void SetCamera(ViewNode* camera);
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
    bool m_38;
    unsigned char unk39;
    bool m_3a;
    ViewNode* FUN_008d80e0();
    ViewNode* FUN_006629f0();
    ViewNode* FUN_00950bb0(bool);
    bool FUN_00456610();
    void FUN_00450f90(bool);
    ViewNode* FUN_004ebbc0(int);
    bool FUN_00871220();
    void FUN_0041fd00(ViewNode*);
    void* FUN_0045bbe0();
    void FUN_00a694a0(void*);
    void FUN_004a0fd0(ViewNode*);
    ViewNode* FUN_0045bc00(unsigned int);
    unsigned int FUN_0043b480();
    ViewNode* FUN_0043b4a0(unsigned int);
    ViewNode* FUN_005f36f0();
    bool FUN_00874650();
    ViewNode* FUN_00454b30();
    ViewList* FUN_00436aa0();
    ViewList* FUN_006ab360();
    ViewGeometry* FUN_0045c4c0();
    bool FUN_00c4f320(ViewGeometry*);
    int FUN_00874480();
    int FUN_009b4440();
    ViewNode* FUN_0084e3a0();
    void FUN_00b5ba80(ViewNode*, ViewNode*);
    ViewList* FUN_007d6bb0();
    ViewNode* FUN_00457070();
    ViewNode* FUN_009d9f20();
    unsigned int FUN_00c5b5d0();
    ViewNode* FUN_00c5b5a0(int);
    void FUN_00b5e870(ViewNode*);
    ViewNode* FUN_00874670();
    void FUN_00c49850();
    void FUN_004dc540(ViewNode*);
    void FUN_00a89af0(ViewNode*);
    void FUN_004fb0b0(bool);
    void FUN_00642860();
    void FUN_006426a0(bool, ViewNode*, ViewNode*);
    int* FUN_0043d4d0();
};
struct ViewGeometry : ViewNode
{
};
struct VisibleList
{
    int unk00;
    int unk04;
    int unk08;
    VisibleList();
    ~VisibleList();
    void FUN_004ed8c0(ViewNode* const&);
    void FUN_004ed900();
};
struct RenderSystem
{
    void FUN_00ba3390(ViewNode*, ViewNode*, int, VisibleList*, int, ViewNode*, int, int, bool);
    void FUN_00ba30f0(int, int);
    void FUN_00ba3130(int, int);
};
struct InterfaceSystem
{
    void FUN_00800f30(int, int, int, int, int, int);
};
ViewNode* FUN_0045c670();
ViewNode* FUN_004e3270();
ViewNode* FUN_00450b80(int);
ViewNode* FUN_0043c4b0();
RenderSystem* FUN_004ea970();
InterfaceSystem* FUN_00705910();
void* FUN_004a0e90();
void FUN_00b6bee0(ViewNode*, ViewNode*, ViewNode*);
void FUN_00b6c0d0(ViewNode*, ViewNode*, bool);
void FUN_00b98380(int, int);
void FUN_004eced0(int);
void FUN_008c80e0(int);
void FUN_00872dd0(bool, bool);
extern ViewNode* DAT_011dea3c;
extern ViewNode* DAT_011dea10;
extern ViewHandle DAT_011deb7c;
extern ViewNode DAT_011c3ea4;
extern const char DAT_010829c4[];
extern __declspec(thread) int DAT_012722bc;
}  // namespace fnv_00873200

namespace fnv_00877730 {
struct GlobalObject_0045cf30;
class ImageSpaceManager;
struct AutoMemHelper
{
    unsigned int previousContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
union SETTING_VALUE
{
    bool b;
    int i;
};

struct NiUpdateData
{
    NiUpdateData(float f, bool bb, bool g);
    float m_f;
    bool m_kPointB;
    bool m_g;
    bool flag06, flag07, flag08;
};

struct NiObject;
struct TESLevItem;
class NiNode
{
  public:
    void Update(const NiUpdateData& data);
    void FUN_00a5a040();
    void AttachProperty(NiObject* p);
};

struct GO00
{
    NiNode* FUN_00559450();
};
struct GO34
{
    NiNode* FUN_00559450();
};
struct GOa4
{
    NiNode* FUN_00559450();
};
extern GO00 DAT_011deb00;
extern GO34 DAT_011deb34;
extern GOa4 g_011deda4;
extern GO34 DAT_011deb34;

template <class Collection> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};

struct ProcObj
{
    void FUN_0063a630(void* a, void* b);
    void* FUN_0045cd60();
    void* FUN_004505a0();
};
extern ProcObj* DAT_011dea20;

struct FUN_0049ec80_Property : NiRefObject
{
    void* unknown08;
    void* unknown0c;
    void* unknown10;
    unsigned int unknown14;
    unsigned short flags18;
    unsigned char alphaThreshold1a;
    unsigned char unknown1b;
    unsigned int unknown1c;
    unsigned int unknown20;
    FUN_0049ec80_Property();
    void FUN_0049ed90(bool b);
    void FUN_0049ede0(unsigned int value);
    void FUN_0050f9a0(unsigned int value);
};
typedef FUN_0049ec80_Property NiAlphaProperty;

struct LightShell
{
    void FUN_00b5aac0(void* p);
};

void FUN_0040fbe0(const char* s);
LightShell* FUN_00450b80(unsigned int i);
ImageSpaceManager* FUN_004e3270();

}  // namespace fnv_00877730

namespace sa238a0 {

}

namespace fnv_00872b00 {
struct ImageSpaceEffectParam
{
    float f0;
    float f4;
    float f8;
    float fC;
    ImageSpaceEffectParam(float a, float b, float c, float d);
};
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    int iFlags;
    NiUpdateData(float t, bool a, bool b);
};
struct ISMgr
{
    void FUN_00712e60(const ImageSpaceEffectParam& p);
};
extern ImageSpaceEffectParam DAT_011ad840;
struct StateObj
{
    unsigned int CallGetFlags();
};
extern StateObj DAT_011f2250;
struct PlayerCharacter;
float __fastcall FUN_00710ab0(PlayerCharacter* p);
extern PlayerCharacter* g_thePlayer;
struct BSShaderManager
{
    static void __cdecl SetFOV(float f);
};
struct NiCamera;
struct NiAVObject
{
    NiPoint3& FUN_0043c490();
    void FUN_00440460(const NiPoint3& p);
    void Update(NiUpdateData& d);
};
struct CamNode
{
    NiAVObject* FUN_00558310();
    NiCamera* GetAnimationData();
};
struct CamNodePtr
{
    operator CamNode*() const;
};
struct NodePtr
{
    operator NiAVObject*() const;
};
extern NodePtr g_011deda4;
void __cdecl FUN_00872dd0(bool a, bool b);
struct Sky
{
    void* FUN_0045cd60();
    int FUN_00476c90();
};
struct TES
{
    Sky* FUN_008d8520();
};
extern TES* g_TES;

}  // namespace fnv_00872b00

namespace fnv_0086ff70 {
struct PlayerState86
{
    virtual bool vfn_000();
    virtual bool vfn_004();
    virtual bool vfn_008();
    virtual bool vfn_00c();
    virtual bool vfn_010();
    virtual bool vfn_014();
    virtual bool vfn_018();
    virtual bool vfn_01c();
    virtual bool vfn_020();
    virtual bool vfn_024();
    virtual bool vfn_028();
    virtual bool vfn_02c();
    virtual bool vfn_030();
    virtual bool vfn_034();
    virtual bool vfn_038();
    virtual bool vfn_03c();
    virtual bool vfn_040();
    virtual bool vfn_044();
    virtual bool vfn_048();
    virtual bool vfn_04c();
    virtual bool vfn_050();
    virtual bool vfn_054();
    virtual bool vfn_058();
    virtual bool vfn_05c();
    virtual bool vfn_060();
    virtual bool vfn_064();
    virtual bool vfn_068();
    virtual bool vfn_06c();
    virtual bool vfn_070();
    virtual bool vfn_074();
    virtual bool vfn_078();
    virtual bool vfn_07c();
    virtual bool vfn_080();
    virtual bool vfn_084();
    virtual bool vfn_088();
    virtual bool vfn_08c();
    virtual bool vfn_090();
    virtual bool vfn_094();
    virtual bool vfn_098();
    virtual bool vfn_09c();
    virtual bool vfn_0a0();
    virtual bool vfn_0a4();
    virtual bool vfn_0a8();
    virtual bool vfn_0ac();
    virtual bool vfn_0b0();
    virtual bool vfn_0b4();
    virtual bool vfn_0b8();
    virtual bool vfn_0bc();
    virtual bool vfn_0c0();
    virtual bool vfn_0c4();
    virtual bool vfn_0c8();
    virtual bool vfn_0cc();
    virtual bool vfn_0d0();
    virtual bool vfn_0d4();
    virtual bool vfn_0d8();
    virtual bool vfn_0dc();
    virtual bool vfn_0e0();
    virtual bool vfn_0e4();
    virtual bool vfn_0e8();
    virtual bool vfn_0ec();
    virtual bool vfn_0f0();
    virtual bool vfn_0f4();
    virtual bool vfn_0f8();
    virtual bool vfn_0fc();
    virtual bool vfn_100();
    virtual bool vfn_104();
    virtual bool vfn_108();
    virtual bool vfn_10c();
    virtual bool vfn_110();
    virtual bool vfn_114();
    virtual bool vfn_118();
    virtual bool vfn_11c();
    virtual bool vfn_120();
    virtual bool vfn_124();
    virtual bool vfn_128();
    virtual bool vfn_12c();
    virtual bool vfn_130();
    virtual bool vfn_134();
    virtual bool vfn_138();
    virtual bool vfn_13c();
    virtual bool vfn_140();
    virtual bool vfn_144();
    virtual bool vfn_148();
    virtual bool vfn_14c();
    virtual bool vfn_150();
    virtual bool vfn_154();
    virtual bool vfn_158();
    virtual bool vfn_15c();
    virtual bool vfn_160();
    virtual bool vfn_164();
    virtual bool vfn_168();
    virtual bool vfn_16c();
    virtual bool vfn_170();
    virtual bool vfn_174();
    virtual bool vfn_178();
    virtual bool vfn_17c();
    virtual bool vfn_180();
    virtual bool vfn_184();
    virtual bool vfn_188();
    virtual bool vfn_18c();
    virtual bool vfn_190();
    virtual bool vfn_194();
    virtual bool vfn_198();
    virtual bool vfn_19c();
    virtual bool vfn_1a0();
    virtual bool vfn_1a4();
    virtual bool vfn_1a8();
    virtual bool vfn_1ac();
    virtual bool vfn_1b0();
    virtual bool vfn_1b4();
    virtual bool vfn_1b8();
    virtual bool vfn_1bc();
    virtual bool vfn_1c0();
    virtual bool vfn_1c4();
    virtual bool vfn_1c8();
    virtual bool vfn_1cc();
    virtual int vfn_1d0();
    PlayerState86* FUN_00950bb0(int);
};
struct Core86
{
    void FUN_004a0370();
    void FUN_005585e0();
    int FUN_004e9530();
    void FUN_004a03c0();
};
struct Input86
{
    bool FUN_00701450(int);
    void FUN_007010e0(int, int);
    bool IsFaderActive(int);
};
struct Topic86
{
    void FUN_004baf10();
};
struct Engine86
{
    void FUN_00457d70(int, int, int);
    int FUN_005f36f0();
    Engine86* FUN_004fd3e0();
    const char* FUN_00548210();
    Topic86* FUN_0044ddc0();
    void FUN_004baf10();
};
struct Global86
{
    int FUN_00559450();
    void FUN_0066b0d0(int);
};
struct Options86
{
    int* FUN_0043d4d0();
    void FUN_0045ce80(int);
};
struct Frame86
{
    float FUN_007013e0();
    void FUN_0086d4c0(int);
};
struct Sound86
{
    void FUN_00ba2f30();
    void FUN_00ba30f0();
    void FUN_00ba3130();
    void FUN_00ba2fa0();
};
struct Receiver86;
extern Receiver86* __cdecl FUN_0043c4b0();
extern Sound86* __cdecl FUN_004ea970();
extern Sound86* __stdcall FUN_004ea970(int, int);
extern char __cdecl FUN_00702680(int, int);
extern bool __cdecl FUN_0070edf0();
extern bool __cdecl FUN_007079b0();
extern bool __cdecl FUN_007079b0(int);
extern bool __cdecl FUN_00702360();
extern void __cdecl FUN_00a29680();
extern int __cdecl FUN_0040fbe0(...);
extern void __cdecl FUN_00c458f0();
extern void __cdecl FUN_00c51f20();
extern void __cdecl FUN_008c80e0(int);
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char*, void*);
extern int __stdcall FUN_004e3270(Core86*, int, int);
extern void __cdecl RenderOrFallback(int, int);
struct SwapMessage86
{
    void FUN_00b6da10();
};
extern SwapMessage86* __stdcall FUN_004a0ea0(int);
extern void __cdecl FUN_00b6da10();
extern bool __cdecl FUN_004dc310();
extern int DAT_011e0e80;
extern void __cdecl FUN_004da670();
extern unsigned char DAT_011d890a, DAT_011c6fb8, DAT_011dea29;
extern int DAT_011def04, DAT_011dea44;
extern PlayerState86* DAT_011dea3c;
extern Engine86* DAT_011dea10;
extern Input86* DAT_011d8804;
extern Global86 DAT_011ded3c, DAT_011dec64, DAT_011deb7c;
extern Options86 DAT_011deecc, DAT_011dee00, DAT_011c3ea4;
extern Frame86 DAT_011f6394;
extern unsigned char DAT_011dea29;
extern int DAT_011def04;
extern void __cdecl FUN_0045cd60();
extern void __stdcall FUN_00870680(void*);
extern void __cdecl FUN_00702840();
extern void __cdecl FUN_00702810();
extern void __cdecl FUN_007027e0();
extern void __cdecl FUN_00a29680();
extern void __cdecl FUN_00c458f0();
extern int __cdecl FUN_0040fbe0(...);
extern void __cdecl FUN_004a03c0();
extern void __cdecl FUN_00702840();
extern void __cdecl RenderOrFallback(int, int);
struct Control86
{
    int FUN_00a24660();
    int FUN_00a24180();
};
extern Control86* __stdcall FUN_007fdf30(int, int);
struct Receiver86;
extern Receiver86* __cdecl FUN_0043c4b0();
extern void __cdecl FUN_00b6da10();
extern void __cdecl FUN_00c51f20();
}  // namespace fnv_0086ff70

namespace fnv_00870bd0 {
struct FUN_00414430;
struct NiPoint2;
struct BSRenderedTexture;
struct ImageView;
struct ProjectionView;
ImageView* FUN_004e3270();
ProjectionView* FUN_0045c670();
bool FUN_004dc310();
unsigned char FUN_008709f0();
struct RenderNode
{
    bool FUN_00456610();
    void FUN_00450f90(bool);
};
struct PlayerView
{
    RenderNode* FUN_00950bb0(bool);
};
struct MenuView
{
    int FUN_005585e0();
};
struct WorldView
{
    int FUN_005f36f0();
};
struct PointView
{
    const NiPoint3& FUN_0045bb80();
};
struct CameraView
{
    virtual void v0();
    virtual PointView* v1();
};
struct CameraHolder
{
    CameraView* FUN_0045cd60();
};
struct ProjectionResult
{
    bool ProjectPointToScreen();
};
struct ProjectionView
{
    ProjectionResult* FUN_006629f0(const NiPoint3&, float&, float&, float&, float);
};
struct RenderView
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
    virtual void v43(void*);
    unsigned FUN_004dee10();
    unsigned FUN_004dee70();
    void FUN_007148c0(FUN_00414430*, bool);
};
struct EffectView
{
    bool FUN_00871220();
};
struct ImageView
{
    EffectView* FUN_004ebbc0(int);
    bool FUN_00b8b390(int);
    void FUN_00b8b1e0(const NiPoint2&);
};
struct SettingView
{
    float* FUN_00403e20();
};
struct ToggleView
{
    void FUN_00ba3130();
    void FUN_00ba30f0();
};
struct NiPoint2
{
    float x, y;
    NiPoint2(float, float);
};
struct FUN_00414430
{
    float a, b, c, d;
    FUN_00414430(float, float, float, float);
};
extern PlayerView* DAT_011dea3c;
extern WorldView* DAT_011dea10;
extern CameraHolder* DAT_011dea20;
RenderView* FUN_0043c4b0();
MenuView* FUN_00705910();
bool FUN_005b9b00();
bool FUN_00705a00();
ToggleView* __stdcall FUN_004ea970(int, int);

}  // namespace fnv_00870bd0

namespace fnv_00872570 {
struct HWND__;
class BGSMoviePlayer_ML
{
  public:
    bool FUN_00ec17c0();
    void FUN_00ec29b0();
    void FUN_00ec1800();
    bool FUN_00872780();
    void FUN_00ec25e0();
};
struct RenderManager_ML
{
    void FUN_00b631d0();
};
RenderManager_ML* __cdecl FUN_00b4f5c0();
struct CellState_ML
{
    int unk00;
    int active;
};
struct CellUpdate_ML
{
    void FUN_005477f0(void**, CellState_ML**);
};
struct GridCell_ML
{
    CellUpdate_ML* cell;
};
struct CellGrid_ML
{
    int FUN_0084e3a0();
};
struct WorldAudio_ML
{
    void ReleaseWaterResources(int, int);
    void FUN_004e65d0();
};
class TES_ML
{
  public:
    CellGrid_ML* FUN_0044ddc0();
    GridCell_ML* FUN_00457050(int, int);
    WorldAudio_ML* FUN_0070ec90();
};
class OSGlobals_ML
{
  public:
    int unk00;
    int unk04;
    HWND__* window;
    void FUN_00877430();
};
unsigned char __cdecl FUN_00446e10();
void __cdecl FUN_00bad4a0();
struct WindowRect_ML
{
    long left, top, right, bottom;
};
extern "C" __declspec(dllimport) long __stdcall GetWindowLongA(HWND__*, int);
extern "C" __declspec(dllimport) int __stdcall AdjustWindowRectEx(WindowRect_ML*, unsigned long, int, unsigned long);
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(HWND__*, HWND__*, int, int, int, int, unsigned int);

namespace MainLoopGlobals {
extern "C" BGSMoviePlayer_ML* DAT_0126fac4;
extern "C" TES_ML* DAT_011dea10;
extern "C" OSGlobals_ML* g_osGlobals;
extern "C" long __cdecl FUN_004dc1f0();
extern "C" long __cdecl FUN_004dc200();
}

}  // namespace fnv_00872570

#include <string.h>
namespace fnv_00a24830 {
extern "C" __declspec(dllimport) void* __stdcall GetForegroundWindow();

}  // namespace fnv_00a24830

namespace fnv_0086f940 {
class BGSAcousticSpace;
// Required virtual interface: the pack leaves the update slot untyped.
struct Receiver86;
extern Receiver86* g_dataHandler;
extern unsigned int _DAT_011dea10;
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
struct UpdateScale
{
    float FUN_009c8cc0();
};
extern UpdateScale DAT_011f2250;
bool FUN_00709bc0();
extern bool DAT_011dea2b;
struct RenderManager
{
    void FUN_00b655b0();
};
RenderManager* FUN_00b4f5c0();

}  // namespace fnv_0086f940

namespace fnv_0086d590 {
struct NiAVObject;
struct AutoMemHelper
{
    int context;
    AutoMemHelper(int, int, const char*, int);
    ~AutoMemHelper();
};

struct NiFixedString
{
    int value;
    NiFixedString(const char*);
    ~NiFixedString();
    const char* FUN_00438170(const char*);
    void FUN_004381b0();
};
struct ResourceObject;
struct Resource
{
    ResourceObject* object;
    ResourceObject* FUN_00559450();
    void FUN_0066b0d0(void* item);
};
struct ResourceObject
{
    ResourceObject* FUN_006629f0();
    void FUN_00712e60(void*);
    void FUN_0070b760(int);
    void FUN_004a1020(void*);
    ResourceObject* FUN_00558310();
    void FUN_00a5a040();
    void FUN_00a59c60(void*);
    void AssignFixedString(const NiFixedString&);
    void FUN_005468d0(int);
    void FUN_005467c0(int);
    void FUN_00546780(int);
    void SetDepthParams(float);
    void FUN_0049ed90(int);
    void FUN_00439410(void*);
    void FUN_004bc1f0(float, float, float);
    void FUN_004bc450(void*);
    void FUN_005b8fc0(int);
    void FUN_0060aeb0(int);
    void FUN_004f3200(int);
    int FUN_004bc320(int);
    void FUN_0086e3f0(int, int, int);
    void FUN_0086e420(int, float, float, float, float);
    void FUN_0086e4b0();
    void FUN_0086e460(int, int, float, float, float, float);
};
struct ModuleRoot
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
    virtual void virtual_dc(void*, int);
    virtual void virtual_e0();
    virtual void virtual_e4();
    virtual void virtual_e8();
    virtual void virtual_ec();
    virtual void virtual_f0();
    virtual void virtual_f4();
    virtual void virtual_f8(int, void*);
};

struct SceneObject : ModuleRoot
{
    SceneObject* FUN_00878610(const char*, int, int);
    void FUN_0086e420(float, float, float, float, int);
};
struct DataObject : ModuleRoot
{
    DataObject* FUN_00b5e0f0();
    void FUN_004dc540(void*);
};
struct RenderSystem
{
    void FUN_0086d590();
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    int unknown_28;
    int unknown_2c;
    int unknown_30;
    int unknown_34;
    int unknown_38;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    int unknown_48;
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    int unknown_58;
    int unknown_5c;
    int unknown_60;
    int unknown_64;
    int unknown_68;
    int unknown_6c;
    int unknown_70;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int unknown_80;
    int unknown_84;
    Resource resource88;
    Resource resource8c;
    Resource resource90;
    Resource resource94;
    Resource resource98;
};

extern Resource DAT_011deb7c;
extern Resource DAT_011deb00;
extern Resource DAT_011deb34;
extern Resource DAT_011ded3c;
extern int DAT_011dea18;
extern int DAT_011dea1c;
extern const char str_010829c4[];
extern int DAT_011ad840;

extern int FUN_00450b80(int);

extern void FUN_004bc1f0();
extern void* FUN_00b4f5c0();
extern int FUN_004bc320(int);
extern DataObject* FUN_0043c4b0();
extern void* __cdecl FUN_00aa13e0(unsigned int);
struct FUN_00b5e0f0 : NiMemObject
{
    FUN_00b5e0f0();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
    unsigned int unknown_b8;
    unsigned int unknown_bc;
    unsigned int unknown_c0;
    unsigned int unknown_c4;
    unsigned int unknown_c8;
    unsigned int unknown_cc;
    unsigned int unknown_d0;
    unsigned int unknown_d4;
    unsigned int unknown_d8;
    unsigned int unknown_dc;
    unsigned int unknown_e0;
    unsigned int unknown_e4;
    unsigned int unknown_e8;
    unsigned int unknown_ec;
    unsigned int unknown_f0;
    unsigned int unknown_f4;
    unsigned int unknown_f8;
    unsigned int unknown_fc;
    unsigned int unknown_100;
    unsigned int unknown_104;
    unsigned int unknown_108;
    unsigned int unknown_10c;
    unsigned int unknown_110;
    unsigned int unknown_114;
    unsigned int unknown_118;
    unsigned int unknown_11c;
    unsigned int unknown_120;
    unsigned int unknown_124;
    unsigned int unknown_128;
    unsigned int unknown_12c;
    unsigned int unknown_130;
    unsigned int unknown_134;
    unsigned int unknown_138;
    unsigned int unknown_13c;
    unsigned int unknown_140;
    unsigned int unknown_144;
    unsigned int unknown_148;
    unsigned int unknown_14c;
    unsigned int unknown_150;
    unsigned int unknown_154;
    unsigned int unknown_158;
    unsigned int unknown_15c;
    unsigned int unknown_160;
    unsigned int unknown_164;
    unsigned int unknown_168;
    unsigned int unknown_16c;
    unsigned int unknown_170;
    unsigned int unknown_174;
    unsigned int unknown_178;
    unsigned int unknown_17c;
    unsigned int unknown_180;
    unsigned int unknown_184;
    unsigned int unknown_188;
    unsigned int unknown_18c;
    unsigned int unknown_190;
    unsigned int unknown_194;
    unsigned int unknown_198;
    unsigned int unknown_19c;
    unsigned int unknown_1a0;
    unsigned int unknown_1a4;
    unsigned int unknown_1a8;
    unsigned int unknown_1ac;
    unsigned int unknown_1b0;
    unsigned int unknown_1b4;
    unsigned int unknown_1b8;
    unsigned int unknown_1bc;
    unsigned int unknown_1c0;
    unsigned int unknown_1c4;
    unsigned int unknown_1c8;
    unsigned int unknown_1cc;
    unsigned int unknown_1d0;
    unsigned int unknown_1d4;
    unsigned int unknown_1d8;
    unsigned int unknown_1dc;
    unsigned int unknown_1e0;
    unsigned int unknown_1e4;
    unsigned int unknown_1e8;
    unsigned int unknown_1ec;
    unsigned int unknown_1f0;
    unsigned int unknown_1f4;
    unsigned int unknown_1f8;
    unsigned int unknown_1fc;
};
struct NiUpdateData
{
    float time;
    bool updateControllers;
    bool multithreaded;
    unsigned int unknown_08;
    NiUpdateData(float, bool, bool);
};
struct SettingView
{
    float* FUN_00403e20();
};
}  // namespace fnv_0086d590

struct S00875bf0_Cam875
{
    void FUN_00712e60(const struct S00875bf0_Color875&);
};
struct S00875bf0_Color875
{
    float x, y, z, w;
    S00875bf0_Color875(float, float, float, float);
};
struct S00875bf0_Scene875
{
    void FUN_00c4f270(int);
    void FUN_0041fd00(S00875bf0_Cam875*);
    void FUN_004a0fd0(void*);
    void FUN_00c4f2d0();
};
struct FORenderedMenu
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
    S00875bf0_Cam875* FUN_008b6200();
};
FORenderedMenu* FUN_00707ad0();
FORenderedMenu* FUN_00705990();
extern unsigned char DAT_011f9426;
extern S00875bf0_Color875 DAT_011ad840;
void FUN_00b6bee0(S00875bf0_Cam875*, void*, S00875bf0_Scene875*);
void FUN_00b97e30(unsigned int, unsigned int);
void FUN_00b98380(int, int);
void FUN_00b6c0d0(S00875bf0_Cam875*, void*, int);
void FUN_004eced0(unsigned int);
void FUN_00714a60(int);
class ShadowSceneNode;
