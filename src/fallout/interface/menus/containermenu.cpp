// fallout/interface/menus/containermenu.cpp: ContainerMenu, MenuStateTarget, MenuLogic, ContainerValue and more (1 function)
#include "f3_common.h"
#include "containermenu_decls.h"
#include "containermenu_packet.h"

struct FUN_00a011f0_shell
{
    char* __thiscall FUN_00a011f0(int);
};

class TESForm
{
  public:
    virtual ~TESForm();
    int GetFormType();
};
class TESBoundObject : public TESForm
{
  public:
};

int __cdecl FUN_00406d00(char* buf, unsigned size, const char* fmt, char* name, int count);

// @f3 0x0063acf0 (community match, verified in this file)
struct FUN_004019c0_owner
{
    void FUN_004019c0(char*, int);
};
struct ContainerUpdate63
{
    bool ItemChange_GetWorn(int);
    int FUN_007270f0();
    char* FUN_0047d5b0();
    void FUN_00bf11a0(int, char*, int);
    void FUN_00bee190(int, float, int);
    char* Tile_GetString(int);
};
void __cdecl FUN_00403230(char* buf, unsigned size, const char* fmt, char* name, int count);

// pdb: ContainerMenu::InitFunc | ContainerMenu.obj | fnv360_0822_retail, objrun, medium
// pdb params: apTile, apItem
void __cdecl FUN_0075d160(void* param1, void* param2)
{
    char buf[0x80];
    ContainerUpdate63* other = (ContainerUpdate63*)param2;
    ContainerUpdate63* self = (ContainerUpdate63*)param1;

    if (other->ItemChange_GetWorn(0))
    {
        ContainerUpdate63* sub = *(ContainerUpdate63**)(*(char**)((char*)param1 + 4) + 8);
        sub->FUN_00bee190(0xfa3, 1.0f, 1);
    }

    if (other->FUN_007270f0() > 1)
    {
        FUN_00403230(buf, 0x80, "%s (%d)", other->FUN_0047d5b0(), other->FUN_007270f0());
        self->FUN_00bf11a0(0xfc4, buf, 1);
    }

    char* name = other->FUN_0047d5b0();
    ((FUN_004019c0_owner*)((char*)param1 + 0x20))->FUN_004019c0(name, 0);
    ContainerUpdate63** pp = (ContainerUpdate63**)(*(char**)((char*)param1 + 8) + 8);
    (*pp)->FUN_00bf11a0(0xfc4, self->Tile_GetString(0xfc4), 1);
    self->FUN_00bee190(0xfb0, 0.0f, 1);
}


// Menu input handler: on accept (1) or cancel (6), play the matching state depending on the controller state.

struct ExpectedReference
{
    bool FUN_004997b0();
};
extern ExpectedReference* DAT_011dea3c;

struct MenuTile
{
    virtual ~MenuTile();
    MenuTile* ReadFile(const char*);
    ContainerMenu* GetMenu();
    float FUN_00a011b0(int);
    static float FUN_00a01530();
    void Set(int, float, bool);
    void Set(int, const char*, bool);
};
struct MenuInput
{
    void FUN_00718630(int, int, int);
};
struct MenuSystem
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    MenuInput input;
    MenuTile* FUN_00586150();
};
MenuSystem* FUN_004b7210();
struct MenuList
{
    void Initialize(Tile*, const char*);
};
MenuTile* FUN_00a08b20(MenuTile*, const char*);
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern InventoryMenuSetting DAT_011d4378, DAT_011d2d0c, DAT_011d33fc, DAT_011d2c7c, DAT_011d412c, DAT_011d330c,
    DAT_011d20c4, DAT_011d396c;

class TESSound
{
  public:
    const char* FUN_00511840();
};

namespace fnv_0075e0b0 {
struct AV_75e0b0
{
    virtual void v0();
    virtual void v4();
    virtual int GetValue(int);
    virtual float GetFloat(int);
    int FUN_0066ef20(int);
};
struct Base_75e0b0
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
    AV_75e0b0 av;
};
struct Actor_75e0b0
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
    virtual bool IsDead();
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
    virtual void UpdateSkill(int, int);
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
    AV_75e0b0 av;
    void FUN_008c00e0(Actor_75e0b0*, int, int);
    Base_75e0b0* FUN_004181e0();
    void FUN_0094fd30(int);
};
extern Actor_75e0b0* DAT_011dea3c;
}  // namespace fnv_0075e0b0

extern double DAT_01072310, DAT_010356b0, DAT_01021928;
void* FUN_00403d30(void*, int, unsigned int);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern unsigned char DAT_011a002c;
extern void* DAT_011d93fc;

struct ContainerMenu;

unsigned __cdecl FUN_00457fe0();
void* __cdecl FUN_00a08b20(void* obj, const char* name);
void* __fastcall FUN_0044ddc0(void* obj);
int __fastcall FUN_00401170(void* obj);

extern ContainerMenu* DAT_011d93f8;

void* __cdecl FUN_00403d30(void*, int, unsigned int);

// 0x0075cd70  unit_5a9677af71cd.cpp  /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall, 2 stack args (ret 8): optional tile lookup, then a switch over the
// tile id (0x14..0x16) driving two mutually exclusive state objects, then the
// shared refresh path that re-inits the visible tile texts.
extern "C" unsigned char DAT_011a002c;
extern "C" void* DAT_011d93fc;

// HandleContainerMenuActivate v1
extern void* DAT_011d93fc;
extern const char DAT_01012058[];
bool __fastcall FUN_004d1360(void* player);

float __cdecl FUN_0048ebc0(int a, bool b);

TESForm* __cdecl FUN_00483a00(void* a1);

void* __fastcall FUN_007af430(void* p);

struct S650Form
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
    virtual unsigned char v37();
    int FUN_00401170();
    unsigned char FUN_004c94d0();
};
struct S650Group
{
    int GetConditionIndex(S650Form*);
};
S650Group* __cdecl FUN_00483a00(char*);

class PlaybackHandle
{
  public:
    unsigned soundID;
    bool assumeSuccess;
    unsigned state;
    PlaybackHandle(const PlaybackHandle&);
    ~PlaybackHandle();
    PlaybackHandle& operator=(const PlaybackHandle&);
};

struct StrMem
{
    char* data;
    unsigned short length, capacity;
    ~StrMem();
    unsigned int FUN_004048e0();
    const char* FUN_00559450();
};
// Native twelve-byte audio handle; its empty but nontrivial destructor is
// retained for the by-value parameter's genuine cleanup contract.
extern "C" unsigned int __cdecl strlen(const char*);
unsigned int __cdecl FUN_00457fe0();

TESForm* FUN_00483a00(const char* pcName);

extern unsigned char DAT_011a002c;
struct Player75
{
};
bool __fastcall FUN_004d1360(Player75*);
double FUN_0048ebc0(void*, bool);
void FUN_0075e650(void*, void*);

extern InventoryMenuSetting DAT_011d29b8, DAT_011d4d50, DAT_011d40b4, DAT_011d2acc, DAT_011d4918;
enum CategoryFilter
{
    FILTER_ALL = 0,
    FILTER_1 = 1,
    FILTER_2 = 2,
    FILTER_3 = 3,
    FILTER_4 = 4,
    FILTER_5 = 5
};

namespace fnv_0075c280 {
struct MenuForm;
struct MenuReference;
struct FUN_00410360
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    FUN_00410360();
    void FUN_0041de40(MenuReference*);
    void FUN_00419970(float);
};
struct FUN_0096a2d0
{
    int unk00, unk04;
    FUN_0096a2d0();
    FUN_00410360** FUN_006815c0();
    void FUN_005ae3d0(FUN_00410360**);
};
struct FUN_004bc550
{
    FUN_0096a2d0* extra;
    int unk04, unk08;
    FUN_004bc550(TESBoundObject*, int);
    const char* GetTargetFullName();
    FUN_0096a2d0* FUN_00559450();
};
struct MenuInventory
{
    unsigned int FUN_0044ddc0();
    FUN_004bc550** FUN_006a7ad0(unsigned int);
};
struct MenuProcess
{
    MenuReference* FUN_0041df00();
};
struct MenuReference
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
    virtual bool IsDead(int);
    MenuInventory* FUN_0075cc70();
    MenuProcess* FUN_005d43c0();
    bool FUN_00437b90();
    MenuForm* FUN_007af430();
    float FUN_00568ad0();
    void GetTwoValues(float*, float*);
};
struct MenuForm
{
    int FUN_00401170();
    MenuForm* Script_IsInListFunction(MenuReference*);
};
struct MenuTileValue
{
    void FUN_00a012d0(float, bool);
};
struct MenuTileHolder
{
    MenuTileValue** FUN_007b5370(int);
};
struct MenuEntry
{
    int unk00;
    MenuTileHolder tile;
};
struct MenuList
{
    virtual void slot0();
    virtual void* GetSelected();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void Clear();
    virtual void Sort(int (*)(FUN_00a011f0_shell**, FUN_00a011f0_shell**));
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

    void FUN_007312e0();
    MenuEntry* FUN_0071a320(FUN_004bc550*, const char*, int, int);
    void PopulateInventoryList(MenuReference*, void (*)(), int, int, int, int);
    void FUN_007314c0(void (*)(), int, int);
    void ApplyFilter(void (*)());
    unsigned int FUN_0071ae60();
    void UpdateCurrentValueTile(int);
    void* CallVirtualZero(int);
};
struct StrMem
{
    char* text;
    unsigned short length, capacity;
    StrMem();
    ~StrMem();
    const char* FUN_00559450();
};
struct MenuSetting
{
    const char* FUN_00403df0();
};
extern MenuSetting DAT_011d3f70, DAT_011d1e60;
extern MenuReference* DAT_011dea3c;
extern const char DAT_01012058[], DAT_010722d0[];
void FUN_0075d160();
void FUN_0075e650();
void* FUN_004bf220(MenuReference*);
int FUN_00406d00(char*, unsigned int, const char*, ...);
struct MenuInput
{
    void FUN_00715860(void*, int);
};
MenuInput* FUN_004b7210();
struct MenuTile
{
    void FUN_00a01350(int, const char*, bool);
};

}  // namespace fnv_0075c280

struct ObjRef
{
    TESBoundObject* FUN_0044ddc0();
    void* FUN_00559450();
    int FUN_004459e0(int a1);
};
struct InvChg
{
    ObjRef* FindEntryWithExtraListType(int a1);
    void ClearExtraForSlot(ObjRef* b, int a2);
    void SetInventorySlotExtraData(ObjRef* p, int v, int a3);
};
InvChg* __cdecl FUN_004bf220(void* arg);
