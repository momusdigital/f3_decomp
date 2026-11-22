// fallout/interface/interfacemanager.cpp: InterfaceManager, ConsoleManager, IFH, BSAudioManager and more (16 functions)
#include "f3_common.h"
#include "interfacemanager_packet.h"
// @fnv 0x00714f70
// @fnv 0x008d8400
// @fnv 0x00713da0
// Multiplies both x and y of this NiPoint2 by scale and returns the resulting NiPoint2.
// @fnv 0x004a4f40
NiPoint2 NiPoint2::operator*(float scale) const
{
    NiPoint2 result = *this;
    result.x *= scale;
    result.y *= scale;
    return result;
}
// Counts the non-null items in the list by walking each node and incrementing a counter when GetItem returns a value.
// Counts the number of non-null items in the BSSimpleList by traversing from the head node to the end.
// @fnv 0x005ae380
// @fnv 0x00717de0
// @fnv 0x00715d40
// @fnv 0x00718fb0
SystemColorManager::SystemColor* SystemColorManager::Find(int trait)
{
    struct Search
    {
        SystemColor* color;
        void* position;
    } state;
    state.position = (void*)((BSStringT<char>*)this)->String();
    while (state.position)
    {
        state.color = (SystemColor*)((NiTPointerListBase<NiTPointerAllocator<unsigned int>, BSOcclusionPlane*>*)this)
                          ->GetNext(state.position);
        if (state.color && Tile::GetTraitID((const char*)((Interface*)state.color)->GetRoot()) == trait)
            return state.color;
    }
    return 0;
}
// Scans enterStack for the first empty slot and returns the matching previousStack entry, or enterStack[9] when full and 0 when empty.
// @fnv 0x00714f00

struct EffectSetting;
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;

struct Tile_
{
    Menu* GetMenu();
};
struct Menu
{
    void SetCurrentPageFromChar(unsigned char);
};
Tile_* FindMenuById(int);

namespace fnv_0070b810 {
struct InventoryStackRecord;
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;

Menu* __cdecl FindMenuById(int);

struct Tile_GetMenu_Accessor : public Tile
{
    Menu* GetMenu(void);
};

__declspec(noalias) inline Menu* CallTileGetMenu(Tile* pTile)
{
    return ((Tile_GetMenu_Accessor*)pTile)->GetMenu();
}

}  // namespace fnv_0070b810

namespace fnv_0070b870 {
struct Menu0b870;
struct Tile0b870
{
    Menu0b870* GetMenu();
};
struct Menu0b870
{
    void FUN_007069f0(int);
};
Tile0b870* __cdecl FindMenuById(int);
}  // namespace fnv_0070b870

struct BSAudio_
{
    void FUN_00ad8510(int, int);
    void FUN_0070bba0();
};

class BSAudioManager
{
  public:
    void DisableAudioPlayback(unsigned int, bool);
};

namespace fnv_0070bc00 {
struct BSAudioManager
{
    void DisableAudioPlayback(unsigned int, bool);
};

}  // namespace fnv_0070bc00

struct FUN_0070c3b0_Dummy
{
    char pad[0x698];
    float m_fValue;
    float Get()
    {
        return m_fValue;
    }
};

int g_011d8950;

class StartMenu
{
  public:
    enum Flag
    {
        FLAG_1 = 1
    };
    bool IsFlagSet(Flag);
};

extern StartMenu* DAT_011daac0;

struct FUN_00710ab0_Class
{
    char pad[0x670];
    float val;
    float Get()
    {
        return val;
    }
};

float __cdecl FUN_00715da0(void);

float __cdecl FUN_00715da0(void);

struct S5
{
    void SetByteAtOffset60();
};
struct S4
{
    S5* FUN_004ebbc0(int, unsigned char);
    void FUN_004019c0(unsigned int, int);
    void FUN_00617750();
    void FUN_007123a0(unsigned char);
    S4* FUN_007123a0(unsigned int);
};
// Calls FUN_004ebbc0 with 0xf and a, then calls SetByteAtOffset60 on the returned object.
// @f3 0x00637810 (community match, verified in this file)
// pdb: NiTPointerListBase<NiTPointerAllocator<unsigned int>,unsigned int>::AddHead | HackingMenu.obj | fnv360_0822_debug, call_gap_sim, low
// pdb params: element
S4* S4::FUN_007123a0(unsigned int value)              // ORIG entry at 0x00637810, twenty-eight bytes ✓⚠',
{                                                           //     their unit declares TWO overloads of this ⚗✓',
    FUN_004019c0(value, 0);                            //     name - mine is the unsigned int one at line ✗⚠',
                                                           //     112, so the definition must match that one ✓⚠',
    FUN_00617750();                                    // ORIG: mov esi,ecx happens BEFORE the first call ⚠✓',
                                                           //     - this is parked in ESI because both calls ✓✗✓',
    return this;                                       //     clobber it - then ecx is restored for the ⚠✓',
}                                                            //     second thiscall and ESI becomes the result ✓⚠'


struct BSRenderedTexture;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct RgbaColor;
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
    NiPoint2 m_kRadialBlurCenter;
    NiPoint2 m_kWeatherRadialBlurCenter;
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
    NiPoint2 m_kRadialBlurOrigin;
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
};
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];

struct _Rect16_00712e60
{
    float a, b, c, d;
};

struct _Cam_00712e60
{
    char pad[0x100];
    _Rect16_00712e60 m_kPort;
    void FUN_00712e60(const _Rect16_00712e60& kPort);
};

struct M3_
{
    void SetElement(unsigned int, float, float, float);
};

class ActorTaskManager
{
  public:
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

class NavMeshEdgeSegment;
template <> class BSSimpleArray<NavMeshEdgeSegment, 1024>
{
  public:
    bool FUN_0076b610(void) const;
};

class Script
{
  public:
    virtual ~Script();
};

template <> class NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*>
{
  public:
    Script* RemoveHead(void);
};

extern ActorTaskManager g_011d8c18;
extern NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*> g_011d8b2c;

// Queries the performance counter, deletes scripts from g_011d8b2c until the array check passes, then waits for tasks during rendering.
// @fnv 0x00713c00
void WaitForTasksAndClearScripts()
{
    g_011d8c18.QueryPerformanceCounter(0);
    while (!((BSSimpleArray<NavMeshEdgeSegment, 1024>*)&g_011d8b2c)->FUN_0076b610())
    {
        delete g_011d8b2c.RemoveHead();
    }
    g_011d8c18.WaitForTasksDuringRendering();
}

class NavMesh;
bool __cdecl FUN_009a3830(NavMesh* const&, NavMesh* const&);

struct S148c0
{
    void** vt;
    bool FUN_004a0e10(const char*, int);
    void FUN_007148c0(int a, int b);
};
typedef void(__thiscall* Fn148c0)(S148c0*, int, int);

extern unsigned char* DAT_011f5b04;

enum BSRENDERSTATE_LOCK
{
    BSRENDERSTATE_LOCK_0 = 0
};

namespace fnv_00714fd0 {

class ImageSpaceManager
{
  public:
    static ImageSpaceManager* __cdecl FUN_004e3270();
    void FUN_007123a0(bool);
};

void __cdecl FUN_00703610();

}  // namespace fnv_00714fd0

extern float DAT_0106f2dc;

class TES
{
  public:
    void SetTESActive(bool);
};

extern TES* g_TES;

void __cdecl operator delete(void*);

float __cdecl FUN_00404010(float, float);
float __cdecl FUN_0040ebd0(float, float);

struct TimeGlobal
{
    int GetSection();
};
extern TimeGlobal g_timeGlobal;

namespace fnv_00716910 {
class Menu;
Menu* __cdecl FindMenuById(int);

}  // namespace fnv_00716910

struct Str6a70
{
    char p[8];
    Str6a70& operator=(const char*);
};

struct S7010
{
    char pad[0x10];
    unsigned int len;
    char pad2[0xd];
    bool flag;
    unsigned int Length();
    void FUN_00717010(bool b);
};

namespace fnv_00717050 {
class AnimIdle
{
  public:
    int GetSection(void);
};

extern AnimIdle g_timeGlobal;

}  // namespace fnv_00717050

bool __cdecl FUN_004de080(void);

class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

extern GlobalObject2_0040c150 g_011d8bd8;

namespace fnv_00717820 {
class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

extern GlobalObject2_0040c150 g_011d8bf0;

}  // namespace fnv_00717820

namespace fnv_00717990 {
class BSAudio
{
  public:
    unsigned int GetSynchTime();
};

extern char* DAT_011d8a80;
class Menu* __cdecl FindMenuById(int);

namespace fnv_anon_interfacemanager {}
using namespace fnv_anon_interfacemanager;
namespace fnv_anon_interfacemanager {
struct InterfaceManager_Access : InterfaceManager
{
    static bool __cdecl IsPipboyMenuActive();
};
static bool (*const pIsInPipboyMenu)() = &InterfaceManager_Access::IsPipboyMenuActive;

struct Tile_Access : Tile
{
    NiNode* FUN_0056c7f0();
};
static NiNode* (Tile_Access::*const pTileFunc)() = &Tile_Access::FUN_0056c7f0;
}

}  // namespace fnv_00717990

struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;

struct DummyItem
{
    virtual bool v0(Tile*);
};

struct DummyNode;

DummyItem** __fastcall _ref_006815c0(DummyNode*);
DummyNode* __fastcall _ref_00726070(DummyNode*);
extern DummyNode g_011d8b54;

namespace fnv_00717ef0 {
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;
struct FUN_00717ef0_shell : public InterfaceManager
{
    void FUN_00717ef0(Menu*, int, Tile*);
};

struct ListBoxBase_00717ef0
{
    virtual bool vfn0(int);
    virtual Tile* vfn1();
};

struct GlobalObject2_0096a2d0;
extern GlobalObject2_0096a2d0 g_011d8b54;

ListBoxBase_00717ef0** __fastcall _ref_006815c0(GlobalObject2_0096a2d0*);
GlobalObject2_0096a2d0* __fastcall _ref_00726070(GlobalObject2_0096a2d0*);

}  // namespace fnv_00717ef0

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
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
struct TESImageSpaceModifier;
struct TESObjectREFR;
struct TESSound;
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

class PlayerCharacter
{
  public:
    static bool __cdecl UpdatePlayerStatus();
    bool FUN_00967ae0();
};

bool __fastcall FUN_00967ae0(PlayerCharacter*);

class InventoryStackRecord
{
  public:
    InventoryStackRecord();
};

class NavMesh;
bool __cdecl FUN_009a3830(NavMesh* const&, NavMesh* const&);

template <> class BSSimpleArray<NavMesh*, 1024>
{
  public:
    unsigned int Find(NavMesh* const&, unsigned int, bool(__cdecl*)(NavMesh* const&, NavMesh* const&));
};

struct FUN_009962f0_s
{
    bool f(NavMesh* const& aValue);
};
static bool (FUN_009962f0_s::*volatile p_f)(NavMesh* const&) = &FUN_009962f0_s::f;

// Returns whether Find locates aValue in the array using FUN_009a3830, i.e. the index is not -1.
// @fnv 0x009962f0
bool FUN_009962f0_s::f(NavMesh* const& aValue)
{
    return ((BSSimpleArray<NavMesh*, 1024>*)this)->Find(aValue, 0, FUN_009a3830) != (unsigned int)-1;
}

struct CF845
{
    unsigned int v;
    CF845(int);
};
typedef CF845 bhkFilter;
struct bhkWorldObject
{
    bhkFilter FUN_0043b4f0();
};
struct Flt
{
    operator bhkWorldObject*() const;
};

namespace fnv_007157b0 {
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;

namespace fnv_00717ef0 {
struct Menu;
struct FUN_00717ef0_shell
{
    void FUN_00717ef0(Menu*, int, Tile*);
};
}
struct TileHelper
{
    void Set(int, int);
    float GetFloat(int);
};
}  // namespace fnv_007157b0

namespace fnv_007181d0 {
struct BSRenderedTexture;
struct FORenderedMenu;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiGeometry;
struct NiPointLight;
struct NiTexture;
struct blob16
{
    char b[16];
};

struct FORenderedMenu
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
    bool GetInitialized();
    void FUN_007fae70(int);
};
struct TileHelper
{
    void Set(int, int);
};
struct InterfaceHelper
{
    FORenderedMenu* GetPipboyManager();
};
}  // namespace fnv_007181d0

namespace p07 {
}

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

struct SystemColor
{
    virtual void v0();
    virtual int GetValue() const;
    void FUN_007193b0(RgbaColor* aOutColor) const;
};

namespace fnv_0070c4a0 {
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuTileComponent;
struct MenuValueDescriptor;
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
struct GamepadManager
{
    int InitGamePads();
    void Poll(unsigned long);
    bool IsChangeDetected();
    bool IsPadActive(int);
    unsigned long GetPhysicalPort(int);
    MenuTileComponent* GetPad(int);
    unsigned int ButtonState(int, int);
    unsigned int AllButtonStates(int);
    int ButtonForce(int, int);
    bool CheckSoftReset(int);
    void SetButtonState(int, int, unsigned int);
    void SetButtonForce(int, int, int);
    static void SetDeadZoneAbs(int, float);
    static float GetDeadZoneAbs(int);
    unsigned int PressedButtons(int);
    unsigned int ClickButtons(int);
    unsigned int DebounceButtons(int);
    unsigned int RepeatButtons(int);
    void Rumble(int, float, float, int, int, int, bool, bool);
    void RumbleFull(int, int);
    void UpdateRumbles(int);
    void KillRumbles();
    void KillRumble(int);
    static bool SomeonePressedStart(int*);
    void* __vecDelDtor(unsigned int);
    char m_cPadData[816];
    bool m_bChangeDetected;
    char _pad_331[3];
};
typedef char _sizecheck_XInputManager[sizeof(GamepadManager) == 820 ? 1 : -1];
struct Controls : public GamepadManager
{
    static Controls* GetInstance();
    static void DeleteInstance();
    void Poll(float, bool, bool);
    void ClearKeystrokes();
    int GetNextKeystroke(int*);
    int GetNextKeyEvent(int*);
    void ResetControls();
    void SetMenuDeadZone(int, bool);
    void SetMenuDeadZone(bool);
    unsigned int GetButtonState(int);
    int GetButtonForce(int);
    void GetMouseDelta(unsigned int, NiPoint2*);
    void GetMouseAbs(unsigned int, NiPoint2*);
    void SetMouseSpeed(unsigned int, float);
    float GetMouseSpeed(int);
    void GetMouseAxis(int*, int*);
    void GetMouseAxis(unsigned int, int*, int*);
    int GetMouseButton(int, int);
    int TranslateKeystroke(int, int);
    int GetUserAction(int, int);
    void ForceUserAction(int);
    void ClearUserActions();
    void ClearUserAction(int);
    unsigned int GetDigitalAction(int, unsigned int);
    int GetAnalogAction(int);
    long GetJoystickAxis(int, int);
    void SetStickConfiguration(int);
    void SetDigitalAction(int, unsigned int);
    void SetAnalogAction(int, int);
    int GetControlValue(int);
    void LoadControl(int, unsigned int);
    void Rumble(float, float, int, int, int, bool, bool);
    void RumbleFull(int);
    void KillRumble();
    bool PerformAction(int);
    static void EnableRumble(bool);
    static bool IsRumbleEnabled();
    bool IsSettingControl();
    bool isControllerValid();
    bool SetCurrentController(int);
    int GetCurrentController();
    void SetFlag(unsigned short);
    bool GetFlag(unsigned short);
    unsigned int PressedButtons();
    unsigned int ClickButtons();
    unsigned int DebounceButtons();
    unsigned int RepeatButtons();
    void SaveControls();
    void LoadControls(unsigned char*, unsigned int);
    static bool Remappable(int);
    static bool RemappableButton(int);
    static void GetIconForButton(int, void*, bool);
    static void ResetMappingsToDefault(bool);
    bool RemapTo(int, int);
    int RemapAction(int, unsigned int);
    float GetRunScale();
    int GetKeyboardButton(int, int);
    void RemoveDuplicateControls(int, int);
    void UpdateMouse(float);
    void UpdateKeyboard(bool);
    int MenuUserAction(int, int);
    void* __vecDelDtor(unsigned int);
    int m_iInputValueAtOffset334;
    int m_iInputValueAtOffset338;
    bool m_bInputFlagAtOffset33C;
    bool m_bInputFlagAtOffset33D;
    char _pad_33e[2];
    float m_fInputValueAtOffset340;
    float m_fInputValueAtOffset344;
    float m_fInputValueAtOffset348;
    bool m_bInputFlagAtOffset34C;
    bool m_bInputFlagAtOffset34D;
    char _pad_34e[2];
    float m_fInputValueAtOffset350;
    float m_fInputValueAtOffset354;
    unsigned short m_uiParameterCount;
    char _pad_35a[2];
    char m_acInputDataAtOffset35C[32];
    char m_acInputDataAtOffset37C[16];
    bool m_bInputFlagAtOffset38C;
    char _pad_38d[3];
    int m_iInputValueAtOffset390;
    int m_iInputValueAtOffset394;
    char m_acInputDataAtOffset398[7];
    char _pad_39f[1];
    char m_acInputDataAtOffset3A0[208];
};
typedef char _sizecheck_Controls[sizeof(Controls) == 1136 ? 1 : -1];

struct TileH;
struct MenuH;
struct NiAVH
{
    void SetAppCulled(bool);
};
struct ListH
{
    int _a;
    void* Find(TileH* const&, void*);
    unsigned int Head();
    TileH*& GetNext(void*&);
};
struct TileH
{
    int _vt;
    ListH lst;
    NiAVH* FUN_0056c7f0();
    void Set(int, int);
    void Set(int, float, bool);
    void Set(int, const char*, bool);
    bool ContainsTrait(int);
    MenuH* GetMenu();
    TileH* GetNamedChild(const char*);
    bool IsVisible();
    float GetFloat(int);
    float GetTotalFloat();
    float GetAccumulatedFloat();
    void FUN_00a0b110(int);
    void FUN_00a04640(int);
    void* FindTraitValue(int);
    char* FUN_00a011f0(int);
    void* GetNext();
};
struct MenuH
{
    virtual void v00();
    virtual void v04();
    virtual void vf08(int, TileH*);
    virtual void vf0c(int, TileH*);
    virtual void v10();
    virtual void vf14(int, TileH*);
    virtual void vf18(int, TileH*, TileH*);
    virtual void vf1c(int, TileH*, TileH*);
    virtual void vf20(int, TileH*);
    virtual void vf24(int, TileH*);
    virtual void v28();
    virtual void vf2c();
    virtual bool vf30(int);
    unsigned int GetThreadID();
};
struct SndH
{
    int _a;
    int _b;
    int _c;
    SndH();
    SndH& operator=(const SndH&);
    ~SndH();
    bool Play(bool);
    void PausePlayback();
};
struct AudH
{
    static AudH* GetSingleton();
    SndH GetSoundHandleByEditorID(const char*, unsigned int);
    void FUN_0070bc00();
};
struct GSet
{
    const char* Get();
};
struct GInt
{
    int* Int();
};
struct ArrSIH
{
    unsigned int GetFlags();
};
struct TG
{
    unsigned int GetSection();
    float GetStoredFloatValue();
};
struct PCH
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
    virtual int vf214();
    virtual void pv218();
    virtual void pv21c();
    virtual void pv220();
    virtual void pv224();
    virtual void pv228();
    virtual bool vf22c(bool);
    bool FUN_005a03f0(unsigned int);
    bool FUN_00950090();
    bool IsAlert();
    void FUN_0095d090();
    void ClearActorList();
};
int __stdcall FUN_009f996e(int, void*);
float GetRatio();
float FUN_00717860();
bool FUN_0070edf0();
void* FUN_0076bfe0();
bool FUN_007024e0();
bool FUN_0070ec00();
int FUN_00717a40(int, int);
void __fastcall FUN_0070bbc0(AudH*);
extern bool DAT_011d8a84;
extern bool DAT_0119f348;
extern GSet g_011d475c;
extern GInt g_011c3ea4;
extern PCH* g_thePlayer;
extern ArrSIH DAT_011f2250;
void* FindMenuById(int);
extern TG g_timeGlobal;
TileH* __fastcall _ref_00726070(MenuH*);
}  // namespace fnv_0070c4a0

void* __cdecl operator new(unsigned int);
struct Scratch
{
    int a;
    int b;
    int c;
    int d;
};
int __stdcall FUN_009f996e(int, Scratch*);
struct UIRoot
{
    char pad[0x20];
    bool flagA;
    bool flagB;
    char pad2[0x580 - 0x22];
    UIRoot();
    void InitInterface(bool);
    void FUN_0070b240();
};
extern UIRoot* DAT_011d8a80;
extern bool DAT_011d8a84;

namespace fnv_0070a130 {
namespace lc1 {
class AutoMemContext
{
  public:
    AutoMemContext(int aeContext, bool abEnter, const char* apFile, int aiLine);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}

template <class T> class NiPointer
{
  public:
    NiPointer(T* apObject = 0);
    ~NiPointer();
    NiPointer& operator=(T* apObject);
    operator T*() const;
    T* operator->() const;
    T* m_pObject;
};

class MenuAlphaProperty
{
  public:
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem, unsigned int);
    MenuAlphaProperty();
    void FUN_0049ed90(bool abEnable);
    void FUN_00636000(bool abEnable);
    void FUN_00439340(int aeMode);
    void FUN_00439390(int aeMode);
    char m_data[0x1c];
};

class BSShaderAccumulator
{
  public:
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem, unsigned int);
    BSShaderAccumulator(int aeMode, unsigned int auiA, unsigned int auiB);
    void FUN_004a1040(int aiValue);
    void FUN_0070a900(bool abValue);
    char m_data[0x280];
};

class TimeGlobal
{
  public:
    int GetSection();
};
extern TimeGlobal g_timeGlobal;

extern char DAT_011d8a50;
extern int DAT_011d8a64;
extern float DAT_011d8a68;

}  // namespace fnv_0070a130

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

namespace lc1 {
struct AutoMemContext
{
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}

void* __cdecl operator new(unsigned int);

struct NiUpdateDataH
{
    void FUN_0043d410(float, bool, bool);
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
};

class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

class NiFixedString
{
  public:
    NiFixedString(const char*);
    ~NiFixedString();
    const char* m_kHandle;
};

class NiAVObject : public NiMemObject
{
  public:
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
    void SetName(const NiFixedString&);
    void SetAppCulled(bool);
    void UpdateSceneObject();
    void Update(NiUpdateDataH&);
};

class NiNode : public NiAVObject
{
  public:
    NiNode(unsigned short);
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
    char pad[0xa8];
};

template <class T> class NiPointer
{
  public:
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    T* m_pObject;
};

struct Tile_Set_Helper
{
    void Set(int, int);
};
struct TileH
{
    void Set(int, float, bool);
    Tile* ReadFile(const char*);
};
struct Tile_Helper
{
    static void UpdateAll(bool);
};
class Menu;
class TESForm;
struct MenuH
{
    static bool ReadMenuDefinition(const char*, Menu*);
};
struct KFModel
{
    void* GetControllerSequence();
};
struct Setting_S
{
    float* Float();
};
struct GlobalObject_0045cfe0
{
    void FUN_0045ce80(int);
};

double __cdecl FUN_00706e20();
double __cdecl FUN_00706e50();
float __cdecl FUN_00715da0();
float __cdecl FUN_007177c0();
float __cdecl FUN_00717820();

struct NP
{
    void* p;
    NP& operator=(void*);
    ~NP();
};

namespace fnv_0070bc20 {
struct Actor;
struct Animation;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSFaceGenNiNode;
struct SoundPlaybackHandle;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryStackRecord;
struct NiAVObject;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct NiStream;
struct Script;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESModel;
struct TESObjectCELL;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESSound;
struct bhkNiCollisionObject;
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
struct blob64
{
    char b[64];
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
struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];

struct NiAVObject;
struct bhkWorld;
struct NiCamera;

struct Vec3
{
    float x, y, z;
    Vec3();
    Vec3& operator+=(const Vec3&);
    Vec3 operator+(const Vec3&) const;
    Vec3 operator*(float) const;
};

struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    ThreeByThreeMatrix();
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix&) const;
    void FUN_004a0c90(float);
    void FUN_00524ac0(float);
    void FUN_00439f50(unsigned int, Vec3&);
};

struct CollisionFilter
{
    unsigned int iFilter;
    CollisionFilter(int);
    void FUN_004a39f0(int);
    unsigned int FUN_004a3a20();
    void FUN_0059ce80(unsigned int);
};

struct NiPickRecord
{
    NiAVObject* FUN_00458b50();
    float GetDistance();
};

struct NiPickResults
{
    unsigned int GetEffectiveSize();
    NiPickRecord* GetAt(unsigned int);
};

struct NiPick
{
    unsigned int m_data[13];
    NiPick(int, int);
    ~NiPick();
    NiPickResults* GetResults();
};

struct TESForm
{
    unsigned char GetFormType();
};

struct TESObjectREFR
{
    static TESObjectREFR* __cdecl GetReferenceFromNiAVObject(NiAVObject*);
    TESForm* GetObjectReference();
};

struct TESObjectCELL
{
    bhkWorld* FUN_004543c0();
};

struct TESContainer
{
    static bool __cdecl IsValidContainerType(unsigned char);
};

struct HUDMainMenu
{
    static bool __cdecl UpdateTargetReference(TESObjectREFR*, bool, bool);
};

struct bhkCharacterController
{
    CollisionFilter FUN_0070c440();
};

struct PlayerCharacter
{
    virtual void Unk000();
    virtual void Unk001();
    virtual void Unk002();
    virtual void Unk003();
    virtual void Unk004();
    virtual void Unk005();
    virtual void Unk006();
    virtual void Unk007();
    virtual void Unk008();
    virtual void Unk009();
    virtual void Unk010();
    virtual void Unk011();
    virtual void Unk012();
    virtual void Unk013();
    virtual void Unk014();
    virtual void Unk015();
    virtual void Unk016();
    virtual void Unk017();
    virtual void Unk018();
    virtual void Unk019();
    virtual void Unk020();
    virtual void Unk021();
    virtual void Unk022();
    virtual void Unk023();
    virtual void Unk024();
    virtual void Unk025();
    virtual void Unk026();
    virtual void Unk027();
    virtual void Unk028();
    virtual void Unk029();
    virtual void Unk030();
    virtual void Unk031();
    virtual void Unk032();
    virtual void Unk033();
    virtual void Unk034();
    virtual void Unk035();
    virtual void Unk036();
    virtual void Unk037();
    virtual void Unk038();
    virtual void Unk039();
    virtual void Unk040();
    virtual void Unk041();
    virtual void Unk042();
    virtual void Unk043();
    virtual void Unk044();
    virtual void Unk045();
    virtual void Unk046();
    virtual void Unk047();
    virtual void Unk048();
    virtual void Unk049();
    virtual void Unk050();
    virtual void Unk051();
    virtual void Unk052();
    virtual void Unk053();
    virtual void Unk054();
    virtual void Unk055();
    virtual void Unk056();
    virtual void Unk057();
    virtual void Unk058();
    virtual void Unk059();
    virtual void Unk060();
    virtual void Unk061();
    virtual void Unk062();
    virtual void Unk063();
    virtual void Unk064();
    virtual void Unk065();
    virtual void Unk066();
    virtual void Unk067();
    virtual void Unk068();
    virtual void Unk069();
    virtual void Unk070();
    virtual void Unk071();
    virtual void Unk072();
    virtual void Unk073();
    virtual void Unk074();
    virtual void Unk075();
    virtual void Unk076();
    virtual void Unk077();
    virtual void Unk078();
    virtual void Unk079();
    virtual void Unk080();
    virtual void Unk081();
    virtual void Unk082();
    virtual void Unk083();
    virtual void Unk084();
    virtual void Unk085();
    virtual void Unk086();
    virtual void Unk087();
    virtual void Unk088();
    virtual void Unk089();
    virtual void Unk090();
    virtual void Unk091();
    virtual void Unk092();
    virtual void Unk093();
    virtual void Unk094();
    virtual void Unk095();
    virtual void Unk096();
    virtual void Unk097();
    virtual void Unk098();
    virtual void Unk099();
    virtual void Unk100();
    virtual void Unk101();
    virtual void Unk102();
    virtual void Unk103();
    virtual void Unk104();
    virtual void Unk105();
    virtual void Unk106();
    virtual void Unk107();
    virtual void Unk108();
    virtual void Unk109();
    virtual void Unk110();
    virtual void Unk111();
    virtual void Unk112();
    virtual void Unk113();
    virtual void Unk114();
    virtual void Unk115();
    virtual void Unk116();
    virtual void Unk117();
    virtual void Unk118();
    virtual void Unk119();
    virtual void Unk120();
    virtual void Unk121();
    virtual void Unk122();
    virtual void Unk123();
    virtual void Unk124();
    virtual Vec3* GetPos();
    virtual void Unk126();
    virtual void Unk127();
    virtual void Unk128();
    virtual void Unk129();
    virtual void Unk130();
    virtual void Unk131();
    virtual void Unk132();
    virtual void Unk133();
    virtual void Unk134();
    virtual void Unk135();
    virtual void Unk136();
    virtual void Unk137();
    virtual void Unk138();
    virtual void Unk139();
    virtual void Unk140();
    virtual void Unk141();
    virtual void Unk142();
    virtual void Unk143();
    virtual void Unk144();
    virtual void Unk145();
    virtual void Unk146();
    virtual void Unk147();
    virtual void Unk148();
    virtual void Unk149();
    virtual void Unk150();
    virtual void Unk151();
    virtual void Unk152();
    virtual void Unk153();
    virtual void Unk154();
    virtual void Unk155();
    virtual void Unk156();
    virtual void Unk157();
    virtual void Unk158();
    virtual void Unk159();
    virtual void Unk160();
    virtual void Unk161();
    virtual void Unk162();
    virtual void Unk163();
    virtual void Unk164();
    virtual void Unk165();
    virtual void Unk166();
    virtual void Unk167();
    virtual void Unk168();
    virtual void Unk169();
    virtual void Unk170();
    virtual void Unk171();
    virtual void Unk172();
    virtual void Unk173();
    virtual void Unk174();
    virtual float GetCurrentTargetDistance(int);
    Vec3* GetFieldAtOffsetDD4();
    float FUN_0070c3b0();
    float GetScale();
    bool Script_IsCurrentFurnitureObj();
    Vec3 GetPosition();
    float GetLooking();
    CollisionFilter GetVectorElement();
    bhkCharacterController* GetPhysicsCharacterController();
    TESObjectCELL* GetParentCell();
    bool FUN_0070c3d0();
};

struct TES
{
    bool ApplyToObject(NiPick&, Vec3&, Vec3&, float, int);
    bool FUN_004570d0(NiPick&, Vec3&, Vec3&, float);
};

bool __fastcall FUN_00644640(void*);
Tile* FindMenuById(int);
Tile* FUN_0076bfe0();
float __cdecl FUN_0040ebd0(float, float);
extern PlayerCharacter* g_thePlayer;
extern TES* g_TES;

}  // namespace fnv_0070bc20

namespace fnv_0070ee80 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct FindData;
struct HWND__;
struct KFModel;
struct NiAVObject;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiNode;
struct NiPoint3;
struct TESAnimGroup;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESIdleForm;
struct TESModel;
struct TESObjectREFR;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
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
    char m_kNodeTranslation[12];
    char m_kRootTranslation[12];
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

struct TESObjectWEAP
{
    int GetWeaponType() const;
};
struct InventoryStackRecord
{
    TESObjectWEAP* GetFlags();
};
struct PlayerCharacter;
struct BaseProcess
{
    virtual void Unk_000();
    virtual void Unk_001();
    virtual void Unk_002();
    virtual void Unk_003();
    virtual void Unk_004();
    virtual void Unk_005();
    virtual void Unk_006();
    virtual void Unk_007();
    virtual void Unk_008();
    virtual void Unk_009();
    virtual void Unk_010();
    virtual void Unk_011();
    virtual void Unk_012();
    virtual void Unk_013();
    virtual void Unk_014();
    virtual void Unk_015();
    virtual void Unk_016();
    virtual void Unk_017();
    virtual void Unk_018();
    virtual void Unk_019();
    virtual void Unk_020();
    virtual void Unk_021();
    virtual void Unk_022();
    virtual void Unk_023();
    virtual void Unk_024();
    virtual void Unk_025();
    virtual void Unk_026();
    virtual void Unk_027();
    virtual void Unk_028();
    virtual void Unk_029();
    virtual void Unk_030();
    virtual void Unk_031();
    virtual void Unk_032();
    virtual void Unk_033();
    virtual void Unk_034();
    virtual void Unk_035();
    virtual void Unk_036();
    virtual void Unk_037();
    virtual void Unk_038();
    virtual void Unk_039();
    virtual void Unk_040();
    virtual void Unk_041();
    virtual void Unk_042();
    virtual void Unk_043();
    virtual void Unk_044();
    virtual void Unk_045();
    virtual void Unk_046();
    virtual void Unk_047();
    virtual void Unk_048();
    virtual void Unk_049();
    virtual void Unk_050();
    virtual void Unk_051();
    virtual void Unk_052();
    virtual void Unk_053();
    virtual void Unk_054();
    virtual void Unk_055();
    virtual void Unk_056();
    virtual void Unk_057();
    virtual void Unk_058();
    virtual void Unk_059();
    virtual void Unk_060();
    virtual void Unk_061();
    virtual void Unk_062();
    virtual void Unk_063();
    virtual void Unk_064();
    virtual void Unk_065();
    virtual void Unk_066();
    virtual void Unk_067();
    virtual void Unk_068();
    virtual void Unk_069();
    virtual void Unk_070();
    virtual void Unk_071();
    virtual void Unk_072();
    virtual void Unk_073();
    virtual void Unk_074();
    virtual void Unk_075();
    virtual void Unk_076();
    virtual void Unk_077();
    virtual void Unk_078();
    virtual void Unk_079();
    virtual void Unk_080();
    virtual void Unk_081();
    virtual InventoryStackRecord* GetActiveWeapon();
    virtual void Unk_083();
    virtual void Unk_084();
    virtual void Unk_085();
    virtual void Unk_086();
    virtual void Unk_087();
    virtual void Unk_088();
    virtual void Unk_089();
    virtual void Unk_090();
    virtual void Unk_091();
    virtual void Unk_092();
    virtual void Unk_093();
    virtual void Unk_094();
    virtual void Unk_095();
    virtual void Unk_096();
    virtual void Unk_097();
    virtual void Unk_098();
    virtual void Unk_099();
    virtual void Unk_100();
    virtual void Unk_101();
    virtual void Unk_102();
    virtual void Unk_103();
    virtual void Unk_104();
    virtual void Unk_105();
    virtual void Unk_106();
    virtual void Unk_107();
    virtual void Unk_108();
    virtual void Unk_109();
    virtual void Unk_110();
    virtual void Unk_111();
    virtual void Unk_112();
    virtual void Unk_113();
    virtual void Unk_114();
    virtual void Unk_115();
    virtual void Unk_116();
    virtual void Unk_117();
    virtual void Unk_118();
    virtual void Unk_119();
    virtual void Unk_120();
    virtual void Unk_121();
    virtual void Unk_122();
    virtual void Unk_123();
    virtual void Unk_124();
    virtual void Unk_125();
    virtual void Unk_126();
    virtual void Unk_127();
    virtual void Unk_128();
    virtual void Unk_129();
    virtual void Unk_130();
    virtual void Unk_131();
    virtual void Unk_132();
    virtual void Unk_133();
    virtual void Unk_134();
    virtual void Unk_135();
    virtual void Unk_136();
    virtual void Unk_137();
    virtual void Unk_138();
    virtual void Unk_139();
    virtual void Unk_140();
    virtual void Unk_141();
    virtual void Unk_142();
    virtual void Unk_143();
    virtual void Unk_144();
    virtual void Unk_145();
    virtual void Unk_146();
    virtual void Unk_147();
    virtual void Unk_148();
    virtual void Unk_149();
    virtual void Unk_150();
    virtual void Unk_151();
    virtual void Unk_152();
    virtual void Unk_153();
    virtual void Unk_154();
    virtual void Unk_155();
    virtual void Unk_156();
    virtual void Unk_157();
    virtual void Unk_158();
    virtual void Unk_159();
    virtual void Unk_160();
    virtual void Unk_161();
    virtual void Unk_162();
    virtual void Unk_163();
    virtual void Unk_164();
    virtual void Unk_165();
    virtual void Unk_166();
    virtual void Unk_167();
    virtual void Unk_168();
    virtual void Unk_169();
    virtual void Unk_170();
    virtual void Unk_171();
    virtual void Unk_172();
    virtual void Unk_173();
    virtual void Unk_174();
    virtual void Unk_175();
    virtual void Unk_176();
    virtual void Unk_177();
    virtual void Unk_178();
    virtual void Unk_179();
    virtual void Unk_180();
    virtual void Unk_181();
    virtual void Unk_182();
    virtual void Unk_183();
    virtual void Unk_184();
    virtual void Unk_185();
    virtual void Unk_186();
    virtual void Unk_187();
    virtual void Unk_188();
    virtual void Unk_189();
    virtual void Unk_190();
    virtual void Unk_191();
    virtual void Unk_192();
    virtual void Unk_193();
    virtual void Unk_194();
    virtual void Unk_195();
    virtual void Unk_196();
    virtual void Unk_197();
    virtual void Unk_198();
    virtual void Unk_199();
    virtual void Unk_200();
    virtual void Unk_201();
    virtual void Unk_202();
    virtual void Unk_203();
    virtual void Unk_204();
    virtual void Unk_205();
    virtual void Unk_206();
    virtual void Unk_207();
    virtual void Unk_208();
    virtual void Unk_209();
    virtual void Unk_210();
    virtual void Unk_211();
    virtual void Unk_212();
    virtual void Unk_213();
    virtual void Unk_214();
    virtual void Unk_215();
    virtual void Unk_216();
    virtual void Unk_217();
    virtual void Unk_218();
    virtual void Unk_219();
    virtual void Unk_220();
    virtual void Unk_221();
    virtual void Unk_222();
    virtual void Unk_223();
    virtual void Unk_224();
    virtual void Unk_225();
    virtual void Unk_226();
    virtual void Unk_227();
    virtual void Unk_228();
    virtual void Unk_229();
    virtual void Unk_230();
    virtual void Unk_231();
    virtual void Unk_232();
    virtual void Unk_233();
    virtual void Unk_234();
    virtual void Unk_235();
    virtual void Unk_236();
    virtual void Unk_237();
    virtual void Unk_238();
    virtual void Unk_239();
    virtual void Unk_240();
    virtual void Unk_241();
    virtual void Unk_242();
    virtual void Unk_243();
    virtual void Unk_244();
    virtual void Unk_245();
    virtual void Unk_246();
    virtual void Unk_247();
    virtual void Unk_248();
    virtual void Unk_249();
    virtual void Unk_250();
    virtual void Unk_251();
    virtual void Unk_252();
    virtual void Unk_253();
    virtual void Unk_254();
    virtual void Unk_255();
    virtual void Unk_256();
    virtual void Unk_257();
    virtual void Unk_258();
    virtual void Unk_259();
    virtual void Unk_260();
    virtual void Unk_261();
    virtual void Unk_262();
    virtual void Unk_263();
    virtual void Unk_264();
    virtual void Unk_265();
    virtual void Unk_266();
    virtual void Unk_267();
    virtual void Unk_268();
    virtual void Unk_269();
    virtual void Unk_270();
    virtual void Unk_271();
    virtual void Unk_272();
    virtual void Unk_273();
    virtual void Unk_274();
    virtual void Unk_275();
    virtual void Unk_276();
    virtual void Unk_277();
    virtual void Unk_278();
    virtual void Unk_279();
    virtual void Unk_280();
    virtual void Unk_281();
    virtual void Unk_282();
    virtual void Unk_283();
    virtual void Unk_284();
    virtual void Unk_285();
    virtual void Unk_286();
    virtual void Unk_287();
    virtual void Unk_288();
    virtual void Unk_289();
    virtual void Unk_290();
    virtual void Unk_291();
    virtual void Unk_292();
    virtual void Unk_293();
    virtual void Unk_294();
    virtual void Unk_295();
    virtual void Unk_296();
    virtual void Unk_297();
    virtual void Unk_298();
    virtual void Unk_299();
    virtual void Unk_300();
    virtual void Unk_301();
    virtual void Unk_302();
    virtual void Unk_303();
    virtual void Unk_304();
    virtual void Unk_305();
    virtual void Unk_306();
    virtual void Unk_307();
    virtual void Unk_308();
    virtual void Unk_309();
    virtual bool IsIdleReady(PlayerCharacter*);

    void ProcessNode(PlayerCharacter*);
};
struct PlayerCharacter
{
    virtual void Unk_000();
    virtual void Unk_001();
    virtual void Unk_002();
    virtual void Unk_003();
    virtual void Unk_004();
    virtual void Unk_005();
    virtual void Unk_006();
    virtual void Unk_007();
    virtual void Unk_008();
    virtual void Unk_009();
    virtual void Unk_010();
    virtual void Unk_011();
    virtual void Unk_012();
    virtual void Unk_013();
    virtual void Unk_014();
    virtual void Unk_015();
    virtual void Unk_016();
    virtual void Unk_017();
    virtual void Unk_018();
    virtual void Unk_019();
    virtual void Unk_020();
    virtual void Unk_021();
    virtual void Unk_022();
    virtual void Unk_023();
    virtual void Unk_024();
    virtual void Unk_025();
    virtual void Unk_026();
    virtual void Unk_027();
    virtual void Unk_028();
    virtual void Unk_029();
    virtual void Unk_030();
    virtual void Unk_031();
    virtual void Unk_032();
    virtual void Unk_033();
    virtual void Unk_034();
    virtual void Unk_035();
    virtual void Unk_036();
    virtual void Unk_037();
    virtual void Unk_038();
    virtual void Unk_039();
    virtual void Unk_040();
    virtual void Unk_041();
    virtual void Unk_042();
    virtual void Unk_043();
    virtual void Unk_044();
    virtual void Unk_045();
    virtual void Unk_046();
    virtual void Unk_047();
    virtual void Unk_048();
    virtual void Unk_049();
    virtual void Unk_050();
    virtual void Unk_051();
    virtual void Unk_052();
    virtual void Unk_053();
    virtual void Unk_054();
    virtual void Unk_055();
    virtual void Unk_056();
    virtual void Unk_057();
    virtual void Unk_058();
    virtual void Unk_059();
    virtual void Unk_060();
    virtual void Unk_061();
    virtual void Unk_062();
    virtual void Unk_063();
    virtual void Unk_064();
    virtual void Unk_065();
    virtual void Unk_066();
    virtual void Unk_067();
    virtual void Unk_068();
    virtual void Unk_069();
    virtual void Unk_070();
    virtual void Unk_071();
    virtual void Unk_072();
    virtual void Unk_073();
    virtual void Unk_074();
    virtual void Unk_075();
    virtual void Unk_076();
    virtual void Unk_077();
    virtual void Unk_078();
    virtual void Unk_079();
    virtual void Unk_080();
    virtual void Unk_081();
    virtual void Unk_082();
    virtual void Unk_083();
    virtual void Unk_084();
    virtual void Unk_085();
    virtual void Unk_086();
    virtual void Unk_087();
    virtual void Unk_088();
    virtual void Unk_089();
    virtual void Unk_090();
    virtual void Unk_091();
    virtual void Unk_092();
    virtual void Unk_093();
    virtual void Unk_094();
    virtual void Unk_095();
    virtual void Unk_096();
    virtual void Unk_097();
    virtual void Unk_098();
    virtual void Unk_099();
    virtual void Unk_100();
    virtual void Unk_101();
    virtual void Unk_102();
    virtual void Unk_103();
    virtual void Unk_104();
    virtual void Unk_105();
    virtual void Unk_106();
    virtual void Unk_107();
    virtual void Unk_108();
    virtual void Unk_109();
    virtual void Unk_110();
    virtual void Unk_111();
    virtual void Unk_112();
    virtual void Unk_113();
    virtual void Unk_114();
    virtual void Unk_115();
    virtual void Unk_116();
    virtual void Unk_117();
    virtual void Unk_118();
    virtual void Unk_119();
    virtual void Unk_120();
    virtual void Unk_121();
    virtual void Unk_122();
    virtual void Unk_123();
    virtual void Unk_124();
    virtual void Unk_125();
    virtual void Unk_126();
    virtual void Unk_127();
    virtual void Unk_128();
    virtual void Unk_129();
    virtual void Unk_130();
    virtual void Unk_131();
    virtual void Unk_132();
    virtual int GetSitSleepState();
    virtual void Unk_134();
    virtual void Unk_135();
    virtual void Unk_136();
    virtual void Unk_137();
    virtual void Unk_138();
    virtual void Unk_139();
    virtual void Unk_140();
    virtual void Unk_141();
    virtual void Unk_142();
    virtual void Unk_143();
    virtual void Unk_144();
    virtual void Unk_145();
    virtual void Unk_146();
    virtual void Unk_147();
    virtual void Unk_148();
    virtual void Unk_149();
    virtual void Unk_150();
    virtual void Unk_151();
    virtual void Unk_152();
    virtual void Unk_153();
    virtual void Unk_154();
    virtual void Unk_155();
    virtual void Unk_156();
    virtual void Unk_157();
    virtual void Unk_158();
    virtual void Unk_159();
    virtual void Unk_160();
    virtual void Unk_161();
    virtual void Unk_162();
    virtual void Unk_163();
    virtual void Unk_164();
    virtual void Unk_165();
    virtual void Unk_166();
    virtual void Unk_167();
    virtual void Unk_168();
    virtual void Unk_169();
    virtual void Unk_170();
    virtual void Unk_171();
    virtual void Unk_172();
    virtual void Unk_173();
    virtual void Unk_174();
    virtual void Unk_175();
    virtual void Unk_176();
    virtual void Unk_177();
    virtual void Unk_178();
    virtual void Unk_179();
    virtual void Unk_180();
    virtual void Unk_181();
    virtual void Unk_182();
    virtual void Unk_183();
    virtual void Unk_184();
    virtual void Unk_185();
    virtual void Unk_186();
    virtual void Unk_187();
    virtual void Unk_188();
    virtual void Unk_189();
    virtual void Unk_190();
    virtual void Unk_191();
    virtual void Unk_192();
    virtual void Unk_193();
    virtual void Unk_194();
    virtual void Unk_195();
    virtual void Unk_196();
    virtual void Unk_197();
    virtual void Unk_198();
    virtual void Unk_199();
    virtual void Unk_200();
    virtual void Unk_201();
    virtual void Unk_202();
    virtual void Unk_203();
    virtual void Unk_204();
    virtual void Unk_205();
    virtual void Unk_206();
    virtual void Unk_207();
    virtual void Unk_208();
    virtual void Unk_209();
    virtual void Unk_210();
    virtual void Unk_211();
    virtual void Unk_212();
    virtual void Unk_213();
    virtual void Unk_214();
    virtual void Unk_215();
    virtual void Unk_216();
    virtual void Unk_217();
    virtual void Unk_218();
    virtual void Unk_219();
    virtual void Unk_220();
    virtual void Unk_221();
    virtual void Unk_222();
    virtual void Unk_223();
    virtual void Unk_224();
    virtual void Unk_225();
    virtual void Unk_226();
    virtual void Unk_227();
    virtual void Unk_228();
    virtual void Unk_229();
    virtual void Unk_230();
    virtual void Unk_231();
    virtual void Unk_232();
    virtual void Unk_233();
    virtual void Unk_234();
    virtual void Unk_235();
    virtual void Unk_236();
    virtual void Unk_237();
    virtual void Unk_238();
    virtual void Unk_239();
    virtual void Unk_240();
    virtual void Unk_241();
    virtual void Unk_242();
    virtual void Unk_243();
    virtual void Unk_244();
    virtual void Unk_245();
    virtual void Unk_246();
    virtual void Unk_247();
    virtual void Unk_248();
    virtual void Unk_249();
    virtual void Unk_250();
    virtual void Unk_251();
    virtual void Unk_252();
    virtual void Unk_253();
    virtual void Unk_254();
    virtual void Unk_255();
    virtual void Unk_256();
    virtual void Unk_257();
    virtual void Unk_258();
    virtual void Unk_259();
    virtual void Unk_260();
    virtual void Unk_261();
    virtual void Unk_262();
    virtual void Unk_263();
    virtual void Unk_264();
    virtual void Unk_265();
    virtual void Unk_266();
    virtual void Unk_267();
    virtual void Unk_268();
    virtual void Unk_269();
    virtual void Unk_270();
    virtual void Unk_271();
    virtual void Unk_272();
    virtual void Unk_273();
    virtual void Unk_274();
    virtual void Unk_275();
    virtual void Unk_276();
    virtual void Unk_277();
    virtual void Unk_278();
    virtual void Unk_279();
    virtual void Unk_280();
    virtual void Unk_281();
    virtual void Unk_282();
    virtual void Unk_283();
    virtual void Unk_284();
    virtual void Unk_285();
    virtual void Unk_286();
    virtual void Unk_287();
    virtual void Unk_288();
    virtual void Unk_289();
    virtual void Unk_290();
    virtual void Unk_291();
    virtual void Unk_292();
    virtual void Unk_293();
    virtual void Unk_294();
    virtual void Unk_295();
    virtual void Unk_296();
    virtual void Unk_297();
    virtual void Unk_298();
    virtual void Unk_299();
    virtual void SetAnimGroup(unsigned short, int);

    int GetAnimAction();
    Animation* GetAnimation(bool);
    void FUN_00950460(int);
    void FUN_00962590();
    BaseProcess* GetLogDate();
};
extern PlayerCharacter* g_thePlayer;
struct TESAnimGroup
{
    float FUN_005f3780(int);
};
struct BSAnimGroupSequence
{
    float FUN_00639aa0();
    TESAnimGroup* GetAnimGroup() const;
};
struct FOPipboyManager
{
    void FUN_007f8a80();
    void UpdatePipboyLight(int);
};
struct InterfaceHelper
{
    static bool GetSelectedTargetIndex(int);
    static FOPipboyManager* GetPipboyManagerInstance();
    FOPipboyManager* GetPipboyManager();
};
struct HUDMainMenu
{
    static void UpdateVisibilityState(int);
};
struct TESImageSpaceModifier
{
    static TESImageSpaceModifier* GetGetHit();
};
struct SoundPlaybackHandle
{
    int soundID;
    bool assumeSuccess;
    int state;
    ~SoundPlaybackHandle();
    bool Play();
};
struct BSAudio
{
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByEditorID(const char*, unsigned int, int);
    void FUN_0070bba0();
};
void __fastcall FUN_0070bbc0(BSAudio*);
bool __fastcall FUN_00967ae0(PlayerCharacter*);
void _FNV_Warning(const char*);

}  // namespace fnv_0070ee80

namespace fnv_00712e90 {
struct NiPoint3;
struct NiStream;
struct SceneGraph;
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
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
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
typedef char _sizecheck_NiMatrix3[sizeof(ThreeByThreeMatrix) == 48 ? 1 : -1];
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiFrustum
{
    char* FormatToBuffer(char*);
    void __dflt_ctor_closure();
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
    char _pad_19[3];
};
typedef char _sizecheck_NiFrustum[sizeof(NiFrustum) == 28 ? 1 : -1];

namespace Local {
enum MEM_CONTEXT
{
    MC_INTERFACE = 13
};
struct AutoMemContext
{
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
    int m_eMemoryContext;
};
struct NiFrustum
{
    NiFrustum(bool);
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};
}

class NiFixedString
{
  public:
    NiFixedString(const char*);
    ~NiFixedString();
    const char* m_kHandle;
};

struct NiPoint3
{
    float x, y, z;
    NiPoint3(float, float, float);
};

struct M3_
{
    M3_();
    void SetElement(unsigned int, float, float, float);
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};

class NiRenderer
{
};

class GraphicsRenderer : public NiRenderer
{
  public:
    unsigned int GetRenderTargetHeight();
    unsigned int GetRenderTargetWidth();
};

NiRenderer* FUN_0043c4b0();

class NiAVObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
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
    void SetName(const NiFixedString&);
    void SetLocalRotation(const M3_&);
    NiPoint3& FUN_0043c490();
    void FUN_00440460(const NiPoint3&);
};

class NiCamera : public NiAVObject
{
  public:
    void UpdateViewFrustum(const Local::NiFrustum&);
};

class NiNode : public NiAVObject
{
  public:
    NiNode(unsigned short);
    char _pad_04[0xa8];
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
};

struct SceneGraph : public NiNode
{
    SceneGraph(const char*, bool, NiCamera*);
    char _pad_ac[0x14];
    NiCamera* GetCamera();
    void FUN_00c52020(float, int, int, int);
};

struct FaderManager
{
    void AddRoot(NiNode*, float, bool);
};

extern float DAT_0106f2dc;
extern FaderManager* DAT_011d8804;

}  // namespace fnv_00712e90

void* __cdecl operator new(unsigned int);
struct Widget
{
    Widget();
    virtual ~Widget();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void Run();
    char pad[0x170 - 4];
};
struct Owner
{
    char pad[0x174];
    Widget* pWidget;
};

namespace fnv_00713c70 {

struct IntHolder0
{
    char c;
};
extern IntHolder0 g_011c3ea4;
bool __cdecl FUN_0070edf0();
void* __cdecl FindMenuById(int);
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
struct TileHelper
{
    static void UpdateAll(bool);
    void SetSpeechChallengeFailure(bool);
};
struct Obj8c
{
    void WaitForEvent(int);
};
void __cdecl WaitForTasksAndClearScripts();
Obj8c* __stdcall FUN_00713d80(int);
void __stdcall FUN_00713d80();
}  // namespace fnv_00713c70

struct FltHelper
{
    operator unsigned int() const;
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct MTRenderingSystem_Helper
{
    void FUN_00ba30f0(int, int);
};
struct FUN_007079f0_shell
{
    bool FUN_007079f0();
};
bool __fastcall FUN_00644640(void*);
void __cdecl FUN_00702c80(bool, bool);
struct IMStandIn
{
    char m_uiStandInValue[0x8c];
    char m_flt8c[0xbc];
    bool m_flag148;
    void FUN_00713c70();
    void FUN_00713f00();
};

namespace fnv_00715ca0 {
struct NiNode
{
    void SetAppCulled(bool);
};
struct TileX
{
    NiNode* FUN_0056c7f0();
    void Set(int, int);
};
struct IMStandIn
{
    char m_uiStandInValue[0x28];
    TileX* m_tile28;
    char m_iValueAfterStandIn[0x7d - 0x2c];
    bool m_flag7d;
    char m_pAuxiliaryObject[0xed - 0x7e];
    bool m_flagED;
    TileX* FindHighestPriorityTile(int*, int);
    void FUN_00715860(TileX*, int, int);
    void UpdateFocusTarget();
};
bool FUN_004b71d0();

}  // namespace fnv_00715ca0

namespace fnv_00717660 {

struct Tile_Set_Helper
{
    void Set(int, int);
};
void __cdecl FUN_00703610();
}  // namespace fnv_00717660

namespace fnv_00717f80 {
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;
struct ListBoxBase
{
    virtual bool Highlight(Tile*);
    virtual Tile* GetHighlightedItem();
    virtual Tile* GetTileForButton(int);
    virtual bool BelongsTo(void*);
    virtual void ScrollToHighlight();
    virtual Tile* GetTileAt(unsigned int, bool);
};
typedef char _sizecheck_ListBoxBase[sizeof(ListBoxBase) == 4 ? 1 : -1];

struct ListNode
{
    ListBoxBase** FUN_006815c0();
    ListNode* FUN_00726070();
};
struct IMStandIn
{
    void FUN_00715860(Tile*, int, int);
};
struct DummyNode;
extern DummyNode g_011d8b54;
}  // namespace fnv_00717f80

struct TutorialEntry
{
    unsigned int shown : 1;
    unsigned int seen : 1;
    unsigned int rest : 30;
};
struct TutorialState
{
    TutorialEntry m_entries[1];
    unsigned int FUN_00706810();
    void LoadTutorialSeenFlags(char* apLoadString);
};

struct GlobalObject_0048f200
{
    GlobalObject_0048f200();
    ~GlobalObject_0048f200();
};

namespace fnv_0070f6e0 {
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;

struct Menu
{
    virtual ~Menu();
    virtual void SetTile(int id, Tile* tile);
    virtual void HandleLeftClickPress(int id, Tile* tile);
    virtual void HandleClick(int id, Tile* tile);
    virtual void HandleMouseover(int id, Tile* tile);
    virtual void HandleUnmouseover(int id, Tile* tile);
    virtual void PostDragTileChange(int id, Tile* newTile, Tile* tile);
    virtual void PreDragTileChange(int id, Tile* oldTile, Tile* tile);
    virtual void HandleActiveMenuClickHeld(int id, Tile* tile);
    virtual void OnClickHeld(int id, Tile* tile);
    virtual void HandleMousewheel(int id, Tile* tile);
    virtual void Update();
    virtual bool HandleKeyboardInput(int inputChar);
    virtual int GetID();
    virtual bool HandleSpecialKeyInput(int code, float keyState);
    virtual bool HandleControllerInput(int button, float value);
    Tile* GetTile();
    unsigned int GetVisibilityState();
};
struct MenuMgr
{
    static MenuMgr* Instance(bool create);
    Menu* GetFrontmostMenu();
};

}  // namespace fnv_0070f6e0

struct M788
{
    void __thiscall FUN_004ed900(void);
};
extern M788 DAT_011f3324;

// @fnv 0x0070aca0
void __cdecl FUN_0070aca0()
{
    DAT_011f3324.FUN_004ed900();
}

namespace fnv_0070b5d0 {
class AnimIdle;
template <class T> class NiPointer
{
  public:
    NiPointer(T* apObject);
    ~NiPointer();
    NiPointer& operator=(T* apObject);
    T* m_pObject;
};

}  // namespace fnv_0070b5d0

struct StatsMenu
{
    enum Page
    {
    };
    void SetCurrentPage(Page);
    void SetCurrentPageFromChar(char a);
};

extern unsigned char DAT_011dea2f;

extern unsigned char DAT_011dea2f;

extern "C" unsigned char* DAT_011f5b04;

namespace fnv_00714d90 {

struct ImageSpaceManager
{
    static ImageSpaceManager* __cdecl FUN_004e3270();
};
struct S4
{
    void FUN_007123a0(unsigned char);
};
void _FNV_Warning(const char*);

}  // namespace fnv_00714d90

namespace fnv_00715e00 {
struct GlobalObject_0045cfe0
{
};
extern GlobalObject_0045cfe0 g_011d8bd8;
extern GlobalObject_0045cfe0 g_011d8bf0;
float __cdecl FUN_00715da0(void);
float __cdecl FUN_007177c0();
float __cdecl FUN_00717820();

}  // namespace fnv_00715e00

namespace fnv_00716320 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct ArrSIH
{
};
struct TimeGlobal
{
};
extern ArrSIH DAT_011f2250;
extern TimeGlobal g_timeGlobal;
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_00404010(float, float);

}  // namespace fnv_00716320

namespace fnv_007164c0 {
struct AutoMemHelper
{
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
    int m_iContext;
};
float __cdecl FUN_00404010(float, float);

}  // namespace fnv_007164c0

namespace fnv_00716730 {
struct AnimIdle
{
    int GetSection();
};
struct Setting_S
{
    float* Float();
};
struct HotkeyWheelDisplay
{
    int HandleHotkeyInput(int, int);
};
struct TimeGlobal
{
};
extern TimeGlobal g_timeGlobal;

}  // namespace fnv_00716730

namespace fnv_007170a0 {
struct S7010
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    unsigned int Length();
};
struct Str6a70
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    Str6a70& operator=(const char*);
};
struct Flt
{
    operator unsigned int() const;
};
void FUN_004046f0(char*, const char*);

}  // namespace fnv_007170a0

namespace fnv_007187a0 {
struct TutorialState
{
    unsigned int FUN_00706810();
    bool FUN_00718840(int);
    void PackFlags(unsigned char* apFlags);
};

}  // namespace fnv_007187a0

namespace fnv_0071d380 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct GlobalObject2_0040c150
{
    int* Int();
};
struct GlobalObject_0045cfe0
{
};

}  // namespace fnv_0071d380

namespace fnv_007e6620 {
struct TileQ
{
    bool ContainsTrait(int);
};
struct Menu
{
    virtual ~Menu();
    virtual void SetTile(unsigned int, Tile*);
    virtual void HandleLeftClickPress(unsigned int, Tile*);
    virtual void HandleClick(int, Tile*);
};

}  // namespace fnv_007e6620

namespace fnv_00ad8510 {
struct BSAudioManager
{
    static BSAudioManager& __cdecl GetRandomGenerator();
    void FUN_00adcb20(unsigned int a1, unsigned char a2);
    void FUN_00ad8510(unsigned int a1, unsigned char a2);
};

}  // namespace fnv_00ad8510

struct BSSystemUtility
{
    static BSSystemUtility* ms_pSystemUtility;
    virtual int ResetSystemUtility(int);
};

// Calls ResetSystemUtility(1) on the BSSystemUtility singleton if set, then clears the singleton pointer.
// @fnv 0x0070ad30
void __cdecl ResetSystemUtility()
{
    BSSystemUtility* pInstance = BSSystemUtility::ms_pSystemUtility;
    BSSystemUtility* pTemp = pInstance;
    int result;
    if (pTemp != 0)
    {
        result = pTemp->ResetSystemUtility(1);
    }
    else
    {
        result = 0;
    }
    BSSystemUtility::ms_pSystemUtility = 0;
}

namespace fnv_0070bbe0 {
struct BSAudio_
{
    void FUN_00ad8510(int, int);
    void FUN_0070bbe0();
};

}  // namespace fnv_0070bbe0

namespace fnv_00711dc0 {
struct Setting_S
{
    float* Float();
};

}  // namespace fnv_00711dc0

struct FUN_007185e0_class
{
    int m_data[0x29];
    int& operator[](int index)
    {
        return m_data[index];
    }
    bool SetFlag2(int index);
};

struct FUN_0070c410_class
{
    int m_auiShapeKeys[0xd58 / 4];
    struct Vec3
    {
        float x, y, z;
    } m_pos;
    Vec3& __thiscall GetPosition(Vec3& akDest);
};

namespace fnv_0070ecb0 {
float __cdecl FUN_00706e20(void);
float __cdecl FUN_00715da0(void);

}  // namespace fnv_0070ecb0

struct HotkeyWheelDisplay
{
    bool GetVisible();
};

namespace fnv_007182b0 {
struct M788
{
    void FUN_004ed8c0(void*);
};
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
struct GlobalObject_0048f200 : M788
{
};
extern GlobalObject_0048f200 g_011d8b2c;
extern ATM g_011d8c18;

}  // namespace fnv_007182b0

void __cdecl _Deallocate(void*);

struct FUN_0070a100_Class
{
    void FUN_0070a920();
    void* FUN_0070a100(unsigned int flags);
};

namespace fnv_0070ad00 {
extern "C" void __cdecl _Deallocate(void*);

}  // namespace fnv_0070ad00

namespace fnv_0070ad80 {
extern "C" void __cdecl _Deallocate(void*);

}  // namespace fnv_0070ad80

namespace fnv_0070b8f0 {
class AutoMemHelper
{
  public:
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
    int m_data;
};
class NiAVObject
{
  public:
    void SetAppCulled(bool);
};
class RgbaColor
{
  public:
    NiNode* FUN_0056c7f0();
};
struct Tile_Set_Helper
{
    void Set(int, int);
};
struct TileHelper
{
    void Set(int, const char*, bool);
};
class StartMenu
{
  public:
    const char* GetMenuTitle();
};
class GlobalObject_0040c150 : public StartMenu
{
};
extern GlobalObject_0040c150 g_011d475c;
class TESObjectREFR;
class HUDMainMenu
{
  public:
    static bool UpdateTargetReference(TESObjectREFR*, bool, bool);
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
};
struct BSAudio_
{
    void FUN_0070bba0();
    void FUN_0070bbe0();
    void FUN_0070bc00();
};
class BSAudioManager;
void __fastcall FUN_0070bbc0(BSAudioManager*);
bool __fastcall FUN_00644640(void*);
}  // namespace fnv_0070b8f0

namespace fnv_007134d0 {
struct NiAVObject;
struct NiGeometry;
struct NiNode;
struct bhkNiCollisionObject;

struct Camera_007134d0;
struct Renderer_007134d0
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int FUN_c8();
    virtual int FUN_cc();
    void SetCurrentCamera(Camera_007134d0*);
};
Renderer_007134d0* __cdecl FUN_0043c4b0();
struct AVObject_007134d0
{
    void SetAppCulled(bool);
    bool FUN_00456610();
};
struct MTRenderingSystem_Helper
{
    void FUN_00ba30f0(int, int);
    void FUN_00ba3130(int, int);
};
struct Flt_Helper
{
    operator unsigned int() const;
};
struct Tile_Helper
{
    AVObject_007134d0* FUN_0056c7f0();
};
void __cdecl FUN_00702c80(bool, bool);
struct FUN_007079f0_shell
{
    bool FUN_007079f0();
};
void __fastcall FUN_00713c70(void*);
struct _Rect16_00712e60
{
    int a;
};
struct _Cam_00712e60
{
    void FUN_00712e60(const _Rect16_00712e60&);
};
struct MenuBase_007134d0;
MenuBase_007134d0* __cdecl FindMenuById(int);
extern _Rect16_00712e60 DAT_011ad840;

}  // namespace fnv_007134d0

namespace fnv_0070a0b0 {
struct FUN_0070a100_Class
{
    void* FUN_0070a100(unsigned int);
};
extern FUN_0070a100_Class* DAT_011d8a80;
}  // namespace fnv_0070a0b0

struct FUN_0070acb0_s
{
    void* FUN_0070ad00(int);
};
extern ConsoleManager* DAT_MenuConsole_pInstance;
// @fnv 0x0070acb0
void DestroyMenuConsoleSingleton()
{
    ConsoleManager* a;
    FUN_0070acb0_s* p;
    void* r;
    if (DAT_MenuConsole_pInstance)
    {
        a = DAT_MenuConsole_pInstance;
        p = reinterpret_cast<FUN_0070acb0_s*>(a);
        if (p)
            r = p->FUN_0070ad00(1);
        else
            r = 0;
    }
    DAT_MenuConsole_pInstance = 0;
}

struct TileQ
{
    TileQ* GetNext();
    bool ContainsTrait(int);
};

namespace fnv_0070ee30 {
struct SM7d6
{
    enum Flag
    {
        F1 = 0x8000,
        F2 = 8
    };
    bool IsFlagSet(Flag);
};
extern SM7d6* DAT_011daac0;

}  // namespace fnv_0070ee30

extern unsigned char* DAT_011f5b04;

extern void* _g_thePlayer;

namespace fnv_0070ed80 {
struct StatsMenu
{
    char pad[0x2a0];
    bool bIsActive;  // +0x2a0
    static StatsMenu* ms_pInventoryMenu;
};

}  // namespace fnv_0070ed80

namespace fnv_00718930 {
struct LLD_PlayerCharacter
{
    void FUN_00718930(bool);
    void SetFlag4(bool);
    void SetCameraPathEnabled(bool, unsigned int);
};

LLD_PlayerCharacter* _g_thePlayer;

}  // namespace fnv_00718930

class NiNode;

struct TileProxy
{
    virtual ~TileProxy()
    {}
    bool ContainsTrait(int value);
    TileProxy* ReadFile();
    void Set(int value1, int value2);
    NiNode* FUN_0056c7f0();
};

void* __stdcall FUN_005bd5b0(int);
struct FormObj
{
    virtual void fvp0();
    virtual void fvp1();
    virtual void fvp2();
    virtual void fvp3();
    virtual void fvp4();
    virtual void fvp5();
    virtual void fvp6();
    virtual void fvp7();
    virtual void fvp8();
    virtual void fvp9();
    virtual void fvp10();
    virtual void fvp11();
    virtual void fvp12();
    virtual void fvp13();
    virtual void fvp14();
    virtual void fvp15();
    virtual void fvp16();
    virtual void fvp17();
    virtual void fvp18();
    virtual void fvp19();
    virtual void fvp20();
    virtual void fvp21();
    virtual void fvp22();
    virtual void fvp23();
    virtual void fvp24();
    virtual void fvp25();
    virtual void fvp26();
    virtual void fvp27();
    virtual void fvp28();
    virtual void fvp29();
    virtual void fvp30();
    virtual void fvp31();
    virtual void fvp32();
    virtual void fvp33();
    virtual void fvp34();
    virtual void fvp35();
    virtual void fvp36();
    virtual void fvp37();
    virtual void fvp38();
    virtual void fvp39();
    virtual void fvp40();
    virtual void fvp41();
    virtual void fvp42();
    virtual void fvp43();
    virtual void fvp44();
    virtual void fvp45();
    virtual void fvp46();
    virtual void fvp47();
    virtual void fvp48();
    virtual void fvp49();
    virtual void fvp50();
    virtual void fvp51();
    virtual void fvp52();
    virtual void fvp53();
    virtual void fvp54();
    virtual void fvp55();
    virtual void fvp56();
    virtual void fvp57();
    virtual void fvp58();
    virtual void fvp59();
    virtual void fvp60();
    virtual void fvp61();
    virtual void fvp62();
    virtual void fvp63();
    virtual void fvp64();
    virtual void fvp65();
    virtual void fvp66();
    virtual void fvp67();
    virtual void fvp68();
    virtual void fvp69();
    virtual void fvp70();
    virtual void fvp71();
    virtual void fvp72();
    virtual void fvp73();
    virtual void fvp74();
    virtual void fvp75();
    virtual const char* fv130();
    unsigned int FUN_0084e3a0();
};
struct ExtraObj
{
    FormObj* FUN_00418800();
    short FUN_00418770();
};
struct FullName
{
    const char* FUN_00408da0();
};
struct KeyObj
{
    char pad[0x30];
    FullName m_fn;
};
struct ProcObj
{
    virtual void pvp0();
    virtual void pvp1();
    virtual void pvp2();
    virtual void pvp3();
    virtual void pvp4();
    virtual void pvp5();
    virtual void pvp6();
    virtual void pvp7();
    virtual void pvp8();
    virtual void pvp9();
    virtual void pvp10();
    virtual void pvp11();
    virtual void pvp12();
    virtual void pvp13();
    virtual void pvp14();
    virtual void pvp15();
    virtual void pvp16();
    virtual void pvp17();
    virtual void pvp18();
    virtual void pvp19();
    virtual void pvp20();
    virtual void pvp21();
    virtual void pvp22();
    virtual void pvp23();
    virtual void pvp24();
    virtual void pvp25();
    virtual void pvp26();
    virtual void pvp27();
    virtual void pvp28();
    virtual void pvp29();
    virtual void pvp30();
    virtual void pvp31();
    virtual void pvp32();
    virtual void pvp33();
    virtual void pvp34();
    virtual void pvp35();
    virtual void pvp36();
    virtual void pvp37();
    virtual void pvp38();
    virtual void pvp39();
    virtual void pvp40();
    virtual void pvp41();
    virtual void pvp42();
    virtual void pvp43();
    virtual void pvp44();
    virtual void pvp45();
    virtual void pvp46();
    virtual void pvp47();
    virtual void pvp48();
    virtual void pvp49();
    virtual void pvp50();
    virtual void pvp51();
    virtual void pvp52();
    virtual void pvp53();
    virtual void pvp54();
    virtual void pvp55();
    virtual void pvp56();
    virtual void pvp57();
    virtual void pvp58();
    virtual void pvp59();
    virtual void pvp60();
    virtual void pvp61();
    virtual void pvp62();
    virtual void pvp63();
    virtual void pvp64();
    virtual void pvp65();
    virtual void pvp66();
    virtual void pvp67();
    virtual void pvp68();
    virtual void pvp69();
    virtual void pvp70();
    virtual void pvp71();
    virtual void pvp72();
    virtual void pvp73();
    virtual void pvp74();
    virtual void pvp75();
    virtual void pvp76();
    virtual void pvp77();
    virtual void pvp78();
    virtual void pvp79();
    virtual void pvp80();
    virtual void pvp81();
    virtual void pvp82();
    virtual void pvp83();
    virtual void pvp84();
    virtual void pvp85();
    virtual void pvp86();
    virtual void pvp87();
    virtual void pvp88();
    virtual void pvp89();
    virtual void pvp90();
    virtual void pvp91();
    virtual void pvp92();
    virtual void pvp93();
    virtual void pvp94();
    virtual void pvp95();
    virtual void pvp96();
    virtual void pvp97();
    virtual void pvp98();
    virtual void pvp99();
    virtual void pvp100();
    virtual void pvp101();
    virtual void pvp102();
    virtual void pvp103();
    virtual void pvp104();
    virtual void pvp105();
    virtual void pvp106();
    virtual void pvp107();
    virtual void pvp108();
    virtual void pvp109();
    virtual void pvp110();
    virtual void pvp111();
    virtual void pvp112();
    virtual void pvp113();
    virtual void pvp114();
    virtual void pvp115();
    virtual void pvp116();
    virtual void pvp117();
    virtual void pvp118();
    virtual void pvp119();
    virtual void pvp120();
    virtual void pvp121();
    virtual void pvp122();
    virtual void pvp123();
    virtual void pvp124();
    virtual void pvp125();
    virtual void pvp126();
    virtual void pvp127();
    virtual void pvp128();
    virtual void pvp129();
    virtual void pvp130();
    virtual void pvp131();
    virtual void pvp132();
    virtual void pvp133();
    virtual void pvp134();
    virtual void pvp135();
    virtual void pvp136();
    virtual void pvp137();
    virtual void pvp138();
    virtual void pvp139();
    virtual void pvp140();
    virtual void pvp141();
    virtual void pvp142();
    virtual void pvp143();
    virtual void pvp144();
    virtual void pvp145();
    virtual void pvp146();
    virtual void pvp147();
    virtual void pvp148();
    virtual void pvp149();
    virtual void pvp150();
    virtual void pvp151();
    virtual void pvp152();
    virtual void pvp153();
    virtual void pvp154();
    virtual void pvp155();
    virtual void pvp156();
    virtual void pvp157();
    virtual void pvp158();
    virtual void pvp159();
    virtual void pvp160();
    virtual void pvp161();
    virtual void pvp162();
    virtual void pvp163();
    virtual void pvp164();
    virtual void pvp165();
    virtual void pvp166();
    virtual void pvp167();
    virtual void pvp168();
    virtual void pvp169();
    virtual void pvp170();
    virtual void pvp171();
    virtual void pvp172();
    virtual void pvp173();
    virtual void pvp174();
    virtual void pvp175();
    virtual void pvp176();
    virtual void pvp177();
    virtual void pvp178();
    virtual void pvp179();
    virtual void pvp180();
    virtual void pvp181();
    virtual void pvp182();
    virtual void pvp183();
    virtual void pvp184();
    virtual void pvp185();
    virtual void pvp186();
    virtual void pvp187();
    virtual void pvp188();
    virtual void pvp189();
    virtual void pvp190();
    virtual void pvp191();
    virtual void pvp192();
    virtual void pvp193();
    virtual void pvp194();
    virtual void pvp195();
    virtual void pvp196();
    virtual void pvp197();
    virtual void pvp198();
    virtual void pvp199();
    virtual void pvp200();
    virtual void pvp201();
    virtual void pvp202();
    virtual void pvp203();
    virtual void pvp204();
    virtual void pvp205();
    virtual void pvp206();
    virtual void pvp207();
    virtual void pvp208();
    virtual void pvp209();
    virtual void pvp210();
    virtual void pvp211();
    virtual void pvp212();
    virtual void pvp213();
    virtual void pvp214();
    virtual void pvp215();
    virtual void pvp216();
    virtual void pvp217();
    virtual void pvp218();
    virtual void pvp219();
    virtual void pvp220();
    virtual void pvp221();
    virtual void pvp222();
    virtual void pvp223();
    virtual void pvp224();
    virtual void pvp225();
    virtual void pvp226();
    virtual void pvp227();
    virtual void pvp228();
    virtual void pvp229();
    virtual void pvp230();
    virtual void pvp231();
    virtual void pvp232();
    virtual void pvp233();
    virtual void pvp234();
    virtual void pvp235();
    virtual void pvp236();
    virtual void pvp237();
    virtual void pvp238();
    virtual void pvp239();
    virtual void pvp240();
    virtual void pvp241();
    virtual void pvp242();
    virtual void pvp243();
    virtual void pvp244();
    virtual void pvp245();
    virtual void pvp246();
    virtual void pvp247();
    virtual void pvp248();
    virtual void pvp249();
    virtual void pvp250();
    virtual void pvp251();
    virtual void pvp252();
    virtual void pvp253();
    virtual void pvp254();
    virtual void pvp255();
    virtual void pvp256();
    virtual void pvp257();
    virtual void pvp258();
    virtual void pvp259();
    virtual void pvp260();
    virtual void pvp261();
    virtual void pvp262();
    virtual void pvp263();
    virtual void pvp264();
    virtual void pvp265();
    virtual void pvp266();
    virtual void pvp267();
    virtual void pvp268();
    virtual void pvp269();
    virtual void pvp270();
    virtual void pvp271();
    virtual void pvp272();
    virtual void pvp273();
    virtual void pvp274();
    virtual void pvp275();
    virtual void pvp276();
    virtual void pvp277();
    virtual void pvp278();
    virtual void pvp279();
    virtual void pvp280();
    virtual void pvp281();
    virtual void pvp282();
    virtual void pvp283();
    virtual void pvp284();
    virtual void pvp285();
    virtual void pvp286();
    virtual void pvp287();
    virtual void pvp288();
    virtual void pvp289();
    virtual void pvp290();
    virtual void pvp291();
    virtual void pvp292();
    virtual void pvp293();
    virtual void pvp294();
    virtual void pvp295();
    virtual void pvp296();
    virtual void pvp297();
    virtual void pvp298();
    virtual void pvp299();
    virtual void pvp300();
    virtual void pvp301();
    virtual void pvp302();
    virtual void pvp303();
    virtual void pvp304();
    virtual void pvp305();
    virtual struct FormObj* pv4c8();
    virtual void pvp307();
    virtual int pv4d0();
};
struct Obj50
{
    int d0;
    int d1;
    int d2;
    int d3;
    void FUN_00509890(int);
    unsigned int FUN_005094b0();
};
struct BoundObj
{
    unsigned char FUN_00509450(int);
    void FUN_00509920(float*, unsigned int, float);
    float GetFurnitureHeading(int);
};
struct CellA
{
    char pad[0x18];
    FullName m_fn;
};
struct Extra2
{
    void* FUN_0041d460();
};
struct CellB
{
    Extra2* FUN_005d43c0();
    const char* FUN_0055d520();
};
struct TeleObj
{
    CellA* FUN_0043a2b0();
    CellB* FUN_00559450();
};
struct Pt3
{
    float x;
    float y;
    float z;
};
struct LockObj
{
    int m_f0;
    KeyObj* m_f4;
    unsigned char FUN_005021a0();
    int FUN_004309e0(struct Refr*);
};
struct Refr
{
    virtual void rvp0();
    virtual void rvp1();
    virtual void rvp2();
    virtual void rvp3();
    virtual void rvp4();
    virtual void rvp5();
    virtual void rvp6();
    virtual void rvp7();
    virtual void rvp8();
    virtual void rvp9();
    virtual void rvp10();
    virtual void rvp11();
    virtual void rvp12();
    virtual void rvp13();
    virtual void rvp14();
    virtual void rvp15();
    virtual void rvp16();
    virtual void rvp17();
    virtual void rvp18();
    virtual void rvp19();
    virtual void rvp20();
    virtual void rvp21();
    virtual void rvp22();
    virtual void rvp23();
    virtual void rvp24();
    virtual void rvp25();
    virtual void rvp26();
    virtual void rvp27();
    virtual void rvp28();
    virtual void rvp29();
    virtual void rvp30();
    virtual void rvp31();
    virtual void rvp32();
    virtual void rvp33();
    virtual void rvp34();
    virtual void rvp35();
    virtual void rvp36();
    virtual void rvp37();
    virtual void rvp38();
    virtual void rvp39();
    virtual void rvp40();
    virtual void rvp41();
    virtual void rvp42();
    virtual void rvp43();
    virtual void rvp44();
    virtual void rvp45();
    virtual void rvp46();
    virtual void rvp47();
    virtual void rvp48();
    virtual void rvp49();
    virtual void rvp50();
    virtual void rvp51();
    virtual void rvp52();
    virtual void rvp53();
    virtual void rvp54();
    virtual void rvp55();
    virtual void rvp56();
    virtual void rvp57();
    virtual void rvp58();
    virtual void rvp59();
    virtual void rvp60();
    virtual void rvp61();
    virtual void rvp62();
    virtual void rvp63();
    virtual unsigned char rv100();
    virtual void rvp65();
    virtual void rvp66();
    virtual void rvp67();
    virtual void rvp68();
    virtual void rvp69();
    virtual void rvp70();
    virtual void rvp71();
    virtual void rvp72();
    virtual void rvp73();
    virtual void rvp74();
    virtual void rvp75();
    virtual void rvp76();
    virtual void rvp77();
    virtual void rvp78();
    virtual void rvp79();
    virtual void rvp80();
    virtual void rvp81();
    virtual void rvp82();
    virtual void rvp83();
    virtual void rvp84();
    virtual void rvp85();
    virtual void rvp86();
    virtual void rvp87();
    virtual void rvp88();
    virtual void rvp89();
    virtual void rvp90();
    virtual void rvp91();
    virtual void rvp92();
    virtual void rvp93();
    virtual void rvp94();
    virtual void rvp95();
    virtual void rvp96();
    virtual void rvp97();
    virtual void rvp98();
    virtual void rvp99();
    virtual void rvp100();
    virtual void rvp101();
    virtual void rvp102();
    virtual void rvp103();
    virtual void rvp104();
    virtual void rvp105();
    virtual void rvp106();
    virtual void rvp107();
    virtual void rvp108();
    virtual void rvp109();
    virtual void rvp110();
    virtual void rvp111();
    virtual void rvp112();
    virtual void rvp113();
    virtual void rvp114();
    virtual void rvp115();
    virtual void rvp116();
    virtual void rvp117();
    virtual void rvp118();
    virtual void rvp119();
    virtual void rvp120();
    virtual void rvp121();
    virtual void rvp122();
    virtual void rvp123();
    virtual void rvp124();
    virtual void rvp125();
    virtual void rvp126();
    virtual void rvp127();
    virtual void rvp128();
    virtual void rvp129();
    virtual void rvp130();
    virtual void rvp131();
    virtual void rvp132();
    virtual int rv214();
    unsigned int FUN_0084e3a0();
    const char* FUN_0055d520();
    ExtraObj* FUN_005d43c0();
    FormObj* FUN_00567790();
    unsigned char FUN_00568680();
    int FUN_00572d10();
    unsigned char FUN_00568500(int, Obj50*);
    unsigned char FUN_00567f80(int, int);
    LockObj* FUN_00569160();
    TeleObj* FUN_00568e50();
    Pt3* FUN_00430830();
    ProcObj* FUN_008d8520();
    BoundObj* FUN_007af430();
};
struct ListNode
{
    void* m_item;
    ListNode* m_next;
    ListNode* FUN_00726070();
    void** FUN_006815c0();
};

// FUN_00711de0: member function of a global-manager object.
// Reads a float out of the value table owned by the global object at DAT_011f3618.

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount,
                                                                long* lpPreviousCount);

struct MenuStub
{
    virtual ~MenuStub();
};

struct TileStub
{
    MenuStub* GetMenu();
};

extern bool DAT_0119f348;

struct MenuMgr
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
    int menuIDs[10];
    void ClearMenuIDs();
};

struct FUN_00717230_bsobj
{
    void FUN_00a1b020();
};

FUN_00717230_bsobj* __stdcall FUN_005bd5b0(float* out, int arg, void* holder, float scale, int zero);

struct InputHelper_cls
{
    void FUN_005407b0();
};

struct OSGlobals_cls
{
    InputHelper_cls* FUN_00877720(bool flag);
};
extern OSGlobals_cls* DAT_011dea0c;

typedef bool(__cdecl* FUN_007e6700_Callback)(void*);

extern const double DAT_01012060;

struct OwnedUIObject
{
    virtual ~OwnedUIObject();
};
struct OwnedNonvirtualUI
{
    ~OwnedNonvirtualUI();
    void* DestroyIfFlagged(unsigned int);
};
struct EmptySoundHandle
{
    ~EmptySoundHandle();
    void FUN_00483710();
    int state;
};
struct UISmartPointer
{
    OwnedUIObject* ptr;
    ~UISmartPointer();
    OwnedUIObject* FUN_00559450();
    void FUN_0066b0d0(OwnedUIObject*);
};
struct UIList
{
    ~UIList();
    int unk00;
    int unk04;
};
struct UIState178
{
    ~UIState178();
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
};
struct UIState1dc
{
    ~UIState1dc();
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
};
struct UIList4c4
{
    ~UIList4c4();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct UIGlobalList
{
    void FUN_00470470();
};
extern UIGlobalList DAT_011d8b54;
extern unsigned char DAT_011d8909;
void ClearPendingObject();
void FUN_00a16850();
void FUN_0071e360();
void FUN_00a00a30();
void FUN_00a1c800();
void FUN_00718bf0();
void ClearAllElements();
void FUN_00707820();
void ClearStartMenuEntries();
void WaitForTasksAndClearScripts();
struct FUN_0070a920
{
    int unk000;
    UISmartPointer rootA;
    UISmartPointer rootB;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    OwnedUIObject* object28;
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
    UIList list70;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    UISmartPointer root8c;
    UISmartPointer root90;
    OwnedUIObject* object94;
    OwnedUIObject* object98;
    OwnedUIObject* object9c;
    OwnedUIObject* objecta0;
    int unk0a4;
    int unk0a8;
    UISmartPointer rootac;
    int unk0b0;
    OwnedUIObject* objectb4;
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
    OwnedNonvirtualUI* object13c;
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
    OwnedUIObject* object174;
    UIState178 state178;
    UIState1dc state1dc;
    UIList4c4 list4c4;
    EmptySoundHandle sound;
    void FUN_00716450();
    ~FUN_0070a920();
};
// Destructor: deletes owned objects, releases smart pointers, resets globals and calls the UI teardown helpers.
// @fnv 0x0070a920
FUN_0070a920::~FUN_0070a920()
{
    if (objectb4)
    {
        delete objectb4;
        objectb4 = 0;
    }
    ResetSystemUtility();
    DestroyMenuConsoleSingleton();
    ClearPendingObject();
    FUN_00a16850();
    if (rootA.FUN_00559450())
    {
        ((EmptySoundHandle*)rootA.FUN_00559450())->FUN_00483710();
        rootA.FUN_0066b0d0(0);
    }
    if (rootB.FUN_00559450())
    {
        ((EmptySoundHandle*)rootB.FUN_00559450())->FUN_00483710();
        rootB.FUN_0066b0d0(0);
    }
    DAT_011d8909 = 1;
    delete objecta0;
    delete object9c;
    DAT_011d8909 = 0;
    FUN_0071e360();
    delete object28;
    rootac.FUN_0066b0d0(0);
    DAT_011d8a80 = 0;
    FUN_00a00a30();
    FUN_0070aca0();
    delete object13c;
    FUN_00716450();
    FUN_00a1c800();
    DAT_011d8b54.FUN_00470470();
    FUN_00718bf0();
    ClearAllElements();
    FUN_00707820();
    delete object174;
    root8c.FUN_0066b0d0(0);
    delete object94;
    delete object98;
    ClearStartMenuEntries();
    WaitForTasksAndClearScripts();
}

namespace cursor_init {
struct SceneNode
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
    virtual void AttachChildInAvailableSlot(SceneNode*, bool);
    void FUN_004bc1f0(float, float, float);
    void FUN_00a5a040();
    void Update(NiUpdateDataH&);
    void SetAppCulled(bool);
};
struct CursorTile
{
    CursorTile();
    virtual void v0();
    virtual void Init(void*, const char*, void*);
    void Set(int, int);
    void SetString(int, const char*);
    void FUN_00a04640(bool);
    SceneNode* FUN_0056c7f0();
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
};
extern const char DAT_0106ef50[];
CursorTile* FUN_0076bfe0();
}

namespace fnv_0070f4e0 {
struct TileStub
{
    void Set(int, int);
};
struct VATSStub
{
    unsigned int CallGetFlags();
};
extern VATSStub DAT_011f2250;
extern const double DAT_01012060;
struct IfaceStub
{
    bool FUN_00701450(int);
};
extern IfaceStub* DAT_011d8804;

}  // namespace fnv_0070f4e0

namespace fnv_00710060 {
bool FUN_004b71d0();
int FUN_00717a40(int a, int b);
struct C877720
{
    int FUN_00877720();
};
extern C877720* DAT_011dea0c;

}  // namespace fnv_00710060

struct NiPoint3
{
    float x, y, z;
    NiPoint3();
};
struct GlobalObject2_0096a2d0
{
    void* item;
    GlobalObject2_0096a2d0* next;
    GlobalObject2_0096a2d0();
    ~GlobalObject2_0096a2d0();
    bool FUN_005f65d0(void*&);
    void FUN_00905820(void*&);
    void*& FUN_006815c0();
    GlobalObject2_0096a2d0* FUN_00726070();
    void FUN_00470470();
};

namespace std {
}
struct AlphaTile
{
    bool IsTraitNonZero(int);
    float FUN_00a011b0(int);
    void FUN_00700320(int, bool);
};
AlphaTile* __cdecl FUN_00a01630(void*);
unsigned int __cdecl FUN_00438220();

extern const double DAT_0106f290;

class FUN_006815c0
{
  public:
    float x, y, z;
    FUN_006815c0();
    bool FUN_00439090(const FUN_006815c0& arPoint);
};

class FUN_0043d410
{
  public:
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    FUN_0043d410(float afTime, bool abUpdateControllers, bool abParallelUpdate);
};

float __cdecl FUN_00715d40();
double __cdecl FUN_00706e20();
double __cdecl FUN_00706e50();

struct FocusMenu
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void Click(int, struct FocusTile*);
};
struct FocusTile
{
    float Read(int);
    void SetInt(int, int);
    void SetCount(int, int);
    FocusMenu* Owner();
    void Trigger(int);
    void Reset(int);
    bool Visible();
    bool Test(int);
};
struct FocusManager
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
    FocusTile* active;
    int count;
    int unkc4;
    int unkc8;
    FocusTile* hover;
    int hoverState;
    void NotifyOff(FocusMenu*, int, FocusTile*);
    void NotifyOn(FocusMenu*, int, FocusTile*);
    void Clear(int);
    void FUN_00715860(FocusTile* tile, int trait, bool sound);
};

struct TileValue7160
{
    float FUN_00488d50();
};
struct TileMenu7160
{
    int FUN_0059bb30();
};
struct TileNode7160;
struct TileChildren7160
{
    TileNode7160* FUN_00559450();
    struct Tile7160** FUN_0057cbe0(TileNode7160**);
};
struct Tile7160
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int GetType();
    TileChildren7160 children;
    TileMenu7160* FUN_00a03c90();
    bool IsTraitNonZero(int);
    TileValue7160* FindTraitValue(int);
    TileValue7160* FUN_00a00f30(int);
};
struct TileNode7160
{
    Tile7160* FUN_00726070();
};

struct MenuView
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
    virtual void SetController(bool);
};
struct TileView
{
    MenuView* FUN_00a03c90();
};

extern float DAT_011d8a68;
extern unsigned int DAT_011d8a64;
extern bool DAT_011d8a50;

namespace fnv_00713fb0 {

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float fr, float fg, float fb, float fa);
};

struct Obj10
{
    unsigned int FUN_0044ddc0();
};

struct Obj6629
{
    void FUN_00712e60(float* p);
};

struct Obj7fa
{
    Obj10* FUN_008d80e0();
    Obj6629* FUN_006629f0();
};

struct ObjE4
{

    int u000, u004, u008, u00c, u010, u014, u018, u01c, u020, u024, u028, u02c;

    int u030, u034, u038, u03c, u040, u044, u048, u04c, u050, u054, u058, u05c;

    int u060, u064, u068, u06c, u070, u074, u078, u07c, u080, u084, u088, u08c;

    int u090, u094, u098, u09c, u0a0, u0a4, u0a8, u0ac, u0b0, u0b4, u0b8, u0bc;

    int u0c0, u0c4;

    ObjE4(unsigned int v);

    ~ObjE4();
};

struct FlagHolder
{
    unsigned char* FUN_00408d60();
};

extern FlagHolder DAT_011db2cc;

extern unsigned char DAT_011f9426;

extern float DAT_011ad840;

extern const char DAT_0106ef50[];

bool __cdecl FUN_004de080();

bool __cdecl FUN_00717990();

struct MenuMgr
{

    int u000, u004, u008, u00c, u010, u014, u018, u01c, u020, u024, u028, u02c;

    int u030, u034, u038, u03c, u040, u044, u048, u04c, u050, u054, u058, u05c;

    int u060, u064, u068, u06c, u070, u074, u078, u07c, u080, u084, u088, u08c;

    int u090, u094, u098, u09c, u0a0, u0a4, u0a8, u0ac, u0b0, u0b4, u0b8, u0bc;

    int u0c0, u0c4, u0c8, u0cc, u0d0, u0d4, u0d8, u0dc, u0e0, u0e4, u0e8, u0ec;

    int u0f0, u0f4, u0f8, u0fc, u100, u104, u108, u10c, u110, u114, u118, u11c;

    int u120, u124, u128, u12c, u130, u134, u138, u13c, u140, u144, u148, u14c;

    int u150, u154, u158, u15c, u160, u164;

    unsigned char unk168;

    int u16c, u170, u174, u178, u17c, u180, u184, u188, u18c, u190, u194, u198;

    int u19c, u1a0, u1a4, u1a8, u1ac, u1b0, u1b4, u1b8, u1bc, u1c0, u1c4, u1c8;

    int u1cc, u1d0, u1d4, u1d8, u1dc, u1e0, u1e4, u1e8, u1ec, u1f0, u1f4, u1f8;

    int u1fc, u200, u204, u208, u20c, u210, u214, u218, u21c, u220, u224, u228;

    int u22c, u230, u234, u238, u23c, u240, u244, u248, u24c, u250, u254, u258;

    int u25c, u260, u264, u268, u26c, u270, u274, u278, u27c, u280, u284, u288;

    int u28c, u290, u294, u298, u29c, u2a0, u2a4, u2a8, u2ac, u2b0, u2b4, u2b8;

    int u2bc, u2c0, u2c4, u2c8, u2cc, u2d0, u2d4, u2d8, u2dc, u2e0, u2e4, u2e8;

    int u2ec, u2f0, u2f4, u2f8, u2fc, u300, u304, u308, u30c, u310, u314, u318;

    int u31c, u320, u324, u328, u32c, u330, u334, u338, u33c, u340, u344, u348;

    int u34c, u350, u354, u358, u35c, u360, u364, u368, u36c, u370, u374, u378;

    int u37c, u380, u384, u388, u38c, u390, u394, u398, u39c, u3a0, u3a4, u3a8;

    int u3ac, u3b0, u3b4, u3b8, u3bc, u3c0, u3c4, u3c8, u3cc, u3d0, u3d4, u3d8;

    int u3dc, u3e0, u3e4, u3e8, u3ec, u3f0, u3f4, u3f8, u3fc, u400, u404, u408;

    int u40c, u410, u414, u418, u41c, u420, u424, u428, u42c, u430, u434, u438;

    int u43c, u440, u444, u448, u44c, u450, u454, u458, u45c, u460, u464, u468;

    int u46c, u470, u474, u478, u47c, u480, u484, u488, u48c, u490, u494, u498;

    int u49c, u4a0, u4a4, u4a8, u4ac, u4b0, u4b4, u4b8;

    int unk4bc;

    Obj7fa* FUN_007fa950();

    void FUN_007134d0(ObjE4* p, bool b);

    void RenderMenu(int a, int b);
};

}  // namespace fnv_00713fb0

namespace fnv_007126c0 {
enum MEM_CONTEXT
{
    MEM_CONTEXT_MEM_CONTEXT_INTERFACE = 13,
};

class AutoMemContext
{
  public:
    int iPrevious;
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bOverride, const char* pcFile, int iLine);
    ~AutoMemContext();
};

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
};

struct PickRect
{
    int iLeft;
    int iTop;
    int iRight;
    int iBottom;
};

class PickProperty
{
  public:
    PickRect* FUN_0050d100();
};
class PickAVObject
{
  public:
    PickProperty* FUN_00a59d30(int iType);
};
class PickNode
{
  public:
    PickAVObject* FUN_0043b4a0(int iIndex);
    void FUN_004add70();
    void* FUN_0045bc00(int iIndex);
};

class PickValue
{
  public:
    float FUN_00a011b0();
};
class PickValueNode
{
  public:
    PickValue* FUN_00726070();
};

class PickTile
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual int GetType();
    virtual void v004();
    virtual bool ContainsPoint(float fX, float fYFinal);
    bool IsTraitNonZero(int m_iValueId);
    PickNode* FUN_0056c7f0();
    PickValueNode* FUN_00a03c90(int m_iValueId);
    void* FindTraitValue(int m_iValueId);
    PickTile* FUN_0045cd60();
};
PickTile* FUN_00a01630(class PickObject* pkObject);
int FUN_00438220();

class PickObject
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual PickObject* GetOwner();
    PickObject* FUN_009611e0();
};

class PickRecordView
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual PickObject* GetObject();
};
class PickRecord
{
  public:
    PickRecordView* FUN_00458b50();
    unsigned short FUN_0047d3d0();
};
class PickResults
{
  public:
    int FUN_0044edb0();
    PickRecord* FUN_00968670(int iIndex);
};

class NiPick
{
  public:
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
    NiPick(int iA, int iB);
    ~NiPick();
    void FUN_00632d20(bool bValue);
    void SetByteAtOffset17(bool bValue);
    void FUN_00705fc0(PickNode* pkRootLoc);
    bool FUN_00e98e20(NiPoint3* pkOrigin, NiPoint3* pkDir, int iValue);
    PickResults* FUN_00500940();
};

struct PickBoolSetting
{
    unsigned char* FUN_00408d60();
};
extern PickBoolSetting DAT_011db2cc;
extern unsigned char DAT_011f9426;
float FUN_00706e50();
float FUN_00706e20();
float FUN_00404010(float fA, float fB);
float FUN_0040ebd0(float fA, float fB);
bool FUN_00717990();

}  // namespace fnv_007126c0

float GetRatio();
float FUN_00717860();

extern char* __cdecl FUN_004046f0(char* dst, const char* src);

namespace s717280 {

class BSSoundHandleEx
{
  public:
    BSSoundHandleEx();
    ~BSSoundHandleEx();

    BSSoundHandleEx& FUN_00418900(const BSSoundHandleEx& kOther);
    bool FUN_00ad8830(bool bUnk);

    BSSoundHandleEx& operator=(const BSSoundHandleEx& kOther)
    {
        return FUN_00418900(kOther);
    }

    int m_iSoundID;
    bool m_bAssumeSuccess;
    int m_iFadeIndex;
};

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char* pcEditorID, unsigned int uiFlags);
};

static const char s_szUIMenuMode[] = "UIMenuMode";
static const char s_szUIMenuFocus[] = "UIMenuFocus";
static const char s_szUIPopUpMessageGeneral[] = "UIPopUpMessageGeneral";
static const char s_szUIMenuPrevNext[] = "UIMenuPrevNext";
static const char s_szUIMenuOK[] = "UIMenuOK";
static const char s_szUIPopUpQuestNew[] = "UIPopUpQuestNew";
static const char s_szUIMenuCancel[] = "UIMenuCancel";
static const char s_szUILevelUp[] = "UILevelUp";

}

namespace fnv_00717a40 {
struct FocusManager
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
    unsigned char unk7c;
    bool controllerBlocked;
};

}  // namespace fnv_00717a40

#include <stdlib.h>
namespace fnv_007118d0 {
struct AutoMemHelper
{
    int unk00;
    AutoMemHelper(int aiType, bool abFlag, const char* apFile, int aiLine);
    ~AutoMemHelper();
};

struct Pt3
{
    float x, y, z;
};

struct NiUpdateData
{
    float a, b, c;
    NiUpdateData(float af, bool ab, bool ac);
};

struct NodeX
{
    void FUN_00450f90(int a);
    Pt3* FUN_0043c490();
    void FUN_00440460(Pt3* p);
    void FUN_00a59c60(NiUpdateData* r);
};

struct TileX
{
    NodeX* FUN_0056c7f0();
    void FUN_00700320(int a, int b);
    float FUN_00a011b0(int a);
};

extern float FUN_0040ebd0(float a, float b);
extern float FUN_00404010(float a, float b);
extern float FUN_00715d40();
extern float FUN_00715da0();
extern float FUN_00706e50();
extern float FUN_00706e20();

extern const double DAT_0106f290;

}  // namespace fnv_007118d0

#include <windows.h>

namespace s716980 {

}

namespace fnv_00718ee0 {
struct SystemColorInfo;

void* __cdecl operator new(unsigned int);
unsigned int __cdecl PackRgba(unsigned int, unsigned int, unsigned int, unsigned int);

struct M788
{
    void FUN_004ed8c0(void*);
};

}  // namespace fnv_00718ee0

struct TESForm
{
  public:
    virtual ~TESForm();
};

namespace s7182e0 {

struct TutorialEntry
{
    int m_bPending : 1;
    int m_bShown : 1;
    unsigned int m_uiMenu : 6;
    unsigned int m_uiDelay : 24;
};

struct GameMode
{
    int unk000;
    int unk004;
    int unk008;
    int m_iMode;
};

extern GameMode* DAT_011d8a80;

bool FUN_0070ec00();
bool FUN_005d4a40();
bool FUN_007024e0();
TESForm* FUN_004839c0(unsigned int auiFormId);

static const char s_szTutorialError[] = "Error occurred while trying to display tutorial message";

struct TutorialState
{
    TutorialEntry m_akEntries[41];
    int m_iCurrent;
    unsigned int m_uiDueTime;

    bool SetFlag2(int iIndex);
    void FUN_007182e0();
};

}

namespace TileModelsUpdateDetail {
struct UpdateData
{
    float time;
    bool updateControllers;
    bool parallelUpdate;
    bool foundParticles;
    bool foundMorphController;
    bool sceneGraphChange;
    void FUN_0043d410(float, bool, bool);
};
struct Model
{
    void FUN_00a59c60(const UpdateData&);
};
struct TileView
{
    Model* FUN_0056c7f0();
    void ClearFlag();
};
}

namespace fnv_00718db0 {
struct SystemColorInfo;

struct SystemColorInfo;

struct GlobalObject2_0040c150
{
    int* Int();
};
void* __cdecl operator new(unsigned int);
unsigned int __cdecl PackRgba(unsigned int, unsigned int, unsigned int, unsigned int);
struct M788
{
    void FUN_004ed8c0(void*);
};
}  // namespace fnv_00718db0

extern "C" ::TESForm* __cdecl FUN_004839c0(unsigned int);
bool __cdecl FUN_005d4a40();
