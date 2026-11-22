// src/f3staging/f3blk_007e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x007f97c0 (community match, verified in this file)
namespace f3m_007f97c0 {
class FUN_007f97c0 { public: virtual void v0(); char b4; int a8; FUN_007f97c0(); };
// pdb: BSCacheDriveSystemUtility::BSCacheDriveSystemUtility | BSCacheDriveSystemUtility.obj | fnv360_0822_retail, call_seq, medium
FUN_007f97c0::FUN_007f97c0() { b4 = 0; a8 = 0; }
}   // namespace f3m_007f97c0

// @f3 0x007f9370 (community match, verified in this file)
namespace f3m_007f9370 {
namespace n7f9370 {
void* __cdecl FUN_00c00610(void* dst, int val, unsigned int size);
}
struct FUN_007f9370 {
    virtual ~FUN_007f9370();
    char buf[0x80];
    int m84;
    int m88;
    char m8c;
    int m90;
    char m94;
    char m95;
    FUN_007f9370();
};
// pdb: BSSystemUtility::BSSystemUtility | BSSystemUtility.obj | fnv360_0822_debug, call_seq, medium, conflict (skyrim: BSWin32SystemUtility::BSWin32SystemUtility)
FUN_007f9370::FUN_007f9370() : m84(0), m88(0), m8c(0), m90(0), m94(0), m95(0) {
    n7f9370::FUN_00c00610(buf, 0, sizeof(buf));
}
}   // namespace f3m_007f9370

// @f3 0x007f9830 (community match, verified in this file)
namespace f3m_007f9830 {
struct FUN_007f9830 {
    char m4;
    char m5;
    int m8;
    char pad[0x84c - 0xc];
    int m84c;
    FUN_007f9830();
    virtual ~FUN_007f9830();
};
// pdb: BSGameDataSystemUtility::BSGameDataSystemUtility | BSGameDataSystemUtility.obj | fnv360_0822_retail, call_seq, medium
FUN_007f9830::FUN_007f9830() : m4(0), m5(0), m8(0), m84c(0)
{
}
}   // namespace f3m_007f9830

// @f3 0x007f1040 (community match, verified in this file)
extern float DAT_01032adc;
namespace f3m_007f1040 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);

struct Vec3 { float x, y, z; };

class QLeaf1 {
public:
    unsigned int unk00;
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
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    signed char m_type;
};

class QMid1 {
public:
    unsigned int unk00;
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
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    QLeaf1* m_pLeaf;
};

class QObj1 {
public:
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
    virtual Vec3& GetPos();
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
    virtual QMid1* GetSub();
};

class Cls_007f1040 {
public:
    QObj1* m_pActor;
    QObj1* m_pOther;
    int m_iPriority;
    unsigned long m_tick;
    float m_fScale;
    Vec3 m_posActor;
    Vec3 m_posOther;
    void FUN_007f1040();
};
// pdb: SpectatorThreatInfo::Update | SpectatorPackage.obj | fnv360_0822_retail, call_seq, medium
void Cls_007f1040::FUN_007f1040()
{
    m_tick = m_pActor ? GetTickCount() : m_tick;

    m_posActor = m_pActor ? m_pActor->GetPos() : m_posActor;
    m_posOther = m_pOther ? m_pOther->GetPos() : m_posOther;

    QMid1* mid = m_pActor ? m_pActor->GetSub() : 0;
    QLeaf1* leaf = mid ? mid->m_pLeaf : 0;
    int result = 0;
    if (leaf) {
        switch (leaf->m_type) {
        case 0: m_fScale = 512.0f; result = 3; break;
        case 1: m_fScale = DAT_01032adc; result = 2; break;
        case 2: m_fScale = 128.0f; result = 1; break;
        case 3: m_fScale = 512.0f; result = 3; break;
        case 4: m_fScale = DAT_01032adc; result = 3; break;
        }
    }
    m_iPriority = m_iPriority > result ? m_iPriority : result;
}
}   // namespace f3m_007f1040

// @f3 0x007f9990 (community match, verified in this file)
namespace f3m_007f9990 {
namespace f3m_007f9990 {
static __declspec(noinline) unsigned int FUN_007f9990(unsigned int value)
{
    if (value > 16)
    {
        if (value > 64)
        {
            if (value > 128)
            {
                if (value > 256)
                {
                    if (value > 512)
                        return 1024;
                    else
                        return 512;
                }
                else
                    return 256;
            }
            else
                return 128;
        }
        else
        {
            if (value > 32)
                return 64;
            else
                return 32;
        }
    }
    else
    {
        if (value > 4)
        {
            if (value > 8)
                return 16;
            else
                return 8;
        }
        else
        {
            if (value > 2)
                return 4;
        }
    }
    return value;
}
unsigned int ForceCall_007f9990(unsigned int v) { return FUN_007f9990(v); }
}
}   // namespace f3m_007f9990

// @f3 0x007e3ac0 (community match, verified in this file)
#include <math.h>
namespace f3m_007e3ac0 {

struct P3Update { float x, y, z; };
struct P3Dir { float x, y, z; P3Dir() {} P3Dir(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {} };

struct S7e3_Actor
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
    virtual const P3Update& Position();
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
    virtual float Heading(bool flag);
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
    virtual float MaxRotation();
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
    float unk80;
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
    unsigned char unk140, unk141;
    float FUN_006f5b00();
    float Actor_GetWalkSpeed();
    float FUN_006f9ec0();
};
struct PointLocation
{
    int unk00;
    P3Update point;
    P3Update Point() const { return point; }
};
struct UpdateNode
{
    int unk00;
    PointLocation location;
};
struct UpdateNodeList
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
    unsigned int unk28;
    void FUN_00605d50(float t, P3Update* out);
    void FUN_00604f70(float t, float distance, int flag, int* index, P3Update* out);
    UpdateNode* FUN_005d20a0();
};
__declspec(noinline) void FUN_00493030(float& value, float lo, float hi)
{
    if (!(lo > hi)) {
        if (value > hi)
            value = fmod(value - lo, hi - lo) + lo;
        else if (value < lo)
            value = fmod(value - lo, hi - lo) + hi;
    }
}

float __cdecl FUN_00477b20(const P3Dir& direction);

__forceinline P3Update MakePoint_7e3ac0(float x, float y, float z)
{
    P3Update point;
    point.x = x;
    point.y = y;
    point.z = z;
    return point;
}

__forceinline P3Update PointDifference_7e3ac0(const P3Update& a, const P3Update& b)
{
    return MakePoint_7e3ac0(a.x - b.x, a.y - b.y, a.z - b.z);
}

__forceinline P3Dir Direction_7e3ac0(const P3Update& a, const P3Update& b)
{
    return P3Dir(a.x - b.x, a.y - b.y, a.z - b.z);
}

__forceinline void Clamp_7e3ac0(float& value, float minimum, float maximum)
{
    if (value > maximum)
        value = maximum;
    else if (value < minimum)
        value = minimum;
}


struct S7e3_Extra
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
    unsigned char unk70, unk71, unk72, unk73;
    P3Update FUN_007ddb50();
};
P3Update __cdecl FUN_007b7bf0(S7e3_Actor* actor);
P3Update __cdecl CombatUtilities_GetAngleToProjectedPoint(S7e3_Actor* actor, P3Update point);
struct S7e3_UpdateHandler
{
    int unk00;
    S7e3_Actor* actor;
    S7e3_Extra* unk08;
    UpdateNodeList* path;
    void* request;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    P3Update tether;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    unsigned int moveMode;
    int unk64;
    int unk68;
    int unk6c;
    float splineT;
    int unk74;
    int unk78;
    int unk7c;
    float unk80;
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
    float rotation;
    unsigned char unkc0, unkc1, unkc2, unkc3;
    float unkc4;
    int unkc8, unkcc, unkd0, unkd4, unkd8;
    unsigned char unkdc, unkdd, unkde, unkdf;
    unsigned char unke0, unke1, unke2, unke3;
    void FUN_007e3780(float& heading, float& toTarget);
    void FUN_007e1290(float dt, float toTarget);
    float FUN_007e3ac0(float dt, float* mult);
};


__declspec(noinline) void S7e3_UpdateHandler::FUN_007e3780(float& heading, float& toTarget)
{
    float turn;
    float look = 0.0f;
    if (unkde)
        turn = unk80;
    else if (unkc0)
    {
        if (unkc1 || !path)
            turn = actor->Heading(false);
        else
        {
            P3Update point;
            path->FUN_00605d50(unkc4, &point);
            const P3Update& position = actor->Position();
            P3Dir direction(point.x - position.x, point.y - position.y, 0.0f);
            turn = FUN_00477b20(direction);
        }
    }
    else if (!unke1 && unk08->unk73)
    {
        P3Update target = unk08->FUN_007ddb50();
        P3Update position = FUN_007b7bf0(actor);
        float dx = position.x - target.x;
        float dy = position.y - target.y;
        float distance = (float)((double)dx * dx + (double)dy * dy);
        if (!(distance < actor->FUN_006f9ec0() * actor->FUN_006f9ec0() * 0.25))
            turn = actor->Heading(false);
        else
        {
            P3Update orientation = CombatUtilities_GetAngleToProjectedPoint(actor, target);
            if (!actor->unk141)
                look = orientation.x;
            if (actor->FUN_006f9ec0() < 100.0)
                turn = orientation.z;
            else
            {
                const P3Update& position = actor->Position();
                P3Dir direction(target.x - position.x, target.y - position.y, 0.0f);
                turn = FUN_00477b20(direction);
            }
        }
    }
    else
    {
        P3Update target;
        if (path && path->unk28 > 0)
            path->FUN_00605d50((float)(splineT + 0.10000000149011612), &target);
        else
            target = tether;
        const P3Update& position = actor->Position();
        P3Dir direction(target.x - position.x, target.y - position.y, target.z - position.z);
        if (actor->unk141 &&
            !(fabs(direction.z) > (float)sqrt((float)(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z)) * 0.949999988079071))
            turn = actor->Heading(false);
        else
            turn = FUN_00477b20(direction);
        if (actor->unk141)
            look = 0.0f;
    }
    heading = turn;
    toTarget = look;
}

// pdb: DetailedActorPathHandler::UpdateHeading | DetailedActorPathHandler.obj | fnv360_0822_retail, uconst, low
// pdb params: fdeltaT, afSlowDown
float S7e3_UpdateHandler::FUN_007e3ac0(float dt, float* mult)
{
    float maxTurn = 0.0f;
    float toTarget;
    toTarget = 0.0f;
    float absDifference = 0.0f;
    FUN_007e3780(maxTurn, toTarget);
    float current;
    current = actor->Heading(false);
    FUN_00493030(current, -3.1415927f, 3.1415927f);
    FUN_00493030(maxTurn, -3.1415927f, 3.1415927f);
    float cnt;
    cnt = maxTurn - current;
    FUN_00493030(cnt, -3.1415927f, 3.1415927f);
    absDifference = (float)fabs((double)cnt);
    if (absDifference >= 0.01745329238474369f)
    {
        float scale = 1.0f;
        if ((UpdateNodeList*)path && actor->MaxRotation() > 45.0f)
        {
            float look;
            float distance2;
            float ptr;
            float angleToTarget;
            float facingAngle;
            float targetAngle;
            P3Update tmp;
            P3Update d = PointDifference_7e3ac0(tether, actor->Position());
            look = (float)sqrt((float)(d.x * d.x + d.y * d.y + d.z * d.z));
            ptr = (moveMode & 0x200) ? actor->FUN_006f5b00() : actor->Actor_GetWalkSpeed();
            distance2 = ptr;
            tmp = tether;
            if (look < distance2)
            {
                int index;
                ((UpdateNodeList*)path)->FUN_00604f70(splineT, distance2 - look, 1, &index, &tmp);
            }
            facingAngle = actor->Heading(false);
            P3Dir distance = Direction_7e3ac0(tmp, actor->Position());
            targetAngle = FUN_00477b20(distance);
            angleToTarget = targetAngle - facingAngle;
            FUN_00493030(angleToTarget, -3.1415927f, 3.1415927f);
            scale = (float)fabs(angleToTarget) / 1.5707963267948966;
            Clamp_7e3ac0(scale, 0.02500000037252903f, 1.0f);
        }
        float x = actor->MaxRotation() * 0.01745329238474369 * dt * 3.0 * scale;
        if (x < absDifference)
        {
            if (absDifference > 2.700000047683716f)
                *mult = 0.05f;
            else if (absDifference > 2.0f)
                *mult = 0.1f;
            else if (absDifference > 1.600000023841858)
                *mult = 0.2f;
            else if ((UpdateNodeList*)path && request)
            {
                P3Update d = PointDifference_7e3ac0(actor->Position(),
                    ((UpdateNodeList*)path)->FUN_005d20a0()->location.Point());
                float lookAheadDistance = (float)((double)d.x * d.x + (double)d.y * d.y);
                if (lookAheadDistance < actor->FUN_006f9ec0() * actor->FUN_006f9ec0())
                    *mult = 0.5f;
            }
        }
        Clamp_7e3ac0(cnt, -x, x);
        maxTurn = cnt + current;
    }
    rotation = (float)fabs(cnt);
    FUN_007e1290(dt, toTarget);
    return maxTurn;
}
}   // namespace f3m_007e3ac0
