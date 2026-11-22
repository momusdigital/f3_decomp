#include <new>
// src/f3staging/f3iso_0096bca0_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x0096bca0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0096bca0 (community match, verified in this file)
class __declspec(align(16)) Vec4
{
public:
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }

    __forceinline void operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    __forceinline void setAdd4(const Vec4& v0, const Vec4& v1)
    {
        x = v0.x + v1.x;
        y = v0.y + v1.y;
        z = v0.z + v1.z;
        w = v0.w + v1.w;
    }

    __forceinline void setSub4(const Vec4& v0, const Vec4& v1)
    {
        x = (float)(v0.x - v1.x);
        y = (float)(v0.y - v1.y);
        z = v0.z - v1.z;
        w = v0.w - v1.w;
    }

    __forceinline void setAddMul4(const Vec4& a, const Vec4& b, float r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }

    __forceinline void mul4(float rs)
    {
        float s = float(rs);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }

    float x,y,z,w;
};
struct S96bca0_Src {
    unsigned int unk00;
    unsigned int unk04;
    float f08;
};
struct S96bca0_Sub {
    S96bca0_Src* FUN_0091dd60();
};
struct S96bca0_Input {
    float f00;
    float f04;
    float f08;
    float f0c;
    Vec4 q10;
    Vec4 q20;
    Vec4 q30;
    Vec4 q40;
    float f50;
    float f54;
    float f58;
    float f5c;
    float f60;
    float f64;
    float f68;
    float f6c;
    Vec4 q70;
};
struct S96bca0_Shape {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    Vec4 q10;
};
struct S96bca0_CtrlBase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37();
    virtual S96bca0_Shape* GetShape();
    unsigned int unk04;
    S96bca0_Sub* unk08;
    unsigned int unk0c;
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
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int flags294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
};
struct S96bca0_Ctrl : S96bca0_CtrlBase {
    Vec4 q2d0;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    Vec4 q320;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    float f340;
    float f344;
    float f348;
    unsigned int unk34c;
    int state350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    Vec4 q360;
    Vec4 q370;
    unsigned int unk380;
    unsigned int unk384;
    float f388;
    unsigned int unk38c;
    Vec4 vel390;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    float f3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    float f3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    float f3ec;
    float f3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    float f408;

    void FUN_008e8900();
    void FUN_008e9380();
    unsigned TestFlag(unsigned bit) const { return static_cast<unsigned char>(flags294 >> bit) & 1; }
    bool GetFlag(unsigned int bit) const { return (*(volatile unsigned int*)&flags294 >> bit) & 1; }
};
void __cdecl FUN_00a062a0(S96bca0_Input* input, Vec4* vel);
extern S96bca0_Src DAT_01092a50;
extern const double DAT_00e7c718;


// pdb: bhkCharacterStateSwimming::Update | bhkCharacterStateSwimming.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: arInput
void __stdcall FUN_0096bca0(S96bca0_Ctrl* c)
{
    S96bca0_Input in;
    in.f00 = 1.0f;
    in.q10 = c->q370;
    in.q20 = c->q360;
    in.q40 = c->vel390;
    in.f50 = c->f344;
    in.f54 = c->f340;
    in.f58 = c->f348;
    in.f5c = 0.0f;
    in.f60 = 100.0f;
    in.q70 = c->q320;
    if (c->GetFlag(8))
        in.q30 = c->q2d0;
    else
        in.q30 = c->q360;
    FUN_00a062a0(&in, &c->vel390);

    S96bca0_Src* src = c->unk08 ? c->unk08->FUN_0091dd60() : &DAT_01092a50;
    float t = src->f08 - c->f408;
    if (c->f3ec >= 0.5f)
        t += c->f3f0 * 0.5 * c->f3ec;
    c->GetShape();
    Vec4 v;
    v = c->GetShape()->q10;
    c->GetShape();
    static_cast<volatile S96bca0_Ctrl*>(c)->flags294 |= 0x400;

    if (t > c->f3c8) {
        if (c->state350 == 1) {
            c->FUN_008e8900();
        } else {
            if (c->vel390(2) > 0.0f)
                c->vel390(2) = 0.0f;
            v.mul4(c->f3d8);
            c->vel390.setAddMul4(c->vel390, v, c->f388);
        }
    } else if (c->f3ec < 0.5f) {
        if (c->state350 == 1 && c->GetFlag(10)) {
            c->FUN_008e8900();
        } else if (c->f3c8 - DAT_00e7c718 > t) {
            v.mul4(c->f3d8);
            c->vel390.setAddMul4(c->vel390, v, -c->f388);
        }
    } else if (c->f3d8 != 1.0f && !c->TestFlag(8) && !c->TestFlag(9)) {
        v.mul4(c->f3d8);
        c->vel390.setAddMul4(c->vel390, v, c->f388);
    }
    c->FUN_008e9380();
    if (c->state350 == 0)
        c->FUN_008e8900();
}
