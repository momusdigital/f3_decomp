#include <windows.h>
// src/f3staging/f3blk_00b40000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b576a0 (community match, verified in this file)
extern int DAT_011780f0;
extern int DAT_011780f4;
extern int DAT_011780f8;
extern int DAT_011780fc;
extern int DAT_01178100;
extern int DAT_01178104;
extern int DAT_01178108;
extern int DAT_0117810c;
extern int DAT_01178110;
extern int DAT_01178114;
extern int DAT_01178118;
extern int DAT_0117811c;
extern int DAT_01178120;
extern int DAT_01178124;
extern int DAT_01178128;
extern int DAT_0117812c;
extern int DAT_01178130;
extern int DAT_01178134;
extern int DAT_01178138;
extern int DAT_0117813c;
extern int DAT_01178140;
extern int DAT_01178144;
extern int DAT_01178148;
extern int DAT_0117814c;
extern int DAT_01178150;
extern int DAT_01178154;
extern int DAT_01178158;
extern int DAT_0117815c;
extern int DAT_01178160;
extern int DAT_01178164;
extern int DAT_01091980;
namespace f3m_00b576a0 {

struct Ref576 { virtual void v00(); virtual void ReleaseObject(); volatile long refs; };
struct Switch576 {
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
Ref576* unk28;
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
Ref576* unk6c;
void FUN_00b576a0(unsigned int kind);
};
void Switch576::FUN_00b576a0(unsigned int kind)
{
 switch(kind) {
 case 0x151: DAT_01091980=DAT_01178108; break;
 case 0xdf: DAT_01091980=DAT_01178118; break;
 case 0xe8: DAT_01091980=DAT_0117811c; break;
 case 0xf1: DAT_01091980=DAT_01178120; break;
 case 0xfa: DAT_01091980=DAT_01178124; break;
 case 0x108: DAT_01091980=DAT_01178128; break;
 case 0x114: DAT_01091980=DAT_0117812c; break;
 case 0x11f: DAT_01091980=DAT_01178130; break;
 case 0x12a: DAT_01091980=DAT_01178134; break;
 case 0x9f: DAT_01091980=DAT_01178138; break;
 case 0xaa: DAT_01091980=DAT_0117813c; break;
 case 0xb5: DAT_01091980=DAT_01178140; break;
 case 0xc0: DAT_01091980=DAT_01178144; break;
 case 0x137: DAT_01091980=DAT_01178148; break;
 case 0x143: DAT_01091980=DAT_0117814c; break;
 case 0x60: DAT_01091980=DAT_011780f0; break;
 case 0x7a: DAT_01091980=DAT_011780f4; break;
 case 0x7b: DAT_01091980=DAT_011780f8; break;
 case 0x7e: DAT_01091980=DAT_011780fc; break;
 case 0x130: DAT_01091980=DAT_01178100; break;
 case 0x131: DAT_01091980=DAT_01178104; break;
 case 0x158: DAT_01091980=DAT_0117810c; break;
 case 0x159: DAT_01091980=DAT_01178110; break;
 case 0x15f: DAT_01091980=DAT_01178150; break;
 case 0x256: DAT_01091980=DAT_01178114; break;
 case 0x165: DAT_01091980=DAT_01178154; break;
 case 0x16b: DAT_01091980=DAT_01178158; break;
 case 0x171: DAT_01091980=DAT_0117815c; break;
 case 0x177: DAT_01091980=DAT_01178160; break;
 case 0x234: DAT_01091980=DAT_01178164; break;
 }
 Ref576* replacement=unk6c;
 Ref576* old=unk28;
 if(old != replacement) {
 if(old && InterlockedDecrement(&old->refs)==0) old->ReleaseObject();
 unk28=replacement;
 if(replacement) InterlockedIncrement(&replacement->refs);
 }
}
}   // namespace f3m_00b576a0

// @f3 0x00b47530 (community match, verified in this file)
namespace f3m_00b47530 {
struct TlsBlock_t {

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

 int m_298;

};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t

{

    int m_saved;



    TlsGuard_t(int value)

    {

        m_saved = g_tlsBlock.m_298;

        g_tlsBlock.m_298 = value;

    }



    ~TlsGuard_t()

    {

        g_tlsBlock.m_298 = m_saved;

    }

};



struct S3e40_Count

{

    unsigned short* ptr;

};

struct S3e40_Color

{

    float r, g, b;

    float FUN_00af4630();

};

struct S3e40_Vec

{

    float x, y, z;

    float FUN_00af4630();

    float FUN_00432bd0();

};

__forceinline float S3e40_Len(const S3e40_Color& v)

{

    S3e40_Color t = v;

    return t.FUN_00af4630();

}

struct S3e40_Xform

{

    float px, py, pz, angle;

};

extern const S3e40_Xform DAT_0108edc8;

struct S3e40_State

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

    float posX, posY, posZ;

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

    S3e40_Color dir;

};

struct S3e40_Light

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

    S3e40_State* state;

};

union SharedWork

{

    S3e40_Xform bound;

    S3e40_Color color;

    S3e40_Light* first;

    SharedWork(const S3e40_Xform& v) : bound(v)

    {}

    SharedWork(const S3e40_Color& v) : color(v)

    {}

};

struct S3e40_Ref

{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    unsigned short status;

    unsigned char Mode() const

    {

        return (status >> 9) & 1;

    }

};

struct S3e40_Geom

{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int unk1c;

    S3e40_Xform* world;

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

    S3e40_Ref* fallback;

    int unka0;

    int unka4;

    int unka8;

    int unkac;

    int unkb0;

    int unkb4;

    int unkb8;

    void* shader;

    S3e40_Ref* FUN_00826590(bool b);

};

struct S3e40_Root

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

    S3e40_Light* currentLight;

};

struct S3e40_View

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

    S3e40_Root* root;

};

struct S3e40_Passes

{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int count;

    void FUN_00b2c0b0(S3e40_Geom*, unsigned short, bool, unsigned char, S3e40_Light*, S3e40_Light*, S3e40_Light*,

                      S3e40_Light*);

};

S3e40_View* __cdecl FUN_00ad5a50();

float __cdecl FUN_00401e20(float, float);

bool __cdecl FUN_00530bb0();

struct S3e40_Shader

{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int unk1c;

    unsigned int renderFlags;

    unsigned int lightFlags;

    int unk28;

    int unk2c;

    int unk30;

    int unk34;

    unsigned int passState;

    S3e40_Passes* passes;

    S3e40_Light* pass7;

    S3e40_Light* pass8;

    S3e40_Light* pass9;

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

    int callback;

    void SetBit(unsigned int& bits, unsigned int mask, bool on)

    {

        if (((bits & mask) != 0) != on)

            passState = 0;

        if (on)

            bits |= mask;

        else

            bits &= ~mask;

    }

    void SetFlag(unsigned int mask, bool on)

    {

        SetBit(lightFlags, mask, on);

    }

    S3e40_Light* FUN_00aeaf80(S3e40_Geom*, unsigned int, unsigned short*, int, S3e40_Light*, bool);

    void FUN_00b60430(S3e40_Geom*, bool, int);

    void FUN_00b2b740(int);

    unsigned short FUN_00af3490();

    S3e40_Light* FUN_00af32e0(int*);

    S3e40_Light* FUN_00af33d0(int*);

    void FUN_00424200(unsigned int, bool);

    void BSShaderPPLightingProperty_AddDepthMapPass_2x(S3e40_Geom*, bool, bool, S3e40_Light*);

    void FUN_00b5bf20(S3e40_Geom*, unsigned short*, bool, bool*, int);

    S3e40_Light* FUN_00b47530(S3e40_Geom* geom, unsigned int subType, S3e40_Count counter, int passType,

                              S3e40_Light* preferred, bool insert);

};

__forceinline bool S3e40_Less(const float& a, const double& b)

{

    return a < b;

}

// @fnv 0x00bc3e40

S3e40_Light* S3e40_Shader::FUN_00b47530(S3e40_Geom* geom, unsigned int subType, S3e40_Count counter, int passType,

                                        S3e40_Light* preferred, bool insert)

{

    TlsGuard_t guard(0x28);

    if ((renderFlags & 0x8000) > 0u)

        goto delegated;

    if ((renderFlags & 0x10000) > 0u)

        goto delegated;

    goto regular;

delegated:

    return FUN_00aeaf80(geom, subType, counter.ptr, passType, preferred, insert);

regular:



    unsigned int key = (passType << 8) | subType;

    if (passType == 7)

        return pass7;

    if (passType == 8)

        return pass8;

    if (passType == 9)

    {

        FUN_00b60430(geom, geom->shader != 0, 0);

        return pass9;

    }



    if (passState != key || !insert)

    {

        if (insert == true)

        {

            FUN_00b2b740(-1);

            passes->count = 0;

            passState = key;

        }

        else

        {

            *counter.ptr = 0;

        }



        S3e40_Light* sceneLight = FUN_00ad5a50()->root->currentLight;

        if (FUN_00af3490() == 0)

        {

            if (insert == true)

            {

                passes->FUN_00b2c0b0(geom, 0xc1, true, 1, sceneLight, 0, 0, 0);

                SetFlag(0x80, false);

                SetFlag(0x100, false);

                SetFlag(0x200, false);

            }

            else

            {

                ++*counter.ptr;

            }

        }

        else

        {

            float dist;

            passType = 0;

            S3e40_Light* __restrict primary = FUN_00af32e0(&passType);

            {

                S3e40_State* ss = sceneLight->state;

                dist = S3e40_Len(ss->dir);

            }

            float quality;

            S3e40_State* ps;

            {

                const S3e40_Xform* wp = geom->world;

                if (!wp)

                    wp = &DAT_0108edc8;

                SharedWork world(*wp);

                ps = primary->state;

                {

                    S3e40_Vec delta = {ps->posX - world.bound.px, ps->posY - world.bound.py, ps->posZ - world.bound.pz};

                    quality = FUN_00401e20(0.0f, delta.FUN_00432bd0() - world.bound.angle);

                }

            }

            {

                SharedWork work(ps->dir);

                S3e40_Light* secondLight;

                S3e40_Light* secondary;

                {



                    if ((double)dist > (float)((1.0 / quality * quality) * work.color.FUN_00af4630()))

                    {

                        work.first = sceneLight;

                        secondLight = 0;

                        secondary = 0;

                        SetFlag(0x80, false);

                        SetFlag(0x100, false);

                        SetFlag(0x200, false);

                        if (primary)

                        {

                            secondLight = primary;

                            SetFlag(0x100, true);

                        }

                        primary = FUN_00af33d0(&passType);

                        if (primary)

                        {

                            secondary = primary;

                            SetFlag(0x200, true);

                        }

                    }

                    else

                    {

                        work.first = primary;

                        SetFlag(0x80, true);

                        if (dist > 0.0f)

                        {

                            primary = FUN_00af33d0(&passType);

                            if (primary)

                            {

                                secondLight = sceneLight;

                                secondary = primary;

                                SetFlag(0x100, true);

                                SetFlag(0x200, true);

                            }

                            else

                            {

                                secondLight = sceneLight;

                                secondary = 0;

                                SetFlag(0x100, true);

                                SetFlag(0x200, false);

                            }

                        }

                        else

                        {

                            primary = FUN_00af33d0(&passType);

                            if (primary)

                            {

                                secondLight = primary;

                                primary = FUN_00af33d0(&passType);

                                secondary = primary;

                                SetFlag(0x100, true);

                                FUN_00424200(0x29, primary != 0);

                            }

                            else

                            {

                                secondLight = 0;

                                secondary = 0;

                                SetFlag(0x100, false);

                                SetFlag(0x200, false);

                            }

                        }

                    }

                }

                if (insert == true)

                    passes->FUN_00b2c0b0(geom, 0xc2, true, 3, work.first, secondLight, secondary, 0);

                else

                    ++*counter.ptr;

            }

        }

        if (FUN_00530bb0() && insert)

        {

            S3e40_Ref* ref = geom->FUN_00826590(false);

            if (!ref)

                ref = geom->fallback;

            bool marked = ref && (ref->Mode() != 0);

            BSShaderPPLightingProperty_AddDepthMapPass_2x(geom, geom->shader != 0, marked, preferred);

        }

    }

    if (callback)

    {

        bool changed = true;

        FUN_00b5bf20(geom, counter.ptr, insert, &changed, 0);

    }

    return reinterpret_cast<S3e40_Light*>(passes);

}

}   // namespace f3m_00b47530
