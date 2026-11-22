// fallout_shared/sky/sky.cpp: Sky, ThisCls, TESObjectCELL, Host and more (2 functions)
#include "f3_common.h"
#include "sky_packet.h"
namespace fnv_00454b10 {
class TESObjectCELL
{
  public:
    unsigned char pad[0x24];
    unsigned char flags;
    unsigned char GetFakeExterior();
};

}  // namespace fnv_00454b10

// @fnv 0x00639d40
Sky::Sky() : m_pRootNode(0), m_pSkyNode(0), m_kSunlightColor(0.0f, 0.0f, 0.0f), m_kSkyColor(0.0f, 0.0f, 0.0f)
{
    m_pAtmosphere = 0;
    m_pStars = 0;
    m_pClouds = 0;
    m_pSun = 0;
    m_pPrimaryMoon = 0;
    m_pSecondaryMoon = 0;
    m_pPrecipitation = 0;
    m_pRootNode = 0;
    m_pSkyNode = 0;
    m_fFogFarDistance = 10.0f;
    eMode = 4;
    m_pCurrentClimate = 0;
    m_pOverrideWeather = 0;
    m_pQueuedWeather = 0;
    m_pPreviousWeather = 0;
    m_pRegionWeather = 0;
    fWeatherChance = 0.0f;
    field11c = 0;
    field124 = 0;
    field120 = 0;
    field128 = 0;
    for (int i = 0; i < 10; i++)
        m_kSkyColors[i] = DAT_011a9b7c;
    *(NiColor*)&m_kSkyColor = DAT_011a9b7c;
    m_fCurrentWeatherBlend = 0.0f;
    m_fTargetWeatherBlend = 1.0f;
    m_fWeatherBlend = 1.0f;
    field110 = 0.0f;
    m_pSkySounds = new BSSimpleList<SkySound*>;
    m_fWeatherFade = 0.0f;
    field108 = 0;
    field10c = originalRuntimeFloatSetting76.Float()->f;
    flags = 0;
    FUN_0063a030(true);
    field12c = 12.0f;
    field130 = 23.99f;
    field134 = 0.0f;
}

struct FUN_0063b600_shell : public Clouds
{
    void FUN_0063b600(int, NiColor*);
};

struct FUN_0063b9b0_shell : public Sky
{
    float FUN_0063b9b0();
};

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting78;

struct FUN_0063ba30_shell : public Sky
{
    float FUN_0063ba30();
};

float __cdecl FUN_0040ebd0(float, float);
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting78;

struct FUN_0063bb40_stand
{
    char pad[0x108];
    int tbl[4][6];
    int FUN_0063bb40(int a, int b);
};
// Returns the int stored at tbl[a][b].
// @f3 0x00a49650 (community match, verified in this file)
namespace EntryStorageA49650 {
struct Entry {
    int value;
    int metadata;
};

struct Storage {
    Entry* entries;
    int FUN_00a2a180();
};
}

int FUN_0063bb40_stand::FUN_0063bb40(int valueAddress, int metadata)
{
    EntryStorageA49650::Storage* storage = reinterpret_cast<EntryStorageA49650::Storage*>(this);
    int index = storage->FUN_00a2a180();
    EntryStorageA49650::Entry& entry = storage->entries[index];
    entry.value = *reinterpret_cast<const int*>(valueAddress);
    entry.metadata = metadata;
    return index;
}


struct NiStream;
struct blob8
{
    char b[8];
};
struct NiPoint2
{
    static struct blob8 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float Dot(void*);
    float Unitize();
    static void LoadBinary(NiStream*, NiPoint2*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint2*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float x;
    float y;
};
typedef char _sizecheck_NiPoint2[sizeof(NiPoint2) == 8 ? 1 : -1];
struct FUN_0063c490_shell : public Sky
{
    void FUN_0063c490();
};

void __fastcall _ref_006815c0(NiPoint2*);

struct TESWeatherEx : public TESWeather
{
    float GetWeatherData(int, float, float);
};

struct Sky_Helper : public Sky
{
    void FUN_0063e860(int);
};

namespace fnv_0063e010 {
class SoundPlaybackHandle
{
  public:
    void Stop(void);
};

SoundPlaybackHandle* const& __fastcall _ref_006815c0(void* pNode);

}  // namespace fnv_0063e010

namespace fnv_0063e290 {
template <class T> class BSStringT
{
  public:
    operator const char*() const;
};

class NiNode
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void InsertChild(const char*);
};

}  // namespace fnv_0063e290

namespace fnv_0063bab0 {

struct FUN_0063bb40_stand
{
    int FUN_0063bb40(int, int);
};
}  // namespace fnv_0063bab0

struct Flt
{
    operator unsigned int(void) const;
};

extern "C"
{
}

namespace fnv_0063b120 {

struct FUN_0063b600_shell
{
    void FUN_0063b600(int, void*);
};

}  // namespace fnv_0063b120

namespace fnv_0063d0e0 {
struct Sky_Helper
{
    void FUN_0063e860(int);
};
struct PC7d
{
    void FUN_0093a7a0(int);
};
extern PC7d* g_thePlayer;
}  // namespace fnv_0063d0e0

namespace fnv_0063ac70 {

struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct MobileObject
{
    float GetRelevantWaterHeight() const;
};
struct PC7d : public BSOcclusionPlane
{
};
struct AnimIdle
{
    int GetSection();
};
struct NiNode_00558310;
class NiAVObject;
NiNode_00558310* __cdecl FUN_0045c670();
NiAVObject* __fastcall FUN_00558310(NiNode_00558310*);
const NiPoint3& __fastcall FUN_0045bb80(NiAVObject*);
struct FUN_0063c490_shell
{
    void FUN_0063c490();
};
extern PC7d* g_thePlayer;
extern AnimIdle g_timeGlobal;

}  // namespace fnv_0063ac70

namespace fnv_0063d5e0 {
struct SkySound
{
    bool HandleCheckTime(int);
    bool IsFlaggedToBeKilled();
    unsigned int GetNextCheck();
    void FlagToKill();
    void SetNextCheck(unsigned int);
    void Play(float);
    void* __vecDelDtor(unsigned int);
    char IdentifierState[12];
    void* m_pWeatherObject;
    int m_iSoundType;
    unsigned int auiFormId;
    unsigned int uiData;
};
typedef char _sizecheck_SkySound[sizeof(SkySound) == 28 ? 1 : -1];

struct SndX
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned int uiState;
    bool IsValid();
    bool IsPlaying();
    void Stop();
    void PausePlayback();
};
struct TESWeatherEx
{
    float GetWeatherData(int, float, float);
    unsigned char GetWeatherDataRaw(int);
};
struct AnimIdle
{
    int GetSection();
};
extern AnimIdle g_timeGlobal;
extern unsigned char DAT_011ccb74;

}  // namespace fnv_0063d5e0

struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
};

namespace fnv_0063e9f0 {
class TESSaveLoadGame
{
  public:
    void FUN_008579b0(void*, int);
    void FUN_00857a10(int*, int);
};

}  // namespace fnv_0063e9f0

class SkySound
{
  public:
    void* field00;
    void* field04;
    void* field08;
    unsigned int field0c;
    void* field10;
    void* field14;
};

struct FogVector
{
    float x, y, z;
};
struct FogNode
{
    void FUN_00450f90(bool);
    const FogVector& FUN_0045bb80();
};
struct FogCell
{
    float FUN_005471e0();
    float FUN_00544b10();
    float FUN_00544ab0();
    float FUN_00544b70();
};
struct FogEnvironment
{
    FogCell* FUN_005f36f0();
};
struct FogCamera
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
    virtual float GetFarPlane();
    FogNode* FUN_00558310();
};
FogCamera* FUN_0045c670();
float FUN_0040ebd0(float, float);
extern FogEnvironment* DAT_011dea10;
extern const double DAT_01012070, DAT_01011588, DAT_01012060, DAT_0103a480, DAT_0104ee90;

namespace SkyAssets {
struct Object;
struct Texture;
struct Model;
struct String
{
    unsigned int unk0, unk4;
    String();
    ~String();
    void FUN_00438390(const char*);
    void FUN_00404820(const char*);
    const char* FUN_00559450();
};
struct Pointer
{
    Object* object;
    Pointer(int);
    ~Pointer();
    Object* FUN_00559450();
};
struct Update
{
    unsigned int unk0, unk4, unk8;
    Update(float, int, int);
};
struct Object
{
    void FUN_00a5a040();
    void FUN_00a59c60(Update*);
};
struct ScenePointer
{
    Object* object;
    Object* FUN_00559450();
};
struct Texture
{
    void FUN_006348e0(Object*);
};
struct Property
{
    Texture* FUN_00a59d30();
};
struct Visible
{
    void FUN_00635fe0(bool);
};
struct Cloud
{
    Property* FUN_006fa820(int);
    Property* FUN_0063d040(int);
    Visible* FUN_005585e0();
    Visible* FUN_0043b230();
};
struct Model
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual const char* Prefix();
    unsigned int FUN_0048cee0();
    const char* FUN_00408da0();
};
struct Weather
{
    void* FUN_0063cfe0();
    Model* FUN_0063cfa0(int);
    bool FUN_0063d000();
    bool FUN_0063d020();
};
struct Atmosphere
{
    void FUN_0063fdb0(void*);
};
struct Particle
{
    virtual ~Particle();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void Attach(Object*, const char*);
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
    Particle(const char*, float, float, float, float, float, int);
};
struct Setting
{
    float* FUN_00403e20();
    int* FUN_0043d4d0();
};
extern bool DAT_011f941e;
extern char DAT_0102d7c4, DAT_0104eeb8, DAT_0104eeb0, DAT_0104eea8;
int FUN_00404dc0(const char*, const char*);
void FUN_00b55840(const char*, int, Pointer*, int, int);
struct Sky
{
    unsigned int unk0;
    ScenePointer scene, root;
    Weather* weather;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Atmosphere* atmosphere;
    Cloud* cloud;
    unsigned int unk2c;
    Particle* rain;
    Particle* snow;
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
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    int mode;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int flags;
    void FUN_0063ca20();
};
}

struct BSAudio;
BSAudio* FUN_00453a70();
struct BSStr
{
    operator const char*() const;
};
struct SndX
{
    bool IsValid();
};

class Texture139;
void __cdecl FUN_00b55840(const char*, bool, NiPointer<Texture139>&, bool, bool);
int __cdecl FUN_00404dc0(const char*, const char*);
extern unsigned char DAT_011f941e;

namespace fnv_0063ef20 {
struct TESObjectDoorController
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct GlobalObject_00633c90
{
    GlobalObject_00633c90(int v);
    ~GlobalObject_00633c90();
    int m_ptr;
};

struct ListX
{
    void FUN_00631540(const GlobalObject_00633c90&);
};
struct TESX
{
    ListX* FUN_0043b5d0();
};
extern TESX* DAT_011dea10;

void __cdecl FNV_Warning(const char*, ...);

}  // namespace fnv_0063ef20

struct GlobalObject_0045cf30
{
    SETTING_VALUE* Bool();
};
extern GlobalObject_0045cf30 g_011ccb8c;
extern unsigned char DAT_011ccb74;

struct GlobalObject_0041a250
{
    int m00;
    unsigned char m04;
    int m08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    GlobalObject_0041a250(const GlobalObject_0041a250&);
    void FUN_copy(const void*);
    bool FUN_00ad8d10();
};

struct BSAudio
{
    GlobalObject_0041a250 FUN_00ad73b0(int, int);
};
BSAudio* __cdecl FUN_00453a70();

struct Entry
{
    int m00;
    int m04;
};

struct ParamObj
{
    BSSimpleList<Entry*>* FUN_0063dff0();
};

struct NodeObj
{
    GlobalObject_0041a250 m_handle;
    ParamObj* m0c;
    int m10;
    int m14;
    int m18;
    NodeObj(GlobalObject_0041a250, ParamObj*, int, int);
};

struct NodeList
{
    NodeObj*& GetItem();
    NodeList* GetNext();
    void AddHead(NodeObj* const& item);
};

struct ThisCls
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;
    int ma4;
    int ma8;
    int mac;
    int mb0;
    int mb4;
    int mb8;
    int mbc;
    int mc0;
    int mc4;
    int mc8;
    int mcc;
    int md0;
    int md4;
    int md8;
    int mdc;
    int me0;
    int me4;
    int me8;
    int mec;
    int mf0;
    int mf4;
    int mf8;
    NodeList* m_fc;
    void FUN_0063ddb0(ParamObj* arg);
};

namespace fnv_0063b630 {

struct FUN_0063b9b0_shell
{
    float FUN_0063b9b0();
};

struct FUN_0063ba30_shell
{
    float FUN_0063ba30();
};

void FNV_Warning(const char*);

}  // namespace fnv_0063b630

float __cdecl FUN_0040ebd0(float a, float b);

class WeatherCell
{
  public:
    TESWeather* FUN_0059bb30();
};
class PlayerCharacter
{
  public:
    WeatherCell* FUN_005454d0();
};
extern PlayerCharacter* g_thePlayer;

namespace fnv_0063a630 {
struct GlobalObject_0045cf30
{
    SETTING_VALUE* Bool();
};
extern GlobalObject_0045cf30 g_011ccb8c;
extern float DAT_011ad87c, DAT_011ad880;
class NiAlphaProperty;
class NiNode
{
  public:
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
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void AttachChildInAvailableSlot(NiNode*, bool);
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void InsertChild(NiNode*);
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;
    int ma4;
    int ma8;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    NiNode(unsigned short);
    NiNode* FUN_009611e0();
    void FUN_005468d0(bool);
    void FUN_004902f0(bool);
    void FUN_00440460(const void*);
    void FUN_00439410(NiAlphaProperty*);
    void FUN_00a5a040();
};
class AtmosphereObj
{
  public:
    virtual ~AtmosphereObj();
    virtual void vfn04();
    virtual void Init(NiNode*);
    virtual void vfn0c();
    virtual void Init2(NiNode*, int);
    int m04, m08, m0c, m10, m14, m18;
};
class StarsObj
{
  public:
    virtual ~StarsObj();
    virtual void vfn04();
    virtual void Init(NiNode*);
    int m04, m08, m0c;
};
class Sun
{
  public:
    virtual ~Sun();
    virtual void vfn04();
    virtual void Init(NiNode*);
    int m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28;
    Sun();
};
class PrecipObj
{
  public:
    virtual ~PrecipObj();
    int m04, m08, m0c, m10, m14;
    void FUN_00636bb0();
};
class CloudsObj
{
  public:
    virtual ~CloudsObj();
    virtual void vfn04();
    virtual void Init(NiNode*);
    int m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c, m40, m44, m48, m4c, m50, m54, m58;
};
class NiAlphaProperty
{
  public:
    int m00, m04, m08, m0c, m10, m14, m18;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    NiAlphaProperty();
    void FUN_00439340(int);
    void FUN_00439390(int);
    void FUN_0049ed90(bool);
    void FUN_00636000(bool);
};
struct RootPointer
{
    NiNode* p;
    bool FUN_0052aa80(int) const;
    NiNode* operator->() const;
    operator NiNode*() const;
    RootPointer& operator=(NiNode*);
};
struct ThisCls
{
    int m00;
    NiPointer<NiNode> m04, m08;
    int m0c, m10, m14, m18, m1c;
    AtmosphereObj* m20;
    StarsObj* m24;
    Sun* m28;
    CloudsObj* m2c;
    int m30, m34;
    PrecipObj* m38;
    void FUN_0063a630(NiNode*, int);
};
}  // namespace fnv_0063a630
