#include "f3_common.h"
// src/staging/blk_00e20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00e3f340_Class
{
    int __thiscall hkPredGskAgent3_createZombie(int arg);
    void* __thiscall GetEntryByArg(int arg);
};

// @f3 0x00448800 (community match, verified in this file)
#include <stdlib.h>

struct FUN_00e3f340_Stand
{
    void* __thiscall FUN_00447d60(void* p, int n);
};

// pdb: TESFile::GetChunkData | TESFile.obj | fnv360_0822_retail, call_seq, high
// pdb params: apData, apData, apData
void* __thiscall FUN_00e3f340_Class::GetEntryByArg(int arg)
{
    int* p = (int*)arg;
    void* r = ((FUN_00e3f340_Stand*)this)->FUN_00447d60(p, 4);
    if (*((char*)this + 0x299) != 0)
    {
        *p = (int)_byteswap_ulong((unsigned long)*p);
    }
    return r;
}


struct FUN_00e3f900_class
{
    int __thiscall FUN_00cb0a70(int a);
    int __thiscall FUN_00e3f900(int a);
};

// @fnv 0x00e3f900
int __thiscall FUN_00e3f900_class::FUN_00e3f900(int a)
{
    FUN_00cb0a70(a);
    return (int)this;
}

struct S_00df8990_Obj;
extern void(__cdecl* DAT_0126ec04)(void*, void*, S_00df8990_Obj*);
void __cdecl FUN_00e2b9b0(void*, void*, S_00df8990_Obj*);
// @fnv 0x00e2ba90
void __cdecl FUN_00e2ba90()
{
    DAT_0126ec04 = FUN_00e2b9b0;
}

extern int DAT_010eb770;

int __cdecl hkString_strCasecmp(int, int);

struct D481D0RefVariant
{
    void set(void*, const void*);
};
struct FUN_00e3f8d0_class
{
    void FUN_00e3f8d0(void* a, const void* b);
};
// @fnv 0x00e3f8d0
void FUN_00e3f8d0_class::FUN_00e3f8d0(void* a, const void* b)
{
    ((D481D0RefVariant*)((char*)this + 4))->set(a, b);
}

struct FUN_00e29620_class
{
    void __thiscall FUN_00e29620(int param);
};

// @fnv 0x00e298f0
// pdb: hkMatrix6SetInvert | hkMatrix6.obj | tesv_win, call_dedup, low
void __cdecl FUN_00e298f0(FUN_00e29620_class* object, int param)
{
    object->FUN_00e29620(param);
}

struct FUN_00e2d0d0_cls;
struct E2d0Ref;
struct E2d0Node;

extern float DAT_0104da48;

struct E2d0Owner
{
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
    E2d0Ref* m_pRef30;
};

struct E2d0Ref
{
    E2d0Owner* m_pSharedOwner;
    unsigned int unk04;
    unsigned int unk08;
    E2d0Node* m_pReferencedNode;
};

struct E2d0Slot
{
    E2d0Ref* m_pReference;
    unsigned int unk04;
    float m_f08;
    int m_state0c;
};

struct E2d0Node
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    E2d0Slot m_slots[3];
    int Probe(int a, FUN_00e2d0d0_cls* self, int* out);
};

struct FUN_00e2d0d0_cls
{
    unsigned int unk00;
    int m_04;
    unsigned int unk08;
    int m_count0c;
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
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59C;
    unsigned int unk5A0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    unsigned int unk5C4;
    unsigned int unk5C8;
    unsigned int unk5CC;
    unsigned int unk5D0;
    unsigned int unk5D4;
    unsigned int unk5D8;
    unsigned int unk5DC;
    unsigned int unk5E0;
    unsigned int unk5E4;
    unsigned int unk5E8;
    unsigned int unk5EC;
    unsigned int unk5F0;
    unsigned int unk5F4;
    unsigned int unk5F8;
    unsigned int unk5FC;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60C;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61C;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62C;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63C;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64C;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65C;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66C;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67C;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68C;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69C;
    unsigned int unk6A0;
    unsigned int unk6A4;
    unsigned int unk6A8;
    unsigned int unk6AC;
    unsigned int unk6B0;
    unsigned int unk6B4;
    unsigned int unk6B8;
    unsigned int unk6BC;
    unsigned int unk6C0;
    unsigned int unk6C4;
    unsigned int unk6C8;
    unsigned int unk6CC;
    unsigned int unk6D0;
    unsigned int unk6D4;
    unsigned int unk6D8;
    unsigned int unk6DC;
    unsigned int unk6E0;
    unsigned int unk6E4;
    unsigned int unk6E8;
    unsigned int unk6EC;
    unsigned int unk6F0;
    unsigned int unk6F4;
    unsigned int unk6F8;
    unsigned int unk6FC;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70C;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71C;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72C;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73C;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74C;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75C;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76C;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77C;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78C;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79C;
    unsigned int unk7A0;
    unsigned int unk7A4;
    unsigned int unk7A8;
    unsigned int unk7AC;
    unsigned int unk7B0;
    unsigned int unk7B4;
    unsigned int unk7B8;
    unsigned int unk7BC;
    unsigned int unk7C0;
    unsigned int unk7C4;
    unsigned int unk7C8;
    unsigned int unk7CC;
    unsigned int unk7D0;
    unsigned int unk7D4;
    unsigned int unk7D8;
    unsigned int unk7DC;
    unsigned int unk7E0;
    unsigned int unk7E4;
    unsigned int unk7E8;
    unsigned int unk7EC;
    unsigned int unk7F0;
    unsigned int unk7F4;
    unsigned int unk7F8;
    unsigned int unk7FC;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80C;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81C;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82C;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83C;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84C;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85C;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86C;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87C;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88C;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89C;
    unsigned int unk8A0;
    unsigned int unk8A4;
    unsigned int unk8A8;
    unsigned int unk8AC;
    unsigned int unk8B0;
    unsigned int unk8B4;
    unsigned int unk8B8;
    unsigned int unk8BC;
    unsigned int unk8C0;
    unsigned int unk8C4;
    unsigned int unk8C8;
    unsigned int unk8CC;
    unsigned int unk8D0;
    unsigned int unk8D4;
    unsigned int unk8D8;
    unsigned int unk8DC;
    unsigned int unk8E0;
    unsigned int unk8E4;
    unsigned int unk8E8;
    unsigned int unk8EC;
    unsigned int unk8F0;
    unsigned int unk8F4;
    unsigned int unk8F8;
    unsigned int unk8FC;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90C;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91C;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92C;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93C;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94C;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95C;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96C;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97C;
    unsigned int unk980;
    unsigned int unk984;
    unsigned int unk988;
    unsigned int unk98C;
    unsigned int unk990;
    unsigned int unk994;
    unsigned int unk998;
    unsigned int unk99C;
    unsigned int unk9A0;
    unsigned int unk9A4;
    unsigned int unk9A8;
    unsigned int unk9AC;
    unsigned int unk9B0;
    unsigned int unk9B4;
    unsigned int unk9B8;
    unsigned int unk9BC;
    unsigned int unk9C0;
    unsigned int unk9C4;
    unsigned int unk9C8;
    unsigned int unk9CC;
    unsigned int unk9D0;
    unsigned int unk9D4;
    unsigned int unk9D8;
    unsigned int unk9DC;
    unsigned int unk9E0;
    unsigned int unk9E4;
    unsigned int unk9E8;
    unsigned int unk9EC;
    unsigned int unk9F0;
    unsigned int unk9F4;
    unsigned int unk9F8;
    unsigned int unk9FC;
    unsigned int unkA00;
    unsigned int unkA04;
    unsigned int unkA08;
    unsigned int unkA0C;
    unsigned int unkA10;
    unsigned int unkA14;
    unsigned int unkA18;
    unsigned int unkA1C;
    unsigned int unkA20;
    unsigned int unkA24;
    unsigned int unkA28;
    unsigned int unkA2C;
    unsigned int unkA30;
    unsigned int unkA34;
    unsigned int unkA38;
    unsigned int unkA3C;
    unsigned int unkA40;
    unsigned int unkA44;
    unsigned int unkA48;
    unsigned int unkA4C;
    unsigned int unkA50;
    unsigned int unkA54;
    unsigned int unkA58;
    unsigned int unkA5C;
    unsigned int unkA60;
    unsigned int unkA64;
    unsigned int unkA68;
    unsigned int unkA6C;
    unsigned int unkA70;
    unsigned int unkA74;
    unsigned int unkA78;
    unsigned int unkA7C;
    unsigned int unkA80;
    unsigned int unkA84;
    unsigned int unkA88;
    unsigned int unkA8C;
    unsigned int unkA90;
    unsigned int unkA94;
    unsigned int unkA98;
    unsigned int unkA9C;
    unsigned int unkAA0;
    unsigned int unkAA4;
    unsigned int unkAA8;
    unsigned int unkAAC;
    unsigned int unkAB0;
    unsigned int unkAB4;
    unsigned int unkAB8;
    unsigned int unkABC;
    unsigned int unkAC0;
    unsigned int unkAC4;
    unsigned int unkAC8;
    unsigned int unkACC;
    unsigned int unkAD0;
    unsigned int unkAD4;
    unsigned int unkAD8;
    unsigned int unkADC;
    unsigned int unkAE0;
    unsigned int unkAE4;
    unsigned int unkAE8;
    unsigned int unkAEC;
    unsigned int unkAF0;
    unsigned int unkAF4;
    unsigned int unkAF8;
    unsigned int unkAFC;
    unsigned int unkB00;
    unsigned int unkB04;
    unsigned int unkB08;
    unsigned int unkB0C;
    unsigned int unkB10;
    unsigned int unkB14;
    unsigned int unkB18;
    unsigned int unkB1C;
    unsigned int unkB20;
    unsigned int unkB24;
    unsigned int unkB28;
    unsigned int unkB2C;
    unsigned int unkB30;
    unsigned int unkB34;
    unsigned int unkB38;
    unsigned int unkB3C;
    unsigned int unkB40;
    unsigned int unkB44;
    unsigned int unkB48;
    unsigned int unkB4C;
    unsigned int unkB50;
    unsigned int unkB54;
    unsigned int unkB58;
    unsigned int unkB5C;
    unsigned int unkB60;
    unsigned int unkB64;
    unsigned int unkB68;
    unsigned int unkB6C;
    unsigned int unkB70;
    unsigned int unkB74;
    unsigned int unkB78;
    unsigned int unkB7C;
    unsigned int unkB80;
    unsigned int unkB84;
    unsigned int unkB88;
    unsigned int unkB8C;
    unsigned int unkB90;
    unsigned int unkB94;
    unsigned int unkB98;
    unsigned int unkB9C;
    unsigned int unkBA0;
    unsigned int unkBA4;
    unsigned int unkBA8;
    unsigned int unkBAC;
    unsigned int unkBB0;
    unsigned int unkBB4;
    unsigned int unkBB8;
    unsigned int unkBBC;
    unsigned int unkBC0;
    unsigned int unkBC4;
    unsigned int unkBC8;
    unsigned int unkBCC;
    unsigned int unkBD0;
    unsigned int unkBD4;
    unsigned int unkBD8;
    unsigned int unkBDC;
    unsigned int unkBE0;
    unsigned int unkBE4;
    unsigned int unkBE8;
    unsigned int unkBEC;
    unsigned int unkBF0;
    unsigned int unkBF4;
    unsigned int unkBF8;
    unsigned int unkBFC;
    unsigned int unkC00;
    unsigned int unkC04;
    unsigned int unkC08;
    unsigned int unkC0C;
    unsigned int unkC10;
    unsigned int unkC14;
    unsigned int unkC18;
    unsigned int unkC1C;
    unsigned int unkC20;
    unsigned int unkC24;
    unsigned int unkC28;
    unsigned int unkC2C;
    unsigned int unkC30;
    unsigned int unkC34;
    unsigned int unkC38;
    unsigned int unkC3C;
    unsigned int unkC40;
    unsigned int unkC44;
    unsigned int unkC48;
    unsigned int unkC4C;
    unsigned int unkC50;
    unsigned int unkC54;
    unsigned int unkC58;
    unsigned int unkC5C;
    unsigned int unkC60;
    unsigned int unkC64;
    unsigned int unkC68;
    unsigned int unkC6C;
    unsigned int unkC70;
    unsigned int unkC74;
    unsigned int unkC78;
    unsigned int unkC7C;
    unsigned int unkC80;
    unsigned int unkC84;
    unsigned int unkC88;
    unsigned int unkC8C;
    unsigned int unkC90;
    unsigned int unkC94;
    unsigned int unkC98;
    unsigned int unkC9C;
    unsigned int unkCA0;
    unsigned int unkCA4;
    unsigned int unkCA8;
    unsigned int unkCAC;
    unsigned int unkCB0;
    unsigned int unkCB4;
    unsigned int unkCB8;
    unsigned int unkCBC;
    unsigned int unkCC0;
    unsigned int unkCC4;
    unsigned int unkCC8;
    unsigned int unkCCC;
    unsigned int unkCD0;
    unsigned int unkCD4;
    unsigned int unkCD8;
    unsigned int unkCDC;
    unsigned int unkCE0;
    unsigned int unkCE4;
    unsigned int unkCE8;
    unsigned int unkCEC;
    unsigned int unkCF0;
    unsigned int unkCF4;
    unsigned int unkCF8;
    unsigned int unkCFC;
    unsigned int unkD00;
    unsigned int unkD04;
    unsigned int unkD08;
    unsigned int unkD0C;
    unsigned int unkD10;
    unsigned int unkD14;
    unsigned int unkD18;
    unsigned int unkD1C;
    unsigned int unkD20;
    unsigned int unkD24;
    unsigned int unkD28;
    unsigned int unkD2C;
    unsigned int unkD30;
    unsigned int unkD34;
    unsigned int unkD38;
    unsigned int unkD3C;
    unsigned int unkD40;
    unsigned int unkD44;
    unsigned int unkD48;
    unsigned int unkD4C;
    unsigned int unkD50;
    unsigned int unkD54;
    unsigned int unkD58;
    unsigned int unkD5C;
    unsigned int unkD60;
    unsigned int unkD64;
    unsigned int unkD68;
    unsigned int unkD6C;
    unsigned int unkD70;
    unsigned int unkD74;
    unsigned int unkD78;
    unsigned int unkD7C;
    unsigned int unkD80;
    unsigned int unkD84;
    unsigned int unkD88;
    unsigned int unkD8C;
    unsigned int unkD90;
    unsigned int unkD94;
    unsigned int unkD98;
    unsigned int unkD9C;
    unsigned int unkDA0;
    unsigned int unkDA4;
    unsigned int unkDA8;
    unsigned int unkDAC;
    unsigned int unkDB0;
    unsigned int unkDB4;
    unsigned int unkDB8;
    unsigned int unkDBC;
    unsigned int unkDC0;
    unsigned int unkDC4;
    unsigned int unkDC8;
    unsigned int unkDCC;
    unsigned int unkDD0;
    unsigned int unkDD4;
    unsigned int unkDD8;
    unsigned int unkDDC;
    E2d0Node* m_pNodes[100];
    int TraverseNode(E2d0Node* a1, int a2, int* a3, E2d0Ref** a4);
};

// @fnv 0x00e2d0d0
// pdb: hkpWingedEdge::findVisibleTriangles | hkpWingedEdge.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkWingedEdge::findVisibleTriangles)
// pdb params: initialTriangle, pointOfView, chainLength, edgeChain
int FUN_00e2d0d0_cls::TraverseNode(E2d0Node* apNode, int aiArg, int* piCount, E2d0Ref** papMatch)
{
    int result = 0;
    for (int i = 0; i < 3; ++i)
    {
        E2d0Ref* ref = apNode->m_slots[i].m_pReference;
        E2d0Node* node = ref->m_pReferencedNode;
        int state = node->m_slots[2].m_state0c;
        if (state == 0)
        {
            state = node->Probe(aiArg, this, &m_04);
            node->m_slots[2].m_state0c = state;
            if (state == 1)
            {
                result = this->TraverseNode(node, aiArg, piCount, papMatch);
                if (result == 2)
                    break;
                continue;
            }
            if (state == 4)
            {
                result = 2;
                break;
            }
        }
        if (state == 2)
        {
            ref->m_pSharedOwner->m_pRef30 = ref;
            ++*piCount;
            *papMatch = ref;
        }
    }
    apNode->m_slots[2].m_f08 = DAT_0104da48;
    if (m_count0c >= 100)
    {
        return 2;
    }
    m_pNodes[m_count0c] = apNode;
    ++m_count0c;
    return result;
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct hkMemoryAllocator;

struct hkMemoryRouterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocator* m_pStreamAllocator;
};

hkMemoryRouterStub* GetMemoryRouterStub();

struct hkArrayUtilStub
{
    static void __cdecl reserve(hkMemoryAllocator& alloc, void* array, int numElem, int sizeElem);
};

struct RefHolderE2
{
    void* m_ptr;
    RefHolderE2(const RefHolderE2& other);
    ~RefHolderE2();
    RefHolderE2& operator=(const RefHolderE2& other);
};

template <typename T> struct hkArrayStub
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void destruct(T* p, int n)
    {
        for (int i = 0; i < n; i++)
        {
            p[i].~T();
        }
    }

    __forceinline void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; i++)
        {
            dst[i] = src[i];
        }
    }

    __forceinline void constructWithCopy(T* dst, int n, const T* src)
    {
        for (int i = 0; i < n; i++)
        {
            new (dst + i) T(src[i]);
        }
    }

    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newCap = n < cap2 ? cap2 : n;
            hkArrayUtilStub::reserve(alloc, this, newCap, sizeof(T));
        }
    }

    __forceinline hkArrayStub& operator=(const hkArrayStub& a)
    {
        copyFromArray(GetMemoryRouterStub()->heap(), a);
        return *this;
    }

    __forceinline void copyFromArray(hkMemoryAllocator& alloc, const hkArrayStub& a)
    {
        const int oldSize = m_iElementCount;
        const int newSize = a.m_iElementCount;
        const int copiedSize = newSize > oldSize ? oldSize : newSize;
        reserve(alloc, newSize);
        destruct(m_data + newSize, oldSize - newSize);
        copy(m_data, a.m_data, copiedSize);
        constructWithCopy(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize);
        m_iElementCount = newSize;
    }
};

unsigned int __cdecl FUN_00e31570(unsigned char a1, unsigned int* a2);

int __cdecl FUN_00e31570(int a, int* c);

extern "C" void _ReadWriteBarrier(void);
extern int DAT_010eb770;

struct Base_b4888
{
    unsigned int unk00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile unsigned int m_08;

    Base_b4888()
    {
        m_06 = 1;
        *(int**)this = &DAT_010eb770;
        m_08 = 0;
    }
};

// @f3 0x00453910 (community match, verified in this file)
extern int DAT_0106dcf4;
extern void* DAT_0106dcf8;
extern unsigned short DAT_0106dcfc;
extern unsigned short DAT_0106dcfe;
extern char DAT_011f6238;

struct A1450MemoryManager {
    void Deallocate(void* p);
};

class TESDescription {
public:
    virtual void vfn0();
    unsigned int m_04;
    TESDescription();
};

// pdb: TESDescription::TESDescription | TESDescription.obj | fnv360_0822_retail, uvref, high
TESDescription::TESDescription()
{
    void* old = DAT_0106dcf8;
    if (old != 0)
        ((A1450MemoryManager*)&DAT_011f6238)->Deallocate(old);
    DAT_0106dcf8 = 0;
    DAT_0106dcfe = 0;
    DAT_0106dcfc = 0;
    DAT_0106dcf4 = 0;
    m_04 = 0;
}


struct S_00e3a270_RefObj
{
    virtual void FUN_vfn0();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    S_00e3a270_RefObj() : m_sReferenceCount(1)
    {}
};

struct S_00e3ae70_Alloc
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct S_00e3ae70_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00e3ae70_Alloc* m_pAllocator;
};

S_00e3ae70_Holder* __cdecl FUN_00c85750() throw();

struct S_00e3ae70_Item
{
    int unk00;
    int unk04;
    int unk08;
    float m_0c;
    float m_10;
};

struct S_00e3ae70_Array
{
    S_00e3ae70_Item** pBuffer;
    int iSize;
    unsigned int SimpleArrayStorage;
};

struct S_00e3ae70_cls
{
    void CollectSlotValues(unsigned int a1, unsigned int a2, S_00e3ae70_Array* pOut);
    void SetItemValues(unsigned int a1, unsigned int a2, float a3, float a4);
};

// @f3 0x00a704d0 (community match, verified in this file)
namespace f3m_00a704d0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_010f3170;
struct Pool { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
}
using namespace f3m_00a704d0;

// pdb: hkpPoweredChainMapper::setForceLimits | hkpPoweredChainMapper.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: linkIndex, coordinageIndex, minForce, maxForce
void S_00e3ae70_cls::SetItemValues(unsigned int a1, unsigned int a2, float a3, float a4)
{
    S_00e3ae70_Array arr;
    arr.pBuffer = 0;
    arr.iSize = 0;
    arr.SimpleArrayStorage = 0x80000000;
    CollectSlotValues(a1, a2, &arr);
    if (arr.iSize != 0) {
        float divisor = (float)arr.iSize;
        a3 /= divisor;
        a4 /= divisor;
        for (int i = 0; i < arr.iSize; i++) {
            S_00e3ae70_Item* item = arr.pBuffer[i];
            item->m_0c = a3;
            item->m_10 = a4;
        }
    }
    if ((arr.SimpleArrayStorage & 0x80000000u) == 0) {
        unsigned int n = arr.SimpleArrayStorage & 0x3fffffffu;
        Pool* pool = (Pool*)TlsGetValue(DAT_010f3170);
        pool->FUN_008f6d90(arr.pBuffer, n * 4, 0x17);
    }
}


extern void* DAT_010eb98c;

namespace fnv_00e3b0a0 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();
extern int DAT_010eb98c;

}  // namespace fnv_00e3b0a0

struct S_00e3c5b0_Obj
{
    int unk04;
    int unk08;
    int unk0c;
    virtual void vf0();
};
struct S_00e3c5b0_Act
{
    int unk14;
    virtual void vf1();
};
struct S_00e3c5b0_Base : S_00e3c5b0_Obj, S_00e3c5b0_Act
{
    S_00e3c5b0_Base(int type, int flag) throw();
    S_00e3c5b0_Base(int type) throw();
};
struct S_00e3c5b0_Arr
{
    int* data;
    int size;
    int cap;
    S_00e3c5b0_Arr()
    {
        data = 0;
        size = 0;
        cap = (int)0x80000000;
    }
};
struct FUN_00e3c5b0 : S_00e3c5b0_Base
{
    S_00e3c5b0_Arr a;
    S_00e3c5b0_Arr b;
    S_00e3c5b0_Arr c;
    float unk3c;
    unsigned char unk40;
    FUN_00e3c5b0(float f);
};
// Initializes the base with type 0x17 and flag 4, stores f in unk3c and sets unk40 to 6.
// @f3 0x00a72bc0 (community match, verified in this file)
// pdb: hkpSimpleMeshShape::hkpSimpleMeshShape | hkpSimpleMeshShape.obj | fnv360_0822_retail, caller_sim, high
// pdb params: radius
FUN_00e3c5b0::FUN_00e3c5b0(float f) : S_00e3c5b0_Base(0x16)
{
    unk3c = f;
    unk40 = 6;
}


struct FUN_00e3dfb0_arg
{
    int value;
    unsigned short m_type;
    unsigned short unk06;
};

class FUN_00e3dfb0_cls
{
  public:
    int unk00;
    int unk04;
    int m_08;
    int unk0c;
    int unk10;
    int m_14;
    int unk18;
    int unk1c;
    int m_20;
    int unk24;
    int unk28;
    int m_2c;
    int unk30;
    int unk34;
    int m_38;

    int FUN_00e3dfb0(FUN_00e3dfb0_arg* rec);
};

// Selects one of the object's fields based on rec->m_type and returns rec->value plus that field, or 0 for unknown types.
// @fnv 0x00e3dfb0
int FUN_00e3dfb0_cls::FUN_00e3dfb0(FUN_00e3dfb0_arg* apRecord)
{
    int field;
    switch (apRecord->m_type)
    {
    case 1:
        field = m_38;
        break;
    case 2:
        field = m_2c;
        break;
    case 3:
        field = m_20;
        break;
    case 4:
    case 5:
        field = m_14;
        break;
    case 6:
    case 7:
        field = m_08;
        break;
    default:
        return 0;
    }
    return apRecord->value + field;
}

struct FUN_00e3ec00_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    FUN_00e3ec00_Class** unk28;
    int unk2c;

    int __thiscall GetTotal();
};

// Returns unk2c plus the sum of GetTotal() over the unk2c elements of unk28.
// @f3 0x0091ab10 (community match, verified in this file)
struct ClassLayout_91ab10
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual int s38(int index);
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24;
    ClassLayout_91ab10** unk28;
    int unk2c; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48;
    int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68;
    int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88;
    int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8;
    int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8;
    int unkCC; int unkD0; int m_count;
};

// pdb: hkMalleableConstraintCinfo::GetStrength | bhkMalleableConstraint.obj | tesv_win, objrun_open, low
int FUN_00e3ec00_Class::GetTotal()
{
    ClassLayout_91ab10* self = (ClassLayout_91ab10*)this;
    int n = self->m_count;
    int i = 0;
    if (n > 0)
    {
        for (;;)
        {
            int r = self->s38(i);
            i++;
            if (i >= n)
                return r;
        }
    }
}


struct S_00e3ed00_Foo;

struct S_00e3ed00_Result
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct S_00e3ed00_List
{
    S_00e3ed00_Foo** elements;
    int count;
    int capacity;
};

struct S_00e3ed00_Foo
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
    S_00e3ed00_Foo** children;
    int childCount;

    S_00e3ed00_Result* __thiscall FUN_00c85750();
    int __thiscall AppendToTraversalList(S_00e3ed00_Foo* param1, S_00e3ed00_List* param2);
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <class T> __forceinline void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem * sizeof(T));
    }
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

NineIntegerRecord& GetMemoryRouter();

struct hkReferencedObj
{
    void removeReference();
};

struct hkRefPtrE
{
    hkReferencedObj* m_pRetainedObject;
    ~hkRefPtrE()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct ReferenceCountedPointer
{
    hkReferencedObj* m_pRetainedObject;
    void release()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct hkStringPtrE
{
    const char* m_pcText;
    ~hkStringPtrE();
};

struct Pair8
{
    int unk00;
    hkStringPtrE m_name;
    ~Pair8()
    {}
};

struct Elem40
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
};

struct hkTypeIsClass
{
};
template <class T> __forceinline void destructAll2(T* t, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}
__forceinline void destructAll(Elem40* t, int n)
{}
template <class T> __forceinline void destructAll(T* t, int n)
{
    destructAll2(t, n, hkTypeIsClass());
}

template <class T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void clear()
    {
        destructAll(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void ClearAndRelease()
    {
        _clearAndDeallocate(GetMemoryRouter().heap());
    }
};

namespace fnv_00e3f110 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

struct BSAudio;
BSAudio* __cdecl FUN_00c85750();

}  // namespace fnv_00e3f110

int __cdecl hkString_strCasecmp(unsigned int a, int b);

namespace fnv_00e30ff0 {
extern int(__cdecl* DAT_011be4a0[])(int);

}  // namespace fnv_00e30ff0

int __cdecl hkString_strCasecmp(const char* pcA, const char* pcB);

struct BE3E7E0Entry
{
    unsigned int m_uiTaggedName;
    int unk04;
    int unk08;
    int unk0C;

    const char* GetName() const
    {
        return (const char*)(m_uiTaggedName & ~1u);
    }
};

void __cdecl SetEntity();

// @fnv 0x00e36f40
// pdb: hkString::memCpy | hkString.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkString_memCpy()
{
    SetEntity();
}

struct FUN_00e39e80_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float unk1C;
    float FUN_00e39e80();
};
// @fnv 0x00e39e80
// pdb: NiIntersector::GetContactTime | NiIntersector.obj | fnv360_0822_retail, objrun_prop, medium
float FUN_00e39e80_class::FUN_00e39e80()
{
    return unk1C;
}

int __cdecl FUN_00e3dfb0(int param_1, int* param_2);

// @fnv 0x00e3e020
// pdb: hkString::memSet | hkString.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
int __cdecl hkString_memSet(int param_1, int* param_2)
{
    return FUN_00e3dfb0(param_1, param_2);
}

struct FNVTreeNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int taggedName;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    FNVTreeNode** children;
    int childCount;

    FNVTreeNode* __thiscall FindChildByName(const char* name);
};
// Searches children recursively for a node whose tagged name string matches name, returning the first match or 0.
// @f3 0x0043c600 (community match, verified in this file)
namespace f3m_0043c600
{
struct QNode;
struct QLink { QNode* node; QLink* next; };
int __cdecl FUN_00c009eb(const char* a, const char* b);

struct QNode
{
    virtual void vt00(); virtual void vt01(); virtual void vt02(); virtual void vt03();
    virtual void vt04(); virtual void vt05(); virtual void vt06(); virtual void vt07();
    virtual void vt08(); virtual void vt09(); virtual void vt10(); virtual void vt11();
    virtual void vt12(); virtual void vt13(); virtual void vt14(); virtual void vt15();
    virtual void vt16(); virtual void vt17(); virtual void vt18(); virtual void vt19();
    virtual void vt20(); virtual void vt21(); virtual void vt22(); virtual void vt23();
    virtual void vt24(); virtual void vt25(); virtual void vt26(); virtual void vt27();
    virtual void vt28(); virtual void vt29(); virtual void vt30(); virtual void vt31();
    virtual void vt32(); virtual void vt33(); virtual void vt34(); virtual void vt35();
    virtual void vt36(); virtual void vt37(); virtual void vt38(); virtual void vt39();
    virtual void vt40(); virtual void vt41(); virtual void vt42(); virtual void vt43();
    virtual void vt44(); virtual void vt45(); virtual void vt46(); virtual void vt47();
    virtual void vt48(); virtual void vt49(); virtual void vt50(); virtual void vt51();
    virtual void vt52(); virtual void vt53(); virtual void vt54(); virtual void vt55();
    virtual void vt56(); virtual void vt57(); virtual void vt58(); virtual void vt59();
    virtual void vt60(); virtual void vt61(); virtual void vt62(); virtual void vt63();
    virtual void vt64(); virtual void vt65(); virtual void vt66(); virtual void vt67();
    virtual void vt68(); virtual void vt69(); virtual void vt70(); virtual void vt71();
    virtual void vt72(); virtual void vt73(); virtual void vt74(); virtual void vt75();
    virtual const char* vt76();
    int unk04;
    int unk08;
    QLink head;
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
    QNode** children;
    unsigned short unk170;
    unsigned short childCount;
    QNode* FUN_005021e0(const char* name);
};
}

// pdb: TESDataHandler::GetCellByEditorID | TESDataHandler.obj | fnv360_0822_retail, call_gap, low
// pdb params: apEditorID
FNVTreeNode* __thiscall FNVTreeNode::FindChildByName(const char* pcName)
{
    using namespace f3m_0043c600;
    QNode* self = reinterpret_cast<QNode*>(this);
    if (pcName == 0)
        return 0;

    int count = self->childCount;
    for (int i = 0; i < count; ++i)
    {
        QNode* child = self->children[i];
        const char* name = child->vt76();
        if (FUN_00c009eb(name, pcName) == 0)
            return reinterpret_cast<FNVTreeNode*>(child);
    }

    for (QLink* link = &self->head; link; link = link->next)
    {
        if (link->node)
        {
            QNode* found = link->node->FUN_005021e0(pcName);
            if (found)
                return reinterpret_cast<FNVTreeNode*>(found);
        }
    }
    return 0;
}


struct FUN_00e31080
{
    float f0;
    float f4;
    float f8;
    float fc;
    unsigned short w10;
    unsigned short w12;
    unsigned short w14;
    unsigned short w16;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1a;
    unsigned char b1b;
    FUN_00e31080();
};
// Constructor that initializes four float fields to 0.001f, four unsigned short fields to 3, and four unsigned char fields to 1.
// @f3 0x00423780 (community match, verified in this file)
namespace v_00423780 {
struct Vec3
{
    float x;
    float y;
    float z;
    Vec3() {}
    Vec3(float f) : x(f), y(f), z(f) {}
};
struct View
{
    int unk00;
    Vec3 a;
    Vec3 b;
    unsigned char c;
};
}
// pdb: DoorTeleportData::DoorTeleportData | TeleportData.obj | fnv360_0822_retail, uconst, low
FUN_00e31080::FUN_00e31080()
{
    v_00423780::View* v = (v_00423780::View*)this;
    v->a = v_00423780::Vec3(3.4028135e+38f);
    v->unk00 = 0;
    v->c = 0;
    v->b = v_00423780::Vec3(3.4028135e+38f);
}


// Probe for 0x00e29900: does cl 15.00.30729.01 /GL + /LTCG deliver this
// wrapper's pointer argument in EAX, so the body compiles to
//   50              push eax
//   e8 xx xx xx xx  call ?__time64@@YA_JPA_J@Z
//   83 c4 04        add esp, 4
//   c3              ret
// (original bytes at 0x00e29900: 50 e8 d4 14 0a 00 83 c4 04 c3)?
// Without /GL the cdecl stack parameter forces "mov eax,[esp+4]" first,
// which the original does not have.

__int64 __cdecl __time64(__int64* t);

// @fnv 0x00e29900
// pdb: time | hkSystemTime.obj | tesv_win, caller_sim, low
static __int64 FUN_00e29900(__int64* t)
{
    return __time64(t);
}

__int64* volatile g_ptr;
__int64 probe_caller(void)
{
    return FUN_00e29900(g_ptr);
}

typedef __int64 (*probe_fn)(void);
probe_fn volatile g_keep = probe_caller;

volatile unsigned int g_be_sink_e2f9;

extern "C" double __cdecl fabs(double);
struct S00e311f0_V
{
    float m[4];
};
struct S00e311f0_PA
{
    const S00e311f0_V* value;
    const S00e311f0_V* operator->() const
    {
        return value;
    }
};
struct S00e311f0_PB
{
    const S00e311f0_V* value;
    const S00e311f0_V* operator->() const
    {
        return value;
    }
};
struct S00e311f0_T
{
    float value;
    operator float() const
    {
        return value;
    }
};

namespace se34af0 {

}

#include <xmmintrin.h>
struct hkVector4X
{
    __m128 m_vComponents;
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct hkRotationX
{
    hkVector4X m_kColumn0;
    hkVector4X m_kColumn1;
    hkVector4X m_kColumn2;
    void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
};

template <class T> struct hkArrayX
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayX() : m_data(0), m_iElementCount(0), m_iCapacityState((int)0x80000000)
    {}
};

struct hkRefObjX
{
    virtual void vf0();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjX() : m_sReferenceCount(1)
    {}
};

struct hkBoolX
{
    char m_cBooleanValue;
    hkBoolX()
    {}
    hkBoolX(bool b) : m_cBooleanValue(static_cast<char>(b))
    {}
    hkBoolX& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }
};

struct S3b010Links
{
    volatile unsigned short unk00;
    int unk04;
    int unk08;

    void FUN_00d21ce0(void* arg);
};

struct S3b010Obj
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    S3b010Links m_0c;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    volatile float unk24;
    float unk28;
    float unk2c;

    void* FUN_00e3b010();
};

// Initializes S3b010Obj fields to default values and calls m_0c.FUN_00d21ce0(this) before returning this.
// @f3 0x00a70be0 (community match, verified in this file)
struct FUN_00d21ce0_cls
{
    unsigned short unk00;
    int unk04;
    int unk08;
    void FUN_00d21ce0(void* arg);
};
extern void* DAT_00e87b30;
// pdb: hkpStiffSpringChainData::hkpStiffSpringChainData | hkpStiffSpringChainData.obj | fnv360_0822_retail, caller_sim, high
void* S3b010Obj::FUN_00e3b010()
{
    unk06 = 1;
    unk08 = 0;
    unk00 = (void*)&DAT_00e87b30;
    FUN_00d21ce0_cls* links = reinterpret_cast<FUN_00d21ce0_cls*>(&m_0c);
    links->unk00 = 1;
    unk18 = 0;
    unk1c = 0;
    unk20 = 0x80000000u;
    unk24 = 0.6f;
    unk28 = 1.0f;
    unk2c = 1.1920929e-8f;
    links->FUN_00d21ce0(this);
    return this;
}


struct V4
{
    __m128 q;

    float& operator()(int i)
    {
        return ((float*)&q)[i];
    }
    void setZero()
    {
        q = _mm_setzero_ps();
    }
};

struct M3
{
    V4 c0;
    V4 c1;
    V4 c2;

    void setIdentity()
    {
        c0.setZero();
        c1.setZero();
        c2.setZero();
        c0(0) = 1.0f;
        c1(1) = 1.0f;
        c2(2) = 1.0f;
    }
};

namespace se3b790 {

struct Cell
{
    unsigned char m_aucFlags[48];
};

}

namespace se3d200 {

}

namespace ns_e3e8 {
int __cdecl hkString_strCasecmp(const char* a, const char* b) throw();
}

template <class T> struct hkRefPtr_e3e8
{
    T* m_pRetainedObject;
    ~hkRefPtr_e3e8() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
    T* FUN_00d477a0() throw();
    T* val() const
    {
        return m_pRetainedObject;
    }
};

struct FUN_00e22d50
{
    virtual ~FUN_00e22d50();
    void operator delete(void* p)
    {
        GetMemoryRouter().heap().ReleaseBlock(p, 0x30);
    }
};

class hkMemoryAllocatorE3A3
{
  public:
    virtual ~hkMemoryAllocatorE3A3() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE3A3
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE3A3* m_pStreamAllocator;

    hkMemoryAllocatorE3A3& heap()
    {
        return *m_pStreamAllocator;
    }
};

template <class T> class hkArrayE3A3
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayE3A3() throw()
    {
        hkMemoryAllocatorE3A3& kAlloc = reinterpret_cast<hkMemoryRouterE3A3*>(FUN_00c85750())->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkE3A3 {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

}

namespace FUN_00e3a360 {

}

struct RefObject_e3f4e0
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    RefObject_e3f4e0()
    {
        m_sReferenceCount = 1;
    }
    virtual ~RefObject_e3f4e0()
    {}
};

template <class T> struct Array_e3f4e0
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    Array_e3f4e0() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct S_00df8990_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    signed char unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    unsigned char unk3c;
};
struct CastOutput
{
    int* vtable;
    float fraction;
    int shape08;
    int shape0c;
    int shape10;
    int shape14;
    int shape18;
};
struct __declspec(align(16)) CastCollector
{
    int* vtable00;
    int* vtable04;
    int* vtable08;
    int* vtable0c;
    int value10;
    float fraction14;
    unsigned char hit18;
    S_00df8990_Obj* owner1c;
    S_00df8990_Obj* owner20;
    int shape24;
    int shape28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int extra50;
    int adjusted54;
    int unk58;
    int unk5c;
    CastOutput* output60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};
extern int DAT_010dbaf8, DAT_010dbae4, DAT_010dbad8, DAT_010dbacc, DAT_010dbb04;

#include <xmmintrin.h>
namespace fnv_00e2cfe0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    void _mm_store_ss(float*, __m128);
    float _mm_cvtss_f32(__m128);
}

struct PlaneScalar
{
    __m128 q;
    __forceinline PlaneScalar(__m128 value) : q(value)
    {}
    __forceinline operator float() const
    {
        float value;
        _mm_store_ss(&value, q);
        return value;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};

struct PlaneVector
{
    __m128 q;
    __forceinline void difference(const PlaneVector& a, const PlaneVector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void cross(const PlaneVector& a, const PlaneVector& b)
    {
        __m128 lhs = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 rhs = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(lhs, rhs);
    }
    __forceinline PlaneScalar dot(const PlaneVector& b) const
    {
        __m128 p = _mm_mul_ps(q, b.q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline PlaneScalar inverseLength() const
    {
        __m128 half = _mm_set_ss(0.5f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 sum = dot(*this).q;
        __m128 isZero = _mm_cmpeq_ss(sum, zero);
        __m128 r = _mm_rsqrt_ss(sum);
        __m128 refined = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(sum, r), r)));
        return _mm_andnot_ps(isZero, refined);
    }
    __forceinline void normalize()
    {
        __m128 inv = inverseLength().splat();
        q = _mm_mul_ps(inv, q);
    }
};

}  // namespace fnv_00e2cfe0

extern "C" void _ReadWriteBarrier(void);
struct Chain
{
    int unk00;
    int value;
    int unk08;
    Chain* next;
};

struct __declspec(align(16)) Vec4
{
    __m128 q;
};

struct __declspec(align(16)) Node
{
    Vec4 vector;
    float value;
    int id;
    int unk18;
    int unk1c;
    int chainValues[12];
    Chain* tail;
    int unk54;
    int unk58;
    int unk5c;
};

template <class T> struct Cell
{
    T data;
    __forceinline Cell()
    {}
    __forceinline Cell(T item) : data(item)
    {}
    __forceinline void operator=(T item)
    {
        data = item;
    }
    __forceinline T get() const
    {
        return data;
    }
    __forceinline operator T() const
    {
        return get();
    }
    __forceinline T operator->() const
    {
        return get();
    }
};
struct Manager
{
    int unk00;
    int unk04;
    Cell<Node*> base;
    Cell<Node*> current;
    Cell<int> capacity;
    Cell<int> used;
    Cell<Chain*> tail;
};

// Copies source into a free slot of manager, or when full over the node with the largest value if source's is smaller, then records the chain's values in it.
// @fnv 0x00e2b9b0
void __cdecl FUN_00e2b9b0(Chain* chain, Node* source, Manager* manager)
{
    Node* destination;

    if (manager->used < manager->capacity)
    {
        destination = manager->current;
        manager->used = manager->used + 1;
        manager->current = manager->current + 1;
    }
    else
    {
        Node* last = manager->base + 1;
        Node* identifier = manager->base;
        for (int i = 1; i < manager->used; ++i)
        {
            if (last->value > identifier->value)
                identifier = last;
            last++;
        }

        if (!(source->value < identifier->value))
            return;

        destination = identifier;
    }

    destination->value = source->value;
    destination->vector.q = source->vector.q;
    int best = source->id;
    _ReadWriteBarrier();
    destination->id = best;
    _ReadWriteBarrier();

    if (manager->tail != 0)
    {
        destination->tail = manager->tail;
    }
    else
    {
        Chain* kIter = chain;

        while (kIter->next != 0)
            kIter = kIter->next;

        destination->tail = kIter;
    }

    int iCount = 0;
    Chain* current = chain->next;

    while ((bool)current)
    {
        ++iCount;
        current = current->next;
    }

    destination->chainValues[iCount] = -1;
    for (int index = iCount - 1; index >= 0; --index)
    {
        int value = chain->value;
        _ReadWriteBarrier();
        destination->chainValues[index] = value;
        chain = chain->next;
    }
}

extern "C" void _ReadWriteBarrier();
struct PlaneIndex
{
    unsigned short value;
};
struct PackedPlane
{
    unsigned int x, y, z;
    union
    {
        unsigned int w;
        struct
        {
            unsigned short low;
            PlaneIndex left;
        };
    };
    unsigned short flags;
    PlaneIndex extra;
    PackedPlane()
    {
        flags = 0;
    }
};

struct WorkItem
{
    PackedPlane plane;
    PackedPlane* node;
    int side;
    int count;
};
S_00e3ae70_Holder* FUN_00e4e3f0() throw();
struct WorkStack
{
    WorkItem* data;
    int size;
    static __forceinline void initialize(WorkItem* ptr, int length)
    {
        for (int j = 0; j < length; ++j)
            new (ptr + j) WorkItem;
    }
    __forceinline WorkItem* expand(int amount)
    {
        int old = size;
        size = old + amount;
        initialize(data + old, size - old);
        return data + old;
    }
};
struct WorkArray : hkArr<WorkItem>
{
    WorkItem* localMemory;
    static __forceinline void initialize(WorkItem* ptr, int length)
    {
        for (int j = 0; j < length; ++j)
            new (ptr + j) WorkItem;
    }
    __forceinline WorkItem* expand(int amount)
    {
        int old = m_iElementCount;
        m_iElementCount = old + amount;
        initialize(m_data + old, m_iElementCount - old);
        return m_data + old;
    }
};

#include <xmmintrin.h>
namespace fnv_00e2c8a0 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;

struct ShortIndex
{
    unsigned short value;
};
struct Bounds
{
    __m128 a;
    __m128 b;
    union
    {
        int f20;
        struct
        {
            unsigned short low20;
            ShortIndex index22;
        };
    };
    unsigned short f24;
    ShortIndex index26;
    __forceinline void assign(const Bounds& rhs) throw()
    {
        a = rhs.a;
        b = rhs.b;
        f20 = rhs.f20;
        f20 = rhs.f20;
        f24 = rhs.f24;
        index26 = rhs.index26;
    }
    __forceinline void copy(const Bounds& rhs) throw()
    {
        a = rhs.a;
        b = rhs.b;
        f20 = rhs.f20;
        f24 = rhs.f24;
        index26 = rhs.index26;
    }
};
struct Item
{
    Bounds bounds;
    int* data;
    int kind;
    int count;
    int unk3c;
};
struct InitItem : Item
{
    __forceinline InitItem() throw()
    {
        bounds.f24 = 0;
    }
};
struct IndexLookup
{
    int* FUN_00d1bb40(ShortIndex) throw();
};
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Bounds* bounds;
    int unk14;
    int unk18;
    IndexLookup lookup;
};
struct Allocator
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void freeBlock(void*, int) = 0;
};
struct Scratch
{
    char* top;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
    __forceinline Allocator& heap() throw()
    {
        return *allocator;
    }
};
__forceinline Scratch* scratchRouter() throw()
{
    return (Scratch*)FUN_00c85750();
}
void FUN_00e4e3f0() throw();
extern "C" __declspec(noalias) void FUN_00e2bbd0(Owner*, Bounds*, int*, int, int, int, int, int, float*, int*, int, int,
                                                 int, int, int*, int*, int*, int*, Bounds*, Bounds*) throw();
struct __declspec(align(16)) Weights
{
    float* data;
    int size;
    int capacity;
    __forceinline Weights(int n) throw()
    {
        Scratch* s = scratchRouter();
        data = (float*)s->top;
        s->top += (n * 4 + 127) & ~127;
        capacity = n | 0x80000000;
        for (int i = 0; i < n; ++i)
            data[i] = 1.0f;
        FUN_00e4e3f0();
    }
    __forceinline void release() throw()
    {
        scratchRouter()->top = (char*)data;
        Allocator& a = scratchRouter()->heap();
        if ((capacity & 0x80000000) == 0)
            a.freeBlock(data, (capacity & 0x3fffffff) * 4);
    }
};
__forceinline void constructItems(Item* p, int n) throw()
{
    for (int i = 0; i < n; ++i)
        new (p + i) InitItem;
}
__forceinline Item* growItems(Item* data, int old, int size) throw()
{
    int delta = size - old;
    Item* p = data + old;
    constructItems(p, delta);
    return p;
}
}  // namespace fnv_00e2c8a0

namespace FanSpace {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m[4];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_set_ss(float);
extern "C" void _mm_store_ss(float*, __m128);
struct SimdScalar
{
    union
    {
        __m128 q;
        float values[4];
    };
    SimdScalar(__m128 x) : q(x)
    {}
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, q);
        return f;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
struct FanVec
{
    union
    {
        __m128 q;
        float values[4];
    };
    __forceinline void subtract(const FanVec& a, const FanVec& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void cross(const FanVec& a, const FanVec& b)
    {
        __m128 p = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 r = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(p, r);
    }
    __forceinline SimdScalar dot(const FanVec& b) const
    {
        __m128 prod = _mm_mul_ps(q, b.q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
        return _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), xy);
    }
    __forceinline SimdScalar inverseLength() const
    {
        __m128 half = _mm_set_ss(0.5f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 len = dot(*this).q;
        __m128 mask = _mm_cmpeq_ss(len, zero);
        __m128 estimate = _mm_rsqrt_ss(len);
        __m128 val =
            _mm_mul_ss(_mm_mul_ss(half, estimate), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, estimate), estimate)));
        return _mm_andnot_ps(mask, val);
    }
    __forceinline void normalize()
    {
        q = _mm_mul_ps(inverseLength().splat(), q);
    }
};
template <class T> struct FanPad
{
    T value;
    FanPad()
    {}
    FanPad(T v) : value(v)
    {}
    __forceinline operator T() const
    {
        return val();
    }
    __forceinline T operator->() const
    {
        return value;
    }
    __forceinline void operator=(T v)
    {
        value = v;
    }
    __forceinline T val() const
    {
        return value;
    }
};
struct FanEdge;
struct FanVertex
{
    FanVec position;
    FanVec pointA;
    FanVec pointB;
    FanPad<FanEdge*> referee;
};
struct FanTriangle;
struct FanEdge
{
    FanVertex* vertex;
    FanEdge* next;
    FanEdge* twin;
    FanTriangle* triangle;
};
struct FanTriangle
{
    FanVec normal;
    FanEdge edges[3];
    float distance;
    int state;
    __forceinline int plane(const FanVec& a, const FanVec& b, const FanVec& c)
    {
        FanVec x;
        x.subtract(a, b);
        FanVec y;
        y.subtract(b, c);
        FanVec n;
        n.cross(x, y);
        if (float(n.dot(n)) == 0.0)
            return 1;
        n.normalize();
        distance = a.dot(n);
        normal.q = n.q;
        return 0;
    }
};
struct FanBuilder
{
    FanPad<float> tolerance;
    FanPad<float> previous;
    FanPad<int> numVertices;
    FanPad<int> numFree;
    FanPad<int> numTriangles;
    FanVertex vertices[55];
    FanTriangle* freeTriangles[100];
    FanTriangle triangles[100];
    __forceinline FanTriangle* allocateOne()
    {
        FanTriangle* t = &triangles[numTriangles];
        numTriangles = numTriangles + 1;
        return t;
    }
    __forceinline void allocate(int n, FanTriangle** result)
    {
        int i = 0;
        for (int f = numFree - 1; n != 0 && f >= 0; --f)
        {
            result[i++] = freeTriangles[f];
            numFree = numFree - 1;
            --n;
        }
        for (int j = 0; j < n; ++j)
        {
            FanTriangle* q = &triangles[numTriangles];
            numTriangles = numTriangles + 1;
            result[i++] = q;
        }
    }
    __forceinline int initialize(FanTriangle** t, int count, FanEdge* chain, FanVertex*& apex)
    {
        FanEdge* current = chain;
        for (int i = 0; i < count; ++i)
        {
            if (current == 0)
                return 2;
            FanTriangle* tri = t[i];
            FanTriangle* nextTri;
            if (i + 1 < count)
                nextTri = t[i + 1];
            else
                nextTri = t[0];
            tri->edges[0].triangle = tri;
            tri->edges[1].triangle = tri;
            tri->edges[2].triangle = tri;
            tri->edges[0].next = &tri->edges[1];
            tri->edges[1].next = &tri->edges[2];
            tri->edges[2].next = &tri->edges[0];
            FanVertex* a = current->next->vertex;
            FanVertex* b = current->vertex;
            tri->edges[0].vertex = a;
            tri->edges[1].vertex = b;
            tri->edges[2].vertex = apex;
            current->twin = &tri->edges[0];
            tri->edges[0].twin = current;
            nextTri->edges[1].twin = &tri->edges[2];
            tri->edges[2].twin = &nextTri->edges[1];
            if (tri->plane(a->position, b->position, apex->position))
                return 2;
            FanVertex* last = current->next->vertex;
            FanEdge* following = last->referee;
            last->referee = 0;
            current = following;
        }
        for (int j = 0; j < numTriangles; ++j)
            triangles[j].state = 0;
        for (int k = 0; k < numVertices; ++k)
            vertices[k].referee = 0;
        return chain == current ? 0 : 2;
    }
    int FUN_00e2d1b0(int count, FanEdge* chain, FanVertex* apex);
};
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00e2d550 {
extern "C" void _ReadWriteBarrier();
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C"
{
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_add_ss(__m128 a, __m128 b);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
    void _mm_store_ss(float* p, __m128 a);
    double __cdecl fabs(double x);
}

struct HullFace;

struct HullEdge
{
    __m128* m_kRayStart;
    __m128** m_kRayEnd;
    HullEdge* m_twin;
    HullFace* m_face;
};

struct HullFace
{
    __m128 m_vHitNormal;
    HullEdge m_kEdges[3];
    float m_fClosestPointDistanceSquared;
    int m_uiContentCount;
};

}  // namespace fnv_00e2d550

namespace fnv_00e31570 {
}  // namespace fnv_00e31570

void __cdecl FUN_00c908c0(hkMemoryAllocatorE3A3* allocator, void* array, int capacity, int elementSize);

template <class T> struct TyremarkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void initialize()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }

    void SetSizeAndGrow(int count)
    {
        hkMemoryAllocatorE3A3& allocator = reinterpret_cast<hkMemoryRouterE3A3*>(FUN_00c85750())->heap();
        int capacity = m_iCapacityState & 0x3fffffff;
        if (capacity < count)
        {
            int doubled = capacity * 2;
            FUN_00c908c0(&allocator, this, count < doubled ? doubled : count, sizeof(T));
        }
        m_iElementCount = count;
    }
};

// @f3 0x0093d830 (community match, verified in this file)
namespace f3m_0093d830 {
int __cdecl hkString_strCmp(const char* pcA, const char* pcB);

struct Entry93d830
{
    const char* m_pcName;
    int unk04;
    int unk08;
};

struct Table93d830
{
    Entry93d830* m_pkEntries;
    int m_iCount;

    int* FUN_0093d830(const char* pcName);
};

// pdb: hkCustomAttributes::getAttribute | hkClass.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: id
int* Table93d830::FUN_0093d830(const char* pcName)
{
    for (int i = 0; i < m_iCount; i++)
    {
        if (hkString_strCmp(m_pkEntries[i].m_pcName, pcName) == 0)
            return &m_pkEntries[i].unk04;
    }
    return 0;
}
}   // namespace f3m_0093d830

// @f3 0x0093d810 (community match, verified in this file)
namespace f3m_0093d810 {
// Class-member accessor: construct a two-pointer result from the member address and struct class.
namespace f3m_0093d810 {

class hkClass;

class hkClassMember
{
	public:
		const hkClass& getStructClass() const;
};

class hkClassAccessor
{
	public:
		hkClassAccessor( void* object, const hkClass* klass );

		void* m_object;
		const hkClass* m_class;
};

class hkClassMemberAccessor
{
	public:
		hkClassAccessor FUN_0093d810() const;

		void* m_address;
		const hkClassMember* m_member;
};

// pdb: hkClassMemberAccessor::object | hkClassMemberAccessor.obj | tesv_win, hash, low
hkClassAccessor hkClassMemberAccessor::FUN_0093d810() const
{
	return hkClassAccessor( m_address, &m_member->getStructClass() );
}

}
}   // namespace f3m_0093d810
