// src/f3staging/f3blk_00880000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00894b50 (community match, verified in this file)
#include <math.h>
struct __declspec(align(16)) MapMatrix {
 float m[4][4];
 __forceinline void Identity() {
  m[0][1]=m[0][2]=m[0][3]=m[1][0]=m[1][2]=m[1][3]=m[2][0]=m[2][1]=m[2][3]=m[3][0]=m[3][1]=m[3][2]=0.0f;
  m[0][0]=m[1][1]=m[2][2]=m[3][3]=1.0f;
 }
};
struct MatrixWorkspace { MapMatrix a,b,c,d,e,f,g; };
struct Mapping { int unk000,unk004,unk008,unk00C; unsigned int mapping; int unk014; unsigned int index; };
struct Vec4 {float x,y,z,w;};
extern MapMatrix DAT_01091b70;
extern Vec4 DAT_01091bf0;
struct Color3 {float r,g,b;};
extern Color3 DAT_0108f450;
extern void* DAT_01090974;
extern const char* DAT_00f772f0;
extern "C" MapMatrix* __stdcall FUN_00c20844(MapMatrix*,float*,MapMatrix*);
extern "C" MapMatrix* __stdcall FUN_00c2083e(MapMatrix*,MapMatrix*);
extern "C" MapMatrix* __stdcall FUN_00c2082c(MapMatrix*,MapMatrix*,MapMatrix*);
extern void __cdecl FUN_00892390(MapMatrix*,char*,bool,bool,int);
struct Renderer {
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
int unk4D4;
int unk4D8;
int unk4DC;
int unk4E0;
int unk4E4;
int unk4E8;
int unk4EC;
int unk4F0;
int unk4F4;
int unk4F8;
int unk4FC;
int unk500;
int unk504;
int unk508;
int unk50C;
int unk510;
int unk514;
int unk518;
int unk51C;
int unk520;
int unk524;
int unk528;
int unk52C;
int unk530;
int unk534;
int unk538;
int unk53C;
int unk540;
int unk544;
int unk548;
int unk54C;
int unk550;
int unk554;
int unk558;
int unk55C;
int unk560;
int unk564;
int unk568;
int unk56C;
int unk570;
int unk574;
int unk578;
int unk57C;
int unk580;
int unk584;
int unk588;
int unk58C;
int unk590;
int unk594;
int unk598;
int unk59C;
int unk5A0;
int unk5A4;
int unk5A8;
int unk5AC;
int unk5B0;
int unk5B4;
int unk5B8;
int unk5BC;
int unk5C0;
int unk5C4;
int unk5C8;
int unk5CC;
int unk5D0;
int unk5D4;
int unk5D8;
int unk5DC;
int unk5E0;
int unk5E4;
int unk5E8;
int unk5EC;
int unk5F0;
int unk5F4;
int unk5F8;
int unk5FC;
int unk600;
int unk604;
int unk608;
int unk60C;
int unk610;
int unk614;
int unk618;
int unk61C;
int unk620;
int unk624;
int unk628;
int unk62C;
int unk630;
int unk634;
int unk638;
int unk63C;
int unk640;
int unk644;
int unk648;
int unk64C;
int unk650;
int unk654;
int unk658;
int unk65C;
int unk660;
int unk664;
int unk668;
int unk66C;
int unk670;
int unk674;
int unk678;
int unk67C;
int unk680;
int unk684;
int unk688;
int unk68C;
int unk690;
int unk694;
int unk698;
int unk69C;
int unk6A0;
int unk6A4;
int unk6A8;
int unk6AC;
int unk6B0;
int unk6B4;
int unk6B8;
int unk6BC;
int unk6C0;
int unk6C4;
int unk6C8;
int unk6CC;
int unk6D0;
int unk6D4;
int unk6D8;
int unk6DC;
int unk6E0;
int unk6E4;
int unk6E8;
int unk6EC;
int unk6F0;
int unk6F4;
int unk6F8;
int unk6FC;
int unk700;
int unk704;
int unk708;
int unk70C;
int unk710;
int unk714;
int unk718;
int unk71C;
int unk720;
int unk724;
int unk728;
int unk72C;
int unk730;
int unk734;
int unk738;
int unk73C;
int unk740;
int unk744;
int unk748;
int unk74C;
int unk750;
int unk754;
int unk758;
int unk75C;
int unk760;
int unk764;
int unk768;
int unk76C;
int unk770;
int unk774;
int unk778;
int unk77C;
int unk780;
int unk784;
int unk788;
int unk78C;
int unk790;
int unk794;
int unk798;
int unk79C;
int unk7A0;
int unk7A4;
int unk7A8;
int unk7AC;
int unk7B0;
int unk7B4;
int unk7B8;
int unk7BC;
int unk7C0;
int unk7C4;
int unk7C8;
int unk7CC;
int unk7D0;
int unk7D4;
int unk7D8;
int unk7DC;
int unk7E0;
int unk7E4;
int unk7E8;
int unk7EC;
int unk7F0;
int unk7F4;
int unk7F8;
int unk7FC;
int unk800;
int unk804;
int unk808;
int unk80C;
int unk810;
int unk814;
int unk818;
int unk81C;
int unk820;
int unk824;
int unk828;
int unk82C;
int unk830;
int unk834;
int unk838;
int unk83C;
int unk840;
int unk844;
int unk848;
int unk84C;
int unk850;
int unk854;
int unk858;
int unk85C;
int unk860;
int unk864;
int unk868;
int unk86C;
int unk870;
int unk874;
int unk878;
int unk87C;
int unk880;
int unk884;
int unk888;
int unk88C;
int unk890;
int unk894;
int unk898;
int unk89C;
int unk8A0;
int unk8A4;
int unk8A8;
int unk8AC;
int unk8B0;
int unk8B4;
int unk8B8;
int unk8BC;
int unk8C0;
int unk8C4;
int unk8C8;
int unk8CC;
int unk8D0;
int unk8D4;
int unk8D8;
int unk8DC;
int unk8E0;
int unk8E4;
int unk8E8;
int unk8EC;
int unk8F0;
int unk8F4;
int unk8F8;
int unk8FC;
int unk900;
int unk904;
int unk908;
int unk90C;
int unk910;
int unk914;
int unk918;
int unk91C;
int unk920;
int unk924;
int unk928;
int unk92C;
int unk930;
int unk934;
int unk938;
int unk93C;
 MapMatrix world, view, projection, unkA00, inverseView;
};
struct NameString {char* FUN_008909f0();};
struct Texture {int unk000,unk004,unk008;NameString* name;};
struct TextureSlots {Texture* base;Texture* unk004;Texture* detail;Texture* gloss;Texture* glow;Texture* bump;Texture* unk018;Texture* unk01C;Texture* shader[1];};
struct Texturing {
int unk000;
int unk004;
int unk008;
int unk00C;
int unk010;
int unk014;
int unk018;
int unk01C;
 TextureSlots* slots;
 Texture* FUN_008865c0(unsigned int i);
};
struct NiPoint3 {float x,y,z;};
struct Material {
int unk000;
int unk004;
int unk008;
int unk00C;
int unk010;
int unk014;
int unk018;
 NiPoint3 diffuse;
 NiPoint3 specular;
 NiPoint3* replacement;
 float gloss, alpha;
 NiPoint3& Specular(){return replacement?*replacement:specular;}
};
struct Properties {int unk000,unk004; Material* material;int unk00C,unk010;Texturing* textures;};
struct ExtraValue {int unk000,unk004,unk008;float value;};
struct TimeString {void* value; TimeString* FUN_00422920(const char*); void FUN_00422950(); __forceinline ~TimeString(){FUN_00422950();} };
struct NiAVObjectCall {ExtraValue* FUN_00824a50(TimeString&);};
struct EffectLink { EffectLink* next;void* value;};
struct Effects {
 int unk000,unk004,unk008;EffectLink* head;
 EffectLink* Head(){return head;}
 void* Next(EffectLink*& it){void* v=it->value;it=it->next;return v;}
};
struct PointExt {float x,y,z; NiPoint3* FUN_00575500(NiPoint3*,float);};
struct Light {
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
 bool enabled;
int unk0A0;
int unk0A4;
int unk0A8;
int unk0AC;
int unk0B0;
int unk0B4;
int unk0B8;
int unk0BC;
int unk0C0;
 float dimmer;NiPoint3 ambient;
};
struct LightObject { static Light* __cdecl FUN_00424d50(void* type,void* object); };
struct ConstantMapView {
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
 Renderer* renderer;
 unsigned int FUN_00894b50(unsigned int,Mapping*,NiAVObjectCall*,void*,Properties*,Effects*,void*,unsigned int);
};
extern "C" void _ReadWriteBarrier();
// pdb: NiD3DShaderConstantMap::SetupDefinedConstantValue | NiD3DShaderConstantMap.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: uiOperatorNum, pkEntry, pkGeometry, pkSkin, pkState, pkEffects, kWorld, kWorldBound
unsigned int ConstantMapView::FUN_00894b50(unsigned int slot, Mapping* apMapping, NiAVObjectCall* geometry, void* skin,
                                           Properties* state, Effects* effects, void*, unsigned int)
{
    MatrixWorkspace work;
    unsigned int mapping = apMapping->mapping;
    switch (mapping)
    {
    case 1:
    case 2:
    case 13:
    case 14: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 2 || mapping == 14)
            inverse = true;
        if (mapping == 13 || mapping == 14)
            transpose = true;
        work.a = renderer->projection;
        reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot] = work.a;
        if (inverse)
            FUN_00c20844(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        if (transpose)
            FUN_00c2083e(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        return 9;
    }
    case 3:
    case 4:
    case 15:
    case 16: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 4 || mapping == 16)
            inverse = true;
        if (mapping == 15 || mapping == 16)
            transpose = true;
        work.a = renderer->view;
        reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot] = work.a;
        if (inverse)
            FUN_00c20844(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        if (transpose)
            FUN_00c2083e(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        return 9;
    }
    case 5:
    case 6:
    case 17:
    case 18: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 6 || mapping == 18)
            inverse = true;
        if (mapping == 17 || mapping == 18)
            transpose = true;
        reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot] = renderer->world;
        if (inverse)
            FUN_00c20844(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        if (transpose)
            FUN_00c2083e(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        return 9;
    }
    case 7:
    case 8:
    case 19:
    case 20: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 8 || mapping == 20)
            inverse = true;
        if (mapping == 19 || mapping == 20)
            transpose = true;
        {
            Renderer* r = renderer;
            const MapMatrix* world = &r->world;
            const MapMatrix* view = &r->view;
            work.b = *world;
            work.a = *view;
        }
        FUN_00c2082c(&work.f, &work.b, &work.a);
        reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot] = work.f;
        if (inverse)
            FUN_00c20844(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        if (transpose)
            FUN_00c2083e(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        return 9;
    }
    case 9:
    case 10:
    case 21:
    case 22: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 10 || mapping == 22)
            inverse = true;
        if (mapping == 21 || mapping == 22)
            transpose = true;
        {
            Renderer* r = renderer;
            const MapMatrix* view = &r->view;
            const MapMatrix* projection = &r->projection;
            work.a = *view;
            work.b = *projection;
        }
        FUN_00c2082c(&work.e, &work.a, &work.b);
        reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot] = work.e;
        if (inverse)
            FUN_00c20844(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        if (transpose)
            FUN_00c2083e(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        return 9;
    }
    case 11:
    case 12:
    case 23:
    case 24: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 12 || mapping == 24)
            inverse = true;
        if (mapping == 23 || mapping == 24)
            transpose = true;
        {
            Renderer* r = renderer;
            work.a = r->world;
            const MapMatrix* view = &r->view;
            const MapMatrix* projection = &r->projection;
            work.b = *view;
            work.d = *projection;
        }
        FUN_00c2082c(&work.c, &work.a, &work.b);
        FUN_00c2082c(&work.g, &work.c, &work.d);
        reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot] = work.g;
        if (inverse)
            FUN_00c20844(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        if (transpose)
            FUN_00c2083e(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        return 9;
    }
    case 25:
    case 26:
    case 27:
    case 28: {
        if (!skin)
            return 0;
        reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot].Identity();
        bool inverse = false;
        bool transpose = false;
        if (mapping == 26 || mapping == 28)
            inverse = true;
        if (mapping == 27 || mapping == 28)
            transpose = true;
        work.c = renderer->view;
        FUN_00c2082c(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                     &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], &work.c);
        if (inverse)
            FUN_00c20844(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        if (transpose)
            FUN_00c2083e(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        return 9;
    }
    case 29:
    case 30:
    case 31:
    case 32: {
        if (!skin)
            return 0;
        reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot].Identity();
        bool inverse = false;
        bool transpose = false;
        if (mapping == 30 || mapping == 32)
            inverse = true;
        if (mapping == 31 || mapping == 32)
            transpose = true;
        work.c = renderer->view;
        work.d = renderer->projection;
        FUN_00c2082c(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                     &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], &work.c);
        FUN_00c2082c(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                     &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], &work.d);
        if (inverse)
            FUN_00c20844(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        if (transpose)
            FUN_00c2083e(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        return 9;
    }
    case 33:
    case 34:
    case 35:
    case 36:
    case 69:
    case 70:
    case 71:
    case 72:
    case 80:
    case 81:
        return 0;
    case 96:
    case 97:
    case 98:
    case 99: {
        if (!skin)
            return 0;
        reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot].Identity();
        bool inverse = false;
        bool transpose = false;
        if (mapping == 97 || mapping == 99)
            inverse = true;
        if (mapping == 98 || mapping == 99)
            transpose = true;

        if (inverse)
            FUN_00c20844(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        if (transpose)
            FUN_00c2083e(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot]);
        return 9;
    }
    case 37:
    case 38:
    case 39:
    case 40: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->base;
            if (texture && texture->name)
            {
                name = texture->name->FUN_008909f0();
                if (mapping == 38 || mapping == 40)
                    inverse = true;
                if (mapping == 39 || mapping == 40)
                    transpose = true;
            }
        }
        FUN_00892390(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 41:
    case 42:
    case 43:
    case 44: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->bump;
            if (texture && texture->name)
            {
                name = texture->name->FUN_008909f0();
                if (mapping == 42 || mapping == 44)
                    inverse = true;
                if (mapping == 43 || mapping == 44)
                    transpose = true;
            }
        }
        FUN_00892390(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 45:
    case 46:
    case 47:
    case 48: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->detail;
            if (texture && texture->name)
            {
                name = texture->name->FUN_008909f0();
                if (mapping == 46 || mapping == 48)
                    inverse = true;
                if (mapping == 47 || mapping == 48)
                    transpose = true;
            }
        }
        FUN_00892390(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 49:
    case 50:
    case 51:
    case 52: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->gloss;
            if (texture && texture->name)
            {
                name = texture->name->FUN_008909f0();
                if (mapping == 50 || mapping == 52)
                    inverse = true;
                if (mapping == 51 || mapping == 52)
                    transpose = true;
            }
        }
        FUN_00892390(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 53:
    case 54:
    case 55:
    case 56: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->glow;
            if (texture && texture->name)
            {
                name = texture->name->FUN_008909f0();
                if (mapping == 54 || mapping == 56)
                    inverse = true;
                if (mapping == 55 || mapping == 56)
                    transpose = true;
            }
        }
        FUN_00892390(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 57:
    case 58:
    case 59:
    case 60: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->bump;
            if (texture && texture->name)
            {
                name = texture->name->FUN_008909f0();
                if (mapping == 58 || mapping == 60)
                    inverse = true;
                if (mapping == 59 || mapping == 60)
                    transpose = true;
            }
        }
        FUN_00892390(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 61:
    case 62:
    case 63:
    case 64: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->shader[apMapping->index];
            if (texture && texture->name)
            {
                name = texture->name->FUN_008909f0();
                if (mapping == 62 || mapping == 64)
                    inverse = true;
                if (mapping == 63 || mapping == 64)
                    transpose = true;
            }
        }
        FUN_00892390(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 65:
    case 66:
    case 67:
    case 68: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->FUN_008865c0(apMapping->index);
            if (texture && texture->name)
            {
                name = texture->name->FUN_008909f0();
                if (mapping == 66 || mapping == 68)
                    inverse = true;
                if (mapping == 67 || mapping == 68)
                    transpose = true;
            }
        }
        FUN_00892390(&reinterpret_cast<MapMatrix*>(&DAT_01091b70)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 73: {
        Material* material = state->material;
        if (!material)
            return 0;
        (&DAT_01091bf0)[slot].x = DAT_0108f450.r;
        (&DAT_01091bf0)[slot].y = DAT_0108f450.g;
        (&DAT_01091bf0)[slot].z = DAT_0108f450.b;
        (&DAT_01091bf0)[slot].w = material->alpha;
        return 10;
    }
    case 74: {
        Material* material = state->material;
        if (!material)
            return 0;
        (&DAT_01091bf0)[slot].x = DAT_0108f450.r;
        (&DAT_01091bf0)[slot].y = DAT_0108f450.g;
        (&DAT_01091bf0)[slot].z = DAT_0108f450.b;
        (&DAT_01091bf0)[slot].w = material->alpha;
        return 10;
    }
    case 75: {
        Material* material = state->material;
        if (!material)
            return 0;
        (&DAT_01091bf0)[slot].x = material->diffuse.x;
        (&DAT_01091bf0)[slot].y = material->diffuse.y;
        (&DAT_01091bf0)[slot].z = material->diffuse.z;
        (&DAT_01091bf0)[slot].w = material->alpha;
        return 10;
    }
    case 76: {
        Material* material = state->material;
        if (!material)
            return 0;
        (&DAT_01091bf0)[slot].x = material->Specular().x;
        (&DAT_01091bf0)[slot].y = material->Specular().y;
        (&DAT_01091bf0)[slot].z = material->Specular().z;
        (&DAT_01091bf0)[slot].w = material->alpha;
        return 10;
    }
    case 77: {
        Material* material = state->material;
        if (!material)
            return 0;
        (&DAT_01091bf0)[slot].x = material->gloss;
        (&DAT_01091bf0)[slot].y = material->gloss;
        (&DAT_01091bf0)[slot].z = material->gloss;
        (&DAT_01091bf0)[slot].w = material->gloss;
        return 10;
    }
    case 78: {
        work.a = renderer->inverseView;
        (&DAT_01091bf0)[slot].x = work.a.m[3][0];
        (&DAT_01091bf0)[slot].y = work.a.m[3][1];
        (&DAT_01091bf0)[slot].z = work.a.m[3][2];
        (&DAT_01091bf0)[slot].w = work.a.m[3][3];
        return 7;
    }
    case 79: {
        work.a = renderer->inverseView;
        (&DAT_01091bf0)[slot].x = work.a.m[2][0];
        (&DAT_01091bf0)[slot].y = work.a.m[2][1];
        (&DAT_01091bf0)[slot].z = work.a.m[2][2];
        (&DAT_01091bf0)[slot].w = work.a.m[2][3];
        return 7;
    }
    case 82:
    case 83:
    case 84:
    case 85:
    case 86: {
        ExtraValue* extra = geometry->FUN_00824a50(*TimeString().FUN_00422920(DAT_00f772f0));
        if (!extra)
            return 16;
        float value = extra->value;
        switch (mapping)
        {
        case 82:
            (&DAT_01091bf0)[slot].x = value;
            (&DAT_01091bf0)[slot].y = value;
            (&DAT_01091bf0)[slot].z = value;
            (&DAT_01091bf0)[slot].w = value;
            return 7;
        case 83: {
            float s = (float)sin(value);
            (&DAT_01091bf0)[slot].x = s;
            (&DAT_01091bf0)[slot].y = s;
            (&DAT_01091bf0)[slot].z = s;
            (&DAT_01091bf0)[slot].w = s;
            return 7;
        }
        case 84: {
            float s = (float)cos(value);
            (&DAT_01091bf0)[slot].x = s;
            (&DAT_01091bf0)[slot].y = s;
            (&DAT_01091bf0)[slot].z = s;
            (&DAT_01091bf0)[slot].w = s;
            return 7;
        }
        case 85: {
            float s = (float)tan(value);
            (&DAT_01091bf0)[slot].x = s;
            (&DAT_01091bf0)[slot].y = s;
            (&DAT_01091bf0)[slot].z = s;
            (&DAT_01091bf0)[slot].w = s;
            return 7;
        }
        case 86:
            (&DAT_01091bf0)[slot].x = value;
            (&DAT_01091bf0)[slot].y = (float)sin(value);
            (&DAT_01091bf0)[slot].z = (float)cos(value);
            (&DAT_01091bf0)[slot].w = (float)tan(value);
            return 7;
        }
        break;
    }
    case 87: {
        int outputIndex=(int)slot;
        (&DAT_01091bf0)[outputIndex].x = 0.0f;
        (&DAT_01091bf0)[outputIndex].y = 0.0f;
        (&DAT_01091bf0)[outputIndex].z = 0.0f;
        (&DAT_01091bf0)[outputIndex].w = 1.0f;
        if (effects)
        {
            EffectLink* iter = effects->Head();
            while (iter)
            {
                void* payload = iter->value;
                EffectLink* next = iter->next;
                Light* light = LightObject::FUN_00424d50(&DAT_01090974, payload);
                if (light && light->enabled)
                {
                    iter = next;
                    NiPoint3 point;
                    ((PointExt*)&light->ambient)->FUN_00575500(&point, light->dimmer);
                    (&DAT_01091bf0)[outputIndex].x = (&DAT_01091bf0)[outputIndex].x + point.x;
                    (&DAT_01091bf0)[outputIndex].y = point.y + (&DAT_01091bf0)[outputIndex].y;
                    (&DAT_01091bf0)[outputIndex].z = (&DAT_01091bf0)[outputIndex].z + point.z;
                }
                else
                    iter = next;
            }
        }
        _ReadWriteBarrier();
        return 7;
    }
    }
    return 0;
}
